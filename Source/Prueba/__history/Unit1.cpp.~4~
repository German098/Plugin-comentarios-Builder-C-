//------------------------------------------------------------------------------
#include "windows.h"
#pragma hdrstop

//------------------------------------------------------------------------------
#include "nucleo.rh"

//------------------------------------------------------------------------------
#include "_entities.h"
#include "ines_glu.h"
#include "functions.h"
#include "formentitydata.h"
#include "mapEntities.h"
#include "tsmlib.h"
#include "variations.h"
#include "mainform.h"
#include "mainform_bg.h"
#include "pbrepdata.h"
#include "sisl.h"
#include "deformers.h"
#include "quadRemesher.h"

//------------------------------------------------------------------------------

#pragma package( smart_init )

static bool debug = false;

//------------------------------------------------------------------------------
// TCadEntity
//------------------------------------------------------------------------------

TCadEntity::TCadEntity( )
{
	Version = ENTITY_VERSION_CURRENT;

	ID = UNDEFINED_ID;
	Dimension = DEFAULT_DIMENSION;
	Description = "";
	Layer = 0;
	Type = 0;
	Visible = true;

	TempName = "";
	TempLayerName = "";
	TempLayerPos = -1;
	// TempNameToRestoreList.Clear( );
	TempIntValue = 0;

	IntValue = 0;
	OGLParam_1_Tol = RES_1_PARAM;
	ParamSurface = 0;
	ParamInterpolationMode = PIM_PARAM;
	ParamOffset = PARAM_OFFSET_DEFAULT;

	Developable = true;
	DevelopSurfIndex = 0;
	ForceDevelopSurfIndex = true;

	AppliedRemesh = false;

	OwnOGLRenderData = false;
	IsTextureDirty = true;
	IsDeformerTextureDirty = true;
	OGLTextureDataList.SetForceCenter( true );
	SetTextureMode( TEXTURE_AUTO );

	RelatedEntities = 0;
	DepShapes = 0;
	DepSurfaces = 0;
	DepMeshes = 0;

	SISLDirtyID = -1;
	PolygonDirtyID = -1;
	Geom3DDirtyID = -1;
	Develop2DDirtyID = -1;
	ForceDevSurfsDirtyID = -1;

	TempParamCenter = -1;
	PBrepData = 0;
	PBrepTrianglesForced = true;

	LockSISLDirty = false;
	LockPolygonDirty = false;
	//	SetAllDirty( true );
	SetAllDirty( true, true, false );
	LockRecalc = false;
	LockNormals = false;

	ConvertToTriangles = false;
	OGLDeformer3DList = 0;

	MaterialConfiguratorGroup = 0;
	Pivot = 0;
}

//------------------------------------------------------------------------------

TCadEntity::TCadEntity( TCadEntity *S )
{
	if ( !S ) return;

	Version = S->Version;

	ID = S->ID;
	Dimension = S->Dimension;
	Description = S->Description;
	Layer = S->Layer;
	Type = S->Type;
	Visible = S->Visible;

	TempName = S->GetTempName( );
	TempLayerName = S->GetTempLayerName( );
	TempLayerPos = S->TempLayerPos;
	TempNameToRestoreList.Set( &( S->TempNameToRestoreList ) );
	TempIntValue = S->GetTempIntValue( );
	IntValue = S->IntValue;

	OGLParam_1_Tol = S->OGLParam_1_Tol;
	ParamSurface = S->ParamSurface;
	ParamInterpolationMode = S->ParamInterpolationMode;
	ParamOffset = S->ParamOffset;

	Developable = S->IsDevelopable( );
	DevelopSurfIndex = S->GetDevelopSurfIndex( );
	ForceDevelopSurfIndex = S->GetForceDevelopSurfIndex( );

	AppliedRemesh = S->GetAppliedRemesh( );
	RemeshData.Set( S->GetRemeshData( ) );

	SISLDirtyID = S->SISLDirtyID;
	PolygonDirtyID = S->PolygonDirtyID;
	Geom3DDirtyID = S->Geom3DDirtyID;
	Develop2DDirtyID = S->Develop2DDirtyID;
	ForceDevSurfsDirtyID = S->ForceDevSurfsDirtyID;

	IsSISLDirty = S->IsSISLDirty;
	IsPolygonDirty = S->IsPolygonDirty;
	IsGeom3DDirty = S->IsGeom3DDirty;
	IsDevelop2DDirty = S->IsDevelop2DDirty;
	IsExternalDirty = S->IsExternalDirty;
	IsPBrepDirty = S->IsPBrepDirty;
	PBrepTrianglesForced = S->PBrepTrianglesForced;
	IsDeformer3DDirty = S->IsDeformer3DDirty;
	IsDeformerDataDirty = S->IsDeformerDataDirty;

	LockRecalc = S->LockRecalc;
	LockSISLDirty = S->LockSISLDirty;
	LockPolygonDirty = S->LockPolygonDirty;
	LockNormals = S->LockNormals;

	ConvertToTriangles = S->ConvertToTriangles;

	OGLPolygonList.Set( S->GetOGLList( 0 ) );
	OGLGeom3DList.Set( S->GetOGLGeom3D( 0 ) );
	OGLDevelop2DList.Set( S->GetOGLDevelop2D( 0 ) );
	if ( S->GetOGLDeformer3DList( ) ) {
		OGLDeformer3DList = new TOGLPolygonList( );
		OGLDeformer3DList->Set( S->GetOGLDeformer3DList( ) );
	} else
		OGLDeformer3DList = 0;
	PBrepData = 0;

	TempParamCenter = S->GetTempParamCenter( );

	OwnOGLRenderData = S->OwnOGLRenderData;
	OGLRenderData.Set( &( S->OGLRenderData ) );
	IsTextureDirty = S->IsTextureDirty;
	IsDeformerTextureDirty = S->IsDeformerTextureDirty;
	OGLTextureDataList.Set( S->GetOGLTextureDataList( ) );

	MaxwellObjectData.Set( &( S->MaxwellObjectData ) );

	MaterialConfiguratorGroup = S->MaterialConfiguratorGroup;

	EntityRelationList.Set( S->GetEntityRelationList( ) );

	RelatedEntities = new TCadGroup( );
	RelatedEntities->SetDestroyList( false );
	RelatedEntities->SetEntities( S->GetRelatedEntities( ) );

	if ( S->GetDepShapes( ) && S->GetDepShapes( )->Count( ) ) {
		DepShapes = new TCadGroup( );
		DepShapes->SetDestroyList( false );
		DepShapes->SetEntities( S->GetDepShapes( ) );
	} else
		DepShapes = 0;

	if ( S->GetDepSurfaces( ) && S->GetDepSurfaces( )->Count( ) ) {
		DepSurfaces = new TCadGroup( );
		DepSurfaces->SetDestroyList( false );
		DepSurfaces->SetEntities( S->GetDepSurfaces( ) );
	} else
		DepSurfaces = 0;

	if ( S->GetDepMeshes( ) && S->GetDepMeshes( )->Count( ) ) {
		DepMeshes = new TCadGroup( );
		DepMeshes->SetDestroyList( false );
		DepMeshes->SetEntities( S->GetDepMeshes( ) );
	} else
		DepMeshes = 0;

	Pivot = 0;
	if ( S->Pivot ) SetPivot( S->Pivot );
}

//------------------------------------------------------------------------------

void TCadEntity::Set( TCadEntity *S, bool copyrels )
{
	if ( !S ) return;

	Version = S->Version;

	ID = S->ID;
	Dimension = S->Dimension;
	Description = S->Description;
	Layer = S->Layer;
	Type = S->Type;
	Visible = S->Visible;

	TempName = S->GetTempName( );
	TempLayerName = S->GetTempLayerName( );
	TempLayerPos = S->GetTempLayerPos( );
	TempNameToRestoreList.Set( &( S->TempNameToRestoreList ) );
	TempIntValue = S->GetTempIntValue( );
	IntValue = S->IntValue;

	OGLParam_1_Tol = S->OGLParam_1_Tol;
	if ( copyrels ) ParamSurface = S->ParamSurface;
	ParamInterpolationMode = S->ParamInterpolationMode;
	ParamOffset = S->ParamOffset;

	Developable = S->IsDevelopable( );
	DevelopSurfIndex = S->GetDevelopSurfIndex( );
	ForceDevelopSurfIndex = S->GetForceDevelopSurfIndex( );

	AppliedRemesh = S->GetAppliedRemesh( );
	RemeshData.Set( S->GetRemeshData( ) );

	SISLDirtyID = S->SISLDirtyID;
	PolygonDirtyID = S->PolygonDirtyID;
	Geom3DDirtyID = S->Geom3DDirtyID;
	Develop2DDirtyID = S->Develop2DDirtyID;
	ForceDevSurfsDirtyID = S->ForceDevSurfsDirtyID;

	IsSISLDirty = S->IsSISLDirty;
	IsPolygonDirty = S->IsPolygonDirty;
	IsGeom3DDirty = S->IsGeom3DDirty;
	IsDevelop2DDirty = S->IsDevelop2DDirty;
	IsExternalDirty = S->IsExternalDirty;
	IsPBrepDirty = S->IsPBrepDirty;
	PBrepTrianglesForced = S->PBrepTrianglesForced;
	IsDeformer3DDirty = S->IsDeformer3DDirty;
	IsDeformerDataDirty = S->IsDeformerDataDirty;

	LockRecalc = S->LockRecalc;
	LockSISLDirty = S->LockSISLDirty;
	LockPolygonDirty = S->LockPolygonDirty;
	LockNormals = S->LockNormals;

	ConvertToTriangles = S->ConvertToTriangles;

	OGLPolygonList.Set( S->GetOGLList( 0 ) );
	OGLGeom3DList.Set( S->GetOGLGeom3D( 0 ) );
	OGLDevelop2DList.Set( S->GetOGLDevelop2D( 0 ) );
	if ( OGLDeformer3DList ) {
		if ( S->GetOGLDeformer3DList( ) ) OGLDeformer3DList->Set( S->GetOGLDeformer3DList( ) );
		else {
			delete OGLDeformer3DList;
			OGLDeformer3DList = 0;
		}
	} else if ( S->GetOGLDeformer3DList( ) ) {
		OGLDeformer3DList = new TOGLPolygonList( );
		OGLDeformer3DList->Set( S->GetOGLDeformer3DList( ) );
	}
	ClearPBrepData( );

	OwnOGLRenderData = S->OwnOGLRenderData;
	OGLRenderData.Set( &( S->OGLRenderData ) );
	IsTextureDirty = S->IsTextureDirty;
	IsDeformerTextureDirty = S->IsDeformerTextureDirty;
	OGLTextureDataList.Set( S->GetOGLTextureDataList( ) );
	TempParamCenter = S->TempParamCenter;

	MaxwellObjectData.Set( &( S->MaxwellObjectData ) );

	MaterialConfiguratorGroup = S->MaterialConfiguratorGroup;

	if ( copyrels ) {
		EntityRelationList.Set( S->GetEntityRelationList( ) );
		if ( !RelatedEntities ) {
			RelatedEntities = new TCadGroup( );
			RelatedEntities->SetDestroyList( false );
		}
		RelatedEntities->SetEntities( S->GetRelatedEntities( ) );

		if ( S->GetDepShapes( ) && S->GetDepShapes( )->Count( ) ) {
			if ( !DepShapes ) {
				DepShapes = new TCadGroup( );
				DepShapes->SetDestroyList( false );
			}
			DepShapes->SetEntities( S->GetDepShapes( ) );
		} else if ( DepShapes ) {
			delete DepShapes;
			DepShapes = 0;
		}

		if ( S->GetDepSurfaces( ) && S->GetDepSurfaces( )->Count( ) ) {
			if ( !DepSurfaces ) {
				DepSurfaces = new TCadGroup( );
				DepSurfaces->SetDestroyList( false );
			}
			DepSurfaces->SetEntities( S->GetDepSurfaces( ) );
		} else if ( DepSurfaces ) {
			delete DepSurfaces;
			DepSurfaces = 0;
		}

		if ( S->GetDepMeshes( ) && S->GetDepMeshes( )->Count( ) ) {
			if ( !DepMeshes ) {
				DepMeshes = new TCadGroup( );
				DepMeshes->SetDestroyList( false );
			}
			DepMeshes->SetEntities( S->GetDepMeshes( ) );
		} else if ( DepMeshes ) {
			delete DepMeshes;
			DepMeshes = 0;
		}
	}

	if ( S->Pivot ) SetPivot( S->Pivot );
}

//------------------------------------------------------------------------------

void TCadEntity::SetBasic( TCadEntity *S, bool copyrels )
{
	if ( !S ) return;

	Version = S->Version;

	ID = S->ID;
	Dimension = S->Dimension;
	Description = S->Description;
	Layer = S->Layer;
	Type = S->Type;
	Visible = S->Visible;

	TempName = S->GetTempName( );
	TempLayerName = S->GetTempLayerName( );
	TempLayerPos = S->GetTempLayerPos( );
	TempNameToRestoreList.Set( &( S->TempNameToRestoreList ) );
	TempIntValue = S->GetTempIntValue( );
	IntValue = S->IntValue;

	OGLParam_1_Tol = S->OGLParam_1_Tol;
	if ( copyrels ) ParamSurface = S->ParamSurface;
	ParamInterpolationMode = S->ParamInterpolationMode;
	ParamOffset = S->ParamOffset;

	Developable = S->IsDevelopable( );
	DevelopSurfIndex = S->GetDevelopSurfIndex( );
	ForceDevelopSurfIndex = S->GetForceDevelopSurfIndex( );

	AppliedRemesh = false;
	RemeshData.Set( S->GetRemeshData( ) );

	SetAllDirty( true );
	LockRecalc = false;
	LockNormals = S->LockNormals;

	ConvertToTriangles = S->ConvertToTriangles;

	OGLPolygonList.Clear( );
	OGLGeom3DList.Clear( );
	OGLDevelop2DList.Clear( );
	ClearOGLDeformer3DList( );
	ClearPBrepData( );

	OGLPolygonList.SetOGLDisplayData( S->GetOGLList( 0 )->GetOGLDisplayData( ) );
	OGLGeom3DList.SetOGLDisplayData( S->GetOGLGeom3D( 0 )->GetOGLDisplayData( ) );
	OGLDevelop2DList.SetOGLDisplayData( S->GetOGLDevelop2D( 0 )->GetOGLDisplayData( ) );

	OwnOGLRenderData = S->OwnOGLRenderData;
	OGLRenderData.Set( &( S->OGLRenderData ) );
	//	IsTextureDirty = S->IsTextureDirty;
	//	IsDeformerTextureDirty = S->IsDeformerTextureDirty;
	OGLTextureDataList.Set( S->GetOGLTextureDataList( ) );
	TempParamCenter = S->TempParamCenter;

	MaxwellObjectData.Set( &( S->MaxwellObjectData ) );

	MaterialConfiguratorGroup = S->MaterialConfiguratorGroup;

	if ( copyrels ) {
		EntityRelationList.Set( S->GetEntityRelationList( ) );
		if ( !RelatedEntities ) {
			RelatedEntities = new TCadGroup( );
			RelatedEntities->SetDestroyList( false );
		}
		RelatedEntities->SetEntities( S->GetRelatedEntities( ) );

		if ( S->GetDepShapes( ) && S->GetDepShapes( )->Count( ) ) {
			if ( !DepShapes ) {
				DepShapes = new TCadGroup( );
				DepShapes->SetDestroyList( false );
			}
			DepShapes->SetEntities( S->GetDepShapes( ) );
		} else if ( DepShapes ) {
			delete DepShapes;
			DepShapes = 0;
		}

		if ( S->GetDepSurfaces( ) && S->GetDepSurfaces( )->Count( ) ) {
			if ( !DepSurfaces ) {
				DepSurfaces = new TCadGroup( );
				DepSurfaces->SetDestroyList( false );
			}
			DepSurfaces->SetEntities( S->GetDepSurfaces( ) );
		} else if ( DepSurfaces ) {
			delete DepSurfaces;
			DepSurfaces = 0;
		}

		if ( S->GetDepMeshes( ) && S->GetDepMeshes( )->Count( ) ) {
			if ( !DepMeshes ) {
				DepMeshes = new TCadGroup( );
				DepMeshes->SetDestroyList( false );
			}
			DepMeshes->SetEntities( S->GetDepMeshes( ) );
		} else if ( DepMeshes ) {
			delete DepMeshes;
			DepMeshes = 0;
		}
	}

	if ( S->Pivot ) SetPivot( S->Pivot );
}

//------------------------------------------------------------------------------

// se asume que no existen relaciones previas
void TCadEntity::SetBasicRels( TCadEntity *S )
{
	int i;
	TEntityRelation *er;

	if ( !S ) return;

	ParamSurface = S->ParamSurface;
	if ( ParamSurface ) ParamSurface->GetParamEntities( )->Add( this );

	for ( i = 0; i < S->GetEntityRelationList( )->Count( ); i++ ) {
		er = S->GetEntityRelationList( )->GetItem( i );
		if ( !er ) continue;
		if ( er->Type == ER_TYPE_DEPENDENT_SE_SOFTEN || er->Type == ER_TYPE_DEPENDENT_SE_DISTRIBUTE || er->Type == ER_TYPE_DEPENDENT_FRAME ) AddEntityRelation( er );
	}

	// si se anyadiera una relacion de entidad necesaria para que tenga sentido la entidad dependiente, anyadir esa relacion aqui
}

//------------------------------------------------------------------------------

void TCadEntity::GetBasicRelsEnts( TCadGroup *grp, bool usesurf, bool )
{
	int i;
	TEntityRelation *er;

	if ( !grp ) return;

	if ( usesurf && ParamSurface ) grp->Add( ParamSurface );

	for ( i = 0; i < EntityRelationList.Count( ); i++ ) {
		er = EntityRelationList.GetItem( i );
		if ( !er ) continue;
		if ( er->Type == ER_TYPE_DEPENDENT_SE_SOFTEN || er->Type == ER_TYPE_DEPENDENT_SE_DISTRIBUTE || er->Type == ER_TYPE_DEPENDENT_FRAME )
			if ( EntityRelationList.GetItem( i )->BaseEntity ) grp->Add( EntityRelationList.GetItem( i )->BaseEntity );
	}
}

//------------------------------------------------------------------------------

void TCadEntity::ChangeBasicRels( TCadEntity *orgbaseent, TCadEntity *dstbaseent, bool updatedirty, bool setdirty )
{
	int i;
	TEntityRelation *er;

	if ( !orgbaseent || !dstbaseent ) return;

	if ( orgbaseent == ParamSurface && ToSurface( dstbaseent ) ) {
		if ( ToSurface( orgbaseent )->GetParamEntities( )->IsEntityIncluded( this, false ) ) {
			ToSurface( orgbaseent )->GetParamEntities( )->Detach( this, NoDelete );
			ToSurface( dstbaseent )->GetParamEntities( )->Add( this );
		}
		ParamSurface = ToSurface( dstbaseent );
	}

	for ( i = 0; i < EntityRelationList.Count( ); i++ ) {
		er = EntityRelationList.GetItem( i );
		if ( !er ) continue;
		if ( er->Type == ER_TYPE_DEPENDENT_SE_SOFTEN || er->Type == ER_TYPE_DEPENDENT_SE_DISTRIBUTE || er->Type == ER_TYPE_DEPENDENT_FRAME ) {
			if ( orgbaseent == EntityRelationList.GetItem( i )->BaseEntity ) {
				if ( orgbaseent->GetRelatedEntities( ) && orgbaseent->GetRelatedEntities( )->IsEntityIncluded( this, false ) ) {
					orgbaseent->GetRelatedEntities( )->Detach( this, NoDelete );
					if ( !dstbaseent->GetRelatedEntities( ) ) dstbaseent->CreateRelatedEntities( );
					dstbaseent->GetRelatedEntities( )->Add( this );
				}
				EntityRelationList.GetItem( i )->BaseEntity = dstbaseent;
				if ( er->Type == ER_TYPE_DEPENDENT_FRAME && ToRect( this ) ) ToRect( this )->GetOGLImageTextureList( )->DelItem( 0 );
				setdirty = true;
			}
		}
	}

	if ( updatedirty && setdirty ) SetAllDirty( true );
}

//------------------------------------------------------------------------------

void TCadEntity::SetDescription( UnicodeString description )
{
	Description = description;
}

//------------------------------------------------------------------------------

UnicodeString TCadEntity::GetDescription( )
{
	UnicodeString str;

	if ( Description.Length( ) ) {
		str = _GetTranslatedString( Description );
		if ( str.Length( ) ) return str;
		return Description;
	}

	return _GetTranslatedString( WhoIDSAmI( ) );
}

//------------------------------------------------------------------------------

void TCadEntity::FillProp( TOGLTransf *OGLTransf, TFormEntityData *properties )
{
	FillProp_General( properties );
	FillProp_Geom( OGLTransf, properties );
	FillProp_Advanced( properties );
}

//------------------------------------------------------------------------------

void TCadEntity::FillProp_General( TFormEntityData *properties )
{
	properties->Type = WhoAmI( );
	properties->IDSType = WhoIDSAmI( );
	properties->EntityData.Description = GetDescription( );
	properties->EntityData.Id = GetDualID( );
	properties->Render = OwnOGLRenderData;
	properties->TextureMode = GetTextureMode( );
	properties->IsParamEntity = IsParamEntity( );
	if ( IsParamEntity( ) ) {
		properties->BaseSurface.Id = GetParamSurface( )->GetDualID( );
		properties->BaseSurface.Description = GetParamSurface( )->GetDescription( );
		properties->CountSurfsInDevelop = GetParamSurface( )->HasDevelop( ) ? GetParamSurface( )->GetDevelopList( )->CountSurfsInDevelop( ) : 0;
	}
}

//------------------------------------------------------------------------------

void TCadEntity::FillProp_Geom( TOGLTransf *OGLTransf, TFormEntityData *properties )
{
	properties->Box[ 0 ] = Size( OGLTransf );
}

//------------------------------------------------------------------------------

void TCadEntity::FillProp_Advanced( TFormEntityData *properties )
{
	int i;
	TCadDepSurface *depsurface;
	TCadDepMesh *depmesh;

	properties->Offset = ParamOffset;

	properties->HasDevelop = ( GetBaseSurface( ) ? GetBaseSurface( )->HasDevelop( ) : HasDevelop( ) );
	properties->Developable = Developable;
	properties->DevelopSide = GetDevelopSurfIndex( );
	properties->ForceDevelopSide = GetForceDevelopSurfIndex( ); // Cambio 02/2019 ForceDevelopSurfIndex por GetForceDevelopSurfIndex( ) pq en depshapes el valor se toma de la funcion de manera distinta a la variable
	properties->RemeshData.Set( &RemeshData );

	if ( DepShapes )
		for ( i = 0; i < DepShapes->Count( ); i++ ) {
			if ( ToDepShape( DepShapes->GetShape( i ) )->IsParallelDepShape( ) ) properties->ParallelShapes->AddItem( DepShapes->GetShape( i )->GetDescription( ), DepShapes->GetShape( i )->GetDualID( ) );
			if ( ToDepShape( DepShapes->GetShape( i ) )->IsSymmetricDepShape( ) || ToDepShape( DepShapes->GetShape( i ) )->IsReallocateDepShape( ) ) properties->SymmetricShapes->AddItem( DepShapes->GetShape( i )->GetDescription( ), DepShapes->GetShape( i )->GetDualID( ) );
			if ( ToDepShape( DepShapes->GetShape( i ) )->IsRotationDepShape( ) ) properties->RotationShapes->AddItem( DepShapes->GetShape( i )->GetDescription( ), DepShapes->GetShape( i )->GetDualID( ) );
			if ( ToDepShape( DepShapes->GetShape( i ) )->IsPolyDepShape( ) ) properties->PolyShapes->AddItem( DepShapes->GetShape( i )->GetDescription( ), DepShapes->GetShape( i )->GetDualID( ) );
		}

	if ( DepSurfaces )
		for ( i = 0; i < DepSurfaces->Count( ); i++ ) {
			depsurface = ToDepSurface( DepSurfaces->GetShape( i ) );
			if ( depsurface ) properties->DepSurfaces->AddItem( depsurface->GetDescription( ), depsurface->GetDualID( ) );
		}

	if ( DepMeshes )
		for ( i = 0; i < DepMeshes->Count( ); i++ ) {
			depmesh = ToDepMesh( DepMeshes->GetShape( i ) );
			if ( depmesh ) properties->DepMeshes->AddItem( depmesh->GetDescription( ), depmesh->GetDualID( ) );
		}
}

//------------------------------------------------------------------------------

TCadEntity::~TCadEntity( )
{
	if ( RelatedEntities ) delete RelatedEntities;
	if ( DepShapes ) delete DepShapes;
	if ( DepSurfaces ) delete DepSurfaces;
	if ( DepMeshes ) delete DepMeshes;
	if ( OGLDeformer3DList ) delete OGLDeformer3DList;
	if ( Pivot ) delete Pivot;
	if ( PBrepData ) delete PBrepData;
}

//------------------------------------------------------------------------------

bool TCadEntity::MustCalcOGLLists( TOGLRenderSystem *_OGLRdSystem )
{
	if ( _OGLRdSystem->RecalcEntities == RECALC_NONE ) return false;
	if ( _OGLRdSystem->RecalcEntities == RECALC_ALL ) return true;
	return ( !IsParamEntity( ) || ( _OGLRdSystem->RecalcEntities & RECALC_PARAM ) );
}

//------------------------------------------------------------------------------

bool TCadEntity::CalcOGLLists( TOGLTransf *OGLTransf )
{
	bool resp, reduce, dirty, secondsurfrestored;
	double filterdist;

	if ( !CalcSISL( OGLTransf ) ) {
		if ( OGLDevelop2DList.Count( ) > 0 ) OGLDevelop2DList.Clear( );
		if ( OGLPolygonList.Count( ) > 0 ) OGLPolygonList.Clear( );
		if ( OGLGeom3DList.Count( ) > 0 ) OGLGeom3DList.Clear( );

		ClearOGLDeformer3DList( );
		return false;
	}

	dirty = IsDevelop2DDirty || IsPolygonDirty || IsGeom3DDirty;
	if ( !dirty ) //	if ( !dirty || LockRecalc )
		return ( OGLDevelop2DList.Count( ) > 0 || OGLPolygonList.Count( ) > 0 || OGLGeom3DList.Count( ) > 0 );

	if ( !IsParamEntity( ) ) {
		//		reduce = IsPolygonDirty;
		resp = CalcOGLPolygon( OGLTransf );
		AppliedRemesh = false; // if ( Remesh )
	} else {
		resp = false;
		if ( AmIStrictBSpline( ) ) filterdist = RES_COMP; // si filtramos a RES_GEOM, ficheros iges importados fallan
		else
			filterdist = RES_GEOM;
		secondsurfrestored = OGLTransf->GetSecondDevelopSurfIndexTempReverted( ) && IsDevelopable( ) && ParamSurface->GetDevelopList( ) && ParamSurface->GetDevelopList( )->CountSurfsInDevelop( ) > 1;
		if ( secondsurfrestored ) ParamSurface->RestoreSecondDevelopSurface( OGLTransf );
		switch ( ParamInterpolationMode ) {
			case PIM_PARAM:
				if ( IsDevelop2DDirty && GetParamSurface( )->HasDevelopData( ) && IsDevelopable( ) && OGLTransf->GetForceMode( ) != VIEW_GEOM3D && OGLTransf->GetForceMode( ) != VIEW_PARAM2D )
					//				if ( IsDevelop2DDirty && GetParamSurface( )->HasDevelopData( ) && IsDevelopable( ) )
					//					if ( OGLTransf->GetForceMode( ) == VIEW_DEVELOP2D || ( OGLTransf->GetForceMode( ) == VIEW_NONE && OGLTransf->GetViewMode( ) == VIEW_DEVELOP2D ) )
					IsPolygonDirty = IsGeom3DDirty = true;
				reduce = IsPolygonDirty;
				if ( CalcOGLParam2D( OGLTransf ) ) {
					if ( CalcOGLGeom3DFromParam2D( OGLTransf ) ) {
						if ( GetParamSurface( )->HasDevelopData( ) && IsDevelopable( ) ) reduce = IsDevelop2DDirty;
						resp = CalcOGLDevelop2DFromParam2D( OGLTransf );
						if ( resp && reduce ) {
							if ( GetParamSurface( )->HasDevelopData( ) && IsDevelopable( ) ) {
								if ( !IsDevelop2DDirty ) OGLDevelop2DList.Filter( filterdist, &OGLPolygonList, &OGLGeom3DList, MAX_PARAM / 4.0, true, false, true );
							} else
								OGLGeom3DList.Filter( filterdist, &OGLPolygonList, 0, MAX_PARAM / 4.0, true, false, true );
						}
					}
				}
				break;

			case PIM_GEOM:
				reduce = IsGeom3DDirty;
				resp = CalcOGLGeom3D( OGLTransf );
				if ( !resp ) break;
				if ( reduce ) OGLGeom3DList.Filter( filterdist, 0, 0, 0.0, true, false, true );
				OGLPolygonList.Clear( );
				ClearOGLDeformer3DList( );
				SetPolygonDirty( false );
				OGLDevelop2DList.Clear( );
				SetDevelop2DDirty( false );
				break;

			case PIM_GEOMPARAM:
				if ( IsDevelop2DDirty && GetParamSurface( )->HasDevelopData( ) && IsDevelopable( ) && OGLTransf->GetForceMode( ) != VIEW_GEOM3D && OGLTransf->GetForceMode( ) != VIEW_PARAM2D )
					//				if ( IsDevelop2DDirty && GetParamSurface( )->HasDevelopData( ) && IsDevelopable( ) )
					//					if ( OGLTransf->GetForceMode( ) == VIEW_DEVELOP2D || ( OGLTransf->GetForceMode( ) == VIEW_NONE && OGLTransf->GetViewMode( ) == VIEW_DEVELOP2D ) )
					IsPolygonDirty = IsGeom3DDirty = true;
				reduce = IsGeom3DDirty;
				if ( CalcOGLGeom3D( OGLTransf ) ) {
					if ( CalcOGLParam2DFromGeom3D( OGLTransf ) ) {
						if ( CalcOGLGeom3DFromParam2D( OGLTransf ) ) {
							resp = CalcOGLDevelop2DFromParam2D( OGLTransf );
							if ( resp && reduce ) {
								if ( GetParamSurface( )->HasDevelopData( ) && IsDevelopable( ) ) {
									if ( !IsDevelop2DDirty ) OGLDevelop2DList.Filter( filterdist, &OGLPolygonList, &OGLGeom3DList, MAX_PARAM / 4.0, true, false, true );
								} else
									OGLGeom3DList.Filter( filterdist, &OGLPolygonList, 0, MAX_PARAM / 4.0, true, false, true );
							}
						}
					}
				}
				break;

			case PIM_GEOMPARAMCT:
				if ( IsDevelop2DDirty && GetParamSurface( )->HasDevelopData( ) && IsDevelopable( ) && OGLTransf->GetForceMode( ) != VIEW_GEOM3D && OGLTransf->GetForceMode( ) != VIEW_PARAM2D )
					//				if ( IsDevelop2DDirty && GetParamSurface( )->HasDevelopData( ) && IsDevelopable( ) )
					//					if ( OGLTransf->GetForceMode( ) == VIEW_DEVELOP2D || ( OGLTransf->GetForceMode( ) == VIEW_NONE && OGLTransf->GetViewMode( ) == VIEW_DEVELOP2D ) )
					IsPolygonDirty = IsGeom3DDirty = true;
				reduce = IsGeom3DDirty;
				if ( CalcOGLGeom3D( OGLTransf ) )
					if ( CalcOGLParam2DFromGeom3D_CT( OGLTransf ) )
						if ( CalcOGLGeom3DFromParam2D( OGLTransf ) ) {
							resp = CalcOGLDevelop2DFromParam2D( OGLTransf );
							if ( resp && reduce ) {
								if ( GetParamSurface( )->HasDevelopData( ) && IsDevelopable( ) ) {
									if ( !IsDevelop2DDirty ) OGLDevelop2DList.Filter( filterdist, &OGLPolygonList, &OGLGeom3DList, MAX_PARAM / 4.0, true, false, true );
								} else
									OGLGeom3DList.Filter( filterdist, &OGLPolygonList, 0, MAX_PARAM / 4.0, true, false, true );
							}
						}
				break;

			case PIM_DEVELOP:
				reduce = IsDevelop2DDirty;
				if ( CalcOGLDevelop2D( OGLTransf ) ) {
					if ( CalcOGLParam2DFromDevelop2D( OGLTransf ) ) {
						if ( CalcOGLGeom3DFromParam2D( OGLTransf ) ) {
							if ( reduce ) IsDevelop2DDirty = true;
							resp = CalcOGLDevelop2DFromParam2D( OGLTransf );
							if ( resp && reduce ) {
								if ( GetParamSurface( )->HasDevelopData( ) && IsDevelopable( ) ) {
									if ( !IsDevelop2DDirty ) OGLDevelop2DList.Filter( filterdist, &OGLPolygonList, &OGLGeom3DList, MAX_PARAM / 4.0, true, false, true );
								} else
									OGLGeom3DList.Filter( filterdist, &OGLPolygonList, 0, MAX_PARAM / 4.0, true, false, true );
							}
						}
					}
				}
				break;
		}
		if ( secondsurfrestored ) ParamSurface->RevertSecondDevelopSurface( OGLTransf );
	}

	return resp;
}

//------------------------------------------------------------------------------

bool TCadEntity::CalcOGLParam2D( TOGLTransf *OGLTransf )
{
	return CalcOGLPolygon( OGLTransf );
}

//------------------------------------------------------------------------------

bool TCadEntity::CalcOGLGeom3D( TOGLTransf *OGLTransf )
{
	TOGLDisplayData dd, geo_dd;
	TCadSurface *paramSurface;

	if ( !CalcSISL( OGLTransf ) ) return false;

	if ( IsGeom3DDirty ) {
		paramSurface = ParamSurface;
		ParamSurface = 0;
		SetPolygonDirty( true, false );
		dd.Set( OGLPolygonList.GetOGLDisplayData( ) );
		geo_dd.Set( OGLGeom3DList.GetOGLDisplayData( ) );
		OGLPolygonList.SetOGLDisplayData( &geo_dd );
		OGLGeom3DList.TransferAll( GetOGLList( OGLTransf ) );
		OGLPolygonList.SetOGLDisplayData( &dd );
		ParamSurface = paramSurface;
		SetGeom3DDirty( false );
		SetPolygonDirty( true, false );
		SetDevelop2DDirty( true, false );
	}

	return OGLGeom3DList.Count( );
}

//------------------------------------------------------------------------------

bool TCadEntity::CalcOGLDevelop2D( TOGLTransf *OGLTransf )
{
	TCadSurface *paramSurface;
	TOGLDisplayData dd, dev_dd;

	if ( !CalcSISL( OGLTransf ) ) return false;

	if ( IsDevelop2DDirty ) {
		if ( IsDevelopable( ) ) {
			paramSurface = ParamSurface;
			ParamSurface = 0;
			SetPolygonDirty( true, false );
			dd.Set( OGLPolygonList.GetOGLDisplayData( ) );
			dev_dd.Set( OGLDevelop2DList.GetOGLDisplayData( ) );
			OGLPolygonList.SetOGLDisplayData( &dev_dd );
			OGLDevelop2DList.TransferAll( GetOGLList( OGLTransf ) );
			OGLPolygonList.SetOGLDisplayData( &dd );
			ParamSurface = paramSurface;
		} else
			OGLDevelop2DList.Clear( );

		SetDevelop2DDirty( false );
		SetPolygonDirty( true, false );
		SetGeom3DDirty( true, false );
	}
	return OGLDevelop2DList.Count( );
}

//------------------------------------------------------------------------------

bool TCadEntity::CalcOGLGeom3DFromParam2D( TOGLTransf *OGLTransf )
{
	bool close[ 2 ], checkdev, applyoffset;
	int i, j, k, c;
	double limits[ 4 ];
	T3DPoint pt, normal;
	T3DRect r3d;
	TOGLFloat3 vtx;
	TOGLPoint oglpt;
	TOGLPolygon *Pol, Pol2;

	if ( !IsGeom3DDirty || !IsParamEntity( ) ) // || OGLTransf->GetViewMode( ) == VIEW_PARAM2D ) //OGLTransf->GetViewMode( ) != VIEW_GEOM3D )
		return true;

	OGLGeom3DList.Clear( );
	if ( !OGLPolygonList.Count( ) ) return true;

	close[ 0 ] = ( GetParamSurface( )->GetUCloseExt( OGLTransf ) == ENT_CLOSE );
	close[ 1 ] = ( GetParamSurface( )->GetVCloseExt( OGLTransf ) == ENT_CLOSE );

	checkdev = ( GetParamSurface( )->HasDevelopData( ) && IsDevelopable( ) && GetForceDevelopSurfIndex( ) && GetDevelopSurfIndex( ) < GetParamSurface( )->GetDevelopList( )->CountSurfsInDevelop( ) ); // Cambio 02/2019 ForceDevelopSurfIndex por GetForceDevelopSurfIndex( ) pq en depshapes el valor se toma de la funcion de manera distinta a la variable
	if ( checkdev ) GetParamSurface( )->GetDevelopLimitsUV( OGLTransf, GetDevelopSurfIndex( ), limits );
	else
		GetParamSurface( )->GetLimitsUV( OGLTransf, limits );

	applyoffset = ( fabs( ParamOffset ) >= RES_GEOM );
	for ( i = 0; i < OGLPolygonList.Count( ); i++ ) {
		Pol = OGLPolygonList.GetItem( i );
		c = Pol->Count( );

		Pol2.Clear( );
		Pol2.SetType( Pol->GetType( ) );
		Pol2.SetUseNormals( Pol->GetUseNormals( ) );
		Pol2.SetUseTextures( Pol->GetUseTextures( ) );
		Pol2.MaterialIndex = Pol->MaterialIndex;
		Pol2.TessOrTrim = Pol->TessOrTrim;
		Pol2.ToolType = Pol->ToolType;
		Pol2.ToolReference = Pol->ToolReference;
		Pol2.ToolLayer = Pol->ToolLayer;
		Pol2.AdjustSize( c );
		for ( k = 0; k < c; k++ ) {
			vtx.Set( &( Pol->GetItem( k )->v ) );
			for ( j = 0; j < 2; j++ )
				vtx.v[ j ] = _ToParamRangeInLimitsF( vtx.v[ j ], close[ j ], limits[ j ], limits[ j + 2 ] );
			if ( !ParamSurface->GetPointAndNormal( OGLTransf, ( (double) vtx.v[ 0 ] ), ( (double) vtx.v[ 1 ] ), pt, normal ) ) {
				OGLGeom3DList.Clear( );
				return false;
			}
			if ( applyoffset ) pt += ( normal * ParamOffset );
			oglpt.v.SetPoint( pt );
			oglpt.uv.Set( Pol->GetItem( k )->v.v[ 0 ], Pol->GetItem( k )->v.v[ 1 ] );
			if ( Pol->GetUseNormals( ) ) oglpt.n.Set( &( Pol->GetItem( k )->n ) );
			if ( Pol->GetUseTextures( ) ) oglpt.t.Set( &( Pol->GetItem( k )->t ) );

			Pol2.AddItem( &oglpt );
		}
		OGLGeom3DList.Add( &Pol2 );
	}

	SetGeom3DDirty( false );
	return true;
}

//------------------------------------------------------------------------------

bool TCadEntity::CalcOGLDevelop2DFromParam2D( TOGLTransf *OGLTransf )
{
	int i;

	if ( !IsDevelop2DDirty ) return true;

	if ( OGLDevelop2DList.Count( ) ) OGLDevelop2DList.Clear( );

	if ( !OGLPolygonList.Count( ) || !IsParamEntity( ) || !GetParamSurface( )->HasDevelopData( ) || !IsDevelopable( ) ) {
		SetDevelop2DDirty( false );
		return true;
	}

	switch ( ParamInterpolationMode ) {
		case PIM_DEVELOP: break;
		case PIM_PARAM:
			//			if ( OGLTransf->GetForceMode( ) != VIEW_DEVELOP2D && !( OGLTransf->GetForceMode( ) == VIEW_NONE && OGLTransf->GetViewMode( ) == VIEW_DEVELOP2D ) )
			if ( OGLTransf->GetForceMode( ) == VIEW_GEOM3D || OGLTransf->GetForceMode( ) == VIEW_PARAM2D ) return true;
			break;
		case PIM_GEOM:
		case PIM_GEOMPARAM:
		case PIM_GEOMPARAMCT:
			//			if ( OGLTransf->GetForceMode( ) != VIEW_DEVELOP2D && !( OGLTransf->GetForceMode( ) == VIEW_NONE && OGLTransf->GetViewMode( ) == VIEW_DEVELOP2D ) )
			if ( OGLTransf->GetForceMode( ) == VIEW_GEOM3D || OGLTransf->GetForceMode( ) == VIEW_PARAM2D ) return true;
			break;
	}

	if ( GetForceDevelopSurfIndex( ) ) { // Cambio 02/2019 ForceDevelopSurfIndex por GetForceDevelopSurfIndex( ) pq en depshapes el valor se toma de la funcion de manera distinta a la variable
		GetParamSurface( )->GetExtBasicOGLDevelop2DFromParam2D( OGLTransf, &OGLPolygonList, GetDevelopSurfIndex( ), &OGLDevelop2DList );
		// A partir de la version 2 de lineas aplanables, no se fuerzan los poligonos para que no se calculen en 3D si no caen dentro del aplanado
		if ( !ToLine( this ) || Version >= LINE_VERSION_3 )
			for ( i = 0; i < OGLDevelop2DList.Count( ); i++ )
				OGLDevelop2DList.GetItem( i )->ForceDevelopSurfIndex = false;
	}

	SetDevelop2DDirty( false );
	return OGLDevelop2DList.Count( );
}

//------------------------------------------------------------------------------

bool TCadEntity::CalcOGLParam2DFromGeom3D( TOGLTransf *OGLTransf )
{
	int i, k, c;
	bool close[ 2 ], del, degen, d[ 4 ];
	double gpar[ 2 ], guess[ 2 ], limits[ 4 ], range[ 2 ], dist, distmin, distminsqr;
	TLPoint ptUV;
	T3DPoint fpoint, ptgeom, ptparam, oldptgeom, oldptparam, n, pt3D, n3D;
	T3DRect r3d;
	TOGLFloat2 uv;
	TOGLPoint oglpt;
	TOGLPolygon Pol2, *PolG;
	TCadEntity *entity;
	TCadSurface *surf;

	if ( !IsPolygonDirty || !IsParamEntity( ) ) return true;

	OGLPolygonList.Clear( );
	ClearOGLDeformer3DList( );
	if ( !OGLGeom3DList.Count( ) ) return true;

	entity = _CreateBasicShape( this, false );
	entity->SetParamSurface( ParamSurface );
	entity->SetParamInterpolationMode( PIM_PARAM );
	entity->SetOGLDisplayData( TESS_SHAPE, OGLPolygonList.OGLDisplayData.DisplayMode, OGLPolygonList.OGLDisplayData.TesselationMode[ TESS_SHAPE ], 1.0, 2.0, 10.0, TOGLFloat2( ) );
	entity->SetOGLDisplayData( TESS_SURF, OGLPolygonList.OGLDisplayData.DisplayMode, OGLPolygonList.OGLDisplayData.TesselationMode[ TESS_SURF ], 1.0, 2.0, 10.0, TOGLFloat2( ) );
	entity->SetDevelopable( false );
	OGLPolygonList.TransferAll( entity->GetOGLList( OGLTransf ) );
	delete entity;

	OGLPolygonList.GetVertex( 0, 0, oglpt.v );
	fpoint = oglpt.v.GetPoint( );
	OGLPolygonList.CalcBoundRect( r3d );
	OGLPolygonList.Clear( );

	GetParamSurface( )->GetLimitsUV( OGLTransf, limits );
	range[ 0 ] = limits[ 2 ] - limits[ 0 ];
	range[ 1 ] = limits[ 3 ] - limits[ 1 ];
	close[ 0 ] = ( GetParamSurface( )->GetUCloseExt( OGLTransf ) == ENT_CLOSE );
	close[ 1 ] = ( GetParamSurface( )->GetVCloseExt( OGLTransf ) == ENT_CLOSE );

	if ( close[ 0 ] ) {
		r3d.left -= ( 0.2 * range[ 0 ] );
		r3d.right += ( 0.2 * range[ 0 ] );
	}
	if ( close[ 1 ] ) {
		r3d.top -= ( 0.2 * range[ 1 ] );
		r3d.bottom += ( 0.2 * range[ 1 ] );
	}

	oldptgeom = OGLGeom3DList.GetItem( 0 )->GetItem( 0 )->v.GetPoint( );
	oldptparam = T3DPoint( _ToParamRangeInLimitsD( fpoint.x, close[ 0 ], limits[ 0 ], limits[ 2 ] ), _ToParamRangeInLimitsD( fpoint.y, close[ 1 ], limits[ 1 ], limits[ 3 ] ), 0.0 );

	degen = GetParamSurface( )->IsDegenerated( OGLTransf, d );
	del = false;
	if ( degen ) {
		surf = GetParamSurface( );
		distmin = DISTMIN_GUESS_DEGEN;
		distminsqr = DISTMIN_GUESS_DEGEN_SQR;
	} else {
		surf = GetParamSurface( )->ReplySurface( OGLTransf, r3d );
		if ( surf ) {
			surf->GetLimitsUV( OGLTransf, limits );
			del = true;
		} else
			surf = GetParamSurface( );
		distmin = DISTMIN_GUESS;
		distminsqr = DISTMIN_GUESS_SQR;
	}

	for ( i = 0; i < OGLGeom3DList.Count( ); i++ ) {
		PolG = OGLGeom3DList.GetItem( i );
		c = PolG->Count( );

		Pol2.Clear( );
		Pol2.SetType( PolG->GetType( ) );
		Pol2.SetUseNormals( PolG->GetUseNormals( ) );
		Pol2.SetUseTextures( PolG->GetUseTextures( ) );
		Pol2.MaterialIndex = PolG->MaterialIndex;
		Pol2.TessOrTrim = PolG->TessOrTrim;
		Pol2.ToolType = PolG->ToolType;
		Pol2.ToolReference = PolG->ToolReference;
		Pol2.ToolLayer = PolG->ToolLayer;
		Pol2.AdjustSize( c );
		for ( k = 0; k < c; k++ ) {
			if ( k > 0 && k == c - 1 && PolG->IsCloseExt( ) ) oglpt.v.Set( &( Pol2.GetItem( 0 )->v ) );
			else {
				ptgeom = PolG->GetItem( k )->v.GetPoint( );
				dist = ptgeom.DistanciaSqr( oldptgeom );
				while ( dist > distminsqr ) {
					T3DVector vec( oldptgeom, ptgeom );
					vec.Modulo( distmin );
					oldptgeom = vec.org + vec.size;
					guess[ 0 ] = oldptparam.x;
					guess[ 1 ] = oldptparam.y;
					if ( surf->GetParValuesSimple( OGLTransf, limits, close, oldptgeom, guess, gpar, range ) ) {			   // se ha añadido el parametro del final pq si hay replysurface es demasiado grande el rango que utiliza dentro
						if ( degen ) surf->ImproveParValuesSimpleInLimits( OGLTransf, gpar, limits, close, oldptgeom, guess ); //, 7, 10 );
					} else
						surf->GetParValues( OGLTransf, oldptgeom, gpar[ 0 ], gpar[ 1 ], 10.0 );
					oldptparam = T3DPoint( _ToParamRangeInLimitsD( gpar[ 0 ], close[ 0 ], limits[ 0 ], limits[ 2 ] ), _ToParamRangeInLimitsD( gpar[ 1 ], close[ 1 ], limits[ 1 ], limits[ 3 ] ), 0.0 );
					dist = ptgeom.DistanciaSqr( oldptgeom );
				}

				if ( i == 0 && k == 0 ) {
					surf->GetPoint( OGLTransf, oldptparam.x, oldptparam.y, pt3D );
					dist = pt3D.DistanciaSqr( oldptgeom );
					if ( dist < RES_GEOM ) {
						oglpt.v.SetPoint( oldptparam );
						oglpt.uv.Set( &( PolG->GetItem( k )->uv ) );
						Pol2.AddItem( &oglpt );
						continue;
					}
				}

				guess[ 0 ] = oldptparam.x;
				guess[ 1 ] = oldptparam.y;
				if ( surf->GetParValuesSimple( OGLTransf, limits, close, ptgeom, guess, gpar, range ) ) {				// se ha añadido el parametro del final pq si hay replysurface es demasiado grande el rango que utiliza dentro
					if ( degen ) surf->ImproveParValuesSimpleInLimits( OGLTransf, gpar, limits, close, ptgeom, guess ); //, 7, 10 );
				} else
					surf->GetParValues( OGLTransf, ptgeom, gpar[ 0 ], gpar[ 1 ], 10.0 );

				ptparam = T3DPoint( _ToParamRangeInLimitsD( gpar[ 0 ], close[ 0 ], limits[ 0 ], limits[ 2 ] ), _ToParamRangeInLimitsD( gpar[ 1 ], close[ 1 ], limits[ 1 ], limits[ 3 ] ), 0.0 );
				oglpt.v.SetPoint( ptparam );
				oldptgeom = ptgeom;
				oldptparam = ptparam;
			}
			oglpt.uv.Set( &( PolG->GetItem( k )->uv ) );
			Pol2.AddItem( &oglpt );
		}
		OGLPolygonList.Add( &Pol2 );
	}
	if ( del ) delete surf;

	if ( GetParamSurface( )->HasDevelopData( ) && IsDevelopable( ) && GetForceDevelopSurfIndex( ) && GetDevelopSurfIndex( ) < GetParamSurface( )->GetDevelopList( )->CountSurfsInDevelop( ) ) { // Cambio 02/2019 ForceDevelopSurfIndex por GetForceDevelopSurfIndex( ) pq en depshapes el valor se toma de la funcion de manera distinta a la variable
		GetParamSurface( )->GetDevelopLimitsUV( OGLTransf, GetDevelopSurfIndex( ), limits );
		OGLPolygonList.ToParamRangeInLimits( close, limits, false );
	} else {
		GetParamSurface( )->GetLimitsUV( OGLTransf, limits );
		OGLPolygonList.ToParamRangeInLimits( close, limits, false );
	}

	SetPolygonDirty( false );
	SetGeom3DDirty( true, false );
	SetDevelop2DDirty( true, false );

	return OGLPolygonList.Count( );
}

//------------------------------------------------------------------------------

bool TCadEntity::CalcOGLParam2DFromGeom3D_CT( TOGLTransf *OGLTransf )
{
	int i, k, c;
	bool close[ 2 ];
	double gpar[ 2 ], limits[ 4 ], range[ 2 ];
	TLPoint ptUV;
	T3DPoint pt, oldpt, n, pt3D, fnormal;
	T3DSize lastn;
	T3DRect r3d;
	TOGLFloat2 uv;
	TOGLPoint oglpt;
	TOGLPolygon Pol2, *PolG;
	TCadEntity *entity;

	if ( !IsPolygonDirty || !IsParamEntity( ) ) return true;

	OGLPolygonList.Clear( );
	ClearOGLDeformer3DList( );
	if ( !OGLGeom3DList.Count( ) ) return true;

	entity = _CreateBasicShape( this, false );
	entity->SetParamSurface( ParamSurface );
	entity->SetParamInterpolationMode( PIM_PARAM );
	entity->SetOGLDisplayData( TESS_SHAPE, OGLPolygonList.OGLDisplayData.DisplayMode, OGLPolygonList.OGLDisplayData.TesselationMode[ TESS_SHAPE ], 1.0, 2.0, 10.0, TOGLFloat2( ) );
	entity->SetOGLDisplayData( TESS_SURF, OGLPolygonList.OGLDisplayData.DisplayMode, OGLPolygonList.OGLDisplayData.TesselationMode[ TESS_SURF ], 1.0, 2.0, 10.0, TOGLFloat2( ) );
	entity->SetDevelopable( false );
	OGLPolygonList.TransferAll( entity->GetOGLList( OGLTransf ) );
	delete entity;

	OGLPolygonList.CalcBoundRect( r3d );
	pt3D = OGLPolygonList.GravityCenter( );
	OGLPolygonList.Clear( );

	GetParamSurface( )->GetLimitsUV( OGLTransf, limits );
	range[ 0 ] = limits[ 2 ] - limits[ 0 ];
	range[ 1 ] = limits[ 3 ] - limits[ 1 ];
	close[ 0 ] = ( GetParamSurface( )->GetUCloseExt( OGLTransf ) == ENT_CLOSE );
	close[ 1 ] = ( GetParamSurface( )->GetVCloseExt( OGLTransf ) == ENT_CLOSE );

	if ( close[ 0 ] ) {
		r3d.left -= ( 0.2 * range[ 0 ] );
		r3d.right += ( 0.2 * range[ 0 ] );
	}
	if ( close[ 1 ] ) {
		r3d.top -= ( 0.2 * range[ 1 ] );
		r3d.bottom += ( 0.2 * range[ 1 ] );
	}

	GetParamSurface( )->GetNormal( OGLTransf, pt3D.x, pt3D.y, fnormal );
	lastn = T3DSize( fnormal.x, fnormal.y, fnormal.z );

	for ( i = 0; i < OGLGeom3DList.Count( ); i++ ) {
		PolG = OGLGeom3DList.GetItem( i );
		c = PolG->Count( );

		Pol2.Clear( );
		Pol2.SetType( PolG->GetType( ) );
		Pol2.SetUseNormals( PolG->GetUseNormals( ) );
		Pol2.SetUseTextures( PolG->GetUseTextures( ) );
		Pol2.MaterialIndex = PolG->MaterialIndex;
		Pol2.TessOrTrim = PolG->TessOrTrim;
		Pol2.ToolType = PolG->ToolType;
		Pol2.ToolReference = PolG->ToolReference;
		Pol2.ToolLayer = PolG->ToolLayer;
		Pol2.AdjustSize( c );
		for ( k = 0; k < c; k++ ) {
			if ( k > 0 && k == c - 1 && PolG->IsCloseExt( ) ) oglpt.v.Set( &( Pol2.GetItem( 0 )->v ) );
			else {
				pt = PolG->GetItem( k )->v.GetPoint( );
				T3DVector v( lastn, pt );
				if ( GetParamSurface( )->Intersect( OGLTransf, v, ptUV, pt3D, n ) ) {
					pt.x = ptUV.x;
					pt.y = ptUV.y;
				} else {
					GetParamSurface( )->GetParValues( OGLTransf, pt, gpar[ 0 ], gpar[ 1 ], 10.0 );
					pt.x = gpar[ 0 ];
					pt.y = gpar[ 1 ];
					GetParamSurface( )->GetNormal( OGLTransf, pt.x, pt.y, n );
				}
				pt = T3DPoint( _ToParamRangeInLimitsD( pt.x, close[ 0 ], limits[ 0 ], limits[ 2 ] ), _ToParamRangeInLimitsD( pt.y, close[ 1 ], limits[ 1 ], limits[ 3 ] ), 0.0 );
				oglpt.v.SetPoint( pt );
				oldpt = pt;
			}
			oglpt.uv.Set( &( PolG->GetItem( k )->uv ) );
			Pol2.AddItem( &oglpt );
		}
		OGLPolygonList.Add( &Pol2 );
	}
	OGLGeom3DList.Clear( );

	if ( GetParamSurface( )->HasDevelopData( ) && IsDevelopable( ) && GetForceDevelopSurfIndex( ) && GetDevelopSurfIndex( ) < GetParamSurface( )->GetDevelopList( )->CountSurfsInDevelop( ) ) { // Cambio 02/2019 ForceDevelopSurfIndex por GetForceDevelopSurfIndex( ) pq en depshapes el valor se toma de la funcion de manera distinta a la variable
		GetParamSurface( )->GetDevelopLimitsUV( OGLTransf, GetDevelopSurfIndex( ), limits );
		OGLPolygonList.ToParamRangeInLimits( close, limits, false );
	} else {
		GetParamSurface( )->GetLimitsUV( OGLTransf, limits );
		OGLPolygonList.ToParamRangeInLimits( close, limits, false );
	}

	SetPolygonDirty( false );
	SetGeom3DDirty( true, false );
	SetDevelop2DDirty( true, false );

	return OGLPolygonList.Count( );
}

//------------------------------------------------------------------------------

bool TCadEntity::CalcOGLParam2DFromDevelop2D( TOGLTransf *OGLTransf )
{
	bool close[ 2 ], degen, d[ 4 ];
	int i, k, c, auxdevsurfindex;
	double gpar[ 2 ], guess[ 2 ], limitsUV[ 4 ], dist, distmin, distminsqr;
	T3DPoint ptdev, ptparam, oldptdev, oldptparam, n;
	TCadTensorSurface *DevSrf;
	TOGLFloat2 uv;
	TOGLPoint oglpt;
	TOGLPolygon Pol2, *PolD, emptypol;
	TOGLPolygonList auxdevlist, auxlist;

	if ( !IsPolygonDirty || !IsParamEntity( ) ) return true;

	OGLPolygonList.Clear( );
	ClearOGLDeformer3DList( );
	if ( !OGLDevelop2DList.Count( ) ) return true;

	if ( OGLDevelop2DList.GetItem( 0 )->ForceDevelopSurfIndex ) {
		for ( i = 0; i < OGLDevelop2DList.Count( ); i++ ) {
			auxdevsurfindex = OGLDevelop2DList.GetItem( i )->DevelopSurfIndex;
			auxdevlist.Add( OGLDevelop2DList.GetItem( i ) );
			if ( GetParamSurface( )->GetExtBasicOGLParam2DFromDevelop2D( OGLTransf, &auxdevlist, auxdevsurfindex, &auxlist ) ) {
				auxlist.GetItem( 0 )->DevelopSurfIndex = auxdevsurfindex;
				OGLPolygonList.Add( auxlist.GetItem( 0 ) );
			} else
				OGLPolygonList.Add( &emptypol );
			auxdevlist.Clear( );
		}
	} else {
		DevSrf = ToTensorSurface( GetTransfDevelopSurfIndexSurface( OGLTransf ) );
		if ( !DevSrf ) return true;

		DevSrf->GetLimitsUV( OGLTransf, limitsUV );
		close[ 0 ] = ( DevSrf->GetUCloseExt( OGLTransf ) == ENT_CLOSE );
		close[ 1 ] = ( DevSrf->GetVCloseExt( OGLTransf ) == ENT_CLOSE );
		degen = DevSrf->IsDegenerated( OGLTransf, d );
		if ( degen ) {
			distmin = DISTMIN_GUESS_DEGEN;
			distminsqr = DISTMIN_GUESS_DEGEN_SQR;
		} else {
			distmin = DISTMIN_GUESS;
			distminsqr = DISTMIN_GUESS_SQR;
		}

		for ( i = 0; i < OGLDevelop2DList.Count( ); i++ ) {
			PolD = OGLDevelop2DList.GetItem( i );
			c = PolD->Count( );

			Pol2.Clear( );
			Pol2.SetType( PolD->GetType( ) );
			Pol2.SetUseNormals( PolD->GetUseNormals( ) );
			Pol2.SetUseTextures( PolD->GetUseTextures( ) );
			Pol2.MaterialIndex = PolD->MaterialIndex;
			Pol2.TessOrTrim = PolD->TessOrTrim;
			Pol2.ToolType = PolD->ToolType;
			Pol2.ToolReference = PolD->ToolReference;
			Pol2.ToolLayer = PolD->ToolLayer;
			Pol2.AdjustSize( c );
			ptdev = PolD->GetItem( 0 )->v.GetPoint( );
			for ( k = 0; k < c; k++ ) {
				if ( k == 0 ) {
					DevSrf->GetParValues( OGLTransf, ptdev, guess[ 0 ], guess[ 1 ], 10.0 );
					if ( DevSrf->GetParValuesSimple( OGLTransf, limitsUV, close, ptdev, guess, gpar ) ) {
						//                  if ( degen )
						DevSrf->ImproveParValuesSimpleInLimits( OGLTransf, gpar, limitsUV, close, ptdev, guess ); //, 7, 10 );
					} else {
						gpar[ 0 ] = guess[ 0 ];
						gpar[ 1 ] = guess[ 1 ];
					}
					ptparam = T3DPoint( gpar[ 0 ], gpar[ 1 ], 0.0 );
					oglpt.v.SetPoint( ptparam );
					oldptdev = ptdev;
					oldptparam = ptparam;
				} else if ( k > 0 && k == c - 1 && PolD->IsCloseExt( ) )
					oglpt.v.Set( &( Pol2.GetItem( 0 )->v ) );
				else {
					ptdev = PolD->GetItem( k )->v.GetPoint( );
					dist = ptdev.DistanciaSqr( oldptdev );
					while ( dist > distminsqr ) {
						T3DVector vec( oldptdev, ptdev );
						vec.Modulo( distmin );
						oldptdev = vec.org + vec.size;
						guess[ 0 ] = oldptparam.x;
						guess[ 1 ] = oldptparam.y;
						if ( DevSrf->GetParValuesSimple( OGLTransf, limitsUV, close, oldptdev, guess, gpar ) ) {
							if ( degen ) DevSrf->ImproveParValuesSimpleInLimits( OGLTransf, gpar, limitsUV, close, oldptdev, guess ); //, 7, 10 );
						} else
							DevSrf->GetParValues( OGLTransf, oldptdev, gpar[ 0 ], gpar[ 1 ], 10.0 );
						oldptparam = T3DPoint( gpar[ 0 ], gpar[ 1 ], 0.0 );
						dist = ptdev.DistanciaSqr( oldptdev );
					}
					guess[ 0 ] = oldptparam.x;
					guess[ 1 ] = oldptparam.y;
					if ( DevSrf->GetParValuesSimple( OGLTransf, limitsUV, close, ptdev, guess, gpar ) ) {
						if ( degen ) DevSrf->ImproveParValuesSimpleInLimits( OGLTransf, gpar, limitsUV, close, ptdev, guess ); //, 7, 10 );
					} else
						DevSrf->GetParValues( OGLTransf, ptdev, gpar[ 0 ], gpar[ 1 ], 10.0 );
					ptparam = T3DPoint( gpar[ 0 ], gpar[ 1 ], 0.0 );
					oglpt.v.SetPoint( ptparam );
					oldptdev = ptdev;
					oldptparam = ptparam;
				}
				oglpt.uv.Set( &( PolD->GetItem( k )->uv ) );
				Pol2.AddItem( &oglpt );
			}
			OGLPolygonList.Add( &Pol2 );
		}
		close[ 0 ] = ( GetParamSurface( )->GetUCloseExt( OGLTransf ) == ENT_CLOSE );
		close[ 1 ] = ( GetParamSurface( )->GetVCloseExt( OGLTransf ) == ENT_CLOSE );
		OGLPolygonList.ToParamRangeInLimits( close, limitsUV, false );
	}

	SetPolygonDirty( false );
	SetGeom3DDirty( true, false );

	return OGLPolygonList.Count( );
}

//------------------------------------------------------------------------------

void TCadEntity::InitializePivot( TOGLTransf *OGLTransf, bool init_pos, bool init_refsystem )
{
	T3DPoint centroid;

	if ( !OGLTransf ) return;

	if ( !Pivot ) {
		Pivot = new TPivotData( );
		init_pos = true;
		init_refsystem = true;
	}

	if ( init_pos ) {
		GravityCenter( OGLTransf, centroid );
		Pivot->SetOrg( &centroid );
	}
	if ( init_refsystem ) Pivot->SetRefSystem( T3DSize( 1, 0, 0 ), T3DSize( 0, 1, 0 ), T3DSize( 0, 0, 1 ) );
}

//------------------------------------------------------------------------------

void TCadEntity::CreatePivot( )
{
	if ( !Pivot ) Pivot = new TPivotData( );
}

//------------------------------------------------------------------------------

TPivotData *TCadEntity::GetPivot( TOGLTransf *OGLTransf, bool force )
{
	if ( !force ) return Pivot;
	if ( !Pivot ) InitializePivot( OGLTransf, true, true );

	return Pivot;
}

//------------------------------------------------------------------------------

void TCadEntity::SetPivot( TPivotData *p )
{
	T3DSize x, y, z;

	if ( !p ) return;

	if ( !Pivot ) Pivot = new TPivotData( );

	Pivot->SetOrg( p->GetOrg( ) );
	p->GetRefSystem( x, y, z );
	Pivot->SetRefSystem( x, y, z );
}

//------------------------------------------------------------------------------

TOGLPolygonList *TCadEntity::GetOGLList( TOGLTransf *OGLTransf, bool recalc )
{
	if ( OGLTransf && recalc ) CalcOGLLists( OGLTransf );
	return &OGLPolygonList;
}

//------------------------------------------------------------------------------

TOGLPolygonList *TCadEntity::GetOGLParam2D( TOGLTransf *OGLTransf, bool recalc )
{
	return GetOGLList( OGLTransf, recalc );
}

//------------------------------------------------------------------------------

TOGLPolygonList *TCadEntity::GetOGLGeom3D( TOGLTransf *OGLTransf, bool recalc, bool force )
{
	if ( OGLTransf && recalc ) CalcOGLLists( OGLTransf );

	return ( ( IsParamEntity( ) || force ) ? &OGLGeom3DList : &OGLPolygonList );
}

//------------------------------------------------------------------------------

TOGLPolygonList *TCadEntity::GetOGLDevelop2D( TOGLTransf *OGLTransf, bool recalc )
{
	int forcemode;

	if ( OGLTransf && recalc ) {
		forcemode = OGLTransf->GetForceMode( );
		OGLTransf->SetForceMode( VIEW_DEVELOP2D );
		CalcOGLLists( OGLTransf );
		OGLTransf->SetForceMode( forcemode );
	}
	return &OGLDevelop2DList;
}

//------------------------------------------------------------------------------
// !!! Esta funcion devuelve los datos de ListPar en uv, no en v como GetOGLParam2D

TOGLPolygonList *TCadEntity::GetOGLGeom3DParam2D( TOGLTransf *OGLTransf, TOGLPolygonList *ListPar, bool recalc )
{
	bool reduce;

	if ( ParamInterpolationMode != PIM_GEOM ) {
		GetOGLGeom3D( OGLTransf, recalc );
		ListPar->Set( GetOGLParam2D( OGLTransf, recalc ) );
		ListPar->SetUVFromV( );
		return &OGLGeom3DList;
	}

	if ( !recalc || !CalcSISL( OGLTransf ) ) return &OGLGeom3DList;

	reduce = IsGeom3DDirty;
	if ( CalcOGLGeom3D( OGLTransf ) ) {
		if ( IsPolygonDirty || !OGLPolygonList.Count( ) ) {
			SetPolygonDirty( true, false );
			if ( CalcOGLParam2DFromGeom3D( OGLTransf ) ) {
				if ( reduce ) OGLGeom3DList.Filter( RES_GEOM, &OGLPolygonList, 0, MAX_PARAM / 4.0, true, false, true );
				ListPar->TransferAll( &OGLPolygonList );
				ListPar->SetUVFromV( );
				SetPolygonDirty( true, false );
			}
		} else {
			ListPar->Set( &OGLPolygonList );
			ListPar->SetUVFromV( );
		}
	}
	return &OGLGeom3DList;
}

//------------------------------------------------------------------------------
// !!!!!! Lista ListPar de entrada. Lista ListDev de salida
// !!!!!! ListPar debe tener los datos en uv, conectando con la funcion anterior

void TCadEntity::GetOGLParam2DDevelop2D( TOGLTransf *OGLTransf, TOGLPolygonList *ListPar, TOGLPolygonList *ListDev )
{
	int forcemode;

	forcemode = OGLTransf->GetForceMode( );
	OGLTransf->SetForceMode( VIEW_DEVELOP2D );
	if ( ParamInterpolationMode != PIM_GEOM ) {
		ListDev->Set( GetOGLDevelop2D( OGLTransf ) );
		ListPar->Set( GetOGLParam2D( OGLTransf ) ); // Hace falta actualizar porque se puede recalcular ListPar
		ListPar->SetUVFromV( );
		OGLTransf->SetForceMode( forcemode );
		return;
	}

	OGLPolygonList.Set( ListPar );
	OGLPolygonList.SetVFromUV( );
	SetPolygonDirty( false );
	SetDevelop2DDirty( true, false );
	if ( CalcOGLDevelop2DFromParam2D( OGLTransf ) ) {
		ListDev->TransferAll( &OGLDevelop2DList );
		OGLPolygonList.Clear( );
		ClearOGLDeformer3DList( );
		SetDevelop2DDirty( false );
		SetPolygonDirty( true, false );
	}
	OGLTransf->SetForceMode( forcemode );
}

//------------------------------------------------------------------------------
// !!! Esta funcion devuelve los datos de ListPar en uv, no en v como GetOGLParam2D

TOGLPolygonList *TCadEntity::GetOGLGeom3DParam2DDevelop2D( TOGLTransf *OGLTransf, TOGLPolygonList *ListPar, TOGLPolygonList *ListDev, bool recalc )
{
	bool reduce;
	int forcemode;

	if ( ParamInterpolationMode != PIM_GEOM ) {
		forcemode = OGLTransf->GetForceMode( );
		OGLTransf->SetForceMode( VIEW_DEVELOP2D );
		GetOGLGeom3D( OGLTransf, recalc );
		ListPar->Set( GetOGLParam2D( OGLTransf, recalc ) );
		ListPar->SetUVFromV( );
		ListDev->Set( GetOGLDevelop2D( OGLTransf ) );
		OGLTransf->SetForceMode( forcemode );
		return &OGLGeom3DList;
	}

	if ( !recalc || !CalcSISL( OGLTransf ) ) return &OGLGeom3DList;

	forcemode = OGLTransf->GetForceMode( );
	OGLTransf->SetForceMode( VIEW_DEVELOP2D );

	reduce = IsGeom3DDirty;
	if ( CalcOGLGeom3D( OGLTransf ) ) {
		if ( IsPolygonDirty || !OGLPolygonList.Count( ) ) {
			SetPolygonDirty( true, false );
			if ( CalcOGLParam2DFromGeom3D( OGLTransf ) ) {
				if ( reduce ) OGLGeom3DList.Filter( RES_GEOM, &OGLPolygonList, 0, MAX_PARAM / 4.0, true, false, true );
				ListPar->TransferAll( &OGLPolygonList );
				ListPar->SetUVFromV( );
				SetPolygonDirty( true, false );
			}
		} else {
			ListPar->Set( &OGLPolygonList );
			ListPar->SetUVFromV( );
		}
	}

	SetPolygonDirty( false );
	SetDevelop2DDirty( true, false );
	if ( CalcOGLDevelop2DFromParam2D( OGLTransf ) ) {
		ListDev->TransferAll( &OGLDevelop2DList );
		OGLPolygonList.Clear( );
		ClearOGLDeformer3DList( );
		SetDevelop2DDirty( false );
		SetPolygonDirty( true, false );
	}

	OGLTransf->SetForceMode( forcemode );

	return &OGLGeom3DList;
}

//------------------------------------------------------------------------------

void TCadEntity::GetOGLDualGeom2DOrDevelop2D( TOGLTransf *OGLTransf, TOGLPolygonList *Out, bool clear, bool recalc, bool, bool ) // forcerevertseconddevsurfindex, joinpolygons
{
	TOGLPolygonList *OGLList;

	if ( !Out ) return;
	if ( clear ) Out->Clear( );

	OGLList = 0;
	if ( IsParamEntity( ) ) {
		if ( IsDevelopable( ) && GetParamSurface( )->HasDevelop( ) ) OGLList = GetOGLDevelop2D( OGLTransf, recalc );
	} else // if ( IsInPlane( plXY ) ) Se supone en el plano XY.
		OGLList = GetOGLGeom3D( OGLTransf, recalc );

	if ( OGLList && OGLList->Count( ) ) Out->Append( OGLList );
}

//------------------------------------------------------------------------------

TOGLPolygonList *TCadEntity::GetOGL3DListByDeformMode( TOGLTransf *OGLTransf )
{
	if ( OGLTransf->GetDeformMode( ) != DEFORMER_VIEW_NONE && GetOGLDeformer3DList( OGLTransf ) ) return GetOGLDeformer3DList( OGLTransf );
	return GetOGLGeom3D( OGLTransf );
}

//------------------------------------------------------------------------------
// No se mira IsDeformer3DDirty pues se maneja desde fuera

TOGLPolygonList *TCadEntity::GetOGLDeformer3DList( TOGLTransf *OGLTransf, bool force )
{
	if ( force && !OGLDeformer3DList ) CreateOGLDeformer3DList( OGLTransf );

	return OGLDeformer3DList;
}

//------------------------------------------------------------------------------

void TCadEntity::SetOGLDeformer3DList( TOGLPolygonList *list )
{
	if ( !list || list == OGLDeformer3DList ) return;

	if ( !OGLDeformer3DList ) OGLDeformer3DList = new TOGLPolygonList( );
	OGLDeformer3DList->Set( list );
	IsDeformer3DDirty = false;
}

//------------------------------------------------------------------------------
// No se cambia IsDeformer3DDirty pues se maneja desde fuera

void TCadEntity::CreateOGLDeformer3DList( TOGLTransf *OGLTransf )
{
	TOGLPolygonList *list;

	if ( OGLDeformer3DList ) return;

	list = GetOGLGeom3D( OGLTransf ); // no se puede cambiar de orden
	OGLDeformer3DList = new TOGLPolygonList( );
	OGLDeformer3DList->Set( list );
}

//------------------------------------------------------------------------------

void TCadEntity::ClearOGLDeformer3DList( )
{
	if ( OGLDeformer3DList ) {
		delete OGLDeformer3DList;
		OGLDeformer3DList = 0;
		IsDeformer3DDirty = true;
	}
}

//------------------------------------------------------------------------------

TPBrepData *TCadEntity::GetPBrepData( bool force )
{
	if ( !IsFillEntity( false ) ) return 0;

	if ( !force ) return PBrepData;
	if ( !PBrepData ) PBrepData = new TPBrepData( this );

	return PBrepData;
}

//------------------------------------------------------------------------------
// Funcion utilizada solo en el RecoverUndo
void TCadEntity::SetPBrepData( TOGLTransf *OGLTransf, TPBrepData *pBrepData )
{
	if ( !OGLTransf || !pBrepData ) return;

	ClearPBrepData( );

	PBrepData = new TPBrepData( this );
	PBrepData->Set( OGLTransf, pBrepData );
}

//------------------------------------------------------------------------------

IwPolyBrep *TCadEntity::GetPBrep( TOGLTransf *OGLTransf, bool force )
{
	if ( !GetPBrepData( force ) ) return 0;

	return GetPBrepData( )->GetPBrep( OGLTransf );
}

//------------------------------------------------------------------------------

void TCadEntity::CreatePBrep( TOGLTransf *OGLTransf, bool force, bool forcecheckpbrep )
{
	if ( !GetPBrepData( force ) ) return;

	GetPBrepData( )->CreatePBrep( OGLTransf, forcecheckpbrep );
}

//------------------------------------------------------------------------------

void TCadEntity::ClearPBrepData( )
{
	if ( PBrepData ) {
		delete PBrepData;
		PBrepData = 0;
	}
	SetPBrepDirty( true );
}

//------------------------------------------------------------------------------

void TCadEntity::UpdateOGLListFromPBrep( TOGLTransf *OGLTransf, bool checkSelected, bool calculateNormals, bool updatetexcoords, bool recalcTopology )
{
	if ( !GetPBrepData( ) ) return;

	GetPBrepData( )->UpdateOGLListFromPBrep( OGLTransf, GetOGLGeom3D( OGLTransf ), checkSelected, calculateNormals, updatetexcoords, recalcTopology );

	// Despues de esta operación se pretende poner a Dirty todas las entidades dependientes.
	// Como no existe esta función, se llama a SetPolygonDirty a true, que las pone, y luego a false para quitar IsPolygonDirty e IsPBrepDirty
	SetPolygonDirty( true );
	SetPolygonDirty( false );
	SetPBrepDirty( false );
}

//------------------------------------------------------------------------------

void TCadEntity::UpdatePBrepUVFromOGLList( TOGLTransf *OGLTransf, TOGLPolygonList *develop )
{
	if ( !GetPBrepData( ) ) return;

	GetPBrepData( )->UpdatePBrepUVFromOGLList( OGLTransf, develop );
}

//------------------------------------------------------------------------------

void TCadEntity::UpdateNormalsOGLListFromPBrep( TOGLTransf *OGLTransf, bool onlyinvalids )
{
	if ( !GetPBrepData( ) ) return;

	GetPBrepData( )->UpdateNormalsOGLListFromPBrep( OGLTransf, 0, onlyinvalids );

	// Despues de esta operación se pretende poner a Dirty todas las entidades dependientes.
	// Como no existe esta función, se llama a SetPolygonDirty a true, que las pone, y luego a false para quitar IsPolygonDirty e IsPBrepDirty
	SetPolygonDirty( true );
	SetPolygonDirty( false );
	SetPBrepDirty( false );
}

//------------------------------------------------------------------------------

void TCadEntity::UpdateColorsFromPBrep( TOGLTransf *OGLTransf, TColor *cIni, TColor *cEnd )
{
	TOGLPolygonList *OGLList;

	if ( !GetPBrepData( ) ) return;

	OGLList = GetOGLGeom3D( OGLTransf );
	if ( !OGLList->Count( ) ) return;

	GetOGLRenderData( )->SetColors( OGLList );
	Download( );
	GetPBrepData( )->UpdateColorsFromPBrep( OGLTransf, GetOGLRenderData( )->Colors, cIni, cEnd );
}

//------------------------------------------------------------------------------

void TCadEntity::UpdateNormalsFromPBrep( TOGLTransf *OGLTransf )
{
	if ( !GetPBrepData( ) ) return;

	GetPBrepData( )->UpdateNormalsFromPBrep( OGLTransf, GetOGLGeom3D( OGLTransf ) );
}

//------------------------------------------------------------------------------

TOGLPolygonList *TCadEntity::GetTextureCoords( TOGLTransf *OGLTransf, TOGLTexture *Texture, bool forcedeform )
{
	if ( !CalcTextureCoords( OGLTransf, Texture ) ) return 0;
	if ( ( forcedeform || OGLTransf->GetDeformMode( ) != DEFORMER_VIEW_NONE ) && GetOGLDeformer3DList( OGLTransf ) ) {
		if ( IsDeformerTextureDirty ) UpdateDeformed3DListTextureCoords( OGLTransf );
		return GetOGLDeformer3DList( OGLTransf );
	}
	return GetOGLGeom3D( OGLTransf );
}

//------------------------------------------------------------------------------

void TCadEntity::GetBaseTextureCoords( TOGLTransf *OGLTransf, TOGLPolygonList *baseTextureCoords, int index )
{
	CalcBaseTextureCoords( OGLTransf, baseTextureCoords, index );
}

//------------------------------------------------------------------------------

bool TCadEntity::CalcTextureCoords( TOGLTransf *OGLTransf, TOGLTexture *_OGLTexture )
{
	int i, k, c, orgWidth, orgHeight, width, height;
	double a, b, sin_angle, cos_angle, zoom_factor2x, zoom_factor2y, resolution, resmm;
	TLPoint factor2, imagesizemm;
	T3DPoint pt2D;
	TOGLPolygon *Pol;
	TOGLPolygonList *OGLList;
	TOGLTextureData *ogltexturedata;

	if ( !CalcOGLLists( OGLTransf ) ) return false;

	if ( !IsTextureDirty ) return true;
	ogltexturedata = GetOGLTextureData( );
	if ( !ogltexturedata ) return false;

	if ( ogltexturedata->UseBaseTextures ) return CalcEndTextureCoords( OGLTransf, _OGLTexture );
	if ( !_OGLTexture || ogltexturedata->TextureMode == TEXTURE_UV ) return false;

	////////////////
	if ( AppliedRemesh ) {
		if ( _OGLTexture->OrgWidth > 0 && _OGLTexture->OrgHeight > 0 && _OGLTexture->Resolution > 0 ) {
			orgWidth = _OGLTexture->OrgWidth;
			orgHeight = _OGLTexture->OrgHeight;
			resolution = _OGLTexture->Resolution;
		} else {
			orgWidth = DEFAULT_TEXTURE_WIDTH;
			orgHeight = DEFAULT_TEXTURE_HEIGHT;
			resolution = DEFAULT_TEXTURE_RESOLUTION;
		}

		resmm = resolution / 25.4;
		factor2.x = resmm / ( (double) orgWidth );
		factor2.y = resmm / ( (double) orgHeight );
		imagesizemm.x = (double) orgWidth / resmm;
		imagesizemm.y = (double) orgHeight / resmm;
		OGLList = GetOGLGeom3D( OGLTransf );
		sin_angle = sin( ogltexturedata->Angle );
		cos_angle = cos( ogltexturedata->Angle );
		zoom_factor2x = factor2.x * ogltexturedata->Zoom;
		zoom_factor2y = factor2.y * ogltexturedata->Zoom;
		for ( i = 0; i < OGLList->Count( ); i++ ) {
			Pol = OGLList->GetItem( i );
			c = Pol->Count( );
			for ( k = 0; k < c; k++ ) {
				pt2D = Pol->GetItem( k )->uv.Get3DPoint( );
				a = ( pt2D.x + ogltexturedata->Origin.x + imagesizemm.x / 2.0 );
				b = ( pt2D.y + ogltexturedata->Origin.y + imagesizemm.y / 2.0 );
				Pol->GetItem( k )->t.v[ 0 ] = ( a * cos_angle - b * sin_angle ) * zoom_factor2x;
				Pol->GetItem( k )->t.v[ 1 ] = ( a * sin_angle + b * cos_angle ) * zoom_factor2y;
			}
		}
		OGLList->Download( );
		SetTextureDirty( false );
		return true;
	}
	///////////////

	// Nuevo, 03/2022
	if ( ogltexturedata->TextureMode == TEXTURE_FIX ) {
		//		int ver_si_hay_que_hacerlo_en_CalcBaseTextureCoords;
		width = ( _OGLTexture->Width > 0 ? _OGLTexture->Width : DEFAULT_TEXTURE_WIDTH );
		height = ( _OGLTexture->Height > 0 ? _OGLTexture->Height : DEFAULT_TEXTURE_HEIGHT );

		OGLList = GetOGLGeom3D( OGLTransf );

		sin_angle = sin( ogltexturedata->Angle );
		cos_angle = cos( ogltexturedata->Angle );
		zoom_factor2x = ogltexturedata->Zoom;
		zoom_factor2y = ogltexturedata->Zoom;

		for ( i = 0; i < OGLList->Count( ); i++ ) {
			Pol = OGLList->GetItem( i );
			c = Pol->Count( );
			for ( k = 0; k < c; k++ ) {
				pt2D = Pol->GetItem( k )->uv.Get3DPoint( );
				a = ( pt2D.x + ogltexturedata->Origin.x / double( width ) ); // dividimos por width porque las coord de textura vienen entre 0 y 1
				b = ( pt2D.y + ogltexturedata->Origin.y / double( height ) );
				Pol->GetItem( k )->t.v[ 0 ] = ( a * cos_angle - b * sin_angle ) * zoom_factor2x;
				Pol->GetItem( k )->t.v[ 1 ] = ( a * sin_angle + b * cos_angle ) * zoom_factor2y;
			}
		}
		OGLList->Download( );
		SetTextureDirty( false );
		return true;
	}

	return false;
}

//------------------------------------------------------------------------------

bool TCadEntity::CalcBaseTextureCoords( TOGLTransf *OGLTransf, TOGLPolygonList *baseTextureCoords, int index )
{
	TOGLPolygonList *OGLList;
	TOGLTextureData *ogltexturedata;
	TOGLTextureDataList *textureDataList;

	if ( AppliedRemesh ) {
		if ( !baseTextureCoords ) return false;
		if ( !CalcOGLLists( OGLTransf ) ) return false;
		baseTextureCoords->Clear( );
		textureDataList = GetOGLTextureDataList( );
		if ( !textureDataList ) return false;
		ogltexturedata = GetOGLTextureData( index );
		if ( !ogltexturedata ) return false;
		ogltexturedata->RotationCenter = TPoint( 0.0, 0.0 );
		ogltexturedata->TempTextureMode = TEXTURE_DEVELOP_FIX;
		OGLList = GetOGL3DListByDeformMode( OGLTransf );
		baseTextureCoords->Set( OGLList );
		return true;
	}

	return false;
}

//------------------------------------------------------------------------------

bool TCadEntity::CalcEndTextureCoords( TOGLTransf *OGLTransf, TOGLTexture *_OGLTexture )
{
	int i, k, c, orgWidth, orgHeight, width, height;
	double a, b, sin_angle, cos_angle, zoom_factor2x, zoom_factor2y, resolution, resmm;
	TLPoint lengthUV, factor, factor2, imagesizemm, incr, rotation_center;
	TLRect rect;
	T3DPoint pt2D;
	TOGLPolygon *Pol;
	TOGLPolygonList *OGLList;
	TOGLTextureData *ogltexturedata;

	if ( !OGLTransf || !_OGLTexture ) return false;

	ogltexturedata = GetOGLTextureData( );
	if ( !ogltexturedata ) return false;

	if ( _OGLTexture->OrgWidth > 0 && _OGLTexture->OrgHeight > 0 && _OGLTexture->Resolution > 0 ) {
		orgWidth = _OGLTexture->OrgWidth;
		orgHeight = _OGLTexture->OrgHeight;
		resolution = _OGLTexture->Resolution;
	} else {
		orgWidth = DEFAULT_TEXTURE_WIDTH;
		orgHeight = DEFAULT_TEXTURE_HEIGHT;
		resolution = DEFAULT_TEXTURE_RESOLUTION;
	}

	if ( ogltexturedata->BaseTextureUVList && ogltexturedata->BaseTextureUVList->Count( ) ) {
		OGLList = GetOGLGeom3D( OGLTransf );
		for ( i = 0; i < OGLList->Count( ); i++ ) {
			Pol = OGLList->GetItem( i );
			// En ficheros antiguos puede pasar que no coincida el numero de vertices con las coordenadas de textura, se deja por si acaso.
			c = min( Pol->Count( ), ogltexturedata->BaseTextureUVList->Count( ) / 2 );
			for ( k = 0; k < c; k++ ) {
				Pol->GetItem( k )->uv.v[ 0 ] = *ogltexturedata->BaseTextureUVList->GetItem( ( i + k ) * 2 );
				Pol->GetItem( k )->uv.v[ 1 ] = *ogltexturedata->BaseTextureUVList->GetItem( ( i + k ) * 2 + 1 );
			}
		}
	}

	if ( ogltexturedata->TempTextureMode == TEXTURE_PARAM ) {
		lengthUV = ogltexturedata->LengthUV;
		if ( lengthUV.x > 0.0 && lengthUV.y > 0.0 ) {
			factor.x = lengthUV.x / ( (double) MAX_PARAM );
			factor.y = lengthUV.y / ( (double) MAX_PARAM );
			rotation_center = ogltexturedata->RotationCenter;
			factor2.x = resolution / ( 25.4 * ( (double) orgWidth ) );
			factor2.y = resolution / ( 25.4 * ( (double) orgHeight ) );
			sin_angle = sin( ogltexturedata->Angle );
			cos_angle = cos( ogltexturedata->Angle );
			zoom_factor2x = factor2.x * ogltexturedata->Zoom;
			zoom_factor2y = factor2.y * ogltexturedata->Zoom;

			OGLList = GetOGLGeom3D( OGLTransf );
			for ( i = 0; i < OGLList->Count( ); i++ ) {
				Pol = OGLList->GetItem( i );
				c = Pol->Count( );
				for ( k = 0; k < c; k++ ) {
					a = ( Pol->GetItem( k )->uv.v[ 0 ] + ogltexturedata->Origin.x - rotation_center.x );
					b = ( Pol->GetItem( k )->uv.v[ 1 ] + ogltexturedata->Origin.y - rotation_center.y );
					Pol->GetItem( k )->t.v[ 0 ] = ( a * cos_angle - b * sin_angle ) * factor.x * zoom_factor2x;
					Pol->GetItem( k )->t.v[ 1 ] = ( a * sin_angle + b * cos_angle ) * factor.y * zoom_factor2y;
				}
			}
			OGLList->Download( );
		}
	} else if ( ogltexturedata->TempTextureMode == TEXTURE_DEVELOP_FIX || ogltexturedata->TempTextureMode == TEXTURE_CURVE ) {
		rotation_center = ogltexturedata->RotationCenter;
		resmm = resolution / 25.4;
		factor2.x = resmm / ( (double) orgWidth );
		factor2.y = resmm / ( (double) orgHeight );
		imagesizemm.x = (double) orgWidth / resmm;
		imagesizemm.y = (double) orgHeight / resmm;

		sin_angle = sin( ogltexturedata->Angle );
		cos_angle = cos( ogltexturedata->Angle );
		zoom_factor2x = factor2.x * ogltexturedata->Zoom;
		zoom_factor2y = factor2.y * ogltexturedata->Zoom;

		incr.x = ogltexturedata->Origin.x - rotation_center.x + imagesizemm.x / 2.0;
		incr.y = ogltexturedata->Origin.y - rotation_center.y + imagesizemm.y / 2.0;

		OGLList = GetOGLGeom3D( OGLTransf );
		for ( i = 0; i < OGLList->Count( ); i++ ) {
			Pol = OGLList->GetItem( i );
			c = Pol->Count( );
			for ( k = 0; k < c; k++ ) {
				a = ( Pol->GetItem( k )->uv.v[ 0 ] + incr.x );
				b = ( Pol->GetItem( k )->uv.v[ 1 ] + incr.y );
				Pol->GetItem( k )->t.v[ 0 ] = ( a * cos_angle - b * sin_angle ) * zoom_factor2x;
				Pol->GetItem( k )->t.v[ 1 ] = ( a * sin_angle + b * cos_angle ) * zoom_factor2y;
			}
		}

		OGLList->Download( );
	} else if ( ogltexturedata->TempTextureMode == TEXTURE_FIX ) { //
		width = ( _OGLTexture->Width > 0 ? _OGLTexture->Width : DEFAULT_TEXTURE_WIDTH );
		height = ( _OGLTexture->Height > 0 ? _OGLTexture->Height : DEFAULT_TEXTURE_HEIGHT );

		rotation_center = ogltexturedata->RotationCenter;
		sin_angle = sin( ogltexturedata->Angle );
		cos_angle = cos( ogltexturedata->Angle );
		zoom_factor2x = ogltexturedata->Zoom;
		zoom_factor2y = ogltexturedata->Zoom;

		OGLList = GetOGLGeom3D( OGLTransf );
		for ( i = 0; i < OGLList->Count( ); i++ ) {
			Pol = OGLList->GetItem( i );
			c = Pol->Count( );
			for ( k = 0; k < c; k++ ) {
				pt2D = Pol->GetItem( k )->uv.Get3DPoint( );
				a = ( pt2D.x + ogltexturedata->Origin.x / double( width ) - rotation_center.x ); // dividimos por width porque las coord de textura vienen entre 0 y 1
				b = ( pt2D.y + ogltexturedata->Origin.y / double( height ) - rotation_center.y );
				Pol->GetItem( k )->t.v[ 0 ] = ( a * cos_angle - b * sin_angle ) * zoom_factor2x;
				Pol->GetItem( k )->t.v[ 1 ] = ( a * sin_angle + b * cos_angle ) * zoom_factor2y;
			}
		}

		OGLList->Download( );
	} else if ( ogltexturedata->TempTextureMode == TEXTURE_UV ) {
		OGLList = GetOGLGeom3D( OGLTransf );
		for ( i = 0; i < OGLList->Count( ); i++ )
			for ( k = 0; k < OGLList->GetItem( i )->Count( ); k++ )
				OGLList->GetItem( i )->GetItem( k )->t.Set( &( OGLList->GetItem( i )->GetItem( k )->uv ) );

		OGLList->Download( );
	} else if ( ogltexturedata->TempTextureMode == TEXTURE_GEOM ) {
		factor.x = lengthUV.x / ( (double) ogltexturedata->Box.Width( ) );
		factor.y = lengthUV.y / ( (double) ogltexturedata->Box.Height( ) );

		rotation_center = ogltexturedata->RotationCenter;

		resmm = resolution / 25.4;
		factor2.x = resmm / ( (double) orgWidth );
		factor2.y = resmm / ( (double) orgHeight );
		imagesizemm.x = (double) orgWidth / resmm;
		imagesizemm.y = (double) orgHeight / resmm;
		sin_angle = sin( ogltexturedata->Angle );
		cos_angle = cos( ogltexturedata->Angle );
		zoom_factor2x = factor2.x * ogltexturedata->Zoom;
		zoom_factor2y = factor2.y * ogltexturedata->Zoom;

		incr.x = ogltexturedata->Origin.x - rotation_center.x + imagesizemm.x / 2.0;
		incr.y = ogltexturedata->Origin.y - rotation_center.y + imagesizemm.y / 2.0;

		OGLList = GetOGLGeom3D( OGLTransf );
		for ( i = 0; i < OGLList->Count( ); i++ ) {
			Pol = OGLList->GetItem( i );
			c = Pol->Count( );
			for ( k = 0; k < c; k++ ) {
				a = Pol->GetItem( k )->uv.v[ 0 ] + incr.x;
				b = Pol->GetItem( k )->uv.v[ 1 ] + incr.y;
				Pol->GetItem( k )->t.v[ 0 ] = ( a * cos_angle - b * sin_angle ) * factor.x * zoom_factor2x;
				Pol->GetItem( k )->t.v[ 1 ] = ( a * sin_angle + b * cos_angle ) * factor.y * zoom_factor2y;
			}
		}

		OGLList->Download( );
	}

	SetTextureDirty( false );

	return true;
}

//------------------------------------------------------------------------------

bool TCadEntity::HasOGLList( TOGLTransf *OGLTransf )
{
	return ( CalcOGLLists( OGLTransf ) && OGLPolygonList.Count( ) );
}

//------------------------------------------------------------------------------

bool TCadEntity::IsRightViewMode( TOGLTransf *OGLTransf )
{
	int forcemode;

	if ( !IsParamEntity( ) || ParamInterpolationMode != PIM_GEOM ) return true;
	forcemode = OGLTransf->GetForceMode( );
	return ( !( ( forcemode == VIEW_PARAM2D || ( forcemode == VIEW_NONE && OGLTransf->GetViewMode( ) == VIEW_PARAM2D ) || forcemode == VIEW_DEVELOP2D || ( forcemode == VIEW_NONE && OGLTransf->GetViewMode( ) == VIEW_DEVELOP2D ) ) ) );
}

//------------------------------------------------------------------------------

int TCadEntity::GetNumberOGLViewLists( TOGLTransf *OGLTransf, bool recalc )
{
	int nlists, forcemode, deformmode;
	TCadGroup *grp;

	nlists = 0;
	if ( recalc && !CalcOGLLists( OGLTransf ) ) return 0;
	forcemode = OGLTransf->GetForceMode( );
	deformmode = OGLTransf->GetDeformMode( );
	if ( IsParamEntity( ) ) {
		if ( !IsRightViewMode( OGLTransf ) ) return 0;
		if ( forcemode == VIEW_GEOM3D || ( forcemode == VIEW_NONE && OGLTransf->GetViewMode( ) == VIEW_GEOM3D ) ) {
			switch ( deformmode ) {
				case DEFORMER_VIEW_NONE: nlists = 1; break;
				case DEFORMER_VIEW_ONLYDEF:
					if ( GetOGLDeformer3DList( OGLTransf ) ) nlists = 1;
					else
						nlists = 0;
					break;
				case DEFORMER_VIEW_ALL: nlists = 1; break;
			}
		} else if ( forcemode == VIEW_DEVELOP2D || ( forcemode == VIEW_NONE && OGLTransf->GetViewMode( ) == VIEW_DEVELOP2D ) )
			nlists = 1;
		else if ( forcemode == VIEW_PARAM2D || ( forcemode == VIEW_NONE && OGLTransf->GetViewMode( ) == VIEW_PARAM2D ) )
			nlists = 1;
		return nlists;
	}

	if ( forcemode == VIEW_DEVELOP2D || ( forcemode == VIEW_NONE && OGLTransf->GetViewMode( ) == VIEW_DEVELOP2D ) ) {
		grp = GetTransfDevelopSurfaces( OGLTransf );
		nlists = grp ? grp->Count( ) : 1;
	}

	if ( forcemode == VIEW_GEOM3D || ( forcemode == VIEW_NONE && OGLTransf->GetViewMode( ) == VIEW_GEOM3D ) ) {
		switch ( deformmode ) {
			case DEFORMER_VIEW_NONE: nlists = 1; break;
			case DEFORMER_VIEW_ONLYDEF:
				if ( GetOGLDeformer3DList( OGLTransf ) ) nlists = 1;
				else
					nlists = 0;
				break;
			case DEFORMER_VIEW_ALL: nlists = 1; break;
		}
	}
	return nlists;
}

//------------------------------------------------------------------------------

int TCadEntity::GetOGLViewLists( TOGLTransf *OGLTransf, TOGLPolygonList ***Lists, int index, bool recalc )
{
	int i, nlists, forcemode, deformmode;
	TCadGroup *grp;

	nlists = GetNumberOGLViewLists( OGLTransf, recalc );
	if ( recalc && !CalcOGLLists( OGLTransf ) ) return nlists;

	if ( nlists == 0 ) return 0;

	( *Lists ) = ( ( *Lists ) == 0 && nlists ) ? new TOGLPolygonList *[ nlists ] : 0;
	forcemode = OGLTransf->GetForceMode( );
	deformmode = OGLTransf->GetDeformMode( );
	if ( IsParamEntity( ) ) {
		if ( !IsRightViewMode( OGLTransf ) ) return 0;
		if ( forcemode == VIEW_GEOM3D || ( forcemode == VIEW_NONE && OGLTransf->GetViewMode( ) == VIEW_GEOM3D ) ) {
			switch ( deformmode ) {
				case DEFORMER_VIEW_NONE:
					( *Lists )[ index ] = GetOGLGeom3D( OGLTransf, recalc );
					( *Lists )[ index ]->SetID( ( ID >= 0 ? ( NUM_ENT_OGLLISTS * ID + 1 ) : -1 ) );
					break;
				case DEFORMER_VIEW_ONLYDEF:
					if ( GetOGLDeformer3DList( OGLTransf ) ) {
						( *Lists )[ index ] = GetOGLDeformer3DList( OGLTransf );
						( *Lists )[ index ]->SetID( ( ID >= 0 ? ( NUM_ENT_OGLLISTS * ID + 3 ) : -1 ) );
					}
					break;
				case DEFORMER_VIEW_ALL:
					if ( GetOGLDeformer3DList( OGLTransf ) ) {
						( *Lists )[ index ] = GetOGLDeformer3DList( OGLTransf );
						( *Lists )[ index ]->SetID( ( ID >= 0 ? ( NUM_ENT_OGLLISTS * ID + 3 ) : -1 ) );
					} else {
						( *Lists )[ index ] = GetOGLGeom3D( OGLTransf, recalc );
						( *Lists )[ index ]->SetID( ( ID >= 0 ? ( NUM_ENT_OGLLISTS * ID + 1 ) : -1 ) );
					}
					break;
			}
		} else if ( forcemode == VIEW_DEVELOP2D || ( forcemode == VIEW_NONE && OGLTransf->GetViewMode( ) == VIEW_DEVELOP2D ) ) {
			( *Lists )[ index ] = GetOGLDevelop2D( OGLTransf, recalc );
			( *Lists )[ index ]->SetID( ( ID >= 0 ? ( NUM_ENT_OGLLISTS * ID + 2 ) : -1 ) );
		} else if ( forcemode == VIEW_PARAM2D || ( forcemode == VIEW_NONE && OGLTransf->GetViewMode( ) == VIEW_PARAM2D ) ) {
			( *Lists )[ index ] = GetOGLList( OGLTransf, recalc );
			( *Lists )[ index ]->SetID( ( ID >= 0 ? ( NUM_ENT_OGLLISTS * ID ) : -1 ) );
		}
		return nlists;
	}

	if ( forcemode == VIEW_DEVELOP2D || ( forcemode == VIEW_NONE && OGLTransf->GetViewMode( ) == VIEW_DEVELOP2D ) ) {
		grp = GetTransfDevelopSurfaces( OGLTransf );
		if ( grp )
			for ( i = 0; i < nlists; i++ )
				( *Lists )[ index + i ] = grp->GetShape( i )->GetOGLList( OGLTransf, recalc );
		else {
			( *Lists )[ index ] = GetOGLList( OGLTransf, recalc );
			( *Lists )[ index ]->SetID( ( ID >= 0 ? ( NUM_ENT_OGLLISTS * ID + 2 ) : -1 ) );
		}
	}
	if ( forcemode == VIEW_GEOM3D || ( forcemode == VIEW_NONE && OGLTransf->GetViewMode( ) == VIEW_GEOM3D ) ) {
		switch ( deformmode ) {
			case DEFORMER_VIEW_NONE:
				( *Lists )[ index ] = GetOGLList( OGLTransf, recalc );
				( *Lists )[ index ]->SetID( ( ID >= 0 ? ( NUM_ENT_OGLLISTS * ID ) : -1 ) );
				break;
			case DEFORMER_VIEW_ONLYDEF:
				if ( GetOGLDeformer3DList( OGLTransf ) ) {
					( *Lists )[ index ] = GetOGLDeformer3DList( OGLTransf );
					( *Lists )[ index ]->SetID( ( ID >= 0 ? ( NUM_ENT_OGLLISTS * ID + 3 ) : -1 ) );
				}
				break;
			case DEFORMER_VIEW_ALL:
				if ( GetOGLDeformer3DList( OGLTransf ) ) {
					( *Lists )[ index ] = GetOGLDeformer3DList( OGLTransf );
					( *Lists )[ index ]->SetID( ( ID >= 0 ? ( NUM_ENT_OGLLISTS * ID + 3 ) : -1 ) );
				} else {
					( *Lists )[ index ] = GetOGLList( OGLTransf, recalc );
					( *Lists )[ index ]->SetID( ( ID >= 0 ? ( NUM_ENT_OGLLISTS * ID ) : -1 ) );
				}
				break;
		}
	}
	return nlists;
}

//------------------------------------------------------------------------------

int TCadEntity::GetWorkingViewMode( )
{
	TCadEntity *baseEntity;

	baseEntity = GetDualBaseEntity( );
	if ( baseEntity->GetDualShapeByDep( ) ) {
		//		if ( baseEntity->IsParamEntity( ) ) return VIEW_NONE; else
		return VIEW_DEVELOP2D;
	} else if ( baseEntity->IsParamEntity( ) ) {
		if ( baseEntity->IsDevelopable( ) && baseEntity->GetParamSurface( )->HasDevelop( ) ) {
			return VIEW_DEVELOP2D;
		} else
			return VIEW_NONE;
	} else
		return VIEW_GEOM3D;
}

//------------------------------------------------------------------------------

TCadSurface *TCadEntity::GetBaseSurface( )
{
	if ( ToDepSurface( ParamSurface ) ) return ParamSurface->GetBaseSurface( );

	return ParamSurface;
}

//------------------------------------------------------------------------------

void TCadEntity::SetParamSurface( TCadSurface *s, bool onlyset )
{
	ParamSurface = s;
	if ( onlyset ) return;

	SetAllDirty( true, false );
}

//------------------------------------------------------------------------------

TCadSurface *TCadEntity::GetDualBaseSurface( )
{
	TCadSurface *surf;

	surf = GetDualParamSurface( );
	if ( surf ) return surf;

	return GetBaseSurface( );
}

//------------------------------------------------------------------------------

void TCadEntity::SetParamInterpolationMode( int mode )
{
	if ( mode == ParamInterpolationMode ) return;
	ParamInterpolationMode = mode;
	SetAllDirty( true );
}

//------------------------------------------------------------------------------

void TCadEntity::SetParamOffset( double d )
{
	if ( fabs( ParamOffset - d ) < RES_COMP ) return;

	ParamOffset = d;
	SetAllDirty( true, false );
}

//------------------------------------------------------------------------------

void TCadEntity::SetOGLParam_1_Tol( double tol )
{
	double d;

	d = 1.0;
	while ( d < ( tol - RES_PARAM ) )
		d *= 10.0;
	OGLParam_1_Tol = d;
	SetAllDirty( true, false );
}

//------------------------------------------------------------------------------

void TCadEntity::SetParamEntity( TCadSurface *_paramsurf, int mode, double offset )
{
	SetParamSurface( _paramsurf );
	SetDimension( ( _paramsurf ? dim2D : dim3D ) );
	if ( _paramsurf ) {
		SetOGLParam_1_Tol( RES_1_PARAM );
		SetParamInterpolationMode( mode );
		SetParamOffset( offset );
	}
}

//------------------------------------------------------------------------------

T3DPoint TCadEntity::SetParamPoint( TOGLTransf *OGLTransf, T3DPoint auxpt )
{
	T3DPoint pt;

	if ( !IsParamEntity( ) ) return auxpt;

	pt = auxpt;
	if ( ParamInterpolationMode == PIM_GEOM || ParamInterpolationMode == PIM_GEOMPARAM || ParamInterpolationMode == PIM_GEOMPARAMCT ) GetParamSurface( )->GetPoint( OGLTransf, auxpt.x, auxpt.y, pt );
	else if ( ParamInterpolationMode == PIM_DEVELOP )
		GetParamSurface( )->PointParamToPointDev( OGLTransf, GetForceDevelopSurfIndex( ), GetDevelopSurfIndex( ), auxpt, pt ); //, devsurfindex //Cambio 02/2019 ForceDevelopSurfIndex por GetForceDevelopSurfIndex( ) pq en depshapes el valor se toma de la funcion de manera distinta a la variable

	return pt;
}

//------------------------------------------------------------------------------

bool TCadEntity::RestoreParamPoint( TOGLTransf *OGLTransf, T3DPoint auxpt, T3DPoint oldpt, T3DPoint &pt )
{
	bool close[ 2 ];
	double gpar[ 2 ], guess[ 2 ], limits[ 4 ];
	TOGLPolygon PolParam;

	pt = auxpt;
	if ( !IsParamEntity( ) ) return true;
	if ( ParamInterpolationMode == PIM_GEOM || ParamInterpolationMode == PIM_GEOMPARAM || ParamInterpolationMode == PIM_GEOMPARAMCT ) {
		GetParamSurface( )->GetLimitsUV( OGLTransf, limits );
		close[ 0 ] = ( GetParamSurface( )->GetUCloseExt( OGLTransf ) == ENT_CLOSE );
		close[ 1 ] = ( GetParamSurface( )->GetVCloseExt( OGLTransf ) == ENT_CLOSE );
		guess[ 0 ] = oldpt.x;
		guess[ 1 ] = oldpt.y;
		if ( !GetParamSurface( )->GetParValuesSimple( OGLTransf, limits, close, auxpt, guess, gpar ) )
			if ( !GetParamSurface( )->GetParValues( OGLTransf, pt, gpar[ 0 ], gpar[ 1 ], 10.0 ) ) return false;
		pt = T3DPoint( gpar[ 0 ], gpar[ 1 ], 0.0 );
	} else if ( ParamInterpolationMode == PIM_DEVELOP ) {
		GetParamSurface( )->PointDevToPointParam( OGLTransf, GetForceDevelopSurfIndex( ), GetDevelopSurfIndex( ), auxpt, &PolParam, true ); // Cambio 02/2019 ForceDevelopSurfIndex por GetForceDevelopSurfIndex( ) pq en depshapes el valor se toma de la funcion de manera distinta a la variable
		if ( !PolParam.Count( ) || PolParam.GetItem( 0 )->n.v[ 1 ] > RES_GEOM ) return false;
		pt = PolParam.GetItem( 0 )->uv.Get3DPoint( );
	}
	return true;
}

//------------------------------------------------------------------------------

void TCadEntity::GetLimitsUV( TOGLTransf *OGLTransf, double *limits )
{
	bool res;
	//   int oldmode;
	T3DRect r;

	limits[ 0 ] = limits[ 1 ] = limits[ 2 ] = limits[ 3 ] = 0.0;
	if ( !IsParamEntity( ) ) return;

	r = T3DRect( 0, 0, 0, 0, 0, 0 );

	//	oldmode = OGLTransf->SetForceMode( VIEW_PARAM2D );
	//	res = CalcBoundRect( OGLTransf, r, true );
	//	OGLTransf->SetForceMode( oldmode );
	res = CalcBoundRectParam( OGLTransf, r, true );

	if ( !res ) return;

	limits[ 0 ] = r.left;
	limits[ 1 ] = r.top;
	limits[ 2 ] = r.right;
	limits[ 3 ] = r.bottom;
}

//------------------------------------------------------------------------------

// 01/2023 Hemos detectado un problema con LimitsUV fuera de 0..MAX_PARAM:
// Al hacer while ( pt1.y > MAX_PARAM ) pt1.y -= MAX_PARAM;, puntos que tenian que estar fuera de ese rango (mayores de MAXPARAM ) los metía en rango, por lo que salia mal la curva
// De hecho solo se trataba el caso > MAX_PARAM y no el de < 0. Como la funcion se utiliza en mucho sitios, solo vamos a controlar el caso detectado, de tal modo que si el limite inferior es menor que el mayor (no están invertidos), si el
// punto resultante cae dentro del rango, no lo cambiamos
// Como puede haber problemas por hbaer hecho por ejemplo una imagen del deformador de relieve con el anterior modo y ahora salga distinto para el aplanado, pasamos
// una entidad origen para determina la versión de esta funcion:
// version = 0: como antes, siempre se trata de hacer while ( pt1.y > MAX_PARAM ) pt1.y -= MAX_PARAM
// version = 1: si el valor está entre limites no se hace

TCadPolyline *TCadEntity::GetCurveUV( TOGLTransf *OGLTransf, double *LimitsUV, bool inflate, TCadEntity *orgent )
{
	int i, version;
	double res, limits[ 4 ], maxrange, f;
	TPoint steps;
	T3DPoint pt1;
	TCadPolyline *curve;

	version = 1;
	if ( ToSurface( orgent ) && orgent->GetVersion( ) <= SURFACE_VERSION_3 ) version = 0;

	if ( LimitsUV )
		for ( i = 0; i < 4; i++ )
			limits[ i ] = LimitsUV[ i ];
	else
		GetLimitsUV( OGLTransf, limits );

	curve = new TCadPolyline( DEFAULT_PARAM_TYPE, DEFAULT_DEGREE, 5 );
	curve->SetDimension( dim2D );

	if ( inflate ) {
		res = 10.0 / OGLParam_1_Tol;
		limits[ 0 ] -= res;
		limits[ 1 ] -= res;
		limits[ 2 ] += res;
		limits[ 3 ] += res;
	}

	maxrange = MAX_PARAM / 3.0 - 1.0;
	steps.x = int( fabs( limits[ 2 ] - limits[ 0 ] ) / maxrange );
	if ( steps.x < 3 ) steps.x = 3;
	steps.y = int( fabs( limits[ 3 ] - limits[ 1 ] ) / maxrange );
	if ( steps.y < 3 ) steps.y = 3;

	pt1 = T3DPoint( limits[ 0 ], limits[ 1 ], 0.0 );
	curve->Add( OGLTransf, pt1 );

	for ( i = 1; i < steps.y; i++ ) {
		pt1.x = limits[ 0 ];
		f = 1.0 - double( i ) / double( steps.y );
		if ( limits[ 1 ] <= limits[ 3 ] ) pt1.y = limits[ 1 ] * f + limits[ 3 ] * ( 1.0 - f );
		else {
			pt1.y = limits[ 1 ] + ( MAX_PARAM - limits[ 1 ] + limits[ 3 ] ) * f;
		}

		if ( !( version > 0 && limits[ 1 ] <= pt1.y && pt1.y <= limits[ 3 ] ) ) // ojo al comentario al inicio de la funcion
			while ( pt1.y > MAX_PARAM )
				pt1.y -= MAX_PARAM;
		curve->Add( OGLTransf, pt1 );
	}

	pt1 = T3DPoint( limits[ 0 ], limits[ 3 ], 0.0 );
	curve->Add( OGLTransf, pt1 );

	for ( i = 1; i < steps.x; i++ ) {
		pt1.y = limits[ 3 ];
		f = 1.0 - double( i ) / double( steps.x );
		if ( limits[ 0 ] <= limits[ 2 ] ) pt1.x = limits[ 0 ] * f + limits[ 2 ] * ( 1.0 - f );
		else {
			pt1.x = limits[ 0 ] + ( MAX_PARAM - limits[ 0 ] + limits[ 2 ] ) * f;
		}

		if ( !( version > 0 && limits[ 0 ] <= pt1.x && pt1.x <= limits[ 2 ] ) ) // ojo al comentario al inicio de la funcion
			while ( pt1.x > MAX_PARAM )
				pt1.x -= MAX_PARAM;

		curve->Add( OGLTransf, pt1 );
	}

	pt1 = T3DPoint( limits[ 2 ], limits[ 3 ], 0.0 );
	curve->Add( OGLTransf, pt1 );

	for ( i = steps.y - 1; i > 0; i-- ) {
		pt1.x = limits[ 2 ];
		f = 1.0 - double( i ) / double( steps.y );
		if ( limits[ 1 ] <= limits[ 3 ] ) pt1.y = limits[ 1 ] * f + limits[ 3 ] * ( 1.0 - f );
		else {
			pt1.y = limits[ 1 ] + ( MAX_PARAM - limits[ 1 ] + limits[ 3 ] ) * f;
		}
		if ( !( version > 0 && limits[ 1 ] <= pt1.y && pt1.y <= limits[ 3 ] ) ) // ojo al comentario al inicio de la funcion
			while ( pt1.y > MAX_PARAM )
				pt1.y -= MAX_PARAM;
		curve->Add( OGLTransf, pt1 );
	}

	pt1 = T3DPoint( limits[ 2 ], limits[ 1 ], 0.0 );
	curve->Add( OGLTransf, pt1 );

	for ( i = steps.x - 1; i > 0; i-- ) {
		pt1.y = limits[ 1 ];
		f = 1.0 - double( i ) / double( steps.x );
		if ( limits[ 0 ] <= limits[ 2 ] ) pt1.x = limits[ 0 ] * f + limits[ 2 ] * ( 1.0 - f );
		else {
			pt1.x = limits[ 0 ] + ( MAX_PARAM - limits[ 0 ] + limits[ 2 ] ) * f;
		}
		if ( !( version > 0 && limits[ 0 ] <= pt1.x && pt1.x <= limits[ 2 ] ) ) // ojo al comentario al inicio de la funcion
			while ( pt1.x > MAX_PARAM )
				pt1.x -= MAX_PARAM;
		curve->Add( OGLTransf, pt1 );
	}

	pt1 = T3DPoint( limits[ 0 ], limits[ 1 ], 0.0 );
	curve->Add( OGLTransf, pt1 );

	return curve;
}

//------------------------------------------------------------------------------

void TCadEntity::GetExtremeCurves( TOGLTransf *OGLTransf, TCadGroup *group, TCadSurface *_surf, double *LimitsUV, bool *_close, bool inflate, double res )
{
	bool close[ 2 ], degen[ 4 ];
	int i;
	double resparam, limits[ 4 ], maxrange, f;
	TPoint steps;
	T3DPoint pt1;
	TCadPolyline *pol;
	TCadEntity *ent;
	TCadSurface *surf;
	TOGLPolygonList *OGLList;

	if ( !OGLTransf || !group ) return;

	if ( LimitsUV )
		for ( i = 0; i < 4; i++ )
			limits[ i ] = LimitsUV[ i ];
	else
		GetLimitsUV( OGLTransf, limits );

	if ( _close ) {
		close[ 0 ] = _close[ 0 ];
		close[ 1 ] = _close[ 1 ];
	} else {
		close[ 0 ] = close[ 1 ] = false;
	}
	if ( close[ 0 ] && close[ 1 ] ) return;

	if ( _surf ) surf = _surf;
	else
		surf = ParamSurface;
	if ( !surf ) return;

	surf->IsDegenerated( OGLTransf, degen );

	if ( inflate ) {
		resparam = 10.0 / OGLParam_1_Tol;
		limits[ 0 ] -= resparam;
		limits[ 1 ] -= resparam;
		limits[ 2 ] += resparam;
		limits[ 3 ] += resparam;
	}

	maxrange = MAX_PARAM / 3.0 - 1.0;
	steps.x = int( fabs( limits[ 2 ] - limits[ 0 ] ) / maxrange );
	if ( steps.x < 3 ) steps.x = 3;
	steps.y = int( fabs( limits[ 3 ] - limits[ 1 ] ) / maxrange );
	if ( steps.y < 3 ) steps.y = 3;

	if ( !degen[ 0 ] && !close[ 0 ] ) {
		// curva limits[ 0 ]
		pol = new TCadPolyline( DEFAULT_PARAM_TYPE, DEFAULT_DEGREE, 5 );
		pol->SetParamEntity( surf, PIM_PARAM );
		pt1 = T3DPoint( limits[ 0 ], limits[ 1 ], 0.0 );
		pol->Add( OGLTransf, pt1 );
		for ( i = 1; i < steps.y; i++ ) {
			pt1.x = limits[ 0 ];
			f = 1.0 - double( i ) / double( steps.y );
			if ( limits[ 1 ] <= limits[ 3 ] ) pt1.y = limits[ 1 ] * f + limits[ 3 ] * ( 1.0 - f );
			else {
				pt1.y = limits[ 1 ] + ( MAX_PARAM - limits[ 1 ] + limits[ 3 ] ) * f;
			}
			while ( pt1.y > MAX_PARAM )
				pt1.y -= MAX_PARAM;
			pol->Add( OGLTransf, pt1 );
		}
		pt1 = T3DPoint( limits[ 0 ], limits[ 3 ], 0.0 );
		pol->Add( OGLTransf, pt1 );
		if ( res >= RES_COMP ) {
			ent = pol->TCadShape::GetIBSpline( OGLTransf, false );
			delete pol;
			if ( ent ) {
				ent->SetParamEntity( surf, PIM_GEOMPARAM );
				ToIBSpline( ent )->FilterShape( OGLTransf, res );
				ToIBSpline( ent )->CornerDetection( OGLTransf );
			}
		} else
			ent = pol;
		OGLList = ent->GetOGLGeom3D( OGLTransf );
		if ( OGLList && OGLList->Perimeter( ) > RES_GEOM ) group->Add( ent );
		else
			delete ent;
	}

	if ( !degen[ 2 ] && !close[ 0 ] ) {
		// curva limits[ 2 ]
		pol = new TCadPolyline( DEFAULT_PARAM_TYPE, DEFAULT_DEGREE, 5 );
		pol->SetParamEntity( surf, PIM_PARAM );
		pt1 = T3DPoint( limits[ 2 ], limits[ 3 ], 0.0 );
		pol->Add( OGLTransf, pt1 );
		for ( i = steps.y - 1; i > 0; i-- ) {
			pt1.x = limits[ 2 ];
			f = 1.0 - double( i ) / double( steps.y );
			if ( limits[ 1 ] <= limits[ 3 ] ) pt1.y = limits[ 1 ] * f + limits[ 3 ] * ( 1.0 - f );
			else {
				pt1.y = limits[ 1 ] + ( MAX_PARAM - limits[ 1 ] + limits[ 3 ] ) * f;
			}
			while ( pt1.y > MAX_PARAM )
				pt1.y -= MAX_PARAM;
			pol->Add( OGLTransf, pt1 );
		}
		pt1 = T3DPoint( limits[ 2 ], limits[ 1 ], 0.0 );
		pol->Add( OGLTransf, pt1 );
		if ( res >= RES_COMP ) {
			ent = pol->TCadShape::GetIBSpline( OGLTransf, false );
			delete pol;
			if ( ent ) {
				ent->SetParamEntity( surf, PIM_GEOMPARAM );
				ToIBSpline( ent )->FilterShape( OGLTransf, res );
				ToIBSpline( ent )->CornerDetection( OGLTransf );
			}
		} else
			ent = pol;
		OGLList = ent->GetOGLGeom3D( OGLTransf );
		if ( OGLList && OGLList->Perimeter( ) > RES_GEOM ) group->Add( ent );
		else
			delete ent;
	}

	if ( !degen[ 1 ] && !close[ 1 ] ) {
		// curva limits[ 1 ]
		pol = new TCadPolyline( DEFAULT_PARAM_TYPE, DEFAULT_DEGREE, 5 );
		pol->SetParamEntity( surf, PIM_PARAM );
		pt1 = T3DPoint( limits[ 2 ], limits[ 1 ], 0.0 );
		pol->Add( OGLTransf, pt1 );
		for ( i = steps.x - 1; i > 0; i-- ) {
			pt1.y = limits[ 1 ];
			f = 1.0 - double( i ) / double( steps.x );
			if ( limits[ 0 ] <= limits[ 2 ] ) pt1.x = limits[ 0 ] * f + limits[ 2 ] * ( 1.0 - f );
			else {
				pt1.x = limits[ 0 ] + ( MAX_PARAM - limits[ 0 ] + limits[ 2 ] ) * f;
			}
			while ( pt1.x > MAX_PARAM )
				pt1.x -= MAX_PARAM;
			pol->Add( OGLTransf, pt1 );
		}

		pt1 = T3DPoint( limits[ 0 ], limits[ 1 ], 0.0 );
		pol->Add( OGLTransf, pt1 );
		if ( res >= RES_COMP ) {
			ent = pol->TCadShape::GetIBSpline( OGLTransf, false );
			delete pol;
			if ( ent ) {
				ent->SetParamEntity( surf, PIM_GEOMPARAM );
				ToIBSpline( ent )->FilterShape( OGLTransf, res );
				ToIBSpline( ent )->CornerDetection( OGLTransf );
			}
		} else
			ent = pol;
		OGLList = ent->GetOGLGeom3D( OGLTransf );
		if ( OGLList && OGLList->Perimeter( ) > RES_GEOM ) group->Add( ent );
		else
			delete ent;
	}

	if ( !degen[ 3 ] && !close[ 1 ] ) {
		// curva limits[ 3 ]
		pol = new TCadPolyline( DEFAULT_PARAM_TYPE, DEFAULT_DEGREE, 5 );
		pol->SetParamEntity( surf, PIM_PARAM );
		pt1 = T3DPoint( limits[ 0 ], limits[ 3 ], 0.0 );
		pol->Add( OGLTransf, pt1 );
		for ( i = 1; i < steps.x; i++ ) {
			pt1.y = limits[ 3 ];
			f = 1.0 - double( i ) / double( steps.x );
			if ( limits[ 0 ] <= limits[ 2 ] ) pt1.x = limits[ 0 ] * f + limits[ 2 ] * ( 1.0 - f );
			else {
				pt1.x = limits[ 0 ] + ( MAX_PARAM - limits[ 0 ] + limits[ 2 ] ) * f;
			}
			while ( pt1.x > MAX_PARAM )
				pt1.x -= MAX_PARAM;
			pol->Add( OGLTransf, pt1 );
		}
		pt1 = T3DPoint( limits[ 2 ], limits[ 3 ], 0.0 );
		pol->Add( OGLTransf, pt1 );
		if ( res >= RES_COMP ) {
			ent = pol->TCadShape::GetIBSpline( OGLTransf, false );
			delete pol;
			if ( ent ) {
				ent->SetParamEntity( surf, PIM_GEOMPARAM );
				ToIBSpline( ent )->FilterShape( OGLTransf, res );
				ToIBSpline( ent )->CornerDetection( OGLTransf );
			}
		} else
			ent = pol;
		OGLList = ent->GetOGLGeom3D( OGLTransf );
		if ( OGLList && OGLList->Perimeter( ) > RES_GEOM ) group->Add( ent );
		else
			delete ent;
	}
}

//------------------------------------------------------------------------------

bool TCadEntity::CalcDevelopSurfIndex( TOGLTransf *OGLTransf )
{
	bool oldforce, found, res, outrange;
	int i, j, index; //, oldmode;
	TLPoint pt[ 4 ];
	TLRect rect;
	T3DRect r3d;
	double limitsUV[ 4 ], d, maxdif;

	if ( !OGLTransf || !IsParamEntity( ) || !ParamSurface->HasDevelopData( ) ) return false;
	//	if ( !OGLTransf || !IsParamEntity( ) || !ParamSurface->HasDevelopData( ) || !IsDevelopable( ) ) return false;

	oldforce = GetForceDevelopSurfIndex( ); // Cambio 02/2019 ForceDevelopSurfIndex por GetForceDevelopSurfIndex( ) pq en depshapes el valor se toma de la funcion de manera distinta a la variable
	SetForceDevelopSurfIndex( false );
	outrange = ( GetDevelopSurfIndex( ) >= ParamSurface->GetDevelopList( )->CountSurfsInDevelop( ) );

	//	oldmode = OGLTransf->SetForceMode( VIEW_PARAM2D );
	//	res = CalcBoundRect( OGLTransf, r3d, outrange );
	//	OGLTransf->SetForceMode( oldmode );
	res = CalcBoundRectParam( OGLTransf, r3d, outrange );

	SetForceDevelopSurfIndex( oldforce );
	if ( !res ) return false;

	if ( outrange ) {
		while ( r3d.right > ( MAX_PARAM + RES_PARAM ) && r3d.left > ( MAX_PARAM / 2.0 ) ) {
			r3d.left -= MAX_PARAM;
			r3d.right -= MAX_PARAM;
		}
		while ( r3d.bottom > ( MAX_PARAM + RES_PARAM ) && r3d.top > ( MAX_PARAM / 2.0 ) ) {
			r3d.top -= MAX_PARAM;
			r3d.bottom -= MAX_PARAM;
		}
	}

	pt[ 0 ] = TLPoint( r3d.left, r3d.top );
	pt[ 1 ] = TLPoint( r3d.right, r3d.top );
	pt[ 2 ] = TLPoint( r3d.right, r3d.bottom );
	pt[ 3 ] = TLPoint( r3d.left, r3d.bottom );

	if ( GetForceDevelopSurfIndex( ) && GetDevelopSurfIndex( ) < ParamSurface->GetDevelopList( )->CountSurfsInDevelop( ) ) { // Cambio 02/2019 ForceDevelopSurfIndex por GetForceDevelopSurfIndex( ) pq en depshapes el valor se toma de la funcion de manera distinta a la variable
		ParamSurface->GetDevelopLimitsUV( OGLTransf, GetDevelopSurfIndex( ), limitsUV );
		rect = TLRect( limitsUV[ 0 ], limitsUV[ 1 ], limitsUV[ 2 ], limitsUV[ 3 ] ).InflatedBy( RES_PARAM, RES_PARAM );
		for ( j = 0; j < 4; j++ )
			if ( !rect.Contains( pt[ j ] ) ) break;
		if ( j == 4 ) return true;
	}

	for ( i = 0; i < ParamSurface->GetDevelopList( )->CountSurfsInDevelop( ); i++ ) {
		index = i;
		if ( GetDevelopSurfIndex( ) < ParamSurface->GetDevelopList( )->CountSurfsInDevelop( ) ) {
			if ( i == GetDevelopSurfIndex( ) ) index = 0;
			else if ( i == 0 )
				index = GetDevelopSurfIndex( );
		}
		if ( index == GetDevelopSurfIndex( ) ) continue;
		ParamSurface->GetDevelopLimitsUV( OGLTransf, index, limitsUV );
		rect = TLRect( limitsUV[ 0 ], limitsUV[ 1 ], limitsUV[ 2 ], limitsUV[ 3 ] ).InflatedBy( RES_PARAM, RES_PARAM );
		for ( j = 0; j < 4; j++ )
			if ( !rect.Contains( pt[ j ] ) ) break;
		if ( j == 4 ) {
			if ( index != GetDevelopSurfIndex( ) ) SetDevelopSurfIndex( index );
			return true;
		}
	}

	if ( GetDevelopSurfIndex( ) >= ParamSurface->GetDevelopList( )->CountSurfsInDevelop( ) ) {
		maxdif = MAX_PARAM;
		index = 0;
		for ( i = 0; i < ParamSurface->GetDevelopList( )->CountSurfsInDevelop( ); i++ ) {
			ParamSurface->GetDevelopLimitsUV( OGLTransf, i, limitsUV );
			found = false;
			d = 0.0;
			if ( pt[ 0 ].x < limitsUV[ 0 ] && ( !found || d < ( limitsUV[ 0 ] - pt[ 0 ].x ) ) ) {
				d = fabs( limitsUV[ 0 ] - pt[ 0 ].x );
				found = true;
			}
			if ( pt[ 1 ].y < limitsUV[ 1 ] && ( !found || d < ( limitsUV[ 1 ] - pt[ 1 ].y ) ) ) {
				d = fabs( limitsUV[ 1 ] - pt[ 1 ].y );
				found = true;
			}
			if ( pt[ 2 ].x > limitsUV[ 2 ] && ( !found || d < ( pt[ 2 ].x - limitsUV[ 2 ] ) ) ) {
				d = fabs( pt[ 2 ].x - limitsUV[ 2 ] );
				found = true;
			}
			if ( pt[ 3 ].y > limitsUV[ 3 ] && ( !found || d < ( pt[ 3 ].y - limitsUV[ 3 ] ) ) ) {
				d = fabs( pt[ 3 ].y - limitsUV[ 3 ] );
				found = true;
			}
			if ( i == 0 || d < maxdif ) {
				index = i;
				maxdif = d;
			}
		}
		if ( maxdif < ( MAX_PARAM / 200.0 ) ) SetDevelopSurfIndex( index );
		return false; // tal vez podrias ser true, pero realmente no esta estrictamente dentro
	}

	return false;
}

//------------------------------------------------------------------------------

int TCadEntity::GetDevelopSurfIndexByPoint( TOGLTransf *, T3DPoint ) // OGLTransf, pt
{
	return GetDevelopSurfIndex( );
}

//------------------------------------------------------------------------------

void TCadEntity::SetDevelopSurfIndex( int index )
{
	if ( index < 0 || DevelopSurfIndex == index ) return;

	DevelopSurfIndex = index;

	if ( !IsParamEntity( ) || !IsDevelopable( ) || ParamInterpolationMode == PIM_DEVELOP ) SetAllDirty( true );
	else
		SetDevelop2DDirty( true );
}

//------------------------------------------------------------------------------

void TCadEntity::SetForceDevelopSurfIndex( bool value )
{
	if ( ForceDevelopSurfIndex == value ) return;

	ForceDevelopSurfIndex = value;

	if ( !IsParamEntity( ) || !IsDevelopable( ) || ParamInterpolationMode == PIM_DEVELOP ) SetAllDirty( true );
	else
		SetDevelop2DDirty( true );
}

//------------------------------------------------------------------------------

TCadSurface *TCadEntity::GetTransfDevelopSurfIndexSurface( TOGLTransf *OGLTransf, int devindex )
{
	TCadGroup *Group;

	if ( !IsParamEntity( ) ) return 0;

	Group = GetParamSurface( )->GetTransfDevelopSurfaces( OGLTransf, devindex );
	if ( !Group || !Group->Count( ) ) return 0;

	if ( !GetForceDevelopSurfIndex( ) || GetDevelopSurfIndex( ) >= Group->Count( ) ) // Cambio 02/2019 ForceDevelopSurfIndex por GetForceDevelopSurfIndex( ) pq en depshapes el valor se toma de la funcion de manera distinta a la variable
		return 0;

	return ToSurface( Group->GetShape( GetDevelopSurfIndex( ) ) );
}

//------------------------------------------------------------------------------

T3DPoint TCadEntity::GetPointByView( TOGLTransf *OGLTransf, int view, T3DPoint auxpt, int *devsurfindex )
{
	T3DPoint pt;

	if ( !IsParamEntity( ) ) return auxpt;

	pt = auxpt;
	if ( view == VIEW_GEOM3D ) GetParamSurface( )->GetPoint( OGLTransf, auxpt.x, auxpt.y, pt );
	else if ( view == VIEW_DEVELOP2D )
		GetParamSurface( )->PointParamToPointDev( OGLTransf, GetForceDevelopSurfIndex( ), GetDevelopSurfIndex( ), auxpt, pt, devsurfindex ); // Cambio 02/2019 ForceDevelopSurfIndex por GetForceDevelopSurfIndex( ) pq en depshapes el valor se toma de la funcion de manera distinta a la variable

	return pt;
}

//------------------------------------------------------------------------------

bool TCadEntity::RestorePointByView( TOGLTransf *OGLTransf, int view, T3DPoint auxpt, T3DPoint oldpt, T3DPoint &pt )
{
	bool close[ 2 ];
	double gpar[ 2 ], guess[ 2 ], limits[ 4 ];
	TOGLPolygon PolParam;

	pt = auxpt;
	if ( !IsParamEntity( ) ) return true;
	if ( view == VIEW_GEOM3D ) {
		GetParamSurface( )->GetLimitsUV( OGLTransf, limits );
		close[ 0 ] = ( GetParamSurface( )->GetUCloseExt( OGLTransf ) == ENT_CLOSE );
		close[ 1 ] = ( GetParamSurface( )->GetVCloseExt( OGLTransf ) == ENT_CLOSE );
		guess[ 0 ] = oldpt.x;
		guess[ 1 ] = oldpt.y;
		if ( !GetParamSurface( )->GetParValuesSimple( OGLTransf, limits, close, auxpt, guess, gpar ) )
			if ( !GetParamSurface( )->GetParValues( OGLTransf, pt, gpar[ 0 ], gpar[ 1 ], 10.0 ) ) return false;
		pt = T3DPoint( gpar[ 0 ], gpar[ 1 ], 0.0 );
	} else if ( view == VIEW_DEVELOP2D ) {
		GetParamSurface( )->PointDevToPointParam( OGLTransf, GetForceDevelopSurfIndex( ), GetDevelopSurfIndex( ), auxpt, &PolParam, true ); // Cambio 02/2019 ForceDevelopSurfIndex por GetForceDevelopSurfIndex( ) pq en depshapes el valor se toma de la funcion de manera distinta a la variable
		if ( !PolParam.Count( ) || PolParam.GetItem( 0 )->n.v[ 1 ] > RES_GEOM ) return false;
		pt = PolParam.GetItem( 0 )->uv.Get3DPoint( );
	}
	return true;
}

//------------------------------------------------------------------------------

void TCadEntity::CleanGroups( )
{
	int i;

	if ( RelatedEntities )
		for ( i = RelatedEntities->Count( ) - 1; i >= 0; i-- )
			if ( !RelatedEntities->GetShape( i ) ) RelatedEntities->Detach( i, NoDelete );

	if ( DepShapes )
		for ( i = DepShapes->Count( ) - 1; i >= 0; i-- )
			if ( !DepShapes->GetShape( i ) ) DepShapes->Detach( i, NoDelete );

	if ( DepSurfaces )
		for ( i = DepSurfaces->Count( ) - 1; i >= 0; i-- )
			if ( !DepSurfaces->GetShape( i ) ) DepSurfaces->Detach( i, NoDelete );

	if ( DepMeshes )
		for ( i = DepMeshes->Count( ) - 1; i >= 0; i-- )
			if ( !DepMeshes->GetShape( i ) ) DepMeshes->Detach( i, NoDelete );
}

//------------------------------------------------------------------------------

void TCadEntity::GetDownRelatedEntities( TOGLTransf *OGLTransf, TCadGroup *Group, HLAYER *excludelayer, bool force )
{
	int i, j, k, ind, index[ 2 ], c;
	TCadEntity *ent, *baseent;
	TCadDepShape *depshape, *deppoly, *depmarker;
	TCadDepMesh *depmesh;
	TEntityRelation *entrel;
	TPointMarker *pm;
	TLineMarker *lm;

	if ( excludelayer && *excludelayer == Layer ) return;
	if ( Group->IsEntityIncluded( this, false ) ) return;

	Group->Add( this, false ); //	if ( !Group->IsEntityIncluded( this, false ) ) Group->Add( this, false );

	if ( RelatedEntities )
		for ( i = 0; i < RelatedEntities->Count( ); i++ ) {
			ent = RelatedEntities->GetShape( i );
			if ( !ent ) continue;
			for ( j = 0; j < ent->GetEntityRelationList( )->Count( ); j++ ) {
				entrel = ent->GetEntityRelationList( )->GetItem( j );
				if ( entrel->Type != ER_TYPE_DEPENDENT_DEVELOP )
					if ( entrel->BaseEntity == this && !Group->IsEntityIncluded( ent, false ) ) ent->GetDownRelatedEntities( OGLTransf, Group, excludelayer, force );
			}
		}

	// caso particular para los tipos de relacion de entidad ER_TYPE_DEPENDENT y ER_TYPE_DEPENDENT_HIDDEN. Relacion de existencia bidireccional
	for ( i = 0; i < EntityRelationList.Count( ); i++ ) {
		entrel = EntityRelationList.GetItem( i );
		if ( force || entrel->Type == ER_TYPE_DEPENDENT || entrel->Type == ER_TYPE_DEPENDENT_HIDDEN )
			if ( entrel->BaseEntity && !Group->IsEntityIncluded( entrel->BaseEntity, false ) ) entrel->BaseEntity->GetDownRelatedEntities( OGLTransf, Group, excludelayer, force );
	}

	if ( DepShapes )
		for ( i = 0; i < DepShapes->Count( ); i++ ) {
			depshape = ToDepShape( DepShapes->GetShape( i ) );
			if ( !depshape ) continue;
			if ( depshape->IsRotationDepShape( ) && depshape->GetBaseEntity( ) != this && depshape->GetRotShape1( ) != this && ( !depshape->GetRotAxis( ) || depshape->GetRotAxis( ) != this ) ) continue;
			if ( depshape->IsCopyDepShape( ) && depshape->GetBaseEntity( ) != this ) continue;
			if ( !Group->IsEntityIncluded( depshape, false ) ) depshape->GetDownRelatedEntities( OGLTransf, Group, excludelayer, force );
		}

	if ( DepSurfaces )
		for ( i = 0; i < DepSurfaces->Count( ); i++ )
			if ( !Group->IsEntityIncluded( DepSurfaces->GetShape( i ), false ) ) DepSurfaces->GetShape( i )->GetDownRelatedEntities( OGLTransf, Group, excludelayer, force );

	if ( DepMeshes )
		for ( i = 0; i < DepMeshes->Count( ); i++ ) {
			depmesh = ToDepMesh( DepMeshes->GetShape( i ) );
			if ( !depmesh ) continue;
			if ( depmesh->IsBoxPlaneDepMesh( ) ) {
				for ( j = 0; j < depmesh->GetBaseEntities( )->Count( ); j++ ) {
					baseent = depmesh->GetBaseEntities( )->GetShape( j );
					for ( k = 0; k < Group->Count( ); k++ )
						if ( baseent == Group->GetShape( k ) ) break;
					if ( k == Group->Count( ) ) // hay una base que no esta en el grupo, no hay que borrarla todavia
						break;
				}
				if ( force || j == depmesh->GetBaseEntities( )->Count( ) ) // todas las bases van a eliminarse, hay que quitar la depmesh tambien
					if ( !Group->IsEntityIncluded( depmesh, false ) ) depmesh->GetDownRelatedEntities( OGLTransf, Group, excludelayer, force );
			} else if ( depmesh->IsSweepOneDepMesh( ) || depmesh->IsSweepTwoDepMesh( ) ) {
				ind = depmesh->GetBaseEntities( )->GetEntityIndex( this );
				index[ 0 ] = index[ 1 ] = -1;
				depmarker = ToDepShape( depmesh->GetBaseEntities( )->GetShape( 0 ) );
				if ( depmarker ) {
					deppoly = ToDepShape( depmarker->GetBaseEntity( ) );
					if ( deppoly ) {
						lm = deppoly->GetMarkerList( )->GetLineMarker( 0 );
						if ( lm ) {
							c = 0;
							for ( j = 0; j < deppoly->PointMarkersCount( ); j++ ) {
								if ( j == lm->GetStartIndex( ) ) index[ 0 ] = c;
								else if ( j == lm->GetEndIndex( ) )
									index[ 1 ] = c;
								pm = deppoly->GetMarkerList( )->GetPointMarker( j );
								if ( pm->GetType( ) == PM_TYPE_SWEEP ) c++;
							}
							if ( index[ 0 ] >= 0 ) index[ 0 ] += ( depmesh->IsSweepOneDepMesh( ) ? 1 : 2 );
							if ( index[ 1 ] >= 0 ) index[ 1 ] += ( depmesh->IsSweepOneDepMesh( ) ? 1 : 2 );
						}
					}
				}
				if ( force || ind == 0 || ( depmesh->IsSweepTwoDepMesh( ) && ind == 1 ) || ind == index[ 0 ] || ind == index[ 1 ] )
					if ( !Group->IsEntityIncluded( depmesh, false ) ) depmesh->GetDownRelatedEntities( OGLTransf, Group, excludelayer, force );
			} else if ( depmesh->IsTrimOffsetSideDepMesh( ) ) {
				ind = depmesh->GetBaseEntities( )->GetEntityIndex( this );
				if ( ind < 2 )
					if ( !Group->IsEntityIncluded( depmesh, false ) ) depmesh->GetDownRelatedEntities( OGLTransf, Group, excludelayer, force );
			} else {
				if ( !Group->IsEntityIncluded( depmesh, false ) ) depmesh->GetDownRelatedEntities( OGLTransf, Group, excludelayer, force );
			}
		}
}

//------------------------------------------------------------------------------

bool TCadEntity::HasUpRelatedEntities( bool rels, bool, bool excludeparamsurf )
{
	int i;

	if ( ParamSurface && !excludeparamsurf ) return true;

	if ( rels )
		for ( i = 0; i < EntityRelationList.Count( ); i++ )
			if ( EntityRelationList.GetItem( i )->BaseEntity ) return true;

	return false;
}

//------------------------------------------------------------------------------

void TCadEntity::GetUpRelatedEntities( TCadGroup *Group, bool rels, bool pointRels )
{
	int i;
	TCadEntity *entity;

	if ( IsParamEntity( ) && !Group->IsEntityIncluded( ParamSurface, false ) ) {
		Group->Add( ParamSurface, false );
		ParamSurface->GetUpRelatedEntities( Group, rels, pointRels );
	}

	if ( rels ) {
		for ( i = 0; i < EntityRelationList.Count( ); i++ ) {
			entity = EntityRelationList.GetItem( i )->BaseEntity;
			if ( entity && !Group->IsEntityIncluded( entity, false ) ) {
				Group->Add( entity, false );
				entity->GetUpRelatedEntities( Group, rels, pointRels );
			}
		}
	}
}

//------------------------------------------------------------------------------

void TCadEntity::DetachUpRelations( TCadGroup *Group, TPointRelationList *, TEntityRelationList *EntityRelations, bool updatedirty ) // PointRelations
{
	int i, j;
	UnicodeString str;
	TEntityRelation *entrel, er;
	TCadEntity *ent, *baseent;
	TCadGroup *grp;
	TCadDepShape *depshape;
	TCadDepSurface *depsurface;
	TCadDepMesh *depmesh;

	if ( IsParamEntity( ) ) {
		if ( GetParamSurface( )->GetParamEntities( )->IsEntityIncluded( this, false ) ) {
			if ( Group ) str.sprintf( L"%d", GetParamSurface( )->GetParamEntities( )->GetEntityIndex( this, false ) );
			GetParamSurface( )->GetParamEntities( )->Detach( this, NoDelete );
			if ( Group ) {
				grp = new TCadGroup( GetParamSurface( ), GetParamSurface( )->GetParamEntities( ), this );
				grp->SetTempName( str );
				grp->SetExternalDirty( false ); // indica si hay que poner dirty la entidad al deshacer/rehacer
				Group->Add( grp, false );
			}
		}
	}

	// caso particular para los tipos de relacion de entidad ER_TYPE_DEPENDENT_DEVELOP. Relacion bidireccional
	if ( RelatedEntities )
		for ( i = 0; i < RelatedEntities->Count( ); i++ ) {
			ent = RelatedEntities->GetShape( i );
			if ( !ent ) continue;
			for ( j = ent->GetEntityRelationList( )->Count( ) - 1; j >= 0; j-- ) {
				entrel = ent->GetEntityRelationList( )->GetItem( j );
				if ( entrel->Type == ER_TYPE_DEPENDENT_DEVELOP && entrel->BaseEntity == this ) {
					if ( EntityRelations ) {
						er.Set( entrel );
						er.OwnerIndex = j;
						er.OwnerEntity = ent;
						EntityRelations->AddItem( &er );
					}
					ent->GetEntityRelationList( )->DelItem( j );
				}
			}
		}

	for ( i = 0; i < EntityRelationList.Count( ); i++ ) {
		baseent = EntityRelationList.GetItem( i )->BaseEntity;
		if ( baseent && baseent->GetRelatedEntities( ) && baseent->GetRelatedEntities( )->IsEntityIncluded( this, false ) ) {
			if ( Group ) str.sprintf( L"%d", baseent->GetRelatedEntities( )->GetEntityIndex( this, false ) );
			baseent->GetRelatedEntities( )->Detach( this, NoDelete );
			if ( Group ) {
				grp = new TCadGroup( baseent, baseent->GetRelatedEntities( ), this );
				grp->SetTempName( str );
				grp->SetExternalDirty( EntityRelationList.GetItem( i )->Type == ER_TYPE_DEPENDENT_DEVELOP ); // indica si hay que poner dirty la entidad al deshacer/rehacer
				Group->Add( grp, false );
			}
		}
	}

	if ( DepShapes )
		for ( i = 0; i < DepShapes->Count( ); i++ ) {
			depshape = ToDepShape( DepShapes->GetShape( i ) );
			if ( depshape && depshape->GetBaseEntities( )->Count( ) && depshape->GetBaseEntities( )->IsEntityIncluded( this, false ) ) {
				if ( Group ) str.sprintf( L"%d", depshape->GetBaseEntities( )->GetEntityIndex( this, false ) );
				depshape->GetBaseEntities( )->Detach( this, NoDelete );
				if ( Group ) {
					grp = new TCadGroup( depshape, depshape->GetBaseEntities( ), this );
					grp->SetTempName( str );
					grp->SetExternalDirty( true ); // indica si hay que poner dirty la entidad al deshacer/rehacer
					Group->Add( grp, false );
				}
				if ( updatedirty ) depshape->SetAllDirty( true );
			}
		}

	if ( DepSurfaces )
		for ( i = 0; i < DepSurfaces->Count( ); i++ ) {
			depsurface = ToDepSurface( DepSurfaces->GetShape( i ) );
			if ( depsurface && depsurface->GetBaseEntities( )->Count( ) && depsurface->GetBaseEntities( )->IsEntityIncluded( this, false ) ) {
				if ( Group ) str.sprintf( L"%d", depsurface->GetBaseEntities( )->GetEntityIndex( this, false ) );
				depsurface->GetBaseEntities( )->Detach( this, NoDelete );
				if ( Group ) {
					grp = new TCadGroup( depsurface, depsurface->GetBaseEntities( ), this );
					grp->SetTempName( str );
					grp->SetExternalDirty( true ); // indica si hay que poner dirty la entidad al deshacer/rehacer
					Group->Add( grp, false );
				}
				if ( updatedirty ) depsurface->SetAllDirty( true );
			}
		}

	if ( DepMeshes )
		for ( i = 0; i < DepMeshes->Count( ); i++ ) {
			depmesh = ToDepMesh( DepMeshes->GetShape( i ) );
			if ( depmesh && depmesh->GetBaseEntities( )->Count( ) && depmesh->GetBaseEntities( )->IsEntityIncluded( this, false ) ) {
				if ( Group ) str.sprintf( L"%d", depmesh->GetBaseEntities( )->GetEntityIndex( this, false ) );
				depmesh->GetBaseEntities( )->Detach( this, NoDelete );
				if ( Group ) {
					grp = new TCadGroup( depmesh, depmesh->GetBaseEntities( ), this );
					grp->SetTempName( str );
					grp->SetExternalDirty( true ); // indica si hay que poner dirty la entidad al deshacer/rehacer
					Group->Add( grp, false );
				}
				if ( updatedirty ) depmesh->SetAllDirty( true );
			}
		}
}

//------------------------------------------------------------------------------

void TCadEntity::ChangeRelatedEntity( TCadEntity *orgent, TCadEntity *dstent, TCadGroup *group, bool setdirty )
{
	int i, index;

	if ( !orgent || !dstent ) return;

	if ( RelatedEntities ) {
		index = RelatedEntities->GetEntityIndex( orgent );
		if ( index >= 0 ) {
			setdirty = true;
			RelatedEntities->SetData( index, dstent );
		}
	}

	for ( i = 0; i < EntityRelationList.Count( ); i++ )
		if ( EntityRelationList.GetItem( i )->BaseEntity == orgent ) {
			setdirty = true;
			EntityRelationList.GetItem( i )->BaseEntity = dstent;
			if ( EntityRelationList.GetItem( i )->Type == ER_TYPE_DEPENDENT_FRAME && ToRect( this ) ) ToRect( this )->GetOGLImageTextureList( )->DelItem( 0 );
		}

	if ( ParamSurface == orgent ) {
		setdirty = true;
		ParamSurface = ToSurface( dstent );
	}

	if ( DepShapes ) {
		index = DepShapes->GetEntityIndex( orgent );
		if ( index >= 0 ) {
			setdirty = true;
			DepShapes->SetData( index, dstent );
		}
	}

	if ( DepSurfaces ) {
		index = DepSurfaces->GetEntityIndex( orgent );
		if ( index >= 0 ) {
			setdirty = true;
			DepSurfaces->SetData( index, dstent );
		}
	}

	if ( DepMeshes ) {
		index = DepMeshes->GetEntityIndex( orgent );
		if ( index >= 0 ) {
			setdirty = true;
			DepMeshes->SetData( index, dstent );
		}
	}

	// if ( setdirty ) SetAllDirty( true );

	if ( setdirty ) {
		if ( group ) group->Add( this );
		else
			SetAllDirty( true );
	}
}

//------------------------------------------------------------------------------
// Suponemos que ent no tiene relaciones previas

void TCadEntity::ChangeOwnRelatedEntity( TCadEntity *ent )
{
	bool setdirty, found;
	int i, j, index;
	TCadEntity *aux;
	TCadDepShape *depshape;
	TCadDepSurface *depsurface;
	TCadDepMesh *depmesh;

	if ( !ent ) return;

	// ENTITY TO ENTITY
	if ( ent->GetRelatedEntities( ) ) ent->GetRelatedEntities( )->Clear( );
	else
		ent->CreateRelatedEntities( );
	if ( RelatedEntities ) {
		for ( i = 0; i < RelatedEntities->Count( ); i++ ) {
			aux = RelatedEntities->GetShape( i );
			if ( !aux ) continue;
			for ( j = 0; j < aux->GetEntityRelationList( )->Count( ); j++ )
				if ( aux->GetEntityRelationList( )->GetItem( j )->BaseEntity == this ) {
					aux->GetEntityRelationList( )->GetItem( j )->BaseEntity = ent;
					aux->SetAllDirty( true );
				}
		}
		ent->GetRelatedEntities( )->SetEntities( RelatedEntities );
		RelatedEntities->Clear( );
	}

	for ( i = 0; i < EntityRelationList.Count( ); i++ ) {
		aux = EntityRelationList.GetItem( i )->BaseEntity;
		if ( !aux || !aux->GetRelatedEntities( ) ) continue;
		index = aux->GetRelatedEntities( )->GetEntityIndex( this );
		if ( index >= 0 ) {
			aux->GetRelatedEntities( )->SetData( index, ent );
			if ( EntityRelationList.GetItem( i )->Type == ER_TYPE_DEPENDENT_FRAME ) {
				if ( ToRect( this ) ) ToRect( this )->GetOGLImageTextureList( )->DelItem( 0 );
				if ( ToRect( ent ) ) ToRect( ent )->GetOGLImageTextureList( )->DelItem( 0 );
			}
		}
	}
	ent->GetEntityRelationList( )->Set( &EntityRelationList );
	EntityRelationList.Clear( );

	// PARAMENTITIES
	ent->SetParamSurface( ParamSurface );
	if ( IsParamEntity( ) ) {
		index = ParamSurface->GetParamEntities( )->GetEntityIndex( this );
		if ( index >= 0 ) ParamSurface->GetParamEntities( )->SetData( index, ent );
		ParamSurface = 0;
	}

	// DEPSHAPES
	if ( ent->GetDepShapes( ) ) ent->GetDepShapes( )->Clear( );
	else
		ent->CreateDepShapes( );
	if ( DepShapes ) {
		ent->GetDepShapes( )->SetEntities( DepShapes );
		for ( i = 0; i < DepShapes->Count( ); i++ ) {
			depshape = ToDepShape( DepShapes->GetShape( i ) );
			if ( !depshape ) continue;
			index = depshape->GetBaseEntities( )->GetEntityIndex( this );
			found = ( index >= 0 );
			if ( found ) depshape->GetBaseEntities( )->SetData( index, ent );
			if ( depshape->IsPolyDepShape( ) && ( found || depshape->GetPolyData( )->IsEntityIncluded( this ) ) ) {
				depshape->GetPolyData( )->ChangeRelatedEntity( this, ent, setdirty );
				found = true;
			}
			if ( found ) depshape->SetAllDirty( true );
		}
		DepShapes->Clear( );
	}

	// DEPSURFACES
	if ( ent->GetDepSurfaces( ) ) ent->GetDepSurfaces( )->Clear( );
	else
		ent->CreateDepSurfaces( );
	if ( DepSurfaces ) {
		ent->GetDepSurfaces( )->SetEntities( DepSurfaces );
		for ( i = 0; i < DepSurfaces->Count( ); i++ ) {
			depsurface = ToDepSurface( DepSurfaces->GetShape( i ) );
			if ( !depsurface ) continue;
			index = depsurface->GetBaseEntities( )->GetEntityIndex( this );
			if ( index >= 0 ) {
				depsurface->GetBaseEntities( )->SetData( index, ent );
				depsurface->SetAllDirty( true );
			}
		}
		DepSurfaces->Clear( );
	}

	// DEPMESHES
	if ( ent->GetDepMeshes( ) ) ent->GetDepMeshes( )->Clear( );
	else
		ent->CreateDepMeshes( );
	if ( DepMeshes ) {
		ent->GetDepMeshes( )->SetEntities( DepMeshes );
		for ( i = 0; i < DepMeshes->Count( ); i++ ) {
			depmesh = ToDepMesh( DepMeshes->GetShape( i ) );
			if ( !depmesh ) continue;
			index = depmesh->GetBaseEntities( )->GetEntityIndex( this );
			if ( index >= 0 ) {
				depmesh->GetBaseEntities( )->SetData( index, ent );
				depmesh->SetAllDirty( true );
			}
		}
		DepMeshes->Clear( );
	}

	SetAllDirty( true );
	ent->SetAllDirty( true );
}

//------------------------------------------------------------------------------

// Suponemos que ent no tiene relaciones previas
void TCadEntity::ChangeOwnRelatedShape2D( TCadShape *shape )
{
	bool setdirty;
	int i, j, index;
	TCadEntity *aux;
	TCadDepShape *depshape;
	TCadDepSurface *depsurface;
	TCadDepMesh *depmesh;

	if ( !shape ) return;

	// ENTITY TO ENTITY
	if ( !shape->GetRelatedEntities( ) ) shape->CreateRelatedEntities( );
	if ( RelatedEntities ) {
		for ( i = 0; i < RelatedEntities->Count( ); i++ ) {
			aux = RelatedEntities->GetShape( i );
			if ( !aux ) continue;
			for ( j = 0; j < aux->GetEntityRelationList( )->Count( ); j++ )
				if ( aux->GetEntityRelationList( )->GetItem( j )->BaseEntity == this ) {
					aux->GetEntityRelationList( )->GetItem( j )->BaseEntity = shape;
					aux->SetAllDirty( true );
				}
			shape->GetRelatedEntities( )->Add( aux );
			RelatedEntities->Detach( aux, NoDelete );
			i--;
		}
	}

	for ( i = 0; i < EntityRelationList.Count( ); i++ ) {
		aux = EntityRelationList.GetItem( i )->BaseEntity;
		if ( !aux || !aux->GetRelatedEntities( ) ) continue;
		index = aux->GetRelatedEntities( )->GetEntityIndex( this );
		if ( index >= 0 ) aux->GetRelatedEntities( )->SetData( index, shape );
		if ( EntityRelationList.GetItem( i )->Type == ER_TYPE_DEPENDENT_FRAME ) {
			if ( ToRect( this ) ) ToRect( this )->GetOGLImageTextureList( )->DelItem( 0 );
			if ( ToRect( shape ) ) ToRect( shape )->GetOGLImageTextureList( )->DelItem( 0 );
		}
		shape->GetEntityRelationList( )->AddItem( EntityRelationList.GetItem( i ) );
		EntityRelationList.DelItem( i );
		i--;
	}

	// DEPSHAPES
	if ( !shape->GetDepShapes( ) ) shape->CreateDepShapes( );
	if ( DepShapes ) {
		for ( i = 0; i < DepShapes->Count( ); i++ ) {
			depshape = ToDepShape( DepShapes->GetShape( i ) );
			if ( !depshape ) continue;
			if ( depshape->GetDualBaseEntity( ) == this ) continue; // la dual no la quitamos
			shape->GetDepShapes( )->Add( depshape );
			index = depshape->GetBaseEntities( )->GetEntityIndex( this );
			if ( index >= 0 ) {
				depshape->GetBaseEntities( )->SetData( index, shape );
				if ( depshape->IsPolyDepShape( ) ) depshape->GetPolyData( )->ChangeRelatedEntity( this, shape, setdirty );
				depshape->SetAllDirty( true );
			}
			DepShapes->Detach( depshape, NoDelete );
			i--;
		}
	}

	// DEPSURFACES
	if ( !shape->GetDepSurfaces( ) ) shape->CreateDepSurfaces( );
	if ( DepSurfaces ) {
		for ( i = 0; i < DepSurfaces->Count( ); i++ ) {
			depsurface = ToDepSurface( DepSurfaces->GetShape( i ) );
			if ( !depsurface ) continue;
			shape->GetDepSurfaces( )->Add( depsurface );
			index = depsurface->GetBaseEntities( )->GetEntityIndex( this );
			if ( index >= 0 ) {
				depsurface->GetBaseEntities( )->SetData( index, shape );
				depsurface->SetAllDirty( true );
			}
			DepSurfaces->Detach( depsurface, NoDelete );
			i--;
		}
	}

	// DEPMESHES
	if ( !shape->GetDepMeshes( ) ) shape->CreateDepMeshes( );
	if ( DepMeshes ) {
		for ( i = 0; i < DepMeshes->Count( ); i++ ) {
			depmesh = ToDepMesh( DepMeshes->GetShape( i ) );
			if ( !depmesh ) continue;
			shape->GetDepMeshes( )->Add( depmesh );
			index = depmesh->GetBaseEntities( )->GetEntityIndex( this );
			if ( index >= 0 ) {
				depmesh->GetBaseEntities( )->SetData( index, shape );
				depmesh->SetAllDirty( true );
			}
			DepMeshes->Detach( depmesh, NoDelete );
			i--;
		}
	}

	SetAllDirty( true );
	shape->SetAllDirty( true );
}

//------------------------------------------------------------------------------

void TCadEntity::ClearOwnRelations( )
{
	if ( RelatedEntities ) RelatedEntities->Clear( );
	EntityRelationList.Clear( );
	if ( DepShapes ) DepShapes->Clear( );
	if ( DepSurfaces ) DepSurfaces->Clear( );
	if ( DepMeshes ) DepMeshes->Clear( );
	ParamSurface = 0;
}

//------------------------------------------------------------------------------

bool TCadEntity::IsHidden( bool checkvisible )
{
	int i;
	TEntityRelation *entrel;

	if ( checkvisible && !Visible ) return true;

	for ( i = 0; i < EntityRelationList.Count( ); i++ ) {
		entrel = EntityRelationList.GetItem( i );
		if ( entrel && entrel->Type == ER_TYPE_DEPENDENT_HIDDEN ) return true;
	}

	if ( IsParamEntity( ) ) return GetParamSurface( )->IsHidden( checkvisible );
	return false;
}

//------------------------------------------------------------------------------

bool TCadEntity::IsDevelopable( )
{
	return Developable;
}

//------------------------------------------------------------------------------

void TCadEntity::SetDevelopable( bool dev )
{
	if ( dev == Developable ) return;

	Developable = dev;
	IsDevelop2DDirty = true;
}

//------------------------------------------------------------------------------

bool TCadEntity::IsInactive( TOGLTransf *OGLTransf )
{
	if ( !OGLTransf ) return false;

	if ( IsParamEntity( ) )
		if ( IsDevelopable( ) )
			if ( GetDevelopSurfIndex( ) != OGLTransf->GetDevelopSurfIndex( ) ) return true;
	return false;
}

//------------------------------------------------------------------------------

bool TCadEntity::IsIndependent( bool )
{
	return ( GetBaseSurface( ) == 0 );
}

//------------------------------------------------------------------------------

bool TCadEntity::HasEntityRelation( int reltype, int *index )
{
	int i;
	TEntityRelation *entrel;

	if ( index ) *index = -1;

	for ( i = 0; i < EntityRelationList.Count( ); i++ ) {
		entrel = EntityRelationList.GetItem( i );
		if ( entrel && entrel->Type == reltype ) {
			if ( index ) *index = i;
			return true;
		}
	}

	return false;
}

//------------------------------------------------------------------------------
// enttype( 0:todas, 1:bases, 2:dependientes )

int TCadEntity::GetEntityRelationEntities( TCadGroup *ents, int reltype, int enttype )
{
	int i, j;
	TEntityRelation *entrel;
	TCadEntity *ent;

	if ( !ents ) return 0;

	if ( enttype == 0 || enttype == 1 ) { // bases
		for ( i = 0; i < EntityRelationList.Count( ); i++ ) {
			entrel = EntityRelationList.GetItem( i );
			if ( entrel && entrel->Type == reltype ) ents->Add( entrel->BaseEntity );
		}
	}
	if ( enttype == 0 || enttype == 2 ) { // dependientes
		if ( RelatedEntities ) {
			for ( i = 0; i < RelatedEntities->Count( ); i++ ) {
				ent = RelatedEntities->GetShape( i );
				if ( !ent ) continue;
				for ( j = 0; j < ent->GetEntityRelationList( )->Count( ); j++ ) {
					entrel = ent->GetEntityRelationList( )->GetItem( j );
					if ( entrel->Type == reltype && entrel->BaseEntity == this ) ents->Add( ent );
				}
			}
		}
	}
	return ents->Count( );
}

//------------------------------------------------------------------------------

bool TCadEntity::CanApplyTransform( bool )
{
	return !IsParamEntity( );
}

//------------------------------------------------------------------------------

bool TCadEntity::SetRangeOGLParam2D( TOGLTransf *OGLTransf, bool inrange )
{
	bool close[ 2 ];
	double limits[ 4 ];
	TOGLPolygonList *List;

	if ( !IsParamEntity( ) ) return false;

	close[ 0 ] = ( GetParamSurface( )->GetUCloseExt( OGLTransf ) == ENT_CLOSE );
	close[ 1 ] = ( GetParamSurface( )->GetVCloseExt( OGLTransf ) == ENT_CLOSE );
	GetParamSurface( )->GetLimitsUV( OGLTransf, limits );

	List = GetOGLParam2D( OGLTransf );
	if ( inrange ) return List->InParamRange( close, limits );
	return List->OutParamRange( close, limits, GetParamSurface( )->GetOGLParam_1_Tol( ) );
}

//------------------------------------------------------------------------------

void TCadEntity::SetAllDirty( bool b, bool sisl, bool increasedirtyid )
{
	if ( increasedirtyid ) _GetNextDirtyID( );

	if ( sisl ) SetSISLDirty( b, false );
	SetPolygonDirty( b, false );
	SetGeom3DDirty( b, false );
	SetDevelop2DDirty( b, false );
}

//------------------------------------------------------------------------------

void TCadEntity::SetSISLDirty( bool b, bool increasedirtyid )
{
	int i, j;
	TCadEntity *ent;
	TEntityRelation *rel;

	IsSISLDirty = b;

	if ( !b ) return;

	if ( increasedirtyid ) _GetNextDirtyID( );
	else if ( _GetDirtyID( ) == SISLDirtyID )
		return;
	SISLDirtyID = _GetDirtyID( );

	if ( !LockSISLDirty ) {
		LockSISLDirty = true;
		if ( DepShapes )
			for ( i = 0; i < DepShapes->Count( ); i++ )
				DepShapes->GetShape( i )->SetAllDirty( true, true, false );
		if ( DepSurfaces )
			for ( i = 0; i < DepSurfaces->Count( ); i++ )
				DepSurfaces->GetShape( i )->SetAllDirty( true, true, false );
		if ( DepMeshes )
			for ( i = 0; i < DepMeshes->Count( ); i++ )
				DepMeshes->GetShape( i )->SetAllDirty( true, true, false );
		if ( RelatedEntities )
			for ( i = 0; i < RelatedEntities->Count( ); i++ ) {
				ent = RelatedEntities->GetShape( i );
				for ( j = 0; j < ent->GetEntityRelationList( )->Count( ); j++ ) {
					rel = ent->GetEntityRelationList( )->GetItem( j );
					if ( rel->BaseEntity == this && rel->Type == ER_TYPE_DEPENDENT_SE_DISTRIBUTE ) {
						RelatedEntities->GetShape( i )->SetAllDirty( true, true, false );
						break;
					}
				}
			}

		LockSISLDirty = false;
	}
}

//------------------------------------------------------------------------------

bool TCadEntity::GetPolygonDirty( )
{
	return IsPolygonDirty;
}

//------------------------------------------------------------------------------

void TCadEntity::SetPolygonDirty( bool b, bool increasedirtyid )
{
	int i;

	IsPolygonDirty = b;

	if ( !b ) return;

	IsExternalDirty = true;
	IsPBrepDirty = true;
	IsDeformer3DDirty = true;
	IsDeformerDataDirty = true;

	if ( GetOGLTextureData( )->TextureMode != TEXTURE_AUTO ) SetTextureDirty( true );

	if ( increasedirtyid ) _GetNextDirtyID( );
	else if ( _GetDirtyID( ) == PolygonDirtyID )
		return;
	PolygonDirtyID = _GetDirtyID( );

	if ( !LockPolygonDirty ) {
		LockPolygonDirty = true;
		if ( DepShapes )
			for ( i = 0; i < DepShapes->Count( ); i++ )
				DepShapes->GetShape( i )->SetAllDirty( true, true, false );
		if ( DepSurfaces )
			for ( i = 0; i < DepSurfaces->Count( ); i++ )
				DepSurfaces->GetShape( i )->SetAllDirty( true, true, false );
		if ( DepMeshes )
			for ( i = 0; i < DepMeshes->Count( ); i++ )
				DepMeshes->GetShape( i )->SetAllDirty( true, true, false );
		//		IsExternalDirty = true;
		//		IsPBrepDirty = true;
		//		IsDeformer3DDirty = true;
		//		IsDeformerDataDirty = true;
		//
		//		if ( GetOGLTextureData( )->TextureMode != TEXTURE_AUTO )
		//			SetTextureDirty( true );
		LockPolygonDirty = false;
	}
}

//------------------------------------------------------------------------------

void TCadEntity::SetGeom3DDirty( bool b, bool ) // increasedirtyid
{
	IsGeom3DDirty = b;

	//	if ( !b ) return;

	//	if ( increasedirtyid ) _GetNextDirtyID( );
	//	else if ( _GetDirtyID( ) == Geom3DDirtyID ) return;
	//	Geom3DDirtyID = _GetDirtyID( );
}

//------------------------------------------------------------------------------

void TCadEntity::SetDevelop2DDirty( bool b, bool increasedirtyid )
{
	int i;

	IsDevelop2DDirty = b;

	if ( !b ) return;

	if ( increasedirtyid ) _GetNextDirtyID( );
	else if ( _GetDirtyID( ) == Develop2DDirtyID )
		return;
	Develop2DDirtyID = _GetDirtyID( );

	if ( DepShapes )
		for ( i = 0; i < DepShapes->Count( ); i++ )
			DepShapes->GetShape( i )->SetAllDirty( true, true, false );
}

//------------------------------------------------------------------------------

bool TCadEntity::GetExternalDirty( )
{
	return IsExternalDirty;
}

//------------------------------------------------------------------------------

void TCadEntity::SetExternalDirty( bool b )
{
	IsExternalDirty = b;
}

//------------------------------------------------------------------------------

bool TCadEntity::GetPBrepDirty( )
{
	return IsPBrepDirty;
}

//------------------------------------------------------------------------------

void TCadEntity::SetPBrepDirty( bool b )
{
	IsPBrepDirty = b;
}

//------------------------------------------------------------------------------

bool TCadEntity::GetPBrepTrianglesForced( )
{
	if ( AppliedRemesh ) return false;
	return PBrepTrianglesForced;
}

//------------------------------------------------------------------------------

void TCadEntity::SetPBrepTrianglesForced( bool b )
{
	PBrepTrianglesForced = b;
}

//------------------------------------------------------------------------------

bool TCadEntity::GetDeformer3DDirty( )
{
	return IsDeformer3DDirty;
}

//------------------------------------------------------------------------------

void TCadEntity::SetDeformer3DDirty( bool b )
{
	IsDeformer3DDirty = b;
	if ( b ) IsDeformerTextureDirty = b;
	else
		IsDeformerDataDirty = b;
}

//------------------------------------------------------------------------------

bool TCadEntity::GetDeformerDataDirty( )
{
	return IsDeformerDataDirty;
}

//------------------------------------------------------------------------------

void TCadEntity::SetDeformerDataDirty( bool b )
{
	IsDeformerDataDirty = b;
	if ( b ) {
		IsDeformer3DDirty = b;
		IsDeformerTextureDirty = b;
	}
}

//------------------------------------------------------------------------------

bool TCadEntity::GetDeformerTextureDirty( )
{
	return IsDeformerTextureDirty;
}

//------------------------------------------------------------------------------

void TCadEntity::SetDeformerTextureDirty( bool b )
{
	IsDeformerTextureDirty = b;
}

//------------------------------------------------------------------------------

void TCadEntity::SetLockRecalc( bool b )
{
	LockRecalc = b;
}

//------------------------------------------------------------------------------

bool TCadEntity::GetLockNormals( )
{
	return LockNormals;
}

//------------------------------------------------------------------------------

void TCadEntity::SetLockNormals( bool b )
{
	if ( LockNormals == b ) return;

	LockNormals = b;
	SetAllDirty( true );
}

//------------------------------------------------------------------------------

bool TCadEntity::GetConvertToTriangles( )
{
	return ConvertToTriangles;
}

//------------------------------------------------------------------------------

void TCadEntity::SetConvertToTriangles( bool b )
{
	if ( b == ConvertToTriangles ) return;

	ConvertToTriangles = b;
	SetAllDirty( true, false );
}

//------------------------------------------------------------------------------

bool TCadEntity::CalcBoundRect( TOGLTransf *OGLTransf, T3DRect &r, bool outrange, TNMatrix *mat )
{
	int i, n;
	bool first, close[ 2 ];
	double limits[ 4 ];
	T3DRect r1;
	TOGLPolygonList **Lists, AuxList;

	r = T3DRect( 0, 0, 0, 0, 0, 0 );
	if ( !CalcOGLLists( OGLTransf ) ) return false;
	Lists = 0;
	n = GetOGLViewLists( OGLTransf, &Lists );
	if ( n ) {
		first = true;
		if ( outrange && !IsParamEntity( ) ) outrange = false;
		if ( outrange ) {
			close[ 0 ] = ( GetParamSurface( )->GetUCloseExt( OGLTransf ) == ENT_CLOSE );
			close[ 1 ] = ( GetParamSurface( )->GetVCloseExt( OGLTransf ) == ENT_CLOSE );
			GetParamSurface( )->GetLimitsUV( OGLTransf, limits );
		}
		for ( i = 0; i < n; i++ ) {
			if ( outrange ) {
				AuxList.Set( Lists[ i ] );
				AuxList.OutParamRange( close, limits, GetParamSurface( )->GetOGLParam_1_Tol( ) );
				if ( !AuxList.CalcBoundRect( r1, mat ) ) continue;
			} else if ( !Lists[ i ]->CalcBoundRect( r1, mat ) )
				continue;
			if ( first ) {
				r = r1;
				first = false;
			} else
				r |= r1;
		}
		delete[] Lists;
		return ( first ? false : true );
	} else if ( !IsRightViewMode( OGLTransf ) )
		return DataBoundRect( OGLTransf, r, mat );
	return false;
}

//------------------------------------------------------------------------------

bool TCadEntity::CalcBoundRectParam( TOGLTransf *OGLTransf, T3DRect &r, bool outrange, TNMatrix *mat )
{
	bool close[ 2 ];
	double limits[ 4 ];
	TOGLPolygonList *List, AuxList;

	r = T3DRect( 0, 0, 0, 0, 0, 0 );

	List = ( IsParamEntity( ) ? GetOGLList( OGLTransf ) : 0 );
	if ( !List ) return false;

	if ( outrange ) {
		close[ 0 ] = ( GetParamSurface( )->GetUCloseExt( OGLTransf ) == ENT_CLOSE );
		close[ 1 ] = ( GetParamSurface( )->GetVCloseExt( OGLTransf ) == ENT_CLOSE );
		GetParamSurface( )->GetLimitsUV( OGLTransf, limits );

		AuxList.Set( List );
		AuxList.OutParamRange( close, limits, GetParamSurface( )->GetOGLParam_1_Tol( ) );
		if ( !AuxList.CalcBoundRect( r, mat ) ) return false;
	} else if ( !List->CalcBoundRect( r, mat ) )
		return false;

	return true;
}

//------------------------------------------------------------------------------

bool TCadEntity::GetBoundRectInPlane( TOGLTransf *OGLTransf, TLRect &rect )
{
	bool inverted;
	T3DRect r;
	TNPlane plane;

	if ( !CalcBoundRect( OGLTransf, r ) ) return false;

	inverted = ( IsParamEntity( ) ? false : OGLTransf->IsAxesInverted( ) );
	plane = ( IsParamEntity( ) ? plXY : OGLTransf->GetPlane( ) );
	if ( plane == plXY ) {
		if ( !inverted ) {
			rect.left = r.left;
			rect.right = r.right;
			rect.top = r.top;
			rect.bottom = r.bottom;
		} else {
			rect.left = r.top;
			rect.right = r.bottom;
			rect.top = r.left;
			rect.bottom = r.right;
		}
	} else if ( plane == plXZ ) {
		if ( !inverted ) {
			rect.left = r.left;
			rect.right = r.right;
			rect.top = r.front;
			rect.bottom = r.back;
		} else {
			rect.left = r.front;
			rect.right = r.back;
			rect.top = r.left;
			rect.bottom = r.right;
		}
	} else if ( plane == plYZ ) {
		if ( !inverted ) {
			rect.left = r.top;
			rect.right = r.bottom;
			rect.top = r.front;
			rect.bottom = r.back;
		} else {
			rect.left = r.front;
			rect.right = r.back;
			rect.top = r.top;
			rect.bottom = r.bottom;
		}
	}
	return true;
}

//------------------------------------------------------------------------------

bool TCadEntity::CalcBoundRectViewport( TOGLTransf *OGLTransf, TLRect &r, int step, TNMatrix *MirrorMat, TInstanceList *list )
{
	int i, n;
	bool first;
	TLRect r1;
	TOGLPolygonList **Lists;

	r = TLRect( 0, 0, 0, 0 );
	if ( !CalcOGLLists( OGLTransf ) ) return false;
	Lists = 0;
	n = GetOGLViewLists( OGLTransf, &Lists );
	if ( n ) {
		first = true;
		for ( i = 0; i < n; i++ ) {
			if ( !Lists[ i ]->CalcBoundRectViewport( OGLTransf, r1, step, MirrorMat, list ) ) continue;
			if ( first ) {
				r = r1;
				first = false;
			} else
				r |= r1;
		}
		delete[] Lists;
		return ( first ? false : true );
	}
	return false;
}

//------------------------------------------------------------------------------

T3DPoint TCadEntity::Size( TOGLTransf *OGLTransf )
{
	T3DRect r;

	CalcBoundRect( OGLTransf, r );
	return r.Size( );
}

//------------------------------------------------------------------------------

bool TCadEntity::GravityCenter( TOGLTransf *OGLTransf, T3DPoint &pt )
{
	int i, n;
	TOGLPolygonList **Lists;

	pt = T3DPoint( 0, 0, 0 );
	if ( !CalcOGLLists( OGLTransf ) ) return false;
	Lists = 0;
	n = GetOGLViewLists( OGLTransf, &Lists );
	if ( n ) {
		for ( i = 0; i < n; i++ )
			pt = pt + Lists[ i ]->GravityCenter( );
		pt = pt / n;
		delete[] Lists;
	}
	return ( n > 0 );
}

//------------------------------------------------------------------------------

bool TCadEntity::GravityCenter( TOGLTransf *OGLTransf, T3DPoint &pt, double inc )
{
	int i, n;
	TOGLPolygonList **Lists;

	pt = T3DPoint( 0, 0, 0 );
	if ( !CalcOGLLists( OGLTransf ) ) return false;
	Lists = 0;
	n = GetOGLViewLists( OGLTransf, &Lists );
	if ( n ) {
		for ( i = 0; i < n; i++ )
			pt = pt + Lists[ i ]->GravityCenter( inc );
		pt = pt / n;
		delete[] Lists;
	}
	return ( n > 0 );
}

//------------------------------------------------------------------------------

bool TCadEntity::IsValid( TOGLTransf *OGLTransf )
{
	return OGLTransf->IsValid( Size( OGLTransf ) );
}

//------------------------------------------------------------------------------

void TCadEntity::GetShapeInfo( TOGLTransf *OGLTransf, TShapeInfo *si )
{
	if ( !OGLTransf ) return;
	si->NumVertexs = Count( );
	si->Perimeter = Perimeter( OGLTransf );
	si->Area = Area( OGLTransf );
	si->Size = Size( OGLTransf );
}

//------------------------------------------------------------------------------

void TCadEntity::ClearOGLLists( )
{
	SetAllDirty( true, false );

	OGLPolygonList.Clear( true );
	OGLGeom3DList.Clear( true );
	OGLDevelop2DList.Clear( true );
}

//------------------------------------------------------------------------------

void TCadEntity::SetID( int id, bool download )
{
	if ( ID == id ) return;

	ID = id;
	if ( download ) Download_glList( );
}

//------------------------------------------------------------------------------

void TCadEntity::ClearID( )
{
	ID = -1;

	OGLPolygonList.ClearID( );
	OGLGeom3DList.ClearID( );
	OGLDevelop2DList.ClearID( );
}

//------------------------------------------------------------------------------

void TCadEntity::Download_glList( )
{
	OGLPolygonList.Download_glList( );
	OGLGeom3DList.Download_glList( );
	OGLDevelop2DList.Download_glList( );
	if ( OGLDeformer3DList ) OGLDeformer3DList->Download_glList( );
}

//------------------------------------------------------------------------------

void TCadEntity::Download( )
{
	OGLPolygonList.Download( );
	OGLGeom3DList.Download( );
	OGLDevelop2DList.Download( );
	if ( OGLDeformer3DList ) OGLDeformer3DList->Download( );
}

//------------------------------------------------------------------------------

void TCadEntity::ReplaceID( int oldid, int newid )
{
	if ( ID == oldid ) SetID( newid );
}

//------------------------------------------------------------------------------

void TCadEntity::ReplaceID( TInteger_List *oldids, TInteger_List *newids )
{
	int index;

	if ( !oldids || !newids || oldids->Count( ) != newids->Count( ) ) return;

	index = oldids->GetItemIndex( &ID );
	if ( index >= 0 ) SetID( *newids->GetItem( index ) );
}

//------------------------------------------------------------------------------

int TCadEntity::GetVersion( )
{
	return Version;
}

//------------------------------------------------------------------------------

void TCadEntity::SetVersion( int value )
{
	Version = value;
}

//------------------------------------------------------------------------------

bool TCadEntity::IsEntityIncluded( TCadEntity *entity, bool )
{
	return ( entity == this );
}

//------------------------------------------------------------------------------

int TCadEntity::GetEntityIndex( TCadEntity *entity, bool, int *curindex ) // recursive
{
	if ( !curindex ) return -1;

	if ( entity == this ) return *curindex;
	( *curindex )++;
	return -1;
}

//------------------------------------------------------------------------------

TCadEntity *TCadEntity::GetEntityByIndex( int index, int *curindex )
{
	if ( *curindex == index ) return this;
	( *curindex )++;
	return 0;
}

//------------------------------------------------------------------------------

void TCadEntity::AddEntitiesToGroup( TCadGroup *Grp, bool ForceNoCopy )
{
	TCadEntity *Ent;
	if ( !Grp ) return;

	if ( Grp->DestroyList && !ForceNoCopy ) {
		Ent = _CreateBasicShape( this, false );
		Grp->Add( Ent, false );
	} else if ( !Grp->IsEntityIncluded( this, false ) )
		Grp->Add( this, false );
}

//------------------------------------------------------------------------------

void TCadEntity::SetOwnOGLRenderData( bool o )
{
	OwnOGLRenderData = o;
	IsExternalDirty = true;
	//	SetAllDirty( true, false ); No siempre es necesario, forzar desde fuera
}

//------------------------------------------------------------------------------

void TCadEntity::SetOGLRenderData( TOGLRenderData *oglrddata )
{
	OGLRenderData.Set( oglrddata );
	IsExternalDirty = true;
	SetOGLDisplayData( oglrddata->GetOGLDisplayData( ) );
}

//------------------------------------------------------------------------------

void TCadEntity::SetOGLDisplayData( TOGLDisplayData *dd )
{
	if ( !dd || *dd == OGLPolygonList.OGLDisplayData ) return;

	OGLPolygonList.SetOGLDisplayData( dd );
	OGLGeom3DList.SetOGLDisplayData( dd );
	OGLDevelop2DList.SetOGLDisplayData( dd );
	Download( );
	//	SetAllDirty( true, false ); No siempre es necesario, forzar desde fuera
}

//------------------------------------------------------------------------------

void TCadEntity::SetOGLDisplayData( int type, GLenum displaymode, int tess, GLfloat error, GLfloat cordal, GLfloat angle, TOGLFloat2 stepuv, bool isstepres, GLfloat *qualityfactor )
{
	if ( type < 0 || type >= N_TESS_ENT_TYPES ) return;
	if ( displaymode == OGLPolygonList.OGLDisplayData.DisplayMode && tess == OGLPolygonList.OGLDisplayData.TesselationMode[ type ] && error == OGLPolygonList.OGLDisplayData.DisplayError[ type ] && cordal == OGLPolygonList.OGLDisplayData.CordalLength[ type ] && angle == OGLPolygonList.OGLDisplayData.Angle[ type ] && isstepres == OGLPolygonList.OGLDisplayData.IsStepRes[ type ] && stepuv == OGLPolygonList.OGLDisplayData.StepUV[ type ] &&
		( !qualityfactor || ( *qualityfactor ) == OGLPolygonList.OGLDisplayData.QualityFactor ) )
		return;

	OGLPolygonList.SetOGLDisplayData( type, displaymode, tess, error, cordal, angle, stepuv, isstepres, qualityfactor );
	OGLGeom3DList.SetOGLDisplayData( type, displaymode, tess, error, cordal, angle, stepuv, isstepres, qualityfactor );
	OGLDevelop2DList.SetOGLDisplayData( type, displaymode, tess, error, cordal, angle, stepuv, isstepres, qualityfactor );
	Download( );
	//	SetAllDirty( true, false ); No siempre es necesario, forzar desde fuera
}

//------------------------------------------------------------------------------

void TCadEntity::GetOGLDisplayData( int type, GLenum &displaymode, int &tess, GLfloat &error, GLfloat &cordal, GLfloat &angle, TOGLFloat2 &stepuv, bool &isstepres, GLfloat *qualityfactor )
{
	if ( type < 0 || type >= N_TESS_ENT_TYPES ) return;
	displaymode = OGLPolygonList.OGLDisplayData.DisplayMode;
	tess = OGLPolygonList.OGLDisplayData.TesselationMode[ type ];
	error = OGLPolygonList.OGLDisplayData.DisplayError[ type ];
	cordal = OGLPolygonList.OGLDisplayData.CordalLength[ type ];
	angle = OGLPolygonList.OGLDisplayData.Angle[ type ];
	isstepres = OGLPolygonList.OGLDisplayData.IsStepRes[ type ];
	stepuv = OGLPolygonList.OGLDisplayData.StepUV[ type ];
	if ( qualityfactor ) *qualityfactor = OGLPolygonList.OGLDisplayData.QualityFactor;
}

//------------------------------------------------------------------------------

void TCadEntity::UpdateUnselectMats( TOGLRenderData *_OGLRdData, TOGLRenderSystem *_OGLRdSystem )
{
	//   bool transparent;
	int i;
	TOGLMaterial *OGLMat[ 2 ];

	if ( !_OGLRdSystem->DrawAsUnselect ) return;

	if ( _OGLRdSystem->DrawAsUnselectedMode == DAUM_MAT ) {
		//      transparent = _OGLRdData->GetMaterial( FRONT )->IsTransparent( );
		_OGLRdData->SetActiveTextureMat( false );
		_OGLRdData->GetMtNoTextureList( )->Clear( );
		OGLMat[ FRONT ] = _OGLRdData->GetMaterial( FRONT, MT_NOTEXTURE );
		OGLMat[ BACK ] = _OGLRdData->GetMaterial( BACK, MT_NOTEXTURE );
		OGLMat[ FRONT ]->Set( _OGLRdSystem->GetMaterial( GetUnselectMatIndex( ) ) );
		OGLMat[ BACK ]->Set( _OGLRdSystem->GetMaterial( GetUnselectMatIndex( ) ) );
		//      if ( transparent ) {
		//		  	  OGLMat[ FRONT ]->SetTransparent( 0.2 );
		//		  	  OGLMat[ BACK ]->SetTransparent( 0.2 );
		//      }
		return;
	}

	if ( _OGLRdSystem->DrawAsUnselectedMode == DAUM_TRANS ) {
		if ( _OGLRdData->GetActiveTextureMat( ) ) {
			OGLMat[ FRONT ] = _OGLRdData->GetMaterial( FRONT, MT_TEXTURE );
			//			OGLMat[ FRONT ]->Texture.ApplyTexture = false;
			OGLMat[ FRONT ]->SetTransparent( 0.2 );
			OGLMat[ FRONT ]->UseOpacityMap = false;
		} else {
			for ( i = 0; i < _OGLRdData->GetMtNoTextureList( )->Count( ); i++ ) {
				OGLMat[ FRONT ] = _OGLRdData->GetMaterial( FRONT, MT_NOTEXTURE, i );
				OGLMat[ BACK ] = _OGLRdData->GetMaterial( BACK, MT_NOTEXTURE, i );
				OGLMat[ FRONT ]->SetTransparent( 0.2 );
				OGLMat[ BACK ]->SetTransparent( 0.2 );
			}
		}
		return;
	}
}

//------------------------------------------------------------------------------

void TCadEntity::ApplyOGLRenderData( TOGLTransf *OGLTransf, TOGLRenderData *_OGLRdData, TOGLRenderSystem *_OGLRdSystem, bool &applytexturecoords )
{
	bool usecolors, recalc;
	int n;
	TColor auxcolor;
	TOGLMaterial *OGLMat[ 2 ], emptymat;
	TOGLPolygonList **Lists;
	TOGLPolygonList *_Colors;

	UpdateUnselectMats( _OGLRdData, _OGLRdSystem );
	UpdateStipple( _OGLRdData, _OGLRdSystem );

	if ( _OGLRdSystem->DrawNormalsMode ) {
		OGLMat[ FRONT ] = _OGLRdSystem->GetMaterial( SYSMAT_NORMALFRONT );
		OGLMat[ BACK ] = _OGLRdSystem->GetMaterial( SYSMAT_NORMALBACK );
		_OGLRdData->SetActiveTextureMat( false );
	} else if ( _OGLRdData->ActiveUseOfSecondaryMat ) {
		OGLMat[ FRONT ] = _OGLRdData->GetMaterial( FRONT, MT_SECONDARY );
		OGLMat[ BACK ] = _OGLRdData->GetMaterial( BACK, MT_SECONDARY );
	} else if ( _OGLRdData->IsSingleMaterialUsed( ) ) {
		OGLMat[ FRONT ] = _OGLRdData->GetMaterial( FRONT );
		OGLMat[ BACK ] = _OGLRdData->GetMaterial( BACK );
	}

	applytexturecoords = false;

	if ( _OGLRdData->OGLDisplayData.DisplayMode == INES_GLU_OUTLINE_PATCH || _OGLRdData->OGLDisplayData.DisplayMode == INES_GLU_SILHOUETTE ) {
		glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );

		if ( _OGLRdSystem->EnablePolygonOffset ) {
			glEnable( GL_POLYGON_OFFSET_LINE );
			glPolygonOffset( 1.0 / ( _OGLRdSystem->LineWidth * _OGLRdSystem->LineWidthFactor ), 1.0 );
		}

		glLineWidth( _OGLRdSystem->LineWidth * _OGLRdSystem->LineWidthFactor );

		if ( !_OGLRdSystem->IsSelectMode && !_OGLRdSystem->IsShadowMode ) {
			glShadeModel( GL_FLAT );
			//			glEnable( GL_LINE_SMOOTH );
			if ( _OGLRdData->IsSingleMaterialUsed( ) ) {
				glColor3f( OGLMat[ FRONT ]->Diffuse.r, OGLMat[ FRONT ]->Diffuse.g, OGLMat[ FRONT ]->Diffuse.b );
				if ( _OGLRdData->GetStipple( ) ) {
					glEnable( GL_LINE_STIPPLE );
					glLineStipple( _OGLRdData->GetStippleFactor( ), _OGLRdData->GetStipplePattern( ) );
				}
			}
		}

	} else if ( _OGLRdData->OGLDisplayData.DisplayMode == INES_GLU_OUTLINE_POLYGON ) {
		glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );

		if ( _OGLRdSystem->EnablePolygonOffset ) {
			glEnable( GL_POLYGON_OFFSET_LINE );
			glPolygonOffset( 1.0 / ( _OGLRdSystem->LineWidth * _OGLRdSystem->LineWidthFactor ), 1. );
		}

		if ( !_OGLRdSystem->DrawShadows ) {
			if ( _OGLRdData->CullFace ) glEnable( GL_CULL_FACE );
			else
				glDisable( GL_CULL_FACE );
		}
		if ( !_OGLRdSystem->IsSelectMode && !_OGLRdSystem->IsShadowMode ) {
			glShadeModel( GL_FLAT );
			glEnable( GL_LIGHTING );
			if ( _OGLRdData->IsSingleMaterialUsed( ) ) OGLMat[ FRONT ]->Apply( );
		}
	} else {
		glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );

		if ( _OGLRdSystem->EnablePolygonOffset ) {
			glEnable( GL_POLYGON_OFFSET_FILL );
			glPolygonOffset( _OGLRdSystem->IsShadowMode ? 0.01 : 1.0 / ( _OGLRdSystem->LineWidth * _OGLRdSystem->LineWidthFactor ), 1. );
		}

		//		glEnable( GL_POLYGON_SMOOTH );
		if ( _OGLRdData->Smooth ) glShadeModel( GL_SMOOTH );
		else
			glShadeModel( GL_FLAT );

		if ( !_OGLRdSystem->DrawShadows ) {
			if ( _OGLRdData->CullFace ) glEnable( GL_CULL_FACE );
			else
				glDisable( GL_CULL_FACE );
		}

		if ( !_OGLRdSystem->IsSelectMode && !_OGLRdSystem->IsShadowMode ) {
			glEnable( GL_LIGHTING );
			_Colors = OwnOGLRenderData ? OGLRenderData.Colors : _OGLRdData->Colors;
			usecolors = ( _OGLRdData->ActiveColors && _Colors && _Colors->Count( ) && !_OGLRdSystem->IsSelectMode && !_OGLRdSystem->IsShadowMode );
			if ( usecolors && _OGLRdSystem->DrawAsUnselect && _OGLRdSystem->DrawAsUnselectedMode != DAUM_NONE ) usecolors = false;
			if ( usecolors ) {
				Lists = 0;
				n = GetOGLViewLists( OGLTransf, &Lists );
				if ( n ) {
					usecolors = ( n == 1 && _Colors->Count( ) == Lists[ 0 ]->Count( ) );
					delete[] Lists;
				}
			}

			if ( usecolors ) {
				emptymat.Apply( ); // coloca caracteristica para el resto de componentes que no son el difuso
				glColorMaterial( GL_FRONT_AND_BACK, GL_DIFFUSE );
				glEnable( GL_COLOR_MATERIAL );
			} else if ( _OGLRdData->IsSingleMaterialUsed( ) ) {
				if ( _OGLRdData->GetActiveTextureMat( ) ) { // _OGLRdSystem->DrawAsUnselect ||
					if ( !OGLMat[ FRONT ]->MixAlbedoWithColor ) {
						auxcolor = OGLMat[ FRONT ]->GetColor( );
						OGLMat[ FRONT ]->SetColor( _OGLRdSystem->GetMaterial( SYSMAT_TEXTURE )->GetColor( ) );
					}
					OGLMat[ FRONT ]->Apply( );
					if ( !OGLMat[ FRONT ]->MixAlbedoWithColor ) OGLMat[ FRONT ]->SetColor( auxcolor );
				} else {
					OGLMat[ FRONT ]->Apply( GL_FRONT );
					OGLMat[ BACK ]->Apply( GL_BACK );
				}
				if ( !OGLRenderData.ActiveTextureUV ) _OGLRdData->ActiveTextureUV = false;
				// if ( !_OGLRdSystem->DrawAsUnselect ) { 06_2022 Eliseo. Quitado porque en el modo DAUM_TRANS aunque pone applytexture a false si que utiliza la textura en la funcion de dibujado DrawOGL de la polygonlist
				if ( _OGLRdData->ActiveTextureUV ) applytexturecoords = ApplyTextureList( OGLTransf, _OGLRdData, MustCalcOGLLists( _OGLRdSystem ) );
				else {
					recalc = MustCalcOGLLists( _OGLRdSystem ) || ( !IsPolygonDirty && IsTextureDirty );
					applytexturecoords = ApplyTexture( OGLTransf, _OGLRdSystem, OGLMat[ FRONT ]->GetCurrentOGLTexture( ), OGLMat[ FRONT ]->IsMaxwell, recalc ); // IsTextureDirty ||
					if ( IsDeformerTextureDirty && OGLTransf->GetDeformMode( ) != DEFORMER_VIEW_NONE )
						if ( OGLTransf->GetForceMode( ) == VIEW_GEOM3D || ( OGLTransf->GetForceMode( ) == VIEW_NONE && OGLTransf->GetViewMode( ) == VIEW_GEOM3D ) ) UpdateDeformed3DListTextureCoords( OGLTransf );
				}
				// }
			}
		}
	}
}

//------------------------------------------------------------------------------

void TCadEntity::SetTextureDirty( bool b )
{
	IsTextureDirty = b;
	if ( b ) {
		IsExternalDirty = true;
		IsDeformerTextureDirty = true;
	}

	//   if ( b ) Download( );
}

//------------------------------------------------------------------------------

TOGLTextureDataList *TCadEntity::GetOGLTextureDataList( bool )
{
	return &OGLTextureDataList;
}

//------------------------------------------------------------------------------

void TCadEntity::SetOGLTextureDataList( TOGLTextureDataList *list, bool )
{
	if ( !list ) return;

	OGLTextureDataList.Set( list );
	SetTextureDirty( true );
}

//------------------------------------------------------------------------------

TOGLTextureData *TCadEntity::GetOGLTextureData( int index )
{
	if ( index < 0 ) index = OGLTextureDataList.GetCurrentIndex( );
	return OGLTextureDataList.GetItem( index );
}

//------------------------------------------------------------------------------

void TCadEntity::SetOGLTextureData( TOGLTextureData *data, int index )
{
	TOGLTextureData *ogltexdata;

	if ( !data ) return;

	if ( index < 0 ) index = OGLTextureDataList.GetCurrentIndex( );
	ogltexdata = OGLTextureDataList.GetItem( index );
	if ( !ogltexdata ) return;

	if ( ogltexdata->IsEqual( data ) ) return;

	ogltexdata->Set( data );
	SetTextureDirty( true );
}

//------------------------------------------------------------------------------

void TCadEntity::SetTextureMode( int mode, bool applyAll )
{
	bool found;
	int i;

	if ( applyAll ) {
		found = false;
		for ( i = 0; i < OGLTextureDataList.Count( ); i++ ) {
			if ( OGLTextureDataList.GetItem( i )->TextureMode == mode ) continue;
			OGLTextureDataList.GetItem( i )->TextureMode = mode;
			found = true;
		}
	} else {
		if ( OGLTextureDataList.GetCurrentItem( ) && OGLTextureDataList.GetCurrentItem( )->TextureMode != mode ) {
			OGLTextureDataList.GetCurrentItem( )->TextureMode = mode;
			found = true;
		}
	}
	if ( found ) SetTextureDirty( true );

	if ( mode == TEXTURE_DEVELOP_MESH && OGLPolygonList.Count( ) ) OGLPolygonList.GetItem( 0 )->SetUseTextures( true );
}

//------------------------------------------------------------------------------

bool TCadEntity::CalcTextureListCoords( TOGLTransf *OGLTransf, TOGLRenderData *_OGLRdData )
{
	int i, numPols, numCoords;
	TOGLRenderData *oglrddata;
	TOGLPolygonList *OGLList;

	if ( !CalcOGLLists( OGLTransf ) ) return false;
	if ( !IsTextureDirty ) return true;
	if ( GetOGLTextureData( )->TextureMode != TEXTURE_UV ) return false;

	oglrddata = OwnOGLRenderData ? &OGLRenderData : _OGLRdData;

	OGLList = GetOGLList( OGLTransf );
	numPols = OGLList->Count( );
	numCoords = oglrddata->CountTextureUVCoords( );
	if ( numCoords <= 0 || ( numPols % numCoords != 0 ) ) return false;
	for ( i = 0; i < numPols; i++ )
		if ( OGLList->GetItem( i ) && OGLList->GetItem( i )->Count( ) != oglrddata->TextureUVCoords->GetItem( i % numCoords )->Count( ) ) return false;
	SetTextureDirty( false );
	return true;
}

//------------------------------------------------------------------------------

bool TCadEntity::ApplyTextureList( TOGLTransf *OGLTransf, TOGLRenderData *_OGLRdData, bool recalc )
{
	int i, compindex;

	if ( GetOGLTextureData( )->TextureMode != TEXTURE_UV ) return false;

	compindex = OGLTransf->GetTextureCompilationIndex( );
	for ( i = 0; i < _OGLRdData->CountTextureUVList( ); i++ )
		if ( !_OGLRdData->TextureUVList->GetItem( i )->ApplyTexture || _OGLRdData->TextureUVList->GetItem( i )->ID[ compindex ] <= ID_OGL_TEXTURE ) return false;
	if ( recalc && !CalcTextureListCoords( OGLTransf, _OGLRdData ) ) {
		glTexGeni( GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP );
		glTexGeni( GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP );
		glEnable( GL_TEXTURE_GEN_S );
		glEnable( GL_TEXTURE_GEN_T );
	}
	return true;
}

//------------------------------------------------------------------------------

bool TCadEntity::ApplyTexture( TOGLTransf *OGLTransf, TOGLRenderSystem *, TOGLTexture *_OGLTexture, bool ismaxwell, bool recalc )
{
	if ( !_OGLTexture || ( GetOGLTextureData( )->TextureMode == TEXTURE_UV && !GetOGLTextureData( )->UseBaseTextures ) ) return false;
	if ( !_OGLTexture->ApplyTexture && !ismaxwell ) return false;

	if ( GetOGLTextureData( )->TextureMode == TEXTURE_AUTO || ( recalc && !CalcTextureCoords( OGLTransf, _OGLTexture ) ) ) {
		glTexGeni( GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP );
		glTexGeni( GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP );
		glEnable( GL_TEXTURE_GEN_S );
		glEnable( GL_TEXTURE_GEN_T );
		return false;
	}
	return true;
}

//------------------------------------------------------------------------------

void TCadEntity::DrawOGL( TOGLTransf *OGLTransf, TOGLRenderData *_OGLRdData, TOGLRenderSystem *_OGLRdSystem )
{
	bool ok, recalc, applytexturecoords, drawgrading, drawrotation;
	int dmm;
	float linewidth;
	TCadEntity *Ent;
	TApplyOGLRenderDataParams applyOGLRdDataParams;

	ok = true;
	recalc = MustCalcOGLLists( _OGLRdSystem );
	if ( recalc && !CalcOGLLists( OGLTransf ) ) ok = false;

	if ( _OGLRdSystem->DrawOnlyMarkers ) {
		Ent = GetEntityToDrawOGLMarkers( );
		if ( !ok && Ent == this ) return;
		if ( Ent && Ent->MustDrawOGLMarkers( OGLTransf, _OGLRdSystem ) ) Ent->DrawOGLMarkers( OGLTransf, _OGLRdSystem );
		return;
	}

	if ( ok ) {
		if ( _OGLRdSystem->UseApplyOGLRdDataParams )
			; // no hacer nada, parametros almacenados en applyOGLRdDataParams
		else
			applyOGLRdDataParams.Get( );
		if ( IsFillEntity( false ) ) {
			linewidth = _OGLRdSystem->LineWidth;
			_OGLRdSystem->LineWidth = 1;
			ApplyOGLRenderData( OGLTransf, _OGLRdData, _OGLRdSystem, applytexturecoords );
			_OGLRdSystem->LineWidth = linewidth;
		} else {
			ApplyOGLRenderData( OGLTransf, _OGLRdData, _OGLRdSystem, applytexturecoords );
		}

		if ( _OGLRdSystem->ForceNameID >= 0 ) glLoadName( _OGLRdSystem->ForceNameID );
		else if ( ID >= 0 )
			glLoadName( ID );

		drawgrading = drawrotation = false;
		if ( !_OGLRdSystem->IsSelectMode && OGLTransf->GetViewMode( ) == VIEW_DEVELOP2D ) {
			if ( _OGLRdSystem->DrawMarkersMode == DMM_GRADING2D ) {
				Ent = GetEntityToDrawOGLMarkers( );
				drawgrading = ToShape( Ent ) && Ent->MustDrawOGLMarkers( OGLTransf, _OGLRdSystem ) && ToShape( Ent )->LineMarkersCount( LM_TYPE_GRADING2D );
				if ( drawgrading && GetDualBaseEntity( )->AmIStrictPolyline( ) && GetDualBaseEntity( )->Type == POLYLINETYPE_POINTS ) drawgrading = false;
			}
			if ( !drawgrading && _OGLRdSystem->DrawMarkersMode == DMM_ROTATION ) {
				Ent = GetEntityToDrawOGLMarkers( );
				drawrotation = ToShape( Ent ) && Ent->MustDrawOGLMarkers( OGLTransf, _OGLRdSystem ) && ToShape( Ent )->LineMarkersCount( LM_TYPE_ROTATION_ANGLE );
			}
		}

		if ( drawgrading ) DrawOGLPolygonGrading2D( OGLTransf, _OGLRdData, _OGLRdSystem, applytexturecoords, recalc );
		else if ( drawrotation )
			DrawOGLPolygonRotation2D( OGLTransf, _OGLRdData, _OGLRdSystem, applytexturecoords, recalc );
		else
			DrawOGLPolygon( OGLTransf, _OGLRdData, _OGLRdSystem, applytexturecoords, recalc );

		if ( _OGLRdSystem->DrawCenterArrow ) DrawOGLCenterArrow( OGLTransf, _OGLRdSystem );

		if ( _OGLRdSystem->UseApplyOGLRdDataParams ) _OGLRdSystem->ApplyOGLRdDataParams.Set( );
		else
			applyOGLRdDataParams.Set( );
	}

	if ( !_OGLRdSystem->IsSelectMode ) {
		Ent = GetEntityToDrawOGLMarkers( );
		if ( !ok && Ent == this ) return;
		if ( Ent && Ent->MustDrawOGLMarkers( OGLTransf, _OGLRdSystem ) ) Ent->DrawOGLMarkers( OGLTransf, _OGLRdSystem );
		else if ( Ent && Ent->MustDrawOGLMarkersSymbolic( OGLTransf, _OGLRdSystem ) ) {
			dmm = _OGLRdSystem->DrawMarkersMode;
			_OGLRdSystem->DrawMarkersMode = DMM_SYMBOLIC;
			Ent->DrawOGLMarkers( OGLTransf, _OGLRdSystem, MK_MODE_POINT );
			_OGLRdSystem->DrawMarkersMode = dmm;
		}
		if ( ok && MustDrawOGLPointRelations( OGLTransf, _OGLRdSystem ) ) DrawOGLPointRelations( OGLTransf, _OGLRdSystem );
	}
}

//------------------------------------------------------------------------------

void TCadEntity::DrawOGLSelectedBox( TOGLTransf *OGLTransf )
{
	T3DRect bound;

	CalcBoundRect( OGLTransf, bound );
	_DrawOGLSelectedBox( bound );
}

//-----------------------------------------------------------------------------

void TCadEntity::DrawOGLPolygon( TOGLTransf *OGLTransf, TOGLRenderData *_OGLRdData, TOGLRenderSystem *_OGLRdSystem, bool applytexturecoords, bool recalc )
{
	int i, n;
	TOGLPolygonList **Lists;
	TOGLRenderData *ownrddata;

	ownrddata = OwnOGLRenderData ? ( &OGLRenderData ) : 0;
	Lists = 0;
	n = GetOGLViewLists( OGLTransf, &Lists, 0, recalc );
	for ( i = 0; i < n; i++ )
		Lists[ i ]->DrawOGL( OGLTransf, ownrddata, _OGLRdData, _OGLRdSystem, applytexturecoords && GetTextureMode( ) != TEXTURE_AUTO );
	if ( Lists ) delete[] Lists;
}

//------------------------------------------------------------------------------

TCadEntity *TCadEntity::GetEntityToDrawOGLMarkers( )
{
	int i;
	TCadDepShape *depshape;

	if ( DepShapes )
		for ( i = 0; i < DepShapes->Count( ); i++ ) {
			depshape = ToDepShape( DepShapes->GetShape( i ) );
			if ( !depshape ) continue;
			if ( depshape->IsMarkersDepShape( ) || depshape->IsSegmentDepShape( ) ) return 0;
		}
	return this;
}

//------------------------------------------------------------------------------

void TCadEntity::SetMarkersDepShapesDirty( bool increasedirtyid )
{
	int i;
	TCadDepShape *depshape;

	if ( increasedirtyid ) _GetNextDirtyID( );

	if ( DepShapes ) {
		for ( i = 0; i < DepShapes->Count( ); i++ ) {
			depshape = ToDepShape( DepShapes->GetShape( i ) );
			if ( !depshape ) continue;
			if ( depshape->IsMarkersDepShape( ) || depshape->IsSegmentDepShape( ) || depshape->IsPctDepShape( ) ) depshape->SetAllDirty( true, true, false );
			else if ( depshape->IsCopyDepShape( ) && depshape->GetCopyData( )->TrimByLineMarkerIndex >= 0 )
				depshape->SetAllDirty( true, true, false );
		}
	}
}

//------------------------------------------------------------------------------

void TCadEntity::ClearRenderDataTextureUV( )
{
	if ( OwnOGLRenderData && OGLRenderData.CountTextureUVCoords( ) ) OGLRenderData.ClearTextureUV( );
}

//-----------------------------------------------------------------------------

void TCadEntity::FitToRect( TOGLTransf *OGLTransf, T3DPoint min, T3DPoint max )
{
	int nulls, oldmode;
	double res, w, w2, h, h2, d, d2;
	T3DPoint m, M;
	T3DRect rr;
	T3DVector vec;
	TNMatrix matrix, matrix2;

	nulls = 0;
	res = ( IsParamEntity( ) ? RES_PARAM : RES_COMP );
	if ( fabs( max.x - min.x ) < res ) nulls++;
	if ( fabs( max.y - min.y ) < res ) nulls++;
	if ( fabs( max.z - min.z ) < res ) nulls++;
	if ( nulls >= 2 ) return;

	oldmode = OGLTransf->SetForceMode( IsParamEntity( ) ? VIEW_PARAM2D : VIEW_GEOM3D );
	if ( !CalcBoundRect( OGLTransf, rr ) ) {
		OGLTransf->SetForceMode( oldmode );
		return;
	}
	OGLTransf->SetForceMode( oldmode );

	m = rr.TopLeftFront( );
	M = rr.BottomRightBack( );

	if ( fabs( m.x - M.x ) < res ) {
		m.x -= res;
		M.x += res;
	}
	if ( fabs( m.y - M.y ) < res ) {
		m.y -= res;
		M.y += res;
	}
	if ( Dimension == dim3D )
		if ( fabs( m.z - M.z ) < res ) {
			m.z -= res;
			M.z += res;
		}

	vec = T3DVector( m, T3DPoint( 0.0, 0.0, 0.0 ) );
	matrix = TNTraslationMatrix( vec );
	w = fabs( M.x - m.x );
	if ( w < RES_COMP ) w = RES_COMP;
	h = fabs( M.y - m.y );
	if ( h < RES_COMP ) h = RES_COMP;
	d = fabs( M.z - m.z );
	if ( d < RES_COMP ) d = RES_COMP;
	w2 = fabs( max.x - min.x );
	if ( w2 < RES_COMP ) w2 = RES_COMP;
	h2 = fabs( max.y - min.y );
	if ( h2 < RES_COMP ) h2 = RES_COMP;
	d2 = fabs( max.z - min.z );
	if ( d2 < RES_COMP ) d2 = RES_COMP;
	matrix2 = TNScaleMatrix( w2 / w, h2 / h, d2 / d );
	matrix = matrix * matrix2;
	vec = T3DVector( T3DPoint( 0.0, 0.0, 0.0 ), min );
	matrix2 = TNTraslationMatrix( vec );
	matrix = matrix * matrix2;

	ApplyMatrix( OGLTransf, &matrix );
}

//------------------------------------------------------------------------------

void TCadEntity::RotatePoints( T3DPoint *Pts, const T3DPoint &center, const int np, float angle, TNPlane plane )
{
	int i;
	float aux;
	double s, c;
	TLPoint P;

	if ( IsParamEntity( ) ) plane = plXY;
	angle *= M_PI_180; // Transforma a radianes
	s = sin( angle );
	c = cos( angle );
	for ( i = 0; i < np; i++ ) {
		Pts[ i ] -= center;
		switch ( plane ) {
			case plXY:
				aux = Pts[ i ].x;
				Pts[ i ].x = Pts[ i ].x * c - Pts[ i ].y * s;
				Pts[ i ].y = aux * s + Pts[ i ].y * c;
				break;
			case plXZ:
				aux = Pts[ i ].x;
				Pts[ i ].x = Pts[ i ].x * c - Pts[ i ].z * s;
				Pts[ i ].z = aux * s + Pts[ i ].z * c;
				break;
			case plYZ:
				aux = Pts[ i ].y;
				Pts[ i ].y = Pts[ i ].y * c - Pts[ i ].z * s;
				Pts[ i ].z = aux * s + Pts[ i ].z * c;
				break;
			case plNone: break;
		}
		Pts[ i ] += center;
	}
}

//------------------------------------------------------------------------------

void TCadEntity::CreateDepShapes( )
{
	if ( DepShapes ) return;

	DepShapes = new TCadGroup( );
	DepShapes->SetDestroyList( false );
}

//------------------------------------------------------------------------------

TCadDepShape *TCadEntity::GetDepShape( int type, int index )
{
	int i, c;
	TCadDepShape *depshape;

	if ( !DepShapes ) return 0;

	c = 0;
	for ( i = 0; i < DepShapes->Count( ); i++ ) {
		depshape = ToDepShape( DepShapes->GetShape( i ) );
		if ( depshape && depshape->GetType( ) == type ) {
			if ( c == index ) return depshape;
			c++;
		}
	}
	return 0;
}

//------------------------------------------------------------------------------

int TCadEntity::GetDepShapesCount( int type )
{
	int i, count;

	if ( !DepShapes ) return 0;
	if ( type == -1 ) return DepShapes->Count( );

	for ( i = 0, count = 0; i < DepShapes->Count( ); i++ )
		if ( DepShapes->GetShape( i )->Type == type ) count++;

	return count;
}

//------------------------------------------------------------------------------

void TCadEntity::CreateDepSurfaces( )
{
	if ( DepSurfaces ) return;

	DepSurfaces = new TCadGroup( );
	DepSurfaces->SetDestroyList( false );
}

//------------------------------------------------------------------------------

void TCadEntity::CreateDepMeshes( )
{
	if ( DepMeshes ) return;

	DepMeshes = new TCadGroup( );
	DepMeshes->SetDestroyList( false );
}

//------------------------------------------------------------------------------

void TCadEntity::CreateRelatedEntities( )
{
	if ( RelatedEntities ) return;

	RelatedEntities = new TCadGroup( );
	RelatedEntities->SetDestroyList( false );
}

//------------------------------------------------------------------------------

void TCadEntity::AddEntityRelation( TEntityRelation *er )
{
	EntityRelationList.AddItem( er );
	if ( !er->BaseEntity->GetRelatedEntities( ) ) er->BaseEntity->CreateRelatedEntities( );
	er->BaseEntity->GetRelatedEntities( )->Add( this );
	//   SetAllDirty( true );
}

//------------------------------------------------------------------------------

void TCadEntity::DelEntityRelation( int index )
{
	int i;
	TEntityRelation *pr;

	if ( index < 0 || index >= EntityRelationList.Count( ) ) return;

	pr = EntityRelationList.GetItem( index );
	for ( i = 0; i < EntityRelationList.Count( ); i++ )
		if ( index != i && EntityRelationList.GetItem( i )->BaseEntity == pr->BaseEntity ) break;
	if ( i == EntityRelationList.Count( ) && pr->BaseEntity->GetRelatedEntities( ) ) pr->BaseEntity->GetRelatedEntities( )->Detach( this, NoDelete );
	if ( EntityRelationList.GetItem( index )->Type == ER_TYPE_DEPENDENT_FRAME && ToRect( this ) ) ToRect( this )->GetOGLImageTextureList( )->DelItem( 0 );
	EntityRelationList.DelItem( index );
}

//------------------------------------------------------------------------------

void TCadEntity::DelEntityRelation( TCadEntity *ent )
{
	int i;

	for ( i = 0; i < EntityRelationList.Count( ); i++ )
		if ( EntityRelationList.GetItem( i )->BaseEntity == ent ) {
			DelEntityRelation( i );
			i = -1; // para empezar de nuevo
		}
}

//------------------------------------------------------------------------------

void TCadEntity::SetVisible( bool visible )
{
	int i;
	TCadEntity *ent;

	Visible = visible;

	if ( !DepMeshes ) return;

	for ( i = 0; i < DepMeshes->Count( ); i++ ) {
		ent = DepMeshes->GetShape( i );
		if ( ent->Type == DEPMESHTYPE_BOXPLANE ) ent->SetAllDirty( true );
	}
}

//------------------------------------------------------------------------------

void TCadEntity::CalcTempParamCenter( TOGLTransf *OGLTransf )
{
	int nu, nv;
	double limitsUV[ 4 ], *upar, *vpar;
	TCadSurface *surf;

	if ( !ToShape( this ) || ToDepShape( this ) ) return;

	surf = IsParamEntity( ) ? GetParamSurface( ) : GetDualParamSurface( );
	if ( !surf ) return;

	surf->GetLimitsUV( OGLTransf, limitsUV );
	surf->GetParamsUV( OGLTransf, limitsUV, 1, 1, nu, nv, &upar, &vpar, false );
	if ( !nu ) return;

	TempParamCenter = upar[ nu / 2 ];
	if ( upar ) freearray( upar );
	if ( vpar ) freearray( vpar );
}

// Funciones globales de creacion de figuras
//------------------------------------------------------------------------------

TCadEntity *_CreateShape( UnicodeString ST )
{
	if ( ST == ST_GROUP ) return new TCadGroup( );
	if ( ST == ST_MAP ) return new TCadMap( );
	if ( ST == ST_POINT ) return new TCadPoint( );
	if ( ST == ST_EDITPLANE ) return new TCadEditPlane( );
	if ( ST == ST_MEASURE ) return new TCadMeasure( );
	if ( ST == ST_LINE ) return new TCadLine( );
	if ( ST == ST_POLYLINE ) return new TCadPolyline( );
	if ( ST == ST_BSPLINE ) return new TCadBSpline( );
	if ( ST == ST_IBSPLINE ) return new TCadIBSpline( );
	if ( ST == ST_GORDONPROFILE ) return new TCadGordonProfile( );
	if ( ST == ST_RECT ) return new TCadRect( );
	if ( ST == ST_ROUNDRECT ) return new TCadRoundRect( );
	if ( ST == ST_ELLIPSE ) return new TCadEllipse( );
	if ( ST == ST_TEXT ) return new TCadText( );
	if ( ST == ST_DEPSHAPE ) return new TCadDepShape( );
	if ( ST == ST_MESH ) return new TCadMesh( );
	if ( ST == ST_DEPMESH ) return new TCadDepMesh( );
	if ( ST == ST_SURFACE ) return new TCadSurface( );
	if ( ST == ST_LOFTEDSURFACE ) return new TCadLoftedSurface( );
	if ( ST == ST_TENSORSURFACE ) return new TCadTensorSurface( );
	if ( ST == ST_GORDONSURFACE ) return new TCadGordonSurface( );
	if ( ST == ST_DEPSURFACE ) return new TCadDepSurface( );
	if ( ST == ST_TRIMSURFACE ) return new TCadTrimSurface( );
	if ( ST == ST_TESSPOLYGON ) return new TCadTessPolygon( );
	if ( ST == ST_MEASURE ) return new TCadMeasure( );

	return 0;
}

//------------------------------------------------------------------------------

TCadEntity *_CreateShape( TCadEntity *Source, bool copyrels )
{
	TCadEntity *Aux;

	if ( !Source ) return 0;
	Aux = _CreateShape( Source->WhoAmI( ) );
	Aux->Set( Source, copyrels );
	return Aux;
}

//------------------------------------------------------------------------------

TCadEntity *_CreateBasicShape( TCadEntity *Source, bool copyrels )
{
	TCadEntity *Aux;

	if ( !Source ) return 0;

	Aux = _CreateShape( Source->WhoAmI( ) );
	Aux->SetBasic( Source, copyrels );

	return Aux;
}

//------------------------------------------------------------------------------

void TCadEntity::CopyMaterialsToPath( UnicodeString *newpath, bool force, bool checktexture, bool cancopymaxwell ) // checktexture
{
	if ( GetOwnOGLRenderData( ) ) GetOGLRenderData( )->CopyMaterialsToPath( newpath, force, checktexture, cancopymaxwell );
}

//------------------------------------------------------------------------------

void TCadEntity::UpdatePathOwnMaterials( UnicodeString *newpath )
{
	if ( GetOwnOGLRenderData( ) ) GetOGLRenderData( )->UpdatePathOwnMaterials( newpath );
}

//------------------------------------------------------------------------------

void TCadEntity::CheckPathOwnMaterials( UnicodeString *newpath, bool ) // checktexture
{
	if ( GetOwnOGLRenderData( ) ) GetOGLRenderData( )->CheckPathOwnMaterials( newpath );
}

//------------------------------------------------------------------------------

int TCadEntity::GetExpLinesListCount( TOGLTransf *OGLTransf )
{
	TOGLPolygonList *OGLList;

	if ( !OGLTransf || IsFillEntity( false ) ) return 0;

	OGLList = GetOGLGeom3D( OGLTransf );
	return ( OGLList ? OGLList->Count( ) : 0 );
}

//------------------------------------------------------------------------------

int TCadEntity::GetExpTrianglesListCount( TOGLTransf * )
{
	if ( IsFillEntity( false ) ) return 1;

	return 0;
}

//------------------------------------------------------------------------------

int TCadEntity::GetExpConesListCount( TOGLTransf * )
{
	return 0;
}

//------------------------------------------------------------------------------

int TCadEntity::GetExpSpheresListCount( )
{
	return 0;
}

//------------------------------------------------------------------------------

void TCadEntity::GetExpLinesList( TOGLTransf *OGLTransf, int index, vector<TOGLPoint> *v, vector<GLint> *vi, bool * ) // isStipple
{
	int i;
	TOGLPoint vt;
	TOGLPolygon *Pol;
	TOGLPolygonList *OGLList;

	if ( !OGLTransf || !v || !vi || IsFillEntity( false ) ) return;

	OGLList = GetOGLGeom3D( OGLTransf );
	if ( !OGLList || !OGLList->Count( ) ) return;

	if ( index < 0 || index >= OGLList->Count( ) ) return;

	Pol = OGLList->GetItem( index );
	if ( !Pol || !Pol->Count( ) ) return;

	for ( i = 0; i < Pol->Count( ); i++ ) {
		vt.Set( Pol->GetItem( i ) );
		v->insert( v->end( ), vt );
		vi->insert( vi->end( ), i );
	}
}

//------------------------------------------------------------------------------
// Ojo! Si se geometryRepair a TRUE, se puede perder la correspondencia entre la OGLList de geometria y la OGLList de textura,
// por lo que si se utiliza con esta opcion, no se utiliza la segunda lista.
void TCadEntity::GetExpTrianglesList( TOGLTransf *OGLTransf, int index, vector<TOGLPoint> *v, vector<GLint> *vi, int comparemask, bool checkdegeneratedtriangles, double prec, TOGLPolygonList *secondlist, vector<TOGLPoint> *secondv, bool geometryRepair, TOGLMaterial *matToForceCalcTexCoords )
{
	TOGLPolygonList *OGLList, OGLListOut;

	if ( !OGLTransf || index != 0 || !IsFillEntity( false ) ) return;

	OGLList = ( matToForceCalcTexCoords ? GetTextureCoords( OGLTransf, &( matToForceCalcTexCoords->Texture ) ) : GetOGL3DListByDeformMode( OGLTransf ) );

	if ( OGLList ) {
		if ( geometryRepair ) {
			_GetSMLib( )->Repair( OGLList, &OGLListOut );
			OGLListOut.GetTriangles( v, vi, comparemask, checkdegeneratedtriangles, prec, 0, 0 ); //, secondlist, secondv
		} else
			OGLList->GetTrianglesCoords( v, vi, comparemask, checkdegeneratedtriangles, prec, 0, 0, secondlist, secondv );
	}
}

//------------------------------------------------------------------------------

void TCadEntity::GetExpConesList( TOGLTransf *, int, T3DPoint &, T3DSize &, double &, double &, double & ) // TOGLTransf *OGLTransf, int index, T3DPoint pos, T3DPoint axis, double rotangle, double radius, double height )
{
	;
}

//------------------------------------------------------------------------------

void TCadEntity::GetExpSpheresList( TOGLTransf *, T3DPoint &, double & )
{
	;
}

//------------------------------------------------------------------------------

// retorna si se devuelve material especifico
bool TCadEntity::GetExpLinesListMat( TOGLTransf *, int, TOGLMaterial * )
{
	return false;
}

//------------------------------------------------------------------------------

// retorna si se devuelve material especifico
bool TCadEntity::GetExpTrianglesListMat( TOGLTransf *, int, TOGLMaterial * )
{
	return false;
}

//------------------------------------------------------------------------------

// retorna si se devuelve material especifico
bool TCadEntity::GetExpConesListMat( TOGLTransf *, int, TOGLMaterial * )
{
	return false;
}

//------------------------------------------------------------------------------

// retorna si se devuelve material especifico
bool TCadEntity::GetExpSpheresListMat( TOGLTransf *, int, TOGLMaterial * )
{
	return false;
}

//------------------------------------------------------------------------------
// se copian los datos en una lista externa

void TCadEntity::GetOGLListToDeform( TOGLTransf *OGLTransf, TOGLPolygonList *OGLListToDeform, TDeformer *def )
{
	int i, j, c, np;
	T3DPoint *pts, *incr;
	TOGLPolygonList *OGLList;

	if ( !OGLTransf || !OGLListToDeform ) return;

	OGLListToDeform->Clear( );

	OGLList = GetOGLDeformer3DList( OGLTransf );
	if ( !OGLList || !OGLList->Count( ) ) {
		OGLList = GetOGLGeom3D( OGLTransf );
		if ( !OGLList || !OGLList->Count( ) ) return;
		def = 0; // no estamos en la lista de deformacion
	}

	OGLListToDeform->Set( OGLList );
	if ( !def ) return;

	np = 0;
	if ( GetPBrepData( ) ) pts = GetPBrepData( )->GetPointsFromOGLList( OGLTransf, np, OGLList );
	else
		pts = OGLList->GetPoints( np );
	if ( np < 1 || !pts ) return;

	incr = ( def ? def->GetEntityPointIncrements( this ) : 0 );
	if ( incr )
		for ( i = 0; i < np; i++ )
			pts[ i ] -= incr[ i ]; // en este caso, se llevan los puntos al estado inicial de ese deformer

	if ( GetPBrepData( ) ) {
		//		GetPBrepData( )->SetPointsToOGLList( OGLTransf, np, pts, OGLListToDeform ); //no se recalculan las normales, si hiciera falta utilizar parámetro en esta función
		GetPBrepData( )->SetPointsToOGLList( OGLTransf, np, pts, OGLListToDeform, true );

		delete[] pts;
		return;
	}

	c = 0;
	for ( i = 0; i < OGLListToDeform->Count( ); i++ )
		for ( j = 0; j < OGLListToDeform->GetItem( i )->Count( ); j++ )
			OGLListToDeform->GetItem( i )->GetItem( j )->v.SetPoint( pts[ c++ ] );
	delete[] pts;
}

//------------------------------------------------------------------------------

bool TCadEntity::GetAllToDeform( TOGLTransf *OGLTransf, int &np, T3DPoint **points, T3DPoint **pointsuv, T3DPoint **normals, TDeformer *def )
{
	int i;
	T3DPoint *incr;
	TOGLPolygonList *OGLList;

	np = 0;
	( *points ) = 0;
	( *pointsuv ) = 0;
	( *normals ) = 0;

	if ( !GetPBrepData( ) ) return false;

	OGLList = GetOGLDeformer3DList( OGLTransf );
	if ( !OGLList || !OGLList->Count( ) ) {
		OGLList = GetOGLGeom3D( OGLTransf );
		if ( !OGLList || !OGLList->Count( ) ) return false;
		def = 0; // no estamos en la lista de deformacion
	}
	if ( !GetPBrepData( )->GetAllFromOGLList( OGLTransf, np, OGLList, points, pointsuv, normals ) ) return false;

	incr = ( def ? def->GetEntityPointIncrements( this ) : 0 );
	if ( incr )
		for ( i = 0; i < np; i++ )
			( *points )[ i ] -= incr[ i ]; // en este caso, se llevan los puntos al estado inicial de ese deformer

	incr = ( def ? def->GetEntityNormalIncrements( this ) : 0 );
	if ( incr )
		for ( i = 0; i < np; i++ )
			( *normals )[ i ] -= incr[ i ]; // en este caso, se llevan las normales al estado inicial de ese deformer

	return true;
}

//-------------------------------------------------------------------------------

T3DPoint *TCadEntity::GetPointsToDeform( TOGLTransf *OGLTransf, int &np, TDeformer *def )
{
	int i;
	T3DPoint *pts, *incr;
	TOGLPolygonList *OGLList;

	np = 0;

	OGLList = GetOGLDeformer3DList( OGLTransf );
	if ( !OGLList || !OGLList->Count( ) ) {
		OGLList = GetOGLGeom3D( OGLTransf );
		if ( !OGLList || !OGLList->Count( ) ) return 0;
		def = 0; // no estamos en la lista de deformacion
	}
	if ( GetPBrepData( ) ) pts = GetPBrepData( )->GetPointsFromOGLList( OGLTransf, np, OGLList );
	else
		pts = OGLList->GetPoints( np );

	incr = ( def ? def->GetEntityPointIncrements( this ) : 0 );
	if ( incr ) {
		for ( i = 0; i < np; i++ )
			pts[ i ] -= incr[ i ]; // en este caso, se llevan los puntos al estado inicial de ese deformer
	}
	return pts;
}

//------------------------------------------------------------------------------

T3DPoint *TCadEntity::GetPointsUVToDeform( TOGLTransf *OGLTransf, int &np )
{
	TOGLPolygonList *OGLList;

	np = 0;

	OGLList = GetOGLDeformer3DList( OGLTransf );
	if ( !OGLList || !OGLList->Count( ) ) {
		OGLList = GetOGLGeom3D( OGLTransf );
		if ( !OGLList || !OGLList->Count( ) ) return 0;
	}
	if ( GetPBrepData( ) ) return GetPBrepData( )->GetPointsUVFromOGLList( OGLTransf, np, OGLList );

	return OGLList->GetPointsUV( np );
}

//------------------------------------------------------------------------------

int TCadEntity::CountPointsToDeform( TOGLTransf *OGLTransf )
{
	if ( GetPBrepData( ) ) return GetPBrepData( )->CountPBrepVertexs( OGLTransf );
	return GetOGLGeom3D( OGLTransf )->ReadPolNumVertexs( );
}

//------------------------------------------------------------------------------

void TCadEntity::SetDeformedPoints( TOGLTransf *OGLTransf, int np, T3DPoint *points, bool locknormals )
{
	int i, j, c;

	if ( np < 1 || !points ) return;

	if ( debug ) {
		WritePoints( L"c:\\temp\\pointsDeformed.asc", L"w", points, np );
	}

	if ( GetPBrepData( ) ) {
		if ( (int) GetPBrepData( )->CountPBrepVertexs( OGLTransf ) != np ) return;
		GetPBrepData( )->SetPointsToOGLList( OGLTransf, np, points, GetOGLDeformer3DList( OGLTransf, true ), locknormals );
		if ( debug ) {
			WriteSections( L"c:\\temp\\deformed3dList.asc", L"w", GetOGLDeformer3DList( OGLTransf, true ) );
		}

		return;
	}

	if ( np != GetOGLDeformer3DList( OGLTransf, true )->ReadPolNumVertexs( ) ) return;

	c = 0;
	for ( i = 0; i < OGLDeformer3DList->Count( ); i++ )
		for ( j = 0; j < OGLDeformer3DList->GetItem( i )->Count( ); j++ )
			OGLDeformer3DList->GetItem( i )->GetItem( j )->v.SetPoint( points[ c++ ] );

	OGLDeformer3DList->Download( );
	//	if ( RemeshData.Apply )
	AppliedRemesh = false;

	if ( debug ) {
		WriteSections( L"c:\\temp\\deformed3dList.asc", L"w", GetOGLDeformer3DList( OGLTransf, true ) );
	}
}

//------------------------------------------------------------------------------

T3DPoint *TCadEntity::GetNormalsToDeform( TOGLTransf *OGLTransf, int &np, TDeformer *def )
{
	int i;
	T3DPoint *pts, *incr;
	TOGLPolygonList *OGLList;

	np = 0;

	OGLList = GetOGLDeformer3DList( OGLTransf );
	if ( !OGLList || !OGLList->Count( ) ) {
		OGLList = GetOGLGeom3D( OGLTransf );
		if ( !OGLList || !OGLList->Count( ) ) return 0;
		def = 0; // no estamos en la lista de deformacion
	}
	if ( GetPBrepData( ) ) pts = GetPBrepData( )->GetNormalsFromOGLList( OGLTransf, np, OGLList );
	else
		pts = OGLList->GetNormals( np );

	incr = ( def ? def->GetEntityNormalIncrements( this ) : 0 );
	if ( incr ) {
		for ( i = 0; i < np; i++ )
			pts[ i ] -= incr[ i ]; // en este caso, se llevan los puntos al estado inicial de ese deformer
	}
	return pts;
}

//------------------------------------------------------------------------------

void TCadEntity::SetDeformedNormals( TOGLTransf *OGLTransf, int np, T3DPoint *points )
{
	int i, j, c;

	if ( np < 1 || !points ) return;

	if ( GetPBrepData( ) ) {
		if ( (int) GetPBrepData( )->CountPBrepVertexs( OGLTransf ) != np ) return;
		GetPBrepData( )->SetNormalsToOGLList( OGLTransf, np, points, GetOGLDeformer3DList( OGLTransf, true ) );
		return;
	}

	if ( np != GetOGLDeformer3DList( OGLTransf, true )->ReadPolNumVertexs( ) ) return;

	c = 0;
	for ( i = 0; i < OGLDeformer3DList->Count( ); i++ )
		for ( j = 0; j < OGLDeformer3DList->GetItem( i )->Count( ); j++ )
			OGLDeformer3DList->GetItem( i )->GetItem( j )->n.SetPoint( points[ c++ ] );

	OGLDeformer3DList->Download( );
}

//------------------------------------------------------------------------------

T3DPoint *TCadEntity::GetTextureCoordsToDeform( TOGLTransf *OGLTransf, int &np )
{
	TOGLPolygonList *OGLList;

	np = 0;

	OGLList = GetOGLDeformer3DList( OGLTransf );
	if ( !OGLList || !OGLList->Count( ) ) {
		OGLList = GetOGLGeom3D( OGLTransf );
		if ( !OGLList || !OGLList->Count( ) ) return 0;
	}
	if ( GetPBrepData( ) ) return GetPBrepData( )->GetTextureCoordsFromOGLList( OGLTransf, np, OGLList );

	return OGLList->GetTextureCoords( np );
}

//------------------------------------------------------------------------------

void TCadEntity::UpdateDeformed3DListTextureCoords( TOGLTransf *OGLTransf )
{
	int i, j;
	TOGLPolygonList *orgList, *defList;

	orgList = GetOGLList( OGLTransf );
	defList = GetOGLDeformer3DList( OGLTransf );
	if ( !orgList || !defList || orgList->Count( ) != defList->Count( ) ) return;

	for ( i = 0; i < orgList->Count( ); i++ ) {
		for ( j = 0; j < orgList->GetItem( i )->Count( ); j++ ) {
			defList->GetItem( i )->GetItem( j )->t.Set( &( orgList->GetItem( i )->GetItem( j )->t ) );
			defList->GetItem( i )->GetItem( j )->uv.Set( &( orgList->GetItem( i )->GetItem( j )->uv ) );
		}
	}
	defList->Download( );
	SetDeformerTextureDirty( false );
}

//------------------------------------------------------------------------------
// Almacena la posicion geometrica de los pointmarkers de las entidades poly dependientes con elementos de los tipos definidos
// group debe llegar vacio y con DestroyList a false

void TCadEntity::CalcMarkerListsPoints( TOGLTransf *OGLTransf, bool isparam, TInteger_List *forcetypes, bool checkextremes, TCadGroup *group, bool forcedev )
{
	bool valid;
	int i;
	TCadGroup auxgroup;
	TCadShape *shape;
	TCadDepShape *polyshape;

	if ( !OGLTransf || !group ) return;

	auxgroup.SetDestroyList( false );

	GetDownRelatedEntities( OGLTransf, &auxgroup );
	for ( i = auxgroup.Count( ) - 1; i >= 0; i-- ) {
		shape = ToShape( auxgroup.GetShape( i ) );
		polyshape = ToDepShape( auxgroup.GetShape( i ) );
		valid = ( shape && !polyshape && ( shape->PointMarkersCount( PM_TYPE_GRADING2D ) || shape->PointMarkersCount( PM_TYPE_GRADING2D_SMOOTH ) ) );
		if ( !valid ) {
			valid = ( polyshape && polyshape->IsPolyDepShape( ) && polyshape->GetShapeElementsCount( forcetypes ) );
			if ( !valid ) {
				auxgroup.Detach( i, NoDelete );
				continue;
			}
		}

		if ( group->IsEntityIncluded( shape, false ) ) {
			auxgroup.Detach( i, NoDelete );
			continue;
		}
	}
	for ( i = 0; i < auxgroup.Count( ); i++ )
		group->Add( auxgroup.GetShape( i ) );

	auxgroup.CalcMarkerListsPoints( OGLTransf, isparam, forcetypes, checkextremes, forcedev );
}

//------------------------------------------------------------------------------

//#include "cxProgressBar.hpp"
void TCadEntity::DoRemesh( TOGLTransf *OGLTransf, QRLib_RemeshSettings *settings, TCadGroup *curvesGroup, int curvesType, bool remesh, bool updatetextcoords, bool calcseams, bool keeporgpols )
{
	QuadRemesher *qr;

	qr = new QuadRemesher( OGLTransf, this, settings, updatetextcoords, calcseams, keeporgpols );
	qr->Remesh( curvesGroup, curvesType, remesh, 0 );
	delete qr;
}

//------------------------------------------------------------------------------

TRemeshData *TCadEntity::GetRemeshData( )
{
	return &RemeshData;
}

//------------------------------------------------------------------------------

void TCadEntity::SetRemeshData( TRemeshData *data )
{
	RemeshData.Set( data );
}

//------------------------------------------------------------------------------

bool TCadEntity::GetAppliedRemesh( )
{
	return AppliedRemesh;
}

//------------------------------------------------------------------------------

void TCadEntity::SetAppliedRemesh( bool value )
{
	if ( value == AppliedRemesh ) return;

	AppliedRemesh = value;
}

//------------------------------------------------------------------------------

