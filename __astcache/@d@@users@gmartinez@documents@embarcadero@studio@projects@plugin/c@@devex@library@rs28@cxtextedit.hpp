// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxTextEdit.pas' rev: 35.00 (Windows)

#ifndef CxtexteditHPP
#define CxtexteditHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.UITypes.hpp>
#include <Winapi.Windows.hpp>
#include <Winapi.Messages.hpp>
#include <System.Variants.hpp>
#include <System.Classes.hpp>
#include <Vcl.Clipbrd.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.StdCtrls.hpp>
#include <System.SysUtils.hpp>
#include <System.Generics.Defaults.hpp>
#include <System.Generics.Collections.hpp>
#include <dxCore.hpp>
#include <dxMessages.hpp>
#include <dxCoreClasses.hpp>
#include <cxClasses.hpp>
#include <cxContainer.hpp>
#include <cxControls.hpp>
#include <cxDataUtils.hpp>
#include <dxSpellCheckerCore.hpp>
#include <cxFormats.hpp>
#include <cxGraphics.hpp>
#include <cxVariants.hpp>
#include <cxFilterControlUtils.hpp>
#include <cxLookAndFeels.hpp>
#include <cxEdit.hpp>
#include <cxDrawTextUtils.hpp>
#include <dxUxTheme.hpp>
#include <cxLookAndFeelPainters.hpp>
#include <dxTouch.hpp>
#include <cxGeometry.hpp>
#include <dxGenerics.hpp>
#include <cxAccessibility.hpp>
#include <System.Types.hpp>

//-- user supplied -----------------------------------------------------------

namespace Cxtextedit
{
//-- forward type declarations -----------------------------------------------
__interface DELPHIINTERFACE IcxInnerTextEdit;
typedef System::DelphiInterface<IcxInnerTextEdit> _di_IcxInnerTextEdit;
class DELPHICLASS TdxCustomInnerTextEditAccessibilityHelper;
class DELPHICLASS TcxCustomInnerTextEditHelper;
struct TcxCustomInnerTextEditPrevState;
class DELPHICLASS TcxCustomInnerTextEdit;
class DELPHICLASS TcxTextEditPropertiesValues;
class DELPHICLASS TdxCustomEditListBoxAccessibilityHelper;
class DELPHICLASS TcxCustomEditListBox;
class DELPHICLASS TcxEditListBoxContainerViewInfo;
class DELPHICLASS TcxEditListBoxContainer;
__interface DELPHIINTERFACE IcxTextEditLookupData;
typedef System::DelphiInterface<IcxTextEditLookupData> _di_IcxTextEditLookupData;
__interface DELPHIINTERFACE IcxTextEditLookupDataIncrementalFilter;
typedef System::DelphiInterface<IcxTextEditLookupDataIncrementalFilter> _di_IcxTextEditLookupDataIncrementalFilter;
class DELPHICLASS TcxCustomTextEditLookupData;
class DELPHICLASS TcxCustomTextEditViewData;
struct TcxTextOutData;
class DELPHICLASS TcxCustomTextEditViewInfo;
class DELPHICLASS TcxCustomTextEditProperties;
class DELPHICLASS TcxTextEditProperties;
class DELPHICLASS TdxCustomTextEditAccessibilityHelper;
class DELPHICLASS TcxCustomTextEdit;
class DELPHICLASS TcxTextEdit;
class DELPHICLASS TcxFilterTextEditHelper;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TcxEditEchoMode : unsigned char { eemNormal, eemPassword };

enum DECLSPEC_DENUM TcxEditScrollCause : unsigned char { escKeyboard, escMouseWheel };

enum DECLSPEC_DENUM TcxEditValueBound : unsigned char { evbMin, evbMax };

enum DECLSPEC_DENUM TcxTextEditViewStyle : unsigned char { vsNormal, vsHideCursor, vsButtonsOnly, vsButtonsAutoWidth };

typedef void __fastcall (__closure *TcxTextEditCustomDrawHandler)(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);

__interface  INTERFACE_UUID("{263EBB8D-1EA9-4CAC-8367-ADD74D2A9651}") IcxInnerTextEdit  : public Cxedit::IcxCustomInnerEdit 
{
	virtual void __fastcall ClearSelection() = 0 ;
	virtual void __fastcall CopyToClipboard() = 0 ;
	virtual System::Classes::TAlignment __fastcall GetAlignment() = 0 ;
	virtual bool __fastcall GetAutoSelect() = 0 ;
	virtual System::Uitypes::TEditCharCase __fastcall GetCharCase() = 0 ;
	virtual TcxEditEchoMode __fastcall GetEchoMode() = 0 ;
	virtual int __fastcall GetFirstVisibleCharIndex() = 0 ;
	virtual bool __fastcall GetHideSelection() = 0 ;
	virtual System::WideChar __fastcall GetImeLastChar() = 0 ;
	virtual Vcl::Controls::TImeMode __fastcall GetImeMode() = 0 ;
	virtual Vcl::Controls::TImeName __fastcall GetImeName() = 0 ;
	virtual bool __fastcall GetInternalUpdating() = 0 ;
	virtual int __fastcall GetMaxLength() = 0 ;
	virtual bool __fastcall GetMultiLine() = 0 ;
	virtual bool __fastcall GetOEMConvert() = 0 ;
	virtual System::Classes::TNotifyEvent __fastcall GetOnSelChange() = 0 ;
	virtual System::WideChar __fastcall GetPasswordChar() = 0 ;
	virtual int __fastcall GetSelLength() = 0 ;
	virtual int __fastcall GetSelStart() = 0 ;
	virtual System::UnicodeString __fastcall GetSelText() = 0 ;
	virtual bool __fastcall GetUseLeftAlignmentOnEditing() = 0 ;
	virtual void __fastcall SelectAll() = 0 ;
	virtual void __fastcall SetAlignment(System::Classes::TAlignment Value) = 0 ;
	virtual void __fastcall SetAutoSelect(bool Value) = 0 ;
	virtual void __fastcall SetCharCase(System::Uitypes::TEditCharCase Value) = 0 ;
	virtual void __fastcall SetEchoMode(TcxEditEchoMode Value) = 0 ;
	virtual void __fastcall SetHideSelection(bool Value) = 0 ;
	virtual void __fastcall SetInternalUpdating(bool Value) = 0 ;
	virtual void __fastcall SetImeMode(Vcl::Controls::TImeMode Value) = 0 ;
	virtual void __fastcall SetImeName(const Vcl::Controls::TImeName Value) = 0 ;
	virtual void __fastcall SetMaxLength(int Value) = 0 ;
	virtual void __fastcall SetOEMConvert(bool Value) = 0 ;
	virtual void __fastcall SetOnSelChange(System::Classes::TNotifyEvent Value) = 0 ;
	virtual void __fastcall SetPasswordChar(System::WideChar Value) = 0 ;
	virtual void __fastcall SetSelLength(int Value) = 0 ;
	virtual void __fastcall SetSelStart(int Value) = 0 ;
	virtual void __fastcall SetSelText(System::UnicodeString Value) = 0 ;
	virtual void __fastcall SetUseLeftAlignmentOnEditing(bool Value) = 0 ;
	virtual System::UnicodeString __fastcall GetTextHint() = 0 ;
	virtual void __fastcall SetTextHint(System::UnicodeString Value) = 0 ;
	__property System::Classes::TAlignment Alignment = {read=GetAlignment, write=SetAlignment};
	__property bool AutoSelect = {read=GetAutoSelect, write=SetAutoSelect};
	__property System::Uitypes::TEditCharCase CharCase = {read=GetCharCase, write=SetCharCase};
	__property TcxEditEchoMode EchoMode = {read=GetEchoMode, write=SetEchoMode};
	__property bool HideSelection = {read=GetHideSelection, write=SetHideSelection};
	__property System::WideChar ImeLastChar = {read=GetImeLastChar};
	__property Vcl::Controls::TImeMode ImeMode = {read=GetImeMode, write=SetImeMode};
	__property Vcl::Controls::TImeName ImeName = {read=GetImeName, write=SetImeName};
	__property bool InternalUpdating = {read=GetInternalUpdating, write=SetInternalUpdating};
	__property int MaxLength = {read=GetMaxLength, write=SetMaxLength};
	__property bool MultiLine = {read=GetMultiLine};
	__property bool OEMConvert = {read=GetOEMConvert, write=SetOEMConvert};
	__property System::WideChar PasswordChar = {read=GetPasswordChar, write=SetPasswordChar};
	__property int SelLength = {read=GetSelLength, write=SetSelLength};
	__property int SelStart = {read=GetSelStart, write=SetSelStart};
	__property System::UnicodeString SelText = {read=GetSelText, write=SetSelText};
	__property bool UseLeftAlignmentOnEditing = {read=GetUseLeftAlignmentOnEditing, write=SetUseLeftAlignmentOnEditing};
	__property System::UnicodeString TextHint = {read=GetTextHint, write=SetTextHint};
	__property System::Classes::TNotifyEvent OnSelChange = {read=GetOnSelChange, write=SetOnSelChange};
};

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomInnerTextEditAccessibilityHelper : public Cxedit::TdxEditChildAccessibilityHelper
{
	typedef Cxedit::TdxEditChildAccessibilityHelper inherited;
	
private:
	TcxCustomTextEdit* __fastcall GetCustomTextEdit();
	TcxCustomInnerTextEdit* __fastcall GetInnerTextEdit();
	TcxCustomTextEditProperties* __fastcall GetEditProperties();
	
protected:
	virtual Cxaccessibility::TcxAccessibilityHelper* __fastcall GetParent();
	virtual int __fastcall GetRole(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
	virtual int __fastcall GetState(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
	virtual Cxaccessibility::TcxAccessibleObjectProperties __fastcall GetSupportedProperties(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
	virtual System::UnicodeString __fastcall GetValue(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
	virtual bool __fastcall IsExtended();
	virtual void __fastcall SetValue(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID, const System::UnicodeString Value);
	__property TcxCustomTextEdit* CustomTextEdit = {read=GetCustomTextEdit};
	__property TcxCustomInnerTextEdit* InnerTextEdit = {read=GetInnerTextEdit};
	__property TcxCustomTextEditProperties* EditProperties = {read=GetEditProperties};
	
public:
	virtual System::Types::TRect __fastcall GetScreenBounds(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
public:
	/* TcxAccessibilityHelper.Create */ inline __fastcall virtual TdxCustomInnerTextEditAccessibilityHelper(System::TObject* AOwnerObject) : Cxedit::TdxEditChildAccessibilityHelper(AOwnerObject) { }
	/* TcxAccessibilityHelper.Destroy */ inline __fastcall virtual ~TdxCustomInnerTextEditAccessibilityHelper() { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TdxCustomInnerTextEditAccessibilityHelperClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomInnerTextEditHelper : public Dxcoreclasses::TcxInterfacedPersistent
{
	typedef Dxcoreclasses::TcxInterfacedPersistent inherited;
	
private:
	TcxCustomInnerTextEdit* FEdit;
	int FSelLength;
	int FSelStart;
	
protected:
	__property TcxCustomInnerTextEdit* Edit = {read=FEdit};
	
public:
	__fastcall virtual TcxCustomInnerTextEditHelper(TcxCustomInnerTextEdit* AEdit);
	Cxcontainer::TcxContainer* __fastcall GetControlContainer();
	Vcl::Controls::TWinControl* __fastcall GetControl();
	NativeInt __fastcall CallDefWndProc(unsigned AMsg, NativeUInt WParam, NativeInt LParam);
	bool __fastcall CanProcessClipboardMessages();
	System::Variant __fastcall GetEditValue();
	Cxaccessibility::_di_IcxAccessibilityHelper __fastcall GetIAccessibilityHelper();
	System::Classes::TNotifyEvent __fastcall GetOnChange();
	void __fastcall LockBounds(bool ALock);
	void __fastcall SafelySetFocus();
	void __fastcall SetEditValue(const System::Variant &Value);
	void __fastcall SetParent(Vcl::Controls::TWinControl* Value);
	void __fastcall SetOnChange(System::Classes::TNotifyEvent Value);
	void __fastcall ClearSelection();
	void __fastcall CopyToClipboard();
	System::Classes::TAlignment __fastcall GetAlignment();
	bool __fastcall GetAutoSelect();
	System::Uitypes::TEditCharCase __fastcall GetCharCase();
	TcxEditEchoMode __fastcall GetEchoMode();
	int __fastcall GetFirstVisibleCharIndex();
	bool __fastcall GetHideSelection();
	System::WideChar __fastcall GetImeLastChar();
	Vcl::Controls::TImeMode __fastcall GetImeMode();
	Vcl::Controls::TImeName __fastcall GetImeName();
	bool __fastcall GetInternalUpdating();
	bool __fastcall GetIsInplace();
	int __fastcall GetMaxLength();
	bool __fastcall GetMultiLine();
	bool __fastcall GetOEMConvert();
	System::Classes::TNotifyEvent __fastcall GetOnSelChange();
	System::WideChar __fastcall GetPasswordChar();
	bool __fastcall GetReadOnly();
	int __fastcall GetSelLength();
	int __fastcall GetSelStart();
	System::UnicodeString __fastcall GetSelText();
	bool __fastcall GetUseLeftAlignmentOnEditing();
	void __fastcall SelectAll();
	void __fastcall SetAlignment(System::Classes::TAlignment Value);
	void __fastcall SetAutoSelect(bool Value);
	void __fastcall SetCharCase(System::Uitypes::TEditCharCase Value);
	void __fastcall SetEchoMode(TcxEditEchoMode Value);
	void __fastcall SetHideSelection(bool Value);
	void __fastcall SetInternalUpdating(bool Value);
	void __fastcall SetImeMode(Vcl::Controls::TImeMode Value);
	void __fastcall SetImeName(const Vcl::Controls::TImeName Value);
	void __fastcall SetMaxLength(int Value);
	void __fastcall SetOEMConvert(bool Value);
	void __fastcall SetOnSelChange(System::Classes::TNotifyEvent Value);
	void __fastcall SetPasswordChar(System::WideChar Value);
	void __fastcall SetReadOnly(bool Value);
	void __fastcall SetSelLength(int Value);
	void __fastcall SetSelStart(int Value);
	void __fastcall SetSelText(System::UnicodeString Value);
	void __fastcall SetUseLeftAlignmentOnEditing(bool Value);
	System::UnicodeString __fastcall GetTextHint();
	void __fastcall SetTextHint(System::UnicodeString Value);
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxCustomInnerTextEditHelper() { }
	
private:
	void *__IcxInnerTextEdit;	// IcxInnerTextEdit 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {263EBB8D-1EA9-4CAC-8367-ADD74D2A9651}
	operator _di_IcxInnerTextEdit()
	{
		_di_IcxInnerTextEdit intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IcxInnerTextEdit*(void) { return (IcxInnerTextEdit*)&__IcxInnerTextEdit; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {468D21B5-48AA-4077-8ED5-4C6112D460B1}
	operator Cxedit::_di_IcxCustomInnerEdit()
	{
		Cxedit::_di_IcxCustomInnerEdit intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Cxedit::IcxCustomInnerEdit*(void) { return (Cxedit::IcxCustomInnerEdit*)&__IcxInnerTextEdit; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {1B111318-D9C9-4C35-9EFF-5D95793C0106}
	operator Cxcontainer::_di_IcxContainerInnerControl()
	{
		Cxcontainer::_di_IcxContainerInnerControl intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontainer::IcxContainerInnerControl*(void) { return (Cxcontainer::IcxContainerInnerControl*)&__IcxInnerTextEdit; }
	#endif
	
};

#pragma pack(pop)

struct DECLSPEC_DRECORD TcxCustomInnerTextEditPrevState
{
public:
	bool IsPrevTextSaved;
	System::UnicodeString PrevText;
	int PrevSelLength;
	int PrevSelStart;
};


class PASCALIMPLEMENTATION TcxCustomInnerTextEdit : public Vcl::Stdctrls::TCustomEdit
{
	typedef Vcl::Stdctrls::TCustomEdit inherited;
	
private:
	System::Classes::TAlignment FAlignment;
	TcxEditEchoMode FEchoMode;
	TcxCustomInnerTextEditHelper* FHelper;
	Cxaccessibility::_di_IcxAccessibilityHelper FIAccessibilityHelper;
	int FImeCharCount;
	System::WideChar FImeLastChar;
	bool FInternalUpdating;
	bool FIsCreating;
	int FLockBoundsCount;
	System::WideChar FPasswordChar;
	bool FRepaintOnGlass;
	bool FUseLeftAlignmentOnEditing;
	System::Classes::TNotifyEvent FOnSelChange;
	Cxaccessibility::_di_IcxAccessibilityHelper __fastcall GetIAccessibilityHelper();
	System::Classes::TAlignment __fastcall GetAlignment();
	TcxCustomTextEdit* __fastcall GetContainer();
	int __fastcall GetCursorPos();
	bool __fastcall GetIsDestroying();
	System::Classes::TAlignment __fastcall GetRealAlignment();
	bool __fastcall IsDesigning();
	void __fastcall InternalPaint(NativeUInt ADC);
	HIDESBASE void __fastcall SetAlignment(System::Classes::TAlignment Value);
	void __fastcall SetEchoMode(const TcxEditEchoMode Value);
	void __fastcall SetUseLeftAlignmentOnEditing(bool Value);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseEnter(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseLeave(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall EMReplaceSel(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall EMSetSel(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMChar(Winapi::Messages::TWMKey &Message);
	MESSAGE void __fastcall WMClear(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Winapi::Messages::TWMEraseBkgnd &Message);
	MESSAGE void __fastcall WMGetDlgCode(Winapi::Messages::TWMNoParams &Message);
	MESSAGE void __fastcall WMGetObject(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall WMIMEChar(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall WMIMEComposition(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMKeyDown(Winapi::Messages::TWMKey &Message);
	HIDESBASE MESSAGE void __fastcall WMKillFocus(Winapi::Messages::TWMKillFocus &Message);
	HIDESBASE MESSAGE void __fastcall WMNCPaint(Winapi::Messages::TWMNCPaint &Message);
	HIDESBASE MESSAGE void __fastcall WMPaint(Winapi::Messages::TWMPaint &Message);
	HIDESBASE MESSAGE void __fastcall WMPrintClient(Winapi::Messages::TWMPrint &Message);
	HIDESBASE MESSAGE void __fastcall WMSetCursor(Winapi::Messages::TWMSetCursor &Message);
	HIDESBASE MESSAGE void __fastcall WMSetFocus(Winapi::Messages::TWMSetFocus &Message);
	HIDESBASE MESSAGE void __fastcall WMSetFont(Winapi::Messages::TWMSetFont &Message);
	HIDESBASE MESSAGE void __fastcall WMSize(Winapi::Messages::TWMSize &Message);
	MESSAGE void __fastcall WMUndo(Winapi::Messages::TWMSize &Message);
	
protected:
	bool IsPasswordRevealButtonPressed;
	HIDESBASE Vcl::Controls::TWinControl* __fastcall GetControl();
	Cxcontainer::TcxContainer* __fastcall GetControlContainer();
	Cxedit::_di_IcxCustomInnerEdit __fastcall GetHelper();
	DYNAMIC void __fastcall Change();
	DYNAMIC void __fastcall Click();
	virtual void __fastcall CreateHandle();
	virtual TcxCustomInnerTextEditHelper* __fastcall CreateHelper();
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall CreateWindowHandle(const Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd();
	DYNAMIC void __fastcall DblClick();
	virtual void __fastcall DestroyWnd();
	DYNAMIC bool __fastcall DoMouseWheel(System::Classes::TShiftState Shift, int WheelDelta, const System::Types::TPoint &MousePos);
	DYNAMIC void __fastcall DragOver(System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	System::Classes::TAlignment __fastcall GetBasedAlignment();
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	DYNAMIC void __fastcall KeyUp(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	virtual void __fastcall AdjustMargins();
	DYNAMIC void __fastcall MouseEnter(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	HIDESBASE void __fastcall RecreateWnd();
	virtual TdxCustomInnerTextEditAccessibilityHelperClass __fastcall GetAccessibilityHelperClass();
	__property System::Classes::TAlignment Alignment = {read=FAlignment, write=SetAlignment, nodefault};
	__property TcxCustomTextEdit* Container = {read=GetContainer};
	__property int CursorPos = {read=GetCursorPos, nodefault};
	__property TcxCustomInnerTextEditHelper* Helper = {read=FHelper};
	__property Cxaccessibility::_di_IcxAccessibilityHelper IAccessibilityHelper = {read=GetIAccessibilityHelper};
	__property bool IsDestroying = {read=GetIsDestroying, nodefault};
	__property bool UseLeftAlignmentOnEditing = {read=FUseLeftAlignmentOnEditing, write=SetUseLeftAlignmentOnEditing, nodefault};
	
public:
	__fastcall virtual TcxCustomInnerTextEdit(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomInnerTextEdit();
	DYNAMIC void __fastcall DragDrop(System::TObject* Source, int X, int Y);
	DYNAMIC bool __fastcall ExecuteAction(System::Classes::TBasicAction* Action);
	virtual bool __fastcall UpdateAction(System::Classes::TBasicAction* Action);
	DYNAMIC bool __fastcall CanFocus();
	virtual void __fastcall DefaultHandler(void *Message);
	DYNAMIC System::Classes::TAlignment __fastcall GetControlsAlignment();
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	__property AutoSelect = {default=1};
	__property CharCase = {default=0};
	__property TcxEditEchoMode EchoMode = {read=FEchoMode, write=SetEchoMode, nodefault};
	__property HideSelection = {default=1};
	__property ImeMode = {default=3};
	__property ImeName = {default=0};
	__property MaxLength = {default=0};
	__property OEMConvert = {default=0};
	__property ReadOnly = {default=0};
	__property OnChange;
	__property System::Classes::TNotifyEvent OnSelChange = {read=FOnSelChange, write=FOnSelChange};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomInnerTextEdit(HWND ParentWindow) : Vcl::Stdctrls::TCustomEdit(ParentWindow) { }
	
private:
	void *__IcxInnerEditHelper;	// Cxedit::IcxInnerEditHelper 
	void *__IcxContainerInnerControl;	// Cxcontainer::IcxContainerInnerControl 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {35667555-6DC8-40D5-B705-B08D5697C621}
	operator Cxedit::_di_IcxInnerEditHelper()
	{
		Cxedit::_di_IcxInnerEditHelper intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Cxedit::IcxInnerEditHelper*(void) { return (Cxedit::IcxInnerEditHelper*)&__IcxInnerEditHelper; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {1B111318-D9C9-4C35-9EFF-5D95793C0106}
	operator Cxcontainer::_di_IcxContainerInnerControl()
	{
		Cxcontainer::_di_IcxContainerInnerControl intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontainer::IcxContainerInnerControl*(void) { return (Cxcontainer::IcxContainerInnerControl*)&__IcxContainerInnerControl; }
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
	operator System::IInterface*(void) { return (System::IInterface*)&__IcxInnerEditHelper; }
	#endif
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxTextEditPropertiesValues : public Cxedit::TcxCustomEditPropertiesValues
{
	typedef Cxedit::TcxCustomEditPropertiesValues inherited;
	
private:
	bool FDisplayFormat;
	bool FEditFormat;
	bool FMaxLength;
	bool __fastcall IsDisplayFormatStored();
	bool __fastcall IsEditFormatStored();
	void __fastcall SetDisplayFormat(bool Value);
	void __fastcall SetEditFormat(bool Value);
	void __fastcall SetMaxLength(bool Value);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults();
	
__published:
	__property bool DisplayFormat = {read=FDisplayFormat, write=SetDisplayFormat, stored=IsDisplayFormatStored, nodefault};
	__property bool EditFormat = {read=FEditFormat, write=SetEditFormat, stored=IsEditFormatStored, nodefault};
	__property bool MaxLength = {read=FMaxLength, write=SetMaxLength, stored=false, nodefault};
	__property MaxValue;
	__property MinValue;
public:
	/* TcxCustomEditPropertiesValues.Create */ inline __fastcall virtual TcxTextEditPropertiesValues(System::Classes::TPersistent* AOwner) : Cxedit::TcxCustomEditPropertiesValues(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxTextEditPropertiesValues() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomEditListBoxAccessibilityHelper : public Cxcontainer::TdxCustomInnerListBoxAccessibilityHelper
{
	typedef Cxcontainer::TdxCustomInnerListBoxAccessibilityHelper inherited;
	
public:
	/* TdxCustomInnerListBoxAccessibilityHelper.Create */ inline __fastcall virtual TdxCustomEditListBoxAccessibilityHelper(System::TObject* AOwnerObject) : Cxcontainer::TdxCustomInnerListBoxAccessibilityHelper(AOwnerObject) { }
	/* TdxCustomInnerListBoxAccessibilityHelper.Destroy */ inline __fastcall virtual ~TdxCustomEditListBoxAccessibilityHelper() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxCustomEditListBox : public Cxcontainer::TcxCustomInnerListBox
{
	typedef Cxcontainer::TcxCustomInnerListBox inherited;
	
private:
	System::Types::TPoint FGestureAccumulatedDelta;
	Dxtouch::TdxGestureHelper* FGestureHelper;
	bool FHotTrack;
	Cxaccessibility::_di_IcxAccessibilityHelper FIAccessibilityHelper;
	System::Types::TPoint FPrevMousePos;
	System::Classes::TNotifyEvent FOnSelectItem;
	TcxCustomTextEdit* __fastcall GetEdit();
	Cxaccessibility::_di_IcxAccessibilityHelper __fastcall GetIAccessibilityHelper();
	HIDESBASE Cxgeometry::TdxScaleFactor* __fastcall GetScaleFactor();
	MESSAGE void __fastcall WMGetObject(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMShowingChanged(Winapi::Messages::TMessage &Message);
	
private:
	TcxEditListBoxContainer* __fastcall GetContainer();
	
protected:
	bool __fastcall AllowGesture(int AGestureId);
	bool __fastcall AllowPan(Vcl::Forms::TScrollBarKind AScrollKind);
	void __fastcall BeginGestureScroll(const System::Types::TPoint &APos);
	void __fastcall EndGestureScroll();
	void __fastcall GestureScroll(int ADeltaX, int ADeltaY);
	int __fastcall GetPanOptions();
	bool __fastcall IsPanArea(const System::Types::TPoint &APoint);
	bool __fastcall NeedPanningFeedback(Vcl::Forms::TScrollBarKind AScrollKind);
	Dxtouch::_di_IdxGestureClient __fastcall GetGestureClient(const System::Types::TPoint &APoint);
	NativeUInt __fastcall GetGestureClientHandle();
	bool __fastcall IsGestureTarget(NativeUInt AWnd);
	virtual void __fastcall DoGesture(const Vcl::Controls::TGestureEventInfo &EventInfo, bool &Handled);
	virtual void __fastcall DoGetGestureOptions(Vcl::Controls::TInteractiveGestures &Gestures, Vcl::Controls::TInteractiveGestureOptions &Options);
	virtual void __fastcall CalculatePadding();
	DYNAMIC void __fastcall Click();
	DYNAMIC bool __fastcall DoMouseWheel(System::Classes::TShiftState Shift, int WheelDelta, const System::Types::TPoint &MousePos);
	virtual void __fastcall DrawItemText(const System::UnicodeString AText, const System::Types::TRect &ARect, Winapi::Windows::TOwnerDrawState AState);
	virtual unsigned __fastcall GetDrawTextFlags();
	DYNAMIC NativeInt __fastcall GetItemData(int Index);
	virtual bool __fastcall IsEmbedded();
	virtual bool __fastcall IsHighlightSearchText();
	virtual bool __fastcall NeedDrawFocusRect();
	virtual bool __fastcall NeedApplyVerticalPaddings();
	virtual void __fastcall MeasureItem(int Index, int &Height);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall SetItemData(int Index, NativeInt AData);
	virtual bool __fastcall DoCustomDrawItem(int AIndex, const System::Types::TRect &ARect, Winapi::Windows::TOwnerDrawState AState);
	void __fastcall DoSelectItem();
	virtual System::UnicodeString __fastcall GetItem(int AIndex);
	void __fastcall InternalRecreateWindow();
	virtual void __fastcall RecreateWindow();
	void __fastcall SetItemCount(int Value);
	virtual void __fastcall SetItemIndex(const int Value)/* overload */;
	virtual bool __fastcall UseCustomPadding();
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	virtual Cxcontainer::TdxCustomInnerListBoxAccessibilityHelperClass __fastcall GetAccessibilityHelperClass();
	__property TcxEditListBoxContainer* Container = {read=GetContainer};
	__property TcxCustomTextEdit* Edit = {read=GetEdit};
	__property bool HotTrack = {read=FHotTrack, write=FHotTrack, nodefault};
	__property Cxaccessibility::_di_IcxAccessibilityHelper IAccessibilityHelper = {read=GetIAccessibilityHelper};
	__property Cxgeometry::TdxScaleFactor* ScaleFactor = {read=GetScaleFactor};
	__property System::Classes::TNotifyEvent OnSelectItem = {read=FOnSelectItem, write=FOnSelectItem};
	
public:
	__fastcall virtual TcxCustomEditListBox(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomEditListBox();
	DYNAMIC bool __fastcall CanFocus();
	virtual int __fastcall GetHeight(int ARowCount, int AMaxHeight);
	HIDESBASE virtual int __fastcall GetItemHeight(int AIndex = 0xffffffff);
	bool __fastcall IsVisible();
	HIDESBASE void __fastcall SetScrollWidth(int Value);
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomEditListBox(HWND ParentWindow) : Cxcontainer::TcxCustomInnerListBox(ParentWindow) { }
	
private:
	void *__IdxGestureOwner;	// Dxtouch::IdxGestureOwner 
	void *__IdxGestureClient2;	// Dxtouch::IdxGestureClient2 
	void *__IdxGestureClient;	// Dxtouch::IdxGestureClient 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {4DF001DA-BE2C-4817-B75C-55171270D158}
	operator Dxtouch::_di_IdxGestureOwner()
	{
		Dxtouch::_di_IdxGestureOwner intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Dxtouch::IdxGestureOwner*(void) { return (Dxtouch::IdxGestureOwner*)&__IdxGestureOwner; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {834D1E09-D446-4E7E-9DE3-AE158BAA9B73}
	operator Dxtouch::_di_IdxGestureClient2()
	{
		Dxtouch::_di_IdxGestureClient2 intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Dxtouch::IdxGestureClient2*(void) { return (Dxtouch::IdxGestureClient2*)&__IdxGestureClient2; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {652B8A09-DAC8-4332-9206-C8905AEE7791}
	operator Dxtouch::_di_IdxGestureClient()
	{
		Dxtouch::_di_IdxGestureClient intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Dxtouch::IdxGestureClient*(void) { return (Dxtouch::IdxGestureClient*)&__IdxGestureClient; }
	#endif
	
};


typedef System::TMetaClass* TcxCustomEditListBoxClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxEditListBoxContainerViewInfo : public Cxcontainer::TcxContainerViewInfo
{
	typedef Cxcontainer::TcxContainerViewInfo inherited;
	
private:
	TcxCustomEditListBox* __fastcall GetListBox();
	
protected:
	virtual void __fastcall DrawNonNativeStyleBackground(Cxgraphics::TcxCanvas* ACanvas);
	__property TcxCustomEditListBox* ListBox = {read=GetListBox};
public:
	/* TcxContainerViewInfo.Create */ inline __fastcall virtual TcxEditListBoxContainerViewInfo() : Cxcontainer::TcxContainerViewInfo() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxEditListBoxContainerViewInfo() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxEditListBoxContainer : public Cxedit::TcxCustomEditContainer
{
	typedef Cxedit::TcxCustomEditContainer inherited;
	
private:
	TcxCustomEditListBox* __fastcall GetListBox();
	HIDESBASE MESSAGE void __fastcall WMWindowPosChanged(Winapi::Messages::TWMWindowPosMsg &Message);
	
protected:
	virtual void __fastcall AdjustInnerControlScrollBarBounds(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Types::TRect &ABounds);
	virtual bool __fastcall AllowTouchScrollUIMode();
	virtual void __fastcall CorrectAlignControlRect(System::Types::TRect &R);
	virtual void __fastcall DoScrollUIModeChanged();
	virtual System::Types::TRect __fastcall GetBorderExtent();
	virtual Cxcontainer::TcxContainerState __fastcall GetContainerState(const System::Types::TPoint &P, bool AMouseTracking);
	virtual Cxcontainer::TcxContainerViewInfoClass __fastcall GetViewInfoClass();
	virtual bool __fastcall IsMouseWheelHandleNeeded(System::Classes::TShiftState Shift, int WheelDelta, const System::Types::TPoint &MousePos);
	virtual bool __fastcall NeedsScrollBars();
	virtual void __fastcall Scroll(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	__property TcxCustomEditListBox* ListBox = {read=GetListBox};
	
public:
	__fastcall virtual TcxEditListBoxContainer(System::Classes::TComponent* AOwner);
	DYNAMIC bool __fastcall CanFocus();
public:
	/* TcxContainer.Destroy */ inline __fastcall virtual ~TcxEditListBoxContainer() { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxEditListBoxContainer(HWND ParentWindow) : Cxedit::TcxCustomEditContainer(ParentWindow) { }
	
};


enum DECLSPEC_DENUM TcxEditLookupDataGoDirection : unsigned char { egdBegin, egdEnd, egdNext, egdPrev, egdPageUp, egdPageDown };

__interface  INTERFACE_UUID("{F49C5F08-7758-4362-A360-1DF02354E708}") IcxTextEditLookupData  : public System::IInterface 
{
	virtual bool __fastcall CanResizeVisualArea(System::Types::TSize &NewSize, int AMaxHeight = 0x0, int AMaxWidth = 0x0) = 0 ;
	virtual void __fastcall CloseUp() = 0 ;
	virtual void __fastcall Deinitialize() = 0 ;
	virtual void __fastcall DropDown() = 0 ;
	virtual void __fastcall DroppedDown(const System::UnicodeString AFindStr) = 0 ;
	virtual bool __fastcall Find(const System::UnicodeString AText) = 0 ;
	virtual Vcl::Controls::TControl* __fastcall GetActiveControl() = 0 ;
	virtual System::Variant __fastcall GetCurrentKey() = 0 ;
	virtual System::UnicodeString __fastcall GetDisplayText(const System::Variant &AKey) = 0 /* overload */;
	virtual System::Classes::TNotifyEvent __fastcall GetOnCurrentKeyChanged() = 0 ;
	virtual System::Classes::TNotifyEvent __fastcall GetOnSelectItem() = 0 ;
	virtual int __fastcall GetSelectedItem() = 0 ;
	virtual System::Types::TSize __fastcall GetVisualAreaPreferredSize(int AMaxHeight, int AWidth = 0x0) = 0 ;
	virtual void __fastcall Go(TcxEditLookupDataGoDirection ADirection, bool ACircular) = 0 ;
	virtual void __fastcall Initialize(Vcl::Controls::TWinControl* AVisualControlsParent) = 0 ;
	virtual bool __fastcall IsEmpty() = 0 ;
	virtual bool __fastcall IsMouseOverList(const System::Types::TPoint &P) = 0 ;
	virtual bool __fastcall Locate(System::UnicodeString &AText, System::UnicodeString &ATail, bool ANext) = 0 ;
	virtual void __fastcall PositionVisualArea(const System::Types::TRect &AClientRect) = 0 ;
	virtual void __fastcall PropertiesChanged() = 0 ;
	virtual void __fastcall SelectItem() = 0 ;
	virtual void __fastcall SetCurrentKey(const System::Variant &AKey) = 0 ;
	virtual void __fastcall SetOnCurrentKeyChanged(System::Classes::TNotifyEvent Value) = 0 ;
	virtual void __fastcall SetOnSelectItem(System::Classes::TNotifyEvent Value) = 0 ;
	virtual void __fastcall SetSelectedItem(int Value) = 0 ;
	virtual void __fastcall TextChanged() = 0 ;
	__property Vcl::Controls::TControl* ActiveControl = {read=GetActiveControl};
	__property System::Variant CurrentKey = {read=GetCurrentKey, write=SetCurrentKey};
	__property int SelectedItem = {read=GetSelectedItem, write=SetSelectedItem};
	__property System::Classes::TNotifyEvent OnCurrentKeyChanged = {read=GetOnCurrentKeyChanged, write=SetOnCurrentKeyChanged};
	__property System::Classes::TNotifyEvent OnSelectItem = {read=GetOnSelectItem, write=SetOnSelectItem};
};

__interface  INTERFACE_UUID("{80037B39-866D-45C5-AB85-176FE576CF2A}") IcxTextEditLookupDataIncrementalFilter  : public System::IInterface 
{
	virtual void __fastcall ResetIncrementalFilter() = 0 ;
};

class PASCALIMPLEMENTATION TcxCustomTextEditLookupData : public Dxcoreclasses::TcxInterfacedPersistent
{
	typedef Dxcoreclasses::TcxInterfacedPersistent inherited;
	
private:
	System::UnicodeString FSearchText;
	int FCurrentKey;
	Dxgenerics::TdxIntegerList* FFilteredLookupItems;
	bool FIsInitializing;
	int FItemIndex;
	TcxCustomEditListBox* FList;
	TcxEditListBoxContainer* FListContainer;
	System::Classes::TPersistent* FOwner;
	System::Classes::TNotifyEvent FOnCurrentKeyChanged;
	System::Classes::TNotifyEvent FOnSelectItem;
	int __fastcall FindItemByText(const System::UnicodeString AText, int AStartIndex, bool AFindFullText);
	TcxCustomTextEdit* __fastcall GetEdit();
	System::Classes::TStrings* __fastcall GetItems();
	TcxCustomTextEditProperties* __fastcall GetActiveProperties();
	Cxgeometry::TdxScaleFactor* __fastcall GetScaleFactor();
	int __fastcall IndexOf(const System::UnicodeString AText);
	void __fastcall SetItemIndex(int Value);
	void __fastcall SetItems(System::Classes::TStrings* Value);
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner();
	void __fastcall DoCurrentKeyChanged();
	virtual void __fastcall DoInitialize(Vcl::Controls::TWinControl* AVisualControlsParent);
	virtual void __fastcall DoPositionVisualArea(const System::Types::TRect &ARect);
	void __fastcall DoSelectItem();
	System::UnicodeString __fastcall GetFilteredItem(int Index);
	int __fastcall GetLookupItemIndexFromFilteredItemIndex(int Index);
	int __fastcall GetFilteredItemIndex(int Index);
	int __fastcall GetFilteredItemCount();
	virtual System::UnicodeString __fastcall GetItem(int Index);
	virtual int __fastcall GetItemCount();
	virtual TcxCustomEditListBoxClass __fastcall GetListBoxClass();
	virtual int __fastcall GetSelectedItem();
	virtual void __fastcall HandleSelectItem(System::TObject* Sender);
	virtual bool __fastcall InternalLocate(System::UnicodeString &AText, System::UnicodeString &ATail, bool ANext, bool ASynchronizeWithText);
	void __fastcall InternalSetItemIndex(int Value);
	virtual bool __fastcall IsFilterActive();
	bool __fastcall IsIncrementalFiltering();
	bool __fastcall IsLikeTypeFiltering();
	virtual void __fastcall ListChanged();
	virtual bool __fastcall NeedLocateItemWithFullString();
	void __fastcall ResetIncrementalFilter();
	virtual void __fastcall SetSelectedItem(int Value);
	virtual void __fastcall UpdateFilteredLookupItems(const System::UnicodeString ASearchText);
	virtual bool __fastcall UseSearchControl();
	__property TcxCustomTextEditProperties* ActiveProperties = {read=GetActiveProperties};
	__property TcxCustomTextEdit* Edit = {read=GetEdit};
	__property bool IsInitializing = {read=FIsInitializing, nodefault};
	__property int ItemIndex = {read=FItemIndex, write=SetItemIndex, stored=false, nodefault};
	__property System::Classes::TStrings* Items = {read=GetItems, write=SetItems};
	__property TcxCustomEditListBox* List = {read=FList};
	__property TcxEditListBoxContainer* ListContainer = {read=FListContainer};
	__property Cxgeometry::TdxScaleFactor* ScaleFactor = {read=GetScaleFactor};
	__property System::UnicodeString SearchText = {read=FSearchText};
	
public:
	__fastcall virtual TcxCustomTextEditLookupData(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TcxCustomTextEditLookupData();
	virtual bool __fastcall CanResizeVisualArea(System::Types::TSize &NewSize, int AMaxHeight = 0x0, int AMaxWidth = 0x0);
	virtual void __fastcall CloseUp();
	void __fastcall Deinitialize();
	virtual void __fastcall DropDown();
	virtual void __fastcall DroppedDown(const System::UnicodeString AFindStr);
	virtual bool __fastcall Find(const System::UnicodeString AText);
	virtual Vcl::Controls::TControl* __fastcall GetActiveControl();
	System::Variant __fastcall GetCurrentKey();
	System::UnicodeString __fastcall GetDisplayText(const System::Variant &AKey)/* overload */;
	System::Classes::TNotifyEvent __fastcall GetOnCurrentKeyChanged();
	System::Classes::TNotifyEvent __fastcall GetOnSelectItem();
	virtual System::Types::TSize __fastcall GetVisualAreaPreferredSize(int AMaxHeight, int AWidth = 0x0);
	void __fastcall Go(TcxEditLookupDataGoDirection ADirection, bool ACircular);
	virtual void __fastcall Initialize(Vcl::Controls::TWinControl* AVisualControlsParent);
	void __fastcall InternalSetCurrentKey(int Value);
	bool __fastcall IsEmpty();
	bool __fastcall IsMouseOverList(const System::Types::TPoint &P);
	bool __fastcall Locate(System::UnicodeString &AText, System::UnicodeString &ATail, bool ANext);
	virtual void __fastcall PositionVisualArea(const System::Types::TRect &AClientRect);
	virtual void __fastcall PropertiesChanged();
	void __fastcall SelectItem();
	void __fastcall SetCurrentKey(const System::Variant &AKey);
	void __fastcall SetOnCurrentKeyChanged(System::Classes::TNotifyEvent Value);
	void __fastcall SetOnSelectItem(System::Classes::TNotifyEvent Value);
	virtual void __fastcall TextChanged();
	__property Vcl::Controls::TControl* ActiveControl = {read=GetActiveControl};
	__property System::Variant CurrentKey = {read=GetCurrentKey, write=SetCurrentKey};
	__property System::Classes::TNotifyEvent OnCurrentKeyChanged = {read=GetOnCurrentKeyChanged, write=SetOnCurrentKeyChanged};
	__property System::Classes::TNotifyEvent OnSelectItem = {read=GetOnSelectItem, write=SetOnSelectItem};
private:
	void *__IcxTextEditLookupDataIncrementalFilter;	// IcxTextEditLookupDataIncrementalFilter 
	void *__IcxTextEditLookupData;	// IcxTextEditLookupData 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {80037B39-866D-45C5-AB85-176FE576CF2A}
	operator _di_IcxTextEditLookupDataIncrementalFilter()
	{
		_di_IcxTextEditLookupDataIncrementalFilter intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IcxTextEditLookupDataIncrementalFilter*(void) { return (IcxTextEditLookupDataIncrementalFilter*)&__IcxTextEditLookupDataIncrementalFilter; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {F49C5F08-7758-4362-A360-1DF02354E708}
	operator _di_IcxTextEditLookupData()
	{
		_di_IcxTextEditLookupData intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IcxTextEditLookupData*(void) { return (IcxTextEditLookupData*)&__IcxTextEditLookupData; }
	#endif
	
};


class PASCALIMPLEMENTATION TcxCustomTextEditViewData : public Cxedit::TcxCustomEditViewData
{
	typedef Cxedit::TcxCustomEditViewData inherited;
	
private:
	bool FIsValueFormatted;
	TcxCustomTextEditProperties* __fastcall GetProperties();
	
protected:
	virtual void __fastcall AdjustStandaloneEditTextOffsets(System::Types::TRect &AContentBounds);
	virtual void __fastcall CalculateButtonNativePartInfo(NativeUInt ATheme, Cxedit::TcxEditButtonViewInfo* AButtonViewInfo);
	virtual void __fastcall InitCacheData();
	virtual System::UnicodeString __fastcall InternalEditValueToDisplayText(const System::Variant &AEditValue);
	virtual System::Types::TSize __fastcall InternalGetEditContentSize(Cxgraphics::TcxCanvas* ACanvas, const System::Variant &AEditValue, const Cxedit::TcxEditSizeProperties &AEditSizeProperties);
	virtual bool __fastcall GetIsEditClass();
	virtual int __fastcall GetMaxLineCount();
	virtual bool __fastcall IsComboBoxStyle();
	virtual void __fastcall PrepareDrawTextFlags(Cxgraphics::TcxCanvas* ACanvas, Cxedit::TcxCustomEditViewInfo* AViewInfo);
	
public:
	virtual void __fastcall Calculate(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TPoint &P, Cxcontainer::TcxMouseButton Button, System::Classes::TShiftState Shift, Cxedit::TcxCustomEditViewInfo* ViewInfo, bool AIsMouseEvent);
	virtual System::Types::TRect __fastcall GetClientExtent(Cxgraphics::TcxCanvas* ACanvas, Cxedit::TcxCustomEditViewInfo* AViewInfo);
	virtual void __fastcall DisplayValueToDrawValue(const System::Variant &ADisplayValue, Cxedit::TcxCustomEditViewInfo* AViewInfo);
	virtual void __fastcall EditValueToDrawValue(const System::Variant &AEditValue, Cxedit::TcxCustomEditViewInfo* AViewInfo);
	virtual unsigned __fastcall GetDrawTextFlags();
	virtual System::Types::TRect __fastcall GetDrawTextOffset();
	void __fastcall PrepareSelection(Cxedit::TcxCustomEditViewInfo* AViewInfo);
	__property TcxCustomTextEditProperties* Properties = {read=GetProperties};
public:
	/* TcxCustomEditViewData.Create */ inline __fastcall virtual TcxCustomTextEditViewData(Cxedit::TcxCustomEditProperties* AProperties, Cxedit::TcxCustomEditStyle* AStyle, bool AIsInplace) : Cxedit::TcxCustomEditViewData(AProperties, AStyle, AIsInplace) { }
	/* TcxCustomEditViewData.Destroy */ inline __fastcall virtual ~TcxCustomTextEditViewData() { }
	
};


struct DECLSPEC_DRECORD TcxTextOutData
{
public:
	bool ForceEndEllipsis;
	bool Initialized;
	int RowCount;
	int SelStart;
	int SelLength;
	System::Uitypes::TColor SelBackgroundColor;
	System::Uitypes::TColor SelTextColor;
	Cxdrawtextutils::TcxTextParams TextParams;
	System::Types::TRect TextRect;
	Cxdrawtextutils::TcxTextRows TextRows;
};


class PASCALIMPLEMENTATION TcxCustomTextEditViewInfo : public Cxedit::TcxCustomEditViewInfo
{
	typedef Cxedit::TcxCustomEditViewInfo inherited;
	
protected:
	virtual Cxedit::TcxEditBackgroundPaintingStyle __fastcall GetBackgroundPaintingStyle();
	virtual void __fastcall DrawNativeButtonBackground(Cxgraphics::TcxCanvas* ACanvas, Cxedit::TcxEditButtonViewInfo* AButtonViewInfo, const System::Types::TRect &ARect);
	virtual void __fastcall DrawLookAndFeelButtonBackground(Cxgraphics::TcxCanvas* ACanvas, Cxedit::TcxEditButtonViewInfo* AButtonViewInfo, const System::Types::TRect &ARect);
	virtual void __fastcall DrawUsualButtonBackground(Cxgraphics::TcxCanvas* ACanvas, Cxedit::TcxEditButtonViewInfo* AButtonViewInfo, const System::Types::TRect &ARect, System::Uitypes::TColor ABrushColor);
	virtual void __fastcall InternalPaint(Cxgraphics::TcxCanvas* ACanvas);
	bool __fastcall DrawPasswordRevealButton(Cxgraphics::TcxCanvas* ACanvas, Cxedit::TcxEditButtonViewInfo* AButtonViewInfo, const System::Types::TRect &ARect);
	bool __fastcall NeedDrawPasswordBullets();
	
public:
	bool ComboBoxStyle;
	TcxTextEditCustomDrawHandler CustomDrawHandler;
	bool DrawSelectionBar;
	unsigned DrawTextFlags;
	Cxedit::TcxEditEditingStyle EditingStyle;
	bool HasPopupWindow;
	bool IsEditClass;
	bool IsOwnerDrawing;
	int MaxLineCount;
	int SelStart;
	int SelLength;
	System::Uitypes::TColor SelTextColor;
	System::Uitypes::TColor SelBackgroundColor;
	System::UnicodeString Text;
	TcxTextOutData TextOutData;
	System::Types::TRect TextRect;
	__fastcall virtual ~TcxCustomTextEditViewInfo();
	virtual bool __fastcall NeedShowHint(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TPoint &P, const System::Types::TRect &AVisibleBounds, /* out */ Vcl::Controls::TCaption &AText, /* out */ bool &AIsMultiLine, /* out */ System::Types::TRect &ATextRect, int AMaxLineCount = 0x0);
	virtual void __fastcall Offset(int DX, int DY);
	virtual void __fastcall DrawText(Cxgraphics::TcxCanvas* ACanvas);
	virtual int __fastcall GetTextBaseLine();
	virtual void __fastcall PrepareCanvasFont(Vcl::Graphics::TCanvas* ACanvas);
public:
	/* TcxCustomEditViewInfo.Create */ inline __fastcall virtual TcxCustomTextEditViewInfo() : Cxedit::TcxCustomEditViewInfo() { }
	
};


typedef void __fastcall (__closure *TcxNewLookupDisplayTextEvent)(System::TObject* Sender, const Vcl::Controls::TCaption AText);

typedef System::Set<char, _DELPHI_SET_CHAR(0), _DELPHI_SET_CHAR(255)> TcxTextEditChars;

enum DECLSPEC_DENUM TcxTextEditIncrementalFilteringOption : unsigned char { ifoHighlightSearchText, ifoUseContainsOperator };

typedef System::Set<TcxTextEditIncrementalFilteringOption, TcxTextEditIncrementalFilteringOption::ifoHighlightSearchText, TcxTextEditIncrementalFilteringOption::ifoUseContainsOperator> TcxTextEditIncrementalFilteringOptions;

class PASCALIMPLEMENTATION TcxCustomTextEditProperties : public Cxedit::TcxCustomEditProperties
{
	typedef Cxedit::TcxCustomEditProperties inherited;
	
private:
	System::Uitypes::TEditCharCase FCharCase;
	System::UnicodeString FDisplayFormat;
	TcxEditEchoMode FEchoMode;
	System::UnicodeString FEditFormat;
	bool FFixedListSelection;
	bool FFormatChanging;
	bool FHideCursor;
	bool FHideSelection;
	Vcl::Controls::TImeMode FImeMode;
	Vcl::Controls::TImeName FImeName;
	bool FImmediateUpdateText;
	bool FIncrementalFiltering;
	TcxTextEditIncrementalFilteringOptions FIncrementalFilteringOptions;
	bool FIncrementalSearch;
	bool FIsPasswordRevealButtonPressed;
	System::Classes::TStringList* FLookupItems;
	int FMaxLength;
	bool FMRUMode;
	System::UnicodeString FNullstring;
	bool FOEMConvert;
	System::WideChar FPasswordChar;
	int FPasswordRevealButtonIndex;
	bool FShowPasswordRevealButton;
	bool FUseDisplayFormatWhenEditing;
	bool FUseNullString;
	TcxTextEditChars FValidChars;
	TcxNewLookupDisplayTextEvent FOnNewLookupDisplayText;
	TcxTextEditPropertiesValues* __fastcall GetAssignedValues();
	System::UnicodeString __fastcall GetDisplayFormat();
	System::UnicodeString __fastcall GetEditFormat();
	System::Classes::TStrings* __fastcall GetLookupItems();
	bool __fastcall GetLookupItemsSorted();
	int __fastcall GetMaxLength();
	TcxTextEditViewStyle __fastcall GetViewStyle();
	bool __fastcall IsDisplayFormatStored();
	bool __fastcall IsEditFormatStored();
	bool __fastcall IsMaxLengthStored();
	void __fastcall LookupItemsChanged(System::TObject* Sender);
	void __fastcall ReadIsDisplayFormatAssigned(System::Classes::TReader* Reader);
	HIDESBASE void __fastcall SetAssignedValues(TcxTextEditPropertiesValues* Value);
	void __fastcall SetDisplayFormat(const System::UnicodeString Value);
	void __fastcall SetEchoMode(TcxEditEchoMode Value);
	void __fastcall SetEditFormat(const System::UnicodeString Value);
	void __fastcall SetFixedListSelection(bool Value);
	void __fastcall SetHideCursor(bool Value);
	void __fastcall SetHideSelection(bool Value);
	void __fastcall SetImeMode(Vcl::Controls::TImeMode Value);
	void __fastcall SetImeName(const Vcl::Controls::TImeName Value);
	void __fastcall SetIncrementalSearch(bool Value);
	void __fastcall SetLookupItems(System::Classes::TStrings* Value);
	void __fastcall SetLookupItemsSorted(bool Value);
	void __fastcall SetMaxLength(int Value);
	void __fastcall SetMRUMode(bool Value);
	void __fastcall SetNullstring(const System::UnicodeString Value);
	void __fastcall SetOEMConvert(bool Value);
	void __fastcall SetPasswordChar(System::WideChar Value);
	void __fastcall SetShowPasswordRevealButton(bool Value);
	void __fastcall SetUseDisplayFormatWhenEditing(bool Value);
	void __fastcall SetUseNullString(const bool Value);
	void __fastcall SetViewStyle(TcxTextEditViewStyle Value);
	
protected:
	virtual void __fastcall AlignmentChangedHandler(System::TObject* Sender);
	virtual void __fastcall BaseSetAlignment(Cxedit::TcxEditAlignment* Value);
	virtual bool __fastcall CanValidate();
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual void __fastcall DoAssign(Cxedit::TcxCustomEditProperties* AProperties);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesValuesClass __fastcall GetAssignedValuesClass();
	virtual Cxedit::TcxEditDisplayFormatOptions __fastcall GetDisplayFormatOptions();
	virtual System::UnicodeString __fastcall GetValidateErrorText(int AErrorKind);
	__classmethod virtual Cxedit::TcxCustomEditViewDataClass __fastcall GetViewDataClass();
	virtual bool __fastcall HasDisplayValue();
	virtual void __fastcall FormatChanged();
	bool __fastcall CanIncrementalSearch();
	virtual void __fastcall CheckEditValueBounds(const System::Variant &AEditValue, Vcl::Controls::TCaption &AErrorText, bool &AError, Cxedit::TcxCustomEdit* AEdit);
	virtual void __fastcall CheckDisplayValueBounds(const System::Variant &ADisplayValue, Vcl::Controls::TCaption &AErrorText, bool &AError, Cxedit::TcxCustomEdit* AEdit);
	virtual System::Variant __fastcall DefaultFocusedDisplayValue();
	void __fastcall DoDisplayValueToDisplayText(bool ANativeStyle, System::UnicodeString &ADisplayValue);
	virtual void __fastcall DoPrepareDisplayValue(const System::Variant &AEditValue, System::Variant &ADisplayValue, bool AEditFocused);
	virtual bool __fastcall FindLookupText(const System::UnicodeString AText);
	virtual System::UnicodeString __fastcall GetDefaultDisplayFormat();
	System::Variant __fastcall GetDefaultDisplayValue(const System::Variant &AEditValue, bool AEditFocused);
	virtual TcxTextEditIncrementalFilteringOptions __fastcall GetDefaultIncrementalFilteringOptions();
	virtual int __fastcall GetDefaultMaxLength();
	virtual Cxedit::TcxEditVertAlignment __fastcall GetDefaultVertAlignment();
	virtual int __fastcall GetDropDownPageRowCount();
	virtual Cxedit::TcxEditEditingStyle __fastcall GetEditingStyle();
	__classmethod virtual Dxcoreclasses::TcxInterfacedPersistentClass __fastcall GetLookupDataClass();
	virtual bool __fastcall HasDigitGrouping(bool AIsDisplayValueSynchronizing);
	virtual System::UnicodeString __fastcall InternalGetEditFormat(/* out */ bool &AIsCurrency, /* out */ bool &AIsOnGetTextAssigned, TcxCustomTextEdit* AEdit = (TcxCustomTextEdit*)(0x0));
	virtual void __fastcall LookupDataChanged(System::TObject* Sender);
	virtual void __fastcall MaxLengthChanged();
	bool __fastcall NeedUseNullString(const System::Variant &AEditValue);
	virtual void __fastcall SetCharCase(System::Uitypes::TEditCharCase Value);
	virtual void __fastcall SetIncrementalFilteringOptions(TcxTextEditIncrementalFilteringOptions Value);
	virtual bool __fastcall UseLookupData();
	virtual bool __fastcall UseSearchControl();
	virtual bool __fastcall IsEditValueEmpty(const System::Variant &AEditValue);
	virtual bool __fastcall IsEditValueNumeric();
	virtual bool __fastcall IsLookupDataVisual();
	virtual bool __fastcall IsLookupEdit();
	virtual bool __fastcall IsMultiLine();
	virtual bool __fastcall IsPopupKey(System::Word Key, System::Classes::TShiftState Shift);
	virtual bool __fastcall IsValueBoundDefined(TcxEditValueBound ABound);
	virtual bool __fastcall IsValueBoundsDefined();
	bool __fastcall TrySetPasswordRevealButtonVisible(bool AValue);
	void __fastcall SetPasswordRevealButtonVisible(bool AValue);
	void __fastcall RevealPassword(bool AIsMouseDown);
	__property TcxTextEditPropertiesValues* AssignedValues = {read=GetAssignedValues, write=SetAssignedValues};
	__property Cxedit::TcxEditEditingStyle EditingStyle = {read=GetEditingStyle, nodefault};
	__property bool FixedListSelection = {read=FFixedListSelection, write=SetFixedListSelection, default=1};
	__property bool FormatChanging = {read=FFormatChanging, nodefault};
	__property bool HideCursor = {read=FHideCursor, write=SetHideCursor, stored=false, nodefault};
	__property bool IsPasswordRevealButtonPressed = {read=FIsPasswordRevealButtonPressed, nodefault};
	__property bool MRUMode = {read=FMRUMode, write=SetMRUMode, default=0};
	__property System::UnicodeString Nullstring = {read=FNullstring, write=SetNullstring};
	__property int PasswordRevealButtonIndex = {read=FPasswordRevealButtonIndex, nodefault};
	__property bool UseNullString = {read=FUseNullString, write=SetUseNullString, default=0};
	
public:
	__fastcall virtual TcxCustomTextEditProperties(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TcxCustomTextEditProperties();
	virtual bool __fastcall CanCompareEditValue();
	virtual bool __fastcall CompareDisplayValues(const System::Variant &AEditValue1, const System::Variant &AEditValue2);
	__classmethod virtual Cxcontainer::TcxContainerClass __fastcall GetContainerClass();
	virtual System::UnicodeString __fastcall GetDisplayText(const System::Variant &AEditValue, bool AFullText = false, bool AIsInplace = true);
	virtual Cxdatautils::TcxDataEditValueSource __fastcall GetEditValueSource(bool AEditFocused);
	virtual Cxedit::TcxEditSupportedOperations __fastcall GetSupportedOperations();
	__classmethod virtual Cxcontainer::TcxContainerViewInfoClass __fastcall GetViewInfoClass();
	virtual bool __fastcall IsEditValueValid(System::Variant &AEditValue, bool AEditFocused);
	virtual bool __fastcall IsResetEditClass();
	virtual void __fastcall PrepareDisplayValue(const System::Variant &AEditValue, System::Variant &ADisplayValue, bool AEditFocused);
	virtual void __fastcall ValidateDisplayValue(System::Variant &ADisplayValue, Vcl::Controls::TCaption &AErrorText, bool &AError, Cxedit::TcxCustomEdit* AEdit);
	virtual void __fastcall DisplayValueToDisplayText(System::UnicodeString &ADisplayValue);
	virtual bool __fastcall IsDisplayValueValid(System::Variant &ADisplayValue, bool AEditFocused);
	void __fastcall SetMinMaxValues(double AMinValue, double AMaxValue);
	__property TcxTextEditChars ValidChars = {read=FValidChars, write=FValidChars};
	__property System::Uitypes::TEditCharCase CharCase = {read=FCharCase, write=SetCharCase, default=0};
	__property System::UnicodeString DisplayFormat = {read=GetDisplayFormat, write=SetDisplayFormat, stored=IsDisplayFormatStored};
	__property TcxEditEchoMode EchoMode = {read=FEchoMode, write=SetEchoMode, default=0};
	__property System::UnicodeString EditFormat = {read=GetEditFormat, write=SetEditFormat, stored=IsEditFormatStored};
	__property bool HideSelection = {read=FHideSelection, write=SetHideSelection, default=1};
	__property Vcl::Controls::TImeMode ImeMode = {read=FImeMode, write=SetImeMode, default=3};
	__property Vcl::Controls::TImeName ImeName = {read=FImeName, write=SetImeName};
	__property bool ImmediateUpdateText = {read=FImmediateUpdateText, write=FImmediateUpdateText, default=0};
	__property bool IncrementalFiltering = {read=FIncrementalFiltering, write=FIncrementalFiltering, default=0};
	__property TcxTextEditIncrementalFilteringOptions IncrementalFilteringOptions = {read=FIncrementalFilteringOptions, write=SetIncrementalFilteringOptions, default=3};
	__property bool IncrementalSearch = {read=FIncrementalSearch, write=SetIncrementalSearch, default=1};
	__property System::Classes::TStrings* LookupItems = {read=GetLookupItems, write=SetLookupItems};
	__property bool LookupItemsSorted = {read=GetLookupItemsSorted, write=SetLookupItemsSorted, default=0};
	__property int MaxLength = {read=GetMaxLength, write=SetMaxLength, stored=IsMaxLengthStored, nodefault};
	__property MaxValue = {default=0};
	__property MinValue = {default=0};
	__property bool OEMConvert = {read=FOEMConvert, write=SetOEMConvert, default=0};
	__property System::WideChar PasswordChar = {read=FPasswordChar, write=SetPasswordChar, default=0};
	__property bool ShowPasswordRevealButton = {read=FShowPasswordRevealButton, write=SetShowPasswordRevealButton, default=0};
	__property bool UseDisplayFormatWhenEditing = {read=FUseDisplayFormatWhenEditing, write=SetUseDisplayFormatWhenEditing, default=0};
	__property TcxTextEditViewStyle ViewStyle = {read=GetViewStyle, write=SetViewStyle, default=0};
	__property TcxNewLookupDisplayTextEvent OnNewLookupDisplayText = {read=FOnNewLookupDisplayText, write=FOnNewLookupDisplayText};
private:
	void *__IcxFormatControllerListener;	// Cxformats::IcxFormatControllerListener 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {A7F2F6D3-1A7D-4295-A6E6-9297BD83D0DE}
	operator Cxformats::_di_IcxFormatControllerListener()
	{
		Cxformats::_di_IcxFormatControllerListener intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Cxformats::IcxFormatControllerListener*(void) { return (Cxformats::IcxFormatControllerListener*)&__IcxFormatControllerListener; }
	#endif
	
};


class PASCALIMPLEMENTATION TcxTextEditProperties : public TcxCustomTextEditProperties
{
	typedef TcxCustomTextEditProperties inherited;
	
__published:
	__property Alignment;
	__property AssignedValues;
	__property AutoSelect = {default=1};
	__property BeepOnError = {default=0};
	__property CharCase = {default=0};
	__property ClearKey = {default=0};
	__property EchoMode = {default=0};
	__property HideSelection = {default=1};
	__property ImeMode = {default=3};
	__property ImeName = {default=0};
	__property IncrementalSearch = {default=1};
	__property LookupItems;
	__property LookupItemsSorted = {default=0};
	__property MaxLength;
	__property Nullstring = {default=0};
	__property OEMConvert = {default=0};
	__property PasswordChar = {default=0};
	__property ReadOnly;
	__property ShowPasswordRevealButton = {default=0};
	__property UseLeftAlignmentOnEditing;
	__property UseNullString = {default=0};
	__property ValidateOnEnter = {default=0};
	__property ValidationErrorIconAlignment = {default=0};
	__property ValidationOptions = {default=1};
	__property OnChange;
	__property OnEditValueChanged;
	__property OnNewLookupDisplayText;
	__property OnValidate;
public:
	/* TcxCustomTextEditProperties.Create */ inline __fastcall virtual TcxTextEditProperties(System::Classes::TPersistent* AOwner) : TcxCustomTextEditProperties(AOwner) { }
	/* TcxCustomTextEditProperties.Destroy */ inline __fastcall virtual ~TcxTextEditProperties() { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomTextEditAccessibilityHelper : public Cxedit::TdxEditAccessibilityHelper
{
	typedef Cxedit::TdxEditAccessibilityHelper inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetName(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
public:
	/* TdxEditAccessibilityHelper.Create */ inline __fastcall virtual TdxCustomTextEditAccessibilityHelper(System::TObject* AOwnerObject) : Cxedit::TdxEditAccessibilityHelper(AOwnerObject) { }
	/* TdxEditAccessibilityHelper.Destroy */ inline __fastcall virtual ~TdxCustomTextEditAccessibilityHelper() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxCustomTextEdit : public Cxedit::TcxCustomEdit
{
	typedef Cxedit::TcxCustomEdit inherited;
	
private:
	bool FBeepOnEnter;
	bool FDisableRefresh;
	bool FFindSelection;
	bool FInternalTextSetting;
	bool FIsDisplayValueSynchronizing;
	int FLastFirstVisibleCharIndex;
	int FLastSelLength;
	int FLastSelPosition;
	bool FLookupItemsScrolling;
	Vcl::Controls::TCaption FText;
	bool __fastcall DoIsMouseWheelHandleNeeded(System::Classes::TShiftState Shift, const System::Types::TPoint &MousePos);
	int __fastcall GetCursorPos();
	Vcl::Controls::TCaption __fastcall GetEditingText();
	_di_IcxInnerTextEdit __fastcall GetInnerTextEdit();
	TcxCustomTextEditLookupData* __fastcall GetLookupData();
	TcxCustomTextEditProperties* __fastcall GetProperties();
	HIDESBASE TcxCustomTextEditProperties* __fastcall GetActiveProperties();
	int __fastcall GetSelLength();
	int __fastcall GetSelStart();
	Vcl::Controls::TCaption __fastcall GetSelText();
	HIDESBASE TcxCustomTextEditViewInfo* __fastcall GetViewInfo();
	void __fastcall SetFindSelection(bool Value);
	void __fastcall SetItemObject(System::TObject* Value);
	HIDESBASE void __fastcall SetProperties(TcxCustomTextEditProperties* Value);
	void __fastcall SetSelLength(int Value);
	void __fastcall SetSelStart(int Value);
	System::UnicodeString __fastcall GetTextHint();
	void __fastcall SetTextHint(System::UnicodeString Value);
	void __fastcall TogglePassword(int AButtonVisibleIndex, bool AIsMouseDown = false);
	MESSAGE void __fastcall WMClear(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMCommand(Winapi::Messages::TWMCommand &Message);
	MESSAGE void __fastcall WMGetText(Winapi::Messages::TWMGetText &Message);
	MESSAGE void __fastcall WMGetTextLength(Winapi::Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall WMSetFocus(Winapi::Messages::TWMSetFocus &Message);
	MESSAGE void __fastcall WMSetText(Winapi::Messages::TWMSetText &Message);
	
protected:
	bool FInnerEditPositionAdjusting;
	bool FIsPopupWindowJustClosed;
	Dxcoreclasses::TcxInterfacedPersistent* FLookupData;
	bool FLookupDataTextChangedLocked;
	bool FIsChangeBySpellChecker;
	DYNAMIC void __fastcall DoExit();
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	virtual void __fastcall Loaded();
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	virtual void __fastcall AdjustInnerEditPosition();
	virtual bool __fastcall CanKeyDownModifyEdit(System::Word Key, System::Classes::TShiftState Shift);
	virtual bool __fastcall CanKeyPressModifyEdit(System::WideChar Key);
	virtual void __fastcall ChangeHandler(System::TObject* Sender);
	virtual void __fastcall ContainerStyleChanged(System::TObject* Sender);
	virtual void __fastcall DoButtonDown(int AButtonVisibleIndex);
	virtual void __fastcall DoButtonUp(int AButtonVisibleIndex);
	virtual void __fastcall DoEditKeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall DoEditKeyPress(System::WideChar &Key);
	virtual void __fastcall DoEditValueChanged();
	virtual void __fastcall DoFocusChanged();
	virtual bool __fastcall DoRefreshContainer(const System::Types::TPoint &P, Cxcontainer::TcxMouseButton Button, System::Classes::TShiftState Shift, bool AIsMouseEvent);
	virtual void __fastcall DoSetFocusWhenActivate();
	virtual void __fastcall DoValidateDisplayValue(System::Variant &ADisplayValue, Vcl::Controls::TCaption &AErrorText, bool &AError);
	virtual bool __fastcall PopulateFromList(System::UnicodeString &AFindText);
	virtual void __fastcall PopulateSizeProperties(Cxedit::TcxEditSizeProperties &AEditSizeProperties);
	virtual Cxedit::TdxEditAccessibilityHelperClass __fastcall GetAccessibilityHelperClass();
	virtual System::UnicodeString __fastcall GetDisplayText();
	virtual Cxcontainer::TcxContainerInnerControlBounds __fastcall GetInnerControlBounds(const System::Types::TRect &AInnerControlsRegion, Vcl::Controls::TControl* AInnerControl);
	virtual Vcl::Controls::TControlClass __fastcall GetInnerEditClass();
	virtual void __fastcall Initialize();
	virtual bool __fastcall InternalDoEditing();
	virtual System::Variant __fastcall InternalGetEditingValue();
	virtual void __fastcall InternalSetDisplayValue(const System::Variant &Value);
	virtual void __fastcall InternalValidateDisplayValue(const System::Variant &ADisplayValue);
	virtual bool __fastcall IsLookupNavigationKey(System::Word AKey, System::Classes::TShiftState AShift);
	virtual bool __fastcall IsTextInputMode();
	virtual bool __fastcall IsValidChar(System::WideChar AChar);
	virtual void __fastcall PropertiesChanged(System::TObject* Sender);
	virtual bool __fastcall SetDisplayText(const System::UnicodeString Value);
	virtual void __fastcall SetInternalDisplayValue(const System::Variant &Value);
	virtual bool __fastcall WantNavigationKeys();
	virtual void __fastcall LockedInnerEditWindowProc(Winapi::Messages::TMessage &Message);
	virtual void __fastcall UnlockInnerEditRepainting();
	virtual void __fastcall UpdateInfoForHiddenInplaceEditor(Cxedit::TcxCustomEditViewData* AViewData, Cxedit::TcxCustomEditViewInfo* AEditViewInfo);
	virtual void __fastcall FormatChanged();
	virtual bool __fastcall CanSpellCheckerPostEditValue();
	virtual void __fastcall DoDrawMisspellings(HDC DC = (HDC)(0x0));
	virtual void __fastcall DoLayoutChanged();
	virtual void __fastcall DoSelectionChanged();
	virtual void __fastcall DoSpellCheckerPostEditValue();
	virtual void __fastcall DoTextChanged();
	void __fastcall InternalCheckSelection();
	virtual void __fastcall InternalSpellCheckerHandler(Winapi::Messages::TMessage &Message);
	void __fastcall RedrawMisspelledWords();
	void __fastcall SpellCheckerPostEditValue();
	virtual void __fastcall SpellCheckerSetSelText(const System::UnicodeString AValue, bool APost = false);
	virtual _di_IcxTextEditLookupData __fastcall GetILookupData();
	virtual bool __fastcall GetScrollLookupDataList(TcxEditScrollCause AScrollCause);
	virtual void __fastcall DoOnNewLookupDisplayText(const System::UnicodeString AText);
	virtual System::Variant __fastcall ItemIndexToLookupKey(int AItemIndex);
	void __fastcall LockLookupDataTextChanged();
	virtual System::Variant __fastcall LookupKeyToEditValue(const System::Variant &AKey);
	virtual int __fastcall LookupKeyToItemIndex(const System::Variant &AKey);
	void __fastcall UnlockLookupDataTextChanged();
	virtual void __fastcall AdjustInnerEdit();
	virtual bool __fastcall CanChangeSelText(const System::UnicodeString Value, /* out */ System::UnicodeString &ANewText, /* out */ int &ANewSelStart);
	virtual bool __fastcall CanSelectItem(bool AFindSelection);
	virtual void __fastcall CheckEditValue();
	virtual void __fastcall CheckEditorValueBounds();
	virtual int __fastcall GetInnerEditHeight();
	virtual int __fastcall GetItemIndex();
	virtual System::TObject* __fastcall GetItemObject();
	virtual void __fastcall HandleSelectItem(System::TObject* Sender);
	virtual System::UnicodeString __fastcall InternalGetText();
	virtual bool __fastcall InternalMouseWheel(System::Classes::TShiftState Shift, int WheelDelta, const System::Types::TPoint &MousePos);
	virtual bool __fastcall InternalSetText(const System::UnicodeString Value);
	virtual bool __fastcall IsMouseWheelHandleNeeded(System::Classes::TShiftState Shift, int WheelDelta, const System::Types::TPoint &MousePos);
	virtual bool __fastcall NeedsInvokeAfterKeyDown(System::Word AKey, System::Classes::TShiftState AShift);
	virtual bool __fastcall NeedResetInvalidTextWhenPropertiesChanged();
	virtual void __fastcall ResetOnNewDisplayValue();
	virtual void __fastcall SelChange(System::TObject* Sender);
	virtual void __fastcall SetEditingText(const Vcl::Controls::TCaption Value);
	virtual void __fastcall SetItemIndex(int Value);
	virtual void __fastcall SetSelText(const Vcl::Controls::TCaption Value);
	virtual void __fastcall SynchronizeDisplayValue();
	virtual void __fastcall SynchronizeEditValue();
	virtual void __fastcall UndoPerformed();
	virtual void __fastcall UpdateDrawValue();
	virtual void __fastcall UpdateDisplayValue();
	virtual void __fastcall DisconnectNonShareableProperties();
	__property bool BeepOnEnter = {read=FBeepOnEnter, write=FBeepOnEnter, default=1};
	__property _di_IcxInnerTextEdit InnerTextEdit = {read=GetInnerTextEdit};
	__property int ItemIndex = {read=GetItemIndex, write=SetItemIndex, stored=false, nodefault};
	__property System::TObject* ItemObject = {read=GetItemObject, write=SetItemObject};
	__property TcxCustomTextEditLookupData* LookupData = {read=GetLookupData};
	__property bool LookupItemsScrolling = {read=FLookupItemsScrolling, write=FLookupItemsScrolling, nodefault};
	__property ParentColor = {default=0};
	__property TcxCustomTextEditViewInfo* ViewInfo = {read=GetViewInfo};
	__property System::UnicodeString TextHint = {read=GetTextHint, write=SetTextHint};
	
public:
	__fastcall virtual TcxCustomTextEdit(System::Classes::TComponent* AOwner)/* overload */;
	__fastcall virtual ~TcxCustomTextEdit();
	virtual void __fastcall DefaultHandler(void *Message);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	virtual void __fastcall CopyToClipboard();
	virtual void __fastcall CutToClipboard();
	virtual bool __fastcall IsEditClass();
	virtual void __fastcall PasteFromClipboard();
	virtual void __fastcall PrepareEditValue(const System::Variant &ADisplayValue, /* out */ System::Variant &AEditValue, bool AEditFocused);
	virtual void __fastcall SelectAll();
	virtual int __fastcall GetTextBaseLine();
	virtual bool __fastcall HasTextBaseLine();
	virtual void __fastcall ClearSelection();
	virtual bool __fastcall IsChildWindow(NativeUInt AWnd);
	virtual void __fastcall SetScrollBarsParameters(bool AIsScrolling = false);
	void __fastcall SetSelection(int ASelStart, int ASelLength);
	virtual void __fastcall Undo();
	__property TcxCustomTextEditProperties* ActiveProperties = {read=GetActiveProperties};
	__property int CursorPos = {read=GetCursorPos, nodefault};
	__property Vcl::Controls::TCaption EditingText = {read=GetEditingText, write=SetEditingText};
	__property bool FindSelection = {read=FFindSelection, write=SetFindSelection, nodefault};
	__property _di_IcxTextEditLookupData ILookupData = {read=GetILookupData};
	__property TcxCustomTextEditProperties* Properties = {read=GetProperties, write=SetProperties};
	__property int SelLength = {read=GetSelLength, write=SetSelLength, nodefault};
	__property int SelStart = {read=GetSelStart, write=SetSelStart, nodefault};
	__property Vcl::Controls::TCaption SelText = {read=GetSelText, write=SetSelText};
	__property Text = {default=0};
	
__published:
	__property ImeMode = {stored=false, default=3};
	__property ImeName = {stored=false, default=0};
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxCustomTextEdit(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxedit::TcxCustomEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomTextEdit(HWND ParentWindow) : Cxedit::TcxCustomEdit(ParentWindow) { }
	
private:
	void *__IcxFormatControllerListener;	// Cxformats::IcxFormatControllerListener 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {A7F2F6D3-1A7D-4295-A6E6-9297BD83D0DE}
	operator Cxformats::_di_IcxFormatControllerListener()
	{
		Cxformats::_di_IcxFormatControllerListener intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Cxformats::IcxFormatControllerListener*(void) { return (Cxformats::IcxFormatControllerListener*)&__IcxFormatControllerListener; }
	#endif
	
};


class PASCALIMPLEMENTATION TcxTextEdit : public TcxCustomTextEdit
{
	typedef TcxCustomTextEdit inherited;
	
private:
	HIDESBASE TcxTextEditProperties* __fastcall GetActiveProperties();
	HIDESBASE TcxTextEditProperties* __fastcall GetProperties();
	HIDESBASE void __fastcall SetProperties(TcxTextEditProperties* Value);
	
protected:
	virtual bool __fastcall SupportsSpelling();
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property TcxTextEditProperties* ActiveProperties = {read=GetActiveProperties};
	
__published:
	__property Anchors = {default=3};
	__property AutoSize = {default=1};
	__property BeepOnEnter = {default=1};
	__property BiDiMode;
	__property Constraints;
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property ParentBiDiMode = {default=1};
	__property ParentColor = {default=0};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property TcxTextEditProperties* Properties = {read=GetProperties, write=SetProperties};
	__property ShowHint;
	__property Style;
	__property StyleDisabled;
	__property StyleFocused;
	__property StyleHot;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Text = {default=0};
	__property TextHint = {default=0};
	__property Visible = {default=1};
	__property OnClick;
	__property OnContextPopup;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEditing;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseDown;
	__property OnMouseEnter;
	__property OnMouseLeave;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TcxCustomTextEdit.Create */ inline __fastcall virtual TcxTextEdit(System::Classes::TComponent* AOwner)/* overload */ : TcxCustomTextEdit(AOwner) { }
	/* TcxCustomTextEdit.Destroy */ inline __fastcall virtual ~TcxTextEdit() { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxTextEdit(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : TcxCustomTextEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxTextEdit(HWND ParentWindow) : TcxCustomTextEdit(ParentWindow) { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFilterTextEditHelper : public Cxfiltercontrolutils::TcxCustomFilterEditHelper
{
	typedef Cxfiltercontrolutils::TcxCustomFilterEditHelper inherited;
	
public:
	__classmethod virtual Cxedit::TcxCustomEditClass __fastcall GetFilterEditClass();
	__classmethod virtual void __fastcall InitializeProperties(Cxedit::TcxCustomEditProperties* AProperties, Cxedit::TcxCustomEditProperties* AEditProperties, bool AHasButtons);
	__classmethod virtual void __fastcall SetFilterValue(Cxedit::TcxCustomEdit* AEdit, Cxedit::TcxCustomEditProperties* AEditProperties, const System::Variant &AValue);
public:
	/* TObject.Create */ inline __fastcall TcxFilterTextEditHelper() : Cxfiltercontrolutils::TcxCustomFilterEditHelper() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxFilterTextEditHelper() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static const System::Int8 cxEditDefaultDropDownPageRowCount = System::Int8(0x8);
static const System::Int8 ekValueOutOfBounds = System::Int8(0x1);
extern DELPHI_PACKAGE Cxedit::TcxEditVertAlignment cxTextEditDefaultVertAlignment;
static const System::WideChar cxTextEditDefaultPasswordChar = (System::WideChar)(0x2a);
extern DELPHI_PACKAGE void __fastcall CheckCharsRegister(System::UnicodeString &AText, System::Uitypes::TEditCharCase ACharCase);
extern DELPHI_PACKAGE bool __fastcall CheckTextEditState(_di_IcxInnerTextEdit ATextEdit, const TcxCustomInnerTextEditPrevState &APrevState);
extern DELPHI_PACKAGE void __fastcall DrawEditText(Cxgraphics::TcxCanvas* ACanvas, TcxCustomTextEditViewInfo* AViewInfo, bool ADrawPasswordCharAsBullet = false);
extern DELPHI_PACKAGE void __fastcall DrawTextEdit(Cxgraphics::TcxCanvas* ACanvas, TcxCustomTextEditViewInfo* AViewInfo);
extern DELPHI_PACKAGE System::Types::TSize __fastcall GetTextEditContentSize(Cxgraphics::TcxCanvas* ACanvas, Cxedit::TcxCustomEditViewData* AViewData, const System::UnicodeString AText, unsigned ADrawTextFlags, const Cxedit::TcxEditSizeProperties &AEditSizeProperties, int ALineCount = 0x0, bool ACorrectWidth = true);
extern DELPHI_PACKAGE void __fastcall InternalTextOut(Vcl::Graphics::TCanvas* ACanvas, TcxCustomTextEditViewInfo* AViewInfo, System::WideChar * AText, System::Types::TRect &R, unsigned AFormat, int ASelStart, int ASelLength, System::Uitypes::TColor ASelBackgroundColor, System::Uitypes::TColor ASelTextColor, int AMaxLineCount = 0x0, int ALeftIndent = 0x0, int ARightIndent = 0x0);
extern DELPHI_PACKAGE void __fastcall InsertThousandSeparator(System::UnicodeString &S);
extern DELPHI_PACKAGE System::UnicodeString __fastcall RemoveExponentialPart(System::UnicodeString &S);
extern DELPHI_PACKAGE void __fastcall RemoveThousandSeparator(System::UnicodeString &S);
extern DELPHI_PACKAGE void __fastcall SaveTextEditState(_di_IcxInnerTextEdit ATextEdit, bool ASaveText, TcxCustomInnerTextEditPrevState &APrevState);
extern DELPHI_PACKAGE void __fastcall SeparateDigitGroups(TcxCustomTextEdit* AEdit);
extern DELPHI_PACKAGE bool __fastcall StrToFloatEx(System::UnicodeString S, double &AValue);
}	/* namespace Cxtextedit */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXTEXTEDIT)
using namespace Cxtextedit;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxtexteditHPP
