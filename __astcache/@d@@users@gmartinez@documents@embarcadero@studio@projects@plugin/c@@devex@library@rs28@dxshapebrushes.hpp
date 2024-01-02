// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxShapeBrushes.pas' rev: 35.00 (Windows)

#ifndef DxshapebrushesHPP
#define DxshapebrushesHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.Windows.hpp>
#include <System.SysUtils.hpp>
#include <dxCoreGraphics.hpp>
#include <cxGeometry.hpp>
#include <dxGDIPlusAPI.hpp>
#include <dxGDIPlusClasses.hpp>
#include <dxShapePrimitives.hpp>
#include <System.Classes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Dxshapebrushes
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TdxGPSolidBrush;
class DELPHICLASS TdxGPTextureBrush;
class DELPHICLASS TdxGpCustomGradientBrush;
class DELPHICLASS TdxGPLinearGradientBrush;
class DELPHICLASS TdxGPPathGradientBrush;
class DELPHICLASS TdxLinearGradientBrush;
class DELPHICLASS TdxRadialGradientBrush;
class DELPHICLASS TdxShapeCustomGradientBrush;
class DELPHICLASS TdxShapeLinearGradientBrush;
class DELPHICLASS TdxShapeRadialGradientBrush;
class DELPHICLASS TdxShapeSolidBrush;
class DELPHICLASS TdxShapeBrushGradientStop;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TdxGPSolidBrush : public Dxgdiplusclasses::TdxGPCustomBrush
{
	typedef Dxgdiplusclasses::TdxGPCustomBrush inherited;
	
private:
	Dxcoregraphics::TdxAlphaColor FColor;
	void __fastcall SetColor(const Dxcoregraphics::TdxAlphaColor AValue);
	
protected:
	virtual void __fastcall DoCreateHandle(/* out */ void * &AHandle);
	virtual bool __fastcall GetIsEmpty();
	
public:
	__fastcall TdxGPSolidBrush(Dxcoregraphics::TdxAlphaColor AColor)/* overload */;
	virtual void __fastcall Assign(Dxgdiplusclasses::TdxGPCustomGraphicObject* ASource);
	__property Dxcoregraphics::TdxAlphaColor Color = {read=FColor, write=SetColor, nodefault};
public:
	/* TdxGPCustomGraphicObject.Create */ inline __fastcall virtual TdxGPSolidBrush()/* overload */ : Dxgdiplusclasses::TdxGPCustomBrush() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxGPSolidBrush() { }
	
};


class PASCALIMPLEMENTATION TdxGPTextureBrush : public Dxgdiplusclasses::TdxGPCustomBrush
{
	typedef Dxgdiplusclasses::TdxGPCustomBrush inherited;
	
private:
	Dxgdiplusclasses::TdxGPImage* FTexture;
	void __fastcall SetTexture(Dxgdiplusclasses::TdxGPImage* const AValue);
	void __fastcall ChangeHandler(System::TObject* Sender);
	
protected:
	virtual void __fastcall DoCreateHandle(/* out */ void * &AHandle);
	virtual void __fastcall DoTargetRectChanged();
	virtual bool __fastcall GetIsEmpty();
	virtual bool __fastcall NeedRecreateHandleOnTargetRectChange();
	
public:
	__fastcall virtual TdxGPTextureBrush()/* overload */;
	__fastcall TdxGPTextureBrush(Dxgdiplusclasses::TdxGPImage* ATexture)/* overload */;
	__fastcall virtual ~TdxGPTextureBrush();
	virtual void __fastcall Assign(Dxgdiplusclasses::TdxGPCustomGraphicObject* ASource);
	__property Dxgdiplusclasses::TdxGPImage* Texture = {read=FTexture, write=SetTexture};
};


class PASCALIMPLEMENTATION TdxGpCustomGradientBrush : public Dxgdiplusclasses::TdxGPCustomBrush
{
	typedef Dxgdiplusclasses::TdxGPCustomBrush inherited;
	
private:
	void __fastcall SetGradientPoints(Dxgdiplusclasses::TdxGPBrushGradientPoints* const AValue);
	void __fastcall SetTransformMatrix(Dxgdiplusclasses::TdxGPMatrix* const AValue);
	
protected:
	Dxgdiplusclasses::TdxGPBrushGradientPoints* FGradientPoints;
	Dxgdiplusclasses::TdxGPMatrix* FTransformMatrix;
	virtual void __fastcall DoCreateHandle(/* out */ void * &AHandle);
	virtual bool __fastcall NeedRecreateHandleOnTargetRectChange();
	virtual bool __fastcall GetIsEmpty();
	virtual void * __fastcall InternalCreateHandle(Winapi::Windows::PSingle AOffsets, Dxcoregraphics::PdxAlphaColor AColors, int ACount) = 0 ;
	virtual void __fastcall PrepareGradientPoints(Dxgdiplusclasses::TdxGPBrushGradientPoints* APoints);
	void * __fastcall PrepareGradientPointsAndCreateHandle(Dxgdiplusclasses::TdxGPBrushGradientPoints* APoints);
	
public:
	__fastcall virtual TdxGpCustomGradientBrush()/* overload */;
	__fastcall virtual ~TdxGpCustomGradientBrush();
	virtual void __fastcall Assign(Dxgdiplusclasses::TdxGPCustomGraphicObject* ASource);
	__property Dxgdiplusclasses::TdxGPBrushGradientPoints* GradientPoints = {read=FGradientPoints, write=SetGradientPoints};
	__property Dxgdiplusclasses::TdxGPMatrix* TransformMatrix = {read=FTransformMatrix, write=SetTransformMatrix};
};


enum DECLSPEC_DENUM TdxGPLinearGradientBrushMode : unsigned char { gplgbmHorizontal, gplgbmVertical, gplgbmForwardDiagonal, gplgbmBackwardDiagonal, gplgbmLine };

class PASCALIMPLEMENTATION TdxGPLinearGradientBrush : public TdxGpCustomGradientBrush
{
	typedef TdxGpCustomGradientBrush inherited;
	
private:
	TdxGPLinearGradientBrushMode FGradientMode;
	Cxgeometry::TdxPointF FEndPoint;
	Cxgeometry::TdxPointF FStartPoint;
	void __fastcall SetEndPoint(const Cxgeometry::TdxPointF &AValue);
	void __fastcall SetGradientMode(const TdxGPLinearGradientBrushMode AValue);
	void __fastcall SetStartPoint(const Cxgeometry::TdxPointF &AValue);
	void __fastcall CalculateTransformation(void * AHandle);
	void __fastcall CalculateTransformMatrix(float M11, float M12, float M21, float M22, float DX, float DY);
	void __fastcall GetBrushTransformElements(void * AHandle, /* out */ float &M11, /* out */ float &M12, /* out */ float &M21, /* out */ float &M22, /* out */ float &DX, /* out */ float &DY);
	
protected:
	virtual void * __fastcall InternalCreateHandle(Winapi::Windows::PSingle AOffsets, Dxcoregraphics::PdxAlphaColor AColors, int ACount);
	
public:
	__fastcall virtual TdxGPLinearGradientBrush()/* overload */;
	virtual void __fastcall Assign(Dxgdiplusclasses::TdxGPCustomGraphicObject* ASource);
	__property TdxGPLinearGradientBrushMode GradientMode = {read=FGradientMode, write=SetGradientMode, nodefault};
	__property Cxgeometry::TdxPointF StartPoint = {read=FStartPoint, write=SetStartPoint};
	__property Cxgeometry::TdxPointF EndPoint = {read=FEndPoint, write=SetEndPoint};
public:
	/* TdxGpCustomGradientBrush.Destroy */ inline __fastcall virtual ~TdxGPLinearGradientBrush() { }
	
};


class PASCALIMPLEMENTATION TdxGPPathGradientBrush : public TdxGpCustomGradientBrush
{
	typedef TdxGpCustomGradientBrush inherited;
	
protected:
	virtual void * __fastcall InternalCreateHandle(Winapi::Windows::PSingle AOffsets, Dxcoregraphics::PdxAlphaColor AColors, int ACount);
	virtual void __fastcall DoCreateHandle(/* out */ void * &AHandle);
	virtual void __fastcall DoPathContent(Dxgdiplusclasses::TdxGPPath* APath);
	virtual void __fastcall PrepareGradientPoints(Dxgdiplusclasses::TdxGPBrushGradientPoints* APoints);
	virtual Cxgeometry::TdxRectF __fastcall GetBounds();
public:
	/* TdxGpCustomGradientBrush.Create */ inline __fastcall virtual TdxGPPathGradientBrush()/* overload */ : TdxGpCustomGradientBrush() { }
	/* TdxGpCustomGradientBrush.Destroy */ inline __fastcall virtual ~TdxGPPathGradientBrush() { }
	
};


class PASCALIMPLEMENTATION TdxLinearGradientBrush : public TdxGPLinearGradientBrush
{
	typedef TdxGPLinearGradientBrush inherited;
	
public:
	/* TdxGPLinearGradientBrush.Create */ inline __fastcall virtual TdxLinearGradientBrush()/* overload */ : TdxGPLinearGradientBrush() { }
	
public:
	/* TdxGpCustomGradientBrush.Destroy */ inline __fastcall virtual ~TdxLinearGradientBrush() { }
	
};


class PASCALIMPLEMENTATION TdxRadialGradientBrush : public TdxGPPathGradientBrush
{
	typedef TdxGPPathGradientBrush inherited;
	
private:
	Cxgeometry::TdxPointF FCenter;
	Cxgeometry::TdxPointF FRadius;
	void __fastcall SetCenter(const Cxgeometry::TdxPointF &AValue);
	void __fastcall SetRadius(const Cxgeometry::TdxPointF &AValue);
	
protected:
	virtual Cxgeometry::TdxRectF __fastcall GetBounds();
	virtual void __fastcall DoPathContent(Dxgdiplusclasses::TdxGPPath* APath);
	
public:
	__fastcall virtual TdxRadialGradientBrush()/* overload */;
	virtual void __fastcall Assign(Dxgdiplusclasses::TdxGPCustomGraphicObject* ASource);
	__property Cxgeometry::TdxPointF Center = {read=FCenter, write=SetCenter};
	__property Cxgeometry::TdxPointF Radius = {read=FRadius, write=SetRadius};
public:
	/* TdxGpCustomGradientBrush.Destroy */ inline __fastcall virtual ~TdxRadialGradientBrush() { }
	
};


class PASCALIMPLEMENTATION TdxShapeCustomGradientBrush : public Dxshapeprimitives::TdxShapeCustomBrush
{
	typedef Dxshapeprimitives::TdxShapeCustomBrush inherited;
	
private:
	Dxgdiplusclasses::TdxGPBrushGradientPoints* __fastcall GetGradientPoints();
	
protected:
	virtual Dxshapeprimitives::TdxShapeBrushClass __fastcall GetBrushClass();
	
public:
	__property Dxgdiplusclasses::TdxGPBrushGradientPoints* GradientPoints = {read=GetGradientPoints};
public:
	/* TdxShapeCustomBrush.Create */ inline __fastcall virtual TdxShapeCustomGradientBrush()/* overload */ : Dxshapeprimitives::TdxShapeCustomBrush() { }
	/* TdxShapeCustomBrush.Destroy */ inline __fastcall virtual ~TdxShapeCustomGradientBrush() { }
	
public:
	/* TdxShapeObject.Create */ inline __fastcall virtual TdxShapeCustomGradientBrush(Dxshapeprimitives::TdxShapeObject* AParent)/* overload */ : Dxshapeprimitives::TdxShapeCustomBrush(AParent) { }
	
};


class PASCALIMPLEMENTATION TdxShapeLinearGradientBrush : public TdxShapeCustomGradientBrush
{
	typedef TdxShapeCustomGradientBrush inherited;
	
private:
	TdxLinearGradientBrush* __fastcall GetBrush();
	System::UnicodeString __fastcall GetEndPoint();
	System::UnicodeString __fastcall GetStartPoint();
	void __fastcall SetEndPoint(const System::UnicodeString AValue);
	void __fastcall SetStartPoint(const System::UnicodeString AValue);
	
protected:
	virtual Dxshapeprimitives::TdxShapeBrushClass __fastcall GetBrushClass();
	
public:
	__fastcall virtual TdxShapeLinearGradientBrush()/* overload */;
	__classmethod virtual System::UnicodeString __fastcall GetName();
	
__published:
	__property System::UnicodeString StartPoint = {read=GetStartPoint, write=SetStartPoint};
	__property System::UnicodeString EndPoint = {read=GetEndPoint, write=SetEndPoint};
public:
	/* TdxShapeCustomBrush.Destroy */ inline __fastcall virtual ~TdxShapeLinearGradientBrush() { }
	
public:
	/* TdxShapeObject.Create */ inline __fastcall virtual TdxShapeLinearGradientBrush(Dxshapeprimitives::TdxShapeObject* AParent)/* overload */ : TdxShapeCustomGradientBrush(AParent) { }
	
};


class PASCALIMPLEMENTATION TdxShapeRadialGradientBrush : public TdxShapeCustomGradientBrush
{
	typedef TdxShapeCustomGradientBrush inherited;
	
private:
	TdxRadialGradientBrush* __fastcall GetBrush();
	System::UnicodeString __fastcall GetCenter();
	float __fastcall GetRadiusX();
	float __fastcall GetRadiusY();
	void __fastcall SetCenter(const System::UnicodeString AValue);
	void __fastcall SetRadiusX(const float AValue);
	void __fastcall SetRadiusY(const float AValue);
	
protected:
	virtual Dxshapeprimitives::TdxShapeBrushClass __fastcall GetBrushClass();
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetName();
	
__published:
	__property System::UnicodeString Center = {read=GetCenter, write=SetCenter};
	__property float RadiusX = {read=GetRadiusX, write=SetRadiusX};
	__property float RadiusY = {read=GetRadiusY, write=SetRadiusY};
public:
	/* TdxShapeCustomBrush.Create */ inline __fastcall virtual TdxShapeRadialGradientBrush()/* overload */ : TdxShapeCustomGradientBrush() { }
	/* TdxShapeCustomBrush.Destroy */ inline __fastcall virtual ~TdxShapeRadialGradientBrush() { }
	
public:
	/* TdxShapeObject.Create */ inline __fastcall virtual TdxShapeRadialGradientBrush(Dxshapeprimitives::TdxShapeObject* AParent)/* overload */ : TdxShapeCustomGradientBrush(AParent) { }
	
};


class PASCALIMPLEMENTATION TdxShapeSolidBrush : public Dxshapeprimitives::TdxShapeCustomBrush
{
	typedef Dxshapeprimitives::TdxShapeCustomBrush inherited;
	
private:
	TdxGPSolidBrush* __fastcall GetBrush();
	Dxcoregraphics::TdxAlphaColor __fastcall GetColor();
	void __fastcall SetColor(const Dxcoregraphics::TdxAlphaColor AValue);
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetName();
	
__published:
	__property Dxcoregraphics::TdxAlphaColor Color = {read=GetColor, write=SetColor, nodefault};
public:
	/* TdxShapeCustomBrush.Create */ inline __fastcall virtual TdxShapeSolidBrush()/* overload */ : Dxshapeprimitives::TdxShapeCustomBrush() { }
	/* TdxShapeCustomBrush.Destroy */ inline __fastcall virtual ~TdxShapeSolidBrush() { }
	
public:
	/* TdxShapeObject.Create */ inline __fastcall virtual TdxShapeSolidBrush(Dxshapeprimitives::TdxShapeObject* AParent)/* overload */ : Dxshapeprimitives::TdxShapeCustomBrush(AParent) { }
	
};


class PASCALIMPLEMENTATION TdxShapeBrushGradientStop : public Dxshapeprimitives::TdxShapeObject
{
	typedef Dxshapeprimitives::TdxShapeObject inherited;
	
private:
	System::UnicodeString FColor;
	float FOffset;
	
public:
	__classmethod virtual Dxshapeprimitives::TdxShapeObjectReaderClass __fastcall GetReaderClass();
	__classmethod virtual System::UnicodeString __fastcall GetName();
	
__published:
	__property System::UnicodeString Color = {read=FColor, write=FColor};
	__property float Offset = {read=FOffset, write=FOffset};
public:
	/* TdxShapeObject.Create */ inline __fastcall virtual TdxShapeBrushGradientStop()/* overload */ : Dxshapeprimitives::TdxShapeObject() { }
	/* TdxShapeObject.Create */ inline __fastcall virtual TdxShapeBrushGradientStop(Dxshapeprimitives::TdxShapeObject* AParent)/* overload */ : Dxshapeprimitives::TdxShapeObject(AParent) { }
	/* TdxShapeObject.Destroy */ inline __fastcall virtual ~TdxShapeBrushGradientStop() { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE System::StaticArray<Dxgdiplusapi::LinearGradientMode, 5> dxGpLinearGradientBrushModeToLinearGradientMode;
}	/* namespace Dxshapebrushes */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSHAPEBRUSHES)
using namespace Dxshapebrushes;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxshapebrushesHPP
