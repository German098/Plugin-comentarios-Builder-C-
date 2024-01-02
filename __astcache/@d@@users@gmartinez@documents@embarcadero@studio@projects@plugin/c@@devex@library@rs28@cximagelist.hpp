// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxImageList.pas' rev: 35.00 (Windows)

#ifndef CximagelistHPP
#define CximagelistHPP

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
#include <System.Contnrs.hpp>
#include <dxCore.hpp>
#include <dxCoreGraphics.hpp>
#include <dxMessages.hpp>
#include <cxClasses.hpp>
#include <cxGeometry.hpp>
#include <dxGDIPlusClasses.hpp>
#include <dxGDIPlusAPI.hpp>
#include <dxSmartImage.hpp>
#include <dxDPIAwareUtils.hpp>
#include <System.ImageList.hpp>

//-- user supplied -----------------------------------------------------------

namespace Cximagelist
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS EcxUnsupportedImageListStreamFormat;
class DELPHICLASS TcxImageInfo;
class DELPHICLASS TcxImageInfoHelper;
class DELPHICLASS TcxBaseImageList;
class DELPHICLASS TcxCustomImageList;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION EcxUnsupportedImageListStreamFormat : public Dxcore::EdxException
{
	typedef Dxcore::EdxException inherited;
	
public:
	__fastcall EcxUnsupportedImageListStreamFormat();
public:
	/* Exception.CreateFmt */ inline __fastcall EcxUnsupportedImageListStreamFormat(const System::UnicodeString Msg, const System::TVarRec *Args, const int Args_High) : Dxcore::EdxException(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EcxUnsupportedImageListStreamFormat(NativeUInt Ident)/* overload */ : Dxcore::EdxException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EcxUnsupportedImageListStreamFormat(System::PResStringRec ResStringRec)/* overload */ : Dxcore::EdxException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxUnsupportedImageListStreamFormat(NativeUInt Ident, const System::TVarRec *Args, const int Args_High)/* overload */ : Dxcore::EdxException(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxUnsupportedImageListStreamFormat(System::PResStringRec ResStringRec, const System::TVarRec *Args, const int Args_High)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EcxUnsupportedImageListStreamFormat(const System::UnicodeString Msg, int AHelpContext) : Dxcore::EdxException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EcxUnsupportedImageListStreamFormat(const System::UnicodeString Msg, const System::TVarRec *Args, const int Args_High, int AHelpContext) : Dxcore::EdxException(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxUnsupportedImageListStreamFormat(NativeUInt Ident, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxUnsupportedImageListStreamFormat(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxUnsupportedImageListStreamFormat(System::PResStringRec ResStringRec, const System::TVarRec *Args, const int Args_High, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxUnsupportedImageListStreamFormat(NativeUInt Ident, const System::TVarRec *Args, const int Args_High, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EcxUnsupportedImageListStreamFormat() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxImageInfo : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::UnicodeString FFileName;
	Vcl::Graphics::TGraphic* FImage;
	Dxcore::TdxDefaultBoolean FIsAlphaUsed;
	System::UnicodeString FKeywords;
	Vcl::Graphics::TBitmap* FMask;
	System::Uitypes::TColor FMaskColor;
	void __fastcall AssignBitmap(Vcl::Graphics::TBitmap* ASourceBitmap, Vcl::Graphics::TBitmap* ADestBitmap);
	Vcl::Graphics::TGraphicClass __fastcall GetImageClass();
	System::UnicodeString __fastcall GetImageClassName();
	System::UnicodeString __fastcall GetImageType();
	bool __fastcall GetIsAlphaUsed();
	void __fastcall SetImage(Vcl::Graphics::TGraphic* Value);
	void __fastcall SetImageClass(Vcl::Graphics::TGraphicClass AValue);
	void __fastcall SetImageClassName(const System::UnicodeString Value);
	void __fastcall SetMask(Vcl::Graphics::TBitmap* Value);
	
private:
	Vcl::Graphics::TBitmap* FInternalMask;
	bool __fastcall HasMask();
	bool __fastcall HasNativeHandle();
	
public:
	__fastcall TcxImageInfo()/* overload */;
	__fastcall virtual ~TcxImageInfo();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall ConvertTo32Bit();
	void __fastcall Dormant();
	virtual bool __fastcall Equals(System::TObject* Obj);
	void __fastcall FlushMask();
	void __fastcall Reset();
	void __fastcall Resize(const System::Types::TSize &ASize);
	__property Vcl::Graphics::TGraphicClass ImageClass = {read=GetImageClass, write=SetImageClass};
	__property System::UnicodeString ImageType = {read=GetImageType};
	__property bool IsAlphaUsed = {read=GetIsAlphaUsed, nodefault};
	
__published:
	__property System::UnicodeString ImageClassName = {read=GetImageClassName, write=SetImageClassName};
	__property Vcl::Graphics::TGraphic* Image = {read=FImage, write=SetImage};
	__property Vcl::Graphics::TBitmap* Mask = {read=FMask, write=SetMask};
	__property System::Uitypes::TColor MaskColor = {read=FMaskColor, write=FMaskColor, nodefault};
	__property System::UnicodeString FileName = {read=FFileName, write=FFileName};
	__property System::UnicodeString Keywords = {read=FKeywords, write=FKeywords};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxImageInfoHelper : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod void __fastcall CopyRect(Vcl::Graphics::TBitmap* ADest, const System::Types::TRect &ADestRect, Vcl::Graphics::TGraphic* ASource)/* overload */;
	__classmethod void __fastcall CopyRect(Vcl::Graphics::TBitmap* ADest, const System::Types::TRect &ADestRect, Vcl::Graphics::TGraphic* ASource, const System::Types::TRect &ASourceRect)/* overload */;
	__classmethod System::Uitypes::TColor __fastcall GetDefaultTransparentColor(Vcl::Graphics::TGraphic* AImage, Vcl::Graphics::TBitmap* AMask);
	__classmethod System::Uitypes::TColor __fastcall GetPixel(Vcl::Graphics::TGraphic* AGraphic, int X, int Y);
	__classmethod Vcl::Graphics::TPixelFormat __fastcall GetPixelFormat(Vcl::Graphics::TGraphic* AGraphic);
	__classmethod bool __fastcall IsAlphaUsed(Vcl::Graphics::TGraphic* AGraphic);
	__classmethod void __fastcall Resize(Vcl::Graphics::TGraphic* AGraphic, const System::Types::TSize &ASize);
public:
	/* TObject.Create */ inline __fastcall TcxImageInfoHelper() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxImageInfoHelper() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxBaseImageList : public Vcl::Controls::TDragImageList
{
	typedef Vcl::Controls::TDragImageList inherited;
	
private:
	int FSourceDPI;
	int __fastcall GetSourceDPI();
	void __fastcall SetSourceDPI(int AValue);
	
protected:
	virtual void __fastcall Initialize();
	
public:
	virtual void __fastcall BeforeDestruction();
	
__published:
	__property int SourceDPI = {read=FSourceDPI, write=SetSourceDPI, nodefault};
public:
	/* TCustomImageList.Create */ inline __fastcall virtual TcxBaseImageList(System::Classes::TComponent* AOwner) : Vcl::Controls::TDragImageList(AOwner) { }
	/* TCustomImageList.CreateSize */ inline __fastcall TcxBaseImageList(int AWidth, int AHeight) : Vcl::Controls::TDragImageList(AWidth, AHeight) { }
	/* TCustomImageList.Destroy */ inline __fastcall virtual ~TcxBaseImageList() { }
	
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


class PASCALIMPLEMENTATION TcxCustomImageList : public TcxBaseImageList
{
	typedef TcxBaseImageList inherited;
	
private:
	static const int DXILSignature = int(0x4c495844);
	
	static const System::Int8 DXILVersion = System::Int8(0x1);
	
	bool FAlphaBlending;
	int FFormatVersion;
	System::Classes::TCollection* FImages;
	int FLockCount;
	int FSynchronizationLockCount;
	void __fastcall ReadDesignInfo(System::Classes::TReader* AReader);
	void __fastcall ReadFormatVersion(System::Classes::TReader* AReader);
	void __fastcall ReadImageInfo(System::Classes::TReader* AReader);
	void __fastcall WriteDesignInfo(System::Classes::TWriter* AWriter);
	void __fastcall WriteFormatVersion(System::Classes::TWriter* AWriter);
	void __fastcall WriteImageInfo(System::Classes::TWriter* AWriter);
	bool __fastcall IsSynchronizationLocked();
	void __fastcall SynchronizeImageInfo();
	void __fastcall SynchronizeHandle();
	void __fastcall AddToInternalCollection(Vcl::Graphics::TGraphic* AImage, Vcl::Graphics::TBitmap* AMask, System::Uitypes::TColor AMaskColor, const System::UnicodeString AKeywords, const System::UnicodeString AFileName);
	__classmethod void __fastcall CheckImageSize(Vcl::Graphics::TBitmap* AImage, int AWidth, int AHeight);
	void __fastcall DormantImage(int AIndex);
	int __fastcall GetImageCount(Vcl::Graphics::TGraphic* AImage, int AWidth, int AHeight);
	bool __fastcall GetCompressData();
	HIDESBASE NativeUInt __fastcall GetHandle();
	int __fastcall GetHeight();
	int __fastcall GetWidth();
	void __fastcall SetCompressData(bool Value);
	HIDESBASE void __fastcall SetHandle(NativeUInt Value);
	HIDESBASE void __fastcall SetHeight(int AValue);
	HIDESBASE void __fastcall SetWidth(int AValue);
	
protected:
	bool __fastcall ChangeLocked();
	virtual void __fastcall DoDraw(int Index, Vcl::Graphics::TCanvas* Canvas, int X, int Y, unsigned Style, bool Enabled = true);
	void __fastcall DoDrawEx(int AIndex, Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, unsigned AStyle, bool AStretch, bool ASmoothResize, bool AEnabled);
	virtual void __fastcall Initialize();
	void __fastcall Finalize();
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	void __fastcall Dormant();
	void __fastcall GetImageInfoCore(int AIndex, Vcl::Graphics::TBitmap* AImage, Vcl::Graphics::TBitmap* AMask, Dxcoregraphics::_di_IdxColorPalette APalette, Dxcore::TdxDefaultBoolean &AIsAlphaUsed)/* overload */;
	__classmethod void __fastcall GetImageInfoCore(Vcl::Imglist::TCustomImageList* AImages, int AIndex, Vcl::Graphics::TBitmap* AImage, Vcl::Graphics::TBitmap* AMask, Dxcoregraphics::_di_IdxColorPalette APalette, Dxcore::TdxDefaultBoolean &AIsAlphaUsed)/* overload */;
	int __fastcall AddCore(Vcl::Graphics::TGraphic* AImage, Vcl::Graphics::TBitmap* AMask, System::Uitypes::TColor AMaskColor, const System::UnicodeString AKeywords, const System::UnicodeString AFileName)/* overload */;
	int __fastcall AddImageInfo(TcxImageInfo* AImageInfo);
	bool __fastcall CanSplitImage(Vcl::Graphics::TGraphic* AImage);
	void __fastcall ConvertTo32bit();
	void __fastcall InternalCopyImageInfos(TcxCustomImageList* AImageList, int AStartIndex, int AEndIndex);
	void __fastcall InternalCopyImages(Vcl::Imglist::TCustomImageList* AImageList, int AStartIndex, int AEndIndex);
	TcxImageInfo* __fastcall GetImageInfo(int AIndex)/* overload */;
	bool __fastcall HasRasterImages();
	
public:
	__fastcall virtual ~TcxCustomImageList();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall Change();
	HIDESBASE int __fastcall Add(Vcl::Graphics::TBitmap* AImage, Vcl::Graphics::TBitmap* AMask)/* overload */;
	HIDESBASE int __fastcall Add(Dxgdiplusclasses::TdxSmartImage* AImage, const System::UnicodeString AKeywords = System::UnicodeString(), const System::UnicodeString ASourceFileName = System::UnicodeString())/* overload */;
	HIDESBASE int __fastcall Add(Vcl::Graphics::TGraphic* AImage, Vcl::Graphics::TBitmap* AMask)/* overload */;
	HIDESBASE int __fastcall AddIcon(Vcl::Graphics::TIcon* AIcon);
	HIDESBASE int __fastcall AddMasked(Vcl::Graphics::TGraphic* AImage, System::Uitypes::TColor AMaskColor);
	virtual bool __fastcall Equals(System::TObject* Obj);
	HIDESBASE void __fastcall Move(int ACurIndex, int ANewIndex);
	HIDESBASE void __fastcall Delete(int AIndex);
	int __fastcall AddBitmap(Vcl::Graphics::TBitmap* AImage, Vcl::Graphics::TBitmap* AMask, System::Uitypes::TColor AMaskColor, bool AStretch, bool ASmooth);
	HIDESBASE int __fastcall AddImage(Vcl::Imglist::TCustomImageList* AImages, int AIndex);
	void __fastcall AddImagesFromResZipStream(NativeUInt AInstance, const System::UnicodeString AResourceName, System::WideChar * AResType);
	void __fastcall AddImagesFromZipStream(System::Classes::TStream* AStream);
	int __fastcall AddImageFromResource(NativeUInt AInstance, const System::UnicodeString AResourceName, System::WideChar * AResType);
	HIDESBASE void __fastcall AddImages(Vcl::Imglist::TCustomImageList* AImages);
	HIDESBASE void __fastcall CopyImages(Vcl::Imglist::TCustomImageList* AImages, int AStartIndex = 0x0, int AEndIndex = 0xffffffff);
	HIDESBASE void __fastcall Clear();
	HIDESBASE void __fastcall Insert(int AIndex, Vcl::Graphics::TGraphic* AImage, Vcl::Graphics::TBitmap* AMask);
	HIDESBASE void __fastcall InsertIcon(int AIndex, Vcl::Graphics::TIcon* AIcon);
	HIDESBASE void __fastcall InsertMasked(int AIndex, Vcl::Graphics::TGraphic* AImage, System::Uitypes::TColor AMaskColor);
	HIDESBASE void __fastcall Replace(int AIndex, Vcl::Graphics::TGraphic* AImage, Vcl::Graphics::TBitmap* AMask);
	HIDESBASE void __fastcall ReplaceIcon(int AIndex, Vcl::Graphics::TIcon* AIcon);
	HIDESBASE void __fastcall ReplaceMasked(int AIndex, Vcl::Graphics::TGraphic* AImage, System::Uitypes::TColor AMaskColor);
	HIDESBASE void __fastcall DrawOverlay(Vcl::Graphics::TCanvas* Canvas, int X, int Y, int ImageIndex, Vcl::Imglist::TOverlay Overlay, bool Enabled = true)/* overload */;
	HIDESBASE void __fastcall DrawOverlay(Vcl::Graphics::TCanvas* Canvas, int X, int Y, int ImageIndex, Vcl::Imglist::TOverlay Overlay, Vcl::Imglist::TDrawingStyle ADrawingStyle, Vcl::Imglist::TImageType AImageType, bool Enabled = true)/* overload */;
	bool __fastcall LoadImage(NativeUInt AInstance, const System::UnicodeString AResourceName, System::Uitypes::TColor AMaskColor = (System::Uitypes::TColor)(0x20000000), int AWidth = 0x0, Vcl::Imglist::TLoadResources AFlags = Vcl::Imglist::TLoadResources() );
	HIDESBASE bool __fastcall FileLoad(Vcl::Imglist::TResType AResType, const System::UnicodeString AName, System::Uitypes::TColor AMaskColor);
	HIDESBASE bool __fastcall GetResource(Vcl::Imglist::TResType AResType, const System::UnicodeString AName, int AWidth, Vcl::Imglist::TLoadResources ALoadFlags, System::Uitypes::TColor AMaskColor);
	HIDESBASE bool __fastcall GetInstRes(NativeUInt AInstance, Vcl::Imglist::TResType AResType, const System::UnicodeString AName, int AWidth, Vcl::Imglist::TLoadResources ALoadFlags, System::Uitypes::TColor AMaskColor)/* overload */;
	HIDESBASE bool __fastcall GetInstRes(NativeUInt AInstance, Vcl::Imglist::TResType AResType, unsigned AResID, int AWidth, Vcl::Imglist::TLoadResources ALoadFlags, System::Uitypes::TColor AMaskColor)/* overload */;
	HIDESBASE bool __fastcall ResourceLoad(Vcl::Imglist::TResType AResType, const System::UnicodeString AName, System::Uitypes::TColor AMaskColor);
	HIDESBASE bool __fastcall ResInstLoad(NativeUInt AInstance, Vcl::Imglist::TResType AResType, const System::UnicodeString AName, System::Uitypes::TColor AMaskColor);
	void __fastcall LoadFromFile(const System::UnicodeString AFileName);
	void __fastcall LoadFromResource(NativeUInt AInstance, const System::UnicodeString AResourceName, System::WideChar * AResourceType);
	void __fastcall LoadFromStream(System::Classes::TStream* AStream);
	void __fastcall SaveToFile(const System::UnicodeString AFileName);
	void __fastcall SaveToStream(System::Classes::TStream* AStream);
	HIDESBASE void __fastcall BeginUpdate();
	void __fastcall CancelUpdate();
	HIDESBASE void __fastcall EndUpdate();
	HIDESBASE void __fastcall Draw(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, int AIndex, bool AStretch = true, bool ASmoothResize = false, bool AEnabled = true)/* overload */;
	void __fastcall GetImageInfo(int AIndex, Vcl::Graphics::TBitmap* AImage, Vcl::Graphics::TBitmap* AMask, Dxcoregraphics::_di_IdxColorPalette APalette = Dxcoregraphics::_di_IdxColorPalette())/* overload */;
	void __fastcall GetImage(int AIndex, Vcl::Graphics::TBitmap* AImage)/* overload */;
	void __fastcall GetImage(int AIndex, Dxgdiplusclasses::TdxSmartImage* AImage)/* overload */;
	void __fastcall GetMask(int AIndex, Vcl::Graphics::TBitmap* AMask);
	__classmethod void __fastcall GetImageInfo(Vcl::Imglist::TCustomImageList* AImages, int AIndex, Vcl::Graphics::TBitmap* AImage, Vcl::Graphics::TBitmap* AMask, Dxcoregraphics::_di_IdxColorPalette APalette = Dxcoregraphics::_di_IdxColorPalette())/* overload */;
	__classmethod void __fastcall GetImageInfo(NativeUInt AHandle, int AIndex, Vcl::Graphics::TBitmap* AImage, Vcl::Graphics::TBitmap* AMask)/* overload */;
	__classmethod int __fastcall GetPixelFormat(NativeUInt AHandle);
	__classmethod bool __fastcall IsEquals(Vcl::Imglist::TCustomImageList* AImages1, Vcl::Imglist::TCustomImageList* AImages2);
	void __fastcall Resize(const System::Types::TSize &ASize);
	HIDESBASE void __fastcall SetSize(int AWidth, int AHeight)/* overload */;
	HIDESBASE void __fastcall SetSize(const System::Types::TSize &ASize)/* overload */;
	__property bool AlphaBlending = {read=FAlphaBlending, write=FAlphaBlending, nodefault};
	__property NativeUInt Handle = {read=GetHandle, write=SetHandle, nodefault};
	
__published:
	__property BlendColor = {default=536870911};
	__property BkColor = {default=536870911};
	__property ColorDepth = {default=6};
	__property bool CompressData = {read=GetCompressData, write=SetCompressData, default=0};
	__property DrawingStyle = {default=2};
	__property int Height = {read=GetHeight, write=SetHeight, default=16};
	__property ImageType = {default=0};
	__property ShareImages = {default=0};
	__property int Width = {read=GetWidth, write=SetWidth, default=16};
	__property OnChange;
public:
	/* TCustomImageList.Create */ inline __fastcall virtual TcxCustomImageList(System::Classes::TComponent* AOwner) : TcxBaseImageList(AOwner) { }
	/* TCustomImageList.CreateSize */ inline __fastcall TcxCustomImageList(int AWidth, int AHeight) : TcxBaseImageList(AWidth, AHeight) { }
	
	/* Hoisted overloads: */
	
public:
	inline void __fastcall  Draw(Vcl::Graphics::TCanvas* Canvas, int X, int Y, int Index, bool Enabled = true){ Vcl::Imglist::TCustomImageList::Draw(Canvas, X, Y, Index, Enabled); }
	inline void __fastcall  Draw(Vcl::Graphics::TCanvas* Canvas, int X, int Y, int Index, Vcl::Imglist::TDrawingStyle ADrawingStyle, Vcl::Imglist::TImageType AImageType, bool Enabled = true){ Vcl::Imglist::TCustomImageList::Draw(Canvas, X, Y, Index, ADrawingStyle, AImageType, Enabled); }
	
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE unsigned __fastcall cxGetImageListStyle(Vcl::Imglist::TDrawingStyle ADrawingStyle, Vcl::Imglist::TImageType AImageType);
}	/* namespace Cximagelist */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXIMAGELIST)
using namespace Cximagelist;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CximagelistHPP
