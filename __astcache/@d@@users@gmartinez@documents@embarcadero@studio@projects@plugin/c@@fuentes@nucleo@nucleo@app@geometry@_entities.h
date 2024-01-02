#ifndef SHAPES_H
#define SHAPES_H

#include <values.h>
#include <vector>
#include <map>
#include <algorithm>

#include "_defines.h"
#include "_layers.h"
#include "developdata.h"
#include "markers.h"
#include "entitydata.h"

// Defines de tipos de entidad en _defines.h
/*

ShEntity,
		 ShGroup, ShMap, ShText,
			 ShShape, ShPoint,
				  ShEditPlane,
						 ShMeasure,
						 ShLine, ShPolyline, ShBSpline, ShIBSpline, ShGordonProfile
												   ShRectangle, ShRoundRect,
																	 ShPuller,
																	 ShEllipse,
																	 ShText,
						 ShDepShape,
			 ShMesh,  ShDepMesh,
		 ShSurface, 	ShLoftedSurface,
							 ShTensorSurface,
							 ShGordonSurface,
							 ShDepSurface,
		 ShTrimSurface,
			 ShTessPolygon,
 */

//------------------------------------------------------------------------------

class TCadPoint;
class TCadGroup;
class TCadPolyline;
class TCadDepShape;
class TCadDepMesh;
class TCadSurface;
class TCadTrimSurface;
class TCameraMXS;
class TDeformer;
class TCadText;
class TOGLTransf;
class TMaterialConfiguratorGroup;
class TPBrepData;
class QRLib_RemeshSettings;

//------------------------------------------------------------------------------
// TCadEntity
//------------------------------------------------------------------------------

class TCadEntity
{
	friend class TCadGroup;
	friend class TCadDepShape;
	friend class TImpExp_XML;
	friend class TPBrepData;

  protected:
	int ID;
	int Version;
	UnicodeString Description;

	UnicodeString TempName;		 // Variable auxiliar utilizada en la lectura y escritura de ficheros. Se ha optado por poner la variable aqui porque si la introdujeramos en la tabla en la que guardamos los IDs tendriamos una fila por cada entidad leida lo que podria llevar a gestionar tablas inmensas en memoria y por lo tanto el agotamiento de este recurso en la maquina.
	UnicodeString TempLayerName; // Variable auxiliar utilizada en la lectura y escritura de ficheros. Se ha optado por poner la variable aqui porque si la introdujeramos en la tabla en la que guardamos los IDs tendriamos una fila por cada entidad leida lo que podria llevar a gestionar tablas inmensas en memoria y por lo tanto el agotamiento de este recurso en la maquina.
	int TempLayerPos;
	TUnicodeStringList TempNameToRestoreList;
	int TempIntValue;

	TDimension Dimension;
	HLAYER Layer;
	int Type;
	int IntValue;
	bool Visible;

	double OGLParam_1_Tol;
	TCadSurface *ParamSurface;
	int ParamInterpolationMode;
	double ParamOffset;

	int SISLDirtyID;
	int PolygonDirtyID;
	int Geom3DDirtyID;
	int Develop2DDirtyID;
	int ForceDevSurfsDirtyID;

	bool IsSISLDirty;
	bool IsPolygonDirty;
	bool IsGeom3DDirty;
	bool IsDevelop2DDirty;
	bool IsExternalDirty;	  // Dirty equivalente al PolygonDirty pero eliminado desde fuera de la entidad
	bool IsDeformer3DDirty;	  // Dirty de la lista OGLDeformer3DList.
	bool IsDeformerDataDirty; // Dirty de los datos para la deformacion de esta entidad almacenados en TDeformerList

	bool LockRecalc;
	bool LockSISLDirty;
	bool LockPolygonDirty;
	bool LockNormals;

	bool ConvertToTriangles;

	TOGLPolygonList OGLPolygonList;
	TOGLPolygonList OGLGeom3DList;
	TOGLPolygonList OGLDevelop2DList;
	TOGLPolygonList *OGLDeformer3DList;

	TPBrepData *PBrepData;
	bool IsPBrepDirty;
	bool PBrepTrianglesForced;

	bool Developable;
	int DevelopSurfIndex;		// Indice de la superficie dentro del desarrollo anterior.
	bool ForceDevelopSurfIndex; // Indica si el DevelopSurfIndex es unico o define prioridad.

	bool OwnOGLRenderData;
	TOGLRenderData OGLRenderData;
	bool IsTextureDirty;
	bool IsDeformerTextureDirty;
	TOGLTextureDataList OGLTextureDataList;

	double TempParamCenter;

	TMaxwellObjectData MaxwellObjectData;

	TMaterialConfiguratorGroup *MaterialConfiguratorGroup;

	TEntityRelationList EntityRelationList;
	TCadGroup *RelatedEntities;
	TCadGroup *DepShapes;
	TCadGroup *DepSurfaces;
	TCadGroup *DepMeshes;

	TPivotData *Pivot;

	virtual bool CalcSISL( TOGLTransf * )
	{
		return true;
	}

	virtual bool CalcOGLLists( TOGLTransf * );
	virtual bool CalcOGLPolygon( TOGLTransf * )
	{
		return false;
	}
	virtual bool CalcOGLParam2D( TOGLTransf * );
	virtual bool CalcOGLGeom3D( TOGLTransf * );
	virtual bool CalcOGLDevelop2D( TOGLTransf * );
	virtual bool CalcOGLGeom3DFromParam2D( TOGLTransf * );
	virtual bool CalcOGLDevelop2DFromParam2D( TOGLTransf *OGLTransf );
	virtual bool CalcOGLParam2DFromGeom3D( TOGLTransf * );
	virtual bool CalcOGLParam2DFromGeom3D_CT( TOGLTransf * );
	virtual bool CalcOGLParam2DFromDevelop2D( TOGLTransf * );
	virtual bool CalcTextureListCoords( TOGLTransf *, TOGLRenderData * );
	virtual bool CalcTextureCoords( TOGLTransf *, TOGLTexture * );
	virtual bool CalcBaseTextureCoords( TOGLTransf *, TOGLPolygonList *, int index = -1 );
	virtual bool CalcEndTextureCoords( TOGLTransf *, TOGLTexture * );

  public:
	TCadEntity( );
	TCadEntity( TCadEntity * );
	virtual ~TCadEntity( );
	virtual void Set( TCadEntity *, bool copyrels );
	virtual void SetBasic( TCadEntity *, bool copyrels );
	virtual void SetBasicRels( TCadEntity *S );
	virtual void ChangeBasicRels( TCadEntity *orgbaseent, TCadEntity *dstbaseent, bool updatedirty = true, bool setdirty = false );
	virtual void GetBasicRelsEnts( TCadGroup *grp, bool usesurf = true, bool usemainaxissurf = true );

	virtual bool MustCalcOGLLists( TOGLRenderSystem * );
	virtual TOGLPolygonList *GetOGLList( TOGLTransf *, bool = true );
	virtual TOGLPolygonList *GetOGLParam2D( TOGLTransf *, bool = true );
	virtual TOGLPolygonList *GetOGLGeom3D( TOGLTransf *, bool = true, bool force = false );
	virtual TOGLPolygonList *GetOGLDevelop2D( TOGLTransf *, bool = true );
	virtual TOGLPolygonList *GetOGLGeom3DParam2D( TOGLTransf *, TOGLPolygonList *, bool recalc = true );
	virtual void GetOGLParam2DDevelop2D( TOGLTransf *, TOGLPolygonList *, TOGLPolygonList * );
	virtual TOGLPolygonList *GetOGLGeom3DParam2DDevelop2D( TOGLTransf *OGLTransf, TOGLPolygonList *ListPar, TOGLPolygonList *ListDev, bool recalc = true );
	virtual TOGLPolygonList *GetTextureCoords( TOGLTransf *, TOGLTexture *, bool forcedeform = false );
	virtual void GetBaseTextureCoords( TOGLTransf *, TOGLPolygonList *, int index = -1 );

	// Deformer functions
	virtual TOGLPolygonList *GetOGL3DListByDeformMode( TOGLTransf *OGLTransf );
	virtual TOGLPolygonList *GetOGLDeformer3DList( TOGLTransf *OGLTransf = 0, bool force = false );
	virtual void SetOGLDeformer3DList( TOGLPolygonList *list );
	virtual void CreateOGLDeformer3DList( TOGLTransf *OGLTransf = 0 );
	virtual void ClearOGLDeformer3DList( );

	virtual int CountPointsToDeform( TOGLTransf *OGLTransf );
	virtual bool GetAllToDeform( TOGLTransf *OGLTransf, int &np, T3DPoint **points, T3DPoint **pointsuv, T3DPoint **normals, TDeformer *def = 0 );
	virtual T3DPoint *GetPointsToDeform( TOGLTransf *OGLTransf, int &np, TDeformer *def = 0 );
	virtual T3DPoint *GetPointsUVToDeform( TOGLTransf *OGLTransf, int &np );
	virtual T3DPoint *GetNormalsToDeform( TOGLTransf *OGLTransf, int &np, TDeformer *def = 0 );
	virtual T3DPoint *GetTextureCoordsToDeform( TOGLTransf *OGLTransf, int &np );
	virtual void SetDeformedPoints( TOGLTransf *OGLTransf, int np, T3DPoint *def_points, bool locknormals = false );
	virtual void SetDeformedNormals( TOGLTransf *OGLTransf, int np, T3DPoint *def_points );

	virtual void GetOGLListToDeform( TOGLTransf *OGLTransf, TOGLPolygonList *OGLList, TDeformer *def = 0 );

	virtual void UpdateDeformed3DListTextureCoords( TOGLTransf *OGLTransf );
	// End Deformer functions

	IwPolyBrep *GetPBrep( TOGLTransf *OGLTransf, bool force = true );
	virtual TPBrepData *GetPBrepData( bool force = true );
	virtual void SetPBrepData( TOGLTransf *OGLTransf, TPBrepData *pBrepData );
	virtual void CreatePBrep( TOGLTransf *OGLTransf, bool force = true, bool forcecheckpbrep = false );
	virtual void ClearPBrepData( );
	virtual void UpdateOGLListFromPBrep( TOGLTransf *OGLTransf, bool checkSelected = false, bool calculateNormals = false, bool updatetexcoords = false, bool recalcTopology = false );
	virtual void UpdateNormalsOGLListFromPBrep( TOGLTransf *OGLTransf, bool onlyinvalids = false );
	virtual void UpdateColorsFromPBrep( TOGLTransf *OGLTransf, TColor *cIni, TColor *cEnd );
	virtual void UpdateNormalsFromPBrep( TOGLTransf *OGLTransf );

	virtual bool HasOGLList( TOGLTransf * );
	virtual int GetNumberOGLViewLists( TOGLTransf *, bool recalc = true );
	virtual int GetOGLViewLists( TOGLTransf *, TOGLPolygonList ***Lists, int index = 0, bool = true );
	virtual bool IsRightViewMode( TOGLTransf * );

	virtual void GetOGLDualGeom2DOrDevelop2D( TOGLTransf *, TOGLPolygonList *, bool clear = true, bool recalc = true, bool forcerevertseconddevsurfindex = false, bool joinpolygons = true );
	virtual bool GetUniqueOGLDualGeom2DOrDevelop2D( TOGLTransf *, TOGLPolygonList *, bool tessortrimclose = false )
	{
		return false;
	}
	virtual bool GetUniqueOGLDualParam2D( TOGLTransf *, TOGLPolygonList *, bool tessortrimclose = false )
	{
		return false;
	}

	virtual int GetWorkingViewMode( );

	virtual TCadEntity *GetDualBaseEntity( )
	{
		return this;
	}
	virtual TCadShape *GetDualShapeByDep( )
	{
		return 0;
	}
	virtual TCadDepShape *GetDualDepShape( )
	{
		return 0;
	}
	virtual TCadShape *GetDualParamShapeByDep( )
	{
		return 0;
	}
	virtual TCadShape *GetDualGeomShapeByDep( )
	{
		return 0;
	}
	virtual TCadSurface *GetBaseSurface( );
	virtual TCadSurface *GetParamSurface( )
	{
		return ParamSurface;
	}
	virtual void SetParamSurface( TCadSurface *s, bool onlyset = false );
	virtual TCadSurface *GetDualParamSurface( )
	{
		return ParamSurface;
	}
	virtual TCadSurface *GetDualBaseSurface( );
	virtual int GetParamInterpolationMode( )
	{
		return ParamInterpolationMode;
	}
	virtual void SetParamInterpolationMode( int );
	virtual double GetParamOffset( )
	{
		return ParamOffset;
	}
	virtual void SetParamOffset( double d );
	virtual double GetDualParamOffset( )
	{
		return ParamOffset;
	}
	virtual double GetOGLParam_1_Tol( )
	{
		return OGLParam_1_Tol;
	}
	virtual void SetOGLParam_1_Tol( double tol );
	virtual void SetParamEntity( TCadSurface *, int mode, double offset = PARAM_OFFSET_DEFAULT );
	virtual bool IsParamEntity( )
	{
		return ( ParamSurface != 0 );
	}
	virtual bool HasParamEntity( )
	{
		return ( ParamSurface != 0 );
	}
	virtual T3DPoint GetPointByView( TOGLTransf *OGLTransf, int view, T3DPoint auxpt, int *devsurfindex = 0 );
	virtual bool RestorePointByView( TOGLTransf *OGLTransf, int view, T3DPoint auxpt, T3DPoint oldpt, T3DPoint &pt );
	virtual T3DPoint SetParamPoint( TOGLTransf *OGLTransf, T3DPoint auxpt );
	virtual bool RestoreParamPoint( TOGLTransf *OGLTransf, T3DPoint auxpt, T3DPoint oldpt, T3DPoint &out );
	virtual TCadEntity *GetNewGeomEntity( TOGLTransf *OGLTransf )
	{
		return 0;
	}
	virtual TCadEntity *GetNewGeomEntityFromDevelop( TOGLTransf *OGLTransf )
	{
		return 0;
	}

	virtual void CalcTempParamCenter( TOGLTransf * );
	virtual void SetTempParamCenter( double pc )
	{
		TempParamCenter = pc;
	}
	virtual double GetTempParamCenter( )
	{
		return TempParamCenter;
	}
	virtual bool HasTempParamCenter( )
	{
		return TempParamCenter >= 0;
	}

	virtual bool ChangeParamSurface( TOGLTransf *, TCadSurface *ParamSurfDest )
	{
		return false;
	}
	virtual void MoveParamCenter( TOGLTransf *OGLTransf, double *limitsUV, TLPoint orgcenter, TLPoint dstcenter )
	{
	}

	virtual void CleanGroups( );
	virtual void GetDownRelatedEntities( TOGLTransf *OGLTransf, TCadGroup *Group, HLAYER *excludelayer = 0, bool force = false );
	virtual void GetUpRelatedEntities( TCadGroup *Group, bool rels = true, bool pointRels = true );
	virtual bool HasUpRelatedEntities( bool rels = true, bool pointRels = true, bool excludeparamsurf = false );
	virtual void DetachUpRelations( TCadGroup *, TPointRelationList *, TEntityRelationList *, bool updatedirty = true );
	virtual void ChangeOwnRelatedEntity( TCadEntity *ent );
	virtual void ChangeOwnRelatedShape2D( TCadShape *ent );
	virtual void ChangeRelatedEntity( TCadEntity *orgent, TCadEntity *dstent, TCadGroup *gr = 0, bool setdirty = false );
	virtual void ClearOwnRelations( );

	virtual TEntityRelationList *GetEntityRelationList( )
	{
		return &EntityRelationList;
	}
	virtual void AddEntityRelation( TEntityRelation *er );
	virtual void DelEntityRelation( int index );
	virtual void DelEntityRelation( TCadEntity *ent );
	virtual void CreateRelatedEntities( );
	virtual TCadGroup *GetRelatedEntities( )
	{
		return RelatedEntities;
	}

	virtual void CreateDepShapes( );
	virtual TCadGroup *GetDepShapes( )
	{
		return DepShapes;
	}
	virtual TCadDepShape *GetDepShape( int type, int index = 0 );
	virtual int GetDepShapesCount( int type = -1 );
	virtual void CreateDepSurfaces( );
	virtual TCadGroup *GetDepSurfaces( )
	{
		return DepSurfaces;
	}
	virtual void CreateDepMeshes( );
	virtual TCadGroup *GetDepMeshes( )
	{
		return DepMeshes;
	}

	virtual bool MustRevertEntity( TOGLTransf *OGLTransf )
	{
		return false;
	}

	virtual bool IsHidden( bool checkvisible = true );
	virtual bool IsEditable( )
	{
		return true;
	}
	virtual bool IsDevelopable( );
	virtual bool IsDualDevelopable( )
	{
		return IsDevelopable( );
	}
	virtual bool IsInactive( TOGLTransf * );
	virtual bool IsIndependent( bool checkpointrels = true );
	virtual bool HasEntityRelation( int type, int *index = 0 );
	virtual int GetEntityRelationEntities( TCadGroup *ents, int reltype, int enttype = 0 );
	virtual void SetDevelopable( bool dev );
	virtual bool CanApplyTransform( bool checkpointrels = true );
	virtual bool CanConvertTo( TOGLTransf *, int type )
	{
		return false;
	}

	virtual bool IsInPlane( TOGLTransf *, T3DPlane &, double prec = RES_GEOM )
	{
		return false;
	}
	virtual bool IsInPlane( TNPlane )
	{
		return false;
	}

	virtual bool IsPeriodicDataValid( TOGLTransf * )
	{
		return true;
	}
	virtual bool SetRangeOGLParam2D( TOGLTransf *, bool inrange );

	virtual bool NormSISLCurveInSurface( TOGLTransf *, double *, double *, double *, TCadSurface * = 0 )
	{
		return false;
	}
	virtual bool NormSISLCurveInLimitsUV( TOGLTransf *OGLTransf, bool *close, double *limitsUV )
	{
		return false;
	}

	virtual void SetAllDirty( bool b, bool sisl = true, bool increasedirtyid = true );
	virtual void SetSISLDirty( bool b, bool increasedirtyid = true );
	virtual void SetPolygonDirty( bool b, bool increasedirtyid = true );
	virtual void SetGeom3DDirty( bool b, bool increasedirtyid = true );
	virtual void SetDevelop2DDirty( bool b, bool increasedirtyid = true );
	virtual void SetMarkersDepShapesDirty( bool increasedirtyid = true );
	virtual bool GetPolygonDirty( );
	virtual bool GetExternalDirty( );
	virtual void SetExternalDirty( bool b );
	virtual bool GetPBrepDirty( );
	virtual void SetPBrepDirty( bool b );
	virtual bool GetPBrepTrianglesForced( );
	virtual void SetPBrepTrianglesForced( bool b );
	virtual bool GetDeformer3DDirty( );
	virtual void SetDeformer3DDirty( bool b );
	virtual bool GetDeformerDataDirty( );
	virtual void SetDeformerDataDirty( bool b );
	virtual bool GetDeformerTextureDirty( );
	virtual void SetDeformerTextureDirty( bool b );
	virtual void ForceDevSurfsDirty( int, int = -1, bool increasedirtyid = true )
	{
	}

	virtual bool GetLockRecalc( )
	{
		return LockRecalc;
	}
	virtual void SetLockRecalc( bool b );
	virtual bool GetLockNormals( );
	virtual void SetLockNormals( bool b );

	virtual bool GetConvertToTriangles( );
	virtual void SetConvertToTriangles( bool b );

	virtual bool GetLockUpdateData( )
	{
		return false;
	}
	virtual void SetLockUpdateData( TOGLTransf *, bool, bool onlyset = false )
	{
	}

	virtual bool AddDevelopIndex( )
	{
		return false;
	}
	virtual bool DeleteDevelopIndex( int )
	{
		return false;
	}
	virtual bool SetCurrentDevelopIndex( int )
	{
		return false;
	}

	virtual void GetLimitsUV( TOGLTransf *, double *limits = 0 );
	virtual TCadPolyline *GetCurveUV( TOGLTransf *, double *limits = 0, bool inflate = true, TCadEntity *orgent = 0 );
	virtual void GetExtremeCurves( TOGLTransf *OGLTransf, TCadGroup *group, TCadSurface *_surf = 0, double *LimitsUV = 0, bool *_close = 0, bool inflate = 0, double res = 0.5 );

	virtual void GetDevelopLimitsUV( TOGLTransf *, int i, double *limits )
	{
	}
	virtual bool GetDevelopDataLimitsUV( TOGLTransf *, TCadSurface *surf, double *limitsUV, double *devdatalimits )
	{
		return false;
	}
	virtual int GetUCloseExt( TOGLTransf * )
	{
		return ENT_OPEN;
	}
	virtual int GetVCloseExt( TOGLTransf * )
	{
		return ENT_OPEN;
	}

	virtual TCadGroup *GetTransfDevelopSurfaces( TOGLTransf *, int devindex = -1 )
	{
		return 0;
	}
	virtual TCadSurface *GetTransfDevelopSurfIndexSurface( TOGLTransf *, int devindex = -1 );
	virtual TOGLPolygonList *GetTransfDevelopSurfacesEdges( TOGLTransf *OGLTransf, int devindex = -1 )
	{
		return 0;
	}
	virtual TDevelopList *GetDevelopList( )
	{
		return 0;
	}
	virtual void SetDevelopList( TOGLTransf *, TDevelopList *, bool del = true, bool copy = true, bool checkindexes = true )
	{
	} // ruben
	virtual int GetDevelopSurfIndex( )
	{
		return DevelopSurfIndex;
	}
	virtual int GetDevelopSurfIndexByPoint( TOGLTransf *OGLTransf, T3DPoint pt );
	virtual void SetDevelopSurfIndex( int );
	virtual int GetDualDevelopSurfIndex( )
	{
		return DevelopSurfIndex;
	}
	virtual bool CalcDevelopSurfIndex( TOGLTransf * );
	virtual bool GetForceDevelopSurfIndex( )
	{
		return ForceDevelopSurfIndex;
	}
	virtual void SetForceDevelopSurfIndex( bool );
	virtual bool GetDualForceDevelopSurfIndex( )
	{
		return ForceDevelopSurfIndex;
	}
	virtual bool HasDevelopData( )
	{
		return false;
	}
	virtual bool HasDevelop( )
	{
		return false;
	}

	virtual bool GetTextureDirty( )
	{
		return IsTextureDirty;
	}
	virtual void SetTextureDirty( bool );
	virtual void SetOGLTextureDataList( TOGLTextureDataList *, bool force = false );
	virtual TOGLTextureDataList *GetOGLTextureDataList( bool force = false );
	virtual TOGLTextureData *GetOGLTextureData( int index = -1 );
	virtual void SetOGLTextureData( TOGLTextureData *, int index = -1 );
	virtual int GetTextureMode( )
	{
		return GetOGLTextureData( )->TextureMode;
	}
	virtual void SetTextureMode( int mode, bool applyAll = true );
	virtual void ClearRenderDataTextureUV( );

	virtual bool CalcBoundRect( TOGLTransf *, T3DRect &, bool outrange = false, TNMatrix *mat = 0 );
	virtual bool CalcBoundRectParam( TOGLTransf *, T3DRect &, bool outrange = false, TNMatrix *mat = 0 );
	virtual bool GetBoundRectInPlane( TOGLTransf *, TLRect & );
	virtual bool CalcBoundRectViewport( TOGLTransf *, TLRect &, int step = 1, TNMatrix *MirrorMat = 0, TInstanceList *list = 0 );
	virtual bool DataBoundRect( TOGLTransf *, T3DRect &r, TNMatrix *mat = 0 )
	{
		r = T3DRect( 0, 0, 0, 0, 0, 0 );
		return false;
	}

	virtual int Count( )
	{
		return 0;
	}
	virtual T3DPoint Size( TOGLTransf * );
	virtual T3DPoint SizeSegment( TOGLTransf *OGLTransf, int, int )
	{
		return Size( OGLTransf );
	}
	virtual bool GravityCenter( TOGLTransf *, T3DPoint &pt );
	virtual bool GravityCenter( TOGLTransf *OGLTransf, T3DPoint &pt, double inc );
	virtual float Perimeter( TOGLTransf * )
	{
		return 0.0;
	}
	virtual float PerimeterSegment( TOGLTransf *OGLTransf, int ind1, int ind2 )
	{
		return 0.0;
	}
	virtual float PerimeterSegment( TOGLTransf *OGLTransf, double param1, double param2 )
	{
		return 0.0;
	}
	virtual float Area( TOGLTransf * )
	{
		return 0.0;
	}
	virtual float Volume( TOGLTransf *, bool force = false )
	{
		return 0.0;
	}
	virtual bool IsValid( TOGLTransf * );
	virtual void GetShapeInfo( TOGLTransf *, TShapeInfo * );
	virtual void GetSegmentInfo( TOGLTransf *OGLTransf, TShapeInfo *si, int ind1, int ind2 )
	{
	}

	virtual void ClearOGLLists( );
	virtual void Download_glList( );
	virtual void Download( );
	virtual void SetID( int id, bool download = true );
	virtual void ClearID( );
	virtual int GetID( )
	{
		return ID;
	}
	virtual int GetDualID( )
	{
		return ID;
	}
	virtual int GetMaxId( )
	{
		return ID;
	}
	virtual void ReplaceID( int oldid, int newid );
	virtual void ReplaceID( TInteger_List *oldids, TInteger_List *newids );
	virtual bool IsIDIncluded( int id )
	{
		return ( ID == id );
	}

	virtual int GetVersion( );
	virtual void SetVersion( int value );

	virtual bool IsEntityIncluded( TCadEntity *entity, bool recursive = true );
	virtual int GetEntityIndex( TCadEntity *entity, bool recursive = true, int *curindex = 0 ); // nunca poner valor curindex desde fuera
	virtual TCadEntity *GetEntityByIndex( int index, int *curindex = 0 );						// nunca poner valor curindex desde fuera
	virtual void AddEntitiesToGroup( TCadGroup *Grp, bool ForceNoCopy = false );

	virtual void SetLayer( HLAYER l )
	{
		Layer = l;
	}
	virtual HLAYER GetLayer( )
	{
		return Layer;
	}

	virtual void SetDimension( TDimension d )
	{
		Dimension = d;
		SetAllDirty( true );
	}
	virtual TDimension GetDimension( )
	{
		return Dimension;
	}

	virtual int GetType( )
	{
		return Type;
	}
	virtual void SetType( int type )
	{
		Type = type;
	}

	virtual void SetVisible( bool b );
	virtual bool IsVisible( )
	{
		return Visible;
	}

	virtual void SetOwnOGLRenderData( bool o );
	virtual bool GetOwnOGLRenderData( )
	{
		return OwnOGLRenderData;
	}
	virtual void SetOGLRenderData( TOGLRenderData *oglrddata );
	virtual TOGLRenderData *GetOGLRenderData( )
	{
		return &OGLRenderData;
	}

	virtual TMaxwellObjectData *GetMaxwellObjectData( )
	{
		return &MaxwellObjectData;
	}

	virtual TMaterialConfiguratorGroup *GetMaterialConfiguratorGroup( )
	{
		return MaterialConfiguratorGroup;
	}
	virtual void SetMaterialConfiguratorGroup( TMaterialConfiguratorGroup *matCfgGroup )
	{
		MaterialConfiguratorGroup = matCfgGroup;
	}

	virtual void CopyMaterialsToPath( UnicodeString *newpath, bool force = true, bool checktexture = true, bool cancopymaxwell = true );
	virtual void UpdatePathOwnMaterials( UnicodeString *newpath );
	virtual void CheckPathOwnMaterials( UnicodeString *newpath, bool checktexture = true );

	virtual void SetOGLDisplayData( int, GLenum, int, GLfloat, GLfloat, GLfloat, TOGLFloat2, bool isStepRes = false, GLfloat *qualityfactor = 0 );
	virtual void GetOGLDisplayData( int, GLenum &, int &, GLfloat &, GLfloat &, GLfloat &, TOGLFloat2 &, bool &, GLfloat *qualityfactor = 0 );
	virtual void SetOGLDisplayData( TOGLDisplayData * );
	virtual int GetUnselectMatIndex( )
	{
		return SYSMAT_UNSELECT;
	}
	virtual void UpdateUnselectMats( TOGLRenderData *, TOGLRenderSystem * );
	virtual void UpdateStipple( TOGLRenderData *, TOGLRenderSystem * )
	{
	}
	virtual void UpdatePenStyle( TOGLRenderData *_OGLRdData, TOGLRenderSystem *_OGLRdSystem, TPenStyle *penstyle )
	{
	}
	virtual void ApplyOGLRenderData( TOGLTransf *, TOGLRenderData *, TOGLRenderSystem *, bool &applytexturecoords );
	virtual bool ApplyTexture( TOGLTransf *, TOGLRenderSystem *, TOGLTexture *, bool ismaxwell = false, bool = true );
	virtual bool ApplyTextureList( TOGLTransf *, TOGLRenderData *, bool recalc = true );
	virtual void DrawOGL( TOGLTransf *, TOGLRenderData *, TOGLRenderSystem * );
	virtual void DrawOGLPolygon( TOGLTransf *, TOGLRenderData *, TOGLRenderSystem *, bool, bool = true );
	virtual void DrawOGLPolygonGrading2D( TOGLTransf *OGLTransf, TOGLRenderData *_OGLRdData, TOGLRenderSystem *_OGLRdSystem, bool applytexturecoords, bool = true )
	{
	}
	virtual void DrawOGLPolygonRotation2D( TOGLTransf *OGLTransf, TOGLRenderData *_OGLRdData, TOGLRenderSystem *_OGLRdSystem, bool applytexturecoords, bool = true )
	{
	}

	virtual void DrawOGLSelectedBox( TOGLTransf * );
	virtual TCadEntity *GetEntityToDrawOGLMarkers( );
	virtual bool MustDrawOGLMarkers( TOGLTransf *OGLTransf, TOGLRenderSystem *_OGLRdSystem )
	{
		return false;
	}
	virtual bool MustDrawOGLMarkersSymbolic( TOGLTransf *OGLTransf, TOGLRenderSystem *_OGLRdSystem )
	{
		return false;
	}
	virtual void DrawOGLMarkers( TOGLTransf *, TOGLRenderSystem *, int forcetype = MK_MODE_NONE, int forceind = -1 )
	{
	}
	virtual void DrawOGLCenterArrow( TOGLTransf *OGLTransf, TOGLRenderSystem *_OGLRdSystem )
	{
	}

	virtual bool MustDrawOGLPointRelations( TOGLTransf *OGLTransf, TOGLRenderSystem *_OGLRdSystem )
	{
		return false;
	}
	virtual void DrawOGLPointRelations( TOGLTransf *, TOGLRenderSystem * )
	{
	}

	virtual void SelectOGL( TOGLTransf *, int, int, TOGLRenderData *, TOGLRenderSystem *, TInteger_List * = 0 )
	{
	}
	virtual void DrawOGLDevelopWeights( TOGLTransf *, TInteger_List *, TOGLRenderData *, TOGLRenderSystem * )
	{
	}

	virtual TCadEntity *GetShapeWithID( int id )
	{
		return ( ( id == ID ) ? this : 0 );
	}
	virtual TCadEntity *GetIBSpline( TOGLTransf *, bool, bool onlyone = true )
	{
		return 0;
	}
	virtual int GetCurvesAmount( )
	{
		return 0;
	}
	virtual int GetSISLCurvesAmount( )
	{
		return 0;
	}
	virtual int GetSurfacesAmount( )
	{
		return 0;
	}
	virtual int GetSISLSurfacesAmount( )
	{
		return 0;
	}
	virtual int GetTrimSurfacesAmount( )
	{
		return 0;
	}
	virtual int GetMeshesAmount( )
	{
		return 0;
	}
	virtual void GetCurves( TCadGroup *Gr )
	{
	}
	virtual void GetSurfaces( TCadGroup *Gr )
	{
	}

	virtual void CalcMarkerListsPoints( TOGLTransf *OGLTransf, bool isparam, TInteger_List *forcetypes, bool checkextremes, TCadGroup *group, bool forcedev = false );
	virtual void CalcMarkerListsPoints( TOGLTransf *OGLTransf, bool isparam, TInteger_List *forcetypes = 0, bool checkextremes = true, bool forcedev = false )
	{
	}
	virtual void CalcMarkerListsPcts( TOGLTransf *OGLTransf, bool isparam, TInteger_List *forcetypes = 0, bool checkextremes = true, bool forcedev = false )
	{
	}

	virtual void Move( TOGLTransf *, T3DPoint )
	{
	}
	virtual bool MoveFromTo( TOGLTransf *, T3DPoint org, T3DPoint dst )
	{
		return false;
	}
	virtual void MoveFromToArea( TOGLTransf *, T3DPoint org, T3DPoint dst, TCadShape *area, TInteger_List *ptslist )
	{
		return;
	}
	virtual void ApplyMatrixArea( TOGLTransf *OGLTransf, TNMatrix *matrix, TCadShape *area, TInteger_List *ptslist )
	{
		return;
	}

	virtual bool IsTouchedByArea( TOGLTransf *OGLTransf, TCadShape *area, TInteger_List *ptslist )
	{
		return false;
	}
	virtual void FitToRect( TOGLTransf *, T3DPoint, T3DPoint );
	virtual void HMirror( TOGLTransf *, TNPlane forceplane = plNone )
	{
	}
	virtual void HMirror( TOGLTransf *, T3DPoint m, T3DPoint M, TNPlane forceplane = plNone )
	{
	}
	virtual void VMirror( TOGLTransf *, TNPlane forceplane = plNone )
	{
	}
	virtual void VMirror( TOGLTransf *, T3DPoint m, T3DPoint M, TNPlane forceplane = plNone )
	{
	}
	virtual void MirrorX0( TOGLTransf *, bool invertu = false, bool invertv = false, bool invert = true )
	{
	}
	virtual void MirrorY0( TOGLTransf *, bool invertu = false, bool invertv = false, bool invert = true )
	{
	}
	virtual void SymAxis( TOGLTransf *, T3DPoint *p1, T3DPoint *p2 )
	{
	}
	virtual void RotatePoints( T3DPoint *Pts, const T3DPoint &center, const int np, float angle, TNPlane plane );
	virtual bool Rotate( TOGLTransf *, float, TNPlane, int fp = -1, int lp = -1 )
	{
		return false;
	}
	virtual bool Rotate( TOGLTransf *, float, T3DPoint, TNPlane, int fp = -1, int lp = -1 )
	{
		return false;
	}
	virtual bool RotateFromTo( TOGLTransf *OGLTransf, TNPlane plane, T3DPoint ct, T3DPoint org, T3DPoint dst, int fp, int lp, double &angle, T3DVector *rotAxis = NULL )
	{
		return false;
	}
	virtual void RotateFromToArea( TOGLTransf *OGLTransf, TNPlane plane, T3DPoint ct, T3DPoint org, T3DPoint dst, TCadShape *area, TInteger_List *ptslist )
	{
		return;
	}
	virtual void Invert( TOGLTransf * )
	{
	}
	virtual void InvertCoordsUV( )
	{
	}
	virtual void InvertCoord( int, double, double )
	{
	}
	virtual void PlaneToPlane( TNPlane plsource, TNPlane pldest, int method = 0 ) { };
	virtual void CheckEntityIsPeriodic( TOGLTransf *, TCadSurface *, float dist, bool corner, bool keepextremepoints )
	{
		;
	}
	virtual bool Compact( TOGLTransf *, TCadSurface *, double dist, bool corner, bool keepextremepoints, int &c )
	{
		return false;
	}
	virtual void ApplyMatrix( TOGLTransf *, TNMatrix *, bool recaldev = true, bool canusepbrep = true )
	{
	}
	virtual void ApplyMatrix( TOGLTransf *, TNMatrix *, int, int iEnd = -1 )
	{
	}

	void Remesh( TOGLTransf *OGLTransf, QRLib_RemeshSettings *settings, TCadGroup *curvesGroup, int curvesType, bool remesh, bool updatetextcoords, bool calcseams );

	virtual int GetExpLinesListCount( TOGLTransf *OGLTransf );
	virtual int GetExpTrianglesListCount( TOGLTransf *OGLTransf );
	virtual int GetExpConesListCount( TOGLTransf *OGLTransf );
	virtual int GetExpSpheresListCount( );
	virtual void GetExpLinesList( TOGLTransf *OGLTransf, int index, vector<TOGLPoint> *v, vector<GLint> *vi, bool *isStipple = 0 );
	virtual void GetExpTrianglesList( TOGLTransf *OGLTransf, int index, vector<TOGLPoint> *v, vector<GLint> *vi, int comparemask = CMASK_V, bool checkdegeneratedtriangles = true, double prec = RES_COMP, TOGLPolygonList *secondlist = 0, vector<TOGLPoint> *secondv = 0, bool geometryRepair = false, TOGLMaterial *matToForceCalcTexCoords = 0 );
	virtual void GetExpConesList( TOGLTransf *OGLTransf, int index, T3DPoint &pos, T3DSize &axis, double &rot_angle, double &radius, double &height );
	virtual void GetExpSpheresList( TOGLTransf *OGLTransf, T3DPoint &pos, double &radius );
	virtual bool GetExpLinesListMat( TOGLTransf *OGLTransf, int index, TOGLMaterial *mat );		// retorna si se devuelve material especifico
	virtual bool GetExpTrianglesListMat( TOGLTransf *OGLTransf, int index, TOGLMaterial *mat ); // retorna si se devuelve material especifico
	virtual bool GetExpConesListMat( TOGLTransf *OGLTransf, int index, TOGLMaterial *mat );		// retorna si se devuelve material especifico
	virtual bool GetExpSpheresListMat( TOGLTransf *, int, TOGLMaterial * );						// retorna si se devuelve material especifico

	virtual void SetEnabledPointRelations( bool enabled )
	{
	}
	virtual void SetEnabledDataRelations( bool enabled )
	{
	}

	virtual void ClearDataEdition( )
	{
	}
	virtual bool IsNormalEdition( )
	{
		return true;
	}
	virtual bool IsNormalEdition( int )
	{
		return true;
	}
	virtual int GetDataEdition( int i )
	{
		return EDIT_POINT_NORMAL;
	}
	virtual void SetDataEdition( int i, int e )
	{
	}
	virtual bool GetDataErasable( int i )
	{
		return true;
	}
	virtual void SetDataErasable( int i, bool e )
	{
	}

	virtual void SetDescription( UnicodeString description );
	virtual UnicodeString GetDescription( );
	virtual UnicodeString GetOwnDescription( )
	{
		return Description;
	}
	virtual UnicodeString WhoAmI( )
	{
		return ST_ENTITY;
	}
	virtual UnicodeString WhoIDSAmI( )
	{
		return "";
	}

	virtual bool AmIStrictEntity( )
	{
		return true;
	}
	virtual bool AmIStrictGroup( )
	{
		return false;
	}
	virtual bool AmIStrictShape( )
	{
		return false;
	}
	virtual bool AmIStrictPoint( )
	{
		return false;
	}
	virtual bool AmIStrictMeasure( )
	{
		return false;
	}
	virtual bool AmIStrictLine( )
	{
		return false;
	}
	virtual bool AmIStrictPolyline( )
	{
		return false;
	}
	virtual bool AmIStrictBSpline( )
	{
		return false;
	}
	virtual bool AmIStrictIBSpline( )
	{
		return false;
	}
	virtual bool AmIStrictGordonProfile( )
	{
		return false;
	}
	virtual bool AmIStrictRect( )
	{
		return false;
	}
	virtual bool AmIStrictRoundRect( )
	{
		return false;
	}
	virtual bool AmIStrictEllipse( )
	{
		return false;
	}
	virtual bool AmIStrictPuller( )
	{
		return false;
	}
	virtual bool AmIStrictText( )
	{
		return false;
	}
	virtual bool AmIStrictDepShape( )
	{
		return false;
	}
	virtual bool AmIStrictMesh( )
	{
		return false;
	}
	virtual bool AmIStrictDepMesh( )
	{
		return false;
	}
	virtual bool AmIStrictSurface( )
	{
		return false;
	}
	virtual bool AmIStrictLoftedSurface( )
	{
		return false;
	}
	virtual bool AmIStrictTensorSurface( )
	{
		return false;
	}
	virtual bool AmIStrictGordonSurface( )
	{
		return false;
	}
	virtual bool AmIStrictDepSurface( )
	{
		return false;
	}
	virtual bool AmIStrictTrimSurface( )
	{
		return false;
	}
	virtual bool AmIStrictTessPolygon( )
	{
		return false;
	}

	virtual bool AmIShape( )
	{
		return false;
	}
	virtual bool AmISurface( )
	{
		return false;
	}

	virtual bool AllowMarkers( )
	{
		return false;
	}
	virtual bool IsHomogeneous( TCadEntity *Ent )
	{
		return Ent && WhoAmI( ) == Ent->WhoAmI( );
	}
	virtual bool IsFillEntity( bool usepoints = true )
	{
		return false;
	}
	virtual bool IsRasterImage( )
	{
		return false;
	}

	virtual void FillProp( TOGLTransf *OGLTransf, TFormEntityData *properties );
	virtual void FillProp_General( TFormEntityData *properties );
	virtual void FillProp_Geom( TOGLTransf *OGLTransf, TFormEntityData *properties );
	virtual void FillProp_Advanced( TFormEntityData *properties );

	virtual UnicodeString GetTempName( )
	{
		return TempName;
	}
	virtual void SetTempName( UnicodeString str )
	{
		TempName = str;
	}
	virtual UnicodeString GetTempLayerName( )
	{
		return TempLayerName;
	}
	virtual void SetTempLayerName( UnicodeString str )
	{
		TempLayerName = str;
	}
	virtual int GetTempLayerPos( )
	{
		return TempLayerPos;
	}
	virtual void SetTempLayerPos( int pos )
	{
		TempLayerPos = pos;
	}
	virtual TUnicodeStringList *GetTempNameToRestoreList( )
	{
		return &TempNameToRestoreList;
	}
	virtual int GetTempIntValue( )
	{
		return TempIntValue;
	}
	virtual void SetTempIntValue( int value )
	{
		TempIntValue = value;
	}
	virtual int GetIntValue( )
	{
		return IntValue;
	}
	virtual void SetIntValue( int value )
	{
		IntValue = value;
	}
	bool operator==( const TCadEntity &other )
	{
		return &other == this;
	}

	// Pivot functions
	virtual void CreatePivot( );
	virtual void InitializePivot( TOGLTransf *OGLTransf, bool init_pos = true, bool init_refsystem = true );
	virtual TPivotData *GetPivot( TOGLTransf *OGLTransf, bool force = false );
	virtual void SetPivot( TPivotData *pivot );

	virtual bool IsAxis( bool strict = true )
	{
		return false;
	}
};

//------------------------------------------------------------------------------
// TData
//------------------------------------------------------------------------------

class TData
{
	friend class TImpExp_XML;

  protected:
	int numItems, maxItems;
	T3DPoint *Data;
	bool *Corner;
	double *Parfix;	   // Soporta parametrizacion definida por el usuario para valores > -1
	int *Edition;	   // Soporta distintos tipos de edicion de un punto
	bool *Erasable;	   // Soporta distintos tipos de edicion de un punto
	T3DPoint *AuxData; // Soporta datos adicionales para un punto. Utilizado para almacenar incrementos en las duales desenlazadas

  public:
	TData( int i = 0 );
	TData( TData * );
	virtual ~TData( );

	virtual void Flush( )
	{
		numItems = 0;
	}
	virtual void Clear( );

	virtual int Add( TOGLTransf *, T3DPoint, bool = false, int = -1, int = EDIT_POINT_NORMAL, bool = true, bool = true, double vtol = RES_COMP );
	virtual bool Delete( int );

	virtual void SetPoints( int np, T3DPoint * );

	virtual bool IsFull( )
	{
		return numItems == maxItems;
	}
	virtual void Grow( const int );

	T3DPoint *GetDataPtr( )
	{
		return Data;
	}
	T3DPoint *GetAuxDataPtr( )
	{
		return AuxData;
	}

	void SetUseAuxData( bool value );
	bool GetUseAuxData( )
	{
		return ( AuxData != 0 );
	}
};

//------------------------------------------------------------------------------

typedef vector<TCadEntity *> TCList;

typedef vector<TCadEntity *>::iterator TCadListIterator;

class TCadList : public TCList
{
  public:
	TCadList( ): TCList( )
	{
	}
	~TCadList( )
	{
		while ( (int) size( ) > 0 ) {
			delete *begin( );
			erase( begin( ) );
		}
	}

	bool HasMember( TCadEntity *entity )
	{
		bool result;
		int s;

		result = false;

		// Si no lo encuentra devuelve el ultimo, por eso debemos hacer 2 comprobaciones.
		s = size( ) - 1;
		if ( s >= 0 ) {
			if ( at( s ) == entity ) result = true;
			else
				result = find( begin( ), end( ), entity ) != end( );
		}

		return result;
	}

	// The given entity replaces the existing element at the index loc.
	void SetData( int loc, TCadEntity *entity )
	{
		// 1.- Primero borramos el hueco en el array. Sin borrar el elemento.
		// delete *( begin( ) + loc );
		erase( begin( ) + loc );

		// 2.- Insertamos el elemento en la posicion 'loc'.
		//     Inserts x before position. The return value points to the inserted x.
		insert( begin( ) + loc, entity );
	}
};

//------------------------------------------------------------------------------
// TCadGroup
//------------------------------------------------------------------------------

class TCadGroup : public TCadEntity
{
	friend class TImpExp_XML;

  protected:
	TCadList *List;

  public:
	bool IsGrouped, DestroyList; // Este parametro indica si realmente el grupo se fijo

  protected:
	virtual bool CalcSISL( TOGLTransf * );

	virtual bool CalcOGLLists( TOGLTransf * );
	virtual bool CalcOGLPolygon( TOGLTransf * );
	virtual bool CalcOGLParam2D( TOGLTransf * );
	virtual bool CalcOGLGeom3D( TOGLTransf * );
	virtual bool CalcOGLDevelop2D( TOGLTransf * );
	virtual bool CalcOGLGeom3DFromParam2D( TOGLTransf * );
	virtual bool CalcOGLDevelop2DFromParam2D( TOGLTransf *OGLTransf );
	virtual bool CalcOGLParam2DFromGeom3D( TOGLTransf * );
	virtual bool CalcOGLParam2DFromGeom3D_CT( TOGLTransf * );
	virtual bool CalcOGLParam2DFromDevelop2D( TOGLTransf * );

  public:
	TCadGroup( );
	TCadGroup( TCadEntity *, TCadEntity * );
	TCadGroup( TCadEntity *, TCadEntity *, TCadEntity * );
	TCadGroup( TCadGroup * );
	virtual ~TCadGroup( );

	virtual void Set( TCadEntity *Ent, bool copyrels );
	virtual void SetBasic( TCadEntity *, bool copyrels );

	virtual bool MustCalcOGLLists( TOGLRenderSystem * );
	virtual bool HasOGLList( TOGLTransf * );
	virtual int GetNumberOGLViewLists( TOGLTransf *, bool recalc = true );
	virtual int GetOGLViewLists( TOGLTransf *, TOGLPolygonList ***Lists, int index = 0, bool = true );

	virtual void GetOGLDualGeom2DOrDevelop2D( TOGLTransf *, TOGLPolygonList *, bool clear = true, bool recalc = true, bool forcerevertseconddevsurfindex = false, bool joinpolygons = true );
	virtual bool GetUniqueOGLDualGeom2DOrDevelop2D( TOGLTransf *OGLTransf, TOGLPolygonList *list, bool tessortrimclose = false );
	virtual bool GetUniqueOGLDualParam2D( TOGLTransf *, TOGLPolygonList *, bool tessortrimclose = false );

	virtual int GetWorkingViewMode( );

	virtual void SetAllDirty( bool, bool = true, bool increasedirtyid = true );
	virtual bool GetLockRecalc( );
	virtual void SetLockRecalc( bool b );

	virtual void SetLockUpdateData( TOGLTransf *, bool b, bool onlyset = false );

	virtual bool CreateEntitiesPBRep( TOGLTransf * );

	virtual void SetDimension( TDimension );
	virtual void SetOGLParam_1_Tol( double );
	virtual void SetParamSurface( TCadSurface *, bool onlyset = false );
	virtual void SetParamOffset( double d );
	virtual double GetParamOffset( );
	virtual double GetDualParamOffset( );
	virtual void SetParamInterpolationMode( int type );
	virtual bool IsParamEntity( );
	virtual bool HasParamEntity( );
	virtual TCadSurface *GetBaseSurface( );
	virtual TCadSurface *GetParamSurface( );
	virtual TCadSurface *GetDualParamSurface( );
	virtual int GetDevelopSurfIndex( );
	virtual int GetDualDevelopSurfIndex( );
	virtual bool GetForceDevelopSurfIndex( );
	virtual bool GetDualForceDevelopSurfIndex( );
	virtual bool ChangeParamSurface( TOGLTransf *, TCadSurface *ParamSurfDest );
	virtual void ClearDataEdition( );
	virtual bool IsNormalEdition( );
	virtual bool IsNormalEdition( int )
	{
		return true;
	}
	virtual void SetEnabledPointRelations( bool enabled );
	virtual void SetEnabledDataRelations( bool enabled );

	virtual void MoveParamCenter( TOGLTransf *OGLTransf, double *limitsUV, TLPoint orgcenter, TLPoint dstcenter );

	virtual bool IsEditable( );
	virtual bool IsIndependent( bool checkpointrels = true );
	virtual bool IsDevelopable( );
	virtual void SetDevelopable( bool dev );
	virtual bool IsDualDevelopable( );
	virtual bool CanApplyTransform( bool checkpointrels = true );
	virtual bool CanConvertTo( TOGLTransf *, int dualityType );

	virtual bool IsInPlane( TOGLTransf *OGLTransf, T3DPlane &plane, double prec = RES_GEOM );
	virtual bool IsInSamePlane( TOGLTransf *OGLTransf, T3DPlane &Plane, double prec = RES_GEOM );
	virtual bool IsInPlane( TNPlane pl );

	virtual bool IsPeriodicDataValid( TOGLTransf * );
	virtual bool SetRangeOGLParam2D( TOGLTransf *, bool inrange );

	virtual TCadEntity *GetNewGeomEntity( TOGLTransf *OGLTransf );
	virtual TCadEntity *GetNewGeomEntityFromDevelop( TOGLTransf *OGLTransf );

	virtual bool NormSISLCurveInSurface( TOGLTransf *, double *, double *, double *, TCadSurface * = 0 );
	virtual bool NormSISLCurveInLimitsUV( TOGLTransf *OGLTransf, bool *close, double *limitsUV );

	virtual void CleanGroups( );
	virtual void GetDownRelatedEntities( TOGLTransf *OGLTransf, TCadGroup *Group, HLAYER *excludelayer = 0, bool force = false );
	virtual void GetUpRelatedEntities( TCadGroup *Group, bool rels = true, bool pointRels = true );
	virtual bool HasUpRelatedEntities( bool rels = true, bool pointRels = true, bool excludeparamsurf = false );
	virtual void DetachUpRelations( TCadGroup *, TPointRelationList *, TEntityRelationList *, bool updatedirty = true );
	virtual void ChangeOwnRelatedEntity( TCadEntity *ent );
	virtual void ChangeRelatedEntity( TCadEntity *orgent, TCadEntity *dstent, TCadGroup *gr = 0, bool setdirty = false );
	virtual void ClearOwnRelations( );

	virtual void AddEntityRelation( TEntityRelation *pr );
	virtual void DelEntityRelation( int index );
	virtual void DelEntityRelation( TCadEntity *ent );

	virtual void Add( TCadEntity *, bool checkexists = true );
	virtual void Insert( int ind, TCadEntity *Entity, bool force = false );
	virtual void Detach( TCadEntity *, DeleteType = Delete );
	virtual void Detach( const int &, DeleteType = Delete );
	virtual void Clear( );
	virtual void ClearTrue( );
	virtual void ClearDelGroups( bool force = false );

	virtual TCadList *GetList( )
	{
		return List;
	}
	virtual void SetData( int ind, TCadEntity *Ent );

	virtual void SetDestroyList( bool value )
	{
		DestroyList = value;
	}

	virtual bool CalcBoundRect( TOGLTransf *, T3DRect &, bool outrange = false, TNMatrix *mat = 0 );
	virtual bool CalcBoundRectParam( TOGLTransf *, T3DRect &, bool outrange = false, TNMatrix *mat = 0 );
	virtual bool CalcBoundRectViewport( TOGLTransf *, TLRect &, int step = 1, TNMatrix *MirrorMat = 0, TInstanceList *list = 0 );
	virtual bool DataBoundRect( TOGLTransf *OGLTransf, T3DRect &r, TNMatrix *mat = 0 );
	virtual void OrderByBounds( TOGLTransf *OGLTransf );

	virtual void GetLimitsUV( TOGLTransf *, double *limits = 0 );

	virtual int Count( )
	{
		return List->size( );
	}
	virtual float Perimeter( TOGLTransf * );
	virtual float Area( TOGLTransf * );
	virtual float Volume( TOGLTransf *, bool force = false );
	virtual bool GravityCenter( TOGLTransf *, T3DPoint &pt );
	virtual bool GravityCenter( TOGLTransf *OGLTransf, T3DPoint &pt, double inc );

	virtual void ClearID( );
	virtual void ClearOGLLists( );
	virtual void Download_glList( );
	virtual void Download( );
	virtual int GetMaxId( );
	virtual void ReplaceID( int oldid, int newid );
	virtual void ReplaceID( TInteger_List *oldids, TInteger_List *newids );
	virtual bool IsIDIncluded( int id );
	virtual bool IsEntityIncluded( TCadEntity *, bool recursive = true );
	virtual int GetEntityIndex( TCadEntity *entity, bool recursive = true, int *curindex = 0 ); // nunca poner valor curindex desde fuera
	virtual TCadEntity *GetEntityByIndex( int index, int *curindex = 0 );						// nunca poner valor curindex desde fuera
	virtual void AddEntitiesToGroup( TCadGroup *Grp, bool ForceNoCopy = false );
	virtual void AddGroupsToGroup( TCadGroup *Grp );
	virtual void SetEntities( TCadGroup * );

	virtual void ClearRenderDataTextureUV( );

	virtual int GetCurvesAmount( );
	virtual int GetSISLCurvesAmount( );
	virtual int GetSurfacesAmount( );
	virtual int GetSISLSurfacesAmount( );
	virtual int GetTrimSurfacesAmount( );
	virtual int GetMeshesAmount( );
	virtual void GetCurves( TCadGroup *Gr );
	virtual void GetSurfaces( TCadGroup *Gr );

	virtual void SetOwnOGLRenderData( bool o );
	virtual void SetOGLRenderData( TOGLRenderData *oglrddata );
	virtual void SetOGLDisplayData( int, GLenum, int, GLfloat, GLfloat, GLfloat, TOGLFloat2, bool isStepRes = false, GLfloat *qualityfactor = 0 );
	virtual void SetOGLDisplayData( TOGLDisplayData * );

	virtual void DrawOGL( TOGLTransf *, TOGLRenderData *, TOGLRenderSystem * );
	virtual bool MustDrawOGLMarkers( TOGLTransf *OGLTransf, TOGLRenderSystem *_OGLRdSystem );
	virtual bool MustDrawOGLMarkersSymbolic( TOGLTransf *OGLTransf, TOGLRenderSystem *_OGLRdSystem );
	virtual void DrawOGLMarkers( TOGLTransf *, TOGLRenderSystem *, int forcetype = MK_MODE_NONE, int forceind = -1 );
	virtual bool MustDrawOGLPointRelations( TOGLTransf *OGLTransf, TOGLRenderSystem *_OGLRdSystem );
	virtual void DrawOGLPointRelations( TOGLTransf *, TOGLRenderSystem * );

	virtual void CalcMarkerListsPoints( TOGLTransf *OGLTransf, bool isparam, TInteger_List *forcetypes, bool checkextremes, TCadGroup *group, bool forcedev = false );
	virtual void CalcMarkerListsPoints( TOGLTransf *OGLTransf, bool isparam, TInteger_List *forcetypes = 0, bool checkextremes = true, bool forcedev = false );
	virtual void CalcMarkerListsPcts( TOGLTransf *OGLTransf, bool isparam, TInteger_List *forcetypes = 0, bool checkextremes = true, bool forcedev = false );

	virtual void Move( TOGLTransf *, T3DPoint );
	virtual bool MoveFromTo( TOGLTransf *, T3DPoint org, T3DPoint dst );
	virtual void MoveFromToArea( TOGLTransf *, T3DPoint org, T3DPoint dst, TCadShape *area, TInteger_List *ptslist );
	virtual void ApplyMatrixArea( TOGLTransf *OGLTransf, TNMatrix *matrix, TCadShape *area, TInteger_List *ptslist );
	virtual void HMirror( TOGLTransf *, TNPlane forceplane = plNone );
	virtual void HMirror( TOGLTransf *, T3DPoint m, T3DPoint M, TNPlane forceplane = plNone );
	virtual void VMirror( TOGLTransf *, TNPlane forceplane = plNone );
	virtual void VMirror( TOGLTransf *, T3DPoint m, T3DPoint M, TNPlane forceplane = plNone );
	virtual void MirrorX0( TOGLTransf *, bool invertu = false, bool invertv = false, bool invert = true );
	virtual void MirrorY0( TOGLTransf *, bool invertu = false, bool invertv = false, bool invert = true );
	virtual void SymAxis( TOGLTransf *, T3DPoint *p1, T3DPoint *p2 );
	virtual bool Rotate( TOGLTransf *, float, TNPlane, int fp = -1, int lp = -1 );
	virtual bool Rotate( TOGLTransf *, float, T3DPoint, TNPlane, int fp = -1, int lp = -1 );
	virtual bool RotateFromTo( TOGLTransf *, TNPlane, T3DPoint, T3DPoint, T3DPoint, int, int, double &, T3DVector *rotAxis = NULL );
	virtual void RotateFromToArea( TOGLTransf *OGLTransf, TNPlane plane, T3DPoint ct, T3DPoint org, T3DPoint dst, TCadShape *area, TInteger_List *ptslist );
	virtual void Invert( TOGLTransf * );
	virtual void InvertCoordsUV( );
	virtual void InvertCoord( int, double, double );
	virtual void InvertEntities( TOGLTransf * );
	virtual void PlaneToPlane( TNPlane plsource, TNPlane pldest, int method = 0 );
	virtual void CheckEntityIsPeriodic( TOGLTransf *, TCadSurface *, float dist, bool corner, bool keepextremepoints );
	virtual bool Compact( TOGLTransf *, TCadSurface *, double dist, bool corner, bool keepextremepoints, int &c );
	TCadGroup *CompactEntities( TOGLTransf *, double dist, bool corner, bool keepextremepoints, bool close = true, double replacesegmentsdist = -1.0 );
	void ReplaceSegments( TOGLTransf *, double dist );
	virtual void ApplyMatrix( TOGLTransf *, TNMatrix *, bool recaldev = true, bool canusepbrep = true );
	virtual void ApplyMatrix( TOGLTransf *, TNMatrix *, int, int iEnd = -1 );

	virtual bool Intersect( TOGLTransf *, T3DPlane &, double ***, int ** );

	virtual TCadEntity *GetShape( const int & );
	virtual TCadEntity *GetShapeWithID( int );

	virtual UnicodeString WhoAmI( )
	{
		return ST_GROUP;
	}
	virtual UnicodeString WhoIDSAmI( )
	{
		return "IDS_ST_GROUP";
	}

	virtual bool AmIStrictEntity( )
	{
		return false;
	}
	virtual bool AmIStrictGroup( )
	{
		return true;
	}

	virtual bool IsHomogeneous( TCadEntity *Ent );
	bool ClearParamSurfaceGroup( );

	virtual void FillProp_General( TFormEntityData *properties );
	virtual void FillProp_Geom( TOGLTransf *OGLTransf, TFormEntityData *properties );

	void WriteD3D( wchar_t *filename );
	virtual void SetLayerForAll( HLAYER l );
	void WriteASCII( wchar_t *filename );

	bool AreValidAllEditPlanes( TOGLTransf * );

	void SortElementsById( );
	void SortElementsByTempLayerPosition( );
};

//------------------------------------------------------------------------------
// TCadShape
//------------------------------------------------------------------------------

class TCadShape : public TCadEntity, public TData
{
	friend class TImpExp_XML;

  protected:
	int Close, CloseExt, Degree, ParamType;
	SISLCurve *Curve;

	TCadGroup *GeomSurfaces; // Lofted y Gordon
	TCadGroup *PointRelatedShapes;
	TCadGroup *TessPolygons;

	double TrimPct[ 2 ];
	TMarkerList MarkerList;

	TPointRelationList PointRelationList;
	bool EnabledPointRelations; // Variable temporal para que cuando se calcule la curva, lo haga sin las relaciones de punto
	bool EnabledDataRelations;	// Variable temporal para que cuando se calcule la curve, lo haga sin recalcular los datas
	TEditPlaneData EditPlaneData;
	T3DPlane SymPlane;
	bool SymPlanePrefStart; // Lado valido para simetria. Tramo inicial = true, tramo final = false

	bool LockUpdateData; // Indica si la entidad esta siendo editada en este momento. Valido para las relaciones punto simultaneas entre dos o mas entidades para saber cual manda.

	bool IsDataToCalcSISLCurveDirty;
	int UpdatingDataToCalcSISLCurve; // Para evitar bucles infinitos en la actualizacion de los datos (debido a relaciones) necesarios para calcular la curva SISL.

	bool ShowStartPoint;

	int Properties;

	bool FillList;
	TOGLPolygonList OGLFillList;

  protected:
	virtual T3DPoint *SetParamData( TOGLTransf *, bool = false );
	virtual void RemoveParamData( TOGLTransf *, T3DPoint *, bool, bool = false );

	virtual void UpdateEditPlaneDataRecur( TOGLTransf *OGLTransf, int baseAux, int i, TCadShape *IniShape );

	virtual void UpdateEditPlaneData( TOGLTransf *OGLTransf, int index = -1 );
	virtual void UpdateSymPlaneData( TOGLTransf *OGLTransf, int index = -1 );
	virtual void SetPointRelations( TOGLTransf * );
	virtual bool IsRelatedPoint( int pos, int &Value );
	virtual void ChangeDataPointRelation( int pos, int value );
	virtual void ChangeDataPointRelated( int pos, int value );

	virtual void UpdateDataToCalcSISLCurve( TOGLTransf *OGLTransf );
	virtual bool CalcSISLCurve( TOGLTransf *, double * = 0 );
	virtual double *CalcSISLParams( TOGLTransf *, int = DEFAULT_PARAM_TYPE );
	virtual double *CalcSISLFixParams( TOGLTransf *, double *params );
	virtual bool RatToPolSISLCurve( TOGLTransf *, bool force = false );
	virtual bool DegreeRedSISLCurve( TOGLTransf * );
	virtual void NormSISLCurve( TOGLTransf * );
	virtual bool CalcCloseExt( );

	virtual bool CalcSISL( TOGLTransf * );

	virtual bool CalcOGLPolygon( TOGLTransf * );

	virtual bool GetOGLMarkerValuesToDraw( TOGLTransf *OGLTransf, double orgpct, TCadSurface *paramsurf, TCadSurface *dualparamsurf, bool *close, double *limits, TOGLPolygonList *ListBase, double perbase, TOGLPolygonList *ListGeom, double pergeom, TOGLPolygonList *ListPar, double perparam, TOGLPolygonList *ListDev, double perdev, T3DPoint &ptguess, TOGLFloat3 &vec, TOGLFloat3 &vecn, TOGLFloat3 &vecn2dbracket, TOGLFloat3 &vecn3dbracket, TOGLFloat3 &vecn3dbracket2, TOGLFloat3 &vecaxis );

	virtual void ApplyTrimPcts( TOGLTransf * );

  public:
	TCadShape( int pt = DEFAULT_PARAM_TYPE, int d = DEFAULT_DEGREE, int i = 0 );
	TCadShape( T3DPoint &P, bool C = false, int pt = DEFAULT_PARAM_TYPE, int d = DEFAULT_DEGREE, int i = 0 );
	TCadShape( TCadShape * );
	virtual ~TCadShape( );

	virtual void Set( TCadEntity *Ent, bool copyrels );
	virtual void SetBasic( TCadEntity *, bool copyrels );
	virtual void SetBasicGeometry( TCadEntity *S );
	virtual void SetBasicRels( TCadEntity *S );
	virtual void ChangeBasicRels( TCadEntity *orgbaseent, TCadEntity *dstbaseent, bool updatedirty = true, bool setdirty = false );
	virtual void GetBasicRelsEnts( TCadGroup *grp, bool usesurf = true, bool usemainaxissurf = true );

	virtual bool NormSISLCurveInSurface( TOGLTransf *, double *, double *, double *, TCadSurface * = 0 );
	virtual bool NormSISLCurveInLimitsUV( TOGLTransf *OGLTransf, bool *close, double *limitsUV );

	bool GetShowStartPoint( )
	{
		return ShowStartPoint;
	}
	void SetShowStartPoint( bool value )
	{
		ShowStartPoint = value;
	}

	virtual void SetParamInterpolationMode( int mode );
	virtual void SetParamOffset( double d );
	virtual double GetParamOffset( );
	virtual double GetDualParamOffset( );
	virtual void SetDevelopable( bool dev );
	virtual bool IsDualDevelopable( );
	virtual int GetDualDevelopSurfIndex( );
	virtual void SetDevelopSurfIndex( int index );
	virtual bool GetDualForceDevelopSurfIndex( );
	virtual void SetForceDevelopSurfIndex( bool value );
	virtual bool GetDevelopSurfIndexByBoxCenter( TOGLTransf *OGLTransf, int &devsurfindex );

	virtual bool GetMainAxis( )
	{
		return false;
	}
	virtual bool GetInvertDevelopSideInAxis( )
	{
		return false;
	}

	virtual void CleanGroups( );
	virtual void GetDownRelatedEntities( TOGLTransf *OGLTransf, TCadGroup *Group, HLAYER *excludelayer = 0, bool force = false );
	virtual void GetUpRelatedEntities( TCadGroup *Group, bool rels = true, bool pointRels = true );
	virtual bool HasUpRelatedEntities( bool rels = true, bool pointRels = true, bool excludeparamsurf = false );
	virtual void DetachUpRelations( TCadGroup *, TPointRelationList *, TEntityRelationList *, bool updatedirty = true );
	virtual void ChangeOwnRelatedEntity( TCadEntity *ent );
	virtual void ChangeOwnRelatedShape2D( TCadShape *ent );
	virtual void ChangeRelatedEntity( TCadEntity *orgent, TCadEntity *dstent, TCadGroup *gr = 0, bool setdirty = false );
	virtual void ClearOwnRelations( );

	virtual bool SetRangeOGLParam2D( TOGLTransf *OGLTransf, bool inrange );
	virtual void ToParamRangeInDev( TOGLTransf *OGLTransf );

	virtual TOGLPolygonList *GetOGLDualParam2D( TOGLTransf *OGLTransf, bool recalc = true );
	virtual TOGLPolygonList *GetOrgOGLDualGeom2DOrDevelop2D( TOGLTransf *, bool recalc = true );
	virtual bool GetOGLDualGeom3DPoint( TOGLTransf *OGLTransf, int index, T3DPoint &pt, bool force = true );
	virtual bool GetOGLDualGeom2DOrDevelop2DPoint( TOGLTransf *OGLTransf, int index, T3DPoint &pt, bool force = true );
	virtual void GetOGLDualGeom2DOrDevelop2D( TOGLTransf *, TOGLPolygonList *, bool clear = true, bool recalc = true, bool forcerevertseconddevsurfindex = false, bool joinpolygons = true );
	virtual bool GetOGLForceGeom2DOrDevelop2D( TOGLTransf *OGLTransf, TOGLPolygonList *Out, bool joinpolygons = true );
	virtual bool GetOGLForceGeom2DOrDevelop2D( TOGLTransf *OGLTransf, TCadSurface *paramsurf, TCadTrimSurface **Trim, TOGLPolygonList *In, TOGLPolygonList *Out, int nparallels, TParallelData *paralleldata, TParallelTypeData *paralleltypedata, TOGLPolygonList *OutParallel );
	virtual bool GetOGLForceGeom2DOrDevelop2DExt( TOGLTransf *OGLTransf, TCadSurface *paramsurf, TCadTrimSurface **Trim, TOGLPolygonList *In, TOGLPolygonList *Out, TOGLPolygonList *ExtList, int nparallels, TParallelData *paralleldata, TOGLPolygonList *OutParallel );
	virtual TOGLPolygonList *GetOGLDualGeom3D( TOGLTransf *OGLTransf, bool recalc = true );
	virtual bool GetOGLDualFilteredList( TOGLTransf *OGLTransf, bool isparam, double *limits, bool *close, double tol, double maxparam, TOGLPolygonList *list, bool forcerevertseconddevsurfindex = false, bool joinpolygons = true );
	virtual bool GetOGLDualFilteredList( TOGLTransf *OGLTransf, bool isparam, double *limits, bool *close, double tol, double maxdist, TOGLPolygonList *list, bool forcerevertseconddevsurfindex, bool joinpolygons, double dist );
	virtual bool GetUniqueOGLDualGeom2DOrDevelop2D( TOGLTransf *OGLTransf, TOGLPolygonList *list, bool tessortrimclose = false );
	virtual bool GetUniqueOGLDualParam2D( TOGLTransf *, TOGLPolygonList *, bool tessortrimclose = false );

	virtual bool CanUseTrimPcts( bool calcoglpolygon = false );
	virtual bool HasTrimPcts( );
	virtual void SetTrimPctValue( int index, double pct );
	virtual double GetTrimPctValue( int index );

	virtual TMarkerList *GetOwnMarkerList( );
	virtual TMarkerList *GetMarkerList( );
	virtual void SetMarkerList( TMarkerList *S, bool onlyset = false );
	virtual void ClearMarkerList( );
	virtual int PointMarkersCount( int type = -1 );
	virtual int LineMarkersCount( int type = -1 );
	virtual int VisibleMarkersCount( );

	virtual TPointMarker *GetPointMarker( TOGLTransf *OGLTransf, int index, int type = -1 );
	virtual TLineMarker *GetLineMarker( TOGLTransf *OGLTransf, int index, int type = -1 );
	virtual void AddPointMarker( TPointMarker *pm );
	virtual void DelPointMarker( int index );
	virtual void SetPointMarker( TOGLTransf *OGLTransf, int index, TPointMarker *pm );
	virtual void UpdatePointMarker( TOGLTransf *OGLTransf, int index );
	virtual void AddLineMarker( TOGLTransf *OGLTransf, TLineMarker *lm, bool check = true );
	virtual void DelLineMarker( int index );
	virtual void SetLineMarker( TOGLTransf *OGLTransf, int index, TLineMarker *lm );
	virtual void MoveLineMarker( TOGLTransf *OGLTransf, int ind, double pct );
	virtual void MovePointMarker( TOGLTransf *OGLTransf, int ind, double pct );
	virtual bool IsSymmetricMarker( bool isline, int ind );
	virtual int DelPointMarkerSymmetry( int ind );

	virtual void SetPointMarkersEditType( int pm );
	virtual void SetMarkerRelType( int rel );
	virtual TCadGroup *GetMarkerRelCurves( );
	virtual void AddMarkerRelCurve( TCadEntity * );
	virtual void OrderMarkerList( );
	virtual void InvertMarkerList( );

	virtual void ApplyMarkerRelation( TMarkerList *list, int type, int ind );
	virtual bool ValidateLineMarkerDragPct( TOGLTransf *OGLTransf, int ind, double &pct );
	virtual bool ValidatePointMarkerDragPct( TOGLTransf *OGLTransf, int ind, double &pct );

	virtual void CalcMarkerListsPoints( TOGLTransf *OGLTransf, bool isparam, TInteger_List *forcetypes, bool checkextremes, TCadGroup *group, bool forcedev = false );
	virtual void CalcMarkerListsPoints( TOGLTransf *OGLTransf, bool isparam, TInteger_List *forcetypes = 0, bool checkextremes = true, bool forcedev = false );
	virtual void CalcMarkerListsPcts( TOGLTransf *OGLTransf, bool isparam, TInteger_List *forcetypes = 0, bool checkextremes = true, bool forcedev = false );

	virtual int GetShapeElementsCount( TInteger_List *forcetypes = 0, TInteger_List *excludetypes = 0, bool forcecosting = false );
	virtual bool GetMarkerByShapeElement( TOGLTransf *, TShapeElement *se, int &indp, int &indl, int checkoffset = 1 );
	virtual bool GetMarkerByShapeElementIndex( TOGLTransf *OGLTransf, int index, int &indp, int &indl, TInteger_List *forcetypes = 0, TInteger_List *excludetypes = 0, bool forcecosting = false );
	virtual bool GetMarkerByShapeElementIndex( TOGLTransf *OGLTransf, int index, TPointMarker **pm, TLineMarker **lm, TInteger_List *forcetypes = 0, TInteger_List *excludetypes = 0, bool forcecosting = false );

	virtual int GetMarkerSEIndexByPct( double pct, bool close, double range, int &indp, int &indl, TInteger_List *forcetypes = 0, TInteger_List *excludetypes = 0, bool forcecosting = false );
	virtual void SetPointMarkerSE( TOGLTransf *OGLTransf, int index, TShapeElement *se );
	virtual void SetLineMarkerSE( TOGLTransf *OGLTransf, int index, TShapeElement *se );
	virtual TShapeElement *GetMarkerSE( TOGLTransf *OGLTransf, bool isline, int index );
	virtual void ApplySymmetryMarkerSE( );
	virtual bool UpdateMarkerSEMachines2D( TMachine2DList *machine2dlist, TTool2DList *tool2dlist, TMachine2DList *newmachine2dlist, TTool2DList *newtool2dlist );
	virtual bool UpdateMarkerSEActive( bool *seVisibility );
	virtual bool ReplaceTool2DTypes( TMachine2DList *machine2dlist, int machine2dindex, int tool2dtype1, int tool2dtype2 );

	virtual bool GetLockUpdateData( )
	{
		return LockUpdateData;
	}
	virtual void SetLockUpdateData( TOGLTransf *, bool, bool onlyset = false );
	virtual void UpdatePointRelationsData( TOGLTransf *OGLTransf, TCadShape *shape );
	virtual TPointRelationList *GetOwnPointRelationList( );
	virtual TPointRelationList *GetPointRelationList( );
	virtual bool AddPointRelation( TOGLTransf *OGLTransf, TPointRelation *pr, int pmv = -1, int ed = -1 );
	virtual bool SetPointRelation( TOGLTransf *OGLTransf, int index, TPointRelation *pr, int pmv = -1, int ed = -1 );
	virtual bool DelPointRelation( TOGLTransf *OGLTransf, int index, int pmv = -1, int ed = -1 );
	virtual bool InsertPointRelation( TOGLTransf *OGLTransf, int index, TPointRelation *pr, int pmv = -1, int ed = -1 );
	virtual bool HasPointRelation( int pos, int &Value );
	virtual bool HasDataPointRelation( );
	virtual bool IsDataWithErasablePointRelation( int index, int &prindex );

	virtual void CreateGeomSurfaces( );
	virtual TCadGroup *GetGeomSurfaces( )
	{
		return GeomSurfaces;
	}
	virtual void CreatePointRelatedShapes( );
	virtual TCadGroup *GetPointRelatedShapes( )
	{
		return PointRelatedShapes;
	}
	virtual void CreateTessPolygons( );
	virtual TCadGroup *GetTessPolygons( )
	{
		return TessPolygons;
	}

	virtual TCadShape *GetDualShapeByDep( );
	virtual TCadDepShape *GetDualDepShape( );
	virtual TCadShape *GetDualParamShapeByDep( );
	virtual TCadShape *GetDualGeomShapeByDep( );
	virtual TCadSurface *GetDualParamSurface( );
	virtual bool BasePctFromDepPct( TOGLTransf *OGLTransf, double pctin, double &pctout );
	virtual bool IsRelatedByDep( TCadShape *shape );
	virtual TCadShape *GetDualParam2DShape( );
	virtual TCadShape *GetDualGeom3DShape( );

	virtual GLfloat *GetPWLCurve( TOGLTransf *, int &np );
	virtual bool IsPeriodicDataValid( TOGLTransf * );

	virtual void SetSISLDirty( bool b, bool increasedirtyid = true );
	virtual void SetPolygonDirty( bool b, bool increasedirtyid = true );
	virtual void SetDevelop2DDirty( bool b, bool increasedirtyid = true );
	virtual void SetMarkersDepShapesDirty( bool increasedirtyid = true );

	virtual int Add( TOGLTransf *, T3DPoint, bool = false, int = -1, int = EDIT_POINT_NORMAL, bool = true, bool = true, double vtol = RES_COMP );
	virtual bool Delete( int );
	virtual void Clear( );
	virtual void ClearCorners( );
	virtual int CountCorners( bool includeextremes = true );
	virtual int Count( )
	{
		return numItems;
	}

	virtual void SetClose( int )
	{
	}
	virtual int GetClose( TOGLTransf *OGLTransf = 0 );
	virtual int GetCloseExt( TOGLTransf * );
	virtual bool IsCloseExtOGLDualFilteredList( TOGLTransf *OGLTransf, bool isparam, bool joinpolygons = true, double offset = 0.0 );

	virtual SISLCurve *GetSISLCurve( TOGLTransf *, double * = 0 );
	virtual T3DPoint *GetPointsSISL( TOGLTransf *OGLTransf, int &np, double = RES_GEOM );
	virtual T3DPoint *GetNPointsSISL( TOGLTransf *OGLTransf, int );

	virtual int GetIndexToAdd( TOGLTransf *, T3DPoint, TNPlane NPlane = plNone, bool forcepersp = false );
	virtual T3DPoint GetDataPoint( TOGLTransf *, int i );
	virtual bool GetDataPoint( TOGLTransf *, int i, T3DPoint &P );
	virtual T3DPoint GetDataPointByParam( TOGLTransf *, double );
	virtual T3DPoint GetAuxData( TOGLTransf *, int i );
	virtual T3DPoint GetDataDerivative( TOGLTransf *, const double & );
	virtual double GetDataParam( TOGLTransf *, const T3DPoint &, bool checkdist = true );
	virtual double GetDataParam( TOGLTransf *, const int & );
	virtual double *GetNParamsSISL( TOGLTransf *OGLTransf, int num );
	int GetParamType( )
	{
		return ParamType;
	}
	void SetParamType( int paramType )
	{
		ParamType = paramType;
		SetAllDirty( true, true );
	}

	virtual T3DPlane GetEditPlane( TOGLTransf * )
	{
		return EditPlaneData.Plane;
	}
	virtual TEditPlaneData *GetEditPlaneData( )
	{
		return &EditPlaneData;
	}
	virtual void SetEditPlaneData( TEditPlaneData *editplanedata );
	virtual T3DPlane GetSymPlane( )
	{
		return SymPlane;
	}
	virtual void SetSymPlane( T3DPlane plane )
	{
		SymPlane = plane;
		SetAllDirty( true, true );
	}
	virtual bool GetSymPlanePrefStart( )
	{
		return SymPlanePrefStart;
	}
	virtual void SetSymPlanePrefStart( bool value )
	{
		SymPlanePrefStart = value;
	}
	virtual void CalcSymPlanePrefStart( int index );
	virtual bool GetSymPlaneOfIndex( int index );
	virtual int GetSymmetricIndexOfSymPlane( int index );
	virtual int GetProperties( )
	{
		return Properties;
	}
	virtual void SetProperty( int Prop )
	{
		Properties = Prop;
	}
	virtual void SetPriority( int _Priority );
	virtual void SetEdge( bool edge );
	virtual bool GetEdge( );
	virtual void SetEnabledPointRelations( bool enabled );
	virtual bool GetEnabledPointRelations( )
	{
		return EnabledPointRelations;
	}
	virtual void SetEnabledDataRelations( bool enabled );
	virtual bool GetEnabledDataRelations( )
	{
		return EnabledDataRelations;
	}

	virtual TCadEntity *GetNewGeomEntity( TOGLTransf *OGLTransf );
	virtual TCadEntity *GetNewGeomEntityFromDevelop( TOGLTransf *OGLTransf );
	virtual bool ChangeParamSurface( TOGLTransf *, TCadSurface *ParamSurfDest );

	virtual void MoveParamCenter( TOGLTransf *OGLTransf, double *limitsUV, TLPoint orgcenter, TLPoint dstcenter );

	virtual int GetNearestDataPoint( T3DPoint *p );
	virtual bool GetNearestPoints( TOGLTransf *, TCadShape *shape, T3DPoint &pt1, T3DPoint &pt2, double *d = 0 );
	virtual bool GetNearestPointsSMLIB( TOGLTransf *OGLTransf, TCadShape *shape, T3DPoint &pt1, T3DPoint &pt2, double tol = RES_GEOM, double *_dist = 0 );
	virtual bool GetIntersectPoints( TOGLTransf *OGLTransf, TCadShape *shape, TOGLPolygon *out, double res = RES_GEOM );

	virtual bool GetDataCorner( int i )
	{
		return true;
	} // Devuelve true solo si es esquina y es spline, no polylines...
	virtual double GetDataParfix( const int &i );
	virtual int GetDataEdition( int i );
	virtual void SetDataEdition( int i, int e );
	virtual void ClearDataEdition( );
	virtual bool IsNormalEdition( );
	virtual bool IsNormalEdition( int i );
	virtual bool GetDataErasable( int i );
	virtual void SetDataErasable( int i, bool e );
	virtual int SelectDataPoint( const T3DPoint &, const float, TOGLTransf * );
	virtual void SetParfix( const int &, double )
	{
	}

	virtual bool SetPointPosRelatedToPlane( TOGLTransf *OGLTransf, int ind, T3DPoint *_pt, T3DPlane *_plane, double horz, double vert, double side, bool extend = false );
	virtual bool GetPointPosRelatedToPlane( TOGLTransf *OGLTransf, int ind, T3DPoint *_pt, T3DPlane *_plane, double &horz, double &vert, double &side, bool extend = false );

	virtual bool DataBoundRect( TOGLTransf *OGLTransf, T3DRect &r, TNMatrix *mat = 0 );

	virtual void GetLimits( TOGLTransf *, double *limits = 0 );
	virtual void GetLimitsUV( TOGLTransf *, double *limits = 0 );

	virtual void GetSegmentInfo( TOGLTransf *OGLTransf, TShapeInfo *si, int ind1, int ind2 );
	virtual T3DPoint SizeSegment( TOGLTransf *OGLTransf, int ind1, int ind2 );
	virtual float Perimeter( TOGLTransf * );
	virtual float PerimeterSegment( TOGLTransf *OGLTransf, int ind1, int ind2 );
	virtual float PerimeterSegment( TOGLTransf *OGLTransf, double param1, double param2 );
	virtual float SignedArea( TOGLTransf * );
	virtual float Area( TOGLTransf *OGLTransf )
	{
		return ( GetClose( OGLTransf ) != ENT_OPEN ) ? fabs( SignedArea( OGLTransf ) ) : 0;
	}
	virtual bool IsClockwise( TOGLTransf *, TNPlane pl = plXY );
	virtual bool IsClockwiseForceGeom2DOrDevelop2D( TOGLTransf *OGLTransf, TCadTrimSurface *trim, bool &clockwise );

	virtual bool Contains( const T3DPoint &P, TNPlane pl, TOGLTransf * );
	virtual bool ContainsSISL( const T3DPoint &P, TNPlane pl, TOGLTransf *OGLTransf );
	virtual bool IsContaining( TOGLTransf *, TCadEntity *Ent1, bool onlyOnePt = false );
	virtual bool IsInactive( TOGLTransf * );
	virtual bool IsIndependent( bool checkpointrels = true );
	virtual bool CanApplyTransform( bool checkpointrels = true );
	virtual bool CanConvertTo( TOGLTransf *, int dualityType );

	virtual bool IsInPlane( TOGLTransf *OGLTransf, T3DPlane &plane, double prec = RES_GEOM );
	virtual bool IsInPlane( TNPlane pl );
	virtual void ToPlane( T3DPlane plane, T3DVector dir );
	virtual bool GetDragPlane( TOGLTransf *OGLTransf, T3DPlane &Plane, int curpoint = -1, bool force = false, bool incalcsisl = false );

	virtual TCadEntity *GetIBSpline( TOGLTransf *, bool, bool onlyone = true );
	virtual int GetCurvesAmount( )
	{
		return 1;
	}
	virtual int GetSISLCurvesAmount( )
	{
		return 1;
	}
	virtual void GetCurves( TCadGroup *Gr );

	virtual void GetExtremeAxisList( TOGLTransf *OGLTransf, TOGLPolygonList *List );

	virtual void SelectOGL( TOGLTransf *, int, int, TOGLRenderData *, TOGLRenderSystem *, TInteger_List * = 0 );
	virtual void DrawOGL( TOGLTransf *OGLTransf, TOGLRenderData *_OGLRdData, TOGLRenderSystem *_OGLRdSystem );
	virtual void DrawOGLPolygonGrading2D( TOGLTransf *OGLTransf, TOGLRenderData *_OGLRdData, TOGLRenderSystem *_OGLRdSystem, bool applytexturecoords, bool = true );
	virtual void DrawOGLPolygonRotation2D( TOGLTransf *OGLTransf, TOGLRenderData *_OGLRdData, TOGLRenderSystem *_OGLRdSystem, bool applytexturecoords, bool = true );
	virtual void DrawOGLPolygonAsAxis( TOGLTransf *OGLTransf, TOGLRenderSystem * );
	virtual void DrawOGLPolygonAsRefAxis( TOGLTransf *OGLTransf, TOGLRenderSystem * );
	virtual void DrawOGLPolygonAsGrading2DAxis( TOGLTransf *OGLTransf, TOGLRenderSystem * );
	virtual void DrawOGLPolygonAsGrading2DRef( TOGLTransf *OGLTransf, TOGLRenderSystem * );
	virtual void DrawOGLPointAsPointCircle( TOGLTransf *OGLTransf, TOGLRenderData *_OGLRdData, TOGLRenderSystem *_OGLRdSystem, int type = -1 );
	virtual void DrawOGLNode( int ind, float nodesize, bool canuserectformat = true );
	virtual void SetOwnOGLRenderData( bool o );
	virtual void SetOGLRenderData( TOGLRenderData *oglrddata );
	virtual void Download_glList( );
	virtual void Download( );
	virtual void ApplyOGLRenderData( TOGLTransf *, TOGLRenderData *, TOGLRenderSystem *, bool &applytexturecoords );
	virtual int GetUnselectMatIndex( )
	{
		return SYSMAT_UNSELECT_SHAPE;
	}
	virtual bool MustDrawOGLMarkers( TOGLTransf *OGLTransf, TOGLRenderSystem *_OGLRdSystem );
	virtual bool MustDrawOGLMarkersSymbolic( TOGLTransf *OGLTransf, TOGLRenderSystem *_OGLRdSystem );
	virtual void DrawOGLMarkers( TOGLTransf *, TOGLRenderSystem *, int forcetype = MK_MODE_NONE, int forceind = -1 );
	virtual void DrawOGLCenterArrow( TOGLTransf *OGLTransf, TOGLRenderSystem *_OGLRdSystem );
	virtual bool MustDrawOGLPointRelations( TOGLTransf *OGLTransf, TOGLRenderSystem *_OGLRdSystem );
	virtual void DrawOGLPointRelations( TOGLTransf *, TOGLRenderSystem * );
	virtual bool GetOGLPointFromMarker( TOGLTransf *OGLTransf, int index, TOGLPoint *oglpt );
	virtual void CalcOGLBracket2D( TOGLTransf *OGLTransf, int type, TOGLFloat3 *vec, TOGLFloat3 *vecn, TOGLFloat3 *vecaxis, float sizelines, TOGLPolygonList *geomlist );
	virtual void CalcOGLBracket3D( TOGLTransf *OGLTransf, int type, TOGLFloat3 *vec, TOGLFloat3 *vecn, TOGLFloat3 *vecn2, T3DPoint ptguess, float sizelines, TOGLPolygonList *geomlist );
	virtual void CalcOGLSymbolic( TOGLTransf *OGLTransf, TOGLFloat3 *vec, TOGLFloat3 *vecn, float sizelines, bool invert, TOGLPolygonList *geomlist );

	virtual bool AlignCurve( TOGLTransf *, int first = -1, int last = -1, TNPlane pl = plXY );
	virtual void Move( TOGLTransf *, T3DPoint );
	virtual bool Move( TOGLTransf *, int, T3DPoint, bool valid = true, bool tol = true, double vtol = RES_COMP );
	virtual bool MoveFromTo( TOGLTransf *, T3DPoint org, T3DPoint dst );
	virtual void MoveFromToArea( TOGLTransf *, T3DPoint org, T3DPoint dst, TCadShape *area, TInteger_List *ptslist );
	virtual void ApplyMatrixArea( TOGLTransf *OGLTransf, TNMatrix *matrix, TCadShape *area, TInteger_List *ptslist );
	virtual bool MoveSegmentFromTo( TOGLTransf *OGLTransf, T3DPoint org, T3DPoint dst, int first, int last );
	virtual bool IsTouchedByArea( TOGLTransf *OGLTransf, TCadShape *area, TInteger_List *ptslist );
	virtual void HMirror( TOGLTransf *, TNPlane forceplane = plNone );
	virtual void HMirror( TOGLTransf *, T3DPoint, T3DPoint, TNPlane forceplane = plNone );
	virtual void VMirror( TOGLTransf *, TNPlane forceplane = plNone );
	virtual void VMirror( TOGLTransf *, T3DPoint, T3DPoint, TNPlane forceplane = plNone );
	virtual void MirrorX0( TOGLTransf *, bool invertu = false, bool invertv = false, bool invert = true );
	virtual void MirrorY0( TOGLTransf *, bool invertu = false, bool invertv = false, bool invert = true );
	virtual void SymAxis( TOGLTransf *, T3DPoint *p1, T3DPoint *p2 );
	virtual bool Rotate( TOGLTransf *, float, TNPlane, int fp = -1, int lp = -1 );
	virtual bool Rotate( TOGLTransf *, float, T3DPoint, TNPlane, int fp = -1, int lp = -1 );
	virtual bool RotateFromTo( TOGLTransf *, TNPlane, T3DPoint, T3DPoint, T3DPoint, int, int, double &, T3DVector *rotAxis = NULL );
	virtual void RotateFromToArea( TOGLTransf *OGLTransf, TNPlane plane, T3DPoint ct, T3DPoint org, T3DPoint dst, TCadShape *area, TInteger_List *ptslist );
	virtual void Invert( TOGLTransf * );
	virtual void InvertCoordsUV( );
	virtual void InvertCoord( int, double, double );
	virtual void PlaneToPlane( TNPlane plsource, TNPlane pldest, int method = 0 );
	virtual void DefineAsFirstPoint( int index );
	virtual void ApplyMatrix( TOGLTransf *, TNMatrix *, bool recaldev = true, bool canusepbrep = true );
	virtual void ApplyMatrix( TOGLTransf *, TNMatrix *, int, int iEnd = -1 );
	virtual void ConvertToOGLPolygon( TOGLTransf *OGLTransf, TOGLPolygon *pol );
	virtual void ConvertTo3DPolygon( TOGLTransf *OGLTransf, T3DPolygon *pol );
	virtual int Trim( TOGLTransf *, TCadShape *curve2, TCadGroup *curves, TNPlane pl, bool out );
	virtual int TrimIn( TOGLTransf *, TCadShape *curve2, TCadGroup *curves, TNPlane pl );
	virtual int TrimOut( TOGLTransf *, TCadShape *curve2, TCadGroup *curves, TNPlane pl );
	virtual TCadShape *Subtract( TOGLTransf *OGLTransf, TCadShape *curve2, TNPlane pl );
	virtual bool Intersect( TOGLTransf *, const T3DPlane &plano, double **intpar, int &numint );
	virtual bool Intersect( TOGLTransf *OGLTransf, TCadShape *curve, double **intpar1, double **intpar2, int &numint );
	virtual bool Intersect( TOGLTransf *, TCadShape *curve, double **intpar1, double **intpar2, int &numint, TNPlane pl );
	virtual SISLCurve *Pick( TOGLTransf *, const double &, const double &, bool norm = true );
	virtual SISLCurve *Join( TOGLTransf *, SISLCurve *, double res, bool norm = true );
	virtual SISLCurve *Extend( TOGLTransf *, const double &, const double & );
	virtual void Extend( TOGLTransf *OGLTransf, double dist, int side );

	// Libreria SMLib
	virtual TCadBSpline *Extend( TOGLTransf *OGLTransf, double dDistance, int StartorEnd, IwContinuityType eExtensionContinuitys );
	virtual bool CutWithPlane( TOGLTransf *OGLTransf, T3DPlane *plane, TCadGroup *curvesOut );
	virtual bool ChangeStartPoint( TOGLTransf *OGLTransf, T3DPoint *p );
	virtual TCadBSpline *Rebuild( TOGLTransf *OGLTransf, double tol = RES_GEOM );
	virtual TCadBSpline *Rebuild( TOGLTransf *OGLTransf, int numPts, double tol = RES_GEOM );

	virtual void FillProp_General( TFormEntityData *properties );
	virtual void FillProp_Geom( TOGLTransf *OGLTransf, TFormEntityData *properties );
	virtual void FillProp_Advanced( TFormEntityData *properties );
	virtual void FillProp_Point( TOGLTransf *OGLTransf, int index, TFormEntityData *properties );
	virtual void FillProp_Segment( TOGLTransf *OGLTransf, int ind1, int ind2, TFormEntityData *properties );
	virtual void FillProp_Distance( TOGLTransf *OGLTransf, TDistanceData *distdata, bool copyList = false );

	virtual void SetDescription( UnicodeString description );
	virtual UnicodeString WhoAmI( )
	{
		return ST_SHAPE;
	}

	virtual bool AmIStrictEntity( )
	{
		return false;
	}
	virtual bool AmIStrictShape( )
	{
		return true;
	}

	virtual bool AmIShape( )
	{
		return true;
	}
	virtual bool AllowMarkers( )
	{
		return true;
	}

	virtual double DistanceSISL( TOGLTransf *OGLTransf, T3DPoint p );
	virtual double DistanceSMLib( TOGLTransf *OGLTransf, T3DPoint p );
	virtual double DistanceSqrSISL( TOGLTransf *OGLTransf, T3DPoint p );

	virtual void SetFillList( bool value );
	virtual bool GetFillList( )
	{
		return FillList;
	}
	virtual bool CanUseFillList( TOGLTransf *OGLTransf );
	virtual bool MustCreateOGLFillList( TOGLTransf *OGLTransf );
	virtual void CreateOGLFillList( TOGLTransf *OGLTransf );
	virtual TOGLPolygonList *GetOGLFillList( TOGLTransf *OGLTransf );
};

//------------------------------------------------------------------------------
//	TCadPoint
//------------------------------------------------------------------------------

class TCadPoint : public TCadShape
{
	friend class TImpExp_XML;

  protected:
	UnicodeString Text;
	double Angle;
	double Radius;
	TDeformer *Deformer;

  protected:
	virtual bool CalcOGLPolygon( TOGLTransf * );
	virtual bool CalcOGLGeom3D( TOGLTransf * );
	virtual bool CalcOGLDevelop2D( TOGLTransf * );

  public:
	TCadPoint( int pt = DEFAULT_PARAM_TYPE, int d = DEFAULT_DEGREE, int i = 1 );
	TCadPoint( T3DPoint &P, int pt = DEFAULT_PARAM_TYPE, int d = DEFAULT_DEGREE );
	TCadPoint( TCadPoint *S );
	virtual ~TCadPoint( );

	virtual void Set( TCadEntity *Ent, bool copyrels );
	virtual void SetBasic( TCadEntity *, bool copyrels );
	virtual void SetBasicGeometry( TCadEntity *S );

	UnicodeString GetText( )
	{
		return Text;
	}
	double GetAngle( )
	{
		return Angle;
	}
	double GetRadius( )
	{
		return Radius;
	}

	void SetText( UnicodeString str )
	{
		Text = str;
	}
	void SetAngle( double angle )
	{
		Angle = angle;
	}
	void SetRadius( double radius )
	{
		Radius = radius;
	}

	virtual bool IsValid( TOGLTransf * )
	{
		return numItems == 1;
	}

	virtual int GetCurvesAmount( )
	{
		return 1;
	}
	virtual int GetSISLCurvesAmount( )
	{
		return 0;
	}
	virtual void GetCurves( TCadGroup *Gr )
	{
	}

	virtual void ApplyOGLRenderData( TOGLTransf *, TOGLRenderData *, TOGLRenderSystem *, bool &applytexturecoords );
	virtual void DrawOGLPolygon( TOGLTransf *OGLTransf, TOGLRenderData *, TOGLRenderSystem *, bool, bool = true );
	virtual void DrawOGLPointPointer( TOGLTransf *OGLTransf, TOGLRenderSystem *_OGLRdSystem );
	virtual void DrawOGLPointRef( TOGLTransf *OGLTransf, TOGLRenderData *_OGLRdData, TOGLRenderSystem *_OGLRdSystem );
	virtual void DrawOGLPointRot( TOGLTransf *OGLTransf, TOGLRenderData *_OGLRdData, TOGLRenderSystem *_OGLRdSystem );
	virtual void DrawOGLPointText( TOGLTransf *OGLTransf, TOGLRenderData *_OGLRdData, TOGLRenderSystem *_OGLRdSystem );
	virtual void DrawOGLPointCircle( TOGLTransf *OGLTransf, TOGLRenderData *_OGLRdData, TOGLRenderSystem *_OGLRdSystem );
	virtual void DrawOGLPointSphere( TOGLTransf *OGLTransf, TOGLRenderData *_OGLRdData, TOGLRenderSystem *_OGLRdSystem );
	virtual void DrawOGLPointRotPoint( TOGLTransf *OGLTransf, TOGLRenderData *_OGLRdData, TOGLRenderSystem *_OGLRdSystem );
	virtual void DrawOGLPointGrading2DLocation( TOGLTransf *OGLTransf, TOGLRenderData *_OGLRdData, TOGLRenderSystem *_OGLRdSystem );
	virtual void DrawOGLPointGrading2DRefPoint( TOGLTransf *OGLTransf, TOGLRenderData *_OGLRdData, TOGLRenderSystem *_OGLRdSystem );

	virtual void SelectOGL( TOGLTransf *, int, int, TOGLRenderData *, TOGLRenderSystem *, TInteger_List * = 0 );

	virtual int CountPointsToDeform( TOGLTransf *OGLTransf );
	virtual T3DPoint *GetPointsToDeform( TOGLTransf *OGLTransf, int &np, TDeformer *def = 0 );
	virtual void SetDeformedPoints( TOGLTransf *OGLTransf, int np, T3DPoint *def_points, bool locknormals = false );

	virtual bool IsFillEntity( bool usepoints = true );

	virtual UnicodeString WhoAmI( )
	{
		return ST_POINT;
	}
	virtual UnicodeString WhoIDSAmI( );

	virtual bool AmIStrictShape( )
	{
		return false;
	}
	virtual bool AmIStrictPoint( )
	{
		return true;
	}

	virtual bool AllowMarkers( )
	{
		return false;
	}

	virtual bool CanUseSpherePoint( );
	virtual int GetExpSpheresListCount( );
	virtual void GetExpSpheresList( TOGLTransf *OGLTransf, T3DPoint &pos, double &radius );
};

//------------------------------------------------------------------------------
//	TCadEditPlane
//------------------------------------------------------------------------------

class TCadEditPlane : public TCadShape
{
	friend class TImpExp_XML;

  protected:
	double PlaneSize[ 3 ];
	bool ViewInPlane[ 3 ];

  protected:
	virtual bool CalcSISLCurve( TOGLTransf *, double * = 0 );
	virtual bool CalcOGLLists( TOGLTransf * );
	virtual bool CalcOGLPolygon( TOGLTransf * );

	virtual void UpdateEditPlaneData( TOGLTransf *, int index = -1 )
	{
	}
	virtual void UpdateSymPlaneData( TOGLTransf *, int index = -1 )
	{
	}

  public:
	TCadEditPlane( int pt = DEFAULT_PARAM_TYPE, int d = DEFAULT_DEGREE, int i = 3 );
	//		TCadEditPlane( T3DPoint& P, int pt = DEFAULT_PARAM_TYPE, int d = DEFAULT_DEGREE );
	TCadEditPlane( TCadEditPlane *S );
	virtual ~TCadEditPlane( )
	{
	}

	virtual void Set( TCadEntity *Ent, bool copyrels );
	virtual void SetBasic( TCadEntity *, bool copyrels );

	virtual void SetEditPlaneData( TEditPlaneData * ) { }; // Se debe hacer a traves de las funciones siguientes
	virtual void SetEditPlaneData2PtsPlane( TOGLTransf *OGLTransf, T3DPoint pt, T3DPoint pt2, TNPlane plane );
	virtual void SetEditPlaneDataPtNormal( TOGLTransf *OGLTransf, T3DPoint pt, T3DPoint normal, T3DPoint dir, bool onlySet = false );
	virtual void SetEditPlaneData3Pts( TOGLTransf *OGLTransf, T3DPoint pt1, T3DPoint pt2, T3DPoint pt3 );

	virtual bool IsValid( TOGLTransf * );

	virtual int GetCurvesAmount( )
	{
		return 0;
	}
	virtual void GetCurves( TCadGroup *Gr )
	{
	}

	virtual bool CalcBoundRect( TOGLTransf *OGLTransf, T3DRect &r, bool outrange = false, TNMatrix *mat = 0 );
	virtual bool CalcBoundRectViewport( TOGLTransf *OGLTransf, TLRect &r, int step = 1, TNMatrix *MirrorMat = 0, TInstanceList *list = 0 );

	virtual bool GetViewInPlane( TNPlane plane );
	virtual void SetViewInPlane( TNPlane plane, bool value );

	virtual double GetPlaneSize( TNPlane plane );
	virtual void SetPlaneSize( TNPlane plane, double value );
	virtual T3DPlane GetEditPlane( TOGLTransf * );
	virtual int GetEditPlanePoints( TOGLTransf *, T3DPoint *, TNPlane forcePlane = plNone );

	virtual void DrawOGLPolygon( TOGLTransf *OGLTransf, TOGLRenderData *, TOGLRenderSystem *, bool, bool = true );
	virtual void DrawOGLPolygon3DPlane( TOGLTransf *, TOGLRenderData *, TOGLRenderSystem * );
	virtual void DrawOGLPolygon3Pts( TOGLTransf *, TOGLRenderData *, TOGLRenderSystem * );
	virtual void DrawOGLPolygon2PtsPlane( TOGLTransf *, TOGLRenderData *, TOGLRenderSystem * );
	virtual void DrawOGLPolygonPtNormal( TOGLTransf *, TOGLRenderData *, TOGLRenderSystem * );

	virtual void SelectOGL( TOGLTransf *, int, int, TOGLRenderData *, TOGLRenderSystem *, TInteger_List * = 0 );
	virtual void SelectOGL3DPlane( TOGLTransf *OGLTransf, TOGLRenderData *, TOGLRenderSystem *_OGLRdSystem );
	virtual void SelectOGL3Pts( TOGLTransf *OGLTransf, TOGLRenderData *, TOGLRenderSystem *_OGLRdSystem );
	virtual void SelectOGL2PtsPlane( TOGLTransf *OGLTransf, TOGLRenderData *, TOGLRenderSystem *_OGLRdSystem );
	virtual void SelectOGLPtNormal( TOGLTransf *OGLTransf, TOGLRenderData *, TOGLRenderSystem *_OGLRdSystem );

	virtual void Move( TOGLTransf *OGLTransf, T3DPoint P );
	virtual bool Move( TOGLTransf *, int, T3DPoint, bool valid = true, bool tol = true, double vtol = RES_COMP );
	virtual bool MoveFromTo( TOGLTransf *, T3DPoint org, T3DPoint dst );
	virtual void MoveFromToArea( TOGLTransf *, T3DPoint org, T3DPoint dst, TCadShape *area, TInteger_List *ptslist )
	{
		return;
	}
	virtual void ApplyMatrixArea( TOGLTransf *OGLTransf, TNMatrix *matrix, TCadShape *area, TInteger_List *ptslist )
	{
		return;
	}
	virtual bool IsTouchedByArea( TOGLTransf *OGLTransf, TCadShape *area, TInteger_List *ptslist )
	{
		return false;
	}
	virtual bool Rotate( TOGLTransf *, float, TNPlane, int fp = -1, int lp = -1 );
	virtual bool Rotate( TOGLTransf *, float, T3DPoint, TNPlane, int fp = -1, int lp = -1 );
	virtual bool RotateFromTo( TOGLTransf *, TNPlane, T3DPoint, T3DPoint, T3DPoint, int, int, double &, T3DVector *rotAxis = NULL );
	virtual void RotateFromToArea( TOGLTransf *OGLTransf, TNPlane plane, T3DPoint ct, T3DPoint org, T3DPoint dst, TCadShape *area, TInteger_List *ptslist )
	{
		return;
	}
	virtual void ApplyMatrix( TOGLTransf *, TNMatrix *, bool recaldev = true, bool canusepbrep = true );
	virtual void ApplyMatrix( TOGLTransf *, TNMatrix *, int, int iEnd = -1 )
	{
	}

	virtual UnicodeString WhoAmI( )
	{
		return ST_EDITPLANE;
	}
	virtual UnicodeString WhoIDSAmI( );

	virtual bool AmIStrictShape( )
	{
		return false;
	}
	virtual bool AllowMarkers( )
	{
		return false;
	}
};

//------------------------------------------------------------------------------
//	TCadMeasure
//------------------------------------------------------------------------------

class TCadMeasure : public TCadShape
{
	friend class TImpExp_XML;

  protected:
	TMeasureData MeasureData;
	bool ViewInPlane[ 3 ];

  protected:
	virtual bool CalcOGLPolygon( TOGLTransf * );
	virtual void CalcOGLPolygonPolyline( TOGLTransf * );
	virtual void CalcOGLPolygonPolylist( TOGLTransf * );
	virtual void CalcOGLPolygonAngle( );

	virtual bool CheckDataValid( TOGLTransf *OGLTransf );

  public:
	TCadMeasure( int pt = DEFAULT_PARAM_TYPE, int d = DEFAULT_DEGREE, int i = 1 );
	TCadMeasure( T3DPoint &P, T3DPoint &Q, int pt = DEFAULT_PARAM_TYPE, int d = DEFAULT_DEGREE );
	TCadMeasure( T3DPoint &P, T3DPoint &Q, T3DPoint &PPos, int pt = DEFAULT_PARAM_TYPE, int d = DEFAULT_DEGREE );
	TCadMeasure( TOGLPolygonList *pol, int pt = DEFAULT_PARAM_TYPE, int d = DEFAULT_DEGREE );
	TCadMeasure( int npoints, T3DPoint *P, int pt = DEFAULT_PARAM_TYPE, int d = DEFAULT_DEGREE );
	TCadMeasure( int npoints, T3DPoint *P, T3DPoint &PPos, int pt = DEFAULT_PARAM_TYPE, int d = DEFAULT_DEGREE );
	TCadMeasure( TCadMeasure *S );
	virtual ~TCadMeasure( )
	{
	}

	virtual void Set( TCadEntity *Ent, bool copyrels );
	virtual void SetBasic( TCadEntity *, bool copyrels );
	virtual void SetBasicGeometry( TCadEntity *S );

	virtual bool GetViewInPlane( TNPlane plane );
	virtual void SetViewInPlane( TNPlane plane, bool value );

	virtual TMeasureData *GetMeasureData( );
	virtual void SetMeasureData( TMeasureData *measuredata );
	virtual void SetMeasureData( TReportObjectFormat *rof );

	virtual void ApplyMatrix( TOGLTransf *OGLTransf, TNMatrix *matrix, bool recaldev = true, bool canusepbrep = true );
	virtual void ApplyMatrix( TOGLTransf *, TNMatrix *, int, int iEnd = -1 )
	{
	}

	virtual int GetCurvesAmount( )
	{
		return 1;
	}
	virtual int GetSISLCurvesAmount( )
	{
		return 0;
	}
	virtual void GetCurves( TCadGroup *Gr )
	{
	}

	virtual bool CalcBoundRect( TOGLTransf *OGLTransf, T3DRect &r, bool outrange = false, TNMatrix *mat = 0 );
	virtual bool CalcBoundRectViewport( TOGLTransf *OGLTransf, TLRect &r, int step = 1, TNMatrix *MirrorMat = 0, TInstanceList *list = 0 );
	virtual void CalcBoundRectText( TOGLPolygonList *list, TOGLTransf *OGLTransf, T3DRect &r );
	void GetBoundRectText( TOGLPolygonList *list, TOGLTransf *OGLTransf, T3DPoint &p1, T3DPoint &p2 );

	virtual void ApplyOGLRenderData( TOGLTransf *, TOGLRenderData *, TOGLRenderSystem *, bool &applytexturecoords );
	virtual void DrawOGLPolygon( TOGLTransf *OGLTransf, TOGLRenderData *, TOGLRenderSystem *, bool, bool = true );

	virtual TOGLPolygonList *CalcDrawOGLListsMeasureBasic( TOGLTransf *OGLTransf );
	virtual void DrawOGLListsMeasureBasic( TOGLPolygonList *OGLLists, TOGLTransf *OGLTransf, TOGLRenderData *_OGLRdData, TOGLRenderSystem *_OGLRdSystem );

	virtual TOGLPolygonList *CalcDrawOGLListsMeasureProjectionPlane( TOGLTransf *OGLTransf );
	virtual void DrawOGLListsMeasureProjectionPlane( TOGLPolygonList *OGLLists, TOGLTransf *OGLTransf, TOGLRenderData *_OGLRdData, TOGLRenderSystem *_OGLRdSystem );

	virtual TOGLPolygonList *CalcDrawOGLListsMeasureProjectionAxis( TOGLTransf *OGLTransf );
	virtual void DrawOGLListsMeasureProjectionAxis( TOGLPolygonList *OGLLists, TOGLTransf *OGLTransf, TOGLRenderData *_OGLRdData, TOGLRenderSystem *_OGLRdSystem );

	virtual TOGLPolygonList *CalcDrawOGLListsMeasureAngle( TOGLTransf *OGLTransf );
	virtual void DrawOGLListsMeasureAngle( TOGLPolygonList *OGLLists, TOGLTransf *OGLTransf, TOGLRenderData *_OGLRdData, TOGLRenderSystem *_OGLRdSystem );

	virtual bool SetData( int ind, T3DPoint P );

	virtual int GetCloseExt( TOGLTransf *OGLTransf );

	void DrawOriginalControlPoints( );
	void DrawArrows( TOGLPolygonList *oglList, TOGLTransf *OGLTransf );
	void DrawArrowsRaster( TOGLPolygonList *oglList, TOGLTransf *OGLTransf );
	void DrawArrows3D( TOGLPolygonList *oglList, TOGLTransf *OGLTransf = 0 );
	void DrawArrows( T3DPoint begin, T3DPoint end );
	void DrawText( TOGLPolygonList *list, TOGLTransf *OGLTransf, TOGLRenderData *_OGLRdData, TOGLRenderSystem *_OGLRdSystem );
	void DrawTextRaster( TOGLPolygonList *list, TOGLTransf *OGLTransf, TOGLRenderData *_OGLRdData, TOGLRenderSystem *_OGLRdSystem );
	TCadText *GetText3D( TOGLPolygonList *list, TOGLTransf *OGLTransf, TNPlane localDrawPlane = plNone );
	void DrawText3D( TOGLPolygonList *list, TOGLTransf *OGLTransf, TOGLRenderData *_OGLRdData, TOGLRenderSystem *_OGLRdSystem );
	void DrawFillSection( TOGLPolygonList *list, TOGLTransf *OGLTransf );

	T3DPoint GetBaseDrawPlanePosition( );
	T3DPoint GetOriginalFirstPoint( );
	T3DPoint GetOriginalLastPoint( );
	T3DPoint GetMinBoundingPoint( TNAxis axis );
	T3DPoint GetMaxBoundingPoint( TNAxis axis );
	T3DPoint GetOriginalGravityCenter( );

	float GetMeasure( TOGLTransf *OGLTransf );
	int GetPolylinesCount( TOGLTransf *OGLTransf );
	bool GetPolylines( TOGLTransf *OGLTransf, int index, vector<TOGLPoint> *v, vector<GLint> *vi, bool *isStipple );
	bool CanUseConePoints( TOGLTransf *OGLTransf );
	bool GetConePoints( TOGLTransf *OGLTransf, vector<TOGLPoint> *v );

	virtual int GetExpLinesListCount( TOGLTransf *OGLTransf );
	virtual int GetExpTrianglesListCount( TOGLTransf *OGLTransf );
	virtual int GetExpConesListCount( TOGLTransf *OGLTransf );
	virtual void GetExpLinesList( TOGLTransf *OGLTransf, int index, vector<TOGLPoint> *v, vector<GLint> *vi, bool *isStipple = 0 );
	virtual void GetExpTrianglesList( TOGLTransf *OGLTransf, int index, vector<TOGLPoint> *v, vector<GLint> *vi, int comparemask = CMASK_V, bool checkdegeneratedtriangles = true, double prec = RES_COMP, TOGLPolygonList *secondlist = 0, vector<TOGLPoint> *secondv = 0, bool geometryRepair = false, TOGLMaterial *matToForceCalcTexCoords = 0 );
	virtual void GetExpConesList( TOGLTransf *OGLTransf, int index, T3DPoint &pos, T3DSize &axis, double &rot_angle, double &radius, double &height );

	virtual UnicodeString WhoAmI( )
	{
		return ST_MEASURE;
	}
	virtual UnicodeString WhoIDSAmI( );

	virtual bool AmIStrictShape( )
	{
		return false;
	}
	virtual bool AmIStrictMeasure( )
	{
		return true;
	}
};

//------------------------------------------------------------------------------
// TCadLine
//------------------------------------------------------------------------------

class TCadLine : public TCadShape
{
	friend class TImpExp_XML;

  protected:
	bool MainAxis, InvertDevelopSideInAxis;
	TCadSurface *MainAxisSurface;
	TCameraMXS *CameraMXS;
	double RadiusDelimiterPlane;
	TDirLightData DirLightData;
	TRenderCameraData RenderCameraData;

  protected:
	virtual bool CalcSISLCurve( TOGLTransf *, double * = 0 );
	virtual bool CalcSISLCurveBasic( TOGLTransf *OGLTransf, double *epar = 0, bool checkcamera = true );

	virtual void UpdateCameraMXSFromData( TNMatrix *matrix = 0, TOGLTransf *OGLTransf = 0 );
	void UpdateRenderCameraFromData( TOGLTransf *, TNMatrix *mat );

  public:
	TCadLine( int pt = DEFAULT_PARAM_TYPE, int d = DEFAULT_DEGREE, int i = 2 );
	TCadLine( T3DPoint &P, int pt = DEFAULT_PARAM_TYPE, int d = DEFAULT_DEGREE );
	TCadLine( T3DPoint &P, T3DPoint &Q, int pt = DEFAULT_PARAM_TYPE, int d = DEFAULT_DEGREE );
	TCadLine( TCadLine *S );
	virtual ~TCadLine( );

	virtual void Set( TCadEntity *Ent, bool copyrels );
	virtual void SetBasic( TCadEntity *Ent, bool copyrels );
	virtual void SetBasicRels( TCadEntity *S );
	virtual void ChangeBasicRels( TCadEntity *orgbaseent, TCadEntity *dstbaseent, bool updatedirty = true, bool setdirty = false );
	virtual void GetBasicRelsEnts( TCadGroup *grp, bool usesurf = true, bool usemainaxissurf = true );

	virtual void GetUpRelatedEntities( TCadGroup *Group, bool rels = true, bool pointRels = true );
	virtual bool HasUpRelatedEntities( bool rels = true, bool pointRels = true, bool excludeparamsurf = false );
	virtual void ChangeOwnRelatedEntity( TCadEntity *ent );
	virtual void ChangeOwnRelatedShape2D( TCadShape *ent );
	virtual void ChangeRelatedEntity( TCadEntity *orgent, TCadEntity *dstent, TCadGroup *gr = 0, bool setdirty = false );
	virtual void ClearOwnRelations( );

	virtual bool GetMainAxis( )
	{
		return MainAxis;
	}
	virtual void SetMainAxis( bool value )
	{
		MainAxis = value;
		SetAllDirty( true, false );
	}
	virtual bool GetInvertDevelopSideInAxis( )
	{
		return InvertDevelopSideInAxis;
	}
	virtual void SetInvertDevelopSideInAxis( bool value )
	{
		InvertDevelopSideInAxis = value;
		SetAllDirty( true, false );
	}

	virtual TCadSurface *GetMainAxisSurface( )
	{
		return MainAxisSurface;
	}
	virtual void SetMainAxisSurface( TCadSurface *s );
	virtual void SetDevelopIndexForSymmetries( int devindex );
	virtual bool HasDevelopIndexForSymmetries( );
	virtual void ConvertOGLListForSymmetries( TOGLTransf *OGLTransf, TOGLPolygonList *OGLList, bool forcedevsurfindex, bool first );

	virtual bool CanUseTrimPcts( bool calcoglpolygon = false );

	void CreateCameraMXS( );
	TCameraMXS *GetCameraMXS( )
	{
		return CameraMXS;
	}
	void UpdateCameraMXS( TOGLTransf *OGLTransf, TCameraMXS *camera );

	void UpdateDirLight( TOGLTransf *OGLTransf );
	TDirLightData *GetDirLightData( );
	void SetDirLightData( TDirLightData *data );
	void GetDirLightPolygonList( TOGLTransf *OGLTransf, TOGLPolygonList *oglpolygonlist );

	void UpdateByRenderCameraData( TOGLTransf *OGLTransf );
	TRenderCameraData *GetRenderCameraData( );
	void SetRenderCameraData( TRenderCameraData *data );

	T3DPlane GetPlane( );
	void SetRadiusDelimiterPlane( double radius );

	virtual void UpdateStipple( TOGLRenderData *, TOGLRenderSystem * );
	virtual void UpdatePenStyle( TOGLRenderData *_OGLRdData, TOGLRenderSystem *_OGLRdSystem, TPenStyle *penstyle );
	virtual void DrawOGL( TOGLTransf *, TOGLRenderData *, TOGLRenderSystem * );
	virtual void DrawOGLPolygon( TOGLTransf *, TOGLRenderData *, TOGLRenderSystem *, bool, bool = true );
	virtual void DrawOGLPolygonCameraMXS( TOGLTransf *, TOGLRenderData *, TOGLRenderSystem *, bool, bool = true );
	void DrawOGLPolygonRenderCamera( TOGLTransf *OGLTransf, TOGLRenderData *, TOGLRenderSystem *_OGLRdSystem, bool, bool = true );
	void DrawOGLPolygonDelimiterPlane( TOGLTransf *, TOGLRenderData *, TOGLRenderSystem *, bool, bool = true );
	virtual void DrawOGLPolygonAsVector( TOGLTransf *OGLTransf, TOGLRenderSystem * );
	virtual void DrawOGLNode( int ind, float nodesize, bool canuserectformat = true );
	virtual void DrawOGLStartPointAndDirection( TOGLTransf *OGLTransf, TOGLRenderSystem *_OGLRdSystem );
	virtual void DrawOGLPolygonDirLight( TOGLTransf *, TOGLRenderSystem *, bool, bool = true );

	virtual void SelectOGL( TOGLTransf *OGLTransf, int current, int first, TOGLRenderData *_OGLRdData, TOGLRenderSystem *_OGLRdSystem, TInteger_List *ptslist = 0 );
	virtual void SelectOGLEditableAxis( TOGLTransf *OGLTransf, int current, int first, TOGLRenderData *_OGLRdData, TOGLRenderSystem *_OGLRdSystem );

	virtual void ApplyMatrix( TOGLTransf *, TNMatrix *, bool recaldev = true, bool canusepbrep = true );
	virtual void ApplyMatrix( TOGLTransf *OGLTransf, TNMatrix *mat, int iStart, int iEnd = -1 )
	{
		TCadShape::ApplyMatrix( OGLTransf, mat, iStart, iEnd );
	}

	virtual bool CanConvertTo( TOGLTransf *, int type );

	virtual bool IsAxis( bool strict = true );
	virtual bool IsRefAxis( )
	{
		return ( AmIStrictLine( ) && Type == LINETYPE_AXIS_REF );
	}
	virtual bool IsEditableAxis( )
	{
		return ( AmIStrictLine( ) && ( Type == LINETYPE_EDITABLE_AXIS_3P || Type == LINETYPE_EDITABLE_AXIS_2P ) );
	}
	virtual bool IsCameraMXS( )
	{
		return ( AmIStrictLine( ) && Type == LINETYPE_CAMERAMXS );
	}
	virtual bool IsRenderCamera( )
	{
		return ( AmIStrictLine( ) && Type == LINETYPE_RENDER_CAMERA );
	}
	virtual bool IsDelimiterPlane( )
	{
		return ( AmIStrictLine( ) && Type == LINETYPE_DELIMITERPLANE );
	}
	virtual bool IsVector( )
	{
		return ( AmIStrictLine( ) && Type == LINETYPE_VECTOR );
	}
	virtual bool IsGrading2DAxis( )
	{
		return ( AmIStrictLine( ) && Type == LINETYPE_GRADING2DAXIS );
	}
	virtual bool IsGrading2DRef( )
	{
		return ( AmIStrictLine( ) && Type == LINETYPE_GRADING2DREF );
	}
	virtual bool IsDirLight( )
	{
		return ( AmIStrictLine( ) && Type == LINETYPE_DIRLIGHT );
	}
	virtual bool IsDirLightArea( )
	{
		return ( IsDirLight( ) && DirLightData.Type == DIRLIGHT_TYPE_AREA );
	}
	virtual bool IsDirLightSpot( )
	{
		return ( IsDirLight( ) && DirLightData.Type == DIRLIGHT_TYPE_SPOT );
	}
	virtual bool IsDirLightPoint( )
	{
		return ( IsDirLight( ) && DirLightData.Type == DIRLIGHT_TYPE_POINT );
	}
	virtual bool IsDirLightPBRDirectional( )
	{
		return ( IsDirLight( ) && DirLightData.Type == DIRLIGHT_TYPE_PBR_DIRECTIONAL );
	}
	virtual bool IsDirLightPBRPoint( )
	{
		return ( IsDirLight( ) && DirLightData.Type == DIRLIGHT_TYPE_PBR_POINT );
	}
	virtual bool IsDirLightPBRSpot( )
	{
		return ( IsDirLight( ) && DirLightData.Type == DIRLIGHT_TYPE_PBR_SPOT );
	}

	virtual UnicodeString WhoAmI( )
	{
		return ST_LINE;
	}
	virtual UnicodeString WhoIDSAmI( );

	virtual bool AmIStrictShape( )
	{
		return false;
	}
	virtual bool AmIStrictLine( )
	{
		return true;
	}
};

//------------------------------------------------------------------------------
// TCadPolyLine
//------------------------------------------------------------------------------

class TCadPolyline : public TCadLine
{
	friend class TImpExp_XML;

  protected:
	int incr_points;

  protected:
	virtual bool CalcOGLLists( TOGLTransf * );
	virtual bool CalcOGLPolygon( TOGLTransf * );

  public:
	TCadPolyline( int pt = DEFAULT_PARAM_TYPE, int d = DEFAULT_DEGREE, int i = 2, int j = 10 );
	TCadPolyline( T3DPoint &P, int pt = DEFAULT_PARAM_TYPE, int d = DEFAULT_DEGREE );
	TCadPolyline( int npoints, T3DPoint *P, int pt = DEFAULT_PARAM_TYPE, int d = DEFAULT_DEGREE );
	TCadPolyline( TCadPolyline *S );
	virtual ~TCadPolyline( )
	{
	}

	virtual void Set( TCadEntity *, bool copyrels );
	virtual void SetBasic( TCadEntity *, bool copyrels );

	virtual void DrawOGLPolygon( TOGLTransf *, TOGLRenderData *, TOGLRenderSystem *, bool, bool = true );

	virtual int Add( TOGLTransf *, T3DPoint, bool = false, int = -1, int = EDIT_POINT_NORMAL, bool = true, bool = true, double vtol = RES_COMP );

	virtual void SetClose( int );
	virtual int GetClose( TOGLTransf *OGLTransf = 0 );

	virtual void FilterXY( TOGLTransf *, double dist );
	virtual void FilterShape( TOGLTransf *, float distMin, int first = -1, int last = -1, bool adjustdistmintosize = false );
	virtual void FilterShape( TOGLTransf *, float distMin, TInteger_List *DataToDelete, int first = -1, int last = -1, bool adjustdistmintosize = false, bool clearcorners = true );
	virtual void SmoothGauss( TOGLTransf *, int rangemax = 1, int first = -1, int last = -1, TNPlane pl = plNone );
	virtual bool SmoothCurve( TOGLTransf *, int rangemax = 1, int first = -1, int last = -1, TNPlane pl = plNone );
	virtual TCadEntity *Parallel( TOGLTransf *, TParallelData *dist, TNPlane pl, bool group );

	virtual TCadEntity *GetIBSpline( TOGLTransf *, bool, bool onlyone = true );

	virtual UnicodeString WhoAmI( )
	{
		return ST_POLYLINE;
	}
	virtual UnicodeString WhoIDSAmI( );

	virtual bool IsPolyPoints( )
	{
		return ( AmIStrictPolyline( ) && Type == POLYLINETYPE_POINTS );
	}

	virtual bool AmIStrictLine( )
	{
		return false;
	}
	virtual bool AmIStrictPolyline( )
	{
		return true;
	}
};

//------------------------------------------------------------------------------
// TCadBSpline
//------------------------------------------------------------------------------

class TCadBSpline : public TCadPolyline
{
  protected:
	virtual bool CalcSISLCurve( TOGLTransf *, double * = 0 );
	bool ReconstructSISL( int pos, bool add );

  public:
	TCadBSpline( int pt = DEFAULT_PARAM_TYPE, int d = DEFAULT_DEGREE, int i = 2, int j = 10 ): TCadPolyline( pt, d, i, j )
	{
	}
	TCadBSpline( T3DPoint &P, int pt = DEFAULT_PARAM_TYPE, int d = DEFAULT_DEGREE ): TCadPolyline( P, pt, d )
	{
	}
	TCadBSpline( int npoints, T3DPoint *P, int pt = DEFAULT_PARAM_TYPE, int d = DEFAULT_DEGREE ): TCadPolyline( npoints, P, pt, d )
	{
	}
	TCadBSpline( SISLCurve *Source, TOGLTransf *OGLTransf = 0, int j = 10, bool norm = true, bool copy = true, bool isImported = false );
	TCadBSpline( TCadBSpline *S ): TCadPolyline( S )
	{
	}
	virtual ~TCadBSpline( )
	{
	}

	virtual void Set( TCadEntity *Ent, bool copyrels )
	{
		TCadPolyline::Set( Ent, copyrels );
	}
	virtual void SetBasic( TCadEntity *Ent, bool copyrels );
	virtual void SetBasicGeometry( TCadEntity *S );

	virtual void SetClose( int );
	virtual void Move( TOGLTransf *OGLTransf, T3DPoint p );
	virtual bool Move( TOGLTransf *OGLTransf, int i, T3DPoint p, bool valid = true, bool tol = false, double vtol = RES_COMP );
	virtual int Add( TOGLTransf *, T3DPoint, bool = false, int = -1, int = EDIT_POINT_NORMAL, bool = true, bool = true, double vtol = RES_COMP );
	virtual bool Delete( int );

	virtual void ApplyMatrix( TOGLTransf *, TNMatrix *, bool recaldev = true, bool canusepbrep = true );
	virtual void ApplyMatrix( TOGLTransf *OGLTransf, TNMatrix *m, int start, int end = -1 )
	{
		TCadPolyline::ApplyMatrix( OGLTransf, m, start, end );
	}

	virtual bool Reduce( TOGLTransf *OGLTransf, double tolerance = 0.01 );
	virtual void SelectOGL( TOGLTransf *, int, int, TOGLRenderData *, TOGLRenderSystem *, TInteger_List * = 0 );

	virtual TCadEntity *GetIBSpline( TOGLTransf *, bool, bool onlyone = true );

	virtual UnicodeString WhoAmI( )
	{
		return ST_BSPLINE;
	}
	virtual UnicodeString WhoIDSAmI( )
	{
		return "IDS_ST_BSPLINE";
	}

	virtual bool AmIStrictPolyline( )
	{
		return false;
	}
	virtual bool AmIStrictBSpline( )
	{
		return true;
	}
};

//------------------------------------------------------------------------------
// TCadIBSpline
//------------------------------------------------------------------------------

class TCadIBSpline : public TCadBSpline
{
	friend class TImpExp_XML;

  protected:
	virtual bool CalcSISLCurve( TOGLTransf *, double * = 0 );

  protected:
	int EndCondition;
	T3DPoint *Der;

  public:
	TCadIBSpline( int pt = DEFAULT_PARAM_TYPE, int d = DEFAULT_DEGREE, int i = 2, int j = 10 );
	TCadIBSpline( T3DPoint &P, int pt = DEFAULT_PARAM_TYPE, int d = DEFAULT_DEGREE );
	TCadIBSpline( int npoints, T3DPoint *P, int pt = DEFAULT_PARAM_TYPE, int d = DEFAULT_DEGREE );
	TCadIBSpline( int npoints, T3DPoint *P, T3DPoint *D, int pt = DEFAULT_PARAM_TYPE, int d = DEFAULT_DEGREE );
	TCadIBSpline( TOGLTransf *OGLTransf, T3DPoint *ct, int nsides, double rext, int pt = DEFAULT_PARAM_TYPE, int d = DEFAULT_DEGREE, int i = 2, int j = 10 );
	TCadIBSpline( TOGLTransf *OGLTransf, T3DPoint *ct, int nends, double rint, double rext, int pt = DEFAULT_PARAM_TYPE, int d = DEFAULT_DEGREE, int i = 2, int j = 10 );
	TCadIBSpline( TCadIBSpline *S );
	virtual ~TCadIBSpline( );

	virtual void Set( TCadEntity *, bool copyrels );
	virtual void SetBasic( TCadEntity *, bool copyrels );
	virtual void SetBasicGeometry( TCadEntity *S );

	virtual int Add( TOGLTransf *, T3DPoint, bool = false, int = -1, int = EDIT_POINT_NORMAL, bool = true, bool = true, double vtol = RES_COMP );
	virtual bool Delete( int );

	virtual void SetEndCondition( int e )
	{
		EndCondition = e;
		SetAllDirty( true );
	}
	virtual int GetEndCondition( )
	{
		return EndCondition;
	}

	virtual void SetParfix( const int &i, double p );
	virtual void SetCorner( int i, bool c );
	virtual bool GetDataCorner( int i ); // Devuelve true solo si es esquina y es spline, no polylines...

	virtual int CornerDetection( TOGLTransf *, double angledeg = 36.0, int first = -1, int last = -1 );

	virtual void SelectOGL( TOGLTransf *, int, int, TOGLRenderData *, TOGLRenderSystem *, TInteger_List * = 0 );

	virtual TCadEntity *GetIBSpline( TOGLTransf *, bool, bool onlyone = true );
	virtual TCadIBSpline *Complete( TOGLTransf *OGLTransf, float distMin );

	virtual void UpdatePolygonOnCreate( TOGLTransf *OGLTransf, T3DPoint *ct, int nsides, double rext );
	virtual void UpdateStarOnCreate( TOGLTransf *OGLTransf, T3DPoint *ct, int nends, double rint, double rext );

	virtual UnicodeString WhoAmI( )
	{
		return ST_IBSPLINE;
	}
	virtual UnicodeString WhoIDSAmI( )
	{
		return "IDS_ST_IBSPLINE";
	}

	virtual bool AmIStrictBSpline( )
	{
		return false;
	}
	virtual bool AmIStrictIBSpline( )
	{
		return true;
	}
};

//------------------------------------------------------------------------------
// TCadGordonProfile
//------------------------------------------------------------------------------

class TCadGordonProfile : public TCadIBSpline
{
	friend class TImpExp_XML;

  protected:
	virtual bool CalcSISLCurve( TOGLTransf *, double * = 0 );

  protected:
	TGordonProfileData GordonProfileData;

  public:
	TCadGordonProfile( int pt = DEFAULT_PARAM_TYPE, int d = DEFAULT_DEGREE, int i = 2, int j = 10 );
	TCadGordonProfile( T3DPoint &P, int pt = DEFAULT_PARAM_TYPE, int d = DEFAULT_DEGREE );
	TCadGordonProfile( int npoints, T3DPoint *P, int pt = DEFAULT_PARAM_TYPE, int d = DEFAULT_DEGREE );
	TCadGordonProfile( int npoints, T3DPoint *P, T3DPoint *D, int pt = DEFAULT_PARAM_TYPE, int d = DEFAULT_DEGREE );
	TCadGordonProfile( TOGLTransf *OGLTransf, T3DPoint *ct, int nsides, double rext, int pt = DEFAULT_PARAM_TYPE, int d = DEFAULT_DEGREE, int i = 2, int j = 10 );
	TCadGordonProfile( TOGLTransf *OGLTransf, T3DPoint *ct, int nends, double rint, double rext, int pt = DEFAULT_PARAM_TYPE, int d = DEFAULT_DEGREE, int i = 2, int j = 10 );
	TCadGordonProfile( TCadGordonProfile *S );
	virtual ~TCadGordonProfile( )
	{
	}

	virtual void Set( TCadEntity *, bool copyrels );
	virtual void SetBasic( TCadEntity *, bool copyrels );
	virtual void SetBasicGeometry( TCadEntity *S );

	virtual int GetIndexToAdd( TOGLTransf *, T3DPoint, TNPlane NPlane = plNone, bool forcepersp = false );
	virtual int Add( TOGLTransf *, T3DPoint, bool = false, int = -1, int = EDIT_POINT_NORMAL, bool = true, bool = true, double vtol = RES_COMP );
	virtual bool Delete( int );

	virtual TCadEntity *GetIBSpline( TOGLTransf *, bool, bool onlyone = true );

	virtual TGordonProfileData *GetGordonProfileData( );
	virtual void SetGordonProfileData( TGordonProfileData *data );

	virtual bool GetDragPlane( TOGLTransf *OGLTransf, T3DPlane &Plane, int curpoint = -1, bool force = false, bool incalcsisl = false );

	virtual UnicodeString WhoAmI( )
	{
		return ST_GORDONPROFILE;
	}
	virtual UnicodeString WhoIDSAmI( )
	{
		return "IDS_ST_GORDONPROFILE";
	}

	virtual bool AmIStrictIBSpline( )
	{
		return false;
	}
	virtual bool AmIStrictGordonProfile( )
	{
		return true;
	}
};

//------------------------------------------------------------------------------
// TCadRect
//------------------------------------------------------------------------------

class TCadRect : public TCadPolyline
{
	friend class TImpExp_XML;

  protected:
	TRectFormatData RectFormatData;
	TRectDataSheetData RectDataSheetData;
	TRectLabelData RectLabelData;

	UnicodeString Text, RectDescription;
	TLRect TextRect;
	T3DPoint InsertPoints[ 2 ];

	bool IsTextDirty;
	bool IsTextVisible;
	// bool IsFillRect;      //atributo quitado, usaremos el  IsTransparent
	bool IsImageEnabled;
	bool TrimTextToRect;
	bool ImageMirrorX, ImageMirrorY; // Solo para imageframes, el espejo se realiza en el pad
	int LockType;
	int SpecialType;
	int Variation3D;
	int SplitMode;
	int ApplyMatMode;

	bool OpenAsSimple;

	TOGLPolygonList OGLTextList, OGLBaseTextList;

	TOGLTextureList OGLImageTextureList;
	TOGLMaterial OGLBackgroundMat;

	TCadGroup GeometryGroup;

  protected:
	virtual void UpdateEditPlaneData( TOGLTransf *, int index = -1 )
	{
	}
	virtual void UpdateSymPlaneData( TOGLTransf *, int index = -1 )
	{
	}

	virtual void CreateLetter( TOGLTransf *OGLTransf, wchar_t letter, TOGLPolygon *Polygon, TOGLPolygonList *OGLList );
	virtual void GetNewChar( TOGLTransf *OGLTransf, TOGLPolygonList *OGLList, wchar_t letter );
	virtual void CalcOGLText( TOGLTransf *OGLTransf );
	virtual void AddUnderlinePolygon( TOGLTransf *OGLTransf, TOGLPolygonList *OGLLineList );
	virtual bool CalcOGLPolygon( TOGLTransf *OGLTransf );
	virtual void CalcSplittedData( T3DPoint *auxData, bool textSide, bool noSeparator = true );
	virtual bool GetBordersList( TOGLTransf *OGLTransf, TOGLPolygonList *OGLList );

  public:
	TCadRect( int pt = DEFAULT_PARAM_TYPE, int d = DEFAULT_DEGREE, TNPlane plane = plXY );
	TCadRect( T3DPoint &P, T3DPoint &Q, int pt = DEFAULT_PARAM_TYPE, int d = DEFAULT_DEGREE, TNPlane plane = plXY );
	TCadRect( TCadRect *S );
	virtual ~TCadRect( )
	{
	}

	virtual TRectFormatData *GetRectFormatData( )
	{
		return &RectFormatData;
	}
	virtual void SetRectFormatData( TRectFormatData *rfd, TCadRect *S = 0 );
	virtual void SetRectFormatData( TReportObjectFormat *rof, TCadRect *S = 0 );

	virtual TRectDataSheetData *GetRectDataSheetData( )
	{
		return &RectDataSheetData;
	}
	virtual void SetRectDataSheetData( TRectDataSheetData *rds )
	{
		RectDataSheetData.Set( rds );
	}

	virtual void SetOGLBackgroundMat( TOGLMaterial *m, bool useApplyMatMode = true );
	virtual TOGLMaterial *GetOGLBackgroundMat( )
	{
		return &OGLBackgroundMat;
	}

	virtual void SetOGLTextMat( TOGLMaterial *m )
	{
		RectFormatData.OGLTextMat.Set( m );
	}
	virtual TOGLMaterial *GetOGLTextMat( )
	{
		return &RectFormatData.OGLTextMat;
	}

	virtual TOGLTextureList *GetOGLImageTextureList( )
	{
		return &OGLImageTextureList;
	}
	virtual void SetOGLImageTextureList( TOGLTextureList *l )
	{
		OGLImageTextureList.Set( l );
	}

	virtual void Set( TCadEntity *, bool copyrels );
	virtual void SetBasic( TCadEntity *, bool copyrels );
	virtual void SetBasicGeometry( TCadEntity *S );

	virtual void DrawOGL( TOGLTransf *, TOGLRenderData *, TOGLRenderSystem * );
	virtual void DrawOGLNode( int ind, float nodesize, bool canuserectformat = true );
	virtual void DrawOGLRectImage( TOGLTransf *, TOGLRenderSystem * );
	virtual void DrawStippleBorders( TOGLTransf *OGLTransf, TOGLRenderData *_OGLRdData, TOGLRenderSystem *_OGLRdSystem, bool uselinewidth );
	virtual void DrawBorderWidth( TOGLTransf *OGLTransf, TNPlane plane, bool inv, bool *chpos );
	virtual void DrawSelectedBorder( TOGLTransf *OGLTransf, TOGLRenderData *_OGLRdData, TOGLRenderSystem *_OGLRdSystem );

	virtual void CopyMaterialsToPath( UnicodeString *newpath, bool force = true, bool checktexture = true, bool cancopymaxwell = true );
	virtual void UpdatePathOwnMaterials( UnicodeString *newpath );
	virtual void CheckPathOwnMaterials( UnicodeString *newpath, bool checktexture = true );

	virtual TCadPolyline *GetSelectCursorOGL( TOGLTransf *OGLTransf );
	virtual void SelectOGL( TOGLTransf *OGLTransf, int first, int last, TOGLRenderData *_OGLRdData, TOGLRenderSystem *_OGLRdSystem, TInteger_List *ptslist = 0 );

	virtual bool AdjustToSquareOnCreate( TOGLTransf *OGLTransf, int curpt );
	virtual bool AdjustToSquareOnMovePoint( TOGLTransf *OGLTransf, int curpt );

	virtual void Move( TOGLTransf *, T3DPoint P );
	virtual bool Move( TOGLTransf *, int, T3DPoint, bool valid = true, bool tol = true, double vtol = RES_COMP );
	virtual bool ForceMove( TOGLTransf *OGLTransf, int ind, T3DPoint P, bool valid = true, bool tol = true, double vtol = RES_COMP );

	virtual void SetRealSize( bool b );

	virtual bool GetRealSize( )
	{
		return RectFormatData.IsRealSize;
	}
	virtual bool GetFillText( )
	{
		return RectFormatData.IsFillText;
	}
	virtual bool GetFillRect( )
	{
		return !RectFormatData.IsTransparent && OGLBackgroundMat.IsValid( );
	}
	virtual bool HasImage( )
	{
		return IsImageEnabled && OGLImageTextureList.Count( ) && OGLImageTextureList.GetItem( 0 )->IsValid( );
	}
	virtual bool HasBackgroundMat( )
	{
		return ( OGLBackgroundMat.IsValid( ) );
	}

	virtual void SetFillText( bool b );
	virtual void SetFillRect( bool b );
	virtual void SetFillAsMaterial( bool b );

	virtual bool GetUnderlineText( )
	{
		return RectFormatData.IsUnderline;
	}
	virtual void SetUnderlineText( bool b );

	virtual bool IsColumnText( )
	{
		return RectFormatData.ColumnText;
	}
	virtual void SetColumnText( bool c );

	void SetImage( UnicodeString name, UnicodeString texPath, bool shownameastext = false, int typeviews = IMAGE_PATH_REPORTS );

	virtual void SetTextVisible( bool b );
	virtual bool GetTextVisible( )
	{
		return IsTextVisible;
	}

	virtual void SetHasBorder( int b );
	virtual int GetHasBorder( )
	{
		return RectFormatData.HasBorder;
	}

	virtual void SetIsSelectableByArea( bool b )
	{
		RectFormatData.IsSelectableByArea = b;
	}
	virtual bool GetIsSelectableByArea( )
	{
		return RectFormatData.IsSelectableByArea;
	}

	virtual void SetIsTransparent( bool b );
	virtual bool GetIsTransparent( )
	{
		return RectFormatData.IsTransparent;
	}

	virtual void SetIsImageEnabled( bool b )
	{
		IsImageEnabled = b;
	}
	virtual bool GetIsImageEnabled( )
	{
		return IsImageEnabled;
	}
	virtual void SetImageMirrorX( bool b )
	{
		ImageMirrorX = b;
	}
	virtual bool GetImageMirrorX( )
	{
		return ImageMirrorX;
	}
	virtual void SetImageMirrorY( bool b )
	{
		ImageMirrorY = b;
	}
	virtual bool GetImageMirrorY( )
	{
		return ImageMirrorY;
	}

	virtual void SetDrawBorderRaster( bool b )
	{
		RectFormatData.DrawBorderRaster = b;
	}
	virtual bool GetDrawBorderRaster( )
	{
		return RectFormatData.DrawBorderRaster;
	}

	virtual void SetAdjustBoxToText( bool b );
	virtual bool GetAdjustBoxToText( )
	{
		return RectFormatData.AdjustBoxToText;
	}

	virtual void SetBorderWidth( double w );
	virtual double GetBorderWidth( )
	{
		return RectFormatData.BorderWidth;
	}

	virtual void SetLockType( int value )
	{
		LockType = value;
	}
	virtual int GetLockType( )
	{
		return LockType;
	}

	virtual void SetOpenAsSimple( int val )
	{
		OpenAsSimple = val;
	}
	virtual bool GetOpenAsSimple( )
	{
		return OpenAsSimple;
	}

	virtual bool UseLabel( );
	virtual TRectLabelData *GetRectLabelData( );
	virtual void SetRectLabelData( TRectLabelData *d );

	virtual void SetSpecialType( int value )
	{
		SpecialType = value;
	}
	virtual int GetSpecialType( )
	{
		return SpecialType;
	}
	virtual bool IsPageNumberRect( )
	{
		return SpecialType == PAGE_NUMBER_RECT;
	}

	virtual bool GetTrimTextToRect( )
	{
		return TrimTextToRect;
	}
	virtual void SetTrimTextToRect( bool ttr )
	{
		TrimTextToRect = ttr;
	}

	virtual void SetImageRealAlign( int a );
	virtual int GetImageRealAlign( )
	{
		return RectFormatData.ImageRealAlign;
	}

	// Alineamiento  del texto
	virtual void SetBoxAlign( int a );
	virtual int GetBoxAlign( )
	{
		return RectFormatData.BoxAlign;
	}
	//  horizontal
	virtual bool IsRightAlign( )
	{
		return ( RectFormatData.BoxAlign == ALIGNTYPE_TOPR || RectFormatData.BoxAlign == ALIGNTYPE_MIDR || RectFormatData.BoxAlign == ALIGNTYPE_BOTR );
	}
	virtual void SetRightAlign( );
	virtual bool IsLeftAlign( )
	{
		return ( RectFormatData.BoxAlign == ALIGNTYPE_TOPL || RectFormatData.BoxAlign == ALIGNTYPE_MIDL || RectFormatData.BoxAlign == ALIGNTYPE_BOTL );
	}
	virtual void SetLeftAlign( );
	virtual bool IsCenterAlign( )
	{
		return ( RectFormatData.BoxAlign == ALIGNTYPE_TOPM || RectFormatData.BoxAlign == ALIGNTYPE_MIDM || RectFormatData.BoxAlign == ALIGNTYPE_BOTM );
	}
	virtual void SetCenterAlign( );
	// vertical
	virtual bool IsTopAlign( )
	{
		return ( RectFormatData.BoxAlign == ALIGNTYPE_TOPR || RectFormatData.BoxAlign == ALIGNTYPE_TOPM || RectFormatData.BoxAlign == ALIGNTYPE_TOPL );
	}
	virtual void SetTopAlign( );
	virtual bool IsMiddleAlign( )
	{
		return ( RectFormatData.BoxAlign == ALIGNTYPE_MIDR || RectFormatData.BoxAlign == ALIGNTYPE_MIDM || RectFormatData.BoxAlign == ALIGNTYPE_MIDL );
	}
	virtual void SetMiddleAlign( );
	virtual bool IsBottomAlign( )
	{
		return ( RectFormatData.BoxAlign == ALIGNTYPE_BOTR || RectFormatData.BoxAlign == ALIGNTYPE_BOTM || RectFormatData.BoxAlign == ALIGNTYPE_BOTL );
	}
	virtual void SetBottomAlign( );

	virtual void SetOrientationText( int a );
	virtual int GetOrientationText( )
	{
		return RectFormatData.OrientationText;
	}

	virtual void SetImageAlign( int );
	virtual int GetImageAlign( )
	{
		return RectFormatData.ImageAlign;
	}
	virtual void AlignToImage( );
	virtual void GetRectImageBox( T3DPoint *box );

	virtual void SetSplitMode( int sm );
	virtual int GetSplitMode( )
	{
		return SplitMode;
	}

	virtual void SetApplyMatMode( int sm );
	virtual int GetApplyMatMode( )
	{
		return ApplyMatMode;
	}

	virtual void SetMargins( TLRect m );
	virtual TLRect GetMargins( )
	{
		return RectFormatData.Margins;
	}

	virtual void SetProps( LOGFONT *, UnicodeString str, TColor c = clBlack, TColor *bc = 0, TColor *bgc = 0 );
	virtual UnicodeString GetProps( LOGFONT *logFont, TColor *color = 0, TColor *bcolor = 0, TColor *bgcolor = 0 );

	virtual int GetVariation3D( )
	{
		return Variation3D;
	}
	virtual void SetVariation3D( int value )
	{
		Variation3D = value;
	}

	virtual void SetText( UnicodeString text );
	virtual UnicodeString GetText( )
	{
		return Text;
	}
	virtual void SetRectDescription( UnicodeString desc );
	virtual UnicodeString GetRectDescription( )
	{
		return RectDescription;
	}
	virtual void SetTextDirty( bool b );

	virtual void GetFont( LOGFONT *lf );
	virtual void SetFont( LOGFONT * );

	virtual bool GetTextColor( TColor *c );
	virtual void SetTextColor( TColor c );

	virtual bool GetBorderColor( TColor *c );
	virtual void SetBorderColor( TColor c );

	virtual bool GetBackgroundColor( TColor *c );
	virtual void SetBackgroundColor( TColor c );

	virtual TOGLPolygonList *GetOGLTextList( TOGLTransf *, bool recalc = true );
	TOGLPolygonList *GetOGLTextListStandard( TOGLTransf *, bool recalc = true );
	virtual void GetSeparatorLinePolygon( TOGLPolygon *pol, bool fillPol );

	virtual void AdjustTextToRect( TOGLTransf *OGLTransf );
	virtual void ApplyMargins( T3DPoint &pt );
	virtual void CalcRectBorder( TOGLTransf *OGLTransf );

	virtual int GetExpLinesListCount( TOGLTransf *OGLTransf );
	virtual int GetExpTrianglesListCount( TOGLTransf *OGLTransf );
	virtual void GetExpLinesList( TOGLTransf *OGLTransf, int index, vector<TOGLPoint> *v, vector<GLint> *vi, bool *isStipple = 0 );
	virtual void GetExpTrianglesList( TOGLTransf *OGLTransf, int index, vector<TOGLPoint> *v, vector<GLint> *vi, int comparemask = CMASK_V, bool checkdegeneratedtriangles = true, double prec = RES_COMP, TOGLPolygonList *secondlist = 0, vector<TOGLPoint> *secondv = 0, bool geometryRepair = false, TOGLMaterial *matToForceCalcTexCoords = 0 );
	virtual bool GetExpLinesListMat( TOGLTransf *OGLTransf, int index, TOGLMaterial *mat );		// retorna si se devuelve material especifico
	virtual bool GetExpTrianglesListMat( TOGLTransf *OGLTransf, int index, TOGLMaterial *mat ); // retorna si se devuelve material especifico

	int CalcOGLTextIntro( TOGLTransf *OGLTransf );
	TOGLPolygonList *GetRectBackgroundList( );
	virtual bool CanConvertToDual( );

	virtual void GetTextCurves( TOGLTransf *OGLTransf, TCadGroup *Curves );

	virtual void HMirror( TOGLTransf *, TNPlane forceplane = plNone );
	virtual void HMirror( TOGLTransf *, T3DPoint, T3DPoint, TNPlane forceplane = plNone );
	virtual void VMirror( TOGLTransf *, TNPlane forceplane = plNone );
	virtual void VMirror( TOGLTransf *, T3DPoint, T3DPoint, TNPlane forceplane = plNone );
	virtual void MirrorX0( TOGLTransf *, bool invertu = false, bool invertv = false, bool invert = true );
	virtual void MirrorY0( TOGLTransf *, bool invertu = false, bool invertv = false, bool invert = true );
	virtual void SymAxis( TOGLTransf *, T3DPoint *p1, T3DPoint *p2 );

	virtual void ApplyMatrix( TOGLTransf *, TNMatrix *, bool recaldev = true, bool canusepbrep = true );
	virtual void ApplyMatrix( TOGLTransf *OGLTransf, TNMatrix *mat, int iStart, int iEnd = -1 );

	virtual void FillProp_General( TFormEntityData *properties );

	virtual UnicodeString WhoAmI( )
	{
		return ST_RECT;
	}
	virtual UnicodeString WhoIDSAmI( )
	{
		return "IDS_ST_RECT";
	}

	virtual bool AmIStrictPolyline( )
	{
		return false;
	}
	virtual bool AmIStrictRect( )
	{
		return true;
	}
	virtual bool CanConvertTo( TOGLTransf *, int dtype )
	{
		return false;
	}

	virtual TCadGroup *GetGeometryGroup( )
	{
		return &GeometryGroup;
	}
};

//------------------------------------------------------------------------------
// TCadRoundRect
//------------------------------------------------------------------------------

class TCadRoundRect : public TCadRect
{
	friend class TImpExp_XML;

  protected:
	TLPoint EllipseSize; // Tamanyo de la elipse que redondea el rectangulo

  protected:
	virtual bool CalcSISLCurve( TOGLTransf *, double *epar = 0 );

  public:
	TCadRoundRect( int pt = DEFAULT_PARAM_TYPE, int d = DEFAULT_DEGREE, const TLPoint &R = TLPoint( 0.5, 0.5 ), TNPlane plane = plXY ): TCadRect( pt, d, plane )
	{
		EllipseSize = R;
	};
	TCadRoundRect( T3DPoint &P, T3DPoint &Q, int pt = DEFAULT_PARAM_TYPE, int d = DEFAULT_DEGREE, const TLPoint &R = TLPoint( 0.5, 0.5 ), TNPlane plane = plXY ): TCadRect( P, Q, pt, d, plane )
	{
		EllipseSize = R;
	};
	TCadRoundRect( TCadRoundRect *S );
	virtual ~TCadRoundRect( )
	{
	}

	virtual void Set( TCadEntity *, bool copyrels );
	virtual void SetBasic( TCadEntity *, bool copyrels );
	virtual void SetBasicGeometry( TCadEntity *S );

	void SetRadius( TLPoint R );
	TLPoint GetRadius( )
	{
		return EllipseSize;
	}

	virtual void FillProp_Geom( TOGLTransf *OGLTransf, TFormEntityData *properties );

	virtual UnicodeString WhoAmI( )
	{
		return ST_ROUNDRECT;
	};
	virtual UnicodeString WhoIDSAmI( )
	{
		return "IDS_ST_ROUNDRECT";
	}

	virtual bool AmIStrictRect( )
	{
		return false;
	}
	virtual bool AmIStrictRoundRect( )
	{
		return true;
	}
};

//------------------------------------------------------------------------------
// TCadEllipse
//------------------------------------------------------------------------------

class TCadEllipse : public TCadRect
{
  protected:
	virtual bool CalcSISLCurve( TOGLTransf *, double *epar = 0 );
	virtual bool CalcOGLPolygon( TOGLTransf *OGLTransf )
	{
		return TCadShape::CalcOGLPolygon( OGLTransf );
	}

  public:
	TCadEllipse( int pt = DEFAULT_PARAM_TYPE, int d = DEFAULT_DEGREE, TNPlane plane = plXY ): TCadRect( pt, d, plane )
	{
	}
	TCadEllipse( T3DPoint &P, T3DPoint &Q, int pt = DEFAULT_PARAM_TYPE, int d = DEFAULT_DEGREE, TNPlane plane = plXY ): TCadRect( P, Q, pt, d, plane )
	{
	}
	TCadEllipse( TCadEllipse *S ): TCadRect( S )
	{
	}
	virtual ~TCadEllipse( )
	{
	}

	virtual void Set( TCadEntity *Ent, bool copyrels )
	{
		TCadRect::Set( Ent, copyrels );
	}
	virtual void SetBasic( TCadEntity *Ent, bool copyrels )
	{
		TCadRect::SetBasic( Ent, copyrels );
	}

	virtual void SelectOGL( TOGLTransf *, int, int, TOGLRenderData *, TOGLRenderSystem *, TInteger_List * = 0 );

	virtual UnicodeString WhoAmI( )
	{
		return ST_ELLIPSE;
	}
	virtual UnicodeString WhoIDSAmI( )
	{
		return "IDS_ST_ELLIPSE";
	}

	virtual TCadEntity *GetIBSpline( TOGLTransf *, bool, bool onlyone = true );

	virtual int GetExpLinesListCount( TOGLTransf *OGLTransf );
	virtual int GetExpTrianglesListCount( TOGLTransf *OGLTransf );
	virtual void GetExpLinesList( TOGLTransf *OGLTransf, int index, vector<TOGLPoint> *v, vector<GLint> *vi, bool *isStipple = 0 );
	virtual void GetExpTrianglesList( TOGLTransf *OGLTransf, int index, vector<TOGLPoint> *v, vector<GLint> *vi, int comparemask = CMASK_V, bool checkdegeneratedtriangles = true, double prec = RES_COMP, TOGLPolygonList *secondlist = 0, vector<TOGLPoint> *secondv = 0, bool geometryRepair = false, TOGLMaterial *matToForceCalcTexCoords = 0 );
	virtual bool GetExpLinesListMat( TOGLTransf *OGLTransf, int index, TOGLMaterial *mat );		// retorna si se devuelve material especifico
	virtual bool GetExpTrianglesListMat( TOGLTransf *OGLTransf, int index, TOGLMaterial *mat ); // retorna si se devuelve material especifico

	virtual bool AmIStrictRect( )
	{
		return false;
	}
	virtual bool AmIStrictEllipse( )
	{
		return true;
	}
};

//------------------------------------------------------------------------------
// TCadPuller
//------------------------------------------------------------------------------

class TCadPuller : public TCadRect
{
  protected:
	virtual bool CalcSISLCurve( TOGLTransf *, double * = 0 );

	void RecalcPoints( TOGLTransf * );
	//		T3DPoint Center( const int, const float );

  public:
	TCadPuller( T3DPoint &, T3DPoint &, int pt = DEFAULT_PARAM_TYPE, int d = DEFAULT_DEGREE );
	virtual ~TCadPuller( )
	{
	}

	virtual bool CalcBoundRect( TOGLTransf *, T3DRect &, bool outrange = false, TNMatrix *mat = 0 );

	virtual void SelectOGL( TOGLTransf *, int, int, TOGLRenderData *, TOGLRenderSystem *, TInteger_List * = 0 );

	virtual void Move( TOGLTransf *OGLTransf, T3DPoint P )
	{
		TCadRect::Move( OGLTransf, P );
	}
	virtual bool Move( TOGLTransf *, int, T3DPoint, bool valid = true, bool tol = true, double vtol = RES_COMP );

	virtual UnicodeString WhoAmI( )
	{
		return ST_PULLER;
	}
	virtual UnicodeString WhoIDSAmI( )
	{
		return "IDS_ST_PULLER";
	}

	virtual bool AmIStrictRect( )
	{
		return false;
	}
	virtual bool AmIStrictPuller( )
	{
		return true;
	}

	virtual bool AllowMarkers( )
	{
		return false;
	}
};

//------------------------------------------------------------------------------
// TCadText
//------------------------------------------------------------------------------

class TCadText : public TCadRect
{
	friend class TImpExp_XML;

  protected:
	virtual bool CalcSISLCurve( TOGLTransf *, double *epar = 0 );
	virtual bool CalcOGLPolygon( TOGLTransf * );

	virtual void CalcOGLText( TOGLTransf *OGLTransf );

  public:
	TCadText( int pt = DEFAULT_PARAM_TYPE, int d = DEFAULT_DEGREE, TNPlane plane = plXY );
	TCadText( T3DPoint &P, T3DPoint &Q, int pt = DEFAULT_PARAM_TYPE, int d = DEFAULT_DEGREE, TNPlane plane = plXY );
	TCadText( TCadText *S );
	virtual ~TCadText( )
	{
	}

	virtual bool CalcBoundRect( TOGLTransf *, T3DRect &, bool outrange = false, TNMatrix *mat = 0 );
	virtual bool CalcBoundRectParam( TOGLTransf *, T3DRect &, bool outrange = false, TNMatrix *mat = 0 );
	virtual bool CalcBoundRectViewport( TOGLTransf *, TLRect &, int step = 1, TNMatrix *MirrorMat = 0, TInstanceList *list = 0 );

	virtual void DrawOGL( TOGLTransf *OGLTransf, TOGLRenderData *_OGLRdData, TOGLRenderSystem *_OGLRdSystem );
	virtual bool AddChar( char );

	virtual int GetExpLinesListCount( TOGLTransf *OGLTransf );
	virtual int GetExpTrianglesListCount( TOGLTransf *OGLTransf );
	virtual void GetExpLinesList( TOGLTransf *OGLTransf, int index, vector<TOGLPoint> *v, vector<GLint> *vi, bool *isStipple = 0 );
	virtual void GetExpTrianglesList( TOGLTransf *OGLTransf, int index, vector<TOGLPoint> *v, vector<GLint> *vi, int comparemask = CMASK_V, bool checkdegeneratedtriangles = true, double prec = RES_COMP, TOGLPolygonList *secondlist = 0, vector<TOGLPoint> *secondv = 0, bool geometryRepair = false, TOGLMaterial *matToForceCalcTexCoords = 0 );
	virtual bool GetExpLinesListMat( TOGLTransf *OGLTransf, int index, TOGLMaterial *mat );		// retorna si se devuelve material especifico
	virtual bool GetExpTrianglesListMat( TOGLTransf *OGLTransf, int index, TOGLMaterial *mat ); // retorna si se devuelve material especifico

	bool CanUseFillList( TOGLTransf *OGLTransf );
	bool MustCreateOGLFillList( TOGLTransf *OGLTransf );

	virtual UnicodeString WhoAmI( )
	{
		return ST_TEXT;
	};
	virtual UnicodeString WhoIDSAmI( )
	{
		return "IDS_ST_TEXT";
	}

	virtual bool AmIStrictRect( )
	{
		return false;
	}
	virtual bool AmIStrictText( )
	{
		return true;
	}
};

//------------------------------------------------------------------------------
// TCadDepShape
//------------------------------------------------------------------------------

class TCadDepShape : public TCadShape
{
	friend class TImpExp_XML;

  protected:
	TCadGroup BaseEntities;
	TParallelData ParallelData;
	TParallelTypeData ParallelTypeData;
	TSymmetricData SymmetricData;
	TIntersectDataList PolyData;
	TMarkersData MarkersData;
	TIntersectPlaneData IntersectPlaneData;
	TRotationData RotationData;
	TPctData PctData;
	TCopyData CopyData;
	TCopyListData CopyListData;
	TReallocateData ReallocateData;
	TGrading2DData Grading2DData;
	TCenterLineData CenterLineData;
	TAngleLineData AngleLineData;
	TSmoothInterData SmoothInterData;
	TIntersectPointData IntersectPointData;
	TTessLocationData TessLocationData;

	bool InvertDepShape;
	bool LinkDual;
	TOGLPolygonList *TempAuxListShape;

	bool IsTessLocationDirty;
	bool LockTessLocationDirty;

  protected:
	virtual bool CalcOGLLists( TOGLTransf * );
	virtual bool CalcSISLCurve( TOGLTransf *, double * = 0 );
	virtual bool CalcOGLPolygon( TOGLTransf * );

	virtual void CalcDualAsBase( TOGLTransf *OGLTransf );

	virtual void CalcOGLPolygonDevToParam( TOGLTransf * );
	virtual bool CalcOGLPolygonDevToParamUnlinked( TOGLTransf * );
	virtual void CalcOGLPolygonParamToDev( TOGLTransf * );
	virtual bool CalcOGLPolygonParamToDevUnlinked( TOGLTransf * );
	virtual void CalcOGLPolygonParallel( TOGLTransf * );
	virtual void CalcOGLPolygonParallelNormal( TOGLTransf *OGLTransf );
	virtual void CalcOGLPolygonParallelGeom3D( TOGLTransf *OGLTransf );
	virtual void CalcOGLPolygonSymmetric( TOGLTransf * );
	virtual void CalcOGLPolygonPoly( TOGLTransf * );
	virtual void CalcOGLPolygonMarkers( TOGLTransf * );
	virtual void CalcOGLPolygonIntersectPlane( TOGLTransf * );
	virtual void CalcOGLPolygonCopy( TOGLTransf * );
	virtual void CalcOGLPolygonCopyList( TOGLTransf * );
	virtual void CalcOGLPolygonBaseSegment( TOGLTransf * );
	virtual void CalcOGLPolygonSegment( TOGLTransf * );
	virtual void CalcOGLPolygonRotation( TOGLTransf * );
	virtual void CalcOGLPolygonRotationAngle( TOGLTransf *OGLTransf );
	virtual void CalcOGLPolygonRotationIncr( TOGLTransf *OGLTransf );
	virtual void CalcOGLPolygonRotationAxis( TOGLTransf *OGLTransf );
	virtual void CalcOGLPolygonRotationAxisGroup( TOGLTransf *OGLTransf, TCadGroup *Group );
	virtual void CalcOGLPolygonRotationCurve( TOGLTransf *OGLTransf );
	virtual void CalcOGLPolygonPct( TOGLTransf * );
	virtual void CalcOGLPolygonReallocate( TOGLTransf * );
	virtual void CalcOGLPolygonGrading2DBasic( TOGLTransf * );
	virtual void CalcOGLPolygonGrading2DLocation( TOGLTransf * );
	virtual void CalcOGLPolygonCenterLine( TOGLTransf *OGLTransf );
	virtual void CalcOGLPolygonAngleLine( TOGLTransf *OGLTransf );
	virtual void CalcOGLPolygonSmoothInter( TOGLTransf *OGLTransf );
	virtual void CalcOGLPolygonIntersectPoint( TOGLTransf *OGLTransf );
	virtual void CalcOGLPolygonTessLocationBoundaries( TOGLTransf * );

	virtual bool CalcOGLInflatedLine( TOGLTransf *OGLTransf, int indextool, TShapeElement *se, bool baseshape, TOGLPolygon *pol );
	virtual bool CalcOGLInflatedLines( TOGLTransf *OGLTransf, int indextypelist, TShapeElement *se, bool baseshape, TOGLPolygonList *list );
	virtual void CalcOGLDepMarkersLines( TOGLTransf *OGLTransf, TShapeElement *se, double pct1, double pct2, bool candividese = true, bool candividepcts = true, bool onlybaseline = false );

	virtual bool CalcOGLWave( TOGLTransf *OGLTransf, TShapeElement *se, TOGLPolygon *pol );
	virtual void CalcOGLDepMarkersWaves( TOGLTransf *OGLTransf, TShapeElement *se, double pct1, double pct2 );

	virtual bool CalcOGLCircle2D( TOGLTransf *OGLTransf, int indextool, TShapeElement *se, TOGLFloat3 *vtx );
	virtual bool CalcOGLCircle3D( TOGLTransf *OGLTransf, int indextool, TShapeElement *se, TOGLFloat2 *v2d, bool calcdev = false );
	virtual void CalcOGLDepMarkersCircles( TOGLTransf *OGLTransf, TShapeElement *se, double pct1, double pct2, bool candividese = true, bool candividepcts = true, bool onlybaseline = false );
	virtual void CalcOGLDepMarkersCircles_OnInters( TOGLTransf *OGLTransf, TShapeElement *se, double _pct1, double _pct2 );
	virtual void CalcOGLDepMarkersCircles_OnPoints( TOGLTransf *OGLTransf, TShapeElement *se, double _pct1, double _pct2 );

	virtual void CalcOGLDepMarkersText( TOGLTransf *OGLTransf, TShapeElement *se, double pct );
	virtual void CalcOGLDepMarkersTextAutoPos( TOGLTransf *OGLTransf, TShapeElement *se );
	virtual void CalcOGLDepMarkersTextCadText( TOGLTransf *OGLTransf, TShapeElement *se );

	virtual void CalcOGLDepMarkersArea( TOGLTransf *OGLTransf, TShapeElement *se, double _pct1, double _pct2 );

	virtual bool CalcOGLMark2D( TOGLTransf *OGLTransf, TShapeElement *se, double *pct, TOGLFloat3 *vec, TOGLFloat3 *vecn, char customizedSymbol = 0, bool isSmall = false, bool issymbolic = false, double smallpct = 0.5 );
	virtual bool CalcOGLMark3D( TOGLTransf *OGLTransf, TShapeElement *se, int *ind, double *pct, TOGLFloat3 *vec, TOGLFloat3 *vecn, TOGLFloat2 *v2d );
	virtual void CalcOGLDepMarkersMark( TOGLTransf *OGLTransf, TShapeElement *se, double pct1, TPointMarker *pminter, bool issym = false, T3DPoint *symnormal = 0 );
	virtual void CalcOGLDepMarkersMarkSegment( TOGLTransf *OGLTransf, TShapeElement *se, double pct1, double pct2, bool candividese = true );

	virtual bool CalcOGLFestoon2D( TOGLTransf *OGLTransf, double orgpct1, double orgpct2, TShapeElement *se, int count, TOGLFloat3 *vec, TOGLFloat3 *vecn, TOGLPolygonList *extremelist );
	virtual bool CalcOGLFestoon3D( TOGLTransf *OGLTransf, double orgpct1, double orgpct2, TShapeElement *se, int count, TOGLFloat3 *vec, TOGLFloat3 *vecn, TOGLFloat2 *v2d, TOGLPolygonList *extremelist );
	virtual void CalcOGLDepMarkersFestoon( TOGLTransf *OGLTransf, TShapeElement *se, double pct1, double pct2, TLineMarker *lm );

	virtual void CalcOGLDepMarkersSymbolic( TOGLTransf *OGLTransf, TShapeElement *se, double pct1 );

	virtual bool CalcOGLSoften2D( TOGLTransf *OGLTransf, TShapeElement *se, double *pct, TOGLFloat3 *vec, TOGLFloat3 *vecn );
	virtual bool CalcOGLSoften3D( TOGLTransf *OGLTransf, TShapeElement *se, int *ind, double *pct, TOGLFloat3 *vec, TOGLFloat3 *vecn, TOGLFloat2 *v2d );
	virtual void CalcOGLDepMarkersSoften( TOGLTransf *OGLTransf, TShapeElement *se, double pct1, bool issym = false );
	virtual void CalcOGLPolygonMarkersSoften( TOGLTransf *OGLTransf );

	virtual void CalcOGLDepMarkersInsides( TOGLTransf *OGLTransf, TShapeElement *se, double pct1, double pct2, bool candividepcts = true );
	virtual TNMatrix CalcOGLDepMarkersInsidesParamMatrix( TOGLTransf *OGLTransf, TCadTrimSurface *trim, double pct, double angle, double &calcAngle, TOGLFloat2 *v2d, TOGLFloat2 *v2dIncr, bool invertNormal, bool forcedevsurfindex, int devsurfindex );
	virtual TNMatrix CalcOGLDepMarkersInsidesDevMatrix( T3DPoint pt, T3DPoint normal, double angle, double &calcAngle, bool invertNormal );

	virtual void CalcOGLDepMarkersBasePoints( TOGLTransf *OGLTransf, TShapeElement *se, double pct1 );
	virtual void CalcOGLDepMarkersBaseLines( TOGLTransf *OGLTransf, TShapeElement *se, double pct1, double pct2 );

	virtual void DivideShapeElementLines( TOGLTransf *OGLTransf, TShapeElement *se, double _pct1, double _pct2, TMarkerList *markerlist );
	virtual void DivideShapeElementCircles( TOGLTransf *OGLTransf, TShapeElement *se, double _pct1, double _pct2, TMarkerList *markerlist );
	virtual void DivideShapeElementInsides( TOGLTransf *OGLTransf, TShapeElement *se, double _pct1, double _pct2, TMarkerList *markerlist );

	virtual bool DivideShapeElementMarksByFitInters( TOGLTransf *OGLTransf, TShapeElement *se, double pct1, double pct2, TMarkerList *markerlist );
	virtual bool DivideShapeElementCirclesByFitInters( TOGLTransf *OGLTransf, TShapeElement *se, double pct1, double pct2, TMarkerList *markerlist );
	virtual bool MustDivideByInters( TShapeElement *se );
	virtual bool DivideShapeElementLinesByInters( TOGLTransf *OGLTransf, TShapeElement *se, double _pct1, double _pct2, TMarkerList *markerlist, TCadGroup *grp, TOGLPolygonListList *ogllistlist );
	virtual bool DividePctsByDistMinContour( TOGLTransf *OGLTransf, TShapeElement *se, double _pct1, double _pct2, TNDoublesList *pctlist );

	virtual bool GetTrimToDevelop( TOGLTransf *OGLTransf, TCadSurface *paramsurf, TOGLFloat2 *vtxparam, bool forcedevsurfindex, int devsurfindex, TOGLPolygonList *DevList, TCadTrimSurface **Trim );

  public:
	TCadDepShape( int pt = DEFAULT_PARAM_TYPE, int d = DEFAULT_DEGREE, int i = 0 );
	TCadDepShape( T3DPoint &P, int pt = DEFAULT_PARAM_TYPE, int d = DEFAULT_DEGREE );
	TCadDepShape( int deptype, TCadEntity *baseent, TOGLTransf *OGLTransf );
	TCadDepShape( int deptype, TOGLPolygonList *OGLList );
	TCadDepShape( TCadDepShape *S );
	virtual ~TCadDepShape( )
	{
	}

	virtual int GetDualID( );

	virtual void Set( TCadEntity *Ent, bool copyrels );
	virtual void SetBasic( TCadEntity *, bool copyrels );
	virtual void SetBasicGeometry( TCadEntity *S ); // solo para las copylist
	virtual void SetBasicRels( TCadEntity *S );
	virtual void ChangeBasicRels( TCadEntity *orgbaseent, TCadEntity *dstbaseent, bool updatedirty = true, bool setdirty = false );
	virtual void GetBasicRelsEnts( TCadGroup *grp, bool usesurf = true, bool usemainaxissurf = true );

	virtual bool AddPointRelation( TOGLTransf *OGLTransf, TPointRelation *pr, int pmv = -1, int ed = -1 );
	virtual bool SetPointRelation( TOGLTransf *OGLTransf, int index, TPointRelation *pr, int pmv = -1, int ed = -1 );
	virtual bool DelPointRelation( TOGLTransf *OGLTransf, int index, int pmv = -1, int ed = -1 );
	virtual bool InsertPointRelation( TOGLTransf *OGLTransf, int index, TPointRelation *pr, int pmv = -1, int ed = -1 );

	virtual bool MustCalcDualAsNotDual( );
	virtual bool MustCalcOGLLists( TOGLRenderSystem * );

	virtual void SetSISLDirty( bool b, bool increasedirtyid = true );
	virtual void SetPolygonDirty( bool b, bool increasedirtyid = true );
	virtual void SetMarkersDepShapesDirty( bool increasedirtyid = true );

	virtual void SetLockUpdateData( TOGLTransf *, bool, bool onlyset = false );

	virtual void SetParamOffset( double d );
	virtual void SetDevelopable( bool dev );
	virtual void SetDevelopSurfIndex( int index );
	virtual void SetForceDevelopSurfIndex( bool value );
	virtual void SetParamInterpolationMode( int mode );
	virtual bool GetForceDevelopSurfIndex( );
	virtual int GetDevelopSurfIndex( );
	virtual int GetDevelopSurfIndexByPoint( TOGLTransf *OGLTransf, T3DPoint pt );

	virtual T3DPoint GetDataPoint( TOGLTransf *, int i );
	virtual bool GetDataPoint( TOGLTransf *, int i, T3DPoint &P );
	virtual T3DPoint GetAuxData( TOGLTransf *, int i );
	virtual void SetCorner( int i, bool c );
	virtual bool GetDataCorner( int i );
	virtual void ClearDataEdition( );
	virtual bool IsNormalEdition( )
	{
		return TCadShape::IsNormalEdition( );
	}
	virtual bool IsNormalEdition( int );

	virtual void MoveParamCenter( TOGLTransf *OGLTransf, double *limitsUV, TLPoint orgcenter, TLPoint dstcenter );
	virtual bool AlignCurve( TOGLTransf *, int first = -1, int last = -1, TNPlane pl = plXY );

	virtual TPointRelationList *GetPointRelationList( );

	virtual void SetClose( int );
	virtual int GetClose( TOGLTransf *OGLTransf = 0 );
	virtual int GetCloseExt( TOGLTransf * );
	virtual int GetIndexToAdd( TOGLTransf *, T3DPoint, TNPlane NPlane = plNone, bool forcepersp = false );

	virtual bool GetSymInvertDevelopSide( ); // Actualiza la version si procede

	virtual void SetInvertDepShape( bool value );
	virtual bool GetInvertDepShape( );
	virtual void ApplyInvertDepShape( );

	virtual void SetLinkDual( bool value, bool alldirty = true, bool updateauxdata = true );
	virtual bool GetLinkDual( );

	virtual bool CanUseTrimPcts( bool calcoglpolygon = false );

	virtual void CleanGroups( );
	virtual void GetDownRelatedEntities( TOGLTransf *OGLTransf, TCadGroup *Group, HLAYER *excludelayer = 0, bool force = false );
	virtual void GetUpRelatedEntities( TCadGroup *Group, bool rels = true, bool pointRels = true );
	virtual bool HasUpRelatedEntities( bool rels = true, bool pointRels = true, bool excludeparamsurf = false );
	virtual void DetachUpRelations( TCadGroup *, TPointRelationList *, TEntityRelationList *, bool updatedirty = true );
	virtual void ChangeOwnRelatedEntity( TCadEntity *ent );
	virtual void ChangeRelatedEntity( TCadEntity *orgent, TCadEntity *dstent, TCadGroup *gr = 0, bool setdirty = false );
	virtual bool ChangeRelatedEntityPoly( TOGLTransf *OGLTransf, TCadEntity *orgent, TCadEntity *dstent );
	virtual void ClearOwnRelations( );

	virtual int Add( TOGLTransf *, T3DPoint, bool = false, int = -1, int = EDIT_POINT_NORMAL, bool = true, bool = true, double vtol = RES_COMP );
	virtual bool Delete( int );
	virtual void Clear( );
	virtual void ClearCorners( );

	virtual void CalcMarkerListsPoints( TOGLTransf *OGLTransf, bool isparam, TInteger_List *forcetypes, bool checkextremes, TCadGroup *group, bool forcedev = false );
	virtual void CalcMarkerListsPoints( TOGLTransf *OGLTransf, bool isparam, TInteger_List *forcetypes = 0, bool checkextremes = true, bool forcedev = false );
	virtual void CalcMarkerListsPcts( TOGLTransf *OGLTransf, bool isparam, TInteger_List *forcetypes = 0, bool checkextremes = true, bool forcedev = false );

	virtual bool Move( TOGLTransf *, int, T3DPoint, bool valid = true, bool tol = true, double vtol = RES_COMP );
	virtual void Move( TOGLTransf *, T3DPoint );
	virtual bool MoveFromTo( TOGLTransf *, T3DPoint org, T3DPoint dst );
	virtual void MoveFromToArea( TOGLTransf *, T3DPoint org, T3DPoint dst, TCadShape *area, TInteger_List *ptslist );
	virtual void ApplyMatrixArea( TOGLTransf *OGLTransf, TNMatrix *matrix, TCadShape *area, TInteger_List *ptslist );
	virtual bool IsTouchedByArea( TOGLTransf *OGLTransf, TCadShape *area, TInteger_List *ptslist );
	virtual bool MoveSegmentFromTo( TOGLTransf *OGLTransf, T3DPoint org, T3DPoint dst, int first, int last );
	virtual void FitToRect( TOGLTransf *, T3DPoint, T3DPoint );
	virtual void HMirror( TOGLTransf *, TNPlane forceplane = plNone );
	virtual void HMirror( TOGLTransf *, T3DPoint, T3DPoint, TNPlane forceplane = plNone );
	virtual void VMirror( TOGLTransf *, TNPlane forceplane = plNone );
	virtual void VMirror( TOGLTransf *, T3DPoint, T3DPoint, TNPlane forceplane = plNone );
	virtual void MirrorX0( TOGLTransf *, bool invertu = false, bool invertv = false, bool invert = true );
	virtual void MirrorY0( TOGLTransf *, bool invertu = false, bool invertv = false, bool invert = true );
	virtual void SymAxis( TOGLTransf *, T3DPoint *p1, T3DPoint *p2 );
	virtual bool Rotate( TOGLTransf *, float, TNPlane, int fp = -1, int lp = -1 );
	virtual bool Rotate( TOGLTransf *, float, T3DPoint, TNPlane, int fp = -1, int lp = -1 );
	virtual bool RotateFromTo( TOGLTransf *OGLTransf, TNPlane plane, T3DPoint ct, T3DPoint org, T3DPoint dst, int fp, int lp, double &angle, T3DVector *rotAxis = NULL );
	virtual void RotateFromToArea( TOGLTransf *OGLTransf, TNPlane plane, T3DPoint ct, T3DPoint org, T3DPoint dst, TCadShape *area, TInteger_List *ptslist );
	virtual void Invert( TOGLTransf * );
	virtual void InvertCoordsUV( );
	virtual void InvertCoord( int, double, double )
	{
	}
	virtual void DefineAsFirstPoint( int index );
	virtual void ApplyMatrix( TOGLTransf *, TNMatrix *, bool recaldev = true, bool canusepbrep = true );
	virtual void ApplyMatrix( TOGLTransf *OGLTransf, TNMatrix *mat, int iStart, int iEnd = -1 );

	virtual TCadEntity *GetIBSpline( TOGLTransf *, bool, bool onlyone = true );
	virtual TCadEntity *GetNewGeomEntity( TOGLTransf * );
	virtual TCadEntity *GetNewGeomEntityFromDevelop( TOGLTransf * )
	{
		return 0;
	}

	virtual void SetOwnOGLRenderData( bool o );
	virtual void SetOGLRenderData( TOGLRenderData *oglrddata );
	virtual void Download_glList( );
	virtual void Download( );

	virtual void UpdateStipple( TOGLRenderData *, TOGLRenderSystem * );
	virtual void UpdatePenStyle( TOGLRenderData *_OGLRdData, TOGLRenderSystem *_OGLRdSystem, TPenStyle *penstyle );
	virtual TCadEntity *GetEntityToDrawOGLMarkers( );
	virtual bool MustDrawOGLMarkers( TOGLTransf *OGLTransf, TOGLRenderSystem *_OGLRdSystem );
	virtual bool MustDrawOGLMarkersSymbolic( TOGLTransf *OGLTransf, TOGLRenderSystem *_OGLRdSystem );
	virtual void DrawOGLMarkers( TOGLTransf *OGLTransf, TOGLRenderSystem *_OGLRdSystem, int forcetype = MK_MODE_NONE, int forceind = -1 );
	virtual void DrawOGL( TOGLTransf *OGLTransf, TOGLRenderData *_OGLRdData, TOGLRenderSystem *_OGLRdSystem );
	virtual void DrawOGLPolygon( TOGLTransf *OGLTransf, TOGLRenderData *, TOGLRenderSystem *, bool, bool = true );
	virtual void DrawOGLStartPointAndDirection( TOGLTransf *OGLTransf, TOGLRenderSystem *_OGLRdSystem );
	virtual void SelectOGL( TOGLTransf *, int, int, TOGLRenderData *, TOGLRenderSystem *, TInteger_List * = 0 );
	virtual void ApplyOGLRenderData( TOGLTransf *, TOGLRenderData *, TOGLRenderSystem *, bool &applytexturecoords );

	virtual TMarkerList *GetMarkerList( );
	virtual bool GetOGLPointFromMarker( TOGLTransf *OGLTransf, int index, TOGLPoint *oglpt );

	virtual int GetCurvesAmount( );
	virtual int GetSISLCurvesAmount( );
	virtual void GetCurves( TCadGroup *Gr )
	{
	}

	virtual TCadGroup *GetBaseEntities( )
	{
		return &BaseEntities;
	}
	virtual void SetBaseEntity( TCadEntity *ent );
	virtual TCadEntity *GetBaseEntity( );
	virtual TCadPoint *GetBasePoint( );
	virtual TCadPolyline *GetBasePolyline( );

	virtual bool IsNodeDepShape( );
	virtual bool IsDualDepShape( );
	virtual bool IsParallelDepShape( );
	virtual bool IsSymmetricDepShape( );
	virtual bool IsPolyDepShape( );
	virtual bool IsMarkersDepShape( );
	virtual bool IsMarkersDepShapeContour( TOGLTransf *OGLTransf, bool strict = false );
	virtual bool IsMarkersDepShapeInside( TOGLTransf *OGLTransf, bool strict = false );
	virtual bool IsMarkersDepShapeHideBaseLines( TOGLTransf *OGLTransf );
	virtual bool IsInvalidPolyDepShapeToMarkers( TOGLTransf *OGLTransf );
	virtual bool IsIntersectPlaneDepShape( );
	virtual bool IsCopyDepShape( );
	virtual bool IsCopyListDepShape( );
	virtual bool IsBaseSegmentDepShape( );
	virtual bool IsSegmentDepShape( );
	virtual bool IsRotationDepShape( );
	virtual bool IsRotationDepShapeAngle( );
	virtual bool IsRotationDepShapeIncr( );
	virtual bool IsRotationDepShapeAxis( );
	virtual bool IsRotationDepShapeCurve( );
	virtual bool IsRotationDepShapeBaseAxis( );
	virtual bool IsPctDepShape( );
	virtual bool IsPctDepShapeAxis( );
	virtual bool IsReallocateDepShape( );
	virtual bool IsReallocateDepShapeAxis( );
	virtual bool IsGrading2DDepShape( );
	virtual bool IsGrading2DBasicDepShape( );
	virtual bool IsGrading2DLocationDepShape( );
	virtual bool IsCenterLineDepShape( );
	virtual bool IsAngleLineDepShape( );
	virtual bool IsSmoothInterDepShape( );
	virtual bool IsIntersectPointDepShape( );
	virtual bool IsTessLocationBoundariesDepShape( );

	virtual bool HasStipplePatternDepMesh( );
	virtual bool HasLocation3DDepMesh( );
	virtual bool HasSweepDepMesh( );
	virtual bool HasLocation3DOnLineDepMesh( );
	virtual bool HasBaseDepRotation( );

	bool CanUseFillList( TOGLTransf *OGLTransf );
	bool MustCreateOGLFillList( TOGLTransf *OGLTransf );
	void CreateOGLFillList( TOGLTransf *OGLTransf );
	TShapeElement *GetOGLFillListSE( TOGLTransf *OGLTransf );

	virtual TCadEntity *GetDualBaseEntity( );
	virtual TCadShape *GetDualShapeByDep( );
	virtual TCadDepShape *GetDualDepShape( );
	virtual TCadShape *GetDualParamShapeByDep( );
	virtual TCadShape *GetDualGeomShapeByDep( );
	virtual TCadShape *GetDualParam2DShape( );
	virtual TCadShape *GetDualGeom3DShape( );

	virtual bool GetParamToDevShapes2D( TOGLTransf *OGLTransf, TCadGroup *shapesgrp );
	virtual bool GetDevToParamShapes2D( TOGLTransf *OGLTransf, TCadGroup *shapesgrp );

	virtual bool BasePointToDepPoint( TOGLTransf *OGLTransf, T3DPoint ptin, bool useforceinparam, T3DPoint &ptout, int *devsurfindex = 0 );
	virtual bool DepPointToBasePoint( TOGLTransf *OGLTransf, T3DPoint ptin, T3DPoint &ptout, int *devsurfindex = 0, bool checknodedepshape = true );
	virtual bool DepPctFromBasePct( TOGLTransf *OGLTransf, double pctin, double &pctout, bool *close = 0, TOGLPolygonList *DualGeom = 0, TOGLPolygonList *BaseGeom = 0, TOGLPolygonList *BaseParam = 0, double perBaseGeom = -1.0, bool avoidunlinkdual = true );
	bool BaseRelationToDepRelation( TOGLTransf *OGLTransf, TPointRelation *prIn, TPointRelation *prOut );

	virtual bool MustRevertEntity( TOGLTransf *OGLTransf );

	virtual bool IsEditable( );
	virtual bool IsIndependent( bool checkpointrels = true );
	virtual bool IsInactive( TOGLTransf * );
	virtual bool CanApplyTransform( bool checkpointrels = true );
	virtual bool CanConvertTo( TOGLTransf *OGLTransf, int dualityType );

	virtual bool IsInPlane( TOGLTransf *OGLTransf, T3DPlane &plane, double prec = RES_GEOM );
	virtual bool IsInPlane( TNPlane pl );

	virtual void FillProp( TOGLTransf *OGLTransf, TFormEntityData *properties );
	virtual void FillProp_General( TFormEntityData *properties );
	virtual void FillProp_Point( TOGLTransf *OGLTransf, int index, TFormEntityData *properties );
	virtual void FillProp_Segment( TOGLTransf *OGLTransf, int ind1, int ind2, TFormEntityData *properties );
	virtual void FillProp_Distance( TOGLTransf *OGLTransf, TDistanceData *distdata, bool copyList = false );

	virtual void SetDescription( UnicodeString description );
	virtual UnicodeString GetDescription( );
	virtual UnicodeString WhoAmI( )
	{
		return ST_DEPSHAPE;
	}
	virtual UnicodeString WhoIDSAmI( );

	virtual bool AmIStrictShape( )
	{
		return false;
	}
	virtual bool AmIStrictDepShape( )
	{
		return true;
	}

	virtual bool AllowMarkers( );

	virtual TParallelData *GetParallelData( );
	virtual void SetParallelData( TParallelData *parallelData );
	virtual void SetParallelSmoothFactor( double value );
	virtual void SetParallelInsideRoundDist( double value );
	virtual void SetParallelRoundCorners( bool value );
	virtual TParallelTypeData *GetParallelTypeData( );
	virtual void SetParallelTypeData( TParallelTypeData *parallelTypeData );

	virtual TSymmetricData *GetSymmetricData( );
	virtual void SetSymmetricData( TSymmetricData *data );
	virtual TCadShape *GetSymAxis( );
	virtual void SetSymAxis( TCadShape *axis );
	virtual void GetSymAxisPoints( TOGLTransf *OGLTransf, T3DPoint &pt1, T3DPoint &pt2 );

	virtual TRotationData *GetRotationData( );
	virtual void SetRotationData( TRotationData *data );
	virtual void SetRotShape1( TCadShape *shape );
	virtual TCadShape *GetRotShape1( );
	virtual void SetRotShape2( TCadShape *shape );
	virtual TCadShape *GetRotShape2( );
	virtual void SetRotZone1( TCadShape *shape );
	virtual TCadShape *GetRotZone1( );
	virtual void SetRotZone2( TCadShape *shape );
	virtual TCadShape *GetRotZone2( );
	virtual void SetRotAxis( TCadShape *shape );
	virtual TCadShape *GetRotAxis( );
	virtual TCadDepShape *GetBaseDepRotation( bool first = true );
	virtual double GetIncrDepRotation( TOGLTransf *OGLTransf, bool accum );

	virtual void CalcRotationPcts( TOGLTransf *OGLTransf, double *constantpcts, double *editedpcts );

	virtual TReallocateData *GetReallocateData( );
	virtual void SetReallocateData( TReallocateData *data );
	virtual TCadShape *GetReallocateEntity( int index );
	virtual void SetReallocateEntity( int index, TCadShape *axis );

	virtual TGrading2DData *GetGrading2DData( );
	virtual void SetGrading2DData( TGrading2DData *data );
	virtual TCadPoint *GetGrading2DLocationPoint( );
	virtual void SetGrading2DLocationPoint( TCadPoint *pt );

	virtual TCadLine *GetBaseAxis( );
	virtual bool GetMainAxis( );
	virtual bool GetInvertDevelopSideInAxis( );

	virtual TPctData *GetPctData( );
	virtual void SetPctData( TPctData *data );
	virtual T3DPoint GetPctDepShapeTangent( TOGLTransf *OGLTransf );

	virtual TCopyData *GetCopyData( );
	virtual void SetCopyData( TCopyData *data );

	virtual TCopyListData *GetCopyListData( );
	virtual void SetCopyListData( TCopyListData *data );

	virtual TCenterLineData *GetCenterLineData( );
	virtual void SetCenterLineData( TCenterLineData *data );

	virtual TAngleLineData *GetAngleLineData( );
	virtual void SetAngleLineData( TAngleLineData *data );

	virtual TSmoothInterData *GetSmoothInterData( );
	virtual void SetSmoothInterData( TSmoothInterData *data );
	virtual void UpdateSmoothInterByPcts( TOGLTransf *OGLTransf );

	virtual TIntersectPointData *GetIntersectPointData( );
	virtual void SetIntersectPointData( TIntersectPointData *data );

	virtual TTessLocationData *GetTessLocationData( );
	virtual void SetTessLocationData( TTessLocationData *data );
	virtual bool GetTessLocationDirty( );
	virtual void SetTessLocationDirty( bool value );
	virtual bool GetLockTessLocationDirty( );
	virtual void SetLockTessLocationDirty( bool value );
	virtual TCadDepMesh *GetTessLocationDepMeshInside( );

	virtual TIntersectDataList *GetPolyData( );
	virtual void SetPolyData( TIntersectDataList *data );
	virtual bool RecalcPolyData( TOGLTransf *OGLTransf, TCadSurface *surf, TIntersectDataList *polydata, bool toparam, TCadDepShape *orgpolyshape );
	virtual void AddPolyMarkers( bool all );
	virtual void RecalcPolyMarkers( TIntersectDataList *polydata, bool force = false, bool checkshapes = true );
	virtual bool CalcOGLPolyInters( TOGLTransf *OGLTransf, int index, TOGLPolygon *Out );
	virtual bool GetRelatedSoftenShapeElements( TOGLTransf *OGLTransf, TCadDepShape *deppolybase );
	virtual void DivideShapeElement( TOGLTransf *OGLTransf, int linemarkerindex, TMarkerList *markerlist );
	virtual TCadShape *GetPolySymmetryAxis( );
	virtual void GetPolySymmetryAxes( TCadGroup *symaxes );
	virtual void UpdateExtPolyPcts( TOGLTransf *OGLTransf, TCadDepShape *depshape );

	virtual void UpdatePointMarker( TOGLTransf *OGLTransf, int index );

	virtual TMarkersData *GetMarkersData( );
	virtual void SetMarkersData( TMarkersData *markersdata );

	virtual bool HasPadding( );
	virtual TPaddingData *GetPaddingData( );
	virtual void SetPaddingData( TPaddingData *data );
	virtual TIntersectPlaneData *GetIntersectPlaneData( );
	virtual void SetIntersectPlaneData( TIntersectPlaneData *data );

	virtual int GetProperties( );
	virtual void SetPriority( int _Priority );
	virtual void SetEdge( bool edge );
	virtual bool GetEdge( );

	virtual bool IsAxis( bool strict = true );
};

//------------------------------------------------------------------------------
// TCadMesh
//------------------------------------------------------------------------------

class TCadMesh : public TCadEntity
{
	friend class TImpExp_XML;

  protected:
	TDevelopMeshData DevelopMeshData;
	TInteger_List *SeamList;		// Se usa para leer y guardar la lista de costuras definida en el pbrep ya qu este no se guarda.
	TNDoublesList *CreaseList;		// Se usa para leer y guardar la lista de pliegues de aristas (pares de vertices) definida en el pbrep.
	TInteger_ListList *AuxInfoList; // Tripletas de enteros (una tripleta por cada vertice de la oglpolygonlist (queda uno libre): Se usa para almacenar los indices de la pbrep y que el sew solo una los que son iguales. Tb se guarda informacion para el calculo del suavizado de normales

  protected:
	virtual bool CalcOGLPolygon( TOGLTransf * );
	virtual bool CalcTextureCoords( TOGLTransf *, TOGLTexture * );
	virtual bool CalcBaseTextureCoords( TOGLTransf *, TOGLPolygonList *, int index = -1 );
	bool GetDevelopMesh( TOGLTransf *OGLTransf, bool *hasDisjointGroups = 0 );
	virtual TOGLPolygon *GetSubdivisionFaces( TOGLTransf * )
	{
		return 0;
	}
	virtual TOGLPolygon *GetSubdivisionEdges( TOGLTransf * )
	{
		return 0;
	}
	virtual TOGLPolygon *GetSubdivisionVertexs( TOGLTransf * )
	{
		return 0;
	}

  public:
	TCadMesh( );
	TCadMesh( T3DPoint *Points, int UDim, int VDim );
	TCadMesh( TOGLPolygonList *S );
	TCadMesh( TCadMesh *S );
	TCadMesh( TOGLTransf *OGLTransf, double totalWidth, double largeWidth, double smallWidth, bool showNumbers = true, bool vertRule = false ); // regla
	virtual ~TCadMesh( );

	virtual void Set( TCadEntity *Ent, bool copyrels );
	virtual void SetBasic( TCadEntity *Ent, bool copyrels );
	virtual void SetBasicGeometry( TCadEntity *S );

	virtual void SetSISLDirty( bool b, bool increasedirtyid = true );
	virtual void SetPolygonDirty( bool b, bool increasedirtyid = true );

	virtual void ClearOGLLists( ) { };
	virtual void SetPolygonList( TOGLPolygonList *S );
	virtual bool GetUniqueOGLDualGeom2DOrDevelop2D( TOGLTransf *OGLTransf, TOGLPolygonList *list, bool tessortrimclose = false );
	virtual void SetTextureMode( int mode, bool applyAll = true );

	virtual float Area( TOGLTransf * );
	virtual float Volume( TOGLTransf *, bool force = false );

	virtual void FillProp_General( TFormEntityData *properties );
	virtual void FillProp_Geom( TOGLTransf *, TFormEntityData *properties );
	virtual void FillProp_Advanced( TFormEntityData *properties );

	virtual bool IsValid( TOGLTransf * )
	{
		return true;
	}
	virtual bool IsHidden( bool checkvisible = true );
	virtual bool IsInactive( TOGLTransf * );

	virtual void SelectOGL( TOGLTransf *, int, int, TOGLRenderData *, TOGLRenderSystem *, TInteger_List * = 0 );

	virtual void DrawOGLPolygon( TOGLTransf *, TOGLRenderData *, TOGLRenderSystem *, bool, bool = true );

	virtual int Count( )
	{
		return OGLPolygonList.Count( );
	}

	virtual int GetMeshesAmount( )
	{
		return 1;
	}

	virtual bool MoveFromTo( TOGLTransf *OGLTransf, T3DPoint org, T3DPoint dst );
	virtual void Move( TOGLTransf *, T3DPoint );
	virtual void HMirror( TOGLTransf *, TNPlane forceplane = plNone );
	virtual void HMirror( TOGLTransf *OGLTransf, T3DPoint m, T3DPoint M, TNPlane forceplane = plNone );
	virtual void VMirror( TOGLTransf *, TNPlane forceplane = plNone );
	virtual void VMirror( TOGLTransf *OGLTransf, T3DPoint m, T3DPoint M, TNPlane forceplane = plNone );
	virtual void MirrorX0( TOGLTransf *, bool invertu = false, bool invertv = false, bool invert = true );
	virtual void MirrorY0( TOGLTransf *OGLTransf, bool, bool, bool = true );
	void InvertSeamAndCreaseLists( );
	virtual void SymAxis( TOGLTransf *, T3DPoint *p1, T3DPoint *p2 );
	virtual bool Rotate( TOGLTransf *, float, TNPlane, int fp = -1, int lp = -1 );
	virtual bool Rotate( TOGLTransf *, float, T3DPoint, TNPlane, int fp = -1, int lp = -1 );
	virtual bool RotateFromTo( TOGLTransf *, TNPlane, T3DPoint, T3DPoint, T3DPoint, int, int, double &, T3DVector *rotAxis = NULL );
	virtual void ApplyMatrix( TOGLTransf *, TNMatrix *, bool recaldev = true, bool canusepbrep = true );
	virtual void ApplyMatrix( TOGLTransf *, TNMatrix *, int, int iEnd = -1 )
	{
	}
	virtual void Offset( TOGLTransf *, double value );

	void ConvertTextureModeToDevelopFix( TOGLTexture *OGLTexture, TOGLTextureData *ogltexturedata );

	virtual void ApplyInvertPolygons( );
	virtual void ApplyInvertNormals( );
	virtual void ApplyInvertNormalsToPBrep( TOGLTransf *OGLTransf );

	virtual bool IsTransparentBackground( );
	virtual bool IsTransparentBackground2D( );
	virtual bool IsTransparentBackground3D( );

	virtual bool IsFillEntity( bool usepoints = true );
	virtual bool IsRasterImage( );
	virtual bool IsEnvelope( );

	virtual UnicodeString WhoAmI( )
	{
		return ST_MESH;
	}
	virtual UnicodeString WhoIDSAmI( )
	{
		return "IDS_ST_MESH";
	}

	virtual bool AmIStrictEntity( )
	{
		return false;
	}
	virtual bool AmIStrictMesh( )
	{
		return true;
	}

	virtual bool IsSubdivisionEntity( ); // Base o dependiente de una subdivision
	bool HasSubdivisionDepMesh( );
	virtual bool IsPolygonalMesh( );
	virtual bool GetPBrepTrianglesForced( );
	virtual void ApplyOGLRenderData( TOGLTransf *, TOGLRenderData *, TOGLRenderSystem *, bool &applytexturecoords );
	void DeleteDegeneratedTriangles( TOGLTransf *OGLTransf, double prec = RES_COMP );

	virtual bool CalcDevelopMesh( TOGLTransf *, bool *hasDisjointGroups = 0 );
	virtual TDevelopMeshData *GetDevelopMeshData( );
	virtual void SetDevelopMeshData( TDevelopMeshData *data );

	bool ApplySubdivision( TOGLTransf *OGLTransf, bool keepcreases = true );

	virtual TInteger_List *GetSeamList( bool force = false );
	virtual TNDoublesList *GetCreaseList( bool force = false );
	virtual TInteger_ListList *GetAuxInfoList( bool force = false );
};

//------------------------------------------------------------------------------
// TCadDepMesh
//------------------------------------------------------------------------------

class TCadDepMesh : public TCadMesh
{
	friend class TImpExp_XML;

  protected:
	TCadGroup BaseEntities;
	TTrimOffsetSideData TrimOffsetSideData;
	TTrimOffsetBorderData TrimOffsetBorderData;
	TTessLocationData TessLocationData;
	TStipplePatternData StipplePatternData;
	TBoxPlaneData BoxPlaneData;
	TLocation3DData Location3DData;
	TLocation3DEntitiesData Location3DEntitiesData;
	TSweepOneData SweepOneData;
	TSweepTwoData SweepTwoData;
	TRevolveData RevolveData;
	TExtrusionData ExtrusionData;
	TGrading2DData Grading2DData;
	TSubdivisionData SubdivisionData;
	TNMatrix TransformMatrix;

	TOGLPolygonListList OGLListOut, OGLListIn;			   // temporal para tipo trimoffsetside con padding
	TPaddingDataList PaddingDataList;					   // temporal para tipo trimoffsetside con padding
	TOGLPolygonList ItemGeomList[ 2 ], ItemParamList[ 2 ]; // para tipo stipplepattern

	TOGLPolygon SubdivisionVertexs, SubdivisionEdges, SubdivisionFaces; // para tipo subdivision

	bool InvertNormals;

	bool IsTessLocationDirty;
	bool LockTessLocationDirty;

	TCadTrimSurface *TempTrimSurface;

  protected:
	virtual bool CalcOGLPolygon( TOGLTransf * );
	virtual void CalcOGLPolygonTrimOffsetSide( TOGLTransf *, bool &recalcnormals );
	virtual void CalcPadding( TOGLTransf * );
	virtual void CalcOGLPolygonTrimOffsetBorder( TOGLTransf * );
	virtual void CalcOGLPolygonTessLocationInside( TOGLTransf * );
	virtual void CalcOGLPolygonStipplePattern( TOGLTransf *OGLTransf );
	virtual void CalcOGLPolygonBoxPlane( TOGLTransf * );
	virtual void CalcOGLPolygonLocation3D( TOGLTransf *OGLTransf );
	virtual void CalcOGLPolygonLocation3DNormal( TOGLTransf *OGLTransf );
	virtual void CalcOGLPolygonLocation3DOnLine( TOGLTransf *OGLTransf );
	virtual void CalcLocation3DNormalData( TOGLTransf *OGLTransf, TOGLPolygonList *ogllist, TNMatrix *matrix, T3DRect *r );
	virtual void CalcOGLPolygonSweepOne( TOGLTransf * );
	virtual void CalcOGLPolygonSweepTwo( TOGLTransf * );
	virtual void CalcSweepTwo( TOGLTransf *OGLTransf, TOGLPolygonList *OGLListRail, int nSections, double *SectionPcts, TOGLPolygonList **OGLListSection, bool CloseSides, bool KeepAspectRatio, double FilterDist, TOGLPolygon *TempSectionCenters );
	virtual void CalcOGLPolygonRevolve( TOGLTransf * );
	virtual void CalcOGLPolygonExtrusion( TOGLTransf * );
	virtual void CalcOGLPolygonExtrusionDevelop2D( TOGLTransf * );
	virtual void CalcOGLPolygonExtrusionTrim( TOGLTransf * );
	virtual void CalcOGLPolygonExtrusionTrimDevelop( TOGLTransf * );
	virtual void CalcOGLPolygonGrading2DLocation( TOGLTransf * );
	virtual void CalcOGLPolygonSubdivision( TOGLTransf * );

	virtual bool CalcTextureCoords( TOGLTransf *, TOGLTexture * );
	virtual bool CalcBaseTextureCoords( TOGLTransf *, TOGLPolygonList *, int index = -1 );

	virtual bool UpdateListGeomParValues( TOGLTransf *OGLTransf, TCadSurface *surf, TOGLFloat3 *vtxpar, TOGLFloat3 *vtxpar2, TOGLPolygonList *ListGeom, TOGLPolygonList *ListGeomOffset, TCadTrimSurface *trim );
	virtual void GetTrimToDevelop( TOGLTransf *OGLTransf, TCadSurface *paramsurf, TOGLFloat3 *vtxparam, T3DRect *r3d, TCadTrimSurface **Trim );

  public:
	TCadDepMesh( );
	TCadDepMesh( TCadDepMesh *S );
	virtual ~TCadDepMesh( )
	{
	}

	virtual void Set( TCadEntity *Ent, bool copyrels );
	virtual void SetBasic( TCadEntity *Ent, bool copyrels );
	virtual void SetBasicGeometry( TCadEntity *S )
	{
	} // no tratado
	virtual void SetBasicRels( TCadEntity *S );
	virtual void ChangeBasicRels( TCadEntity *orgbaseent, TCadEntity *dstbaseent, bool updatedirty = true, bool setdirty = false );
	virtual void GetBasicRelsEnts( TCadGroup *grp, bool usesurf = true, bool usemainaxissurf = true );

	virtual void SetSISLDirty( bool b, bool increasedirtyid = true )
	{
		TCadEntity::SetSISLDirty( b, increasedirtyid );
	}
	virtual void SetPolygonDirty( bool b, bool increasedirtyid = true );

	virtual bool ApplyTexture( TOGLTransf *, TOGLRenderSystem *, TOGLTexture *, bool ismaxwell = false, bool = true );
	virtual void SetTextureMode( int mode, bool applyAll = true );
	virtual void SetDevelopMeshData( TDevelopMeshData *data );

	virtual bool MustCalcOGLLists( TOGLRenderSystem * );
	virtual void DrawOGLPolygon( TOGLTransf *, TOGLRenderData *, TOGLRenderSystem *, bool, bool = true );
	virtual void DrawOGL( TOGLTransf *, TOGLRenderData *, TOGLRenderSystem * );
	virtual void ApplyOGLRenderData( TOGLTransf *, TOGLRenderData *, TOGLRenderSystem *, bool &applytexturecoords );
	virtual bool GetBasicTextureCoords( TOGLTransf *, TOGLPolygonList *Out );
	virtual bool CalcDevelopMesh( TOGLTransf *, bool * = 0 );

	virtual void CleanGroups( );
	virtual void DetachUpRelations( TCadGroup *, TPointRelationList *, TEntityRelationList *, bool updatedirty = true );

	virtual void ChangeOwnRelatedEntity( TCadEntity *ent );
	virtual void ChangeRelatedEntity( TCadEntity *orgent, TCadEntity *dstent, TCadGroup *gr = 0, bool setdirty = false );
	virtual void GetUpRelatedEntities( TCadGroup *Group, bool rels = true, bool pointRels = true );
	virtual bool HasUpRelatedEntities( bool rels = true, bool pointRels = true, bool excludeparamsurf = false );
	virtual void ClearOwnRelations( );
	virtual void FillProp_General( TFormEntityData *properties );
	virtual void FillProp_Advanced( TFormEntityData *properties );
	virtual TCadSurface *GetBaseSurface( );
	virtual TCadGroup *GetBaseEntities( )
	{
		return &BaseEntities;
	}
	virtual TCadEntity *GetBaseEntity( );

	virtual bool GetLockNormals( );

	virtual TTrimOffsetSideData *GetTrimOffsetSideData( );
	virtual void SetTrimOffsetSideData( TTrimOffsetSideData *data );
	virtual TTrimOffsetBorderData *GetTrimOffsetBorderData( );
	virtual void SetTrimOffsetBorderData( TTrimOffsetBorderData *data );
	virtual TTessLocationData *GetTessLocationData( );
	virtual void SetTessLocationData( TTessLocationData *data );
	virtual TStipplePatternData *GetStipplePatternData( );
	virtual void SetStipplePatternData( TStipplePatternData *data, bool calcholes = true, bool baseentityindex = true );
	virtual TBoxPlaneData *GetBoxPlaneData( );
	virtual void SetBoxPlaneData( TBoxPlaneData *data );
	virtual TLocation3DData *GetLocation3DData( );
	virtual void SetLocation3DData( TLocation3DData *data );
	virtual TLocation3DEntitiesData *GetLocation3DEntitiesData( );
	virtual void SetLocation3DEntitiesData( TLocation3DEntitiesData *data );
	virtual TSweepOneData *GetSweepOneData( );
	virtual void SetSweepOneData( TSweepOneData *data );
	virtual TSweepTwoData *GetSweepTwoData( );
	virtual void SetSweepTwoData( TSweepTwoData *data );
	virtual TRevolveData *GetRevolveData( );
	virtual void SetRevolveData( TRevolveData *data );
	virtual TExtrusionData *GetExtrusionData( );
	virtual void SetExtrusionData( TExtrusionData *data );
	virtual TGrading2DData *GetGrading2DData( );
	virtual void SetGrading2DData( TGrading2DData *data );
	virtual TCadPoint *GetGrading2DLocationPoint( );
	virtual void SetGrading2DLocationPoint( TCadPoint *pt );
	virtual TSubdivisionData *GetSubdivisionData( );
	virtual void SetSubdivisionData( TSubdivisionData *data );
	virtual TOGLPolygon *GetSubdivisionVertexs( TOGLTransf * );
	virtual TOGLPolygon *GetSubdivisionEdges( TOGLTransf * );
	virtual TOGLPolygon *GetSubdivisionFaces( TOGLTransf * );

	virtual TNMatrix *GetTransformMatrix( );
	virtual void SetTransformMatrix( TNMatrix * );
	virtual void ClearTransformMatrix( );

	virtual TOGLPolygonList *GetItemGeomList( int ind );
	virtual TOGLPolygonList *GetItemParamList( int ind );
	virtual double GetStipplePatternEstimatedLength( TOGLTransf *OGLTransf );

	virtual void SetOGLTextureDataList( TOGLTextureDataList *, bool force = false );
	virtual TOGLTextureDataList *GetOGLTextureDataList( bool force = false );
	virtual TOGLTextureData *GetOGLTextureData( int index = -1 );
	virtual void SetOGLTextureData( TOGLTextureData *, int index = -1 );

	virtual bool IsTrimOffsetSideDepMesh( );
	virtual bool IsTrimOffsetBorderDepMesh( );
	virtual bool IsTessLocationInsideDepMesh( );
	virtual bool IsStipplePatternDepMesh( );
	virtual bool IsBoxPlaneDepMesh( );
	virtual bool IsLocation3DDepMesh( );
	virtual bool IsLocation3DOnLineDepMesh( );
	virtual bool IsSweepOneDepMesh( );
	virtual bool IsSweepTwoDepMesh( );
	virtual bool IsRevolveDepMesh( );
	virtual bool IsExtrusionDepMesh( );
	virtual bool IsExtrusionTrimDepMesh( );
	virtual bool IsGrading2DLocationDepMesh( );
	virtual bool IsSubdivisionDepMesh( );

	virtual double GetOffsetValueLocation3DOnLineDepMesh( TOGLTransf *OGLTransf, double pct );

	virtual bool GetLocation3DNormalPoints( TOGLTransf *OGLTransf, TOGLPolygon *ItemParamPol );
	virtual TShapeElement *GetLocation3DShapeElement( TOGLTransf *OGLTransf );
	virtual void SetLocation3DShapeElement( TOGLTransf *OGLTransf, TShapeElement *se );

	virtual void CalcMarkerListsPoints( TOGLTransf *OGLTransf, bool isparam, TInteger_List *forcetypes, bool checkextremes, TCadGroup *group, bool forcedev = false );
	virtual void CalcMarkerListsPoints( TOGLTransf *OGLTransf, bool isparam, TInteger_List *forcetypes = 0, bool checkextremes = true, bool forcedev = false );
	virtual void CalcMarkerListsPcts( TOGLTransf *OGLTransf, bool isparam, TInteger_List *forcetypes = 0, bool checkextremes = true, bool forcedev = false );

	virtual bool GetLocation3DDepMesh( TCadGroup *group );

	virtual double *GetPaddingHeight( TOGLTransf *OGLTransf, TOGLPolygonList *OGLList );
	virtual int GetPaddingIndex( TOGLTransf *OGLTransf, TOGLFloat3 *vtx );
	virtual void UpdateGeomListByPadding( TOGLTransf *OGLTransf, TOGLPolygonList *baseparam2Dlist, TOGLPolygonList *basegeom3Dlist );
	virtual bool HasPaddingActive( TOGLTransf *OGLTransf );

	virtual void SetPolygonList( TOGLPolygonList *S )
	{
	}

	virtual bool MoveFromTo( TOGLTransf *OGLTransf, T3DPoint org, T3DPoint dst )
	{
		return false;
	}
	virtual void Move( TOGLTransf *, T3DPoint )
	{
	}

	virtual void FitToRect( TOGLTransf *, T3DPoint, T3DPoint )
	{
	}
	virtual void HMirror( TOGLTransf *, TNPlane forceplane = plNone )
	{
	}
	virtual void HMirror( TOGLTransf *OGLTransf, T3DPoint m, T3DPoint M, TNPlane forceplane = plNone )
	{
	}
	virtual void VMirror( TOGLTransf *, TNPlane forceplane = plNone )
	{
	}
	virtual void VMirror( TOGLTransf *OGLTransf, T3DPoint m, T3DPoint M, TNPlane forceplane = plNone )
	{
	}
	virtual void MirrorY0( TOGLTransf *OGLTransf, bool, bool, bool = true )
	{
	}
	virtual void SymAxis( TOGLTransf *, T3DPoint *, T3DPoint * )
	{
	}
	virtual bool Rotate( TOGLTransf *, float, TNPlane, int fp = -1, int lp = -1 )
	{
		return false;
	}
	virtual bool Rotate( TOGLTransf *, float, T3DPoint, TNPlane, int fp = -1, int lp = -1 )
	{
		return false;
	}
	virtual void ApplyMatrix( TOGLTransf *, TNMatrix *, bool recaldev = true, bool canusepbrep = true );
	virtual void ApplyMatrix( TOGLTransf *OGLTransf, TNMatrix *mat, int iStart, int iEnd = -1 )
	{
		TCadMesh::ApplyMatrix( OGLTransf, mat, iStart, iEnd );
	}

	virtual bool GetInvertNormals( );
	virtual void SetInvertNormals( bool );
	virtual void ApplyInvertPolygons( )
	{
	}
	virtual void ApplyInvertNormals( )
	{
	}

	virtual void SetTempTrimSurface( TCadTrimSurface *trim );

	virtual bool GetTessLocationDirty( );
	virtual void SetTessLocationDirty( bool value );
	virtual bool GetLockTessLocationDirty( );
	virtual void SetLockTessLocationDirty( bool value );
	virtual TCadDepShape *GetTessLocationDepShapeBoundaries( );

	virtual bool IsTransparentBackground( )
	{
		return false;
	}
	virtual bool IsTransparentBackground2D( )
	{
		return false;
	}
	virtual bool IsTransparentBackground3D( )
	{
		return false;
	}

	virtual bool IsEditable( )
	{
		return false;
	}
	virtual bool IsFillEntity( bool usepoints = true );
	virtual bool IsRasterImage( )
	{
		return false;
	}
	virtual bool IsIndependent( bool checkpointrels = true )
	{
		return false;
	}
	virtual bool CanApplyTransform( bool checkpointrels = true )
	{
		return false;
	}

	virtual bool IsPolygonalMesh( )
	{
		return false;
	}
	virtual bool IsSubdivisionEntity( ); // Base o dependiente de una subdivision

	virtual UnicodeString WhoAmI( )
	{
		return ST_DEPMESH;
	}
	virtual UnicodeString WhoIDSAmI( );

	virtual bool AmIStrictMesh( )
	{
		return false;
	}
	virtual bool AmIStrictDepMesh( )
	{
		return true;
	}
};

//------------------------------------------------------------------------------
// TCadSurface
//------------------------------------------------------------------------------

class TCadSurface : public TCadEntity
{
	friend class TImpExp_XML;

  protected:
	SISLSurf *Surface;
	int UClose, VClose;
	int UCloseExt, VCloseExt;
	bool DegeneratedUV[ 4 ];
	double DegeneratedTol;
	int UDegree, VDegree;
	int DrawMode;
	int DrawCurvesMode;

	TCadSurface *SurfaceSmall;
	int SurfaceSmallMethod;
	double SurfaceSmallReductionValue;
	bool UseSurfaceSmallToNormals;
	bool UseSurfaceSmallToSelect;
	bool UseSurfaceSmallToDevelopTrims;
	bool IsSurfaceSmall;

	TCadGroup ParamEntities;
	TCadGroup TrimSurfaces;

	TDevelopList *DevelopList;
	bool IsCalcDevSurfsDirty;
	bool LockCalcDevSurfIndex;
	bool LockCalcDevSurfsDirty;

	bool InvertNormals;

	double ParValuesSimpleRange[ 2 ]; // de 0 a 1, para la función GetParValuesSimple

  protected:
	virtual bool CalcSISL( TOGLTransf * );

	virtual bool CalcSISLSurface( TOGLTransf * )
	{
		return true;
	}
	virtual bool RatToPolSISLSurface( TOGLTransf * );
	virtual void NormInternalSISLSurface( TOGLTransf *OGLTransf, double *_endlimitsUV = 0 );
	virtual bool CalcCloseExt( );
	virtual bool CalcSurfaceSmall( TOGLTransf * );
	virtual bool CalcDegeneratedUV( );
	virtual void CalcParValuesSimpleRange( TOGLTransf * );

	virtual bool CalcOGLLists( TOGLTransf * );
	virtual bool CalcOGLPolygon( TOGLTransf * );
	virtual bool CalcDevelopSurfaces( TOGLTransf *, bool start = true );
	virtual bool CalcDevelopSurfacesEdges( TOGLTransf * );
	virtual bool CalcTextureCoords( TOGLTransf *, TOGLTexture * );
	virtual bool CalcBaseTextureCoords( TOGLTransf *, TOGLPolygonList *, int index = -1 );
	virtual bool CalcOGLPolygonOptimum( TOGLTransf *OGLTransf, double angMax );
	virtual bool CalcOGLPolygonDevelop2D( TOGLTransf * );
	virtual T3DPoint *GetDataSurfaceToOptimunTesselation( TOGLTransf *OGLTransf, double **upar, double **vpar, int &UDim, int &vDim, int &uClose, int &vClose, double &angMax );

  public:
	TCadSurface( int u = DEFAULT_DEGREE, int v = DEFAULT_DEGREE );
	TCadSurface( SISLSurf *s, TOGLTransf *OGLTransf = 0, double tol = RES_PARAM, bool norm = true, bool copy = true );
	TCadSurface( TCadSurface *s );
	virtual ~TCadSurface( );

	virtual void Set( TCadEntity *Ent, bool copyrels );
	virtual void SetBasic( TCadEntity *, bool copyrels );
	virtual void SetBasicGeometry( TCadEntity *S );

	virtual bool CalcBoundRectViewport( TOGLTransf *, TLRect &, int step = 1, TNMatrix *MirrorMat = 0, TInstanceList *list = 0 );
	virtual bool SISLBoundRectViewport( TOGLTransf *, TLRect &rect, TNMatrix *MirrorMat = 0, TInstanceList *RenderInstanceList = 0 );

	virtual int GetUClose( )
	{
		return UClose;
	}
	virtual int GetVClose( )
	{
		return VClose;
	}
	virtual int GetUDegree( )
	{
		return UDegree;
	}
	virtual int GetVDegree( )
	{
		return VDegree;
	}

	virtual int GetUCloseExt( TOGLTransf * );
	virtual int GetVCloseExt( TOGLTransf * );
	virtual bool IsDegenerated( TOGLTransf *, bool * = 0 );

	virtual void NormSISLSurface( TOGLTransf *, double * = 0 );
	virtual SISLSurf *GetSISLSurface( TOGLTransf * );
	virtual void SetSISLSurface( SISLSurf *, bool deletesurf );

	virtual void SetParamEntities( TOGLTransf *, TCadGroup *curves );
	virtual TCadGroup *GetParamEntities( )
	{
		return &ParamEntities;
	}

	virtual TCadGroup *GetTrimSurfaces( )
	{
		return &TrimSurfaces;
	}
	virtual TCadTrimSurface *HasCompleteTrim( TOGLTransf *OGLTransf );
	virtual TCadTrimSurface *HasCompleteTrim2U1V( TOGLTransf *OGLTransf );
	virtual bool HasTrimSurfaceInGroup( TCadGroup *grp );

	virtual TCadGroup *GetTransfDevelopSurfaces( TOGLTransf *, int devindex = -1 );
	virtual TOGLPolygonList *GetTransfDevelopSurfacesEdges( TOGLTransf *OGLTransf, int devindex = -1 );
	virtual TDevelopList *GetDevelopList( )
	{
		return DevelopList;
	}
	virtual TCadGroup *GetDevelopSurfacesForSymmetries( TOGLTransf *OGLTransf );
	virtual bool IsDevelopValidForSymmetries( int devindex );
	virtual bool GetDevelopSymAxisPoints( TOGLTransf *, T3DPoint *p1, T3DPoint *p2, int devindex = -1 );

	virtual void SetDevelopList( TOGLTransf *, TDevelopList *devlist, bool del = true, bool copy = true, bool checkindexes = true ); // ruben
	virtual bool SetDevelopDataLengthFactor( TOGLTransf *, float value );
	virtual void GetDevelopLimitsUV( TOGLTransf *, int i, double *limits );
	virtual void GetDevelopLimitsUV( TOGLTransf *, double *devlimits, double *limits );
	virtual bool GetDevelopDataLimitsUV( TOGLTransf *, TCadSurface *surf, double *limitsUV, double *devdatalimits );

	virtual bool RevertSecondDevelopSurface( TOGLTransf *OGLTransf );
	virtual void RestoreSecondDevelopSurface( TOGLTransf *OGLTransf );
	virtual bool RevertSecondDevelopSurfIndex( TOGLTransf *OGLTransf, T3DPoint *p );

	virtual bool UpdateDevelopDataArea( TOGLTransf *OGLTransf, int developtype, int vlimitarea, TInteger_List *weighttypes, float *weightvalues );
	virtual void CalcDevelopDataArea( TOGLTransf *OGLTransf, int developtype, int vlimitarea, int weightinitmethod, TOGLPolygonList *Contours, TNDoublesList *ContoursLimits, TOGLPolygonList *Curve, double vvalue = 0.0, double tightenanglefactor = 0.0 );
	virtual void CalcDevelopWeightTypesPriorityTop( TOGLTransf *OGLTransf, double *limits, TOGLPolygon *Contour, float pct1, float pct2, TInteger_List *WeightTypes );
	virtual void CalcDevelopWeightTypesPriorityCurve( TOGLTransf *OGLTransf, double *limits, TOGLPolygon *Contour, TOGLPolygonList *Curve, TInteger_List *WeightTypes );
	virtual void CalcDevelopWeightTypesPriorityNone( TOGLTransf *OGLTransf, double *limits, TOGLPolygon *Contour, TInteger_List *WeightTypes );
	virtual void CalcDevelopWeightTypesPriorityVValue( TOGLTransf *OGLTransf, double *limits, double vvalue, bool invertu, double tightenanglefactor, TInteger_List *WeightTypes );
	virtual bool GetDevelopWeights( TOGLTransf *OGLTransf, TDevelopData *devdata, int nu, int nv, float ***Weights );
	virtual bool SetDevelopWeight( TOGLTransf *OGLTransf, int devsurfindex, int priority, T3DPoint pt, double res, bool recalc = true );

	virtual int GetIndexVLimit( TOGLTransf *OGLTransf, double v );
	virtual int GetIndexVLimitNearest( TOGLTransf *OGLTransf, double v );
	virtual TCadSurface *GetTransfDevelopSurfaceByIndex( TOGLTransf *OGLTransf, int index );
	virtual int GetTransfDevelopSurfIndexByPoint( TOGLTransf *OGLTransf, TLPoint ptparam, int defindex = -1 );
	virtual int IsInDevelopSurfIndex( TOGLTransf *OGLTransf, TOGLPolygonList *ogllist, double margin = RES_PARAM );
	virtual bool HasDevelopData( );
	virtual bool HasDevelop( );
	virtual bool CalcDevelopErrors( TOGLTransf * );

	virtual T3DPoint GetDataParam( TOGLTransf *OGLTransf, int u, int v, int nu = 0, int nv = 0, double *upar = 0, double *vpar = 0 );
	virtual T3DPoint GetDataPoint( TOGLTransf *OGLTransf, int u, int v );

	virtual bool PointParamToPointDev( TOGLTransf *OGLTransf, bool forcedevsurfindex, int devindex, T3DPoint pt, T3DPoint &pt2D, int *devsurfindex = 0 );
	virtual bool PointDevToPointParam( TOGLTransf *OGLTransf, bool forcedevsurfindex, int devindex, T3DPoint pt2D, TOGLPolygon *PolParam, bool forceinside = false, bool alldevsurfindex = false );

	virtual void SetSISLDirty( bool b, bool increasedirtyid = true );
	virtual void SetPolygonDirty( bool b, bool increasedirtyid = true );
	virtual void ForceDevSurfsDirty( int level, int devindex = -1, bool increasedirtyid = true );
	virtual bool IsTransfDevSurfsDirty( int devindex = -1 );
	virtual bool IsAnyDevSurfsDirty( );
	virtual void SetCalcDevSurfsDirty( bool value );
	virtual void SetTransfDevSurfsDirty( bool value, int devindex = -1 );

	virtual bool IsTransfDevSurfsEdgesDirty( int devindex = -1 );
	virtual void SetTransfDevSurfsEdgesDirty( bool value, int devindex = -1 );

	virtual bool GetLockCalcDevSurfIndex( )
	{
		return LockCalcDevSurfIndex;
	}
	virtual void SetLockCalcDevSurfIndex( bool b );
	virtual bool GetLockCalcDevSurfsDirty( )
	{
		return LockCalcDevSurfsDirty;
	}
	virtual void SetLockCalcDevSurfsDirty( bool b );

	virtual bool AddDevelopIndex( );
	virtual bool DeleteDevelopIndex( int devindex );
	virtual bool SetCurrentDevelopIndex( int devindex );

	virtual int GetDrawMode( )
	{
		return DrawMode;
	}
	virtual void SetDrawMode( TOGLTransf *, int mode )
	{
		DrawMode = mode;
	}

	virtual int GetDrawCurvesMode( )
	{
		return DrawCurvesMode;
	}
	virtual void SetDrawCurvesMode( TOGLTransf *, int mode )
	{
		DrawCurvesMode = mode;
	}

	virtual void CleanGroups( );
	virtual void GetDownRelatedEntities( TOGLTransf *OGLTransf, TCadGroup *Group, HLAYER *excludelayer = 0, bool force = false );
	virtual void ChangeOwnRelatedEntity( TCadEntity *ent );
	virtual void ChangeRelatedEntity( TCadEntity *orgent, TCadEntity *dstent, TCadGroup *gr = 0, bool setdirty = false );
	virtual void ClearOwnRelations( );

	virtual bool ValidatePWLCurve( double *, int np, GLfloat *array );

	virtual bool IsValid( TOGLTransf * )
	{
		return true;
	}
	virtual void GetShapeInfo( TOGLTransf *OGLTransf, TShapeInfo *si );

	virtual void Invert( TOGLTransf * );
	virtual void InvertU( TOGLTransf * );
	virtual void InvertV( TOGLTransf * );

	virtual TLRect ApproachPeriodicRect( TOGLTransf *, TLRect, TLRect, bool = true );
	virtual TCadSurface *ReplySurface( TOGLTransf *, T3DRect );

	virtual bool GetPoint( TOGLTransf *, double pu, double pv, T3DPoint &p );
	virtual bool GetNormal( TOGLTransf *, double pu, double pv, T3DPoint &p );
	virtual bool GetPointAndNormal( TOGLTransf *, double pu, double pv, T3DPoint &p, T3DPoint &n );
	virtual bool GetPointAndDerivatives( TOGLTransf *, double pu, double pv, T3DPoint *p );

	virtual T3DPoint *GetPoints( TOGLTransf *OGLTransf, int nu, int nv, double **upar = 0, double **vpar = 0 );
	virtual T3DPoint *GetPoints( TOGLTransf *, int, double *, int, double * );
	virtual T3DPoint *GetPointsRes( TOGLTransf *, double, int &, int & ); // defecto double = 1.0; si es 2.0 devuelve el doble de la longitud +- en mm, ....
	virtual TOGLPoint **GetPoints2( TOGLTransf *, int, int );
	virtual void GetDevelopDataRes( TOGLTransf *OGLTransf, TDevelopData *DevelopData, int &ures, int &vres );
	virtual void GetParamsUV( TOGLTransf *, double *limits, int ures, int vres, int &nu, int &nv, double **upar, double **vpar, bool minthree = true );

	virtual void GetNormals2( TOGLTransf *OGLTransf, double *limits, int ures, int vres, int &nu, int &nv, T3DPointF ***Normals );
	virtual void GetPointsAndNormals2( TOGLTransf *, int, double *, int, double *, T3DPointF ***Points, T3DPointF ***Normals );
	virtual void GetPointsAndNormalsAndParams2( TOGLTransf *, double *limits, int ures, int vres, int &nu, int &nv, T3DPointF ***Points, T3DPointF ***Normals, double **upar, double **vpar );

	virtual T3DPoint **GetPointsAndParams2( TOGLTransf *, int, int, double **, double ** );
	virtual void GetPointsAndNormalsAndParams2( TOGLTransf *, int nu, int nv, double **upar, double **vpar, T3DPoint ***points, T3DPoint ***normals );
	virtual bool GetExtremePoint( TOGLTransf *, T3DVector vector, T3DPoint &point, double *limits = NULL );
	virtual T3DPoint GetExtremeNearestParamPoint( TOGLTransf *OGLTransf, T3DPoint ptgeom );

	virtual bool GetParValuesSimple( TOGLTransf *OGLTransf, double *limits, bool *close, T3DPoint p, double *guess, double *clpar, double *_range = 0 );
	virtual void ImproveParValuesSimpleInLimits( TOGLTransf *OGLTransf, double *gpar, double *limits, bool *close, T3DPoint pt, double *guess, int ntests = 7, int maxtests = 50, double parampct = 0.05, bool onsurface = true );
	virtual bool GetParValues( TOGLTransf *, T3DPoint p, double &pu, double &pv, double maxerr = RES_GEOM );

	virtual bool GetExtOGLGeomParam( TOGLTransf *OGLTransf, TOGLPolygonList *ingeomlist, int nptguess, T3DPoint *ptguess, bool isdevelopable, bool forcedevsurfindex, int devsurfindex, TOGLPolygonList *outparamlist, TOGLPolygonList *outgeomlist, double paramoffset = PARAM_OFFSET_MARKER_DEFAULT, bool onsurface = true, double replysurffactor = 0.2 );
	virtual bool GetExtOGLParam2DFromGeom3D( TOGLTransf *OGLTransf, TOGLPolygonList *geomlist, int nptguess, T3DPoint *ptguess, bool isdevelopable, bool forcedevsurfindex, int devsurfindex, TOGLPolygonList *paramlist, bool onsurface = true, double replysurffactor = 0.2 );
	virtual bool GetExtOGLGeom3DFromParam2D( TOGLTransf *OGLTransf, TOGLPolygonList *paramlist, bool isdevelopable, bool forcedevsurfindex, int devsurfindex, TOGLPolygonList *geomlist, double paramoffset );
	virtual bool GetExtBasicOGLDevelop2DFromParam2D( TOGLTransf *OGLTransf, TOGLPolygonList *in, int devsurfindex, TOGLPolygonList *out, TCadGroup *devsurfs = 0 );
	virtual bool GetExtBasicOGLParam2DFromDevelop2D( TOGLTransf *OGLTransf, TOGLPolygonList *devlist, int devsurfindex, TOGLPolygonList *paramlist, TCadGroup *devsurfs = 0 );
	virtual bool GetExtOGLDevelop2DFromParam2D( TOGLTransf *OGLTransf, TOGLPolygonList *inlist, bool forcedevsurfindex, int devsurfindex, TOGLPolygonList *outlist, bool meshlist = false, TCadGroup *devsurfs = 0 );
	virtual bool GetExtOGLParam2DFromDevelop2D( TOGLTransf *OGLTransf, TOGLPolygonList *devlist, bool forcedevsurfindex, int devsurfindex, TOGLPolygonList *paramlist, TCadGroup *devsurfs = 0 );

	virtual bool GetOGLPointParam2DFromGeom3D( TOGLTransf *OGLTransf, TOGLPoint ptin, T3DPoint guesspt, bool isdevelopable, bool forcedevsurfindex, int devsurfindex, TOGLPoint &ptout );

	virtual bool Intersect( TOGLTransf *OGLTransf, T3DPoint point, TLPoint &ptUV );
	virtual bool Intersect( TOGLTransf *, T3DVector vector, TLPoint &ptUV, T3DPoint &pt3D, T3DPoint &n3D, bool nearest = true );
	virtual bool Intersect( TOGLTransf *OGLTransf, T3DVector vector, TOGLPolygon *out );
	virtual bool Intersect( TOGLTransf *, T3DPlane plano, TCadGroup *curves, int represent = 2 );
	virtual bool Intersect( TOGLTransf *, SISLCurve *curve, TCadGroup *curves, int represent );
	virtual bool Intersect( TOGLTransf *, TPoint Size, TRect Range, T3DPlane plane, TOGLPolygonList *OGLList, bool = true, TNPlane forceplane = plNone, T3DPoint ptplane = T3DPoint( 0.0, 0.0, 0.0 ) );
	virtual bool Intersect( TOGLTransf *, TCadSurface *surf2, int represent, bool forcejoin, TCadGroup *curves );
	virtual void GetIntersectLimits( T3DPoint **, int, int, T3DPlane, int &, int &, int &, int & );

	virtual double GetDegeneratedTol( )
	{
		return DegeneratedTol;
	}
	virtual void SetDegeneratedTol( double value );

	virtual void SetSurfaceSmallValues( int method, double reductionvalue );
	virtual void GetSurfaceSmallValues( int &method, double &reductionvalue );
	virtual void SetUseSurfaceSmallToNormals( bool value )
	{
		UseSurfaceSmallToNormals = value;
	}
	virtual bool GetUseSurfaceSmallToNormals( )
	{
		return UseSurfaceSmallToNormals;
	}
	virtual void SetUseSurfaceSmallToSelect( bool value )
	{
		UseSurfaceSmallToSelect = value;
	}
	virtual bool GetUseSurfaceSmallToSelect( )
	{
		return UseSurfaceSmallToSelect;
	}
	virtual void SetUseSurfaceSmallToDevelopTrims( bool value )
	{
		UseSurfaceSmallToDevelopTrims = value;
	}
	virtual bool GetUseSurfaceSmallToDevelopTrims( )
	{
		return UseSurfaceSmallToDevelopTrims;
	}
	virtual bool GetIsSurfaceSmall( )
	{
		return IsSurfaceSmall;
	}
	virtual void SetIsSurfaceSmall( bool value );
	virtual TCadSurface *GetSurfaceSmall( TOGLTransf * );
	virtual void ClearSurfaceSmall( );

	virtual TCadSurface *Pick( TOGLTransf *, double * );

	virtual void SelectOGL( TOGLTransf *, int, int, TOGLRenderData *, TOGLRenderSystem *, TInteger_List * = 0 );

	virtual void ApplyMatrix( TOGLTransf *, TNMatrix *, bool recaldev = true, bool canusepbrep = true );
	virtual void ApplyMatrix( TOGLTransf *, TNMatrix *, int, int iEnd = -1 )
	{
	}

	virtual SISLCurve *ToParamPlane( TOGLTransf *, SISLCurve *, bool forceclose = false );
	virtual SISLCurve *ToGeomPlane( TOGLTransf *, SISLCurve * );

	virtual TCadBSpline *GetCurveU( TOGLTransf *, double u, bool norm = true );
	virtual TCadBSpline *GetCurveV( TOGLTransf *, double v, bool norm = true );

	virtual void EquidistributeParamsByLengthUV( TOGLTransf *OGLTransf, int nu, int nv, double *upar, double *vpar );
	virtual TLPoint GetLengthUV( TOGLTransf *, double *limits = 0, double = 0.1 );
	virtual TLPoint GetLimitsLengthUV( TOGLTransf *OGLTransf, double *orglimits );
	virtual void GetLimitsUV( TOGLTransf *, double *limits = 0 );

	virtual void FitToRect( TOGLTransf *, T3DPoint, T3DPoint )
	{
	}
	virtual void HMirror( TOGLTransf *, TNPlane forceplane = plNone )
	{
	}
	virtual void VMirror( TOGLTransf *, TNPlane forceplane = plNone )
	{
	}
	virtual void HMirror( TOGLTransf *, T3DPoint, T3DPoint, TNPlane forceplane = plNone )
	{
	}
	virtual void VMirror( TOGLTransf *, T3DPoint, T3DPoint, TNPlane forceplane = plNone )
	{
	}
	virtual void MirrorX0( TOGLTransf *, bool invertu = false, bool invertv = false, bool invert = true );
	virtual void MirrorY0( TOGLTransf *, bool invertu = false, bool invertv = false, bool invert = true );
	virtual void SymAxis( TOGLTransf *, T3DPoint *p1, T3DPoint *p2 );
	virtual bool Rotate( TOGLTransf *, float, TNPlane, int fp = -1, int lp = -1 )
	{
		return false;
	}
	virtual bool Rotate( TOGLTransf *, float, T3DPoint, TNPlane, int fp = -1, int lp = -1 )
	{
		return false;
	}
	virtual void Move( TOGLTransf *, T3DPoint )
	{
	}
	virtual bool MoveFromTo( TOGLTransf *OGLTransf, T3DPoint org, T3DPoint dst );
	virtual bool RotateFromTo( TOGLTransf *, TNPlane, T3DPoint, T3DPoint, T3DPoint, int, int, double &, T3DVector *rotAxis = NULL );

	// Nueva libreria SMLib
	virtual bool Extend( TOGLTransf *OGLTransf, IwSurfParamType eExtDirection, double dDist, IwContinuityType eExtensionContinuity );
	virtual bool Intersect( TOGLTransf *OGLTransf, TCadSurface *surf, TCadGroup *curvesOut );
	virtual bool IntersectWithPlane( TOGLTransf *OGLTransf, T3DPlane *plane, TCadGroup *curvesOut );

	virtual bool GetInvertNormals( );
	virtual void SetInvertNormals( bool );

	virtual int GetSurfacesAmount( )
	{
		return 1;
	}
	virtual int GetSISLSurfacesAmount( )
	{
		return 1;
	}
	virtual void GetSurfaces( TCadGroup *Gr )
	{
		Gr->Add( this );
	}

	virtual bool IsFillEntity( bool usepoints = true )
	{
		return true;
	}

	virtual float Area( TOGLTransf * );
	virtual float Volume( TOGLTransf *, bool force = false );

	virtual void FillProp_General( TFormEntityData *properties );
	virtual void FillProp_Geom( TOGLTransf *OGLTransf, TFormEntityData *properties );
	virtual void FillProp_Advanced( TFormEntityData *properties );

	virtual UnicodeString WhoAmI( )
	{
		return ST_SURFACE;
	}
	virtual UnicodeString WhoIDSAmI( )
	{
		return "IDS_ST_SURFACE";
	}

	virtual bool AmIStrictEntity( )
	{
		return false;
	}
	virtual bool AmIStrictSurface( )
	{
		return true;
	}

	virtual bool AmISurface( )
	{
		return true;
	}
};

//------------------------------------------------------------------------------
// TCadLoftedSurface
//------------------------------------------------------------------------------

class TCadLoftedSurface : public TCadSurface
{
	friend class TImpExp_XML;

  protected:
	int ParamType;
	TCadGroup LoftCurves;
	double *Params;
	bool InvertUV;
	bool CombinedMode;

  protected:
	virtual bool CalcSISLSurface( TOGLTransf * );
	bool CalcSISLSurfaceType2( TOGLTransf *OGLTransf );
	bool CalcSISLSurfaceType3( TOGLTransf *OGLTransf );
	virtual T3DPoint *GetDataSurfaceToOptimunTesselation( TOGLTransf *OGLTransf, double **upar, double **vpar, int &UDim, int &vDim, int &uClose, int &vClose, double &angMax );

  public:
	TCadLoftedSurface( int pt = DEFAULT_PARAM_TYPE_LOFTED, int udegree = DEFAULT_DEGREE, int vdegree = DEFAULT_DEGREE );
	TCadLoftedSurface( TCadGroup *, int pt = DEFAULT_PARAM_TYPE_LOFTED, int vdegree = DEFAULT_DEGREE, int vclose = ENT_OPEN );
	TCadLoftedSurface( TCadLoftedSurface *S );
	virtual ~TCadLoftedSurface( );

	virtual bool MustCalcOGLLists( TOGLRenderSystem * );

	virtual void Set( TCadEntity *Ent, bool copyrels );
	virtual void SetBasic( TCadEntity *, bool copyrels );
	virtual void SetBasicGeometry( TCadEntity *S );
	virtual void SetBasicRels( TCadEntity *S );
	virtual void ChangeBasicRels( TCadEntity *orgbaseent, TCadEntity *dstbaseent, bool updatedirty = true, bool setdirty = false );
	virtual void GetBasicRelsEnts( TCadGroup *grp, bool usesurf = true, bool usemainaxissurf = true );

	virtual TCadGroup *GetLoftCurves( )
	{
		return &LoftCurves;
	}
	virtual double *GetParams( )
	{
		return Params;
	}
	virtual int GetParamType( )
	{
		return ParamType;
	}
	virtual void SetParamType( int paramType )
	{
		ParamType = paramType;
		SetAllDirty( true, true );
	}
	virtual bool GetCombinedMode( )
	{
		return CombinedMode;
	}
	virtual void SetCombinedMode( TOGLTransf *OGLTransf, bool combinedMode );

	virtual void CleanGroups( );
	virtual void GetUpRelatedEntities( TCadGroup *Group, bool rels = true, bool pointRels = true );
	virtual bool HasUpRelatedEntities( bool rels = true, bool pointRels = true, bool excludeparamsurf = false );
	virtual void DetachUpRelations( TCadGroup *, TPointRelationList *, TEntityRelationList *, bool updatedirty = true );
	virtual void ChangeOwnRelatedEntity( TCadEntity *ent );
	virtual void ChangeRelatedEntity( TCadEntity *orgent, TCadEntity *dstent, TCadGroup *gr = 0, bool setdirty = false );
	virtual void ClearOwnRelations( );

	virtual int GetUClose( );
	virtual int GetVClose( );
	virtual void SetVClose( int vClose );
	virtual int GetInvertUV( )
	{
		return InvertUV;
	}
	virtual void SetInvertUV( bool invertUV )
	{
		InvertUV = invertUV;
	}
	virtual void Invert( TOGLTransf * );
	virtual void InvertU( TOGLTransf * );
	virtual void InvertV( TOGLTransf * );
	virtual void MirrorX0( TOGLTransf *, bool invertu = false, bool invertv = false, bool invert = true );
	virtual void MirrorY0( TOGLTransf *, bool invertu = false, bool invertv = false, bool invert = true );
	virtual void SymAxis( TOGLTransf *, T3DPoint *p1, T3DPoint *p2 );
	virtual void ApplyMatrix( TOGLTransf *, TNMatrix *, bool recaldev = true, bool canusepbrep = true );
	virtual void ApplyMatrix( TOGLTransf *, TNMatrix *, int, int iEnd = -1 )
	{
	}
	virtual void Move( TOGLTransf *, T3DPoint );
	virtual bool MoveFromTo( TOGLTransf *, T3DPoint org, T3DPoint dst );
	virtual bool RotateFromTo( TOGLTransf *, TNPlane, T3DPoint, T3DPoint, T3DPoint, int, int, double &, T3DVector *rotAxis = NULL );
	virtual void Reduce( TOGLTransf *OGLTransf, double tolerance = 0.01 );

	virtual void FillProp_General( TFormEntityData *properties );

	virtual UnicodeString WhoAmI( )
	{
		return ST_LOFTEDSURFACE;
	}
	virtual UnicodeString WhoIDSAmI( )
	{
		return "IDS_ST_LOFTEDSURFACE";
	}

	virtual bool AmIStrictSurface( )
	{
		return false;
	}
	virtual bool AmIStrictLoftedSurface( )
	{
		return true;
	}
};

//------------------------------------------------------------------------------
// TCadTensorSurface
//------------------------------------------------------------------------------

class TCadTensorSurface : public TCadSurface
{
	friend class TImpExp_XML;

  public:
	T3DPoint *TensorPts;
	bool UseExtTensorPts; // Puntos extendidos para poder utilizar puntos deformados
	T3DPoint *ExtTensorPts;

	int *TensorEdit, CloseExtremes;
	bool *TensorErase;
	T3DPoint *TensorDer10, *TensorDer01, *TensorDer11;
	double *UParams, *VParams;
	int UDim, VDim, IPar;
	TCadGroup UCurves, VCurves;

  protected:
	virtual T3DPoint *SetParamData( TOGLTransf *, bool = false );
	virtual void RemoveParamData( TOGLTransf *, T3DPoint *, bool, bool = false );
	virtual void RemoveTensorDerivatives( );

	virtual bool CalcSISL( TOGLTransf * );
	virtual bool CalcSISLSurface( TOGLTransf * );
	virtual bool CalcSISLSurfaceAndCurves( TOGLTransf *, int, int );
	virtual void CompleteSISLSurface( TOGLTransf * );
	virtual bool CalcTensorCurves( TOGLTransf *, int, int );
	virtual bool CalcOGLPolygon( TOGLTransf * );

	virtual bool CalcOGLParam2DFromGeom3D( TOGLTransf * );

  public:
	TCadTensorSurface( int udegree = DEFAULT_DEGREE, int vdegree = DEFAULT_DEGREE );
	TCadTensorSurface( T3DPoint *, double *, double *, int, int, int udegree = DEFAULT_DEGREE, int vdegree = DEFAULT_DEGREE, int u = ENT_OPEN, int v = ENT_OPEN );
	TCadTensorSurface( T3DPoint *points, int ipar, int uDim, int vDim, int udegree = DEFAULT_DEGREE, int vdegree = DEFAULT_DEGREE, int u = ENT_OPEN, int v = ENT_OPEN );
	TCadTensorSurface( T3DPoint *points, T3DPoint *der10, T3DPoint *der01, T3DPoint *der11, int ipar, int uDim, int vDim, int udegree = DEFAULT_DEGREE, int vdegree = DEFAULT_DEGREE, int u = ENT_OPEN, int v = ENT_OPEN );
	TCadTensorSurface( TCadTensorSurface *S );
	TCadTensorSurface( TCadTensorSurface *S, int uIni, int uEnd );
	virtual ~TCadTensorSurface( );

	virtual void Set( TCadEntity *Ent, bool copyrels );
	virtual void SetBasic( TCadEntity *, bool copyrels );
	virtual void SetBasicGeometry( TCadEntity *S );
	virtual void SetTensorPoints( T3DPoint *points, double *upar, double *vpar, bool force = true );

	void SetUseExtTensorPts( TOGLTransf *OGLTransf, bool value, bool onlysisldirty = false );
	bool GetUseExtTensorPts( )
	{
		return UseExtTensorPts;
	}
	T3DPoint *GetExtTensorPts( )
	{
		return ExtTensorPts;
	}
	void SetExtTensorPts( T3DPoint *pts );
	void ClearExtTensorPts( );
	T3DPoint *GetCurTensorPts( );

	virtual void SetCloseExtremes( int value );

	virtual bool MustCalcOGLLists( TOGLRenderSystem * );

	virtual void GetDataPoint( TOGLTransf *OGLTransf, int, T3DPoint & );
	virtual T3DPoint GetDataPoint( TOGLTransf *OGLTransf, int u, int v );
	virtual int GetNearestPoint( T3DPoint, int u = -1 );
	T3DPoint GetNearestGeomPoint( TOGLTransf *OGLTransf, T3DPoint &pt );

	virtual bool CalcBoundRect( TOGLTransf *, T3DRect &, bool outrange = false, TNMatrix *mat = 0 );
	virtual bool GetBoundRectInPlane( TOGLTransf *, TLRect & );
	virtual bool CalcBoundRectViewport( TOGLTransf *, TLRect &, int step = 1, TNMatrix *MirrorMat = 0, TInstanceList *list = 0 );
	virtual bool DataBoundRect( TOGLTransf *OGLTransf, T3DRect &r, TNMatrix *mat = 0 );

	virtual TCadEntity *GetCurve( int i );
	virtual TCadEntity *GetUCurve( int i );
	virtual TCadEntity *GetVCurve( int i );

	virtual void SetDataEdition( int i, int edition );
	virtual int GetDataEdition( int i )
	{
		return TensorEdit[ i ];
	}
	virtual int GetSegmentEdition( int, int );
	virtual void ClearDataEdition( );
	virtual bool IsNormalEdition( int i );
	virtual bool IsNormalEdition( );
	virtual void SetBoundaryEdition( TRect R, TPoint mid, int edit_u, int edit_v, int edit_uv );
	virtual bool GetDataErasable( int i )
	{
		return TensorErase[ i ];
	}
	virtual void SetDataErasable( int i, bool e );
	virtual bool IsSegmentErasable( int, int );

	virtual void SetDrawMode( TOGLTransf *, int );
	virtual void SetDrawCurvesMode( TOGLTransf *, int );
	virtual void DrawOGL( TOGLTransf *, TOGLRenderData *, TOGLRenderSystem * );
	virtual void SelectOGL( TOGLTransf *, int, int, TOGLRenderData *, TOGLRenderSystem *, TInteger_List * = 0 );
	virtual void SelectTensorCurvesOGL( TOGLTransf *, TOGLRenderData *, TOGLRenderSystem * );
	virtual void DrawOGLDevelopWeights( TOGLTransf *, TInteger_List *, TOGLRenderData *, TOGLRenderSystem * );

	virtual bool GetOGLPointParam2DFromDevelop2D( TOGLTransf *OGLTransf, bool *close, TOGLPoint ptin, TOGLPoint &ptout );
	virtual TOGLPoint *GetOGLPointsParam2DFromDevelop2D( TOGLTransf *OGLTransf, bool *closein, int np, TOGLPoint *ptsin );

	virtual bool CalcTensorCurvesUV( TOGLTransf *, int );
	virtual bool ChangeParamSurface( TOGLTransf *, TCadSurface *ParamSurfDest );

	virtual bool IsInPlane( TOGLTransf *OGLTransf, T3DPlane &plane, double prec = RES_GEOM );
	virtual bool IsInPlane( TNPlane pl );

	virtual void MoveParamCenter( TOGLTransf *OGLTransf, double *limitsUV, TLPoint orgcenter, TLPoint dstcenter );

	virtual void GetIndexUVFromCurve( int, int &, int & );
	virtual void GetIndexUVFromSegment( int, int, int * );
	virtual void InsertIndexUV( int, int &, int & );
	virtual bool CheckRangeUV( TOGLTransf *, int, T3DPoint &, int );
	virtual bool GetUVFromPoint( int, int &, int & );
	virtual bool BelongToSelection( int index, int first, int second, int UDim, int );

	virtual TCadEntity *GetNewGeomEntity( TOGLTransf *OGLTransf );
	virtual TCadEntity *GetNewGeomEntityFromDevelop( TOGLTransf *OGLTransf );

	virtual bool Intersect( TOGLTransf *OGLTransf, T3DPoint point, TLPoint &ptUV )
	{
		return TCadSurface::Intersect( OGLTransf, point, ptUV );
	}
	virtual bool Intersect( TOGLTransf *OGLTransf, T3DVector vector, TLPoint &ptUV, T3DPoint &pt3D, T3DPoint &n3D, bool nearest = true )
	{
		return TCadSurface::Intersect( OGLTransf, vector, ptUV, pt3D, n3D, nearest );
	}
	virtual bool Intersect( TOGLTransf *OGLTransf, T3DVector vector, TOGLPolygon *out )
	{
		return TCadSurface::Intersect( OGLTransf, vector, out );
	}
	virtual bool Intersect( TOGLTransf *OGLTransf, T3DPlane plano, TCadGroup *curves, int represent = 2 )
	{
		return TCadSurface::Intersect( OGLTransf, plano, curves, represent );
	}
	virtual bool Intersect( TOGLTransf *OGLTransf, SISLCurve *curve, TCadGroup *curves, int represent )
	{
		return TCadSurface::Intersect( OGLTransf, curve, curves, represent );
	}
	virtual bool Intersect( TOGLTransf *OGLTransf, TPoint Size, TRect Range, T3DPlane plane, TOGLPolygonList *OGLList, bool = true, TNPlane forceplane = plNone, T3DPoint ptplane = T3DPoint( 0.0, 0.0, 0.0 ) );
	virtual bool Intersect( TOGLTransf *OGLTransf, TCadSurface *surf2, int represent, bool forcejoin, TCadGroup *curves )
	{
		return TCadSurface::Intersect( OGLTransf, surf2, represent, forcejoin, curves );
	}
	virtual bool Intersect( TOGLTransf *OGLTransf, TCadSurface *surf2, TCadGroup *curvesOut )
	{
		return TCadSurface::Intersect( OGLTransf, surf2, curvesOut );
	}
	virtual bool IntersectWithUCurves( TOGLTransf *OGLTransf, TCadShape *Ent, T3DPoint **Points, int **IndexU, int &np );
	virtual void RemoveIntersectItselfXY( TOGLTransf *OGLTransf );

	virtual void RotatePlaneAngleArea( TOGLTransf *OGLTransf, float angle, T3DPoint center, T3DPoint *ptline, bool invertU, bool back, double smooth, double distribution );
	virtual void RotatePlaneUArea( TOGLTransf *OGLTransf, int ustart, int vstart, int vend, double angle, T3DPoint center, double smooth, int *uindex = 0, double pct = 0.0 );
	virtual void MovePlaneArea( TOGLTransf *OGLTransf, T3DPlane plane, double distoadd, double smooth, double distribution );
	virtual void MovePlaneArea( TOGLTransf *OGLTransf, T3DPlane plane, T3DPoint incr, double smooth, double smooth2 = -1.0 );
	virtual void MovePlaneUArea( TOGLTransf *OGLTransf, int u, int vstart, int vend, T3DPoint incr, double smooth, bool xincr, double distribution = 1.0, TInteger_List *weighttypes = 0 );
	virtual void MovePlaneUAreaWithCurve( TOGLTransf *OGLTransf, int u, TOGLPolygon *PolIncr, double smooth, double distribution = 1.0 );
	virtual void MovePlaneVAreaWithCurve( TOGLTransf *OGLTransf, int v, TOGLPolygon *PolIncr, double smooth, double distribution = 1.0 );
	virtual void MovePlaneUVAreaWithCurve( TOGLTransf *, TOGLPolygon **PolIncr, double smooth, double distribution = 1.0 );
	virtual void MeanPlaneUArea( TOGLTransf *OGLTransf, int u, TCadTensorSurface *surf, int usurf, int vstart, int vend, double smooth, double distribution );
	virtual void MeanPlaneVArea( TOGLTransf *OGLTransf, int v, TCadTensorSurface *surf, int vsurf, int ustart, int uend, double smooth, double distrib_start, double distrib_end, bool smooth2start, bool smooth2end, bool invert );
	virtual void MeanPlaneUAreaWithCurve( TOGLTransf *OGLTransf, TOGLPolygon *PolDevStart, TOGLPolygon *PolDevEnd, int ustart, int vstart, int vend, double factor, double smooth );
	virtual void AdjustULength( TOGLTransf *OGLTransf, TCadSurface *surf3D, int devindex, int uoffset3D, int vstart, int ustart, double distance );
	virtual void AdjustVLength( TOGLTransf *OGLTransf, TCadSurface *surf3D, TOGLPolygonList *ListGeom, TOGLPolygonList *ListDev, int uoffset3D, int ustart, int uend, int vstart, TInteger_List *weighttypes, bool alwaysustart, double factor );
	virtual void AdjustToCurve( TOGLTransf *OGLTransf, TCadShape *Ent );
	virtual void AdjustToPolygon( TOGLTransf *OGLTransf, TOGLPolygon *Pol, int ustart, int uend, int vstart );
	virtual void MoveVLength( TOGLTransf *OGLTransf, int ustart, int vstart, double distance, double smooth );
	virtual void EndVConditions( TOGLTransf *OGLTransf, TCadTensorSurface *surf, int ustart, int usurfstart, int vstart, int vend, int *uindex, int *usurfindex, double factor );
	virtual void EndVConditions( TOGLTransf *OGLTransf, TCadSurface *surf3D, int vstart, bool invert );
	virtual void EndVConditions( TOGLTransf *OGLTransf, TCadTensorSurface *surf, int vstart, int vend, double factor );

	virtual bool Rotate( TOGLTransf *, float, TNPlane, int fp = -1, int lp = -1 );
	virtual bool Rotate( TOGLTransf *, float, T3DPoint, TNPlane, int fp = -1, int lp = -1 );
	virtual bool Move( TOGLTransf *, int, T3DPoint, bool valid = true, bool tol = true, double vtol = RES_COMP );
	virtual void Move( TOGLTransf *OGLTransf, T3DPoint P );
	virtual void MoveByPolygon( TOGLTransf *, TOGLPolygon *P );
	virtual void Offset( TOGLTransf *OGLTransf, T3DPointF **normals, double offset );

	virtual void AddCurves( TOGLTransf *, int *, int, TOGLPolygon *, TOGLPolygon * );
	virtual void DeleteCurves( int * );
	virtual void SmoothUV( TOGLTransf *, int *uv, bool u );
	virtual bool MoveUV( TOGLTransf *, int ind, double dist, int edit_type, bool dirty = true );

	virtual void ApplyMatrix( TOGLTransf *, TNMatrix *matrix, bool recaldev = true, bool canusepbrep = true );
	virtual void ApplyMatrix( TOGLTransf *, TNMatrix *, int, int iEnd = -1 );

	virtual void Invert( TOGLTransf * );
	virtual void InvertU( TOGLTransf * );
	virtual void InvertV( TOGLTransf * );
	virtual void InvertCoordsUV( );
	virtual void InvertCoord( int, double, double );

	virtual void HMirror( TOGLTransf *, TNPlane forceplane = plNone );
	virtual void HMirror( TOGLTransf *, T3DPoint, T3DPoint, TNPlane forceplane = plNone );
	virtual void VMirror( TOGLTransf *, TNPlane forceplane = plNone );
	virtual void VMirror( TOGLTransf *, T3DPoint, T3DPoint, TNPlane forceplane = plNone );
	virtual void MirrorX0( TOGLTransf *, bool invertu = false, bool invertv = false, bool invert = true );
	virtual void MirrorY0( TOGLTransf *, bool invertu = false, bool invertv = false, bool invert = true );
	virtual void SymAxis( TOGLTransf *, T3DPoint *p1, T3DPoint *p2 );
	virtual bool MoveFromTo( TOGLTransf *OGLTransf, T3DPoint org, T3DPoint dst );
	virtual bool RotateFromTo( TOGLTransf *, TNPlane, T3DPoint, T3DPoint, T3DPoint, int, int, double &, T3DVector *rotAxis = NULL );

	virtual void FillProp_Geom( TOGLTransf *OGLTransf, TFormEntityData *properties );

	bool GetNormalUV( int u, int v, T3DPoint &p );

	virtual void GetSection( int u, TOGLPolygon *polOut );
	virtual void SetSection( int u, TOGLPolygon *pol );
	virtual void GetSections( TOGLPolygonList *list );
	virtual void SetSections( TOGLPolygonList *list );

	// Algoritmo de la galleta
	virtual void GetSection( int u, T3DPolygon *polOut );
	virtual void SetSection( int u, T3DPolygon *pol );
	virtual void GetSections( T3DPolygonList *list );
	virtual void SetSections( T3DPolygonList *list );
	virtual bool CalcOGLPolygonOptimum( TOGLTransf *OGLTransf, double angMax = 10.0 );
	virtual UnicodeString WhoAmI( )
	{
		return ST_TENSORSURFACE;
	}
	virtual UnicodeString WhoIDSAmI( )
	{
		return "IDS_ST_TENSORSURFACE";
	}

	virtual bool AmIStrictSurface( )
	{
		return false;
	}
	virtual bool AmIStrictTensorSurface( )
	{
		return true;
	}
};

//------------------------------------------------------------------------------
// TCadGordonSurface
//------------------------------------------------------------------------------

class TCadGordonSurface : public TCadSurface
{
	friend class TImpExp_XML;

  protected:
	bool CheckInvertSections, CloseProfilesContinuity;
	int CloseProfilesContinuityTimes;
	double CurvesFilterDist;
	bool CurvesFilterCornerDetection;
	TCadGroup Sections, Profiles;
	double CompleteKnotsParamDist;

  protected:
	virtual bool CalcSISLSurface( TOGLTransf * );

  public:
	TCadGordonSurface( int udegree = DEFAULT_DEGREE, int vdegree = DEFAULT_DEGREE );
	TCadGordonSurface( int type, TCadGroup *, TCadGroup *, int uclose = ENT_OPEN );
	TCadGordonSurface( TCadGordonSurface *S );
	virtual ~TCadGordonSurface( )
	{
	}

	virtual bool MustCalcOGLLists( TOGLRenderSystem * );

	virtual void Set( TCadEntity *Ent, bool copyrels );
	virtual void SetBasic( TCadEntity *, bool copyrels );
	virtual void SetBasicGeometry( TCadEntity *S );
	virtual void SetBasicRels( TCadEntity *S );
	virtual void ChangeBasicRels( TCadEntity *orgbaseent, TCadEntity *dstbaseent, bool updatedirty = true, bool setdirty = false );
	virtual void GetBasicRelsEnts( TCadGroup *grp, bool usesurf = true, bool usemainaxissurf = true );

	virtual TCadGroup *GetSections( )
	{
		return &Sections;
	}
	virtual TCadGroup *GetProfiles( )
	{
		return &Profiles;
	}

	virtual TCadGordonProfile *AddProfileOneSection( TOGLTransf *OGLTransf, int addtype, TCadShape *orgshape, double pct, double pct2, double pct3, bool forcedata = false );
	virtual TCadGordonProfile *AddProfileMultiSection( TOGLTransf *OGLTransf, int addtype, TCadShape *orgshape, double pct, double pct2, TCadGroup *PointRelationGrp = 0 );

	virtual bool IsIndependent( bool checkpointrels = true );

	virtual bool GetCheckInvertSections( );
	virtual void SetCheckInvertSections( bool value );
	virtual bool GetCloseProfilesContinuity( );
	virtual void SetCloseProfilesContinuity( bool value );
	virtual double GetCurvesFilterDist( );
	virtual void SetCurvesFilterDist( double value );
	virtual bool GetCurvesFilterCornerDetection( );
	virtual void SetCurvesFilterCornerDetection( bool value );
	virtual double GetCompleteKnotsParamDist( );
	virtual void SetCompleteKnotsParamDist( double value );

	virtual void CleanGroups( );
	virtual void GetUpRelatedEntities( TCadGroup *Group, bool rels = true, bool pointRels = true );
	virtual bool HasUpRelatedEntities( bool rels = true, bool pointRels = true, bool excludeparamsurf = false );
	virtual void DetachUpRelations( TCadGroup *, TPointRelationList *, TEntityRelationList *, bool updatedirty = true );
	virtual void ChangeOwnRelatedEntity( TCadEntity *ent );
	virtual void ChangeRelatedEntity( TCadEntity *orgent, TCadEntity *dstent, TCadGroup *gr = 0, bool setdirty = false );
	virtual void ClearOwnRelations( );

	virtual void SetUClose( int uclose );
	virtual void Invert( TOGLTransf * )
	{
	}
	virtual void InvertU( TOGLTransf * )
	{
	}
	virtual void InvertV( TOGLTransf * )
	{
	}
	virtual void MirrorX0( TOGLTransf *, bool invertu = false, bool invertv = false, bool invert = true );
	virtual void MirrorY0( TOGLTransf *, bool invertu = false, bool invertv = false, bool invert = true );
	virtual void SymAxis( TOGLTransf *, T3DPoint *p1, T3DPoint *p2 );
	virtual void ApplyMatrix( TOGLTransf *, TNMatrix *, bool recaldev = true, bool canusepbrep = true );
	virtual void ApplyMatrix( TOGLTransf *, TNMatrix *, int, int iEnd = -1 )
	{
	}
	virtual void ApplyMatrixBaseEnts( TOGLTransf *, TNMatrix *, bool recaldev = true, bool canusepbrep = true );
	virtual void Move( TOGLTransf *, T3DPoint );
	virtual bool MoveFromTo( TOGLTransf *, T3DPoint org, T3DPoint dst );
	virtual bool RotateFromTo( TOGLTransf *, TNPlane, T3DPoint, T3DPoint, T3DPoint, int, int, double &, T3DVector *rotAxis = NULL );

	virtual void FillProp_General( TFormEntityData *properties );

	virtual UnicodeString WhoAmI( )
	{
		return ST_GORDONSURFACE;
	}
	virtual UnicodeString WhoIDSAmI( )
	{
		return "IDS_ST_GORDONSURFACE";
	}

	virtual bool AmIStrictSurface( )
	{
		return false;
	}
	virtual bool AmIStrictGordonSurface( )
	{
		return true;
	}
};

//------------------------------------------------------------------------------
// TCadDepSurface
//------------------------------------------------------------------------------

class TCadDepSurface : public TCadSurface
{
	friend class TImpExp_XML;

  protected:
	TCadGroup BaseEntities;
	TOffsetVarData OffsetVarData;

  protected:
	virtual bool CalcSISLSurface( TOGLTransf * );
	virtual bool CalcOGLPolygon( TOGLTransf * );

	virtual bool CalcDevelopSurfaces( TOGLTransf *, bool start = true )
	{
		return false;
	}
	virtual bool CalcDevelopSurfacesEdges( TOGLTransf * )
	{
		return false;
	}

  public:
	TCadDepSurface( );
	TCadDepSurface( int deptype, TCadSurface *surf );
	TCadDepSurface( TCadDepSurface *S );
	virtual ~TCadDepSurface( )
	{
	}

	virtual void Set( TCadEntity *Ent, bool copyrels );
	virtual void SetBasic( TCadEntity *Ent, bool copyrels );
	virtual void SetBasicGeometry( TCadEntity *S )
	{
	} // no tratado
	virtual void SetBasicRels( TCadEntity *S );
	virtual void ChangeBasicRels( TCadEntity *orgbaseent, TCadEntity *dstbaseent, bool updatedirty = true, bool setdirty = false );
	virtual void GetBasicRelsEnts( TCadGroup *grp, bool usesurf = true, bool usemainaxissurf = true );

	//		virtual void SetSISLDirty( bool b, bool increasedirtyid = true ) { TCadEntity::SetSISLDirty( b, increasedirtyid ); }
	//		virtual void SetPolygonDirty( bool b, bool increasedirtyid = true ) { TCadEntity::SetPolygonDirty( b, increasedirtyid ); }

	virtual bool MustCalcOGLLists( TOGLRenderSystem * );
	virtual void UpdateOGLRenderData( TOGLRenderData *_OGLRdData, TColor _maxColor, TColor _minColor );

	virtual void CleanGroups( );
	virtual void DetachUpRelations( TCadGroup *, TPointRelationList *, TEntityRelationList *, bool updatedirty = true );

	virtual void ChangeOwnRelatedEntity( TCadEntity *ent );
	virtual void ChangeRelatedEntity( TCadEntity *orgent, TCadEntity *dstent, TCadGroup *gr = 0, bool setdirty = false );
	virtual void GetUpRelatedEntities( TCadGroup *Group, bool rels = true, bool pointRels = true );
	virtual bool HasUpRelatedEntities( bool rels = true, bool pointRels = true, bool excludeparamsurf = false );
	virtual void ClearOwnRelations( );
	virtual void FillProp_General( TFormEntityData *properties );
	virtual void FillProp_Advanced( TFormEntityData *properties );
	virtual TCadSurface *GetBaseSurface( );
	virtual TCadGroup *GetBaseEntities( )
	{
		return &BaseEntities;
	}

	virtual TOffsetVarData *GetOffsetVarData( );
	virtual void SetOffsetVarData( TOffsetVarData *data );
	virtual void SetOffsetVarRes( int res );
	virtual bool CalcOffsetVarData( TOGLTransf *OGLTransf, T3DPoint pt, double offset, double distance, double smooth );
	virtual bool CalcOffsetVarData( TOGLTransf *OGLTransf, TOGLPolygon *polparam, double offset, double smooth, TOffsetVarData *offsetvardata );

	virtual bool IsOffsetVarDepSurface( );
	virtual bool IsOffsetVarDepSurface1( );
	virtual bool IsOffsetVarDepSurface2( );

	virtual bool PointParamToPointDev( TOGLTransf *OGLTransf, bool forcedevsurfindex, int devindex, T3DPoint pt, T3DPoint &pt2D, int *devsurfindex = 0 );
	virtual bool PointDevToPointParam( TOGLTransf *OGLTransf, bool forcedevsurfindex, int devindex, T3DPoint pt2D, TOGLPolygon *PolParam, bool forceinside = false, bool alldevsurfindex = false );

	virtual TCadGroup *GetTransfDevelopSurfaces( TOGLTransf *, int devindex = -1 );
	virtual TOGLPolygonList *GetTransfDevelopSurfacesEdges( TOGLTransf *OGLTransf, int devindex = -1 );
	virtual TDevelopList *GetDevelopList( );
	virtual void GetDevelopLimitsUV( TOGLTransf *, int i, double *limits );
	virtual void GetDevelopLimitsUV( TOGLTransf *OGLTransf, double *devlimits, double *limits );

	virtual bool CalcDevelopErrors( TOGLTransf * )
	{
		return false;
	}

	virtual TCadSurface *GetSurfaceSmall( TOGLTransf * );
	virtual void SetSurfaceSmallValues( int method, double reductionvalue );
	virtual void SetUseSurfaceSmallToNormals( bool value );
	virtual void SetUseSurfaceSmallToSelect( bool value );
	virtual void SetUseSurfaceSmallToDevelopTrims( bool value );

	////////////////////////

	virtual bool GetPoint( TOGLTransf *, double pu, double pv, T3DPoint &p );
	virtual bool GetPointAndNormal( TOGLTransf *, double pu, double pv, T3DPoint &p, T3DPoint &n );
	//		virtual bool GetPointAndDerivatives( TOGLTransf*, double pu,double pv, T3DPoint* p );

	//		virtual T3DPoint *GetPoints( TOGLTransf*, int, int );
	//		virtual T3DPoint *GetPoints( TOGLTransf*, int, double*, int, double* );
	//		virtual T3DPoint *GetPointsRes( TOGLTransf*, double, int&, int& ); //defecto double = 1.0; si es 2.0 devuelve el doble de la longitud +- en mm, ....
	//		virtual TOGLPoint **GetPoints2( TOGLTransf*, int, int );

	//		virtual void GetPointsAndNormals2( TOGLTransf*, int, double*, int, double*, T3DPointF ***Points, T3DPointF ***Normals );
	//		virtual void GetPointsAndNormalsAndParams2( TOGLTransf*, double *limits, int ures, int vres, int &nu, int &nv, T3DPointF ***Points, T3DPointF ***Normals, double **upar, double **vpar );

	//		virtual T3DPoint **GetPointsAndParams2( TOGLTransf*, int, int, double**, double**);
	//		virtual void GetPointsAndNormalsAndParams2( TOGLTransf*, int nu, int nv,  double** upar,  double** vpar,T3DPoint ***points, T3DPoint ***normals);
	//		virtual bool GetExtremePoint( TOGLTransf*, T3DVector vector, T3DPoint& point, double* limits = NULL);

	//		virtual bool GetExtOGLGeomParam( TOGLTransf *OGLTransf, TOGLPolygonList *ingeomlist, T3DPoint ptguess, bool isdevelopable, bool forcedevsurfindex, int devsurfindex, TOGLPolygonList *outparamlist, TOGLPolygonList *outgeomlist, double paramoffset = PARAM_OFFSET_MARKER_DEFAULT );
	//////////////////////////////////////////////////

	virtual bool MoveFromTo( TOGLTransf *OGLTransf, T3DPoint org, T3DPoint dst )
	{
		return false;
	}
	virtual void Move( TOGLTransf *, T3DPoint )
	{
	}

	virtual void FitToRect( TOGLTransf *, T3DPoint, T3DPoint )
	{
	}
	virtual void HMirror( TOGLTransf *, TNPlane forceplane = plNone )
	{
	}
	virtual void HMirror( TOGLTransf *, T3DPoint, T3DPoint, TNPlane forceplane = plNone )
	{
	}
	virtual void VMirror( TOGLTransf *, TNPlane forceplane = plNone )
	{
	}
	virtual void VMirror( TOGLTransf *, T3DPoint, T3DPoint, TNPlane forceplane = plNone )
	{
	}
	virtual bool Rotate( TOGLTransf *, float, TNPlane, int fp = -1, int lp = -1 )
	{
		return false;
	}
	virtual bool Rotate( TOGLTransf *, float, T3DPoint, TNPlane, int fp = -1, int lp = -1 )
	{
		return false;
	}

	virtual bool IsRasterImage( )
	{
		return false;
	}
	virtual bool IsTransparentBackground( )
	{
		return false;
	}
	virtual bool IsTransparentBackground2D( )
	{
		return false;
	}
	virtual bool IsTransparentBackground3D( )
	{
		return false;
	}

	virtual bool IsEditable( )
	{
		return false;
	}
	virtual bool IsIndependent( bool checkpointrels = true )
	{
		return false;
	}
	virtual bool CanApplyTransform( bool checkpointrels = true )
	{
		return false;
	}

	virtual UnicodeString WhoAmI( )
	{
		return ST_DEPSURFACE;
	}
	virtual UnicodeString WhoIDSAmI( );

	virtual bool AmIStrictSurface( )
	{
		return false;
	}
	virtual bool AmIStrictDepSurface( )
	{
		return true;
	}
};

//------------------------------------------------------------------------------
// TCadTrimSurface
//------------------------------------------------------------------------------

class TCadTrimSurface : public TCadEntity
{
	friend class TImpExp_XML;

  protected:
	TCadSurface *TrimSurface;
	TCadGroup TrimCurves;

	TDevelopList *DevelopList;
	bool IsCalcDevSurfsDirty;

	bool InvertNormals;
	bool UseSurfaceSmallToDevelop;

	TOGLPolygonList OGLBoundariesList;
	int OGLBoundariesListFilter;
	bool OGLBoundariesListRestore;
	TParallelDataList ParallelDataList;

	double TempDevelopOffset3D;

  protected:
	virtual bool CalcOGLLists( TOGLTransf * );
	virtual bool CalcOGLPolygon( TOGLTransf * );
	virtual bool CalcOGLPolygonDevelop2D( TOGLTransf * );
	virtual bool CalcOGLBoundaries( TOGLTransf * );
	virtual bool CalcDevelopSurfaces( TOGLTransf *, bool start = true );
	virtual bool CalcTextureCoords( TOGLTransf *, TOGLTexture * );
	virtual bool CalcBaseTextureCoords( TOGLTransf *, TOGLPolygonList *, int index = -1 );

  public:
	TCadTrimSurface( );
	TCadTrimSurface( TCadSurface *s, TCadEntity *c, TOGLTransf *, double tol = RES_PARAM );
	TCadTrimSurface( TCadTrimSurface *s );
	virtual ~TCadTrimSurface( );

	virtual void Set( TCadEntity *Ent, bool copyrels );
	virtual void SetBasic( TCadEntity *, bool copyrels );
	virtual void SetBasicRels( TCadEntity *S );
	virtual void ChangeBasicRels( TCadEntity *orgbaseent, TCadEntity *dstbaseent, bool updatedirty = true, bool setdirty = false );
	virtual void GetBasicRelsEnts( TCadGroup *grp, bool usesurf = true, bool usemainaxissurf = true );

	virtual bool MustCalcOGLLists( TOGLRenderSystem * );

	virtual TCadSurface *GetBaseSurface( );
	virtual TCadSurface *GetTrimSurface( )
	{
		return TrimSurface;
	}
	virtual TCadGroup *GetTrimCurves( )
	{
		return &TrimCurves;
	}
	virtual void SetTrimSurface( TCadSurface *s );

	virtual TOGLPolygonList *GetOGLBoundariesList( TOGLTransf *OGLTransf, bool &restore, bool onlyboundaries = false, bool recalc = true );
	virtual bool CheckExtOGLBoundaries( TOGLTransf *OGLTransf, TOGLPolygonList *oglboundarieslist );
	virtual bool GetExtOGLListByBoundaries( TOGLTransf *OGLTransf, TOGLPolygonList *oglboundarieslist, bool restore, TOGLPolygonList *out );
	virtual bool GetExtOGLListByBoundariesDevelop2D( TOGLTransf *OGLTransf, TOGLPolygonList *oglboundarieslist, bool restore, TOGLPolygonList *out );

	virtual TParallelDataList *GetParallelDataList( );
	virtual void SetParallelDataList( TParallelDataList * );
	virtual TCadSurface *GetPeriodicSurface( TOGLTransf *, TCadSurface *surf = 0, double *limitsUV = 0 );
	virtual void GetPeriodicPWLCurve( TOGLTransf *, int, GLfloat *, TLRect );

	virtual void CleanGroups( );
	virtual void DetachUpRelations( TCadGroup *, TPointRelationList *, TEntityRelationList *, bool updatedirty = true );
	virtual void ChangeOwnRelatedEntity( TCadEntity *ent );
	virtual void ChangeRelatedEntity( TCadEntity *orgent, TCadEntity *dstent, TCadGroup *gr = 0, bool setdirty = false );
	virtual void GetUpRelatedEntities( TCadGroup *Group, bool rels = true, bool pointRels = true );
	virtual bool HasUpRelatedEntities( bool rels = true, bool pointRels = true, bool excludeparamsurf = false );
	virtual void ClearOwnRelations( );

	virtual bool IsEditable( )
	{
		return false;
	}
	virtual bool IsIndependent( bool checkpointrels = true )
	{
		return false;
	}
	virtual bool CanApplyTransform( bool checkpointrels = true )
	{
		return false;
	}

	virtual int GetTrimSurfacesAmount( )
	{
		return 1;
	}

	virtual TCadGroup *GetTransfDevelopSurfaces( TOGLTransf *, int devindex = -1 );
	virtual TDevelopList *GetDevelopList( )
	{
		return DevelopList;
	}
	virtual void SetDevelopList( TOGLTransf *, TDevelopList *devlist, bool del = true, bool copy = true, bool checkindexes = true ); // ruben
	virtual bool HasDevelopData( );
	virtual bool HasDevelop( );
	virtual bool CalcDevelopErrors( TOGLTransf * );

	virtual TLPoint GetLengthUV( TOGLTransf *, double *limits );
	virtual void GetLimitsUV( TOGLTransf *, double *limits );
	virtual void GetLimitsUVAllCurves( TOGLTransf *, double *limits );
	virtual bool GetDevelopDataLimitsUV( TOGLTransf *, TCadSurface *surf, double *limitsUV, double *devdatalimits );

	virtual bool GetExtOGLDevelop2DFromParam2D( TOGLTransf *OGLTransf, TOGLPolygonList *inlist, TOGLPolygonList *outlist, bool meshlist = false );
	virtual bool GetExtOGLParam2DFromDevelop2D( TOGLTransf *OGLTransf, TOGLPolygonList *devlist, TOGLPolygonList *paramlist );
	virtual bool GetExtBasicOGLParam2DFromDevelop2D( TOGLTransf *OGLTransf, TOGLPolygonList *devlist, TOGLPolygonList *paramlist );

	virtual bool PointParamToPointDev( TOGLTransf *OGLTransf, T3DPoint pt, T3DPoint &pt2D );
	virtual bool PointDevToPointParam( TOGLTransf *OGLTransf, T3DPoint pt2D, TOGLPolygon *PolParam, bool forceinside = false );

	virtual bool Intersect( TOGLTransf *, T3DVector vector, TLPoint &ptUV, T3DPoint &pt3D, T3DPoint &n3D, bool nearest = true );

	virtual void SetSISLDirty( bool b, bool increasedirtyid = true );
	virtual void ForceDevSurfsDirty( int level, int devindex = -1, bool increasedirtyid = true );
	virtual bool IsTransfDevSurfsDirty( int devindex = -1 );
	virtual bool IsAnyDevSurfsDirty( );
	virtual void SetCalcDevSurfsDirty( bool value );
	virtual void SetTransfDevSurfsDirty( bool value, int devindex = -1 );

	virtual bool GetInvertNormals( );
	virtual void SetInvertNormals( bool );

	virtual void SetUseSurfaceSmallToDevelop( bool value );
	virtual bool GetUseSurfaceSmallToDevelop( );

	virtual void MirrorX0( TOGLTransf *, bool invertu = false, bool invertv = false, bool invert = true );
	virtual void MirrorY0( TOGLTransf *, bool invertu = false, bool invertv = false, bool invert = true );
	virtual void SymAxis( TOGLTransf *, T3DPoint *, T3DPoint * );

	virtual void SelectOGL( TOGLTransf *, int, int, TOGLRenderData *, TOGLRenderSystem *, TInteger_List * = 0 );

	virtual double GetTempDevelopOffset3D( )
	{
		return TempDevelopOffset3D;
	}
	virtual void SetTempDevelopOffset3D( double value );

	virtual bool IsFillEntity( bool usepoints = true )
	{
		return true;
	}

	virtual float Area( TOGLTransf * );

	virtual void FillProp_General( TFormEntityData *properties );
	virtual void FillProp_Geom( TOGLTransf *, TFormEntityData *properties );
	virtual void FillProp_Advanced( TFormEntityData *properties );

	virtual UnicodeString WhoAmI( )
	{
		return ST_TRIMSURFACE;
	}
	virtual UnicodeString WhoIDSAmI( )
	{
		return "IDS_ST_TRIMSURFACE";
	}

	virtual bool AmIStrictEntity( )
	{
		return false;
	}
	virtual bool AmIStrictTrimSurface( )
	{
		return true;
	}
};

//------------------------------------------------------------------------------
// TCadTessPolygon
//------------------------------------------------------------------------------

class TCadTessPolygon : public TCadEntity
{
	friend class TImpExp_XML;

  protected:
	TCadGroup TessCurves;
	TNPlane Plane;
	double DivideTrianglesMaxLength;
	bool CanFilterOGLBoundariesList;
	TOGLPolygonList OGLBoundariesList;
	TParallelDataList ParallelDataList;
	TTessPolygonTempOGLLists TempOGLLists;

  protected:
	virtual bool CalcOGLLists( TOGLTransf * );
	virtual bool CalcOGLPolygon( TOGLTransf * );
	virtual bool CalcOGLBoundaries( TOGLTransf * );
	virtual bool CalcTextureCoords( TOGLTransf *, TOGLTexture * );
	virtual bool CalcBaseTextureCoords( TOGLTransf *, TOGLPolygonList *, int index = -1 );

  public:
	TCadTessPolygon( );
	TCadTessPolygon( TCadEntity *c, TOGLTransf *, TNPlane pl = plXY, int type = TESS_ONLY1HOLELEVEL );
	TCadTessPolygon( TCadTessPolygon *s );
	virtual ~TCadTessPolygon( );

	virtual void Set( TCadEntity *Ent, bool copyrels );
	virtual void SetBasic( TCadEntity *, bool copyrels );
	virtual void SetBasicRels( TCadEntity *S );
	virtual void ChangeBasicRels( TCadEntity *orgbaseent, TCadEntity *dstbaseent, bool updatedirty = true, bool setdirty = false );
	virtual void GetBasicRelsEnts( TCadGroup *grp, bool usesurf = true, bool usemainaxissurf = true );

	virtual bool MustCalcOGLLists( TOGLRenderSystem * );
	virtual TOGLPolygonList *GetOGLBoundariesList( TOGLTransf *OGLTransf, bool recalc = true );
	TOGLPolygon *GetExtBoundary( TOGLTransf *OGLTransf, bool usetempogllists );
	virtual TParallelDataList *GetParallelDataList( );
	virtual void SetParallelDataList( TParallelDataList * );

	virtual void SetType( int type );

	TNPlane GetPlane( )
	{
		return Plane;
	}

	virtual double GetDivideTrianglesMaxLength( )
	{
		return DivideTrianglesMaxLength;
	}
	virtual void SetDivideTrianglesMaxLength( double value );

	virtual bool GetCanFilterOGLBoundariesList( )
	{
		return CanFilterOGLBoundariesList;
	}
	virtual void SetCanFilterOGLBoundariesList( bool value );

	virtual TCadGroup *GetTessCurves( )
	{
		return &TessCurves;
	}

	TTessPolygonTempOGLLists *GetTempOGLLists( )
	{
		return &TempOGLLists;
	}
	void SetTempOGLLists( TTessPolygonTempOGLLists *lists );
	void ClearTempOGLLists( );

	virtual void CleanGroups( );
	virtual void DetachUpRelations( TCadGroup *, TPointRelationList *, TEntityRelationList *, bool updatedirty = true );
	virtual void ChangeOwnRelatedEntity( TCadEntity *ent );
	virtual void ChangeRelatedEntity( TCadEntity *orgent, TCadEntity *dstent, TCadGroup *gr = 0, bool setdirty = false );
	virtual void GetUpRelatedEntities( TCadGroup *Group, bool rels = true, bool pointRels = true );
	virtual bool HasUpRelatedEntities( bool rels = true, bool pointRels = true, bool excludeparamsurf = false );
	virtual void ClearOwnRelations( );

	virtual bool IsInPlane( TOGLTransf *OGLTransf, T3DPlane &plane, double prec = RES_GEOM );
	virtual bool IsInPlane( TNPlane pl );

	virtual bool IsEditable( )
	{
		return false;
	}
	virtual bool IsIndependent( bool checkpointrels = true )
	{
		return false;
	}
	virtual bool CanApplyTransform( bool checkpointrels = true )
	{
		return false;
	}

	virtual int GetMeshesAmount( )
	{
		return 1;
	}

	virtual bool IsFillEntity( bool usepoints = true )
	{
		return true;
	}

	virtual float Area( TOGLTransf * );

	virtual void FillProp_General( TFormEntityData *properties );
	virtual void FillProp_Geom( TOGLTransf *OGLTransf, TFormEntityData *properties );

	virtual UnicodeString WhoAmI( )
	{
		return ST_TESSPOLYGON;
	}
	virtual UnicodeString WhoIDSAmI( )
	{
		return "IDS_ST_TESSPOLYGON";
	}

	virtual bool AmIStrictEntity( )
	{
		return false;
	}
	virtual bool AmIStrictTessPolygon( )
	{
		return true;
	}
};

//------------------------------------------------------------------------------

TCadEntity *_CreateShape( UnicodeString );
TCadEntity *_CreateShape( TCadEntity *, bool copyrels );
TCadEntity *_CreateBasicShape( TCadEntity *, bool copyrels );

#define ToShape( E )		 ( dynamic_cast<TCadShape *>( E ) )
#define ToPoint( E )		 ( dynamic_cast<TCadPoint *>( E ) )
#define ToEditPlane( E )	 ( dynamic_cast<TCadEditPlane *>( E ) )
#define ToMeasure( E )		 ( dynamic_cast<TCadMeasure *>( E ) )
#define ToLine( E )			 ( dynamic_cast<TCadLine *>( E ) )
#define ToPolyline( E )		 ( dynamic_cast<TCadPolyline *>( E ) )
#define ToBSpline( E )		 ( dynamic_cast<TCadBSpline *>( E ) )
#define ToIBSpline( E )		 ( dynamic_cast<TCadIBSpline *>( E ) )
#define ToGordonProfile( E ) ( dynamic_cast<TCadGordonProfile *>( E ) )
#define ToRect( E )			 ( dynamic_cast<TCadRect *>( E ) )
#define ToRoundRect( E )	 ( dynamic_cast<TCadRoundRect *>( E ) )
#define ToEllipse( E )		 ( dynamic_cast<TCadEllipse *>( E ) )
#define ToPuller( E )		 ( dynamic_cast<TCadPuller *>( E ) )
#define ToText( E )			 ( dynamic_cast<TCadText *>( E ) )
#define ToDepShape( E )		 ( dynamic_cast<TCadDepShape *>( E ) )

#define ToGroup( E )		 ( dynamic_cast<TCadGroup *>( E ) )
#define ToMap( E )			 ( dynamic_cast<TCadMap *>( E ) )

#define ToSurface( E )		 ( dynamic_cast<TCadSurface *>( E ) )
#define ToLoftedSurface( E ) ( dynamic_cast<TCadLoftedSurface *>( E ) )
#define ToTensorSurface( E ) ( dynamic_cast<TCadTensorSurface *>( E ) )
#define ToGordonSurface( E ) ( dynamic_cast<TCadGordonSurface *>( E ) )
#define ToDepSurface( E )	 ( dynamic_cast<TCadDepSurface *>( E ) )

#define ToMesh( E )			 ( dynamic_cast<TCadMesh *>( E ) )
#define ToDepMesh( E )		 ( dynamic_cast<TCadDepMesh *>( E ) )

#define ToTrimSurface( E )	 ( dynamic_cast<TCadTrimSurface *>( E ) )
#define ToTessPolygon( E )	 ( dynamic_cast<TCadTessPolygon *>( E ) )

#endif

