//---------------------------------------------------------------------------

#ifndef pbrepfromcurvesH
#define pbrepfromcurvesH

//---------------------------------------------------------------------------

#include "_entities.h"

#define MIN_DISTANCE_SUBDIV_BIG	   5.0
#define MAX_DISTANCE_SUBDIV_BIG	   30.0
#define DEF_DISTANCE_SUBDIV_BIG	   10.0

#define MIN_DISTANCE_SUBDIV_MEDIUM 5.0
#define MAX_DISTANCE_SUBDIV_MEDIUM 20.0
#define DEF_DISTANCE_SUBDIV_MEDIUM 20.0

#define MIN_DISTANCE_SUBDIV_SMALL  5.0
#define MAX_DISTANCE_SUBDIV_SMALL  10.0
#define DEF_DISTANCE_SUBDIV_SMALL  10.0

#define MIN_QUANTITY_SUBDIV_BIG	   10
#define MAX_QUANTITY_SUBDIV_BIG	   30
#define DEF_QUANTITY_SUBDIV_BIG	   20

#define MIN_QUANTITY_SUBDIV_MEDIUM 5
#define MAX_QUANTITY_SUBDIV_MEDIUM 10
#define DEF_QUANTITY_SUBDIV_MEDIUM 5

#define MIN_QUANTITY_SUBDIV_SMALL  3
#define MAX_QUANTITY_SUBDIV_SMALL  10
#define DEF_QUANTITY_SUBDIV_SMALL  5

#define DEF_CLOSE_ENDING_SUBDIV	   Quads
#define DEF_METHOD_SUBDIV		   Planes
#define DEF_SEC_TYPE_SUBDIV		   Distance

#define DEF_CREATE_SUBDIVISION	   1

#define DEF_CLOSE_ENDING_SUBDIV	   Quads
#define DEF_METHOD_SUBDIV		   Planes
#define DEF_SEC_TYPE_SUBDIV		   Distance

#define MIN_HEELTOEANGLE_SUBDIV	   5.0
#define MAX_HEELTOEANGLE_SUBDIV	   45.0
#define DEF_HEELTOEANGLE_SUBDIV	   20.0
#define MIN_HEELPERCENT_SUBDIV	   10.0
#define MAX_HEELPERCENT_SUBDIV	   30.0
#define DEF_HEELPERCENT_SUBDIV	   15.0
#define MIN_TOEPERCENT_SUBDIV	   10.0
#define MAX_TOEPERCENT_SUBDIV	   30.0
#define DEF_TOEPERCENT_SUBDIV	   20.0

#define PERCENT_ONE_SKELETON	   0.75
#define PERCENT_HEEL_TOE_POINTS	   0.20

class IwPolyBrep;
class IwPolyRegion;
class IwPolyShell;

enum TPBrepType { Insole = 0, Insole_R = 1, Heel_4S = 2, Heel_3S = 3, TopPiece_4S = 4, TopPiece_3S = 5, Platform_Std = 6, Platform_Ind = 7, Sole = 8 };

enum MeshFromCurvesMethodType { Nearest = 0, Normals = 1, Planes = 2 };
enum MeshFromCurvesDivisionType { Quantity = 0, Distance = 1 };
enum MeshFromCurvesCloseExtremesType { Triangles = 0, Quads = 1 };
enum MeshFromCurvesCurveType { Section = 0, Profile = 1, Skeleton = 2 };

//------------------------------------------------------------------------------
// TMeshFromCurvesParams
//------------------------------------------------------------------------------

class TMeshFromCurvesParams
{
  public:
	TMeshFromCurvesParams( );
	~TMeshFromCurvesParams( );

	virtual void InitValues( TPBrepType type );
	virtual void Set( TMeshFromCurvesParams *params );
	virtual bool IsValid( TPBrepType type );

  public:
	MeshFromCurvesMethodType CreationMethodType; // 0 MasCercano, 1 Normales, 2 Planos

	MeshFromCurvesDivisionType SectionsDivisionType; // 0 Cantidad, 1 Distancia
	double SectionsDivisionValue;

	MeshFromCurvesDivisionType CentralFacesDivisionType; // 0 Cantidad, 1 Distancia
	double CentralFacesDivisionValue;
	double HeelToeAngle;
	double HeelPercent;
	double ToePercent;

	MeshFromCurvesCloseExtremesType CloseExtremesType; // 0 Triangulos, 1 Quads

	bool CreateSubdivision;
};

//------------------------------------------------------------------------------
// TPBrepFromCurvesData
//------------------------------------------------------------------------------

class TPBrepFromCurvesData
{
  public:
	TPBrepFromCurvesData( );
	~TPBrepFromCurvesData( );

	void InitValues( );
	bool IsValidData( );
	void PrepareCurves( TOGLTransf *OGLTransf );
	void PrepareCurve( TOGLTransf *OGLTransf, TCadEntity *crv, TOGLPolygon *polCrv, MeshFromCurvesCurveType type );
	TOGLPolygon *GetPolCurveByIndex( int indexCrv );
	TOGLPolygon *GetPolSkeletonByIndex( int indexCrv );
	TOGLPolygon *GetPolProfileByIndex( int indexCrv );

	void SetApplyCreases( bool apply )
	{
		ApplyCreases = apply;
	}
	bool GetApplyCreases( )
	{
		return ApplyCreases;
	}
	void SetHasBorderCurve( bool value )
	{
		HasBorderCurve = value;
	}
	bool GetHasBorderCurve( )
	{
		return HasBorderCurve;
	}
	void SetPBrepType( TPBrepType type )
	{
		PBrepType = type;
	}
	TPBrepType GetPBrepType( )
	{
		return PBrepType;
	}
	bool ExistHeel( );
	bool ExistToe( );
	void SetFirstCurve( TCadEntity *ent )
	{
		FirstCurve = ent;
	}
	TCadEntity *GetFirstCurve( )
	{
		return FirstCurve;
	}
	TOGLPolygon *GetPolFirstCurve( )
	{
		return &PolFirstCurve;
	}
	void SetFirstSkeleton( TCadEntity *ent )
	{
		FirstSkeleton = ent;
	}
	TOGLPolygon *GetPolFirstSkeleton( )
	{
		return &PolFirstSkeleton;
	}
	void SetFirstProfile( TCadEntity *ent )
	{
		FirstProfile = ent;
	}
	TOGLPolygon *GetPolFirstProfile( )
	{
		return &PolFirstProfile;
	}
	void SetLastCurve( TCadEntity *ent )
	{
		LastCurve = ent;
	}
	TCadEntity *GetLastCurve( )
	{
		return LastCurve;
	}
	TOGLPolygon *GetPolLastCurve( )
	{
		return &PolLastCurve;
	}
	void SetLastSkeleton( TCadEntity *ent )
	{
		LastSkeleton = ent;
	}
	TOGLPolygon *GetPolLastSkeleton( )
	{
		return &PolLastSkeleton;
	}
	void SetLastProfile( TCadEntity *ent )
	{
		LastProfile = ent;
	}
	TOGLPolygon *GetPolLastProfile( )
	{
		return &PolLastProfile;
	}
	void AddMidCurve( TCadEntity *ent )
	{
		MidCurves.Add( ent );
	}
	int GetMidCurvesCount( )
	{
		return MidCurves.Count( );
	}
	TOGLPolygon *GetPolMidCurve( int pos )
	{
		return ( pos >= 0 && pos < PolMidCurves.Count( ) ) ? PolMidCurves.GetItem( pos ) : 0;
	}
	void AddMidProfile( TCadEntity *ent )
	{
		MidProfiles.Add( ent );
	}
	int GetMidProfilesCount( )
	{
		return MidProfiles.Count( );
	}
	TOGLPolygon *GetPolMidProfile( int pos )
	{
		return ( pos >= 0 && pos < PolMidProfiles.Count( ) ) ? PolMidProfiles.GetItem( pos ) : 0;
	}
	void SetCutPointsFristCurve( TOGLPoint ptUp, TOGLPoint ptDown );
	TOGLPoint *GetCutPtUpFirstCrv( )
	{
		return &CutPtUpFirstCrv;
	}
	TOGLPoint *GetCutPtDownFirstCrv( )
	{
		return &CutPtDownFirstCrv;
	}

	int GetNumCurves( )
	{
		return NumCurves;
	}
	TOGLPoint *GetFirstPtSklFirstCrv( )
	{
		return &FirstPtSklFirstCrv;
	}
	TOGLPoint *GetLastPtSklFirstCrv( )
	{
		return &LastPtSklFirstCrv;
	}
	TOGLPoint *GetFirstPtSklLastCrv( )
	{
		return &FirstPtSklLastCrv;
	}
	TOGLPoint *GetLastPtSklLastCrv( )
	{
		return &LastPtSklLastCrv;
	}

  private:
	void PrepareSkeletonPoints( TOGLTransf *OGLTransf, TOGLPolygon *polCrv, TOGLPolygon *pokSkl, TOGLPolygon *polProf, TOGLPoint &firstPt, TOGLPoint &lastPt );

  private:
	bool ApplyCreases, HasBorderCurve, IsProfileOnRight;
	int NumCurves;
	TOGLPoint FirstPtSklFirstCrv, LastPtSklFirstCrv, FirstPtSklLastCrv, LastPtSklLastCrv;
	TOGLPoint CutPtUpFirstCrv, CutPtDownFirstCrv; // Puntos de corte de las zonas frontal y dorsal de la primera curva. Usados en plataformas independientes de suela.
	TPBrepType PBrepType;
	TCadEntity *FirstCurve, *FirstSkeleton, *FirstProfile, *LastCurve, *LastSkeleton, *LastProfile;
	TOGLPolygon PolFirstCurve, PolFirstSkeleton, PolFirstProfile, PolLastCurve, PolLastSkeleton, PolLastProfile;
	TCadGroup MidCurves, MidProfiles;
	TOGLPolygonList PolMidCurves, PolMidProfiles;
};

//------------------------------------------------------------------------------
// TPBrepFromCurves
//------------------------------------------------------------------------------

class TPBrepFromCurves
{
  public:
	TPBrepFromCurves( TOGLTransf *_OGLTransf, TPBrepFromCurvesData *_curveData, TMeshFromCurvesParams *_curveParams );
	~TPBrepFromCurves( );

	void InitValues( );
	void Clear( );

	IwPolyBrep *CreatePBrepFromCurves( );

  protected:
	bool GetPointsFromCurve( int indexCrv, TOGLPolygon *polEquiUp, TOGLPolygon *polEquiDown, TOGLPolygon *polEquiSkeleton );
	bool GetPlanesMethodValues( int indexCrv, TOGLPoint &ptMinX, TOGLPoint &ptMaxX, TOGLPoint &ptHeel, TOGLPoint &ptToe, double &sectionsWidth );
	bool GetSkeletonPointsOnCurve( bool heelPoint, TOGLPolygon *polCrv, TOGLPoint ptUp, TOGLPoint ptDown, TOGLPoint ptMid, TOGLPoint *ptUp_1, TOGLPoint *ptUp_2, TOGLPoint *ptDown_1, TOGLPoint *ptDown_2 );
	bool GetSkeletonPointsOnProfile( int indexCrv, TOGLPoint ptSkl, TOGLPoint &ptSklUp, TOGLPoint &ptSklDown );
	bool GetSkeletonPointsAux( TOGLPoint ptUp, TOGLPoint ptSkl, TOGLPoint ptDown, TOGLPoint &ptSklUp, TOGLPoint &ptSklDown );
	bool GetPointsUsingPlanes( int indexCrv, TOGLPolygon *polEquiUp, TOGLPolygon *polEquDown, TOGLPolygon *polEquiSkeleton, TOGLPoint &ptHeel, TOGLPoint &ptToe );
	bool GetExtremesOfCurve( int indexCrv, TOGLPoint *ptMinX, TOGLPoint *ptMaxX );
	bool GetPolUpPolDown( int indexCrv, TOGLPoint *ptHeel, TOGLPoint *ptToe, TOGLPolygon *polUp, TOGLPolygon *polDown );
	bool GetSkeleton( int indexCrv, TOGLPolygon *polUp, TOGLPolygon *polDown, TOGLPolygon *polSkeleton );
	bool GetEquiSkeleton( TOGLPolygon *polUp, TOGLPolygon *polDown, TOGLPolygon *polSkeleton, TOGLPolygon *polEquiUp, TOGLPolygon *polEquDown, TOGLPolygon *polEquiSkeleton );
	void OrderPointsFromCurveParameters( TOGLPolygon *pol, TOGLPolygon *polEqui );
	bool CreatePBrepFromPoints( TOGLPolygon *polUp, TOGLPolygon *polDown, TOGLPolygon *polSkeleton, bool bAddAtStart, IwVector3d *normalCurve, IwVector3d *centroidCurve );
	bool AddCurveToPBrep( int indexCrv, bool bAtStart );
	bool GetNEquidistantPoints( TOGLPolygon *polCrv1, int indexCrv2, int iNPoligons, IwTA<T3DPoint> *lp3dCrv1, IwTA<T3DPoint> *lp3dCrv2 );
	bool GetPointsFromCurveUsingPlanes( int indexCrv, IwTA<T3DPoint> *lpt3dOrig, IwTA<T3DPoint> *lpt3dForCurve, TOGLPoint &ptHeel, TOGLPoint &ptToe );
	bool CreatePBrepFromPoints( int indexCrv, IwTA<IwPolyVertex *> *liIndexesCrv, IwTA<T3DPoint> *lp3dCrv2, bool bIsClosed, bool bAtStart );
	bool ClosePBrep( bool bAtStart, IwVector3d *normalCurve, IwVector3d *centroidCurve );
	bool ClosePBrepFromPoints( IwTA<IwPolyVertex *> *liUp, IwTA<IwPolyVertex *> *liDown, TOGLPolygon *polEquiSkeleton, bool bAtStart, IwVector3d *normalCurve, IwVector3d *centroidCurve );
	void InvertNormalFaces( );
	void MarkCreaseNewFace( IwPolyFace *iwFace, IwPolyVertex *iwVertex1, IwPolyVertex *iwVertex2, float value = 1.0 );

  protected:
	TOGLTransf *OGLTransf;
	TPBrepFromCurvesData *CurveData;
	TMeshFromCurvesParams *CurveParams;

	IwPolyBrep *PBrep;
	IwPolyRegion *PRegion;
	IwPolyShell *PShell;
	TOGLPolygon *PolCrvAtStart, *PolCrvAtEnd;
	IwTA<IwPolyVertex *> LiIndexesAtStart, LiIndexesAtEnd;
	TOGLPoint PtHeelAtStart, PtToeAtStart, PtHeelAtEnd, PtToeAtEnd;

	bool OneSkeleton;
	int NumSecsHeel, NumSecsCentral, NumSecsToe;
};

#endif

