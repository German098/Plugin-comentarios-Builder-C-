#ifndef T3DDATAH
#define T3DDATAH

//------------------------------------------------------------------------------

#include <vector>
#include "_entities.h"
#include "_gpoint3d.h"
using namespace InesMath;
//------------------------------------------------------------------------------

/**
 *  Clase T3DPolygon
 *	Clase utilizada para la normalizacion de hormas en forma3D, utiliza T3DPoint
 *	para la normalizacion que internamente contiene doubles en lugar de floats
 */
class TOGLTransf;
class TOGLPolygon;
class TCadIBSpline;
class TCadPolyline;
class TOGLPolygonList;
class TCadTensorSurface;
class TCadIBSpline;

class T3DPolygon
{
  public:
	T3DPolygon( int d = 1000 ); // DEFAULT_DITEMS_LIST
	T3DPolygon( T3DPolygon *Pol );
	~T3DPolygon( );

	void Clear( bool = false );
	void GrowItems( long d = 0 );
	void AdjustSize( long dB = 0 );

	void Set( T3DPolygon *Pol );
	void Set( TOGLPolygon *Pol );
	void Append( T3DPolygon *Pol );
	void Append( TOGLPolygon *Pol );
	void SetVertexs( int np, T3DPoint *pts );
	T3DPoint *GetPoints( int &np );

	void AddItem( T3DPoint *p, int = -1 );
	void AddItemTol( T3DPoint *p, double tolerance );
	void SetItem( int ind, T3DPoint *p );
	void DeleteItem( int ind );
	T3DPoint *GetItem( int ind );
	T3DPoint *GetFirstItem( );
	T3DPoint *GetLastItem( );
	bool GetVertexFromPct( double pct, double per, T3DPoint *pt );
	void SetFirstAt( int index, bool checkclose = false );

	int Count( )
	{
		return numItems;
	}

	bool CalcBoundRect( T3DRect &, TNMatrix *mat = 0 );
	void ApplyMatrix( TNMatrix *matrix );
	bool GetYZMatrix( TNMatrix &matrix, TNMatrix &imatrix );

	bool GetRefineList( T3DPolygon &out, int first, int last, double distance );
	bool GetRefineListYZ( TOGLTransf *OGLTransf, T3DPolygon &out, int nadd, bool onlySegments );
	bool GetRefineListYZInBiggerHoles( TOGLTransf *OGLTransf, T3DPolygon &out, int nHoles, bool onlySegments );
	void GetMachiningPointsYZ( T3DPolygon &out, int pv, double angle, double radio, double tol = RES_GEOM, bool center = false );
	void GetMachiningPoints( T3DPolygon &out, int pv, double radio, double tol = RES_GEOM, bool center = false );
	bool GetMinMaxValue( int axisMinMax, int &minIndex, double &minValue, int &maxIndex, double &maxValue, int axisLimit = -1, double limit = MAXDOUBLE );
	bool GetReduceListByDistance( T3DPolygon &out, double distMin );
	int NormalizeYZ( TOGLTransf *OGLTransf, T3DPolygon &out, int nSecs, int *npointsSec, int npointsRef, double &angle, double &radius, bool renormalize, bool digitPoints = false );
	int NormalizeYZNew( TOGLTransf *OGLTransf, T3DPolygon &out, int *npointsSec, int npointsRef, double &angle, double &radius, T3DPoint *pCenterIn, bool digitPoints = false );
	bool GetNEquidistantPoints( int n, T3DPolygon *out );
	// isPolyline sirve para si queremos que la ibspline sea una curva (sin corners) o una poligono (todo corners)
	bool GetNEquidistantPointsSISL( TOGLTransf *OGLTransf, int n, bool isPolyline, bool cornerExtremes, T3DPolygon *out );
	int FindNearestPoint( T3DPoint *p );
	int FindNearestPointYZ( T3DPoint *p );
	int GetNearestPointContYZ( T3DPoint *P, T3DPoint &Point );
	bool GetGeoEquidistPoints( T3DPolygon &out, int nSecs, int *indexesSec, int *npointsSec );

	void CompletePoints( double mindist, double maxdist = -1.0 );

	T3DPoint GravityCenter( );
	bool IsClockwise( TNPlane Plane = plXY );
	void Invert( );
	double Perimeter( bool closed = false );
	double PerimeterSegment( int ind1, int ind2 );
	void IntersectAt( int from, double d, T3DPoint &res );
	void Move( T3DPoint pt );
	void Open( );
	void Close( );

	void GetNoLacesList( T3DPolygon &out2 );
	void GetNoLacesList2( T3DPolygon &out );

	bool IsInPlane( T3DPlane &Plane, double prec = RES_GEOM );
	void MirrorY0( );

	void Offset( double d );

	// TRIANGLES
	bool IntersectTriangle( T3DPlane &plane, T3DPolygon &list );

	virtual void ConvertToIBSpline( TOGLTransf *OGLTransf, TCadIBSpline *curve, bool cornerExtremes = false );
	void ConvertToPolyline( TOGLTransf *OGLTransf, TCadPolyline *poly );
	bool IsCloseExt( bool checkclose = false, bool *close = 0, double *limits = 0 );
	void ToPlane( T3DPlane plane, T3DVector dir );

	double GetMaxDistSqrtBetweenConsecutivePoints( );

  public:
	T3DPoint *Item;
	long dItems, numItems, maxItems;
};

/**
 *  Clase T3DPolygonList
 *	Clase utilizada para la normalizacion de hormas en forma3D, utiliza
 *	T3DPolygon
 */
class T3DPolygonList
{
  public:
	T3DPolygonList( long di = 1000 ); // DEFAULT_DITEMS_LIST
	~T3DPolygonList( );

	void GrowItems( long d = 0 );
	void AdjustSize( long dI = 0 );

	void Set( T3DPolygonList *E );
	void Set( TOGLPolygonList *E );

	void Append( T3DPolygonList *E );

	void Add( T3DPolygon *s );
	void InvertList( );
	void AddAtFirst( T3DPolygon *p );
	void DeleteItem( int ind );
	T3DPolygon *GetItem( long a );
	T3DPolygon *GetFirstItem( );
	T3DPolygon *GetLastItem( );
	T3DPoint *GetPoints( int &np );

	T3DPoint GravityCenter( );
	T3DPoint GravityCenter( double inc );

	void Clear( bool adjustsize = false );
	long Count( )
	{
		return numItems;
	}

	bool CalcBoundRect( T3DRect & );
	void GetMachiningPoints( T3DPolygon &out, int pv, double radio, double tol = RES_GEOM );

	void TransferAll( T3DPolygonList *origin );
	void ApplyMatrix( TNMatrix *matrix );

	void IntersectSectionsWithPlaneX( T3DPoint &p, double x, int v, int vmin, int vmax );
	bool IntersectTriangles( T3DPlane &Plane, T3DPolygonList *List );
	void GetNoLacesList( T3DPolygonList &out );

	bool SectionsToTriangles( T3DPolygonList *out, int step = 1 );
	TCadTensorSurface *SectionsToTensor( int closeextremes = CLOSE_NONE, int ustep = 1, int vstep = 1 );
	void GetIntersectionsSectionsCurve( TOGLTransf *OGLTransf, int uini, int ufin, TCadIBSpline *centersToNormCurve, T3DPolygon *centersToNormOut );
	void CreatePolygonCenters( TOGLTransf *OGLTransf, int uini, int ufin, T3DPolygon *centersToNormOut );
	int Normalize( TOGLTransf *OGLTransf, T3DPolygonList &out, int pv, int npointsRef, double angle, double radius, bool force, int uini, int ufin, T3DPolygon *centersToNorm, bool digitPoints = false );
	void NormalizeStep1( TOGLTransf *OGLTransf, bool newNormalization, T3DPolygonList *out, int pv, int npointsRef, double angle, double radius, int uini, int ufin, T3DPolygon *centersToNorm );
	void NormalizeStep1Sec( TOGLTransf *OGLTransf, bool newNormalization, T3DPolygonList *out, int pv, int npointsRef, double angle, double radius, int uini, int ufin, int startIndex, int endIndex, T3DPolygon *centersToNorm );
	bool NormalizeStep2( TOGLTransf *OGLTransf, bool newNormalization, T3DPolygonList *out, int pv, int npointsRef, double angle, double radius, int uini, int ufin, T3DPolygon *centersToNorm, bool digitPoints = false );
	void NormalizeStep2Sec( TOGLTransf *OGLTransf, bool newNormalization, T3DPolygonList *out, int pv, int npointsRef, double angle, double radius, int uini, int ufin, bool &Res, int startIndex, int endIndex, T3DPolygon *centersToNorm, bool digitPoints = false );

	void CompletePoints( double mindist, double maxdist = -1.0 );

	void MirrorY0( );

	// TRIANGLES
	bool ReduceArea( double areaCorte );
	void SortByX( );
	void ToPlane( T3DPlane plane, T3DVector dir );

	//------------------------------------------------------------------------------

  protected:
	T3DPolygon **Item;
	long dItems, numItems, maxItems;
};

//------------------------------------------------------------------------------

class T3DPolygonListList
{
  public:
	T3DPolygonListList( );
	~T3DPolygonListList( );

	void Clear( );
	int Count( );
	void Grow( int d );

	void Set( T3DPolygonListList * );
	void Init( int nitems, int curitem );

	void AddItem( T3DPolygonList *s );
	void SetItem( int ind, T3DPolygonList *s );
	void InsertItem( int ind, T3DPolygonList *s );
	void DelItem( int ind );
	T3DPolygonList *GetItem( int ind );
	void ReplaceItems( int ind1, int ind2 );

	virtual int GetCurrentIndex( );
	virtual void SetCurrentIndex( int );
	virtual T3DPolygonList *GetCurrentItem( );

  public:
	int numItems, maxItems, curItem;
	T3DPolygonList *Item;
};

#endif

