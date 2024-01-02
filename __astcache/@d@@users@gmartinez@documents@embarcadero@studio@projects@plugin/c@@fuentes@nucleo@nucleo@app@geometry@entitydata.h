#ifndef ENTITYDATAH
#define ENTITYDATAH

#include <values.h>
#include <vector>

#include <IniFiles.hpp>
#include "IwTArray.h"

#include "_layers.h"
#include "functions.h"

//------------------------------------------------------------------------------

class TShapeInfo
{
  public:
	int NumVertexs, UDim, VDim;
	float Area, Perimeter;
	T3DPoint Size;

  public:
	TShapeInfo( )
	{
		NumVertexs = 0;
		Area = 0.0;
		Perimeter = 0.0;
		Size = T3DPoint( 0, 0, 0 );
		UDim = 0;
		VDim = 0;
	}
	void Set( TShapeInfo *S )
	{
		NumVertexs = S->NumVertexs;
		Area = S->Area;
		Perimeter = S->Perimeter;
		Size = S->Size;
		UDim = S->UDim;
		VDim = S->VDim;
	}
};

//------------------------------------------------------------------------------

#define RT_UP_NONE				   ""
#define RT_UP_PARAMENTITIES		   "PARAMENTITIES"
#define RT_UP_BASEENTITIES		   "BASEENTITIES"
#define RT_UP_DEPMESHES			   "DEPMESHES"
#define RT_UP_BASESHAPES		   "BASESHAPES"
#define RT_UP_DEPSHAPES			   "DEPSHAPES"
#define RT_UP_TRIMCURVES		   "TRIMCURVES"
#define RT_UP_TESSCURVES		   "TESSCURVES"
#define RT_UP_LOFTCURVES		   "LOFTCURVES"
#define RT_UP_GORDONSECTIONS	   "GORDONSECTIONS"
#define RT_UP_GORDONPROFILES	   "GORDONPROFILES"
#define RT_UP_GEOMSURFACES		   "GEOMSURFACES"
#define RT_UP_DEPSURFACES		   "DEPSURFACES"
#define RT_UP_TRIMSURFACES		   "TRIMSURFACES"
#define RT_UP_TESSPOLYGONS		   "TESSPOLYGONS"
#define RT_UP_POINTRELATEDSHAPES   "POINTRELATEDSHAPES"
#define RT_UP_RELATEDENTITIES	   "RELATEDENTITIES"

#define ToEnvelope_BBox( E )	   ( dynamic_cast<TEnvelope_BBox *>( E ) )
#define ToEnvelope_Normalized( E ) ( dynamic_cast<TEnvelope_Normalized *>( E ) )
#define ToEnvelope_PolyCube( E )   ( dynamic_cast<TEnvelope_PolyCube *>( E ) )
#define ToEnvelope_Regular( E )	   ( dynamic_cast<TEnvelope_Regular *>( E ) )

class TPointMarker;
class TLineMarker;
class TIntersectDataList;
class TCadEntity;
class TCadShape;
class TCadDepShape;
class TCadPoint;
class TCadRect;
class TCadTessPolygon;
class TMachine2D;
class TMachine2DList;
class TTool2DList;
class TFormEntityData;
class TReportObjectFormat;
class TriangulateDelaunay;
class TAdvancedRectType;
class TDeformer;

//------------------------------------------------------------------------------

class TRelationData
{
  public:
	TRelationData( )
	{
		Clear( );
	}

	void Clear( )
	{
		IDOrg = IDDst = -1;
		EntOrg = EntDst = 0;
		Type = UnicodeString( "" );
		GroupIndex = -1;
	}

  public:
	int IDOrg;			// Identificador de la entidad a ser referenciada.
	TCadEntity *EntOrg; // Direccion de la entidad origen (puede ser un grupo o no).
	int IDDst;			// Identificador de la entidad a ser referenciada.
	TCadEntity *EntDst; // Direccion de la entidad destino (hasta despues de la lectura no sera rellenada).
	UnicodeString Type; // Nombre de la variable a reasignar el puntero.
	int GroupIndex;		// Si la entidad destino se va a anyadir a un grupo, indica la posicion
};

//------------------------------------------------------------------------------

class TDeformerRelationData
{
  public:
	TDeformerRelationData( )
	{
		Clear( );
	}

	void Clear( )
	{
		Deformer = 0;
		ID = -1;
		Type = UnicodeString( "" );
	}

  public:
	TDeformer *Deformer;
	int ID;
	UnicodeString Type;
};

//------------------------------------------------------------------------------

class TMeasureData
{
  public:
	TMeasureData( );
	~TMeasureData( );

	virtual void Set( TMeasureData *data );
	virtual void Set( TReportObjectFormat *rof );

	virtual void ApplyMatrix( TOGLTransf *, TNMatrix *matrix );

  public:
	int MeasureType; // Tipo de medida que representa (distancia, perimetro, area, etc.)

	// Variables para calculo de la lista
	TNPlane ProjectionPlane;
	TNAxis ProjectionAxis;

	// Variables para dibujado de la lista de la medida
	TNPlane DrawPlane;
	bool ProjectOnDrawAxis;
	int DrawPlanePosType;
	float DrawPlaneDist;
	int DrawDirectionType;
	float DrawDirectionDist;

	// Angulos
	float DrawAngleDist;
	T3DPoint AngleVertex;

	// Variables para las opciones de dibujado de la medida
	int DrawArrows;
	bool DrawArrowsRaster;
	bool DrawLineRaster;
	float ArrowRadius;
	float ArrowHeight;
	float LineWidth;
	int DrawAuxLines;
	bool DrawAuxLinesAsStipple;
	int DrawControlPoints;
	bool DrawFilledSection;

	// Variables para gestionar el texto de la medida
	bool DrawText;
	bool DrawTextRaster;
	UnicodeString Text;
	float DrawTextAngle;
	float DrawTextDist;
	LOGFONT DrawTextFont;
	void *DrawTextFont2;

	// Variables para la clase TFoot
	UnicodeString code;
	int id;

	TOGLPolygonList StripList;

	// Variable para copiar formato
	TOGLMaterial OGLMainMat;

	// DataSheet
	bool DataSheetPageBreak;
};

//------------------------------------------------------------------------------
//  TRectFormatData
//------------------------------------------------------------------------------

class TRectFormatData
{
  public:
	TRectFormatData( );
	TRectFormatData( double bWidth );
	~TRectFormatData( );

	virtual void Set( TRectFormatData *data );
	virtual void Set( TReportObjectFormat *rof );

	void Write( UnicodeString str, TMemIniFile *_local_file = 0, UnicodeString file = EmptyStr, TCadRect *rect = 0, int *index = 0, UnicodeString *tag = 0 );
	void Read( UnicodeString str, TMemIniFile *_local_file = 0, UnicodeString file = EmptyStr, TCadRect *rect = 0, int *index = 0, UnicodeString *tag = 0, UnicodeString *imagename = 0 );

	bool IsRightRealAlign( )
	{
		return ( ImageRealAlign == ALIGNTYPE_TOPR || ImageRealAlign == ALIGNTYPE_MIDR || ImageRealAlign == ALIGNTYPE_BOTR );
	}
	bool IsLeftRealAlign( )
	{
		return ( ImageRealAlign == ALIGNTYPE_TOPL || ImageRealAlign == ALIGNTYPE_MIDL || ImageRealAlign == ALIGNTYPE_BOTL );
	}
	bool IsCenterRealAlign( )
	{
		return ( ImageRealAlign == ALIGNTYPE_TOPM || ImageRealAlign == ALIGNTYPE_MIDM || ImageRealAlign == ALIGNTYPE_BOTM );
	}
	bool IsTopRealAlign( )
	{
		return ( ImageRealAlign == ALIGNTYPE_TOPR || ImageRealAlign == ALIGNTYPE_TOPM || ImageRealAlign == ALIGNTYPE_TOPL );
	}
	bool IsMiddleRealAlign( )
	{
		return ( ImageRealAlign == ALIGNTYPE_MIDR || ImageRealAlign == ALIGNTYPE_MIDM || ImageRealAlign == ALIGNTYPE_MIDL );
	}
	bool IsBottomRealAlign( )
	{
		return ( ImageRealAlign == ALIGNTYPE_BOTR || ImageRealAlign == ALIGNTYPE_BOTM || ImageRealAlign == ALIGNTYPE_BOTL );
	}

	bool IsHorizontalOrientationText( )
	{
		return ( OrientationText == ORIENTATIONTEXT_NONE );
	}
	bool IsVerticalOrientationText( )
	{
		return ( OrientationText == ORIENTATIONTEXT_90 );
	}
	bool IsInvertHorizontalOrientationText( )
	{
		return ( OrientationText == ORIENTATIONTEXT_180 );
	}
	bool IsInvertVerticalOrientationText( )
	{
		return ( OrientationText == ORIENTATIONTEXT_270 );
	}

	LOGFONT LogFont;
	TLRect Margins;

	bool IsRealSize;
	bool IsFillText;
	bool IsSimpleText;
	bool IsUnderline;
	bool AdjustBoxToText;
	bool IsSelectableByArea;
	bool IsTransparent;
	bool DrawBorderRaster;
	bool ColumnText;
	double BorderWidth;
	int HasBorder;
	int BoxAlign;
	int ImageAlign;
	int ImageRealAlign;
	int OrientationText;
	bool FillAsMaterial;
	TOGLMaterial OGLMainMat;
	TOGLMaterial OGLTextMat;
};

//------------------------------------------------------------------------------
//  TRectDataSheetData
//------------------------------------------------------------------------------
class TRectDataSheetData
{
  public:
	TRectDataSheetData( );
	~TRectDataSheetData( );
	void Clear( );

	void Set( TRectDataSheetData *data );

	bool IsDataSheetRect( )
	{
		return DataSheetRect;
	}
	void SetDataSheetRect( bool ds )
	{
		DataSheetRect = ds;
	}

  public:
	int Header;
	int RefCode;
	int FitToPage;
	BitMask TypeID;
	int RefDecimals;

	bool RealSizeGeom;
	double ZoomGeom;
	bool RuleRealSizeGeomX;
	bool RuleRealSizeGeomY;
	bool AdjustHeightWidth;

	// Usadas en imagenes de geometria
	bool OpenedDev;
	bool MainSurface; // para la trepa, 0 es Body, 1 es surface
	bool Margins;
	bool SymmetryEnts;
	bool SymmetryAxes;

	UnicodeString RefText, IDRefCode;

	TAdvancedRectType *TypeTree; // indices para la estructura AdvancedRectTypeList

  private:
	bool DataSheetRect;
};

//------------------------------------------------------------------------------
//  TRectLabelData
//------------------------------------------------------------------------------
class TRectLabelData
{
  public:
	TRectLabelData( );
	~TRectLabelData( );

	void Clear( );
	void Set( TRectLabelData *data );
	bool IsEqual( TRectLabelData *data );

  public:
	UnicodeString LabelKey; // Clave de la etiqueta utilizada para obtener el texto. Si no tiene valor, no tienen sentido las siguientes variables
	int LabelField;			// 0: Nombre, 1: Value
	int LabelType;			// Para facilitar la busqueda de la etiqueta en funcion del tipo
	int LabelIndex[ 4 ];	// Indices dependientes del tipo;
};

//------------------------------------------------------------------------------
//  TTessLocationData
//------------------------------------------------------------------------------

#define TLD_TYPE_DEFAULT 0

class TTessLocationData
{
  public:
	TTessLocationData( );
	~TTessLocationData( )
	{
	}

	virtual void Set( TTessLocationData *data );
	virtual bool IsEqual( TTessLocationData *data );

  public:
	int Type;
	bool InvertPolygons;
	bool ShowInsides;
	bool ShowColors;
	bool OwnTextureCoords;
	bool LockTessLocationApplyMatrix;

	TNMatrix Matrix;
};

//------------------------------------------------------------------------------
//  TReportObjectFormat
//------------------------------------------------------------------------------

class TReportObjectFormat
{
  public:
	TReportObjectFormat( );
	~TReportObjectFormat( );

	virtual void Set( TReportObjectFormat *rof );

  public:
	int Type;

	TRectFormatData RectFormatData;
	TOGLMaterial OGLBackgroundMat;

	TMeasureData MeasureData;

	TTessLocationData TessLocationData;
	bool ViewFill;
	int MaterialSource;
};

//------------------------------------------------------------------------------
//  TMaxwellObjectData
//------------------------------------------------------------------------------
class TMaxwellObjectData
{
  public:
	TMaxwellObjectData( );
	~TMaxwellObjectData( );

	virtual void Set( TMaxwellObjectData *mod );

	bool HideToCamera;
	bool HideToReflectionsRefractions;
	bool HideToGI;
	bool IsExcludedOfCutPlanes;
	bool IsExcludedToExport;
};

//------------------------------------------------------------------------------
//  TParallelTypeData
//------------------------------------------------------------------------------

#define PTD_TYPE_NORMAL	  0
#define PTD_TYPE_GEOM3D	  1
#define PTD_TYPE_IBSPLINE 2

class TParallelTypeData
{
  public:
	TParallelTypeData( );
	~TParallelTypeData( )
	{
	}

	virtual void Clear( );

	virtual void Set( TParallelTypeData *data );
	virtual bool IsEqual( TParallelTypeData *data );

  public:
	int Type;
	TNPlane Plane;
	T3DPoint ForcePlaneDir;
	bool ForcePlane;
	bool ForceAxis;
	bool InvertAxis;
	double CheckExtremesNormals;

	bool Independent; // temporal, solo para creacion
};

//------------------------------------------------------------------------------

#define PDV_BREAKPOINT_NONE 1000 // No son de punto de ruptura
#define PDV_BREAKPOINT_ALL	2000 // Cualquier tipo de punto de ruptura

// Value( valores especiales )
#define PDV_BREAKPOINT_1 3000 // Punto de ruptura basico
#define PDV_BREAKPOINT_2 4000 // Punto de ruptura con interseccion con la linea base

class TParallelData : public TPctValueList
{
	friend class TImpExp_XML;

  public:
	TParallelData( bool roundcorners = true );
	virtual ~TParallelData( )
	{
	}

	virtual void Set( TNDoublesList *E );
	virtual void Clear( );

	virtual bool IsEqual( TNDoublesList *list )
	{
		return IsEqual( list, true );
	}
	virtual bool IsEqual( TNDoublesList *, bool checkpcts );
	virtual bool IsValid( );

	virtual int Count( )
	{
		return TPctValueList::Count( );
	}
	virtual int Count( int type );

	virtual double *GetItem( int ind )
	{
		return TPctValueList::GetItem( ind );
	}
	virtual double *GetItem( int indtype, int type );

	virtual double GetMaxValue( bool _unsigned = false );
	virtual double GetValue( int ind )
	{
		return TPctValueList::GetValue( ind );
	}
	virtual double GetValue( int indtype, int type );

	virtual bool GetSmoothKeepDist( )
	{
		return SmoothKeepDist;
	}
	virtual void SetSmoothKeepDist( bool value )
	{
		SmoothKeepDist = value;
	}

	virtual int GetInstances( )
	{
		return Instances;
	}
	virtual void SetInstances( int value )
	{
		Instances = value;
	}

	virtual double GetSmoothFactor( )
	{
		return SmoothFactor;
	}
	virtual void SetSmoothFactor( double value )
	{
		SmoothFactor = value;
	}

	virtual bool GetRoundCorners( )
	{
		return RoundCorners;
	}
	virtual void SetRoundCorners( bool value )
	{
		RoundCorners = value;
	}

	virtual double GetInsideRoundDist( )
	{
		return InsideRoundDist;
	}
	virtual void SetInsideRoundDist( double value )
	{
		InsideRoundDist = value;
	}

	virtual int GetQualityLevel( )
	{
		return QualityLevel;
	}
	virtual void SetQualityLevel( int value )
	{
		QualityLevel = value;
	}

	virtual bool GetInvertSideValues( )
	{
		return InvertSideValues;
	}
	virtual void SetInvertSideValues( bool value )
	{
		InvertSideValues = value;
	}

	virtual TInteger_List *GetCorners( )
	{
		return &Corners;
	}
	virtual void SetCorners( TInteger_List *corners )
	{
		Corners.Set( corners );
	}

	virtual bool IsOneSide( );
	virtual bool HasPositiveValue( );

	virtual UnicodeString GetDistancesStr( bool isoneside = false, int comptype = 0, int index = -1 );
	virtual void SetDistancesStr( UnicodeString str, bool isoneside = false, bool update = false );

	virtual void InvertSide( );								 // distancias positivas por negativas y viceversa
	virtual void InvertDirection( bool onlyvalues = false ); // las distancias en los porcentajes 0.0 a 1.0 pasan de 1.0 a 0.0
	virtual void CheckExtremes( );							 // chequea que existan los extremos 0 y 1, y elimina el resto

	virtual bool IsBreakPoint( int i, int type = PDV_BREAKPOINT_ALL );
	virtual double GetValidValue( int index, bool back );
	virtual int GetIndexByIndexType( int indtype, int type );
	virtual int GetIndexTypeByIndex( int index, int type );
	virtual int GetIndexByPct( double pct, int comptype = 0 );
	virtual double GetValueFromPct( double pct, int type = 0 );

	virtual bool IsVariable( );
	virtual void Accum( TPctValueList *list );
	virtual void UpdateValues( TParallelData *paralleldata );
	virtual void DeleteInvalidPcts( );
	virtual bool MustDivideInSegments( bool checkZeroSegments );

  protected:
	bool SmoothKeepDist;
	double SmoothFactor;
	double InsideRoundDist;
	bool RoundCorners;
	int QualityLevel; // 0, mas baja
	bool InvertSideValues;
	int Instances;

	TInteger_List Corners; // utilizado para ParallelTypeData->Type == PTD_TYPE_IBSPLINE, indica los indices de los pcts que son esquinas
};

//------------------------------------------------------------------------------
// TParallelDataList
//------------------------------------------------------------------------------

class TParallelDataList
{
  public:
	TParallelDataList( );
	~TParallelDataList( );

	void Set( TParallelDataList *E );

	void AddItem( TParallelData *s );
	void SetItem( int ind, TParallelData *s );
	virtual void InsertItem( int ind, TParallelData *s );
	void DelItem( int ind );
	TParallelData *GetItem( int ind );
	bool IsEqual( TParallelDataList *list );

	void Clear( );
	void Grow( int d );
	int Count( );

  protected:
	int numItems, maxItems;
	TParallelData *Item;
};

//------------------------------------------------------------------------------
// TMargin
//------------------------------------------------------------------------------

class TMargin
{
	friend class TImpExp_XML;

  public:
	TMargin( );

	virtual void Set( TMargin *M );
	virtual void Clear( );
	virtual bool IsEqual( TMargin *margin, bool layerbyname );

  public:
	UnicodeString Name;
	TParallelData ParallelData;
	HLAYER HLayer;
	UnicodeString LayerName; // Temporal para la lectura y escritura
	bool ForceView;
};

//------------------------------------------------------------------------------
// TMarginList
//------------------------------------------------------------------------------

class TMarginList
{
	friend class TImpExp_XML;

  public:
	TMarginList( );
	virtual ~TMarginList( );

	virtual void Set( TMarginList *E );

	virtual void AddItem( TMargin *s );
	virtual void SetItem( int ind, TMargin *s );
	virtual void DelItem( int ind );
	virtual TMargin *GetItem( int ind );
	virtual void Clear( );
	virtual int Count( );
	virtual void Grow( int d );

	virtual int GetCurrentIndex( );
	virtual void SetCurrentIndex( int );
	virtual TMargin *GetCurrentItem( );

	virtual int CountSel( );
	virtual void ClearSel( );
	virtual int GetSelIndex( int selind );
	virtual TMargin *GetSelItem( int selind );
	virtual void AddToSel( int ind );
	virtual void DelFromSel( int ind );

	virtual bool Read( UnicodeString file );
	virtual void Write( UnicodeString file );

  protected:
	int numItems, maxItems;
	TMargin *Item;

	TInteger_List curItems;
};

//------------------------------------------------------------------------------
// TSymmetricData
//------------------------------------------------------------------------------

#define SDT_NONE	  0
#define SDT_ENTITY	  1
#define SDT_POINTS	  2
#define SDT_PLANECUTS 3
#define SDT_3DPLANE	  4

class TSymmetricData
{
  public:
	TSymmetricData( );
	~TSymmetricData( )
	{
	}

	virtual void Set( TSymmetricData *data );
	virtual bool IsEqual( TSymmetricData *data );

  public:
	int Type;
	bool InvertDevelopSide;	 // SDT_ENTITY
	T3DPoint Point1, Point2; // SDT_POINTS, SDT_PLANECUTS
	double Pct1, Pct2;		 // SDT_PLANECUTS
	int nTimes;				 // SDT_PLANECUTS
	T3DPlane Plane;			 // SDT_3DPLANE
};

//------------------------------------------------------------------------------
// TOffsetVarData
//------------------------------------------------------------------------------

class TOffsetVarData
{
  public:
	TOffsetVarData( );
	~TOffsetVarData( );

	virtual void Set( TOffsetVarData *data );
	virtual void Clear( );

	virtual bool IsEqual( TOffsetVarData *data );
	virtual bool IsValid( int nvaluesu, int nvaluesv );
	virtual bool IsEmpty( );

	virtual void SetWritePoints( bool value )
	{
		WritePoints = value;
	}

	virtual void GetExtremeValues( double &minvalue, double &maxvalue );
	virtual void UpdateRes( int newres, int *close );
	virtual double GetOffset( double pu, double pv );

	virtual void UpdateToSurface( TOGLTransf *OGLTransf, TCadSurface *surf ); // TCadTensorSurface *
	virtual void InvertUValues( );

  public:
	bool Apply, WritePoints;
	int Res;
	//		int UDim, VDim;
	int nValuesU, nValuesV;
	double *Values;
	TOGLPolygon Points;
};

#define SWEEP_FILTERDIST 0.05

//------------------------------------------------------------------------------
// TSweepOneData
//------------------------------------------------------------------------------
class TSweepOneData
{
  public:
	TSweepOneData( );
	~TSweepOneData( )
	{
	}

	virtual void Clear( );
	virtual void Set( TSweepOneData *data );
	virtual bool IsEqual( TSweepOneData *data );

  public:
	bool KeepAspectRatio; // in section
	bool CloseSides;
	bool RoundCorners; // in rail
	double FilterDist;
	TOGLPolygon TempSectionCenters; // temporal y solo utilizado en las location3d tipo online
};

//------------------------------------------------------------------------------
// TSweepTwoData
//------------------------------------------------------------------------------
class TSweepTwoData
{
  public:
	TSweepTwoData( );
	~TSweepTwoData( )
	{
	}

	virtual void Clear( );
	virtual void Set( TSweepTwoData *data );
	virtual bool IsEqual( TSweepTwoData *data );

  public:
	bool KeepAspectRatio; // in section
	bool CloseSides;
	double FilterDist;
};

//------------------------------------------------------------------------------
// TRevolveData
//------------------------------------------------------------------------------
class TRevolveData
{
  public:
	TRevolveData( );
	~TRevolveData( )
	{
	}

	virtual void Clear( );
	virtual void Set( TRevolveData *data );
	virtual bool IsEqual( TRevolveData *data );

  public:
	bool CloseSides;
	double Angle;
};

#define BORDERTYPE_STRAIGHT		   0
#define BORDERTYPE_ROUNDED		   1
#define BORDERTYPE_HALFROUNDED	   2
#define BORDERTYPE_HALFROUNDED_INV 3
#define BORDERTYPE_CONTINUOUS	   4

//------------------------------------------------------------------------------
// TExtendData
//------------------------------------------------------------------------------
class TExtendData
{
  public:
	TExtendData( );
	~TExtendData( )
	{
	}

	virtual void Clear( );
	virtual void Set( TExtendData *data );
	virtual bool IsEqual( TExtendData *data );

  public:
	double Distance;
	bool Straight;
	double FilterDist;
};

//------------------------------------------------------------------------------
// TExtrusionData
//------------------------------------------------------------------------------
class TExtrusionData
{
  public:
	TExtrusionData( );
	~TExtrusionData( )
	{
	}

	virtual void Clear( );
	virtual void Set( TExtrusionData *data );
	virtual bool IsEqual( TExtrusionData *data );

	virtual int GetProfileType( int index );
	virtual double GetProfileValue( int index );

  public:
	TIntDoubleList Profiles;
	double Thickness;
	double Curvature; // (0..1). Solo para ExtrusionTrim
};

//------------------------------------------------------------------------------
// TTrimOffsetSideData
//------------------------------------------------------------------------------

class TTrimOffsetSideData
{
  public:
	TTrimOffsetSideData( );
	~TTrimOffsetSideData( )
	{
	}

	virtual void Set( TTrimOffsetSideData *data );
	virtual bool IsEqual( TTrimOffsetSideData *data );

  public:
	bool Offset2D;
	double Offset3D;
	bool InvertNormals;
};

//------------------------------------------------------------------------------
// TTrimOffsetBorderData
//------------------------------------------------------------------------------

class TTrimOffsetBorderData
{
  public:
	TTrimOffsetBorderData( );
	~TTrimOffsetBorderData( )
	{
	}

	virtual void Set( TTrimOffsetBorderData *data );
	virtual bool IsEqual( TTrimOffsetBorderData *data );

  public:
	int Type;
	bool Advanced;
	bool InvertSide;
};

//------------------------------------------------------------------------------
// TPointRelation
//------------------------------------------------------------------------------

class TPointRelation
{
  public:
	UnicodeString Description;
	int Type;  // PR_TYPE_NONE, PR_TYPE_DATA, PR_TYPE_MARKER
	int Value; // Data(int)
	TCadShape *BaseShape;
	int BaseType;	  // PR_BASETYPE_NONE, PR_BASETYPE_DATA, PR_BASETYPE_MARKER, PR_BASETYPE_DISTANCE, PR_BASETYPE_PERCENT, PR_BASETYPE_INTERSECT (solo para Type == PR_TYPE_MARKER)
	double BaseValue; // Data(int), Marker(int), Pct(double), Distance(double)
	bool BaseFromEnd; // los datos de BaseValue en Pct y Distance van de final a principio (menos PR_BASETYPE_INTERSECT)
	int BaseMode;	  // PR_BASEMODE_GEOM3D, PR_BASEMODE_DEVELOP2D, PR_BASEMODE_PARAM2D
	int Visible;	  // PR_VISIBLE_NONE PR_VISIBLE_GEOM3D, PR_BASEMODE_DEVELOP2D, PR_BASEMODE_PARAM2D PR_VISIBLE_ALL
	double ExtendDist;
	bool OwnMaterial;
	TOGLMaterial Mat;
	bool Needed;   // true: si desaparece la relacion, desaparece la entidad. false lo contrario
	bool Erasable; // false: no puede ser borrado el punto sin borrar la relación de punto previamente

	int OwnerIndex;		   // Indice de la relacion dentro de la lista antes de ser quitada de la entidad
	TCadShape *OwnerShape; // entidad utilizado para almacenar la propietaria de la relacion de punto para rehacer / deshacer tanto quitar como poner la relacion

  public:
	TPointRelation( );
	void Set( TPointRelation * );
	void SetBasic( TPointRelation * );
	void Clear( );

	void SetMaterial( TOGLMaterial * );
	TOGLMaterial *GetMaterial( );
};

//------------------------------------------------------------------------------
// TPointRelationList
//------------------------------------------------------------------------------

class TPointRelationList
{
  public:
	TPointRelationList( );
	~TPointRelationList( );

	void Set( TPointRelationList *E );
	void SetBasic( TPointRelationList *E );

	void AddItem( TPointRelation *s );
	void SetItem( int ind, TPointRelation *s );
	virtual void InsertItem( int ind, TPointRelation *s );
	void DelItem( int ind );
	TPointRelation *GetItem( int ind );

	void Clear( );
	void Grow( int d );
	int Count( );
	int VisibleCount( TOGLTransf * );

	void Invert( );

  protected:
	int numItems, maxItems;
	TPointRelation *Item;
};

//------------------------------------------------------------------------------
// TEntityRelation
//------------------------------------------------------------------------------

class TEntityRelation
{
  public:
	UnicodeString Description;
	int Type;
	TCadEntity *BaseEntity;

	int OwnerIndex;			 // Indice de la relacion dentro de la lista antes de ser quitada de la entidad
	TCadEntity *OwnerEntity; // entidad utilizado para almacenar la propietaria de la relacion de entidad para rehacer / deshacer tanto quitar como poner la relacion

  public:
	TEntityRelation( );
	void Set( TEntityRelation * );
	void SetBasic( TEntityRelation * );
};

//------------------------------------------------------------------------------
// TEntityRelationList
//------------------------------------------------------------------------------

class TEntityRelationList
{
  public:
	TEntityRelationList( );
	~TEntityRelationList( );

	void Set( TEntityRelationList *E );

	void AddItem( TEntityRelation *s );
	void SetItem( int ind, TEntityRelation *s );
	virtual void InsertItem( int ind, TEntityRelation *entrel );
	void DelItem( int ind );
	TEntityRelation *GetItem( int ind );

	void Invert( );

	void Clear( );
	void Grow( int d );
	int Count( );

  protected:
	int numItems, maxItems;
	TEntityRelation *Item;
};

//------------------------------------------------------------------------------
// TReference
//------------------------------------------------------------------------------

class TReference
{
  public:
	TReference( );
	TReference( TReference *m );
	~TReference( );

	void Clear( );
	void Set( TReference *m );

	TCadEntity *GetEntity( );
	void SetEntity( TCadEntity *ent );
	int GetMarkerIndex( );
	void SetMarkerIndex( int mi );
	bool IsVisible( );
	void SetVisible( bool v );
	bool IsVisibleInterface( );
	void SetVisibleInterface( bool v );
	bool IsLocked( );
	void SetLocked( bool v );
	int GetType( );
	void SetType( int t );
	int GetGroupType( );
	void SetGroupType( int gt );
	int GetGroup( );
	void SetGroup( int g );
	UnicodeString GetGroupName( );
	void SetGroupName( UnicodeString str );
	int GetGroupIndex( );
	void SetGroupIndex( int i );
	wchar_t *GetSourceFileName( );
	void SetSourceFileName( wchar_t *str );
	double GetResolution( );
	void SetResolution( double res );
	bool IsSystemReference( );
	void SetSystemReference( bool sys );
	UnicodeString GetDescription( );

	virtual void ChangeRelatedEntity( TCadEntity *orgent, TCadEntity *dstent );

	bool __fastcall operator==( const TReference &reference );

	//  protected:

  public:								// para optimizar y no usar llamadas
	TCadEntity *Entity;					// Puntero a la entidad referenciada
	int MarkerIndex;					// Indice de marcador para las referencias de tipo RF_MARKER
	bool Visible;						// Visible o no en el editor
	bool VisibleInterface;				// Visible o no en el formulario
	bool Locked;						// No editable. Solo para las de la pagina REF_PAGE_FREE
	int Type;							// Tipo de referencia: marcador, punto, curva, etc.
	int GroupType;						// Identificador del tipo de grupo
	int Group;							// Identificador del grupo: locales, de fichero, etc.
	UnicodeString GroupName;			// Nombre del grupo
	int GroupIndex;						// Indice de la referencia dentro de su grupo
	wchar_t SourceFileName[ MAX_PATH ]; // Ruta y nombre del fichero para las referencias de tipo RF_FILE
	double Resolution;					// Resolucion, en puntos por pulgada, para las imagenes de referencia
	bool SystemReference;				// Indica si una referencia es de sistema o no
};

//------------------------------------------------------------------------------
// TReferenceList
//------------------------------------------------------------------------------

class TReferenceList
{
  public:
	TReferenceList( );
	~TReferenceList( );

	void Set( TReferenceList *E );

	void AddItem( TReference *s );
	int AddItemAtGroupIndex( TReference *r, int groupindex );
	void SetItem( int ind, TReference *s );
	void DelItem( int ind );
	TReference *GetItem( int ind );
	int GetItemIndex( TReference *s );

	void Clear( );
	int Count( );
	void Grow( int d );

	int GetSystemReferencesCount( );

	int GetCountByType( int type );
	int GetSubListByType( int type, TReferenceList *list );

	int GetCountByGroupType( int grouptype );
	int GetSubListByGroupType( int grouptype, TReferenceList *list );

	int GetCountByGroup( int group );
	int GetSubListByGroup( int group, TReferenceList *list );
	TReference *GetReferenceByGroupIndex( int group, int index );

	int GetReferenceIndex( TCadEntity *ent );
	int GetReferenceIndex( TPointMarker *marker );
	int GetReferenceIndex( TLineMarker *marker );
	int GetPointReferenceIndex( TCadEntity *ent );
	int GetShapeReferenceIndex( TCadEntity *ent );
	int GetFreeReferenceIndex( TCadEntity *ent );
	int GetFileReferenceIndex( TCadEntity *ent );

	int GetReferenceEntNoGroupIndex( TCadEntity *ent );
	bool IsReference( TPointMarker *marker );
	bool IsReference( TLineMarker *marker );
	bool IsReference( TCadEntity *ent );
	bool IsPointReference( TCadEntity *ent );
	bool IsShapeReference( TCadEntity *ent );
	bool IsFreeReference( TCadEntity *ent );
	bool IsFileReference( TCadEntity *ent );

	bool IsGroupInType( int group, int type );

	virtual void ChangeRelatedEntity( TCadEntity *orgent, TCadEntity *dstent );

	bool AreAllVisible( );

  protected:
	int numItems, maxItems;
	TReference *Item;
};

//------------------------------------------------------------------------------
// TTractData
//------------------------------------------------------------------------------

class TTractData
{
  public:
	TTractData( );

	virtual void Clear( );
	virtual void Set( TTractData *data );

	virtual bool IsEqual( TTractData *data, bool checkAuxID = false );
	virtual void Invert( );

	virtual double GetIncOffset( );

  public:
	TCadShape *Shape;
	double Pct1, Pct2;
	int ExtendSide;
	double ExtendDist;
	double Offset;
	bool InvertOffset;
	int PolIndex;
	T3DPoint Point1, Point2;
	bool Increase;
	int AuxID; // Temporal
};

//------------------------------------------------------------------------------
// TTractDataList
//------------------------------------------------------------------------------

class TTractDataList
{
  public:
	TTractDataList( );
	~TTractDataList( );

	virtual void Set( TTractDataList *datalist );
	virtual bool IsEqual( TTractDataList *datalist );

	virtual void AddItem( TTractData *data );
	virtual void SetItem( int ind, TTractData *data );
	virtual void InsertItem( int ind, TTractData *data );
	virtual void DelItem( int ind );

	virtual TTractData *GetItem( int ind );

	virtual bool HasMember( TTractData *data, int first = 0, bool checkAuxID = false );

	virtual void Clear( );
	virtual int Count( );
	virtual void Grow( int d );

	virtual void UpdatePctsByExtendDist( TOGLTransf *OGLTransf, TTractDataList *list, bool isParam, bool *close, double *limitsUV, double tol_1 );

	virtual void GetIntersectDataList( TIntersectDataList *list, bool iscloseext = true );

	virtual int GetIndexByPoint( TOGLTransf *OGLTransf, bool isParam, T3DPoint pt, double limitdist = MAXDOUBLE );

  public:
	int numItems, maxItems;
	TTractData *Item;

	bool ExcludeFirst, ExcludeLast;
	double Tolerance;
};

//------------------------------------------------------------------------------
// TIntersectData
//------------------------------------------------------------------------------

class TIntersectData
{
  public:
	TIntersectData( );

	virtual void Clear( );
	virtual void Set( TIntersectData *data );

	virtual bool IsEqual( TIntersectData *data, bool checkshapes = true );

	virtual void ChangeRelatedEntity( TCadEntity *orgent, TCadEntity *dstent, bool &setdirty );
	virtual bool IsEntityIncluded( TCadEntity *ent );
	virtual bool IsEntityIncluded( TIntersectData *data );
	virtual void InvertEntities( );

	virtual double GetIncOffset1( ); // double pctprev );

  public:
	TCadShape *Shape1;
	double Pct1;
	int ExtendSide1;
	double ExtendDist1;
	double Offset1;
	bool InvertOffset1;
	int PolIndex1;

	TCadShape *Shape2;
	double Pct2;
	int ExtendSide2;
	double ExtendDist2;
	double Offset2;
	bool InvertOffset2;
	int PolIndex2;

	bool Increase;
	T3DPoint Point;
};

//------------------------------------------------------------------------------
// TIntersectDataList
//------------------------------------------------------------------------------

#define RES_CONTACT_PARAM 0.1
#define RES_CONTACT_GEOM  0.01

typedef struct {
	int numInt;
	T3DPoint *pt1, *pt2;
	double *intpar1, *intpar2;
} TContourIntersection;

class TIntersectDataList
{
  public:
	TIntersectDataList( );
	~TIntersectDataList( );

	virtual void Set( TIntersectDataList *datalist );
	virtual bool IsEqual( TIntersectDataList *datalist );

	virtual void AddItem( TIntersectData *data );
	virtual void SetItem( int ind, TIntersectData *data );
	virtual void InsertItem( int ind, TIntersectData *data );
	virtual void DelItem( int ind );

	virtual TIntersectData *GetItem( int ind );
	virtual int GetItemIndex( T3DPoint pt, double res );

	virtual void Clear( );
	virtual int Count( );
	virtual void Grow( int d );

	virtual void UpdatePctsByExtendDist( TOGLTransf *OGLTransf, bool isParam, bool *close, double *limitsUV, double tol_1 );
	virtual double GetMinExtendDist( );
	virtual void SetExtendValues( int side, double dist );

	virtual void GetTractDataList( TTractDataList *list );

	virtual bool Intersect( TOGLTransf *OGLTransf, TCadShape **shape, int *polindex, double *offset, int *OrgExtendSide, bool isparam, double *res, bool checksimilar );

	virtual bool CalcContour( TOGLTransf *OGLTransf, TCadGroup *group, TInteger_List *exceptions, TInteger_List *notincontour, TInteger_List *notextend, TInteger_List *swap, bool param, T3DPoint point, double res, bool yield = false, double maxdist = 1.0, double filterdist = 0.0 );

	virtual bool AddDelContour( TOGLTransf *OGLTransf, bool isParam, TIntersectDataList *contour, TInteger_List *swapEnts = 0 );
	virtual bool SplitInTwo( TOGLTransf *OGLTransf, bool isParam, TIntersectDataList *contourSplit, TIntersectDataList *contour1, TIntersectDataList *contour2 );

	virtual void ChangeRelatedEntity( TCadEntity *orgent, TCadEntity *dstent, bool &setdirty );
	virtual bool IsEntityIncluded( TCadEntity *ent );
	virtual bool IsEntityIncluded( TIntersectDataList *list );
	virtual bool IsDualRelated( TIntersectDataList *dualContour );

	virtual bool IsCloseExt( );
	virtual void RecalcPolIndex( TOGLTransf *, bool );

	// DEBUG
	//		virtual void PrintIntersectionsTableDebug( TCadGroup *group, TInteger_List *indexList, TContourIntersection** inters );
	//		virtual void PrintContourDebug( TTractDataList *contour, bool ok );

  public:
	int numItems, maxItems;
	TIntersectData *Item;

	bool RecalcWithPoints; // true: recalcular los porcentajes usando los puntos
	bool ExcludeFirst, ExcludeLast;
	double Tolerance;

	bool Use; // Por defecto es true, se utiliza en las depshapes. Si es false, las depshapes no utilizan la clase

  private:
	// funciones auxiliares para el CalcContour

	virtual int PreProcessContourEntities( TOGLTransf *OGLTransf, bool isParam, double *limitsUV, bool *close, TInteger_List *GroupIndexList, TInteger_List *exceptions, TOGLPointerPolygonList *InitialOGLList, TContourIntersection **intersections, bool *discards, double **limits, TOGLPolygon *Out );
	virtual void ClearLocalMem( int nCurves, TOGLPolygonList *OGLList, bool *discards, double **limits, TContourIntersection **intersections );
	virtual void FindSeeds( bool toRight, T3DPoint *point, TOGLPointerPolygonList *InitialOGLList, bool *discards, double **limits, TTractDataList *seeds );
	virtual void UpdateDiscardList( TInteger_List *notincontour, TInteger_List *GroupIndexList, TTractData *tractdata, bool *discards );
	virtual void SetContourSegmentParams( bool firstSegment, int curEntity, int nCurves, TOGLPolygon *OGLPol, TInteger_List *GroupIndexList, TOGLPointerPolygonList *InitialOGLList, TContourIntersection **inters, bool *discards, double **limits, bool Increase, bool isParam, bool *close, double *limitsUV, double refParam, double &prevParam, int &nextEntity, double &nextEntityParam, int refDevSurfIndex, TInteger_List *swapents, bool yield );
	virtual void AppendContactPoints( bool isparam, TOGLPointerPolygonList *InitialOGLList, T3DPoint pt, TOGLPolygon *Out, TOGLPolygon *Out2, int x, int y );
};

//------------------------------------------------------------------------------
// TPaddingData
//------------------------------------------------------------------------------

#define PADDING_MODE_NONE		 -1
#define PADDING_MODE_EXTRUSION	 0
#define PADDING_MODE_SWEEP		 1

#define PADDING_NONE			 -1
#define PADDING_OUTSIDE			 0
#define PADDING_INSIDE			 1
#define PADDING_BOTH_SYMMETRIC	 2
#define PADDING_BOTH			 3

#define PADDING_PROFILE_CURVE	 0
#define PADDING_PROFILE_STRAIGHT 1

class TPaddingData
{
  public:
	TPaddingData( );
	~TPaddingData( );

	virtual void Clear( );
	virtual void InitValues( UnicodeString name, int mode );
	virtual void Set( TPaddingData *data );
	virtual bool IsEqual( TPaddingData *data );
	virtual bool IsNull( );

	virtual void Write( UnicodeString str, TMemIniFile *local_file = 0, UnicodeString file = EmptyStr );
	virtual void Read( UnicodeString str, TMemIniFile *local_file = 0, UnicodeString file = EmptyStr );

  public:
	// Comunes
	UnicodeString Name;
	bool Active;
	int Mode;			  // Modo del acolchado: PADDING_MODE_EXTRUSION, PADDING_MODE_SWEEP
	double Height;		  // Altura del acolchado
	double SmoothProfile; // Valor de suavizado del perfil tipo PADDING_PROFILE_CURVE (0..1)
	double SmoothUnion;	  // Indica si se suaviza la union del padding con el resto de la pieza (0..1)
	int Side;			  // PADDING_OUTSIDE, PADDING_INSIDE, PADDING_BOTH_SYMMETRIC, PADDING_BOTH;
	bool HighQuality;

	// Modo EXTRUSION
	double ExtrusionMargin;		 // Distancia del contorno al comienzo del acolchado en modo EXTRUSION
	double ExtrusionSmoothWidth; // Distancia del comienzo del acolchado hasta la altura en modo EXTRUSION

	// Modo SWEEP
	double SweepOffset2D; // Desplazamiento del carril respecto a su curva base en modo SWEEP
	double SweepWidth;	  // Ancho total en el modo SWEEP
	double SweepSmooth;	  // Distancia del comienzo del acolchado hasta la altura como porcentaje del ancho total en el modo SWEEP (0..1)

	int Index; // Temporal: utilizado en TPaddingDataList
};

//------------------------------------------------------------------------------

class TPaddingDataList
{
  public:
	TPaddingDataList( );
	~TPaddingDataList( );

	virtual void Set( TPaddingDataList *datalist );

	virtual void AddItem( TPaddingData *data );
	virtual void SetItem( int ind, TPaddingData *data );
	virtual void InsertItem( int ind, TPaddingData *data );
	virtual void DelItem( int ind );

	virtual TPaddingData *GetItem( int ind );

	virtual void Clear( );
	virtual int Count( );
	virtual void Grow( int d );

  public:
	int numItems, maxItems;
	TPaddingData *Item;
};

//------------------------------------------------------------------------------
// TMarkersData
//------------------------------------------------------------------------------

class TMarkersData
{
  public:
	TMarkersData( );
	~TMarkersData( )
	{
	}

	virtual void Set( TMarkersData *data );

  public:
	bool UseBaseShapePol;
	bool ExportInvertSense;
	double ExportStartPct;

	TMachine2DList *Machine2DList;
	TTool2DList *Tool2DList;

	TPaddingData PaddingData; // para tipo markers
};

//------------------------------------------------------------------------------
// TSE_DataOnMachine2D
//------------------------------------------------------------------------------

#define SE_DOM_MARK_NONE  0
#define SE_DOM_MARK_LEFT  1
#define SE_DOM_MARK_RIGHT 2
#define SE_DOM_MARK_BOTH  3

#define SE_SHAPETYPE_NONE -1
#define SE_SHAPETYPE_1	  0
#define SE_SHAPETYPE_2	  1
#define SE_SHAPETYPE_3	  2
#define SE_SHAPETYPE_4	  3
#define SE_SHAPETYPE_5	  4
#define SE_SHAPETYPE_6	  5
#define SE_SHAPETYPE_7	  6
#define SE_SHAPETYPE_8	  7

class TSE_DataOnMachine2D
{
  public:
	TSE_DataOnMachine2D( );
	virtual ~TSE_DataOnMachine2D( )
	{
	}

	virtual void Clear( );
	virtual void Set( TSE_DataOnMachine2D *data );
	virtual bool IsEqual( TSE_DataOnMachine2D *, int checkoffset = 1 );

	virtual int GetTool2DType( int indextypelist );
	virtual double GetValue( TMachine2D *machine2d, int index );

	// Todos los parametros son para una maquina concreta, y pueden diferir de una a otra

  public:
	TInteger_List Tool2D_TypeList; // Lista de tipos de herramienta utilizados en este elemento
	TNDoublesList Values;		   // Ancho/Diametro del elemento si OwnValues
	TOGLMaterial Mat;			   // Material del elemento si OwnMat
	bool OwnValues;				   // true: Ancho/Diametro se toma de Values, false: Ancho/Diametro se toma de Tool2D_DataOnMachine2D
	bool OwnMat;				   // true: Material se toma de la herramienta, false: Ancho/Diametro se toma de Tool2D_DataOnMachine2D
	double Offset;				   // Offset del elemento respecto a la linea base
	double StartDist;			   // Distancia respecto al inicio de la linea base para empezar a distribuir items
	double EndDist;				   // Distancia respecto al final de la linea base para empezar a distribuir items
	double InterDist;			   // Distancia respecto al final de la linea base para empezar a distribuir items
	bool AutoJoin;				   // Unir las lineas o suavizado en marcas automatico
	bool BaseAutoJoin;			   // Unir las lineas base de las lineas o hacerlas como la distribucion que tenga

	// Lineas
	int BaseShapeTool2DType; // Tipo de herramienta para dibujar la linea base
	int Mark;				 // Lado donde incluir una marca en la linea
	double BaseOffset;		 // Offset de la linea base

	// Circulos
	// Figuras

	// Marcas
	int ShapeType;	  // Subtipo dentro de cada tipo.
	bool Invert;	  // Invertir la marca
	bool InBaseShape; // Insertada en la BaseShape o independiente
	bool FirstPoint;  // Si el usuario no lo cambia, se utiliza como primer punto de la pieza
	bool DoubleInverted;
	double RoundExtreme;
	double SmoothDist;		 // Suavizado en marcas
	TNDoublesList Distances; // Distancias entre los items del elemento. En lineas si no hay se utiliza Sizes, en SE_BASEPOINTS_OFFSET se almacena el offset. En SE_AREA se almacena el ancho

	// Areas
	int Index;

	// simbolicas y area
	bool Apply; // Aplicar
};

//------------------------------------------------------------------------------
// TSE_DataOnMachine2DList
//------------------------------------------------------------------------------

class TSE_DataOnMachine2DList
{
	friend class TImpExp_XML;

  public:
	TSE_DataOnMachine2DList( );
	virtual ~TSE_DataOnMachine2DList( );

	virtual void Set( TSE_DataOnMachine2DList *E );
	virtual bool IsEqual( TSE_DataOnMachine2DList *, int checkoffset = 1 );

	virtual void AddItem( TSE_DataOnMachine2D *s );
	virtual void SetItem( int ind, TSE_DataOnMachine2D *s );
	virtual void DelItem( int ind );
	virtual TSE_DataOnMachine2D *GetItem( int ind );
	virtual void Clear( );
	virtual int Count( );
	virtual void Grow( int d );

  protected:
	int numItems, maxItems;
	TSE_DataOnMachine2D *Item;
};

//------------------------------------------------------------------------------
// TSE_TextData
//------------------------------------------------------------------------------

// mascaras individuales
#define TEXT_SE_MODELNAME	 0x0001
#define TEXT_SE_AREA		 0x0002
#define TEXT_SE_QUALITY		 0x0004
#define TEXT_SE_DESC		 0x0008
#define TEXT_SE_GROUP		 0x0010
#define TEXT_SE_PIECENAME	 0x0020
#define TEXT_SE_PERIMETER	 0x0040
#define TEXT_SE_PIECEPAR	 0x0080
#define TEXT_SE_SIZE		 0x0100
#define TEXT_SE_DATE		 0x0200
#define TEXT_SE_ENTER		 0x0400
#define TEXT_SE_WIDTH		 0x0800
#define TEXT_SE_TIME		 0x1000
#define TEXT_SE_PIECENUMBER	 0x2000
#define TEXT_SE_PIECESAMOUNT 0x4000
#define TEXT_SE_GEOMVAR		 0x8000

// mascaras conjuntas
#define TEXT_SE_ONLYGEOM 0x0042
#define TEXT_SE_ALL		 0xFFFF

class TSE_TextData
{
  public:
	TSE_TextData( );
	virtual ~TSE_TextData( )
	{
	}

	virtual void Clear( );
	virtual void Set( TSE_TextData *data );
	bool __fastcall operator==( const TSE_TextData &data );

	virtual void SetReferences( TSE_TextData *data );
	virtual bool HasTextReferences( unsigned inputmask, unsigned *outputmask );
	virtual int CountCR( ); // intro, retorno de carro
	virtual bool EqualFont( TSE_TextData *data );
	virtual UnicodeString GetTextStr( bool useCR = true );
	virtual void Write( UnicodeString str, TMemIniFile *_local_file, UnicodeString file );
	virtual void Read( UnicodeString str, TMemIniFile *_local_file, UnicodeString file );

  public:
	// Atributos almacenados
	vector<UnicodeString> Texts;
	vector<unsigned> TextRefs;
	LOGFONT LogFont;
	double TextSize;
	bool UseCadText;
	bool OwnFont;
	bool UseAsSimple;
	bool CustomBySize;
	bool OnlyFirstSize;
	bool AutomaticInsertion;
	TNDoublesList OrgSizes;
	TUnicodeStringList CustomSizes;

	// Referencias calculadas
	int Quality;
	int PiecePar;
	int PieceIndex;
	int PiecesAmount;
	double Perimeter;
	UnicodeString Area;
	UnicodeString GradingSize;
	UnicodeString GradingWidth;
	UnicodeString ModelName;
	UnicodeString Description;
	UnicodeString PieceName;
	UnicodeString PieceGroup;
	UnicodeString GeomVar;

	bool CalcAutoPos;
};

//------------------------------------------------------------------------------
// TSE_Costing
//------------------------------------------------------------------------------

#define SE_COSTINGTYPE_NONE		 0
#define SE_COSTINGTYPE_FIX		 1
#define SE_COSTINGTYPE_NUMBER	 2
#define SE_COSTINGTYPE_PERIMETER 3
#define SE_COSTINGTYPE_AREA		 4

class TSE_Costing
{
  public:
	TSE_Costing( );
	virtual ~TSE_Costing( )
	{
	}

	virtual void Clear( );
	virtual void Init( int type, int units, UnicodeString currency );
	virtual void Set( TSE_Costing *data );
	virtual bool IsEqual( TSE_Costing * );
	virtual bool IsValid( );
	virtual void CheckUnits( );

	bool __fastcall operator==( const TSE_Costing &data );

	virtual void Write( UnicodeString str, TMemIniFile *local_file = 0, UnicodeString file = EmptyStr );
	virtual void Read( UnicodeString str, TMemIniFile *local_file = 0, UnicodeString file = EmptyStr );

  public:
	int Instances;
	int Type;
	double Amount; // Solo para Type == SE_COSTINGTYPE_FIX
	int Units;	   // Solo para Type == SE_COSTINGTYPE_PERIMETER || Type == SE_COSTINGTYPE_AREA
	double PriceByUnit;
	UnicodeString Currency;

	int CostingInstancesTemp;
	double CostingAmountTemp;
	double CostingTemp;
};

//------------------------------------------------------------------------------
// TShapeElement
//------------------------------------------------------------------------------

#define SE_TOTAL			   14 // Todos los SE
#define SE_ALL				   11 // No incluye las lineas y puntos base de elementos virtuales
#define SE_CONTOURS			   5
#define SE_INSIDES			   6

#define SE_NONE				   -1
#define SE_SHAPES_MARGIN	   0
#define SE_SHAPES_MARK		   1
#define SE_SHAPES_FESTOON	   2
#define SE_SHAPES_SYMBOLIC	   3
#define SE_SHAPES_SOFTEN	   4
#define SE_LINES			   5
#define SE_CIRCLES			   6
#define SE_SHAPES_INSIDES	   7
#define SE_BASELINES		   8
#define SE_BASEPOINTS		   9
#define SE_BASEPOINTS_OFFSET   10
#define SE_TEXT				   11
#define SE_AREA				   12
#define SE_WAVES			   13

#define SE_SHAPETYPE_CUSTOM_1  '1'
#define SE_SHAPETYPE_CUSTOM_2  '2'
#define SE_SHAPETYPE_CUSTOM_3  '3'
#define SE_SHAPETYPE_CUSTOM_4  '4'
#define SE_SHAPETYPE_CUSTOM_5  '5'
#define SE_SHAPETYPE_CUSTOM_6  '6'
#define SE_SHAPETYPE_CUSTOM_7  '7'
#define SE_SHAPETYPE_CUSTOM_8  '8'
#define SE_SHAPETYPE_CUSTOM_A  'A'
#define SE_SHAPETYPE_CUSTOM_B  'B'
#define SE_SHAPETYPE_CUSTOM_C  'C'
#define SE_SHAPETYPE_CUSTOM_D  'D'
#define SE_SHAPETYPE_CUSTOM_E  'E'
#define SE_SHAPETYPE_CUSTOM_F  'F'
#define SE_SHAPETYPE_CUSTOM_G  'G'
#define SE_SHAPETYPE_CUSTOM_H  'H'

#define SE_SEP_NONE			   0
#define SE_SEP_HALF			   1
#define SE_SEP_WHOLE		   2

#define SE_SYM_NONE			   0
#define SE_SYM_BOTH			   1
#define SE_SYM_OTHER		   2

#define SE_DISTRIBUTEIN_OFFSET 0
#define SE_DISTRIBUTEIN_CURVE  1

class TShapeElement
{
  public:
	TShapeElement( );
	virtual ~TShapeElement( );

	virtual void Clear( );
	virtual void Set( TShapeElement * );

	virtual bool IsEqual( TShapeElement *, int checkoffset = 1, bool checkcosting = false );

	virtual void ApplySymmetry( );

	virtual void UpdateMachines2DCount( TMachine2DList *machine2dlist );
	virtual void UpdateMachines2DCount( int countmachines );

	virtual bool UpdateMachines2D( TMachine2DList *machine2dlist, TTool2DList *tool2dlist, TMachine2DList *newmachine2dlist, TTool2DList *newtool2dlist );
	virtual TSE_DataOnMachine2D *GetDataOnMachine2D( int machineindex );
	virtual bool ReplaceTool2DTypes( TMachine2DList *machine2dlist, int machine2dindex, int tool2dtype1, int tool2dtype2 );

	virtual bool IsLine( );
	virtual bool IsWave( );
	virtual bool IsCircle( );
	virtual bool IsText( );
	virtual bool IsArea( );
	virtual bool IsShape( );
	virtual bool IsBaseLine( );
	virtual bool IsBasePoint( );
	virtual bool IsBasePointOffset( );

	virtual bool IsShapeMargin( );
	virtual bool IsShapeMark( );
	virtual bool IsShapeSymbolic( );
	virtual bool IsShapeFestoon( );
	virtual bool IsShapeSoften( );
	virtual bool IsShapeInside( );

	virtual bool IsPointMarkerType( );
	virtual bool IsPointMarkerInContourType( );
	virtual bool IsContourType( bool strict = false );
	virtual bool IsInsideType( bool strict = false );
	virtual bool IsBaseSE( );
	virtual bool CanReplace( TShapeElement *se, bool checkcontour = false, bool contour = false );

	virtual bool CanDistributeDim2D3D( TOGLTransf *OGLTransf, TCadShape *shape );
	virtual void InitDim2DToDistribute( TOGLTransf *OGLTransf, TCadShape *shape );

	virtual bool IsLinkedToBaseShape( );

	virtual bool UseTempTrimShape( );

	virtual double GetSoftenSideValue( int machineindex, bool left );
	virtual void SetSoftenSideValue( int machineindex, bool left, double value );

	virtual TSE_Costing *GetCosting( bool force );

	virtual void Write( UnicodeString str, TMemIniFile *local_file = 0, UnicodeString file = EmptyStr );
	virtual void Read( UnicodeString str, TMemIniFile *local_file = 0, UnicodeString file = EmptyStr );

  public:
	UnicodeString Name; // Nombre del elemento
	bool Active;		// Establece si el SE esta activo o no (se utiliza para la gestion de la visibilidad de los SE)
	int Type;			// Tipo: SE_NONE, SE_LINES, SE_CIRCLES, SE_BASELINES, SE_BASEPOINTS, SE_BASEPOINTS_OFFSET, SE_SHAPES_MARGIN, SE_SHAPES_MARK, SE_SHAPES_SYMBOLIC, SE_SHAPES_FESTOON, SE_SHAPES_SOFTEN, SE_SHAPES_INSIDES, SE_TEXT, SE_AREA, SE_WAVES
	bool ForceView;		// Forzar en vista de creacion
	bool HideBaseLines; // Para elementos tipo coste
	bool Favorite;		// Mostrar en el listado de elementos favoritos
	int CreateMode;		// Modo de creacion por defecto para un elemento

	int numItems;				  // Numero de items del elemento; si es -1, reparte la cantidad que puede en grupos por tamanyo o distancia entre elementos
	TNDoublesList Distances;	  // Distancias entre los items del elemento. En lineas si no hay se utiliza Sizes, en SE_BASEPOINTS_OFFSET se almacena el offset. En SE_AREA se almacena el ancho
	double OffsetToDistribute;	  // Offset a aplicar a la linea base para distruir los items; en SE_AREA se almacena el offset
	bool RoundOffsetToDistribute; // Redondear esquinas al calcular paralela con el valor de OffsetToDistribute.
	bool Dim2DToDistribute;		  // Distribuir utilizando la lista 2D o 3D en circulos y figuras
	bool Invert;				  // Invertir la linea base para distribuir items
	int SeparationFirst;		  // Separacion inicial: Ninguna, media, completa
	int SeparationLast;			  // Separacion final: Ninguna, media, completa
	bool FitExtremes;			  // Ajustar extremos en la distribucion de elementos
	double DistMinContour;		  // Distancia minima al contorno al crear el elemento
	bool StartOnIntersect;		  // Comenzar en interseccion
	bool EndOnIntersect;		  // Terminar en interseccion
	double Angle;				  // Para figuras y texto
	double ScaleFactor;			  // Para figuras y texto
	bool Mirror;				  // Para figuras y texto
	TNDoublesList AmountsBySize;  // Para circulos y figuras
	bool UseForSymmetries;		  // Para marcas y lineas
	bool OnIntersect;			  // Marcas y simbolica en interseccion
	bool ByDefaultForPieces;	  // Para circulos y lineas
	TUnicodeStringList DXFLayers; // Para circulos y lineas: indica para que capas en la importacion DXF se utiliza el elemento
	bool OuterStart;			  // Para festones y ondas
	bool OuterEnd;				  // Para festones y ondas

	bool InvertedAxis; // Temporal en base a la transformacion
	bool CanUseTempTrimShape;
	TCadDepShape *TempTrimShape;	  // Para recortar elementos interiores
	double TempCurSize, TempBaseSize; // Vbles temporales utilizadas para calcular el escalado

	TSE_DataOnMachine2DList SE_DataOnMachine2DList; // Lista de datos del elemento especificos para cada maquina

	// Lineas
	TNDoublesList Sizes; // Tamanyo de cada item. Si no hay,  se utiliza Distances
	bool RoundExtremes;	 // Redondear extremos del item
	bool TempForceClose; // Forzar el metodo de creacion de contornos cerrados

	// Ondas
	bool Center; // Onda centrada en la linea base
	bool Cross;	 // Doble onda cruzada

	// Circulos
	bool FitInInters; // Forzar a incluir circulos en las intersecciones

	// Textos
	TSE_TextData SE_TextData;

	bool InBaseShape; // Insertada en la BaseShape o independiente

	// Lineas base
	int Symmetric; // Trata de hacer la marca o el suavizado simetrico en 2D, si se dan las condiciones SE_SHAPES_SOFTEN y SE_SHAPES_MARK

	int ShapeType; // Subtipo dentro de cada tipo SHAPES.

	// SE_SHAPES_MARGIN:
	TParallelData ParallelData; // Datos del margen.
	TShapeElement *BaseSE;		// Elemento de la linea base del margen.
	TShapeElement *AreaSE;		// Elemento area que se crea al anyadir el margen.

	// SE_SHAPES_MARK:
	bool PerpToBaseShape; // "perpendicular al contorno" cuando sea marca en interseccion,

	// SE_SHAPES_FESTOON
	bool IncludeHoles;
	double RoundInsides; // Redondear interiores en festones tipo 3

	// SE_SHAPES_SYMBOLIC:
	bool TensWith;
	bool OwnSymbolic, SymbolicUsePunches;
	double LineSize;
	double SmallPct;
	TNDoublesList SymbolicSizes;
	TUnicodeStringList SymbolicTypes;

	// SE_AREA:
	TOGLMaterial Mat;

	// SE_SHAPES_SOFTEN:     Las distancias izquierda y derecha se tratan en Values del DOM
	bool UseArcShape;

	// SE_SHAPES_INSIDE
	TOGLPolygonList Shape; // Figura

	// Costing
	TSE_Costing *SE_Costing;
};

//------------------------------------------------------------------------------

class TShapeElementList
{
	friend class TImpExp_XML;

  public:
	TShapeElementList( );
	virtual ~TShapeElementList( );

	virtual void Set( TShapeElementList *E );

	virtual void AddItem( TShapeElement *s );
	virtual void SetItem( int ind, TShapeElement *s );
	virtual void SetItemByType( int type, int ind, TShapeElement *s );
	virtual void DelItem( int ind );
	virtual void DelItemByType( int type, int ind );
	virtual TShapeElement *GetItem( int ind );
	virtual TShapeElement *GetItemByType( int type, int ind );
	virtual void Clear( );
	virtual int Count( );
	virtual void Grow( int d );

	virtual int GetIndex( int type, int indexbytype );
	virtual int GetIndexByType( int type, int index );

	virtual int GetCurrentIndex( );
	virtual void SetCurrentIndex( int );
	virtual TShapeElement *GetCurrentItem( );
	virtual void SetCurrentItem( TShapeElement * );

	virtual void GetDXFLayersInfo( TUnicodeStringList *layers, TInteger_List *selinesindexes, TInteger_List *secirclesindexes );
	virtual void SetDXFLayersInfo( TUnicodeStringList *layers, TInteger_List *selinesindexes, TInteger_List *secirclesindexes );

	virtual void Write( UnicodeString file );
	virtual void Read( UnicodeString file );

	virtual bool ReplaceTool2DTypes( TMachine2DList *machine2dlist, int machine2dindex, int tool2dtype1, int tool2dtype2 );

  protected:
	int numItems, maxItems, curItem;
	TShapeElement *Item;
};

//------------------------------------------------------------------------------

#define SPI_TYPE_NATURAL 0
#define SPI_TYPE_SHARP	 1

class TStipplePatternItem
{
	friend class TImpExp_XML;

  public:
	TStipplePatternItem( );
	~TStipplePatternItem( )
	{
	}

	virtual void Set( TStipplePatternItem *data );
	virtual bool IsEqual( TStipplePatternItem *data );
	virtual bool IsValid( );

	virtual void Clear( );

	virtual bool CalcItemHole( TOGLTransf *, TOGLPolygonList *List, double qualityfactor = 1.0 );
	virtual bool CalcItem( TOGLTransf *OGLTransf, TOGLMaterial *mat, TOGLPolygonList *List, double qualityfactor = 1.0 );

	virtual void Write( UnicodeString str = EmptyStr, TMemIniFile *local_file = 0, UnicodeString file = EmptyStr );
	virtual void Read( UnicodeString str = EmptyStr, TMemIniFile *local_file = 0, UnicodeString file = EmptyStr );

  public:
	int Type;
	bool Hole;
	double Width;
	double Height;
	double Length;

	bool CloseHoles; // no se escribe, solo cierra caras cuando interesa
};

//------------------------------------------------------------------------------

#define SP_TYPE_SIMPLE		  0
#define SP_TYPE_DOUBLE		  1
#define SP_TYPE_TRIPLE		  2

#define SP_STYLE_NORMAL		  0
#define SP_STYLE_ZIGZAG		  1
#define SP_STYLE_CROSS		  2
#define SP_STYLE_L			  3

#define BITMAP_SP_WIDTH_SMALL 30
#define BITMAP_SP_WIDTH_HALF  50
#define BITMAP_SP_WIDTH_LARGE 70

class TStipplePatternData
{
	friend class TImpExp_XML;

  public:
	TStipplePatternData( );
	~TStipplePatternData( )
	{
	}

	virtual void Set( TStipplePatternData *data, bool calcholes = true, bool baseentityindex = true );
	virtual bool IsEqual( TStipplePatternData *data, bool calcholes = true, bool baseentityindex = true );
	virtual bool IsValid( );

	virtual void Clear( );

	virtual void Write( UnicodeString *_file, UnicodeString *orgfileimage );
	virtual void Read( UnicodeString *file, UnicodeString *pathmat, UnicodeString *pathownsimplematerialslibrary );

  protected:
	virtual void WriteSWG( UnicodeString *file );
	virtual void ReadSWG( UnicodeString *file, UnicodeString *pathmat, UnicodeString *pathownsimplematerialslibrary );

  public:
	UnicodeString Name;
	TStipplePatternItem Item;
	// Datos de la distribucion
	int Type;
	int Style;
	double ItemDistance;
	double ItemAngle;
	double PatternDistance;
	int ItemGroupCount;
	double GroupDistance;
	double LengthFactor;

	double Offset3D;
	double Offset3DSecondary;
	bool CalcHoles;		 // Se usa en TCadDepMesh. Indica si se calculan los agujeros o el item de cada TStipplePatternItem
	int BaseEntityIndex; // Se usa en TCadDepMesh. Indica en cual de las depmesh base recae el TStipplePattern.

	int MaxStitches; // n maximo de items en el patron. si es 0, no se tiene en cuenta

	TOGLMaterial Material;
	bool UseMaterialOnCreate;
	bool BOMActive;
};

//------------------------------------------------------------------------------

#define EPT_NONE		 0
#define EPT_3DPLANE		 1
#define EPT_3PTS		 2
#define EPT_2PTSPLANE	 3
#define EPT_PTNORMAL	 4 // se toma el primer punto de la shape como PT y el segundo como NORMAL

#define EPR_CENTER		 0
#define EPR_EXTREME		 1

#define EPS_SEGMENT_BOTH 0
#define EPS_SEGMENT_1	 1
#define EPS_SEGMENT_2	 2

class TEditPlaneData
{
	friend class TImpExp_XML;

  public:
	TEditPlaneData( );
	~TEditPlaneData( )
	{
	}

	virtual void Set( TEditPlaneData *data );
	virtual void Clear( );
	virtual bool IsValid( );

	virtual bool CalcPlane( TOGLTransf *OGLTransf, TCadShape *shape );
	virtual bool IsPointUsed( int index );
	virtual void UpdateAddPoint( int index );
	virtual void UpdateDeletePoint( int index );

  public:
	int Type;
	T3DPlane Plane;
	TNPlane OrgPlane;
	int OrgPts[ 3 ];

	int RotateMode;
	bool CanRotate;
	bool CanMove;
	bool ShowCircles[ 3 ];
	int ShowSegmentSide;
	int ShowNormal; // 0 NO, 1 SI, 2 SI Ambos lados
	double SizeDrawNormal;

	double RotAngle;
	T3DVector RotVector;
};

//------------------------------------------------------------------------------
//  TIntersectPlaneData
//------------------------------------------------------------------------------

#define FORCE_PT_MINZ			  0
#define FORCE_PT_0				  1
#define FORCE_PT_CENTER_EDITPLANE 2

#define FORCE_DM_OGLTRANSF		  0
#define FORCE_DM_NONE			  1
#define FORCE_DM_ONLYDEF		  2

class TIntersectPlaneData
{
  public:
	TIntersectPlaneData( );
	~TIntersectPlaneData( )
	{
	}

	virtual void Set( TIntersectPlaneData *data );
	virtual bool IsEqual( TIntersectPlaneData *data );

	virtual bool GetViewInPlane( TNPlane plane );
	virtual void SetViewInPlane( TNPlane plane, bool value );

  public:
	double DistanceToPlane;
	bool ViewInPlane[ 3 ];
	TNPlane ForcePlane;
	int ForceRotPointType;
	int ForceDeformerMode;
	bool UseForceStartPoint, ForceOnePolygon, ForceClose;
	T3DPoint ForceStartPoint;
};

//------------------------------------------------------------------------------
//  TBoxPlaneData
//------------------------------------------------------------------------------

class TBoxPlaneData
{
  public:
	TBoxPlaneData( );
	~TBoxPlaneData( )
	{
	}

	virtual void Set( TBoxPlaneData *data );
	virtual bool IsEqual( TBoxPlaneData *data );

	virtual bool GetViewInPlane( TNPlane plane );
	virtual void SetViewInPlane( TNPlane plane, bool value );

  public:
	double Border;
	bool ShowBorder;

	// Variable auxiliar usada para calcular los bordes de un BoxPlaneData
	T3DPoint BorderPoints[ 4 ];

	TNPlane Direction; // plano de interseccion para recortar el plano 3D
	bool ViewInPlane[ 3 ];
};

//------------------------------------------------------------------------------
//  TLocation3DData
//------------------------------------------------------------------------------

#define L3D_TYPE_NORMAL 0
#define L3D_TYPE_ONLINE 1

#define SIDE_BOTH		-1
#define SIDE_CURRENT	0
#define SIDE_OTHER		1

class TLocation3DData
{
  public:
	TLocation3DData( );
	~TLocation3DData( )
	{
	}

	virtual void Set( TLocation3DData *data );
	virtual bool IsEqual( TLocation3DData *data );

	int GetNumBySide( int index );
	void SetNumBySide( int index, int n );

	bool WriteDataXML( _di_IXMLNode xmlNode );
	bool ReadDataXML( _di_IXMLNode xmlNode );

  public:
	int Type;
	bool OnSurface; // para tipo L3D_TYPE_NORMAL

	int BaseEntityIndex; // Se usa en TCadDepMesh. Indica en cual de las entidades base recae el objeto.

	double Offset;
	double Angle[ 3 ];
	double ScaleFactor;
	bool Symmetric;

	bool BOMActive;
	int NumBySide[ 2 ];

	bool Online_AdaptTexture;
};

//------------------------------------------------------------------------------
//  TLocation3DEntitiesData
//------------------------------------------------------------------------------

class TCadDepMesh;

class TLocation3DEntitiesData
{
  public:
	TLocation3DEntitiesData( );
	~TLocation3DEntitiesData( );

	virtual void Set( TLocation3DEntitiesData *data );
	//		virtual bool IsEqual( TLocation3DEntitiesData *data );

	virtual void CreateEntities( );
	virtual TCadGroup *GetEntities( )
	{
		return Entities;
	}
	virtual void SetEntities( TCadGroup * );
	virtual TNMatrix *GetPosMatrix( )
	{
		return &PosMatrix;
	}
	virtual void SetPosMatrix( TNMatrix *mat );
	virtual T3DRect GetBoundRect( )
	{
		return BoundRect;
	}
	virtual void SetBoundRect( T3DRect r );

	virtual void GetOGLList( TOGLTransf *OGLTransf, TOGLPolygonList *ogllist, TNMatrix *mat, T3DRect *r, TOGLPolygonList *orgTextureUVCoords, TCadDepMesh *depmesh );
	virtual void GetTextureCoords( TOGLTransf *, TOGLTexture *, TOGLPolygonList * );
	virtual void GetBaseTextureCoords( TOGLTransf *OGLTransf, TOGLPolygonList *ogltexturelist );

  public:
	TCadGroup *Entities;
	TNMatrix PosMatrix;
	T3DRect BoundRect; // utilizado para desplazar en la distribucion con separacion
	double Smooth;	   // utilizado en el tipo online para el suavizado de externalsection
};

//------------------------------------------------------------------------------
//  TEditShapesData
//------------------------------------------------------------------------------

class TEditShapesData
{
  public:
	TEditShapesData( );
	~TEditShapesData( );

	virtual void Set( TEditShapesData *data );
	virtual bool IsEqual( TEditShapesData *data );

  public:
	double Radius;

	double Length;
	double Width;
	double Height;
	double Angle;

	double CurvatureX;
	double CurvatureY;

	int NumSides;
	int NumEnds;
	double RatioInt;
	double RatioExt;

	bool FixedRadius, FixedSize;

	double MoveDist;
	bool MoveAsOrthoDist;
};

//------------------------------------------------------------------------------
//  TGordonProfileData
//------------------------------------------------------------------------------
// no cambiar, se utilizan en los combos del interface
#define GPD_TYPE_POINTS 0
#define GPD_TYPE_ARC	1

class TGordonProfileData
{
  public:
	TGordonProfileData( );
	~TGordonProfileData( );

	virtual void Clear( );
	virtual void Set( TGordonProfileData *data );
	virtual bool IsEqual( TGordonProfileData *data );

  public:
	int Type;
	double Angle;
	double Distance;
};

//------------------------------------------------------------------------------
//  TPivotData
//------------------------------------------------------------------------------

class TPivotData
{
  public:
	TPivotData( );
	TPivotData( TPivotData *p );
	~TPivotData( );

	virtual void Set( TPivotData *pivot );

	virtual void SetOrg( T3DPoint *org );
	virtual void SetRefSystem( T3DSize axisX, T3DSize axisY, T3DSize axisZ );

	virtual T3DPoint *GetOrg( );
	virtual void GetRefSystem( T3DSize &axisX, T3DSize &axisY, T3DSize &axisZ );
	virtual void ApplyMatrix( TNMatrix mat, bool apply_org = true, bool apply_refsystem = true );

  private:
	T3DPoint Org;
	T3DSize AxisX;
	T3DSize AxisY;
	T3DSize AxisZ;
};

//------------------------------------------------------------------------------
// TEnvelope
//------------------------------------------------------------------------------

class TEnvelope
{
	friend class TImpExp_XML;

  public:
	TEnvelope( bool destroyenvelopemesh = true );
	virtual ~TEnvelope( );

	void CleanPointers( );

	virtual int GetType( )
	{
		return -1;
	}

	void SetDirty( bool b );

	TCadMesh *GetMesh( TOGLTransf *OGLTransf, TCadGroup *entities, bool force = true );
	void SetMesh( TCadMesh *mesh );

	void SetMeshOGLRenderData( TCadMesh *mesh );

	virtual void Set( TEnvelope * );

  protected:
	virtual bool Calculate( TOGLTransf *OGLTransf, TCadGroup *entities )
	{
		return false;
	}

  protected:
	bool DestroyMesh;
	bool IsDirty;

	TCadMesh *Mesh;
};

//------------------------------------------------------------------------------

class TEnvelope_BBox : public TEnvelope
{
	friend class TImpExp_XML;

  public:
	TEnvelope_BBox( bool destroyenvelopemesh = true );
	~TEnvelope_BBox( );

	void Set( TEnvelope * );

	int GetType( )
	{
		return ENVELOPE_TYPE_BBOX;
	}

	void SetBBoxType( int type );
	int GetBBoxType( );

	void SetRowsX( int rowsx );
	void SetRowsY( int rowsy );
	void SetRowsZ( int rowsz );
	int GetRowsX( );
	int GetRowsY( );
	int GetRowsZ( );

	TNDoublesList *GetPctsX( )
	{
		return &PctsX;
	}
	TNDoublesList *GetPctsY( )
	{
		return &PctsY;
	}
	TNDoublesList *GetPctsZ( )
	{
		return &PctsZ;
	}

	T3DPoint GetDataOrigBox( int ind );
	T3DPoint GetCenter( );
	double GetWidth( );
	double GetHeight( );
	double GetDepth( );
	T3DVector GetWidthDirection( );
	T3DVector GetHeightDirection( );
	T3DVector GetDepthDirection( );

  protected:
	bool Calculate( TOGLTransf *OGLTransf, TCadGroup *entities );

	void SetDataBoxBasicFromOrig( );

  protected:
	int BboxType;
	int RowsX, RowsY, RowsZ;
	TNDoublesList PctsX, PctsY, PctsZ;
	T3DPoint DataBoxBasic[ 6 ][ 4 ];
	T3DPoint DataBoxOrig[ 8 ];
};

//------------------------------------------------------------------------------

class TEnvelope_Normalized : public TEnvelope
{
	friend class TImpExp_XML;

  public:
	TEnvelope_Normalized( bool destroyenvelopemesh = true );
	~TEnvelope_Normalized( );

	void Set( TEnvelope * );

	int GetType( )
	{
		return ENVELOPE_TYPE_NORMALIZED;
	}

	void SetPps( int pps );
	void SetStep( float step );
	void SetOffset( float offset );
	void SetRadiusTool( float rad );
	void SetReductionFactorStep( float rfs );

	int GetPps( );
	float GetStep( );
	float GetOffset( );
	float GetRadiusTool( );
	float GetReductionFactorStep( );

  protected:
	bool Calculate( TOGLTransf *OGLTransf, TCadGroup *entities );

	bool GetPlanarSectionsFromGeometry( TOGLTransf *OGLTransf, T3DPolygonList *in, T3DPlane *originalPlane, T3DPolygonList *out );

  protected:
	int Pps;
	float Offset, Step, RadiusTool, ReductionFactorStep;
};

//------------------------------------------------------------------------------

class TEnvelope_PolyCube : public TEnvelope
{
	friend class TImpExp_XML;

  public:
	TEnvelope_PolyCube( bool destroyenvelopemesh = true );
	~TEnvelope_PolyCube( );

	void Set( TEnvelope * );

	int GetType( )
	{
		return ENVELOPE_TYPE_POLYCUBE;
	}

	void SetCubeSizeX( int csizeX );
	void SetCubeSizeY( int csizeY );
	void SetCubeSizeZ( int csizeZ );

	int GetCubeSizeX( );
	int GetCubeSizeY( );
	int GetCubeSizeZ( );

	TNDoublesList *GetPctsX( )
	{
		return &PctsX;
	}
	TNDoublesList *GetPctsY( )
	{
		return &PctsY;
	}
	TNDoublesList *GetPctsZ( )
	{
		return &PctsZ;
	}

  protected:
	bool Calculate( TOGLTransf *OGLTransf, TCadGroup *entities );

  protected:
	int CubeSizeX, CubeSizeY, CubeSizeZ;
	TNDoublesList PctsX, PctsY, PctsZ;
};

//------------------------------------------------------------------------------

class TEnvelope_RegularNode
{
  public:
	TEnvelope_RegularNode( )
	{
	}

	void Set( TEnvelope_RegularNode );

	bool CalculateCentroide( );

  public:
	vector<T3DPoint *> Points;
	T3DPoint Center, Centroide;
};

//------------------------------------------------------------------------------

class TEnvelope_Regular : public TEnvelope
{
	friend class TImpExp_XML;

  public:
	TEnvelope_Regular( bool destroyenvelopemesh = true );
	~TEnvelope_Regular( );

	void Set( TEnvelope * );

	int GetType( )
	{
		return ENVELOPE_TYPE_REGULAR;
	}

	void SetSize( float size );
	float GetSize( );

  protected:
	bool Calculate( TOGLTransf *OGLTransf, TCadGroup *entities );
	bool CalculateExtremes( TOGLTransf *OGLTransf, TCadGroup *entities );

  protected:
	TriangulateDelaunay *Triangulator;
	TEnvelope_RegularNode *SuperNode;
	vector<TEnvelope_RegularNode *> Subdivisions;
	vector<T3DPoint> Centroides;

	float Size;

	float fXMin, fYMin, fZMin;
	float fXMax, fYMax, fZMax;
	float difX, difY, difZ;
};

//------------------------------------------------------------------------------
// TRotationData
//------------------------------------------------------------------------------

class TRotationData
{
  public:
	TRotationData( );
	~TRotationData( )
	{
	}

	virtual void Clear( );
	virtual void Set( TRotationData *data );
	virtual bool IsEqual( TRotationData *data );

  public:
	int Type;			   // ROTATIONDATA_TYPE_ANGLE, ROTATIONDATA_TYPE_INCR, ROTATIONDATA_TYPE_AXIS, ROTATIONDATA_TYPE_CURVE
	double Angle;		   // ROTATIONDATA_TYPE_ANGLE
	double Incr;		   // ROTATIONDATA_TYPE_INCR
	double SmoothDistance; // ROTATIONDATA_TYPE_ANGLE, ROTATIONDATA_TYPE_INCR, ROTATIONDATA_TYPE_AXIS
	double Distribution;   // ROTATIONDATA_TYPE_AXIS ( 0 como RotOrg y 1 como RotBase )
};

//------------------------------------------------------------------------------
// TRotationPoint
//------------------------------------------------------------------------------

class TRotationPoint
{
	friend class TImpExp_XML;

  public:
	TRotationPoint( );
	~TRotationPoint( );

	void Set( TRotationPoint * );
	bool IsValid( );

	void SetName( UnicodeString str )
	{
		Name = str;
	}
	UnicodeString GetName( )
	{
		return Name;
	}

	bool SetEntities( TCadGroup *group );
	TCadGroup *GetEntities( )
	{
		return Entities;
	}
	void InsertEntity( TCadEntity *ent, int index = -1 );

	TCadGroup *GetRefEntities( )
	{
		return RefEntities;
	}
	void InsertRefEntity( TCadEntity *ent, int index = -1 );

	TCadGroup *GetOtherEntities( )
	{
		return OtherEntities;
	}
	void InsertOtherEntity( TCadEntity *ent, int index = -1 );

	void SetRotShape1( TCadShape *shape );
	TCadShape *GetRotShape1( )
	{
		return RotShape1;
	}
	void SetRotShape2( TCadShape *shape );
	TCadShape *GetRotShape2( )
	{
		return RotShape2;
	}

	void SetRotZone1( TCadShape *shape );
	TCadShape *GetRotZone1( )
	{
		return RotZone1;
	}
	void SetTessRotZone1( TCadTessPolygon *tess );
	TCadTessPolygon *GetTessRotZone1( )
	{
		return TessRotZone1;
	}

	void SetRotZone2( TCadShape *shape );
	TCadShape *GetRotZone2( )
	{
		return RotZone2;
	}
	void SetTessRotZone2( TCadTessPolygon *tess );
	TCadTessPolygon *GetTessRotZone2( )
	{
		return TessRotZone2;
	}

	void SetRotAxis( TCadShape *shape );
	TCadShape *GetRotAxis( )
	{
		return RotAxis;
	}

	void SetData( TRotationData *data );
	TRotationData *GetData( )
	{
		return &Data;
	}

	int GetType( )
	{
		return Data.Type;
	}
	void SetType( int type );

	bool IsAngleType( );
	bool IsIncrType( );
	bool IsAxisType( );
	bool IsCurveType( );

	void SetAngle( double angle );
	double GetAngle( )
	{
		return Data.Angle;
	}

	void SetIncr( double incr );
	double GetIncr( )
	{
		return Data.Incr;
	}

	void SetSmoothDistance( double dist );
	double GetSmoothDistance( )
	{
		return Data.SmoothDistance;
	}

	void SetDistribution( double dist );
	double GetDistribution( )
	{
		return Data.Distribution;
	}

	void SetBaseIndex( int index );
	int GetBaseIndex( )
	{
		return BaseIndex;
	}

	void SetForceUnlocked( bool b );
	bool GetForceUnlocked( )
	{
		return ForceUnlocked;
	}

	bool IsEntityIncluded( TCadEntity *ent );
	bool IsAuxEntityIncluded( TCadEntity *ent );
	void UpdateAuxEntitiesColors( TColor *AuxEntityColor, TCadEntity *Ent = 0 );

	bool EraseEntity( TCadEntity *ent );
	void SetTempNameToRestore( TCadEntity *ent, int rotIndex );
	void RestoreEntity( TCadEntity *ent, int rotIndex );
	void ChangeRelatedEntity( TCadEntity *orgent, TCadEntity *dstent );

	void SetEntitiesRotationData( );
	void SetEntitiesDirty( );

	bool HasDepRotationEntities( );
	void GetBaseAndAuxEntities( TCadGroup *grp );
	void GetAllBaseEntities( TCadGroup *baseshapes, TCadGroup *rotdepshapes, TCadShape *baseshape = 0, TCadDepShape *rotdepshape = 0 );

  protected:
	UnicodeString Name;
	TRotationData Data;

	TCadGroup *Entities;
	TCadGroup *RefEntities;
	TCadGroup *OtherEntities;
	TCadShape *RotShape1;			// ROTATIONDATA_TYPE_ANGLE (TCadPoint); ROTATIONDATA_TYPE_INCR (TCadLine); ROTATIONDATA_TYPE_AXIS (TCadDepShape Copy), ROTATIONDATA_TYPE_CURVE (TCadDepShape Copy)
	TCadShape *RotShape2;			// ROTATIONDATA_TYPE_AXIS (TCadDepShape Copy), ROTATIONDATA_TYPE_CURVE (TCadDepShape Copy)
	TCadShape *RotZone1, *RotZone2; // ROTATIONDATA_TYPE_ANGLE, ROTATIONDATA_TYPE_INCR (ConstantZone, EditedZone); ROTATIONDATA_TYPE_AXIS, ROTATIONDATA_TYPE_CURVE (UnfoldLockedZones)
	TCadTessPolygon *TessRotZone1, *TessRotZone2;
	TCadShape *RotAxis; // ROTATIONDATA_TYPE_AXIS (TCadDepShape Pct)

	int BaseIndex;
	bool ForceUnlocked;
};

//------------------------------------------------------------------------------
// TRotationPointList
//------------------------------------------------------------------------------

class TRotationPointList
{
	friend class TImpExp_XML;

  public:
	TRotationPointList( );
	~TRotationPointList( );

	void GetNextRotationPointName( TRotationPoint *rotpt, UnicodeString baseName );

	void Clear( bool del = true );

	int Count( );
	TRotationPoint *GetItem( int index );

	void AddItem( TRotationPoint *rotpt );
	void InsertItem( int ind, TRotationPoint *rotpt );
	void DelItem( int index, bool del = true );
	void ReplaceItems( int indexOrg, int indexDst );

	void GetDownRelated( int ind, TInteger_List *list, bool first = true );
	void GetUpRelatedUntilLastVersionEntity( int ind, TCadEntity *Ent, TInteger_List *list, bool first = true );
	TCadEntity *GetEntityByVersion( int ind, TCadEntity *Ent, bool forward = false );
	bool IsVisibleDepRotation( int ind, TCadDepShape *depshape );
	void GetBaseAndAuxEntities( int ind, TCadGroup *grp );
	bool IsUpAuxEntity( int ind, TCadEntity *ent );

	void SetCurIndex( int ind );
	int GetCurIndex( )
	{
		return CurIndex;
	}
	TRotationPoint *GetCurItem( )
	{
		return GetItem( CurIndex );
	}

	bool EraseEntity( TCadEntity *ent );
	void SetTempNameToRestore( TCadEntity *ent );
	void RestoreEntity( TCadEntity *ent );
	void ChangeRelatedEntity( TCadEntity *orgent, TCadEntity *dstent );

	bool IsInitialEntity( TCadEntity *Ent, int index = -1 );
	bool IsSelectableEntity( TCadEntity *ent, int index = -1, bool checkentities = true );
	bool IsAuxEntityIncluded( TCadEntity *ent );

	void SetAuxEntityColor( int index, TColor c, bool writeinifile );
	TColor GetAuxEntityColor( int index );
	void UpdateAuxEntitiesColors( TCadEntity *Ent = 0 );

	bool IsLocked( int ind, bool useforce = true );
	bool IsCurLocked( bool useforce = true );

  protected:
	vector<TRotationPoint *> RotationPoints;
	int CurIndex;

	TColor AuxEntityColor[ 3 ];
};

//------------------------------------------------------------------------------
// TPctData
//------------------------------------------------------------------------------

class TPctData
{
  public:
	TPctData( );
	~TPctData( )
	{
	}

	virtual void Clear( );
	virtual void Set( TPctData *data );
	virtual bool IsEqual( TPctData *data );

  public:
	int Type;			  // PCTDATA_TYPE_TANGENT, PCTDATA_TYPE_PERP
	double Length;		  // si es < 0, misma longitud que la base
	int PointMarkerIndex; // si >= 0 indice del marker del que se extrae BasePct;
	double BasePct;		  // 0..1, posicion en la curva base
	double OwnPct;		  // 0..1, (0.5 mitad de longitud a cada lado del punto de enlace)
	double ExtendDist;
	bool LinkPcts; // Si es true, OwnPct no tiene efecto y se considera como BasePct
	bool IsAxis;
};

//------------------------------------------------------------------------------
// TCopyData
//------------------------------------------------------------------------------

class TCopyData
{
  public:
	TCopyData( );
	~TCopyData( )
	{
	}

	virtual void Clear( );
	virtual void Set( TCopyData *data );
	virtual bool IsEqual( TCopyData *data );

  public:
	int ForceMode;			   // VIEW_NONE, VIEW_GEOM3D, VIEW_PARAM2D, VIEW_DEVELOP2D
	bool OnlyOneShape;		   // Solo una entidad o varias entidades juntas
	bool UseTrimZones;		   // Hay entidades base adicionales (zonas) que recortan la entidad
	int TrimByLineMarkerIndex; // La entidad base es recortada por un line marker
	TNMatrix Matrix;		   // Matriz a aplicar si ForceMode != VIEW_NONE
};

//------------------------------------------------------------------------------
// TCopyListData
//------------------------------------------------------------------------------

class TCopyListData
{
  public:
	TCopyListData( );
	~TCopyListData( )
	{
	}

	virtual void Clear( );
	virtual void Set( TCopyListData *data );

  public:
	bool FillList;

	// Si se ve que provoca uso de memoria excesivo, meterlo en una clase y ponerlo dependiente de UseText
	bool UseText;
	UnicodeString Text;
	T3DPoint TextPt1, TextPt2;
	double TextHeight;
	LOGFONT LogFont;
	bool IsSimpleText, UseAsSimple;
	int ToolType;
	bool Invert;
};

//------------------------------------------------------------------------------
// TReallocateData
//------------------------------------------------------------------------------

class TReallocateData
{
  public:
	TReallocateData( );
	~TReallocateData( )
	{
	}

	virtual void Clear( );
	virtual void Set( TReallocateData *data );
	virtual bool IsEqual( TReallocateData *data );

  public:
	bool DoSymmetry;
	bool InvertDevelopSide;
};

//------------------------------------------------------------------------------
// TGrading2D
//------------------------------------------------------------------------------

class TGrading2D
{
  public:
	TGrading2D( );
	virtual ~TGrading2D( )
	{
	}

	virtual void Clear( );
	virtual void Set( TGrading2D *data );
	virtual bool IsEqual( TGrading2D *data );

	virtual void Grade( TOGLTransf *, TCadEntity * )
	{
	}
	virtual void Locate( TOGLTransf *, TCadEntity * )
	{
	}

  public:
	;
};

//------------------------------------------------------------------------------
// TGrading2DData
//------------------------------------------------------------------------------

class TGrading2DData
{
  public:
	TGrading2DData( );
	virtual ~TGrading2DData( )
	{
	}

	virtual void Clear( );
	virtual void Set( TGrading2DData *data );
	virtual bool IsEqual( TGrading2DData *data );

  public:
	TGrading2D *Grading2D;

	int Surface;
	int Index1, Index2, Index3, Index4, Index5;
};

//------------------------------------------------------------------------------
// TCenterLineData
//------------------------------------------------------------------------------

#define CLM_DISTANCE 0
#define CLM_PERCENT	 1
#define CLM_PERCENT2 2

class TCenterLineData
{
  public:
	TCenterLineData( );
	~TCenterLineData( )
	{
	}

	virtual void Clear( );
	virtual void Set( TCenterLineData *data );
	virtual bool IsEqual( TCenterLineData *data );

  public:
	int Method;
	double Distribution;
};

//------------------------------------------------------------------------------
// TAngleLineData
//------------------------------------------------------------------------------

class TAngleLineData
{
  public:
	TAngleLineData( );
	~TAngleLineData( )
	{
	}

	virtual void Clear( );
	virtual void Set( TAngleLineData *data );
	virtual bool IsEqual( TAngleLineData *data );

  public:
	double Angle, Length, Pct, Pct2;
	bool Centered, Invert, TwoLinks, AsAxis;
	TNPlane Plane;
	int BaseShapeIndex1, BaseShapeIndex2;
	int IntersectIndex1, IntersectIndex2;

	bool Dependent;
	double MultipleDist;
};

//------------------------------------------------------------------------------
// TSmoothInterData
//------------------------------------------------------------------------------

class TSmoothInterData
{
  public:
	TSmoothInterData( );
	~TSmoothInterData( )
	{
	}

	virtual void Clear( );
	virtual void Set( TSmoothInterData *data );
	virtual bool IsEqual( TSmoothInterData *data );

  public:
	double Pct, Pct2;
	int Sense, Sense2; // sentido, -1: no asignado, 0: sentido creciente, 1: sentido decreciente
	bool KeepDistanceInGrading;

	int ShapeType;
	bool Invert, UseArcShape;
	TNDoublesList Values;

	bool IsGrading; // Temporal
};

//------------------------------------------------------------------------------
// TIntersectPointData
//------------------------------------------------------------------------------

class TIntersectPointData
{
  public:
	TIntersectPointData( );
	~TIntersectPointData( )
	{
	}

	virtual void Clear( );
	virtual void Set( TIntersectPointData *data );
	virtual bool IsEqual( TIntersectPointData *data );

  public:
	double Pct, Pct2;
};

//------------------------------------------------------------------------------
// TDistanceData
//------------------------------------------------------------------------------

#define DIST_EDGE_FREE		0
#define DIST_EDGE_NODE		1
#define DIST_EDGE_NEAR		2
#define DIST_EDGE_INTERSECT 3
#define DIST_EDGE_FIXED		4

#define DIST_TYPE_LINE		0
#define DIST_TYPE_ORTHO		1
#define DIST_TYPE_OVER		2

#define DIST_MARK_NONE		0
#define DIST_MARK_TEMP		1
#define DIST_MARK_PERM		2

#define DIST_LIST_2D		0x01
#define DIST_LIST_3D		0x02
#define DIST_LIST_2D3D		0x04
#define DIST_LIST_3D2D		0x08
#define DIST_LIST_MARK		0X10

class TDistanceData
{
  public:
	TDistanceData( );
	virtual ~TDistanceData( );
	virtual void Clear( );
	virtual void Set( TDistanceData *data );

	virtual TOGLPolygonList *GetAcumDistanceListDev( )
	{
		return &AcumDistanceListDev;
	}
	virtual void SetAcumDistanceListDev( TOGLPolygonList *list )
	{
		AcumDistanceListDev.Set( list );
	}

	virtual TOGLPolygonList *GetAcumDistanceListParam( )
	{
		return &AcumDistanceListParam;
	}
	virtual void SetAcumDistanceListParam( TOGLPolygonList *list )
	{
		AcumDistanceListParam.Set( list );
	}

	virtual vector<int> *GetAcumDistUndoType( )
	{
		return &AcumDistUndoType;
	}

	virtual bool CanChangeDirOverLine( bool otherpct )
	{
		return ( OverLineStartPct - otherpct ) < 0.25;
	}

	virtual void SetDistance( double d, bool force = false );
	virtual double GetDistance( )
	{
		return Distance;
	}

	virtual void SetUseMark( int um );
	virtual int GetUseMark( )
	{
		return UseMark;
	}

	virtual TCadPoint *GetMarkPoint( )
	{
		return MarkPoint;
	}
	virtual void SetMarkPoint( T3DPoint *, TOGLTransf * );
	virtual void ClearMarkPoint( );

	void SetCandidateEnts( TCadGroup *gr );
	TCadGroup *GetCandidateEnts( )
	{
		return CandidateEnts;
	}
	int GetCurCandidateIndex( )
	{
		return CurCandidateIndex;
	}
	void SetCurCandidateIndex( int index )
	{
		CurCandidateIndex = index;
	}

	virtual void ClearDistances( );
	virtual void ClearAcumDistance( );
	virtual void ClearCandidateEnts( );
	virtual void EnableAcumDistance( bool );

	virtual void CalcAdditionalInfoStr( vector<UnicodeString> *strVec );

	virtual double GetValueToShow( double );
	virtual double GetRealValue( double );

  public:
	int StartType, EndType, LineType;
	int OrthoMovingAxis; // -1 ninguno; 0 X, 1 Y, 2 Z

	bool Acumulative, AdditionalInfo, Is2D;
	double DualDistance, Total;
	TOGLFloat3 Incr;
	TColor Color;

	int OverLineDirection;
	double OverLineStartPct;

	bool ShowInInches;

  private:
	int UseMark;
	double Distance;
	TOGLPolygonList AcumDistanceListDev, AcumDistanceListParam;
	vector<int> AcumDistUndoType;

	TCadGroup *CandidateEnts;
	int CurCandidateIndex;

	TCadPoint *MarkPoint;
};

//------------------------------------------------------------------------------
//  TTessPolygonTempOGLLists
//------------------------------------------------------------------------------

class TTessPolygonTempOGLLists
{
  public:
	TTessPolygonTempOGLLists( );
	~TTessPolygonTempOGLLists( );

	void Set( TTessPolygonTempOGLLists *data );
	void Clear( );
	bool IsUsed( );

  public:
	TOGLPolygonList OGLBoundariesList, NotTrimCurvesOGLList, OGLList;
	TOGLPolygonList OGLBoundariesListToInvert, NotTrimCurvesOGLListToInvert, OGLListToInvert;
};

//------------------------------------------------------------------------------
// TSubdivisionData
//------------------------------------------------------------------------------

class TSubdivisionData
{
  public:
	TSubdivisionData( );
	virtual ~TSubdivisionData( );

	virtual void Clear( );
	virtual void Set( TSubdivisionData *data );
	virtual bool IsEqual( TSubdivisionData *data );

	void UpdateOrgPols( TOGLPolygon *polvertexs, TOGLPolygon *poledges, TOGLPolygon *polfaces, TOGLPolygon *pol );
	void ClearOrgPols( );

  public:
	int Level;
	bool RecalcTopology;
	bool RebuildFromLevel0;
	bool Dragging;
	bool RecalcColorsInDragging;
	bool RecalcPolVertexs;
	bool RecalcPolEdges;
	bool RecalcPolFaces;
	bool InitEdition, Editing;
	bool ForceTriangles;

	TOGLPolygon OrgVertexs, OrgEdges, OrgFaces, OrgPol;
	int norgarray;
	int3 *orgarray;

	IwTA<IwTA<IwPolyEdge *> > CreaseList;
	IwTA<IwTA<IwPolyFace *> > GroupsOfFaces1, GroupsOfFaces2;
};

//------------------------------------------------------------------------------
// TDevelopMeshData
//------------------------------------------------------------------------------

#define DMD_TYPE_0 0
#define DMD_TYPE_1 1

class TDevelopMeshData
{
  public:
	TDevelopMeshData( );
	virtual ~TDevelopMeshData( )
	{
	}

	virtual void Clear( int Version );
	virtual void Set( TDevelopMeshData *data );
	virtual bool IsEqual( TDevelopMeshData *data );

  public:
	int Type;
};

//------------------------------------------------------------------------------
// TDirLightData
//------------------------------------------------------------------------------

class TDirLightData
{
  public:
	TDirLightData( );
	~TDirLightData( )
	{
	}

	void Clear( );
	void Set( TDirLightData *data );
	bool IsEqual( TDirLightData *data );

  public:
	int Type;

	double Width;
	double Height;

	double Power;
	double Efficacy;
	double ConeAngle;
	double FallOffAngle;
	int FallOffType;

	TColor Color;

	T3DPoint OldData0, OldData1, OldDataX, OldDataY;

	UnicodeString TempName;
	double TempAngle;
	double TempLength;
};

//------------------------------------------------------------------------------

class TRenderCameraData
{
  public:
	TRenderCameraData( );
	~TRenderCameraData( )
	{
	}

	void Clear( );
	void Set( TRenderCameraData *data );
	bool IsEqual( TRenderCameraData *data );

	void GetBox( T3DPoint *box ); // array of 4
	void GetSCP( T3DPoint *scp ); // array of 3

  public:
	T3DPoint Origin, FocalPoint, Up, InitUp;
	int WRes, HRes;
	double FocalLength, FilmHeight, TargetDistance, FilmWidth;

	bool EnableCutPlanes; // Z-Clip Planes
	double ZNear, ZFar;

	bool DOF_Use;
	int DOF_Blades;
	double DOF_FStop, DOF_Rotation, DOF_Ratio;
	bool EnableDOFPlanes;
	bool ViewCamera;
};

#endif

