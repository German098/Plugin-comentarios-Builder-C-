//------------------------------------------------------------------------------

#pragma hdrstop

#include "pbrepdata.h"
#include "_entities.h"
#include "mainform.h"
#include "mainform_bg.h"
#include "tsmlib.h"
#include "IwPoly.h"
#include "IwTree.h"
#include "subdivision.h"
#include "t3ddata.h"
#include "pad.h"
#include "inputQueryEx.h"
#ifdef _USE_LIBIGL
//#include "ParamMesh.h"
#include "libiglWrapper.h"

#include <cmath>

#endif

//------------------------------------------------------------------------------

#pragma package( smart_init )

static bool debug = false;

#define LPM_PIPE_NUMPOINTSSEC 8

//------------------------------------------------------------------------------
// TAddedElements
//------------------------------------------------------------------------------
void InitAddedElements( TAddedElements *addedElements )
{
	if ( !addedElements ) return;

	addedElements->iwVertexs.RemoveAll( );
	addedElements->iwEdges.RemoveAll( );
	addedElements->iwNewEdges.RemoveAll( );
	addedElements->iwFaces.RemoveAll( );
}

//------------------------------------------------------------------------------

void IncludeToAddedElements( TAddedElements *ae, TAddedElements *aeToInclude )
{
	int i, count;

	if ( !ae || !aeToInclude ) return;

	count = (int) aeToInclude->iwVertexs.GetSize( );
	for ( i = 0; i < count; i++ )
		ae->iwVertexs.AddUnique( aeToInclude->iwVertexs.GetAt( i ) );

	count = (int) aeToInclude->iwEdges.GetSize( );
	for ( i = 0; i < count; i++ )
		ae->iwEdges.AddUnique( aeToInclude->iwEdges.GetAt( i ) );

	count = (int) aeToInclude->iwNewEdges.GetSize( );
	for ( i = 0; i < count; i++ )
		ae->iwEdges.AddUnique( aeToInclude->iwNewEdges.GetAt( i ) );

	count = (int) aeToInclude->iwFaces.GetSize( );
	for ( i = 0; i < count; i++ )
		ae->iwFaces.AddUnique( aeToInclude->iwFaces.GetAt( i ) );
}

//------------------------------------------------------------------------------

IwTA<IwPolyEdge *> GetEdgesWithSameIndex( TAddedElements *addedElements, ULONG ulIndex2 )
{
	ULONG uli;
	IwTA<IwPolyEdge *> liwEdges;
	IwPolyEdge *iwEdge;

	if ( addedElements == NULL ) return liwEdges;

	for ( uli = 0; uli < addedElements->iwEdges.GetSize( ); uli++ ) {
		iwEdge = addedElements->iwEdges.GetAt( uli );
		if ( iwEdge != NULL && iwEdge->GetUserIndex2( ) == ulIndex2 ) liwEdges.Add( iwEdge );
	}

	return liwEdges;
}

//------------------------------------------------------------------------------

IwTA<IwPolyFace *> GetFacesWithSameIndex( TAddedElements *addedElements, ULONG ulIndex2 )
{
	ULONG uli;
	IwTA<IwPolyFace *> liwFaces;
	IwPolyFace *iwFace;

	if ( addedElements == NULL ) return liwFaces;

	for ( uli = 0; uli < addedElements->iwFaces.GetSize( ); uli++ ) {
		iwFace = addedElements->iwFaces.GetAt( uli );
		if ( iwFace != NULL && iwFace->GetUserIndex2( ) == ulIndex2 ) liwFaces.Add( iwFace );
	}

	return liwFaces;
}

//------------------------------------------------------------------------------
// TranslateVertexInfo
//------------------------------------------------------------------------------

// Normalizamos el array de direcciones conjuntamente para no perder las proporciones
void TranslateVertexInfo::Normalize( )
{
	int i, numDirs;
	double maxMod, mod;
	IwPoint3d dir;

	maxMod = 0;
	numDirs = Directions.size( );
	for ( i = 0; i < numDirs; i++ ) {
		dir = Directions[ i ];
		mod = sqrt( dir.x * dir.x + dir.y * dir.y + dir.z * dir.z );
		if ( mod > maxMod ) maxMod = mod;
	}

	for ( i = 0; i < numDirs; i++ ) {
		dir = Directions[ i ];
		dir.x /= maxMod;
		dir.y /= maxMod;
		dir.z /= maxMod;
		Directions[ i ] = dir;
	}
}

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// TReverseSubdivision
//------------------------------------------------------------------------------

TReverseSubdivision::TReverseSubdivision( TOGLTransf *_OGLTransf, int _type, TMeshPrimitiveParams *_params, int _level )
{
	Type = _type;
	Params = _params;
	Level = _level;
	SizeCornersRail1 = SizeCornersRail2 = SizeCornersForm = 0;
	CornersRail1 = CornersRail2 = CornersForm = 0;
	SizeNormalsRail1 = 0;
	NormalsRail1 = 0;
	FineVertexs = 0;
	OGLTransf = _OGLTransf;

	InitValues( );
}

//------------------------------------------------------------------------------

TReverseSubdivision::~TReverseSubdivision( )
{
	if ( CornersRail1 ) delete[] CornersRail1;
	if ( CornersRail2 ) delete[] CornersRail2;
	if ( CornersForm ) delete[] CornersForm;
	if ( NormalsRail1 ) delete[] NormalsRail1;
	if ( FineVertexs ) delete FineVertexs;
}

//------------------------------------------------------------------------------

void TReverseSubdivision::InitValues( )
{
	switch ( Type ) {
		case ST_REVOLVE: InitValuesRevolve( ); break;

		case ST_ONE_RAIL_SWEEP: InitValuesOneRailSweep( ); break;

		case ST_TWO_RAILS_SWEEP: InitValuesTwoRailsSweep( ); break;

		default: Closed_H = Closed_V = Closed_V_First = Closed_V_Last = false; break;
	}
}

//------------------------------------------------------------------------------

void TReverseSubdivision::InitValuesRevolve( )
{
	TOGLPolygonList *OGLList_crv, *OGLList_axis;

	if ( !OGLTransf || !Params || !Params->RevolveBaseCrv || !Params->RevolveAxis ) return;

	OGLList_axis = Params->RevolveAxis->GetOGLGeom3D( OGLTransf );
	if ( !OGLList_axis || OGLList_axis->Count( ) != 1 ) return;
	OGLList_crv = Params->RevolveBaseCrv->GetOGLGeom3D( OGLTransf );
	if ( !OGLList_crv || OGLList_crv->Count( ) != 1 ) return;

	// Establecemos parámetros
	Closed_V = ( ToShape( Params->RevolveBaseCrv )->GetCloseExt( OGLTransf ) != ENT_OPEN );
	if ( !Closed_V ) {
		Closed_V_First = ( OGLList_axis->GetFirstItem( )->GetFirstItem( )->IsEqual( OGLList_crv->GetFirstItem( )->GetFirstItem( ) ) || OGLList_axis->GetFirstItem( )->GetLastItem( )->IsEqual( OGLList_crv->GetFirstItem( )->GetFirstItem( ) ) );
		Closed_V_Last = ( OGLList_axis->GetFirstItem( )->GetFirstItem( )->IsEqual( OGLList_crv->GetFirstItem( )->GetLastItem( ) ) || OGLList_axis->GetFirstItem( )->GetLastItem( )->IsEqual( OGLList_crv->GetFirstItem( )->GetLastItem( ) ) );
	} else
		Closed_V_First = Closed_V_Last = false;
	Closed_H = ( Params->RevolveAngleIni == 0.0 && Params->RevolveAngleFin == 360.0 );
}

//------------------------------------------------------------------------------

void TReverseSubdivision::InitValuesOneRailSweep( )
{
	TOGLPolygonList *OGLList_railcrv, *OGLList_formcrv;

	if ( !OGLTransf || !Params || !Params->OneRailSweepRailCrv || !Params->OneRailSweepFormCrv ) return;

	OGLList_railcrv = Params->OneRailSweepRailCrv->GetOGLGeom3D( OGLTransf );
	if ( !OGLList_railcrv || OGLList_railcrv->Count( ) != 1 ) return;
	OGLList_formcrv = Params->OneRailSweepFormCrv->GetOGLGeom3D( OGLTransf );
	if ( !OGLList_formcrv || OGLList_formcrv->Count( ) != 1 ) return;

	// Establecemos parámetros
	Closed_V = ( ToShape( Params->OneRailSweepFormCrv )->GetCloseExt( OGLTransf ) != ENT_OPEN );
	Closed_V_First = Closed_V_Last = false;
	Closed_H = ( ToShape( Params->OneRailSweepRailCrv )->GetCloseExt( OGLTransf ) != ENT_OPEN );
}

//------------------------------------------------------------------------------

void TReverseSubdivision::InitValuesTwoRailsSweep( )
{
	TOGLPolygonList *OGLList_railcrv1, *OGLList_railcrv2, *OGLList_formcrv;

	if ( !OGLTransf || !Params || !Params->TwoRailsSweepRail1Crv || !Params->TwoRailsSweepRail2Crv || !Params->TwoRailsSweepFormCrv ) return;

	OGLList_railcrv1 = Params->TwoRailsSweepRail1Crv->GetOGLGeom3D( OGLTransf );
	if ( !OGLList_railcrv1 || OGLList_railcrv1->Count( ) != 1 ) return;
	OGLList_railcrv2 = Params->TwoRailsSweepRail2Crv->GetOGLGeom3D( OGLTransf );
	if ( !OGLList_railcrv2 || OGLList_railcrv2->Count( ) != 1 ) return;
	OGLList_formcrv = Params->TwoRailsSweepFormCrv->GetOGLGeom3D( OGLTransf );
	if ( !OGLList_formcrv || OGLList_formcrv->Count( ) != 1 ) return;

	// Establecemos parámetros
	Closed_V = ( ToShape( Params->TwoRailsSweepFormCrv )->GetCloseExt( OGLTransf ) != ENT_OPEN );
	Closed_V_First = Closed_V_Last = false;
	Closed_H = ( ToShape( Params->TwoRailsSweepRail1Crv )->GetCloseExt( OGLTransf ) != ENT_OPEN );
}

//------------------------------------------------------------------------------

void TReverseSubdivision::InitCornersRail1( int size )
{
	int i;

	if ( size <= 0 ) return;
	if ( !CornersRail1 || size != SizeCornersRail1 ) {
		if ( CornersRail1 ) delete[] CornersRail1;
		SizeCornersRail1 = size;
		CornersRail1 = new bool[ SizeCornersRail1 ];
	}
	for ( i = 0; i < SizeCornersRail1; i++ )
		CornersRail1[ i ] = false;
}

//------------------------------------------------------------------------------

void TReverseSubdivision::InvertCornersRail1( )
{
	int i;
	bool bAux;

	for ( i = 0; i < SizeCornersRail1 / 2; i++ ) {
		bAux = CornersRail1[ i ];
		CornersRail1[ i ] = CornersRail1[ SizeCornersRail1 - i - 1 ];
		CornersRail1[ SizeCornersRail1 - i - 1 ] = bAux;
	}
}

//------------------------------------------------------------------------------

void TReverseSubdivision::SetFirstAtCornersRail1( int index )
{
	int i, ii;
	bool *cornersAux;

	if ( index < 1 || index > ( SizeCornersRail1 - 1 ) ) return;

	cornersAux = new bool[ SizeCornersRail1 ];
	memcpy( cornersAux, CornersRail1, SizeCornersRail1 * sizeof( bool ) );
	for ( i = 0, ii = index; ii < SizeCornersRail1; i++, ii++ )
		CornersRail1[ i ] = cornersAux[ ii ];
	for ( ii = 0; ii < index; i++, ii++ )
		CornersRail1[ i ] = cornersAux[ ii ];
	delete[] cornersAux;
}

//------------------------------------------------------------------------------

void TReverseSubdivision::InitCornersRail2( int size )
{
	int i;

	if ( size <= 0 ) return;
	if ( !CornersRail2 || size != SizeCornersRail2 ) {
		if ( CornersRail2 ) delete[] CornersRail2;
		SizeCornersRail2 = size;
		CornersRail2 = new bool[ SizeCornersRail2 ];
	}
	for ( i = 0; i < SizeCornersRail2; i++ )
		CornersRail2[ i ] = false;
}

//------------------------------------------------------------------------------

void TReverseSubdivision::InvertCornersRail2( )
{
	int i;
	bool bAux;

	for ( i = 0; i < SizeCornersRail2 / 2; i++ ) {
		bAux = CornersRail2[ i ];
		CornersRail2[ i ] = CornersRail2[ SizeCornersRail2 - i - 1 ];
		CornersRail2[ SizeCornersRail2 - i - 1 ] = bAux;
	}
}

//------------------------------------------------------------------------------

void TReverseSubdivision::SetFirstAtCornersRail2( int index )
{
	int i, ii;
	bool *cornersAux;

	if ( index < 1 || index > ( SizeCornersRail2 - 1 ) ) return;

	cornersAux = new bool[ SizeCornersRail2 ];
	memcpy( cornersAux, CornersRail2, SizeCornersRail2 * sizeof( bool ) );
	for ( i = 0, ii = index; ii < SizeCornersRail2; i++, ii++ )
		CornersRail2[ i ] = cornersAux[ ii ];
	for ( ii = 0; ii < index; i++, ii++ )
		CornersRail2[ i ] = cornersAux[ ii ];
	delete[] cornersAux;
}

//------------------------------------------------------------------------------

void TReverseSubdivision::InitCornersForm( int size )
{
	int i;

	if ( size <= 0 ) return;
	if ( !CornersForm || size != SizeCornersForm ) {
		if ( CornersForm ) delete[] CornersForm;
		SizeCornersForm = size;
		CornersForm = new bool[ SizeCornersForm ];
	}
	for ( i = 0; i < SizeCornersForm; i++ )
		CornersForm[ i ] = false;
}

//------------------------------------------------------------------------------

void TReverseSubdivision::InvertCornersForm( )
{
	int i;
	bool bAux;

	for ( i = 0; i < SizeCornersForm / 2; i++ ) {
		bAux = CornersForm[ i ];
		CornersForm[ i ] = CornersForm[ SizeCornersForm - i - 1 ];
		CornersForm[ SizeCornersForm - i - 1 ] = bAux;
	}
}

//------------------------------------------------------------------------------

void TReverseSubdivision::SetFirstAtCornersForm( int index )
{
	int i, ii;
	bool *cornersAux;

	if ( index < 1 || index > ( SizeCornersForm - 1 ) ) return;

	cornersAux = new bool[ SizeCornersForm ];
	memcpy( cornersAux, CornersForm, SizeCornersForm * sizeof( bool ) );
	for ( i = 0, ii = index; ii < SizeCornersForm; i++, ii++ )
		CornersForm[ i ] = cornersAux[ ii ];
	for ( ii = 0; ii < index; i++, ii++ )
		CornersForm[ i ] = cornersAux[ ii ];
	delete[] cornersAux;
}

//------------------------------------------------------------------------------

void TReverseSubdivision::InitNormalsRail1( int size )
{
	int i;

	if ( size <= 0 ) return;
	if ( !NormalsRail1 || size != SizeNormalsRail1 ) {
		if ( NormalsRail1 ) delete[] NormalsRail1;
		SizeNormalsRail1 = size;
		NormalsRail1 = new T3DPoint[ SizeNormalsRail1 ];
	}
	for ( i = 0; i < SizeNormalsRail1; i++ )
		NormalsRail1[ i ] = T3DPoint( 0.0, 0.0, 0.0 );
}

//------------------------------------------------------------------------------

void TReverseSubdivision::InvertNormalsRail1( )
{
	int i;
	T3DPoint point;

	for ( i = 0; i < SizeNormalsRail1 / 2; i++ ) {
		point = NormalsRail1[ i ];
		NormalsRail1[ i ] = NormalsRail1[ SizeNormalsRail1 - i - 1 ];
		NormalsRail1[ SizeNormalsRail1 - i - 1 ] = point;
	}
}

//------------------------------------------------------------------------------

void TReverseSubdivision::SetFirstAtNormalsRail1( int index )
{
	int i, ii;
	T3DPoint *normalsAux;

	if ( index < 1 || index > ( SizeNormalsRail1 - 1 ) ) return;

	normalsAux = new T3DPoint[ SizeNormalsRail1 ];
	memcpy( normalsAux, NormalsRail1, SizeNormalsRail1 * sizeof( T3DPoint ) );
	for ( i = 0, ii = index; ii < SizeNormalsRail1; i++, ii++ )
		NormalsRail1[ i ] = normalsAux[ ii ];
	for ( ii = 0; ii < index; i++, ii++ )
		NormalsRail1[ i ] = normalsAux[ ii ];
	delete[] normalsAux;
}

//------------------------------------------------------------------------------

bool TReverseSubdivision::IsCornerRail1( int index )
{
	if ( !CornersRail1 || index < 0 || index >= SizeCornersRail1 ) return false;

	return CornersRail1[ index ];
}

//------------------------------------------------------------------------------

bool TReverseSubdivision::IsCornerRail2( int index )
{
	if ( !CornersRail2 || index < 0 || index >= SizeCornersRail2 ) return false;

	return CornersRail2[ index ];
}

//------------------------------------------------------------------------------

bool TReverseSubdivision::IsCornerForm( int index )
{
	if ( !CornersForm || index < 0 || index >= SizeCornersForm ) return false;

	return CornersForm[ index ];
}

//------------------------------------------------------------------------------

bool TReverseSubdivision::GenFineVertexs( )
{
	bool ret;

	if ( FineVertexs ) FineVertexs->Clear( );
	else
		FineVertexs = new TOGLPolygonList( );

	switch ( Type ) {
		case ST_REVOLVE: ret = GenFineVertexsRevolve( ); break;

		case ST_ONE_RAIL_SWEEP: ret = GenFineVertexsOneRailSweep( ); break;

		case ST_TWO_RAILS_SWEEP: ret = GenFineVertexsTwoRailsSweep( ); break;

		default: ret = false; break;
	}

	return ret;
}

//------------------------------------------------------------------------------

bool TReverseSubdivision::GenFineVertexsRevolve( )
{
	int i, nsecs, npoints, nMidSecs, nSubSecs;
	double rotAngle, minDist, maxDist;
	T3DVector vecRot;
	TNMatrix matRot;
	T3DPoint point3D;
	TOGLPolygon polBaseCrv;
	TOGLPolygonList *OGLList;
	TCadShape *dualshape;

	if ( !OGLTransf || !Params || !Params->RevolveBaseCrv || !Params->RevolveAxis ) return false;
	if ( !Params->IsValid( LPM_CREATIONTYPE_REVOLVE ) || Level < 1 || Level > 10 ) return false;

	// Obtenemos el número de puntos gruesos que tendrá la low
	dualshape = ToShape( Params->RevolveBaseCrv->GetDualBaseEntity( ) );
	if ( !dualshape ) return false;
	OGLList = dualshape->GetOGLDualGeom3D( OGLTransf );
	polBaseCrv.Set( OGLList->GetItem( 0 ) );

	minDist = 1.0 - 0.9 * Params->RevolvePrecision;
	if ( Params->RevolveBaseCrv->Count( ) > 0 ) {
		maxDist = polBaseCrv.Perimeter( ) / Params->RevolveBaseCrv->Count( );
		maxDist *= ( fabs( 1.0 - 0.5 * Params->RevolvePrecision ) );
	} else
		maxDist = 0.0;
	polBaseCrv.Filter( minDist, 0, 0, maxDist );
	npoints = polBaseCrv.Count( );
	polBaseCrv.Clear( );

	// Calculamos el número de puntos finos
	for ( i = 0; i < Level; i++ )
		npoints += ( Closed_V ? npoints : ( npoints - 1 ) );

	// Obtenemos los puntos finos iniciales de la curva
	OGLList->GetItem( 0 )->GetNEquidistantPoints( Closed_V ? npoints + 1 : npoints, &polBaseCrv );
	if ( Closed_V ) polBaseCrv.DeleteItem( npoints );

	// Generamos las secciones necesarias para posteriormente hacer la subdivisión inversa.
	// Necesitamos solo 3 secciones iniciales y tantas intermedias como se generarian por subdivisión según el valor level
	// La primera sección y la última se tratarán como bordes aunque se trate de una revolución completa
	nMidSecs = 1;
	for ( i = 0; i < ( Level - 1 ); i++ )
		nMidSecs = ( 2 * nMidSecs ) + 1;
	nSubSecs = ( 2 * nMidSecs ) + 3;

	nsecs = ( Closed_H ? Params->RevolveSections : Params->RevolveSections + 1 );
	for ( i = 0; i < Level; i++ )
		nsecs += ( Closed_H ? nsecs : ( nsecs - 1 ) );
	rotAngle = Params->RevolveAngleFin - Params->RevolveAngleIni;
	rotAngle /= nsecs;
	OGLList = Params->RevolveAxis->GetOGLGeom3D( OGLTransf );
	vecRot = T3DVector( OGLList->GetFirstItem( )->GetFirstItem( )->v.GetPoint( ), OGLList->GetFirstItem( )->GetLastItem( )->v.GetPoint( ) );
	matRot = TNRotateMatrix( rotAngle * M_PI_180, vecRot );
	for ( i = 0; i < nSubSecs; i++ ) {
		FineVertexs->Add( &polBaseCrv );
		polBaseCrv.ApplyMatrix( &matRot );
	}

	return true;
}

//------------------------------------------------------------------------------

bool TReverseSubdivision::GenFineVertexsOneRailSweep( )
{
	int i, n, index, nFinePointsRail, nFinePointsForm;
	double perRail, pct;
	T3DVector vecRot;
	TNMatrix matrix, matrixT;
	T3DPoint pt3d, normal, center, *points;
	T3DPlane planeOri, planeDest;
	T3DVector vec;
	TOGLPolygon polRailCrv, polRailEqui, polFormCrv, polFormEqui;
	TOGLPolygonList *OGLList;
	TOGLFloat3 v1, v2;
	TCadShape *dualshape;

	if ( !OGLTransf || !Params || !Params->OneRailSweepRailCrv || !Params->OneRailSweepFormCrv ) return false;
	if ( !Params->IsValid( LPM_CREATIONTYPE_ONE_RAIL_SWEEP ) || Level < 1 || Level > 10 ) return false;

	// Obtenemos los oglpolygon de las curvas rail y forma
	dualshape = ToShape( Params->OneRailSweepRailCrv->GetDualBaseEntity( ) );
	if ( !dualshape ) return false;
	OGLList = dualshape->GetOGLDualGeom3D( OGLTransf );
	polRailCrv.Set( OGLList->GetFirstItem( ) );
	dualshape = ToShape( Params->OneRailSweepFormCrv->GetDualBaseEntity( ) );
	if ( !dualshape ) return false;
	OGLList = dualshape->GetOGLDualGeom3D( OGLTransf );
	polFormCrv.Set( OGLList->GetFirstItem( ) );

	// Si es un rail cerrado buscamos el punto mas cercano a la forma y empezamos por el
	// Si es abierto empezaremos por el extremo mas cercano
	center = polFormCrv.GravityCenter( );
	n = polRailCrv.Count( );
	if ( Closed_H ) {
		points = new T3DPoint[ n ];
		for ( i = 0; i < n; i++ )
			points[ i ] = polRailCrv.GetItem( i )->v.GetPoint( );
		index = _GetNearestPoint( n, points, center );
		polRailCrv.SetFirstAt( index );
		delete[] points;
	} else {
		if ( polRailCrv.GetFirstItem( )->v.GetPoint( ).DistanciaSqr( center ) > polRailCrv.GetItem( n - 1 )->v.GetPoint( ).DistanciaSqr( center ) ) polRailCrv.Invert( );
	}
	// Si la forma es cerrada buscamos el punto mas cercano al primer punto del rail y empezamos por el
	// Si es abierto empezamos por el ectremo mas cercano
	if ( Closed_V ) {
		polFormCrv.GetNearestVertex( &polRailCrv.GetFirstItem( )->v, false, 0, 0, index, v1 );
		polFormCrv.SetFirstAt( index );
	} else {
		if ( polFormCrv.GetFirstItem( )->v.GetPoint( ).DistanciaSqr( polRailCrv.GetFirstItem( )->v.GetPoint( ) ) > polFormCrv.GetItem( polFormCrv.Count( ) - 1 )->v.GetPoint( ).DistanciaSqr( polRailCrv.GetFirstItem( )->v.GetPoint( ) ) ) polFormCrv.Invert( );
	}

	// Obtenemos los puntos finos iniciales de la curva rail
	nFinePointsRail = ( Closed_H ? Params->OneRailSweepRailSections : Params->OneRailSweepRailSections + 1 );
	for ( i = 0; i < Level; i++ )
		nFinePointsRail += ( Closed_H ? nFinePointsRail : ( nFinePointsRail - 1 ) );
	polRailCrv.GetNEquidistantPoints( Closed_H ? nFinePointsRail + 1 : nFinePointsRail, &polRailEqui );
	if ( Closed_H ) polRailEqui.DeleteItem( nFinePointsRail );

	if ( debug ) {
		WriteSection( L"d:\\Inescop\\Subsoles\\debug\\Barrido\\Barrido_puntos rail.asc", L"w", &polRailCrv );
		WriteSection( L"d:\\Inescop\\Subsoles\\debug\\Barrido\\Barrido_puntos rail - Finos.asc", L"w", &polRailEqui );
	}

	// Obtenemos los puntos finos iniciales de la curva de forma
	nFinePointsForm = ( Closed_V ? Params->OneRailSweepFormSections : Params->OneRailSweepFormSections + 1 );
	for ( i = 0; i < Level; i++ )
		nFinePointsForm += ( Closed_V ? nFinePointsForm : ( nFinePointsForm - 1 ) );
	polFormCrv.GetNEquidistantPoints( Closed_V ? nFinePointsForm + 1 : nFinePointsForm, &polFormEqui );
	if ( Closed_V ) polFormEqui.DeleteItem( nFinePointsForm );

	if ( debug ) {
		WriteSection( L"d:\\Inescop\\Subsoles\\debug\\Barrido\\Barrido_puntos forma.asc", L"w", &polFormCrv );
		WriteSection( L"d:\\Inescop\\Subsoles\\debug\\Barrido\\Barrido_puntos forma - Finos.asc", L"w", &polFormEqui );
	}

	// Trasladamos la curva de forma al primer punto de la curva rail
	vec = T3DVector( polFormEqui.GetFirstItem( )->v.GetPoint( ), polRailEqui.GetFirstItem( )->v.GetPoint( ) );
	matrixT = TNTraslationMatrix( vec );
	polFormEqui.ApplyMatrix( &matrixT );

	// Generamos las secciones necesarias para posteriormente hacer la subdivisión inversa.
	perRail = polRailCrv.Perimeter( );
	pct = polRailCrv.GetPct( &polRailEqui.GetFirstItem( )->v, perRail );
	polRailCrv.GetPointAndNormalFromPct( pct, perRail, pt3d, normal, 1.0, T3DPoint( 0.0, 0.0, 0.0 ) );
	vec = T3DVector( T3DSize( normal.x, normal.y, normal.z ), pt3d );
	planeOri = T3DPlane( pt3d, vec );
	FineVertexs->Add( &polFormEqui );

	for ( i = 1; i < nFinePointsRail; i++ ) {
		pct = polRailCrv.GetPct( &polRailEqui.GetItem( i )->v, perRail );
		polRailCrv.GetPointAndNormalFromPct( pct, perRail, pt3d, normal, 1.0, T3DPoint( 0.0, 0.0, 0.0 ) );
		vec = T3DVector( T3DSize( normal.x, normal.y, normal.z ), pt3d );
		planeDest = T3DPlane( pt3d, vec );

		matrix = _GetMatrixTransformPlaneToPlane( planeOri, planeDest, Params->OneRailSweepAdaptCurvature );
		planeOri = planeDest;

		polFormEqui.ApplyMatrix( &matrix );
		FineVertexs->Add( &polFormEqui );
	}

	// Trasladamos todo a la posición inicial de la curva de forma
	matrixT = matrixT.Inverse( );
	FineVertexs->ApplyMatrix( &matrixT );

	return true;
}

//------------------------------------------------------------------------------

bool TReverseSubdivision::GenFineVertexsTwoRailsSweep( )
{
	int i, nFinePointsRail, nFinePointsForm;
	double size1, size2, incrSize, perRail1, pct;
	TNMatrix matrixR, matrixT;
	T3DPoint pt3d1, pt3d2, pt3d3, pt1Form, pt2Form, normal;
	T3DPlane plane1, plane2, rail1PlaneOri, rail1PlaneDest, rail2PlaneOri, rail2PlaneDest;
	T3DVector vec, vecForm;
	TOGLFloat3 v1, v2;
	TOGLPolygon polRail1Crv, polRail1Equi, polRail2Crv, polRail2Equi, polFormCrv, polFormEqui, polInt;
	TOGLPolygonList *OGLList;
	TCadShape *dualshape;

	if ( !OGLTransf || !Params || !Params->TwoRailsSweepRail1Crv || !Params->TwoRailsSweepRail2Crv || !Params->TwoRailsSweepFormCrv ) return false;
	if ( ToShape( Params->TwoRailsSweepRail1Crv )->GetCloseExt( OGLTransf ) != ToShape( Params->TwoRailsSweepRail2Crv )->GetCloseExt( OGLTransf ) ) return false;
	if ( !Params->IsValid( LPM_CREATIONTYPE_TWO_RAILS_SWEEP ) || Level < 1 || Level > 10 ) return false;

	// Obtenemos los oglpolygon de las curvas rail y forma
	dualshape = ToShape( Params->TwoRailsSweepRail1Crv->GetDualBaseEntity( ) );
	if ( !dualshape ) return false;
	OGLList = dualshape->GetOGLDualGeom3D( OGLTransf );
	polRail1Crv.Set( OGLList->GetFirstItem( ) );
	dualshape = ToShape( Params->TwoRailsSweepRail2Crv->GetDualBaseEntity( ) );
	if ( !dualshape ) return false;
	OGLList = dualshape->GetOGLDualGeom3D( OGLTransf );
	polRail2Crv.Set( OGLList->GetFirstItem( ) );
	dualshape = ToShape( Params->TwoRailsSweepFormCrv->GetDualBaseEntity( ) );
	if ( !dualshape ) return false;
	OGLList = dualshape->GetOGLDualGeom3D( OGLTransf );
	polFormCrv.Set( OGLList->GetFirstItem( ) );

	// Si los railes son cerrados nos aseguramos van en el mismo sentido.
	// Si son abiertos forzamos que empiecen por su extremo más cercano a la forma.
	if ( Closed_H ) {
		pt3d1 = polRail1Crv.GravityCenter( );
		pt3d2 = polRail2Crv.GravityCenter( );
		plane1 = T3DPlane( pt3d1, T3DVector( pt3d1, pt3d2 ) );
		if ( _IsClockWise( &polRail1Crv, plane1 ) != _IsClockWise( &polRail2Crv, plane1 ) ) polRail2Crv.Invert( );
	} else {
		pt3d1 = polFormCrv.GravityCenter( );
		pt3d2 = polRail1Crv.GetFirstItem( )->v.GetPoint( );
		pt3d3 = polRail1Crv.GetLastItem( )->v.GetPoint( );
		if ( pt3d1.DistanciaSqr( pt3d2 ) > pt3d1.DistanciaSqr( pt3d3 ) ) polRail1Crv.Invert( );
		pt3d2 = polRail2Crv.GetFirstItem( )->v.GetPoint( );
		pt3d3 = polRail2Crv.GetLastItem( )->v.GetPoint( );
		if ( pt3d1.DistanciaSqr( pt3d2 ) > pt3d1.DistanciaSqr( pt3d3 ) ) polRail2Crv.Invert( );
	}

	// Búsqueda de los puntos pt1Form y pt2Form
	if ( Closed_V ) {
		// La forma es cerrada
		if ( Closed_H ) {
			// Si railes y forma son cerradas establecemos los puntos iniciales de los railes como los mas cercanos a la forma
			polRail1Crv.GetPolNearestVertex( &polFormCrv, false, 0, 0, i, v1 );
			polRail1Crv.SetFirstAt( i );
			polRail2Crv.GetPolNearestVertex( &polFormCrv, false, 0, 0, i, v1 );
			polRail2Crv.SetFirstAt( i );
		}

		// Los puntos pt2Form y pt2Form de la forma serán los mas cercanos a los puntos iniciales de los railes
		polFormCrv.GetNearestVertex( &polRail1Crv.GetFirstItem( )->v, false, 0, 0, i, v1 );
		pt1Form = v1.GetPoint( );
		polFormCrv.GetNearestVertex( &polRail2Crv.GetFirstItem( )->v, false, 0, 0, i, v1 );
		pt2Form = v1.GetPoint( );
	} else {
		// La forma es abierta
		if ( Closed_H ) {
			pt3d1 = polFormCrv.GetFirstItem( )->v.GetPoint( );
			v1.SetPoint( pt3d1 );
			polRail1Crv.GetNearestPoint( &v1, pt3d2 );
			polRail2Crv.GetNearestPoint( &v1, pt3d3 );
			if ( pt3d1.DistanciaSqr( pt3d2 ) < pt3d1.DistanciaSqr( pt3d3 ) ) {
				pt1Form = polFormCrv.GetFirstItem( )->v.GetPoint( );
				pt2Form = polFormCrv.GetLastItem( )->v.GetPoint( );
			} else {
				pt1Form = polFormCrv.GetLastItem( )->v.GetPoint( );
				pt2Form = polFormCrv.GetFirstItem( )->v.GetPoint( );
			}
			v1.SetPoint( pt1Form );
			polRail1Crv.GetNearestVertex( &v1, false, 0, 0, i, v2 );
			polRail1Crv.SetFirstAt( i );
			v1.SetPoint( pt2Form );
			polRail2Crv.GetNearestVertex( &v1, false, 0, 0, i, v2 );
			polRail2Crv.SetFirstAt( i );
		} else {
			// Railes abiertos: establecemos pt1Form y pt2Form como el primer y ultimo punto de la misma
			pt3d1 = polRail1Crv.GetFirstItem( )->v.GetPoint( );
			pt3d2 = polRail2Crv.GetFirstItem( )->v.GetPoint( );
			pt1Form = polFormCrv.GetFirstItem( )->v.GetPoint( );
			pt2Form = polFormCrv.GetLastItem( )->v.GetPoint( );
			if ( pt3d1.DistanciaSqr( pt1Form ) > pt3d1.DistanciaSqr( pt2Form ) ) {
				pt1Form = polFormCrv.GetLastItem( )->v.GetPoint( );
				pt2Form = polFormCrv.GetFirstItem( )->v.GetPoint( );
			}
		}
	}

	// Obtenemos los puntos finos iniciales de la primera curva rail
	nFinePointsRail = ( Closed_H ? Params->TwoRailsSweepRailSections : Params->TwoRailsSweepRailSections + 1 );
	for ( i = 0; i < Level; i++ )
		nFinePointsRail += ( Closed_H ? nFinePointsRail : ( nFinePointsRail - 1 ) );
	polRail1Crv.GetNEquidistantPoints( Closed_H ? nFinePointsRail + 1 : nFinePointsRail, &polRail1Equi );
	if ( Closed_H ) polRail1Equi.DeleteItem( nFinePointsRail );

	// Obtenemos los puntos finos iniciales de la segunda curva rail
	polRail2Crv.GetNEquidistantPoints( Closed_H ? nFinePointsRail + 1 : nFinePointsRail, &polRail2Equi );
	if ( Closed_H ) polRail2Equi.DeleteItem( nFinePointsRail );

	// Obtenemos los puntos finos iniciales de la curva de forma
	nFinePointsForm = ( Closed_V ? Params->TwoRailsSweepFormSections : Params->TwoRailsSweepFormSections + 1 );
	for ( i = 0; i < Level; i++ )
		nFinePointsForm += ( Closed_V ? nFinePointsForm : ( nFinePointsForm - 1 ) );
	polFormCrv.GetNEquidistantPoints( Closed_V ? nFinePointsForm + 1 : nFinePointsForm, &polFormEqui );
	if ( Closed_V ) polFormEqui.DeleteItem( nFinePointsForm );

	// Trasladamos la curva de forma: pt1Form al primer punto de la curva rail
	pt3d1 = polRail1Equi.GetFirstItem( )->v.GetPoint( );
	vec = T3DVector( pt1Form, pt3d1 );
	matrixT = TNTraslationMatrix( vec );
	polFormEqui.ApplyMatrix( &matrixT );

	// Generamos las secciones necesarias para posteriormente hacer la subdivisión inversa.
	perRail1 = polRail1Crv.Perimeter( );
	pct = polRail1Crv.GetPct( &polRail1Equi.GetFirstItem( )->v, perRail1 );
	polRail1Crv.GetPointAndNormalFromPct( pct, perRail1, pt3d1, normal, 1.0, T3DPoint( 0.0, 0.0, 0.0 ) );
	vec = T3DVector( T3DSize( normal.x, normal.y, normal.z ), pt3d1 );
	rail1PlaneOri = T3DPlane( pt3d1, vec );

	pt3d1 = polRail1Equi.GetFirstItem( )->v.GetPoint( );
	pt3d2 = polRail2Equi.GetFirstItem( )->v.GetPoint( );
	vec = T3DVector( pt3d1, pt3d2 );
	rail2PlaneOri = T3DPlane( pt3d1, vec );

	FineVertexs->Add( &polFormEqui );

	size1 = pt3d1.DistanciaSqr( pt3d2 );
	vecForm = T3DVector( pt1Form, pt2Form );

	for ( i = 1; i < nFinePointsRail; i++ ) {
		// Aplicamos rotación por cambio de sección sobre rail1
		pct = polRail1Crv.GetPct( &polRail1Equi.GetItem( i )->v, perRail1 );
		polRail1Crv.GetPointAndNormalFromPct( pct, perRail1, pt3d1, normal, 1.0, T3DPoint( 0.0, 0.0, 0.0 ) );
		vec = T3DVector( T3DSize( normal.x, normal.y, normal.z ), pt3d1 );
		rail1PlaneDest = T3DPlane( pt3d1, vec );
		matrixR = _GetMatrixTransformPlaneToPlane( rail1PlaneOri, rail1PlaneDest );
		rail1PlaneOri = rail1PlaneDest;
		polFormEqui.ApplyMatrix( &matrixR );
		rail2PlaneOri.ApplyMatrix( matrixR );
		vecForm.ApplyMatrix( matrixR );

		// Aplicamos rotación por cambio de sección sobre rail2
		pt3d1 = polRail1Equi.GetItem( i )->v.GetPoint( );
		pt3d2 = polRail2Equi.GetItem( i )->v.GetPoint( );
		vec = T3DVector( pt3d1, pt3d2 );
		rail2PlaneDest = T3DPlane( pt3d1, vec );
		matrixR = _GetMatrixTransformPlaneToPlane( rail2PlaneOri, rail2PlaneDest );
		rail2PlaneOri = rail2PlaneDest;
		polFormEqui.ApplyMatrix( &matrixR );
		vecForm.ApplyMatrix( matrixR );

		// Escalamos con rotación previa a plano XY
		size2 = pt3d1.DistanciaSqr( pt3d2 );
		incrSize = sqrt( size2 / size1 );
		if ( fabs( incrSize - 1.0 ) > RES_COMP ) {
			size1 = size2;

			plane1 = T3DPlane( vecForm.org, vecForm );
			plane2 = T3DPlane( plXY );
			matrixR = _GetMatrixTransformPlaneToPlane( plane1, plane2 );
			polFormEqui.ApplyMatrix( &matrixR );
			polFormEqui.Scale( T3DPoint( incrSize, incrSize, incrSize ) );
			matrixR = matrixR.Inverse( );
			polFormEqui.ApplyMatrix( &matrixR );
		}

		FineVertexs->Add( &polFormEqui );
	}

	// Trasladamos todo a la posición inicial de la curva de forma
	matrixT = matrixT.Inverse( );
	FineVertexs->ApplyMatrix( &matrixT );

	return true;
}

//------------------------------------------------------------------------------

void TReverseSubdivision::GetCoarsePoints( T3DPoint *finePoints, int numFinePoints, T3DPoint **coarsePoints, int &numCoarsePoint, int numTimes, bool closed )
{
	int i, j, k, cont, numFinePointsPrev, endCont;
	//	float vect[ 7 ] = { 0.125, -0.5, 0.375, 1, 0.375, -0.5, 0.125 }; //Reversing subdivision rules: local linear conditions and observations on inner products Richard H. Bartels; Faramarz F. Samavati
	// 1/8, -1/2, 3/8, 1, 3/8, -1/2, 1/8 //Reversing subdivision rules: local linear conditions and observations on inner products Richard H. Bartels; Faramarz F. Samavati
	float vect[ 7 ] = { 23.0 / 196.0, -23.0 / 49.0, 9.0 / 28.0, 52.0 / 49.0, 9.0 / 28.0, -23.0 / 49.0, 23.0 / 196.0 }; // Reversing subdivision rules: local linear conditions and observations on inner products Richard H. Bartels; Faramarz F. Samavati
	T3DPoint ptCoarse, ptintersect;
	T3DPoint *coarsePointsAux;

	( *coarsePoints ) = 0;
	coarsePointsAux = finePoints;
	numCoarsePoint = numFinePoints / 2;
	numCoarsePoint = numFinePoints % 2 == 0 ? numCoarsePoint : numCoarsePoint + 1;
	numFinePointsPrev = numFinePoints;
	for ( k = 0; k < numTimes; k++ ) {
		( *coarsePoints ) = new T3DPoint[ numCoarsePoint ];
		cont = 0;
		if ( !closed ) {
			( *coarsePoints )[ cont++ ] = coarsePointsAux[ 0 ];
			i = 1;
		} else
			i = 0;
		if ( !closed ) endCont = numFinePointsPrev - 2;
		else
			endCont = numFinePointsPrev;
		for ( ; i < endCont; i += 2 ) { // El punto central del vector es el que se aplica sobre el punto objetivo
			ptCoarse = coarsePointsAux[ i ] * vect[ 3 ];
			for ( j = 1; j <= 3; j++ ) {
				if ( !closed ) {
					if ( i - j >= 0 ) ptCoarse = ptCoarse + coarsePointsAux[ i - j ] * vect[ 3 - j ];
				} else {
					ptCoarse = ptCoarse + coarsePointsAux[ i - j >= 0 ? i - j : numFinePointsPrev + ( i - j ) ] * vect[ 3 - j ];
				}

				if ( !closed ) {
					if ( i + j < numFinePointsPrev ) ptCoarse = ptCoarse + coarsePointsAux[ i + j ] * vect[ 3 + j ];
				} else {
					ptCoarse = ptCoarse + coarsePointsAux[ i + j < numFinePointsPrev ? i + j : ( i + j ) - numFinePointsPrev ] * vect[ 3 + j ];
				}
			}
			( *coarsePoints )[ cont++ ] = ptCoarse;
		}
		if ( cont < numCoarsePoint - 1 ) {
			i = numFinePointsPrev - 1;
			ptCoarse = coarsePointsAux[ i ] * vect[ 3 ];
			for ( j = 1; j <= 3; j++ ) {
				if ( !closed ) {
					if ( i - j >= 0 ) ptCoarse = ptCoarse + coarsePointsAux[ i - j ] * vect[ 3 - j ];
				} else {
					ptCoarse = ptCoarse + coarsePointsAux[ i - j >= 0 ? i - j : numFinePointsPrev + ( i - j ) ] * vect[ 3 - j ];
				}

				if ( !closed ) {
					if ( i + j < numFinePointsPrev ) ptCoarse = ptCoarse + coarsePointsAux[ i + j ] * vect[ 3 + j ];
				} else {
					ptCoarse = ptCoarse + coarsePointsAux[ i + j < numFinePointsPrev ? i + j : ( i + j ) - numFinePointsPrev ] * vect[ 3 + j ];
				}
			}
			( *coarsePoints )[ cont++ ] = ptCoarse;
		}
		if ( cont < numCoarsePoint && !closed ) ( *coarsePoints )[ cont++ ] = coarsePointsAux[ numFinePointsPrev - 1 ];
		numCoarsePoint = cont;
		if ( k > 0 ) delete[] coarsePointsAux;
		if ( k < numTimes - 1 ) {
			coarsePointsAux = ( *coarsePoints );
			numFinePointsPrev = numCoarsePoint;
			numCoarsePoint = numCoarsePoint / 2;
			numCoarsePoint = numFinePointsPrev % 2 == 0 ? numCoarsePoint : numCoarsePoint + 1;
			if ( !closed ) endCont = numFinePointsPrev - 2;
			else
				endCont = numFinePointsPrev;
		}
	}

	if ( !( *coarsePoints ) ) {
		numCoarsePoint = numFinePoints;
		( *coarsePoints ) = new T3DPoint[ numCoarsePoint ];
		for ( k = 0; k < numCoarsePoint; k++ )
			( *coarsePoints )[ k ] = finePoints[ k ];
	}
}

//------------------------------------------------------------------------------

void TReverseSubdivision::GetVertexNeighbours( int sec, int pos, bool _closed_V, bool _closed_H, TOGLPolygon *vertexsEdge, TOGLPolygon *vertexsFace )
{
	int nsecs, npoints;

	if ( !FineVertexs || !vertexsEdge || !vertexsFace ) return;
	nsecs = FineVertexs->Count( );
	if ( sec < 0 || sec >= nsecs ) return;
	npoints = FineVertexs->GetItem( 0 )->Count( );
	if ( pos < 0 || pos >= npoints ) return;

	vertexsEdge->Clear( );
	if ( _closed_H || sec > 0 ) vertexsEdge->AddItem( FineVertexs->GetItem( sec > 0 ? sec - 1 : nsecs - 1 )->GetItem( pos ) );
	if ( _closed_V || pos > 0 ) vertexsEdge->AddItem( FineVertexs->GetItem( sec )->GetItem( pos > 0 ? pos - 1 : npoints - 1 ) );
	if ( _closed_H || sec < ( nsecs - 1 ) ) vertexsEdge->AddItem( FineVertexs->GetItem( ( sec + 1 ) % nsecs )->GetItem( pos ) );
	if ( _closed_V || pos < ( npoints - 1 ) ) vertexsEdge->AddItem( FineVertexs->GetItem( sec )->GetItem( ( pos + 1 ) % npoints ) );

	vertexsFace->Clear( );
	if ( ( _closed_H || sec > 0 ) && ( _closed_V || pos > 0 ) ) vertexsFace->AddItem( FineVertexs->GetItem( sec > 0 ? sec - 1 : nsecs - 1 )->GetItem( pos > 0 ? pos - 1 : npoints - 1 ) );
	if ( ( _closed_H || sec < ( nsecs - 1 ) ) && ( _closed_V || pos > 0 ) ) vertexsFace->AddItem( FineVertexs->GetItem( ( sec + 1 ) % nsecs )->GetItem( pos > 0 ? pos - 1 : npoints - 1 ) );
	if ( ( _closed_H || sec < ( nsecs - 1 ) ) && ( _closed_V || pos < ( npoints - 1 ) ) ) vertexsFace->AddItem( FineVertexs->GetItem( ( sec + 1 ) % nsecs )->GetItem( ( pos + 1 ) % npoints ) );
	if ( ( _closed_H || sec > 0 ) && ( _closed_V || pos < ( npoints - 1 ) ) ) vertexsFace->AddItem( FineVertexs->GetItem( sec > 0 ? sec - 1 : nsecs - 1 )->GetItem( ( pos + 1 ) % npoints ) );
}

//------------------------------------------------------------------------------
// Obtención de puntos Coarse a partir del cálculo de los puntos finos
bool TReverseSubdivision::GetReverseSubdivision( TOGLPolygonList *coarseVertexs )
{
	if ( !coarseVertexs ) return false;

	switch ( Type ) {
		case ST_REVOLVE: return GetReverseSubdivisionForRevolve( coarseVertexs );

		case ST_CONTOUR: return GetReverseSubdivisionForClosedCurve( coarseVertexs );

		case ST_ONE_RAIL_SWEEP:
		case ST_TWO_RAILS_SWEEP: return GetReverseSubdivisionForSweep( coarseVertexs );

		default: return false;
	}
}

//------------------------------------------------------------------------------
// Obtención de los puntos Coarse a partir de los puntos de control de las curvas
bool TReverseSubdivision::GetReverseSubdivisionSISL( TOGLPolygonList *coarseVertexs )
{
	if ( !coarseVertexs ) return false;

	switch ( Type ) {
		case ST_ONE_RAIL_SWEEP: return GetReverseSubdivisionSISLForOneRailSweep( coarseVertexs );

		case ST_TWO_RAILS_SWEEP: return GetReverseSubdivisionSISLForTwoRailsSweep( coarseVertexs );

		default: return false;
	}
}

//------------------------------------------------------------------------------
// Obtención básica de la lowpoly por subdivisión inversa de una malla de quads base para la generación de primitivas: revolución, barrido
bool TReverseSubdivision::GetReverseSubdivisionBasic( TOGLPolygonList *coarseVertexs, int _level, bool _closed_H, bool _closed_V )
{
	int i, j, k, nsecs, npoints;
	TOGLFloat3 v1, v2, v3;
	TOGLPoint point;
	TOGLPolygon pol, vertexsEdge, vertexsFace;

	if ( !coarseVertexs || _level < 1 ) return false;
	if ( FineVertexs->Count( ) == 0 ) return false;

	if ( debug ) WriteSections( L"d:\\Inescop\\Subsoles\\debug\\Barrido\\Barrido_puntos Finos.asc", L"w", FineVertexs );

	for ( i = 0; i < _level; i++ ) {
		nsecs = FineVertexs->Count( );
		npoints = FineVertexs->GetItem( 0 )->Count( );
		coarseVertexs->Clear( );
		for ( j = 0; j < nsecs; j += 2 ) {
			pol.Clear( );
			for ( k = 0; k < npoints; k += 2 ) {
				point.Set( FineVertexs->GetItem( j )->GetItem( k ) );

				GetVertexNeighbours( j, k, _closed_V, _closed_H, &vertexsEdge, &vertexsFace );
				if ( ( _closed_H || ( j > 0 && j < ( nsecs - 1 ) ) ) && ( _closed_V || ( k > 0 && k < ( npoints - 1 ) ) ) ) {
					// Vértices interiores con valencia 4
					v1.v[ 0 ] = 4.0 * point.v.v[ 0 ];
					v1.v[ 1 ] = 4.0 * point.v.v[ 1 ];
					v1.v[ 2 ] = 4.0 * point.v.v[ 2 ];
					v2 = vertexsEdge.GetItem( 0 )->v + vertexsEdge.GetItem( 1 )->v + vertexsEdge.GetItem( 2 )->v + vertexsEdge.GetItem( 3 )->v;
					v3 = vertexsFace.GetItem( 0 )->v + vertexsFace.GetItem( 1 )->v + vertexsFace.GetItem( 2 )->v + vertexsFace.GetItem( 3 )->v;
					v3.v[ 0 ] *= 0.25;
					v3.v[ 1 ] *= 0.25;
					v3.v[ 2 ] *= 0.25;
					point.v = v1 - v2 + v3;
				} else if ( vertexsEdge.Count( ) == 3 ) {
					// Vértices de borde
					v1.v[ 0 ] = 2.0 * point.v.v[ 0 ];
					v1.v[ 1 ] = 2.0 * point.v.v[ 1 ];
					v1.v[ 2 ] = 2.0 * point.v.v[ 2 ];
					if ( !_closed_H && j == 0 ) { // Borde izquierdo
						v2 = vertexsEdge.GetItem( 0 )->v;
						v3 = vertexsEdge.GetItem( 2 )->v;
					} else if ( !_closed_H && j == ( nsecs - 1 ) ) { // Borde derecho
						v2 = vertexsEdge.GetItem( 1 )->v;
						v3 = vertexsEdge.GetItem( 2 )->v;
					} else if ( !_closed_V && k == 0 ) { // Borde superior
						v2 = vertexsEdge.GetItem( 0 )->v;
						v3 = vertexsEdge.GetItem( 1 )->v;
					} else if ( !_closed_V && k == ( npoints - 1 ) ) { // Borde inferior
						v2 = vertexsEdge.GetItem( 0 )->v;
						v3 = vertexsEdge.GetItem( 2 )->v;
					}
					v2.v[ 0 ] *= 0.5;
					v2.v[ 1 ] *= 0.5;
					v2.v[ 2 ] *= 0.5;
					v3.v[ 0 ] *= 0.5;
					v3.v[ 1 ] *= 0.5;
					v3.v[ 2 ] *= 0.5;
					point.v = v1 - v2 - v3;
				} // Los vértices de esquina no se recalculan

				pol.AddItem( &point );
			}
			coarseVertexs->Add( &pol );
		}
		FineVertexs->Set( coarseVertexs );
	}

	if ( debug ) WriteSections( L"d:\\Inescop\\Subsoles\\debug\\Barrido\\Barrido_puntos Coarse.asc", L"w", FineVertexs );

	return true;
}

//------------------------------------------------------------------------------

bool TReverseSubdivision::GetReverseSubdivisionForRevolve( TOGLPolygonList *coarseVertexs ) // Reverse Catmull-Clark Subdivision. Sandrine Lanquetin. Marc Neveu
{
	int i, nsecs;
	double rotAngle;
	T3DVector vecRot;
	TNMatrix matRot;
	TOGLPolygonList *OGLList;

	if ( !coarseVertexs ) return false;
	if ( !GenFineVertexs( ) ) return false;

	// Al final obtendremos tres secciones iniciales.
	// La primera y la última se calculan como si fuesen bordes.
	if ( !GetReverseSubdivisionBasic( coarseVertexs, Level, false, Closed_V ) ) return false;

	// Montamos todas las secciones a partir de las 3 calculadas.
	// La sección central está inicialmente girada rotAngle grados.
	// La última lo está a 2*rotAngle grados
	nsecs = ( Closed_H ? Params->RevolveSections : Params->RevolveSections + 1 );
	rotAngle = Params->RevolveAngleFin - Params->RevolveAngleIni;
	rotAngle /= ( Closed_H ? nsecs : ( nsecs - 1 ) );

	// Ponemos todas las secciones a 0 grados
	// Vector de rotación
	OGLList = Params->RevolveAxis->GetOGLGeom3D( OGLTransf );
	vecRot = T3DVector( OGLList->GetFirstItem( )->GetFirstItem( )->v.GetPoint( ), OGLList->GetFirstItem( )->GetLastItem( )->v.GetPoint( ) );
	matRot = TNRotateMatrix( -( rotAngle * M_PI_180 ), vecRot );
	FineVertexs->GetItem( 1 )->ApplyMatrix( &matRot );
	matRot = TNRotateMatrix( -( 2 * rotAngle * M_PI_180 ), vecRot );
	FineVertexs->GetItem( 2 )->ApplyMatrix( &matRot );
	if ( Params->RevolveAngleIni != 0 ) {
		matRot = TNRotateMatrix( Params->RevolveAngleIni * M_PI_180, vecRot );
		FineVertexs->ApplyMatrix( &matRot );
	}

	coarseVertexs->Clear( );
	matRot = TNRotateMatrix( rotAngle * M_PI_180, vecRot );
	for ( i = 0; i < nsecs; i++ ) {
		if ( i == 0 && !Closed_H ) coarseVertexs->Add( FineVertexs->GetItem( 0 ) );
		else if ( i == ( nsecs - 1 ) && !Closed_H )
			coarseVertexs->Add( FineVertexs->GetItem( 2 ) );
		else
			coarseVertexs->Add( FineVertexs->GetItem( 1 ) );

		FineVertexs->GetItem( 1 )->ApplyMatrix( &matRot );
		FineVertexs->GetItem( 2 )->ApplyMatrix( &matRot );
	}

	return true;
}

//------------------------------------------------------------------------------

bool TReverseSubdivision::GetReverseSubdivisionForClosedCurve( TOGLPolygonList *coarseVertexs )
{
	int i, numTimesReverse, numpoints, numCoarsePoints, numFinePoints, numFinePointsBySegment, numFinePointsBySegmentTotal, ind, ind2, indini, nloops;
	double angledeg = 25, perTotal, *perimeters, distaverage, max, contourprecision;
	TCadShape *shape;
	TCadSurface *paramsurf;
	TCadTrimSurface *trim;
	T3DPoint *finePoints, *coarsePoints, *points;
	TOGLPolygonList *OGLList, auxlist, segments;
	TOGLPolygon *pol, pol2, polCorners, segment, polAux, contour, outIntersect;
	TOGLFloat3 oglfloat;

	if ( !Params || !Params->ContourBaseCrv || !ToShape( Params->ContourBaseCrv ) || ToShape( Params->ContourBaseCrv )->GetClose( OGLTransf ) == ENT_OPEN ) return false;
	if ( Params->ContourPrecision < 0.0 || Params->ContourPrecision > 1.0 ) return false;
	shape = ToShape( Params->ContourBaseCrv );

	numTimesReverse = Params->NumTimes;

	// CASO CON DETECCION DE ESQUINAS INICIAL Y LUEGO OBTENCION DE PUNTOS EQUIDISTANTES ENTRE CADA TRAMO
	paramsurf = shape->GetDualParamSurface( );
	if ( !paramsurf ) return false;

	OGLList = shape->GetOGLList( OGLTransf );
	if ( !OGLList || OGLList->Count( ) != 1 ) return false;

	trim = new TCadTrimSurface( paramsurf, shape, OGLTransf, RES_PARAM );
	trim->SetUseSurfaceSmallToDevelop( false );
	trim->GetExtOGLDevelop2DFromParam2D( OGLTransf, OGLList, &auxlist );
	delete trim;

	pol = auxlist.GetItem( 0 );
	if ( !auxlist.GetItem( 0 )->IsClockwise( plXY ) ) pol->Invert( );

	if ( Params->ContourThickness > RES_GEOM ) pol->Invert( );

	pol2.Set( pol );
	contourprecision = ( 1.0 - Params->ContourPrecision ) * 10 + 1;
	pol2.Filter( 0.5, 0, 0, contourprecision, false, false, false, true ); // Para saber cuantos puntos son los representativos

	numFinePoints = pol2.Count( );
	for ( i = 0; i < Params->NumTimes; i++ )
		numFinePoints = 2 * numFinePoints - 1;

	pol2.Set( pol );
	pol2.FilterMaxError( RES_GEOM );
	numpoints = pol2.Count( );
	if ( pol2.IsCloseExt( ) ) numpoints--;
	points = new T3DPoint[ numpoints ];
	for ( i = 0; i < numpoints; i++ ) {
		points[ i ].x = pol2.GetItem( i )->v.v[ 0 ];
		points[ i ].y = pol2.GetItem( i )->v.v[ 1 ];
	}
	ClosedCornerDetection( numpoints, points, angledeg, &polCorners );
	if ( polCorners.IsCloseExt( ) ) polCorners.DeleteItem( polCorners.Count( ) - 1 );
	delete[] points;

	if ( polCorners.Count( ) ) {
		perTotal = 0;
		perimeters = new double[ polCorners.Count( ) ];
		for ( i = 0; i < polCorners.Count( ) - 1; i++ ) {
			pol->GetNearestVertexX( &polCorners.GetItem( i )->v, ind, oglfloat );
			pol->GetNearestVertexX( &polCorners.GetItem( i + 1 )->v, ind2, oglfloat );

			if ( i == 0 ) indini = ind;

			pol->GetSubItem( &segment, ind, ind2 );
			segments.Add( &segment );
			perimeters[ i ] = segment.Perimeter( );
			perTotal += perimeters[ i ];
		}
		// Ultimo tramo
		pol->GetNearestVertexX( &polCorners.GetItem( polCorners.Count( ) - 1 )->v, ind, oglfloat );
		ind2 = pol->Count( ) - 1;
		pol->GetSubItem( &segment, ind, ind2 );
		segments.Add( &segment );
		perimeters[ i ] = segment.Perimeter( );
		perTotal += perimeters[ i ];
		if ( indini > 0 ) {
			pol->GetSubItem( &segment, 0, indini );
			segments.GetItem( segments.Count( ) - 1 )->Append( &segment );
			perimeters[ i ] += segment.Perimeter( );
			perTotal += segment.Perimeter( );
		}

		pol2.Clear( );
		numFinePointsBySegmentTotal = 0;
		for ( i = 0; i < polCorners.Count( ) - 1; i++ ) {
			numFinePointsBySegment = numFinePoints * ( perimeters[ i ] / perTotal );
			numFinePointsBySegmentTotal += numFinePointsBySegment;
			segments.GetItem( i )->GetNEquidistantPoints( numFinePointsBySegment, &polAux );
			polAux.DeleteItem( polAux.Count( ) - 1 );
			pol2.Append( &polAux );
		}
		// Ultimo tramo
		numFinePointsBySegment = numFinePoints - numFinePointsBySegmentTotal;
		segments.GetItem( segments.Count( ) - 1 )->GetNEquidistantPoints( numFinePointsBySegment, &polAux );
		pol2.Append( &polAux );

		polAux.Clear( );
		polAux.Set( &pol2 );

		delete[] perimeters;
	} else {
		pol->GetNEquidistantPoints( numFinePoints + 1, &polAux );
		polAux.GetItem( polAux.Count( ) - 1 )->Set( polAux.GetItem( 0 ) ); // soluciona problema de la funcion
	}

	finePoints = polAux.GetVertexs( numFinePoints );

	GetCoarsePoints( finePoints, numFinePoints, &coarsePoints, numCoarsePoints, numTimesReverse, shape->GetCloseExt( OGLTransf ) != ENT_OPEN );

	contour.SetType( GL_LINE_STRIP );
	contour.TessOrTrim = true;
	contour.SetVertexs( numCoarsePoints, coarsePoints );
	if ( !contour.IsCloseExt( ) ) { // Aqui si que lo queremos cerrado
		distaverage = contour.Perimeter( ) / contour.Count( );
		if ( contour.GetItem( 0 )->v.Distance( &contour.GetItem( contour.Count( ) - 1 )->v ) < distaverage / 5.0 ) contour.GetItem( contour.Count( ) - 1 )->Set( contour.GetItem( 0 ) );
		else
			contour.Close( );
	}

	delete[] coarsePoints;

	( *coarseVertexs ).Add( &contour );
	if ( !( *coarseVertexs ).Count( ) || ( *coarseVertexs ).GetItem( 0 )->Count( ) <= 3 ) {
		if ( finePoints ) delete[] finePoints;
		return false;
	}

	if ( ( *coarseVertexs ).GetItem( 0 )->IntersectItselfXY( &outIntersect ) ) {
		nloops = ( *coarseVertexs ).GetItem( 0 )->DivideByLoops( &auxlist, plXY );
		if ( nloops > 0 ) { // Nos quedamos con el loop del perimetro mayor
			max = 0;
			for ( i = 0; i < auxlist.Count( ); i++ ) {
				perTotal = auxlist.GetItem( i )->Perimeter( );
				if ( perTotal > max ) {
					max = perTotal;
					ind = i;
				}
			}
			( *coarseVertexs ).Clear( );
			( *coarseVertexs ).Add( auxlist.GetItem( ind ) );
		}
		if ( ( *coarseVertexs ).GetItem( 0 )->IntersectItselfXY( &outIntersect ) ) {
			if ( numTimesReverse <= 0 ) {
				if ( finePoints ) delete[] finePoints;
				return false;
			}
			do {
				GetCoarsePoints( finePoints, numFinePoints, &coarsePoints, numCoarsePoints, --numTimesReverse, shape->GetCloseExt( OGLTransf ) != ENT_OPEN );
				contour.Clear( );
				contour.SetVertexs( numCoarsePoints, coarsePoints );
				if ( !contour.IsCloseExt( ) ) contour.Close( );
				delete[] coarsePoints;
				( *coarseVertexs ).Clear( );
				( *coarseVertexs ).Add( &contour );
				if ( !( *coarseVertexs ).Count( ) || ( *coarseVertexs ).GetItem( 0 )->Count( ) <= 3 ) {
					if ( finePoints ) delete[] finePoints;
					return false;
				}
				outIntersect.Clear( );
				( *coarseVertexs ).GetItem( 0 )->IntersectItselfXY( &outIntersect );
			} while ( numTimesReverse > 0 && outIntersect.Count( ) );

			if ( outIntersect.Count( ) > 0 || numTimesReverse < 0 ) {
				if ( finePoints ) delete[] finePoints;
				return false;
			}
		}
	}

	if ( finePoints ) delete[] finePoints;
	return true;
}

//------------------------------------------------------------------------------

bool TReverseSubdivision::GetReverseSubdivisionForSweep( TOGLPolygonList *coarseVertexs ) // Reverse Catmull-Clark Subdivision. Sandrine Lanquetin. Marc Neveu
{
	if ( !coarseVertexs ) return false;
	if ( !GenFineVertexs( ) ) return false;

	if ( !GetReverseSubdivisionBasic( coarseVertexs, Level, Closed_H, Closed_V ) ) return false;

	return true;
}

//------------------------------------------------------------------------------

bool TReverseSubdivision::GetNControlPointsFromCurve( int n, TCadEntity *ent, TOGLPolygon *pol, bool *corners, T3DPoint *normals, T3DPoint *refPoint )
{
	bool endConditionChanged, addPoint, closedCurve;
	int i, j;
	double perRail, pct;
	T3DPoint p1, p2, prevP, *points, normal;
	TCadShape *dualshape;
	TCadIBSpline *ibspline;
	SISLCurve *sislcurve;
	TOGLPolygon polCrv, polEqui;
	TOGLPolygonList *OGLList;
	TOGLFloat3 oglFloat3;

	if ( n < 2 || !ent || !pol ) return false;

	// Nos aseguramos que el primer y ultimo punto no se repitan
	if ( ent->WhoAmI( ) == ST_IBSPLINE && ToIBSpline( ent )->GetEndCondition( ) == ENDC_CORNERS ) {
		ToIBSpline( ent )->SetEndCondition( ENDC_ZEROCURVATURE );
		endConditionChanged = true;
	} else
		endConditionChanged = false;

	dualshape = ToShape( ent->GetDualBaseEntity( ) );
	if ( !dualshape ) {
		if ( endConditionChanged ) ToIBSpline( ent )->SetEndCondition( ENDC_CORNERS );
		return false;
	}
	closedCurve = dualshape->GetClose( OGLTransf ) != ENT_OPEN;

	if ( corners ) {
		for ( i = 0; i < n; i++ )
			corners[ i ] = false;
	}

	// Obtenemos los n puntos 3D sobre la curva y construimos una IBSpline con ellos
	OGLList = dualshape->GetOGLDualGeom3D( OGLTransf );
	polCrv.Set( OGLList->GetFirstItem( ) );

	if ( refPoint ) {
		if ( closedCurve ) { // Ordenamos los puntos de la curva para que empiece por el más cercano a refPoint
			points = new T3DPoint[ polCrv.Count( ) ];
			for ( i = 0; i < polCrv.Count( ); i++ )
				points[ i ] = polCrv.GetItem( i )->v.GetPoint( );
			i = _GetNearestPoint( polCrv.Count( ), points, *refPoint );
			if ( i != 0 ) polCrv.SetFirstAt( i, true );
			delete[] points;
		} else { // Forzamos a que el primer punto de la curva sea el mas cercano a refPoint
			if ( polCrv.GetFirstItem( )->v.GetPoint( ).DistanciaSqr( *refPoint ) > polCrv.GetLastItem( )->v.GetPoint( ).DistanciaSqr( *refPoint ) ) polCrv.Invert( );
		}
	}

	polCrv.GetNSignificantPoints( n, &polEqui );

	// Si es una malla con subdivisión, obtenemos la SISL para usar sus puntos de control como puntos coarse.
	// Si no hay subdivisión, usamos los puntos significativos
	if ( Params->CreateSubdivision ) {
		points = new T3DPoint[ n ];
		for ( i = 0; i < n; i++ ) {
			points[ i ] = polEqui.GetItem( i )->v.GetPoint( );
		}
		ibspline = new TCadIBSpline( n, points );
		ibspline->SetClose( dualshape->GetClose( OGLTransf ) );
		delete[] points;
	} else
		ibspline = 0;

	// Buscamos las esquinas
	if ( corners || ibspline ) {
		if ( dualshape->WhoAmI( ) == ST_POLYLINE ) {
			for ( i = 0; i < dualshape->Count( ); i++ ) {
				for ( j = 0; j < n; j++ ) {
					if ( dualshape->GetDataPoint( OGLTransf, i ).Similar( polEqui.GetItem( j )->v.GetPoint( ), RES_TESSELATION ) ) {
						if ( corners ) corners[ j ] = true;
						if ( ibspline ) ibspline->SetCorner( j, true );
						break;
					}
				}
			}
		} else if ( dualshape->WhoAmI( ) == ST_IBSPLINE ) {
			for ( i = 0; i < dualshape->Count( ); i++ ) {
				if ( ToIBSpline( dualshape )->GetDataCorner( i ) ) {
					for ( j = 0; j < n; j++ ) {
						if ( dualshape->GetDataPoint( OGLTransf, i ).Similar( polEqui.GetItem( j )->v.GetPoint( ), RES_TESSELATION ) ) {
							if ( corners ) corners[ j ] = true;
							if ( ibspline ) ibspline->SetCorner( j, true );
							break;
						}
					}
				}
			}
		}
	}

	if ( Params->CreateSubdivision ) {
		// Obtenemos la SISL para usar sus puntos de control como puntos coarse.
		sislcurve = ibspline->GetSISLCurve( OGLTransf );
		if ( !sislcurve ) {
			if ( endConditionChanged ) ToIBSpline( ent )->SetEndCondition( ENDC_CORNERS );
			return false;
		}

		j = closedCurve ? ( sislcurve->in - 2 ) : ( sislcurve->in - 1 );
		for ( i = 1; i < j; i++ ) {
			p1.x = sislcurve->ecoef[ i * 3 ];
			p1.y = sislcurve->ecoef[ i * 3 + 1 ];
			p1.z = sislcurve->ecoef[ i * 3 + 2 ];
			addPoint = true;
			if ( i > 1 ) {
				p2.x = sislcurve->ecoef[ ( i - 1 ) * 3 ];
				p2.y = sislcurve->ecoef[ ( i - 1 ) * 3 + 1 ];
				p2.z = sislcurve->ecoef[ ( i - 1 ) * 3 + 2 ];
				if ( p1.Similar( p2 ) ) addPoint = false;
			}
			if ( addPoint ) pol->AddItem( &p1 );
		}
	} else {
		// Los puntos coarse son los putos equidistantes
		for ( i = 0; i < n; i++ ) {
			p1 = polEqui.GetItem( i )->v.GetPoint( );
			pol->AddItem( &p1 );
		}
	}

	// Cálculo de normales
	if ( normals ) {
		perRail = polCrv.Perimeter( );
		for ( i = 0; i < n; i++ ) {
			p1 = polEqui.GetItem( i )->v.GetPoint( );
			oglFloat3.v[ 0 ] = p1.x;
			oglFloat3.v[ 1 ] = p1.y;
			oglFloat3.v[ 2 ] = p1.z;
			pct = polCrv.GetPct( &oglFloat3, perRail );
			polCrv.GetPointAndNormalFromPct( pct, perRail, p1, normal, 1.0, T3DPoint( 0.0, 0.0, 0.0 ) );
			normals[ i ] = normal;
		}
	}

	if ( endConditionChanged ) ToIBSpline( ent )->SetEndCondition( ENDC_CORNERS );

	return true;
}

//------------------------------------------------------------------------------

void TReverseSubdivision::GetBestRefPoints( TCadEntity *crv1, TCadEntity *crv2, T3DPoint &pt1, T3DPoint &pt2 )
{
	int i, nPointsCrv1, nPointsCrv2, index, indexCrv1, indexCrv2;
	double dist, minDist;
	bool closedCrv1, closedCrv2;
	TCadShape *dualshape;
	TOGLPolygon polCrv1, polCrv2;
	TOGLPolygonList *OGLList;
	T3DPoint pointCrv, *pointsCrv1, *pointsCrv2;

	if ( !OGLTransf || !crv1 || !crv2 ) return;

	dualshape = ToShape( crv1->GetDualBaseEntity( ) );
	if ( !dualshape ) return;
	closedCrv1 = dualshape->GetClose( OGLTransf ) != ENT_OPEN;
	OGLList = dualshape->GetOGLDualGeom3D( OGLTransf );
	polCrv1.Set( OGLList->GetFirstItem( ) );
	nPointsCrv1 = polCrv1.Count( );
	if ( nPointsCrv1 == 0 ) return;

	dualshape = ToShape( crv2->GetDualBaseEntity( ) );
	if ( !dualshape ) return;
	closedCrv2 = dualshape->GetClose( OGLTransf ) != ENT_OPEN;
	OGLList = dualshape->GetOGLDualGeom3D( OGLTransf );
	polCrv2.Set( OGLList->GetFirstItem( ) );
	nPointsCrv2 = polCrv2.Count( );
	if ( nPointsCrv2 == 0 ) return;

	if ( closedCrv1 ) {
		pointsCrv1 = new T3DPoint[ nPointsCrv1 ];
		for ( i = 0; i < nPointsCrv1; i++ )
			pointsCrv1[ i ] = polCrv1.GetItem( i )->v.GetPoint( );
	} else {
		pointsCrv1 = new T3DPoint[ 2 ];
		pointsCrv1[ 0 ] = polCrv1.GetFirstItem( )->v.GetPoint( );
		pointsCrv1[ 1 ] = polCrv1.GetLastItem( )->v.GetPoint( );
		nPointsCrv1 = 2;
	}

	if ( closedCrv2 ) {
		pointsCrv2 = new T3DPoint[ nPointsCrv2 ];
		for ( i = 0; i < nPointsCrv2; i++ )
			pointsCrv2[ i ] = polCrv2.GetItem( i )->v.GetPoint( );
	} else {
		pointsCrv2 = new T3DPoint[ 2 ];
		pointsCrv2[ 0 ] = polCrv2.GetFirstItem( )->v.GetPoint( );
		pointsCrv2[ 1 ] = polCrv2.GetLastItem( )->v.GetPoint( );
		nPointsCrv2 = 2;
	}

	minDist = MAXDOUBLE;
	for ( i = 0; i < nPointsCrv1; i++ ) {
		index = _GetNearestPoint( nPointsCrv2, pointsCrv2, pointsCrv1[ i ], &dist );
		if ( dist < minDist ) {
			indexCrv1 = i;
			indexCrv2 = index;
			minDist = dist;
		}
	}

	pt1 = pointsCrv1[ indexCrv1 ];
	pt2 = pointsCrv2[ indexCrv2 ];

	delete[] pointsCrv1;
	delete[] pointsCrv2;
}

//------------------------------------------------------------------------------

bool TReverseSubdivision::GetReverseSubdivisionSISLForOneRailSweep( TOGLPolygonList *coarseVertexs )
{
	int i, nPointsRail, nPointsForm;
	TNMatrix matrixT1, matrixT2, matrixR;
	T3DPoint point1, point2;
	T3DVector vec;
	T3DPlane planeOri, planeDest;
	TOGLPolygon polRail, polForm;

	if ( !coarseVertexs ) return false;
	if ( !OGLTransf || !Params || !Params->OneRailSweepRailCrv || !Params->OneRailSweepFormCrv ) return false;
	if ( !Params->IsValid( LPM_CREATIONTYPE_ONE_RAIL_SWEEP ) ) return false;

	// Obtenemos los puntos coarse del rail y de la forma
	GetBestRefPoints( Params->OneRailSweepRailCrv, Params->OneRailSweepFormCrv, point1, point2 );
	nPointsRail = Closed_H ? Params->OneRailSweepRailSections : Params->OneRailSweepRailSections + 1;
	InitCornersRail1( nPointsRail );
	if ( Params->OneRailSweepAdaptCurvature ) InitNormalsRail1( nPointsRail );
	if ( !GetNControlPointsFromCurve( nPointsRail, Params->OneRailSweepRailCrv, &polRail, CornersRail1, Params->OneRailSweepAdaptCurvature ? NormalsRail1 : 0, &point2 ) ) return false;
	nPointsForm = Closed_V ? Params->OneRailSweepFormSections : Params->OneRailSweepFormSections + 1;
	InitCornersForm( nPointsForm );
	point2 = polRail.GetFirstItem( )->v.GetPoint( );
	if ( !GetNControlPointsFromCurve( nPointsForm, Params->OneRailSweepFormCrv, &polForm, CornersForm, 0, &point2 ) ) return false;

	// Trasladamos el rail a la forma
	vec = T3DVector( polRail.GetFirstItem( )->v.GetPoint( ), polForm.GetFirstItem( )->v.GetPoint( ) );
	matrixT1 = TNTraslationMatrix( vec );
	polRail.ApplyMatrix( &matrixT1 );

	// Generamos las secciones trasladando la forma por el rail
	if ( Params->OneRailSweepAdaptCurvature ) {
		vec = T3DVector( T3DSize( NormalsRail1[ 0 ].x, NormalsRail1[ 0 ].y, NormalsRail1[ 0 ].z ), polRail.GetFirstItem( )->v.GetPoint( ) );
		planeOri = T3DPlane( polRail.GetFirstItem( )->v.GetPoint( ), vec );
	}
	coarseVertexs->Add( &polForm );
	for ( i = 1; i < nPointsRail; i++ ) {
		vec = T3DVector( polRail.GetItem( i - 1 )->v.GetPoint( ), polRail.GetItem( i )->v.GetPoint( ) );
		matrixT1 = TNTraslationMatrix( vec );
		if ( Params->OneRailSweepAdaptCurvature ) {
			planeOri.ApplyMatrix( matrixT1 );
			vec = T3DVector( T3DSize( NormalsRail1[ i ].x, NormalsRail1[ i ].y, NormalsRail1[ i ].z ), polRail.GetItem( i )->v.GetPoint( ) );
			planeDest = T3DPlane( polRail.GetItem( i )->v.GetPoint( ), vec );
			matrixR = _GetMatrixTransformPlaneToPlane( planeOri, planeDest, true );
			planeOri = planeDest;

			vec = T3DVector( polForm.GetFirstItem( )->v.GetPoint( ), polRail.GetItem( i )->v.GetPoint( ) );
			matrixT2 = TNTraslationMatrix( vec );
			polForm.ApplyMatrix( &matrixT2 );
			polForm.ApplyMatrix( &matrixR );
			matrixT2 = matrixT2.Inverse( );
			polForm.ApplyMatrix( &matrixT2 );
		}

		polForm.ApplyMatrix( &matrixT1 );
		coarseVertexs->Add( &polForm );
	}

	return true;
}

//------------------------------------------------------------------------------

bool TReverseSubdivision::GetReverseSubdivisionSISLForTwoRailsSweep( TOGLPolygonList *coarseVertexs )
{
	int i, nPointsRail, nPointsForm;
	double size1, size2, incrSize;
	TNMatrix matrixR, matrixT;
	TOGLPolygon polRail1, polRail2, polForm;
	T3DPoint pt3d1, pt3d2, pt3d3, pt1Form, pt2Form;
	T3DPlane plane1, plane2, rail1PlaneOri, rail1PlaneDest, rail2PlaneOri, rail2PlaneDest;
	T3DVector vec, vecForm;
	TOGLFloat3 v1, v2;

	if ( !coarseVertexs ) return false;
	if ( !OGLTransf || !Params || !Params->TwoRailsSweepRail1Crv || !Params->TwoRailsSweepRail2Crv || !Params->TwoRailsSweepFormCrv ) return false;
	if ( !Params->IsValid( LPM_CREATIONTYPE_TWO_RAILS_SWEEP ) ) return false;

	// Obtenemos los puntos coarse de los railes y de la forma
	GetBestRefPoints( Params->TwoRailsSweepRail1Crv, Params->TwoRailsSweepFormCrv, pt3d1, pt1Form );
	nPointsRail = Closed_H ? Params->TwoRailsSweepRailSections : Params->TwoRailsSweepRailSections + 1;
	InitCornersRail1( nPointsRail );
	InitNormalsRail1( nPointsRail );
	if ( !GetNControlPointsFromCurve( nPointsRail, Params->TwoRailsSweepRail1Crv, &polRail1, CornersRail1, NormalsRail1, &pt1Form ) ) return false;

	nPointsForm = Closed_V ? Params->TwoRailsSweepFormSections : Params->TwoRailsSweepFormSections + 1;
	InitCornersForm( nPointsForm );
	if ( !GetNControlPointsFromCurve( nPointsForm, Params->TwoRailsSweepFormCrv, &polForm, CornersForm, 0, &pt1Form ) ) return false;

	if ( ToShape( Params->TwoRailsSweepFormCrv )->GetClose( OGLTransf ) != ENT_OPEN ) GetBestRefPoints( Params->TwoRailsSweepRail2Crv, Params->TwoRailsSweepFormCrv, pt3d1, pt2Form );
	else
		pt2Form = polForm.GetLastItem( )->v.GetPoint( );

	InitCornersRail2( nPointsRail );
	if ( !GetNControlPointsFromCurve( nPointsRail, Params->TwoRailsSweepRail2Crv, &polRail2, CornersRail2, 0, &pt2Form ) ) return false;

	// Si los railes son cerrados nos aseguramos van en el mismo sentido.
	if ( Closed_H ) {
		pt3d1 = polRail1.GravityCenter( );
		pt3d2 = polRail2.GravityCenter( );
		plane1 = T3DPlane( pt3d1, T3DVector( pt3d1, pt3d2 ) );
		if ( _IsClockWise( &polRail1, plane1 ) != _IsClockWise( &polRail2, plane1 ) ) {
			polRail2.Invert( );
			InvertCornersRail2( );
		}
	}

	// Trasladados las curvas de rail: primer punto coarse de la curva de rail 1 a pt1Form
	pt3d1 = polRail1.GetFirstItem( )->v.GetPoint( );
	vec = T3DVector( pt3d1, pt1Form );
	matrixT = TNTraslationMatrix( vec );
	polRail1.ApplyMatrix( &matrixT );
	polRail2.ApplyMatrix( &matrixT );

	// Recorremos los railes con la forma obteniendo las secciones necesarias.
	vec = T3DVector( T3DSize( NormalsRail1[ 0 ].x, NormalsRail1[ 0 ].y, NormalsRail1[ 0 ].z ), pt3d2 );
	rail1PlaneOri = T3DPlane( pt3d1, vec );

	pt3d1 = polRail1.GetFirstItem( )->v.GetPoint( );
	pt3d2 = polRail2.GetFirstItem( )->v.GetPoint( );
	vec = T3DVector( pt3d1, pt3d2 );
	rail2PlaneOri = T3DPlane( pt3d1, vec );

	coarseVertexs->Add( &polForm );

	size1 = pt3d1.DistanciaSqr( pt3d2 );
	vecForm = T3DVector( pt1Form, pt2Form );

	for ( i = 1; i < nPointsRail; i++ ) {
		// Aplicamos rotación por cambio de sección sobre rail1
		vec = T3DVector( T3DSize( NormalsRail1[ i ].x, NormalsRail1[ i ].y, NormalsRail1[ i ].z ), pt3d1 );
		rail1PlaneDest = T3DPlane( pt3d1, vec );
		matrixR = _GetMatrixTransformPlaneToPlane( rail1PlaneOri, rail1PlaneDest );
		rail1PlaneOri = rail1PlaneDest;
		polForm.ApplyMatrix( &matrixR );
		rail2PlaneOri.ApplyMatrix( matrixR );
		vecForm.ApplyMatrix( matrixR );

		// Aplicamos rotación por cambio de sección sobre rail2
		pt3d1 = polRail1.GetItem( i )->v.GetPoint( );
		pt3d2 = polRail2.GetItem( i )->v.GetPoint( );
		vec = T3DVector( pt3d1, pt3d2 );
		rail2PlaneDest = T3DPlane( pt3d1, vec );
		matrixR = _GetMatrixTransformPlaneToPlane( rail2PlaneOri, rail2PlaneDest );
		rail2PlaneOri = rail2PlaneDest;
		polForm.ApplyMatrix( &matrixR );
		vecForm.ApplyMatrix( matrixR );

		// Escalamos con rotación previa a plano XY
		size2 = pt3d1.DistanciaSqr( pt3d2 );
		incrSize = sqrt( size2 / size1 );
		if ( fabs( incrSize - 1.0 ) > RES_COMP ) {
			size1 = size2;

			plane1 = T3DPlane( vecForm.org, vecForm );
			plane2 = T3DPlane( plXY );
			matrixR = _GetMatrixTransformPlaneToPlane( plane1, plane2 );
			polForm.ApplyMatrix( &matrixR );
			polForm.Scale( T3DPoint( incrSize, incrSize, incrSize ) );
			matrixR = matrixR.Inverse( );
			polForm.ApplyMatrix( &matrixR );
		}

		coarseVertexs->Add( &polForm );
	}

	return true;
}

//------------------------------------------------------------------------------

void TReverseSubdivision::ClosedCornerDetection( int np, T3DPoint *Pts, double angledeg, TOGLPolygon *PolCorners )
{
	int i, next, prev;
	bool *corners;
	double *angles, cosa, cosangle;
	T3DPoint pt0, pt1, pt2;
	T3DVector v1, v2;
	TOGLPoint oglpt;

	if ( !PolCorners ) return;
	PolCorners->Clear( );
	if ( np < 3 ) return;

	angles = new double[ np ];
	corners = new bool[ np ];

	pt0 = T3DPoint( 0.0, 0.0, 0.0 );
	for ( i = 0; i < np; i++ ) {			// Creacion de angles entre puntos
		next = ( i != np - 1 ) ? i + 1 : 1; // 0;
		prev = ( i != 0 ) ? i - 1 : np - 2; // 1;
		pt1 = Pts[ prev ] - Pts[ i ];
		pt1.Normalize( );
		pt2 = Pts[ next ] - Pts[ i ];
		pt2.Normalize( );

		v1 = T3DVector( pt0, pt1 );
		v2 = T3DVector( pt0, pt2 );
		cosa = v2 ^ v1;
		angles[ i ] = ( 1.0 - cosa ) / 2.0; // Normalizamos 0 - 1
	}

	cosangle = cos( angledeg * M_PI_180 );
	for ( i = 0; i < np; i++ )
		corners[ i ] = ( angles[ i ] < cosangle );

	for ( i = 0; i < np; i++ )
		if ( corners[ i ] ) {
			oglpt.v.Set( Pts[ i ].x, Pts[ i ].y, 0.0 );
			PolCorners->AddItem( &oglpt );
		}

	if ( corners ) delete[] corners;
	if ( angles ) delete[] angles;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// TPBrepData
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

TPBrepData::TPBrepData( TCadEntity *refent )
{
	RefEnt = refent;
	PBrep = 0;
	PBrepFaceTriangulation = false;
	SelectedF = 0;
	SelectedV = 0;
	SelectedE = 0;
	Subdivision = 0;
	CompareMask = CMASK_V | CMASK_N | CMASK_T;
	RepairTol = RES_COMP;									 // NO CAMBIAR!!!!
	AuxEntityColor[ 0 ] = (TColor) ( RGB( 204, 204, 229 ) ); // azul/gris claro //colorFace
	AuxEntityColor[ 1 ] = (TColor) ( RGB( 107, 107, 107 ) ); // colorEdge //Anterioremente ( RGB( 255, 255, 255 ) );
	AuxEntityColor[ 2 ] = (TColor) ( RGB( 255, 255, 255 ) ); // colorVertex
	AuxEntityColor[ 3 ] = (TColor) ( RGB( 250, 196, 127 ) ); // amarillo claro //colorSelectFace
	AuxEntityColor[ 4 ] = (TColor) ( RGB( 108, 195, 127 ) ); // marron  //seam
	AnyClosedRingSelected = 0;
	DirtyFaceSel = DirtyEdgeSel = false;
}

//------------------------------------------------------------------------------

// Esta funcion solo se debe usar para un uso puntual de alguna funcion que no use RefEnt
TPBrepData::TPBrepData( IwPolyBrep *pBrep, bool copy )
{
	RefEnt = 0;
	PBrep = 0;
	PBrepFaceTriangulation = false;
	SelectedF = 0;
	SelectedV = 0;
	SelectedE = 0;
	Subdivision = 0;
	CompareMask = CMASK_V | CMASK_N | CMASK_T;
	RepairTol = RES_COMP; // NO CAMBIAR!!!!
	if ( pBrep && copy ) CopyPBrep( pBrep );
	else
		PBrep = pBrep;

	AuxEntityColor[ 0 ] = (TColor) ( RGB( 204, 204, 229 ) ); // azul/gris claro //colorFace
	AuxEntityColor[ 1 ] = (TColor) ( RGB( 107, 107, 107 ) ); // colorEdge //Anterioremente ( RGB( 255, 255, 255 ) );
	AuxEntityColor[ 2 ] = (TColor) ( RGB( 255, 255, 255 ) ); // colorVertex
	AuxEntityColor[ 3 ] = (TColor) ( RGB( 250, 196, 127 ) ); // amarillo claro //colorSelectFace
	AuxEntityColor[ 4 ] = (TColor) ( RGB( 108, 195, 127 ) ); // marron  //seam
	AnyClosedRingSelected = 0;
	DirtyFaceSel = DirtyEdgeSel = false;
}

//------------------------------------------------------------------------------

TPBrepData::~TPBrepData( )
{
	DestroyPBrepVars( );
}

//------------------------------------------------------------------------------

void TPBrepData::DestroyPBrepVars( )
{
	if ( PBrep ) {
		_GetSMLib( )->DestroyIwPolyBrep( PBrep );
		PBrep = 0;

		PBrepFaces.RemoveAll( );
		PBrepVertexs.RemoveAll( );
		PBrepEdges.RemoveAll( );

		SeamEdges.RemoveAll( );
	}
	ClearSubdivision( );
	if ( SelectedF ) {
		delete[] SelectedF;
		SelectedF = 0;
	}
	if ( SelectedV ) {
		delete[] SelectedV;
		SelectedV = 0;
	}
	if ( SelectedE ) {
		delete[] SelectedE;
		SelectedE = 0;
	}

	PBrepPolListRelF.clear( );

	AnyClosedRingSelected = 0;
	DirtyFaceSel = DirtyEdgeSel = false;

	//	RefEnt = 0; si no, no puede calcular nada
}

//------------------------------------------------------------------------------
// Función Genérica para recalcular los arrays asociados a las caras, aristas y vertices de la PBrep. NO SE DEBEN de recalcular en otro sitio
// que no sea esta función ya que por ejemplo las aristas no están todas, solo las de un sentido.
// Devuelve true en caso de éxito o false en caso de error
bool TPBrepData::CreatePBrepArrays( )
{
	int i, nvertexs, nfaces, nEdges;
	ULONG ulCount;
	IwTA<IwPolyEdge *> edgesAux;
	IwPolyEdge *edge, *edgeSym;

	if ( !PBrep ) return false;

	PBrep->GetPolyFaces( PBrepFaces );
	PBrep->GetPolyVertices( PBrepVertexs );
	PBrep->GetPolyEdges( edgesAux );

	nfaces = (int) PBrepFaces.GetSize( );
	nEdges = (int) edgesAux.GetSize( );
	nvertexs = (int) PBrepVertexs.GetSize( );
	if ( !nfaces || !nvertexs || !nEdges ) {
		DestroyPBrepVars( );
		return false;
	}

	// Caras
	if ( SelectedF ) delete[] SelectedF;
	SelectedF = new intdouble[ nfaces ];
	for ( i = 0; i < nfaces; i++ ) {
		SelectedF[ i ].i = 0;
		SelectedF[ i ].d = 0;
		PBrepFaces[ i ]->SetIndexExt( i );
	}

	// Aristas
	// La pbrep tiene los edges repetidos, los metemos solo una vez
	// Ponemos a ULONG_MAX los índices de los simétricos.
	// Si se quiere acceder a ellos, se usa la función GetSymmetricPolyEdge desde cualquier arista de PBrepEdges
	// Inicializamos el valor UserIndex1 que usaremos para referenciar entre PBrepEdges y la lista de aristas de la pbrep
	for ( i = 0; i < nEdges; i++ )
		edgesAux[ i ]->SetUserIndex1( 0 );
	PBrepEdges.RemoveAll( );
	ulCount = 0;
	PBrepEdges.SetDataSize( nEdges / 2 );
	for ( i = 0; i < nEdges; i++ ) {
		edge = edgesAux[ i ];
		edgeSym = edge->GetSymmetricPolyEdge( );

		if ( edge->GetUserIndex1( ) > 0 ) continue;

		edge->SetUserIndex1( ulCount++ );
		PBrepEdges.Add( edge );

		if ( edgeSym ) edgeSym->SetUserIndex1( ULONG_MAX );
	}

	if ( SelectedE ) delete[] SelectedE;
	nEdges = (int) PBrepEdges.GetSize( );
	SelectedE = new int[ nEdges ];
	for ( i = 0; i < nEdges; i++ )
		SelectedE[ i ] = 0;

	// Vértices
	if ( SelectedV ) delete[] SelectedV;
	SelectedV = new intdouble[ nvertexs ];
	for ( i = 0; i < nvertexs; i++ ) {
		SelectedV[ i ].i = 0;
		SelectedV[ i ].d = 0;
		PBrepVertexs[ i ]->SetIndexExt( i );
	}

	// Costuras
	UpdateAllSeamEdgesFromPBrep( );

	AnyClosedRingSelected = 0;
	DirtyFaceSel = DirtyEdgeSel = false;

	return true;
}

//------------------------------------------------------------------------------

void TPBrepData::ClearSubdivision( )
{
	if ( Subdivision ) {
		delete Subdivision;
		Subdivision = 0;
	}
}

//------------------------------------------------------------------------------

void TPBrepData::ClearTempData( )
{
	MoveVertUser.Clear( );
}

//------------------------------------------------------------------------------

bool TPBrepData::CheckConsistency( IwTA<IwPolyVertex *> *iwVertexToCheck, IwTA<IwPolyEdge *> *iwEdgesToCheck, IwTA<IwPolyVertex *> *vertexsOut, IwTA<IwPolyEdge *> *edgesOut, IwTA<IwPolyFace *> *facesOut )
{
	bool ret;
	int i, nEdges;
	IwPolyEdge *edge1, *edge2;
	IwPolyVertex *vertex1;
	IwPolyFace *face, *face2;

	ret = true;
	if ( iwVertexToCheck ) {
		// Buscamos vertices huerfanos.
		for ( i = 0; i < (int) ( *iwVertexToCheck ).GetSize( ); i++ ) {
			if ( i >= (int) ( *iwVertexToCheck ).GetSize( ) ) break;
			vertex1 = ( *iwVertexToCheck )[ i ];
			if ( !vertex1 || vertex1->GetFirstPolyEdge( ) == NULL ) {
				ret = false;
				if ( vertexsOut ) {
					vertexsOut->Add( vertex1 );
					( *iwVertexToCheck ).RemoveAt( i );
					i--;
				}
			}
		}
	}

	// Buscamos aristas huerfanas (o caras sin aristas)
	if ( iwEdgesToCheck ) {
		nEdges = (int) ( *iwEdgesToCheck ).GetSize( );
		for ( i = 0; i < nEdges; i++ ) {
			if ( i >= (int) ( *iwEdgesToCheck ).GetSize( ) ) break;
			edge1 = ( *iwEdgesToCheck )[ i ];
			if ( !edge1 || ( edge1 && !edge1->GetStartVertex( ) ) ) {
				ret = false;
				if ( edgesOut ) {
					edgesOut->Add( edge1 );
					( *iwEdgesToCheck ).RemoveAt( i );
					i--;
				}
				continue;
			}
			edge2 = edge1->GetSymmetricPolyEdge( );
			face2 = 0;
			if ( edge2 ) face2 = edge2->GetPolyFace( );
			face = edge1->GetPolyFace( );
			if ( !face || ( edge2 && face == face2 ) ) {
				ret = false;
				if ( facesOut && edge2 && face == face2 ) {
					facesOut->Add( face );
					( *iwEdgesToCheck ).RemoveAt( i );
					i--;
				} else if ( edgesOut ) {
					edgesOut->Add( edge1 );
					( *iwEdgesToCheck ).RemoveAt( i );
					i--;
				}
				continue;
			}
		}
	}

	return ret;
}

//------------------------------------------------------------------------------

bool TPBrepData::CanSubdivide( bool force, IwTA<IwPolyVertex *> *vertexsOut, IwTA<IwPolyEdge *> *edgesOut, IwTA<IwPolyFace *> *facesOut )
{
	int i, j, nEdges;
	IwPolyEdge *edge1;
	IwTA<IwPolyEdge *> edges;
	IwTA<IwPolyVertex *> vertexs;
	IwPolyVertex **vertexes;
	bool canSubdivide;

	if ( !RefEnt || !PBrep ) return false;
	if ( !force && !IsTopologyDirty( ) && Subdivision && !IsDataSubdivisionDirty( ) ) return true;

	PBrep->GetPolyVertices( vertexs );
	PBrep->GetPolyEdges( edges );

	if ( !CheckConsistency( &vertexs, &edges, vertexsOut, edgesOut, facesOut ) ) return false;

	// Aristas degeneradas
	canSubdivide = true;
	nEdges = (int) edges.GetSize( );
	vertexes = new IwPolyVertex *[ nEdges * 2 ];
	for ( i = 0; i < nEdges; i++ ) {
		edge1 = edges[ i ];
		vertexes[ i * 2 ] = edge1->GetStartVertex( );
		vertexes[ i * 2 + 1 ] = edge1->GetEndVertex( );
	}
	for ( i = 0; i < nEdges * 2; i += 2 ) {
		for ( j = i + 2; j < nEdges * 2; j += 2 ) {
			if ( vertexes[ i ] == vertexes[ j ] && vertexes[ i + 1 ] == vertexes[ j + 1 ] ) {
				if ( edgesOut ) {
					edgesOut->Add( edges[ i / 2 ] );
					edgesOut->Add( edges[ j / 2 ] );
				}
				canSubdivide = false;
				if ( !edgesOut ) break;
			}
		}
	}
	delete[] vertexes;

	return canSubdivide;
}

//------------------------------------------------------------------------------

bool TPBrepData::ApplySubdivision( TOGLTransf *OGLTransf, bool keepcreases )
{
	int i, j, k, l, index, cont, nItems, nPoints, nPointsSubd, nVertexs; // nItemsSubd,
	float *creasevalues;
	IwPolyVertex *vertex1, *vertex2, **verticesOriginalPos;
	IwPolyEdge *edge;
	IwTA<IwPolyEdge *> creaseedges;
	TOGLPoint *oglPoint;
	TOGLPolygon *oglPol, *oglPolSubd, polvertexs, poledges, polfaces;
	TOGLPolygonList subdOGLList, *OGLList;
	TInteger_ListList auxinfolist;
	TInteger_List seams, creases;

	if ( !RefEnt || !ToMesh( RefEnt ) || !ToMesh( RefEnt )->HasSubdivisionDepMesh( ) ) return false;
	OGLList = RefEnt->GetOGLGeom3D( OGLTransf );
	if ( !OGLList ) return false;

	// Obtenemos ogllist de la subdividida
	if ( GetSubdividedOGLList( OGLTransf, &subdOGLList, &polvertexs, &poledges, &polfaces, ToDepMesh( RefEnt->GetDepMeshes( )->GetShape( 0 ) )->GetSubdivisionData( ), &auxinfolist ) == 0 ) return false;

	// Nos guardamos una lista de las costuras para recupararlas luego y los borramos de la pbrep
	nItems = CountPBrepSeams( );
	for ( i = 0; i < nItems; i++ ) {
		edge = GetSeamByIndex( i );
		j = edge->GetUserIndex1( );
		seams.AddItem( &j );
	}
	DeleteSeamEdges( OGLTransf, &seams );

	// Nos guardamos una lista de las pliegues y sus porcentajes para recupararlos luego y los borramos de la pbrep
	creasevalues = 0;
	if ( keepcreases ) {
		GetCreaseEdges( OGLTransf, &creaseedges );
		nItems = (int) creaseedges.GetSize( );
		if ( nItems > 0 ) {
			creasevalues = new float[ nItems ];
			for ( i = 0; i < nItems; i++ ) {
				j = creaseedges[ i ]->GetUserIndex1( );
				creases.AddItem( &j );
				creasevalues[ i ] = creaseedges[ i ]->GetUserFloat1( );
			}
		}
	}

	// Asignamos subdOGLlist y auxinfolist y volvemos a crear la pbrep
	OGLList->Set( &subdOGLList );
	nItems = OGLList->Count( );
	for ( i = 0; i < nItems; i++ ) {
		oglPol = OGLList->GetItem( i );
		nPoints = oglPol->Count( );
		for ( j = 0; j < nPoints; j++ )
			oglPol->GetItem( j )->uv.v[ 1 ] = 0;
	}
	ToMesh( RefEnt )->GetAuxInfoList( true )->Set( &auxinfolist );
	if ( ToMesh( RefEnt )->GetCreaseList( ) ) ToMesh( RefEnt )->GetCreaseList( )->Clear( );
	if ( ToMesh( RefEnt )->GetSeamList( ) ) ToMesh( RefEnt )->GetSeamList( )->Clear( );
	RefEnt->GetOGLRenderData( )->SetColors( RefEnt->GetDepMeshes( )->GetShape( 0 )->GetOGLRenderData( )->Colors );

	CreatePBrep( OGLTransf, false, &verticesOriginalPos ); // Se obtiene una lista de los vértices ordenados según los índices iniciales en subdOGLList, para poder recuperar luego costuras y pliegues

	// Recuperamos costuras y plieges
	if ( seams.Count( ) > 0 || creases.Count( ) > 0 ) {
		nVertexs = (int) PBrepVertexs.GetSize( );
		nItems = subdOGLList.Count( );
		for ( i = 0; i < nItems; i++ ) {
			oglPol = subdOGLList.GetItem( i );
			nPoints = oglPol->Count( );
			cont = 0;
			for ( j = 0; j < nPoints; j++ ) {
				oglPoint = oglPol->GetItem( j );
				if ( oglPoint->uv.v[ 1 ] != LONG_MAX ) {
					vertex1 = vertex2 = 0;
					k = (int) oglPoint->uv.v[ 1 ];
					index = seams.GetItemIndex( &k );
					if ( index != -1 ) {
						vertex1 = verticesOriginalPos[ (int) ( oglPoint->uv.v[ 0 ] ) ];
						vertex2 = verticesOriginalPos[ (int) ( oglPol->GetItem( cont < 3 ? j + 1 : j - 3 )->uv.v[ 0 ] ) ];
						if ( !vertex1 || !vertex2 ) continue;
						edge = GetEdgeFromVertices( vertex1, vertex2, true );
						if ( edge ) AddSeamEdge( edge );
					}
					k = (int) oglPoint->uv.v[ 1 ];
					index = creases.GetItemIndex( &k );
					if ( index != -1 ) {
						vertex1 = verticesOriginalPos[ (int) ( oglPoint->uv.v[ 0 ] ) ];
						vertex2 = verticesOriginalPos[ (int) ( oglPol->GetItem( cont < 3 ? j + 1 : j - 3 )->uv.v[ 0 ] ) ];
						if ( !vertex1 || !vertex2 ) continue;
						edge = GetEdgeFromVertices( vertex1, vertex2, true );
						if ( edge ) AddCreaseEdges( OGLTransf, edge, creasevalues[ index ], false );
					}
				}
				cont = ( cont + 1 ) % 4;
			}
		}
	}

	// Liberamos verticesOriginalPos
	nVertexs = (int) PBrepVertexs.GetSize( );
	if ( verticesOriginalPos ) {
		for ( i = 0; i < nVertexs; i++ )
			verticesOriginalPos[ i ] = 0;
		delete[] verticesOriginalPos;
	}

	// Restauramos la OGList respecto a la pBrep creada
	RefEnt->UpdateOGLListFromPBrep( OGLTransf, false, true, false, true );

	// No hace falta recalcular las normales. Aplicamos las que venían de la subdivisión.
	k = l = cont = 0;
	nItems = OGLList->Count( );
	oglPolSubd = subdOGLList.GetItem( 0 );
	nPointsSubd = oglPolSubd->Count( );
	for ( i = 0; i < nItems; i++ ) {
		oglPol = OGLList->GetItem( i );
		nPoints = oglPol->Count( );
		for ( j = 0; j < nPoints; j++ ) {
			oglPol->GetItem( j )->n.Set( &( oglPolSubd->GetItem( l )->n ) );
			if ( l != nPointsSubd ) l++;
			else {
				k++;
				oglPolSubd = subdOGLList.GetItem( k );
				nPointsSubd = oglPolSubd->Count( );
				l = 0;
			}
		}
	}

	if ( creasevalues ) delete[] creasevalues;

	return true;
}

//------------------------------------------------------------------------------

bool TPBrepData::CreatePBrep( TOGLTransf *OGLTransf, bool forcecheckpbrep, IwPolyVertex ***verticesOriginalPos )
{
	bool activeRel, checkPBrep, ispolygonalmesh, issubdivisionDepMesh, check;
	int i, j, numPols, numCoords, times, auxType, oldCompareMask;
	TOGLPoint oglpt;
	TOGLPolygon pol;
	TOGLPolygonList *OGLList, *AuxOGLList, *OGLDeformed, list;

	if ( !RefEnt || !RefEnt->IsFillEntity( false ) ) return false;

	//	if ( !RefEnt->GetPBrepDirty( ) && PBrep ) return true; //se comprueba desde la entidad

	if ( PBrep ) DestroyPBrepVars( );
	PBrepPolListRelF.clear( );

	OGLList = RefEnt->GetOGLGeom3D( OGLTransf );
	if ( !OGLList ) return false;

	activeRel = true;
	ispolygonalmesh = ToMesh( RefEnt ) && ToMesh( RefEnt )->IsPolygonalMesh( );
	issubdivisionDepMesh = ToDepMesh( RefEnt ) && ToDepMesh( RefEnt )->IsSubdivisionEntity( );

	if ( ispolygonalmesh && ( !ToMesh( RefEnt )->GetAuxInfoList( ) || !ToMesh( RefEnt )->GetAuxInfoList( )->Count( ) ) ) ToMesh( RefEnt )->DeleteDegeneratedTriangles( OGLTransf );

	auxType = -1;
	AuxOGLList = 0;
	if ( RefEnt->GetOwnOGLRenderData( ) && RefEnt->GetOGLRenderData( )->ActiveTextureUV && RefEnt->GetOGLRenderData( )->CountTextureUVCoords( ) ) {
		AuxOGLList = RefEnt->GetOGLRenderData( )->TextureUVCoords;
		auxType = 0;
	}
	if ( !AuxOGLList && ToDepMesh( RefEnt ) && ToDepMesh( RefEnt )->IsTrimOffsetBorderDepMesh( ) && ( RefEnt->GetOGLList( OGLTransf )->Count( ) == RefEnt->GetOGLGeom3D( OGLTransf, true, true )->Count( ) ) ) {
		AuxOGLList = RefEnt->GetOGLGeom3D( OGLTransf, true, true );
		auxType = 1;
	}
	if ( AuxOGLList ) {
		if ( auxType == 0 ) {
			numPols = OGLList->Count( );
			numCoords = AuxOGLList->Count( );
			if ( numCoords > 0 && numPols != numCoords && ( numPols % numCoords == 0 ) ) { // no deberia ya ocurrir
				times = numPols / numCoords - 1;
				for ( i = 0; i < times; i++ ) {
					RefEnt->GetOGLRenderData( )->CheckTextureUVCoords( );
					AuxOGLList->Append( RefEnt->GetOGLRenderData( )->TextureUVCoords );
				}
			}
		}
		OGLList->ConvertToTriangles( 0, MULTI_POLYGON, CompareMask, AuxOGLList );
	} else {
		OGLDeformed = RefEnt->GetOGLDeformer3DList( OGLTransf, false );
		if ( !issubdivisionDepMesh ) { // Nuevo 07/2021. Las OGLList de las entidades dependientes de subdivision tienen una relacion muy estrecha con las listas de caras, aristas y vertices que se calculan conjuntamente. Por tanto, si se modifica esta OGLList entonces ya no mantienen esa relacion
			check = ispolygonalmesh && OGLList->AreTriangles( );
			if ( !check ) // nuevo caso detectado (12/2022): location basadas en mallas importadas
				if ( ToDepMesh( RefEnt ) && ToDepMesh( RefEnt )->IsLocation3DDepMesh( ) && ToDepMesh( RefEnt )->GetLocation3DEntitiesData( )->GetEntities( ) )
					if ( ToDepMesh( RefEnt )->GetLocation3DEntitiesData( )->GetEntities( )->GetShape( 0 ) && ToDepMesh( RefEnt )->GetLocation3DEntitiesData( )->GetEntities( )->GetShape( 0 )->AmIStrictMesh( ) ) check = OGLList->AreTriangles( );
			if ( check ) OGLList->ConvertToTriangles( 0, MULTI_POLYGON, CompareMask, OGLDeformed, 0, 0, true );
			else if ( AreTrianglesForced( ) )
				OGLList->ConvertToTriangles( 0, MULTI_POLYGON, CompareMask, OGLDeformed );
			if ( ToMesh( RefEnt ) && ToMesh( RefEnt )->GetAuxInfoList( ) && ToMesh( RefEnt )->GetAuxInfoList( )->Count( ) == OGLList->Count( ) ) {
				for ( i = 0; i < ToMesh( RefEnt )->GetAuxInfoList( )->Count( ); i++ ) {
					pol.Clear( );
					for ( j = 0; j < ToMesh( RefEnt )->GetAuxInfoList( )->GetItem( i )->Count( ); j += 3 ) {
						oglpt.t.v[ 0 ] = *( ToMesh( RefEnt )->GetAuxInfoList( )->GetItem( i )->GetItem( j ) );
						pol.AddItem( &oglpt );
					}
					list.Add( &pol );
				}
				AuxOGLList = &list;
				auxType = 2;
			}
		}
	}

	checkPBrep = ( RepairTol > 0.0 );
	if ( checkPBrep ) {
		if ( ToDepMesh( RefEnt ) && ToDepMesh( RefEnt )->IsTrimOffsetSideDepMesh( ) ) // Nuevo 11/2022. Mismo problema que en en los otros dos casos. En piezas cerradas por detrás, los vertices en 0 y en 1000 (u) son iguales pero las coordenadas de texture son distintas. Si se llama al sew, unifica vértices y una coordenada de textura se queda mal (igual en el 0 que en 1000)
			checkPBrep = false;
		else if ( ToDepMesh( RefEnt ) && ToDepMesh( RefEnt )->IsLocation3DDepMesh( ) ) // Nuevo 11/2020. Se hace el mismo tratamiento en las coordoneras que tienen el mismo problema
			checkPBrep = false;
		else if ( RefEnt && RefEnt->AmIStrictMesh( ) && RefEnt->GetOGLTextureData( )->TextureMode == TEXTURE_FIX ) // Nuevo 03/2022. Mallas importadas del digitalizador con vertices iguales con coordenadas de textura diferente las unificaba. Si no da problemas, dejarlo asi
			checkPBrep = false;
	}

	oldCompareMask = CompareMask;
	if ( ispolygonalmesh || issubdivisionDepMesh ) { // Nuevo 07/2021 y 07/2022 (ispolygonalmesh: para que el sew no una los vertices iguales con diferentes indices). Las OGLList de las entidades dependientes de subdivision tienen una relacion muy estrecha con las listas de caras, aristas y vertices que se calculan conjuntamente. Por tanto, si se modifica esta OGLList entonces ya no mantienen esa relacion
		checkPBrep = false;
		activeRel = false;
		// 03/05/2023 El if se ha anyadido para diferenciar entre las mallas creadas a partir de una pbrep y el resto de mallas, en las que no se sabe si dos vertices con la misma posicion son el mismo vertice o no
		if ( ToMesh( RefEnt ) && ToMesh( RefEnt )->GetAuxInfoList( ) && ToMesh( RefEnt )->GetAuxInfoList( )->Count( ) == OGLList->Count( ) ) CompareMask = CMASK_V; // 28/09 Cuando las coordenadas de textura o las normales son diferentes, diferencia los vertices, y esto no es así.
	}

	if ( forcecheckpbrep && !( RefEnt && RefEnt->AmIStrictMesh( ) && ( RefEnt->GetOGLTextureData( )->TextureMode == TEXTURE_FIX ) ) ) { // 02/2023 para no perder la coordenadas de textura en ese caso
		checkPBrep = true;
		activeRel = true;
	}

	PBrep = _GetSMLib( )->ConvertToIwPolyBrep( OGLList, &PBrepPolListRelF, activeRel, auxType, AuxOGLList, PBrepFaceTriangulation, CompareMask, checkPBrep, RepairTol, RES_COMP, AreTrianglesForced( ), ispolygonalmesh || issubdivisionDepMesh, verticesOriginalPos );
	if ( !PBrep ) return false;

	if ( forcecheckpbrep && OGLList->GetItem( 0 ) && OGLList->GetItem( 0 )->GetUseNormals( ) ) {
		OGLList->CalculateNormal( );
		if ( RefEnt && RefEnt->GetOGLRenderData( )->Smooth ) OGLList->UnifyNormals( RefEnt->GetOGLRenderData( )->Smooth_MaxDegAngle );
	}

	CompareMask = oldCompareMask;

	CreatePBrepArrays( );

	RefEnt->SetPBrepDirty( false );
	RefEnt->SetDeformer3DDirty( true ); // cambia OGLList

	UpdatePBrepSeamFromOGLList( OGLTransf );
	UpdatePBrepCreasesFromOGLList( OGLTransf, false );
	UpdateOGLListAuxInfoList( OGLTransf );

	return true;
}

//------------------------------------------------------------------------------
// Funcion utilizada solo en la funcion SetPBrepData
bool TPBrepData::Set( TOGLTransf *OGLTransf, TPBrepData *pBrepData )
{
	int i, size, nVertexs, nFaces, nEdges;
	int3 aux;

	if ( !OGLTransf || !pBrepData ) return false;

	if ( !CopyPBrep( pBrepData->PBrep ) ) return false;

	// La RefEnt se tiene que asignar desde el constructor previamente
	// La subdivision no se copia. El set se usa para el undo

	PBrepFaceTriangulation = pBrepData->PBrepFaceTriangulation;

	size = (int) pBrepData->PBrepPolListRelF.size( );
	for ( i = 0; i < size; i++ ) {
		aux = pBrepData->PBrepPolListRelF[ i ];
		PBrepPolListRelF.push_back( aux );
	}

	CompareMask = pBrepData->CompareMask;
	RepairTol = pBrepData->RepairTol;

	nFaces = (int) PBrepFaces.GetSize( );
	for ( i = 0; i < nFaces; i++ )
		SelectedF[ i ].i = pBrepData->GetFaceSelectedType( i );

	nEdges = (int) PBrepEdges.GetSize( );
	for ( i = 0; i < nEdges; i++ )
		SelectedE[ i ] = pBrepData->GetEdgeSelectedType( i );

	nVertexs = (int) PBrepVertexs.GetSize( );
	for ( i = 0; i < nVertexs; i++ ) {
		SelectedV[ i ].i = pBrepData->GetVertexSelectedType( i );
		SelectedV[ i ].d = 1; // revisar
	}

	AuxEntityColor[ 0 ] = pBrepData->AuxEntityColor[ 0 ];
	AuxEntityColor[ 1 ] = pBrepData->AuxEntityColor[ 1 ];
	AuxEntityColor[ 2 ] = pBrepData->AuxEntityColor[ 2 ];
	AuxEntityColor[ 3 ] = pBrepData->AuxEntityColor[ 3 ];
	AuxEntityColor[ 4 ] = pBrepData->AuxEntityColor[ 4 ];

	AnyClosedRingSelected = pBrepData->AnyClosedRingSelected;
	DirtyFaceSel = pBrepData->DirtyFaceSel;
	DirtyEdgeSel = pBrepData->DirtyEdgeSel;

	UpdatePBrepSeamFromOGLList( OGLTransf );
	UpdatePBrepCreasesFromOGLList( OGLTransf );

	return true;
}

//------------------------------------------------------------------------------

// updateuvandtexcoords: lo lógico seria hacerlo, pero como hasta ahora no se hacia, se deja a false por defecto
bool TPBrepData::CopyPBrep( IwPolyBrep *pbrep, bool updateuvandtexcoords )
{
	int i;
	IwTA<IwPolyVertex *> iwAuxVertexs, iwAuxVertexs2;

	if ( !pbrep ) return false;

	if ( PBrep ) DestroyPBrepVars( );

	PBrepPolListRelF.clear( );
	PBrep = new IwPolyBrep( _GetSMLib( )->GetContext( ), *pbrep );
	if ( !PBrep ) return false;

	CreatePBrepArrays( );

	if ( updateuvandtexcoords ) {
		pbrep->GetPolyVertices( iwAuxVertexs );
		PBrep->GetPolyVertices( iwAuxVertexs2 );
		if ( iwAuxVertexs.GetSize( ) == iwAuxVertexs2.GetSize( ) )
			for ( i = 0; i < (int) iwAuxVertexs.GetSize( ); i++ ) {
				iwAuxVertexs2[ i ]->SetUV( iwAuxVertexs[ i ]->GetUV( ) );
				iwAuxVertexs2[ i ]->SetTexture( iwAuxVertexs[ i ]->GetTexture( ) );
			}
	}

	if ( RefEnt ) {
		RefEnt->SetPBrepDirty( false );
		RefEnt->SetDeformer3DDirty( true );
	}

	return true;
}

//------------------------------------------------------------------------------

// copyAll: copiar todas las caras o solo las seleccionadas
// markSeams: marca las nuevas aritas que estaban como costuras en UserLong2 para poder recuperarlas luego. Funcionará bien cuando copyAll sea true o cuando se copien todas las caras a ambos ladods de las costuras.
// updateTopology: actualizar topología. Si no se hace, es respondabilidad del que realiza la llamada
bool TPBrepData::AddFacesFromPBrep( TOGLTransf *OGLTransf, TPBrepData *pBrepData, bool cutOpenSeams, bool copyAll, bool updateTopology )
{
	ULONG pos;
	int i, j, k, l, m, nFaces, nvertexs, nVertexsFace, nEdgesFace, numgroups, indexv;
	IwPoint3d iwPoint3d, iwpt3d;
	IwPoint2d iwpt2d;
	IwPolyVertex *iwVertex, *vertexcur;
	IwPolyEdge *iwEdgeFace, *iwEdgeNewFace;
	IwPolyFace *newFace, *face;
	IwTA<IwPolyVertex *> iwVertexsFace, iwVertexNewFace, iwVertexs;
	IwTA<IwTA<IwPolyVertex *> > iwSeamVertexs;
	IwTA<IwPolyEdge *> iwEdgesFace, iwEdgesNewFace, iwSeams, insideSeamsAux;
	IwTA<IwTA<IwPolyEdge *> > insideSeams;
	IwTA<IwPolyFace *> iwFaces1, iwFaces2;
	IwTA<IwTA<IwPolyFace *> > iwSeamFaces1, iwSeamFaces2, *facesgroup;
	IwTA<IwPolyRegion *> regions;
	IwTA<IwPolyShell *> shells;
	IwStatus status;
	IwPolyBrep *pBrep;
	IwPolyRegion *pRegion;
	IwPolyShell *pShell;
	vector<vector<int> > groups;
	vector<int> listFaces;
	struct reference {
		IwPolyVertex *vertex;
		IwTA<IwTA<IwPolyFace *> > *faces;
		IwTA<IwPolyVertex *> *newvertexs;
	} * *reflist;

	int nVertexsToCopy;
	IwTA<IwPolyVertex *> iwVertexsToCopy, iwVertexsNew, iwVertexsNew2;
	IwTA<IwPolyFace *> iwFacesToCopy;
	IwTA<IwTA<IwPolyFace *> > iwFacesToCopySepared;

	if ( !OGLTransf || !pBrepData ) return false;

	if ( copyAll || pBrepData->IsAnyFaceSelected( OGLTransf ) ) {
		// Si la PBrep es null es porque partimos de una lowpoly vacía.
		if ( PBrep ) {
			PBrep->GetPolyRegions( regions );
			PBrep->GetPolyShells( shells );
			if ( regions.GetSize( ) == 0 || shells.GetSize( ) == 0 ) return false;
			pBrep = 0;
		} else {
			pBrep = new IwPolyBrep( _GetSMLib( )->GetContext( ), RES_COMP );
			pRegion = new IwPolyRegion( _GetSMLib( )->GetContext( ), pBrep );
			pShell = new IwPolyShell( _GetSMLib( )->GetContext( ), *pBrep, pRegion );
		}

		// Creamos una lista con todos los vértices a copiar y otra de igual tamaño con vertices vacios, que iremos creando segun se necesiten
		// A su vez, añadimos a otra lista las caras a copiar
		nFaces = pBrepData->CountPBrepFaces( OGLTransf );
		for ( i = 0; i < nFaces; i++ ) {
			if ( copyAll || pBrepData->IsFaceSelected( OGLTransf, i ) ) {
				face = pBrepData->GetPBrepFace( OGLTransf, i );
				iwFacesToCopy.AddUnique( face );
				face->GetPolyVertices( iwVertexsFace );
				nVertexsFace = (int) iwVertexsFace.GetSize( );
				for ( j = 0; j < nVertexsFace; j++ )
					iwVertexsToCopy.AddUnique( iwVertexsFace[ j ] );
			}
		}
		nVertexsToCopy = (int) iwVertexsToCopy.GetSize( );
		pBrepData->GetDisjointGroupFaces( OGLTransf, &groups, false, true, true );
		numgroups = groups.size( );
		for ( i = 0; i < numgroups; i++ ) {
			listFaces = groups.at( i );
			insideSeamsAux.RemoveAll( );
			pBrepData->IsAnySeamInsideOfGroupOfFaces( &listFaces, &insideSeamsAux );
			insideSeams.Add( insideSeamsAux );
		}

		nvertexs = pBrepData->CountPBrepVertexs( OGLTransf );
		reflist = new reference *[ nvertexs ];
		for ( k = 0; k < nvertexs; k++ )
			reflist[ k ] = 0;

		for ( k = 0; k < numgroups; k++ ) {
			iwVertex = 0;
			iwVertexsNew.RemoveAll( );
			for ( i = 0; i < nVertexsToCopy; i++ )
				iwVertexsNew.Add( iwVertex );

			for ( i = 0; i < (int) groups[ k ].size( ); i++ ) {
				face = pBrepData->GetPBrepFace( OGLTransf, groups[ k ][ i ] );
				if ( !face ) continue;
				if ( !iwFacesToCopy.FindElement( face, pos ) ) continue;
				face->GetPolyVertices( iwVertexsFace );
				nVertexsFace = (int) iwVertexsFace.GetSize( );
				iwVertexNewFace.RemoveAll( );
				for ( j = 0; j < nVertexsFace; j++ ) {
					iwVertex = 0;
					vertexcur = iwVertexsFace[ j ];
					indexv = vertexcur->GetIndexExt( );
					if ( cutOpenSeams && insideSeams[ k ].GetSize( ) ) {
						for ( l = 0; l < (int) insideSeams[ k ].GetSize( ); l++ ) {
							if ( insideSeams[ k ][ l ]->GetStartVertex( ) != vertexcur && insideSeams[ k ][ l ]->GetEndVertex( ) != vertexcur ) continue;
							// Tratar costuras
							if ( pBrepData->IsVertexSeam( vertexcur ) && !pBrepData->IsVertexSeamExtrem( vertexcur ) ) {
								if ( !reflist[ indexv ] ) {
									reflist[ indexv ] = new reference;
									facesgroup = new IwTA<IwTA<IwPolyFace *> >;
									pBrepData->GetFacesGroupedByVertexSeam( vertexcur, facesgroup );
									reflist[ indexv ]->vertex = vertexcur;
									reflist[ indexv ]->faces = facesgroup;
									reflist[ indexv ]->newvertexs = new IwTA<IwPolyVertex *>;
									for ( m = 0; m < (int) facesgroup->GetSize( ); m++ )
										reflist[ indexv ]->newvertexs->Add( 0 );
								}
								for ( m = 0; m < (int) reflist[ indexv ]->faces->GetSize( ); m++ )
									if ( reflist[ indexv ]->faces->GetAt( m ).FindElement( face, pos ) ) break;
								if ( m == (int) reflist[ indexv ]->faces->GetSize( ) ) continue; // No debería ocurrir esto

								if ( reflist[ indexv ]->newvertexs->GetAt( m ) ) iwVertex = reflist[ indexv ]->newvertexs->GetAt( m );
								else {
									// O ademas es una costura que no pertenece a su propia lista de costuras internas
									iwPoint3d.Set( vertexcur->GetPoint( ).x, vertexcur->GetPoint( ).y, vertexcur->GetPoint( ).z );
									iwpt3d = vertexcur->GetTexture( );
									iwpt2d = vertexcur->GetUV( );
									iwVertex = new IwPolyVertex( _GetSMLib( )->GetContext( ), PBrep ? *PBrep : *pBrep, iwPoint3d, RES_COMP, &iwpt3d, &iwpt2d );
									reflist[ indexv ]->newvertexs->SetAt( m, iwVertex );
								}
								break;
							}
						}
					}

					// Si no es de costura abierta lo buscamos en iwVertexsToCopy y cogemos el nuevo (se crea si es necesario)
					if ( !iwVertex ) {
						iwVertexsToCopy.FindElement( iwVertexsFace[ j ], pos );
						if ( iwVertexsNew[ pos ] == 0 ) {
							iwPoint3d.Set( iwVertexsToCopy[ pos ]->GetPoint( ).x, iwVertexsToCopy[ pos ]->GetPoint( ).y, iwVertexsToCopy[ pos ]->GetPoint( ).z );
							iwpt3d = iwVertexsToCopy[ pos ]->GetTexture( );
							iwpt2d = iwVertexsToCopy[ pos ]->GetUV( );
							iwVertex = new IwPolyVertex( _GetSMLib( )->GetContext( ), PBrep ? *PBrep : *pBrep, iwPoint3d, RES_COMP, &iwpt3d, &iwpt2d );
							iwVertexsNew[ pos ] = iwVertex;
						} else
							iwVertex = iwVertexsNew[ pos ];
					}

					// Añadimos al vértice a usar en la creación de la nueva cara.
					iwVertexNewFace.Add( iwVertex );
				}

				// Creamos la nueva cara
				status = PBrep ? PBrep->CreatePolyFace( regions.GetAt( 0 ), shells.GetAt( 0 ), iwVertexNewFace, newFace ) : pBrep->CreatePolyFace( pRegion, pShell, iwVertexNewFace, newFace );
				if ( status != IW_SUCCESS ) {
					if ( !PBrep ) delete pBrep;
					if ( reflist ) {
						for ( k = 0; k < nvertexs; k++ ) {
							if ( !reflist[ k ] ) continue;
							if ( reflist[ k ]->faces ) delete reflist[ k ]->faces;
							if ( reflist[ k ]->newvertexs ) delete reflist[ k ]->newvertexs;
							delete reflist[ k ];
						}
						delete[] reflist;
					}
					return false;
				}

				// Copiamos los bordes y las costuras
				face->GetPolyEdges( iwEdgesFace );
				newFace->GetPolyEdges( iwEdgesNewFace );
				nEdgesFace = (int) iwEdgesFace.GetSize( );
				for ( j = 0; j < nEdgesFace; j++ ) {
					iwEdgeFace = iwEdgesFace[ j ];
					if ( iwEdgeFace->GetUserFloat1( ) > 0 ) {
						iwEdgeNewFace = iwEdgesNewFace[ j ];
						AddCreaseEdges( OGLTransf, iwEdgeNewFace, iwEdgeFace->GetUserFloat1( ), false, false );
					}
					// Copiamos las costuras
					if ( iwEdgeFace->GetUserInt1( ) & MESH_EDGE_SEAM ) {
						iwEdgeNewFace = iwEdgesNewFace[ j ];
						AddSeamEdge( iwEdgeNewFace );
					}
				}
			}
		}

		if ( reflist ) {
			for ( k = 0; k < nvertexs; k++ ) {
				if ( !reflist[ k ] ) continue;
				if ( reflist[ k ]->faces ) delete reflist[ k ]->faces;
				if ( reflist[ k ]->newvertexs ) delete reflist[ k ]->newvertexs;
				delete reflist[ k ];
			}
			delete[] reflist;
		}

		UpdatePBrepCreases( OGLTransf, true, false );

		if ( PBrep ) {
			if ( updateTopology ) UpdateTopology( OGLTransf );
		} else {
			CopyPBrep( pBrep, true );
			UpdateOGLListFromPBrep( OGLTransf, RefEnt->GetOGLList( OGLTransf ), false, true, true, true );
			RefEnt->SetPolygonDirty( true );
			RefEnt->SetPBrepDirty( false );
			delete pBrep;
		}
	}

	return true;
}

//------------------------------------------------------------------------------

bool TPBrepData::SeparateSelectedFaces( TOGLTransf *OGLTransf )
{
	ULONG pos;
	bool separateFace;
	int i, j, k, nFaces, nEdges, nVertexs, nConectedFaces;
	IwPoint3d iwPoint3d, iwpt3d;
	IwPoint2d iwpt2d;
	IwPolyVertex *iwVertex;
	IwPolyEdge *iwEdgeFace, *iwEdgeNewFace;
	IwPolyFace *newFace;
	IwTA<IwPolyVertex *> iwVertexsFace, iwVertexsNewFace, iwVertexsToSeparate, iwVertexsNew;
	IwTA<IwPolyEdge *> iwEdgesFace, iwEdgesNewFace;
	IwTA<IwPolyFace *> iwConectedFaces, iwFacesToSeparate, iwFacesToSelect;
	IwTA<IwPolyRegion *> regions;
	IwTA<IwPolyShell *> shells;

	if ( !OGLTransf || !PBrep ) return false;

	if ( IsAnyFaceSelected( OGLTransf ) ) {
		PBrep->GetPolyRegions( regions );
		PBrep->GetPolyShells( shells );
		if ( regions.GetSize( ) == 0 || shells.GetSize( ) == 0 ) return false;

		// Buscamos las caras y los vertices que han de ser separados.
		// Serán las conectadas con caras no seleccionadas.
		nFaces = CountPBrepFaces( OGLTransf );
		for ( i = 0; i < nFaces; i++ ) {
			if ( IsFaceSelected( OGLTransf, i ) ) {
				separateFace = false;
				GetPBrepFace( OGLTransf, i )->GetPolyVertices( iwVertexsFace );
				nVertexs = (int) iwVertexsFace.GetSize( );
				for ( j = 0; j < nVertexs; j++ ) {
					iwVertexsFace[ j ]->GetPolyFaces( iwConectedFaces );
					nConectedFaces = (int) iwConectedFaces.GetSize( );
					for ( k = 0; k < nConectedFaces; k++ ) {
						if ( !IsFaceSelected( OGLTransf, iwConectedFaces[ k ]->GetIndexExt( ) ) ) {
							separateFace = true;
							iwVertexsToSeparate.AddUnique( iwVertexsFace[ j ] );
							break;
						}
					}
				}
				if ( separateFace ) iwFacesToSeparate.AddUnique( GetPBrepFace( OGLTransf, i ) );
				else
					iwFacesToSelect.Add( GetPBrepFace( OGLTransf, i ) );
			}
		}

		nFaces = (int) iwFacesToSeparate.GetSize( );
		nVertexs = (int) iwVertexsToSeparate.GetSize( );
		if ( nFaces > 0 && nVertexs > 0 ) {
			// Creamos los nuevos vértices
			for ( i = 0; i < nVertexs; i++ ) {
				iwPoint3d.Set( iwVertexsToSeparate[ i ]->GetPoint( ).x, iwVertexsToSeparate[ i ]->GetPoint( ).y, iwVertexsToSeparate[ i ]->GetPoint( ).z );
				iwpt3d = iwVertexsToSeparate[ i ]->GetTexture( );
				iwpt2d = iwVertexsToSeparate[ i ]->GetUV( );
				iwVertex = new IwPolyVertex( _GetSMLib( )->GetContext( ), *PBrep, iwPoint3d, RES_COMP, &iwpt3d, &iwpt2d );
				iwVertexsNew.Add( iwVertex );
			}

			// Separamos las caras creando nuevas y sustituyéndoles los vértices a duplicar
			for ( i = 0; i < nFaces; i++ ) {
				iwVertexsNewFace.RemoveAll( );
				iwFacesToSeparate[ i ]->GetPolyVertices( iwVertexsFace );
				nVertexs = (int) iwVertexsFace.GetSize( );
				for ( j = 0; j < nVertexs; j++ ) {
					if ( iwVertexsToSeparate.FindElement( iwVertexsFace[ j ], pos ) ) iwVertexsNewFace.Add( iwVertexsNew[ pos ] );
					else
						iwVertexsNewFace.Add( iwVertexsFace[ j ] );
				}
				if ( !PBrep->CreatePolyFace( regions.GetAt( 0 ), shells.GetAt( 0 ), iwVertexsNewFace, newFace ) ) return false;
				iwFacesToSelect.Add( newFace );

				// Copiamos los bordes y las costuras
				iwFacesToSeparate[ i ]->GetPolyEdges( iwEdgesFace );
				newFace->GetPolyEdges( iwEdgesNewFace );
				nEdges = (int) iwEdgesFace.GetSize( );
				for ( j = 0; j < nEdges; j++ ) {
					iwEdgeFace = iwEdgesFace.GetAt( j );
					if ( iwEdgeFace->GetUserFloat1( ) > 0 ) {
						iwEdgeNewFace = iwEdgesNewFace.GetAt( j );
						AddCreaseEdges( OGLTransf, iwEdgeNewFace, iwEdgeFace->GetUserFloat1( ), false, false );
					}
					if ( iwEdgeFace->GetUserInt1( ) & MESH_EDGE_SEAM ) {
						iwEdgeNewFace = iwEdgesNewFace.GetAt( j );
						AddSeamEdge( iwEdgeNewFace );
					}
				}
			}

			// Borramos las caras separadas originales y actualizamos la topología
			RemoveFaces( OGLTransf, &iwFacesToSeparate, false );
			UpdateTopology( OGLTransf );

			// Actualizamos la selección
			SelectFaces( OGLTransf, &iwFacesToSelect );
		}
	}

	return true;
}

//------------------------------------------------------------------------------

bool TPBrepData::DuplicateSelectedFaces( TOGLTransf *OGLTransf )
{
	ULONG pos;
	int i, j, nFaces, nEdges, nVertexs;
	IwPoint3d iwPoint3d, iwpt3d;
	IwPoint2d iwpt2d;
	IwPolyVertex *iwVertex;
	IwPolyEdge *iwEdgeFace, *iwEdgeNewFace;
	IwPolyFace *newFace;
	IwTA<IwPolyVertex *> iwVertexsFace, iwVertexsNewFace, iwVertexsToDuplicate, iwVertexsNew;
	IwTA<IwPolyEdge *> iwEdgesFace, iwEdgesNewFace;
	IwTA<IwPolyFace *> iwFacesToDuplicate, iwFacesToSelect;
	IwTA<IwPolyRegion *> regions;
	IwTA<IwPolyShell *> shells;

	if ( !OGLTransf || !PBrep ) return false;

	if ( IsAnyFaceSelected( OGLTransf ) ) {
		PBrep->GetPolyRegions( regions );
		PBrep->GetPolyShells( shells );
		if ( regions.GetSize( ) == 0 || shells.GetSize( ) == 0 ) return false;

		// Buscamos las caras seleccionadas y sus vértices
		nFaces = CountPBrepFaces( OGLTransf );
		for ( i = 0; i < nFaces; i++ ) {
			if ( IsFaceSelected( OGLTransf, i ) ) {
				GetPBrepFace( OGLTransf, i )->GetPolyVertices( iwVertexsFace );
				nVertexs = (int) iwVertexsFace.GetSize( );
				for ( j = 0; j < nVertexs; j++ )
					iwVertexsToDuplicate.AddUnique( iwVertexsFace[ j ] );
				iwFacesToDuplicate.AddUnique( GetPBrepFace( OGLTransf, i ) );
			}
		}

		// Creamos los nuevos vértices
		nVertexs = (int) iwVertexsToDuplicate.GetSize( );
		for ( i = 0; i < nVertexs; i++ ) {
			iwPoint3d.Set( iwVertexsToDuplicate[ i ]->GetPoint( ).x, iwVertexsToDuplicate[ i ]->GetPoint( ).y, iwVertexsToDuplicate[ i ]->GetPoint( ).z );
			iwpt3d = iwVertexsToDuplicate[ i ]->GetTexture( );
			iwpt2d = iwVertexsToDuplicate[ i ]->GetUV( );
			iwVertex = new IwPolyVertex( _GetSMLib( )->GetContext( ), *PBrep, iwPoint3d, RES_COMP, &iwpt3d, &iwpt2d );
			iwVertexsNew.Add( iwVertex );
		}

		// Duplicamos las caras creando nuevas y sustituyéndoles los vértices por los nuevos
		nFaces = (int) iwFacesToDuplicate.GetSize( );
		for ( i = 0; i < nFaces; i++ ) {
			iwVertexsNewFace.RemoveAll( );
			iwFacesToDuplicate[ i ]->GetPolyVertices( iwVertexsFace );
			nVertexs = (int) iwVertexsFace.GetSize( );
			for ( j = 0; j < nVertexs; j++ ) {
				if ( iwVertexsToDuplicate.FindElement( iwVertexsFace[ j ], pos ) ) iwVertexsNewFace.Add( iwVertexsNew[ pos ] );
				else
					return false;
			}
			if ( !PBrep->CreatePolyFace( regions.GetAt( 0 ), shells.GetAt( 0 ), iwVertexsNewFace, newFace ) ) return false;
			iwFacesToSelect.Add( newFace );

			// Copiamos los bordes
			iwFacesToDuplicate[ i ]->GetPolyEdges( iwEdgesFace );
			newFace->GetPolyEdges( iwEdgesNewFace );
			nEdges = (int) iwEdgesFace.GetSize( );
			for ( j = 0; j < nEdges; j++ ) {
				iwEdgeFace = iwEdgesFace.GetAt( j );
				if ( iwEdgeFace->GetUserFloat1( ) > 0 ) {
					iwEdgeNewFace = iwEdgesNewFace.GetAt( j );
					AddCreaseEdges( OGLTransf, iwEdgeNewFace, iwEdgeFace->GetUserFloat1( ), false, false );
				}
				if ( iwEdgeFace->GetUserInt1( ) & MESH_EDGE_SEAM ) {
					iwEdgeNewFace = iwEdgesNewFace.GetAt( j );
					AddSeamEdge( iwEdgeNewFace );
				}
			}
		}

		// Actualizamos la topología
		UpdateTopology( OGLTransf );

		// Actualizamos la selección
		UnSelectAll( OGLTransf );
		SelectFaces( OGLTransf, &iwFacesToSelect );
	}

	return true;
}

//------------------------------------------------------------------------------

bool TPBrepData::JoinMeshes( TOGLTransf *OGLTransf, TCadGroup *group, bool updateTopology )
{
	int i, count;
	TCadEntity *ent;
	TPBrepData *pBrepToCopy;
	IwTA<IwTA<IwPolyEdge *> > edgeGroups;
	IwTA<IwTA<IwPolyEdge *> > edgeGroupsOrdered;
	TInteger_List list;

	if ( !OGLTransf || !group ) return false;
	count = group->Count( );
	if ( count == 0 ) return false;

	// Añadimos las geometrias
	for ( i = 0; i < count; i++ ) {
		ent = group->GetShape( i );
		if ( !ent ) continue;
		if ( ToMesh( ent ) && ToMesh( ent )->IsPolygonalMesh( ) ) pBrepToCopy = ToMesh( ent )->GetPBrepData( false );
		else if ( ToDepMesh( ent ) && ToDepMesh( ent )->IsSubdivisionDepMesh( ) )
			pBrepToCopy = ToMesh( ToDepMesh( ent )->GetBaseEntity( ) )->GetPBrepData( false );
		else
			continue;
		if ( !pBrepToCopy ) continue;

		AddFacesFromPBrep( OGLTransf, pBrepToCopy, false, true, false );
	}

	// Actualizamos la topología
	if ( updateTopology ) {
		UpdateTopology( OGLTransf );

		UpdateOGLListSeamFromPBrep( OGLTransf );
	}

	return true;
}

//------------------------------------------------------------------------------

bool TPBrepData::BooleanOperation( TOGLTransf *OGLTransf, TCadGroup *group, int BooleanOperation, bool updateTopology, bool preserveCreaseAndSeam )
{
	int i, j, k, b, count, cont, contA, contB;
	int nFA, nFB, nVertA, nVertB;
	bool booleanOperationStatus, newCrease;
	double distance, angleAB_AC, distanceBC;
	int nVerticesA, nFacesA, nVerticesB, nFacesB, finalnVertices, finalnFaces, totalNumVerticesPerFace, indexNewB;
	double *verticesA, *verticesB, *finalVertices;
	int *facesA, *facesB, *vertPerFaceA, *vertPerFaceB, *indexPerFaceA, *indexPerFaceB, *finalFaces, *finalVertPerFace, *origFaces, *vertA, *vertB;
	int **neighbor_verticesA, **neighbor_verticesB;
	TCadEntity *ent;
	TPBrepData *pBrepB;
	IwPolyFace *face, *newFace;
	IwTA<IwPolyVertex *> vertices, vertexsNew, vertexFace;
	IwTA<IwPolyRegion *> regions;
	IwTA<IwPolyShell *> shells;
	IwPolyRegion *pRegion;
	IwPolyShell *pShell;
	IwPolyBrep *pBrep;
	IwPoint3d iwPoint3d, iwPoint3dA, iwPoint3dB, iwPoint3dC, newiwPoint3dB;
	IwTA<IwPolyFace *> *fcs;
	IwPolyVertex *iwVertex; //, *iwVertexA, *iwVertexB, *iwVertexC;
	IwTA<IwPolyEdge *> creaseEdges, creaseAllEdges, *seamAllEdges, cE;
	IwTA<int> pairPoints, isSeam;
	IwTA<float> creasePorcentages;
	IwPolyVertex *newVertexB, *vt;
	IwPoint3d AB, AC;
	IwTArray<IwPolyEdge *> rEdges;

#ifndef _USE_LIBIGL
	return false;
#endif

	if ( !OGLTransf || !group ) return false;
	count = group->Count( );
	if ( count == 0 ) return false;

	ent = group->GetShape( 0 );
	if ( !ent ) return false;
	if ( ToMesh( ent ) && ToMesh( ent )->IsPolygonalMesh( ) ) pBrepB = ToMesh( ent )->GetPBrepData( true );
	else if ( ToDepMesh( ent ) && ToDepMesh( ent )->IsSubdivisionDepMesh( ) )
		pBrepB = ToMesh( ToDepMesh( ent )->GetBaseEntity( ) )->GetPBrepData( true );
	else
		return false;

	if ( !pBrepB ) return false;

	// Operación
	nVerticesA = CountPBrepVertexs( OGLTransf );
	nVerticesB = pBrepB->CountPBrepVertexs( OGLTransf );
	nFacesA = CountPBrepFaces( OGLTransf );
	nFacesB = pBrepB->CountPBrepFaces( OGLTransf );
	verticesA = new double[ nVerticesA * 3 ];
	verticesB = new double[ nVerticesB * 3 ];
	j = ( nVerticesA > nVerticesB ) ? nVerticesA : nVerticesB;
	contA = 0;
	contB = 0;
	for ( i = 0; i < j; i++ ) {
		if ( i < nVerticesA ) {
			verticesA[ contA++ ] = GetPBrepVertex( OGLTransf, i )->GetPoint( ).x;
			verticesA[ contA++ ] = GetPBrepVertex( OGLTransf, i )->GetPoint( ).y;
			verticesA[ contA++ ] = GetPBrepVertex( OGLTransf, i )->GetPoint( ).z;
		}

		if ( i < nVerticesB ) {
			verticesB[ contB++ ] = pBrepB->GetPBrepVertex( OGLTransf, i )->GetPoint( ).x;
			verticesB[ contB++ ] = pBrepB->GetPBrepVertex( OGLTransf, i )->GetPoint( ).y;
			verticesB[ contB++ ] = pBrepB->GetPBrepVertex( OGLTransf, i )->GetPoint( ).z;
		}
	}

	vertPerFaceA = new int[ nFacesA ];
	indexPerFaceA = new int[ nFacesA ];
	vertPerFaceB = new int[ nFacesB ];
	indexPerFaceB = new int[ nFacesB ];

	totalNumVerticesPerFace = 0;
	for ( i = 0; i < nFacesA; i++ ) {
		face = GetPBrepFace( OGLTransf, i );
		face->GetPolyVertices( vertices );
		vertPerFaceA[ i ] = vertices.GetSize( );
		indexPerFaceA[ i ] = totalNumVerticesPerFace;
		totalNumVerticesPerFace += vertPerFaceA[ i ];
	}

	facesA = new int[ totalNumVerticesPerFace ];

	totalNumVerticesPerFace = 0;
	for ( i = 0; i < nFacesB; i++ ) {
		face = pBrepB->GetPBrepFace( OGLTransf, i );
		face->GetPolyVertices( vertices );
		vertPerFaceB[ i ] = vertices.GetSize( );
		indexPerFaceB[ i ] = totalNumVerticesPerFace;
		totalNumVerticesPerFace += vertPerFaceB[ i ];
	}

	facesB = new int[ totalNumVerticesPerFace ];

	j = ( nFacesA > nFacesB ) ? nFacesA : nFacesB;
	nFA = 0;
	nFB = 0;
	for ( i = 0; i < j; i++ ) {
		if ( i < nFacesA ) {
			face = GetPBrepFace( OGLTransf, i );
			face->GetPolyVertices( vertices );

			for ( k = 0; k < vertPerFaceA[ i ]; k++ ) {
				facesA[ nFA++ ] = vertices[ k ]->GetIndexExt( );
			}
		}

		if ( i < nFacesB ) {
			face = pBrepB->GetPBrepFace( OGLTransf, i );
			face->GetPolyVertices( vertices );

			for ( k = 0; k < vertPerFaceB[ i ]; k++ ) {
				facesB[ nFB++ ] = vertices[ k ]->GetIndexExt( );
			}
		}
	}

	finalVertices = 0;
	finalFaces = 0;
	finalVertPerFace = 0;
	origFaces = 0;
	neighbor_verticesA = 0;
	neighbor_verticesB = 0;
	vertA = 0;
	vertB = 0;
	nVertA = 0;
	nVertB = 0;
	finalnVertices = 0;
	finalnFaces = 0;
#ifdef _USE_LIBIGL
	booleanOperationStatus = LibiglWrapper::boolean_op_solid_solid( nVerticesA, nFacesA, verticesA, facesA, vertPerFaceA, indexPerFaceA, nVerticesB, nFacesB, verticesB, facesB, vertPerFaceB, indexPerFaceB, BooleanOperation, finalnVertices, finalnFaces, finalVertices, finalFaces, finalVertPerFace, origFaces, nVertA, vertA, nVertB, vertB, neighbor_verticesA, neighbor_verticesB );
#else
	booleanOperationStatus = false;
#endif

	std::ofstream file1;
	file1.open( "d:/Users/GMARTINEZ/Desktop/cuboA.txt" );
	for ( int i = 0; i < nVertA; i++ ) {
		file1 << vertA[ i ] << " ";
	}
	file1 << "\n";

	for ( int i = 0; i < nVertB; i++ ) {
		file1 << vertB[ i ] << " ";
	}

	file1 << "\n\n";

	for ( int i = 0; i < nVertA; i++ ) {
		for ( int j = 0; j < neighbor_verticesA[ i ][ 0 ] + 1; j++ ) {
			file1 << neighbor_verticesA[ i ][ j ] << " ";
		}
		file1 << "\n";
	}

	file1.close( );

	std::ofstream file;
	file.open( "d:/Users/GMARTINEZ/Desktop/salida.obj" );

	for ( int i = 0; i < finalnVertices; i++ ) {
		file << "v " << finalVertices[ i * 3 ] << " " << finalVertices[ i * 3 + 1 ] << " " << finalVertices[ i * 3 + 2 ] << "\n";
	}

	int f = 0;
	for ( int i = 0; i < finalnFaces; i++ ) {
		file << "f ";
		for ( int j = 0; j < finalVertPerFace[ i ]; j++ ) {
			file << finalFaces[ f ] + 1 << " ";
			f++;
		}
		file << "\n";
	}

	file.close( );

	if ( !booleanOperationStatus ) {
		delete[] verticesA;
		delete[] verticesB;
		delete[] facesA;
		delete[] facesB;
		delete[] vertPerFaceA;
		delete[] indexPerFaceA;
		delete[] vertPerFaceB;
		delete[] indexPerFaceB;

		return false;
	}

	if ( PBrep ) {
		PBrep->GetPolyRegions( regions );
		PBrep->GetPolyShells( shells );
		if ( regions.GetSize( ) == 0 || shells.GetSize( ) == 0 ) {
			/*delete finalVertices;
			delete finalFaces;
			delete finalVertPerFace;
			delete origFaces;
			for ( i = 0; i < nVertA; i++ )
				delete neighbor_verticesA[ i ];
			for ( i = 0; i < nVertB; i++ )
				delete neighbor_verticesB[ i ]; */
			delete[] verticesA;
			delete[] verticesB;
			delete[] facesA;
			delete[] facesB;
			delete[] vertPerFaceA;
			delete[] indexPerFaceA;
			delete[] vertPerFaceB;
			delete[] indexPerFaceB;
			LibiglWrapper::free_double_function( finalVertices );
			LibiglWrapper::free_int_function( finalFaces );
			LibiglWrapper::free_int_function( finalVertPerFace );
			LibiglWrapper::free_int_function( origFaces );
			LibiglWrapper::free_int_function( vertA );
			LibiglWrapper::free_int_function( vertB );
			LibiglWrapper::free_array_int_function( neighbor_verticesA, nVertA );
			LibiglWrapper::free_array_int_function( neighbor_verticesB, nVertB );

			return false;
		}
		pBrep = 0;
	} else {
		pBrep = new IwPolyBrep( _GetSMLib( )->GetContext( ), RES_COMP );
		pRegion = new IwPolyRegion( _GetSMLib( )->GetContext( ), pBrep );
		pShell = new IwPolyShell( _GetSMLib( )->GetContext( ), *pBrep, pRegion );
	}

	if ( preserveCreaseAndSeam ) {
		newCrease = true;
		GetCreaseEdges( OGLTransf, &creaseAllEdges );
		seamAllEdges = GetSeams( );

		for ( i = 0; i < nVertA; i++ ) {
			iwPoint3dA.Set( finalVertices[ vertA[ i ] * 3 ], finalVertices[ vertA[ i ] * 3 + 1 ], finalVertices[ vertA[ i ] * 3 + 2 ] );
			// iwVertexA = new IwPolyVertex( _GetSMLib( )->GetContext( ), PBrep ? *PBrep : *pBrep, iwPoint3d, RES_COMP );
			GetCreaseAndSeamEdgesFromVertex( /*iwVertexA*/ iwPoint3dA, &creaseEdges, creaseAllEdges, *seamAllEdges );

			for ( j = 0; j < (int) creaseEdges.GetSize( ); j++ ) {
				if ( creaseEdges.GetAt( j )->GetStartVertex( )->GetPoint( ) != iwPoint3dA /*iwVertexA->GetPoint( )*/ ) {
					// iwVertexB = creaseEdges.GetAt( j )->GetStartVertex( );
					iwPoint3dB = creaseEdges.GetAt( j )->GetStartVertex( )->GetPoint( );
				} else {
					// iwVertexB = creaseEdges.GetAt( j )->GetEndVertex( );
					iwPoint3dB = creaseEdges.GetAt( j )->GetEndVertex( )->GetPoint( );
				}

				distance = DBL_MAX;
				AB = iwPoint3dB /*iwVertexB->GetPoint( )*/ - iwPoint3dA /*iwVertexA->GetPoint( )*/;
				indexNewB = -1;
				for ( k = 1; k <= neighbor_verticesA[ i ][ 0 ]; k++ ) {
					iwPoint3dC.Set( finalVertices[ neighbor_verticesA[ i ][ k ] * 3 ], finalVertices[ neighbor_verticesA[ i ][ k ] * 3 + 1 ], finalVertices[ neighbor_verticesA[ i ][ k ] * 3 + 2 ] );
					// iwVertexC = new IwPolyVertex( _GetSMLib( )->GetContext( ), PBrep ? *PBrep : *pBrep, iwPoint3d, RES_COMP );

					if ( iwPoint3dB /*iwVertexB->GetPoint( )*/ == iwPoint3dC /*iwVertexC->GetPoint( )*/ ) {
						// Mantenemos pliegue
						pairPoints.Add( vertA[ i ] );

						for ( b = 0; b < finalnVertices; b++ ) {
							IwPoint3d aux( finalVertices[ b * 3 ], finalVertices[ b * 3 + 1 ], finalVertices[ b * 3 + 2 ] );
							if ( aux == iwPoint3dB /*iwVertexB->GetPoint( )*/ ) break;
						}

						pairPoints.Add( b );
						isSeam.Add( creaseEdges[ j ]->GetUserInt1( ) );
						creasePorcentages.Add( creaseEdges[ j ]->GetUserFloat1( ) );
						newCrease = false;
						// delete iwVertexC;
						break;
					} else {
						AC = iwPoint3dC /*iwVertexC->GetPoint( )*/ - iwPoint3dA /*iwVertexA->GetPoint( )*/;
						angleAB_AC = asin( ( AB * AC ).Length( ) / ( AB.Length( ) * AC.Length( ) ) );

						if ( std::fabs( angleAB_AC ) < RES_COMP ) {
							// newVertexB = iwVertexC;
							newiwPoint3dB = iwPoint3dC;
							// distanceBC = iwVertexA->GetPoint( ).DistanceBetween( newVertexB->GetPoint( ) );
							distanceBC = iwPoint3dA.DistanceBetween( newiwPoint3dB );

							if ( distanceBC < distance ) {
								distance = distanceBC;
								indexNewB = neighbor_verticesA[ i ][ k ];
							}
						}

						// delete iwVertexC;
					}
				}

				if ( newCrease && indexNewB != -1 ) {
					// Nuevo pliegue
					pairPoints.Add( vertA[ i ] );
					pairPoints.Add( indexNewB );
					isSeam.Add( creaseEdges[ j ]->GetUserInt1( ) );
					creasePorcentages.Add( creaseEdges[ j ]->GetUserFloat1( ) );
					indexNewB = -1;
					// delete iwVertexC;
				} else {
					newCrease = true;
				}
			}

			// delete iwVertexA;
		}

		creaseAllEdges.RemoveAll( );
		seamAllEdges->RemoveAll( );
		pBrepB->GetCreaseEdges( OGLTransf, &creaseAllEdges );
		seamAllEdges = pBrepB->GetSeams( );

		for ( i = 0; i < nVertB; i++ ) {
			iwPoint3dA.Set( finalVertices[ vertB[ i ] * 3 ], finalVertices[ vertB[ i ] * 3 + 1 ], finalVertices[ vertB[ i ] * 3 + 2 ] );
			// iwVertexA = new IwPolyVertex( _GetSMLib( )->GetContext( ), PBrep ? *PBrep : *pBrep, iwPoint3d, RES_COMP );
			pBrepB->GetCreaseAndSeamEdgesFromVertex( iwPoint3dA /*iwVertexA*/, &creaseEdges, creaseAllEdges, *seamAllEdges );

			for ( j = 0; j < (int) creaseEdges.GetSize( ); j++ ) {
				if ( creaseEdges.GetAt( j )->GetStartVertex( )->GetPoint( ) != iwPoint3dA /*iwVertexA->GetPoint( )*/ ) {
					// iwVertexB = creaseEdges.GetAt( j )->GetStartVertex( );
					iwPoint3dB = creaseEdges.GetAt( j )->GetStartVertex( )->GetPoint( );
				} else {
					// iwVertexB = creaseEdges.GetAt( j )->GetEndVertex( );
					iwPoint3dB = creaseEdges.GetAt( j )->GetEndVertex( )->GetPoint( );
				}

				distance = DBL_MAX;
				AB = iwPoint3dB /*iwVertexB->GetPoint( )*/ - iwPoint3dA /*iwVertexA->GetPoint( )*/;
				indexNewB = -1;
				for ( k = 1; k <= neighbor_verticesB[ i ][ 0 ]; k++ ) {
					iwPoint3dC.Set( finalVertices[ neighbor_verticesB[ i ][ k ] * 3 ], finalVertices[ neighbor_verticesB[ i ][ k ] * 3 + 1 ], finalVertices[ neighbor_verticesB[ i ][ k ] * 3 + 2 ] );
					// iwVertexC = new IwPolyVertex( _GetSMLib( )->GetContext( ), PBrep ? *PBrep : *pBrep, iwPoint3d, RES_COMP );

					if ( iwPoint3dB /*iwVertexB->GetPoint( )*/ == iwPoint3dC /*iwVertexC->GetPoint( )*/ ) {
						// Mantenemos pliegue
						pairPoints.Add( vertB[ i ] );

						for ( b = 0; b < finalnVertices; b++ ) {
							IwPoint3d aux( finalVertices[ b * 3 ], finalVertices[ b * 3 + 1 ], finalVertices[ b * 3 + 2 ] );
							if ( aux == iwPoint3dB /*iwVertexB->GetPoint( )*/ ) break;
						}

						pairPoints.Add( b );
						isSeam.Add( creaseEdges[ j ]->GetUserInt1( ) );
						creasePorcentages.Add( creaseEdges[ j ]->GetUserFloat1( ) );
						newCrease = false;
						// delete iwVertexC;
						break;
					} else {
						AC = iwPoint3dC /*iwVertexC->GetPoint( )*/ - iwPoint3dA /*iwVertexA->GetPoint( )*/;
						angleAB_AC = asin( ( AB * AC ).Length( ) / ( AB.Length( ) * AC.Length( ) ) );

						if ( std::fabs( angleAB_AC ) < RES_COMP ) {
							// newVertexB = iwVertexC;
							newiwPoint3dB = iwPoint3dC;
							// distanceBC = iwVertexA->GetPoint( ).DistanceBetween( newVertexB->GetPoint( ) );
							distanceBC = iwPoint3dA.DistanceBetween( newiwPoint3dB );

							if ( distanceBC < distance ) {
								distance = distanceBC;
								indexNewB = neighbor_verticesB[ i ][ k ];
							}
						}
					}

					// delete iwVertexC;
				}

				if ( newCrease && indexNewB != -1 ) {
					// Nuevo pliegue
					pairPoints.Add( vertB[ i ] );
					pairPoints.Add( indexNewB );
					isSeam.Add( creaseEdges[ j ]->GetUserInt1( ) );
					creasePorcentages.Add( creaseEdges[ j ]->GetUserFloat1( ) );
					indexNewB = -1;
					// delete iwVertexC;
				} else {
					newCrease = true;
				}
			}

			// delete iwVertexA;
		}
	}

	fcs = GetPBrepFaces( OGLTransf );
	for ( i = 0; i < (int) fcs->GetSize( ); i++ )
		PBrep->DeletePolyFace( ( *fcs ).GetAt( i ) );

	for ( i = 0; i < finalnVertices; i++ ) {
		iwPoint3d.Set( finalVertices[ i * 3 ], finalVertices[ i * 3 + 1 ], finalVertices[ i * 3 + 2 ] );
		iwVertex = new IwPolyVertex( _GetSMLib( )->GetContext( ), PBrep ? *PBrep : *pBrep, iwPoint3d, RES_COMP );
		vertexsNew.Add( iwVertex );
	}

	cont = 0;
	for ( i = 0; i < finalnFaces; i++ ) {
		vertexFace.RemoveAll( );
		for ( j = 0; j < finalVertPerFace[ i ]; j++ ) {
			vertexFace.Add( vertexsNew[ finalFaces[ cont ] ] );
			cont++;
		}
		PBrep ? PBrep->CreatePolyFace( regions.GetAt( 0 ), shells.GetAt( 0 ), vertexFace, newFace ) : pBrep->CreatePolyFace( pRegion, pShell, vertexFace, newFace );
	}

	if ( PBrep ) {
		if ( updateTopology ) UpdateTopology( OGLTransf );
	} else {
		CopyPBrep( pBrep, true );
		UpdateOGLListFromPBrep( OGLTransf, RefEnt->GetOGLList( OGLTransf ), false, true, true, true );
		RefEnt->SetPolygonDirty( true );
		RefEnt->SetPBrepDirty( false );
		delete pBrep;
	}

	if ( preserveCreaseAndSeam ) {
		GetCreaseEdges( OGLTransf, &cE );
		for ( i = 0; i < (int) pairPoints.GetSize( ); i += 2 ) {
			vt = GetPBrepVertex( OGLTransf, pairPoints.GetAt( i ) );
			vt->GetStartingPolyEdges( rEdges );
			for ( j = 0; j < (int) rEdges.GetSize( ); j++ ) {
				if ( rEdges.GetAt( j )->GetEndVertex( ) == GetPBrepVertex( OGLTransf, pairPoints.GetAt( i + 1 ) ) ) {
					if ( isSeam.GetAt( i / 2 ) ) AddSeamEdge( rEdges.GetAt( j ) );
					if ( creasePorcentages.GetAt( i / 2 ) > 0 ) AddCreaseEdges( OGLTransf, rEdges.GetAt( j ), creasePorcentages.GetAt( i / 2 ), false, false );
					break;
				}
			}
		}
	}

	delete[] verticesA;
	delete[] verticesB;
	delete[] facesA;
	delete[] facesB;
	delete[] vertPerFaceA;
	delete[] indexPerFaceA;
	delete[] vertPerFaceB;
	delete[] indexPerFaceB;
	if ( pBrep ) delete pBrep;
	// delete[] finalVertices;
	LibiglWrapper::free_double_function( finalVertices );
	LibiglWrapper::free_int_function( finalFaces );
	LibiglWrapper::free_int_function( finalVertPerFace );
	LibiglWrapper::free_int_function( origFaces );
	LibiglWrapper::free_int_function( vertA );
	LibiglWrapper::free_int_function( vertB );
	LibiglWrapper::free_array_int_function( neighbor_verticesA, nVertA );
	LibiglWrapper::free_array_int_function( neighbor_verticesB, nVertB );

	// delete pRegion;
	// delete pShell;

	return true;
}

//------------------------------------------------------------------------------

bool TPBrepData::BooleanOperationMultiple( TOGLTransf *OGLTransf, TCadGroup *group, int BooleanOperation, bool updateTopology, bool preserveCreaseAndSeam )
{
	int i, j, k, count, cont, nMeshes, totalNumVerticesPerFace, index, indexNewB, newCrease;
	bool booleanOperationStatus;
	int *nVerticesPerMesh, *nFacesPerMesh, *vertA, *vertB;
	double **vertices, *finalVertices;
	int **faces, **indexPerFace, **vertPerface;
	int finalnVertices, finalnFaces, nVertA, nVertB;
	int *finalFaces, *finalVertPerFace, *origFaces;
	int **neighbor_verticesA, **neighbor_verticesB;
	double distance, angleAB_AC, distanceBC;
	TCadEntity *ent;
	TPBrepData *pBrepB;
	IwPolyBrep *pBrep;
	IwTA<IwPolyVertex *> vts, vertexsNew, vertexFace;
	IwPolyFace *face, *newFace;
	IwTA<IwPolyRegion *> regions;
	IwTA<IwPolyShell *> shells;
	IwPolyRegion *pRegion;
	IwPolyShell *pShell;
	IwPoint3d iwPoint3d, iwPoint3dA, iwPoint3dB, iwPoint3dC, newiwPoint3dB;
	IwPolyVertex *iwVertex; //, *iwVertexA, *iwVertexB, *iwVertexC;
	IwTA<IwPolyFace *> *fcs;
	IwTA<IwPolyEdge *> creaseEdges, creaseAllEdges, cE, rEdges;
	IwTA<IwPolyEdge *> *seamAllEdges;
	IwPolyVertex *newVertexB, *vt;
	IwPoint3d AB, AC;

#ifndef _USE_LIBIGL
	return false;
#endif

	if ( !OGLTransf || !group ) return false;
	count = group->Count( );
	if ( count <= 1 ) return false;

	nMeshes = count + 1;
	nVerticesPerMesh = new int[ nMeshes ];
	vertices = new double *[ nMeshes ];
	nFacesPerMesh = new int[ nMeshes ];
	faces = new int *[ nMeshes ];
	indexPerFace = new int *[ nMeshes ];
	vertPerface = new int *[ nMeshes ];

	nVerticesPerMesh[ 0 ] = CountPBrepVertexs( OGLTransf );
	nFacesPerMesh[ 0 ] = CountPBrepFaces( OGLTransf );
	vertices[ 0 ] = new double[ CountPBrepVertexs( OGLTransf ) * 3 ];
	for ( i = 0; i < CountPBrepVertexs( OGLTransf ); i++ ) {
		vertices[ 0 ][ i * 3 ] = GetPBrepVertex( OGLTransf, i )->GetPoint( ).x;
		vertices[ 0 ][ i * 3 + 1 ] = GetPBrepVertex( OGLTransf, i )->GetPoint( ).y;
		vertices[ 0 ][ i * 3 + 2 ] = GetPBrepVertex( OGLTransf, i )->GetPoint( ).z;
	}

	// faces[ 0 ] = new int[ nFacesPerMesh[0] * nFacesPerMesh[0] ];
	vertPerface[ 0 ] = new int[ nFacesPerMesh[ 0 ] ];
	indexPerFace[ 0 ] = new int[ nFacesPerMesh[ 0 ] ];

	totalNumVerticesPerFace = 0;
	for ( i = 0; i < nFacesPerMesh[ 0 ]; i++ ) {
		face = GetPBrepFace( OGLTransf, i );
		face->GetPolyVertices( vts );
		vertPerface[ 0 ][ i ] = vts.GetSize( );
		indexPerFace[ 0 ][ i ] = totalNumVerticesPerFace;
		totalNumVerticesPerFace += vertPerface[ 0 ][ i ];
	}

	faces[ 0 ] = new int[ totalNumVerticesPerFace ];
	index = 0;
	for ( i = 0; i < nFacesPerMesh[ 0 ]; i++ ) {
		face = GetPBrepFace( OGLTransf, i );
		face->GetPolyVertices( vts );
		for ( j = 0; j < (int) vts.GetSize( ); j++ ) {
			faces[ 0 ][ index++ ] = vts[ j ]->GetIndexExt( );
		}
	}

	for ( i = 1; i < nMeshes; i++ ) {
		ent = group->GetShape( i - 1 );
		if ( !ent ) continue;
		if ( ToMesh( ent ) && ToMesh( ent )->IsPolygonalMesh( ) ) pBrepB = ToMesh( ent )->GetPBrepData( true );
		else if ( ToDepMesh( ent ) && ToDepMesh( ent )->IsSubdivisionDepMesh( ) )
			pBrepB = ToMesh( ToDepMesh( ent )->GetBaseEntity( ) )->GetPBrepData( true );
		else
			continue;

		if ( !pBrepB ) continue;

		nVerticesPerMesh[ i ] = pBrepB->CountPBrepVertexs( OGLTransf );
		nFacesPerMesh[ i ] = pBrepB->CountPBrepFaces( OGLTransf );
		vertices[ i ] = new double[ pBrepB->CountPBrepVertexs( OGLTransf ) * 3 ];
		for ( j = 0; j < pBrepB->CountPBrepVertexs( OGLTransf ); j++ ) {
			vertices[ i ][ j * 3 ] = pBrepB->GetPBrepVertex( OGLTransf, j )->GetPoint( ).x;
			vertices[ i ][ j * 3 + 1 ] = pBrepB->GetPBrepVertex( OGLTransf, j )->GetPoint( ).y;
			vertices[ i ][ j * 3 + 2 ] = pBrepB->GetPBrepVertex( OGLTransf, j )->GetPoint( ).z;
		}

		vertPerface[ i ] = new int[ nFacesPerMesh[ i ] ];
		indexPerFace[ i ] = new int[ nFacesPerMesh[ i ] ];

		totalNumVerticesPerFace = 0;
		for ( j = 0; j < nFacesPerMesh[ i ]; j++ ) {
			face = pBrepB->GetPBrepFace( OGLTransf, j );
			face->GetPolyVertices( vts );
			vertPerface[ i ][ j ] = vts.GetSize( );
			indexPerFace[ i ][ j ] = totalNumVerticesPerFace;
			totalNumVerticesPerFace += vertPerface[ i ][ j ];
		}

		faces[ i ] = new int[ totalNumVerticesPerFace ];
		index = 0;
		for ( j = 0; j < nFacesPerMesh[ i ]; j++ ) {
			face = pBrepB->GetPBrepFace( OGLTransf, j );
			face->GetPolyVertices( vts );
			for ( k = 0; k < (int) vts.GetSize( ); k++ ) {
				faces[ i ][ index++ ] = vts[ k ]->GetIndexExt( );
			}
		}
	}

	nVertA = 0;
	nVertB = 0;
	finalnVertices = 0;
	finalnFaces = 0;
	origFaces = 0;
	finalVertices = 0;
	finalFaces = 0;
	finalVertPerFace = 0;
	vertA = 0;
	vertB = 0;
	neighbor_verticesA = 0;
	neighbor_verticesB = 0;
#ifdef _USE_LIBIGL
	booleanOperationStatus = LibiglWrapper::boolean_op_multiple_solids( nMeshes, nVerticesPerMesh, vertices, nFacesPerMesh, faces, indexPerFace, vertPerface, BooleanOperation, finalnVertices, finalnFaces, finalVertices, finalFaces, finalVertPerFace, origFaces, nVertA, vertA, nVertB, vertB, neighbor_verticesA, neighbor_verticesB );
#else
	booleanOperationStatus = false;
#endif

	if ( !booleanOperationStatus ) {
		for ( i = 0; i < nMeshes; i++ ) {
			delete[] vertices[ i ];
			delete[] faces[ i ];
			delete[] indexPerFace[ i ];
			delete[] vertPerface[ i ];
		}
		delete[] vertices;
		delete[] faces;
		delete[] nVerticesPerMesh;
		delete[] nFacesPerMesh;
		delete[] indexPerFace;
		delete[] vertPerface;

		return false;
	}

	if ( PBrep ) {
		PBrep->GetPolyRegions( regions );
		PBrep->GetPolyShells( shells );
		if ( regions.GetSize( ) == 0 || shells.GetSize( ) == 0 ) {
			for ( i = 0; i < nMeshes; i++ ) {
				delete[] vertices[ i ];
				delete[] faces[ i ];
				delete[] indexPerFace[ i ];
				delete[] vertPerface[ i ];
			}
			delete[] vertices;
			delete[] faces;
			delete[] nVerticesPerMesh;
			delete[] nFacesPerMesh;
			delete[] indexPerFace;
			delete[] vertPerface;
			LibiglWrapper::free_double_function( finalVertices );
			LibiglWrapper::free_int_function( finalFaces );
			LibiglWrapper::free_int_function( finalVertPerFace );
			LibiglWrapper::free_int_function( origFaces );
			LibiglWrapper::free_int_function( vertA );
			LibiglWrapper::free_int_function( vertB );
			LibiglWrapper::free_array_int_function( neighbor_verticesA, nVertA );
			LibiglWrapper::free_array_int_function( neighbor_verticesB, nVertB );

			return false;
		}
		pBrep = 0;
	} else {
		pBrep = new IwPolyBrep( _GetSMLib( )->GetContext( ), RES_COMP );
		pRegion = new IwPolyRegion( _GetSMLib( )->GetContext( ), pBrep );
		pShell = new IwPolyShell( _GetSMLib( )->GetContext( ), *pBrep, pRegion );
	}

	IwTA<int> pairPoints;
	IwTA<float> creasePorcentages;
	IwTA<int> isSeam;
	if ( preserveCreaseAndSeam ) {
		newCrease = true;
		GetCreaseEdges( OGLTransf, &creaseAllEdges );
		seamAllEdges = GetSeams( );

		for ( int i = 0; i < nVertA; i++ ) {
			iwPoint3dA.Set( finalVertices[ vertA[ i ] * 3 ], finalVertices[ vertA[ i ] * 3 + 1 ], finalVertices[ vertA[ i ] * 3 + 2 ] );
			// iwVertexA = new IwPolyVertex( _GetSMLib( )->GetContext( ), PBrep ? *PBrep : *pBrep, iwPoint3d, RES_COMP );
			GetCreaseAndSeamEdgesFromVertex( iwPoint3dA /*iwVertexA*/, &creaseEdges, creaseAllEdges, *seamAllEdges );

			for ( int j = 0; j < (int) creaseEdges.GetSize( ); j++ ) {
				if ( creaseEdges.GetAt( j )->GetStartVertex( )->GetPoint( ) != iwPoint3dA /*iwVertexA->GetPoint( )*/ ) {
					// iwVertexB = creaseEdges.GetAt( j )->GetStartVertex( );
					iwPoint3dB = creaseEdges.GetAt( j )->GetStartVertex( )->GetPoint( );
				} else {
					// iwVertexB = creaseEdges.GetAt( j )->GetEndVertex( );
					iwPoint3dB = creaseEdges.GetAt( j )->GetEndVertex( )->GetPoint( );
				}

				distance = DBL_MAX;
				AB = iwPoint3dB /*iwVertexB->GetPoint( )*/ - iwPoint3dA /*iwVertexA->GetPoint( )*/;
				indexNewB = -1;
				for ( k = 1; k <= neighbor_verticesA[ i ][ 0 ]; k++ ) {
					iwPoint3dC.Set( finalVertices[ neighbor_verticesA[ i ][ k ] * 3 ], finalVertices[ neighbor_verticesA[ i ][ k ] * 3 + 1 ], finalVertices[ neighbor_verticesA[ i ][ k ] * 3 + 2 ] );
					// iwVertexC = new IwPolyVertex( _GetSMLib( )->GetContext( ), PBrep ? *PBrep : *pBrep, iwPoint3d, RES_COMP );

					if ( iwPoint3dB /*iwVertexB->GetPoint( )*/ == iwPoint3dC /*iwVertexC->GetPoint( )*/ ) {
						// Mantenemos pliegue
						pairPoints.Add( vertA[ i ] );

						int b;
						for ( b = 0; b < finalnVertices; b++ ) {
							IwPoint3d aux( finalVertices[ b * 3 ], finalVertices[ b * 3 + 1 ], finalVertices[ b * 3 + 2 ] );
							if ( aux == iwPoint3dB /*iwVertexB->GetPoint( )*/ ) break;
						}

						pairPoints.Add( b );
						isSeam.Add( creaseEdges[ j ]->GetUserInt1( ) );
						creasePorcentages.Add( creaseEdges[ j ]->GetUserFloat1( ) );
						newCrease = false;
						// delete iwVertexC;
						break;
					} else {
						IwPoint3d AC = iwPoint3dC /*iwVertexC->GetPoint( )*/ - iwPoint3dA /*iwVertexA->GetPoint( )*/;
						double angleAB_AC = asin( ( AB * AC ).Length( ) / ( AB.Length( ) * AC.Length( ) ) );

						if ( std::fabs( angleAB_AC ) < RES_COMP ) {
							// newVertexB = iwVertexC;
							newiwPoint3dB = iwPoint3dC;
							// double distanceBC = iwVertexA->GetPoint( ).DistanceBetween( newVertexB->GetPoint( ) );
							distanceBC = iwPoint3dA.DistanceBetween( newiwPoint3dB );
							if ( distanceBC < distance ) {
								distance = distanceBC;
								indexNewB = neighbor_verticesA[ i ][ k ];
							}
						}
					}
				}

				if ( newCrease && indexNewB != -1 ) {
					// Nuevo pliegue
					pairPoints.Add( vertA[ i ] );
					pairPoints.Add( indexNewB );
					isSeam.Add( creaseEdges[ j ]->GetUserInt1( ) );
					creasePorcentages.Add( creaseEdges[ j ]->GetUserFloat1( ) );
					indexNewB = -1;
					// delete iwVertexC;
				} else {
					newCrease = true;
				}
			}

			// delete iwVertexA;
		}

		for ( int m = 1; m < nMeshes; m++ ) {
			ent = group->GetShape( m - 1 );
			if ( !ent ) continue;
			if ( ToMesh( ent ) && ToMesh( ent )->IsPolygonalMesh( ) ) pBrepB = ToMesh( ent )->GetPBrepData( true );
			else if ( ToDepMesh( ent ) && ToDepMesh( ent )->IsSubdivisionDepMesh( ) )
				pBrepB = ToMesh( ToDepMesh( ent )->GetBaseEntity( ) )->GetPBrepData( true );
			else
				continue;

			if ( !pBrepB ) continue;

			creaseAllEdges.RemoveAll( );
			seamAllEdges->RemoveAll( );
			pBrepB->GetCreaseEdges( OGLTransf, &creaseAllEdges );
			seamAllEdges = pBrepB->GetSeams( );

			for ( int i = 0; i < nVertB; i++ ) {
				iwPoint3dA.Set( finalVertices[ vertB[ i ] * 3 ], finalVertices[ vertB[ i ] * 3 + 1 ], finalVertices[ vertB[ i ] * 3 + 2 ] );
				// iwVertexA = new IwPolyVertex( _GetSMLib( )->GetContext( ), PBrep ? *PBrep : *pBrep, iwPoint3d, RES_COMP );
				pBrepB->GetCreaseAndSeamEdgesFromVertex( iwPoint3dA /*iwVertexA*/, &creaseEdges, creaseAllEdges, *seamAllEdges );

				for ( int j = 0; j < (int) creaseEdges.GetSize( ); j++ ) {
					if ( creaseEdges.GetAt( j )->GetStartVertex( )->GetPoint( ) != iwPoint3dA /*iwVertexA->GetPoint( )*/ ) {
						// iwVertexB = creaseEdges.GetAt( j )->GetStartVertex( );
						iwPoint3dB = creaseEdges.GetAt( j )->GetStartVertex( )->GetPoint( );
					} else {
						// iwVertexB = creaseEdges.GetAt( j )->GetEndVertex( );
						iwPoint3dB = creaseEdges.GetAt( j )->GetEndVertex( )->GetPoint( );
					}

					double distance = DBL_MAX;
					// IwPolyVertex *newVertexB;
					IwPoint3d AB = iwPoint3dB /*iwVertexB->GetPoint( )*/ - iwPoint3dA /*iwVertexA->GetPoint( )*/;
					int indexNewB = -1;
					for ( int k = 1; k <= neighbor_verticesB[ i ][ 0 ]; k++ ) {
						iwPoint3dC.Set( finalVertices[ neighbor_verticesB[ i ][ k ] * 3 ], finalVertices[ neighbor_verticesB[ i ][ k ] * 3 + 1 ], finalVertices[ neighbor_verticesB[ i ][ k ] * 3 + 2 ] );
						// iwVertexC = new IwPolyVertex( _GetSMLib( )->GetContext( ), PBrep ? *PBrep : *pBrep, iwPoint3d, RES_COMP );

						if ( iwPoint3dB /*iwVertexB->GetPoint( )*/ == iwPoint3dC /*iwVertexC->GetPoint( )*/ ) {
							// Mantenemos pliegue
							pairPoints.Add( /*iwVertexA->GetPoint( )*/ vertB[ i ] );

							int b;
							for ( b = 0; b < finalnVertices; b++ ) {
								IwPoint3d aux( finalVertices[ b * 3 ], finalVertices[ b * 3 + 1 ], finalVertices[ b * 3 + 2 ] );
								if ( aux == iwPoint3dB /*iwVertexB->GetPoint( )*/ ) break;
							}

							pairPoints.Add( /*iwVertexB->GetPoint( )*/ b );
							isSeam.Add( creaseEdges[ j ]->GetUserInt1( ) );
							creasePorcentages.Add( creaseEdges[ j ]->GetUserFloat1( ) );
							newCrease = false;
							// delete iwVertexC;
							break;
						} else {
							AC = iwPoint3dC /*iwVertexC->GetPoint( )*/ - iwPoint3dA /*iwVertexA->GetPoint( )*/;
							angleAB_AC = asin( ( AB * AC ).Length( ) / ( AB.Length( ) * AC.Length( ) ) );

							if ( std::fabs( angleAB_AC ) < RES_COMP ) {
								// newVertexB = iwVertexC;
								// distanceBC = iwVertexA->GetPoint( ).DistanceBetween( newVertexB->GetPoint( ) );
								distanceBC = iwPoint3dA.DistanceBetween( iwPoint3dB );
								if ( distanceBC < distance ) {
									distance = distanceBC;
									indexNewB = neighbor_verticesB[ i ][ k ];
								}
							}
						}
					}

					if ( newCrease && indexNewB != -1 ) {
						// Nuevo pliegue
						pairPoints.Add( vertB[ i ] );
						pairPoints.Add( indexNewB );
						isSeam.Add( creaseEdges[ j ]->GetUserInt1( ) );
						creasePorcentages.Add( creaseEdges[ j ]->GetUserFloat1( ) );
						indexNewB = -1;
						// delete iwVertexC;
					} else {
						newCrease = true;
					}
				}

				// delete iwVertexA;
			}
		}
	}

	fcs = GetPBrepFaces( OGLTransf );
	for ( i = 0; i < (int) fcs->GetSize( ); i++ )
		PBrep->DeletePolyFace( ( *fcs ).GetAt( i ) );

	for ( i = 0; i < finalnVertices; i++ ) {
		iwPoint3d.Set( finalVertices[ i * 3 ], finalVertices[ i * 3 + 1 ], finalVertices[ i * 3 + 2 ] );
		iwVertex = new IwPolyVertex( _GetSMLib( )->GetContext( ), PBrep ? *PBrep : *pBrep, iwPoint3d, RES_COMP );
		vertexsNew.Add( iwVertex );
	}

	cont = 0;
	for ( i = 0; i < finalnFaces; i++ ) {
		vertexFace.RemoveAll( );
		for ( j = 0; j < finalVertPerFace[ i ]; j++ ) {
			vertexFace.Add( vertexsNew[ finalFaces[ cont ] ] );
			cont++;
		}
		PBrep ? PBrep->CreatePolyFace( regions.GetAt( 0 ), shells.GetAt( 0 ), vertexFace, newFace ) : pBrep->CreatePolyFace( pRegion, pShell, vertexFace, newFace );
	}

	if ( PBrep ) {
		if ( updateTopology ) UpdateTopology( OGLTransf );
	} else {
		CopyPBrep( pBrep, true );
		UpdateOGLListFromPBrep( OGLTransf, RefEnt->GetOGLList( OGLTransf ), false, true, true, true );
		RefEnt->SetPolygonDirty( true );
		RefEnt->SetPBrepDirty( false );
		delete pBrep;
	}

	if ( preserveCreaseAndSeam ) {
		GetCreaseEdges( OGLTransf, &cE );
		// vtsPBrep = GetPBrepVertexs( OGLTransf );

		for ( int i = 0; i < (int) pairPoints.GetSize( ); i += 2 ) {
			vt = GetPBrepVertex( OGLTransf, pairPoints.GetAt( i ) );
			vt->GetStartingPolyEdges( rEdges );
			for ( j = 0; j < (int) rEdges.GetSize( ); j++ ) {
				if ( rEdges.GetAt( j )->GetEndVertex( ) == GetPBrepVertex( OGLTransf, pairPoints.GetAt( i + 1 ) ) ) {
					if ( isSeam.GetAt( i / 2 ) ) AddSeamEdge( rEdges.GetAt( j ) );
					if ( creasePorcentages.GetAt( i / 2 ) > 0 ) AddCreaseEdges( OGLTransf, rEdges.GetAt( j ), creasePorcentages.GetAt( i / 2 ), false, false );
					break;
				}
			}
		}
	}

	for ( i = 0; i < nMeshes; i++ ) {
		delete[] vertices[ i ];
		delete[] faces[ i ];
		delete[] indexPerFace[ i ];
		delete[] vertPerface[ i ];
	}
	delete[] vertices;
	delete[] faces;
	delete[] nVerticesPerMesh;
	delete[] nFacesPerMesh;
	delete[] indexPerFace;
	delete[] vertPerface;
	if ( pBrep ) delete pBrep;
	LibiglWrapper::free_double_function( finalVertices );
	LibiglWrapper::free_int_function( finalFaces );
	LibiglWrapper::free_int_function( finalVertPerFace );
	LibiglWrapper::free_int_function( origFaces );
	LibiglWrapper::free_int_function( vertA );
	LibiglWrapper::free_int_function( vertB );
	LibiglWrapper::free_array_int_function( neighbor_verticesA, nVertA );
	LibiglWrapper::free_array_int_function( neighbor_verticesB, nVertB );

	return true;
}

//------------------------------------------------------------------------------

IwPolyBrep *TPBrepData::GetPBrep( TOGLTransf *OGLTransf, bool force )
{
	if ( RefEnt && !RefEnt->GetPBrepDirty( ) && PBrep ) return PBrep;

	if ( force ) CreatePBrep( OGLTransf );

	return PBrep;
}

//------------------------------------------------------------------------------

void TPBrepData::UnSelectAll( TOGLTransf *OGLTransf )
{
	UnSelectAllFaces( OGLTransf );
	UnSelectAllEdges( OGLTransf );
	UnSelectAllVertexs( OGLTransf );

	AnyClosedRingSelected = 0;
	SetDirtyFaceSelection( false );
	SetDirtyEdgeSelection( false );
}

//------------------------------------------------------------------------------

void TPBrepData::ChangeSelectedElementsType( TOGLTransf *OGLTransf, int newMode )
{
	bool unSelect, found;
	int i, j, k, l, num, *selectedList, oppositevertex;
	ULONG index;
	IwPolyVertex *v;
	IwPolyFace *f;
	IwPolyEdge *e, *edge;
	IwTA<IwPolyFace *> faces;
	IwTA<IwPolyEdge *> edges;
	IwTA<IwPolyVertex *> vertexs;

	unSelect = false;

	// Vertices
	if ( IsAnyVertexSelected( OGLTransf ) ) {
		if ( newMode != MD_SELECTMESHEDGES && newMode != MD_OFFSET_RING_MESH && newMode != MD_SELECTMESHFACES && newMode != MD_EXTRUDE_MESH && newMode != MD_INSET_MESH && newMode != MD_BEVEL_MESH && newMode != MD_SOLIDIFY_MESH ) return;
		UnSelectAllFaces( OGLTransf );
		if ( newMode == MD_SELECTMESHEDGES || newMode == MD_OFFSET_RING_MESH ) {
			unSelect = true;
			selectedList = GetVertexs( OGLTransf, SelectedElementType::AllSelected, num );
			for ( i = 0; i < num; i++ ) {
				v = PBrepVertexs[ selectedList[ i ] ];
				if ( !v ) continue;
				v->GetPolyEdges( edges );
				for ( j = 0; j < (int) edges.GetSize( ); j++ ) {
					e = edges[ j ];
					if ( !e ) continue;
					if ( e->GetUserIndex1( ) == ULONG_MAX ) e = e->GetSymmetricPolyEdge( );
					if ( !e ) continue;
					if ( e->GetStartVertex( ) == v ) oppositevertex = e->GetEndVertex( )->GetIndexExt( );
					else
						oppositevertex = e->GetStartVertex( )->GetIndexExt( );
					for ( k = 0; k < num; k++ ) {
						if ( selectedList[ k ] == oppositevertex ) {
							SelectEdge( OGLTransf, e->GetUserIndex1( ) );
							break;
						}
					}
				}
			}
			if ( selectedList ) delete[] selectedList;
			if ( ToMesh( RefEnt ) && ToMesh( RefEnt )->IsPolygonalMesh( ) && IsAnyEdgeSelected( OGLTransf ) ) SetDirtyEdgeSelection( true );
		} else if ( newMode == MD_SELECTMESHFACES || newMode == MD_EXTRUDE_MESH || newMode == MD_INSET_MESH || newMode == MD_BEVEL_MESH || newMode == MD_SOLIDIFY_MESH /* || newMode == MD_KNIFE_CURVE_MESH*/ ) {
			// El modo newMode == MD_KNIFE_CURVE_MESH se quita pq cuando acaba la operacion queremos que se quede seleccionado el corte de aristas y no las caras
			unSelect = true;
			selectedList = GetVertexs( OGLTransf, SelectedElementType::AllSelected, num );
			for ( i = 0; i < num; i++ ) {
				v = PBrepVertexs[ selectedList[ i ] ];
				if ( !v ) continue;
				v->GetPolyFaces( faces );
				for ( j = 0; j < (int) faces.GetSize( ); j++ ) {
					f = faces[ j ];
					if ( !f ) continue;
					f->GetPolyVertices( vertexs );
					for ( k = 0; k < (int) vertexs.GetSize( ); k++ ) {
						oppositevertex = vertexs[ k ]->GetIndexExt( );
						found = false;
						for ( l = 0; l < num; l++ ) {
							if ( selectedList[ l ] == oppositevertex ) {
								found = true;
								break;
							}
						}
						if ( !found ) break;
					}
					if ( found ) SelectFace( OGLTransf, f->GetIndexExt( ) );
				}
			}
			if ( selectedList ) delete[] selectedList;
			if ( ToMesh( RefEnt ) && ToMesh( RefEnt )->IsPolygonalMesh( ) && IsAnyFaceSelected( OGLTransf ) ) SetDirtyFaceSelection( true );
		}
		if ( unSelect ) UnSelectAllVertexs( OGLTransf );
	}
	// Edges
	else if ( IsAnyEdgeSelected( OGLTransf ) ) {
		if ( newMode != MD_SELECTMESHVERTEXS && newMode != MD_SELECTMESHFACES && newMode != MD_EXTRUDE_MESH && newMode != MD_INSET_MESH && newMode != MD_BEVEL_MESH && newMode != MD_SOLIDIFY_MESH /*&& newMode*/ ) return;
		UnSelectAllFaces( OGLTransf );
		if ( newMode == MD_SELECTMESHVERTEXS ) {
			unSelect = true;
			selectedList = GetEdges( OGLTransf, SelectedElementType::AllSelected, num );
			for ( i = 0; i < num; i++ ) {
				e = PBrepEdges[ selectedList[ i ] ];
				if ( !e ) continue;
				v = e->GetStartVertex( );
				if ( !v ) continue;
				SelectVertex( OGLTransf, v->GetIndexExt( ) );
				v = e->GetEndVertex( );
				if ( !v ) continue;
				SelectVertex( OGLTransf, v->GetIndexExt( ) );
			}
			if ( selectedList ) delete[] selectedList;
		} else if ( newMode == MD_SELECTMESHFACES || newMode == MD_EXTRUDE_MESH || newMode == MD_INSET_MESH || newMode == MD_BEVEL_MESH || newMode == MD_SOLIDIFY_MESH /*|| newMode == MD_KNIFE_CURVE_MESH*/ ) {
			// El modo newMode == MD_KNIFE_CURVE_MESH se quita pq cuando acaba la operacion queremos que se quede seleccionado el corte de aristas y no las caras
			unSelect = true;
			selectedList = GetEdges( OGLTransf, SelectedElementType::AllSelected, num );
			for ( i = 0; i < num; i++ ) {
				e = PBrepEdges[ selectedList[ i ] ];
				if ( !e ) continue;
				f = e->GetPolyFace( );
				if ( !f ) continue;

				f->GetPolyEdges( edges );
				found = false;
				for ( j = 0; j < (int) edges.GetSize( ); j++ ) {
					found = false;
					if ( FindElement_Edge( &PBrepEdges, edges[ j ], index, edge ) ) {
						for ( k = 0; k < num; k++ ) {
							if ( selectedList[ k ] == (int) edge->GetUserIndex1( ) ) found = true;
						}
					}
					if ( !found ) break;
				}
				if ( found ) SelectFace( OGLTransf, f->GetIndexExt( ) );

				e = e->GetSymmetricPolyEdge( );
				if ( !e ) continue;
				f = e->GetPolyFace( );
				if ( !f ) continue;

				f->GetPolyEdges( edges );
				found = false;
				for ( j = 0; j < (int) edges.GetSize( ); j++ ) {
					found = false;
					if ( FindElement_Edge( &PBrepEdges, edges[ j ], index, edge ) ) {
						for ( k = 0; k < num; k++ ) {
							if ( selectedList[ k ] == (int) edge->GetUserIndex1( ) ) found = true;
						}
					}
					if ( !found ) break;
				}
				if ( found ) SelectFace( OGLTransf, f->GetIndexExt( ) );
			}
			if ( selectedList ) delete[] selectedList;
			if ( ToMesh( RefEnt ) && ToMesh( RefEnt )->IsPolygonalMesh( ) && IsAnyFaceSelected( OGLTransf ) ) SetDirtyFaceSelection( true );
		}
		if ( unSelect ) UnSelectAllEdges( OGLTransf );
		// Faces
	} else if ( IsAnyFaceSelected( OGLTransf ) ) {
		if ( newMode != MD_SELECTMESHVERTEXS && newMode != MD_SELECTMESHEDGES && newMode != MD_OFFSET_RING_MESH ) return;
		if ( newMode == MD_SELECTMESHVERTEXS ) {
			unSelect = true;
			selectedList = GetFaces( OGLTransf, SelectedElementType::AllSelected, num );
			for ( i = 0; i < num; i++ ) {
				f = PBrepFaces[ selectedList[ i ] ];
				if ( !f ) continue;
				f->GetPolyVertices( vertexs );
				for ( j = 0; j < (int) vertexs.GetSize( ); j++ ) {
					v = vertexs[ j ];
					if ( !v ) continue;
					SelectVertex( OGLTransf, v->GetIndexExt( ) );
				}
			}
			if ( selectedList ) delete[] selectedList;
		} else if ( newMode == MD_SELECTMESHEDGES || newMode == MD_OFFSET_RING_MESH ) {
			unSelect = true;
			selectedList = GetFaces( OGLTransf, SelectedElementType::AllSelected, num );
			for ( i = 0; i < num; i++ ) {
				f = PBrepFaces[ selectedList[ i ] ];
				if ( !f ) continue;
				f->GetPolyEdges( edges );
				for ( j = 0; j < (int) edges.GetSize( ); j++ ) {
					e = edges[ j ];
					if ( !e ) continue;
					if ( e->GetUserIndex1( ) == ULONG_MAX ) e = e->GetSymmetricPolyEdge( );
					if ( !e ) continue;
					SelectEdge( OGLTransf, e->GetUserIndex1( ) );
				}
			}
			if ( selectedList ) delete[] selectedList;
			if ( ToMesh( RefEnt ) && ToMesh( RefEnt )->IsPolygonalMesh( ) && IsAnyEdgeSelected( OGLTransf ) ) SetDirtyEdgeSelection( true );
		}
		if ( unSelect ) UnSelectAllFaces( OGLTransf );
	}
}

//------------------------------------------------------------------------------

int TPBrepData::CountPBrepFaces( TOGLTransf *OGLTransf )
{
	if ( !GetPBrep( OGLTransf ) ) return 0;

	return (int) PBrepFaces.GetSize( );
}

//------------------------------------------------------------------------------

IwTA<IwPolyFace *> *TPBrepData::GetPBrepFaces( TOGLTransf *OGLTransf )
{
	if ( !GetPBrep( OGLTransf ) ) return 0;

	return &PBrepFaces;
}

//------------------------------------------------------------------------------

IwPolyFace *TPBrepData::GetPBrepFace( TOGLTransf *OGLTransf, int ind )
{
	if ( !GetPBrep( OGLTransf ) ) return 0;

	if ( ind < 0 || ind >= (int) PBrepFaces.GetSize( ) ) return 0;

	return PBrepFaces[ ind ];
}

//------------------------------------------------------------------------------

int TPBrepData::CountPBrepEdges( TOGLTransf *OGLTransf )
{
	if ( !GetPBrep( OGLTransf ) ) return 0;

	return (int) PBrepEdges.GetSize( );
}

//------------------------------------------------------------------------------

IwTA<IwPolyEdge *> *TPBrepData::GetPBrepEdges( TOGLTransf *OGLTransf )
{
	if ( !GetPBrep( OGLTransf ) ) return 0;

	return &PBrepEdges;
}

//------------------------------------------------------------------------------

IwPolyEdge *TPBrepData::GetPBrepEdge( TOGLTransf *OGLTransf, int ind )
{
	if ( !GetPBrep( OGLTransf ) ) return 0;

	if ( ind < 0 || ind >= (int) PBrepEdges.GetSize( ) ) return 0;

	return PBrepEdges[ ind ];
}

//------------------------------------------------------------------------------

int TPBrepData::CountPBrepVertexs( TOGLTransf *OGLTransf )
{
	if ( !GetPBrep( OGLTransf ) ) return 0;

	return (int) PBrepVertexs.GetSize( );
}

//------------------------------------------------------------------------------

IwTA<IwPolyVertex *> *TPBrepData::GetPBrepVertexs( TOGLTransf *OGLTransf )
{
	if ( !GetPBrep( OGLTransf ) ) return 0;

	return &PBrepVertexs;
}

//------------------------------------------------------------------------------

IwPolyVertex *TPBrepData::GetPBrepVertex( TOGLTransf *OGLTransf, int ind )
{
	if ( !GetPBrep( OGLTransf ) ) return 0;

	if ( ind < 0 || ind >= (int) PBrepVertexs.GetSize( ) ) return 0;

	return PBrepVertexs[ ind ];
}

//------------------------------------------------------------------------------

T3DVector TPBrepData::GetNormalPBrepVertex( TOGLTransf *OGLTransf, int index )
{
	if ( !GetPBrep( OGLTransf ) ) return T3DVector( T3DPoint( 0, 0, 0 ), T3DPoint( 0, 0, 0 ) );
	if ( index < 0 || index >= (int) PBrepVertexs.GetSize( ) ) return T3DVector( T3DPoint( 0, 0, 0 ), T3DPoint( 0, 0, 0 ) );

	return GetNormalPBrepVertex( OGLTransf, PBrepVertexs[ index ] );
}

//------------------------------------------------------------------------------

T3DVector TPBrepData::GetNormalPBrepVertex( TOGLTransf *OGLTransf, IwPolyVertex *vertex, IwTA<IwPolyFace *> *facesGroup )
{
	ULONG ulIndex;
	int i, numFaces;
	T3DVector vectN, vectT;
	IwVector3d normal3D;
	IwTA<IwPolyFace *> faces;

	if ( !GetPBrep( OGLTransf ) ) return T3DVector( T3DPoint( 0, 0, 0 ), T3DPoint( 0, 0, 0 ) );
	if ( !vertex ) return T3DVector( T3DPoint( 0, 0, 0 ), T3DPoint( 0, 0, 0 ) );

	vertex->GetPolyFaces( faces );
	// facesGroup se usa para tener en cuenta solo las caras que se pasan como parametro para calcular las normales: default = null
	if ( facesGroup ) {
		for ( i = (int) faces.GetSize( ) - 1; i >= 0; i-- ) {
			if ( !( *facesGroup ).FindElement( faces[ i ], ulIndex ) ) faces.RemoveAt( i );
		}
	}
	if ( faces.GetSize( ) == 0 ) return T3DVector( T3DPoint( 0, 0, 0 ), T3DPoint( 0, 0, 0 ) );

	numFaces = (int) faces.GetSize( );
	vectT.org = T3DPoint( 0, 0, 0 );
	normal3D = faces[ 0 ]->GetNormal( true );

	vectT.size.cx = normal3D.x;
	vectT.size.cy = normal3D.y;
	vectT.size.cz = normal3D.z;

	for ( i = 1; i < numFaces; i++ ) {
		vectN.org = T3DPoint( 0, 0, 0 );
		normal3D = faces[ i ]->GetNormal( true );

		vectN.size.cx = normal3D.x;
		vectN.size.cy = normal3D.y;
		vectN.size.cz = normal3D.z;
		vectT = vectN + vectT;
	}
	vectT.Unitario( );

	return vectT;
}

T3DVector TPBrepData::GetNormalPBrepVertexFromEdges( TOGLTransf *OGLTransf, IwPolyVertex *vertex )
{
	int i, numedges;
	T3DPoint pt1, pt2;
	T3DVector vectN, vect;
	IwPolyVertex *v1, *v2;
	IwTA<IwPolyEdge *> edges;

	if ( !GetPBrep( OGLTransf ) ) return T3DVector( T3DPoint( 0, 0, 0 ), T3DPoint( 0, 0, 0 ) );
	if ( !vertex ) return T3DVector( T3DPoint( 0, 0, 0 ), T3DPoint( 0, 0, 0 ) );

	vertex->GetPolyEdges( edges );
	if ( edges.GetSize( ) == 0 ) return T3DVector( T3DPoint( 0, 0, 0 ), T3DPoint( 0, 0, 0 ) );

	numedges = (int) edges.GetSize( );
	for ( i = 0; i < numedges; i++ ) {
		if ( edges[ i ]->GetUserIndex1( ) == ULONG_MAX ) continue;
		if ( edges[ i ]->GetEndVertex( ) == vertex ) {
			v1 = edges[ i ]->GetEndVertex( );
			v2 = edges[ i ]->GetStartVertex( );
		} else {
			v1 = edges[ i ]->GetStartVertex( );
			v2 = edges[ i ]->GetEndVertex( );
		}

		pt1 = T3DPoint( v1->GetPointPtr( )->x, v1->GetPointPtr( )->y, v1->GetPointPtr( )->z );
		pt2 = T3DPoint( v2->GetPointPtr( )->x, v2->GetPointPtr( )->y, v2->GetPointPtr( )->z );
		vect = pt1 - pt2;
		vect.org = pt1;
		vect.Unitario( );
		vectN = vectN + vect;
	}

	vectN.Unitario( );
	return vectN;
}

//------------------------------------------------------------------------------

// Devuelve normal de un vertice de borde para extrusionar sus aristas "bordes" seleccionadas.
// Type 0: Direccion de la media de aristas que no forman parte del borde (Si es un extremo del camino solo se tiene en cuenta la arista de la cara)
// Type 1: Eje de coordenadas
// Type 2: Direccional
// Type 3: Por proyeccion
bool TPBrepData::GetNormalVertexToExtrudeEdge( TOGLTransf *OGLTransf, TExtrudeEdgeType type, IwPolyVertex *vertex, T3DVector *norm, TNPlane plane, bool forcecalc )
{
	bool cwise;
	ULONG index;
	int *selectedList, num, i;
	T3DPoint p1, p2;
	IwPoint3d sPnt;
	IwVector3d pt, sNormal( 1, 1, 1 ), sVec1, sVec2;
	IwTArray<IwPolyVertex *> vertexadj, vertexadjbound;
	IwPolyEdge *edge, *iniedge, *endedge, *edgetocalnormal;
	IwTA<IwPolyEdge *> edgesfromvertex, edgesaux, edgesface, edgesforcalc;
	IwTA<IwTA<IwPolyEdge *> > edgesordered;
	IwPolyFace *face;

	if ( !norm || !vertex ) return false;

	if ( !forcecalc && vertex && MoveVertUser.VerticesOrg.FindElement( vertex, index ) ) {
		( *norm ).org = T3DPoint( MoveVertUser.VerticesOrg[ index ]->GetPointPtr( )->x, MoveVertUser.VerticesOrg[ index ]->GetPointPtr( )->y, MoveVertUser.VerticesOrg[ index ]->GetPointPtr( )->z );
		( *norm ).size = T3DSize( MoveVertUser.Directions[ index ].x, MoveVertUser.Directions[ index ].y, MoveVertUser.Directions[ index ].z );
		return true;
	}

	( *norm ) = T3DVector( T3DPoint( 0, 0, 0 ), T3DPoint( 0, 0, 0 ) );

	if ( forcecalc ) {
		MoveVertUser.Clear( );
	}

	if ( type == TExtrudeEdgeType::ByAxis ) {
		if ( plane == plXY ) ( *norm ) = T3DVector( T3DPoint( 0, 0, 0 ), T3DPoint( 0, 0, 1 ) );
		else if ( plane == plXZ )
			( *norm ) = T3DVector( T3DPoint( 0, 0, 0 ), T3DPoint( 0, 1, 0 ) );
		else if ( plane == plYZ )
			( *norm ) = T3DVector( T3DPoint( 0, 0, 0 ), T3DPoint( 1, 0, 0 ) );
		else
			return false;
		( *norm ).org = T3DPoint( vertex->GetPointPtr( )->x, vertex->GetPointPtr( )->y, vertex->GetPointPtr( )->z );
		return true;
	}

	if ( type == TExtrudeEdgeType::ByNormalVertex ) {
		( *norm ) = GetNormalPBrepVertex( 0, vertex );
		( *norm ).org = T3DPoint( vertex->GetPointPtr( )->x, vertex->GetPointPtr( )->y, vertex->GetPointPtr( )->z );
		return true;
	}

	if ( vertex && !vertex->IsBoundaryVertex( ) ) return false;

	// Obtenemos la lista de seleccion de aristas porque si es un extremo solo influirá la arista correspondiente para su normal
	// Obtenemos la lista de aristas seleccionadas
	selectedList = GetEdges( OGLTransf, SelectedElementType::AllSelected, num );
	if ( num == 0 ) return false;

	for ( i = 0; i < num; i++ ) {
		edge = GetPBrepEdge( OGLTransf, selectedList[ i ] );
		if ( !edge ) continue;
		if ( !edge->IsBoundary( ) ) continue;
		edgesaux.Add( edge );
	}
	if ( selectedList ) delete[] selectedList;

	num = 0;
	vertex->GetAdjacentVertices( vertexadj );
	vertex->GetAdjacentBoundaryVertices( vertexadjbound );
	for ( i = 0; i < (int) vertexadjbound.GetSize( ); i++ ) {
		if ( vertex->FindPolyEdgeBetween( vertexadjbound[ i ], edge ) != IW_SUCCESS ) continue;
		if ( !edge ) continue;
		if ( FindElement_Edge( &edgesaux, edge, index, edge ) ) {
			num++;
			edgesfromvertex.Add( edge );
		}
	}

	if ( num == 0 ) return false;

	if ( num == 1 ) {
		edgetocalnormal = GetNextCWPolyEdge( vertex, edgesfromvertex[ 0 ] );
		if ( !edgetocalnormal ) {
			edgetocalnormal = GetNextCCWPolyEdge( vertex, edgesfromvertex[ 0 ] );
			if ( !edgetocalnormal ) return false;
		}
		if ( type == TExtrudeEdgeType::ByNormalVertex ) {
			face = edgesfromvertex[ 0 ]->GetPolyFace( );
			face->GetPolyEdges( edgesface );
			if ( !edgesface.FindElement( edgetocalnormal, index ) ) {
				edgetocalnormal = edgetocalnormal->GetSymmetricPolyEdge( );
				if ( !edgetocalnormal || !edgesface.FindElement( edgetocalnormal, index ) ) return false;
			}
			sPnt = edgetocalnormal->GetStartPoint( );
			sVec1 = edgetocalnormal->GetEndPoint( ) - sPnt;
			sVec2 = edgesface[ index < edgesface.GetSize( ) - 1 ? index + 1 : 0 ]->GetEndPoint( ) - sPnt;
			sNormal = sVec1 * sVec2;
			( *norm ).org = T3DPoint( sPnt.x, sPnt.y, sPnt.z );
			( *norm ).size.cx = sNormal.x;
			( *norm ).size.cy = sNormal.y;
			( *norm ).size.cz = sNormal.z;
		} else {
			p1 = T3DPoint( edgetocalnormal->GetStartVertex( )->GetPointPtr( )->x, edgetocalnormal->GetStartVertex( )->GetPointPtr( )->y, edgetocalnormal->GetStartVertex( )->GetPointPtr( )->z );
			p2 = T3DPoint( edgetocalnormal->GetEndVertex( )->GetPointPtr( )->x, edgetocalnormal->GetEndVertex( )->GetPointPtr( )->y, edgetocalnormal->GetEndVertex( )->GetPointPtr( )->z );
			if ( edgetocalnormal->GetPolyFace( ) != edgesfromvertex[ 0 ]->GetPolyFace( ) && edgetocalnormal->GetSymmetricPolyEdge( ) && edgetocalnormal->GetSymmetricPolyEdge( )->GetPolyFace( ) != edgesfromvertex[ 0 ]->GetPolyFace( ) ) return false;
			if ( edgetocalnormal->GetStartVertex( ) == vertex ) ( *norm ) = T3DVector( p2, p1 );
			else
				( *norm ) = T3DVector( p1, p2 );
		}
		( *norm ).Unitario( );

	} else {
		if ( vertex->IsBoundaryVertex( ) && edgesfromvertex.GetSize( ) == 2 && vertexadjbound.GetSize( ) == vertexadj.GetSize( ) && vertexadj.GetSize( ) == 2 ) {
			iniedge = edgesfromvertex[ 0 ];
			endedge = edgesfromvertex[ 1 ];
			edgesforcalc.Add( edgesfromvertex[ 0 ] );
			edgesforcalc.Add( edgesfromvertex[ 1 ] );
		} else {
			edgetocalnormal = GetNextCWPolyEdge( vertex, edgesfromvertex[ 0 ] );
			cwise = true;
			if ( !edgetocalnormal ) {
				edgetocalnormal = GetNextCCWPolyEdge( vertex, edgesfromvertex[ 0 ] );
				if ( !edgetocalnormal ) return false;
				cwise = false;
			}
			edgesforcalc.Add( edgetocalnormal );
			endedge = edgesfromvertex[ 1 ];
			while ( edgetocalnormal && edgetocalnormal != endedge && edgetocalnormal != iniedge ) {
				if ( cwise ) edgetocalnormal = vertex->GetCWPolyEdge( edgetocalnormal );
				else
					edgetocalnormal = vertex->GetCCWPolyEdge( edgetocalnormal );
				if ( edgesforcalc.FindElement( edgetocalnormal, index ) ) break;
				if ( edgetocalnormal && edgetocalnormal != endedge && edgetocalnormal != iniedge ) edgesforcalc.Add( edgetocalnormal );
			}
		}
		num = 0;
		for ( i = 0; i < (int) edgesforcalc.GetSize( ); i++ ) {
			edgetocalnormal = edgesforcalc[ i ];
			if ( type == TExtrudeEdgeType::ByNormalVertex ) {
				// Para cada arista cogemos la otra arista que comparte con el vertice para calcular la normal
				if ( i == 0 ) edge = iniedge;
				else {
					face = edgetocalnormal->GetPolyFace( );
					face->GetPolyEdges( edgesface );
					if ( edgesface.FindElement( edgetocalnormal, index ) != IW_SUCCESS ) continue;
					if ( edgetocalnormal->GetStartVertex( ) == vertex ) edge = edgesface[ index > 0 ? index - 1 : edgesface.GetSize( ) - 1 ];
					else
						edge = edgesface[ index < edgesface.GetSize( ) - 1 ? index + 1 : 0 ];
				}
				sPnt = edgetocalnormal->GetStartPoint( );
				sVec1 = edgetocalnormal->GetEndPoint( ) - sPnt;
				sVec2 = edge->GetEndVertex( ) == edgetocalnormal->GetStartVertex( ) ? edge->GetStartPoint( ) - sPnt : edge->GetEndPoint( ) - sPnt;
				sNormal = sVec1 * sVec2;
				if ( edge->GetEndVertex( ) == edgetocalnormal->GetStartVertex( ) ) {
					sVec2 = edge->GetStartPoint( ) - sPnt;
					sNormal = sVec1 * sVec2;
				} else {
					sVec2 = edge->GetEndPoint( ) - sPnt;
					sNormal = sVec2 * sVec1;
				}
				( *norm ) = ( *norm ) + T3DVector( T3DSize( sNormal.x, sNormal.y, sNormal.z ) ).Unitario( );
				if ( i == (int) edgesforcalc.GetSize( ) - 1 ) {
					edge = endedge;
					sPnt = edgetocalnormal->GetStartPoint( );
					sVec1 = edgetocalnormal->GetEndPoint( ) - sPnt;
					if ( edge->GetEndVertex( ) == edgetocalnormal->GetStartVertex( ) ) {
						sVec2 = edge->GetStartPoint( ) - sPnt;
						sNormal = sVec1 * sVec2;
					} else {
						sVec2 = edge->GetEndPoint( ) - sPnt;
						sNormal = sVec2 * sVec1;
					}

					( *norm ) = ( *norm ) + T3DVector( T3DSize( sNormal.x, sNormal.y, sNormal.z ) ).Unitario( );
					num++;
				}
			} else {
				p1 = T3DPoint( edgetocalnormal->GetStartVertex( )->GetPointPtr( )->x, edgetocalnormal->GetStartVertex( )->GetPointPtr( )->y, edgetocalnormal->GetStartVertex( )->GetPointPtr( )->z );
				p2 = T3DPoint( edgetocalnormal->GetEndVertex( )->GetPointPtr( )->x, edgetocalnormal->GetEndVertex( )->GetPointPtr( )->y, edgetocalnormal->GetEndVertex( )->GetPointPtr( )->z );
				if ( edgetocalnormal->GetStartVertex( ) == vertex ) ( *norm ) = ( *norm ) + T3DVector( p2, p1 ).Unitario( );
				else
					( *norm ) = ( *norm ) + T3DVector( p1, p2 ).Unitario( );
			}
			num++;
			( *norm ).Unitario( );
		}
		( *norm ).size.cx = ( *norm ).size.cx / num;
		( *norm ).size.cy = ( *norm ).size.cy / num;
		( *norm ).size.cz = ( *norm ).size.cz / num;
		( *norm ).Unitario( );
	}
	( *norm ).org = T3DPoint( vertex->GetPointPtr( )->x, vertex->GetPointPtr( )->y, vertex->GetPointPtr( )->z );

	return true;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

bool TPBrepData::IsFaceSelected( TOGLTransf *OGLTransf, int index, SelectedElementType selType )
{
	if ( !GetPBrep( OGLTransf ) ) return false;
	if ( index < 0 || index >= (int) PBrepFaces.GetSize( ) ) return false;

	if ( selType > SelectedElementType::NoSelected ) return ( SelectedF[ index ].i == (int) selType );

	return ( SelectedF[ index ].i != (int) selType );
}

//------------------------------------------------------------------------------

bool TPBrepData::IsEdgeSelected( TOGLTransf *OGLTransf, int index, SelectedElementType selType )
{
	if ( !GetPBrep( OGLTransf ) ) return false;
	if ( index < 0 || index >= (int) PBrepEdges.GetSize( ) ) return false;

	if ( (int) selType == (int) SelectedElementType::AllSelected ) return ( SelectedE[ index ] >= (int) SelectedElementType::UserSelection && SelectedE[ index ] <= (int) SelectedElementType::AllSelected );
	if ( (int) selType > (int) SelectedElementType::NoSelected ) return ( SelectedE[ index ] == (int) selType );

	return ( SelectedE[ index ] != (int) selType );
}

//------------------------------------------------------------------------------

bool TPBrepData::IsVertexSelected( TOGLTransf *OGLTransf, int index, SelectedElementType selType )
{
	if ( !GetPBrep( OGLTransf ) ) return false;
	if ( index < 0 || index >= (int) PBrepVertexs.GetSize( ) ) return false;

	if ( selType > SelectedElementType::NoSelected ) return ( SelectedV[ index ].i == (int) selType );

	return ( SelectedV[ index ].i != (int) selType );
}

//------------------------------------------------------------------------------

int TPBrepData::GetFaceSelectedType( int index )
{
	if ( index < 0 || index >= (int) PBrepFaces.GetSize( ) ) return 0;

	return SelectedF[ index ].i;
}

//------------------------------------------------------------------------------

int TPBrepData::GetEdgeSelectedType( int index )
{
	if ( index < 0 || index >= (int) PBrepEdges.GetSize( ) ) return 0;

	return SelectedE[ index ];
}

//------------------------------------------------------------------------------

void TPBrepData::GetBoundaryEdgesOrVertexs( TInteger_List *borderIndexs, ElementType eType )
{
	int i, nEdges, nVertexs;
	int borderIndex;

	IwTA<IwPolyEdge *> edgesBorder;
	IwTA<IwPolyVertex *> vertexsBorder;
	if ( !borderIndexs || !PBrep ) return;

	if ( eType == ElementType::Edge ) {
		PBrep->GetBoundaryEdges( edgesBorder );
		nEdges = (int) edgesBorder.GetSize( );
		for ( i = 0; i < nEdges; i++ ) {
			borderIndex = edgesBorder[ i ]->GetUserIndex1( );
			borderIndexs->AddItem( &borderIndex );
		}
	} else if ( eType == ElementType::Vertex ) {
		PBrep->GetBoundaryVertices( vertexsBorder );
		nVertexs = (int) vertexsBorder.GetSize( );
		for ( i = 0; i < nVertexs; i++ ) {
			borderIndex = vertexsBorder[ i ]->GetIndexExt( );
			borderIndexs->AddItem( &borderIndex );
		}
	}
}

//------------------------------------------------------------------------------
int TPBrepData::GetVertexSelectedType( int index )
{
	if ( index < 0 || index >= (int) PBrepVertexs.GetSize( ) ) return 0;

	return SelectedV[ index ].i;
}

//---------------------------------------------------------------------------

bool TPBrepData::FillSelection( TOGLTransf *OGLTransf, int faceInd, int mode, bool delFromSelect, bool useSeams )
{
	int i, j, count, *facesList, iNumFaces, *edgesList, iNumEdges;
	ULONG ulIndex;
	IwPolyEdge *edge, *edgeAux;
	IwPolyFace *face, *faceref;
	IwTA<IwPolyEdge *> edges, edgesface, edgesfill;
	IwTA<IwPolyFace *> faces, facesfill;

	if ( !GetPBrep( OGLTransf ) || faceInd < 0 || mode < 1 ) return false;

	// SELECCIONAR CARAS
	if ( mode == MD_SELECTMESHFACES && !delFromSelect ) {
		faceref = GetPBrepFace( OGLTransf, faceInd );
		if ( !faceref ) return false;
		facesList = GetFaces( OGLTransf, SelectedElementType::AllSelected, iNumFaces );

		if ( iNumFaces ) {
			for ( i = 0; i < iNumFaces; i++ ) {
				face = GetPBrepFace( OGLTransf, facesList[ i ] );
				if ( face ) faces.Add( face );
			}
			delete[] facesList;
			if ( faces.FindElement( faceref, ulIndex ) ) return false;

			facesfill = GetFacesInsideSelection( OGLTransf, faceref, &faces, useSeams );
			if ( facesfill.GetSize( ) > 0 )
				for ( i = 0; i < (int) facesfill.GetSize( ); i++ )
					SelectFace( OGLTransf, facesfill[ i ]->GetIndexExt( ) );
			else
				SelectFace( OGLTransf, faceInd );
		} else {
			facesfill = GetFacesInsideNoSelection( faceref, ElementType::Face, useSeams );
			for ( i = 0; i < (int) facesfill.GetSize( ); i++ )
				SelectFace( OGLTransf, facesfill[ i ]->GetIndexExt( ) );
		}
	} else if ( mode == MD_SELECTMESHFACES && IsAnyFaceSelected( OGLTransf ) && delFromSelect ) { // DESELECCIONAR CARAS.
		faceref = GetPBrepFace( OGLTransf, faceInd );
		if ( !faceref ) return false;
		facesList = GetFaces( OGLTransf, SelectedElementType::NoSelected, iNumFaces );

		if ( iNumFaces ) {
			for ( i = 0; i < iNumFaces; i++ ) {
				face = GetPBrepFace( OGLTransf, facesList[ i ] );
				if ( face ) faces.Add( face );
			}
			delete[] facesList;
			if ( faces.FindElement( faceref, ulIndex ) ) return false;

			facesfill = GetFacesInsideSelection( OGLTransf, faceref, &faces, useSeams );
			if ( facesfill.GetSize( ) > 0 )
				for ( i = 0; i < (int) facesfill.GetSize( ); i++ )
					UnSelectFace( OGLTransf, facesfill[ i ]->GetIndexExt( ), 0.0f, false, false, true );
			else
				UnSelectFace( OGLTransf, faceInd, 0.0f, false, false, true );
		} else {
			facesfill = GetFacesInsideNoSelection( faceref, ElementType::Face, useSeams );
			for ( i = 0; i < (int) facesfill.GetSize( ); i++ )
				UnSelectFace( OGLTransf, facesfill[ i ]->GetIndexExt( ), 0.0f, false, false, true );
		}

	} else if ( mode == MD_SELECTMESHEDGES && !delFromSelect ) { // SELECCIONAR ARISTAS
		edgesList = GetEdges( OGLTransf, SelectedElementType::AllSelected, iNumEdges );

		if ( iNumEdges ) {
			for ( i = 0; i < iNumEdges; i++ ) {
				edge = GetPBrepEdge( OGLTransf, edgesList[ i ] );
				if ( edge ) edges.Add( edge );
			}
			delete[] edgesList;
			faces = GetFacesInsideSelection( OGLTransf, GetPBrepFace( OGLTransf, faceInd ), &edges );

			for ( i = 0; i < (int) faces.GetSize( ); i++ ) {
				faces[ i ]->GetPolyEdges( edgesface );
				for ( j = 0; j < (int) edgesface.GetSize( ); j++ )
					if ( FindElement_Edge( &PBrepEdges, edgesface[ j ], ulIndex, edge ) ) edgesfill.AddUnique( edge );
			}
			for ( i = 0; i < (int) edgesfill.GetSize( ); i++ )
				if ( !IsEdgeSelected( OGLTransf, edgesfill[ i ]->GetUserIndex1( ) ) ) SelectEdge( OGLTransf, edgesfill[ i ]->GetUserIndex1( ) );

		} else {
			faces = GetFacesInsideNoSelection( GetPBrepFace( OGLTransf, faceInd ), ElementType::Edge, useSeams );
			for ( i = 0; i < (int) faces.GetSize( ); i++ ) {
				faces[ i ]->GetPolyEdges( edgesface );
				for ( j = 0; j < (int) edgesface.GetSize( ); j++ ) {
					if ( edgesface[ j ]->GetUserIndex1( ) == ULONG_MAX ) edgesface[ j ] = edgesface[ j ]->GetSymmetricPolyEdge( );
					if ( edgesface[ j ] ) SelectEdge( OGLTransf, edgesface[ j ]->GetUserIndex1( ) );
				}
			}
		}
	} else if ( mode == MD_SELECTMESHEDGES && IsAnyEdgeSelected( OGLTransf ) && delFromSelect ) { // DESELECCIONAR ARISTAS
		faceref = GetPBrepFace( OGLTransf, faceInd );
		faceref->GetPolyEdges( edgesface );
		count = 0;
		for ( j = 0; j < (int) edgesface.GetSize( ); j++ ) {
			edgeAux = edgesface[ j ]->GetSymmetricPolyEdge( );
			if ( !edgeAux ) {
				if ( IsEdgeSelected( OGLTransf, edgesface[ j ]->GetUserIndex1( ) ) ) count++;
				continue;
			}
			if ( ( IsEdgeSelected( OGLTransf, edgesface[ j ]->GetUserIndex1( ) ) ) || ( IsEdgeSelected( OGLTransf, edgesface[ j ]->GetSymmetricPolyEdge( )->GetUserIndex1( ) ) ) ) count++;
		}
		if ( ( count != (int) edgesface.GetSize( ) ) ) return false;

		edgesList = GetEdges( OGLTransf, SelectedElementType::NoSelected, iNumEdges );
		if ( iNumEdges ) {
			for ( i = 0; i < iNumEdges; i++ ) {
				edge = GetPBrepEdge( OGLTransf, edgesList[ i ] );
				if ( edge ) edges.Add( edge );
			}
			delete[] edgesList;

			faces = GetFacesInsideSelection( OGLTransf, GetPBrepFace( OGLTransf, faceInd ), &edges, true, useSeams );
			if ( faces.GetSize( ) > 0 && count >= 3 ) {
				for ( i = 0; i < (int) faces.GetSize( ); i++ ) {
					faces[ i ]->GetPolyEdges( edgesface );
					for ( j = 0; j < (int) edgesface.GetSize( ); j++ ) {
						if ( FindElement_Edge( &PBrepEdges, edgesface[ j ], ulIndex, edge ) ) edgesfill.AddUnique( edge );
					}
				}
				for ( i = 0; i < (int) edgesfill.GetSize( ); i++ )
					UnSelectEdge( OGLTransf, edgesfill[ i ]->GetUserIndex1( ) );
			}

		} else {
			faces = GetFacesInsideNoSelection( GetPBrepFace( OGLTransf, faceInd ), ElementType::Edge, useSeams );
			for ( i = 0; i < (int) faces.GetSize( ); i++ ) {
				faces[ i ]->GetPolyEdges( edgesface );
				for ( j = 0; j < (int) edgesface.GetSize( ); j++ ) {
					if ( edgesface[ j ]->GetUserIndex1( ) == ULONG_MAX ) edgesface[ j ] = edgesface[ j ]->GetSymmetricPolyEdge( );
					if ( edgesface[ j ] ) UnSelectEdge( OGLTransf, edgesface[ j ]->GetUserIndex1( ) );
				}
			}
		}
	}

	if ( RefEnt ) {
		RefEnt->Download( );
		if ( ToMesh( RefEnt ) && ToMesh( RefEnt )->HasSubdivisionDepMesh( ) ) ToMesh( RefEnt )->GetDepMeshes( )->GetShape( 0 )->Download( );
	}

	return true;
}
//---------------------------------------------------------------------------

bool TPBrepData::InvertSelection( TOGLTransf *OGLTransf, ElementType eType )
{
	bool ret;
	int i, numElements;
	TInteger_List indexes;

	if ( !GetPBrep( OGLTransf ) ) return false;

	ret = false;

	if ( eType == ElementType::Face || ( eType == ElementType::Undefined && IsAnyFaceSelected( OGLTransf ) ) ) {
		ret = true;
		numElements = (int) PBrepFaces.GetSize( );
		indexes.Clear( );
		for ( i = 0; i < numElements; i++ )
			if ( !IsFaceSelected( OGLTransf, i ) ) indexes.AddItem( &i );
		UnSelectAllFaces( OGLTransf );
		if ( indexes.Count( ) > 0 ) SelectFaces( OGLTransf, &indexes );
		if ( RefEnt ) {
			RefEnt->Download( );
			if ( ToMesh( RefEnt ) && ToMesh( RefEnt )->HasSubdivisionDepMesh( ) ) ToMesh( RefEnt )->GetDepMeshes( )->GetShape( 0 )->Download( );
		}
		SetDirtyFaceSelection( true );
	}

	if ( eType == ElementType::Edge || ( eType == ElementType::Undefined && IsAnyEdgeSelected( OGLTransf ) ) ) {
		ret = true;
		numElements = (int) PBrepEdges.GetSize( );
		indexes.Clear( );
		for ( i = 0; i < numElements; i++ )
			if ( !IsEdgeSelected( OGLTransf, i ) ) indexes.AddItem( &i );
		UnSelectAllEdges( OGLTransf );
		if ( indexes.Count( ) > 0 ) SelectEdges( OGLTransf, &indexes );
		SetDirtyEdgeSelection( true );
	}

	if ( eType == ElementType::Vertex || ( eType == ElementType::Undefined && IsAnyVertexSelected( OGLTransf ) ) ) {
		ret = true;
		numElements = (int) PBrepVertexs.GetSize( );
		indexes.Clear( );
		for ( i = 0; i < numElements; i++ )
			if ( !IsVertexSelected( OGLTransf, i ) ) indexes.AddItem( &i );
		UnSelectAllVertexs( OGLTransf );
		if ( indexes.Count( ) > 0 ) SelectVertexs( OGLTransf, &indexes );
	}

	return ret;
}

//------------------------------------------------------------------------------

bool TPBrepData::GetSelectionCentroid( TOGLTransf *OGLTransf, T3DPoint *pos, T3DVector *normal, bool centroidFromSubdivision )
{
	int i, j, count, nFaces, nVertices, nEdges;
	T3DPoint aux, centroid;
	IwVector3d iwpt, iwpt2;
	TOGLPoint *oglpt;
	IwPolyEdge *edge;
	IwPolyVertex *vertex;
	IwTA<IwPolyVertex *> auxVertices;
	IwVector3d normal3D;
	T3DVector normalAux;

	count = 0;

	if ( normal ) ( *normal ).size = T3DSize( 0, 0, 0 );

	if ( IsAnyFaceSelected( OGLTransf ) ) {
		nFaces = CountPBrepFaces( OGLTransf );
		for ( i = 0; i < nFaces; i++ ) {
			if ( IsFaceSelected( OGLTransf, i ) ) {
				if ( centroidFromSubdivision ) {
					aux += GetSubdivisionCentroidFromFace( OGLTransf, GetPBrepFace( OGLTransf, i ), normal ? &normalAux : 0 );
					if ( normal ) ( *normal ) = ( *normal ) + normalAux;
				} else {
					GetPBrepFace( OGLTransf, i )->GetPolyVertices( auxVertices );
					nVertices = (int) auxVertices.GetSize( );
					for ( j = 0; j < nVertices; j++ ) {
						centroid.x += auxVertices[ j ]->GetPoint( ).x;
						centroid.y += auxVertices[ j ]->GetPoint( ).y;
						centroid.z += auxVertices[ j ]->GetPoint( ).z;
					}
					centroid /= nVertices;
					aux += centroid;
					centroid = T3DPoint( 0, 0, 0 );
					if ( normal ) {
						normal3D = GetPBrepFace( OGLTransf, i )->GetNormal( true );
						( *normal ).size.cx += normal3D.x;
						( *normal ).size.cy += normal3D.y;
						( *normal ).size.cz += normal3D.z;
					}
				}
				count++;
			}
		}
	} else if ( IsAnyEdgeSelected( OGLTransf ) ) {
		nEdges = CountPBrepEdges( OGLTransf );
		for ( i = 0; i < nEdges; i++ ) {
			if ( IsEdgeSelected( OGLTransf, i ) ) {
				edge = GetPBrepEdge( OGLTransf, i );
				if ( centroidFromSubdivision ) {
					aux += GetSubdivisionCentroidFromEdge( OGLTransf, edge, &normalAux );
					if ( normal ) ( *normal ) = ( *normal ) + normalAux;
				} else {
					iwpt = edge->GetStartPoint( );
					iwpt2 = edge->GetEndPoint( );
					aux.x += ( iwpt.x + iwpt2.x ) / 2.0;
					aux.y += ( iwpt.y + iwpt2.y ) / 2.0;
					aux.z += ( iwpt.z + iwpt2.z ) / 2.0;
					if ( normal ) {
						normalAux = GetNormalPBrepVertex( OGLTransf, edge->GetStartVertex( )->GetIndexExt( ) );
						( *normal ) = ( *normal ) + normalAux;
						normalAux = GetNormalPBrepVertex( OGLTransf, edge->GetEndVertex( )->GetIndexExt( ) );
						( *normal ) = ( *normal ) + normalAux;
					}
				}
				count++;
			}
		}
	} else if ( IsAnyVertexSelected( OGLTransf ) ) {
		nVertices = CountPBrepVertexs( OGLTransf );
		for ( i = 0; i < nVertices; i++ ) {
			if ( IsVertexSelected( OGLTransf, i ) ) {
				vertex = GetPBrepVertex( OGLTransf, i );
				if ( centroidFromSubdivision ) {
					oglpt = GetSubdivisionCentroidFromVertex( OGLTransf, vertex, &normalAux );
					if ( !oglpt ) continue;
					aux.x += oglpt->v.v[ 0 ];
					aux.y += oglpt->v.v[ 1 ];
					aux.z += oglpt->v.v[ 2 ];
					if ( normal ) ( *normal ) = ( *normal ) + normalAux;
				} else {
					iwpt = vertex->GetPoint( );
					aux.x += iwpt.x;
					aux.y += iwpt.y;
					aux.z += iwpt.z;
					if ( normal ) {
						normalAux = GetNormalPBrepVertex( OGLTransf, vertex->GetIndexExt( ) );
						( *normal ) = ( *normal ) + normalAux;
					}
				}
				count++;
			}
		}
	}

	if ( count == 0 ) return false;
	aux /= count;
	*pos = aux;
	return true;
}

//------------------------------------------------------------------------------

bool TPBrepData::GetSelectionMiddleNormal( TOGLTransf *OGLTransf, T3DVector *normal )
{
	int i, j, count, nFaces, nVertices;
	T3DPoint aux, centroid;
	IwPolyFace *face;
	IwVector3d norm;
	IwTA<IwPolyVertex *> auxVertices;

	count = 0;
	if ( IsAnyFaceSelected( OGLTransf ) ) {
		nFaces = CountPBrepFaces( OGLTransf );
		norm.x = 0;
		norm.y = 0;
		norm.z = 0;
		for ( i = 0; i < nFaces; i++ ) {
			if ( IsFaceSelected( OGLTransf, i ) ) {
				face = GetPBrepFace( OGLTransf, i );
				norm += face->GetNormal( true );
				face->GetPolyVertices( auxVertices );
				nVertices = (int) auxVertices.GetSize( );
				for ( j = 0; j < nVertices; j++ ) {
					centroid.x += auxVertices[ j ]->GetPoint( ).x;
					centroid.y += auxVertices[ j ]->GetPoint( ).y;
					centroid.z += auxVertices[ j ]->GetPoint( ).z;
				}
				centroid /= nVertices;
				aux += centroid;
				centroid = T3DPoint( 0, 0, 0 );
				count++;
			}
		}
		norm.Unitize( );
	}

	if ( count == 0 ) return false;
	aux /= count;
	normal->org = aux;
	normal->size = T3DPoint( norm.x, norm.y, norm.z );
	return true;
}

//------------------------------------------------------------------------------

bool TPBrepData::GetSelectionGroupMiddleNormal( TOGLTransf *OGLTransf, IwPolyFace *currentFace, T3DVector *normal )
{
	bool isGroup;
	int i, j, g, count, nFaces, nVertices;
	T3DPoint aux, centroid;
	IwPolyFace *face;
	IwVector3d norm;
	IwTA<IwPolyVertex *> auxVertices;
	vector<int> listFaces;
	vector<vector<int> > groups;

	isGroup = false;
	if ( IsAnyFaceSelected( OGLTransf ) ) {
		if ( !GetDisjointGroupFaces( OGLTransf, &groups ) ) return false;

		for ( g = 0; g < (int) groups.size( ); g++ ) {
			listFaces = groups.at( g );
			nFaces = listFaces.size( );
			norm.x = 0;
			norm.y = 0;
			norm.z = 0;
			count = 0;
			for ( i = 0; i < nFaces; i++ ) {
				face = GetPBrepFace( OGLTransf, listFaces[ i ] );
				if ( face == currentFace ) isGroup = true;
				norm += face->GetNormal( true );
				face->GetPolyVertices( auxVertices );
				nVertices = (int) auxVertices.GetSize( );
				for ( j = 0; j < nVertices; j++ ) {
					centroid.x += auxVertices[ j ]->GetPoint( ).x;
					centroid.y += auxVertices[ j ]->GetPoint( ).y;
					centroid.z += auxVertices[ j ]->GetPoint( ).z;
				}
				centroid /= nVertices;
				aux += centroid;
				centroid = T3DPoint( 0, 0, 0 );
				count++;
			}
			norm.Unitize( );
			if ( isGroup ) break;
		}
	}

	if ( count == 0 ) return false;
	aux /= count;
	normal->org = aux;
	normal->size = T3DPoint( norm.x, norm.y, norm.z );
	return true;
}

//------------------------------------------------------------------------------

// Para crear una cara por selección, tienen que ser vértices o aristas frontera
// Si se pasa el parámetro 'vertexs', se le añaden todos los vértices
bool TPBrepData::IsCorrectBoundarySelectionCreateFace( TOGLTransf *OGLTransf, ElementType eType )
{
	bool ret;
	int i, nElements;
	int *liElementsSelected;
	IwPolyVertex *v;
	IwPolyEdge *e;

	if ( !OGLTransf ) return false;

	ret = true;
	liElementsSelected = 0;
	switch ( eType ) {
		case ElementType::Vertex:
			liElementsSelected = GetVertexs( OGLTransf, SelectedElementType::AllSelected, nElements );
			if ( liElementsSelected && nElements > 2 ) {
				for ( i = 0; i < nElements; i++ ) {
					v = PBrepVertexs[ liElementsSelected[ i ] ];
					if ( !v ) continue;
					if ( !v->IsBoundaryVertex( ) ) {
						ret = false;
						break;
					}
				}
			} else
				ret = false;
			break;

		case ElementType::Edge:
			liElementsSelected = GetEdges( OGLTransf, SelectedElementType::AllSelected, nElements );
			if ( liElementsSelected && nElements > 1 ) {
				for ( i = 0; i < nElements; i++ ) {
					e = PBrepEdges[ liElementsSelected[ i ] ];
					if ( !e ) continue;
					if ( !e->IsBoundary( ) ) {
						ret = false;
						break;
					}
				}
			} else
				ret = false;
			break;

		default: ret = false; break;
	}

	if ( liElementsSelected ) delete[] liElementsSelected;
	return ret;
}

//------------------------------------------------------------------------------

bool TPBrepData::CreateFaceFromBoundarySelection( TOGLTransf *OGLTransf, ElementType eType, int selectededges[ 2 ] )
{
	int i, j, nSegments, nElements;
	bool faceCreated;
	int *liElementsSelected;
	IwPolyFace *newFace;
	IwPolyVertex *v1, *v2;
	IwPolyEdge *e;
	IwTA<IwPolyVertex *> vertexs, boundaryVertices;
	IwTA<IwPolyEdge *> edges, edgesAux;
	IwTA<IwTA<IwPolyVertex *> > vertexsOrdered, holes;
	IwTA<IwPolyRegion *> regions;
	IwTA<IwPolyShell *> shells;

	if ( !OGLTransf ) return false;
	if ( eType != ElementType::Vertex && eType != ElementType::Edge ) return false;
	PBrep->GetPolyRegions( regions );
	PBrep->GetPolyShells( shells );
	if ( regions.GetSize( ) == 0 || shells.GetSize( ) == 0 ) return false;

	if ( selectededges ) {
		liElementsSelected = selectededges;
		nElements = 2;
		eType = ElementType::Edge;
	} else
		liElementsSelected = 0;
	if ( eType == ElementType::Vertex ) {
		if ( !liElementsSelected ) liElementsSelected = GetVertexs( OGLTransf, SelectedElementType::AllSelected, nElements );
		if ( liElementsSelected ) {
			for ( i = 0; i < nElements; i++ ) {
				v1 = PBrepVertexs[ liElementsSelected[ i ] ];
				if ( !v1 ) continue;
				vertexs.AddUnique( v1 );
			}
		}
	} else {
		if ( !liElementsSelected ) liElementsSelected = GetEdges( OGLTransf, SelectedElementType::AllSelected, nElements );
		if ( liElementsSelected ) {
			for ( i = 0; i < nElements; i++ ) {
				e = PBrepEdges[ liElementsSelected[ i ] ];
				if ( !e ) continue;
				vertexs.AddUnique( e->GetStartVertex( ) );
				vertexs.AddUnique( e->GetEndVertex( ) );
			}
		}
	}

	if ( liElementsSelected && !selectededges ) delete[] liElementsSelected;
	if ( (int) vertexs.GetSize( ) < 3 ) return false;

	if ( !OrderBoundaryVertexsByContinuity( &vertexs, &vertexsOrdered ) ) return false;
	faceCreated = false;

	// Primero buscamos los segmentos cerrados y hacemos caras con ellos
	nSegments = (int) vertexsOrdered.GetSize( );
	for ( i = 0; i < nSegments; i++ ) {
		if ( (int) vertexsOrdered.GetAt( i ).GetSize( ) > 2 ) {
			v1 = vertexsOrdered.GetAt( i ).GetAt( 0 );
			v2 = vertexsOrdered.GetAt( i ).GetLast( );
			v1->FindPolyEdgesBetween( v2, edges );
			if ( (int) edges.GetSize( ) == 1 ) {
				PBrep->CreatePolyFace( regions.GetAt( 0 ), shells.GetAt( 0 ), vertexsOrdered.GetAt( i ), newFace );

				// Chequeo de si las aristas simetricas son pliegues
				if ( newFace ) {
					newFace->GetPolyEdges( edgesAux );
					for ( j = 0; j < (int) vertexsOrdered.GetAt( i ).GetSize( ) - 1; j++ ) {
						vertexsOrdered.GetAt( i ).GetAt( j + 1 )->FindPolyEdgeBetween( vertexsOrdered.GetAt( i ).GetAt( j ), e );
						if ( e && IsEdgeCrease( e ) && (int) edgesAux.GetSize( ) > j && edgesAux[ j ] ) edgesAux[ j ]->SetUserFloat1( e->GetUserFloat1( ) );
					}
					vertexsOrdered.GetAt( i ).GetAt( 0 )->FindPolyEdgeBetween( vertexsOrdered.GetAt( i ).GetAt( vertexsOrdered.GetAt( i ).GetSize( ) - 1 ), e );
					if ( e && IsEdgeCrease( e ) && (int) edgesAux.GetSize( ) > j && edgesAux[ j ] ) edgesAux[ j ]->SetUserFloat1( e->GetUserFloat1( ) );
				}

				vertexsOrdered.RemoveAt( i );
				i--;
				nSegments--;
				faceCreated = true;
			}
		}
	}

	if ( nSegments > 0 ) {
		// Si queda un segmento abierto y tiene al menos tres vértices se crea una cara con el
		newFace = 0;
		if ( nSegments == 1 ) {
			if ( ( (int) vertexsOrdered.GetAt( 0 ).GetSize( ) ) > 2 ) {
				PBrep->CreatePolyFace( regions.GetAt( 0 ), shells.GetAt( 0 ), vertexsOrdered.GetAt( 0 ), newFace );
				vertexs.RemoveAll( );
				vertexs.Copy( vertexsOrdered.GetAt( 0 ) );
				faceCreated = true;
			}
		} else { // Si hay más de un segmento abierto se forma una cara con los dos primeros si en conjunto al menos hay dos vértices
			if ( ( (int) vertexsOrdered.GetAt( 0 ).GetSize( ) + (int) vertexsOrdered.GetAt( 1 ).GetSize( ) ) > 2 ) {
				vertexs.RemoveAll( );
				vertexs.Copy( vertexsOrdered.GetAt( 0 ) );
				vertexs.Append( vertexsOrdered.GetAt( 1 ) );
				PBrep->CreatePolyFace( regions.GetAt( 0 ), shells.GetAt( 0 ), vertexs, newFace );
				faceCreated = true;
			}
		}
		// Chequeo de si las aristas simetricas son pliegues
		if ( newFace ) {
			newFace->GetPolyEdges( edgesAux );
			for ( j = 0; j < (int) vertexs.GetSize( ) - 1; j++ ) {
				vertexs.GetAt( j + 1 )->FindPolyEdgeBetween( vertexs.GetAt( j ), e );
				if ( e && IsEdgeCrease( e ) && (int) edgesAux.GetSize( ) > j && edgesAux[ j ] ) edgesAux[ j ]->SetUserFloat1( e->GetUserFloat1( ) );
			}
			vertexs.GetAt( 0 )->FindPolyEdgeBetween( vertexs.GetAt( vertexs.GetSize( ) - 1 ), e );
			if ( e && IsEdgeCrease( e ) && (int) edgesAux.GetSize( ) > j && edgesAux[ j ] ) edgesAux[ j ]->SetUserFloat1( e->GetUserFloat1( ) );
		}
	}

	if ( faceCreated ) UpdateTopology( OGLTransf );

	return faceCreated;
}

//------------------------------------------------------------------------------

bool TPBrepData::OrderBoundaryVertexsByContinuity( IwTA<IwPolyVertex *> *vertexsIn, IwTA<IwTA<IwPolyVertex *> > *vertexsOut )
{
	bool added;
	int i, nIn, step;
	IwPolyVertex *v1, *v2;
	IwTA<IwPolyVertex *> vertexInAux, vertexsConnected;
	IwTA<IwPolyEdge *> edges;

	if ( !PBrep || !vertexsIn || !vertexsOut ) return false;

	vertexsOut->RemoveAll( );
	nIn = (int) vertexsIn->GetSize( );
	if ( nIn == 0 ) return false;
	vertexInAux.Copy( *vertexsIn );

	do {
		v1 = vertexInAux.GetAt( 0 );
		vertexInAux.RemoveAt( 0 );
		vertexsConnected.RemoveAll( );
		vertexsConnected.Add( v1 );
		nIn--;
		step = 0;
		do {
			added = false;
			for ( i = 0; i < nIn; i++ ) {
				v2 = vertexInAux.GetAt( i );
				v1->FindPolyEdgesBetween( v2, edges );
				if ( (int) edges.GetSize( ) == 1 ) {
					vertexsConnected.Add( v2 );
					vertexInAux.RemoveAt( i );
					nIn--;
					added = true;
					v1 = v2;
					break;
				}
			}
			if ( !added && step == 0 && nIn > 0 ) {
				v1 = vertexsConnected.GetAt( 0 );
				vertexsConnected.ReverseArray( 0, vertexsConnected.GetSize( ) );
				added = true;
				step = 1;
			}
		} while ( added );

		// Nos aseguramos que el sentido de es el correcto
		if ( !CheckClockwiseVertexsForNewFace( &vertexsConnected ) ) {
			vertexsOut->RemoveAll( );
			return false;
		}

		vertexsOut->Add( vertexsConnected );
	} while ( nIn > 0 );

	return true;
}

//------------------------------------------------------------------------------

bool TPBrepData::CheckClockwiseVertexsForNewFace( IwTA<IwPolyVertex *> *vertexs )
{
	bool reverse;
	int i, nVertexs;
	IwPolyVertex *v1, *v2;
	IwTA<IwPolyEdge *> edges;

	if ( !vertexs ) return false;
	nVertexs = (int) vertexs->GetSize( );
	if ( nVertexs < 2 ) return true;
	reverse = false;

	// Buscamos dos puntos consecutivos que compartan una arista, la cual definirá el sentido
	for ( i = 0; i < nVertexs; i++ ) {
		v1 = vertexs->GetAt( i );
		v2 = vertexs->GetAt( ( i + 1 ) % nVertexs );
		v1->FindPolyEdgesBetween( v2, edges );
		if ( (int) edges.GetSize( ) > 0 ) {
			reverse = ( edges.GetAt( 0 )->GetStartVertex( ) == v1 );
			i++;
			break;
		}
	}

	// Comprobamos si hay mas aristas previas, las cuales tienen que coincidir en sentido con la previa encontrada.
	if ( nVertexs > 2 ) {
		for ( ; i < nVertexs; i++ ) {
			v1 = vertexs->GetAt( i );
			v2 = vertexs->GetAt( ( i + 1 ) % nVertexs );
			v1->FindPolyEdgesBetween( v2, edges );
			if ( (int) edges.GetSize( ) > 0 && reverse != ( edges.GetAt( 0 )->GetStartVertex( ) == v1 ) ) return false;
		}
	}

	// Invertimos sentido de creación si es necesario
	if ( reverse ) vertexs->ReverseArray( 0, nVertexs );
	return true;
}

//------------------------------------------------------------------------------

bool TPBrepData::CreateFaceFromCurrentMeshElementList( TOGLTransf *OGLTransf, IwTA<TMeshElementInfo> *elements, IwTA<IwPolyFace *> *faces, bool retopologize, ULONG userIndex )
{
	int i, nElements, pos;
	double area, vol, maxarea;
	bool faceDeg;
	IwPoint3d iwNewPoint3d, pt, deltaBarycenter;
	IwVector3d deltaMoments[ 2 ];
	IwPolyVertex *iwVertex;
	IwPolyEdge *e;
	IwPolyFace *newFace, *faceAux;
	IwTA<IwPolyEdge *> edgesAux;
	IwTA<IwPolyVertex *> vertexs;
	IwTA<IwPolyRegion *> regions;
	IwTA<IwPolyShell *> shells;
	IwPolyBrep *pBrep;
	IwPolyRegion *pRegion;
	IwPolyShell *pShell;
	IwTArray<IwPolyFace *> rNewTriangleFaces, unifiedFaces, faceAuxList;
	TAddedElements addedElements;

	if ( !OGLTransf || !elements || !RefEnt ) return false;
	nElements = (int) elements->GetSize( );
	if ( nElements < 3 ) return false;

	// Si la PBrep es null es porque partimos de una lowpoly vacía.
	if ( PBrep ) {
		PBrep->GetPolyRegions( regions );
		PBrep->GetPolyShells( shells );
		if ( regions.GetSize( ) == 0 || shells.GetSize( ) == 0 ) return false;
		pBrep = 0;
	} else {
		pBrep = new IwPolyBrep( _GetSMLib( )->GetContext( ), RES_COMP );
		pRegion = new IwPolyRegion( _GetSMLib( )->GetContext( ), pBrep );
		pShell = new IwPolyShell( _GetSMLib( )->GetContext( ), *pBrep, pRegion );
	}

	for ( i = 0; i < nElements; i++ ) {
		if ( elements->GetAt( i ).Type != ElementType::Vertex && elements->GetAt( i ).Type != ElementType::Undefined ) {
			if ( pBrep ) delete pBrep;
			return false;
		}
	}
	for ( i = 0; i < nElements; i++ ) {
		if ( elements->GetAt( i ).Type == ElementType::Vertex ) vertexs.Add( GetPBrepVertex( OGLTransf, elements->GetAt( i ).Index ) );
		else {
			iwNewPoint3d.Set( elements->GetAt( i ).Point.x, elements->GetAt( i ).Point.y, elements->GetAt( i ).Point.z );
			iwVertex = new IwPolyVertex( _GetSMLib( )->GetContext( ), PBrep ? *PBrep : *pBrep, iwNewPoint3d, RES_COMP );
			vertexs.Add( iwVertex );
		}
	}

	// Nos aseguramos que el sentido de es el correcto
	if ( !retopologize )
		if ( !CheckClockwiseVertexsForNewFace( &vertexs ) ) return false;

	if ( PBrep ) {
		if ( !PBrep->CreatePolyFace( regions.GetAt( 0 ), shells.GetAt( 0 ), vertexs, newFace ) ) return false;

		if ( retopologize && faces ) {
			newFace->SetUserIndex1( userIndex );
			newFace->TriangulateNonPlanar( rNewTriangleFaces );
			UpdateTopology( OGLTransf );
			maxarea = 0;
			for ( i = 0; i < (int) rNewTriangleFaces.GetSize( ); i++ ) {
				rNewTriangleFaces[ i ]->ComputeProperties( pt, area, vol, deltaBarycenter, deltaMoments, IW_MPT_AREA );
				if ( area > maxarea ) {
					maxarea = area;
					pos = i;
				}
			}

			newFace->ComputeProperties( pt, area, vol, deltaBarycenter, deltaMoments, IW_MPT_AREA );
			if ( area > maxarea || (int) rNewTriangleFaces.GetSize( ) == 0 ) newFace->SetUserIndex2( 1 ); // Para no borrar cara, que no cumple area pero es válida.
			else
				rNewTriangleFaces[ pos ]->SetUserIndex2( 1 ); // Para no borrar cara que no cumple area, pero es válida.
			faces->Add( newFace );
			if ( area >= MIN_AREA_MESH_FACE || newFace->GetUserIndex2( ) == 1 ) unifiedFaces.AddUnique( newFace );
			if ( rNewTriangleFaces.GetSize( ) > 0 ) {
				for ( i = 0; i < (int) rNewTriangleFaces.GetSize( ); i++ ) {
					faceAux = rNewTriangleFaces[ i ];
					faceAux->SetUserIndex1( userIndex );
					faces->Add( faceAux );
					faceAux->ComputeProperties( pt, area, vol, deltaBarycenter, deltaMoments, IW_MPT_AREA );
					if ( area >= MIN_AREA_MESH_FACE || faceAux->GetUserIndex2( ) == 1 ) unifiedFaces.Add( faceAux );
				}
			}

			faceDeg = false;
			if ( (int) unifiedFaces.GetSize( ) == 1 && (int) rNewTriangleFaces.GetSize( ) == 1 && faceAux->GetUserIndex2( ) == 1 ) {
				unifiedFaces.Add( newFace );
				faceDeg = true;
			} else if ( (int) unifiedFaces.GetSize( ) == 1 && (int) rNewTriangleFaces.GetSize( ) == 1 && newFace->GetUserIndex2( ) == 1 ) {
				unifiedFaces.Add( faceAux );
				faceDeg = true;
			}

			if ( unifiedFaces.GetSize( ) > 1 ) {
				faceAuxList.RemoveAll( );
				faces->RemoveElements( unifiedFaces, faceAuxList );
				InitAddedElements( &addedElements );
				DisolveFaces( OGLTransf, &unifiedFaces, -1, &addedElements, true );
				faces->RemoveAll( );
				unifiedFaces.RemoveAll( );
				if ( addedElements.iwFaces.GetSize( ) ) {
					faceAux = addedElements.iwFaces[ 0 ];
					faceAux->SetUserIndex1( userIndex );
					if ( faceDeg ) {
						faceAux->SetUserIndex2( 1 );
					}
					faceAuxList.Add( faceAux );
					( *faces ) = faceAuxList;
				}
			}
			return true;
		}

		// Chequeo de si las aristas simetricas son pliegues
		if ( newFace ) {
			newFace->GetPolyEdges( edgesAux );
			for ( i = 0; i < (int) vertexs.GetSize( ) - 1; i++ ) {
				vertexs.GetAt( i + 1 )->FindPolyEdgeBetween( vertexs.GetAt( i ), e );
				if ( e && IsEdgeCrease( e ) && (int) edgesAux.GetSize( ) > i && edgesAux[ i ] ) edgesAux[ i ]->SetUserFloat1( e->GetUserFloat1( ) );
			}
			vertexs.GetAt( 0 )->FindPolyEdgeBetween( vertexs.GetAt( vertexs.GetSize( ) - 1 ), e );
			if ( e && IsEdgeCrease( e ) && (int) edgesAux.GetSize( ) > i && edgesAux[ i ] ) edgesAux[ i ]->SetUserFloat1( e->GetUserFloat1( ) );
		}

		UpdateTopology( OGLTransf );
	} else {
		if ( !pBrep->CreatePolyFace( pRegion, pShell, vertexs, newFace ) ) {
			delete pBrep;
			return false;
		}
		// Chequeo de si las aristas simetricas son pliegues
		if ( newFace ) {
			newFace->GetPolyEdges( edgesAux );
			for ( i = 0; i < (int) vertexs.GetSize( ) - 1; i++ ) {
				vertexs.GetAt( i + 1 )->FindPolyEdgeBetween( vertexs.GetAt( i ), e );
				if ( e && IsEdgeCrease( e ) && (int) edgesAux.GetSize( ) > i && edgesAux[ i ] ) edgesAux[ i ]->SetUserFloat1( e->GetUserFloat1( ) );
			}
			vertexs.GetAt( 0 )->FindPolyEdgeBetween( vertexs.GetAt( vertexs.GetSize( ) - 1 ), e );
			if ( e && IsEdgeCrease( e ) && (int) edgesAux.GetSize( ) > i && edgesAux[ i ] ) edgesAux[ i ]->SetUserFloat1( e->GetUserFloat1( ) );
		}

		CopyPBrep( pBrep );
		UpdateOGLListFromPBrep( OGLTransf, RefEnt->GetOGLList( OGLTransf ), false, true, false, true );
		RefEnt->SetPolygonDirty( true );
		RefEnt->SetPBrepDirty( false );

		delete pBrep;
	}

	return true;
}

//------------------------------------------------------------------------------
// -1 - Todos
// 0  - No seleccionadas
// 1  - Selección de usuario
// 2  - Selección automática de Ring
// 3  - Ultima seleccion del usuario
// 4 	- Todos los seleccionados
int *TPBrepData::GetVertexs( TOGLTransf *OGLTransf, SelectedElementType selType, int &iNumVertex )
{
	int *liVertexSelected;
	ULONG uli;

	iNumVertex = 0;
	if ( !GetPBrep( OGLTransf ) ) return 0;

	if ( selType == SelectedElementType::All ) iNumVertex = (int) PBrepVertexs.GetSize( );
	else {
		iNumVertex = 0;
		for ( uli = 0; uli < PBrepVertexs.GetSize( ); uli++ ) {
			if ( SelectedV[ uli ].i == (int) selType || ( SelectedV[ uli ].i > 0 && selType == SelectedElementType::AllSelected ) ) iNumVertex++;
		}
	}
	if ( !iNumVertex ) return 0;

	liVertexSelected = new int[ iNumVertex ];
	iNumVertex = 0;
	for ( uli = 0; uli < PBrepVertexs.GetSize( ); uli++ )
		if ( selType == SelectedElementType::All || SelectedV[ uli ].i == (int) selType || ( SelectedV[ uli ].i > 0 && selType == SelectedElementType::AllSelected ) ) liVertexSelected[ iNumVertex++ ] = uli;

	return liVertexSelected;
}

//------------------------------------------------------------------------------
// -1 - Todos
// 0  - No seleccionadas
// 1  - Selección de usuario
// 2  - Selección automática de Ring
// 3  - Ultima seleccion del usuario
// 4 	- Todas las seleccionadas
int *TPBrepData::GetFaces( TOGLTransf *OGLTransf, SelectedElementType selType, int &iNumFaces )
{
	ULONG uli;
	int *liFacesSelected;

	iNumFaces = 0;
	if ( !GetPBrep( OGLTransf ) ) return 0;

	if ( selType == SelectedElementType::All ) iNumFaces = (int) PBrepFaces.GetSize( );
	else {
		iNumFaces = 0;
		for ( uli = 0; uli < PBrepFaces.GetSize( ); uli++ ) {
			if ( SelectedF[ uli ].i == (int) selType || ( SelectedF[ uli ].i > 0 && selType == SelectedElementType::AllSelected ) ) iNumFaces++;
		}
	}
	if ( !iNumFaces ) return 0;

	liFacesSelected = new int[ iNumFaces ];
	iNumFaces = 0;
	for ( uli = 0; uli < PBrepFaces.GetSize( ); uli++ )
		if ( selType == SelectedElementType::All || SelectedF[ uli ].i == (int) selType || ( SelectedF[ uli ].i > 0 && selType == SelectedElementType::AllSelected ) ) liFacesSelected[ iNumFaces++ ] = uli;

	return liFacesSelected;
}

//------------------------------------------------------------------------------

bool TPBrepData::GetDisjointGroupFaces( IwTA<IwPolyFace *> *faces, vector<vector<int> > *groups )
{
	bool added;
	int i;
	IwPolyFace *face;
	vector<int> currentgroup;
	IwTA<IwPolyFace *> facesCopy;

	if ( !faces || !groups ) return false;
	groups->clear( );

	if ( !( *faces ).GetSize( ) ) return false;

	facesCopy = ( *faces );

	face = facesCopy[ facesCopy.GetSize( ) - 1 ];
	facesCopy.RemoveAt( facesCopy.GetSize( ) - 1 );
	currentgroup.push_back( face->GetIndexExt( ) );

	do {
		added = false;
		for ( i = facesCopy.GetSize( ) - 1; i >= 0; i-- )
			if ( IsAdjacentFaceToGroup( facesCopy[ i ], &currentgroup ) ) {
				currentgroup.push_back( facesCopy[ i ]->GetIndexExt( ) );
				facesCopy.RemoveAt( i );
				added = true;
			}
		if ( !added && facesCopy.GetSize( ) ) {
			groups->push_back( currentgroup );
			currentgroup.clear( );
			face = facesCopy[ facesCopy.GetSize( ) - 1 ];
			facesCopy.RemoveAt( facesCopy.GetSize( ) - 1 );
			currentgroup.push_back( face->GetIndexExt( ) );
		}
	} while ( facesCopy.GetSize( ) );

	if ( currentgroup.size( ) ) groups->push_back( currentgroup );

	return true;
}

//------------------------------------------------------------------------------

bool TPBrepData::GetDisjointGroupFaces( TOGLTransf *OGLTransf, vector<vector<int> > *groups, bool extend, bool allFaces, bool useSeams )
{
	bool anyAdded, faceInSelectionList;
	int num, i, *selectedList;
	IwPolyFace *f2;
	IwTA<IwPolyFace *> faces;
	vector<int> group, groupAux, selectedListVector;
	vector<int>::iterator iterFaces, iterFacesAux, iteratorGroup, iterGroups;
	vector<vector<int> > groupsAux;
	IwTA<IwPolyEdge *> boundaryEdges;
	TInteger_List facesUserIndex2List;

	if ( !groups ) return false;

	groups->clear( );

	if ( !allFaces || extend ) selectedList = GetFaces( OGLTransf, SelectedElementType::AllSelected, num );
	else
		selectedList = GetFaces( OGLTransf, SelectedElementType::All, num );

	if ( !selectedList ) return false;

	if ( !useSeams && num == (int) PBrepFaces.GetSize( ) && PBrep ) {
		PBrep->GetBoundaryEdges( boundaryEdges );
		if ( boundaryEdges.GetSize( ) == 0 ) {
			for ( i = 0; i < (int) PBrepFaces.GetSize( ); i++ )
				group.push_back( PBrepFaces[ i ]->GetIndexExt( ) );
			groups->push_back( group );

			delete[] selectedList;
			return true;
		}
	}

	GetListsUserIndex2( 0, 0, &facesUserIndex2List );
	InitUserIndex2( false, false, true );

	for ( i = 0; i < num; i++ )
		selectedListVector.push_back( selectedList[ i ] );

	iterFaces = selectedListVector.begin( );
	while ( selectedListVector.size( ) > 0 ) {
		group.clear( );

		f2 = PBrepFaces[ *iterFaces ];
		if ( f2->GetUserIndex2( ) != 0 ) {
			selectedListVector.erase( iterFaces );
			continue;
		}

		group.push_back( (int) f2->GetIndexExt( ) );
		f2->SetUserIndex2( 1 );

		do {
			groupAux.clear( );
			iteratorGroup = group.begin( );

			anyAdded = false;
			while ( iteratorGroup != group.end( ) ) {
				f2 = PBrepFaces[ *iteratorGroup ];
				if ( f2->GetUserIndex2( ) == 2 ) { // Ya se han recorrido las adyacentes de esta cara
					iteratorGroup++;
					continue;
				}
				f2->SetUserIndex2( 2 );
				GetAdjacentFaces( f2, &faces, useSeams );
				for ( i = 0; i < (int) faces.GetSize( ); i++ ) {
					if ( ( !allFaces && !extend ) && faces[ i ]->GetUserIndex2( ) == 0 ) {
						faceInSelectionList = false;
						iterFacesAux = selectedListVector.begin( );
						while ( iterFacesAux != selectedListVector.end( ) ) {
							if ( *iterFacesAux == faces[ i ]->GetIndexExt( ) ) {
								faceInSelectionList = true;
								break;
							}
							iterFacesAux++;
						}
						if ( !faceInSelectionList ) continue;
					}

					if ( faces[ i ]->GetUserIndex2( ) == 0 ) {
						anyAdded = true;
						groupAux.push_back( (int) faces[ i ]->GetIndexExt( ) );
						faces[ i ]->SetUserIndex2( 1 );
					}
				}
				iteratorGroup++;
			}

			if ( groupAux.size( ) > 0 ) {
				iteratorGroup = groupAux.begin( );
				while ( iteratorGroup != groupAux.end( ) ) {
					group.push_back( *iteratorGroup );
					iteratorGroup++;
				}
			}

			// Buscamos las caras en el vector y borramos las que ya se han metido
			iterFacesAux = selectedListVector.begin( );
			while ( iterFacesAux != selectedListVector.end( ) ) {
				f2 = PBrepFaces[ *iterFacesAux ];
				// f2 = GetPBrepFace( OGLTransf, *iterFacesAux );
				if ( !f2 ) continue;
				if ( f2->GetUserIndex2( ) != 0 ) selectedListVector.erase( iterFacesAux );
				else
					iterFacesAux++;
			}

		} while ( anyAdded && ( extend || iterFaces != selectedListVector.end( ) ) );
		sort( group.begin( ), group.end( ) );
		groups->push_back( group );
		iterFaces = selectedListVector.begin( );
	}

	delete[] selectedList;

	SetListsUserIndex2( 0, 0, &facesUserIndex2List );

	return true;
}

bool TPBrepData::GetDisjointGroupEdges( TOGLTransf *OGLTransf, vector<vector<int> > *groups, bool extend, bool allEdges, IwTA<IwPolyEdge *> *edgesGoal )
{
	bool foundodd, foundeven;
	int num, i, *selectedList, nextodd, nexteven, steps;
	ULONG index;
	IwPolyVertex *nextvertex, *prevvertex;
	IwPolyEdge *e2, *e3;
	IwTA<IwPolyEdge *> edges;
	vector<int> group, groupAux, selectedListVector;
	vector<int>::iterator iterEdges, iterEdges2, iterEdgesAux, iteratorGroup, iteratorGroup2, iterGroups;
	vector<vector<int> > groupsAux;
	TInteger_List vertexsUserIndex2List, edgesUserIndex2List;

	if ( !groups ) return false;

	groups->clear( );

	if ( edgesGoal ) {
		num = edgesGoal->GetSize( );
		selectedList = new int[ num ];
		for ( i = 0; i < num; i++ ) {
			if ( FindElement_Edge( &PBrepEdges, ( *edgesGoal )[ i ], index, e2 ) ) selectedList[ i ] = e2->GetUserIndex1( );
			else
				selectedList[ i ] = ( *edgesGoal )[ i ]->GetUserIndex1( );
		}
	} else if ( !allEdges || extend )
		selectedList = GetEdges( OGLTransf, SelectedElementType::AllSelected, num );
	else
		selectedList = GetEdges( OGLTransf, SelectedElementType::All, num );

	if ( !selectedList ) return false;

	GetListsUserIndex2( &vertexsUserIndex2List, &edgesUserIndex2List, 0 );
	InitUserIndex2( true, true, false );

	for ( i = 0; i < num; i++ )
		selectedListVector.push_back( selectedList[ i ] );

	// Recorremos las aristas y marcamos los vertices tantas veces como aparezcan
	iterEdges = selectedListVector.begin( );
	while ( iterEdges != selectedListVector.end( ) ) {
		e2 = PBrepEdges[ *iterEdges ];
		e2->GetStartVertex( )->SetUserIndex2( e2->GetStartVertex( )->GetUserIndex2( ) + 1 );
		e2->GetEndVertex( )->SetUserIndex2( e2->GetEndVertex( )->GetUserIndex2( ) + 1 );
		iterEdges++;
	}

	steps = 1;
	nextodd = 1;
	nexteven = 2;
	nextvertex = 0;
	prevvertex = 0;
	while ( selectedListVector.size( ) > 0 && steps <= 2 ) {
		iterEdges = selectedListVector.begin( );
		while ( selectedListVector.size( ) && iterEdges != selectedListVector.end( ) ) {
			e2 = PBrepEdges[ *iterEdges ];
			foundodd = false;
			foundeven = false;
			if ( steps == 1 ) { // Buscamos los vertices impares a partir del 1
				if ( (int) e2->GetStartVertex( )->GetUserIndex2( ) == nextodd ) {
					nextvertex = e2->GetEndVertex( );
					prevvertex = e2->GetStartVertex( );
				} else if ( (int) e2->GetEndVertex( )->GetUserIndex2( ) == nextodd ) {
					nextvertex = e2->GetStartVertex( );
					prevvertex = e2->GetEndVertex( );
				}
				if ( nextvertex ) foundodd = true;
			} else if ( steps == 2 ) { // Ahora buscamos los pares a partir del 2
				if ( (int) e2->GetStartVertex( )->GetUserIndex2( ) == nexteven ) {
					nextvertex = e2->GetEndVertex( );
					prevvertex = e2->GetStartVertex( );
				} else if ( (int) e2->GetEndVertex( )->GetUserIndex2( ) == nexteven ) {
					nextvertex = e2->GetStartVertex( );
					prevvertex = e2->GetEndVertex( );
				}
				if ( nextvertex ) foundeven = true;
			}
			if ( nextvertex ) {
				group.push_back( *iterEdges );
				selectedListVector.erase( iterEdges );

				if ( nextvertex->GetUserIndex2( ) == 2 ) {
					iterEdges2 = selectedListVector.begin( );
					while ( iterEdges2 != selectedListVector.end( ) ) {
						e3 = PBrepEdges[ *iterEdges2 ];
						if ( e3->GetStartVertex( ) != nextvertex && e3->GetEndVertex( ) != nextvertex ) {
							iterEdges2++;
							continue;
						}

						if ( e3->GetEndVertex( ) == nextvertex && e3->GetStartVertex( )->GetUserIndex2( ) == 2 ) nextvertex = e3->GetStartVertex( );
						else if ( e3->GetStartVertex( ) == nextvertex && e3->GetEndVertex( )->GetUserIndex2( ) == 2 )
							nextvertex = e3->GetEndVertex( );
						else
							nextvertex = 0;

						group.push_back( *iterEdges2 );
						selectedListVector.erase( iterEdges2 );

						if ( !nextvertex ) {
							if ( prevvertex && prevvertex->GetUserIndex2( ) != 2 ) {
								groups->push_back( group );
								group.clear( );
							}
							break;
						}
						iterEdges2 = selectedListVector.begin( );
					}
				}
				if ( prevvertex && prevvertex->GetUserIndex2( ) == 2 ) {
					iterEdges2 = selectedListVector.begin( );
					while ( iterEdges2 != selectedListVector.end( ) ) {
						e3 = PBrepEdges[ *iterEdges2 ];
						if ( e3->GetStartVertex( ) != prevvertex && e3->GetEndVertex( ) != prevvertex ) {
							iterEdges2++;
							continue;
						}

						if ( e3->GetEndVertex( ) == prevvertex && e3->GetStartVertex( )->GetUserIndex2( ) == 2 ) prevvertex = e3->GetStartVertex( );
						else if ( e3->GetStartVertex( ) == prevvertex && e3->GetEndVertex( )->GetUserIndex2( ) == 2 )
							prevvertex = e3->GetEndVertex( );
						else
							prevvertex = 0;

						group.push_back( *iterEdges2 );
						selectedListVector.erase( iterEdges2 );

						if ( !prevvertex ) {
							if ( !nextvertex || nextvertex->GetUserIndex2( ) != 2 ) {
								groups->push_back( group );
								group.clear( );
								break;
							}
						}
						iterEdges2 = selectedListVector.begin( );
					}
				}
				if ( group.size( ) ) {
					groups->push_back( group );
					group.clear( );
				}
				if ( selectedListVector.size( ) ) {
					iterEdges = selectedListVector.begin( ); // Reinicimos el bucle pq se ha modificado el array
					continue;
				}
			}
			iterEdges++;
		}
		foundodd = foundeven = false;
		if ( steps == 1 ) { // Primero comprobamos si hay algun impar
			iterEdges2 = selectedListVector.begin( );
			while ( iterEdges2 != selectedListVector.end( ) ) {
				e3 = PBrepEdges[ *iterEdges2 ];
				if ( e3->GetStartVertex( )->GetUserIndex2( ) % 2 == 1 ) {
					foundodd = true;
					nextodd = e3->GetStartVertex( )->GetUserIndex2( );
					break;
				} else if ( e3->GetEndVertex( )->GetUserIndex2( ) % 2 == 1 ) {
					foundodd = true;
					nextodd = e3->GetEndVertex( )->GetUserIndex2( );
					break;
				}
				iterEdges2++;
			}
		} else if ( steps == 2 ) {
			iterEdges2 = selectedListVector.begin( );
			while ( iterEdges2 != selectedListVector.end( ) ) {
				e3 = PBrepEdges[ *iterEdges2 ];
				if ( e3->GetStartVertex( )->GetUserIndex2( ) % 2 == 0 ) {
					foundeven = true;
					nexteven = e3->GetStartVertex( )->GetUserIndex2( );
					break;
				} else if ( e3->GetEndVertex( )->GetUserIndex2( ) % 2 == 0 ) {
					foundeven = true;
					nexteven = e3->GetEndVertex( )->GetUserIndex2( );
					break;
				}
				iterEdges2++;
			}
		}
		if ( !foundodd && !foundeven ) steps++;
	}
	/*
	//Ahora hay que buscar los impares mayor de 2
	foundodd = false;
	iterEdges = selectedListVector.begin( );
	do {

	} while ( foundodd || iterEdges != selectedListVector.end( ) );
   */

	delete[] selectedList;

	SetListsUserIndex2( &vertexsUserIndex2List, &edgesUserIndex2List, 0 );

	return !selectedListVector.size( );
}

//------------------------------------------------------------------------------

bool TPBrepData::IsAnyFaceSelected( TOGLTransf *OGLTransf, SelectedElementType selType )
{
	ULONG uli, size;

	if ( !GetPBrep( OGLTransf, false ) ) return false;

	size = PBrepFaces.GetSize( );
	for ( uli = 0; uli < size; uli++ ) {
		if ( selType == SelectedElementType::All ) {
			if ( SelectedF[ uli ].i != (int) SelectedElementType::NoSelected ) return true;
		} else if ( SelectedF[ uli ].i == (int) selType )
			return true;
	}

	return false;
}

//------------------------------------------------------------------------------

int TPBrepData::GetFacesSelected( TOGLTransf *OGLTransf, SelectedElementType selType )
{
	int count;
	ULONG uli, size;

	count = 0;
	if ( !GetPBrep( OGLTransf, false ) ) return count;

	size = PBrepFaces.GetSize( );
	for ( uli = 0; uli < size; uli++ ) {
		if ( selType == SelectedElementType::All ) {
			if ( SelectedF[ uli ].i != (int) SelectedElementType::NoSelected ) count++;
		} else if ( SelectedF[ uli ].i == (int) selType )
			count++;
	}

	return count;
}

//------------------------------------------------------------------------------

bool TPBrepData::IsAnyEdgeSelected( TOGLTransf *OGLTransf, SelectedElementType selType )
{
	ULONG uli, size;

	if ( !GetPBrep( OGLTransf, false ) ) return false;

	size = PBrepEdges.GetSize( );
	for ( uli = 0; uli < size; uli++ ) {
		if ( selType == SelectedElementType::All ) {
			if ( SelectedE[ uli ] != (int) SelectedElementType::NoSelected && SelectedE[ uli ] < (int) SelectedElementType::AllSelected ) return true;
		} else if ( SelectedE[ uli ] == (int) selType )
			return true;
	}

	return false;
}

//------------------------------------------------------------------------------

int TPBrepData::GetEdgesSelected( TOGLTransf *OGLTransf, SelectedElementType selType )
{
	int count;
	ULONG uli, size;

	count = 0;
	if ( !GetPBrep( OGLTransf, false ) ) return count;

	size = PBrepEdges.GetSize( );
	for ( uli = 0; uli < size; uli++ ) {
		if ( selType == SelectedElementType::All ) {
			if ( SelectedE[ uli ] != (int) SelectedElementType::NoSelected && SelectedE[ uli ] < (int) SelectedElementType::AllSelected ) count++;
		} else if ( SelectedE[ uli ] == (int) selType )
			count++;
	}

	return count;
}

//------------------------------------------------------------------------------

int *TPBrepData::GetEdgesFromSelection( TOGLTransf *OGLTransf, int &numedges )
{
	int *selected, numsel, i, j;
	IwPolyEdge *edge;
	IwTA<IwPolyEdge *> edges, edgesface;
	IwPolyFace *face;

	numedges = 0;
	selected = GetVertexs( OGLTransf, SelectedElementType::AllSelected, numsel );
	if ( numsel ) {
		for ( i = 0; i < numsel - 1; i++ )
			for ( j = 0; j < numsel; j++ ) {
				edge = GetEdgeFromVertices( selected[ i ], selected[ j ] );
				if ( edge ) edges.Add( edge );
			}
		delete[] selected;
	}
	if ( !edges.GetSize( ) ) {
		selected = GetFaces( OGLTransf, SelectedElementType::AllSelected, numsel );
		if ( !numsel ) return 0;
		InitUserIndex2( false, true, false );
		for ( i = 0; i < numsel; i++ ) {
			face = GetPBrepFace( OGLTransf, selected[ i ] );
			face->GetPolyEdges( edgesface );
			for ( j = 0; j < (int) edgesface.GetSize( ); j++ ) {
				edge = edgesface[ j ];
				if ( edge->GetUserIndex1( ) == ULONG_MAX ) edge = edge->GetSymmetricPolyEdge( );
				if ( edge->GetUserIndex2( ) ) continue;
				edge->SetUserIndex2( 1 );
				edges.Add( edge );
			}
		}
		InitUserIndex2( false, true, false );
		delete[] selected;
	}

	numedges = edges.GetSize( );
	if ( !numedges ) return 0;
	selected = new int[ numedges ];
	for ( i = 0; i < numedges; i++ )
		selected[ i ] = edges[ i ]->GetUserIndex1( );
	return selected;
}

//------------------------------------------------------------------------------

bool TPBrepData::IsAnyVertexSelected( TOGLTransf *OGLTransf, SelectedElementType selType )
{
	ULONG uli, size;

	if ( !GetPBrep( OGLTransf, false ) ) return false;

	size = PBrepVertexs.GetSize( );
	for ( uli = 0; uli < size; uli++ ) {
		if ( selType == SelectedElementType::All ) {
			if ( SelectedV[ uli ].i != (int) SelectedElementType::NoSelected ) return true;
		} else if ( SelectedV[ uli ].i == (int) selType )
			return true;
	}

	return false;
}

//------------------------------------------------------------------------------

int TPBrepData::GetVertexsSelected( TOGLTransf *OGLTransf, SelectedElementType selType )
{
	int count;
	ULONG uli, size;

	count = 0;
	if ( !GetPBrep( OGLTransf, false ) ) return count;

	size = PBrepVertexs.GetSize( );
	for ( uli = 0; uli < size; uli++ ) {
		if ( selType == SelectedElementType::All ) {
			if ( SelectedV[ uli ].i != (int) SelectedElementType::NoSelected ) count++;
		} else if ( SelectedV[ uli ].i == (int) selType )
			count++;
	}

	return count;
}

//---------------------------------------------------------------------------

int TPBrepData::IsAnyClosedRingSelected( TOGLTransf *OGLTransf, ElementType faceOrEdge, bool force, IwTA<IwTA<IwPolyFace *> > *faces, IwTA<IwTA<IwPolyEdge *> > *edges )
{
	bool ret, anyClosed;
	int i, j, k, num, *selectedList;
	vector<int> listFaces;
	vector<vector<int> > groups;
	IwPolyFace *face;
	IwTA<IwPolyFace *> path;
	IwTA<IwTA<IwPolyFace *> > iwFacesOrdered;
	IwPolyEdge *edge;
	IwTA<IwPolyEdge *> pathEdge;
	IwTA<IwTA<IwPolyEdge *> > iwEdgesOrdered;

	// AnyClosedRingSelected 0x001: aristas, 0x010: caras
	if ( !force && !DirtyEdgeSel && faceOrEdge == ElementType::Edge ) return AnyClosedRingSelected & 0x001;
	else if ( !force && !DirtyFaceSel && faceOrEdge == ElementType::Face )
		return AnyClosedRingSelected & 0x010;

	if ( faces ) ( *faces ).RemoveAll( );
	if ( edges ) ( *edges ).RemoveAll( );

	if ( !GetPBrep( OGLTransf ) ) return false;

	if ( ( force || DirtyFaceSel ) && faceOrEdge == ElementType::Face ) {
		selectedList = GetFaces( OGLTransf, SelectedElementType::AllSelected, num );

		anyClosed = false;
		if ( num > 2 ) {
			path.RemoveAll( );
			for ( j = 0; j < num; j++ ) {
				face = GetPBrepFace( OGLTransf, selectedList[ j ] );
				if ( face ) path.Add( face );
			}

			GetDisjointGroupFaces( &path, &groups );
			for ( k = 0; k < (int) groups.size( ); k++ ) {
				ret = true;
				path.RemoveAll( );
				listFaces = groups.at( k );
				for ( j = 0; j < (int) listFaces.size( ); j++ ) {
					face = GetPBrepFace( OGLTransf, listFaces[ j ] );
					if ( face ) path.Add( face );
				}
				if ( !GetFacesOrdered( &path, &iwFacesOrdered ) ) ret = false;
				if ( ret && iwFacesOrdered.GetSize( ) != 1 ) ret = false;
				if ( ret && IsClosedPath( &iwFacesOrdered[ 0 ] ) ) {
					ret = true;
					anyClosed = true;
				} else
					ret = false;

				if ( ret && faces ) ( *faces ).Add( iwFacesOrdered[ 0 ] );
			}
		}

		if ( selectedList ) delete[] selectedList;

		AnyClosedRingSelected = anyClosed || ( faces ? ( *faces ).GetSize( ) : false ) ? 0x010 : 0;
		SetDirtyFaceSelection( false );
	}
	if ( ( force || DirtyEdgeSel ) && faceOrEdge == ElementType::Edge ) {
		if ( !GetDisjointGroupEdges( OGLTransf, &groups ) ) return false;
		if ( !groups.size( ) ) return 0;

		anyClosed = false;
		if ( groups.size( ) > 0 ) {
			pathEdge.RemoveAll( );
			for ( i = 0; i < (int) groups.size( ); i++ ) {
				if ( groups[ i ].size( ) < 3 ) continue;
				ret = true;
				pathEdge.RemoveAll( );
				for ( j = 0; j < (int) groups[ i ].size( ); j++ ) {
					edge = GetPBrepEdge( OGLTransf, groups[ i ][ j ] );
					if ( edge ) pathEdge.Add( edge );
				}
				if ( !GetEdgesOrdered( &pathEdge, &iwEdgesOrdered ) ) ret = false;
				if ( ret && iwEdgesOrdered.GetSize( ) != 1 ) ret = false;
				if ( ret && IsClosedPath( &iwEdgesOrdered[ 0 ] ) ) {
					anyClosed = true;
					if ( edges ) {
						// Convertimos las aristas en sus simetricas si no estan en la lista
						for ( k = 0; k < (int) iwEdgesOrdered[ 0 ].GetSize( ); k++ ) {
							if ( iwEdgesOrdered[ 0 ][ k ]->GetUserIndex1( ) == ULONG_MAX ) iwEdgesOrdered[ 0 ].SetAt( k, iwEdgesOrdered[ 0 ][ k ]->GetSymmetricPolyEdge( ) );
						}
						( *edges ).Add( iwEdgesOrdered[ 0 ] );
					}
				}
			}
		}

		AnyClosedRingSelected = anyClosed || ( edges ? ( *edges ).GetSize( ) : false ) ? 0x001 : 0;
		SetDirtyEdgeSelection( false );
	}

	return AnyClosedRingSelected;
}

//---------------------------------------------------------------------------

void TPBrepData::SetVertexWeight( TOGLTransf *OGLTransf, int index, double w )
{
	if ( !GetPBrep( OGLTransf ) ) return;

	SelectedV[ index ].d = w;
}

//---------------------------------------------------------------------------

double TPBrepData::GetVertexWeight( TOGLTransf *OGLTransf, int index )
{
	if ( !GetPBrep( OGLTransf ) ) return 0.0;

	return SelectedV[ index ].d;
}

//---------------------------------------------------------------------------

void TPBrepData::InitIndexSelected( )
{
	int i, nvertexs, nedges, nfaces;

	nvertexs = (int) PBrepVertexs.GetSize( );
	if ( SelectedV ) delete[] SelectedV;
	SelectedV = nvertexs > 0 ? new intdouble[ nvertexs ] : 0;
	for ( i = 0; i < nvertexs; i++ ) {
		SelectedV[ i ].i = 0;
		SelectedV[ i ].d = 0;
		PBrepVertexs[ i ]->SetIndexExt( i );
	}

	nedges = (int) PBrepEdges.GetSize( );
	if ( SelectedE ) delete[] SelectedE;
	SelectedE = nedges > 0 ? new int[ nedges ] : 0;
	for ( i = 0; i < nedges; i++ ) {
		SelectedE[ i ] = 0;
	}

	nfaces = (int) PBrepFaces.GetSize( );
	if ( SelectedF ) delete[] SelectedF;
	SelectedF = nfaces > 0 ? new intdouble[ nfaces ] : 0;
	for ( i = 0; i < nfaces; i++ ) {
		SelectedF[ i ].i = 0;
		SelectedF[ i ].d = 0;
		PBrepFaces[ i ]->SetIndexExt( i );
	}
	AnyClosedRingSelected = 0;
	SetDirtyFaceSelection( false );
	SetDirtyEdgeSelection( false );
}

//---------------------------------------------------------------------------

void TPBrepData::SetCompareMask( int value )
{
	CompareMask = value;
}

//---------------------------------------------------------------------------

int TPBrepData::GetCompareMask( )
{
	return CompareMask;
}

//---------------------------------------------------------------------------

void TPBrepData::SetRepairTol( double value )
{
	RepairTol = value;
}

//---------------------------------------------------------------------------

double TPBrepData::GetRepairTol( )
{
	return RepairTol;
}

//---------------------------------------------------------------------------

bool TPBrepData::GetPBrepPolListRelF( TOGLTransf *OGLTransf, int i, int &numPol, int &numFace, int &numVert )
{
	if ( !GetPBrep( OGLTransf ) || i < 0 || i >= (int) PBrepPolListRelF.size( ) ) {
		numPol = numFace = numVert = -1;
		return false;
	}
	numPol = PBrepPolListRelF[ i ].i0;
	numFace = PBrepPolListRelF[ i ].i1;
	numVert = PBrepPolListRelF[ i ].i2;
	return true;
}

//---------------------------------------------------------------------------

bool TPBrepData::AreTrianglesForced( )
{
	return ( RefEnt ? RefEnt->GetPBrepTrianglesForced( ) : true );
}

//------------------------------------------------------------------------------

void TPBrepData::UpdateNormalsOGLListFromPBrep( TOGLTransf *OGLTransf, TOGLPolygonList *OGLList, bool onlyinvalids )
{
	int i, j;
	vector<TOGLPoint> tempv, vaux;
	vector<GLint> tempvi;
	vector<int> tempvn;
	TOGLPoint oglpt;
	TOGLPolygon pol;
	TOGLPolygonList *ptrOGLList, auxOGLList;
	TInteger_ListList *auxInfoList;

	if ( !OGLTransf || !RefEnt ) return;

	if ( OGLList ) ptrOGLList = OGLList;
	else
		ptrOGLList = RefEnt->GetOGLGeom3D( OGLTransf );

	if ( onlyinvalids ) {
		if ( !RefEnt->GetOGLRenderData( )->Smooth || ( ToMesh( RefEnt ) && ToMesh( RefEnt )->HasSubdivisionDepMesh( ) ) ) ptrOGLList->CalculateNormal( plNone, onlyinvalids );
	} else
		ptrOGLList->CalculateNormal( plNone, onlyinvalids );

	if ( !RefEnt->GetOGLRenderData( )->Smooth ) return;
	if ( ToMesh( RefEnt ) && ToMesh( RefEnt )->HasSubdivisionDepMesh( ) ) return;

	auxInfoList = ToMesh( RefEnt ) ? ToMesh( RefEnt )->GetAuxInfoList( ) : 0;
	if ( auxInfoList && auxInfoList->Count( ) == ptrOGLList->Count( ) && PBrep ) {
		for ( i = 0; i < auxInfoList->Count( ); i++ ) {
			pol.Clear( );
			for ( j = 0; j < auxInfoList->GetItem( i )->Count( ); j += 3 ) {
				oglpt.t.v[ 0 ] = *( ToMesh( RefEnt )->GetAuxInfoList( )->GetItem( i )->GetItem( j ) );
				oglpt.t.v[ 1 ] = *( ToMesh( RefEnt )->GetAuxInfoList( )->GetItem( i )->GetItem( j + 1 ) );
				pol.AddItem( &oglpt );
			}
			auxOGLList.Add( &pol );
		}
		ptrOGLList->GetPolygonsCoords( &tempv, &tempvi, &tempvn, CMASK_V, false, 0.0001, 0, 0, &auxOGLList, &vaux, 2 );
	} else
		ptrOGLList->GetPolygons( &tempv, &tempvi, &tempvn, CMASK_V, false, 0.0001, 0, 0 );

	ptrOGLList->UnifyNormals( RefEnt->GetOGLRenderData( )->Smooth_MaxDegAngle, false, &tempv, &tempvi, CMASK_V, onlyinvalids );
}

//------------------------------------------------------------------------------

void TPBrepData::UpdateOGLListAuxInfoList( TOGLTransf *OGLTransf )
{
	int i, j, k, size_faces, size_vertices;
	IwTA<IwPolyVertex *> verticesFaces;
	IwPolyVertex *vertex;
	IwTA<IwPolyFace *> faces;
	IwPolyFace *face;
	TInteger_List list;

	if ( !ToMesh( RefEnt ) || !ToMesh( RefEnt )->IsPolygonalMesh( ) ) return;
	if ( !GetPBrep( OGLTransf ) || !PBrep ) return;

	ToMesh( RefEnt )->GetAuxInfoList( true )->Clear( );
	PBrep->GetPolyFaces( faces );
	size_faces = faces.GetSize( );
	for ( i = 0; i < size_faces; i++ ) {
		face = faces[ i ]; // face = faces.GetAt( i );
		face->GetPolyVertices( verticesFaces );
		size_vertices = verticesFaces.GetSize( );
		for ( j = 0; j < size_vertices; j++ ) {
			vertex = verticesFaces[ j ]; // vertex = verticesFaces.GetAt( j );
			k = vertex->GetIndexExt( );	 // Usado para diferenciar los vertices iguales en la lowpoly de la subdivision y que el sew no los una
			list.AddItem( &k );
			k = 0;
			list.AddItem( &k );
			k = 0;
			list.AddItem( &k );
		}
		ToMesh( RefEnt )->GetAuxInfoList( )->AddItem( &list );
		list.Clear( );
	}
}

//------------------------------------------------------------------------------

void TPBrepData::UpdateOGLListFromPBrep( TOGLTransf *OGLTransf, TOGLPolygonList *OGLList, bool checkselected, bool calcnormals, bool updateuvandtexcoords, bool recalcTopology )
{
	bool ispolygonalmesh;
	int i0, i1, i, j, k, incr, size_faces, size_vertices;
	int3 relation;
	IwTA<IwPolyVertex *> vertexs, verticesFaces;
	IwPolyVertex *vertex;
	IwTA<IwPolyFace *> faces;
	IwPolyFace *face;
	TOGLPoint *oglPt, oglPt2;
	TOGLPolygon *pol, pol2;
	IwVector2d uv;
	IwVector3d pt, tex;
	T3DVector n;
	TInteger_List list;

	if ( !GetPBrep( OGLTransf ) || !PBrep ) return;
	if ( !OGLList ) return;

	if ( AreTrianglesForced( ) && !OGLList->AreTriangles( ) ) recalcTopology = true;

	if ( recalcTopology ) {
		if ( debug ) WriteSections( L"c:\\temp\\1.asc", L"w", OGLList );

		OGLList->Clear( );
		ispolygonalmesh = ToMesh( RefEnt ) && ToMesh( RefEnt )->IsPolygonalMesh( );

		if ( ispolygonalmesh ) ToMesh( RefEnt )->GetAuxInfoList( true )->Clear( );

		PBrep->GetPolyFaces( faces );
		size_faces = faces.GetSize( );

		pol2.Clear( );
		pol2.SetType( GL_TRIANGLES );

		for ( i = 0; i < size_faces; i++ ) {
			face = faces[ i ]; // face = faces.GetAt( i );
			face->GetPolyVertices( verticesFaces );
			size_vertices = verticesFaces.GetSize( );
			for ( j = 0; j < size_vertices; j++ ) {
				vertex = verticesFaces[ j ]; // vertex = verticesFaces.GetAt( j );
				oglPt2.v.v[ 0 ] = vertex->GetPoint( ).x;
				oglPt2.v.v[ 1 ] = vertex->GetPoint( ).y;
				oglPt2.v.v[ 2 ] = vertex->GetPoint( ).z;

				//				int ojo; // parece razonable dejarlo
				if ( updateuvandtexcoords ) {
					oglPt2.uv.v[ 0 ] = vertex->GetUV( ).x;
					oglPt2.uv.v[ 1 ] = vertex->GetUV( ).y;
					oglPt2.t.v[ 0 ] = vertex->GetTexture( ).x;
					oglPt2.t.v[ 1 ] = vertex->GetTexture( ).y;
				}

				if ( ispolygonalmesh ) {
					k = vertex->GetIndexExt( ); // Usado para diferenciar los vertices iguales en la lowpoly de la subdivision y que el sew no los una
					list.AddItem( &k );
					k = 0;
					list.AddItem( &k );
					k = 0;
					list.AddItem( &k );
				}

				pol2.AddItem( &oglPt2 );
			}

			if ( size_vertices == 3 ) pol2.SetType( GL_TRIANGLES );
			else if ( size_vertices == 4 )
				pol2.SetType( GL_QUADS );
			else if ( size_vertices > 4 )
				pol2.SetType( GL_POLYGON );

			if ( ispolygonalmesh ) {
				ToMesh( RefEnt )->GetAuxInfoList( )->AddItem( &list );
				list.Clear( );
			}

			if ( calcnormals ) pol2.SetUseNormals( true );
			pol2.SetUseTextures( true );
			OGLList->Add( &pol2 );
			pol2.Clear( );
		}

		// Creamos la relación de nuevo
		PBrepPolListRelF.clear( );
		for ( i = 0; i < OGLList->Count( ); i++ ) {
			pol = OGLList->GetItem( i );
			if ( !pol ) continue;

			relation.i0 = i;
			k = -1;
			// Si un polígno tiene varios polígnos dentro sólo se pueden separar en triángulos
			size_vertices = pol->Count( );
			if ( pol->GetType( ) == GL_TRIANGLES ) incr = 3;
			else if ( pol->GetType( ) == GL_QUADS )
				incr = 4;
			else
				incr = size_vertices;
			for ( j = 0; j < size_vertices; j += incr ) {
				k++;
				relation.i1 = k;
				relation.i2 = incr;
				PBrepPolListRelF.push_back( relation );
			}
		}

		UpdateOGLListSeamFromPBrep( OGLTransf );
		UpdateOGLListCreasesFromPBrep( OGLTransf );

		if ( debug ) WriteSections( L"c:\\temp\\2.asc", L"w", OGLList );

	} else {
		if ( AreTrianglesForced( ) ) {
			///////////////////////Nuevo JC 11/2021, para no tocar la lista
			if ( !OGLList->AreTriangles( ) )
				//////////////////////////////////////
				OGLList->ConvertToTriangles( 0, MULTI_POLYGON, CompareMask );
		} /* else
			OGLList->ConvertToPolygons( 0, CompareMask, ToMesh( RefEnt )->GetPBrepIndexes( ), 0, true );*/

		size_faces = (int) PBrepPolListRelF.size( );
		for ( i = 0; i < size_faces; i++ ) {
			PBrepFaces[ i ]->GetPolyVertices( vertexs );
			size_vertices = vertexs.GetSize( );
			i0 = PBrepPolListRelF[ i ].i0;
			i1 = PBrepPolListRelF[ i ].i1 * size_vertices;
			pol = OGLList->GetItem( i0 );
			if ( !pol ) continue;
			for ( j = 0; j < size_vertices; j++ ) { // CUIDADO: vértice marcado por edición proporcional.
				if ( !checkselected || IsVertexSelected( OGLTransf, vertexs[ j ]->GetIndexExt( ) ) || vertexs[ j ]->GetUserIndex1( ) == 1 ) {
					oglPt = pol->GetItem( i1 + j );
					pt = vertexs[ j ]->GetPoint( );
					oglPt->v.Set( pt.x, pt.y, pt.z );
					if ( updateuvandtexcoords ) {
						uv = vertexs[ j ]->GetUV( );
						oglPt->uv.Set( uv.x, uv.y );
						tex = vertexs[ j ]->GetTexture( );
						oglPt->t.Set( tex.x, tex.y );
					}
				}
			}
		}

		if ( calcnormals && RefEnt && !RefEnt->GetLockNormals( ) ) UpdateNormalsOGLListFromPBrep( OGLTransf, OGLList );
	}

	OGLList->Download( );
}

//------------------------------------------------------------------------------

void TPBrepData::UpdatePBrepFromOGLList( TOGLTransf *OGLTransf, TOGLPolygonList *OGLList, bool checkselected, bool updatenormals, bool updateuvandtexcoords )
{
	int i0, i1, i, j, size_faces, size_vertices;
	IwTA<IwPolyVertex *> vertexs;
	TOGLPoint *oglPt;
	TOGLPolygon *pol;
	IwVector2d uv;
	IwVector3d vertex, tex;

	if ( !GetPBrep( OGLTransf ) ) return;
	if ( !OGLList ) return;

	if ( AreTrianglesForced( ) ) {
		///////////////////////Nuevo JC 11/2021, para no tocar la lista
		if ( !OGLList->AreTriangles( ) )
			//////////////////////////////////////
			OGLList->ConvertToTriangles( 0, MULTI_POLYGON, CompareMask );
	}

	size_faces = (int) PBrepPolListRelF.size( );
	for ( i = 0; i < size_faces; i++ ) {
		PBrepFaces[ i ]->GetPolyVertices( vertexs );
		size_vertices = vertexs.GetSize( );
		i0 = PBrepPolListRelF[ i ].i0;
		i1 = PBrepPolListRelF[ i ].i1 * size_vertices;
		pol = OGLList->GetItem( i0 );
		if ( !pol ) continue;
		for ( j = 0; j < size_vertices; j++ ) {
			if ( !checkselected || IsVertexSelected( OGLTransf, vertexs[ j ]->GetIndexExt( ) ) ) {
				oglPt = pol->GetItem( i1 + j );
				vertex.x = oglPt->v.v[ 0 ];
				vertex.y = oglPt->v.v[ 1 ];
				vertex.z = oglPt->v.v[ 2 ];
				vertexs[ j ]->SetPoint( vertex );
				if ( updateuvandtexcoords ) {
					uv.x = oglPt->uv.v[ 0 ];
					uv.y = oglPt->uv.v[ 1 ];
					vertexs[ j ]->SetUV( uv );
					tex.x = oglPt->t.v[ 0 ];
					tex.y = oglPt->t.v[ 1 ];
					tex.z = vertexs[ j ]->GetTexture( ).z;
					vertexs[ j ]->SetTexture( tex );
				}
			}
		}
		if ( updatenormals ) PBrepFaces[ i ]->GetNormal( true );
	}

	UpdatePBrepSeamFromOGLList( OGLTransf );
	UpdatePBrepCreasesFromOGLList( OGLTransf );

	OGLList->Download( );
}

//------------------------------------------------------------------------------

void TPBrepData::UpdateColorsFromSelection( TOGLTransf *OGLTransf )
{
	if ( ToMesh( RefEnt ) ) {
		if ( ToMesh( RefEnt )->HasSubdivisionDepMesh( ) && !RefEnt->GetDepMeshes( )->GetShape( 0 )->GetPolygonDirty( ) ) {
			if ( RefEnt->GetDepMeshes( )->GetShape( 0 )->GetOGLRenderData( )->CountColors( ) != RefEnt->GetDepMeshes( )->GetShape( 0 )->GetOGLList( OGLTransf )->Count( ) ) RefEnt->GetDepMeshes( )->GetShape( 0 )->GetOGLRenderData( )->SetColors( RefEnt->GetDepMeshes( )->GetShape( 0 )->GetOGLList( OGLTransf ) );
			RefEnt->GetDepMeshes( )->GetShape( 0 )->Download( );
		}
		UpdateColor( OGLTransf, -1, SelectedElementType::All );
	}
}

//------------------------------------------------------------------------------

void TPBrepData::UpdateColorsFromPBrep( TOGLTransf *OGLTransf, TOGLPolygonList *OGLColorList, TColor *cIni, TColor *cEnd )
{
	int i0, i1, i, j, size_faces, size_vertices;
	float rIni, gIni, bIni, rEnd, gEnd, bEnd;
	double weight;
	IwTA<IwPolyVertex *> vertexs;
	TOGLPoint *oglpt;
	TOGLPolygon *pol;

	if ( !GetPBrep( OGLTransf ) ) return;
	if ( !OGLColorList ) return;

	rIni = ( (float) GetRValue( ColorToRGB( *cIni ) ) );
	gIni = ( (float) GetGValue( ColorToRGB( *cIni ) ) );
	bIni = ( (float) GetBValue( ColorToRGB( *cIni ) ) );

	rEnd = ( (float) GetRValue( ColorToRGB( *cEnd ) ) );
	gEnd = ( (float) GetGValue( ColorToRGB( *cEnd ) ) );
	bEnd = ( (float) GetBValue( ColorToRGB( *cEnd ) ) );

	size_faces = (int) PBrepPolListRelF.size( );
	for ( i = 0; i < size_faces; i++ ) {
		PBrepFaces[ i ]->GetPolyVertices( vertexs );
		size_vertices = vertexs.GetSize( );
		i0 = PBrepPolListRelF[ i ].i0;
		i1 = PBrepPolListRelF[ i ].i1 * size_vertices;
		pol = OGLColorList->GetItem( i0 );
		if ( !pol ) continue;
		for ( j = 0; j < size_vertices; j++ ) {
			oglpt = pol->GetItem( i1 + j );
			weight = SelectedV[ vertexs[ j ]->GetIndexExt( ) ].d;

			// aumentamos la intensidad del color final
			if ( weight > RES_COMP2 ) weight = ( sqrt( weight ) + weight ) / 2.0;

			if ( weight < 0.0 ) weight = 0.0;
			else if ( weight > 1.0 )
				weight = 1.0;

			oglpt->v.Set( rIni * ( 1 - weight ) + rEnd * weight, gIni * ( 1 - weight ) + gEnd * weight, bIni * ( 1 - weight ) + bEnd * weight );
		}
	}

	OGLColorList->Download( );
}

//---------------------------------------------------------------------------

void TPBrepData::UpdateColorsForProportionalEditing( TOGLTransf *OGLTransf, TOGLPolygonList *OGLColorList, TColor *cIni, TColor *cEnd )
{
	int i0, i1, i, j, size_faces, size_vertices;
	float rIni, gIni, bIni, rEnd, gEnd, bEnd;
	double weight;
	IwTA<IwPolyVertex *> vertexs;
	TOGLPoint *oglpt;
	TOGLPolygon *pol;

	if ( !GetPBrep( OGLTransf ) ) return;
	if ( !OGLColorList ) return;

	rIni = ( (float) GetRValue( ColorToRGB( *cIni ) ) );
	gIni = ( (float) GetGValue( ColorToRGB( *cIni ) ) );
	bIni = ( (float) GetBValue( ColorToRGB( *cIni ) ) );

	rEnd = ( (float) GetRValue( ColorToRGB( *cEnd ) ) );
	gEnd = ( (float) GetGValue( ColorToRGB( *cEnd ) ) );
	bEnd = ( (float) GetBValue( ColorToRGB( *cEnd ) ) );

	size_faces = (int) PBrepPolListRelF.size( );
	for ( i = 0; i < size_faces; i++ ) {
		if ( PBrepFaces[ i ]->GetUserIndex1( ) == 0 ) continue;
		PBrepFaces[ i ]->GetPolyVertices( vertexs );
		size_vertices = vertexs.GetSize( );
		i0 = PBrepPolListRelF[ i ].i0;
		i1 = PBrepPolListRelF[ i ].i1 * size_vertices;
		pol = OGLColorList->GetItem( i0 );
		if ( !pol ) continue;
		weight = 0;
		if ( !RefEnt->GetOGLRenderData( )->Smooth ) {
			for ( j = 0; j < size_vertices; j++ ) {
				if ( vertexs[ j ]->GetPointExt( ).x > 0.0 && vertexs[ j ]->GetPointExt( ).x <= 1 ) weight += vertexs[ j ]->GetPointExt( ).x;
				else
					weight += SelectedV[ vertexs[ j ]->GetIndexExt( ) ].d;
			}
			weight = weight / size_vertices;
			// aumentamos la intensidad del color final
			if ( weight > RES_COMP2 ) weight = ( sqrt( weight ) + weight ) / 2.0;

			if ( weight < 0.0 ) weight = 0.0;
			else if ( weight > 1.0 )
				weight = 1.0;

			for ( j = 0; j < size_vertices; j++ ) {
				oglpt = pol->GetItem( i1 + j );
				oglpt->v.Set( rIni * ( 1 - weight ) + rEnd * weight, gIni * ( 1 - weight ) + gEnd * weight, bIni * ( 1 - weight ) + bEnd * weight );
			}

		} else {
			for ( j = 0; j < size_vertices; j++ ) {
				oglpt = pol->GetItem( i1 + j );
				if ( vertexs[ j ]->GetPointExt( ).x > 0.0 && vertexs[ j ]->GetPointExt( ).x <= 1 ) weight = vertexs[ j ]->GetPointExt( ).x;
				else
					weight = SelectedV[ vertexs[ j ]->GetIndexExt( ) ].d;

				// aumentamos la intensidad del color final
				if ( weight > RES_COMP2 ) weight = ( sqrt( weight ) + weight ) / 2.0;

				if ( weight < 0.0 ) weight = 0.0;
				else if ( weight > 1.0 )
					weight = 1.0;

				oglpt->v.Set( rIni * ( 1 - weight ) + rEnd * weight, gIni * ( 1 - weight ) + gEnd * weight, bIni * ( 1 - weight ) + bEnd * weight );
			}
		}
	}
}

//---------------------------------------------------------------------------

void TPBrepData::UpdateNormalsFromPBrep( TOGLTransf *OGLTransf, TOGLPolygonList *OGLList )
{
	if ( !GetPBrep( OGLTransf ) ) return;
	if ( !OGLList ) return;
	if ( RefEnt && RefEnt->GetLockNormals( ) ) return;

	UpdateNormalsOGLListFromPBrep( OGLTransf, OGLList );
	OGLList->Download( );
}

//---------------------------------------------------------------------------

TOGLPolygon *TPBrepData::GetOGLDataFromPolyFace( TOGLTransf *OGLTransf, TOGLPolygonList *OGLList, IwPolyFace *iwPolyFace, int &index )
{
	int index1, a, b, i0;
	TOGLPolygon *pol;

	if ( iwPolyFace == NULL || OGLList == NULL ) return 0;

	GetPBrepPolListRelF( OGLTransf, iwPolyFace->GetIndexExt( ), index1, a, b );
	if ( index1 < 0 ) return 0;

	i0 = PBrepPolListRelF[ index1 ].i0;
	index = i0;
	pol = OGLList->GetItem( i0 );
	return pol;
}

//---------------------------------------------------------------------------

IwTA<IwPolyFace *> TPBrepData::GetPolyFacesFromOGLPolygon( TOGLTransf *OGLTransf, TOGLPolygonList *OGLList, int iPosPolygon )
{
	ULONG uli;
	IwPolyFace *iwFace;
	IwTA<IwPolyFace *> liwFaces;

	if ( iPosPolygon < 0 || OGLList == NULL || OGLList->Count( ) <= iPosPolygon ) return liwFaces;
	if ( !GetPBrep( OGLTransf ) || iPosPolygon < 0 || iPosPolygon >= (int) PBrepPolListRelF.size( ) ) return liwFaces;
	for ( uli = 0; uli < PBrepPolListRelF.size( ); uli++ )
		if ( PBrepPolListRelF[ uli ].i0 == iPosPolygon ) {
			iwFace = GetPBrepFace( OGLTransf, uli );
			if ( iwFace ) liwFaces.Add( iwFace );
		}

	return liwFaces;
}

//---------------------------------------------------------------------------
//------------------------------------------------------------------------------

T3DPoint *TPBrepData::GetPoints( TOGLTransf *OGLTransf, int &np )
{
	int i;
	T3DPoint *pts;
	IwVector3d iwpt;

	if ( !GetPBrep( OGLTransf ) ) return 0;

	np = PBrepVertexs.GetSize( );

	pts = new T3DPoint[ np ];
	for ( i = 0; i < np; i++ ) {
		iwpt = PBrepVertexs[ i ]->GetPoint( );
		pts[ i ].x = iwpt.x;
		pts[ i ].y = iwpt.y;
		pts[ i ].z = iwpt.z;
	}

	return pts;
}

//------------------------------------------------------------------------------

bool TPBrepData::GetAllFromOGLList( TOGLTransf *OGLTransf, int &np, TOGLPolygonList *OGLList, T3DPoint **points, T3DPoint **pointsuv, T3DPoint **normals )
{
	bool *used;
	int i0, i1, i, j, ind, size_faces, size_vertices;
	IwTA<IwPolyVertex *> vertexs;
	TOGLPoint *oglpt;
	TOGLPolygon *pol;
	IwVector3d vertex;

	np = 0;
	( *points ) = 0;
	( *pointsuv ) = 0;
	( *normals ) = 0;

	if ( !GetPBrep( OGLTransf ) ) return false;

	np = PBrepVertexs.GetSize( );
	if ( !np ) return 0;
	used = new bool[ np ];
	( *points ) = new T3DPoint[ np ];
	( *pointsuv ) = new T3DPoint[ np ];
	( *normals ) = new T3DPoint[ np ];
	for ( i = 0; i < np; i++ )
		used[ i ] = false;

	size_faces = (int) PBrepPolListRelF.size( );
	for ( i = 0; i < size_faces; i++ ) {
		PBrepFaces[ i ]->GetPolyVertices( vertexs );
		size_vertices = vertexs.GetSize( );
		i0 = PBrepPolListRelF[ i ].i0;
		i1 = PBrepPolListRelF[ i ].i1 * size_vertices;
		pol = OGLList->GetItem( i0 );
		if ( !pol ) continue;
		for ( j = 0; j < size_vertices; j++ ) {
			ind = vertexs[ j ]->GetIndexExt( );
			if ( used[ ind ] ) continue;
			oglpt = pol->GetItem( i1 + j );
			if ( !oglpt ) continue;
			used[ ind ] = true;
			( *points )[ ind ] = oglpt->v.GetPoint( );
			( *pointsuv )[ ind ] = oglpt->uv.Get3DPoint( ); // T3DPoint( extra->u, extra->v, 0.0 );
			( *normals )[ ind ] = oglpt->n.GetPoint( );
		}
	}

	for ( i = 0; i < np; i++ )
		if ( !used[ i ] ) {
			delete[] used;
			delete[]( *points );
			( *points ) = 0;
			delete[]( *pointsuv );
			( *pointsuv ) = 0;
			delete[]( *normals );
			( *normals ) = 0;
			np = 0;
			return false;
		}

	delete[] used;

	return true;
}

//------------------------------------------------------------------------------

T3DPoint *TPBrepData::GetPointsFromOGLList( TOGLTransf *OGLTransf, int &np, TOGLPolygonList *OGLList )
{
	bool *used;
	int i0, i1, i, j, ind, size_faces, size_vertices;
	T3DPoint *pts;
	IwTA<IwPolyVertex *> vertexs;
	TOGLPoint *oglpt;
	TOGLPolygon *pol;
	IwVector3d vertex;

	if ( !GetPBrep( OGLTransf ) ) return 0;

	np = PBrepVertexs.GetSize( );
	if ( !np ) return 0;
	used = new bool[ np ];
	pts = new T3DPoint[ np ];
	for ( i = 0; i < np; i++ )
		used[ i ] = false;

	size_faces = (int) PBrepPolListRelF.size( );
	for ( i = 0; i < size_faces; i++ ) {
		PBrepFaces[ i ]->GetPolyVertices( vertexs );
		size_vertices = vertexs.GetSize( );
		i0 = PBrepPolListRelF[ i ].i0;
		i1 = PBrepPolListRelF[ i ].i1 * size_vertices;
		pol = OGLList->GetItem( i0 );
		if ( !pol ) continue;
		for ( j = 0; j < size_vertices; j++ ) {
			ind = vertexs[ j ]->GetIndexExt( );
			if ( used[ ind ] ) continue;
			oglpt = pol->GetItem( i1 + j );
			if ( !oglpt ) continue;
			used[ ind ] = true;
			pts[ ind ] = oglpt->v.GetPoint( );
		}
	}

	for ( i = 0; i < np; i++ )
		if ( !used[ i ] ) {
			delete[] used;
			delete[] pts;
			np = 0;
			return 0;
		}

	delete[] used;

	return pts;
}

//------------------------------------------------------------------------------

T3DPoint *TPBrepData::GetPointsUVFromOGLList( TOGLTransf *OGLTransf, int &np, TOGLPolygonList *OGLList )
{
	bool *used;
	int i0, i1, i, j, ind, size_faces, size_vertices;
	T3DPoint *ptsuv;
	IwTA<IwPolyVertex *> vertexs;
	TOGLPoint *oglpt;
	TOGLPolygon *pol;
	IwVector3d vertex;

	if ( !GetPBrep( OGLTransf ) ) return 0;

	np = PBrepVertexs.GetSize( );
	if ( !np ) return 0;
	used = new bool[ np ];
	ptsuv = new T3DPoint[ np ];
	for ( i = 0; i < np; i++ )
		used[ i ] = false;

	size_faces = (int) PBrepPolListRelF.size( );
	for ( i = 0; i < size_faces; i++ ) {
		PBrepFaces[ i ]->GetPolyVertices( vertexs );
		size_vertices = vertexs.GetSize( );
		i0 = PBrepPolListRelF[ i ].i0;
		i1 = PBrepPolListRelF[ i ].i1 * size_vertices;
		pol = OGLList->GetItem( i0 );
		if ( !pol ) continue;
		for ( j = 0; j < size_vertices; j++ ) {
			ind = vertexs[ j ]->GetIndexExt( );
			if ( used[ ind ] ) continue;
			oglpt = pol->GetItem( i1 + j );
			if ( !oglpt ) continue;
			used[ ind ] = true;
			ptsuv[ ind ].x = oglpt->uv.v[ 0 ];
			ptsuv[ ind ].y = oglpt->uv.v[ 1 ];
		}
	}

	for ( i = 0; i < np; i++ )
		if ( !used[ i ] ) {
			delete[] used;
			delete[] ptsuv;
			np = 0;
			return 0;
		}

	delete[] used;

	return ptsuv;
}

//------------------------------------------------------------------------------

void TPBrepData::SetPointsToOGLList( TOGLTransf *OGLTransf, int np, T3DPoint *pts, TOGLPolygonList *OGLList, bool locknormals )
{
	bool recalcnormals, updatenormals;
	int i0, i1, i, j, ind, size_faces, size_vertices;
	IwTA<IwPolyVertex *> vertexs;
	TOGLPoint *oglpt;
	TOGLPolygon *pol;

	if ( !GetPBrep( OGLTransf ) ) return;
	if ( !PBrepVertexs.GetSize( ) ) return;

	recalcnormals = ( !locknormals && RefEnt && !RefEnt->GetLockNormals( ) );
	updatenormals = false;

	size_faces = (int) PBrepPolListRelF.size( );
	for ( i = 0; i < size_faces; i++ ) {
		PBrepFaces[ i ]->GetPolyVertices( vertexs );
		size_vertices = vertexs.GetSize( );
		i0 = PBrepPolListRelF[ i ].i0;
		i1 = PBrepPolListRelF[ i ].i1 * size_vertices;
		pol = OGLList->GetItem( i0 );
		if ( !pol ) continue;
		for ( j = 0; j < size_vertices; j++ ) {
			ind = vertexs[ j ]->GetIndexExt( );
			if ( ind < 0 || ind >= np ) continue;
			oglpt = pol->GetItem( i1 + j );
			if ( !oglpt ) continue;
			if ( recalcnormals ) {
				if ( fabs( oglpt->v.v[ 0 ] - pts[ ind ].x ) > RES_GEOM || fabs( oglpt->v.v[ 1 ] - pts[ ind ].y ) > RES_GEOM || fabs( oglpt->v.v[ 2 ] - pts[ ind ].z ) > RES_GEOM ) {
					oglpt->n.Set( 0.0, 0.0, 0.0 );
					updatenormals = true;
				} else if ( fabs( oglpt->n.v[ 0 ] ) < RES_COMP && fabs( oglpt->n.v[ 1 ] ) < RES_COMP && fabs( oglpt->n.v[ 2 ] ) < RES_COMP )
					updatenormals = true;
			}
			oglpt->v.v[ 0 ] = pts[ ind ].x;
			oglpt->v.v[ 1 ] = pts[ ind ].y;
			oglpt->v.v[ 2 ] = pts[ ind ].z;
		}
	}

	if ( debug ) {
		WriteTrianglesSTL( L"c:\\temp\\ogllist.stl", OGLList );
	}

	if ( recalcnormals && updatenormals ) {
		// tenemos que recalcular todas las normales en el que caso de que haya aristas marcadas
		if ( ToMesh( RefEnt ) && ToMesh( RefEnt )->GetAuxInfoList( ) && ToMesh( RefEnt )->GetAuxInfoList( )->Count( ) == OGLList->Count( ) ) UpdateNormalsOGLListFromPBrep( OGLTransf, OGLList );
		else if ( RefEnt->GetOGLRenderData( )->Smooth ) {
			OGLList->UnifyNormals( RefEnt->GetOGLRenderData( )->Smooth_MaxDegAngle, false, 0, 0, CMASK_V, true );
		} else
			OGLList->CalculateNormal( ); // tenemos que recalcular todas las normales pq no hay funcion para calcular solo esas
		OGLList->Download( );
	}
}

//------------------------------------------------------------------------------

T3DPoint *TPBrepData::GetNormalsFromOGLList( TOGLTransf *OGLTransf, int &np, TOGLPolygonList *OGLList )
{
	bool *used;
	int i0, i1, i, j, ind, size_faces, size_vertices;
	T3DPoint *normals;
	IwTA<IwPolyVertex *> vertexs;
	TOGLPoint *oglpt;
	IwVector3d vertex;

	if ( !GetPBrep( OGLTransf ) ) return 0;

	np = PBrepVertexs.GetSize( );
	if ( !np ) return 0;
	used = new bool[ np ];
	normals = new T3DPoint[ np ];
	for ( i = 0; i < np; i++ )
		used[ i ] = false;

	size_faces = (int) PBrepPolListRelF.size( );
	for ( i = 0; i < size_faces; i++ ) {
		PBrepFaces[ i ]->GetPolyVertices( vertexs );
		size_vertices = vertexs.GetSize( );
		i0 = PBrepPolListRelF[ i ].i0;
		i1 = PBrepPolListRelF[ i ].i1;
		if ( !OGLList->GetItem( i0 ) ) continue;
		for ( j = 0; j < size_vertices; j++ ) {
			ind = vertexs[ j ]->GetIndexExt( );
			if ( used[ ind ] ) continue;
			oglpt = OGLList->GetItem( i0 )->GetItem( i1 * size_vertices + j );
			if ( !oglpt ) continue;
			used[ ind ] = true;
			normals[ ind ] = oglpt->n.GetPoint( );
		}
	}

	for ( i = 0; i < np; i++ )
		if ( !used[ i ] ) {
			delete[] used;
			delete[] normals;
			np = 0;
			return 0;
		}

	delete[] used;

	return normals;
}

//------------------------------------------------------------------------------

void TPBrepData::SetNormalsToOGLList( TOGLTransf *OGLTransf, int np, T3DPoint *normals, TOGLPolygonList *OGLList )
{
	int i0, i1, i, j, ind, size_faces, size_vertices;
	IwTA<IwPolyVertex *> vertexs;
	TOGLPoint *oglpt;
	TOGLPolygon *pol;
	IwVector3d vertex;

	if ( !GetPBrep( OGLTransf ) ) return;

	size_faces = (int) PBrepPolListRelF.size( );
	for ( i = 0; i < size_faces; i++ ) {
		PBrepFaces[ i ]->GetPolyVertices( vertexs );
		size_vertices = vertexs.GetSize( );
		i0 = PBrepPolListRelF[ i ].i0;
		i1 = PBrepPolListRelF[ i ].i1 * size_vertices;
		pol = OGLList->GetItem( i0 );
		if ( !pol ) continue;
		for ( j = 0; j < size_vertices; j++ ) {
			ind = vertexs[ j ]->GetIndexExt( );
			if ( ind < 0 || ind >= np ) continue;
			oglpt = pol->GetItem( i1 + j );
			if ( !oglpt ) continue;
			oglpt->n.v[ 0 ] = normals[ ind ].x;
			oglpt->n.v[ 1 ] = normals[ ind ].y;
			oglpt->n.v[ 2 ] = normals[ ind ].z;
			//			oglpt->n.SetPoint( normals[ ind ] );
		}
	}
	OGLList->Download( );
}

//------------------------------------------------------------------------------

T3DPoint *TPBrepData::GetTextureCoordsFromOGLList( TOGLTransf *OGLTransf, int &np, TOGLPolygonList *OGLList )
{
	bool *used;
	int i0, i1, i, j, ind, size_faces, size_vertices;
	T3DPoint *ptstex;
	IwTA<IwPolyVertex *> vertexs;
	TOGLPoint *oglpt;
	TOGLPolygon *pol;
	IwVector3d vertex;

	if ( !GetPBrep( OGLTransf ) ) return 0;

	np = PBrepVertexs.GetSize( );
	if ( !np ) return 0;
	used = new bool[ np ];
	ptstex = new T3DPoint[ np ];
	for ( i = 0; i < np; i++ )
		used[ i ] = false;

	size_faces = (int) PBrepPolListRelF.size( );
	for ( i = 0; i < size_faces; i++ ) {
		PBrepFaces[ i ]->GetPolyVertices( vertexs );
		size_vertices = vertexs.GetSize( );
		i0 = PBrepPolListRelF[ i ].i0;
		i1 = PBrepPolListRelF[ i ].i1 * size_vertices;
		pol = OGLList->GetItem( i0 );
		if ( !pol ) continue;
		for ( j = 0; j < size_vertices; j++ ) {
			ind = vertexs[ j ]->GetIndexExt( );
			if ( used[ ind ] ) continue;
			oglpt = pol->GetItem( i1 + j );
			if ( !oglpt ) continue;
			used[ ind ] = true;
			ptstex[ ind ].x = oglpt->t.v[ 0 ];
			ptstex[ ind ].y = oglpt->t.v[ 1 ];
		}
	}

	for ( i = 0; i < np; i++ )
		if ( !used[ i ] ) {
			delete[] used;
			delete[] ptstex;
			np = 0;
			return 0;
		}

	delete[] used;

	return ptstex;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void TPBrepData::UnSelectAllFaces( TOGLTransf *OGLTransf, SelectedElementType selType, float a, bool onlySubdivision, bool onlyLowPoly )
{
	int i, count;

	if ( !GetPBrep( OGLTransf ) ) return;
	if ( !SelectedF || !RefEnt ) return;

	count = (int) PBrepPolListRelF.size( );
	for ( i = 0; i < count; i++ ) {
		SelectedF[ i ].i = 0;
		SelectedF[ i ].d = 0;
	}

	if ( ToMesh( RefEnt ) && ToMesh( RefEnt )->IsPolygonalMesh( ) ) UpdateColor( OGLTransf, -1, selType, 0, a, onlySubdivision, onlyLowPoly );

	AnyClosedRingSelected = 0;
	SetDirtyFaceSelection( false );
}

//---------------------------------------------------------------------------

void TPBrepData::SelectAllFaces( TOGLTransf *OGLTransf, SelectedElementType selType, float a, bool onlySubdivision, bool onlyLowPoly )
{
	int i, count;

	if ( !GetPBrep( OGLTransf ) ) return;
	if ( !SelectedF || !RefEnt ) return;

	count = (int) PBrepPolListRelF.size( );
	for ( i = 0; i < count; i++ ) {
		SelectedF[ i ].i = (int) selType;
		SelectedF[ i ].d = 1;
	}

	if ( ToMesh( RefEnt ) && ToMesh( RefEnt )->IsPolygonalMesh( ) ) UpdateColor( OGLTransf, -1, selType, 0, a, onlySubdivision, onlyLowPoly );

	AnyClosedRingSelected = 0;
	SetDirtyFaceSelection( false );
}

//---------------------------------------------------------------------------

void TPBrepData::SelectFace( TOGLTransf *OGLTransf, int ind, SelectedElementType selType, float a, bool onlySubdivision, bool onlyLowPoly, bool checkring )
{
	int ii, iNumFaces, *liFacesSelected;

	if ( !GetPBrep( OGLTransf ) ) return;
	if ( !SelectedF || !RefEnt ) return;
	if ( ind < 0 || ind >= (int) PBrepFaces.GetSize( ) ) return;

	if ( selType == SelectedElementType::LastUserSelection ) {
		// La penúltima pasa a ser una seleccionada más.
		liFacesSelected = GetFaces( OGLTransf, SelectedElementType::LastBeforeUserSelection, iNumFaces );
		if ( liFacesSelected ) {
			for ( ii = 0; ii < iNumFaces; ii++ ) {
				SelectedF[ liFacesSelected[ ii ] ].i = (int) SelectedElementType::UserSelection;
				if ( ToMesh( RefEnt ) && ToMesh( RefEnt )->IsPolygonalMesh( ) ) UpdateColor( OGLTransf, liFacesSelected[ ii ], SelectedElementType::UserSelection, 0, a, onlySubdivision, onlyLowPoly );
			}
			delete[] liFacesSelected;
		}

		// La última pasa a ser la penúltima.
		liFacesSelected = GetFaces( OGLTransf, SelectedElementType::LastUserSelection, iNumFaces );
		if ( liFacesSelected ) {
			for ( ii = 0; ii < iNumFaces; ii++ ) {
				SelectedF[ liFacesSelected[ ii ] ].i = (int) SelectedElementType::LastBeforeUserSelection;
				if ( ToMesh( RefEnt ) && ToMesh( RefEnt )->IsPolygonalMesh( ) ) UpdateColor( OGLTransf, liFacesSelected[ ii ], SelectedElementType::LastBeforeUserSelection, 0, a, onlySubdivision, onlyLowPoly );
			}
			delete[] liFacesSelected;
		}
	}

	SelectedF[ ind ].i = (int) selType;
	SelectedF[ ind ].d = 1;

	if ( ToMesh( RefEnt ) && ToMesh( RefEnt )->IsPolygonalMesh( ) ) {
		UpdateColor( OGLTransf, ind, selType, 0, a, onlySubdivision, onlyLowPoly );
		if ( checkring ) SetDirtyFaceSelection( true );
	}
}

//---------------------------------------------------------------------------

void TPBrepData::SelectFaces( TOGLTransf *OGLTransf, TInteger_List *indexes, SelectedElementType selType, float a, bool onlySubdivision, bool onlyLowPoly, bool checkring )
{
	int k, ind;

	if ( !GetPBrep( OGLTransf ) ) return;
	if ( !SelectedF || !RefEnt ) return;
	if ( !indexes || !indexes->Count( ) ) return;

	for ( k = 0; k < indexes->Count( ); k++ ) {
		ind = *( indexes->GetItem( k ) );
		SelectedF[ ind ].i = (int) selType;
		SelectedF[ ind ].d = 1;
	}

	if ( ToMesh( RefEnt ) && ToMesh( RefEnt )->IsPolygonalMesh( ) ) {
		UpdateColor( OGLTransf, -1, selType, indexes, a, onlySubdivision, onlyLowPoly );
		if ( checkring ) SetDirtyFaceSelection( true );
	}
}

//---------------------------------------------------------------------------

void TPBrepData::SelectFaces( TOGLTransf *OGLTransf, IwTA<IwPolyFace *> *faces, SelectedElementType selType, float a, bool onlySubdivision, bool onlyLowPoly, bool checkring )
{
	int k, ind;
	TInteger_List indexes;

	if ( !GetPBrep( OGLTransf ) ) return;
	if ( !SelectedF || !RefEnt ) return;
	if ( !faces || !faces->GetSize( ) ) return;

	for ( k = 0; k < (int) faces->GetSize( ); k++ ) {
		ind = faces->GetAt( k )->GetIndexExt( );
		SelectedF[ ind ].i = (int) selType;
		SelectedF[ ind ].d = 1;
		indexes.AddItem( &ind );
	}

	if ( ToMesh( RefEnt ) && ToMesh( RefEnt )->IsPolygonalMesh( ) ) {
		UpdateColor( OGLTransf, -1, selType, &indexes, a, onlySubdivision, onlyLowPoly );
		if ( checkring ) SetDirtyFaceSelection( true );
	}
}

//---------------------------------------------------------------------------

void TPBrepData::UnSelectFace( TOGLTransf *OGLTransf, int ind, float a, bool onlySubdivision, bool onlyLowPoly, bool checkring )
{
	if ( !GetPBrep( OGLTransf ) ) return;
	if ( !SelectedF || !RefEnt ) return;

	SelectedF[ ind ].i = (int) SelectedElementType::NoSelected;
	SelectedF[ ind ].d = 0;

	if ( ToMesh( RefEnt ) && ToMesh( RefEnt )->IsPolygonalMesh( ) ) {
		UpdateColor( OGLTransf, ind, SelectedElementType::NoSelected, 0, a, onlySubdivision, onlyLowPoly );
		if ( checkring ) SetDirtyFaceSelection( true );
	}
}

//---------------------------------------------------------------------------

void TPBrepData::UnSelectFaces( TOGLTransf *OGLTransf, TInteger_List *indexes, float a, bool onlySubdivision, bool onlyLowPoly, bool checkring )
{
	int k, ind;

	if ( !GetPBrep( OGLTransf ) ) return;
	if ( !SelectedF || !RefEnt ) return;
	if ( !indexes || !indexes->Count( ) ) return;

	for ( k = 0; k < indexes->Count( ); k++ ) {
		ind = *( indexes->GetItem( k ) );
		SelectedF[ ind ].i = (int) SelectedElementType::NoSelected;
		SelectedF[ ind ].d = 0;
	}

	if ( ToMesh( RefEnt ) && ToMesh( RefEnt )->IsPolygonalMesh( ) ) {
		UpdateColor( OGLTransf, -1, SelectedElementType::NoSelected, indexes, a, onlySubdivision, onlyLowPoly );
		if ( checkring ) SetDirtyFaceSelection( true );
	}
}

//---------------------------------------------------------------------------

// Seleccionamos las caras dentro del anillo de aristas pasado por parámetro.
// NO se comprueba si es un anillo válido.
// La cara guest es la que define cual es el interior de anillo
IwTA<IwPolyFace *> TPBrepData::GetFacesInsideSelection( TOGLTransf *OGLTransf, IwPolyFace *iwGuestFace, IwTA<IwPolyEdge *> *liwPolyEdges, bool unSel, bool useSeams )
{
	int ii, count, nSeams;
	ULONG uli, ulj, ulIndex;
	IwPolyEdge *edge, *edgeAux, *edgeSeam;
	IwTA<IwPolyFace *> liNextFaces, liFacesConnected;
	IwTA<IwPolyEdge *> liwEdgesToTest, liwEdgesTested, liwEdgesToTestAux;

	if ( iwGuestFace == NULL || liwPolyEdges == NULL || liwPolyEdges->GetSize( ) == NULL ) return liFacesConnected;

	nSeams = useSeams ? CountPBrepSeams( ) : 0;

	iwGuestFace->GetPolyEdges( liwEdgesToTest );

	if ( !unSel ) {
		for ( ii = (int) liwEdgesToTest.GetSize( ) - 1; ii >= 0; ii-- ) {
			if ( FindElement_Edge( liwPolyEdges, liwEdgesToTest[ ii ], ulIndex, edge ) ) liwEdgesToTest.RemoveAt( ii );
		}
	}

	if ( useSeams && nSeams > 0 ) {
		for ( ii = (int) liwEdgesToTest.GetSize( ) - 1; ii >= 0; ii-- ) {
			edgeSeam = liwEdgesToTest[ ii ];
			if ( edgeSeam->GetUserInt1( ) & MESH_EDGE_SEAM ) liwEdgesToTest.RemoveAt( ii );
		}
	}

	liFacesConnected.AddUnique( iwGuestFace );

	while ( liwEdgesToTest.GetSize( ) > 0 ) {
		liNextFaces = GetConnectedFacesFromEdge( liwEdgesToTest[ 0 ] );
		for ( uli = 0; uli < liNextFaces.GetSize( ); uli++ ) {
			liNextFaces[ uli ]->GetPolyEdges( liwEdgesToTestAux );
			count = 0;
			if ( unSel ) {
				for ( ulj = 0; ulj < liwEdgesToTestAux.GetSize( ); ulj++ ) {
					edgeAux = liwEdgesToTestAux[ ulj ]->GetSymmetricPolyEdge( );
					if ( !edgeAux ) {
						if ( IsEdgeSelected( OGLTransf, liwEdgesToTestAux[ ulj ]->GetUserIndex1( ) ) ) count++;
						continue;
					}
					if ( ( IsEdgeSelected( OGLTransf, liwEdgesToTestAux[ ulj ]->GetUserIndex1( ) ) ) || ( IsEdgeSelected( OGLTransf, liwEdgesToTestAux[ ulj ]->GetSymmetricPolyEdge( )->GetUserIndex1( ) ) ) ) count++;
				}
				if ( ( count < 4 && !liNextFaces[ uli ]->IsTriangle( ) ) || ( count != (int) liwEdgesToTestAux.GetSize( ) ) ) continue;
			}
			liFacesConnected.AddUnique( liNextFaces[ uli ] );
			for ( ulj = 0; ulj < liwEdgesToTestAux.GetSize( ); ulj++ ) {
				if ( FindElement_Edge( &liwEdgesTested, liwEdgesToTestAux[ ulj ], ulIndex, edge ) ) continue;
				if ( useSeams && nSeams > 0 ) {
					edgeSeam = liwEdgesToTestAux[ ulj ];
					if ( edgeSeam->GetUserInt1( ) & MESH_EDGE_SEAM ) continue;
				}
				if ( !FindElement_Edge( &liwEdgesToTest, liwEdgesToTestAux[ ulj ], ulIndex, edge ) ) {
					if ( !FindElement_Edge( liwPolyEdges, liwEdgesToTestAux[ ulj ], ulIndex, edge ) ) liwEdgesToTest.Add( liwEdgesToTestAux[ ulj ] );
				}
			}
		}
		liwEdgesTested.Add( liwEdgesToTest[ 0 ] );
		liwEdgesToTest.RemoveAt( 0 );
	}

	return liFacesConnected;
}

//---------------------------------------------------------------------------

// Seleccionamos las caras dentro del anillo de caras pasado por parámetro.
// NO se comprueba si es un anillo válido.
// La cara guest es la que define cual es el interior de anillo
IwTA<IwPolyFace *> TPBrepData::GetFacesInsideSelection( TOGLTransf *OGLTransf, IwPolyFace *iwGuestFace, IwTA<IwPolyFace *> *liwPolyFaces, bool useSeams )
{
	int ii, nSeams;
	ULONG uli, ulIndex;
	IwPolyEdge *edgeSeam;
	IwPolyFace *face;
	IwTA<IwPolyFace *> liNextFaces, liFacesConnected, liwFacesToTestAux, liwFacesToTest, liwFacesTested;
	IwTA<IwPolyEdge *> liwEdgesToTest;

	if ( !iwGuestFace || !liwPolyFaces || liwPolyFaces->GetSize( ) == 0 ) return liFacesConnected;

	nSeams = useSeams ? CountPBrepSeams( ) : 0;

	if ( liwPolyFaces->FindElement( iwGuestFace, ulIndex ) ) {
		iwGuestFace = NULL;
		for ( ii = 0; ii < CountPBrepFaces( OGLTransf ); ii++ ) {
			face = GetPBrepFace( OGLTransf, ii );
			if ( !liwPolyFaces->FindElement( face, ulIndex ) ) {
				iwGuestFace = face;
				break;
			}
		}
		if ( iwGuestFace == NULL ) return liFacesConnected;
		liFacesConnected.AddUnique( iwGuestFace );
	}

	GetAdjacentFaces( iwGuestFace, &liwFacesToTest, false, true );
	for ( ii = (int) liwFacesToTest.GetSize( ) - 1; ii >= 0; ii-- ) {
		if ( liwPolyFaces->FindElement( liwFacesToTest[ ii ], ulIndex ) ) liwFacesToTest.RemoveAt( ii );
		else if ( useSeams && nSeams > 0 ) {
			edgeSeam = GetEdgeBetweenFaces( liwFacesToTest[ ii ], iwGuestFace );
			if ( edgeSeam->GetUserInt1( ) & MESH_EDGE_SEAM ) liwFacesToTest.RemoveAt( ii );
		}
	}

	while ( liwFacesToTest.GetSize( ) > 0 ) {
		liFacesConnected.AddUnique( liwFacesToTest[ 0 ] );
		GetAdjacentFaces( liwFacesToTest[ 0 ], &liNextFaces, false, true );
		for ( uli = 0; uli < liNextFaces.GetSize( ); uli++ ) {
			if ( liwFacesTested.FindElement( liNextFaces[ uli ], ulIndex ) ) continue;
			if ( !liwFacesToTest.FindElement( liNextFaces[ uli ], ulIndex ) ) {
				if ( !liwPolyFaces->FindElement( liNextFaces[ uli ], ulIndex ) ) {
					if ( useSeams && nSeams > 0 ) {
						edgeSeam = GetEdgeBetweenFaces( liNextFaces[ uli ], liwFacesToTest[ 0 ] );
						if ( edgeSeam->GetUserInt1( ) & MESH_EDGE_SEAM ) continue;
					}
					liwFacesToTest.Add( liNextFaces[ uli ] );
				}
			}
		}

		liwFacesTested.Add( liwFacesToTest[ 0 ] );
		liwFacesToTest.RemoveAt( 0 );
	}

	return liFacesConnected;
}

//------------------------------------------------------------------------------

IwTA<IwPolyFace *> TPBrepData::GetFacesInsideNoSelection( IwPolyFace *iwGuestFace, ElementType eType, bool useSeams )
{
	int i, nSeams;
	ULONG uli, ulj, ulIndex;
	IwPolyEdge *edge, *edgeSeam;
	IwTA<IwPolyFace *> liNextFaces, liFacesConnected, liwFacesToTest, liwFacesTested;
	IwTA<IwPolyEdge *> liwEdgesToTest, liwEdgesTested, liwEdgesToTestAux;

	if ( !iwGuestFace ) return liFacesConnected;

	nSeams = useSeams ? CountPBrepSeams( ) : 0;

	if ( eType == ElementType::Face ) {
		liFacesConnected.Add( iwGuestFace );
		liwFacesTested.Add( iwGuestFace );
		GetAdjacentFaces( iwGuestFace, &liwFacesToTest, false, true );

		if ( useSeams && nSeams > 0 ) {
			for ( i = (int) liwFacesToTest.GetSize( ) - 1; i >= 0; i-- ) {
				edgeSeam = GetEdgeBetweenFaces( liwFacesToTest[ i ], iwGuestFace );
				if ( edgeSeam->GetUserInt1( ) & MESH_EDGE_SEAM ) liwFacesToTest.RemoveAt( i );
			}
		}

		while ( liwFacesToTest.GetSize( ) > 0 ) {
			liFacesConnected.AddUnique( liwFacesToTest[ 0 ] );
			GetAdjacentFaces( liwFacesToTest[ 0 ], &liNextFaces, false, true );
			for ( uli = 0; uli < liNextFaces.GetSize( ); uli++ ) {
				if ( liwFacesTested.FindElement( liNextFaces[ uli ], ulIndex ) ) continue;
				if ( useSeams && nSeams > 0 ) {
					edgeSeam = GetEdgeBetweenFaces( liwFacesToTest[ 0 ], liNextFaces[ uli ] );
					if ( edgeSeam->GetUserInt1( ) & MESH_EDGE_SEAM ) continue;
				}
				liwFacesToTest.AddUnique( liNextFaces[ uli ] );
			}
			liwFacesTested.Add( liwFacesToTest[ 0 ] );
			liwFacesToTest.RemoveAt( 0 );
		}
	} else if ( eType == ElementType::Edge ) {
		liFacesConnected.AddUnique( iwGuestFace );
		iwGuestFace->GetPolyEdges( liwEdgesToTest );

		if ( useSeams && nSeams > 0 ) {
			for ( i = (int) liwEdgesToTest.GetSize( ) - 1; i >= 0; i-- ) {
				edgeSeam = liwEdgesToTest[ i ];
				if ( edgeSeam->GetUserInt1( ) & MESH_EDGE_SEAM ) {
					liwEdgesTested.AddUnique( edgeSeam );
					liwEdgesToTest.RemoveAt( i );
				}
			}
		}

		while ( liwEdgesToTest.GetSize( ) > 0 ) {
			if ( !liwEdgesTested.FindElement( liwEdgesToTest[ 0 ], ulIndex ) ) {
				liNextFaces = GetConnectedFacesFromEdge( liwEdgesToTest[ 0 ] );
				for ( uli = 0; uli < liNextFaces.GetSize( ); uli++ ) {
					liFacesConnected.AddUnique( liNextFaces[ uli ] );
					liNextFaces[ uli ]->GetPolyEdges( liwEdgesToTestAux );
					for ( ulj = 0; ulj < liwEdgesToTestAux.GetSize( ); ulj++ ) {
						if ( FindElement_Edge( &liwEdgesTested, liwEdgesToTestAux[ ulj ], ulIndex, edge ) ) continue;
						if ( useSeams && nSeams > 0 ) {
							edgeSeam = liwEdgesToTestAux[ ulj ];
							if ( edgeSeam->GetUserInt1( ) & MESH_EDGE_SEAM ) {
								liwEdgesTested.AddUnique( edgeSeam );
								continue;
							}
						}
						liwEdgesToTest.AddUnique( liwEdgesToTestAux[ ulj ] );
					}
				}
			}
			liwEdgesTested.AddUnique( liwEdgesToTest[ 0 ] );
			liwEdgesToTest.RemoveAt( 0 );
		}
	}

	return liFacesConnected;
}

//------------------------------------------------------------------------------

void TPBrepData::UnSelectAllEdges( TOGLTransf *OGLTransf )
{
	int i, nEdges;

	if ( !GetPBrep( OGLTransf ) ) return;
	if ( !SelectedE ) return;

	nEdges = (int) PBrepEdges.GetSize( );
	for ( i = 0; i < nEdges; i++ ) {
		SelectedE[ i ] = 0;
	}
	AnyClosedRingSelected = false;
	SetDirtyEdgeSelection( false );
}

//---------------------------------------------------------------------------

void TPBrepData::SelectEdge( TOGLTransf *OGLTransf, int ind, SelectedElementType selType, bool checkring )
{
	int iNumEdges, ii;
	int *liEdgesSelected;

	if ( !GetPBrep( OGLTransf ) ) return;
	if ( !SelectedE ) return;
	if ( ind < 0 || ind >= (int) PBrepEdges.GetSize( ) ) return;

	if ( selType == SelectedElementType::LastUserSelection ) { //última seleccion de usuario (solo dejamos una)

		// La penúltima selección pasa a ser una más
		liEdgesSelected = GetEdges( OGLTransf, SelectedElementType::LastBeforeUserSelection, iNumEdges );
		if ( liEdgesSelected ) {
			for ( ii = 0; ii < iNumEdges; ii++ )
				SelectedE[ liEdgesSelected[ ii ] ] = (int) SelectedElementType::UserSelection;
			delete[] liEdgesSelected;
		}

		// La selección de loop pasan a ser una más
		liEdgesSelected = GetEdges( OGLTransf, SelectedElementType::LoopSelection, iNumEdges );
		if ( liEdgesSelected ) {
			for ( ii = 0; ii < iNumEdges; ii++ )
				SelectedE[ liEdgesSelected[ ii ] ] = (int) SelectedElementType::UserSelection;
			delete[] liEdgesSelected;
		}

		// Revertimos cualquier seleccion previa de usuario que hubiera. Pasará de la última a la penúltima
		liEdgesSelected = GetEdges( OGLTransf, SelectedElementType::LastUserSelection, iNumEdges );
		if ( liEdgesSelected ) {
			for ( ii = 0; ii < iNumEdges; ii++ )
				SelectedE[ liEdgesSelected[ ii ] ] = (int) SelectedElementType::LastBeforeUserSelection;
			delete[] liEdgesSelected;
		}
	}

	SelectedE[ ind ] = (int) selType;
	if ( checkring && ToMesh( RefEnt ) && ToMesh( RefEnt )->IsPolygonalMesh( ) ) SetDirtyEdgeSelection( true );
}

//---------------------------------------------------------------------------

void TPBrepData::SelectEdges( TOGLTransf *OGLTransf, TInteger_List *indexes, SelectedElementType selType, bool checkring )
{
	int ind, k, iNumEdges, ii;
	int *liEdgesSelected;

	if ( !GetPBrep( OGLTransf ) ) return;
	if ( !SelectedE ) return;
	if ( !indexes || !indexes->Count( ) ) return;

	if ( selType == SelectedElementType::LastUserSelection ) { //última seleccion de usuario (solo dejamos una)
		// Revertimos cualquier seleccion previa de usuario que hubiera
		liEdgesSelected = GetEdges( OGLTransf, SelectedElementType::LastUserSelection, iNumEdges );
		if ( liEdgesSelected ) {
			for ( ii = 0; ii < iNumEdges; ii++ )
				SelectedE[ liEdgesSelected[ ii ] ] = 1;
			delete[] liEdgesSelected;
		}
	}

	for ( k = 0; k < indexes->Count( ); k++ ) {
		ind = *( indexes->GetItem( k ) );
		SelectedE[ ind ] = (int) selType;
	}

	if ( checkring && ToMesh( RefEnt ) && ToMesh( RefEnt )->IsPolygonalMesh( ) ) SetDirtyEdgeSelection( true );
}

//---------------------------------------------------------------------------

void TPBrepData::UnSelectEdge( TOGLTransf *OGLTransf, int ind, bool checkring )
{
	if ( !GetPBrep( OGLTransf ) ) return;
	if ( !SelectedE ) return;

	SelectedE[ ind ] = (int) SelectedElementType::NoSelected;

	if ( checkring && ToMesh( RefEnt ) && ToMesh( RefEnt )->IsPolygonalMesh( ) ) SetDirtyEdgeSelection( true );
}

//------------------------------------------------------------------------------

void TPBrepData::UnSelectEdges( TOGLTransf *OGLTransf, TInteger_List *indexes, bool checkring )
{
	int k, ind;

	if ( !GetPBrep( OGLTransf ) ) return;
	if ( !SelectedE || !RefEnt ) return;
	if ( !indexes || !indexes->Count( ) ) return;

	for ( k = 0; k < indexes->Count( ); k++ ) {
		ind = *( indexes->GetItem( k ) );
		SelectedE[ ind ] = (int) SelectedElementType::NoSelected;
	}

	if ( checkring && ToMesh( RefEnt ) && ToMesh( RefEnt )->IsPolygonalMesh( ) ) SetDirtyEdgeSelection( true );
}

//------------------------------------------------------------------------------

int *TPBrepData::GetEdges( TOGLTransf *OGLTransf, SelectedElementType selType, int &iNumEdges, bool force )
{
	int *liEdgesSelected;
	ULONG uli;

	iNumEdges = 0;
	if ( !GetPBrep( OGLTransf, force ) ) return 0;

	if ( selType == SelectedElementType::All ) iNumEdges = (int) PBrepEdges.GetSize( );
	else {
		for ( uli = 0; uli < PBrepEdges.GetSize( ); uli++ ) {
			if ( SelectedE[ uli ] == (int) selType || ( SelectedE[ uli ] > (int) SelectedElementType::NoSelected && SelectedE[ uli ] < (int) SelectedElementType::AllSelected && selType == SelectedElementType::AllSelected ) ) iNumEdges++;
		}
	}
	if ( !iNumEdges ) return 0;

	liEdgesSelected = new int[ iNumEdges ];
	iNumEdges = 0;
	for ( uli = 0; uli < PBrepEdges.GetSize( ); uli++ )
		if ( selType == SelectedElementType::All || SelectedE[ uli ] == (int) selType || ( SelectedE[ uli ] > 0 && SelectedE[ uli ] < (int) SelectedElementType::AllSelected && selType == SelectedElementType::AllSelected ) ) liEdgesSelected[ iNumEdges++ ] = uli;

	return liEdgesSelected;
}

//------------------------------------------------------------------------------

void TPBrepData::UnSelectAllVertexs( TOGLTransf *OGLTransf )
{
	int i, nvertexs;

	if ( !GetPBrep( OGLTransf ) ) return;
	if ( !SelectedV ) return;

	nvertexs = (int) PBrepVertexs.GetSize( );
	for ( i = 0; i < nvertexs; i++ ) {
		SelectedV[ i ].i = (int) SelectedElementType::NoSelected;
		SelectedV[ i ].d = 0;
	}
}

//------------------------------------------------------------------------------

void TPBrepData::SelectVertex( TOGLTransf *OGLTransf, int ind, SelectedElementType selType, bool recalcW )
{
	int iNumVertexs, ii;
	int *liVertexsSelected;

	if ( !GetPBrep( OGLTransf ) ) return;
	if ( !SelectedV ) return;
	if ( ind < 0 || ind >= (int) PBrepVertexs.GetSize( ) ) return;
	if ( selType == SelectedElementType::LastUserSelection ) {
		// La penúltima pasa a ser un seleccionada más.
		liVertexsSelected = GetVertexs( OGLTransf, SelectedElementType::LastBeforeUserSelection, iNumVertexs );
		if ( liVertexsSelected ) {
			for ( ii = 0; ii < iNumVertexs; ii++ ) {
				SelectedV[ liVertexsSelected[ ii ] ].i = (int) SelectedElementType::UserSelection;
				// if ( ToMesh( RefEnt ) && ToMesh( RefEnt )->IsPolygonalMesh( ) ) UpdateColor( OGLTransf, liFacesSelected[ ii ], SelectedElementType::UserSelection, 0, a, onlySubdivision, onlyLowPoly );
			}
			delete[] liVertexsSelected;
		}

		// Los Ring pasan a ser un seleccionado más.
		liVertexsSelected = GetVertexs( OGLTransf, SelectedElementType::LoopSelection, iNumVertexs );
		if ( liVertexsSelected ) {
			for ( ii = 0; ii < iNumVertexs; ii++ ) {
				SelectedV[ liVertexsSelected[ ii ] ].i = (int) SelectedElementType::UserSelection;
				// if ( ToMesh( RefEnt ) && ToMesh( RefEnt )->IsPolygonalMesh( ) ) UpdateColor( OGLTransf, liFacesSelected[ ii ], SelectedElementType::UserSelection, 0, a, onlySubdivision, onlyLowPoly );
			}
			delete[] liVertexsSelected;
		}

		// La última pasa a ser la penúltima.
		liVertexsSelected = GetVertexs( OGLTransf, SelectedElementType::LastUserSelection, iNumVertexs );
		if ( liVertexsSelected ) {
			for ( ii = 0; ii < iNumVertexs; ii++ ) {
				SelectedV[ liVertexsSelected[ ii ] ].i = (int) SelectedElementType::LastBeforeUserSelection;
				// if ( ToMesh( RefEnt ) && ToMesh( RefEnt )->IsPolygonalMesh( ) ) UpdateColor( OGLTransf, liFacesSelected[ ii ], SelectedElementType::LastBeforeUserSelection, 0, a, onlySubdivision, onlyLowPoly );
			}
			delete[] liVertexsSelected;
		}
	}

	SelectedV[ ind ].i = (int) selType;
	if ( recalcW ) SelectedV[ ind ].d = 1;
}

//------------------------------------------------------------------------------

void TPBrepData::SelectVertexs( TOGLTransf *OGLTransf, TInteger_List *indexes, SelectedElementType selType, bool recalcW )
{
	int ind, k, iNumVertexs, ii;
	int *liVertexsSelected;

	if ( !GetPBrep( OGLTransf ) ) return;
	if ( !SelectedV ) return;
	if ( !indexes || !indexes->Count( ) ) return;

	if ( selType == SelectedElementType::LastUserSelection ) { //última seleccion de usuario (solo dejamos una)
		// Revertimos cualquier seleccion previa de usuario que hubiera
		liVertexsSelected = GetVertexs( OGLTransf, SelectedElementType::LastUserSelection, iNumVertexs );
		if ( liVertexsSelected ) {
			for ( ii = 0; ii < iNumVertexs; ii++ )
				SelectedV[ liVertexsSelected[ ii ] ].i = (int) SelectedElementType::UserSelection;
			delete[] liVertexsSelected;
		}
	}

	for ( k = 0; k < indexes->Count( ); k++ ) {
		ind = *( indexes->GetItem( k ) );
		SelectedV[ ind ].i = (int) selType;
		if ( recalcW ) SelectedV[ ind ].d = 1;
	}
}

//------------------------------------------------------------------------------

void TPBrepData::UnSelectVertex( TOGLTransf *OGLTransf, int ind, bool deleteW )
{
	if ( !GetPBrep( OGLTransf ) ) return;
	if ( !SelectedV ) return;

	SelectedV[ ind ].i = (int) SelectedElementType::NoSelected;
	if ( deleteW ) SelectedV[ ind ].d = 0;
}

//------------------------------------------------------------------------------

void TPBrepData::UnSelectVertexs( TOGLTransf *OGLTransf, TInteger_List *indexes, bool deleteW )
{
	int k, ind;

	if ( !GetPBrep( OGLTransf ) ) return;
	if ( !SelectedV || !RefEnt ) return;
	if ( !indexes || !indexes->Count( ) ) return;

	for ( k = 0; k < indexes->Count( ); k++ ) {
		ind = *( indexes->GetItem( k ) );
		SelectedV[ ind ].i = (int) SelectedElementType::NoSelected;
		if ( deleteW ) SelectedV[ ind ].d = 0;
	}
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Utilizar para marcar los vertices SelectedV
void TPBrepData::FindNeighbors( IwTA<IwPolyVertex *> vertexs, IwTA<IwPolyVertex *> &neighbors, float radius )
{
	int i, j, k, iV, sizeV, sizeN;
	float distance, init;
	bool carryOn;
	IwPolyVertex *vOrig, *vOther;
	IwTA<IwPolyVertex *> neighborsAux, aux;

	k = 1;
	distance = init = 0;
	sizeV = vertexs.GetSize( );
	carryOn = true;

	UnSelectAllVertexs( 0 );

	for ( iV = 0; iV < sizeV; iV++ ) {
		if ( SelectedV[ vertexs[ iV ]->GetIndexExt( ) ].i == 0 ) {
			SelectedV[ vertexs[ iV ]->GetIndexExt( ) ].i = 1;
			neighbors.Add( vertexs[ iV ] );
		}
		neighborsAux.Add( vertexs[ iV ] );
		sizeN = neighborsAux.GetSize( );
		init = 0;
		carryOn = true;
		do {
			for ( i = init; i < sizeN; i++ ) {
				vOrig = neighborsAux[ i ];
				vOrig->GetAdjacentVertices( aux );
				for ( j = 0; j < (int) aux.GetSize( ); j++ ) {
					vOther = aux[ j ];
					distance = vertexs[ iV ]->GetPoint( ).DistanceBetween( vOther->GetPoint( ) );
					if ( SelectedV[ vOther->GetIndexExt( ) ].i == 0 && distance < radius ) {
						SelectedV[ vOther->GetIndexExt( ) ].i = 1;
						neighbors.Add( vOther );
					}

					if ( SelectedV[ vOther->GetIndexExt( ) ].d < (unsigned long) k && distance < radius ) {
						SelectedV[ vOther->GetIndexExt( ) ].d = k;
						neighborsAux.Add( vOther );
					}
				}
				aux.RemoveAll( );
			}
			init = sizeN;
			sizeN = neighborsAux.GetSize( );
			if ( init == sizeN ) carryOn = false;
		} while ( carryOn );
		k++; // Sive para ir marcando los vertices revisados en la iteracion que toca y no volver a estudiarlos.
			 // En las siguiente iteraciones con otros puntos de partida si hay que volver a estudiarlos.
		neighborsAux.RemoveAll( );
	}
}

//------------------------------------------------------------------------------
// Devuelve la curva 3d pasada convertida en vertices del Brep
void TPBrepData::ConvertSelectionCurveToBrepVertexs( TOGLTransf *OGLTransf, TOGLPolygonList *OGLListCurve, IwTA<IwPolyVertex *> *vertexsCurveOut )
{
	bool first, close[ 2 ];
	int i, j;
	double limitsUV[ 4 ], *dist;
	T3DPoint pt;
	TOGLPolygon *pol, debugPol;
	TOGLPoint *oglPt;
	IwPolyVertex *vertex;
	IwVector3d iwPoint;
	IwPolyVertex *vClosest, *vGuess, *vIni;
	// IwTA< IwPolyVertex* > vertexsCurveGuess;

	if ( !OGLTransf || !OGLListCurve || !vertexsCurveOut ) return;
	if ( debug ) {
		WriteSections( L"c:\\temp\\OGLListCurve3D.asc", L"w", OGLListCurve );
		WriteSectionsAsPolylines( L"c:\\temp\\OGLListCurve3D.igs", OGLTransf, OGLListCurve );
	}

	vertexsCurveOut->RemoveAll( );
	first = true;
	for ( i = 0; i < OGLListCurve->Count( ); i++ ) {
		pol = OGLListCurve->GetItem( i );
		dist = new double[ pol->Count( ) ];
		for ( j = 0; j < pol->Count( ); j++ ) {
			oglPt = pol->GetItem( j );
			if ( !oglPt ) continue;

			dist[ j ] = 0;
			iwPoint = IwPoint3d( oglPt->v.v[ 0 ], oglPt->v.v[ 1 ], oglPt->v.v[ 2 ] );
			// El primer punto de la curva de seleccion se busca sobre la malla utilizando la cara
			if ( first ) {
				vClosest = GetClosestVertex( iwPoint, RES_GEOM );
				first = false;
				vGuess = vClosest;
			}
			// El resto de puntos se busca de forma mas rapida buscando caminos sobre las aristas
			else {
				vClosest = GetClosestVertex( vGuess, iwPoint );
				if ( vClosest ) dist[ j ] = vClosest->GetPoint( ).DistanceBetweenSquared( iwPoint );
				// Si el candidato no es bueno y el resultado da lejos del punto buscado, se busca de manera absoluta
				if ( !vClosest || dist[ j ] > 5.0 ) vClosest = GetClosestVertex( iwPoint, RES_GEOM );
				if ( !vClosest ) continue;
				vGuess = vClosest;
			}
			if ( !vClosest ) continue;
			vertexsCurveOut->AddUnique( vClosest );
			// vertexsCurveGuess.Add( vGuess );
		}
		if ( dist ) delete[] dist;
	}
	// Si es cerrada ...
	OGLListCurve->GetLimitsUV( limitsUV );
	if ( OGLListCurve->IsCloseExt( false, close, limitsUV ) ) {
		vIni = vertexsCurveOut->GetAt( 0 );
		vertexsCurveOut->Add( vIni );
	}

	if ( debug ) {
		for ( i = 0; i < (int) vertexsCurveOut->GetSize( ); i++ ) {
			vertex = vertexsCurveOut->GetAt( i );
			if ( !vertex ) continue;

			iwPoint = vertex->GetPoint( );
			pt = T3DPoint( iwPoint.x, iwPoint.y, iwPoint.z );
			debugPol.AddItem( &pt );
		}
		WriteSection( L"C:\\temp\\debugPol.asc", L"w", &debugPol );
		WriteSectionAsPolyline( L"C:\\temp\\debugPol.igs", OGLTransf, &debugPol );
		debugPol.Clear( );

		/*for ( i = 0; i < (int)vertexsCurveGuess.GetSize( ); i++ ) {
			vertex = vertexsCurveGuess.GetAt( i );
			if ( !vertex ) continue;

			iwPoint = vertex->GetPoint( );
			pt = T3DPoint( iwPoint.x, iwPoint.y, iwPoint.z );
			debugPol.AddItem( &pt );
		}
		WriteSection( L"C:\\temp\\debugPol_GUESS.asc", L"w", &debugPol );
		WriteSectionAsPolyline( L"C:\\temp\\debugPol_GUESS.igs", OGLTransf, &debugPol );
		debugPol.Clear( );       */
	}
}

//------------------------------------------------------------------------------
// Devuelve un poligo con la curva de seleccion cerrada parametrizada en UV
void TPBrepData::ConvertSelectionCurveVertexsToUV( TOGLTransf *OGLTransf, IwTA<IwPolyVertex *> *vertexsCurve, bool *close, double *limitsUV, double tol_1, TOGLPolygon *polUVOut )
{
	int i, numVertexsCurve, size;
	double limitsCurveUV[ 2 ], param;
	T3DPoint pt2D, ptFirst, ptLast;
	TOGLPoint oglPt, *oglFirst, *oglLast;
	TOGLPolygon polUVOutAux;
	TCadIBSpline curveUV;
	IwPolyVertex *vertex;

	if ( !vertexsCurve || !polUVOut ) return;

	polUVOut->Clear( );
	curveUV.Clear( );

	numVertexsCurve = (int) vertexsCurve->GetSize( );
	for ( i = 0; i < numVertexsCurve; i++ ) {
		vertex = vertexsCurve->GetAt( i );
		if ( !vertex ) continue;
		pt2D.x = vertex->GetUV( ).x;
		pt2D.y = vertex->GetUV( ).y;
		pt2D.z = 0;
		polUVOut->AddItem( &pt2D );
	}
	if ( debug ) {
		WriteSection( L"C:\\temp\\polUVOut_1.asc", L"w", polUVOut );
	}

	// --
	// Hacemos continua en V si es necesario
	polUVOutAux.Set( polUVOut ); // Para restaurarlo si falla ...
	polUVOut->OutParamRange( close, limitsUV, tol_1 );
	if ( debug ) {
		WriteSection( L"C:\\temp\\polUVOut_2.asc", L"w", polUVOut );
	}

	// --
	// MUY IMP.
	// Si la curva cruza la U ..., el OutParamRange no habra dejado una curva cerrada UV, lo hacemos a mano.
	// Si la curva es cerrada, el primer y ultimo punto deberia tener misma UV despues del OutParamRange.
	oglFirst = polUVOut->GetFirstItem( );
	oglLast = polUVOut->GetLastItem( );
	if ( !oglFirst || !oglLast ) return;
	ptFirst = oglFirst->v.GetPoint( );
	ptLast = oglLast->v.GetPoint( );
	if ( ptFirst.x != ptLast.x || ptFirst.y != ptLast.y ) {
		polUVOut->Set( &polUVOutAux ); // Deshacemos el OutParamRange
		polUVOut->CloseParamRange( limitsUV );
	}
	if ( debug ) {
		WriteSection( L"C:\\temp\\polUVOut_3.asc", L"w", polUVOut );
		WriteSectionAsPolyline( L"C:\\temp\\polUVOut_3.igs", OGLTransf, polUVOut );
	}

	// --
	// Afinamos
	for ( i = 0; i < polUVOut->Count( ); i++ ) {
		pt2D.x = polUVOut->GetItem( i )->v.v[ 0 ];
		pt2D.y = polUVOut->GetItem( i )->v.v[ 1 ];
		pt2D.z = 0;
		curveUV.Add( OGLTransf, pt2D );
	}
	if ( debug ) {
		WriteCurve( L"C:\\temp\\curveUV.igs", OGLTransf, &curveUV );
	}

	// --
	// Reconstruccion de polUV
	polUVOut->Clear( );
	curveUV.GetLimits( OGLTransf, limitsCurveUV );
	size = curveUV.Count( ) + 100;
	for ( i = 0; i < size; i++ ) {
		param = limitsCurveUV[ 0 ] + i * ( limitsCurveUV[ 1 ] - limitsCurveUV[ 0 ] ) / ( size - 1 );
		oglPt.v.SetPoint( curveUV.GetDataPointByParam( OGLTransf, param ) );
		polUVOut->AddItem( &oglPt, i );
	}
	polUVOut->Close( );
	if ( debug ) {
		WriteSection( L"C:\\temp\\polUVOut_4.asc", L"w", polUVOut );
	}
}

//------------------------------------------------------------------------------
// Dada una curva parametrizada en vertices del Brep devuelve en conjunto de vertice afectados
// por el radio introducido buscando vertices adyacentes.
// El peso asociado a esos vertices esta SUAVIZADo por GAUSS.
void TPBrepData::FindNeighborsOverSelectionCurveByRadius( TOGLPolygonList *OGLListCurve, IwTA<IwPolyVertex *> &vertexsCurve, IwTA<IwPolyVertex *> &vertexsSelectedOut, double radius, float *entityDeformerWeights )
{
	int i, numSelectedVertexs;
	double dist, w;
	T3DPoint pt, ptDist;
	TOGLFloat3 v;
	IwPolyVertex *vertex;
	IwVector3d iwPoint;

	if ( !OGLListCurve ) return;

	vertexsSelectedOut.RemoveAll( );
	FindNeighbors( vertexsCurve, vertexsSelectedOut, radius );

	// Calculo de pesos para cada vecino de la selecion actual
	numSelectedVertexs = (int) vertexsSelectedOut.GetSize( );
	for ( i = 0; i < numSelectedVertexs; i++ ) {
		vertex = vertexsSelectedOut[ i ];
		if ( !vertex ) continue;

		// MUY IMP
		// Una vez encontrado un peso != 0 para uno de los selectionItems NO se busca más para ese vertice
		// Si se utiliza el multi-selectionItem los Items NO deben mezclarse por no sabriamos que factor asignar
		if ( entityDeformerWeights[ vertex->GetIndexExt( ) ] != 0.0 ) continue;

		// Los que son vecinos del seleccionado
		iwPoint = vertex->GetPoint( );
		pt = T3DPoint( iwPoint.x, iwPoint.y, iwPoint.z );

		v.SetPoint( pt );
		OGLListCurve->GetNearestPoint( &v, ptDist );
		dist = pt.Distancia( ptDist );
		w = SmoothGauss( dist, 1.0, 0.0, 0.25, radius );
		if ( w > 0.0 ) entityDeformerWeights[ vertex->GetIndexExt( ) ] = w;
	}
}

//------------------------------------------------------------------------------
// con un vguess busca el vertice mas cercano (Puede equivocarse, hay que darle un candidato bueno)
IwPolyVertex *TPBrepData::GetClosestVertex( IwPolyVertex *vGuess, IwPoint3d ptDest )
{
	bool exit, *calculated;
	int i, selectedNeighbor;
	double minDistanceToPoint, currentDistanceToPoint;
	IwPolyVertex *vOrig, *vOther;
	IwTA<IwPolyVertex *> neighbors;
	T3DPoint p;
	T3DPolygon winners;

	if ( !vGuess ) return 0;

	calculated = new bool[ PBrepVertexs.GetSize( ) ];
	for ( i = 0; i < (int) PBrepVertexs.GetSize( ); i++ )
		calculated[ i ] = false;

	if ( debug ) {
		p = T3DPoint( vGuess->GetPoint( ).x, vGuess->GetPoint( ).y, vGuess->GetPoint( ).z );
		winners.AddItem( &p );
	}
	minDistanceToPoint = vGuess->GetPoint( ).DistanceBetweenSquared( ptDest );
	calculated[ vGuess->GetIndexExt( ) ] = true;
	exit = false;
	vOrig = vGuess;
	while ( !exit ) {
		vOrig->GetAdjacentVertices( neighbors );
		selectedNeighbor = -1;
		for ( i = 0; i < (int) neighbors.GetSize( ); i++ ) {
			vOther = neighbors[ i ];
			if ( calculated[ vOther->GetIndexExt( ) ] ) continue;
			currentDistanceToPoint = vOther->GetPoint( ).DistanceBetweenSquared( ptDest );
			calculated[ vOther->GetIndexExt( ) ] = true;
			if ( currentDistanceToPoint < minDistanceToPoint ) {
				minDistanceToPoint = currentDistanceToPoint;
				selectedNeighbor = i;
			}
		}
		if ( selectedNeighbor == -1 ) exit = true;
		else {
			vOrig = neighbors[ selectedNeighbor ];
			if ( debug ) {
				p = T3DPoint( vOrig->GetPoint( ).x, vOrig->GetPoint( ).y, vOrig->GetPoint( ).z );
				winners.AddItem( &p );
			}
		}
	}

	if ( debug ) {
		WriteSection( L"c:\\temp\\winners.asc", L"w", &winners );
		WriteSectionAsPolyline( L"c:\\temp\\winners.igs", 0, &winners );
	}
	delete[] calculated;

	return vOrig;
}

//------------------------------------------------------------------------------
// Dado un punto3D buscamos el vertice mas cercano buscando en todas las caras (o las que se se pasan por parametro) y luego buscando el vertice mas cercano
IwPolyVertex *TPBrepData::GetClosestVertex( IwPoint3d ptDest, double tol, IwTA<IwPolyFace *> *PBrepFacesSubset )
{
	int i;
	double minDist, d;
	T3DPoint pt3dCenter;
	IwPolyVertex *vRet;
	IwPolyFace *closestFace;
	IwTA<IwPolyVertex *> vertexs;
	//	T3DPoint point3D;

	//	if ( debug ) {
	//		point3D = T3DPoint( ptDest.x, ptDest.y, ptDest.z );
	//		WritePoint( L"c:\\temp\\ptDest.asc", L"w", &point3D );
	//	}

	vRet = 0;
	closestFace = GetClosestFace( ptDest, tol, PBrepFacesSubset );
	if ( !closestFace ) return vRet;

	minDist = MAXDOUBLE;
	closestFace->GetPolyVertices( vertexs );
	for ( i = 0; i < (int) vertexs.GetSize( ); i++ ) {
		d = vertexs.GetAt( i )->GetPoint( ).DistanceBetweenSquared( ptDest );
		if ( d < minDist ) {
			minDist = d;
			vRet = vertexs.GetAt( i );
		}
	}
	//	if ( debug ) {
	//		point3D = T3DPoint( vRet->GetPoint( ).x, vRet->GetPoint( ).y, vRet->GetPoint( ).z );
	//		WritePoint( L"c:\\temp\\verticeEncontrado.asc", L"w", &point3D );
	//	}

	return vRet;
}

//------------------------------------------------------------------------------
// Dado un punto3D buscamos la cara mas cercana. Creo que El punto debe yacer sobre la cara o estar cerca
IwPolyFace *TPBrepData::GetClosestFace( IwPoint3d ptDest, double tol, IwTA<IwPolyFace *> *PBrepFacesSubset )
{
	int i;
	float oldTol;
	IwPolyFace *fRet;
	IwTA<IwPolyFace *> *faces;
	IwTA<IwPolyVertex *> vertexs;
	IwBoolean rbInside;
	//	T3DPoint point3D;

	//	if ( debug ) {
	//		point3D = T3DPoint( ptDest.x, ptDest.y, ptDest.z );
	//		WritePoint( L"c:\\temp\\ptDest.asc", L"w", &point3D );
	//	}

	fRet = 0;
	if ( PBrepFacesSubset != NULL && PBrepFacesSubset->GetSize( ) > 0 ) faces = PBrepFacesSubset;
	else
		faces = GetPBrepFaces( 0 );
	for ( i = 0; i < (int) faces->GetSize( ); i++ ) {
		oldTol = faces->GetAt( i )->GetTolerance( );
		faces->GetAt( i )->SetTolerance( tol );
		faces->GetAt( i )->PointInPolygon( ptDest, rbInside, TRUE );
		faces->GetAt( i )->SetTolerance( oldTol );
		if ( rbInside ) {
			fRet = faces->GetAt( i );
			//			if ( debug ) { fRet->WriteToOBJFile( L"c:\\temp\\caraEncontrada.obj" ); }
			break;
		}
	}

	return fRet;
}

//------------------------------------------------------------------------------

bool TPBrepData::TranslateEditedVertexs( TOGLTransf *OGLTransf, float length, bool testLengthEdges, bool updateOGLList )
{
	int i, j, nVertices, nEdges;
	double lengthMove, tol;
	IwVector3d new_p;
	IwPolyFace *face;
	IwPolyEdge *edge;
	IwPolyVertex *vertex;
	IwPoint3d pt, ptDir;
	IwTA<IwPolyEdge *> edges;

	if ( !RefEnt ) return false;

	tol = RES_TESSELATION;
	nVertices = MoveVertUser.Vertices.GetSize( );
	if ( nVertices == 0 ) return false;

	if ( testLengthEdges ) {
		for ( i = 0; i < nVertices; i++ ) {
			vertex = MoveVertUser.Vertices[ i ];
			vertex->GetPolyEdges( edges );
			ptDir = MoveVertUser.Directions[ i ];
			lengthMove = sqrt( length * length * ( ptDir.x * ptDir.x + ptDir.y * ptDir.y + ptDir.z * ptDir.z ) );
			nEdges = edges.GetSize( );
			for ( j = 0; j < nEdges; j++ ) {
				edge = edges[ j ];
				if ( !edge ) continue;
				face = edge->GetPolyFace( );
				if ( !face ) continue;
				if ( IsFaceSelected( OGLTransf, face->GetIndexExt( ) ) ) {
					if ( length < 0 ) {
						if ( edge->Length( ) < lengthMove + tol ) return false;
					}
				} else {
					if ( length > 0 ) {
						edge = edge->GetSymmetricPolyEdge( );
						if ( !edge ) continue;
						face = edge->GetPolyFace( );
						if ( !face ) continue;
						if ( !IsFaceSelected( OGLTransf, face->GetIndexExt( ) ) ) {
							if ( edge->Length( ) < lengthMove + tol ) return false;
						}
					}
				}
			}
		}
	}

	for ( i = 0; i < nVertices; i++ ) {
		vertex = MoveVertUser.Vertices[ i ];
		pt = vertex->GetPoint( );
		ptDir = MoveVertUser.Directions[ i ];
		new_p.Set( pt.x + ptDir.x * length, pt.y + ptDir.y * length, pt.z + ptDir.z * length );
		vertex->SetPoint( new_p );
		SelectVertex( OGLTransf, vertex->GetIndexExt( ) );
	}

	if ( updateOGLList && RefEnt ) RefEnt->UpdateOGLListFromPBrep( OGLTransf, true );
	UnSelectAllVertexs( OGLTransf );

	return true;
}

//------------------------------------------------------------------------------

bool TPBrepData::TranslateSelectedFaces( TOGLTransf *OGLTransf, float incrX, float incrY, float incrZ, bool updateOGLList )
{
	int i, j, nvertexs, nfaces;
	float x, y, z;
	double w;
	IwVector3d new_p;
	IwPolyFace *face;
	IwTA<IwPolyVertex *> auxvertexs;

	if ( !RefEnt ) return false;

	nfaces = CountPBrepFaces( OGLTransf );
	for ( i = 0; i < nfaces; i++ ) {
		if ( IsFaceSelected( OGLTransf, i ) ) {
			face = GetPBrepFace( OGLTransf, i );
			if ( !face ) return false;
			face->GetPolyVertices( auxvertexs );
			nvertexs = auxvertexs.GetSize( );
			for ( j = 0; j < nvertexs; j++ )
				SelectVertex( OGLTransf, auxvertexs[ j ]->GetIndexExt( ) );
		}
	}

	nvertexs = CountPBrepVertexs( OGLTransf );
	for ( i = 0; i < nvertexs; i++ ) {
		if ( IsVertexSelected( OGLTransf, i ) ) {
			w = GetVertexWeight( OGLTransf, i );
			x = PBrepVertexs[ i ]->GetPoint( ).x;
			y = PBrepVertexs[ i ]->GetPoint( ).y;
			z = PBrepVertexs[ i ]->GetPoint( ).z;
			new_p.Set( x + incrX * w, y + incrY * w, z + incrZ * w );
			PBrepVertexs[ i ]->SetPoint( new_p );
		}
	}

	if ( updateOGLList && RefEnt ) RefEnt->UpdateOGLListFromPBrep( OGLTransf, true );

	UnSelectAllVertexs( OGLTransf );

	return true;
}

//------------------------------------------------------------------------------

bool TPBrepData::TranslateSelectedEdges( TOGLTransf *OGLTransf, float incrX, float incrY, float incrZ, bool updateOGLList )
{
	int i, nvertexs, nEdges;
	float x, y, z;
	IwPolyVertex *vertex;
	IwVector3d new_p;

	if ( !RefEnt ) return false;

	nEdges = CountPBrepEdges( OGLTransf );
	for ( i = 0; i < nEdges; i++ ) {
		if ( IsEdgeSelected( OGLTransf, i ) ) {
			vertex = PBrepEdges[ i ]->GetStartVertex( );
			SelectVertex( OGLTransf, vertex->GetIndexExt( ) );

			vertex = PBrepEdges[ i ]->GetEndVertex( );
			SelectVertex( OGLTransf, vertex->GetIndexExt( ) );
		}
	}

	nvertexs = CountPBrepVertexs( OGLTransf );
	for ( i = 0; i < nvertexs; i++ ) {
		if ( IsVertexSelected( OGLTransf, i ) ) {
			x = PBrepVertexs[ i ]->GetPoint( ).x;
			y = PBrepVertexs[ i ]->GetPoint( ).y;
			z = PBrepVertexs[ i ]->GetPoint( ).z;
			new_p.Set( x + incrX, y + incrY, z + incrZ );
			PBrepVertexs[ i ]->SetPoint( new_p );
		}
	}

	if ( updateOGLList && RefEnt ) RefEnt->UpdateOGLListFromPBrep( OGLTransf, true );

	UnSelectAllVertexs( OGLTransf );

	return true;
}

//------------------------------------------------------------------------------

bool TPBrepData::TranslateSelectedVertexs( TOGLTransf *OGLTransf, float incrX, float incrY, float incrZ, bool updateOGLList, bool slideVertex )
{
	int i, nvertexs;
	float x, y, z;
	double w;
	IwVector3d new_p;

	if ( !RefEnt ) return false;

	nvertexs = CountPBrepVertexs( OGLTransf );
	for ( i = 0; i < nvertexs; i++ ) {
		if ( IsVertexSelected( OGLTransf, i ) ) {
			if ( slideVertex ) new_p.Set( incrX, incrY, incrZ ); // En este caso los incrementos son la posición final del punto
			else {
				w = GetVertexWeight( OGLTransf, i );
				x = PBrepVertexs[ i ]->GetPoint( ).x;
				y = PBrepVertexs[ i ]->GetPoint( ).y;
				z = PBrepVertexs[ i ]->GetPoint( ).z;
				new_p.Set( x + incrX * w, y + incrY * w, z + incrZ * w );
			}
			PBrepVertexs[ i ]->SetPoint( new_p );
		}
	}

	if ( updateOGLList && RefEnt ) RefEnt->UpdateOGLListFromPBrep( OGLTransf, true );

	return true;
}

//------------------------------------------------------------------------------
bool TPBrepData::TranslateProportionalEditing( TOGLTransf *OGLTransf, float incrX, float incrY, float incrZ, bool updateOGLList )
{
	int i;
	float x, y, z;
	double w;
	IwVector3d new_p;
	IwPolyVertex *vertex;
	TColor cIni, cEnd;

	if ( !RefEnt ) return false;

	// Movimiento de vértices seleccionados
	for ( i = 0; i < (int) MoveVertUser.VerticesOrg.GetSize( ); i++ ) {
		vertex = MoveVertUser.VerticesOrg[ i ];
		x = vertex->GetPoint( ).x;
		y = vertex->GetPoint( ).y;
		z = vertex->GetPoint( ).z;
		new_p.Set( x + incrX * 1, y + incrY * 1, z + incrZ * 1 );

		vertex->SetPoint( new_p );
	}

	// Movimiento proporcional de vértices dentro del radio de influencia.
	for ( i = 0; i < (int) MoveVertUser.Vertices.GetSize( ); i++ ) {
		vertex = MoveVertUser.Vertices[ i ];
		w = vertex->GetPointExt( ).x;
		x = vertex->GetPoint( ).x;
		y = vertex->GetPoint( ).y;
		z = vertex->GetPoint( ).z;
		new_p.Set( x + incrX * w, y + incrY * w, z + incrZ * w );

		vertex->SetPoint( new_p );
	}

	cIni = (TColor) RGB( 1.0, 1.0, 0.0 );
	cEnd = (TColor) RGB( 1.0, 0.0, 0.0 );
	UpdateColorsForProportionalEditing( OGLTransf, RefEnt->GetOGLRenderData( )->Colors, &cIni, &cEnd );

	if ( updateOGLList && RefEnt ) RefEnt->UpdateOGLListFromPBrep( OGLTransf, true );

	return true;
}

//------------------------------------------------------------------------------

bool TPBrepData::Translate( TOGLTransf *OGLTransf, float incrX, float incrY, float incrZ, bool updateOGLList )
{
	int i, nvertexs;
	float x, y, z;
	double w;
	IwVector3d new_p;

	if ( !RefEnt ) return false;

	nvertexs = CountPBrepVertexs( OGLTransf );
	for ( i = 0; i < nvertexs; i++ ) {
		w = GetVertexWeight( OGLTransf, i );
		x = PBrepVertexs[ i ]->GetPoint( ).x;
		y = PBrepVertexs[ i ]->GetPoint( ).y;
		z = PBrepVertexs[ i ]->GetPoint( ).z;
		new_p.Set( x + incrX * w, y + incrY * w, z + incrZ * w );
		PBrepVertexs[ i ]->SetPoint( new_p );
	}

	if ( updateOGLList && RefEnt ) RefEnt->UpdateOGLListFromPBrep( OGLTransf );

	return true;
}

//------------------------------------------------------------------------------

bool TPBrepData::RotateSelectedFaces( TOGLTransf *OGLTransf, float angle, T3DVector axis, bool updateOGLList )
{
	int i, j, nfaces, nvertexs;
	float x, y, z;
	double w;
	T3DPoint aux_p;
	TNRotateMatrix matRot;
	IwPolyFace *face;
	IwVector3d new_p;
	IwTA<IwPolyVertex *> auxvertexs;

	if ( !RefEnt ) return false;

	nfaces = CountPBrepFaces( OGLTransf );
	for ( i = 0; i < nfaces; i++ ) {
		if ( IsFaceSelected( OGLTransf, i ) ) {
			face = GetPBrepFace( OGLTransf, i );
			if ( !face ) return false;
			face->GetPolyVertices( auxvertexs );
			nvertexs = auxvertexs.GetSize( );
			for ( j = 0; j < nvertexs; j++ )
				SelectVertex( OGLTransf, auxvertexs[ j ]->GetIndexExt( ) );
		}
	}

	nvertexs = CountPBrepVertexs( OGLTransf );
	for ( i = 0; i < nvertexs; i++ ) {
		if ( IsVertexSelected( OGLTransf, i ) ) {
			w = GetVertexWeight( OGLTransf, i );
			x = PBrepVertexs[ i ]->GetPoint( ).x;
			y = PBrepVertexs[ i ]->GetPoint( ).y;
			z = PBrepVertexs[ i ]->GetPoint( ).z;
			aux_p = T3DPoint( x, y, z );
			matRot = TNRotateMatrix( angle * w * M_PI_180, axis );
			aux_p.ApplyMatrix( matRot );
			new_p.Set( aux_p.x, aux_p.y, aux_p.z );
			PBrepVertexs[ i ]->SetPoint( new_p );
		}
	}

	if ( updateOGLList && RefEnt ) RefEnt->UpdateOGLListFromPBrep( OGLTransf, true );

	UnSelectAllVertexs( OGLTransf );

	return true;
}

//------------------------------------------------------------------------------

bool TPBrepData::RotateSelectedEdges( TOGLTransf *OGLTransf, float angle, T3DVector axis, bool updateOGLList )
{
	int i, nEdges, nvertexs;
	float x, y, z;
	T3DPoint aux_p;
	TNRotateMatrix matRot;
	IwVector3d new_p;
	IwPolyVertex *vertex;

	if ( !RefEnt ) return false;

	nEdges = CountPBrepEdges( OGLTransf );
	matRot = TNRotateMatrix( angle * M_PI_180, axis );
	for ( i = 0; i < nEdges; i++ ) {
		if ( IsEdgeSelected( OGLTransf, i ) ) {
			vertex = PBrepEdges[ i ]->GetStartVertex( );
			SelectVertex( OGLTransf, vertex->GetIndexExt( ) );

			vertex = PBrepEdges[ i ]->GetEndVertex( );
			SelectVertex( OGLTransf, vertex->GetIndexExt( ) );
		}
	}

	nvertexs = CountPBrepVertexs( OGLTransf );
	for ( i = 0; i < nvertexs; i++ ) {
		if ( IsVertexSelected( OGLTransf, i ) ) {
			x = PBrepVertexs[ i ]->GetPoint( ).x;
			y = PBrepVertexs[ i ]->GetPoint( ).y;
			z = PBrepVertexs[ i ]->GetPoint( ).z;
			aux_p = T3DPoint( x, y, z );
			matRot = TNRotateMatrix( angle * M_PI_180, axis );
			aux_p.ApplyMatrix( matRot );
			new_p.Set( aux_p.x, aux_p.y, aux_p.z );
			PBrepVertexs[ i ]->SetPoint( new_p );
		}
	}

	if ( updateOGLList && RefEnt ) RefEnt->UpdateOGLListFromPBrep( OGLTransf, true );

	UnSelectAllVertexs( OGLTransf );

	return true;
}

//------------------------------------------------------------------------------

bool TPBrepData::RotateSelectedVertexs( TOGLTransf *OGLTransf, float angle, T3DVector axis, bool updateOGLList )
{
	int i, nvertexs;
	float x, y, z;
	double w;
	T3DPoint aux_p;
	TNRotateMatrix matRot;
	IwVector3d new_p;

	if ( !RefEnt ) return false;

	nvertexs = CountPBrepVertexs( OGLTransf );
	for ( i = 0; i < nvertexs; i++ ) {
		if ( IsVertexSelected( OGLTransf, i ) ) {
			w = GetVertexWeight( OGLTransf, i );
			x = PBrepVertexs[ i ]->GetPoint( ).x;
			y = PBrepVertexs[ i ]->GetPoint( ).y;
			z = PBrepVertexs[ i ]->GetPoint( ).z;
			aux_p = T3DPoint( x, y, z );
			matRot = TNRotateMatrix( angle * M_PI_180 * w, axis );
			aux_p.ApplyMatrix( matRot );
			new_p.Set( aux_p.x, aux_p.y, aux_p.z );
			PBrepVertexs[ i ]->SetPoint( new_p );
		}
	}

	if ( updateOGLList && RefEnt ) RefEnt->UpdateOGLListFromPBrep( OGLTransf, true );

	return true;
}

//------------------------------------------------------------------------------

bool TPBrepData::RotateProportionalEditing( TOGLTransf *OGLTransf, float angle, T3DVector axis, bool updateOGLList )
{
	int i;
	float x, y, z;
	double w;
	IwVector3d new_p;
	T3DPoint aux_p;
	TNRotateMatrix matRot;
	IwPolyVertex *vertex;
	TColor cIni, cEnd;

	if ( !RefEnt ) return false;

	// Movimiento de vértices seleccionados
	for ( i = 0; i < (int) MoveVertUser.VerticesOrg.GetSize( ); i++ ) {
		vertex = MoveVertUser.VerticesOrg[ i ];
		x = vertex->GetPoint( ).x;
		y = vertex->GetPoint( ).y;
		z = vertex->GetPoint( ).z;

		aux_p = T3DPoint( x, y, z );
		matRot = TNRotateMatrix( angle * M_PI_180 * 1, axis );
		aux_p.ApplyMatrix( matRot );
		new_p.Set( aux_p.x, aux_p.y, aux_p.z );
		vertex->SetPoint( new_p );
	}

	// Movimiento proporcional de vértices dentro del radio de influencia.
	for ( i = 0; i < (int) MoveVertUser.Vertices.GetSize( ); i++ ) {
		vertex = MoveVertUser.Vertices[ i ];
		w = vertex->GetPointExt( ).x;
		x = vertex->GetPoint( ).x;
		y = vertex->GetPoint( ).y;
		z = vertex->GetPoint( ).z;

		aux_p = T3DPoint( x, y, z );
		matRot = TNRotateMatrix( angle * M_PI_180 * w, axis );
		aux_p.ApplyMatrix( matRot );
		new_p.Set( aux_p.x, aux_p.y, aux_p.z );
		vertex->SetPoint( new_p );
	}

	cIni = (TColor) RGB( 1.0, 1.0, 0.0 );
	cEnd = (TColor) RGB( 1.0, 0.0, 0.0 );
	UpdateColorsForProportionalEditing( OGLTransf, RefEnt->GetOGLRenderData( )->Colors, &cIni, &cEnd );

	if ( updateOGLList && RefEnt ) RefEnt->UpdateOGLListFromPBrep( OGLTransf, true );

	return true;
}

//------------------------------------------------------------------------------

bool TPBrepData::Rotate( TOGLTransf *OGLTransf, float angle, T3DVector axis, bool updateOGLList )
{
	int i, nvertexs;
	float x, y, z;
	double w;
	T3DPoint aux_p;
	TNRotateMatrix matRot;
	IwVector3d new_p;

	if ( !RefEnt ) return false;

	nvertexs = CountPBrepVertexs( OGLTransf );
	for ( i = 0; i < nvertexs; i++ ) {
		w = GetVertexWeight( OGLTransf, i );
		x = PBrepVertexs[ i ]->GetPoint( ).x;
		y = PBrepVertexs[ i ]->GetPoint( ).y;
		z = PBrepVertexs[ i ]->GetPoint( ).z;
		aux_p = T3DPoint( x, y, z );
		matRot = TNRotateMatrix( angle * M_PI_180 * w, axis );
		aux_p.ApplyMatrix( matRot );
		new_p.Set( aux_p.x, aux_p.y, aux_p.z );
		PBrepVertexs[ i ]->SetPoint( new_p );
	}

	if ( updateOGLList && RefEnt ) RefEnt->UpdateOGLListFromPBrep( OGLTransf );

	return true;
}

//------------------------------------------------------------------------------

bool TPBrepData::ScaleSelectedFaces( TOGLTransf *OGLTransf, float factorX, float factorY, float factorZ, TNMatrix matSCP, TNMatrix matSCPinv, bool updateOGLList )
{
	int i, j, nfaces, nvertexs;
	float x, y, z;
	double w;
	T3DPoint aux_p;
	TNMatrix matrix, matrix2;
	IwPolyFace *face;
	IwVector3d new_p;
	IwTA<IwPolyVertex *> auxvertexs;

	if ( !RefEnt ) return false;

	nfaces = CountPBrepFaces( OGLTransf );
	for ( i = 0; i < nfaces; i++ ) {
		if ( IsFaceSelected( OGLTransf, i ) ) {
			face = GetPBrepFace( OGLTransf, i );
			if ( !face ) return false;
			face->GetPolyVertices( auxvertexs );
			nvertexs = auxvertexs.GetSize( );
			for ( j = 0; j < nvertexs; j++ )
				SelectVertex( OGLTransf, auxvertexs[ j ]->GetIndexExt( ) );
		}
	}

	nvertexs = CountPBrepVertexs( OGLTransf );
	for ( i = 0; i < nvertexs; i++ ) {
		if ( IsVertexSelected( OGLTransf, i ) ) {
			w = GetVertexWeight( OGLTransf, i );
			matrix2 = TNScaleMatrix( 1.0 + factorX * w, 1.0 + factorY * w, 1.0 + factorZ * w );
			matrix = matSCP * matrix2 * matSCPinv;
			x = PBrepVertexs[ i ]->GetPoint( ).x;
			y = PBrepVertexs[ i ]->GetPoint( ).y;
			z = PBrepVertexs[ i ]->GetPoint( ).z;
			aux_p = T3DPoint( x, y, z );
			aux_p.ApplyMatrix( matrix );
			new_p.Set( aux_p.x, aux_p.y, aux_p.z );
			PBrepVertexs[ i ]->SetPoint( new_p );
		}
	}

	if ( updateOGLList && RefEnt ) RefEnt->UpdateOGLListFromPBrep( OGLTransf, true );

	UnSelectAllVertexs( OGLTransf );

	return true;
}

//------------------------------------------------------------------------------
// Extrude
// type = 0 -> extrusión en dirección de la normal
// type = 1 -> extrusión en dirección indicada
// type = 2 -> extrusión en dirección media de cada grupo
bool TPBrepData::ExtrudeSelectedFaces( TOGLTransf *OGLTransf, float incrX, float incrY, float incrZ, TExtrudeType extrudetype, int sign, bool createFaces, bool updateOGLList, bool creaseUpBorder, double valcrease )
{
	float mod;
	T3DPoint incr;
	T3DVector v;

	incr = T3DPoint( incrX, incrY, incrZ );
	v = T3DVector( T3DSize( incr ) );
	mod = v.Modulo( );
	if ( mod < RES_COMP ) return false;

	if ( !createFaces ) return TranslateEditedVertexs( OGLTransf, mod * sign );
	else if ( extrudetype == TExtrudeType::NormalFace )
		return ExtrudeSelectedFacesByNormalFace( OGLTransf, mod, sign, updateOGLList );
	else if ( extrudetype == TExtrudeType::Direction )
		return ExtrudeSelectedFacesByDirection( OGLTransf, incrX, incrY, incrZ, sign, updateOGLList );
	else if ( extrudetype == TExtrudeType::GroupFacesByNormal )
		return ExtrudeSelectedGroupFacesByNormal( OGLTransf, mod, sign, updateOGLList );
	else if ( extrudetype == TExtrudeType::GroupFacesByVertexNormal || extrudetype == TExtrudeType::Solidify )
		return ExtrudeSelectedGroupFacesByVertexNormal( OGLTransf, mod, sign, updateOGLList, creaseUpBorder, valcrease );

	return false;
}

//------------------------------------------------------------------------------

bool TPBrepData::ExtrudeSelectedGroupFacesByNormal( TOGLTransf *OGLTransf, float length, int sign, bool updateOGLList )
{
	int g, i, j, numFaces, numEdges, count, typeAuxInt;
	double vertexTol;
	ULONG auxNum;
	SelectedElementType typeSel;
	IwVector3d pt;
	IwPolyVertex *pV1, *pV2, *pV3, *pV4, *pVAux;
	IwVector3d extrudeDir, extrudeDirUnit;
	IwPolyFace *face, *faceSup;
	IwPolyEdge *edge, *edgeSym;
	IwPolyShell *pShell;
	IwPolyRegion *pRegion;
	IwTArray<IwPolyVertex *> listVerticesSup;
	IwTA<IwPolyEdge *> listEdges, edgesAux;
	IwTA<IwPolyFace *> faces, facesGroupAdded;
	vector<int> listFaces;
	vector<vector<int> > groups;
	IwVector3d norm;

	if ( !RefEnt || !PBrep ) return false;

	// extrude direction
	if ( !GetDisjointGroupFaces( OGLTransf, &groups ) ) return false;

	MoveVertUser.Clear( );
	vertexTol = RES_COMP;
	InitUserIndex2( true, true, true );

	for ( g = 0; g < (int) groups.size( ); g++ ) {
		listFaces = groups.at( g );
		numFaces = listFaces.size( );
		norm.x = 0;
		norm.y = 0;
		norm.z = 0;
		for ( i = 0; i < numFaces; i++ ) {
			face = GetPBrepFace( OGLTransf, listFaces[ i ] );
			norm += face->GetNormal( true );
		}
		norm.Unitize( );

		extrudeDir.x = norm.x * length * sign;
		extrudeDir.y = norm.y * length * sign;
		extrudeDir.z = norm.z * length * sign;
		extrudeDirUnit = extrudeDir / sign;
		extrudeDirUnit.Unitize( );

		facesGroupAdded.RemoveAll( );

		for ( i = 0; i < numFaces; i++ ) {
			face = GetPBrepFace( OGLTransf, listFaces[ i ] );
			if ( face == NULL ) continue;

			face->GetPolyEdges( listEdges );
			numEdges = (int) listEdges.GetSize( );
			for ( j = 0; j < numEdges; j++ ) {
				edge = listEdges[ j ];
				edgeSym = edge->GetSymmetricPolyEdge( );
				count = edge->GetUserIndex2( );
				if ( edgeSym ) count = max( count, (int) edgeSym->GetUserIndex2( ) );
				edge->SetUserIndex2( ++count );
				if ( edgeSym ) edgeSym->SetUserIndex2( count );
			}
		}

		for ( i = 0; i < numFaces; i++ ) {
			face = GetPBrepFace( OGLTransf, listFaces[ i ] );
			if ( face == NULL ) continue;

			pShell = face->GetPolyShell( );
			pRegion = pShell->GetPolyRegion( );

			face->GetPolyEdges( listEdges );
			numEdges = (int) listEdges.GetSize( );

			listVerticesSup.RemoveAll( );

			// duplicate face
			for ( j = 0; j < numEdges; j++ ) {
				edge = listEdges[ j ];

				pV1 = edge->GetStartVertex( );

				// testeo de edges degenerados
				if ( AreAnyNonSelFaces( OGLTransf, pV1 ) && !IsFaceConnectedToSelGroupByVertex( OGLTransf, face, &facesGroupAdded, pV1 ) ) pV1->SetUserIndex2( 0 );

				if ( (int) pV1->GetUserIndex2( ) < g + 1 ) {
					pt = pV1->GetPoint( );
					pt.x += extrudeDir.x;
					pt.y += extrudeDir.y;
					pt.z += extrudeDir.z;
					pVAux = new IwPolyVertex( _GetSMLib( )->GetContext( ), *PBrep, pt, vertexTol );
					pV1->SetUserPtr1( pVAux );
					pV1->SetUserIndex2( g + 1 );
				}

				pVAux = (IwPolyVertex *) pV1->GetUserPtr1( );
				listVerticesSup.Push( pVAux );

				if ( !MoveVertUser.Vertices.FindElement( pVAux, auxNum ) ) {
					MoveVertUser.Directions.push_back( extrudeDirUnit );
					MoveVertUser.Vertices.Add( pVAux );
				}
			}
			PBrep->CreatePolyFace( pRegion, pShell, listVerticesSup, faceSup );

			// use UserIndex2 to select face after delete
			faceSup->SetUserIndex2( SelectedF[ listFaces[ i ] ].i );

			// create one face for each edge
			count = 0;
			for ( j = 0; j < numEdges; j++ ) {
				edge = listEdges[ j ];

				// dont add midle face
				if ( edge->GetUserIndex2( ) > 1 ) {
					count++;
					continue;
				}

				pV1 = edge->GetStartVertex( );
				pV2 = edge->GetEndVertex( );
				if ( numEdges == count + 1 ) pV3 = listVerticesSup[ 0 ];
				else
					pV3 = listVerticesSup[ count + 1 ];
				pV4 = listVerticesSup[ count ];
				PBrep->CreatePolyQuad( pRegion, pShell, pV1, pV2, pV3, pV4, faceSup );

				// Chequeo de si las aristas simetricas son pliegues
				if ( faceSup && IsEdgeCrease( edge ) ) {
					faceSup->GetPolyEdges( edgesAux );
					if ( edgesAux.GetSize( ) )
						if ( edgesAux[ 0 ] ) edgesAux[ 0 ]->SetUserFloat1( edge->GetUserFloat1( ) );
				}

				count++;
			}
			facesGroupAdded.Add( face );
		}
	}

	RemoveSelectedFaces( OGLTransf, true );

	// select faces
	PBrep->GetPolyFaces( faces );
	numFaces = (int) faces.GetSize( );
	for ( i = 0; i < numFaces; i++ ) {
		face = faces[ i ];
		typeAuxInt = face->GetUserIndex2( );
		if ( typeAuxInt > 0 ) {
			typeSel = ( typeAuxInt == (int) SelectedElementType::LastUserSelection ) ? SelectedElementType::LastUserSelection : SelectedElementType::UserSelection;
			SelectFace( OGLTransf, face->GetIndexExt( ), typeSel );
		}
	}
	SetDirtyFaceSelection( true );

	InitUserIndex2( true, true, true );

	if ( updateOGLList && RefEnt ) RefEnt->UpdateOGLListFromPBrep( OGLTransf, true );

	return true;
}

//------------------------------------------------------------------------------

bool TPBrepData::ExtrudeSelectedFacesByDirection( TOGLTransf *OGLTransf, float incrX, float incrY, float incrZ, int sign, bool updateOGLList )
{
	int g, i, j, numFaces, numEdges, count, typeAuxInt;
	double vertexTol;
	ULONG auxNum;
	SelectedElementType typeSel;
	IwVector3d pt;
	IwPolyVertex *pV1, *pV2, *pV3, *pV4, *pVAux;
	IwVector3d extrudeDir, extrudeDirUnit;
	IwPolyFace *face, *faceSup;
	IwPolyEdge *edge, *edgeSym;
	IwPolyShell *pShell;
	IwPolyRegion *pRegion;
	IwTArray<IwPolyVertex *> listVerticesSup;
	IwTA<IwPolyEdge *> listEdges, edgesAux;
	IwTA<IwPolyFace *> faces, facesGroupAdded;
	vector<int> listFaces;
	vector<vector<int> > groups;
	T3DPoint incr;

	if ( !RefEnt || !PBrep ) return false;

	// extrude direction
	if ( incrX == 0 && incrY == 0 && incrZ == 0 ) return false;
	if ( !GetDisjointGroupFaces( OGLTransf, &groups ) ) return false;

	MoveVertUser.Clear( );
	incr = T3DPoint( incrX, incrY, incrZ ) * sign;

	extrudeDir.x = incrX;
	extrudeDir.y = incrY;
	extrudeDir.z = incrZ;

	extrudeDirUnit = extrudeDir / sign;
	extrudeDirUnit.Unitize( );

	vertexTol = RES_COMP;
	InitUserIndex2( true, true, true );

	for ( g = 0; g < (int) groups.size( ); g++ ) {
		listFaces = groups.at( g );
		numFaces = listFaces.size( );
		facesGroupAdded.RemoveAll( );

		for ( i = 0; i < numFaces; i++ ) {
			face = GetPBrepFace( OGLTransf, listFaces[ i ] );
			if ( face == NULL ) continue;

			face->GetPolyEdges( listEdges );
			numEdges = (int) listEdges.GetSize( );
			for ( j = 0; j < numEdges; j++ ) {
				edge = listEdges[ j ];
				edgeSym = edge->GetSymmetricPolyEdge( );
				count = edge->GetUserIndex2( );
				if ( edgeSym ) count = max( count, (int) edgeSym->GetUserIndex2( ) );
				edge->SetUserIndex2( ++count );
				if ( edgeSym ) edgeSym->SetUserIndex2( count );
			}
		}

		for ( i = 0; i < numFaces; i++ ) {
			face = GetPBrepFace( OGLTransf, listFaces[ i ] );
			if ( face == NULL ) continue;

			pShell = face->GetPolyShell( );
			pRegion = pShell->GetPolyRegion( );

			face->GetPolyEdges( listEdges );
			numEdges = (int) listEdges.GetSize( );

			listVerticesSup.RemoveAll( );
			// duplicate face
			for ( j = 0; j < numEdges; j++ ) {
				edge = listEdges[ j ];

				pV1 = edge->GetStartVertex( );

				// testeo de edges degenerados
				if ( AreAnyNonSelFaces( OGLTransf, pV1 ) && !IsFaceConnectedToSelGroupByVertex( OGLTransf, face, &facesGroupAdded, pV1 ) ) pV1->SetUserIndex2( 0 );

				if ( (int) pV1->GetUserIndex2( ) < g + 1 ) {
					pt = pV1->GetPoint( );
					pt.x += extrudeDir.x;
					pt.y += extrudeDir.y;
					pt.z += extrudeDir.z;
					pVAux = new IwPolyVertex( _GetSMLib( )->GetContext( ), *PBrep, pt, vertexTol );
					pV1->SetUserPtr1( pVAux );
					pV1->SetUserIndex2( g + 1 );
				}

				pVAux = (IwPolyVertex *) pV1->GetUserPtr1( );
				listVerticesSup.Push( pVAux );

				if ( !MoveVertUser.Vertices.FindElement( pVAux, auxNum ) ) {
					MoveVertUser.Directions.push_back( extrudeDirUnit );
					MoveVertUser.Vertices.Add( pVAux );
				}
			}
			PBrep->CreatePolyFace( pRegion, pShell, listVerticesSup, faceSup );

			// use UserIndex2 to select face after delete
			faceSup->SetUserIndex2( SelectedF[ listFaces[ i ] ].i );

			// create one face for each edge
			count = 0;
			for ( j = 0; j < numEdges; j++ ) {
				edge = listEdges[ j ];

				// dont add midle face
				if ( edge->GetUserIndex2( ) > 1 ) {
					count++;
					continue;
				}

				pV1 = edge->GetStartVertex( );
				pV2 = edge->GetEndVertex( );
				if ( numEdges == count + 1 ) pV3 = listVerticesSup[ 0 ];
				else
					pV3 = listVerticesSup[ count + 1 ];
				pV4 = listVerticesSup[ count ];
				PBrep->CreatePolyQuad( pRegion, pShell, pV1, pV2, pV3, pV4, faceSup );

				// Chequeo de si las aristas simetricas son pliegues
				if ( faceSup && IsEdgeCrease( edge ) ) {
					faceSup->GetPolyEdges( edgesAux );
					if ( edgesAux.GetSize( ) )
						if ( edgesAux[ 0 ] ) edgesAux[ 0 ]->SetUserFloat1( edge->GetUserFloat1( ) );
				}

				count++;
			}
			facesGroupAdded.Add( face );
		}
	}

	RemoveSelectedFaces( OGLTransf, true );

	// select faces
	PBrep->GetPolyFaces( faces );
	numFaces = (int) faces.GetSize( );
	for ( i = 0; i < numFaces; i++ ) {
		face = faces[ i ];
		typeAuxInt = face->GetUserIndex2( );
		if ( typeAuxInt > 0 ) {
			typeSel = ( typeAuxInt == (int) SelectedElementType::LastUserSelection ) ? SelectedElementType::LastUserSelection : SelectedElementType::UserSelection;
			SelectFace( OGLTransf, face->GetIndexExt( ), typeSel );
		}
	}
	SetDirtyFaceSelection( true );

	InitUserIndex2( true, true, true );

	if ( updateOGLList && RefEnt ) RefEnt->UpdateOGLListFromPBrep( OGLTransf, true );

	return true;
}

//------------------------------------------------------------------------------

bool TPBrepData::ExtrudeSelectedFacesByNormalFace( TOGLTransf *OGLTransf, float length, int sign, bool updateOGLList )
{
	int i, j, numFaces, numEdges, count, *listFaces, typeAuxInt;
	double vertexTol;
	SelectedElementType typeSel;
	IwVector3d pt;
	IwPolyVertex *pV1, *pV2, *pV3, *pV4, *pVAux;
	IwVector3d extrudeDir, extrudeDirUnit;
	IwPolyFace *face, *faceSup;
	IwPolyEdge *edge, *edgeSym;
	IwPolyShell *pShell;
	IwPolyRegion *pRegion;
	IwTArray<IwPolyVertex *> listVerticesSup;
	IwTA<IwPolyEdge *> listEdges, edgesAux;
	IwTA<IwPolyFace *> faces;

	if ( !RefEnt || !PBrep ) return false;
	listFaces = GetFaces( OGLTransf, SelectedElementType::AllSelected, numFaces );
	if ( !listFaces ) return false;

	MoveVertUser.Clear( );
	vertexTol = RES_COMP;
	InitUserIndex2( true, true, true );

	for ( i = 0; i < numFaces; i++ ) {
		face = GetPBrepFace( OGLTransf, listFaces[ i ] );
		if ( face == NULL ) continue;

		face->GetPolyEdges( listEdges );
		numEdges = (int) listEdges.GetSize( );
		for ( j = 0; j < numEdges; j++ ) {
			edge = listEdges[ j ];
			edgeSym = edge->GetSymmetricPolyEdge( );
			count = edge->GetUserIndex2( );
			if ( edgeSym ) count = max( count, (int) edgeSym->GetUserIndex2( ) );
			edge->SetUserIndex2( ++count );
			if ( edgeSym ) edgeSym->SetUserIndex2( count );
		}
	}

	for ( i = 0; i < numFaces; i++ ) {
		face = GetPBrepFace( OGLTransf, listFaces[ i ] );
		if ( face == NULL ) continue;

		extrudeDir = face->GetNormal( true ) * length * sign;
		extrudeDirUnit = extrudeDir / sign;
		extrudeDirUnit.Unitize( );

		pShell = face->GetPolyShell( );
		pRegion = pShell->GetPolyRegion( );

		face->GetPolyEdges( listEdges );
		numEdges = (int) listEdges.GetSize( );

		listVerticesSup.RemoveAll( );
		// duplicate face
		for ( j = 0; j < numEdges; j++ ) {
			edge = listEdges[ j ];

			pV1 = edge->GetStartVertex( );
			pt = pV1->GetPoint( );
			pt.x += extrudeDir.x;
			pt.y += extrudeDir.y;
			pt.z += extrudeDir.z;
			pVAux = new IwPolyVertex( _GetSMLib( )->GetContext( ), *PBrep, pt, vertexTol );
			listVerticesSup.Push( pVAux );

			MoveVertUser.Directions.push_back( extrudeDirUnit );
			MoveVertUser.Vertices.Add( pVAux );
		}
		PBrep->CreatePolyFace( pRegion, pShell, listVerticesSup, faceSup );

		// use UserIndex2 to select face after delete
		faceSup->SetUserIndex2( SelectedF[ listFaces[ i ] ].i );

		// create one face for each edge
		count = 0;
		for ( j = 0; j < numEdges; j++ ) {
			edge = listEdges[ j ];

			pV1 = edge->GetStartVertex( );
			pV2 = edge->GetEndVertex( );
			if ( numEdges == count + 1 ) pV3 = listVerticesSup[ 0 ];
			else
				pV3 = listVerticesSup[ count + 1 ];
			pV4 = listVerticesSup[ count ];
			PBrep->CreatePolyQuad( pRegion, pShell, pV1, pV2, pV3, pV4, faceSup );

			// Chequeo de si las aristas simetricas son pliegues
			if ( faceSup && IsEdgeCrease( edge ) ) {
				faceSup->GetPolyEdges( edgesAux );
				if ( edgesAux.GetSize( ) )
					if ( edgesAux[ 0 ] ) edgesAux[ 0 ]->SetUserFloat1( edge->GetUserFloat1( ) );
			}

			count++;
		}
	}

	RemoveSelectedFaces( OGLTransf, true );

	// select faces
	PBrep->GetPolyFaces( faces );
	numFaces = (int) faces.GetSize( );
	for ( i = 0; i < numFaces; i++ ) {
		face = faces[ i ];
		typeAuxInt = face->GetUserIndex2( );
		if ( typeAuxInt > 0 ) {
			typeSel = ( typeAuxInt == (int) SelectedElementType::LastUserSelection ) ? SelectedElementType::LastUserSelection : SelectedElementType::UserSelection;
			SelectFace( OGLTransf, face->GetIndexExt( ), typeSel );
		}
	}
	SetDirtyFaceSelection( true );

	InitUserIndex2( true, true, true );

	if ( updateOGLList && RefEnt ) RefEnt->UpdateOGLListFromPBrep( OGLTransf, true );

	delete[] listFaces;

	return true;
}

//------------------------------------------------------------------------------

bool TPBrepData::ExtrudeSelectedGroupFacesByVertexNormal( TOGLTransf *OGLTransf, float length, int sign, bool updateOGLList, bool creaseUpBorder, double valcrease )
{
	int g, i, j, numFaces, numEdges, count, typeAuxInt;
	double vertexTol;
	ULONG auxNum;
	SelectedElementType typeSel;
	T3DPoint ptEnd;
	T3DVector dirVertex;
	IwVector3d pt;
	IwPolyVertex *pV1, *pV2, *pV3, *pV4, *pVAux;
	IwVector3d extrudeDir, extrudeDirUnit;
	IwPolyFace *face, *faceSup;
	IwPolyEdge *edge, *edgeSym, *edgeAux;
	IwPolyShell *pShell;
	IwPolyRegion *pRegion;
	IwTArray<IwPolyVertex *> listVerticesSup;
	IwTA<IwPolyEdge *> listEdges, edgesAux;
	IwTA<IwPolyFace *> faces, facesGroupAdded;
	vector<int> listFaces;
	vector<vector<int> > groups;
	IwVector3d norm;

	if ( !RefEnt || !PBrep ) return false;

	// extrude direction
	if ( !GetDisjointGroupFaces( OGLTransf, &groups ) ) return false;

	MoveVertUser.Clear( );
	vertexTol = RES_COMP;
	InitUserIndex2( true, true, true );

	for ( g = 0; g < (int) groups.size( ); g++ ) {
		listFaces = groups.at( g );
		numFaces = listFaces.size( );

		faces.RemoveAll( );
		for ( i = 0; i < numFaces; i++ )
			faces.Add( GetPBrepFace( OGLTransf, listFaces[ i ] ) );

		facesGroupAdded.RemoveAll( );

		for ( i = 0; i < numFaces; i++ ) {
			face = GetPBrepFace( OGLTransf, listFaces[ i ] );
			if ( face == NULL ) continue;

			face->GetPolyEdges( listEdges );
			numEdges = (int) listEdges.GetSize( );
			for ( j = 0; j < numEdges; j++ ) {
				edge = listEdges[ j ];
				edgeSym = edge->GetSymmetricPolyEdge( );
				count = edge->GetUserIndex2( );
				if ( edgeSym ) count = max( count, (int) edgeSym->GetUserIndex2( ) );
				edge->SetUserIndex2( ++count );
				if ( edgeSym ) edgeSym->SetUserIndex2( count );
			}
		}

		for ( i = 0; i < numFaces; i++ ) {
			face = GetPBrepFace( OGLTransf, listFaces[ i ] );
			if ( face == NULL ) continue;

			pShell = face->GetPolyShell( );
			pRegion = pShell->GetPolyRegion( );

			face->GetPolyEdges( listEdges );
			numEdges = (int) listEdges.GetSize( );

			listVerticesSup.RemoveAll( );

			// duplicate face
			for ( j = 0; j < numEdges; j++ ) {
				edge = listEdges[ j ];

				pV1 = edge->GetStartVertex( );

				// testeo de edges degenerados
				if ( AreAnyNonSelFaces( OGLTransf, pV1 ) && !IsFaceConnectedToSelGroupByVertex( OGLTransf, face, &facesGroupAdded, pV1 ) ) pV1->SetUserIndex2( 0 );

				if ( (int) pV1->GetUserIndex2( ) < g + 1 ) {
					dirVertex = GetNormalPBrepVertex( OGLTransf, pV1, &faces );
					ptEnd = dirVertex.org + dirVertex.size;
					extrudeDir = IwVector3d( IwPoint3d( dirVertex.org.x, dirVertex.org.y, dirVertex.org.z ), IwPoint3d( ptEnd.x, ptEnd.y, ptEnd.z ) ) * length * sign;
					extrudeDirUnit = extrudeDir * sign;
					extrudeDirUnit.Unitize( );

					pt = pV1->GetPoint( );
					pt.x += extrudeDir.x;
					pt.y += extrudeDir.y;
					pt.z += extrudeDir.z;
					pVAux = new IwPolyVertex( _GetSMLib( )->GetContext( ), *PBrep, pt, vertexTol );
					pV1->SetUserPtr1( pVAux );
					pV1->SetUserIndex2( g + 1 );
				}

				pVAux = (IwPolyVertex *) pV1->GetUserPtr1( );
				listVerticesSup.Push( pVAux );

				if ( !MoveVertUser.Vertices.FindElement( pVAux, auxNum ) ) {
					MoveVertUser.Directions.push_back( extrudeDirUnit );
					MoveVertUser.Vertices.Add( pVAux );
				}
			}
			PBrep->CreatePolyFace( pRegion, pShell, listVerticesSup, faceSup );

			// use UserIndex2 to select face after delete
			faceSup->SetUserIndex2( SelectedF[ listFaces[ i ] ].i );

			// create one face for each edge
			count = 0;
			for ( j = 0; j < numEdges; j++ ) {
				edge = listEdges[ j ];

				// dont add midle face
				if ( edge->GetUserIndex2( ) > 1 ) {
					count++;
					continue;
				}

				pV1 = edge->GetStartVertex( );
				pV2 = edge->GetEndVertex( );
				if ( numEdges == count + 1 ) pV3 = listVerticesSup[ 0 ];
				else
					pV3 = listVerticesSup[ count + 1 ];
				pV4 = listVerticesSup[ count ];
				PBrep->CreatePolyQuad( pRegion, pShell, pV1, pV2, pV3, pV4, faceSup );

				// Chequeo de si las aristas simetricas son pliegues
				if ( faceSup && IsEdgeCrease( edge ) ) {
					faceSup->GetPolyEdges( edgesAux );
					if ( edgesAux.GetSize( ) )
						if ( edgesAux[ 0 ] ) edgesAux[ 0 ]->SetUserFloat1( edge->GetUserFloat1( ) );
				}

				if ( creaseUpBorder ) {
					pV3->FindPolyEdgeTowards( pV4, edgeAux );
					if ( edgeAux ) {
						edgeAux->SetUserFloat1( valcrease );
						edgeSym = edgeAux->GetSymmetricPolyEdge( );
						if ( edgeSym ) edgeSym->SetUserFloat1( valcrease );
					}
				}

				count++;
			}
			facesGroupAdded.Add( face );
		}
	}

	RemoveSelectedFaces( OGLTransf, true );

	// select faces
	faces.RemoveAll( );
	PBrep->GetPolyFaces( faces );
	numFaces = (int) faces.GetSize( );
	for ( i = 0; i < numFaces; i++ ) {
		face = faces[ i ];
		typeAuxInt = face->GetUserIndex2( );
		if ( typeAuxInt > 0 ) {
			typeSel = ( typeAuxInt == (int) SelectedElementType::LastUserSelection ) ? SelectedElementType::LastUserSelection : SelectedElementType::UserSelection;
			SelectFace( OGLTransf, face->GetIndexExt( ), typeSel );
		}
	}
	SetDirtyFaceSelection( true );

	InitUserIndex2( true, true, true );

	if ( updateOGLList && RefEnt ) RefEnt->UpdateOGLListFromPBrep( OGLTransf, true );

	return true;
}

//------------------------------------------------------------------------------

bool TPBrepData::ExtrudeSelectedEdges( TOGLTransf *OGLTransf, float incrX, float incrY, float incrZ, TExtrudeEdgeType extrudeedgetype, int sign, bool createFaces, TNPlane extrusionplane, int indexvertex, bool updateOGLList )
{
	float mod;
	T3DPoint incr;
	T3DVector v;

	incr = T3DPoint( incrX, incrY, incrZ );
	v = T3DVector( T3DSize( incr ) );
	mod = v.Modulo( );
	if ( mod < RES_COMP ) return false;
	if ( !createFaces ) return TranslateEditedVertexs( OGLTransf, mod * sign );
	else if ( extrudeedgetype == TExtrudeEdgeType::ByEdges || extrudeedgetype == TExtrudeEdgeType::ByEdges_UnifiedDir || extrudeedgetype == TExtrudeEdgeType::ByNormalVertex )
		return ExtrudeSelectedEdgesByExtrudeType( OGLTransf, extrudeedgetype, mod, plNone, indexvertex, updateOGLList );
	else if ( extrudeedgetype == TExtrudeEdgeType::ByAxis )
		return ExtrudeSelectedEdgesByExtrudeType( OGLTransf, extrudeedgetype, mod, extrusionplane, indexvertex, updateOGLList );

	return false;
}

//------------------------------------------------------------------------------

bool TPBrepData::ExtrudeSelectedEdgesByExtrudeType( TOGLTransf *OGLTransf, TExtrudeEdgeType extrudeedgetype, float length, TNPlane extrusionplane, int indexvertex, bool updateOGLList )
{
	bool isclosed;
	int *selectedList, num, i, j, numEdges;
	ULONG auxNum;
	double vertexTol;
	T3DVector normal;
	IwVector3d pt, norm, extrudeDir, extrudeDirIni, extrudeDirUnit;
	IwPolyEdge *edge;
	IwTA<IwPolyEdge *> edgesAdded, edgesaux;
	IwTA<IwTA<IwPolyEdge *> > edgesordered;
	IwPolyVertex *pV1, *pV2, *pV3, *pV4, *vertex;
	IwTArray<IwPolyVertex *> vertexs, listVerticesAdded, vertexsforface;
	IwTArray<IwTArray<IwPolyVertex *> > vertexsordered;
	IwPolyFace *face;
	IwTA<IwPolyFace *> facesGroupAdded;
	IwPolyShell *pShell;
	IwPolyRegion *pRegion;

	if ( !RefEnt || !PBrep ) return false;

	// Obtenemos la lista de aristas seleccionadas
	selectedList = GetEdges( OGLTransf, SelectedElementType::AllSelected, num );
	if ( num == 0 ) return false;

	// Si alguna arista no es borde, no dejamos hacerlo (pq la subdivision no lo contempla). Si se quisiera hacer, hay que hacer una malla aparte y marcar las aristas como esquinas
	for ( i = 0; i < num; i++ ) {
		edge = GetPBrepEdge( OGLTransf, selectedList[ i ] );
		if ( !edge ) continue;
		if ( !edge->IsBoundary( ) ) continue;
		edgesaux.Add( edge );
	}
	if ( selectedList ) delete[] selectedList;

	GetEdgesOrdered( &edgesaux, &edgesordered );
	for ( i = 0; i < (int) edgesordered.GetSize( ); i++ ) {
		vertexs.RemoveAll( );
		for ( j = 0; j < (int) edgesordered[ i ].GetSize( ); j++ ) {
			edge = edgesordered[ i ][ j ];
			vertexs.AddUnique( edge->GetStartVertex( ) );
			vertexs.AddUnique( edge->GetEndVertex( ) );
		}
		vertexsordered.Add( vertexs );
	}

	MoveVertUser.Clear( );
	vertexTol = RES_COMP;
	pShell = 0;
	pRegion = 0;

	// ByEdges, ByEdges_UnifiedDir, ByNormalVertex, ByAxis, ByDirection (4)
	if ( extrudeedgetype == TExtrudeEdgeType::ByEdges_UnifiedDir ) {
		vertex = GetPBrepVertex( OGLTransf, indexvertex );
		if ( vertex ) GetNormalVertexToExtrudeEdge( OGLTransf, extrudeedgetype, vertex, &normal, extrusionplane );
		else
			return false;
	}

	// Para cada grupo de vertices consecutivos creamos su conjunto de caras
	for ( i = 0; i < (int) vertexsordered.GetSize( ); i++ ) {
		listVerticesAdded.RemoveAll( );
		if ( vertexsordered[ i ].GetSize( ) < 2 ) continue;

		edge = 0;
		if ( vertexsordered[ i ][ 0 ]->FindPolyEdgeTowards( vertexsordered[ i ][ 1 ], edge ) != IW_SUCCESS || !edge ) vertexsordered[ i ].ReverseArray( 0, vertexsordered[ i ].GetSize( ) );

		// Comprobación de si es cerrada
		vertexsordered[ i ][ vertexsordered[ i ].GetSize( ) - 1 ]->FindPolyEdgeTowards( vertexsordered[ i ][ 0 ], edge );
		if ( edge && IsEdgeSelected( OGLTransf, edge->GetUserIndex1( ) ) ) isclosed = true;
		else
			isclosed = false;

		for ( j = 1; j < (int) vertexsordered[ i ].GetSize( ); j++ ) {
			vertex = vertexsordered[ i ][ j - 1 ];
			pV1 = vertexsordered[ i ][ j ];
			if ( vertex->FindPolyEdgeTowards( vertexsordered[ i ][ j ], edge ) != IW_SUCCESS || !edge ) break;
			if ( !edge ) break;

			if ( !pShell ) {
				pShell = edge->GetPolyFace( )->GetPolyShell( );
				pRegion = pShell->GetPolyRegion( );
			}

			if ( extrudeedgetype != TExtrudeEdgeType::ByEdges_UnifiedDir ) GetNormalVertexToExtrudeEdge( OGLTransf, extrudeedgetype, vertex, &normal, extrusionplane );

			extrudeDir.x = normal.size.cx * length;
			extrudeDir.y = normal.size.cy * length;
			extrudeDir.z = normal.size.cz * length;
			extrudeDirUnit = extrudeDir;
			extrudeDirUnit.Unitize( );
			if ( j == 1 ) extrudeDirIni = extrudeDir;

			pt = vertexsordered[ i ][ j - 1 ]->GetPoint( );
			pt.x += extrudeDir.x;
			pt.y += extrudeDir.y;
			pt.z += extrudeDir.z;
			pV1 = new IwPolyVertex( _GetSMLib( )->GetContext( ), *PBrep, pt, vertexTol );
			listVerticesAdded.Push( pV1 );
			if ( !MoveVertUser.Vertices.FindElement( pV1, auxNum ) ) {
				MoveVertUser.Directions.push_back( extrudeDirUnit );
				MoveVertUser.VerticesOrg.Add( vertexsordered[ i ][ j - 1 ] );
				MoveVertUser.Vertices.Add( pV1 );
			}

			if ( j == (int) vertexsordered[ i ].GetSize( ) - 1 ) {
				if ( !isclosed ) {
					vertex = vertexsordered[ i ][ j ];
					if ( extrudeedgetype != TExtrudeEdgeType::ByEdges_UnifiedDir ) GetNormalVertexToExtrudeEdge( OGLTransf, extrudeedgetype, vertex, &normal, extrusionplane );

					extrudeDir.x = normal.size.cx * length;
					extrudeDir.y = normal.size.cy * length;
					extrudeDir.z = normal.size.cz * length;
					extrudeDirUnit = extrudeDir;
					extrudeDirUnit.Unitize( );
				} else {
					vertex = vertexsordered[ i ][ j ];
					if ( extrudeedgetype != TExtrudeEdgeType::ByEdges_UnifiedDir ) GetNormalVertexToExtrudeEdge( OGLTransf, extrudeedgetype, vertex, &normal, extrusionplane );
					extrudeDir.x = normal.size.cx * length;
					extrudeDir.y = normal.size.cy * length;
					extrudeDir.z = normal.size.cz * length;
					extrudeDirUnit = extrudeDir;
					extrudeDirUnit.Unitize( );
				}

				pt = vertexsordered[ i ][ j ]->GetPoint( );
				pt.x += extrudeDir.x;
				pt.y += extrudeDir.y;
				pt.z += extrudeDir.z;
				pV2 = new IwPolyVertex( _GetSMLib( )->GetContext( ), *PBrep, pt, vertexTol );
				listVerticesAdded.Push( pV2 );

				if ( !MoveVertUser.Vertices.FindElement( pV2, auxNum ) ) {
					MoveVertUser.Directions.push_back( extrudeDirUnit );
					MoveVertUser.VerticesOrg.Add( vertexsordered[ i ][ j ] );
					MoveVertUser.Vertices.Add( pV2 );
				}
			}
		}

		if ( !pShell ) return false;
		if ( listVerticesAdded.GetSize( ) != vertexsordered[ i ].GetSize( ) ) continue; // No ha podido replicar algun vertice

		// Vamos a crear las caras para cada 4 vertices (2 de cada lista)
		for ( j = 1; j < (int) vertexsordered[ i ].GetSize( ); j++ ) {
			pV1 = PBrepVertexs[ vertexsordered[ i ][ j ]->GetIndexExt( ) ];
			pV2 = PBrepVertexs[ vertexsordered[ i ][ j - 1 ]->GetIndexExt( ) ];
			pV3 = listVerticesAdded[ j - 1 ];
			pV4 = listVerticesAdded[ j ];
			vertexsforface.RemoveAll( );
			vertexsforface.Add( pV1 );
			vertexsforface.Add( pV2 );
			vertexsforface.Add( pV3 );
			vertexsforface.Add( pV4 );
			PBrep->CreatePolyFace( pRegion, pShell, vertexsforface, face );
			pV3->FindPolyEdgeTowards( pV4, edge );
			if ( edge ) edgesAdded.Add( edge );
		}
		if ( isclosed ) {
			pV1 = PBrepVertexs[ vertexsordered[ i ][ 0 ]->GetIndexExt( ) ]; // para que sea el mismo puntero
			pV2 = PBrepVertexs[ vertexsordered[ i ][ vertexsordered[ i ].GetSize( ) - 1 ]->GetIndexExt( ) ];
			pV3 = listVerticesAdded[ listVerticesAdded.GetSize( ) - 1 ];
			pV4 = listVerticesAdded[ 0 ];
			vertexsforface.RemoveAll( );
			vertexsforface.Add( pV1 );
			vertexsforface.Add( pV2 );
			vertexsforface.Add( pV3 );
			vertexsforface.Add( pV4 );
			PBrep->CreatePolyFace( pRegion, pShell, vertexsforface, face );
			pV3->FindPolyEdgeTowards( pV4, edge );
			if ( edge ) edgesAdded.Add( edge );
		}
	}

	UpdateTopology( OGLTransf );
	UnSelectAllEdges( OGLTransf );
	// select edges
	numEdges = (int) edgesAdded.GetSize( );
	for ( i = 0; i < numEdges; i++ ) {
		edge = edgesAdded[ i ];
		SelectEdge( OGLTransf, edge->GetUserIndex1( ), SelectedElementType::UserSelection );
	}
	SetDirtyEdgeSelection( true );

	if ( updateOGLList && RefEnt ) RefEnt->UpdateOGLListFromPBrep( OGLTransf, true );

	return true;
}

//------------------------------------------------------------------------------

bool TPBrepData::ExtrudeSelectedEdgesByDirection( TOGLTransf *OGLTransf, TNMatrix *mat, TNRotateMatrix *matrot, IwTA<int> *indexes, IwTA<T3DPoint> *positions, bool updateOGLList )
{
	bool isclosed;
	int *selectedList, num, i, j, numEdges;
	IwTA<ULONG> indexesfounded;
	double vertexTol;
	TPoint ptraster;
	T3DPoint pt3d, ptpersp;
	IwVector3d norm;
	IwPoint3d pt;
	IwPolyEdge *edge;
	IwTA<IwPolyEdge *> edgesAdded, edgesaux;
	IwTA<IwTA<IwPolyEdge *> > edgesordered;
	IwPolyVertex *pV1, *pV2, *pV3, *pV4, *vertex;
	IwTArray<IwPolyVertex *> vertexs, listVerticesAdded, vertexsforface;
	IwTArray<IwTArray<IwPolyVertex *> > vertexsordered;
	IwPolyFace *face;
	IwTA<IwPolyFace *> facesGroupAdded;
	IwPolyShell *pShell;
	IwPolyRegion *pRegion;

	if ( !RefEnt || !PBrep ) return false;

	// Obtenemos la lista de aristas seleccionadas
	selectedList = GetEdges( OGLTransf, SelectedElementType::AllSelected, num );
	if ( num == 0 ) return false;

	// Si alguna arista no es borde, no dejamos hacerlo (pq la subdivision no lo contempla). Si se quisiera hacer, hay que hacer una malla aparte y marcar las aristas como esquinas
	for ( i = 0; i < num; i++ ) {
		edge = GetPBrepEdge( OGLTransf, selectedList[ i ] );
		if ( !edge ) continue;
		if ( !edge->IsBoundary( ) ) continue;
		edgesaux.Add( edge );
	}
	if ( selectedList ) delete[] selectedList;

	GetEdgesOrdered( &edgesaux, &edgesordered );
	for ( i = 0; i < (int) edgesordered.GetSize( ); i++ ) {
		vertexs.RemoveAll( );
		for ( j = 0; j < (int) edgesordered[ i ].GetSize( ); j++ ) {
			edge = edgesordered[ i ][ j ];
			vertexs.AddUnique( edge->GetStartVertex( ) );
			vertexs.AddUnique( edge->GetEndVertex( ) );
		}
		vertexsordered.Add( vertexs );
	}

	MoveVertUser.Clear( );
	vertexTol = RES_COMP;
	pShell = 0;
	pRegion = 0;

	// Para cada grupo de vertices consecutivos creamos su conjunto de caras
	for ( i = 0; i < (int) vertexsordered.GetSize( ); i++ ) {
		listVerticesAdded.RemoveAll( );
		if ( vertexsordered[ i ].GetSize( ) < 2 ) continue;

		edge = 0;
		if ( vertexsordered[ i ][ 0 ]->FindPolyEdgeTowards( vertexsordered[ i ][ 1 ], edge ) != IW_SUCCESS || !edge ) vertexsordered[ i ].ReverseArray( 0, vertexsordered[ i ].GetSize( ) );

		// Comprobación de si es cerrada
		vertexsordered[ i ][ vertexsordered[ i ].GetSize( ) - 1 ]->FindPolyEdgeTowards( vertexsordered[ i ][ 0 ], edge );
		if ( edge && IsEdgeSelected( OGLTransf, edge->GetUserIndex1( ) ) ) isclosed = true;
		else
			isclosed = false;

		for ( j = 1; j < (int) vertexsordered[ i ].GetSize( ); j++ ) {
			vertex = vertexsordered[ i ][ j - 1 ];
			pV1 = vertexsordered[ i ][ j ];
			if ( vertex->FindPolyEdgeTowards( vertexsordered[ i ][ j ], edge ) != IW_SUCCESS || !edge ) break;
			if ( !edge ) break;

			if ( !pShell ) {
				pShell = edge->GetPolyFace( )->GetPolyShell( );
				pRegion = pShell->GetPolyRegion( );
			}

			pt = vertexsordered[ i ][ j - 1 ]->GetPoint( );
			pt3d = T3DPoint( pt.x, pt.y, pt.z );
			if ( mat ) pt3d.ApplyMatrix( *mat );
			else if ( positions && indexes && ( *indexes ).FindElements( vertexsordered[ i ][ j - 1 ]->GetIndexExt( ), indexesfounded ) ) {
				if ( indexesfounded.GetSize( ) > 0 ) pt3d = ( *positions )[ indexesfounded[ 0 ] ];
				if ( indexesfounded.GetSize( ) > 1 ) { // cambiamos el vertice original
					vertexsordered[ i ][ j - 1 ]->GetPointPtr( )->x = ( *positions )[ indexesfounded[ 1 ] ].x;
					vertexsordered[ i ][ j - 1 ]->GetPointPtr( )->y = ( *positions )[ indexesfounded[ 1 ] ].y;
					vertexsordered[ i ][ j - 1 ]->GetPointPtr( )->z = ( *positions )[ indexesfounded[ 1 ] ].z;
				}
			}

			pt = IwPoint3d( pt3d.x, pt3d.y, pt3d.z );

			pV1 = new IwPolyVertex( _GetSMLib( )->GetContext( ), *PBrep, pt, vertexTol );
			listVerticesAdded.Push( pV1 );

			if ( j == (int) vertexsordered[ i ].GetSize( ) - 1 ) {
				pt = vertexsordered[ i ][ j ]->GetPoint( );
				pt3d = T3DPoint( pt.x, pt.y, pt.z );
				if ( mat ) pt3d.ApplyMatrix( *mat );
				else if ( positions && indexes && ( *indexes ).FindElements( vertexsordered[ i ][ j ]->GetIndexExt( ), indexesfounded ) ) {
					if ( indexesfounded.GetSize( ) > 0 ) pt3d = ( *positions )[ indexesfounded[ 0 ] ];
					if ( indexesfounded.GetSize( ) > 1 ) { // cambiamos el vertice original
						vertexsordered[ i ][ j ]->GetPointPtr( )->x = ( *positions )[ indexesfounded[ 1 ] ].x;
						vertexsordered[ i ][ j ]->GetPointPtr( )->y = ( *positions )[ indexesfounded[ 1 ] ].y;
						vertexsordered[ i ][ j ]->GetPointPtr( )->z = ( *positions )[ indexesfounded[ 1 ] ].z;
					}
				}
				pt = IwPoint3d( pt3d.x, pt3d.y, pt3d.z );
				pV2 = new IwPolyVertex( _GetSMLib( )->GetContext( ), *PBrep, pt, vertexTol );
				listVerticesAdded.Push( pV2 );
			}
		}

		if ( !pShell ) return false;
		if ( listVerticesAdded.GetSize( ) != vertexsordered[ i ].GetSize( ) ) continue; // No ha podido replicar algun vertice

		// Vamos a crear las caras para cada 4 vertices (2 de cada lista)
		for ( j = 1; j < (int) vertexsordered[ i ].GetSize( ); j++ ) {
			pV1 = PBrepVertexs[ vertexsordered[ i ][ j ]->GetIndexExt( ) ];
			pV2 = PBrepVertexs[ vertexsordered[ i ][ j - 1 ]->GetIndexExt( ) ];
			pV3 = listVerticesAdded[ j - 1 ];
			pV4 = listVerticesAdded[ j ];
			vertexsforface.RemoveAll( );
			vertexsforface.Add( pV1 );
			vertexsforface.Add( pV2 );
			vertexsforface.Add( pV3 );
			vertexsforface.Add( pV4 );
			PBrep->CreatePolyFace( pRegion, pShell, vertexsforface, face );
			pV3->FindPolyEdgeTowards( pV4, edge );
			if ( edge ) edgesAdded.Add( edge );
		}
		if ( isclosed ) {
			pV1 = PBrepVertexs[ vertexsordered[ i ][ 0 ]->GetIndexExt( ) ]; // para que sea el mismo puntero
			pV2 = PBrepVertexs[ vertexsordered[ i ][ vertexsordered[ i ].GetSize( ) - 1 ]->GetIndexExt( ) ];
			pV3 = listVerticesAdded[ listVerticesAdded.GetSize( ) - 1 ];
			pV4 = listVerticesAdded[ 0 ];
			vertexsforface.RemoveAll( );
			vertexsforface.Add( pV1 );
			vertexsforface.Add( pV2 );
			vertexsforface.Add( pV3 );
			vertexsforface.Add( pV4 );
			PBrep->CreatePolyFace( pRegion, pShell, vertexsforface, face );
			pV3->FindPolyEdgeTowards( pV4, edge );
			if ( edge ) edgesAdded.Add( edge );
		}
	}

	// Rotamos los vertices originales en base a la matriz matrot
	if ( mat && matrot && !( *matrot ).IsIdentity( ) ) {
		for ( i = 0; i < (int) vertexsordered.GetSize( ); i++ ) {
			for ( j = 0; j < (int) vertexsordered[ i ].GetSize( ); j++ ) {
				pt = vertexsordered[ i ][ j ]->GetPoint( );
				pt3d = T3DPoint( pt.x, pt.y, pt.z );
				pt3d.ApplyMatrix( *matrot );
				vertexsordered[ i ][ j ]->GetPointPtr( )->x = pt3d.x;
				vertexsordered[ i ][ j ]->GetPointPtr( )->y = pt3d.y;
				vertexsordered[ i ][ j ]->GetPointPtr( )->z = pt3d.z;
			}
		}
	}

	UpdateTopology( OGLTransf );
	UnSelectAllEdges( OGLTransf );
	// select edges
	numEdges = (int) edgesAdded.GetSize( );
	for ( i = 0; i < numEdges; i++ ) {
		edge = edgesAdded[ i ];
		SelectEdge( OGLTransf, edge->GetUserIndex1( ), SelectedElementType::UserSelection );
	}
	SetDirtyEdgeSelection( true );

	if ( updateOGLList && RefEnt ) RefEnt->UpdateOGLListFromPBrep( OGLTransf, true );

	return true;
}

//------------------------------------------------------------------------------

bool TPBrepData::IsBoundaryEdge( int ind )
{
	if ( ind < 0 || ind >= (int) PBrepEdges.GetSize( ) ) return false;

	return PBrepEdges[ ind ]->IsBoundary( );
}

//------------------------------------------------------------------------------
// Inset
// type = 0 -> inset por cara
// type = 1 -> inset por grupo
// si el signo es positivo, la flecha se mueve hacia fuera de la cara y no hay que hacer inset agregando caras
bool TPBrepData::InsetSelectedFaces( TOGLTransf *OGLTransf, float incrX, float incrY, float incrZ, int type, int sign, bool createFaces, bool normalizeDirs, bool updateOGLList )
{
	bool change, insetEachFace;
	int g, i, j, k, numFaces, numEdges, numVertices, count, typeAuxInt, currFace;
	float mod;
	double vertexTol, angle, distMove, distEnd;
	ULONG auxNum;
	IwPoint3d *point;
	T3DPoint pt2;
	SelectedElementType typeSel;
	IwVector3d pt, ptEnd, extrudeDir, dir, dirMove, normalBrepFace;
	IwPolyVertex *pV1, *pV2, *pV3, *pV4, *pVAux;
	IwPolyFace *face, *faceSup;
	IwPolyEdge *edge, *edgeSym, *edgeUse;
	IwPolyVertex *vertex;
	IwPolyShell *pShell;
	IwPolyRegion *pRegion;
	IwTArray<IwPolyVertex *> listVerticesSup, listVerticesSupFull;
	IwTA<IwPolyEdge *> edges, edgesAux;
	IwTA<IwPolyFace *> faces, facesGroupAdded;
	IwTA<IwPolyVertex *> vertices, verticesFace1, verticesFace2;
	vector<int> listFaces;
	vector<vector<int> > groups;
	IwTA<IwPolyVertex *> auxVertices;
	T3DPoint aux, centroid, incr;
	T3DVector v, v1, v2, vAux, norm, axis;
	TNMatrix mat;

	if ( !RefEnt || !PBrep ) return false;
	if ( !GetDisjointGroupFaces( OGLTransf, &groups ) ) return false;

	insetEachFace = type == 0;
	incr = T3DPoint( incrX, incrY, incrZ );
	v = T3DVector( T3DSize( incr ) );
	mod = v.Modulo( );
	if ( mod < RES_COMP ) return false;
	mod *= sign;

	vertexTol = RES_COMP;
	distMove = 20;

	if ( !createFaces ) return TranslateEditedVertexs( OGLTransf, mod, true );

	MoveVertUser.Clear( );
	InitUserIndex2( true, true, true );

	for ( g = 0; g < (int) groups.size( ); g++ ) {
		listFaces = groups.at( g );
		numFaces = listFaces.size( );

		// No se puede hacer un inset hacia fuera
		if ( mod > 0 ) return false;

		facesGroupAdded.RemoveAll( );

		for ( i = 0; i < numFaces; i++ ) {
			face = GetPBrepFace( OGLTransf, listFaces[ i ] );
			if ( face == NULL ) continue;

			face->GetPolyEdges( edges );
			numEdges = (int) edges.GetSize( );
			for ( j = 0; j < numEdges; j++ ) {
				edge = edges[ j ];
				edgeSym = edge->GetSymmetricPolyEdge( );
				count = edge->GetUserIndex2( );
				if ( edgeSym ) count = max( count, (int) edgeSym->GetUserIndex2( ) );
				edge->SetUserIndex2( ++count );
				if ( edgeSym ) edgeSym->SetUserIndex2( count );
			}
		}

		for ( i = 0; i < numFaces; i++ ) {
			face = GetPBrepFace( OGLTransf, listFaces[ i ] );
			if ( face == NULL ) continue;

			pShell = face->GetPolyShell( );
			pRegion = pShell->GetPolyRegion( );

			face->GetPolyEdges( edges );
			numEdges = (int) edges.GetSize( );

			listVerticesSup.RemoveAll( );
			// duplicate face
			for ( j = 0; j < numEdges; j++ ) {
				edge = edges[ j ];
				pV1 = edge->GetStartVertex( );

				// testeo de edges degenerados
				if ( !insetEachFace && AreAnyNonSelFaces( OGLTransf, pV1 ) && !IsFaceConnectedToSelGroupByVertex( OGLTransf, face, &facesGroupAdded, pV1 ) ) pV1->SetUserIndex2( 0 );

				if ( (int) pV1->GetUserIndex2( ) < g + 1 ) {
					pt = pV1->GetPoint( );
					pt.z += distMove; // desplazamos para no tener caras degeneradas al crear la pbrep

					pVAux = new IwPolyVertex( _GetSMLib( )->GetContext( ), *PBrep, pt, vertexTol );
					pV1->SetUserPtr1( pVAux );
					if ( !insetEachFace ) pV1->SetUserIndex2( g + 1 );
					listVerticesSupFull.Push( pVAux );
				}

				pVAux = (IwPolyVertex *) pV1->GetUserPtr1( );
				listVerticesSup.Push( pVAux );
			}
			PBrep->CreatePolyFace( pRegion, pShell, listVerticesSup, faceSup );

			// use UserIndex2 to select face after delete
			faceSup->SetUserIndex2( SelectedF[ listFaces[ i ] ].i );

			// create one face for each edge
			count = 0;
			for ( j = 0; j < numEdges; j++ ) {
				edge = edges[ j ];

				// dont add midle face
				if ( edge->GetUserIndex2( ) > 1 && !insetEachFace ) {
					count++;
					continue;
				}

				pV1 = edge->GetStartVertex( );
				pV2 = edge->GetEndVertex( );
				if ( numEdges == count + 1 ) pV3 = listVerticesSup[ 0 ];
				else
					pV3 = listVerticesSup[ count + 1 ];
				pV4 = listVerticesSup[ count ];
				PBrep->CreatePolyQuad( pRegion, pShell, pV1, pV2, pV3, pV4, faceSup );

				// Chequeo de si las aristas simetricas son pliegues
				if ( faceSup && IsEdgeCrease( edge ) ) {
					faceSup->GetPolyEdges( edgesAux );
					if ( edgesAux.GetSize( ) )
						if ( edgesAux[ 0 ] ) edgesAux[ 0 ]->SetUserFloat1( edge->GetUserFloat1( ) );
				}

				count++;
			}

			facesGroupAdded.Add( face );
		}
	}

	RemoveSelectedFaces( OGLTransf );

	PBrep->GetPolyEdges( edges );
	numEdges = (int) edges.GetSize( );
	count = 0;
	for ( i = 0; i < numEdges; i++ ) {
		edge = edges[ i ];
		if ( !edge->IsManifold( ) ) {
			count++;
		}
	}

	// select faces
	PBrep->GetPolyFaces( faces );
	numFaces = (int) faces.GetSize( );
	for ( i = 0; i < numFaces; i++ ) {
		face = faces[ i ];
		typeAuxInt = face->GetUserIndex2( );
		if ( typeAuxInt > 0 ) {
			typeSel = ( typeAuxInt == (int) SelectedElementType::LastUserSelection ) ? SelectedElementType::LastUserSelection : SelectedElementType::UserSelection;
			SelectFace( OGLTransf, face->GetIndexExt( ), typeSel );
		}
	}
	SetDirtyFaceSelection( true );

	numVertices = (int) listVerticesSupFull.GetSize( );
	// colocamos los vertices en el punto de partida
	for ( i = 0; i < numVertices; i++ ) {
		vertex = listVerticesSupFull[ i ];
		pt = vertex->GetPoint( );
		pt.z = pt.z - distMove;
		vertex->SetPoint( pt );
	}

	// Recolocamos los vértices en su sitio
	for ( i = 0; i < numVertices; i++ ) {
		norm = T3DVector( T3DPoint( 0, 0, 0 ), T3DPoint( 0, 0, 0 ) );
		vertex = listVerticesSupFull[ i ];
		vertex->GetPolyFaces( faces );
		numFaces = (int) faces.GetSize( );
		count = 0;
		for ( j = 0; j < numFaces; j++ )
			if ( IsFaceSelected( OGLTransf, faces[ j ]->GetIndexExt( ) ) ) count++;
		if ( count == 0 || count == numFaces ) continue;

		vertex->GetPolyEdges( edges );
		numEdges = (int) edges.GetSize( );
		v = T3DVector( T3DPoint( 0, 0, 0 ), T3DPoint( 0, 0, 0 ) );

		for ( j = 0; j < numEdges; j++ ) {
			edge = edges[ j ];
			pt = edge->GetStartPoint( );
			if ( edge->GetStartVertex( ) == vertex ) {
				count = 0;
				ptEnd = edge->GetEndPoint( );

				face = edge->GetPolyFace( );
				if ( face && IsFaceSelected( OGLTransf, face->GetIndexExt( ) ) ) {
					count++;
					edgeUse = edge;
				}

				edge = edge->GetSymmetricPolyEdge( );
				if ( !edge ) continue;
				face = edge->GetPolyFace( );
				if ( face && IsFaceSelected( OGLTransf, face->GetIndexExt( ) ) ) {
					edgeUse = edge;
					count++;
				}
				if ( count != 1 ) continue;

				face = edgeUse->GetPolyFace( );
				if ( face && IsFaceSelected( OGLTransf, face->GetIndexExt( ) ) ) {
					normalBrepFace = face->GetNormal( true );
					norm.size.cx += normalBrepFace.x;
					norm.size.cy += normalBrepFace.y;
					norm.size.cz += normalBrepFace.z;
				}

				vAux = T3DVector( T3DPoint( 0, 0, 0 ), T3DPoint( ptEnd.x - pt.x, ptEnd.y - pt.y, ptEnd.z - pt.z ) );
				vAux.Unitario( );
				v.size += vAux.size;
			}
		}

		angle = M_PI_2;
		norm.Unitario( );
		if ( v.Modulo( ) < RES_GEOM ) {
			axis = vAux;
		} else {
			v.Unitario( );
			axis = norm || v;
			if ( axis.Modulo( ) < RES_GEOM ) {
				axis = vAux || v;
				axis.Unitario( );
				mat = TNRotateMatrix( angle, axis );
				v.ApplyMatrix( mat );
				axis = v;
			}
		}
		axis.Unitario( );
		mat = TNRotateMatrix( angle, axis );
		norm.ApplyMatrix( mat );
		v = norm;
		axis = v || vAux;
		axis.Unitario( );
		angle = GetAngle( &v, &vAux, &axis );
		distEnd = mod / sin( angle );
		pt = vertex->GetPoint( );
		dirMove.x = v.size.cx * distEnd;
		dirMove.y = v.size.cy * distEnd;
		dirMove.z = v.size.cz * distEnd;
		dir = pt + dirMove;
		vertex->SetPoint( dir );
		vertex->SetUserPtr1( new IwPoint3d( dir.x, dir.y, dir.z ) );

		vertex->GetPolyFaces( faces );
		numFaces = (int) faces.GetSize( );
		change = false;

		// criterio de normales para identificar el sentido del movimiento
		currFace = 0;
		for ( currFace = 0; currFace < numFaces; currFace++ ) {
			if ( IsFaceSelected( OGLTransf, faces[ currFace ]->GetIndexExt( ) ) ) {
				normalBrepFace = faces[ currFace ]->GetNormal( true );
				norm = T3DVector( T3DPoint( 0, 0, 0 ), T3DPoint( normalBrepFace.x, normalBrepFace.y, normalBrepFace.z ) );
				change = false;
				faces[ currFace ]->GetPolyVertices( verticesFace1 );
				for ( j = 0; j < numFaces; j++ ) {
					if ( j == currFace ) continue;
					if ( IsFaceSelected( OGLTransf, faces[ j ]->GetIndexExt( ) ) ) continue;

					// tiene que tener al menos dos vértices en común para comparar la normal
					faces[ j ]->GetPolyVertices( verticesFace2 );
					count = 0;
					for ( k = 0; k < (int) verticesFace2.GetSize( ); k++ )
						if ( verticesFace1.FindElement( verticesFace2[ k ], auxNum ) ) count++;
					if ( count < 2 ) continue;

					normalBrepFace = faces[ j ]->GetNormal( true );
					vAux = T3DVector( T3DPoint( 0, 0, 0 ), T3DPoint( normalBrepFace.x, normalBrepFace.y, normalBrepFace.z ) );
					axis = norm || vAux;
					angle = GetAngle( &norm, &vAux, &axis );
					if ( angle > M_PI_2 && angle < 3 * M_PI_2 ) {
						change = true;
						break;
					}
				}
			}
			if ( change ) break;
		}

		if ( change ) {
			dirMove.x = -v.size.cx * distEnd;
			dirMove.y = -v.size.cy * distEnd;
			dirMove.z = -v.size.cz * distEnd;
			dir = pt + dirMove;
			vertex->SetPoint( dir );
			point = (IwPoint3d *) vertex->GetUserPtr1( );
			delete point;
			vertex->SetUserPtr1( new IwPoint3d( dir.x, dir.y, dir.z ) );
		}

		vertex->SetPoint( pt );

		// Guardamos la contraria para que luego cuando se mueva el lenght que le llegue no vuelva a invertir
		MoveVertUser.Directions.push_back( -dirMove );
		MoveVertUser.Vertices.Add( vertex );
	}

	if ( normalizeDirs ) MoveVertUser.Normalize( );

	numVertices = (int) MoveVertUser.Vertices.GetSize( );
	for ( i = 0; i < numVertices; i++ ) {
		vertex = MoveVertUser.Vertices[ i ];
		point = (IwPoint3d *) vertex->GetUserPtr1( );
		vertex->SetPoint( *point );
		delete point;
	}

	InitUserIndex2( true, true, true );

	if ( updateOGLList && RefEnt ) RefEnt->UpdateOGLListFromPBrep( OGLTransf );

	return true;
}

//------------------------------------------------------------------------------
// Bevel
bool TPBrepData::BevelSelectedFaces( TOGLTransf *OGLTransf, float incrX, float incrY, float incrZ, int sign, bool createFaces, bool updateOGLList )
{
	bool vertexFound;
	int i, j, numEdges, numVertices, count;
	float mod;
	ULONG auxNum;
	IwPoint3d *point;
	T3DPoint pt2;
	IwVector3d pt, ptEnd, dir, dirMove;
	IwPolyFace *face, *face1, *face2;
	IwPolyEdge *edge, *edgeSym;
	IwPolyVertex *vertex, *vertexEnd;
	IwTA<IwPolyEdge *> edges;
	IwTA<IwPolyFace *> faces;
	IwTA<IwPolyVertex *> vertices;
	vector<vector<int> > groups;
	IwTA<IwPolyVertex *> auxVertices;
	T3DPoint incr;
	T3DVector v, vAux;

	incr = T3DPoint( incrX, incrY, incrZ );
	v = T3DVector( T3DSize( incr ) );
	mod = v.Modulo( );
	if ( mod < RES_COMP ) return false;

	if ( !createFaces ) return TranslateEditedVertexs( OGLTransf, mod * ( -sign ), true );

	// Creamos un inset con el signo invertido para que vaya estirando hacia fuera la tool
	InsetSelectedFaces( OGLTransf, incrX, incrY, incrZ, 1, -sign, createFaces, false );

	// Desplazamiento para los vértices de la otra parte del bevel
	InitUserIndex2( true, false, false );
	numVertices = (int) MoveVertUser.Vertices.GetSize( );
	for ( i = 0; i < numVertices; i++ ) {
		vertex = MoveVertUser.Vertices[ i ];
		vertex->GetPolyEdges( edges );
		numEdges = (int) edges.GetSize( );
		v = T3DVector( T3DPoint( 0, 0, 0 ), T3DPoint( 0, 0, 0 ) );
		vertexFound = false;
		for ( j = 0; j < numEdges; j++ ) {
			edge = edges[ j ];
			pt = edge->GetStartPoint( );
			if ( edge->GetStartVertex( ) == vertex ) {
				count = 0;
				ptEnd = edge->GetEndPoint( );
				vertexEnd = edge->GetEndVertex( );

				face1 = edge->GetPolyFace( );
				if ( face1 && IsFaceSelected( OGLTransf, face1->GetIndexExt( ) ) ) count++;
				edge = edge->GetSymmetricPolyEdge( );
				if ( !edge ) continue;
				face2 = edge->GetPolyFace( );
				if ( face2 && IsFaceSelected( OGLTransf, face2->GetIndexExt( ) ) ) count++;
				if ( count != 0 ) continue;
				vertexFound = true;
				break;
			}
		}

		if ( !vertexFound ) continue;

		vertexFound = false;
		vertexEnd->GetPolyEdges( edges );
		numEdges = (int) edges.GetSize( );

		for ( j = 0; j < numEdges; j++ ) {
			edge = edges[ j ];
			if ( !edge ) continue;
			vertex = edge->GetStartVertex( );
			if ( vertex != vertexEnd ) continue;

			face = edge->GetPolyFace( );
			if ( face && ( face == face1 || face == face2 ) ) continue;
			edgeSym = edge->GetSymmetricPolyEdge( );
			if ( edgeSym ) {
				face = edgeSym->GetPolyFace( );
				if ( face && ( face == face1 || face == face2 ) ) continue;
			}

			pt = edge->GetStartPoint( );
			ptEnd = edge->GetEndPoint( );

			vAux = T3DVector( T3DPoint( 0, 0, 0 ), T3DPoint( ptEnd.x - pt.x, ptEnd.y - pt.y, ptEnd.z - pt.z ) );
			vAux.Unitario( );
			v.size += vAux.size;
			vertexFound = true;
		}

		if ( !vertexFound ) continue;

		vertex = vertexEnd;
		v.Unitario( );

		pt = vertex->GetPoint( );
		dirMove.x = v.size.cx * mod;
		dirMove.y = v.size.cy * mod;
		dirMove.z = v.size.cz * mod;
		dir = pt + dirMove;
		vertex->SetUserPtr1( new IwPoint3d( dir.x, dir.y, dir.z ) );

		vertex->SetUserIndex2( 1 );
		if ( !MoveVertUser.Vertices.FindElement( vertex, auxNum ) ) {
			MoveVertUser.Directions.push_back( -dirMove );
			MoveVertUser.Vertices.Add( vertex );
		}
	}

	MoveVertUser.Normalize( );
	numVertices = (int) MoveVertUser.Vertices.GetSize( );
	for ( i = 0; i < numVertices; i++ ) {
		vertex = MoveVertUser.Vertices[ i ];
		if ( vertex->GetUserIndex2( ) == 1 ) {
			point = (IwPoint3d *) vertex->GetUserPtr1( );
			vertex->SetPoint( *point );
			delete point;
		}
	}

	InitUserIndex2( true, false, false );
	if ( updateOGLList && RefEnt ) RefEnt->UpdateOGLListFromPBrep( OGLTransf );

	return true;
}

//------------------------------------------------------------------------------

bool TPBrepData::ScaleSelectedEdges( TOGLTransf *OGLTransf, float factorX, float factorY, float factorZ, TNMatrix matSCP, TNMatrix matSCPinv, bool updateOGLList )
{
	int i, nvertexs, nEdges;
	float x, y, z;
	T3DPoint aux_p;
	TNMatrix matrix, matrix2;
	IwVector3d new_p;
	IwPolyVertex *vertex;

	if ( !RefEnt ) return false;

	matrix2 = TNScaleMatrix( 1.0 + factorX, 1.0 + factorY, 1.0 + factorZ );
	matrix = matSCP * matrix2 * matSCPinv;

	nEdges = CountPBrepEdges( OGLTransf );
	for ( i = 0; i < nEdges; i++ ) {
		if ( IsEdgeSelected( OGLTransf, i ) ) {
			vertex = PBrepEdges[ i ]->GetStartVertex( );
			SelectVertex( OGLTransf, vertex->GetIndexExt( ) );

			vertex = PBrepEdges[ i ]->GetEndVertex( );
			SelectVertex( OGLTransf, vertex->GetIndexExt( ) );
		}
	}

	nvertexs = CountPBrepVertexs( OGLTransf );
	for ( i = 0; i < nvertexs; i++ ) {
		if ( IsVertexSelected( OGLTransf, i ) ) {
			x = PBrepVertexs[ i ]->GetPoint( ).x;
			y = PBrepVertexs[ i ]->GetPoint( ).y;
			z = PBrepVertexs[ i ]->GetPoint( ).z;
			aux_p = T3DPoint( x, y, z );
			aux_p.ApplyMatrix( matrix );
			new_p.Set( aux_p.x, aux_p.y, aux_p.z );
			PBrepVertexs[ i ]->SetPoint( new_p );
		}
	}

	if ( updateOGLList && RefEnt ) RefEnt->UpdateOGLListFromPBrep( OGLTransf, true );

	UnSelectAllVertexs( OGLTransf );

	return true;
}

//------------------------------------------------------------------------------

bool TPBrepData::ScaleSelectedVertexs( TOGLTransf *OGLTransf, float factorX, float factorY, float factorZ, TNMatrix matSCP, TNMatrix matSCPinv, bool updateOGLList )
{
	int i, nvertexs;
	float x, y, z;
	double w;
	T3DPoint aux_p;
	TNMatrix matrix, matrix2;
	IwVector3d new_p;

	if ( !RefEnt ) return false;

	nvertexs = CountPBrepVertexs( OGLTransf );
	for ( i = 0; i < nvertexs; i++ ) {
		if ( IsVertexSelected( OGLTransf, i ) ) {
			w = GetVertexWeight( OGLTransf, i );
			matrix2 = TNScaleMatrix( 1.0 + factorX * w, 1.0 + factorY * w, 1.0 + factorZ * w );
			matrix = matSCP * matrix2 * matSCPinv;
			x = PBrepVertexs[ i ]->GetPoint( ).x;
			y = PBrepVertexs[ i ]->GetPoint( ).y;
			z = PBrepVertexs[ i ]->GetPoint( ).z;
			aux_p = T3DPoint( x, y, z );
			aux_p.ApplyMatrix( matrix );
			new_p.Set( aux_p.x, aux_p.y, aux_p.z );
			PBrepVertexs[ i ]->SetPoint( new_p );
		}
	}

	if ( updateOGLList && RefEnt ) RefEnt->UpdateOGLListFromPBrep( OGLTransf, true );

	return true;
}

//------------------------------------------------------------------------------

bool TPBrepData::ScaleProportionalEditing( TOGLTransf *OGLTransf, float factorX, float factorY, float factorZ, TNMatrix matSCP, TNMatrix matSCPinv, bool updateOGLList )
{
	int i;
	float x, y, z;
	double w;
	T3DPoint aux_p;
	TNMatrix matrix, matrix2;
	IwVector3d new_p;
	IwPolyVertex *vertex;
	TColor cIni, cEnd;

	if ( !RefEnt ) return false;

	// Movimiento de vértices seleccionados
	for ( i = 0; i < (int) MoveVertUser.VerticesOrg.GetSize( ); i++ ) {
		vertex = MoveVertUser.VerticesOrg[ i ];
		matrix2 = TNScaleMatrix( 1.0 + factorX * 1, 1.0 + factorY * 1, 1.0 + factorZ * 1 );
		matrix = matSCP * matrix2 * matSCPinv;
		x = vertex->GetPoint( ).x;
		y = vertex->GetPoint( ).y;
		z = vertex->GetPoint( ).z;
		aux_p = T3DPoint( x, y, z );
		aux_p.ApplyMatrix( matrix );
		new_p.Set( aux_p.x, aux_p.y, aux_p.z );
		vertex->SetPoint( new_p );
	}

	// Movimiento proporcional de vértices dentro del radio de influencia.
	for ( i = 0; i < (int) MoveVertUser.Vertices.GetSize( ); i++ ) {
		vertex = MoveVertUser.Vertices[ i ];
		w = vertex->GetPointExt( ).x;
		matrix2 = TNScaleMatrix( 1.0 + factorX * w, 1.0 + factorY * w, 1.0 + factorZ * w );
		matrix = matSCP * matrix2 * matSCPinv;
		x = vertex->GetPoint( ).x;
		y = vertex->GetPoint( ).y;
		z = vertex->GetPoint( ).z;
		aux_p = T3DPoint( x, y, z );
		aux_p.ApplyMatrix( matrix );
		new_p.Set( aux_p.x, aux_p.y, aux_p.z );
		vertex->SetPoint( new_p );
	}

	cIni = (TColor) RGB( 1.0, 1.0, 0.0 );
	cEnd = (TColor) RGB( 1.0, 0.0, 0.0 );
	UpdateColorsForProportionalEditing( OGLTransf, RefEnt->GetOGLRenderData( )->Colors, &cIni, &cEnd );

	if ( updateOGLList && RefEnt ) RefEnt->UpdateOGLListFromPBrep( OGLTransf, true );

	return true;
}

//------------------------------------------------------------------------------

bool TPBrepData::Scale( TOGLTransf *OGLTransf, float factorX, float factorY, float factorZ, TNMatrix matSCP, TNMatrix matSCPinv, bool updateOGLList )
{
	int i, nvertexs;
	float x, y, z;
	double w;
	T3DPoint aux_p;
	TNMatrix matrix, matrix2;
	IwVector3d new_p;

	if ( !RefEnt ) return false;

	nvertexs = CountPBrepVertexs( OGLTransf );
	for ( i = 0; i < nvertexs; i++ ) {
		w = GetVertexWeight( OGLTransf, i );
		matrix2 = TNScaleMatrix( 1.0 + factorX * w, 1.0 + factorY * w, 1.0 + factorZ * w );
		matrix = matSCP * matrix2 * matSCPinv;
		x = PBrepVertexs[ i ]->GetPoint( ).x;
		y = PBrepVertexs[ i ]->GetPoint( ).y;
		z = PBrepVertexs[ i ]->GetPoint( ).z;
		aux_p = T3DPoint( x, y, z );
		aux_p.ApplyMatrix( matrix );
		new_p.Set( aux_p.x, aux_p.y, aux_p.z );
		PBrepVertexs[ i ]->SetPoint( new_p );
	}

	if ( updateOGLList && RefEnt ) RefEnt->UpdateOGLListFromPBrep( OGLTransf );

	return true;
}

//------------------------------------------------------------------------------

/*
void TPBrepData::SetInvalidNormalsToSelection( TOGLTransf *OGLTransf, ElementType type )
{
	int i, j, nfaces, nedges, nvertexs, numPol, numFace, numVert;
	TOGLPolygonList *OGLList;
	TOGLFloat3 nInvalid;
	IwPolyVertex *vertex;
	IwPolyFace *face;
	IwTA<IwPolyFace *> affectedfaces, adyafaces;

	if ( !OGLTransf || !RefEnt ) return;

	InitUserIndex2( false, false, true );

	// Obtenemos la lista de caras afectadas por la selección, incluyendo las adyacentes si es necesario.
	switch ( type ) {
		case ElementType::Face:
			nfaces = CountPBrepFaces( OGLTransf );
			for ( i = 0; i < nfaces; i++ ) {
				if ( IsFaceSelected( OGLTransf, i ) ) {
					face = GetPBrepFace( OGLTransf, i );
					affectedfaces.Add( face );
					GetAdjacentFaces( face, &adyafaces );
					for ( j = 0; j < (int) adyafaces.GetSize( ); j++ ) {
						if ( adyafaces[ j ]->GetUserIndex2( ) == 1 ) continue;
						adyafaces[ j ]->SetUserIndex2( 1 );
						affectedfaces.Add( adyafaces[ j ] );
					}
				}
			}
			break;

		case ElementType::Edge:
			nedges = CountPBrepEdges( OGLTransf );
			for ( i = 0; i < nedges; i++ ) {
				if ( IsEdgeSelected( OGLTransf, i ) ) {
					vertex = PBrepEdges[ i ]->GetStartVertex( );
					vertex->GetPolyFaces( adyafaces );
					for ( j = 0; j < (int) adyafaces.GetSize( ); j++ ) {
						if ( adyafaces[ j ]->GetUserIndex2( ) == 1 ) continue;
						adyafaces[ j ]->SetUserIndex2( 1 );
						affectedfaces.Add( adyafaces[ j ] );
					}

					vertex = PBrepEdges[ i ]->GetEndVertex( );
					vertex->GetPolyFaces( adyafaces );
					for ( j = 0; j < (int) adyafaces.GetSize( ); j++ ) {
						if ( adyafaces[ j ]->GetUserIndex2( ) == 1 ) continue;
						adyafaces[ j ]->SetUserIndex2( 1 );
						affectedfaces.Add( adyafaces[ j ] );
					}
				}
			}
			break;

		case ElementType::Vertex:
			nvertexs = CountPBrepVertexs( OGLTransf );
			for ( i = 0; i < nvertexs; i++ ) { // UserIndex1 por edición proporcional.
				if ( IsVertexSelected( OGLTransf, i ) || PBrepVertexs[ i ]->GetUserIndex1( ) == 1 ) {
					PBrepVertexs[ i ]->GetPolyFaces( adyafaces );
					for ( j = 0; j < (int) adyafaces.GetSize( ); j++ ) {
						if ( adyafaces[ j ]->GetUserIndex2( ) == 1 ) continue;
						adyafaces[ j ]->SetUserIndex2( 1 );
						affectedfaces.Add( adyafaces[ j ] );
					}
				}
			}
			break;

		default: break;
	}

	// Ponemos como inválidas las normales de los vértices de las caras seleccionadas.
	nfaces = affectedfaces.GetSize( );
	if ( nfaces > 0 ) {
		nInvalid.Set( 0.0, 0.0, 0.0 );
		OGLList = RefEnt->GetOGLGeom3D( OGLTransf );
		for ( i = 0; i < nfaces; i++ ) {
			GetPBrepPolListRelF( OGLTransf, affectedfaces[ i ]->GetIndexExt( ), numPol, numFace, numVert );
			for ( j = 0; j < numVert; j++ )
				OGLList->GetItem( numPol )->GetItem( numFace + j )->n.Set( &nInvalid );
		}
	}
	InitUserIndex2( false, false, true );
}
*/

void TPBrepData::SetInvalidNormalsToSelection( TOGLTransf *OGLTransf, ElementType type )
{
	int i, j, nfaces, nedges, nvertexs, numPol, numFace, numVert;
	TOGLPolygonList *OGLList;
	TOGLFloat3 nInvalid;
	IwPolyVertex *vertex;
	IwPolyFace *face;
	IwTA<IwPolyFace *> affectedfaces, adyafaces;
	IwTA<IwPolyVertex *> vertexs;

	if ( !OGLTransf || !RefEnt ) return;

	InitUserIndex2( false, false, true );

	// Obtenemos la lista de caras afectadas por la selección, incluyendo las adyacentes si es necesario.
	switch ( type ) {
		case ElementType::Face:
			nfaces = CountPBrepFaces( OGLTransf );
			for ( i = 0; i < nfaces; i++ ) {
				if ( IsFaceSelected( OGLTransf, i ) ) {
					face = GetPBrepFace( OGLTransf, i );
					affectedfaces.Add( face );
					GetAdjacentFaces( face, &adyafaces );
					for ( j = 0; j < (int) adyafaces.GetSize( ); j++ ) {
						if ( adyafaces[ j ]->GetUserIndex2( ) == 1 ) continue;
						affectedfaces.Add( adyafaces[ j ] );
					}
				}
			}
			break;

		case ElementType::Edge:
			nedges = CountPBrepEdges( OGLTransf );
			for ( i = 0; i < nedges; i++ ) {
				if ( IsEdgeSelected( OGLTransf, i ) ) {
					vertex = PBrepEdges[ i ]->GetStartVertex( );
					vertex->GetPolyFaces( adyafaces );
					for ( j = 0; j < (int) adyafaces.GetSize( ); j++ ) {
						if ( adyafaces[ j ]->GetUserIndex2( ) == 1 ) continue;
						affectedfaces.Add( adyafaces[ j ] );
					}

					vertex = PBrepEdges[ i ]->GetEndVertex( );
					vertex->GetPolyFaces( adyafaces );
					for ( j = 0; j < (int) adyafaces.GetSize( ); j++ ) {
						if ( adyafaces[ j ]->GetUserIndex2( ) == 1 ) continue;
						affectedfaces.Add( adyafaces[ j ] );
					}
				}
			}
			break;

		case ElementType::Vertex:
			nvertexs = CountPBrepVertexs( OGLTransf );
			for ( i = 0; i < nvertexs; i++ ) { // UserIndex1 por edición proporcional.
				if ( IsVertexSelected( OGLTransf, i ) || PBrepVertexs[ i ]->GetUserIndex1( ) == 1 ) {
					PBrepVertexs[ i ]->GetPolyFaces( adyafaces );
					for ( j = 0; j < (int) adyafaces.GetSize( ); j++ ) {
						if ( adyafaces[ j ]->GetUserIndex2( ) == 1 ) continue;
						affectedfaces.Add( adyafaces[ j ] );
					}
				}
			}
			break;

		default: break;
	}

	// Ponemos como inválidas las normales de los vértices de las caras seleccionadas.
	nfaces = affectedfaces.GetSize( );
	if ( nfaces > 0 ) {
		nInvalid.Set( 0.0, 0.0, 0.0 );
		OGLList = RefEnt->GetOGLGeom3D( OGLTransf );
		for ( i = 0; i < nfaces; i++ ) {
			GetPBrepPolListRelF( OGLTransf, affectedfaces[ i ]->GetIndexExt( ), numPol, numFace, numVert );
			for ( j = 0; j < numVert; j++ )
				OGLList->GetItem( numPol )->GetItem( numFace + j )->n.Set( &nInvalid );
		}
	}
	InitUserIndex2( false, false, true );
}

//------------------------------------------------------------------------------

bool TPBrepData::ApplyMatrixToSelectedFaces( TOGLTransf *OGLTransf, TNMatrix matrix, bool updateOGLList )
{
	int i, j, nfaces, nvertexs;
	T3DPoint pt;
	IwVector3d new_p;
	IwTA<IwPolyVertex *> auxvertexs;
	IwPolyVertex *vertex;
	IwPolyFace *face;

	if ( !RefEnt ) return false;

	nfaces = CountPBrepFaces( OGLTransf );
	for ( i = 0; i < nfaces; i++ ) {
		if ( IsFaceSelected( OGLTransf, i ) ) {
			face = GetPBrepFace( OGLTransf, i );
			if ( !face ) return false;

			face->GetPolyVertices( auxvertexs );
			nvertexs = auxvertexs.GetSize( );
			for ( j = 0; j < nvertexs; j++ )
				SelectVertex( OGLTransf, auxvertexs[ j ]->GetIndexExt( ) );
		}
	}

	for ( i = 0; i < nfaces; i++ ) {
		if ( IsFaceSelected( OGLTransf, i ) ) {
			face = GetPBrepFace( OGLTransf, i );
			if ( !face ) return false;

			face->GetPolyVertices( auxvertexs );
			nvertexs = auxvertexs.GetSize( );
			for ( j = 0; j < nvertexs; j++ ) {
				vertex = auxvertexs[ j ];
				if ( IsVertexSelected( OGLTransf, vertex->GetIndexExt( ) ) ) {
					pt.x = vertex->GetPoint( ).x;
					pt.y = vertex->GetPoint( ).y;
					pt.z = vertex->GetPoint( ).z;
					pt.ApplyMatrix( matrix );
					new_p.Set( pt.x, pt.y, pt.z );
					vertex->SetPoint( new_p );
					UnSelectVertex( OGLTransf, vertex->GetIndexExt( ) );
				}
			}
		}
	}

	if ( updateOGLList && RefEnt ) {
		// Actualizamos la OGLList
		RefEnt->UpdateOGLListFromPBrep( OGLTransf );
		// Ponemos como inválidas las normales de los vértices de las caras seleccionadas y las actualizamos
		SetInvalidNormalsToSelection( OGLTransf, ElementType::Face );
		UpdateNormalsOGLListFromPBrep( OGLTransf, RefEnt->GetOGLGeom3D( OGLTransf ), true );
	}

	return true;
}

//------------------------------------------------------------------------------

bool TPBrepData::ApplyMatrixToSelectedEdges( TOGLTransf *OGLTransf, TNMatrix matrix, bool updateOGLList )
{
	int i, nEdges;
	T3DPoint pt;
	IwVector3d new_p;
	IwPolyVertex *vertex;

	if ( !RefEnt ) return false;

	nEdges = CountPBrepEdges( OGLTransf );
	for ( i = 0; i < nEdges; i++ ) {
		if ( IsEdgeSelected( OGLTransf, i ) ) {
			vertex = PBrepEdges[ i ]->GetStartVertex( );
			SelectVertex( OGLTransf, vertex->GetIndexExt( ) );

			vertex = PBrepEdges[ i ]->GetEndVertex( );
			SelectVertex( OGLTransf, vertex->GetIndexExt( ) );
		}
	}

	for ( i = 0; i < nEdges; i++ ) {
		vertex = PBrepEdges[ i ]->GetStartVertex( );
		if ( IsVertexSelected( OGLTransf, vertex->GetIndexExt( ) ) ) {
			pt.x = vertex->GetPoint( ).x;
			pt.y = vertex->GetPoint( ).y;
			pt.z = vertex->GetPoint( ).z;
			pt.ApplyMatrix( matrix );
			new_p.Set( pt.x, pt.y, pt.z );
			vertex->SetPoint( new_p );
			UnSelectVertex( OGLTransf, vertex->GetIndexExt( ) );
		}

		vertex = PBrepEdges[ i ]->GetEndVertex( );
		if ( IsVertexSelected( OGLTransf, vertex->GetIndexExt( ) ) ) {
			pt.x = vertex->GetPoint( ).x;
			pt.y = vertex->GetPoint( ).y;
			pt.z = vertex->GetPoint( ).z;
			pt.ApplyMatrix( matrix );
			new_p.Set( pt.x, pt.y, pt.z );
			vertex->SetPoint( new_p );
			UnSelectVertex( OGLTransf, vertex->GetIndexExt( ) );
		}
	}

	if ( updateOGLList && RefEnt ) {
		// Actualizamos la OGLList
		RefEnt->UpdateOGLListFromPBrep( OGLTransf );
		// Ponemos como inválidas las normales de los vértices de las caras seleccionadas y las actualizamos
		SetInvalidNormalsToSelection( OGLTransf, ElementType::Edge );
		UpdateNormalsOGLListFromPBrep( OGLTransf, RefEnt->GetOGLGeom3D( OGLTransf ), true );
	}

	return true;
}

//------------------------------------------------------------------------------

bool TPBrepData::ApplyMatrixToSelectedVertexs( TOGLTransf *OGLTransf, TNMatrix matrix, bool updateOGLList )
{
	int i, nvertexs;
	T3DPoint pt;
	IwVector3d new_p;

	if ( !RefEnt ) return false;

	nvertexs = CountPBrepVertexs( OGLTransf );
	for ( i = 0; i < nvertexs; i++ ) {
		if ( IsVertexSelected( OGLTransf, i ) ) {
			pt.x = PBrepVertexs[ i ]->GetPoint( ).x;
			pt.y = PBrepVertexs[ i ]->GetPoint( ).y;
			pt.z = PBrepVertexs[ i ]->GetPoint( ).z;
			pt.ApplyMatrix( matrix );
			new_p.Set( pt.x, pt.y, pt.z );
			( *( &PBrepVertexs ) )[ i ]->SetPoint( new_p );
		}
	}

	if ( updateOGLList && RefEnt ) {
		// Actualizamos la OGLList
		RefEnt->UpdateOGLListFromPBrep( OGLTransf );
		// Ponemos como inválidas las normales de los vértices de las caras seleccionadas y las actualizamos
		SetInvalidNormalsToSelection( OGLTransf, ElementType::Vertex );
		UpdateNormalsOGLListFromPBrep( OGLTransf, RefEnt->GetOGLGeom3D( OGLTransf ), true );
	}

	return true;
}

//------------------------------------------------------------------------------

void TPBrepData::CalcNeigWeight( TOGLTransf *OGLTransf, IwPolyVertex vertexsToNeig, IwTA<IwPolyVertex *> neighbors, float radius, vector<float> *w )
{
	int i;
	float weight, wSum, wUnit, dist;

	if ( !GetPBrep( OGLTransf ) ) return;

	wSum = 0;

	for ( i = 0; i < (int) neighbors.GetSize( ); i++ ) {
		dist = vertexsToNeig.GetPoint( ).DistanceBetween( neighbors[ i ]->GetPoint( ) );
		weight = SmoothGauss( dist, 1, 0, 0.25, radius );
		wSum = wSum + weight;
	}

	for ( i = 0; i < (int) neighbors.GetSize( ); i++ ) {
		dist = vertexsToNeig.GetPoint( ).DistanceBetween( neighbors[ i ]->GetPoint( ) );
		weight = SmoothGauss( dist, 1, 0, 0.25, radius );
		wUnit = weight / wSum;
		w->push_back( wUnit );
	}
}

//------------------------------------------------------------------------------

void TPBrepData::ApplyMatrixPBrep( TOGLTransf *OGLTransf, TNMatrix *matrix, bool updatePolList, bool calcnormals )
{
	int i, nvertexs;
	T3DPoint pt;
	IwVector3d iwpt;

	if ( !GetPBrep( OGLTransf ) ) return;

	nvertexs = (int) PBrepVertexs.GetSize( );
	for ( i = 0; i < nvertexs; i++ ) {
		iwpt = PBrepVertexs[ i ]->GetPoint( );
		pt.x = iwpt.x;
		pt.y = iwpt.y;
		pt.z = iwpt.z;
		pt.ApplyMatrix( *matrix );
		iwpt.Set( pt.x, pt.y, pt.z );
		PBrepVertexs[ i ]->SetPoint( iwpt );
	}

	if ( updatePolList && RefEnt ) RefEnt->UpdateOGLListFromPBrep( OGLTransf, false, calcnormals );
}

//------------------------------------------------------------------------------

bool TPBrepData::GetPBrepBorder( TOGLTransf *OGLTransf, IwTA<IwPolyEdge *> *edges, TOGLPolygonList *polList )
{
	bool isCycle;
	int i, j, currIndexV1, currIndexV2, iniCiclo, endCiclo, count;
	IwTA<IwPolyEdge *> edgesPBrep, edgesPBrepAux1, edgesPBrepAux2;
	IwTA<IwPolyVertex *> verticesPBrep;
	TOGLPolygon pol;
	TOGLPoint pt;

	if ( !GetPBrep( OGLTransf ) ) return false;

	count = 0;
	PBrep->GetPolyEdges( edgesPBrep );
	PBrep->GetPolyVertices( verticesPBrep );

	for ( i = 0; i < (int) edgesPBrep.GetSize( ); i++ ) {
		if ( edgesPBrep[ i ]->IsBoundary( ) ) {
			edgesPBrepAux1.Add( edgesPBrep[ i ] );
			edgesPBrepAux2.Add( edgesPBrep[ i ] );
		}
	}

	edgesPBrepAux1.RemoveDuplicates( );
	edgesPBrepAux2.RemoveDuplicates( );

	if ( edgesPBrepAux1.GetSize( ) > 0 ) {
		edges->Add( edgesPBrepAux1[ 0 ] );
		pt.v.Set( ( *edges )[ 0 ]->GetEndVertex( )->GetPoint( ).x, ( *edges )[ 0 ]->GetEndVertex( )->GetPoint( ).y, ( *edges )[ 0 ]->GetEndVertex( )->GetPoint( ).z );
		iniCiclo = edgesPBrepAux1[ 0 ]->GetStartVertex( )->GetIndexExt( );
		pol.AddItem( &pt, count++ );
		edgesPBrepAux2.RemoveAt( 0 );
		while ( edgesPBrepAux2.GetSize( ) > 0 ) {
			isCycle = false;
			for ( i = 0; i < (int) ( *edges ).GetSize( ); i++ ) {
				currIndexV1 = ( *edges )[ i ]->GetEndVertex( )->GetIndexExt( );
				for ( j = 0; j < (int) edgesPBrepAux2.GetSize( ); j++ ) {
					currIndexV2 = edgesPBrepAux2[ j ]->GetStartVertex( )->GetIndexExt( );
					if ( currIndexV1 == currIndexV2 ) {
						( *edges ).Add( edgesPBrepAux2[ j ] );
						pt.v.Set( edgesPBrepAux2[ j ]->GetEndVertex( )->GetPoint( ).x, edgesPBrepAux2[ j ]->GetEndVertex( )->GetPoint( ).y, edgesPBrepAux2[ j ]->GetEndVertex( )->GetPoint( ).z );
						pol.AddItem( &pt, count++ );
						endCiclo = edgesPBrepAux2[ j ]->GetEndVertex( )->GetIndexExt( );
						edgesPBrepAux2.RemoveAt( j );
						if ( iniCiclo == endCiclo ) { // se cierra un ciclo e iniciamos otro
							pol.AddItem( pol.GetItem( 0 ), count++ );
							polList->Add( &pol );
							pol.Clear( );
							if ( edgesPBrepAux2.GetSize( ) > 0 ) {
								( *edges ).Add( edgesPBrepAux2[ 0 ] );
								pt.v.Set( edgesPBrepAux2[ 0 ]->GetEndVertex( )->GetPoint( ).x, edgesPBrepAux2[ 0 ]->GetEndVertex( )->GetPoint( ).y, edgesPBrepAux2[ 0 ]->GetEndVertex( )->GetPoint( ).z );
								count = 0;
								pol.AddItem( &pt, count++ );
								iniCiclo = edgesPBrepAux2[ 0 ]->GetStartVertex( )->GetIndexExt( );
								edgesPBrepAux2.RemoveAt( 0 );
								i++;
							}
							isCycle = true;
						}
						break;
					}
				}
			}
			if ( !isCycle && edgesPBrepAux2.GetSize( ) > 0 ) {
				( *edges ).Add( edgesPBrepAux2[ 0 ] );
				pt.v.Set( edgesPBrepAux2[ 0 ]->GetEndVertex( )->GetPoint( ).x, edgesPBrepAux2[ 0 ]->GetEndVertex( )->GetPoint( ).y, edgesPBrepAux2[ 0 ]->GetEndVertex( )->GetPoint( ).z );
				count = 0;
				pol.Clear( );
				pol.AddItem( &pt, count++ );
				iniCiclo = edgesPBrepAux2[ 0 ]->GetStartVertex( )->GetIndexExt( );
				edgesPBrepAux2.RemoveAt( 0 );
			}
		}
	}

	return true;
}

//==============================================================================
//==============================================================================
// SUBSOLES
//==============================================================================
//==============================================================================
// IMP: Para trabajar correctamente con la subdivisión, es importante que la entidad permita trabajar con quads
int TPBrepData::GetSubdividedOGLList( TOGLTransf *OGLTransf, TOGLPolygonList *ogllist, TOGLPolygon *polvertexs, TOGLPolygon *poledges, TOGLPolygon *polfaces, TSubdivisionData *subdivisiondata, TInteger_ListList *auxinfolist )
{
	int i, j, k, count, count2, index, nItems, nPoints;
	IwPolyBrep *pBrep;
	TOGLPoint oglpt, *pointAux;
	TOGLPolygon pol, polPoint, polLine, polFace, *polAux;
	TOGLPolygonList outPolListAux, auxlist;
	IwTA<IwPolyVertex *> vertexs;
	TInteger_List list;

	if ( !OGLTransf || !ogllist ) return 0;

	pBrep = GetPBrep( OGLTransf );
	if ( !pBrep ) return 0;
	if ( !subdivisiondata->Dragging && !CanSubdivide( ) ) return 0;

	if ( !Subdivision ) {
		Subdivision = new TSubdivision( pBrep, subdivisiondata->Level );
		Subdivision->Apply( );
	} else {
		if ( Subdivision->GetLevel( ) != subdivisiondata->Level ) {
			Subdivision->SetLevel( subdivisiondata->Level );
			Subdivision->Update( true );
		} else
			Subdivision->Update( subdivisiondata->RecalcTopology, subdivisiondata->RebuildFromLevel0 );
	}

	if ( subdivisiondata->Level != 0 ) {
		if ( IsTopologyDirty( ) ) SetTopologyDirty( false );
		if ( IsDataSubdivisionDirty( ) ) SetDataSubdivisionDirty( OGLTransf, false );
		Subdivision->GetOGLList( ogllist, polvertexs, poledges, polfaces, true, subdivisiondata, auxinfolist != 0 );
	} else {
		if ( !ogllist ) return 0;

		if ( polvertexs ) {
			polvertexs->Clear( );
			polvertexs->SetType( GL_POINTS );
			count = PBrepVertexs.GetSize( );
			for ( i = 0; i < count; i++ ) {
				oglpt.v.v[ 0 ] = PBrepVertexs[ i ]->GetPointPtr( )->x;
				oglpt.v.v[ 1 ] = PBrepVertexs[ i ]->GetPointPtr( )->y;
				oglpt.v.v[ 2 ] = PBrepVertexs[ i ]->GetPointPtr( )->z;
				oglpt.t.v[ 0 ] = GLfloat( PBrepVertexs[ i ]->GetIndexExt( ) );
				oglpt.t.v[ 1 ] = 1;
				polvertexs->AddItem( &oglpt );
			}
		}

		if ( poledges ) {
			poledges->Clear( );
			poledges->SetType( GL_LINES );

			count = PBrepEdges.GetSize( );
			for ( i = 0; i < count; i++ ) {
				if ( PBrepEdges[ i ]->GetUserIndex1( ) == ULONG_MAX ) continue;

				oglpt.t.v[ 0 ] = GLfloat( PBrepEdges[ i ]->GetUserIndex1( ) );
				oglpt.t.v[ 1 ] = 1;

				oglpt.v.v[ 0 ] = PBrepEdges[ i ]->GetStartVertex( )->GetPointPtr( )->x;
				oglpt.v.v[ 1 ] = PBrepEdges[ i ]->GetStartVertex( )->GetPointPtr( )->y;
				oglpt.v.v[ 2 ] = PBrepEdges[ i ]->GetStartVertex( )->GetPointPtr( )->z;
				poledges->AddItem( &oglpt );
				oglpt.v.v[ 0 ] = PBrepEdges[ i ]->GetEndVertex( )->GetPointPtr( )->x;
				oglpt.v.v[ 1 ] = PBrepEdges[ i ]->GetEndVertex( )->GetPointPtr( )->y;
				oglpt.v.v[ 2 ] = PBrepEdges[ i ]->GetEndVertex( )->GetPointPtr( )->z;
				poledges->AddItem( &oglpt );
			}
		}

		ogllist->Set( RefEnt->GetOGLList( OGLTransf ) );

		if ( polfaces ) {
			polfaces->Clear( );
			polfaces->SetType( GL_TRIANGLES );
			polfaces->SetUseNormals( true );

			count = PBrepFaces.GetSize( );
			for ( i = 0; i < count; i++ ) {
				polAux = GetOGLDataFromPolyFace( OGLTransf, ogllist, PBrepFaces[ i ], index );
				auxlist.Clear( );
				auxlist.Add( polAux );
				auxlist.ConvertToTriangles( 0, SINGLE_POLYGON );
				polAux = auxlist.GetItem( 0 );
				count2 = polAux->Count( );
				for ( j = 0; j < count2; j++ ) {
					pointAux = polAux->GetItem( j );
					pointAux->t.v[ 0 ] = GLfloat( PBrepFaces[ i ]->GetIndexExt( ) );
					pointAux->t.v[ 1 ] = 1;
				}
				polfaces->Append( polAux );
			}

			auxlist.Clear( true );
		}

		// La ogllist siempre ha de ser triangulada, aunque SubdivisionData->ForceTriangles sea false.
		// Si no es así no podemos hacer una correspondencia entre la ogllist y SubdivisionFaces.
		// La variable ForceTriangles sólo se ponde a false en las exportaciones.
		ogllist->ConvertToTriangles( 0, SINGLE_POLYGON );
		ogllist->CalculateNormal( );
		ogllist->UnifyNormals( );

		for ( i = 0; i < ogllist->Count( ); i++ )
			ogllist->GetItem( i )->SetUseTextures( true );

		auxlist.Add( polfaces );
		auxlist.CalculateNormal( );
		auxlist.UnifyNormals( );

		polfaces->Set( auxlist.GetItem( 0 ) );
		auxlist.Clear( true );

		if ( IsTopologyDirty( ) ) SetTopologyDirty( false );
		if ( IsDataSubdivisionDirty( ) ) SetDataSubdivisionDirty( OGLTransf, false );
	}

	// Calculamos AuxInfoList si se ha pedido
	if ( auxinfolist ) {
		auxinfolist->Clear( );
		nItems = ogllist->Count( );
		for ( i = 0; i < nItems; i++ ) {
			polAux = ogllist->GetItem( i );
			nPoints = polAux->Count( );
			list.Clear( );
			for ( j = 0; j < nPoints; j++ ) {
				pointAux = polAux->GetItem( j );
				k = pointAux->uv.v[ 0 ];
				list.AddItem( &k );
				k = 0;
				list.AddItem( &k );
				list.AddItem( &k );
			}
			auxinfolist->AddItem( &list );
		}
	}

	return ogllist->Count( );
}

//------------------------------------------------------------------------------

void TPBrepData::CreateLowPolyCube( TOGLTransf *OGLTransf, TMeshPrimitiveParams *params )
{
	int sizeV, count;
	T3DPoint position;
	IwPolyVertex **vertices;
	IwPolyFace *face;
	IwPolyBrep *pBrep;
	IwPolyRegion *pRegion;
	IwPolyShell *pShell;
	IwPoint3d pt3d;

	if ( !OGLTransf || !params || !RefEnt ) return;

	pBrep = new IwPolyBrep( _GetSMLib( )->GetContext( ), RES_COMP );
	if ( !pBrep ) return;
	pRegion = new IwPolyRegion( _GetSMLib( )->GetContext( ), pBrep );
	if ( !pRegion ) {
		_GetSMLib( )->DestroyIwPolyBrep( pBrep );
		pBrep = 0;
		return;
	}
	pShell = new IwPolyShell( _GetSMLib( )->GetContext( ), *pBrep, pRegion );
	if ( !pShell ) {
		_GetSMLib( )->DestroyIwPolyBrep( pBrep );
		pBrep = 0;
		pRegion = 0;
		return;
	}

	sizeV = 8;
	count = 0;
	position = T3DPoint( 0.0, 0.0, 0.0 );

	vertices = new IwPolyVertex *[ sizeV ];

	pt3d = IwPoint3d( position.x, position.y, position.z );
	vertices[ count++ ] = new IwPolyVertex( _GetSMLib( )->GetContext( ), *pBrep, pt3d, RES_COMP );
	pt3d = IwPoint3d( position.x + params->CubeDimX, position.y, position.z );
	vertices[ count++ ] = new IwPolyVertex( _GetSMLib( )->GetContext( ), *pBrep, pt3d, RES_COMP );
	pt3d = IwPoint3d( position.x + params->CubeDimX, position.y, position.z + params->CubeDimZ );
	vertices[ count++ ] = new IwPolyVertex( _GetSMLib( )->GetContext( ), *pBrep, pt3d, RES_COMP );
	pt3d = IwPoint3d( position.x, position.y, position.z + params->CubeDimZ );
	vertices[ count++ ] = new IwPolyVertex( _GetSMLib( )->GetContext( ), *pBrep, pt3d, RES_COMP );

	pt3d = IwPoint3d( position.x, position.y + params->CubeDimY, position.z );
	vertices[ count++ ] = new IwPolyVertex( _GetSMLib( )->GetContext( ), *pBrep, pt3d, RES_COMP );
	pt3d = IwPoint3d( position.x + params->CubeDimX, position.y + params->CubeDimY, position.z );
	vertices[ count++ ] = new IwPolyVertex( _GetSMLib( )->GetContext( ), *pBrep, pt3d, RES_COMP );
	pt3d = IwPoint3d( position.x + params->CubeDimX, position.y + params->CubeDimY, position.z + params->CubeDimZ );
	vertices[ count++ ] = new IwPolyVertex( _GetSMLib( )->GetContext( ), *pBrep, pt3d, RES_COMP );
	pt3d = IwPoint3d( position.x, position.y + params->CubeDimY, position.z + params->CubeDimZ );
	vertices[ count ] = new IwPolyVertex( _GetSMLib( )->GetContext( ), *pBrep, pt3d, RES_COMP );

	pBrep->CreatePolyQuad( pRegion, pShell, vertices[ 0 ], vertices[ 1 ], vertices[ 2 ], vertices[ 3 ], face );
	pBrep->CreatePolyQuad( pRegion, pShell, vertices[ 1 ], vertices[ 5 ], vertices[ 6 ], vertices[ 2 ], face );
	pBrep->CreatePolyQuad( pRegion, pShell, vertices[ 5 ], vertices[ 4 ], vertices[ 7 ], vertices[ 6 ], face );
	pBrep->CreatePolyQuad( pRegion, pShell, vertices[ 4 ], vertices[ 0 ], vertices[ 3 ], vertices[ 7 ], face );
	pBrep->CreatePolyQuad( pRegion, pShell, vertices[ 6 ], vertices[ 7 ], vertices[ 3 ], vertices[ 2 ], face );
	pBrep->CreatePolyQuad( pRegion, pShell, vertices[ 4 ], vertices[ 5 ], vertices[ 1 ], vertices[ 0 ], face );

	CopyPBrep( pBrep );
	UpdateOGLListFromPBrep( OGLTransf, RefEnt->GetOGLList( OGLTransf ), false, true, false, true );

	delete[] vertices;
	delete pBrep;

	return;
}

//---------------------------------------------------------------------------

bool TPBrepData::GetPointsSphere( TOGLTransf *OGLTransf, double radius, IwTA<T3DPoint> *iwPointsUp, IwTA<T3DPoint> *iwPointsMid, IwTA<T3DPoint> *iwPointsDown )
{
	int numVertexsSec, i;
	double param_1, param_2, dist;
	T3DPoint pt3d, pt3d_1, pt3d_2;
	T3DVector vec;
	TNMatrix matrix;
	TCadIBSpline *section;

	if ( !OGLTransf || !iwPointsUp || !iwPointsMid || !iwPointsDown ) return false;
	if ( radius < RES_COMP ) return false;

	section = new TCadIBSpline( );
	pt3d = T3DPoint( radius, 0.0, 0.0 );
	section->Add( OGLTransf, pt3d );
	pt3d = T3DPoint( 0.0, 0.0, radius );
	section->Add( OGLTransf, pt3d );
	pt3d = T3DPoint( -radius, 0.0, 0.0 );
	section->Add( OGLTransf, pt3d );
	pt3d = T3DPoint( 0.0, 0.0, -radius );
	section->Add( OGLTransf, pt3d );
	section->SetClose( ENT_PERIODIC );

	numVertexsSec = 8;
	vec = T3DVector( T3DSize( 0, 0, -1 ) );
	matrix = TNRotateMatrix( 360.0 / numVertexsSec * M_PI_180, vec );

	iwPointsUp->RemoveAll( );
	iwPointsMid->RemoveAll( );
	iwPointsDown->RemoveAll( );
	param_1 = 1.0 / numVertexsSec * MAX_PARAM;
	for ( i = 0; i < numVertexsSec; i++ ) {
		pt3d = section->GetDataPointByParam( OGLTransf, 0.0 );
		iwPointsMid->Add( pt3d );

		if ( i == 1 ) { // Calculamos param_2
			param_2 = param_1 * 0.85;
			pt3d_1 = iwPointsUp->GetAt( 0 );
			pt3d_2 = iwPointsMid->GetAt( 1 );
			dist = 1;
			while ( dist > RES_COMP ) {
				param_2 -= ( 0.001 * MAX_PARAM );
				pt3d = section->GetDataPointByParam( OGLTransf, param_2 );
				dist = pt3d.DistanciaSqr( pt3d_2 ) - pt3d.DistanciaSqr( pt3d_1 );
			}
			param_2 += ( 0.001 * MAX_PARAM );
		}

		pt3d = section->GetDataPointByParam( OGLTransf, ( i == 0 || i == 2 || i == 4 || i == 6 ) ? param_1 : param_2 );
		iwPointsUp->Add( pt3d );

		pt3d = section->GetDataPointByParam( OGLTransf, ( i == 0 || i == 2 || i == 4 || i == 6 ) ? ( MAX_PARAM - param_1 ) : ( MAX_PARAM - param_2 ) );
		iwPointsDown->Add( pt3d );

		section->ApplyMatrix( OGLTransf, &matrix );
	}
	delete section;

	return true;
}

//---------------------------------------------------------------------------

void TPBrepData::CreateLowPolySphere( TOGLTransf *OGLTransf, TMeshPrimitiveParams *params )
{
	int i, numVertexsSec;
	T3DPoint pt3d;
	IwPolyBrep *pBrep;
	IwPolyRegion *pRegion;
	IwPolyShell *pShell;
	IwPoint3d iwPoint;
	IwPolyVertex *iwVertex, *iwVertexUp, *iwVertexDown;
	IwPolyFace *newFace;
	IwTA<IwPolyVertex *> iwVertexsUp, iwVertexsMid, iwVertexsDown;
	IwTA<T3DPoint> iwPointsUp, iwPointsMid, iwPointsDown;

	if ( !OGLTransf || !params || !RefEnt ) return;
	if ( params->SphereRadius < RES_COMP ) return;

	pBrep = new IwPolyBrep( _GetSMLib( )->GetContext( ), RES_COMP );
	if ( !pBrep ) return;
	pRegion = new IwPolyRegion( _GetSMLib( )->GetContext( ), pBrep );
	if ( !pRegion ) {
		_GetSMLib( )->DestroyIwPolyBrep( pBrep );
		pBrep = 0;
		return;
	}
	pShell = new IwPolyShell( _GetSMLib( )->GetContext( ), *pBrep, pRegion );
	if ( !pShell ) {
		_GetSMLib( )->DestroyIwPolyBrep( pBrep );
		pBrep = 0;
		pRegion = 0;
		return;
	}

	if ( !GetPointsSphere( OGLTransf, params->SphereRadius, &iwPointsUp, &iwPointsMid, &iwPointsDown ) ) return;

	numVertexsSec = (int) iwPointsMid.GetSize( );
	for ( i = 0; i < numVertexsSec; i++ ) {
		pt3d = iwPointsMid.GetAt( i );
		iwPoint = IwPoint3d( pt3d.x, pt3d.y, pt3d.z );
		iwVertex = new IwPolyVertex( _GetSMLib( )->GetContext( ), *PBrep, iwPoint, RES_COMP );
		iwVertexsMid.Add( iwVertex );

		pt3d = iwPointsUp.GetAt( i );
		iwPoint = IwPoint3d( pt3d.x, pt3d.y, pt3d.z );
		iwVertex = new IwPolyVertex( _GetSMLib( )->GetContext( ), *PBrep, iwPoint, RES_COMP );
		iwVertexsUp.Add( iwVertex );

		pt3d = iwPointsDown.GetAt( i );
		iwPoint = IwPoint3d( pt3d.x, pt3d.y, pt3d.z );
		iwVertex = new IwPolyVertex( _GetSMLib( )->GetContext( ), *PBrep, iwPoint, RES_COMP );
		iwVertexsDown.Add( iwVertex );
	}

	pt3d = T3DPoint( 0.0, 0.0, params->SphereRadius );
	iwPoint = IwPoint3d( pt3d.x, pt3d.y, pt3d.z );
	iwVertexUp = new IwPolyVertex( _GetSMLib( )->GetContext( ), *PBrep, iwPoint, RES_COMP );

	pt3d = T3DPoint( 0.0, 0.0, -params->SphereRadius );
	iwPoint = IwPoint3d( pt3d.x, pt3d.y, pt3d.z );
	iwVertexDown = new IwPolyVertex( _GetSMLib( )->GetContext( ), *PBrep, iwPoint, RES_COMP );

	for ( i = 0; i < numVertexsSec; i++ ) {
		pBrep->CreatePolyQuad( pRegion, pShell, iwVertexsUp.GetAt( i ), iwVertexsUp.GetAt( ( i + 1 ) % numVertexsSec ), iwVertexsMid.GetAt( ( i + 1 ) % numVertexsSec ), iwVertexsMid.GetAt( i ), newFace );
		pBrep->CreatePolyQuad( pRegion, pShell, iwVertexsMid.GetAt( i ), iwVertexsMid.GetAt( ( i + 1 ) % numVertexsSec ), iwVertexsDown.GetAt( ( i + 1 ) % numVertexsSec ), iwVertexsDown.GetAt( i ), newFace );
		if ( i == 0 || i == 2 || i == 4 || i == 6 ) {
			pBrep->CreatePolyQuad( pRegion, pShell, iwVertexUp, iwVertexsUp.GetAt( ( i + 2 ) % numVertexsSec ), iwVertexsUp.GetAt( ( i + 1 ) % numVertexsSec ), iwVertexsUp.GetAt( i ), newFace );
			pBrep->CreatePolyQuad( pRegion, pShell, iwVertexDown, iwVertexsDown.GetAt( i ), iwVertexsDown.GetAt( ( i + 1 ) % numVertexsSec ), iwVertexsDown.GetAt( ( i + 2 ) % numVertexsSec ), newFace );
		}
	}

	CopyPBrep( pBrep );
	UpdateOGLListFromPBrep( OGLTransf, RefEnt->GetOGLList( OGLTransf ), false, true, false, true );
	delete pBrep;
}

//---------------------------------------------------------------------------

void TPBrepData::CreateLowPolyCylinder( TOGLTransf *OGLTransf, TMeshPrimitiveParams *params )
{
	int i, j;
	double angle, heightFace;
	T3DPoint pt;
	IwPolyFace *face;
	IwPolyBrep *pBrep;
	IwPolyRegion *pRegion;
	IwPolyShell *pShell;
	IwPoint3d pt3d;
	IwPolyVertex *vertex;
	IwTA<IwPolyVertex *> iwVertexs;
	IwTA<IwTA<IwPolyVertex *> > iwVertexsList;

	if ( !OGLTransf || !params || !RefEnt ) return;
	if ( !params->IsValid( LPM_CREATIONTYPE_CYLINDER ) ) return;

	pBrep = new IwPolyBrep( _GetSMLib( )->GetContext( ), RES_COMP );
	if ( !pBrep ) return;
	pRegion = new IwPolyRegion( _GetSMLib( )->GetContext( ), pBrep );
	if ( !pRegion ) {
		_GetSMLib( )->DestroyIwPolyBrep( pBrep );
		pBrep = 0;
		return;
	}
	pShell = new IwPolyShell( _GetSMLib( )->GetContext( ), *pBrep, pRegion );
	if ( !pShell ) {
		_GetSMLib( )->DestroyIwPolyBrep( pBrep );
		pBrep = 0;
		pRegion = 0;
		return;
	}

	angle = M_PI * 2.0 / params->CylinderFaces;
	if ( params->CylinderPlane == plXZ ) angle *= -1.0;
	heightFace = (double) params->CylinderHeight / (double) params->CylinderSections;

	// Vertices
	for ( i = 0; i < ( params->CylinderSections + 1 ); i++ ) {
		switch ( params->CylinderPlane ) {
			case plXY: pt = T3DPoint( params->CylinderRadius, 0.0, ( heightFace * i ) ); break;
			case plXZ: pt = T3DPoint( params->CylinderRadius, ( heightFace * i ), 0.0 ); break;
			case plYZ: pt = T3DPoint( ( heightFace * i ), params->CylinderRadius, 0.0 ); break;
			default: break;
		}

		iwVertexs.RemoveAll( );
		for ( j = 0; j < params->CylinderFaces; j++ ) {
			_RotatePoint( pt, params->CylinderPlane, angle );
			pt3d = IwPoint3d( pt.x, pt.y, pt.z );
			vertex = new IwPolyVertex( _GetSMLib( )->GetContext( ), *pBrep, pt3d, RES_COMP );
			iwVertexs.Push( vertex );
		}
		iwVertexsList.Push( iwVertexs );
	}

	// Faces
	for ( i = 0; i < params->CylinderSections; i++ )
		for ( j = 0; j < params->CylinderFaces; j++ )
			pBrep->CreatePolyQuad( pRegion, pShell, iwVertexsList.GetAt( i ).GetAt( j ), iwVertexsList.GetAt( i ).GetAt( ( j + 1 ) % params->CylinderFaces ), iwVertexsList.GetAt( i + 1 ).GetAt( ( j + 1 ) % params->CylinderFaces ), iwVertexsList.GetAt( i + 1 ).GetAt( j ), face );

	pBrep->CreatePolyFace( pRegion, pShell, iwVertexsList.GetAt( 0 ), face );
	face->ReverseOrientation( );
	pBrep->CreatePolyFace( pRegion, pShell, iwVertexsList.GetAt( params->CylinderSections ), face );

	CopyPBrep( pBrep );
	UpdateOGLListFromPBrep( OGLTransf, RefEnt->GetOGLList( OGLTransf ), false, true, false, true );

	delete pBrep;

	return;
}

//---------------------------------------------------------------------------

void TPBrepData::CreateLowPolyPlane( TOGLTransf *OGLTransf, TMeshPrimitiveParams *params )
{
	int sizeV, count;
	double dim1, dim2;
	T3DPoint position;
	IwPolyVertex **vertices;
	IwPolyFace *face;
	IwPolyBrep *pBrep;
	IwPolyRegion *pRegion;
	IwPolyShell *pShell;
	IwPoint3d pt3d;

	if ( !OGLTransf || !params || !RefEnt ) return;

	pBrep = new IwPolyBrep( _GetSMLib( )->GetContext( ), RES_COMP );
	if ( !pBrep ) return;
	pRegion = new IwPolyRegion( _GetSMLib( )->GetContext( ), pBrep );
	if ( !pRegion ) {
		_GetSMLib( )->DestroyIwPolyBrep( pBrep );
		pBrep = 0;
		return;
	}
	pShell = new IwPolyShell( _GetSMLib( )->GetContext( ), *pBrep, pRegion );
	if ( !pShell ) {
		_GetSMLib( )->DestroyIwPolyBrep( pBrep );
		pBrep = 0;
		pRegion = 0;
		return;
	}

	sizeV = 9;
	count = 0;
	dim1 = (double) params->PlaneDim1 / 2.0;
	dim2 = (double) params->PlaneDim2 / 2.0;

	vertices = new IwPolyVertex *[ sizeV ];
	position = T3DPoint( 0.0, 0.0, 0.0 );

	switch ( params->PlanePlane ) {
		case plXY:
			pt3d = IwPoint3d( position.x, position.y, position.z );
			vertices[ count++ ] = new IwPolyVertex( _GetSMLib( )->GetContext( ), *pBrep, pt3d, RES_COMP );
			pt3d = IwPoint3d( position.x + dim1, position.y, position.z );
			vertices[ count++ ] = new IwPolyVertex( _GetSMLib( )->GetContext( ), *pBrep, pt3d, RES_COMP );
			pt3d = IwPoint3d( position.x + dim1, position.y + dim2, position.z );
			vertices[ count++ ] = new IwPolyVertex( _GetSMLib( )->GetContext( ), *pBrep, pt3d, RES_COMP );
			pt3d = IwPoint3d( position.x, position.y + dim2, position.z );
			vertices[ count++ ] = new IwPolyVertex( _GetSMLib( )->GetContext( ), *pBrep, pt3d, RES_COMP );

			pt3d = IwPoint3d( position.x + dim1 * 2, position.y, position.z );
			vertices[ count++ ] = new IwPolyVertex( _GetSMLib( )->GetContext( ), *pBrep, pt3d, RES_COMP );
			pt3d = IwPoint3d( position.x + dim1 * 2, position.y + dim2, position.z );
			vertices[ count++ ] = new IwPolyVertex( _GetSMLib( )->GetContext( ), *pBrep, pt3d, RES_COMP );

			pt3d = IwPoint3d( position.x + dim1, position.y + dim2 * 2, position.z );
			vertices[ count++ ] = new IwPolyVertex( _GetSMLib( )->GetContext( ), *pBrep, pt3d, RES_COMP );
			pt3d = IwPoint3d( position.x, position.y + dim2 * 2, position.z );
			vertices[ count++ ] = new IwPolyVertex( _GetSMLib( )->GetContext( ), *pBrep, pt3d, RES_COMP );

			pt3d = IwPoint3d( position.x + dim1 * 2, position.y + dim2 * 2, position.z );
			vertices[ count ] = new IwPolyVertex( _GetSMLib( )->GetContext( ), *pBrep, pt3d, RES_COMP );
			break;

		case plXZ:
			pt3d = IwPoint3d( position.x, position.y, position.z );
			vertices[ count++ ] = new IwPolyVertex( _GetSMLib( )->GetContext( ), *pBrep, pt3d, RES_COMP );
			pt3d = IwPoint3d( position.x + dim1, position.y, position.z );
			vertices[ count++ ] = new IwPolyVertex( _GetSMLib( )->GetContext( ), *pBrep, pt3d, RES_COMP );
			pt3d = IwPoint3d( position.x + dim1, position.y, position.z + dim2 );
			vertices[ count++ ] = new IwPolyVertex( _GetSMLib( )->GetContext( ), *pBrep, pt3d, RES_COMP );
			pt3d = IwPoint3d( position.x, position.y, position.z + dim2 );
			vertices[ count++ ] = new IwPolyVertex( _GetSMLib( )->GetContext( ), *pBrep, pt3d, RES_COMP );

			pt3d = IwPoint3d( position.x + dim1 * 2, position.y, position.z );
			vertices[ count++ ] = new IwPolyVertex( _GetSMLib( )->GetContext( ), *pBrep, pt3d, RES_COMP );
			pt3d = IwPoint3d( position.x + dim1 * 2, position.y, position.z + dim2 );
			vertices[ count++ ] = new IwPolyVertex( _GetSMLib( )->GetContext( ), *pBrep, pt3d, RES_COMP );

			pt3d = IwPoint3d( position.x + dim1, position.y, position.z + dim2 * 2 );
			vertices[ count++ ] = new IwPolyVertex( _GetSMLib( )->GetContext( ), *pBrep, pt3d, RES_COMP );
			pt3d = IwPoint3d( position.x, position.y, position.z + dim2 * 2 );
			vertices[ count++ ] = new IwPolyVertex( _GetSMLib( )->GetContext( ), *pBrep, pt3d, RES_COMP );

			pt3d = IwPoint3d( position.x + dim1 * 2, position.y, position.z + dim2 * 2 );
			vertices[ count ] = new IwPolyVertex( _GetSMLib( )->GetContext( ), *pBrep, pt3d, RES_COMP );
			break;

		case plYZ:
			pt3d = IwPoint3d( position.x, position.y, position.z );
			vertices[ count++ ] = new IwPolyVertex( _GetSMLib( )->GetContext( ), *pBrep, pt3d, RES_COMP );
			pt3d = IwPoint3d( position.x, position.y + dim1, position.z );
			vertices[ count++ ] = new IwPolyVertex( _GetSMLib( )->GetContext( ), *pBrep, pt3d, RES_COMP );
			pt3d = IwPoint3d( position.x, position.y + dim1, position.z + dim2 );
			vertices[ count++ ] = new IwPolyVertex( _GetSMLib( )->GetContext( ), *pBrep, pt3d, RES_COMP );
			pt3d = IwPoint3d( position.x, position.y, position.z + dim2 );
			vertices[ count++ ] = new IwPolyVertex( _GetSMLib( )->GetContext( ), *pBrep, pt3d, RES_COMP );

			pt3d = IwPoint3d( position.x, position.y + dim1 * 2, position.z );
			vertices[ count++ ] = new IwPolyVertex( _GetSMLib( )->GetContext( ), *pBrep, pt3d, RES_COMP );
			pt3d = IwPoint3d( position.x, position.y + dim1 * 2, position.z + dim2 );
			vertices[ count++ ] = new IwPolyVertex( _GetSMLib( )->GetContext( ), *pBrep, pt3d, RES_COMP );

			pt3d = IwPoint3d( position.x, position.y + dim1, position.z + dim2 * 2 );
			vertices[ count++ ] = new IwPolyVertex( _GetSMLib( )->GetContext( ), *pBrep, pt3d, RES_COMP );
			pt3d = IwPoint3d( position.x, position.y, position.z + dim2 * 2 );
			vertices[ count++ ] = new IwPolyVertex( _GetSMLib( )->GetContext( ), *pBrep, pt3d, RES_COMP );

			pt3d = IwPoint3d( position.x, position.y + dim1 * 2, position.z + dim2 * 2 );
			vertices[ count ] = new IwPolyVertex( _GetSMLib( )->GetContext( ), *pBrep, pt3d, RES_COMP );
			break;
		default: break;
	}

	pBrep->CreatePolyQuad( pRegion, pShell, vertices[ 0 ], vertices[ 1 ], vertices[ 2 ], vertices[ 3 ], face );
	pBrep->CreatePolyQuad( pRegion, pShell, vertices[ 1 ], vertices[ 4 ], vertices[ 5 ], vertices[ 2 ], face );
	pBrep->CreatePolyQuad( pRegion, pShell, vertices[ 3 ], vertices[ 2 ], vertices[ 6 ], vertices[ 7 ], face );
	pBrep->CreatePolyQuad( pRegion, pShell, vertices[ 2 ], vertices[ 5 ], vertices[ 8 ], vertices[ 6 ], face );

	CopyPBrep( pBrep );
	UpdateOGLListFromPBrep( OGLTransf, RefEnt->GetOGLList( OGLTransf ), false, true, false, true );

	delete[] vertices;
	delete pBrep;

	return;
}

//---------------------------------------------------------------------------
// Creación de una tubería a partir de una curva
bool TPBrepData::CreateLowPolyPipe( TOGLTransf *OGLTransf, TCadEntity *rail, TMeshPrimitiveParams *params )
{
	bool isClosed;
	double pct, perSection, perRail, radExt, radExtLast, radInt, radIntLast, dist, minDistExt, minDistInt;
	int nPointsRail, i, j, nearestExt, nearestInt, nEdges;
	UnicodeString str;
	IwPolyBrep *pBrep;
	IwPolyRegion *pRegion;
	IwPolyShell *pShell;
	TOGLPolygon polRail, *polSection, polMesh;
	TOGLPolygonList *OGLList, polMeshListExt, polMeshListInt;
	TCadIBSpline *sectionExt, *sectionInt;
	TCadShape *dualshape;
	T3DPoint pt3d, normal, tan, pt3dFirst, pt3dLast, ptExt1, ptExt2, ptInt1, ptInt2;
	T3DVector vec;
	T3DPlane planeOri, planeDest;
	TNMatrix matrix, acumMatrix, acumMatrixInv, scaleMatrix;
	IwPoint3d iwPoint;
	IwPolyVertex *iwVertex, *iwFirstVertexRound, *iwLastVertexRound;
	IwPolyEdge *iwEdge;
	IwPolyFace *newFace;
	IwTA<IwPolyVertex *> iwVertexsExtSec1, iwVertexsExtSec2, iwVertexsExtFirstSec;
	IwTA<IwPolyVertex *> iwVertexsIntSec1, iwVertexsIntSec2, iwVertexsIntFirstSec;
	IwTA<IwPolyVertex *> iwFirstVertexsRound, iwLastVertexsRound;
	IwTA<IwPolyEdge *> iwCreaseEdges, iwEdges;
	IwTA<T3DPoint> iwFirstPointsUp, iwFirstPointsMid, iwFirstPointsDown;
	IwTA<T3DPoint> iwLastPointsUp, iwLastPointsMid, iwLastPointsDown;

	if ( !OGLTransf || !rail || !ToShape( rail ) || !params || !params->IsValid( LPM_CREATIONTYPE_PIPE ) ) return false;
	isClosed = ( ToShape( rail )->GetClose( ) != ENT_OPEN );

	dualshape = ( ToShape( rail ) ? ToShape( rail )->GetDualShapeByDep( ) : 0 );
	if ( dualshape && !dualshape->GetDualBaseEntity( )->IsParamEntity( ) ) OGLList = dualshape->GetOGLGeom3D( OGLTransf );
	else
		OGLList = rail->GetOGLGeom3D( OGLTransf );
	if ( !OGLList || OGLList->Count( ) != 1 ) return false;

	pBrep = new IwPolyBrep( _GetSMLib( )->GetContext( ), RES_COMP );
	if ( !pBrep ) return false;
	pRegion = new IwPolyRegion( _GetSMLib( )->GetContext( ), pBrep );
	if ( !pRegion ) {
		_GetSMLib( )->DestroyIwPolyBrep( pBrep );
		pBrep = 0;
		return false;
	}
	pShell = new IwPolyShell( _GetSMLib( )->GetContext( ), *pBrep, pRegion );
	if ( !pShell ) {
		_GetSMLib( )->DestroyIwPolyBrep( pBrep );
		pBrep = 0;
		pRegion = 0;
		return false;
	}

	// Obtenemos los puntos filtrados del rail donde se posicionan las secciones
	polRail.Set( OGLList->GetFirstItem( ) );
	polRail.Filter( params->PipePrecision, 0, 0, 10.0 );

	// Creamos la seccion
	sectionExt = new TCadIBSpline( );
	radExt = radExtLast = params->PipePctListRadius.GetValue( 0 ) + params->PipeThickness;
	pt3d = T3DPoint( radExt, 0.0, 0.0 );
	sectionExt->Add( OGLTransf, pt3d );
	pt3d = T3DPoint( 0.0, -radExt, 0.0 );
	sectionExt->Add( OGLTransf, pt3d );
	pt3d = T3DPoint( -radExt, 0.0, 0.0 );
	sectionExt->Add( OGLTransf, pt3d );
	pt3d = T3DPoint( 0.0, radExt, 0.0 );
	sectionExt->Add( OGLTransf, pt3d );
	sectionExt->SetClose( ENT_PERIODIC );
	if ( params->PipeThickness > 0.0 ) {
		sectionInt = new TCadIBSpline( );
		radInt = radIntLast = params->PipePctListRadius.GetValue( 0 );
		pt3d = T3DPoint( radInt, 0.0, 0.0 );
		sectionInt->Add( OGLTransf, pt3d );
		pt3d = T3DPoint( 0.0, -radInt, 0.0 );
		sectionInt->Add( OGLTransf, pt3d );
		pt3d = T3DPoint( -radInt, 0.0, 0.0 );
		sectionInt->Add( OGLTransf, pt3d );
		pt3d = T3DPoint( 0.0, radInt, 0.0 );
		sectionInt->Add( OGLTransf, pt3d );
		sectionInt->SetClose( ENT_PERIODIC );
	} else
		sectionInt = 0;

	// Calculamos las secciones en cada punto de polRail
	nPointsRail = polRail.Count( );
	if ( isClosed ) nPointsRail--;
	planeOri = T3DPlane( plXY );
	perRail = OGLList->GetFirstItem( )->Perimeter( );
	for ( i = 0; i < nPointsRail; i++ ) {
		pct = OGLList->GetFirstItem( )->GetPct( &polRail.GetItem( i )->v, perRail );
		OGLList->GetFirstItem( )->GetPointAndNormalFromPct( pct, perRail, pt3d, normal, 1.0, T3DPoint( 0.0, 0.0, 0.0 ) );
		vec = T3DVector( T3DSize( normal.x, normal.y, normal.z ), pt3d );
		planeDest = T3DPlane( pt3d, vec );
		matrix = _GetMatrixTransformPlaneToPlane( planeOri, planeDest );
		acumMatrix = acumMatrix * matrix;

		// Aplicamos la matriz a la sección
		sectionExt->ApplyMatrix( OGLTransf, &matrix );
		if ( sectionInt ) sectionInt->ApplyMatrix( OGLTransf, &matrix );

		// Si cambia el radio escalamos.
		radExt = params->PipePctListRadius.GetValueFromPct( pct ) + params->PipeThickness;
		if ( fabs( radExt - radExtLast ) > RES_GEOM ) {
			acumMatrixInv = acumMatrix.Inverse( );
			scaleMatrix = TNScaleMatrix( radExt / radExtLast, radExt / radExtLast, 1.0 );
			sectionExt->ApplyMatrix( OGLTransf, &acumMatrixInv );
			sectionExt->ApplyMatrix( OGLTransf, &scaleMatrix );
			sectionExt->ApplyMatrix( OGLTransf, &acumMatrix );
			radExtLast = radExt;
		}
		if ( params->PipeThickness > 0.0 ) {
			radInt = params->PipePctListRadius.GetValueFromPct( pct );
			if ( fabs( radInt - radIntLast ) > RES_GEOM ) {
				acumMatrixInv = acumMatrix.Inverse( );
				scaleMatrix = TNScaleMatrix( radInt / radIntLast, radInt / radIntLast, 1.0 );
				sectionInt->ApplyMatrix( OGLTransf, &acumMatrixInv );
				sectionInt->ApplyMatrix( OGLTransf, &scaleMatrix );
				sectionInt->ApplyMatrix( OGLTransf, &acumMatrix );
				radIntLast = radInt;
			}
		}

		planeOri = planeDest;

		// Nos guardamos los puntos
		polSection = sectionExt->GetOGLGeom3D( OGLTransf )->GetFirstItem( );
		perSection = polSection->Perimeter( );
		polMesh.Clear( );
		for ( j = 0; j < LPM_PIPE_NUMPOINTSSEC; j++ ) {
			pct = j * ( 1.0 / LPM_PIPE_NUMPOINTSSEC );
			polSection->GetPointAndNormalFromPct( pct, perSection, pt3d, normal );
			polMesh.AddItem( &pt3d );
		}
		polMeshListExt.Add( &polMesh );
		if ( sectionInt ) {
			polSection = sectionInt->GetOGLGeom3D( OGLTransf )->GetFirstItem( );
			perSection = polSection->Perimeter( );
			polMesh.Clear( );
			for ( j = 0; j < LPM_PIPE_NUMPOINTSSEC; j++ ) {
				pct = j * ( 1.0 / LPM_PIPE_NUMPOINTSSEC );
				polSection->GetPointAndNormalFromPct( pct, perSection, pt3d, normal );
				polMesh.AddItem( &pt3d );
			}
			polMeshListInt.Add( &polMesh );
		}
	}

	delete sectionExt;
	if ( params->PipeThickness ) delete sectionInt;

	// Si se el tipo de cierre es Round calculamos las esferas
	if ( params->PipeEndType == LPM_PIPE_ENDTYPE_ROUND ) {
		if ( !GetPointsSphere( OGLTransf, params->PipePctListRadius.GetValue( 0 ), &iwFirstPointsUp, &iwFirstPointsMid, &iwFirstPointsDown ) || !GetPointsSphere( OGLTransf, params->PipePctListRadius.GetValue( params->PipePctListRadius.Count( ) - 1 ), &iwLastPointsUp, &iwLastPointsMid, &iwLastPointsDown ) ) {
			_GetSMLib( )->DestroyIwPolyBrep( pBrep );
			pBrep = 0;
			pRegion = 0;
			return false;
		}

		pt3dFirst = T3DPoint( 0.0, 0.0, -params->PipePctListRadius.GetValue( 0 ) );
		pt3dLast = T3DPoint( 0.0, 0.0, params->PipePctListRadius.GetValue( params->PipePctListRadius.Count( ) - 1 ) );
		planeOri = T3DPlane( plXY );
		for ( i = 0; i < nPointsRail; i++ ) {
			pct = OGLList->GetFirstItem( )->GetPct( &polRail.GetItem( i )->v, perRail );
			OGLList->GetFirstItem( )->GetPointAndNormalFromPct( pct, perRail, pt3d, normal, 1.0, T3DPoint( 0.0, 0.0, 0.0 ) );
			vec = T3DVector( T3DSize( normal.x, normal.y, normal.z ), pt3d );
			planeDest = T3DPlane( pt3d, vec );
			matrix = _GetMatrixTransformPlaneToPlane( planeOri, planeDest );
			for ( j = 0; j < 8; j++ ) {
				if ( i == 0 ) {
					pt3d = iwFirstPointsDown.GetAt( j );
					pt3d.ApplyMatrix( matrix );
					iwFirstPointsDown.SetAt( j, pt3d );
				}
				pt3d = iwLastPointsUp.GetAt( j );
				pt3d.ApplyMatrix( matrix );
				iwLastPointsUp.SetAt( j, pt3d );
			}
			if ( i == 0 ) pt3dFirst.ApplyMatrix( matrix );
			pt3dLast.ApplyMatrix( matrix );
			planeOri = planeDest;
		}

		for ( j = 0; j < 8; j++ ) {
			pt3d = iwFirstPointsDown.GetAt( j );
			iwPoint = IwPoint3d( pt3d.x, pt3d.y, pt3d.z );
			iwVertex = new IwPolyVertex( _GetSMLib( )->GetContext( ), *PBrep, iwPoint, RES_COMP );
			iwFirstVertexsRound.Add( iwVertex );

			pt3d = iwLastPointsUp.GetAt( j );
			iwPoint = IwPoint3d( pt3d.x, pt3d.y, pt3d.z );
			iwVertex = new IwPolyVertex( _GetSMLib( )->GetContext( ), *PBrep, iwPoint, RES_COMP );
			iwLastVertexsRound.Add( iwVertex );
		}

		iwPoint = IwPoint3d( pt3dFirst.x, pt3dFirst.y, pt3dFirst.z );
		iwFirstVertexRound = new IwPolyVertex( _GetSMLib( )->GetContext( ), *PBrep, iwPoint, RES_COMP );

		iwPoint = IwPoint3d( pt3dLast.x, pt3dLast.y, pt3dLast.z );
		iwLastVertexRound = new IwPolyVertex( _GetSMLib( )->GetContext( ), *PBrep, iwPoint, RES_COMP );
	}

	// Creamos las caras de las tuberias
	for ( i = 0; i < nPointsRail; i++ ) {
		for ( j = 0; j < LPM_PIPE_NUMPOINTSSEC; j++ ) {
			pt3d = polMeshListExt.GetItem( i )->GetItem( j )->v.GetPoint( );
			iwPoint = IwPoint3d( pt3d.x, pt3d.y, pt3d.z );
			iwVertex = new IwPolyVertex( _GetSMLib( )->GetContext( ), *PBrep, iwPoint, RES_COMP );
			iwVertexsExtSec2.Add( iwVertex );
			if ( sectionInt ) {
				pt3d = polMeshListInt.GetItem( i )->GetItem( j )->v.GetPoint( );
				iwPoint = IwPoint3d( pt3d.x, pt3d.y, pt3d.z );
				iwVertex = new IwPolyVertex( _GetSMLib( )->GetContext( ), *PBrep, iwPoint, RES_COMP );
				iwVertexsIntSec2.Add( iwVertex );
			}
		}

		if ( i > 0 ) {
			for ( j = 0; j < LPM_PIPE_NUMPOINTSSEC; j++ ) {
				pBrep->CreatePolyQuad( pRegion, pShell, iwVertexsExtSec2.GetAt( j ), iwVertexsExtSec2.GetAt( ( j + 1 ) % LPM_PIPE_NUMPOINTSSEC ), iwVertexsExtSec1.GetAt( ( j + 1 ) % LPM_PIPE_NUMPOINTSSEC ), iwVertexsExtSec1.GetAt( j ), newFace );
				if ( sectionInt ) pBrep->CreatePolyQuad( pRegion, pShell, iwVertexsIntSec1.GetAt( j ), iwVertexsIntSec1.GetAt( ( j + 1 ) % LPM_PIPE_NUMPOINTSSEC ), iwVertexsIntSec2.GetAt( ( j + 1 ) % LPM_PIPE_NUMPOINTSSEC ), iwVertexsIntSec2.GetAt( j ), newFace );
			}
		}

		if ( i == ( nPointsRail - 1 ) && isClosed ) {
			minDistExt = minDistInt = MAXDOUBLE;
			nearestExt = nearestInt = 0;
			iwPoint = iwVertexsExtFirstSec.GetAt( 0 )->GetPoint( );
			ptExt1 = T3DPoint( iwPoint.x, iwPoint.y, iwPoint.z );
			if ( sectionInt ) {
				iwPoint = iwVertexsIntFirstSec.GetAt( 0 )->GetPoint( );
				ptInt1 = T3DPoint( iwPoint.x, iwPoint.y, iwPoint.z );
			}
			for ( j = 0; j < LPM_PIPE_NUMPOINTSSEC; j++ ) {
				iwPoint = iwVertexsExtSec2.GetAt( j )->GetPoint( );
				ptExt2 = T3DPoint( iwPoint.x, iwPoint.y, iwPoint.z );
				dist = ptExt1.DistanciaSqr( ptExt2 );
				if ( dist < minDistExt ) {
					minDistExt = dist;
					nearestExt = j;
				}
				if ( sectionInt ) {
					iwPoint = iwVertexsIntSec2.GetAt( j )->GetPoint( );
					ptInt2 = T3DPoint( iwPoint.x, iwPoint.y, iwPoint.z );
					dist = ptInt1.DistanciaSqr( ptInt2 );
					if ( dist < minDistInt ) {
						minDistInt = dist;
						nearestInt = j;
					}
				}
			}
			for ( j = 0; j < LPM_PIPE_NUMPOINTSSEC; j++ ) {
				pBrep->CreatePolyQuad( pRegion, pShell, iwVertexsExtFirstSec.GetAt( j ), iwVertexsExtFirstSec.GetAt( ( j + 1 ) % LPM_PIPE_NUMPOINTSSEC ), iwVertexsExtSec2.GetAt( ( j + nearestExt + 1 ) % LPM_PIPE_NUMPOINTSSEC ), iwVertexsExtSec2.GetAt( ( j + nearestExt ) % LPM_PIPE_NUMPOINTSSEC ), newFace );
				if ( sectionInt ) pBrep->CreatePolyQuad( pRegion, pShell, iwVertexsIntSec2.GetAt( ( j + nearestInt ) % LPM_PIPE_NUMPOINTSSEC ), iwVertexsIntSec2.GetAt( ( j + nearestInt + 1 ) % LPM_PIPE_NUMPOINTSSEC ), iwVertexsIntFirstSec.GetAt( ( j + 1 ) % LPM_PIPE_NUMPOINTSSEC ), iwVertexsIntFirstSec.GetAt( j ), newFace );
			}
		}

		if ( i == ( nPointsRail - 1 ) && !isClosed ) {
			if ( params->PipeEndType == LPM_PIPE_ENDTYPE_PLANE ) {
				if ( params->PipeThickness ) {
					for ( j = 0; j < LPM_PIPE_NUMPOINTSSEC; j++ ) {
						pBrep->CreatePolyQuad( pRegion, pShell, iwVertexsExtFirstSec.GetAt( j ), iwVertexsExtFirstSec.GetAt( ( j + 1 ) % LPM_PIPE_NUMPOINTSSEC ), iwVertexsIntFirstSec.GetAt( ( j + 1 ) % LPM_PIPE_NUMPOINTSSEC ), iwVertexsIntFirstSec.GetAt( j ), newFace );
						MarkCreaseNewFace( newFace, iwVertexsExtFirstSec.GetAt( j ), iwVertexsExtFirstSec.GetAt( ( j + 1 ) % LPM_PIPE_NUMPOINTSSEC ) );
						MarkCreaseNewFace( newFace, iwVertexsIntFirstSec.GetAt( ( j + 1 ) % LPM_PIPE_NUMPOINTSSEC ), iwVertexsIntFirstSec.GetAt( j ) );
						pBrep->CreatePolyQuad( pRegion, pShell, iwVertexsIntSec2.GetAt( j ), iwVertexsIntSec2.GetAt( ( j + 1 ) % LPM_PIPE_NUMPOINTSSEC ), iwVertexsExtSec2.GetAt( ( j + 1 ) % LPM_PIPE_NUMPOINTSSEC ), iwVertexsExtSec2.GetAt( j ), newFace );
						MarkCreaseNewFace( newFace, iwVertexsIntSec2.GetAt( j ), iwVertexsIntSec2.GetAt( ( j + 1 ) % LPM_PIPE_NUMPOINTSSEC ) );
						MarkCreaseNewFace( newFace, iwVertexsExtSec2.GetAt( ( j + 1 ) % LPM_PIPE_NUMPOINTSSEC ), iwVertexsExtSec2.GetAt( j ) );
					}
				} else {
					pt3d = polMeshListExt.GetFirstItem( )->GravityCenter( );
					iwPoint = IwPoint3d( pt3d.x, pt3d.y, pt3d.z );
					iwVertex = new IwPolyVertex( _GetSMLib( )->GetContext( ), *PBrep, iwPoint, RES_COMP );
					for ( j = 0; j < LPM_PIPE_NUMPOINTSSEC; j++ ) {
						pBrep->CreatePolyTriangle( pRegion, pShell, iwVertexsExtFirstSec.GetAt( j ), iwVertexsExtFirstSec.GetAt( ( j + 1 ) % LPM_PIPE_NUMPOINTSSEC ), iwVertex, newFace );
						MarkCreaseNewFace( newFace, iwVertexsExtFirstSec.GetAt( j ), iwVertexsExtFirstSec.GetAt( ( j + 1 ) % LPM_PIPE_NUMPOINTSSEC ) );
					}

					pt3d = polMeshListExt.GetLastItem( )->GravityCenter( );
					iwPoint = IwPoint3d( pt3d.x, pt3d.y, pt3d.z );
					iwVertex = new IwPolyVertex( _GetSMLib( )->GetContext( ), *PBrep, iwPoint, RES_COMP );
					for ( j = 0; j < LPM_PIPE_NUMPOINTSSEC; j++ ) {
						pBrep->CreatePolyTriangle( pRegion, pShell, iwVertexsExtSec2.GetAt( ( j + 1 ) % LPM_PIPE_NUMPOINTSSEC ), iwVertexsExtSec2.GetAt( j ), iwVertex, newFace );
						MarkCreaseNewFace( newFace, iwVertexsExtSec2.GetAt( ( j + 1 ) % LPM_PIPE_NUMPOINTSSEC ), iwVertexsExtSec2.GetAt( j ) );
					}
				}
			} else if ( params->PipeEndType == LPM_PIPE_ENDTYPE_ROUND ) {
				for ( j = 0; j < 8; j++ ) {
					pBrep->CreatePolyQuad( pRegion, pShell, iwVertexsExtFirstSec.GetAt( j ), iwVertexsExtFirstSec.GetAt( ( j + 1 ) % LPM_PIPE_NUMPOINTSSEC ), iwFirstVertexsRound.GetAt( ( j + 1 ) % LPM_PIPE_NUMPOINTSSEC ), iwFirstVertexsRound.GetAt( j ), newFace );
					pBrep->CreatePolyQuad( pRegion, pShell, iwLastVertexsRound.GetAt( j ), iwLastVertexsRound.GetAt( ( j + 1 ) % LPM_PIPE_NUMPOINTSSEC ), iwVertexsExtSec2.GetAt( ( j + 1 ) % LPM_PIPE_NUMPOINTSSEC ), iwVertexsExtSec2.GetAt( j ), newFace );
					if ( j == 0 || j == 2 || j == 4 || j == 6 ) {
						pBrep->CreatePolyQuad( pRegion, pShell, iwFirstVertexRound, iwFirstVertexsRound.GetAt( j ), iwFirstVertexsRound.GetAt( ( j + 1 ) % LPM_PIPE_NUMPOINTSSEC ), iwFirstVertexsRound.GetAt( ( j + 2 ) % LPM_PIPE_NUMPOINTSSEC ), newFace );
						pBrep->CreatePolyQuad( pRegion, pShell, iwLastVertexRound, iwLastVertexsRound.GetAt( ( j + 2 ) % LPM_PIPE_NUMPOINTSSEC ), iwLastVertexsRound.GetAt( ( j + 1 ) % LPM_PIPE_NUMPOINTSSEC ), iwLastVertexsRound.GetAt( j ), newFace );
					}
				}
			}
		}

		if ( i == 0 ) iwVertexsExtFirstSec.Append( iwVertexsExtSec2 );
		iwVertexsExtSec1.RemoveAll( );
		iwVertexsExtSec1.Append( iwVertexsExtSec2 );
		iwVertexsExtSec2.RemoveAll( );
		if ( sectionInt ) {
			if ( i == 0 ) iwVertexsIntFirstSec.Append( iwVertexsIntSec2 );
			iwVertexsIntSec1.RemoveAll( );
			iwVertexsIntSec1.Append( iwVertexsIntSec2 );
			iwVertexsIntSec2.RemoveAll( );
		}
	}

	// Copiamos la pBrep
	CopyPBrep( pBrep );

	// Marcamos las aristas de pliegues si es necesario
	PBrep->GetPolyEdges( iwEdges );
	nEdges = (int) iwEdges.GetSize( );
	for ( i = 0; i < nEdges; i++ ) {
		iwEdge = iwEdges.GetAt( i );
		if ( iwEdge->GetUserFloat1( ) > 0.0 && iwEdge->GetUserIndex1( ) != ULONG_MAX ) iwCreaseEdges.Add( iwEdge );
	}
	nEdges = (int) iwCreaseEdges.GetSize( );
	for ( i = 0; i < nEdges; i++ ) {
		iwEdge = iwCreaseEdges.GetAt( i );
		AddCreaseEdges( OGLTransf, iwEdge, iwEdge->GetUserFloat1( ), false, false );
	}

	UpdateOGLListFromPBrep( OGLTransf, RefEnt->GetOGLList( OGLTransf ), false, true, false, true );

	delete pBrep;

	return true;
}

//---------------------------------------------------------------------------
// Creación de una revolución a partir de una curva y un eje
bool TPBrepData::CreateLowPolyRevolve( TOGLTransf *OGLTransf, TMeshPrimitiveParams *params )
{
	int i, j, nsecs, npoints;
	TOGLPolygonList revolveCoarseSections;
	T3DPoint pt3d, pt3d_prev_1, pt3d_prev_2, pt3d_prev_3, pt3d_post_1, pt3d_post_2, pt3d_post_3, pt3d_aux;
	IwPolyBrep *pBrep;
	IwPolyRegion *pRegion;
	IwPolyShell *pShell;
	IwPoint3d iwPoint;
	IwPolyVertex *iwVertex, *iwVertex1, *iwVertex2, *iwVertex3, *iwVertex4;
	IwPolyFace *iwFace;
	IwTA<IwPolyVertex *> iwVertexs;
	IwTA<IwTA<IwPolyVertex *> > iwVertexsAll;
	TReverseSubdivision *reverseSubd;

	if ( !OGLTransf || !params || !params->RevolveBaseCrv || !ToShape( params->RevolveBaseCrv ) || !params->IsValid( LPM_CREATIONTYPE_REVOLVE ) ) return false;

	// Obtenemos los coarse points por subdivisión inversa
	reverseSubd = new TReverseSubdivision( OGLTransf, ST_REVOLVE, params );
	if ( !reverseSubd->GetReverseSubdivision( &revolveCoarseSections ) ) {
		delete reverseSubd;
		return false;
	}

	// Creamos pbRep
	pBrep = new IwPolyBrep( _GetSMLib( )->GetContext( ), RES_COMP );
	if ( !pBrep ) {
		delete reverseSubd;
		return false;
	}
	pRegion = new IwPolyRegion( _GetSMLib( )->GetContext( ), pBrep );
	if ( !pRegion ) {
		_GetSMLib( )->DestroyIwPolyBrep( pBrep );
		pBrep = 0;
		delete reverseSubd;
		return false;
	}
	pShell = new IwPolyShell( _GetSMLib( )->GetContext( ), *pBrep, pRegion );
	if ( !pShell ) {
		_GetSMLib( )->DestroyIwPolyBrep( pBrep );
		pBrep = 0;
		pRegion = 0;
		delete reverseSubd;
		return false;
	}

	// Creamos los vértices
	nsecs = revolveCoarseSections.Count( );
	npoints = revolveCoarseSections.GetItem( 0 )->Count( );
	for ( i = 0; i < nsecs; i++ ) {
		iwVertexs.RemoveAll( );
		for ( j = 0; j < npoints; j++ ) {
			if ( reverseSubd->GetClosed_V_First( ) && j == 0 && i > 0 ) // Si es una curva abierta y se cierra en el primer punto, sólo lo creamos una vez
				iwVertexs.Add( iwVertexsAll.GetAt( 0 ).GetAt( 0 ) );
			else if ( reverseSubd->GetClosed_V_Last( ) && j == ( npoints - 1 ) && i > 0 ) // Si es una curva abierta y se cierra en el último punto, sólo lo creamos una vez
				iwVertexs.Add( iwVertexsAll.GetAt( 0 ).GetAt( npoints - 1 ) );
			else {
				pt3d = revolveCoarseSections.GetItem( i )->GetItem( j )->v.GetPoint( );
				iwPoint = IwPoint3d( pt3d.x, pt3d.y, pt3d.z );
				iwVertex = new IwPolyVertex( _GetSMLib( )->GetContext( ), *PBrep, iwPoint, RES_COMP );
				iwVertexs.Add( iwVertex );
			}
		}
		iwVertexsAll.Add( iwVertexs );
	}

	// Creamos las caras
	for ( i = 0; i < ( nsecs - 1 ); i++ ) {
		for ( j = 0; j < ( npoints - 1 ); j++ ) {
			if ( reverseSubd->GetClosed_V_First( ) && j == 0 ) {
				iwVertex1 = iwVertexsAll.GetAt( i ).GetAt( j );
				iwVertex2 = iwVertexsAll.GetAt( i + 1 ).GetAt( j + 1 );
				iwVertex3 = iwVertexsAll.GetAt( i ).GetAt( j + 1 );
				pBrep->CreatePolyTriangle( pRegion, pShell, iwVertex1, iwVertex2, iwVertex3, iwFace );
			} else if ( reverseSubd->GetClosed_V_Last( ) && j == ( npoints - 2 ) ) {
				iwVertex1 = iwVertexsAll.GetAt( i ).GetAt( j );
				iwVertex2 = iwVertexsAll.GetAt( i + 1 ).GetAt( j );
				iwVertex3 = iwVertexsAll.GetAt( i ).GetAt( j + 1 );
				pBrep->CreatePolyTriangle( pRegion, pShell, iwVertex1, iwVertex2, iwVertex3, iwFace );
			} else {
				iwVertex1 = iwVertexsAll.GetAt( i ).GetAt( j );
				iwVertex2 = iwVertexsAll.GetAt( i + 1 ).GetAt( j );
				iwVertex3 = iwVertexsAll.GetAt( i + 1 ).GetAt( j + 1 );
				iwVertex4 = iwVertexsAll.GetAt( i ).GetAt( j + 1 );
				pBrep->CreatePolyQuad( pRegion, pShell, iwVertex1, iwVertex2, iwVertex3, iwVertex4, iwFace );
			}
		}
	}
	if ( reverseSubd->GetClosed_V( ) ) {
		for ( i = 0; i < ( nsecs - 1 ); i++ ) {
			iwVertex1 = iwVertexsAll.GetAt( i ).GetAt( npoints - 1 );
			iwVertex2 = iwVertexsAll.GetAt( i + 1 ).GetAt( npoints - 1 );
			iwVertex3 = iwVertexsAll.GetAt( i + 1 ).GetAt( 0 );
			iwVertex4 = iwVertexsAll.GetAt( i ).GetAt( 0 );
			pBrep->CreatePolyQuad( pRegion, pShell, iwVertex1, iwVertex2, iwVertex3, iwVertex4, iwFace );
		}
	}
	if ( reverseSubd->GetClosed_H( ) ) {
		for ( j = 0; j < ( npoints - 1 ); j++ ) {
			if ( reverseSubd->GetClosed_V_First( ) && j == 0 ) {
				iwVertex1 = iwVertexsAll.GetAt( 0 ).GetAt( j );
				iwVertex2 = iwVertexsAll.GetAt( 0 ).GetAt( j + 1 );
				iwVertex3 = iwVertexsAll.GetAt( nsecs - 1 ).GetAt( j + 1 );
				pBrep->CreatePolyTriangle( pRegion, pShell, iwVertex1, iwVertex2, iwVertex3, iwFace );
			} else if ( reverseSubd->GetClosed_V_Last( ) && j == ( npoints - 2 ) ) {
				iwVertex1 = iwVertexsAll.GetAt( 0 ).GetAt( j );
				iwVertex2 = iwVertexsAll.GetAt( 0 ).GetAt( j + 1 );
				iwVertex3 = iwVertexsAll.GetAt( nsecs - 1 ).GetAt( j );
				pBrep->CreatePolyTriangle( pRegion, pShell, iwVertex1, iwVertex2, iwVertex3, iwFace );
			} else {
				iwVertex1 = iwVertexsAll.GetAt( nsecs - 1 ).GetAt( j );
				iwVertex2 = iwVertexsAll.GetAt( 0 ).GetAt( j );
				iwVertex3 = iwVertexsAll.GetAt( 0 ).GetAt( j + 1 );
				iwVertex4 = iwVertexsAll.GetAt( nsecs - 1 ).GetAt( j + 1 );
				pBrep->CreatePolyQuad( pRegion, pShell, iwVertex1, iwVertex2, iwVertex3, iwVertex4, iwFace );
			}
		}
		if ( reverseSubd->GetClosed_V( ) ) {
			iwVertex1 = iwVertexsAll.GetAt( nsecs - 1 ).GetAt( npoints - 1 );
			iwVertex2 = iwVertexsAll.GetAt( 0 ).GetAt( npoints - 1 );
			iwVertex3 = iwVertexsAll.GetAt( 0 ).GetAt( 0 );
			iwVertex4 = iwVertexsAll.GetAt( nsecs - 1 ).GetAt( 0 );
			pBrep->CreatePolyQuad( pRegion, pShell, iwVertex1, iwVertex2, iwVertex3, iwVertex4, iwFace );
		}
	}

	// Copiamos la pBrep
	CopyPBrep( pBrep );

	UpdateOGLListFromPBrep( OGLTransf, RefEnt->GetOGLList( OGLTransf ), false, true, false, true );
	delete pBrep;

	delete reverseSubd;

	return true;
}

//---------------------------------------------------------------------------
// Creación de un contorno a partir de una curva
bool TPBrepData::CreateLowPolyContour( TOGLTransf *OGLTransf, TMeshPrimitiveParams *params )
{
	bool close[ 2 ];
	int i, ind;
	double contourprecision, limits[ 4 ];
	T3DPoint pt3d, p1, p2, normal;
	T3DPoint pt, oldpt;
	TCadShape *shape;
	TCadSurface *paramsurf;
	TCadTrimSurface *trim;
	TOGLPolygon polAux;
	TOGLPolygonList pollist;
	IwPolyBrep *pBrep;
	IwTA<IwPolyEdge *> boundaryedgesDown;
	IwTA<IwPolyFace *> newfaces;
	TReverseSubdivision *reverseSubd;

	if ( !params || !params->ContourBaseCrv || !ToShape( params->ContourBaseCrv ) || ToShape( params->ContourBaseCrv )->GetClose( OGLTransf ) == ENT_OPEN ) return false;
	if ( params->ContourPrecision < 0.0 || params->ContourPrecision > 1.0 ) return false;

	contourprecision = ( 1.0 - params->ContourPrecision ) * 10 + 1;
	shape = ToShape( params->ContourBaseCrv );
	paramsurf = shape->GetDualParamSurface( );
	if ( !paramsurf ) return false;

	// Obtenemos los coarse points por subdivisión inversa
	reverseSubd = new TReverseSubdivision( OGLTransf, ST_CONTOUR, params );
	if ( !reverseSubd->GetReverseSubdivision( &pollist ) ) {
		delete reverseSubd;
		return false;
	}
	delete reverseSubd;

	// Obtenemos la triangulacion de delaunay
	pBrep = _GetSMLib( )->Tessellate2DDelaunay( &pollist, contourprecision, false, false );
	if ( !pBrep ) {
		return false;
	}

	CopyPBrep( pBrep );
	delete pBrep;

	JoinTrianglesInQuads( OGLTransf );

	trim = new TCadTrimSurface( paramsurf, shape, OGLTransf, RES_PARAM );
	trim->SetUseSurfaceSmallToDevelop( false );

	close[ 0 ] = ( paramsurf->GetUCloseExt( OGLTransf ) == ENT_CLOSE );
	close[ 1 ] = ( paramsurf->GetVCloseExt( OGLTransf ) == ENT_CLOSE );
	paramsurf->GetLimitsUV( OGLTransf, limits );

	for ( i = 0; i < (int) PBrepVertexs.GetSize( ); i++ ) {
		pt3d.x = PBrepVertexs[ i ]->GetPointPtr( )->x;
		pt3d.y = PBrepVertexs[ i ]->GetPointPtr( )->y;
		pt3d.z = PBrepVertexs[ i ]->GetPointPtr( )->z;

		polAux.Clear( );
		trim->PointDevToPointParam( OGLTransf, pt3d, &polAux, true );

		if ( !polAux.Count( ) || polAux.GetItem( 0 )->n.v[ 1 ] > RES_GEOM ) continue;
		p1 = polAux.GetItem( 0 )->uv.Get3DPoint( );

		p1.x = _ToParamRangeInLimitsF( polAux.GetItem( 0 )->uv.v[ 0 ], close[ 0 ], limits[ 0 ], limits[ 2 ] );
		p1.y = _ToParamRangeInLimitsF( polAux.GetItem( 0 )->uv.v[ 1 ], close[ 1 ], limits[ 1 ], limits[ 3 ] );

		if ( params->ContourOffset > RES_GEOM ) {
			paramsurf->GetPointAndNormal( OGLTransf, p1.x, p1.y, p2, normal );

			p2.x += normal.x * params->ContourOffset;
			p2.y += normal.y * params->ContourOffset;
			p2.z += normal.z * params->ContourOffset;
		} else
			paramsurf->GetPoint( OGLTransf, p1.x, p1.y, p2 );

		PBrepVertexs[ i ]->GetPointPtr( )->x = p2.x;
		PBrepVertexs[ i ]->GetPointPtr( )->y = p2.y;
		PBrepVertexs[ i ]->GetPointPtr( )->z = p2.z;
	}
	delete trim;

	if ( params->ContourThickness > RES_GEOM ) {
		SelectAllFaces( OGLTransf );

		DuplicateFaces( OGLTransf, &newfaces, &boundaryedgesDown, 0 );

		if ( params->ContourProfile == BORDERTYPE_STRAIGHT || params->ContourProfile == BORDERTYPE_HALFROUNDED ) { // BORDERTYPE_STRAIGHT, BORDERTYPE_ROUNDED, BORDERTYPE_HALFROUNDED, BORDERTYPE_HALFROUNDED_INV
			for ( i = 0; i < (int) boundaryedgesDown.GetSize( ); i++ )
				AddCreaseEdges( OGLTransf, boundaryedgesDown[ i ], 0.75, false, false, SelectedElementType::AllSelected, false );
		}

		TInteger_List indexes;
		for ( i = 0; i < (int) newfaces.GetSize( ); i++ ) {
			ind = newfaces[ i ]->GetIndexExt( );
			indexes.AddItem( &ind );
		}

		SelectFaces( OGLTransf, &indexes );
		ExtrudeSelectedGroupFacesByVertexNormal( OGLTransf, params->ContourThickness, pollist.GetItem( 0 )->IsClockwise( plXY ) ? 1 : -1, true, params->ContourProfile == BORDERTYPE_STRAIGHT || params->ContourProfile == BORDERTYPE_HALFROUNDED_INV, 0.75 ); // Para crear las piezas, con el borde a 1 se marcan demasiado.
		UnSelectAllFaces( OGLTransf );
	}

	UpdateOGLListFromPBrep( OGLTransf, RefEnt->GetOGLList( OGLTransf ), false, true, false, true );

	return true;
}

//---------------------------------------------------------------------------
// Creación de un barrido por 1 carril
bool TPBrepData::CreateLowPolyOneRailSweep( TOGLTransf *OGLTransf, TMeshPrimitiveParams *params )
{
	int i, j, nPointsRail, nPointsForm;
	TOGLPolygonList revolveCoarseSections;
	T3DPoint pt3d, pt3d_prev_1, pt3d_prev_2, pt3d_prev_3, pt3d_post_1, pt3d_post_2, pt3d_post_3, pt3d_aux;
	IwPolyBrep *pBrep;
	IwPolyRegion *pRegion;
	IwPolyShell *pShell;
	IwPoint3d iwPoint;
	IwPolyVertex *iwVertex, *iwVertex1, *iwVertex2, *iwVertex3, *iwVertex4;
	IwPolyFace *iwFace;
	IwTA<IwPolyVertex *> iwVertexs;
	IwTA<IwTA<IwPolyVertex *> > iwVertexsAll;
	IwTA<IwPolyEdge *> iwEdgesFace;
	TReverseSubdivision *reverseSubd;
	if ( !OGLTransf || !params || !params->OneRailSweepRailCrv || !ToShape( params->OneRailSweepRailCrv ) || !params->OneRailSweepFormCrv || !ToShape( params->OneRailSweepFormCrv ) || !params->IsValid( LPM_CREATIONTYPE_ONE_RAIL_SWEEP ) ) return false;

	// Obtenemos los coarse points de la curva de forma por subdivisión inversa
	reverseSubd = new TReverseSubdivision( OGLTransf, ST_ONE_RAIL_SWEEP, params );
	if ( !reverseSubd->GetReverseSubdivisionSISL( &revolveCoarseSections ) ) {
		delete reverseSubd;
		return false;
	}

	// Creamos pbRep
	pBrep = new IwPolyBrep( _GetSMLib( )->GetContext( ), RES_COMP );
	if ( !pBrep ) {
		delete reverseSubd;
		return false;
	}
	pRegion = new IwPolyRegion( _GetSMLib( )->GetContext( ), pBrep );
	if ( !pRegion ) {
		_GetSMLib( )->DestroyIwPolyBrep( pBrep );
		pBrep = 0;
		delete reverseSubd;
		return false;
	}
	pShell = new IwPolyShell( _GetSMLib( )->GetContext( ), *pBrep, pRegion );
	if ( !pShell ) {
		_GetSMLib( )->DestroyIwPolyBrep( pBrep );
		pBrep = 0;
		pRegion = 0;
		delete reverseSubd;
		return false;
	}

	// Creamos los vértices
	nPointsRail = revolveCoarseSections.Count( );
	nPointsForm = revolveCoarseSections.GetItem( 0 )->Count( );
	for ( i = 0; i < nPointsRail; i++ ) {
		iwVertexs.RemoveAll( );
		for ( j = 0; j < nPointsForm; j++ ) {
			if ( reverseSubd->GetClosed_V_First( ) && j == 0 && i > 0 ) // Si es una curva abierta y se cierra en el primer punto, sólo lo creamos una vez
				iwVertexs.Add( iwVertexsAll.GetAt( 0 ).GetAt( 0 ) );
			else if ( reverseSubd->GetClosed_V_Last( ) && j == ( nPointsForm - 1 ) && i > 0 ) // Si es una curva abierta y se cierra en el último punto, sólo lo creamos una vez
				iwVertexs.Add( iwVertexsAll.GetAt( 0 ).GetAt( nPointsForm - 1 ) );
			else {
				pt3d = revolveCoarseSections.GetItem( i )->GetItem( j )->v.GetPoint( );
				iwPoint = IwPoint3d( pt3d.x, pt3d.y, pt3d.z );
				iwVertex = new IwPolyVertex( _GetSMLib( )->GetContext( ), *PBrep, iwPoint, RES_COMP );
				iwVertexs.Add( iwVertex );
			}
		}
		iwVertexsAll.Add( iwVertexs );
	}

	// Creamos las caras
	for ( i = 0; i < ( nPointsRail - 1 ); i++ ) {
		for ( j = 0; j < ( nPointsForm - 1 ); j++ ) {
			if ( reverseSubd->GetClosed_V_First( ) && j == 0 ) {
				iwVertex1 = iwVertexsAll.GetAt( i ).GetAt( j );
				iwVertex2 = iwVertexsAll.GetAt( i + 1 ).GetAt( j + 1 );
				iwVertex3 = iwVertexsAll.GetAt( i ).GetAt( j + 1 );
				pBrep->CreatePolyTriangle( pRegion, pShell, iwVertex1, iwVertex2, iwVertex3, iwFace );
			} else if ( reverseSubd->GetClosed_V_Last( ) && j == ( nPointsForm - 2 ) ) {
				iwVertex1 = iwVertexsAll.GetAt( i ).GetAt( j );
				iwVertex2 = iwVertexsAll.GetAt( i + 1 ).GetAt( j );
				iwVertex3 = iwVertexsAll.GetAt( i ).GetAt( j + 1 );
				pBrep->CreatePolyTriangle( pRegion, pShell, iwVertex1, iwVertex2, iwVertex3, iwFace );
			} else {
				iwVertex1 = iwVertexsAll.GetAt( i ).GetAt( j );
				iwVertex2 = iwVertexsAll.GetAt( i + 1 ).GetAt( j );
				iwVertex3 = iwVertexsAll.GetAt( i + 1 ).GetAt( j + 1 );
				iwVertex4 = iwVertexsAll.GetAt( i ).GetAt( j + 1 );
				pBrep->CreatePolyQuad( pRegion, pShell, iwVertex1, iwVertex2, iwVertex3, iwVertex4, iwFace );

				iwFace->GetPolyEdges( iwEdgesFace );
				if ( reverseSubd->IsCornerRail1( i ) ) AddCreaseEdges( OGLTransf, iwEdgesFace.GetAt( 3 ), 1.0, false, false, SelectedElementType::AllSelected, false );
				if ( !reverseSubd->GetClosed_H( ) && i == ( nPointsRail - 2 ) && reverseSubd->IsCornerRail1( nPointsRail - 1 ) ) AddCreaseEdges( OGLTransf, iwEdgesFace.GetAt( 1 ), 1.0, false, false, SelectedElementType::AllSelected, false );
				if ( reverseSubd->IsCornerForm( j ) ) AddCreaseEdges( OGLTransf, iwEdgesFace.GetAt( 0 ), 1.0, false, false, SelectedElementType::AllSelected, false );
				if ( !reverseSubd->GetClosed_V( ) && j == ( nPointsForm - 2 ) && reverseSubd->IsCornerForm( nPointsForm - 1 ) ) AddCreaseEdges( OGLTransf, iwEdgesFace.GetAt( 2 ), 1.0, false, false, SelectedElementType::AllSelected, false );
			}
		}
	}
	if ( reverseSubd->GetClosed_V( ) ) {
		for ( i = 0; i < ( nPointsRail - 1 ); i++ ) {
			iwVertex1 = iwVertexsAll.GetAt( i ).GetAt( nPointsForm - 1 );
			iwVertex2 = iwVertexsAll.GetAt( i + 1 ).GetAt( nPointsForm - 1 );
			iwVertex3 = iwVertexsAll.GetAt( i + 1 ).GetAt( 0 );
			iwVertex4 = iwVertexsAll.GetAt( i ).GetAt( 0 );
			pBrep->CreatePolyQuad( pRegion, pShell, iwVertex1, iwVertex2, iwVertex3, iwVertex4, iwFace );

			iwFace->GetPolyEdges( iwEdgesFace );
			if ( reverseSubd->IsCornerForm( nPointsForm - 1 ) ) AddCreaseEdges( OGLTransf, iwEdgesFace.GetAt( 0 ), 1.0, false, false, SelectedElementType::AllSelected, false );
			if ( reverseSubd->IsCornerForm( 0 ) ) AddCreaseEdges( OGLTransf, iwEdgesFace.GetAt( 2 ), 1.0, false, false, SelectedElementType::AllSelected, false );
		}
	}
	if ( reverseSubd->GetClosed_H( ) ) {
		for ( j = 0; j < ( nPointsForm - 1 ); j++ ) {
			if ( reverseSubd->GetClosed_V_First( ) && j == 0 ) {
				iwVertex1 = iwVertexsAll.GetAt( 0 ).GetAt( j );
				iwVertex2 = iwVertexsAll.GetAt( 0 ).GetAt( j + 1 );
				iwVertex3 = iwVertexsAll.GetAt( nPointsRail - 1 ).GetAt( j + 1 );
				pBrep->CreatePolyTriangle( pRegion, pShell, iwVertex1, iwVertex2, iwVertex3, iwFace );
			} else if ( reverseSubd->GetClosed_V_Last( ) && j == ( nPointsForm - 2 ) ) {
				iwVertex1 = iwVertexsAll.GetAt( 0 ).GetAt( j );
				iwVertex2 = iwVertexsAll.GetAt( 0 ).GetAt( j + 1 );
				iwVertex3 = iwVertexsAll.GetAt( nPointsRail - 1 ).GetAt( j );
				pBrep->CreatePolyTriangle( pRegion, pShell, iwVertex1, iwVertex2, iwVertex3, iwFace );
			} else {
				iwVertex1 = iwVertexsAll.GetAt( nPointsRail - 1 ).GetAt( j );
				iwVertex2 = iwVertexsAll.GetAt( 0 ).GetAt( j );
				iwVertex3 = iwVertexsAll.GetAt( 0 ).GetAt( j + 1 );
				iwVertex4 = iwVertexsAll.GetAt( nPointsRail - 1 ).GetAt( j + 1 );
				pBrep->CreatePolyQuad( pRegion, pShell, iwVertex1, iwVertex2, iwVertex3, iwVertex4, iwFace );

				iwFace->GetPolyEdges( iwEdgesFace );
				if ( reverseSubd->IsCornerRail1( nPointsRail - 1 ) ) AddCreaseEdges( OGLTransf, iwEdgesFace.GetAt( 3 ), 1.0, false, false, SelectedElementType::AllSelected, false );
				if ( reverseSubd->IsCornerRail1( 0 ) ) AddCreaseEdges( OGLTransf, iwEdgesFace.GetAt( 1 ), 1.0, false, false, SelectedElementType::AllSelected, false );
			}
		}
		if ( reverseSubd->GetClosed_V( ) ) {
			iwVertex1 = iwVertexsAll.GetAt( nPointsRail - 1 ).GetAt( nPointsForm - 1 );
			iwVertex2 = iwVertexsAll.GetAt( 0 ).GetAt( nPointsForm - 1 );
			iwVertex3 = iwVertexsAll.GetAt( 0 ).GetAt( 0 );
			iwVertex4 = iwVertexsAll.GetAt( nPointsRail - 1 ).GetAt( 0 );
			pBrep->CreatePolyQuad( pRegion, pShell, iwVertex1, iwVertex2, iwVertex3, iwVertex4, iwFace );

			iwFace->GetPolyEdges( iwEdgesFace );
			if ( reverseSubd->IsCornerForm( nPointsForm - 2 ) ) AddCreaseEdges( OGLTransf, iwEdgesFace.GetAt( 0 ), 1.0, false, false, SelectedElementType::AllSelected, false );
			if ( reverseSubd->IsCornerForm( nPointsForm - 1 ) ) AddCreaseEdges( OGLTransf, iwEdgesFace.GetAt( 2 ), 1.0, false, false, SelectedElementType::AllSelected, false );
		}
	}

	// Copiamos la pBrep
	CopyPBrep( pBrep );

	UpdateOGLListFromPBrep( OGLTransf, RefEnt->GetOGLList( OGLTransf ), false, true, false, true );
	delete pBrep;

	delete reverseSubd;

	return true;
}

//---------------------------------------------------------------------------
// Creación de un barrido por 2 carriles
bool TPBrepData::CreateLowPolyTwoRailsSweep( TOGLTransf *OGLTransf, TMeshPrimitiveParams *params )
{
	int i, j, nPointsRail, nPointsForm;
	TOGLPolygonList revolveCoarseSections;
	T3DPoint pt3d, pt3d_prev_1, pt3d_prev_2, pt3d_prev_3, pt3d_post_1, pt3d_post_2, pt3d_post_3, pt3d_aux;
	IwPolyBrep *pBrep;
	IwPolyRegion *pRegion;
	IwPolyShell *pShell;
	IwPoint3d iwPoint;
	IwPolyVertex *iwVertex, *iwVertex1, *iwVertex2, *iwVertex3, *iwVertex4;
	IwPolyFace *iwFace;
	IwTA<IwPolyVertex *> iwVertexs;
	IwTA<IwTA<IwPolyVertex *> > iwVertexsAll;
	IwTA<IwPolyEdge *> iwEdgesFace;
	TReverseSubdivision *reverseSubd;

	if ( !OGLTransf || !params || !params->TwoRailsSweepRail1Crv || !ToShape( params->TwoRailsSweepRail1Crv ) || !params->TwoRailsSweepRail2Crv || !ToShape( params->TwoRailsSweepRail2Crv ) || !params->TwoRailsSweepFormCrv || !ToShape( params->TwoRailsSweepFormCrv ) || !params->IsValid( LPM_CREATIONTYPE_TWO_RAILS_SWEEP ) ) return false;

	// Obtenemos los coarse points de la curva de forma por subdivisión inversa
	reverseSubd = new TReverseSubdivision( OGLTransf, ST_TWO_RAILS_SWEEP, params );
	if ( !reverseSubd->GetReverseSubdivisionSISL( &revolveCoarseSections ) ) {
		delete reverseSubd;
		return false;
	}

	// Creamos pbRep
	pBrep = new IwPolyBrep( _GetSMLib( )->GetContext( ), RES_COMP );
	if ( !pBrep ) {
		delete reverseSubd;
		return false;
	}
	pRegion = new IwPolyRegion( _GetSMLib( )->GetContext( ), pBrep );
	if ( !pRegion ) {
		_GetSMLib( )->DestroyIwPolyBrep( pBrep );
		pBrep = 0;
		delete reverseSubd;
		return false;
	}
	pShell = new IwPolyShell( _GetSMLib( )->GetContext( ), *pBrep, pRegion );
	if ( !pShell ) {
		_GetSMLib( )->DestroyIwPolyBrep( pBrep );
		pBrep = 0;
		pRegion = 0;
		delete reverseSubd;
		return false;
	}

	// Creamos los vértices
	nPointsRail = revolveCoarseSections.Count( );
	nPointsForm = revolveCoarseSections.GetItem( 0 )->Count( );
	for ( i = 0; i < nPointsRail; i++ ) {
		iwVertexs.RemoveAll( );
		for ( j = 0; j < nPointsForm; j++ ) {
			if ( reverseSubd->GetClosed_V_First( ) && j == 0 && i > 0 ) // Si es una curva abierta y se cierra en el primer punto, sólo lo creamos una vez
				iwVertexs.Add( iwVertexsAll.GetAt( 0 ).GetAt( 0 ) );
			else if ( reverseSubd->GetClosed_V_Last( ) && j == ( nPointsForm - 1 ) && i > 0 ) // Si es una curva abierta y se cierra en el último punto, sólo lo creamos una vez
				iwVertexs.Add( iwVertexsAll.GetAt( 0 ).GetAt( nPointsForm - 1 ) );
			else {
				pt3d = revolveCoarseSections.GetItem( i )->GetItem( j )->v.GetPoint( );
				iwPoint = IwPoint3d( pt3d.x, pt3d.y, pt3d.z );
				iwVertex = new IwPolyVertex( _GetSMLib( )->GetContext( ), *PBrep, iwPoint, RES_COMP );
				iwVertexs.Add( iwVertex );
			}
		}
		iwVertexsAll.Add( iwVertexs );
	}

	// Creamos las caras
	for ( i = 0; i < ( nPointsRail - 1 ); i++ ) {
		for ( j = 0; j < ( nPointsForm - 1 ); j++ ) {
			if ( reverseSubd->GetClosed_V_First( ) && j == 0 ) {
				iwVertex1 = iwVertexsAll.GetAt( i ).GetAt( j );
				iwVertex2 = iwVertexsAll.GetAt( i + 1 ).GetAt( j + 1 );
				iwVertex3 = iwVertexsAll.GetAt( i ).GetAt( j + 1 );
				pBrep->CreatePolyTriangle( pRegion, pShell, iwVertex1, iwVertex2, iwVertex3, iwFace );
			} else if ( reverseSubd->GetClosed_V_Last( ) && j == ( nPointsForm - 2 ) ) {
				iwVertex1 = iwVertexsAll.GetAt( i ).GetAt( j );
				iwVertex2 = iwVertexsAll.GetAt( i + 1 ).GetAt( j );
				iwVertex3 = iwVertexsAll.GetAt( i ).GetAt( j + 1 );
				pBrep->CreatePolyTriangle( pRegion, pShell, iwVertex1, iwVertex2, iwVertex3, iwFace );
			} else {
				iwVertex1 = iwVertexsAll.GetAt( i ).GetAt( j );
				iwVertex2 = iwVertexsAll.GetAt( i + 1 ).GetAt( j );
				iwVertex3 = iwVertexsAll.GetAt( i + 1 ).GetAt( j + 1 );
				iwVertex4 = iwVertexsAll.GetAt( i ).GetAt( j + 1 );
				pBrep->CreatePolyQuad( pRegion, pShell, iwVertex1, iwVertex2, iwVertex3, iwVertex4, iwFace );
			}

			iwFace->GetPolyEdges( iwEdgesFace );
			if ( reverseSubd->IsCornerRail1( i ) && reverseSubd->IsCornerRail2( i ) ) AddCreaseEdges( OGLTransf, iwEdgesFace.GetAt( 3 ), 1.0, false, false, SelectedElementType::AllSelected, false );
			if ( !reverseSubd->GetClosed_H( ) && i == ( nPointsRail - 2 ) && reverseSubd->IsCornerRail1( nPointsRail - 1 ) && reverseSubd->IsCornerRail2( nPointsRail - 1 ) ) AddCreaseEdges( OGLTransf, iwEdgesFace.GetAt( 1 ), 1.0, false, false, SelectedElementType::AllSelected, false );
			if ( reverseSubd->IsCornerForm( j ) ) AddCreaseEdges( OGLTransf, iwEdgesFace.GetAt( 0 ), 1.0, false, false, SelectedElementType::AllSelected, false );
			if ( !reverseSubd->GetClosed_V( ) && j == ( nPointsForm - 2 ) && reverseSubd->IsCornerForm( nPointsForm - 1 ) ) AddCreaseEdges( OGLTransf, iwEdgesFace.GetAt( 2 ), 1.0, false, false, SelectedElementType::AllSelected, false );
		}
	}
	if ( reverseSubd->GetClosed_V( ) ) {
		for ( i = 0; i < ( nPointsRail - 1 ); i++ ) {
			iwVertex1 = iwVertexsAll.GetAt( i ).GetAt( nPointsForm - 1 );
			iwVertex2 = iwVertexsAll.GetAt( i + 1 ).GetAt( nPointsForm - 1 );
			iwVertex3 = iwVertexsAll.GetAt( i + 1 ).GetAt( 0 );
			iwVertex4 = iwVertexsAll.GetAt( i ).GetAt( 0 );
			pBrep->CreatePolyQuad( pRegion, pShell, iwVertex1, iwVertex2, iwVertex3, iwVertex4, iwFace );

			iwFace->GetPolyEdges( iwEdgesFace );
			if ( reverseSubd->IsCornerForm( nPointsForm - 1 ) ) AddCreaseEdges( OGLTransf, iwEdgesFace.GetAt( 0 ), 1.0, false, false, SelectedElementType::AllSelected, false );
			if ( reverseSubd->IsCornerForm( 0 ) ) AddCreaseEdges( OGLTransf, iwEdgesFace.GetAt( 2 ), 1.0, false, false, SelectedElementType::AllSelected, false );
		}
	}
	if ( reverseSubd->GetClosed_H( ) ) {
		for ( j = 0; j < ( nPointsForm - 1 ); j++ ) {
			if ( reverseSubd->GetClosed_V_First( ) && j == 0 ) {
				iwVertex1 = iwVertexsAll.GetAt( 0 ).GetAt( j );
				iwVertex2 = iwVertexsAll.GetAt( 0 ).GetAt( j + 1 );
				iwVertex3 = iwVertexsAll.GetAt( nPointsRail - 1 ).GetAt( j + 1 );
				pBrep->CreatePolyTriangle( pRegion, pShell, iwVertex1, iwVertex2, iwVertex3, iwFace );
			} else if ( reverseSubd->GetClosed_V_Last( ) && j == ( nPointsForm - 2 ) ) {
				iwVertex1 = iwVertexsAll.GetAt( 0 ).GetAt( j );
				iwVertex2 = iwVertexsAll.GetAt( 0 ).GetAt( j + 1 );
				iwVertex3 = iwVertexsAll.GetAt( nPointsRail - 1 ).GetAt( j );
				pBrep->CreatePolyTriangle( pRegion, pShell, iwVertex1, iwVertex2, iwVertex3, iwFace );
			} else {
				iwVertex1 = iwVertexsAll.GetAt( nPointsRail - 1 ).GetAt( j );
				iwVertex2 = iwVertexsAll.GetAt( 0 ).GetAt( j );
				iwVertex3 = iwVertexsAll.GetAt( 0 ).GetAt( j + 1 );
				iwVertex4 = iwVertexsAll.GetAt( nPointsRail - 1 ).GetAt( j + 1 );
				pBrep->CreatePolyQuad( pRegion, pShell, iwVertex1, iwVertex2, iwVertex3, iwVertex4, iwFace );
			}

			iwFace->GetPolyEdges( iwEdgesFace );
			if ( reverseSubd->IsCornerRail1( nPointsRail - 1 ) && reverseSubd->IsCornerRail2( nPointsRail - 1 ) ) AddCreaseEdges( OGLTransf, iwEdgesFace.GetAt( 3 ), 1.0, false, false, SelectedElementType::AllSelected, false );
			if ( reverseSubd->IsCornerRail1( 0 ) && reverseSubd->IsCornerRail2( 0 ) ) AddCreaseEdges( OGLTransf, iwEdgesFace.GetAt( 1 ), 1.0, false, false, SelectedElementType::AllSelected, false );
		}
		if ( reverseSubd->GetClosed_V( ) ) {
			iwVertex1 = iwVertexsAll.GetAt( nPointsRail - 1 ).GetAt( nPointsForm - 1 );
			iwVertex2 = iwVertexsAll.GetAt( 0 ).GetAt( nPointsForm - 1 );
			iwVertex3 = iwVertexsAll.GetAt( 0 ).GetAt( 0 );
			iwVertex4 = iwVertexsAll.GetAt( nPointsRail - 1 ).GetAt( 0 );
			pBrep->CreatePolyQuad( pRegion, pShell, iwVertex1, iwVertex2, iwVertex3, iwVertex4, iwFace );

			iwFace->GetPolyEdges( iwEdgesFace );
			if ( reverseSubd->IsCornerForm( nPointsForm - 2 ) ) AddCreaseEdges( OGLTransf, iwEdgesFace.GetAt( 0 ), 1.0, false, false, SelectedElementType::AllSelected, false );
			if ( reverseSubd->IsCornerForm( nPointsForm - 1 ) ) AddCreaseEdges( OGLTransf, iwEdgesFace.GetAt( 2 ), 1.0, false, false, SelectedElementType::AllSelected, false );
		}
	}

	// Copiamos la pBrep
	CopyPBrep( pBrep );

	UpdateOGLListFromPBrep( OGLTransf, RefEnt->GetOGLList( OGLTransf ), false, true, false, true );
	delete pBrep;

	delete reverseSubd;

	return true;
}

//------------------------------------------------------------------------------

bool TPBrepData::CollapseVertexs( TOGLTransf *OGLTransf, IwPolyVertex *vertexStart, IwPolyVertex *vertexEnd )
{
	int i, j, k, index1, isseam;
	double area, vol;
	float valcrease;
	bool success, doanother, vertexsconnected;
	IwPoint3d pt, deltaBarycenter;
	IwVector3d deltaMoments[ 2 ];
	ULONG ulIndex;
	IwTA<int> isSeam;
	IwTA<double> valCrease;
	IwPolyVertex *vs, *ve;
	IwPolyEdge *e, *eAux;
	IwPolyFace *face, *face2, *faceAux;
	IwTA<IwPolyVertex *> vertexsI, vertexsE;
	IwTA<IwPolyEdge *> edges;
	IwTA<IwPolyFace *> facesToRemoveVertex, facesToReplaceVertex, allFaces, disolveFaces, facesOld, facesAuxList, deleteFaces, facesNoArea, facestotest;
	IwTA<IwTA<IwPolyFace *> > iwFacesToDisolve, facesR, facesRAux;

	if ( !OGLTransf || !vertexStart || !vertexEnd || vertexStart == vertexEnd ) return false;

	vertexsconnected = false;
	vertexStart->GetPolyEdges( edges );
	for ( i = 0; i < (int) edges.GetSize( ); i++ ) {
		e = edges[ i ];
		if ( !e ) continue;
		if ( e->GetStartVertex( ) == vertexEnd || e->GetEndVertex( ) == vertexEnd ) {
			vertexsconnected = true;
			break;
		}
	}

	isSeam.RemoveAll( );
	valCrease.RemoveAll( );
	InitUserIndex2( false, false, true );
	if ( vertexsconnected ) {
		facesOld = GetConnectedFacesFromVertex( vertexStart );
		if ( facesOld.GetSize( ) <= 0 ) return false;
		facesToRemoveVertex = GetCommonFacesBetweenVertexs( vertexStart, vertexEnd );
		if ( facesToRemoveVertex.GetSize( ) <= 0 ) return false;

		for ( i = 0; i < (int) facesOld.GetSize( ); i++ ) {
			face = facesOld[ i ];
			if ( !facesToRemoveVertex.FindElement( face, ulIndex ) ) facesToReplaceVertex.Add( face );
		}

		// Información de pliegues y costuras.
		SaveCreaseAndSeamsValuesFromCollapseVertexs( &facesToReplaceVertex, &facesToRemoveVertex, vertexStart, vertexEnd, &vertexsI, &vertexsE, &isSeam, &valCrease );

		// Caras ordenadas en un sentido horario o antihorario a partir de la arista por la que se desplaza.
		InitUserIndex1( );
		index1 = 1; // Marca userIndex1 para ordenar caras.
		for ( i = 0; i < (int) facesToRemoveVertex.GetSize( ); i++ ) {
			face = facesToRemoveVertex[ i ];
			if ( ( ( (int) facesToRemoveVertex.GetSize( ) - 1 ) == i ) && facesToRemoveVertex.GetSize( ) > 1 ) index1 += 1;
			face->SetUserIndex1( index1 );
			for ( j = 0; j < (int) facesToReplaceVertex.GetSize( ); j++ ) {
				faceAux = facesToReplaceVertex[ j ];
				if ( AreAdjacentFaces( face, faceAux ) && faceAux->GetUserIndex1( ) == 0 ) {
					index1 += 1;
					faceAux->SetUserIndex1( index1 );
					face = faceAux;
					j = -1;
				}
			}
		}

		// Se crea las nuevas caras, dependiendo el grupo de caras al que se va a modificar, si es para eliminar vértices o para reemplazar vértices.
		if ( ( !FacesToReplaceVertex( OGLTransf, vertexStart, vertexEnd, &facesToReplaceVertex, &facesR ) ) && facesToReplaceVertex.GetSize( ) > 0 ) return false;
		FacesToRemoveVertex( OGLTransf, vertexStart, vertexEnd, &facesToRemoveVertex, &facesR );
	} else { // Caso para vértices NO conectados por una arista ( SOLO BORDES )
		if ( !vertexStart->IsBoundaryVertex( ) || !vertexEnd->IsBoundaryVertex( ) ) return false;
		facesOld = GetConnectedFacesFromVertex( vertexStart );
		facesToRemoveVertex = GetConnectedFacesFromVertex( vertexEnd );

		// Información de pliegues y costuras.
		SaveCreaseAndSeamsValuesFromCollapseVertexs( &facesOld, &facesToRemoveVertex, vertexStart, vertexEnd, &vertexsI, &vertexsE, &isSeam, &valCrease );

		// Se crean nuevas caras.
		FacesToReplaceVertex( OGLTransf, vertexStart, vertexEnd, &facesOld, &facesR, true );
	}
	// se ordena la lista de caras nueva a partir de los user index1
	allFaces.RemoveAll( );
	for ( i = 1; i <= (int) facesR.GetSize( ); i++ ) {
		facesAuxList = facesR[ i - 1 ];
		for ( j = 0; j < (int) facesAuxList.GetSize( ); j++ )
			allFaces.Add( facesAuxList[ j ] );
	}
	for ( i = 1; i < (int) allFaces.GetSize( ); i++ ) {
		faceAux = allFaces[ i ];
		index1 = faceAux->GetUserIndex1( );
		j = i - 1;
		while ( ( ( (int) allFaces[ j ]->GetUserIndex1( ) ) > index1 ) && ( j >= 0 ) ) {
			allFaces[ j + 1 ] = allFaces[ j ];
			j--;
		}
		allFaces[ j + 1 ] = faceAux;
	}

	facesAuxList.RemoveAll( );
	disolveFaces.RemoveAll( );
	iwFacesToDisolve.RemoveAll( );

	// Caras con area que no cumplen la tolerancia.
	for ( i = 0; i < (int) allFaces.GetSize( ); i++ ) {
		face = allFaces[ i ];
		face->ComputeProperties( pt, area, vol, deltaBarycenter, deltaMoments, IW_MPT_AREA );
		if ( area <= MIN_AREA_MESH_FACE && face->GetUserIndex2( ) != 1 ) facesNoArea.Add( face );
	}

	// Grupos de caras adyacentes que no cumplen tolerancia y marcar UserIndex2 a 1
	InitUserIndex2( false, false, true );
	for ( i = 0; i < (int) facesNoArea.GetSize( ); i++ ) {
		face = facesNoArea[ i ];
		if ( face->GetUserIndex2( ) == 1 ) continue;
		face->SetUserIndex2( 1 );
		disolveFaces.Add( face );
		do {
			doanother = false;
			for ( j = 0; j < (int) facesNoArea.GetSize( ); j++ ) {
				face2 = facesNoArea[ j ];
				if ( face2->GetUserIndex2( ) == 1 ) continue;
				if ( AreAdjacentFaces( face, face2 ) ) {
					face2->SetUserIndex2( 1 );
					facestotest.Add( face2 );
					disolveFaces.Add( face2 );
				}
			}
			// Comprobamos con las nuevas caras añadidas
			if ( facestotest.GetSize( ) ) {
				face = facestotest[ facestotest.GetSize( ) - 1 ];
				facestotest.RemoveAt( facestotest.GetSize( ) - 1 );
				doanother = true;
			}
		} while ( doanother );
		iwFacesToDisolve.Add( disolveFaces );
		disolveFaces.RemoveAll( );
	}

	// Grupos de caras que no cumplen tolerancia junto con una adyacente que si cumple tolerancia.
	facesR.RemoveAll( );
	facestotest.RemoveAll( );
	for ( i = 0; i < (int) allFaces.GetSize( ); i++ ) {
		success = false;
		face = allFaces[ i ];
		if ( face->GetUserIndex2( ) == 1 ) continue;
		if ( success ) i = -1;
		for ( j = 0; j < (int) iwFacesToDisolve.GetSize( ); j++ ) {
			if ( success ) i = -1;
			disolveFaces = iwFacesToDisolve[ j ];
			success = false;
			faceAux = 0;
			for ( k = 0; k < (int) disolveFaces.GetSize( ); k++ ) {
				face2 = disolveFaces[ k ];
				if ( AreAdjacentFaces( face, face2 ) ) {
					disolveFaces.Add( face );
					facesR.Add( disolveFaces );
					disolveFaces.RemoveAll( );
					iwFacesToDisolve.RemoveAt( j );
					success = true;
					break;
				}
			}
		}
	}

	// unificación de grupos de caras sin area que comparten una cara con area.
	for ( i = 0; i < (int) allFaces.GetSize( ); i++ ) {
		face = allFaces[ i ];
		for ( j = 0; j < (int) facesR.GetSize( ); j++ ) {
			facesAuxList = facesR[ j ];
			if ( facesAuxList.FindElement( face, ulIndex ) ) {
				facesRAux.Add( facesAuxList );
			}
		}
		if ( facesRAux.GetSize( ) > 1 ) {
			for ( j = 0; j < (int) facesRAux.GetSize( ); j++ ) {
				facesAuxList = facesRAux[ j ];
				for ( k = 0; k < (int) facesAuxList.GetSize( ); k++ )
					disolveFaces.AddUnique( facesAuxList[ k ] );
				for ( k = 0; k < (int) facesR.GetSize( ); k++ ) {
					facestotest = facesR[ k ];
					facestotest.FindCommonElements( facesAuxList, deleteFaces );
					if ( (int) deleteFaces.GetSize( ) == (int) facestotest.GetSize( ) && (int) deleteFaces.GetSize( ) == (int) facesAuxList.GetSize( ) ) facesR.RemoveAt( k );
				}
			}
			facesR.Add( disolveFaces );
			disolveFaces.RemoveAll( );
			deleteFaces.RemoveAll( );
		}
		facesRAux.RemoveAll( );
	}

	// Caras a eliminar porque no encontró adyacente
	deleteFaces.RemoveAll( );
	for ( i = 0; i < (int) iwFacesToDisolve.GetSize( ); i++ ) {
		facesAuxList = iwFacesToDisolve[ i ];
		for ( j = 0; j < (int) facesAuxList.GetSize( ); j++ ) {
			deleteFaces.Add( facesAuxList[ j ] );
		}
	}

	// Se unifican las caras chafadas y agrupadas.
	for ( i = 0; i < (int) facesR.GetSize( ); i++ ) {
		DisolveFaces( OGLTransf, &facesR[ i ], -1, 0, false );
	}

	RemoveFaces( OGLTransf, &facesOld, false );
	RemoveFaces( OGLTransf, &deleteFaces, false );

	// Se recuperan pliegues/costuras de aristas
	InitUserIndex2( false, true, false );
	for ( i = 0; i < (int) vertexsI.GetSize( ); i++ ) {
		vs = vertexsI[ i ];
		ve = vertexsE[ i ];
		valcrease = valCrease[ i ];
		isseam = isSeam[ i ];
		if ( !vs && !ve ) continue;
		if ( !vs ) ve->FindPolyEdgeBetween( vertexEnd, eAux );
		else if ( !ve )
			vs->FindPolyEdgeBetween( vertexEnd, eAux );
		else
			vs->FindPolyEdgeBetween( ve, eAux );

		if ( !eAux ) continue;
		if ( eAux->GetUserIndex1( ) == ULONG_MAX ) eAux = eAux->GetSymmetricPolyEdge( );
		AddCreaseEdges( OGLTransf, eAux, valcrease, false, false );
		if ( isseam == 1 ) AddSeamEdge( eAux );
	}

	InitUserIndex1( );
	InitUserIndex2( );
	UpdateTopology( OGLTransf );
	SelectVertex( OGLTransf, vertexEnd->GetIndexExt( ), SelectedElementType::LastUserSelection );

	return true;
}

//---------------------------------------------------------------------------
// Creación de un sólido a partir de un conjunto de caras seleccionadas
bool TPBrepData::Solidify( TOGLTransf *OGLTransf, float incrX, float incrY, float incrZ, int bordertype, int indexFace, int sign, bool createFaces, bool updateOGLList )
{
	bool ret;
	int i, ind;
	IwTA<IwPolyEdge *> boundaryedges;
	IwTA<IwPolyFace *> newfaces, facesorg;
	float thickness;
	T3DPoint incr;
	T3DVector v;
	TInteger_List indexes;

	incr = T3DPoint( incrX, incrY, incrZ );
	v = T3DVector( T3DSize( incr ) );
	thickness = v.Modulo( );
	if ( thickness < RES_COMP ) return false;

	if ( createFaces ) {
		if ( indexFace != -1 ) GetIsolatedFaces( OGLTransf, indexFace, &facesorg, &boundaryedges );

		DuplicateFaces( OGLTransf, &newfaces, &boundaryedges, &facesorg );

		if ( bordertype == BORDERTYPE_STRAIGHT || bordertype == BORDERTYPE_HALFROUNDED ) { // BORDERTYPE_STRAIGHT, BORDERTYPE_ROUNDED, BORDERTYPE_HALFROUNDED, BORDERTYPE_HALFROUNDED_INV
			for ( i = 0; i < (int) boundaryedges.GetSize( ); i++ )
				AddCreaseEdges( OGLTransf, boundaryedges[ i ], 1.0, false, false, SelectedElementType::AllSelected, false );
			UpdatePBrepCreases( OGLTransf, true, false );
		}

		for ( i = 0; i < (int) newfaces.GetSize( ); i++ ) {
			ind = newfaces[ i ]->GetIndexExt( );
			indexes.AddItem( &ind );
		}

		SelectFaces( OGLTransf, &indexes );
	}

	ret = ExtrudeSelectedFaces( OGLTransf, incrX, incrY, incrZ, TExtrudeType::Solidify, sign, createFaces, updateOGLList, bordertype == BORDERTYPE_STRAIGHT || bordertype == BORDERTYPE_HALFROUNDED_INV, 1.0 );

	if ( updateOGLList && RefEnt ) RefEnt->UpdateOGLListFromPBrep( OGLTransf, true );

	return ret;
}

//---------------------------------------------------------------------------

void TPBrepData::ReverseOrientation( TOGLTransf *OGLTransf, bool onlygroupbyselection )
{
	int size, i, index;
	IwTA<IwPolyEdge *> edgesboundary;
	IwTA<IwPolyFace *> faces;

	size = (int) PBrepFaces.GetSize( );
	if ( onlygroupbyselection ) {
		for ( i = 0; i < size; i++ )
			if ( SelectedF[ i ].i > 0 ) break;
		index = i;
		if ( index >= size ) return;
		GetIsolatedFaces( OGLTransf, index, &faces, &edgesboundary );
		size = faces.GetSize( );
		for ( i = 0; i < size; i++ )
			faces.GetAt( i )->ReverseOrientation( );
	} else
		for ( i = 0; i < size; i++ )
			PBrepFaces.GetAt( i )->ReverseOrientation( );

	UpdateTopology( OGLTransf );
}

// =============================================================================
// TPBrepData - Creación malla a partir de curvas
// =============================================================================
// Se crea una malla a partir de una curva cerrada
bool TPBrepData::CreateMeshFromCurves( TOGLTransf *OGLTransf, TPBrepFromCurvesData *curveData, TMeshFromCurvesParams *curveParams )
{
	int i, nEdges;
	IwPolyBrep *pBrep;
	IwPolyEdge *iwEdge;
	IwTA<IwPolyEdge *> iwCreaseEdges, iwEdges;
	TPBrepFromCurves *pBrepFromCurves;

	if ( !OGLTransf || !curveData || !curveParams ) return false;
	if ( !curveParams->IsValid( curveData->GetPBrepType( ) ) ) return false;
	if ( !curveData->GetFirstCurve( ) || !curveData->GetLastCurve( ) ) return false;

	pBrep = 0;
	try {
		pBrepFromCurves = new TPBrepFromCurves( OGLTransf, curveData, curveParams );
		pBrep = pBrepFromCurves->CreatePBrepFromCurves( );
		delete pBrepFromCurves;

		if ( !pBrep ) return false;
		if ( !CopyPBrep( pBrep ) ) return false;

		// Marcamos las aristas de pliegues si es necesario
		PBrep->GetPolyEdges( iwEdges );
		nEdges = (int) iwEdges.GetSize( );
		for ( i = 0; i < nEdges; i++ ) {
			iwEdge = iwEdges.GetAt( i );
			if ( iwEdge->GetUserFloat1( ) > 0.0 && iwEdge->GetUserIndex1( ) != ULONG_MAX ) iwCreaseEdges.Add( iwEdge );
		}
		nEdges = (int) iwCreaseEdges.GetSize( );
		for ( i = 0; i < nEdges; i++ ) {
			iwEdge = iwCreaseEdges.GetAt( i );
			AddCreaseEdges( OGLTransf, iwEdge, iwEdge->GetUserFloat1( ), false, false );
		}

		UpdateOGLListFromPBrep( OGLTransf, RefEnt->GetOGLList( OGLTransf ), false, true, false, true );

	} __finally {
		_GetSMLib( )->DestroyIwPolyBrep( pBrep );
	}

	return true;
}

//------------------------------------------------------------------------------
// Se hace una reconstrucción de la LowPoly eliminando triángulos.
// Se unifican triángulos coplanares y los que quedan se convierten a quads
void TPBrepData::ReconstructLowPoly( TOGLTransf *OGLTransf, bool tryUnify, double angleTolerance )
{
	ULONG pos;
	int i, j, k, nFaces, nEdges;
	IwPoint3d iwCentroid, iwPointEdge0, iwPointEdge1, iwPointEdge2;
	IwVector3d iwNormalFace, iwNormalSimetricFace;
	IwPolyVertex *iwVertexCentroid, *iwVertexEdge0, *iwVertexEdge1, *iwVertexEdge2;
	IwPolyEdge *iwSymmetricEdge;
	IwPolyFace *iwFace, *iwSymmetricFace, *newFace;
	IwTA<IwPolyRegion *> regions;
	IwTA<IwPolyShell *> shells;
	IwTA<IwPolyVertex *> iwVertexsAdded;
	IwTA<IwPolyEdge *> iwEdgesFace;
	IwTA<IwPolyFace *> iwFaces, iwCoplanarFaces, iwReviewedFaces;

	if ( !PBrep || !OGLTransf ) return;
	PBrep->GetPolyRegions( regions );
	PBrep->GetPolyShells( shells );
	if ( regions.GetSize( ) == 0 || shells.GetSize( ) == 0 ) return;

	// Unificamos los triangulos contiguos coplanares con tolerancia 'angleTolerance'
	PBrep->GetPolyFaces( iwFaces );
	nFaces = (int) iwFaces.GetSize( );
	if ( tryUnify && angleTolerance >= 0.0 ) {
		while ( angleTolerance > 360 )
			angleTolerance -= 360;
		for ( i = 0; i < nFaces; i++ ) {
			iwFace = iwFaces.GetAt( i );
			if ( iwFace->IsTriangle( ) ) {
				if ( iwReviewedFaces.FindElement( iwFace, pos ) ) continue;
				iwReviewedFaces.AddUnique( iwFace );
				iwCoplanarFaces.Add( iwFace );
				j = 0;
				while ( j < (int) iwCoplanarFaces.GetSize( ) ) {
					iwFace = iwCoplanarFaces.GetAt( j );
					iwFace->GetPolyEdges( iwEdgesFace );
					nEdges = iwEdgesFace.GetSize( );
					iwNormalFace = iwFace->GetNormal( );
					for ( k = 0; k < nEdges; k++ ) {
						iwSymmetricEdge = iwEdgesFace.GetAt( k )->GetSymmetricPolyEdge( );
						iwSymmetricFace = iwSymmetricEdge ? iwSymmetricEdge->GetPolyFace( ) : 0;
						if ( iwSymmetricFace ) {
							if ( iwReviewedFaces.FindElement( iwSymmetricFace, pos ) || !iwSymmetricFace->IsTriangle( ) ) continue;
							iwNormalSimetricFace = iwSymmetricFace->GetNormal( );
							if ( iwNormalFace.IsParallelTo( iwNormalSimetricFace, angleTolerance * M_PI_180 ) ) {
								iwReviewedFaces.AddUnique( iwSymmetricFace );
								iwCoplanarFaces.AddUnique( iwSymmetricFace );
							}
						}
					}
					j++;
				}
				if ( iwCoplanarFaces.GetSize( ) > 1 ) {
					RemoveFaces( OGLTransf, &iwCoplanarFaces );
					FillHoles( );
					PBrep->GetPolyFaces( iwFaces );
					nFaces = (int) iwFaces.GetSize( );
					i = -1;
				}
				iwCoplanarFaces.RemoveAll( );
				iwReviewedFaces.RemoveAll( );
			}
		}
	}

	// Los triángulos que quedan se dividen convirtiéndolos en quads.
	PBrep->GetPolyFaces( iwFaces );
	nFaces = (int) iwFaces.GetSize( );
	for ( i = 0; i < nFaces; i++ ) {
		iwFace = iwFaces.GetAt( i );
		if ( iwFace->IsTriangle( ) ) {
			iwReviewedFaces.AddUnique( iwFace );
			iwCentroid = iwFace->GetCentroid( );
			iwFace->GetPolyEdges( iwEdgesFace );
			iwPointEdge0 = ( iwEdgesFace.GetAt( 0 )->GetStartPoint( ) + iwEdgesFace.GetAt( 0 )->GetEndPoint( ) ) / 2.0;
			iwPointEdge1 = ( iwEdgesFace.GetAt( 1 )->GetStartPoint( ) + iwEdgesFace.GetAt( 1 )->GetEndPoint( ) ) / 2.0;
			iwPointEdge2 = ( iwEdgesFace.GetAt( 2 )->GetStartPoint( ) + iwEdgesFace.GetAt( 2 )->GetEndPoint( ) ) / 2.0;

			iwVertexCentroid = new IwPolyVertex( _GetSMLib( )->GetContext( ), *PBrep, iwCentroid, RES_COMP );
			iwVertexEdge0 = FindVertex( &iwVertexsAdded, &iwPointEdge0, pos );
			if ( !iwVertexEdge0 ) {
				iwVertexEdge0 = new IwPolyVertex( _GetSMLib( )->GetContext( ), *PBrep, iwPointEdge0, RES_COMP );
				iwVertexsAdded.Add( iwVertexEdge0 );
			}
			iwVertexEdge1 = FindVertex( &iwVertexsAdded, &iwPointEdge1, pos );
			if ( !iwVertexEdge1 ) {
				iwVertexEdge1 = new IwPolyVertex( _GetSMLib( )->GetContext( ), *PBrep, iwPointEdge1, RES_COMP );
				iwVertexsAdded.Add( iwVertexEdge1 );
			}
			iwVertexEdge2 = FindVertex( &iwVertexsAdded, &iwPointEdge2, pos );
			if ( !iwVertexEdge2 ) {
				iwVertexEdge2 = new IwPolyVertex( _GetSMLib( )->GetContext( ), *PBrep, iwPointEdge2, RES_COMP );
				iwVertexsAdded.Add( iwVertexEdge2 );
			}

			// Dividimos la cara
			PBrep->CreatePolyQuad( regions.GetAt( 0 ), shells.GetAt( 0 ), iwVertexEdge0, iwEdgesFace.GetAt( 0 )->GetEndVertex( ), iwVertexEdge1, iwVertexCentroid, newFace );
			PBrep->CreatePolyQuad( regions.GetAt( 0 ), shells.GetAt( 0 ), iwVertexEdge1, iwEdgesFace.GetAt( 1 )->GetEndVertex( ), iwVertexEdge2, iwVertexCentroid, newFace );
			PBrep->CreatePolyQuad( regions.GetAt( 0 ), shells.GetAt( 0 ), iwVertexEdge2, iwEdgesFace.GetAt( 2 )->GetEndVertex( ), iwVertexEdge0, iwVertexCentroid, newFace );

			// Dividimos sus caras adyacentes si no son triangulos
			for ( j = 0; j < 3; j++ ) {
				iwSymmetricEdge = iwEdgesFace.GetAt( j )->GetSymmetricPolyEdge( );
				iwSymmetricFace = iwSymmetricEdge ? iwSymmetricEdge->GetPolyFace( ) : 0;
				if ( iwSymmetricFace && !iwSymmetricFace->IsTriangle( ) ) SplitFace( OGLTransf, iwSymmetricFace, iwSymmetricEdge, j == 0 ? iwVertexEdge0 : j == 1 ? iwVertexEdge1 : iwVertexEdge2, NULL, false );
			}

			// Borramos la cara
			PBrep->DeletePolyFace( iwFace );

			PBrep->GetPolyFaces( iwFaces );
			nFaces = (int) iwFaces.GetSize( );
			i = -1;
		}
	}

	UpdateTopology( OGLTransf );
}

//------------------------------------------------------------------------------
// Se exporta la Low Poly a una archivo obj, sin triangular
void TPBrepData::ExportLowPolyToObj( UnicodeString file, int nDecimals )
{
	if ( !PBrep ) return;

	PBrep->WriteToOBJFile( file.c_str( ), false, nDecimals );
}

//------------------------------------------------------------------------------

TOGLPoint *TPBrepData::GetSubdivisionCentroidFromVertex( TOGLTransf *OGLTransf, IwPolyVertex *vertex, T3DVector *normal )
{
	int i, j, index, nVertexs, nFaces, value;
	double distance;
	T3DPoint pt3d;
	TOGLPolygon *polVertexs, *polfaces;
	TSubdivisionData *subdivisiondata;

	if ( !vertex || !RefEnt || !ToMesh( RefEnt ) || !ToMesh( RefEnt )->HasSubdivisionDepMesh( ) ) return 0;
	subdivisiondata = 0;
	if ( ToMesh( RefEnt )->HasSubdivisionDepMesh( ) ) subdivisiondata = ToDepMesh( ToMesh( RefEnt )->GetDepMeshes( )->GetShape( 0 ) )->GetSubdivisionData( );

	if ( !IsTopologyDirty( ) ) {
		polfaces = 0;
		if ( normal ) {
			polfaces = ToDepMesh( RefEnt->GetDepMeshes( )->GetShape( 0 ) )->GetSubdivisionFaces( OGLTransf );
			( *normal ) = T3DVector( );
		}
		polVertexs = ToDepMesh( RefEnt->GetDepMeshes( )->GetShape( 0 ) )->GetSubdivisionVertexs( OGLTransf );
		if ( polVertexs ) {
			nVertexs = polVertexs->Count( );
			index = vertex->GetIndexExt( );
			for ( i = 0; i < nVertexs; i++ ) {
				if ( (int) polVertexs->GetItem( i )->t.v[ 0 ] == index ) {
					if ( polfaces && normal ) {
						if ( !subdivisiondata || subdivisiondata->ForceTriangles ) value = 3;
						else
							value = 4;
						nFaces = polfaces->Count( ) / value;
						for ( j = 0; j < nFaces; j++ ) {
							distance = polfaces->GetItem( j * value )->v.DistanceSqr( &polVertexs->GetItem( i )->v );
							if ( distance <= RES_GEOM ) {
								( *normal ) = ( *normal ) + T3DSize( polfaces->GetItem( j * value )->n.GetPoint( ) );
								continue;
							}
							distance = polfaces->GetItem( j * value + 1 )->v.DistanceSqr( &polVertexs->GetItem( i )->v );
							if ( distance <= RES_GEOM ) {
								( *normal ) = ( *normal ) + T3DSize( polfaces->GetItem( j * value + 1 )->n.GetPoint( ) );
								continue;
							}
							distance = polfaces->GetItem( j * value + 2 )->v.DistanceSqr( &polVertexs->GetItem( i )->v );
							if ( distance <= RES_GEOM ) {
								( *normal ) = ( *normal ) + T3DSize( polfaces->GetItem( j * value + 2 )->n.GetPoint( ) );
								continue;
							}
							if ( value == 4 ) {
								distance = polfaces->GetItem( j * value + 3 )->v.DistanceSqr( &polVertexs->GetItem( i )->v );
								if ( distance <= RES_GEOM ) {
									( *normal ) = ( *normal ) + T3DSize( polfaces->GetItem( j * value + 3 )->n.GetPoint( ) );
									continue;
								}
							}
						}
					}
					return polVertexs->GetItem( i );
				}
			}
		}
	}
	return 0;
}

//------------------------------------------------------------------------------

T3DPoint TPBrepData::GetSubdivisionCentroidFromEdge( TOGLTransf *OGLTransf, IwPolyEdge *edge, T3DVector *normal )
{
	int i, j, index, nEdges, nFaces, value;
	double distance;
	T3DPoint pt3dVoid;
	TOGLPolygon *poledges, *polfaces;
	TSubdivisionData *subdivisiondata;

	if ( !edge || !RefEnt || !ToMesh( RefEnt ) || !ToMesh( RefEnt )->HasSubdivisionDepMesh( ) ) return pt3dVoid;
	subdivisiondata = 0;
	if ( ToMesh( RefEnt )->HasSubdivisionDepMesh( ) ) subdivisiondata = ToDepMesh( ToMesh( RefEnt )->GetDepMeshes( )->GetShape( 0 ) )->GetSubdivisionData( );

	if ( !IsTopologyDirty( ) ) {
		poledges = ToDepMesh( RefEnt->GetDepMeshes( )->GetShape( 0 ) )->GetSubdivisionEdges( OGLTransf );
		if ( poledges ) {
			polfaces = 0;
			if ( normal ) {
				polfaces = ToDepMesh( RefEnt->GetDepMeshes( )->GetShape( 0 ) )->GetSubdivisionFaces( OGLTransf );
				( *normal ) = T3DVector( );
			}
			index = edge->GetUserIndex1( );
			nEdges = poledges->Count( ) / 2;
			for ( i = 0; i < nEdges; i++ ) {
				if ( (int) poledges->GetItem( i * 2 )->t.v[ 0 ] == index ) {
					if ( (int) poledges->GetItem( i * 2 )->t.v[ 1 ] ) {
						if ( polfaces && normal ) {
							if ( !subdivisiondata || subdivisiondata->ForceTriangles ) value = 3;
							else
								value = 4;
							nFaces = polfaces->Count( ) / value;
							for ( j = 0; j < nFaces; j++ ) {
								distance = polfaces->GetItem( j * value )->v.DistanceSqr( &poledges->GetItem( i * 2 )->v );
								if ( distance <= RES_GEOM ) {
									( *normal ) = ( *normal ) + T3DSize( polfaces->GetItem( j * value )->n.GetPoint( ) );
									continue;
								}
								distance = polfaces->GetItem( j * value + 1 )->v.DistanceSqr( &poledges->GetItem( i * 2 )->v );
								if ( distance <= RES_GEOM ) {
									( *normal ) = ( *normal ) + T3DSize( polfaces->GetItem( j * value + 1 )->n.GetPoint( ) );
									continue;
								}
								distance = polfaces->GetItem( j * value + 2 )->v.DistanceSqr( &poledges->GetItem( i * 2 )->v );
								if ( distance <= RES_GEOM ) {
									( *normal ) = ( *normal ) + T3DSize( polfaces->GetItem( j * value + 2 )->n.GetPoint( ) );
									continue;
								}
								if ( value == 4 ) {
									distance = polfaces->GetItem( j * value + 3 )->v.DistanceSqr( &poledges->GetItem( i * 2 )->v );
									if ( distance <= RES_GEOM ) {
										( *normal ) = ( *normal ) + T3DSize( polfaces->GetItem( j * value + 3 )->n.GetPoint( ) );
										continue;
									}
								}
							}
						}
						return poledges->GetItem( i * 2 )->v.GetPoint( );
					}
				}
			}
		}
	}
	return pt3dVoid;
}

//------------------------------------------------------------------------------

T3DPoint TPBrepData::GetSubdivisionCentroidFromFace( TOGLTransf *OGLTransf, IwPolyFace *face, T3DVector *normal )
{
	int i, j, index, nFaces, nCount, value;
	T3DPoint org;
	T3DVector v0, v1, normAux;
	TOGLPolygon *polfaces;
	IwTA<IwPolyVertex *> auxVertices;
	TSubdivisionData *subdivisiondata;

	if ( !face || !RefEnt || !ToMesh( RefEnt ) || !ToMesh( RefEnt )->HasSubdivisionDepMesh( ) ) return org;
	subdivisiondata = 0;
	if ( ToMesh( RefEnt )->HasSubdivisionDepMesh( ) ) subdivisiondata = ToDepMesh( ToMesh( RefEnt )->GetDepMeshes( )->GetShape( 0 ) )->GetSubdivisionData( );

	if ( !IsTopologyDirty( ) ) {
		polfaces = ToDepMesh( RefEnt->GetDepMeshes( )->GetShape( 0 ) )->GetSubdivisionFaces( OGLTransf );
		if ( polfaces ) {
			nCount = 0;
			if ( normal ) ( *normal ) = T3DVector( );
			index = face->GetIndexExt( );
			if ( !subdivisiondata || subdivisiondata->ForceTriangles ) value = 3;
			else
				value = 4;
			nFaces = polfaces->Count( ) / value;
			for ( i = 0; i < nFaces; i++ ) {
				if ( int( polfaces->GetItem( i * value )->t.v[ 0 ] ) == index ) {
					for ( j = 0; j < value; j++ ) {
						if ( (int) polfaces->GetItem( i * value + j )->t.v[ 1 ] ) {
							if ( normal ) ( *normal ) = ( *normal ) + T3DSize( polfaces->GetItem( i * value + j )->n.GetPoint( ) );
							// El origen es diferente cuando el nivel de subdivision es 0 (todos los puntos de la cara)
							org = org + polfaces->GetItem( i * value + j )->v.GetPoint( );
							nCount++;
							if ( Subdivision && Subdivision->GetLevel( ) != 0 ) break;
						}
					}
				}
				if ( Subdivision && Subdivision->GetLevel( ) != 0 && nCount > 0 ) break;
			}
			if ( nCount ) org = org / nCount;
		}
	}
	return org;
}

//------------------------------------------------------------------------------

void TPBrepData::UpdateColor( TOGLTransf *OGLTransf, int ind, SelectedElementType selType, TInteger_List *indexes, float a, bool onlySubdivision, bool onlyLowPoly )
{
	int i, j, k, numPol, numFace, numVert, nFaces, value;
	float colorNoSelR, colorNoSelG, colorNoSelB, colorSelR, colorSelG, colorSelB, colorSelR_Dark, colorSelG_Dark, colorSelB_Dark;
	TColor colorNoSel, colorSel;
	SelectedElementType selTypeFace;
	TOGLPolygon *pol;
	TOGLPoint *oglpt;
	TOGLPolygon *polfaces;
	TOGLPolygonList *polList;
	TSubdivisionData *subdivisiondata;

	if ( !PBrep || !RefEnt || !ToMesh( RefEnt ) || !ToMesh( RefEnt )->IsPolygonalMesh( ) ) return;
	if ( ind >= (int) PBrepFaces.GetSize( ) ) return;

	subdivisiondata = 0;
	if ( ToMesh( RefEnt )->HasSubdivisionDepMesh( ) ) subdivisiondata = ToDepMesh( ToMesh( RefEnt )->GetDepMeshes( )->GetShape( 0 ) )->GetSubdivisionData( );

	colorNoSel = AuxEntityColor[ 0 ];
	colorNoSelR = ( (float) GetRValue( ColorToRGB( colorNoSel ) ) ) / 255.0;
	colorNoSelG = ( (float) GetGValue( ColorToRGB( colorNoSel ) ) ) / 255.0;
	colorNoSelB = ( (float) GetBValue( ColorToRGB( colorNoSel ) ) ) / 255.0;

	colorSel = AuxEntityColor[ 3 ];
	colorSelR = ( (float) GetRValue( ColorToRGB( colorSel ) ) ) / 255.0;
	colorSelG = ( (float) GetGValue( ColorToRGB( colorSel ) ) ) / 255.0;
	colorSelB = ( (float) GetBValue( ColorToRGB( colorSel ) ) ) / 255.0;

	colorSelR_Dark = colorSelR - ( colorSelR * (float) 0.07 );
	if ( colorSelR_Dark < 0.0 ) colorSelR_Dark = 0.0;
	colorSelG_Dark = colorSelG - ( colorSelG * (float) 0.07 );
	if ( colorSelG_Dark < 0.0 ) colorSelG_Dark = 0.0;
	colorSelB_Dark = colorSelB - ( colorSelB * (float) 0.07 );
	if ( colorSelB_Dark < 0.0 ) colorSelB_Dark = 0.0;
	if ( ind > -1 ) { // una cara
		if ( !onlySubdivision ) {
			numPol = PBrepPolListRelF[ ind ].i0;
			numFace = PBrepPolListRelF[ ind ].i1;
			numVert = PBrepPolListRelF[ ind ].i2;
			if ( !RefEnt->GetOGLRenderData( )->Colors || !RefEnt->GetOGLRenderData( )->Colors->IsHomogeneous( RefEnt->GetOGLList( OGLTransf ) ) ) RefEnt->GetOGLRenderData( )->SetColors( RefEnt->GetOGLList( OGLTransf ) );
			for ( j = 0; j < numVert; j++ ) {
				pol = RefEnt->OGLRenderData.Colors->GetItem( numPol );
				if ( !pol ) continue;
				oglpt = pol->GetItem( numFace * numVert + j );
				if ( !oglpt ) continue;
				if ( selType == SelectedElementType::UserSelection || selType == SelectedElementType::LoopSelection || selType == SelectedElementType::LastBeforeUserSelection ) oglpt->v.Set( colorSelR, colorSelG, colorSelB );
				else if ( selType == SelectedElementType::NoSelected )
					oglpt->v.Set( colorNoSelR, colorNoSelG, colorNoSelB );
				else if ( selType == SelectedElementType::LastUserSelection )
					oglpt->v.Set( colorSelR_Dark, colorSelG_Dark, colorSelB_Dark );
				oglpt->uv.Set( a, 0 );
			}
		}

		if ( !onlyLowPoly && !IsTopologyDirty( ) && ToMesh( RefEnt ) && ToMesh( RefEnt )->HasSubdivisionDepMesh( ) && !RefEnt->GetDepMeshes( )->GetShape( 0 )->GetPolygonDirty( ) && RefEnt->GetDepMeshes( )->GetShape( 0 )->OGLRenderData.Colors ) {
			polfaces = ToDepMesh( RefEnt->GetDepMeshes( )->GetShape( 0 ) )->GetSubdivisionFaces( OGLTransf );
			pol = RefEnt->GetDepMeshes( )->GetShape( 0 )->OGLRenderData.Colors->GetItem( 0 );
			if ( pol && polfaces && !pol->IsHomogeneous( polfaces ) ) {
				polList = RefEnt->GetDepMeshes( )->GetShape( 0 )->GetOGLList( OGLTransf );
				RefEnt->GetDepMeshes( )->GetShape( 0 )->GetOGLRenderData( )->SetColors( polList );
				pol = RefEnt->GetDepMeshes( )->GetShape( 0 )->OGLRenderData.Colors->GetItem( 0 );
				if ( !pol->IsHomogeneous( polfaces ) ) return; // Si aun asi no coinciden no hacer el bucle
			}

			if ( pol && polfaces ) {
				if ( !subdivisiondata || subdivisiondata->ForceTriangles ) value = 3;
				else
					value = 4;
				nFaces = polfaces->Count( ) / value;
				for ( i = 0; i < nFaces; i++ ) {
					if ( int( polfaces->GetItem( i * value )->t.v[ 0 ] ) == ind ) {
						for ( j = 0; j < value; j++ ) {
							oglpt = pol->GetItem( i * value + j );
							if ( selType == SelectedElementType::UserSelection || selType == SelectedElementType::LoopSelection || selType == SelectedElementType::LastBeforeUserSelection ) oglpt->v.Set( colorSelR, colorSelG, colorSelB );
							else if ( selType == SelectedElementType::NoSelected )
								oglpt->v.Set( colorNoSelR, colorNoSelG, colorNoSelB );
							else if ( selType == SelectedElementType::LastUserSelection )
								oglpt->v.Set( colorSelR_Dark, colorSelG_Dark, colorSelB_Dark );
							oglpt->uv.Set( a, 0 );
						}
					}
				}
			}
		}
	} else if ( indexes ) { // Lista de caras
		if ( !onlySubdivision ) {
			// si hiciera falta, optimizar como el de arriba
			if ( !RefEnt->GetOGLRenderData( )->Colors || !RefEnt->GetOGLRenderData( )->Colors->IsHomogeneous( RefEnt->GetOGLList( OGLTransf ) ) ) RefEnt->GetOGLRenderData( )->SetColors( RefEnt->GetOGLList( OGLTransf ) );
			for ( k = 0; k < indexes->Count( ); k++ ) {
				ind = *( indexes->GetItem( k ) );
				numPol = PBrepPolListRelF[ ind ].i0;
				pol = RefEnt->OGLRenderData.Colors->GetItem( numPol );
				if ( !pol ) continue;
				numFace = PBrepPolListRelF[ ind ].i1;
				numVert = PBrepPolListRelF[ ind ].i2;
				for ( i = 0; i < numVert; i++ ) {
					oglpt = pol->GetItem( numFace * numVert + i );
					if ( !oglpt ) continue;
					if ( selType == SelectedElementType::UserSelection || selType == SelectedElementType::LoopSelection || selType == SelectedElementType::LastBeforeUserSelection ) oglpt->v.Set( colorSelR, colorSelG, colorSelB );
					else if ( selType == SelectedElementType::NoSelected )
						oglpt->v.Set( colorNoSelR, colorNoSelG, colorNoSelB );
					else if ( selType == SelectedElementType::LastUserSelection )
						oglpt->v.Set( colorSelR_Dark, colorSelG_Dark, colorSelB_Dark );
					oglpt->uv.Set( a, 0 );
				}
			}
		}

		if ( !onlyLowPoly && !IsTopologyDirty( ) && ToMesh( RefEnt ) && ToMesh( RefEnt )->HasSubdivisionDepMesh( ) && !RefEnt->GetDepMeshes( )->GetShape( 0 )->GetPolygonDirty( ) && RefEnt->GetDepMeshes( )->GetShape( 0 )->OGLRenderData.Colors ) {
			polfaces = ToDepMesh( RefEnt->GetDepMeshes( )->GetShape( 0 ) )->GetSubdivisionFaces( OGLTransf );
			pol = RefEnt->GetDepMeshes( )->GetShape( 0 )->OGLRenderData.Colors->GetItem( 0 );
			if ( pol && polfaces && !pol->IsHomogeneous( polfaces ) ) {
				polList = RefEnt->GetDepMeshes( )->GetShape( 0 )->GetOGLList( OGLTransf );
				RefEnt->GetDepMeshes( )->GetShape( 0 )->GetOGLRenderData( )->SetColors( polList );
				pol = RefEnt->GetDepMeshes( )->GetShape( 0 )->OGLRenderData.Colors->GetItem( 0 );
				if ( !pol->IsHomogeneous( polfaces ) ) return; // Si aun asi no coinciden no hacer el bucle
			}

			if ( pol && polfaces ) {
				if ( !subdivisiondata || subdivisiondata->ForceTriangles ) value = 3;
				else
					value = 4;
				nFaces = polfaces->Count( ) / value;
				for ( i = 0; i < nFaces; i++ ) {
					ind = int( polfaces->GetItem( i * value )->t.v[ 0 ] );
					if ( indexes->GetItemIndex( &ind ) >= 0 ) {
						for ( j = 0; j < value; j++ ) {
							oglpt = pol->GetItem( i * value + j );
							if ( selType == SelectedElementType::UserSelection || selType == SelectedElementType::LoopSelection || selType == SelectedElementType::LastBeforeUserSelection ) oglpt->v.Set( colorSelR, colorSelG, colorSelB );
							else if ( selType == SelectedElementType::NoSelected )
								oglpt->v.Set( colorNoSelR, colorNoSelG, colorNoSelB );
							else if ( selType == SelectedElementType::LastUserSelection )
								oglpt->v.Set( colorSelR_Dark, colorSelG_Dark, colorSelB_Dark );
							oglpt->uv.Set( a, 0 );
						}
					}
				}
			}
		}
	} else { // todas
		if ( !onlySubdivision ) {
			if ( !RefEnt->GetOGLRenderData( )->Colors || !RefEnt->GetOGLRenderData( )->Colors->IsHomogeneous( RefEnt->GetOGLList( OGLTransf ) ) ) RefEnt->GetOGLRenderData( )->SetColors( RefEnt->GetOGLList( OGLTransf ) );
			for ( i = 0; i < (int) PBrepFaces.GetSize( ); i++ ) {
				numPol = PBrepPolListRelF[ i ].i0;
				pol = RefEnt->OGLRenderData.Colors->GetItem( numPol );
				if ( !pol ) continue;
				numFace = PBrepPolListRelF[ i ].i1;
				numVert = PBrepPolListRelF[ i ].i2;
				for ( j = 0; j < numVert; j++ ) {
					oglpt = pol->GetItem( numFace * numVert + j );
					if ( !oglpt ) continue;
					if ( (SelectedElementType) SelectedF[ i ].i == SelectedElementType::UserSelection || (SelectedElementType) SelectedF[ i ].i == SelectedElementType::LoopSelection || (SelectedElementType) SelectedF[ i ].i == SelectedElementType::LastBeforeUserSelection ) oglpt->v.Set( colorSelR, colorSelG, colorSelB );
					else if ( (SelectedElementType) SelectedF[ i ].i == SelectedElementType::NoSelected )
						oglpt->v.Set( colorNoSelR, colorNoSelG, colorNoSelB );
					else if ( (SelectedElementType) SelectedF[ i ].i == SelectedElementType::LastUserSelection )
						oglpt->v.Set( colorSelR_Dark, colorSelG_Dark, colorSelB_Dark );
					oglpt->uv.Set( a, 0 );
				}
			}
		}

		if ( !onlyLowPoly && !IsTopologyDirty( ) && ToMesh( RefEnt ) && ToMesh( RefEnt )->HasSubdivisionDepMesh( ) && !RefEnt->GetDepMeshes( )->GetShape( 0 )->GetPolygonDirty( ) && RefEnt->GetDepMeshes( )->GetShape( 0 )->OGLRenderData.Colors ) {
			polfaces = ToDepMesh( RefEnt->GetDepMeshes( )->GetShape( 0 ) )->GetSubdivisionFaces( OGLTransf );
			pol = RefEnt->GetDepMeshes( )->GetShape( 0 )->OGLRenderData.Colors->GetItem( 0 );
			if ( pol && polfaces && !pol->IsHomogeneous( polfaces ) ) {
				polList = RefEnt->GetDepMeshes( )->GetShape( 0 )->GetOGLList( OGLTransf );
				RefEnt->GetDepMeshes( )->GetShape( 0 )->GetOGLRenderData( )->SetColors( polList );
				pol = RefEnt->GetDepMeshes( )->GetShape( 0 )->OGLRenderData.Colors->GetItem( 0 );
				if ( !pol->IsHomogeneous( polfaces ) ) return; // Si aun asi no coinciden no hacer el bucle
			}

			if ( pol && polfaces ) {
				if ( !subdivisiondata || subdivisiondata->ForceTriangles ) value = 3;
				else
					value = 4;
				nFaces = polfaces->Count( ) / value;
				for ( i = 0; i < nFaces; i++ ) {
					selTypeFace = SelectedElementType( SelectedF[ int( polfaces->GetItem( i * value )->t.v[ 0 ] ) ].i );
					for ( j = 0; j < value; j++ ) {
						oglpt = pol->GetItem( i * value + j );
						if ( selTypeFace == SelectedElementType::UserSelection || selTypeFace == SelectedElementType::LoopSelection || selTypeFace == SelectedElementType::LastBeforeUserSelection ) oglpt->v.Set( colorSelR, colorSelG, colorSelB );
						else if ( selTypeFace == SelectedElementType::NoSelected )
							oglpt->v.Set( colorNoSelR, colorNoSelG, colorNoSelB );
						else if ( selTypeFace == SelectedElementType::LastUserSelection )
							oglpt->v.Set( colorSelR_Dark, colorSelG_Dark, colorSelB_Dark );
						oglpt->uv.Set( a, 0 );
					}
				}
			}
		}
	}
}

//------------------------------------------------------------------------------

void TPBrepData::SetColorEntities( TColor colorFace, TColor colorEdge, TColor colorVertex, TColor colorSelectFace, TColor seam )
{
	AuxEntityColor[ 0 ] = colorFace;
	AuxEntityColor[ 1 ] = colorEdge;
	AuxEntityColor[ 2 ] = colorVertex;
	AuxEntityColor[ 3 ] = colorSelectFace;
	AuxEntityColor[ 4 ] = seam;
}

//------------------------------------------------------------------------------
// Se busca en la pbrep aquel vértice que se corresponda con el punto
IwPolyVertex *TPBrepData::FindVertex( IwPoint3d *iwPoint )
{
	int nVertexs, i;
	IwVector3d iwVector3d;
	IwTA<IwPolyVertex *> iwVertexs;

	if ( !PBrep || !iwPoint ) return 0;

	PBrep->GetPolyVertices( iwVertexs );
	nVertexs = (int) iwVertexs.GetSize( );
	for ( i = 0; i < nVertexs; i++ ) {
		iwVector3d = iwVertexs.GetAt( i )->GetPoint( );
		if ( fabs( iwPoint->x - iwVector3d.x ) < RES_COMP && fabs( iwPoint->y - iwVector3d.y ) < RES_COMP && fabs( iwPoint->z - iwVector3d.z ) < RES_COMP ) return iwVertexs.GetAt( i );
	}

	return 0;
}

//------------------------------------------------------------------------------
// Se busca en una lista de vertices aquel que se corresponda con el punto
IwPolyVertex *TPBrepData::FindVertex( IwTA<IwPolyVertex *> *iwVertexs, IwPoint3d *iwPoint, ULONG &pos )
{
	int nVertexs, i;
	IwVector3d iwVector3d;

	if ( !iwVertexs || !iwPoint ) return 0;

	nVertexs = (int) iwVertexs->GetSize( );
	for ( i = 0; i < nVertexs; i++ ) {
		iwVector3d = iwVertexs->GetAt( i )->GetPoint( );
		if ( fabs( iwPoint->x - iwVector3d.x ) < RES_COMP && fabs( iwPoint->y - iwVector3d.y ) < RES_COMP && fabs( iwPoint->z - iwVector3d.z ) < RES_COMP ) {
			pos = i;
			return iwVertexs->GetAt( i );
		}
	}

	return 0;
}

//==============================================================================
// TPBrepData - Cálculo de anillos
//==============================================================================
// Función generica para obtener un anillo de selección que se base en uno de los métodos implementados dependiendo del valor de oneRingSelectionOption
// liSelectedElements - Elemento seleccionado de la topología de la malla
// optionsSelectElements - Opciones de selección, tipo de elemento que se ha seleccionado: Arista, cara o vértice
// liVertexLists - Vértices/Caras topológicos ordenados del anillo encontrado
// liVertexListsForSecondEdge - Vértices/Caras topológicos ordenados del segundo anillo encontrado en el caso de anillos de caras
// Devuelve la cantidad encontrada. 2, 1 o 0
int TPBrepData::GetOneRing_Iterative( TOGLTransf *OGLTransf, IwTA<int> liSelectedElements, TOneRingParams params, IwTA<TDataIntIntForVertexPaths> *liVertexLists, IwTA<TDataIntIntForVertexPaths> *liVertexListsForSecondEdge )
{
	int iError;
	ULONG i, indexedge;
	T3DPoint pt3dCenter;
	T3DRect bbMesh;
	IwExtent3d iwExtendBox;
	IwTA<TStructFaces> liFacesPaths, liFacesPaths2, liFacesPathsAux;
	OneRingFacesSearchMethod oneRingFacesSearchMethod;
	IwTA<TDataIntIntForVertexPaths> liVertexListAtOneRing, liVertexListAtOneRing2;
	IwTA<TDataIntIntForVertexPaths> liVertexListVoid;
	TDataIntIntForVertexPaths dataIntIntForVertexPaths;
	IwTA<TDataIntIntForVertexPaths> liEdgesLists;
	IwPolyEdge *edge;
	IwTA<IwPolyEdge *> edges;

	iError = DefinesForErrors::ERROR_GENERIC;
	try {
		oneRingFacesSearchMethod = OneRingFacesSearchMethod::OppositeEdge;

		( *liVertexLists ) = liVertexListAtOneRing;
		( *liVertexListsForSecondEdge ) = liVertexListAtOneRing2;

		iError = DefinesForErrors::NON_ERROR;

		if ( PBrepVertexs.GetSize( ) == 0 ) return DefinesForErrors::ERROR_SOMELISTS_ARE_VOID;
		if ( PBrepEdges.GetSize( ) == 0 ) return DefinesForErrors::ERROR_SOMELISTS_ARE_VOID;
		if ( liSelectedElements.GetSize( ) == 0 ) return DefinesForErrors::ERROR_SOMELISTS_ARE_VOID;

		switch ( params.CalcMode ) {
			case OneRingCalcMode::ShortestLength:
				if ( !TryOneRingShortest_GreatestLength( liSelectedElements[ 0 ], params.Type, liVertexLists, true ) ) ( *liVertexLists ).RemoveAll( );
				break;

			case OneRingCalcMode::GreatestLength:
				if ( !TryOneRingShortest_GreatestLength( liSelectedElements[ 0 ], params.Type, liVertexLists, false ) ) ( *liVertexLists ).RemoveAll( );
				break;

			case OneRingCalcMode::OneRingWithLevel:
				if ( !TryOneRingLevel( liSelectedElements[ 0 ], params.Type, liVertexLists, params.Level ) ) ( *liVertexLists ).RemoveAll( );
				if ( params.Type == ElementType::Edge ) {
					if ( !GetEdgeListFromVerticesList( liVertexLists, &liEdgesLists ) ) {
						( *liVertexLists ).RemoveAll( );
						return 0;
					}
					( *liVertexLists ) = liEdgesLists;
				}
				break;
				/*
				  case OneRingSelection.LyingInPlane:
						if (!TryOneRingLyingInPlane(liSelectedElements, optionsSelectElements.kindOfElement, ref liVertexLists, -1))
							 if (liVertexLists != null && liVertexLists.Count > 0) liVertexLists[0].Clear();
						break;
				  case OneRingSelection.LyingInPlaneRhino:
						if (!TryOneRingLyingInPlaneByRhino(liSelectedElements, optionsSelectElements.kindOfElement, ref liVertexLists, -1, 0.1))
							 if (liVertexLists != null && liVertexLists.Count > 0) liVertexLists[0].Clear();
						break;
						*/
			case OneRingCalcMode::ContinuityFaces:
				if ( params.Type == ElementType::Edge ) {
					if ( liSelectedElements[ 0 ] < 0 || liSelectedElements[ 0 ] > (int) PBrepEdges.GetSize( ) - 1 ) return DefinesForErrors::ERROR_NO_RINGS_FOUNDED;
					edge = PBrepEdges[ liSelectedElements[ 0 ] ];
					if ( edge && edge->IsBoundary( ) ) GetBoundaryEdgesConnected( liSelectedElements[ 0 ], liVertexLists );
					else
						TryOneRingConnectedEdges_ForEdges_Iterative( liSelectedElements[ 0 ], liVertexLists );

					DeleteInvalidRings( OGLTransf, liVertexLists, &liSelectedElements, ElementType::Edge );

					if ( liVertexLists == NULL || ( liVertexLists != NULL && ( *liVertexLists ).GetSize( ) == 0 ) ) iError = DefinesForErrors::ERROR_NO_RINGS_FOUNDED;
					else {
						if ( !GetEdgeListFromVerticesList( liVertexLists, &liEdgesLists ) ) {
							( *liVertexLists ).RemoveAll( );
							return 0;
						}
						( *liVertexLists ) = liEdgesLists;
					}
				} else if ( params.Type == ElementType::Face ) {
					if ( liSelectedElements.GetSize( ) == 1 ) {
						if ( oneRingFacesSearchMethod != OneRingFacesSearchMethod::ByEdges ) {
							if ( params.FacesType == OneRingFacesType::FacesHV ) {
								if ( liSelectedElements[ 0 ] < 0 || liSelectedElements[ 0 ] > (int) PBrepFaces.GetSize( ) - 1 ) return DefinesForErrors::ERROR_NO_RINGS_FOUNDED;
								PBrepFaces[ liSelectedElements[ 0 ] ]->GetPolyEdges( edges );
								if ( edges.GetSize( ) % 2 != 0 ) return DefinesForErrors::ERROR_NO_RINGS_FOUNDED;
								for ( i = 0; i < edges.GetSize( ) / 2; i++ ) {
									indexedge = edges[ i ]->GetUserIndex1( );
									if ( indexedge == ULONG_MAX && edges[ i ]->GetSymmetricPolyEdge( ) ) indexedge = edges[ i ]->GetSymmetricPolyEdge( )->GetUserIndex1( );
									TryOneRingConnectedFaces_ForFaces_Iterative( liSelectedElements[ 0 ], true, &liFacesPathsAux, oneRingFacesSearchMethod, indexedge );
									liFacesPaths.Append( liFacesPathsAux );
									liFacesPathsAux.RemoveAll( );
									indexedge = GetOppositeEdgeFace( OGLTransf, liSelectedElements[ 0 ], indexedge );
									if ( indexedge > 0 ) {
										TryOneRingConnectedFaces_ForFaces_Iterative( liSelectedElements[ 0 ], true, &liFacesPathsAux, oneRingFacesSearchMethod, indexedge );
										liFacesPaths2.Append( liFacesPathsAux );
										liFacesPathsAux.RemoveAll( );
									}
								}
							}

							if ( params.FacesType == OneRingFacesType::FacesByEdge ) TryOneRingConnectedFaces_ForFaces_Iterative( liSelectedElements[ 0 ], true, &liFacesPaths, oneRingFacesSearchMethod, params.IndexEdge );
						}
					}

					if ( oneRingFacesSearchMethod != OneRingFacesSearchMethod::ByEdges ) {
						if ( params.FacesType == OneRingFacesType::FacesHV || params.FacesType == OneRingFacesType::FacesByEdge ) {
							if ( liFacesPaths.GetSize( ) == 0 ) return DefinesForErrors::ERROR_NO_RINGS_FOUNDED;
							( *liVertexLists ) = liVertexListVoid;
							dataIntIntForVertexPaths.iNumBranches = 0;
							for ( i = 0; i < liFacesPaths.GetSize( ); i++ ) {
								dataIntIntForVertexPaths.iElementIndex = liFacesPaths[ i ].ulIndexOfFace;
								( *liVertexLists ).Add( dataIntIntForVertexPaths );
							}
						}

						if ( params.FacesType == OneRingFacesType::FacesHV ) {
							if ( liFacesPaths2.GetSize( ) == 0 ) return DefinesForErrors::ERROR_NO_RINGS_FOUNDED;
							( *liVertexListsForSecondEdge ) = liVertexListVoid;
							dataIntIntForVertexPaths.iNumBranches = 0;
							for ( i = 0; i < liFacesPaths2.GetSize( ); i++ ) {
								dataIntIntForVertexPaths.iElementIndex = liFacesPaths2[ i ].ulIndexOfFace;
								( *liVertexListsForSecondEdge ).Add( dataIntIntForVertexPaths );
							}
						}

						DeleteInvalidRings( OGLTransf, liVertexLists, &liSelectedElements, ElementType::Face );
						DeleteInvalidRings( OGLTransf, liVertexListsForSecondEdge, &liSelectedElements, ElementType::Face );

						if ( ( *liVertexLists ).GetSize( ) == 0 && ( *liVertexListsForSecondEdge ).GetSize( ) == 0 ) iError = DefinesForErrors::ERROR_NO_RINGS_FOUNDED;
					}
				}
				break;
			default: break;
		}
	} catch ( Exception &e ) {
#ifdef _DEBUG
		_MessageBox( e.ToString( ), _GetTranslatedString( "IDS_WARNING" ), mtWarning, TMsgDlgButtons( ) << mbOK );
#endif
	}

	return iError;
}

//---------------------------------------------------------------------------
// INICIO Funciones de apoyo CALCULO DE ANILLOS
//---------------------------------------------------------------------------

// Función para obtener el anillo más corto/ más largo a partir de un elemento seleccionado. Si el elemento es una arista o un vértice
//  entonces busca la cara adyacente cuyo perímetro es más corto/largo. Si es una cara entonces se devuelve su perímetro
// ulSelectedElement - Elemento seleccionado de la topología de la malla
// kindOfElement - Tipo de elemento que se ha seleccionado: Arista, cara o vértice
// liVertexPaths - Vértices topológicos ordenados del anillo encontrado, puede haber varias listas
// bShortest - Booleano para especificar si queremos la cara mas corta o la más larga
// True en caso de búsqueda exitosa. False en caso contrario
bool TPBrepData::TryOneRingShortest_GreatestLength( ULONG ulSelectedElement, ElementType eType, IwTA<TDataIntIntForVertexPaths> *liVertexPaths, bool bShortest )
{
	bool bCorrectPath, bOneRingClosed;
	int iFaceSelected;
	ULONG i;
	double dPerimeterSquared, dMinPerimeterSquared, dMaxPerimeterSquared;
	TDataIntIntForVertexPaths dataIntIntForVertexPaths;
	IwTA<TDataIntIntForVertexPaths> liVertexPathsFounded;
	IwTA<IwPolyFace *> liFaces;
	IwTA<IwPolyVertex *> liVertex;

	try {
		bOneRingClosed = false;
		bCorrectPath = false;
		if ( PBrepVertexs.GetSize( ) == 0 ) return false;
		if ( PBrepEdges.GetSize( ) == 0 ) return false;
		if ( PBrepFaces.GetSize( ) == 0 ) return false;

		if ( eType == ElementType::Edge && ( ulSelectedElement > PBrepEdges.GetSize( ) - 1 ) ) return false;
		if ( eType == ElementType::Face && ( ulSelectedElement > PBrepFaces.GetSize( ) - 1 ) ) return false;
		if ( eType == ElementType::Vertex && ( ulSelectedElement > PBrepVertexs.GetSize( ) - 1 ) ) return false;

		iFaceSelected = -1;

		if ( eType == ElementType::Edge ) liFaces = GetConnectedFacesFromEdge( ulSelectedElement );
		else if ( eType == ElementType::Face )
			liFaces.AddUnique( PBrepFaces[ ulSelectedElement ] );
		else
			liFaces = GetConnectedFacesFromVertex( ulSelectedElement );

		if ( liFaces.GetSize( ) > 0 ) {
			dMinPerimeterSquared = DBL_MAX;
			dMaxPerimeterSquared = 0;
			for ( i = 0; i < liFaces.GetSize( ); i++ ) {
				dPerimeterSquared = PerimeterSquared( liFaces[ i ] );
				if ( bShortest ) {
					if ( dPerimeterSquared < dMinPerimeterSquared ) {
						dMinPerimeterSquared = dPerimeterSquared;
						iFaceSelected = i;
					}
				} else // Greatest
				{
					if ( dPerimeterSquared > dMaxPerimeterSquared ) {
						dMaxPerimeterSquared = dPerimeterSquared;
						iFaceSelected = i;
					}
				}
			}
		}

		if ( iFaceSelected >= 0 ) {
			*liVertexPaths = liVertexPathsFounded;
			liFaces.GetAt( iFaceSelected )->GetPolyVertices( liVertex );
			for ( i = 0; i < liVertex.GetSize( ); i++ ) {
				dataIntIntForVertexPaths.iNumBranches = 0;
				dataIntIntForVertexPaths.iElementIndex = liVertex[ i ]->GetIndexExt( );
				( *liVertexPaths ).Add( dataIntIntForVertexPaths );
			}
			dataIntIntForVertexPaths.iNumBranches = 0;
			dataIntIntForVertexPaths.iElementIndex = liVertex[ 0 ]->GetIndexExt( );
			( *liVertexPaths ).Add( dataIntIntForVertexPaths );
			bOneRingClosed = true;
		}

		if ( bOneRingClosed ) bCorrectPath = true;
	} catch ( Exception &e ) {
#ifdef _DEBUG
		_MessageBox( e.ToString( ), _GetTranslatedString( "IDS_WARNING" ), mtWarning, TMsgDlgButtons( ) << mbOK );
#endif
	}

	return bCorrectPath;
}

//-------------------------------------------------------------------------------------
// Función para obtener un anillo concéntrico de un radio de aristas definido por el usuario
// ulSelectedElement - Elemento seleccionado de la topología de la malla
// kindOfElement - Tipo de elemento que se ha seleccionado: Arista, cara o vértice
// liElementsPaths - Devuelve la lista de elementos del anillo que se calcula
// iLevel - Nivel de profundidad en la búsqueda del anillo en el caso del tipo de anillo OneRingWithLevel
// True si ha encontrado un anillo, False en caso contrario
bool TPBrepData::TryOneRingLevel( ULONG ulSelectedElement, ElementType eType, IwTA<TDataIntIntForVertexPaths> *liElementsPaths, int iLevel )
{
	bool bCorrectPath, bOneRingClosed, bDeletedVertex, bClockWise, bFounded;
	ULONG uli, ulj, ulk, ulIndex1, ulIndex2, nFoundIndex;
	int ii, iNumVertexAtExtrems;
	IwPolyVertex *iwVertexStart, *iwVertexEnd;
	IwPolyEdge *iwEdge_Simmetric;
	IwTA<IwPolyFace *> liwAllFacesPrevious, liwFacesNext, liwFacesPrevious;
	IwTA<IwPolyVertex *> liwVerticesAux, liwVerticesActual, liwVertexPrevious, liwAllVertexPrevious;
	IwTA<IwPolyEdge *> liwEdges;
	IwTA<TDataIntIntForVertexPaths> liElementsPathsFounded;
	TDataIntIntForVertexPaths dataIntIntForVertexPaths;
	int indexPairTopologyVertex[ 2 ];

	try {
		bOneRingClosed = false;
		bCorrectPath = false;

		if ( PBrepVertexs.GetSize( ) == 0 ) return false;
		if ( PBrepEdges.GetSize( ) == 0 ) return false;
		if ( PBrepFaces.GetSize( ) == 0 ) return false;

		if ( eType == ElementType::Edge && ( ulSelectedElement > PBrepEdges.GetSize( ) - 1 ) ) return false;
		if ( eType == ElementType::Face && ( ulSelectedElement > PBrepFaces.GetSize( ) - 1 ) ) return false;
		if ( eType == ElementType::Vertex && ( ulSelectedElement > PBrepVertexs.GetSize( ) - 1 ) ) return false;

		if ( iLevel < 1 ) return false;

		// Primer nivel de caras
		if ( eType == ElementType::Edge ) {
			liwFacesNext.Append( GetConnectedFacesFromVertex( PBrepEdges[ ulSelectedElement ]->GetStartVertex( ) ) );
			liwFacesNext.Append( GetConnectedFacesFromVertex( PBrepEdges[ ulSelectedElement ]->GetEndVertex( ) ) );
			liwFacesNext.RemoveDuplicates( );
		} else if ( eType == ElementType::Face )
			liwFacesNext.AddUnique( PBrepFaces[ ulSelectedElement ] );
		else
			liwFacesNext = GetConnectedFacesFromVertex( ulSelectedElement );

		// Primer nivel de vértices.
		for ( uli = 0; uli < liwFacesNext.GetSize( ); uli++ ) {
			liwFacesNext[ uli ]->GetPolyVertices( liwVerticesAux );
			liwVerticesActual.Append( liwVerticesAux );
		}
		liwVerticesActual.RemoveDuplicates( );

		if ( eType == ElementType::Vertex ) {
			if ( liwVerticesActual.FindElement( PBrepVertexs[ ulSelectedElement ], nFoundIndex ) ) liwVerticesActual.RemoveAt( nFoundIndex );
		} else if ( eType == ElementType::Edge ) {
			if ( liwVerticesActual.FindElement( PBrepEdges[ ulSelectedElement ]->GetStartVertex( ), nFoundIndex ) ) liwVerticesActual.RemoveAt( nFoundIndex );
			if ( liwVerticesActual.FindElement( PBrepEdges[ ulSelectedElement ]->GetEndVertex( ), nFoundIndex ) ) liwVerticesActual.RemoveAt( nFoundIndex );
		}

		for ( ii = 0; ii < ( eType == ElementType::Face ? iLevel : iLevel - 1 ); ii++ ) {
			// Copiamos las caras y vertices en el array correspondiente preprarando el siguiente nivel
			liwFacesPrevious = liwFacesNext;
			liwAllFacesPrevious.Append( liwFacesPrevious );
			liwAllVertexPrevious.Append( liwVerticesActual );

			liwVerticesActual.RemoveAll( );
			liwFacesNext.RemoveAll( );
			for ( ulj = 0; ulj < liwFacesPrevious.GetSize( ); ulj++ ) {
				liwFacesPrevious[ ulj ]->GetPolyVertices( liwVerticesAux );
				for ( ulk = 0; ulk < liwVerticesAux.GetSize( ); ulk++ ) {
					liwFacesNext.Append( GetConnectedFacesFromVertex( liwVerticesAux[ ulk ]->GetIndexExt( ) ) );
				}
			}
			liwFacesNext.RemoveDuplicates( );

			// Ahora eliminamos las caras de los niveles anteriores para dejar solo el contorno externo
			for ( ulj = 0; ulj < liwAllFacesPrevious.GetSize( ); ulj++ ) {
				bFounded = liwFacesNext.FindElement( liwAllFacesPrevious[ ulj ], nFoundIndex );
				if ( bFounded ) liwFacesNext.RemoveAt( nFoundIndex );
			}

			for ( uli = 0; uli < liwFacesNext.GetSize( ); uli++ ) {
				liwFacesNext[ uli ]->GetPolyVertices( liwVerticesAux );
				liwVerticesActual.Append( liwVerticesAux );
			}
			liwVerticesActual.RemoveDuplicates( );

			// Con todos los vertices del nivel actual y del anterior podemos sacar los vertices del borde externo
			for ( ulj = 0; ulj < liwAllVertexPrevious.GetSize( ); ulj++ ) {
				do {
					bFounded = liwVerticesActual.FindElement( liwAllVertexPrevious[ ulj ], nFoundIndex );
					if ( bFounded > 0 ) liwVerticesActual.RemoveAt( nFoundIndex );
				} while ( bFounded > 0 );
			}
		}

		// Antes de pasar a la ultima fase, tenemos que quitar los vertices que se hayan quedado en un camino sin salida
		// pq dependiendo de la malla y el vertice elegido, puede pasar.
		do {
			bDeletedVertex = false;
			for ( uli = 0; uli < liwVerticesActual.GetSize( ); uli++ ) {
				iNumVertexAtExtrems = 0;
				liwVerticesActual[ uli ]->GetPolyEdges( liwEdges );

				// Buscamos en la lista de vertices uno de la lista anterior
				for ( ulj = 0; ulj < liwEdges.GetSize( ); ulj++ ) {
					iwEdge_Simmetric = liwEdges[ ulj ]->GetSymmetricPolyEdge( );
					bFounded = PBrepEdges.FindElement( liwEdges[ ulj ], nFoundIndex );
					if ( !bFounded && iwEdge_Simmetric ) {
						bFounded = PBrepEdges.FindElement( iwEdge_Simmetric, nFoundIndex );
						if ( bFounded ) liwEdges[ ulj ] = iwEdge_Simmetric;
					}
					if ( bFounded ) {
						if ( eType == ElementType::Edge && ulSelectedElement == nFoundIndex ) continue;

						indexPairTopologyVertex[ 0 ] = liwEdges[ ulj ]->GetStartVertex( )->GetIndexExt( );
						indexPairTopologyVertex[ 1 ] = liwEdges[ ulj ]->GetEndVertex( )->GetIndexExt( );
						iwVertexStart = liwEdges[ ulj ]->GetStartVertex( );
						iwVertexEnd = liwEdges[ ulj ]->GetEndVertex( );
						bFounded = liwVerticesActual.FindElement( iwVertexStart, ulIndex1 );
						if ( !bFounded ) continue;
						bFounded = liwVerticesActual.FindElement( iwVertexEnd, ulIndex2 );
						if ( !bFounded ) continue;

						if ( ulIndex1 != uli ) iNumVertexAtExtrems++;
						if ( ulIndex2 != uli ) iNumVertexAtExtrems++;
					}
				}
				if ( iNumVertexAtExtrems < 2 ) {
					// Si no tiene los 2 indices entonces borramos el vertice de la lista
					liwVerticesActual.RemoveAt( uli );
					bDeletedVertex = true;
					break;
				}
			}
		} while ( bDeletedVertex );

		// En este punto ya tenemos todas las caras implicadas y el anillo de vertices, solo falta ordenar estos vertices
		// Empezamos por uno y vamos siguiendo por las aristas implicadas.
		liwVerticesActual = OrderListOfVertexes( &liwVerticesActual, &liwFacesNext, bClockWise );

		if ( liwVerticesActual.GetSize( ) > 1 && eType != ElementType::Face ) {
			liwVerticesActual.Add( liwVerticesActual[ 0 ] );

			( *liElementsPaths ) = liElementsPathsFounded;
			for ( uli = 0; uli < liwVerticesActual.GetSize( ); uli++ ) {
				dataIntIntForVertexPaths.iNumBranches = 0;
				dataIntIntForVertexPaths.iElementIndex = liwVerticesActual[ uli ]->GetIndexExt( );
				( *liElementsPaths ).Add( dataIntIntForVertexPaths );
			}
			bOneRingClosed = true;
		} else if ( liwFacesNext.GetSize( ) > 0 && eType == ElementType::Face ) {
			( *liElementsPaths ) = liElementsPathsFounded;
			for ( uli = 0; uli < liwFacesNext.GetSize( ); uli++ ) {
				dataIntIntForVertexPaths.iNumBranches = 0;
				dataIntIntForVertexPaths.iElementIndex = liwFacesNext[ uli ]->GetIndexExt( );
				( *liElementsPaths ).Add( dataIntIntForVertexPaths );
			}
			bOneRingClosed = true;
		}

		if ( bOneRingClosed ) bCorrectPath = true;
	} catch ( Exception &e ) {
#ifdef _DEBUG
		_MessageBox( e.ToString( ), _GetTranslatedString( "IDS_WARNING" ), mtWarning, TMsgDlgButtons( ) << mbOK );
#endif
	}

	return bCorrectPath;
}

//-------------------------------------------------------------------------------------
// Función para obtener un anillo de aristas a partir de la conectividad de las mismas.
// iSelectedEdge - Arista seleccionada de la topología de la malla
// liVertexPaths - Devuelve la lista de vertices del anillo de aristas que se calcula
// True si ha encontrado un anillo, False en caso contrario
bool TPBrepData::TryOneRingConnectedEdges_ForEdges_Iterative( int iSelectedEdge, IwTA<TDataIntIntForVertexPaths> *liVertexPaths )
{
	bool bCorrectPath, bOneRingClosed, bContinue, bFounded1, bFounded2, bFounded;
	int indexPairTopologyVertex[ 2 ];
	ULONG ulIndex1, ulIndex2, ul, ulIndex, ulIndexIni, ulIndexAux;
	TDataIntIntForVertexPaths dataIntIntForVertexPath;
	IwTA<TDataIntIntForVertexPaths> ldataIntIntForVertexPath;
	IwStatus iwStatus;
	IwTA<TDataIntIntForVertexPaths> lNewPath;
	T3DVector vect3dNormal;
	T3DPlane pln, plnNew, planeFit;
	IwPoint3d iwPoint3d;
	IwPolyEdge *iwEdge, *iwEdgeAux;
	IwTA<ULONG> liVertexAux;
	IwTA<TDataIntIntForVertexPaths> liFacesOneRing;
	IwTA<IwPolyVertex *> meshVertexList, liwVertexAux, liwVertexStart, liwVertexEnd, liwVertexStartCopy, liwVertexEndCopy, liwVertexStartAux, liwVertexListAtEnd;
	IwTA<IwPolyEdge *> liwEdges, meshEdgeList;

	bOneRingClosed = false;
	bCorrectPath = false;
	try {
		meshEdgeList = PBrepEdges;
		meshVertexList = PBrepVertexs;

		if ( liVertexPaths == NULL || ( *liVertexPaths ).GetSize( ) == 0 ) {
			( *liVertexPaths ) = lNewPath;

			indexPairTopologyVertex[ 0 ] = meshEdgeList[ iSelectedEdge ]->GetStartVertex( )->GetIndexExt( );
			indexPairTopologyVertex[ 1 ] = meshEdgeList[ iSelectedEdge ]->GetEndVertex( )->GetIndexExt( );

			dataIntIntForVertexPath.iElementIndex = indexPairTopologyVertex[ 0 ];
			dataIntIntForVertexPath.iNumBranches = 0;
			( *liVertexPaths ).Add( dataIntIntForVertexPath );

			dataIntIntForVertexPath.iElementIndex = indexPairTopologyVertex[ 1 ];
			dataIntIntForVertexPath.iNumBranches = 0;
			( *liVertexPaths ).Add( dataIntIntForVertexPath );
		}

		indexPairTopologyVertex[ 0 ] = ( *liVertexPaths )[ 0 ].iElementIndex;
		indexPairTopologyVertex[ 1 ] = ( *liVertexPaths )[ ( *liVertexPaths ).GetSize( ) - 1 ].iElementIndex;

		dataIntIntForVertexPath.iElementIndex = indexPairTopologyVertex[ 0 ];
		dataIntIntForVertexPath.iNumBranches = 0;
		bFounded1 = ( *liVertexPaths ).FindElement( dataIntIntForVertexPath, ulIndex1 );
		dataIntIntForVertexPath.iElementIndex = indexPairTopologyVertex[ 1 ];
		dataIntIntForVertexPath.iNumBranches = 0;
		bFounded2 = ( *liVertexPaths ).FindElement( dataIntIntForVertexPath, ulIndex2 );

		if ( !bFounded1 || !bFounded2 ) return false;
		if ( ulIndex1 != ulIndex2 + 1 && ulIndex1 + 1 != ulIndex2 && ulIndex1 != 0 && ulIndex2 != ( *liVertexPaths ).GetSize( ) - 1 && ulIndex1 != ( *liVertexPaths ).GetSize( ) - 1 && ulIndex2 != 0 ) return false;

		liwVertexStart.Add( meshVertexList[ indexPairTopologyVertex[ 0 ] ] );
		liwVertexEnd.Add( meshVertexList[ indexPairTopologyVertex[ 1 ] ] );

		bContinue = true;
		bCorrectPath = true;

		do {
			if ( bOneRingClosed || !bCorrectPath ) {
				bContinue = false;
				continue;
			}

			indexPairTopologyVertex[ 0 ] = ( *liVertexPaths )[ 0 ].iElementIndex;
			indexPairTopologyVertex[ 1 ] = ( *liVertexPaths )[ ( *liVertexPaths ).GetSize( ) - 1 ].iElementIndex;

			liVertexAux.RemoveAll( );
			for ( ul = 0; ul < ( *liVertexPaths ).GetSize( ); ul++ )
				liVertexAux.Add( ( *liVertexPaths )[ ul ].iElementIndex );

			meshVertexList[ ( *liVertexPaths )[ 0 ].iElementIndex ]->FindPolyEdgeBetween( meshVertexList[ ( *liVertexPaths )[ 1 ].iElementIndex ], iwEdge );

			liwVertexStart.RemoveAll( );
			liwVertexStart.Add( meshVertexList[ ( *liVertexPaths )[ 0 ].iElementIndex ] );
			liwVertexEnd.RemoveAll( );
			liwVertexEnd.Add( meshVertexList[ ( *liVertexPaths )[ ( *liVertexPaths ).GetSize( ) - 1 ].iElementIndex ] );

			liwVertexStartCopy = liwVertexStart;
			liwVertexEndCopy = liwVertexEnd;
			bOneRingClosed = false;

			liwEdges = GetNextEdge_Iterative( liVertexPaths, &liwVertexStart, &liwVertexEnd );
			if ( ( *liVertexPaths ).GetSize( ) > 2 && ( *liVertexPaths )[ 0 ].iElementIndex == ( *liVertexPaths )[ ( *liVertexPaths ).GetSize( ) - 1 ].iElementIndex ) {
				bOneRingClosed = true;
				continue;
			}
			if ( liwEdges.GetSize( ) == 0 ) {
				bOneRingClosed = false;
				bCorrectPath = false;
				bContinue = false;
				continue;
			}

			if ( ( *liVertexPaths )[ 0 ].iElementIndex == ( *liVertexPaths )[ ( *liVertexPaths ).GetSize( ) - 1 ].iElementIndex ) {
				bOneRingClosed = true;
				bContinue = false;
				continue;
			}

			if ( liwEdges.GetSize( ) > 0 ) {
				if ( liwVertexStartCopy[ 0 ] != liwVertexStart[ 0 ] ) // Se ha añadido por el principio
				{
					dataIntIntForVertexPath.iElementIndex = liwVertexStart[ 0 ]->GetIndexExt( );
					bFounded = ( *liVertexPaths ).FindElement( dataIntIntForVertexPath, ulIndex );
					if ( bFounded ) {
						// El valor añadido al principio ya esta en la lista por lo tanto se cierra el anillo.
						if ( ( *liVertexPaths )[ ( *liVertexPaths ).GetSize( ) - 1 ].iElementIndex == liwVertexStart[ 0 ]->GetIndexExt( ) ) {
							( *liVertexPaths ).InsertAt( 0, ( *liVertexPaths )[ ( *liVertexPaths ).GetSize( ) - 1 ] );
							bOneRingClosed = true;
							bContinue = false;
							continue;
						}

						// Hay que borrar la lista de vertices que no estan incluidos en el anillo
						dataIntIntForVertexPath.iElementIndex = indexPairTopologyVertex[ 1 ];
						bFounded = ( *liVertexPaths ).FindElement( dataIntIntForVertexPath, ulIndexIni );
						if ( ulIndexIni < ulIndex ) {
							( *liVertexPaths ).RemoveAt( ulIndex, ( *liVertexPaths ).GetSize( ) - ulIndex );
							if ( ( *liVertexPaths )[ ( *liVertexPaths ).GetSize( ) - 1 ].iElementIndex != ( *liVertexPaths )[ 0 ].iElementIndex ) {
								if ( meshVertexList[ ( *liVertexPaths )[ ( *liVertexPaths ).GetSize( ) - 1 ].iElementIndex ]->FindPolyEdgeBetween( meshVertexList[ ( *liVertexPaths )[ 0 ].iElementIndex ], iwEdgeAux ) != IW_SUCCESS || iwEdgeAux == NULL ) {
									bOneRingClosed = false;
									bCorrectPath = true;
									bContinue = true;
									( *liVertexPaths )[ 0 ].iNumBranches++; // para que no continue por aqui y continue por el otro lado
									continue;
								}
								( *liVertexPaths ).Add( ( *liVertexPaths )[ 0 ] );
							}
							bOneRingClosed = true;
							bContinue = false;
							continue;
						} else {
							( *liVertexPaths ).RemoveAt( 0, ulIndex );
							if ( ( *liVertexPaths )[ ( *liVertexPaths ).GetSize( ) - 1 ] != ( *liVertexPaths )[ 0 ] ) {
								iwStatus = meshVertexList[ ( *liVertexPaths )[ ( *liVertexPaths ).GetSize( ) - 1 ].iElementIndex ]->FindPolyEdgeBetween( meshVertexList[ ( *liVertexPaths )[ 0 ].iElementIndex ], iwEdge );
								if ( ( *liVertexPaths ).GetSize( ) <= 2 || iwStatus != IW_SUCCESS || iwEdge == NULL ) {
									bOneRingClosed = false;
									bCorrectPath = true;
									bContinue = true;
									( *liVertexPaths )[ 0 ].iNumBranches++; // para que no continue por aqui y continue por el otro lado
									continue;
								}
								( *liVertexPaths ).Add( ( *liVertexPaths )[ 0 ] );
							}
							if ( ( *liVertexPaths ).GetSize( ) <= 3 ) {
								( *liVertexPaths ).RemoveAll( );
								bOneRingClosed = false;
								bCorrectPath = false;
								bContinue = false;
								continue;
							}
							bOneRingClosed = true;
							bContinue = false;
							continue;
						}
					}

					dataIntIntForVertexPath.iNumBranches = 0;
					dataIntIntForVertexPath.iElementIndex = liwVertexStart[ 0 ]->GetIndexExt( );
					( *liVertexPaths ).InsertAt( 0, dataIntIntForVertexPath );

					iwEdge = liwEdges[ 0 ];
				}

				if ( liwVertexEndCopy[ 0 ] != liwVertexEnd[ 0 ] ) {
					dataIntIntForVertexPath.iElementIndex = liwVertexEnd[ 0 ]->GetIndexExt( );
					bFounded = ( *liVertexPaths ).FindElement( dataIntIntForVertexPath, ulIndexAux );
					if ( bFounded ) {
						iwStatus = meshVertexList[ ( *liVertexPaths )[ ( *liVertexPaths ).GetSize( ) - 1 ].iElementIndex ]->FindPolyEdgeBetween( meshVertexList[ ( *liVertexPaths )[ 0 ].iElementIndex ], iwEdge );
						if ( iwStatus != IW_SUCCESS || iwEdge == NULL ) {
							bOneRingClosed = false;
							bCorrectPath = false;
							bContinue = false;
							continue;
						}
						( *liVertexPaths ).Add( ( *liVertexPaths )[ 0 ] );
						bOneRingClosed = true;
						bContinue = false;
						continue;
					}

					dataIntIntForVertexPath.iNumBranches = 0;
					dataIntIntForVertexPath.iElementIndex = liwVertexEnd[ 0 ]->GetIndexExt( );
					( *liVertexPaths ).Add( dataIntIntForVertexPath );

					iwEdge = liwEdges[ 0 ];
				}
			}

			bContinue = false;
			if ( bCorrectPath ) bCorrectPath = CheckEndingConditions( iSelectedEdge, &( *liVertexPaths ), bContinue );

			if ( !bCorrectPath ) {
				( *liVertexPaths ).RemoveAll( );
				bContinue = true;
			}

			if ( bContinue && bCorrectPath ) iwEdge = liwEdges[ 0 ];

		} while ( bContinue );
	} catch ( Exception &e ) {
#ifdef _DEBUG
		_MessageBox( e.ToString( ), _GetTranslatedString( "IDS_WARNING" ), mtWarning, TMsgDlgButtons( ) << mbOK );
#endif
	}

	return bCorrectPath;
}

//-------------------------------------------------------------------------------------
// Función para obtener un anillo de caras a partir de la conectividad de las mismas.
// ulSelectedFace - Cara seleccionada de la topología de la malla
// bFirstEdge - Si true entonces empieza a buscar el anillo a partir de la primera arista de la lista de aristas de la cara, si false entonces empieza a buscar a partir de la segunda arista
// liFacesPaths - Devuelve la lista de caras del anillo de caras que se calcula
// oneRingFacesSearchMethod - Método de búsqueda de la cara siguiente en el anillo
// True si ha encontrado un anillo, False en caso contrario
bool TPBrepData::TryOneRingConnectedFaces_ForFaces_Iterative( ULONG ulSelectedFace, bool bFirstEdge, IwTA<TStructFaces> *liFacesPaths, OneRingFacesSearchMethod oneRingFacesSearchMethod, int indexEdge )
{
	bool bCorrectPath, bOneRingClosed, bContinue, bFirstDirection, bFounded;
	ULONG ulIndex;
	IwTA<IwPolyEdge *> liwEdgesFromFace, liwEdgeStart, liwEdgeEnd, liwNextEdges;
	IwTA<IwPolyVertex *> liwVertexListAtEnd;
	IwTA<IwPolyFace *> liwFacesConnected;
	IwPolyFace *iwSelectedFace, *iwFace;
	IwPolyEdge *iwEdgeOpposite, *iwPreviousEdge;
	IwTA<TStructFaces> lNewPath;
	TStructFaces structFaces;

	bOneRingClosed = false;
	bCorrectPath = false;

	try {
		if ( ulSelectedFace >= PBrepFaces.GetSize( ) ) return false;

		iwSelectedFace = PBrepFaces[ ulSelectedFace ];

		if ( liFacesPaths == NULL || ( *liFacesPaths ).GetSize( ) == 0 ) {
			structFaces.ulIndexOfFace = ulSelectedFace;
			structFaces.iNumOfPossiblePaths = 0;
			iwSelectedFace->GetPolyEdges( liwEdgesFromFace );

			( *liFacesPaths ) = lNewPath;
			if ( indexEdge < 0 ) {
				if ( bFirstEdge ) structFaces.iwPolyEdgeSharedWithPreviousFace = liwEdgesFromFace[ 0 ];
				else
					structFaces.iwPolyEdgeSharedWithPreviousFace = liwEdgesFromFace[ 1 ];
			} else {
				if ( indexEdge < 0 ) return false;
				structFaces.iwPolyEdgeSharedWithPreviousFace = PBrepEdges[ indexEdge ];
			}

			iwEdgeOpposite = GetOppositeEdgeFromFace( structFaces.iwPolyEdgeSharedWithPreviousFace, iwSelectedFace, true );
			if ( iwEdgeOpposite == NULL ) return false;

			structFaces.iwPolyEdgeSharedWithNextFace = iwEdgeOpposite;
			( *liFacesPaths ).Add( structFaces );
		}

		PBrepFaces[ ( *liFacesPaths )[ 0 ].ulIndexOfFace ]->GetPolyEdges( liwEdgesFromFace );

		iwFace = iwSelectedFace;
		liwEdgeStart.Add( liwEdgesFromFace[ 0 ] );
		iwEdgeOpposite = liwEdgesFromFace[ 0 ]->GetCCWPolyEdge( );
		iwEdgeOpposite = iwEdgeOpposite->GetCCWPolyEdge( );
		liwEdgeEnd.Add( iwEdgeOpposite );

		iwPreviousEdge = liwEdgeStart[ 0 ];
		bContinue = true;
		bCorrectPath = true;
		bFirstDirection = true;

		do {
			if ( bOneRingClosed || !bCorrectPath ) {
				if ( !bCorrectPath ) {
					// Si el path no es correcto y lo estaba metiendo el usuario que hacemos??? continuamos o cancelamos?
					return true;
				}

				if ( !bOneRingClosed ) {
					( *liFacesPaths ).RemoveAll( );
					return false;
				}

				bCorrectPath = true;
				bOneRingClosed = false;
			}

			if ( bFirstDirection ) {
				iwFace = PBrepFaces[ ( *liFacesPaths )[ ( *liFacesPaths ).GetSize( ) - 1 ].ulIndexOfFace ];
				iwPreviousEdge = ( *liFacesPaths )[ ( *liFacesPaths ).GetSize( ) - 1 ].iwPolyEdgeSharedWithPreviousFace;
			} else {
				iwPreviousEdge = ( *liFacesPaths )[ 0 ].iwPolyEdgeSharedWithNextFace;
				iwFace = PBrepFaces[ ( *liFacesPaths )[ 0 ].ulIndexOfFace ];
			}

			liwNextEdges = GetNextEdge( iwFace, iwPreviousEdge, oneRingFacesSearchMethod );

			if ( liwNextEdges.GetSize( ) == 0 ) {
				if ( bFirstDirection ) {
					bFirstDirection = false;
					iwPreviousEdge = ( *liFacesPaths )[ 0 ].iwPolyEdgeSharedWithNextFace;
					if ( iwPreviousEdge == NULL ) {
						bOneRingClosed = false;
						bContinue = false;
						continue;
					}
					iwFace = PBrepFaces[ ( *liFacesPaths )[ 0 ].ulIndexOfFace ];

					liwNextEdges = GetNextEdge( iwFace, iwPreviousEdge, oneRingFacesSearchMethod );
				}

				if ( liwNextEdges.GetSize( ) == 0 ) {
					bOneRingClosed = false;
					bContinue = false;
					continue;
				}
			}

			if ( liwNextEdges.GetSize( ) > 1 ) {
				bOneRingClosed = false;
				bContinue = false;
				continue;
			}

			iwPreviousEdge = liwNextEdges[ 0 ];
			liwFacesConnected = GetConnectedFacesFromEdge( liwNextEdges[ 0 ] );
			bFounded = liwFacesConnected.FindElement( iwFace, ulIndex );
			if ( !bFounded ) {
				bOneRingClosed = false;
				bContinue = false;
				continue;
			}
			liwFacesConnected.RemoveAt( ulIndex );

			iwFace = liwFacesConnected[ 0 ];

			structFaces.ulIndexOfFace = iwFace->GetIndexExt( );
			structFaces.iwPolyEdgeSharedWithPreviousFace = liwNextEdges[ 0 ];
			structFaces.iwPolyEdgeSharedWithNextFace = iwPreviousEdge;
			structFaces.iNumOfPossiblePaths = 0;
			if ( bFirstDirection ) ( *liFacesPaths ).Add( structFaces );
			else
				( *liFacesPaths ).InsertAt( 0, structFaces );

			if ( bCorrectPath ) bCorrectPath = CheckEndingConditions_FacesRing( &( *liFacesPaths ), bContinue, bOneRingClosed );

			if ( !bCorrectPath ) bCorrectPath = false;

		} while ( bContinue );

		return bCorrectPath;
	} catch ( Exception &e ) {
#ifdef _DEBUG
		_MessageBox( e.ToString( ), _GetTranslatedString( "IDS_WARNING" ), mtWarning, TMsgDlgButtons( ) << mbOK );
#endif
	}

	return bCorrectPath;
}

//-------------------------------------------------------------------------------------
// Función para obtener la arista siguiente a la lista de vertices que se le pasa por parámetro. Si no la encuentra por el principio entonces busca por el final
// liVertexPaths - Lista de vértices actual
// liwTopologyVertexAtStart - Entrada: Vertice inicial. Salida: Lista de vértices encontrados al principio si fuera el caso o el mismo vértice
// liwTopologyVertexAt - Entrada: Vertice final. Salida: Lista de vértices encontrados al final si fuera el caso o el mismo vértice
// Devuelve la lista de aristas siguiente. De momento solo una.
IwTA<IwPolyEdge *> TPBrepData::GetNextEdge_Iterative( IwTA<TDataIntIntForVertexPaths> *liVertexPaths, IwTA<IwPolyVertex *> *liwTopologyVertexAtStart, IwTA<IwPolyVertex *> *liwTopologyVertexAtEnd )
{
	IwTA<IwPolyEdge *> liwNextEdges, liEdgesNULL;
	IwTA<IwPolyVertex *> liwTopologyVertexAtStartCopy, liwTopologyVertexAtEndCopy;

	try {
		// Primero recorremos la mayor cantidad de camino posible por ambos lados. Si previamente se hubiera encontrado alguna bifurcacion habria que comprobar el ángulo del plano de acumulación
		// por si hubiera que descartar esa bifurcación.
		// Buscamos por el principio

		if ( ( *liVertexPaths )[ 0 ].iNumBranches == 0 ) // Si en el anterior vertice no ha habido bifurcacion
		{
			liwTopologyVertexAtStartCopy = ( *liwTopologyVertexAtStart );
			liwNextEdges = GetNextEdgeAtStart_Iterative( liVertexPaths, liwTopologyVertexAtStart );
			if ( ( *liwTopologyVertexAtStart ).GetSize( ) == 1 && ( *liwTopologyVertexAtStart )[ 0 ] != liwTopologyVertexAtStartCopy[ 0 ] ) return liwNextEdges;
			( *liVertexPaths )[ 0 ].iNumBranches++; // para que no vuelva a intentarlo por aqui
		}

		// Buscamos por el final
		if ( ( *liVertexPaths )[ ( *liVertexPaths ).GetSize( ) - 1 ].iNumBranches == 0 ) // Si en el anterior vertice no ha habido bifurcacion
		{
			liwTopologyVertexAtEndCopy = ( *liwTopologyVertexAtEnd );
			liwNextEdges = GetNextEdgeAtEnd_Iterative( liVertexPaths, liwTopologyVertexAtEnd );
			if ( ( *liwTopologyVertexAtEnd ).GetSize( ) == 1 && ( *liwTopologyVertexAtEnd )[ 0 ] != liwTopologyVertexAtEndCopy[ 0 ] ) return liwNextEdges;
			( *liVertexPaths )[ ( *liVertexPaths ).GetSize( ) - 1 ].iNumBranches++;
		}

		// De momento no miramos mas
		return liwNextEdges;
	} catch ( Exception &e ) {
#ifdef _DEBUG
		_MessageBox( e.ToString( ), _GetTranslatedString( "IDS_WARNING" ), mtWarning, TMsgDlgButtons( ) << mbOK );
#endif
	}

	return liwNextEdges;
}

//-------------------------------------------------------------------------------------
// Función para obtener la arista siguiente a la lista de vertices que se le pasa por parámetro. Busca por el principio
// liVertexPaths - Lista de vértices actual
// liwTopologyVertexAtStart - Entrada: Vertice inicial. Salida: Lista de vértices encontrados al principio si fuera el caso o el mismo vértice
// Devuelve la lista de aristas siguiente. De momento solo una.
IwTA<IwPolyEdge *> TPBrepData::GetNextEdgeAtStart_Iterative( IwTA<TDataIntIntForVertexPaths> *liVertexPaths, IwTA<IwPolyVertex *> *liwTopologyVertexAtStart )
{
	bool bFoundedEdge, bFounded;
	ULONG ulIndex;
	T3DPoint pto;
	T3DVector vectNew;
	T3DPlane plnNew, plnFromLastVertex;
	IwPolyVertex *iwVertexStart, *iwPreviousVertex, *iwNextVertex, *iwVertexFromPreviousEdge;
	IwPolyEdge *iwLastEdge, *iwEdge;
	IwTA<IwPolyFace *> liwFacesStart, liwFacesAux, liwFaces, liwFaces2;
	IwTA<IwPolyVertex *> liwVertexAtStart, liwVertexAtStartAux, liwVertexToContinue;
	IwTA<IwPolyEdge *> liwNextEdgeAtStart, liwEdges, liEdgesNULL;

	plnFromLastVertex = T3DPlane( plNone );
	bFoundedEdge = false;
	try {
		if ( ( *liwTopologyVertexAtStart ).GetSize( ) != 1 ) return liEdgesNULL;

		iwVertexStart = ( *liwTopologyVertexAtStart )[ 0 ];

		iwVertexFromPreviousEdge = PBrepVertexs[ ( *liVertexPaths )[ 1 ].iElementIndex ];
		iwVertexStart->FindPolyEdgeBetween( iwVertexFromPreviousEdge, iwLastEdge );

		liwFacesStart = GetConnectedFacesFromEdge( iwLastEdge );

		iwVertexStart->GetAdjacentVertices( liwVertexAtStart );
		if ( liwVertexAtStart.GetSize( ) != 0 ) {
			// Si el numero de aristas es par entonces continuamos por la arista opuesta a la actual
			if ( ( *liVertexPaths ).GetSize( ) > 1 && ( *liVertexPaths )[ 0 ].iNumBranches == 0 ) {
				iwPreviousVertex = PBrepVertexs[ ( *liVertexPaths )[ 1 ].iElementIndex ];

				bFounded = liwVertexAtStart.FindElement( iwPreviousVertex, ulIndex );
				if ( ( liwVertexAtStart.GetSize( ) % 2 ) == 0 && bFounded ) {
					iwEdge = GetOppositeEdgeFromVertex( iwLastEdge, iwVertexStart );
					if ( iwEdge != NULL ) bFoundedEdge = true;

					if ( bFoundedEdge ) {
						if ( iwEdge->GetStartVertex( ) != iwVertexStart ) iwNextVertex = iwEdge->GetStartVertex( );
						else
							iwNextVertex = iwEdge->GetEndVertex( );
						liwNextEdgeAtStart.RemoveAll( );
						( *liwTopologyVertexAtStart ).RemoveAll( );
						liwNextEdgeAtStart.Add( iwEdge );
						( *liwTopologyVertexAtStart ).Add( iwNextVertex );
						return liwNextEdgeAtStart;
					}
				}
				return liEdgesNULL;
			}

			return liEdgesNULL;
		}
	} catch ( Exception &e ) {
#ifdef _DEBUG
		_MessageBox( e.ToString( ), _GetTranslatedString( "IDS_WARNING" ), mtWarning, TMsgDlgButtons( ) << mbOK );
#endif
	}

	return liwNextEdgeAtStart;
}

//-------------------------------------------------------------------------------------
// Función para obtener la arista siguiente a la lista de vertices que se le pasa por parámetro. Busca por el final
// liVertexPaths - Lista de vértices actual
// liwTopologyVertexAtEnd - Entrada: Vertice final. Salida: Lista de vértices encontrados al final si fuera el caso o el mismo vértice
// Devuelve la lista de aristas siguiente. De momento solo una.
IwTA<IwPolyEdge *> TPBrepData::GetNextEdgeAtEnd_Iterative( IwTA<TDataIntIntForVertexPaths> *liVertexPaths, IwTA<IwPolyVertex *> *liwTopologyVertexAtEnd )
{
	bool bFoundedEdge, bFounded;
	ULONG ulIndex;
	IwTA<IwPolyFace *> liwFacesStart, liwFacesAux;
	IwPolyVertex *iwVertexEnd1, *iwPreviousVertex, *iwNextVertex;
	IwTA<IwPolyVertex *> liwVertexAtEnd;
	IwPolyEdge *iwLastEdge, *iwEdge;
	IwTA<IwPolyEdge *> liwNextEdgeAtEnd, liEdgesNULL;
	IwTA<TDataIntIntForVertexPaths> ldataIntIntForVertexPaths;

	bFoundedEdge = false;
	try {
		if ( ( *liwTopologyVertexAtEnd ).GetSize( ) != 1 ) return liEdgesNULL;

		iwVertexEnd1 = ( *liwTopologyVertexAtEnd )[ 0 ];

		iwVertexEnd1->FindPolyEdgeBetween( PBrepVertexs[ ( *liVertexPaths )[ ( *liVertexPaths ).GetSize( ) - 2 ].iElementIndex ], iwLastEdge );
		liwFacesStart = GetConnectedFacesFromEdge( iwLastEdge );

		iwVertexEnd1->GetAdjacentVertices( liwVertexAtEnd );

		if ( liwVertexAtEnd.GetSize( ) > 0 ) {
			if ( ( *liVertexPaths ).GetSize( ) > 1 && ( *liVertexPaths )[ ( *liVertexPaths ).GetSize( ) - 1 ].iNumBranches == 0 ) {
				iwPreviousVertex = PBrepVertexs[ ( *liVertexPaths )[ ( *liVertexPaths ).GetSize( ) - 2 ].iElementIndex ];
				bFounded = liwVertexAtEnd.FindElement( iwPreviousVertex, ulIndex );
				if ( ( liwVertexAtEnd.GetSize( ) % 2 ) == 0 && bFounded ) {
					if ( liwVertexAtEnd.GetSize( ) != 4 ) {
						bFounded = false;
					}
					iwEdge = GetOppositeEdgeFromVertex( iwLastEdge, iwVertexEnd1 );
					if ( iwEdge != NULL ) bFoundedEdge = true;
					if ( bFoundedEdge ) {
						if ( iwEdge->GetStartVertex( ) != iwVertexEnd1 ) iwNextVertex = iwEdge->GetStartVertex( );
						else
							iwNextVertex = iwEdge->GetEndVertex( );

						iwVertexEnd1->FindPolyEdgeBetween( iwNextVertex, iwEdge );
						liwNextEdgeAtEnd.RemoveAll( );
						( *liwTopologyVertexAtEnd ).RemoveAll( );
						liwNextEdgeAtEnd.Add( iwEdge );
						( *liwTopologyVertexAtEnd ).Add( iwNextVertex );
						return liwNextEdgeAtEnd;
					}
				}
				return liEdgesNULL;
			}

			// De momendo evitamos mas calculos pq no esta hecho aun la seleccion de caminos a mitad de calculo
			return liEdgesNULL;
		}
	} catch ( Exception &e ) {
#ifdef _DEBUG
		_MessageBox( e.ToString( ), _GetTranslatedString( "IDS_WARNING" ), mtWarning, TMsgDlgButtons( ) << mbOK );
#endif
	}

	return liwNextEdgeAtEnd;
}

//-------------------------------------------------------------------------------------

bool TPBrepData::GetBoundaryEdgesConnected( int iSelectedEdge, IwTA<TDataIntIntForVertexPaths> *liVertexPaths )
{
	int i;
	IwPolyEdge *edge;
	IwPolyVertex *vertex1, *vertex2, *nextvertex, *prevvertex;
	IwTA<IwPolyEdge *> edges, edgestoreview;
	TDataIntIntForVertexPaths data;
	TInteger_List edgesUserIndex2List;

	if ( !liVertexPaths ) return false;
	liVertexPaths->RemoveAll( );

	if ( iSelectedEdge < 0 || (int) PBrepEdges.GetSize( ) <= iSelectedEdge ) return false;

	edge = PBrepEdges[ iSelectedEdge ];
	if ( !edge->IsBoundary( ) ) return false;

	vertex1 = edge->GetStartVertex( );
	vertex2 = edge->GetEndVertex( );
	edges = GetAdjacentEdges( edge );

	data.iElementIndex = vertex1->GetIndexExt( );
	data.iNumBranches = 0;
	liVertexPaths->Add( data );

	data.iElementIndex = vertex2->GetIndexExt( );
	liVertexPaths->Add( data );

	GetListsUserIndex2( 0, &edgesUserIndex2List, 0 );
	InitUserIndex2( false, true, false );

	do {
		if ( edgestoreview.GetSize( ) ) {
			edges = GetAdjacentEdges( edgestoreview[ 0 ] );
			edgestoreview.RemoveAt( 0 );
		}
		for ( i = 0; i < (int) edges.GetSize( ); i++ ) {
			if ( edges[ i ]->GetUserIndex2( ) ) continue;
			if ( edges[ i ]->IsBoundary( ) ) {
				nextvertex = 0;
				prevvertex = 0;
				if ( vertex2 == edges[ i ]->GetEndVertex( ) ) nextvertex = edges[ i ]->GetStartVertex( );
				else if ( vertex2 == edges[ i ]->GetStartVertex( ) )
					nextvertex = edges[ i ]->GetEndVertex( );
				else if ( vertex1 == edges[ i ]->GetEndVertex( ) )
					prevvertex = edges[ i ]->GetStartVertex( );
				else if ( vertex1 == edges[ i ]->GetStartVertex( ) )
					prevvertex = edges[ i ]->GetEndVertex( );

				if ( nextvertex || prevvertex ) {
					if ( prevvertex ) {
						data.iElementIndex = prevvertex->GetIndexExt( );
						liVertexPaths->InsertAt( 0, data );
						vertex1 = prevvertex;
					} else {
						data.iElementIndex = nextvertex->GetIndexExt( );
						liVertexPaths->Add( data );
						vertex2 = nextvertex;
					}
					edges[ i ]->SetUserIndex2( 1 );
					edgestoreview.Add( edges[ i ] );
				}
			}
		}
	} while ( edgestoreview.GetSize( ) > 0 );

	SetListsUserIndex2( 0, &edgesUserIndex2List, 0 );

	return false;
}

//-------------------------------------------------------------------------------------
// Función para ordenar una lista de vértices en función de la conectividad de aristas
// liwVertexActual - Lista de vértices actual
// liwFaces - Lista de caras correspondiente a la lista de vértices
// bClockWise - Devuelve si la lista es clockwise o no ( Contra clockwise )
// Devuelve la lista de aristas ordenada.
IwTA<IwPolyVertex *> TPBrepData::OrderListOfVertexes( IwTA<IwPolyVertex *> *liwVertexActual, IwTA<IwPolyFace *> *liwFaces, bool &bClockWise )
{
	int ii, j;
	ULONG uli;
	IwPolyVertex *iwVertexAux;
	IwTA<IwPolyVertex *> liwVertexNew, liwVertexRemain;
	IwTA<IwPolyEdge *> meshEdgeList;
	IwTA<IwPolyVertex *> meshTopologyVertex;

	bClockWise = true;

	try {
		if ( liwVertexActual->GetSize( ) == 0 ) return liwVertexNew;

		meshTopologyVertex = PBrepVertexs;
		if ( meshTopologyVertex.GetSize( ) == 0 ) return liwVertexNew;

		meshEdgeList = PBrepEdges;
		if ( meshEdgeList.GetSize( ) == 0 ) return liwVertexNew;

		liwVertexNew = *liwVertexActual;
		liwVertexRemain = *liwVertexActual;

		// Hay que empezar con un vertice que solo tenga 2 posibles caminos para seguir y asi obtener el clockwise correcto
		GetFirstValidVertexFromList( &liwVertexNew, ii, bClockWise );
		liwVertexNew = SetStartIndex( liwVertexNew, ii );

		uli = 0;
		do {
			j = GetNextVertexFromList( &liwVertexNew, uli, liwFaces, bClockWise );
			if ( j != -1 ) {
				iwVertexAux = liwVertexNew[ uli + 1 ];
				liwVertexNew[ uli + 1 ] = liwVertexNew[ j ];
				liwVertexNew[ j ] = iwVertexAux;
			} else
				liwVertexNew.RemoveAt( uli + 1, liwVertexNew.GetSize( ) - uli - 1 );
			uli++;
		} while ( uli < liwVertexNew.GetSize( ) - 1 && j != -1 );
	} catch ( Exception &e ) {
#ifdef _DEBUG
		_MessageBox( e.ToString( ), _GetTranslatedString( "IDS_WARNING" ), mtWarning, TMsgDlgButtons( ) << mbOK );
#endif
	}

	return liwVertexNew;
}

//-------------------------------------------------------------------------------------
// Función usada previamente al caso de ordenar una lista de vértices.
// Hay que empezar con un vertice que solo tenga 2 posibles caminos para seguir y asi obtener el clockwise correcto
// liwVertex - Lista de vértices actual
// iFirstVertex - Vértice encontrado si el resultado fuera satisfactorio
// bClockWise - Devuelve si la lista es clockwise o no ( Contra clockwise )
// True en caso de haber encontrado una solución. False en caso contrario
bool TPBrepData::GetFirstValidVertexFromList( IwTA<IwPolyVertex *> *liwVertex, int &iFirstVertex, bool &bClockWise )
{
	bool bFounded, bFounded2;
	int k, iNumVertexAtExtrems;
	ULONG uli, ulj, ulFoundIndex, ulFoundIndex2;
	T3DPoint pt3dOrg, *lpt3d;
	T3DVector vect3d;
	T3DPlane pln;
	IwVector3d iwPt3dA, iwPt3dB, iwPt3dC, iwPt3dD;
	IwTA<IwPolyFace *> liwFaces;
	IwTA<IwPolyVertex *> liwVertexForFindFace, liwVertexAux, liwVertexOfFace;

	iFirstVertex = 0;
	bClockWise = false;

	try {
		if ( PBrepVertexs.GetSize( ) == 0 ) return false;
		if ( PBrepEdges.GetSize( ) == 0 ) return false;

		for ( uli = 0; uli < ( *liwVertex ).GetSize( ); uli++ ) {
			iNumVertexAtExtrems = 0;
			liwVertexForFindFace.RemoveAll( );
			( *liwVertex )[ uli ]->GetAdjacentVertices( liwVertexAux );
			for ( ulj = 0; ulj < liwVertexAux.GetSize( ); ulj++ ) {
				bFounded = ( *liwVertex ).FindElement( liwVertexAux[ ulj ], ulFoundIndex );
				if ( bFounded ) {
					iNumVertexAtExtrems++;
					liwVertexForFindFace.Add( ( *liwVertex )[ ulFoundIndex ] );
				}
			}
			if ( iNumVertexAtExtrems == 2 ) {
				iFirstVertex = uli;
				liwFaces = GetConnectedFacesFromVertex( ( *liwVertex )[ uli ] );

				for ( ulj = 0; ulj < liwFaces.GetSize( ); ulj++ ) {
					liwFaces[ ulj ]->GetPolyVertices( liwVertexAux );
					bFounded = liwVertexAux.FindElement( liwVertexForFindFace[ 0 ], ulFoundIndex );
					bFounded2 = liwVertexAux.FindElement( liwVertexForFindFace[ 1 ], ulFoundIndex2 );
					if ( bFounded && bFounded2 ) {
						pt3dOrg = T3DPoint( 0, 0, 0 );
						iwPt3dA = liwFaces[ ulj ]->GetNormal( );
						vect3d.size = T3DSize( iwPt3dA.x, iwPt3dA.y, iwPt3dA.z );
						pln = T3DPlane( pt3dOrg, vect3d );

						liwFaces[ ulj ]->GetPolyVertices( liwVertexOfFace );
						lpt3d = new T3DPoint[ liwVertexOfFace.GetSize( ) ];
						for ( k = 0; k < (int) liwVertexOfFace.GetSize( ); k++ )
							lpt3d[ k ] = T3DPoint( liwVertexOfFace[ k ]->GetPointPtr( )->x, liwVertexOfFace[ k ]->GetPointPtr( )->y, liwVertexOfFace[ k ]->GetPointPtr( )->z );

						bClockWise = _IsClockWise( (int) liwVertexOfFace.GetSize( ), lpt3d, pln );
						delete[] lpt3d;
						return true;
					}
				}
			}
		}
	} catch ( Exception &e ) {
#ifdef _DEBUG
		_MessageBox( e.ToString( ), _GetTranslatedString( "IDS_WARNING" ), mtWarning, TMsgDlgButtons( ) << mbOK );
#endif
	}

	return false;
}

//-------------------------------------------------------------------------------------
// Función usada para el caso de ordenar una lista de vértices. Busca el siguiente vértice al definido como actual
// liwVertexActual - Lista de vértices actual
// iCurrentVertex - Vértice definido como actual<param>
// liwFacesOrig - Lista de caras originales correspondiente a la lista de vértices
// bClockWise - Devuelve si la lista es clockwise o no ( Contra clockwise )
// Devuelve la posición al que debería ser el siguiente vértice en la lista
int TPBrepData::GetNextVertexFromList( IwTA<IwPolyVertex *> *liwVertexActual, int iCurrentVertex, IwTA<IwPolyFace *> *liwFacesOrig, bool bClockWise )
{
	int iNextVertex, ii, ij;
	bool bFoundedVertex, bFoundedEdge, bIsFaceClockWise, bFounded;
	int iNumVertexAtExtrems;
	T3DPoint pt3dOrg, *lpt3d;
	T3DVector vect;
	T3DPlane pln;
	ULONG ulFoundIndex, ulk, ulVertex, ulVertexAux;
	IwVector3d iwVector3D;
	IwPolyEdge *iwEdge, *iwEdge_Simmetric;
	IwPolyVertex *iwNextVertex, *iwVertex;
	IwTA<IwPolyVertex *> liwVertexProbableNext, liwVertexAux, liwVertex, liwVertexOfFace;
	IwTA<IwPolyFace *> liwFaces;
	IwTA<IwPolyEdge *> liwEdges;

	iNextVertex = -1;
	bFoundedVertex = false;

	try {
		if ( PBrepVertexs.GetSize( ) == 0 ) return iNextVertex;
		if ( PBrepEdges.GetSize( ) == 0 ) return iNextVertex;

		( *liwVertexActual )[ iCurrentVertex ]->GetAdjacentVertices( liwVertexProbableNext );
		iNumVertexAtExtrems = 0;

		for ( ii = (int) liwVertexProbableNext.GetSize( ) - 1; ii >= 0; ii-- ) {
			if ( liwVertexProbableNext.GetSize( ) == 0 ) break;
			// Primero quitamos de los probables los que no estan en la lista
			bFounded = ( *liwVertexActual ).FindElement( liwVertexProbableNext[ ii ], ulFoundIndex );
			if ( !bFounded ) {
				liwVertexProbableNext.RemoveAt( ii );
				continue;
			}
			// Luego, de esos probables eliminamos los que ya se hayan recorrido
			if ( (int) ulFoundIndex < iCurrentVertex ) {
				liwVertexProbableNext.RemoveAt( ii );
				continue;
			}
		}

		if ( liwVertexProbableNext.GetSize( ) == 1 ) {
			bFounded = ( *liwVertexActual ).FindElement( liwVertexProbableNext[ 0 ], ulFoundIndex );
			return ulFoundIndex;
		}

		// Y por ultimo, de los que queden en la lista sumamos el numero de vertices con el que estan conectados para quedarnos con el que nos interese
		for ( ii = liwVertexProbableNext.GetSize( ) - 1; ii >= 0; ii-- ) {
			if ( liwVertexProbableNext.GetSize( ) == 0 ) break;
			// Primero miramos si la arista del vertice probable junto con el anterior forma parte de una de las caras de la lista
			( *liwVertexActual )[ iCurrentVertex ]->FindPolyEdgeBetween( liwVertexProbableNext[ ii ], iwEdge );
			bFoundedEdge = false;
			for ( ij = 0; ij < (int) ( *liwFacesOrig ).GetSize( ); ij++ ) {
				( *liwFacesOrig )[ ij ]->GetPolyEdges( liwEdges );
				if ( liwEdges.FindElement( iwEdge, ulFoundIndex ) > 0 ) {
					bFoundedEdge = true;
					break;
				} else {
					iwEdge_Simmetric = iwEdge->GetSymmetricPolyEdge( );
					if ( liwEdges.FindElement( iwEdge_Simmetric, ulFoundIndex ) > 0 ) {
						iwEdge = iwEdge_Simmetric;
						bFoundedEdge = true;
						break;
					}
				}
			}
			if ( !bFoundedEdge ) continue;

			// A partir del sentido que se le pasa se busca el vertice que cumpla ese sentido
			liwFaces = GetConnectedFacesFromVertex( liwVertexProbableNext[ ii ] );

			// Borramos las caras que no esten en las originales
			for ( ij = (int) liwFaces.GetSize( ) - 1; ij >= 0; ij-- ) {
				if ( liwFaces.GetSize( ) == 0 ) break;
				bFounded = ( *liwFacesOrig ).FindElement( liwFaces[ ij ], ulFoundIndex );
				if ( !bFounded ) {
					for ( ulk = 0; ulk < ( *liwFacesOrig ).GetSize( ); ulk++ ) {
						if ( ( *liwFacesOrig )[ ulk ]->GetIndexExt( ) == liwFaces[ ij ]->GetIndexExt( ) ) {
							bFounded = true;
						}
					}
					if ( !bFounded ) liwFaces.RemoveAt( ij );
				}
			}

			for ( ij = (int) liwFaces.GetSize( ) - 1; ij >= 0; ij-- ) {
				liwFaces[ ij ]->GetPolyVertices( liwVertex );
				for ( ulVertex = 0; ulVertex < liwVertex.GetSize( ); ulVertex++ ) {
					if ( ( *liwVertexActual )[ iCurrentVertex ]->GetIndexExt( ) == liwVertex[ ulVertex ]->GetIndexExt( ) ) {
						for ( ulVertexAux = 0; ulVertexAux < liwVertexProbableNext.GetSize( ); ulVertexAux++ ) {
							if ( (int) ulVertexAux == ii ) continue;
							bFounded = liwVertex.FindElement( liwVertexProbableNext[ ulVertexAux ], ulFoundIndex );
							if ( bFounded ) {
								bFoundedVertex = true;
								break;
							}
						}
						if ( !bFoundedVertex ) continue;

						// if (liwVertex.FindElement(liwVertex[iVertex],ulFoundIndex) > 0) OJO. Esta pregunta la quito pq me parece una tonteria
						{
							// Estamos en la cara que comparte los dos vertices probables y por tanto la cara que nos tiene que dar el clockwise
							iwVector3D = liwFaces[ ij ]->GetNormal( );
							vect.size = T3DSize( iwVector3D.x, iwVector3D.y, iwVector3D.z );
							pt3dOrg = T3DPoint( 0, 0, 0 );
							pln = T3DPlane( pt3dOrg, vect );

							liwFaces[ ij ]->GetPolyVertices( liwVertexOfFace );

							lpt3d = new T3DPoint[ liwVertexOfFace.GetSize( ) ];
							for ( ulk = 0; ulk < liwVertexOfFace.GetSize( ); ulk++ )
								lpt3d[ ulk ] = T3DPoint( liwVertexOfFace[ ulk ]->GetPointPtr( )->x, liwVertexOfFace[ ulk ]->GetPointPtr( )->y, liwVertexOfFace[ ulk ]->GetPointPtr( )->z );

							bIsFaceClockWise = _IsClockWise( (int) liwVertexOfFace.GetSize( ), lpt3d, pln );

							bFounded = liwVertex.FindElement( ( *liwVertexActual )[ iCurrentVertex ], ulFoundIndex );
							if ( ( bClockWise && bIsFaceClockWise ) || ( !bClockWise && !bIsFaceClockWise ) ) ulFoundIndex++;
							else if ( ( bClockWise && !bIsFaceClockWise ) || ( !bClockWise && bIsFaceClockWise ) ) {
								if ( ulFoundIndex == 0 ) ulFoundIndex = liwVertex.GetSize( ) - 1;
							}
							if ( ulFoundIndex > liwVertex.GetSize( ) - 1 ) ulFoundIndex = 0;
							iwNextVertex = liwVertex[ ulFoundIndex ];

							bFounded = ( *liwVertexActual ).FindElement( iwNextVertex, ulFoundIndex );
							iNextVertex = (int) ulFoundIndex;
							return iNextVertex;
						}
					}
				}
			}

			for ( ij = (int) liwFaces.GetSize( ) - 1; ij >= 0; ij-- ) {
				if ( liwFaces.GetSize( ) == 0 ) break;
				liwFaces[ ij ]->GetPolyVertices( liwVertex );
				for ( ulk = 0; ulk < liwVertex.GetSize( ); ulk++ ) {
					iwVertex = liwVertex[ ulk ];
					if ( liwVertexProbableNext[ ii ]->GetIndexExt( ) == iwVertex->GetIndexExt( ) ) {
						bFounded = ( *liwVertexActual ).FindElement( liwVertexProbableNext[ ii ], ulFoundIndex );
						if ( bFounded ) {
							iNextVertex = (int) ulFoundIndex;
							return iNextVertex;
						}
					}
				}
			}

			iNumVertexAtExtrems = 0;
			liwVertexProbableNext[ ii ]->GetAdjacentVertices( liwVertexAux );
			for ( ij = 0; ij < (int) liwVertexAux.GetSize( ); ij++ ) {
				bFounded = ( *liwVertexActual ).FindElement( liwVertexAux[ ij ], ulFoundIndex );
				if ( bFounded ) iNumVertexAtExtrems++;
			}
			if ( iNumVertexAtExtrems == 2 ) {
				bFounded = ( *liwVertexActual ).FindElement( liwVertexProbableNext[ ii ], ulFoundIndex );
				if ( bFounded ) {
					iNextVertex = (int) ulFoundIndex;
					return iNextVertex;
				}
			}
		}
	} catch ( Exception &e ) {
#ifdef _DEBUG
		_MessageBox( e.ToString( ), _GetTranslatedString( "IDS_WARNING" ), mtWarning, TMsgDlgButtons( ) << mbOK );
#endif
	}

	return iNextVertex;
}

//-------------------------------------------------------------------------------------
// Función usada para empezar una lista a partir del vértice que se le dice
// liwValues - Lista de vértices original
// ulIndex - Posición del vértice que se quiere que sea el primero de la lista
// La lista de vértices reordenada
IwTA<IwPolyVertex *> TPBrepData::SetStartIndex( IwTA<IwPolyVertex *> liwValues, ULONG ulIndex )
{
	ULONG uli;
	IwTA<IwPolyVertex *> liwNewValues;

	try {
		if ( ulIndex >= liwValues.GetSize( ) ) return liwValues;

		for ( uli = ulIndex; uli < liwValues.GetSize( ); uli++ )
			liwNewValues.Add( liwValues[ uli ] );
		for ( uli = 0; uli < ulIndex; uli++ )
			liwNewValues.Add( liwValues[ uli ] );
	} catch ( Exception &e ) {
#ifdef _DEBUG
		_MessageBox( e.ToString( ), _GetTranslatedString( "IDS_WARNING" ), mtWarning, TMsgDlgButtons( ) << mbOK );
#endif
	}

	return liwNewValues;
}

//-------------------------------------------------------------------------------------
// Función usada para en la búsqueda de un anillo de caras. Obtiene la siguiente arista a partir de una cara y una arista perteneciente a la misma
// dependiendo del método seleccionado. De momento solo nos interesa el método OppositeEdge
// iwFace - Cara actual a partir de la cual buscar la siguiente arista
// iwPreviousEdge - Arista perteneciente a la cara actual
// method - Método de busqueda de la arista
// La lista de aristas encontrada.
IwTA<IwPolyEdge *> TPBrepData::GetNextEdge( IwPolyFace *iwFace, IwPolyEdge *iwPreviousEdge, OneRingFacesSearchMethod method, bool bOnlyQuads )
{
	bool bFounded;
	ULONG ulIndex, ulEdge;
	IwTA<IwPolyEdge *> liwEdgesFromFace, liwNextEdges;
	IwTA<double> ldLengthPercent;
	double dLength, dTotalLength, dMinDistance, dDistance;
	IwPolyEdge *iwPreviousEdge_Simmetric, *iwNextEdge;

	try {
		iwFace->GetPolyEdges( liwEdgesFromFace );

		iwPreviousEdge_Simmetric = iwPreviousEdge->GetSymmetricPolyEdge( );
		bFounded = liwEdgesFromFace.FindElement( iwPreviousEdge, ulIndex );
		if ( !bFounded ) {
			bFounded = liwEdgesFromFace.FindElement( iwPreviousEdge_Simmetric, ulIndex );
			if ( !bFounded ) return liwNextEdges;
		}

		switch ( method ) {
			case OneRingFacesSearchMethod::ClosestLength:
				dTotalLength = Perimeter( iwFace );
				for ( ulEdge = 0; ulEdge < liwEdgesFromFace.GetSize( ); ulEdge++ ) {
					dLength = liwEdgesFromFace[ ulEdge ]->Length( ); //  TopologyEdges.EdgeLine( liwEdgesFromFace[iEdge] ).Length;
					ldLengthPercent.Add( dLength / dTotalLength );
				}

				// Si la longitud de la arista varia menos de un 20% de la longitud de la arista inicial entonces la seleccionamos
				// Si no cogemos la que mas se acerque
				dMinDistance = 10000;
				for ( ulEdge = 0; ulEdge < liwEdgesFromFace.GetSize( ); ulEdge++ ) {
					if ( ulEdge == ulIndex ) continue;
					dDistance = fabs( ldLengthPercent[ ulEdge ] - ldLengthPercent[ ulIndex ] );
					if ( dDistance < dMinDistance ) {
						dMinDistance = dDistance;
					}
					if ( dDistance < 0.1 ) liwNextEdges.Add( liwEdgesFromFace[ ulEdge ] );
				}
				if ( liwNextEdges.GetSize( ) == 0 ) {
					// Si ninguno cumple la distancia minima entonces los añadimos todos
					for ( ulEdge = 0; ulEdge < liwEdgesFromFace.GetSize( ); ulEdge++ ) {
						if ( ulEdge == ulIndex ) continue;
						liwNextEdges.Add( liwEdgesFromFace[ ulEdge ] );
					}
				}
				break;
			case OneRingFacesSearchMethod::OppositeEdge:
				iwNextEdge = GetOppositeEdgeFromFace( iwPreviousEdge, iwFace, bOnlyQuads );
				if ( iwNextEdge != NULL ) // Numero par de aristas
					liwNextEdges.Add( iwNextEdge );
				else
					return NULL;

				break;
			default: break;
		}
	} catch ( Exception &e ) {
#ifdef _DEBUG
		_MessageBox( e.ToString( ), _GetTranslatedString( "IDS_WARNING" ), mtWarning, TMsgDlgButtons( ) << mbOK );
#endif
	}

	return liwNextEdges;
}

//-------------------------------------------------------------------------------------
// Chequea condiciones de terminación de anillos de caras. Si es correcto o incorrecto
// liFacesPath - Lista de caras a chequear
// bContinue - Devuelve si se debe continuar el anillo o no (si es abierto devuelve true)
// bOneRingClosed - Devuelve si el anillo es cerrado o no
// True en caso de que el anillo sea correcto. False si el anillo es incorrecto
bool TPBrepData::CheckEndingConditions_FacesRing( IwTA<TStructFaces> *liFacesPath, bool &bContinue, bool &bOneRingClosed )
{
	bool bFounded;
	int iFace1, iFace2;
	ULONG ulIndex, uli;
	IwPolyEdge *iwPolyEdge, *iwEdge_Simmetric;
	IwTA<IwPolyEdge *> liwEdges1, liwEdges2;
	IwTA<TStructFaces> lwFaceRepeated;

	bContinue = true;
	bOneRingClosed = false;
	try {
		// 0. Si la lista de vertices esta vacia
		if ( liFacesPath == NULL || ( *liFacesPath ).GetSize( ) == 0 ) return false;

		// 1. El numero de aristas excede el permitido
		// if ( ( *liFacesPath ).GetSize( ) > UL_MAX_EDGES_FOR_RING ) return false;

		// 2. La última cara coincide con la primera
		if ( ( *liFacesPath )[ 0 ].ulIndexOfFace == ( *liFacesPath )[ ( *liFacesPath ).GetSize( ) - 1 ].ulIndexOfFace ) {
			if ( ( *liFacesPath ).GetSize( ) < 3 ) return false;

			bOneRingClosed = true;
			return true;
		}

		// 3. La ultima arista coincide con la primera
		if ( ( *liFacesPath )[ 0 ].iwPolyEdgeSharedWithPreviousFace == ( *liFacesPath )[ ( *liFacesPath ).GetSize( ) - 1 ].iwPolyEdgeSharedWithNextFace ) {
			if ( ( *liFacesPath ).GetSize( ) < 3 ) return false;
			bOneRingClosed = true;
			return true;
		}

		// 4. Tenemos que comprobar si el ultimo indice que se ha añadido forma ya un camino cerrado (se repite)
		for ( uli = 0; uli < ( *liFacesPath ).GetSize( ); uli++ ) {
			if ( ( *liFacesPath )[ uli ].ulIndexOfFace == ( *liFacesPath )[ ( *liFacesPath ).GetSize( ) - 1 ].ulIndexOfFace ) lwFaceRepeated.Add( ( *liFacesPath )[ uli ] );
		}
		if ( lwFaceRepeated.GetSize( ) > 1 ) {
			// Como el camino cerrado no incluye a la arista inicial entonces es un camino incorrecto (pq esta comprobacion ya se habia hecho antes)
			return false;
		}

		// 5. La ultima cara comparte arista con la primera
		if ( ( *liFacesPath ).GetSize( ) > 2 ) {
			iFace1 = ( *liFacesPath )[ 0 ].ulIndexOfFace;
			iFace2 = ( *liFacesPath )[ ( *liFacesPath ).GetSize( ) - 1 ].ulIndexOfFace;
			PBrepFaces[ iFace1 ]->GetPolyEdges( liwEdges1 );
			PBrepFaces[ iFace2 ]->GetPolyEdges( liwEdges2 );
			for ( uli = 0; uli < liwEdges1.GetSize( ); uli++ ) {
				iwPolyEdge = liwEdges1[ uli ];
				bFounded = liwEdges2.FindElement( iwPolyEdge, ulIndex );
				if ( bFounded ) {
					bOneRingClosed = true;
					return true;
				} else {
					iwEdge_Simmetric = iwPolyEdge->GetSymmetricPolyEdge( );
					bFounded = liwEdges2.FindElement( iwEdge_Simmetric, ulIndex );
					if ( bFounded ) {
						bOneRingClosed = true;
						return true;
					}
				}
			}
		}
	} catch ( Exception &e ) {
#ifdef _DEBUG
		_MessageBox( e.ToString( ), _GetTranslatedString( "IDS_WARNING" ), mtWarning, TMsgDlgButtons( ) << mbOK );
#endif
	}

	bContinue = true;
	return true;
}

//-------------------------------------------------------------------------------------
// Chequea condiciones de terminación de anillos de vértices (aristas). Si es correcto o incorrecto
// liVertexPath - Lista de caras a chequear
// bContinue - Devuelve si se debe continuar el anillo o no (si es abierto devuelve true)
// True en caso de que el anillo sea correcto. False si el anillo es incorrecto
bool TPBrepData::CheckEndingConditions( int iSelectedIniElementForOneRing, IwTA<TDataIntIntForVertexPaths> *liVertexPath, bool &bContinue )
{
	int iNumFounded;
	ULONG ulStartIndex, ulIndex;
	IwTA<ULONG> lVertexRepeated;
	int indexPairTopologyVertex[ 2 ], indexPairTopologyVertexAux[ 2 ];
	IwPolyVertex *iwVertexStart, *iwVertexEnd;
	IwPolyEdge *iwEdge;
	IwStatus iwStatus;
	TDataIntIntForVertexPaths dataIntIntForVertexPaths;

	bContinue = true;
	try {
		// 0. Si la lista de vertices esta vacia
		if ( liVertexPath == NULL || ( *liVertexPath ).GetSize( ) == 0 ) return false;

		// 1. El numero de aristas excede el permitido
		// if ( ( *liVertexPath ).GetSize( ) > UL_MAX_EDGES_FOR_RING ) return false;

		// 2. El ultimo vertice coincide con el primero
		if ( ( *liVertexPath )[ 0 ].iElementIndex == ( *liVertexPath )[ ( *liVertexPath ).GetSize( ) - 1 ].iElementIndex ) {
			if ( ( *liVertexPath ).GetSize( ) < 3 ) return false;
			return true;
		}

		// 3. Tenemos que comprobar si el ultimo indice que se ha añadido forma ya un camino cerrado (se repite)
		indexPairTopologyVertex[ 0 ] = ( *liVertexPath )[ 0 ].iElementIndex;
		indexPairTopologyVertex[ 1 ] = ( *liVertexPath )[ ( *liVertexPath ).GetSize( ) - 1 ].iElementIndex;

		dataIntIntForVertexPaths.iElementIndex = indexPairTopologyVertex[ 0 ];
		( *liVertexPath ).FindElements( dataIntIntForVertexPaths, lVertexRepeated );

		if ( lVertexRepeated.GetSize( ) > 1 && iSelectedIniElementForOneRing >= 0 ) {
			iwVertexStart = PBrepEdges[ iSelectedIniElementForOneRing ]->GetStartVertex( );
			iwVertexEnd = PBrepEdges[ iSelectedIniElementForOneRing ]->GetEndVertex( );
			indexPairTopologyVertexAux[ 0 ] = iwVertexStart->GetIndexExt( );
			indexPairTopologyVertexAux[ 1 ] = iwVertexEnd->GetIndexExt( );

			if ( indexPairTopologyVertex[ 0 ] != indexPairTopologyVertexAux[ 0 ] && indexPairTopologyVertex[ 1 ] != indexPairTopologyVertexAux[ 0 ] && indexPairTopologyVertex[ 0 ] != indexPairTopologyVertexAux[ 1 ] && indexPairTopologyVertex[ 1 ] != indexPairTopologyVertexAux[ 1 ] ) return false;

			// Si el camino cerrado no incluye a la arista inicial entonces es un camino incorrecto
			if ( ( *liVertexPath )[ ( *liVertexPath ).GetSize( ) - 1 ].iElementIndex != indexPairTopologyVertex[ 0 ] ) {
				// A no ser que haya una arista entre el vertice repetido y el primero, entonces quitamos este bucle y nos quedamos con el camino
				iwStatus = PBrepVertexs[ ( *liVertexPath )[ ( *liVertexPath ).GetSize( ) - 1 ].iElementIndex ]->FindPolyEdgeBetween( PBrepVertexs[ indexPairTopologyVertex[ 0 ] ], iwEdge );
				if ( iwStatus == IW_SUCCESS && iwEdge != NULL ) {
					dataIntIntForVertexPaths.iElementIndex = indexPairTopologyVertex[ 0 ];
					iNumFounded = ( *liVertexPath ).FindElements( dataIntIntForVertexPaths, lVertexRepeated );
					if ( iNumFounded < 2 ) return true;

					ulStartIndex = lVertexRepeated[ 0 ];
					ulIndex = lVertexRepeated[ 1 ];

					( *liVertexPath ).RemoveAt( ulStartIndex, ulIndex - ulStartIndex );
					( *liVertexPath )[ 0 ].iNumBranches = 0;
					if ( ( *liVertexPath ).GetSize( ) < 3 ) return false;

					( *liVertexPath ).InsertAt( 0, ( *liVertexPath )[ ( *liVertexPath ).GetSize( ) - 1 ] );
					return true;
				}
				return false;
			}

			return true;
		}
		dataIntIntForVertexPaths.iElementIndex = indexPairTopologyVertex[ 1 ];
		iNumFounded = ( *liVertexPath ).FindElements( dataIntIntForVertexPaths, lVertexRepeated );
		if ( lVertexRepeated.GetSize( ) > 1 && iSelectedIniElementForOneRing >= 0 ) {
			iwVertexStart = PBrepEdges[ iSelectedIniElementForOneRing ]->GetStartVertex( );
			iwVertexEnd = PBrepEdges[ iSelectedIniElementForOneRing ]->GetEndVertex( );
			indexPairTopologyVertexAux[ 0 ] = iwVertexStart->GetIndexExt( );
			indexPairTopologyVertexAux[ 1 ] = iwVertexEnd->GetIndexExt( );

			if ( indexPairTopologyVertex[ 0 ] != indexPairTopologyVertexAux[ 0 ] && indexPairTopologyVertex[ 1 ] != indexPairTopologyVertexAux[ 0 ] && indexPairTopologyVertex[ 0 ] != indexPairTopologyVertexAux[ 1 ] && indexPairTopologyVertex[ 1 ] != indexPairTopologyVertexAux[ 1 ] ) return false;

			return true;
		}

		// 4. Tenemos que comprobar si el ultimo indice que se ha añadido forma ya un camino cerrado
		dataIntIntForVertexPaths.iElementIndex = indexPairTopologyVertex[ 0 ];
		iNumFounded = ( *liVertexPath ).FindElements( dataIntIntForVertexPaths, lVertexRepeated );
		if ( lVertexRepeated.GetSize( ) > 1 && iSelectedIniElementForOneRing >= 0 ) {
			iwVertexStart = PBrepEdges[ iSelectedIniElementForOneRing ]->GetStartVertex( );
			iwVertexEnd = PBrepEdges[ iSelectedIniElementForOneRing ]->GetEndVertex( );
			indexPairTopologyVertexAux[ 0 ] = iwVertexStart->GetIndexExt( );
			indexPairTopologyVertexAux[ 1 ] = iwVertexEnd->GetIndexExt( );

			if ( ( indexPairTopologyVertex[ 0 ] != indexPairTopologyVertexAux[ 0 ] && indexPairTopologyVertex[ 0 ] != indexPairTopologyVertexAux[ 1 ] ) || ( indexPairTopologyVertex[ 1 ] != indexPairTopologyVertexAux[ 0 ] && indexPairTopologyVertex[ 1 ] != indexPairTopologyVertexAux[ 1 ] ) ) return false;

			return true;
		}
		dataIntIntForVertexPaths.iElementIndex = indexPairTopologyVertex[ 1 ];
		iNumFounded = ( *liVertexPath ).FindElements( dataIntIntForVertexPaths, lVertexRepeated );
		if ( lVertexRepeated.GetSize( ) > 1 && iSelectedIniElementForOneRing >= 0 ) {
			iwVertexStart = PBrepEdges[ iSelectedIniElementForOneRing ]->GetStartVertex( );
			iwVertexEnd = PBrepEdges[ iSelectedIniElementForOneRing ]->GetEndVertex( );
			indexPairTopologyVertexAux[ 0 ] = iwVertexStart->GetIndexExt( );
			indexPairTopologyVertexAux[ 1 ] = iwVertexEnd->GetIndexExt( );

			if ( ( indexPairTopologyVertex[ 0 ] != indexPairTopologyVertexAux[ 0 ] && indexPairTopologyVertex[ 0 ] != indexPairTopologyVertexAux[ 1 ] ) || ( indexPairTopologyVertex[ 1 ] != indexPairTopologyVertexAux[ 0 ] && indexPairTopologyVertex[ 1 ] != indexPairTopologyVertexAux[ 1 ] ) ) return false;

			return true;
		}
	} catch ( Exception &e ) {
#ifdef _DEBUG
		_MessageBox( e.ToString( ), _GetTranslatedString( "IDS_WARNING" ), mtWarning, TMsgDlgButtons( ) << mbOK );
#endif
	}

	bContinue = true;
	return true;
}

//-------------------------------------------------------------------------------------

// Vacia el anillo en el caso de que sea incorrecto

// liVertexLists - Lista de elementos a chequear
// liSelectedElements - Lista de elementos seleccionada previamente por el usuario
// OneRingType - Tipo de elemento: Caras o vértices
void TPBrepData::DeleteInvalidRings( TOGLTransf *OGLTransf, IwTA<TDataIntIntForVertexPaths> *liVertexLists, IwTA<int> *liSelectedElements, ElementType eType )
{
	bool bCorrect, bValid, bFounded;
	int iNumPlanes, numint;
	double *intpar;
	ULONG ulIndex, ulj, uli;
	IwTA<int> liVertexesOnly;
	IwPolyVertex *iwVertexStart, *iwVertexEnd;

	int indexPairSelected[ 2 ];
	T3DRect bbCurve;
	T3DPoint pto;
	T3DVector vect3d;
	IwTA<T3DPlane> lPlaneXZ_YZ;
	TCadPolyline *polyline;

	//   CurveIntersections crvIntersections;

	TDataIntIntForVertexPaths dataIntIntForVertexPaths, dataIntIntForVertexPaths2;

	try {
		// 1. Descartar las listas vacias
		if ( liVertexLists == NULL || ( *liVertexLists ).GetSize( ) == 0 ) return;

		// 2. Descartar las listas en las que no aparezca el elemento seleccionado
		if ( liSelectedElements != NULL ) {
			if ( eType == ElementType::Edge && ( *liSelectedElements ).GetSize( ) == 1 ) {
				// 2.1. Descartar las listas que no incluyan los vertices del eje seleccionado (Aunque esto no deberia pasar)
				iwVertexStart = PBrepEdges[ ( *liSelectedElements )[ 0 ] ]->GetStartVertex( );
				iwVertexEnd = PBrepEdges[ ( *liSelectedElements )[ 0 ] ]->GetEndVertex( );
				indexPairSelected[ 0 ] = iwVertexStart->GetIndexExt( );
				indexPairSelected[ 1 ] = iwVertexEnd->GetIndexExt( );

				dataIntIntForVertexPaths.iElementIndex = indexPairSelected[ 0 ];
				dataIntIntForVertexPaths2.iElementIndex = indexPairSelected[ 1 ];

				bFounded = ( *liVertexLists ).FindElement( dataIntIntForVertexPaths, ulIndex );
				if ( !bFounded ) ( *liVertexLists ).RemoveAll( );

				bFounded = ( *liVertexLists ).FindElement( dataIntIntForVertexPaths2, ulIndex );
				if ( !bFounded ) ( *liVertexLists ).RemoveAll( );
			} else if ( eType == ElementType::Face && ( *liSelectedElements ).GetSize( ) > 0 ) {
				// 2.2. Descartar las listas que no incluyan la/s caras seleccionadas (Aunque esto no deberia pasar)
				for ( uli = 0; uli < ( *liSelectedElements ).GetSize( ); uli++ ) {
					dataIntIntForVertexPaths.iElementIndex = ( *liSelectedElements )[ uli ];
					bFounded = ( *liVertexLists ).FindElement( dataIntIntForVertexPaths, ulIndex );
					if ( !bFounded ) {
						( *liVertexLists ).RemoveAll( );
						break;
					}
				}
			}
		}

		if ( liVertexLists == NULL || ( *liVertexLists ).GetSize( ) == 0 ) return;

		// 3. En el caso de que sea un anillo de aristas vamos a intentar quitar los casos en los que el anillo recorre la malla mas de una vez
		// Vamos a evitar este caso pq esta dando mas intersecciones de las que deberia.
		if ( false && eType == ElementType::Edge ) {
			for ( ulj = 0; ulj < ( *liVertexLists ).GetSize( ); ulj++ )
				liVertexesOnly.Add( ( *liVertexLists )[ ulj ].iElementIndex );

			polyline = GetPolylineFromVertices( OGLTransf, &liVertexesOnly, bValid );
			liVertexesOnly.RemoveAll( );
			if ( polyline == NULL || !bValid ) {
				( *liVertexLists ).RemoveAll( );
				return;
			}

			polyline->CalcBoundRect( OGLTransf, bbCurve );
			iNumPlanes = 0;
			vect3d = T3DVector( bbCurve.BottomRightBack( ) - bbCurve.TopLeftFront( ) );
			if ( bbCurve.Width( ) < vect3d.Modulo( ) ) iNumPlanes++;
			if ( bbCurve.Height( ) < vect3d.Modulo( ) ) iNumPlanes++;
			pto = bbCurve.Center( );

			vect3d = T3DVector( T3DSize( 0, 1, 0 ) );
			lPlaneXZ_YZ.Add( T3DPlane( pto, vect3d ) );
			vect3d = T3DVector( T3DSize( 1, 0, 0 ) );
			lPlaneXZ_YZ.Add( T3DPlane( pto, vect3d ) );
			bCorrect = true;
			for ( ulj = 0; ulj < lPlaneXZ_YZ.GetSize( ); ulj++ ) {
				polyline->Intersect( OGLTransf, lPlaneXZ_YZ[ ulj ], &intpar, numint );
				if ( numint > 2 ) bCorrect = false;
			}
			if ( !bCorrect ) ( *liVertexLists ).RemoveAll( );
			delete polyline;
		}

	} catch ( Exception &e ) {
#ifdef _DEBUG
		_MessageBox( e.ToString( ), _GetTranslatedString( "IDS_WARNING" ), mtWarning, TMsgDlgButtons( ) << mbOK );
#endif
	}
}

//-------------------------------------------------------------------------------------
// Obtiene la arista cuyo inicio es el vertice que se le pasa por parametro y la cara contiene a ambos
// iwPolyFace - Puntero a la cara seleccionado
// iwPolyVertex - Puntero al vértice seleccionado
// Devuelve la arista que contiene a ambos
IwPolyEdge *TPBrepData::GetEdgeFromFaceStartingAtVertex( IwPolyFace *iwPolyFace, IwPolyVertex *iwPolyVertex )
{
	bool bFounded;
	ULONG ulIndex, uli;
	IwPolyEdge *iwEdge;
	IwTA<IwPolyFace *> liwPolyFace;
	IwTA<IwPolyEdge *> liwPolyEdge;

	iwEdge = NULL;
	if ( iwPolyVertex == NULL || iwPolyFace == NULL ) return NULL;
	try {
		iwPolyVertex->GetStartingPolyEdges( liwPolyEdge );
		for ( uli = 0; uli < liwPolyEdge.GetSize( ); uli++ ) {
			liwPolyFace = GetConnectedFacesFromEdge( liwPolyEdge[ uli ] );
			bFounded = liwPolyFace.FindElement( iwPolyFace, ulIndex );
			if ( bFounded ) {
				iwEdge = liwPolyEdge[ uli ];
				break;
			}
		}
	} catch ( Exception &e ) {
#ifdef _DEBUG
		_MessageBox( e.ToString( ), _GetTranslatedString( "IDS_WARNING" ), mtWarning, TMsgDlgButtons( ) << mbOK );
#endif
	}
	return iwEdge;
}

//-------------------------------------------------------------------------------------
// Función de comparación de dos aristas teniendo en cuenta sólo si sus vertices final e inicial son iguales, ya sean simétricas o no
// iwPolyEdge1 - Puntero de la arista 1
// iwPolyEdge2 - Puntero de la arista 2
// Devuelve true si son iguales
bool TPBrepData::AreEqual( IwPolyEdge *iwPolyEdge1, IwPolyEdge *iwPolyEdge2 )
{
	IwPolyEdge *ieEdgeSymmetric;
	IwPolyVertex *iwVertexStart1, *iwVertexStart2, *iwVertexEnd1, *iwVertexEnd2;

	try {
		if ( iwPolyEdge1 == NULL || iwPolyEdge2 == NULL ) return false;

		if ( iwPolyEdge1 == iwPolyEdge2 ) return true;

		ieEdgeSymmetric = iwPolyEdge1->GetSymmetricPolyEdge( );
		if ( iwPolyEdge2 == ieEdgeSymmetric ) return true;

		iwVertexStart1 = iwPolyEdge1->GetStartVertex( );
		iwVertexStart2 = iwPolyEdge2->GetStartVertex( );
		iwVertexEnd1 = iwPolyEdge1->GetEndVertex( );
		iwVertexEnd2 = iwPolyEdge2->GetEndVertex( );

		if ( iwVertexStart1 == iwVertexStart2 && iwVertexEnd1 == iwVertexEnd2 ) return true;
		if ( iwVertexStart1 == iwVertexEnd2 && iwVertexEnd1 == iwVertexStart2 ) return true;
	} catch ( Exception &e ) {
#ifdef _DEBUG
		_MessageBox( e.ToString( ), _GetTranslatedString( "IDS_WARNING" ), mtWarning, TMsgDlgButtons( ) << mbOK );
#endif
	}

	return false;
}

//-------------------------------------------------------------------------------------
// Comprobacion de si un vertice es el principio o final de una arista
bool TPBrepData::IsVertexFromEdge( IwPolyVertex *iwPolyVertex, IwPolyEdge *iwPolyEdge )
{
	if ( iwPolyVertex == NULL || iwPolyEdge == NULL ) return false;

	return iwPolyEdge->GetStartVertex( ) == iwPolyVertex || iwPolyEdge->GetEndVertex( ) == iwPolyVertex;
}

//-------------------------------------------------------------------------------------
// Comprobacion de si un vertice es el principio o final de una arista
bool TPBrepData::IsVertexFromFace( IwPolyVertex *iwPolyVertex, IwPolyFace *IwPolyFace )
{
	ULONG ulIndex;
	IwTA<IwPolyVertex *> vertexs;

	if ( iwPolyVertex == NULL || IwPolyFace == NULL ) return false;

	IwPolyFace->GetPolyVertices( vertexs );
	return vertexs.FindElement( iwPolyVertex, ulIndex );
}

//-------------------------------------------------------------------------------------
bool TPBrepData::IsEdgeFromFace( IwPolyEdge *iwPolyEdge, IwPolyFace *iwPolyFace, bool checkSymmetric )
{
	if ( !iwPolyEdge || !iwPolyFace ) return false;

	if ( iwPolyEdge->GetPolyFace( ) == iwPolyFace ) return true;

	if ( checkSymmetric && iwPolyEdge->GetSymmetricPolyEdge( ) ) {
		return ( iwPolyEdge->GetSymmetricPolyEdge( )->GetPolyFace( ) == iwPolyFace );
	}
	return false;
}

//-------------------------------------------------------------------------------------

IwPolyVertex *TPBrepData::IsPointAVertexFromEdge( T3DPoint point, IwPolyEdge *iwEdge, double tol )
{
	IwPoint3d ptVertex;
	T3DPoint point3D;
	IwPolyVertex *vertex;

	vertex = NULL;

	if ( iwEdge == NULL ) return vertex;

	ptVertex = iwEdge->GetStartPoint( );
	point3D = T3DPoint( ptVertex.x, ptVertex.y, ptVertex.z );
	if ( point.Similar( point3D, tol ) ) {
		vertex = iwEdge->GetStartVertex( );
		return vertex;
	}
	ptVertex = iwEdge->GetEndPoint( );
	point3D = T3DPoint( ptVertex.x, ptVertex.y, ptVertex.z );
	if ( point.Similar( point3D, tol ) ) {
		vertex = iwEdge->GetEndVertex( );
		return vertex;
	}

	return vertex;
}

//-------------------------------------------------------------------------------------

IwPolyEdge *TPBrepData::GetEdgeFromVertices( IwPolyVertex *iVertexPos1, IwPolyVertex *iVertexPos2, bool forceGetVisibleEdge )
{
	bool bFounded;
	ULONG ulIndex;
	IwStatus iwStatus;
	IwPolyEdge *iwPolyEdgeFounded, *iwEdge;

	iwEdge = 0;
	try {
		if ( iVertexPos1 && iVertexPos1->GetIndexExt( ) > (int) PBrepVertexs.GetSize( ) - 1 ) return NULL;
		if ( iVertexPos2 && iVertexPos2->GetIndexExt( ) > (int) PBrepVertexs.GetSize( ) - 1 ) return NULL;

		iwStatus = PBrepVertexs[ iVertexPos1->GetIndexExt( ) ]->FindPolyEdgeBetween( PBrepVertexs[ iVertexPos2->GetIndexExt( ) ], iwEdge );
		if ( forceGetVisibleEdge && iwStatus == IW_SUCCESS && iwEdge != NULL ) {
			bFounded = FindElement_Edge( &PBrepEdges, iwEdge, ulIndex, iwPolyEdgeFounded );
			if ( bFounded ) return iwPolyEdgeFounded;
		}
	} catch ( Exception &e ) {
#ifdef _DEBUG
		_MessageBox( e.ToString( ), _GetTranslatedString( "IDS_WARNING" ), mtWarning, TMsgDlgButtons( ) << mbOK );
#endif
	}
	return iwEdge;
}

//-------------------------------------------------------------------------------------

IwPolyEdge *TPBrepData::GetEdgeFromVertices( ULONG iVertexPos1, ULONG iVertexPos2, bool forceGetVisibleEdge )
{
	IwPolyEdge *iwPolyEdgeFounded;
	IwPolyVertex *iwVertex1, *iwVertex2;

	try {
		if ( iVertexPos1 > PBrepVertexs.GetSize( ) - 1 ) return NULL;
		if ( iVertexPos2 > PBrepVertexs.GetSize( ) - 1 ) return NULL;

		iwVertex1 = PBrepVertexs[ iVertexPos1 ];
		iwVertex2 = PBrepVertexs[ iVertexPos2 ];
		iwPolyEdgeFounded = GetEdgeFromVertices( iwVertex1, iwVertex2, forceGetVisibleEdge );
		if ( iwPolyEdgeFounded ) return iwPolyEdgeFounded;
	} catch ( Exception &e ) {
#ifdef _DEBUG
		_MessageBox( e.ToString( ), _GetTranslatedString( "IDS_WARNING" ), mtWarning, TMsgDlgButtons( ) << mbOK );
#endif
	}
	return NULL;
}

//-------------------------------------------------------------------------------------
// Obtiene las caras adyacentes a un vértice
// iSelectedVertex - Índice del vértice
// Devuelve la lista de caras adyacentes al vértice elegido
IwTA<IwPolyFace *> TPBrepData::GetConnectedFacesFromVertex( ULONG ulSelectedVertex )
{
	IwTA<IwPolyFace *> adjacentFaces;

	if ( ulSelectedVertex < PBrepVertexs.GetSize( ) ) PBrepVertexs[ ulSelectedVertex ]->GetPolyFaces( adjacentFaces );

	return adjacentFaces;
}

//-------------------------------------------------------------------------------------
// Obtiene las caras adyacentes a un vértice
// iwPolyVertex - Puntero al vértice seleccionado
// Devuelve la lista de caras adyacentes al vértice elegido
IwTA<IwPolyFace *> TPBrepData::GetConnectedFacesFromVertex( IwPolyVertex *iwPolyVertex )
{
	IwTA<IwPolyFace *> adjacentFaces;

	if ( iwPolyVertex == NULL ) return NULL;
	iwPolyVertex->GetPolyFaces( adjacentFaces );
	return adjacentFaces;
}

//-------------------------------------------------------------------------------------
// Obtiene las caras adyacentes a una arista
// iSelectedVertex - Índice de la arista
// Devuelve la lista de caras adyacentes a la arista elegida
IwTA<IwPolyFace *> TPBrepData::GetConnectedFacesFromEdge( ULONG ulSelectedEdge )
{
	IwPolyEdge *iwPolyEdge;

	if ( ulSelectedEdge < PBrepEdges.GetSize( ) ) iwPolyEdge = PBrepEdges[ ulSelectedEdge ];

	return GetConnectedFacesFromEdge( iwPolyEdge );
}

//-------------------------------------------------------------------------------------
// Obtiene las caras adyacentes a una arista
// iSelectedVertex - Puntero de la arista
// Devuelve la lista de caras adyacentes a la arista elegida
IwTA<IwPolyFace *> TPBrepData::GetConnectedFacesFromEdge( IwPolyEdge *iwPolyEdge )
{
	ULONG uli;
	IwPolyVertex *iwPolyVertex;
	IwPolyFace *pFace;
	IwTA<IwPolyFace *> rFaces;
	IwTA<IwPolyFace *> allFaces, adjacentFaces;

	try {
		if ( iwPolyEdge == NULL ) return NULL;

		iwPolyVertex = iwPolyEdge->GetStartVertex( );
		iwPolyVertex->GetPolyFaces( rFaces );
		for ( uli = 0; uli < rFaces.GetSize( ); uli++ ) {
			pFace = rFaces[ uli ];
			allFaces.Add( pFace );
		}

		iwPolyVertex = iwPolyEdge->GetEndVertex( );
		iwPolyVertex->GetPolyFaces( rFaces );
		for ( uli = 0; uli < rFaces.GetSize( ); uli++ ) {
			pFace = rFaces[ uli ];
			allFaces.Add( pFace );
		}
		allFaces.GetDuplicates( adjacentFaces );
	} catch ( Exception &e ) {
#ifdef _DEBUG
		_MessageBox( e.ToString( ), _GetTranslatedString( "IDS_WARNING" ), mtWarning, TMsgDlgButtons( ) << mbOK );
#endif
	}

	return adjacentFaces;
}

//-------------------------------------------------------------------------------------
// Función usada en el calculo de rings. Se busca la arista opuesta descartando la misma cantidad de
// aristas tanto a derecha como a izquierda del conjunto de aristas conectadas al vertice
// iwPolyEdge - Puntero de la arista original
// iwPolyVertex_Common - Puntero del vértice que debe compartir la arista buscada
// Devuelve la arista "opuesta" encontrada
IwPolyEdge *TPBrepData::GetOppositeEdgeFromVertex( IwPolyEdge *iwPolyEdge, IwPolyVertex *iwPolyVertex_Common )
{
	int iNumFounded;
	ULONG ulPos, uli, ulj;
	IwPolyEdge *iwEdge, *iwCurrentEdge, *iwEdgeAux;
	IwPolyVertex *iwVertexFromPreviousEdge;
	IwTA<IwPolyVertex *> liwVertexAtStart;
	IwTA<IwPolyFace *> liwAdjacentFaces;
	IwTA<IwPolyVertex *> liwVertexFromFace;
	IwTA<IwPolyEdge *> liwEdgesToReview;

	iwEdge = NULL;
	try {
		if ( iwPolyVertex_Common == NULL || iwPolyEdge == NULL ) return iwEdge;

		if ( iwPolyEdge->GetStartVertex( ) == iwPolyVertex_Common ) iwVertexFromPreviousEdge = iwPolyEdge->GetEndVertex( );
		else
			iwVertexFromPreviousEdge = iwPolyEdge->GetEndVertex( );

		iwPolyVertex_Common->GetAdjacentVertices( liwVertexAtStart );

		// Si el  numero de aristas es impar entonces la funcion debe  devolver NULL
		if ( liwVertexAtStart.GetSize( ) % 2 != 0 ) return NULL;

		// Primero de todo borramos el otro vertice de la arista implicada
		iNumFounded = liwVertexAtStart.FindElement( iwVertexFromPreviousEdge, ulPos );
		if ( iNumFounded <= 0 ) return NULL;
		liwVertexAtStart.RemoveAt( ulPos );

		// Ahora vamos descartando por parejas.
		liwEdgesToReview.Add( iwPolyEdge );
		do {
			iwCurrentEdge = liwEdgesToReview[ 0 ];
			liwEdgesToReview.RemoveAt( 0 );
			liwAdjacentFaces = GetConnectedFacesFromEdge( iwCurrentEdge );
			for ( uli = 0; uli < liwAdjacentFaces.GetSize( ); uli++ ) {
				liwAdjacentFaces[ uli ]->GetPolyVertices( liwVertexFromFace );
				// Si algun vertice de la cara esta en el conjunto de vertices objetivo entonces los descartamos
				for ( ulj = 0; ulj < liwVertexFromFace.GetSize( ); ulj++ ) {
					iNumFounded = liwVertexAtStart.FindElement( liwVertexFromFace[ ulj ], ulPos );
					if ( iNumFounded > 0 ) {
						liwVertexAtStart[ ulPos ]->FindPolyEdgeBetween( iwPolyVertex_Common, iwEdgeAux );
						// Antes de borrar el vertice añadimos la arista para revisar (puede ser que haya mas de 4 vertices adyacentes)
						liwEdgesToReview.Add( iwEdgeAux );
						liwVertexAtStart.RemoveAt( ulPos );
					}
				}
			}
		} while ( liwVertexAtStart.GetSize( ) > 1 && liwEdgesToReview.GetSize( ) > 0 );

		liwVertexAtStart[ 0 ]->FindPolyEdgeBetween( iwPolyVertex_Common, iwEdge );
	} catch ( Exception &e ) {
#ifdef _DEBUG
		_MessageBox( e.ToString( ), _GetTranslatedString( "IDS_WARNING" ), mtWarning, TMsgDlgButtons( ) << mbOK );
#endif
	}

	return iwEdge;
}

//-------------------------------------------------------------------------------------
// Función usada en el calculo de rings. Se busca la arista opuesta descartando la misma cantidad de
// aristas tanto a derecha como a izquierda del conjunto de aristas de una cara
// iwPolyEdge - Puntero de la arista original
// iwFace_Common - Puntero de la cara común que debe compartir la arista buscada
// Devuelve la arista "opuesta" encontrada dentro de la misca cara
IwPolyEdge *TPBrepData::GetOppositeEdgeFromFace( IwPolyEdge *iwPolyEdge, IwPolyFace *iwFace_Common, bool onlyQuads )
{
	int iNumFounded, iRem;
	ULONG ulIndex, ulNextEdge;
	IwPolyEdge *iwEdge, *iwEdgeFounded;
	IwTA<IwPolyVertex *> liwVertexAtStart;
	IwTA<IwPolyFace *> liwAdjacentFaces;
	IwTA<IwPolyVertex *> liwVertexFromFace;
	IwTA<IwPolyEdge *> liwEdgesToReview;

	iwEdge = NULL;
	try {
		if ( iwFace_Common == NULL || iwPolyEdge == NULL ) return iwEdge;

		// Obtenemos las aristas de la cara y luego las recorremos en ambos sentidos al mismo tiempo hasta que nos quede una
		iwFace_Common->GetPolyEdges( liwEdgesToReview );

		iNumFounded = FindElement_Edge( &liwEdgesToReview, iwPolyEdge, ulIndex, iwEdgeFounded );
		if ( iNumFounded <= 0 ) return NULL;

		iRem = liwEdgesToReview.GetSize( ) % 2;
		if ( ( !onlyQuads && iRem == 0 ) || ( onlyQuads && liwEdgesToReview.GetSize( ) == 4 ) ) // Numero par de aristas
		{
			ulNextEdge = ulIndex + liwEdgesToReview.GetSize( ) / 2;
			if ( ulNextEdge > liwEdgesToReview.GetSize( ) - 1 ) ulNextEdge = ulNextEdge - liwEdgesToReview.GetSize( );
			iwEdge = liwEdgesToReview[ ulNextEdge ];
		} else
			// Si no es par entonces no hay solución
			return NULL;
	} catch ( Exception &e ) {
#ifdef _DEBUG
		_MessageBox( e.ToString( ), _GetTranslatedString( "IDS_WARNING" ), mtWarning, TMsgDlgButtons( ) << mbOK );
#endif
	}

	return iwEdge;
}

//-------------------------------------------------------------------------------------
// Función para saber si dos caras son adyacentes
// iwFace1 - Puntero de la arista 1
// iwFace2 - Puntero de la arista 1
// Devuelve true si son Adyancetes o false en caso contrario
bool TPBrepData::AreAdjacentFaces( IwPolyFace *iwFace1, IwPolyFace *iwFace2 )
{
	ULONG uli;
	IwPolyFace *iwPolyFace, *iwPolyFaceSymmetric;
	IwPolyEdge *iwPolyEdgeSymmetric;
	IwTA<IwPolyEdge *> liwEdges;

	try {
		if ( iwFace1 == NULL || iwFace2 == NULL || iwFace1 == iwFace2 ) return false;
		iwFace1->GetPolyEdges( liwEdges );
		for ( uli = 0; uli < liwEdges.GetSize( ); uli++ ) {
			iwPolyFace = liwEdges[ uli ]->GetPolyFace( );
			iwPolyEdgeSymmetric = liwEdges[ uli ]->GetSymmetricPolyEdge( );
			if ( iwPolyEdgeSymmetric == NULL ) continue;
			iwPolyFaceSymmetric = iwPolyEdgeSymmetric->GetPolyFace( );
			if ( iwPolyFace == iwFace1 && iwPolyFaceSymmetric == iwFace2 ) return true;
			if ( iwPolyFace == iwFace2 && iwPolyFaceSymmetric == iwFace1 ) return true;
		}
	} catch ( Exception &e ) {
#ifdef _DEBUG
		_MessageBox( e.ToString( ), _GetTranslatedString( "IDS_WARNING" ), mtWarning, TMsgDlgButtons( ) << mbOK );
#endif
	}
	return false;
}

//-------------------------------------------------------------------------------------

// Función para saber si dos aristas estan conectadas por sus vertices
bool TPBrepData::AreAdjacentEdges( IwPolyEdge *edge1, IwPolyEdge *edge2, bool &atStart )
{
	ULONG index;
	IwPolyVertex *vertex;
	IwPolyEdge *edgeFounded;
	IwTA<IwPolyEdge *> edges;

	if ( !edge1 || !edge2 ) return false;

	vertex = edge1->GetStartVertex( );
	vertex->GetPolyEdges( edges );

	if ( FindElement_Edge( &edges, edge2, index, edgeFounded ) ) {
		atStart = true;
		return true;
	}

	vertex = edge1->GetEndVertex( );
	vertex->GetPolyEdges( edges );

	if ( FindElement_Edge( &edges, edge2, index, edgeFounded ) ) {
		atStart = false;
		return true;
	}

	return false;
}
//-------------------------------------------------------------------------------------

bool TPBrepData::IsAdjacentFaceToGroup( IwPolyFace *f, vector<int> *group )
{
	int i, num;

	num = group->size( );
	for ( i = 0; i < num; i++ )
		if ( AreAdjacentFaces( f, PBrepFaces[ group->at( i ) ] ) ) return true;

	return false;
}

//-------------------------------------------------------------------------------------

IwTA<IwPolyFace *> TPBrepData::GetCommonFacesBetweenElements( TOGLTransf *OGLTransf, TMeshElementInfo *element1, TMeshElementInfo *element2 )
{
	IwPolyVertex *vertex1, *vertex2;
	IwPolyEdge *edge1, *edge2;
	IwPolyFace *face;
	IwTA<IwPolyFace *> faces;

	if ( !element1 || !element2 ) return false;

	edge1 = edge2 = 0;
	vertex1 = vertex2 = 0;
	face = 0;

	if ( element1->Type == ElementType::Vertex ) vertex1 = GetPBrepVertex( OGLTransf, element1->Index );
	else if ( element1->Type == ElementType::Edge )
		edge1 = GetPBrepEdge( OGLTransf, element1->Index );
	else
		return false;

	if ( element2->Type == ElementType::Vertex ) vertex2 = GetPBrepVertex( OGLTransf, element2->Index );
	else if ( element2->Type == ElementType::Edge )
		edge2 = GetPBrepEdge( OGLTransf, element2->Index );
	else
		return false;

	if ( edge1 && edge2 ) faces = GetCommonFacesBetweenEdges( edge1, edge2 );
	else if ( edge1 )
		face = GetCommonFaceBetweenVertexAndEdge( vertex2, edge1 );
	else if ( edge2 )
		face = GetCommonFaceBetweenVertexAndEdge( vertex1, edge2 );
	else if ( vertex1 && vertex2 )
		faces = GetCommonFacesBetweenVertexs( vertex1, vertex2 );

	if ( face ) faces.Add( face );

	return faces;
}

//-------------------------------------------------------------------------------------
// Función para encontrar las caras entre 2 aristas.
// iwEdge1 - Puntero de la arista 1
// iwEdge2 - Puntero de la arista 2
// Devuelve la cara encontrada o NULL
IwTA<IwPolyFace *> TPBrepData::GetCommonFacesBetweenEdges( IwPolyEdge *iwEdge1, IwPolyEdge *iwEdge2 )
{
	ULONG ulIndex;
	IwPolyFace *iwPolyFace, *iwPolyFaceSymmetric;
	IwPolyEdge *iwPolyEdgeSymmetric;
	IwTA<IwPolyEdge *> liwEdges;
	IwTA<IwPolyFace *> liwAllFaces, polyFaces;

	try {
		iwPolyFace = NULL;
		if ( iwEdge1 != NULL ) {
			iwPolyFace = iwEdge1->GetPolyFace( );
			liwAllFaces.Add( iwPolyFace );
			iwPolyEdgeSymmetric = iwEdge1->GetSymmetricPolyEdge( );
			if ( iwPolyEdgeSymmetric != NULL ) liwAllFaces.Add( iwPolyEdgeSymmetric->GetPolyFace( ) );
		}

		if ( iwEdge2 != NULL ) {
			iwPolyFace = iwEdge2->GetPolyFace( );
			if ( liwAllFaces.FindElement( iwPolyFace, ulIndex ) ) polyFaces.Add( iwPolyFace );
			iwPolyEdgeSymmetric = iwEdge2->GetSymmetricPolyEdge( );
			if ( iwPolyEdgeSymmetric != NULL ) {
				iwPolyFaceSymmetric = iwPolyEdgeSymmetric->GetPolyFace( );
				if ( liwAllFaces.FindElement( iwPolyFaceSymmetric, ulIndex ) ) polyFaces.Add( iwPolyFaceSymmetric );
			}
		}

		return polyFaces;
	} catch ( Exception &e ) {
#ifdef _DEBUG
		_MessageBox( e.ToString( ), _GetTranslatedString( "IDS_WARNING" ), mtWarning, TMsgDlgButtons( ) << mbOK );
#endif
	}
	return polyFaces;
}

//-------------------------------------------------------------------------------------
// Función para encontrar la cara entre un vértice y una arista.
// iwVertex - Puntero del  vértice
// iwEdge - Puntero de la arista
// Devuelve la cara encontrada o NULL
IwPolyFace *TPBrepData::GetCommonFaceBetweenVertexAndEdge( IwPolyVertex *iwVertex, IwPolyEdge *iwEdge )
{
	ULONG ulIndex;
	IwPolyFace *iwPolyFace, *iwPolyFaceSymmetric;
	IwPolyEdge *iwPolyEdgeSymmetric;
	IwTA<IwPolyEdge *> liwEdges;
	IwTA<IwPolyFace *> liwAllFacesFromVertex;

	try {
		if ( iwVertex == NULL || iwEdge == NULL ) return NULL;
		iwPolyFace = iwEdge->GetPolyFace( );
		iwPolyEdgeSymmetric = iwEdge->GetSymmetricPolyEdge( );
		if ( iwPolyEdgeSymmetric != NULL ) iwPolyFaceSymmetric = iwPolyEdgeSymmetric->GetPolyFace( );

		iwVertex->GetPolyFaces( liwAllFacesFromVertex );
		if ( liwAllFacesFromVertex.FindElement( iwPolyFace, ulIndex ) ) return iwPolyFace;
		if ( liwAllFacesFromVertex.FindElement( iwPolyFaceSymmetric, ulIndex ) ) return iwPolyFaceSymmetric;
	} catch ( Exception &e ) {
#ifdef _DEBUG
		_MessageBox( e.ToString( ), _GetTranslatedString( "IDS_WARNING" ), mtWarning, TMsgDlgButtons( ) << mbOK );
#endif
	}
	return NULL;
}

//-------------------------------------------------------------------------------------
// Función para encontrar la cara entre 2 vértices
// iwVertex1 - Puntero del  vértice1
// iwVertex2 - Puntero del  vértice2
// Devuelve la cara encontrada o NULL
IwTA<IwPolyFace *> TPBrepData::GetCommonFacesBetweenVertexs( IwPolyVertex *iwVertex1, IwPolyVertex *iwVertex2 )
{
	ULONG uli, ulIndex;
	IwTA<IwPolyFace *> liwAllFacesFounded, liwAllFacesFromVertex1, liwAllFacesFromVertex2;

	try {
		if ( iwVertex1 == NULL || iwVertex2 == NULL ) return liwAllFacesFounded;

		iwVertex1->GetPolyFaces( liwAllFacesFromVertex1 );
		iwVertex2->GetPolyFaces( liwAllFacesFromVertex2 );

		for ( uli = 0; uli < liwAllFacesFromVertex2.GetSize( ); uli++ ) {
			if ( liwAllFacesFromVertex1.FindElement( liwAllFacesFromVertex2[ uli ], ulIndex ) ) liwAllFacesFounded.Add( liwAllFacesFromVertex2[ uli ] );
		}
		return liwAllFacesFounded;
	} catch ( Exception &e ) {
#ifdef _DEBUG
		_MessageBox( e.ToString( ), _GetTranslatedString( "IDS_WARNING" ), mtWarning, TMsgDlgButtons( ) << mbOK );
#endif
	}
	return NULL;
}

//-------------------------------------------------------------------------------------
// Función para encontrar las aristas compartidas entre 2 caras (las que se encuentran en el array de edges).
// iwFace1 - Puntero de la cara 1
// iwFace1 - Puntero de la cara 2
// Devuelve las aristas encontrada o NULL
IwTA<IwPolyEdge *> TPBrepData::GetCommonEdgesBetweenFaces( IwPolyFace *iwFace1, IwPolyFace *iwFace2 )
{
	ULONG uli;
	IwPolyFace *iwPolyFace, *iwPolyFaceSymmetric;
	IwPolyEdge *iwPolyEdgeSymmetric;
	IwTA<IwPolyEdge *> liwEdges;
	IwTA<IwPolyEdge *> liwCommonEdges;

	try {
		if ( iwFace1 == NULL || iwFace2 == NULL || iwFace1 == iwFace2 ) return NULL;
		iwFace1->GetPolyEdges( liwEdges );
		for ( uli = 0; uli < liwEdges.GetSize( ); uli++ ) {
			iwPolyFace = liwEdges[ uli ]->GetPolyFace( );
			iwPolyEdgeSymmetric = liwEdges[ uli ]->GetSymmetricPolyEdge( );
			if ( iwPolyEdgeSymmetric == NULL ) continue;
			iwPolyFaceSymmetric = iwPolyEdgeSymmetric->GetPolyFace( );
			if ( ( iwPolyFace == iwFace1 && iwPolyFaceSymmetric == iwFace2 ) || ( iwPolyFace == iwFace2 && iwPolyFaceSymmetric == iwFace1 ) ) {
				if ( iwPolyEdgeSymmetric->GetUserIndex1( ) < ULONG_MAX ) liwCommonEdges.Add( iwPolyEdgeSymmetric );
				else
					liwCommonEdges.Add( liwEdges[ uli ] );
			}
		}
	} catch ( Exception &e ) {
#ifdef _DEBUG
		_MessageBox( e.ToString( ), _GetTranslatedString( "IDS_WARNING" ), mtWarning, TMsgDlgButtons( ) << mbOK );
#endif
		liwCommonEdges.RemoveAll( );
	}
	return liwCommonEdges;
}

//-------------------------------------------------------------------------------------
// Función para encontrar los vertices compartidos entre 2 caras.
// iwFace1 - Puntero de la cara 1
// iwFace1 - Puntero de la cara 2
// Devuelve la lista de vertices compartidos o NULL si no los hubiera
IwTA<IwPolyVertex *> TPBrepData::GetCommonVerticesBetweenFaces( IwPolyFace *iwFace1, IwPolyFace *iwFace2 )
{
	IwTA<IwPolyVertex *> liwVertices1, liwVertices2;

	try {
		if ( iwFace1 == NULL || iwFace2 == NULL || iwFace1 == iwFace2 ) return liwVertices1;
		iwFace1->GetPolyVertices( liwVertices1 );
		iwFace2->GetPolyVertices( liwVertices2 );

		liwVertices1.Append( liwVertices2 );

		liwVertices1.GetDuplicates( liwVertices2 );
		return liwVertices2;
	} catch ( Exception &e ) {
#ifdef _DEBUG
		_MessageBox( e.ToString( ), _GetTranslatedString( "IDS_WARNING" ), mtWarning, TMsgDlgButtons( ) << mbOK );
#endif
	}
	liwVertices1.RemoveAll( );
	return liwVertices1;
}

//-------------------------------------------------------------------------------------
// Función para encontrar las aristas adyacentes a otra
IwTA<IwPolyEdge *> TPBrepData::GetAdjacentEdges( IwPolyEdge *iwEdge )
{
	ULONG uli, ulj;
	IwTA<IwPolyEdge *> liwAdjacentPolyEdges, liwEdgesAux;
	IwTA<IwPolyVertex *> liwPolyVertexFromEdge;

	if ( iwEdge == NULL ) return liwAdjacentPolyEdges;

	liwPolyVertexFromEdge.Add( iwEdge->GetStartVertex( ) );
	liwPolyVertexFromEdge.Add( iwEdge->GetEndVertex( ) );
	for ( uli = 0; uli < liwPolyVertexFromEdge.GetSize( ); uli++ ) {
		liwPolyVertexFromEdge[ uli ]->GetPolyEdges( liwEdgesAux );
		for ( ulj = 0; ulj < liwEdgesAux.GetSize( ); ulj++ ) {
			if ( liwEdgesAux[ ulj ] == iwEdge ) continue;
			liwAdjacentPolyEdges.AddUnique( liwEdgesAux[ ulj ] );
		}
	}

	return liwAdjacentPolyEdges;
}

//-------------------------------------------------------------------------------------
// Función para encontrar las caras adyacentes a otra
void TPBrepData::GetAdjacentFaces( IwPolyFace *iwFace, IwTA<IwPolyFace *> *faces, bool useSeams, bool onlybyedges )
{
	bool foundedSeam;
	int i, j;
	ULONG uli, ulj, ulIndex;
	IwTA<IwPolyFace *> liwFacesAux;
	IwTA<IwPolyVertex *> liwPolyVertexFromFace, vertexs;
	IwTA<IwPolyEdge *> edges;
	IwPolyEdge *iwPolyEdgeFounded;
	IwTA<IwPolyVertex *> vertexsFromSeams;

	if ( !faces || iwFace == NULL ) return;
	faces->ReSet( );
	if ( useSeams && SeamEdges.GetSize( ) ) {
		for ( i = 0; i < (int) SeamEdges.GetSize( ); i++ ) {
			vertexsFromSeams.AddUnique( SeamEdges[ i ]->GetStartVertex( ) );
			vertexsFromSeams.AddUnique( SeamEdges[ i ]->GetEndVertex( ) );
		}
	}

	iwFace->GetPolyVertices( liwPolyVertexFromFace );
	for ( uli = 0; uli < liwPolyVertexFromFace.GetSize( ); uli++ ) {
		liwFacesAux = GetConnectedFacesFromVertex( liwPolyVertexFromFace[ uli ] );
		for ( ulj = 0; ulj < liwFacesAux.GetSize( ); ulj++ ) {
			if ( liwFacesAux[ ulj ] == iwFace ) continue;
			if ( useSeams && SeamEdges.GetSize( ) ) {
				// Comprobación 1: Si comparten una arista y es una costura, entonces no se añade
				foundedSeam = false;
				edges = GetCommonEdgesBetweenFaces( iwFace, liwFacesAux[ ulj ] );
				if ( edges.GetSize( ) > 0 ) {
					for ( i = 0; i < (int) SeamEdges.GetSize( ); i++ ) {
						for ( j = 0; j < (int) edges.GetSize( ); j++ )
							if ( FindElement_Edge( &SeamEdges, edges[ j ], ulIndex, iwPolyEdgeFounded ) ) {
								foundedSeam = true;
								break;
							}
						if ( foundedSeam ) break;
					}
					if ( foundedSeam ) continue;
				} else {
					if ( onlybyedges ) continue;
					if ( !foundedSeam ) {
						// Comprobación 2: Si comparten vertice de costura y no comparten ninguna arista, entonces no se añade
						vertexs = GetCommonVerticesBetweenFaces( iwFace, liwFacesAux[ ulj ] );
						for ( j = 0; j < (int) vertexs.GetSize( ); j++ ) {
							if ( vertexsFromSeams.FindElement( vertexs[ j ], ulIndex ) ) {
								foundedSeam = true;
								break;
							}
						}
					}
					if ( foundedSeam ) continue;
				}
			} else if ( onlybyedges ) {
				edges = GetCommonEdgesBetweenFaces( iwFace, liwFacesAux[ ulj ] );
				if ( edges.GetSize( ) == 0 ) continue;
			}
			faces->AddUnique( liwFacesAux[ ulj ] );
		}
	}
}

//-------------------------------------------------------------------------------------
// Función de búsqueda de una arista en una lista teniendo en cuenta sólo si sus vertices final e inicial son iguales, ya sean simétricas o no
// liwPolyEdges - Lista de aristas donde se debe buscar
// iwPolyEdgeToFind - Puntero de la arista que queremos encontrar
// ulIndex - Índice de la arista encontrada. -1 si no se ha encontrado
// iwPolyEdgeFounded - Arista encontrada. Podría ser que fuera la simétrica o la propia arista.
// Devuelve true si se ha encontrado o false en caso contrario
bool TPBrepData::FindElement_Edge( IwTA<IwPolyEdge *> *liwPolyEdges, IwPolyEdge *iwPolyEdgeToFind, ULONG &ulIndex, IwPolyEdge *&iwPolyEdgeFounded )
{
	bool bFounded;
	IwPolyEdge *iwEdge_Simmetric;

	ulIndex = -1;
	bFounded = false;
	iwPolyEdgeFounded = NULL;
	try {
		if ( iwPolyEdgeToFind == NULL ) return false;

		iwEdge_Simmetric = iwPolyEdgeToFind->GetSymmetricPolyEdge( );
		bFounded = liwPolyEdges->FindElement( iwPolyEdgeToFind, ulIndex );

		if ( !bFounded ) {
			if ( iwEdge_Simmetric ) {
				bFounded = liwPolyEdges->FindElement( iwEdge_Simmetric, ulIndex );
				if ( bFounded ) iwPolyEdgeFounded = iwEdge_Simmetric;
			}
		} else
			iwPolyEdgeFounded = iwPolyEdgeToFind;
	} catch ( Exception &e ) {
#ifdef _DEBUG
		_MessageBox( e.ToString( ), _GetTranslatedString( "IDS_WARNING" ), mtWarning, TMsgDlgButtons( ) << mbOK );
#endif
	}

	return bFounded;
}

//-------------------------------------------------------------------------------------
// Función de búsqueda de una sola cara que comparta la lista de vertices
// liwVertices - Lista de vertices que deberian compartir cara
// Devuelve la cara o NULL en caso de no haber encontrado ninguna común
IwPolyFace *TPBrepData::GetUniqueFaceFromVertices( IwTA<IwPolyVertex *> liwVertices )
{
	bool bFounded;
	ULONG ulIndex, i, j;
	IwTA<IwPolyFace *> liwPolyFaces, liwFinalPolyFaces, liwCommonFaces;

	try {
		liwVertices[ 0 ]->GetPolyFaces( liwFinalPolyFaces );
		for ( i = 1; i < liwVertices.GetSize( ); i++ ) {
			liwVertices[ i ]->GetPolyFaces( liwPolyFaces );
			liwCommonFaces.RemoveAll( );
			for ( j = 0; j < liwPolyFaces.GetSize( ); j++ ) {
				bFounded = liwFinalPolyFaces.FindElement( liwPolyFaces[ j ], ulIndex );
				if ( bFounded ) liwCommonFaces.Add( liwPolyFaces[ j ] );
			}
			liwFinalPolyFaces = liwCommonFaces;
		}
		if ( liwFinalPolyFaces.GetSize( ) == 1 ) return liwFinalPolyFaces[ 0 ];
	} catch ( ... ) {
	}

	return NULL;
}

//-------------------------------------------------------------------------------------
// Función cálculo del perímetro al cuadrado de una cara
// iwFace - Cara propuesta para el cálculo de su perímetro
// Devuelve el perímetro al cuadrado
double TPBrepData::PerimeterSquared( IwPolyFace *iwFace )
{
	ULONG uli;
	double dPerimeterSquared;
	IwPoint3d *iwPoint3d1, *iwPoint3d2;
	IwTA<IwPolyVertex *> liwFaceVertices;

	dPerimeterSquared = -1;
	try {
		NER( iwFace );
		iwFace->GetPolyVertices( liwFaceVertices );

		dPerimeterSquared = 0;
		for ( uli = 0; uli < liwFaceVertices.GetSize( ) - 1; uli++ ) {
			iwPoint3d1 = liwFaceVertices[ uli ]->GetPointPtr( );
			iwPoint3d2 = liwFaceVertices[ uli + 1 ]->GetPointPtr( );
			dPerimeterSquared += iwPoint3d1->DistanceBetweenSquared( *iwPoint3d2 );
		}
		dPerimeterSquared += liwFaceVertices[ liwFaceVertices.GetSize( ) - 1 ]->GetPointPtr( )->DistanceBetweenSquared( *( liwFaceVertices[ 0 ]->GetPointPtr( ) ) );
	} catch ( Exception &e ) {
#ifdef _DEBUG
		_MessageBox( e.ToString( ), _GetTranslatedString( "IDS_WARNING" ), mtWarning, TMsgDlgButtons( ) << mbOK );
#endif
	}

	return dPerimeterSquared;
}

//-------------------------------------------------------------------------------------
// Función cálculo del perímetro al cuadrado de una cara
// iFace - Indice de la cara propuesta para el cálculo de su perímetro
// Devuelve el perímetro al cuadrado
double TPBrepData::PerimeterSquared( int iFace )
{
	double dPerimeterSquared;
	IwPolyFace *iwFace;
	IwTA<IwPolyVertex *> liwFaceVertices;

	dPerimeterSquared = -1;
	try {
		if ( iFace >= 0 && iFace < (int) PBrepFaces.GetSize( ) ) {
			iwFace = PBrepFaces[ iFace ];
			dPerimeterSquared = PerimeterSquared( iwFace );
		}
	} catch ( Exception &e ) {
#ifdef _DEBUG
		_MessageBox( e.ToString( ), _GetTranslatedString( "IDS_WARNING" ), mtWarning, TMsgDlgButtons( ) << mbOK );
#endif
	}

	return dPerimeterSquared;
}

//-------------------------------------------------------------------------------------
// Función cálculo del perímetro de una cara
// iFace - Indice de la cara propuesta para el cálculo de su perímetro
// Devuelve el perímetro
double TPBrepData::Perimeter( int iFace )
{
	double dPerimeter;
	IwPolyFace *iwFace;
	IwTA<IwPolyVertex *> liwFaceVertices;

	dPerimeter = -1;
	try {
		if ( iFace >= 0 && iFace < (int) PBrepFaces.GetSize( ) ) {
			iwFace = PBrepFaces[ iFace ];
			dPerimeter = Perimeter( iwFace );
		}
	} catch ( Exception &e ) {
#ifdef _DEBUG
		_MessageBox( e.ToString( ), _GetTranslatedString( "IDS_WARNING" ), mtWarning, TMsgDlgButtons( ) << mbOK );
#endif
	}

	return dPerimeter;
}

//-------------------------------------------------------------------------------------
// Función cálculo del perímetro de una cara
// iwFace - Cara propuesta para el cálculo de su perímetro
// Devuelve el perímetro
double TPBrepData::Perimeter( IwPolyFace *iwFace )
{
	ULONG uli;
	double dPerimeter;
	IwTA<IwPolyEdge *> liwFaceEdges;

	dPerimeter = -1;
	try {
		NER( iwFace );
		iwFace->GetPolyEdges( liwFaceEdges );

		dPerimeter = 0;
		for ( uli = 0; uli < liwFaceEdges.GetSize( ) - 1; uli++ ) {
			dPerimeter += liwFaceEdges[ uli ]->Length( );
		}
	} catch ( Exception &e ) {
#ifdef _DEBUG
		_MessageBox( e.ToString( ), _GetTranslatedString( "IDS_WARNING" ), mtWarning, TMsgDlgButtons( ) << mbOK );
#endif
	}

	return dPerimeter;
}

//-------------------------------------------------------------------------------------
// Comprueba si el vértice tiene caras sin seleccionar intercaladas entre otras caras seleccionadas, lo que puede dar problemas en extrude, inset o bevel
bool TPBrepData::AreAnyNonSelFaces( TOGLTransf *OGLTransf, IwPolyVertex *vertex )
{
	bool isFace1Selected, isFace2Selected;
	int i, count, sizeEdges;
	;
	IwPolyEdge *edge, *edgeSym;
	IwPolyFace *face1, *face2;
	IwTA<IwPolyEdge *> edges;

	if ( !OGLTransf ) return false;

	count = 0;
	vertex->GetPolyEdges( edges );
	sizeEdges = (int) edges.GetSize( );
	for ( i = 0; i < sizeEdges; i++ ) {
		edge = edges[ i ];
		face1 = edge->GetPolyFace( );
		isFace1Selected = IsFaceSelected( OGLTransf, face1->GetIndexExt( ) );
		edgeSym = edge->GetSymmetricPolyEdge( );
		if ( edgeSym ) {
			face2 = edgeSym->GetPolyFace( );
			isFace2Selected = IsFaceSelected( OGLTransf, face2->GetIndexExt( ) );
			if ( ( isFace1Selected && !isFace2Selected ) || ( !isFace1Selected && isFace2Selected ) ) count++;
		} else if ( edge->IsLamina( ) && isFace1Selected )
			count++;
	}

	return count > 4;
}

//------------------------------------------------------------------------------
// Devuelve las dos caras adyacentes que tienen el vértice en común
IwTA<IwPolyFace *> TPBrepData::GetAdjacentFacesFromVertexFace( IwPolyFace *faceIn, IwPolyVertex *vertex )
{
	bool found;
	int i, numEdges;
	ULONG num;
	IwPolyFace *faceCurrent;
	IwPolyFace *face1Out, *face2Out;
	IwPolyEdge *edge, *edgeSym;
	IwTA<IwPolyEdge *> edges;
	IwTA<IwPolyFace *> facesOut;

	found = false;

	face1Out = 0;
	face2Out = 0;

	faceIn->GetPolyEdges( edges );
	numEdges = (int) edges.GetSize( );

	for ( i = 0; i < numEdges; i++ ) {
		edge = edges[ i ];
		if ( edge->GetStartVertex( ) == vertex || edge->GetEndVertex( ) == vertex ) {
			edgeSym = edge->GetSymmetricPolyEdge( );
			if ( edgeSym ) {
				faceCurrent = edgeSym->GetPolyFace( );

				if ( faceCurrent && !found ) {
					face1Out = faceCurrent;
					found = true;
				} else if ( faceCurrent && found ) {
					face2Out = faceCurrent;
					break;
				}
			}
		}
	}

	// Si estamos a mitad de hacer inset y el PBrepFaces no ha sido actualizada, testeamos solo las caras del PBrepFaces
	if ( !PBrepFaces.FindElement( face1Out, num ) ) face1Out = 0;

	if ( !PBrepFaces.FindElement( face2Out, num ) ) face2Out = 0;

	facesOut.Add( face1Out );
	facesOut.Add( face2Out );

	return facesOut;
}

//------------------------------------------------------------------------------
// Comprueba si una cara está conectada por un vértice a un grupo de caras seleccionadas
bool TPBrepData::IsFaceConnectedToSelGroupByVertex( TOGLTransf *OGLTransf, IwPolyFace *face, IwTA<IwPolyFace *> *faces, IwPolyVertex *vertex )
{
	bool stop1, stop2;
	int count, maxIter;
	ULONG num;
	IwPolyFace *face1, *face2, *faceCurrent1, *faceCurrent2, *lastFace, *faceAux;
	IwTA<IwPolyFace *> conFaces;
	IwTA<IwPolyEdge *> edges;

	stop1 = stop2 = false;
	maxIter = 10000;

	conFaces = GetAdjacentFacesFromVertexFace( face, vertex );
	face1 = conFaces[ 0 ];
	face2 = conFaces[ 1 ];
	if ( !face1 && !face2 ) return false;
	if ( faces->FindElement( face1, num ) ) return true;
	if ( faces->FindElement( face2, num ) ) return true;

	if ( face1 && IsFaceSelected( OGLTransf, face1->GetIndexExt( ) ) ) faceCurrent1 = face1;
	else
		stop1 = true;
	if ( face2 && IsFaceSelected( OGLTransf, face2->GetIndexExt( ) ) ) faceCurrent2 = face2;
	else
		stop2 = true;

	// face 1
	lastFace = face;
	count = 0;
	while ( !stop1 ) {
		conFaces = GetAdjacentFacesFromVertexFace( faceCurrent1, vertex );
		face1 = conFaces[ 0 ];
		face2 = conFaces[ 1 ];
		if ( !face1 && !face2 ) break;
		faceAux = faceCurrent1;
		if ( face1 == lastFace ) faceCurrent1 = face2;
		else
			faceCurrent1 = face1;

		if ( !faceCurrent1 ) break;
		if ( !IsFaceSelected( OGLTransf, faceCurrent1->GetIndexExt( ) ) ) break;
		if ( faces->FindElement( faceCurrent1, num ) ) return true;

		if ( face1 == face2 ) break;
		lastFace = faceAux;

		count++;
		if ( count > maxIter ) break;
	}

	// face 2
	lastFace = face;
	count = 0;
	while ( !stop2 ) {
		conFaces = GetAdjacentFacesFromVertexFace( faceCurrent2, vertex );
		face1 = conFaces[ 0 ];
		face2 = conFaces[ 1 ];
		if ( !face1 && !face2 ) break;
		faceAux = faceCurrent2;
		if ( face1 == lastFace ) faceCurrent2 = face2;
		else
			faceCurrent2 = face1;

		if ( !faceCurrent2 ) break;
		if ( !IsFaceSelected( OGLTransf, faceCurrent2->GetIndexExt( ) ) ) break;
		if ( faces->FindElement( faceCurrent2, num ) ) return true;

		if ( face1 == face2 ) break;
		lastFace = faceAux;

		count++;
		if ( count > maxIter ) break;
	}

	return false;
}

//-------------------------------------------------------------------------------------

bool TPBrepData::IsFaceIsolated( TOGLTransf *OGLTransf, int ind )
{
	bool bound;
	int i;
	IwPolyFace *f;
	IwPolyVertex *v1;
	IwTA<IwPolyVertex *> vertexs, allvertexs;
	TInteger_List vertexsUserIndex1List;

	if ( !GetPBrep( OGLTransf ) ) return false;
	if ( ind < 0 || ind >= (int) PBrepFaces.GetSize( ) ) return false;

	f = GetPBrepFace( OGLTransf, ind );
	if ( !f ) return false;

	bound = false;
	GetListsUserIndex1( &vertexsUserIndex1List, 0 );
	InitUserIndex1( true, false );

	f->GetPolyVertices( allvertexs );
	for ( i = 0; i < (int) allvertexs.GetSize( ); i++ )
		allvertexs.GetAt( i )->SetUserIndex1( 1 );

	do {
		bound = allvertexs.GetAt( allvertexs.GetSize( ) - 1 )->IsBoundaryVertex( );
		if ( !bound ) {
			allvertexs.GetAt( allvertexs.GetSize( ) - 1 )->GetAdjacentVertices( vertexs );
			allvertexs.RemoveLast( );
			for ( i = 0; i < (int) vertexs.GetSize( ); i++ ) {
				v1 = vertexs.GetAt( i );
				if ( v1->GetUserIndex1( ) == 0 ) {
					allvertexs.Add( v1 );
					v1->SetUserIndex1( 1 );
				}
			}
		}
	} while ( allvertexs.GetSize( ) && !bound );

	SetListsUserIndex1( &vertexsUserIndex1List, 0 );

	return bound;
}

//-------------------------------------------------------------------------------------

void TPBrepData::GetIsolatedFaces( TOGLTransf *OGLTransf, int guestface, IwTA<IwPolyFace *> *faces, IwTA<IwPolyEdge *> *boundaryedges )
{
	int i;
	IwPolyFace *f;
	IwTA<IwPolyEdge *> edges;
	IwTA<IwPolyFace *> facesorg, facesAux;
	TInteger_List vertexsUserIndex1List;

	if ( !GetPBrep( OGLTransf ) || !faces || !boundaryedges ) return;
	if ( guestface < 0 || guestface >= (int) PBrepFaces.GetSize( ) ) return;

	f = GetPBrepFace( OGLTransf, guestface );
	if ( !f ) return;

	faces->ReSet( );
	boundaryedges->ReSet( );
	GetListsUserIndex1( &vertexsUserIndex1List, 0 );
	InitUserIndex1( false, true );

	faces->Add( f );
	f->SetUserIndex1( 1 );
	f->GetPolyEdges( edges );
	for ( i = 0; i < (int) edges.GetSize( ); i++ )
		if ( edges.GetAt( i )->IsBoundary( ) ) boundaryedges->AddUnique( edges.GetAt( i ) );
	GetAdjacentFaces( f, &facesorg );
	if ( facesorg.GetSize( ) == 0 ) {
		SetListsUserIndex1( &vertexsUserIndex1List, 0 );
		return;
	}

	do {
		f = facesorg.GetAt( facesorg.GetSize( ) - 1 );
		facesorg.RemoveLast( );
		if ( f->GetUserIndex1( ) == 0 ) {
			faces->Add( f );
			f->GetPolyEdges( edges );
			for ( i = 0; i < (int) edges.GetSize( ); i++ )
				if ( edges.GetAt( i )->IsBoundary( ) ) boundaryedges->AddUnique( edges.GetAt( i ) );
			f->SetUserIndex1( 1 );
			GetAdjacentFaces( f, &facesAux );
			facesorg.Append( facesAux );
		}
	} while ( facesorg.GetSize( ) );

	SetListsUserIndex1( &vertexsUserIndex1List, 0 );
}

//-------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------
// Obtiene un polilinea entre los vértices de la lista
// Devuelve una TCadPolyline con sus puntos como los vértices de la malla
// liVertices - Lista de vértices
// bValid - Devuelve true si era una lista válidad de vértices consecutivos
TCadPolyline *TPBrepData::GetPolylineFromVertices( TOGLTransf *oglTransf, IwTA<int> *liVertices, bool &bValid )
{
	int iVertex;
	ULONG uli;
	TCadPolyline *polyline;
	IwPoint3d *iwPoint3d;
	IwTA<T3DPoint> lpt3d2;
	T3DPoint pto;
	T3DVector vect3d;
	T3DRect bbBrep;

	bValid = false;
	try {
		if ( liVertices == NULL || ( *liVertices ).GetSize( ) == 0 ) return NULL;

		polyline = new TCadPolyline( );

		for ( uli = 0; uli < ( *liVertices ).GetSize( ); uli++ ) {
			iVertex = ( *liVertices )[ uli ];
			iwPoint3d = PBrepVertexs[ iVertex ]->GetPointPtr( );
			pto = T3DPoint( iwPoint3d->x, iwPoint3d->y, iwPoint3d->z );
			lpt3d2.Add( pto );
			polyline->Add( oglTransf, pto );
		}

		RefEnt->CalcBoundRect( oglTransf, bbBrep );
		vect3d = T3DVector( bbBrep.BottomRightBack( ) - bbBrep.TopLeftFront( ) );
		if ( polyline->GetClose( ) != ENT_OPEN || polyline->Perimeter( oglTransf ) > vect3d.Modulo( ) * 2 ) bValid = false;
		else
			bValid = true;
	} catch ( Exception &e ) {
#ifdef _DEBUG
		_MessageBox( e.ToString( ), _GetTranslatedString( "IDS_WARNING" ), mtWarning, TMsgDlgButtons( ) << mbOK );
#endif
	}

	return polyline;
}

//-------------------------------------------------------------------------------------
// Lo que forma el ring no son las aristas, sino los puntos intermedios de las mismas conectados
IwTA<IwPolyEdge *> TPBrepData::GetEdgeRingFromFacesConnection( TOGLTransf *OGLTransf, ULONG ind )
{
	bool founded;
	int i;
	ULONG indexAux;
	IwPolyEdge *edgeOrig, *edgeAux;
	IwPolyFace *faceCurrent;
	IwTA<IwPolyEdge *> edgesResult;
	IwTA<IwPolyFace *> faces, facesAux;

	edgeOrig = GetPBrepEdge( OGLTransf, ind );

	if ( !edgeOrig ) return edgesResult;
	founded = FindElement_Edge( &PBrepEdges, edgeOrig, indexAux, edgeOrig );
	if ( !founded ) return edgesResult;
	edgesResult.AddUnique( edgeOrig );

	faces = GetConnectedFacesFromEdge( edgeOrig );
	if ( faces.GetSize( ) > 2 || faces.GetSize( ) == 0 ) return edgesResult;

	for ( i = 0; i < (int) faces.GetSize( ); i++ ) {
		edgeAux = edgeOrig;
		faceCurrent = faces[ i ];
		do {
			edgeAux = GetOppositeEdgeFromFace( edgeAux, faceCurrent, true );
			if ( edgeAux ) {
				founded = FindElement_Edge( &PBrepEdges, edgeAux, indexAux, edgeAux );
				if ( founded ) {
					if ( !edgesResult.AddUnique( edgeAux ) ) {
						if ( edgesResult.GetSize( ) > 0 && AreEqual( edgeAux, edgesResult[ 0 ] ) ) edgesResult.Add( edgeAux ); // para cerrar el ring
						break;
					}

					facesAux = GetConnectedFacesFromEdge( edgeAux );
					if ( facesAux.GetSize( ) == 2 ) {
						if ( facesAux.FindElement( faceCurrent, indexAux ) ) {
							facesAux.RemoveAt( indexAux );
							faceCurrent = facesAux[ 0 ];
						} else
							edgeAux = NULL;
					} else
						edgeAux = NULL;
				} else
					edgeAux = NULL;
			}
		} while ( edgeAux );
		edgesResult.ReverseArray( 0, edgesResult.GetSize( ) );
	}

	return edgesResult;
}

//-------------------------------------------------------------------------------------
// La funcion presupone que las aristas estan ordenadas
TCadPolyline *TPBrepData::GetPolylineFromEdgesAtParam( TOGLTransf *oglTransf, IwTA<IwPolyEdge *> edges, double param )
{
	bool founded;
	int i;
	ULONG index;
	IwPoint3d point3d;
	IwTA<IwPolyFace *> faces;
	IwPolyEdge *edgeCurrent, *edgeGoal;
	IwTA<IwPolyEdge *> edgesFromFace;
	TCadPolyline *poly;

	if ( !oglTransf || edges.GetSize( ) < 2 ) return NULL;
	if ( param < 0 || param > 1 ) return NULL;

	edgeCurrent = edges[ 0 ];
	if ( edgeCurrent->EvaluatePoint( param, point3d ) != IW_SUCCESS ) return NULL;

	poly = new TCadPolyline( );
	poly->Add( oglTransf, T3DPoint( point3d.x, point3d.y, point3d.z ) );

	for ( i = 1; i < (int) edges.GetSize( ); i++ ) {
		faces = GetCommonFacesBetweenEdges( edgeCurrent, edges[ i ] );
		if ( faces.GetSize( ) == 0 ) return poly;
		faces[ 0 ]->GetPolyEdges( edgesFromFace );

		// Primero buscamos el anterior para ver si esta en la lista y dependiendo de eso nos quedamos con el que encuentre
		// en la lista de caras o su simetrico
		founded = edgesFromFace.FindElement( edgeCurrent, index );
		if ( !founded ) {
			founded = edgesFromFace.FindElement( edges[ i ], index );
			if ( founded ) edgeGoal = edges[ i ];
			else
				edgeGoal = edges[ i ]->GetSymmetricPolyEdge( );
		} else {
			founded = edgesFromFace.FindElement( edges[ i ], index );
			if ( !founded ) edgeGoal = edges[ i ];
			else
				edgeGoal = edges[ i ]->GetSymmetricPolyEdge( );
		}

		if ( edgeGoal ) {
			edgeCurrent = edgeGoal;
			if ( edgeCurrent->EvaluatePoint( param, point3d ) != IW_SUCCESS ) {
				delete poly;
				return NULL;
			}
		} else {
			// Si pasa por este caso es pq es un borde
			edgeCurrent = edges[ i ];
			if ( edgeCurrent->EvaluatePoint( 1 - param, point3d ) != IW_SUCCESS ) {
				delete poly;
				return NULL;
			}
		}

		poly->Add( oglTransf, T3DPoint( point3d.x, point3d.y, point3d.z ) );
	}

	return poly;
}

//-------------------------------------------------------------------------------------

// Se ordena una lista de aristas de la High, correspondientes a una Low.
// iniPoint es el punto inicial de la arista Low
bool TPBrepData::OrderHighEdges( TOGLTransf *OGLTransf, TOGLPolygon *poledgeSelect, TOGLPolygon *poledgeSelectOrder )
{
	int i, j, nPoints;
	T3DPoint point3D, point3D_2;
	TOGLPolygon polAux;

	if ( !OGLTransf || !poledgeSelect || !poledgeSelectOrder ) return false;
	nPoints = poledgeSelect->Count( ) / 2;
	if ( nPoints == 0 ) return false;

	poledgeSelectOrder->Clear( );
	polAux.Set( poledgeSelect );

	// Bucamos el segmento cuyo primer punto no aparezca como fin de otro. Será el primer segmento
	for ( i = 0; i < nPoints; i++ ) {
		point3D = polAux.GetItem( i * 2 )->v.GetPoint( );
		for ( j = 0; j < nPoints; j++ ) {
			if ( i != j ) {
				point3D_2 = polAux.GetItem( j * 2 + 1 )->v.GetPoint( );
				if ( point3D.Similar( point3D_2 ) ) break;
			}
		}
		if ( j == nPoints ) break;
	}
	if ( i == nPoints ) return false;

	// En la posición i está el primer segmento
	poledgeSelectOrder->AddItem( polAux.GetItem( i * 2 ) );
	poledgeSelectOrder->AddItem( polAux.GetItem( i * 2 + 1 ) );
	polAux.DeleteItem( i * 2 );
	polAux.DeleteItem( i * 2 );
	nPoints--;

	point3D = poledgeSelectOrder->GetItem( 1 )->v.GetPoint( );
	while ( nPoints > 0 ) {
		for ( i = 0; i < nPoints; i++ ) {
			point3D_2 = polAux.GetItem( i * 2 )->v.GetPoint( );
			if ( point3D_2.Similar( point3D ) ) {
				point3D = polAux.GetItem( i * 2 + 1 )->v.GetPoint( );
				poledgeSelectOrder->AddItem( polAux.GetItem( i * 2 ) );
				poledgeSelectOrder->AddItem( polAux.GetItem( i * 2 + 1 ) );
				polAux.DeleteItem( i * 2 );
				polAux.DeleteItem( i * 2 );
				break;
			}
		}
		if ( i == nPoints ) return false;
		nPoints--;
	}

	return true;
}

//-------------------------------------------------------------------------------------

// Se obtiene un grupo de polilíneas a partir de la selección actual de aristas
void TPBrepData::GetPolylinesFromSelectedEdges( TOGLTransf *OGLTransf, TCadGroup *group, bool fromSubdivision, bool allEdges )
{
	int i, j, k, index, nLines, nEdges, nHighEdges, nHighEdgesSelect;
	vector<vector<int> > lines;
	TCadPolyline *polyline;
	T3DPoint point3D;
	TOGLPolygon *poledges, poledgeSelect, poledgeSelectOrder;
	IwPolyEdge *iwEdge;
	IwTA<IwPolyEdge *> iwEdges;
	IwTA<IwTA<IwPolyEdge *> > iwEdgesOrdered;

	if ( !OGLTransf || !group ) return;

	group->Clear( );

	if ( !GetDisjointGroupEdges( OGLTransf, &lines, false, allEdges ) ) return;
	nLines = (int) lines.size( );
	if ( nLines == 0 ) return;

	if ( fromSubdivision ) {
		poledges = ToDepMesh( RefEnt->GetDepMeshes( )->GetShape( 0 ) )->GetSubdivisionEdges( OGLTransf );
		nHighEdges = poledges->Count( ) / 2;
	}

	for ( i = 0; i < nLines; i++ ) {
		nEdges = (int) lines[ i ].size( );
		if ( nEdges > 0 ) {
			iwEdges.RemoveAll( );
			for ( j = 0; j < nEdges; j++ ) {
				iwEdge = GetPBrepEdge( OGLTransf, lines[ i ][ j ] );
				iwEdges.Add( iwEdge );
			}
			if ( GetEdgesOrdered( &iwEdges, &iwEdgesOrdered ) ) {
				polyline = new TCadPolyline( );
				for ( j = 0; j < nEdges; j++ ) {
					iwEdge = iwEdgesOrdered[ 0 ][ j ];

					if ( fromSubdivision ) {
						poledgeSelect.Clear( );
						index = iwEdge->GetUserIndex1( );
						for ( k = 0; k < nHighEdges; k++ ) {
							if ( (int) poledges->GetItem( k * 2 )->t.v[ 0 ] == index ) {
								poledgeSelect.AddItem( poledges->GetItem( k * 2 ) );
								poledgeSelect.AddItem( poledges->GetItem( k * 2 + 1 ) );
							}
						}
						if ( !OrderHighEdges( OGLTransf, &poledgeSelect, &poledgeSelectOrder ) ) {
							delete polyline;
							return;
						}
						nHighEdgesSelect = poledgeSelectOrder.Count( ) / 2;
						for ( k = 0; k < nHighEdgesSelect; k++ ) {
							point3D = poledgeSelectOrder.GetItem( k * 2 )->v.GetPoint( );
							polyline->Add( OGLTransf, point3D );
						}
					} else {
						point3D = T3DPoint( iwEdge->GetStartPoint( ).x, iwEdge->GetStartPoint( ).y, iwEdge->GetStartPoint( ).z );
						polyline->Add( OGLTransf, point3D );
					}
				}
				if ( fromSubdivision ) {
					point3D = poledgeSelectOrder.GetItem( ( nHighEdgesSelect - 1 ) * 2 + 1 )->v.GetPoint( );
					polyline->Add( OGLTransf, point3D );
				} else {
					point3D = T3DPoint( iwEdge->GetEndPoint( ).x, iwEdge->GetEndPoint( ).y, iwEdge->GetEndPoint( ).z );
					polyline->Add( OGLTransf, point3D );
				}
				group->Add( polyline );
			}
		}
	}
}

//-------------------------------------------------------------------------------------
// Obtiene una lista de aristas a partir de una lista de vertices conectados entre si cada uno con el siguiente
// Devuelve true en caso de exito. False si no se ha encontrado alguna arista
// liVertices - Lista de vértices
// liEdges - Devuelve la lista de aristas
bool TPBrepData::GetEdgeListFromVerticesList( IwTA<TDataIntIntForVertexPaths> *liVertices, IwTA<TDataIntIntForVertexPaths> *liEdges )
{
	int iVertex1, iVertex2;
	ULONG uli;
	IwPolyEdge *iwEdge;
	IwTA<T3DPoint> lpt3d2;
	TDataIntIntForVertexPaths dataIntIntForVertexPaths;

	try {
		if ( liVertices == NULL || ( *liVertices ).GetSize( ) == 0 ) return false;
		if ( liEdges == NULL ) return false;

		dataIntIntForVertexPaths.iNumBranches = 0;
		for ( uli = 0; uli < ( *liVertices ).GetSize( ) - 1; uli++ ) {
			iVertex1 = ( *liVertices )[ uli ].iElementIndex;
			iVertex2 = ( *liVertices )[ uli + 1 ].iElementIndex;
			iwEdge = GetEdgeFromVertices( iVertex1, iVertex2 );
			if ( !iwEdge ) return false;
			dataIntIntForVertexPaths.iElementIndex = iwEdge->GetUserIndex1( );
			if ( dataIntIntForVertexPaths.iElementIndex >= 0 ) liEdges->Add( dataIntIntForVertexPaths );
			else
				return false;
		}
		return true;
	} catch ( Exception &e ) {
#ifdef _DEBUG
		_MessageBox( e.ToString( ), _GetTranslatedString( "IDS_WARNING" ), mtWarning, TMsgDlgButtons( ) << mbOK );
#endif
	}

	return false;
}

// =============================================================================
// TPBrepData - Costuras
// =============================================================================

// En index se devuelve la posicion de la costura dentro de la lista de costuras
bool TPBrepData::IsEdgeSeam( TOGLTransf *OGLTransf, int ind, int *index )
{
	if ( !GetPBrep( OGLTransf ) ) return false;

	if ( ind < 0 || ind >= (int) PBrepEdges.GetSize( ) ) return false;

	if ( !PBrepEdges[ ind ] ) return false;

	return IsEdgeSeam( PBrepEdges[ ind ], index );
}

//------------------------------------------------------------------------------

// En index1 se devuelven la posicion de la costura dentro de la lista de costuras
bool TPBrepData::IsEdgeSeam( IwPolyEdge *edge, int *index1 )
{
	ULONG index;
	IwPolyEdge *edgereal;

	if ( !edge ) return false;

	if ( edge->GetUserIndex1( ) == ULONG_MAX ) edgereal = edge->GetSymmetricPolyEdge( );
	else
		edgereal = edge;

	if ( edge->GetUserInt1( ) & MESH_EDGE_SEAM ) {
		if ( !index1 ) return true;
		if ( SeamEdges.FindElement( edgereal, index ) ) {
			if ( index1 ) ( *index1 ) = (int) index;
			return true;
		}
	}
	return false;
}

//------------------------------------------------------------------------------

IwPolyEdge *TPBrepData::GetSeamByIndex( int index )
{
	if ( index >= 0 && index < CountPBrepSeams( ) ) return SeamEdges.GetAt( index );
	return 0;
}

//------------------------------------------------------------------------------

void TPBrepData::UpdatePBrepSeamFromOGLList( TOGLTransf *OGLTransf )
{
	int i, i0, i1, i1_2;
	IwPolyEdge *edge;
	IwPolyFace *face;
	IwPolyVertex *vertexStart, *vertexEnd;
	IwTA<IwPolyFace *> faces;
	IwTA<IwPolyEdge *> seamEdges;
	IwTA<IwPolyVertex *> vertexs;

	if ( !RefEnt ) return;

	if ( !ToMesh( RefEnt ) || !ToMesh( RefEnt )->IsPolygonalMesh( ) ) return;

	DeleteAllSeamEdges( );

	if ( !ToMesh( RefEnt )->GetSeamList( ) ) return;
	if ( ToMesh( RefEnt )->GetSeamList( )->Count( ) % 4 != 0 ) return;
	for ( i = 0; i < ToMesh( RefEnt )->GetSeamList( )->Count( ); i += 4 ) {
		i0 = *ToMesh( RefEnt )->GetSeamList( )->GetItem( i );
		i1 = *ToMesh( RefEnt )->GetSeamList( )->GetItem( i + 1 );

		if ( PBrepPolListRelF[ i0 ].i0 != i0 ) continue;

		face = GetPBrepFace( OGLTransf, i0 );
		if ( !face ) continue;
		face->GetPolyVertices( vertexs );

		if ( i1 < 0 || i1 >= (int) vertexs.GetSize( ) ) continue;
		vertexStart = vertexs[ i1 ];

		i1_2 = *ToMesh( RefEnt )->GetSeamList( )->GetItem( i + 3 );

		if ( i1_2 < 0 || i1_2 >= (int) vertexs.GetSize( ) ) continue;
		vertexEnd = vertexs[ i1_2 ];
		if ( !vertexStart || !vertexEnd ) continue;

		edge = GetEdgeFromVertices( vertexStart->GetIndexExt( ), vertexEnd->GetIndexExt( ) );
		if ( !edge ) continue;
		seamEdges.Add( edge );
		edge->SetUserInt1( edge->GetUserInt1( ) | MESH_EDGE_SEAM );
		if ( edge->GetSymmetricPolyEdge( ) ) edge->GetSymmetricPolyEdge( )->SetUserInt1( edge->GetSymmetricPolyEdge( )->GetUserInt1( ) | MESH_EDGE_SEAM );
	}
	SeamEdges.Append( seamEdges );
}

//------------------------------------------------------------------------------

void TPBrepData::UpdateOGLListSeamFromPBrep( TOGLTransf *OGLTransf )
{
	int i, z, i0, i1, size_vertices, count;
	vector<int2> seam;
	TInteger_List seamIntegerList;
	IwPolyEdge *edge;
	IwPolyVertex *vertexStart, *vertexEnd;
	IwTA<IwPolyFace *> faces;
	IwTA<IwPolyVertex *> vertexs;
	TOGLPolygon *pol;
	TOGLPolygonList *OGLList;
	int2 item;
	TCadDepMesh *depMesh;

	if ( !RefEnt || !ToMesh( RefEnt ) || !ToMesh( RefEnt )->IsPolygonalMesh( ) ) return;
	if ( ToMesh( RefEnt )->GetSeamList( ) ) {
		count = ToMesh( RefEnt )->GetSeamList( )->Count( );
		ToMesh( RefEnt )->GetSeamList( )->Clear( );
	} else
		count = 0;

	if ( !count && !SeamEdges.GetSize( ) ) return;

	OGLList = RefEnt->GetOGLGeom3D( OGLTransf );
	if ( !OGLList ) return;

	for ( i = 0; i < (int) SeamEdges.GetSize( ); i++ ) {
		edge = SeamEdges[ i ];
		faces = GetConnectedFacesFromEdge( edge );
		if ( !faces.GetSize( ) ) continue;

		vertexStart = edge->GetStartVertex( );
		vertexEnd = edge->GetEndVertex( );
		faces[ 0 ]->GetPolyVertices( vertexs );

		size_vertices = vertexs.GetSize( );
		i0 = PBrepPolListRelF[ faces[ 0 ]->GetIndexExt( ) ].i0;
		i1 = PBrepPolListRelF[ faces[ 0 ]->GetIndexExt( ) ].i1 * size_vertices;
		pol = OGLList->GetItem( i0 );
		if ( !pol ) continue;
		for ( z = 0; z < size_vertices; z++ ) {
			if ( vertexs[ z ] != vertexStart && vertexs[ z ] != vertexEnd ) continue;
			// Añadimos a la lista los vertices de la cara que forman la arista
			item.i0 = i0;
			item.i1 = i1 + z;
			seamIntegerList.AddItem( &item.i0 );
			seamIntegerList.AddItem( &item.i1 );
		}
	}
	ToMesh( RefEnt )->GetSeamList( true )->Set( &seamIntegerList );
	seamIntegerList.Clear( );

	if ( ToMesh( RefEnt ) && ToMesh( RefEnt )->HasSubdivisionDepMesh( ) ) {
		depMesh = ToDepMesh( RefEnt->GetDepMeshes( )->GetShape( 0 ) );
		if ( depMesh && depMesh->IsSubdivisionDepMesh( ) ) {
			depMesh->SetDevelop2DDirty( true );
			depMesh->SetTextureDirty( true );
		}
	} else if ( ToMesh( RefEnt ) && ToMesh( RefEnt )->IsPolygonalMesh( ) ) {
		ToMesh( RefEnt )->SetDevelop2DDirty( true );
		ToMesh( RefEnt )->SetTextureDirty( true );
	}
}

//------------------------------------------------------------------------------

void TPBrepData::AddSeamEdge( IwPolyEdge *edge )
{
	if ( !edge ) return;
	if ( IsEdgeSeam( edge ) ) return;

	edge->SetUserInt1( edge->GetUserInt1( ) | MESH_EDGE_SEAM );
	if ( edge->GetSymmetricPolyEdge( ) ) edge->GetSymmetricPolyEdge( )->SetUserInt1( edge->GetSymmetricPolyEdge( )->GetUserInt1( ) | MESH_EDGE_SEAM );
	SeamEdges.Add( edge );
}

//------------------------------------------------------------------------------

void TPBrepData::AddSeamEdge( TOGLTransf *OGLTransf, int nedge )
{
	IwPolyEdge *edge;

	edge = GetPBrepEdge( OGLTransf, nedge );
	if ( !edge ) return;
	AddSeamEdge( edge );
}

//------------------------------------------------------------------------------

DefinesForErrors TPBrepData::AddSeamEdges( TOGLTransf *OGLTransf, TInteger_List *list )
{
	bool exist;
	int i;
	int num, *selectedList;
	DefinesForErrors err;
	vector<vector<int> > groups;
	IwPolyEdge *edge;
	IwTA<IwPolyEdge *> oneSeam, oneSeamOrdered;
	IwTA<IwTA<IwPolyEdge *> > iwEdgesOrdered;
	IwTA<IwTA<IwPolyEdge *> > seamedgesaux, seamedgesnews;
	IwTA<IwPolyFace *> faces;

	if ( !RefEnt || !ToMesh( RefEnt ) || !ToMesh( RefEnt )->IsPolygonalMesh( ) ) return DefinesForErrors::ERROR_GENERIC;

	err = DefinesForErrors::NON_ERROR;
	if ( list ) {
		num = list->Count( );
		for ( i = 0; i < num; i++ ) {
			edge = GetPBrepEdge( OGLTransf, *list->GetItem( i ) );
			if ( !edge ) continue;
			exist = IsEdgeSeam( edge );
			if ( exist ) continue;
			oneSeam.Add( edge );
			edge->SetUserInt1( edge->GetUserInt1( ) | MESH_EDGE_SEAM );
			if ( edge->GetSymmetricPolyEdge( ) ) edge->GetSymmetricPolyEdge( )->SetUserInt1( edge->GetSymmetricPolyEdge( )->GetUserInt1( ) | MESH_EDGE_SEAM );
		}
	} else {
		selectedList = GetEdges( OGLTransf, SelectedElementType::AllSelected, num );
		for ( i = 0; i < num; i++ ) {
			exist = IsEdgeSeam( OGLTransf, selectedList[ i ] );
			if ( exist ) continue;
			edge = GetPBrepEdge( OGLTransf, selectedList[ i ] );
			if ( !edge ) continue;
			oneSeam.Add( edge );
			edge->SetUserInt1( edge->GetUserInt1( ) | MESH_EDGE_SEAM );
			if ( edge->GetSymmetricPolyEdge( ) ) edge->GetSymmetricPolyEdge( )->SetUserInt1( edge->GetSymmetricPolyEdge( )->GetUserInt1( ) | MESH_EDGE_SEAM );
		}
		if ( selectedList ) delete[] selectedList;
	}
	if ( oneSeam.GetSize( ) ) SeamEdges.Append( oneSeam );

	UpdateOGLListSeamFromPBrep( OGLTransf );
	return err;
}

//------------------------------------------------------------------------------

DefinesForErrors TPBrepData::DeleteSeamEdges( TOGLTransf *OGLTransf, TInteger_List *list )
{
	int i, num, index1;
	DefinesForErrors err;

	if ( !list ) return DefinesForErrors::ERROR_GENERIC;
	if ( !RefEnt || !ToMesh( RefEnt ) || !ToMesh( RefEnt )->IsPolygonalMesh( ) ) return DefinesForErrors::ERROR_GENERIC;

	err = DefinesForErrors::NON_ERROR;
	num = list->Count( );
	for ( i = 0; i < num; i++ ) {
		if ( IsEdgeSeam( OGLTransf, *list->GetItem( i ), &index1 ) ) {
			SeamEdges[ index1 ]->SetUserInt1( SeamEdges[ index1 ]->GetUserInt1( ) & ~MESH_EDGE_SEAM );
			if ( SeamEdges[ index1 ]->GetSymmetricPolyEdge( ) ) SeamEdges[ index1 ]->GetSymmetricPolyEdge( )->SetUserInt1( SeamEdges[ index1 ]->GetSymmetricPolyEdge( )->GetUserInt1( ) & ~MESH_EDGE_SEAM );
			SeamEdges.RemoveAt( index1 );
		}
	}

	UpdateOGLListSeamFromPBrep( OGLTransf );
	return err;
}

//------------------------------------------------------------------------------

DefinesForErrors TPBrepData::DeleteSelectedSeamEdges( TOGLTransf *OGLTransf )
{
	int i, index1, num, *selectedList;
	DefinesForErrors err;

	if ( !RefEnt || !ToMesh( RefEnt ) || !ToMesh( RefEnt )->IsPolygonalMesh( ) ) return DefinesForErrors::ERROR_GENERIC;

	err = DefinesForErrors::NON_ERROR;
	selectedList = GetEdges( OGLTransf, SelectedElementType::AllSelected, num );
	for ( i = 0; i < num; i++ ) {
		if ( !IsEdgeSeam( OGLTransf, selectedList[ i ], &index1 ) ) continue;
		SeamEdges[ index1 ]->SetUserInt1( SeamEdges[ index1 ]->GetUserInt1( ) & ~MESH_EDGE_SEAM );
		if ( SeamEdges[ index1 ]->GetSymmetricPolyEdge( ) ) SeamEdges[ index1 ]->GetSymmetricPolyEdge( )->SetUserInt1( SeamEdges[ index1 ]->GetSymmetricPolyEdge( )->GetUserInt1( ) & ~MESH_EDGE_SEAM );
		SeamEdges.RemoveAt( index1 );
	}
	if ( selectedList ) delete[] selectedList;

	UpdateOGLListSeamFromPBrep( OGLTransf );
	return err;
}

//------------------------------------------------------------------------------

DefinesForErrors TPBrepData::DeleteAllSeamEdges( )
{
	int i, num;
	DefinesForErrors err;
	IwTA<IwPolyEdge *> edgesAux;

	err = DefinesForErrors::NON_ERROR;
	if ( (int) SeamEdges.GetSize( ) > 0 ) {
		// Recorremo las aristas de la PBrep porque si venimos de realizar un borrado de una cara, SeamEdges puede contener aristas borradas.
		PBrep->GetPolyEdges( edgesAux );
		num = (int) edgesAux.GetSize( );
		for ( i = 0; i < num; i++ )
			edgesAux[ i ]->SetUserInt1( edgesAux[ i ]->GetUserInt1( ) & ~MESH_EDGE_SEAM );

		SeamEdges.RemoveAll( );
	}

	return err;
}

//------------------------------------------------------------------------------

void TPBrepData::UpdateAllSeamEdgesFromPBrep( )
{
	int i, num;
	IwPolyEdge *edge;
	IwTA<IwPolyEdge *> edges;

	if ( !PBrep ) return;

	SeamEdges.RemoveAll( );
	// Recorremo las aristas de la PBrep para actualizar la lista SeamEdges.
	PBrep->GetPolyEdges( edges );
	num = (int) edges.GetSize( );
	for ( i = 0; i < num; i++ ) {
		edge = edges[ i ];
		if ( edge->GetUserIndex1( ) == ULONG_MAX ) continue;
		if ( edge->GetUserInt1( ) & MESH_EDGE_SEAM ) SeamEdges.Add( edge );
	}
}

//------------------------------------------------------------------------------

void TPBrepData::SelectSeams( TOGLTransf *OGLTransf )
{
	int i;

	if ( !RefEnt || !ToMesh( RefEnt ) || !ToMesh( RefEnt )->IsPolygonalMesh( ) ) return;

	for ( i = 0; i < (int) SeamEdges.GetSize( ); i++ )
		SelectEdge( OGLTransf, SeamEdges[ i ]->GetUserIndex1( ), SelectedElementType::Seam );
}

//------------------------------------------------------------------------------

void TPBrepData::UnSelectSeams( TOGLTransf *OGLTransf )
{
	int i;

	if ( !RefEnt || !ToMesh( RefEnt ) || !ToMesh( RefEnt )->IsPolygonalMesh( ) ) return;

	for ( i = 0; i < (int) SeamEdges.GetSize( ); i++ )
		UnSelectEdge( OGLTransf, SeamEdges[ i ]->GetUserIndex1( ) );
}

//------------------------------------------------------------------------------

// En esta funcion se supone que la lista esta ordenada
bool TPBrepData::IsClosedPath( IwTA<IwPolyEdge *> *path )
{
	if ( !path ) return false;
	return ( ( *path ).GetSize( ) > 2 && ( IsVertexFromEdge( ( *path )[ 0 ]->GetStartVertex( ), ( *path )[ ( *path ).GetSize( ) - 1 ] ) || IsVertexFromEdge( ( *path )[ 0 ]->GetEndVertex( ), ( *path )[ ( *path ).GetSize( ) - 1 ] ) ) );
}

//------------------------------------------------------------------------------

// En esta funcion se supone que la lista esta ordenada
bool TPBrepData::IsClosedPath( IwTA<IwPolyFace *> *path )
{
	IwTA<IwPolyEdge *> edges;

	if ( !path ) return false;

	if ( ( *path ).GetSize( ) > 2 ) {
		edges = GetCommonEdgesBetweenFaces( ( *path )[ 0 ], ( *path )[ ( *path ).GetSize( ) - 1 ] );
		return edges.GetSize( );
	}

	return false;
}

//------------------------------------------------------------------------------

bool TPBrepData::IsAnySeamInsideOfGroupOfFaces( vector<int> *group, IwTA<IwPolyEdge *> *insideSeams )
{
	bool ret;
	int i;
	IwTA<IwPolyFace *> faces, facesConnected, facesFounded;
	IwPolyFace *face;

	if ( !group ) return false;

	ret = false;
	if ( insideSeams ) ( *insideSeams ).RemoveAll( );

	for ( i = 0; i < (int) ( *group ).size( ); i++ ) {
		face = PBrepFaces[ ( *group )[ i ] ];
		faces.Add( face );
	}

	for ( i = 0; i < (int) SeamEdges.GetSize( ); i++ ) {
		//		if ( !forceClosed && IsClosedPath( &SeamEdges[ i ] ) ) continue; // Cuando el grupo de caras que se pasa es un solido cerrado en 2 direcciones (ej: tuberia) el camino cerrado tiene que tratarse
		facesConnected = GetConnectedFacesFromEdge( SeamEdges[ i ] );
		if ( !facesConnected.GetSize( ) ) continue;
		faces.FindCommonElements( facesConnected, facesFounded );
		if ( facesFounded.GetSize( ) == facesConnected.GetSize( ) ) { // Si no todas las caras estan en el grupo es pq esa arista esta en un borde del grupo
			if ( insideSeams ) ( *insideSeams ).Add( SeamEdges[ i ] );
			ret = true;
		}
	}

	return ret;
}

//------------------------------------------------------------------------------

// Obtenemos las caras que tiene el vertice y a partir de las costuras se van agrupando
// Si el vertice es el final de una costura, se devuelve false
bool TPBrepData::GetFacesGroupedByVertexSeam( IwPolyVertex *vertex, IwTA<IwTA<IwPolyFace *> > *faces )
{
	int i, j;
	IwPolyEdge *edge;
	IwTA<IwPolyEdge *> edges, seams;
	IwPolyFace *face, *faceaux;
	IwTA<IwPolyFace *> facesadjacents, facesfromvertex, groupfaces, facestotest;

	if ( !vertex || !faces ) return false;

	( *faces ).RemoveAll( );
	vertex->GetPolyEdges( edges );
	for ( i = 0; i < (int) edges.GetSize( ); i++ ) {
		edge = edges[ i ];
		if ( edge->GetUserIndex1( ) == ULONG_MAX ) continue;
		if ( edge->GetUserInt1( ) & MESH_EDGE_SEAM ) seams.Add( edge );
	}
	if ( seams.GetSize( ) <= 1 ) return false;

	InitUserIndex1( false, true );

	vertex->GetPolyFaces( facesfromvertex );
	while ( facesfromvertex.GetSize( ) ) {
		face = facesfromvertex[ 0 ];
		facesfromvertex.RemoveAt( 0 );
		if ( face->GetUserIndex1( ) > 0 ) continue;
		face->SetUserIndex1( 1 );
		groupfaces.Add( face );
		facestotest = GetAdjacentFacesFromVertexFace( face, vertex );
		while ( facestotest.GetSize( ) ) {
			faceaux = facestotest[ 0 ];
			facestotest.RemoveAt( 0 );
			if ( !faceaux ) continue;
			if ( faceaux->GetUserIndex1( ) > 0 ) continue;
			edges = GetCommonEdgesBetweenFaces( face, faceaux );
			for ( j = 0; j < (int) edges.GetSize( ); j++ ) {
				edge = edges[ j ];
				if ( ( edge->GetStartVertex( ) == vertex || edge->GetEndVertex( ) == vertex ) ) {
					if ( !( edge->GetUserInt1( ) & MESH_EDGE_SEAM ) ) {
						groupfaces.Add( faceaux );
						faceaux->SetUserIndex1( 1 );
						facesadjacents = GetAdjacentFacesFromVertexFace( faceaux, vertex );
						facestotest.Append( facesadjacents );
					}
					break;
				}
			}
		}
		( *faces ).Add( groupfaces );
		groupfaces.RemoveAll( );
	}

	InitUserIndex1( false, true );

	return true;
}

//------------------------------------------------------------------------------

bool TPBrepData::IsVertexSeam( IwPolyVertex *vertex )
{
	int i;
	IwPolyEdge *edge;
	IwTA<IwPolyEdge *> edges;

	if ( !vertex ) return false;

	vertex->GetPolyEdges( edges );
	for ( i = 0; i < (int) edges.GetSize( ); i++ ) {
		edge = edges[ i ];
		if ( edge->GetUserIndex1( ) == ULONG_MAX ) continue;
		if ( edge->GetUserInt1( ) & MESH_EDGE_SEAM ) return true;
	}
	return false;
}

//------------------------------------------------------------------------------

bool TPBrepData::IsVertexSeamExtrem( IwPolyVertex *vertex, int *num )
{
	int i, numedges;
	IwPolyEdge *edge;
	IwTA<IwPolyEdge *> edges;

	if ( !vertex ) return false;

	numedges = 0;
	vertex->GetPolyEdges( edges );
	for ( i = 0; i < (int) edges.GetSize( ); i++ ) {
		edge = edges[ i ];
		if ( edge->GetUserIndex1( ) == ULONG_MAX ) continue;
		if ( edge->GetUserInt1( ) & MESH_EDGE_SEAM ) numedges++;
	}
	if ( num ) ( *num ) = numedges;
	return ( numedges == 1 );
}

//------------------------------------------------------------------------------

// =============================================================================
// TPBrepData - Pliegues
// =============================================================================

//------------------------------------------------------------------------------

bool TPBrepData::IsEdgeCrease( TOGLTransf *OGLTransf, int ind, bool sharp, int level )
{
	if ( !GetPBrep( OGLTransf ) ) return false;

	if ( ind < 0 || ind >= (int) PBrepEdges.GetSize( ) ) return false;

	if ( !PBrepEdges[ ind ] ) return false;
	if ( sharp ) return floor( PBrepEdges[ ind ]->GetUserFloat1( ) * level + 0.5 ) >= level; // return PBrepEdges[ ind ]->GetUserFloat1( ) == 1.0;

	return PBrepEdges[ ind ]->GetUserFloat1( ) > 0;
}

//------------------------------------------------------------------------------

bool TPBrepData::IsEdgeCrease( IwPolyEdge *edge )
{
	return edge && edge->GetUserFloat1( ) > 0;
}

//------------------------------------------------------------------------------

void TPBrepData::AddCreaseEdges( TOGLTransf *OGLTransf, IwPolyEdge *edgecrease, float percent, bool updateDataSubdivision, bool updateOGLList, SelectedElementType selType, bool checkIsSubd )
{
	int i;
	int num, *selectedList;
	IwPolyEdge *edge;

	IwTA<IwPolyFace *> faces;

	if ( percent < 0 || percent > 1 || !RefEnt || ( checkIsSubd && ( !ToMesh( RefEnt ) || !ToMesh( RefEnt )->IsPolygonalMesh( ) ) ) ) return;

	if ( edgecrease ) {
		edgecrease->SetUserFloat1( percent );
		edge = edgecrease->GetSymmetricPolyEdge( );
		if ( edge ) edge->SetUserFloat1( percent );
	} else {
		selectedList = GetEdges( OGLTransf, selType, num );

		for ( i = 0; i < num; i++ ) {
			edge = GetPBrepEdge( OGLTransf, selectedList[ i ] );
			if ( edge ) {
				edge->SetUserFloat1( percent );
				edge = edge->GetSymmetricPolyEdge( );
				if ( edge ) edge->SetUserFloat1( percent );
			}
		}

		if ( selectedList ) delete[] selectedList;
	}

	if ( updateDataSubdivision ) UpdateDataSubdivision( OGLTransf );
	if ( updateOGLList ) UpdateOGLListCreasesFromPBrep( OGLTransf );
}

//------------------------------------------------------------------------------

void TPBrepData::RemoveCreaseEdges( TOGLTransf *OGLTransf, bool updateDataSubdivision, bool updateOGLList, bool force )
{
	int i, count;
	int num, *selectedList;
	IwPolyEdge *edge;
	IwTA<IwPolyFace *> faces;

	if ( !RefEnt || !ToMesh( RefEnt ) || !ToMesh( RefEnt )->IsPolygonalMesh( ) ) return;

	selectedList = GetEdges( OGLTransf, SelectedElementType::AllSelected, num, force );

	if ( num > 0 ) {
		for ( i = 0; i < num; i++ ) {
			edge = GetPBrepEdge( OGLTransf, selectedList[ i ] );
			if ( edge ) {
				edge->SetUserFloat1( 0.0 );
				edge = edge->GetSymmetricPolyEdge( );
				if ( edge ) edge->SetUserFloat1( 0.0 );
			}
		}
	} else {
		count = CountPBrepEdges( OGLTransf );
		for ( i = 0; i < count; i++ ) {
			edge = GetPBrepEdge( OGLTransf, i );
			if ( edge ) {
				edge->SetUserFloat1( 0 );
				edge = edge->GetSymmetricPolyEdge( );
				if ( edge ) edge->SetUserFloat1( 0.0 );
			}
		}
	}
	if ( selectedList ) delete[] selectedList;

	if ( updateDataSubdivision ) UpdateDataSubdivision( OGLTransf );
	if ( updateOGLList ) UpdateOGLListCreasesFromPBrep( OGLTransf );
}

//------------------------------------------------------------------------------

void TPBrepData::GetCreaseEdges( TOGLTransf *OGLTransf, IwTA<IwPolyEdge *> *creaseEdges, bool onlysharp )
{
	bool addedge;
	int i, numedges, value;
	IwPolyEdge *edge;
	TSubdivisionData *subdivisiondata;

	if ( !creaseEdges ) return;
	if ( !ToMesh( RefEnt ) || !ToMesh( RefEnt )->IsPolygonalMesh( ) ) return;

	( *creaseEdges ).RemoveAll( );

	subdivisiondata = 0;
	if ( ToMesh( RefEnt )->HasSubdivisionDepMesh( ) ) subdivisiondata = ToDepMesh( ToMesh( RefEnt )->GetDepMeshes( )->GetShape( 0 ) )->GetSubdivisionData( );

	numedges = CountPBrepEdges( OGLTransf );
	for ( i = 0; i < numedges; i++ ) {
		edge = GetPBrepEdge( OGLTransf, i );
		if ( edge && edge->GetUserFloat1( ) > RES_GEOM ) {
			addedge = true;
			if ( onlysharp ) {
				if ( subdivisiondata ) {
					value = floor( edge->GetUserFloat1( ) * subdivisiondata->Level + 0.5 );
					if ( value < subdivisiondata->Level ) addedge = false;
				} else
					value = edge->GetUserFloat1( );
			}
			if ( addedge ) ( *creaseEdges ).Add( edge );
		}
	}
}

//------------------------------------------------------------------------------

void TPBrepData::GetCreaseAndSeamEdgesFromVertex( IwPoint3d iwPoint3d /*IwPolyVertex *vertex*/, IwTA<IwPolyEdge *> *creaseAndSeamEdgesFromVertex, IwTA<IwPolyEdge *> &creaseEdges, IwTA<IwPolyEdge *> &seamEdges )
{
	int i = 0;

	// if ( !vertex ) return;

	( *creaseAndSeamEdgesFromVertex ).RemoveAll( );

	while ( i < (int) creaseEdges.GetSize( ) ) {
		if ( creaseEdges[ i ]->GetStartVertex( )->GetPoint( ) == iwPoint3d /*vertex->GetPoint( )*/ || creaseEdges[ i ]->GetEndVertex( )->GetPoint( ) == iwPoint3d /*vertex->GetPoint( )*/ ) {
			( *creaseAndSeamEdgesFromVertex ).Add( creaseEdges[ i ] );
			creaseEdges.RemoveAt( i );
		} else {
			i++;
		}
	}

	while ( i < (int) seamEdges.GetSize( ) ) {
		if ( seamEdges.GetAt( i )->GetStartVertex( )->GetPoint( ) == iwPoint3d /*vertex->GetPoint( )*/ || seamEdges.GetAt( i )->GetEndVertex( )->GetPoint( ) == iwPoint3d /*vertex->GetPoint( )*/ ) {
			( *creaseAndSeamEdgesFromVertex ).Add( seamEdges.GetAt( i ) );
			seamEdges.RemoveAt( i );
		} else {
			i++;
		}
	}
}

//------------------------------------------------------------------------------

float TPBrepData::GetCreaseAverage( TOGLTransf *OGLTransf )
{
	int i, num, *selectedList;
	float average;
	IwPolyEdge *edge;

	average = 0;
	selectedList = GetEdges( OGLTransf, SelectedElementType::AllSelected, num );
	for ( i = 0; i < num; i++ ) {
		edge = GetPBrepEdge( OGLTransf, selectedList[ i ] );
		average += edge->GetUserFloat1( );
	}

	if ( selectedList ) delete[] selectedList;

	return num > 0 ? average / num : 0;
}

//------------------------------------------------------------------------------

bool TPBrepData::ObtainListOfCreaseSharp( TOGLTransf *OGLTransf, IwTA<IwTA<IwPolyEdge *> > *crease ) // Las aristas de pliegues agudos son las que tienen el nivel de crease a 1
{
	int i, j;
	IwTA<IwPolyEdge *> allcrease, onelist;
	vector<vector<int> > groups;

	if ( !crease ) return false;

	crease->RemoveAll( );

	GetCreaseEdges( OGLTransf, &allcrease, true );
	if ( !GetDisjointGroupEdges( OGLTransf, &groups, false, false, &allcrease ) ) return false;
	for ( i = 0; i < (int) groups.size( ); i++ ) {
		for ( j = 0; j < (int) groups[ i ].size( ); j++ )
			onelist.Add( GetPBrepEdge( OGLTransf, groups[ i ][ j ] ) );
		crease->Add( onelist );
		onelist.RemoveAll( );
	}

	return crease->GetSize( );
}

//------------------------------------------------------------------------------

void TPBrepData::GetGroupsOfFacesFromCreaseSharps( TOGLTransf *OGLTransf, IwTA<IwTA<IwPolyEdge *> > *creaselist, IwTA<IwTA<IwPolyFace *> > *faces1, IwTA<IwTA<IwPolyFace *> > *faces2 )
{
	int i;
	IwTA<IwPolyFace *> faces1Aux, faces2Aux;

	if ( !creaselist || !faces1 || !faces2 ) return;

	creaselist->RemoveAll( );
	faces1->RemoveAll( );
	faces2->RemoveAll( );

	ObtainListOfCreaseSharp( OGLTransf, creaselist );
	for ( i = 0; i < (int) creaselist->GetSize( ); i++ ) {
		GetFacesBothSideOfCreaseSharp( &( *creaselist )[ i ], &faces1Aux, &faces2Aux ); // Aunque devuelva false, se anyaden los grupos de caras pq las listas de crease y caras han de tener la misma longitud
		faces1->Add( faces1Aux );
		faces2->Add( faces2Aux );
	}
}

//------------------------------------------------------------------------------

bool TPBrepData::GetFacesBothSideOfCreaseSharp( IwTA<IwPolyEdge *> *crease, IwTA<IwPolyFace *> *faces1, IwTA<IwPolyFace *> *faces2 )
{
	bool founded1, founded2, added;
	int i, j, k, m;
	ULONG index;
	IwPolyEdge *edgeAux;
	IwTA<IwPolyFace *> facesAdyacents;
	IwTA<IwPolyFace *> facesAdyacentsForbidden;
	IwTA<IwPolyEdge *> commonEdges;

	if ( !crease || !faces1 || !faces2 ) return false;

	( *faces1 ).RemoveAll( );
	( *faces2 ).RemoveAll( );
	for ( i = 0; i < (int) ( *crease ).GetSize( ); i++ ) {
		facesAdyacents = GetConnectedFacesFromEdge( ( *crease )[ i ] );
		// Si son mas de dos no lo tratamos
		if ( !facesAdyacents.GetSize( ) || facesAdyacents.GetSize( ) > 2 ) return false;
		if ( ( *faces1 ).GetSize( ) == 0 ) {
			( *faces1 ).Add( facesAdyacents[ 0 ] );
			if ( facesAdyacents.GetSize( ) > 1 ) ( *faces2 ).Add( facesAdyacents[ 1 ] );
		} else {
			for ( m = 0; m < (int) facesAdyacents.GetSize( ); m++ ) {
				if ( faces1->FindElement( facesAdyacents[ m ], index ) || faces2->FindElement( facesAdyacents[ m ], index ) ) continue;
				founded1 = false;
				founded2 = false;
				for ( j = 0; j < (int) ( *faces1 ).GetSize( ); j++ ) {
					commonEdges = GetCommonEdgesBetweenFaces( facesAdyacents[ m ], ( *faces1 )[ j ] );
					if ( !commonEdges.GetSize( ) ) continue;
					for ( k = 0; k < (int) commonEdges.GetSize( ); k++ )
						if ( !FindElement_Edge( crease, commonEdges[ k ], index, edgeAux ) ) {
							founded1 = true;
							break;
						}
				}
				if ( founded1 ) ( *faces1 ).Add( facesAdyacents[ m ] );

				if ( !founded1 ) {
					for ( j = 0; j < (int) ( *faces2 ).GetSize( ); j++ ) {
						commonEdges = GetCommonEdgesBetweenFaces( facesAdyacents[ m ], ( *faces2 )[ j ] );
						if ( !commonEdges.GetSize( ) ) continue;
						for ( k = 0; k < (int) commonEdges.GetSize( ); k++ )
							if ( !FindElement_Edge( crease, commonEdges[ k ], index, edgeAux ) ) {
								founded2 = true;
								break;
							}
					}
					if ( founded2 ) ( *faces2 ).Add( facesAdyacents[ m ] );
				}
				// Si no se ha encontrado adyacencia en ningun lado es pq no estan seguidos, reservamos para luego
				if ( !founded1 && !founded2 ) {
					if ( ( *faces2 ).GetSize( ) == 0 ) ( *faces2 ).Add( facesAdyacents[ m ] );
					else
						facesAdyacentsForbidden.AddUnique( facesAdyacents[ m ] );
				}
			}
		}
	}

	if ( facesAdyacentsForbidden.GetSize( ) ) {
		do {
			for ( i = facesAdyacentsForbidden.GetSize( ) - 1; i >= 0; i-- ) {
				added = founded1 = founded2 = false;
				for ( j = 0; j < (int) ( *faces1 ).GetSize( ); j++ ) {
					commonEdges = GetCommonEdgesBetweenFaces( facesAdyacentsForbidden[ i ], ( *faces1 )[ j ] );
					if ( !commonEdges.GetSize( ) ) continue;
					for ( k = 0; k < (int) commonEdges.GetSize( ); k++ )
						if ( !FindElement_Edge( crease, commonEdges[ k ], index, edgeAux ) ) {
							added = true;
							break;
						} else
							founded1 = true;
				}
				if ( added ) {
					( *faces1 ).Add( facesAdyacentsForbidden[ i ] );
					facesAdyacentsForbidden.RemoveAt( i );
					continue;
				}
				for ( j = 0; j < (int) ( *faces2 ).GetSize( ); j++ ) {
					commonEdges = GetCommonEdgesBetweenFaces( facesAdyacentsForbidden[ i ], ( *faces2 )[ j ] );
					if ( !commonEdges.GetSize( ) ) continue;
					for ( k = 0; k < (int) commonEdges.GetSize( ); k++ )
						if ( !FindElement_Edge( crease, commonEdges[ k ], index, edgeAux ) ) {
							added = true;
							break;
						} else
							founded2 = true;
				}
				if ( added ) {
					( *faces2 ).Add( facesAdyacentsForbidden[ i ] );
					facesAdyacentsForbidden.RemoveAt( i );
					continue;
				} else {
					// Si tiene conexión con alguna cara de sólo una de las listas a través de una de las aristas marcadas, lo incluimos en la lista opuesta.
					if ( founded1 && !founded2 ) {
						( *faces2 ).Add( facesAdyacentsForbidden[ i ] );
						facesAdyacentsForbidden.RemoveAt( i );
						added = true;
						continue;
					} else if ( !founded1 && founded2 ) {
						( *faces1 ).Add( facesAdyacentsForbidden[ i ] );
						facesAdyacentsForbidden.RemoveAt( i );
						added = true;
						continue;
					}
				}
			}
		} while ( facesAdyacentsForbidden.GetSize( ) && added );
	}

	return !facesAdyacentsForbidden.GetSize( ) && ( *faces1 ).GetSize( );
}

//------------------------------------------------------------------------------

int TPBrepData::SaveCreaseEdgeInfo( IwPolyEdge *edge, IwTA<int> *longuser2, IwTA<float> *values, bool force, int userLong2 )
{
	int userLong2Aux;

	userLong2Aux = -1;

	if ( !edge || !longuser2 || !values ) return userLong2Aux;
	if ( edge->GetUserLong2( ) > 0 ) return edge->GetUserLong2( );

	if ( force || edge->GetUserFloat1( ) > 0 ) {
		values->Add( edge->GetUserFloat1( ) );
		if ( !userLong2 ) {
			longuser2->GetSize( ) ? longuser2->Add( ( *longuser2 )[ longuser2->GetSize( ) - 1 ] + 1 ) : longuser2->Add( 1 );
			userLong2Aux = ( *longuser2 )[ longuser2->GetSize( ) - 1 ];
		} else {
			longuser2->Add( userLong2 );
			userLong2Aux = userLong2;
		}
		edge->SetUserLong2( userLong2Aux );
	}

	return userLong2Aux;
}

//------------------------------------------------------------------------------

void TPBrepData::RestoreCreaseEdgeInfo( TAddedElements *addedElements, IwTA<int> *userlongs2, IwTA<float> *values )
{
	int i, nAddedEdges;
	ULONG index;

	if ( !addedElements || !userlongs2 || !values ) return;
	if ( userlongs2->GetSize( ) != values->GetSize( ) ) return;

	nAddedEdges = addedElements->iwEdges.GetSize( );
	for ( i = 0; i < nAddedEdges; i++ ) {
		if ( addedElements->iwEdges[ i ]->GetUserLong2( ) == 0 ) continue;
		if ( userlongs2->FindElement( addedElements->iwEdges[ i ]->GetUserLong2( ), index ) ) {
			addedElements->iwEdges[ i ]->SetUserFloat1( ( *values )[ index ] );
			addedElements->iwEdges[ i ]->SetUserLong2( 0 );
			if ( addedElements->iwEdges[ i ]->GetSymmetricPolyEdge( ) ) {
				addedElements->iwEdges[ i ]->GetSymmetricPolyEdge( )->SetUserFloat1( ( *values )[ index ] );
				addedElements->iwEdges[ i ]->GetSymmetricPolyEdge( )->SetUserLong2( 0 );
			}
		}
	}

	nAddedEdges = addedElements->iwNewEdges.GetSize( );
	for ( i = 0; i < nAddedEdges; i++ ) {
		if ( addedElements->iwNewEdges[ i ]->GetUserLong2( ) == 0 ) continue;
		if ( userlongs2->FindElement( addedElements->iwNewEdges[ i ]->GetUserLong2( ), index ) ) {
			addedElements->iwNewEdges[ i ]->SetUserFloat1( ( *values )[ index ] );
			addedElements->iwNewEdges[ i ]->SetUserLong2( 0 );
			if ( addedElements->iwNewEdges[ i ]->GetSymmetricPolyEdge( ) ) {
				addedElements->iwNewEdges[ i ]->GetSymmetricPolyEdge( )->SetUserFloat1( ( *values )[ index ] );
				addedElements->iwNewEdges[ i ]->GetSymmetricPolyEdge( )->SetUserLong2( 0 );
			}
		}
	}
}

//------------------------------------------------------------------------------
// Se añade a las listas de ariastas afectadas aquellas cuyo userIndex2 sea distinto de cero y pertenecientes a las caras compartidas por el iwVertex
void TPBrepData::AddCreaseEdgesAffectedFromVertex( IwPolyVertex *iwVertex, IwTA<ULONG> *iwIndexes, IwTA<IwPolyVertex *> *iwStartVertexs, IwTA<IwPolyVertex *> *iwEndVertexs )
{
	int i, nFaces;
	IwTA<IwPolyFace *> iwFacesVertex;

	if ( !iwVertex || !iwIndexes || !iwStartVertexs || !iwEndVertexs ) return;

	iwVertex->GetPolyFaces( iwFacesVertex );
	nFaces = (int) iwFacesVertex.GetSize( );
	for ( i = 0; i < nFaces; i++ )
		AddCreaseEdgesAffectedFromFace( iwFacesVertex.GetAt( i ), iwIndexes, iwStartVertexs, iwEndVertexs );
}

//------------------------------------------------------------------------------

// Se actualizan los userIndex2 y los userlong2 de las aristas añadidas
void TPBrepData::UpdateCreaseEdgesAffected( TAddedElements *addedElements, IwTA<ULONG> *iwIndexes, IwTA<IwPolyVertex *> *iwStartVertexs, IwTA<IwPolyVertex *> *iwEndVertexs )
{
	ULONG pos;
	int i, j, k, nAddedEdges, nAffectedEdges, nAddedVertexs;
	IwPolyVertex *iwAddedVertex; //, *nextVertex;
	IwPolyEdge *iwAddedEdge, *iwEdge1, *iwEdge2;
	IwTA<int> iwReplacedEdges;

	if ( !addedElements || !iwIndexes || !iwStartVertexs || !iwEndVertexs ) return;

	nAffectedEdges = (int) iwIndexes->GetSize( );
	if ( nAffectedEdges == 0 ) return;

	iwReplacedEdges.RemoveAll( );
	// Buscamos las aristas que han sido sustituiadas al borrar una cara y crear otra.
	nAddedEdges = addedElements->iwEdges.GetSize( );
	for ( i = 0; i < nAddedEdges; i++ ) {
		for ( j = 0; j < nAffectedEdges; j++ ) {
			if ( addedElements->iwEdges.GetAt( i )->GetStartVertex( ) == iwStartVertexs->GetAt( j ) && addedElements->iwEdges.GetAt( i )->GetEndVertex( ) == iwEndVertexs->GetAt( j ) ) {
				addedElements->iwEdges.GetAt( i )->SetUserLong2( iwIndexes->GetAt( j ) );
				iwReplacedEdges.AddUnique( iwIndexes->GetAt( j ) );
				break;
			}
		}
	}

	nAddedVertexs = addedElements->iwVertexs.GetSize( );
	if ( nAddedVertexs > 0 ) {
		for ( i = 0; i < nAffectedEdges; i++ ) {
			if ( iwReplacedEdges.FindElement( iwIndexes->GetAt( i ), pos ) ) continue;
			for ( j = 0; j < nAddedVertexs; j++ ) {
				iwEdge1 = iwEdge2 = 0;
				iwAddedVertex = addedElements->iwVertexs.GetAt( j );
				for ( k = 0; k < nAddedEdges; k++ ) {
					iwAddedEdge = addedElements->iwEdges.GetAt( k );
					if ( iwAddedEdge->GetUserLong2( ) > 0 ) continue;
					if ( iwAddedEdge->GetStartVertex( ) == iwStartVertexs->GetAt( i ) && iwAddedEdge->GetEndVertex( ) == iwAddedVertex ) iwEdge1 = iwAddedEdge;
					if ( iwAddedEdge->GetStartVertex( ) == iwAddedVertex && iwAddedEdge->GetEndVertex( ) == iwEndVertexs->GetAt( i ) ) iwEdge2 = iwAddedEdge;
					if ( iwEdge1 && iwEdge2 ) {
						iwEdge1->SetUserLong2( iwIndexes->GetAt( i ) );
						iwEdge2->SetUserLong2( iwIndexes->GetAt( i ) );
						break;
					}
				}
			}
		}
	}

	/*
	Raul. Para nueva funcionalidad de MD_SUBDIVISIONS

	//recorrer las aristas nuevas iwNewEdges. Tomando el vértice inicial que sea el mismo que la arista seleccionada
	//hasta el vertice final de la arista seleccionada
	//y a cada vértice encontrado asignarle el userlong de la arista original
	nAddedEdges = addedElements->iwNewEdges.GetSize( ); //añadidos
	nAffectedEdges = (int) iwIndexes->GetSize( );   //cuantos vertices han sido afectados por el cambio
	//iwStartVertex -> vertices originales ?¿?¿

	iwReplacedEdges.RemoveAll( );
	for( i = 0; i < nAffectedEdges; i++ ) {
		for( j = 0; j < nAddedEdges; j++ ) {
			if ( addedElements->iwNewEdges[ j ]->GetUserLong2( ) == 0 && addedElements->iwNewEdges[ j ]->GetStartVertex( ) == iwStartVertexs->GetAt( i ) ) {

				addedElements->iwNewEdges.GetAt( j )->SetUserLong2( iwIndexes->GetAt( i ) );
				iwReplacedEdges.AddUnique( iwIndexes->GetAt( i ) );
				nextVertex = addedElements->iwNewEdges[ j ]->GetEndVertex( );

				while ( nextVertex != iwEndVertexs->GetAt( i ) ) {
					for( k = 0; k < nAddedEdges; k++ ) {
						if ( addedElements->iwNewEdges[ k ]->GetUserLong2( ) == 0 && addedElements->iwNewEdges[ k ]->GetStartVertex( ) == nextVertex ) {
							addedElements->iwNewEdges.GetAt( k )->SetUserLong2( iwIndexes->GetAt( i ) );
							iwReplacedEdges.AddUnique( iwIndexes->GetAt( i ) );
							nextVertex = addedElements->iwNewEdges[ k ]->GetEndVertex( );
							break;
						}
					}
				}
			}
		}
	}
	*/
}

//------------------------------------------------------------------------------

// Se añade a las listas de ariastas afectadas aquellas cuyo userIndex2 sea distinto de cero y pertenecientes a las caras iwFace
void TPBrepData::AddCreaseEdgesAffectedFromFace( IwPolyFace *iwFace, IwTA<ULONG> *iwIndexes, IwTA<IwPolyVertex *> *iwStartVertexs, IwTA<IwPolyVertex *> *iwEndVertexs )
{
	int i, nEdges;
	ULONG userLong2;
	IwTA<IwPolyEdge *> iwEdgesFace;

	if ( !iwFace || !iwIndexes || !iwStartVertexs || !iwEndVertexs ) return;

	iwFace->GetPolyEdges( iwEdgesFace );
	nEdges = (int) iwEdgesFace.GetSize( );
	for ( i = 0; i < nEdges; i++ ) {
		userLong2 = iwEdgesFace.GetAt( i )->GetUserLong2( );
		if ( userLong2 > 0 ) {
			iwIndexes->Add( userLong2 );
			iwStartVertexs->Add( iwEdgesFace.GetAt( i )->GetStartVertex( ) );
			iwEndVertexs->Add( iwEdgesFace.GetAt( i )->GetEndVertex( ) );
		}
	}
}

//------------------------------------------------------------------------------

// Se actualizan los userlong2 de las aristas añadidas
void TPBrepData::UpdateCreaseEdgesAffectedFromDisolve( TAddedElements *addedElements, IwTA<ULONG> *iwIndexes, IwTA<IwPolyVertex *> *iwStartVertexs, IwTA<IwPolyVertex *> *iwEndVertexs, IwTA<int> *newindexes, IwTA<float> *values )
{
	ULONG pos;
	int i, j, k, nAffectedEdges, nAddedEdges, cont;
	float value;
	IwPolyVertex *vertex, *vertex1, *vertex2;

	nAffectedEdges = (int) iwIndexes->GetSize( );
	if ( nAffectedEdges == 0 ) return;

	// Buscamos en la lista de vertices aquellos que se han disuelto.
	for ( i = 0; i < (int) addedElements->iwVertexs.GetSize( ); i++ ) {
		value = 0;
		cont = 0;
		vertex1 = 0;
		vertex2 = 0;
		vertex = addedElements->iwVertexs[ i ];
		// Buscamos en la lista este vertice
		for ( j = 0; j < nAffectedEdges; j++ ) {
			if ( iwStartVertexs->GetAt( j ) == vertex || iwEndVertexs->GetAt( j ) == vertex ) {
				if ( newindexes->FindElement( (int) iwIndexes->GetAt( j ), pos ) ) {
					value += values->GetAt( pos );
					cont++;
					if ( iwStartVertexs->GetAt( j ) == vertex ) {
						if ( !vertex1 ) vertex1 = iwEndVertexs->GetAt( j );
						else if ( !vertex2 )
							vertex2 = iwEndVertexs->GetAt( j );
					} else {
						if ( !vertex1 ) vertex1 = iwStartVertexs->GetAt( j );
						else if ( !vertex2 )
							vertex2 = iwStartVertexs->GetAt( j );
					}
				}
			}
		}

		if ( vertex1 && vertex2 ) {
			// Buscamos las aristas que han sido sustituidas al disolver un vertice
			nAddedEdges = addedElements->iwEdges.GetSize( );
			for ( k = 0; k < nAddedEdges; k++ ) {
				for ( j = 0; j <= nAffectedEdges - 2; j += 2 ) {
					if ( ( addedElements->iwEdges.GetAt( k )->GetStartVertex( ) == vertex1 && addedElements->iwEdges.GetAt( k )->GetEndVertex( ) == vertex2 ) || ( addedElements->iwEdges.GetAt( k )->GetStartVertex( ) == vertex2 && addedElements->iwEdges.GetAt( k )->GetEndVertex( ) == vertex1 ) ) {
						addedElements->iwEdges.GetAt( k )->SetUserLong2( 0 ); // Para que ya no la busque mas
																			  //						addedElements->iwEdges.GetAt( k )->SetUserLong2( iwIndexes->GetAt( j ) );
						addedElements->iwEdges.GetAt( k )->SetUserFloat1( value / cont );
						if ( addedElements->iwEdges.GetAt( k )->GetSymmetricPolyEdge( ) ) {
							addedElements->iwEdges.GetAt( k )->GetSymmetricPolyEdge( )->SetUserLong2( 0 ); // Para que ya no la busque mas
							addedElements->iwEdges.GetAt( k )->GetSymmetricPolyEdge( )->SetUserFloat1( value / cont );
						}
						break;
					}
				}
			}
		}
	}
}

//------------------------------------------------------------------------------
// Se añade a las listas de ariastas afectadas aquellas cuyo userLong2 sea distinto de cero y pertenecientes a las aristas compartidas por el iwVertex
void TPBrepData::AddCreaseEdgesAffectedFromVertexDisolve( IwPolyVertex *iwVertex, IwTA<ULONG> *iwIndexes, IwTA<IwPolyVertex *> *iwStartVertexs, IwTA<IwPolyVertex *> *iwEndVertexs )
{
	int i, nEdges;
	ULONG userLong2;
	IwTA<IwPolyEdge *> edges;

	if ( !iwVertex || !iwIndexes || !iwStartVertexs || !iwEndVertexs ) return;

	iwVertex->GetPolyEdges( edges );
	//	iwVertex->GetStartingPolyEdges( edges );
	nEdges = (int) edges.GetSize( );
	for ( i = 0; i < nEdges; i++ ) {
		userLong2 = edges.GetAt( i )->GetUserLong2( );
		if ( userLong2 > 0 ) {
			iwIndexes->Add( userLong2 );
			iwStartVertexs->Add( edges.GetAt( i )->GetStartVertex( ) );
			iwEndVertexs->Add( edges.GetAt( i )->GetEndVertex( ) );
		}
	}
}

//------------------------------------------------------------------------------

void TPBrepData::MarkCreaseNewFace( IwPolyFace *iwFace, IwPolyVertex *iwVertex1, IwPolyVertex *iwVertex2, float value )
{
	int i;
	IwPolyEdge *iwEdge;
	IwTA<IwPolyEdge *> iwEdges;

	if ( !iwFace || !iwVertex1 || !iwVertex2 ) return;
	if ( value < 0.0 || value > 1.0 ) return;

	iwFace->GetPolyEdges( iwEdges );
	for ( i = 0; i < (int) iwEdges.GetSize( ); i++ ) {
		iwEdge = iwEdges.GetAt( i );
		if ( ( iwEdge->GetStartVertex( ) == iwVertex1 && iwEdge->GetEndVertex( ) == iwVertex2 ) || ( iwEdge->GetStartVertex( ) == iwVertex2 && iwEdge->GetEndVertex( ) == iwVertex1 ) ) {
			iwEdge->SetUserFloat1( value );
			iwEdge = iwEdge->GetSymmetricPolyEdge( );
			if ( iwEdge ) iwEdge->SetUserFloat1( value );
		}
	}
}

//-----------------------------------------------------------------------------

void TPBrepData::SaveCreaseAndSeamsValuesFromCollapseVertexs( IwTA<IwPolyFace *> *vsFaces, IwTA<IwPolyFace *> *veFaces, IwPolyVertex *vertexStart, IwPolyVertex *vertexEnd, IwTA<IwPolyVertex *> *vertexsI, IwTA<IwPolyVertex *> *vertexsE, IwTA<int> *isSeam, IwTA<double> *valCrease )
{
	ULONG ulIndex;
	bool onlyvsFaces;
	int i, j;
	IwPolyVertex *vs, *ve;
	IwPolyEdge *e, *eAux;
	IwTA<IwPolyVertex *> currentV;
	IwTA<IwPolyEdge *> edges;
	IwPolyFace *face;

	if ( !vsFaces || !veFaces || !vertexStart || !vertexEnd || !vertexsI || !vertexsE || !isSeam || !valCrease || veFaces->GetSize( ) <= 0 ) return;

	onlyvsFaces = false;
	if ( vsFaces->GetSize( ) <= 0 ) {
		vsFaces = veFaces;
		onlyvsFaces = true;
	}
	vertexsI->RemoveAll( );
	vertexsE->RemoveAll( );
	isSeam->RemoveAll( );
	valCrease->RemoveAll( );

	// Información de aristas que influyen en vertexStart
	for ( i = 0; i < (int) vsFaces->GetSize( ); i++ ) {
		face = vsFaces->GetAt( i );
		face->GetPolyEdges( edges );
		for ( j = 0; j < (int) edges.GetSize( ); j++ ) {
			e = edges[ j ];
			if ( !e ) continue;
			vs = e->GetStartVertex( );
			if ( vs == vertexStart ) vs = NULL;
			vertexsI->Add( vs );
			ve = e->GetEndVertex( );
			if ( ve == vertexStart ) ve = NULL;
			vertexsE->Add( ve );
			valCrease->Add( e->GetUserFloat1( ) );
			isSeam->Add( e->GetUserInt1( ) );
			if ( vs == NULL ) currentV.Add( ve );
			else if ( ve == NULL )
				currentV.Add( vs );
		}
	}
	// Información de aristas que influyen en vertexEnd
	if ( onlyvsFaces ) return;
	for ( i = 0; i < (int) veFaces->GetSize( ); i++ ) {
		face = veFaces->GetAt( i );
		face->GetPolyEdges( edges );
		for ( j = 0; j < (int) edges.GetSize( ); j++ ) {
			e = edges[ j ];
			if ( !e ) continue;
			vs = e->GetStartVertex( );
			if ( vs == vertexEnd ) vs = NULL;
			vertexsI->Add( vs );
			ve = e->GetEndVertex( );
			if ( ve == vertexEnd ) ve = NULL;
			vertexsE->Add( ve );
			isSeam->Add( e->GetUserInt1( ) );
			if ( !vs && currentV.FindElement( ve, ulIndex ) ) {
				ve->FindPolyEdgeBetween( vertexStart, eAux );
				if ( eAux && IsEdgeCrease( eAux ) && IsEdgeCrease( e ) ) {
					if ( eAux->GetUserFloat1( ) >= e->GetUserFloat1( ) ) valCrease->Add( eAux->GetUserFloat1( ) );
					else
						valCrease->Add( e->GetUserFloat1( ) );
				} else
					valCrease->Add( 0 );
			} else if ( !ve && currentV.FindElement( vs, ulIndex ) ) {
				vs->FindPolyEdgeBetween( vertexStart, eAux );
				if ( eAux && IsEdgeCrease( eAux ) && IsEdgeCrease( e ) ) {
					if ( eAux->GetUserFloat1( ) >= e->GetUserFloat1( ) ) valCrease->Add( eAux->GetUserFloat1( ) );
					else
						valCrease->Add( e->GetUserFloat1( ) );
				} else
					valCrease->Add( 0 );
			} else
				valCrease->Add( e->GetUserFloat1( ) );
		}
	}
}

//==============================================================================
// TPBrepData - Cálculo de contornos
//==============================================================================
void TPBrepData::JoinTrianglesInQuads( TOGLTransf *OGLTransf )
{
	bool isconcave, found, joined;
	int i, j, j2, k, numtimes, nFaces, cont, numborders, indexAux, indexEdge1Aux, indexEdge2Aux;
	ULONG foundindex;
	double anglerad, anglerad1;
	IwPolyVertex *v0, *v1, *v2, *v3, *vertexopptobound, *v1bound, *v2bound, *vAux;
	IwPolyEdge *edge, *edge1, *edge2, *edgeaux1, *edgeaux1Prev, *edgeaux1Bis, *edgeaux2;
	IwPolyFace *face1, *face2, *face3, *newFace;
	IwTA<IwPolyFace *> adjacentFaces, boundaryfaces, vertexboundaryfaces, facestoremove, *facestosearch, *setoffaces;
	IwTA<IwPolyEdge *> boundaryedges, edgesface;
	IwTA<IwPolyVertex *> boundaryvertexs, adjacentvertices, vertexnewface;
	IwTA<IwPolyRegion *> regions;
	IwTA<IwPolyShell *> shells;
	IwVector3d vect1, vect2;
	IwPoint3d point;
	TAddedElements addedElements;

	if ( !PBrep ) return;

	InitUserIndex2( false, false, true );

	PBrep->GetPolyRegions( regions );
	PBrep->GetPolyShells( shells );

	PBrep->GetBoundaryEdges( boundaryedges );
	for ( i = 0; i < (int) boundaryedges.GetSize( ); i++ )
		boundaryfaces.Add( boundaryedges[ i ]->GetPolyFace( ) );

	// Paso 0: Juntar los triangulos de los bordes con la finalidad de que todos los vertices del borde tengan 1 y solo 1 arista hacia el interior.
	// Paso 1: Juntar todos los triangulos del borde con su quad adyacente (a izquierda o a derecha dependiendo del angulo de la arista, cogera la del angulo mas pequeño respescto del vertice que comparten )
	// Paso 2: Paso general juntando todos los triangulos de la malla

	joined = false;
	for ( numtimes = 0; numtimes < 3; numtimes++ ) {
		if ( joined && numtimes == 2 ) numtimes = 1; // Repetimos el paso 1 hasta que no se puedan unificar caras

		if ( numtimes == 0 ) {
			vertexboundaryfaces.RemoveAll( );
			boundaryvertexs.RemoveAll( );
			PBrep->GetBoundaryVertices( boundaryvertexs );
			for ( i = 0; i < (int) boundaryvertexs.GetSize( ); i++ ) {
				boundaryedges.RemoveAll( );
				adjacentvertices.RemoveAll( );
				boundaryvertexs[ i ]->GetAdjacentVertices( adjacentvertices );
				if ( adjacentvertices.GetSize( ) > 3 ) {
					adjacentFaces.RemoveAll( );
					boundaryvertexs[ i ]->GetPolyFaces( adjacentFaces );
					for ( j = 0; j < (int) adjacentFaces.GetSize( ); j++ ) {
						if ( boundaryfaces.FindElement( adjacentFaces[ j ], foundindex ) ) continue;
						vertexboundaryfaces.Add( adjacentFaces[ j ] ); // Vertices borde de las caras sin arista en el borde
					}
				}
			}
			facestosearch = &vertexboundaryfaces;
			setoffaces = &boundaryfaces;
		} else if ( numtimes == 1 ) {
			joined = false;
			facestosearch = &boundaryfaces;
			setoffaces = &boundaryfaces;
		} else {
			vertexboundaryfaces.RemoveAll( );
			boundaryvertexs.RemoveAll( );
			PBrep->GetBoundaryVertices( boundaryvertexs );
			for ( i = 0; i < (int) boundaryvertexs.GetSize( ); i++ ) {
				boundaryedges.RemoveAll( );
				adjacentvertices.RemoveAll( );
				boundaryvertexs[ i ]->GetAdjacentVertices( adjacentvertices );
				if ( adjacentvertices.GetSize( ) > 3 ) {
					adjacentFaces.RemoveAll( );
					boundaryvertexs[ i ]->GetPolyFaces( adjacentFaces );
					for ( j = 0; j < (int) adjacentFaces.GetSize( ); j++ ) {
						if ( boundaryfaces.FindElement( adjacentFaces[ j ], foundindex ) ) continue;
						vertexboundaryfaces.Add( adjacentFaces[ j ] ); // Vertices borde de las caras sin arista en el borde
					}
				}
			}
			facestosearch = &PBrepFaces;
		}

		cont = 0;
		i = -1;

		nFaces = facestosearch->GetSize( );
		if ( nFaces <= 0 ) continue;

		do {
			found = false;
			do {
				i++;
				face1 = ( *facestosearch )[ i ];
				if ( numtimes == 2 ) found = vertexboundaryfaces.FindElement( face1, foundindex );
			} while ( i < nFaces - 1 && face1->GetUserIndex2( ) != 0 && !face1->IsTriangle( ) && ( numtimes == 2 && found ) );

			if ( !face1 || face1->GetUserIndex2( ) != 0 || !face1->IsTriangle( ) ) continue;

			isconcave = true;
			GetAdjacentFaces( face1, &adjacentFaces, true, true );
			for ( j = 0; j < (int) adjacentFaces.GetSize( ); j++ ) {
				face2 = adjacentFaces[ j ];
				if ( ( numtimes == 0 || numtimes == 1 ) && !( *setoffaces ).FindElement( face2, foundindex ) ) continue;
				if ( face2->GetUserIndex2( ) != 0 ) continue;
				if ( ( numtimes == 0 || numtimes == 2 ) && !face2->IsTriangle( ) ) continue;

				// En el Paso 1. Miramos si la otra cara adyacente es un quad o un triangulo
				if ( numtimes == 1 ) {
					numborders = 0;
					edge = 0;
					edgesface.RemoveAll( );
					face1->GetPolyEdges( edgesface );
					for ( k = 0; k < (int) edgesface.GetSize( ); k++ ) {
						if ( edgesface[ k ]->IsBoundary( ) ) {
							numborders++;
							edge = edgesface[ k ];
						}
					}
					if ( !edge || numborders != 1 ) continue;

					// edge = arista de borde exterior
					v1bound = edge->GetStartVertex( );
					v2bound = edge->GetEndVertex( );
					found = false;
					for ( j2 = j + 1; j2 < (int) adjacentFaces.GetSize( ); j2++ ) {
						face3 = adjacentFaces[ j2 ];
						if ( face3 == face2 ) continue;
						if ( !( *setoffaces ).FindElement( face3, foundindex ) ) continue;
						if ( face3->GetUserIndex2( ) != 0 ) continue;
						if ( !face2->IsTriangle( ) && !face3->IsTriangle( ) ) {
							// Sacamos los angulos de la arista borde
							edge1 = edge->GetCWPolyEdge( );
							edge2 = edge->GetCCWPolyEdge( );

							vect1 = edge1->GetStartPoint( ) - edge1->GetEndPoint( );
							vect2 = edge->GetEndPoint( ) - edge->GetStartPoint( );
							vect1.AngleBetween( vect2, anglerad );

							vect1 = edge2->GetEndPoint( ) - edge2->GetStartPoint( );
							vect2 = edge->GetStartPoint( ) - edge->GetEndPoint( );
							vect1.AngleBetween( vect2, anglerad1 );

							edgeaux1 = edge1->GetSymmetricPolyEdge( );
							edgeaux2 = edge2->GetSymmetricPolyEdge( );
							if ( !edgeaux1 || !edgeaux2 ) continue;
							if ( anglerad < anglerad1 && edgeaux1->GetPolyFace( )->GetUserIndex2( ) == 0 ) {
								face2 = edgeaux1->GetPolyFace( ); // Nos quedamos con el angulo más pequeño
								edge = edgeaux1;
							} else {
								face2 = edgeaux2->GetPolyFace( );
								edge = edgeaux2;
							}
							found = true;
							break;
						} else if ( !face3->IsTriangle( ) ) {
							face2 = face3;
							edgesface.RemoveAll( );
							edgesface = GetCommonEdgesBetweenFaces( face1, face2 );
							if ( edgesface[ 0 ]->GetPolyFace( ) == face2 ) edge = edgesface[ 0 ];
							else
								edge = edgesface[ 0 ]->GetSymmetricPolyEdge( );
							found = true;
							break;
						} else if ( !face2->IsTriangle( ) ) {
							edgesface.RemoveAll( );
							edgesface = GetCommonEdgesBetweenFaces( face1, face2 );
							if ( edgesface[ 0 ]->GetPolyFace( ) == face2 ) edge = edgesface[ 0 ];
							else
								edge = edgesface[ 0 ]->GetSymmetricPolyEdge( );
							found = true;
							break;
						}
					}
					if ( !found || !edge || !face1 || !face2 || face1->GetUserIndex2( ) != 0 || face2->GetUserIndex2( ) != 0 ) continue;

					// Añadimos un vertice a la cara contigua para convertir el triangulo en quad
					// Preparacion de la conversion;
					// edge = arista que comparten ambas caras
					// Nueva cara del quad
					if ( edge->GetStartVertex( ) == v1bound || edge->GetStartVertex( ) == v2bound ) {
						edgeaux1 = edge->GetCCWPolyEdge( );
						vertexopptobound = edge->GetEndVertex( );
					} else {
						edgeaux1 = edge->GetCWPolyEdge( );
						vertexopptobound = edge->GetStartVertex( );
					}
					edgeaux1->EvaluatePoint( 0.5, point );
					vertexnewface.RemoveAll( );

					face2->SetUserIndex2( ++cont );
					edgeaux1->SetUserIndex2( ++cont );
					edge->SetUserIndex2( ++cont );

					vAux = edgeaux1->GetEndVertex( );
					indexAux = face2->GetUserIndex2( );
					indexEdge1Aux = edgeaux1->GetUserIndex2( );
					indexEdge2Aux = edge->GetUserIndex2( );
					InitAddedElements( &addedElements );

					SplitEdge( OGLTransf, edgeaux1, 0, &addedElements, true, false );

					v1 = addedElements.iwVertexs[ addedElements.iwVertexs.GetSize( ) - 1 ];
					for ( k = 0; k < (int) addedElements.iwFaces.GetSize( ); k++ ) { // Restauro face2
						if ( (int) addedElements.iwFaces[ k ]->GetUserIndex2( ) == indexAux ) {
							face2 = addedElements.iwFaces[ k ];
							break;
						}
					}
					edgeaux1Prev = edgeaux1Bis = 0;
					for ( k = 0; k < (int) addedElements.iwEdges.GetSize( ); k++ ) { // Restauro edgeaux1
						if ( (int) addedElements.iwEdges[ k ]->GetUserIndex2( ) == indexEdge1Aux ) {
							if ( addedElements.iwEdges[ k ]->GetEndVertex( ) == vAux ) edgeaux1Bis = addedElements.iwEdges[ k ];
							else
								edgeaux1Prev = addedElements.iwEdges[ k ];
						}
					}
					if ( !edgeaux1Prev || !edgeaux1Bis ) continue;
					edgeaux1 = edgeaux1Bis;
					for ( k = 0; k < (int) addedElements.iwEdges.GetSize( ); k++ ) { // Restauro edge
						if ( (int) addedElements.iwEdges[ k ]->GetUserIndex2( ) == indexEdge2Aux ) {
							edge = addedElements.iwEdges[ k ];
							break;
						}
					}
					if ( !edge ) continue;

					// Quad que se reduce de tamaño
					vertexnewface.Add( v1 );
					edgeaux2 = edgeaux1->GetCCWPolyEdge( );
					if ( edgeaux1->GetEndVertex( ) != vertexopptobound ) {
						edgeaux2 = edgeaux1;
						v3 = edge->GetStartVertex( );
					} else
						v3 = edgeaux1Prev->GetStartVertex( );
					v2 = edgeaux2->GetEndVertex( );

					edge1 = edgeaux2;
					while ( v2 != v3 ) {
						vertexnewface.Add( v2 );
						edge2 = edge1->GetCCWPolyEdge( );
						v2 = edge2->GetEndVertex( );
						edge1 = edge2;
					}
					vertexnewface.Add( v2 );
					PBrep->CreatePolyFace( regions.GetAt( 0 ), shells.GetAt( 0 ), vertexnewface, newFace );
					newFace->SetUserIndex2( ++cont );
					facestoremove.Add( face2 );

					joined = true;

					// Nueva cara del triangulo que pasa a ser un quad
					vertexnewface.RemoveAll( );
					vertexnewface.Add( v1 );
					edge1 = edge->GetSymmetricPolyEdge( );
					if ( !edge1 ) continue;
					v2 = edge1->GetEndVertex( );
					v3 = edge1->GetStartVertex( );
					while ( v2 != v3 ) {
						vertexnewface.Add( v2 );
						edge2 = edge1->GetCCWPolyEdge( );
						v2 = edge2->GetEndVertex( );
						edge1 = edge2;
					}
					vertexnewface.Add( v2 );
					PBrep->CreatePolyFace( regions.GetAt( 0 ), shells.GetAt( 0 ), vertexnewface, newFace );
					newFace->SetUserIndex2( ++cont );
					facestoremove.Add( face1 );

					break;
				}

				if ( numtimes == 0 || numtimes == 2 ) {
					edge = GetEdgeBetweenFaces( face1, face2 );
					if ( !edge ) continue;

					edge2 = edge->GetSymmetricPolyEdge( );
					if ( !edge2 ) continue;

					edge1 = edge->GetCWPolyEdge( );
					edge2 = edge2->GetCCWPolyEdge( );

					vect1 = edge1->GetStartPoint( ) - edge1->GetEndPoint( );
					vect2 = edge2->GetEndPoint( ) - edge2->GetStartPoint( );
					vect1.AngleBetween( vect2, anglerad );
					if ( anglerad < 0.0 ) anglerad += 2.0 * IW_PI;
					if ( anglerad > IW_PI + IW_EFF_ZERO_SQRT ) isconcave = true;
					else
						isconcave = false;

					if ( !isconcave ) { // Miramos el otro extremo
						edge2 = edge->GetSymmetricPolyEdge( );

						edge1 = edge->GetCCWPolyEdge( );
						edge2 = edge2->GetCWPolyEdge( );

						vect1 = edge1->GetEndPoint( ) - edge1->GetStartPoint( );
						vect2 = edge2->GetStartPoint( ) - edge2->GetEndPoint( );
						vect1.AngleBetween( vect2, anglerad );
						if ( anglerad < 0.0 ) anglerad += 2.0 * IW_PI;
						if ( anglerad > IW_PI + IW_EFF_ZERO_SQRT ) isconcave = true;
						else
							isconcave = false;

						v0 = edge->GetEndVertex( );
						v1 = edge1->GetEndVertex( );
						v2 = edge->GetStartVertex( );
						v3 = edge2->GetStartVertex( );
					}

					if ( !isconcave ) {
						face1->SetUserIndex2( ++cont );
						face2->SetUserIndex2( ++cont );

						PBrep->CreatePolyQuad( regions.GetAt( 0 ), shells.GetAt( 0 ), v0, v1, v2, v3, newFace );
						newFace->SetUserIndex2( ++cont ); // Para que tampoco la tenga en cuenta en el proceso

						facestoremove.Add( face1 );
						facestoremove.Add( face2 );
						break;
					}
				}
			}
		} while ( i < nFaces - 1 );

		if ( numtimes == 0 || numtimes == 1 ) {
			for ( i = 0; i < (int) facestoremove.GetSize( ); i++ )
				PBrep->DeletePolyFace( facestoremove[ i ] );
			facestoremove.RemoveAll( );

			InitUserIndex2( false, false, true );

			UpdateTopology( OGLTransf );

			boundaryedges.RemoveAll( );
			PBrep->GetBoundaryEdges( boundaryedges );
			boundaryfaces.RemoveAll( );
			for ( i = 0; i < (int) boundaryedges.GetSize( ); i++ )
				boundaryfaces.Add( boundaryedges[ i ]->GetPolyFace( ) );
		}
	}

	for ( i = 0; i < (int) facestoremove.GetSize( ); i++ )
		PBrep->DeletePolyFace( facestoremove[ i ] );

	InitUserIndex2( false, false, true );

	UpdateTopology( OGLTransf );
}

//------------------------------------------------------------------------------

bool TPBrepData::DuplicateFaces( TOGLTransf *OGLTransf, IwTA<IwPolyFace *> *newfaces, IwTA<IwPolyEdge *> *boundaryedges, IwTA<IwPolyFace *> *orgfaces )
{
	// Duplica todas las caras de la pbrep en el caso de que no sea cerrada, devuelve los bordes implicados
	// En el caso de que boundaryedges tenga una lista, solo se duplican las caras que estan dentro de ese borde exterior
	bool all;
	int i, j, numFaces, numEdges, userindex1, userindex2;
	ULONG userlong2;
	IwPolyVertex *vertex;
	IwTA<IwPolyRegion *> regions;
	IwTA<IwPolyShell *> shells;
	IwTA<IwPolyVertex *> boundaryvertexs, vertexs, vertexsface, vertexcreated;
	IwTA<IwPolyFace *> boundaryfaces, facesaux;
	IwPolyFace *newFace, *f;

	if ( !PBrep ) return false;

	PBrep->GetPolyRegions( regions );
	PBrep->GetPolyShells( shells );

	all = false;
	if ( boundaryedges->GetSize( ) == 0 || orgfaces == 0 || orgfaces->GetSize( ) == 0 ) all = true;

	if ( all ) PBrep->GetBoundaryEdges( *boundaryedges );

	if ( boundaryedges->GetSize( ) < 3 ) return false;

	newfaces->RemoveAll( );
	InitUserIndex2( true, false, false );
	InitUserIndex1( true, false );
	InitUserLong2( );
	userindex1 = 0;
	userindex2 = 0;
	userlong2 = 0;

	for ( i = 0; i < (int) boundaryedges->GetSize( ); i++ ) {
		boundaryfaces.AddUnique( boundaryedges->GetAt( i )->GetPolyFace( ) );
		boundaryedges->GetAt( i )->SetUserLong2( ++userlong2 );
	}

	if ( all ) PBrep->GetBoundaryVertices( boundaryvertexs );
	for ( i = 0; i < (int) boundaryvertexs.GetSize( ); i++ ) {
		boundaryvertexs[ i ]->GetPolyFaces( facesaux );
		for ( j = 0; j < (int) facesaux.GetSize( ); j++ )
			boundaryfaces.AddUnique( facesaux[ j ] );
	}

	// Replicamos las caras e invertimos su sentido
	if ( all ) numFaces = PBrepFaces.GetSize( );
	else
		numFaces = orgfaces->GetSize( );
	for ( i = 0; i < numFaces; i++ ) {
		vertexsface.ReSet( );
		if ( all ) f = PBrepFaces[ i ];
		else
			f = orgfaces->GetAt( i );
		f->GetPolyVertices( vertexs );
		for ( j = 0; j < (int) vertexs.GetSize( ); j++ ) {
			if ( vertexs[ j ]->GetUserIndex2( ) > 0 || vertexs[ j ]->IsBoundaryVertex( ) ) {
				vertexs[ j ]->SetUserIndex2( ++userindex2 );
				vertex = vertexs[ j ];
			} else {
				if ( vertexs[ j ]->GetUserIndex1( ) == 0 ) {
					vertex = new IwPolyVertex( _GetSMLib( )->GetContext( ), *PBrep, vertexs[ j ]->GetPoint( ), RES_COMP );
					vertexcreated.Add( vertex );
					vertexs[ j ]->SetUserIndex1( ++userindex1 );
				} else
					vertex = vertexcreated[ vertexs[ j ]->GetUserIndex1( ) - 1 ];
			}
			vertexsface.Add( vertex );
		}
		PBrep->CreatePolyFace( regions.GetAt( 0 ), shells.GetAt( 0 ), vertexsface, newFace );
		if ( !newFace ) return false;
		newFace->ReverseOrientation( );
		newfaces->Add( newFace );
	}

	UpdateTopology( OGLTransf );

	boundaryedges->RemoveAll( );
	numEdges = PBrepEdges.GetSize( );
	for ( i = 0; i < numEdges; i++ ) {
		if ( PBrepEdges[ i ]->GetUserLong2( ) > 0 ) boundaryedges->Add( PBrepEdges[ i ] );
	}

	InitUserIndex2( true, false, false );
	InitUserIndex1( true, false );
	InitUserLong2( );

	return true;
}

//==============================================================================
// TPBrepData - FIN Cálculo de contornos
//==============================================================================

//------------------------------------------------------------------------------

void TPBrepData::UpdatePBrepCreases( TOGLTransf *OGLTransf, bool updateDataSubdivision, bool updateOGLList )
{
	if ( updateDataSubdivision ) UpdateDataSubdivision( OGLTransf );
	if ( updateOGLList ) UpdateOGLListCreasesFromPBrep( OGLTransf );
}

//------------------------------------------------------------------------------

void TPBrepData::UpdatePBrepCreasesFromOGLList( TOGLTransf *OGLTransf, bool force )
{
	int j;
	float i0, i1, i1_2, percent;
	IwPolyEdge *edge;
	IwPolyFace *face;
	IwPolyVertex *vertexStart, *vertexEnd;
	IwTA<IwPolyFace *> faces;
	IwTA<IwPolyVertex *> vertexs;

	if ( !RefEnt ) return;

	if ( !ToMesh( RefEnt ) || !ToMesh( RefEnt )->IsPolygonalMesh( ) ) return;

	RemoveCreaseEdges( OGLTransf, false, false, force );

	if ( !ToMesh( RefEnt )->GetCreaseList( ) || ToMesh( RefEnt )->GetCreaseList( )->Count( ) % 2 != 0 ) return;
	for ( j = 0; j < ToMesh( RefEnt )->GetCreaseList( )->Count( ); j += 2 ) {
		i0 = ToMesh( RefEnt )->GetCreaseList( )->GetItem( j )[ 0 ];
		i1 = ToMesh( RefEnt )->GetCreaseList( )->GetItem( j )[ 1 ];
		percent = ToMesh( RefEnt )->GetCreaseList( )->GetItem( j )[ 2 ];

		if ( PBrepPolListRelF[ i0 ].i0 != i0 ) continue;

		face = GetPBrepFace( OGLTransf, i0 );
		if ( !face ) continue;
		face->GetPolyVertices( vertexs );

		vertexStart = vertexs[ i1 ];

		i1_2 = ToMesh( RefEnt )->GetCreaseList( )->GetItem( j + 1 )[ 1 ];

		vertexEnd = vertexs[ i1_2 ];

		edge = GetEdgeFromVertices( vertexStart->GetIndexExt( ), vertexEnd->GetIndexExt( ) );
		if ( edge ) AddCreaseEdges( OGLTransf, edge, percent, j == ToMesh( RefEnt )->GetCreaseList( )->Count( ) - 2 ? true : false );
	}
}

//------------------------------------------------------------------------------

void TPBrepData::UpdateOGLListCreasesFromPBrep( TOGLTransf *OGLTransf, bool updateNormals )
{
	int i, z, i0, i1, size_vertices, count, j, k, numCreases, size_faces, size_edges, mark;
	double values[ 3 ];
	IwPolyEdge *edge;
	IwPolyVertex *vertexStart, *vertexEnd;
	IwTA<IwPolyFace *> faces;
	IwTA<IwPolyVertex *> vertexs;
	IwTA<IwPolyEdge *> edges;
	TOGLPolygon *pol;
	TOGLPolygonList *OGLList;
	TCadDepMesh *depMesh;
	TInteger_List *itemList;
	TInteger_ListList *auxInfoList;
	IwTA<IwTA<IwPolyEdge *> > creaselist;
	IwTA<IwTA<IwPolyFace *> > faces1, faces2;
	IwTA<IwPolyEdge *> edgesFace;
	IwPolyFace *face;
	ULONG index;

	if ( !RefEnt || !ToMesh( RefEnt ) || !ToMesh( RefEnt )->IsPolygonalMesh( ) ) return;

	GetCreaseEdges( OGLTransf, &edges );

	if ( ToMesh( RefEnt )->GetCreaseList( ) ) {
		count = ToMesh( RefEnt )->GetCreaseList( )->Count( );
		ToMesh( RefEnt )->GetCreaseList( )->Clear( );
	} else
		count = 0;

	if ( !count && !edges.GetSize( ) ) {
		if ( updateNormals ) ToMesh( RefEnt )->UpdateNormalsOGLListFromPBrep( OGLTransf );
		return;
	}

	OGLList = RefEnt->GetOGLGeom3D( OGLTransf );
	if ( !OGLList ) return;

	for ( i = 0; i < (int) edges.GetSize( ); i++ ) {
		edge = edges[ i ];
		faces = GetConnectedFacesFromEdge( edge );
		if ( !faces.GetSize( ) ) continue;

		vertexStart = edge->GetStartVertex( );
		vertexEnd = edge->GetEndVertex( );
		faces[ 0 ]->GetPolyVertices( vertexs );

		size_vertices = vertexs.GetSize( );
		i0 = PBrepPolListRelF[ faces[ 0 ]->GetIndexExt( ) ].i0;
		i1 = PBrepPolListRelF[ faces[ 0 ]->GetIndexExt( ) ].i1 * size_vertices;
		pol = OGLList->GetItem( i0 );
		if ( !pol ) continue;
		for ( z = 0; z < size_vertices; z++ ) {
			if ( vertexs[ z ] != vertexStart && vertexs[ z ] != vertexEnd ) continue;
			// Añadimos a la lista los vertices de la cara que forman la arista
			values[ 0 ] = i0;
			values[ 1 ] = i1 + z;
			values[ 2 ] = edge->GetUserFloat1( );
			ToMesh( RefEnt )->GetCreaseList( true )->AddItem( values );
		}
	}

	if ( ToMesh( RefEnt ) && !ToMesh( RefEnt )->HasSubdivisionDepMesh( ) ) {
		auxInfoList = ToMesh( RefEnt )->GetAuxInfoList( );
		if ( auxInfoList && auxInfoList->Count( ) == OGLList->Count( ) && PBrep ) {
			// Rellenamos auxInfoList con la información de las aristas marcadas
			GetGroupsOfFacesFromCreaseSharps( OGLTransf, &creaselist, &faces1, &faces2 );
			numCreases = (int) creaselist.GetSize( );
			PBrep->GetPolyFaces( faces );
			size_faces = faces.GetSize( );
			if ( numCreases > 0 ) {
				for ( i = 0; i < size_faces; i++ ) {
					itemList = auxInfoList->GetItem( i );
					face = faces[ i ]; // face = faces.GetAt( i );
					face->GetPolyEdges( edgesFace );
					size_edges = (int) edgesFace.GetSize( );
					for ( j = 0; j < size_edges; j++ ) {
						edge = edgesFace[ j ]; // edge = edgesFace.GetAt( j );

						for ( k = 0; k < numCreases; k++ )
							if ( creaselist[ k ].FindElement( edge, index ) || creaselist[ k ].FindElement( edge->GetSymmetricPolyEdge( ), index ) ) break;

						if ( k >= numCreases ) continue;

						mark = ( k * 2 ) + 1;
						if ( faces2[ k ].FindElement( face, index ) ) mark += 1;

						itemList->SetItem( ( j * 3 ) + 1, &mark );
						itemList->SetItem( ( ( ( j + 1 ) % size_edges ) * 3 ) + 1, &mark );
					}
				}
			} else {
				mark = 0;
				for ( i = 0; i < size_faces; i++ ) {
					itemList = auxInfoList->GetItem( i );
					count = itemList->Count( );
					for ( j = 0; j < count; j = j + 3 )
						itemList->SetItem( j + 1, &mark );
				}
			}
		}
	}

	if ( updateNormals ) ToMesh( RefEnt )->UpdateNormalsOGLListFromPBrep( OGLTransf );

	if ( ToMesh( RefEnt ) && ToMesh( RefEnt )->HasSubdivisionDepMesh( ) ) {
		depMesh = ToDepMesh( RefEnt->GetDepMeshes( )->GetShape( 0 ) );
		if ( depMesh && depMesh->IsSubdivisionDepMesh( ) ) {
			depMesh->SetDevelop2DDirty( true );
			depMesh->SetTextureDirty( true );
		}
	} else if ( ToMesh( RefEnt ) && ToMesh( RefEnt )->IsPolygonalMesh( ) ) {
		ToMesh( RefEnt )->SetDevelop2DDirty( true );
		ToMesh( RefEnt )->SetTextureDirty( true );
	}
}

//------------------------------------------------------------------------------

// =============================================================================
// TPBrepData - Borrado de elementos de la malla
// =============================================================================
//------------------------------------------------------------------------------
// Se borra los vértices seleccionados
bool TPBrepData::RemoveSelectedVertexs( TOGLTransf *OGLTransf, bool updateTopology )
{
	int i, nVertexs;
	IwTA<IwPolyVertex *> iwVertexs;

	if ( !PBrep || !OGLTransf ) return false;

	// Obtenemos lista de vértieces a eliminar
	nVertexs = (int) PBrepVertexs.GetSize( );
	for ( i = 0; i < nVertexs; i++ )
		if ( SelectedV[ i ].i > 0 ) iwVertexs.Add( PBrepVertexs.GetAt( i ) );

	// Borramos
	if ( !RemoveVertexs( OGLTransf, &iwVertexs, false ) ) return false;

	if ( updateTopology ) UpdateTopology( OGLTransf );

	return true;
}

//------------------------------------------------------------------------------

// Se borra un conjunto de vértices
// Si updateTopology se pasa a false, es responsabilidad del que llama a la función de restaurar la PolygonList y los colores poseriormente
bool TPBrepData::RemoveVertexs( TOGLTransf *OGLTransf, IwTA<IwPolyVertex *> *iwVertexsToRemove, bool updateTopology )
{
	ULONG pos;
	int i, nVertexs;
	IwPolyVertex *iwVertex;
	IwTA<IwPolyVertex *> iwVertexs, iwVertexAux;
	IwTA<IwPolyFace *> iwFacesVertex, iwFaces, iwFacesPBrep;

	if ( !PBrep || !OGLTransf || !iwVertexsToRemove ) return false;

	// Si el resultado elimina toda las caras, dejamos al menos una.
	nVertexs = (int) iwVertexsToRemove->GetSize( );
	if ( nVertexs == 0 ) return false;
	for ( i = 0; i < nVertexs; i++ ) {
		iwVertexsToRemove->GetAt( i )->GetPolyFaces( iwFacesVertex );
		iwFaces.Append( iwFacesVertex );
	}
	iwFaces.RemoveDuplicates( );
	PBrep->GetPolyFaces( iwFacesPBrep );
	if ( iwFaces.GetSize( ) == iwFacesPBrep.GetSize( ) ) {
		iwFacesPBrep.GetAt( 0 )->GetPolyVertices( iwVertexs );
		iwVertexsToRemove->RemoveElements( iwVertexs, iwVertexAux );
		iwVertexsToRemove->RemoveAll( );
		iwVertexsToRemove->Copy( iwVertexAux );
		nVertexs = (int) iwVertexsToRemove->GetSize( );
		if ( nVertexs == 0 ) return false;
	}
	iwFaces.RemoveAll( );

	// Borramos
	for ( i = 0; i < nVertexs; i++ ) {
		PBrep->GetPolyVertices( iwVertexs );
		iwVertex = iwVertexsToRemove->GetAt( i );
		if ( !iwVertexs.FindElement( iwVertex, pos ) ) continue; // Un vertice puede haberse borrado al borrar otro
		RemoveVertex( OGLTransf, iwVertex, false );
	}

	if ( updateTopology ) UpdateTopology( OGLTransf );

	return true;
}

//------------------------------------------------------------------------------

// Se borra un vértice de la malla
bool TPBrepData::RemoveVertex( TOGLTransf *OGLTransf, IwPolyVertex *iwVertex, bool updateTopology )
{
	int i, nFaces;
	IwTA<IwPolyFace *> iwFaces, iwFacesPBrep;
	IwTA<IwPolyVertex *> iwVertexsNewFace;
	IwTA<IwPolyEdge *> iwEdgesFace, iwEdgesNewFace;
	IwTA<IwPolyRegion *> regions;
	IwTA<IwPolyShell *> shells;

	if ( !PBrep || !OGLTransf || !iwVertex ) return false;
	PBrep->GetPolyRegions( regions );
	PBrep->GetPolyShells( shells );
	if ( regions.GetSize( ) == 0 || shells.GetSize( ) == 0 ) return false;

	iwVertex->GetPolyFaces( iwFaces );
	nFaces = (int) iwFaces.GetSize( );
	PBrep->GetPolyFaces( iwFacesPBrep );
	if ( nFaces == (int) iwFacesPBrep.GetSize( ) ) return false;

	for ( i = 0; i < nFaces; i++ )
		PBrep->DeletePolyFace( iwFaces.GetAt( i ) );

	if ( updateTopology ) UpdateTopology( OGLTransf );

	return true;
}

//------------------------------------------------------------------------------

// Se borra las aristas seleccionadas
bool TPBrepData::RemoveSelectedEdges( TOGLTransf *OGLTransf, bool updateTopology )
{
	int i, nEdges;
	IwTA<IwPolyEdge *> iwEdgesToRemove, iwEdgesInvalid;

	if ( !PBrep || !OGLTransf ) return false;

	// Obtenemos lista de aristas a eliminar
	nEdges = (int) PBrepEdges.GetSize( );
	for ( i = 0; i < nEdges; i++ ) {
		if ( SelectedE[ i ] > (int) SelectedElementType::NoSelected && SelectedE[ i ] < (int) SelectedElementType::AllSelected ) iwEdgesToRemove.Add( PBrepEdges.GetAt( i ) );
	}

	if ( !CheckConsistency( 0, &iwEdgesToRemove, 0, &iwEdgesInvalid ) )
		if ( iwEdgesToRemove.GetSize( ) == 0 ) return false;

	// Borramos
	if ( !RemoveEdges( OGLTransf, &iwEdgesToRemove, 0, true, false, false ) ) return false;

	if ( updateTopology ) UpdateTopology( OGLTransf );

	return true;
}

//------------------------------------------------------------------------------

// Se borra un conjunto de aristas
// Si updateTopology se pasa a false, es responsabilidad del que llama a la función de restaurar la PolygonList y los colores poseriormente
bool TPBrepData::RemoveEdges( TOGLTransf *OGLTransf, IwTA<IwPolyEdge *> *iwEdgesToRemove, TAddedElements *addedElements, bool delSimetric, bool repair, bool updateTopology )
{
	ULONG pos, userIndex2, maxUserIndex2;
	int i, j, nEdges, nAddedEdges, nAddedFaces;
	IwPolyEdge *iwEdge;
	IwTA<IwPolyEdge *> iwEdges, iwEdgesAux;
	IwTA<IwPolyFace *> iwFaces, iwFacesPBrep;
	TAddedElements addedElementsAux;

	if ( !OGLTransf || !iwEdgesToRemove || !PBrep ) return false;

	// Si el resultado elimina toda las caras, dejamos al menos una.
	nEdges = (int) iwEdgesToRemove->GetSize( );
	if ( nEdges == 0 ) return false;
	for ( i = 0; i < nEdges; i++ ) {
		iwFaces.Add( iwEdgesToRemove->GetAt( i )->GetPolyFace( ) );
		if ( delSimetric ) {
			iwEdge = iwEdgesToRemove->GetAt( i )->GetSymmetricPolyEdge( );
			if ( iwEdge ) iwFaces.Add( iwEdge->GetPolyFace( ) );
		}
	}
	iwFaces.RemoveDuplicates( );
	PBrep->GetPolyFaces( iwFacesPBrep );
	if ( iwFaces.GetSize( ) == iwFacesPBrep.GetSize( ) ) {
		iwFacesPBrep.GetAt( 0 )->GetPolyEdges( iwEdges );
		if ( delSimetric ) {
			nEdges = (int) iwEdges.GetSize( );
			for ( i = 0; i < nEdges; i++ ) {
				iwEdge = iwEdges.GetAt( i )->GetSymmetricPolyEdge( );
				if ( iwEdge ) iwEdges.Add( iwEdge );
			}
		}
		iwEdgesToRemove->RemoveElements( iwEdges, iwEdgesAux );
		iwEdgesToRemove->RemoveAll( );
		iwEdgesToRemove->Copy( iwEdgesAux );
	}
	iwFaces.RemoveAll( );
	nEdges = (int) iwEdgesToRemove->GetSize( );
	if ( nEdges == 0 ) return false;

	// Si hay que borrar simétricos y no reparar ( es un borrado solo ) hay que añadir las simétricas a la lista
	if ( delSimetric && !repair ) {
		for ( i = 0; i < nEdges; i++ ) {
			iwEdge = iwEdgesToRemove->GetAt( i )->GetSymmetricPolyEdge( );
			if ( iwEdge ) iwEdgesToRemove->AddUnique( iwEdge );
		}
		nEdges = (int) iwEdgesToRemove->GetSize( );
	}

	// Marcamos las aristas a borrar para actualizar los punteros afectados tras cada borrado
	maxUserIndex2 = GetMaxEdgeUserIndex2( );
	for ( i = 0; i < nEdges; i++ )
		iwEdgesToRemove->GetAt( i )->SetUserIndex2( maxUserIndex2 + i + 1 );

	// Borramos
	if ( addedElements ) InitAddedElements( addedElements );
	for ( i = 0; i < nEdges; i++ ) {
		iwEdge = iwEdgesToRemove->GetAt( i );
		if ( !iwEdge ) continue;
		PBrep->GetPolyEdges( iwEdges );
		if ( addedElements && addedElements->iwEdges.FindElement( iwEdge, pos ) ) // Vamos a eliminar una arista que ha sustituido a otra al eliminar una anterior
			addedElements->iwEdges.RemoveAt( pos );
		if ( !iwEdges.FindElement( iwEdge, pos ) ) continue;

		InitAddedElements( &addedElementsAux );
		RemoveEdge( OGLTransf, iwEdge, &addedElementsAux, delSimetric, repair, false );
		nAddedEdges = (int) addedElementsAux.iwEdges.GetSize( );
		for ( j = 0; j < nAddedEdges; j++ ) {
			iwEdge = addedElementsAux.iwEdges.GetAt( j );
			if ( iwEdgesToRemove->FindElement( iwEdge, pos ) ) // La nueva arista ocupa la posición de memoria de una que ha sido eliminada por efecto de eliminar iwEdge
				iwEdgesToRemove->SetAt( pos, 0 );

			// Miramos si la nueva arista sustituye a una arista pendiente de eliminar
			userIndex2 = iwEdge->GetUserIndex2( );
			if ( userIndex2 > maxUserIndex2 ) iwEdgesToRemove->SetAt( userIndex2 - maxUserIndex2 - 1, iwEdge );
		}
		if ( addedElements ) IncludeToAddedElements( addedElements, &addedElementsAux );
	}

	InitEdgeUserIndex2( maxUserIndex2 );

	// Limpiamos los elementos añadidos
	if ( addedElements ) {
		PBrep->GetPolyEdges( iwEdges );
		nAddedEdges = (int) addedElements->iwEdges.GetSize( );
		for ( j = nAddedEdges - 1; j >= 0; j-- ) {
			if ( !iwEdges.FindElement( addedElements->iwEdges.GetAt( j ), pos ) ) addedElements->iwEdges.RemoveAt( (ULONG) j );
		}

		PBrep->GetPolyFaces( iwFaces );
		nAddedFaces = (int) addedElements->iwFaces.GetSize( );
		for ( j = nAddedFaces - 1; j >= 0; j-- ) {
			if ( !iwFaces.FindElement( addedElements->iwFaces.GetAt( j ), pos ) ) addedElements->iwFaces.RemoveAt( (ULONG) j );
		}
	}

	if ( updateTopology ) UpdateTopology( OGLTransf );

	return true;
}

//------------------------------------------------------------------------------

// Se borra una arista de la malla
bool TPBrepData::RemoveEdge( TOGLTransf *OGLTransf, IwPolyEdge *iwEdge, TAddedElements *addedElements, bool delSimetric, bool repair, bool updateTopology )
{
	int i, j, nEdges;
	IwPolyEdge *iwSymmetricEdge;
	IwPolyFace *iwFace, *iwSymmetricFace, *newFace;
	IwTA<IwPolyFace *> faces;
	IwTA<IwPolyVertex *> iwVertexsNewFace, iwStartVertexRemovedEdges, iwEndVertexRemovedEdges, start2, end2;
	IwTA<IwPolyEdge *> iwEdgesFace, iwEdgesNewFace;
	IwTA<int> iwIndexesRemovedEdges;
	IwTA<IwPolyRegion *> regions;
	IwTA<IwPolyShell *> shells;
	IwTA<ULONG> indexes2;
	IwTA<int> userlongs2;
	IwTA<float> values;
	TAddedElements *addedElements2, addedElements3;

	if ( !PBrep || !iwEdge ) return false;
	PBrep->GetPolyRegions( regions );
	PBrep->GetPolyShells( shells );
	if ( regions.GetSize( ) == 0 || shells.GetSize( ) == 0 ) return false;

	if ( addedElements ) addedElements2 = addedElements;
	else
		addedElements2 = &addedElements3;

	iwFace = iwEdge->GetPolyFace( );
	if ( delSimetric ) {
		iwSymmetricEdge = iwEdge->GetSymmetricPolyEdge( );
		iwSymmetricFace = iwSymmetricEdge ? iwSymmetricEdge->GetPolyFace( ) : 0;
	} else
		iwSymmetricFace = 0;

	if ( addedElements2 && repair ) {
		faces = GetConnectedFacesFromEdge( iwEdge );
		for ( j = 0; j < (int) faces.GetSize( ); j++ ) {
			faces[ j ]->GetPolyEdges( iwEdgesFace );
			nEdges = (int) iwEdgesFace.GetSize( );
			for ( i = 0; i < nEdges; i++ )
				SaveCreaseEdgeInfo( iwEdgesFace[ i ], &userlongs2, &values, true );
		}
	}

	if ( addedElements2 && repair && iwSymmetricFace ) {
		AddEdgesAffectedFromFace( iwFace, &iwIndexesRemovedEdges, &iwStartVertexRemovedEdges, &iwEndVertexRemovedEdges );
		AddCreaseEdgesAffectedFromFace( iwFace, &indexes2, &start2, &end2 );
		AddEdgesAffectedFromFace( iwSymmetricFace, &iwIndexesRemovedEdges, &iwStartVertexRemovedEdges, &iwEndVertexRemovedEdges );
		AddCreaseEdgesAffectedFromFace( iwSymmetricFace, &indexes2, &start2, &end2 );
	}

	if ( repair && iwSymmetricFace ) {
		if ( GetOrderedEdgesNewFaceFromRemoveEdge( iwEdge, &iwEdgesNewFace ) ) {
			nEdges = (int) iwEdgesNewFace.GetSize( );
			for ( i = 0; i < nEdges; i++ )
				iwVertexsNewFace.Add( iwEdgesNewFace.GetAt( i )->GetStartVertex( ) );
			PBrep->CreatePolyFace( regions.GetAt( 0 ), shells.GetAt( 0 ), iwVertexsNewFace, newFace );
			if ( addedElements2 ) AddFaceAndEdgesToElements( newFace, addedElements2 );
		} else
			return false;
	}

	if ( addedElements2 ) {
		RemoveFaceAndEdgesFromElements( iwFace, addedElements2 );
	}
	PBrep->DeletePolyFace( iwFace );
	if ( iwSymmetricFace ) {
		if ( addedElements2 ) RemoveFaceAndEdgesFromElements( iwSymmetricFace, addedElements2 );
		PBrep->DeletePolyFace( iwSymmetricFace );
	}

	if ( addedElements2 ) {
		UpdateEdgesAffected( addedElements2, &iwIndexesRemovedEdges, &iwStartVertexRemovedEdges, &iwEndVertexRemovedEdges );
		UpdateCreaseEdgesAffected( addedElements2, &indexes2, &start2, &end2 );
		if ( repair && userlongs2.GetSize( ) > 0 ) RestoreCreaseEdgeInfo( addedElements2, &userlongs2, &values );
	}

	if ( updateTopology ) UpdateTopology( OGLTransf );

	return true;
}

//------------------------------------------------------------------------------

// Se borra las caras seleccionadas
bool TPBrepData::RemoveSelectedFaces( TOGLTransf *OGLTransf, bool updateTopology )
{
	int i, nFaces;
	IwTA<IwPolyFace *> iwFaces;

	if ( !PBrep || !OGLTransf ) return false;

	// Obtenemos lista de caras a eliminar
	nFaces = (int) PBrepFaces.GetSize( );
	for ( i = 0; i < nFaces; i++ ) {
		if ( SelectedF[ i ].i > 0 ) iwFaces.Add( PBrepFaces.GetAt( i ) );
	}

	// Borramos
	if ( !RemoveFaces( OGLTransf, &iwFaces, false ) ) return false;

	if ( updateTopology ) UpdateTopology( OGLTransf );

	return true;
}

//------------------------------------------------------------------------------

// Se borra un conjunto de caras
// Si updateTopology se pasa a false, es responsabilidad del que llama a la función de restaurar la PolygonList y los colores poseriormente
bool TPBrepData::RemoveFaces( TOGLTransf *OGLTransf, IwTA<IwPolyFace *> *iwFaces, bool updateTopology )
{
	int i, nFaces, nFacesPBrep;
	IwTA<IwPolyFace *> iwFacesPBrep;

	if ( !PBrep || !OGLTransf || !iwFaces ) return false;

	nFaces = (int) iwFaces->GetSize( );
	if ( nFaces == 0 ) return false;
	PBrep->GetPolyFaces( iwFacesPBrep );
	nFacesPBrep = (int) iwFacesPBrep.GetSize( );
	i = ( nFaces != nFacesPBrep ? 0 : 1 );
	for ( ; i < nFaces; i++ )
		RemoveFace( OGLTransf, iwFaces->GetAt( i ), false );

	if ( updateTopology ) UpdateTopology( OGLTransf );

	return true;
}

//------------------------------------------------------------------------------

// Se borra una cara de la malla
bool TPBrepData::RemoveFace( TOGLTransf *OGLTransf, IwPolyFace *iwFace, bool updateTopology )
{
	IwTA<IwPolyFace *> iwFacesPBrep;

	if ( !PBrep || !iwFace ) return false;

	PBrep->GetPolyFaces( iwFacesPBrep );
	if ( iwFacesPBrep.GetSize( ) < 2 ) return false;

	PBrep->DeletePolyFace( iwFace );

	if ( updateTopology ) UpdateTopology( OGLTransf );

	return true;
}

//------------------------------------------------------------------------------

// Se invierte una lista de caras
bool TPBrepData::InvertFacesMeshBySelection( TOGLTransf *OGLTransf, TInteger_List *faces, bool updateTopology )
{
	int i, j, k, nFaces, indFace, numPol, numFace, numVert, value, pos1, pos2;
	TOGLPoint point;
	TOGLPolygonList *OGLList;
	IwPolyFace *iwFace;
	TInteger_ListList *auxInfoList;

	if ( !OGLTransf || !GetPBrep( OGLTransf ) || !faces ) return false;
	OGLList = RefEnt->GetOGLGeom3D( OGLTransf );
	if ( !OGLList ) return false;
	auxInfoList = ToMesh( RefEnt )->GetAuxInfoList( );
	if ( auxInfoList && auxInfoList->Count( ) != OGLList->Count( ) ) return false;

	nFaces = faces->Count( );
	for ( i = 0; i < nFaces; i++ ) {
		indFace = *faces->GetItem( i );
		iwFace = GetPBrepFace( OGLTransf, indFace );
		if ( !iwFace ) continue;

		iwFace->ReverseOrientation( );

		if ( GetPBrepPolListRelF( OGLTransf, indFace, numPol, numFace, numVert ) ) {
			// Invertimos la cara en la OGLList de RefEnt
			for ( j = 0; j < numVert; j++ ) {
				OGLList->GetItem( numPol )->GetItem( numFace + j )->n.v[ 0 ] *= -1.0;
				OGLList->GetItem( numPol )->GetItem( numFace + j )->n.v[ 1 ] *= -1.0;
				OGLList->GetItem( numPol )->GetItem( numFace + j )->n.v[ 2 ] *= -1.0;
			}
			point.Set( OGLList->GetItem( numPol )->GetItem( numFace ) );
			OGLList->GetItem( numPol )->GetItem( numFace )->Set( OGLList->GetItem( numPol )->GetItem( numFace + 1 ) );
			OGLList->GetItem( numPol )->GetItem( numFace + 1 )->Set( &point );
			if ( numVert > 3 ) {
				for ( j = 0; j < ( numVert - 2 ) / 2; j++ ) {
					point.Set( OGLList->GetItem( numPol )->GetItem( numFace + 2 + j ) );
					OGLList->GetItem( numPol )->GetItem( numFace + 2 + j )->Set( OGLList->GetItem( numPol )->GetItem( numFace + numVert - 1 - j ) );
					OGLList->GetItem( numPol )->GetItem( numFace + numVert - 1 - j )->Set( &point );
				}
			}

			// Invertimos la cara en AuxInfoList (seams)
			if ( auxInfoList ) {
				for ( k = 0; k < 3; k++ ) {
					value = *( auxInfoList->GetItem( indFace )->GetItem( k ) );
					*( auxInfoList->GetItem( indFace )->GetItem( k ) ) = *( auxInfoList->GetItem( indFace )->GetItem( k + 3 ) );
					*( auxInfoList->GetItem( indFace )->GetItem( k + 3 ) ) = value;
				}
				if ( numVert > 3 ) {
					for ( j = 0; j < ( numVert - 2 ) / 2; j++ ) {
						pos1 = ( j + 2 ) * 3;
						pos2 = ( numVert - 1 - j ) * 3;
						for ( k = 0; k < 3; k++ ) {
							value = *( auxInfoList->GetItem( indFace )->GetItem( pos1 + k ) );
							*( auxInfoList->GetItem( indFace )->GetItem( pos1 + k ) ) = *( auxInfoList->GetItem( indFace )->GetItem( pos2 + k ) );
							*( auxInfoList->GetItem( indFace )->GetItem( pos2 + k ) ) = value;
						}
					}
				}
			}
		}
	}

	if ( updateTopology ) UpdateTopology( OGLTransf );
	else {
		OGLList->Download( );
		ToMesh( RefEnt )->SetDevelop2DDirty( true );
		ToMesh( RefEnt )->SetTextureDirty( true );
		SetTopologyDirty( true );
		UpdateOGLListSeamFromPBrep( OGLTransf );
		UpdateOGLListCreasesFromPBrep( OGLTransf, false );
	}

	return true;
}

//------------------------------------------------------------------------------

// A partir de la cara de índice faceRef se selecciona el conjunto que forma un grupo aislado
// y se invierten a fin de invertir sus normales.
bool TPBrepData::InvertFacesMeshBySelection( TOGLTransf *OGLTransf, int faceRef, TInteger_List *facesInverted, bool updateTopology )
{
	int i, nFacesToInvert, numFace;
	TOGLPoint point;
	IwPolyFace *iwfaceref;
	IwTA<IwPolyFace *> facesToInvert;
	TInteger_List indFaces, *pIndFaces;

	if ( !OGLTransf || !GetPBrep( OGLTransf ) || faceRef < 0 ) return false;

	iwfaceref = GetPBrepFace( OGLTransf, faceRef );
	if ( !iwfaceref ) return false;
	facesToInvert = GetFacesInsideNoSelection( iwfaceref, ElementType::Face );
	nFacesToInvert = (int) facesToInvert.GetSize( );
	if ( nFacesToInvert == 0 ) return false;

	pIndFaces = facesInverted ? facesInverted : &indFaces;
	pIndFaces->Clear( );
	for ( i = 0; i < nFacesToInvert; i++ ) {
		numFace = facesToInvert.GetAt( i )->GetIndexExt( );
		pIndFaces->AddItem( &numFace );
	}

	if ( !InvertFacesMeshBySelection( OGLTransf, pIndFaces, updateTopology ) ) return false;

	return true;
}

//------------------------------------------------------------------------------

// Se invierte todas las caras
// Si updateTopology se pasa a false, es responsabilidad del que llama a la función de restaurar la PolygonList y los colores posteriormente
bool TPBrepData::InvertAllFacesMesh( TOGLTransf *OGLTransf, bool updateTopology )
{
	int i, nFaces, numFace;
	IwTA<IwPolyFace *> iwFaces;
	TInteger_List indFaces;

	if ( !OGLTransf ) return false;
	if ( !GetPBrep( OGLTransf ) ) return false;

	PBrep->GetPolyFaces( iwFaces );
	nFaces = (int) iwFaces.GetSize( );
	if ( nFaces == 0 ) return false;

	for ( i = 0; i < nFaces; i++ ) {
		numFace = iwFaces.GetAt( i )->GetIndexExt( );
		indFaces.AddItem( &numFace );
	}

	return InvertFacesMeshBySelection( OGLTransf, &indFaces, updateTopology );
}

//------------------------------------------------------------------------------

// Se borran vertices que solo hacen de conexion de dos aristas según un ángulo de tolerancia
void TPBrepData::RemoveUnnecessaryVertexs( TOGLTransf *OGLTransf, IwTA<IwPolyVertex *> *iwVertexs, double angleTolerance, TAddedElements *addedElements, bool updateTopology )
{
	ULONG pos;
	int i, j, nFaces, nVertexs, nEdges;
	IwPolyVertex *iwVertex;
	IwPolyFace *iwFace, *newFace;
	IwTA<IwPolyVertex *> iwVertexsAux, iwVertexsUnnecessary, iwVertexsFace, start2, end2, iwStartVertexRemovedEdges, iwEndVertexRemovedEdges;
	IwTA<IwPolyFace *> iwNewFaces, iwFaces;
	IwTA<IwPolyRegion *> regions;
	IwTA<IwPolyShell *> shells;
	IwTA<IwPolyEdge *> edges;
	IwTA<ULONG> indexes2;
	IwTA<int> userlongs2;
	IwTA<float> values;
	TAddedElements addedElements2;
	IwTA<int> iwIndexesRemovedEdges;

	if ( !PBrep || !OGLTransf || !iwVertexs || angleTolerance < 0.0 || angleTolerance > 90.0 ) return;
	PBrep->GetPolyRegions( regions );
	PBrep->GetPolyShells( shells );
	if ( regions.GetSize( ) == 0 || shells.GetSize( ) == 0 ) return;

	PBrep->GetPolyFaces( iwFaces );
	if ( (int) iwFaces.GetSize( ) > 0 ) {
		// Unificamos las aristas de las caras afectadas que incluyan los vertices previamente marcados
		if ( addedElements ) iwNewFaces.Copy( addedElements->iwFaces );
		nFaces = (int) iwNewFaces.GetSize( );
		for ( i = 0; i < nFaces; i++ )
			RemoveUnnecessaryVertexsFromFace( OGLTransf, iwNewFaces.GetAt( i ), iwVertexs, &iwVertexsUnnecessary, angleTolerance, addedElements, false );
	}

	// Eliminamos definitivamente los vertices innecesarios
	PBrep->GetPolyVertices( iwVertexsAux );
	nVertexs = iwVertexsUnnecessary.GetSize( );
	for ( i = 0; i < nVertexs; i++ ) {
		iwVertex = iwVertexsUnnecessary.GetAt( i );
		if ( !iwVertexsAux.FindElement( iwVertex, pos ) ) continue;
		iwVertex->GetPolyFaces( iwFaces );
		if ( iwFaces.GetSize( ) == 1 ) {
			iwFace = iwFaces.GetAt( 0 );
			iwFace->GetPolyVertices( iwVertexsFace );
			iwVertexsFace.FindElement( iwVertex, pos );
			iwVertexsFace.RemoveAt( pos );
			if ( (int) iwVertexsFace.GetSize( ) > 2 ) {
				InitUserLong2( );
				InitAddedElements( &addedElements2 );
				userlongs2.RemoveAll( );
				values.RemoveAll( );
				iwIndexesRemovedEdges.RemoveAll( );
				iwStartVertexRemovedEdges.RemoveAll( );
				iwEndVertexRemovedEdges.RemoveAll( );
				indexes2.RemoveAll( );
				start2.RemoveAll( );
				end2.RemoveAll( );

				iwFace->GetPolyEdges( edges );
				nEdges = (int) edges.GetSize( );
				for ( j = 0; j < nEdges; j++ )
					SaveCreaseEdgeInfo( edges[ j ], &userlongs2, &values, true );
				AddEdgesAffectedFromFace( iwFace, &iwIndexesRemovedEdges, &iwStartVertexRemovedEdges, &iwEndVertexRemovedEdges );
				AddCreaseEdgesAffectedFromFace( iwFace, &indexes2, &start2, &end2 );
				AddFaceAndEdgesToElements( iwFace, &addedElements2 );
				AddVertexToElements( iwVertex, &addedElements2 );

				PBrep->CreatePolyFace( regions.GetAt( 0 ), shells.GetAt( 0 ), iwVertexsFace, newFace );
				AddFaceAndEdgesToElements( newFace, &addedElements2 );

				UpdateEdgesAffected( &addedElements2, &iwIndexesRemovedEdges, &iwStartVertexRemovedEdges, &iwEndVertexRemovedEdges );
				UpdateCreaseEdgesAffected( &addedElements2, &indexes2, &start2, &end2 );
				UpdateCreaseEdgesAffectedFromDisolve( &addedElements2, &indexes2, &start2, &end2, &userlongs2, &values );
				RestoreCreaseEdgeInfo( &addedElements2, &userlongs2, &values );

				if ( addedElements ) {
					AddFaceAndEdgesToElements( newFace, addedElements );
					RemoveFaceAndEdgesFromElements( iwFace, addedElements );
				}
			}
			PBrep->DeletePolyFace( iwFace );
		}
	}

	if ( updateTopology ) UpdateTopology( OGLTransf );
}

//------------------------------------------------------------------------------

// Se borran de una cara los vertices que solo hacen de conexion de dos aristas y estas son paralelas.
void TPBrepData::RemoveUnnecessaryVertexsFromFace( TOGLTransf *OGLTransf, IwPolyFace *iwFace, IwTA<IwPolyVertex *> *iwVertexs, IwTA<IwPolyVertex *> *iwVertexsUnnecessary, double angleTolerance, TAddedElements *addedElements, bool updateTopology )
{
	ULONG pos;
	int i, j, k, nVertexs, nVertexIni, nEdges;
	double coseno, minCoseno;
	T3DVector v1, v2;
	IwPolyVertex *iwVertex_1, *iwVertex_2, *iwVertex_3;
	IwPolyFace *newFace;
	IwTA<IwPolyVertex *> iwVertexsFace, iwVertexsAdjacent, start2, end2, start3, end3, iwStartVertexRemovedEdges, iwEndVertexRemovedEdges;
	IwTA<IwPolyFace *> faces;
	IwTA<IwPolyEdge *> edges;
	IwTA<IwPolyRegion *> regions;
	IwTA<IwPolyShell *> shells;
	IwTA<int> userlongs2;
	IwTA<float> values;
	IwTA<ULONG> indexes2, indexes3;
	TAddedElements addedElements2;
	IwTA<int> iwIndexesRemovedEdges;

	if ( !PBrep || !OGLTransf || !iwFace || angleTolerance < 0.0 || angleTolerance > 90.0 ) return;
	PBrep->GetPolyRegions( regions );
	PBrep->GetPolyShells( shells );
	if ( regions.GetSize( ) == 0 || shells.GetSize( ) == 0 ) return;
	if ( iwFace->IsTriangle( ) ) return;

	iwFace->GetPolyVertices( iwVertexsFace );
	nVertexs = nVertexIni = (int) iwVertexsFace.GetSize( );

	InitUserLong2( );

	minCoseno = fabs( cos( angleTolerance * M_PI_180 ) );
	for ( i = 0; i < nVertexs; i++ ) {
		iwVertex_2 = iwVertexsFace.GetAt( i );
		if ( iwVertexs && !iwVertexs->FindElement( iwVertex_2, pos ) ) continue;
		iwVertex_2->GetAdjacentVertices( iwVertexsAdjacent );
		if ( iwVertexsAdjacent.GetSize( ) == 2 ) {
			iwVertex_1 = i > 0 ? iwVertexsFace.GetAt( i - 1 ) : iwVertexsFace.GetAt( nVertexs - 1 );
			iwVertex_3 = iwVertexsFace.GetAt( ( i + 1 ) % nVertexs );
			v1 = T3DVector( T3DPoint( iwVertex_1->GetPoint( ).x, iwVertex_1->GetPoint( ).y, iwVertex_1->GetPoint( ).z ), T3DPoint( iwVertex_2->GetPoint( ).x, iwVertex_2->GetPoint( ).y, iwVertex_2->GetPoint( ).z ) );
			v2 = T3DVector( T3DPoint( iwVertex_2->GetPoint( ).x, iwVertex_2->GetPoint( ).y, iwVertex_2->GetPoint( ).z ), T3DPoint( iwVertex_3->GetPoint( ).x, iwVertex_3->GetPoint( ).y, iwVertex_3->GetPoint( ).z ) );
			coseno = fabs( v1.Unitario( ) ^ v2.Unitario( ) );
			if ( ( coseno + RES_GEOM2 ) >= minCoseno ) {
				iwVertexsFace.GetAt( i )->GetPolyFaces( faces );
				for ( j = 0; j < (int) faces.GetSize( ); j++ ) {
					faces[ j ]->GetPolyEdges( edges );
					nEdges = (int) edges.GetSize( );
					for ( k = 0; k < nEdges; k++ )
						// SaveCreaseEdgeInfo( edges[ k ], &userlongs2, &values, true ); Prueba Jair

						// AddFaceAndEdgesToElements( faces[ j ], &addedElements2 );

						AddEdgesAffectedFromFace( faces[ j ], &iwIndexesRemovedEdges, &iwStartVertexRemovedEdges, &iwEndVertexRemovedEdges );
					AddCreaseEdgesAffectedFromFace( faces[ j ], &indexes2, &start2, &end2 );
				}

				AddCreaseEdgesAffectedFromVertexDisolve( iwVertexsFace.GetAt( i ), &indexes3, &start3, &end3 );
				AddVertexToElements( iwVertexsFace.GetAt( i ), &addedElements2 );

				if ( iwVertexsUnnecessary ) iwVertexsUnnecessary->AddUnique( iwVertexsFace.GetAt( i ) );
				iwVertexsFace.RemoveAt( i );
				nVertexs--;
				i = -1;
			}
		}
	}

	if ( nVertexs < nVertexIni ) {
		if ( nVertexs > 2 ) {
			PBrep->CreatePolyFace( regions.GetAt( 0 ), shells.GetAt( 0 ), iwVertexsFace, newFace );
			if ( addedElements ) {
				AddFaceAndEdgesToElements( newFace, addedElements );
				RemoveFaceAndEdgesFromElements( iwFace, addedElements );
			}

			AddFaceAndEdgesToElements( newFace, &addedElements2 );
			UpdateEdgesAffected( &addedElements2, &iwIndexesRemovedEdges, &iwStartVertexRemovedEdges, &iwEndVertexRemovedEdges );

			UpdateCreaseEdgesAffected( &addedElements2, &indexes2, &start2, &end2 );
			UpdateCreaseEdgesAffectedFromDisolve( &addedElements2, &indexes3, &start3, &end3, &userlongs2, &values );
			RestoreCreaseEdgeInfo( &addedElements2, &userlongs2, &values );

		} else {
			if ( addedElements ) RemoveFaceAndEdgesFromElements( iwFace, addedElements );

			UpdateEdgesAffected( &addedElements2, &iwIndexesRemovedEdges, &iwStartVertexRemovedEdges, &iwEndVertexRemovedEdges );

			UpdateCreaseEdgesAffected( &addedElements2, &indexes2, &start2, &end2 );
			UpdateCreaseEdgesAffectedFromDisolve( &addedElements2, &indexes2, &start2, &end2, &userlongs2, &values );
			RestoreCreaseEdgeInfo( &addedElements2, &userlongs2, &values );
		}

		PBrep->DeletePolyFace( iwFace );

		if ( updateTopology ) UpdateTopology( OGLTransf );
	}
}

//------------------------------------------------------------------------------
// Se buscan los agujeros y ser rellenan con una cara
void TPBrepData::FillHoles( IwTA<IwPolyVertex *> *iwVertexsHoles, TAddedElements *addedElements )
{
	ULONG pos;
	int i, nEdges, nHole;
	bool keep;
	IwPolyEdge *iwEdge;
	IwPolyVertex *iwVertex;
	IwPolyFace *newFace;
	IwTA<IwPolyRegion *> regions;
	IwTA<IwPolyShell *> shells;
	IwTA<IwPolyVertex *> hole, faceHole;
	IwTA<IwPolyEdge *> boundaryEdges;

	if ( !PBrep ) return;
	PBrep->GetPolyRegions( regions );
	PBrep->GetPolyShells( shells );
	if ( regions.GetSize( ) == 0 || shells.GetSize( ) == 0 ) return;
	PBrep->GetBoundaryEdges( boundaryEdges );

	// Si pasamos lista de vertices, se filtran las aristas y nos quedamos solo las que tengan alguno de los vertices.
	if ( iwVertexsHoles && (int) iwVertexsHoles->GetSize( ) > 0 ) {
		nEdges = (int) boundaryEdges.GetSize( );
		for ( i = nEdges - 1; i >= 0; i-- ) {
			if ( !iwVertexsHoles->FindElement( boundaryEdges.GetAt( i )->GetStartVertex( ), pos ) || !iwVertexsHoles->FindElement( boundaryEdges.GetAt( i )->GetEndVertex( ), pos ) ) boundaryEdges.RemoveAt( i, 1 );
		}
	}

	nEdges = (int) boundaryEdges.GetSize( );
	while ( nEdges > 1 ) {
		iwEdge = boundaryEdges.GetAt( 0 );
		boundaryEdges.RemoveAt( 0, 1 );
		nEdges--;
		hole.RemoveAll( );
		iwVertex = iwEdge->GetStartVertex( );
		hole.Add( iwVertex );
		iwVertex = iwEdge->GetEndVertex( );
		hole.Add( iwVertex );

		keep = true;
		do {
			for ( i = 0; i < nEdges; i++ ) {
				iwEdge = boundaryEdges.GetAt( i );
				if ( iwEdge->GetStartVertex( ) == iwVertex ) break;
			}
			if ( i < nEdges ) {
				boundaryEdges.RemoveAt( i, 1 );
				nEdges--;
				if ( hole.FindElement( iwEdge->GetEndVertex( ), pos ) ) {
					faceHole.RemoveAll( );
					nHole = (int) hole.GetSize( );
					for ( i = pos; i < nHole; i++ )
						faceHole.Add( hole.GetAt( i ) );
					faceHole.ReverseArray( 0, faceHole.GetSize( ) );
					PBrep->CreatePolyFace( regions.GetAt( 0 ), shells.GetAt( 0 ), faceHole, newFace );

					if ( addedElements ) AddFaceAndEdgesToElements( newFace, addedElements );

					hole.RemoveAt( pos, nHole - pos );
					if ( hole.GetSize( ) > 0 ) iwVertex = hole.GetAt( hole.GetSize( ) - 1 );
					else
						keep = false;
				} else {
					iwVertex = iwEdge->GetEndVertex( );
					hole.Add( iwVertex );
				}
			} else
				keep = false;
		} while ( keep );
	}
}

//------------------------------------------------------------------------------

// Se añade a la estructura de elementos seleccionado una cara y su aristas
// Si se pasan iwVertex1 y iwVertex2 se considran las aristas desde iwVertex1 a iwVertex2 como nuevas
void TPBrepData::AddFaceAndEdgesToElements( IwPolyFace *iwFace, TAddedElements *elements, IwPolyVertex *iwVertex1, IwPolyVertex *iwVertex2 )
{
	ULONG pos;
	int i, pos1, pos2, nEdges;
	IwTA<IwPolyVertex *> iwVertexsFace;
	IwTA<IwPolyEdge *> iwEdgesFace;

	if ( !iwFace || !elements || ( iwVertex1 && !iwVertex2 ) || ( !iwVertex1 && iwVertex2 ) ) return;
	if ( iwVertex1 && iwVertex2 ) {
		iwFace->GetPolyVertices( iwVertexsFace );
		if ( !iwVertexsFace.FindElement( iwVertex1, pos ) || !iwVertexsFace.FindElement( iwVertex2, pos ) ) return;
	}

	elements->iwFaces.AddUnique( iwFace );
	iwFace->GetPolyEdges( iwEdgesFace );
	nEdges = (int) iwEdgesFace.GetSize( );
	if ( !iwVertex1 ) {
		for ( i = 0; i < nEdges; i++ )
			elements->iwEdges.AddUnique( iwEdgesFace.GetAt( i ) );
	} else if ( iwVertex1 == iwVertex2 ) {
		for ( i = 0; i < nEdges; i++ )
			elements->iwNewEdges.AddUnique( iwEdgesFace.GetAt( i ) );
	} else {
		for ( i = 0; i < nEdges; i++ ) {
			if ( iwEdgesFace.GetAt( i )->GetStartVertex( ) == iwVertex1 ) pos1 = i;
			if ( iwEdgesFace.GetAt( i )->GetEndVertex( ) == iwVertex2 ) pos2 = i;
		}
		if ( pos1 <= pos2 ) {
			for ( i = 0; i < pos1; i++ )
				elements->iwEdges.AddUnique( iwEdgesFace.GetAt( i ) );
			for ( i = pos1; i <= pos2; i++ )
				elements->iwNewEdges.AddUnique( iwEdgesFace.GetAt( i ) );
			for ( i = pos2 + 1; i < nEdges; i++ )
				elements->iwEdges.AddUnique( iwEdgesFace.GetAt( i ) );
		} else {
			for ( i = pos1; i < nEdges; i++ )
				elements->iwNewEdges.AddUnique( iwEdgesFace.GetAt( i ) );
			for ( i = 0; i <= pos2; i++ )
				elements->iwNewEdges.AddUnique( iwEdgesFace.GetAt( i ) );
			for ( i = pos2 + 1; i < pos1; i++ )
				elements->iwEdges.AddUnique( iwEdgesFace.GetAt( i ) );
		}
	}
}

//------------------------------------------------------------------------------

// Se añade a la estructura de elementos seleccionado una cara y su aristas
// Si se pasan iwVertex1 y iwVertex2 se considran las aristas desde iwVertex1 a iwVertex2 como nuevas
void TPBrepData::AddVertexToElements( IwPolyVertex *iwVertex, TAddedElements *elements )
{
	if ( !elements || !iwVertex ) return;

	elements->iwVertexs.AddUnique( iwVertex );
}

//------------------------------------------------------------------------------

// Se elimina de la estructura de elementos seleccionados una cara y su aristas
void TPBrepData::RemoveFaceAndEdgesFromElements( IwPolyFace *iwFace, TAddedElements *elements )
{
	ULONG pos;
	int i, nEdges;
	IwTA<IwPolyEdge *> iwEdgesFace;

	if ( !iwFace || !elements ) return;

	if ( elements->iwFaces.FindElement( iwFace, pos ) ) elements->iwFaces.RemoveAt( pos );
	iwFace->GetPolyEdges( iwEdgesFace );
	nEdges = (int) iwEdgesFace.GetSize( );
	for ( i = 0; i < nEdges; i++ ) {
		if ( elements->iwEdges.FindElement( iwEdgesFace.GetAt( i ), pos ) ) elements->iwEdges.RemoveAt( pos );
		if ( elements->iwNewEdges.FindElement( iwEdgesFace.GetAt( i ), pos ) ) elements->iwNewEdges.RemoveAt( pos );
	}
}

//------------------------------------------------------------------------------
// Se añade a las listas de ariastas afectadas aquellas cuyo userIndex2 sea distinto de cero y pertenecientes a las caras compartidas por el iwVertex
void TPBrepData::AddEdgesAffectedFromVertex( IwPolyVertex *iwVertex, IwTA<int> *iwIndexes, IwTA<IwPolyVertex *> *iwStartVertexs, IwTA<IwPolyVertex *> *iwEndVertexs )
{
	int i, nFaces;
	IwTA<IwPolyFace *> iwFacesVertex;

	if ( !iwVertex || !iwIndexes || !iwStartVertexs || !iwEndVertexs ) return;

	iwVertex->GetPolyFaces( iwFacesVertex );
	nFaces = (int) iwFacesVertex.GetSize( );
	for ( i = 0; i < nFaces; i++ )
		AddEdgesAffectedFromFace( iwFacesVertex.GetAt( i ), iwIndexes, iwStartVertexs, iwEndVertexs );
}

//------------------------------------------------------------------------------

// Se añade a las listas de ariastas afectadas aquellas cuyo userIndex2 sea distinto de cero y pertenecientes a las caras iwFace
void TPBrepData::AddEdgesAffectedFromFace( IwPolyFace *iwFace, IwTA<int> *iwIndexes, IwTA<IwPolyVertex *> *iwStartVertexs, IwTA<IwPolyVertex *> *iwEndVertexs )
{
	int i, nEdges, userIndex2;
	IwTA<IwPolyEdge *> iwEdgesFace;

	if ( !iwFace || !iwIndexes || !iwStartVertexs || !iwEndVertexs ) return;

	iwFace->GetPolyEdges( iwEdgesFace );
	nEdges = (int) iwEdgesFace.GetSize( );
	for ( i = 0; i < nEdges; i++ ) {
		userIndex2 = iwEdgesFace.GetAt( i )->GetUserIndex2( );
		if ( userIndex2 > 0 ) {
			iwIndexes->Add( userIndex2 );
			iwStartVertexs->Add( iwEdgesFace.GetAt( i )->GetStartVertex( ) );
			iwEndVertexs->Add( iwEdgesFace.GetAt( i )->GetEndVertex( ) );
		}
	}
}

//------------------------------------------------------------------------------

// Se actualizan los userIndex2 de las aristas añadidas
void TPBrepData::UpdateEdgesAffected( TAddedElements *addedElements, IwTA<int> *iwIndexes, IwTA<IwPolyVertex *> *iwStartVertexs, IwTA<IwPolyVertex *> *iwEndVertexs )
{
	ULONG pos;
	int i, j, k, nAddedEdges, nAffectedEdges, nAddedVertexs;
	IwPolyVertex *iwAddedVertex;
	IwPolyEdge *iwAddedEdge, *iwEdge1, *iwEdge2;
	IwTA<int> iwReplacedEdges;

	if ( !addedElements || !iwIndexes || !iwStartVertexs || !iwEndVertexs ) return;
	nAffectedEdges = (int) iwIndexes->GetSize( );
	if ( nAffectedEdges ) {
		// Buscamos las aristas que han sido sustituiadas al borrar una cara y crear otra.
		nAddedEdges = addedElements->iwEdges.GetSize( );
		for ( i = 0; i < nAddedEdges; i++ ) {
			for ( j = 0; j < nAffectedEdges; j++ ) {
				if ( addedElements->iwEdges.GetAt( i )->GetStartVertex( ) == iwStartVertexs->GetAt( j ) && addedElements->iwEdges.GetAt( i )->GetEndVertex( ) == iwEndVertexs->GetAt( j ) ) {
					addedElements->iwEdges.GetAt( i )->SetUserIndex2( iwIndexes->GetAt( j ) );
					iwReplacedEdges.AddUnique( iwIndexes->GetAt( j ) );
					break;
				}
			}
		}

		// Buscamos las aristas que han sido partidas al añadir un vértice
		nAddedVertexs = addedElements->iwVertexs.GetSize( );
		if ( nAddedVertexs > 0 ) {
			for ( i = 0; i < nAffectedEdges; i++ ) {
				if ( iwReplacedEdges.FindElement( iwIndexes->GetAt( i ), pos ) ) continue;
				iwEdge1 = iwEdge2 = 0;
				for ( j = 0; j < nAddedVertexs; j++ ) {
					iwAddedVertex = addedElements->iwVertexs.GetAt( j );
					for ( k = 0; k < nAddedEdges; k++ ) {
						iwAddedEdge = addedElements->iwEdges.GetAt( k );
						if ( iwAddedEdge->GetUserIndex2( ) > 0 ) continue;
						if ( iwAddedEdge->GetStartVertex( ) == iwStartVertexs->GetAt( i ) && iwAddedEdge->GetEndVertex( ) == iwAddedVertex ) iwEdge1 = iwAddedEdge;
						if ( iwAddedEdge->GetStartVertex( ) == iwAddedVertex && iwAddedEdge->GetEndVertex( ) == iwEndVertexs->GetAt( i ) ) iwEdge2 = iwAddedEdge;
						if ( iwEdge1 && iwEdge2 ) break;
					}
					if ( iwEdge1 && iwEdge2 ) {
						iwEdge1->SetUserIndex2( iwIndexes->GetAt( i ) );
						iwEdge2->SetUserIndex2( iwIndexes->GetAt( i ) );
						break;
					}
				}
			}
		}
	}
}

//------------------------------------------------------------------------------

// Se busca ordenar las caras en listas de caras conectadas
bool TPBrepData::GetFacesOrdered( IwTA<IwPolyFace *> *faces, IwTA<IwTA<IwPolyFace *> > *facesOrdered )
{
	bool founded;
	int i, j;
	IwPolyFace *faceAtStart, *faceAtEnd, *faceAux;
	IwTA<IwPolyFace *> facesAux, facesOrderedAux;
	IwTA<IwPolyEdge *> edges;

	if ( !faces || (int) faces->GetSize( ) == 0 || !facesOrdered ) return false;

	facesOrdered->RemoveAll( );
	facesAux.Copy( *faces );

	faceAtStart = NULL;
	// Si hay algun borde empezamos por ese borde al no tener simetrica
	for ( i = 0; i < (int) facesAux.GetSize( ); i++ ) {
		facesAux.GetAt( i )->GetPolyEdges( edges );
		for ( j = 0; j < (int) edges.GetSize( ); j++ ) {
			if ( edges[ j ]->IsBoundary( ) ) {
				faceAtStart = facesAux.GetAt( i );
				facesAux.RemoveAt( i );
				break;
			}
		}
		if ( faceAtStart ) break;
	}

	if ( !faceAtStart ) {
		faceAtStart = facesAux.GetAt( 0 );
		facesAux.RemoveAt( 0 );
	}
	facesOrderedAux.RemoveAll( );
	facesOrderedAux.Add( faceAtStart );
	if ( (int) ( *faces ).GetSize( ) == 1 ) {
		facesOrdered->Add( facesOrderedAux );
		return true;
	}

	faceAtEnd = faceAtStart;
	do {
		for ( i = 0; i < (int) facesAux.GetSize( ); i++ ) {
			founded = false;
			faceAux = facesAux.GetAt( i );
			if ( AreAdjacentFaces( faceAtStart, faceAux ) ) {
				facesOrderedAux.InsertAt( 0, faceAux );
				founded = true;
				// Habria que comprobar que no esten conectados con ninguna otra cara de la lista?? (excepto la ultima?). NO permitimos ramificaciones
				faceAtStart = faceAux;
			}
			if ( !founded && AreAdjacentFaces( faceAtEnd, faceAux ) ) {
				facesOrderedAux.Add( faceAux );
				founded = true;
				// Habria que comprobar que no esten conectados con ninguna otra cara de la lista?? (excepto la ultima?). NO permitimos ramificaciones
				faceAtEnd = faceAux;
			}
			if ( founded ) break;
		}

		// Si no ha encontrado conexion empezamos una nueva lista
		if ( !founded ) {
			facesOrdered->Add( facesOrderedAux );
			facesOrderedAux.RemoveAll( );
			faceAux = facesAux.GetAt( 0 );
			facesOrderedAux.Add( faceAux );
			faceAtEnd = faceAtStart = faceAux;
			facesAux.RemoveAt( 0 );
		} else {
			facesAux.RemoveAt( i );
		}
	} while ( facesAux.GetSize( ) > 0 );

	// Ultimo camino si lo hubiera
	if ( facesOrderedAux.GetSize( ) > 0 ) facesOrdered->Add( facesOrderedAux );

	return true;
}

//------------------------------------------------------------------------------

// Se busca ordenar las aristas en listas de aristas conectadas, ademas las aristas que se devuelven forman
// un camino orientado (todas apuntan en la misma direccion del camino )
bool TPBrepData::GetEdgesOrdered( IwTA<IwPolyEdge *> *edges, IwTA<IwTA<IwPolyEdge *> > *edgesOrdered )
{
	bool atStart, atStartAux, founded;
	int i, j;
	IwPolyEdge *edgeAtStart, *edgeAtEnd, *edgeAux, *edgeAuxSym;
	IwTA<IwPolyEdge *> edgesAux, edgesOrderedAux;

	if ( !edges || (int) edges->GetSize( ) == 0 || !edgesOrdered ) return false;

	edgesOrdered->RemoveAll( );
	edgesAux.Copy( *edges );

	edgeAtStart = NULL;
	// Si hay algun borde empezamos por ese borde al no tener simetrica
	for ( i = 0; i < (int) edgesAux.GetSize( ); i++ )
		if ( edgesAux.GetAt( i )->IsBoundary( ) ) {
			edgeAtStart = edgesAux.GetAt( i );
			edgesAux.RemoveAt( i );
			break;
		}

	if ( !edgeAtStart ) {
		edgeAtStart = edgesAux.GetAt( 0 );
		edgesAux.RemoveAt( 0 );
	}
	edgesOrderedAux.RemoveAll( );
	edgesOrderedAux.Add( edgeAtStart );
	if ( (int) ( *edges ).GetSize( ) == 1 ) {
		edgesOrdered->Add( edgesOrderedAux );
		return true;
	}

	edgeAtEnd = edgeAtStart;
	do {
		for ( i = 0; i < (int) edgesAux.GetSize( ); i++ ) {
			founded = false;
			edgeAux = edgesAux.GetAt( i );
			if ( AreAdjacentEdges( edgeAtStart, edgeAux, atStart ) ) {
				if ( atStart ) {
					// Antes de añadirla nueva arista comprobamos que siga el sentido del anterior
					if ( AreAdjacentEdges( edgeAux, edgeAtStart, atStartAux ) ) {
						if ( atStartAux ) {
							edgeAuxSym = edgeAux->GetSymmetricPolyEdge( );
							if ( edgeAuxSym ) edgeAux = edgeAuxSym;
						}
					}
					edgesOrderedAux.InsertAt( 0, edgeAux );
					founded = true;
					// Comprobamos que no esten conectados con ninguna otra arista de la lista. NO permitimos ramificaciones
					for ( j = 0; j < (int) edgesAux.GetSize( ); j++ ) {
						if ( j == i ) continue;
						if ( AreAdjacentEdges( edgeAtStart, edgesAux[ j ], atStartAux ) ) {
							if ( atStart == atStartAux ) return false;
						}
					}
					edgeAtStart = edgeAux;
				}
			}
			if ( !founded && AreAdjacentEdges( edgeAtEnd, edgeAux, atStart ) ) {
				if ( !atStart ) {
					if ( AreAdjacentEdges( edgeAux, edgeAtEnd, atStartAux ) ) {
						if ( !atStartAux ) {
							edgeAuxSym = edgeAux->GetSymmetricPolyEdge( );
							if ( edgeAuxSym ) edgeAux = edgeAuxSym;
						}
					}
					edgesOrderedAux.Add( edgeAux );
					founded = true;
					// Comprobamos que no esten conectados con ninguna otra arista de la lista. NO permitimos ramificaciones
					for ( j = 0; j < (int) edgesAux.GetSize( ); j++ ) {
						if ( j == i ) continue;
						if ( AreAdjacentEdges( edgeAtEnd, edgesAux[ j ], atStartAux ) ) {
							if ( atStart == atStartAux ) return false;
						}
					}
					edgeAtEnd = edgeAux;
				}
			}
			if ( founded ) break;
		}

		// Si no ha encontrado conexion empezamos una nueva lista
		if ( !founded ) {
			edgesOrdered->Add( edgesOrderedAux );
			edgesOrderedAux.RemoveAll( );
			edgeAux = edgesAux.GetAt( 0 );
			edgesOrderedAux.Add( edgeAux );
			edgeAtEnd = edgeAtStart = edgeAux;
			edgesAux.RemoveAt( 0 );
		} else {
			edgesAux.RemoveAt( i );
		}
	} while ( edgesAux.GetSize( ) > 0 );

	// Ultimo camino si lo hubiera
	if ( edgesOrderedAux.GetSize( ) > 0 ) edgesOrdered->Add( edgesOrderedAux );

	return true;
}

//------------------------------------------------------------------------------

// Se ordena un conjunto de aristas por su continuidad.
// Devuelve true cuando todas formen un camino, que ha de ser cerrado segun el valor forceClose
bool TPBrepData::OrderEdgesFace( IwTA<IwPolyEdge *> *iwEdgesFace, bool forceClose )
{
	int i, j, iniEdge, nEdges;
	IwPolyEdge *iwEdge;
	IwTA<IwPolyVertex *> iwVertexFace;
	IwTA<IwPolyEdge *> iwEdgesFaceAux, iwEdgesOrdered;

	if ( !iwEdgesFace ) return false;
	nEdges = (int) iwEdgesFace->GetSize( );
	if ( nEdges < 2 ) return false;

	iwEdgesFaceAux.Copy( *iwEdgesFace );
	iniEdge = 0;
	if ( !forceClose ) {
		// Buscamos empezar por una arista cuyo vertice inicial no sea vertice final de otra arista.
		// Si no empezamos por la primera
		for ( i = 0; i < nEdges; i++ ) {
			for ( j = 0; j < nEdges; j++ ) {
				if ( i == j ) continue;
				if ( iwEdgesFaceAux.GetAt( i )->GetStartVertex( ) == iwEdgesFaceAux.GetAt( j )->GetEndVertex( ) ) break;
			}
			if ( j == nEdges ) {
				iniEdge = i;
				break;
			}
		}
	}

	iwEdge = iwEdgesFaceAux.GetAt( iniEdge );
	iwEdgesOrdered.Add( iwEdge );
	iwEdgesFaceAux.RemoveAt( iniEdge );
	nEdges--;

	for ( i = 0; i < nEdges; i++ ) {
		if ( iwEdge->GetEndVertex( ) == iwEdgesFaceAux.GetAt( i )->GetStartVertex( ) ) {
			iwEdge = iwEdgesFaceAux.GetAt( i );
			iwEdgesOrdered.Add( iwEdge );
			iwEdgesFaceAux.RemoveAt( i );
			nEdges--;
			i = -1;
		}
	}
	if ( nEdges > 0 ) return false;

	// Comprobamos que no se repitan los vertices
	nEdges = (int) iwEdgesOrdered.GetSize( );
	for ( i = 0; i < nEdges; i++ )
		iwVertexFace.AddUnique( iwEdgesOrdered.GetAt( i )->GetStartVertex( ) );
	if ( (int) iwVertexFace.GetSize( ) != nEdges ) return false;

	if ( forceClose && iwEdgesOrdered.GetAt( 0 )->GetStartVertex( ) != iwEdge->GetEndVertex( ) ) return false;

	iwEdgesFace->RemoveAll( );
	iwEdgesFace->Copy( iwEdgesOrdered );
	return true;
}

//------------------------------------------------------------------------------

// Se obtiene una lista de aristas resultante de eliminar una arista y unificar las dos caras que la comparten.
// Se intentan ordenar para formar una cara con todas, devolviendose true cuando se pueda.
bool TPBrepData::GetOrderedEdgesNewFaceFromRemoveEdge( IwPolyEdge *iwEdge, IwTA<IwPolyEdge *> *iwEdgesNewFace )
{
	ULONG pos;
	int i, nEdges;
	IwPolyEdge *iwSymmetricEdge;
	IwPolyFace *iwFace, *iwSymmetricFace;
	IwTA<IwPolyEdge *> iwEdgesFace;

	if ( !iwEdge || !iwEdgesNewFace ) return false;

	iwSymmetricEdge = iwEdge->GetSymmetricPolyEdge( );
	if ( !iwSymmetricEdge ) return false;
	iwFace = iwEdge->GetPolyFace( );
	iwSymmetricFace = iwSymmetricEdge->GetPolyFace( );

	iwFace->GetPolyEdges( iwEdgesFace );
	iwEdgesNewFace->Append( iwEdgesFace );
	iwSymmetricFace->GetPolyEdges( iwEdgesFace );
	iwEdgesNewFace->Append( iwEdgesFace );
	nEdges = (int) iwEdgesNewFace->GetSize( );
	for ( i = 0; i < nEdges; i++ ) {
		iwSymmetricEdge = iwEdgesNewFace->GetAt( i )->GetSymmetricPolyEdge( );
		if ( iwSymmetricEdge && iwEdgesNewFace->FindElement( iwSymmetricEdge, pos ) ) {
			iwEdgesNewFace->RemoveAt( pos );
			iwEdgesNewFace->RemoveAt( i );
			nEdges -= 2;
			i--;
		}
	}

	return OrderEdgesFace( iwEdgesNewFace );
}

//------------------------------------------------------------------------------

// Devuelve la arista de iwFace1 cuya simetrica está en iwFace2
IwPolyEdge *TPBrepData::GetEdgeBetweenFaces( IwPolyFace *iwFace1, IwPolyFace *iwFace2 )
{
	ULONG pos;
	int i, nEdgesFace1;

	IwPolyEdge *iwEdge, *iwSymmetricEdge;
	IwTA<IwPolyEdge *> iwEdgesFace1, iwEdgesFace2;

	if ( !PBrep || !iwFace1 || !iwFace2 ) return 0;

	iwFace1->GetPolyEdges( iwEdgesFace1 );
	nEdgesFace1 = (int) iwEdgesFace1.GetSize( );
	iwFace2->GetPolyEdges( iwEdgesFace2 );

	for ( i = 0; i < nEdgesFace1; i++ ) {
		iwEdge = iwEdgesFace1.GetAt( i );
		iwSymmetricEdge = iwEdge->GetSymmetricPolyEdge( );
		if ( iwSymmetricEdge && iwEdgesFace2.FindElement( iwSymmetricEdge, pos ) ) return iwEdge;
	}

	return 0;
}

//------------------------------------------------------------------------------

// Actualiza la topología
void TPBrepData::UpdateTopology( TOGLTransf *OGLTransf )
{
	TOGLPolygonList *polList;

	if ( !OGLTransf ) return;
	if ( !RefEnt ) return;

	if ( !CreatePBrepArrays( ) ) {
		RefEnt->ClearOGLLists( );
		return;
	}

	RefEnt->UpdateOGLListFromPBrep( OGLTransf, false, true, false, true );
	RefEnt->SetPolygonDirty( true );
	RefEnt->SetPBrepDirty( false );
	if ( RefEnt->GetOGLRenderData( )->CountColors( ) ) {
		polList = RefEnt->GetOGLList( OGLTransf );
		RefEnt->GetOGLRenderData( )->SetColors( polList );
		RefEnt->Download( );
		// No se actualizan los colores de las caras de la subdividida pq se hace en el CalOGLPolygon, si se hace aqui peta
		UnSelectAllFaces( OGLTransf, SelectedElementType::All, 0.0, false, true );
	}
	SetTopologyDirty( true );
}

//------------------------------------------------------------------------------

// Actualiza la informacion de los pliegues
void TPBrepData::UpdateDataSubdivision( TOGLTransf *OGLTransf )
{
	if ( !OGLTransf ) return;
	if ( !RefEnt ) return;

	RefEnt->SetPolygonDirty( true );
	RefEnt->SetPBrepDirty( false );
	SetDataSubdivisionDirty( OGLTransf, true );
}

//------------------------------------------------------------------------------

// Se inicializan los valores UserIndex2 a cero
void TPBrepData::InitUserIndex1( bool vertexs, bool faces )
{
	int i, count;
	IwTA<IwPolyVertex *> iwVertexs;
	IwTA<IwPolyEdge *> iwEdges;
	IwTA<IwPolyFace *> iwFaces;

	if ( !PBrep ) return;

	if ( vertexs ) {
		PBrep->GetPolyVertices( iwVertexs );
		count = (int) iwVertexs.GetSize( );
		for ( i = 0; i < count; i++ )
			iwVertexs.GetAt( i )->SetUserIndex1( 0 );
	}

	if ( faces ) {
		PBrep->GetPolyFaces( iwFaces );
		count = (int) iwFaces.GetSize( );
		for ( i = 0; i < count; i++ )
			iwFaces.GetAt( i )->SetUserIndex1( 0 );
	}
}

//------------------------------------------------------------------------------

void TPBrepData::GetListsUserIndex1( TInteger_List *vertexsList, TInteger_List *facesList )
{
	int i, count, value;
	IwTA<IwPolyVertex *> iwVertexs;
	IwTA<IwPolyEdge *> iwEdges;
	IwTA<IwPolyFace *> iwFaces;

	if ( !PBrep ) return;

	if ( vertexsList ) {
		vertexsList->Clear( );
		PBrep->GetPolyVertices( iwVertexs );
		count = (int) iwVertexs.GetSize( );
		for ( i = 0; i < count; i++ ) {
			value = (int) iwVertexs.GetAt( i )->GetUserIndex1( );
			vertexsList->AddItem( &value );
		}
	}

	if ( facesList ) {
		facesList->Clear( );
		PBrep->GetPolyFaces( iwFaces );
		count = (int) iwFaces.GetSize( );
		for ( i = 0; i < count; i++ ) {
			value = (int) iwFaces.GetAt( i )->GetUserIndex1( );
			facesList->AddItem( &value );
		}
	}
}

//------------------------------------------------------------------------------

void TPBrepData::SetListsUserIndex1( TInteger_List *vertexsList, TInteger_List *facesList )
{
	int i, count, value;
	IwTA<IwPolyVertex *> iwVertexs;
	IwTA<IwPolyEdge *> iwEdges;
	IwTA<IwPolyFace *> iwFaces;

	if ( !PBrep ) return;

	if ( vertexsList ) {
		count = vertexsList->Count( );
		PBrep->GetPolyVertices( iwVertexs );
		if ( count == (int) iwVertexs.GetSize( ) ) {
			for ( i = 0; i < count; i++ ) {
				value = (int) ( *vertexsList->GetItem( i ) );
				iwVertexs.GetAt( i )->SetUserIndex1( value );
			}
		}
	}

	if ( facesList ) {
		count = facesList->Count( );
		PBrep->GetPolyFaces( iwFaces );
		if ( count == (int) iwFaces.GetSize( ) ) {
			for ( i = 0; i < count; i++ ) {
				value = (int) ( *facesList->GetItem( i ) );
				iwFaces.GetAt( i )->SetUserIndex1( value );
			}
		}
	}
}

//------------------------------------------------------------------------------

// Se inicializan los valores UserIndex2 a cero
void TPBrepData::InitUserIndex2( bool vertexs, bool edges, bool faces )
{
	int i, count;
	IwTA<IwPolyVertex *> iwVertexs;
	IwTA<IwPolyEdge *> iwEdges;
	IwTA<IwPolyFace *> iwFaces;

	if ( !PBrep ) return;

	if ( vertexs ) {
		PBrep->GetPolyVertices( iwVertexs );
		count = (int) iwVertexs.GetSize( );
		for ( i = 0; i < count; i++ )
			iwVertexs.GetAt( i )->SetUserIndex2( 0 );
	}

	if ( edges ) {
		PBrep->GetPolyEdges( iwEdges );
		count = (int) iwEdges.GetSize( );
		for ( i = 0; i < count; i++ )
			iwEdges.GetAt( i )->SetUserIndex2( 0 );
	}

	if ( faces ) {
		PBrep->GetPolyFaces( iwFaces );
		count = (int) iwFaces.GetSize( );
		for ( i = 0; i < count; i++ )
			iwFaces.GetAt( i )->SetUserIndex2( 0 );
	}
}

//------------------------------------------------------------------------------

void TPBrepData::GetListsUserIndex2( TInteger_List *vertexsList, TInteger_List *edgesList, TInteger_List *facesList )
{
	int i, count, value;
	IwTA<IwPolyVertex *> iwVertexs;
	IwTA<IwPolyEdge *> iwEdges;
	IwTA<IwPolyFace *> iwFaces;

	if ( !PBrep ) return;

	if ( vertexsList ) {
		vertexsList->Clear( );
		PBrep->GetPolyVertices( iwVertexs );
		count = (int) iwVertexs.GetSize( );
		for ( i = 0; i < count; i++ ) {
			value = (int) iwVertexs.GetAt( i )->GetUserIndex2( );
			vertexsList->AddItem( &value );
		}
	}

	if ( edgesList ) {
		edgesList->Clear( );
		PBrep->GetPolyEdges( iwEdges );
		count = (int) iwEdges.GetSize( );
		for ( i = 0; i < count; i++ ) {
			value = (int) iwEdges.GetAt( i )->GetUserIndex2( );
			edgesList->AddItem( &value );
		}
	}

	if ( facesList ) {
		facesList->Clear( );
		PBrep->GetPolyFaces( iwFaces );
		count = (int) iwFaces.GetSize( );
		for ( i = 0; i < count; i++ ) {
			value = (int) iwFaces.GetAt( i )->GetUserIndex2( );
			facesList->AddItem( &value );
		}
	}
}

//------------------------------------------------------------------------------

void TPBrepData::SetListsUserIndex2( TInteger_List *vertexsList, TInteger_List *edgesList, TInteger_List *facesList )
{
	int i, count, value;
	IwTA<IwPolyVertex *> iwVertexs;
	IwTA<IwPolyEdge *> iwEdges;
	IwTA<IwPolyFace *> iwFaces;

	if ( !PBrep ) return;

	if ( vertexsList ) {
		count = vertexsList->Count( );
		PBrep->GetPolyVertices( iwVertexs );
		if ( count == (int) iwVertexs.GetSize( ) ) {
			for ( i = 0; i < count; i++ ) {
				value = (int) ( *vertexsList->GetItem( i ) );
				iwVertexs.GetAt( i )->SetUserIndex2( value );
			}
		}
	}

	if ( edgesList ) {
		count = edgesList->Count( );
		PBrep->GetPolyEdges( iwEdges );
		if ( count == (int) iwEdges.GetSize( ) ) {
			for ( i = 0; i < count; i++ ) {
				value = (int) ( *edgesList->GetItem( i ) );
				iwEdges.GetAt( i )->SetUserIndex2( value );
			}
		}
	}

	if ( facesList ) {
		count = facesList->Count( );
		PBrep->GetPolyFaces( iwFaces );
		if ( count == (int) iwFaces.GetSize( ) ) {
			for ( i = 0; i < count; i++ ) {
				value = (int) ( *facesList->GetItem( i ) );
				iwFaces.GetAt( i )->SetUserIndex2( value );
			}
		}
	}
}

//------------------------------------------------------------------------------

// Se devuelve el mayor valor UserLong2 usado en las aristas
ULONG TPBrepData::GetMaxEdgeUserLong2( )
{
	ULONG userLong2, maxUserLong2;
	int i, count;
	IwTA<IwPolyEdge *> iwEdges;

	if ( !PBrep ) return 0;

	PBrep->GetPolyEdges( iwEdges );
	count = (int) iwEdges.GetSize( );
	maxUserLong2 = 0;
	for ( i = 0; i < count; i++ ) {
		userLong2 = iwEdges.GetAt( i )->GetUserLong2( );
		if ( userLong2 > maxUserLong2 ) maxUserLong2 = userLong2;
	}

	return maxUserLong2;
}

//------------------------------------------------------------------------------

// Se inicializan los valores UserLong2 a cero
void TPBrepData::InitUserLong2( )
{
	int i, count;
	IwTA<IwPolyEdge *> iwEdges;

	if ( !PBrep ) return;

	PBrep->GetPolyEdges( iwEdges );
	count = (int) iwEdges.GetSize( );
	for ( i = 0; i < count; i++ )
		iwEdges.GetAt( i )->SetUserLong2( 0 );
}

//------------------------------------------------------------------------------

// Se devuelve el mayor valor UserIndex2 usado en las aristas
ULONG TPBrepData::GetMaxEdgeUserIndex2( )
{
	ULONG userIndex2, maxUserIndex2;
	int i, count;
	IwTA<IwPolyEdge *> iwEdges;

	if ( !PBrep ) return 0;

	PBrep->GetPolyEdges( iwEdges );
	count = (int) iwEdges.GetSize( );
	maxUserIndex2 = 0;
	for ( i = 0; i < count; i++ ) {
		userIndex2 = iwEdges.GetAt( i )->GetUserIndex2( );
		if ( userIndex2 > maxUserIndex2 ) maxUserIndex2 = userIndex2;
	}

	return maxUserIndex2;
}

//------------------------------------------------------------------------------

// Se inicializan a cero los valores UserIndex2 de las aristas a partir del valor especificado en limit
void TPBrepData::InitEdgeUserIndex2( ULONG limit )
{
	ULONG userIndex2;
	int i, count;
	IwTA<IwPolyEdge *> iwEdges;

	if ( !PBrep ) return;

	PBrep->GetPolyEdges( iwEdges );
	count = (int) iwEdges.GetSize( );
	for ( i = 0; i < count; i++ ) {
		userIndex2 = iwEdges.GetAt( i )->GetUserIndex2( );
		if ( userIndex2 > limit ) iwEdges.GetAt( i )->SetUserIndex2( 0 );
	}
}
// =============================================================================
// TPBrepData - Partición de aristas y caras
// =============================================================================
//------------------------------------------------------------------------------

// Partir aristas seleccionadas por su centro.
void TPBrepData::SplitSelectedEdges( TOGLTransf *OGLTransf, bool updateTopology )
{
	int i, nEdges;
	IwPolyEdge *iwSymmetricEdge;
	IwTA<IwPolyEdge *> iwEdges, iwEdgesToSplit;

	if ( !PBrep || !OGLTransf ) return;

	// Obtenemos lista de aristas a partir
	nEdges = (int) PBrepEdges.GetSize( );
	for ( i = 0; i < nEdges; i++ ) {
		if ( SelectedE[ i ] ) {
			iwEdgesToSplit.AddUnique( PBrepEdges.GetAt( i ) );
			iwSymmetricEdge = PBrepEdges.GetAt( i )->GetSymmetricPolyEdge( );
			if ( iwSymmetricEdge ) iwEdgesToSplit.AddUnique( iwSymmetricEdge );
		}
	}

	// Partimos
	SplitEdges( OGLTransf, &iwEdgesToSplit, 0, 0, false, false );

	if ( updateTopology ) UpdateTopology( OGLTransf );
}

//------------------------------------------------------------------------------

// Partir una lista de aristas por una lista de puntos. Si ésta es vacia se parten las aritstas por la mitad
// Si updateTopology se pasa a false, es responsabilidad del que llama a la función de restaurar la PolygonList y los colores poseriormente
void TPBrepData::SplitEdges( TOGLTransf *OGLTransf, IwTA<IwPolyEdge *> *iwEdgesToSplit, IwTA<T3DPoint> *points, TAddedElements *addedElements, bool splitSimetric, bool updateTopology )
{
	ULONG pos, userIndex2, maxUserIndex2;
	int i, j, nEdges, nAddedEdges;
	T3DPoint pt3d;
	IwPolyEdge *iwEdge;
	IwTA<IwPolyEdge *> iwEdges;
	TAddedElements addedElementsAux;

	if ( !PBrep || !OGLTransf || !iwEdgesToSplit ) return;
	if ( points && points->GetSize( ) != iwEdgesToSplit->GetSize( ) ) return;

	// Si hay que partir los simétricos nos aseguramos que no hay ninguno incluido en la lista inicial.
	nEdges = (int) iwEdgesToSplit->GetSize( );
	if ( splitSimetric ) {
		for ( i = 0; i < nEdges; i++ ) {
			iwEdge = iwEdgesToSplit->GetAt( i )->GetSymmetricPolyEdge( );
			if ( iwEdgesToSplit->FindElement( iwEdge, pos ) ) {
				iwEdgesToSplit->RemoveAt( pos );
				nEdges--;
			}
		}
	}
	if ( nEdges == 0 ) return;

	// Partimos
	maxUserIndex2 = GetMaxEdgeUserIndex2( );
	for ( i = 0; i < nEdges; i++ )
		iwEdgesToSplit->GetAt( i )->SetUserIndex2( maxUserIndex2 + i + 1 );
	for ( i = 0; i < nEdges; i++ ) {
		iwEdge = iwEdgesToSplit->GetAt( i );
		PBrep->GetPolyEdges( iwEdges );
		if ( !iwEdges.FindElement( iwEdge, pos ) ) continue;
		if ( !addedElements ) InitAddedElements( &addedElementsAux );
		if ( points ) {
			pt3d.Set( &( points->GetAt( i ) ) );
			SplitEdge( OGLTransf, iwEdgesToSplit->GetAt( i ), &pt3d, addedElements ? addedElements : &addedElementsAux, splitSimetric, false );
		} else
			SplitEdge( OGLTransf, iwEdge, 0, addedElements ? addedElements : &addedElementsAux, splitSimetric, false );
		nAddedEdges = addedElements ? (int) addedElements->iwEdges.GetSize( ) : (int) addedElementsAux.iwEdges.GetSize( );
		for ( j = 0; j < nAddedEdges; j++ ) {
			iwEdge = addedElements ? addedElements->iwEdges.GetAt( j ) : addedElementsAux.iwEdges.GetAt( j );
			userIndex2 = iwEdge->GetUserIndex2( );
			if ( userIndex2 > maxUserIndex2 ) iwEdgesToSplit->SetAt( userIndex2 - maxUserIndex2 - 1, iwEdge );
		}
	}
	InitEdgeUserIndex2( maxUserIndex2 );

	if ( updateTopology ) UpdateTopology( OGLTransf );
}

//------------------------------------------------------------------------------

void TPBrepData::SplitEdge( TOGLTransf *OGLTransf, int index, T3DPoint *point, TAddedElements *addedElements, bool splitSimetric, bool updateTopology )
{
	IwPolyEdge *iwEdge;

	if ( !PBrep || !OGLTransf || index < 0 || !point ) return;

	iwEdge = GetPBrepEdge( OGLTransf, index );
	if ( !iwEdge ) return;
	SplitEdge( OGLTransf, iwEdge, point, addedElements, splitSimetric, updateTopology );
}

//------------------------------------------------------------------------------

// Partir arista por un punto. Si no se pasa un punto se parte por la mitad

void TPBrepData::SplitEdge( TOGLTransf *OGLTransf, IwPolyEdge *iwEdge, T3DPoint *point, TAddedElements *addedElements, bool splitSimetric, bool updateTopology )
{
	TAddedElements *addedElements2, addedElements3;
	T3DPoint pt3d;
	IwVector3d iwVector3d;
	IwPoint3d iwPoint;
	IwPolyVertex *newVertex;
	IwPolyEdge *iwSymmetricEdge;
	IwPolyFace *iwFace, *iwSymmetricFace;
	IwTA<IwPolyRegion *> regions;
	IwTA<IwPolyShell *> shells;
	IwTA<int> iwIndexesRemovedEdges;
	IwTA<ULONG> indexes2;
	IwTA<IwPolyVertex *> iwStartVertexRemovedEdges, iwEndVertexRemovedEdges, start2, end2;

	if ( !PBrep || !iwEdge ) return;
	PBrep->GetPolyRegions( regions );
	PBrep->GetPolyShells( shells );
	if ( regions.GetSize( ) == 0 || shells.GetSize( ) == 0 ) return;

	if ( addedElements ) addedElements2 = addedElements;
	else
		addedElements2 = &addedElements3;

	if ( point ) {
		iwVector3d = iwEdge->GetStartPoint( );
		pt3d = T3DPoint( iwVector3d.x, iwVector3d.y, iwVector3d.z );
		if ( point->Similar( pt3d ) ) return;
		iwVector3d = iwEdge->GetEndPoint( );
		pt3d = T3DPoint( iwVector3d.x, iwVector3d.y, iwVector3d.z );
		if ( point->Similar( pt3d ) ) return;
		iwPoint.x = point->x;
		iwPoint.y = point->y;
		iwPoint.z = point->z;
	} else
		iwPoint = ( iwEdge->GetStartPoint( ) + iwEdge->GetEndPoint( ) ) / 2.0;

	newVertex = FindVertex( &iwPoint );
	if ( !newVertex ) newVertex = new IwPolyVertex( _GetSMLib( )->GetContext( ), *PBrep, iwPoint, RES_COMP );

	iwFace = iwEdge->GetPolyFace( );
	if ( splitSimetric ) {
		iwSymmetricEdge = iwEdge->GetSymmetricPolyEdge( );
		iwSymmetricFace = iwSymmetricEdge ? iwSymmetricEdge->GetPolyFace( ) : 0;
	} else {
		iwSymmetricEdge = 0;
		iwSymmetricFace = 0;
	}

	if ( addedElements2 ) {
		addedElements2->iwVertexs.AddUnique( newVertex );
		AddEdgesAffectedFromFace( iwFace, &iwIndexesRemovedEdges, &iwStartVertexRemovedEdges, &iwEndVertexRemovedEdges );
		AddCreaseEdgesAffectedFromFace( iwFace, &indexes2, &start2, &end2 );
		RemoveFaceAndEdgesFromElements( iwFace, addedElements2 );
		if ( iwSymmetricFace ) {
			AddEdgesAffectedFromFace( iwSymmetricFace, &iwIndexesRemovedEdges, &iwStartVertexRemovedEdges, &iwEndVertexRemovedEdges );
			AddCreaseEdgesAffectedFromFace( iwSymmetricFace, &indexes2, &start2, &end2 );
			RemoveFaceAndEdgesFromElements( iwSymmetricFace, addedElements2 );
		}
	}

	SplitFace( OGLTransf, iwFace, iwEdge, newVertex, addedElements2, false );
	if ( splitSimetric && iwSymmetricFace && iwSymmetricEdge ) SplitFace( OGLTransf, iwSymmetricFace, iwSymmetricEdge, newVertex, addedElements2, false );

	if ( addedElements2 ) {
		UpdateEdgesAffected( addedElements2, &iwIndexesRemovedEdges, &iwStartVertexRemovedEdges, &iwEndVertexRemovedEdges );
		UpdateCreaseEdgesAffected( addedElements2, &indexes2, &start2, &end2 );
	}

	if ( updateTopology ) UpdateTopology( OGLTransf );
}

//------------------------------------------------------------------------------

// Partir las caras seleccionadas por su punto central, aplicando el offset si es distinto de 0
// Offset limitado a +-20.0
// Si updateTopology se pasa a false, es responsabilidad del que llama a la función de restaurar la PolygonList y los colores poseriormente
void TPBrepData::SplitSelectedFaces( TOGLTransf *OGLTransf, double offset, bool updateTopology )
{
	int nFaces, i;

	if ( !PBrep || !OGLTransf || offset < -20.0 || offset > 20.0 ) return;

	nFaces = (int) PBrepFaces.GetSize( );
	for ( i = 0; i < nFaces; i++ ) {
		if ( SelectedF[ i ].i > 0 ) SplitFace( OGLTransf, PBrepFaces.GetAt( i ), 0, offset, 0, false );
	}

	if ( updateTopology ) UpdateTopology( OGLTransf );
}

//------------------------------------------------------------------------------

// Partir lista de caras
// Si updateTopology se pasa a false, es responsabilidad del que llama a la función de restaurar la PolygonList y los colores poseriormente
void TPBrepData::SplitFaces( TOGLTransf *OGLTransf, IwTA<IwPolyFace *> *iwFaces, IwTA<T3DPoint> *points, IwTA<double> *offsets, TAddedElements *addedElements, bool updateTopology )
{
	int nFaces, i;
	double offset;
	T3DPoint pt3d;

	if ( !PBrep || !OGLTransf || !iwFaces ) return;
	nFaces = (int) PBrepFaces.GetSize( );
	if ( points && (int) points->GetSize( ) != nFaces ) return;
	if ( offsets && (int) offsets->GetSize( ) != nFaces ) return;

	offset = 0.0;
	for ( i = 0; i < nFaces; i++ ) {
		if ( points ) pt3d.Set( &( points->GetAt( i ) ) );
		if ( offsets ) offset = offsets->GetAt( i );
		SplitFace( OGLTransf, PBrepFaces.GetAt( i ), points ? &pt3d : 0, offset, addedElements, false );
	}

	if ( updateTopology ) UpdateTopology( OGLTransf );
}

//------------------------------------------------------------------------------

// Partir cara por un punto a partir de su índice
void TPBrepData::SplitFace( TOGLTransf *OGLTransf, int index, T3DPoint *point, double offset, TAddedElements *addedElements, bool updateTopology )
{
	IwPolyFace *iwFace;

	if ( !PBrep || !OGLTransf || index < 0 || !point ) return;
	iwFace = GetPBrepFace( OGLTransf, index );
	if ( !iwFace ) return;
	SplitFace( OGLTransf, iwFace, point, offset, addedElements, updateTopology );
}

//------------------------------------------------------------------------------

// Partir cara por un punto aplicando un offset si es distinto de 0.
// Si no se pasa el punto se hace por el centroide

void TPBrepData::SplitFace( TOGLTransf *OGLTransf, IwPolyFace *iwFace, T3DPoint *point, double offset, TAddedElements *addedElements, bool updateTopology )
{
	int nVertexs, i, userIndex2, nEdges;
	T3DPoint pt3d;
	T3DVector vec;
	TNTraslationMatrix tMatrix;
	IwPoint3d iwNewPoint3d;
	IwVector3d iwVector;
	IwPolyVertex *newVertex;
	IwPolyFace *newFace;
	IwTA<IwPolyVertex *> iwVertexsFace, iwVertexsNewFace;
	IwTA<IwPolyRegion *> regions;
	IwTA<IwPolyShell *> shells;
	IwTA<int> iwIndexesRemovedEdges;
	IwTA<ULONG> indexes2;
	IwTA<IwPolyVertex *> iwStartVertexRemovedEdges, iwEndVertexRemovedEdges, start2, end2;
	IwTA<int> userlongs2;
	IwTA<float> values;
	IwTA<IwPolyEdge *> edges;
	TAddedElements *addedElements2, addedElements3;

	if ( !PBrep || !OGLTransf || !iwFace || offset < -20.0 || offset > 20.0 ) return;
	PBrep->GetPolyRegions( regions );
	PBrep->GetPolyShells( shells );
	if ( regions.GetSize( ) == 0 || shells.GetSize( ) == 0 ) return;

	if ( addedElements ) addedElements2 = addedElements;
	else
		addedElements2 = &addedElements3;

	if ( !point ) {
		iwVector = iwFace->GetCentroid( );
		pt3d = T3DPoint( iwVector.x, iwVector.y, iwVector.z );
	} else
		pt3d.Set( point );

	if ( offset != 0 ) {
		iwVector = iwFace->GetNormal( );
		vec = T3DVector( T3DSize( iwVector.x * offset, iwVector.y * offset, iwVector.z * offset ) );
		tMatrix = TNTraslationMatrix( vec );
		pt3d.ApplyMatrix( tMatrix );
	}

	InitUserLong2( );

	iwFace->GetPolyEdges( edges );
	nEdges = (int) edges.GetSize( );
	for ( i = 0; i < nEdges; i++ ) {
		SaveCreaseEdgeInfo( edges[ i ], &userlongs2, &values );
		SaveCreaseEdgeInfo( edges[ i ]->GetSymmetricPolyEdge( ), &userlongs2, &values );
	}

	if ( addedElements2 ) {
		userIndex2 = iwFace->GetUserIndex2( );
		AddEdgesAffectedFromFace( iwFace, &iwIndexesRemovedEdges, &iwStartVertexRemovedEdges, &iwEndVertexRemovedEdges );
		AddCreaseEdgesAffectedFromFace( iwFace, &indexes2, &start2, &end2 );
	}

	iwNewPoint3d.Set( pt3d.x, pt3d.y, pt3d.z );
	newVertex = new IwPolyVertex( _GetSMLib( )->GetContext( ), *PBrep, iwNewPoint3d, RES_COMP );
	if ( addedElements2 ) addedElements2->iwVertexs.AddUnique( newVertex );

	iwFace->GetPolyVertices( iwVertexsFace );
	nVertexs = (int) iwVertexsFace.GetSize( );
	for ( i = 0; i < nVertexs; i++ ) {
		iwVertexsNewFace.Add( iwVertexsFace.GetAt( i ) );
		iwVertexsNewFace.Add( iwVertexsFace.GetAt( ( i + 1 ) % nVertexs ) );
		iwVertexsNewFace.Add( newVertex );
		PBrep->CreatePolyFace( regions.GetAt( 0 ), shells.GetAt( 0 ), iwVertexsNewFace, newFace );
		if ( addedElements2 ) {
			newFace->SetUserIndex2( userIndex2 );
			AddFaceAndEdgesToElements( newFace, addedElements2, iwVertexsFace.GetAt( ( i + 1 ) % nVertexs ), iwVertexsFace.GetAt( i ) );
		}
		iwVertexsNewFace.RemoveAll( );
	}

	if ( addedElements2 ) {
		UpdateEdgesAffected( addedElements2, &iwIndexesRemovedEdges, &iwStartVertexRemovedEdges, &iwEndVertexRemovedEdges );
		UpdateCreaseEdgesAffected( addedElements2, &indexes2, &start2, &end2 );
	}

	if ( userlongs2.GetSize( ) > 0 ) RestoreCreaseEdgeInfo( addedElements2, &userlongs2, &values );

	PBrep->DeletePolyFace( iwFace );

	if ( updateTopology ) UpdateTopology( OGLTransf );
}

//------------------------------------------------------------------------------

// Partir cara por n puntos interiores, cada punto tiene que tener su correspondiente vertice de union
// En las estructuras TAddedElements se devuelven los vertices, aristas y caras añadidos.
// Si updateTopology se pasa a false, es responsabilidad del que llama a la función de restaurar la PolygonList y los colores poseriormente
void TPBrepData::SplitFace( TOGLTransf *OGLTransf, IwPolyFace *iwFace, IwTA<T3DPoint> points, IwTA<ULONG> vertexs, TAddedElements *addedElements, bool updateTopology )
{
	bool founded;
	int i, j, previousK, k, nVertexs, iniIndex, indexReal, indexReal2, userIndex2, nEdges;
	ULONG index;
	IwPoint3d iwNewPoint3d;
	IwVector3d iwVector;
	IwTA<IwPolyVertex *> newVertexesCreated;
	IwPolyVertex *newVertex, *vertexAux;
	IwPolyFace *newFace;
	IwTA<IwPolyVertex *> iwVertexsFace, iwVertexsNewFace, iwVertexsNewFace2;
	IwTA<IwPolyRegion *> regions;
	IwTA<IwPolyShell *> shells;
	IwTA<int> iwIndexesRemovedEdges;
	IwTA<ULONG> indexes2;
	IwTA<IwPolyVertex *> iwStartVertexRemovedEdges, iwEndVertexRemovedEdges, start2, end2;
	IwTA<IwPolyEdge *> edges;
	TAddedElements *addedElements2, addedElements3;
	IwTA<int> userlongs2;
	IwTA<float> values;

	if ( !OGLTransf || !PBrep || !iwFace || points.GetSize( ) == 0 || vertexs.GetSize( ) == 0 ) return;
	if ( points.GetSize( ) != vertexs.GetSize( ) ) return;
	PBrep->GetPolyRegions( regions );
	PBrep->GetPolyShells( shells );
	if ( regions.GetSize( ) == 0 || shells.GetSize( ) == 0 ) return;

	if ( addedElements ) addedElements2 = addedElements;
	else
		addedElements2 = &addedElements3;

	InitUserLong2( );

	iwFace->GetPolyEdges( edges );
	nEdges = (int) edges.GetSize( );
	for ( i = 0; i < nEdges; i++ ) {
		SaveCreaseEdgeInfo( edges[ i ], &userlongs2, &values );
		SaveCreaseEdgeInfo( edges[ i ]->GetSymmetricPolyEdge( ), &userlongs2, &values );
	}

	iwFace->GetPolyVertices( iwVertexsFace );
	nVertexs = (int) iwVertexsFace.GetSize( );
	// Comprobamos que la lista de vertices pertenezcan a la cara
	for ( i = 0; i < (int) points.GetSize( ); i++ ) {
		if ( vertexs[ i ] >= PBrepVertexs.GetSize( ) ) return;
		vertexAux = PBrepVertexs[ vertexs[ i ] ];
		if ( !iwVertexsFace.FindElement( vertexAux, index ) ) return;
		if ( i == 0 ) iniIndex = (int) index;
	}

	if ( addedElements2 ) {
		userIndex2 = iwFace->GetUserIndex2( );
		AddEdgesAffectedFromFace( iwFace, &iwIndexesRemovedEdges, &iwStartVertexRemovedEdges, &iwEndVertexRemovedEdges );
		AddCreaseEdgesAffectedFromFace( iwFace, &indexes2, &start2, &end2 );
	}

	for ( i = 0; i < (int) points.GetSize( ); i++ )
		newVertexesCreated.Add( 0 );
	previousK = 0;
	newFace = 0;
	// Empezamos por un vertice que tiene punto asociado
	for ( i = iniIndex; i < iniIndex + nVertexs; i++ ) {
		indexReal = i >= nVertexs ? i - nVertexs + 1 : i;
		if ( indexReal == iniIndex && newFace ) break;
		iwVertexsNewFace.Add( iwVertexsFace[ indexReal ] );
		for ( j = indexReal + 1; j <= iniIndex + nVertexs; j++ ) {
			indexReal2 = j >= nVertexs ? i - nVertexs + 1 : j;

			founded = false;
			for ( k = 0; k < (int) points.GetSize( ); k++ ) {
				if ( iwVertexsFace[ indexReal2 ]->GetIndexExt( ) == (int) vertexs[ k ] ) {
					founded = true;
					break;
				}
			}

			if ( !founded ) iwVertexsNewFace.Add( iwVertexsFace[ indexReal2 ] );
			else {
				iwVertexsNewFace.Add( iwVertexsFace[ indexReal2 ] );
				if ( newVertexesCreated[ k ] == 0 ) {
					iwNewPoint3d.Set( points[ k ].x, points[ k ].y, points[ k ].z );
					newVertex = new IwPolyVertex( _GetSMLib( )->GetContext( ), *PBrep, iwNewPoint3d, RES_COMP );
				} else
					newVertex = newVertexesCreated[ k ];

				iwVertexsNewFace.Add( newVertex );
				iwVertexsNewFace2.Add( newVertex );

				if ( addedElements2 ) addedElements2->iwVertexs.AddUnique( newVertex );

				if ( newVertexesCreated[ previousK ] == 0 ) {
					iwNewPoint3d.Set( points[ previousK ].x, points[ previousK ].y, points[ previousK ].z );
					newVertexesCreated[ previousK ] = new IwPolyVertex( _GetSMLib( )->GetContext( ), *PBrep, iwNewPoint3d, RES_COMP );
				}
				iwVertexsNewFace.Add( newVertexesCreated[ previousK ] );
				newVertexesCreated[ k ] = newVertex;
				if ( addedElements2 ) addedElements2->iwVertexs.AddUnique( newVertexesCreated[ k ] );

				previousK = k;
				PBrep->CreatePolyFace( regions.GetAt( 0 ), shells.GetAt( 0 ), iwVertexsNewFace, newFace );
				if ( addedElements2 ) {
					newFace->SetUserIndex2( userIndex2 );
					AddFaceAndEdgesToElements( newFace, addedElements2 ); // No añadimos estas aristas como nuevas para que no se seleccionen, vertex2, vertex1 );
				}

				i = indexReal2 - 1;
				iwVertexsNewFace.RemoveAll( );
				break;
			}
		}
	}

	// Y por ultimo creamos una cara entre todos los puntos nuevos
	PBrep->CreatePolyFace( regions.GetAt( 0 ), shells.GetAt( 0 ), iwVertexsNewFace2, newFace );

	if ( addedElements2 ) {
		newFace->SetUserIndex2( userIndex2 );
		AddFaceAndEdgesToElements( newFace, addedElements2, iwVertexsNewFace2[ 0 ], iwVertexsNewFace2[ 0 ] );
		UpdateEdgesAffected( addedElements2, &iwIndexesRemovedEdges, &iwStartVertexRemovedEdges, &iwEndVertexRemovedEdges );
		UpdateCreaseEdgesAffected( addedElements2, &indexes2, &start2, &end2 );
	}

	if ( userlongs2.GetSize( ) > 0 ) RestoreCreaseEdgeInfo( addedElements2, &userlongs2, &values );

	PBrep->DeletePolyFace( iwFace );

	if ( updateTopology ) UpdateTopology( OGLTransf );
}

//------------------------------------------------------------------------------

// Partir cara por dos de sus vertices.
// En las estructuras TAddedElements se devuelven los vertices, aristas y caras añadidos.
// Si updateTopology se pasa a false, es responsabilidad del que llama a la función de restaurar la PolygonList y los colores poseriormente
void TPBrepData::SplitFace( TOGLTransf *OGLTransf, IwPolyFace *iwFace, IwPolyVertex *iwVertex1, IwPolyVertex *iwVertex2, IwTA<T3DPoint> *points, TAddedElements *addedElements, bool updateTopology )
{
	ULONG pos1, pos2;
	int i, nVertexs, nPoints, userIndex2, nEdges;
	IwPoint3d iwNewPoint3d;
	IwPolyVertex *newVertex;
	IwPolyFace *newFace;
	IwTA<IwPolyRegion *> regions;
	IwTA<IwPolyShell *> shells;
	IwTA<IwPolyVertex *> iwVertexsFace, iwVertexsNewFace, iwNewVertexs;
	IwTA<int> iwIndexesRemovedEdges;
	IwTA<ULONG> indexes2;
	IwTA<IwPolyVertex *> iwStartVertexRemovedEdges, iwEndVertexRemovedEdges, start2, end2;
	IwTA<IwPolyEdge *> edges;
	TAddedElements *addedElements2, addedElements3;
	IwTA<int> userlongs2;
	IwTA<float> values;

	if ( !OGLTransf || !PBrep || !iwFace || !iwVertex1 || !iwVertex2 || ( iwVertex1 == iwVertex2 ) ) return;
	PBrep->GetPolyRegions( regions );
	PBrep->GetPolyShells( shells );
	if ( regions.GetSize( ) == 0 || shells.GetSize( ) == 0 ) return;

	if ( addedElements ) addedElements2 = addedElements;
	else
		addedElements2 = &addedElements3;

	InitUserLong2( );

	iwFace->GetPolyEdges( edges );
	nEdges = (int) edges.GetSize( );
	for ( i = 0; i < nEdges; i++ ) {
		SaveCreaseEdgeInfo( edges[ i ], &userlongs2, &values );
		SaveCreaseEdgeInfo( edges[ i ]->GetSymmetricPolyEdge( ), &userlongs2, &values );
	}

	iwFace->GetPolyVertices( iwVertexsFace );
	nVertexs = (int) iwVertexsFace.GetSize( );

	if ( !iwVertexsFace.FindElement( iwVertex1, pos1 ) ) return;
	if ( !iwVertexsFace.FindElement( iwVertex2, pos2 ) ) return;
	if ( points ) nPoints = (int) points->GetSize( );
	if ( ( !points || nPoints == 0 ) && ( fabs( (float) ( pos2 - pos1 ) ) == 1 || fabs( (float) ( pos2 - pos1 ) ) == ( nVertexs - 1 ) ) ) return;

	if ( points ) {
		for ( i = 0; i < nPoints; i++ ) {
			iwNewPoint3d.Set( points->GetAt( i ).x, points->GetAt( i ).y, points->GetAt( i ).z );
			newVertex = new IwPolyVertex( _GetSMLib( )->GetContext( ), *PBrep, iwNewPoint3d, RES_COMP );
			if ( addedElements2 ) addedElements2->iwVertexs.AddUnique( newVertex );
			iwNewVertexs.Add( newVertex );
		}
	} else
		nPoints = 0;

	if ( addedElements2 ) {
		userIndex2 = iwFace->GetUserIndex2( );
		AddEdgesAffectedFromFace( iwFace, &iwIndexesRemovedEdges, &iwStartVertexRemovedEdges, &iwEndVertexRemovedEdges );
		AddCreaseEdgesAffectedFromFace( iwFace, &indexes2, &start2, &end2 );
	}

	i = pos1;
	do {
		iwVertexsNewFace.Add( iwVertexsFace.GetAt( i ) );
		i = ( i + 1 ) % nVertexs;
	} while ( iwVertexsFace.GetAt( i ) != iwVertex2 );
	iwVertexsNewFace.Add( iwVertexsFace.GetAt( i ) );
	for ( i = nPoints - 1; i >= 0; i-- )
		iwVertexsNewFace.Add( iwNewVertexs.GetAt( i ) );
	PBrep->CreatePolyFace( regions.GetAt( 0 ), shells.GetAt( 0 ), iwVertexsNewFace, newFace );
	if ( addedElements2 ) {
		newFace->SetUserIndex2( userIndex2 );
		AddFaceAndEdgesToElements( newFace, addedElements2, iwVertex2, iwVertex1 );
	}
	iwVertexsNewFace.RemoveAll( );
	i = pos2;
	do {
		iwVertexsNewFace.Add( iwVertexsFace.GetAt( i ) );
		i = ( i + 1 ) % nVertexs;
	} while ( iwVertexsFace.GetAt( i ) != iwVertex1 );
	iwVertexsNewFace.Add( iwVertexsFace.GetAt( i ) );
	for ( i = 0; i < nPoints; i++ )
		iwVertexsNewFace.Add( iwNewVertexs.GetAt( i ) );
	PBrep->CreatePolyFace( regions.GetAt( 0 ), shells.GetAt( 0 ), iwVertexsNewFace, newFace );
	if ( addedElements2 ) {
		newFace->SetUserIndex2( userIndex2 );
		AddFaceAndEdgesToElements( newFace, addedElements2, iwVertex1, iwVertex2 );
		UpdateEdgesAffected( addedElements2, &iwIndexesRemovedEdges, &iwStartVertexRemovedEdges, &iwEndVertexRemovedEdges );
		UpdateCreaseEdgesAffected( addedElements2, &indexes2, &start2, &end2 );
	}

	if ( userlongs2.GetSize( ) > 0 ) RestoreCreaseEdgeInfo( addedElements2, &userlongs2, &values );

	PBrep->DeletePolyFace( iwFace );

	if ( updateTopology ) UpdateTopology( OGLTransf );
}

//------------------------------------------------------------------------------

// Partir cara por un vertice y una de sus aristas
// En las estructuras TAddedElements se devuelven los vertices, aristas y caras añadidos o eliminados.
// Si se obtienen los añadidos además en el valor 'userIndex2' de la nueva cara se pone el índice de la cara original.
// Si updateTopology se pasa a false, es responsabilidad del que llama a la función de restaurar la PolygonList y los colores poseriormente
void TPBrepData::SplitFace( TOGLTransf *OGLTransf, IwPolyFace *iwFace, IwPolyVertex *iwVertex, IwPolyEdge *iwEdge, T3DPoint *point, IwTA<T3DPoint> *points, TAddedElements *addedElements, bool repairAdyacents, bool updateTopology )
{
	int i, j, nEdges, nPoints, userIndex2;
	ULONG posVertex, posEdge;
	T3DPoint pt3d;
	IwVector3d iwVector3d;
	IwPoint3d iwNewPoint3d;
	IwPolyVertex *iwNewVertex, *newVertex;
	IwPolyEdge *iwSymmetricEdge, *iwEdgeAux;
	IwPolyFace *newFace, *iwSymmetricFace;
	IwTA<IwPolyRegion *> regions;
	IwTA<IwPolyShell *> shells;
	IwTA<IwPolyVertex *> iwVertexsFace, iwVertexsNewFace, iwNewVertexs;
	IwTA<IwPolyEdge *> iwEdgesFace;
	IwTA<int> iwIndexesRemovedEdges;
	IwTA<ULONG> indexes2;
	IwTA<IwPolyVertex *> iwStartVertexRemovedEdges, iwEndVertexRemovedEdges, start2, end2;
	IwTA<IwPolyEdge *> edges;
	TAddedElements *addedElements2, addedElements3;
	IwTA<int> userlongs2;
	IwTA<float> values;

	if ( !OGLTransf || !PBrep || !iwFace || !iwVertex || !iwEdge ) return;
	PBrep->GetPolyRegions( regions );
	PBrep->GetPolyShells( shells );
	if ( regions.GetSize( ) == 0 || shells.GetSize( ) == 0 ) return;

	// Comprobamos si el vertice pertenece a la arista
	if ( ( iwVertex == iwEdge->GetStartVertex( ) || iwVertex == iwEdge->GetEndVertex( ) ) && ( !points || (int) points->GetSize( ) == 0 ) ) {
		if ( point ) iwNewPoint3d.Set( point->x, point->y, point->z );
		else {
			iwNewPoint3d = iwEdge->GetStartPoint( );
			iwNewPoint3d += iwEdge->GetEndPoint( );
			iwNewPoint3d /= 2.0;
		}
		iwNewVertex = FindVertex( &iwNewPoint3d );
		if ( !iwNewVertex ) {
			if ( repairAdyacents ) iwSymmetricEdge = iwEdge->GetSymmetricPolyEdge( );
			iwNewVertex = new IwPolyVertex( _GetSMLib( )->GetContext( ), *PBrep, iwNewPoint3d, RES_COMP );
			if ( addedElements ) addedElements->iwVertexs.AddUnique( iwNewVertex );
			SplitFace( OGLTransf, iwFace, iwEdge, iwNewVertex, addedElements, updateTopology );
			if ( iwSymmetricEdge ) {
				iwSymmetricFace = iwSymmetricEdge->GetPolyFace( );
				SplitFace( OGLTransf, iwSymmetricFace, iwSymmetricEdge, iwNewVertex, addedElements, updateTopology );
			}

			// Hay que incluir las aristas nuevas aquellas que estan entre el vertice de entrada y el nuevo vertice
			if ( addedElements ) {
				nEdges = (int) addedElements->iwEdges.GetSize( );
				for ( i = nEdges - 1; i >= 0; i-- ) {
					iwEdgeAux = addedElements->iwEdges.GetAt( i );
					if ( ( iwEdgeAux->GetStartVertex( ) == iwVertex && iwEdgeAux->GetEndVertex( ) == iwNewVertex ) || ( iwEdgeAux->GetStartVertex( ) == iwNewVertex && iwEdgeAux->GetEndVertex( ) == iwVertex ) ) {
						addedElements->iwEdges.RemoveAt( i );
						addedElements->iwNewEdges.AddUnique( iwEdgeAux );
					}
				}
			}
		}

		return;
	}

	// Comprobamos que el punto no sea uno de los vértices de la arista
	if ( point ) {
		iwVector3d = iwEdge->GetStartPoint( );
		pt3d = T3DPoint( iwVector3d.x, iwVector3d.y, iwVector3d.z );
		if ( point->Similar( pt3d ) ) {
			newVertex = iwEdge->GetStartVertex( );
			SplitFace( OGLTransf, iwFace, iwVertex, iwEdge->GetStartVertex( ), points, addedElements, updateTopology );
			// El vertice no se ha añadido pq no es nuevo... pero como de esta funcion se espera q se añada un nuevo vertice, entonces lo añadimos para tenerlo controlado fuera
			addedElements->iwVertexs.AddUnique( newVertex );
			return;
		}
		iwVector3d = iwEdge->GetEndPoint( );
		pt3d = T3DPoint( iwVector3d.x, iwVector3d.y, iwVector3d.z );
		if ( point->Similar( pt3d ) ) {
			newVertex = iwEdge->GetEndVertex( );
			SplitFace( OGLTransf, iwFace, iwVertex, newVertex, points, addedElements, updateTopology );
			// El vertice no se ha añadido pq no es nuevo... pero como de esta funcion se espera q se añada un nuevo vertice, entonces lo añadimos para tenerlo controlado fuera
			addedElements->iwVertexs.AddUnique( newVertex );
			return;
		}
	}

	iwFace->GetPolyVertices( iwVertexsFace );
	if ( !iwVertexsFace.FindElement( iwVertex, posVertex ) ) return;

	iwFace->GetPolyEdges( iwEdgesFace );
	nEdges = (int) iwEdgesFace.GetSize( );
	if ( !iwEdgesFace.FindElement( iwEdge, posEdge ) ) return;

	if ( addedElements ) addedElements2 = addedElements;
	else
		addedElements2 = &addedElements3;

	InitUserLong2( );

	for ( i = 0; i < nEdges; i++ ) {
		SaveCreaseEdgeInfo( iwEdgesFace[ i ], &userlongs2, &values );
		SaveCreaseEdgeInfo( iwEdgesFace[ i ]->GetSymmetricPolyEdge( ), &userlongs2, &values );
	}

	if ( point ) iwNewPoint3d.Set( point->x, point->y, point->z );
	else {
		iwNewPoint3d = iwEdge->GetStartPoint( );
		iwNewPoint3d += iwEdge->GetEndPoint( );
		iwNewPoint3d /= 2.0;
	}
	iwNewVertex = FindVertex( &iwNewPoint3d );
	if ( !iwNewVertex ) {
		iwNewVertex = new IwPolyVertex( _GetSMLib( )->GetContext( ), *PBrep, iwNewPoint3d, RES_COMP );
		if ( addedElements2 ) addedElements2->iwVertexs.AddUnique( iwNewVertex );
	}

	if ( points ) {
		nPoints = (int) points->GetSize( );
		for ( i = 0; i < nPoints; i++ ) {
			iwNewPoint3d.Set( points->GetAt( i ).x, points->GetAt( i ).y, points->GetAt( i ).z );
			newVertex = new IwPolyVertex( _GetSMLib( )->GetContext( ), *PBrep, iwNewPoint3d, RES_COMP );
			if ( addedElements2 ) addedElements2->iwVertexs.AddUnique( newVertex );
			iwNewVertexs.Add( newVertex );
		}
	} else
		nPoints = 0;

	if ( addedElements2 ) {
		userIndex2 = iwFace->GetUserIndex2( );
		AddEdgesAffectedFromFace( iwFace, &iwIndexesRemovedEdges, &iwStartVertexRemovedEdges, &iwEndVertexRemovedEdges );
		AddCreaseEdgesAffectedFromFace( iwFace, &indexes2, &start2, &end2 );
	}

	i = posEdge;
	iwVertexsNewFace.Add( iwNewVertex );
	do {
		iwVertexsNewFace.Add( iwEdgesFace.GetAt( i )->GetEndVertex( ) );
		i = ( i + 1 ) % nEdges;
	} while ( iwEdgesFace.GetAt( i )->GetStartVertex( ) != iwVertex );
	for ( j = 0; j < nPoints; j++ )
		iwVertexsNewFace.Add( iwNewVertexs.GetAt( j ) );
	PBrep->CreatePolyFace( regions.GetAt( 0 ), shells.GetAt( 0 ), iwVertexsNewFace, newFace );
	if ( addedElements2 ) {
		newFace->SetUserIndex2( userIndex2 );
		AddFaceAndEdgesToElements( newFace, addedElements2, iwVertex, iwNewVertex );
	}

	iwVertexsNewFace.RemoveAll( );
	iwVertexsNewFace.Add( iwVertex );
	while ( iwEdgesFace.GetAt( i ) != iwEdge ) {
		iwVertexsNewFace.Add( iwEdgesFace.GetAt( i )->GetEndVertex( ) );
		i = ( i + 1 ) % nEdges;
	}
	iwVertexsNewFace.Add( iwNewVertex );
	for ( i = nPoints - 1; i >= 0; i-- )
		iwVertexsNewFace.Add( iwNewVertexs.GetAt( i ) );
	PBrep->CreatePolyFace( regions.GetAt( 0 ), shells.GetAt( 0 ), iwVertexsNewFace, newFace );
	if ( addedElements2 ) {
		newFace->SetUserIndex2( userIndex2 );
		AddFaceAndEdgesToElements( newFace, addedElements2, iwNewVertex, iwVertex );
		UpdateEdgesAffected( addedElements2, &iwIndexesRemovedEdges, &iwStartVertexRemovedEdges, &iwEndVertexRemovedEdges );
		UpdateCreaseEdgesAffected( addedElements2, &indexes2, &start2, &end2 );
	}

	if ( userlongs2.GetSize( ) > 0 ) RestoreCreaseEdgeInfo( addedElements2, &userlongs2, &values );

	if ( repairAdyacents ) {
		iwSymmetricEdge = iwEdge->GetSymmetricPolyEdge( );
		if ( iwSymmetricEdge ) {
			iwSymmetricFace = iwSymmetricEdge->GetPolyFace( );
			SplitFace( OGLTransf, iwSymmetricFace, iwSymmetricEdge, iwNewVertex, addedElements2, false );
		}
	}

	PBrep->DeletePolyFace( iwFace );

	if ( updateTopology ) UpdateTopology( OGLTransf );
}

//------------------------------------------------------------------------------

// Partir cara por dos de sus aristas
// En las estructuras TAddedElements se devuelven los vertices, aristas y caras añadidos o eliminados.
// Si se obtienen los añadidos además en el valor 'userIndex2' de la nueva cara se pone el índice de la cara original.
// Si updateTopology se pasa a false, es responsabilidad del que llama a la función de restaurar la PolygonList y los colores poseriormente
void TPBrepData::SplitFace( TOGLTransf *OGLTransf, IwPolyFace *iwFace, IwPolyEdge *iwEdge1, T3DPoint *point1, IwPolyEdge *iwEdge2, T3DPoint *point2, IwTA<T3DPoint> *points, TAddedElements *addedElements, bool repairAdyacents, bool updateTopology )
{
	int i, j, nEdges, nPoints, userIndex2;
	ULONG posEdge1, posEdge2;
	T3DPoint pt3d;
	IwVector3d iwVector3d;
	IwPoint3d iwNewPoint3d;
	IwPolyVertex *iwNewVertex1, *iwNewVertex2, *newVertex;
	IwPolyEdge *iwSymmetricEdge;
	IwPolyFace *newFace, *iwSymmetricFace;
	IwTA<IwPolyRegion *> regions;
	IwTA<IwPolyShell *> shells;
	IwTA<IwPolyVertex *> iwVertexsNewFace, iwNewVertexs;
	IwTA<IwPolyEdge *> iwEdgesFace;
	IwTA<int> iwIndexesRemovedEdges;
	IwTA<ULONG> indexes2;
	IwTA<IwPolyVertex *> iwStartVertexRemovedEdges, iwEndVertexRemovedEdges, start2, end2;
	TAddedElements *addedElements2, addedElements3;
	IwTA<int> userlongs2;
	IwTA<float> values;

	if ( !PBrep || !OGLTransf || !iwFace || !iwEdge1 || !iwEdge2 || ( iwEdge1 == iwEdge2 ) ) return;
	PBrep->GetPolyRegions( regions );
	PBrep->GetPolyShells( shells );
	if ( regions.GetSize( ) == 0 || shells.GetSize( ) == 0 ) return;

	// Comprobamos que los puntos no sean uno de los vértices de la aristas
	iwNewVertex1 = iwNewVertex2 = NULL;
	if ( point1 ) {
		iwVector3d = iwEdge1->GetStartPoint( );
		pt3d = T3DPoint( iwVector3d.x, iwVector3d.y, iwVector3d.z );
		if ( point1->Similar( pt3d ) ) iwNewVertex1 = iwEdge1->GetStartVertex( );
		else {
			iwVector3d = iwEdge1->GetEndPoint( );
			pt3d = T3DPoint( iwVector3d.x, iwVector3d.y, iwVector3d.z );
			if ( point1->Similar( pt3d ) ) iwNewVertex1 = iwEdge1->GetEndVertex( );
		}
	}
	if ( point2 ) {
		iwVector3d = iwEdge2->GetStartPoint( );
		pt3d = T3DPoint( iwVector3d.x, iwVector3d.y, iwVector3d.z );
		if ( point2->Similar( pt3d ) ) iwNewVertex2 = iwEdge2->GetStartVertex( );
		else {
			iwVector3d = iwEdge2->GetEndPoint( );
			pt3d = T3DPoint( iwVector3d.x, iwVector3d.y, iwVector3d.z );
			if ( point2->Similar( pt3d ) ) iwNewVertex2 = iwEdge2->GetEndVertex( );
		}
	}
	if ( iwNewVertex1 && iwNewVertex2 ) {
		SplitFace( OGLTransf, iwFace, iwNewVertex1, iwNewVertex2, points, addedElements, updateTopology );
		// El vertice no se ha añadido pq no es nuevo... pero como de esta funcion se espera q se añada un nuevo vertice, entonces lo añadimos para tenerlo controlado fuera
		addedElements->iwVertexs.AddUnique( iwNewVertex2 );
		return;
	} else if ( iwNewVertex1 && !iwNewVertex2 ) {
		SplitFace( OGLTransf, iwFace, iwNewVertex1, iwEdge2, point2, points, addedElements, repairAdyacents, updateTopology );
		return;
	} else if ( !iwNewVertex1 && iwNewVertex2 ) {
		if ( points ) points->ReverseArray( 0, points->GetSize( ) );
		SplitFace( OGLTransf, iwFace, iwNewVertex2, iwEdge1, point1, points, addedElements, repairAdyacents, updateTopology );
		// El vertice no se ha añadido pq no es nuevo... pero como de esta funcion se espera q se añada un nuevo vertice, entonces lo añadimos para tenerlo controlado fuera
		addedElements->iwVertexs.InsertAt( 0, iwNewVertex2 );
		if ( points ) points->ReverseArray( 0, points->GetSize( ) );
		return;
	}

	iwFace->GetPolyEdges( iwEdgesFace );
	nEdges = (int) iwEdgesFace.GetSize( );
	if ( !iwEdgesFace.FindElement( iwEdge1, posEdge1 ) ) return;
	if ( !iwEdgesFace.FindElement( iwEdge2, posEdge2 ) ) return;

	if ( addedElements ) addedElements2 = addedElements;
	else
		addedElements2 = &addedElements3;

	InitUserLong2( );

	for ( i = 0; i < nEdges; i++ ) {
		SaveCreaseEdgeInfo( iwEdgesFace[ i ], &userlongs2, &values );
		SaveCreaseEdgeInfo( iwEdgesFace[ i ]->GetSymmetricPolyEdge( ), &userlongs2, &values );
	}

	if ( point1 ) iwNewPoint3d.Set( point1->x, point1->y, point1->z );
	else {
		iwNewPoint3d = iwEdge1->GetStartPoint( );
		iwNewPoint3d += iwEdge1->GetEndPoint( );
		iwNewPoint3d /= 2.0;
	}
	iwNewVertex1 = FindVertex( &iwNewPoint3d );
	if ( !iwNewVertex1 ) {
		iwNewVertex1 = new IwPolyVertex( _GetSMLib( )->GetContext( ), *PBrep, iwNewPoint3d, RES_COMP );
		if ( addedElements2 ) addedElements2->iwVertexs.AddUnique( iwNewVertex1 );
	}

	if ( point2 ) iwNewPoint3d.Set( point2->x, point2->y, point2->z );
	else {
		iwNewPoint3d = iwEdge2->GetStartPoint( );
		iwNewPoint3d += iwEdge2->GetEndPoint( );
		iwNewPoint3d /= 2.0;
	}
	iwNewVertex2 = FindVertex( &iwNewPoint3d );
	if ( !iwNewVertex2 ) {
		iwNewVertex2 = new IwPolyVertex( _GetSMLib( )->GetContext( ), *PBrep, iwNewPoint3d, RES_COMP );
		if ( addedElements2 ) addedElements2->iwVertexs.AddUnique( iwNewVertex2 );
	}

	if ( points ) {
		nPoints = (int) points->GetSize( );
		for ( i = 0; i < nPoints; i++ ) {
			iwNewPoint3d.Set( points->GetAt( i ).x, points->GetAt( i ).y, points->GetAt( i ).z );
			newVertex = new IwPolyVertex( _GetSMLib( )->GetContext( ), *PBrep, iwNewPoint3d, RES_COMP );
			if ( addedElements2 ) addedElements2->iwVertexs.AddUnique( newVertex );
			iwNewVertexs.Add( newVertex );
		}
	} else
		nPoints = 0;

	if ( addedElements2 ) {
		userIndex2 = iwFace->GetUserIndex2( );
		AddEdgesAffectedFromFace( iwFace, &iwIndexesRemovedEdges, &iwStartVertexRemovedEdges, &iwEndVertexRemovedEdges );
		AddCreaseEdgesAffectedFromFace( iwFace, &indexes2, &start2, &end2 );
	}

	i = posEdge1;
	iwVertexsNewFace.Add( iwNewVertex1 );
	do {
		iwVertexsNewFace.Add( iwEdgesFace.GetAt( i )->GetEndVertex( ) );
		i = ( i + 1 ) % nEdges;
	} while ( iwEdgesFace.GetAt( i ) != iwEdge2 );
	iwVertexsNewFace.Add( iwNewVertex2 );
	for ( j = nPoints - 1; j >= 0; j-- )
		iwVertexsNewFace.Add( iwNewVertexs.GetAt( j ) );
	PBrep->CreatePolyFace( regions.GetAt( 0 ), shells.GetAt( 0 ), iwVertexsNewFace, newFace );
	if ( addedElements2 ) {
		newFace->SetUserIndex2( userIndex2 );
		AddFaceAndEdgesToElements( newFace, addedElements2, iwNewVertex2, iwNewVertex1 );
	}

	iwVertexsNewFace.RemoveAll( );
	iwVertexsNewFace.Add( iwNewVertex2 );
	do {
		iwVertexsNewFace.Add( iwEdgesFace.GetAt( i )->GetEndVertex( ) );
		i = ( i + 1 ) % nEdges;
	} while ( iwEdgesFace.GetAt( i ) != iwEdge1 );
	iwVertexsNewFace.Add( iwNewVertex1 );
	for ( j = 0; j < nPoints; j++ )
		iwVertexsNewFace.Add( iwNewVertexs.GetAt( j ) );
	PBrep->CreatePolyFace( regions.GetAt( 0 ), shells.GetAt( 0 ), iwVertexsNewFace, newFace );
	if ( addedElements2 ) {
		newFace->SetUserIndex2( userIndex2 );
		AddFaceAndEdgesToElements( newFace, addedElements2, iwNewVertex1, iwNewVertex2 );
		UpdateEdgesAffected( addedElements2, &iwIndexesRemovedEdges, &iwStartVertexRemovedEdges, &iwEndVertexRemovedEdges );
		UpdateCreaseEdgesAffected( addedElements2, &indexes2, &start2, &end2 );
	}

	if ( userlongs2.GetSize( ) > 0 ) RestoreCreaseEdgeInfo( addedElements2, &userlongs2, &values );

	if ( repairAdyacents ) {
		iwSymmetricEdge = iwEdge1->GetSymmetricPolyEdge( );
		if ( iwSymmetricEdge ) {
			iwSymmetricFace = iwSymmetricEdge->GetPolyFace( );
			SplitFace( OGLTransf, iwSymmetricFace, iwSymmetricEdge, iwNewVertex1, addedElements2, false );
		}
		iwSymmetricEdge = iwEdge2->GetSymmetricPolyEdge( );
		if ( iwSymmetricEdge ) {
			iwSymmetricFace = iwSymmetricEdge->GetPolyFace( );
			SplitFace( OGLTransf, iwSymmetricFace, iwSymmetricEdge, iwNewVertex2, addedElements2, false );
		}
	}

	PBrep->DeletePolyFace( iwFace );

	if ( updateTopology ) UpdateTopology( OGLTransf );
}

//------------------------------------------------------------------------------

// Partir cara por dos puntos de una de sus aristas, añadiendo o no vértices en medio.
// Si updateTopology se pasa a false, es responsabilidad del que llama a la función de restaurar la PolygonList y los colores poseriormente
void TPBrepData::SplitFace( TOGLTransf *OGLTransf, IwPolyFace *iwFace, IwPolyEdge *iwEdge, T3DPoint *point1, T3DPoint *point2, IwTA<T3DPoint> *points, TAddedElements *addedElements, bool repairAdyacents, bool updateTopology )
{
	ULONG pos;
	int i, nPoints, nNewPoints, nEdges;
	bool v1_new, v2_new, invertPoints;
	T3DPoint pt;
	IwPoint3d iwNewPoint3d;
	IwVector3d iwVector3d;
	IwPolyVertex *iwVertex1, *iwVertex2, *newVertex;
	IwPolyEdge *iwSymmetricEdge;
	IwPolyFace *iwSymmetricFace, *newFace;
	IwTA<IwPolyRegion *> regions;
	IwTA<IwPolyShell *> shells;
	IwTA<IwPolyVertex *> iwVertexsFace, iwVertexsNewFace, iwNewVertexs;
	IwTA<IwPolyEdge *> iwEdgesFace;
	IwTA<int> iwIndexesRemovedEdges;
	IwTA<ULONG> indexes2;
	IwTA<IwPolyVertex *> iwStartVertexRemovedEdges, iwEndVertexRemovedEdges, start2, end2;
	IwTA<IwPolyEdge *> edges;
	TAddedElements *addedElements2, addedElements3;
	IwTA<int> userlongs2;
	IwTA<float> values;

	if ( !PBrep || !OGLTransf || !iwFace || !iwEdge || !point1 || !point2 || point1->Similar( *point2 ) ) return;
	iwFace->GetPolyEdges( iwEdgesFace );
	if ( !iwEdgesFace.FindElement( iwEdge, pos ) ) return;
	PBrep->GetPolyRegions( regions );
	PBrep->GetPolyShells( shells );
	if ( regions.GetSize( ) == 0 || shells.GetSize( ) == 0 ) return;

	if ( addedElements ) addedElements2 = addedElements;
	else
		addedElements2 = &addedElements3;

	InitUserLong2( );

	iwFace->GetPolyEdges( edges );
	nEdges = (int) edges.GetSize( );
	for ( i = 0; i < nEdges; i++ ) {
		SaveCreaseEdgeInfo( edges[ i ], &userlongs2, &values );
		SaveCreaseEdgeInfo( edges[ i ]->GetSymmetricPolyEdge( ), &userlongs2, &values );
	}

	// Añadimos los dos nuevos puntos comprobando si son alguno de los vértices de la arista.
	iwVector3d = iwEdge->GetStartPoint( );
	pt = T3DPoint( iwVector3d.x, iwVector3d.y, iwVector3d.z );
	if ( point1->Similar( pt ) || point2->Similar( pt ) ) {
		invertPoints = point2->Similar( pt );
		iwVertex1 = iwEdge->GetStartVertex( );
		v1_new = false;
	} else {
		if ( point1->DistanciaSqr( pt ) < point2->DistanciaSqr( pt ) ) {
			iwNewPoint3d.Set( point1->x, point1->y, point1->z );
			invertPoints = false;
		} else {
			iwNewPoint3d.Set( point2->x, point2->y, point2->z );
			invertPoints = true;
		}
		iwVertex1 = NULL;
		if ( !FindVertex( &iwNewPoint3d ) ) {
			iwVertex1 = new IwPolyVertex( _GetSMLib( )->GetContext( ), *PBrep, iwNewPoint3d, RES_COMP );
			if ( addedElements2 ) addedElements2->iwVertexs.AddUnique( iwVertex1 );
		}
		v1_new = true;
	}

	iwVector3d = iwEdge->GetEndPoint( );
	pt = T3DPoint( iwVector3d.x, iwVector3d.y, iwVector3d.z );
	if ( point1->Similar( pt ) || point2->Similar( pt ) ) {
		iwVertex2 = iwEdge->GetEndVertex( );
		v2_new = false;
	} else {
		if ( point1->DistanciaSqr( pt ) < point2->DistanciaSqr( pt ) ) iwNewPoint3d.Set( point1->x, point1->y, point1->z );
		else
			iwNewPoint3d.Set( point2->x, point2->y, point2->z );
		iwVertex2 = FindVertex( &iwNewPoint3d );
		if ( !iwVertex2 ) {
			iwVertex2 = new IwPolyVertex( _GetSMLib( )->GetContext( ), *PBrep, iwNewPoint3d, RES_COMP );
			if ( addedElements2 ) addedElements2->iwVertexs.AddUnique( iwVertex2 );
		}
		v2_new = true;
	}

	// Añadimos los puntos intermedios
	nNewPoints = points ? (int) points->GetSize( ) : 0;
	if ( !v1_new && !v2_new && nNewPoints == 0 ) return;
	if ( nNewPoints > 0 ) {
		for ( i = 0; i < nNewPoints; i++ ) {
			iwNewPoint3d.Set( points->GetAt( i ).x, points->GetAt( i ).y, points->GetAt( i ).z );
			newVertex = new IwPolyVertex( _GetSMLib( )->GetContext( ), *PBrep, iwNewPoint3d, RES_COMP );
			if ( addedElements2 ) addedElements2->iwVertexs.AddUnique( newVertex );
			iwNewVertexs.Add( newVertex );
		}
		if ( invertPoints ) iwNewVertexs.ReverseArray( 0, nNewPoints );
	}

	if ( repairAdyacents ) {
		iwSymmetricEdge = iwEdge->GetSymmetricPolyEdge( );
		iwSymmetricFace = iwSymmetricEdge ? iwSymmetricEdge->GetPolyFace( ) : 0;
	}

	// Primera cara
	iwFace->GetPolyVertices( iwVertexsFace );
	nPoints = (int) iwVertexsFace.GetSize( );
	iwVertexsFace.FindElement( iwEdge->GetEndVertex( ), pos );
	iwVertexsNewFace.Add( iwVertex1 );
	for ( i = 0; i < nNewPoints; i++ )
		iwVertexsNewFace.Add( iwNewVertexs.GetAt( i ) );
	iwVertexsNewFace.Add( iwVertex2 );
	if ( v2_new ) iwVertexsNewFace.Add( iwVertexsFace.GetAt( pos ) );
	i = ( pos + 1 ) % nPoints;
	while ( iwVertexsFace.GetAt( i ) != iwEdge->GetStartVertex( ) ) {
		iwVertexsNewFace.Add( iwVertexsFace.GetAt( i ) );
		i = ( i + 1 ) % nPoints;
	}
	if ( v1_new ) iwVertexsNewFace.Add( iwVertexsFace.GetAt( i ) );
	PBrep->CreatePolyFace( regions.GetAt( 0 ), shells.GetAt( 0 ), iwVertexsNewFace, newFace );
	if ( addedElements2 ) {
		AddEdgesAffectedFromFace( iwFace, &iwIndexesRemovedEdges, &iwStartVertexRemovedEdges, &iwEndVertexRemovedEdges );
		AddCreaseEdgesAffectedFromFace( iwFace, &indexes2, &start2, &end2 );
		newFace->SetUserIndex2( iwFace->GetUserIndex2( ) );
		AddFaceAndEdgesToElements( newFace, addedElements2, iwVertex1, iwVertex2 );
	}

	// Cara nueva
	if ( nNewPoints > 0 ) {
		iwVertexsNewFace.RemoveAll( );
		iwVertexsNewFace.Add( iwVertex1 );
		iwVertexsNewFace.Add( iwVertex2 );
		for ( i = nNewPoints - 1; i >= 0; i-- )
			iwVertexsNewFace.Add( iwNewVertexs.GetAt( i ) );
		PBrep->CreatePolyFace( regions.GetAt( 0 ), shells.GetAt( 0 ), iwVertexsNewFace, newFace );
		if ( addedElements2 ) {
			newFace->SetUserIndex2( iwFace->GetUserIndex2( ) );
			AddFaceAndEdgesToElements( newFace, addedElements2, iwVertex2, iwVertex1 );
		}
	}
	PBrep->DeletePolyFace( iwFace );

	// Cara arista simétrica
	if ( repairAdyacents && iwSymmetricFace ) {
		iwVertexsNewFace.RemoveAll( );
		iwSymmetricFace->GetPolyVertices( iwVertexsFace );
		nPoints = (int) iwVertexsFace.GetSize( );
		iwVertexsFace.FindElement( iwSymmetricEdge->GetEndVertex( ), pos );
		iwVertexsNewFace.Add( iwVertex2 );
		iwVertexsNewFace.Add( iwVertex1 );
		if ( v1_new ) iwVertexsNewFace.Add( iwVertexsFace.GetAt( pos ) );
		i = ( pos + 1 ) % nPoints;
		while ( iwVertexsFace.GetAt( i ) != iwSymmetricEdge->GetStartVertex( ) ) {
			iwVertexsNewFace.Add( iwVertexsFace.GetAt( i ) );
			i = ( i + 1 ) % nPoints;
		}
		if ( v2_new ) iwVertexsNewFace.Add( iwVertexsFace.GetAt( i ) );
		PBrep->CreatePolyFace( regions.GetAt( 0 ), shells.GetAt( 0 ), iwVertexsNewFace, newFace );
		if ( addedElements2 ) {
			AddEdgesAffectedFromFace( iwSymmetricFace, &iwIndexesRemovedEdges, &iwStartVertexRemovedEdges, &iwEndVertexRemovedEdges );
			AddCreaseEdgesAffectedFromFace( iwSymmetricFace, &indexes2, &start2, &end2 );
			newFace->SetUserIndex2( iwSymmetricFace->GetUserIndex2( ) );
			AddFaceAndEdgesToElements( newFace, addedElements2 );
		}
		PBrep->DeletePolyFace( iwSymmetricFace );
	}

	if ( addedElements2 ) {
		UpdateEdgesAffected( addedElements2, &iwIndexesRemovedEdges, &iwStartVertexRemovedEdges, &iwEndVertexRemovedEdges );
		UpdateCreaseEdgesAffected( addedElements2, &indexes2, &start2, &end2 );
	}

	if ( userlongs2.GetSize( ) > 0 ) RestoreCreaseEdgeInfo( addedElements2, &userlongs2, &values );

	if ( updateTopology ) UpdateTopology( OGLTransf );
}

//------------------------------------------------------------------------------

// Se parte una cara por un punto en una de sus aristas.
// Función de apoyo para reparar particiones de caras.
void TPBrepData::SplitFace( TOGLTransf *OGLTransf, IwPolyFace *iwFace, IwPolyEdge *iwEdge, IwPolyVertex *iwVertex, TAddedElements *addedElements, bool updateTopology )
{
	ULONG posEdge;
	int nEdges, i;
	IwPolyFace *newFace;
	IwTA<IwPolyRegion *> regions;
	IwTA<IwPolyShell *> shells;
	IwTA<IwPolyEdge *> iwEdgesFace;
	IwTA<IwPolyVertex *> iwVertexsNewFace;
	IwTA<int> iwIndexesRemovedEdges;
	IwTA<ULONG> indexes2;
	IwTA<IwPolyVertex *> iwStartVertexRemovedEdges, iwEndVertexRemovedEdges, start2, end2;
	TAddedElements *addedElements2, addedElements3;
	IwTA<int> userlongs2;
	IwTA<float> values;

	if ( !PBrep || !iwFace || !iwEdge || !iwVertex ) return;
	PBrep->GetPolyRegions( regions );
	PBrep->GetPolyShells( shells );
	if ( regions.GetSize( ) == 0 || shells.GetSize( ) == 0 ) return;

	if ( addedElements ) addedElements2 = addedElements;
	else
		addedElements2 = &addedElements3;

	iwFace->GetPolyEdges( iwEdgesFace );
	nEdges = (int) iwEdgesFace.GetSize( );
	if ( !iwEdgesFace.FindElement( iwEdge, posEdge ) ) return;

	InitUserLong2( );

	for ( i = 0; i < nEdges; i++ ) {
		SaveCreaseEdgeInfo( iwEdgesFace[ i ], &userlongs2, &values );
		SaveCreaseEdgeInfo( iwEdgesFace[ i ]->GetSymmetricPolyEdge( ), &userlongs2, &values );
	}

	iwVertexsNewFace.Add( iwVertex );
	i = (int) posEdge;
	do {
		iwVertexsNewFace.Add( iwEdgesFace.GetAt( i )->GetEndVertex( ) );
		i = ( i + 1 ) % nEdges;
	} while ( iwEdgesFace.GetAt( i ) != iwEdge );
	PBrep->CreatePolyFace( regions.GetAt( 0 ), shells.GetAt( 0 ), iwVertexsNewFace, newFace );
	if ( addedElements2 ) {
		newFace->SetUserIndex2( iwFace->GetUserIndex2( ) );
		AddFaceAndEdgesToElements( newFace, addedElements2 );
		AddEdgesAffectedFromFace( iwFace, &iwIndexesRemovedEdges, &iwStartVertexRemovedEdges, &iwEndVertexRemovedEdges );
		AddCreaseEdgesAffectedFromFace( iwFace, &indexes2, &start2, &end2 );
		UpdateEdgesAffected( addedElements2, &iwIndexesRemovedEdges, &iwStartVertexRemovedEdges, &iwEndVertexRemovedEdges );
		UpdateCreaseEdgesAffected( addedElements2, &indexes2, &start2, &end2 );
	}

	if ( userlongs2.GetSize( ) > 0 ) RestoreCreaseEdgeInfo( addedElements2, &userlongs2, &values );

	PBrep->DeletePolyFace( iwFace );

	if ( updateTopology ) UpdateTopology( OGLTransf );
}

bool TPBrepData::SplitSubdivideEdge( TOGLTransf *OGLTransf, IwPolyFace *iwFace, IwPolyEdge *iwEdge, IwTA<T3DPoint> *newPoints, TAddedElements *addedElements, bool updateTopology )
{
	ULONG posEdge, posEdgeSymetric;
	int i, nEdges, nEdgesSymetric;
	IwTA<IwPolyEdge *> iwEdgesFace, iwEdgesFaceSymetric;
	IwTA<int> userlongs2;
	IwTA<float> values;
	IwTA<ULONG> indexes2;
	IwTA<int> iwIndexesRemovedEdges;
	IwTA<IwPolyVertex *> auxVertices, iwEndVertexRemovedEdges, iwStartVertexRemovedEdges, start2, end2;
	TAddedElements *addedElements2, addedElements3;
	IwTA<IwPolyRegion *> regions;
	IwTA<IwPolyShell *> shells;
	IwPolyFace *newFace, *newFaceSymetric, *iwFaceSymetric;
	IwTA<IwPolyVertex *> iwVertexsNewFace, iwVertexsNewFaceSymetric;
	IwPolyVertex *newVertex, *vertexStart, *vertexEnd;
	IwPoint3d iwNewPoint3d;
	IwPolyEdge *iwEdgeSymetric;

	if ( !PBrep || !iwFace || !iwEdge ) return false;
	PBrep->GetPolyRegions( regions );
	PBrep->GetPolyShells( shells );
	if ( regions.GetSize( ) == 0 || shells.GetSize( ) == 0 ) return false;

	if ( addedElements ) addedElements2 = addedElements;
	else
		addedElements2 = &addedElements3;

	InitUserLong2( );

	iwFace->GetPolyEdges( iwEdgesFace );

	// simetrica
	iwEdgeSymetric = iwEdge->GetSymmetricPolyEdge( );

	nEdges = (int) iwEdgesFace.GetSize( );
	if ( !iwEdgesFace.FindElement( iwEdge, posEdge ) ) return false;

	// guardar vertice inicial y final
	vertexStart = iwEdge->GetStartVertex( );
	vertexEnd = iwEdge->GetEndVertex( );

	// guardar los vertices de la cara afectados
	AddEdgesAffectedFromFace( iwFace, &iwIndexesRemovedEdges, &iwStartVertexRemovedEdges, &iwEndVertexRemovedEdges );

	// Guardar creases
	for ( i = 0; i < nEdges; i++ ) {
		SaveCreaseEdgeInfo( iwEdgesFace[ i ], &userlongs2, &values );
	}

	// Añadimos los vértices intermedios
	if ( newPoints->GetSize( ) > 0 ) {
		for ( i = 0; i < (int) newPoints->GetSize( ); i++ ) {
			iwNewPoint3d.Set( newPoints->GetAt( i ).x, newPoints->GetAt( i ).y, newPoints->GetAt( i ).z );
			newVertex = new IwPolyVertex( _GetSMLib( )->GetContext( ), *PBrep, iwNewPoint3d, RES_COMP );
			if ( addedElements2 ) addedElements2->iwVertexs.AddUnique( newVertex );
			iwVertexsNewFace.Add( newVertex );
		}
	}

	i = (int) posEdge;
	do {
		iwVertexsNewFace.Add( iwEdgesFace.GetAt( i )->GetEndVertex( ) );
		i = ( i + 1 ) % nEdges;
	} while ( iwEdgesFace.GetAt( i ) != iwEdge );

	PBrep->CreatePolyFace( regions.GetAt( 0 ), shells.GetAt( 0 ), iwVertexsNewFace, newFace );

	// face1
	if ( addedElements2 ) {
		newFace->SetUserIndex2( iwFace->GetUserIndex2( ) );
		AddFaceAndEdgesToElements( newFace, addedElements2, vertexStart, vertexEnd );
		AddCreaseEdgesAffectedFromFace( iwFace, &indexes2, &start2, &end2 );
	}

	newFace->SetUserIndex2( iwFace->GetUserIndex2( ) );
	PBrep->DeletePolyFace( iwFace );

	if ( iwEdgeSymetric ) {
		iwFaceSymetric = iwEdgeSymetric->GetPolyFace( );
		iwFaceSymetric->GetPolyEdges( iwEdgesFaceSymetric );

		nEdgesSymetric = (int) iwEdgesFaceSymetric.GetSize( );

		if ( !iwEdgesFaceSymetric.FindElement( iwEdgeSymetric, posEdgeSymetric ) ) return false;

		// Guardar creases
		for ( i = 0; i < nEdgesSymetric; i++ ) {
			SaveCreaseEdgeInfo( iwEdgesFaceSymetric[ i ], &userlongs2, &values );
		}

		// Añadimos los vértices intermedios
		if ( newPoints->GetSize( ) > 0 ) {
			iwVertexsNewFace.RemoveAt( newPoints->GetSize( ), iwVertexsNewFace.GetSize( ) - newPoints->GetSize( ) );
			iwVertexsNewFaceSymetric = iwVertexsNewFace;
			iwVertexsNewFaceSymetric.ReverseArray( 0, newPoints->GetSize( ) );
		}

		i = (int) posEdgeSymetric;
		do {
			iwVertexsNewFaceSymetric.Add( iwEdgesFaceSymetric.GetAt( i )->GetEndVertex( ) );
			i = ( i + 1 ) % nEdgesSymetric;
		} while ( iwEdgesFaceSymetric.GetAt( i ) != iwEdgeSymetric );

		// createpolyface 2
		PBrep->CreatePolyFace( regions.GetAt( 0 ), shells.GetAt( 0 ), iwVertexsNewFaceSymetric, newFaceSymetric );

		// face 2
		if ( addedElements2 ) {
			newFaceSymetric->SetUserIndex2( iwFaceSymetric->GetUserIndex2( ) );
			AddFaceAndEdgesToElements( newFaceSymetric, addedElements2, vertexEnd, vertexStart );
			AddCreaseEdgesAffectedFromFace( iwFaceSymetric, &indexes2, &start2, &end2 );
		}

		newFaceSymetric->SetUserIndex2( iwFaceSymetric->GetUserIndex2( ) );
		PBrep->DeletePolyFace( iwFaceSymetric );
	}

	// solo una vez después de las dos caras
	UpdateCreaseEdgesAffected( addedElements2, &indexes2, &start2, &end2 );

	if ( userlongs2.GetSize( ) > 0 ) RestoreCreaseEdgeInfo( addedElements2, &userlongs2, &values );

	if ( updateTopology ) UpdateTopology( OGLTransf );

	return true;
}

// =============================================================================
// SUBDIVISION DE ARISTAS.
// =============================================================================
//------------------------------------------------------------------------------
bool TPBrepData::SubdivisionEdge( TOGLTransf *OGLTransf, int numCuts, bool /*nGons*/, int /*cornerType*/ )
{
	int i, j, num, *selectedList;
	double *params;
	// IwTArray<IwPolyEdge*> edges;
	IwPolyEdge *edgeaux;
	IwTA<T3DPoint> newPoints;
	T3DPoint auxP;
	IwPoint3d point;
	IwPolyFace *iwFace;
	IwTA<IwPolyEdge *> edgeListChanged, iwAllEdges;

	// obtener las aristas seleccionadas
	selectedList = GetEdges( OGLTransf, SelectedElementType::AllSelected, num );
	// selectedListAux = selectedList;

	// inicializamos los Index2 de las aristas
	InitUserIndex2( false, true, false );

	PBrep->GetPolyEdges( iwAllEdges );
	for ( i = 0; i < num; i++ )
		iwAllEdges.GetAt( selectedList[ i ] )->SetUserIndex2( 1 );

	if ( num > 0 ) {
		params = new double[ numCuts ];
		for ( i = 0; i < numCuts; i++ )
			params[ i ] = (double) ( i + 1 ) / ( numCuts + 1 );

		for ( i = 0; i < num; i++ ) {
			edgeaux = GetPBrepEdge( OGLTransf, selectedList[ i ] );

			iwFace = edgeaux->GetPolyFace( );

			if ( !edgeaux ) {
				delete[] params;
				return false;
			}
			for ( j = 0; j < numCuts; j++ ) {
				edgeaux->EvaluatePoint( params[ j ], point );
				auxP = T3DPoint( point.x, point.y, point.z );
				newPoints.Add( auxP );
			}
			if ( !SplitSubdivideEdge( OGLTransf, iwFace, edgeaux, &newPoints ) ) {
				newPoints.RemoveAll( );
				if ( selectedList ) delete[] selectedList;
				delete[] params;
				return false;
			} else {
				newPoints.RemoveAll( );
				PBrep->GetPolyEdges( iwAllEdges ); // obtener todos los vértices
				// actualizar los números de las seleccionadas
				// añadir los userindex a los que faltan por cambiar
				for ( i = 0; i < num; i++ )
					iwAllEdges.GetAt( selectedList[ i ] )->SetUserIndex2( 1 );
			}
		}
		if ( selectedList ) delete[] selectedList;
		delete[] params;
	}
	return true;
}

// =============================================================================
// TPBrepData - Disolver elementos. Eliminarlos unificando caras
// =============================================================================
//------------------------------------------------------------------------------

// Solo se pueden disolver vertices que unan dos aristas, independientemente del angulo que formen
bool TPBrepData::CanDisolveSelectedVertexs( )
{
	int i, j, nVertexs, nFaces, count;
	IwTA<IwPolyVertex *> iwVertexs;
	IwTA<IwPolyFace *> iwFaces;

	if ( !PBrep ) return false;

	// Obtenemos lista de vértieces a eliminar
	nVertexs = (int) PBrepVertexs.GetSize( );
	count = 0;
	for ( i = 0; i < nVertexs; i++ )
		if ( SelectedV[ i ].i > 0 ) {
			PBrepVertexs.GetAt( i )->GetAdjacentVertices( iwVertexs );
			if ( (int) iwVertexs.GetSize( ) != 2 ) return false;
			PBrepVertexs.GetAt( i )->GetPolyFaces( iwFaces );
			nFaces = (int) iwFaces.GetSize( );
			for ( j = 0; j < nFaces; j++ ) {
				iwFaces.GetAt( j )->GetPolyVertices( iwVertexs );
				if ( iwVertexs.GetSize( ) < 4 ) return false;
			}
			count++;
		}

	return count > 0;
}

//------------------------------------------------------------------------------

// Disolver vértices seleccionados
bool TPBrepData::DisolveSelectedVertexs( TOGLTransf *OGLTransf, bool updateTopology )
{
	int i, nVertexs;
	IwTA<IwPolyVertex *> iwVertexs;

	if ( !PBrep || !OGLTransf ) return false;

	// Obtenemos lista de vértieces a eliminar
	nVertexs = (int) PBrepVertexs.GetSize( );
	for ( i = 0; i < nVertexs; i++ )
		if ( SelectedV[ i ].i > 0 ) iwVertexs.Add( PBrepVertexs.GetAt( i ) );

	// Disolvemos
	if ( !DisolveVertexs( OGLTransf, &iwVertexs, false ) ) return false;

	if ( updateTopology ) UpdateTopology( OGLTransf );

	return true;
}

//------------------------------------------------------------------------------

// Disolver conjunto de vértices
bool TPBrepData::DisolveVertexs( TOGLTransf *OGLTransf, IwTA<IwPolyVertex *> *iwVertexsToDisolve, bool updateTopology )
{
	ULONG pos;
	int i, nVertexs;
	bool ret;
	IwPolyVertex *iwVertex;
	IwTA<IwPolyVertex *> iwVertexs, iwVertexAux;
	IwTA<IwPolyFace *> iwFacesVertex, iwFaces, iwFacesPBrep;

	if ( !PBrep || !OGLTransf || !iwVertexsToDisolve ) return false;

	// Disolvemos
	ret = false;
	nVertexs = (int) iwVertexsToDisolve->GetSize( );
	for ( i = 0; i < nVertexs; i++ ) {
		PBrep->GetPolyVertices( iwVertexs );
		iwVertex = iwVertexsToDisolve->GetAt( i );
		if ( !iwVertexs.FindElement( iwVertex, pos ) ) continue; // Un vertice puede haberse borrado al borrar otro
		if ( DisolveVertex( OGLTransf, iwVertex, false ) ) ret = true;
	}

	if ( updateTopology ) UpdateTopology( OGLTransf );

	return ret;
}

//------------------------------------------------------------------------------

// Disolver un vértice
bool TPBrepData::DisolveVertex( TOGLTransf *OGLTransf, IwPolyVertex *iwVertex, bool updateTopology )
{
	ULONG pos;
	int i, j, nFaces, nEdges;
	IwPolyEdge *iwEdge, *iwSymmetricEdge;
	IwPolyFace *newFace;
	IwTA<IwPolyFace *> iwFaces, faces;
	IwTA<IwPolyVertex *> iwVertexsNewFace, iwVertexs;
	IwTA<IwPolyEdge *> iwEdgesFace, iwEdgesNewFace;
	IwTA<int> iwIndexesRemovedEdges;
	IwTA<ULONG> indexes2;
	IwTA<IwPolyVertex *> iwStartVertexRemovedEdges, iwEndVertexRemovedEdges, start2, end2;
	IwTA<IwPolyRegion *> regions;
	IwTA<IwPolyShell *> shells;
	TAddedElements addedElements;
	IwTA<int> userlongs2;
	IwTA<float> values;

	if ( !PBrep || !OGLTransf || !iwVertex ) return false;
	PBrep->GetPolyRegions( regions );
	PBrep->GetPolyShells( shells );
	if ( regions.GetSize( ) == 0 || shells.GetSize( ) == 0 ) return false;

	iwVertex->GetAdjacentVertices( iwVertexs );

	if ( iwVertexs.GetSize( ) == 2 ) { // Se unifican las dos aristas en una
		iwVertex->GetPolyFaces( iwFaces );
		nFaces = (int) iwFaces.GetSize( );

		InitUserLong2( );

		iwVertex->GetPolyFaces( faces );
		for ( j = 0; j < (int) faces.GetSize( ); j++ ) {
			faces[ j ]->GetPolyEdges( iwEdgesFace );
			nEdges = (int) iwEdgesFace.GetSize( );
			for ( i = 0; i < nEdges; i++ )
				SaveCreaseEdgeInfo( iwEdgesFace[ i ], &userlongs2, &values, true );
			AddEdgesAffectedFromFace( faces[ j ], &iwIndexesRemovedEdges, &iwStartVertexRemovedEdges, &iwEndVertexRemovedEdges );
			AddCreaseEdgesAffectedFromFace( faces[ j ], &indexes2, &start2, &end2 );
		}

		AddCreaseEdgesAffectedFromVertexDisolve( iwVertex, &indexes2, &start2, &end2 );

		AddVertexToElements( iwVertex, &addedElements );
		// Crear caras
		for ( i = 0; i < nFaces; i++ ) {
			iwEdgesNewFace.RemoveAll( );
			iwFaces.GetAt( i )->GetPolyEdges( iwEdgesFace );
			nEdges = (int) iwEdgesFace.GetSize( );
			for ( j = 0; j < nEdges; j++ ) {
				iwEdge = iwEdgesFace.GetAt( j );
				if ( iwEdge->GetStartVertex( ) != iwVertex && iwEdge->GetEndVertex( ) != iwVertex ) iwEdgesNewFace.AddUnique( iwEdge );
			}
			OrderEdgesFace( &iwEdgesNewFace, false );

			iwVertexsNewFace.RemoveAll( );
			nEdges = (int) iwEdgesNewFace.GetSize( );
			for ( j = 0; j < nEdges; j++ )
				iwVertexsNewFace.Add( iwEdgesNewFace.GetAt( j )->GetStartVertex( ) );
			iwVertexsNewFace.Add( iwEdgesNewFace.GetAt( nEdges - 1 )->GetEndVertex( ) );
			if ( (int) iwVertexsNewFace.GetSize( ) > 2 ) {
				PBrep->CreatePolyFace( regions.GetAt( 0 ), shells.GetAt( 0 ), iwVertexsNewFace, newFace );
				AddFaceAndEdgesToElements( newFace, &addedElements );
			}
		}

		UpdateEdgesAffected( &addedElements, &iwIndexesRemovedEdges, &iwStartVertexRemovedEdges, &iwEndVertexRemovedEdges );
		UpdateCreaseEdgesAffected( &addedElements, &indexes2, &start2, &end2 );

		if ( userlongs2.GetSize( ) > 0 ) {
			RestoreCreaseEdgeInfo( &addedElements, &userlongs2, &values );
			UpdateCreaseEdgesAffectedFromDisolve( &addedElements, &indexes2, &start2, &end2, &userlongs2, &values );
		}

		for ( i = 0; i < nFaces; i++ )
			PBrep->DeletePolyFace( iwFaces.GetAt( i ) );

	} else { // Se elimina el vértice y las aristas que lo comparten
		iwVertex->GetPolyFaces( iwFaces );
		nFaces = (int) iwFaces.GetSize( );

		AddEdgesAffectedFromVertex( iwVertex, &iwIndexesRemovedEdges, &iwStartVertexRemovedEdges, &iwEndVertexRemovedEdges );
		AddCreaseEdgesAffectedFromVertex( iwVertex, &indexes2, &start2, &end2 );

		for ( i = 0; i < nFaces; i++ ) {
			iwFaces.GetAt( i )->GetPolyEdges( iwEdgesFace );
			nEdges = (int) iwEdgesFace.GetSize( );
			for ( j = 0; j < nEdges; j++ ) {
				iwEdge = iwEdgesFace.GetAt( j );
				if ( iwEdge->GetStartVertex( ) != iwVertex && iwEdge->GetEndVertex( ) != iwVertex ) iwEdgesNewFace.AddUnique( iwEdge );
			}
		}
		nEdges = (int) iwEdgesNewFace.GetSize( );
		for ( i = 0; i < nEdges; i++ ) {
			iwSymmetricEdge = iwEdgesNewFace.GetAt( i )->GetSymmetricPolyEdge( );
			if ( iwSymmetricEdge && iwEdgesNewFace.FindElement( iwSymmetricEdge, pos ) ) {
				iwEdgesNewFace.RemoveAt( pos );
				iwEdgesNewFace.RemoveAt( i );
				nEdges -= 2;
				i--;
			}
		}
		if ( OrderEdgesFace( &iwEdgesNewFace, false ) ) {
			nEdges = (int) iwEdgesNewFace.GetSize( );
			for ( i = 0; i < nEdges; i++ )
				iwVertexsNewFace.Add( iwEdgesNewFace.GetAt( i )->GetStartVertex( ) );
			if ( iwEdgesNewFace.GetAt( 0 )->GetStartVertex( ) != iwEdgesNewFace.GetAt( nEdges - 1 )->GetEndVertex( ) ) iwVertexsNewFace.Add( iwEdgesNewFace.GetAt( nEdges - 1 )->GetEndVertex( ) );
			PBrep->CreatePolyFace( regions.GetAt( 0 ), shells.GetAt( 0 ), iwVertexsNewFace, newFace );
			AddFaceAndEdgesToElements( newFace, &addedElements );
		} else
			return false;

		for ( i = 0; i < nFaces; i++ ) {
			RemoveFaceAndEdgesFromElements( iwFaces.GetAt( i ), &addedElements );
			PBrep->DeletePolyFace( iwFaces.GetAt( i ) );
		}

		UpdateEdgesAffected( &addedElements, &iwIndexesRemovedEdges, &iwStartVertexRemovedEdges, &iwEndVertexRemovedEdges );
		UpdateCreaseEdgesAffected( &addedElements, &indexes2, &start2, &end2 );
	}

	if ( updateTopology ) UpdateTopology( OGLTransf );

	return true;
}

//------------------------------------------------------------------------------

// Disolver aristas seleccionadas
bool TPBrepData::DisolveSelectedEdges( TOGLTransf *OGLTransf, double angleTolerance, bool updateTopology )
{
	int i, nEdges;
	IwTA<IwPolyEdge *> iwEdges;

	if ( !PBrep || !OGLTransf || angleTolerance < 0.0 || angleTolerance > 90.0 ) return false;

	// Obtenemos lista de aristas a disolver
	nEdges = (int) PBrepEdges.GetSize( );
	for ( i = 0; i < nEdges; i++ ) {
		if ( SelectedE[ i ] > 0 ) iwEdges.Add( PBrepEdges.GetAt( i ) );
	}

	// Disolvemos
	if ( !DisolveEdges( OGLTransf, &iwEdges, angleTolerance, 0, false ) ) return false;

	if ( updateTopology ) UpdateTopology( OGLTransf );

	return true;
}

//------------------------------------------------------------------------------

// Disolver un conjunto de aristas
bool TPBrepData::DisolveEdges( TOGLTransf *OGLTransf, IwTA<IwPolyEdge *> *iwEdgesToDisolve, double angleTolerance, TAddedElements *addedElements, bool updateTopology )
{
	ULONG pos;
	bool ret;
	int i, nEdges, nEdgesFace, nVertexs, maxUserIndex2;
	TAddedElements addedElementsAux;
	IwPolyVertex *iwVertex;
	IwPolyEdge *iwEdge, *iwEdgeSymmetric;
	IwPolyFace *iwFace;
	IwTA<IwPolyVertex *> iwVertexs;
	IwTA<IwPolyEdge *> iwEdgesFace;
	IwTA<IwPolyRegion *> regions;
	IwTA<IwPolyShell *> shells;

	if ( !PBrep || !OGLTransf || !iwEdgesToDisolve || angleTolerance < 0.0 || angleTolerance > 90.0 ) return false;

	nEdges = (int) iwEdgesToDisolve->GetSize( );
	if ( nEdges == (int) PBrepEdges.GetSize( ) ) { // No se pueden disolver todas las caras
		iwFace = PBrepFaces.GetAt( 0 );
		iwFace->GetPolyEdges( iwEdgesFace );
		nEdgesFace = (int) iwEdgesFace.GetSize( );
		for ( i = 0; i < nEdgesFace; i++ ) {
			iwEdge = iwEdgesFace.GetAt( i );
			if ( iwEdgesToDisolve->FindElement( iwEdge, pos ) ) {
				iwEdgesToDisolve->RemoveAt( pos );
				nEdges--;
			}
			iwEdgeSymmetric = iwEdge->GetSymmetricPolyEdge( );
			if ( iwEdgeSymmetric && iwEdgesToDisolve->FindElement( iwEdgeSymmetric, pos ) ) {
				iwEdgesToDisolve->RemoveAt( pos );
				nEdges--;
			}
		}
	}
	if ( nEdges == 0 ) return false;
	PBrep->GetPolyRegions( regions );
	PBrep->GetPolyShells( shells );
	if ( regions.GetSize( ) == 0 || shells.GetSize( ) == 0 ) return false;

	// Marcamos los vertices para luego unificar las aristas de las caras afectadas
	maxUserIndex2 = GetMaxEdgeUserIndex2( );
	for ( i = 0; i < nEdges; i++ ) {
		iwEdge = iwEdgesToDisolve->GetAt( i );
		iwVertex = iwEdge->GetStartVertex( );
		iwVertex->SetUserIndex2( maxUserIndex2 + 1 );
		iwVertexs.AddUnique( iwVertex );
		iwVertex = iwEdge->GetEndVertex( );
		iwVertex->SetUserIndex2( maxUserIndex2 + 1 );
		iwVertexs.AddUnique( iwVertex );
	}

	// Borramos
	ret = RemoveEdges( OGLTransf, iwEdgesToDisolve, addedElements ? addedElements : &addedElementsAux, true, true, false );

	if ( ret ) RemoveUnnecessaryVertexs( OGLTransf, &iwVertexs, angleTolerance, addedElements ? addedElements : &addedElementsAux, false );

	// Desmarcamos los vertices
	PBrep->GetPolyVertices( iwVertexs );
	nVertexs = (int) iwVertexs.GetSize( );
	for ( i = 0; i < nVertexs; i++ )
		iwVertexs.GetAt( i )->SetUserIndex2( 0 );

	if ( updateTopology && ret ) UpdateTopology( OGLTransf );

	return ret;
}

//------------------------------------------------------------------------------

// Disolver un eje.
// Se eliminan las dos caras que comparten el eje y se crea una que que las unifique pero sin incluir los vertices del eje eliminado.
bool TPBrepData::DisolveEdge( TOGLTransf *OGLTransf, IwPolyEdge *iwEdge, double angleTolerance, TAddedElements *addedElements, bool updateTopology )
{
	IwTA<IwPolyEdge *> iwEdgesToDisolve;

	if ( !PBrep || !OGLTransf || !iwEdge || angleTolerance < 0.0 || angleTolerance > 90.0 ) return false;

	iwEdgesToDisolve.Add( iwEdge );
	return DisolveEdges( OGLTransf, &iwEdgesToDisolve, angleTolerance, addedElements, updateTopology );
}

//------------------------------------------------------------------------------

// Disolver caras seleccionadas
bool TPBrepData::DisolveSelectedFaces( TOGLTransf *OGLTransf, double angleTolerance, bool updateTopology )
{
	int i, nFaces;
	IwTA<IwPolyFace *> iwFaces;

	TAddedElements addedElements;

	if ( !PBrep || !OGLTransf || angleTolerance < 0.0 || angleTolerance > 90.0 ) return false;

	// Obtenemos lista de caras a disolver
	nFaces = (int) PBrepFaces.GetSize( );
	for ( i = 0; i < nFaces; i++ ) {
		if ( SelectedF[ i ].i > 0 ) iwFaces.AddUnique( PBrepFaces.GetAt( i ) );
	}

	// Disolvemos
	if ( !DisolveFaces( OGLTransf, &iwFaces, angleTolerance, 0, false ) ) return false;

	if ( updateTopology ) UpdateTopology( OGLTransf );

	return true;
}

//------------------------------------------------------------------------------

// Disolver un conjunto de caras
bool TPBrepData::DisolveFaces( TOGLTransf *OGLTransf, IwTA<IwPolyFace *> *iwFacesToDisolve, double angleTolerance, TAddedElements *addedElements, bool updateTopology )
{
	int i, j, k, nFaces, nNewFaces, nNewFacesOld;
	bool keep, ret, thereAreNewFaces;
	ULONG pos;
	IwPolyEdge *iwEdge;
	IwPolyFace *iwFace1, *iwFace2;
	IwTA<IwPolyVertex *> iwVertexs, iwVertexsAux;
	IwTA<IwPolyEdge *> iwEdgesNewFace;
	IwTA<IwPolyFace *> iwFacesToDisolveAux;
	TAddedElements addedElementsAux, addedElementsOld;

	if ( !PBrep || !OGLTransf || !iwFacesToDisolve ) return false;

	iwFacesToDisolveAux.Copy( *iwFacesToDisolve );
	nFaces = (int) iwFacesToDisolveAux.GetSize( );
	if ( nFaces < 2 ) return false;

	// Nos guardamos los vertices afectados para eliminar luego los innecesarios que hayan quedado
	for ( i = 0; i < nFaces; i++ ) {
		iwFace1 = iwFacesToDisolveAux.GetAt( i );
		iwFace1->GetPolyVertices( iwVertexsAux );
		iwVertexs.Append( iwVertexsAux );
	}
	iwVertexs.RemoveDuplicates( );

	// Disolvemos
	do {
		keep = false;
		for ( i = 0; i < nFaces; i++ ) {
			iwFace1 = iwFacesToDisolveAux.GetAt( i );
			for ( j = i + 1; j < nFaces; j++ ) {
				iwFace2 = iwFacesToDisolveAux.GetAt( j );
				if ( AreAdjacentFaces( iwFace1, iwFace2 ) ) {
					iwEdge = GetEdgeBetweenFaces( iwFace1, iwFace2 );
					iwEdgesNewFace.RemoveAll( );
					if ( GetOrderedEdgesNewFaceFromRemoveEdge( iwEdge, &iwEdgesNewFace ) ) {
						keep = ret = true;
						if ( !addedElements ) InitAddedElements( &addedElementsAux );
						nNewFacesOld = addedElements ? (int) addedElements->iwFaces.GetSize( ) : 0;
						if ( addedElements ) {
							InitAddedElements( &addedElementsOld );
							IncludeToAddedElements( &addedElementsOld, addedElements );
						}
						RemoveEdge( OGLTransf, iwEdge, addedElements ? addedElements : &addedElementsAux, true, true, false );
						nNewFaces = addedElements ? (int) addedElements->iwFaces.GetSize( ) : (int) addedElementsAux.iwFaces.GetSize( );

						if ( ( nNewFaces - nNewFacesOld ) == 0 ) {
							if ( addedElements ) {
								for ( k = 0; k < nNewFacesOld; k++ ) {
									if ( !addedElements->iwFaces.FindElement( addedElementsOld.iwFaces.GetAt( k ), pos ) ) break;
								}
								thereAreNewFaces = ( k != nNewFacesOld );
							} else
								thereAreNewFaces = false;
						} else
							thereAreNewFaces = true;

						if ( !thereAreNewFaces ) {
							// Se han eliminado las dos caras y no se ha podido reparar: se quitan de la lista
							iwFacesToDisolveAux.RemoveAt( j );
							iwFacesToDisolveAux.RemoveAt( i );
							nFaces = (int) iwFacesToDisolveAux.GetSize( );
							if ( nFaces > 0 ) iwFace1 = iwFacesToDisolveAux.GetAt( i );
						} else {
							iwFace1 = addedElements ? addedElements->iwFaces.GetAt( nNewFacesOld ) : addedElementsAux.iwFaces.GetAt( nNewFacesOld );
							iwFacesToDisolveAux.SetAt( i, iwFace1 );
							iwFacesToDisolveAux.RemoveAt( j );
							if ( ( nNewFaces - nNewFacesOld ) > 1 ) {
								// Se ha reparado haciendo uso de FillHoles obteniéndose más de una cara
								for ( k = nNewFacesOld + 1; k < nNewFaces - nNewFacesOld; k++ )
									iwFacesToDisolveAux.Add( addedElements ? addedElements->iwFaces.GetAt( k ) : addedElementsAux.iwFaces.GetAt( k ) );
							}
							nFaces = (int) iwFacesToDisolveAux.GetSize( );
						}
						j = i;
					}
				}
			}
		}
	} while ( keep );

	RemoveUnnecessaryVertexs( OGLTransf, &iwVertexs, angleTolerance, addedElements ? addedElements : &addedElementsAux, false );

	if ( updateTopology ) UpdateTopology( OGLTransf );

	return ret;
}

// =============================================================================
// TPBrepData - Offset
// =============================================================================

//------------------------------------------------------------------------------

// En GetNextCWPolyEdge y GetNextCCWPolyEdge se tienen en cuenta también las aristas que no salen del vértice,
// ya que en los bordes de una malla GetCWPolyEdge y GetCCWPolyEdge pueden devolver NULL
// Para que estas funciones vayan bien es necesario que vertex sea el StartVertex de pEdge
IwPolyEdge *TPBrepData::GetNextCWPolyEdge( IwPolyVertex *vertex, IwPolyEdge *pEdge )
{
	ULONG index, index2;
	IwPolyEdge *edgeNext, *edgeSym;
	IwTA<IwPolyVertex *> vertices;
	IwTA<IwPolyEdge *> edgesStarting, edgesFromFace;
	IwPolyFace *face;

	if ( !pEdge || !vertex ) return NULL;

	if ( !vertex->IsBoundaryVertex( ) ) {
		edgeNext = vertex->GetCWPolyEdge( pEdge );
		return edgeNext;
	}

	if ( !pEdge->IsBoundary( ) ) {
		edgeSym = pEdge->GetSymmetricPolyEdge( );
		face = GetCommonFaceBetweenVertexAndEdge( vertex, edgeSym );
		if ( !face ) return NULL;
		face->GetPolyEdges( edgesFromFace );
		if ( !edgesFromFace.FindElement( edgeSym, index ) ) return NULL;
		edgeNext = edgesFromFace[ index < edgesFromFace.GetSize( ) - 1 ? index + 1 : 0 ];
		return edgeNext;
	}

	face = GetCommonFaceBetweenVertexAndEdge( vertex, pEdge );
	if ( !face ) return NULL;
	face->GetPolyEdges( edgesFromFace );
	if ( !edgesFromFace.FindElement( pEdge, index ) ) return NULL;

	vertex->GetStartingPolyEdges( edgesStarting );
	if ( edgesStarting.FindElement( pEdge, index2 ) ) {
		// La arista empieza en el vertice, asi que en este caso devolvemos NULL
		return NULL;
	} else {
		// La arista acaba en el vertice, asi que buscamos la siguiente en la cara
		edgeNext = edgesFromFace[ index < edgesFromFace.GetSize( ) - 1 ? index + 1 : 0 ];
		return edgeNext;
	}
}

//------------------------------------------------------------------------------

IwPolyEdge *TPBrepData::GetNextCCWPolyEdge( IwPolyVertex *vertex, IwPolyEdge *pEdge )
{
	ULONG index, index2;
	IwPolyEdge *edgeNext;
	IwTA<IwPolyVertex *> vertices;
	IwTA<IwPolyEdge *> allEdges, edgesStarting, edgesFromFace;
	IwPolyFace *face;

	if ( !pEdge || !vertex ) return NULL;

	if ( !vertex->IsBoundaryVertex( ) ) {
		edgeNext = vertex->GetCCWPolyEdge( pEdge );
		return edgeNext;
	}

	if ( !pEdge->IsBoundary( ) ) {
		face = GetCommonFaceBetweenVertexAndEdge( vertex, pEdge );
		if ( !face ) return NULL;
		face->GetPolyEdges( edgesFromFace );
		if ( !edgesFromFace.FindElement( pEdge, index ) ) return NULL;
		edgeNext = edgesFromFace[ index > 0 ? index - 1 : edgesFromFace.GetSize( ) - 1 ];
		return edgeNext;
	}

	face = GetCommonFaceBetweenVertexAndEdge( vertex, pEdge );
	if ( !face ) return NULL;
	face->GetPolyEdges( edgesFromFace );
	if ( !edgesFromFace.FindElement( pEdge, index ) ) return NULL;

	vertex->GetStartingPolyEdges( edgesStarting );
	if ( edgesStarting.FindElement( pEdge, index2 ) ) {
		// La arista empieza en el vertice, asi que buscamos la anterior en la cara
		edgeNext = edgesFromFace[ index > 0 ? index - 1 : edgesFromFace.GetSize( ) - 1 ];
		if ( !edgeNext->IsBoundary( ) ) edgeNext = edgeNext->GetSymmetricPolyEdge( );
		return edgeNext;
	} else
		// La arista acaba en el vertice, asi que en este caso devolvemos NULL
		return NULL;
}

//------------------------------------------------------------------------------

bool TPBrepData::GetOffsetFromRing( IwTA<IwPolyEdge *> *edges, double lenght, bool clockWise, IwTA<IwTA<TMeshElementInfo> > &elements, bool onlyForRedraw, bool force, IwTA<IwPolyEdge *> &edgesForDraw )
{
	bool addedElements, atStart;
	int i, j, k, l, count;
	double param, dist, angle, angle2;
	ULONG index;
	IwPoint3d pointIw;
	IwVector3d vectIw;
	IwPolyVertex *vertexAux, *vertexIni;
	IwPolyEdge *edge1, *edge1Symmetric, *edge2, *edgeAux, *edgeToInsert, *edgeToInsertSymmetric, *firstEdge, *lastEdgeAdded;
	IwTA<IwPolyEdge *> edgesFromVertex, OneRing, edgesFromFace;
	IwTA<IwTA<IwPolyEdge *> > edgesOrdered;
	IwPolyFace *face, *face1, *face2;
	IwTA<IwPolyFace *> faces;
	IwTA<TMeshElementInfo> elementsOneList;
	TMeshElementInfo element;
	TOGLPolygonList outPolList;
	T3DPoint point1, point2, pointOrig;
	T3DVector vect1, vect2, bisec, vectAux;
	T3DPlane pln, plnRot;
	TNRotateMatrix rotMatrix;
	IwBoolean inside;

	if ( !edges || edges->GetSize( ) == 0 ) return false;

	if ( !GetEdgesOrdered( edges, &edgesOrdered ) ) return false;

	elements.RemoveAll( );
	if ( edgesOrdered.GetSize( ) == 0 ) return false;

	// Para el metodo de offset es imprescindible que la lista empiece en una arista que conecte mas de 2 si es un
	// camino cerrado ( para que asi encuentre offset en ambos lados)
	for ( i = 0; i < (int) edgesOrdered.GetSize( ); i++ ) {
		OneRing = edgesOrdered[ i ];
		if ( OneRing.GetSize( ) <= 2 ) continue;
		if ( AreAdjacentEdges( OneRing[ 0 ], OneRing[ OneRing.GetSize( ) - 1 ], atStart ) ) {
			// Es un camino cerrado, buscamos un comienzo valido para el algoritmo
			for ( j = 0; j < (int) OneRing.GetSize( ); j++ ) {
				vertexAux = OneRing[ j ]->GetStartVertex( );
				vertexAux->GetPolyEdges( edgesFromVertex );
				count = 0;
				for ( k = 0; k < (int) edgesFromVertex.GetSize( ); k++ ) {
					if ( edgesFromVertex[ k ]->GetUserIndex1( ) != ULONG_MAX ) count++;
				}
				if ( count > 3 ) {
					if ( j > 0 ) {
						OneRing.RotateArray( j );
						edgesOrdered.SetAt( i, OneRing );
					}
					break;
				}
			}
		}
	}

	if ( onlyForRedraw ) edgesForDraw.RemoveAll( );

	for ( i = 0; i < (int) edgesOrdered.GetSize( ); i++ ) {
		OneRing = edgesOrdered[ i ];

		if ( OneRing.GetSize( ) == 0 ) continue;

		// Primera arista
		edge1 = OneRing[ 0 ];
		vertexIni = edge1->GetStartVertex( );
		vertexAux = edge1->GetEndVertex( ); // Siguiente vertice
		if ( clockWise ) firstEdge = GetNextCCWPolyEdge( vertexIni, edge1 );
		else
			firstEdge = GetNextCWPolyEdge( vertexIni, edge1 );

		if ( !firstEdge ) continue;

		if ( onlyForRedraw ) edgesForDraw.Add( firstEdge );
		FindElement_Edge( &PBrepEdges, firstEdge, index, edgeAux );
		if ( !edgeAux ) continue;

		point1 = T3DPoint( edgeAux->GetStartPoint( ).x, edgeAux->GetStartPoint( ).y, edgeAux->GetStartPoint( ).z );
		point2 = T3DPoint( edgeAux->GetEndPoint( ).x, edgeAux->GetEndPoint( ).y, edgeAux->GetEndPoint( ).z );
		vect1 = point2 - point1;
		if ( edgeAux->GetEndVertex( ) == vertexIni ) vect1.size *= -1;
		vect1 = vect1.Modulo( lenght );
		point1 = T3DPoint( vertexIni->GetPointPtr( )->x, vertexIni->GetPointPtr( )->y, vertexIni->GetPointPtr( )->z ) + vect1.org + vect1.size;
		pointIw = IwPoint3d( point1.x, point1.y, point1.z );
		edgeAux->DropPoint( pointIw, param, dist );
		if ( !force && ( param < RES_GEOM || param > 1 - RES_GEOM ) ) continue;

		edgeAux->EvaluatePoint( param, pointIw );

		element.Type = ElementType::Edge;
		element.Index = edgeAux->GetUserIndex1( );
		element.Point = pointIw;
		element.IndexVertex = vertexIni->GetIndexExt( );
		elementsOneList.Add( element );
		element.IndexVertex = ULONG_MAX;
		lastEdgeAdded = edgeAux;

		edgeAux = edge1->GetSymmetricPolyEdge( );
		if ( !edgeAux ) edgeAux = edge1;

		for ( j = 1; j < (int) OneRing.GetSize( ); j++ ) {
			edge1 = OneRing[ j ];
			if ( !edge1 ) return false;
			edge1Symmetric = edge1->GetSymmetricPolyEdge( );
			addedElements = false;

			edge2 = OneRing[ j - 1 ];
			// Comprobacion de que la arista inicial esta en la lista de aristas del vertice
			vertexAux->GetPolyEdges( edgesFromVertex );
			if ( !FindElement_Edge( &edgesFromVertex, edgeAux, index, edgeAux ) ) return false;
			if ( !edgeAux ) return false;

			// edgeAux empieza siendo la arista anterior del Ring
			firstEdge = 0;
			do {
				if ( clockWise ) edgeAux = GetNextCWPolyEdge( vertexAux, edgeAux );
				else
					edgeAux = GetNextCCWPolyEdge( vertexAux, edgeAux );

				if ( !edgeAux ) return false;

				if ( !firstEdge ) firstEdge = edgeAux;
				else if ( firstEdge == edgeAux ) // Control de seguridad por si no estan bien ordenadas y seguidas las aristas para que no siga
					return false;

				FindElement_Edge( &PBrepEdges, edgeAux, index, edgeToInsert );
				if ( !edgeToInsert ) return false;
				edgeToInsertSymmetric = edgeToInsert->GetSymmetricPolyEdge( );

				if ( edgeToInsertSymmetric != edge1 && edgeToInsert != edge1 ) {
					point1 = T3DPoint( edgeToInsert->GetStartPoint( ).x, edgeToInsert->GetStartPoint( ).y, edgeToInsert->GetStartPoint( ).z );
					point2 = T3DPoint( edgeToInsert->GetEndPoint( ).x, edgeToInsert->GetEndPoint( ).y, edgeToInsert->GetEndPoint( ).z );
					vect1 = point2 - point1;
					if ( edgeToInsert->GetEndVertex( ) == vertexAux ) vect1.size *= -1;
					vect1 = vect1.Modulo( lenght );
					point1 = T3DPoint( vertexAux->GetPointPtr( )->x, vertexAux->GetPointPtr( )->y, vertexAux->GetPointPtr( )->z ) + vect1.org + vect1.size;
					pointIw = IwPoint3d( point1.x, point1.y, point1.z );
					edgeToInsert->DropPoint( pointIw, param, dist );
					if ( !force && ( param < RES_GEOM || param > 1 - RES_GEOM ) ) return false;

					edgeToInsert->EvaluatePoint( param, pointIw );

					if ( onlyForRedraw ) edgesForDraw.Add( edgeAux );
					element.Type = ElementType::Edge;
					element.Index = edgeToInsert->GetUserIndex1( );
					element.Point = pointIw;
					element.IndexVertex = ULONG_MAX;
					elementsOneList.Add( element );
					lastEdgeAdded = edgeToInsert;
					addedElements = true;
				}
			} while ( edgeAux != edge1 && edgeAux != edge1Symmetric );

			if ( !addedElements ) {
				// Ha encontrado un vertice sin arista asi que en este caso tenemos que crear una arista.

				face = 0;
				faces = GetCommonFacesBetweenEdges( edge1, edge2 );
				if ( faces.GetSize( ) == 0 ) return false;
				if ( faces.GetSize( ) > 1 ) {
					if ( lastEdgeAdded ) {
						for ( i = 0; i < (int) faces.GetSize( ); i++ ) {
							if ( IsEdgeFromFace( lastEdgeAdded, faces[ i ], true ) ) face = faces[ i ];
						}
					}
				} else
					face = faces[ 0 ];
				if ( !face ) return false;

				// calculamos la bisectriz entre las 2 aristas que comparten el punto
				point1 = T3DPoint( edge1->GetStartPoint( ).x, edge1->GetStartPoint( ).y, edge1->GetStartPoint( ).z );
				point2 = T3DPoint( edge1->GetEndPoint( ).x, edge1->GetEndPoint( ).y, edge1->GetEndPoint( ).z );
				vect1 = point2 - point1;
				if ( edge1->GetEndVertex( ) == vertexAux ) vect1.size *= -1;
				vect1.Unitario( );
				point1 = T3DPoint( edge2->GetStartPoint( ).x, edge2->GetStartPoint( ).y, edge2->GetStartPoint( ).z );
				point2 = T3DPoint( edge2->GetEndPoint( ).x, edge2->GetEndPoint( ).y, edge2->GetEndPoint( ).z );
				vect2 = point2 - point1;
				if ( edge2->GetEndVertex( ) == vertexAux ) vect2.size *= -1;
				vect2.Unitario( );

				bisec = vect1 + vect2;

				pointOrig = T3DPoint( vertexAux->GetPointPtr( )->x, vertexAux->GetPointPtr( )->y, vertexAux->GetPointPtr( )->z );
				if ( bisec.Modulo( ) > RES_GEOM ) {
					bisec.Unitario( );
					point2 = pointOrig + bisec.size;
					vectIw = IwVector3d( vertexAux->GetPoint( ), IwPoint3d( point2.x, point2.y, point2.z ) );
					vectIw = vectIw.ProjectToPlane( face->GetNormal( ) );

					pointIw = IwPoint3d( pointOrig.x + vectIw.x, pointOrig.y + vectIw.y, pointOrig.z + vectIw.z );
					if ( face->PointInPolygon( pointIw, inside, true ) != IW_SUCCESS || !inside ) {
						vectIw.x *= -1;
						vectIw.y *= -1;
						vectIw.z *= -1;
					}
					point2 = pointOrig + T3DPoint( vectIw.x, vectIw.y, vectIw.z );
				} else {
					pln = T3DPlane( pointOrig, T3DSize( face->GetNormal( ).x, face->GetNormal( ).y, face->GetNormal( ).z ) );
					vectAux = vect1 || pln.normal;
					point2 = pointOrig + vectAux.size;
					vectIw = IwVector3d( vertexAux->GetPoint( ), IwPoint3d( point2.x, point2.y, point2.z ) );
					vectIw = vectIw.ProjectToPlane( face->GetNormal( ) );
					pointIw = IwPoint3d( pointOrig.x + vectIw.x, pointOrig.y + vectIw.y, pointOrig.z + vectIw.z );
					if ( face->PointInPolygon( pointIw, inside, true ) != IW_SUCCESS || !inside ) vectAux.size *= -1;
					point2 = pointOrig + vectAux.size;

					// Tenemos que asegurar que el angulo que hay entre el punto y los dos segmentos es igual
					// Calculamos el plano entre las 2 aristas
					pln = T3DPlane( vect1.org, vect1.org + vect1.size, vect1.org + vect2.size );
					angle = vect1.Angle( vectAux );
					angle2 = vectAux.Angle( vect2 );
					if ( angle > angle2 ) rotMatrix = TNRotateMatrix( angle - angle2, pln.normal );
					else
						rotMatrix = TNRotateMatrix( angle2 - angle, pln.normal );
					point2.ApplyMatrix( rotMatrix );
				}

				vect1 = point2 - pointOrig;
				if ( bisec.Modulo( ) > RES_GEOM ) {
					angle = vect2.Angle( bisec );
					angle = fabs( angle );
					vect1.Modulo( lenght / sin( angle ) );
				} else
					vect1.Modulo( lenght );
				point2 = pointOrig + vect1.size;
				pointIw = IwPoint3d( point2.x, point2.y, point2.z );

				// Añadimos el punto sobre la cara
				element.Type = ElementType::Face;
				element.Index = face->GetIndexExt( );
				element.Point = pointIw;
				element.IndexVertex = vertexAux->GetIndexExt( );
				elementsOneList.Add( element );

				if ( onlyForRedraw ) edgesForDraw.Add( edge1 );
			}

			if ( edge1->GetStartVertex( ) == vertexAux ) {
				vertexAux = edge1->GetEndVertex( );
				edgeAux = edge1->GetSymmetricPolyEdge( );
				if ( !edgeAux ) edgeAux = edge1;
			} else {
				vertexAux = edge1->GetStartVertex( );
				edgeAux = edge1;
			}
		}

		// Ultima arista
		if ( clockWise ) edgeAux = GetNextCWPolyEdge( vertexAux, edgeAux );
		else
			edgeAux = GetNextCCWPolyEdge( vertexAux, edgeAux );
		if ( !edgeAux ) {
			elements.Add( elementsOneList );
			elementsOneList.RemoveAll( );
			continue;
		}

		if ( onlyForRedraw ) edgesForDraw.Add( edgeAux );
		FindElement_Edge( &PBrepEdges, edgeAux, index, edgeToInsert );

		if ( !edgeToInsert ) {
			elements.Add( elementsOneList );
			elementsOneList.RemoveAll( );
			continue;
		}

		point1 = T3DPoint( edgeToInsert->GetStartPoint( ).x, edgeToInsert->GetStartPoint( ).y, edgeToInsert->GetStartPoint( ).z );
		point2 = T3DPoint( edgeToInsert->GetEndPoint( ).x, edgeToInsert->GetEndPoint( ).y, edgeToInsert->GetEndPoint( ).z );
		vect1 = point2 - point1;
		if ( edgeToInsert->GetEndVertex( ) == vertexAux ) vect1.size *= -1;
		vect1 = vect1.Modulo( lenght );
		point1 = T3DPoint( vertexAux->GetPointPtr( )->x, vertexAux->GetPointPtr( )->y, vertexAux->GetPointPtr( )->z ) + vect1.org + vect1.size;
		pointIw = IwPoint3d( point1.x, point1.y, point1.z );
		edgeToInsert->DropPoint( pointIw, param, dist );
		if ( !force && ( param < RES_GEOM || param > 1 - RES_GEOM ) ) return false;
		edgeToInsert->EvaluatePoint( param, pointIw );

		element.Type = ElementType::Edge;
		element.Index = edgeToInsert->GetUserIndex1( );
		element.Point = pointIw;
		element.IndexVertex = vertexAux->GetIndexExt( );
		lastEdgeAdded = edgeToInsert;
		elementsOneList.Add( element );

		// Comprobacion de si hay que cerrar el offset cuando las aristas son adyacentes y el vertice de ambas coincide
		edgeAux = PBrepEdges[ elementsOneList[ 0 ].Index ];
		if ( elementsOneList.GetSize( ) > 2 && element.IndexVertex == elementsOneList[ 0 ].IndexVertex && !AreEqual( edgeToInsert, edgeAux ) ) {
			// Primero de todo borramos el element.IndexVertex para que no incida despues
			elementsOneList[ 0 ].IndexVertex = ULONG_MAX;
			elementsOneList[ elementsOneList.GetSize( ) - 1 ].IndexVertex = ULONG_MAX;
			if ( AreAdjacentEdges( edgeToInsert, edgeAux, atStart ) ) { // Añadir vertice de interseccion

				// Si la cara entre el primer segmento y el ultimo es la misma entonces hay que añadir, sino solo cerramos
				if ( elementsOneList[ 1 ].Type == ElementType::Face ) {
					if ( elementsOneList[ 1 ].Index > PBrepFaces.GetSize( ) - 1 ) return false;
					face1 = PBrepFaces[ elementsOneList[ 1 ].Index ];
				} else {
					if ( elementsOneList[ 1 ].Index > PBrepEdges.GetSize( ) - 1 ) return false;
					edge1 = PBrepEdges[ elementsOneList[ 1 ].Index ];
					FindElement_Edge( &PBrepEdges, edge1, index, edge1 );
					face1 = 0;
					faces = GetCommonFacesBetweenEdges( edgeAux, edge1 );
					if ( faces.GetSize( ) == 0 ) return false;
					if ( faces.GetSize( ) > 1 ) {
						if ( lastEdgeAdded ) {
							for ( i = 0; i < (int) faces.GetSize( ); i++ ) {
								if ( IsEdgeFromFace( lastEdgeAdded, faces[ i ], true ) ) face1 = faces[ i ];
							}
						}
					} else
						face1 = faces[ 0 ];
				}
				if ( elementsOneList[ elementsOneList.GetSize( ) - 2 ].Type == ElementType::Face ) {
					if ( elementsOneList[ elementsOneList.GetSize( ) - 2 ].Index > PBrepFaces.GetSize( ) - 1 ) return false;
					face2 = PBrepFaces[ elementsOneList[ elementsOneList.GetSize( ) - 2 ].Index ];
				} else {
					if ( elementsOneList[ elementsOneList.GetSize( ) - 2 ].Index > PBrepEdges.GetSize( ) - 1 ) return false;
					edge1 = PBrepEdges[ elementsOneList[ elementsOneList.GetSize( ) - 2 ].Index ];
					FindElement_Edge( &PBrepEdges, edge1, index, edge1 );
					face2 = 0;
					faces = GetCommonFacesBetweenEdges( edgeToInsert, edge1 );
					if ( faces.GetSize( ) == 0 ) return false;
					if ( faces.GetSize( ) > 1 ) {
						if ( lastEdgeAdded ) {
							for ( i = 0; i < (int) faces.GetSize( ); i++ ) {
								if ( IsEdgeFromFace( lastEdgeAdded, faces[ i ], true ) ) face2 = faces[ i ];
							}
						}
					} else
						face2 = faces[ 0 ];
				}

				if ( face1 != face2 ) {
					if ( elementsOneList[ 0 ].Type == ElementType::Edge ) {
						// En este caso final es posible que haya mas caras/aristas por enmedio

						// edgeAux empieza siendo la arista anterior del Ring
						// edge1 es la arista hasta la que tiene que llegar

						edge1 = PBrepEdges[ elementsOneList[ 0 ].Index ];
						FindElement_Edge( &PBrepEdges, edge1, index, edge1 );
						edgeAux = lastEdgeAdded;
						if ( edgeAux->GetStartVertex( ) != vertexAux ) edgeAux = edgeAux->GetSymmetricPolyEdge( );
						if ( edgeAux ) {
							firstEdge = 0;
							do {
								if ( clockWise ) edgeAux = GetNextCWPolyEdge( vertexAux, edgeAux );
								else
									edgeAux = GetNextCCWPolyEdge( vertexAux, edgeAux );

								if ( !edgeAux ) return false;

								if ( !firstEdge ) firstEdge = edgeAux;
								else if ( firstEdge == edgeAux ) // Control de seguridad por si no estan bien ordenadas y seguidas las aristas para que no siga
									return false;

								FindElement_Edge( &PBrepEdges, edgeAux, index, edgeToInsert );
								if ( !edgeToInsert ) return false;
								edgeToInsertSymmetric = edgeToInsert->GetSymmetricPolyEdge( );

								if ( edgeToInsertSymmetric != edge1 && edgeToInsert != edge1 ) {
									point1 = T3DPoint( edgeToInsert->GetStartPoint( ).x, edgeToInsert->GetStartPoint( ).y, edgeToInsert->GetStartPoint( ).z );
									point2 = T3DPoint( edgeToInsert->GetEndPoint( ).x, edgeToInsert->GetEndPoint( ).y, edgeToInsert->GetEndPoint( ).z );
									vect1 = point2 - point1;
									if ( edgeToInsert->GetEndVertex( ) == vertexAux ) vect1.size *= -1;
									vect1 = vect1.Modulo( lenght );
									point1 = T3DPoint( vertexAux->GetPointPtr( )->x, vertexAux->GetPointPtr( )->y, vertexAux->GetPointPtr( )->z ) + vect1.org + vect1.size;
									pointIw = IwPoint3d( point1.x, point1.y, point1.z );
									edgeToInsert->DropPoint( pointIw, param, dist );
									if ( !force && ( param < RES_GEOM || param > 1 - RES_GEOM ) ) return false;

									edgeToInsert->EvaluatePoint( param, pointIw );

									if ( onlyForRedraw ) edgesForDraw.Add( edgeAux );
									element.Type = ElementType::Edge;
									element.Index = edgeToInsert->GetUserIndex1( );
									element.Point = pointIw;
									element.IndexVertex = ULONG_MAX;
									elementsOneList.Add( element );
									lastEdgeAdded = edgeToInsert;
									addedElements = true;
								} else
									break; // En este caso final, la arista final salimos del bucle
							} while ( edgeAux != edge1 && edgeAux != edge1Symmetric && edgeAux != lastEdgeAdded );
						}
					}
					elementsOneList.Add( elementsOneList[ 0 ] );
				} else {
					face = 0;
					faces = GetCommonFacesBetweenEdges( edgeToInsert, edgeAux );
					if ( faces.GetSize( ) == 0 ) return false;
					if ( faces.GetSize( ) > 1 ) {
						if ( lastEdgeAdded ) {
							for ( i = 0; i < (int) faces.GetSize( ); i++ ) {
								if ( IsEdgeFromFace( lastEdgeAdded, faces[ i ], true ) ) face = faces[ i ];
							}
						}
					} else
						face = faces[ 0 ];
					if ( !face ) return false;

					// calculamos la bisectriz entre las 2 aristas que comparten el punto
					point1 = T3DPoint( edgeAux->GetStartPoint( ).x, edgeAux->GetStartPoint( ).y, edgeAux->GetStartPoint( ).z );
					point2 = T3DPoint( edgeAux->GetEndPoint( ).x, edgeAux->GetEndPoint( ).y, edgeAux->GetEndPoint( ).z );
					vect1 = point2 - point1;
					if ( edgeAux->GetEndVertex( ) == vertexAux ) vect1.size *= -1;
					vect1.Unitario( );
					point1 = T3DPoint( edgeToInsert->GetStartPoint( ).x, edgeToInsert->GetStartPoint( ).y, edgeToInsert->GetStartPoint( ).z );
					point2 = T3DPoint( edgeToInsert->GetEndPoint( ).x, edgeToInsert->GetEndPoint( ).y, edgeToInsert->GetEndPoint( ).z );
					vect2 = point2 - point1;
					if ( edgeToInsert->GetEndVertex( ) == vertexAux ) vect2.size *= -1;
					vect2.Unitario( );

					bisec = vect1 + vect2;
					pointOrig = T3DPoint( vertexAux->GetPointPtr( )->x, vertexAux->GetPointPtr( )->y, vertexAux->GetPointPtr( )->z );
					if ( bisec.Modulo( ) > RES_GEOM ) {
						bisec.Unitario( );
						point2 = pointOrig + bisec.size;
						vectIw = IwVector3d( vertexAux->GetPoint( ), IwPoint3d( point2.x, point2.y, point2.z ) );
						vectIw = vectIw.ProjectToPlane( face->GetNormal( ) );

						pointIw = IwPoint3d( pointOrig.x + vectIw.x, pointOrig.y + vectIw.y, pointOrig.z + vectIw.z );
						if ( face->PointInPolygon( pointIw, inside, true ) != IW_SUCCESS || !inside ) {
							vectIw.x *= -1;
							vectIw.y *= -1;
							vectIw.z *= -1;
						}

						point2 = pointOrig + T3DPoint( vectIw.x, vectIw.y, vectIw.z );
					} else {
						pln = T3DPlane( pointOrig, T3DSize( face->GetNormal( ).x, face->GetNormal( ).y, face->GetNormal( ).z ) );
						vectAux = vect1 || pln.normal;
						point2 = pointOrig + vectAux.size;
						vectIw = IwVector3d( vertexAux->GetPoint( ), IwPoint3d( point2.x, point2.y, point2.z ) );
						vectIw = vectIw.ProjectToPlane( face->GetNormal( ) );
						pointIw = IwPoint3d( pointOrig.x + vectIw.x, pointOrig.y + vectIw.y, pointOrig.z + vectIw.z );
						if ( face->PointInPolygon( pointIw, inside, true ) != IW_SUCCESS || !inside ) vectAux.size *= -1;
						point2 = pointOrig + vectAux.size;

						// Tenemos que asegurar que el angulo que hay entre el punto y los dos segmentos es igual
						// Calculamos el plano entre las 2 aristas
						pln = T3DPlane( vect1.org, vect1.org + vect1.size, vect1.org + vect2.size );
						vectAux = point2 - vect1.org;
						angle = vect1 ^ vectAux;
						angle2 = vect2 ^ vectAux;
						if ( angle > angle2 ) rotMatrix = TNRotateMatrix( angle - angle2, pln.normal );
						else
							rotMatrix = TNRotateMatrix( angle2 - angle, pln.normal );
						point2.ApplyMatrix( rotMatrix );
					}

					vect1 = point2 - pointOrig;
					if ( bisec.Modulo( ) > RES_GEOM ) {
						angle = vect2.Angle( bisec );
						angle = fabs( angle );
						vect1.Modulo( lenght / sin( angle ) );
					} else
						vect1.Modulo( lenght );
					point2 = pointOrig + vect1.size;
					pointIw = IwPoint3d( point2.x, point2.y, point2.z );

					// quitamos los extremos y añadimos el punto de la cara, aparte nos aseguramos de que el primer y ultimo punto de la lista
					// es una arista y ademas se repite al final
					element.Type = ElementType::Face;
					element.Index = face->GetIndexExt( );
					element.Point = pointIw;
					element.IndexVertex = vertexAux->GetIndexExt( );

					elementsOneList.RemoveAt( 0 );
					elementsOneList.RemoveLast( );

					if ( onlyForRedraw ) edgesForDraw.Add( edgeToInsert );

					for ( l = elementsOneList.GetSize( ) - 1; l >= 0; l-- ) {
						if ( elementsOneList[ l ].Type == ElementType::Edge ) break;
					}
					if ( l > 0 ) {
						elementsOneList.InsertAt( 0, element );
						for ( k = elementsOneList.GetSize( ) - 1; k > l; k-- ) {
							elementsOneList.InsertAt( 0, elementsOneList[ elementsOneList.GetSize( ) - 1 ] );
							elementsOneList.RemoveLast( );
						}
						elementsOneList.Add( elementsOneList[ 0 ] );
					} else
						elementsOneList.InsertAt( 0, element ); // Todos los elementos van a ser puntos sobre una cara
				}
			}
		} else {
			// borramos el element.IndexVertex para que no incida despues
			elementsOneList[ 0 ].IndexVertex = ULONG_MAX;
			elementsOneList[ elementsOneList.GetSize( ) - 1 ].IndexVertex = ULONG_MAX;
		}

		elements.Add( elementsOneList );
		elementsOneList.RemoveAll( );
	}

	return true;
}

//------------------------------------------------------------------------------

bool TPBrepData::FacesToRemoveVertex( TOGLTransf *OGLTransf, IwPolyVertex *vertexToDelete, IwPolyVertex *vertexToKeep, IwTA<IwPolyFace *> *faces, IwTA<IwTA<IwPolyFace *> > *facesR )
{
	int i, j;
	IwPolyVertex *vertex;
	IwPolyFace *faceToDelete;
	IwTA<IwPolyVertex *> vertexs;
	IwTA<IwPolyFace *> facesOut;
	TMeshElementInfo element;
	IwTA<TMeshElementInfo> elements;

	if ( !OGLTransf || !vertexToDelete || !faces || !facesR ) return false;
	if ( faces->GetSize( ) <= 0 ) return false;

	for ( i = 0; i < (int) faces->GetSize( ); i++ ) {
		faceToDelete = faces->GetAt( i );
		faceToDelete->GetPolyVertices( vertexs );
		if ( vertexs.GetSize( ) > 2 ) {
			for ( j = 0; j < (int) vertexs.GetSize( ); j++ ) {
				vertex = vertexs[ j ];
				if ( vertex != vertexToDelete ) {
					element.Type = ElementType::Vertex;
					element.Index = vertex->GetIndexExt( );
					elements.Add( element );
				}
			}
		}
		if ( faceToDelete->GetUserIndex1( ) >= 1 ) CreateFaceFromCurrentMeshElementList( OGLTransf, &elements, &facesOut, true, faceToDelete->GetUserIndex1( ) );
		if ( facesOut.GetSize( ) > 0 ) facesR->Add( facesOut );
		facesOut.RemoveAll( );
		elements.RemoveAll( );
	}
	if ( facesR->GetSize( ) <= 0 ) return false;
	return true;
}

//------------------------------------------------------------------------------

bool TPBrepData::FacesToReplaceVertex( TOGLTransf *OGLTransf, IwPolyVertex *vertexToDelete, IwPolyVertex *vertexToKeep, IwTA<IwPolyFace *> *faces, IwTA<IwTA<IwPolyFace *> > *facesR, bool borderFaces )
{
	int i, j;
	T3DPoint point;
	IwPolyVertex *vertex;
	IwPolyFace *faceToDelete;
	IwTA<IwPolyVertex *> vertexs;
	IwTA<IwPolyFace *> facesOut;
	TMeshElementInfo element;
	IwTA<TMeshElementInfo> elements;

	if ( !OGLTransf || !vertexToDelete || !vertexToKeep || !faces || !facesR ) return false;
	if ( faces->GetSize( ) <= 0 ) return false;

	for ( i = 0; i < (int) faces->GetSize( ); i++ ) {
		faceToDelete = faces->GetAt( i );
		faceToDelete->GetPolyVertices( vertexs );
		if ( vertexs.GetSize( ) <= 0 ) return false;

		for ( j = 0; j < (int) vertexs.GetSize( ); j++ ) {
			vertex = vertexs[ j ];
			if ( vertex != vertexToDelete ) {
				element.Type = ElementType::Vertex;
				element.Index = vertex->GetIndexExt( );
				point = T3DPoint( vertex->GetPointPtr( )->x, vertex->GetPointPtr( )->y, vertex->GetPointPtr( )->z );
				element.Point = IwPoint3d( point.x, point.y, point.z );
				elements.Add( element );
			} else {
				element.Type = ElementType::Vertex;
				element.Index = vertexToKeep->GetIndexExt( );
				point = T3DPoint( vertexToKeep->GetPointPtr( )->x, vertexToKeep->GetPointPtr( )->y, vertexToKeep->GetPointPtr( )->z );
				element.Point = IwPoint3d( point.x, point.y, point.z );
				elements.Add( element );
			}
		}
		if ( faceToDelete->GetUserIndex1( ) >= 1 || borderFaces || vertexToDelete->IsBoundaryVertex( ) ) CreateFaceFromCurrentMeshElementList( OGLTransf, &elements, &facesOut, true, faceToDelete->GetUserIndex1( ) );
		if ( facesOut.GetSize( ) > 0 ) facesR->Add( facesOut );
		facesOut.RemoveAll( );
		elements.RemoveAll( );
	}
	return true;
}

//==============================================================================
// TPBrepData - Funciones genéricas
//==============================================================================

bool TPBrepData::IsTopologyDirty( )
{
	TCadDepMesh *depMesh;

	if ( !RefEnt || !RefEnt->GetDepMeshes( ) || RefEnt->GetDepMeshes( )->Count( ) < 1 ) return false;

	depMesh = ToDepMesh( RefEnt->GetDepMeshes( )->GetShape( 0 ) );
	if ( depMesh && depMesh->IsSubdivisionDepMesh( ) ) return depMesh->GetSubdivisionData( )->RecalcTopology;

	return false;
}

//------------------------------------------------------------------------------

bool TPBrepData::IsDataSubdivisionDirty( )
{
	TCadDepMesh *depMesh;

	if ( !RefEnt || !RefEnt->GetDepMeshes( ) || RefEnt->GetDepMeshes( )->Count( ) < 1 ) return false;

	depMesh = ToDepMesh( RefEnt->GetDepMeshes( )->GetShape( 0 ) );
	if ( depMesh && depMesh->IsSubdivisionDepMesh( ) ) return depMesh->GetSubdivisionData( )->RebuildFromLevel0;

	return false;
}

//------------------------------------------------------------------------------

void TPBrepData::SetTopologyDirty( bool dirty )
{
	TCadDepMesh *depMesh;
	TSubdivisionData data;

	if ( !RefEnt || !RefEnt->GetDepMeshes( ) || RefEnt->GetDepMeshes( )->Count( ) < 1 ) return;

	depMesh = ToDepMesh( RefEnt->GetDepMeshes( )->GetShape( 0 ) );
	if ( depMesh && depMesh->IsSubdivisionDepMesh( ) ) {
		data.Set( depMesh->GetSubdivisionData( ) );
		data.RecalcTopology = dirty;
		depMesh->SetSubdivisionData( &data );
	}
}

//------------------------------------------------------------------------------

void TPBrepData::SetDataSubdivisionDirty( TOGLTransf *OGLTransf, bool dirty )
{
	TCadDepMesh *depMesh;
	TSubdivisionData data;
	IwTA<IwTA<IwPolyEdge *> > creaselist;
	IwTA<IwTA<IwPolyFace *> > faces1, faces2;

	if ( !RefEnt || !RefEnt->GetDepMeshes( ) || RefEnt->GetDepMeshes( )->Count( ) < 1 ) return;

	depMesh = ToDepMesh( RefEnt->GetDepMeshes( )->GetShape( 0 ) );
	if ( depMesh && depMesh->IsSubdivisionDepMesh( ) ) {
		data.Set( depMesh->GetSubdivisionData( ) );
		data.RebuildFromLevel0 = dirty;
		GetGroupsOfFacesFromCreaseSharps( OGLTransf, &creaselist, &faces1, &faces2 ); // Actualizamos el marcado de caras para el calculo correcto de las normales
		data.CreaseList.RemoveAll( );
		data.GroupsOfFaces1.RemoveAll( );
		data.GroupsOfFaces2.RemoveAll( );
		data.CreaseList = creaselist;
		data.GroupsOfFaces1 = faces1;
		data.GroupsOfFaces2 = faces2;
		depMesh->SetSubdivisionData( &data );
	}
}

TColor TPBrepData::GetColorForFace( )
{
	return AuxEntityColor[ 0 ];
}

//------------------------------------------------------------------------------

TColor TPBrepData::GetColorForEdge( )
{
	return AuxEntityColor[ 1 ];
}

//------------------------------------------------------------------------------

TColor TPBrepData::GetColorForVertex( )
{
	return AuxEntityColor[ 2 ];
}
//------------------------------------------------------------------------------

TColor TPBrepData::GetColorForSelection( )
{
	return AuxEntityColor[ 3 ];
}
//---------------------------------------------------------------------------

TColor TPBrepData::GetColorForSeam( )
{
	return AuxEntityColor[ 4 ];
}

//---------------------------------------------------------------------------

void TPBrepData::GetSelectedInteger_List( TOGLTransf *OGLTransf, TInteger_List *list, ElementType type )
{
	int *selectedlist, i, num, value;

	if ( !OGLTransf || !list || type == ElementType::Undefined ) return;

	if ( type == ElementType::Vertex ) selectedlist = GetVertexs( OGLTransf, SelectedElementType::AllSelected, num );
	else if ( type == ElementType::Edge )
		selectedlist = GetEdges( OGLTransf, SelectedElementType::AllSelected, num );
	else
		selectedlist = GetFaces( OGLTransf, SelectedElementType::AllSelected, num );

	list->Clear( );
	if ( selectedlist ) {
		for ( i = 0; i < num; i++ ) {
			value = selectedlist[ i ];
			list->AddItem( &value );
			value = ( type == ElementType::Vertex ) ? SelectedV[ value ].i : ( type == ElementType::Edge ) ? SelectedE[ value ] : SelectedF[ value ].i;
			list->AddItem( &value );
		}
		delete[] selectedlist;
	}
}

//---------------------------------------------------------------------------

void TPBrepData::SetSelectedInteger_List( TOGLTransf *OGLTransf, TInteger_List *list, ElementType type, bool unSelectPrev )
{
	int i, num;
	bool select;

	if ( !OGLTransf || !list || type == ElementType::Undefined ) return;

	if ( unSelectPrev ) {
		if ( type == ElementType::Vertex ) UnSelectAllVertexs( OGLTransf );
		else if ( type == ElementType::Edge )
			UnSelectAllEdges( OGLTransf );
		else
			UnSelectAllFaces( OGLTransf );
	}

	num = list->Count( );
	if ( type == ElementType::Vertex ) {
		for ( i = 0; i < num; i = i + 2 ) {
			select = ( (SelectedElementType) *list->GetItem( i + 1 ) ) != SelectedElementType::NoSelected;
			select ? SelectVertex( OGLTransf, *list->GetItem( i ), (SelectedElementType) *list->GetItem( i + 1 ) ) : UnSelectVertex( OGLTransf, *list->GetItem( i ) );
		}
	} else if ( type == ElementType::Edge ) {
		for ( i = 0; i < num; i = i + 2 ) {
			select = ( (SelectedElementType) *list->GetItem( i + 1 ) ) != SelectedElementType::NoSelected;
			select ? SelectEdge( OGLTransf, *list->GetItem( i ), (SelectedElementType) *list->GetItem( i + 1 ) ) : UnSelectEdge( OGLTransf, *list->GetItem( i ) );
		}
	} else {
		for ( i = 0; i < num; i = i + 2 ) {
			select = ( (SelectedElementType) *list->GetItem( i + 1 ) ) != SelectedElementType::NoSelected;
			select ? SelectFace( OGLTransf, *list->GetItem( i ), (SelectedElementType) *list->GetItem( i + 1 ) ) : UnSelectFace( OGLTransf, *list->GetItem( i ) );
		}
	}
}

//---------------------------------------------------------------------------

int TPBrepData::GetSeamListIndex( int index )
{
	int i;

	if ( !CountPBrepSeams( ) ) return -1;

	for ( i = 0; i < (int) SeamEdges.GetSize( ); i++ )
		if ( (int) SeamEdges[ i ]->GetUserIndex1( ) == index ) return i;

	return -1;
}

//---------------------------------------------------------------------------

int TPBrepData::GetNearestEdgeToPoint( TOGLTransf *OGLTransf, int indexFace, T3DPoint point )
{
	int nEdges, i;
	double dist, minDist;
	ULONG indexEdge;
	IwPoint3d ptVertex;
	IwPolyEdge *iwEdge, *iwSymEdge;
	IwPolyFace *iwFace;
	IwTA<IwPolyEdge *> iwEdgesFace;
	T3DPoint pt3D_1, pt3D_2;

	if ( !OGLTransf || indexFace < 0 || indexFace >= (int) PBrepFaces.GetSize( ) ) return -1;

	iwFace = GetPBrepFace( OGLTransf, indexFace );
	if ( !iwFace ) return -1;

	iwFace->GetPolyEdges( iwEdgesFace );
	nEdges = iwEdgesFace.GetSize( );
	minDist = MAXDOUBLE;
	for ( i = 0; i < nEdges; i++ ) {
		iwEdge = iwEdgesFace.GetAt( i );
		ptVertex = iwEdge->GetStartPoint( );
		pt3D_1 = T3DPoint( ptVertex.x, ptVertex.y, ptVertex.z );
		ptVertex = iwEdge->GetEndPoint( );
		pt3D_2 = T3DPoint( ptVertex.x, ptVertex.y, ptVertex.z );
		dist = DistanceToSegment( pt3D_1, pt3D_2, point );
		if ( dist < minDist ) {
			minDist = dist;
			indexEdge = iwEdge->GetUserIndex1( );
			if ( indexEdge == ULONG_MAX ) {
				iwSymEdge = iwEdge->GetSymmetricPolyEdge( );
				indexEdge = iwSymEdge ? (int) iwSymEdge->GetUserIndex1( ) : ULONG_MAX;
			}
		}
	}
	return ( indexEdge != ULONG_MAX ) ? (int) indexEdge : -1;
}

// Lista de vertices aislados
void TPBrepData::GetIsolatedVertexs( TInteger_List *IsolatedVertexsIndexs, double angle )
{
	int i, j, nVertexs, nEdges, isolatedVertexIndex, countEdges, count;
	double anglerad, angleaux;
	IwTA<IwPolyEdge *> edgesAux, edgesAux1;
	IwTA<IwPolyFace *> faces;
	IwPolyVertex *isolatedVertex;
	IwPolyEdge *isolatedEdge;
	IwVector3d vector1, vector2;

	if ( !IsolatedVertexsIndexs ) return;

	nVertexs = (int) PBrepVertexs.GetSize( );

	for ( i = 0; i < nVertexs; i++ ) {
		isolatedVertex = PBrepVertexs[ i ];
		if ( !isolatedVertex ) continue;
		count = 0;
		faces = GetConnectedFacesFromVertex( isolatedVertex->GetIndexExt( ) );
		for ( j = 0; j < (int) faces.GetSize( ); j++ )
			if ( faces[ j ]->IsTriangle( ) ) count++;
		if ( count > 0 ) continue;
		isolatedVertex->GetPolyEdges( edgesAux );

		nEdges = (int) edgesAux.GetSize( );
		if ( nEdges <= 4 ) {
			countEdges = 0;
			for ( j = 0; j < nEdges; j++ ) {
				isolatedEdge = edgesAux[ j ];
				if ( !isolatedEdge ) continue;
				if ( isolatedEdge->GetUserIndex1( ) != ULONG_MAX ) {
					edgesAux1.Add( isolatedEdge );
					countEdges++;
				}
			}
			isolatedVertexIndex = isolatedVertex->GetIndexExt( );

			angleaux = angle * ( M_PI / 180 );

			if ( countEdges == 2 ) {
				// Comprobacion del angulo.
				vector1 = edgesAux[ 0 ]->GetStartPoint( ) - edgesAux[ 0 ]->GetEndPoint( );
				vector2 = edgesAux[ 1 ]->GetEndPoint( ) - edgesAux[ 1 ]->GetStartPoint( );
				vector1.AngleBetween( vector2, anglerad );

				if ( anglerad >= angleaux || angle == 180 ) {
					IsolatedVertexsIndexs->AddItem( &isolatedVertexIndex );
					if ( !IsolatedVertexsIndexs ) continue;
				}
			}
		}
	}
}

//---------------------------------------------------------------------------

void TPBrepData::AlignList( TOGLTransf *OGLTransf, ElementType eType, TNPlane plane, TInteger_List *elements, int refElement, int *nElem, int **idElem, T3DPoint **points, bool updateOGLList )
{
	int i, j, indice;
	float x, y, z, incr;
	IwTA<IwPolyVertex *> auxvertexs, vertexs;
	IwPolyVertex *refVertex, *vertex;
	IwPolyEdge *refEdge;
	IwPolyFace *refFace, *face;
	IwVector3d new_p;
	T3DPoint centroid;
	T3DVector normalAux;

	if ( !OGLTransf || !RefEnt || !elements || plane == plNone ) return;
	if ( eType != ElementType::Vertex && eType != ElementType::Edge && eType != ElementType::Face ) return;

	( *nElem ) = 0;
	( *idElem ) = 0;
	( *points ) = 0;

	if ( eType == ElementType::Vertex ) {
		if ( refElement < 0 || refElement >= (int) PBrepVertexs.GetSize( ) ) return;
		// referencia de vertice para alinear la seleccion
		refVertex = PBrepVertexs[ refElement ];
		if ( !refVertex ) return;

		*nElem = elements->Count( );
		( *idElem ) = new int[ *nElem ];
		( *points ) = new T3DPoint[ *nElem ];
		// Alineacion de vertices con referencia a otro vertice
		for ( i = 0; i < elements->Count( ); i++ ) {
			indice = *( elements->GetItem( i ) );
			( *idElem )[ i ] = indice;
			if ( PBrepVertexs[ indice ] != refVertex ) {
				x = PBrepVertexs[ indice ]->GetPoint( ).x;
				y = PBrepVertexs[ indice ]->GetPoint( ).y;
				z = PBrepVertexs[ indice ]->GetPoint( ).z;
				( *points )[ i ] = T3DPoint( x, y, z );
				switch ( plane ) {
					case plXY:
						incr = refVertex->GetPoint( ).z;
						new_p.Set( x, y, incr );
						break;
					case plXZ:
						incr = refVertex->GetPoint( ).y;
						new_p.Set( x, incr, z );
						break;
					case plYZ:
						incr = refVertex->GetPoint( ).x;
						new_p.Set( incr, y, z );
						break;
					default: new_p.Set( x, y, z ); break;
				}
				PBrepVertexs[ indice ]->SetPoint( new_p );
			}
		}
		if ( updateOGLList && RefEnt ) RefEnt->UpdateOGLListFromPBrep( OGLTransf, true );

	} else if ( eType == ElementType::Edge ) {
		if ( refElement < 0 || refElement >= (int) PBrepEdges.GetSize( ) ) return;
		// Vertice de referencia para alinear la seleccion
		refEdge = PBrepEdges[ refElement ];
		if ( !refEdge ) return;
		centroid = GetSubdivisionCentroidFromEdge( OGLTransf, refEdge, &normalAux );

		// Se obtiene y selecciona los vertices correspondiente a las aristas seleccionadas
		for ( i = 0; i < elements->Count( ); i++ ) {
			indice = *( elements->GetItem( i ) );
			vertex = PBrepEdges[ indice ]->GetStartVertex( );
			if ( !vertex ) return;
			auxvertexs.Add( vertex );

			vertex = PBrepEdges[ indice ]->GetEndVertex( );
			if ( !vertex ) return;
			auxvertexs.Add( vertex );
		}

		// Alineacion de vertices a partir del centroide de una arista de referencia.
		*nElem = (int) auxvertexs.GetSize( );
		( *idElem ) = new int[ *nElem ];
		( *points ) = new T3DPoint[ *nElem ];
		for ( i = 0; i < (int) auxvertexs.GetSize( ); i++ ) {
			( *idElem )[ i ] = auxvertexs[ i ]->GetIndexExt( );
			x = auxvertexs[ i ]->GetPoint( ).x;
			y = auxvertexs[ i ]->GetPoint( ).y;
			z = auxvertexs[ i ]->GetPoint( ).z;
			( *points )[ i ] = T3DPoint( x, y, z );
			switch ( plane ) {
				case plXY:
					incr = centroid.z;
					new_p.Set( x, y, incr );
					break;
				case plXZ:
					incr = centroid.y;
					new_p.Set( x, incr, z );
					break;
				case plYZ:
					incr = centroid.x;
					new_p.Set( incr, y, z );
					break;
				default: new_p.Set( x, y, z ); break;
			}
			auxvertexs[ i ]->SetPoint( new_p );
		}

		if ( updateOGLList && RefEnt ) RefEnt->UpdateOGLListFromPBrep( OGLTransf );

	} else if ( eType == ElementType::Face ) {
		if ( refElement < 0 || refElement >= (int) PBrepFaces.GetSize( ) ) return;
		// cara de referencia para alinear la seleccion
		refFace = PBrepFaces[ refElement ];
		if ( !refFace ) return;
		centroid = GetSubdivisionCentroidFromFace( OGLTransf, refFace, &normalAux );

		// Se obtiene y selecciona los vertices que componen las caras
		for ( i = 0; i < elements->Count( ); i++ ) {
			indice = *( elements->GetItem( i ) );
			face = PBrepFaces[ indice ];
			if ( !face ) return;
			face->GetPolyVertices( vertexs );
			for ( j = 0; j < (int) vertexs.GetSize( ); j++ )
				auxvertexs.Add( vertexs[ j ] );
		}
		// Alineacion de vertices a partir del centroide de una cara de referencia
		*nElem = (int) auxvertexs.GetSize( );
		( *idElem ) = new int[ *nElem ];
		( *points ) = new T3DPoint[ *nElem ];
		for ( i = 0; i < (int) auxvertexs.GetSize( ); i++ ) {
			( *idElem )[ i ] = auxvertexs[ i ]->GetIndexExt( );
			x = auxvertexs[ i ]->GetPoint( ).x;
			y = auxvertexs[ i ]->GetPoint( ).y;
			z = auxvertexs[ i ]->GetPoint( ).z;
			( *points )[ i ] = T3DPoint( x, y, z );
			switch ( plane ) {
				case plXY:
					incr = centroid.z;
					new_p.Set( x, y, incr );
					break;
				case plXZ:
					incr = centroid.y;
					new_p.Set( x, incr, z );
					break;
				case plYZ:
					incr = centroid.x;
					new_p.Set( incr, y, z );
					break;
				default: new_p.Set( x, y, z ); break;
			}
			auxvertexs[ i ]->SetPoint( new_p );
		}

		if ( updateOGLList && RefEnt ) RefEnt->UpdateOGLListFromPBrep( OGLTransf );
	}
}

//---------------------------------------------------------------------------

int TPBrepData::GetOppositeEdgeFace( TOGLTransf *OGLTransf, int indexFace, int indexEdge )
{
	int i, nEdges;
	ULONG userIndex;
	IwPolyEdge *iwEdge;
	IwPolyFace *iwFace;
	IwTA<IwPolyEdge *> iwEdgesFace;

	if ( !OGLTransf || indexFace < 0 || indexEdge < 0 ) return -1;
	iwFace = GetPBrepFace( OGLTransf, indexFace );
	if ( !iwFace ) return -1;

	iwFace->GetPolyEdges( iwEdgesFace );
	nEdges = (int) iwEdgesFace.GetSize( );
	if ( ( nEdges % 2 ) != 0 ) return -1;

	for ( i = 0; i < nEdges; i++ ) {
		iwEdge = iwEdgesFace.GetAt( i );
		userIndex = (int) iwEdge->GetUserIndex1( );
		if ( userIndex == ULONG_MAX ) {
			iwEdge = iwEdge->GetSymmetricPolyEdge( );
			userIndex = iwEdge ? (int) iwEdge->GetUserIndex1( ) : ULONG_MAX;
		}
		if ( (int) userIndex == indexEdge ) break;
	}
	if ( i == nEdges ) return -1;

	i = ( i + ( nEdges / 2 ) ) % nEdges;
	iwEdge = iwEdgesFace.GetAt( i );
	userIndex = iwEdge->GetUserIndex1( );
	if ( userIndex == ULONG_MAX ) {
		iwEdge = iwEdge->GetSymmetricPolyEdge( );
		userIndex = iwEdge ? iwEdge->GetUserIndex1( ) : -1;
	}

	return (int) userIndex;
}

//---------------------------------------------------------------------------

bool TPBrepData::IsQuadFace( TOGLTransf *OGLTransf, int indexFace )
{
	IwPolyFace *iwFace;
	IwTA<IwPolyEdge *> iwEdgesFace;

	if ( !OGLTransf || indexFace < 0 ) return false;
	iwFace = GetPBrepFace( OGLTransf, indexFace );
	if ( !iwFace ) return false;

	iwFace->GetPolyEdges( iwEdgesFace );
	return ( (int) iwEdgesFace.GetSize( ) == 4 );
}

//---------------------------------------------------------------------------
// type->0: Para distancia geométrica.
// type->1: Para distancia topológica.
bool TPBrepData::GetShortPathBetweenEdges( TOGLTransf *OGLTransf, int indexEdgeStart, int indexEdgeEnd, int type )
{
	IwPolyVertex *vs, *ve;
	IwPolyEdge *edgeStart, *edgeEnd;
	IwTA<IwPolyVertex *> vertexsStart, vertexsEnd;
	TDataVertexInfo v;
	IwTA<TDataVertexInfo> path, correctPath;
	IwTA<IwTA<TDataVertexInfo> > listPaths;
	int i, j, ieTest, iStart;
	double minDistance;

	if ( !OGLTransf || indexEdgeStart < 0 || indexEdgeEnd < 0 || indexEdgeStart >= (int) PBrepEdges.GetSize( ) || indexEdgeEnd >= (int) PBrepEdges.GetSize( ) ) return false;
	edgeStart = PBrepEdges[ indexEdgeStart ];
	edgeEnd = PBrepEdges[ indexEdgeEnd ];
	if ( !edgeStart || !edgeEnd ) return false;

	vertexsStart.Add( edgeStart->GetStartVertex( ) );
	vertexsStart.Add( edgeStart->GetEndVertex( ) );
	vertexsEnd.Add( edgeEnd->GetStartVertex( ) );
	vertexsEnd.Add( edgeEnd->GetEndVertex( ) );

	// Obtenemos los caminos mínimos entre todos los vértices de cada arista.
	for ( i = 0; i < (int) vertexsStart.GetSize( ); i++ ) {
		vs = vertexsStart[ i ];
		for ( j = 0; j < (int) vertexsEnd.GetSize( ); j++ ) {
			ve = vertexsEnd[ j ];
			if ( type == 0 && DistancePathBetweenVertexs( vs, ve, &path ) ) listPaths.Add( path );
			else if ( type == 1 && TopologyDistancePathBetweenVertexs( vs, ve, &path ) )
				listPaths.Add( path );
			path.RemoveAll( );
		}
	}
	minDistance = MAX_RES_1_PARAM; // Inicializamos con un valor muy alto.
	for ( i = 0; i < (int) listPaths.GetSize( ); i++ ) {
		path = listPaths[ i ];
		for ( j = 0; j < (int) vertexsEnd.GetSize( ); j++ ) {
			ieTest = vertexsEnd[ j ]->GetIndexExt( );
			if ( type == 0 ) {
				if ( path[ ieTest ].weight < minDistance && path[ ieTest ].indFather != -1 ) {
					minDistance = path[ ieTest ].weight;
					correctPath = path;
					iStart = ieTest;
				}
			} else if ( type == 1 ) {
				if ( path[ ieTest ].nEdges < minDistance && path[ ieTest ].indFather != -1 ) {
					minDistance = path[ ieTest ].nEdges;
					correctPath = path;
					iStart = ieTest;
				} else if ( path[ ieTest ].nEdges == minDistance ) {
					if ( path[ ieTest ].weight < correctPath[ ieTest ].weight ) {
						minDistance = path[ ieTest ].nEdges;
						correctPath = path;
						iStart = ieTest;
					}
				}
			}
		}
	}

	while ( iStart != -1 ) { // Seleccionamos las aristas entre el origen y el destino.
		if ( iStart < 0 || iStart >= (int) correctPath.GetSize( ) ) return false;
		v = correctPath[ iStart ];
		if ( v.indEdge != indexEdgeStart && v.indEdge != indexEdgeEnd ) SelectEdge( OGLTransf, v.indEdge, SelectedElementType::LoopSelection );
		iStart = v.indFather;
	}

	return true;
}

//---------------------------------------------------------------------------

// Devuelve la lista de caras que forman un camino entre dos caras seleccionadas
// vertexStart = Vértice por la que se va a iniciar a buscar el camino
// vertexEnd = Vértice a la que se quiere llegar por el camino
// rPath = lista de vértices a devolver si encuentra un camino válido
// shortPathByElements = Indice de la lista que tiene menos elementos.
bool TPBrepData::DistancePathBetweenVertexs( IwPolyVertex *vertexStart, IwPolyVertex *vertexEnd, IwTA<TDataVertexInfo> *vertexsToTest )
{
	bool found;
	int i, iRemov, ivAdjacent, iInsert, ivFather;
	double val;
	IwPolyVertex *vFather, *vAdjacent;
	IwPolyEdge *e;
	TDataVertexInfo vertexFatherData, vertexAdjData;
	IwTA<IwPolyEdge *> edges;
	IwTA<TDataVertexInfo> priority;

	if ( !vertexStart || !vertexEnd ) return false;

	// Inicializamos el vértice inicial.
	InitUserIndex1( true, false );
	vertexsToTest->SetSize( PBrepVertexs.GetSize( ) );
	vertexFatherData.ind = vertexStart->GetIndexExt( );
	vertexFatherData.weight = 0;
	priority.Add( vertexFatherData );

	while ( priority.GetSize( ) > 0 ) {
		vertexFatherData = priority.GetLast( );
		ivFather = vertexFatherData.ind;
		vFather = PBrepVertexs[ ivFather ];
		if ( !vFather ) return false;
		priority.RemoveLast( );
		if ( vFather->GetUserIndex1( ) == 1 ) continue;
		vFather->SetUserIndex1( 1 );
		vFather->GetPolyEdges( edges );

		for ( i = 0; i < (int) edges.GetSize( ); i++ ) {
			e = edges[ i ];
			if ( e->GetUserIndex1( ) == ULONG_MAX ) continue;
			vAdjacent = e->GetOtherVertex( vFather );
			if ( !vAdjacent ) return false;
			if ( vAdjacent->GetUserIndex1( ) == 1 ) continue;
			val = e->Length( );
			ivAdjacent = vAdjacent->GetIndexExt( );
			vertexAdjData = vertexsToTest->GetAt( ivAdjacent );

			// Comprobamos si ha encontrado un camino más corto.
			if ( vertexFatherData.weight + val < vertexAdjData.weight ) {
				vertexAdjData.weight = vertexFatherData.weight + val;
				vertexAdjData.indFather = vertexFatherData.ind;
				vertexAdjData.indEdge = e->GetUserIndex1( );
				vertexAdjData.ind = ivAdjacent;
				vertexsToTest->SetAt( ivAdjacent, vertexAdjData );

				// Comprobar si el vértice adyacente ya está en la lista de prioridad para ordenarlo
				for ( iRemov = 0; iRemov < (int) priority.GetSize( ); iRemov++ ) {
					if ( priority[ iRemov ].ind == vertexAdjData.ind ) {
						priority.RemoveAt( iRemov );
						break;
					}
				}
				// Insertamos el vértice ordenado.
				found = false;
				for ( iInsert = 0; iInsert < (int) priority.GetSize( ); iInsert++ )
					if ( priority[ iInsert ].weight < vertexAdjData.weight ) {
						found = true;
						break;
					}
				if ( found || priority.GetSize( ) == 1 ) priority.InsertAt( iInsert, vertexAdjData );
				else
					priority.Add( vertexAdjData );
			}
		}
		if ( vFather == vertexEnd ) break;
	}

	InitUserIndex1( true, false );
	return true;
}

//---------------------------------------------------------------------------

bool TPBrepData::TopologyDistancePathBetweenVertexs( IwPolyVertex *vertexStart, IwPolyVertex *vertexEnd, IwTA<TDataVertexInfo> *vertexsToTest )
{
	bool sumedge, found;
	int i, iRemov, ivAdjacent, iInsert, ivFather;
	double val;
	IwPolyVertex *vFather, *vAdjacent;
	IwPolyEdge *e;
	TDataVertexInfo vertexFatherData, vertexAdjData;
	IwTA<IwPolyEdge *> edges;
	IwTA<TDataVertexInfo> parentVertexs, childVertexs;

	if ( !vertexStart || !vertexEnd ) return false;

	// Inicializamos el vértice inicial.
	vertexsToTest->RemoveAll( );
	vertexsToTest->SetSize( PBrepVertexs.GetSize( ) );
	InitUserIndex1( true, false ); // 1: Marcar como padre ; -1: Marcar como hijo.
	vertexFatherData.ind = vertexStart->GetIndexExt( );
	vertexFatherData.weight = 0;
	vertexFatherData.nEdges = 0;
	parentVertexs.Add( vertexFatherData );

	while ( parentVertexs.GetSize( ) > 0 ) {
		vertexFatherData = parentVertexs.GetLast( );
		ivFather = vertexFatherData.ind;
		vFather = PBrepVertexs[ ivFather ];
		if ( !vFather ) return false;
		parentVertexs.RemoveLast( );
		if ( vFather->GetUserIndex1( ) == 1 ) continue;
		vFather->SetUserIndex1( 1 );
		vFather->GetPolyEdges( edges );

		for ( i = 0; i < (int) edges.GetSize( ); i++ ) {
			e = edges[ i ];
			if ( e->GetUserIndex1( ) == ULONG_MAX ) continue;
			vAdjacent = e->GetOtherVertex( vFather );
			if ( !vAdjacent ) return false;
			val = e->Length( );
			ivAdjacent = vAdjacent->GetIndexExt( );
			vertexAdjData = vertexsToTest->GetAt( ivAdjacent );

			sumedge = true;
			found = false;
			if ( vertexFatherData.nEdges + 1 == vertexAdjData.nEdges ) { // Si la cantidad de aristas es igual no importa si es padre o hijo.
				found = true;
				if ( vertexFatherData.weight + val < vertexAdjData.weight ) {
					vertexAdjData.weight = vertexFatherData.weight + val;
					vertexAdjData.indEdge = e->GetUserIndex1( );
					vertexAdjData.indFather = vertexFatherData.ind;
					sumedge = false;
				}
			} else if ( (int) vAdjacent->GetUserIndex1( ) == 1 || (int) vAdjacent->GetUserIndex1( ) == -1 )
				continue;

			if ( sumedge && !found ) {
				vertexAdjData.indFather = vertexFatherData.ind;
				vertexAdjData.nEdges = vertexFatherData.nEdges + 1;
				vertexAdjData.weight = vertexFatherData.weight + val;
				vertexAdjData.indEdge = e->GetUserIndex1( );
			}

			vertexAdjData.ind = ivAdjacent;
			vertexsToTest->SetAt( ivAdjacent, vertexAdjData );
			if ( vAdjacent == vertexEnd ) break;
			vAdjacent->SetUserIndex1( -1 ); // A -1 para indicar que es un hijo.
			// Comprobar si el vértice adyacente ya está en la lista de prioridad para ordenarlo
			if ( found ) {
				for ( iRemov = 0; iRemov < (int) childVertexs.GetSize( ); iRemov++ ) {
					if ( childVertexs[ iRemov ].ind == vertexAdjData.ind ) {
						childVertexs.RemoveAt( iRemov );
						break;
					}
				}
			}
			// Insertamos el vértice ordenado en lista de hijos.
			found = false;
			for ( iInsert = 0; iInsert < (int) childVertexs.GetSize( ); iInsert++ )
				if ( childVertexs[ iInsert ].weight < vertexAdjData.weight ) {
					found = true;
					break;
				}
			if ( found || childVertexs.GetSize( ) == 1 ) childVertexs.InsertAt( iInsert, vertexAdjData );
			else
				childVertexs.Add( vertexAdjData );
		}
		if ( vAdjacent == vertexEnd ) break;
		if ( parentVertexs.GetSize( ) <= 0 ) { // La lista de hijos es ahora lista de padres.
			parentVertexs = childVertexs;
			childVertexs.RemoveAll( );
		}
	}

	InitUserIndex1( true, false );
	return true;
}

//---------------------------------------------------------------------------

// Devuelve la lista de caras que forman un camino entre dos caras seleccionadas
// faceStart = Cara por la que se va a iniciar a buscar el camino
// faceEnd = Cara a la que se quiere llegar por el camino
// rPath = lista de caras a devolver si encuentra un camino válido
// edgeStart = Arista por la que va a buscar el camino desde faceStart hasta faceEnd
bool TPBrepData::PathBetweenFaces( IwPolyFace *faceStart, IwPolyFace *faceEnd, IwPolyEdge *edgeStart, IwTA<IwPolyFace *> *rPath )
{
	bool bContinue, path;
	ULONG ulIndex;
	IwPolyEdge *iwNextEdge, *iwEdgeBetweenFaces;
	IwPolyFace *iwFace;
	IwTA<IwPolyEdge *> liwNextEdges;
	IwTA<IwPolyFace *> liwFacesConnected;

	if ( !faceStart || !faceEnd || !rPath || !edgeStart ) return false;
	( *rPath ).RemoveAll( );

	liwNextEdges.Add( edgeStart );
	InitUserIndex1( false, true );
	faceStart->SetUserIndex1( 1 ); // UserIndex1 = 1 para marcar cara en la lista de camino.
	( *rPath ).Add( faceStart );

	bContinue = true;
	path = true;
	do {
		iwFace = rPath->GetLast( );
		iwEdgeBetweenFaces = liwNextEdges[ liwNextEdges.GetSize( ) - 1 ];
		liwNextEdges = GetNextEdge( iwFace, iwEdgeBetweenFaces, OneRingFacesSearchMethod::OppositeEdge, false );

		if ( liwNextEdges.GetSize( ) != 1 ) {
			path = false;
			break;
		}

		iwNextEdge = liwNextEdges[ 0 ];
		liwFacesConnected = GetConnectedFacesFromEdge( iwNextEdge );

		if ( !liwFacesConnected.FindElement( iwFace, ulIndex ) ) {
			path = false;
			break;
		}

		liwFacesConnected.RemoveAt( ulIndex );
		iwFace = liwFacesConnected[ 0 ];
		if ( iwFace->GetUserIndex1( ) == 1 ) {
			path = false;
			break;
		}
		iwFace->SetUserIndex1( 1 );
		liwNextEdges.Add( iwNextEdge );
		( *rPath ).Add( iwFace );

		if ( iwFace == faceEnd ) {
			if ( !GetOppositeEdgeFromFace( iwNextEdge, iwFace, false ) ) {
				path = false;
				break;
			}
			bContinue = false;
		}

	} while ( bContinue );

	if ( !path ) ( *rPath ).RemoveAll( );
	InitUserIndex1( false, true );

	return path;
}

//---------------------------------------------------------------------------

bool TPBrepData::GetShortPathBetweenFaces( TOGLTransf *OGLTransf, int indexFaceStart, int indexFaceEnd )
{
	int i, iShortPath;
	IwPolyEdge *e;
	IwPolyFace *faceStart, *faceEnd;
	IwTA<IwPolyEdge *> edgesFaceStart;
	IwTA<IwPolyFace *> facesPath;
	IwTA<IwTA<IwPolyFace *> > listPaths;

	if ( indexFaceStart < 0 || indexFaceEnd < 0 || indexFaceStart >= (int) PBrepFaces.GetSize( ) || indexFaceEnd >= (int) PBrepFaces.GetSize( ) ) return false;
	faceStart = PBrepFaces[ indexFaceStart ];
	faceEnd = PBrepFaces[ indexFaceEnd ];
	if ( !faceStart || !faceEnd ) return false;

	faceStart->GetPolyEdges( edgesFaceStart );
	if ( (int) edgesFaceStart.GetSize( ) % 2 != 0 ) return false;

	// Se obtiene los caminos entre las dos caras
	for ( i = 0; i < (int) edgesFaceStart.GetSize( ); i++ ) {
		e = edgesFaceStart[ i ];
		if ( PathBetweenFaces( faceStart, faceEnd, e, &facesPath ) ) listPaths.Add( facesPath );
		facesPath.RemoveAll( );
	}

	if ( (int) listPaths.GetSize( ) <= 0 ) return false;

	// Comprobamos el camino más corto.
	iShortPath = 0;
	if ( (int) listPaths.GetSize( ) > 1 ) {
		for ( i = 0; i < (int) listPaths.GetSize( ); i++ )
			if ( i == 0 || (int) listPaths[ i ].GetSize( ) <= (int) listPaths[ iShortPath ].GetSize( ) ) iShortPath = i;
		facesPath = listPaths[ iShortPath ];
	} else
		facesPath = listPaths[ 0 ];

	// Seleccionamos las caras
	for ( i = 0; i < (int) facesPath.GetSize( ); i++ )
		SelectFace( OGLTransf, facesPath[ i ]->GetIndexExt( ) );

	// Para que a partir de la última selección, pueda continuar el camino
	SelectFace( OGLTransf, faceEnd->GetIndexExt( ), SelectedElementType::LastUserSelection );

	return true;
}

//---------------------------------------------------------------------------
// type->0: Para distancia geométrica.
// type->1: Para distancia topológica.
bool TPBrepData::GetShortPathBetweenVertexs( TOGLTransf *OGLTransf, int indexVertexStart, int indexVertexEnd, int type )
{
	int iStart;
	IwPolyVertex *vertexStart, *vertexEnd;
	IwTA<TDataVertexInfo> paths;
	TDataVertexInfo v;

	if ( !OGLTransf || indexVertexStart < 0 || indexVertexEnd < 0 || indexVertexStart >= (int) PBrepVertexs.GetSize( ) || indexVertexEnd >= (int) PBrepVertexs.GetSize( ) || ( type < 0 && type > 1 ) ) return false;
	vertexStart = PBrepVertexs[ indexVertexStart ];
	vertexEnd = PBrepVertexs[ indexVertexEnd ];
	if ( !vertexStart || !vertexEnd ) return false;

	if ( type == 0 ) DistancePathBetweenVertexs( vertexStart, vertexEnd, &paths );
	else if ( type == 1 )
		TopologyDistancePathBetweenVertexs( vertexStart, vertexEnd, &paths );

	iStart = indexVertexEnd;
	while ( iStart != -1 ) { // Se seleccionan los vértices entre el origen y el destino
		if ( iStart < 0 || iStart >= (int) paths.GetSize( ) ) return false;
		v = paths[ iStart ];
		if ( v.indFather != indexVertexStart ) SelectVertex( OGLTransf, v.indFather, SelectedElementType::LoopSelection );
		iStart = v.indFather;
	}

	return true;
}

//---------------------------------------------------------------------------

bool TPBrepData::InitVertexConnectedFromArea( TOGLTransf *OGLTransf, IwTA<IwPolyVertex *> *vertexs, double area, TProportionalEditingType type, int *nElem, int **idElem, T3DPoint **points )
{
	ULONG pos;
	bool found;
	int i, j, k, count;
	double d;
	IwPoint3d weight, weightSel; // Se guardará en x el peso para la edición proporcional.
	IwPolyVertex *v, *vStart, *vOppositive;
	IwPolyEdge *e;
	IwTA<IwPolyEdge *> edges;
	IwTA<IwPolyVertex *> parentsVertexs, childVertexs, vertexsF;
	IwTA<IwPolyFace *> faces;
	IwPolyFace *f;

	if ( !OGLTransf || !vertexs || area <= 0 || (int) type < 0 ) return false;

	( *nElem ) = 0;
	( *idElem ) = 0;
	( *points ) = 0;
	InitUserIndex1( );					  // Marcar si tiene peso.
	InitUserIndex2( true, false, false ); // Marcar su padre.
	childVertexs.RemoveAll( );
	MoveVertUser.Clear( );
	weightSel = IwPoint3d( 1, 0, 0 );

	// Limpiamos valores residuales de m_vPointExt
	InitPointExt( );

	for ( j = 0; j < (int) vertexs->GetSize( ); j++ ) {
		vStart = ( *vertexs )[ j ];
		if ( !vStart ) return false;
		parentsVertexs.RemoveAll( );
		parentsVertexs.Add( vStart );
		MoveVertUser.VerticesOrg.Add( vStart );
		vStart->SetUserIndex1( 1 );
		vStart->SetPointExt( weightSel );

		while ( parentsVertexs.GetSize( ) > 0 ) {
			v = parentsVertexs.GetLast( );
			if ( !v ) continue;
			v->GetPolyEdges( edges );
			for ( i = 0; i < (int) edges.GetSize( ); i++ ) {
				e = edges[ i ];
				if ( !e || e->GetUserIndex1( ) == ULONG_MAX ) continue;
				vOppositive = e->GetOtherVertex( v );
				if ( !vOppositive || vOppositive == vStart ) continue;
				if ( vertexs->FindElement( vOppositive, pos ) ) continue;
				if ( (int) vOppositive->GetUserIndex2( ) == j && vOppositive->GetUserIndex1( ) == 1 ) continue;

				d = vStart->GetPoint( ).DistanceBetween( vOppositive->GetPoint( ) );
				if ( d > area ) continue;
				if ( vOppositive->GetUserIndex1( ) == 0 ) MoveVertUser.Vertices.Add( vOppositive );
				vOppositive->SetUserIndex1( 1 ); // Marcado que ya tiene/tendrá peso.
				vOppositive->SetUserIndex2( j ); // Añadimos posición del array del vértice padre del grupo.

				childVertexs.Add( vOppositive );
				if ( (int) type == (int) TProportionalEditingType::Smooth ) weight.x = SmoothGauss( d, 1.0, 0.0, 0.165, area );
				else if ( (int) type == (int) TProportionalEditingType::Sphere )
					weight.x = Sphere( d, area, 1.0 );
				else if ( (int) type == (int) TProportionalEditingType::Root )
					weight.x = Root( d, area, 1.0 );
				else if ( (int) type == (int) TProportionalEditingType::InverseSquare )
					weight.x = InverseSqueare( d, area, 1.0 );
				else if ( (int) type == (int) TProportionalEditingType::Sharp )
					weight.x = SlaterGauss( d, 1.0, 0.0, 0.16, area );
				else if ( (int) type == (int) TProportionalEditingType::Linear )
					weight.x = Linear( d, area, 1.0 );
				else if ( (int) type == (int) TProportionalEditingType::Random )
					weight.x = ProportionalEditingRandomFunction( d, area, 1.0 );
				else if ( (int) type == (int) TProportionalEditingType::Constant )
					weight.x = 1;
				else
					weight.x = 1;
				if ( weight.x > 0.0 ) {
					if ( vOppositive->GetPointExt( ).x > 0.0 && vOppositive->GetPointExt( ).x < 1 ) {
						if ( weight.x >= vOppositive->GetPointExt( ).x ) {
							vOppositive->SetPointExt( weight );
						}
					} else
						vOppositive->SetPointExt( weight );
				}
			}
			parentsVertexs.RemoveLast( );
			if ( parentsVertexs.GetSize( ) <= 0 && childVertexs.GetSize( ) > 0 ) {
				parentsVertexs = childVertexs;
				childVertexs.RemoveAll( );
			}
		}
	}

	// EQUIVALENCIA EN CARAS PARA EL DIBUJADO DE AREA DE INFLUENCIA y DATOS PARA UNDO.
	*nElem = (int) MoveVertUser.VerticesOrg.GetSize( ) + (int) MoveVertUser.Vertices.GetSize( );
	( *idElem ) = new int[ *nElem ];
	( *points ) = new T3DPoint[ *nElem ];
	count = 0;
	for ( i = 0; i < (int) MoveVertUser.VerticesOrg.GetSize( ); i++ ) {
		v = MoveVertUser.VerticesOrg[ i ];
		if ( !v ) continue;
		( *idElem )[ count ] = v->GetIndexExt( );
		( *points )[ count ] = T3DPoint( v->GetPoint( ).x, v->GetPoint( ).y, v->GetPoint( ).z );
		count++;
		v->GetPolyFaces( faces );
		for ( j = 0; j < (int) faces.GetSize( ); j++ ) {
			f = faces[ j ];
			if ( !f || f->GetUserIndex1( ) == 1 ) continue;
			f->SetUserIndex1( 1 );
		}
	}
	for ( i = 0; i < (int) MoveVertUser.Vertices.GetSize( ); i++ ) {
		vStart = MoveVertUser.Vertices[ i ];
		if ( !vStart ) continue;
		( *idElem )[ count ] = vStart->GetIndexExt( );
		( *points )[ count ] = T3DPoint( vStart->GetPoint( ).x, vStart->GetPoint( ).y, vStart->GetPoint( ).z );
		count++;
		vStart->GetPolyFaces( faces );
		for ( j = 0; j < (int) faces.GetSize( ); j++ ) {
			f = faces[ j ];
			if ( !f || f->GetUserIndex1( ) == 1 ) continue;

			f->GetPolyVertices( vertexsF );
			for ( k = 0; k < (int) vertexsF.GetSize( ); k++ ) {
				vOppositive = vertexsF[ k ];
				found = false;
				if ( vOppositive->GetUserIndex1( ) == 1 ) {
					found = true;
					break;
				}
			}
			if ( found && f->GetUserIndex1( ) == 0 ) f->SetUserIndex1( 1 );
		}
	}

	InitUserIndex2( true, false, false );

	return true;
}

//---------------------------------------------------------------------------

bool TPBrepData::InitVertexFromArea( TOGLTransf *OGLTransf, IwTA<IwPolyVertex *> *vertexs, double area, TProportionalEditingType type, int *nElem, int **idElem, T3DPoint **points )
{
	ULONG pos;
	bool found;
	int i, j, k, count;
	double d;
	IwPoint3d weight, weightSel; // Se guardará en x el peso para la edición proporcional.
	IwPolyVertex *v, *vOppositive;
	IwTA<IwPolyVertex *> vertexsF;
	IwTA<IwPolyFace *> faces;
	IwPolyFace *f;
	T3DPoint pt;
	T3DRect rect;

	if ( !OGLTransf || !vertexs || area <= 0 || (int) type < 0 ) return false;

	( *nElem ) = 0;
	( *idElem ) = 0;
	( *points ) = 0;
	InitUserIndex1( );					  // Para saber si ya tiene peso.
	InitUserIndex2( true, false, false ); // Para marcar su padre.
	MoveVertUser.Clear( );
	weightSel = IwPoint3d( 1, 0, 0 );

	// Limpiamos valores residuales de m_vPointExt
	InitPointExt( );

	for ( i = 0; i < (int) vertexs->GetSize( ); i++ ) {
		v = ( *vertexs )[ i ];
		if ( !v ) continue;
		MoveVertUser.VerticesOrg.Add( v );
		v->SetUserIndex1( 1 );
		v->SetPointExt( weightSel );
		pt = T3DPoint( v->GetPointPtr( )->x, v->GetPointPtr( )->y, v->GetPointPtr( )->z );

		rect = T3DRect( pt.x - area, pt.y - area, pt.z - area, pt.x + area, pt.y + area, pt.z + area );

		for ( j = 0; j < (int) CountPBrepVertexs( OGLTransf ); j++ ) {
			vOppositive = GetPBrepVertex( OGLTransf, j );
			if ( !vOppositive || vOppositive == v ) continue;
			if ( vertexs->FindElement( vOppositive, pos ) ) continue;
			if ( (int) vOppositive->GetUserIndex2( ) == i && vOppositive->GetUserIndex1( ) == 1 ) continue;

			pt = T3DPoint( vOppositive->GetPointPtr( )->x, vOppositive->GetPointPtr( )->y, vOppositive->GetPointPtr( )->z );
			if ( !rect.Contains( pt ) ) continue;
			d = v->GetPoint( ).DistanceBetween( vOppositive->GetPoint( ) );
			if ( d > area ) continue;
			if ( vOppositive->GetUserIndex1( ) == 0 ) MoveVertUser.Vertices.Add( vOppositive );
			vOppositive->SetUserIndex1( 1 ); // Marcado que ya tiene/tendrá peso.
			vOppositive->SetUserIndex2( i ); // Añadimos posición del array del vértice padre del grupo.

			if ( (int) type == (int) TProportionalEditingType::Smooth ) weight.x = SmoothGauss( d, 1.0, 0.0, 0.165, area );
			else if ( (int) type == (int) TProportionalEditingType::Sphere )
				weight.x = Sphere( d, area, 1.0 );
			else if ( (int) type == (int) TProportionalEditingType::Root )
				weight.x = Root( d, area, 1.0 );
			else if ( (int) type == (int) TProportionalEditingType::InverseSquare )
				weight.x = InverseSqueare( d, area, 1.0 );
			else if ( (int) type == (int) TProportionalEditingType::Sharp )
				weight.x = SlaterGauss( d, 1.0, 0.0, 0.16, area );
			else if ( (int) type == (int) TProportionalEditingType::Linear )
				weight.x = Linear( d, area, 1.0 );
			else if ( (int) type == (int) TProportionalEditingType::Random )
				weight.x = ProportionalEditingRandomFunction( d, area, 1.0 );
			else if ( (int) type == (int) TProportionalEditingType::Constant )
				weight.x = 1;
			if ( weight.x > 0.0 ) {
				if ( vOppositive->GetPointExt( ).x > 0.0 && vOppositive->GetPointExt( ).x < 1 ) {
					if ( weight.x >= vOppositive->GetPointExt( ).x ) {
						vOppositive->SetPointExt( weight );
					}
				} else
					vOppositive->SetPointExt( weight );
			}
		}
	}

	// EQUIVALENCIA DE CARAS PARA EL DIBUJADO DE AREA DE INFLUENCIA y DATOS PARA UNDO.
	*nElem = (int) MoveVertUser.VerticesOrg.GetSize( ) + (int) MoveVertUser.Vertices.GetSize( );
	( *idElem ) = new int[ *nElem ];
	( *points ) = new T3DPoint[ *nElem ];
	count = 0;
	for ( i = 0; i < (int) MoveVertUser.VerticesOrg.GetSize( ); i++ ) {
		v = MoveVertUser.VerticesOrg[ i ];
		if ( !v ) continue;
		( *idElem )[ count ] = v->GetIndexExt( );
		( *points )[ count ] = T3DPoint( v->GetPoint( ).x, v->GetPoint( ).y, v->GetPoint( ).z );
		count++;
		v->GetPolyFaces( faces );
		for ( j = 0; j < (int) faces.GetSize( ); j++ ) {
			f = faces[ j ];
			if ( !f || f->GetUserIndex1( ) == 1 ) continue;
			f->SetUserIndex1( 1 );
		}
	}
	for ( i = 0; i < (int) MoveVertUser.Vertices.GetSize( ); i++ ) {
		v = MoveVertUser.Vertices[ i ];
		if ( !v ) continue;
		( *idElem )[ count ] = v->GetIndexExt( );
		( *points )[ count ] = T3DPoint( v->GetPoint( ).x, v->GetPoint( ).y, v->GetPoint( ).z );
		count++;
		v->GetPolyFaces( faces );
		for ( j = 0; j < (int) faces.GetSize( ); j++ ) {
			f = faces[ j ];
			if ( !f || f->GetUserIndex1( ) == 1 ) continue;

			f->GetPolyVertices( vertexsF );
			for ( k = 0; k < (int) vertexsF.GetSize( ); k++ ) {
				vOppositive = vertexsF[ k ];
				found = false;
				if ( vOppositive->GetUserIndex1( ) == 1 ) {
					found = true;
					break;
				}
			}
			if ( found ) f->SetUserIndex1( 1 );
		}
	}

	InitUserIndex2( true, false, false );

	return true;
}

//---------------------------------------------------------------------------

void TPBrepData::InitPointExt( )
{
	int i;
	IwPoint3d weight;
	weight = IwPoint3d( 0, 0, 0 );
	for ( i = 0; i < (int) PBrepVertexs.GetSize( ); i++ )
		PBrepVertexs[ i ]->SetPointExt( weight );
}

