// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxGeometry.pas' rev: 35.00 (Windows)

#ifndef CxgeometryHPP
#define CxgeometryHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.SysUtils.hpp>
#include <Winapi.Windows.hpp>
#include <System.Classes.hpp>
#include <System.Types.hpp>
#include <System.Math.hpp>
#include <System.Generics.Defaults.hpp>
#include <System.Generics.Collections.hpp>
#include <dxCore.hpp>
#include <dxCoreClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Cxgeometry
{
//-- forward type declarations -----------------------------------------------
struct TdxSector;
struct TdxSizeF;
struct TdxPointF;
struct TdxRectF;
class DELPHICLASS TdxRectFList;
struct TdxSizeDouble;
struct TdxPolygonF;
struct TdxPointDouble;
struct TdxRectDouble;
class DELPHICLASS TcxGeometryObject;
class DELPHICLASS TcxPointBasedGeometryObject;
class DELPHICLASS TcxPointDoubleBasedGeometryObject;
class DELPHICLASS TcxRectBasedGeometryObject;
class DELPHICLASS TcxOffsets;
class DELPHICLASS TcxMargin;
class DELPHICLASS TcxRect;
class DELPHICLASS TcxSize;
class DELPHICLASS TdxSizeFloat;
class DELPHICLASS TdxPoint;
class DELPHICLASS TdxPointDoublePersistent;
class DELPHICLASS TdxMatrix;
class DELPHICLASS TdxScaleFactor;
__interface DELPHIINTERFACE IdxScaleFactor;
typedef System::DelphiInterface<IdxScaleFactor> _di_IdxScaleFactor;
class DELPHICLASS TdxOwnedScaleFactor;
class DELPHICLASS TdxVectors;
struct TdxXFormHelper /* Helper for record 'tagXFORM' */;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TcxBorder : unsigned char { bLeft, bTop, bRight, bBottom };

typedef System::Set<TcxBorder, TcxBorder::bLeft, TcxBorder::bBottom> TcxBorders;

enum class DECLSPEC_DENUM TdxAlignment : unsigned char { Default, Near, Center, Far };

enum DECLSPEC_DENUM TcxPtInRectType : unsigned char { ptrtNone, ptrtArea, ptrtLeft, ptrtTop, ptrtRight, ptrtBottom };

struct DECLSPEC_DRECORD TdxSector
{
public:
	float StartAngle;
	float SweepAngle;
};


struct DECLSPEC_DRECORD TdxSizeF
{
public:
	float cx;
	float cy;
	static TdxSizeF __fastcall Create(const float AWidth, const float AHeight);
	__fastcall operator System::Types::TSize();
	static TdxSizeF __fastcall _op_Implicit(const System::Types::TSize &Value);
	static bool __fastcall _op_Equality(const TdxSizeF &S1, const TdxSizeF &S2);
	static bool __fastcall _op_Inequality(const TdxSizeF &S1, const TdxSizeF &S2);
	static TdxSizeF __fastcall Null();
	TdxSizeF __fastcall Ceil();
	void __fastcall ChangeScale(int M, int D);
	void __fastcall Init(const float AWidth, const float AHeight);
	__property float Width = {read=cx, write=cx};
	__property float Height = {read=cy, write=cy};
	
	TdxSizeF& operator =(const System::Types::TSize &Value) { *this = TdxSizeF::_op_Implicit(Value); return *this; }
	friend bool operator ==(const TdxSizeF &S1, const TdxSizeF &S2) { return TdxSizeF::_op_Equality(S1, S2); }
	friend bool operator !=(const TdxSizeF &S1, const TdxSizeF &S2) { return TdxSizeF::_op_Inequality(S1, S2); }
};


typedef TdxPointF *PdxPointF;

struct DECLSPEC_DRECORD TdxPointF
{
public:
	float X;
	float Y;
	static TdxPointF __fastcall Create(const float AX, const float AY);
	static TdxPointF __fastcall _op_Implicit(const System::Types::TPoint &Value);
	__fastcall operator System::Types::TPoint();
	static bool __fastcall _op_Equality(const TdxPointF &P1, const TdxPointF &P2);
	static bool __fastcall _op_Inequality(const TdxPointF &P1, const TdxPointF &P2);
	void __fastcall Init(const float AX, const float AY)/* overload */;
	void __fastcall Init(const TdxPointF &APoint)/* overload */;
	void __fastcall Offset(const float DX, const float DY, bool APositiveFactor = true)/* overload */;
	void __fastcall Offset(const TdxPointF &P, bool APositiveFactor = true)/* overload */;
	void __fastcall Offset(const TdxSizeF &S, bool APositiveFactor = true)/* overload */;
	void __fastcall Rotate(float AAngle, const TdxPointF &APivotPoint);
	void __fastcall Scale(const float DX, const float DY)/* overload */;
	void __fastcall Scale(const TdxPointF &P)/* overload */;
	void __fastcall Scale(const TdxSizeF &S)/* overload */;
	static TdxPointF __fastcall Null();
	
	TdxPointF& operator =(const System::Types::TPoint &Value) { *this = TdxPointF::_op_Implicit(Value); return *this; }
	friend bool operator ==(const TdxPointF &P1, const TdxPointF &P2) { return TdxPointF::_op_Equality(P1, P2); }
	friend bool operator !=(const TdxPointF &P1, const TdxPointF &P2) { return TdxPointF::_op_Inequality(P1, P2); }
};


struct DECLSPEC_DRECORD TdxRectF
{
public:
	float Left;
	float Top;
	float Right;
	float Bottom;
	
private:
	TdxPointF __fastcall GetBottomCenter();
	TdxPointF __fastcall GetBottomLeft();
	TdxPointF __fastcall GetBottomRight();
	float __fastcall GetHeight();
	TdxPointF __fastcall GetLeftCenter();
	TdxPointF __fastcall GetLocation();
	TdxPointF __fastcall GetRightCenter();
	TdxSizeF __fastcall GetSize();
	TdxPointF __fastcall GetTopCenter();
	TdxPointF __fastcall GetTopLeft();
	TdxPointF __fastcall GetTopRight();
	float __fastcall GetWidth();
	void __fastcall SetBottomCenter(const TdxPointF &Value);
	void __fastcall SetBottomLeft(const TdxPointF &P);
	void __fastcall SetBottomRight(const TdxPointF &P);
	void __fastcall SetLeftCenter(const TdxPointF &Value);
	void __fastcall SetLocation(const TdxPointF &P);
	void __fastcall SetRightCenter(const TdxPointF &Value);
	void __fastcall SetSize(const TdxSizeF &Value);
	void __fastcall SetTopCenter(const TdxPointF &Value);
	void __fastcall SetTopLeft(const TdxPointF &P);
	void __fastcall SetTopRight(const TdxPointF &P);
	void __fastcall SetHeight(const float Value);
	void __fastcall SetWidth(const float Value);
	
public:
	static TdxRectF __fastcall Create(const float ALeft, const float ATop, const float ARight, const float ABottom)/* overload */;
	static TdxRectF __fastcall Create(const TdxPointF &ACenter, const float AWidth, const float AHeight)/* overload */;
	static TdxRectF __fastcall CreateSize(const float ALeft, const float ATop, const float AWidth, const float AHeight)/* overload */;
	void __fastcall Init(const float ALeft, const float ATop, const float ARight, const float ABottom)/* overload */;
	void __fastcall InitSize(const float ALeft, const float ATop, const float AWidth, const float AHeight)/* overload */;
	static TdxRectF __fastcall _op_Implicit(const System::Types::TRect &Value);
	static bool __fastcall _op_Equality(const TdxRectF &R1, const TdxRectF &R2);
	static bool __fastcall _op_Inequality(const TdxRectF &R1, const TdxRectF &R2);
	void __fastcall Assign(const System::Types::TRect &Value);
	void __fastcall AdjustByBorder(const TdxSizeF &ASize, TcxBorder ASide)/* overload */;
	void __fastcall AdjustByBorder(const TdxSizeF &ASize, TcxBorder ASide, const System::Types::TRect &AMargins)/* overload */;
	TdxRectF __fastcall AlignHorizontally(const TdxSizeF &ASize, TdxAlignment AAlignment)/* overload */;
	TdxRectF __fastcall AlignHorizontally(const TdxRectF &R, TdxAlignment AAlignment)/* overload */;
	TdxRectF __fastcall AlignVertically(const TdxSizeF &ASize, TdxAlignment AAlignment)/* overload */;
	TdxRectF __fastcall AlignVertically(const TdxRectF &R, TdxAlignment AAlignment)/* overload */;
	TdxPointF __fastcall CenterPoint();
	bool __fastcall Contains(const TdxPointF &P)/* overload */;
	bool __fastcall Contains(const TdxRectF &R)/* overload */;
	TdxRectF __fastcall Content(const System::Types::TRect &AMargins)/* overload */;
	TdxRectF __fastcall Content(TcxMargin* const AMargins)/* overload */;
	TdxPointF __fastcall Distance(const TdxRectF &R);
	void __fastcall Empty();
	void __fastcall Inflate(float DX, float DY)/* overload */;
	void __fastcall Inflate(float ADelta)/* overload */;
	void __fastcall Inflate(float ALeft, float ATop, float ARight, float ABottom)/* overload */;
	void __fastcall Inflate(const TdxPointF &P)/* overload */;
	void __fastcall Inflate(const TdxSizeF &S)/* overload */;
	void __fastcall Inflate(const TdxRectF &R)/* overload */;
	bool __fastcall IntersectsWith(const TdxRectF &R);
	bool __fastcall IsEmpty();
	bool __fastcall IsZero();
	void __fastcall Intersect(const TdxRectF &R);
	void __fastcall Normalize();
	static TdxRectF __fastcall Null();
	void __fastcall Offset(float X, float Y)/* overload */;
	void __fastcall Offset(const TdxPointF &ATopLeft)/* overload */;
	void __fastcall SetCenter(const TdxPointF &APoint);
	void __fastcall SetMargins(const TdxRectF &AMargins);
	void __fastcall TruncBorder(const TdxRectF &R, TcxBorders ASide, const System::Types::TRect &AMargin);
	void __fastcall Union(const TdxRectF &R);
	TdxRectF __fastcall ZoomInto(const TdxSizeF &ASize)/* overload */;
	TdxRectF __fastcall ZoomInto(const TdxRectF &ABounds)/* overload */;
	__property TdxPointF Location = {read=GetLocation, write=SetLocation};
	__property float Height = {read=GetHeight, write=SetHeight};
	__property float Width = {read=GetWidth, write=SetWidth};
	__property TdxSizeF Size = {read=GetSize, write=SetSize};
	__property TdxPointF BottomLeft = {read=GetBottomLeft, write=SetBottomLeft};
	__property TdxPointF BottomCenter = {read=GetBottomCenter, write=SetBottomCenter};
	__property TdxPointF BottomRight = {read=GetBottomRight, write=SetBottomRight};
	__property TdxPointF LeftCenter = {read=GetLeftCenter, write=SetLeftCenter};
	__property TdxPointF RightCenter = {read=GetRightCenter, write=SetRightCenter};
	__property TdxPointF TopCenter = {read=GetTopCenter, write=SetTopCenter};
	__property TdxPointF TopLeft = {read=GetTopLeft, write=SetTopLeft};
	__property TdxPointF TopRight = {read=GetTopRight, write=SetTopRight};
	
	TdxRectF& operator =(const System::Types::TRect &Value) { *this = TdxRectF::_op_Implicit(Value); return *this; }
	friend bool operator ==(const TdxRectF &R1, const TdxRectF &R2) { return TdxRectF::_op_Equality(R1, R2); }
	friend bool operator !=(const TdxRectF &R1, const TdxRectF &R2) { return TdxRectF::_op_Inequality(R1, R2); }
};


typedef TdxRectF *PdxRectF;

class PASCALIMPLEMENTATION TdxRectFList : public System::Generics::Collections::TList__1<TdxRectF>
{
	typedef System::Generics::Collections::TList__1<TdxRectF> inherited;
	
public:
	/* {System_Generics_Collections}TList<cxGeometry_TdxRectF>.Create */ inline __fastcall TdxRectFList()/* overload */ : System::Generics::Collections::TList__1<TdxRectF>() { }
	/* {System_Generics_Collections}TList<cxGeometry_TdxRectF>.Create */ inline __fastcall TdxRectFList(const System::DelphiInterface<System::Generics::Defaults::IComparer__1<TdxRectF> > AComparer)/* overload */ : System::Generics::Collections::TList__1<TdxRectF>(AComparer) { }
	/* {System_Generics_Collections}TList<cxGeometry_TdxRectF>.Create */ inline __fastcall TdxRectFList(System::Generics::Collections::TEnumerable__1<TdxRectF>* const Collection)/* overload */ : System::Generics::Collections::TList__1<TdxRectF>(Collection) { }
	/* {System_Generics_Collections}TList<cxGeometry_TdxRectF>.Create */ inline __fastcall TdxRectFList(const TdxRectF *Values, const int Values_High)/* overload */ : System::Generics::Collections::TList__1<TdxRectF>(Values, Values_High) { }
	/* {System_Generics_Collections}TList<cxGeometry_TdxRectF>.Destroy */ inline __fastcall virtual ~TdxRectFList() { }
	
};


struct DECLSPEC_DRECORD TdxSizeDouble
{
public:
	double Height;
	double Width;
	void __fastcall Init(double AWidth, double AHeight);
	static TdxSizeDouble __fastcall Create(const double AWidth, const double AHeight);
	static bool __fastcall _op_Equality(const TdxSizeDouble &R1, const TdxSizeDouble &R2);
	static bool __fastcall _op_Inequality(const TdxSizeDouble &R1, const TdxSizeDouble &R2);
	__fastcall operator System::Types::TSize();
	static TdxSizeDouble __fastcall Null();
	
	friend bool operator ==(const TdxSizeDouble &R1, const TdxSizeDouble &R2) { return TdxSizeDouble::_op_Equality(R1, R2); }
	friend bool operator !=(const TdxSizeDouble &R1, const TdxSizeDouble &R2) { return TdxSizeDouble::_op_Inequality(R1, R2); }
};


struct DECLSPEC_DRECORD TdxPolygonF
{
	
private:
	typedef System::DynamicArray<TdxPointF> _TdxPolygonF__1;
	
	
public:
	_TdxPolygonF__1 Points;
	
private:
	int __fastcall GetPointCount();
	void __fastcall SetPointCount(int ACount);
	
public:
	static TdxPolygonF __fastcall Create(const TdxRectF &ARect);
	bool __fastcall Contains(const TdxPointF &APoint);
	bool __fastcall IntersectsWith(const TdxPolygonF APolygon, /* out */ TdxPointF &AIntersectionPoint);
	bool __fastcall PointsPresent(int AExpectedPointCount);
	void __fastcall Clear();
	void __fastcall Init(const TdxRectF &ARect);
	void __fastcall Offset(const TdxPointF &ATopLeft)/* overload */;
	void __fastcall Offset(float X, float Y)/* overload */;
	void __fastcall Rotate(float AAngle, const TdxPointF &APivotPoint);
	__property int PointCount = {read=GetPointCount, write=SetPointCount};
};


typedef TdxPolygonF *PdxPolygonF;

struct DECLSPEC_DRECORD TdxPointDouble
{
public:
	double X;
	double Y;
	void __fastcall Init(const double AX, const double AY);
	static TdxPointDouble __fastcall Create(const double AX, const double AY);
	static bool __fastcall _op_Equality(const TdxPointDouble &R1, const TdxPointDouble &R2);
	static bool __fastcall _op_Inequality(const TdxPointDouble &R1, const TdxPointDouble &R2);
	__fastcall operator System::Types::TPoint();
	__fastcall operator TdxPointF();
	void __fastcall Offset(const double DX, const double DY)/* overload */;
	void __fastcall Offset(const TdxPointDouble &P)/* overload */;
	void __fastcall Offset(const TdxSizeDouble &S)/* overload */;
	void __fastcall Scale(const double DX, const double DY)/* overload */;
	void __fastcall Scale(const TdxPointDouble &P)/* overload */;
	void __fastcall Scale(const TdxSizeDouble &S)/* overload */;
	static TdxPointDouble __fastcall Null();
	
	friend bool operator ==(const TdxPointDouble &R1, const TdxPointDouble &R2) { return TdxPointDouble::_op_Equality(R1, R2); }
	friend bool operator !=(const TdxPointDouble &R1, const TdxPointDouble &R2) { return TdxPointDouble::_op_Inequality(R1, R2); }
};


struct DECLSPEC_DRECORD TdxRectDouble
{
private:
	double __fastcall GetBottom();
	TdxPointDouble __fastcall GetBottomRight();
	double __fastcall GetRight();
	TdxSizeDouble __fastcall GetSize();
	TdxPointDouble __fastcall GetTopLeft();
	void __fastcall SetBottom(const double AValue);
	void __fastcall SetBottomRight(const TdxPointDouble &ABottomRight);
	void __fastcall SetRight(const double AValue);
	void __fastcall SetTopLeft(const TdxPointDouble &ATopLeft);
	
public:
	double Left;
	double Top;
	double Width;
	double Height;
	static TdxRectDouble __fastcall CreateFromLTRB(const double ALeft, const double ATop, const double ARight, const double ABottom)/* overload */;
	static TdxRectDouble __fastcall Create(const TdxPointDouble &AOrigin)/* overload */;
	static TdxRectDouble __fastcall Create(const TdxPointDouble &ATopLeft, const TdxPointDouble &ABottomRight)/* overload */;
	static TdxRectDouble __fastcall Create(const TdxSizeDouble &ASize)/* overload */;
	static TdxRectDouble __fastcall Create(const TdxPointDouble &AOrigin, double AWidth, double AHeight)/* overload */;
	static TdxRectDouble __fastcall Create(const double ALeft, const double ATop, const double AWidth, const double AHeight)/* overload */;
	static TdxRectDouble __fastcall Create(const double ALeft, const double ATop, const TdxSizeDouble &ASize)/* overload */;
	static TdxRectDouble __fastcall Create(const TdxPointDouble &AOrigin, const TdxSizeDouble &ASize)/* overload */;
	bool __fastcall IsEmpty();
	static TdxRectDouble __fastcall Null();
	bool __fastcall Contains(const TdxPointDouble &P);
	void __fastcall Inflate(const double AValue)/* overload */;
	void __fastcall Union(const TdxRectDouble &R);
	__property double Bottom = {read=GetBottom, write=SetBottom};
	__property TdxPointDouble BottomRight = {read=GetBottomRight, write=SetBottomRight};
	__property double Right = {read=GetRight, write=SetRight};
	__property TdxSizeDouble Size = {read=GetSize};
	__property TdxPointDouble TopLeft = {read=GetTopLeft, write=SetTopLeft};
};


class PASCALIMPLEMENTATION TcxGeometryObject : public Dxcoreclasses::TcxLockablePersistent
{
	typedef Dxcoreclasses::TcxLockablePersistent inherited;
	
private:
	System::Classes::TNotifyEvent FOnChange;
	
protected:
	virtual void __fastcall DoChanged();
	virtual void __fastcall DoChangeScale(int M, int D);
	
public:
	void __fastcall ChangeScale(int M, int D);
	virtual void __fastcall LoadFromStream(System::Classes::TStream* AStream);
	virtual void __fastcall SaveToStream(System::Classes::TStream* AStream);
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
public:
	/* TcxOwnedPersistent.Create */ inline __fastcall virtual TcxGeometryObject(System::Classes::TPersistent* AOwner) : Dxcoreclasses::TcxLockablePersistent(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxGeometryObject() { }
	
};


class PASCALIMPLEMENTATION TcxPointBasedGeometryObject : public TcxGeometryObject
{
	typedef TcxGeometryObject inherited;
	
private:
	System::Types::TPoint FDefaultValue;
	System::Types::TPoint FValue;
	
protected:
	virtual void __fastcall DoAssign(System::Classes::TPersistent* Source);
	virtual void __fastcall DoChangeScale(int M, int D);
	virtual System::Types::TPoint __fastcall GetValue();
	virtual int __fastcall GetValuePart(int PartIndex);
	virtual bool __fastcall IsValuePartStored(int PartIndex);
	virtual void __fastcall SetValue(const System::Types::TPoint &AValue);
	virtual void __fastcall SetValuePart(int PartIndex, int AValue);
	virtual void __fastcall ValidateValue(System::Types::TPoint &AValue);
	
public:
	__fastcall TcxPointBasedGeometryObject(System::Classes::TPersistent* AOwner, int ADefaultX, int ADefaultY);
	bool __fastcall IsDefault();
	bool __fastcall IsEmpty();
	bool __fastcall IsEqual(TcxPointBasedGeometryObject* const AValue)/* overload */;
	bool __fastcall IsEqual(const System::Types::TPoint &AValue)/* overload */;
	bool __fastcall IsEqual(const System::Types::TSize &AValue)/* overload */;
	virtual void __fastcall LoadFromStream(System::Classes::TStream* AStream);
	virtual void __fastcall SaveToStream(System::Classes::TStream* AStream);
	void __fastcall Reset();
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxPointBasedGeometryObject() { }
	
};


class PASCALIMPLEMENTATION TcxPointDoubleBasedGeometryObject : public TcxGeometryObject
{
	typedef TcxGeometryObject inherited;
	
private:
	TdxPointDouble FDefaultValue;
	TdxPointDouble FValue;
	
protected:
	virtual void __fastcall DoAssign(System::Classes::TPersistent* Source);
	virtual void __fastcall DoChangeScale(int M, int D);
	TdxPointDouble __fastcall GetValue();
	virtual double __fastcall GetValuePart(int PartIndex);
	virtual bool __fastcall IsValuePartStored(int PartIndex);
	virtual void __fastcall SetValue(const TdxPointDouble &AValue);
	virtual void __fastcall SetValuePart(int PartIndex, const double AValue);
	virtual void __fastcall ValidateValue(TdxPointDouble &AValue);
	
public:
	__fastcall TcxPointDoubleBasedGeometryObject(System::Classes::TPersistent* AOwner, const double ADefaultX, const double ADefaultY);
	bool __fastcall IsDefault();
	bool __fastcall IsEmpty();
	bool __fastcall IsEqual(TcxPointDoubleBasedGeometryObject* const AValue)/* overload */;
	bool __fastcall IsEqual(const TdxPointDouble &AValue)/* overload */;
	bool __fastcall IsEqual(const TdxPointF &AValue)/* overload */;
	bool __fastcall IsEqual(const TdxSizeDouble &AValue)/* overload */;
	bool __fastcall IsEqual(const TdxSizeF &AValue)/* overload */;
	bool __fastcall IsEqual(const System::Types::TPoint &AValue)/* overload */;
	bool __fastcall IsEqual(const System::Types::TSize &AValue)/* overload */;
	virtual void __fastcall LoadFromStream(System::Classes::TStream* AStream);
	virtual void __fastcall SaveToStream(System::Classes::TStream* AStream);
	void __fastcall Reset();
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxPointDoubleBasedGeometryObject() { }
	
};


class PASCALIMPLEMENTATION TcxRectBasedGeometryObject : public TcxGeometryObject
{
	typedef TcxGeometryObject inherited;
	
private:
	int __fastcall GetValuePart(int AIndex);
	void __fastcall SetValuePart(int AIndex, int AValue);
	
protected:
	System::Types::TRect FDefaultValue;
	System::Types::TRect FValue;
	virtual void __fastcall DoAssign(System::Classes::TPersistent* Source);
	virtual void __fastcall DoChangeScale(int M, int D);
	virtual int __fastcall GetHeight();
	virtual int __fastcall GetWidth();
	virtual bool __fastcall IsValuePartStored(int Index);
	virtual void __fastcall SetHeight(int AValue);
	void __fastcall SetValue(const System::Types::TRect &AValue);
	virtual void __fastcall SetWidth(int AValue);
	virtual void __fastcall ValidateValue(System::Types::TRect &R);
	
public:
	__fastcall TcxRectBasedGeometryObject(System::Classes::TPersistent* AOwner, const System::Types::TRect &ADefaultValue)/* overload */;
	__fastcall TcxRectBasedGeometryObject(System::Classes::TPersistent* AOwner, const int ADefaultValue)/* overload */;
	bool __fastcall IsDefault();
	virtual bool __fastcall IsEmpty();
	bool __fastcall IsEqual(TcxRectBasedGeometryObject* const ARect)/* overload */;
	bool __fastcall IsEqual(const System::Types::TRect &ARect)/* overload */;
	virtual System::UnicodeString __fastcall ToString();
	virtual void __fastcall LoadFromStream(System::Classes::TStream* AStream);
	virtual void __fastcall SaveToStream(System::Classes::TStream* AStream);
	void __fastcall Reset();
	__property int Height = {read=GetHeight, write=SetHeight, nodefault};
	__property int Width = {read=GetWidth, write=SetWidth, nodefault};
	__property System::Types::TRect Value = {read=FValue, write=SetValue};
	
__published:
	__property int Left = {read=GetValuePart, write=SetValuePart, stored=IsValuePartStored, index=0, nodefault};
	__property int Top = {read=GetValuePart, write=SetValuePart, stored=IsValuePartStored, index=1, nodefault};
	__property int Right = {read=GetValuePart, write=SetValuePart, stored=IsValuePartStored, index=2, nodefault};
	__property int Bottom = {read=GetValuePart, write=SetValuePart, stored=IsValuePartStored, index=3, nodefault};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxRectBasedGeometryObject() { }
	
};


class PASCALIMPLEMENTATION TcxOffsets : public TcxRectBasedGeometryObject
{
	typedef TcxRectBasedGeometryObject inherited;
	
private:
	int __fastcall GetAll();
	void __fastcall SetAll(int AValue);
	
protected:
	virtual int __fastcall GetHeight();
	virtual int __fastcall GetWidth();
	bool __fastcall IsAllStored();
	virtual bool __fastcall IsValuePartStored(int Index);
	virtual void __fastcall SetHeight(int AValue);
	virtual void __fastcall SetWidth(int AValue);
	
public:
	virtual bool __fastcall IsEmpty();
	__property Height;
	__property Width;
	
__published:
	__property int All = {read=GetAll, write=SetAll, stored=IsAllStored, nodefault};
	__property Left;
	__property Top;
	__property Right;
	__property Bottom;
public:
	/* TcxRectBasedGeometryObject.Create */ inline __fastcall TcxOffsets(System::Classes::TPersistent* AOwner, const System::Types::TRect &ADefaultValue)/* overload */ : TcxRectBasedGeometryObject(AOwner, ADefaultValue) { }
	/* TcxRectBasedGeometryObject.Create */ inline __fastcall TcxOffsets(System::Classes::TPersistent* AOwner, const int ADefaultValue)/* overload */ : TcxRectBasedGeometryObject(AOwner, ADefaultValue) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxOffsets() { }
	
};


class PASCALIMPLEMENTATION TcxMargin : public TcxOffsets
{
	typedef TcxOffsets inherited;
	
public:
	__property System::Types::TRect Margin = {read=FValue, write=SetValue};
public:
	/* TcxRectBasedGeometryObject.Create */ inline __fastcall TcxMargin(System::Classes::TPersistent* AOwner, const System::Types::TRect &ADefaultValue)/* overload */ : TcxOffsets(AOwner, ADefaultValue) { }
	/* TcxRectBasedGeometryObject.Create */ inline __fastcall TcxMargin(System::Classes::TPersistent* AOwner, const int ADefaultValue)/* overload */ : TcxOffsets(AOwner, ADefaultValue) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxMargin() { }
	
};


class PASCALIMPLEMENTATION TcxRect : public TcxRectBasedGeometryObject
{
	typedef TcxRectBasedGeometryObject inherited;
	
private:
	System::Types::TPoint __fastcall GetVertex(int AIndex);
	void __fastcall SetVertex(int AIndex, const System::Types::TPoint &AValue);
	
public:
	__property System::Types::TPoint BottomLeft = {read=GetVertex, write=SetVertex, index=2};
	__property System::Types::TPoint BottomRight = {read=GetVertex, write=SetVertex, index=3};
	__property System::Types::TPoint TopLeft = {read=GetVertex, write=SetVertex, index=0};
	__property System::Types::TPoint TopRight = {read=GetVertex, write=SetVertex, index=1};
	__property System::Types::TRect Rect = {read=FValue, write=SetValue};
	
__published:
	__property OnChange;
public:
	/* TcxRectBasedGeometryObject.Create */ inline __fastcall TcxRect(System::Classes::TPersistent* AOwner, const System::Types::TRect &ADefaultValue)/* overload */ : TcxRectBasedGeometryObject(AOwner, ADefaultValue) { }
	/* TcxRectBasedGeometryObject.Create */ inline __fastcall TcxRect(System::Classes::TPersistent* AOwner, const int ADefaultValue)/* overload */ : TcxRectBasedGeometryObject(AOwner, ADefaultValue) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxRect() { }
	
};


class PASCALIMPLEMENTATION TcxSize : public TcxPointBasedGeometryObject
{
	typedef TcxPointBasedGeometryObject inherited;
	
private:
	System::Types::TSize __fastcall GetSize();
	void __fastcall SetSize(const System::Types::TSize &AValue);
	
protected:
	virtual void __fastcall ValidateValue(System::Types::TPoint &AValue);
	
public:
	__fastcall TcxSize(System::Classes::TPersistent* AOwner, const System::Types::TSize &ADefaultValue)/* overload */;
	__fastcall TcxSize(System::Classes::TPersistent* AOwner, int ADefaultWidth, int ADefaultHeight)/* overload */;
	virtual System::UnicodeString __fastcall ToString();
	__property System::Types::TSize Size = {read=GetSize, write=SetSize};
	__property System::Types::TSize Value = {read=GetSize, write=SetSize};
	
__published:
	__property int Height = {read=GetValuePart, write=SetValuePart, stored=IsValuePartStored, index=1, nodefault};
	__property int Width = {read=GetValuePart, write=SetValuePart, stored=IsValuePartStored, index=0, nodefault};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxSize() { }
	
};


class PASCALIMPLEMENTATION TdxSizeFloat : public TcxPointDoubleBasedGeometryObject
{
	typedef TcxPointDoubleBasedGeometryObject inherited;
	
private:
	TdxSizeF __fastcall GetSize();
	void __fastcall SetSize(const TdxSizeF &ASize);
	
protected:
	virtual void __fastcall ValidateValue(TdxPointDouble &AValue);
	
public:
	__fastcall TdxSizeFloat(System::Classes::TPersistent* AOwner, const TdxSizeF &ADefaultValue)/* overload */;
	__fastcall TdxSizeFloat(System::Classes::TPersistent* AOwner, float ADefaultWidth, float ADefaultHeight)/* overload */;
	__property TdxSizeF Value = {read=GetSize, write=SetSize};
	
__published:
	__property double Height = {read=GetValuePart, write=SetValuePart, stored=IsValuePartStored, index=1};
	__property double Width = {read=GetValuePart, write=SetValuePart, stored=IsValuePartStored, index=0};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxSizeFloat() { }
	
};


class PASCALIMPLEMENTATION TdxPoint : public TcxPointBasedGeometryObject
{
	typedef TcxPointBasedGeometryObject inherited;
	
public:
	__property System::Types::TPoint Point = {read=GetValue, write=SetValue};
	__property System::Types::TPoint Value = {read=GetValue, write=SetValue};
	
__published:
	__property int X = {read=GetValuePart, write=SetValuePart, stored=IsValuePartStored, index=0, nodefault};
	__property int Y = {read=GetValuePart, write=SetValuePart, stored=IsValuePartStored, index=1, nodefault};
public:
	/* TcxPointBasedGeometryObject.Create */ inline __fastcall TdxPoint(System::Classes::TPersistent* AOwner, int ADefaultX, int ADefaultY) : TcxPointBasedGeometryObject(AOwner, ADefaultX, ADefaultY) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPoint() { }
	
};


class PASCALIMPLEMENTATION TdxPointDoublePersistent : public TcxPointDoubleBasedGeometryObject
{
	typedef TcxPointDoubleBasedGeometryObject inherited;
	
public:
	__property TdxPointDouble Point = {read=GetValue, write=SetValue};
	__property TdxPointDouble Value = {read=GetValue, write=SetValue};
	
__published:
	__property double X = {read=GetValuePart, write=SetValuePart, stored=IsValuePartStored, index=0};
	__property double Y = {read=GetValuePart, write=SetValuePart, stored=IsValuePartStored, index=1};
public:
	/* TcxPointDoubleBasedGeometryObject.Create */ inline __fastcall TdxPointDoublePersistent(System::Classes::TPersistent* AOwner, const double ADefaultX, const double ADefaultY) : TcxPointDoubleBasedGeometryObject(AOwner, ADefaultX, ADefaultY) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPointDoublePersistent() { }
	
};


typedef System::DynamicArray<TdxPointF> TdxPointsF;

typedef System::DynamicArray<TdxRectF> TdxRectsF;

enum DECLSPEC_DENUM TdxTransformationOrder : unsigned char { moPrepend, moAppend };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxMatrix : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	tagXFORM FMatrix;
	void __fastcall DoMultiply(const tagXFORM &AXForm, TdxTransformationOrder AOrder = (TdxTransformationOrder)(0x0));
	
public:
	__fastcall TdxMatrix();
	__fastcall TdxMatrix(const float M11, const float M12, const float M21, const float M22, const float DX, const float DY)/* overload */;
	__fastcall TdxMatrix(TdxMatrix* const Matrix)/* overload */;
	__fastcall TdxMatrix(const tagXFORM &XForm)/* overload */;
	void __fastcall Assign(const float M11, const float M12, const float M21, const float M22, const float DX, const float DY)/* overload */;
	void __fastcall Assign(TdxMatrix* const Matrix)/* overload */;
	void __fastcall Assign(const tagXFORM &XForm)/* overload */;
	bool __fastcall IsIdentity();
	TdxPointF __fastcall Transform(const TdxPointF &APoint)/* overload */;
	TdxRectF __fastcall Transform(const TdxRectF &ARect)/* overload */;
	void __fastcall Multiply(TdxMatrix* M, TdxTransformationOrder AOrder = (TdxTransformationOrder)(0x0));
	void __fastcall Reset();
	void __fastcall Rotate(float AAngle, TdxTransformationOrder AOrder = (TdxTransformationOrder)(0x0))/* overload */;
	void __fastcall Rotate(float AAngle, const System::Types::TPoint &APivotPoint, TdxTransformationOrder AOrder = (TdxTransformationOrder)(0x0))/* overload */;
	void __fastcall Rotate(float AAngle, const TdxPointF &APivotPoint, TdxTransformationOrder AOrder = (TdxTransformationOrder)(0x0))/* overload */;
	void __fastcall Scale(float AScaleX, float AScaleY, TdxTransformationOrder AOrder = (TdxTransformationOrder)(0x0))/* overload */;
	void __fastcall Scale(const TdxPointF &AScale, TdxTransformationOrder AOrder = (TdxTransformationOrder)(0x0))/* overload */;
	void __fastcall Translate(float DX, float DY, TdxTransformationOrder AOrder = (TdxTransformationOrder)(0x0))/* overload */;
	void __fastcall Translate(const TdxPointF &AOffset, TdxTransformationOrder AOrder = (TdxTransformationOrder)(0x0))/* overload */;
	__property tagXFORM XForm = {read=FMatrix, write=FMatrix};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxMatrix() { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TdxScaleFactorNotifyEvent)(System::TObject* Sender, int M, int D, bool IsLoading);

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxScaleFactor : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FDenominator;
	int FNumerator;
	TdxScaleFactor* FDiscreteFactor;
	System::Generics::Collections::TList__1<TdxScaleFactorNotifyEvent>* FListeners;
	bool __fastcall GetAssigned();
	bool __fastcall TransformScaleFactor(int &ASourceNumerator, int &ASourceDenominator);
	
protected:
	virtual void __fastcall Changed(int M, int D, bool IsLoading);
	
public:
	__fastcall TdxScaleFactor();
	__fastcall virtual ~TdxScaleFactor();
	void __fastcall Assign(int ANumerator, int ADenominator, bool AIsLoading = false)/* overload */;
	void __fastcall Assign(TdxScaleFactor* ASource)/* overload */;
	void __fastcall Change(int ANumerator, int ADenominator);
	virtual bool __fastcall Equals(System::TObject* Obj);
	int __fastcall Apply(const int V)/* overload */;
	System::Types::TPoint __fastcall Apply(const System::Types::TPoint &V)/* overload */;
	System::Types::TRect __fastcall Apply(const System::Types::TRect &V)/* overload */;
	System::Types::TSize __fastcall Apply(const System::Types::TSize &V)/* overload */;
	float __fastcall ApplyF(const float V)/* overload */;
	double __fastcall ApplyF(const double V)/* overload */;
	TdxPointF __fastcall ApplyF(const TdxPointF &V)/* overload */;
	TdxRectF __fastcall ApplyF(const TdxRectF &V)/* overload */;
	TdxSizeF __fastcall ApplyF(const TdxSizeF &V)/* overload */;
	int __fastcall Apply(const int V, TdxScaleFactor* ASourceScaleFactor)/* overload */;
	System::Types::TPoint __fastcall Apply(const System::Types::TPoint &V, TdxScaleFactor* ASourceScaleFactor)/* overload */;
	System::Types::TRect __fastcall Apply(const System::Types::TRect &V, TdxScaleFactor* ASourceScaleFactor)/* overload */;
	System::Types::TSize __fastcall Apply(const System::Types::TSize &V, TdxScaleFactor* ASourceScaleFactor)/* overload */;
	int __fastcall Apply(const int V, int ASourceNumerator, int ASourceDenominator)/* overload */;
	System::Types::TPoint __fastcall Apply(const System::Types::TPoint &V, int ASourceNumerator, int ASourceDenominator)/* overload */;
	System::Types::TRect __fastcall Apply(const System::Types::TRect &V, int ASourceNumerator, int ASourceDenominator)/* overload */;
	System::Types::TSize __fastcall Apply(const System::Types::TSize &V, int ASourceNumerator, int ASourceDenominator)/* overload */;
	int __fastcall Revert(const int V)/* overload */;
	System::Types::TPoint __fastcall Revert(const System::Types::TPoint &V)/* overload */;
	System::Types::TRect __fastcall Revert(const System::Types::TRect &V)/* overload */;
	System::Types::TSize __fastcall Revert(const System::Types::TSize &V)/* overload */;
	double __fastcall RevertF(const double V)/* overload */;
	float __fastcall RevertF(const float V)/* overload */;
	TdxPointF __fastcall RevertF(const TdxPointF &V)/* overload */;
	TdxRectF __fastcall RevertF(const TdxRectF &V)/* overload */;
	TdxSizeF __fastcall RevertF(const TdxSizeF &V)/* overload */;
	void __fastcall ListenerAdd(TdxScaleFactorNotifyEvent AEventHandler);
	void __fastcall ListenerRemove(TdxScaleFactorNotifyEvent AEventHandler);
	TdxScaleFactor* __fastcall GetDiscreteFactor();
	__property bool Assigned = {read=GetAssigned, nodefault};
	__property int Denominator = {read=FDenominator, nodefault};
	__property int Numerator = {read=FNumerator, nodefault};
};

#pragma pack(pop)

__interface  INTERFACE_UUID("{367A805A-A84B-441A-83A3-6A7E489D3B6C}") IdxScaleFactor  : public System::IInterface 
{
	virtual TdxScaleFactor* __fastcall GetScaleFactor() = 0 ;
	__property TdxScaleFactor* Value = {read=GetScaleFactor};
};

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxOwnedScaleFactor : public TdxScaleFactor
{
	typedef TdxScaleFactor inherited;
	
private:
	TdxScaleFactor* FOwner;
	bool FUseOwnerValue;
	void __fastcall OwnerChangeHandler(System::TObject* Sender, int M, int D, bool IsLoading);
	void __fastcall SetOwner(TdxScaleFactor* const Value);
	void __fastcall SetUseOwnerValue(const bool Value);
	void __fastcall SynchronizeValue(bool AIsLoading = false);
	
protected:
	virtual void __fastcall Changed(int M, int D, bool IsLoading);
	
public:
	virtual void __fastcall AfterConstruction();
	virtual void __fastcall BeforeDestruction();
	__property TdxScaleFactor* Owner = {read=FOwner, write=SetOwner};
	__property bool UseOwnerValue = {read=FUseOwnerValue, write=SetUseOwnerValue, nodefault};
public:
	/* TdxScaleFactor.Create */ inline __fastcall TdxOwnedScaleFactor() : TdxScaleFactor() { }
	/* TdxScaleFactor.Destroy */ inline __fastcall virtual ~TdxOwnedScaleFactor() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxVectors : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod float __fastcall Angle(const TdxPointF &V1, const TdxPointF &V2)/* overload */;
	__classmethod float __fastcall Length(const TdxPointF &P1, const TdxPointF &P2)/* overload */;
	__classmethod float __fastcall Length(const TdxPointF &V)/* overload */;
	__classmethod float __fastcall Length(const float VX, const float VY)/* overload */;
	__classmethod TdxPointF __fastcall Normalize(const TdxPointF &V);
	__classmethod float __fastcall ScalarProduct(const TdxPointF &V1, const TdxPointF &V2);
	__classmethod TdxPointF __fastcall Scale(const TdxPointF &V, const float AScaleFactor);
public:
	/* TObject.Create */ inline __fastcall TdxVectors() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxVectors() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
#define cxBordersAll (System::Set<TcxBorder, TcxBorder::bLeft, TcxBorder::bBottom>() << TcxBorder::bLeft << TcxBorder::bTop << TcxBorder::bRight << TcxBorder::bBottom )
extern DELPHI_PACKAGE System::Types::TRect cxFullAreaRect;
extern DELPHI_PACKAGE tagXFORM cxIdentityMatrix;
extern DELPHI_PACKAGE System::Types::TPoint cxInvalidPoint;
extern DELPHI_PACKAGE System::Types::TRect cxInvalidRect;
extern DELPHI_PACKAGE System::Types::TSize cxInvalidSize;
extern DELPHI_PACKAGE System::Types::TPoint cxInvisiblePoint;
static const System::Word cxMaxRectSize = System::Word(0x7d00);
extern DELPHI_PACKAGE System::Types::TPoint cxSimplePoint;
extern DELPHI_PACKAGE System::Types::TRect cxSimpleRect;
extern DELPHI_PACKAGE System::Types::TPoint cxNullPoint;
extern DELPHI_PACKAGE TdxPointF dxNullPointF;
extern DELPHI_PACKAGE TdxPointDouble dxNullPointDouble;
extern DELPHI_PACKAGE System::Types::TRect cxNullRect;
extern DELPHI_PACKAGE TdxRectF dxNullRectF;
extern DELPHI_PACKAGE TdxRectDouble dxNullRectDouble;
extern DELPHI_PACKAGE System::Types::TSize cxNullSize;
extern DELPHI_PACKAGE int __fastcall cxHalfCoordinate(int ASize);
extern DELPHI_PACKAGE int __fastcall cxRectHeight(const System::Types::TRect &R)/* overload */;
extern DELPHI_PACKAGE float __fastcall cxRectHeight(const TdxRectF &R)/* overload */;
extern DELPHI_PACKAGE bool __fastcall cxRectIntersect(const System::Types::TRect &R1, const System::Types::TRect &R2)/* overload */;
extern DELPHI_PACKAGE bool __fastcall cxRectIntersect(const TdxRectF &R1, const TdxRectF &R2)/* overload */;
extern DELPHI_PACKAGE bool __fastcall cxRectIntersect(/* out */ System::Types::TRect &R, const System::Types::TRect &R1, const System::Types::TRect &R2)/* overload */;
extern DELPHI_PACKAGE bool __fastcall cxRectIntersect(/* out */ TdxRectF &R, const TdxRectF &R1, const TdxRectF &R2)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectInflate(const System::Types::TRect &R, int DX, int DY)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectInflate(const System::Types::TRect &R, int DX1, int DY1, int DX2, int DY2)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectInflate(const System::Types::TRect &R, int Delta)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectInflate(const System::Types::TRect &R, const System::Types::TRect &AMargins)/* overload */;
extern DELPHI_PACKAGE TdxRectF __fastcall cxRectInflate(const TdxRectF &R, float DX, float DY)/* overload */;
extern DELPHI_PACKAGE TdxRectF __fastcall cxRectInflate(const TdxRectF &R, float Delta)/* overload */;
extern DELPHI_PACKAGE TdxRectF __fastcall cxRectInflate(const TdxRectF &ARect, const TdxRectF &AMargins)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectInvert(const System::Types::TRect &R);
extern DELPHI_PACKAGE bool __fastcall cxRectIsEmpty(const System::Types::TRect &R)/* overload */;
extern DELPHI_PACKAGE bool __fastcall cxRectIsEmpty(const TdxRectF &R)/* overload */;
extern DELPHI_PACKAGE bool __fastcall cxRectIsEqual(const System::Types::TRect &R, const System::Types::TRect &R1);
extern DELPHI_PACKAGE bool __fastcall cxRectIsInvalid(const System::Types::TRect &R);
extern DELPHI_PACKAGE bool __fastcall cxRectIsNull(const System::Types::TRect &R);
extern DELPHI_PACKAGE int __fastcall cxRectGetItem(const System::Types::TRect &ARect, int AIndex);
extern DELPHI_PACKAGE int __fastcall cxRectGetSize(const System::Types::TRect &ARect, int AIndex);
extern DELPHI_PACKAGE System::Types::TPoint __fastcall cxRectLeftBottom(const System::Types::TRect &R);
extern DELPHI_PACKAGE void __fastcall cxRectMinMaxHeight(const System::Types::TRect &R, int &AMax, int &AMin);
extern DELPHI_PACKAGE void __fastcall cxRectMinMaxInit(int &AMin, int &AMax);
extern DELPHI_PACKAGE void __fastcall cxRectMinMaxWidth(const System::Types::TRect &R, int &AMax, int &AMin);
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectOffset(const System::Types::TRect &R, const System::Types::TPoint &P, bool APositiveFactor = true)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectOffset(const System::Types::TRect &R, int DX, int DY, bool APositiveFactor = true)/* overload */;
extern DELPHI_PACKAGE TdxRectF __fastcall cxRectOffset(const TdxRectF &R, const TdxPointF &P, bool APositiveFactor = true)/* overload */;
extern DELPHI_PACKAGE TdxRectF __fastcall cxRectOffset(const TdxRectF &R, float DX, float DY, bool APositiveFactor = true)/* overload */;
extern DELPHI_PACKAGE void __fastcall cxRectsOffset(TdxRectF *Rs, const int Rs_High, const TdxPointF &AOffset, bool APositiveFactor = true)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectOffset(const System::Types::TRect &R, const System::Types::TPoint *Ps, const int Ps_High, bool APositiveFactor = true)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectOffsetHorz(const System::Types::TRect &R, int DX);
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectOffsetVert(const System::Types::TRect &R, int DY);
extern DELPHI_PACKAGE void __fastcall cxRectOverlapped(const System::Types::TRect &ASrc, const System::Types::TRect &ADst, /* out */ System::Types::TRect &ASrcH, /* out */ System::Types::TRect &ASrcV, /* out */ System::Types::TRect &ADstH, /* out */ System::Types::TRect &ADstV);
extern DELPHI_PACKAGE bool __fastcall cxRectPtIn(const System::Types::TRect &R, const System::Types::TPoint &P)/* overload */;
extern DELPHI_PACKAGE bool __fastcall cxRectPtIn(const TdxRectF &R, const TdxPointF &P)/* overload */;
extern DELPHI_PACKAGE bool __fastcall cxRectPtIn(const System::Types::TRect &R, const int X, const int Y)/* overload */;
extern DELPHI_PACKAGE TcxPtInRectType __fastcall cxRectPtInEx(const System::Types::TRect &R, const int X, const int Y, int DL, int DT, int DR, int DB)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectRotate(const System::Types::TRect &R);
extern DELPHI_PACKAGE System::UnicodeString __fastcall cxRectToString(const System::Types::TRect &R);
extern DELPHI_PACKAGE TcxPtInRectType __fastcall cxRectPtInEx(const System::Types::TRect &R, int X, int Y, int ADelta)/* overload */;
extern DELPHI_PACKAGE TcxPtInRectType __fastcall cxRectPtInEx(const System::Types::TRect &R, int X, int Y, int ADeltaX, int ADeltaY)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRect(const System::Types::TSize &ASize)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRect(const int ALeft, const int ATop, const int ARight, const int ABottom)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRect(const System::Types::TPoint &ATopLeft, const System::Types::TPoint &ABottomRight)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRect(const TdxRectF &ARect, bool ATruncate = true)/* overload */;
extern DELPHI_PACKAGE TdxRectF __fastcall cxRectF(const TdxPointF &ATopLeft, const TdxPointF &ABottomRight)/* overload */;
extern DELPHI_PACKAGE TdxRectF __fastcall cxRectF(const float ALeft, const float ATop, const float ARight, const float ABottom)/* overload */;
extern DELPHI_PACKAGE TdxRectF __fastcall cxRectF(const System::Types::TRect &ARect)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectAdjust(const System::Types::TRect &R);
extern DELPHI_PACKAGE TdxRectF __fastcall cxRectAdjustF(const TdxRectF &R);
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectBounds(int ALeft, int ATop, int AWidth, int AHeight)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectBounds(int ALeft, int ATop, const System::Types::TSize &ASize)/* overload */;
extern DELPHI_PACKAGE TdxRectF __fastcall cxRectFBounds(float ALeft, float ATop, float AWidth, float AHeight)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectBounds(const System::Types::TPoint &P, int AWidth, int AHeight)/* overload */;
extern DELPHI_PACKAGE System::Types::TPoint __fastcall cxRectRightTop(const System::Types::TRect &R);
extern DELPHI_PACKAGE TdxRectF __fastcall cxRectScale(const TdxRectF &R, float AScaleFactor)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectScale(const System::Types::TRect &R, float AScaleFactor)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectScale(const System::Types::TRect &R, int ANumerator, int ADenominator)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectScale(const System::Types::TRect &R, int ANumeratorX, int ADenominatorX, int ANumeratorY, int ADenominatorY)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectScaleSize(const System::Types::TRect &R, int ANumerator, int ADenominator)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectScaleHeight(const System::Types::TRect &R, int Y1, int Y2, int H1, int H2);
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectScaleWidth(const System::Types::TRect &R, int X1, int X2, int W1, int W2);
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectSetBottom(const System::Types::TRect &R, int Y)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectSetBottom(const System::Types::TRect &R, int Y, int H)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectSetHeight(const System::Types::TRect &R, int H);
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectSetItem(const System::Types::TRect &R, int AIndex, int AValue);
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectSetLeft(const System::Types::TRect &R, int X)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectSetLeft(const System::Types::TRect &R, int X, int W)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectSetOrigin(const System::Types::TRect &R, const System::Types::TPoint &APos);
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectSetNullOrigin(const System::Types::TRect &R);
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectSetTop(const System::Types::TRect &R, int Y)/* overload */;
extern DELPHI_PACKAGE TdxRectF __fastcall cxRectSetTop(const TdxRectF &R, float Y)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectSetTop(const System::Types::TRect &R, int Y, int H)/* overload */;
extern DELPHI_PACKAGE TdxRectF __fastcall cxRectSetTop(const TdxRectF &R, float Y, float H)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectSetRight(const System::Types::TRect &R, int X)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectSetRight(const System::Types::TRect &R, int X, int W)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectSetSize(const System::Types::TRect &R, int W, int H)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectSetSize(const System::Types::TRect &R, const System::Types::TSize &ASize)/* overload */;
extern DELPHI_PACKAGE TdxRectF __fastcall cxRectSetSizeF(const TdxRectF &R, const TdxSizeF &ASize)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectSetWidth(const System::Types::TRect &R, int W)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectSetWidth(const System::Types::TRect &R, int X, int W)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectSetXPos(const System::Types::TRect &R, int X1, int X2);
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectSetYPos(const System::Types::TRect &R, int Y1, int Y2);
extern DELPHI_PACKAGE System::Types::TSize __fastcall cxRectSize(const System::Types::TRect &R);
extern DELPHI_PACKAGE void __fastcall cxRectSplitHorz(const System::Types::TRect &ABounds, System::Types::TRect &ARect1, System::Types::TRect &ARect2);
extern DELPHI_PACKAGE int __fastcall cxRectSquare(const System::Types::TRect &R);
extern DELPHI_PACKAGE void __fastcall cxRectSplitVert(const System::Types::TRect &ABounds, System::Types::TRect &ARect1, System::Types::TRect &ARect2);
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectTransform(const System::Types::TRect &ARect, int ALeftOffset, int ATopOffset, int ARightOffset, int ABottomOffset)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectTransform(const System::Types::TRect &ARect, const System::Types::TRect &AOffsets)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectUnion(const System::Types::TRect &R1, const System::Types::TRect &R2)/* overload */;
extern DELPHI_PACKAGE TdxRectF __fastcall cxRectUnion(const TdxRectF &R1, const TdxRectF &R2)/* overload */;
extern DELPHI_PACKAGE int __fastcall cxRectWidth(const System::Types::TRect &R)/* overload */;
extern DELPHI_PACKAGE float __fastcall cxRectWidth(const TdxRectF &R)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectProportionalStretch(const System::Types::TRect &R, const System::Types::TSize &ASize)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectProportionalStretch(const System::Types::TRect &R, int W, int H)/* overload */;
extern DELPHI_PACKAGE TdxRectF __fastcall cxRotatedRectBox(const TdxRectF &R, const TdxPointF &APivotPoint, float AAngle);
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxBordersSizeRect(const TcxBorders ABorders, const int ABorderWidth)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxBordersSizeRect(const TcxBorders ABorders, const System::Types::TRect &ARect)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxMargins(const System::Types::TRect &ARect, const System::Types::TRect &AContentRect);
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxMarginsCombine(const System::Types::TRect &R1, const System::Types::TRect &R2);
extern DELPHI_PACKAGE int __fastcall cxMarginsHeight(const System::Types::TRect &R);
extern DELPHI_PACKAGE int __fastcall cxMarginsWidth(const System::Types::TRect &R);
extern DELPHI_PACKAGE bool __fastcall cxRectCompare(const System::Types::TRect &R1, const System::Types::TRect &R2);
extern DELPHI_PACKAGE System::Types::TPoint __fastcall cxRectCenter(const System::Types::TRect &R)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectCenter(const System::Types::TRect &ABounds, const System::Types::TSize &ASize)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectCenter(const System::Types::TRect &ABounds, int AWidth, int AHeight)/* overload */;
extern DELPHI_PACKAGE TdxRectF __fastcall cxRectCenter(const TdxRectF &ABounds, const TdxSizeF &ASize)/* overload */;
extern DELPHI_PACKAGE TdxRectF __fastcall cxRectCenter(const TdxRectF &ABounds, float AWidth, float AHeight)/* overload */;
extern DELPHI_PACKAGE TdxPointF __fastcall cxRectCenter(const TdxRectF &R)/* overload */;
extern DELPHI_PACKAGE TdxRectF __fastcall cxRectCenterHorizontally(const TdxRectF &R, const double AWidth)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectCenterHorizontally(const System::Types::TRect &R, int AWidth)/* overload */;
extern DELPHI_PACKAGE TdxRectF __fastcall cxRectCenterVertically(const TdxRectF &R, const double AHeight)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectCenterVertically(const System::Types::TRect &R, int AHeight)/* overload */;
extern DELPHI_PACKAGE bool __fastcall cxRectContain(const System::Types::TRect &ABounds, const System::Types::TRect &AInner);
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectContent(const System::Types::TRect &R, const System::Types::TRect &AMargins)/* overload */;
extern DELPHI_PACKAGE TdxRectF __fastcall cxRectContent(const TdxRectF &R, const TdxRectF &AMargins)/* overload */;
extern DELPHI_PACKAGE float __fastcall cxPointDistance(const System::Types::TPoint &P1, const System::Types::TPoint &P2);
extern DELPHI_PACKAGE float __fastcall cxPointDistanceF(const TdxPointF &P1, const TdxPointF &P2);
extern DELPHI_PACKAGE System::Types::TPoint __fastcall cxPointInvert(const System::Types::TPoint &P)/* overload */;
extern DELPHI_PACKAGE bool __fastcall cxPointInLine(const TdxPointF &P, const TdxPointF &LinePoint1, const TdxPointF &LinePoint2)/* overload */;
extern DELPHI_PACKAGE bool __fastcall cxPointInLine(const System::Types::TPoint &P, const System::Types::TPoint &LinePoint1, const System::Types::TPoint &LinePoint2)/* overload */;
extern DELPHI_PACKAGE bool __fastcall cxPointIsEqual(const System::Types::TPoint &P1, const System::Types::TPoint &P2)/* overload */;
extern DELPHI_PACKAGE bool __fastcall cxPointIsEqual(const TdxPointF &P1, const TdxPointF &P2)/* overload */;
extern DELPHI_PACKAGE bool __fastcall cxPointIsInvalid(const System::Types::TPoint &P);
extern DELPHI_PACKAGE bool __fastcall cxPointIsNull(const System::Types::TPoint &P)/* overload */;
extern DELPHI_PACKAGE int __fastcall cxPointGetItem(const System::Types::TPoint &P, int AIndex);
extern DELPHI_PACKAGE System::Types::TPoint __fastcall cxPointOffset(const System::Types::TPoint &P, const System::Types::TPoint *Ps, const int Ps_High, bool APositiveFactor = true)/* overload */;
extern DELPHI_PACKAGE System::Types::TPoint __fastcall cxPointOffset(const System::Types::TPoint &P, int X, int Y, bool APositiveFactor = true)/* overload */;
extern DELPHI_PACKAGE System::Types::TPoint __fastcall cxPointOffset(const System::Types::TPoint &P, int ADelta)/* overload */;
extern DELPHI_PACKAGE System::Types::TPoint __fastcall cxPointOffset(const System::Types::TPoint &P, const System::Types::TPoint &DP, bool APositiveFactor = true)/* overload */;
extern DELPHI_PACKAGE TdxPointF __fastcall cxPointOffset(const TdxPointF &P, const TdxPointF &AOffset, bool APositiveFactor = true)/* overload */;
extern DELPHI_PACKAGE TdxPointF __fastcall cxPointOffset(const TdxPointF &P, float X, float Y, bool APositiveFactor = true)/* overload */;
extern DELPHI_PACKAGE void __fastcall cxPointsOffset(TdxPointF *Ps, const int Ps_High, const TdxPointF &AOffset)/* overload */;
extern DELPHI_PACKAGE System::Types::TPoint __fastcall cxPointReplaceItem(const System::Types::TPoint &P, const int AIndex, const int AValue);
extern DELPHI_PACKAGE System::Types::TPoint __fastcall cxPoint(int X, int Y)/* overload */;
extern DELPHI_PACKAGE System::Types::TPoint __fastcall cxPoint(const TdxPointF &APointF, bool AUsedTrunc = true)/* overload */;
extern DELPHI_PACKAGE System::Types::TPoint __fastcall cxPoint(const System::Types::TSize &ASize)/* overload */;
extern DELPHI_PACKAGE TdxPointF __fastcall cxPointF(float X, float Y)/* overload */;
extern DELPHI_PACKAGE TdxPointF __fastcall cxPointF(const System::Types::TPoint &P)/* overload */;
extern DELPHI_PACKAGE System::Types::TPoint __fastcall cxPointSum(const System::Types::TPoint *Ps, const int Ps_High);
extern DELPHI_PACKAGE System::Types::TPoint __fastcall cxPointScale(const System::Types::TPoint &P, int ANumerator, int ADenominator)/* overload */;
extern DELPHI_PACKAGE TdxPointF __fastcall cxPointScale(const TdxPointF &P, float AScaleFactor)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxPointsBox(const System::Types::TPoint *Ps, const int Ps_High)/* overload */;
extern DELPHI_PACKAGE TdxRectF __fastcall cxPointsBox(const TdxPointF *Ps, const int Ps_High)/* overload */;
extern DELPHI_PACKAGE TdxRectF __fastcall cxPointsBox(PdxPointF APoints, int ACount)/* overload */;
extern DELPHI_PACKAGE void __fastcall cxPointsOffset(System::Types::TPoint *Ps, const int Ps_High, int DX, int DY)/* overload */;
extern DELPHI_PACKAGE void __fastcall cxPointsOffset(System::Types::TPoint *Ps, const int Ps_High, const System::Types::TPoint &AOffset)/* overload */;
extern DELPHI_PACKAGE System::Types::TSize __fastcall cxSize(int XY)/* overload */;
extern DELPHI_PACKAGE System::Types::TSize __fastcall cxSize(int DX, int DY)/* overload */;
extern DELPHI_PACKAGE System::Types::TSize __fastcall cxSize(const System::Types::TPoint &P)/* overload */;
extern DELPHI_PACKAGE System::Types::TSize __fastcall cxSize(const System::Types::TRect &R)/* overload */;
extern DELPHI_PACKAGE System::Types::TSize __fastcall cxSize(const TdxSizeF &S, bool AUseTrunc = true)/* overload */;
extern DELPHI_PACKAGE System::Types::TSize __fastcall cxSizeAddMargins(const System::Types::TSize &S, const System::Types::TRect &AMargins);
extern DELPHI_PACKAGE System::Types::TSize __fastcall cxSizeAddPadding(const System::Types::TSize &S, const System::Types::TRect &APadding);
extern DELPHI_PACKAGE bool __fastcall cxSizeIsEmpty(const System::Types::TSize &S1);
extern DELPHI_PACKAGE bool __fastcall cxSizeIsValid(const System::Types::TSize &S1);
extern DELPHI_PACKAGE bool __fastcall cxSizeIsEqual(const System::Types::TSize &S1, const System::Types::TSize &S2)/* overload */;
extern DELPHI_PACKAGE bool __fastcall cxSizeIsEqual(const TdxRectF &R1, const TdxRectF &R2, float ATolerance = 0.000000E+00f)/* overload */;
extern DELPHI_PACKAGE bool __fastcall cxSizeIsEqual(const System::Types::TRect &R1, const System::Types::TRect &R2)/* overload */;
extern DELPHI_PACKAGE System::Types::TSize __fastcall cxSizeMin(const System::Types::TSize &S1, const System::Types::TSize &S2)/* overload */;
extern DELPHI_PACKAGE System::Types::TSize __fastcall cxSizeMax(const System::Types::TSize &S1, const System::Types::TSize &S2)/* overload */;
extern DELPHI_PACKAGE TdxSizeF __fastcall cxSizeMax(const TdxSizeF &S1, const TdxSizeF &S2)/* overload */;
extern DELPHI_PACKAGE System::Types::TSize __fastcall cxSizeProportionalStretch(const System::Types::TSize &S, const System::Types::TSize &ASize)/* overload */;
extern DELPHI_PACKAGE System::Types::TSize __fastcall cxSizeProportionalStretch(const System::Types::TSize &S, int W, int H)/* overload */;
extern DELPHI_PACKAGE System::Types::TSize __fastcall cxSizeScale(const System::Types::TSize &S, float AScaleFactor)/* overload */;
extern DELPHI_PACKAGE TdxSizeF __fastcall cxSizeScale(const TdxSizeF &S, float AScaleFactor)/* overload */;
extern DELPHI_PACKAGE System::Types::TSize __fastcall cxSizeScale(const System::Types::TSize &S, int ANumerator, int ADenominator)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall cxSizeToString(const System::Types::TSize &S);
extern DELPHI_PACKAGE bool __fastcall cxTryStringToSize(const System::UnicodeString S, /* out */ System::Types::TSize &ASize);
extern DELPHI_PACKAGE void __fastcall dxCalcPosition(const int ANumerator, const int ACount, const float ASize, const float AStartOffset, const float AItemsIndent, float &AStart, float &AFinish);
extern DELPHI_PACKAGE System::Types::TRect __fastcall dxEllipse(const System::Types::TPoint &ACenter, int ARadius)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall dxEllipse(const System::Types::TPoint &ACenter, int ARadiusX, int ARadiusY)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall dxEllipse(const int ACenterX, const int ACenterY, const int ARadiusX, const int ARadiusY)/* overload */;
extern DELPHI_PACKAGE TdxRectF __fastcall dxEllipseF(const TdxPointF &ACenter, float ARadius)/* overload */;
extern DELPHI_PACKAGE TdxRectF __fastcall dxEllipseF(const TdxPointF &ACenter, float ARadiusX, float ARadiusY)/* overload */;
extern DELPHI_PACKAGE TdxRectF __fastcall dxEllipseF(const float ACenterX, const float ACenterY, const float ARadiusX, const float ARadiusY)/* overload */;
extern DELPHI_PACKAGE bool __fastcall dxEllipsePtIn(const TdxPointF &Center, float RadiusX, float RadiusY, const TdxPointF &P)/* overload */;
extern DELPHI_PACKAGE bool __fastcall dxEllipsePtIn(const TdxRectF &Ellipse, const TdxPointF &P)/* overload */;
extern DELPHI_PACKAGE bool __fastcall dxEllipseRectIn(const TdxPointF &Center, float RadiusX, float RadiusY, const TdxRectF &R);
extern DELPHI_PACKAGE double __fastcall dxScale(const double AValue, const double M, const double D);
extern DELPHI_PACKAGE TdxPointF __fastcall dxPointF(float X, float Y)/* overload */;
extern DELPHI_PACKAGE TdxPointF __fastcall dxPointF(const System::Types::TPoint &P)/* overload */;
extern DELPHI_PACKAGE TdxSizeF __fastcall dxSizeF(float DX, float DY)/* overload */;
extern DELPHI_PACKAGE TdxSizeF __fastcall dxSizeF(const System::Types::TSize &ASize)/* overload */;
extern DELPHI_PACKAGE TdxRectF __fastcall dxRectF(const float ALeft, const float ATop, const float ARight, const float ABottom)/* overload */;
extern DELPHI_PACKAGE TdxRectF __fastcall dxRectF(const System::Types::TRect &ARect)/* overload */;
extern DELPHI_PACKAGE bool __fastcall dxRingPtIn(const System::Types::TRect &ARingRect, const System::Types::TPoint &P);
extern DELPHI_PACKAGE float __fastcall dxRingAngle(const TdxPointF &ABase, const TdxPointF &APoint);
extern DELPHI_PACKAGE TdxPointF __fastcall dxRingPoint(const TdxPointF &ABase, float ARadius, float AAngle);
extern DELPHI_PACKAGE TdxPointF __fastcall dxRingRelativePoint(const TdxPointF &ABase, const TdxPointF &APoint);
extern DELPHI_PACKAGE TdxPointF __fastcall dxRingRotatePoint(const TdxPointF &ABase, const TdxPointF &APoint, float AAngle);
extern DELPHI_PACKAGE void __fastcall dxRingRotatePoints(const TdxPointF &ABase, TdxPointF *APoints, const int APoints_High, float AAngle);
extern DELPHI_PACKAGE double __fastcall dxNormalizeAngle(const double AAngleInDegrees);
extern DELPHI_PACKAGE void __fastcall dxCalculateArcAngles(const TdxRectF &AEllipse, const TdxPointF &AStartPoint, const TdxPointF &AEndPoint, /* out */ float &AStartAngle, /* out */ float &ASweepAngle);
extern DELPHI_PACKAGE void __fastcall dxCalculateArcSegment(const TdxRectF &AEllipse, float AStartAngle, float ASweepAngle, /* out */ TdxPointF &AStartPoint, /* out */ TdxPointF &AEndPoint)/* overload */;
extern DELPHI_PACKAGE void __fastcall dxCalculateArcSegment(const float ACenterX, const float ACenterY, const float ARadiusX, const float ARadiusY, const float AStartAngle, const float ASweepAngle, /* out */ TdxPointF &AStartPoint, /* out */ TdxPointF &AEndPoint)/* overload */;
extern DELPHI_PACKAGE bool __fastcall dxCalculateIntersectionBetweenLines(const TdxPointF &ALine1Point1, const TdxPointF &ALine1Point2, bool AIsLine1Segment, const TdxPointF &ALine2Point1, const TdxPointF &ALine2Point2, bool AIsLine2Segment, /* out */ TdxPointF &APoint);
extern DELPHI_PACKAGE TdxPointsF __fastcall dxCalculateIntersectionBetweenLineAndRect(const TdxRectF &ARect, const TdxPointF &ALinePoint1, const TdxPointF &ALinePoint2, bool AIsLineSegment = true);
extern DELPHI_PACKAGE void __fastcall dxCalculateOptimalInscribedRect(const TdxRectF &ABox, float AAngle, /* out */ float &AWidth, /* out */ float &AHeight, /* out */ TdxPointF &ATopLeft, /* out */ TdxPointF &ATopRight, /* out */ TdxPointF &ABottomRight, /* out */ TdxPointF &ABottomLeft);
extern DELPHI_PACKAGE System::Generics::Collections::TList__1<float>* __fastcall dxCalculateQuadraticEquation(float A, float B, float C);
extern DELPHI_PACKAGE System::Generics::Collections::TList__1<TdxPointF>* __fastcall dxCalculateIntersectionBetweenLineAndEllipse(const TdxPointF &ASegmentPoint1, const TdxPointF &ASegmentPoint2, const TdxPointF &ALeftTopEllipseRect, const TdxPointF &ARightBottomEllipseRect);
extern DELPHI_PACKAGE System::Generics::Collections::TList__1<TdxPointF>* __fastcall dxCalculateIntersectionBetweenRectAndEllipse(const TdxRectF &ARect, const TdxRectF &AEllipse);
extern DELPHI_PACKAGE TdxSizeDouble __fastcall dxSizeDouble(double AWidth, double AHeight);
extern DELPHI_PACKAGE bool __fastcall dxSizeDoubleIsEqual(const TdxSizeDouble &ASize1, const TdxSizeDouble &ASize2);
extern DELPHI_PACKAGE TdxSizeDouble __fastcall dxSizeDoubleScale(const TdxSizeDouble &ASize, const TdxPointDouble &AScale);
extern DELPHI_PACKAGE TdxPointDouble __fastcall dxPointDouble(double X, double Y)/* overload */;
extern DELPHI_PACKAGE TdxPointDouble __fastcall dxPointDouble(const System::Types::TPoint &APoint)/* overload */;
extern DELPHI_PACKAGE TdxPointDouble __fastcall dxPointDouble(const TdxPointF &APoint)/* overload */;
extern DELPHI_PACKAGE bool __fastcall dxPointDoubleIsEqual(const TdxPointDouble &APoint1, const TdxPointDouble &APoint2);
extern DELPHI_PACKAGE System::Types::TPoint __fastcall dxPointDoubleToPoint(const TdxPointDouble &APoint);
extern DELPHI_PACKAGE TdxPointF __fastcall dxPointDoubleToPointF(const TdxPointDouble &APoint);
extern DELPHI_PACKAGE TdxPointDouble __fastcall dxPointDoubleOffset(const TdxPointDouble &APoint, double X, double Y, bool APositiveFactor = true)/* overload */;
extern DELPHI_PACKAGE TdxPointDouble __fastcall dxPointDoubleOffset(const TdxPointDouble &APoint, const TdxPointDouble &AOffset, bool APositiveFactor = true)/* overload */;
extern DELPHI_PACKAGE TdxPointDouble __fastcall dxPointDoubleScale(const TdxPointDouble &APoint, const double AScale)/* overload */;
extern DELPHI_PACKAGE TdxPointDouble __fastcall dxPointDoubleScale(const TdxPointDouble &APoint, const TdxPointDouble &AScale)/* overload */;
extern DELPHI_PACKAGE TdxRectDouble __fastcall dxRectDouble(double ALeft, double ATop, double AWidth, double AHeight)/* overload */;
extern DELPHI_PACKAGE TdxRectDouble __fastcall dxRectDouble(const TdxPointDouble &ATopLeft, const TdxPointDouble &ABottomRight)/* overload */;
extern DELPHI_PACKAGE TdxRectDouble __fastcall dxRectDouble(const System::Types::TRect &ARect)/* overload */;
extern DELPHI_PACKAGE bool __fastcall dxRectDoubleIntersect(const TdxRectDouble &ARect1, const TdxRectDouble &ARect2);
extern DELPHI_PACKAGE bool __fastcall dxRectDoubleIsEmpty(const TdxRectDouble &ARect);
extern DELPHI_PACKAGE bool __fastcall dxRectDoubleIsEqual(const TdxRectDouble &ARect1, const TdxRectDouble &ARect2);
extern DELPHI_PACKAGE TdxRectDouble __fastcall dxRectDoubleOffset(const TdxRectDouble &ARect, const TdxPointDouble &APoint, bool APositiveFactor = true);
extern DELPHI_PACKAGE System::Types::TRect __fastcall dxRectDoubleToRect(const TdxRectDouble &AMapRect);
extern DELPHI_PACKAGE TdxRectF __fastcall dxRectDoubleToRectF(const TdxRectDouble &AMapRect);
extern DELPHI_PACKAGE void __fastcall cxReduceFraction(int &A, int &B);
}	/* namespace Cxgeometry */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXGEOMETRY)
using namespace Cxgeometry;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxgeometryHPP
