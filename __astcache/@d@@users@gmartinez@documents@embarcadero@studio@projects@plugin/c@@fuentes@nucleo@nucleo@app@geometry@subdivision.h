//---------------------------------------------------------------------------

#ifndef subdivisionH
#define subdivisionH
//---------------------------------------------------------------------------

#include <glut.h>
#include "PolygonMesh.h"
#include "SubdSurface.h"
#include "SubdLimitVertexTessellator.h"
#include "IwTArray.h"

class TOGLPoint;
class TOGLPolygon;
class TOGLPolygonList;
class TCadMesh;
class TSubdivisionData;
class IwPolyBrep;
class IwPolyEdge;
class IwPolyVertex;

//------------------------------------------------------------------------------
// TSubdivision
//------------------------------------------------------------------------------

class TSubdivision
{
  public:
	TSubdivision( IwPolyBrep *pBrep, int level = 2 );
	~TSubdivision( );

	void Clear( );

	void SetLevel( int level )
	{
		Level = level;
	}
	int GetLevel( )
	{
		return Level;
	}

	void Apply( );
	bool Update( bool recalcTopology = false, bool rebuildFromLevel0 = false );
	// Esta funcion no se usa pq no agiliza el calculo, se deja por si fuera interesante saber el ámbito de los vértices. IMP: Hay algo que falla a veces y hace que se cuelgue
	bool Update( IwTA<IwPolyVertex *> *vertexList, bool recalcTopology );

	void GetOGLList( TOGLPolygonList *outOGLList, TOGLPolygon *polvertexs, TOGLPolygon *poledges, TOGLPolygon *polfaces, bool forceNormals, TSubdivisionData *subdivisiondata, bool getbaseedge = false );

	bool GetFinestVertexFromVertex( IwPolyVertex *vertex, TOGLPoint *pt );
	bool GetFinestEdgesFromEdge( IwPolyEdge *edge, TOGLPolygon *oglPol );
	bool GetFinestFacesFromFace( IwPolyFace *face, TOGLPolygonList *oglPolList );

  protected:
	void CalculatePolygonMeshFromPBrep( );
	void MarkCreaseEdgesAtSubdivision( bool reset );

	void GetPBrepEdgeFromSudEdge( SubdEdge *edgeptr, IwPolyEdge *&edge );

	bool GetFinestVertexFromVertex( int index, SubdVertex &vertex );
	bool GetFinestEdgesFromEdge( IwPolyEdge *edge, IwTA<SubdEdge *> *edgesSubd );
	bool GetFinestFacesFromFace( IwPolyFace *face, IwTA<SubdFacet *> *facesSubd );

	int GetEdgeSub0FromPBrep( int index );
	BaseEdge *GetBaseEdgeFromPBrep( int index );
	BaseEdge *GetBaseEdgeFromPBrep( IwPolyEdge *edge );
	void GetFinerEdgeFromSubd( int level, SubdEdge *edge, IwTA<SubdEdge *> *edges );
	void GetFinerFaceFromSubd( int level, SubdFacet *face, IwTA<SubdFacet *> *faces );

	bool GetVertexLevelFromIndex( int index, int level, SubdVertex &vertex );
	SubdVertex GetFinerVertexFromVertex( SubdVertex &vertex );

	Point3 GetCoarseVertexValueFromVertex( SubdVertex &vertex );

	void FillSubdOnlyInfluenced2( SubdVertex &vertex, vector<SubdVertex *> &vertexListParam );

	void FillSubdOnlyInfluenced( SubdVertex &vertex, SubdVertexList &vertexListParam, bool start );
	void CalcSubdPositiononList( SubdVertexList &vertexListParam );

	void FillSubdFinestVertexs( SubdVertex &vertex, SubdVertexList &vertexListParam );
	void FillSubdFinestVertexs( SubdFacet &facet, SubdVertexList &vertexListParam );

	void FillSubdFacesAtLevel0( SubdVertex &vertex, IwTA<SubdFacet> &facesList );
	void GetNextFacesLevel( IwTA<SubdFacet> &facesListOrg, IwTA<SubdFacet> &facesList );

  protected:
	IwPolyBrep *CagePBrep;
	int Level;

	PolygonMesh *SubdMesh;
	SubdSurface *SubdCage;
	SubdLimitVertexTessellator *CreaseTess;

	vector<TOGLPoint> tempdragv, tempdragfacesv;
	vector<GLint> tempdragvi, tempdragvn, tempdragfacesvi, tempdragfacesvn;

	bool debug;
};

#endif

