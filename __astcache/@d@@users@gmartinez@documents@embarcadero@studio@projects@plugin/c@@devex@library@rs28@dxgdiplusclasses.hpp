// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxGDIPlusClasses.pas' rev: 35.00 (Windows)

#ifndef DxgdiplusclassesHPP
#define DxgdiplusclassesHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.Windows.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <System.SyncObjs.hpp>
#include <Vcl.Graphics.hpp>
#include <Winapi.ActiveX.hpp>
#include <System.Types.hpp>
#include <Vcl.Clipbrd.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <System.UITypes.hpp>
#include <System.Generics.Collections.hpp>
#include <System.Generics.Defaults.hpp>
#include <dxCore.hpp>
#include <dxCoreGraphics.hpp>
#include <dxDPIAwareUtils.hpp>
#include <cxGeometry.hpp>
#include <dxGDIPlusAPI.hpp>
#include <dxCoreClasses.hpp>
#include <System.Contnrs.hpp>
#include <dxSmartImage.hpp>

//-- user supplied -----------------------------------------------------------

namespace Dxgdiplusclasses
{
//-- forward type declarations -----------------------------------------------
__interface DELPHIINTERFACE IdxGPHandle;
typedef System::DelphiInterface<IdxGPHandle> _di_IdxGPHandle;
class DELPHICLASS TdxGPCustomGraphicObject;
class DELPHICLASS TdxGPMatrix;
class DELPHICLASS TdxGPBrushGradientPoints;
class DELPHICLASS TdxGPCustomBrush;
class DELPHICLASS TdxGPHatchBrush;
class DELPHICLASS TdxGPBrush;
class DELPHICLASS TdxGPPen;
class DELPHICLASS TdxGPPath;
class DELPHICLASS TdxGPRegion;
class DELPHICLASS TdxGPMemoryStream;
class DELPHICLASS TdxGPStringFormat;
class DELPHICLASS TdxGPFontFamily;
class DELPHICLASS TdxGPFontCollection;
class DELPHICLASS TdxGPInstalledFontCollection;
class DELPHICLASS TdxGPPrivateFontCollection;
class DELPHICLASS TdxGPFont;
class DELPHICLASS TdxGPCanvas;
class DELPHICLASS TdxGPGraphics;
class DELPHICLASS TdxGPCustomPaintCanvas;
class DELPHICLASS TdxGPPaintCanvas;
class DELPHICLASS TdxGPStreamAdapter;
__interface DELPHIINTERFACE IdxGPGraphicDraw;
typedef System::DelphiInterface<IdxGPGraphicDraw> _di_IdxGPGraphicDraw;
__interface DELPHIINTERFACE IdxGpFlipContent;
typedef System::DelphiInterface<IdxGpFlipContent> _di_IdxGpFlipContent;
class DELPHICLASS TdxGPImageHandle;
class DELPHICLASS TdxGPImageCodec;
class DELPHICLASS TdxGPImageCodecBMP;
class DELPHICLASS TdxGPImageCodecGIF;
class DELPHICLASS TdxGPImageCodecJPEG;
class DELPHICLASS TdxGPImageCodecPNG;
class DELPHICLASS TdxGPImageCodecTIFF;
class DELPHICLASS TdxGPImageCodecEMF;
class DELPHICLASS TdxGPImageCodecWMF;
class DELPHICLASS TdxGPImageAttributes;
class DELPHICLASS TdxGPImage;
class DELPHICLASS TdxSmartImage;
class DELPHICLASS TdxSmartGlyph;
class DELPHICLASS TdxPNGImage;
class DELPHICLASS TdxJPEGImage;
class DELPHICLASS TdxGIFImage;
class DELPHICLASS TdxTIFFImage;
class DELPHICLASS TdxBMPImage;
class DELPHICLASS TdxGpFastDIB;
//-- type declarations -------------------------------------------------------
using Dxsmartimage::TdxImageDataFormat;

enum DECLSPEC_DENUM TdxGpCompositionMode : unsigned char { cmSourceOver, cmSourceCopy };

enum DECLSPEC_DENUM TdxGPInterpolationMode : unsigned char { imDefault, imLowQuality, imHighQuality, imBilinear, imBicubic, imNearestNeighbor, imHighQualityBilinear, imHighQualityBicubic };

enum DECLSPEC_DENUM TdxGPSmoothingMode : unsigned char { smDefault, smHighSpeed, smHighQuality, smNone, smAntiAlias };

typedef System::DynamicArray<System::Byte> TdxGPImagePropertyData;

__interface  INTERFACE_UUID("{329D311E-2864-4E9F-93E7-5556D7E264AC}") IdxGPHandle  : public System::IInterface 
{
	virtual void * __fastcall GetNativeHandle() = 0 ;
};

typedef System::TMetaClass* TdxGPCustomGraphicObjectClass;

class PASCALIMPLEMENTATION TdxGPCustomGraphicObject : public Dxgdiplusapi::TdxGpBase
{
	typedef Dxgdiplusapi::TdxGpBase inherited;
	
private:
	int FChangeLockCount;
	void *FHandle;
	System::Classes::TNotifyEvent FOnChange;
	void * __fastcall GetHandle();
	bool __fastcall GetHandleAllocated();
	
protected:
	virtual void __fastcall Changed();
	virtual void __fastcall DoCreateHandle(/* out */ void * &AHandle) = 0 ;
	virtual void __fastcall DoFreeHandle(void * AHandle) = 0 ;
	virtual void __fastcall DoHandleCreated();
	
public:
	__fastcall virtual TdxGPCustomGraphicObject()/* overload */;
	virtual void __fastcall Assign(TdxGPCustomGraphicObject* ASource);
	virtual void __fastcall BeforeDestruction();
	TdxGPCustomGraphicObject* __fastcall Clone();
	void __fastcall FreeHandle();
	virtual void __fastcall HandleNeeded();
	__property void * Handle = {read=GetHandle};
	__property bool HandleAllocated = {read=GetHandleAllocated, nodefault};
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxGPCustomGraphicObject() { }
	
};


class PASCALIMPLEMENTATION TdxGPMatrix : public TdxGPCustomGraphicObject
{
	typedef TdxGPCustomGraphicObject inherited;
	
private:
	bool __fastcall GetIsIdentity();
	bool __fastcall GetIsInvertible();
	float __fastcall GetOffsetX();
	float __fastcall GetOffsetY();
	
protected:
	virtual void __fastcall DoCreateHandle(/* out */ void * &AHandle);
	virtual void __fastcall DoFreeHandle(void * AHandle);
	
public:
	__fastcall TdxGPMatrix(const tagXFORM &XForm)/* overload */;
	__fastcall TdxGPMatrix(float M11, float M12, float M21, float M22, float DX, float DY)/* overload */;
	__fastcall TdxGPMatrix(bool AFlipHorizontally, bool AFlipVertically, const float APivotPointX, const float APivotPointY)/* overload */;
	__fastcall TdxGPMatrix(bool AFlipHorizontally, bool AFlipVertically, const Cxgeometry::TdxPointF &APivotPoint)/* overload */;
	virtual void __fastcall Assign(TdxGPCustomGraphicObject* ASource);
	HIDESBASE TdxGPMatrix* __fastcall Clone();
	void __fastcall GetElements(/* out */ float &M11, /* out */ float &M12, /* out */ float &M21, /* out */ float &M22, /* out */ float &DX, /* out */ float &DY);
	void __fastcall SetElements(const float M11, const float M12, const float M21, const float M22, const float DX, const float DY)/* overload */;
	void __fastcall SetElements(const tagXFORM &XForm)/* overload */;
	void __fastcall Flip(bool AFlipHorizontally, bool AFlipVertically, const Cxgeometry::TdxPointF &APivotPoint);
	void __fastcall Invert()/* overload */;
	__classmethod tagXFORM __fastcall Invert(const tagXFORM &AForm)/* overload */;
	Cxgeometry::TdxRectF __fastcall GetBoundingRectangle(const Cxgeometry::TdxRectF &R);
	void __fastcall Multiply(const tagXFORM &XForm, Dxgdiplusapi::TdxGpMatrixOrder AMatrixOrder = (Dxgdiplusapi::TdxGpMatrixOrder)(0x0))/* overload */;
	void __fastcall Multiply(TdxGPMatrix* AMatrix, Dxgdiplusapi::TdxGpMatrixOrder AMatrixOrder = (Dxgdiplusapi::TdxGpMatrixOrder)(0x0))/* overload */;
	void __fastcall Reset();
	void __fastcall Rotate(float AAngle, Dxgdiplusapi::TdxGpMatrixOrder AMatrixOrder = (Dxgdiplusapi::TdxGpMatrixOrder)(0x0))/* overload */;
	void __fastcall Rotate(float AAngle, const Cxgeometry::TdxPointF &APivotPoint, Dxgdiplusapi::TdxGpMatrixOrder AMatrixOrder = (Dxgdiplusapi::TdxGpMatrixOrder)(0x0))/* overload */;
	void __fastcall Scale(const Cxgeometry::TdxPointF &AScale, Dxgdiplusapi::TdxGpMatrixOrder AMatrixOrder = (Dxgdiplusapi::TdxGpMatrixOrder)(0x0))/* overload */;
	void __fastcall Scale(const Cxgeometry::TdxPointF &AScale, const Cxgeometry::TdxPointF &ACenter, Dxgdiplusapi::TdxGpMatrixOrder AMatrixOrder = (Dxgdiplusapi::TdxGpMatrixOrder)(0x0))/* overload */;
	void __fastcall Scale(const float AScale, Dxgdiplusapi::TdxGpMatrixOrder AMatrixOrder = (Dxgdiplusapi::TdxGpMatrixOrder)(0x0))/* overload */;
	void __fastcall Scale(const float AScaleX, const float AScaleY, Dxgdiplusapi::TdxGpMatrixOrder AMatrixOrder = (Dxgdiplusapi::TdxGpMatrixOrder)(0x0))/* overload */;
	void __fastcall Shear(const Cxgeometry::TdxPointF &AShear, Dxgdiplusapi::TdxGpMatrixOrder AMatrixOrder = (Dxgdiplusapi::TdxGpMatrixOrder)(0x0))/* overload */;
	void __fastcall Shear(const float AShearX, const float AShearY, Dxgdiplusapi::TdxGpMatrixOrder AMatrixOrder = (Dxgdiplusapi::TdxGpMatrixOrder)(0x0))/* overload */;
	tagXFORM __fastcall ToXForm();
	void __fastcall Translate(const Cxgeometry::TdxPointF &AOffset, Dxgdiplusapi::TdxGpMatrixOrder AMatrixOrder = (Dxgdiplusapi::TdxGpMatrixOrder)(0x0))/* overload */;
	void __fastcall Translate(const float AOffsetX, const float AOffsetY, Dxgdiplusapi::TdxGpMatrixOrder AMatrixOrder = (Dxgdiplusapi::TdxGpMatrixOrder)(0x0))/* overload */;
	Cxgeometry::TdxPointF __fastcall TransformPoint(const Cxgeometry::TdxPointF &P)/* overload */;
	System::Types::TPoint __fastcall TransformPoint(const System::Types::TPoint &P)/* overload */;
	void __fastcall TransformPoints(System::DynamicArray<System::Types::TPoint> &APoints)/* overload */;
	void __fastcall TransformPoints(System::DynamicArray<Cxgeometry::TdxPointF> &APoints)/* overload */;
	void __fastcall TransformPointsI(System::Types::PPoint APoints, int ACount)/* overload */;
	Cxgeometry::TdxRectF __fastcall TransformRect(const Cxgeometry::TdxRectF &R)/* overload */;
	System::Types::TRect __fastcall TransformRect(const System::Types::TRect &R)/* overload */;
	__property bool IsIdentity = {read=GetIsIdentity, nodefault};
	__property bool IsInvertible = {read=GetIsInvertible, nodefault};
	__property float OffsetX = {read=GetOffsetX};
	__property float OffsetY = {read=GetOffsetY};
public:
	/* TdxGPCustomGraphicObject.Create */ inline __fastcall virtual TdxGPMatrix()/* overload */ : TdxGPCustomGraphicObject() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxGPMatrix() { }
	
};


class PASCALIMPLEMENTATION TdxGPBrushGradientPoints : public Dxgdiplusapi::TdxGpBase
{
	typedef Dxgdiplusapi::TdxGpBase inherited;
	
	
private:
	typedef System::DynamicArray<float> _TdxGPBrushGradientPoints__1;
	
	
private:
	int FCapacity;
	Dxcoregraphics::TdxAlphaColorDynArray FColors;
	int FCount;
	_TdxGPBrushGradientPoints__1 FOffsets;
	System::Classes::TNotifyEvent FOnChange;
	void __fastcall CheckIndex(int Index);
	void __fastcall Grow();
	Dxcoregraphics::TdxAlphaColor __fastcall GetColor(int Index);
	float __fastcall GetOffset(int Index);
	int __fastcall InternalAdd(float AOffset, Dxcoregraphics::TdxAlphaColor AColor);
	void __fastcall SetCapacity(int AValue);
	void __fastcall SetColor(int Index, const Dxcoregraphics::TdxAlphaColor AValue);
	void __fastcall SetOffset(int Index, const float AValue);
	
protected:
	void __fastcall CalculateParams(/* out */ Dxcoregraphics::PdxAlphaColor &AColors, /* out */ Winapi::Windows::PSingle &AOffsets, /* out */ int &ACount);
	void __fastcall Changed();
	void __fastcall ValidateOrder();
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	
public:
	__fastcall virtual TdxGPBrushGradientPoints();
	int __fastcall Add(float AOffset, Dxcoregraphics::TdxAlphaColor AColor);
	void __fastcall Assign(TdxGPBrushGradientPoints* Source);
	void __fastcall Clear();
	void __fastcall Delete(int Index);
	void __fastcall InvertOrder();
	__property int Capacity = {read=FCapacity, write=SetCapacity, nodefault};
	__property Dxcoregraphics::TdxAlphaColor Colors[int Index] = {read=GetColor, write=SetColor};
	__property int Count = {read=FCount, nodefault};
	__property float Offsets[int Index] = {read=GetOffset, write=SetOffset};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxGPBrushGradientPoints() { }
	
};


class PASCALIMPLEMENTATION TdxGPCustomBrush : public TdxGPCustomGraphicObject
{
	typedef TdxGPCustomGraphicObject inherited;
	
protected:
	Dxgdiplusapi::TdxGpRectF FTargetRect;
	virtual void __fastcall DoFreeHandle(void * AHandle);
	virtual void __fastcall DoTargetRectChanged();
	virtual bool __fastcall GetIsEmpty();
	virtual bool __fastcall NeedRecreateHandleOnTargetRectChange();
	
public:
	virtual void __fastcall Assign(TdxGPCustomGraphicObject* ASource);
	void __fastcall SetTargetRect(const System::Types::TRect &R)/* overload */;
	void __fastcall SetTargetRect(const Cxgeometry::TdxRectF &R)/* overload */;
	void __fastcall SetTargetRect(const Dxgdiplusapi::TdxGpRect &R)/* overload */;
	void __fastcall SetTargetRect(const Dxgdiplusapi::TdxGpRectF &R)/* overload */;
	__property bool IsEmpty = {read=GetIsEmpty, nodefault};
	__property Dxgdiplusapi::TdxGpRectF TargetRect = {read=FTargetRect};
public:
	/* TdxGPCustomGraphicObject.Create */ inline __fastcall virtual TdxGPCustomBrush()/* overload */ : TdxGPCustomGraphicObject() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxGPCustomBrush() { }
	
};


class PASCALIMPLEMENTATION TdxGPHatchBrush : public TdxGPCustomBrush
{
	typedef TdxGPCustomBrush inherited;
	
private:
	Dxcoregraphics::TdxAlphaColor FBackgroundColor;
	Dxcoregraphics::TdxAlphaColor FForegroundColor;
	Dxgdiplusapi::HatchStyle FStyle;
	void __fastcall SetBackgroundColor(const Dxcoregraphics::TdxAlphaColor AValue);
	void __fastcall SetForegroundColor(const Dxcoregraphics::TdxAlphaColor AValue);
	void __fastcall SetStyle(const Dxgdiplusapi::HatchStyle AValue);
	
protected:
	virtual void __fastcall Changed();
	virtual void __fastcall DoCreateHandle(/* out */ void * &AHandle);
	virtual bool __fastcall GetIsEmpty();
	
public:
	__fastcall TdxGPHatchBrush(Dxcoregraphics::TdxAlphaColor ABackgroundColor, Dxcoregraphics::TdxAlphaColor AForegroundColor, Dxgdiplusapi::HatchStyle AStyle)/* overload */;
	virtual void __fastcall Assign(TdxGPCustomGraphicObject* ASource);
	__property Dxcoregraphics::TdxAlphaColor BackgroundColor = {read=FBackgroundColor, write=SetBackgroundColor, nodefault};
	__property Dxcoregraphics::TdxAlphaColor ForegroundColor = {read=FForegroundColor, write=SetForegroundColor, nodefault};
	__property Dxgdiplusapi::HatchStyle Style = {read=FStyle, write=SetStyle, nodefault};
public:
	/* TdxGPCustomGraphicObject.Create */ inline __fastcall virtual TdxGPHatchBrush()/* overload */ : TdxGPCustomBrush() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxGPHatchBrush() { }
	
};


enum DECLSPEC_DENUM TdxGPBrushGradientMode : unsigned char { gpbgmHorizontal, gpbgmVertical, gpbgmForwardDiagonal, gpbgmBackwardDiagonal };

enum DECLSPEC_DENUM TdxGPBrushStyle : unsigned char { gpbsSolid, gpbsGradient, gpbsTexture, gpbsClear };

class PASCALIMPLEMENTATION TdxGPBrush : public TdxGPCustomBrush
{
	typedef TdxGPCustomBrush inherited;
	
private:
	Dxcoregraphics::TdxAlphaColor FColor;
	TdxGPBrushGradientMode FGradientMode;
	TdxGPBrushGradientPoints* FGradientPoints;
	TdxGPBrushStyle FStyle;
	TdxGPImage* FTexture;
	TdxGPMatrix* FTextureTransform;
	void __fastcall ApplyTextureTransform();
	void __fastcall GradientSettingsChanged(System::TObject* Sender = (System::TObject*)(0x0));
	void __fastcall SetColor(const Dxcoregraphics::TdxAlphaColor AValue);
	void __fastcall SetGradientMode(const TdxGPBrushGradientMode AValue);
	void __fastcall SetGradientPoints(TdxGPBrushGradientPoints* const AValue);
	void __fastcall SetStyle(const TdxGPBrushStyle AValue);
	void __fastcall SetTexture(TdxGPImage* const AValue);
	void __fastcall SetTextureTransform(TdxGPMatrix* const AValue);
	void __fastcall TextureChangeHandler(System::TObject* Sender);
	
protected:
	System::Classes::TNotifyEvent FOnHandleCreated;
	virtual void __fastcall CreateGradientBrushHandle(/* out */ void * &AHandle);
	virtual void __fastcall CreateSolidBrushHandle(/* out */ void * &AHandle, Dxcoregraphics::TdxAlphaColor AColor);
	virtual void __fastcall CreateTextureBrushHandle(/* out */ void * &AHandle);
	virtual void __fastcall DoCreateHandle(/* out */ void * &AHandle);
	virtual void __fastcall DoHandleCreated();
	virtual void __fastcall DoTargetRectChanged();
	virtual bool __fastcall GetIsEmpty();
	virtual bool __fastcall NeedRecreateHandleOnTargetRectChange();
	
public:
	__fastcall virtual TdxGPBrush()/* overload */;
	__fastcall virtual ~TdxGPBrush();
	virtual void __fastcall Assign(TdxGPCustomGraphicObject* ASource);
	__property Dxcoregraphics::TdxAlphaColor Color = {read=FColor, write=SetColor, nodefault};
	__property TdxGPBrushGradientMode GradientMode = {read=FGradientMode, write=SetGradientMode, nodefault};
	__property TdxGPBrushGradientPoints* GradientPoints = {read=FGradientPoints, write=SetGradientPoints};
	__property TdxGPBrushStyle Style = {read=FStyle, write=SetStyle, nodefault};
	__property TdxGPImage* Texture = {read=FTexture, write=SetTexture};
	__property TdxGPMatrix* TextureTransform = {read=FTextureTransform, write=SetTextureTransform};
};


enum DECLSPEC_DENUM TdxGPPenDashCapStyle : unsigned char { gpdcFlat, gpdcRound, gpdcTriangle };

enum DECLSPEC_DENUM TdxGPPenLineCapStyle : unsigned char { gpcsFlat, gpcsSquare, gpcsRound };

enum DECLSPEC_DENUM TdxGPPenStyle : unsigned char { gppsSolid, gppsDash, gppsDot, gppsDashDot, gppsDashDotDot };

class PASCALIMPLEMENTATION TdxGPPen : public TdxGPCustomGraphicObject
{
	typedef TdxGPCustomGraphicObject inherited;
	
private:
	TdxGPBrush* FBrush;
	TdxGPPenDashCapStyle FDashCapStyle;
	TdxGPPenLineCapStyle FLineEndCapStyle;
	Dxgdiplusapi::TdxGpLineJoin FLineJoin;
	TdxGPPenLineCapStyle FLineStartCapStyle;
	float FMiterLimit;
	TdxGPPenStyle FStyle;
	float FWidth;
	void __fastcall BrushChangeHandler(System::TObject* Sender);
	void __fastcall BrushCreatedHandler(System::TObject* Sender);
	void __fastcall SetBrush(TdxGPBrush* const AValue);
	void __fastcall SetDashCapStyle(const TdxGPPenDashCapStyle AValue);
	void __fastcall SetLineEndCapStyle(const TdxGPPenLineCapStyle AValue);
	void __fastcall SetLineJoin(const Dxgdiplusapi::TdxGpLineJoin AValue);
	void __fastcall SetLineStartCapStyle(const TdxGPPenLineCapStyle AValue);
	void __fastcall SetMiterLimit(const float AValue);
	void __fastcall SetStyle(const TdxGPPenStyle AValue);
	void __fastcall SetWidth(float AValue);
	
protected:
	virtual TdxGPBrush* __fastcall CreateBrush();
	virtual void __fastcall DoCreateHandle(/* out */ void * &AHandle);
	virtual void __fastcall DoFreeHandle(void * AHandle);
	void __fastcall DoSetDashStyle(void * AHandle);
	void __fastcall DoSetDashCapStyle(void * AHandle);
	void __fastcall DoSetLineEndCapStyle(void * AHandle);
	void __fastcall DoSetLineJoin(void * AHandle);
	void __fastcall DoSetLineStartCapStyle(void * AHandle);
	void __fastcall DoSetMiterLimit(void * AHandle);
	virtual bool __fastcall GetIsEmpty();
	void __fastcall InitializePenPattern(Vcl::Graphics::TPenStyle APenStyle, float AScale);
	void __fastcall SetDashArray(const float *AValue, const int AValue_High, float AScale)/* overload */;
	
public:
	__fastcall virtual TdxGPPen()/* overload */;
	__fastcall TdxGPPen(Dxcoregraphics::TdxAlphaColor AColor, float AWidth, Vcl::Graphics::TPenStyle APenStyle, float AScale)/* overload */;
	__fastcall virtual ~TdxGPPen();
	virtual void __fastcall Assign(TdxGPCustomGraphicObject* ASource);
	virtual void __fastcall HandleNeeded();
	void __fastcall SetDashArray(const float *AValue, const int AValue_High)/* overload */;
	void __fastcall SetTargetRect(const Dxgdiplusapi::TdxGpRect &R)/* overload */;
	void __fastcall SetTargetRect(const System::Types::TRect &R)/* overload */;
	void __fastcall SetTargetRect(const Cxgeometry::TdxRectF &R)/* overload */;
	__property TdxGPBrush* Brush = {read=FBrush, write=SetBrush};
	__property TdxGPPenStyle Style = {read=FStyle, write=SetStyle, nodefault};
	__property float Width = {read=FWidth, write=SetWidth};
	__property TdxGPPenDashCapStyle DashCapStyle = {read=FDashCapStyle, write=SetDashCapStyle, nodefault};
	__property TdxGPPenLineCapStyle LineEndCapStyle = {read=FLineEndCapStyle, write=SetLineEndCapStyle, nodefault};
	__property Dxgdiplusapi::TdxGpLineJoin LineJoin = {read=FLineJoin, write=SetLineJoin, nodefault};
	__property TdxGPPenLineCapStyle LineStartCapStyle = {read=FLineStartCapStyle, write=SetLineStartCapStyle, nodefault};
	__property float MiterLimit = {read=FMiterLimit, write=SetMiterLimit};
	__property bool IsEmpty = {read=GetIsEmpty, nodefault};
};


enum DECLSPEC_DENUM TdxGPFillMode : unsigned char { gpfmAlternate, gpfmWinding };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGPPath : public Dxgdiplusapi::TdxGpBase
{
	typedef Dxgdiplusapi::TdxGpBase inherited;
	
private:
	void *FHandle;
	TdxGPFillMode __fastcall GetFillMode();
	void * __fastcall GetPenHandle(TdxGPPen* APen);
	void __fastcall SetFillMode(TdxGPFillMode AValue);
	
public:
	__fastcall virtual TdxGPPath()/* overload */;
	__fastcall virtual TdxGPPath(TdxGPFillMode AFillMode)/* overload */;
	__fastcall virtual TdxGPPath(Dxgdiplusapi::TdxGpPointFDynArray APoints, const System::DynamicArray<System::Byte> APointTypes)/* overload */;
	__fastcall virtual ~TdxGPPath();
	virtual void __fastcall Assign(TdxGPPath* ASource);
	void __fastcall Flatten(TdxGPMatrix* AMatrix = (TdxGPMatrix*)(0x0), float AFlatness = 2.500000E-01f);
	void __fastcall FigureFinish();
	void __fastcall FigureStart();
	void __fastcall Reset();
	void __fastcall AddArc(const float X, const float Y, const float Width, const float Height, const float StartAngle, const float SweepAngle);
	void __fastcall AddBezier(const Cxgeometry::TdxPointF &P1, const Cxgeometry::TdxPointF &P2, const Cxgeometry::TdxPointF &P3, const Cxgeometry::TdxPointF &P4);
	void __fastcall AddEllipse(const System::Types::TRect &R)/* overload */;
	void __fastcall AddEllipse(const Cxgeometry::TdxRectF &R)/* overload */;
	void __fastcall AddLine(const float X1, const float Y1, const float X2, const float Y2)/* overload */;
	void __fastcall AddLine(const Cxgeometry::TdxPointF &P1, const Cxgeometry::TdxPointF &P2)/* overload */;
	void __fastcall AddPath(TdxGPPath* const Path)/* overload */;
	void __fastcall AddPath(TdxGPPath* const Path, bool Connect)/* overload */;
	void __fastcall AddPie(const float X, const float Y, const float Width, const float Height, const float StartAngle, const float SweepAngle);
	void __fastcall AddPolygon(const System::Types::TPoint *APoints, const int APoints_High)/* overload */;
	void __fastcall AddPolygon(const Cxgeometry::TdxPointF *APoints, const int APoints_High)/* overload */;
	void __fastcall AddPolyline(const System::Types::TPoint *APoints, const int APoints_High)/* overload */;
	void __fastcall AddPolyline(const Cxgeometry::TdxPointF *APoints, const int APoints_High)/* overload */;
	void __fastcall AddPolyline(const Cxgeometry::PdxPointF APoints, int ACount)/* overload */;
	void __fastcall AddRect(const System::Types::TRect &R)/* overload */;
	void __fastcall AddRect(const Cxgeometry::TdxRectF &R)/* overload */;
	void __fastcall AddRoundRect(const System::Types::TRect &R, int ARadiusX, int ARadiusY)/* overload */;
	void __fastcall AddRoundRect(const Cxgeometry::TdxRectF &R, float ARadiusX, float ARadiusY)/* overload */;
	void __fastcall AddString(const System::UnicodeString S, Vcl::Graphics::TFont* AFont, float AEmSize, const System::Types::TRect &ARect)/* overload */;
	void __fastcall AddString(const System::UnicodeString S, TdxGPFont* AFont, TdxGPStringFormat* AFormat, const Cxgeometry::TdxRectF &ARect)/* overload */;
	void __fastcall AddString(const System::UnicodeString S, TdxGPFont* AFont, TdxGPStringFormat* AFormat, const Cxgeometry::TdxPointF &AOrigin)/* overload */;
	void __fastcall AddString(const System::UnicodeString S, TdxGPFontFamily* AFamily, int AStyle, float AEmSize, const Cxgeometry::TdxPointF &AOrigin, TdxGPStringFormat* AFormat)/* overload */;
	void __fastcall AddString(const System::UnicodeString S, TdxGPFontFamily* AFamily, int AStyle, float AEmSize, const System::Types::TPoint &AOrigin, TdxGPStringFormat* AFormat)/* overload */;
	void __fastcall AddString(const System::UnicodeString S, TdxGPFontFamily* AFamily, int AStyle, float AEmSize, const Cxgeometry::TdxRectF &ALayoutRect, TdxGPStringFormat* AFormat)/* overload */;
	void __fastcall AddString(const System::UnicodeString S, TdxGPFontFamily* AFamily, int AStyle, float AEmSize, const System::Types::TRect &ALayoutRect, TdxGPStringFormat* AFormat)/* overload */;
	System::Types::TRect __fastcall GetBounds(TdxGPPen* APen = (TdxGPPen*)(0x0));
	Cxgeometry::TdxRectF __fastcall GetBoundsF(TdxGPPen* APen = (TdxGPPen*)(0x0));
	HRGN __fastcall GetGdiRegionHandle(TdxGPCanvas* ACanvas);
	int __fastcall GetPointCount();
	bool __fastcall IsPointInPath(const Cxgeometry::TdxPointF &P, TdxGPCanvas* ACanvas = (TdxGPCanvas*)(0x0))/* overload */;
	bool __fastcall IsPointInPath(const System::Types::TPoint &P, TdxGPCanvas* ACanvas = (TdxGPCanvas*)(0x0))/* overload */;
	bool __fastcall IsPointInPathOutline(const Cxgeometry::TdxPointF &P, TdxGPPen* APen, TdxGPCanvas* ACanvas = (TdxGPCanvas*)(0x0))/* overload */;
	bool __fastcall IsPointInPathOutline(const System::Types::TPoint &P, TdxGPPen* APen, TdxGPCanvas* ACanvas = (TdxGPCanvas*)(0x0))/* overload */;
	bool __fastcall IsPointInPathOutline(const System::Types::TPoint &P, int APenWidth, TdxGPCanvas* ACanvas = (TdxGPCanvas*)(0x0))/* overload */;
	Dxgdiplusapi::Status __fastcall TryGetBounds(/* out */ System::Types::TRect &ARect, TdxGPPen* APen = (TdxGPPen*)(0x0));
	Dxgdiplusapi::Status __fastcall TryGetBoundsF(/* out */ Cxgeometry::TdxRectF &ARect, TdxGPPen* APen = (TdxGPPen*)(0x0));
	void __fastcall Transform(TdxGPMatrix* AMatrix);
	__property TdxGPFillMode FillMode = {read=GetFillMode, write=SetFillMode, nodefault};
	__property void * Handle = {read=FHandle};
};

#pragma pack(pop)

enum DECLSPEC_DENUM TdxGPCombineMode : unsigned char { gmReplace, gmIntersect, gmUnion, gmXor, gmExclude, gmComplement };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGPRegion : public Dxgdiplusapi::TdxGpBase
{
	typedef Dxgdiplusapi::TdxGpBase inherited;
	
private:
	void *FHandle;
	
public:
	__fastcall virtual TdxGPRegion()/* overload */;
	__fastcall virtual TdxGPRegion(void * APath)/* overload */;
	__fastcall virtual TdxGPRegion(TdxGPPath* const APath)/* overload */;
	__fastcall virtual TdxGPRegion(const System::Types::TRect &ARect)/* overload */;
	__fastcall virtual TdxGPRegion(const Cxgeometry::TdxRectF &ARect)/* overload */;
	__fastcall virtual TdxGPRegion(void * ARegion, int ADummy);
	__fastcall virtual ~TdxGPRegion();
	void __fastcall CombineRegionPath(TdxGPPath* const APath, TdxGPCombineMode AMode);
	void __fastcall CombineRegionRect(const System::Types::TRect &ARect, TdxGPCombineMode AMode)/* overload */;
	void __fastcall CombineRegionRect(const Cxgeometry::TdxRectF &ARect, TdxGPCombineMode AMode)/* overload */;
	void __fastcall CombineRegionRegion(const HRGN ARegion, TdxGPCombineMode AMode, bool AFreeRegion = false)/* overload */;
	void __fastcall CombineRegionRegion(TdxGPRegion* const ARegion, TdxGPCombineMode AMode, bool AFreeRegion = false)/* overload */;
	HRGN __fastcall GetGdiRegionHandle(TdxGPCanvas* ACanvas);
	void __fastcall MakeEmpty();
	__property void * Handle = {read=FHandle};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGPMemoryStream : public Dxsmartimage::TdxSmartImageDataStream
{
	typedef Dxsmartimage::TdxSmartImageDataStream inherited;
	
protected:
	virtual void * __fastcall Realloc(NativeInt &ANewCapacity);
	
public:
	__fastcall TdxGPMemoryStream();
	__fastcall virtual ~TdxGPMemoryStream();
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGPStringFormat : public Dxgdiplusapi::TdxGpBase
{
	typedef Dxgdiplusapi::TdxGpBase inherited;
	
private:
	static TdxGPStringFormat* FGenericTypographic;
	static TdxGPStringFormat* FGenericDefault;
	static TdxGPStringFormat* __fastcall GetGenericDefault();
	static TdxGPStringFormat* __fastcall GetGenericTypographic();
	void *FHandle;
	
protected:
	__fastcall TdxGPStringFormat(void * AHandle);
	
private:
	Dxgdiplusapi::TdxGpStringAlignment __fastcall GetAlignment();
	System::Word __fastcall GetDigitSubstitutionLanguage();
	Dxgdiplusapi::TdxGpStringDigitSubstitute __fastcall GetDigitSubstitutionMethod();
	int __fastcall GetFormatFlags();
	Dxgdiplusapi::TdxGPHotkeyPrefix __fastcall GetHotkeyPrefix();
	Dxgdiplusapi::TdxGpStringAlignment __fastcall GetLineAlignment();
	int __fastcall GetMeasurableCharacterRangeCount();
	Dxgdiplusapi::TdxGpStringTrimming __fastcall GetTrimming();
	void __fastcall SetAlignment(const Dxgdiplusapi::TdxGpStringAlignment AValue);
	void __fastcall SetFormatFlags(const int AValue);
	void __fastcall SetHotkeyPrefix(const Dxgdiplusapi::TdxGPHotkeyPrefix AValue);
	void __fastcall SetLineAlignment(const Dxgdiplusapi::TdxGpStringAlignment AValue);
	void __fastcall SetTrimming(const Dxgdiplusapi::TdxGpStringTrimming AValue);
	
protected:
	__classmethod void __fastcall Finalize();
	
public:
	__fastcall TdxGPStringFormat(int AFormatAttributes, System::Word ALanguage)/* overload */;
	__fastcall TdxGPStringFormat(TdxGPStringFormat* AFormat)/* overload */;
	__fastcall virtual ~TdxGPStringFormat();
	void __fastcall Assign(TdxGPStringFormat* ASource);
	TdxGPStringFormat* __fastcall Clone();
	void __fastcall SetTabStops(float AFirstTabOffset, int ACount, const System::DynamicArray<float> ATabStops);
	int __fastcall GetTabStopCount();
	System::DynamicArray<float> __fastcall GetTabStops(int ACount, /* out */ float &AFirstTabOffset);
	void __fastcall SetDigitSubstitution(System::Word ALanguage, Dxgdiplusapi::TdxGpStringDigitSubstitute ASubstitute);
	void __fastcall SetMeasurableCharacterRanges(int ACount, const System::DynamicArray<Dxgdiplusapi::TdxGpCharacterRange> ARanges);
	__property Dxgdiplusapi::TdxGpStringAlignment Alignment = {read=GetAlignment, write=SetAlignment, nodefault};
	__property System::Word DigitSubstitutionLanguage = {read=GetDigitSubstitutionLanguage, nodefault};
	__property Dxgdiplusapi::TdxGpStringDigitSubstitute DigitSubstitutionMethod = {read=GetDigitSubstitutionMethod, nodefault};
	__property int FormatFlags = {read=GetFormatFlags, write=SetFormatFlags, nodefault};
	__property void * Handle = {read=FHandle};
	__property Dxgdiplusapi::TdxGPHotkeyPrefix HotkeyPrefix = {read=GetHotkeyPrefix, write=SetHotkeyPrefix, nodefault};
	__property Dxgdiplusapi::TdxGpStringAlignment LineAlignment = {read=GetLineAlignment, write=SetLineAlignment, nodefault};
	__property int MeasurableCharacterRangeCount = {read=GetMeasurableCharacterRangeCount, nodefault};
	__property Dxgdiplusapi::TdxGpStringTrimming Trimming = {read=GetTrimming, write=SetTrimming, nodefault};
	/* static */ __property TdxGPStringFormat* GenericDefault = {read=GetGenericDefault};
	/* static */ __property TdxGPStringFormat* GenericTypographic = {read=GetGenericTypographic};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGPFontFamily : public Dxgdiplusapi::TdxGpBase
{
	typedef Dxgdiplusapi::TdxGpBase inherited;
	
private:
	static TdxGPFontFamily* FGenericSansSerif;
	static TdxGPFontFamily* FGenericSerif;
	static TdxGPFontFamily* FGenericMonospace;
	static TdxGPFontFamily* __fastcall GetGenericSansSerif();
	static TdxGPFontFamily* __fastcall GetGenericSerif();
	static TdxGPFontFamily* __fastcall GetGenericMonospace();
	void *FHandle;
	System::UnicodeString __fastcall GetNameProperty();
	
protected:
	__fastcall TdxGPFontFamily(void * AHandle)/* overload */;
	__classmethod void __fastcall Finalize();
	
public:
	__fastcall TdxGPFontFamily(const System::UnicodeString AName)/* overload */;
	__fastcall virtual ~TdxGPFontFamily();
	System::UnicodeString __fastcall GetName(System::Word ALanguage);
	TdxGPFontFamily* __fastcall Clone();
	System::Word __fastcall GetCellAscent(int AStyle);
	System::Word __fastcall GetCellDescent(int AStyle);
	System::Word __fastcall GetEmHeight(int AStyle);
	System::Word __fastcall GetLineSpacing(int AStyle);
	bool __fastcall IsStyleAvailable(int AStyle);
	__property void * Handle = {read=FHandle};
	__property System::UnicodeString Name = {read=GetNameProperty};
	/* static */ __property TdxGPFontFamily* GenericSansSerif = {read=GetGenericSansSerif};
	/* static */ __property TdxGPFontFamily* GenericSerif = {read=GetGenericSerif};
	/* static */ __property TdxGPFontFamily* GenericMonospace = {read=GetGenericMonospace};
};

#pragma pack(pop)

typedef System::DynamicArray<TdxGPFontFamily*> TdxGPFontFamilies;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGPFontCollection : public Dxgdiplusapi::TdxGpBase
{
	typedef Dxgdiplusapi::TdxGpBase inherited;
	
private:
	int __fastcall GetFamilyCount();
	System::DynamicArray<TdxGPFontFamily*> __fastcall GetFamilies();
	void __fastcall ClearFamilies();
	
protected:
	System::DynamicArray<TdxGPFontFamily*> FFamilies;
	void *FHandle;
	virtual void __fastcall CreateHandle() = 0 ;
	virtual void __fastcall FreeHandle();
	
public:
	__fastcall TdxGPFontCollection();
	__fastcall virtual ~TdxGPFontCollection();
	__property int FamilyCount = {read=GetFamilyCount, nodefault};
	__property System::DynamicArray<TdxGPFontFamily*> Families = {read=GetFamilies};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGPInstalledFontCollection : public TdxGPFontCollection
{
	typedef TdxGPFontCollection inherited;
	
protected:
	virtual void __fastcall CreateHandle();
public:
	/* TdxGPFontCollection.Create */ inline __fastcall TdxGPInstalledFontCollection() : TdxGPFontCollection() { }
	/* TdxGPFontCollection.Destroy */ inline __fastcall virtual ~TdxGPInstalledFontCollection() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGPPrivateFontCollection : public TdxGPFontCollection
{
	typedef TdxGPFontCollection inherited;
	
protected:
	virtual void __fastcall CreateHandle();
	virtual void __fastcall FreeHandle();
public:
	/* TdxGPFontCollection.Create */ inline __fastcall TdxGPPrivateFontCollection() : TdxGPFontCollection() { }
	/* TdxGPFontCollection.Destroy */ inline __fastcall virtual ~TdxGPPrivateFontCollection() { }
	
};

#pragma pack(pop)

enum DECLSPEC_DENUM TdxGPFontStyle : unsigned char { FontStyleRegular, FontStyleBold, FontStyleItalic, FontStyleUnderline = 0x4, FontStyleStrikeout = 0x8 };

typedef System::Set<TdxGPFontStyle, TdxGPFontStyle::FontStyleRegular, TdxGPFontStyle::FontStyleStrikeout> TdxGPFontStyles;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGPFont : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	void *FNativeFont;
	float FFontSize;
	int FFontStyle;
	TdxGPFontFamily* FFontFamily;
	Dxcoregraphics::TdxGraphicUnit FFontUnit;
	System::Byte FGdiCharSet;
	bool FGdiVerticalFont;
	System::UnicodeString FSystemFontName;
	System::UnicodeString FOriginalFontName;
	void __fastcall CreateNativeFont();
	void __fastcall Initialize(const System::UnicodeString AFamilyName, float AEmSize, TdxGPFontStyle AStyle, Dxcoregraphics::TdxGraphicUnit AUnit, System::Byte AGdiCharSet, bool AGdiVerticalFont)/* overload */;
	void __fastcall Initialize(TdxGPFontFamily* AFamily, float AEmSize, TdxGPFontStyle AStyle, Dxcoregraphics::TdxGraphicUnit AUnit, System::Byte AGdiCharSet, bool AGdiVerticalFont)/* overload */;
	TdxGPFontFamily* __fastcall GetFontFamily();
	bool __fastcall GetBold();
	bool __fastcall GetItalic();
	System::UnicodeString __fastcall GetName();
	bool __fastcall GetStrikeout();
	bool __fastcall GetUnderline();
	float __fastcall GetSizeInPoints();
	int __fastcall GetHeightProperty();
	bool __fastcall GetIsSystemFont();
	
public:
	__fastcall TdxGPFont(TdxGPFont* APrototype, TdxGPFontStyle ANewStyle)/* overload */;
	__fastcall TdxGPFont(TdxGPFontFamily* AFamily, float AEmSize)/* overload */;
	__fastcall TdxGPFont(TdxGPFontFamily* AFamily, float AEmSize, TdxGPFontStyle AStyle)/* overload */;
	__fastcall TdxGPFont(TdxGPFontFamily* AFamily, float AEmSize, TdxGPFontStyle AStyle, Dxcoregraphics::TdxGraphicUnit AUnit)/* overload */;
	__fastcall TdxGPFont(TdxGPFontFamily* AFamily, float AEmSize, TdxGPFontStyle AStyle, Dxcoregraphics::TdxGraphicUnit AUnit, System::Byte AGdiCharSet)/* overload */;
	__fastcall TdxGPFont(TdxGPFontFamily* AFamily, float AEmSize, TdxGPFontStyle AStyle, Dxcoregraphics::TdxGraphicUnit AUnit, System::Byte AGdiCharSet, bool AGdiVerticalFont)/* overload */;
	__fastcall TdxGPFont(TdxGPFontFamily* AFamily, float AEmSize, Dxcoregraphics::TdxGraphicUnit AUnit)/* overload */;
	__fastcall TdxGPFont(const System::UnicodeString AFamilyName, float AEmSize)/* overload */;
	__fastcall TdxGPFont(const System::UnicodeString AFamilyName, float AEmSize, TdxGPFontStyle AStyle)/* overload */;
	__fastcall TdxGPFont(const System::UnicodeString AFamilyName, float AEmSize, TdxGPFontStyle AStyle, Dxcoregraphics::TdxGraphicUnit AUnit)/* overload */;
	__fastcall TdxGPFont(const System::UnicodeString AFamilyName, float AEmSize, TdxGPFontStyle AStyle, Dxcoregraphics::TdxGraphicUnit AUnit, System::Byte AGdiCharSet)/* overload */;
	__fastcall TdxGPFont(const System::UnicodeString AFamilyName, float AEmSize, TdxGPFontStyle AStyle, Dxcoregraphics::TdxGraphicUnit AUnit, System::Byte AGdiCharSet, bool AGdiVerticalFont)/* overload */;
	__fastcall TdxGPFont(const System::UnicodeString AFamilyName, float AEmSize, Dxcoregraphics::TdxGraphicUnit AUnit)/* overload */;
	__fastcall TdxGPFont(void * ANativeFont, System::Byte AGdiCharSet, bool AGdiVerticalFont)/* overload */;
	__fastcall virtual ~TdxGPFont();
	static TdxGPFont* __fastcall FromHFont(NativeUInt AHFont);
	static TdxGPFont* __fastcall FromLogFont(const tagLOGFONTW &ALogFont)/* overload */;
	static TdxGPFont* __fastcall FromLogFont(const tagLOGFONTW &ALogFont, NativeUInt AHdc)/* overload */;
	static TdxGPFont* __fastcall FromHdc(NativeUInt AHdc);
	__classmethod TdxGPFont* __fastcall SafeCreate(const System::UnicodeString AFamilyName, float AEmSize, TdxGPFontStyle AStyle, Dxcoregraphics::TdxGraphicUnit AUnit = (Dxcoregraphics::TdxGraphicUnit)(0x3), System::Byte AGdiCharSet = (System::Byte)(0x1));
	TdxGPFont* __fastcall Clone();
	void __fastcall SetFontFamily(TdxGPFontFamily* AFamily);
	static bool __fastcall IsVerticalName(const System::UnicodeString AFamilyName);
	virtual int __fastcall GetHashCode();
	static System::UnicodeString __fastcall StripVerticalName(const System::UnicodeString AFamilyName);
	void __fastcall ToLogFont(/* out */ tagLOGFONTW &ALogFont)/* overload */;
	void __fastcall ToLogFont(/* out */ tagLOGFONTW &ALogFont, TdxGPCanvas* ACanvas)/* overload */;
	NativeUInt __fastcall ToHfont();
	float __fastcall GetHeight(TdxGPCanvas* AGraphics)/* overload */;
	float __fastcall GetHeight(float ADpi)/* overload */;
	float __fastcall GetHeight()/* overload */;
	void __fastcall SetSystemFontName(const System::UnicodeString ASystemFontName);
	__property void * NativeFont = {read=FNativeFont};
	__property TdxGPFontFamily* FontFamily = {read=GetFontFamily};
	__property bool Bold = {read=GetBold, nodefault};
	__property System::Byte GdiCharSet = {read=FGdiCharSet, nodefault};
	__property bool GdiVerticalFont = {read=FGdiVerticalFont, nodefault};
	__property bool Italic = {read=GetItalic, nodefault};
	__property System::UnicodeString Name = {read=GetName};
	__property System::UnicodeString OriginalFontName = {read=FOriginalFontName};
	__property bool Strikeout = {read=GetStrikeout, nodefault};
	__property bool Underline = {read=GetUnderline, nodefault};
	__property int Style = {read=FFontStyle, nodefault};
	__property float Size = {read=FFontSize};
	__property float SizeInPoints = {read=GetSizeInPoints};
	__property Dxcoregraphics::TdxGraphicUnit Unit = {read=FFontUnit, nodefault};
	__property int Height = {read=GetHeightProperty, nodefault};
	__property bool IsSystemFont = {read=GetIsSystemFont, nodefault};
	__property System::UnicodeString SystemFontName = {read=FSystemFontName};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGPCanvas : public Dxgdiplusapi::TdxGpBase
{
	typedef Dxgdiplusapi::TdxGpBase inherited;
	
private:
	System::Contnrs::TStack* FSavedClipRegions;
	System::Contnrs::TStack* FSavedWorldTransforms;
	TdxGpCompositionMode __fastcall GetCompositionMode();
	float __fastcall GetDpiX();
	float __fastcall GetDpiY();
	TdxGPInterpolationMode __fastcall GetInterpolationMode();
	float __fastcall GetPageScale();
	Dxcoregraphics::TdxGraphicUnit __fastcall GetPageUnit();
	Dxgdiplusapi::TdxGpPixelOffsetMode __fastcall GetPixelOffsetMode();
	TdxGPSmoothingMode __fastcall GetSmoothingMode();
	Dxgdiplusapi::TdxGpTextRenderingHint __fastcall GetTextRenderingHint();
	void __fastcall SetCompositionMode(TdxGpCompositionMode AValue);
	void __fastcall SetInterpolationMode(TdxGPInterpolationMode AValue);
	void __fastcall SetPageScale(float AValue);
	void __fastcall SetPageUnit(Dxcoregraphics::TdxGraphicUnit AValue);
	void __fastcall SetPixelOffsetMode(Dxgdiplusapi::TdxGpPixelOffsetMode AValue);
	void __fastcall SetSmoothingMode(TdxGPSmoothingMode AValue);
	void __fastcall SetTextRenderingHint(Dxgdiplusapi::TdxGpTextRenderingHint AValue);
	
protected:
	void *FHandle;
	bool FIsLowColorsMode;
	void __fastcall AdjustRectToGdiLikeAppearance(Cxgeometry::TdxRectF &R)/* overload */;
	void __fastcall AdjustRectToGdiLikeAppearance(System::Types::TRect &R)/* overload */;
	void __fastcall CreateHandle(HDC DC);
	void __fastcall FreeHandle();
	Cxgeometry::TdxSizeF __fastcall MeasureString(const System::UnicodeString AText, TdxGPFont* AFont, const Dxgdiplusapi::TdxGpRectF &ALayoutRect, TdxGPStringFormat* AStringFormat, /* out */ int &ACharactersFitted, /* out */ int &ALinesFilled)/* overload */;
	
public:
	__fastcall virtual TdxGPCanvas()/* overload */;
	__fastcall TdxGPCanvas(void * AHandle)/* overload */;
	__fastcall TdxGPCanvas(NativeUInt DC)/* overload */;
	__fastcall virtual ~TdxGPCanvas();
	HDC __fastcall GetHDC();
	void __fastcall ReleaseHDC(HDC DC);
	void __fastcall Clear(System::Uitypes::TColor AColor);
	void __fastcall Draw(TdxGPImage* AGraphic, const Cxgeometry::TdxRectF &ADestRect, const Cxgeometry::TdxRectF &ASourceRect, System::Byte AAlpha = (System::Byte)(0xff))/* overload */;
	void __fastcall Draw(TdxGPImage* AGraphic, const System::Types::TRect &ADestRect, const System::Types::TRect &ASourceRect, System::Byte AAlpha = (System::Byte)(0xff))/* overload */;
	void __fastcall Draw(TdxGPImage* AGraphic, const Cxgeometry::TdxRectF &R, System::Byte AAlpha = (System::Byte)(0xff))/* overload */;
	void __fastcall Draw(TdxGPImage* AGraphic, const System::Types::TRect &R, System::Byte AAlpha = (System::Byte)(0xff))/* overload */;
	void __fastcall Draw(TdxGPImage* AGraphic, const Cxgeometry::TdxRectF &ADestRect, const Cxgeometry::TdxRectF &ASourceRect, TdxGPImageAttributes* AAttributes)/* overload */;
	void __fastcall Draw(TdxGPImage* AGraphic, const System::Types::TRect &R, TdxGPImageAttributes* AAttributes)/* overload */;
	void __fastcall Draw(TdxGPImage* AGraphic, const Cxgeometry::TdxPointF *APoints, const int APoints_High)/* overload */;
	void __fastcall Draw(TdxGPImage* AGraphic, const Cxgeometry::TdxPointF *APoints, const int APoints_High, TdxGPImageAttributes* AAttributes)/* overload */;
	void __fastcall DrawBitmap(Vcl::Graphics::TBitmap* ABitmap, const System::Types::TRect &R, System::Byte AAlpha = (System::Byte)(0xff));
	void __fastcall DrawTile(TdxGPImage* AGraphic, const System::Types::TRect &R, System::Byte AAlpha = (System::Byte)(0xff))/* overload */;
	void __fastcall DrawTile(TdxGPImage* AGraphic, const System::Types::TRect &ADestRect, const System::Types::TRect &ASourceRect, System::Byte AAlpha = (System::Byte)(0xff))/* overload */;
	bool __fastcall GetClipBounds(/* out */ Cxgeometry::TdxRectF &R)/* overload */;
	bool __fastcall GetClipBounds(/* out */ System::Types::TRect &R)/* overload */;
	HRGN __fastcall GetClipGdiRegion();
	void * __fastcall GetClipNativeRegion();
	TdxGPRegion* __fastcall GetClipRegion();
	bool __fastcall IsClipEmpty();
	void __fastcall RestoreClipRegion();
	void __fastcall SaveClipRegion();
	void __fastcall SetClipPath(TdxGPPath* APath, TdxGPCombineMode AMode);
	void __fastcall SetClipRect(const System::Types::TRect &R, TdxGPCombineMode AMode)/* overload */;
	void __fastcall SetClipRect(const Cxgeometry::TdxRectF &R, TdxGPCombineMode AMode)/* overload */;
	void __fastcall SetClipRegion(HRGN ARgn, TdxGPCombineMode AMode)/* overload */;
	void __fastcall SetClipRegion(TdxGPRegion* ARegion, TdxGPCombineMode AMode)/* overload */;
	void __fastcall Arc(const System::Types::TRect &R, float AStartAngle, float ASweepAngle, System::Uitypes::TColor APenColor, float APenWidth, Vcl::Graphics::TPenStyle APenStyle, System::Byte APenColorAlpha)/* overload */;
	void __fastcall Arc(const System::Types::TRect &R, float AStartAngle, float ASweepAngle, Dxcoregraphics::TdxAlphaColor APenColor, float APenWidth = 1.000000E+00f, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0))/* overload */;
	void __fastcall Arc(const System::Types::TRect &AEllipse, const System::Types::TPoint &AStartPoint, const System::Types::TPoint &AEndPoint, Dxcoregraphics::TdxAlphaColor AColor, int APenWidth, Vcl::Graphics::TPenStyle APenStyle)/* overload */;
	void __fastcall Curve(const System::Types::TPoint *APoints, const int APoints_High, System::Uitypes::TColor APenColor, float APenWidth, Vcl::Graphics::TPenStyle APenStyle, System::Byte APenColorAlpha)/* overload */;
	void __fastcall Curve(const System::Types::TPoint *APoints, const int APoints_High, Dxcoregraphics::TdxAlphaColor APenColor, float APenWidth = 1.000000E+00f, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0))/* overload */;
	void __fastcall Curve(const Cxgeometry::TdxPointF *APoints, const int APoints_High, System::Uitypes::TColor APenColor, float APenWidth, Vcl::Graphics::TPenStyle APenStyle, System::Byte APenColorAlpha)/* overload */;
	void __fastcall DonutSlice(const Cxgeometry::TdxRectF &R, float AStartAngle, float ASweepAngle, float AWholePercent, TdxGPCustomBrush* ABrush = (TdxGPCustomBrush*)(0x0), TdxGPPen* APen = (TdxGPPen*)(0x0));
	void __fastcall Ellipse(const System::Types::TRect &R, TdxGPPen* APen, TdxGPCustomBrush* ABrush)/* overload */;
	void __fastcall Ellipse(const Cxgeometry::TdxRectF &R, TdxGPPen* APen, TdxGPCustomBrush* ABrush)/* overload */;
	void __fastcall Ellipse(const Cxgeometry::TdxRectF &R, System::Uitypes::TColor APenColor, System::Uitypes::TColor ABrushColor, float APenWidth, Vcl::Graphics::TPenStyle APenStyle, System::Byte APenColorAlpha, System::Byte ABrushColorAlpha)/* overload */;
	void __fastcall Ellipse(const System::Types::TRect &R, Dxcoregraphics::TdxAlphaColor APenColor, Dxcoregraphics::TdxAlphaColor ABrushColor, float APenWidth = 1.000000E+00f, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0))/* overload */;
	void __fastcall Ellipse(const Cxgeometry::TdxRectF &R, Dxcoregraphics::TdxAlphaColor APenColor, Dxcoregraphics::TdxAlphaColor ABrushColor, float APenWidth = 1.000000E+00f, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0))/* overload */;
	void __fastcall Ellipse(const System::Types::TRect &R, System::Uitypes::TColor APenColor, System::Uitypes::TColor ABrushColor, float APenWidth, Vcl::Graphics::TPenStyle APenStyle, System::Byte APenColorAlpha, System::Byte ABrushColorAlpha)/* overload */;
	void __fastcall Line(int X1, int Y1, int X2, int Y2, System::Uitypes::TColor APenColor, float APenWidth, Vcl::Graphics::TPenStyle APenStyle, System::Byte APenColorAlpha)/* overload */;
	void __fastcall Line(int X1, int Y1, int X2, int Y2, Dxcoregraphics::TdxAlphaColor APenColor, float APenWidth = 1.000000E+00f, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0))/* overload */;
	void __fastcall Line(float X1, float Y1, float X2, float Y2, Dxcoregraphics::TdxAlphaColor APenColor, float APenWidth = 1.000000E+00f, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0))/* overload */;
	void __fastcall Line(int X1, int Y1, int X2, int Y2, TdxGPPen* APen)/* overload */;
	void __fastcall Line(float X1, float Y1, float X2, float Y2, TdxGPPen* APen)/* overload */;
	void __fastcall Path(TdxGPPath* APath, TdxGPPen* APen, TdxGPCustomBrush* ABrush)/* overload */;
	void __fastcall Path(TdxGPPath* APath, Dxcoregraphics::TdxAlphaColor APenColor, Dxcoregraphics::TdxAlphaColor ABrushColor, float APenWidth = 1.000000E+00f, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0))/* overload */;
	void __fastcall Path(TdxGPPath* APath, System::Uitypes::TColor APenColor, System::Uitypes::TColor ABrushColor, float APenWidth, Vcl::Graphics::TPenStyle APenStyle, System::Byte APenColorAlpha, System::Byte ABrushColorAlpha)/* overload */;
	void __fastcall Pie(const System::Types::TRect &R, float AStartAngle, float ASweepAngle, System::Uitypes::TColor APenColor, System::Uitypes::TColor ABrushColor, float APenWidth, Vcl::Graphics::TPenStyle APenStyle, System::Byte APenColorAlpha, System::Byte ABrushColorAlpha)/* overload */;
	void __fastcall Pie(const System::Types::TRect &R, float AStartAngle, float ASweepAngle, Dxcoregraphics::TdxAlphaColor APenColor, Dxcoregraphics::TdxAlphaColor ABrushColor, float APenWidth = 1.000000E+00f, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0))/* overload */;
	void __fastcall Pie(const Cxgeometry::TdxRectF &R, float AStartAngle, float ASweepAngle, TdxGPCustomBrush* ABrush = (TdxGPCustomBrush*)(0x0), TdxGPPen* APen = (TdxGPPen*)(0x0))/* overload */;
	void __fastcall Polygon(const System::Types::TPoint *APoints, const int APoints_High, System::Uitypes::TColor APenColor, System::Uitypes::TColor ABrushColor, float APenWidth, Vcl::Graphics::TPenStyle APenStyle, System::Byte APenColorAlpha, System::Byte ABrushColorAlpha)/* overload */;
	void __fastcall Polygon(const System::Types::TPoint *APoints, const int APoints_High, Dxcoregraphics::TdxAlphaColor APenColor, Dxcoregraphics::TdxAlphaColor ABrushColor, float APenWidth = 1.000000E+00f, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0))/* overload */;
	void __fastcall Polygon(const Cxgeometry::TdxPointF *APoints, const int APoints_High, System::Uitypes::TColor APenColor, System::Uitypes::TColor ABrushColor, float APenWidth, Vcl::Graphics::TPenStyle APenStyle, System::Byte APenColorAlpha, System::Byte ABrushColorAlpha)/* overload */;
	void __fastcall Polygon(const Cxgeometry::TdxPointF *APoints, const int APoints_High, Dxcoregraphics::TdxAlphaColor APenColor, Dxcoregraphics::TdxAlphaColor ABrushColor, float APenWidth, TdxGPPenStyle APenStyle)/* overload */;
	void __fastcall Polygon(const System::Types::TPoint *APoints, const int APoints_High, TdxGPPen* APen, TdxGPCustomBrush* ABrush)/* overload */;
	void __fastcall Polygon(const Cxgeometry::TdxPointF *APoints, const int APoints_High, TdxGPPen* APen, TdxGPCustomBrush* ABrush)/* overload */;
	void __fastcall Polygon(const Cxgeometry::PdxPointF APoints, int ACount, TdxGPPen* APen, TdxGPCustomBrush* ABrush)/* overload */;
	void __fastcall Polyline(const System::Types::TPoint *APoints, const int APoints_High, System::Uitypes::TColor APenColor, float APenWidth, Vcl::Graphics::TPenStyle APenStyle, System::Byte APenColorAlpha)/* overload */;
	void __fastcall Polyline(const System::Types::TPoint *APoints, const int APoints_High, Dxcoregraphics::TdxAlphaColor APenColor, float APenWidth = 1.000000E+00f, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0))/* overload */;
	void __fastcall Polyline(const Cxgeometry::TdxPointF *APoints, const int APoints_High, System::Uitypes::TColor APenColor, float APenWidth, Vcl::Graphics::TPenStyle APenStyle, System::Byte APenColorAlpha)/* overload */;
	void __fastcall Polyline(const Cxgeometry::TdxPointF *APoints, const int APoints_High, Dxcoregraphics::TdxAlphaColor APenColor, float APenWidth = 1.000000E+00f, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0))/* overload */;
	void __fastcall Polyline(const Cxgeometry::TdxPointF *APoints, const int APoints_High, TdxGPPen* APen)/* overload */;
	void __fastcall Polyline(const System::Types::TPoint *APoints, const int APoints_High, TdxGPPen* APen)/* overload */;
	void __fastcall Polyline(const Cxgeometry::PdxPointF APoints, int ACount, TdxGPPen* APen)/* overload */;
	void __fastcall DrawRectangle(const Cxgeometry::TdxRectF &R, TdxGPPen* APen)/* overload */;
	void __fastcall FillRectangle(const Cxgeometry::TdxRectF &R, TdxGPCustomBrush* ABrush)/* overload */;
	void __fastcall FillRectangle(const Cxgeometry::TdxRectF &R, Dxcoregraphics::TdxAlphaColor ABrushColor)/* overload */;
	void __fastcall FillRectangle(const System::Types::TRect &R, TdxGPCustomBrush* ABrush)/* overload */;
	void __fastcall FillRectangle(const System::Types::TRect &R, Dxcoregraphics::TdxAlphaColor ABrushColor)/* overload */;
	void __fastcall FillRectangleByGradient(const System::Types::TRect &R, Dxcoregraphics::TdxAlphaColor AColor1, Dxcoregraphics::TdxAlphaColor AColor2, Dxgdiplusapi::LinearGradientMode AMode)/* overload */;
	void __fastcall FillRectangleByGradient(const Cxgeometry::TdxRectF &R, Dxcoregraphics::TdxAlphaColor AColor1, Dxcoregraphics::TdxAlphaColor AColor2, Dxgdiplusapi::LinearGradientMode AMode)/* overload */;
	void __fastcall Rectangle(const Cxgeometry::TdxRectF &R, Dxcoregraphics::TdxAlphaColor APenColor, Dxcoregraphics::TdxAlphaColor ABrushColor, float APenWidth = 1.000000E+00f, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0))/* overload */;
	void __fastcall Rectangle(const Cxgeometry::TdxRectF &R, TdxGPPen* APen, TdxGPCustomBrush* ABrush)/* overload */;
	void __fastcall Rectangle(const System::Types::TRect &R, TdxGPPen* APen, TdxGPCustomBrush* ABrush)/* overload */;
	void __fastcall Rectangle(const System::Types::TRect &R, Dxcoregraphics::TdxAlphaColor APenColor, Dxcoregraphics::TdxAlphaColor ABrushColor, float APenWidth = 1.000000E+00f, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0))/* overload */;
	void __fastcall Rectangle(const System::Types::TRect &R, System::Uitypes::TColor APenColor, System::Uitypes::TColor ABrushColor, float APenWidth, Vcl::Graphics::TPenStyle APenStyle, System::Byte APenColorAlpha, System::Byte ABrushColorAlpha)/* overload */;
	void __fastcall Region(TdxGPRegion* ARegion, Dxcoregraphics::TdxAlphaColor APenColor, Dxcoregraphics::TdxAlphaColor ABrushColor, float APenWidth = 1.000000E+00f, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0));
	void __fastcall RoundRect(const System::Types::TRect &R, TdxGPPen* APen, TdxGPCustomBrush* ABrush, int ARadiusX, int ARadiusY)/* overload */;
	void __fastcall RoundRect(const System::Types::TRect &R, System::Uitypes::TColor APenColor, System::Uitypes::TColor ABrushColor, int ARadiusX, int ARadiusY, int APenWidth, System::Byte APenColorAlpha, System::Byte ABrushColorAlpha)/* overload */;
	void __fastcall RoundRect(const System::Types::TRect &R, Dxcoregraphics::TdxAlphaColor APenColor, Dxcoregraphics::TdxAlphaColor ABrushColor, int ARadiusX, int ARadiusY, float APenWidth = 1.000000E+00f)/* overload */;
	void __fastcall DrawString(const System::UnicodeString S, TdxGPFont* AFont, TdxGPCustomBrush* ABrush, float X, float Y)/* overload */;
	void __fastcall DrawString(const System::UnicodeString S, TdxGPFont* AFont, TdxGPCustomBrush* ABrush, const Cxgeometry::TdxRectF &ARect)/* overload */;
	void __fastcall DrawString(const System::UnicodeString S, TdxGPFont* AFont, TdxGPCustomBrush* ABrush, const Cxgeometry::TdxPointF &APoint)/* overload */;
	void __fastcall DrawString(const System::UnicodeString S, TdxGPFont* AFont, TdxGPCustomBrush* ABrush, float X, float Y, TdxGPStringFormat* AFormat)/* overload */;
	void __fastcall DrawString(const System::UnicodeString S, TdxGPFont* AFont, TdxGPCustomBrush* ABrush, const Cxgeometry::TdxPointF &APoint, TdxGPStringFormat* AFormat)/* overload */;
	void __fastcall DrawString(const System::UnicodeString S, TdxGPFont* AFont, TdxGPCustomBrush* ABrush, const Cxgeometry::TdxRectF &ARect, TdxGPStringFormat* AFormat)/* overload */;
	Cxgeometry::TdxSizeF __fastcall MeasureString(const System::UnicodeString AText, TdxGPFont* AFont, const Cxgeometry::TdxSizeF &ALayoutArea, TdxGPStringFormat* AStringFormat, /* out */ int &ACharactersFitted, /* out */ int &ALinesFilled)/* overload */;
	Cxgeometry::TdxSizeF __fastcall MeasureString(const System::UnicodeString AText, TdxGPFont* AFont, const Cxgeometry::TdxPointF &AOrigin, TdxGPStringFormat* AStringFormat)/* overload */;
	Cxgeometry::TdxSizeF __fastcall MeasureString(const System::UnicodeString AText, TdxGPFont* AFont, const Cxgeometry::TdxSizeF &ALayoutArea)/* overload */;
	Cxgeometry::TdxSizeF __fastcall MeasureString(const System::UnicodeString AText, TdxGPFont* AFont, const Cxgeometry::TdxSizeF &ALayoutArea, TdxGPStringFormat* AStringFormat)/* overload */;
	Cxgeometry::TdxSizeF __fastcall MeasureString(const System::UnicodeString AText, TdxGPFont* AFont)/* overload */;
	Cxgeometry::TdxSizeF __fastcall MeasureString(const System::UnicodeString AText, TdxGPFont* AFont, const double AWidth)/* overload */;
	Cxgeometry::TdxSizeF __fastcall MeasureString(const System::UnicodeString AText, TdxGPFont* AFont, const double AWidth, TdxGPStringFormat* AFormat)/* overload */;
	System::DynamicArray<TdxGPRegion*> __fastcall MeasureCharacterRanges(const System::UnicodeString AText, TdxGPFont* AFont, const Cxgeometry::TdxRectF &ALayoutRect, TdxGPStringFormat* AStringFormat);
	void __fastcall FlipWorldTransform(bool AFlipHorizontally, bool AFlipVertically, const Cxgeometry::TdxPointF &APivotPoint)/* overload */;
	void __fastcall FlipWorldTransform(bool AFlipHorizontally, bool AFlipVertically, const System::Types::TPoint &APivotPoint)/* overload */;
	void __fastcall FlipWorldTransform(bool AFlipHorizontally, bool AFlipVertically, const float APivotPointX, const float APivotPointY)/* overload */;
	TdxGPMatrix* __fastcall GetWorldTransform();
	void __fastcall ModifyWorldTransform(TdxGPMatrix* AMatrix, Dxgdiplusapi::TdxGpMatrixOrder AOrder = (Dxgdiplusapi::TdxGpMatrixOrder)(0x0));
	void __fastcall RotateWorldTransform(float AAngle, Dxgdiplusapi::TdxGpMatrixOrder AOrder = (Dxgdiplusapi::TdxGpMatrixOrder)(0x0))/* overload */;
	void __fastcall RotateWorldTransform(float AAngle, const System::Types::TPoint &APivotPoint, Dxgdiplusapi::TdxGpMatrixOrder AOrder = (Dxgdiplusapi::TdxGpMatrixOrder)(0x0))/* overload */;
	void __fastcall RotateWorldTransform(float AAngle, const Cxgeometry::TdxPointF &APivotPoint, Dxgdiplusapi::TdxGpMatrixOrder AOrder = (Dxgdiplusapi::TdxGpMatrixOrder)(0x0))/* overload */;
	void __fastcall ScaleWorldTransform(float AScaleX, float AScaleY, Dxgdiplusapi::TdxGpMatrixOrder AOrder = (Dxgdiplusapi::TdxGpMatrixOrder)(0x0))/* overload */;
	void __fastcall ScaleWorldTransform(float AScaleX, float AScaleY, const Cxgeometry::TdxPointF &ACenter, Dxgdiplusapi::TdxGpMatrixOrder AOrder = (Dxgdiplusapi::TdxGpMatrixOrder)(0x0))/* overload */;
	void __fastcall SetWorldTransform(TdxGPMatrix* AMatrix);
	void __fastcall TranslateWorldTransform(float AOffsetX, float AOffsetY, Dxgdiplusapi::TdxGpMatrixOrder AOrder = (Dxgdiplusapi::TdxGpMatrixOrder)(0x0));
	void __fastcall TransformPoints(Dxgdiplusapi::TdxGpCoordinateSpace ADestSpace, Dxgdiplusapi::TdxGpCoordinateSpace ASrcSpace, System::DynamicArray<Cxgeometry::TdxPointF> &APoints)/* overload */;
	void __fastcall TransformPoints(Dxgdiplusapi::TdxGpCoordinateSpace ADestSpace, Dxgdiplusapi::TdxGpCoordinateSpace ASrcSpace, System::DynamicArray<System::Types::TPoint> &APoints)/* overload */;
	void __fastcall ResetWorldTransform();
	void __fastcall RestoreWorldTransform();
	void __fastcall SaveWorldTransform();
	__property float DpiX = {read=GetDpiX};
	__property float DpiY = {read=GetDpiY};
	__property void * Handle = {read=FHandle};
	__property TdxGpCompositionMode CompositionMode = {read=GetCompositionMode, write=SetCompositionMode, nodefault};
	__property TdxGPInterpolationMode InterpolationMode = {read=GetInterpolationMode, write=SetInterpolationMode, nodefault};
	__property bool IsLowColorsMode = {read=FIsLowColorsMode, nodefault};
	__property float PageScale = {read=GetPageScale, write=SetPageScale};
	__property Dxcoregraphics::TdxGraphicUnit PageUnit = {read=GetPageUnit, write=SetPageUnit, nodefault};
	__property Dxgdiplusapi::TdxGpPixelOffsetMode PixelOffsetMode = {read=GetPixelOffsetMode, write=SetPixelOffsetMode, nodefault};
	__property TdxGPSmoothingMode SmoothingMode = {read=GetSmoothingMode, write=SetSmoothingMode, nodefault};
	__property Dxgdiplusapi::TdxGpTextRenderingHint TextRenderingHint = {read=GetTextRenderingHint, write=SetTextRenderingHint, nodefault};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGPGraphics : public TdxGPCanvas
{
	typedef TdxGPCanvas inherited;
	
public:
	/* TdxGPCanvas.Create */ inline __fastcall virtual TdxGPGraphics()/* overload */ : TdxGPCanvas() { }
	/* TdxGPCanvas.Create */ inline __fastcall TdxGPGraphics(void * AHandle)/* overload */ : TdxGPCanvas(AHandle) { }
	/* TdxGPCanvas.Create */ inline __fastcall TdxGPGraphics(NativeUInt DC)/* overload */ : TdxGPCanvas(DC) { }
	/* TdxGPCanvas.Destroy */ inline __fastcall virtual ~TdxGPGraphics() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGPCustomPaintCanvas : public TdxGPGraphics
{
	typedef TdxGPGraphics inherited;
	
private:
	System::Syncobjs::TCriticalSection* FLock;
	void __fastcall CreateBuffer(HDC DC, const System::Types::TRect &R);
	void __fastcall FreeBuffer();
	void __fastcall OutputBuffer();
	
protected:
	Vcl::Graphics::TBitmap* FBuffer;
	HDC FDrawDC;
	System::Types::TRect FDrawRect;
	virtual void __fastcall SaveState();
	virtual void __fastcall RestoreState();
	
public:
	__fastcall virtual TdxGPCustomPaintCanvas()/* overload */;
	__fastcall virtual ~TdxGPCustomPaintCanvas();
	void __fastcall BeginPaint(HDC DC, const Cxgeometry::TdxRectF &R)/* overload */;
	void __fastcall BeginPaint(HDC DC, const System::Types::TRect &R)/* overload */;
	void __fastcall BeginPaint(void * AHandle)/* overload */;
	void __fastcall EndPaint();
public:
	/* TdxGPCanvas.Create */ inline __fastcall TdxGPCustomPaintCanvas(void * AHandle)/* overload */ : TdxGPGraphics(AHandle) { }
	/* TdxGPCanvas.Create */ inline __fastcall TdxGPCustomPaintCanvas(NativeUInt DC)/* overload */ : TdxGPGraphics(DC) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGPPaintCanvas : public TdxGPCustomPaintCanvas
{
	typedef TdxGPCustomPaintCanvas inherited;
	
	
private:
	#pragma pack(push,8)
	struct DECLSPEC_DRECORD TdxGPPaintCanvasState
	{
	public:
		void *Handle;
		Vcl::Graphics::TBitmap* Buffer;
		System::Types::TRect DrawRect;
		HDC DC;
	};
	#pragma pack(pop)
	
	
	typedef System::DynamicArray<TdxGPPaintCanvasState> TdxGPPaintCanvasStates;
	
	
private:
	int FCounter;
	TdxGPPaintCanvasStates FSavedStates;
	void __fastcall SetCapacity(int AValue);
	
protected:
	virtual void __fastcall SaveState();
	virtual void __fastcall RestoreState();
	
public:
	__fastcall virtual ~TdxGPPaintCanvas();
public:
	/* TdxGPCustomPaintCanvas.Create */ inline __fastcall virtual TdxGPPaintCanvas()/* overload */ : TdxGPCustomPaintCanvas() { }
	
public:
	/* TdxGPCanvas.Create */ inline __fastcall TdxGPPaintCanvas(void * AHandle)/* overload */ : TdxGPCustomPaintCanvas(AHandle) { }
	/* TdxGPCanvas.Create */ inline __fastcall TdxGPPaintCanvas(NativeUInt DC)/* overload */ : TdxGPCustomPaintCanvas(DC) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGPStreamAdapter : public System::Classes::TStreamAdapter
{
	typedef System::Classes::TStreamAdapter inherited;
	
public:
	virtual HRESULT __stdcall Stat(/* out */ tagSTATSTG &statstg, unsigned grfStatFlag);
public:
	/* TStreamAdapter.Create */ inline __fastcall TdxGPStreamAdapter(System::Classes::TStream* Stream, System::Classes::TStreamOwnership Ownership) : System::Classes::TStreamAdapter(Stream, Ownership) { }
	/* TStreamAdapter.Destroy */ inline __fastcall virtual ~TdxGPStreamAdapter() { }
	
};

#pragma pack(pop)

__interface  INTERFACE_UUID("{12CC0C8A-2C68-4467-AF5F-EBA89E93E1CD}") IdxGPGraphicDraw  : public System::IInterface 
{
	virtual void __fastcall Draw(TdxGPCanvas* ACanvas, const Cxgeometry::TdxRectF &ADest, const Cxgeometry::TdxRectF &ASource, TdxGPImageAttributes* AAttributes) = 0 /* overload */;
	virtual void __fastcall Draw(TdxGPCanvas* ACanvas, const System::Types::TRect &ADest, const System::Types::TRect &ASource, TdxGPImageAttributes* AAttributes) = 0 /* overload */;
};

__interface  INTERFACE_UUID("{011BADAA-55B0-4493-9539-5F0811018C00}") IdxGpFlipContent  : public System::IInterface 
{
	virtual void __fastcall Flip(bool AHorizontally, bool AVertically) = 0 ;
};

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGPImageHandle : public Dxsmartimage::TdxSmartImageCustomHandle
{
	typedef Dxsmartimage::TdxSmartImageCustomHandle inherited;
	
private:
	static const System::Word FrameDelayProperty = System::Word(0x5100);
	
	static const System::Word LoopCountProperty = System::Word(0x5101);
	
	unsigned FActiveFrame;
	GUID FDimensionID;
	void *FHandle;
	Dxsmartimage::TdxImageDataFormat FImageFormat;
	Cxgeometry::TdxPointF FImageOrigin;
	float FImageScaleFactor;
	__classmethod TdxGPImageHandle* __fastcall CreateImageHandle(void * AHandle);
	void __fastcall HandleChanged();
	Cxgeometry::TdxRectF __fastcall GetActualSourceRect(const Cxgeometry::TdxRectF &R);
	Dxgdiplusapi::TdxGpImageFlags __fastcall GetFlags();
	Dxgdiplusapi::PixelFormat __fastcall GetPixelFormat();
	bool __fastcall GetPropertyValue(unsigned APropID, TdxGPImagePropertyData &AData);
	void __fastcall SetHandle(void * AValue);
	void __fastcall UpdateImageAttributes();
	
protected:
	void __fastcall FreeHandle();
	virtual System::Types::TSize __fastcall GetSize();
	virtual void __fastcall SetSize(const System::Types::TSize &AValue);
	Dxcoregraphics::TdxAlphaColorDynArray __fastcall GetColorPalette(/* out */ unsigned &AFlags);
	void __fastcall SetColorPalette(const Dxcoregraphics::TdxAlphaColorDynArray AColors, unsigned AFlags);
	Dxsmartimage::TdxImageDataFormat __fastcall GetImageFormat();
	unsigned __fastcall GetActiveFrame();
	unsigned __fastcall GetAnimationFrameCount();
	int __fastcall GetAnimationFrameDelay();
	int __fastcall GetAnimationLoopCount();
	void __fastcall SetActiveFrame(unsigned AValue);
	
public:
	__fastcall TdxGPImageHandle(void * AHandle);
	__fastcall TdxGPImageHandle(int AWidth, int AHeight, const Dxcoregraphics::TRGBColors ABitsRef, Vcl::Graphics::TAlphaFormat AAlphaFormat);
	__fastcall TdxGPImageHandle(int AWidth, int AHeight)/* overload */;
	__fastcall TdxGPImageHandle(int AWidth, int AHeight, Dxgdiplusapi::PixelFormat APixelFormat)/* overload */;
	__fastcall TdxGPImageHandle(const System::Types::TSize &ASize)/* overload */;
	__fastcall virtual ~TdxGPImageHandle();
	TdxGPImageHandle* __fastcall Clone()/* overload */;
	TdxGPImageHandle* __fastcall Clone(const System::Types::TRect &ARect, Dxgdiplusapi::PixelFormat APixelFormat)/* overload */;
	TdxGPImageHandle* __fastcall Clone(const Cxgeometry::TdxRectF &ARect, Dxgdiplusapi::PixelFormat APixelFormat)/* overload */;
	Dxgdiplusapi::BitmapData __fastcall LockBits(const System::Types::TRect &ARect, int ALockMode, Dxgdiplusapi::PixelFormat APixelFormat);
	void __fastcall UnlockBits(const Dxgdiplusapi::BitmapData &AData);
	TdxGPCanvas* __fastcall CreateCanvas();
	virtual bool __fastcall Empty();
	virtual void __fastcall Draw(HDC DC, const Cxgeometry::TdxRectF &ADest, const Cxgeometry::TdxRectF &ASource, System::Byte AAlpha = (System::Byte)(0xff), Dxcoregraphics::_di_IdxColorPalette APalette = Dxcoregraphics::_di_IdxColorPalette())/* overload */;
	virtual void __fastcall Draw(HDC DC, const System::Types::TRect &ADest, const System::Types::TRect &ASource, System::Byte AAlpha = (System::Byte)(0xff), Dxcoregraphics::_di_IdxColorPalette APalette = Dxcoregraphics::_di_IdxColorPalette())/* overload */;
	HIDESBASE void __fastcall Draw(TdxGPCanvas* ACanvas, const Cxgeometry::TdxRectF &ADest, const Cxgeometry::TdxRectF &ASource, TdxGPImageAttributes* AAttributes)/* overload */;
	HIDESBASE void __fastcall Draw(TdxGPCanvas* ACanvas, const System::Types::TRect &ADest, const System::Types::TRect &ASource, TdxGPImageAttributes* AAttributes)/* overload */;
	virtual Vcl::Graphics::TBitmap* __fastcall GetAsBitmap();
	Dxcoregraphics::TdxAlphaColor __fastcall GetPixel(int X, int Y);
	bool __fastcall IsMetafile();
	void __fastcall Resize(const System::Types::TSize &ASize, TdxGPInterpolationMode AInterpolationMode = (TdxGPInterpolationMode)(0x0), Dxgdiplusapi::TdxGpPixelOffsetMode APixelOffsetMode = (Dxgdiplusapi::TdxGpPixelOffsetMode)(0x0));
	void __fastcall SetPixel(int X, int Y, Dxcoregraphics::TdxAlphaColor AColor);
	void __fastcall Flip(bool AHorizontally, bool AVertically);
	__property unsigned ActiveFrame = {read=GetActiveFrame, write=SetActiveFrame, nodefault};
	__property unsigned AnimationFrameCount = {read=GetAnimationFrameCount, nodefault};
	__property int AnimationFrameDelay = {read=GetAnimationFrameDelay, nodefault};
	__property int AnimationLoopCount = {read=GetAnimationLoopCount, nodefault};
	__property Dxgdiplusapi::TdxGpImageFlags Flags = {read=GetFlags, nodefault};
	__property void * Handle = {read=FHandle, write=SetHandle};
	__property Dxsmartimage::TdxImageDataFormat ImageDataFormat = {read=FImageFormat, nodefault};
	__property Dxgdiplusapi::PixelFormat PixelFormat = {read=GetPixelFormat, nodefault};
private:
	void *__IdxImageDataFormat;	// Dxsmartimage::IdxImageDataFormat 
	void *__IdxGPGraphicDraw;	// IdxGPGraphicDraw 
	void *__IdxGpFlipContent;	// IdxGpFlipContent 
	void *__IdxAnimatedImage;	// Dxsmartimage::IdxAnimatedImage 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {19993C97-DF15-4E67-A250-77BACBF5DB64}
	operator Dxsmartimage::_di_IdxImageDataFormat()
	{
		Dxsmartimage::_di_IdxImageDataFormat intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Dxsmartimage::IdxImageDataFormat*(void) { return (Dxsmartimage::IdxImageDataFormat*)&__IdxImageDataFormat; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {12CC0C8A-2C68-4467-AF5F-EBA89E93E1CD}
	operator _di_IdxGPGraphicDraw()
	{
		_di_IdxGPGraphicDraw intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IdxGPGraphicDraw*(void) { return (IdxGPGraphicDraw*)&__IdxGPGraphicDraw; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {011BADAA-55B0-4493-9539-5F0811018C00}
	operator _di_IdxGpFlipContent()
	{
		_di_IdxGpFlipContent intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IdxGpFlipContent*(void) { return (IdxGpFlipContent*)&__IdxGpFlipContent; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {511C08FA-ED2A-4998-95BB-CBAED1D39BA9}
	operator Dxsmartimage::_di_IdxAnimatedImage()
	{
		Dxsmartimage::_di_IdxAnimatedImage intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Dxsmartimage::IdxAnimatedImage*(void) { return (Dxsmartimage::IdxAnimatedImage*)&__IdxAnimatedImage; }
	#endif
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGPImageCodec : public Dxsmartimage::TdxSmartImageCodec
{
	typedef Dxsmartimage::TdxSmartImageCodec inherited;
	
protected:
	__classmethod bool __fastcall CheckHeader(System::Classes::TStream* AStream, const System::AnsiString AHeader);
	__classmethod int __fastcall ReadInteger(System::Classes::TStream* AStream);
	__classmethod System::Word __fastcall ReadWord(System::Classes::TStream* AStream);
	__classmethod GUID __fastcall GetCodecID();
	__classmethod virtual bool __fastcall SaveCore(System::Classes::TStream* AStream, TdxGPImageHandle* AHandle, void * AParameters = (void *)(0x0));
	
public:
	__classmethod virtual bool __fastcall CanSaveImage(Dxsmartimage::TdxSmartImageCustomHandle* AHandle);
	__classmethod virtual bool __fastcall Load(System::Classes::TStream* AStream, /* out */ Dxsmartimage::TdxSmartImageCustomHandle* &AHandle)/* overload */;
	__classmethod virtual bool __fastcall Save(System::Classes::TStream* AStream, Dxsmartimage::TdxSmartImageCustomHandle* AHandle);
public:
	/* TObject.Create */ inline __fastcall TdxGPImageCodec() : Dxsmartimage::TdxSmartImageCodec() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxGPImageCodec() { }
	
	/* Hoisted overloads: */
	
public:
	inline bool __fastcall  Load(const Dxcoregraphics::TRGBColors ABits, Vcl::Graphics::TAlphaFormat AAlphaFormat, int AWidth, int AHeight, /* out */ Dxsmartimage::TdxSmartImageCustomHandle* &AHandle){ return Dxsmartimage::TdxSmartImageCodec::Load(ABits, AAlphaFormat, AWidth, AHeight, AHandle); }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGPImageCodecBMP : public TdxGPImageCodec
{
	typedef TdxGPImageCodec inherited;
	
protected:
	__classmethod virtual Dxsmartimage::TdxImageDataFormat __fastcall ID();
	
public:
	__classmethod virtual bool __fastcall CanLoadFromBits();
	__classmethod virtual bool __fastcall CanLoadStream(System::Classes::TStream* AStream);
	__classmethod virtual System::UnicodeString __fastcall Extensions();
	__classmethod virtual System::UnicodeString __fastcall MimeType();
	__classmethod virtual bool __fastcall GetSize(System::Classes::TStream* AStream, /* out */ System::Types::TSize &ASize);
	__classmethod virtual bool __fastcall Load(const Dxcoregraphics::TRGBColors ABits, Vcl::Graphics::TAlphaFormat AAlphaFormat, int AWidth, int AHeight, /* out */ Dxsmartimage::TdxSmartImageCustomHandle* &AHandle)/* overload */;
public:
	/* TObject.Create */ inline __fastcall TdxGPImageCodecBMP() : TdxGPImageCodec() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxGPImageCodecBMP() { }
	
	/* Hoisted overloads: */
	
public:
	inline bool __fastcall  Load(System::Classes::TStream* AStream, /* out */ Dxsmartimage::TdxSmartImageCustomHandle* &AHandle){ return TdxGPImageCodec::Load(AStream, AHandle); }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGPImageCodecGIF : public TdxGPImageCodec
{
	typedef TdxGPImageCodec inherited;
	
protected:
	__classmethod virtual Vcl::Graphics::TGraphicClass __fastcall GetGraphicClassForRegistrationInVCL();
	__classmethod virtual Dxsmartimage::TdxImageDataFormat __fastcall ID();
	
public:
	__classmethod virtual bool __fastcall CanLoadStream(System::Classes::TStream* AStream);
	__classmethod virtual System::UnicodeString __fastcall Extensions();
	__classmethod virtual System::UnicodeString __fastcall MimeType();
	__classmethod virtual System::Word __fastcall GetClipboardFormatId();
	__classmethod virtual bool __fastcall GetSize(System::Classes::TStream* AStream, /* out */ System::Types::TSize &ASize);
public:
	/* TObject.Create */ inline __fastcall TdxGPImageCodecGIF() : TdxGPImageCodec() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxGPImageCodecGIF() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGPImageCodecJPEG : public TdxGPImageCodec
{
	typedef TdxGPImageCodec inherited;
	
public:
	static const unsigned DefaultQuality = unsigned(0xffffffff);
	
	
private:
	static unsigned FQuality;
	// __classmethod void __fastcall Initialize@();
	static void __fastcall SetQuality(const unsigned Value);
	
protected:
	__classmethod virtual Vcl::Graphics::TGraphicClass __fastcall GetGraphicClassForRegistrationInVCL();
	__classmethod virtual Dxsmartimage::TdxImageDataFormat __fastcall ID();
	__classmethod virtual bool __fastcall SaveCore(System::Classes::TStream* AStream, TdxGPImageHandle* AHandle, void * AParameters = (void *)(0x0));
	
public:
	__classmethod virtual bool __fastcall CanLoadStream(System::Classes::TStream* AStream);
	__classmethod virtual System::UnicodeString __fastcall Extensions();
	__classmethod virtual System::UnicodeString __fastcall MimeType();
	__classmethod virtual System::Word __fastcall GetClipboardFormatId();
	__classmethod virtual bool __fastcall GetSize(System::Classes::TStream* AStream, /* out */ System::Types::TSize &ASize);
	/* static */ __property unsigned Quality = {read=FQuality, write=SetQuality, nodefault};
	
private:
	// __classmethod void __fastcall Destroy@();
public:
	/* TObject.Create */ inline __fastcall TdxGPImageCodecJPEG() : TdxGPImageCodec() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxGPImageCodecJPEG() { }
	
};

#pragma pack(pop)

typedef TdxGPImageCodecJPEG TdxGPImageCodecJPG;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGPImageCodecPNG : public TdxGPImageCodec
{
	typedef TdxGPImageCodec inherited;
	
protected:
	__classmethod virtual Vcl::Graphics::TGraphicClass __fastcall GetGraphicClassForRegistrationInVCL();
	__classmethod virtual Dxsmartimage::TdxImageDataFormat __fastcall ID();
	
public:
	__classmethod virtual bool __fastcall CanLoadStream(System::Classes::TStream* AStream);
	__classmethod virtual System::UnicodeString __fastcall Extensions();
	__classmethod virtual System::UnicodeString __fastcall MimeType();
	__classmethod virtual System::Word __fastcall GetClipboardFormatId();
	__classmethod virtual bool __fastcall GetSize(System::Classes::TStream* AStream, /* out */ System::Types::TSize &ASize);
public:
	/* TObject.Create */ inline __fastcall TdxGPImageCodecPNG() : TdxGPImageCodec() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxGPImageCodecPNG() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGPImageCodecTIFF : public TdxGPImageCodec
{
	typedef TdxGPImageCodec inherited;
	
private:
	#define TdxGPImageCodecTIFF_TIFFHeader1 L"II*\u0000"
	
	#define TdxGPImageCodecTIFF_TIFFHeader2 L"MM\u0000*"
	
	
protected:
	__classmethod virtual Vcl::Graphics::TGraphicClass __fastcall GetGraphicClassForRegistrationInVCL();
	__classmethod virtual Dxsmartimage::TdxImageDataFormat __fastcall ID();
	
public:
	__classmethod virtual bool __fastcall CanLoadStream(System::Classes::TStream* AStream);
	__classmethod virtual System::UnicodeString __fastcall Extensions();
	__classmethod virtual System::UnicodeString __fastcall MimeType();
	__classmethod virtual System::Word __fastcall GetClipboardFormatId();
	__classmethod virtual bool __fastcall GetSize(System::Classes::TStream* AStream, /* out */ System::Types::TSize &ASize);
public:
	/* TObject.Create */ inline __fastcall TdxGPImageCodecTIFF() : TdxGPImageCodec() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxGPImageCodecTIFF() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGPImageCodecEMF : public TdxGPImageCodec
{
	typedef TdxGPImageCodec inherited;
	
protected:
	__classmethod virtual Dxsmartimage::TdxImageDataFormat __fastcall ID();
	__classmethod virtual bool __fastcall SaveCore(System::Classes::TStream* AStream, TdxGPImageHandle* AHandle, void * AParameters = (void *)(0x0));
	
public:
	__classmethod virtual System::UnicodeString __fastcall Extensions();
	__classmethod virtual System::UnicodeString __fastcall MimeType();
public:
	/* TObject.Create */ inline __fastcall TdxGPImageCodecEMF() : TdxGPImageCodec() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxGPImageCodecEMF() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGPImageCodecWMF : public TdxGPImageCodecEMF
{
	typedef TdxGPImageCodecEMF inherited;
	
protected:
	__classmethod virtual Dxsmartimage::TdxImageDataFormat __fastcall ID();
	
public:
	__classmethod virtual System::UnicodeString __fastcall Extensions();
	__classmethod virtual System::UnicodeString __fastcall MimeType();
public:
	/* TObject.Create */ inline __fastcall TdxGPImageCodecWMF() : TdxGPImageCodecEMF() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxGPImageCodecWMF() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGPImageAttributes : public Dxgdiplusapi::TdxGpBase
{
	typedef Dxgdiplusapi::TdxGpBase inherited;
	
private:
	void *FHandle;
	
protected:
	__fastcall TdxGPImageAttributes(const void * AHandle)/* overload */;
	
public:
	__fastcall TdxGPImageAttributes()/* overload */;
	__fastcall virtual ~TdxGPImageAttributes();
	void __fastcall ClearBrushRemapTable();
	void __fastcall ClearColorKey(const Dxgdiplusapi::TdxGpColorAdjustType AType = (Dxgdiplusapi::TdxGpColorAdjustType)(0x0));
	void __fastcall ClearColorMatrix(const Dxgdiplusapi::TdxGpColorAdjustType AType = (Dxgdiplusapi::TdxGpColorAdjustType)(0x0));
	void __fastcall ClearGamma(const Dxgdiplusapi::TdxGpColorAdjustType AType = (Dxgdiplusapi::TdxGpColorAdjustType)(0x0));
	void __fastcall ClearNoOp(const Dxgdiplusapi::TdxGpColorAdjustType AType = (Dxgdiplusapi::TdxGpColorAdjustType)(0x0));
	void __fastcall ClearOutputChannel(const Dxgdiplusapi::TdxGpColorAdjustType AType = (Dxgdiplusapi::TdxGpColorAdjustType)(0x0));
	void __fastcall ClearOutputChannelColorProfile(const Dxgdiplusapi::TdxGpColorAdjustType AType = (Dxgdiplusapi::TdxGpColorAdjustType)(0x0));
	void __fastcall ClearRemapTable(const Dxgdiplusapi::TdxGpColorAdjustType AType = (Dxgdiplusapi::TdxGpColorAdjustType)(0x0));
	void __fastcall ClearThreshold(const Dxgdiplusapi::TdxGpColorAdjustType AType = (Dxgdiplusapi::TdxGpColorAdjustType)(0x0));
	TdxGPImageAttributes* __fastcall Clone();
	void __fastcall GetAdjustedPalette(const Dxgdiplusapi::TGpColorPalette &APalette, const Dxgdiplusapi::TdxGpColorAdjustType AType = (Dxgdiplusapi::TdxGpColorAdjustType)(0x0));
	void __fastcall SetBrushRemapTable(const Dxgdiplusapi::TGpColorMap *AMap, const int AMap_High);
	void __fastcall SetColorKey(const Dxcoregraphics::TdxAlphaColor AColorLow, const Dxcoregraphics::TdxAlphaColor AColorHigh, const Dxgdiplusapi::TdxGpColorAdjustType AType = (Dxgdiplusapi::TdxGpColorAdjustType)(0x0));
	void __fastcall SetColorMatrices(const Dxgdiplusapi::TdxGpColorMatrix &ANewColorMatrix, const Dxgdiplusapi::TdxGpColorMatrix &AGrayMatrix, const Dxgdiplusapi::TdxGpColorMatrixFlags AMode = (Dxgdiplusapi::TdxGpColorMatrixFlags)(0x0), const Dxgdiplusapi::TdxGpColorAdjustType AType = (Dxgdiplusapi::TdxGpColorAdjustType)(0x0));
	void __fastcall SetColorMatrix(Dxgdiplusapi::PdxGpColorMatrix ANewColorMatrix, const Dxgdiplusapi::TdxGpColorMatrixFlags AMode = (Dxgdiplusapi::TdxGpColorMatrixFlags)(0x0), const Dxgdiplusapi::TdxGpColorAdjustType AType = (Dxgdiplusapi::TdxGpColorAdjustType)(0x0));
	void __fastcall SetGamma(float AGamma, const Dxgdiplusapi::TdxGpColorAdjustType AType = (Dxgdiplusapi::TdxGpColorAdjustType)(0x0));
	void __fastcall SetNoOp(const Dxgdiplusapi::TdxGpColorAdjustType AType = (Dxgdiplusapi::TdxGpColorAdjustType)(0x0));
	void __fastcall SetOutputChannel(const Dxgdiplusapi::TdxGpColorChannelFlags AFlags, const Dxgdiplusapi::TdxGpColorAdjustType AType = (Dxgdiplusapi::TdxGpColorAdjustType)(0x0));
	void __fastcall SetOutputChannelColorProfile(const System::UnicodeString AColorProfileFilename, const Dxgdiplusapi::TdxGpColorAdjustType AType = (Dxgdiplusapi::TdxGpColorAdjustType)(0x0));
	void __fastcall SetRemapTable(const Dxgdiplusapi::TGpColorMap *AMap, const int AMap_High, const Dxgdiplusapi::TdxGpColorAdjustType AType = (Dxgdiplusapi::TdxGpColorAdjustType)(0x0));
	void __fastcall SetThreshold(float AThreshold, const Dxgdiplusapi::TdxGpColorAdjustType AType = (Dxgdiplusapi::TdxGpColorAdjustType)(0x0));
	void __fastcall SetWrapMode(const Dxgdiplusapi::WrapMode AMode)/* overload */;
	void __fastcall SetWrapMode(const Dxgdiplusapi::WrapMode AMode, Dxcoregraphics::TdxAlphaColor AColor, bool AClamp = false)/* overload */;
	__property void * Handle = {read=FHandle};
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TdxGPImage : public Dxsmartimage::TdxCustomSmartImage
{
	typedef Dxsmartimage::TdxCustomSmartImage inherited;
	
private:
	HIDESBASE void * __fastcall GetHandle();
	Dxsmartimage::TdxSmartImageCustomHandle* __fastcall GetHandleAsObject();
	HIDESBASE void __fastcall SetHandle(const void * Value);
	void __fastcall SetHandleAsObject(Dxsmartimage::TdxSmartImageCustomHandle* const Value);
	
protected:
	virtual Dxsmartimage::TdxSmartImageCustomHandle* __fastcall CreateCache(const System::Types::TSize &ASize);
	virtual void __fastcall Draw(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall PopulateImageDataFromHandle();
	__property Dxsmartimage::TdxSmartImageCustomHandle* HandleAsObject = {read=GetHandleAsObject, write=SetHandleAsObject};
	
public:
	HIDESBASE TdxGPImage* __fastcall Clone();
	TdxGPCanvas* __fastcall CreateCanvas();
	void __fastcall Flip(bool AHorizontally, bool AVertically);
	TdxGPImage* __fastcall MakeComposition(TdxGPImage* AOverlayImage, System::Byte AOverlayAlpha)/* overload */;
	TdxGPImage* __fastcall MakeComposition(TdxGPImage* AOverlayImage, System::Byte AOverlayAlpha, System::Byte ASourceAlpha)/* overload */;
	HIDESBASE void __fastcall StretchDraw(TdxGPCanvas* ACanvas, const Cxgeometry::TdxRectF &ADest, const Cxgeometry::TdxRectF &ASource, TdxGPImageAttributes* AAttributes, Dxcoregraphics::_di_IdxColorPalette AColorPalette = Dxcoregraphics::_di_IdxColorPalette())/* overload */;
	HIDESBASE void __fastcall StretchDraw(TdxGPCanvas* ACanvas, const System::Types::TRect &ADest, const System::Types::TRect &ASource, TdxGPImageAttributes* AAttributes, Dxcoregraphics::_di_IdxColorPalette AColorPalette = Dxcoregraphics::_di_IdxColorPalette())/* overload */;
	__property void * Handle = {read=GetHandle, write=SetHandle};
public:
	/* TdxCustomSmartImage.Create */ inline __fastcall virtual TdxGPImage()/* overload */ : Dxsmartimage::TdxCustomSmartImage() { }
	/* TdxCustomSmartImage.CreateSize */ inline __fastcall TdxGPImage(const System::Types::TRect &ARect, Dxcoregraphics::TdxAlphaColor AColor)/* overload */ : Dxsmartimage::TdxCustomSmartImage(ARect, AColor) { }
	/* TdxCustomSmartImage.CreateSize */ inline __fastcall TdxGPImage(const System::Types::TSize &ASize, Dxcoregraphics::TdxAlphaColor AColor)/* overload */ : Dxsmartimage::TdxCustomSmartImage(ASize, AColor) { }
	/* TdxCustomSmartImage.CreateSize */ inline __fastcall virtual TdxGPImage(int AWidth, int AHeight, Dxcoregraphics::TdxAlphaColor AColor)/* overload */ : Dxsmartimage::TdxCustomSmartImage(AWidth, AHeight, AColor) { }
	/* TdxCustomSmartImage.CreateFromBitmap */ inline __fastcall virtual TdxGPImage(Vcl::Graphics::TBitmap* ABitmap) : Dxsmartimage::TdxCustomSmartImage(ABitmap) { }
	/* TdxCustomSmartImage.CreateFromHBitmap */ inline __fastcall virtual TdxGPImage(HBITMAP ABitmap) : Dxsmartimage::TdxCustomSmartImage(ABitmap) { }
	/* TdxCustomSmartImage.CreateFromBits */ inline __fastcall virtual TdxGPImage(int AWidth, int AHeight, const Dxcoregraphics::TRGBColors ABits, bool AHasAlphaChannel)/* overload */ : Dxsmartimage::TdxCustomSmartImage(AWidth, AHeight, ABits, AHasAlphaChannel) { }
	/* TdxCustomSmartImage.CreateFromBits */ inline __fastcall virtual TdxGPImage(int AWidth, int AHeight, const Dxcoregraphics::TRGBColors ABits, Vcl::Graphics::TAlphaFormat AAlphaFormat)/* overload */ : Dxsmartimage::TdxCustomSmartImage(AWidth, AHeight, ABits, AAlphaFormat) { }
	/* TdxCustomSmartImage.CreateFromBits */ inline __fastcall virtual TdxGPImage(int AWidth, int AHeight, const Winapi::Windows::PRGBQuad ABits, Vcl::Graphics::TAlphaFormat AAlphaFormat)/* overload */ : Dxsmartimage::TdxCustomSmartImage(AWidth, AHeight, ABits, AAlphaFormat) { }
	/* TdxCustomSmartImage.CreateFromFile */ inline __fastcall TdxGPImage(const System::UnicodeString AFileName) : Dxsmartimage::TdxCustomSmartImage(AFileName) { }
	/* TdxCustomSmartImage.CreateFromStream */ inline __fastcall virtual TdxGPImage(System::Classes::TStream* AStream) : Dxsmartimage::TdxCustomSmartImage(AStream) { }
	/* TdxCustomSmartImage.Destroy */ inline __fastcall virtual ~TdxGPImage() { }
	
	/* Hoisted overloads: */
	
public:
	inline void __fastcall  StretchDraw(HDC DC, const Cxgeometry::TdxRectF &ADest, const Cxgeometry::TdxRectF &ASource, System::Byte AAlpha = (System::Byte)(0xff), Dxcoregraphics::_di_IdxColorPalette APalette = Dxcoregraphics::_di_IdxColorPalette()){ Dxsmartimage::TdxCustomSmartImage::StretchDraw(DC, ADest, ASource, AAlpha, APalette); }
	inline void __fastcall  StretchDraw(HDC DC, const System::Types::TRect &ADest, const System::Types::TRect &ASource, System::Byte AAlpha = (System::Byte)(0xff), Dxcoregraphics::_di_IdxColorPalette APalette = Dxcoregraphics::_di_IdxColorPalette()){ Dxsmartimage::TdxCustomSmartImage::StretchDraw(DC, ADest, ASource, AAlpha, APalette); }
	inline void __fastcall  StretchDraw(HDC DC, const System::Types::TRect &ADest, System::Byte AAlpha = (System::Byte)(0xff), Dxcoregraphics::_di_IdxColorPalette APalette = Dxcoregraphics::_di_IdxColorPalette()){ Dxsmartimage::TdxCustomSmartImage::StretchDraw(DC, ADest, AAlpha, APalette); }
	inline void __fastcall  StretchDraw(HDC DC, const Cxgeometry::TdxRectF &ADest, System::Byte AAlpha = (System::Byte)(0xff), Dxcoregraphics::_di_IdxColorPalette APalette = Dxcoregraphics::_di_IdxColorPalette()){ Dxsmartimage::TdxCustomSmartImage::StretchDraw(DC, ADest, AAlpha, APalette); }
	
};


class PASCALIMPLEMENTATION TdxSmartImage : public TdxGPImage
{
	typedef TdxGPImage inherited;
	
public:
	__classmethod virtual bool __fastcall CanLoadFromStream(System::Classes::TStream* AStream);
public:
	/* TdxCustomSmartImage.Create */ inline __fastcall virtual TdxSmartImage()/* overload */ : TdxGPImage() { }
	/* TdxCustomSmartImage.CreateSize */ inline __fastcall TdxSmartImage(const System::Types::TRect &ARect, Dxcoregraphics::TdxAlphaColor AColor)/* overload */ : TdxGPImage(ARect, AColor) { }
	/* TdxCustomSmartImage.CreateSize */ inline __fastcall TdxSmartImage(const System::Types::TSize &ASize, Dxcoregraphics::TdxAlphaColor AColor)/* overload */ : TdxGPImage(ASize, AColor) { }
	/* TdxCustomSmartImage.CreateSize */ inline __fastcall virtual TdxSmartImage(int AWidth, int AHeight, Dxcoregraphics::TdxAlphaColor AColor)/* overload */ : TdxGPImage(AWidth, AHeight, AColor) { }
	/* TdxCustomSmartImage.CreateFromBitmap */ inline __fastcall virtual TdxSmartImage(Vcl::Graphics::TBitmap* ABitmap) : TdxGPImage(ABitmap) { }
	/* TdxCustomSmartImage.CreateFromHBitmap */ inline __fastcall virtual TdxSmartImage(HBITMAP ABitmap) : TdxGPImage(ABitmap) { }
	/* TdxCustomSmartImage.CreateFromBits */ inline __fastcall virtual TdxSmartImage(int AWidth, int AHeight, const Dxcoregraphics::TRGBColors ABits, bool AHasAlphaChannel)/* overload */ : TdxGPImage(AWidth, AHeight, ABits, AHasAlphaChannel) { }
	/* TdxCustomSmartImage.CreateFromBits */ inline __fastcall virtual TdxSmartImage(int AWidth, int AHeight, const Dxcoregraphics::TRGBColors ABits, Vcl::Graphics::TAlphaFormat AAlphaFormat)/* overload */ : TdxGPImage(AWidth, AHeight, ABits, AAlphaFormat) { }
	/* TdxCustomSmartImage.CreateFromBits */ inline __fastcall virtual TdxSmartImage(int AWidth, int AHeight, const Winapi::Windows::PRGBQuad ABits, Vcl::Graphics::TAlphaFormat AAlphaFormat)/* overload */ : TdxGPImage(AWidth, AHeight, ABits, AAlphaFormat) { }
	/* TdxCustomSmartImage.CreateFromFile */ inline __fastcall TdxSmartImage(const System::UnicodeString AFileName) : TdxGPImage(AFileName) { }
	/* TdxCustomSmartImage.CreateFromStream */ inline __fastcall virtual TdxSmartImage(System::Classes::TStream* AStream) : TdxGPImage(AStream) { }
	/* TdxCustomSmartImage.Destroy */ inline __fastcall virtual ~TdxSmartImage() { }
	
};


class PASCALIMPLEMENTATION TdxSmartGlyph : public TdxSmartImage
{
	typedef TdxSmartImage inherited;
	
private:
	int FSourceDPI;
	int FSourceHeight;
	int FSourceWidth;
	int __fastcall GetSourceHeight();
	int __fastcall GetSourceWidth();
	bool __fastcall IsSourceDPIStored();
	bool __fastcall IsSourceHeightStored();
	bool __fastcall IsSourceWidthStored();
	void __fastcall SetSourceHeight(int AValue);
	void __fastcall SetSourceWidth(int AValue);
	int __fastcall GetSourceDPI();
	void __fastcall SetSourceDPI(int AValue);
	System::Types::TSize __fastcall GetSourceSize();
	
protected:
	bool FTransparent;
	virtual void __fastcall AssignFromSmartImage(Dxsmartimage::TdxCustomSmartImage* AImage);
	virtual void __fastcall CreateHandleFromBitmap(Vcl::Graphics::TBitmap* ABitmap);
	virtual bool __fastcall IsBitmapStream(System::Classes::TStream* AStream);
	
public:
	__fastcall virtual TdxSmartGlyph()/* overload */;
	virtual void __fastcall AfterConstruction();
	
__published:
	__property int SourceDPI = {read=FSourceDPI, write=SetSourceDPI, stored=IsSourceDPIStored, nodefault};
	__property int SourceHeight = {read=GetSourceHeight, write=SetSourceHeight, stored=IsSourceHeightStored, nodefault};
	__property int SourceWidth = {read=GetSourceWidth, write=SetSourceWidth, stored=IsSourceWidthStored, nodefault};
public:
	/* TdxCustomSmartImage.CreateSize */ inline __fastcall TdxSmartGlyph(const System::Types::TRect &ARect, Dxcoregraphics::TdxAlphaColor AColor)/* overload */ : TdxSmartImage(ARect, AColor) { }
	/* TdxCustomSmartImage.CreateSize */ inline __fastcall TdxSmartGlyph(const System::Types::TSize &ASize, Dxcoregraphics::TdxAlphaColor AColor)/* overload */ : TdxSmartImage(ASize, AColor) { }
	/* TdxCustomSmartImage.CreateSize */ inline __fastcall virtual TdxSmartGlyph(int AWidth, int AHeight, Dxcoregraphics::TdxAlphaColor AColor)/* overload */ : TdxSmartImage(AWidth, AHeight, AColor) { }
	/* TdxCustomSmartImage.CreateFromBitmap */ inline __fastcall virtual TdxSmartGlyph(Vcl::Graphics::TBitmap* ABitmap) : TdxSmartImage(ABitmap) { }
	/* TdxCustomSmartImage.CreateFromHBitmap */ inline __fastcall virtual TdxSmartGlyph(HBITMAP ABitmap) : TdxSmartImage(ABitmap) { }
	/* TdxCustomSmartImage.CreateFromBits */ inline __fastcall virtual TdxSmartGlyph(int AWidth, int AHeight, const Dxcoregraphics::TRGBColors ABits, bool AHasAlphaChannel)/* overload */ : TdxSmartImage(AWidth, AHeight, ABits, AHasAlphaChannel) { }
	/* TdxCustomSmartImage.CreateFromBits */ inline __fastcall virtual TdxSmartGlyph(int AWidth, int AHeight, const Dxcoregraphics::TRGBColors ABits, Vcl::Graphics::TAlphaFormat AAlphaFormat)/* overload */ : TdxSmartImage(AWidth, AHeight, ABits, AAlphaFormat) { }
	/* TdxCustomSmartImage.CreateFromBits */ inline __fastcall virtual TdxSmartGlyph(int AWidth, int AHeight, const Winapi::Windows::PRGBQuad ABits, Vcl::Graphics::TAlphaFormat AAlphaFormat)/* overload */ : TdxSmartImage(AWidth, AHeight, ABits, AAlphaFormat) { }
	/* TdxCustomSmartImage.CreateFromFile */ inline __fastcall TdxSmartGlyph(const System::UnicodeString AFileName) : TdxSmartImage(AFileName) { }
	/* TdxCustomSmartImage.CreateFromStream */ inline __fastcall virtual TdxSmartGlyph(System::Classes::TStream* AStream) : TdxSmartImage(AStream) { }
	/* TdxCustomSmartImage.Destroy */ inline __fastcall virtual ~TdxSmartGlyph() { }
	
private:
	void *__IdxSourceSize;	// Dxdpiawareutils::IdxSourceSize 
	void *__IdxSourceDPI;	// Dxdpiawareutils::IdxSourceDPI 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {F8A5DDDA-FE77-45F1-8A75-203767ED5982}
	operator Dxdpiawareutils::_di_IdxSourceSize()
	{
		Dxdpiawareutils::_di_IdxSourceSize intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Dxdpiawareutils::IdxSourceSize*(void) { return (Dxdpiawareutils::IdxSourceSize*)&__IdxSourceSize; }
	#endif
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


class PASCALIMPLEMENTATION TdxPNGImage : public TdxSmartImage
{
	typedef TdxSmartImage inherited;
	
protected:
	virtual Dxsmartimage::TdxSmartImageCodecClass __fastcall GetImageCodec();
	
public:
	virtual void __fastcall SaveToStream(System::Classes::TStream* AStream);
public:
	/* TdxCustomSmartImage.Create */ inline __fastcall virtual TdxPNGImage()/* overload */ : TdxSmartImage() { }
	/* TdxCustomSmartImage.CreateSize */ inline __fastcall TdxPNGImage(const System::Types::TRect &ARect, Dxcoregraphics::TdxAlphaColor AColor)/* overload */ : TdxSmartImage(ARect, AColor) { }
	/* TdxCustomSmartImage.CreateSize */ inline __fastcall TdxPNGImage(const System::Types::TSize &ASize, Dxcoregraphics::TdxAlphaColor AColor)/* overload */ : TdxSmartImage(ASize, AColor) { }
	/* TdxCustomSmartImage.CreateSize */ inline __fastcall virtual TdxPNGImage(int AWidth, int AHeight, Dxcoregraphics::TdxAlphaColor AColor)/* overload */ : TdxSmartImage(AWidth, AHeight, AColor) { }
	/* TdxCustomSmartImage.CreateFromBitmap */ inline __fastcall virtual TdxPNGImage(Vcl::Graphics::TBitmap* ABitmap) : TdxSmartImage(ABitmap) { }
	/* TdxCustomSmartImage.CreateFromHBitmap */ inline __fastcall virtual TdxPNGImage(HBITMAP ABitmap) : TdxSmartImage(ABitmap) { }
	/* TdxCustomSmartImage.CreateFromBits */ inline __fastcall virtual TdxPNGImage(int AWidth, int AHeight, const Dxcoregraphics::TRGBColors ABits, bool AHasAlphaChannel)/* overload */ : TdxSmartImage(AWidth, AHeight, ABits, AHasAlphaChannel) { }
	/* TdxCustomSmartImage.CreateFromBits */ inline __fastcall virtual TdxPNGImage(int AWidth, int AHeight, const Dxcoregraphics::TRGBColors ABits, Vcl::Graphics::TAlphaFormat AAlphaFormat)/* overload */ : TdxSmartImage(AWidth, AHeight, ABits, AAlphaFormat) { }
	/* TdxCustomSmartImage.CreateFromBits */ inline __fastcall virtual TdxPNGImage(int AWidth, int AHeight, const Winapi::Windows::PRGBQuad ABits, Vcl::Graphics::TAlphaFormat AAlphaFormat)/* overload */ : TdxSmartImage(AWidth, AHeight, ABits, AAlphaFormat) { }
	/* TdxCustomSmartImage.CreateFromFile */ inline __fastcall TdxPNGImage(const System::UnicodeString AFileName) : TdxSmartImage(AFileName) { }
	/* TdxCustomSmartImage.CreateFromStream */ inline __fastcall virtual TdxPNGImage(System::Classes::TStream* AStream) : TdxSmartImage(AStream) { }
	/* TdxCustomSmartImage.Destroy */ inline __fastcall virtual ~TdxPNGImage() { }
	
};


class PASCALIMPLEMENTATION TdxJPEGImage : public TdxSmartImage
{
	typedef TdxSmartImage inherited;
	
private:
	unsigned FQuality;
	void __fastcall SetQuality(unsigned AValue);
	
protected:
	virtual Dxsmartimage::TdxSmartImageCodecClass __fastcall GetImageCodec();
	
public:
	__fastcall virtual TdxJPEGImage()/* overload */;
	virtual void __fastcall SaveToStream(System::Classes::TStream* AStream);
	__property unsigned Quality = {read=FQuality, write=SetQuality, nodefault};
public:
	/* TdxCustomSmartImage.CreateSize */ inline __fastcall TdxJPEGImage(const System::Types::TRect &ARect, Dxcoregraphics::TdxAlphaColor AColor)/* overload */ : TdxSmartImage(ARect, AColor) { }
	/* TdxCustomSmartImage.CreateSize */ inline __fastcall TdxJPEGImage(const System::Types::TSize &ASize, Dxcoregraphics::TdxAlphaColor AColor)/* overload */ : TdxSmartImage(ASize, AColor) { }
	/* TdxCustomSmartImage.CreateSize */ inline __fastcall virtual TdxJPEGImage(int AWidth, int AHeight, Dxcoregraphics::TdxAlphaColor AColor)/* overload */ : TdxSmartImage(AWidth, AHeight, AColor) { }
	/* TdxCustomSmartImage.CreateFromBitmap */ inline __fastcall virtual TdxJPEGImage(Vcl::Graphics::TBitmap* ABitmap) : TdxSmartImage(ABitmap) { }
	/* TdxCustomSmartImage.CreateFromHBitmap */ inline __fastcall virtual TdxJPEGImage(HBITMAP ABitmap) : TdxSmartImage(ABitmap) { }
	/* TdxCustomSmartImage.CreateFromBits */ inline __fastcall virtual TdxJPEGImage(int AWidth, int AHeight, const Dxcoregraphics::TRGBColors ABits, bool AHasAlphaChannel)/* overload */ : TdxSmartImage(AWidth, AHeight, ABits, AHasAlphaChannel) { }
	/* TdxCustomSmartImage.CreateFromBits */ inline __fastcall virtual TdxJPEGImage(int AWidth, int AHeight, const Dxcoregraphics::TRGBColors ABits, Vcl::Graphics::TAlphaFormat AAlphaFormat)/* overload */ : TdxSmartImage(AWidth, AHeight, ABits, AAlphaFormat) { }
	/* TdxCustomSmartImage.CreateFromBits */ inline __fastcall virtual TdxJPEGImage(int AWidth, int AHeight, const Winapi::Windows::PRGBQuad ABits, Vcl::Graphics::TAlphaFormat AAlphaFormat)/* overload */ : TdxSmartImage(AWidth, AHeight, ABits, AAlphaFormat) { }
	/* TdxCustomSmartImage.CreateFromFile */ inline __fastcall TdxJPEGImage(const System::UnicodeString AFileName) : TdxSmartImage(AFileName) { }
	/* TdxCustomSmartImage.CreateFromStream */ inline __fastcall virtual TdxJPEGImage(System::Classes::TStream* AStream) : TdxSmartImage(AStream) { }
	/* TdxCustomSmartImage.Destroy */ inline __fastcall virtual ~TdxJPEGImage() { }
	
};


class PASCALIMPLEMENTATION TdxGIFImage : public TdxSmartImage
{
	typedef TdxSmartImage inherited;
	
protected:
	virtual Dxsmartimage::TdxSmartImageCodecClass __fastcall GetImageCodec();
	
public:
	virtual void __fastcall SaveToStream(System::Classes::TStream* AStream);
public:
	/* TdxCustomSmartImage.Create */ inline __fastcall virtual TdxGIFImage()/* overload */ : TdxSmartImage() { }
	/* TdxCustomSmartImage.CreateSize */ inline __fastcall TdxGIFImage(const System::Types::TRect &ARect, Dxcoregraphics::TdxAlphaColor AColor)/* overload */ : TdxSmartImage(ARect, AColor) { }
	/* TdxCustomSmartImage.CreateSize */ inline __fastcall TdxGIFImage(const System::Types::TSize &ASize, Dxcoregraphics::TdxAlphaColor AColor)/* overload */ : TdxSmartImage(ASize, AColor) { }
	/* TdxCustomSmartImage.CreateSize */ inline __fastcall virtual TdxGIFImage(int AWidth, int AHeight, Dxcoregraphics::TdxAlphaColor AColor)/* overload */ : TdxSmartImage(AWidth, AHeight, AColor) { }
	/* TdxCustomSmartImage.CreateFromBitmap */ inline __fastcall virtual TdxGIFImage(Vcl::Graphics::TBitmap* ABitmap) : TdxSmartImage(ABitmap) { }
	/* TdxCustomSmartImage.CreateFromHBitmap */ inline __fastcall virtual TdxGIFImage(HBITMAP ABitmap) : TdxSmartImage(ABitmap) { }
	/* TdxCustomSmartImage.CreateFromBits */ inline __fastcall virtual TdxGIFImage(int AWidth, int AHeight, const Dxcoregraphics::TRGBColors ABits, bool AHasAlphaChannel)/* overload */ : TdxSmartImage(AWidth, AHeight, ABits, AHasAlphaChannel) { }
	/* TdxCustomSmartImage.CreateFromBits */ inline __fastcall virtual TdxGIFImage(int AWidth, int AHeight, const Dxcoregraphics::TRGBColors ABits, Vcl::Graphics::TAlphaFormat AAlphaFormat)/* overload */ : TdxSmartImage(AWidth, AHeight, ABits, AAlphaFormat) { }
	/* TdxCustomSmartImage.CreateFromBits */ inline __fastcall virtual TdxGIFImage(int AWidth, int AHeight, const Winapi::Windows::PRGBQuad ABits, Vcl::Graphics::TAlphaFormat AAlphaFormat)/* overload */ : TdxSmartImage(AWidth, AHeight, ABits, AAlphaFormat) { }
	/* TdxCustomSmartImage.CreateFromFile */ inline __fastcall TdxGIFImage(const System::UnicodeString AFileName) : TdxSmartImage(AFileName) { }
	/* TdxCustomSmartImage.CreateFromStream */ inline __fastcall virtual TdxGIFImage(System::Classes::TStream* AStream) : TdxSmartImage(AStream) { }
	/* TdxCustomSmartImage.Destroy */ inline __fastcall virtual ~TdxGIFImage() { }
	
};


class PASCALIMPLEMENTATION TdxTIFFImage : public TdxSmartImage
{
	typedef TdxSmartImage inherited;
	
protected:
	virtual Dxsmartimage::TdxSmartImageCodecClass __fastcall GetImageCodec();
	
public:
	virtual void __fastcall SaveToStream(System::Classes::TStream* AStream);
public:
	/* TdxCustomSmartImage.Create */ inline __fastcall virtual TdxTIFFImage()/* overload */ : TdxSmartImage() { }
	/* TdxCustomSmartImage.CreateSize */ inline __fastcall TdxTIFFImage(const System::Types::TRect &ARect, Dxcoregraphics::TdxAlphaColor AColor)/* overload */ : TdxSmartImage(ARect, AColor) { }
	/* TdxCustomSmartImage.CreateSize */ inline __fastcall TdxTIFFImage(const System::Types::TSize &ASize, Dxcoregraphics::TdxAlphaColor AColor)/* overload */ : TdxSmartImage(ASize, AColor) { }
	/* TdxCustomSmartImage.CreateSize */ inline __fastcall virtual TdxTIFFImage(int AWidth, int AHeight, Dxcoregraphics::TdxAlphaColor AColor)/* overload */ : TdxSmartImage(AWidth, AHeight, AColor) { }
	/* TdxCustomSmartImage.CreateFromBitmap */ inline __fastcall virtual TdxTIFFImage(Vcl::Graphics::TBitmap* ABitmap) : TdxSmartImage(ABitmap) { }
	/* TdxCustomSmartImage.CreateFromHBitmap */ inline __fastcall virtual TdxTIFFImage(HBITMAP ABitmap) : TdxSmartImage(ABitmap) { }
	/* TdxCustomSmartImage.CreateFromBits */ inline __fastcall virtual TdxTIFFImage(int AWidth, int AHeight, const Dxcoregraphics::TRGBColors ABits, bool AHasAlphaChannel)/* overload */ : TdxSmartImage(AWidth, AHeight, ABits, AHasAlphaChannel) { }
	/* TdxCustomSmartImage.CreateFromBits */ inline __fastcall virtual TdxTIFFImage(int AWidth, int AHeight, const Dxcoregraphics::TRGBColors ABits, Vcl::Graphics::TAlphaFormat AAlphaFormat)/* overload */ : TdxSmartImage(AWidth, AHeight, ABits, AAlphaFormat) { }
	/* TdxCustomSmartImage.CreateFromBits */ inline __fastcall virtual TdxTIFFImage(int AWidth, int AHeight, const Winapi::Windows::PRGBQuad ABits, Vcl::Graphics::TAlphaFormat AAlphaFormat)/* overload */ : TdxSmartImage(AWidth, AHeight, ABits, AAlphaFormat) { }
	/* TdxCustomSmartImage.CreateFromFile */ inline __fastcall TdxTIFFImage(const System::UnicodeString AFileName) : TdxSmartImage(AFileName) { }
	/* TdxCustomSmartImage.CreateFromStream */ inline __fastcall virtual TdxTIFFImage(System::Classes::TStream* AStream) : TdxSmartImage(AStream) { }
	/* TdxCustomSmartImage.Destroy */ inline __fastcall virtual ~TdxTIFFImage() { }
	
};


class PASCALIMPLEMENTATION TdxBMPImage : public TdxSmartImage
{
	typedef TdxSmartImage inherited;
	
protected:
	virtual Dxsmartimage::TdxSmartImageCodecClass __fastcall GetImageCodec();
	
public:
	virtual void __fastcall SaveToStream(System::Classes::TStream* AStream);
public:
	/* TdxCustomSmartImage.Create */ inline __fastcall virtual TdxBMPImage()/* overload */ : TdxSmartImage() { }
	/* TdxCustomSmartImage.CreateSize */ inline __fastcall TdxBMPImage(const System::Types::TRect &ARect, Dxcoregraphics::TdxAlphaColor AColor)/* overload */ : TdxSmartImage(ARect, AColor) { }
	/* TdxCustomSmartImage.CreateSize */ inline __fastcall TdxBMPImage(const System::Types::TSize &ASize, Dxcoregraphics::TdxAlphaColor AColor)/* overload */ : TdxSmartImage(ASize, AColor) { }
	/* TdxCustomSmartImage.CreateSize */ inline __fastcall virtual TdxBMPImage(int AWidth, int AHeight, Dxcoregraphics::TdxAlphaColor AColor)/* overload */ : TdxSmartImage(AWidth, AHeight, AColor) { }
	/* TdxCustomSmartImage.CreateFromBitmap */ inline __fastcall virtual TdxBMPImage(Vcl::Graphics::TBitmap* ABitmap) : TdxSmartImage(ABitmap) { }
	/* TdxCustomSmartImage.CreateFromHBitmap */ inline __fastcall virtual TdxBMPImage(HBITMAP ABitmap) : TdxSmartImage(ABitmap) { }
	/* TdxCustomSmartImage.CreateFromBits */ inline __fastcall virtual TdxBMPImage(int AWidth, int AHeight, const Dxcoregraphics::TRGBColors ABits, bool AHasAlphaChannel)/* overload */ : TdxSmartImage(AWidth, AHeight, ABits, AHasAlphaChannel) { }
	/* TdxCustomSmartImage.CreateFromBits */ inline __fastcall virtual TdxBMPImage(int AWidth, int AHeight, const Dxcoregraphics::TRGBColors ABits, Vcl::Graphics::TAlphaFormat AAlphaFormat)/* overload */ : TdxSmartImage(AWidth, AHeight, ABits, AAlphaFormat) { }
	/* TdxCustomSmartImage.CreateFromBits */ inline __fastcall virtual TdxBMPImage(int AWidth, int AHeight, const Winapi::Windows::PRGBQuad ABits, Vcl::Graphics::TAlphaFormat AAlphaFormat)/* overload */ : TdxSmartImage(AWidth, AHeight, ABits, AAlphaFormat) { }
	/* TdxCustomSmartImage.CreateFromFile */ inline __fastcall TdxBMPImage(const System::UnicodeString AFileName) : TdxSmartImage(AFileName) { }
	/* TdxCustomSmartImage.CreateFromStream */ inline __fastcall virtual TdxBMPImage(System::Classes::TStream* AStream) : TdxSmartImage(AStream) { }
	/* TdxCustomSmartImage.Destroy */ inline __fastcall virtual ~TdxBMPImage() { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGpFastDIB : public Dxcoregraphics::TdxCustomFastDIB
{
	typedef Dxcoregraphics::TdxCustomFastDIB inherited;
	
private:
	void *FHandle;
	
protected:
	virtual void __fastcall Allocate();
	virtual void __fastcall Release();
	
public:
	virtual void __fastcall Clear();
	TdxGPCanvas* __fastcall CreateCanvas();
	__property void * Handle = {read=FHandle};
public:
	/* TdxCustomFastDIB.Create */ inline __fastcall TdxGpFastDIB(int AWidth, int AHeight, bool AClear)/* overload */ : Dxcoregraphics::TdxCustomFastDIB(AWidth, AHeight, AClear) { }
	/* TdxCustomFastDIB.Create */ inline __fastcall TdxGpFastDIB(const System::Types::TRect &R, bool AClear)/* overload */ : Dxcoregraphics::TdxCustomFastDIB(R, AClear) { }
	/* TdxCustomFastDIB.Create */ inline __fastcall TdxGpFastDIB(const System::Types::TSize &S, bool AClear)/* overload */ : Dxcoregraphics::TdxCustomFastDIB(S, AClear) { }
	/* TdxCustomFastDIB.Destroy */ inline __fastcall virtual ~TdxGpFastDIB() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static const System::Int8 DefaultAnimationFrameDelay = System::Int8(0x4b);
extern DELPHI_PACKAGE System::StaticArray<Dxgdiplusapi::TdxGpStringAlignment, 3> dxGpAlignmentToStringAlignment;
extern DELPHI_PACKAGE System::StaticArray<Dxgdiplusapi::TdxGpStringAlignment, 3> dxGpVerticalAlignmentToLineAlignment;
extern DELPHI_PACKAGE System::StaticArray<TdxGPInterpolationMode, 2> dxGpSmoothStretchModeMap;
extern DELPHI_PACKAGE System::StaticArray<Dxgdiplusapi::TdxGpStringFormatFlags, 2> dxGpWordWrapFlagsMap;
extern DELPHI_PACKAGE System::StaticArray<Dxgdiplusapi::TdxGpStringFormatFlags, 2> dxGpRtlReadingFlagsMap;
extern DELPHI_PACKAGE System::StaticArray<Dxgdiplusapi::LinearGradientMode, 4> dxGpBrushGradientModeToLinearGradientMode;
extern DELPHI_PACKAGE TdxGPImageAttributes* __fastcall dxGpGetAlphaBlendAttributes(const System::Byte AAlpha);
extern DELPHI_PACKAGE TdxGPGraphics* __fastcall dxGpBeginPaint(void * AHandle)/* overload */;
extern DELPHI_PACKAGE TdxGPGraphics* __fastcall dxGpBeginPaint(HDC DC, const System::Types::TRect &R)/* overload */;
extern DELPHI_PACKAGE void __fastcall dxGpEndPaint(TdxGPGraphics* &AGraphics);
extern DELPHI_PACKAGE Dxsmartimage::TdxImageDataFormat __fastcall dxGetImageDataFormat(const void * AImage)/* overload */;
extern DELPHI_PACKAGE Dxsmartimage::TdxImageDataFormat __fastcall dxGetImageDataFormat(const GUID &AFormatId)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall dxGetImageDataFormatExtension(Dxsmartimage::TdxImageDataFormat AImageDataFormat);
extern DELPHI_PACKAGE GUID __fastcall dxGetImageEncoder(Dxsmartimage::TdxImageDataFormat AImageDataFormat);
extern DELPHI_PACKAGE GUID __fastcall dxGetImageDecoder(Dxsmartimage::TdxImageDataFormat AImageDataFormat);
extern DELPHI_PACKAGE void __fastcall dxGpDrawImage(void * AGraphics, const System::Types::TRect &ADestRect, const System::Types::TRect &ASourceRect, void * AImage, System::Byte AAlpha = (System::Byte)(0xff), void * AAttributes = (void *)(0x0))/* overload */;
extern DELPHI_PACKAGE void __fastcall dxGpDrawImage(void * AGraphics, const Cxgeometry::TdxRectF &ADestRect, const Cxgeometry::TdxRectF &ASourceRect, void * AImage, System::Byte AAlpha = (System::Byte)(0xff), void * AAttributes = (void *)(0x0))/* overload */;
extern DELPHI_PACKAGE void __fastcall dxGpRightToLeftDependentDraw(TdxGPCanvas* AGPCanvas, const System::Types::TRect &R, bool AIsRightToLeftLayout, System::Sysutils::_di_TProc AProc);
extern DELPHI_PACKAGE int __fastcall dxFontStylesToGpFontStyles(System::Uitypes::TFontStyles AStyles);
extern DELPHI_PACKAGE void __fastcall dxGPDrawText(TdxGPCanvas* AGraphics, const System::UnicodeString AText, const System::Types::TRect &ARect, Vcl::Graphics::TFont* AFont, Dxcoregraphics::TdxAlphaColor ATextColor, System::Classes::TAlignment AHorzAlignment = (System::Classes::TAlignment)(0x0), System::Classes::TVerticalAlignment AVertAlignment = (System::Classes::TVerticalAlignment)(0x2), bool AWordWrap = false, Dxgdiplusapi::TdxGpTextRenderingHint ARendering = (Dxgdiplusapi::TdxGpTextRenderingHint)(0x0), Dxgdiplusapi::TdxGpStringTrimming ATrimming = (Dxgdiplusapi::TdxGpStringTrimming)(0x0), bool ARtlReading = false)/* overload */;
extern DELPHI_PACKAGE void __fastcall dxGPDrawText(TdxGPCanvas* AGraphics, const System::UnicodeString AText, const Cxgeometry::TdxRectF &ARect, Vcl::Graphics::TFont* AFont, Dxcoregraphics::TdxAlphaColor ATextColor, System::Classes::TAlignment AHorzAlignment = (System::Classes::TAlignment)(0x0), System::Classes::TVerticalAlignment AVertAlignment = (System::Classes::TVerticalAlignment)(0x2), bool AWordWrap = false, Dxgdiplusapi::TdxGpTextRenderingHint ARendering = (Dxgdiplusapi::TdxGpTextRenderingHint)(0x0), Dxgdiplusapi::TdxGpStringTrimming ATrimming = (Dxgdiplusapi::TdxGpStringTrimming)(0x0), bool ARtlReading = false)/* overload */;
extern DELPHI_PACKAGE _di_IdxGPHandle __fastcall dxGpGetFontHandle(Vcl::Graphics::TFont* AFont);
extern DELPHI_PACKAGE void __fastcall dxGPDrawGlowText(TdxGPCanvas* AGraphics, const System::UnicodeString AText, const System::Types::TRect &ARect, Vcl::Graphics::TFont* AFont, Dxcoregraphics::TdxAlphaColor ATextColor, Dxcoregraphics::TdxAlphaColor ATextGlowColor);
extern DELPHI_PACKAGE void __fastcall dxGPGetTextRect(TdxGPCanvas* AGraphics, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, bool AWordWrap, const System::Types::TRect &ALayoutRect, /* out */ System::Types::TRect &ATextRect)/* overload */;
extern DELPHI_PACKAGE void __fastcall dxGPGetTextRect(TdxGPCanvas* AGraphics, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, bool AWordWrap, const Cxgeometry::TdxRectF &ALayoutRect, /* out */ Cxgeometry::TdxRectF &ATextRect)/* overload */;
extern DELPHI_PACKAGE void __fastcall dxGPGetTextRect(TdxGPCanvas* AGraphics, const System::UnicodeString AText, void * AGpFont, bool AWordWrap, const Cxgeometry::TdxRectF &ALayoutRect, /* out */ Cxgeometry::TdxRectF &ATextRect)/* overload */;
extern DELPHI_PACKAGE _di_IdxGPHandle __fastcall dxGpGetBrushHandle(Dxcoregraphics::TdxAlphaColor AColor);
extern DELPHI_PACKAGE void __fastcall dxGpFillRect(HDC DC, const System::Types::TRect &R, System::Uitypes::TColor AColor, System::Byte AColorAlpha = (System::Byte)(0xff))/* overload */;
extern DELPHI_PACKAGE void __fastcall dxGpFillRectByGradient(HDC DC, const System::Types::TRect &R, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, Dxgdiplusapi::LinearGradientMode AMode, System::Byte AColor1Alpha = (System::Byte)(0xff), System::Byte AColor2Alpha = (System::Byte)(0xff));
extern DELPHI_PACKAGE bool __fastcall dxGpIsDoubleBufferedNeeded(HDC DC);
extern DELPHI_PACKAGE System::LongBool __fastcall dxGpIsRectVisible(void * AGraphics, const Cxgeometry::TdxRectF &R)/* overload */;
extern DELPHI_PACKAGE System::LongBool __fastcall dxGpIsRectVisible(void * AGraphics, const System::Types::TRect &R)/* overload */;
extern DELPHI_PACKAGE TdxGPBrushGradientMode __fastcall dxGetNearestGradientMode(const double AAngle, /* out */ bool &AInverseOrder);
extern DELPHI_PACKAGE void __fastcall dxGpTilePart(HDC DC, const System::Types::TRect &ADestRect, const System::Types::TRect &ASourceRect, void * AImage);
extern DELPHI_PACKAGE void __fastcall dxGpTilePartEx(void * AGraphics, const System::Types::TRect &ADestRect, const System::Types::TRect &ASourceRect, void * AImage, System::Byte AAlpha = (System::Byte)(0xff));
extern DELPHI_PACKAGE void __fastcall dxGpRoundRect(HDC DC, const System::Types::TRect &R, System::Uitypes::TColor APenColor, System::Uitypes::TColor ABrushColor, int ARadius, int APenWidth = 0x1, System::Byte APenColorAlpha = (System::Byte)(0xff), System::Byte ABrushColorAlpha = (System::Byte)(0xff));
extern DELPHI_PACKAGE TdxGPPaintCanvas* __fastcall dxGPPaintCanvas(void);
extern DELPHI_PACKAGE TdxGPCanvas* __fastcall dxGPMeasureCanvas(void);
}	/* namespace Dxgdiplusclasses */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXGDIPLUSCLASSES)
using namespace Dxgdiplusclasses;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxgdiplusclassesHPP
