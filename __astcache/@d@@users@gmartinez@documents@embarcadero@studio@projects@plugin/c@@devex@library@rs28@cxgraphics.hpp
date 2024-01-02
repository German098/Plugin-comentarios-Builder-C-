// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxGraphics.pas' rev: 35.00 (Windows)

#ifndef CxgraphicsHPP
#define CxgraphicsHPP

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
#include <System.SysUtils.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Menus.hpp>
#include <Winapi.CommCtrl.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ImgList.hpp>
#include <Winapi.ActiveX.hpp>
#include <System.Generics.Defaults.hpp>
#include <System.Generics.Collections.hpp>
#include <dxCore.hpp>
#include <dxCoreClasses.hpp>
#include <dxCoreGraphics.hpp>
#include <dxMessages.hpp>
#include <cxClasses.hpp>
#include <cxGeometry.hpp>
#include <dxGDIPlusClasses.hpp>
#include <dxGDIPlusAPI.hpp>
#include <dxSmartImage.hpp>
#include <cxImageList.hpp>
#include <cxCustomCanvas.hpp>
#include <dxGenerics.hpp>
#include <dxDPIAwareUtils.hpp>
#include <System.ImageList.hpp>

//-- user supplied -----------------------------------------------------------

namespace Cxgraphics
{
//-- forward type declarations -----------------------------------------------
__interface DELPHIINTERFACE IcxFontListener;
typedef System::DelphiInterface<IcxFontListener> _di_IcxFontListener;
__interface DELPHIINTERFACE IdxMultiPartGlyphSupport;
typedef System::DelphiInterface<IdxMultiPartGlyphSupport> _di_IdxMultiPartGlyphSupport;
struct TcxViewParams;
__interface DELPHIINTERFACE IcxPaintControlsHelper;
typedef System::DelphiInterface<IcxPaintControlsHelper> _di_IcxPaintControlsHelper;
__interface DELPHIINTERFACE IcxImageCollectionListener;
typedef System::DelphiInterface<IcxImageCollectionListener> _di_IcxImageCollectionListener;
struct TdxHSV;
struct TdxHSL;
class DELPHICLASS TcxRegion;
class DELPHICLASS TcxCanvas;
class DELPHICLASS TcxMeasureCanvas;
class DELPHICLASS TcxScreenCanvas;
struct TcxPaintCanvasState;
class DELPHICLASS TcxPaintCanvas;
class DELPHICLASS TcxBitmap;
struct TcxColorTransitionMap;
struct TcxHatchData;
class DELPHICLASS TcxBitmap32;
class DELPHICLASS TcxColorList;
class DELPHICLASS TcxAlphaBitmap;
class DELPHICLASS TcxImageList;
class DELPHICLASS TcxImageCollectionItem;
class DELPHICLASS TcxImageCollectionItems;
class DELPHICLASS TcxImageCollection;
class DELPHICLASS TcxSystemImageList;
class DELPHICLASS TdxSolidBrushCacheManager;
class DELPHICLASS TdxSolidBrushCache;
class DELPHICLASS TdxColorUtils;
class DELPHICLASS TdxColorPaletteBuilder;
class DELPHICLASS TdxAdjustFontSizeCustomHelper;
class DELPHICLASS TdxAdjustFontSizeHelper;
class DELPHICLASS TdxImageAnimationController;
struct TdxDrawImageCacheID;
class DELPHICLASS TdxImageListPaintCache;
struct TcxColorInfo;
//-- type declarations -------------------------------------------------------
using Cxgeometry::TcxBorder;

using Cxgeometry::TcxBorders;

using Dxcoregraphics::TcxModifyStringType;

using Cxcustomcanvas::TcxImageDrawMode;

using Cxcustomcanvas::TcxRotationAngle;

__interface  INTERFACE_UUID("{B144DD7E-0B27-439A-B908-FC3ACFE6A2D3}") IcxFontListener  : public System::IInterface 
{
	virtual void __fastcall Changed(System::TObject* Sender, Vcl::Graphics::TFont* AFont) = 0 ;
};

__interface  INTERFACE_UUID("{9F33E339-DEDD-422A-9908-5B44FDADEBD9}") IdxMultiPartGlyphSupport  : public System::IInterface 
{
	virtual System::UnicodeString __fastcall GetStateCaption(int AIndex) = 0 ;
	virtual int __fastcall GetGlyphCount() = 0 ;
	virtual void __fastcall SetGlyphCount(int AValue) = 0 ;
	__property int GlyphCount = {read=GetGlyphCount, write=SetGlyphCount};
};

enum DECLSPEC_DENUM TcxArrowDirection : unsigned char { adUp, adDown, adLeft, adRight };

typedef System::Set<TcxArrowDirection, TcxArrowDirection::adUp, TcxArrowDirection::adRight> TcxArrowDirections;

typedef System::StaticArray<System::Types::TPoint, 3> TcxArrowPoints;

typedef HBRUSH TBrushHandle;

typedef System::Int8 TcxColorPart;

enum DECLSPEC_DENUM TcxGridLines : unsigned char { glBoth, glNone, glVertical, glHorizontal };

typedef TcxViewParams *PcxViewParams;

struct DECLSPEC_DRECORD TcxViewParams
{
public:
	Vcl::Graphics::TBitmap* Bitmap;
	System::Uitypes::TColor Color;
	Vcl::Graphics::TFont* Font;
	System::Uitypes::TColor TextColor;
};


__interface  INTERFACE_UUID("{7EFAF634-E8D2-489D-9603-FCFC03ACA460}") IcxPaintControlsHelper  : public System::IInterface 
{
	virtual bool __fastcall AllowDrawEdgesAndBorders() = 0 ;
};

__interface  INTERFACE_UUID("{FDFF372B-F49E-40C9-9E03-E0D6B110774A}") IcxImageCollectionListener  : public System::IInterface 
{
	virtual void __fastcall ImageCollectionChanged() = 0 ;
	virtual void __fastcall ImageCollectionDestroyed() = 0 ;
};

struct DECLSPEC_DRECORD TdxHSV
{
public:
	double H;
	double S;
	double V;
};


struct DECLSPEC_DRECORD TdxHSL
{
public:
	double H;
	double S;
	double L;
};


typedef System::Uitypes::TImageIndex TcxImageIndex;

typedef HRGN TcxRegionHandle;

enum DECLSPEC_DENUM TcxRegionOperation : unsigned char { roSet, roAdd, roSubtract, roIntersect };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxRegion : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	HRGN FHandle;
	System::Types::TRect __fastcall GetBoundsRect();
	bool __fastcall GetIsEmpty();
	
protected:
	void __fastcall DestroyHandle();
	
public:
	__fastcall TcxRegion(HRGN AHandle)/* overload */;
	__fastcall TcxRegion(const System::Types::TRect &ABounds)/* overload */;
	__fastcall TcxRegion()/* overload */;
	__fastcall TcxRegion(int ALeft, int ATop, int ARight, int ABottom)/* overload */;
	__fastcall TcxRegion(HWND AHandle, int ADummy)/* overload */;
	__fastcall TcxRegion(int ALeft, int ATop, int ARight, int ABottom, int AWidthEllipse, int AHeightEllipse)/* overload */;
	__fastcall TcxRegion(const System::Types::TRect &ABounds, int AWidthEllipse, int AHeightEllipse)/* overload */;
	__fastcall virtual ~TcxRegion();
	TcxRegion* __fastcall Clone();
	void __fastcall Combine(TcxRegion* ARegion, TcxRegionOperation AOperation, bool ADestroyRegion = true)/* overload */;
	void __fastcall Combine(HRGN ARegionHandle, TcxRegionOperation AOperation)/* overload */;
	void __fastcall Combine(const System::Types::TRect &R, TcxRegionOperation AOperation)/* overload */;
	bool __fastcall IsEqual(TcxRegion* ARegion)/* overload */;
	bool __fastcall IsEqual(HRGN ARegionHandle)/* overload */;
	void __fastcall Offset(const System::Types::TPoint &P)/* overload */;
	void __fastcall Offset(int DX, int DY)/* overload */;
	bool __fastcall PtInRegion(const System::Types::TPoint &Pt)/* overload */;
	bool __fastcall PtInRegion(int X, int Y)/* overload */;
	bool __fastcall RectInRegion(const System::Types::TRect &R)/* overload */;
	bool __fastcall RectInRegion(int ALeft, int ATop, int ARight, int ABottom)/* overload */;
	__property System::Types::TRect BoundsRect = {read=GetBoundsRect};
	__property HRGN Handle = {read=FHandle, write=FHandle, nodefault};
	__property bool IsEmpty = {read=GetIsEmpty, nodefault};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCanvas : public Cxcustomcanvas::TcxGdiBasedCanvas
{
	typedef Cxcustomcanvas::TcxGdiBasedCanvas inherited;
	
	
private:
	#pragma pack(push,8)
	struct DECLSPEC_DRECORD TcxCanvasState
	{
	public:
		Vcl::Graphics::TFont* Font;
		Vcl::Graphics::TBrush* Brush;
		Vcl::Graphics::TPen* Pen;
		Dxcore::TdxDefaultBoolean UseRightToLeftAlignment;
		int TextFlags;
	};
	#pragma pack(pop)
	
	
	typedef System::DynamicArray<TcxCanvasState> TcxCanvasStates;
	
	#pragma pack(push,8)
	struct DECLSPEC_DRECORD TcxDCState
	{
	public:
		NativeUInt Handle;
		int State;
	};
	#pragma pack(pop)
	
	
	typedef System::DynamicArray<TcxDCState> TcxDCStates;
	
	
private:
	TcxDCStates FSavedDCs;
	System::Classes::TList* FSavedRegions;
	TcxCanvasStates FSavedStates;
	Vcl::Graphics::TBrush* __fastcall GetBrush();
	int __fastcall GetCopyMode();
	Vcl::Graphics::TFont* __fastcall GetFont();
	int __fastcall GetDpiX();
	int __fastcall GetDpiY();
	Vcl::Graphics::TPen* __fastcall GetPen();
	int __fastcall GetTextFlags();
	void __fastcall SetBrush(Vcl::Graphics::TBrush* Value);
	void __fastcall SetCopyMode(int Value);
	void __fastcall SetFont(Vcl::Graphics::TFont* Value);
	void __fastcall SetPen(Vcl::Graphics::TPen* Value);
	void __fastcall SetPixel(int X, int Y, System::Uitypes::TColor Value);
	void __fastcall SetTextFlags(int Value);
	
protected:
	Vcl::Graphics::TCanvas* FCanvas;
	virtual bool __fastcall GetDefaultUseRightToLeftAlignment();
	virtual HDC __fastcall GetHandle();
	void __fastcall InitializePen(System::Uitypes::TColor AColor, Vcl::Graphics::TPenStyle AStyle, int AWidth);
	virtual void __fastcall SetCanvas(Vcl::Graphics::TCanvas* Value);
	void __fastcall SynchronizeObjects(Vcl::Graphics::TCanvas* ACanvas, NativeUInt ADC)/* overload */;
	void __fastcall SynchronizeObjects(NativeUInt ADC)/* overload */;
	
public:
	__fastcall virtual TcxCanvas(Vcl::Graphics::TCanvas* ACanvas);
	__fastcall virtual ~TcxCanvas();
	void __fastcall AngleArc(int X, int Y, unsigned ARadius, float AStartAngle, float ASweepAngle);
	HIDESBASE void __fastcall Arc(int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4)/* overload */;
	virtual void __fastcall Arc(const System::Types::TRect &AEllipse, const System::Types::TPoint &AStartPoint, const System::Types::TPoint &AEndPoint, System::Uitypes::TColor AColor, int APenWidth = 0x1, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0))/* overload */;
	void __fastcall ArcTo(int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4);
	void __fastcall Chord(int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4);
	HIDESBASE void __fastcall Ellipse(int X1, int Y1, int X2, int Y2)/* overload */;
	HIDESBASE void __fastcall Ellipse(const System::Types::TRect &Rect)/* overload */;
	virtual void __fastcall Ellipse(const System::Types::TRect &Rect, System::Uitypes::TColor ABrushColor, System::Uitypes::TColor APenColor, Vcl::Graphics::TPenStyle APenStyle, int APenWidth)/* overload */;
	void __fastcall FloodFill(int X, int Y, System::Uitypes::TColor Color, Vcl::Graphics::TFillStyle FillStyle);
	HIDESBASE void __fastcall Line(const System::Types::TPoint &P1, const System::Types::TPoint &P2)/* overload */;
	HIDESBASE void __fastcall Line(int X1, int Y1, int X2, int Y2)/* overload */;
	void __fastcall LineTo(int X, int Y);
	void __fastcall MoveTo(int X, int Y);
	void __fastcall PolyBezier(const System::Types::TPoint *Points, const int Points_High);
	void __fastcall PolyBezierTo(const System::Types::TPoint *Points, const int Points_High);
	HIDESBASE void __fastcall Polygon(const System::Types::TPoint *Points, const int Points_High)/* overload */;
	virtual void __fastcall Polygon(const System::Types::TPoint *Points, const int Points_High, System::Uitypes::TColor ABrushColor, System::Uitypes::TColor APenColor)/* overload */;
	HIDESBASE void __fastcall Polyline(const System::Types::TPoint *Points, const int Points_High)/* overload */;
	virtual void __fastcall Polyline(const System::Types::TPoint *Points, const int Points_High, System::Uitypes::TColor AColor, int APenWidth = 0x1, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0))/* overload */;
	HIDESBASE void __fastcall Rectangle(const System::Types::TRect &R)/* overload */;
	HIDESBASE void __fastcall Rectangle(int X1, int Y1, int X2, int Y2)/* overload */;
	HIDESBASE void __fastcall Rectangle(const System::Types::TRect &R, const TcxViewParams &AParams, const Cxgeometry::TcxBorders ABorders = (Cxgeometry::TcxBorders() << Cxgeometry::TcxBorder::bLeft << Cxgeometry::TcxBorder::bTop << Cxgeometry::TcxBorder::bRight << Cxgeometry::TcxBorder::bBottom ), System::Uitypes::TColor ABorderColor = (System::Uitypes::TColor)(0x20000000), int ALineWidth = 0x1, bool AExcludeRect = false)/* overload */;
	virtual void __fastcall Rectangle(const System::Types::TRect &R, System::Uitypes::TColor ABrushColor, System::Uitypes::TColor APenColor, Vcl::Graphics::TPenStyle APenStyle, int APenWidth = 0x1)/* overload */;
	void __fastcall RoundRect(int X1, int Y1, int X2, int Y2, int X3, int Y3)/* overload */;
	void __fastcall RoundRect(const System::Types::TRect &R, int CX, int CY)/* overload */;
	HIDESBASE void __fastcall FillRect(const System::Types::TRect &R, Vcl::Graphics::TBitmap* ABitmap = (Vcl::Graphics::TBitmap*)(0x0), bool AExcludeRect = false)/* overload */;
	virtual void __fastcall FillRect(const System::Types::TRect &R, System::Uitypes::TColor AColor)/* overload */;
	HIDESBASE void __fastcall FillRect(const System::Types::TRect &R, const TcxViewParams &AParams, bool AExcludeRect = false)/* overload */;
	void __fastcall FillRegion(TcxRegion* ARegion, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000))/* overload */;
	void __fastcall FillRegion(HRGN ARegion, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000))/* overload */;
	HIDESBASE void __fastcall FrameRect(const System::Types::TRect &R)/* overload */;
	virtual void __fastcall FrameRect(const System::Types::TRect &R, System::Uitypes::TColor AColor, int ALineWidth = 0x1, Cxgeometry::TcxBorders ABorders = (Cxgeometry::TcxBorders() << Cxgeometry::TcxBorder::bLeft << Cxgeometry::TcxBorder::bTop << Cxgeometry::TcxBorder::bRight << Cxgeometry::TcxBorder::bBottom ))/* overload */;
	HIDESBASE void __fastcall FrameRect(const System::Types::TRect &R, System::Uitypes::TColor AColor, int ALineWidth, const Cxgeometry::TcxBorders ABorders, bool AExcludeFrame)/* overload */;
	void __fastcall FrameRegion(TcxRegion* ARegion, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000), int ABorderWidth = 0x1, int ABorderHeight = 0x1)/* overload */;
	void __fastcall FrameRegion(HRGN ARegion, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000), int ABorderWidth = 0x1, int ABorderHeight = 0x1)/* overload */;
	HIDESBASE void __fastcall Pie(int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4)/* overload */;
	HIDESBASE void __fastcall Pie(const System::Types::TRect &R, const System::Types::TPoint &ARadial1, const System::Types::TPoint &ARadial2)/* overload */;
	HIDESBASE void __fastcall Pie(const System::Types::TRect &R, int AStartAngle, int ASweepAngle)/* overload */;
	void __fastcall BrushCopy(const System::Types::TRect &Dest, Vcl::Graphics::TBitmap* Bitmap, const System::Types::TRect &Source, System::Uitypes::TColor Color);
	void __fastcall CopyRect(const System::Types::TRect &Dest, Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &Source);
	void __fastcall Draw(int X, int Y, Vcl::Graphics::TGraphic* Graphic)/* overload */;
	void __fastcall Draw(int X, int Y, Vcl::Graphics::TGraphic* Graphic, System::Byte Opacity)/* overload */;
	void __fastcall DrawDesignSelection(const System::Types::TRect &ARect, int AWidth = 0x2);
	void __fastcall DrawFocusRect(const System::Types::TRect &R);
	void __fastcall DrawFocusRectEx(const System::Types::TRect &R, Cxgeometry::TcxBorders ABorders, bool AExclude = false);
	void __fastcall DrawGlyph(int X, int Y, Vcl::Graphics::TBitmap* AGlyph, bool AEnabled = true, System::Uitypes::TColor ABackgroundColor = (System::Uitypes::TColor)(0x1fffffff));
	HIDESBASE void __fastcall DrawImage(Vcl::Imglist::TCustomImageList* Images, int X, int Y, int Index, bool Enabled = true);
	void __fastcall DrawRegion(TcxRegion* ARegion, System::Uitypes::TColor AContentColor = (System::Uitypes::TColor)(0x20000000), System::Uitypes::TColor ABorderColor = (System::Uitypes::TColor)(0x20000000), int ABorderWidth = 0x1, int ABorderHeight = 0x1)/* overload */;
	void __fastcall DrawRegion(HRGN ARegion, System::Uitypes::TColor AContentColor = (System::Uitypes::TColor)(0x20000000), System::Uitypes::TColor ABorderColor = (System::Uitypes::TColor)(0x20000000), int ABorderWidth = 0x1, int ABorderHeight = 0x1)/* overload */;
	void __fastcall DrawTexT(const System::UnicodeString Text, const System::Types::TRect &R, int Flags, bool Enabled = true)/* overload */;
	void __fastcall DrawTexT(const System::UnicodeString Text, const System::Types::TRect &R, int Flags, bool Enabled, Cxcustomcanvas::TcxRotationAngle ARotationAngle)/* overload */;
	void __fastcall DrawTexT(const System::UnicodeString Text, const System::Types::TRect &R, System::Classes::TAlignment AAlignmentHorz, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AMultiLine, bool AShowEndEllipsis)/* overload */;
	void __fastcall FlipHorizontally(Vcl::Graphics::TBitmap* ABitmap);
	void __fastcall InvertFrame(const System::Types::TRect &R, int ABorderSize);
	void __fastcall InvertRect(const System::Types::TRect &R);
	void __fastcall RotateBitmap(Vcl::Graphics::TBitmap* ABitmap, Cxcustomcanvas::TcxRotationAngle ARotationAngle, bool AFlipVertically = false);
	void __fastcall StretchDraw(const System::Types::TRect &Rect, Vcl::Graphics::TGraphic* Graphic);
	void __fastcall TextOut(int X, int Y, const System::UnicodeString Text);
	void __fastcall TransparentDraw(int X, int Y, Vcl::Graphics::TBitmap* ABitmap, System::Byte AAlpha, Vcl::Graphics::TBitmap* ABackground = (Vcl::Graphics::TBitmap*)(0x0));
	bool __fastcall HandleAllocated();
	void __fastcall Lock();
	void __fastcall Refresh();
	void __fastcall Unlock();
	void __fastcall AlignMultiLineTextRectVertically(System::Types::TRect &R, const System::UnicodeString AText, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AWordBreak, bool AShowPrefix, bool AEnabled = true, bool ADontBreakChars = false, bool AEndEllipsis = false, bool AExpandTabs = false);
	void __fastcall GetTextStringsBounds(System::UnicodeString Text, const System::Types::TRect &R, int Flags, bool Enabled, Dxcore::TRects &ABounds);
	int __fastcall FontHeight(Vcl::Graphics::TFont* AFont);
	System::Types::TSize __fastcall TextExtent(const System::UnicodeString Text)/* overload */;
	void __fastcall TextExtent(const System::UnicodeString Text, System::Types::TRect &R, int Flags)/* overload */;
	int __fastcall TextHeight(const System::UnicodeString Text);
	int __fastcall TextWidth(const System::UnicodeString Text);
	void __fastcall RestoreDC();
	void __fastcall SaveDC();
	virtual void __fastcall RestoreClipRegion();
	virtual void __fastcall SaveClipRegion();
	virtual void __fastcall RestoreState();
	virtual void __fastcall SaveState();
	void __fastcall GetParams(TcxViewParams &AParams);
	void __fastcall SetParams(const TcxViewParams &AParams);
	void __fastcall SetBrushColor(System::Uitypes::TColor Value);
	void __fastcall SetFontAngle(int Value);
	void __fastcall BeginPath();
	void __fastcall EndPath();
	TcxRegion* __fastcall PathToRegion(bool AConsiderOrigin = true);
	void __fastcall WidenPath();
	void __fastcall ExcludeFrameRect(const System::Types::TRect &R, int ALineWidth = 0x1, Cxgeometry::TcxBorders ABorders = (Cxgeometry::TcxBorders() << Cxgeometry::TcxBorder::bLeft << Cxgeometry::TcxBorder::bTop << Cxgeometry::TcxBorder::bRight << Cxgeometry::TcxBorder::bBottom ));
	TcxRegion* __fastcall GetClipRegion(bool AConsiderOrigin = true);
	void __fastcall SetClipRegion(TcxRegion* ARegion, TcxRegionOperation AOperation, bool ADestroyRegion = true, bool AConsiderOrigin = true);
	bool __fastcall RectFullyVisible(const System::Types::TRect &R);
	void __fastcall OffsetClipRegion(int AOffsetX, int AOffsetY);
	__property Vcl::Graphics::TBrush* Brush = {read=GetBrush, write=SetBrush};
	__property Vcl::Graphics::TCanvas* Canvas = {read=FCanvas, write=SetCanvas};
	__property int CopyMode = {read=GetCopyMode, write=SetCopyMode, nodefault};
	__property int DpiX = {read=GetDpiX, nodefault};
	__property int DpiY = {read=GetDpiY, nodefault};
	__property Vcl::Graphics::TFont* Font = {read=GetFont, write=SetFont};
	__property Vcl::Graphics::TPen* Pen = {read=GetPen, write=SetPen};
	__property System::Uitypes::TColor Pixels[int X][int Y] = {write=SetPixel};
	__property int TextFlags = {read=GetTextFlags, write=SetTextFlags, nodefault};
	/* Hoisted overloads: */
	
public:
	inline void __fastcall  Arc(const System::Types::TRect &AEllipse, const System::Types::TPoint &AStartPoint, const System::Types::TPoint &AEndPoint, Dxcoregraphics::TdxAlphaColor AColor, int APenWidth, Vcl::Graphics::TPenStyle APenStyle){ Cxcustomcanvas::TcxGdiBasedCanvas::Arc(AEllipse, AStartPoint, AEndPoint, AColor, APenWidth, APenStyle); }
	inline void __fastcall  Ellipse(const System::Types::TRect &R, Dxcoregraphics::TdxAlphaColor ABrushColor, Dxcoregraphics::TdxAlphaColor APenColor, Vcl::Graphics::TPenStyle APenStyle, int APenWidth){ Cxcustomcanvas::TcxGdiBasedCanvas::Ellipse(R, ABrushColor, APenColor, APenStyle, APenWidth); }
	inline void __fastcall  Ellipse(const Cxgeometry::TdxRectF &R, Cxcustomcanvas::TcxCanvasBasedBrush* ABrush, Cxcustomcanvas::TcxCanvasBasedPen* APen){ Cxcustomcanvas::TcxGdiBasedCanvas::Ellipse(R, ABrush, APen); }
	inline void __fastcall  Line(const System::Types::TPoint &P1, const System::Types::TPoint &P2, Dxcoregraphics::TdxAlphaColor AColor, int APenWidth, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0)){ Cxcustomcanvas::TcxGdiBasedCanvas::Line(P1, P2, AColor, APenWidth, APenStyle); }
	inline void __fastcall  Line(const Cxgeometry::TdxPointF &P1, const Cxgeometry::TdxPointF &P2, Cxcustomcanvas::TcxCanvasBasedPen* APen){ Cxcustomcanvas::TcxGdiBasedCanvas::Line(P1, P2, APen); }
	inline void __fastcall  Line(const System::Types::TPoint &P1, const System::Types::TPoint &P2, System::Uitypes::TColor AColor, int APenWidth = 0x1, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0)){ Cxcustomcanvas::TcxCustomCanvas::Line(P1, P2, AColor, APenWidth, APenStyle); }
	inline void __fastcall  Polygon(const System::Types::TPoint *P, const int P_High, Dxcoregraphics::TdxAlphaColor ABrushColor, Dxcoregraphics::TdxAlphaColor APenColor){ Cxcustomcanvas::TcxGdiBasedCanvas::Polygon(P, P_High, ABrushColor, APenColor); }
	inline void __fastcall  Polygon(const Cxgeometry::PdxPointF P, int ACount, Cxcustomcanvas::TcxCanvasBasedBrush* ABrush, Cxcustomcanvas::TcxCanvasBasedPen* APen){ Cxcustomcanvas::TcxGdiBasedCanvas::Polygon(P, ACount, ABrush, APen); }
	inline void __fastcall  Polygon(const Cxgeometry::TdxPointF *P, const int P_High, Cxcustomcanvas::TcxCanvasBasedBrush* ABrush, Cxcustomcanvas::TcxCanvasBasedPen* APen){ Cxcustomcanvas::TcxCustomCanvas::Polygon(P, P_High, ABrush, APen); }
	inline void __fastcall  Polyline(const Cxgeometry::PdxPointF P, int ACount, Cxcustomcanvas::TcxCanvasBasedPen* APen){ Cxcustomcanvas::TcxGdiBasedCanvas::Polyline(P, ACount, APen); }
	inline void __fastcall  Polyline(const System::Types::TPoint *P, const int P_High, Dxcoregraphics::TdxAlphaColor AColor, int APenWidth = 0x1, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0)){ Cxcustomcanvas::TcxGdiBasedCanvas::Polyline(P, P_High, AColor, APenWidth, APenStyle); }
	inline void __fastcall  Polyline(const Cxgeometry::TdxPointF *P, const int P_High, Cxcustomcanvas::TcxCanvasBasedPen* APen){ Cxcustomcanvas::TcxCustomCanvas::Polyline(P, P_High, APen); }
	inline void __fastcall  Rectangle(const System::Types::TRect &R, Dxcoregraphics::TdxAlphaColor ABrushColor, Dxcoregraphics::TdxAlphaColor APenColor, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0), int APenWidth = 0x1){ Cxcustomcanvas::TcxGdiBasedCanvas::Rectangle(R, ABrushColor, APenColor, APenStyle, APenWidth); }
	inline void __fastcall  Rectangle(const Cxgeometry::TdxRectF &R, Cxcustomcanvas::TcxCanvasBasedBrush* ABrush, Cxcustomcanvas::TcxCanvasBasedPen* APen){ Cxcustomcanvas::TcxCustomCanvas::Rectangle(R, ABrush, APen); }
	inline void __fastcall  FillRect(const System::Types::TRect &R, Dxcoregraphics::TdxAlphaColor AColor){ Cxcustomcanvas::TcxGdiBasedCanvas::FillRect(R, AColor); }
	inline void __fastcall  FillRect(const System::Types::TRect &R, Dxgdiplusclasses::TdxGPImage* AImage, Cxcustomcanvas::PcxCanvasBasedImage ACache = (Cxcustomcanvas::PcxCanvasBasedImage)(0x0)){ Cxcustomcanvas::TcxGdiBasedCanvas::FillRect(R, AImage, ACache); }
	inline void __fastcall  FillRect(const System::Types::TRect &R, Cxcustomcanvas::TcxCanvasBasedImage* AImage){ Cxcustomcanvas::TcxCustomGdiBasedCanvas::FillRect(R, AImage); }
	inline void __fastcall  FillRect(const System::Types::TRect &R, System::Uitypes::TColor AColor, System::Byte AAlpha){ Cxcustomcanvas::TcxCustomCanvas::FillRect(R, AColor, AAlpha); }
	inline void __fastcall  FillRect(const Cxgeometry::TdxRectF &R, Dxcoregraphics::TdxAlphaColor AColor){ Cxcustomcanvas::TcxCustomCanvas::FillRect(R, AColor); }
	inline void __fastcall  FillRect(const Cxgeometry::TdxRectF &R, Cxcustomcanvas::TcxCanvasBasedBrush* ABrush){ Cxcustomcanvas::TcxCustomCanvas::FillRect(R, ABrush); }
	inline void __fastcall  FrameRect(const System::Types::TRect &R, Dxcoregraphics::TdxAlphaColor AColor, int ALineWidth = 0x1, Cxgeometry::TcxBorders ABorders = (Cxgeometry::TcxBorders() << Cxgeometry::TcxBorder::bLeft << Cxgeometry::TcxBorder::bTop << Cxgeometry::TcxBorder::bRight << Cxgeometry::TcxBorder::bBottom )){ Cxcustomcanvas::TcxCustomCanvas::FrameRect(R, AColor, ALineWidth, ABorders); }
	inline void __fastcall  FrameRect(const Cxgeometry::TdxRectF &R, Dxcoregraphics::TdxAlphaColor AColor, float ALineWidth = 1.000000E+00f, Cxgeometry::TcxBorders ABorders = (Cxgeometry::TcxBorders() << Cxgeometry::TcxBorder::bLeft << Cxgeometry::TcxBorder::bTop << Cxgeometry::TcxBorder::bRight << Cxgeometry::TcxBorder::bBottom )){ Cxcustomcanvas::TcxCustomCanvas::FrameRect(R, AColor, ALineWidth, ABorders); }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxMeasureCanvas : public TcxCanvas
{
	typedef TcxCanvas inherited;
	
private:
	Vcl::Graphics::TBitmap* FBitmap;
	
public:
	__fastcall virtual TcxMeasureCanvas();
	__fastcall virtual ~TcxMeasureCanvas();
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxScreenCanvas : public TcxCanvas
{
	typedef TcxCanvas inherited;
	
public:
	__fastcall virtual TcxScreenCanvas();
	__fastcall virtual ~TcxScreenCanvas();
	void __fastcall Dormant();
};

#pragma pack(pop)

struct DECLSPEC_DRECORD TcxPaintCanvasState
{
public:
	Vcl::Graphics::TCanvas* PrevCanvas;
	int FSaveDC;
};


typedef System::DynamicArray<TcxPaintCanvasState> TcxPaintCanvasStates;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPaintCanvas : public TcxCanvas
{
	typedef TcxCanvas inherited;
	
private:
	int FCounter;
	TcxPaintCanvasStates FSavedStates;
	void __fastcall SetCapacity(int AValue);
	
protected:
	virtual void __fastcall SetCanvas(Vcl::Graphics::TCanvas* Value);
	
public:
	__fastcall TcxPaintCanvas();
	__fastcall virtual ~TcxPaintCanvas();
	void __fastcall BeginPaint(NativeUInt ADC)/* overload */;
	void __fastcall BeginPaint(Vcl::Graphics::TCanvas* ACanvas)/* overload */;
	void __fastcall EndPaint();
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxBitmap : public Vcl::Graphics::TBitmap
{
	typedef Vcl::Graphics::TBitmap inherited;
	
private:
	bool FCompressData;
	TcxCanvas* FcxCanvas;
	int FLockCount;
	bool FModified;
	HIDESBASE TcxCanvas* __fastcall GetCanvas();
	System::Types::TRect __fastcall GetClientRect();
	bool __fastcall GetIsDormant();
	void __fastcall CompressByBlock(System::Classes::TStream* ASourceStream, System::Classes::TStream* ADestStream, int ASize, int ABlockSize);
	void __fastcall DecompressByBlock(System::Classes::TStream* ASourceStream, System::Classes::TStream* ADestStream, int ASize, int ABlockSize);
	void __fastcall Compress(System::Classes::TStream* ASourceStream, System::Classes::TStream* ADestStream, int ASize);
	void __fastcall Decompress1(System::Classes::TStream* ASourceStream, System::Classes::TStream* ADestStream, int ASize);
	void __fastcall Decompress2(System::Classes::TStream* ASourceStream, System::Classes::TStream* ADestStream, int ASize);
	
protected:
	virtual void __fastcall Changed(System::TObject* Sender);
	bool __fastcall ChangeLocked();
	virtual void __fastcall Initialize(int AWidth, int AHeight, Vcl::Graphics::TPixelFormat APixelFormat);
	virtual void __fastcall Update();
	virtual void __fastcall ReadData(System::Classes::TStream* Stream);
	virtual void __fastcall WriteData(System::Classes::TStream* Stream);
	__property bool IsDormant = {read=GetIsDormant, nodefault};
	
public:
	__fastcall virtual TcxBitmap()/* overload */;
	__fastcall virtual TcxBitmap(int AWidth, int AHeight)/* overload */;
	__fastcall TcxBitmap(int AWidth, int AHeight, Vcl::Graphics::TPixelFormat APixelFormat)/* overload */;
	__fastcall TcxBitmap(const System::Types::TSize &ASize)/* overload */;
	__fastcall TcxBitmap(const System::Types::TRect &ARect)/* overload */;
	__fastcall TcxBitmap(const System::Types::TRect &ARect, Vcl::Graphics::TPixelFormat APixelFormat)/* overload */;
	__fastcall virtual ~TcxBitmap();
	void __fastcall BeginUpdate();
	void __fastcall CancelUpdate();
	void __fastcall EndUpdate(bool AForceUpdate = true);
	void __fastcall CopyBitmap(Vcl::Graphics::TBitmap* ASrcBitmap, unsigned ACopyMode = (unsigned)(0xcc0020))/* overload */;
	void __fastcall CopyBitmap(Vcl::Graphics::TBitmap* ASrcBitmap, const System::Types::TRect &ADestRect, const System::Types::TPoint &ASrcTopLeft, unsigned ACopyMode = (unsigned)(0xcc0020))/* overload */;
	HIDESBASE void __fastcall Dormant();
	void __fastcall Flip(bool AFlipHorizontally, bool AFlipVertically);
	void __fastcall Rotate(Cxcustomcanvas::TcxRotationAngle ARotationAngle, bool AFlipVertically = false);
	virtual void __fastcall SetSize(int AWidth, int AHeight)/* overload */;
	HIDESBASE void __fastcall SetSize(const System::Types::TRect &ARect)/* overload */;
	__property bool CompressData = {read=FCompressData, write=FCompressData, nodefault};
	__property System::Types::TRect ClientRect = {read=GetClientRect};
	__property TcxCanvas* cxCanvas = {read=GetCanvas};
};


enum DECLSPEC_DENUM TcxImageFitMode : unsigned char { ifmNormal, ifmStretch, ifmProportionalStretch, ifmFit, ifmFill };

enum DECLSPEC_DENUM TcxBitmapTransformationMode : unsigned char { btmDingy, btmDirty, btmGrayScale, btmSetOpaque, btmMakeMask, btmFade, btmDisable, btmCorrectBlend, btmHatch, btmClear, btmResetAlpha, btmExtractLayer };

typedef void __fastcall (__closure *TcxBitmapTransformationProc)(tagRGBQUAD &AColor);

typedef bool __fastcall (*TcxDrawImageProc)(Vcl::Graphics::TCanvas* ACanvas, Vcl::Imglist::TCustomImageList* AImages, int AImageIndex, Vcl::Graphics::TGraphic* AGlyph, const System::Types::TRect &ARect, Cxcustomcanvas::TcxImageDrawMode ADrawMode);

struct DECLSPEC_DRECORD TcxColorTransitionMap
{
public:
	float RedScale;
	float GreenScale;
	float BlueScale;
	System::Byte SrcAlpha;
	System::Byte SrcConstantAlpha;
};


struct DECLSPEC_DRECORD TcxHatchData
{
public:
	tagRGBQUAD Color1;
	System::Byte Alpha1;
	tagRGBQUAD Color2;
	System::Byte Alpha2;
	System::Byte Step;
};


class PASCALIMPLEMENTATION TcxBitmap32 : public TcxBitmap
{
	typedef TcxBitmap inherited;
	
private:
	Dxcore::TdxDefaultBoolean FIsAlphaUsed;
	bool __fastcall GetIsAlphaUsed();
	
protected:
	virtual void __fastcall Update();
	void __fastcall Resize(int ANewWidth, int ANewHeight, bool AStretch, bool ASmooth, System::Uitypes::TColor AFillColor = (System::Uitypes::TColor)(0x1fffffff));
	
public:
	__fastcall virtual TcxBitmap32(int AWidth, int AHeight)/* overload */;
	__fastcall TcxBitmap32(int AWidth, int AHeight, bool AClear)/* overload */;
	__fastcall TcxBitmap32(const System::Types::TRect &ARect, bool AClear)/* overload */;
	__fastcall TcxBitmap32(const System::Types::TSize &ASize, bool AClear)/* overload */;
	virtual void __fastcall AfterConstruction();
	void __fastcall GetBitmapColors(/* out */ Dxcoregraphics::TRGBColors &AColors);
	void __fastcall SetBitmapColors(const Dxcoregraphics::TRGBColors AColors);
	void __fastcall AlphaBlend(TcxBitmap32* ADestBitmap, const System::Types::TRect &ADestRect, bool ASmoothImage, System::Byte AConstantAlpha = (System::Byte)(0xff));
	virtual void __fastcall Clear();
	void __fastcall Darken(System::Byte APercent);
	void __fastcall Filter(TcxBitmap32* AMaskBitmap);
	void __fastcall Invert();
	void __fastcall Lighten(System::Byte APercent);
	virtual void __fastcall LoadFromStream(System::Classes::TStream* Stream);
	void __fastcall MakeOpaque();
	void __fastcall RecoverTransparency(System::Uitypes::TColor ATransparentColor);
	void __fastcall SetAlphaChannel(System::Byte Alpha);
	__property bool IsAlphaUsed = {read=GetIsAlphaUsed, nodefault};
public:
	/* TcxBitmap.Create */ inline __fastcall virtual TcxBitmap32()/* overload */ : TcxBitmap() { }
	/* TcxBitmap.CreateSize */ inline __fastcall TcxBitmap32(int AWidth, int AHeight, Vcl::Graphics::TPixelFormat APixelFormat)/* overload */ : TcxBitmap(AWidth, AHeight, APixelFormat) { }
	/* TcxBitmap.CreateSize */ inline __fastcall TcxBitmap32(const System::Types::TSize &ASize)/* overload */ : TcxBitmap(ASize) { }
	/* TcxBitmap.CreateSize */ inline __fastcall TcxBitmap32(const System::Types::TRect &ARect)/* overload */ : TcxBitmap(ARect) { }
	/* TcxBitmap.CreateSize */ inline __fastcall TcxBitmap32(const System::Types::TRect &ARect, Vcl::Graphics::TPixelFormat APixelFormat)/* overload */ : TcxBitmap(ARect, APixelFormat) { }
	/* TcxBitmap.Destroy */ inline __fastcall virtual ~TcxBitmap32() { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxColorList : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	HIDESBASE int __fastcall Add(System::Uitypes::TColor AColor);
public:
	/* TList.Destroy */ inline __fastcall virtual ~TcxColorList() { }
	
public:
	/* TObject.Create */ inline __fastcall TcxColorList() : System::Classes::TList() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxAlphaBitmap : public TcxBitmap32
{
	typedef TcxBitmap32 inherited;
	
private:
	tagRGBQUAD FTransparentBkColor;
	TcxColorList* FTransparentPixels;
	System::Types::TPoint FCurrentColorIndex;
	TcxHatchData FHatchData;
	void __fastcall CorrectBlend(tagRGBQUAD &AColor);
	void __fastcall ClearColor(tagRGBQUAD &AColor);
	void __fastcall Dingy(tagRGBQUAD &AColor);
	void __fastcall Dirty(tagRGBQUAD &AColor);
	void __fastcall Disable(tagRGBQUAD &AColor);
	void __fastcall ExtractLayerProc(tagRGBQUAD &AColor);
	void __fastcall Fade(tagRGBQUAD &AColor);
	void __fastcall GrayScale(tagRGBQUAD &AColor);
	void __fastcall Hatch(tagRGBQUAD &AColor);
	void __fastcall MakeMask(tagRGBQUAD &AColor);
	void __fastcall SetOpaque(tagRGBQUAD &AColor);
	void __fastcall ResetAlpha(tagRGBQUAD &AColor);
	bool __fastcall IsColorTransparent(const tagRGBQUAD AColor);
	
protected:
	virtual void __fastcall Initialize(int AWidth, int AHeight, Vcl::Graphics::TPixelFormat APixelFormat);
	void __fastcall ScaleColor(tagRGBQUAD &AColor, const TcxColorTransitionMap &AColorMap);
	__property TcxHatchData HatchData = {read=FHatchData, write=FHatchData};
	__property tagRGBQUAD TransparentBkColor = {read=FTransparentBkColor, write=FTransparentBkColor};
	__property TcxColorList* TransparentPixels = {read=FTransparentPixels};
	
public:
	__fastcall virtual TcxAlphaBitmap(int AWidth, int AHeight)/* overload */;
	__fastcall TcxAlphaBitmap(int AWidth, int AHeight, tagRGBQUAD ATransparentBkColor)/* overload */;
	__fastcall virtual ~TcxAlphaBitmap();
	virtual void __fastcall Clear();
	void __fastcall DrawHatch(const TcxHatchData &AHatchData)/* overload */;
	void __fastcall DrawHatch(System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, System::Byte AStep, System::Byte AAlpha1 = (System::Byte)(0xff), System::Byte AAlpha2 = (System::Byte)(0xff))/* overload */;
	void __fastcall DrawShadow(TcxAlphaBitmap* AMaskBitmap, int AShadowSize, System::Uitypes::TColor AShadowColor, bool AInflateSize = false);
	void __fastcall ExtractLayer(System::Uitypes::TColor ATransparentColor);
	void __fastcall RecoverAlphaChannel(System::Uitypes::TColor ATransparentColor)/* overload */;
	void __fastcall RecoverAlphaChannel(const System::Types::TRect &ARect, System::Uitypes::TColor ATransparentColor)/* overload */;
	void __fastcall Shade(TcxAlphaBitmap* AMaskBitmap);
	void __fastcall TransformBitmap(TcxBitmapTransformationMode AMode);
	void __fastcall RefreshImage(int AWidth, int AHeight)/* overload */;
	void __fastcall RefreshImage(const System::Types::TRect &ARect)/* overload */;
public:
	/* TcxBitmap32.CreateSize */ inline __fastcall TcxAlphaBitmap(int AWidth, int AHeight, bool AClear)/* overload */ : TcxBitmap32(AWidth, AHeight, AClear) { }
	/* TcxBitmap32.CreateSize */ inline __fastcall TcxAlphaBitmap(const System::Types::TRect &ARect, bool AClear)/* overload */ : TcxBitmap32(ARect, AClear) { }
	/* TcxBitmap32.CreateSize */ inline __fastcall TcxAlphaBitmap(const System::Types::TSize &ASize, bool AClear)/* overload */ : TcxBitmap32(ASize, AClear) { }
	
public:
	/* TcxBitmap.Create */ inline __fastcall virtual TcxAlphaBitmap()/* overload */ : TcxBitmap32() { }
	/* TcxBitmap.CreateSize */ inline __fastcall TcxAlphaBitmap(int AWidth, int AHeight, Vcl::Graphics::TPixelFormat APixelFormat)/* overload */ : TcxBitmap32(AWidth, AHeight, APixelFormat) { }
	/* TcxBitmap.CreateSize */ inline __fastcall TcxAlphaBitmap(const System::Types::TSize &ASize)/* overload */ : TcxBitmap32(ASize) { }
	/* TcxBitmap.CreateSize */ inline __fastcall TcxAlphaBitmap(const System::Types::TRect &ARect)/* overload */ : TcxBitmap32(ARect) { }
	/* TcxBitmap.CreateSize */ inline __fastcall TcxAlphaBitmap(const System::Types::TRect &ARect, Vcl::Graphics::TPixelFormat APixelFormat)/* overload */ : TcxBitmap32(ARect, APixelFormat) { }
	
};


class PASCALIMPLEMENTATION TcxImageList : public Cximagelist::TcxCustomImageList
{
	typedef Cximagelist::TcxCustomImageList inherited;
	
public:
	/* TcxCustomImageList.Destroy */ inline __fastcall virtual ~TcxImageList() { }
	
public:
	/* TCustomImageList.Create */ inline __fastcall virtual TcxImageList(System::Classes::TComponent* AOwner) : Cximagelist::TcxCustomImageList(AOwner) { }
	/* TCustomImageList.CreateSize */ inline __fastcall TcxImageList(int AWidth, int AHeight) : Cximagelist::TcxCustomImageList(AWidth, AHeight) { }
	
};


class PASCALIMPLEMENTATION TcxImageCollectionItem : public Cxclasses::TcxComponentCollectionItem
{
	typedef Cxclasses::TcxComponentCollectionItem inherited;
	
private:
	Vcl::Graphics::TPicture* FPicture;
	NativeInt FTag;
	System::Types::TRect __fastcall GetClientRect();
	int __fastcall GetHeight();
	int __fastcall GetWidth();
	void __fastcall SetPicture(Vcl::Graphics::TPicture* AValue);
	
protected:
	virtual System::UnicodeString __fastcall GetDisplayName();
	virtual Cxclasses::TcxComponentCollection* __fastcall GetCollectionFromParent(System::Classes::TComponent* AParent);
	void __fastcall DoPictureChanged(System::TObject* Sender);
	
public:
	__fastcall virtual TcxImageCollectionItem(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxImageCollectionItem();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall Draw(Vcl::Graphics::TCanvas* ACanvas, int X, int Y)/* overload */;
	void __fastcall Draw(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &R, bool AStretch = true, bool ASmoothResize = false, bool AEnabled = true)/* overload */;
	__property System::Types::TRect ClientRect = {read=GetClientRect};
	__property int Height = {read=GetHeight, nodefault};
	__property int Width = {read=GetWidth, nodefault};
	
__published:
	__property Vcl::Graphics::TPicture* Picture = {read=FPicture, write=SetPicture};
	__property NativeInt Tag = {read=FTag, write=FTag, default=0};
};


class PASCALIMPLEMENTATION TcxImageCollectionItems : public Cxclasses::TcxComponentCollection
{
	typedef Cxclasses::TcxComponentCollection inherited;
	
public:
	TcxImageCollectionItem* operator[](int Index) { return this->Items[Index]; }
	
private:
	TcxImageCollection* FCollection;
	HIDESBASE TcxImageCollectionItem* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TcxImageCollectionItem* AValue);
	
protected:
	virtual void __fastcall SetItemName(Cxclasses::TcxComponentCollectionItem* AItem, int ABaseIndex = 0xffffffff);
	virtual void __fastcall Update(Cxclasses::TcxComponentCollectionItem* AItem, Cxclasses::TcxComponentCollectionNotification AAction);
	
public:
	__fastcall TcxImageCollectionItems(TcxImageCollection* ACollection);
	HIDESBASE TcxImageCollectionItem* __fastcall Add();
	bool __fastcall FindItemByName(const System::UnicodeString AName, /* out */ TcxImageCollectionItem* &AItem);
	HIDESBASE TcxImageCollectionItem* __fastcall FindItemByID(int ID);
	HIDESBASE TcxImageCollectionItem* __fastcall Insert(int Index);
	__property TcxImageCollectionItem* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TcxComponentCollection.Destroy */ inline __fastcall virtual ~TcxImageCollectionItems() { }
	
};


class PASCALIMPLEMENTATION TcxImageCollection : public Cxclasses::TcxCustomComponent
{
	typedef Cxclasses::TcxCustomComponent inherited;
	
private:
	TcxImageCollectionItems* FItems;
	System::Classes::TInterfaceList* FListeners;
	int __fastcall GetCount();
	bool __fastcall GetFrame(int AFrameIndex, const System::Types::TSize &ASize, TcxImageFitMode AMode, Dxgdiplusclasses::TdxSmartImage* &AFrame);
	void __fastcall SetItems(TcxImageCollectionItems* AItems);
	
protected:
	void __fastcall Changed();
	void __fastcall DoDestroyed();
	
public:
	__fastcall virtual TcxImageCollection(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxImageCollection();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall AddFromMultiFrameImage(Dxgdiplusclasses::TdxSmartImage* ASource);
	Dxgdiplusclasses::TdxSmartImage* __fastcall GetAsMultiFrameTIFF()/* overload */;
	Dxgdiplusclasses::TdxSmartImage* __fastcall GetAsMultiFrameTIFF(const System::Types::TSize &ASize, TcxImageFitMode AMode)/* overload */;
	DYNAMIC void __fastcall GetChildren(System::Classes::TGetChildProc Proc, System::Classes::TComponent* Root);
	void __fastcall Draw(Vcl::Graphics::TCanvas* ACanvas, int X, int Y, int AIndex)/* overload */;
	void __fastcall Draw(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &R, int AIndex, bool AStretch = true, bool ASmoothResize = false, bool AEnabled = true)/* overload */;
	void __fastcall AddListener(_di_IcxImageCollectionListener AListener);
	void __fastcall RemoveListener(_di_IcxImageCollectionListener AListener);
	__property int Count = {read=GetCount, nodefault};
	
__published:
	__property TcxImageCollectionItems* Items = {read=FItems, write=SetItems};
};


class PASCALIMPLEMENTATION TcxSystemImageList : public Vcl::Controls::TImageList
{
	typedef Vcl::Controls::TImageList inherited;
	
private:
	int FSourceDPI;
	
protected:
	int __fastcall GetSourceDPI();
	
public:
	__fastcall virtual TcxSystemImageList(System::Classes::TComponent* AOwner);
public:
	/* TCustomImageList.CreateSize */ inline __fastcall TcxSystemImageList(int AWidth, int AHeight) : Vcl::Controls::TImageList(AWidth, AHeight) { }
	/* TCustomImageList.Destroy */ inline __fastcall virtual ~TcxSystemImageList() { }
	
private:
	void *__IdxSourceDPI;	// Dxdpiawareutils::IdxSourceDPI 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {F722512C-50D3-4266-AA1C-399C3301BB6A}
	operator Dxdpiawareutils::_di_IdxSourceDPI()
	{
		Dxdpiawareutils::_di_IdxSourceDPI intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Dxdpiawareutils::IdxSourceDPI*(void) { return (Dxdpiawareutils::IdxSourceDPI*)&__IdxSourceDPI; }
	#endif
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSolidBrushCacheManager : public Dxcoregraphics::TdxValueCacheManager__2<System::Uitypes::TColor,HBRUSH>
{
	typedef Dxcoregraphics::TdxValueCacheManager__2<System::Uitypes::TColor,HBRUSH> inherited;
	
protected:
	virtual void __fastcall DoRemove(const HBRUSH Value);
public:
	/* {dxCoreGraphics}TdxValueCacheManager<System_UITypes_TColor,Winapi_Windows_HBRUSH>.Create */ inline __fastcall TdxSolidBrushCacheManager(int ACapacity)/* overload */ : Dxcoregraphics::TdxValueCacheManager__2<System::Uitypes::TColor,HBRUSH>(ACapacity) { }
	/* {dxCoreGraphics}TdxValueCacheManager<System_UITypes_TColor,Winapi_Windows_HBRUSH>.Create */ inline __fastcall TdxSolidBrushCacheManager(int ACapacity, System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<System::Uitypes::TColor> > AEqualityComparer)/* overload */ : Dxcoregraphics::TdxValueCacheManager__2<System::Uitypes::TColor,HBRUSH>(ACapacity, AEqualityComparer) { }
	/* {dxCoreGraphics}TdxValueCacheManager<System_UITypes_TColor,Winapi_Windows_HBRUSH>.Destroy */ inline __fastcall virtual ~TdxSolidBrushCacheManager() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSolidBrushCache : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	static const System::Byte Capacity = System::Byte(0x80);
	
	static TdxSolidBrushCacheManager* FData;
	static System::TObject* FSystemPaletteChangedNotifier;
	
protected:
	__classmethod void __fastcall Initialize();
	__classmethod void __fastcall Finalize();
	
public:
	__classmethod void __fastcall Clear();
	__classmethod HBRUSH __fastcall Get(const System::Uitypes::TColor AColor);
public:
	/* TObject.Create */ inline __fastcall TdxSolidBrushCache() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSolidBrushCache() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxColorUtils : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	#define TdxColorUtils_DefaultTextContrast  (4.500000E+00)
	
	__classmethod TdxHSL __fastcall AlphaColorToHSL(Dxcoregraphics::TdxAlphaColor AColor)/* overload */;
	__classmethod TdxHSL __fastcall AlphaColorToHSL(Dxcoregraphics::TdxAlphaColor AColor, /* out */ System::Byte &AAlpha)/* overload */;
	__classmethod TdxHSL __fastcall ColorToHSL(System::Uitypes::TColor AColor);
	__classmethod Dxcoregraphics::TdxAlphaColor __fastcall HSLToAlphaColor(const TdxHSL &AHSL, System::Byte AAlpha = (System::Byte)(0xff))/* overload */;
	__classmethod System::Uitypes::TColor __fastcall HSLToColor(const TdxHSL &AHSL)/* overload */;
	__classmethod System::Uitypes::TColor __fastcall HSLToColor(const double H, const double S, const double L)/* overload */;
	__classmethod tagRGBQUAD __fastcall HSLToRGB(const TdxHSL &AHSL)/* overload */;
	__classmethod tagRGBQUAD __fastcall HSLToRGB(const double H, const double S, const double L)/* overload */;
	__classmethod void __fastcall HSLToRGB(const double H, const double S, const double L, /* out */ System::Byte &R, /* out */ System::Byte &G, /* out */ System::Byte &B)/* overload */;
	__classmethod TdxHSL __fastcall RGBToHSL(const tagRGBQUAD ARGB);
	__classmethod TdxHSV __fastcall ColorToHSV(System::Uitypes::TColor AColor);
	__classmethod System::Uitypes::TColor __fastcall HSVToColor(const TdxHSV &AHSV)/* overload */;
	__classmethod System::Uitypes::TColor __fastcall HSVToColor(const double H, const double S, const double V)/* overload */;
	__classmethod TdxHSV __fastcall RGBToHSV(const tagRGBQUAD ARGB);
	__classmethod System::Uitypes::TColor __fastcall ChangeLightness(System::Uitypes::TColor AColor, const double ALightnessDelta);
	__classmethod System::Uitypes::TColor __fastcall ChangeSaturation(System::Uitypes::TColor AColor, const double ASaturationDelta);
	__classmethod System::Uitypes::TColor __fastcall Colorize(System::Uitypes::TColor ABaseColor, System::Uitypes::TColor AColor);
	__classmethod double __fastcall ComponentToXYZ(const System::Byte AComponent);
	__classmethod double __fastcall Contrast(const System::Uitypes::TColor AForegroundColor, const System::Uitypes::TColor ABackgroundColor);
	__classmethod Dxcoregraphics::TdxAlphaColor __fastcall InvertLightness(Dxcoregraphics::TdxAlphaColor AColor)/* overload */;
	__classmethod System::Uitypes::TColor __fastcall InvertLightness(System::Uitypes::TColor AColor)/* overload */;
	__classmethod double __fastcall Luminance(const System::Uitypes::TColor AColor)/* overload */;
	__classmethod double __fastcall Luminance(const System::Byte R, const System::Byte G, const System::Byte B)/* overload */;
	__classmethod System::Uitypes::TColor __fastcall MakeForegroundColor(System::Uitypes::TColor ABackgroundColor);
	__classmethod System::Uitypes::TColor __fastcall MultiplyLightness(System::Uitypes::TColor AColor, const double AFactor);
public:
	/* TObject.Create */ inline __fastcall TdxColorUtils() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxColorUtils() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TdxColorPaletteBuilder : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	#define TdxColorPaletteBuilder_DefaultLightnessDelta  (1.500000E-01)
	
	#define TdxColorPaletteBuilder_MaxBaseLightness  (8.000000E-01)
	
	#define TdxColorPaletteBuilder_MaxLightness  (9.000000E-01)
	
	#define TdxColorPaletteBuilder_MinBaseLightness  (4.000000E-01)
	
	#define TdxColorPaletteBuilder_MinLightness  (2.000000E-01)
	
	#define TdxColorPaletteBuilder_MinSaturation  (4.000000E-01)
	
	
private:
	TdxHSL FBaseColor;
	void __fastcall EnsureCapacity(Dxgenerics::TdxAlphaColorList* AList, int ACount)/* overload */;
	void __fastcall EnsureCapacity(Dxgenerics::TdxColorList* AList, int ACount)/* overload */;
	
public:
	__fastcall TdxColorPaletteBuilder(const System::Uitypes::TColor ABaseColor)/* overload */;
	__fastcall TdxColorPaletteBuilder(const Dxcoregraphics::TdxAlphaColor ABaseColor)/* overload */;
	__fastcall TdxColorPaletteBuilder(const tagRGBQUAD ABaseColor)/* overload */;
	void __fastcall Build(Dxgenerics::TdxAlphaColorList* ATargetList, Dxcoregraphics::TdxAlphaColor *ABasePalette, const int ABasePalette_High)/* overload */;
	void __fastcall Build(Dxgenerics::TdxAlphaColorList* ATargetList, Dxcoregraphics::TdxAlphaColor *ABasePalette, const int ABasePalette_High, float ALightnessDelta)/* overload */;
	void __fastcall Build(Dxgenerics::TdxColorList* ATargetList, System::Uitypes::TColor *ABasePalette, const int ABasePalette_High)/* overload */;
	void __fastcall Build(Dxgenerics::TdxColorList* ATargetList, System::Uitypes::TColor *ABasePalette, const int ABasePalette_High, float ALightnessDelta)/* overload */;
	Dxcoregraphics::TdxAlphaColor __fastcall Build(Dxcoregraphics::TdxAlphaColor AColor, float ALightnessDelta = 0.000000E+00f)/* overload */;
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxColorPaletteBuilder() { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAdjustFontSizeCustomHelper : public System::TObject
{
	typedef System::TObject inherited;
	
	
protected:
	typedef int __fastcall (__closure *TCheckParamFunc)(int ALastSuitableValue, int AOriginalValue, int AMinValue);
	
	typedef int __fastcall (__closure *TMeasureTextFunc)(const System::UnicodeString AText, int AParam);
	
	
private:
	static const System::Int8 LineSpacingScaleFactor = System::Int8(0x64);
	
	bool FAllowAdjustLineSpacing;
	Vcl::Graphics::TFont* FFont;
	float FLineSpacing;
	int FWidth;
	void __fastcall SetFont(Vcl::Graphics::TFont* AValue);
	
protected:
	unsigned FFlags;
	virtual void __fastcall AfterCalculate();
	virtual void __fastcall BeforeCalculate();
	int __fastcall CalculateCore(int AAvailableSize, int AParam, int AParamLow, const System::UnicodeString AText, TMeasureTextFunc AMeasureFunc, TCheckParamFunc ACheckParamFunc);
	virtual int __fastcall CheckFontSize(int ALastSuitableSize, int AOriginalSize, int AMinSize);
	int __fastcall DoMeasureTextHeight1(const System::UnicodeString AText, int ALineSpacing);
	int __fastcall DoMeasureTextHeight2(const System::UnicodeString AText, int AFontSize);
	int __fastcall DoMeasureTextWidth(const System::UnicodeString AText, int AFontSize);
	virtual int __fastcall GetMinFontSize() = 0 ;
	virtual float __fastcall GetMinLineSpacing();
	virtual int __fastcall GetTextHeight(const System::UnicodeString AText, int AWidth, float ALineSpacing) = 0 ;
	virtual int __fastcall GetTextWidth(const System::UnicodeString AText) = 0 ;
	
public:
	__fastcall TdxAdjustFontSizeCustomHelper();
	__fastcall virtual ~TdxAdjustFontSizeCustomHelper();
	void __fastcall Calculate(const int AAvailableWidth, const System::UnicodeString AText)/* overload */;
	void __fastcall Calculate(const System::Types::TSize &AAvailableSize, const System::UnicodeString AText, bool AMultiline, unsigned AFlags, int AMaxFontSize = 0xffffffff)/* overload */;
	__property bool AllowAdjustLineSpacing = {read=FAllowAdjustLineSpacing, write=FAllowAdjustLineSpacing, nodefault};
	__property Vcl::Graphics::TFont* Font = {read=FFont, write=SetFont};
	__property float LineSpacing = {read=FLineSpacing};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAdjustFontSizeHelper : public TdxAdjustFontSizeCustomHelper
{
	typedef TdxAdjustFontSizeCustomHelper inherited;
	
private:
	int FZoomFactor;
	tagXFORM FPrevXForm;
	
protected:
	virtual void __fastcall AfterCalculate();
	virtual void __fastcall BeforeCalculate();
	virtual int __fastcall GetMinFontSize();
	virtual int __fastcall GetTextHeight(const System::UnicodeString AText, int AWidth, float ALineSpacing);
	virtual int __fastcall GetTextWidth(const System::UnicodeString AText);
	
public:
	__fastcall TdxAdjustFontSizeHelper();
	__property int ZoomFactor = {read=FZoomFactor, write=FZoomFactor, nodefault};
public:
	/* TdxAdjustFontSizeCustomHelper.Destroy */ inline __fastcall virtual ~TdxAdjustFontSizeHelper() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxImageAnimationController : public Dxsmartimage::TdxSmartImageAnimationController
{
	typedef Dxsmartimage::TdxSmartImageAnimationController inherited;
	
private:
	Cxclasses::TcxTimer* FTimer;
	
protected:
	virtual void __fastcall ActivateTimer();
	virtual void __fastcall DeactivateTimer();
	virtual bool __fastcall IsTimerActive();
	__property Cxclasses::TcxTimer* Timer = {read=FTimer};
	
public:
	__fastcall virtual ~TdxImageAnimationController();
public:
	/* TdxSmartImageAnimationController.Create */ inline __fastcall virtual TdxImageAnimationController(Dxsmartimage::TdxCustomSmartImage* AImage) : Dxsmartimage::TdxSmartImageAnimationController(AImage) { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TdxDrawImageCacheID
{
public:
	HBRUSH BrushHandle;
	Cxcustomcanvas::TcxImageDrawMode DrawMode;
	Vcl::Graphics::TGraphic* Glyph;
	int ImageIndex;
	Vcl::Imglist::TCustomImageList* ImageList;
	GUID PaletteID;
	bool SmoothImage;
	System::Uitypes::TColor TransparentColor;
	bool UseLeftBottomPixelAsTransparent;
	__fastcall TdxDrawImageCacheID(Vcl::Graphics::TGraphic* AGlyph, Vcl::Imglist::TCustomImageList* AImageList, int AImageIndex, Cxcustomcanvas::TcxImageDrawMode ADrawMode, bool AUseLeftBottomPixelAsTransparent, bool ASmoothImage, System::Uitypes::TColor ATransparentColor, const Dxcoregraphics::_di_IdxColorPalette APalette, HBRUSH ABrushHandle);
	int __fastcall GetHashCode();
	bool __fastcall IsEqual(const TdxDrawImageCacheID &ID);
	void __fastcall Reset();
	TdxDrawImageCacheID() {}
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxImageListPaintCache : public System::TObject
{
	typedef System::TObject inherited;
	
	
protected:
	class DELPHICLASS TImageIdComparer;
	class PASCALIMPLEMENTATION TImageIdComparer : public System::Generics::Defaults::TEqualityComparer__1<TdxDrawImageCacheID>
	{
		typedef System::Generics::Defaults::TEqualityComparer__1<TdxDrawImageCacheID> inherited;
		
	public:
		virtual bool __fastcall Equals(const TdxDrawImageCacheID &Left, const TdxDrawImageCacheID &Right)/* overload */;
		virtual int __fastcall GetHashCode(const TdxDrawImageCacheID &Value)/* overload */;
	public:
		/* TObject.Create */ inline __fastcall TImageIdComparer() : System::Generics::Defaults::TEqualityComparer__1<TdxDrawImageCacheID>() { }
		/* TObject.Destroy */ inline __fastcall virtual ~TImageIdComparer() { }
		
	};
	
	
	class DELPHICLASS TImageListCacheHelper;
	#pragma pack(push,8)
	class PASCALIMPLEMENTATION TImageListCacheHelper : public System::Classes::TComponent
	{
		typedef System::Classes::TComponent inherited;
		
		
	private:
		class DELPHICLASS TImages;
		class PASCALIMPLEMENTATION TImages : public System::Generics::Collections::TObjectDictionary__2<TdxDrawImageCacheID,Dxgdiplusclasses::TdxGPImage*>
		{
			typedef System::Generics::Collections::TObjectDictionary__2<TdxDrawImageCacheID,Dxgdiplusclasses::TdxGPImage*> inherited;
			
		public:
			__fastcall TImages(int ACapacity);
		public:
			/* {System_Generics_Collections}TDictionary<cxGraphics_TdxDrawImageCacheID,dxGDIPlusClasses_TdxGPImage>.Destroy */ inline __fastcall virtual ~TImages() { }
			
		};
		
		
		class DELPHICLASS TSizeImages;
		class PASCALIMPLEMENTATION TSizeImages : public System::Generics::Collections::TObjectDictionary__2<System::Types::TSize,TdxImageListPaintCache::TImageListCacheHelper::TImages*>
		{
			typedef System::Generics::Collections::TObjectDictionary__2<System::Types::TSize,TdxImageListPaintCache::TImageListCacheHelper::TImages*> inherited;
			
		public:
			/* {System_Generics_Collections}TObjectDictionary<System_Types_TSize,cxGraphics_TdxImageListPaintCache_TImageListCacheHelper_TImages>.Create */ inline __fastcall TSizeImages(System::Generics::Collections::TDictionaryOwnerships Ownerships, int ACapacity)/* overload */ : System::Generics::Collections::TObjectDictionary__2<System::Types::TSize,TdxImageListPaintCache::TImageListCacheHelper::TImages*>(Ownerships, ACapacity) { }
			/* {System_Generics_Collections}TObjectDictionary<System_Types_TSize,cxGraphics_TdxImageListPaintCache_TImageListCacheHelper_TImages>.Create */ inline __fastcall TSizeImages(System::Generics::Collections::TDictionaryOwnerships Ownerships, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<System::Types::TSize> > AComparer)/* overload */ : System::Generics::Collections::TObjectDictionary__2<System::Types::TSize,TdxImageListPaintCache::TImageListCacheHelper::TImages*>(Ownerships, AComparer) { }
			/* {System_Generics_Collections}TObjectDictionary<System_Types_TSize,cxGraphics_TdxImageListPaintCache_TImageListCacheHelper_TImages>.Create */ inline __fastcall TSizeImages(System::Generics::Collections::TDictionaryOwnerships Ownerships, int ACapacity, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<System::Types::TSize> > AComparer)/* overload */ : System::Generics::Collections::TObjectDictionary__2<System::Types::TSize,TdxImageListPaintCache::TImageListCacheHelper::TImages*>(Ownerships, ACapacity, AComparer) { }
			
		public:
			/* {System_Generics_Collections}TDictionary<System_Types_TSize,cxGraphics_TdxImageListPaintCache_TImageListCacheHelper_TImages>.Create */ inline __fastcall TSizeImages()/* overload */ : System::Generics::Collections::TObjectDictionary__2<System::Types::TSize,TdxImageListPaintCache::TImageListCacheHelper::TImages*>() { }
			/* {System_Generics_Collections}TDictionary<System_Types_TSize,cxGraphics_TdxImageListPaintCache_TImageListCacheHelper_TImages>.Create */ inline __fastcall TSizeImages(int ACapacity)/* overload */ : System::Generics::Collections::TObjectDictionary__2<System::Types::TSize,TdxImageListPaintCache::TImageListCacheHelper::TImages*>(ACapacity) { }
			/* {System_Generics_Collections}TDictionary<System_Types_TSize,cxGraphics_TdxImageListPaintCache_TImageListCacheHelper_TImages>.Create */ inline __fastcall TSizeImages(const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<System::Types::TSize> > AComparer)/* overload */ : System::Generics::Collections::TObjectDictionary__2<System::Types::TSize,TdxImageListPaintCache::TImageListCacheHelper::TImages*>(AComparer) { }
			/* {System_Generics_Collections}TDictionary<System_Types_TSize,cxGraphics_TdxImageListPaintCache_TImageListCacheHelper_TImages>.Create */ inline __fastcall TSizeImages(int ACapacity, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<System::Types::TSize> > AComparer)/* overload */ : System::Generics::Collections::TObjectDictionary__2<System::Types::TSize,TdxImageListPaintCache::TImageListCacheHelper::TImages*>(ACapacity, AComparer) { }
			/* {System_Generics_Collections}TDictionary<System_Types_TSize,cxGraphics_TdxImageListPaintCache_TImageListCacheHelper_TImages>.Create */ inline __fastcall TSizeImages(System::Generics::Collections::TEnumerable__1<System::Generics::Collections::TPair__2<System::Types::TSize,TdxImageListPaintCache::TImageListCacheHelper::TImages*> >* const Collection)/* overload */ : System::Generics::Collections::TObjectDictionary__2<System::Types::TSize,TdxImageListPaintCache::TImageListCacheHelper::TImages*>(Collection) { }
			/* {System_Generics_Collections}TDictionary<System_Types_TSize,cxGraphics_TdxImageListPaintCache_TImageListCacheHelper_TImages>.Create */ inline __fastcall TSizeImages(System::Generics::Collections::TEnumerable__1<System::Generics::Collections::TPair__2<System::Types::TSize,TdxImageListPaintCache::TImageListCacheHelper::TImages*> >* const Collection, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<System::Types::TSize> > AComparer)/* overload */ : System::Generics::Collections::TObjectDictionary__2<System::Types::TSize,TdxImageListPaintCache::TImageListCacheHelper::TImages*>(Collection, AComparer) { }
			/* {System_Generics_Collections}TDictionary<System_Types_TSize,cxGraphics_TdxImageListPaintCache_TImageListCacheHelper_TImages>.Create */ inline __fastcall TSizeImages(const System::Generics::Collections::TPair__2<System::Types::TSize,TdxImageListPaintCache::TImageListCacheHelper::TImages*> *AItems, const int AItems_High)/* overload */ : System::Generics::Collections::TObjectDictionary__2<System::Types::TSize,TdxImageListPaintCache::TImageListCacheHelper::TImages*>(AItems, AItems_High) { }
			/* {System_Generics_Collections}TDictionary<System_Types_TSize,cxGraphics_TdxImageListPaintCache_TImageListCacheHelper_TImages>.Create */ inline __fastcall TSizeImages(const System::Generics::Collections::TPair__2<System::Types::TSize,TdxImageListPaintCache::TImageListCacheHelper::TImages*> *AItems, const int AItems_High, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<System::Types::TSize> > AComparer)/* overload */ : System::Generics::Collections::TObjectDictionary__2<System::Types::TSize,TdxImageListPaintCache::TImageListCacheHelper::TImages*>(AItems, AItems_High, AComparer) { }
			/* {System_Generics_Collections}TDictionary<System_Types_TSize,cxGraphics_TdxImageListPaintCache_TImageListCacheHelper_TImages>.Destroy */ inline __fastcall virtual ~TSizeImages() { }
			
		};
		
		
		
	private:
		Vcl::Imglist::TCustomImageList* FImageList;
		Vcl::Imglist::TChangeLink* FImagesChangeLink;
		TImages* FLastImages;
		System::Types::TSize FLastSize;
		int FMaxSizeCount;
		TSizeImages* FSizedImages;
		System::Generics::Collections::TQueue__1<System::Types::TSize>* FSizes;
		
	protected:
		Dxgdiplusclasses::TdxGPImage* __fastcall GetImage(const System::Types::TRect &ABounds, int AIndex, Cxcustomcanvas::TcxImageDrawMode ADrawMode, bool AUseLeftBottomPixelAsTransparent, const Dxcoregraphics::_di_IdxColorPalette APalette, bool ASmoothImage);
		void __fastcall ImageListChanged(System::TObject* Sender);
		virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
		
	public:
		__fastcall TImageListCacheHelper(Vcl::Imglist::TCustomImageList* AImages, int AMaxSizeCount);
		__fastcall virtual ~TImageListCacheHelper();
		void __fastcall Draw(Cxcustomcanvas::TcxGdiBasedCanvas* ACanvas, const System::Types::TRect &ABounds, int AIndex, Cxcustomcanvas::TcxImageDrawMode ADrawMode, bool AUseLeftBottomPixelAsTransparent, const Dxcoregraphics::_di_IdxColorPalette APalette, bool ASmoothImage)/* overload */;
		void __fastcall Draw(Dxgdiplusclasses::TdxGPGraphics* AGraphic, const System::Types::TRect &ABounds, int AIndex, Cxcustomcanvas::TcxImageDrawMode ADrawMode, bool AUseLeftBottomPixelAsTransparent, const Dxcoregraphics::_di_IdxColorPalette APalette)/* overload */;
		void __fastcall Invalidate();
		__property Vcl::Imglist::TCustomImageList* ImageList = {read=FImageList};
	};
	
	#pragma pack(pop)
	
	
private:
	static Vcl::Imglist::TCustomImageList* FLastImages;
	static TImageListCacheHelper* FLastHelper;
	static System::Generics::Collections::TObjectDictionary__2<Vcl::Imglist::TCustomImageList*,TImageListCacheHelper*>* FImages;
	static TcxAlphaBitmap* FTransferBitmap;
	// __classmethod void __fastcall Initialize@();
	// __classmethod void __fastcall Finalize@();
	
protected:
	static void __fastcall SetupHelper(Vcl::Imglist::TCustomImageList* AImages);
	static void __fastcall RemoveHelper(TImageListCacheHelper* AHelper);
	/* static */ __property TcxAlphaBitmap* TransferBitmap = {read=FTransferBitmap};
	
public:
	static void __fastcall Draw(Cxcustomcanvas::TcxGdiBasedCanvas* ACanvas, const System::Types::TRect &ABounds, Vcl::Imglist::TCustomImageList* AImages, int AIndex, Cxcustomcanvas::TcxImageDrawMode ADrawMode, bool AUseLeftBottomPixelAsTransparent, Dxcoregraphics::_di_IdxColorPalette APalette, bool ASmoothImage)/* overload */;
	static void __fastcall Draw(Dxgdiplusclasses::TdxGPGraphics* AGraphic, const System::Types::TRect &ABounds, Vcl::Imglist::TCustomImageList* AImages, int AIndex, Cxcustomcanvas::TcxImageDrawMode ADrawMode, bool AUseLeftBottomPixelAsTransparent, Dxcoregraphics::_di_IdxColorPalette APalette)/* overload */;
	static void __fastcall InvalidateImageList(Vcl::Imglist::TCustomImageList* AImages);
	__classmethod void __fastcall PrepareImage(Dxgdiplusclasses::TdxGPImage* ATarget, const System::Types::TSize &ASize, const TdxDrawImageCacheID &ID, const Dxcoregraphics::_di_IdxColorPalette AColorPalette);
public:
	/* TObject.Create */ inline __fastcall TdxImageListPaintCache() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxImageListPaintCache() { }
	
};

#pragma pack(pop)

struct DECLSPEC_DRECORD TcxColorInfo
{
public:
	System::UnicodeString Name;
	System::Uitypes::TColor Color;
};


typedef System::StaticArray<TcxColorInfo, 169> Cxgraphics__72;

typedef bool __fastcall (__closure *TdxGetImageFrameProc)(int AIndex, const System::Types::TSize &ASize, TcxImageFitMode AMode, Dxgdiplusclasses::TdxSmartImage* &AFrame);

//-- var, const, procedure ---------------------------------------------------
static const System::Int8 cxAlignLeft = System::Int8(0x1);
static const System::Int8 cxAlignRight = System::Int8(0x2);
static const System::Int8 cxAlignHCenter = System::Int8(0x4);
static const System::Int8 cxAlignTop = System::Int8(0x8);
static const System::Int8 cxAlignBottom = System::Int8(0x10);
static const System::Int8 cxAlignVCenter = System::Int8(0x20);
static const System::Int8 cxAlignCenter = System::Int8(0x24);
static const System::Int8 cxSingleLine = System::Int8(0x40);
static const System::Byte cxDontClip = System::Byte(0x80);
static const System::Word cxExpandTabs = System::Word(0x100);
static const System::Word cxShowPrefix = System::Word(0x200);
static const System::Word cxWordBreak = System::Word(0x400);
static const System::Word cxShowEndEllipsis = System::Word(0x800);
static const System::Word cxCalcRect = System::Word(0x1000);
static const System::Word cxShowPathEllipsis = System::Word(0x2000);
static const System::Word cxDontBreakChars = System::Word(0x4000);
static const System::Word cxNoFullWidthCharBreak = System::Word(0x8000);
static const int cxRtlReading = int(0x10000);
static const int cxShowWordEllipsis = int(0x20000);
static const System::Word cxDontPrint = System::Word(0x1000);
extern DELPHI_PACKAGE System::StaticArray<int, 3> SystemAlignmentsHorz;
extern DELPHI_PACKAGE System::StaticArray<int, 3> SystemAlignmentsVert;
extern DELPHI_PACKAGE System::StaticArray<int, 3> cxAlignmentsHorz;
extern DELPHI_PACKAGE System::StaticArray<int, 3> cxAlignmentsVert;
static const int clcxLightGray = int(0xcfcfcf);
extern DELPHI_PACKAGE System::Types::TRect cxEmptyRect;
static const System::Int8 cxDesignSelectionWidth = System::Int8(0x2);
static const System::Int8 cxTransparencyCheckerboardSizeDefault = System::Int8(0x8);
static const System::Int8 cxTransparencyCheckerboardSizeSmall = System::Int8(0x2);
static const System::Byte cxDefaultAlphaValue = System::Byte(0xc8);
extern DELPHI_PACKAGE Vcl::Graphics::TBrush* cxHalfToneBrush;
extern DELPHI_PACKAGE Vcl::Graphics::TPixelFormat cxDoubleBufferedBitmapPixelFormat;
static const System::Word cxMaxRegionSize = System::Word(0x7530);
extern DELPHI_PACKAGE TcxColorTransitionMap DisableMap;
extern DELPHI_PACKAGE TcxColorTransitionMap FadeMap;
extern DELPHI_PACKAGE TcxColorTransitionMap GrayMap;
extern DELPHI_PACKAGE System::StaticArray<Cxcustomcanvas::TcxImageDrawMode, 2> EnabledImageDrawModeMap;
extern DELPHI_PACKAGE Cxgraphics__72 cxColorsByName;
static const System::Int8 dxDefaultFontSizeCount = System::Int8(0x10);
extern DELPHI_PACKAGE System::StaticArray<int, 16> dxDefaultFontSizes;
extern DELPHI_PACKAGE TcxDrawImageProc CustomDrawImageProc;
extern DELPHI_PACKAGE bool dxUseAntialiasingForRotatedText;
static const System::Int8 LAYOUT_LTR = System::Int8(0x0);
extern DELPHI_PACKAGE int __fastcall cxGetCurrentDPI(void);
extern DELPHI_PACKAGE int __fastcall cxGetValueCurrentDPI(int AValue)/* overload */;
extern DELPHI_PACKAGE System::Types::TPoint __fastcall cxGetValueCurrentDPI(const System::Types::TPoint &AValue)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxGetValueCurrentDPI(const System::Types::TRect &AValue)/* overload */;
extern DELPHI_PACKAGE System::Types::TSize __fastcall cxGetValueCurrentDPI(const System::Types::TSize &AValue)/* overload */;
extern DELPHI_PACKAGE System::Types::TSize __fastcall cxGetPixelsPerInch(void);
extern DELPHI_PACKAGE int __fastcall cxFlagsToDTFlags(int Flags);
extern DELPHI_PACKAGE void __fastcall cxSetImageList(Vcl::Imglist::TCustomImageList* const AValue, Vcl::Imglist::TCustomImageList* &AFieldValue, Vcl::Imglist::TChangeLink* AChangeLink, System::Classes::TComponent* ANotifyComponent, Dxcoreclasses::TdxComponentNotificationProc ANotificationProc = 0x0);
extern DELPHI_PACKAGE bool __fastcall IsGlyphAssigned(Vcl::Graphics::TGraphic* AGlyph);
extern DELPHI_PACKAGE bool __fastcall IsImageAssigned(Vcl::Imglist::TCustomImageList* AImageList, int AImageIndex)/* overload */;
extern DELPHI_PACKAGE bool __fastcall IsImageAssigned(Vcl::Graphics::TGraphic* AGlyph, Vcl::Imglist::TCustomImageList* AImageList, int AImageIndex)/* overload */;
extern DELPHI_PACKAGE bool __fastcall IsImageAssigned(Vcl::Graphics::TGraphic* AImage)/* overload */;
extern DELPHI_PACKAGE bool __fastcall IsPictureAssigned(Vcl::Graphics::TPicture* APicture);
extern DELPHI_PACKAGE System::Types::TSize __fastcall dxGetImageSize(Vcl::Graphics::TGraphic* AImage)/* overload */;
extern DELPHI_PACKAGE System::Types::TSize __fastcall dxGetImageSize(Vcl::Graphics::TGraphic* AImage, Vcl::Imglist::TCustomImageList* AImageList, int AImageIndex, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
extern DELPHI_PACKAGE System::Types::TSize __fastcall dxGetImageSize(Vcl::Graphics::TGraphic* AImage, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
extern DELPHI_PACKAGE System::Types::TSize __fastcall dxGetImageSize(Vcl::Graphics::TGraphic* AImage, Vcl::Imglist::TCustomImageList* AImageList, int AImageIndex)/* overload */;
extern DELPHI_PACKAGE System::Types::TSize __fastcall dxGetImageSize(Vcl::Imglist::TCustomImageList* AImageList, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
extern DELPHI_PACKAGE System::Types::TSize __fastcall dxGetImageSize(Vcl::Imglist::TCustomImageList* AImageList, int APPI)/* overload */;
extern DELPHI_PACKAGE System::Types::TSize __fastcall dxGetImageSize(Vcl::Graphics::TPicture* APicture, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
extern DELPHI_PACKAGE System::Types::TSize __fastcall dxGetImageSize(Vcl::Graphics::TPicture* APicture)/* overload */;
extern DELPHI_PACKAGE int __fastcall dxGetImageSourceDPI(System::TObject* AImage);
extern DELPHI_PACKAGE bool __fastcall IsXPManifestEnabled(void);
extern DELPHI_PACKAGE System::Uitypes::TColor __fastcall dxGetNearestColor(System::Uitypes::TColor AColor);
extern DELPHI_PACKAGE System::Uitypes::TColor __fastcall dxInvertColor(System::Uitypes::TColor AColor);
extern DELPHI_PACKAGE System::Uitypes::TColor __fastcall dxOffsetColor(System::Uitypes::TColor AColor, System::Byte ARed, System::Byte AGreen, System::Byte ABlue);
extern DELPHI_PACKAGE Dxcoregraphics::TdxAlphaColor __fastcall cxGetActualAlphaColor(const Dxcoregraphics::TdxAlphaColor AValue, const Dxcoregraphics::TdxAlphaColor ADefaultValue);
extern DELPHI_PACKAGE System::Uitypes::TColor __fastcall cxGetActualColor(const System::Uitypes::TColor AValue, const System::Uitypes::TColor ADefaultValue);
extern DELPHI_PACKAGE TdxHSV __fastcall dxColorToHSV(System::Uitypes::TColor AColor);
extern DELPHI_PACKAGE System::Uitypes::TColor __fastcall dxHSVToColor(const TdxHSV &AHSV);
extern DELPHI_PACKAGE System::Uitypes::TColor __fastcall dxGetColorTint(System::Uitypes::TColor AColor, int ATintPercent);
extern DELPHI_PACKAGE System::Uitypes::TColor __fastcall GetLightColor(TcxColorPart ABtnFaceColorPart, TcxColorPart AHighlightColorPart, TcxColorPart AWindowColorPart);
extern DELPHI_PACKAGE System::Uitypes::TColor __fastcall GetLightBtnFaceColor(void);
extern DELPHI_PACKAGE System::Uitypes::TColor __fastcall GetLightDownedColor(void);
extern DELPHI_PACKAGE System::Uitypes::TColor __fastcall GetLightDownedSelColor(void);
extern DELPHI_PACKAGE System::Uitypes::TColor __fastcall GetLightSelColor(void);
extern DELPHI_PACKAGE System::Uitypes::TColor __fastcall dxGetDarkerColor(System::Uitypes::TColor AColor, System::Byte APercent);
extern DELPHI_PACKAGE System::Uitypes::TColor __fastcall dxGetMiddleRGB(System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, int APercent);
extern DELPHI_PACKAGE System::Uitypes::TColor __fastcall dxGetLighterColor(System::Uitypes::TColor AColor, System::Byte APercent);
extern DELPHI_PACKAGE float __fastcall dxGetColorRelativeLuminance(System::Uitypes::TColor AColor);
extern DELPHI_PACKAGE bool __fastcall IsHighContrast(void);
extern DELPHI_PACKAGE bool __fastcall IsHighContrastBlack(void);
extern DELPHI_PACKAGE bool __fastcall IsHighContrastWhite(void);
extern DELPHI_PACKAGE bool __fastcall IsHighContrast2(void);
extern DELPHI_PACKAGE bool __fastcall cxIntersectClipRect(HDC DC, const System::Types::TRect &R);
extern DELPHI_PACKAGE void __fastcall cxExcludeClipRect(HDC DC, const System::Types::TRect &R);
extern DELPHI_PACKAGE void __fastcall FillGradientRect(HDC DC, const System::Types::TRect &ARect, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, bool AHorizontal);
extern DELPHI_PACKAGE void __fastcall FillTubeGradientRect(HDC DC, const System::Types::TRect &ARect, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, int AGradientPercent, bool AHorizontal);
extern DELPHI_PACKAGE void __fastcall FillRectByColor(HDC DC, const System::Types::TRect &R, System::Uitypes::TColor AColor);
extern DELPHI_PACKAGE void __fastcall FillRegionByColor(HDC DC, HRGN ARegion, System::Uitypes::TColor AColor);
extern DELPHI_PACKAGE void __fastcall FrameRectByColor(HDC DC, const System::Types::TRect &R, System::Uitypes::TColor AColor);
extern DELPHI_PACKAGE System::Uitypes::TColor __fastcall GetGradientColorRect(const System::Types::TRect &ARect, int X, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, bool AHorizontal);
extern DELPHI_PACKAGE bool __fastcall CanApplySystemAlphaBlending(void);
extern DELPHI_PACKAGE bool __fastcall SystemAlphaBlend(HDC ADestDC, HDC ASrcDC, const System::Types::TRect &ADestRect, const System::Types::TRect &ASrcRect, System::Byte AAlpha = (System::Byte)(0xff), bool AHasPerPixelAlpha = true);
extern DELPHI_PACKAGE bool __fastcall cxColorByName(const System::UnicodeString AText, System::Uitypes::TColor &AColor);
extern DELPHI_PACKAGE bool __fastcall cxNameByColor(System::Uitypes::TColor AColor, System::UnicodeString &AText);
extern DELPHI_PACKAGE void __fastcall cxAlphaBlend(Vcl::Graphics::TBitmap* ADestBitmap, Vcl::Graphics::TBitmap* ASrcBitmap, const System::Types::TRect &ADestRect, const System::Types::TRect &ASrcRect, bool ASmoothImage = false, System::Byte AConstantAlpha = (System::Byte)(0xff))/* overload */;
extern DELPHI_PACKAGE void __fastcall cxAlphaBlend(HDC ADestDC, Vcl::Graphics::TBitmap* ASrcBitmap, const System::Types::TRect &ADestRect, const System::Types::TRect &ASrcRect, bool ASmoothImage = false, System::Byte AConstantAlpha = (System::Byte)(0xff))/* overload */;
extern DELPHI_PACKAGE void __fastcall cxAlphaBlend(HDC ADestDC, HDC ASrcDC, const System::Types::TRect &ADestRect, const System::Types::TRect &ASrcRect, bool ASmoothImage = false, System::Byte AConstantAlpha = (System::Byte)(0xff))/* overload */;
extern DELPHI_PACKAGE void __fastcall cxBitBlt(HDC ADestDC, HDC ASrcDC, const System::Types::TRect &ADestRect, const System::Types::TPoint &ASrcTopLeft, unsigned ROP);
extern DELPHI_PACKAGE void __fastcall cxBlendFunction(const tagRGBQUAD ASource, tagRGBQUAD &ADest, System::Byte ASourceConstantAlpha);
extern DELPHI_PACKAGE bool __fastcall cxColorIsValid(System::Uitypes::TColor AColor);
extern DELPHI_PACKAGE bool __fastcall cxColorIsEqual(const tagRGBQUAD AColor1, const tagRGBQUAD AColor2);
extern DELPHI_PACKAGE void __fastcall cxExchangeColors(System::Uitypes::TColor &AColor1, System::Uitypes::TColor &AColor2);
extern DELPHI_PACKAGE HRGN __fastcall cxCreateRegionFromBitmap(Vcl::Graphics::TBitmap* ABitmap, System::Uitypes::TColor ATransparentColor)/* overload */;
extern DELPHI_PACKAGE HRGN __fastcall cxCreateRegionFromBitmap(Winapi::Windows::PRGBQuad APixels, int AWidth, int AHeight, System::Uitypes::TColor ATransparentColor)/* overload */;
extern DELPHI_PACKAGE Vcl::Graphics::TBitmap* __fastcall cxCreateBitmap(const System::Types::TSize &ASize, Vcl::Graphics::TPixelFormat AFormat = (Vcl::Graphics::TPixelFormat)(0x6))/* overload */;
extern DELPHI_PACKAGE Vcl::Graphics::TBitmap* __fastcall cxCreateBitmap(const System::Types::TRect &ARect, Vcl::Graphics::TPixelFormat AFormat = (Vcl::Graphics::TPixelFormat)(0x6))/* overload */;
extern DELPHI_PACKAGE Vcl::Graphics::TBitmap* __fastcall cxCreateBitmap(int AWidth, int AHeight, Vcl::Graphics::TPixelFormat AFormat = (Vcl::Graphics::TPixelFormat)(0x6))/* overload */;
extern DELPHI_PACKAGE Vcl::Graphics::TBitmap* __fastcall cxCreateTrueColorBitmap(const System::Types::TSize &ASize)/* overload */;
extern DELPHI_PACKAGE Vcl::Graphics::TBitmap* __fastcall cxCreateTrueColorBitmap(int AWidth, int AHeight)/* overload */;
extern DELPHI_PACKAGE HBITMAP __fastcall cxCreateTrueColorBitmapHandle(int AWidth, int AHeight, int ABPP = 0x20);
extern DELPHI_PACKAGE void __fastcall cxDrawHatchRect(TcxCanvas* ACanvas, const System::Types::TRect &ARect, System::Uitypes::TColor AColor, bool ADrawShadow = true);
extern DELPHI_PACKAGE void __fastcall cxDrawDesignRect(TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool ASelected, bool ADrawShadow = true);
extern DELPHI_PACKAGE void __fastcall cxDrawBitmap(NativeUInt ADestDC, Vcl::Graphics::TBitmap* ASrcBitmap, const System::Types::TRect &ADestRect, const System::Types::TPoint &ASrcPoint, int AMode = 0xcc0020);
extern DELPHI_PACKAGE void __fastcall cxDrawImage(NativeUInt ADC, const System::Types::TRect &AGlyphRect, const System::Types::TRect &ABackgroundRect, Vcl::Graphics::TGraphic* AGlyph, Vcl::Imglist::TCustomImageList* AImages, int AImageIndex, Cxcustomcanvas::TcxImageDrawMode ADrawMode, bool ASmoothImage = false, NativeUInt ABrush = (NativeUInt)(0x0), System::Uitypes::TColor ATransparentColor = (System::Uitypes::TColor)(0x1fffffff), bool AUseLeftBottomPixelAsTransparent = true, Dxcoregraphics::_di_IdxColorPalette APalette = Dxcoregraphics::_di_IdxColorPalette())/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxGetImageRect(const System::Types::TRect &ADrawRect, const System::Types::TSize &AImageSize, TcxImageFitMode AFitMode, bool ACentre = true, int AScale = 0x64)/* overload */;
extern DELPHI_PACKAGE Cxgeometry::TdxRectF __fastcall cxGetImageRect(const Cxgeometry::TdxRectF &ADrawRect, const Cxgeometry::TdxSizeF &AImageSize, TcxImageFitMode AFitMode, bool ACentre = true, float AScale = 1.000000E+02f)/* overload */;
extern DELPHI_PACKAGE void __fastcall cxDrawImage(Cxcustomcanvas::TcxGdiBasedCanvas* ACanvas, const System::Types::TRect &ARect, Vcl::Graphics::TGraphic* AGlyph, Vcl::Imglist::TCustomImageList* AImages, int AImageIndex, TcxImageFitMode AFitMode, Cxcustomcanvas::TcxImageDrawMode ADrawMode = (Cxcustomcanvas::TcxImageDrawMode)(0x0), bool AUseLeftBottomPixelAsTransparent = true, Dxcoregraphics::_di_IdxColorPalette APalette = Dxcoregraphics::_di_IdxColorPalette(), Cxgeometry::TdxScaleFactor* AScaleFactor = (Cxgeometry::TdxScaleFactor*)(0x0), bool ASmoothImage = false)/* overload */;
extern DELPHI_PACKAGE void __fastcall cxDrawImage(Cxcustomcanvas::TcxGdiBasedCanvas* ACanvas, const System::Types::TRect &ARect, Vcl::Graphics::TGraphic* AGlyph, Vcl::Imglist::TCustomImageList* AImages, int AImageIndex, bool AEnabled, Dxcoregraphics::_di_IdxColorPalette APalette = Dxcoregraphics::_di_IdxColorPalette(), Cxgeometry::TdxScaleFactor* AScaleFactor = (Cxgeometry::TdxScaleFactor*)(0x0))/* overload */;
extern DELPHI_PACKAGE void __fastcall cxDrawPicture(TcxCanvas* ACanvas, const System::Types::TRect &ARect, Vcl::Graphics::TPicture* APicture, TcxImageFitMode AFitMode, Cxgeometry::TdxScaleFactor* AScaleFactor = (Cxgeometry::TdxScaleFactor*)(0x0));
extern DELPHI_PACKAGE void __fastcall cxDrawImage(Cxcustomcanvas::TcxGdiBasedCanvas* ACanvas, const System::Types::TRect &ARect, Vcl::Graphics::TGraphic* AImage, TcxImageFitMode AFitMode, Dxcoregraphics::_di_IdxColorPalette APalette = Dxcoregraphics::_di_IdxColorPalette(), Cxgeometry::TdxScaleFactor* AScaleFactor = (Cxgeometry::TdxScaleFactor*)(0x0), bool ASmoothResize = false)/* overload */;
extern DELPHI_PACKAGE void __fastcall cxDrawImageList(NativeUInt AImageListHandle, int AImageIndex, HDC ADC, const System::Types::TPoint &APoint, Vcl::Imglist::TDrawingStyle ADrawingStyle, Vcl::Imglist::TImageType AImageType);
extern DELPHI_PACKAGE void __fastcall cxDrawHatch(HDC ADC, const System::Types::TRect &ARect, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, System::Byte AStep, System::Byte AAlpha1 = (System::Byte)(0xff), System::Byte AAlpha2 = (System::Byte)(0xff));
extern DELPHI_PACKAGE void __fastcall cxDrawTransparencyCheckerboard(HDC DC, const System::Types::TRect &ARect, int ACellSize = 0x8)/* overload */;
extern DELPHI_PACKAGE void __fastcall cxDrawTransparencyCheckerboard(TcxCanvas* ACanvas, const System::Types::TRect &ARect, int ACellSize = 0x8)/* overload */;
extern DELPHI_PACKAGE void __fastcall cxTransformImage(Vcl::Graphics::TBitmap* ABitmap, TcxBitmapTransformationMode AMode)/* overload */;
extern DELPHI_PACKAGE void __fastcall cxTransformImage(Dxgdiplusclasses::TdxSmartImage* AImage, TcxBitmapTransformationMode AMode)/* overload */;
extern DELPHI_PACKAGE Vcl::Graphics::TBitmap* __fastcall cxGetAsBitmap(Vcl::Graphics::TGraphic* AGraphic);
extern DELPHI_PACKAGE TcxAlphaBitmap* __fastcall cxPrepareBitmapForDrawing(Vcl::Graphics::TGraphic* AGlyph, Vcl::Imglist::TCustomImageList* AImages, int AImageIndex, bool AUseLeftBottomPixelAsTransparent, System::Uitypes::TColor ATransparentColor, Dxcoregraphics::_di_IdxColorPalette APalette = Dxcoregraphics::_di_IdxColorPalette(), int AGlyphWidth = 0x0, int AGlyphHeight = 0x0)/* overload */;
extern DELPHI_PACKAGE TcxAlphaBitmap* __fastcall cxPrepareBitmapForDrawing(Vcl::Graphics::TGraphic* AGlyph, Vcl::Imglist::TCustomImageList* AImages, int AImageIndex, bool AUseLeftBottomPixelAsTransparent, System::Uitypes::TColor ATransparentColor, Dxcoregraphics::_di_IdxColorPalette APalette, int AGlyphWidth, int AGlyphHeight, bool ASmoothResize, /* out */ TcxAlphaBitmap* &AMaskBitmap, /* out */ bool &AIsAlphaUsed)/* overload */;
extern DELPHI_PACKAGE bool __fastcall cxSmoothDrawingNeeded(const System::Types::TRect &ADest, Vcl::Graphics::TGraphic* AGraphic, Cxgeometry::TdxScaleFactor* AScaleFactor);
extern DELPHI_PACKAGE void __fastcall cxSmoothResizeBitmap(Vcl::Graphics::TBitmap* ASource, Vcl::Graphics::TBitmap* ADestination, bool AForceUseLanczos3Filter = false);
extern DELPHI_PACKAGE void __fastcall cxStretchBlt(HDC ADestDC, HDC ASrcDC, const System::Types::TRect &ADestRect, const System::Types::TRect &ASrcRect, unsigned ROP);
extern DELPHI_PACKAGE void __fastcall cxStretchGraphic(Vcl::Graphics::TBitmap* ADestination, Vcl::Graphics::TGraphic* ASource, bool ASmoothStretch = false, Dxcoregraphics::_di_IdxColorPalette APalette = Dxcoregraphics::_di_IdxColorPalette())/* overload */;
extern DELPHI_PACKAGE void __fastcall cxStretchGraphic(Vcl::Graphics::TBitmap* ADestination, Vcl::Graphics::TGraphic* ASource, const System::Types::TRect &ADestRect, const System::Types::TRect &ASourceRect, bool ASmoothStretch = false, Dxcoregraphics::_di_IdxColorPalette APalette = Dxcoregraphics::_di_IdxColorPalette())/* overload */;
extern DELPHI_PACKAGE void __fastcall cxMakeColoredBitmap(Vcl::Graphics::TBitmap* ABitmap, System::Uitypes::TColor AColor);
extern DELPHI_PACKAGE void __fastcall cxMakeTrueColorBitmap(Vcl::Graphics::TBitmap* ASourceBitmap, Vcl::Graphics::TBitmap* ATrueColorBitmap);
extern DELPHI_PACKAGE void __fastcall cxMakeMaskBitmap(Vcl::Graphics::TBitmap* ASourceBitmap, Vcl::Graphics::TBitmap* AMaskBitmap);
extern DELPHI_PACKAGE System::Types::TSize __fastcall cxGetCursorSize(void);
extern DELPHI_PACKAGE void __fastcall cxAlphaBlend(Vcl::Graphics::TBitmap* ASource, const System::Types::TRect &ARect, const System::Uitypes::TColor ASelColor, System::Byte Alpha = (System::Byte)(0xaa))/* overload */;
extern DELPHI_PACKAGE void __fastcall cxAlphaBlend(Vcl::Graphics::TBitmap* ADest, Vcl::Graphics::TBitmap* ABkSource, Vcl::Graphics::TBitmap* ASource, System::Byte Alpha = (System::Byte)(0xc8))/* overload */;
extern DELPHI_PACKAGE void __fastcall cxApplyViewParams(TcxCanvas* ACanvas, const TcxViewParams &AViewParams);
extern DELPHI_PACKAGE void __fastcall cxCopyImage(Vcl::Graphics::TBitmap* ASource, Vcl::Graphics::TBitmap* ADest, const System::Types::TPoint &ASrcOffset, const System::Types::TPoint &ADstOffset, const System::Types::TRect &ARect)/* overload */;
extern DELPHI_PACKAGE void __fastcall cxCopyImage(Vcl::Graphics::TCanvas* ASource, Vcl::Graphics::TCanvas* ADest, const System::Types::TPoint &ASrcOffset, const System::Types::TPoint &ADstOffset, const System::Types::TRect &ARect)/* overload */;
extern DELPHI_PACKAGE HBITMAP __fastcall cxCopyImage(HBITMAP ASrcHandle)/* overload */;
extern DELPHI_PACKAGE void __fastcall cxClearBitmap(Vcl::Graphics::TBitmap* ABitmap);
extern DELPHI_PACKAGE void __fastcall cxFillHalfToneRect(Vcl::Graphics::TCanvas* Canvas, const System::Types::TRect &ARect, System::Uitypes::TColor ABkColor, System::Uitypes::TColor AColor);
extern DELPHI_PACKAGE void __fastcall cxFillRectWithCustomBrush(Vcl::Graphics::TCanvas* ACanvas, Vcl::Graphics::TBrush* ABrush, const System::Types::TRect &ARect, System::Uitypes::TColor ABkColor, System::Uitypes::TColor AColor, bool ATransparentBackground = false);
extern DELPHI_PACKAGE bool __fastcall cxGetTextExtentPoint32(NativeUInt ADC, const System::UnicodeString AText, /* out */ System::Types::TSize &ASize, int ACharCount = 0xffffffff);
extern DELPHI_PACKAGE void __fastcall cxGetTextLines(const System::UnicodeString AText, TcxCanvas* ACanvas, const System::Types::TRect &ARect, System::Classes::TStrings* ALines);
extern DELPHI_PACKAGE int __fastcall cxDrawText(NativeUInt ADC, const System::UnicodeString AText, System::Types::TRect &ARect, unsigned AFormat, int ACharCount = 0xffffffff, System::Uitypes::TColor ATextColor = (System::Uitypes::TColor)(0x20000000), int ABkMode = 0x1)/* overload */;
extern DELPHI_PACKAGE int __fastcall cxDrawText(Vcl::Graphics::TCanvas* ACanvas, const System::UnicodeString AText, const System::Types::TRect &ARect, unsigned AFormat, System::Uitypes::TColor ATextColor = (System::Uitypes::TColor)(0x20000000))/* overload */;
extern DELPHI_PACKAGE int __fastcall cxDrawText(TcxCanvas* ACanvas, const System::UnicodeString AText, const System::Types::TRect &ARect, unsigned AFormat, System::Uitypes::TColor ATextColor = (System::Uitypes::TColor)(0x20000000), Cxcustomcanvas::TcxRotationAngle ARotationAngle = (Cxcustomcanvas::TcxRotationAngle)(0x0))/* overload */;
extern DELPHI_PACKAGE int __fastcall cxDrawMultilineText(TcxCanvas* ACanvas, const System::UnicodeString AText, const System::Types::TRect &ARect, unsigned AFormat, System::Uitypes::TColor ATextColor = (System::Uitypes::TColor)(0x20000000))/* overload */;
extern DELPHI_PACKAGE int __fastcall cxDrawMultilineText(TcxCanvas* ACanvas, const System::UnicodeString AText, const System::Types::TRect &ARect, System::Classes::TAlignment ATextAlignHorz = (System::Classes::TAlignment)(0x0), Cxclasses::TcxAlignmentVert ATextAlignVert = (Cxclasses::TcxAlignmentVert)(0x0), System::Uitypes::TColor ATextColor = (System::Uitypes::TColor)(0x20000000))/* overload */;
extern DELPHI_PACKAGE bool __fastcall cxExtTextOut(NativeUInt ADC, const System::UnicodeString AText, const System::Types::TPoint &APoint, const System::Types::TRect &ARect, unsigned AOptions, int ACharCount = 0xffffffff)/* overload */;
extern DELPHI_PACKAGE bool __fastcall cxExtTextOut(NativeUInt ADC, const System::UnicodeString AText, const System::Types::TPoint &APoint, unsigned AOptions, int ACharCount = 0xffffffff)/* overload */;
extern DELPHI_PACKAGE int __fastcall cxTextHeight(NativeUInt ADC)/* overload */;
extern DELPHI_PACKAGE int __fastcall cxTextHeight(Vcl::Graphics::TFont* AFont)/* overload */;
extern DELPHI_PACKAGE int __fastcall cxTextHeight(Vcl::Graphics::TFont* AFont, const System::UnicodeString S, const System::Types::TRect &ARect, int AFlags)/* overload */;
extern DELPHI_PACKAGE System::Types::TSize __fastcall cxTextExtent(NativeUInt AFontHandle, const System::UnicodeString S)/* overload */;
extern DELPHI_PACKAGE int __fastcall cxTextHeight(Vcl::Graphics::TFont* AFont, const System::UnicodeString S, int AFontSize = 0x0)/* overload */;
extern DELPHI_PACKAGE int __fastcall cxTextWidth(Vcl::Graphics::TFont* AFont, const System::UnicodeString S, int AFontSize = 0x0);
extern DELPHI_PACKAGE System::Types::TSize __fastcall cxTextExtent(Vcl::Graphics::TFont* AFont, const System::UnicodeString S, int AFontSize = 0x0)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxGetTextRect(NativeUInt ADC, const System::UnicodeString AText, int ARowCount, bool AReturnMaxRectHeight = false, int ADTFlags = 0x0)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxGetTextRect(Vcl::Graphics::TFont* AFont, const System::UnicodeString AText, int ARowCount, bool AConsiderLineBreaks = false)/* overload */;
extern DELPHI_PACKAGE void __fastcall cxGetTextRect(System::Types::TRect &ARect, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, int ADTFlags)/* overload */;
extern DELPHI_PACKAGE System::Types::TSize __fastcall cxTextSize(NativeUInt ADC, const System::UnicodeString AText)/* overload */;
extern DELPHI_PACKAGE System::Types::TSize __fastcall cxTextSize(Vcl::Graphics::TFont* AFont, const System::UnicodeString AText, int AFlags = 0x0)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall cxGetStringAdjustedToWidth(HDC ADC, HFONT AFontHandle, const System::UnicodeString S, int AWidth, Dxcoregraphics::TcxModifyStringType AModifyStringType = (Dxcoregraphics::TcxModifyStringType)(0x0))/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall cxGetStringAdjustedToWidth(Vcl::Graphics::TFont* AFont, const System::UnicodeString S, int AWidth, Dxcoregraphics::TcxModifyStringType AModifyStringType = (Dxcoregraphics::TcxModifyStringType)(0x0))/* overload */;
extern DELPHI_PACKAGE bool __fastcall cxCompareBitmaps(Vcl::Graphics::TBitmap* ABitmap1, Vcl::Graphics::TBitmap* ABitmap2);
extern DELPHI_PACKAGE bool __fastcall cxCompareGraphics(Vcl::Graphics::TGraphic* AGraphic1, Vcl::Graphics::TGraphic* AGraphic2);
extern DELPHI_PACKAGE bool __fastcall cxGetBitmapData(HBITMAP ABitmapHandle, /* out */ tagBITMAP &ABitmapData);
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxGetImageClientRect(Vcl::Graphics::TGraphic* AImage);
extern DELPHI_PACKAGE bool __fastcall cxGetBrushData(HBRUSH ABrushHandle, /* out */ tagLOGBRUSH &ALogBrush)/* overload */;
extern DELPHI_PACKAGE tagLOGBRUSH __fastcall cxGetBrushData(HBRUSH ABrushHandle)/* overload */;
extern DELPHI_PACKAGE bool __fastcall cxGetFontData(HFONT AFontHandle, /* out */ tagLOGFONTW &ALogFont);
extern DELPHI_PACKAGE bool __fastcall cxGetPenData(HPEN APenHandle, /* out */ tagLOGPEN &ALogPen);
extern DELPHI_PACKAGE bool __fastcall cxGetTextMetrics(Vcl::Graphics::TFont* AFont, /* out */ tagTEXTMETRICW &ATextMetric);
extern DELPHI_PACKAGE void __fastcall cxInitLogFont(tagLOGFONTW &ALogFont, const System::UnicodeString AFontName);
extern DELPHI_PACKAGE Vcl::Graphics::TCanvasOrientation __fastcall cxGetWritingDirection(System::Uitypes::TFontCharset AFontCharset, const System::UnicodeString AText);
extern DELPHI_PACKAGE void __fastcall cxDrawThemeParentBackground(Vcl::Controls::TWinControl* AControl, TcxCanvas* ACanvas, const System::Types::TRect &ARect)/* overload */;
extern DELPHI_PACKAGE void __fastcall cxDrawThemeParentBackground(Vcl::Controls::TWinControl* AControl, Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect)/* overload */;
extern DELPHI_PACKAGE void __fastcall cxPaintControlTo(Vcl::Controls::TWinControl* ADrawingControl, TcxCanvas* ACanvas, const System::Types::TPoint &ADestinationPoint, const System::Types::TRect &ADrawingRect, bool ADrawParentWithChildren, bool ADrawNC, bool AConsiderWindowRegion = true, bool ACheckVisibility = true);
extern DELPHI_PACKAGE void __fastcall cxDrawTransparentControlBackground(Vcl::Controls::TWinControl* AControl, TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool APaintParentWithChildren = true)/* overload */;
extern DELPHI_PACKAGE void __fastcall cxDrawTransparentControlBackground(Vcl::Controls::TWinControl* AControl, Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, bool APaintParentWithChildren = true)/* overload */;
extern DELPHI_PACKAGE void __fastcall cxDrawTransparentControlBackground(Vcl::Controls::TWinControl* AControl, TcxCanvas* ACanvas, const System::Types::TRect &ASourceRect, const System::Types::TPoint &ADestinationPoint, bool APaintParentWithChildren = true)/* overload */;
extern DELPHI_PACKAGE bool __fastcall cxIsTransparentBackgroundDrawing(Vcl::Controls::TWinControl* ABackgroundControl);
extern DELPHI_PACKAGE void __fastcall cxRightToLeftDependentDraw(TcxCanvas* ACanvas, const System::Types::TRect &R, System::Sysutils::_di_TProc AProc)/* overload */;
extern DELPHI_PACKAGE void __fastcall cxRightToLeftDependentDraw(HDC DC, const System::Types::TRect &R, bool AIsRightToLeftLayout, System::Sysutils::_di_TProc AProc, bool ACorrectNeeded = true)/* overload */;
extern DELPHI_PACKAGE void __fastcall cxPaintTo(Vcl::Controls::TWinControl* ASourceControl, TcxCanvas* ADestinationCanvas, const System::Types::TPoint &ADestinationPoint, const System::Types::TRect &ASourceRect, System::Classes::TList* ASkipList = (System::Classes::TList*)(0x0));
extern DELPHI_PACKAGE void __fastcall cxPaintToBitmap(Vcl::Controls::TWinControl* AControl, TcxBitmap* ABitmap, bool ADrawNCArea = false);
extern DELPHI_PACKAGE void __fastcall cxResetFont(Vcl::Graphics::TFont* AFont, Cxgeometry::TdxScaleFactor* AScaleFactor);
extern DELPHI_PACKAGE TcxScreenCanvas* __fastcall cxScreenCanvas(void);
extern DELPHI_PACKAGE TcxCanvas* __fastcall cxMeasureCanvas(void);
extern DELPHI_PACKAGE TcxPaintCanvas* __fastcall cxPaintCanvas(void);
extern DELPHI_PACKAGE bool __fastcall cxPtInRegion(HRGN ARegionHandle, const int X, const int Y)/* overload */;
extern DELPHI_PACKAGE bool __fastcall cxPtInRegion(HRGN ARegionHandle, const System::Types::TPoint &P)/* overload */;
extern DELPHI_PACKAGE void __fastcall cxTransformImages(TcxImageList* AImageList, System::Uitypes::TColor ABkColor, bool AEnabled = true)/* overload */;
extern DELPHI_PACKAGE void __fastcall cxTransformImages(TcxImageList* ASourceImageList, TcxImageList* ADestinationImageList, System::Uitypes::TColor ABkColor, bool AEnabled = true)/* overload */;
extern DELPHI_PACKAGE void __fastcall cxAdvancedDrawPopupMenuItem(Vcl::Menus::TMenuItem* AMenuItem, Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, Winapi::Windows::TOwnerDrawState AState, Vcl::Imglist::TCustomImageList* AExternalImages = (Vcl::Imglist::TCustomImageList*)(0x0))/* overload */;
extern DELPHI_PACKAGE void __fastcall cxAdvancedDrawPopupMenuItem(Vcl::Menus::TMenuItem* AMenuItem, TcxCanvas* ACanvas, const System::Types::TRect &ARect, Winapi::Windows::TOwnerDrawState AState, Vcl::Imglist::TCustomImageList* AExternalImages = (Vcl::Imglist::TCustomImageList*)(0x0))/* overload */;
extern DELPHI_PACKAGE void __fastcall dxSetFontAsNonAntialiased(Vcl::Graphics::TFont* AFont);
extern DELPHI_PACKAGE void __fastcall dxSetZoomFactor(TcxCanvas* ACanvas, int AZoomFactor, tagXFORM &APrevTransform);
extern DELPHI_PACKAGE bool __fastcall dxPictureToImage(Vcl::Graphics::TPicture* APicture, const System::Types::TSize &ASize, TcxImageFitMode AMode, Dxgdiplusclasses::TdxSmartImage* &AImage);
extern DELPHI_PACKAGE Dxgdiplusclasses::TdxSmartImage* __fastcall dxImageFrameToGraphic(Dxgdiplusclasses::TdxSmartImage* ASource, int AFrameIndex, Dxsmartimage::TdxImageDataFormat AImageDataFormat = (Dxsmartimage::TdxImageDataFormat)(0x4));
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectExcludeBorders(const System::Types::TRect &ABounds, const System::Types::TRect &ABordersWidth, Cxgeometry::TcxBorders ABorders)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxRectExcludeBorders(const System::Types::TRect &ABounds, int ABorderWidth, const Cxgeometry::TcxBorders ABorders)/* overload */;
extern DELPHI_PACKAGE Dxgdiplusclasses::TdxSmartImage* __fastcall dxCreateMultiFrameTIFF(int AFrameCount, const System::Types::TSize &ASize, TcxImageFitMode AMode, TdxGetImageFrameProc AProc);
extern DELPHI_PACKAGE System::UnicodeString __fastcall cxGraphicExtension(Vcl::Graphics::TGraphic* AGraphic)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall cxGraphicExtension(Vcl::Graphics::TGraphicClass AGraphicClass)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall cxGraphicFileMask(Vcl::Graphics::TGraphicClass AGraphicClass);
extern DELPHI_PACKAGE System::UnicodeString __fastcall cxGraphicFilter(Vcl::Graphics::TGraphic* AGraphic, bool AForExport = false)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall cxGraphicFilter(Vcl::Graphics::TGraphicClass AGraphicClass)/* overload */;
extern DELPHI_PACKAGE void __fastcall cxGraphicDormant(Vcl::Graphics::TGraphic* AGraphic);
}	/* namespace Cxgraphics */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXGRAPHICS)
using namespace Cxgraphics;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxgraphicsHPP
