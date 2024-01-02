//------------------------------------------------------------------------------
#ifndef tsmlibH
#define tsmlibH
//------------------------------------------------------------------------------

#include "_gpoint3d.h"
#include "_defines.h"
#include "functions.h"
#include "IwTArray.h"
#include "iwgfx_extern.h"
#include "iwcurv_types.h"
#include "nurbs.h"
#include "IwMatrix.h"

#define ISINSIDE_NOTASSIGNED  0
#define ISINSIDE_IN			  1
#define ISINSIDE_OUT		  -1
#define ISINSIDE_HOLE		  -2
#define ISINSIDE_INBORDEROUT  -3
#define ISINSIDE_INBORDERHOLE -4

using std::vector;

//---------------------------------------------------------------------------

class TessCurveParameters
{
  public:
	TessCurveParameters( );

	bool EvaluatorBasedTessellation;	   // FALSE = IwCurve::TessellateByBisection() if that fails - tessellate by IwCurveCache spatial decomposition
										   // TRUE  = IwBSplineCurve::EquallySpacedPoints() default:[FALSE]
	int MinimumNumberOfSegments;		   // min number of segments in tess polygon,     0=ignore
	double ChordHeight;					   // max distance between geom and tess segment, 0=ignore
	double AngleToleranceDegrees;		   // max angle between tess tangents,            0=ignore
	double Maximum3DDistanceBetweenPoints; // max distance between tess pts,              0=ignore
	double MinimumParametricRatio;		   // Limits the smallness of the stepsize relative to the paramtric range (typically 0.00001).
};

//---------------------------------------------------------------------------

class TessSurfaceParameters
{
  public:
	TessSurfaceParameters( );

	bool EvaluatorBasedTessellation; //
	double ChordHeight;				 // max distance between geom and tess segment, 0=ignore
	double AngleToleranceDegrees;	 // max angle between tess tangents,            0=ignore
	double MaxEdgeLength3D;			 // Maximum length of polygon edge in 3D
	double MinEdgeLength3D;			 // Minimum length of a polygon edge in 3D
	double MinEdgeLengthRatioUV;	 // Maximum edge length of a polygon edge in UV space of the surface relative to the UV size.
	double MaxAspectRatio;			 // Maximum ratio of a rectangles sized during subdivision. Size of largest / size of smallest = aspect ratio.
};

//---------------------------------------------------------------------------

class TessSmoothingData
{
  public:
	TessSmoothingData( );

	int SmoothingPasses;	  // How many times to test each vertex for smoothing.
	double SmoothingStepSize; // 0.0 - no movement of vertices to improve 0.* - how far toward average point to move each pass. 1.0 - move to average of surrounding vertices
	double MinSmoothingRatio; // If the largest area to the smallest area of the UV polygon is less than this then no smoothing is required. 1.0 or less - smooth every vertex no matter what 2.0-4.0 - smooth lots of things 10.0 - smooth only areas with really small polygons
};

//---------------------------------------------------------------------------

class TessParameters
{
  public:
	TessParameters( );

	TessCurveParameters CurveParams;
	TessSurfaceParameters SurfParams;

	bool Smooth;
	TessSmoothingData SmoothParams;
};

//---------------------------------------------------------------------------
class MeshCallback : public IwPolygonOutputCallback
{
  public:
	MeshCallback( );

	IwStatus OutputMesh( IwTArray<ULONG> &rPolygonVertexCount, IwTArray<ULONG> &rPolygonVertexIndices, IwTArray<IwPoint3d> &rPolygon3DPoints, IwTArray<IwVector3d> &rSurfaceNormals, IwTArray<IwPoint2d> &rPolygonUVPoints, IwSurface *pSurface, IwFace *pFace );

	IwPolyBrep *PolyBrep;
	IwContext *pContext;
};

//---------------------------------------------------------------------------

class TOGLPolygon;
class TOGLPolygonList;
class TOGLPolygonListList;

class TSMLib
{
  public:
	TSMLib( );
	~TSMLib( );

	// Public methods Curves
	SISLCurve *ExtendCurve( SISLCurve *curve, double dDistance, int StartorEnd, IwContinuityType eExtensionContinuity );
	bool CutWithPlane( SISLCurve *curve, T3DPlane *plane, vector<SISLCurve *> *curvesOut );
	bool CutWithPlane( IwBSplineCurve *curve, T3DPlane *plane, IwTArray<IwCurve *> *curvesOut );
	SISLCurve *Trim( SISLCurve *curve, double param1, double param2 );
	SISLCurve *ChangeStartPoint( SISLCurve *curve, T3DPoint *p );
	bool GetNearestPoints( SISLCurve *curve1, SISLCurve *curve2, T3DPoint &p1, T3DPoint &p2, double tol = RES_GEOM, double *d = 0 );
	float DistanceCurvePoint( SISLCurve *curve, T3DPoint p, double tol = RES_GEOM );

	SISLCurve *JoinCurves( vector<SISLCurve *> *curves );
	bool MakeCurvesCompatible( vector<SISLCurve *> *curves, vector<SISLCurve *> *resultCurves );
	SISLCurve *CreateDegenerateCurve( T3DPoint pt, int dim = 3 );
	double PerimeterSegment( SISLCurve *curve, double param1, double param2 );
	bool GetTessParamsAndPoints( SISLCurve *curve, vector<double> *params, vector<T3DPoint> *points, ULONG minNumSegments = 0, double chordHeightTol = 0.0, double angleDegreesTol = 8.0, double max3DDistBetweenPoints = 0.0, double minParamRatio = 0.00001, bool evalBasedTessellation = false );
	bool GetTessParamsAndPoints( IwBSplineCurve *curve, vector<double> *params, vector<T3DPoint> *points, ULONG minNumSegments = 0, double chordHeightTol = 0.0, double angleDegreesTol = 8.0, double max3DDistBetweenPoints = 0.0, double minParamRatio = 0.00001, bool evalBasedTessellation = false );

	IwBSplineCurve *CreateCurve( SISLCurve *sl ); //( vector<T3DPoint> *points, ULONG degree = DEFAULT_DEGREE, int dim = DEFAULT_DIMENSION, int closedCurve = ENT_OPEN );
	IwBSplineCurve *InterpolateCurve( vector<T3DPoint> *points, ULONG degree = DEFAULT_DEGREE, IwInterpolationType interpType = IW_IT_CENTRIPETAL, int closedCurve = ENT_OPEN, bool cornerAtEnds = false );
	IwBSplineCurve *InterpolateCurve( vector<T3DPoint> *points, vector<bool> *corners, ULONG degree = DEFAULT_DEGREE, IwInterpolationType interpType = IW_IT_CENTRIPETAL, int closedCurve = ENT_OPEN );

	SISLCurve *AproximateCurve( vector<T3DPoint> *points, ULONG degree = DEFAULT_DEGREE, int closedCurve = ENT_OPEN );

	SISLCurve *RebuildCurve( SISLCurve *curve, double tol = RES_GEOM, bool filter = true );
	SISLCurve *RebuildCurve( SISLCurve *curve, int numPts, double tol = RES_GEOM );

	bool ProjectPoint( IwTree *tree, IwPoint3d point, IwPoint3d &pBest, IwPoint3d &nBest, double expansion = true, bool proNor = true, double nProNor = 1.0 );
	SISLCurve *ProjectCurve( IwTree *tree, SISLCurve *curve, TNPlane forcePlane, double stepOver = 1.0, vector<T3DPoint> *pointsOut = NULL, vector<T3DPoint> *normalsOut = NULL, double expansion = 0.5 );
	bool ProjectPointToPlane( IwTree *tree, TNPlane forcePlane, IwPoint3d point, IwPoint3d &pBest, IwPoint3d &nBest, double expansion );
	//		SISLCurve *ProjectCurveToPlane( IwTree *tree, SISLCurve *curve, TNPlane forcePlane, double stepOver = 1.0, vector<T3DPoint> *pointsOut = NULL, vector<T3DPoint> *normalsOut = NULL, double expansion = 0.5 );

	void GetCloudEnvelope2D( vector<IwPoint2d> *cloud, vector<IwPoint2d> &cloudEnvelope );
	void GetBrepOutbounds( IwPolyBrep *pPolyBrep, TOGLPolygonList *outbounds, vector<T3DRect> &domains );
	void GetBrepOutbounds( IwPolyBrep *pPolyBrep, IwTArray<IwTArray<IwPolyVertex *> > *outbounds, IwTArray<T3DRect> &domains );

	// Public methods Surfaces
	SISLSurf *ExtendSurface( SISLSurf *surf, IwSurfParamType eExtDirection, double dDist, IwContinuityType eExtensionContinuity );
	bool Intersect( SISLSurf *surf1, SISLSurf *surf2, vector<SISLCurve *> *curvesOut );
	bool Intersect( SISLSurf *surf1, T3DPlane *plane, vector<SISLCurve *> *curvesOut );
	SISLSurf *CreateGordonSurface( vector<SISLCurve *> *uSISLCurves, vector<SISLCurve *> *vSISLCurves, IwSurfParamType closedDir = IW_SP_V, double tol = 0.1, double completeknotsparamdist = -1.0 );
	IwBSplineSurface *CreateGordonSurface( IwTArray<IwBSplineCurve *> *uCurves, IwTArray<IwBSplineCurve *> *vCurves, IwSurfParamType closedDir = IW_SP_V, double tol = 0.1 );
	//		SISLSurf *CreateSweep1Surface( SISLCurve *railSISLCurve, vector<SISLCurve*> *sectionSISLCurves, vector<double> *params = 0, bool close = false, IwSurfParamType sweepDir = IW_SP_U, double tol = RES_GEOM, int sectionPos = SECPOS_NONE );
	//		SISLSurf *CreateLoftedSurface( vector<SISLCurve*> *SISLCurves, IwSurfParamType sectionsDir = IW_SP_U, IwSurfParamType closeDir = IW_SP_V, double tol = 0.0, bool makeCompatibleCurves = false );
	//		IwBSplineSurface *CreateLoftedSurface( IwTArray< IwBSplineCurve* > *iwCurves, IwSurfParamType sectionsDir = IW_SP_U, IwSurfParamType closeDir = IW_SP_V, double tol = 0.0, bool makeCompatibleCurves = false );
	//		vector<SISLSurf*> *SurfaceSurfaceFillet( SISLSurf *surf1, SISLSurf *surf2, vector<SISLCurve*> *&trimCurves, double radius1, double radius2, double tol, ULONG secType = 2, double secAccur = 0.1, IwBoundaryTrimmingType fillTrimType = IW_BT_MAXIMAL, ULONG baseTrimType = 0, bool mirror = false, bool complement = false );
	//		vector<SISLSurf*> *FilletTrimSurface( vector<SISLSurf*> *trimSurfaces, vector<TOGLPolygonList*> *trimPolygons, vector<TOGLPolygonList*> *&newTrimPolygons, vector< ULONG > *edgesToFillet, IwFilletSurfaceGeneratorType genType = IW_FSG_CIRCULAR );
	//		SISLSurf *JoinSurfaces( SISLSurf *surf1, SISLSurf *surf2, double tol = RES_GEOM );
	bool IntersectSrfCrv( SISLSurf *surf, SISLCurve *curve, TOGLPolygon *out, double dDistanceTolerance = 1.0e-5 );
	bool TessellateTrimSurface( TOGLTransf *OGLTransf, TCadTrimSurface *trimSurf, TessParameters *params, TOGLPolygonList *trianglesOut );

	void SplitFaceQuad( IwPolyFace *pFace, std::map<UnicodeString, IwPolyVertex *> *mapVertices, IwTArray<IwPolyFace *> *newFaces, double maxValueLength );
	bool TessellateTrimSurfaceTIN( TOGLTransf *OGLTransf, TCadSurface *surf, TCadSurface *periodicSurf, TOGLPolygonList *OGLBoundaries, TOGLPolygonList *trianglesOut );
	// bool GetSectionsByNormal( TOGLPolygonList *sections, SISLSurf *surf, TOGLPolygonList *out );

	// Public methods Polybreps
	int RemoveDegenerateFaces( IwPolyBrep *brep, double tol = RES_COMP );
	int RemoveDegenerateFacesSizeEdge( IwPolyBrep *brep, double minSize = 0.0001 );
	int JoinNearVertices( IwPolyBrep *brep, double tol = RES_COMP );
	bool JoinVertices( IwPolyBrep *brep, IwPolyVertex *v1, IwPolyVertex *v2 );
	bool Repair( IwPolyBrep *pPolyBrep, double jointol = RES_COMP );
	bool Repair( TOGLPolygonList *OGLList, TOGLPolygonList *OGLListOut, double jointol = RES_COMP, int type = SINGLE_POLYGON );
	bool Decimate( IwPolyBrep *pPolyBrep, bool repair = true, double dPercentOfReduction = 0.0, double dMaximumError = 0.0, bool bUseEdgeLengthAsError = false, double dMinFeatureAngle = 30.0, double dInteriorEdgeWeight = 1.0, double dBoundaryEdgeWeight = 1.0 );
	bool Decimate( TOGLPolygonList *OGLList, IwPolyBrep *&pPolyBrep, bool repair = true, double dPercentOfReduction = 0.0, double dMaximumError = 0.0, bool bUseEdgeLengthAsError = false, double dMinFeatureAngle = 30.0, double dInteriorEdgeWeight = 1.0, double dBoundaryEdgeWeight = 1.0, bool converttotriangles = true );
	bool Decimate( TOGLPolygonList *OGLList, TOGLPolygonList *OGLListOut, bool repair = true, double dPercentOfReduction = 0.0, double dMaximumError = 0.0, bool bUseEdgeLengthAsError = false, double dMinFeatureAngle = 30.0, double dInteriorEdgeWeight = 1.0, double dBoundaryEdgeWeight = 1.0, bool converttotriangles = true );
	bool DecimateSolid( TOGLPolygonList *OGLList, TOGLPolygonList *OGLListOut, double dPercentOfReduction = 0.0, double dMaximumError = 0.0, bool bUseEdgeLengthAsError = false, double dMinFeatureAngle = 30.0, double dInteriorEdgeWeight = 1.0, double dBoundaryEdgeWeight = 1.0 );
	IwPolyBrep *Tessellate( SISLSurf *surf, TessParameters *params );
	bool Tessellate( vector<SISLSurf *> *surfaces, vector<TOGLPolygonList *> *trimPolygons, TOGLPolygonList *OGLListOut, TessParameters *params );
	bool IntersectTriangles( TOGLPolygonList *OGLList1, TOGLPolygonList *OGLList2, TOGLPolygonList *OGLListOut, double d3DApproximationTolerance = 0.0001, double dAngleTolerance = 5.0 );
	bool IntersectTriangles( IwPolyBrep *brep1, IwPolyBrep *brep2, TOGLPolygonList *OGLListOut, double d3DApproximationTolerance = 0.0001, double dAngleTolerance = 5.0 );
	bool Difference( IwPolyBrep *pPolyBrep1, IwPolyBrep *pPolyBrep2, TOGLPolygonList *OGLListOut, double d3DApproximationTolerance, double dAngleTolerance );
	bool ModifyPolyBrepsAsSolid( TOGLTransf *OGLTransf, TOGLPolygonListList *oglLists, double tol, int type, TCadGroup *meshesOut );
	bool ModifyPolyBrepsAsSolid( IwTArray<IwPolyBrep *> *pBreps, int type, double tol = 0.1 );
	bool ModifyPolyBrepsAsSolidComponents( IwTArray<IwPolyBrep *> *pBreps, double minValue = 0.25, double maxValue = 0.75, bool closeHoles = true );
	bool SewBorders( IwTArray<IwPolyVertex *> *vertices, IwTArray<IwPolyEdge *> *edges, double distToSew = 0.1 );

	//------------------------------------------------------------------------------
	//	TSMLib - FUNCIONES DE PARA ESCRIBIR EN IGS ELEMENTOS DE LA LIBRERIA - DEBUG
	//------------------------------------------------------------------------------
	bool WritePolyEdgeSMLIB( UnicodeString file, IwPolyEdge *edge );
	bool WritePolyEdgesSMLIB( UnicodeString file, IwTArray<IwPolyEdge *> *polyEdges );
	bool WritePolyVertexSMLIB( UnicodeString file, IwPolyVertex *sVertex );
	bool WritePolyVerticesSMLIB( UnicodeString file, IwTArray<IwPolyVertex *> *sVertices );
	bool WritePolyFaceSMLIB( UnicodeString file, IwPolyFace *face );
	bool WritePolyFacesSMLIB( UnicodeString file, IwTArray<IwPolyFace *> *sFaces );
	bool WritePointSMLIB( UnicodeString file, const IwPoint3d &point );
	bool WritePointsSMLIB( UnicodeString file, IwTArray<IwPoint3d> *points );
	bool WriteCurveSMLIB( UnicodeString file, IwBSplineCurve *curve );
	bool WriteCurvesSMLIB( UnicodeString file, IwTArray<IwBSplineCurve *> *curves );
	bool WriteSurfaceSMLIB( UnicodeString file, IwBSplineSurface *surf );
	bool WriteSurfacesSMLIB( UnicodeString file, IwTArray<IwBSplineSurface *> *surfs );
	bool WriteBrep( UnicodeString file, IwBrep *brep );
	bool WriteBreps( UnicodeString file, IwTArray<IwBrep *> *breps );
	bool WritePolyBrep( UnicodeString file, IwPolyBrep *pBrep );

	IwPolyBrep *ConvertToIwPolyBrep( TOGLPolygonList *OGLList, vector<int3> *PBrepPolListRelF = NULL, bool activeRel = false, int auxType = -1, TOGLPolygonList *auxOGLList = 0, bool brepFaceTriangulation = true, int CompareMask = CMASK_V | CMASK_N | CMASK_T, bool checkPBrep = true, double repairTol = RES_COMP, double vertexTol = RES_COMP, bool trianglesForced = true, bool ispolygonalorsubdmesh = false, IwPolyVertex ***verticesOriginalPos = 0 );
	void ConvertToOGLPolygonList( IwPolyBrep *pPolyBrep, TOGLPolygonList *OGLListOut, int type = SINGLE_POLYGON, int auxType = -1, TOGLPolygonList *auxOGLListOut = 0, bool brepFaceTriangulation = true, IwTArray<IwPolyFace *> *groupFaces = 0 );
	void RemoveDuplicatedFaces( IwPolyBrep *pBrep );
	void RemoveDegenerateFacesAndTriangulate( IwPolyBrep *pBrep, double tolerance = RES_COMP );
	void FillDegenerateHoles( IwPolyBrep *pBrep, double tolerance = RES_COMP );
	void RemoveDegenerateBorderFaces( IwPolyBrep *pBrep, double minArea );
	void TriangulateSmallBorderFaces( IwPolyBrep *pBrep );
	void RemoveBoundaryFacesWithDifferentNormal( IwPolyBrep *brep, double maxAngleRad );
	void RemoveFacesMinusAspectRatio( IwPolyBrep *brep, double maxAspectRatio );
	void ReTriangulateFacesWithMinimalAspectRatio( IwPolyBrep *brep, double maxAspectRatio );
	void DestroyIwPolyBrep( IwPolyBrep *pPolyBrep );
	void DestroyIwPolyFace( IwPolyBrep *pPolyBrep, IwPolyFace *pPolyFace );

	IwContext &GetContext( )
	{
		return *pContext;
	}

  protected:
	// Variables
	IwContext *pContext;
	NL_STACKS *NS;

  public:
	// Protected methods Curves
	bool ExtendCurve( IwBSplineCurve *curve, double dDistance, int StartorEnd, IwContinuityType eExtensionContinuity );
	bool ChangeStartPoint( IwBSplineCurve *curve, IwPoint3d *p );
	bool ChangeStartPoint( IwBSplineCurve *curve, double param );
	bool SetStartPointFromCurve( IwBSplineCurve *curveToChange, IwBSplineCurve *curve, double param );
	bool RebuildCurve( IwBSplineCurve *curve, double tol = RES_GEOM, bool filter = true );
	bool RebuildCurve( IwBSplineCurve *curve, int numPts, double tol = RES_GEOM );
	bool RemoveDuplicateCompatibleCurves( IwTArray<IwBSplineCurve *> &curves );
	bool OrderCurvesAroundCurve( IwTArray<IwBSplineCurve *> &curves, IwBSplineCurve *mainCurve, double tol = RES_GEOM );
	bool CheckOrderedCurves( IwTArray<IwBSplineCurve *> &curves, IwBSplineCurve *mainCurve, double tol = RES_GEOM );
	bool AdjustIntersections( IwTArray<IwBSplineCurve *> &uCurves, IwTArray<IwBSplineCurve *> &vCurves, double tol = RES_GEOM );
	bool GetNearestPoints( IwBSplineCurve *curve1, IwBSplineCurve *curve2, T3DPoint &p1, T3DPoint &p2, double tol = RES_GEOM, double *d = 0 );
	float DistanceCurvePoint( IwBSplineCurve *curve, T3DPoint p, double tol = RES_GEOM );
	IwBSplineCurve *JoinCurves( IwTArray<IwBSplineCurve *> *curves );
	bool NormNLCurveInSurface( IwExtent2d *beginDomain, IwExtent2d *endDomain, IwBSplineCurve *curve );
	bool RotateCurve( IwBSplineCurve *curve, const IwVector3d &vecOrig, const IwVector3d &vecDest, const IwPoint3d &ptRot );
	bool RotateAndTranslateCurve( IwBSplineCurve *curve, const IwPoint3d &ptOrig, const IwVector3d &vecOrig, const IwPoint3d &ptDest, const IwVector3d &vecDest, IwVector3d *vecRotAux = 0 );
	bool GetCurvePointAndNormal( IwBSplineCurve *curve, IwPoint3d &point, IwVector3d &normal, int position = SECPOS_NONE );
	bool GetPointAndNormalFromParam( IwBSplineCurve *curve, IwPoint3d &point, IwVector3d &normal, const double &param );
	bool PrepareCurvesForSweep1( IwBSplineCurve *rail, IwTArray<IwBSplineCurve *> *curves, vector<double> *params, bool close, int position = SECPOS_NONE );
	bool SetDirectionAlongRail( IwBSplineCurve *rail, IwTArray<IwBSplineCurve *> *curves );
	bool MakeCompatibleDirection( IwBSplineCurve *crv1, IwBSplineCurve *crv2 );
	bool MorphCurves( IwBSplineCurve *crv1, const double &pct1, IwBSplineCurve *crv2, const double &pct2, IwBSplineCurve *&crvMorph );
	bool MorphCurvesAlongRail( IwBSplineCurve *rail, IwBSplineCurve *crv1, IwBSplineCurve *crv2, const double &param, IwBSplineCurve *&crvMorph, int position = SECPOS_NONE );
	bool CreateSecuenceMorphingCurves( IwBSplineCurve *rail, IwBSplineCurve *crv1, IwBSplineCurve *crv2, IwTArray<IwBSplineCurve *> *morphedCurves, bool addLast, double tol = RES_GEOM, int sectionPos = SECPOS_NONE );
	bool GetTessParamsAndPoints( IwBSplineCurve *curve, IwTArray<double> *params, IwTArray<IwPoint3d> *points, double tol = RES_GEOM );

	IwBSplineCurve *InterpolateCurve( IwTArray<IwPoint3d> *iwPoints, ULONG degree = DEFAULT_DEGREE, IwInterpolationType interpType = IW_IT_CENTRIPETAL, int closedCurve = ENT_OPEN, bool cornerAtEnds = false );
	IwBSplineCurve *InterpolateCurve( IwTArray<IwPoint3d> *iwPoints, IwTArray<bool> *corners, ULONG degree = DEFAULT_DEGREE, IwInterpolationType interpType = IW_IT_CENTRIPETAL, int closedCurve = ENT_OPEN );

	IwBSplineCurve *AproximateCurve( IwTArray<IwPoint3d> *iwPoints, ULONG degree = DEFAULT_DEGREE, bool closedCurve = ENT_OPEN );

	double GetNeighbours( IwTree *tree, IwExtent3d domain, int numNeighbours, double expand, IwTA<IwObject *> &neighbours );
	void ComputeNormalFromPoints( vector<T3DPoint> *points, T3DPoint &normal );

	// Protected methods Surfaces
	bool ExtendSurface( IwBSplineSurface *surf, IwSurfParamType eExtDirection, double dDist, IwContinuityType eExtensionContinuity );
	bool Intersect( IwSurface *surf1, IwSurface *surf2, IwTArray<IwCurve *> *curvesOut );
	bool Intersect( IwBSplineSurface *iwSurf, T3DPlane *plane, IwTArray<IwCurve *> *curvesOut );
	bool IntersectSrfCrv( IwSurface *iwSurf, IwCurve *iwCurve, TOGLPolygon *out, double dDistanceTolerance = 1.0e-5 );
	//		bool GetSectionsByNormal( TOGLPolygonList *sections, IwSurface *surf, TOGLPolygonList *out );

	// Protected methods Polybreps
	IwPolyBrep *Tessellate( IwBrep *brep, TessParameters *params );

	// Protected methods
	NL_CURVE *CreateNL_CURVE( SISLCurve *sl );
	NL_CURVE *ConvertToNL_CURVE( SISLCurve *sl );
	SISLCurve *ConvertToSISLCurve( int iDim, int iKind, NL_CURVE *nl );
	NL_SURFACE *ConvertToNL_SURFACE( SISLSurf *sl );
	SISLSurf *ConvertToSISLSurf( int iDim, int iKind, NL_SURFACE *nl );
	IwBrep *ConvertToBrep( vector<SISLSurf *> *surfaces, vector<TOGLPolygonList *> *trimPolygons );
	IwBrep *ConvertTrimSurfaceToBrep( TOGLTransf *OGLTransf, TCadTrimSurface *trimSurf );
	//		vector<SISLSurf*> * ConvertToSISLTrimSurfs( IwBrep *bRep, vector<TOGLPolygonList*> *&trimPolygons );

	bool SetCurve( IwBSplineCurve *orgCurve, IwBSplineCurve *newCurve );
	bool SetSurface( IwBSplineSurface *orgSurf, IwBSplineSurface *newSurf );
	bool NormalizeNLCurve( NL_CURVE *nlCurve );
	bool VerifyAndConvertToSameDimension( IwTArray<IwBSplineCurve *> *curves );

	void IsInsidePolygon( TOGLPolygon *pointsBorder, int numSU, int numSV, IwPoint3d **matrixPts, bool inside, int **valid, bool *changeValid = 0 );
	IwPolyBrep *CreatePBrepQuads( IwExtent2d boundsUV, TOGLPolygonList *borders, double maxDist, int numSubdivisionsU, int numSubdivisionsV, bool invertPolygons );
	IwStatus IntersectSegment( const IwPoint3d &p1Start, const IwPoint3d &p1End, const IwPoint3d &p2Start, const IwPoint3d &p2End, double dTolerance, ULONG &rlNumIntersections, double aParametersThis[ 2 ], double aParametersOther[ 2 ] );
	bool CreateTriangles( IwTArray<IwPolyVertex *> *vertices1, IwTArray<IwPolyVertex *> *vertices2, IwPolyBrep *pBrep );
	IwPolyBrep *Tessellate2D( TOGLPolygonList *OGLBoundaries, double prec );
	IwPolyBrep *Tessellate2DDelaunay( TOGLPolygonList *OGLBoundaries, double prec, bool deleteRepPts = true, bool canAddBoundaryPts = false );
};

#endif

