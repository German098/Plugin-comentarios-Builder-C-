//---------------------------------------------------------------------------

#ifndef pbrepdataH
#define pbrepdataH

#include <values.h>
#include <vector>

#include <IniFiles.hpp>
#include "IwTArray.h"

#include "_layers.h"
#include "functions.h"
#include "pbrepfromcurves.h"
//#include "cxProgressBar.hpp"

// Tipos de subdivisión
#define ST_NONE			   -1
#define ST_CUBE			   0
#define ST_SPHERE		   1
#define ST_CYLINDER		   2
#define ST_PLANE		   3
#define ST_PIPE			   4
#define ST_REVOLVE		   5
#define ST_CONTOUR		   6
#define ST_ONE_RAIL_SWEEP  7
#define ST_TWO_RAILS_SWEEP 8

// Area de cara
#define MIN_AREA_MESH_FACE 6.00

class TCadEntity;
class TSubdivision;
class TSubdivisionData;
class IwPolyBrep;
class IwPolyEdge;
class IwPolyRegion;
class IwPolyShell;
class TMeshPrimitiveParams;

//------------------------------------------------------------------------------
// CREACION MALLAS LOW_POLY A PARITR DE CURVAS Y PRIMITIVAS
// CONTROL DE HERRAMIENTAS
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// GENERAL
//------------------------------------------------------------------------------
enum class ElementType { Vertex, Edge, Face, Undefined };
enum class SelectedElementType { All = -1, NoSelected = 0, UserSelection = 1, LoopSelection = 2, LastBeforeUserSelection = 3, LastUserSelection = 4, AllSelected = 5, Seam = 6, Crease = 7 }; // el Seam o crease no entra dentro de la seleccion
enum class TExtrudeType { NormalFace, Direction, GroupFacesByNormal, GroupFacesByVertexNormal, Solidify };
enum class TExtrudeEdgeType { ByEdges, ByEdges_UnifiedDir, ByNormalVertex, ByAxis, ByDirection };
enum class TCollapseVertexsType { AtCenter, AtFirst, AtLast, ByDistance };
enum class TProportionalEditingType { Smooth, Sphere, Root, InverseSquare, Sharp, Linear, Constant, Random };

// Estructura que se pasará a las operaciones sobre elementos de la malla,
// para que se puedan devolver los elementos creados.
struct TAddedElements {
	IwTA<IwPolyVertex *> iwVertexs;
	IwTA<IwPolyEdge *> iwEdges;
	IwTA<IwPolyEdge *> iwNewEdges;
	IwTA<IwPolyFace *> iwFaces;
};

void InitAddedElements( TAddedElements *addedElements );
void IncludeToAddedElements( TAddedElements *ae, TAddedElements *aeToInclude );
IwTA<IwPolyEdge *> GetEdgesWithSameIndex( TAddedElements *addedElements, ULONG iIndex2 );
IwTA<IwPolyFace *> GetFacesWithSameIndex( TAddedElements *addedElements, ULONG iIndex2 );

//------------------------------------------------------------------------------
// ANILLOS
//------------------------------------------------------------------------------
#define UL_MAX_EDGES_FOR_RING 500

enum OneRingCalcMode {
	NearestToPointList = 0, // Pensado para buscar el anillo de aristas mas cercano a una serie de puntos resultado de intersecciones de una curva cerrada sobre la malla
	GreatestLength = 1,		// Camino mas cercano -> la cara mas grande de todas las que comparte el vertice.
	ShortestLength = 2,		// Camino mas cercano -> la cara mas pequeña de todas las que comparte el vertice.
	OneRingWithLevel = 3,	// Anillo alrededor de la arista con un nivel de lejania.
	LyingInPlane = 4,		// Anillo más cercano a un plano dado
	ContinuityFaces = 5,	// Anillo cuya continuidad la proporciona la adyacencia de las caras.
	ContinuityAtEdge = 6,	// Anillo cuya continuidad acumulada, entre aristas, sea la menor. De momento inviable por su complejidad
	LyingInPlaneRhino = 7	// Anillo cuya continuidad la proporciona la adyacencia de las caras, proveida por Rhino.
};

enum class OneRingFacesType { FacesHV = 0, FacesByEdge = 1, Undefined = 2 };

enum OneRingFacesSearchMethod { OppositeEdge, ClosestLength, ByEdges };

struct TOneRingParams {
	ElementType Type;
	OneRingCalcMode CalcMode;
	OneRingFacesType FacesType; // 0: Primer anillo de caras; 1: Segundo anillo de caras; 2: Ambos anillos de caras
	int Level;					// Nivel de profundidad de los anillos concentricos. De 1 en adelante.
	ULONG IndexEdge;			// Indice de la arista para anillos de caras del tipo FacesByEdge
};

enum PlaneFitResult { Failure = -1, Success = 0, Inconclusive = 1 };

struct TDataIntIntForVertexPaths {
	int iElementIndex;
	int iNumBranches;

	bool operator==( const TDataIntIntForVertexPaths &other ) const
	{
		return other.iElementIndex == iElementIndex;
	}
	bool operator!=( const TDataIntIntForVertexPaths &other ) const
	{
		return other.iElementIndex != iElementIndex;
	}
};

struct TDataVertexInfo {
	TDataVertexInfo( )
	{
		ind = -1;
		indFather = -1;
		indEdge = -1;
		nEdges = -1;
		weight = MAX_RES_1_PARAM; // Se inicializa con un valor muy alto.
	}
	int ind;
	int indFather;
	int indEdge;
	int nEdges;
	double weight;
};

// La tupla de cada cara indica: índice de la cara, índice de la arista que comparte con la anterior cara,
// índice de la arista que comparte con la cara siguiente, índice del numero de caminos posibles a partir de esta cara
struct TStructFaces {
	ULONG ulIndexOfFace;
	IwPolyEdge *iwPolyEdgeSharedWithPreviousFace;
	IwPolyEdge *iwPolyEdgeSharedWithNextFace;
	int iNumOfPossiblePaths;
};

enum DefinesForErrors { NON_ERROR = 0, ERROR_GENERIC = 1, ERROR_NO_RINGS_FOUNDED = 2, ERROR_SOMELISTS_ARE_VOID = 3, ERROR_SEAM_EDGE_INCLUDED = 4, ERROR_SEAM_DISCONTINUOUS = 5, ERROR_SEAM_IS_NOT_SIMPLE = 6, ERROR_SEAM_INTERSECT_WITH_OTHER = 7, ERROR_SEAM_VOID = 8, ERROR_SEAM_ANY_INCLUDED = 9 };

// ERROR_SEAM_EDGE_INCLUDED: Que no coincida ninguna arista con otra de otro camino
// ERROR_SEAM_DISCONTINUOUS: No son adyacentes una arista con la siguiente
// ERROR_SEAM_IS_NOT_SIMPLE: No es un camino simple o Interseca consigo mismo (algun vertice está mas de 2 veces)
// ERROR_SEAM_INTERSECT_WITH_OTHER: La costura interseca con otra (Si la intersección es el extremo de una costura abierta, entonces si que es valido)
// ERROR_SEAM_VOID: Camino de aristas vacio
// ERROR_SEAM_ANY_INCLUDED: No se ha podido incluir ningun camino

// ------------------------------------------------------------------------------
// KNIFE
// ------------------------------------------------------------------------------
struct TMeshElementInfo {
	TMeshElementInfo( )
	{
		IndexVertex = ULONG_MAX;
	}
	ElementType Type;
	IwPoint3d Point;
	double ParamFromCrv;
	ULONG Index;
	ULONG IndexVertex;
};

// ------------------------------------------------------------------------------
// INFO TO RESTORE
// ------------------------------------------------------------------------------
struct TInfoToRestoreData {
	TInfoToRestoreData( )
	{
		edgetorestore = 0;
		face = 0;
		edge = 0;
		point = 0;
		FaceOrEdgeLayout = 0;
	}

	~TInfoToRestoreData( )
	{
		Clear( );
	}

	void Clear( )
	{
		delete FaceOrEdgeLayout;
		FaceOrEdgeLayout = 0;
	}

	IwPolyEdge *edgetorestore;	   // Arista donde vamos a restaurar la informacion
	IwPolyFace *face;			   // Cara origen a partir de la cual se va a calcular la uv para la arista destino
	IwPolyEdge *edge;			   // Arista origen a partir de la cual se va a calcular la uv para la arista destino
	IwPolyVertex *point;		   // Punto para calcular el valor de uv
	TOGLPolygon *FaceOrEdgeLayout; // En ocasiones es necesario guardar la ogl ya que la cara se borra
};

// ------------------------------------------------------------------------------
// Información para almacenar desplazamientos de vértices en distintas direcciones
// ------------------------------------------------------------------------------
class TranslateVertexInfo
{
  public:
	TranslateVertexInfo( )
	{
		Clear( );
	}
	~TranslateVertexInfo( )
	{
		Clear( );
	}

	void Clear( )
	{
		VerticesOrg.RemoveAll( );
		Vertices.RemoveAll( );

		for ( int i = 0; i < (int) infotorestoredata.GetSize( ); i++ )
			delete infotorestoredata[ i ];
		infotorestoredata.RemoveAll( );
		for ( int i = 0; i < (int) FaceOrEdgeLayout.GetSize( ); i++ )
			delete FaceOrEdgeLayout[ i ];
		FaceOrEdgeLayout.RemoveAll( );
		Directions.clear( );
	}
	void Normalize( );

	IwTA<TInfoToRestoreData *> infotorestoredata;

	// Vertices y Directions deben tener siempre el mismo tamaño
	IwTA<IwPolyVertex *> VerticesOrg;
	IwTA<IwPolyVertex *> Vertices;
	IwTA<TOGLPolygon *> FaceOrEdgeLayout;
	vector<IwPoint3d> Directions;
};

// -----------------------------------------------------------------------------
// Cálculo de la subdivisión inversa
// -----------------------------------------------------------------------------
class TReverseSubdivision
{
  public:
	TReverseSubdivision( TOGLTransf *_OGLTransf, int _type, TMeshPrimitiveParams *_params, int _level = 3 );
	~TReverseSubdivision( );

	bool IsCornerRail1( int index );
	bool IsCornerRail2( int index );
	bool IsCornerForm( int index );

	bool GetClosed_H( )
	{
		return Closed_H;
	}
	bool GetClosed_V( )
	{
		return Closed_V;
	}
	bool GetClosed_V_First( )
	{
		return Closed_V_First;
	}
	bool GetClosed_V_Last( )
	{
		return Closed_V_Last;
	}

	bool GetReverseSubdivision( TOGLPolygonList *coarseVertexs );

	bool GetReverseSubdivisionSISL( TOGLPolygonList *coarseVertexs );

  private:
	void InitValues( );
	void InitValuesRevolve( );
	void InitValuesOneRailSweep( );
	void InitValuesTwoRailsSweep( );
	void InitCornersRail1( int size );
	void InvertCornersRail1( );
	void SetFirstAtCornersRail1( int index );
	void InitCornersRail2( int size );
	void InvertCornersRail2( );
	void SetFirstAtCornersRail2( int index );
	void InitCornersForm( int size );
	void InvertCornersForm( );
	void SetFirstAtCornersForm( int index );
	void InitNormalsRail1( int size );
	void InvertNormalsRail1( );
	void SetFirstAtNormalsRail1( int index );

	bool GenFineVertexs( );
	bool GenFineVertexsRevolve( );
	bool GenFineVertexsOneRailSweep( );
	bool GenFineVertexsTwoRailsSweep( );
	void GetCoarsePoints( T3DPoint *finePoints, int numFinePoints, T3DPoint **coarsePoints, int &numCoarsePoint, int numTimes, bool closed );

	void GetVertexNeighbours( int sec, int pos, bool _closed_V, bool _closed_H, TOGLPolygon *vertexsEdge, TOGLPolygon *vertexsFace );

	bool GetReverseSubdivisionBasic( TOGLPolygonList *coarseVertexs, int _level, bool _closed_V, bool _closed_H );
	bool GetReverseSubdivisionForRevolve( TOGLPolygonList *coarseVertexs );
	bool GetReverseSubdivisionForClosedCurve( TOGLPolygonList *coarseVertexs );
	bool GetReverseSubdivisionForSweep( TOGLPolygonList *coarseVertexs );

	bool GetNControlPointsFromCurve( int n, TCadEntity *ent, TOGLPolygon *pol, bool *corners = 0, T3DPoint *normals = 0, T3DPoint *refPoint = 0 );
	bool GetReverseSubdivisionSISLForOneRailSweep( TOGLPolygonList *coarseVertexs );
	bool GetReverseSubdivisionSISLForTwoRailsSweep( TOGLPolygonList *coarseVertexs );
	void ClosedCornerDetection( int np, T3DPoint *Pts, double angledeg, TOGLPolygon *PolCorners );

	void GetBestRefPoints( TCadEntity *crv1, TCadEntity *crv2, T3DPoint &pt1, T3DPoint &pt2 );

  private:
	bool Closed_H, Closed_V, Closed_V_First, Closed_V_Last;
	int Type, Level;
	TMeshPrimitiveParams *Params;
	TOGLPolygonList *FineVertexs;
	TOGLTransf *OGLTransf;
	// Variables para el barrido
	int SizeCornersRail1, SizeCornersRail2, SizeCornersForm, SizeNormalsRail1;
	bool *CornersRail1, *CornersRail2, *CornersForm;
	T3DPoint *NormalsRail1;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// CLASE PRINCIPAL
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class TPBrepData
{
  public:
	TPBrepData( TCadEntity * );
	TPBrepData( IwPolyBrep *pBrep, bool copy );
	~TPBrepData( );

	bool CreatePBrep( TOGLTransf *OGLTransf, bool forcecheckpbrep = false, IwPolyVertex ***verticesOriginalPos = 0 );
	bool Set( TOGLTransf *OGLTransf, TPBrepData *pBrepData );
	bool CopyPBrep( IwPolyBrep *pbrepCopy, bool updateuvandtexcoords = true );
	bool AddFacesFromPBrep( TOGLTransf *OGLTransf, TPBrepData *pBrepData, bool cutOpenSeams = false, bool copyAll = false, bool updateTopology = true );
	bool SeparateSelectedFaces( TOGLTransf *OGLTransf );
	bool DuplicateSelectedFaces( TOGLTransf *OGLTransf );
	bool JoinMeshes( TOGLTransf *OGLTransf, TCadGroup *group, bool updateTopology = true );
	void UnSelectAll( TOGLTransf *OGLTransf );
	void ChangeSelectedElementsType( TOGLTransf *OGLTransf, int newMode );
	bool BooleanOperation( TOGLTransf *OGLTransf, TCadGroup *group, int BooleanOperation = 0, bool updateTopology = true, bool preserveCreaseAndSeam = true );
	bool BooleanOperationMultiple( TOGLTransf *OGLTransf, TCadGroup *group, int BooleanOperation = 0, bool updateTopology = true, bool preserveCreaseAndSeam = true );

	IwPolyBrep *GetPBrep( TOGLTransf *OGLTransf, bool force = true );

	int CountPBrepFaces( TOGLTransf *OGLTransf );
	IwTA<IwPolyFace *> *GetPBrepFaces( TOGLTransf *OGLTransf );
	IwPolyFace *GetPBrepFace( TOGLTransf *OGLTransf, int ind );

	int CountPBrepEdges( TOGLTransf *OGLTransf );
	IwTA<IwPolyEdge *> *GetPBrepEdges( TOGLTransf *OGLTransf );
	IwPolyEdge *GetPBrepEdge( TOGLTransf *OGLTransf, int ind );

	int CountPBrepVertexs( TOGLTransf *OGLTransf );
	IwTA<IwPolyVertex *> *GetPBrepVertexs( TOGLTransf *OGLTransf );
	IwPolyVertex *GetPBrepVertex( TOGLTransf *OGLTransf, int ind );
	T3DVector GetNormalPBrepVertex( TOGLTransf *OGLTransf, int index );
	T3DVector GetNormalPBrepVertex( TOGLTransf *OGLTransf, IwPolyVertex *vertex, IwTA<IwPolyFace *> *faces = 0 );
	T3DVector GetNormalPBrepVertexFromEdges( TOGLTransf *OGLTransf, IwPolyVertex *vertex );
	bool GetNormalVertexToExtrudeEdge( TOGLTransf *OGLTransf, TExtrudeEdgeType type, IwPolyVertex *vertex, T3DVector *norm, TNPlane plane = plNone, bool forcecalc = false );

	void SetVertexWeight( TOGLTransf *OGLTransf, int index, double w );
	double GetVertexWeight( TOGLTransf *OGLTransf, int index );

	bool IsFaceSelected( TOGLTransf *OGLTransf, int index, SelectedElementType selType = SelectedElementType::NoSelected );
	void UnSelectAllFaces( TOGLTransf *OGLTransf, SelectedElementType selType = SelectedElementType::All, float a = 0.0f, bool onlySubdivision = false, bool onlyLowPoly = false );
	void SelectAllFaces( TOGLTransf *OGLTransf, SelectedElementType selType = SelectedElementType::UserSelection, float a = 0.0f, bool onlySubdivision = false, bool onlyLowPoly = false );
	void SelectFace( TOGLTransf *OGLTransf, int ind, SelectedElementType selType = SelectedElementType::UserSelection, float a = 0.0f, bool onlySubdivision = false, bool onlyLowPoly = false, bool checkring = false );
	void SelectFaces( TOGLTransf *OGLTransf, TInteger_List *indexes, SelectedElementType selType = SelectedElementType::UserSelection, float a = 0.0f, bool onlySubdivision = false, bool onlyLowPoly = false, bool checkring = false );
	void SelectFaces( TOGLTransf *OGLTransf, IwTA<IwPolyFace *> *faces, SelectedElementType selType = SelectedElementType::UserSelection, float a = 0.0f, bool onlySubdivision = false, bool onlyLowPoly = false, bool checkring = false );
	void UnSelectFace( TOGLTransf *OGLTransf, int ind, float a = 0.0f, bool onlySubdivision = false, bool onlyLowPoly = false, bool checkring = false );
	void UnSelectFaces( TOGLTransf *OGLTransf, TInteger_List *indexes, float a = 0.0f, bool onlySubdivision = false, bool onlyLowPoly = false, bool checkring = false );
	IwTA<IwPolyFace *> GetFacesInsideSelection( TOGLTransf *OGLTransf, IwPolyFace *iwGuestFace, IwTA<IwPolyEdge *> *liwPolyEdges, bool unSel = false, bool useSemas = false );
	IwTA<IwPolyFace *> GetFacesInsideSelection( TOGLTransf *OGLTransf, IwPolyFace *iwGuestFace, IwTA<IwPolyFace *> *liwPolyFaces, bool useSemas = false );
	IwTA<IwPolyFace *> GetFacesInsideNoSelection( IwPolyFace *iwGuestFace, ElementType eType, bool useSemas = false );
	int *GetFaces( TOGLTransf *OGLTransf, SelectedElementType selType, int &iNumFaces );
	bool GetDisjointGroupFaces( IwTA<IwPolyFace *> *faces, vector<vector<int> > *groups );
	bool GetDisjointGroupFaces( TOGLTransf *OGLTransf, vector<vector<int> > *groups, bool extend = false, bool allFaces = false, bool useSeams = false );
	bool GetDisjointGroupEdges( TOGLTransf *OGLTransf, vector<vector<int> > *groups );
	bool GetDisjointGroupVertexs( TOGLTransf *OGLTransf, vector<vector<int> > *groups );
	bool GetDisjointLoopsEdges( TOGLTransf *OGLTransf, vector<vector<int> > *groups, bool extend = false, bool allEdges = false, IwTA<IwPolyEdge *> *edges = 0 );
	bool IsAnyFaceSelected( TOGLTransf *OGLTransf, SelectedElementType selType = SelectedElementType::All );
	int GetFacesSelected( TOGLTransf *OGLTransf, SelectedElementType selType = SelectedElementType::All );
	int GetFaceSelectedType( int index );
	bool GetShortPathBetweenFaces( TOGLTransf *OGLTransf, int indexFaceStart, int indexFaceEnd, int type );

	bool IsEdgeSelected( TOGLTransf *OGLTransf, int index, SelectedElementType selType = SelectedElementType::NoSelected );
	void SelectAllEdges( TOGLTransf *OGLTransf, SelectedElementType selType = SelectedElementType::UserSelection, bool checkring = false );
	void UnSelectAllEdges( TOGLTransf *OGLTransf );
	void SelectEdge( TOGLTransf *OGLTransf, int ind, SelectedElementType selType = SelectedElementType::UserSelection, bool checkring = false );
	void SelectEdges( TOGLTransf *OGLTransf, TInteger_List *indexes, SelectedElementType selType = SelectedElementType::UserSelection, bool checkring = false );
	void UnSelectEdge( TOGLTransf *OGLTransf, int ind, bool checkring = false );
	void UnSelectEdges( TOGLTransf *OGLTransf, TInteger_List *indexes, bool checkring = false );
	int *GetEdges( TOGLTransf *OGLTransf, SelectedElementType selType, int &iNumEdges, bool force = true );
	bool IsAnyEdgeSelected( TOGLTransf *OGLTransf, SelectedElementType selType = SelectedElementType::All );
	int GetEdgesSelected( TOGLTransf *OGLTransf, SelectedElementType selType = SelectedElementType::All );
	int *GetEdgesFromSelection( TOGLTransf *OGLTransf, int &numedges );
	int GetEdgeSelectedType( int index );
	void GetBoundaryEdgesOrVertexs( TInteger_List *borderIndexs, ElementType etype );
	bool GetShortPathBetweenEdges( TOGLTransf *OGLTransf, int indexEdgeStart, int indexEdgeEnd, int type );

	void SelectAllVertexs( TOGLTransf *OGLTransf, SelectedElementType selType = SelectedElementType::UserSelection, bool recalc = true );
	bool IsVertexSelected( TOGLTransf *OGLTransf, int index, SelectedElementType selType = SelectedElementType::NoSelected );
	bool IsVertexSelectedFromEdge( TOGLTransf *OGLTransf, int index, SelectedElementType selType = SelectedElementType::NoSelected );
	bool IsVertexSelectedFromFace( TOGLTransf *OGLTransf, int index, SelectedElementType selType = SelectedElementType::NoSelected );
	void UnSelectAllVertexs( TOGLTransf *OGLTransf );
	void SelectVertex( TOGLTransf *OGLTransf, int ind, SelectedElementType selType = SelectedElementType::UserSelection, bool recalc = true );
	void SelectVertexs( TOGLTransf *OGLTransf, TInteger_List *indexes, SelectedElementType selType = SelectedElementType::UserSelection, bool recalcW = true );
	void UnSelectVertex( TOGLTransf *OGLTransf, int ind, bool deleteW = true );
	void UnSelectVertexs( TOGLTransf *OGLTransf, TInteger_List *indexes, bool deleteW = true );
	int *GetVertexs( TOGLTransf *OGLTransf, SelectedElementType selType, int &iNumVertex );
	bool IsAnyVertexSelected( TOGLTransf *OGLTransf, SelectedElementType selType = SelectedElementType::All );
	int GetVertexsSelected( TOGLTransf *OGLTransf, SelectedElementType selType = SelectedElementType::All );
	int GetVertexSelectedType( int index );
	void GetIsolatedVertexs( TInteger_List *isolatedVertexsIndexs, double angle );
	bool GetShortPathBetweenVertexs( TOGLTransf *OGLTransf, int indexVertexStart, int indexVertexEnd, int type );
	bool InitVertexConnectedFromArea( TOGLTransf *OGLTransf, IwTA<IwPolyVertex *> *vertex, double area, TProportionalEditingType type, int *nElem, int **idElem, T3DPoint **points );
	bool InitVertexFromArea( TOGLTransf *OGLTransf, vector<vector<int> > *groups, ElementType typeEl, double area, TProportionalEditingType type, int *nElem, int **idElem, T3DPoint **points );
	int IsAnyClosedRingSelected( TOGLTransf *OGLTransf, ElementType faceOrEdge, bool force = false, IwTA<IwTA<IwPolyFace *> > *faces = 0, IwTA<IwTA<IwPolyEdge *> > *edges = 0 );

	bool FillSelection( TOGLTransf *OGLTransf, int faceInd, int mode, bool delFromSelect = true, bool useSeams = false );
	bool InvertSelection( TOGLTransf *OGLTransf, ElementType eType = ElementType::Undefined );
	bool GetSelectionCentroid( TOGLTransf *OGLTransf, T3DPoint *pos, T3DVector *normal = 0, bool centroidFromSubdivision = false );
	bool GetSelectionMiddleNormal( TOGLTransf *OGLTransf, T3DVector *norm );
	bool GetSelectionGroupMiddleNormal( TOGLTransf *OGLTransf, IwPolyFace *currentFace, T3DVector *normal );

	bool IsCorrectBoundarySelectionCreateFace( TOGLTransf *OGLTransf, ElementType eType );
	bool CreateFaceFromBoundarySelection( TOGLTransf *OGLTransf, ElementType eType, int selectededges[ 2 ] = 0 );
	bool OrderBoundaryVertexsByContinuity( IwTA<IwPolyVertex *> *vertexsIn, IwTA<IwTA<IwPolyVertex *> > *vertexsOut );
	bool CheckClockwiseVertexsForNewFace( IwTA<IwPolyVertex *> *vertexs );
	bool CreateFaceFromCurrentMeshElementList( TOGLTransf *OGLTransf, IwTA<TMeshElementInfo> *elements, IwTA<IwPolyFace *> *faces = 0, bool retopologize = false, IwPolyFace *facetodelete = 0 );

	int GetNearestEdgeToPoint( TOGLTransf *OGLTransf, int indexFace, T3DPoint point );
	int GetOppositeEdgeFace( TOGLTransf *OGLTransf, int indexFace, int indexEdge );
	bool IsQuadFace( TOGLTransf *OGLTransf, int indexFace );

	// Mover
	bool TranslateSelectedFaces( TOGLTransf *OGLTransf, float incrX, float incrY, float incrZ, bool updateOGLList = true );
	bool TranslateSelectedEdges( TOGLTransf *OGLTransf, float incrX, float incrY, float incrZ, bool updateOGLList = true );
	bool TranslateSelectedVertexs( TOGLTransf *OGLTransf, float incrX, float incrY, float incrZ, bool updateOGLList = true, bool slideVertexs = false, int edgeindex = -1, bool updateuv = true );
	bool Translate( TOGLTransf *OGLTransf, float incrX, float incrY, float incrZ, bool updateOGLList = true );
	bool TranslateEditedVertexs( TOGLTransf *OGLTransf, float length, bool testLengthEdges = false, bool updateOGLList = true );
	bool TranslateProportionalEditing( TOGLTransf *OGLTransf, float incrX, float incrY, float incrZ, bool updateOGLList = true );

	// Rotar
	bool RotateSelectedFaces( TOGLTransf *OGLTransf, float angle, T3DVector axis, bool updateOGLList = true );
	bool RotateSelectedEdges( TOGLTransf *OGLTransf, float angle, T3DVector axis, bool updateOGLList = true );
	bool RotateSelectedVertexs( TOGLTransf *OGLTransf, float angle, T3DVector axis, bool updateOGLList = true );
	bool Rotate( TOGLTransf *OGLTransf, float angle, T3DVector axis, bool updateOGLList = true );
	bool RotateProportionalEditing( TOGLTransf *OGLTransf, float angle, T3DVector axis, bool updateOGLList = true );

	// Escalar
	bool ScaleSelectedFaces( TOGLTransf *OGLTransf, float factorX, float factorY, float factorZ, TNMatrix matSCP, TNMatrix matSCPinv, bool updateOGLList = true );
	bool ScaleSelectedEdges( TOGLTransf *OGLTransf, float factorX, float factorY, float factorZ, TNMatrix matSCP, TNMatrix matSCPinv, bool updateOGLList = true );
	bool ScaleSelectedVertexs( TOGLTransf *OGLTransf, float factorX, float factorY, float factorZ, TNMatrix matSCP, TNMatrix matSCPinv, bool updateOGLList = true );
	bool Scale( TOGLTransf *OGLTransf, float factorX, float factorY, float factorZ, TNMatrix matSCP, TNMatrix matSCPinv, bool updateOGLList = true );
	bool ScaleProportionalEditing( TOGLTransf *OGLTransf, float factorX, float factorY, float factorZ, TNMatrix matSCP, TNMatrix matSCPinv, bool updateOGLList = true );

	// Extruir caras
	bool ExtrudeSelectedFaces( TOGLTransf *OGLTransf, float incrX, float incrY, float incrZ, TExtrudeType extrudetype, int sign, bool createFaces, bool updateOGLList = true, bool creaseUpBorder = false, double valcrease = 1.0 );
	bool ExtrudeSelectedFacesByDirection( TOGLTransf *OGLTransf, float incrX, float incrY, float incrZ, int sign, bool updateOGLList = true );
	bool ExtrudeSelectedFacesByNormalFace( TOGLTransf *OGLTransf, float length, int sign, bool updateOGLList = true );
	bool ExtrudeSelectedGroupFacesByNormal( TOGLTransf *OGLTransf, float length, int sign, bool updateOGLList );
	bool ExtrudeSelectedGroupFacesByVertexNormal( TOGLTransf *OGLTransf, float length, int sign, bool updateOGLList, bool creaseUpBorder = false, double valcrease = 1.0 );
	// Extruir aristas
	bool ExtrudeSelectedEdges( TOGLTransf *OGLTransf, float incrX, float incrY, float incrZ, TExtrudeEdgeType extrudeedgetype, int sign, bool createFaces, TNPlane extrusionplane, int indexvertex = -1, bool updateOGLList = true );
	bool ExtrudeSelectedEdgesByExtrudeType( TOGLTransf *OGLTransf, TExtrudeEdgeType extrudeedgetype, float length, TNPlane extrusionplane, int indexvertex, bool updateOGLList );
	bool ExtrudeSelectedEdgesByDirection( TOGLTransf *OGLTransf, TNMatrix *mat = 0, TNRotateMatrix *matrot = 0, IwTA<int> *indexes = 0, IwTA<T3DPoint> *positions = 0, bool updateOGLList = true );
	bool IsBoundaryEdge( int ind );

	// Inset
	bool InsetSelectedFaces( TOGLTransf *OGLTransf, float incrX, float incrY, float incrZ, int type, int sign, bool createFaces, bool normalizeDirs, IwTA<TInfoToRestoreData *> *infotorestoredata = 0, bool updateOGLList = true );

	// Bevel
	bool BevelSelectedFaces( TOGLTransf *OGLTransf, float incrX, float incrY, float incrZ, int sign, bool createFaces, bool updateOGLList = true );

	// Matriz
	void SetInvalidNormalsToSelection( TOGLTransf *OGLTransf, ElementType type );
	bool ApplyMatrixToSelectedFaces( TOGLTransf *OGLTransf, TNMatrix matrix, bool updateOGLList = true );
	bool ApplyMatrixToSelectedEdges( TOGLTransf *OGLTransf, TNMatrix matrix, bool updateOGLList = true );
	bool ApplyMatrixToSelectedVertexs( TOGLTransf *OGLTransf, TNMatrix matrix, bool updateOGLList = true );

	void ApplyMatrixPBrep( TOGLTransf *OGLTransf, TNMatrix *matrix, bool updatePolList = false, bool calcnormals = true );

	bool GetPBrepPolListRelF( TOGLTransf *OGLTransf, int index, int &numPol, int &numFace, int &numVert );
	bool GetPBrepBorder( TOGLTransf *OGLTransf, IwTA<IwPolyEdge *> *edges, TOGLPolygonList *polList );

	void UpdateOGLListFromPBrep( TOGLTransf *OGLTransf, TOGLPolygonList *OGLList, bool checkSelected = false, bool calcnormals = false, bool updatetexcoords = true, bool recalcTopology = false );
	void UpdateNormalsOGLListFromPBrep( TOGLTransf *OGLTransf, TOGLPolygonList *OGLList = 0, bool onlyinvalids = false );
	void UpdatePBrepFromOGLList( TOGLTransf *OGLTransf, TOGLPolygonList *OGLList, bool checkSelected = false, bool updatenormals = false, bool updatetexcoords = false );
	void UpdatePBrepUVFromOGLList( TOGLTransf *OGLTransf, TOGLPolygonList *develop = 0, bool issubd = false );
	void UpdateColorsFromSelection( TOGLTransf *OGLTransf );
	void UpdateColorsFromPBrep( TOGLTransf *OGLTransf, TOGLPolygonList *OGLColorList, TColor *cIni, TColor *cEnd );
	void UpdateNormalsFromPBrep( TOGLTransf *OGLTransf, TOGLPolygonList *OGLList );
	void CreateOGLDataFromPolyEdge( IwPolyEdge *edge, TOGLPolygon *oglpoledge );
	TOGLPolygon *GetOGLDataFromPolyFace( TOGLTransf *OGLTransf, TOGLPolygonList *OGLList, IwPolyFace *iwPolyFace, int &index );
	IwTA<IwPolyFace *> GetPolyFacesFromOGLPolygon( TOGLTransf *OGLTransf, TOGLPolygonList *OGLList, int iPos );
	void UpdateColorsForProportionalEditing( TOGLTransf *OGLTransf, TOGLPolygonList *OGLColorList, TColor *cIni, TColor *cEnd );

	T3DPoint *GetPoints( TOGLTransf *OGLTransf, int &np );
	bool GetAllFromOGLList( TOGLTransf *OGLTransf, int &np, TOGLPolygonList *OGLList, T3DPoint **points, T3DPoint **pointsuv, T3DPoint **normals );
	T3DPoint *GetPointsFromOGLList( TOGLTransf *OGLTransf, int &np, TOGLPolygonList *OGLList );
	T3DPoint *GetPointsUVFromOGLList( TOGLTransf *OGLTransf, int &np, TOGLPolygonList *OGLList );
	void SetPointsToOGLList( TOGLTransf *OGLTransf, int np, T3DPoint *pts, TOGLPolygonList *OGLList, bool locknormals = false );
	T3DPoint *GetNormalsFromOGLList( TOGLTransf *OGLTransf, int &np, TOGLPolygonList *OGLList );
	void SetNormalsToOGLList( TOGLTransf *OGLTransf, int np, T3DPoint *normals, TOGLPolygonList *OGLList );
	T3DPoint *GetTextureCoordsFromOGLList( TOGLTransf *OGLTransf, int &np, TOGLPolygonList *OGLList );
	void UpdateOGLListAuxInfoList( TOGLTransf *OGLTransf );

	bool GetPBrepFaceTriangulation( )
	{
		return PBrepFaceTriangulation;
	}
	void SetPBrepFaceTriangulation( bool value )
	{
		PBrepFaceTriangulation = value;
	}

	bool AreTrianglesForced( );

	void InitIndexSelected( );

	void SetCompareMask( int value );
	int GetCompareMask( );
	void SetRepairTol( double value );
	double GetRepairTol( );

	void FindNeighbors( IwTA<IwPolyVertex *> vertexs, IwTA<IwPolyVertex *> &neighbors, float radius );
	void ConvertSelectionCurveToBrepVertexs( TOGLTransf *OGLTransf, TOGLPolygonList *OGLListCurve, IwTA<IwPolyVertex *> *vertexsCurveOut );
	void ConvertSelectionCurveVertexsToUV( TOGLTransf *OGLTransf, IwTA<IwPolyVertex *> *vertexsCurve, bool *close, double *limitsUV, double tol_1, TOGLPolygon *polUVOut );
	void FindNeighborsOverSelectionCurveByRadius( TOGLPolygonList *OGLListCurve, IwTA<IwPolyVertex *> &vertexsCurve, IwTA<IwPolyVertex *> &vertexsSelectedOut, double radius, float *entityDeformerWeights );

	IwPolyVertex *GetClosestVertex( IwPolyVertex *vGuess, IwPoint3d ptDest );
	IwPolyVertex *GetClosestVertex( IwPoint3d ptDest, double tol = RES_COMP, IwTA<IwPolyFace *> *PBrepFacesSubset = NULL );
	IwPolyFace *GetClosestFace( IwPoint3d ptDest, double tol = RES_COMP, IwTA<IwPolyFace *> *PBrepFacesSubset = NULL );

  public:
	bool CreatePBrepArrays( );

  protected:
	void DestroyPBrepVars( );
	void CalcNeigWeight( TOGLTransf *OGLTransf, IwPolyVertex vertexsToNeig, IwTA<IwPolyVertex *> neighbors, float radius, vector<float> *w );

	//==============================================================================
	//==============================================================================
	// SUBSOLES
	//==============================================================================
	//==============================================================================

  public:
	// --
	// Subdivision
	int GetSubdividedOGLList( TOGLTransf *OGLTransf, TOGLPolygonList *ogllist, TOGLPolygon *ogllistVertex, TOGLPolygon *ogllistEdges, TOGLPolygon *ogllistFaces, TSubdivisionData *subdivisiondata, TInteger_ListList *auxinfolist = 0, TOGLPolygonList *outOGLListExtraValues = 0 );
	void UpdateTextureUVSubdivision( TOGLPolygonList *ogllist, TSubdivisionData *subdivisiondata );
	void ClearSubdivision( );
	void ClearTempData( );
	bool CheckConsistency( IwTA<IwPolyVertex *> *iwVertexToCheck, IwTA<IwPolyEdge *> *iwEdgesToCheck, IwTA<IwPolyVertex *> *vertexsOut = 0, IwTA<IwPolyEdge *> *edgesOut = 0, IwTA<IwPolyFace *> *facesOut = 0 );
	bool CanSubdivide( bool force = false, IwTA<IwPolyVertex *> *vertexsOut = 0, IwTA<IwPolyEdge *> *edgesOut = 0, IwTA<IwPolyFace *> *facesOut = 0 );
	bool ApplySubdivision( TOGLTransf *OGLTransf, bool keepcreases = true );

	// --
	// Creación de primitivas lowPoly
	void CreateLowPolyCube( TOGLTransf *OGLTransf, TMeshPrimitiveParams *params );
	bool GetPointsSphere( TOGLTransf *OGLTransf, double radius, IwTA<T3DPoint> *iwPointsUp, IwTA<T3DPoint> *iwPointsMid, IwTA<T3DPoint> *iwPointsDown );
	void CreateLowPolySphere( TOGLTransf *OGLTransf, TMeshPrimitiveParams *params );
	void CreateLowPolyCylinder( TOGLTransf *OGLTransf, TMeshPrimitiveParams *params );
	void CreateLowPolyPlane( TOGLTransf *OGLTransf, TMeshPrimitiveParams *params );
	bool CreateLowPolyPipe( TOGLTransf *OGLTransf, TCadEntity *rail, TMeshPrimitiveParams *params );
	bool CreateLowPolyRevolve( TOGLTransf *OGLTransf, TMeshPrimitiveParams *params );
	bool CreateLowPolyContour( TOGLTransf *OGLTransf, TMeshPrimitiveParams *params );
	bool CreateLowPolyOneRailSweep( TOGLTransf *OGLTransf, TMeshPrimitiveParams *params );
	bool CreateLowPolyTwoRailsSweep( TOGLTransf *OGLTransf, TMeshPrimitiveParams *params );

	// --
	// Primitivas/Modificadores
	bool Solidify( TOGLTransf *OGLTransf, float incrX, float incrY, float incrZ, int bordertype, int indexFace, int sign, bool createFaces, bool updateOGLList = true );
	void ReverseOrientation( TOGLTransf *OGLTransf, bool onlygroupbyselection = true );

	// --
	// Creacion de lowpoly a partir de curvas
	bool CreateMeshFromCurves( TOGLTransf *OGLTransf, TPBrepFromCurvesData *curveData, TMeshFromCurvesParams *params );
	void ReconstructLowPoly( TOGLTransf *OGLTransf, bool tryUnify = true, double angleTolerance = 0.01 );
	void ExportLowPolyToObj( UnicodeString file, int nDecimals = 6 );

	// Color
	void UpdateColor( TOGLTransf *OGLTransf, int ind, SelectedElementType selType, TInteger_List *indexes = 0, float a = 0.0f, bool onlySubdivision = false, bool onlyLowPoly = false );
	void SetColorEntities( TColor colorFace, TColor colorEdge, TColor vertex, TColor colorSelectFace, TColor seam );

  protected:
	IwPolyVertex *FindVertex( IwPoint3d *iwPoint );
	IwPolyVertex *FindVertex( IwTA<IwPolyVertex *> *iwVertexs, IwPoint3d *iwPoint, ULONG &pos );

	TOGLPoint *GetSubdivisionCentroidFromVertex( TOGLTransf *OGLTransf, IwPolyVertex *vertex, T3DVector *normal = 0 );
	T3DPoint GetSubdivisionCentroidFromEdge( TOGLTransf *OGLTransf, IwPolyEdge *edge, T3DVector *normal = 0 );
	T3DPoint GetSubdivisionCentroidFromFace( TOGLTransf *OGLTransf, IwPolyFace *face, T3DVector *normal = 0 );

	// --
	// Anillos

  public:
	int GetOneRing_Iterative( TOGLTransf *OGLTransf, IwTA<int> liSelectedElements, TOneRingParams optionsSelectElements, IwTA<TDataIntIntForVertexPaths> *liVertexLists, IwTA<TDataIntIntForVertexPaths> *liVertexListsForSecondEdge );
	TCadPolyline *GetPolylineFromVertices( TOGLTransf *oglTransf, IwTA<int> *liVertices, bool &bValid );
	IwTA<IwPolyEdge *> GetEdgeRingFromFacesConnection( TOGLTransf *OGLTransf, ULONG index );
	TCadPolyline *GetPolylineFromEdgesAtParam( TOGLTransf *oglTransf, IwTA<IwPolyEdge *> edges, double param );
	bool OrderHighEdges( TOGLTransf *OGLTransf, TOGLPolygon *poledgeSelect, TOGLPolygon *poledgeSelectOrder );
	void GetPolylinesFromSelectedEdges( TOGLTransf *OGLTransf, TCadGroup *group, bool fromSubdivision, bool allEdges = false );

	// Costuras

  public:
	int CountPBrepSeams( )
	{
		return SeamEdges.GetSize( );
	}
	bool IsEdgeSeam( TOGLTransf *OGLTransf, int index, int *index1 = 0 );
	bool IsEdgeSeam( IwPolyEdge *edge, int *index1 = 0 );
	IwTA<IwPolyEdge *> *GetSeams( )
	{
		return &SeamEdges;
	}
	IwPolyEdge *GetSeamByIndex( int index );
	void UpdatePBrepSeamFromOGLList( TOGLTransf *OGLTransf );
	void UpdateOGLListSeamFromPBrep( TOGLTransf *OGLTransf );
	void AddSeamEdge( IwPolyEdge *edge );
	void AddSeamEdge( TOGLTransf *OGLTransf, int edge );
	DefinesForErrors AddSeamEdges( TOGLTransf *OGLTransf, TInteger_List *list = 0 );
	DefinesForErrors DeleteSeamEdges( TOGLTransf *OGLTransf, TInteger_List *list );
	DefinesForErrors DeleteSelectedSeamEdges( TOGLTransf *OGLTransf );
	DefinesForErrors DeleteAllSeamEdges( );
	void UpdateAllSeamEdgesFromPBrep( );
	void SelectSeams( TOGLTransf *OGLTransf );
	void UnSelectSeams( TOGLTransf *OGLTransf );
	void SetSharpnessEdge( TOGLTransf *OGLTransf, bool b );
	bool IsClosedPath( IwTA<IwPolyEdge *> *path );
	bool IsClosedPath( IwTA<IwPolyFace *> *path );
	bool IsAnySeamInsideOfGroupOfFaces( vector<int> *group, IwTA<IwPolyEdge *> *insideSeams );
	bool GetFacesBothSideOfSeam( IwTA<IwPolyEdge *> *seam, IwTA<IwPolyFace *> *faces1, IwTA<IwPolyFace *> *faces2 );
	bool GetFacesGroupedByVertexSeam( IwPolyVertex *vertex, IwTA<IwTA<IwPolyFace *> > *faces );
	bool IsVertexSeam( IwPolyVertex *vertex );
	bool IsVertexSeamExtrem( IwPolyVertex *vertex, int *num = 0 );
	void SetUVForVertex( IwPolyVertex *vertex, IwPoint2d &uv, IwPolyFace *face = 0, bool alledges = false );

  private:
	void MarkEdgeUserLong2WithSeams( );
	void GetEdgesMarkedByUserLong2( IwTA<IwTA<IwPolyEdge *> > *edgeGroups );

	// Pliegues

  public:
	bool IsEdgeCrease( TOGLTransf *OGLTransf, int index, bool sharp = false, int level = 1 );
	bool IsEdgeCrease( IwPolyEdge *edge );
	void AddCreaseEdges( TOGLTransf *OGLTransf, IwPolyEdge *edge = 0, float percent = 0.0, bool updateDataSubdivision = true, bool updateOGLList = false, SelectedElementType selType = SelectedElementType::AllSelected, bool checkIsSubd = true );
	void RemoveCreaseEdges( TOGLTransf *OGLTransf, bool updateDataSubdivision = true, bool updateOGLList = false, bool force = true );
	float GetCreaseAverage( TOGLTransf *OGLTransf );
	void UpdatePBrepCreases( TOGLTransf *OGLTransf, bool updateDataSubdivision = true, bool updateOGLList = true );

  protected:
	void UpdatePBrepCreasesFromOGLList( TOGLTransf *OGLTransf, bool force = true );
	void UpdateOGLListCreasesFromPBrep( TOGLTransf *OGLTransf, bool updateNormals = true );
	void GetGroupsOfFacesFromCreaseSharps( TOGLTransf *OGLTransf, IwTA<IwTA<IwPolyEdge *> > *creaselist, IwTA<IwTA<IwPolyFace *> > *faces1, IwTA<IwTA<IwPolyFace *> > *faces2 );

  private:
	void GetCreaseEdges( TOGLTransf *OGLTransf, IwTA<IwPolyEdge *> *creaseEdges, bool onlysharp = false );
	void GetCreaseAndSeamEdgesFromVertex( IwPolyVertex *vertex, IwTA<IwPolyEdge *> *creaseAndSeamEdgesFromVertex, IwTA<IwPolyEdge *> &creaseEdges, IwTA<IwPolyEdge *> &seamEdges );
	bool ObtainListOfCreaseSharp( TOGLTransf *OGLTransf, IwTA<IwTA<IwPolyEdge *> > *crease );
	bool GetFacesBothSideOfCreaseSharp( IwTA<IwPolyEdge *> *crease, IwTA<IwPolyFace *> *faces1, IwTA<IwPolyFace *> *faces2 );
	int SaveCreaseEdgeInfo( IwPolyEdge *edge, IwTA<int> *longuser2, IwTA<float> *values, bool force = false, int userLong2 = 0 );
	void RestoreCreaseEdgeInfo( TAddedElements *addedElements, IwTA<int> *userlongs2, IwTA<float> *values );
	void AddCreaseEdgesAffectedFromVertex( IwPolyVertex *iwVertex, IwTA<ULONG> *iwIndexes, IwTA<IwPolyVertex *> *iwStartVertexs, IwTA<IwPolyVertex *> *iwEndVertexs );
	void UpdateCreaseEdgesAffected( TAddedElements *addedElements, IwTA<ULONG> *iwIndexes, IwTA<IwPolyVertex *> *iwStartVertexs, IwTA<IwPolyVertex *> *iwEndVertexs );
	void AddCreaseEdgesAffectedFromFace( IwPolyFace *iwFace, IwTA<ULONG> *iwIndexes, IwTA<IwPolyVertex *> *iwStartVertexs, IwTA<IwPolyVertex *> *iwEndVertexs );
	void UpdateCreaseEdgesAffectedFromDisolve( TAddedElements *addedElements, IwTA<ULONG> *iwIndexes, IwTA<IwPolyVertex *> *iwStartVertexs, IwTA<IwPolyVertex *> *iwEndVertexs, IwTA<int> *newindexes, IwTA<float> *values );
	void AddCreaseEdgesAffectedFromVertexDisolve( IwPolyVertex *iwVertex, IwTA<ULONG> *iwIndexes, IwTA<IwPolyVertex *> *iwStartVertexs, IwTA<IwPolyVertex *> *iwEndVertexs );
	void MarkCreaseNewFace( IwPolyFace *iwFace, IwPolyVertex *iwVertex1, IwPolyVertex *iwVertex2, float value = 1.0 );
	void SaveCreaseAndSeamsValuesFromCollapseVertexs( IwTA<IwPolyFace *> *vsFaces, IwTA<IwPolyFace *> *veFaces, IwPolyVertex *vertexStart, IwPolyVertex *vertexEnd, IwTA<IwPolyVertex *> *vertexsI, IwTA<IwPolyVertex *> *vertexsE, IwTA<int> *isSeam, IwTA<double> *valCrease );

	// Contornos

  private:
	void JoinTrianglesInQuads( TOGLTransf *OGLTransf );
	bool DuplicateFaces( TOGLTransf *OGLTransf, IwTA<IwPolyFace *> *newfaces, IwTA<IwPolyEdge *> *boundaryedges, IwTA<IwPolyFace *> *orgfaces );

	// Funciones de apoyo

  private:
	bool TryOneRingShortest_GreatestLength( ULONG ulSelectedElement, ElementType eType, IwTA<TDataIntIntForVertexPaths> *liVertexPaths, bool bShortest = true );
	bool TryOneRingLevel( ULONG iSelectedElement, ElementType eType, IwTA<TDataIntIntForVertexPaths> *liElementsPaths, int iLevel );
	bool TryOneRingConnectedEdges_ForEdges_Iterative( int iSelectedEdge, IwTA<TDataIntIntForVertexPaths> *liVertexPaths );
	bool TryOneRingConnectedFaces_ForFaces_Iterative( ULONG ulSelectedFace, bool bFirstEdge, IwTA<TStructFaces> *liFacesPaths, OneRingFacesSearchMethod oneRingFacesSearchMethod, int indexEdge = -1 );
	IwTA<IwPolyEdge *> GetNextEdge_Iterative( IwTA<TDataIntIntForVertexPaths> *liVertexPaths, IwTA<IwPolyVertex *> *liwTopologyVertexAtStart, IwTA<IwPolyVertex *> *liwTopologyVertexAtEnd );
	IwTA<IwPolyEdge *> GetNextEdgeAtStart_Iterative( IwTA<TDataIntIntForVertexPaths> *liVertexPaths, IwTA<IwPolyVertex *> *liTopologyVertexAtStart );
	IwTA<IwPolyEdge *> GetNextEdgeAtEnd_Iterative( IwTA<TDataIntIntForVertexPaths> *liVertexPaths, IwTA<IwPolyVertex *> *liTopologyVertexAtEnd );
	bool GetBoundaryEdgesConnected( int iSelectedEdge, IwTA<TDataIntIntForVertexPaths> *liVertexPaths );
	bool CheckEndingConditions( int iSelected, IwTA<TDataIntIntForVertexPaths> *liVertexPaths, bool &bContinue );
	void DeleteInvalidRings( TOGLTransf *OGLTransf, IwTA<TDataIntIntForVertexPaths> *liVertexLists, IwTA<int> *liSelectedElements, ElementType eType );
	bool GetFirstValidVertexFromList( IwTA<IwPolyVertex *> *liwVertexActual, int &iFirstVertex, bool &bClockWise );
	int GetNextVertexFromList( IwTA<IwPolyVertex *> *liwVertexActual, int iCurrentVertex, IwTA<IwPolyFace *> *liwFacesOrig, bool bClockWise );
	IwTA<IwPolyVertex *> SetStartIndex( IwTA<IwPolyVertex *> liwVertexNew, ULONG i );
	IwTA<IwPolyEdge *> GetNextEdge( IwPolyFace *iwFace, IwPolyEdge *iwPreviousEdge, OneRingFacesSearchMethod method, bool bOnlyQuads = true );
	bool CheckEndingConditions_FacesRing( IwTA<TStructFaces> *liFacesPath, bool &bContinue, bool &bOneRingClosed );
	bool GetEdgeListFromVerticesList( IwTA<TDataIntIntForVertexPaths> *liVertices, IwTA<TDataIntIntForVertexPaths> *liEdgesList );
	bool PathBetweenFaces( IwPolyFace *faceStart, IwPolyFace *faceEnd, IwPolyEdge *edgeStart, IwTA<IwPolyFace *> *rPath );
	bool DistancePathBetweenVertexs( IwPolyVertex *vertexStart, IwPolyVertex *vertexEnd, IwTA<TDataVertexInfo> *paths );
	bool TopologyDistancePathBetweenVertexs( IwPolyVertex *vertexStart, IwPolyVertex *vertexEnd, IwTA<TDataVertexInfo> *paths );

	IwTA<IwPolyFace *> GetConnectedFacesFromVertex( ULONG iSelectedVertex );
	IwPolyEdge *GetOppositeEdgeFromVertex( IwPolyEdge *iwPolyEdge, IwPolyVertex *iwPolyVertex_Common );
	IwPolyEdge *GetOppositeEdgeFromFace( IwPolyEdge *iwPolyEdge, IwPolyFace *iwFace_Common, bool onlyQuads );
	bool AreAdjacentFaces( IwPolyFace *iwFace1, IwPolyFace *iwFace2 );
	bool IsAdjacentFaceToGroup( IwPolyFace *f, vector<int> *group );
	IwTA<IwPolyFace *> GetFacesFromVertices( IwTA<IwPolyVertex *> liwVertices );
	IwTA<IwPolyFace *> GetFacesFromVerticesIndexes( IwTA<int> vertexindexes );
	double Perimeter( IwPolyFace *iwFace );
	double Perimeter( int iFace );
	double PerimeterSquared( IwPolyFace *iwFace );
	double PerimeterSquared( int iFace );
	IwTA<IwPolyVertex *> OrderListOfVertexes( IwTA<IwPolyVertex *> *liwVertexActual, IwTA<IwPolyFace *> *liwFaces, bool &bClockWise );
	bool IsClockWise( int iNumPoints, T3DPoint *lpt3d, T3DPlane pln );
	bool AreAnyNonSelFaces( TOGLTransf *OGLTransf, IwPolyVertex *vertex );
	IwTA<IwPolyFace *> GetAdjacentFacesFromVertexFace( IwPolyFace *faceIn, IwPolyVertex *vertex );
	bool IsFaceConnectedToSelGroupByVertex( TOGLTransf *OGLTransf, IwPolyFace *face, IwTA<IwPolyFace *> *faces, IwPolyVertex *vertex );

	// TEXTURIZADO

  private:
	// Funciones para obtener las coordenadas de textura y las UV a partir de un punto interior a una cara o un punto de una arista
	void GetBarycentricCoordinatesOfPolygonForEdge( IwPolyEdge *edge, IwPoint3d &point, IwPoint2d *uvcoords );
	bool GetBarycentricCoordinatesOfPolygonForFace( TOGLTransf *OGLTransf, IwPolyFace *face, IwPoint3d &point, IwPoint2d *uvcoords, bool force = false );
	bool GetBarycentricCoordinatesOfPolygon( TOGLTransf *OGLTransf, TOGLPolygon *pol, IwPoint3d &point, IwPoint2d *uvcoords, bool force = false );
	// Funciones auxiliares
	bool GetBarycentricCoordinatesOfTriangle( TOGLPolygon *pol, IwPoint3d &point, IwPoint2d *coords, bool force = false );
	bool CalcUVAndTextureCoordsFromBarycentricCoordinates( TOGLPolygon *pol, IwPoint2d &barycentric, IwPoint2d *uvcoords );
	bool ContainsPoint( TOGLPolygon *pol, IwPoint3d &point );
	IwPolyVertex *AddNewVertex( IwPoint3d &crVertexPoint, double dTolerance, IwPolyEdge *edge = 0, IwPolyFace *face = 0, IwPoint2d *crUV = 0, IwPolyBrep *pBrep = 0 );

  public:
	IwTA<IwPolyFace *> GetConnectedFacesFromEdge( ULONG iSelectedEdge );
	IwTA<IwPolyFace *> GetConnectedFacesFromEdge( IwPolyEdge *iwPolyEdge );
	IwTA<IwPolyFace *> GetConnectedFacesFromVertex( IwPolyVertex *iwPolyVertex );
	IwTA<IwPolyFace *> GetCommonFacesBetweenElements( TOGLTransf *OGLTransf, TMeshElementInfo *element1, TMeshElementInfo *element2 );
	IwTA<IwPolyFace *> GetCommonFacesBetweenEdges( IwPolyEdge *iwEdge1, IwPolyEdge *iwEdge2 );
	IwPolyFace *GetCommonFaceBetweenVertexAndEdge( IwPolyVertex *iwVertex, IwPolyEdge *iwEdge );
	IwTA<IwPolyFace *> GetCommonFacesBetweenVertexs( IwPolyVertex *iwVertex1, IwPolyVertex *iwVertex2 );
	IwTA<IwPolyEdge *> GetCommonEdgesBetweenFaces( IwPolyFace *iwFace1, IwPolyFace *iwFace2 );
	IwTA<IwPolyVertex *> GetCommonVerticesBetweenFaces( IwPolyFace *iwFace1, IwPolyFace *iwFace2 );
	IwTA<IwPolyEdge *> GetAdjacentEdges( IwPolyEdge *iwEdge );
	void GetAdjacentFaces( IwPolyFace *iwFace, IwTA<IwPolyFace *> *faces, bool useSeams = false, bool onlybyedges = false );
	bool FindElement_Edge( IwTA<IwPolyEdge *> *liwPolyEdges, IwPolyEdge *iwPolyEdgeToFind, ULONG &ulIndex, IwPolyEdge *&iwPolyEdgeFounded );
	IwPolyEdge *GetEdgeFromFaceStartingAtVertex( IwPolyFace *iwPolyFace, IwPolyVertex *iwPolyVertex );
	bool AreEqual( IwPolyEdge *iwPolyEdge1, IwPolyEdge *iwPolyEdge2 );
	bool IsVertexFromEdge( IwPolyVertex *iwPolyVertex, IwPolyEdge *iwPolyEdge );
	bool IsVertexFromFace( IwPolyVertex *iwPolyVertex, IwPolyFace *iwPolyFace );
	bool IsEdgeFromFace( IwPolyEdge *iwPolyEdge, IwPolyFace *iwPolyFace, bool checkSymmetric );
	IwPolyVertex *IsPointAVertexFromEdge( T3DPoint point, IwPolyEdge *iwEdge, double tol = RES_GEOM );
	IwPolyEdge *GetEdgeFromVertices( IwPolyVertex *iVertexPos1, IwPolyVertex *iVertexPos2, bool forceGetVisibleEdge = true );
	IwPolyEdge *GetEdgeFromVertices( ULONG iVertexPos1, ULONG iVertexPos2, bool forceGetVisibleEdge = true );
	bool IsFaceIsolated( TOGLTransf *OGLTransf, int index );
	void GetIsolatedFaces( TOGLTransf *OGLTransf, int guestface, IwTA<IwPolyFace *> *faces, IwTA<IwPolyEdge *> *boundaryedges );
	IwTA<IwPolyFace *> ShorterCornerFaces( IwPolyVertex *v, IwPolyFace *lastFace, IwPolyFace *beforeFace, IwPolyEdge *eEnd, double &rArea );
	void SetOldValue( int value )
	{
		OldValue = value;
	}
	int GetOldValue( )
	{
		return OldValue;
	}

	// --
	// Borrado de elementos

  public:
	bool RemoveSelectedVertexs( TOGLTransf *OGLTransf, bool updateTopology = true );
	bool RemoveVertexs( TOGLTransf *OGLTransf, IwTA<IwPolyVertex *> *iwVertexsToRemove, bool updateTopology = true );
	bool RemoveVertex( TOGLTransf *OGLTransf, IwPolyVertex *iwVertex, bool updateTopology = true );
	bool RemoveSelectedEdges( TOGLTransf *OGLTransf, bool updateTopology = true );
	bool RemoveEdges( TOGLTransf *OGLTransf, IwTA<IwPolyEdge *> *iwEdgesToRemove, TAddedElements *addedElements = NULL, bool delSimetric = true, bool repair = true, bool updateTopology = true );
	bool RemoveEdge( TOGLTransf *OGLTransf, IwPolyEdge *iwEdge, TAddedElements *addedElements = NULL, bool delSimetric = true, bool repair = true, bool updateTopology = true );
	bool RemoveSelectedFaces( TOGLTransf *OGLTransf, bool updateTopology = true );
	bool RemoveFaces( TOGLTransf *OGLTransf, IwTA<IwPolyFace *> *iwFaces, bool updateTopology = true );
	bool RemoveFace( TOGLTransf *OGLTransf, IwPolyFace *iwFace, bool updateTopology = true );
	bool InvertFacesMeshBySelection( TOGLTransf *OGLTransf, TInteger_List *facesInverted, bool updateTopology = false );
	bool InvertFacesMeshBySelection( TOGLTransf *OGLTransf, int faceRef, TInteger_List *facesInverted = 0, bool updateTopology = false );
	bool InvertAllFacesMesh( TOGLTransf *OGLTransf, bool updateTopology = false );
	bool FacesToRemoveVertex( TOGLTransf *OGLTransf, IwPolyVertex *vertexToDelete, IwTA<IwPolyFace *> *faces, IwTA<IwTA<IwPolyFace *> > *facesR );
	bool FacesToReplaceVertex( TOGLTransf *OGLTransf, IwPolyVertex *vertexToDelete, IwPolyVertex *vertexToKeep, IwTA<IwPolyFace *> *faces, IwTA<IwTA<IwPolyFace *> > *facesR, bool borderFaces = false );
	void InitUserIndex1( bool vertexs = true, bool faces = true );
	void GetListsUserIndex1( TInteger_List *vertexsList, TInteger_List *facesList );
	void SetListsUserIndex1( TInteger_List *vertexsList, TInteger_List *facesList );
	void InitUserIndex2( bool vertexs = true, bool edges = true, bool faces = true );
	void GetListsUserIndex2( TInteger_List *vertexsList, TInteger_List *edgesList, TInteger_List *facesList );
	void SetListsUserIndex2( TInteger_List *vertexsList, TInteger_List *edgesList, TInteger_List *facesList );
	ULONG GetMaxEdgeUserLong2( );
	void InitUserLong2( ); // Solo se usa con aristas
	ULONG GetMaxEdgeUserIndex2( );
	void InitEdgeUserIndex2( ULONG limit = 0 );
	bool GetEdgesOrdered( IwTA<IwPolyEdge *> *iwEdges, IwTA<IwTA<IwPolyEdge *> > *iwEdgesOrdered );
	void InitPointExt( ); // Solo para vértices.

  protected:
	void RemoveUnnecessaryVertexs( TOGLTransf *OGLTransf, IwTA<IwPolyVertex *> *iwVertexs, double angleTolerance = 90.0, TAddedElements *addedElements = NULL, bool updateTopology = true );
	void RemoveUnnecessaryVertexsFromFace( TOGLTransf *OGLTransf, IwPolyFace *iwFace, IwTA<IwPolyVertex *> *iwVertexs = NULL, IwTA<IwPolyVertex *> *iwVertexsUnnecessary = NULL, double angleTolerance = 90.0, TAddedElements *addedElements = NULL, bool updateTopology = true );
	void FillHoles( IwTA<IwPolyVertex *> *iwVertexsHoles = NULL, TAddedElements *addedElements = NULL );
	void AddFaceAndEdgesToElements( IwPolyFace *iwFace, TAddedElements *elements, IwPolyVertex *iwVertex1 = 0, IwPolyVertex *iwVertex2 = 0 );
	void AddVertexToElements( IwPolyVertex *iwVertex, TAddedElements *elements );
	void RemoveFaceAndEdgesFromElements( IwPolyFace *iwFace, TAddedElements *elements );
	void AddEdgesAffectedFromVertex( IwPolyVertex *iwVertex, IwTA<int> *iwIndexes, IwTA<IwPolyVertex *> *iwStartVertexs, IwTA<IwPolyVertex *> *iwEndVertexs );
	void AddEdgesAffectedFromFace( IwPolyFace *iwFace, IwTA<int> *iwIndexes, IwTA<IwPolyVertex *> *iwStartVertexs, IwTA<IwPolyVertex *> *iwEndVertexs );
	void UpdateEdgesAffected( TAddedElements *addedElements, IwTA<int> *iwIndexes, IwTA<IwPolyVertex *> *iwStartVertexs, IwTA<IwPolyVertex *> *iwEndVertexs );
	bool GetFacesOrdered( IwTA<IwPolyFace *> *iwFaces, IwTA<IwTA<IwPolyFace *> > *iwFacesOrdered );
	bool OrderEdgesFace( IwTA<IwPolyEdge *> *iwEdgesFace, bool forceClose = true );
	bool GetOrderedEdgesNewFaceFromRemoveEdge( IwPolyEdge *iwEdge, IwTA<IwPolyEdge *> *iwEdgesNewFace );
	IwPolyEdge *GetEdgeBetweenFaces( IwPolyFace *iwFace1, IwPolyFace *iwFace2 );
	void UpdateTopology( TOGLTransf *OGLTransf );
	void UpdateDataSubdivision( TOGLTransf *OGLTransf );

	// --
	// Partición de aristas y caras

  public:
	void SplitSelectedEdges( TOGLTransf *OGLTransf, bool updateTopology = true );
	void SplitEdges( TOGLTransf *OGLTransf, IwTA<IwPolyEdge *> *iwEdgesToSplit, IwTA<T3DPoint> *points = NULL, TAddedElements *addedElements = NULL, bool splitSimetric = true, bool updateTopology = true );
	void SplitEdge( TOGLTransf *OGLTransf, int index, T3DPoint *point = NULL, TAddedElements *addedElements = NULL, bool splitSimetric = true, bool updateTopology = true );
	void SplitEdge( TOGLTransf *OGLTransf, IwPolyEdge *iwEdge, T3DPoint *point = NULL, TAddedElements *addedElements = NULL, bool splitSimetric = true, bool updateTopology = true );
	void SplitSelectedFaces( TOGLTransf *OGLTransf, double offset = 0, bool updateTopology = true );
	void SplitFaces( TOGLTransf *OGLTransf, IwTA<IwPolyFace *> *iwFaces, IwTA<T3DPoint> *points = NULL, IwTA<double> *offsets = NULL, TAddedElements *addedElements = NULL, bool updateTopology = true );
	void SplitFace( TOGLTransf *OGLTransf, int index, T3DPoint *point = NULL, double offset = 0.0, TAddedElements *addedElements = NULL, bool updateTopology = true );
	void SplitFace( TOGLTransf *OGLTransf, IwPolyFace *iwFace, T3DPoint *point = NULL, double offset = 0.0, TAddedElements *addedElements = NULL, bool updateTopology = true );
	void SplitFace( TOGLTransf *OGLTransf, IwPolyFace *iwFace, IwTA<T3DPoint> points, IwTA<ULONG> vertexs, TAddedElements *addedElements = NULL, bool updateTopology = true );
	void SplitFace( TOGLTransf *OGLTransf, IwPolyFace *iwFace, IwPolyVertex *iwVertex1, IwPolyVertex *iwVertex2, IwTA<T3DPoint> *points = NULL, TAddedElements *addedElements = NULL, bool updateTopology = true );
	void SplitFace( TOGLTransf *OGLTransf, IwPolyFace *iwFace, IwPolyVertex *iwVertex, IwPolyEdge *iwEdge, T3DPoint *point, IwTA<T3DPoint> *points = NULL, TAddedElements *addedElements = NULL, bool repairAdyacents = true, bool updateTopology = true );
	void SplitFace( TOGLTransf *OGLTransf, IwPolyFace *iwFace, IwPolyEdge *iwEdge1, T3DPoint *point1, IwPolyEdge *iwEdge2, T3DPoint *point2, IwTA<T3DPoint> *points = NULL, TAddedElements *addedElements = NULL, bool repairAdyacents = true, bool updateTopology = true );
	void SplitFace( TOGLTransf *OGLTransf, IwPolyFace *iwFace, IwPolyEdge *iwEdge, T3DPoint *point1, T3DPoint *point2, IwTA<T3DPoint> *points, TAddedElements *addedElements = NULL, bool repairAdyacents = true, bool updateTopology = true );
	void SplitFace( TOGLTransf *OGLTransf, IwPolyFace *iwFace, IwPolyEdge *iwEdge, IwPolyVertex *iwVertex, IwTA<IwPolyFace *> *facesToDelete, TAddedElements *addedElements = NULL, bool updateTopology = true );

	// Subdivisión de caras y aristas

  public:
	bool SubdivisionEdge( TOGLTransf *OGLTransf, int numCuts, bool nGons = true, int cornerType = 0 );

  private:
	bool SplitSubdivideEdge( TOGLTransf *OGLTransf, IwPolyFace *iwFace, IwPolyEdge *iwEdge, IwTA<T3DPoint> *newPoints, TAddedElements *addedElements = NULL, bool updateTopology = true );

	// Disolución de elementos. Se eliminan unificando las caras que se compartían

  public:
	bool CollapseVertexs( TOGLTransf *OGLTransf, IwPolyVertex *vertexStart, IwPolyVertex *vertexEnd );
	bool CanDisolveSelectedVertexs( );
	bool DisolveSelectedVertexs( TOGLTransf *OGLTransf, bool updateTopology = true );
	bool DisolveVertexs( TOGLTransf *OGLTransf, IwTA<IwPolyVertex *> *iwVertexsToDisolve, bool updateTopology = true );
	bool DisolveVertex( TOGLTransf *OGLTransf, IwPolyVertex *iwVertex, bool updateTopology = true );
	bool DisolveSelectedEdges( TOGLTransf *OGLTransf, double angleTolerance = 90.0, bool updateTopology = true );
	bool DisolveEdges( TOGLTransf *OGLTransf, IwTA<IwPolyEdge *> *iwEdgesToDisolve, double angleTolerance = 90.0, TAddedElements *addedElements = NULL, bool updateTopology = true );
	bool DisolveEdge( TOGLTransf *OGLTransf, IwPolyEdge *iwEdge, double angleTolerance = 90.0, TAddedElements *addedElements = NULL, bool updateLists = true );
	bool DisolveSelectedFaces( TOGLTransf *OGLTransf, double angleTolerance = 90.0, bool updateTopology = true );
	bool DisolveFaces( TOGLTransf *OGLTransf, IwTA<IwPolyFace *> *iwFacesToDisolve, double angleTolerance = 90.0, TAddedElements *addedElements = NULL, bool updateTopology = true );

	// Offset

  protected:
	IwPolyEdge *GetNextCWPolyEdge( IwPolyVertex *vertex, IwPolyEdge *pEdge );
	IwPolyEdge *GetNextCCWPolyEdge( IwPolyVertex *vertex, IwPolyEdge *pEdge );

  public:
	bool GetOffsetFromRing( IwTA<IwPolyEdge *> *edges, double lenght, bool clockWise, IwTA<IwTA<TMeshElementInfo> > &elements, bool onlyForRedraw, bool force, IwTA<IwPolyEdge *> &edgesForDraw );
	bool AreAdjacentEdges( IwPolyEdge *edge1, IwPolyEdge *edge2, bool &atStart );

  public:
	// --
	// Funciones genéricas
	bool IsTopologyDirty( );
	bool IsDataSubdivisionDirty( );
	void SetTopologyDirty( bool dirty );
	void SetDataSubdivisionDirty( TOGLTransf *OGLTransf, bool dirty );
	void SetDirtyFaceSelection( bool dirty )
	{
		DirtyFaceSel = dirty;
	}
	void SetDirtyEdgeSelection( bool dirty )
	{
		DirtyEdgeSel = dirty;
	}
	TColor GetColorForFace( );
	TColor GetColorForEdge( );
	TColor GetColorForVertex( );
	TColor GetColorForSelection( );
	TColor GetColorForSeam( );
	void GetSelectedInteger_List( TOGLTransf *OGLTransf, TInteger_List *list, ElementType type );
	void SetSelectedInteger_List( TOGLTransf *OGLTransf, TInteger_List *list, ElementType type, bool unSelectPrev = true );
	int GetSeamListIndex( int indexVertexSeam );
	void AlignList( TOGLTransf *OGLTransf, ElementType eType, TNPlane plane, TInteger_List *elements, int refElement, int *nElem, int **idElem, T3DPoint **points, bool updateOGLList = true );

  protected:
	TCadEntity *RefEnt;
	IwPolyBrep *PBrep;
	bool PBrepFaceTriangulation;
	intdouble *SelectedV; // i -> selección; d -> peso de la selección
	intdouble *SelectedF; // i -> selección; d -> peso de la selección
	int *SelectedE;
	IwTA<IwPolyFace *> PBrepFaces;
	IwTA<IwPolyEdge *> PBrepEdges;
	IwTA<IwPolyVertex *> PBrepVertexs;
	vector<int3> PBrepPolListRelF;
	TSubdivision *Subdivision;

	IwTA<IwPolyEdge *> SeamEdges;

	int CompareMask;
	double RepairTol; // Ahora esta variable solo se utiliza para aplicar Sew (>0.0) o no aplicaralo (en caso contrario)

	TranslateVertexInfo MoveVertUser; // Desplazamientos de vértices en distintas direcciones

	TColor AuxEntityColor[ 5 ];
	bool DirtyFaceSel, DirtyEdgeSel;
	int AnyClosedRingSelected; // 0x001: aristas, 0x010: caras
	int OldValue;			   // Usado para almacenar temporales
};

#endif

