// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxSmartImage.pas' rev: 35.00 (Windows)

#ifndef DxsmartimageHPP
#define DxsmartimageHPP

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
#include <Vcl.Graphics.hpp>
#include <System.Variants.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <dxCore.hpp>
#include <dxCoreGraphics.hpp>
#include <cxGeometry.hpp>

//-- user supplied -----------------------------------------------------------

namespace Dxsmartimage
{
//-- forward type declarations -----------------------------------------------
__interface DELPHIINTERFACE IdxAnimatedImage;
typedef System::DelphiInterface<IdxAnimatedImage> _di_IdxAnimatedImage;
__interface DELPHIINTERFACE IdxImageDataFormat;
typedef System::DelphiInterface<IdxImageDataFormat> _di_IdxImageDataFormat;
__interface DELPHIINTERFACE IdxImageDataFormatEx;
typedef System::DelphiInterface<IdxImageDataFormatEx> _di_IdxImageDataFormatEx;
__interface DELPHIINTERFACE IdxVectorImage;
typedef System::DelphiInterface<IdxVectorImage> _di_IdxVectorImage;
class DELPHICLASS TdxSmartImageCustomHandle;
class DELPHICLASS TdxSmartImageEmptyHandle;
class DELPHICLASS TdxSmartImageCodec;
class DELPHICLASS TdxSmartImageAnimationController;
class DELPHICLASS TdxSmartImageDataStream;
class DELPHICLASS TdxSmartImageData;
class DELPHICLASS TdxCustomSmartImage;
class DELPHICLASS TdxSmartImageCodecsRepository;
class DELPHICLASS TdxSmartImageHelper;
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TdxSmartImageCodecClass;

enum DECLSPEC_DENUM TdxImageDataFormat : unsigned char { dxImageUnknown, dxImageBitmap, dxImageJpeg, dxImagePng, dxImageTiff, dxImageGif, dxImageEmf, dxImageExif, dxImageIcon, dxImageMemoryBmp, dxImageWmf };

__interface  INTERFACE_UUID("{511C08FA-ED2A-4998-95BB-CBAED1D39BA9}") IdxAnimatedImage  : public System::IInterface 
{
	virtual unsigned __fastcall GetActiveFrame() = 0 ;
	virtual unsigned __fastcall GetAnimationFrameCount() = 0 ;
	virtual int __fastcall GetAnimationFrameDelay() = 0 ;
	virtual int __fastcall GetAnimationLoopCount() = 0 ;
	virtual void __fastcall SetActiveFrame(unsigned AValue) = 0 ;
};

__interface  INTERFACE_UUID("{19993C97-DF15-4E67-A250-77BACBF5DB64}") IdxImageDataFormat  : public System::IInterface 
{
	virtual TdxImageDataFormat __fastcall GetImageFormat() = 0 ;
};

__interface  INTERFACE_UUID("{F54CB0CE-F15C-4EE2-9323-F95B65BB9769}") IdxImageDataFormatEx  : public System::IInterface 
{
	virtual TdxSmartImageCodecClass __fastcall GetImageFormat() = 0 ;
};

__interface  INTERFACE_UUID("{F7B61E70-B4E6-4A23-862B-117530E00EB2}") IdxVectorImage  : public System::IInterface 
{
	
};

typedef System::TMetaClass* TdxSmartImageCustomHandleClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSmartImageCustomHandle : public System::Classes::TInterfacedPersistent
{
	typedef System::Classes::TInterfacedPersistent inherited;
	
private:
	System::Types::TRect __fastcall GetClientRect();
	int __fastcall GetHeight();
	int __fastcall GetWidth();
	
protected:
	virtual System::Types::TSize __fastcall GetSize() = 0 ;
	virtual void __fastcall SetSize(const System::Types::TSize &AValue);
	
public:
	virtual bool __fastcall Empty();
	virtual bool __fastcall Equals(System::TObject* Obj);
	virtual Dxcoregraphics::TdxAlphaState __fastcall GetAlphaState();
	virtual Vcl::Graphics::TBitmap* __fastcall GetAsBitmap();
	virtual Dxcoregraphics::TRGBColors __fastcall GetAsBitmapBits();
	virtual int __fastcall GetHashCode();
	virtual void __fastcall Draw(HDC DC, const Cxgeometry::TdxRectF &ADest, const Cxgeometry::TdxRectF &ASource, System::Byte AAlpha = (System::Byte)(0xff), Dxcoregraphics::_di_IdxColorPalette APalette = Dxcoregraphics::_di_IdxColorPalette())/* overload */;
	virtual void __fastcall Draw(HDC DC, const System::Types::TRect &ADest, const System::Types::TRect &ASource, System::Byte AAlpha = (System::Byte)(0xff), Dxcoregraphics::_di_IdxColorPalette APalette = Dxcoregraphics::_di_IdxColorPalette()) = 0 /* overload */;
	__property System::Types::TRect ClientRect = {read=GetClientRect};
	__property int Height = {read=GetHeight, nodefault};
	__property System::Types::TSize Size = {read=GetSize, write=SetSize};
	__property int Width = {read=GetWidth, nodefault};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxSmartImageCustomHandle() { }
	
public:
	/* TObject.Create */ inline __fastcall TdxSmartImageCustomHandle() : System::Classes::TInterfacedPersistent() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSmartImageEmptyHandle : public TdxSmartImageCustomHandle
{
	typedef TdxSmartImageCustomHandle inherited;
	
protected:
	virtual System::Types::TSize __fastcall GetSize();
	
public:
	virtual bool __fastcall Empty();
	virtual void __fastcall Draw(HDC DC, const System::Types::TRect &ADest, const System::Types::TRect &ASource, System::Byte AAlpha = (System::Byte)(0xff), Dxcoregraphics::_di_IdxColorPalette APalette = Dxcoregraphics::_di_IdxColorPalette())/* overload */;
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxSmartImageEmptyHandle() { }
	
public:
	/* TObject.Create */ inline __fastcall TdxSmartImageEmptyHandle() : TdxSmartImageCustomHandle() { }
	
	/* Hoisted overloads: */
	
public:
	inline void __fastcall  Draw(HDC DC, const Cxgeometry::TdxRectF &ADest, const Cxgeometry::TdxRectF &ASource, System::Byte AAlpha = (System::Byte)(0xff), Dxcoregraphics::_di_IdxColorPalette APalette = Dxcoregraphics::_di_IdxColorPalette()){ TdxSmartImageCustomHandle::Draw(DC, ADest, ASource, AAlpha, APalette); }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSmartImageCodec : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	__classmethod virtual Vcl::Graphics::TGraphicClass __fastcall GetGraphicClassForRegistrationInVCL();
	__classmethod virtual TdxImageDataFormat __fastcall ID();
	
public:
	__classmethod virtual System::UnicodeString __fastcall Description();
	__classmethod virtual System::UnicodeString __fastcall Extensions();
	__classmethod virtual System::UnicodeString __fastcall MimeType();
	__classmethod virtual System::Word __fastcall GetClipboardFormatId();
	__classmethod virtual bool __fastcall GetSize(System::Classes::TStream* AStream, /* out */ System::Types::TSize &ASize);
	__classmethod virtual bool __fastcall CanLoadFromBits();
	__classmethod virtual bool __fastcall CanLoadStream(System::Classes::TStream* AStream);
	__classmethod virtual bool __fastcall CanSaveImage(TdxSmartImageCustomHandle* AHandle);
	__classmethod virtual bool __fastcall Load(const Dxcoregraphics::TRGBColors ABits, Vcl::Graphics::TAlphaFormat AAlphaFormat, int AWidth, int AHeight, /* out */ TdxSmartImageCustomHandle* &AHandle)/* overload */;
	__classmethod virtual bool __fastcall Load(System::Classes::TStream* AStream, /* out */ TdxSmartImageCustomHandle* &AHandle)/* overload */;
	__classmethod virtual bool __fastcall Save(System::Classes::TStream* AStream, TdxSmartImageCustomHandle* AHandle);
public:
	/* TObject.Create */ inline __fastcall TdxSmartImageCodec() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSmartImageCodec() { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TdxSmartImageAnimationControllerClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSmartImageAnimationController : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxCustomSmartImage* FImage;
	bool __fastcall GetActive();
	
protected:
	virtual void __fastcall ActivateTimer();
	virtual void __fastcall DeactivateTimer();
	virtual bool __fastcall IsTimerActive();
	virtual void __fastcall TimerHandler(System::TObject* Sender);
	
public:
	__fastcall virtual TdxSmartImageAnimationController(TdxCustomSmartImage* AImage);
	__fastcall virtual ~TdxSmartImageAnimationController();
	void __fastcall StartAnimation();
	void __fastcall StopAnimation();
	__property bool Active = {read=GetActive, nodefault};
	__property TdxCustomSmartImage* Image = {read=FImage};
};

#pragma pack(pop)

typedef System::TMetaClass* TdxSmartImageDataStreamClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSmartImageDataStream : public System::Classes::TMemoryStream
{
	typedef System::Classes::TMemoryStream inherited;
	
public:
	TdxSmartImageDataStream* __fastcall Clone();
public:
	/* TMemoryStream.Destroy */ inline __fastcall virtual ~TdxSmartImageDataStream() { }
	
public:
	/* TObject.Create */ inline __fastcall TdxSmartImageDataStream() : System::Classes::TMemoryStream() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSmartImageData : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FTransparent;
	System::Uitypes::TColor FTransparentColor;
	Vcl::Graphics::TTransparentMode FTransparentMode;
	bool __fastcall GetIsEmpty();
	
protected:
	Dxcoregraphics::TRGBColors FBits;
	Vcl::Graphics::TAlphaFormat FBitsFormat;
	TdxSmartImageDataStream* FData;
	System::Types::TSize FNewSize;
	System::Types::TSize FSize;
	void __fastcall ApplyMask();
	void __fastcall Assign(TdxSmartImageData* AData);
	void __fastcall FreeImageData();
	void __fastcall LoadFromBitmap(Vcl::Graphics::TBitmap* const ABitmap);
	void __fastcall LoadFromBits(const Dxcoregraphics::TRGBColors ABits, const System::Types::TSize &ASize, Vcl::Graphics::TAlphaFormat AAlphaFormat);
	void __fastcall LoadFromStream(System::Classes::TStream* AStream);
	
public:
	__fastcall virtual ~TdxSmartImageData();
	__property bool Transparent = {read=FTransparent, write=FTransparent, nodefault};
	__property System::Uitypes::TColor TransparentColor = {read=FTransparentColor, write=FTransparentColor, nodefault};
	__property Vcl::Graphics::TTransparentMode TransparentMode = {read=FTransparentMode, write=FTransparentMode, nodefault};
	__property bool Empty = {read=GetIsEmpty, nodefault};
public:
	/* TObject.Create */ inline __fastcall TdxSmartImageData() : System::TObject() { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TdxCustomSmartImageClass;

class PASCALIMPLEMENTATION TdxCustomSmartImage : public Vcl::Graphics::TGraphic
{
	typedef Vcl::Graphics::TGraphic inherited;
	
private:
	Dxcoregraphics::TdxAlphaState FAlphaState;
	bool FAlphaStateAssigned;
	TdxSmartImageAnimationController* FAnimationController;
	int FAnimationFrameDelay;
	Dxcore::TdxDefaultBoolean FAnimationLoop;
	int FAnimationLoopIndex;
	TdxSmartImageCustomHandle* FCache;
	GUID FCachePaletteID;
	TdxSmartImageCustomHandle* FHandle;
	TdxSmartImageData* FImageData;
	bool FUseCache;
	void __fastcall Check(bool AResult, const System::UnicodeString AMessage);
	unsigned __fastcall GetActiveFrame();
	Dxcoregraphics::TdxAlphaState __fastcall GetAlphaState();
	bool __fastcall GetAnimation();
	unsigned __fastcall GetAnimationFrameCount();
	int __fastcall GetAnimationFrameDelay();
	int __fastcall GetAnimationLoopCount();
	System::Types::TRect __fastcall GetClientRect();
	TdxSmartImageCustomHandle* __fastcall GetHandle();
	bool __fastcall GetHandleAllocated();
	TdxImageDataFormat __fastcall GetImageDataFormat();
	bool __fastcall GetIsAlphaUsed();
	System::Types::TSize __fastcall GetSize();
	void __fastcall SetActiveFrame(unsigned AValue);
	void __fastcall SetAnimation(bool AValue);
	void __fastcall SetAnimationFrameDelay(int AValue);
	void __fastcall SetHandle(TdxSmartImageCustomHandle* const Value);
	void __fastcall SetImageCodec(const TdxSmartImageCodecClass AValue);
	void __fastcall SetImageDataFormat(TdxImageDataFormat AValue);
	void __fastcall SetUseCache(const bool Value);
	
protected:
	bool __fastcall CanStartAnimation();
	virtual bool __fastcall CanCreateCache(const System::Types::TSize &ASourceSize, const System::Types::TSize &ATargetSize);
	bool __fastcall CheckCache(const System::Types::TSize &ASize, const Dxcoregraphics::_di_IdxColorPalette APalette);
	virtual TdxSmartImageCustomHandle* __fastcall CreateCache(const System::Types::TSize &ASize);
	virtual bool __fastcall IsBitmapStream(System::Classes::TStream* AStream);
	virtual bool __fastcall AssignFromClipboard();
	virtual void __fastcall AssignFromGraphic(Vcl::Graphics::TGraphic* AGraphic);
	virtual void __fastcall AssignFromSmartImage(TdxCustomSmartImage* AImage);
	virtual void __fastcall AssignTo(System::Classes::TPersistent* ADest);
	virtual void __fastcall AssignToMetaFile(Vcl::Graphics::TMetafile* ADest);
	virtual void __fastcall CreateHandleFromBitmap(Vcl::Graphics::TBitmap* ABitmap);
	void __fastcall CreateHandleFromBits(int AWidth, int AHeight, const Dxcoregraphics::TRGBColors ABits, Vcl::Graphics::TAlphaFormat AAlphaFormat);
	void __fastcall CreateHandleFromHBITMAP(HBITMAP ABitmap, HPALETTE APalette);
	void __fastcall CreateHandleFromImageData();
	void __fastcall CreateHandleFromStream(System::Classes::TStream* AStream);
	TdxSmartImageDataStream* __fastcall ExportToStream(TdxSmartImageCodecClass ACodec);
	virtual void __fastcall FreeHandle();
	virtual void __fastcall PopulateImageDataFromHandle();
	HIDESBASE void __fastcall Changed()/* overload */;
	virtual void __fastcall Changed(System::TObject* Sender)/* overload */;
	void __fastcall CheckIsImageDataValid();
	virtual void __fastcall Draw(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual bool __fastcall Equals(Vcl::Graphics::TGraphic* Graphic)/* overload */;
	virtual bool __fastcall GetEmpty();
	virtual int __fastcall GetHeight();
	virtual TdxSmartImageCodecClass __fastcall GetImageCodec();
	virtual bool __fastcall GetTransparent();
	virtual int __fastcall GetWidth();
	bool __fastcall ResizeCore(const System::Types::TSize &ASize);
	virtual void __fastcall SetHeight(int Value);
	virtual void __fastcall SetWidth(int Value);
	__property Dxcoregraphics::TdxAlphaState AlphaState = {read=GetAlphaState, nodefault};
	__property TdxSmartImageAnimationController* AnimationController = {read=FAnimationController};
	__property TdxSmartImageCustomHandle* Handle = {read=GetHandle, write=SetHandle};
	__property TdxSmartImageData* ImageData = {read=FImageData};
	__property bool UseCache = {read=FUseCache, write=SetUseCache, nodefault};
	
public:
	__fastcall virtual TdxCustomSmartImage()/* overload */;
	__fastcall TdxCustomSmartImage(const System::Types::TRect &ARect, Dxcoregraphics::TdxAlphaColor AColor)/* overload */;
	__fastcall TdxCustomSmartImage(const System::Types::TSize &ASize, Dxcoregraphics::TdxAlphaColor AColor)/* overload */;
	__fastcall virtual TdxCustomSmartImage(int AWidth, int AHeight, Dxcoregraphics::TdxAlphaColor AColor)/* overload */;
	__fastcall virtual TdxCustomSmartImage(Vcl::Graphics::TBitmap* ABitmap);
	__fastcall virtual TdxCustomSmartImage(HBITMAP ABitmap);
	__fastcall virtual TdxCustomSmartImage(int AWidth, int AHeight, const Dxcoregraphics::TRGBColors ABits, bool AHasAlphaChannel)/* overload */;
	__fastcall virtual TdxCustomSmartImage(int AWidth, int AHeight, const Dxcoregraphics::TRGBColors ABits, Vcl::Graphics::TAlphaFormat AAlphaFormat)/* overload */;
	__fastcall virtual TdxCustomSmartImage(int AWidth, int AHeight, const Winapi::Windows::PRGBQuad ABits, Vcl::Graphics::TAlphaFormat AAlphaFormat)/* overload */;
	__fastcall TdxCustomSmartImage(const System::UnicodeString AFileName);
	__fastcall virtual TdxCustomSmartImage(System::Classes::TStream* AStream);
	__fastcall virtual ~TdxCustomSmartImage();
	virtual void __fastcall Assign(System::Classes::TPersistent* ASource);
	void __fastcall LoadFromBits(int AWidth, int AHeight, const Dxcoregraphics::TRGBColors ABits, bool AHasAlphaChannel)/* overload */;
	void __fastcall LoadFromBits(int AWidth, int AHeight, const Dxcoregraphics::TRGBColors ABits, Vcl::Graphics::TAlphaFormat AAlphaFormat)/* overload */;
	virtual void __fastcall LoadFromClipboardFormat(System::Word AFormat, NativeUInt AData, HPALETTE APalette);
	void __fastcall LoadFromFieldValue(const System::Variant &AValue);
	void __fastcall LoadFromResource(NativeUInt AInstance, const System::UnicodeString AResName, System::WideChar * AResType);
	virtual void __fastcall LoadFromStream(System::Classes::TStream* AStream);
	virtual void __fastcall SaveToClipboardFormat(System::Word &AFormat, NativeUInt &AData, HPALETTE &APalette);
	virtual void __fastcall SaveToFile(const System::UnicodeString Filename);
	virtual void __fastcall SaveToStream(System::Classes::TStream* AStream);
	void __fastcall SaveToStreamByCodec(System::Classes::TStream* AStream, TdxSmartImageCodecClass ACodec)/* overload */;
	void __fastcall SaveToStreamByCodec(System::Classes::TStream* AStream, TdxImageDataFormat AFormat)/* overload */;
	__classmethod virtual bool __fastcall IsSupportClipboardFormat(System::Word AFormat);
	__classmethod virtual bool __fastcall HasClipboardFormat();
	void __fastcall CopyToClipboard();
	void __fastcall CutToClipboard();
	void __fastcall PasteFromClipboard();
	virtual void __fastcall Clear();
	TdxCustomSmartImage* __fastcall Clone();
	virtual void __fastcall ChangeColor(System::Uitypes::TColor AColor);
	virtual bool __fastcall Compare(TdxCustomSmartImage* AImage);
	void __fastcall ConvertToBitmap();
	void __fastcall Dormant();
	virtual Vcl::Graphics::TBitmap* __fastcall GetAsBitmap();
	Dxcoregraphics::TRGBColors __fastcall GetBitmapBits();
	virtual int __fastcall GetHashCode();
	void __fastcall HandleNeeded();
	virtual void __fastcall Resize(const int AWidth, const int AHeight)/* overload */;
	void __fastcall Resize(const System::Types::TSize &ASize)/* overload */;
	virtual void __fastcall SetBitmap(Vcl::Graphics::TBitmap* ABitmap);
	void __fastcall Scale(const int M, const int D);
	void __fastcall StartAnimation();
	void __fastcall StopAnimation();
	void __fastcall StretchDraw(HDC DC, const Cxgeometry::TdxRectF &ADest, const Cxgeometry::TdxRectF &ASource, System::Byte AAlpha = (System::Byte)(0xff), Dxcoregraphics::_di_IdxColorPalette APalette = Dxcoregraphics::_di_IdxColorPalette())/* overload */;
	void __fastcall StretchDraw(HDC DC, const System::Types::TRect &ADest, const System::Types::TRect &ASource, System::Byte AAlpha = (System::Byte)(0xff), Dxcoregraphics::_di_IdxColorPalette APalette = Dxcoregraphics::_di_IdxColorPalette())/* overload */;
	void __fastcall StretchDraw(HDC DC, const System::Types::TRect &ADest, System::Byte AAlpha = (System::Byte)(0xff), Dxcoregraphics::_di_IdxColorPalette APalette = Dxcoregraphics::_di_IdxColorPalette())/* overload */;
	void __fastcall StretchDraw(HDC DC, const Cxgeometry::TdxRectF &ADest, System::Byte AAlpha = (System::Byte)(0xff), Dxcoregraphics::_di_IdxColorPalette APalette = Dxcoregraphics::_di_IdxColorPalette())/* overload */;
	virtual HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	__property unsigned ActiveFrame = {read=GetActiveFrame, write=SetActiveFrame, nodefault};
	__property bool Animation = {read=GetAnimation, write=SetAnimation, nodefault};
	__property unsigned AnimationFrameCount = {read=GetAnimationFrameCount, nodefault};
	__property int AnimationFrameDelay = {read=GetAnimationFrameDelay, write=SetAnimationFrameDelay, nodefault};
	__property Dxcore::TdxDefaultBoolean AnimationLoop = {read=FAnimationLoop, write=FAnimationLoop, default=1};
	__property int AnimationLoopIndex = {read=FAnimationLoopIndex, write=FAnimationLoopIndex, nodefault};
	__property int AnimationLoopCount = {read=GetAnimationLoopCount, nodefault};
	__property System::Types::TRect ClientRect = {read=GetClientRect};
	__property bool HandleAllocated = {read=GetHandleAllocated, nodefault};
	__property TdxSmartImageCodecClass ImageCodec = {read=GetImageCodec, write=SetImageCodec};
	__property TdxImageDataFormat ImageDataFormat = {read=GetImageDataFormat, write=SetImageDataFormat, nodefault};
	__property bool IsAlphaUsed = {read=GetIsAlphaUsed, nodefault};
	__property System::Types::TSize Size = {read=GetSize};
	/* Hoisted overloads: */
	
public:
	inline bool __fastcall  Equals(System::TObject* Obj){ return Vcl::Graphics::TGraphic::Equals(Obj); }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSmartImageCodecsRepository : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	static bool FInitialized;
	static System::Classes::TList* FList;
	static System::Classes::TList* FRegisteredClasses;
	static bool FRegisterInVCL;
	static int __fastcall GetCount();
	static TdxSmartImageCodecClass __fastcall GetItem(int Index);
	static void __fastcall SetRegisterInVCL(bool AValue);
	__classmethod System::DynamicArray<System::UnicodeString> __fastcall SplitExtensions(const System::UnicodeString ExtList);
	
protected:
	__classmethod void __fastcall CheckInitialized();
	__classmethod void __fastcall DoRegisterInVCL(TdxSmartImageCodecClass ACodec);
	__classmethod void __fastcall DoUnregisterFromVCL(TdxSmartImageCodecClass ACodec);
	
public:
	__classmethod bool __fastcall Contains(TdxSmartImageCodecClass ACodec);
	__classmethod System::UnicodeString __fastcall GetDefaultExt(TdxSmartImageCodecClass ACodec);
	__classmethod TdxSmartImageCodecClass __fastcall GetFormatByExt(const System::UnicodeString Ext);
	__classmethod TdxSmartImageCodecClass __fastcall GetFormatByID(TdxImageDataFormat ID);
	__classmethod TdxSmartImageCodecClass __fastcall GetFormatFromStream(System::Classes::TStream* AStream);
	__classmethod bool __fastcall GetImageInfo(const System::UnicodeString AFileName, /* out */ System::Types::TSize &ASize, /* out */ TdxSmartImageCodecClass &ACodec)/* overload */;
	__classmethod bool __fastcall GetImageInfo(TdxSmartImageData* const AImageData, /* out */ System::Types::TSize &ASize, /* out */ TdxSmartImageCodecClass &ACodec)/* overload */;
	__classmethod bool __fastcall GetImageInfo(System::Classes::TStream* const AStream, /* out */ System::Types::TSize &ASize, /* out */ TdxSmartImageCodecClass &ACodec)/* overload */;
	__classmethod bool __fastcall CanLoad(const System::UnicodeString AFileName)/* overload */;
	__classmethod bool __fastcall CanLoad(System::Classes::TStream* const AStream)/* overload */;
	__classmethod System::UnicodeString __fastcall GetOpenDialogFilter();
	__classmethod System::UnicodeString __fastcall GetSaveDialogFilter(TdxSmartImageCustomHandle* AHandle = (TdxSmartImageCustomHandle*)(0x0));
	__classmethod System::UnicodeString __fastcall GetSupportedExtensions();
	__classmethod bool __fastcall Load(const Dxcoregraphics::TRGBColors ABits, Vcl::Graphics::TAlphaFormat AAlphaFormat, int AWidth, int AHeight, /* out */ TdxSmartImageCustomHandle* &AHandle)/* overload */;
	__classmethod bool __fastcall Load(TdxSmartImageData* const AImageData, /* out */ TdxSmartImageCustomHandle* &AHandle)/* overload */;
	__classmethod bool __fastcall Load(System::Classes::TStream* const AStream, /* out */ TdxSmartImageCustomHandle* &AHandle)/* overload */;
	__classmethod void __fastcall Register(TdxSmartImageCodecClass ACodec);
	__classmethod void __fastcall Unregister(TdxSmartImageCodecClass ACodec);
	/* static */ __property int Count = {read=GetCount, nodefault};
	/* static */ __property TdxSmartImageCodecClass Items[int Index] = {read=GetItem};
	/* static */ __property bool RegisterInVCL = {read=FRegisterInVCL, write=SetRegisterInVCL, nodefault};
public:
	/* TObject.Create */ inline __fastcall TdxSmartImageCodecsRepository() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSmartImageCodecsRepository() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSmartImageHelper : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod Dxcoregraphics::TRGBColors __fastcall AllocColors(int AWidth, int AHeight, Dxcoregraphics::TdxAlphaColor AColor = (Dxcoregraphics::TdxAlphaColor)(0x0));
	__classmethod bool __fastcall HasAlpha(const Dxcoregraphics::TRGBColors ABits);
public:
	/* TObject.Create */ inline __fastcall TdxSmartImageHelper() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSmartImageHelper() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE TdxSmartImageAnimationControllerClass ImageAnimationControllerClass;
extern DELPHI_PACKAGE System::StaticArray<System::Word, 11> ImageClipboardFormats;
extern DELPHI_PACKAGE System::UnicodeString dxSmartImageCodecDescriptionSuffix;
}	/* namespace Dxsmartimage */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSMARTIMAGE)
using namespace Dxsmartimage;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxsmartimageHPP
