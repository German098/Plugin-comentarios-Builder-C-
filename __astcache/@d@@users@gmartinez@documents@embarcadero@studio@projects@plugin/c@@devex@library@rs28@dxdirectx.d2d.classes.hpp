// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxDirectX.D2D.Classes.pas' rev: 35.00 (Windows)

#ifndef Dxdirectx_D2d_ClassesHPP
#define Dxdirectx_D2d_ClassesHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.UITypes.hpp>
#include <System.Types.hpp>
#include <Winapi.Windows.hpp>
#include <System.Classes.hpp>
#include <System.Math.hpp>
#include <Vcl.Graphics.hpp>
#include <Winapi.D2D1.hpp>
#include <dxCore.hpp>
#include <dxCoreGraphics.hpp>
#include <dxGenerics.hpp>
#include <cxGeometry.hpp>
#include <dxGDIPlusAPI.hpp>
#include <dxGDIPlusClasses.hpp>
#include <dxDirectX.D2D.Types.hpp>
#include <cxCustomCanvas.hpp>
#include <dxCoreClasses.hpp>
#include <System.Generics.Collections.hpp>
#include <System.SysUtils.hpp>
#include <System.Generics.Defaults.hpp>

//-- user supplied -----------------------------------------------------------

namespace Dxdirectx
{
namespace D2d
{
namespace Classes
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TdxDirect2DBrush;
class DELPHICLASS TdxDirect2DSolidBrush;
class DELPHICLASS TdxDirect2DHatchBrush;
class DELPHICLASS TdxDirect2DCustomTexturedBrush;
class DELPHICLASS TdxDirect2DComplexNativeBrush;
class DELPHICLASS TdxDirect2DCustomGradientBrush;
class DELPHICLASS TdxDirect2DLineGradientBrush;
class DELPHICLASS TdxDirect2DLinearGradientBrush;
class DELPHICLASS TdxDirect2DRadialGradientBrush;
class DELPHICLASS TdxDirect2DTexturedBrush;
class DELPHICLASS TdxDirect2DBrushFactory;
class DELPHICLASS TdxDirect2DPenStyleCache;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxDirect2DBrush : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Dxdirectx::D2d::Types::_di_ID2D1DeviceContext FContext;
	
protected:
	Winapi::D2d1::_di_ID2D1Brush FHandle;
	
public:
	__fastcall TdxDirect2DBrush(const Dxdirectx::D2d::Types::_di_ID2D1DeviceContext AContext);
	virtual Winapi::D2d1::_di_ID2D1Brush __fastcall GetHandle(const D2D_RECT_F &R);
	virtual bool __fastcall IsEmpty();
	__property Dxdirectx::D2d::Types::_di_ID2D1DeviceContext Context = {read=FContext};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxDirect2DBrush() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxDirect2DSolidBrush : public TdxDirect2DBrush
{
	typedef TdxDirect2DBrush inherited;
	
public:
	__fastcall TdxDirect2DSolidBrush(const Dxdirectx::D2d::Types::_di_ID2D1DeviceContext AContext, const Dxcoregraphics::TdxAlphaColor AColor);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxDirect2DSolidBrush() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxDirect2DHatchBrush : public TdxDirect2DBrush
{
	typedef TdxDirect2DBrush inherited;
	
public:
	__fastcall TdxDirect2DHatchBrush(const Dxdirectx::D2d::Types::_di_ID2D1DeviceContext AContext, const Dxdirectx::D2d::Types::_di_ID2D1Bitmap ATexture);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxDirect2DHatchBrush() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxDirect2DCustomTexturedBrush : public TdxDirect2DBrush
{
	typedef TdxDirect2DBrush inherited;
	
private:
	Cxgeometry::TdxPointF FOrigin;
	Dxgdiplusclasses::TdxGPMatrix* FOriginalTransform;
	
protected:
	virtual void __fastcall ApplyTransformation(const Winapi::D2d1::_di_ID2D1Brush ABrush, const Cxgeometry::TdxPointF &AOrigin);
	
public:
	__fastcall TdxDirect2DCustomTexturedBrush(const Dxdirectx::D2d::Types::_di_ID2D1DeviceContext AContext, Dxgdiplusclasses::TdxGPMatrix* ATransform);
	__fastcall virtual ~TdxDirect2DCustomTexturedBrush();
	virtual Winapi::D2d1::_di_ID2D1Brush __fastcall GetHandle(const D2D_RECT_F &R);
	__property Dxgdiplusclasses::TdxGPMatrix* OriginalTransform = {read=FOriginalTransform};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxDirect2DComplexNativeBrush : public TdxDirect2DCustomTexturedBrush
{
	typedef TdxDirect2DCustomTexturedBrush inherited;
	
private:
	Dxgdiplusclasses::TdxGPCustomBrush* FBrush;
	D2D_SIZE_F FSize;
	Dxdirectx::D2d::Types::_di_ID2D1BitmapBrush1 __fastcall CreateHandle(const D2D_SIZE_F &S);
	
public:
	__fastcall TdxDirect2DComplexNativeBrush(const Dxdirectx::D2d::Types::_di_ID2D1DeviceContext AContext, Dxgdiplusclasses::TdxGPCustomBrush* ABrush);
	__fastcall virtual ~TdxDirect2DComplexNativeBrush();
	__classmethod Dxdirectx::D2d::Types::_di_ID2D1Bitmap __fastcall CreateBrushBitmap(const Dxdirectx::D2d::Types::_di_ID2D1DeviceContext AContext, Dxgdiplusclasses::TdxGPCustomBrush* ABrush, int AWidth, int AHeight);
	virtual Winapi::D2d1::_di_ID2D1Brush __fastcall GetHandle(const D2D_RECT_F &R);
	virtual bool __fastcall IsEmpty();
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxDirect2DCustomGradientBrush : public TdxDirect2DBrush
{
	typedef TdxDirect2DBrush inherited;
	
private:
	Winapi::D2d1::_di_ID2D1GradientStopCollection FStopCollection;
	D2D_RECT_F FTargetRect;
	
protected:
	virtual Winapi::D2d1::_di_ID2D1Brush __fastcall CreateHandle(const D2D_RECT_F &R, const Winapi::D2d1::_di_ID2D1GradientStopCollection AStops) = 0 ;
	void __fastcall SetGradientStops(Dxdirectx::D2d::Types::TD2D1GradientStops AStops);
	
public:
	virtual Winapi::D2d1::_di_ID2D1Brush __fastcall GetHandle(const D2D_RECT_F &R) _FINAL_ATTRIBUTE;
	virtual bool __fastcall IsEmpty();
public:
	/* TdxDirect2DBrush.Create */ inline __fastcall TdxDirect2DCustomGradientBrush(const Dxdirectx::D2d::Types::_di_ID2D1DeviceContext AContext) : TdxDirect2DBrush(AContext) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxDirect2DCustomGradientBrush() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxDirect2DLineGradientBrush : public TdxDirect2DCustomGradientBrush
{
	typedef TdxDirect2DCustomGradientBrush inherited;
	
private:
	Cxgeometry::TdxPointF FEndPoint;
	Cxgeometry::TdxPointF FStartPoint;
	
protected:
	virtual Winapi::D2d1::_di_ID2D1Brush __fastcall CreateHandle(const D2D_RECT_F &R, const Winapi::D2d1::_di_ID2D1GradientStopCollection AStops);
	
public:
	__fastcall TdxDirect2DLineGradientBrush(const Dxdirectx::D2d::Types::_di_ID2D1DeviceContext AContext, Dxdirectx::D2d::Types::TD2D1GradientStops AStops, const Cxgeometry::TdxPointF &AStartPoint, const Cxgeometry::TdxPointF &AEndPoint);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxDirect2DLineGradientBrush() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxDirect2DLinearGradientBrush : public TdxDirect2DCustomGradientBrush
{
	typedef TdxDirect2DCustomGradientBrush inherited;
	
private:
	Dxgdiplusapi::LinearGradientMode FMode;
	
protected:
	virtual Winapi::D2d1::_di_ID2D1Brush __fastcall CreateHandle(const D2D_RECT_F &R, const Winapi::D2d1::_di_ID2D1GradientStopCollection AStops);
	
public:
	__fastcall TdxDirect2DLinearGradientBrush(const Dxdirectx::D2d::Types::_di_ID2D1DeviceContext AContext, Dxdirectx::D2d::Types::TD2D1GradientStops AStops, Dxgdiplusapi::LinearGradientMode AMode);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxDirect2DLinearGradientBrush() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxDirect2DRadialGradientBrush : public TdxDirect2DCustomGradientBrush
{
	typedef TdxDirect2DCustomGradientBrush inherited;
	
private:
	Cxgeometry::TdxPointF FCenter;
	Cxgeometry::TdxPointF FRadius;
	
protected:
	virtual Winapi::D2d1::_di_ID2D1Brush __fastcall CreateHandle(const D2D_RECT_F &R, const Winapi::D2d1::_di_ID2D1GradientStopCollection AStops);
	
public:
	__fastcall TdxDirect2DRadialGradientBrush(const Dxdirectx::D2d::Types::_di_ID2D1DeviceContext AContext, Dxdirectx::D2d::Types::TD2D1GradientStops AStops, const Cxgeometry::TdxPointF &ACenter, const Cxgeometry::TdxPointF &ARadius);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxDirect2DRadialGradientBrush() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxDirect2DTexturedBrush : public TdxDirect2DCustomTexturedBrush
{
	typedef TdxDirect2DCustomTexturedBrush inherited;
	
public:
	__fastcall TdxDirect2DTexturedBrush(const Dxdirectx::D2d::Types::_di_ID2D1DeviceContext AContext, const Dxdirectx::D2d::Types::_di_ID2D1Bitmap ATexture, Dxgdiplusclasses::TdxGPMatrix* ATextureTransform);
public:
	/* TdxDirect2DCustomTexturedBrush.Destroy */ inline __fastcall virtual ~TdxDirect2DTexturedBrush() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxDirect2DBrushFactory : public System::TObject
{
	typedef System::TObject inherited;
	
	
private:
	typedef TdxDirect2DBrush* __fastcall (*TCreateBrushFunc)(const Dxdirectx::D2d::Types::_di_ID2D1DeviceContext AContext, Dxgdiplusclasses::TdxGPCustomBrush* ABrush);
	
	
private:
	static Dxgenerics::TdxClassDictionary__1<TCreateBrushFunc>* FFactory;
	static TdxDirect2DBrush* __fastcall CreateBrush(const Dxdirectx::D2d::Types::_di_ID2D1DeviceContext AContext, Dxgdiplusclasses::TdxGPCustomBrush* ABrush);
	static TdxDirect2DBrush* __fastcall CreateComplexBrush(const Dxdirectx::D2d::Types::_di_ID2D1DeviceContext AContext, Dxgdiplusclasses::TdxGPCustomBrush* ABrush);
	static TdxDirect2DBrush* __fastcall CreateHatchBrush(const Dxdirectx::D2d::Types::_di_ID2D1DeviceContext AContext, Dxgdiplusclasses::TdxGPCustomBrush* ABrush);
	static TdxDirect2DBrush* __fastcall CreateLinearGradientBrush(const Dxdirectx::D2d::Types::_di_ID2D1DeviceContext AContext, Dxgdiplusclasses::TdxGPCustomBrush* ABrush);
	static TdxDirect2DBrush* __fastcall CreateLinearGradientBrushCore(const Dxdirectx::D2d::Types::_di_ID2D1DeviceContext AContext, Dxgdiplusclasses::TdxGPBrushGradientPoints* APoints, Dxgdiplusapi::LinearGradientMode AMode)/* overload */;
	static TdxDirect2DBrush* __fastcall CreateLinearGradientBrushCore(const Dxdirectx::D2d::Types::_di_ID2D1DeviceContext AContext, Dxgdiplusclasses::TdxGPBrushGradientPoints* APoints, const Cxgeometry::TdxPointF &AStartPoint, const Cxgeometry::TdxPointF &AFinishPoint)/* overload */;
	static TdxDirect2DBrush* __fastcall CreateRadialBrush(const Dxdirectx::D2d::Types::_di_ID2D1DeviceContext AContext, Dxgdiplusclasses::TdxGPCustomBrush* ABrush);
	static TdxDirect2DBrush* __fastcall CreateSolidBrush(const Dxdirectx::D2d::Types::_di_ID2D1DeviceContext AContext, Dxgdiplusclasses::TdxGPCustomBrush* ABrush);
	static TdxDirect2DBrush* __fastcall CreateSolidBrushCore(const Dxdirectx::D2d::Types::_di_ID2D1DeviceContext AContext, Dxcoregraphics::TdxAlphaColor AColor);
	static TdxDirect2DBrush* __fastcall CreateTextureBrush(const Dxdirectx::D2d::Types::_di_ID2D1DeviceContext AContext, Dxgdiplusclasses::TdxGPCustomBrush* ABrush);
	static TdxDirect2DBrush* __fastcall CreateTextureBrushCore(const Dxdirectx::D2d::Types::_di_ID2D1DeviceContext AContext, Dxgdiplusclasses::TdxGPImage* ATexture, Dxgdiplusclasses::TdxGPMatrix* ATextureTransform = (Dxgdiplusclasses::TdxGPMatrix*)(0x0));
	
protected:
	__classmethod void __fastcall CheckCreated();
	__classmethod void __fastcall Finalize();
	
public:
	__classmethod TdxDirect2DBrush* __fastcall Create(const Dxdirectx::D2d::Types::_di_ID2D1DeviceContext AContext, Dxgdiplusclasses::TdxGPCustomBrush* ABrush);
public:
	/* TObject.Create */ inline __fastcall TdxDirect2DBrushFactory() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxDirect2DBrushFactory() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxDirect2DPenStyleCache : public System::TObject
{
	typedef System::TObject inherited;
	
	
private:
	typedef System::StaticArray<Dxdirectx::D2d::Types::_di_ID2D1StrokeStyle1, 5> _TdxDirect2DPenStyleCache__1;
	
	
private:
	static _TdxDirect2DPenStyleCache__1 FCache;
	
public:
	__classmethod Dxdirectx::D2d::Types::_di_ID2D1StrokeStyle1 __fastcall Get(Cxcustomcanvas::TdxStrokeStyle AStyle);
	
private:
	// __classmethod void __fastcall Create@();
	// __classmethod void __fastcall Destroy@();
public:
	/* TObject.Create */ inline __fastcall TdxDirect2DPenStyleCache() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxDirect2DPenStyleCache() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Classes */
}	/* namespace D2d */
}	/* namespace Dxdirectx */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXDIRECTX_D2D_CLASSES)
using namespace Dxdirectx::D2d::Classes;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXDIRECTX_D2D)
using namespace Dxdirectx::D2d;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXDIRECTX)
using namespace Dxdirectx;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Dxdirectx_D2d_ClassesHPP
