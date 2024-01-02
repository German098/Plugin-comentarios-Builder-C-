// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxCustomHint.pas' rev: 35.00 (Windows)

#ifndef DxcustomhintHPP
#define DxcustomhintHPP

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
#include <System.Classes.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Graphics.hpp>
#include <System.SysUtils.hpp>
#include <dxCore.hpp>
#include <dxCoreClasses.hpp>
#include <cxClasses.hpp>
#include <dxFormattedText.hpp>
#include <cxDrawTextUtils.hpp>
#include <cxGraphics.hpp>
#include <cxGeometry.hpp>
#include <cxLookAndFeels.hpp>
#include <cxLookAndFeelPainters.hpp>

//-- user supplied -----------------------------------------------------------

namespace Dxcustomhint
{
//-- forward type declarations -----------------------------------------------
__interface DELPHIINTERFACE IcxHintWindowHelper;
typedef System::DelphiInterface<IcxHintWindowHelper> _di_IcxHintWindowHelper;
__interface DELPHIINTERFACE IcxHintableObject;
typedef System::DelphiInterface<IcxHintableObject> _di_IcxHintableObject;
__interface DELPHIINTERFACE IcxHintableObject2;
typedef System::DelphiInterface<IcxHintableObject2> _di_IcxHintableObject2;
class DELPHICLASS TcxBaseHintWindow;
class DELPHICLASS TcxCustomHintWindow;
class DELPHICLASS TcxCustomHintStyle;
class DELPHICLASS TcxCustomHintStyleController;
class DELPHICLASS TdxCustomHintViewInfoHelper;
class DELPHICLASS TdxCustomHintViewInfo;
class DELPHICLASS TdxHintViewInfoHelper;
class DELPHICLASS TcxCustomHintHelper;
//-- type declarations -------------------------------------------------------
__interface  INTERFACE_UUID("{BE228118-851E-4C8D-8A31-58E26AA4F88B}") IcxHintWindowHelper  : public System::IInterface 
{
	virtual void __fastcall SetHintAreaBounds(const System::Types::TRect &ABounds, bool AUseMousePos) = 0 ;
};

__interface  INTERFACE_UUID("{228FF1F5-6D0C-40F0-9F7B-8C71CE12CEC8}") IcxHintableObject  : public System::IInterface 
{
	virtual bool __fastcall HasHintPoint(const System::Types::TPoint &P) = 0 ;
	virtual bool __fastcall IsHintAtMousePos() = 0 ;
	virtual bool __fastcall UseHintHidePause() = 0 ;
};

__interface  INTERFACE_UUID("{2D6C9CAB-443E-4F72-A3A6-1467489580D4}") IcxHintableObject2  : public IcxHintableObject 
{
	virtual bool __fastcall ImmediateShowHint() = 0 ;
	virtual System::TObject* __fastcall GetHintObject() = 0 ;
	virtual System::UnicodeString __fastcall GetHintText() = 0 ;
	virtual bool __fastcall IsHintMultiLine() = 0 ;
	virtual Vcl::Graphics::TFont* __fastcall GetHintFont() = 0 ;
	virtual System::Types::TRect __fastcall GetHintAreaBounds() = 0 ;
	virtual System::Types::TRect __fastcall GetHintTextBounds() = 0 ;
};

enum DECLSPEC_DENUM TcxHintAnimationStyle : unsigned char { cxhaSlideFromLeft, cxhaSlideFromRight, cxhaSlideDownward, cxhaSlideUpward, cxhaSlideFromCenter, cxhaHide, cxhaActivate, cxhaFadeIn, cxhaAuto, cxhaNone };

class PASCALIMPLEMENTATION TcxBaseHintWindow : public Vcl::Controls::THintWindow
{
	typedef Vcl::Controls::THintWindow inherited;
	
private:
	bool FAbsolutePosition;
	bool FActivating;
	TcxHintAnimationStyle FAnimationStyle;
	int FAnimationDelay;
	Vcl::Forms::TFormBorderStyle FBorderStyle;
	Cxgraphics::TcxCanvas* FcxCanvas;
	bool FHasAnimation;
	System::Types::TRect FHintAreaBounds;
	unsigned FLastActive;
	bool FNeedEraseBackground;
	Cxgeometry::TdxScaleFactor* FScaleFactor;
	bool FUseMousePos;
	HIDESBASE MESSAGE void __fastcall CMTextChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Winapi::Messages::TWMEraseBkgnd &Message);
	HIDESBASE MESSAGE void __fastcall WMWindowPosChanging(Winapi::Messages::TWMWindowPosMsg &Message);
	
protected:
	bool FStandardHint;
	virtual void __fastcall AdjustActivateRect(System::Types::TRect &ARect);
	void __fastcall CheckExecuteAnimation(const System::UnicodeString AHint);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	TcxHintAnimationStyle __fastcall GetAnimationStyle();
	virtual void __fastcall DisableRegion();
	virtual void __fastcall EnableRegion();
	virtual bool __fastcall HasWindowRegion();
	virtual void __fastcall SetHintAreaBounds(const System::Types::TRect &ABounds, bool AUseMousePos);
	HIDESBASE virtual void __fastcall Show();
	void __fastcall UpdateScaleFactorFromPos(const System::Types::TPoint &P);
	__property bool AbsolutePosition = {read=FAbsolutePosition, write=FAbsolutePosition, nodefault};
	__property System::Types::TRect HintAreaBounds = {read=FHintAreaBounds};
	__property Cxgeometry::TdxScaleFactor* ScaleFactor = {read=FScaleFactor};
	__property bool UseMousePos = {read=FUseMousePos, nodefault};
	
public:
	__fastcall virtual TcxBaseHintWindow(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxBaseHintWindow();
	virtual void __fastcall ActivateHint(const System::Types::TRect &ARect, const System::UnicodeString AHint);
	HIDESBASE void __fastcall ScaleForPPI(const int PPI);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	__property TcxHintAnimationStyle AnimationStyle = {read=FAnimationStyle, write=FAnimationStyle, nodefault};
	__property int AnimationDelay = {read=FAnimationDelay, write=FAnimationDelay, nodefault};
	__property Vcl::Forms::TBorderStyle BorderStyle = {read=FBorderStyle, write=FBorderStyle, nodefault};
	__property Cxgraphics::TcxCanvas* cxCanvas = {read=FcxCanvas};
	__property bool NeedEraseBackground = {read=FNeedEraseBackground, write=FNeedEraseBackground, nodefault};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxBaseHintWindow(HWND ParentWindow) : Vcl::Controls::THintWindow(ParentWindow) { }
	
private:
	void *__IcxHintWindowHelper;	// IcxHintWindowHelper 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {BE228118-851E-4C8D-8A31-58E26AA4F88B}
	operator _di_IcxHintWindowHelper()
	{
		_di_IcxHintWindowHelper intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IcxHintWindowHelper*(void) { return (IcxHintWindowHelper*)&__IcxHintWindowHelper; }
	#endif
	
};


typedef System::TMetaClass* TcxCustomHintWindowClass;

class PASCALIMPLEMENTATION TcxCustomHintWindow : public TcxBaseHintWindow
{
	typedef TcxBaseHintWindow inherited;
	
private:
	System::UnicodeString FCaption;
	
protected:
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetPainter();
	HIDESBASE virtual void __fastcall ShowHint(int X, int Y, System::UnicodeString ACaption, System::UnicodeString AHint, int AMaxWidth = 0x0);
	__property bool StandardHint = {read=FStandardHint, write=FStandardHint, nodefault};
	
public:
	DYNAMIC bool __fastcall UseRightToLeftAlignment();
	__property System::UnicodeString Caption = {read=FCaption, write=FCaption};
public:
	/* TcxBaseHintWindow.Create */ inline __fastcall virtual TcxCustomHintWindow(System::Classes::TComponent* AOwner) : TcxBaseHintWindow(AOwner) { }
	/* TcxBaseHintWindow.Destroy */ inline __fastcall virtual ~TcxCustomHintWindow() { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomHintWindow(HWND ParentWindow) : TcxBaseHintWindow(ParentWindow) { }
	
};


typedef System::TMetaClass* TcxHintStyleClass;

class PASCALIMPLEMENTATION TcxCustomHintStyle : public Dxcoreclasses::TcxInterfacedPersistent
{
	typedef Dxcoreclasses::TcxInterfacedPersistent inherited;
	
private:
	System::Classes::TNotifyEvent FOnChanged;
	
protected:
	virtual void __fastcall ControllerChangedNotification(TcxCustomHintStyleController* AStyleController);
	virtual void __fastcall ControllerFreeNotification(TcxCustomHintStyleController* AHintStyleController);
	virtual void __fastcall DoShowHint(System::UnicodeString &AHintStr, bool &ACanShow, Vcl::Controls::THintInfo &AHintInfo);
	__property System::Classes::TNotifyEvent OnChanged = {read=FOnChanged, write=FOnChanged};
	
public:
	__fastcall virtual TcxCustomHintStyle(System::Classes::TComponent* AComponent);
	virtual void __fastcall ComponentRemoved(System::Classes::TComponent* AComponent);
	virtual TcxCustomHintWindowClass __fastcall GetHintWindowClass() = 0 ;
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxCustomHintStyle() { }
	
};


typedef void __fastcall (__closure *TcxHintStyleChangedEvent)(System::TObject* Sender, TcxCustomHintStyle* AStyle);

typedef void __fastcall (__closure *TcxShowHintEvent)(System::TObject* Sender, System::UnicodeString &HintStr, bool &CanShow, Vcl::Controls::THintInfo &HintInfo);

typedef void __fastcall (__closure *TcxShowHintExEvent)(System::TObject* Sender, System::UnicodeString &Caption, System::UnicodeString &HintStr, bool &CanShow, Vcl::Controls::THintInfo &HintInfo);

class PASCALIMPLEMENTATION TcxCustomHintStyleController : public Cxclasses::TcxCustomComponent
{
	typedef Cxclasses::TcxCustomComponent inherited;
	
private:
	bool FGlobal;
	int FHintShortPause;
	int FHintPause;
	int FHintHidePause;
	TcxHintStyleClass FHintStyleClass;
	TcxCustomHintWindow* FHintWindow;
	System::Classes::TList* FListeners;
	Cxlookandfeels::TcxLookAndFeel* FLookAndFeel;
	int FUpdateCount;
	bool FUseHintControlLookAndFeel;
	TcxHintStyleChangedEvent FOnHintStyleChanged;
	TcxShowHintEvent FOnShowHint;
	TcxShowHintExEvent FOnShowHintEx;
	void __fastcall DoShowHint(System::UnicodeString &AHintStr, bool &ACanShow, Vcl::Controls::THintInfo &AHintInfo);
	void __fastcall DoShowHintEx(System::UnicodeString &AHintStr, System::UnicodeString &AHintCaption, bool &ACanShow, Vcl::Controls::THintInfo &AHintInfo);
	System::UnicodeString __fastcall GetHintStyleClassName();
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter();
	void __fastcall HintStyleChanged(System::TObject* Sender);
	void __fastcall SetGlobal(bool Value);
	void __fastcall SetHintStyle(TcxCustomHintStyle* Value);
	void __fastcall SetHintStyleClass(const TcxHintStyleClass Value);
	void __fastcall SetHintStyleClassName(const System::UnicodeString Value);
	void __fastcall SetLookAndFeel(Cxlookandfeels::TcxLookAndFeel* const Value);
	void __fastcall SetHintShortPause(int Value);
	void __fastcall SetHintPause(int Value);
	void __fastcall SetHintHidePause(int Value);
	void __fastcall SetApplicationHintProperties();
	
protected:
	TcxCustomHintStyle* FHintStyle;
	virtual void __fastcall Loaded();
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual TcxHintStyleClass __fastcall GetHintStyleClass();
	virtual TcxCustomHintWindowClass __fastcall GetHintWindowClass();
	void __fastcall CreateHintStyle();
	void __fastcall DestroyHintStyle();
	virtual void __fastcall BeginUpdate();
	virtual void __fastcall EndUpdate();
	void __fastcall Changed();
	virtual void __fastcall DoHintStyleChanged(TcxCustomHintStyle* AStyle);
	__property bool Global = {read=FGlobal, write=SetGlobal, default=1};
	__property int HintHidePause = {read=FHintHidePause, write=SetHintHidePause, default=2500};
	__property int HintPause = {read=FHintPause, write=SetHintPause, default=500};
	__property int HintShortPause = {read=FHintShortPause, write=SetHintShortPause, default=50};
	__property TcxHintStyleClass HintStyleClass = {read=GetHintStyleClass, write=SetHintStyleClass};
	__property System::UnicodeString HintStyleClassName = {read=GetHintStyleClassName, write=SetHintStyleClassName};
	__property System::Classes::TList* Listeners = {read=FListeners};
	__property TcxHintStyleChangedEvent OnHintStyleChanged = {read=FOnHintStyleChanged, write=FOnHintStyleChanged};
	__property TcxShowHintEvent OnShowHint = {read=FOnShowHint, write=FOnShowHint};
	__property TcxShowHintExEvent OnShowHintEx = {read=FOnShowHintEx, write=FOnShowHintEx};
	
public:
	__fastcall virtual TcxCustomHintStyleController(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomHintStyleController();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall AddListener(TcxCustomHintStyle* AListener);
	virtual void __fastcall RemoveListener(TcxCustomHintStyle* AListener);
	Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeelValue();
	void __fastcall ShowHint(int X, int Y, System::UnicodeString ACaption, System::UnicodeString AHint, int AMaxWidth = 0x0);
	void __fastcall HideHint();
	__property TcxCustomHintStyle* HintStyle = {read=FHintStyle, write=SetHintStyle};
	__property TcxCustomHintWindow* HintWindow = {read=FHintWindow};
	__property Cxlookandfeels::TcxLookAndFeel* LookAndFeel = {read=FLookAndFeel, write=SetLookAndFeel};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* LookAndFeelPainter = {read=GetLookAndFeelPainter};
	__property bool UseHintControlLookAndFeel = {read=FUseHintControlLookAndFeel, write=FUseHintControlLookAndFeel, default=0};
private:
	void *__IdxSkinSupport;	// Cxlookandfeels::IdxSkinSupport 
	void *__IcxLookAndFeelContainer;	// Cxlookandfeels::IcxLookAndFeelContainer 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {EF3FF483-9B69-46DF-95A4-D3A3810F63A5}
	operator Cxlookandfeels::_di_IdxSkinSupport()
	{
		Cxlookandfeels::_di_IdxSkinSupport intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Cxlookandfeels::IdxSkinSupport*(void) { return (Cxlookandfeels::IdxSkinSupport*)&__IdxSkinSupport; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {6065B58B-C557-4464-A67D-64183FD13F25}
	operator Cxlookandfeels::_di_IcxLookAndFeelContainer()
	{
		Cxlookandfeels::_di_IcxLookAndFeelContainer intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Cxlookandfeels::IcxLookAndFeelContainer*(void) { return (Cxlookandfeels::IcxLookAndFeelContainer*)&__IcxLookAndFeelContainer; }
	#endif
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomHintViewInfoHelper : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Types::TRect FBoundsRect;
	bool FUseRightToLeftAlignment;
	bool FUseRightToLeftReading;
	
protected:
	virtual Cxgeometry::TdxScaleFactor* __fastcall GetScaleFactor();
	
public:
	virtual void __fastcall Calculate(Vcl::Graphics::TCanvas* ACanvas) = 0 ;
	virtual void __fastcall Paint(Vcl::Graphics::TCanvas* ACanvas) = 0 ;
	__property System::Types::TRect BoundsRect = {read=FBoundsRect, write=FBoundsRect};
	__property Cxgeometry::TdxScaleFactor* ScaleFactor = {read=GetScaleFactor};
	__property bool UseRightToLeftAlignment = {read=FUseRightToLeftAlignment, write=FUseRightToLeftAlignment, nodefault};
	__property bool UseRightToLeftReading = {read=FUseRightToLeftReading, write=FUseRightToLeftReading, nodefault};
public:
	/* TObject.Create */ inline __fastcall TdxCustomHintViewInfoHelper() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxCustomHintViewInfoHelper() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomHintViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FUseRightToLeftAlignment;
	bool FUseRightToLeftReading;
	System::Types::TRect __fastcall GetBoundsRect();
	
protected:
	TdxCustomHintViewInfoHelper* FHelper;
	virtual void __fastcall CreateHelper() = 0 ;
	virtual void __fastcall DestroyHelper();
	
public:
	__fastcall TdxCustomHintViewInfo();
	__fastcall virtual ~TdxCustomHintViewInfo();
	virtual void __fastcall Calculate(Vcl::Graphics::TCanvas* ACanvas);
	virtual void __fastcall Paint(Vcl::Graphics::TCanvas* ACanvas);
	__property System::Types::TRect BoundsRect = {read=GetBoundsRect};
	__property bool UseRightToLeftAlignment = {read=FUseRightToLeftAlignment, write=FUseRightToLeftAlignment, nodefault};
	__property bool UseRightToLeftReading = {read=FUseRightToLeftReading, write=FUseRightToLeftReading, nodefault};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxHintViewInfoHelper : public TdxCustomHintViewInfoHelper
{
	typedef TdxCustomHintViewInfoHelper inherited;
	
private:
	System::Types::TPoint FPos;
	Cxgeometry::TdxScaleFactor* FScaleFactor;
	System::UnicodeString FText;
	Dxformattedtext::TdxFormattedText* FFormattedHintText;
	System::Types::TSize __fastcall CalculateMinSize(Vcl::Graphics::TCanvas* ACanvas);
	
protected:
	virtual void __fastcall CorrectMinSize(System::Types::TSize &ASize);
	virtual Cxgeometry::TdxScaleFactor* __fastcall GetScaleFactor();
	virtual System::Types::TRect __fastcall GetTextRect();
	virtual void __fastcall DrawText(Vcl::Graphics::TCanvas* ACanvas);
	virtual void __fastcall PrepareCanvasFont(Vcl::Graphics::TCanvas* ACanvas);
	virtual void __fastcall SetTextColor(Vcl::Graphics::TCanvas* ACanvas);
	__property System::UnicodeString Text = {read=FText, write=FText};
	__property System::Types::TPoint Pos = {read=FPos, write=FPos};
	
public:
	__fastcall TdxHintViewInfoHelper(const System::UnicodeString AHint, const System::UnicodeString AShortCut, const System::Types::TPoint &ACursorPos);
	__fastcall virtual ~TdxHintViewInfoHelper();
	virtual void __fastcall Calculate(Vcl::Graphics::TCanvas* ACanvas);
	virtual void __fastcall Paint(Vcl::Graphics::TCanvas* ACanvas);
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomHintHelper : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	System::TObject* FActivatingHintObject;
	_di_IcxHintableObject2 FActivatingHintIntf;
	System::TObject* FHintableObject;
	System::Types::TRect FHintAreaBounds;
	Cxclasses::TcxTimer* FHintCheckerTimer;
	Cxclasses::TcxTimer* FHintHideTimer;
	int FHintHidePause;
	Cxclasses::TcxTimer* FHintShowTimer;
	int FHintShowPause;
	System::TObject* FLastHintableObject;
	System::Types::TPoint FLastHintMousePos;
	System::UnicodeString FLastHintText;
	System::Types::TRect FHintTextRect;
	Vcl::Controls::THintWindow* FHintWindow;
	void __fastcall CancelShowHint();
	void __fastcall HintCheckerTimerHandler(System::TObject* Sender);
	void __fastcall HintHideTimerHandler(System::TObject* Sender);
	void __fastcall HintShowTimerHandler(System::TObject* Sender);
	void __fastcall RestartHintHideTimer();
	void __fastcall RecreateHintWindow();
	
protected:
	bool __fastcall IsMouseButtonPressed();
	virtual void __fastcall MouseLeave();
	virtual bool __fastcall PtInCaller(const System::Types::TPoint &P);
	virtual bool __fastcall CanShowHint();
	virtual void __fastcall CorrectHintWindowRect(System::Types::TRect &ARect);
	virtual Vcl::Controls::TWinControl* __fastcall GetHintWinControl();
	virtual System::Types::TRect __fastcall GetHintControlBounds();
	virtual int __fastcall GetHintHidePause();
	virtual Vcl::Controls::THintWindowClass __fastcall GetHintWindowClass();
	virtual System::Types::TRect __fastcall GetHintWindowRect(const System::Types::TRect &AHintAreaBounds, const System::Types::TRect &ATextRect, const System::UnicodeString AText, bool AIsHintMultiLine);
	virtual Vcl::Controls::TWinControl* __fastcall GetOwnerWinControl();
	virtual bool __fastcall IsHintAtMousePos();
	virtual bool __fastcall IsSuppressHintOnMouseDown();
	void __fastcall StartHintCheckerTimers();
	void __fastcall StartShowHintTimer();
	void __fastcall StopHintCheckerTimers();
	virtual bool __fastcall UseHintHidePause();
	__property System::Types::TRect HintAreaBounds = {read=FHintAreaBounds};
	__property int HintShowPause = {read=FHintShowPause, write=FHintShowPause, nodefault};
	
public:
	__fastcall TcxCustomHintHelper();
	__fastcall virtual ~TcxCustomHintHelper();
	void __fastcall ActivateHint(const _di_IcxHintableObject2 AHintableObject)/* overload */;
	void __fastcall CancelHint();
	void __fastcall HideHint();
	virtual void __fastcall MouseDown();
	virtual void __fastcall ResetLastHintElement();
	void __fastcall ShowHint(const System::Types::TRect &AHintAreaBounds, const System::Types::TRect &ATextRect, const System::UnicodeString AText, bool AIsHintMultiLine, System::TObject* AHintObject, Vcl::Graphics::TFont* AFont = (Vcl::Graphics::TFont*)(0x0));
	void __fastcall UnsubscribeHintObject(System::TObject* AHintObject);
	__property System::TObject* HintableObject = {read=FHintableObject};
	__property Vcl::Controls::THintWindow* HintWindow = {read=FHintWindow};
private:
	void *__IcxMouseTrackingCaller2;	// Dxcoreclasses::IcxMouseTrackingCaller2 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {3A5D973B-F016-4F22-80B6-1D35668D7743}
	operator Dxcoreclasses::_di_IcxMouseTrackingCaller2()
	{
		Dxcoreclasses::_di_IcxMouseTrackingCaller2 intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Dxcoreclasses::IcxMouseTrackingCaller2*(void) { return (Dxcoreclasses::IcxMouseTrackingCaller2*)&__IcxMouseTrackingCaller2; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {84A4BCBE-E001-4D60-B7A6-75E2B0DCD3E9}
	operator Dxcoreclasses::_di_IcxMouseTrackingCaller()
	{
		Dxcoreclasses::_di_IcxMouseTrackingCaller intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Dxcoreclasses::IcxMouseTrackingCaller*(void) { return (Dxcoreclasses::IcxMouseTrackingCaller*)&__IcxMouseTrackingCaller2; }
	#endif
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE void __fastcall cxActivateHint(Vcl::Controls::THintWindow* AHintWindow, const System::Types::TRect &ARect, const System::UnicodeString AHint);
extern DELPHI_PACKAGE void __fastcall cxActivateHintData(Vcl::Controls::THintWindow* AHintWindow, const System::Types::TRect &ARect, const System::UnicodeString AHint, void * AData);
extern DELPHI_PACKAGE bool __fastcall cxProcessControlHintInfo(/* out */ Vcl::Controls::THintInfo &AHintInfo, Vcl::Controls::THintWindow* &AHintWindow, Vcl::Controls::TControl* AControl, const System::UnicodeString AHint, System::Types::TRect &AHintWinRect, void * AData = (void *)(0x0), int AHintHidePause = 0x0);
extern DELPHI_PACKAGE Cxclasses::TcxRegisteredClasses* __fastcall cxRegisteredHintStyles(void);
extern DELPHI_PACKAGE TcxCustomHintStyleController* __fastcall cxGetHintStyleController(void);
extern DELPHI_PACKAGE TcxCustomHintStyle* __fastcall cxGetHintStyle(void);
extern DELPHI_PACKAGE Vcl::Controls::THintWindowClass __fastcall cxGetHintWindowClass(void);
extern DELPHI_PACKAGE Vcl::Controls::TControl* __fastcall cxGetHintedControl(void);
extern DELPHI_PACKAGE void __fastcall cxRemoveHintedControl(void);
}	/* namespace Dxcustomhint */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXCUSTOMHINT)
using namespace Dxcustomhint;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxcustomhintHPP
