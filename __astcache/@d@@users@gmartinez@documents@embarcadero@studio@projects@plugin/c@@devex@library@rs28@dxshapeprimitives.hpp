// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxShapePrimitives.pas' rev: 35.00 (Windows)

#ifndef DxshapeprimitivesHPP
#define DxshapeprimitivesHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <System.TypInfo.hpp>
#include <System.Contnrs.hpp>
#include <dxCore.hpp>
#include <dxCoreGraphics.hpp>
#include <cxClasses.hpp>
#include <cxGeometry.hpp>
#include <dxGDIPlusAPI.hpp>
#include <dxGDIPlusClasses.hpp>
#include <dxXMLDoc.hpp>

//-- user supplied -----------------------------------------------------------

namespace Dxshapeprimitives
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TdxShapeList;
class DELPHICLASS TdxShapeObject;
class DELPHICLASS TdxCustomVectorShape;
class DELPHICLASS TdxShapeRectangle;
class DELPHICLASS TdxShapeEllipse;
class DELPHICLASS TdxShapePath;
class DELPHICLASS TdxShapeCanvas;
class DELPHICLASS TdxShapeViewBox;
class DELPHICLASS TdxShapeFakeBrush;
class DELPHICLASS TdxShapeFakeGradientStops;
class DELPHICLASS TdxShapeFakeCustomTransformation;
class DELPHICLASS TdxShapeFakeRenderTransformation;
class DELPHICLASS TdxShapeFakeRelativeTransformation;
class DELPHICLASS TdxShapeObjectReader;
class DELPHICLASS TdxShapeTransformations;
class DELPHICLASS TdxShapeCustomBrush;
class DELPHICLASS TdxShapeCustomTransformation;
class DELPHICLASS TdxShapePathDataParser;
class DELPHICLASS TdxShapesFactory;
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TdxShapeBrushClass;

typedef System::TMetaClass* TdxShapeObjectClass;

typedef System::TMetaClass* TdxShapeObjectReaderClass;

enum DECLSPEC_DENUM TdxShapeTransformationType : unsigned char { dxsttScale, dxsttSkew, dxsttRotate, dxsttTranslate };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxShapeList : public Cxclasses::TcxObjectList
{
	typedef Cxclasses::TcxObjectList inherited;
	
protected:
	virtual void __fastcall FreeItem(int AIndex);
public:
	/* TcxObjectList.Create */ inline __fastcall TdxShapeList(bool AOwnObjects) : Cxclasses::TcxObjectList(AOwnObjects) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxShapeList() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TdxShapeObject : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	int FLockCount;
	TdxShapeObject* FParent;
	TdxShapeTransformations* FTransformations;
	Dxgdiplusclasses::TdxGPMatrix* FTransformMatrix;
	Cxgeometry::TdxPointF FTransformOrigin;
	System::Classes::TNotifyEvent FOnChange;
	System::UnicodeString __fastcall GetRenderTransformOrigin();
	void __fastcall SetRenderTransformOrigin(const System::UnicodeString AValue);
	void __fastcall TransformationsChanged(System::TObject* ASender);
	
protected:
	virtual void __fastcall Calculate();
	virtual void __fastcall Changed();
	virtual void __fastcall SetTransformMatrix(Dxgdiplusclasses::TdxGPMatrix* const AValue);
	__property TdxShapeObject* Parent = {read=FParent, write=FParent};
	__property TdxShapeTransformations* Transformations = {read=FTransformations};
	__property Dxgdiplusclasses::TdxGPMatrix* TransformMatrix = {read=FTransformMatrix, write=SetTransformMatrix};
	
public:
	__fastcall virtual TdxShapeObject()/* overload */;
	__fastcall virtual TdxShapeObject(TdxShapeObject* AParent)/* overload */;
	__fastcall virtual ~TdxShapeObject();
	virtual void __fastcall Assign(System::Classes::TPersistent* ASource);
	void __fastcall BeginUpdate();
	void __fastcall EndUpdate();
	void __fastcall CancelUpdate();
	__classmethod virtual System::UnicodeString __fastcall GetName();
	__classmethod virtual TdxShapeObjectReaderClass __fastcall GetReaderClass();
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	
__published:
	__property System::UnicodeString RenderTransformOrigin = {read=GetRenderTransformOrigin, write=SetRenderTransformOrigin};
};


class PASCALIMPLEMENTATION TdxCustomVectorShape : public TdxShapeObject
{
	typedef TdxShapeObject inherited;
	
private:
	TdxShapeCustomBrush* FBrush;
	Dxgdiplusclasses::TdxGPPen* FGPPen;
	System::UnicodeString FName;
	Dxgdiplusclasses::TdxGPPath* FPath;
	int FRefCount;
	Cxgeometry::TdxRectF FBounds;
	float FHeight;
	Cxgeometry::TdxPointF FTopLeft;
	float FWidth;
	void __fastcall SetBrush(TdxShapeCustomBrush* const AValue);
	void __fastcall SetLeft(const float AValue);
	void __fastcall SetHeight(const float AValue);
	void __fastcall SetStroke(const System::UnicodeString AValue);
	void __fastcall SetStrokeThickness(const float AValue);
	void __fastcall SetTop(const float AValue);
	void __fastcall SetWidth(const float AValue);
	Dxgdiplusclasses::TdxGPPath* __fastcall CreatePath();
	Dxgdiplusclasses::TdxGPPath* __fastcall GetPath();
	bool __fastcall NeedCreatePath();
	void __fastcall ApplyTransformation(TdxShapeCustomTransformation* ATransformation);
	void __fastcall BrushChangeHandler(System::TObject* ASender);
	void __fastcall CalculateTransformMatrix();
	void __fastcall DoApplyTransformation(TdxShapeTransformationType AType, float M11, float M12, float M21, float M22, float DX, float DY);
	
protected:
	virtual void __fastcall SetTransformMatrix(Dxgdiplusclasses::TdxGPMatrix* const AValue);
	virtual Cxgeometry::TdxRectF __fastcall GetContentBounds();
	virtual void __fastcall Calculate();
	virtual void __fastcall CreatePathContent(Dxgdiplusclasses::TdxGPPath* &APath);
	virtual void __fastcall Draw(Dxgdiplusclasses::TdxGPGraphics* AGraphics);
	virtual void __fastcall SetColor(Dxcoregraphics::TdxAlphaColor AAlphaColor);
	void __fastcall Reference();
	void __fastcall Release();
	__property Cxgeometry::TdxRectF Bounds = {read=FBounds};
	__property TransformMatrix;
	__property Dxgdiplusclasses::TdxGPPen* Pen = {read=FGPPen};
	
public:
	__fastcall virtual TdxCustomVectorShape()/* overload */;
	__fastcall virtual ~TdxCustomVectorShape();
	virtual void __fastcall Assign(System::Classes::TPersistent* ASource);
	__property Cxgeometry::TdxRectF ContentBounds = {read=GetContentBounds};
	
__published:
	__property TdxShapeCustomBrush* Brush = {read=FBrush, write=SetBrush};
	__property float Left = {read=FTopLeft.X, write=SetLeft};
	__property System::UnicodeString Name = {read=FName, write=FName};
	__property float Height = {read=FHeight, write=SetHeight};
	__property float Top = {read=FTopLeft.Y, write=SetTop};
	__property float Width = {read=FWidth, write=SetWidth};
	__property System::UnicodeString Stroke = {write=SetStroke};
	__property float StrokeThickness = {write=SetStrokeThickness};
public:
	/* TdxShapeObject.Create */ inline __fastcall virtual TdxCustomVectorShape(TdxShapeObject* AParent)/* overload */ : TdxShapeObject(AParent) { }
	
};


class PASCALIMPLEMENTATION TdxShapeRectangle : public TdxCustomVectorShape
{
	typedef TdxCustomVectorShape inherited;
	
private:
	Cxgeometry::TdxPointF FRadius;
	void __fastcall SetRadiusX(const float AValue);
	void __fastcall SetRadiusY(const float AValue);
	
protected:
	virtual void __fastcall CreatePathContent(Dxgdiplusclasses::TdxGPPath* &APath);
	
public:
	__fastcall virtual TdxShapeRectangle()/* overload */;
	__classmethod virtual System::UnicodeString __fastcall GetName();
	
__published:
	__property float RadiusX = {read=FRadius.X, write=SetRadiusX};
	__property float RadiusY = {read=FRadius.Y, write=SetRadiusY};
public:
	/* TdxCustomVectorShape.Destroy */ inline __fastcall virtual ~TdxShapeRectangle() { }
	
public:
	/* TdxShapeObject.Create */ inline __fastcall virtual TdxShapeRectangle(TdxShapeObject* AParent)/* overload */ : TdxCustomVectorShape(AParent) { }
	
};


class PASCALIMPLEMENTATION TdxShapeEllipse : public TdxCustomVectorShape
{
	typedef TdxCustomVectorShape inherited;
	
protected:
	virtual void __fastcall CreatePathContent(Dxgdiplusclasses::TdxGPPath* &APath);
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetName();
public:
	/* TdxCustomVectorShape.Create */ inline __fastcall virtual TdxShapeEllipse()/* overload */ : TdxCustomVectorShape() { }
	/* TdxCustomVectorShape.Destroy */ inline __fastcall virtual ~TdxShapeEllipse() { }
	
public:
	/* TdxShapeObject.Create */ inline __fastcall virtual TdxShapeEllipse(TdxShapeObject* AParent)/* overload */ : TdxCustomVectorShape(AParent) { }
	
};


class PASCALIMPLEMENTATION TdxShapePath : public TdxCustomVectorShape
{
	typedef TdxCustomVectorShape inherited;
	
private:
	System::AnsiString FData;
	Dxgdiplusapi::TdxGpPointFDynArray FNormalizedPoints;
	Dxgdiplusapi::TdxGpPointFDynArray FPoints;
	System::DynamicArray<System::Byte> FPointTypes;
	void __fastcall SetData(const System::AnsiString AValue);
	Cxgeometry::TdxRectF __fastcall GetPathBounds();
	void __fastcall CalculatePoints();
	
protected:
	virtual Cxgeometry::TdxRectF __fastcall GetContentBounds();
	virtual void __fastcall Calculate();
	virtual void __fastcall CreatePathContent(Dxgdiplusclasses::TdxGPPath* &APath);
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetName();
	
__published:
	__property System::AnsiString Data = {read=FData, write=SetData};
public:
	/* TdxCustomVectorShape.Create */ inline __fastcall virtual TdxShapePath()/* overload */ : TdxCustomVectorShape() { }
	/* TdxCustomVectorShape.Destroy */ inline __fastcall virtual ~TdxShapePath() { }
	
public:
	/* TdxShapeObject.Create */ inline __fastcall virtual TdxShapePath(TdxShapeObject* AParent)/* overload */ : TdxCustomVectorShape(AParent) { }
	
};


class PASCALIMPLEMENTATION TdxShapeCanvas : public TdxCustomVectorShape
{
	typedef TdxCustomVectorShape inherited;
	
private:
	bool FIsRoot;
	TdxShapeList* FShapes;
	int __fastcall GetCount();
	TdxCustomVectorShape* __fastcall GetShape(int AIndex);
	
protected:
	virtual Cxgeometry::TdxRectF __fastcall GetContentBounds();
	void __fastcall Add(TdxCustomVectorShape* AShape);
	virtual void __fastcall Calculate();
	virtual void __fastcall Draw(Dxgdiplusclasses::TdxGPGraphics* AGraphics);
	void __fastcall SetShapeColor(Dxcoregraphics::TdxAlphaColor AAlphaColor, const System::UnicodeString AShapeName);
	__property bool IsRoot = {read=FIsRoot, write=FIsRoot, nodefault};
	
public:
	__fastcall virtual TdxShapeCanvas()/* overload */;
	__fastcall virtual ~TdxShapeCanvas();
	__classmethod virtual System::UnicodeString __fastcall GetName();
	__classmethod virtual TdxShapeObjectReaderClass __fastcall GetReaderClass();
	__property int Count = {read=GetCount, nodefault};
	__property TdxCustomVectorShape* Shapes[int Index] = {read=GetShape};
public:
	/* TdxShapeObject.Create */ inline __fastcall virtual TdxShapeCanvas(TdxShapeObject* AParent)/* overload */ : TdxCustomVectorShape(AParent) { }
	
};


class PASCALIMPLEMENTATION TdxShapeViewBox : public TdxShapeCanvas
{
	typedef TdxShapeCanvas inherited;
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetName();
public:
	/* TdxShapeCanvas.Create */ inline __fastcall virtual TdxShapeViewBox()/* overload */ : TdxShapeCanvas() { }
	/* TdxShapeCanvas.Destroy */ inline __fastcall virtual ~TdxShapeViewBox() { }
	
public:
	/* TdxShapeObject.Create */ inline __fastcall virtual TdxShapeViewBox(TdxShapeObject* AParent)/* overload */ : TdxShapeCanvas(AParent) { }
	
};


class PASCALIMPLEMENTATION TdxShapeFakeBrush : public TdxShapeObject
{
	typedef TdxShapeObject inherited;
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetName();
	__classmethod virtual TdxShapeObjectReaderClass __fastcall GetReaderClass();
public:
	/* TdxShapeObject.Create */ inline __fastcall virtual TdxShapeFakeBrush()/* overload */ : TdxShapeObject() { }
	/* TdxShapeObject.Create */ inline __fastcall virtual TdxShapeFakeBrush(TdxShapeObject* AParent)/* overload */ : TdxShapeObject(AParent) { }
	/* TdxShapeObject.Destroy */ inline __fastcall virtual ~TdxShapeFakeBrush() { }
	
};


class PASCALIMPLEMENTATION TdxShapeFakeGradientStops : public TdxShapeObject
{
	typedef TdxShapeObject inherited;
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetName();
	__classmethod virtual TdxShapeObjectReaderClass __fastcall GetReaderClass();
public:
	/* TdxShapeObject.Create */ inline __fastcall virtual TdxShapeFakeGradientStops()/* overload */ : TdxShapeObject() { }
	/* TdxShapeObject.Create */ inline __fastcall virtual TdxShapeFakeGradientStops(TdxShapeObject* AParent)/* overload */ : TdxShapeObject(AParent) { }
	/* TdxShapeObject.Destroy */ inline __fastcall virtual ~TdxShapeFakeGradientStops() { }
	
};


class PASCALIMPLEMENTATION TdxShapeFakeCustomTransformation : public TdxShapeObject
{
	typedef TdxShapeObject inherited;
	
public:
	__classmethod virtual TdxShapeObjectReaderClass __fastcall GetReaderClass();
public:
	/* TdxShapeObject.Create */ inline __fastcall virtual TdxShapeFakeCustomTransformation()/* overload */ : TdxShapeObject() { }
	/* TdxShapeObject.Create */ inline __fastcall virtual TdxShapeFakeCustomTransformation(TdxShapeObject* AParent)/* overload */ : TdxShapeObject(AParent) { }
	/* TdxShapeObject.Destroy */ inline __fastcall virtual ~TdxShapeFakeCustomTransformation() { }
	
};


class PASCALIMPLEMENTATION TdxShapeFakeRenderTransformation : public TdxShapeFakeCustomTransformation
{
	typedef TdxShapeFakeCustomTransformation inherited;
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetName();
public:
	/* TdxShapeObject.Create */ inline __fastcall virtual TdxShapeFakeRenderTransformation()/* overload */ : TdxShapeFakeCustomTransformation() { }
	/* TdxShapeObject.Create */ inline __fastcall virtual TdxShapeFakeRenderTransformation(TdxShapeObject* AParent)/* overload */ : TdxShapeFakeCustomTransformation(AParent) { }
	/* TdxShapeObject.Destroy */ inline __fastcall virtual ~TdxShapeFakeRenderTransformation() { }
	
};


class PASCALIMPLEMENTATION TdxShapeFakeRelativeTransformation : public TdxShapeFakeCustomTransformation
{
	typedef TdxShapeFakeCustomTransformation inherited;
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetName();
public:
	/* TdxShapeObject.Create */ inline __fastcall virtual TdxShapeFakeRelativeTransformation()/* overload */ : TdxShapeFakeCustomTransformation() { }
	/* TdxShapeObject.Create */ inline __fastcall virtual TdxShapeFakeRelativeTransformation(TdxShapeObject* AParent)/* overload */ : TdxShapeFakeCustomTransformation(AParent) { }
	/* TdxShapeObject.Destroy */ inline __fastcall virtual ~TdxShapeFakeRelativeTransformation() { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxShapeObjectReader : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::UnicodeString __fastcall GetShapePropertyName(const System::UnicodeString AAttributeName);
	void __fastcall ReadAttribute(TdxShapeObject* ABaseShape, System::Typinfo::PPropList APropList, int APropCount, Dxxmldoc::TdxXMLNodeAttribute* AAttribute);
	
protected:
	TdxShapeObject* __fastcall CreateShapeFromNode(TdxShapeObject* AParentShape, Dxxmldoc::TdxXMLNode* ANode);
	virtual void __fastcall ReadAttributes(TdxShapeObject* ABaseShape, Dxxmldoc::TdxXMLNode* ANode);
	virtual void __fastcall ReadChildNodes(TdxShapeObject* AParentShape, Dxxmldoc::TdxXMLNode* ANode);
	
public:
	void __fastcall ReadFromNode(TdxShapeObject* ABaseObject, Dxxmldoc::TdxXMLNode* ANode);
public:
	/* TObject.Create */ inline __fastcall TdxShapeObjectReader() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxShapeObjectReader() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TdxShapeTransformations : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::Contnrs::TObjectList* FItems;
	System::Classes::TNotifyEvent FOnChange;
	int __fastcall GetCount();
	TdxShapeCustomTransformation* __fastcall GetTransformation(int AIndex);
	void __fastcall Changed();
	
protected:
	void __fastcall AddTransformation(TdxShapeObject* ATransformation);
	
public:
	__fastcall TdxShapeTransformations();
	__fastcall virtual ~TdxShapeTransformations();
	virtual void __fastcall Assign(System::Classes::TPersistent* ASource);
	__property int Count = {read=GetCount, nodefault};
	__property TdxShapeCustomTransformation* Items[int Index] = {read=GetTransformation};
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
};


class PASCALIMPLEMENTATION TdxShapeCustomBrush : public TdxShapeObject
{
	typedef TdxShapeObject inherited;
	
private:
	Dxgdiplusclasses::TdxGPCustomBrush* FGPBrush;
	void __fastcall BrushChangeHandler(System::TObject* ASender);
	
protected:
	virtual TdxShapeBrushClass __fastcall GetBrushClass();
	
public:
	__fastcall virtual TdxShapeCustomBrush()/* overload */;
	__fastcall virtual ~TdxShapeCustomBrush();
	__property Dxgdiplusclasses::TdxGPCustomBrush* GPBrush = {read=FGPBrush};
public:
	/* TdxShapeObject.Create */ inline __fastcall virtual TdxShapeCustomBrush(TdxShapeObject* AParent)/* overload */ : TdxShapeObject(AParent) { }
	
};


class PASCALIMPLEMENTATION TdxShapeCustomTransformation : public TdxShapeObject
{
	typedef TdxShapeObject inherited;
	
protected:
	TdxShapeTransformationType FType;
	
public:
	__property TdxShapeTransformationType TransformationType = {read=FType, write=FType, nodefault};
public:
	/* TdxShapeObject.Create */ inline __fastcall virtual TdxShapeCustomTransformation()/* overload */ : TdxShapeObject() { }
	/* TdxShapeObject.Create */ inline __fastcall virtual TdxShapeCustomTransformation(TdxShapeObject* AParent)/* overload */ : TdxShapeObject(AParent) { }
	/* TdxShapeObject.Destroy */ inline __fastcall virtual ~TdxShapeCustomTransformation() { }
	
};


enum DECLSPEC_DENUM TdxShapePathPointType : unsigned char { dxpsptStart, dxpsptLine, dxpsptBezier = 3, dxpsptPathTypeMask = 7, dxpsptDashMode = 16, dxpsptPathMarker = 32, dxpsptCloseSubpath = 128 };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxShapePathDataParser : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::UnicodeString FData;
	int FDataSize;
	TdxShapePathPointType FLastPointType;
	int FPosition;
	float __fastcall GetCoordinate(System::WideChar &ACommand);
	System::UnicodeString __fastcall GetDigits();
	int __fastcall GetNextPosition();
	TdxShapePathPointType __fastcall GetPointType(System::WideChar ACommand);
	bool __fastcall IsNumberChar(System::WideChar AChar);
	
public:
	void __fastcall Parse(const System::AnsiString AData, Dxgdiplusapi::TdxGpPointFDynArray &APoints, System::DynamicArray<System::Byte> &APointTypes);
public:
	/* TObject.Create */ inline __fastcall TdxShapePathDataParser() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxShapePathDataParser() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxShapesFactory : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Classes::TStringList* FClasses;
	int __fastcall GetCount();
	
public:
	__fastcall TdxShapesFactory();
	__fastcall virtual ~TdxShapesFactory();
	TdxShapeObjectClass __fastcall GetShapeClass(int AIndex)/* overload */;
	TdxShapeObjectClass __fastcall GetShapeClass(const Dxxmldoc::TdxXMLString AName)/* overload */;
	void __fastcall RegisterShape(TdxShapeObjectClass AShapeClass);
	void __fastcall UnregisterShape(TdxShapeObjectClass AShapeClass);
	__property int Count = {read=GetCount, nodefault};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE Dxcoregraphics::TdxAlphaColor __fastcall dxColorNameToAlphaColor(const System::UnicodeString AColorName);
extern DELPHI_PACKAGE System::UnicodeString __fastcall dxPointFToStr(const Cxgeometry::TdxPointF &P);
extern DELPHI_PACKAGE Cxgeometry::TdxPointF __fastcall dxStrToPointF(const System::UnicodeString S);
extern DELPHI_PACKAGE TdxShapesFactory* __fastcall dxShapesFactory(void);
}	/* namespace Dxshapeprimitives */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSHAPEPRIMITIVES)
using namespace Dxshapeprimitives;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxshapeprimitivesHPP
