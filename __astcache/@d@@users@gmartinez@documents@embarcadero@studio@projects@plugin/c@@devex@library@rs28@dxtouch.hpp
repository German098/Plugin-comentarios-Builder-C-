// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxTouch.pas' rev: 35.00 (Windows)

#ifndef DxtouchHPP
#define DxtouchHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.Windows.hpp>
#include <Winapi.Messages.hpp>
#include <System.Types.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Dialogs.hpp>
#include <System.Classes.hpp>
#include <Vcl.Themes.hpp>
#include <System.RTLConsts.hpp>
#include <dxCore.hpp>
#include <cxGeometry.hpp>
#include <dxUxTheme.hpp>

//-- user supplied -----------------------------------------------------------

namespace Dxtouch
{
//-- forward type declarations -----------------------------------------------
struct TdxGestureInfo;
struct TdxGestureNotifyStruct;
struct TWMGestureNotify;
struct TdxGestureConfig;
__interface DELPHIINTERFACE IdxGestureClient;
typedef System::DelphiInterface<IdxGestureClient> _di_IdxGestureClient;
__interface DELPHIINTERFACE IdxGestureClient2;
typedef System::DelphiInterface<IdxGestureClient2> _di_IdxGestureClient2;
__interface DELPHIINTERFACE IdxGestureOwner;
typedef System::DelphiInterface<IdxGestureOwner> _di_IdxGestureOwner;
__interface DELPHIINTERFACE IdxZoomClient;
typedef System::DelphiInterface<IdxZoomClient> _di_IdxZoomClient;
__interface DELPHIINTERFACE IdxRotateClient;
typedef System::DelphiInterface<IdxRotateClient> _di_IdxRotateClient;
class DELPHICLASS TdxGestureHelper;
//-- type declarations -------------------------------------------------------
struct DECLSPEC_DRECORD TdxGestureInfo
{
public:
	unsigned cbSize;
	unsigned dwFlags;
	unsigned dwID;
	HWND hwndTarget;
	System::Types::TSmallPoint ptsLocation;
	unsigned dwInstanceID;
	unsigned dwSequenceID;
	unsigned __int64 ullArguments;
	unsigned cbExtraArgs;
};


struct DECLSPEC_DRECORD TdxGestureNotifyStruct
{
public:
	unsigned cbSize;
	unsigned dwFlags;
	HWND hwndTarget;
	System::Types::TSmallPoint ptsLocation;
	unsigned dwInstanceID;
};


typedef TdxGestureNotifyStruct *PdxGestureNotifyStruct;

struct DECLSPEC_DRECORD TWMGestureNotify
{
public:
	NativeUInt Msg;
	NativeUInt Unused;
	TdxGestureNotifyStruct *NotifyStruct;
	NativeInt Result;
};


struct DECLSPEC_DRECORD TdxGestureConfig
{
public:
	unsigned dwID;
	unsigned dwWant;
	unsigned dwBlock;
};


typedef System::DynamicArray<TdxGestureConfig> TdxGestureConfigs;

__interface  INTERFACE_UUID("{652B8A09-DAC8-4332-9206-C8905AEE7791}") IdxGestureClient  : public System::IInterface 
{
	virtual bool __fastcall AllowGesture(int AGestureId) = 0 ;
	virtual bool __fastcall AllowPan(Vcl::Forms::TScrollBarKind AScrollKind) = 0 ;
	virtual void __fastcall BeginGestureScroll(const System::Types::TPoint &APos) = 0 ;
	virtual void __fastcall EndGestureScroll() = 0 ;
	virtual void __fastcall GestureScroll(int ADeltaX, int ADeltaY) = 0 ;
	virtual int __fastcall GetPanOptions() = 0 ;
	virtual bool __fastcall IsPanArea(const System::Types::TPoint &APoint) = 0 ;
	virtual bool __fastcall NeedPanningFeedback(Vcl::Forms::TScrollBarKind AScrollKind) = 0 ;
};

__interface  INTERFACE_UUID("{834D1E09-D446-4E7E-9DE3-AE158BAA9B73}") IdxGestureClient2  : public System::IInterface 
{
	virtual bool __fastcall UseRightToLeftScrollbar() = 0 ;
};

__interface  INTERFACE_UUID("{4DF001DA-BE2C-4817-B75C-55171270D158}") IdxGestureOwner  : public System::IInterface 
{
	virtual _di_IdxGestureClient __fastcall GetGestureClient(const System::Types::TPoint &APoint) = 0 ;
	virtual NativeUInt __fastcall GetHandle() = 0 ;
	virtual bool __fastcall IsGestureTarget(NativeUInt AWnd) = 0 ;
	virtual System::Types::TPoint __fastcall ScreenToClient(const System::Types::TPoint &APoint) = 0 ;
};

__interface  INTERFACE_UUID("{B3A0623E-D155-462F-B234-22E9CFC6BFBF}") IdxZoomClient  : public System::IInterface 
{
	virtual void __fastcall Zoom(int ADelta, bool &AHandled) = 0 ;
};

__interface  INTERFACE_UUID("{EAC9BA3A-C2C3-42E2-8CA8-8CEA85821CAE}") IdxRotateClient  : public System::IInterface 
{
	virtual void __fastcall Rotate(double AAngle, bool &AHandled) = 0 ;
};

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGestureHelper : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FIsInertia;
	_di_IdxGestureClient FGestureClient;
	System::TObject* FGestureNotifyClient;
	_di_IdxGestureOwner FGestureOwner;
	bool FIsPanning;
	int FLastDistance;
	System::Types::TPoint FPanPoint;
	System::Types::TPoint FOverPan;
	Vcl::Controls::TControl* FNotifyTouchControl;
	Vcl::Controls::TControl* FTouchControl;
	void __fastcall DoOverpan(Vcl::Forms::TScrollBarKind AScrollKind, int ADelta);
	_di_IdxGestureClient __fastcall GetGestureNotifyClient();
	System::Types::TPoint __fastcall GetTouchStartPoint();
	bool __fastcall IsRightToLeft();
	bool __fastcall Pan(const System::Types::TPoint &APos, bool AIsBegin, bool AIsEnd, bool AIsInertia);
	bool __fastcall Rotate(double AAngle, bool AIsBegin, bool AIsEnd);
	bool __fastcall Zoom(int ADistance, bool AIsBegin, bool AIsEnd);
	
protected:
	virtual bool __fastcall AllowGesture(int AGestureId);
	virtual bool __fastcall AllowPan(Vcl::Forms::TScrollBarKind AScrollKind);
	void __fastcall BeginGestureScroll(const System::Types::TPoint &APos);
	bool __fastcall Gesture(Winapi::Messages::TMessage &Message);
	bool __fastcall GestureNotify(TWMGestureNotify &Message);
	void __fastcall EndGestureScroll();
	void __fastcall GestureScroll(int ADeltaX, int ADeltaY);
	int __fastcall GetAllowedPanOptions(const System::Types::TPoint &APoint);
	virtual NativeUInt __fastcall GetHandle();
	virtual int __fastcall GetPanOptions();
	virtual bool __fastcall IsGestureTarget(NativeUInt AWnd);
	virtual bool __fastcall IsPanArea(const System::Types::TPoint &APoint);
	virtual bool __fastcall NeedPanningFeedback(Vcl::Forms::TScrollBarKind AScrollKind);
	virtual System::Types::TPoint __fastcall ScreenToClient(const System::Types::TPoint &APoint);
	__property NativeUInt Handle = {read=GetHandle, nodefault};
	
public:
	__fastcall TdxGestureHelper(_di_IdxGestureOwner AGestureOwner);
	__fastcall virtual ~TdxGestureHelper();
	void __fastcall CheckOverpan(Vcl::Forms::TScrollBarKind AScrollKind, int ANewDataPos, int AMinDataPos, int AMaxDataPos, int ADeltaX, int ADeltaY);
	void __fastcall CheckGestureOptions(Vcl::Controls::TInteractiveGestures &Gestures, Vcl::Controls::TInteractiveGestureOptions &Options);
	void __fastcall DoGesture(const Vcl::Controls::TGestureEventInfo &EventInfo, bool &Handled);
	bool __fastcall HandleMessage(Winapi::Messages::TMessage &Message);
	__property bool IsPanning = {read=FIsPanning, nodefault};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE System::StaticArray<int, 5> dxTouchInteractiveGestureToGestureID;
extern DELPHI_PACKAGE System::StaticArray<int, 4> dxTouchInteractiveGestureOptionToPanOption;
static const System::Int8 dxTouchPanOptions = System::Int8(0x1f);
static const System::Int8 dxSupportedGestureCount = System::Int8(0x5);
extern DELPHI_PACKAGE System::StaticArray<int, 5> dxSupportedGestureOptions;
extern DELPHI_PACKAGE System::StaticArray<int, 5> dxSupportedGestureIDs;
extern DELPHI_PACKAGE bool __fastcall dxIsTouchEvent(System::Classes::TShiftState Shift);
extern DELPHI_PACKAGE Vcl::Controls::TInteractiveGesture __fastcall GetInteractiveGestureByGestureID(int AGestureID);
extern DELPHI_PACKAGE Vcl::Controls::TInteractiveGestureOption __fastcall GetInteractiveGestureOptionByPanOptionID(int APanOptionID);
extern DELPHI_PACKAGE Vcl::Controls::TInteractiveGestureOptions __fastcall GetInteractiveGestureOptionsByPanOptions(int APanOptions);
extern DELPHI_PACKAGE int __fastcall GetPanOptionsByInteractiveGestureOptions(Vcl::Controls::TInteractiveGestureOptions AGestureOptions);
extern DELPHI_PACKAGE bool __fastcall dxGetGestureInfo(NativeUInt hGestureInfo, TdxGestureInfo &AGestureInfo);
extern DELPHI_PACKAGE bool __fastcall dxCloseGestureInfoHandle(NativeUInt hGestureInfo);
extern DELPHI_PACKAGE bool __fastcall dxSetGestureConfig(NativeUInt AWindow, const TdxGestureConfigs AGestureConfigs);
extern DELPHI_PACKAGE bool __fastcall dxLogicalToPhysicalPoint(NativeUInt AWindow, System::Types::TPoint &APoint);
extern DELPHI_PACKAGE bool __fastcall dxPhysicalToLogicalPoint(NativeUInt AWindow, System::Types::TPoint &APoint);
extern DELPHI_PACKAGE bool __fastcall dxLockGestures(NativeUInt AHandle, TWMGestureNotify &Message);
}	/* namespace Dxtouch */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXTOUCH)
using namespace Dxtouch;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxtouchHPP
