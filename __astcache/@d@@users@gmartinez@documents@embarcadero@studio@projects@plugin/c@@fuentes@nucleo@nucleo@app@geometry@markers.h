#ifndef MARKERSH
#define MARKERSH

#include <vcl.h>

#pragma hdrstop

#include "ogldata.h"
#include "entitydata.h"

class TCadGroup;
class TNDoublesList;

//------------------------------------------------------------------------------

class TPointMarker
{
	friend class TImpExp_XML;

  public:
	TPointMarker( );

	void Clear( );
	void Set( TPointMarker *M );
	void SetBasic( TPointMarker *M );

	UnicodeString GetName( );
	void SetName( UnicodeString str );

	int GetType( );
	void SetType( int type );
	bool IsIntersectionType( );

	int GetEditType( );
	void SetEditType( int etype );
	int GetDrawType( );
	void SetDrawType( int type );

	double GetPct( );
	void SetPct( double pct );

	bool GetOwnMaterial( );
	void SetOwnMaterial( bool value );
	TOGLMaterial *GetMaterial( );
	void SetMaterial( TOGLMaterial * );

	bool IsDirty( );
	void SetDirty( bool value );

	UnicodeString GetText( );
	void SetText( UnicodeString str );
	double GetAngle( );
	void SetAngle( double value );
	double GetRadius( );
	void SetRadius( double value );

	int GetIndex( );
	void SetIndex( int value );

	T3DPoint GetPoint( );
	void SetPoint( T3DPoint point );

	TShapeElement *GetShapeElement( )
	{
		return &ShapeElement;
	}

	int GetSymIndex( );
	void SetSymIndex( int value );

  protected:
	UnicodeString Name;
	int Type;
	int EditType;
	int DrawType;
	double Pct;
	bool OwnMaterial;
	TOGLMaterial Mat;
	TShapeElement ShapeElement;
	int SymIndex;

	bool Dirty; // Controla cuando se deben recalcular los marcadores dependientes: bien
				// de una relacion de punto tipo marker, bien de una interseccion de una deppoly.
	// Tipo PM_TYPE_TEXT
	UnicodeString Text;
	double Angle;
	double Radius;

	// Tipo PM_TYPE_DEPPOLY, PM_TYPE_DEPPCT, PM_TYPE_GRADING2D y PM_TYPE_GRADING2D_SMOOTH

	int Index;

	// Tipo PM_TYPE_OFFSET
	T3DPoint Point;
};

//------------------------------------------------------------------------------

class TPointMarkerList
{
	friend class TImpExp_XML;

  public:
	TPointMarkerList( int d = 5 );
	virtual ~TPointMarkerList( );

	void Set( TPointMarkerList *E );
	void SetBasic( TPointMarkerList *E );

	void AddItem( TPointMarker *s );
	void SetItem( int ind, TPointMarker *s );
	void DelItem( int ind );
	TPointMarker *GetItem( int ind );
	int GetItemIndex( TPointMarker *s );

	void Clear( );
	int Count( );
	void Grow( int d );

  protected:
	int numItems, maxItems, delta;
	TPointMarker *Item;
};

//------------------------------------------------------------------------------

class TLineMarker
{
	friend class TImpExp_XML;

  public:
	TLineMarker( );

	void Clear( );
	void Set( TLineMarker *M );
	void SetBasic( TLineMarker *M );

	UnicodeString GetName( );
	void SetName( UnicodeString str );

	int GetIndex( );
	void SetIndex( int );
	int GetEditType( );
	void SetEditType( int etype );
	int GetDrawType( );
	void SetDrawType( int type );
	int GetStartIndex( );
	void SetStartIndex( int );
	int GetEndIndex( );
	void SetEndIndex( int );
	bool GetOwnMaterial( );
	TOGLMaterial *GetMaterial( );
	void SetMaterial( TOGLMaterial * );
	TShapeElement *GetShapeElement( )
	{
		return &ShapeElement;
	}

	// Tipos LM_TYPE_GRADING2D y LM_TYPE_GRADING2D_SMOOTH
	int Index;

  protected:
	UnicodeString Name;
	int EditType;
	int DrawType;
	int StartIndex, EndIndex;
	bool OwnMaterial;
	TOGLMaterial Mat;
	TShapeElement ShapeElement;
};

//------------------------------------------------------------------------------

class TLineMarkerList
{
	friend class TImpExp_XML;

  public:
	TLineMarkerList( int d = 5 );
	virtual ~TLineMarkerList( );

	void Set( TLineMarkerList *E );
	void SetBasic( TLineMarkerList *E );

	void AddItem( TLineMarker *s );
	void SetItem( int ind, TLineMarker *s );
	void DelItem( int ind );
	TLineMarker *GetItem( int ind );
	int GetItemIndex( TLineMarker *s );

	void Clear( );
	int Count( );
	void Grow( int d );

  protected:
	int numItems, maxItems, delta;
	TLineMarker *Item;
};

//------------------------------------------------------------------------------

class TMarkerList
{
	friend class TImpExp_XML;

  public:
	TMarkerList( );
	virtual ~TMarkerList( );

	void Set( TMarkerList *E );

	int GetRelType( )
	{
		return RelType;
	}
	void SetRelType( int rel );

	void AddRelCurve( TCadEntity * );
	void DelRelCurve( TCadEntity * );
	TCadGroup *GetRelCurves( )
	{
		return RelCurves;
	}

	void CheckRelations( int = MK_MODE_NONE, int = -1 );
	void ApplyRelation( TMarkerList *list, int type, int ind );

	TPointMarkerList *GetPointMarkerList( )
	{
		return &PointMarkerList;
	}
	TLineMarkerList *GetLineMarkerList( )
	{
		return &LineMarkerList;
	}

	void AddPointMarker( TPointMarker *s );
	void AddLineMarker( TLineMarker *s );

	void SetPointMarker( int ind, TPointMarker *s, bool close );
	void SetLineMarker( int ind, TLineMarker *s );

	void DelPointMarker( int ind );
	void DelLineMarker( int ind );

	bool ValidateLineDragPct( int ind, double &pct, bool close );
	void MoveLineMarker( int ind, double pct, bool close );

	bool ValidatePointDragPct( int ind, double &pct, bool close );
	void MovePointMarker( int ind, double pct, bool close );

	TPointMarker *GetPointMarker( int ind );
	int GetPointMarkerIndexByPoint( T3DPoint pt, double res, TInteger_List *forcetypes = 0 );
	int GetPointMarkerIndexByIndex( int ind, TInteger_List *forcetypes = 0 );
	TLineMarker *GetLineMarker( int ind );

	int GetLineMarkerType( int ind );
	int GetGrading2DRelatedPointMarkerIndex( int ind, bool lmsmooth );

	int PointMarkersCount( int type = -1 );
	int LineMarkersCount( int type = -1 );
	int VisibleMarkersCount( );

	void SetPointMarkersEditType( int etype );

	int GetShapeElementsCount( TInteger_List *forcetypes = 0, TInteger_List *excludetypes = 0, bool forcecosting = false );
	bool GetMarkerByShapeElementIndex( int index, int &indp, int &indl, TInteger_List *forcetypes = 0, TInteger_List *excludetypes = 0, bool forcecosting = false );
	bool GetMarkerByShapeElement( TShapeElement *se, int &indp, int &indl, int checkoffset = 1 );

	int GetPointMarkerSEIndexByPct( double pct, bool close, double range, TInteger_List *forcetypes = 0, TInteger_List *excludetypes = 0, bool forcecosting = false );
	int GetLineMarkerSEIndexByPct( double pct, bool close, double range, TInteger_List *forcetypes = 0, TInteger_List *excludetypes = 0, bool forcecosting = false );
	bool GetMarkerSEIndexByPct( double pct, bool close, double range, int &indp, int &indl, TInteger_List *forcetypes = 0, TInteger_List *excludetypes = 0, bool forcecosting = false );
	void ApplySymmetrySE( );

	bool UpdateSEMachines2D( TMachine2DList *machine2dlist, TTool2DList *tool2dlist, TMachine2DList *newmachine2dlist, TTool2DList *newtool2dlist );
	bool UpdateSEActive( bool *seVisibility );
	bool ReplaceTool2DTypes( TMachine2DList *machine2dlist, int machine2dindex, int tool2dtype1, int tool2dtype2 );

	void Clear( );
	void ClearRel( );

	void Invert( bool invertlinemarkers = true );
	void OrderList( );

	void SetMaterial( TOGLMaterial *mat );

  protected:
	TPointMarkerList PointMarkerList;
	TLineMarkerList LineMarkerList;

	int RelType;
	TCadGroup *RelCurves;
};

#endif

