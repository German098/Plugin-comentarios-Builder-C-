// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxCustomCanvas.pas' rev: 35.00 (Windows)

#ifndef CxcustomcanvasHPP
#define CxcustomcanvasHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Hash.hpp>
#include <System.ImageList.hpp>
#include <System.UITypes.hpp>
#include <System.Types.hpp>
#include <Winapi.Windows.hpp>
#include <System.SysUtils.hpp>
#include <System.Generics.Collections.hpp>
#include <System.Generics.Defaults.hpp>
#include <System.Classes.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.ImgList.hpp>
#include <cxGeometry.hpp>
#include <dxCore.hpp>
#include <dxCoreClasses.hpp>
#include <dxSmartImage.hpp>
#include <dxGDIPlusAPI.hpp>
#include <dxGDIPlusClasses.hpp>
#include <dxCoreGraphics.hpp>
#include <dxGenerics.hpp>
#include <cxDrawTextUtils.hpp>
#include <dxDPIAwareUtils.hpp>
#include <dxHash.hpp>
#include <dxHashUtils.hpp>

//-- user supplied -----------------------------------------------------------

namespace Cxcustomcanvas
{
//-- forward type declarations -----------------------------------------------
__interface DELPHIINTERFACE IcxControlCanvas;
typedef System::DelphiInterface<IcxControlCanvas> _di_IcxControlCanvas;
__interface DELPHIINTERFACE IcxControlDirectCanvas;
typedef System::DelphiInterface<IcxControlDirectCanvas> _di_IcxControlDirectCanvas;
__interface DELPHIINTERFACE IcxCanvasCacheControl;
typedef System::DelphiInterface<IcxCanvasCacheControl> _di_IcxCanvasCacheControl;
__interface DELPHIINTERFACE IcxCanvasBuffer;
typedef System::DelphiInterface<IcxCanvasBuffer> _di_IcxCanvasBuffer;
__interface DELPHIINTERFACE IcxCustomCanvasSupport;
typedef System::DelphiInterface<IcxCustomCanvasSupport> _di_IcxCustomCanvasSupport;
class DELPHICLASS TdxFillOptions;
class DELPHICLASS TdxStrokeOptions;
class DELPHICLASS TdxFontOptions;
class DELPHICLASS TcxCanvasBasedResource;
struct TcxCanvasBasedResourceCacheKey;
class DELPHICLASS TcxCanvasBasedResourceHandle;
class DELPHICLASS TcxCanvasBasedSharedResources;
class DELPHICLASS TcxCanvasBasedBrush;
class DELPHICLASS TcxCanvasBasedBrushHandle;
class DELPHICLASS TcxCanvasBasedFont;
class DELPHICLASS TcxCanvasBasedFontHandle;
class DELPHICLASS TcxCanvasBasedImage;
class DELPHICLASS TcxCanvasBasedImageList;
class DELPHICLASS TcxCanvasBasedImageListHandle;
class DELPHICLASS TcxCanvasBasedImageListMap;
class DELPHICLASS TcxCanvasBasedPath;
class DELPHICLASS TcxCanvasBasedPen;
class DELPHICLASS TcxCanvasBasedPenHandle;
class DELPHICLASS TcxCanvasBasedTextLayout;
class DELPHICLASS TcxCanvasBasedTextLayoutCustomTransform;
class DELPHICLASS TcxCanvasBasedSharedBrushes;
class DELPHICLASS TcxCanvasBasedSharedFonts;
class DELPHICLASS TcxCanvasBasedSharedImageLists;
class DELPHICLASS TcxCanvasBasedSharedPens;
__interface DELPHIINTERFACE TcxCanvasNativeDrawProc;
typedef System::DelphiInterface<TcxCanvasNativeDrawProc> _di_TcxCanvasNativeDrawProc;
__interface DELPHIINTERFACE TcxCanvasNativeDrawExProc;
typedef System::DelphiInterface<TcxCanvasNativeDrawExProc> _di_TcxCanvasNativeDrawExProc;
class DELPHICLASS TcxCustomCanvas;
class DELPHICLASS TcxCustomGdiBasedCanvas;
class DELPHICLASS TcxGdiBasedCanvas;
class DELPHICLASS TcxGdiCanvasBasedBrushHandle;
class DELPHICLASS TcxGdiCanvasBasedFontHandle;
class DELPHICLASS TcxGdiCanvasBasedImage;
class DELPHICLASS TcxGdiCanvasBasedPath;
class DELPHICLASS TcxGdiCanvasBasedPenHandle;
class DELPHICLASS TcxGdiCanvasBasedTextLayout;
class DELPHICLASS TcxGdiCanvasBasedSharedBrushes;
class DELPHICLASS TcxGdiCanvasBasedSharedFonts;
class DELPHICLASS TcxGdiCanvasBasedSharedImageLists;
class DELPHICLASS TcxGdiCanvasBasedSharedPens;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TcxRotationAngle : unsigned char { ra0, raPlus90, raMinus90, ra180 };

enum DECLSPEC_DENUM TcxImageDrawMode : unsigned char { idmNormal, idmDisabled, idmFaded, idmGrayScale, idmDingy, idmShadowed };

__interface  INTERFACE_UUID("{E40B5E3C-CD3C-4D2C-81DA-2A41800CA183}") IcxControlCanvas  : public System::IInterface 
{
	virtual void __fastcall BeginPaint() = 0 ;
	virtual void __fastcall EndPaint() = 0 ;
};

__interface  INTERFACE_UUID("{0920AC2D-5CED-4DF4-ABCB-4D12248AC63D}") IcxControlDirectCanvas  : public IcxControlCanvas 
{
	virtual void __fastcall CopyToDC(HDC DC) = 0 /* overload */;
	virtual void __fastcall CopyToDC(HDC DC, const System::Types::TRect &ATargetRect, const System::Types::TRect &ASourceRect) = 0 /* overload */;
	virtual void __fastcall SetWndHandle(HWND AHandle) = 0 ;
};

__interface  INTERFACE_UUID("{A1DEDC74-DBA2-4EAC-BC91-5016E48F4E7B}") IcxCanvasCacheControl  : public System::IInterface 
{
	virtual void __fastcall FlushCache() = 0 ;
};

__interface  INTERFACE_UUID("{C5B683CB-EC4A-41AA-AE0D-DBF0EE320C9C}") IcxCanvasBuffer  : public System::IInterface 
{
	virtual void __fastcall CopyToDC(HDC DC) = 0 ;
	virtual void __fastcall Invalidate() = 0 ;
	virtual bool __fastcall IsValid() = 0 ;
};

__interface  INTERFACE_UUID("{F0C3C819-F9BB-4ECF-97D0-F274B0EBB658}") IcxCustomCanvasSupport  : public System::IInterface 
{
	
};

enum class DECLSPEC_DENUM TdxFillOptionsMode : unsigned char { Clear, Solid, Gradient, Texture, Hatch };

enum class DECLSPEC_DENUM TdxFillOptionsGradientMode : unsigned char { Horizontal, Vertical, ForwardDiagonal, BackwardDiagonal };

enum class DECLSPEC_DENUM TdxFillOptionsHatchStyle : unsigned char { Horizontal, Vertical, ForwardDiagonal, BackwardDiagonal, Cross, DiagonalCross, Percent05, Percent10, Percent20, Percent25, Percent30, Percent40, Percent50, Percent60, Percent70, Percent75, Percent80, Percent90, LightDownwardDiagonal, LightUpwardDiagonal, DarkDownwardDiagonal, DarkUpwardDiagonal, WideDownwardDiagonal, WideUpwardDiagonal, LightVertical, LightHorizontal, NarrowVertical, NarrowHorizontal, DarkVertical, DarkHorizontal, DashedDownwardDiagonal, DashedUpwardDiagonal, DashedHorizontal, DashedVertical, SmallConfetti, LargeConfetti, ZigZag, Wave, DiagonalBrick, HorizontalBrick, Weave, Plaid, Divot, DottedGrid, DottedDiamond, Shingle, Trellis, Sphere, SmallGrid, SmallCheckerBoard, 
	LargeCheckerBoard, OutlinedDiamond, SolidDiamond };

class PASCALIMPLEMENTATION TdxFillOptions : public Dxcoreclasses::TcxLockablePersistent
{
	typedef Dxcoreclasses::TcxLockablePersistent inherited;
	
private:
	Dxcoregraphics::TdxAlphaColor FColor;
	Dxcoregraphics::TdxAlphaColor FColor2;
	TdxFillOptionsGradientMode FGradientMode;
	TdxFillOptionsHatchStyle FHatchStyle;
	TdxFillOptionsMode FMode;
	Dxgdiplusclasses::TdxSmartImage* FTexture;
	System::Classes::TNotifyEvent FOnChange;
	TcxCanvasBasedBrush* FCachedBrush;
	Dxcoregraphics::TdxAlphaColor __fastcall GetActualColor();
	Dxcoregraphics::TdxAlphaColor __fastcall GetActualColor2();
	void __fastcall SetColor(Dxcoregraphics::TdxAlphaColor AValue);
	void __fastcall SetColor2(Dxcoregraphics::TdxAlphaColor AValue);
	void __fastcall SetGradientMode(TdxFillOptionsGradientMode AValue);
	void __fastcall SetHatchStyle(TdxFillOptionsHatchStyle AValue);
	void __fastcall SetMode(TdxFillOptionsMode AValue);
	void __fastcall SetTexture(Dxgdiplusclasses::TdxSmartImage* AValue);
	bool __fastcall IsModeStored();
	bool __fastcall IsTextureStored();
	void __fastcall TextureChangeHandler(System::TObject* Sender);
	
protected:
	Dxcoregraphics::_di_TdxAlphaColorFunc FOnGetDefaultColor;
	Dxcoregraphics::_di_TdxAlphaColorFunc FOnGetDefaultColor2;
	virtual void __fastcall DoAssign(System::Classes::TPersistent* Source);
	virtual void __fastcall DoChanged();
	
public:
	__fastcall virtual TdxFillOptions(System::Classes::TPersistent* AOwner)/* overload */;
	__fastcall TdxFillOptions(System::Classes::TPersistent* AOwner, Dxcoregraphics::_di_TdxAlphaColorFunc AGetDefaultColorFunc, Dxcoregraphics::_di_TdxAlphaColorFunc AGetDefaultColor2Func)/* overload */;
	__fastcall virtual ~TdxFillOptions();
	void __fastcall FlushCache();
	TcxCanvasBasedBrush* __fastcall GetHandle(TcxCustomCanvas* ACanvas);
	__property Dxcoregraphics::TdxAlphaColor ActualColor = {read=GetActualColor, nodefault};
	__property Dxcoregraphics::TdxAlphaColor ActualColor2 = {read=GetActualColor2, nodefault};
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	
__published:
	__property Dxcoregraphics::TdxAlphaColor Color = {read=FColor, write=SetColor, default=66051};
	__property Dxcoregraphics::TdxAlphaColor Color2 = {read=FColor2, write=SetColor2, default=66051};
	__property TdxFillOptionsGradientMode GradientMode = {read=FGradientMode, write=SetGradientMode, default=0};
	__property TdxFillOptionsHatchStyle HatchStyle = {read=FHatchStyle, write=SetHatchStyle, default=0};
	__property Dxgdiplusclasses::TdxSmartImage* Texture = {read=FTexture, write=SetTexture, stored=IsTextureStored};
	__property TdxFillOptionsMode Mode = {read=FMode, write=SetMode, stored=IsModeStored, nodefault};
private:
	void *__IcxCanvasCacheControl;	// IcxCanvasCacheControl 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {A1DEDC74-DBA2-4EAC-BC91-5016E48F4E7B}
	operator _di_IcxCanvasCacheControl()
	{
		_di_IcxCanvasCacheControl intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IcxCanvasCacheControl*(void) { return (IcxCanvasCacheControl*)&__IcxCanvasCacheControl; }
	#endif
	
};


enum class DECLSPEC_DENUM TdxStrokeStyle : unsigned char { Solid, Dash, Dot, DashDot, DashDotDot };

class PASCALIMPLEMENTATION TdxStrokeOptions : public Dxcoreclasses::TcxLockablePersistent
{
	typedef Dxcoreclasses::TcxLockablePersistent inherited;
	
private:
	Dxcoregraphics::TdxAlphaColor FColor;
	TdxStrokeStyle FStyle;
	float FWidth;
	System::Classes::TNotifyEvent FOnChange;
	TcxCanvasBasedPen* FCachedPen;
	Dxcoregraphics::TdxAlphaColor __fastcall GetActualColor();
	bool __fastcall IsWidthStored();
	void __fastcall SetColor(Dxcoregraphics::TdxAlphaColor AValue);
	void __fastcall SetStyle(TdxStrokeStyle AValue);
	void __fastcall SetWidth(float AValue);
	
protected:
	Dxcoregraphics::_di_TdxAlphaColorFunc FOnGetDefaultColor;
	virtual void __fastcall DoAssign(System::Classes::TPersistent* Source);
	virtual void __fastcall DoChanged();
	virtual void __fastcall DoChangeScale(int M, int D);
	
public:
	__fastcall virtual TdxStrokeOptions(System::Classes::TPersistent* AOwner)/* overload */;
	__fastcall TdxStrokeOptions(System::Classes::TPersistent* AOwner, Dxcoregraphics::_di_TdxAlphaColorFunc AGetDefaultColorFunc)/* overload */;
	__fastcall virtual ~TdxStrokeOptions();
	void __fastcall ChangeScale(int M, int D);
	void __fastcall FlushCache();
	TcxCanvasBasedPen* __fastcall GetHandle(TcxCustomCanvas* ACanvas);
	__property Dxcoregraphics::TdxAlphaColor ActualColor = {read=GetActualColor, nodefault};
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	
__published:
	__property Dxcoregraphics::TdxAlphaColor Color = {read=FColor, write=SetColor, default=66051};
	__property TdxStrokeStyle Style = {read=FStyle, write=SetStyle, default=0};
	__property float Width = {read=FWidth, write=SetWidth, stored=IsWidthStored};
private:
	void *__IcxCanvasCacheControl;	// IcxCanvasCacheControl 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {A1DEDC74-DBA2-4EAC-BC91-5016E48F4E7B}
	operator _di_IcxCanvasCacheControl()
	{
		_di_IcxCanvasCacheControl intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IcxCanvasCacheControl*(void) { return (IcxCanvasCacheControl*)&__IcxCanvasCacheControl; }
	#endif
	
};


enum class DECLSPEC_DENUM TdxFontPitch : unsigned char { Default, Fixed, Variable };

enum class DECLSPEC_DENUM TdxFontQuality : unsigned char { Default, Draft, Proof, NonAntialiased, Antialiased, ClearType, ClearTypeNatural };

class PASCALIMPLEMENTATION TdxFontOptions : public Dxcoreclasses::TcxLockablePersistent
{
	typedef Dxcoreclasses::TcxLockablePersistent inherited;
	
private:
	System::Uitypes::TFontCharset FCharset;
	int FHeight;
	System::Uitypes::TFontName FName;
	TdxFontPitch FPitch;
	TdxFontQuality FQuality;
	System::Uitypes::TFontStyles FStyle;
	TcxCanvasBasedFont* FCachedFont;
	System::Classes::TNotifyEvent FOnChange;
	int __fastcall GetSize();
	bool __fastcall GetStyleState(System::Uitypes::TFontStyle AStyle);
	void __fastcall SetCharset(System::Uitypes::TFontCharset AValue);
	void __fastcall SetHeight(int AValue);
	void __fastcall SetName(const System::Uitypes::TFontName AValue);
	void __fastcall SetPitch(TdxFontPitch AValue);
	void __fastcall SetQuality(TdxFontQuality AValue);
	void __fastcall SetSize(int AValue);
	void __fastcall SetStyle(System::Uitypes::TFontStyles AValue);
	void __fastcall SetStyleState(System::Uitypes::TFontStyle AStyle, bool AValue);
	bool __fastcall IsNameStored();
	bool __fastcall IsSizeStored();
	
protected:
	System::UnicodeString FDefaultName;
	int FDefaultSize;
	virtual void __fastcall AssignTo(System::Classes::TPersistent* Dest);
	virtual void __fastcall DoAssign(System::Classes::TPersistent* Source);
	virtual void __fastcall DoChanged();
	
public:
	__fastcall virtual TdxFontOptions(System::Classes::TPersistent* AOwner)/* overload */;
	__fastcall TdxFontOptions(System::Classes::TPersistent* AOwner, const System::Uitypes::TFontName ADefaultName, const int ADefaultSize)/* overload */;
	__fastcall virtual ~TdxFontOptions();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall ChangeScale(int M, int D);
	void __fastcall FlushCache();
	TcxCanvasBasedFont* __fastcall GetHandle(TcxCustomCanvas* ACanvas);
	__property int Height = {read=FHeight, write=SetHeight, nodefault};
	__property System::Uitypes::TFontStyles Style = {read=FStyle, write=SetStyle, nodefault};
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	
__published:
	__property bool Bold = {read=GetStyleState, write=SetStyleState, index=0, default=0};
	__property System::Uitypes::TFontCharset Charset = {read=FCharset, write=SetCharset, default=1};
	__property System::Uitypes::TFontName Name = {read=FName, write=SetName, stored=IsNameStored};
	__property TdxFontPitch Pitch = {read=FPitch, write=SetPitch, default=0};
	__property bool Italic = {read=GetStyleState, write=SetStyleState, index=1, default=0};
	__property int Size = {read=GetSize, write=SetSize, stored=IsSizeStored, nodefault};
	__property bool StrikeOut = {read=GetStyleState, write=SetStyleState, index=3, default=0};
	__property TdxFontQuality Quality = {read=FQuality, write=SetQuality, default=0};
	__property bool Underline = {read=GetStyleState, write=SetStyleState, index=2, default=0};
private:
	void *__IcxCanvasCacheControl;	// IcxCanvasCacheControl 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {A1DEDC74-DBA2-4EAC-BC91-5016E48F4E7B}
	operator _di_IcxCanvasCacheControl()
	{
		_di_IcxCanvasCacheControl intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IcxCanvasCacheControl*(void) { return (IcxCanvasCacheControl*)&__IcxCanvasCacheControl; }
	#endif
	
};


typedef TcxCanvasBasedResource* *PcxCanvasBasedResource;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCanvasBasedResource : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxCustomCanvas* FCanvas;
	TcxCanvasBasedResourceHandle* FHandle;
	
protected:
	void __fastcall CheckState();
	
public:
	__fastcall TcxCanvasBasedResource(TcxCustomCanvas* ACanvas, TcxCanvasBasedResourceHandle* AHandle);
	virtual void __fastcall BeforeDestruction();
	virtual bool __fastcall IsEmpty();
	virtual void __fastcall Release();
	__property TcxCustomCanvas* Canvas = {read=FCanvas};
	__property TcxCanvasBasedResourceHandle* Handle = {read=FHandle};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCanvasBasedResource() { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TcxCanvasBasedResourceCacheKey
{
public:
	void *Owner;
	System::Types::TSize Size;
	int Part;
	int State;
	System::Word TargetDPI;
	static TcxCanvasBasedResourceCacheKey __fastcall Create(void * AOwner, const System::Types::TSize &ASize, int AState, int APart = 0x0, System::Word ATargetDPI = (System::Word)(0x60));
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCanvasBasedResourceHandle : public Dxhashutils::TdxHashTableItem
{
	typedef Dxhashutils::TdxHashTableItem inherited;
	
protected:
	virtual void __fastcall CreateNativeHandle(TcxCustomCanvas* ACanvas) = 0 ;
	virtual void __fastcall FreeNativeHandle() = 0 ;
	
public:
	__fastcall TcxCanvasBasedResourceHandle();
	__fastcall virtual ~TcxCanvasBasedResourceHandle();
	virtual bool __fastcall IsEmpty();
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCanvasBasedSharedResources : public TcxCanvasBasedResource
{
	typedef TcxCanvasBasedResource inherited;
	
private:
	Dxhashutils::TdxHashTable* FHashTable;
	
public:
	__fastcall TcxCanvasBasedSharedResources(TcxCustomCanvas* ACanvas);
	__fastcall virtual ~TcxCanvasBasedSharedResources();
	virtual void __fastcall Release();
	TcxCanvasBasedResourceHandle* __fastcall Share(TcxCanvasBasedResourceHandle* AResource);
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCanvasBasedBrush : public TcxCanvasBasedResource
{
	typedef TcxCanvasBasedResource inherited;
	
public:
	/* TcxCanvasBasedResource.Create */ inline __fastcall TcxCanvasBasedBrush(TcxCustomCanvas* ACanvas, TcxCanvasBasedResourceHandle* AHandle) : TcxCanvasBasedResource(ACanvas, AHandle) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCanvasBasedBrush() { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCanvasBasedBrushHandleClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCanvasBasedBrushHandle : public TcxCanvasBasedResourceHandle
{
	typedef TcxCanvasBasedResourceHandle inherited;
	
protected:
	Dxcoregraphics::TdxAlphaColor FColor1;
	Dxcoregraphics::TdxAlphaColor FColor2;
	Dxgdiplusclasses::TdxGPBrushGradientMode FGradientMode;
	Dxgdiplusapi::HatchStyle FHatchStyle;
	TdxFillOptionsMode FMode;
	Dxgdiplusclasses::TdxSmartImage* FTexture;
	virtual void __fastcall CalculateHash(int &AHash)/* overload */;
	virtual bool __fastcall DoIsEqual(Dxhashutils::TdxHashTableItem* const AItem);
	
public:
	__fastcall TcxCanvasBasedBrushHandle(Dxcoregraphics::TdxAlphaColor AColor)/* overload */;
	__fastcall TcxCanvasBasedBrushHandle(TdxFillOptions* AOptions)/* overload */;
	__fastcall virtual ~TcxCanvasBasedBrushHandle();
	/* Hoisted overloads: */
	
protected:
	inline void __fastcall  CalculateHash(){ Dxhashutils::TdxHashTableItem::CalculateHash(); }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCanvasBasedFont : public TcxCanvasBasedResource
{
	typedef TcxCanvasBasedResource inherited;
	
private:
	int __fastcall GetLineHeight();
	
public:
	virtual bool __fastcall IsEmpty();
	__property int LineHeight = {read=GetLineHeight, nodefault};
public:
	/* TcxCanvasBasedResource.Create */ inline __fastcall TcxCanvasBasedFont(TcxCustomCanvas* ACanvas, TcxCanvasBasedResourceHandle* AHandle) : TcxCanvasBasedResource(ACanvas, AHandle) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCanvasBasedFont() { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCanvasBasedFontHandleClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCanvasBasedFontHandle : public TcxCanvasBasedResourceHandle
{
	typedef TcxCanvasBasedResourceHandle inherited;
	
private:
	int FLineHeight;
	
protected:
	System::Uitypes::TFontCharset FCharset;
	int FHeight;
	System::Uitypes::TFontName FName;
	TdxFontPitch FPitch;
	TdxFontQuality FQuality;
	System::Uitypes::TFontStyles FStyle;
	virtual void __fastcall CalculateHash(int &AHash)/* overload */;
	void __fastcall Initialize(Vcl::Graphics::TFont* AFont);
	virtual int __fastcall DoGetLineHeight(TcxCustomCanvas* ACanvas);
	virtual bool __fastcall DoIsEqual(Dxhashutils::TdxHashTableItem* const AItem);
	
public:
	__fastcall virtual TcxCanvasBasedFontHandle(Vcl::Graphics::TFont* const AFont, Dxcore::TdxObjectOwnership AOwnership)/* overload */;
	__fastcall TcxCanvasBasedFontHandle(TdxFontOptions* const AFont)/* overload */;
	int __fastcall GetLineHeight(TcxCustomCanvas* ACanvas);
	__property System::Uitypes::TFontStyles Style = {read=FStyle, nodefault};
public:
	/* TcxCanvasBasedResourceHandle.Destroy */ inline __fastcall virtual ~TcxCanvasBasedFontHandle() { }
	
	/* Hoisted overloads: */
	
protected:
	inline void __fastcall  CalculateHash(){ Dxhashutils::TdxHashTableItem::CalculateHash(); }
	
};

#pragma pack(pop)

typedef TcxCanvasBasedImage* *PcxCanvasBasedImage;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCanvasBasedImage : public TcxCanvasBasedResource
{
	typedef TcxCanvasBasedResource inherited;
	
private:
	int FHeight;
	int FWidth;
	System::Types::TRect __fastcall GetClientRect();
	System::Types::TSize __fastcall GetSize();
	
public:
	__fastcall TcxCanvasBasedImage(TcxCustomCanvas* ACanvas, int AWidth, int AHeight);
	virtual void __fastcall Draw(const Cxgeometry::TdxRectF &ATargetRect, System::Byte AAlpha = (System::Byte)(0xff))/* overload */;
	virtual void __fastcall Draw(const System::Types::TRect &ATargetRect, System::Byte AAlpha = (System::Byte)(0xff))/* overload */;
	virtual void __fastcall Draw(const Cxgeometry::TdxRectF &ATargetRect, const Cxgeometry::TdxRectF &ASourceRect, System::Byte AAlpha = (System::Byte)(0xff))/* overload */;
	virtual void __fastcall Draw(const System::Types::TRect &ATargetRect, const System::Types::TRect &ASourceRect, System::Byte AAlpha = (System::Byte)(0xff))/* overload */;
	virtual bool __fastcall IsEmpty();
	__property System::Types::TRect ClientRect = {read=GetClientRect};
	__property int Height = {read=FHeight, nodefault};
	__property System::Types::TSize Size = {read=GetSize};
	__property int Width = {read=FWidth, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCanvasBasedImage() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCanvasBasedImageList : public TcxCanvasBasedResource
{
	typedef TcxCanvasBasedResource inherited;
	
private:
	TcxCanvasBasedImageListHandle* __fastcall GetHandle();
	bool __fastcall TryGetImage(int AImageIndex, int AOverlayIndex, TcxImageDrawMode AMode, const Dxcoregraphics::_di_IdxColorPalette AColorPalette, /* out */ TcxCanvasBasedImage* &AImage);
	
public:
	void __fastcall Draw(const Cxgeometry::TdxRectF &R, int AImageIndex, int AOverlayIndex, TcxImageDrawMode AMode, System::Byte AAlpha = (System::Byte)(0xff), const Dxcoregraphics::_di_IdxColorPalette AColorPalette = Dxcoregraphics::_di_IdxColorPalette())/* overload */;
	void __fastcall Draw(const Cxgeometry::TdxRectF &R, int AImageIndex, TcxImageDrawMode AMode, System::Byte AAlpha = (System::Byte)(0xff), const Dxcoregraphics::_di_IdxColorPalette AColorPalette = Dxcoregraphics::_di_IdxColorPalette())/* overload */;
	void __fastcall Draw(const System::Types::TRect &R, int AImageIndex, int AOverlayIndex, TcxImageDrawMode AMode, System::Byte AAlpha = (System::Byte)(0xff), const Dxcoregraphics::_di_IdxColorPalette AColorPalette = Dxcoregraphics::_di_IdxColorPalette())/* overload */;
	void __fastcall Draw(const System::Types::TRect &R, int AImageIndex, TcxImageDrawMode AMode, System::Byte AAlpha = (System::Byte)(0xff), const Dxcoregraphics::_di_IdxColorPalette AColorPalette = Dxcoregraphics::_di_IdxColorPalette())/* overload */;
	System::Types::TSize __fastcall GetSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	__property TcxCanvasBasedImageListHandle* Handle = {read=GetHandle};
public:
	/* TcxCanvasBasedResource.Create */ inline __fastcall TcxCanvasBasedImageList(TcxCustomCanvas* ACanvas, TcxCanvasBasedResourceHandle* AHandle) : TcxCanvasBasedResource(ACanvas, AHandle) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCanvasBasedImageList() { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCanvasBasedImageListHandleClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCanvasBasedImageListHandle : public TcxCanvasBasedResourceHandle
{
	typedef TcxCanvasBasedResourceHandle inherited;
	
private:
	System::TObject* FCache;
	Vcl::Imglist::TChangeLink* FChangeLink;
	bool FUseNativeDrawing;
	void __fastcall ChangeHandler(System::TObject* Sender);
	
protected:
	Vcl::Imglist::TCustomImageList* FImageList;
	virtual void __fastcall CalculateHash(int &AHash)/* overload */;
	virtual void __fastcall CreateNativeHandle(TcxCustomCanvas* ACanvas);
	virtual void __fastcall FreeNativeHandle();
	virtual bool __fastcall DoIsEqual(Dxhashutils::TdxHashTableItem* const AItem);
	
public:
	__fastcall TcxCanvasBasedImageListHandle(Vcl::Imglist::TCustomImageList* AImageList);
	System::Types::TSize __fastcall GetSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual bool __fastcall IsEmpty();
	bool __fastcall TryGetImage(TcxCustomCanvas* ACanvas, int AImageIndex, int AOverlayIndex, TcxImageDrawMode AMode, const Dxcoregraphics::_di_IdxColorPalette AColorPalette, /* out */ TcxCanvasBasedImage* &AImage);
public:
	/* TcxCanvasBasedResourceHandle.Destroy */ inline __fastcall virtual ~TcxCanvasBasedImageListHandle() { }
	
	/* Hoisted overloads: */
	
protected:
	inline void __fastcall  CalculateHash(){ Dxhashutils::TdxHashTableItem::CalculateHash(); }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCanvasBasedImageListMap : public TcxCanvasBasedResource
{
	typedef TcxCanvasBasedResource inherited;
	
private:
	Dxcoreclasses::TcxFreeNotificator* FFreeNotificator;
	Dxgenerics::TdxObjectDictionary* FMap;
	void __fastcall FreeNotificationHandler(System::Classes::TComponent* Sender);
	
public:
	__fastcall TcxCanvasBasedImageListMap(TcxCustomCanvas* ACanvas);
	__fastcall virtual ~TcxCanvasBasedImageListMap();
	void __fastcall Clear();
	TcxCanvasBasedImageList* __fastcall GetOrCreate(Vcl::Imglist::TCustomImageList* AImageList);
	void __fastcall Remove(Vcl::Imglist::TCustomImageList* AImageList);
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCanvasBasedPath : public TcxCanvasBasedResource
{
	typedef TcxCanvasBasedResource inherited;
	
public:
	virtual void __fastcall AddArc(const Cxgeometry::TdxRectF &AEllipse, const float AStartAngle, const float ASweepAngle) = 0 ;
	virtual void __fastcall AddLine(const Cxgeometry::TdxPointF &P1, const Cxgeometry::TdxPointF &P2);
	void __fastcall AddPolyline(const Cxgeometry::TdxPointF *Points, const int Points_High)/* overload */;
	virtual void __fastcall AddPolyline(Cxgeometry::PdxPointF Points, int Count) = 0 /* overload */;
	virtual void __fastcall FigureClose() = 0 ;
	virtual void __fastcall FigureStart() = 0 ;
public:
	/* TcxCanvasBasedResource.Create */ inline __fastcall TcxCanvasBasedPath(TcxCustomCanvas* ACanvas, TcxCanvasBasedResourceHandle* AHandle) : TcxCanvasBasedResource(ACanvas, AHandle) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCanvasBasedPath() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCanvasBasedPen : public TcxCanvasBasedResource
{
	typedef TcxCanvasBasedResource inherited;
	
public:
	/* TcxCanvasBasedResource.Create */ inline __fastcall TcxCanvasBasedPen(TcxCustomCanvas* ACanvas, TcxCanvasBasedResourceHandle* AHandle) : TcxCanvasBasedResource(ACanvas, AHandle) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCanvasBasedPen() { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCanvasBasedPenHandleClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCanvasBasedPenHandle : public TcxCanvasBasedResourceHandle
{
	typedef TcxCanvasBasedResourceHandle inherited;
	
protected:
	Dxcoregraphics::TdxAlphaColor FColor;
	TdxStrokeStyle FStyle;
	float FWidth;
	virtual void __fastcall CalculateHash(int &AHash)/* overload */;
	virtual bool __fastcall DoIsEqual(Dxhashutils::TdxHashTableItem* const AItem);
	
public:
	__fastcall TcxCanvasBasedPenHandle(Dxcoregraphics::TdxAlphaColor AColor, float AWidth, TdxStrokeStyle AStyle)/* overload */;
	__fastcall TcxCanvasBasedPenHandle(TdxStrokeOptions* AOptions)/* overload */;
	__property TdxStrokeStyle Style = {read=FStyle, nodefault};
	__property float Width = {read=FWidth};
public:
	/* TcxCanvasBasedResourceHandle.Destroy */ inline __fastcall virtual ~TcxCanvasBasedPenHandle() { }
	
	/* Hoisted overloads: */
	
protected:
	inline void __fastcall  CalculateHash(){ Dxhashutils::TdxHashTableItem::CalculateHash(); }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCanvasBasedTextLayout : public TcxCanvasBasedResource
{
	typedef TcxCanvasBasedResource inherited;
	
private:
	TcxCanvasBasedBrushHandle* FFill;
	bool FIsDirty;
	int FMaxHeight;
	int FMaxRowCount;
	int FMaxWidth;
	System::Types::TRect FPadding;
	System::Types::TSize FSize;
	TcxCanvasBasedPenHandle* FStroke;
	System::Types::TPoint __fastcall CalculateOrigin(const System::Types::TRect &ARect, const System::Types::TSize &ASize);
	System::Types::TRect __fastcall FloatRectToRect(const Cxgeometry::TdxRectF &R);
	void __fastcall SetTransform(TcxCanvasBasedTextLayoutCustomTransform* ATransform);
	
protected:
	int FFlags;
	TcxCanvasBasedFontHandle* FFontHandle;
	bool FPaintOnGlass;
	int FRowCount;
	System::UnicodeString FText;
	System::Types::TSize FTextSize;
	bool FTextTruncated;
	TcxCanvasBasedTextLayoutCustomTransform* FTransform;
	virtual void __fastcall ApplyFlags();
	int __fastcall CalculateRowCount(float AMaxHeight, float ARowHeight);
	void __fastcall CheckCalculated();
	void __fastcall DoCalculate()/* overload */;
	virtual void __fastcall DoCalculate(int AMaxWidth, int AMaxHeight, int AMaxRowCount) = 0 /* overload */;
	virtual void __fastcall DoDraw(const System::Types::TRect &R) = 0 ;
	virtual void __fastcall DoSetFont(TcxCanvasBasedFontHandle* AFontHandle);
	virtual void __fastcall FontChanged();
	virtual void __fastcall LayoutChanged();
	virtual void __fastcall TextChanged();
	
public:
	__fastcall virtual ~TcxCanvasBasedTextLayout();
	void __fastcall Draw(const Cxgeometry::TdxRectF &ARect)/* overload */;
	virtual void __fastcall Draw(const System::Types::TRect &ARect)/* overload */;
	virtual bool __fastcall IsTruncated();
	System::Types::TSize __fastcall MeasureSize();
	Cxgeometry::TdxSizeF __fastcall MeasureSizeF();
	virtual void __fastcall Release();
	void __fastcall SetColor(System::Uitypes::TColor AColor)/* overload */;
	virtual void __fastcall SetColor(Dxcoregraphics::TdxAlphaColor AColor) = 0 /* overload */;
	void __fastcall SetBackgroundAppearance(TcxCanvasBasedBrush* AFill, TcxCanvasBasedPen* AStroke);
	void __fastcall SetFlag(int ACxToFlag, bool AFlagState);
	virtual void __fastcall SetFlags(int ACxTOFlags);
	void __fastcall SetFont(TcxCanvasBasedFont* AFont, Dxcore::TdxObjectOwnership AOwnership = (Dxcore::TdxObjectOwnership)(0x1))/* overload */;
	void __fastcall SetFont(Vcl::Graphics::TFont* AFont, Dxcore::TdxObjectOwnership AOwnership = (Dxcore::TdxObjectOwnership)(0x1))/* overload */;
	void __fastcall SetLayoutConstraints(int AMaxWidth, int AMaxHeight, int AMaxRowCount = 0x0)/* overload */;
	void __fastcall SetLayoutConstraints(const Cxgeometry::TdxRectF &R, int AMaxRowCount = 0x0)/* overload */;
	void __fastcall SetLayoutConstraints(const System::Types::TRect &R, int AMaxRowCount = 0x0)/* overload */;
	void __fastcall SetPadding(const System::Types::TRect &APadding);
	void __fastcall SetPaintOnGlass(bool AValue);
	void __fastcall SetRotation(float AAngle)/* overload */;
	void __fastcall SetRotation(TcxRotationAngle AAngle)/* overload */;
	virtual void __fastcall SetText(const System::UnicodeString AText);
	__property System::UnicodeString Text = {read=FText, write=SetText};
public:
	/* TcxCanvasBasedResource.Create */ inline __fastcall TcxCanvasBasedTextLayout(TcxCustomCanvas* ACanvas, TcxCanvasBasedResourceHandle* AHandle) : TcxCanvasBasedResource(ACanvas, AHandle) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCanvasBasedTextLayoutCustomTransform : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	float FAngle;
	tagXFORM FMatrix;
	
public:
	__fastcall TcxCanvasBasedTextLayoutCustomTransform(const float AAngle);
	virtual void __fastcall CalculateConstraints(int &AMaxWidth, int &AMaxHeight) = 0 ;
	virtual void __fastcall CalculateSize(System::Types::TSize &ASize) = 0 ;
	HIDESBASE bool __fastcall Equals(const float AAngle)/* overload */;
	HIDESBASE bool __fastcall Equals(const TcxRotationAngle AAngle)/* overload */;
	__property float Angle = {read=FAngle};
	__property tagXFORM Matrix = {read=FMatrix};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCanvasBasedTextLayoutCustomTransform() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCanvasBasedSharedBrushes : public TcxCanvasBasedSharedResources
{
	typedef TcxCanvasBasedSharedResources inherited;
	
private:
	TcxCanvasBasedBrushHandleClass FClass;
	
public:
	__fastcall TcxCanvasBasedSharedBrushes(TcxCustomCanvas* ACanvas, TcxCanvasBasedBrushHandleClass AClass);
	TcxCanvasBasedBrushHandle* __fastcall GetOrCreate(Dxcoregraphics::TdxAlphaColor AColor)/* overload */;
	TcxCanvasBasedBrushHandle* __fastcall GetOrCreate(TdxFillOptions* AOptions)/* overload */;
public:
	/* TcxCanvasBasedSharedResources.Destroy */ inline __fastcall virtual ~TcxCanvasBasedSharedBrushes() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCanvasBasedSharedFonts : public TcxCanvasBasedSharedResources
{
	typedef TcxCanvasBasedSharedResources inherited;
	
private:
	TcxCanvasBasedFontHandleClass FClass;
	
public:
	__fastcall TcxCanvasBasedSharedFonts(TcxCustomCanvas* ACanvas, TcxCanvasBasedFontHandleClass AClass);
	TcxCanvasBasedFontHandle* __fastcall GetOrCreate(TdxFontOptions* const AFont)/* overload */;
	TcxCanvasBasedFontHandle* __fastcall GetOrCreate(Vcl::Graphics::TFont* const AFont, Dxcore::TdxObjectOwnership AOwnership = (Dxcore::TdxObjectOwnership)(0x2))/* overload */;
public:
	/* TcxCanvasBasedSharedResources.Destroy */ inline __fastcall virtual ~TcxCanvasBasedSharedFonts() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCanvasBasedSharedImageLists : public TcxCanvasBasedSharedResources
{
	typedef TcxCanvasBasedSharedResources inherited;
	
private:
	TcxCanvasBasedImageListHandleClass FClass;
	
public:
	__fastcall TcxCanvasBasedSharedImageLists(TcxCustomCanvas* ACanvas, TcxCanvasBasedImageListHandleClass AClass);
	TcxCanvasBasedImageListHandle* __fastcall GetOrCreate(Vcl::Imglist::TCustomImageList* const AImageList);
public:
	/* TcxCanvasBasedSharedResources.Destroy */ inline __fastcall virtual ~TcxCanvasBasedSharedImageLists() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCanvasBasedSharedPens : public TcxCanvasBasedSharedResources
{
	typedef TcxCanvasBasedSharedResources inherited;
	
private:
	TcxCanvasBasedPenHandleClass FClass;
	
public:
	__fastcall TcxCanvasBasedSharedPens(TcxCustomCanvas* ACanvas, TcxCanvasBasedPenHandleClass AClass);
	TcxCanvasBasedPenHandle* __fastcall GetOrCreate(Dxcoregraphics::TdxAlphaColor AColor, float AWidth, TdxStrokeStyle AStyle)/* overload */;
	TcxCanvasBasedPenHandle* __fastcall GetOrCreate(TdxStrokeOptions* AOptions)/* overload */;
public:
	/* TcxCanvasBasedSharedResources.Destroy */ inline __fastcall virtual ~TcxCanvasBasedSharedPens() { }
	
};

#pragma pack(pop)

__interface TcxCanvasNativeDrawProc  : public System::IInterface 
{
	virtual void __fastcall Invoke(TcxGdiBasedCanvas* ACanvas, const System::Types::TRect &R) = 0 ;
};

__interface TcxCanvasNativeDrawExProc  : public System::IInterface 
{
	virtual void __fastcall Invoke(Dxgdiplusclasses::TdxGPCanvas* ACanvas, const System::Types::TRect &R) = 0 ;
};

enum DECLSPEC_DENUM TcxCanvasImageStretchQuality : unsigned char { isqStandard, isqHigh };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomCanvas : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	TcxCanvasImageStretchQuality FImageStretchQuality;
	TcxCanvasBasedImage* __fastcall AllocateTempImage(Dxgdiplusclasses::TdxGPImage* AImage, PcxCanvasBasedImage AImageCache);
	void __fastcall ReleaseTempResource(TcxCanvasBasedResource* AResource, void * ACache);
	void __fastcall DrawFastDIB(Dxcoregraphics::TdxCustomFastDIB* AFastDIB, const System::Types::TRect &ATargetRect, const System::Types::TRect &ASourceRect, Vcl::Graphics::TAlphaFormat AAlphaFormat, PcxCanvasBasedImage ACache = (PcxCanvasBasedImage)(0x0))/* overload */;
	void __fastcall DrawFastDIB(Dxcoregraphics::TdxCustomFastDIB* AFastDIB, const Cxgeometry::TdxRectF &ATargetRect, const Cxgeometry::TdxRectF &ASourceRect, Vcl::Graphics::TAlphaFormat AAlphaFormat, PcxCanvasBasedImage ACache = (PcxCanvasBasedImage)(0x0))/* overload */;
	bool __fastcall GetUseRightToLeftAlignment();
	void __fastcall SetUseRightToLeftAlignment(const bool Value);
	
protected:
	System::Classes::TList* FResources;
	Dxcore::TdxDefaultBoolean FUseRightToLeftAlignment;
	virtual void __fastcall DrawImageCore(TcxCanvasBasedImage* AImage, const Cxgeometry::TdxRectF &ATargetRect, const Cxgeometry::TdxRectF &ASourceRect, System::Byte AAlpha) = 0 /* overload */;
	virtual void __fastcall DrawImageCore(TcxCanvasBasedImage* AImage, const System::Types::TRect &ATargetRect, const System::Types::TRect &ASourceRect, System::Byte AAlpha) = 0 /* overload */;
	virtual void __fastcall FillRectByGradientCore(const System::Types::TRect &R, Dxcoregraphics::TdxAlphaColor AColor1, Dxcoregraphics::TdxAlphaColor AColor2, Dxgdiplusapi::LinearGradientMode AMode) = 0 ;
	virtual void __fastcall RectangleCore(const Cxgeometry::TdxRectF &R, TcxCanvasBasedBrushHandle* ABrushHandle, TcxCanvasBasedPenHandle* APenHandle) = 0 ;
	virtual bool __fastcall GetDefaultUseRightToLeftAlignment();
	virtual bool __fastcall GetIsLowColorsMode();
	virtual TcxCanvasBasedSharedBrushes* __fastcall GetSharedBrushes() = 0 ;
	virtual TcxCanvasBasedSharedFonts* __fastcall GetSharedFonts() = 0 ;
	virtual TcxCanvasBasedSharedImageLists* __fastcall GetSharedImageLists() = 0 ;
	virtual TcxCanvasBasedSharedPens* __fastcall GetSharedPens() = 0 ;
	virtual System::Types::TPoint __fastcall GetWindowOrg() = 0 ;
	virtual void __fastcall SetWindowOrg(const System::Types::TPoint &Value) = 0 ;
	void __fastcall ReleaseResources();
	
public:
	__fastcall TcxCustomCanvas();
	__fastcall virtual ~TcxCustomCanvas();
	virtual void __fastcall BeforeDestruction();
	bool __fastcall CheckIsValid(void *AResource);
	virtual TcxCanvasBasedBrush* __fastcall CreateBrush(Dxgdiplusclasses::TdxGPCustomBrush* ABrush, Dxcore::TdxObjectOwnership AOwnership = (Dxcore::TdxObjectOwnership)(0x2)) = 0 /* overload */;
	virtual TcxCanvasBasedBrush* __fastcall CreateBrush(Dxcoregraphics::TdxAlphaColor AColor)/* overload */;
	virtual TcxCanvasBasedBrush* __fastcall CreateBrush(TdxFillOptions* AFillOptions)/* overload */;
	virtual TcxCanvasBasedFont* __fastcall CreateFonT(Vcl::Graphics::TFont* AFont, Dxcore::TdxObjectOwnership AOwnership = (Dxcore::TdxObjectOwnership)(0x2))/* overload */;
	virtual TcxCanvasBasedFont* __fastcall CreateFonT(TdxFontOptions* AFont)/* overload */;
	virtual TcxCanvasBasedImage* __fastcall CreateImage(Vcl::Graphics::TBitmap* ABitmap, Vcl::Graphics::TAlphaFormat AAlphaFormat = (Vcl::Graphics::TAlphaFormat)(0x0)) = 0 /* overload */;
	virtual TcxCanvasBasedImage* __fastcall CreateImage(Dxcoregraphics::TdxCustomFastDIB* ABitmap, Vcl::Graphics::TAlphaFormat AAlphaFormat = (Vcl::Graphics::TAlphaFormat)(0x0)) = 0 /* overload */;
	virtual TcxCanvasBasedImage* __fastcall CreateImage(Vcl::Graphics::TGraphic* AGraphic)/* overload */;
	virtual TcxCanvasBasedImage* __fastcall CreateImage(Dxgdiplusclasses::TdxGPImage* AImage, Dxcore::TdxObjectOwnership AOwnership = (Dxcore::TdxObjectOwnership)(0x2))/* overload */;
	virtual TcxCanvasBasedImageList* __fastcall CreateImageList(Vcl::Imglist::TCustomImageList* AImageList);
	virtual TcxCanvasBasedPath* __fastcall CreatePath() = 0 ;
	virtual TcxCanvasBasedPen* __fastcall CreatePeN(Dxcoregraphics::TdxAlphaColor AColor, float AWidth, TdxStrokeStyle AStyle)/* overload */;
	virtual TcxCanvasBasedPen* __fastcall CreatePeN(Dxgdiplusclasses::TdxGPPen* APen, Dxcore::TdxObjectOwnership AOwnership = (Dxcore::TdxObjectOwnership)(0x2)) = 0 /* overload */;
	virtual TcxCanvasBasedPen* __fastcall CreatePeN(TdxStrokeOptions* AStrokeOptions)/* overload */;
	virtual TcxCanvasBasedTextLayout* __fastcall CreateTextLayout() = 0 ;
	virtual void __fastcall DrawNativeObject(const System::Types::TRect &R, const TcxCanvasBasedResourceCacheKey &ACacheKey, _di_TcxCanvasNativeDrawExProc AProc)/* overload */;
	virtual void __fastcall DrawNativeObject(const System::Types::TRect &R, const TcxCanvasBasedResourceCacheKey &ACacheKey, _di_TcxCanvasNativeDrawProc AProc) = 0 /* overload */;
	void __fastcall DrawBitmap(Vcl::Graphics::TBitmap* ABitmap, const System::Types::TRect &ATargetRect, PcxCanvasBasedImage ACache = (PcxCanvasBasedImage)(0x0))/* overload */;
	void __fastcall DrawBitmap(Vcl::Graphics::TBitmap* ABitmap, const System::Types::TRect &ATargetRect, Vcl::Graphics::TAlphaFormat AAlphaFormat, PcxCanvasBasedImage ACache = (PcxCanvasBasedImage)(0x0))/* overload */;
	void __fastcall DrawBitmap(Vcl::Graphics::TBitmap* ABitmap, const System::Types::TRect &ATargetRect, const System::Types::TRect &ASourceRect, PcxCanvasBasedImage ACache = (PcxCanvasBasedImage)(0x0))/* overload */;
	virtual void __fastcall DrawBitmap(Vcl::Graphics::TBitmap* ABitmap, const System::Types::TRect &ATargetRect, const System::Types::TRect &ASourceRect, Vcl::Graphics::TAlphaFormat AAlphaFormat, PcxCanvasBasedImage ACache = (PcxCanvasBasedImage)(0x0))/* overload */;
	void __fastcall DrawBitmap(Dxcoregraphics::TdxFastDIB* ABitmap, const System::Types::TRect &ATargetRect, Vcl::Graphics::TAlphaFormat AAlphaFormat, PcxCanvasBasedImage ACache = (PcxCanvasBasedImage)(0x0))/* overload */;
	void __fastcall DrawBitmap(Dxcoregraphics::TdxFastDIB* ABitmap, const Cxgeometry::TdxRectF &ATargetRect, Vcl::Graphics::TAlphaFormat AAlphaFormat, PcxCanvasBasedImage ACache = (PcxCanvasBasedImage)(0x0))/* overload */;
	virtual void __fastcall DrawBitmap(Dxcoregraphics::TdxFastDIB* ABitmap, const System::Types::TRect &ATargetRect, const System::Types::TRect &ASourceRect, Vcl::Graphics::TAlphaFormat AAlphaFormat, PcxCanvasBasedImage ACache = (PcxCanvasBasedImage)(0x0))/* overload */;
	virtual void __fastcall DrawBitmap(Dxcoregraphics::TdxFastDIB* ABitmap, const Cxgeometry::TdxRectF &ATargetRect, const Cxgeometry::TdxRectF &ASourceRect, Vcl::Graphics::TAlphaFormat AAlphaFormat, PcxCanvasBasedImage ACache = (PcxCanvasBasedImage)(0x0))/* overload */;
	void __fastcall DrawBitmap(Dxgdiplusclasses::TdxGpFastDIB* ABitmap, const Cxgeometry::TdxRectF &ATargetRect, Vcl::Graphics::TAlphaFormat AAlphaFormat, PcxCanvasBasedImage ACache = (PcxCanvasBasedImage)(0x0))/* overload */;
	void __fastcall DrawBitmap(Dxgdiplusclasses::TdxGpFastDIB* ABitmap, const System::Types::TRect &ATargetRect, Vcl::Graphics::TAlphaFormat AAlphaFormat, PcxCanvasBasedImage ACache = (PcxCanvasBasedImage)(0x0))/* overload */;
	virtual void __fastcall DrawBitmap(Dxgdiplusclasses::TdxGpFastDIB* ABitmap, const System::Types::TRect &ATargetRect, const System::Types::TRect &ASourceRect, Vcl::Graphics::TAlphaFormat AAlphaFormat, PcxCanvasBasedImage ACache = (PcxCanvasBasedImage)(0x0))/* overload */;
	virtual void __fastcall DrawBitmap(Dxgdiplusclasses::TdxGpFastDIB* ABitmap, const Cxgeometry::TdxRectF &ATargetRect, const Cxgeometry::TdxRectF &ASourceRect, Vcl::Graphics::TAlphaFormat AAlphaFormat, PcxCanvasBasedImage ACache = (PcxCanvasBasedImage)(0x0))/* overload */;
	virtual void __fastcall DrawImage(Dxgdiplusclasses::TdxGPImage* AImage, const System::Types::TRect &ATargetRect, PcxCanvasBasedImage ACache = (PcxCanvasBasedImage)(0x0))/* overload */;
	virtual void __fastcall DrawImage(Dxgdiplusclasses::TdxGPImage* AImage, const Cxgeometry::TdxRectF &ATargetRect, PcxCanvasBasedImage ACache = (PcxCanvasBasedImage)(0x0))/* overload */;
	virtual void __fastcall DrawComplexFrame(const System::Types::TRect &R, System::Uitypes::TColor ALeftTopColor, System::Uitypes::TColor ARightBottomColor, Cxgeometry::TcxBorders ABorders = (Cxgeometry::TcxBorders() << Cxgeometry::TcxBorder::bLeft << Cxgeometry::TcxBorder::bTop << Cxgeometry::TcxBorder::bRight << Cxgeometry::TcxBorder::bBottom ), int ABorderWidth = 0x1);
	virtual void __fastcall DrawEdge(const System::Types::TRect &R, bool ASunken, bool AOuter, Cxgeometry::TcxBorders ABorders = (Cxgeometry::TcxBorders() << Cxgeometry::TcxBorder::bLeft << Cxgeometry::TcxBorder::bTop << Cxgeometry::TcxBorder::bRight << Cxgeometry::TcxBorder::bBottom ));
	virtual void __fastcall FrameRect(const System::Types::TRect &R, System::Uitypes::TColor AColor, int ALineWidth = 0x1, Cxgeometry::TcxBorders ABorders = (Cxgeometry::TcxBorders() << Cxgeometry::TcxBorder::bLeft << Cxgeometry::TcxBorder::bTop << Cxgeometry::TcxBorder::bRight << Cxgeometry::TcxBorder::bBottom ))/* overload */;
	virtual void __fastcall FrameRect(const System::Types::TRect &R, Dxcoregraphics::TdxAlphaColor AColor, int ALineWidth = 0x1, Cxgeometry::TcxBorders ABorders = (Cxgeometry::TcxBorders() << Cxgeometry::TcxBorder::bLeft << Cxgeometry::TcxBorder::bTop << Cxgeometry::TcxBorder::bRight << Cxgeometry::TcxBorder::bBottom ))/* overload */;
	virtual void __fastcall FrameRect(const Cxgeometry::TdxRectF &R, Dxcoregraphics::TdxAlphaColor AColor, float ALineWidth = 1.000000E+00f, Cxgeometry::TcxBorders ABorders = (Cxgeometry::TcxBorders() << Cxgeometry::TcxBorder::bLeft << Cxgeometry::TcxBorder::bTop << Cxgeometry::TcxBorder::bRight << Cxgeometry::TcxBorder::bBottom ))/* overload */;
	virtual void __fastcall Arc(const System::Types::TRect &AEllipse, const System::Types::TPoint &AStartPoint, const System::Types::TPoint &AEndPoint, System::Uitypes::TColor AColor, int APenWidth = 0x1, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0))/* overload */;
	virtual void __fastcall Arc(const System::Types::TRect &AEllipse, const System::Types::TPoint &AStartPoint, const System::Types::TPoint &AEndPoint, Dxcoregraphics::TdxAlphaColor AColor, int APenWidth = 0x1, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0)) = 0 /* overload */;
	virtual void __fastcall DonutSlice(const Cxgeometry::TdxRectF &R, float AStartAngle, float ASweepAngle, float AWholePercent, TcxCanvasBasedBrush* ABrush, TcxCanvasBasedPen* APen) = 0 ;
	virtual void __fastcall Ellipse(const System::Types::TRect &R, System::Uitypes::TColor ABrushColor, System::Uitypes::TColor APenColor, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0), int APenWidth = 0x1)/* overload */;
	virtual void __fastcall Ellipse(const System::Types::TRect &R, Dxcoregraphics::TdxAlphaColor ABrushColor, Dxcoregraphics::TdxAlphaColor APenColor, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0), int APenWidth = 0x1) = 0 /* overload */;
	virtual void __fastcall Ellipse(const Cxgeometry::TdxRectF &R, TcxCanvasBasedBrush* ABrush, TcxCanvasBasedPen* APen) = 0 /* overload */;
	virtual void __fastcall FillPixel(int X, int Y, System::Uitypes::TColor AColor);
	virtual void __fastcall FillPolygon(const System::Types::TPoint *P, const int P_High, System::Uitypes::TColor AColor)/* overload */;
	virtual void __fastcall FillPolygon(const System::Types::TPoint *P, const int P_High, Dxcoregraphics::TdxAlphaColor AColor)/* overload */;
	virtual void __fastcall FillPolygon(const Cxgeometry::TdxPointF *P, const int P_High, TcxCanvasBasedBrush* ABrush)/* overload */;
	virtual void __fastcall FillRect(const System::Types::TRect &R, System::Uitypes::TColor AColor)/* overload */;
	void __fastcall FillRect(const System::Types::TRect &R, System::Uitypes::TColor AColor, System::Byte AAlpha)/* overload */;
	virtual void __fastcall FillRect(const System::Types::TRect &R, Dxcoregraphics::TdxAlphaColor AColor) = 0 /* overload */;
	virtual void __fastcall FillRect(const System::Types::TRect &R, TcxCanvasBasedImage* AImage)/* overload */;
	virtual void __fastcall FillRect(const System::Types::TRect &R, Dxgdiplusclasses::TdxGPImage* AImage, PcxCanvasBasedImage ACache = (PcxCanvasBasedImage)(0x0))/* overload */;
	void __fastcall FillRect(const Cxgeometry::TdxRectF &R, Dxcoregraphics::TdxAlphaColor AColor)/* overload */;
	virtual void __fastcall FillRect(const Cxgeometry::TdxRectF &R, TcxCanvasBasedBrush* ABrush)/* overload */;
	virtual void __fastcall FillRectByGradient(const System::Types::TRect &R, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, bool AHorizontal)/* overload */;
	void __fastcall FillRectByGradient(const System::Types::TRect &R, Dxcoregraphics::TdxAlphaColor AColor1, Dxcoregraphics::TdxAlphaColor AColor2, Dxgdiplusapi::LinearGradientMode AMode)/* overload */;
	virtual void __fastcall FocusRectangle(const System::Types::TRect &R);
	virtual void __fastcall Line(const System::Types::TPoint &P1, const System::Types::TPoint &P2, System::Uitypes::TColor AColor, int APenWidth = 0x1, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0))/* overload */;
	virtual void __fastcall Line(const System::Types::TPoint &P1, const System::Types::TPoint &P2, Dxcoregraphics::TdxAlphaColor AColor, int APenWidth, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0))/* overload */;
	virtual void __fastcall Line(const Cxgeometry::TdxPointF &P1, const Cxgeometry::TdxPointF &P2, TcxCanvasBasedPen* APen)/* overload */;
	virtual void __fastcall Path(TcxCanvasBasedPath* APath, TcxCanvasBasedBrush* ABrush, TcxCanvasBasedPen* APen) = 0 ;
	virtual void __fastcall Pie(const Cxgeometry::TdxRectF &R, float AStartAngle, float ASweepAngle, TcxCanvasBasedBrush* ABrush, TcxCanvasBasedPen* APen) = 0 ;
	virtual void __fastcall Polygon(const System::Types::TPoint *P, const int P_High, System::Uitypes::TColor ABrushColor, System::Uitypes::TColor APenColor)/* overload */;
	virtual void __fastcall Polygon(const System::Types::TPoint *P, const int P_High, Dxcoregraphics::TdxAlphaColor ABrushColor, Dxcoregraphics::TdxAlphaColor APenColor) = 0 /* overload */;
	virtual void __fastcall Polygon(const Cxgeometry::TdxPointF *P, const int P_High, TcxCanvasBasedBrush* ABrush, TcxCanvasBasedPen* APen)/* overload */;
	virtual void __fastcall Polygon(const Cxgeometry::PdxPointF P, int ACount, TcxCanvasBasedBrush* ABrush, TcxCanvasBasedPen* APen) = 0 /* overload */;
	virtual void __fastcall Polyline(const System::Types::TPoint *P, const int P_High, System::Uitypes::TColor AColor, int APenWidth = 0x1, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0))/* overload */;
	virtual void __fastcall Polyline(const System::Types::TPoint *P, const int P_High, Dxcoregraphics::TdxAlphaColor AColor, int APenWidth = 0x1, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0)) = 0 /* overload */;
	virtual void __fastcall Polyline(const Cxgeometry::TdxPointF *P, const int P_High, TcxCanvasBasedPen* APen)/* overload */;
	virtual void __fastcall Polyline(const Cxgeometry::PdxPointF P, int ACount, TcxCanvasBasedPen* APen) = 0 /* overload */;
	virtual void __fastcall Rectangle(const System::Types::TRect &R, System::Uitypes::TColor ABrushColor, System::Uitypes::TColor APenColor, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0), int APenWidth = 0x1)/* overload */;
	virtual void __fastcall Rectangle(const System::Types::TRect &R, Dxcoregraphics::TdxAlphaColor ABrushColor, Dxcoregraphics::TdxAlphaColor APenColor, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0), int APenWidth = 0x1) = 0 /* overload */;
	void __fastcall Rectangle(const Cxgeometry::TdxRectF &R, TcxCanvasBasedBrush* ABrush, TcxCanvasBasedPen* APen)/* overload */;
	virtual void __fastcall ModifyWorldTransform(const tagXFORM &AForm) = 0 ;
	virtual void __fastcall RestoreWorldTransform() = 0 ;
	virtual void __fastcall SaveWorldTransform() = 0 ;
	virtual void __fastcall RestoreState() = 0 ;
	virtual void __fastcall SaveState() = 0 ;
	virtual System::Types::TPoint __fastcall MoveWindowOrg(const System::Types::TPoint &P);
	virtual void __fastcall IntersectClipRect(const System::Types::TRect &ARect) = 0 /* overload */;
	virtual void __fastcall IntersectClipRect(const Cxgeometry::TdxRectF &ARect)/* overload */;
	virtual bool __fastcall RectVisible(const Cxgeometry::TdxRectF &R)/* overload */;
	virtual bool __fastcall RectVisible(const System::Types::TRect &R) = 0 /* overload */;
	virtual void __fastcall RestoreClipRegion() = 0 ;
	virtual void __fastcall SaveClipRegion() = 0 ;
	__property bool IsLowColorsMode = {read=GetIsLowColorsMode, nodefault};
	__property TcxCanvasImageStretchQuality ImageStretchQuality = {read=FImageStretchQuality, write=FImageStretchQuality, nodefault};
	__property bool UseRightToLeftAlignment = {read=GetUseRightToLeftAlignment, write=SetUseRightToLeftAlignment, nodefault};
	__property System::Types::TPoint WindowOrg = {read=GetWindowOrg, write=SetWindowOrg};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGdiBasedCanvas : public TcxCustomCanvas
{
	typedef TcxCustomCanvas inherited;
	
protected:
	bool __fastcall GetGpBrushAndPen(TcxCanvasBasedBrush* ABrush, TcxCanvasBasedPen* APen, /* out */ Dxgdiplusclasses::TdxGPCustomBrush* &AGpBrush, /* out */ Dxgdiplusclasses::TdxGPPen* &AGpPen);
	virtual TcxCanvasBasedSharedBrushes* __fastcall GetSharedBrushes();
	virtual TcxCanvasBasedSharedFonts* __fastcall GetSharedFonts();
	virtual TcxCanvasBasedSharedImageLists* __fastcall GetSharedImageLists();
	virtual TcxCanvasBasedSharedPens* __fastcall GetSharedPens();
	
public:
	virtual TcxCanvasBasedBrush* __fastcall CreateBrush(Dxgdiplusclasses::TdxGPCustomBrush* AGpBrush, Dxcore::TdxObjectOwnership AOwnership)/* overload */;
	virtual TcxCanvasBasedImage* __fastcall CreateImage(Vcl::Graphics::TBitmap* ABitmap, Vcl::Graphics::TAlphaFormat AAlphaFormat = (Vcl::Graphics::TAlphaFormat)(0x0))/* overload */ _FINAL_ATTRIBUTE;
	virtual TcxCanvasBasedImage* __fastcall CreateImage(Dxcoregraphics::TdxCustomFastDIB* ABitmap, Vcl::Graphics::TAlphaFormat AAlphaFormat = (Vcl::Graphics::TAlphaFormat)(0x0))/* overload */ _FINAL_ATTRIBUTE;
	virtual TcxCanvasBasedImage* __fastcall CreateImage(Dxgdiplusclasses::TdxGPImage* AGpImage, Dxcore::TdxObjectOwnership AOwnership = (Dxcore::TdxObjectOwnership)(0x2))/* overload */;
	virtual TcxCanvasBasedPath* __fastcall CreatePath();
	virtual TcxCanvasBasedPen* __fastcall CreatePeN(Dxgdiplusclasses::TdxGPPen* AGpPen, Dxcore::TdxObjectOwnership AOwnership)/* overload */;
	virtual void __fastcall FillRect(const System::Types::TRect &R, TcxCanvasBasedImage* AImage)/* overload */;
public:
	/* TcxCustomCanvas.Create */ inline __fastcall TcxCustomGdiBasedCanvas() : TcxCustomCanvas() { }
	/* TcxCustomCanvas.Destroy */ inline __fastcall virtual ~TcxCustomGdiBasedCanvas() { }
	
	/* Hoisted overloads: */
	
public:
	inline TcxCanvasBasedBrush* __fastcall  CreateBrush(Dxcoregraphics::TdxAlphaColor AColor){ return TcxCustomCanvas::CreateBrush(AColor); }
	inline TcxCanvasBasedBrush* __fastcall  CreateBrush(TdxFillOptions* AFillOptions){ return TcxCustomCanvas::CreateBrush(AFillOptions); }
	inline TcxCanvasBasedImage* __fastcall  CreateImage(Vcl::Graphics::TGraphic* AGraphic){ return TcxCustomCanvas::CreateImage(AGraphic); }
	inline TcxCanvasBasedPen* __fastcall  CreatePeN(Dxcoregraphics::TdxAlphaColor AColor, float AWidth, TdxStrokeStyle AStyle){ return TcxCustomCanvas::CreatePeN(AColor, AWidth, AStyle); }
	inline TcxCanvasBasedPen* __fastcall  CreatePeN(TdxStrokeOptions* AStrokeOptions){ return TcxCustomCanvas::CreatePeN(AStrokeOptions); }
	inline void __fastcall  FillRect(const System::Types::TRect &R, System::Uitypes::TColor AColor){ TcxCustomCanvas::FillRect(R, AColor); }
	inline void __fastcall  FillRect(const System::Types::TRect &R, System::Uitypes::TColor AColor, System::Byte AAlpha){ TcxCustomCanvas::FillRect(R, AColor, AAlpha); }
	inline void __fastcall  FillRect(const System::Types::TRect &R, Dxcoregraphics::TdxAlphaColor AColor){ TcxCustomCanvas::FillRect(R, AColor); }
	inline void __fastcall  FillRect(const System::Types::TRect &R, Dxgdiplusclasses::TdxGPImage* AImage, PcxCanvasBasedImage ACache = (PcxCanvasBasedImage)(0x0)){ TcxCustomCanvas::FillRect(R, AImage, ACache); }
	inline void __fastcall  FillRect(const Cxgeometry::TdxRectF &R, Dxcoregraphics::TdxAlphaColor AColor){ TcxCustomCanvas::FillRect(R, AColor); }
	inline void __fastcall  FillRect(const Cxgeometry::TdxRectF &R, TcxCanvasBasedBrush* ABrush){ TcxCustomCanvas::FillRect(R, ABrush); }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGdiBasedCanvas : public TcxCustomGdiBasedCanvas
{
	typedef TcxCustomGdiBasedCanvas inherited;
	
private:
	static System::StaticArray<Dxgdiplusclasses::TdxGpCompositionMode, 3> CompositionModeMap;
	System::Types::TPoint FBaseOrigin;
	System::Types::TPoint FBrushOrigin;
	System::Generics::Collections::TStack__1<tagXFORM>* FSavedWorldTransforms;
	System::Types::TPoint __fastcall GetDCOrigin();
	
protected:
	void __fastcall RestoreBaseOrigin();
	void __fastcall SaveBaseOrigin();
	virtual void __fastcall FillRectByGradientCore(const System::Types::TRect &R, Dxcoregraphics::TdxAlphaColor AColor1, Dxcoregraphics::TdxAlphaColor AColor2, Dxgdiplusapi::LinearGradientMode AMode);
	virtual void __fastcall DrawImageCore(TcxCanvasBasedImage* AImage, const Cxgeometry::TdxRectF &ATargetRect, const Cxgeometry::TdxRectF &ASourceRect, System::Byte AAlpha)/* overload */;
	virtual void __fastcall DrawImageCore(TcxCanvasBasedImage* AImage, const System::Types::TRect &ATargetRect, const System::Types::TRect &ASourceRect, System::Byte AAlpha)/* overload */;
	virtual void __fastcall RectangleCore(const Cxgeometry::TdxRectF &R, TcxCanvasBasedBrushHandle* ABrushHandle, TcxCanvasBasedPenHandle* APenHandle);
	virtual HDC __fastcall GetHandle() = 0 ;
	virtual bool __fastcall GetIsLowColorsMode();
	System::Types::TPoint __fastcall GetViewportOrg();
	virtual System::Types::TPoint __fastcall GetWindowOrg();
	void __fastcall SetViewportOrg(const System::Types::TPoint &P);
	virtual void __fastcall SetWindowOrg(const System::Types::TPoint &P);
	
public:
	__fastcall virtual ~TcxGdiBasedCanvas();
	virtual TcxCanvasBasedTextLayout* __fastcall CreateTextLayout();
	virtual void __fastcall DrawNativeObject(const System::Types::TRect &R, const TcxCanvasBasedResourceCacheKey &ACacheKey, _di_TcxCanvasNativeDrawProc AProc)/* overload */;
	virtual void __fastcall DrawBitmap(Vcl::Graphics::TBitmap* ABitmap, const System::Types::TRect &ATargetRect, const System::Types::TRect &ASourceRect, Vcl::Graphics::TAlphaFormat AAlphaFormat = (Vcl::Graphics::TAlphaFormat)(0x0), PcxCanvasBasedImage ACache = (PcxCanvasBasedImage)(0x0))/* overload */;
	virtual void __fastcall DrawBitmap(Dxcoregraphics::TdxFastDIB* ABitmap, const System::Types::TRect &ATargetRect, const System::Types::TRect &ASourceRect, Vcl::Graphics::TAlphaFormat AAlphaFormat, PcxCanvasBasedImage ACache = (PcxCanvasBasedImage)(0x0))/* overload */;
	virtual void __fastcall DrawBitmap(Dxcoregraphics::TdxFastDIB* ABitmap, const Cxgeometry::TdxRectF &ATargetRect, const Cxgeometry::TdxRectF &ASourceRect, Vcl::Graphics::TAlphaFormat AAlphaFormat, PcxCanvasBasedImage ACache = (PcxCanvasBasedImage)(0x0))/* overload */;
	virtual void __fastcall DrawBitmap(Dxgdiplusclasses::TdxGpFastDIB* ABitmap, const System::Types::TRect &ATargetRect, const System::Types::TRect &ASourceRect, Vcl::Graphics::TAlphaFormat AAlphaFormat, PcxCanvasBasedImage ACache = (PcxCanvasBasedImage)(0x0))/* overload */;
	virtual void __fastcall DrawBitmap(Dxgdiplusclasses::TdxGpFastDIB* ABitmap, const Cxgeometry::TdxRectF &ATargetRect, const Cxgeometry::TdxRectF &ASourceRect, Vcl::Graphics::TAlphaFormat AAlphaFormat, PcxCanvasBasedImage ACache = (PcxCanvasBasedImage)(0x0))/* overload */;
	virtual void __fastcall DrawImage(Dxgdiplusclasses::TdxGPImage* AImage, const System::Types::TRect &ATargetRect, PcxCanvasBasedImage ACache = (PcxCanvasBasedImage)(0x0))/* overload */;
	virtual void __fastcall DrawImage(Dxgdiplusclasses::TdxGPImage* AImage, const Cxgeometry::TdxRectF &ATargetRect, PcxCanvasBasedImage ACache = (PcxCanvasBasedImage)(0x0))/* overload */;
	virtual void __fastcall Arc(const System::Types::TRect &AEllipse, const System::Types::TPoint &AStartPoint, const System::Types::TPoint &AEndPoint, Dxcoregraphics::TdxAlphaColor AColor, int APenWidth, Vcl::Graphics::TPenStyle APenStyle)/* overload */;
	virtual void __fastcall DonutSlice(const Cxgeometry::TdxRectF &R, float AStartAngle, float ASweepAngle, float AWholePercent, TcxCanvasBasedBrush* ABrush, TcxCanvasBasedPen* APen);
	virtual void __fastcall Ellipse(const System::Types::TRect &R, Dxcoregraphics::TdxAlphaColor ABrushColor, Dxcoregraphics::TdxAlphaColor APenColor, Vcl::Graphics::TPenStyle APenStyle, int APenWidth)/* overload */;
	virtual void __fastcall Ellipse(const Cxgeometry::TdxRectF &R, TcxCanvasBasedBrush* ABrush, TcxCanvasBasedPen* APen)/* overload */;
	virtual void __fastcall FillPixel(int X, int Y, System::Uitypes::TColor AColor);
	virtual void __fastcall FillPolygon(const System::Types::TPoint *P, const int P_High, System::Uitypes::TColor AColor)/* overload */;
	virtual void __fastcall FillRect(const System::Types::TRect &R, System::Uitypes::TColor AColor)/* overload */;
	virtual void __fastcall FillRect(const System::Types::TRect &R, Dxcoregraphics::TdxAlphaColor AColor)/* overload */;
	virtual void __fastcall FillRect(const System::Types::TRect &R, Dxgdiplusclasses::TdxGPImage* AImage, PcxCanvasBasedImage ACache = (PcxCanvasBasedImage)(0x0))/* overload */;
	virtual void __fastcall FillRectByGradient(const System::Types::TRect &R, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, bool AHorizontal)/* overload */;
	virtual void __fastcall FocusRectangle(const System::Types::TRect &R);
	virtual void __fastcall Line(const System::Types::TPoint &P1, const System::Types::TPoint &P2, Dxcoregraphics::TdxAlphaColor AColor, int APenWidth, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0))/* overload */;
	virtual void __fastcall Line(const Cxgeometry::TdxPointF &P1, const Cxgeometry::TdxPointF &P2, TcxCanvasBasedPen* APen)/* overload */;
	virtual void __fastcall Path(TcxCanvasBasedPath* APath, TcxCanvasBasedBrush* ABrush, TcxCanvasBasedPen* APen);
	virtual void __fastcall Pie(const Cxgeometry::TdxRectF &R, float AStartAngle, float ASweepAngle, TcxCanvasBasedBrush* ABrush, TcxCanvasBasedPen* APen);
	virtual void __fastcall Polygon(const System::Types::TPoint *P, const int P_High, Dxcoregraphics::TdxAlphaColor ABrushColor, Dxcoregraphics::TdxAlphaColor APenColor)/* overload */;
	virtual void __fastcall Polygon(const Cxgeometry::PdxPointF P, int ACount, TcxCanvasBasedBrush* ABrush, TcxCanvasBasedPen* APen)/* overload */;
	virtual void __fastcall Polyline(const Cxgeometry::PdxPointF P, int ACount, TcxCanvasBasedPen* APen)/* overload */;
	virtual void __fastcall Polyline(const System::Types::TPoint *P, const int P_High, Dxcoregraphics::TdxAlphaColor AColor, int APenWidth = 0x1, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0))/* overload */;
	virtual void __fastcall Rectangle(const System::Types::TRect &R, Dxcoregraphics::TdxAlphaColor ABrushColor, Dxcoregraphics::TdxAlphaColor APenColor, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0), int APenWidth = 0x1)/* overload */;
	virtual void __fastcall ModifyWorldTransform(const tagXFORM &AForm);
	virtual void __fastcall RestoreWorldTransform();
	virtual void __fastcall SaveWorldTransform();
	void __fastcall ExcludeClipRect(const System::Types::TRect &R);
	virtual void __fastcall IntersectClipRect(const System::Types::TRect &R)/* overload */;
	virtual bool __fastcall RectVisible(const System::Types::TRect &R)/* overload */;
	__property System::Types::TPoint BaseOrigin = {read=FBaseOrigin};
	__property System::Types::TPoint DCOrigin = {read=GetDCOrigin};
	__property HDC Handle = {read=GetHandle, nodefault};
	__property System::Types::TPoint ViewportOrg = {read=GetViewportOrg, write=SetViewportOrg};
public:
	/* TcxCustomCanvas.Create */ inline __fastcall TcxGdiBasedCanvas() : TcxCustomGdiBasedCanvas() { }
	
	/* Hoisted overloads: */
	
public:
	inline void __fastcall  DrawNativeObject(const System::Types::TRect &R, const TcxCanvasBasedResourceCacheKey &ACacheKey, _di_TcxCanvasNativeDrawExProc AProc){ TcxCustomCanvas::DrawNativeObject(R, ACacheKey, AProc); }
	inline void __fastcall  DrawBitmap(Vcl::Graphics::TBitmap* ABitmap, const System::Types::TRect &ATargetRect, PcxCanvasBasedImage ACache = (PcxCanvasBasedImage)(0x0)){ TcxCustomCanvas::DrawBitmap(ABitmap, ATargetRect, ACache); }
	inline void __fastcall  DrawBitmap(Vcl::Graphics::TBitmap* ABitmap, const System::Types::TRect &ATargetRect, Vcl::Graphics::TAlphaFormat AAlphaFormat, PcxCanvasBasedImage ACache = (PcxCanvasBasedImage)(0x0)){ TcxCustomCanvas::DrawBitmap(ABitmap, ATargetRect, AAlphaFormat, ACache); }
	inline void __fastcall  DrawBitmap(Vcl::Graphics::TBitmap* ABitmap, const System::Types::TRect &ATargetRect, const System::Types::TRect &ASourceRect, PcxCanvasBasedImage ACache = (PcxCanvasBasedImage)(0x0)){ TcxCustomCanvas::DrawBitmap(ABitmap, ATargetRect, ASourceRect, ACache); }
	inline void __fastcall  DrawBitmap(Dxcoregraphics::TdxFastDIB* ABitmap, const System::Types::TRect &ATargetRect, Vcl::Graphics::TAlphaFormat AAlphaFormat, PcxCanvasBasedImage ACache = (PcxCanvasBasedImage)(0x0)){ TcxCustomCanvas::DrawBitmap(ABitmap, ATargetRect, AAlphaFormat, ACache); }
	inline void __fastcall  DrawBitmap(Dxcoregraphics::TdxFastDIB* ABitmap, const Cxgeometry::TdxRectF &ATargetRect, Vcl::Graphics::TAlphaFormat AAlphaFormat, PcxCanvasBasedImage ACache = (PcxCanvasBasedImage)(0x0)){ TcxCustomCanvas::DrawBitmap(ABitmap, ATargetRect, AAlphaFormat, ACache); }
	inline void __fastcall  DrawBitmap(Dxgdiplusclasses::TdxGpFastDIB* ABitmap, const Cxgeometry::TdxRectF &ATargetRect, Vcl::Graphics::TAlphaFormat AAlphaFormat, PcxCanvasBasedImage ACache = (PcxCanvasBasedImage)(0x0)){ TcxCustomCanvas::DrawBitmap(ABitmap, ATargetRect, AAlphaFormat, ACache); }
	inline void __fastcall  DrawBitmap(Dxgdiplusclasses::TdxGpFastDIB* ABitmap, const System::Types::TRect &ATargetRect, Vcl::Graphics::TAlphaFormat AAlphaFormat, PcxCanvasBasedImage ACache = (PcxCanvasBasedImage)(0x0)){ TcxCustomCanvas::DrawBitmap(ABitmap, ATargetRect, AAlphaFormat, ACache); }
	inline void __fastcall  Arc(const System::Types::TRect &AEllipse, const System::Types::TPoint &AStartPoint, const System::Types::TPoint &AEndPoint, System::Uitypes::TColor AColor, int APenWidth = 0x1, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0)){ TcxCustomCanvas::Arc(AEllipse, AStartPoint, AEndPoint, AColor, APenWidth, APenStyle); }
	inline void __fastcall  Ellipse(const System::Types::TRect &R, System::Uitypes::TColor ABrushColor, System::Uitypes::TColor APenColor, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0), int APenWidth = 0x1){ TcxCustomCanvas::Ellipse(R, ABrushColor, APenColor, APenStyle, APenWidth); }
	inline void __fastcall  FillPolygon(const System::Types::TPoint *P, const int P_High, Dxcoregraphics::TdxAlphaColor AColor){ TcxCustomCanvas::FillPolygon(P, P_High, AColor); }
	inline void __fastcall  FillPolygon(const Cxgeometry::TdxPointF *P, const int P_High, TcxCanvasBasedBrush* ABrush){ TcxCustomCanvas::FillPolygon(P, P_High, ABrush); }
	inline void __fastcall  FillRect(const System::Types::TRect &R, TcxCanvasBasedImage* AImage){ TcxCustomGdiBasedCanvas::FillRect(R, AImage); }
	inline void __fastcall  FillRect(const System::Types::TRect &R, System::Uitypes::TColor AColor, System::Byte AAlpha){ TcxCustomCanvas::FillRect(R, AColor, AAlpha); }
	inline void __fastcall  FillRect(const Cxgeometry::TdxRectF &R, Dxcoregraphics::TdxAlphaColor AColor){ TcxCustomCanvas::FillRect(R, AColor); }
	inline void __fastcall  FillRect(const Cxgeometry::TdxRectF &R, TcxCanvasBasedBrush* ABrush){ TcxCustomCanvas::FillRect(R, ABrush); }
	inline void __fastcall  FillRectByGradient(const System::Types::TRect &R, Dxcoregraphics::TdxAlphaColor AColor1, Dxcoregraphics::TdxAlphaColor AColor2, Dxgdiplusapi::LinearGradientMode AMode){ TcxCustomCanvas::FillRectByGradient(R, AColor1, AColor2, AMode); }
	inline void __fastcall  Line(const System::Types::TPoint &P1, const System::Types::TPoint &P2, System::Uitypes::TColor AColor, int APenWidth = 0x1, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0)){ TcxCustomCanvas::Line(P1, P2, AColor, APenWidth, APenStyle); }
	inline void __fastcall  Polygon(const System::Types::TPoint *P, const int P_High, System::Uitypes::TColor ABrushColor, System::Uitypes::TColor APenColor){ TcxCustomCanvas::Polygon(P, P_High, ABrushColor, APenColor); }
	inline void __fastcall  Polygon(const Cxgeometry::TdxPointF *P, const int P_High, TcxCanvasBasedBrush* ABrush, TcxCanvasBasedPen* APen){ TcxCustomCanvas::Polygon(P, P_High, ABrush, APen); }
	inline void __fastcall  Polyline(const System::Types::TPoint *P, const int P_High, System::Uitypes::TColor AColor, int APenWidth = 0x1, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0)){ TcxCustomCanvas::Polyline(P, P_High, AColor, APenWidth, APenStyle); }
	inline void __fastcall  Polyline(const Cxgeometry::TdxPointF *P, const int P_High, TcxCanvasBasedPen* APen){ TcxCustomCanvas::Polyline(P, P_High, APen); }
	inline void __fastcall  Rectangle(const System::Types::TRect &R, System::Uitypes::TColor ABrushColor, System::Uitypes::TColor APenColor, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0), int APenWidth = 0x1){ TcxCustomCanvas::Rectangle(R, ABrushColor, APenColor, APenStyle, APenWidth); }
	inline void __fastcall  Rectangle(const Cxgeometry::TdxRectF &R, TcxCanvasBasedBrush* ABrush, TcxCanvasBasedPen* APen){ TcxCustomCanvas::Rectangle(R, ABrush, APen); }
	inline void __fastcall  IntersectClipRect(const Cxgeometry::TdxRectF &ARect){ TcxCustomCanvas::IntersectClipRect(ARect); }
	inline bool __fastcall  RectVisible(const Cxgeometry::TdxRectF &R){ return TcxCustomCanvas::RectVisible(R); }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGdiCanvasBasedBrushHandle : public TcxCanvasBasedBrushHandle
{
	typedef TcxCanvasBasedBrushHandle inherited;
	
protected:
	Dxgdiplusclasses::TdxGPCustomBrush* FBrush;
	Dxcore::TdxObjectOwnership FBrushOwnership;
	virtual void __fastcall CreateNativeHandle(TcxCustomCanvas* ACanvas);
	virtual void __fastcall FreeNativeHandle();
	
public:
	__fastcall TcxGdiCanvasBasedBrushHandle(Dxgdiplusclasses::TdxGPCustomBrush* ABrush, Dxcore::TdxObjectOwnership AOwnership)/* overload */;
	virtual bool __fastcall IsEmpty();
	__property Dxgdiplusclasses::TdxGPCustomBrush* Brush = {read=FBrush};
public:
	/* TcxCanvasBasedBrushHandle.Create */ inline __fastcall TcxGdiCanvasBasedBrushHandle(Dxcoregraphics::TdxAlphaColor AColor)/* overload */ : TcxCanvasBasedBrushHandle(AColor) { }
	/* TcxCanvasBasedBrushHandle.Create */ inline __fastcall TcxGdiCanvasBasedBrushHandle(TdxFillOptions* AOptions)/* overload */ : TcxCanvasBasedBrushHandle(AOptions) { }
	/* TcxCanvasBasedBrushHandle.Destroy */ inline __fastcall virtual ~TcxGdiCanvasBasedBrushHandle() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGdiCanvasBasedFontHandle : public TcxCanvasBasedFontHandle
{
	typedef TcxCanvasBasedFontHandle inherited;
	
private:
	Vcl::Graphics::TFont* FFont;
	Dxcore::TdxObjectOwnership FFontOwnership;
	
protected:
	virtual void __fastcall CreateNativeHandle(TcxCustomCanvas* ACanvas);
	virtual void __fastcall FreeNativeHandle();
	
public:
	__fastcall virtual TcxGdiCanvasBasedFontHandle(Vcl::Graphics::TFont* const AFont, Dxcore::TdxObjectOwnership AOwnership)/* overload */;
	__property Vcl::Graphics::TFont* Font = {read=FFont};
public:
	/* TcxCanvasBasedFontHandle.Create */ inline __fastcall TcxGdiCanvasBasedFontHandle(TdxFontOptions* const AFont)/* overload */ : TcxCanvasBasedFontHandle(AFont) { }
	
public:
	/* TcxCanvasBasedResourceHandle.Destroy */ inline __fastcall virtual ~TcxGdiCanvasBasedFontHandle() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGdiCanvasBasedImage : public TcxCanvasBasedImage
{
	typedef TcxCanvasBasedImage inherited;
	
private:
	Dxgdiplusclasses::TdxGPImage* FImage;
	Dxcore::TdxObjectOwnership FImageOwnership;
	
public:
	__fastcall TcxGdiCanvasBasedImage(TcxCustomCanvas* ACanvas, Dxgdiplusclasses::TdxGPImage* AImage, Dxcore::TdxObjectOwnership AOwnership);
	__fastcall virtual ~TcxGdiCanvasBasedImage();
	__property Dxgdiplusclasses::TdxGPImage* Image = {read=FImage};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGdiCanvasBasedPath : public TcxCanvasBasedPath
{
	typedef TcxCanvasBasedPath inherited;
	
private:
	Dxgdiplusclasses::TdxGPPath* FPath;
	
public:
	__fastcall TcxGdiCanvasBasedPath(TcxCustomCanvas* ACanvas);
	__fastcall virtual ~TcxGdiCanvasBasedPath();
	virtual void __fastcall AddArc(const Cxgeometry::TdxRectF &AEllipse, const float AStartAngle, const float ASweepAngle);
	virtual void __fastcall AddLine(const Cxgeometry::TdxPointF &P1, const Cxgeometry::TdxPointF &P2);
	virtual void __fastcall AddPolyline(Cxgeometry::PdxPointF Points, int Count)/* overload */;
	virtual void __fastcall FigureClose();
	virtual void __fastcall FigureStart();
	__property Dxgdiplusclasses::TdxGPPath* Path = {read=FPath};
	/* Hoisted overloads: */
	
public:
	inline void __fastcall  AddPolyline(const Cxgeometry::TdxPointF *Points, const int Points_High){ TcxCanvasBasedPath::AddPolyline(Points, Points_High); }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGdiCanvasBasedPenHandle : public TcxCanvasBasedPenHandle
{
	typedef TcxCanvasBasedPenHandle inherited;
	
protected:
	Dxgdiplusclasses::TdxGPPen* FPen;
	Dxcore::TdxObjectOwnership FPenOwnership;
	virtual void __fastcall CreateNativeHandle(TcxCustomCanvas* ACanvas);
	virtual void __fastcall FreeNativeHandle();
	
public:
	__fastcall TcxGdiCanvasBasedPenHandle(Dxgdiplusclasses::TdxGPPen* APen, Dxcore::TdxObjectOwnership AOwnership)/* overload */;
	virtual bool __fastcall IsEmpty();
	__property Dxgdiplusclasses::TdxGPPen* Pen = {read=FPen};
public:
	/* TcxCanvasBasedPenHandle.Create */ inline __fastcall TcxGdiCanvasBasedPenHandle(Dxcoregraphics::TdxAlphaColor AColor, float AWidth, TdxStrokeStyle AStyle)/* overload */ : TcxCanvasBasedPenHandle(AColor, AWidth, AStyle) { }
	/* TcxCanvasBasedPenHandle.Create */ inline __fastcall TcxGdiCanvasBasedPenHandle(TdxStrokeOptions* AOptions)/* overload */ : TcxCanvasBasedPenHandle(AOptions) { }
	
public:
	/* TcxCanvasBasedResourceHandle.Destroy */ inline __fastcall virtual ~TcxGdiCanvasBasedPenHandle() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGdiCanvasBasedTextLayout : public TcxCanvasBasedTextLayout
{
	typedef TcxCanvasBasedTextLayout inherited;
	
private:
	static System::Types::TSize __fastcall InternalCalcTextExtends(HDC DC, System::WideChar * AText, int ATextLength, bool AExpandTabs, TcxGdiCanvasBasedTextLayout* AData);
	Vcl::Graphics::TFont* __fastcall GetNativeFont();
	
protected:
	tagRGBQUAD FColor;
	Cxdrawtextutils::TcxTextRows FTextRows;
	virtual void __fastcall DoCalculate(int AMaxWidth, int AMaxHeight, int AMaxRowCount)/* overload */;
	virtual System::Types::TSize __fastcall DoCalculateTextExtends(HDC DC, System::WideChar * AText, int ATextLength, bool AExpandTabs);
	virtual void __fastcall DoDraw(const System::Types::TRect &R);
	virtual void __fastcall DoDrawCore(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DoSetFont(TcxCanvasBasedFontHandle* AFontHandle);
	
public:
	__fastcall TcxGdiCanvasBasedTextLayout(TcxCustomCanvas* ACanvas);
	__fastcall virtual ~TcxGdiCanvasBasedTextLayout();
	virtual void __fastcall SetColor(Dxcoregraphics::TdxAlphaColor AColor)/* overload */;
	__property Vcl::Graphics::TFont* NativeFont = {read=GetNativeFont};
	/* Hoisted overloads: */
	
protected:
	inline void __fastcall  DoCalculate(){ TcxCanvasBasedTextLayout::DoCalculate(); }
	
public:
	inline void __fastcall  SetColor(System::Uitypes::TColor AColor){ TcxCanvasBasedTextLayout::SetColor(AColor); }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGdiCanvasBasedSharedBrushes : public TcxCanvasBasedSharedBrushes
{
	typedef TcxCanvasBasedSharedBrushes inherited;
	
private:
	static TcxGdiCanvasBasedSharedBrushes* FInstance;
	
protected:
	__classmethod void __fastcall Finalize();
	
public:
	__classmethod Dxgdiplusclasses::TdxGPCustomBrush* __fastcall CreateBrush(TcxCanvasBasedBrushHandle* AOptions);
	__classmethod TcxGdiCanvasBasedSharedBrushes* __fastcall Instance();
public:
	/* TcxCanvasBasedSharedBrushes.Create */ inline __fastcall TcxGdiCanvasBasedSharedBrushes(TcxCustomCanvas* ACanvas, TcxCanvasBasedBrushHandleClass AClass) : TcxCanvasBasedSharedBrushes(ACanvas, AClass) { }
	
public:
	/* TcxCanvasBasedSharedResources.Destroy */ inline __fastcall virtual ~TcxGdiCanvasBasedSharedBrushes() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGdiCanvasBasedSharedFonts : public TcxCanvasBasedSharedFonts
{
	typedef TcxCanvasBasedSharedFonts inherited;
	
private:
	static TcxGdiCanvasBasedSharedFonts* FInstance;
	
protected:
	__classmethod void __fastcall Finalize();
	
public:
	__classmethod TcxGdiCanvasBasedSharedFonts* __fastcall Instance();
public:
	/* TcxCanvasBasedSharedFonts.Create */ inline __fastcall TcxGdiCanvasBasedSharedFonts(TcxCustomCanvas* ACanvas, TcxCanvasBasedFontHandleClass AClass) : TcxCanvasBasedSharedFonts(ACanvas, AClass) { }
	
public:
	/* TcxCanvasBasedSharedResources.Destroy */ inline __fastcall virtual ~TcxGdiCanvasBasedSharedFonts() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGdiCanvasBasedSharedImageLists : public TcxCanvasBasedSharedImageLists
{
	typedef TcxCanvasBasedSharedImageLists inherited;
	
private:
	static TcxGdiCanvasBasedSharedImageLists* FInstance;
	
protected:
	__classmethod void __fastcall Finalize();
	
public:
	__classmethod TcxGdiCanvasBasedSharedImageLists* __fastcall Instance();
public:
	/* TcxCanvasBasedSharedImageLists.Create */ inline __fastcall TcxGdiCanvasBasedSharedImageLists(TcxCustomCanvas* ACanvas, TcxCanvasBasedImageListHandleClass AClass) : TcxCanvasBasedSharedImageLists(ACanvas, AClass) { }
	
public:
	/* TcxCanvasBasedSharedResources.Destroy */ inline __fastcall virtual ~TcxGdiCanvasBasedSharedImageLists() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGdiCanvasBasedSharedPens : public TcxCanvasBasedSharedPens
{
	typedef TcxCanvasBasedSharedPens inherited;
	
private:
	static TcxGdiCanvasBasedSharedPens* FInstance;
	
protected:
	__classmethod void __fastcall Finalize();
	
public:
	__classmethod TcxGdiCanvasBasedSharedPens* __fastcall Instance();
public:
	/* TcxCanvasBasedSharedPens.Create */ inline __fastcall TcxGdiCanvasBasedSharedPens(TcxCustomCanvas* ACanvas, TcxCanvasBasedPenHandleClass AClass) : TcxCanvasBasedSharedPens(ACanvas, AClass) { }
	
public:
	/* TcxCanvasBasedSharedResources.Destroy */ inline __fastcall virtual ~TcxGdiCanvasBasedSharedPens() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
#define sdxInternalErrorFontNotSet L"Font is not set"
#define sdxInternalErrorResourceAbandoned L"Resource is in abandoned state"
#define sdxInternalErrorResourceOwnerMismatch L"Resource was created for different Canvas"
extern DELPHI_PACKAGE System::StaticArray<TcxRotationAngle, 4> cxOppositeRotationAngle;
extern DELPHI_PACKAGE System::StaticArray<int, 4> cxRotationAngleToAngle;
extern DELPHI_PACKAGE System::StaticArray<Dxgdiplusclasses::TdxGPBrushGradientMode, 4> dxFillOptionsGradientModeToBrushGradientMode;
extern DELPHI_PACKAGE bool __fastcall cxCopyDirectCanvasContentToGdiCanvas(TcxCustomCanvas* AActualCanvas, TcxGdiBasedCanvas* AGdiCanvas);
extern DELPHI_PACKAGE bool __fastcall cxIsCustomCanvasSupported(System::TObject* AObject);
}	/* namespace Cxcustomcanvas */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXCUSTOMCANVAS)
using namespace Cxcustomcanvas;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxcustomcanvasHPP
