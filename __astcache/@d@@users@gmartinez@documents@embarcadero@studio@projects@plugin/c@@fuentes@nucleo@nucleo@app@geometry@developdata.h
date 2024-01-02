#ifndef DEVELOPDATAH
#define DEVELOPDATAH

#include "ogldata.h"
#include "functions.h"

#define DEV_DM_BASIC			0 // NATURAL

#define DEV_LF_MIN				0.05
#define DEV_LF_MAX				0.35
#define DEV_LF_DEFAULT			DEV_LF_MAX

#define DEV_TLF_DEFAULT			0.0 // (0..1)
#define DEV_TAF_DEFAULT			0.0 // (0..1)

#define DEV_WIM_PRIORITY_TOP	0
#define DEV_WIM_PRIORITY_CURVE	1
#define DEV_WIM_PRIORITY_NONE	2
#define DEV_WIM_PRIORITY_VVALUE 3

#define DEV_WT_MIN				0
#define DEV_WT_MED				1
#define DEV_WT_MAX				2

#define DEV_WEIGHT_MIN			0.0001
#define DEV_WEIGHT_MED			0.01
#define DEV_WEIGHT_MAX			1.0

#define DEV_FIXWEIGHT_FACTOR	1000000.0

#define DEV_EDGEWIDTH			6.0

#define MAXVERTEXS_DEVELOP		2500

//------------------------------------------------------------------------------

class TCadGroup;
class TCadEntity;
class TCadSurface;
class TOGLTransf;

//------------------------------------------------------------------------------

class TDevelopData
{
  public:
	TDevelopData( );
	~TDevelopData( );
	void Set( TDevelopData *D );

  public:
	int DevelopMode;	// DEVMODE_SV, DEVMODE_GV
	float LengthFactor; // ( DEV_LF_MAX ... DEV_LF_MIN )
	double InitsUV[ 2 ];
	bool InvertUV[ 2 ];

	int DevelopType; // DEVTYPE_ALL, DEVTYPE_WEIGHTS, DEVTYPE_FIXWEIGHTS
	double LimitsUV[ 4 ];
	int Res;				   // positivo aumenta la definicion, negativo la reduce. 1 y -1 neutro, 0 no permitido
	bool Reduce;			   // positivo reduce la superficie a aplanar en base a la longitud en U y en V
	float WeightValues[ 3 ];   // Indices: DEV_WT_MIN, DEV_WT_MED, DEV_WT_MAX
	TInteger_List WeightTypes; // Valores: DEV_WT_MIN, DEV_WT_MED, DEV_WT_MAX

	double TempOffset3D; // No se guarda, para aplicar offset 3D a la superficie
};

//------------------------------------------------------------------------------

class TTransformingData
{
  public:
	TTransformingData( );
	virtual ~TTransformingData( );

	virtual void Set( TTransformingData * );
	virtual void SetBasic( TTransformingData * );
	virtual TTransformingData *CreateCopy( );
	virtual TTransformingData *CreateCopyBasic( );

	virtual void InitTransfSurfaces( );

	virtual void Clear( );
	virtual void ClearBasic( );
	virtual void ClearTransfSurfaces( );
	virtual void ClearTransfSurfacesEdges( );
	virtual void ClearAllTransfs( );

	virtual bool GetSymAxisPoints( TLPoint *pt1, TLPoint *pt2 )
	{
		return false;
	}

  public:
	wchar_t Name[ 60 ];

	// Datos basicos. Si varian, debe recalcularse el desarrollo inicial. ( DEV_DIRTY_CALC )
	// Se almacenan aqui para permitir que difieran de unas transformaciones a otras.
	int Method;
	double Offset; // Varia la superficie geometrica 3D, y por tanto, el desarrollo inicial
	//------------------------------------------

	TLPoint RefPoint[ 3 ];
	bool FirstPtAtRight;

	TLPoint EndTranslation; // Traslacion geometrica (x,y) final
	bool EndInvertedY;		// Invertir el signo de la y al final.

	bool IsTransfDevSurfsDirty;
	TCadGroup *TransfDevelopSurfaces;

	bool IsTransfDevSurfsEdgesDirty;
	TOGLPolygonList TransfDevelopSurfacesEdges;
};

//------------------------------------------------------------------------------

class TTransformingDataList
{
	friend class TImpExp_XML;

  public:
	TTransformingDataList( );
	virtual ~TTransformingDataList( );

	virtual void Set( TTransformingDataList *list );
	virtual void SetBasic( TTransformingDataList *E );
	virtual void Clear( int items = 10 );

	virtual void AddItem( TTransformingData *td );
	virtual void SetItem( int ind, TTransformingData *td );
	virtual void DelItem( int ind );
	virtual void ReplaceItems( int ind1, int ind2 );
	virtual TTransformingData *GetItem( int ind );

	virtual int Count( );
	virtual void Grow( int d );

	virtual bool IsNameUsed( wchar_t * );

	virtual int GetCurrentIndex( );
	virtual bool SetCurrentIndex( int );
	virtual TTransformingData *GetCurrentItem( );
	virtual void SetCurrentItem( TTransformingData * );

  protected:
	int numItems, maxItems, curItem;
	TTransformingData **Item;
};

//------------------------------------------------------------------------------
// TDevelopList

class TDevelopList
{
	friend class TImpExp_XML;

  public:
	TDevelopList( );
	virtual ~TDevelopList( );

	virtual void Set( TDevelopList *E );
	virtual void SetBasic( TDevelopList *E );
	virtual TDevelopList *CreateCopy( );
	virtual TDevelopList *CreateCopyBasic( );

	virtual void AddItem( TDevelopData *s, TOGLRenderData *r );
	virtual void SetItem( int ind, TDevelopData *s, TOGLRenderData *r );
	virtual void DelItem( int ind );
	virtual TDevelopData *GetItem( int ind );

	virtual TOGLRenderData *GetOGLRenderData( int ind );
	virtual void SetOGLRenderData( int ind, TOGLRenderData * );
	virtual void SetOGLDisplayData( TOGLDisplayData * );
	virtual void SetOGLDisplayDataMode( int mode );

	virtual void Clear( );
	virtual void ClearSurfaces( );
	virtual void ClearTransfSurfaces( );

	virtual void InitTransformingData( );
	virtual TTransformingData *CreateTransformingData( );
	virtual TTransformingData *GetTransformingData( int ind = -1 );
	virtual void SetTransformingData( TCadEntity *surfortrim, TTransformingData *, int ind = -1, bool checkdevdata = true );
	virtual TTransformingDataList *GetTransformingDataList( );

	virtual int GetCurrentDevelopIndex( );
	virtual int CountDevelops( );

	virtual int GetDevelopIndexForSymmetries( );
	virtual void SetDevelopIndexForSymmetries( int devindex );
	virtual bool IsDevelopValidForSymmetries( int index );

	virtual bool GetFixInitialSurfaces( );
	virtual void SetFixInitialSurfaces( bool value );

	virtual TCadGroup *GetInitialSurfaces( );
	virtual TCadGroup *GetTransfDevSurfs( int index = -1 );
	virtual TOGLPolygonList *GetTransfDevSurfsEdges( int index = -1 );

	virtual void AddSurface( TCadSurface *s, float **error );
	virtual void SetSurface( int i, TCadSurface *s, float **error );

	virtual void InitListToTexture( TOGLTransf *OGLTransf, TCadSurface *surf, TCadEntity *entity, double *limitsUV = 0, bool updaterefpoints = true, bool reducesurf = true, bool checkdevdata = true );

	virtual TOGLErrorData *GetOGLErrorData( );
	virtual void SetOGLErrorData( TOGLErrorData * );
	virtual void SetError( int i, TCadSurface *s, float **error );
	virtual void ClearErrors( );
	virtual void ClearColors( );
	virtual void AssignColors( );
	virtual bool HasColors( );

	virtual bool GetActiveColors( );
	virtual void SetActiveColors( bool active );

	virtual void TransformingSurfaces( TOGLTransf *, TCadSurface *, int devindex );
	virtual void TransformingSurfacesEdges( TOGLTransf *OGLTransf, TCadSurface *, int devindex );

	virtual int CountSurfsInDevelop( );
	virtual int CountInitialSurfaces( );
	virtual int CountTransfSurfaces( int index = -1 );

	virtual void Grow( int d );

  protected:
	int numItems, maxItems;
	TDevelopData *Item;
	TOGLRenderData *OGLRenderData;
	TOGLPolygonList Errors;
	TOGLErrorData OGLErrorData;
	int DevelopIndexForSymmetries;

	bool FixInitialSurfaces;
	TCadGroup *InitialSurfaces;
	TTransformingDataList TransformingDataList;
};

//------------------------------------------------------------------------------

#endif

