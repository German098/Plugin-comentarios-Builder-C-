// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxContainer.pas' rev: 35.00 (Windows)

#ifndef CxcontainerHPP
#define CxcontainerHPP

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
#include <Winapi.Messages.hpp>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.StdCtrls.hpp>
#include <System.SysUtils.hpp>
#include <System.Math.hpp>
#include <dxCore.hpp>
#include <dxCoreClasses.hpp>
#include <dxMessages.hpp>
#include <dxThemeManager.hpp>
#include <dxUxTheme.hpp>
#include <cxClasses.hpp>
#include <cxControls.hpp>
#include <Winapi.MultiMon.hpp>
#include <dxTouch.hpp>
#include <cxGraphics.hpp>
#include <cxLookAndFeels.hpp>
#include <cxScrollBar.hpp>
#include <cxLookAndFeelPainters.hpp>
#include <cxGeometry.hpp>
#include <dxTypeHelpers.hpp>
#include <cxAccessibility.hpp>
#include <dxForms.hpp>

//-- user supplied -----------------------------------------------------------

namespace Cxcontainer
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TcxContainerViewInfo;
struct TcxContainerStyleData;
class DELPHICLASS TcxContainerStyle;
class DELPHICLASS TcxContainerStyles;
class DELPHICLASS TcxStyleController;
__interface DELPHIINTERFACE IcxContainerInnerControl;
typedef System::DelphiInterface<IcxContainerInnerControl> _di_IcxContainerInnerControl;
struct TcxContainerActiveStyleData;
struct TcxContainerInnerControlBounds;
struct TcxContainerSizeGripData;
class DELPHICLASS TcxContainer;
struct TcxPrevPopupControlData;
class DELPHICLASS TcxCustomPopupWindow;
class DELPHICLASS TcxCustomInnerListBox;
class DELPHICLASS TdxCustomInnerListBoxAccessibilityHelper;
class DELPHICLASS _TcxContainerAccess;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TcxContainerHotState : unsigned char { chsNoHotTrack, chsNormal, chsSelected };

enum DECLSPEC_DENUM TcxContainerStateItem : unsigned char { csNormal, csActive, csDisabled, csHotTrack };

typedef System::Set<TcxContainerStateItem, TcxContainerStateItem::csNormal, TcxContainerStateItem::csHotTrack> TcxContainerState;

enum DECLSPEC_DENUM TcxMouseButton : unsigned char { cxmbNone, cxmbLeft, cxmbRight, cxmbMiddle };

typedef System::Int8 TcxContainerStyleValue;

typedef System::Set<TcxContainerStyleValue, 0, 31> TcxContainerStyleValues;

typedef System::StaticArray<System::UnicodeString, 10> Cxcontainer__1;

typedef System::TMetaClass* TcxContainerClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxContainerViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Uitypes::TColor FBackgroundColor;
	Cxlookandfeelpainters::TcxContainerBorderState __fastcall GetBorderState();
	
protected:
	bool FCalculated;
	virtual void __fastcall DrawBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DrawNativeStyleBackground(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DrawNonNativeStyleBackground(Cxgraphics::TcxCanvas* ACanvas);
	virtual System::Uitypes::TColor __fastcall CalculateBackgroundColor(TcxContainerStyle* AStyle, bool AEnabled, TcxContainer* AContainer = (TcxContainer*)(0x0));
	virtual System::Uitypes::TColor __fastcall CalculateBorderColor(TcxContainerStyle* AStyle, bool AEnabled, bool AIsDesigning, TcxContainer* AContainer = (TcxContainer*)(0x0));
	virtual System::Uitypes::TColor __fastcall CalculateTextColor(TcxContainerStyle* AStyle, bool AEnabled, TcxContainer* AContainer = (TcxContainer*)(0x0));
	virtual Cxlookandfeelpainters::TcxContainerBorderStyle __fastcall GetContainerBorderStyle();
	virtual System::Uitypes::TColor __fastcall GetSkinnedTextColor(Cxlookandfeelpainters::TcxEditStateColorKind AKind);
	bool __fastcall IsStyleValueAssigned(TcxContainerStyle* AStyle, TcxContainerStyleValue AValue);
	virtual void __fastcall InternalPaint(Cxgraphics::TcxCanvas* ACanvas);
	
public:
	System::Uitypes::TColor BorderColor;
	System::Types::TRect BorderRect;
	Cxlookandfeelpainters::TcxContainerBorderStyle BorderStyle;
	int BorderWidth;
	System::Types::TRect Bounds;
	System::Types::TRect ClientRect;
	TcxContainerState ContainerState;
	Cxgeometry::TcxBorders Edges;
	Vcl::Graphics::TFont* Font;
	TcxContainerHotState HotState;
	int NativePart;
	int NativeState;
	bool NativeStyle;
	System::TObject* Owner;
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* Painter;
	bool PaintOnGlass;
	bool Shadow;
	Dxthememanager::TdxThemedObjectType ThemedObjectType;
	bool UseBorderedBackground;
	bool UseSkinnedColors;
	bool UseSkins;
	__fastcall virtual TcxContainerViewInfo();
	virtual void __fastcall Assign(System::TObject* Source);
	virtual Cxgraphics::TcxRegion* __fastcall GetUpdateRegion(TcxContainerViewInfo* AViewInfo);
	virtual void __fastcall Offset(int DX, int DY);
	virtual void __fastcall Paint(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall UpdateStyle(TcxContainerStyle* AStyle);
	__property System::Uitypes::TColor BackgroundColor = {read=FBackgroundColor, write=FBackgroundColor, nodefault};
	__property Cxlookandfeelpainters::TcxContainerBorderState BorderState = {read=GetBorderState, nodefault};
	__property bool Calculated = {read=FCalculated, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxContainerViewInfo() { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxContainerViewInfoClass;

struct DECLSPEC_DRECORD TcxContainerStyleData
{
public:
	System::Uitypes::TColor Color;
	Vcl::Graphics::TFont* Font;
	System::Uitypes::TColor FontColor;
};


class PASCALIMPLEMENTATION TcxContainerStyle : public Dxcoreclasses::TcxInterfacedPersistent
{
	typedef Dxcoreclasses::TcxInterfacedPersistent inherited;
	
private:
	System::Uitypes::TColor FBorderColor;
	Cxlookandfeelpainters::TcxContainerBorderStyle FBorderStyle;
	Cxgeometry::TcxBorders FEdges;
	bool FHotTrack;
	bool FShadow;
	bool FTransparentBorder;
	bool FDirectAccessMode;
	int FFontAssignedValueLockCount;
	bool FIsDestroying;
	Cxlookandfeels::TcxLookAndFeel* FLookAndFeel;
	bool FModified;
	System::Classes::TPersistent* FOwner;
	TcxContainerStyle* FParentStyle;
	TcxContainerStateItem FState;
	System::Uitypes::TFontStyles FTextStyle;
	int FUpdateCount;
	Vcl::Graphics::TFont* FVisibleFont;
	System::Classes::TNotifyEvent FOnChanged;
	TcxContainerStyleValues __fastcall GetAssignedValues();
	System::Uitypes::TColor __fastcall GetBorderColor();
	Cxlookandfeelpainters::TcxContainerBorderStyle __fastcall GetBorderStyle();
	Cxgeometry::TcxBorders __fastcall GetEdges();
	Vcl::Graphics::TFont* __fastcall GetFont();
	bool __fastcall GetHotTrack();
	bool __fastcall GetShadow();
	bool __fastcall GetTransparentBorder();
	bool __fastcall InternalGetBorderColor(System::Uitypes::TColor &BorderColor);
	bool __fastcall InternalGetBorderStyle(Cxlookandfeelpainters::TcxContainerBorderStyle &BorderStyle);
	bool __fastcall InternalGetEdges(Cxgeometry::TcxBorders &Edges);
	bool __fastcall InternalGetFont(Vcl::Graphics::TFont* &Font);
	bool __fastcall InternalGetHotTrack(bool &HotTrack);
	bool __fastcall InternalGetShadow(bool &Shadow);
	bool __fastcall InternalGetTextColor(System::Uitypes::TColor &TextColor);
	bool __fastcall InternalGetTextStyle(System::Uitypes::TFontStyles &TextStyle);
	bool __fastcall InternalGetTransparentBorder(bool &TransparentBorder);
	void __fastcall InternalSetFont(Vcl::Graphics::TFont* AFont);
	bool __fastcall IsBorderColorStored();
	bool __fastcall IsBorderStyleStored();
	bool __fastcall IsColorStored();
	bool __fastcall IsEdgesStored();
	bool __fastcall IsFontStored();
	bool __fastcall IsHotTrackStored();
	bool __fastcall IsShadowStored();
	bool __fastcall IsStyleControllerStored();
	bool __fastcall IsTextColorStored();
	bool __fastcall IsTextStyleStored();
	bool __fastcall IsTransparentBorderStored();
	void __fastcall SetAssignedValues(TcxContainerStyleValues Value);
	void __fastcall SetBorderColor(System::Uitypes::TColor Value);
	void __fastcall SetBorderStyle(Cxlookandfeelpainters::TcxContainerBorderStyle Value);
	void __fastcall SetColor(System::Uitypes::TColor Value);
	void __fastcall SetEdges(Cxgeometry::TcxBorders Value);
	void __fastcall SetFont(Vcl::Graphics::TFont* Value);
	void __fastcall SetHotTrack(bool Value);
	void __fastcall SetShadow(bool Value);
	void __fastcall SetTextColor(System::Uitypes::TColor Value);
	void __fastcall SetTextStyle(System::Uitypes::TFontStyles Value);
	void __fastcall SetTransparentBorder(bool Value);
	void __fastcall CheckChanges();
	void __fastcall CreateFont();
	TcxStyleController* __fastcall GetActiveStyleController();
	TcxContainerStyle* __fastcall GetBaseStyle();
	TcxContainer* __fastcall GetContainer();
	Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeel();
	void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	void __fastcall ReadIsFontAssigned(System::Classes::TReader* Reader);
	void __fastcall RestoreFont(Vcl::Graphics::TFont* AFont);
	void __fastcall SetLookAndFeel(Cxlookandfeels::TcxLookAndFeel* Value);
	void __fastcall UpdateVisibleFont();
	void __fastcall WriteIsFontAssigned(System::Classes::TWriter* Writer);
	
protected:
	TcxContainerStyleValues FAssignedValues;
	TcxStyleController* FStyleController;
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	TcxStyleController* __fastcall BaseGetStyleController();
	void __fastcall BaseSetStyleController(TcxStyleController* Value);
	virtual void __fastcall Changed();
	virtual void __fastcall ControllerChangedNotification(TcxStyleController* AStyleController);
	virtual void __fastcall ControllerFreeNotification(TcxStyleController* AStyleController);
	virtual System::Uitypes::TColor __fastcall DefaultBorderColor();
	virtual Cxlookandfeelpainters::TcxContainerBorderStyle __fastcall DefaultBorderStyle();
	virtual System::Uitypes::TColor __fastcall DefaultColor();
	virtual System::Uitypes::TColor __fastcall DefaultDisabledTextColor();
	virtual Cxgeometry::TcxBorders __fastcall DefaultEdges();
	virtual bool __fastcall DefaultHotTrack();
	virtual bool __fastcall DefaultShadow();
	virtual System::Uitypes::TColor __fastcall DefaultTextColor();
	virtual System::Uitypes::TFontStyles __fastcall DefaultTextStyle();
	virtual bool __fastcall DefaultTransparentBorder();
	virtual void __fastcall FontChanged(System::TObject* Sender);
	virtual System::Uitypes::TColor __fastcall GetColor();
	virtual TcxStyleController* __fastcall GetDefaultStyleController();
	virtual System::Uitypes::TColor __fastcall GetStyleColor();
	virtual System::Uitypes::TColor __fastcall GetTextColor();
	virtual System::Uitypes::TFontStyles __fastcall GetTextStyle();
	bool __fastcall InternalGetColor(System::Uitypes::TColor &Color);
	virtual TcxContainerStyleValues __fastcall InternalGetNotPublishedExtendedStyleValues();
	bool __fastcall IsDestroying();
	bool __fastcall IsFontAssignedValueLocked();
	void __fastcall LockFontAssignedValue(bool ALock);
	virtual bool __fastcall UsePainterBorderSettings();
	void __fastcall UpdateFont();
	__property TcxContainerStyle* ParentStyle = {read=FParentStyle};
	__property System::Classes::TNotifyEvent OnChanged = {read=FOnChanged, write=FOnChanged};
	
public:
	TcxContainerStyleData StyleData;
	__fastcall virtual TcxContainerStyle(System::Classes::TPersistent* AOwner, bool ADirectAccessMode, TcxContainerStyle* AParentStyle, TcxContainerStateItem AState);
	__fastcall virtual ~TcxContainerStyle();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall BeginUpdate();
	void __fastcall EndUpdate();
	bool __fastcall GetStyleValue(const System::UnicodeString APropertyName, /* out */ TcxContainerStyleValue &StyleValue);
	virtual int __fastcall GetStyleValueCount();
	virtual bool __fastcall GetStyleValueName(TcxContainerStyleValue AStyleValue, /* out */ System::UnicodeString &StyleValueName);
	Vcl::Graphics::TFont* __fastcall GetVisibleFont();
	virtual bool __fastcall HasBorder();
	bool __fastcall IsExtendedStylePropertyPublished(const System::UnicodeString APropertyName);
	virtual bool __fastcall IsValueAssigned(TcxContainerStyleValue AValue);
	virtual void __fastcall RestoreDefaults();
	__property TcxStyleController* ActiveStyleController = {read=GetActiveStyleController};
	__property TcxContainerStyle* BaseStyle = {read=GetBaseStyle};
	__property TcxContainer* Container = {read=GetContainer};
	__property bool DirectAccessMode = {read=FDirectAccessMode, nodefault};
	__property TcxContainerStateItem State = {read=FState, nodefault};
	
__published:
	__property TcxContainerStyleValues AssignedValues = {read=GetAssignedValues, write=SetAssignedValues, stored=false, nodefault};
	__property System::Uitypes::TColor BorderColor = {read=GetBorderColor, write=SetBorderColor, stored=IsBorderColorStored, nodefault};
	__property Cxlookandfeelpainters::TcxContainerBorderStyle BorderStyle = {read=GetBorderStyle, write=SetBorderStyle, stored=IsBorderStyleStored, nodefault};
	__property System::Uitypes::TColor Color = {read=GetColor, write=SetColor, stored=IsColorStored, nodefault};
	__property Cxgeometry::TcxBorders Edges = {read=GetEdges, write=SetEdges, stored=IsEdgesStored, nodefault};
	__property Vcl::Graphics::TFont* Font = {read=GetFont, write=SetFont, stored=IsFontStored};
	__property bool HotTrack = {read=GetHotTrack, write=SetHotTrack, stored=IsHotTrackStored, nodefault};
	__property Cxlookandfeels::TcxLookAndFeel* LookAndFeel = {read=GetLookAndFeel, write=SetLookAndFeel};
	__property bool Shadow = {read=GetShadow, write=SetShadow, stored=IsShadowStored, nodefault};
	__property TcxStyleController* StyleController = {read=BaseGetStyleController, write=BaseSetStyleController, stored=IsStyleControllerStored};
	__property System::Uitypes::TColor TextColor = {read=GetTextColor, write=SetTextColor, stored=IsTextColorStored, nodefault};
	__property System::Uitypes::TFontStyles TextStyle = {read=GetTextStyle, write=SetTextStyle, stored=IsTextStyleStored, nodefault};
	__property bool TransparentBorder = {read=GetTransparentBorder, write=SetTransparentBorder, stored=IsTransparentBorderStored, nodefault};
private:
	void *__IdxSkinSupport;	// Cxlookandfeels::IdxSkinSupport 
	
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
	
};


typedef TcxContainerStyle TcxCustomContainerStyle;

typedef System::TMetaClass* TcxContainerStyleClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxContainerStyles : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxContainerStyle* operator[](TcxContainerStateItem AState) { return this->Styles[AState]; }
	
private:
	System::StaticArray<TcxContainerStyle*, 4> FStyles;
	TcxContainerStyle* __fastcall GetStyle(TcxContainerStateItem AState);
	TcxContainerStyle* __fastcall GetStyleDisabled();
	TcxContainerStyle* __fastcall GetStyleFocused();
	TcxContainerStyle* __fastcall GetStyleHot();
	TcxContainerStyle* __fastcall GetStyleNormal();
	void __fastcall SetOnChanged(System::Classes::TNotifyEvent Value);
	void __fastcall SetStyle(TcxContainerStateItem AState, TcxContainerStyle* Value);
	void __fastcall SetStyleDisabled(TcxContainerStyle* Value);
	void __fastcall SetStyleFocused(TcxContainerStyle* Value);
	void __fastcall SetStyleHot(TcxContainerStyle* Value);
	void __fastcall SetStyleNormal(TcxContainerStyle* Value);
	
public:
	__fastcall virtual TcxContainerStyles(System::Classes::TPersistent* AOwner, TcxContainerStyleClass AStyleClass);
	__fastcall virtual ~TcxContainerStyles();
	void __fastcall RestoreDefaults();
	__property TcxContainerStyle* Style = {read=GetStyleNormal, write=SetStyleNormal};
	__property TcxContainerStyle* StyleDisabled = {read=GetStyleDisabled, write=SetStyleDisabled};
	__property TcxContainerStyle* StyleFocused = {read=GetStyleFocused, write=SetStyleFocused};
	__property TcxContainerStyle* StyleHot = {read=GetStyleHot, write=SetStyleHot};
	__property TcxContainerStyle* Styles[TcxContainerStateItem AState] = {read=GetStyle, write=SetStyle/*, default*/};
	__property System::Classes::TNotifyEvent OnChanged = {write=SetOnChanged};
};

#pragma pack(pop)

typedef System::TMetaClass* TcxContainerStylesClass;

class PASCALIMPLEMENTATION TcxStyleController : public Cxclasses::TcxScalableComponent
{
	typedef Cxclasses::TcxScalableComponent inherited;
	
private:
	bool FIsDestruction;
	System::Classes::TList* FListeners;
	System::Classes::TNotifyEvent FOnStyleChanged;
	TcxStyleController* __fastcall GetFakeStyleController();
	TcxContainerStyle* __fastcall GetStyle();
	TcxContainerStyle* __fastcall GetInternalStyle(TcxContainerStateItem AState);
	void __fastcall SetFakeStyleController(TcxStyleController* Value);
	void __fastcall SetInternalStyle(TcxContainerStateItem AState, TcxContainerStyle* Value);
	void __fastcall StyleChanged(System::TObject* Sender);
	
protected:
	TcxContainerStyles* FStyles;
	virtual void __fastcall ChangeScale(int M, int D);
	virtual void __fastcall Loaded();
	virtual void __fastcall AddListener(TcxContainerStyle* AListener);
	void __fastcall Changed();
	virtual TcxContainerStyleClass __fastcall GetStyleClass();
	virtual TcxContainerStylesClass __fastcall GetStylesClass();
	bool __fastcall IsDestruction();
	virtual void __fastcall RemoveListener(TcxContainerStyle* AListener);
	__property TcxContainerStyle* Style = {read=GetStyle};
	__property System::Classes::TList* Listeners = {read=FListeners};
	__property System::Classes::TNotifyEvent OnStyleChanged = {read=FOnStyleChanged, write=FOnStyleChanged};
	
public:
	__fastcall virtual TcxStyleController(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxStyleController();
	void __fastcall RestoreStyles();
	__property TcxContainerStyle* Styles[TcxContainerStateItem AState] = {read=GetInternalStyle, write=SetInternalStyle};
	
__published:
	__property Scalable = {default=1};
	__property TcxStyleController* FakeStyleController = {read=GetFakeStyleController, write=SetFakeStyleController, stored=false};
};


__interface  INTERFACE_UUID("{1B111318-D9C9-4C35-9EFF-5D95793C0106}") IcxContainerInnerControl  : public System::IInterface 
{
	virtual Vcl::Controls::TWinControl* __fastcall GetControl() = 0 ;
	virtual TcxContainer* __fastcall GetControlContainer() = 0 ;
	__property Vcl::Controls::TWinControl* Control = {read=GetControl};
	__property TcxContainer* ControlContainer = {read=GetControlContainer};
};

typedef tagSCROLLBARINFO TcxScrollBarInfo;

struct DECLSPEC_DRECORD TcxContainerActiveStyleData
{
public:
	TcxContainerState ContainerState;
	TcxContainerStyle* ActiveStyle;
};


struct DECLSPEC_DRECORD TcxContainerInnerControlBounds
{
public:
	bool IsEmpty;
	System::Types::TRect Rect;
};


struct DECLSPEC_DRECORD TcxContainerSizeGripData
{
public:
	System::Types::TRect Bounds;
	bool Visible;
};


class PASCALIMPLEMENTATION TcxContainer : public Cxcontrols::TcxControl
{
	typedef Cxcontrols::TcxControl inherited;
	
private:
	TcxContainerActiveStyleData FActiveStyleData;
	bool FHasChanges;
	Vcl::Controls::TWinControl* FInnerControl;
	TcxContainerInnerControlBounds FInnerControlBounds;
	bool FInnerControlBufferedPaint;
	bool FInnerControlMouseDown;
	bool FIsViewInfoCalculated;
	int FLockAlignControlsCount;
	int FPopupMenuLockCount;
	int FProcessEventsLockCount;
	int FRefreshLockCount;
	bool FScrollBarsCalculating;
	TcxContainerSizeGripData FSizeGripData;
	TcxStyleController* __fastcall GetFakeStyleController();
	TcxContainerStyle* __fastcall GetInternalStyle(TcxContainerStateItem AState);
	HIDESBASE bool __fastcall GetIsDestroying();
	bool __fastcall GetOnGlass();
	void __fastcall GetStandardScrollBarParameters(Vcl::Forms::TScrollBarKind AKind, /* out */ tagSCROLLINFO &AScrollInfo);
	TcxContainerStyle* __fastcall GetStyle();
	TcxContainerStyle* __fastcall GetStyleDisabled();
	TcxContainerStyle* __fastcall GetStyleFocused();
	TcxContainerStyle* __fastcall GetStyleHot();
	Vcl::Graphics::TFont* __fastcall GetVisibleFont();
	System::Uitypes::TColor __fastcall GetVisibleFontColor();
	void __fastcall SetFakeStyleController(TcxStyleController* Value);
	void __fastcall SetInnerControl(Vcl::Controls::TWinControl* Value);
	void __fastcall SetOnGlass(bool AValue);
	HIDESBASE void __fastcall SetParentFont(bool Value);
	void __fastcall SetStyle(TcxContainerStyle* Value);
	void __fastcall SetStyleDisabled(TcxContainerStyle* Value);
	void __fastcall SetStyleFocused(TcxContainerStyle* Value);
	void __fastcall SetStyleHot(TcxContainerStyle* Value);
	void __fastcall SetInternalStyle(TcxContainerStateItem AState, TcxContainerStyle* Value);
	System::Uitypes::TDragKind __fastcall GetDragKind();
	HIDESBASE MESSAGE void __fastcall WMDestroy(Winapi::Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall WMKillFocus(Winapi::Messages::TWMKillFocus &Message);
	HIDESBASE MESSAGE void __fastcall WMSetCursor(Winapi::Messages::TWMSetCursor &Message);
	HIDESBASE MESSAGE void __fastcall WMSetFocus(Winapi::Messages::TWMSetFocus &Message);
	HIDESBASE MESSAGE void __fastcall WMWindowPosChanged(Winapi::Messages::TWMWindowPosMsg &Message);
	HIDESBASE MESSAGE void __fastcall WMWindowPosChanging(Winapi::Messages::TWMWindowPosMsg &Message);
	HIDESBASE MESSAGE void __fastcall CMBiDiModeChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMCtl3DChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMParentColorChanged(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall CMShortRefreshContainer(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMParentFontChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMSysColorChange(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall CMUpdateScrollBars(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall DXMUpdateWindowRegion(Winapi::Messages::TMessage &Message);
	
protected:
	int FInternalSetting;
	bool FIsCreating;
	TcxContainerStyles* FStyles;
	TcxContainerViewInfo* FViewInfo;
	int FUpdateWindowRegionCount;
	bool FInternalWindowRegionSetting;
	HRGN FNewWindowRegion;
	virtual Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeelValue();
	Vcl::Controls::TWinControl* __fastcall GetActiveControl();
	virtual void __fastcall MouseTrackingCallerMouseLeave();
	virtual void __fastcall AdjustClientRect(System::Types::TRect &Rect);
	virtual void __fastcall AlignControls(Vcl::Controls::TControl* AControl, System::Types::TRect &Rect);
	virtual bool __fastcall AllowAutoDragAndDropAtDesignTime(int X, int Y, System::Classes::TShiftState Shift);
	virtual bool __fastcall CanFocusOnClick()/* overload */;
	virtual void __fastcall ChangeScaleEx(int M, int D, bool isDpiChange);
	DYNAMIC void __fastcall ColorChanged();
	virtual void __fastcall CorrectAlignControlRect(System::Types::TRect &R);
	DYNAMIC void __fastcall CursorChanged();
	DYNAMIC void __fastcall DoContextPopup(const System::Types::TPoint &MousePos, bool &Handled);
	DYNAMIC void __fastcall DragCanceled();
	DYNAMIC void __fastcall FocusChanged();
	virtual bool __fastcall FocusWhenChildIsClicked(Vcl::Controls::TControl* AChild);
	virtual System::Types::TRect __fastcall GetClientBounds();
	virtual TcxContainerState __fastcall GetContainerState(const System::Types::TPoint &P, bool AMouseTracking);
	virtual bool __fastcall IsGestureTarget(NativeUInt AWnd);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall Loaded();
	DYNAMIC bool __fastcall MayFocus();
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseEnter(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual bool __fastcall NeedsScrollBars();
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall Paint();
	DYNAMIC void __fastcall Resize();
	virtual void __fastcall SetDragMode(System::Uitypes::TDragMode Value);
	virtual void __fastcall SetParent(Vcl::Controls::TWinControl* AParent);
	virtual void __fastcall CreateHandle();
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall CreateWindowHandle(const Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall DestroyHandle();
	virtual void __fastcall DestroyWnd();
	virtual void __fastcall UpdateScrollBars();
	virtual bool __fastcall UseSystemRightToLeftLayoutForInnerControl();
	virtual bool __fastcall UseInnerControlScrollBarParameters();
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	virtual void __fastcall AdjustInnerControl();
	virtual void __fastcall AdjustInnerControlScrollBarBounds(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Types::TRect &ABounds);
	virtual void __fastcall AdjustScrollBarPosition(const Cxcontrols::_di_IcxControlScrollBar AScrollBar);
	virtual void __fastcall AdjustScrollBarPositions();
	virtual void __fastcall AdjustVisibleFontHeight(Vcl::Graphics::TFont* AVisibleFont);
	virtual void __fastcall CalculateViewInfo(const System::Types::TPoint &P, bool AMouseTracking);
	virtual bool __fastcall CanContainerHandleTabs();
	virtual bool __fastcall CanHaveTransparentBorder();
	virtual bool __fastcall CanRefreshContainer();
	virtual bool __fastcall CanShowPopupMenu(const System::Types::TPoint &P);
	void __fastcall CheckIsViewInfoCalculated();
	virtual void __fastcall ContainerStyleChanged(System::TObject* Sender);
	virtual HRGN __fastcall CreateWindowRegion();
	virtual void __fastcall DataChange();
	virtual void __fastcall DataSetChange();
	virtual bool __fastcall DefaultParentColor();
	virtual bool __fastcall DoInnerControlDefaultHandler(Winapi::Messages::TMessage &Message);
	virtual void __fastcall DoProcessEventsOnViewInfoChanging();
	virtual bool __fastcall DoRefreshContainer(const System::Types::TPoint &P, TcxMouseButton Button, System::Classes::TShiftState Shift, bool AIsMouseEvent);
	virtual void __fastcall ShortRefreshContainerOnWindowPosChanging();
	virtual void __fastcall EnabledChanged();
	virtual void __fastcall EndMouseTracking();
	virtual TcxContainerStyle* __fastcall GetActiveStyle();
	virtual System::Types::TRect __fastcall GetBorderExtent();
	virtual System::Uitypes::TColor __fastcall GetDefaultSkinnedTextColor(bool AEnabled);
	virtual Cxlookandfeelpainters::TcxEditStateColorKind __fastcall GetEditStateColorKind();
	virtual TcxContainerInnerControlBounds __fastcall GetInnerControlBounds(const System::Types::TRect &AInnerControlsRegion, Vcl::Controls::TControl* AInnerControl);
	NativeUInt __fastcall GetScrollBarHandle(Vcl::Forms::TScrollBarKind AKind);
	virtual System::Types::TRect __fastcall GetShadowBounds();
	virtual System::Types::TRect __fastcall GetShadowBoundsExtent();
	virtual TcxContainerStyleClass __fastcall GetStyleClass();
	virtual TcxContainerStylesClass __fastcall GetStylesClass();
	virtual TcxContainerViewInfoClass __fastcall GetViewInfoClass();
	virtual System::Types::TRect __fastcall GetWindowRegionAddon();
	virtual bool __fastcall HasShadow();
	virtual TcxContainerStyle* __fastcall InternalGetActiveStyle();
	virtual TcxContainerStyleValues __fastcall InternalGetNotPublishedStyleValues();
	virtual bool __fastcall CanDisableAlignOnCreateInnerControl();
	virtual bool __fastcall HandleInnerControlGestures();
	bool __fastcall IsAlignControlsLocked();
	virtual bool __fastcall IsContainerFocused();
	bool __fastcall IsInnerControlBoundsChanged(Vcl::Controls::TWinControl* AControl, const TcxContainerInnerControlBounds &ABounds);
	virtual bool __fastcall IsContainerClass();
	virtual bool __fastcall IsMouseTracking();
	virtual bool __fastcall IsNativeStyle();
	bool __fastcall IsPopupMenuLocked();
	virtual bool __fastcall IsReadOnly();
	bool __fastcall IsStyleAssigned(TcxContainerStyleValue AValue);
	void __fastcall BeginRefreshContainer();
	bool __fastcall EndRefreshContainer(bool AIsMouseEvent = false);
	bool __fastcall IsRefreshContainerLocked();
	bool __fastcall RefreshContainer(const System::Types::TPoint &P, TcxMouseButton Button, System::Classes::TShiftState Shift, bool AIsMouseEvent);
	void __fastcall SaveInnerControlBounds(Vcl::Controls::TWinControl* AControl, const TcxContainerInnerControlBounds &ABounds);
	virtual void __fastcall DoSetSize();
	void __fastcall SetSize();
	virtual void __fastcall SetVisibleBoundsClipRect();
	virtual void __fastcall UpdateData();
	virtual bool __fastcall NeedUpdateWindowRegion();
	virtual void __fastcall UpdateWindowRegion();
	virtual Dxthememanager::TdxThemedObjectType __fastcall GetBackgroundThemedObjectType();
	virtual int __fastcall GetBackgroundNativePart();
	virtual int __fastcall GetBackgroundNativeState();
	virtual System::Uitypes::TColor __fastcall GetScrollContentForegroundColor();
	virtual System::Types::TRect __fastcall GetScrollBarBounds(const System::Types::TRect &AScrollBarRect);
	virtual bool __fastcall GetScrollBarEnabled(Cxcontrols::_di_IcxControlScrollBar AScrollBar, const tagSCROLLBARINFO &AScrollBarinfo);
	virtual bool __fastcall GetScrollBarInfo(tagSCROLLBARINFO &AScrollBarInfo, const Vcl::Forms::TScrollBarKind AKind);
	bool __fastcall IsScrollBarVisible(Vcl::Forms::TScrollBarKind AKind, /* out */ tagSCROLLBARINFO &AScrollbarInfo);
	void __fastcall ProcessEventsOnViewInfoChanging();
	virtual void __fastcall SafeSelectionFocusInnerControl();
	virtual void __fastcall ScaleFactorChanged();
	virtual void __fastcall SetDragKind(System::Uitypes::TDragKind Value);
	virtual void __fastcall SetScrollBarVisible(Cxcontrols::_di_IcxControlScrollBar AScrollBar, bool AVisible);
	virtual bool __fastcall UseBorderedBackground();
	__property TcxContainerStyle* ActiveStyle = {read=GetActiveStyle};
	__property System::Uitypes::TDragKind DragKind = {read=GetDragKind, write=SetDragKind, default=0};
	__property bool HasChanges = {read=FHasChanges, write=FHasChanges, nodefault};
	__property bool IsViewInfoCalculated = {read=FIsViewInfoCalculated, write=FIsViewInfoCalculated, nodefault};
	__property bool ScrollBarsCalculating = {read=FScrollBarsCalculating, nodefault};
	__property TcxContainerStyle* Style = {read=GetStyle, write=SetStyle};
	__property TcxContainerStyle* StyleDisabled = {read=GetStyleDisabled, write=SetStyleDisabled};
	__property TcxContainerStyle* StyleFocused = {read=GetStyleFocused, write=SetStyleFocused};
	__property TcxContainerStyle* StyleHot = {read=GetStyleHot, write=SetStyleHot};
	__property TcxContainerViewInfo* ViewInfo = {read=FViewInfo};
	__property Vcl::Graphics::TFont* VisibleFont = {read=GetVisibleFont};
	__property System::Uitypes::TColor VisibleFontColor = {read=GetVisibleFontColor, nodefault};
	
public:
	__fastcall virtual TcxContainer(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxContainer();
	DYNAMIC bool __fastcall Focused();
	virtual Vcl::Controls::TDragImageList* __fastcall GetDragImages();
	DYNAMIC void __fastcall GetTabOrderList(System::Classes::TList* List);
	virtual void __fastcall SetFocus();
	virtual void __fastcall Invalidate();
	virtual void __fastcall Update();
	virtual void __fastcall ClearSavedChildControlRegions();
	virtual System::Types::TRect __fastcall GetVisibleBounds();
	bool __fastcall HasInnerControl();
	bool __fastcall HasInnerControlHandle();
	virtual bool __fastcall HasPopupWindow();
	bool __fastcall InnerControlDefaultHandler(Winapi::Messages::TMessage &Message);
	virtual bool __fastcall InnerControlMenuHandler(Winapi::Messages::TMessage &Message);
	virtual bool __fastcall IsInplace();
	bool __fastcall IsStylePropertyPublished(const System::UnicodeString APropertyName, bool AExtendedStyle);
	void __fastcall LockAlignControls(bool ALock);
	void __fastcall LockPopupMenu(bool ALock);
	void __fastcall RestoreStyles();
	virtual void __fastcall SetScrollBarsParameters(bool AIsScrolling = false);
	bool __fastcall ShortRefreshContainer(bool AIsMouseEvent);
	void __fastcall UpdateScrollBarsParameters();
	virtual void __fastcall TranslationChanged();
	__property Vcl::Controls::TWinControl* ActiveControl = {read=GetActiveControl};
	__property Vcl::Controls::TWinControl* InnerControl = {read=FInnerControl, write=SetInnerControl};
	__property bool InnerControlMouseDown = {read=FInnerControlMouseDown, write=FInnerControlMouseDown, nodefault};
	__property bool IsDestroying = {read=GetIsDestroying, nodefault};
	__property bool OnGlass = {read=GetOnGlass, write=SetOnGlass, nodefault};
	__property ParentColor = {default=1};
	__property ParentFont = {write=SetParentFont, default=1};
	__property TcxContainerStyle* Styles[TcxContainerStateItem AState] = {read=GetInternalStyle, write=SetInternalStyle};
	__property System::Types::TRect VisibleBounds = {read=GetVisibleBounds};
	
__published:
	__property TcxStyleController* FakeStyleController = {read=GetFakeStyleController, write=SetFakeStyleController, stored=false};
	__property TabStop = {default=1};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxContainer(HWND ParentWindow) : Cxcontrols::TcxControl(ParentWindow) { }
	
	/* Hoisted overloads: */
	
protected:
	inline bool __fastcall  CanFocusOnClick(int X, int Y){ return Cxcontrols::TcxControl::CanFocusOnClick(X, Y); }
	
private:
	void *__IcxMouseTrackingCaller;	// Dxcoreclasses::IcxMouseTrackingCaller 
	void *__IcxCompoundControl;	// Cxcontrols::IcxCompoundControl 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {84A4BCBE-E001-4D60-B7A6-75E2B0DCD3E9}
	operator Dxcoreclasses::_di_IcxMouseTrackingCaller()
	{
		Dxcoreclasses::_di_IcxMouseTrackingCaller intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Dxcoreclasses::IcxMouseTrackingCaller*(void) { return (Dxcoreclasses::IcxMouseTrackingCaller*)&__IcxMouseTrackingCaller; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {A4A77F28-1D03-425B-9A83-0B853B5D8DEF}
	operator Cxcontrols::_di_IcxCompoundControl()
	{
		Cxcontrols::_di_IcxCompoundControl intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontrols::IcxCompoundControl*(void) { return (Cxcontrols::IcxCompoundControl*)&__IcxCompoundControl; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00000000-0000-0000-C000-000000000046}
	operator System::_di_IInterface()
	{
		System::_di_IInterface intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator System::IInterface*(void) { return (System::IInterface*)&__IcxCompoundControl; }
	#endif
	
};


struct DECLSPEC_DRECORD TcxPrevPopupControlData
{
public:
	Vcl::Controls::TAlign Align;
	System::Types::TRect Bounds;
	Vcl::Controls::TWinControl* Parent;
	bool Visible;
	Vcl::Forms::TFormBorderStyle BorderStyle;
	Vcl::Controls::TWinControl* ActiveControl;
};


class PASCALIMPLEMENTATION TcxCustomPopupWindow : public Cxcontrols::TcxPopupWindow
{
	typedef Cxcontrols::TcxPopupWindow inherited;
	
private:
	bool FCaptureFocus;
	int FDeactivateLockCount;
	bool FDeactivation;
	Vcl::Controls::TWinControl* FFocusedControl;
	bool FIsPopup;
	bool FIsTopMost;
	bool FJustClosed;
	bool FModalMode;
	bool FTerminateOnDestroy;
	Vcl::Controls::TWinControl* FOwnerControl;
	HWND FSavedWndParent;
	System::Classes::TNotifyEvent FOnBeforeClosing;
	System::Classes::TNotifyEvent FOnClosed;
	System::Classes::TNotifyEvent FOnClosing;
	System::Classes::TNotifyEvent FOnShowed;
	System::Classes::TNotifyEvent FOnShowing;
	bool __fastcall GetJustClosed();
	void __fastcall SetCaptureFocus(bool Value);
	void __fastcall SetIsTopMost(bool Value);
	MESSAGE void __fastcall CMClosePopupWindow(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseEnter(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseLeave(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMRecreateWnd(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMShowingChanged(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall CMShowPopupWindow(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMActivate(Winapi::Messages::TWMActivate &Message);
	HIDESBASE MESSAGE void __fastcall WMActivateApp(Winapi::Messages::TWMActivateApp &Message);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Winapi::Messages::TWMEraseBkgnd &Message);
	HIDESBASE MESSAGE void __fastcall WMWindowPosChanging(Winapi::Messages::TWMWindowPosMsg &Message);
	
protected:
	TcxContainerStyle* FStyle;
	TcxContainerViewInfo* FViewInfo;
	Vcl::Forms::TCustomForm* FPrevActiveForm;
	Vcl::Controls::TWinControl* FPrevActiveControl;
	bool FShowWithoutActivation;
	virtual void __fastcall AdjustClientRect(System::Types::TRect &Rect);
	DYNAMIC void __fastcall Deactivate();
	virtual void __fastcall InitPopup();
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall Paint();
	DYNAMIC void __fastcall VisibleChanged();
	virtual void __fastcall CreateHandle();
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall CreateWindowHandle(const Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd();
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual bool __fastcall AcceptsAnySize();
	virtual void __fastcall DoBeforeClosing();
	virtual void __fastcall DoClosed();
	virtual void __fastcall DoClosing();
	virtual void __fastcall DoShowed();
	virtual void __fastcall DoShowing();
	Vcl::Controls::TWinControl* __fastcall GetFirstFocusControl(Vcl::Controls::TWinControl* AControl);
	Vcl::Controls::TWinControl* __fastcall GetOwnerControl();
	virtual bool __fastcall HasBackground();
	void __fastcall InternalEnableWindow(bool AEnable);
	bool __fastcall IsDeactivateLocked();
	bool __fastcall IsOwnerControlVisible();
	virtual bool __fastcall IsSysKeyAccepted(System::Word Key);
	virtual void __fastcall ModalCloseUp();
	DYNAMIC void __fastcall MouseEnter(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	virtual bool __fastcall NeedIgnoreMouseMessageAfterCloseUp(NativeUInt AWnd, unsigned AMsg, System::Classes::TShiftState AShift, const System::Types::TPoint &APos);
	virtual void __fastcall PopupWindowStyleChanged(System::TObject* Sender);
	void __fastcall RecreateWindow();
	void __fastcall UpdateScaleFactor();
	virtual bool __fastcall UseOwnerParentToGetScreenBounds();
	__property TcxContainerStyle* Style = {read=FStyle};
	__property TcxContainerViewInfo* ViewInfo = {read=FViewInfo};
	
public:
	__fastcall virtual TcxCustomPopupWindow(Vcl::Controls::TWinControl* AOwnerControl);
	__fastcall virtual ~TcxCustomPopupWindow();
	DYNAMIC bool __fastcall CanFocus();
	DYNAMIC bool __fastcall Focused();
	void __fastcall ClosePopup();
	virtual void __fastcall CloseUp();
	virtual void __fastcall CorrectBoundsWithDesktopWorkArea(System::Types::TPoint &APosition, System::Types::TSize &ASize);
	virtual TcxContainerStyleClass __fastcall GetStyleClass();
	virtual TcxContainerViewInfoClass __fastcall GetViewInfoClass();
	bool __fastcall HasCapture();
	DYNAMIC bool __fastcall IsShortCut(Winapi::Messages::TWMKey &Message);
	bool __fastcall IsVisible();
	void __fastcall LockDeactivate(bool ALock);
	HIDESBASE virtual void __fastcall Popup(Vcl::Controls::TWinControl* AFocusedControl);
	virtual bool __fastcall SetFocusedControl(Vcl::Controls::TWinControl* Control);
	__property bool CaptureFocus = {read=FCaptureFocus, write=SetCaptureFocus, default=1};
	__property Vcl::Controls::TWinControl* FocusedControl = {read=FFocusedControl, write=FFocusedControl};
	__property bool IsTopMost = {read=FIsTopMost, write=SetIsTopMost, nodefault};
	__property bool JustClosed = {read=GetJustClosed, nodefault};
	__property bool ModalMode = {read=FModalMode, write=FModalMode, default=1};
	__property Vcl::Controls::TWinControl* OwnerControl = {read=GetOwnerControl};
	__property bool TerminateOnDestroy = {read=FTerminateOnDestroy, write=FTerminateOnDestroy, nodefault};
	__property System::Classes::TNotifyEvent OnBeforeClosing = {read=FOnBeforeClosing, write=FOnBeforeClosing};
	__property System::Classes::TNotifyEvent OnClosed = {read=FOnClosed, write=FOnClosed};
	__property System::Classes::TNotifyEvent OnClosing = {read=FOnClosing, write=FOnClosing};
	__property OnCloseQuery;
	__property System::Classes::TNotifyEvent OnShowed = {read=FOnShowed, write=FOnShowed};
	__property System::Classes::TNotifyEvent OnShowing = {read=FOnShowing, write=FOnShowing};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxCustomPopupWindow(System::Classes::TComponent* AOwner, int Dummy) : Cxcontrols::TcxPopupWindow(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomPopupWindow(HWND ParentWindow) : Cxcontrols::TcxPopupWindow(ParentWindow) { }
	
private:
	void *__IdxPopupControl;	// Cxcontrols::IdxPopupControl 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {631D4C30-8543-4A08-A50E-9ABA2FA7EF33}
	operator Cxcontrols::_di_IdxPopupControl()
	{
		Cxcontrols::_di_IdxPopupControl intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontrols::IdxPopupControl*(void) { return (Cxcontrols::IdxPopupControl*)&__IdxPopupControl; }
	#endif
	
};


class PASCALIMPLEMENTATION TcxCustomInnerListBox : public Vcl::Stdctrls::TListBox
{
	typedef Vcl::Stdctrls::TListBox inherited;
	
private:
	System::UnicodeString FAutoCompleteFilter;
	Cxgraphics::TcxCanvas* FCanvas;
	Cxgraphics::TcxBitmap* FItemBitmap;
	bool FIsRedrawLocked;
	Cxlookandfeels::TcxLookAndFeel* FLookAndFeel;
	System::Uitypes::TColor FPrevBrushColor;
	System::Uitypes::TColor FPrevFontColor;
	unsigned FPrevKeyPressTime;
	Vcl::Stdctrls::TListBoxStyle FRealStyle;
	Cxcontrols::TdxTouchScrollUIActivityHelper* FScrollUIActivityHelper;
	void __fastcall EraseBackground(HDC DC);
	int __fastcall FindAutoCompleteString(const System::UnicodeString S);
	HIDESBASE Vcl::Controls::TWinControl* __fastcall GetControl();
	TcxContainer* __fastcall GetControlContainer();
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetPainter();
	Cxgeometry::TdxScaleFactor* __fastcall GetScaleFactor();
	void __fastcall SetLookAndFeel(Cxlookandfeels::TcxLookAndFeel* Value);
	void __fastcall ValidateItemBitmapSize(const System::Types::TSize &AItemSize);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Winapi::Messages::TWMEraseBkgnd &Message);
	MESSAGE void __fastcall WMGetDlgCode(Winapi::Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall WMKillFocus(Winapi::Messages::TWMKillFocus &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonDown(Winapi::Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMNCCalcSize(Winapi::Messages::TWMNCCalcSize &Message);
	HIDESBASE MESSAGE void __fastcall WMNCPaint(Winapi::Messages::TWMNCPaint &Message);
	HIDESBASE MESSAGE void __fastcall WMSetFocus(Winapi::Messages::TWMSetFocus &Message);
	MESSAGE void __fastcall WMSetRedraw(Winapi::Messages::TWMSetRedraw &Message);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseEnter(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseLeave(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CNCommand(Winapi::Messages::TWMCommand &Message);
	HIDESBASE MESSAGE void __fastcall CNDrawItem(Winapi::Messages::TWMDrawItem &Message);
	HIDESBASE MESSAGE void __fastcall CNMeasureItem(Winapi::Messages::TWMMeasureItem &Message);
	
protected:
	TcxContainer* FContainer;
	Cxlookandfeels::TdxPadding FBackgroundPadding;
	Cxlookandfeels::TdxPadding FItemPadding;
	void __fastcall VisualRefinementsChanged();
	DYNAMIC void __fastcall Click();
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd();
	DYNAMIC void __fastcall DblClick();
	virtual void __fastcall DestroyWindowHandle();
	virtual void __fastcall BufferedDrawItem(HDC DC, int AIndex, const System::Types::TRect &ARect, Winapi::Windows::TOwnerDrawState AState);
	virtual void __fastcall CalculatePadding();
	virtual void __fastcall DrawItem(int Index, const System::Types::TRect &Rect, Winapi::Windows::TOwnerDrawState State);
	virtual void __fastcall DrawItemContent(int AIndex, const System::Types::TRect &ARect, Winapi::Windows::TOwnerDrawState AState);
	virtual void __fastcall DrawItemFocusRect(const System::Types::TRect &ABounds);
	virtual void __fastcall DrawItemText(const System::UnicodeString AText, const System::Types::TRect &ARect, Winapi::Windows::TOwnerDrawState AState);
	virtual void __fastcall DrawItemBackground(int AIndex, const System::Types::TRect &ARect, Winapi::Windows::TOwnerDrawState AState);
	virtual Cxlookandfeels::TdxPadding __fastcall GetDefaultItemPadding();
	virtual System::Types::TRect __fastcall GetItemContentBounds(const System::Types::TRect &ARect);
	virtual System::Types::TRect __fastcall GetItemFocusRectBounds(const System::Types::TRect &ARect);
	virtual int __fastcall GetItemNonTextWidth(int AIndex);
	virtual bool __fastcall IsBufferedItemPaint();
	virtual bool __fastcall SupportsListBoxSkinPadding();
	void __fastcall PrepareDrawItemCanvas(Vcl::Graphics::TCanvas* ACanvas, int AIndex, Winapi::Windows::TOwnerDrawState AState);
	virtual void __fastcall DoAutoComplete(System::WideChar &Key);
	virtual bool __fastcall DoCustomDrawItem(int AIndex, const System::Types::TRect &ARect, Winapi::Windows::TOwnerDrawState AState);
	virtual void __fastcall DoGesture(const Vcl::Controls::TGestureEventInfo &EventInfo, bool &Handled);
	virtual void __fastcall DoGetGestureOptions(Vcl::Controls::TInteractiveGestures &Gestures, Vcl::Controls::TInteractiveGestureOptions &Options);
	DYNAMIC bool __fastcall DoMouseWheel(System::Classes::TShiftState Shift, int WheelDelta, const System::Types::TPoint &MousePos);
	void __fastcall DoScroll(Vcl::Forms::TScrollBarKind AKind, System::Uitypes::TScrollCode AScrollCode, int AScrollPos);
	DYNAMIC void __fastcall DragOver(System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	virtual int __fastcall GetDefaultItemHeight();
	virtual unsigned __fastcall GetDrawTextFlags();
	virtual System::UnicodeString __fastcall GetItem(int AIndex);
	DYNAMIC Vcl::Menus::TPopupMenu* __fastcall GetPopupMenu();
	virtual Vcl::Stdctrls::TListBoxStyle __fastcall GetRealStyle();
	virtual TcxContainer* __fastcall GetRootContainer();
	virtual bool __fastcall IsEmbedded();
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	DYNAMIC void __fastcall KeyUp(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseEnter(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual bool __fastcall NeedDrawFocusRect();
	void __fastcall Scroll(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	void __fastcall UpdateControl();
	virtual void __fastcall UpdateItemsLayout();
	virtual bool __fastcall HasContentVerticalPadding();
	virtual bool __fastcall UseCustomPadding();
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	__property TcxContainer* Container = {read=FContainer, write=FContainer};
	__property bool IsRedrawLocked = {read=FIsRedrawLocked, nodefault};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* Painter = {read=GetPainter};
	__property TcxContainer* RootContainer = {read=GetRootContainer};
	
public:
	__fastcall virtual TcxCustomInnerListBox(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomInnerListBox();
	virtual void __fastcall DefaultHandler(void *Message);
	DYNAMIC void __fastcall DragDrop(System::TObject* Source, int X, int Y);
	virtual int __fastcall GetItemWidth(int AIndex);
	virtual void __fastcall SetExternalScrollBarsParameters();
	bool __fastcall ItemVisible(int Index);
	__property Cxgraphics::TcxCanvas* Canvas = {read=FCanvas};
	__property Cxlookandfeels::TcxLookAndFeel* LookAndFeel = {read=FLookAndFeel, write=SetLookAndFeel};
	__property Cxgeometry::TdxScaleFactor* ScaleFactor = {read=GetScaleFactor};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomInnerListBox(HWND ParentWindow) : Vcl::Stdctrls::TListBox(ParentWindow) { }
	
private:
	void *__IdxVisualRefinementsListener;	// Cxlookandfeels::IdxVisualRefinementsListener 
	void *__IcxContainerInnerControl;	// IcxContainerInnerControl 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {287BA6FB-1282-4933-AFDB-45DC4D2E3F65}
	operator Cxlookandfeels::_di_IdxVisualRefinementsListener()
	{
		Cxlookandfeels::_di_IdxVisualRefinementsListener intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Cxlookandfeels::IdxVisualRefinementsListener*(void) { return (Cxlookandfeels::IdxVisualRefinementsListener*)&__IdxVisualRefinementsListener; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {1B111318-D9C9-4C35-9EFF-5D95793C0106}
	operator _di_IcxContainerInnerControl()
	{
		_di_IcxContainerInnerControl intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IcxContainerInnerControl*(void) { return (IcxContainerInnerControl*)&__IcxContainerInnerControl; }
	#endif
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomInnerListBoxAccessibilityHelper : public Cxaccessibility::TcxAccessibilityHelper
{
	typedef Cxaccessibility::TcxAccessibilityHelper inherited;
	
private:
	Cxaccessibility::TdxScrollItemProvider* FScrollItemProvider;
	TcxCustomInnerListBox* __fastcall GetListBox();
	
protected:
	virtual bool __fastcall ChildIsSimpleElement(int AIndex);
	virtual int __fastcall GetChildCount();
	virtual System::UnicodeString __fastcall GetDefaultActionDescription(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
	virtual System::UnicodeString __fastcall GetName(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
	virtual HWND __fastcall GetOwnerObjectWindow();
	virtual int __fastcall GetRole(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
	virtual int __fastcall GetState(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
	virtual Cxaccessibility::TcxAccessibleObjectProperties __fastcall GetSupportedProperties(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
	virtual bool __fastcall IsExtended();
	virtual bool __fastcall IsSupportedPattern(int APatternID, /* out */ System::_di_IInterface &AProvider, Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID = (Cxaccessibility::TcxAccessibleSimpleChildElementID)(0x0));
	__property TcxCustomInnerListBox* ListBox = {read=GetListBox};
	
public:
	__fastcall virtual TdxCustomInnerListBoxAccessibilityHelper(System::TObject* AOwnerObject);
	__fastcall virtual ~TdxCustomInnerListBoxAccessibilityHelper();
	virtual System::Types::TRect __fastcall GetScreenBounds(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
};

#pragma pack(pop)

typedef System::TMetaClass* TdxCustomInnerListBoxAccessibilityHelperClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION _TcxContainerAccess : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod void __fastcall BeginAutoDrag(TcxContainer* AInstance);
	__classmethod void __fastcall Click(TcxContainer* AInstance);
	__classmethod void __fastcall DblClick(TcxContainer* AInstance);
	__classmethod bool __fastcall DoMouseWheel(TcxContainer* AInstance, System::Classes::TShiftState Shift, int WheelDelta, const System::Types::TPoint &MousePos);
	__classmethod void __fastcall DragOver(TcxContainer* AInstance, System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	__classmethod void __fastcall KeyDown(TcxContainer* AInstance, System::Word &Key, System::Classes::TShiftState Shift);
	__classmethod void __fastcall KeyPress(TcxContainer* AInstance, System::WideChar &Key);
	__classmethod void __fastcall KeyUp(TcxContainer* AInstance, System::Word &Key, System::Classes::TShiftState Shift);
	__classmethod void __fastcall MouseDown(TcxContainer* AInstance, System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	__classmethod void __fastcall MouseMove(TcxContainer* AInstance, System::Classes::TShiftState Shift, int X, int Y);
	__classmethod void __fastcall MouseUp(TcxContainer* AInstance, System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
public:
	/* TObject.Create */ inline __fastcall _TcxContainerAccess() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~_TcxContainerAccess() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static const System::Word cxDefaultAutoCompleteDelay = System::Word(0x1f4);
static const System::Int8 cxContainerShadowWidth = System::Int8(0x3);
extern DELPHI_PACKAGE HBRUSH cxEmptyBrush;
extern DELPHI_PACKAGE System::Types::TRect cxContainerDefaultBorderExtent;
static const System::Int8 csvBorderColor = System::Int8(0x0);
static const System::Int8 csvBorderStyle = System::Int8(0x1);
static const System::Int8 csvColor = System::Int8(0x2);
static const System::Int8 csvEdges = System::Int8(0x3);
static const System::Int8 csvFont = System::Int8(0x4);
static const System::Int8 csvHotTrack = System::Int8(0x5);
static const System::Int8 csvShadow = System::Int8(0x6);
static const System::Int8 csvTextColor = System::Int8(0x7);
static const System::Int8 csvTextStyle = System::Int8(0x8);
static const System::Int8 csvTransparentBorder = System::Int8(0x9);
static const System::Int8 cxContainerStyleValueCount = System::Int8(0xa);
extern DELPHI_PACKAGE Cxcontainer__1 cxContainerStyleValueNameA;
extern DELPHI_PACKAGE TcxStyleController* cxContainerDefaultStyleController;
extern DELPHI_PACKAGE System::Uitypes::TColor cxContainerShadowColor;
extern DELPHI_PACKAGE bool TopMostComboBoxes;
extern DELPHI_PACKAGE TcxMouseButton __fastcall ButtonTocxButton(System::Uitypes::TMouseButton Button);
extern DELPHI_PACKAGE bool __fastcall cxCanShowHint(Vcl::Controls::TWinControl* AControl);
extern DELPHI_PACKAGE bool __fastcall CheckParentsNativeHandle(Vcl::Controls::TWinControl* AControl, NativeUInt ANativeHandle);
extern DELPHI_PACKAGE bool __fastcall cxGetScrollBarInfo(HWND hwnd, int idObject, tagSCROLLBARINFO &psbi)/* overload */;
extern DELPHI_PACKAGE bool __fastcall cxGetScrollBarInfo(HWND hwnd, int idObject, tagSCROLLBARINFO &psbi, Cxgeometry::TdxScaleFactor* AScaleFactor, bool AIsRightToLeftLayout)/* overload */;
extern DELPHI_PACKAGE TcxStyleController* __fastcall DefaultContainerStyleController(void);
extern DELPHI_PACKAGE void __fastcall DrawContainerShadow(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
extern DELPHI_PACKAGE void __fastcall ExtendRectByBorders(System::Types::TRect &R, int ABorderWidth, Cxgeometry::TcxBorders AEdges);
extern DELPHI_PACKAGE HWND __fastcall FindFirstNonChildParentWindow(HWND AWnd);
extern DELPHI_PACKAGE System::Uitypes::TColor __fastcall GetContainerBorderColor(bool AIsHighlight, bool AIsOffice11Style);
extern DELPHI_PACKAGE int __fastcall GetContainerBorderWidth(Cxlookandfeelpainters::TcxContainerBorderStyle ABorderStyle)/* overload */;
extern DELPHI_PACKAGE int __fastcall GetContainerBorderWidth(Cxlookandfeels::TcxLookAndFeelKind ALookAndFeelKind)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall GetControlRect(Vcl::Controls::TControl* AControl);
extern DELPHI_PACKAGE TcxContainer* __fastcall GetcxContainer(Vcl::Controls::TWinControl* AControl);
extern DELPHI_PACKAGE Vcl::Controls::TWinControl* __fastcall GetInnerControlContainer(Vcl::Controls::TWinControl* AControl);
extern DELPHI_PACKAGE HWND __fastcall GetPopupOwnerControl(HWND AWnd);
extern DELPHI_PACKAGE bool __fastcall HasHandle(Vcl::Controls::TWinControl* AControl, NativeUInt AHandle);
extern DELPHI_PACKAGE bool __fastcall HasNativeHandle(Vcl::Controls::TWinControl* AControl, NativeUInt AHandle, bool ACheckChildren = false);
extern DELPHI_PACKAGE bool __fastcall HasOpenedPopupWindow(Vcl::Controls::TWinControl* AControl);
extern DELPHI_PACKAGE void __fastcall InflateRectByBorders(System::Types::TRect &R, int ABorderWidth, Cxgeometry::TcxBorders AEdges);
extern DELPHI_PACKAGE bool __fastcall InternalCompareString(const Vcl::Controls::TCaption S1, const Vcl::Controls::TCaption S2, bool ACaseSensitive);
extern DELPHI_PACKAGE void __fastcall InternalInvalidate(NativeUInt AHandle, const System::Types::TRect &AOuterRect, const System::Types::TRect &AInternalRect, bool AEraseBackground = false, bool ARedrawNC = false);
extern DELPHI_PACKAGE bool __fastcall IsChildWindow(Vcl::Controls::TWinControl* AParent, NativeUInt AChildHandle);
extern DELPHI_PACKAGE bool __fastcall IsRelatedWindow(NativeUInt AParentHandle, NativeUInt AChildHandle)/* overload */;
extern DELPHI_PACKAGE bool __fastcall IsRelatedWindow(Vcl::Controls::TWinControl* AParent, NativeUInt AChildHandle)/* overload */;
extern DELPHI_PACKAGE bool __fastcall IsFormActive(Vcl::Forms::TCustomForm* AForm);
extern DELPHI_PACKAGE bool __fastcall IsMouseDownMessage(NativeUInt AMsg);
extern DELPHI_PACKAGE bool __fastcall IsMessageInQueue _DEPRECATED_ATTRIBUTE0 (HWND AWnd, unsigned AMessage);
extern DELPHI_PACKAGE bool __fastcall KillMessages _DEPRECATED_ATTRIBUTE0 (HWND AWnd, unsigned AMsgFilterMin, unsigned AMsgFilterMax = (unsigned)(0x0), bool AKillAllMessages = true);
extern DELPHI_PACKAGE void __fastcall LockCMActivateMessages(bool ALock);
extern DELPHI_PACKAGE void __fastcall CloseRelatedPopups(HWND AWnd);
extern DELPHI_PACKAGE void __fastcall CloseUnrelatedPopups(HWND AWnd);
extern DELPHI_PACKAGE System::Classes::TShiftState __fastcall MouseButtonToShift(System::Uitypes::TMouseButton Button);
extern DELPHI_PACKAGE HRGN __fastcall GetWindowRegion(NativeUInt AWindowHandle);
extern DELPHI_PACKAGE void __fastcall SetWindowEmptyRegion(NativeUInt AWindowHandle);
extern DELPHI_PACKAGE bool __fastcall SetWindowRegion(NativeUInt AWindowHandle, HRGN ARegionHandle, bool ARedraw = true)/* overload */;
extern DELPHI_PACKAGE void __fastcall SetWindowRegion(NativeUInt AWindowHandle, HRGN ARegionHandle, Cxgraphics::TcxRegionOperation AOperation, bool ARedraw = true)/* overload */;
extern DELPHI_PACKAGE void __fastcall SetWindowRegion(Vcl::Controls::TWinControl* AControl, const System::Types::TRect &ABounds, Cxgraphics::TcxRegionOperation AOperation = (Cxgraphics::TcxRegionOperation)(0x0), bool ARedraw = true)/* overload */;
extern DELPHI_PACKAGE void __fastcall SetWindowRegion(Vcl::Controls::TWinControl* AControl, const TcxContainerInnerControlBounds &ABounds)/* overload */;
extern DELPHI_PACKAGE void __fastcall SetWindowShadowRegion(NativeUInt AWindowHandle, const System::Types::TRect &AShadowBounds, const System::Types::TRect &AShadowBoundsExtent, bool ANativeStyle, bool AShadow, const System::Types::TRect &AExcludeRect);
extern DELPHI_PACKAGE bool __fastcall UsecxScrollBars(void);
extern DELPHI_PACKAGE bool __fastcall AreVisualStylesMustBeUsed(bool ANativeStyle, Dxthememanager::TdxThemedObjectType AThemedObjectType);
extern DELPHI_PACKAGE System::Types::TRect __fastcall GetSizeGripRect(_di_IcxContainerInnerControl AControl)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall GetSizeGripRect(TcxContainer* AContainer)/* overload */;
extern DELPHI_PACKAGE void __fastcall cxFillSizeGrip(TcxContainer* AContainer, const System::Types::TRect &ARect)/* overload */;
extern DELPHI_PACKAGE void __fastcall cxFillSizeGrip(TcxContainer* AContainer)/* overload */;
extern DELPHI_PACKAGE void __fastcall SetHooksSettingMode(bool ASetHooksOnlyWhenPopupsAreVisible);
extern DELPHI_PACKAGE void __fastcall DisableWindow(System::Classes::TList* AWindowList, HWND AWnd);
extern DELPHI_PACKAGE void __fastcall EnableWindows(System::Classes::TList* AWindowList);
extern DELPHI_PACKAGE void __fastcall DisableAppWindows(bool ANeedDisable = true);
extern DELPHI_PACKAGE void __fastcall EnableAppWindows(void);
extern DELPHI_PACKAGE bool __fastcall IsInternalWindowsDisabled(void);
extern DELPHI_PACKAGE bool __fastcall IsInternalWindowsDisabling(void);
extern DELPHI_PACKAGE bool __fastcall ExecuteEmbeddedDialog(Vcl::Dialogs::TCommonDialog* ADialog, NativeUInt AParentWnd);
}	/* namespace Cxcontainer */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXCONTAINER)
using namespace Cxcontainer;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxcontainerHPP
