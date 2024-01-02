// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxFading.pas' rev: 35.00 (Windows)

#ifndef DxfadingHPP
#define DxfadingHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Types.hpp>
#include <Winapi.Windows.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <dxCore.hpp>
#include <dxCoreGraphics.hpp>
#include <dxCoreClasses.hpp>
#include <cxGraphics.hpp>
#include <dxGDIPlusClasses.hpp>
#include <dxGDIPlusAPI.hpp>
#include <cxClasses.hpp>
#include <cxLookAndFeelPainters.hpp>
#include <cxCustomCanvas.hpp>
#include <System.UITypes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Dxfading
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TdxFadingOptions;
__interface DELPHIINTERFACE IdxFadingObject;
typedef System::DelphiInterface<IdxFadingObject> _di_IdxFadingObject;
__interface DELPHIINTERFACE IdxFadingObjectFadingOptions;
typedef System::DelphiInterface<IdxFadingObjectFadingOptions> _di_IdxFadingObjectFadingOptions;
class DELPHICLASS TdxFadingElement;
class DELPHICLASS TdxFadingObjectHelper;
class DELPHICLASS TdxFadingList;
class DELPHICLASS TdxFadingHelper;
class DELPHICLASS TdxFader;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TdxFadingObjectState : unsigned char { fosNone, fosGetParams, fosFading };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFadingOptions : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	int FFadeInFrameCount;
	int FFadeInFrameDelay;
	int FFadeOutFrameCount;
	int FFadeOutFrameDelay;
	bool __fastcall IsFadeInFrameCountStored();
	bool __fastcall IsFadeInFrameDelayStored();
	bool __fastcall IsFadeOutFrameCountStored();
	bool __fastcall IsFadeOutFrameDelayStored();
	void __fastcall SetFadeInFrameCount(int AValue);
	void __fastcall SetFadeInFrameDelay(int AValue);
	void __fastcall SetFadeOutFrameCount(int AValue);
	void __fastcall SetFadeOutFrameDelay(int AValue);
	
public:
	__fastcall TdxFadingOptions();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property int FadeInFrameCount = {read=FFadeInFrameCount, write=SetFadeInFrameCount, stored=IsFadeInFrameCountStored, nodefault};
	__property int FadeInFrameDelay = {read=FFadeInFrameDelay, write=SetFadeInFrameDelay, stored=IsFadeInFrameDelayStored, nodefault};
	__property int FadeOutFrameCount = {read=FFadeOutFrameCount, write=SetFadeOutFrameCount, stored=IsFadeOutFrameCountStored, nodefault};
	__property int FadeOutFrameDelay = {read=FFadeOutFrameDelay, write=SetFadeOutFrameDelay, stored=IsFadeOutFrameDelayStored, nodefault};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxFadingOptions() { }
	
};

#pragma pack(pop)

__interface  INTERFACE_UUID("{73AB2A92-CDD9-4F13-965A-DC799DE837F9}") IdxFadingObject  : public System::IInterface 
{
	virtual bool __fastcall CanFade() = 0 ;
	virtual void __fastcall DrawFadeImage() = 0 ;
	virtual void __fastcall GetFadingImages(/* out */ Cxgraphics::TcxBitmap* &AFadeOutImage, /* out */ Cxgraphics::TcxBitmap* &AFadeInImage) = 0 ;
};

__interface  INTERFACE_UUID("{FAAAF4F8-7F10-42CD-9368-2BB5A1F1482B}") IdxFadingObjectFadingOptions  : public System::IInterface 
{
	virtual TdxFadingOptions* __fastcall GetFadingOptions() = 0 ;
};

enum DECLSPEC_DENUM TdxFadingState : unsigned char { fsFadeIn, fsFadeOut };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFadingElement : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	int FAnimationFrameCount;
	int FAnimationFrameDelay;
	int FDelayCount;
	int FDelayIndex;
	System::TObject* FElement;
	_di_IdxFadingObject FFadingObject;
	System::Types::TSize FImageSize;
	TdxFader* FOwner;
	int FStage;
	Dxgdiplusclasses::TdxGPImage* FWorkImage;
	void __fastcall SetWorkImage(Dxgdiplusclasses::TdxGPImage* AImage);
	
protected:
	Dxcoregraphics::TRGBColors FImage1Colors;
	Dxcoregraphics::TRGBColors FImage2Colors;
	void __fastcall BuildWorkImage();
	void __fastcall ProcessFadeStep();
	void __fastcall SetAnimationParams(int AAnimationFrameCount, int AAnimationFrameDelay);
	void __fastcall SetImages(Vcl::Graphics::TBitmap* AImage1, Vcl::Graphics::TBitmap* AImage2);
	__property System::Types::TSize ImageSize = {read=FImageSize};
	__property TdxFader* Owner = {read=FOwner};
	
public:
	__fastcall TdxFadingElement(TdxFader* AOwner, System::TObject* AElement);
	__fastcall virtual ~TdxFadingElement();
	bool __fastcall DrawImage(HDC DC, const System::Types::TRect &R)/* overload */;
	bool __fastcall DrawImage(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R)/* overload */;
	void __fastcall Finalize();
	__property int AnimationFrameCount = {read=FAnimationFrameCount, nodefault};
	__property int AnimationFrameDelay = {read=FAnimationFrameDelay, nodefault};
	__property System::TObject* Element = {read=FElement};
	__property Dxgdiplusclasses::TdxGPImage* WorkImage = {read=FWorkImage, write=SetWorkImage};
	__property int Stage = {read=FStage, write=FStage, nodefault};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFadingObjectHelper : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	bool __fastcall GetActive();
	
protected:
	virtual bool __fastcall CanFade();
	virtual void __fastcall DrawFadeImage();
	virtual void __fastcall GetFadingImages(/* out */ Cxgraphics::TcxBitmap* &AFadeOutImage, /* out */ Cxgraphics::TcxBitmap* &AFadeInImage);
	
public:
	__fastcall virtual ~TdxFadingObjectHelper();
	void __fastcall CheckStartFading(Cxlookandfeelpainters::TcxButtonState APrevState, Cxlookandfeelpainters::TcxButtonState AState);
	bool __fastcall DrawImage(HDC DC, const System::Types::TRect &R);
	void __fastcall FadeIn();
	void __fastcall FadeOut();
	void __fastcall StopFading();
	__property bool Active = {read=GetActive, nodefault};
public:
	/* TObject.Create */ inline __fastcall TdxFadingObjectHelper() : Dxcoreclasses::TcxIUnknownObject() { }
	
private:
	void *__IdxFadingObject;	// IdxFadingObject 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {73AB2A92-CDD9-4F13-965A-DC799DE837F9}
	operator _di_IdxFadingObject()
	{
		_di_IdxFadingObject intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IdxFadingObject*(void) { return (IdxFadingObject*)&__IdxFadingObject; }
	#endif
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFadingList : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	TdxFadingElement* operator[](int Index) { return this->Items[Index]; }
	
private:
	TdxFadingElement* __fastcall GetItems(int Index);
	
public:
	virtual void __fastcall Clear();
	__property TdxFadingElement* Items[int Index] = {read=GetItems/*, default*/};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxFadingList() { }
	
public:
	/* TObject.Create */ inline __fastcall TdxFadingList() : System::Classes::TList() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFadingHelper : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod System::Uitypes::TColor __fastcall CheckColor(const System::Uitypes::TColor AColor);
	__classmethod void __fastcall CorrectAlphaChannel(Vcl::Graphics::TBitmap* ABitmap)/* overload */;
	__classmethod void __fastcall CorrectAlphaChannel(Dxcoregraphics::TRGBColors &AColors)/* overload */;
	__classmethod void __fastcall CorrectAlphaChannel(Winapi::Windows::PRGBQuad AColors, int AColorCount)/* overload */;
public:
	/* TObject.Create */ inline __fastcall TdxFadingHelper() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxFadingHelper() { }
	
};

#pragma pack(pop)

enum DECLSPEC_DENUM TdxFaderAnimationState : unsigned char { fasDefault, fasEnabled, fasDisabled };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFader : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxFadingList* FList;
	int FMaxAnimationCount;
	TdxFaderAnimationState FState;
	Cxclasses::TcxTimer* FTimer;
	bool __fastcall GetActive();
	bool __fastcall GetIsReady();
	System::LongBool __fastcall GetSystemAnimationState();
	void __fastcall SetMaxAnimationCount(int Value);
	void __fastcall ValidateQueue();
	
protected:
	bool __fastcall CanFade(System::TObject* AObject)/* overload */;
	bool __fastcall CanFade(System::TObject* AObject, /* out */ _di_IdxFadingObject &AFadingObject)/* overload */;
	void __fastcall DoTimer(System::TObject* Sender);
	void __fastcall AddFadingElement(TdxFadingElement* AElement);
	void __fastcall RemoveFadingElement(TdxFadingElement* AElement);
	
public:
	__fastcall TdxFader();
	__fastcall virtual ~TdxFader();
	void __fastcall Clear();
	bool __fastcall Contains(System::TObject* AObject);
	bool __fastcall DrawFadeImage(System::TObject* AObject, HDC DC, const System::Types::TRect &R)/* overload */;
	bool __fastcall DrawFadeImage(System::TObject* AObject, Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R)/* overload */;
	bool __fastcall Find(System::TObject* AObject, /* out */ TdxFadingElement* &AFadingElement);
	void __fastcall Remove(System::TObject* AObject, bool ADestroying = true);
	void __fastcall Fade(System::TObject* AObject, TdxFadingState AState)/* overload */;
	void __fastcall Fade(System::TObject* AObject, Vcl::Graphics::TBitmap* AImage1, Vcl::Graphics::TBitmap* AImage2, int AAnimationFrameCount, int AAnimationFrameDelay)/* overload */;
	void __fastcall FadeIn(System::TObject* AObject);
	void __fastcall FadeOut(System::TObject* AObject);
	__property bool Active = {read=GetActive, nodefault};
	__property bool IsReady = {read=GetIsReady, nodefault};
	__property int MaxAnimationCount = {read=FMaxAnimationCount, write=SetMaxAnimationCount, nodefault};
	__property TdxFaderAnimationState State = {read=FState, write=FState, nodefault};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE int dxFadeInDefaultAnimationFrameCount;
extern DELPHI_PACKAGE int dxFadeInDefaultAnimationFrameDelay;
extern DELPHI_PACKAGE int dxFadeOutDefaultAnimationFrameCount;
extern DELPHI_PACKAGE int dxFadeOutDefaultAnimationFrameDelay;
static const System::Byte dxFadeMaxAlpha = System::Byte(0xff);
static const System::Int8 dxFadeMaxAnimationCount = System::Int8(0x14);
static const System::Int8 dxFadeMaxAnimationFrameCount = System::Int8(0x20);
static const System::Word dxFadeMaxAnimationFrameDelay = System::Word(0x12c);
static const System::Int8 dxFadeTimerInterval = System::Int8(0xa);
extern DELPHI_PACKAGE TdxFader* __fastcall dxFader(void);
}	/* namespace Dxfading */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXFADING)
using namespace Dxfading;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxfadingHPP
