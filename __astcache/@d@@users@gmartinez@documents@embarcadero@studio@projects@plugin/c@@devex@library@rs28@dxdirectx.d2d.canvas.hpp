// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxDirectX.D2D.Canvas.pas' rev: 35.00 (Windows)

#ifndef Dxdirectx_D2d_CanvasHPP
#define Dxdirectx_D2d_CanvasHPP

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
#include <System.SysUtils.hpp>
#include <System.Generics.Collections.hpp>
#include <System.Generics.Defaults.hpp>
#include <System.Classes.hpp>
#include <Vcl.Graphics.hpp>
#include <Winapi.D2D1.hpp>
#include <Winapi.DxgiFormat.hpp>
#include <Vcl.Controls.hpp>
#include <System.Contnrs.hpp>
#include <System.Math.hpp>
#include <cxCustomCanvas.hpp>
#include <cxGeometry.hpp>
#include <cxGraphics.hpp>
#include <dxCore.hpp>
#include <dxCoreClasses.hpp>
#include <dxCoreGraphics.hpp>
#include <dxGenerics.hpp>
#include <dxGDIPlusClasses.hpp>
#include <dxGDIPlusAPI.hpp>
#include <dxShapeBrushes.hpp>
#include <dxDirectX.D2D.Types.hpp>
#include <dxDirectX.D2D.Classes.hpp>
#include <dxDirectX.D2D.Utils.hpp>
#include <dxHashUtils.hpp>

//-- user supplied -----------------------------------------------------------

namespace Dxdirectx
{
namespace D2d
{
namespace Canvas
{
//-- forward type declarations -----------------------------------------------
struct TdxDWriteTextMetrics;
class DELPHICLASS TdxDirect2DCanvasBasedFontHandle;
class DELPHICLASS TdxDirect2DCanvasBasedImage;
class DELPHICLASS TdxDirect2DCanvasBasedPath;
class DELPHICLASS TdxDirect2DCanvasBasedTextLayout;
class DELPHICLASS TdxDirect2DCanvasBasedBrushHandle;
class DELPHICLASS TdxDirect2DCanvasBasedPenHandle;
template<typename X, typename Y> class DELPHICLASS TdxDirect2DResourceCache__2;
__interface DELPHIINTERFACE IdxDirect2DCanvasOwner;
typedef System::DelphiInterface<IdxDirect2DCanvasOwner> _di_IdxDirect2DCanvasOwner;
class DELPHICLASS TdxCustomDirect2DCanvas;
class DELPHICLASS TdxDirect2DGdiCompatibleCanvas;
class DELPHICLASS TdxDirect2DHwndBasedCanvas;
//-- type declarations -------------------------------------------------------
struct DECLSPEC_DRECORD TdxDWriteTextMetrics
{
public:
	float Height;
	int LineCount;
	float LineHeight;
	bool Truncated;
	float Width;
	float WidthIncludingTrailingWhitespace;
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxDirect2DCanvasBasedFontHandle : public Cxcustomcanvas::TcxCanvasBasedFontHandle
{
	typedef Cxcustomcanvas::TcxCanvasBasedFontHandle inherited;
	
private:
	Winapi::D2d1::_di_IDWriteInlineObject FEndEllipsisSign;
	Winapi::D2d1::_di_IDWriteTextFormat FNativeHandle;
	Winapi::D2d1::_di_IDWriteInlineObject __fastcall GetEndEllipsisSign();
	
protected:
	virtual void __fastcall CreateNativeHandle(Cxcustomcanvas::TcxCustomCanvas* ACanvas);
	virtual void __fastcall FreeNativeHandle();
	
public:
	__property Winapi::D2d1::_di_IDWriteInlineObject EndEllipsisSign = {read=GetEndEllipsisSign};
	__property Winapi::D2d1::_di_IDWriteTextFormat NativeHandle = {read=FNativeHandle};
public:
	/* TcxCanvasBasedFontHandle.Create */ inline __fastcall virtual TdxDirect2DCanvasBasedFontHandle(Vcl::Graphics::TFont* const AFont, Dxcore::TdxObjectOwnership AOwnership)/* overload */ : Cxcustomcanvas::TcxCanvasBasedFontHandle(AFont, AOwnership) { }
	/* TcxCanvasBasedFontHandle.Create */ inline __fastcall TdxDirect2DCanvasBasedFontHandle(Cxcustomcanvas::TdxFontOptions* const AFont)/* overload */ : Cxcustomcanvas::TcxCanvasBasedFontHandle(AFont) { }
	
public:
	/* TcxCanvasBasedResourceHandle.Destroy */ inline __fastcall virtual ~TdxDirect2DCanvasBasedFontHandle() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxDirect2DCanvasBasedImage : public Cxcustomcanvas::TcxCanvasBasedImage
{
	typedef Cxcustomcanvas::TcxCanvasBasedImage inherited;
	
private:
	Dxdirectx::D2d::Types::_di_ID2D1Bitmap FHandle;
	
public:
	__fastcall TdxDirect2DCanvasBasedImage(TdxCustomDirect2DCanvas* ACanvas, Dxdirectx::D2d::Types::_di_ID2D1Bitmap AHandle, int AWidth, int AHeight);
	virtual void __fastcall Release();
	__property Dxdirectx::D2d::Types::_di_ID2D1Bitmap Handle = {read=FHandle};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxDirect2DCanvasBasedImage() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxDirect2DCanvasBasedPath : public Cxcustomcanvas::TcxCanvasBasedPath
{
	typedef Cxcustomcanvas::TcxCanvasBasedPath inherited;
	
private:
	bool FFigureStarted;
	Dxdirectx::D2d::Types::_di_ID2D1PathGeometry1 FHandle;
	Winapi::D2d1::_di_ID2D1GeometrySink FSink;
	void __fastcall CloseSink();
	void __fastcall FinishFigureIfNecessary(const D2D1_FIGURE_END AMode);
	void __fastcall StartFigureIfNecessary(const D2D_POINT_2F &P);
	
public:
	__fastcall TdxDirect2DCanvasBasedPath(TdxCustomDirect2DCanvas* ACanvas);
	__fastcall virtual ~TdxDirect2DCanvasBasedPath();
	Dxdirectx::D2d::Types::_di_ID2D1PathGeometry1 __fastcall BuildHandle();
	virtual void __fastcall Release();
	virtual void __fastcall AddArc(const Cxgeometry::TdxRectF &AEllipse, const float AStartAngle, const float ASweepAngle);
	virtual void __fastcall AddPolyline(Cxgeometry::PdxPointF Points, int Count)/* overload */;
	virtual void __fastcall FigureClose();
	virtual void __fastcall FigureStart();
	/* Hoisted overloads: */
	
public:
	inline void __fastcall  AddPolyline(const Cxgeometry::TdxPointF *Points, const int Points_High){ Cxcustomcanvas::TcxCanvasBasedPath::AddPolyline(Points, Points_High); }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxDirect2DCanvasBasedTextLayout : public Cxcustomcanvas::TcxCanvasBasedTextLayout
{
	typedef Cxcustomcanvas::TcxCanvasBasedTextLayout inherited;
	
private:
	static const System::Word MaxSize = System::Word(0xffff);
	
	Dxcoregraphics::TdxAlphaColor FColor;
	Winapi::D2d1::_di_IDWriteTextLayout FHandle;
	bool FHasEndEllipsis;
	float FMinWidth;
	void __fastcall CalculateTextMetrics(/* out */ TdxDWriteTextMetrics &AMetrics);
	void __fastcall HandleNeeded();
	TdxCustomDirect2DCanvas* __fastcall GetCanvas();
	TdxDirect2DCanvasBasedFontHandle* __fastcall GetFont();
	float __fastcall GetMinWidth();
	
protected:
	virtual void __fastcall ApplyFlags();
	virtual void __fastcall DoCalculate(int AMaxWidth, int AMaxHeight, int AMaxRowCount)/* overload */;
	virtual void __fastcall DoDraw(const System::Types::TRect &R);
	virtual void __fastcall DoSetFont(Cxcustomcanvas::TcxCanvasBasedFontHandle* AFontHandle);
	virtual void __fastcall FontChanged();
	virtual void __fastcall TextChanged();
	
public:
	__fastcall TdxDirect2DCanvasBasedTextLayout(TdxCustomDirect2DCanvas* ACanvas);
	virtual void __fastcall Release();
	virtual void __fastcall SetColor(Dxcoregraphics::TdxAlphaColor AColor)/* overload */;
	__property TdxCustomDirect2DCanvas* Canvas = {read=GetCanvas};
	__property TdxDirect2DCanvasBasedFontHandle* Font = {read=GetFont};
public:
	/* TcxCanvasBasedTextLayout.Destroy */ inline __fastcall virtual ~TdxDirect2DCanvasBasedTextLayout() { }
	
	/* Hoisted overloads: */
	
protected:
	inline void __fastcall  DoCalculate(){ Cxcustomcanvas::TcxCanvasBasedTextLayout::DoCalculate(); }
	
public:
	inline void __fastcall  SetColor(System::Uitypes::TColor AColor){ Cxcustomcanvas::TcxCanvasBasedTextLayout::SetColor(AColor); }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxDirect2DCanvasBasedBrushHandle : public Cxcustomcanvas::TcxCanvasBasedBrushHandle
{
	typedef Cxcustomcanvas::TcxCanvasBasedBrushHandle inherited;
	
protected:
	Dxdirectx::D2d::Classes::TdxDirect2DBrush* FBrush;
	virtual void __fastcall CreateNativeHandle(Cxcustomcanvas::TcxCustomCanvas* ACanvas);
	virtual void __fastcall FreeNativeHandle();
	
public:
	__fastcall TdxDirect2DCanvasBasedBrushHandle(Dxdirectx::D2d::Classes::TdxDirect2DBrush* AHandle)/* overload */;
	virtual bool __fastcall IsEmpty();
public:
	/* TcxCanvasBasedBrushHandle.Create */ inline __fastcall TdxDirect2DCanvasBasedBrushHandle(Dxcoregraphics::TdxAlphaColor AColor)/* overload */ : Cxcustomcanvas::TcxCanvasBasedBrushHandle(AColor) { }
	/* TcxCanvasBasedBrushHandle.Create */ inline __fastcall TdxDirect2DCanvasBasedBrushHandle(Cxcustomcanvas::TdxFillOptions* AOptions)/* overload */ : Cxcustomcanvas::TcxCanvasBasedBrushHandle(AOptions) { }
	/* TcxCanvasBasedBrushHandle.Destroy */ inline __fastcall virtual ~TdxDirect2DCanvasBasedBrushHandle() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxDirect2DCanvasBasedPenHandle : public Cxcustomcanvas::TcxCanvasBasedPenHandle
{
	typedef Cxcustomcanvas::TcxCanvasBasedPenHandle inherited;
	
private:
	TdxDirect2DCanvasBasedBrushHandle* FBrushHandle;
	Winapi::D2d1::_di_ID2D1Brush FSolidBrush;
	Winapi::D2d1::_di_ID2D1StrokeStyle FStrokeStyle;
	
protected:
	virtual void __fastcall CreateNativeHandle(Cxcustomcanvas::TcxCustomCanvas* ACanvas);
	virtual void __fastcall FreeNativeHandle();
	
public:
	__fastcall TdxDirect2DCanvasBasedPenHandle(const Winapi::D2d1::_di_ID2D1StrokeStyle AStrokeStyle, float AWidth, TdxDirect2DCanvasBasedBrushHandle* ABrushHandle)/* overload */;
	Winapi::D2d1::_di_ID2D1Brush __fastcall GetBrush(const D2D_RECT_F &R);
	virtual bool __fastcall IsEmpty();
	__property Winapi::D2d1::_di_ID2D1StrokeStyle StrokeStyle = {read=FStrokeStyle};
public:
	/* TcxCanvasBasedPenHandle.Create */ inline __fastcall TdxDirect2DCanvasBasedPenHandle(Dxcoregraphics::TdxAlphaColor AColor, float AWidth, Cxcustomcanvas::TdxStrokeStyle AStyle)/* overload */ : Cxcustomcanvas::TcxCanvasBasedPenHandle(AColor, AWidth, AStyle) { }
	/* TcxCanvasBasedPenHandle.Create */ inline __fastcall TdxDirect2DCanvasBasedPenHandle(Cxcustomcanvas::TdxStrokeOptions* AOptions)/* overload */ : Cxcustomcanvas::TcxCanvasBasedPenHandle(AOptions) { }
	
public:
	/* TcxCanvasBasedResourceHandle.Destroy */ inline __fastcall virtual ~TdxDirect2DCanvasBasedPenHandle() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename X, typename Y> class PASCALIMPLEMENTATION TdxDirect2DResourceCache__2 : public Dxcoregraphics::TdxValueCacheManager__2<X,Y>
{
	typedef Dxcoregraphics::TdxValueCacheManager__2<X,Y> inherited;
	
protected:
	TdxCustomDirect2DCanvas* FOwner;
	
public:
	__fastcall TdxDirect2DResourceCache__2(TdxCustomDirect2DCanvas* AOwner, int ACapacity);
public:
	/* {dxCoreGraphics}TdxValueCacheManager<dxDirectX_D2D_Canvas_TdxDirect2DResourceCache<X,Y>_X,dxDirectX_D2D_Canvas_TdxDirect2DResourceCache<X,Y>_Y>.Destroy */ inline __fastcall virtual ~TdxDirect2DResourceCache__2() { }
	
};

#pragma pack(pop)

__interface  INTERFACE_UUID("{08D21768-F2CA-4F1B-99D6-AE30A59216CB}") IdxDirect2DCanvasOwner  : public System::IInterface 
{
	virtual void __fastcall RecreateNeeded() = 0 ;
};

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomDirect2DCanvas : public Cxcustomcanvas::TcxCustomCanvas
{
	typedef Cxcustomcanvas::TcxCustomCanvas inherited;
	
private:
	static System::StaticArray<Dxdirectx::D2d::Types::TD2D1InterpolationMode, 2> InterpolationModeMap;
	System::Types::TRect FClipRect;
	int FClipRectModificationCount;
	Dxdirectx::D2d::Types::_di_ID2D1DeviceContext FDeviceContext;
	int FMaxBitmapSize;
	System::Types::TPoint FWindowOrg;
	D2D_MATRIX_3X2_F FWorldTransform;
	System::Generics::Collections::TStack__1<System::Types::TRect>* FSavedClipRects;
	System::Generics::Collections::TStack__1<System::Types::TPoint>* FSavedWindowOrgs;
	System::Generics::Collections::TStack__1<D2D_MATRIX_3X2_F>* FSavedWorldTransforms;
	void __fastcall ApplyWorldTransform();
	void __fastcall RollbackClipRectChanges();
	void __fastcall SetDeviceContext(const Dxdirectx::D2d::Types::_di_ID2D1DeviceContext Value);
	
protected:
	TdxDirect2DResourceCache__2<Cxcustomcanvas::TcxCanvasBasedResourceCacheKey,Dxdirectx::D2d::Types::_di_ID2D1Bitmap>* FCacheNativeObjects;
	TdxDirect2DResourceCache__2<Dxcoregraphics::TdxAlphaColor,Winapi::D2d1::_di_ID2D1SolidColorBrush>* FCacheSolidBrushes;
	bool FIsGDICompatible;
	Cxcustomcanvas::TcxCanvasBasedSharedBrushes* FSharedBrushes;
	Cxcustomcanvas::TcxCanvasBasedSharedImageLists* FSharedImageLists;
	Cxcustomcanvas::TcxCanvasBasedSharedPens* FSharedPens;
	bool FRecreateContextNeeded;
	void __fastcall DoBeginDraw(const System::Types::TRect &AClipRect);
	void __fastcall DoEndDraw();
	virtual Cxcustomcanvas::TcxCanvasBasedSharedBrushes* __fastcall GetSharedBrushes();
	virtual Cxcustomcanvas::TcxCanvasBasedSharedFonts* __fastcall GetSharedFonts();
	virtual Cxcustomcanvas::TcxCanvasBasedSharedImageLists* __fastcall GetSharedImageLists();
	virtual Cxcustomcanvas::TcxCanvasBasedSharedPens* __fastcall GetSharedPens();
	virtual System::Types::TPoint __fastcall GetWindowOrg();
	virtual void __fastcall SetWindowOrg(const System::Types::TPoint &AValue);
	Winapi::D2d1::_di_ID2D1StrokeStyle __fastcall CacheGetPenStyle(const Cxcustomcanvas::TdxStrokeStyle AStyle)/* overload */;
	Winapi::D2d1::_di_ID2D1StrokeStyle __fastcall CacheGetPenStyle(const Vcl::Graphics::TPenStyle AStyle)/* overload */;
	Winapi::D2d1::_di_ID2D1SolidColorBrush __fastcall CacheGetSolidBrush(const Dxcoregraphics::TdxAlphaColor AColor);
	TdxDirect2DCanvasBasedBrushHandle* __fastcall CreateBrushHandle(Dxgdiplusclasses::TdxGPCustomBrush* const ABrush);
	TdxDirect2DCanvasBasedPenHandle* __fastcall CreatePenHandle(Dxgdiplusclasses::TdxGPPen* const APen);
	Dxdirectx::D2d::Types::_di_ID2D1PathGeometry1 __fastcall CreatePathGeometry(System::Types::PPoint APoints, int ACount, D2D1_FIGURE_BEGIN AFigureBegin, D2D1_FIGURE_END AFigureEnd)/* overload */;
	Dxdirectx::D2d::Types::_di_ID2D1PathGeometry1 __fastcall CreatePathGeometry(Cxgeometry::PdxPointF APoints, int ACount, D2D1_FIGURE_BEGIN AFigureBegin, D2D1_FIGURE_END AFigureEnd)/* overload */;
	Dxdirectx::D2d::Types::_di_ID2D1Bitmap __fastcall CreateNativeObjectTexture(const System::Types::TRect &ARect, const System::Types::TRect &AClippedRect, Cxcustomcanvas::_di_TcxCanvasNativeDrawExProc AProc)/* overload */;
	Dxdirectx::D2d::Types::_di_ID2D1Bitmap __fastcall CreateNativeObjectTexture(const System::Types::TRect &ARect, const System::Types::TRect &AClippedRect, Cxcustomcanvas::_di_TcxCanvasNativeDrawProc AProc)/* overload */;
	Dxdirectx::D2d::Types::_di_ID2D1StrokeStyle1 __fastcall CreateNativeStrokeStyle(Dxgdiplusclasses::TdxGPPen* APen);
	bool __fastcall GetGdiInteropRenderTarget(/* out */ Winapi::D2d1::_di_ID2D1GdiInteropRenderTarget &ATarget, /* out */ HDC &DC);
	bool __fastcall GetNativeBrushAndPen(Cxcustomcanvas::TcxCanvasBasedBrush* ABrush, Cxcustomcanvas::TcxCanvasBasedPen* APen, /* out */ Dxdirectx::D2d::Classes::TdxDirect2DBrush* &ANativeBrush, /* out */ TdxDirect2DCanvasBasedPenHandle* &ANativePen);
	bool __fastcall GetNativeImage(Cxcustomcanvas::TcxCanvasBasedImage* AImageResource, /* out */ Dxdirectx::D2d::Types::_di_ID2D1Bitmap &AHandle);
	bool __fastcall IsLargeForTexture(const System::Types::TRect &R);
	virtual void __fastcall DrawImageCore(Cxcustomcanvas::TcxCanvasBasedImage* AImage, const Cxgeometry::TdxRectF &ATargetRect, const Cxgeometry::TdxRectF &ASourceRect, System::Byte AAlpha)/* overload */;
	virtual void __fastcall DrawImageCore(Cxcustomcanvas::TcxCanvasBasedImage* AImage, const System::Types::TRect &ATargetRect, const System::Types::TRect &ASourceRect, System::Byte AAlpha)/* overload */;
	virtual void __fastcall FillRectByGradientCore(const System::Types::TRect &R, Dxcoregraphics::TdxAlphaColor AColor1, Dxcoregraphics::TdxAlphaColor AColor2, Dxgdiplusapi::LinearGradientMode AMode);
	virtual void __fastcall RectangleCore(const Cxgeometry::TdxRectF &R, Cxcustomcanvas::TcxCanvasBasedBrushHandle* ABrushHandle, Cxcustomcanvas::TcxCanvasBasedPenHandle* APenHandle);
	virtual void __fastcall ReleaseDevice();
	__property Dxdirectx::D2d::Types::_di_ID2D1DeviceContext DeviceContext = {read=FDeviceContext, write=SetDeviceContext};
	
public:
	__fastcall TdxCustomDirect2DCanvas();
	__fastcall virtual ~TdxCustomDirect2DCanvas();
	void __fastcall FlushCache();
	virtual void __fastcall DrawNativeObject(const System::Types::TRect &R, const Cxcustomcanvas::TcxCanvasBasedResourceCacheKey &ACacheKey, Cxcustomcanvas::_di_TcxCanvasNativeDrawProc AProc)/* overload */;
	virtual void __fastcall DrawNativeObject(const System::Types::TRect &R, const Cxcustomcanvas::TcxCanvasBasedResourceCacheKey &ACacheKey, Cxcustomcanvas::_di_TcxCanvasNativeDrawExProc AProc)/* overload */;
	virtual Cxcustomcanvas::TcxCanvasBasedBrush* __fastcall CreateBrush(Dxgdiplusclasses::TdxGPCustomBrush* ABrush, Dxcore::TdxObjectOwnership AOwnership = (Dxcore::TdxObjectOwnership)(0x2))/* overload */;
	virtual Cxcustomcanvas::TcxCanvasBasedImage* __fastcall CreateImage(Vcl::Graphics::TBitmap* ABitmap, Vcl::Graphics::TAlphaFormat AAlphaFormat = (Vcl::Graphics::TAlphaFormat)(0x0))/* overload */;
	virtual Cxcustomcanvas::TcxCanvasBasedImage* __fastcall CreateImage(Dxcoregraphics::TdxCustomFastDIB* ABitmap, Vcl::Graphics::TAlphaFormat AAlphaFormat = (Vcl::Graphics::TAlphaFormat)(0x0))/* overload */;
	virtual Cxcustomcanvas::TcxCanvasBasedPath* __fastcall CreatePath();
	virtual Cxcustomcanvas::TcxCanvasBasedPen* __fastcall CreatePeN(Dxgdiplusclasses::TdxGPPen* APen, Dxcore::TdxObjectOwnership AOwnership = (Dxcore::TdxObjectOwnership)(0x2))/* overload */;
	virtual Cxcustomcanvas::TcxCanvasBasedTextLayout* __fastcall CreateTextLayout();
	virtual void __fastcall Arc(const System::Types::TRect &AEllipse, const System::Types::TPoint &AStartPoint, const System::Types::TPoint &AEndPoint, Dxcoregraphics::TdxAlphaColor AColor, int APenWidth, Vcl::Graphics::TPenStyle APenStyle)/* overload */;
	virtual void __fastcall DonutSlice(const Cxgeometry::TdxRectF &R, float AStartAngle, float ASweepAngle, float AWholePercent, Cxcustomcanvas::TcxCanvasBasedBrush* ABrush, Cxcustomcanvas::TcxCanvasBasedPen* APen);
	virtual void __fastcall Ellipse(const Cxgeometry::TdxRectF &R, Cxcustomcanvas::TcxCanvasBasedBrush* ABrush, Cxcustomcanvas::TcxCanvasBasedPen* APen)/* overload */;
	virtual void __fastcall Ellipse(const System::Types::TRect &R, Dxcoregraphics::TdxAlphaColor ABrushColor, Dxcoregraphics::TdxAlphaColor APenColor, Vcl::Graphics::TPenStyle APenStyle, int APenWidth)/* overload */;
	virtual void __fastcall FillRect(const System::Types::TRect &R, Dxcoregraphics::TdxAlphaColor AColor)/* overload */;
	virtual void __fastcall Path(Cxcustomcanvas::TcxCanvasBasedPath* APath, Cxcustomcanvas::TcxCanvasBasedBrush* ABrush, Cxcustomcanvas::TcxCanvasBasedPen* APen);
	virtual void __fastcall Pie(const Cxgeometry::TdxRectF &R, float AStartAngle, float ASweepAngle, Cxcustomcanvas::TcxCanvasBasedBrush* ABrush, Cxcustomcanvas::TcxCanvasBasedPen* APen);
	virtual void __fastcall Line(const System::Types::TPoint &P1, const System::Types::TPoint &P2, Dxcoregraphics::TdxAlphaColor AColor, int APenWidth, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0))/* overload */;
	virtual void __fastcall Line(const System::Types::TPoint &P1, const System::Types::TPoint &P2, System::Uitypes::TColor AColor, int APenWidth = 0x1, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0))/* overload */;
	virtual void __fastcall Line(const Cxgeometry::TdxPointF &P1, const Cxgeometry::TdxPointF &P2, Cxcustomcanvas::TcxCanvasBasedPen* APen)/* overload */;
	virtual void __fastcall Polyline(const System::Types::TPoint *P, const int P_High, Dxcoregraphics::TdxAlphaColor AColor, int APenWidth = 0x1, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0))/* overload */;
	virtual void __fastcall Polyline(const Cxgeometry::PdxPointF P, int ACount, Cxcustomcanvas::TcxCanvasBasedPen* APen)/* overload */;
	virtual void __fastcall Polygon(const System::Types::TPoint *P, const int P_High, Dxcoregraphics::TdxAlphaColor ABrushColor, Dxcoregraphics::TdxAlphaColor APenColor)/* overload */;
	virtual void __fastcall Polygon(const Cxgeometry::PdxPointF P, int ACount, Cxcustomcanvas::TcxCanvasBasedBrush* ABrush, Cxcustomcanvas::TcxCanvasBasedPen* APen)/* overload */;
	virtual void __fastcall Rectangle(const System::Types::TRect &R, Dxcoregraphics::TdxAlphaColor ABrushColor, Dxcoregraphics::TdxAlphaColor APenColor, Vcl::Graphics::TPenStyle APenStyle, int APenWidth = 0x1)/* overload */;
	HIDESBASE void __fastcall DrawBitmap(const Dxdirectx::D2d::Types::_di_ID2D1Bitmap AHandle, const Cxgeometry::TdxRectF &ATargetRect, const Cxgeometry::TdxRectF &ASourceRect, System::Byte AAlpha)/* overload */;
	HIDESBASE void __fastcall DrawBitmap(const Dxdirectx::D2d::Types::_di_ID2D1Bitmap AHandle, const System::Types::TRect &ATargetRect, const System::Types::TRect &ASourceRect, System::Byte AAlpha)/* overload */;
	HIDESBASE void __fastcall DrawBitmap(const Dxdirectx::D2d::Types::_di_ID2D1Bitmap AHandle, const System::Types::TRect &ATargetRect)/* overload */;
	void __fastcall DrawTextLayout(const Winapi::D2d1::_di_IDWriteTextLayout AHandle, int X, int Y, Dxcoregraphics::TdxAlphaColor AColor);
	void __fastcall Geometry(const Winapi::D2d1::_di_ID2D1Geometry AHandle, Dxcoregraphics::TdxAlphaColor ABrushColor, Dxcoregraphics::TdxAlphaColor APenColor, float APenWidth = 1.000000E+00f, Winapi::D2d1::_di_ID2D1StrokeStyle APenStyle = Winapi::D2d1::_di_ID2D1StrokeStyle())/* overload */;
	void __fastcall Geometry(const Winapi::D2d1::_di_ID2D1Geometry AHandle, Dxdirectx::D2d::Classes::TdxDirect2DBrush* ANativeBrush, TdxDirect2DCanvasBasedPenHandle* ANativePen)/* overload */;
	void __fastcall Geometry(const Winapi::D2d1::_di_ID2D1Geometry AHandle, const D2D_RECT_F &ABoundingRect, Dxdirectx::D2d::Classes::TdxDirect2DBrush* ANativeBrush, TdxDirect2DCanvasBasedPenHandle* ANativePen)/* overload */;
	void __fastcall ApplyClipRect();
	virtual void __fastcall IntersectClipRect(const System::Types::TRect &ARect)/* overload */;
	virtual bool __fastcall RectVisible(const System::Types::TRect &R)/* overload */;
	virtual void __fastcall RestoreClipRegion();
	virtual void __fastcall SaveClipRegion();
	virtual void __fastcall ModifyWorldTransform(const tagXFORM &AForm);
	virtual void __fastcall RestoreWorldTransform();
	virtual void __fastcall SaveWorldTransform();
	virtual void __fastcall RestoreState();
	virtual void __fastcall SaveState();
	/* Hoisted overloads: */
	
public:
	inline Cxcustomcanvas::TcxCanvasBasedBrush* __fastcall  CreateBrush(Dxcoregraphics::TdxAlphaColor AColor){ return Cxcustomcanvas::TcxCustomCanvas::CreateBrush(AColor); }
	inline Cxcustomcanvas::TcxCanvasBasedBrush* __fastcall  CreateBrush(Cxcustomcanvas::TdxFillOptions* AFillOptions){ return Cxcustomcanvas::TcxCustomCanvas::CreateBrush(AFillOptions); }
	inline Cxcustomcanvas::TcxCanvasBasedImage* __fastcall  CreateImage(Vcl::Graphics::TGraphic* AGraphic){ return Cxcustomcanvas::TcxCustomCanvas::CreateImage(AGraphic); }
	inline Cxcustomcanvas::TcxCanvasBasedImage* __fastcall  CreateImage(Dxgdiplusclasses::TdxGPImage* AImage, Dxcore::TdxObjectOwnership AOwnership = (Dxcore::TdxObjectOwnership)(0x2)){ return Cxcustomcanvas::TcxCustomCanvas::CreateImage(AImage, AOwnership); }
	inline Cxcustomcanvas::TcxCanvasBasedPen* __fastcall  CreatePeN(Dxcoregraphics::TdxAlphaColor AColor, float AWidth, Cxcustomcanvas::TdxStrokeStyle AStyle){ return Cxcustomcanvas::TcxCustomCanvas::CreatePeN(AColor, AWidth, AStyle); }
	inline Cxcustomcanvas::TcxCanvasBasedPen* __fastcall  CreatePeN(Cxcustomcanvas::TdxStrokeOptions* AStrokeOptions){ return Cxcustomcanvas::TcxCustomCanvas::CreatePeN(AStrokeOptions); }
	inline void __fastcall  Arc(const System::Types::TRect &AEllipse, const System::Types::TPoint &AStartPoint, const System::Types::TPoint &AEndPoint, System::Uitypes::TColor AColor, int APenWidth = 0x1, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0)){ Cxcustomcanvas::TcxCustomCanvas::Arc(AEllipse, AStartPoint, AEndPoint, AColor, APenWidth, APenStyle); }
	inline void __fastcall  Ellipse(const System::Types::TRect &R, System::Uitypes::TColor ABrushColor, System::Uitypes::TColor APenColor, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0), int APenWidth = 0x1){ Cxcustomcanvas::TcxCustomCanvas::Ellipse(R, ABrushColor, APenColor, APenStyle, APenWidth); }
	inline void __fastcall  FillRect(const System::Types::TRect &R, System::Uitypes::TColor AColor){ Cxcustomcanvas::TcxCustomCanvas::FillRect(R, AColor); }
	inline void __fastcall  FillRect(const System::Types::TRect &R, System::Uitypes::TColor AColor, System::Byte AAlpha){ Cxcustomcanvas::TcxCustomCanvas::FillRect(R, AColor, AAlpha); }
	inline void __fastcall  FillRect(const System::Types::TRect &R, Cxcustomcanvas::TcxCanvasBasedImage* AImage){ Cxcustomcanvas::TcxCustomCanvas::FillRect(R, AImage); }
	inline void __fastcall  FillRect(const System::Types::TRect &R, Dxgdiplusclasses::TdxGPImage* AImage, Cxcustomcanvas::PcxCanvasBasedImage ACache = (Cxcustomcanvas::PcxCanvasBasedImage)(0x0)){ Cxcustomcanvas::TcxCustomCanvas::FillRect(R, AImage, ACache); }
	inline void __fastcall  FillRect(const Cxgeometry::TdxRectF &R, Dxcoregraphics::TdxAlphaColor AColor){ Cxcustomcanvas::TcxCustomCanvas::FillRect(R, AColor); }
	inline void __fastcall  FillRect(const Cxgeometry::TdxRectF &R, Cxcustomcanvas::TcxCanvasBasedBrush* ABrush){ Cxcustomcanvas::TcxCustomCanvas::FillRect(R, ABrush); }
	inline void __fastcall  Polyline(const System::Types::TPoint *P, const int P_High, System::Uitypes::TColor AColor, int APenWidth = 0x1, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0)){ Cxcustomcanvas::TcxCustomCanvas::Polyline(P, P_High, AColor, APenWidth, APenStyle); }
	inline void __fastcall  Polyline(const Cxgeometry::TdxPointF *P, const int P_High, Cxcustomcanvas::TcxCanvasBasedPen* APen){ Cxcustomcanvas::TcxCustomCanvas::Polyline(P, P_High, APen); }
	inline void __fastcall  Polygon(const System::Types::TPoint *P, const int P_High, System::Uitypes::TColor ABrushColor, System::Uitypes::TColor APenColor){ Cxcustomcanvas::TcxCustomCanvas::Polygon(P, P_High, ABrushColor, APenColor); }
	inline void __fastcall  Polygon(const Cxgeometry::TdxPointF *P, const int P_High, Cxcustomcanvas::TcxCanvasBasedBrush* ABrush, Cxcustomcanvas::TcxCanvasBasedPen* APen){ Cxcustomcanvas::TcxCustomCanvas::Polygon(P, P_High, ABrush, APen); }
	inline void __fastcall  Rectangle(const System::Types::TRect &R, System::Uitypes::TColor ABrushColor, System::Uitypes::TColor APenColor, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0), int APenWidth = 0x1){ Cxcustomcanvas::TcxCustomCanvas::Rectangle(R, ABrushColor, APenColor, APenStyle, APenWidth); }
	inline void __fastcall  Rectangle(const Cxgeometry::TdxRectF &R, Cxcustomcanvas::TcxCanvasBasedBrush* ABrush, Cxcustomcanvas::TcxCanvasBasedPen* APen){ Cxcustomcanvas::TcxCustomCanvas::Rectangle(R, ABrush, APen); }
	inline void __fastcall  DrawBitmap(Vcl::Graphics::TBitmap* ABitmap, const System::Types::TRect &ATargetRect, Cxcustomcanvas::PcxCanvasBasedImage ACache = (Cxcustomcanvas::PcxCanvasBasedImage)(0x0)){ Cxcustomcanvas::TcxCustomCanvas::DrawBitmap(ABitmap, ATargetRect, ACache); }
	inline void __fastcall  DrawBitmap(Vcl::Graphics::TBitmap* ABitmap, const System::Types::TRect &ATargetRect, Vcl::Graphics::TAlphaFormat AAlphaFormat, Cxcustomcanvas::PcxCanvasBasedImage ACache = (Cxcustomcanvas::PcxCanvasBasedImage)(0x0)){ Cxcustomcanvas::TcxCustomCanvas::DrawBitmap(ABitmap, ATargetRect, AAlphaFormat, ACache); }
	inline void __fastcall  DrawBitmap(Vcl::Graphics::TBitmap* ABitmap, const System::Types::TRect &ATargetRect, const System::Types::TRect &ASourceRect, Cxcustomcanvas::PcxCanvasBasedImage ACache = (Cxcustomcanvas::PcxCanvasBasedImage)(0x0)){ Cxcustomcanvas::TcxCustomCanvas::DrawBitmap(ABitmap, ATargetRect, ASourceRect, ACache); }
	inline void __fastcall  DrawBitmap(Vcl::Graphics::TBitmap* ABitmap, const System::Types::TRect &ATargetRect, const System::Types::TRect &ASourceRect, Vcl::Graphics::TAlphaFormat AAlphaFormat, Cxcustomcanvas::PcxCanvasBasedImage ACache = (Cxcustomcanvas::PcxCanvasBasedImage)(0x0)){ Cxcustomcanvas::TcxCustomCanvas::DrawBitmap(ABitmap, ATargetRect, ASourceRect, AAlphaFormat, ACache); }
	inline void __fastcall  DrawBitmap(Dxcoregraphics::TdxFastDIB* ABitmap, const System::Types::TRect &ATargetRect, Vcl::Graphics::TAlphaFormat AAlphaFormat, Cxcustomcanvas::PcxCanvasBasedImage ACache = (Cxcustomcanvas::PcxCanvasBasedImage)(0x0)){ Cxcustomcanvas::TcxCustomCanvas::DrawBitmap(ABitmap, ATargetRect, AAlphaFormat, ACache); }
	inline void __fastcall  DrawBitmap(Dxcoregraphics::TdxFastDIB* ABitmap, const Cxgeometry::TdxRectF &ATargetRect, Vcl::Graphics::TAlphaFormat AAlphaFormat, Cxcustomcanvas::PcxCanvasBasedImage ACache = (Cxcustomcanvas::PcxCanvasBasedImage)(0x0)){ Cxcustomcanvas::TcxCustomCanvas::DrawBitmap(ABitmap, ATargetRect, AAlphaFormat, ACache); }
	inline void __fastcall  DrawBitmap(Dxcoregraphics::TdxFastDIB* ABitmap, const System::Types::TRect &ATargetRect, const System::Types::TRect &ASourceRect, Vcl::Graphics::TAlphaFormat AAlphaFormat, Cxcustomcanvas::PcxCanvasBasedImage ACache = (Cxcustomcanvas::PcxCanvasBasedImage)(0x0)){ Cxcustomcanvas::TcxCustomCanvas::DrawBitmap(ABitmap, ATargetRect, ASourceRect, AAlphaFormat, ACache); }
	inline void __fastcall  DrawBitmap(Dxcoregraphics::TdxFastDIB* ABitmap, const Cxgeometry::TdxRectF &ATargetRect, const Cxgeometry::TdxRectF &ASourceRect, Vcl::Graphics::TAlphaFormat AAlphaFormat, Cxcustomcanvas::PcxCanvasBasedImage ACache = (Cxcustomcanvas::PcxCanvasBasedImage)(0x0)){ Cxcustomcanvas::TcxCustomCanvas::DrawBitmap(ABitmap, ATargetRect, ASourceRect, AAlphaFormat, ACache); }
	inline void __fastcall  DrawBitmap(Dxgdiplusclasses::TdxGpFastDIB* ABitmap, const Cxgeometry::TdxRectF &ATargetRect, Vcl::Graphics::TAlphaFormat AAlphaFormat, Cxcustomcanvas::PcxCanvasBasedImage ACache = (Cxcustomcanvas::PcxCanvasBasedImage)(0x0)){ Cxcustomcanvas::TcxCustomCanvas::DrawBitmap(ABitmap, ATargetRect, AAlphaFormat, ACache); }
	inline void __fastcall  DrawBitmap(Dxgdiplusclasses::TdxGpFastDIB* ABitmap, const System::Types::TRect &ATargetRect, Vcl::Graphics::TAlphaFormat AAlphaFormat, Cxcustomcanvas::PcxCanvasBasedImage ACache = (Cxcustomcanvas::PcxCanvasBasedImage)(0x0)){ Cxcustomcanvas::TcxCustomCanvas::DrawBitmap(ABitmap, ATargetRect, AAlphaFormat, ACache); }
	inline void __fastcall  DrawBitmap(Dxgdiplusclasses::TdxGpFastDIB* ABitmap, const System::Types::TRect &ATargetRect, const System::Types::TRect &ASourceRect, Vcl::Graphics::TAlphaFormat AAlphaFormat, Cxcustomcanvas::PcxCanvasBasedImage ACache = (Cxcustomcanvas::PcxCanvasBasedImage)(0x0)){ Cxcustomcanvas::TcxCustomCanvas::DrawBitmap(ABitmap, ATargetRect, ASourceRect, AAlphaFormat, ACache); }
	inline void __fastcall  DrawBitmap(Dxgdiplusclasses::TdxGpFastDIB* ABitmap, const Cxgeometry::TdxRectF &ATargetRect, const Cxgeometry::TdxRectF &ASourceRect, Vcl::Graphics::TAlphaFormat AAlphaFormat, Cxcustomcanvas::PcxCanvasBasedImage ACache = (Cxcustomcanvas::PcxCanvasBasedImage)(0x0)){ Cxcustomcanvas::TcxCustomCanvas::DrawBitmap(ABitmap, ATargetRect, ASourceRect, AAlphaFormat, ACache); }
	inline void __fastcall  IntersectClipRect(const Cxgeometry::TdxRectF &ARect){ Cxcustomcanvas::TcxCustomCanvas::IntersectClipRect(ARect); }
	inline bool __fastcall  RectVisible(const Cxgeometry::TdxRectF &R){ return Cxcustomcanvas::TcxCustomCanvas::RectVisible(R); }
	
private:
	void *__IcxCanvasCacheControl;	// Cxcustomcanvas::IcxCanvasCacheControl 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {A1DEDC74-DBA2-4EAC-BC91-5016E48F4E7B}
	operator Cxcustomcanvas::_di_IcxCanvasCacheControl()
	{
		Cxcustomcanvas::_di_IcxCanvasCacheControl intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcustomcanvas::IcxCanvasCacheControl*(void) { return (Cxcustomcanvas::IcxCanvasCacheControl*)&__IcxCanvasCacheControl; }
	#endif
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxDirect2DGdiCompatibleCanvas : public TdxCustomDirect2DCanvas
{
	typedef TdxCustomDirect2DCanvas inherited;
	
private:
	Winapi::D2d1::_di_ID2D1DCRenderTarget FRenderTarget;
	void __fastcall CreateRenderTarget();
	
public:
	__fastcall TdxDirect2DGdiCompatibleCanvas();
	void __fastcall BeginPaint(HDC DC, const System::Types::TRect &R);
	void __fastcall EndPaint();
public:
	/* TdxCustomDirect2DCanvas.Destroy */ inline __fastcall virtual ~TdxDirect2DGdiCompatibleCanvas() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxDirect2DHwndBasedCanvas : public TdxCustomDirect2DCanvas
{
	typedef TdxCustomDirect2DCanvas inherited;
	
private:
	Dxdirectx::D2d::Types::_di_IDXGIDevice1 FDevice;
	Dxdirectx::D2d::Types::_di_ID3D11Device FDevice3D;
	Dxdirectx::D2d::Types::_di_ID3D11DeviceContext FDevice3DContext;
	Dxdirectx::D2d::Types::_di_ID3D11Texture2D FFrontBufferContent;
	System::Types::TSize FFrontBufferContentSize;
	Dxdirectx::D2d::Types::_di_IDXGISurface FFrontBufferSurface;
	bool FIsBufferValid;
	_di_IdxDirect2DCanvasOwner FOwner;
	tagPAINTSTRUCT FPaintStruct;
	Dxdirectx::D2d::Types::TDXGIPresentParameters FPresentParameters;
	Dxdirectx::D2d::Types::_di_IDXGISwapChain1 FSwapChain;
	System::Types::TSize FTextureSize;
	System::Types::TRect FUpdateRect;
	Vcl::Controls::TWinControl* FWinControl;
	HWND FWindowHandle;
	void __fastcall CheckCreateFrontBufferContent();
	void __fastcall DoPresentBuffer();
	
protected:
	virtual bool __fastcall GetDefaultUseRightToLeftAlignment();
	void __fastcall CreateTexture();
	virtual void __fastcall ReleaseDevice();
	void __fastcall ReleaseTexture();
	bool __fastcall IsBufferValid();
	void __fastcall MarkBufferInvalid();
	void __fastcall BeginPaint();
	void __fastcall EndPaint();
	void __fastcall CopyToDC(HDC DC)/* overload */;
	void __fastcall CopyToDC(HDC DC, const System::Types::TRect &ATargetRect, const System::Types::TRect &ASourceRect)/* overload */;
	void __fastcall SetWndHandle(HWND AHandle);
	__property Dxdirectx::D2d::Types::_di_IDXGIDevice1 Device = {read=FDevice};
	__property Dxdirectx::D2d::Types::_di_ID3D11Device Device3D = {read=FDevice3D};
	__property Dxdirectx::D2d::Types::_di_ID3D11DeviceContext Device3DContext = {read=FDevice3DContext};
	
public:
	__fastcall TdxDirect2DHwndBasedCanvas(const _di_IdxDirect2DCanvasOwner AOwner, const Dxdirectx::D2d::Types::_di_IDXGIDevice1 ADevice, const Dxdirectx::D2d::Types::_di_ID2D1DeviceContext AContext, const Dxdirectx::D2d::Types::_di_ID3D11Device ADevice3D, const Dxdirectx::D2d::Types::_di_ID3D11DeviceContext ADevice3DContext);
public:
	/* TdxCustomDirect2DCanvas.Destroy */ inline __fastcall virtual ~TdxDirect2DHwndBasedCanvas() { }
	
private:
	void *__IcxControlDirectCanvas;	// Cxcustomcanvas::IcxControlDirectCanvas 
	void *__IcxCanvasBuffer;	// Cxcustomcanvas::IcxCanvasBuffer 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {E40B5E3C-CD3C-4D2C-81DA-2A41800CA183}
	operator Cxcustomcanvas::_di_IcxControlCanvas()
	{
		Cxcustomcanvas::_di_IcxControlCanvas intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcustomcanvas::IcxControlCanvas*(void) { return (Cxcustomcanvas::IcxControlCanvas*)&__IcxControlDirectCanvas; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {0920AC2D-5CED-4DF4-ABCB-4D12248AC63D}
	operator Cxcustomcanvas::_di_IcxControlDirectCanvas()
	{
		Cxcustomcanvas::_di_IcxControlDirectCanvas intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcustomcanvas::IcxControlDirectCanvas*(void) { return (Cxcustomcanvas::IcxControlDirectCanvas*)&__IcxControlDirectCanvas; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {C5B683CB-EC4A-41AA-AE0D-DBF0EE320C9C}
	operator Cxcustomcanvas::_di_IcxCanvasBuffer()
	{
		Cxcustomcanvas::_di_IcxCanvasBuffer intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcustomcanvas::IcxCanvasBuffer*(void) { return (Cxcustomcanvas::IcxCanvasBuffer*)&__IcxCanvasBuffer; }
	#endif
	
};

#pragma pack(pop)

typedef System::Int8 TdxDirectXSwapChainSize;

//-- var, const, procedure ---------------------------------------------------
#define sdxErrorCannotCreateTextLayoutHandle L"Cannot create TextLayout handle because %s is not set."
extern DELPHI_PACKAGE bool dxDirectXAntialiasing;
extern DELPHI_PACKAGE TdxDirectXSwapChainSize dxDirectXSwapChainSize;
extern DELPHI_PACKAGE D2D1_TEXT_ANTIALIAS_MODE dxDirectXTextAntialiasMode;
extern DELPHI_PACKAGE bool dxDirectXVSync;
extern DELPHI_PACKAGE bool __fastcall dxCreateDirect2DCanvas(const _di_IdxDirect2DCanvasOwner AOwner, /* out */ Cxcustomcanvas::TcxCustomCanvas* &ACanvas);
}	/* namespace Canvas */
}	/* namespace D2d */
}	/* namespace Dxdirectx */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXDIRECTX_D2D_CANVAS)
using namespace Dxdirectx::D2d::Canvas;
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
#endif	// Dxdirectx_D2d_CanvasHPP
