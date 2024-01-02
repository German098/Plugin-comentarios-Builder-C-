// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxEdit.pas' rev: 35.00 (Windows)

#ifndef CxeditHPP
#define CxeditHPP

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
#include <System.Variants.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.StdCtrls.hpp>
#include <System.SysUtils.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.ImgList.hpp>
#include <dxCore.hpp>
#include <dxCoreClasses.hpp>
#include <dxMessages.hpp>
#include <dxGDIPlusClasses.hpp>
#include <cxGeometry.hpp>
#include <dxDPIAwareUtils.hpp>
#include <cxClasses.hpp>
#include <cxContainer.hpp>
#include <cxControls.hpp>
#include <cxCustomData.hpp>
#include <dxSpellCheckerCore.hpp>
#include <cxDataStorage.hpp>
#include <cxDataUtils.hpp>
#include <cxGraphics.hpp>
#include <cxLookAndFeels.hpp>
#include <cxVariants.hpp>
#include <dxCustomHint.hpp>
#include <cxLookAndFeelPainters.hpp>
#include <dxFading.hpp>
#include <dxThemeManager.hpp>
#include <dxUxTheme.hpp>
#include <cxEditPaintUtils.hpp>
#include <dxCoreGraphics.hpp>
#include <cxAccessibility.hpp>
#include <System.Actions.hpp>

//-- user supplied -----------------------------------------------------------

namespace Cxedit
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS EcxEditError;
class DELPHICLASS EcxEditValidationError;
__interface DELPHIINTERFACE IcxEditorFieldLink;
typedef System::DelphiInterface<IcxEditorFieldLink> _di_IcxEditorFieldLink;
__interface DELPHIINTERFACE IcxEditorFieldLink2;
typedef System::DelphiInterface<IcxEditorFieldLink2> _di_IcxEditorFieldLink2;
__interface DELPHIINTERFACE IcxCustomInnerEdit;
typedef System::DelphiInterface<IcxCustomInnerEdit> _di_IcxCustomInnerEdit;
__interface DELPHIINTERFACE IcxInnerEditHelper;
typedef System::DelphiInterface<IcxInnerEditHelper> _di_IcxInnerEditHelper;
__interface DELPHIINTERFACE IcxEditOwner;
typedef System::DelphiInterface<IcxEditOwner> _di_IcxEditOwner;
__interface DELPHIINTERFACE IcxInplaceEditIMEHelper;
typedef System::DelphiInterface<IcxInplaceEditIMEHelper> _di_IcxInplaceEditIMEHelper;
__interface DELPHIINTERFACE IcxEditRepositoryItemListener;
typedef System::DelphiInterface<IcxEditRepositoryItemListener> _di_IcxEditRepositoryItemListener;
class DELPHICLASS TcxEditRepositoryItem;
__interface DELPHIINTERFACE IcxEditDefaultValuesProvider;
typedef System::DelphiInterface<IcxEditDefaultValuesProvider> _di_IcxEditDefaultValuesProvider;
class DELPHICLASS TcxEditRepository;
struct TcxEditButtonViewInfoData;
class DELPHICLASS TcxCustomEditFadingHelper;
class DELPHICLASS TcxEditButtonFadingHelper;
class DELPHICLASS TdxEditChildAccessibilityHelper;
class DELPHICLASS TdxEditButtonAccessibilityHelper;
class DELPHICLASS TcxEditButtonViewInfo;
class DELPHICLASS TcxEditButtonActionLink;
class DELPHICLASS TcxCustomEditButton;
class DELPHICLASS TcxEditButton;
class DELPHICLASS TcxCustomEditButtons;
class DELPHICLASS TcxEditButtons;
class DELPHICLASS TcxEditValidateInfo;
class DELPHICLASS TcxCustomEditViewInfo;
struct TcxInplaceEditPosition;
struct TcxInplaceEditParams;
struct TcxEditSizeProperties;
struct TcxEditContentParams;
class DELPHICLASS TcxCustomEditViewData;
class DELPHICLASS TcxEditStyleController;
class DELPHICLASS TcxCustomEditStyle;
class DELPHICLASS TcxEditStyle;
class DELPHICLASS TcxCustomEditPropertiesValues;
class DELPHICLASS TcxCustomEditDefaultValuesProvider;
class DELPHICLASS TcxCustomEditProperties;
class DELPHICLASS TcxDataBinding;
class DELPHICLASS TcxEditDataBinding;
struct TcxEditModifiedState;
class DELPHICLASS TcxCustomEditData;
class DELPHICLASS TcxEditChangeEventsCatcher;
class DELPHICLASS TcxCustomEditContainer;
struct TdxCachedSize;
class DELPHICLASS TdxEditAccessibilityHelper;
class DELPHICLASS TcxCustomEdit;
class DELPHICLASS TcxEditAlignment;
struct TcxEditListItem;
class DELPHICLASS TcxInplaceEditList;
class DELPHICLASS TcxDefaultEditStyleController;
class DELPHICLASS TcxCustomEditingController;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TcxBlobKind : unsigned char { bkNone, bkBlob, bkGraphic, bkMemo, bkOle };

enum DECLSPEC_DENUM TcxEditBorderStyle : unsigned char { ebsNone, ebsSingle, ebsThick, ebsFlat, ebs3D, ebsUltraFlat, ebsOffice11 };

enum DECLSPEC_DENUM TcxEditButtonKind : unsigned char { bkEllipsis, bkDown, bkGlyph, bkText };

enum DECLSPEC_DENUM TcxEditButtonState : unsigned char { ebsDisabled, ebsNormal, ebsPressed, ebsSelected };

enum DECLSPEC_DENUM TcxEditButtonStyle : unsigned char { btsDefault, bts3D, btsFlat, btsSimple, btsHotFlat, btsUltraFlat, btsOffice11 };

enum DECLSPEC_DENUM TcxEditButtonsViewStyle : unsigned char { bvsNormal, bvsButtonsOnly, bvsButtonsAutoWidth };

enum DECLSPEC_DENUM TcxEditButtonTransparency : unsigned char { ebtNone, ebtInactive, ebtAlways, ebtHideInactive, ebtHideUnselected };

typedef Cxclasses::TcxDirection TcxEditGradientDirection;

typedef Cxcontainer::TcxContainerStyleValue TcxEditStyleValue;

typedef Cxcontainer::TcxContainerStyleValues TcxEditStyleValues;

typedef System::Classes::TAlignment TcxEditHorzAlignment;

enum DECLSPEC_DENUM TcxEditVertAlignment : unsigned char { taTopJustify, taBottomJustify, taVCenter };

enum DECLSPEC_DENUM TcxInplaceEditAutoHeight : unsigned char { eahNone, eahEditor, eahRow };

enum DECLSPEC_DENUM TcxItemInplaceEditAutoHeight : unsigned char { ieahDefault, ieahNone };

typedef System::StaticArray<System::UnicodeString, 6> Cxedit__1;

enum DECLSPEC_DENUM TcxEditDisplayFormatOption : unsigned char { dfoSupports, dfoNoCurrencyValue };

typedef System::Set<TcxEditDisplayFormatOption, TcxEditDisplayFormatOption::dfoSupports, TcxEditDisplayFormatOption::dfoNoCurrencyValue> TcxEditDisplayFormatOptions;

enum DECLSPEC_DENUM TcxEditBackgroundPaintingStyle : unsigned char { bpsSolid, bpsComboEdit, bpsComboListEdit };

enum DECLSPEC_DENUM TcxEditEditingStyle : unsigned char { esEdit, esEditList, esFixedList, esNoEdit };

enum DECLSPEC_DENUM TcxEditPaintOption : unsigned char { epoAllowZeroHeight, epoAutoHeight, epoHasExternalBorder, epoShowEndEllipsis, epoShowFocusRectWhenInplace };

typedef System::Set<TcxEditPaintOption, TcxEditPaintOption::epoAllowZeroHeight, TcxEditPaintOption::epoShowFocusRectWhenInplace> TcxEditPaintOptions;

enum DECLSPEC_DENUM Cxedit__2 : unsigned char { esfBlobEditValue, esfMinSize, esfNoContentPart, esfClickable, esfMultiRow };

typedef System::Set<Cxedit__2, Cxedit__2::esfBlobEditValue, Cxedit__2::esfMultiRow> TcxEditSpecialFeatures;

enum DECLSPEC_DENUM TcxEditSupportedOperation : unsigned char { esoAlwaysHotTrack, esoAutoHeight, esoEditing, esoFiltering, esoHorzAlignment, esoHotTrack, esoIncSearch, esoShowingCaption, esoSorting, esoSortingByDisplayText, esoTransparency, esoEditingAutoHeight, esoNeedHandle, esoAutoWidth };

typedef System::Set<TcxEditSupportedOperation, TcxEditSupportedOperation::esoAlwaysHotTrack, TcxEditSupportedOperation::esoAutoWidth> TcxEditSupportedOperations;

typedef System::Variant TcxEditValue;

typedef System::Variant *PcxEditValue;

typedef void __fastcall (__closure *TcxEditValidateEvent)(System::TObject* Sender, System::Variant &DisplayValue, Vcl::Controls::TCaption &ErrorText, bool &Error);

typedef int TcxEditErrorKind;

enum DECLSPEC_DENUM Cxedit__3 : unsigned char { evoRaiseException, evoShowErrorIcon, evoAllowLoseFocus };

typedef System::Set<Cxedit__3, Cxedit__3::evoRaiseException, Cxedit__3::evoAllowLoseFocus> TcxEditValidationOptions;

#pragma pack(push,4)
class PASCALIMPLEMENTATION EcxEditError : public Dxcore::EdxException
{
	typedef Dxcore::EdxException inherited;
	
public:
	/* Exception.Create */ inline __fastcall EcxEditError(const System::UnicodeString Msg) : Dxcore::EdxException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EcxEditError(const System::UnicodeString Msg, const System::TVarRec *Args, const int Args_High) : Dxcore::EdxException(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EcxEditError(NativeUInt Ident)/* overload */ : Dxcore::EdxException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EcxEditError(System::PResStringRec ResStringRec)/* overload */ : Dxcore::EdxException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxEditError(NativeUInt Ident, const System::TVarRec *Args, const int Args_High)/* overload */ : Dxcore::EdxException(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxEditError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const int Args_High)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EcxEditError(const System::UnicodeString Msg, int AHelpContext) : Dxcore::EdxException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EcxEditError(const System::UnicodeString Msg, const System::TVarRec *Args, const int Args_High, int AHelpContext) : Dxcore::EdxException(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxEditError(NativeUInt Ident, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxEditError(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxEditError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const int Args_High, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxEditError(NativeUInt Ident, const System::TVarRec *Args, const int Args_High, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EcxEditError() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION EcxEditValidationError : public EcxEditError
{
	typedef EcxEditError inherited;
	
public:
	/* Exception.Create */ inline __fastcall EcxEditValidationError(const System::UnicodeString Msg) : EcxEditError(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EcxEditValidationError(const System::UnicodeString Msg, const System::TVarRec *Args, const int Args_High) : EcxEditError(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EcxEditValidationError(NativeUInt Ident)/* overload */ : EcxEditError(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EcxEditValidationError(System::PResStringRec ResStringRec)/* overload */ : EcxEditError(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxEditValidationError(NativeUInt Ident, const System::TVarRec *Args, const int Args_High)/* overload */ : EcxEditError(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxEditValidationError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const int Args_High)/* overload */ : EcxEditError(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EcxEditValidationError(const System::UnicodeString Msg, int AHelpContext) : EcxEditError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EcxEditValidationError(const System::UnicodeString Msg, const System::TVarRec *Args, const int Args_High, int AHelpContext) : EcxEditError(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxEditValidationError(NativeUInt Ident, int AHelpContext)/* overload */ : EcxEditError(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxEditValidationError(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : EcxEditError(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxEditValidationError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const int Args_High, int AHelpContext)/* overload */ : EcxEditError(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxEditValidationError(NativeUInt Ident, const System::TVarRec *Args, const int Args_High, int AHelpContext)/* overload */ : EcxEditError(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EcxEditValidationError() { }
	
};

#pragma pack(pop)

__interface  INTERFACE_UUID("{E21A0DDE-85DF-42CC-9063-D9E5DF45F02F}") IcxEditorFieldLink  : public System::IInterface 
{
	virtual bool __fastcall CreateFieldControls(int X, int Y, System::TObject* ADataSource, System::Classes::TList* AFieldList) = 0 ;
};

__interface  INTERFACE_UUID("{4A1B4837-FF36-4408-AF91-D195D16F2BA0}") IcxEditorFieldLink2  : public IcxEditorFieldLink 
{
	virtual void __fastcall DoCreateFieldControl(Vcl::Controls::TControl* AControl, System::TObject* AField) = 0 ;
	virtual bool __fastcall NeedCreateCaption() = 0 ;
};

__interface  INTERFACE_UUID("{468D21B5-48AA-4077-8ED5-4C6112D460B1}") IcxCustomInnerEdit  : public Cxcontainer::IcxContainerInnerControl 
{
	virtual NativeInt __fastcall CallDefWndProc(unsigned AMsg, NativeUInt WParam, NativeInt LParam) = 0 ;
	virtual bool __fastcall CanProcessClipboardMessages() = 0 ;
	virtual System::Variant __fastcall GetEditValue() = 0 ;
	virtual Cxaccessibility::_di_IcxAccessibilityHelper __fastcall GetIAccessibilityHelper() = 0 ;
	virtual System::Classes::TNotifyEvent __fastcall GetOnChange() = 0 ;
	virtual bool __fastcall GetReadOnly() = 0 ;
	virtual void __fastcall LockBounds(bool ALock) = 0 ;
	virtual void __fastcall SafelySetFocus() = 0 ;
	virtual void __fastcall SetEditValue(const System::Variant &Value) = 0 ;
	virtual void __fastcall SetParent(Vcl::Controls::TWinControl* Value) = 0 ;
	virtual void __fastcall SetOnChange(System::Classes::TNotifyEvent Value) = 0 ;
	virtual void __fastcall SetReadOnly(bool Value) = 0 ;
	__property System::Variant EditValue = {read=GetEditValue, write=SetEditValue};
	__property Vcl::Controls::TWinControl* Parent = {write=SetParent};
	__property bool ReadOnly = {read=GetReadOnly, write=SetReadOnly};
	__property System::Classes::TNotifyEvent OnChange = {read=GetOnChange, write=SetOnChange};
};

__interface  INTERFACE_UUID("{35667555-6DC8-40D5-B705-B08D5697C621}") IcxInnerEditHelper  : public System::IInterface 
{
	virtual _di_IcxCustomInnerEdit __fastcall GetHelper() = 0 ;
};

__interface  INTERFACE_UUID("{4129100C-7FC6-436E-8711-47A5C978CA73}") IcxEditOwner  : public System::IInterface 
{
	virtual TcxCustomEditViewData* __fastcall GetViewData(/* out */ bool &AIsViewDataCreated) = 0 ;
	virtual void __fastcall Invalidate(const System::Types::TRect &R, bool AEraseBackground) = 0 ;
};

__interface  INTERFACE_UUID("{DC5EF4E1-2847-4950-854A-F8BFE29706F5}") IcxInplaceEditIMEHelper  : public System::IInterface 
{
	virtual void __fastcall IMEComposition(Winapi::Messages::TMessage &AMessage) = 0 ;
	virtual void __fastcall IMEStartComposition() = 0 ;
};

typedef System::TMetaClass* TcxCustomEditPropertiesClass;

__interface  INTERFACE_UUID("{4E27D642-022B-4CD2-AB96-64C7CF9B3299}") IcxEditRepositoryItemListener  : public System::IInterface 
{
	virtual void __fastcall ItemRemoved(TcxEditRepositoryItem* Sender) = 0 ;
	virtual void __fastcall PropertiesChanged(TcxEditRepositoryItem* Sender) = 0 ;
};

class PASCALIMPLEMENTATION TcxEditRepositoryItem : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	System::Classes::_di_IInterfaceList FListenerList;
	TcxCustomEditProperties* FProperties;
	System::Classes::TNotifyEvent FPropertiesEvents;
	TcxEditRepository* FRepository;
	Cxgeometry::TdxOwnedScaleFactor* FScaleFactor;
	void __fastcall SetProperties(TcxCustomEditProperties* Value);
	void __fastcall SetRepository(TcxEditRepository* Value);
	
protected:
	bool __fastcall ArePropertiesCompatible(System::TClass APropertiesClass);
	virtual void __fastcall PropertiesChanged(System::TObject* Sender);
	virtual void __fastcall ReadState(System::Classes::TReader* Reader);
	Cxgeometry::TdxScaleFactor* __fastcall GetScaleFactor();
	
public:
	__fastcall virtual TcxEditRepositoryItem(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxEditRepositoryItem();
	virtual void __fastcall AddListener(_di_IcxEditRepositoryItemListener AListener);
	__classmethod virtual TcxCustomEditPropertiesClass __fastcall GetEditPropertiesClass();
	virtual System::UnicodeString __fastcall GetBaseName();
	DYNAMIC System::Classes::TComponent* __fastcall GetParentComponent();
	DYNAMIC bool __fastcall HasParent();
	virtual void __fastcall RemoveListener(_di_IcxEditRepositoryItemListener AListener);
	DYNAMIC void __fastcall SetParentComponent(System::Classes::TComponent* AParent);
	__property TcxCustomEditProperties* Properties = {read=FProperties, write=SetProperties};
	__property TcxEditRepository* Repository = {read=FRepository, write=SetRepository};
	
__published:
	__property System::Classes::TNotifyEvent PropertiesEvents = {read=FPropertiesEvents, write=FPropertiesEvents};
private:
	void *__IdxScaleFactor;	// Cxgeometry::IdxScaleFactor 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {367A805A-A84B-441A-83A3-6A7E489D3B6C}
	operator Cxgeometry::_di_IdxScaleFactor()
	{
		Cxgeometry::_di_IdxScaleFactor intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Cxgeometry::IdxScaleFactor*(void) { return (Cxgeometry::IdxScaleFactor*)&__IdxScaleFactor; }
	#endif
	
};


typedef System::TMetaClass* TcxEditRepositoryItemClass;

__interface  INTERFACE_UUID("{AE727882-6FDF-4E3A-AB35-E58AB28EFE7B}") IcxEditDefaultValuesProvider  : public System::IInterface 
{
	virtual bool __fastcall CanSetEditMode() = 0 ;
	virtual void __fastcall ClearUsers() = 0 ;
	virtual System::Classes::TAlignment __fastcall DefaultAlignment() = 0 ;
	virtual TcxBlobKind __fastcall DefaultBlobKind() = 0 ;
	virtual bool __fastcall DefaultCanModify() = 0 ;
	virtual System::UnicodeString __fastcall DefaultDisplayFormat() = 0 ;
	virtual System::UnicodeString __fastcall DefaultEditFormat() = 0 ;
	virtual System::UnicodeString __fastcall DefaultEditMask() = 0 ;
	virtual bool __fastcall DefaultIsFloatValue() = 0 ;
	virtual int __fastcall DefaultMaxLength() = 0 ;
	virtual double __fastcall DefaultMaxValue() = 0 ;
	virtual double __fastcall DefaultMinValue() = 0 ;
	virtual int __fastcall DefaultPrecision() = 0 ;
	virtual bool __fastcall DefaultReadOnly() = 0 ;
	virtual bool __fastcall DefaultRequired() = 0 ;
	virtual System::TObject* __fastcall GetInstance() = 0 ;
	virtual bool __fastcall IsDataStorage() = 0 ;
	virtual bool __fastcall IsBlob() = 0 ;
	virtual bool __fastcall IsCurrency() = 0 ;
	virtual bool __fastcall IsDataAvailable() = 0 ;
	virtual bool __fastcall IsDisplayFormatDefined(bool AIsCurrencyValueAccepted) = 0 ;
	virtual bool __fastcall IsOnGetTextAssigned() = 0 ;
	virtual bool __fastcall IsOnSetTextAssigned() = 0 ;
	virtual bool __fastcall IsValidChar(System::WideChar AChar) = 0 ;
};

class PASCALIMPLEMENTATION TcxEditRepository : public Cxclasses::TcxScalableComponent
{
	typedef Cxclasses::TcxScalableComponent inherited;
	
public:
	TcxEditRepositoryItem* operator[](int Index) { return this->Items[Index]; }
	
private:
	System::Classes::TList* FItems;
	int __fastcall GetCount();
	TcxEditRepositoryItem* __fastcall GetItem(int Index);
	
protected:
	void __fastcall AddItem(TcxEditRepositoryItem* AItem);
	DYNAMIC void __fastcall GetChildren(System::Classes::TGetChildProc Proc, System::Classes::TComponent* Root);
	void __fastcall RemoveItem(TcxEditRepositoryItem* AItem);
	
public:
	__fastcall virtual TcxEditRepository(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxEditRepository();
	void __fastcall Clear();
	virtual TcxEditRepositoryItem* __fastcall CreateItem(TcxEditRepositoryItemClass ARepositoryItemClass);
	virtual TcxEditRepositoryItem* __fastcall CreateItemEx(TcxEditRepositoryItemClass ARepositoryItemClass, System::Classes::TComponent* AOwner);
	TcxEditRepositoryItem* __fastcall ItemByName(const System::UnicodeString ARepositoryItemName);
	void __fastcall RemoveItems(TcxEditRepositoryItemClass AItemClass);
	__property int Count = {read=GetCount, nodefault};
	__property TcxEditRepositoryItem* Items[int Index] = {read=GetItem/*, default*/};
};


typedef TcxEditButtonViewInfoData *PcxEditButtonViewInfoData;

struct DECLSPEC_DRECORD TcxEditButtonViewInfoData
{
public:
	Vcl::Actnlist::TActionLink* ActionLink;
	System::Uitypes::TColor BackgroundColor;
	System::UnicodeString Caption;
	System::Classes::TAlignment ContentAlignment;
	bool Default;
	bool Gradient;
	System::UnicodeString Hint;
	bool IsInplace;
	TcxEditButtonKind Kind;
	bool LeftAlignment;
	bool Leftmost;
	bool NativeStyle;
	bool Rightmost;
	TcxEditButtonState State;
	TcxEditButtonStyle Style;
	System::Uitypes::TColor TextColor;
	bool Transparent;
	System::UnicodeString VisibleCaption;
	bool BackgroundPartiallyTransparent;
	bool ComboBoxStyle;
	int NativePart;
	int NativeState;
	bool UseSkins;
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomEditFadingHelper : public Dxfading::TdxFadingObjectHelper
{
	typedef Dxfading::TdxFadingObjectHelper inherited;
	
private:
	_di_IcxEditOwner __fastcall GetEditOwner();
	
protected:
	virtual bool __fastcall CanFade();
	virtual TcxCustomEditViewInfo* __fastcall GetEditViewInfo() = 0 ;
	virtual void __fastcall DrawFadeImage();
	
public:
	virtual void __fastcall Invalidate() = 0 /* overload */;
	void __fastcall Invalidate(const System::Types::TRect &R, bool AEraseBackground)/* overload */;
	__property _di_IcxEditOwner EditOwner = {read=GetEditOwner};
	__property TcxCustomEditViewInfo* EditViewInfo = {read=GetEditViewInfo};
public:
	/* TdxFadingObjectHelper.Destroy */ inline __fastcall virtual ~TcxCustomEditFadingHelper() { }
	
public:
	/* TObject.Create */ inline __fastcall TcxCustomEditFadingHelper() : Dxfading::TdxFadingObjectHelper() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxEditButtonFadingHelper : public TcxCustomEditFadingHelper
{
	typedef TcxCustomEditFadingHelper inherited;
	
private:
	TcxEditButtonState FState;
	TcxEditButtonViewInfo* FViewInfo;
	
protected:
	virtual bool __fastcall CanFade();
	virtual void __fastcall DrawButton(Cxgraphics::TcxCanvas* ACanvas);
	virtual System::Types::TRect __fastcall GetButtonRect();
	virtual TcxCustomEditViewInfo* __fastcall GetEditViewInfo();
	virtual void __fastcall GetFadingImages(/* out */ Cxgraphics::TcxBitmap* &AFadeOutImage, /* out */ Cxgraphics::TcxBitmap* &AFadeInImage);
	virtual Cxgraphics::TcxBitmap32* __fastcall PrepareFadingImage(TcxEditButtonState AState);
	
public:
	__fastcall virtual TcxEditButtonFadingHelper(TcxEditButtonViewInfo* AViewInfo);
	virtual void __fastcall Invalidate()/* overload */;
	virtual void __fastcall UpdateState();
	__property System::Types::TRect ButtonRect = {read=GetButtonRect};
	__property TcxEditButtonState State = {read=FState, nodefault};
	__property TcxEditButtonViewInfo* ViewInfo = {read=FViewInfo};
public:
	/* TdxFadingObjectHelper.Destroy */ inline __fastcall virtual ~TcxEditButtonFadingHelper() { }
	
	/* Hoisted overloads: */
	
public:
	inline void __fastcall  Invalidate(const System::Types::TRect &R, bool AEraseBackground){ TcxCustomEditFadingHelper::Invalidate(R, AEraseBackground); }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxEditChildAccessibilityHelper : public Cxaccessibility::TcxAccessibilityHelper
{
	typedef Cxaccessibility::TcxAccessibilityHelper inherited;
	
protected:
	int FLocalId;
	virtual int __fastcall GetLocalId(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID = (Cxaccessibility::TcxAccessibleSimpleChildElementID)(0x0));
public:
	/* TcxAccessibilityHelper.Create */ inline __fastcall virtual TdxEditChildAccessibilityHelper(System::TObject* AOwnerObject) : Cxaccessibility::TcxAccessibilityHelper(AOwnerObject) { }
	/* TcxAccessibilityHelper.Destroy */ inline __fastcall virtual ~TdxEditChildAccessibilityHelper() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxEditButtonAccessibilityHelper : public TdxEditChildAccessibilityHelper
{
	typedef TdxEditChildAccessibilityHelper inherited;
	
private:
	TcxEditButtonViewInfo* __fastcall GetEditButtonViewInfo();
	
protected:
	virtual void __fastcall DoDefaultAction(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
	virtual System::UnicodeString __fastcall GetDefaultActionDescription(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
	virtual System::UnicodeString __fastcall GetName(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
	virtual Cxaccessibility::TcxAccessibilityHelper* __fastcall GetParent();
	virtual int __fastcall GetRole(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
	virtual int __fastcall GetState(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
	virtual Cxaccessibility::TcxAccessibleObjectProperties __fastcall GetSupportedProperties(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
	virtual bool __fastcall IsExtended();
	__property TcxEditButtonViewInfo* EditButtonViewInfo = {read=GetEditButtonViewInfo};
	
public:
	virtual System::Types::TRect __fastcall GetScreenBounds(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
public:
	/* TcxAccessibilityHelper.Create */ inline __fastcall virtual TdxEditButtonAccessibilityHelper(System::TObject* AOwnerObject) : TdxEditChildAccessibilityHelper(AOwnerObject) { }
	/* TcxAccessibilityHelper.Destroy */ inline __fastcall virtual ~TdxEditButtonAccessibilityHelper() { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxEditButtonViewInfoClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxEditButtonViewInfo : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	Cxaccessibility::_di_IcxAccessibilityHelper FIAccessibilityHelper;
	Cxaccessibility::_di_IcxAccessibilityHelper __fastcall GetIAccessibilityHelper();
	Cxgeometry::TdxScaleFactor* __fastcall GetScaleFactor();
	
protected:
	virtual TcxEditButtonFadingHelper* __fastcall CreateFadingHelper();
	__property Cxaccessibility::_di_IcxAccessibilityHelper IAccessibilityHelper = {read=GetIAccessibilityHelper};
	
public:
	System::Types::TRect Bounds;
	int ButtonIndex;
	int ButtonVisibleIndex;
	TcxEditButtonViewInfoData Data;
	TcxCustomEditViewInfo* EditViewInfo;
	TcxEditButtonFadingHelper* FadingHelper;
	Dxgdiplusclasses::TdxSmartGlyph* Glyph;
	bool HasBackground;
	System::Uitypes::TImageIndex ImageIndex;
	Vcl::Imglist::TCustomImageList* Images;
	bool Stretchable;
	System::Types::TRect VisibleBounds;
	int Width;
	__fastcall virtual ~TcxEditButtonViewInfo();
	virtual void __fastcall AfterConstruction();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual Cxgraphics::TcxRegion* __fastcall GetUpdateRegion(TcxEditButtonViewInfo* AViewInfo);
	virtual bool __fastcall Repaint(Vcl::Controls::TWinControl* AControl, TcxEditButtonViewInfo* AViewInfo, const System::Types::TPoint &AEditPosition);
	__property Cxgeometry::TdxScaleFactor* ScaleFactor = {read=GetScaleFactor};
public:
	/* TObject.Create */ inline __fastcall TcxEditButtonViewInfo() : System::Classes::TPersistent() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxEditButtonActionLink : public Vcl::Actnlist::TActionLink
{
	typedef Vcl::Actnlist::TActionLink inherited;
	
protected:
	TcxCustomEditButton* FClient;
	virtual void __fastcall AssignClient(System::TObject* AClient);
	virtual bool __fastcall IsCaptionLinked();
	virtual bool __fastcall IsEnabledLinked();
	virtual bool __fastcall IsImageIndexLinked();
	virtual bool __fastcall IsHintLinked();
	virtual bool __fastcall IsVisibleLinked();
	virtual void __fastcall SetCaption(const System::UnicodeString Value);
	virtual void __fastcall SetEnabled(bool Value);
	virtual void __fastcall SetImageIndex(int Value);
	virtual void __fastcall SetHint(const System::UnicodeString Value);
	virtual void __fastcall SetVisible(bool Value);
	
public:
	virtual bool __fastcall PrepareHint(System::UnicodeString &HintStr);
public:
	/* TBasicActionLink.Create */ inline __fastcall virtual TcxEditButtonActionLink(System::TObject* AClient) : Vcl::Actnlist::TActionLink(AClient) { }
	/* TBasicActionLink.Destroy */ inline __fastcall virtual ~TcxEditButtonActionLink() { }
	
};


typedef System::TMetaClass* TcxEditButtonActionLinkClass;

typedef System::TMetaClass* TcxEditButtonClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomEditButton : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	TcxEditButtonActionLink* FActionLink;
	Vcl::Controls::TCaption FCaption;
	System::Classes::TAlignment FContentAlignment;
	bool FDefault;
	bool FEnabled;
	Dxgdiplusclasses::TdxSmartGlyph* FGlyph;
	System::UnicodeString FHint;
	System::Uitypes::TImageIndex FImageIndex;
	TcxEditButtonKind FKind;
	bool FLeftAlignment;
	bool FStretchable;
	NativeInt FTag;
	System::Uitypes::TColor FTextColor;
	bool FVisible;
	Vcl::Controls::TCaption FVisibleCaption;
	int FWidth;
	DYNAMIC void __fastcall ActionChange(System::TObject* Sender, bool CheckDefaults);
	void __fastcall DoActionChange(System::TObject* Sender);
	TcxCustomEditButtons* __fastcall GetCollection();
	void __fastcall GlyphChanged(System::TObject* Sender);
	bool __fastcall IsCaptionStored();
	bool __fastcall IsEnabledStored();
	bool __fastcall IsHintStored();
	bool __fastcall IsImageIndexStored();
	bool __fastcall IsTagStored();
	bool __fastcall IsVisibleStored();
	void __fastcall SetAction(System::Classes::TBasicAction* Value);
	void __fastcall SetCaption(const Vcl::Controls::TCaption Value);
	void __fastcall SetContentAlignment(System::Classes::TAlignment Value);
	void __fastcall SetDefault(bool Value);
	void __fastcall SetEnabled(bool Value);
	void __fastcall SetGlyph(Dxgdiplusclasses::TdxSmartGlyph* Value);
	void __fastcall SetImageIndex(System::Uitypes::TImageIndex Value);
	void __fastcall SetKind(TcxEditButtonKind Value);
	void __fastcall SetLeftAlignment(bool Value);
	void __fastcall SetStretchable(bool Value);
	void __fastcall SetTextColor(System::Uitypes::TColor Value);
	void __fastcall SetVisible(bool Value);
	void __fastcall SetWidth(int Value);
	
protected:
	virtual void __fastcall ChangeScale(int M, int D);
	virtual void __fastcall FreeNotification(System::Classes::TComponent* Sender);
	virtual System::Classes::TBasicAction* __fastcall GetAction();
	virtual TcxEditButtonActionLinkClass __fastcall GetActionLinkClass();
	virtual void __fastcall InitiateAction();
	__property System::Classes::TBasicAction* Action = {read=GetAction, write=SetAction};
	__property TcxEditButtonActionLink* ActionLink = {read=FActionLink};
	__property Vcl::Controls::TCaption Caption = {read=FCaption, write=SetCaption, stored=IsCaptionStored};
	__property TcxCustomEditButtons* Collection = {read=GetCollection};
	__property System::Classes::TAlignment ContentAlignment = {read=FContentAlignment, write=SetContentAlignment, default=2};
	__property bool Default = {read=FDefault, write=SetDefault, default=0};
	__property bool Enabled = {read=FEnabled, write=SetEnabled, stored=IsEnabledStored, default=1};
	__property Dxgdiplusclasses::TdxSmartGlyph* Glyph = {read=FGlyph, write=SetGlyph};
	__property System::UnicodeString Hint = {read=FHint, write=FHint, stored=IsHintStored};
	__property System::Uitypes::TImageIndex ImageIndex = {read=FImageIndex, write=SetImageIndex, stored=IsImageIndexStored, default=-1};
	__property TcxEditButtonKind Kind = {read=FKind, write=SetKind, default=1};
	__property bool LeftAlignment = {read=FLeftAlignment, write=SetLeftAlignment, default=0};
	__property bool Stretchable = {read=FStretchable, write=SetStretchable, default=1};
	__property NativeInt Tag = {read=FTag, write=FTag, stored=IsTagStored, nodefault};
	__property System::Uitypes::TColor TextColor = {read=FTextColor, write=SetTextColor, default=-16777198};
	__property bool Visible = {read=FVisible, write=SetVisible, stored=IsVisibleStored, default=1};
	__property Vcl::Controls::TCaption VisibleCaption = {read=FVisibleCaption};
	__property int Width = {read=FWidth, write=SetWidth, default=0};
	
public:
	__fastcall virtual TcxCustomEditButton(System::Classes::TCollection* Collection);
	__fastcall virtual ~TcxCustomEditButton();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxEditButton : public TcxCustomEditButton
{
	typedef TcxCustomEditButton inherited;
	
__published:
	__property Action;
	__property Caption = {default=0};
	__property ContentAlignment = {default=2};
	__property Default = {default=0};
	__property Enabled = {default=1};
	__property ImageIndex = {default=-1};
	__property Glyph;
	__property Hint = {default=0};
	__property Kind = {default=1};
	__property LeftAlignment = {default=0};
	__property Stretchable = {default=1};
	__property Tag;
	__property Visible = {default=1};
	__property Width = {default=0};
public:
	/* TcxCustomEditButton.Create */ inline __fastcall virtual TcxEditButton(System::Classes::TCollection* Collection) : TcxCustomEditButton(Collection) { }
	/* TcxCustomEditButton.Destroy */ inline __fastcall virtual ~TcxEditButton() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxCustomEditButtons : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	TcxCustomEditButton* operator[](int Index) { return this->Items[Index]; }
	
private:
	Dxcoreclasses::TcxFreeNotificator* FFreeNotificator;
	System::Classes::TPersistent* FOwner;
	Vcl::Imglist::TCustomImageList* FImages;
	System::Classes::TNotifyEvent FOnChange;
	HIDESBASE TcxCustomEditButton* __fastcall GetItem(int Index);
	Dxcoreclasses::TcxFreeNotificator* __fastcall GetFreeNotificator();
	int __fastcall GetVisibleCount();
	HIDESBASE void __fastcall SetItem(int Index, TcxCustomEditButton* Value);
	
protected:
	void __fastcall AddFreeNotificatorSender(System::Classes::TComponent* Sender);
	virtual void __fastcall ChangeScale(int M, int D);
	virtual void __fastcall DoFreeNotification(System::Classes::TComponent* Sender);
	__classmethod virtual TcxEditButtonClass __fastcall GetButtonClass();
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner();
	virtual void __fastcall InitiateActions();
	void __fastcall RemoveFreeNotificatorSender(System::Classes::TComponent* Sender);
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	__property Dxcoreclasses::TcxFreeNotificator* FreeNotificator = {read=GetFreeNotificator};
	__property Vcl::Imglist::TCustomImageList* Images = {read=FImages, write=FImages};
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	
public:
	__fastcall virtual TcxCustomEditButtons(System::Classes::TPersistent* AOwner, TcxEditButtonClass AButtonClass);
	__fastcall virtual ~TcxCustomEditButtons();
	__property TcxCustomEditButton* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
	__property int VisibleCount = {read=GetVisibleCount, nodefault};
};


class PASCALIMPLEMENTATION TcxEditButtons : public TcxCustomEditButtons
{
	typedef TcxCustomEditButtons inherited;
	
public:
	TcxEditButton* operator[](int Index) { return this->Items[Index]; }
	
private:
	HIDESBASE TcxEditButton* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TcxEditButton* Value);
	
protected:
	__classmethod virtual TcxEditButtonClass __fastcall GetButtonClass();
	
public:
	HIDESBASE TcxEditButton* __fastcall Add();
	__property TcxEditButton* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TcxCustomEditButtons.Create */ inline __fastcall virtual TcxEditButtons(System::Classes::TPersistent* AOwner, TcxEditButtonClass AButtonClass) : TcxCustomEditButtons(AOwner, AButtonClass) { }
	/* TcxCustomEditButtons.Destroy */ inline __fastcall virtual ~TcxEditButtons() { }
	
};


typedef System::TMetaClass* TcxEditButtonsClass;

typedef void __fastcall (__closure *TcxEditCanStartButtonFadingEvent)(TcxCustomEditViewInfo* Sender, bool &ACanStart);

typedef void __fastcall (__closure *TcxEditDrawBackgroundEvent)(TcxCustomEditViewInfo* Sender, Cxgraphics::TcxCanvas* ACanvas, bool &AHandled);

typedef void __fastcall (__closure *TcxEditDrawButtonEvent)(TcxEditButtonViewInfo* Sender, Cxgraphics::TcxCanvas* ACanvas, bool &AHandled);

typedef void __fastcall (__closure *TcxEditDrawButtonBackgroundEvent)(TcxEditButtonViewInfo* Sender, Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool &AHandled);

typedef void __fastcall (__closure *TcxEditDrawButtonBorderEvent)(TcxEditButtonViewInfo* Sender, Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &ABackgroundRect, System::Types::TRect &AContentRect, bool &AHandled);

typedef void __fastcall (__closure *TcxEditGetButtonContentColorEvent)(TcxEditButtonViewInfo* Sender, System::Uitypes::TColor &AColor);

typedef void __fastcall (__closure *TcxEditGetButtonStateEvent)(TcxEditButtonViewInfo* Sender, TcxEditButtonState &AState);

typedef void __fastcall (__closure *TcxEditPaintEvent)(TcxCustomEditViewInfo* Sender, Cxgraphics::TcxCanvas* ACanvas);

typedef void __fastcall (__closure *TcxEditPrepareButtonFadingImageEvent)(TcxEditButtonViewInfo* ASender, TcxEditButtonState AState, /* out */ Cxgraphics::TcxBitmap32* &AImage, bool &AHandled);

enum DECLSPEC_DENUM TcxDrawBackgroundStyle : unsigned char { dbsCustom, dbsCustomEdit, dbsNone, dbsSimpleFill, dbsSimpleParent, dbsThemeParent };

enum DECLSPEC_DENUM TcxEditViewInfoState : unsigned char { evsPaintButtons };

typedef System::Set<TcxEditViewInfoState, TcxEditViewInfoState::evsPaintButtons, TcxEditViewInfoState::evsPaintButtons> TcxEditViewInfoStates;

enum DECLSPEC_DENUM TcxEditErrorType : unsigned char { eetNone, eetError, eetWarning, eetInfo, eetCustom };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxEditValidateInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Dxgdiplusclasses::TdxSmartGlyph* FErrorIcon;
	System::UnicodeString FErrorText;
	TcxEditErrorType FErrorType;
	Dxgdiplusclasses::TdxSmartGlyph* __fastcall GetErrorIcon();
	void __fastcall SetErrorType(TcxEditErrorType AValue);
	void __fastcall SetErrorIcon(Dxgdiplusclasses::TdxSmartGlyph* AValue);
	
public:
	__fastcall virtual ~TcxEditValidateInfo();
	bool __fastcall HasErrorIcon();
	bool __fastcall IsError();
	void __fastcall Reset();
	__property Dxgdiplusclasses::TdxSmartGlyph* ErrorIcon = {read=GetErrorIcon, write=SetErrorIcon};
	__property System::UnicodeString ErrorText = {read=FErrorText, write=FErrorText};
	__property TcxEditErrorType ErrorType = {read=FErrorType, write=SetErrorType, nodefault};
public:
	/* TObject.Create */ inline __fastcall TcxEditValidateInfo() : System::TObject() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxCustomEditViewInfo : public Cxcontainer::TcxContainerViewInfo
{
	typedef Cxcontainer::TcxContainerViewInfo inherited;
	
	
private:
	typedef void __fastcall (__closure *TAfterDrawEvent)(TcxCustomEditViewInfo* Sender, Cxgraphics::TcxCanvas* ACanvas);
	
	typedef void __fastcall (__closure *TCanDrawEditValueEvent)(TcxCustomEditViewInfo* Sender, bool &Allow);
	
	typedef void __fastcall (__closure *TCalculateEditorBoundsEvent)(TcxCustomEditViewInfo* AViewInfo, System::Types::TRect &R);
	
	
private:
	typedef System::DynamicArray<TcxEditButtonViewInfo*> _TcxCustomEditViewInfo__1;
	
	
private:
	bool FReadOnly;
	Cxgeometry::TdxScaleFactor* FScaleFactor;
	TAfterDrawEvent FOnAfterDrawBackground;
	TAfterDrawEvent FOnAfterDrawValue;
	TCalculateEditorBoundsEvent FOnCalculateEditorBounds;
	TCanDrawEditValueEvent FOnCanDrawEditValue;
	TcxEditCanStartButtonFadingEvent FOnCanStartButtonFading;
	TcxEditDrawBackgroundEvent FOnDrawBackground;
	TcxEditDrawButtonEvent FOnDrawButton;
	TcxEditDrawButtonBackgroundEvent FOnDrawButtonBackground;
	TcxEditDrawButtonBorderEvent FOnDrawButtonBorder;
	TcxEditGetButtonContentColorEvent FOnGetButtonContentColor;
	TcxEditGetButtonStateEvent FOnGetButtonState;
	TcxEditPaintEvent FOnPaint;
	TcxEditPrepareButtonFadingImageEvent FOnPrepareButtonFadingImage;
	bool __fastcall DoCanStartButtonFading();
	bool __fastcall DoDrawBackground(Cxgraphics::TcxCanvas* ACanvas);
	bool __fastcall DoDrawButton(Cxgraphics::TcxCanvas* ACanvas, TcxEditButtonViewInfo* AViewInfo);
	bool __fastcall DoDrawButtonBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TcxEditButtonViewInfo* AViewInfo);
	bool __fastcall DoDrawButtonBorder(Cxgraphics::TcxCanvas* ACanvas, TcxEditButtonViewInfo* AViewInfo, System::Types::TRect &ABackgroundRect, System::Types::TRect &AContentRect);
	bool __fastcall DoPrepareButtonFadingImage(TcxEditButtonViewInfo* ASender, TcxEditButtonState AState, /* out */ Cxgraphics::TcxBitmap32* &AImage);
	TcxDrawBackgroundStyle __fastcall GetDrawBackgroundStyle();
	bool __fastcall IsNativeBackground();
	bool __fastcall IsTransparent();
	System::Types::TRect __fastcall GetHintTextRect(const System::Types::TPoint &P, int APart);
	
protected:
	TcxCustomEdit* FEdit;
	TcxEditViewInfoStates FState;
	System::Types::TRect FErrorBounds;
	System::Types::TRect FEditorBounds;
	TcxEditValidateInfo* FErrorData;
	bool FNeedShowErrorIcon;
	virtual System::Uitypes::TColor __fastcall CalculateBackgroundColor(Cxcontainer::TcxContainerStyle* AStyle, bool AEnabled, Cxcontainer::TcxContainer* AContainer = (Cxcontainer::TcxContainer*)(0x0));
	virtual System::Uitypes::TCursor __fastcall GetCurrentCursor(const System::Types::TPoint &AMousePos);
	virtual void __fastcall InplaceMouseDown(System::Uitypes::TMouseButton AButton, const System::Classes::TShiftState AShift, int X, int Y);
	virtual TcxEditBackgroundPaintingStyle __fastcall GetBackgroundPaintingStyle();
	Dxcoregraphics::_di_IdxColorPalette __fastcall GetButtonColorPalette(TcxEditButtonState AState);
	virtual TcxEditButtonViewInfoClass __fastcall GetButtonViewInfoClass();
	virtual Cxlookandfeelpainters::TcxContainerBorderStyle __fastcall GetContainerBorderStyle();
	bool __fastcall GetHasButtonsStateChanges();
	virtual System::UnicodeString __fastcall GetHintText(int APart);
	virtual int __fastcall GetPart(const System::Types::TPoint &P);
	virtual System::Types::TRect __fastcall GetPartRect(int APart);
	bool __fastcall HasNonClientArea();
	virtual void __fastcall InternalPaint(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall InternalPrepareEditButtonBackground(Cxgraphics::TcxCanvas* ACanvas, TcxEditButtonViewInfo* AViewInfo, /* out */ System::Types::TRect &AContentRect, /* out */ System::Types::TRect &ABackgroundRect, /* out */ System::Uitypes::TColor &APenColor, /* out */ System::Uitypes::TColor &ABrushColor, bool ACalculateOnly);
	virtual bool __fastcall IsRepaintOnStateChangingNeeded();
	virtual void __fastcall DrawEditButton(Cxgraphics::TcxCanvas* ACanvas, int AButtonVisibleIndex);
	virtual void __fastcall SetOnDrawBackground(TcxEditDrawBackgroundEvent AValue);
	virtual void __fastcall StoreLastState();
	void __fastcall DoAfterDrawBackground(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall DoAfterDrawValue(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall Draw3DButtonBorder(Cxgraphics::TcxCanvas* ACanvas, TcxEditButtonViewInfo* AButtonViewInfo, System::Types::TRect &ARect, /* out */ System::Types::TRect &AContentRect, System::Uitypes::TColor &APenColor, System::Uitypes::TColor &ABrushColor);
	virtual void __fastcall DrawComplexFrameEx(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &ARect, System::Uitypes::TColor ALeftTopColor, System::Uitypes::TColor ARightBottomColor);
	virtual void __fastcall DrawFlatButtonBorder(Cxgraphics::TcxCanvas* ACanvas, TcxEditButtonViewInfo* AButtonViewInfo, System::Types::TRect &ARect, /* out */ System::Types::TRect &AContentRect, System::Uitypes::TColor &APenColor, System::Uitypes::TColor &ABrushColor);
	virtual void __fastcall DrawHotFlatButtonBorder(Cxgraphics::TcxCanvas* ACanvas, TcxEditButtonViewInfo* AButtonViewInfo, System::Types::TRect &ARect, /* out */ System::Types::TRect &AContentRect, System::Uitypes::TColor &APenColor, System::Uitypes::TColor &ABrushColor);
	virtual void __fastcall DrawNativeButtonBorder(Cxgraphics::TcxCanvas* ACanvas, TcxEditButtonViewInfo* AButtonViewInfo, System::Types::TRect &ARect, /* out */ System::Types::TRect &AContentRect, System::Uitypes::TColor &APenColor, System::Uitypes::TColor &ABrushColor);
	virtual void __fastcall DrawSimpleButtonBorder(Cxgraphics::TcxCanvas* ACanvas, TcxEditButtonViewInfo* AButtonViewInfo, System::Types::TRect &ARect, /* out */ System::Types::TRect &AContentRect, System::Uitypes::TColor &APenColor, System::Uitypes::TColor &ABrushColor);
	virtual void __fastcall DrawUltraFlatButtonBorder(Cxgraphics::TcxCanvas* ACanvas, TcxEditButtonViewInfo* AButtonViewInfo, bool AIsOffice11Style, System::Types::TRect &ARect, System::Types::TRect &AContentRect, /* out */ System::Uitypes::TColor &APenColor, /* out */ System::Uitypes::TColor &ABrushColor);
	virtual void __fastcall FrameRectEx(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &ARect, System::Uitypes::TColor AColor);
	void __fastcall CalculateEditorBounds();
	void __fastcall CalculateNativeInfo(/* out */ Dxthememanager::TdxThemedObjectType &AThemedObjectType, /* out */ int &ANativePart);
	void __fastcall DrawButtonBorderByPainter(TcxEditButtonViewInfo* AButtonViewInfo, System::Types::TRect &ARect, /* out */ System::Types::TRect &AContentRect, System::Uitypes::TColor &APenColor, System::Uitypes::TColor &ABrushColor);
	virtual void __fastcall DrawLookAndFeelButtonBackground(Cxgraphics::TcxCanvas* ACanvas, TcxEditButtonViewInfo* AButtonViewInfo, const System::Types::TRect &ARect);
	virtual void __fastcall DrawNativeButtonBackground(Cxgraphics::TcxCanvas* ACanvas, TcxEditButtonViewInfo* AButtonViewInfo, const System::Types::TRect &ARect);
	virtual void __fastcall DrawUsualButtonBackground(Cxgraphics::TcxCanvas* ACanvas, TcxEditButtonViewInfo* AButtonViewInfo, const System::Types::TRect &ARect, System::Uitypes::TColor ABrushColor);
	
public:
	System::Types::TRect BorderExtent;
	TcxEditBorderStyle BorderStyle;
	_TcxCustomEditViewInfo__1 ButtonsInfo;
	TcxCustomEditProperties* EditProperties;
	int Data;
	bool Enabled;
	bool Focused;
	Vcl::Graphics::TFont* Font;
	bool ForceDrawAsStandalone;
	bool HasBackground;
	bool HasContentOffsets;
	bool HasInnerEdit;
	bool HasTextButtons;
	int HitTestInfo;
	Cxcontainer::TcxContainerHotState HotState;
	System::Types::TRect InnerEditRect;
	bool IsButtonReallyPressed;
	bool IsContainerInnerControl;
	bool IsDBEditPaintCopyDrawing;
	bool IsDesigning;
	bool IsInplace;
	bool IsSelected;
	int LastPressedButton;
	int LastSelectedButton;
	int Left;
	TcxEditPaintOptions PaintOptions;
	Cxlookandfeelpainters::TcxEditPopupBorderStyle PopupBorderStyle;
	int PressedButton;
	int SelectedButton;
	System::Types::TRect ShadowRect;
	System::Uitypes::TColor TextColor;
	int Top;
	bool Transparent;
	HWND WindowHandle;
	bool UseRightToLeftAlignment;
	__fastcall virtual TcxCustomEditViewInfo();
	__fastcall virtual ~TcxCustomEditViewInfo();
	virtual void __fastcall Assign(System::TObject* Source);
	virtual void __fastcall UpdateStyle(Cxcontainer::TcxContainerStyle* AStyle);
	virtual bool __fastcall CanDrawEditValue();
	bool __fastcall DrawAsInplace();
	bool __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas)/* overload */;
	bool __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TPoint &APos)/* overload */;
	virtual void __fastcall DrawBorderedBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	void __fastcall DrawCustomEdit(Cxgraphics::TcxCanvas* ACanvas, bool ACanDrawBackground, bool ACanDrawValidationMark);
	void __fastcall DrawCustomEditValidationMark(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall DrawEditBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const System::Types::TRect &AGlyphRect, bool AGlyphTransparent);
	virtual void __fastcall DrawNativeStyleEditBackground(Cxgraphics::TcxCanvas* ACanvas, bool ADrawBackground, HBRUSH ABackgroundBrush);
	virtual void __fastcall DrawButton(Cxgraphics::TcxCanvas* ACanvas, int AButtonVisibleIndex);
	void __fastcall DrawButtons(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall DrawButtonBackground(Cxgraphics::TcxCanvas* ACanvas, TcxEditButtonViewInfo* AViewInfo, const System::Types::TRect &ARect, const System::Types::TRect &AContentRect, System::Uitypes::TColor ABrushColor);
	virtual void __fastcall DrawButtonBorder(Cxgraphics::TcxCanvas* ACanvas, TcxEditButtonViewInfo* AViewInfo, System::Types::TRect &ARect, System::Types::TRect &AContentRect, System::Uitypes::TColor &APenColor, System::Uitypes::TColor &ABrushColor);
	virtual void __fastcall DrawButtonContent(Cxgraphics::TcxCanvas* ACanvas, TcxEditButtonViewInfo* AViewInfo, const System::Types::TRect &AContentRect, System::Uitypes::TColor APenColor, System::Uitypes::TColor ABrushColor, bool ANeedOffsetContent);
	virtual bool __fastcall IsBackgroundPartiallyTransparent();
	bool __fastcall IsBackgroundTransparent();
	bool __fastcall IsCustomBackground();
	bool __fastcall IsCustomButton(int AButtonVisibleIndex = 0x0);
	bool __fastcall IsCustomButtonBackground(int AButtonVisibleIndex = 0x0);
	bool __fastcall IsCustomButtonBorder(int AButtonVisibleIndex = 0x0);
	bool __fastcall IsCustomDrawButton(int AButtonVisibleIndex = 0x0);
	virtual bool __fastcall IsFadingAvailable();
	virtual bool __fastcall IsHotTrack()/* overload */;
	virtual bool __fastcall IsHotTrack(const System::Types::TPoint &P)/* overload */;
	virtual bool __fastcall NeedShowHint(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TPoint &P, const System::Types::TRect &AVisibleBounds, /* out */ Vcl::Controls::TCaption &AText, /* out */ bool &AIsMultiLine, /* out */ System::Types::TRect &ATextRect, int AMaxLineCount = 0x0);
	virtual bool __fastcall SupportsBorders();
	virtual bool __fastcall SupportsRoundedContainerBorders();
	virtual void __fastcall Paint(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall PaintEx(Cxgraphics::TcxCanvas* ACanvas);
	virtual Cxgraphics::TcxRegion* __fastcall GetUpdateRegion(Cxcontainer::TcxContainerViewInfo* AViewInfo);
	virtual void __fastcall Offset(int DX, int DY);
	virtual void __fastcall PrepareCanvasFont(Vcl::Graphics::TCanvas* ACanvas);
	virtual bool __fastcall Repaint(Vcl::Controls::TWinControl* AControl, Cxcontainer::TcxContainerViewInfo* AViewInfo = (Cxcontainer::TcxContainerViewInfo*)(0x0))/* overload */;
	virtual bool __fastcall Repaint(Vcl::Controls::TWinControl* AControl, const System::Types::TRect &AInnerEditRect, Cxcontainer::TcxContainerViewInfo* AViewInfo = (Cxcontainer::TcxContainerViewInfo*)(0x0))/* overload */;
	void __fastcall ResetValidationInfo();
	void __fastcall SetButtonCount(int ACount);
	System::Types::TPoint __fastcall SetOrigin(const System::Types::TPoint &APoint);
	__property TcxEditBackgroundPaintingStyle BackgroundPaintingStyle = {read=GetBackgroundPaintingStyle, nodefault};
	__property TcxCustomEdit* Edit = {read=FEdit};
	__property TcxEditValidateInfo* ErrorData = {read=FErrorData};
	__property bool ReadOnly = {read=FReadOnly, write=FReadOnly, nodefault};
	__property Cxgeometry::TdxScaleFactor* ScaleFactor = {read=FScaleFactor};
	__property TAfterDrawEvent OnAfterDrawBackground = {read=FOnAfterDrawBackground, write=FOnAfterDrawBackground};
	__property TAfterDrawEvent OnAfterDrawValue = {read=FOnAfterDrawValue, write=FOnAfterDrawValue};
	__property TCalculateEditorBoundsEvent OnCalculateEditorBounds = {read=FOnCalculateEditorBounds, write=FOnCalculateEditorBounds};
	__property TCanDrawEditValueEvent OnCanDrawEditValue = {read=FOnCanDrawEditValue, write=FOnCanDrawEditValue};
	__property TcxEditCanStartButtonFadingEvent OnCanStartButtonFading = {read=FOnCanStartButtonFading, write=FOnCanStartButtonFading};
	__property TcxEditDrawBackgroundEvent OnDrawBackground = {read=FOnDrawBackground, write=SetOnDrawBackground};
	__property TcxEditDrawButtonEvent OnDrawButton = {read=FOnDrawButton, write=FOnDrawButton};
	__property TcxEditDrawButtonBackgroundEvent OnDrawButtonBackground = {read=FOnDrawButtonBackground, write=FOnDrawButtonBackground};
	__property TcxEditDrawButtonBorderEvent OnDrawButtonBorder = {read=FOnDrawButtonBorder, write=FOnDrawButtonBorder};
	__property TcxEditGetButtonContentColorEvent OnGetButtonContentColor = {read=FOnGetButtonContentColor, write=FOnGetButtonContentColor};
	__property TcxEditGetButtonStateEvent OnGetButtonState = {read=FOnGetButtonState, write=FOnGetButtonState};
	__property TcxEditPaintEvent OnPaint = {read=FOnPaint, write=FOnPaint};
	__property TcxEditPrepareButtonFadingImageEvent OnPrepareButtonFadingImage = {read=FOnPrepareButtonFadingImage, write=FOnPrepareButtonFadingImage};
};


struct DECLSPEC_DRECORD TcxInplaceEditPosition
{
public:
	System::TObject* Item;
	NativeInt RecordIndex;
};


struct DECLSPEC_DRECORD TcxInplaceEditParams
{
public:
	bool MultiRowParent;
	TcxInplaceEditPosition Position;
};


struct DECLSPEC_DRECORD TcxEditSizeProperties
{
public:
	int Height;
	int MaxLineCount;
	int Width;
};


typedef TcxEditSizeProperties *PcxEditSizeProperties;

enum DECLSPEC_DENUM TcxEditContentOption : unsigned char { ecoShowFocusRectWhenInplace, ecoOffsetButtonContent };

typedef System::Set<TcxEditContentOption, TcxEditContentOption::ecoShowFocusRectWhenInplace, TcxEditContentOption::ecoOffsetButtonContent> TcxEditContentOptions;

struct DECLSPEC_DRECORD TcxEditContentParams
{
public:
	System::Types::TRect ExternalBorderBounds;
	System::Types::TRect Offsets;
	TcxEditContentOptions Options;
	System::Types::TSize SizeCorrection;
};


typedef void __fastcall (__closure *TcxEditGetDefaultButtonWidthEvent)(TcxCustomEditViewData* Sender, int AIndex, int &ADefaultWidth);

typedef void __fastcall (__closure *TcxEditViewDataGetDisplayTextEvent)(TcxCustomEditViewData* Sender, System::UnicodeString &AText);

class PASCALIMPLEMENTATION TcxCustomEditViewData : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::TObject* FData;
	bool FIsInplace;
	int FLeftSideLeftmostButtonIndex;
	int FLeftSideRightmostButtonIndex;
	int FRightSideLeftmostButtonIndex;
	int FRightSideRightmostButtonIndex;
	Cxgeometry::TdxScaleFactor* FScaleFactor;
	System::Classes::TAlignment FValidationErrorIconAlignment;
	TcxEditGetDefaultButtonWidthEvent FOnGetDefaultButtonWidth;
	TcxEditViewDataGetDisplayTextEvent FOnGetDisplayText;
	void __fastcall DoGetButtonState(TcxEditButtonViewInfo* AViewInfo, TcxEditButtonState &AState);
	int __fastcall DoGetDefaultButtonWidth(int AIndex);
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetPainter();
	
protected:
	TcxCustomEdit* FEdit;
	TcxCustomEditProperties* FProperties;
	TcxCustomEditStyle* FStyle;
	virtual void __fastcall CalculateButtonNativeInfo(TcxEditButtonViewInfo* AButtonViewInfo);
	virtual void __fastcall CalculateButtonNativePartInfo(NativeUInt ATheme, TcxEditButtonViewInfo* AButtonViewInfo);
	virtual NativeUInt __fastcall GetButtonNativeTheme(TcxEditButtonViewInfo* AButtonViewInfo);
	virtual void __fastcall AdjustPadding(Cxlookandfeels::TdxPadding &APadding);
	virtual TcxEditPaintOptions __fastcall CalculatePaintOptions();
	virtual bool __fastcall CalculateReadOnly();
	void __fastcall CalculateViewInfo(TcxCustomEditViewInfo* AViewInfo, bool AIsMouseEvent);
	virtual bool __fastcall CanPressButton(TcxCustomEditViewInfo* AViewInfo, int AButtonVisibleIndex);
	void __fastcall CheckSizeConstraints(System::Types::TSize &AEditSize);
	void __fastcall CorrectBorderStyle(TcxEditBorderStyle &ABorderStyle);
	void __fastcall DoOnGetDisplayText(System::UnicodeString &AText);
	System::UnicodeString __fastcall EditValueToDisplayText(const System::Variant &AEditValue);
	TcxEditButtonStyle __fastcall GetButtonsStyle();
	int __fastcall GetCaptureButtonVisibleIndex();
	virtual Cxcontainer::TcxContainerState __fastcall GetContainerState(const System::Types::TRect &ABounds, const System::Types::TPoint &P, Cxcontainer::TcxMouseButton Button, System::Classes::TShiftState Shift, bool AIsMouseEvent);
	virtual System::Types::TRect __fastcall GetEditContentDefaultOffsets();
	virtual int __fastcall GetEditNativeState(TcxCustomEditViewInfo* AViewInfo);
	int __fastcall GetErrorIconWidth(TcxEditValidateInfo* AErrorData);
	virtual void __fastcall InitCacheData();
	virtual void __fastcall InitEditContentParams(TcxEditContentParams &AParams);
	virtual void __fastcall Initialize();
	virtual System::UnicodeString __fastcall InternalEditValueToDisplayText(const System::Variant &AEditValue);
	bool __fastcall InternalFocused();
	virtual System::Types::TSize __fastcall InternalGetEditConstantPartSize(Cxgraphics::TcxCanvas* ACanvas, bool AIsInplace, const TcxEditSizeProperties &AEditSizeProperties, System::Types::TSize &MinContentSize, TcxCustomEditViewInfo* AViewInfo);
	virtual System::Types::TSize __fastcall InternalGetEditContentSize(Cxgraphics::TcxCanvas* ACanvas, const System::Variant &AEditValue, const TcxEditSizeProperties &AEditSizeProperties);
	System::Types::TSize __fastcall InternalGetEditSize(Cxgraphics::TcxCanvas* ACanvas, const System::Variant &AEditValue, const TcxEditSizeProperties &AEditSizeProperties, TcxCustomEditViewInfo* AViewInfo = (TcxCustomEditViewInfo*)(0x0), bool AIsEditing = false);
	virtual bool __fastcall IsButtonPressed(TcxCustomEditViewInfo* AViewInfo, int AButtonVisibleIndex);
	bool __fastcall NeedShowErrorIcon(TcxEditValidateInfo* AErrorData);
	
public:
	bool ButtonsOnlyStyle;
	int ButtonVisibleCount;
	System::Types::TRect ClientExtent;
	Cxcontainer::TcxContainerState ContainerState;
	System::Types::TRect ContentOffset;
	TcxEditContentParams EditContentParams;
	bool Enabled;
	bool Focused;
	System::Classes::TAlignment HorzAlignment;
	Cxcontrols::_di_IcxControlScrollBar HScrollBar;
	_di_IcxCustomInnerEdit InnerEdit;
	TcxInplaceEditParams InplaceEditParams;
	bool IsDesigning;
	bool IsSelected;
	bool IsTouchScrollUIMode;
	bool IsValueSource;
	int MaxLineCount;
	bool NativeStyle;
	TcxEditPaintOptions PaintOptions;
	bool PaintOnGlass;
	bool PreviewMode;
	Cxlookandfeels::_di_IdxVisualRefinementsTuner RefinementsTuner;
	bool Selected;
	int SelStart;
	int SelLength;
	System::Uitypes::TColor SelTextColor;
	System::Uitypes::TColor SelBackgroundColor;
	bool SupportsTouchMode;
	bool UseRightToLeftAlignment;
	bool UseRightToLeftReading;
	bool UseRightToLeftScrollBar;
	TcxEditVertAlignment VertAlignment;
	Cxcontrols::_di_IcxControlScrollBar VScrollBar;
	HWND WindowHandle;
	__fastcall virtual TcxCustomEditViewData(TcxCustomEditProperties* AProperties, TcxCustomEditStyle* AStyle, bool AIsInplace);
	__fastcall virtual ~TcxCustomEditViewData();
	virtual void __fastcall Calculate(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TPoint &P, Cxcontainer::TcxMouseButton Button, System::Classes::TShiftState Shift, TcxCustomEditViewInfo* AViewInfo, bool AIsMouseEvent);
	virtual void __fastcall CalculateButtonBounds(Cxgraphics::TcxCanvas* ACanvas, TcxCustomEditViewInfo* AViewInfo, int AButtonVisibleIndex, System::Types::TRect &ButtonsRect);
	virtual void __fastcall CalculateButtonsViewInfo(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TPoint &P, Cxcontainer::TcxMouseButton Button, System::Classes::TShiftState Shift, TcxCustomEditViewInfo* AViewInfo, bool AIsMouseEvent);
	virtual void __fastcall CalculateButtonViewInfo(Cxgraphics::TcxCanvas* ACanvas, TcxCustomEditViewInfo* AViewInfo, int AButtonVisibleIndex, System::Types::TRect &ButtonsRect);
	virtual void __fastcall DoCalculateButtonViewInfos(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &AButtonsRect, TcxCustomEditViewInfo* AViewInfo);
	void __fastcall CalculateEx(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TPoint &P, Cxcontainer::TcxMouseButton Button, System::Classes::TShiftState Shift, TcxCustomEditViewInfo* AViewInfo, bool AIsMouseEvent);
	virtual void __fastcall CheckButtonsOnly(TcxCustomEditViewInfo* AViewInfo, int APrevButtonsWidth, int AButtonsWidth);
	virtual void __fastcall CheckStartButtonsFading(TcxCustomEditViewInfo* AViewInfo);
	virtual void __fastcall DoRightToLeftConversion(TcxCustomEditViewInfo* AViewInfo, const System::Types::TRect &ABounds);
	virtual void __fastcall EditValueToDrawValue(const System::Variant &AEditValue, TcxCustomEditViewInfo* AViewInfo);
	virtual void __fastcall InitializeButtonInfo(TcxCustomEditViewInfo* AViewInfo, int AButtonVisibleIndex);
	virtual System::Types::TRect __fastcall GetBorderExtent();
	virtual System::Types::TRect __fastcall GetBorderExtentByEdges(int ABorderWidth);
	virtual System::Types::TRect __fastcall GetBorderExtentByPainter();
	virtual TcxEditBorderStyle __fastcall GetBorderStyle();
	virtual System::Types::TRect __fastcall GetButtonsExtent(Cxgraphics::TcxCanvas* ACanvas);
	virtual System::Types::TRect __fastcall GetClientExtent(Cxgraphics::TcxCanvas* ACanvas, TcxCustomEditViewInfo* AViewInfo);
	virtual System::Types::TSize __fastcall GetEditConstantPartSize(Cxgraphics::TcxCanvas* ACanvas, const TcxEditSizeProperties &AEditSizeProperties, System::Types::TSize &MinContentSize, TcxCustomEditViewInfo* AViewInfo = (TcxCustomEditViewInfo*)(0x0));
	virtual System::Types::TSize __fastcall GetEditContentSize(Cxgraphics::TcxCanvas* ACanvas, const System::Variant &AEditValue, const TcxEditSizeProperties &AEditSizeProperties, TcxEditValidateInfo* AErrorData = (TcxEditValidateInfo*)(0x0));
	virtual System::Types::TSize __fastcall GetEditingContentSize(Cxgraphics::TcxCanvas* ACanvas, const System::Variant &AEditValue, const TcxEditSizeProperties &AEditSizeProperties);
	virtual System::Types::TSize __fastcall GetEditContentSizeCorrection();
	System::Types::TSize __fastcall GetEditSize(Cxgraphics::TcxCanvas* ACanvas, const System::Variant &AEditValue, const TcxEditSizeProperties &AEditSizeProperties, TcxCustomEditViewInfo* AViewInfo = (TcxCustomEditViewInfo*)(0x0));
	System::Types::TSize __fastcall GetEditingSize(Cxgraphics::TcxCanvas* ACanvas, const System::Variant &AEditValue, const TcxEditSizeProperties &AEditSizeProperties, TcxCustomEditViewInfo* AViewInfo = (TcxCustomEditViewInfo*)(0x0));
	bool __fastcall HasBorders();
	virtual bool __fastcall HasShadow();
	virtual bool __fastcall IgnoreButtonWhileStretching(int AButtonVisibleIndex);
	virtual bool __fastcall IgnorePainterBorderSettings();
	virtual bool __fastcall IsButtonLeftAligned(TcxCustomEditViewInfo* AViewInfo, int AButtonVisibleIndex);
	__classmethod virtual bool __fastcall IsNativeStyle(Cxlookandfeels::TcxLookAndFeel* ALookAndFeel);
	virtual bool __fastcall IsPaddingAllowedForInplace();
	virtual bool __fastcall IsPaddingAllowedForStandalone();
	__property System::TObject* Data = {read=FData, write=FData};
	__property TcxCustomEdit* Edit = {read=FEdit, write=FEdit};
	__property bool IsInplace = {read=FIsInplace, nodefault};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* Painter = {read=GetPainter};
	__property TcxCustomEditProperties* Properties = {read=FProperties};
	__property Cxgeometry::TdxScaleFactor* ScaleFactor = {read=FScaleFactor};
	__property TcxCustomEditStyle* Style = {read=FStyle, write=FStyle};
	__property TcxEditGetDefaultButtonWidthEvent OnGetDefaultButtonWidth = {read=FOnGetDefaultButtonWidth, write=FOnGetDefaultButtonWidth};
	__property TcxEditViewDataGetDisplayTextEvent OnGetDisplayText = {read=FOnGetDisplayText, write=FOnGetDisplayText};
};


typedef System::TMetaClass* TcxCustomEditViewDataClass;

class PASCALIMPLEMENTATION TcxEditStyleController : public Cxcontainer::TcxStyleController
{
	typedef Cxcontainer::TcxStyleController inherited;
	
private:
	HIDESBASE TcxCustomEditStyle* __fastcall GetInternalStyle(Cxcontainer::TcxContainerStateItem AState);
	HIDESBASE TcxEditStyle* __fastcall GetStyle();
	TcxEditStyle* __fastcall GetStyleDisabled();
	TcxEditStyle* __fastcall GetStyleFocused();
	TcxEditStyle* __fastcall GetStyleHot();
	HIDESBASE void __fastcall SetInternalStyle(Cxcontainer::TcxContainerStateItem AState, TcxCustomEditStyle* Value);
	void __fastcall SetStyle(TcxEditStyle* Value);
	void __fastcall SetStyleDisabled(TcxEditStyle* Value);
	void __fastcall SetStyleFocused(TcxEditStyle* Value);
	void __fastcall SetStyleHot(TcxEditStyle* Value);
	
protected:
	virtual Cxcontainer::TcxContainerStyleClass __fastcall GetStyleClass();
	
public:
	__property TcxCustomEditStyle* Styles[Cxcontainer::TcxContainerStateItem AState] = {read=GetInternalStyle, write=SetInternalStyle};
	
__published:
	__property TcxEditStyle* Style = {read=GetStyle, write=SetStyle};
	__property TcxEditStyle* StyleDisabled = {read=GetStyleDisabled, write=SetStyleDisabled};
	__property TcxEditStyle* StyleFocused = {read=GetStyleFocused, write=SetStyleFocused};
	__property TcxEditStyle* StyleHot = {read=GetStyleHot, write=SetStyleHot};
	__property OnStyleChanged;
public:
	/* TcxStyleController.Create */ inline __fastcall virtual TcxEditStyleController(System::Classes::TComponent* AOwner) : Cxcontainer::TcxStyleController(AOwner) { }
	/* TcxStyleController.Destroy */ inline __fastcall virtual ~TcxEditStyleController() { }
	
};


typedef System::TMetaClass* TcxCustomEditStyleClass;

class PASCALIMPLEMENTATION TcxCustomEditStyle : public Cxcontainer::TcxContainerStyle
{
	typedef Cxcontainer::TcxContainerStyle inherited;
	
private:
	TcxEditButtonStyle FButtonStyle;
	TcxEditButtonTransparency FButtonTransparency;
	bool FGradient;
	bool FGradientButtons;
	Cxclasses::TcxDirection FGradientDirection;
	Cxlookandfeelpainters::TcxEditPopupBorderStyle FPopupBorderStyle;
	bool FPopupCloseButton;
	HIDESBASE TcxEditStyleController* __fastcall GetActiveStyleController();
	HIDESBASE Cxcontainer::TcxContainerStyleValues __fastcall GetAssignedValues();
	HIDESBASE TcxCustomEditStyle* __fastcall GetBaseStyle();
	HIDESBASE TcxEditBorderStyle __fastcall GetBorderStyle();
	TcxEditButtonStyle __fastcall GetButtonStyle();
	TcxEditButtonTransparency __fastcall GetButtonTransparency();
	TcxCustomEdit* __fastcall GetEdit();
	bool __fastcall GetGradient();
	bool __fastcall GetGradientButtons();
	TcxEditGradientDirection __fastcall GetGradientDirection();
	Cxlookandfeelpainters::TcxEditPopupBorderStyle __fastcall GetPopupBorderStyle();
	bool __fastcall GetPopupCloseButton();
	TcxEditStyleController* __fastcall GetStyleController();
	bool __fastcall InternalGetButtonStyle(TcxEditButtonStyle &ButtonStyle);
	bool __fastcall InternalGetButtonTransparency(TcxEditButtonTransparency &ButtonTransparency);
	bool __fastcall InternalGetGradient(bool &Gradient);
	bool __fastcall InternalGetGradientButtons(bool &GradientButtons);
	bool __fastcall InternalGetGradientDirection(TcxEditGradientDirection &GradientDirection);
	bool __fastcall InternalGetPopupBorderStyle(Cxlookandfeelpainters::TcxEditPopupBorderStyle &PopupBorderStyle);
	HIDESBASE bool __fastcall IsBorderStyleStored();
	bool __fastcall IsButtonStyleStored();
	bool __fastcall IsButtonTransparencyStored();
	bool __fastcall IsGradientStored();
	bool __fastcall IsGradientButtonsStored();
	bool __fastcall IsGradientDirectionStored();
	bool __fastcall IsPopupBorderStyleStored();
	HIDESBASE bool __fastcall IsStyleControllerStored();
	HIDESBASE void __fastcall SetAssignedValues(Cxcontainer::TcxContainerStyleValues Value);
	HIDESBASE void __fastcall SetBorderStyle(TcxEditBorderStyle Value);
	void __fastcall SetButtonStyle(TcxEditButtonStyle Value);
	void __fastcall SetButtonTransparency(TcxEditButtonTransparency Value);
	void __fastcall SetGradient(bool Value);
	void __fastcall SetGradientButtons(bool Value);
	void __fastcall SetGradientDirection(TcxEditGradientDirection Value);
	void __fastcall SetPopupBorderStyle(Cxlookandfeelpainters::TcxEditPopupBorderStyle Value);
	void __fastcall SetPopupCloseButton(bool Value);
	void __fastcall SetStyleController(TcxEditStyleController* Value);
	
protected:
	virtual Cxcontainer::TcxStyleController* __fastcall GetDefaultStyleController();
	virtual Cxcontainer::TcxContainerStyleValues __fastcall InternalGetNotPublishedExtendedStyleValues();
	virtual TcxEditButtonStyle __fastcall DefaultButtonStyle();
	virtual TcxEditButtonTransparency __fastcall DefaultButtonTransparency();
	virtual bool __fastcall DefaultGradient();
	virtual bool __fastcall DefaultGradientButtons();
	virtual TcxEditGradientDirection __fastcall DefaultGradientDirection();
	virtual Cxlookandfeelpainters::TcxEditPopupBorderStyle __fastcall DefaultPopupBorderStyle();
	__property bool PopupCloseButton = {read=GetPopupCloseButton, write=SetPopupCloseButton, default=1};
	
public:
	__fastcall virtual TcxCustomEditStyle(System::Classes::TPersistent* AOwner, bool ADirectAccessMode, Cxcontainer::TcxContainerStyle* AParentStyle, Cxcontainer::TcxContainerStateItem AState);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual int __fastcall GetStyleValueCount();
	virtual bool __fastcall GetStyleValueName(Cxcontainer::TcxContainerStyleValue AStyleValue, /* out */ System::UnicodeString &StyleValueName);
	virtual bool __fastcall IsValueAssigned(Cxcontainer::TcxContainerStyleValue AValue);
	void __fastcall Init(const Cxgraphics::TcxViewParams &AParams);
	__property TcxEditStyleController* ActiveStyleController = {read=GetActiveStyleController};
	__property Cxcontainer::TcxContainerStyleValues AssignedValues = {read=GetAssignedValues, write=SetAssignedValues, stored=false, nodefault};
	__property TcxCustomEditStyle* BaseStyle = {read=GetBaseStyle};
	__property TcxEditBorderStyle BorderStyle = {read=GetBorderStyle, write=SetBorderStyle, stored=IsBorderStyleStored, nodefault};
	__property TcxEditButtonStyle ButtonStyle = {read=GetButtonStyle, write=SetButtonStyle, stored=IsButtonStyleStored, nodefault};
	__property TcxEditButtonTransparency ButtonTransparency = {read=GetButtonTransparency, write=SetButtonTransparency, stored=IsButtonTransparencyStored, nodefault};
	__property TcxCustomEdit* Edit = {read=GetEdit};
	__property bool Gradient = {read=GetGradient, write=SetGradient, stored=IsGradientStored, nodefault};
	__property bool GradientButtons = {read=GetGradientButtons, write=SetGradientButtons, stored=IsGradientButtonsStored, nodefault};
	__property TcxEditGradientDirection GradientDirection = {read=GetGradientDirection, write=SetGradientDirection, stored=IsGradientDirectionStored, nodefault};
	__property Cxlookandfeelpainters::TcxEditPopupBorderStyle PopupBorderStyle = {read=GetPopupBorderStyle, write=SetPopupBorderStyle, stored=IsPopupBorderStyleStored, nodefault};
	__property TcxEditStyleController* StyleController = {read=GetStyleController, write=SetStyleController, stored=IsStyleControllerStored};
public:
	/* TcxContainerStyle.Destroy */ inline __fastcall virtual ~TcxCustomEditStyle() { }
	
};


class PASCALIMPLEMENTATION TcxEditStyle : public TcxCustomEditStyle
{
	typedef TcxCustomEditStyle inherited;
	
__published:
	__property AssignedValues;
	__property BorderColor;
	__property BorderStyle;
	__property ButtonStyle;
	__property ButtonTransparency;
	__property Color;
	__property Edges;
	__property Font;
	__property Gradient;
	__property GradientDirection;
	__property HotTrack;
	__property LookAndFeel;
	__property PopupBorderStyle;
	__property Shadow;
	__property StyleController;
	__property TextColor;
	__property TextStyle;
	__property TransparentBorder;
public:
	/* TcxCustomEditStyle.Create */ inline __fastcall virtual TcxEditStyle(System::Classes::TPersistent* AOwner, bool ADirectAccessMode, Cxcontainer::TcxContainerStyle* AParentStyle, Cxcontainer::TcxContainerStateItem AState) : TcxCustomEditStyle(AOwner, ADirectAccessMode, AParentStyle, AState) { }
	
public:
	/* TcxContainerStyle.Destroy */ inline __fastcall virtual ~TcxEditStyle() { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomEditPropertiesValues : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::Classes::TPersistent* FOwner;
	bool FMaxValue;
	bool FMinValue;
	bool FReadOnly;
	TcxCustomEditProperties* __fastcall GetProperties();
	void __fastcall SetMaxValue(bool Value);
	void __fastcall SetMinValue(bool Value);
	void __fastcall SetReadOnly(bool Value);
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner();
	void __fastcall Changed();
	bool __fastcall IsMaxValueStored();
	bool __fastcall IsMinValueStored();
	bool __fastcall IsPropertiesPropertyVisible(const System::UnicodeString APropertyName);
	__property bool MaxValue = {read=FMaxValue, write=SetMaxValue, stored=IsMaxValueStored, nodefault};
	__property bool MinValue = {read=FMinValue, write=SetMinValue, stored=IsMinValueStored, nodefault};
	__property TcxCustomEditProperties* Properties = {read=GetProperties};
	
public:
	__fastcall virtual TcxCustomEditPropertiesValues(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall BeginUpdate();
	void __fastcall EndUpdate();
	virtual void __fastcall RestoreDefaults();
	
__published:
	__property bool ReadOnly = {read=FReadOnly, write=SetReadOnly, stored=false, nodefault};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxCustomEditPropertiesValues() { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCustomEditPropertiesValuesClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomEditDefaultValuesProvider : public Dxcoreclasses::TcxInterfacedPersistent
{
	typedef Dxcoreclasses::TcxInterfacedPersistent inherited;
	
public:
	__fastcall virtual ~TcxCustomEditDefaultValuesProvider();
	virtual bool __fastcall CanSetEditMode();
	void __fastcall ClearUsers();
	virtual System::Classes::TAlignment __fastcall DefaultAlignment();
	virtual TcxBlobKind __fastcall DefaultBlobKind();
	virtual bool __fastcall DefaultCanModify();
	virtual System::UnicodeString __fastcall DefaultDisplayFormat();
	virtual System::UnicodeString __fastcall DefaultEditFormat();
	virtual System::UnicodeString __fastcall DefaultEditMask();
	virtual bool __fastcall DefaultIsFloatValue();
	virtual int __fastcall DefaultMaxLength();
	virtual double __fastcall DefaultMaxValue();
	virtual double __fastcall DefaultMinValue();
	virtual int __fastcall DefaultPrecision();
	virtual bool __fastcall DefaultReadOnly();
	virtual bool __fastcall DefaultRequired();
	System::TObject* __fastcall GetInstance();
	virtual bool __fastcall IsBlob();
	virtual bool __fastcall IsCurrency();
	virtual bool __fastcall IsDataAvailable();
	virtual bool __fastcall IsDataStorage();
	virtual bool __fastcall IsDisplayFormatDefined(bool AIsCurrencyValueAccepted);
	virtual bool __fastcall IsOnGetTextAssigned();
	virtual bool __fastcall IsOnSetTextAssigned();
	virtual bool __fastcall IsValidChar(System::WideChar AChar);
public:
	/* TcxInterfacedPersistent.Create */ inline __fastcall virtual TcxCustomEditDefaultValuesProvider(System::Classes::TPersistent* AOwner) : Dxcoreclasses::TcxInterfacedPersistent(AOwner) { }
	
private:
	void *__IcxEditDefaultValuesProvider;	// IcxEditDefaultValuesProvider 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {AE727882-6FDF-4E3A-AB35-E58AB28EFE7B}
	operator _di_IcxEditDefaultValuesProvider()
	{
		_di_IcxEditDefaultValuesProvider intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IcxEditDefaultValuesProvider*(void) { return (IcxEditDefaultValuesProvider*)&__IcxEditDefaultValuesProvider; }
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
	operator System::IInterface*(void) { return (System::IInterface*)&__IcxEditDefaultValuesProvider; }
	#endif
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCustomEditDefaultValuesProviderClass;

typedef void __fastcall (__closure *TcxEditButtonClickEvent)(System::TObject* Sender, int AButtonIndex);

typedef void __fastcall (__closure *TcxEditEditingEvent)(System::TObject* Sender, bool &CanEdit);

enum DECLSPEC_DENUM TcxEditCloseUpReason : unsigned char { crUnknown, crTab, crClose, crCancel, crEnter };

typedef void __fastcall (__closure *TcxEditClosePopupEvent)(Cxcontrols::TcxControl* Sender, TcxEditCloseUpReason AReason);

class PASCALIMPLEMENTATION TcxCustomEditProperties : public Dxcoreclasses::TcxInterfacedPersistent
{
	typedef Dxcoreclasses::TcxInterfacedPersistent inherited;
	
private:
	bool FAutoSelect;
	bool FBeepOnError;
	TcxEditButtons* FButtons;
	TcxEditButtonsViewStyle FButtonsViewStyle;
	bool FChangedOccurred;
	System::Classes::TShortCut FClearKey;
	System::Classes::TShortCut FClickKey;
	Dxcoreclasses::TcxFreeNotificator* FFreeNotificator;
	Vcl::Imglist::TChangeLink* FImageChangeLink;
	bool FImmediatePost;
	TcxEditAlignment* FInnerAlignment;
	int FIsChangingCount;
	double FMaxValue;
	double FMinValue;
	bool FReadOnly;
	Cxgeometry::TdxOwnedScaleFactor* FScaleFactor;
	bool FTransparent;
	int FUpdateCount;
	bool FUseLeftAlignmentOnEditing;
	bool FUseMouseWheel;
	Dxgdiplusclasses::TdxSmartImage* FErrorIcon;
	bool FValidateOnEnter;
	System::Classes::TAlignment FValidationErrorIconAlignment;
	TcxEditValidationOptions FValidationOptions;
	TcxEditValidationOptions FInternalValidationOptions;
	TcxEditButtonClickEvent FOnButtonClick;
	System::Classes::TNotifyEvent FOnChange;
	TcxEditClosePopupEvent FOnClosePopup;
	System::Classes::TNotifyEvent FOnEditValueChanged;
	TcxEditValidateEvent FOnValidate;
	System::Classes::TNotifyEvent FOnPropertiesChanged;
	TcxEditAlignment* __fastcall BaseGetAlignment();
	Vcl::Imglist::TCustomImageList* __fastcall GetImages();
	bool __fastcall GetIsChanging();
	Dxcoreclasses::TcxFreeNotificator* __fastcall GetFreeNotificator();
	bool __fastcall GetReadOnly();
	Cxgeometry::TdxScaleFactor* __fastcall GetScaleFactor();
	void __fastcall ImageListChange(System::TObject* Sender);
	bool __fastcall IsAlignmentStored();
	bool __fastcall IsUseLeftAlignmentOnEditingStored();
	bool __fastcall IsReadOnlyStored();
	void __fastcall SetAssignedValues(TcxCustomEditPropertiesValues* Value);
	void __fastcall SetAutoSelect(bool Value);
	void __fastcall SetButtons(TcxEditButtons* Value);
	void __fastcall SetButtonsViewStyle(TcxEditButtonsViewStyle Value);
	void __fastcall SetErrorIcon(Dxgdiplusclasses::TdxSmartImage* Value);
	void __fastcall SetImages(Vcl::Imglist::TCustomImageList* Value);
	void __fastcall SetUseLeftAlignmentOnEditing(bool Value);
	void __fastcall SetDefaultValuesProvider(TcxCustomEditDefaultValuesProvider* Value);
	void __fastcall SetMaxValue(double Value);
	void __fastcall SetMinValue(double Value);
	void __fastcall SetReadOnly(bool Value);
	void __fastcall SetTransparent(bool Value);
	void __fastcall SetValidationErrorIconAlignment(System::Classes::TLeftRight AValue);
	void __fastcall SetValidationOptions(TcxEditValidationOptions Value);
	void __fastcall ScaleFactorChangeHandler(System::TObject* Sender, int M, int D, bool IsLoading);
	
protected:
	TcxEditAlignment* FAlignment;
	TcxCustomEditPropertiesValues* FAssignedValues;
	bool FChangedLocked;
	TcxCustomEditDefaultValuesProvider* FDefaultValuesProvider;
	void __fastcall DestroyFreeNotificator();
	virtual void __fastcall AlignmentChangedHandler(System::TObject* Sender);
	virtual void __fastcall BaseSetAlignment(TcxEditAlignment* Value);
	virtual void __fastcall ChangeScale(int M, int D);
	bool __fastcall CanModify();
	virtual bool __fastcall CanValidate();
	virtual void __fastcall ChangeHandler(System::TObject* Sender);
	virtual bool __fastcall DefaultUseLeftAlignmentOnEditing();
	virtual void __fastcall DefaultValuesProviderDestroyed();
	virtual void __fastcall DoAssign(TcxCustomEditProperties* AProperties);
	virtual void __fastcall DoChanged();
	void __fastcall DoValidate(System::Variant &ADisplayValue, Vcl::Controls::TCaption &AErrorText, bool &AError, TcxCustomEdit* AEdit, /* out */ bool &AIsUserErrorDisplayValue);
	void __fastcall FillMinMaxValues(double AMinValue, double AMaxValue);
	virtual void __fastcall FreeNotification(System::Classes::TComponent* Sender);
	__classmethod virtual TcxCustomEditPropertiesValuesClass __fastcall GetAssignedValuesClass();
	int __fastcall GetButtonIndexByVisibleIndex(int AButtonVisibleIndex);
	virtual System::Classes::TAlignment __fastcall GetDefaultHorzAlignment();
	virtual TcxEditVertAlignment __fastcall GetDefaultVertAlignment();
	virtual TcxEditDisplayFormatOptions __fastcall GetDisplayFormatOptions();
	virtual double __fastcall GetMaxValue();
	virtual double __fastcall GetMinValue();
	virtual System::UnicodeString __fastcall GetValidateErrorText(int AErrorKind);
	virtual Cxdatautils::TcxDataEditValueSource __fastcall GetValueEditorEditValueSource(bool AEditFocused);
	__classmethod virtual TcxCustomEditViewDataClass __fastcall GetViewDataClass();
	virtual bool __fastcall HasDisplayValue();
	virtual bool __fastcall InnerEditNeedsTabs();
	bool __fastcall IsDesigning();
	virtual bool __fastcall IsEditValueConversionDependOnFocused();
	bool __fastcall IsMaxValueStored();
	bool __fastcall IsMinValueStored();
	virtual void __fastcall InitiateActions();
	virtual bool __fastcall SupportsMultiThreading(bool AUseDisplayValue);
	__property TcxCustomEditPropertiesValues* AssignedValues = {read=FAssignedValues, write=SetAssignedValues};
	__property TcxEditButtonsViewStyle ButtonsViewStyle = {read=FButtonsViewStyle, write=SetButtonsViewStyle, default=0};
	__property TcxEditDisplayFormatOptions DisplayFormatOptions = {read=GetDisplayFormatOptions, nodefault};
	__property Dxcoreclasses::TcxFreeNotificator* FreeNotificator = {read=GetFreeNotificator};
	__property double MaxValue = {read=GetMaxValue, write=SetMaxValue, stored=IsMaxValueStored};
	__property double MinValue = {read=GetMinValue, write=SetMinValue, stored=IsMinValueStored};
	__property Cxgeometry::TdxOwnedScaleFactor* ScaleFactor = {read=FScaleFactor};
	__property bool Transparent = {read=FTransparent, write=SetTransparent, stored=false, nodefault};
	
public:
	__fastcall virtual TcxCustomEditProperties(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TcxCustomEditProperties();
	virtual void __fastcall AfterConstruction();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual bool __fastcall CanCompareEditValue();
	virtual TcxCustomEditProperties* __fastcall Clone(System::Classes::TPersistent* AOwner);
	__classmethod virtual TcxEditButtonsClass __fastcall GetButtonsClass();
	__classmethod virtual Cxcontainer::TcxContainerClass __fastcall GetContainerClass();
	__classmethod virtual TcxCustomEditStyleClass __fastcall GetStyleClass();
	__classmethod virtual Cxcontainer::TcxContainerViewInfoClass __fastcall GetViewInfoClass();
	void __fastcall BeginUpdate();
	void __fastcall Changed();
	bool __fastcall ChangedLocked();
	virtual void __fastcall DoUpdate(TcxCustomEditProperties* AProperties);
	void __fastcall EndUpdate(bool AInvokeChanged = true);
	void __fastcall Update(TcxCustomEditProperties* AProperties);
	void __fastcall LockUpdate(bool ALock);
	virtual bool __fastcall AllowRepositorySharing();
	virtual void __fastcall RefreshNonShareable();
	virtual bool __fastcall CompareDisplayValues(const System::Variant &AEditValue1, const System::Variant &AEditValue2);
	virtual TcxCustomEditProperties* __fastcall CreatePreviewProperties();
	virtual TcxCustomEditViewData* __fastcall CreateViewData(TcxCustomEditStyle* AStyle, bool AIsInplace, bool APreviewMode = false);
	virtual void __fastcall DataChanged();
	virtual System::UnicodeString __fastcall GetDisplayText(const System::Variant &AEditValue, bool AFullText = false, bool AIsInplace = true);
	System::Types::TSize __fastcall GetEditConstantPartSize(Cxgraphics::TcxCanvas* ACanvas, TcxCustomEditStyle* AEditStyle, bool AIsInplace, const TcxEditSizeProperties &AEditSizeProperties, System::Types::TSize &MinContentSize);
	System::Types::TSize __fastcall GetEditContentSize(Cxgraphics::TcxCanvas* ACanvas, TcxCustomEditStyle* AEditStyle, bool AIsInplace, const System::Variant &AEditValue, const TcxEditSizeProperties &AEditSizeProperties);
	System::Types::TSize __fastcall GetEditSize(Cxgraphics::TcxCanvas* ACanvas, TcxCustomEditStyle* AEditStyle, bool AIsInplace, const System::Variant &AEditValue, const TcxEditSizeProperties &AEditSizeProperties);
	virtual TcxEditSpecialFeatures __fastcall GetSpecialFeatures();
	virtual TcxEditSupportedOperations __fastcall GetSupportedOperations();
	virtual bool __fastcall IsActivationKey(System::WideChar AKey);
	virtual bool __fastcall IsEditValueValid(System::Variant &AEditValue, bool AEditFocused);
	virtual bool __fastcall IsResetEditClass();
	virtual bool __fastcall IsValueFormattedByProperties();
	virtual bool __fastcall IsValueFormattedByProvider();
	virtual void __fastcall PrepareDisplayValue(const System::Variant &AEditValue, System::Variant &DisplayValue, bool AEditFocused);
	virtual void __fastcall RestoreDefaults();
	virtual void __fastcall ValidateDisplayValue(System::Variant &ADisplayValue, Vcl::Controls::TCaption &AErrorText, bool &AError, TcxCustomEdit* AEdit);
	virtual Cxdatautils::TcxDataEditValueSource __fastcall GetEditValueSource(bool AEditFocused);
	__property TcxEditButtons* Buttons = {read=FButtons, write=SetButtons};
	__property TcxCustomEditDefaultValuesProvider* DefaultValuesProvider = {read=FDefaultValuesProvider, write=SetDefaultValuesProvider};
	__property Vcl::Imglist::TCustomImageList* Images = {read=GetImages, write=SetImages};
	__property bool IsChanging = {read=GetIsChanging, nodefault};
	__property System::Classes::TNotifyEvent OnPropertiesChanged = {read=FOnPropertiesChanged, write=FOnPropertiesChanged};
	__property bool ReadOnly = {read=GetReadOnly, write=SetReadOnly, stored=IsReadOnlyStored, nodefault};
	__property bool UseLeftAlignmentOnEditing = {read=FUseLeftAlignmentOnEditing, write=SetUseLeftAlignmentOnEditing, stored=IsUseLeftAlignmentOnEditingStored, nodefault};
	__property bool UseMouseWheel = {read=FUseMouseWheel, write=FUseMouseWheel, default=1};
	__property TcxEditAlignment* Alignment = {read=BaseGetAlignment, write=BaseSetAlignment, stored=IsAlignmentStored};
	__property bool AutoSelect = {read=FAutoSelect, write=SetAutoSelect, default=1};
	__property bool BeepOnError = {read=FBeepOnError, write=FBeepOnError, default=0};
	__property System::Classes::TShortCut ClearKey = {read=FClearKey, write=FClearKey, default=0};
	__property System::Classes::TShortCut ClickKey = {read=FClickKey, write=FClickKey, default=16397};
	__property bool ImmediatePost = {read=FImmediatePost, write=FImmediatePost, default=0};
	__property bool ValidateOnEnter = {read=FValidateOnEnter, write=FValidateOnEnter, default=0};
	__property System::Classes::TLeftRight ValidationErrorIconAlignment = {read=FValidationErrorIconAlignment, write=SetValidationErrorIconAlignment, default=0};
	__property TcxEditValidationOptions ValidationOptions = {read=FValidationOptions, write=SetValidationOptions, default=1};
	__property Dxgdiplusclasses::TdxSmartImage* ErrorIcon = {read=FErrorIcon, write=SetErrorIcon};
	__property TcxEditButtonClickEvent OnButtonClick = {read=FOnButtonClick, write=FOnButtonClick};
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property TcxEditClosePopupEvent OnClosePopup = {read=FOnClosePopup, write=FOnClosePopup};
	__property System::Classes::TNotifyEvent OnEditValueChanged = {read=FOnEditValueChanged, write=FOnEditValueChanged};
	__property TcxEditValidateEvent OnValidate = {read=FOnValidate, write=FOnValidate};
private:
	void *__IdxFreeNotify;	// Dxcoreclasses::IdxFreeNotify 
	void *__IdxScaleFactor;	// Cxgeometry::IdxScaleFactor 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {31F91C69-F04C-451D-9091-32FF27BBF3A8}
	operator Dxcoreclasses::_di_IdxFreeNotify()
	{
		Dxcoreclasses::_di_IdxFreeNotify intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Dxcoreclasses::IdxFreeNotify*(void) { return (Dxcoreclasses::IdxFreeNotify*)&__IdxFreeNotify; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {367A805A-A84B-441A-83A3-6A7E489D3B6C}
	operator Cxgeometry::_di_IdxScaleFactor()
	{
		Cxgeometry::_di_IdxScaleFactor intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Cxgeometry::IdxScaleFactor*(void) { return (Cxgeometry::IdxScaleFactor*)&__IdxScaleFactor; }
	#endif
	
};


class PASCALIMPLEMENTATION TcxDataBinding : public Cxdatautils::TcxCustomDataBinding
{
	typedef Cxdatautils::TcxCustomDataBinding inherited;
	
public:
	/* TcxCustomDataBinding.Create */ inline __fastcall virtual TcxDataBinding(System::Classes::TComponent* AOwner, System::Classes::TComponent* ADataComponent) : Cxdatautils::TcxCustomDataBinding(AOwner, ADataComponent) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxDataBinding() { }
	
};


typedef System::TMetaClass* TInterfacedObjectClass;

class PASCALIMPLEMENTATION TcxEditDataBinding : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TcxCustomEditDefaultValuesProvider* FDefaultValuesProvider;
	System::Classes::TActionEvent FOnExecuteAction;
	System::Classes::TActionEvent FOnUpdateAction;
	
protected:
	TcxCustomEdit* FEdit;
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner();
	virtual void __fastcall DefaultValuesChanged();
	virtual System::Variant __fastcall GetDisplayValue();
	virtual bool __fastcall GetIsDataAvailable();
	TcxEditDataBinding* __fastcall GetEditDataBindingInstance();
	virtual bool __fastcall GetEditing();
	virtual bool __fastcall GetModified();
	virtual System::Variant __fastcall GetStoredValue();
	virtual bool __fastcall IsInnerControlHaveToBeReadOnly();
	virtual bool __fastcall IsNull();
	virtual void __fastcall Reset();
	void __fastcall SetInternalDisplayValue(const System::Variant &Value);
	virtual void __fastcall SetDisplayValue(const System::Variant &Value);
	virtual bool __fastcall SetEditMode();
	virtual void __fastcall SetStoredValue(const System::Variant &Value);
	__property TcxCustomEdit* Edit = {read=FEdit};
	__property System::Classes::TActionEvent OnExecuteAction = {read=FOnExecuteAction, write=FOnExecuteAction};
	__property System::Classes::TActionEvent OnUpdateAction = {read=FOnUpdateAction, write=FOnUpdateAction};
	
public:
	__fastcall virtual TcxEditDataBinding(TcxCustomEdit* AEdit);
	__fastcall virtual ~TcxEditDataBinding();
	virtual bool __fastcall CanCheckEditorValue();
	virtual bool __fastcall CanModify();
	virtual bool __fastcall CanPostEditorValue();
	virtual bool __fastcall ExecuteAction(System::Classes::TBasicAction* Action);
	__classmethod virtual TcxCustomEditDefaultValuesProviderClass __fastcall GetDefaultValuesProviderClass();
	virtual void __fastcall SetModified();
	virtual bool __fastcall UpdateAction(System::Classes::TBasicAction* Action);
	virtual void __fastcall UpdateDisplayValue();
	virtual void __fastcall UpdateNotConnectedDBEditDisplayValue();
	__property TcxCustomEditDefaultValuesProvider* DefaultValuesProvider = {read=FDefaultValuesProvider};
	__property System::Variant DisplayValue = {read=GetDisplayValue, write=SetDisplayValue};
	__property bool Editing = {read=GetEditing, nodefault};
	__property bool IsDataAvailable = {read=GetIsDataAvailable, nodefault};
	__property bool Modified = {read=GetModified, nodefault};
	__property System::Variant StoredValue = {read=GetStoredValue, write=SetStoredValue};
};


typedef System::TMetaClass* TcxEditDataBindingClass;

struct DECLSPEC_DRECORD TcxEditModifiedState
{
public:
	bool Modified;
	bool ModifiedAfterEnter;
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomEditData : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FCleared;
	TcxCustomEdit* FEdit;
	Dxcoreclasses::TcxFreeNotificator* FFreeNotificator;
	void __fastcall FreeNotification(System::Classes::TComponent* AComponent);
	
protected:
	__property bool Cleared = {read=FCleared, write=FCleared, nodefault};
	
public:
	__fastcall virtual TcxCustomEditData(TcxCustomEdit* AEdit);
	__fastcall virtual ~TcxCustomEditData();
	void __fastcall Clear();
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCustomEditDataClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxEditChangeEventsCatcher : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxCustomEdit* FEdit;
	int FLockCount;
	bool FOnChangeEvent;
	bool FOnEditValueChangedEvent;
	
public:
	__fastcall TcxEditChangeEventsCatcher(TcxCustomEdit* AEdit);
	bool __fastcall IsLocked();
	void __fastcall Lock(bool ALock, bool AInvokeChangedOnUnlock = true);
	void __fastcall InvokeEditChangedEvents();
	__property bool OnChangeEvent = {read=FOnChangeEvent, write=FOnChangeEvent, nodefault};
	__property bool OnEditValueChangedEvent = {read=FOnEditValueChangedEvent, write=FOnEditValueChangedEvent, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxEditChangeEventsCatcher() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxCustomEditContainer : public Cxcontainer::TcxContainer
{
	typedef Cxcontainer::TcxContainer inherited;
	
private:
	MESSAGE void __fastcall CMGestureManagerChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseLeave(Winapi::Messages::TMessage &Message);
	
protected:
	virtual bool __fastcall IsCaptureMouse();
	virtual bool __fastcall PtInCaller(const System::Types::TPoint &P);
	bool __fastcall IsTransparentRegionsPresent();
	DYNAMIC void __fastcall MouseEnter(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	
__published:
	__property Align = {default=0};
public:
	/* TcxContainer.Create */ inline __fastcall virtual TcxCustomEditContainer(System::Classes::TComponent* AOwner) : Cxcontainer::TcxContainer(AOwner) { }
	/* TcxContainer.Destroy */ inline __fastcall virtual ~TcxCustomEditContainer() { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomEditContainer(HWND ParentWindow) : Cxcontainer::TcxContainer(ParentWindow) { }
	
private:
	void *__IcxMouseTrackingCaller3;	// Dxcoreclasses::IcxMouseTrackingCaller3 
	void *__IcxMouseTrackingCaller2;	// Dxcoreclasses::IcxMouseTrackingCaller2 
	void *__IcxTransparentControl;	// Cxcontrols::IcxTransparentControl 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {94877AC7-D2D8-4F2B-8396-DF3CB45E01DF}
	operator Dxcoreclasses::_di_IcxMouseTrackingCaller3()
	{
		Dxcoreclasses::_di_IcxMouseTrackingCaller3 intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Dxcoreclasses::IcxMouseTrackingCaller3*(void) { return (Dxcoreclasses::IcxMouseTrackingCaller3*)&__IcxMouseTrackingCaller3; }
	#endif
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
	// {F4980C69-029E-4B14-B3AD-953DA5C18BE7}
	operator Cxcontrols::_di_IcxTransparentControl()
	{
		Cxcontrols::_di_IcxTransparentControl intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontrols::IcxTransparentControl*(void) { return (Cxcontrols::IcxTransparentControl*)&__IcxTransparentControl; }
	#endif
	
};


struct DECLSPEC_DRECORD TdxCachedSize
{
public:
	int Hash;
	System::Types::TSize Size;
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxEditAccessibilityHelper : public Cxaccessibility::TcxAccessibilityHelper
{
	typedef Cxaccessibility::TcxAccessibilityHelper inherited;
	
private:
	System::Classes::TList* FAccessibilityChildren;
	TcxCustomEdit* __fastcall GetEdit();
	TcxCustomEditViewInfo* __fastcall GetViewInfo();
	
protected:
	virtual bool __fastcall ChildIsSimpleElement(int AIndex);
	virtual Cxaccessibility::TcxAccessibilityHelper* __fastcall GetChild(int AIndex);
	virtual int __fastcall GetChildCount();
	virtual System::UnicodeString __fastcall GetName(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
	virtual HWND __fastcall GetOwnerObjectWindow();
	virtual int __fastcall GetRole(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
	virtual int __fastcall GetState(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
	virtual Cxaccessibility::TcxAccessibleObjectProperties __fastcall GetSupportedProperties(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
	virtual System::UnicodeString __fastcall GetValue(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
	virtual bool __fastcall IsExtended();
	void __fastcall AddAccessibilityChild(Cxaccessibility::_di_IcxAccessibilityHelper AChild);
	virtual void __fastcall DoButtonClick(int AVisibleIndex);
	virtual System::UnicodeString __fastcall GetButtonName(int AIndex);
	__property System::Classes::TList* AccessibilityChildren = {read=FAccessibilityChildren};
	__property TcxCustomEdit* Edit = {read=GetEdit};
	__property TcxCustomEditViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual TdxEditAccessibilityHelper(System::TObject* AOwnerObject);
	__fastcall virtual ~TdxEditAccessibilityHelper();
	virtual System::Types::TRect __fastcall GetScreenBounds(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
};

#pragma pack(pop)

typedef System::TMetaClass* TdxEditAccessibilityHelperClass;

class PASCALIMPLEMENTATION TcxCustomEdit : public TcxCustomEditContainer
{
	typedef TcxCustomEditContainer inherited;
	
	
private:
	typedef System::DynamicArray<TcxEditModifiedState> _TcxCustomEdit__1;
	
	
private:
	int FAnchorX;
	int FAnchorY;
	Vcl::Controls::TScalingFlags FAnchorScalingFlags;
	bool FAutoHeight;
	bool FAutoWidth;
	int FCaptureButtonVisibleIndex;
	TcxEditChangeEventsCatcher* FChangeEventsCatcher;
	int FClickLockCount;
	Cxclasses::TcxTimer* FDblClickTimer;
	TcxCustomEditData* FEditData;
	bool FEditModeSetting;
	bool FFocused;
	bool FHandleAllocating;
	Cxaccessibility::_di_IcxAccessibilityHelper FIAccessibilityHelper;
	_di_IcxCustomInnerEdit FInnerEdit;
	int FUserActionCount;
	int FUserActionDisabledCount;
	bool FModified;
	bool FModifiedAfterEnter;
	bool FNeedFocusOnClick;
	_TcxCustomEdit__1 FPrevModifiedList;
	System::Classes::TNotifyEvent FPropertiesEvents;
	TcxEditRepositoryItem* FRepositoryItem;
	bool FSupportsTouchMode;
	bool FUpdate;
	Cxcontrols::TcxWindowProcLinkedObject* FWindowProcObject;
	bool FIsBarControl;
	bool FIsContentParamsInitialized;
	bool FIsKeyPressHandled;
	bool FIsFirstSetSize;
	bool FIsHiding;
	bool FIsInplace;
	bool FIsInplaceInitializing;
	bool FIsJustCreated;
	bool FIsPosting;
	bool FIsEditValidated;
	bool FIsEditValidating;
	int FLockValidate;
	bool FValidateErrorProcessing;
	bool FValidationError;
	Vcl::Controls::TCaption FValidationErrorText;
	System::Variant FPrevEditValue;
	bool FPrevValidationError;
	int FEditValueChangingLockCount;
	Vcl::Controls::TKeyEvent FOnAfterKeyDown;
	TcxEditEditingEvent FOnEditing;
	System::Classes::TNotifyEvent FOnPostEditValue;
	bool __fastcall CheckButtonShortCuts(int AKey);
	void __fastcall DblClickTimerHandler(System::TObject* Sender);
	void __fastcall DoClearEditData(TcxCustomEditData* AEditData);
	TcxCustomEditProperties* __fastcall GetActiveProperties();
	bool __fastcall GetAutoSize();
	TcxCustomEditStyle* __fastcall GetEditActiveStyle();
	int __fastcall GetHeight();
	Cxaccessibility::_di_IcxAccessibilityHelper __fastcall GetIAccessibilityHelper();
	Cxaccessibility::_di_IcxAccessibilityHelper __fastcall GetIInnerEditAccessibilityHelper();
	HIDESBASE TcxCustomEditStyle* __fastcall GetInternalStyle(Cxcontainer::TcxContainerStateItem AState);
	HIDESBASE TcxEditStyle* __fastcall GetStyle();
	HIDESBASE TcxEditStyle* __fastcall GetStyleDisabled();
	HIDESBASE TcxEditStyle* __fastcall GetStyleFocused();
	HIDESBASE TcxEditStyle* __fastcall GetStyleHot();
	TcxCustomEditViewInfo* __fastcall GetViewInfo();
	void __fastcall HandleCutMessage();
	void __fastcall HandlePasteMessage();
	void __fastcall ReadAnchorX(System::Classes::TReader* Reader);
	void __fastcall ReadAnchorY(System::Classes::TReader* Reader);
	void __fastcall ReadHeight(System::Classes::TReader* Reader);
	void __fastcall ReadWidth(System::Classes::TReader* Reader);
	void __fastcall SetAutoHeight(bool AValue);
	void __fastcall SetAutoWidth(bool AValue);
	void __fastcall SetDataBinding(TcxEditDataBinding* Value);
	HIDESBASE void __fastcall SetHeight(int Value);
	HIDESBASE void __fastcall SetInternalStyle(Cxcontainer::TcxContainerStateItem AState, TcxCustomEditStyle* Value);
	void __fastcall SetInternalReadOnly(bool Value);
	void __fastcall SetModified(bool Value);
	void __fastcall SetModifiedAfterEnter(bool Value);
	void __fastcall SetModifiedAfterEnterValue(bool Value);
	void __fastcall SetPrevEditValue(const System::Variant &Value);
	void __fastcall SetProperties(TcxCustomEditProperties* Value);
	void __fastcall SetRepositoryItem(TcxEditRepositoryItem* Value);
	void __fastcall SetReplicatableFlag();
	HIDESBASE void __fastcall SetStyle(TcxEditStyle* Value);
	HIDESBASE void __fastcall SetStyleDisabled(TcxEditStyle* Value);
	HIDESBASE void __fastcall SetStyleFocused(TcxEditStyle* Value);
	HIDESBASE void __fastcall SetStyleHot(TcxEditStyle* Value);
	void __fastcall WriteAnchorX(System::Classes::TWriter* Writer);
	void __fastcall WriteAnchorY(System::Classes::TWriter* Writer);
	void __fastcall WriteHeight(System::Classes::TWriter* Writer);
	void __fastcall WriteWidth(System::Classes::TWriter* Writer);
	MESSAGE void __fastcall WMCopy(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall WMCut(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMHintShow(Vcl::Controls::TCMHintShow &Message);
	MESSAGE void __fastcall WMPaste(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMDialogChar(Winapi::Messages::TWMKey &Message);
	HIDESBASE MESSAGE void __fastcall CMEnter(Winapi::Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall CMShowingChanged(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall WMGetObject(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall DXMUpdateEditValue(Winapi::Messages::TMessage &Message);
	
protected:
	TcxEditDataBinding* FDataBinding;
	System::Variant FEditValue;
	TcxCustomEditProperties* FProperties;
	virtual bool __fastcall CanResize(int &NewWidth, int &NewHeight);
	virtual void __fastcall ChangeScaleEx(int M, int D, bool IsDPIChanged);
	DYNAMIC void __fastcall Click();
	virtual void __fastcall CreateHandle();
	DYNAMIC void __fastcall DblClick();
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	DYNAMIC void __fastcall DoEnter();
	DYNAMIC void __fastcall DoExit();
	DYNAMIC bool __fastcall DoMouseWheel(System::Classes::TShiftState Shift, int WheelDelta, const System::Types::TPoint &MousePos);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	DYNAMIC void __fastcall KeyUp(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall Loaded();
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall Paint();
	virtual void __fastcall ReadState(System::Classes::TReader* Reader);
	virtual void __fastcall RequestAlign();
	virtual void __fastcall SetName(const System::Classes::TComponentName Value);
	virtual void __fastcall SetParent(Vcl::Controls::TWinControl* AParent);
	virtual void __fastcall VisualRefinementsListenerChanged();
	virtual void __fastcall ScaleFactorChanged();
	virtual bool __fastcall CanContainerHandleTabs();
	virtual bool __fastcall CanFocusOnClick()/* overload */;
	virtual bool __fastcall DoInnerControlDefaultHandler(Winapi::Messages::TMessage &Message);
	virtual bool __fastcall DoRefreshContainer(const System::Types::TPoint &P, Cxcontainer::TcxMouseButton Button, System::Classes::TShiftState Shift, bool AIsMouseEvent);
	virtual void __fastcall DoSetSize();
	DYNAMIC void __fastcall FocusChanged();
	virtual Cxcontrols::TcxControlBackgroundStyle __fastcall GetBackgroundStyle();
	virtual System::Types::TRect __fastcall GetBorderExtent();
	virtual Cxlookandfeelpainters::TcxEditStateColorKind __fastcall GetEditStateColorKind();
	virtual System::UnicodeString __fastcall GetStatusHint(const System::Types::TPoint &APoint);
	virtual Cxcontainer::TcxContainerStyleClass __fastcall GetStyleClass();
	virtual Cxcontainer::TcxContainerViewInfoClass __fastcall GetViewInfoClass();
	virtual System::Types::TRect __fastcall GetWindowRegionAddon();
	virtual bool __fastcall GetPaintBlackOpaqueOnGlass();
	virtual Cxcontainer::TcxContainerStyleValues __fastcall InternalGetNotPublishedStyleValues();
	virtual bool __fastcall IsNativeStyle();
	virtual bool __fastcall IsReadOnly();
	virtual bool __fastcall IsTransparentBackground();
	virtual void __fastcall SafeSelectionFocusInnerControl();
	DYNAMIC void __fastcall TransparentChanged();
	virtual void __fastcall AcceleratorClick();
	virtual void __fastcall AdjustInnerEditPosition();
	virtual void __fastcall AfterPosting();
	virtual void __fastcall BeforePosting();
	int __fastcall ButtonVisibleIndexAt(const System::Types::TPoint &P);
	HIDESBASE void __fastcall CalculateViewInfo(bool AIsMouseEvent)/* overload */;
	HIDESBASE virtual void __fastcall CalculateViewInfo(const System::Types::TPoint &P, Cxcontainer::TcxMouseButton Button, System::Classes::TShiftState Shift, bool AIsMouseEvent)/* overload */;
	HIDESBASE void __fastcall CalculateViewInfo(TcxCustomEditViewInfo* AViewInfo, const System::Types::TPoint &P, Cxcontainer::TcxMouseButton Button, System::Classes::TShiftState Shift, bool AIsMouseEvent)/* overload */;
	virtual void __fastcall CalculateAnchors();
	virtual void __fastcall ChangeHandler(System::TObject* Sender);
	void __fastcall CheckAutoSizeChanges(bool AValue);
	void __fastcall CheckHandle();
	virtual _di_IcxCustomInnerEdit __fastcall CreateInnerEdit();
	virtual TcxCustomEditViewData* __fastcall CreateViewData();
	virtual void __fastcall DefaultButtonClick();
	void __fastcall DoAfterKeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall DoAutoSizeChanged();
	virtual void __fastcall DoButtonClick(int AButtonVisibleIndex);
	virtual void __fastcall DoButtonDown(int AButtonVisibleIndex);
	virtual void __fastcall DoButtonUp(int AButtonVisibleIndex);
	virtual void __fastcall DoChange();
	void __fastcall DoClick();
	void __fastcall DoClosePopup(TcxEditCloseUpReason AReason);
	virtual void __fastcall DoEditValueChanged();
	virtual void __fastcall DoEditKeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall DoEditKeyPress(System::WideChar &Key);
	virtual void __fastcall DoEditKeyUp(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall DoEditProcessTab(System::Classes::TShiftState Shift);
	virtual void __fastcall DoFocusChanged();
	virtual void __fastcall DoHideEdit(bool AExit);
	virtual void __fastcall DoOnChange();
	virtual void __fastcall DoOnEditValueChanged();
	void __fastcall DoPostEditValue();
	virtual void __fastcall DoProcessEventsOnViewInfoChanging();
	virtual void __fastcall DoSetFocusWhenActivate();
	virtual void __fastcall DoShowEdit();
	virtual void __fastcall DoValidateOnEnter();
	virtual void __fastcall EditingChanged();
	virtual System::Variant __fastcall GetClearValue();
	__classmethod virtual TcxEditDataBindingClass __fastcall GetDataBindingClass();
	int __fastcall GetDefaultButtonVisibleIndex();
	virtual System::UnicodeString __fastcall GetDisplayText();
	virtual System::Variant __fastcall GetDisplayValue();
	virtual TcxCustomEditDataClass __fastcall GetEditDataClass();
	virtual System::Variant __fastcall GetEditingValue();
	virtual System::Variant __fastcall GetEditValue();
	virtual System::UnicodeString __fastcall GetHintText(int APart);
	virtual Vcl::Controls::TControlClass __fastcall GetInnerEditClass();
	virtual bool __fastcall HandleMouseWheel(System::Classes::TShiftState Shift);
	virtual void __fastcall HidePopupWindowOnScroll();
	virtual bool __fastcall NeedAccessibilityHelper();
	virtual void __fastcall PopulateSizeProperties(TcxEditSizeProperties &AEditSizeProperties);
	virtual void __fastcall InitializeNonShareableProperties();
	virtual void __fastcall DisconnectNonShareableProperties();
	virtual void __fastcall Initialize();
	void __fastcall InitContentParams();
	virtual void __fastcall InitializeEditData();
	virtual void __fastcall InitializeInfoForHiddenInplaceEditor(TcxCustomEditViewData* AEditViewData, TcxCustomEditViewInfo* AEditViewInfo);
	virtual void __fastcall InitializeInnerEdit();
	virtual void __fastcall InitializeViewData(TcxCustomEditViewData* AViewData);
	virtual void __fastcall PrepareEditForInplaceActivation();
	virtual void __fastcall UpdateInfoForHiddenInplaceEditor(TcxCustomEditViewData* AViewData, TcxCustomEditViewInfo* AEditViewInfo);
	void __fastcall InternalCanResize(int &ANewWidth, int &ANewHeight);
	virtual bool __fastcall InternalDoEditing();
	TcxCustomEditProperties* __fastcall InternalGetActiveProperties();
	virtual System::Variant __fastcall InternalGetEditingValue();
	void __fastcall InternalPostEditValue(bool AValidateEdit = false);
	void __fastcall InternalPostValue();
	virtual void __fastcall InternalSetDisplayValue(const System::Variant &Value);
	virtual void __fastcall InternalSetEditValue(const System::Variant &Value, bool AValidateEditValue);
	virtual void __fastcall InternalStoreEditValue(const System::Variant &Value);
	HIDESBASE virtual bool __fastcall CanAutoSize();
	virtual bool __fastcall CanAutoHeight();
	virtual bool __fastcall CanAutoWidth();
	bool __fastcall IsAutoHeight();
	bool __fastcall IsAutoWidth();
	virtual bool __fastcall IsHeightDependOnWidth();
	bool __fastcall NeedStoreHeight();
	bool __fastcall NeedStoreWidth();
	virtual bool __fastcall CanKeyDownModifyEdit(System::Word Key, System::Classes::TShiftState Shift);
	virtual bool __fastcall CanKeyPressModifyEdit(System::WideChar Key);
	virtual bool __fastcall CanModify();
	bool __fastcall HasInnerEdit();
	virtual bool __fastcall IsActiveControl();
	virtual bool __fastcall IsButtonDC(NativeUInt ADC);
	virtual bool __fastcall IsClickEnabledDuringLoading();
	bool __fastcall IsDBEdit();
	bool __fastcall IsDBEditPaintCopyDrawing();
	bool __fastcall IsDefaultButtonKey(System::Classes::TShortCut AShortCut);
	virtual bool __fastcall IsDoubleBufferedNeeded();
	virtual bool __fastcall IsEditorKey(System::Word Key, System::Classes::TShiftState Shift);
	virtual bool __fastcall IsEditValueStored();
	virtual bool __fastcall IsNativeBackground();
	bool __fastcall IsOnChangeEventAssigned();
	bool __fastcall IsOnEditValueChangedEventAssigned();
	bool __fastcall IsResetEditClass();
	bool __fastcall IsSpecialKey(System::Word Key, System::Classes::TShiftState Shift);
	virtual bool __fastcall IsTransparent();
	virtual bool __fastcall IsValidChar(System::WideChar AChar);
	virtual bool __fastcall NeedsInvokeAfterKeyDown(System::Word AKey, System::Classes::TShiftState AShift);
	virtual bool __fastcall UseAnchors();
	virtual bool __fastcall UseAnchorX();
	virtual bool __fastcall UseAnchorY();
	void __fastcall BeginUserAction();
	void __fastcall EndUserAction();
	bool __fastcall IsUserAction();
	void __fastcall DisableUserAction();
	void __fastcall EnableUserAction();
	bool __fastcall IsUserActionDisabled();
	virtual bool __fastcall IsOnValidateEventAssigned();
	virtual bool __fastcall CanShowValidationErrorOnPostEditValue();
	void __fastcall DisableValidate();
	virtual void __fastcall DoOnValidate(System::Variant &ADisplayValue, Vcl::Controls::TCaption &AErrorText, bool &AError);
	virtual void __fastcall DoValidateDisplayValue(System::Variant &ADisplayValue, Vcl::Controls::TCaption &AErrorText, bool &AError);
	virtual System::Variant __fastcall InternalGetValueToValidate();
	virtual void __fastcall InternalValidateDisplayValue(const System::Variant &ADisplayValue);
	bool __fastcall InternalValidateEdit(TcxEditValidationOptions AValidationOptions, bool AForceValidation = false)/* overload */;
	bool __fastcall InternalValidateEdit(bool AForceValidation = false)/* overload */;
	virtual void __fastcall HandleValidationError(const System::UnicodeString AErrorText, TcxEditValidationOptions AValidationOptions, bool ACanAbortExecution);
	void __fastcall EnableValidate();
	virtual void __fastcall PaintCopyDraw();
	virtual void __fastcall PrepareDisplayValue(const System::Variant &AEditValue, System::Variant &DisplayValue, bool AEditFocused);
	virtual void __fastcall PrepareForInplaceActivation();
	virtual void __fastcall PropertiesChanged(System::TObject* Sender);
	bool __fastcall PropertiesChangeLocked();
	virtual bool __fastcall RealReadOnly();
	virtual void __fastcall RepositoryItemAssigned();
	virtual void __fastcall RepositoryItemAssigning();
	virtual void __fastcall ResetEditValue();
	void __fastcall ResetErrorState();
	void __fastcall RollBackErrorState();
	void __fastcall RestoreModified();
	void __fastcall SaveModified();
	virtual bool __fastcall SendActivationKey(System::WideChar Key);
	virtual bool __fastcall SetDisplayText(const System::UnicodeString Value);
	virtual void __fastcall SetEditAutoSize(bool AValue);
	virtual void __fastcall SetEditValue(const System::Variant &Value);
	virtual void __fastcall SetInternalEditValue(const System::Variant &Value);
	virtual void __fastcall SetInternalDisplayValue(const System::Variant &Value);
	virtual void __fastcall SynchronizeDisplayValue();
	virtual void __fastcall SynchronizeEditValue();
	virtual bool __fastcall TabsNeeded();
	virtual bool __fastcall UpdateContentOnFocusChanging();
	virtual void __fastcall UpdateDrawValue();
	void __fastcall UpdateInnerEditReadOnly();
	virtual bool __fastcall ValidateKeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual bool __fastcall ValidateKeyPress(System::WideChar &Key);
	virtual bool __fastcall WantNavigationKeys();
	virtual void __fastcall LockedInnerEditWindowProc(Winapi::Messages::TMessage &Message);
	virtual void __fastcall LockInnerEditRepainting();
	virtual void __fastcall UnlockInnerEditRepainting();
	void __fastcall IMEComposition(Winapi::Messages::TMessage &AMessage);
	void __fastcall IMEStartComposition();
	TcxCustomEditViewData* __fastcall GetViewData(/* out */ bool &AIsViewDataCreated);
	void __fastcall RepositoryItemListenerItemRemoved(TcxEditRepositoryItem* Sender);
	void __fastcall RepositoryItemListenerPropertiesChanged(TcxEditRepositoryItem* Sender);
	virtual bool __fastcall SupportsSpelling();
	virtual void __fastcall SpellCheckerSetIsBarControl(bool AValue);
	virtual void __fastcall SpellCheckerSetSelText(const System::UnicodeString AValue, bool APost = false);
	virtual void __fastcall SpellCheckerSetValue(const System::Variant &AValue);
	void __fastcall DisableTouchModeSupport();
	void __fastcall EnableTouchModeSupport();
	virtual bool __fastcall FadingCanFadeBackground();
	virtual void __fastcall FadingGetBackgroundImages(/* out */ Cxgraphics::TcxBitmap* &AFadeOutImage, /* out */ Cxgraphics::TcxBitmap* &AFadeInImage);
	void __fastcall FadingInvalidateBackground();
	virtual TdxEditAccessibilityHelperClass __fastcall GetAccessibilityHelperClass();
	__property TcxCustomEditStyle* ActiveStyle = {read=GetEditActiveStyle};
	__property int AnchorX = {read=FAnchorX, nodefault};
	__property int AnchorY = {read=FAnchorY, nodefault};
	__property bool AutoHeight = {read=FAutoHeight, write=SetAutoHeight, nodefault};
	__property bool AutoSize = {read=GetAutoSize, write=SetEditAutoSize, default=1};
	__property bool AutoWidth = {read=FAutoWidth, write=SetAutoWidth, nodefault};
	__property int CaptureButtonVisibleIndex = {read=FCaptureButtonVisibleIndex, write=FCaptureButtonVisibleIndex, nodefault};
	__property TcxEditChangeEventsCatcher* ChangeEventsCatcher = {read=FChangeEventsCatcher};
	__property TcxEditDataBinding* DataBinding = {read=FDataBinding, write=SetDataBinding};
	__property System::UnicodeString DisplayText = {read=GetDisplayText};
	__property System::Variant DisplayValue = {read=GetDisplayValue};
	__property TcxCustomEditData* EditData = {read=FEditData};
	__property bool EditModeSetting = {read=FEditModeSetting, nodefault};
	__property Cxaccessibility::_di_IcxAccessibilityHelper IAccessibilityHelper = {read=GetIAccessibilityHelper};
	__property _di_IcxCustomInnerEdit InnerEdit = {read=FInnerEdit};
	__property Cxaccessibility::_di_IcxAccessibilityHelper IInnerEditAccessibilityHelper = {read=GetIInnerEditAccessibilityHelper};
	__property bool IsEditValidated = {read=FIsEditValidated, write=FIsEditValidated, nodefault};
	__property bool IsInplaceInitializing = {read=FIsInplaceInitializing, nodefault};
	__property bool IsKeyPressHandled = {read=FIsKeyPressHandled, write=FIsKeyPressHandled, nodefault};
	__property bool NeedFocusOnClick = {read=FNeedFocusOnClick, write=FNeedFocusOnClick, nodefault};
	__property System::Variant PrevEditValue = {read=FPrevEditValue, write=SetPrevEditValue};
	__property TcxCustomEditProperties* Properties = {read=FProperties, write=SetProperties};
	__property bool SupportsTouchMode = {read=FSupportsTouchMode, write=FSupportsTouchMode, nodefault};
	__property bool ValidateErrorProcessing = {read=FValidateErrorProcessing, nodefault};
	
public:
	TcxEditContentParams ContentParams;
	TcxInplaceEditParams InplaceParams;
	__fastcall virtual TcxCustomEdit(System::Classes::TComponent* AOwner)/* overload */;
	__fastcall virtual TcxCustomEdit(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */;
	__fastcall virtual ~TcxCustomEdit();
	DYNAMIC bool __fastcall ExecuteAction(System::Classes::TBasicAction* Action);
	DYNAMIC void __fastcall GetTabOrderList(System::Classes::TList* List);
	virtual bool __fastcall InnerControlMenuHandler(Winapi::Messages::TMessage &Message);
	virtual bool __fastcall IsInplace();
	virtual bool __fastcall UpdateAction(System::Classes::TBasicAction* Action);
	virtual void __fastcall CopyToClipboard();
	virtual void __fastcall CutToClipboard();
	virtual void __fastcall PasteFromClipboard();
	virtual void __fastcall Activate(TcxCustomEditData* &AEditData, bool ANeedSetFocus = true);
	virtual void __fastcall ActivateByKey(System::WideChar Key, TcxCustomEditData* &AEditData);
	virtual void __fastcall ActivateByMouse(System::Classes::TShiftState Shift, int X, int Y, TcxCustomEditData* &AEditData);
	bool __fastcall AreChangeEventsLocked();
	bool __fastcall CanPostEditValue();
	virtual void __fastcall Clear();
	HIDESBASE virtual bool __fastcall Deactivate();
	bool __fastcall DoEditing();
	__classmethod virtual TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	virtual void __fastcall InitiateAction();
	bool __fastcall InternalFocused();
	virtual bool __fastcall IsChildWindow(NativeUInt AWnd);
	virtual bool __fastcall IsEditClass();
	virtual bool __fastcall IsRepositoryItemAcceptable(TcxEditRepositoryItem* ARepositoryItem);
	void __fastcall LockChangeEvents(bool ALock, bool AInvokeChangedOnUnlock = true);
	void __fastcall LockClick(bool ALock);
	void __fastcall LockEditValueChanging(bool ALock);
	void __fastcall PostEditValue();
	virtual void __fastcall PrepareEditValue(const System::Variant &ADisplayValue, /* out */ System::Variant &AEditValue, bool AEditFocused);
	void __fastcall Reset();
	virtual void __fastcall SelectAll();
	void __fastcall SetValidatableEditValue(const System::Variant &AEditValue);
	bool __fastcall ValidateEdit(bool ARaiseExceptionOnError)/* overload */;
	bool __fastcall ValidateEdit()/* overload */;
	virtual int __fastcall GetTextBaseLine();
	virtual bool __fastcall HasTextBaseLine();
	__property TcxCustomEditProperties* ActiveProperties = {read=GetActiveProperties};
	__property System::Variant EditingValue = {read=GetEditingValue};
	__property bool EditModified = {read=FModified, write=SetModified, nodefault};
	__property System::Variant EditValue = {read=GetEditValue, write=SetEditValue, stored=IsEditValueStored};
	__property System::Variant InternalEditValue = {read=GetEditValue, write=SetInternalEditValue, stored=false};
	__property TcxCustomEditProperties* InternalProperties = {read=FProperties};
	__property bool IsEditValidating = {read=FIsEditValidating, nodefault};
	__property bool IsHiding = {read=FIsHiding, nodefault};
	__property bool IsPosting = {read=FIsPosting, nodefault};
	__property bool ModifiedAfterEnter = {read=FModifiedAfterEnter, write=SetModifiedAfterEnter, nodefault};
	__property TcxEditStyle* Style = {read=GetStyle, write=SetStyle};
	__property TcxEditStyle* StyleDisabled = {read=GetStyleDisabled, write=SetStyleDisabled};
	__property TcxEditStyle* StyleFocused = {read=GetStyleFocused, write=SetStyleFocused};
	__property TcxEditStyle* StyleHot = {read=GetStyleHot, write=SetStyleHot};
	__property TcxCustomEditStyle* Styles[Cxcontainer::TcxContainerStateItem AState] = {read=GetInternalStyle, write=SetInternalStyle};
	__property TabStop = {default=1};
	__property TcxCustomEditViewInfo* ViewInfo = {read=GetViewInfo};
	__property OnClick;
	__property OnContextPopup;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
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
	__property Vcl::Controls::TKeyEvent OnAfterKeyDown = {read=FOnAfterKeyDown, write=FOnAfterKeyDown};
	__property TcxEditEditingEvent OnEditing = {read=FOnEditing, write=FOnEditing};
	__property System::Classes::TNotifyEvent OnPostEditValue = {read=FOnPostEditValue, write=FOnPostEditValue};
	
__published:
	__property int Height = {read=GetHeight, write=SetHeight, stored=false, nodefault};
	__property System::Classes::TNotifyEvent PropertiesEvents = {read=FPropertiesEvents, write=FPropertiesEvents};
	__property TcxEditRepositoryItem* RepositoryItem = {read=FRepositoryItem, write=SetRepositoryItem};
	__property Width = {stored=false};
	__property OnFocusChanged;
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomEdit(HWND ParentWindow) : TcxCustomEditContainer(ParentWindow) { }
	
	/* Hoisted overloads: */
	
protected:
	inline bool __fastcall  CanFocusOnClick(int X, int Y){ return Cxcontrols::TcxControl::CanFocusOnClick(X, Y); }
	
private:
	void *__IdxTouchModeSupport;	// Cxlookandfeels::IdxTouchModeSupport 
	void *__IcxEditOwner;	// IcxEditOwner 
	void *__IdxFadingObject;	// Dxfading::IdxFadingObject 
	void *__IdxSpellCheckerControl;	// Dxspellcheckercore::IdxSpellCheckerControl 
	void *__IdxSkinSupport;	// Cxlookandfeels::IdxSkinSupport 
	void *__IcxInplaceEditIMEHelper;	// IcxInplaceEditIMEHelper 
	void *__IcxEditRepositoryItemListener;	// IcxEditRepositoryItemListener 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {9107444B-867E-44C5-BF9A-DAB4EE879827}
	operator Cxlookandfeels::_di_IdxTouchModeSupport()
	{
		Cxlookandfeels::_di_IdxTouchModeSupport intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Cxlookandfeels::IdxTouchModeSupport*(void) { return (Cxlookandfeels::IdxTouchModeSupport*)&__IdxTouchModeSupport; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {4129100C-7FC6-436E-8711-47A5C978CA73}
	operator _di_IcxEditOwner()
	{
		_di_IcxEditOwner intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IcxEditOwner*(void) { return (IcxEditOwner*)&__IcxEditOwner; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {73AB2A92-CDD9-4F13-965A-DC799DE837F9}
	operator Dxfading::_di_IdxFadingObject()
	{
		Dxfading::_di_IdxFadingObject intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Dxfading::IdxFadingObject*(void) { return (Dxfading::IdxFadingObject*)&__IdxFadingObject; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {2DEA4CCA-3C6D-4283-9441-AABBD61F74F3}
	operator Dxspellcheckercore::_di_IdxSpellCheckerControl()
	{
		Dxspellcheckercore::_di_IdxSpellCheckerControl intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Dxspellcheckercore::IdxSpellCheckerControl*(void) { return (Dxspellcheckercore::IdxSpellCheckerControl*)&__IdxSpellCheckerControl; }
	#endif
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
	// {DC5EF4E1-2847-4950-854A-F8BFE29706F5}
	operator _di_IcxInplaceEditIMEHelper()
	{
		_di_IcxInplaceEditIMEHelper intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IcxInplaceEditIMEHelper*(void) { return (IcxInplaceEditIMEHelper*)&__IcxInplaceEditIMEHelper; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {4E27D642-022B-4CD2-AB96-64C7CF9B3299}
	operator _di_IcxEditRepositoryItemListener()
	{
		_di_IcxEditRepositoryItemListener intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IcxEditRepositoryItemListener*(void) { return (IcxEditRepositoryItemListener*)&__IcxEditRepositoryItemListener; }
	#endif
	
};


typedef System::TMetaClass* TcxCustomEditClass;

class PASCALIMPLEMENTATION TcxEditAlignment : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TcxEditVertAlignment FDefaultVertAlignment;
	System::Classes::TAlignment FHorz;
	System::Classes::TAlignment FDefaultHorzAlignment;
	bool FIsHorzAssigned;
	System::Classes::TPersistent* FOwner;
	TcxEditVertAlignment FVert;
	System::Classes::TNotifyEvent FOnChanged;
	void __fastcall SetHorz(const System::Classes::TAlignment Value);
	void __fastcall SetVert(const TcxEditVertAlignment Value);
	
protected:
	void __fastcall DoChanged();
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner();
	__property System::Classes::TNotifyEvent OnChanged = {read=FOnChanged, write=FOnChanged};
	
public:
	__fastcall virtual TcxEditAlignment(System::Classes::TPersistent* AOwner)/* overload */;
	__fastcall virtual TcxEditAlignment(System::Classes::TPersistent* AOwner, TcxEditVertAlignment ADefaultVertAlignment)/* overload */;
	__fastcall virtual TcxEditAlignment(System::Classes::TPersistent* AOwner, System::Classes::TAlignment ADefaultHorzAlignment, TcxEditVertAlignment ADefaultVertAlignment)/* overload */;
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	bool __fastcall IsHorzStored();
	bool __fastcall IsVertStored();
	void __fastcall Reset();
	
__published:
	__property System::Classes::TAlignment Horz = {read=FHorz, write=SetHorz, stored=IsHorzStored, nodefault};
	__property TcxEditVertAlignment Vert = {read=FVert, write=SetVert, stored=IsVertStored, nodefault};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxEditAlignment() { }
	
};


struct DECLSPEC_DRECORD TcxEditListItem
{
public:
	TcxCustomEdit* Edit;
	TcxCustomEditProperties* Properties;
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxInplaceEditList : public System::TObject
{
	typedef System::TObject inherited;
	
	
private:
	typedef System::DynamicArray<TcxEditListItem> _TcxInplaceEditList__1;
	
	
private:
	_TcxInplaceEditList__1 FItems;
	System::Classes::TComponent* FEditorOwner;
	TcxCustomEdit* __fastcall CreateEdit(TcxCustomEditPropertiesClass APropertiesClass);
	void __fastcall DestroyItems();
	int __fastcall FindItem(TcxCustomEditProperties* AProperties, bool ACanUseFreeEditors)/* overload */;
	int __fastcall FindItem(TcxCustomEditPropertiesClass APropertiesClass)/* overload */;
	int __fastcall GetCount();
	TcxCustomEdit* __fastcall GetEdit(int AItemIndex)/* overload */;
	void __fastcall InitEdit(TcxCustomEdit* AEdit, TcxCustomEditProperties* AProperties);
	void __fastcall RemoveItem(int AIndex)/* overload */;
	
protected:
	__property int Count = {read=GetCount, nodefault};
	__property System::Classes::TComponent* EditorOwner = {read=FEditorOwner};
	
public:
	__fastcall virtual TcxInplaceEditList(System::Classes::TComponent* AEditorOwner);
	__fastcall virtual ~TcxInplaceEditList();
	void __fastcall DisconnectProperties(TcxCustomEditProperties* AProperties);
	TcxCustomEdit* __fastcall FindEdit(TcxCustomEditProperties* AProperties)/* overload */;
	TcxCustomEdit* __fastcall FindEdit(TcxCustomEditPropertiesClass APropertiesClass)/* overload */;
	TcxCustomEdit* __fastcall GetEdit(TcxCustomEditProperties* AProperties)/* overload */;
	TcxCustomEdit* __fastcall GetEdit(TcxCustomEditPropertiesClass APropertiesClass)/* overload */;
	void __fastcall RemoveItem(TcxCustomEditProperties* AProperties)/* overload */;
	void __fastcall RemoveItem(TcxCustomEditPropertiesClass APropertiesClass)/* overload */;
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxDefaultEditStyleController : public Cxclasses::TcxScalableComponent
{
	typedef Cxclasses::TcxScalableComponent inherited;
	
private:
	bool __fastcall GetEmulateStandardControlDrawing();
	TcxCustomEditStyle* __fastcall GetInternalStyle(Cxcontainer::TcxContainerStateItem AState);
	System::Classes::TNotifyEvent __fastcall GetOnStyleChanged();
	TcxEditStyle* __fastcall GetStyle();
	TcxEditStyle* __fastcall GetStyleDisabled();
	TcxEditStyle* __fastcall GetStyleFocused();
	TcxEditStyle* __fastcall GetStyleHot();
	void __fastcall SetEmulateStandardControlDrawing(bool Value);
	void __fastcall SetInternalStyle(Cxcontainer::TcxContainerStateItem AState, TcxCustomEditStyle* Value);
	void __fastcall SetOnStyleChanged(System::Classes::TNotifyEvent Value);
	void __fastcall SetStyle(TcxEditStyle* Value);
	void __fastcall SetStyleDisabled(TcxEditStyle* Value);
	void __fastcall SetStyleFocused(TcxEditStyle* Value);
	void __fastcall SetStyleHot(TcxEditStyle* Value);
	
protected:
	virtual void __fastcall ChangeScale(int M, int D);
	
public:
	__fastcall virtual TcxDefaultEditStyleController(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxDefaultEditStyleController();
	void __fastcall RestoreStyles();
	__property TcxCustomEditStyle* Styles[Cxcontainer::TcxContainerStateItem AState] = {read=GetInternalStyle, write=SetInternalStyle};
	
__published:
	__property Scalable = {default=1};
	__property bool EmulateStandardControlDrawing = {read=GetEmulateStandardControlDrawing, write=SetEmulateStandardControlDrawing, default=0};
	__property TcxEditStyle* Style = {read=GetStyle, write=SetStyle};
	__property TcxEditStyle* StyleDisabled = {read=GetStyleDisabled, write=SetStyleDisabled};
	__property TcxEditStyle* StyleFocused = {read=GetStyleFocused, write=SetStyleFocused};
	__property TcxEditStyle* StyleHot = {read=GetStyleHot, write=SetStyleHot};
	__property System::Classes::TNotifyEvent OnStyleChanged = {read=GetOnStyleChanged, write=SetOnStyleChanged};
};


class PASCALIMPLEMENTATION TcxCustomEditingController : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	bool FEditingItemSetting;
	TcxInplaceEditList* FEditList;
	Cxclasses::TcxTimer* FEditShowingTimer;
	bool FEditUpdateNeeded;
	int FHideEditOnScrollContentCount;
	bool FInitiatingEditing;
	System::Classes::TNotifyEvent FPrevEditOnChange;
	System::Classes::TNotifyEvent FPrevEditOnEditValueChanged;
	void __fastcall EditShowingTimerHandler(System::TObject* Sender);
	TcxEditChangeEventsCatcher* __fastcall GetChangeEventsCatcher();
	void __fastcall ImmediateEventHandler(Cxcustomdata::TcxCustomDataController* ADataController);
	
protected:
	TcxCustomEdit* FEdit;
	bool FEditHiding;
	System::Types::TRect FEditPlaceBounds;
	bool FEditPreparing;
	bool FIsEditPlaced;
	bool FIsErrorOnPost;
	void __fastcall CancelEditUpdatePost();
	virtual bool __fastcall CanHideEdit();
	virtual bool __fastcall CanInitEditing() = 0 ;
	virtual bool __fastcall CanRemoveEditFocus();
	virtual bool __fastcall CanUpdateEditValue();
	void __fastcall CheckEditUpdatePost();
	virtual void __fastcall ClearEditingItem() = 0 ;
	void __fastcall ClearErrorState();
	void __fastcall CloseEdit();
	virtual void __fastcall DoEditChanged();
	virtual void __fastcall DoHideEdit(bool Accept) = 0 ;
	virtual void __fastcall DoHideEditOnScrollContent();
	virtual void __fastcall DoShowEditAfterScrollContent();
	virtual void __fastcall DoUpdateEdit() = 0 ;
	virtual bool __fastcall GetCancelEditingOnExit() = 0 ;
	virtual Vcl::Controls::TWinControl* __fastcall GetEditParent() = 0 ;
	virtual System::Types::TRect __fastcall GetFocusRectBounds();
	virtual System::Types::TRect __fastcall GetFocusedCellBounds() = 0 ;
	virtual bool __fastcall GetHideEditOnExit();
	virtual bool __fastcall GetHideEditOnFocusedRecordChange() = 0 ;
	virtual bool __fastcall GetIsEditing() = 0 ;
	bool __fastcall HasHiddenEditor();
	void __fastcall HideEditOnScrollContent();
	virtual void __fastcall HideInplaceEditor();
	virtual void __fastcall InitEdit();
	bool __fastcall IsEditVisible();
	bool __fastcall IsHiddenOnScrolling();
	virtual bool __fastcall IsNeedInvokeEditChangedEventsBeforePost();
	void __fastcall InvokeEditChangedEvents();
	virtual void __fastcall MultilineEditTextChanged();
	void __fastcall PostEditUpdate();
	virtual void __fastcall RecalculateEditViewInfo();
	void __fastcall ShowEditAfterScrollContent();
	virtual void __fastcall StartEditAutoHeight(bool AHeightChanged);
	virtual void __fastcall StartEditingByTimer() = 0 ;
	void __fastcall StartEditShowingTimer();
	virtual void __fastcall UninitEdit();
	virtual void __fastcall UpdateInplaceParamsPosition() = 0 ;
	virtual Cxcustomdata::TcxCustomDataController* __fastcall GetDataController();
	virtual System::Variant __fastcall GetValue() = 0 ;
	void __fastcall SetImmediatePostEventHandler(bool ASet);
	virtual void __fastcall SetValue(const System::Variant &AValue) = 0 ;
	void __fastcall UpdateEditValue();
	void __fastcall UpdateValue();
	virtual void __fastcall AssignOverridableEditEvents();
	virtual void __fastcall AssignStaticEditEvents();
	virtual void __fastcall UnassignEditEvents();
	virtual void __fastcall EditAfterKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall EditChanged(System::TObject* Sender);
	virtual void __fastcall EditDblClick(System::TObject* Sender);
	virtual void __fastcall EditEditing(System::TObject* Sender, bool &CanEdit);
	virtual void __fastcall EditExecuteAction(System::Classes::TBasicAction* Action, bool &Handled);
	virtual void __fastcall EditExit(System::TObject* Sender);
	virtual void __fastcall EditFocusChanged(System::TObject* Sender);
	virtual void __fastcall EditKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall EditKeyPress(System::TObject* Sender, System::WideChar &Key);
	virtual void __fastcall EditKeyUp(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall EditPostEditValue(System::TObject* Sender);
	virtual void __fastcall EditUpdateAction(System::Classes::TBasicAction* Action, bool &Handled);
	virtual void __fastcall EditValueChanged(System::TObject* Sender);
	__property TcxEditChangeEventsCatcher* ChangeEventsCatcher = {read=GetChangeEventsCatcher};
	__property bool EditHiding = {read=FEditHiding, nodefault};
	__property bool EditingItemSetting = {read=FEditingItemSetting, write=FEditingItemSetting, nodefault};
	__property TcxInplaceEditList* EditList = {read=FEditList};
	__property Cxclasses::TcxTimer* EditShowingTimer = {read=FEditShowingTimer};
	__property bool EditPreparing = {read=FEditPreparing, nodefault};
	__property bool EditUpdateNeeded = {read=FEditUpdateNeeded, nodefault};
	__property bool HideEditOnExit = {read=GetHideEditOnExit, nodefault};
	__property bool HideEditOnFocusedRecordChange = {read=GetHideEditOnFocusedRecordChange, nodefault};
	__property bool InitiatingEditing = {read=FInitiatingEditing, nodefault};
	__property bool IsEditPlaced = {read=FIsEditPlaced, nodefault};
	__property bool IsErrorOnPost = {read=FIsErrorOnPost, nodefault};
	
public:
	__fastcall TcxCustomEditingController(System::Classes::TComponent* AEditorOwner);
	__fastcall virtual ~TcxCustomEditingController();
	virtual bool __fastcall IMEComposition(Winapi::Messages::TMessage &AMessage);
	virtual bool __fastcall IMEStartComposition();
	virtual void __fastcall HideEdit(bool Accept);
	virtual void __fastcall RemoveEdit(TcxCustomEditProperties* AProperties);
	virtual void __fastcall ShowEdit() = 0 ;
	void __fastcall StopEditShowingTimer();
	void __fastcall UpdateEdit();
	__property TcxCustomEdit* Edit = {read=FEdit};
	__property System::Types::TRect FocusRectBounds = {read=GetFocusRectBounds};
	__property bool IsEditing = {read=GetIsEditing, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 cxEditDefaultPrecision = System::Int8(0xf);
static const bool cxEditDefaultUseLeftAlignmentOnEditing = true;
extern DELPHI_PACKAGE System::Classes::TAlignment cxEditDefaultHorzAlignment;
extern DELPHI_PACKAGE TcxEditVertAlignment cxEditDefaultVertAlignment;
static const System::Int8 cxInplaceEditOffset = System::Int8(0x1);
static const System::Int8 ekDefault = System::Int8(0x0);
static const System::Int8 svBorderColor = System::Int8(0x0);
static const System::Int8 svBorderStyle = System::Int8(0x1);
static const System::Int8 svColor = System::Int8(0x2);
static const System::Int8 svEdges = System::Int8(0x3);
static const System::Int8 svFont = System::Int8(0x4);
static const System::Int8 svHotTrack = System::Int8(0x5);
static const System::Int8 svShadow = System::Int8(0x6);
static const System::Int8 svTextColor = System::Int8(0x7);
static const System::Int8 svTextStyle = System::Int8(0x8);
static const System::Int8 svTransparentBorder = System::Int8(0x9);
static const System::Int8 svButtonStyle = System::Int8(0xa);
static const System::Int8 svButtonTransparency = System::Int8(0xb);
static const System::Int8 svPopupBorderStyle = System::Int8(0xc);
static const System::Int8 svGradientButtons = System::Int8(0xd);
static const System::Int8 svGradient = System::Int8(0xe);
static const System::Int8 svGradientDirection = System::Int8(0xf);
static const System::Int8 cxEditStyleValueCount = System::Int8(0x10);
extern DELPHI_PACKAGE Cxedit__1 cxEditStyleValueNameA;
extern DELPHI_PACKAGE System::StaticArray<System::Types::TRect, 2> EditContentDefaultOffsets;
extern DELPHI_PACKAGE System::StaticArray<Cxlookandfeelpainters::TcxEditBtnKind, 4> EditBtnKindToEditBtnPainterKind;
extern DELPHI_PACKAGE System::StaticArray<Cxlookandfeelpainters::TcxButtonState, 4> EditBtnStateToButtonState;
extern DELPHI_PACKAGE System::StaticArray<Cxlookandfeelpainters::TcxEditBtnPosition, 2> EditBtnPositionMap;
static const System::Int8 ecpNone = System::Int8(-3);
static const System::Int8 ecpErrorIcon = System::Int8(-2);
static const System::Int8 ecpControl = System::Int8(-1);
static const System::Int8 ecpButton = System::Int8(0x0);
extern DELPHI_PACKAGE TcxEditSizeProperties cxDefaultEditSizeProperties;
extern DELPHI_PACKAGE System::Classes::TShiftState __fastcall ButtonToShift(System::Uitypes::TMouseButton Button);
extern DELPHI_PACKAGE System::Classes::TShiftState __fastcall cxButtonToShift(Cxcontainer::TcxMouseButton Button);
extern DELPHI_PACKAGE void __fastcall cxCalculateTextSelectionColors(System::Uitypes::TColor &ATextSelectionColor, System::Uitypes::TColor &ATextSelectionBackgroundColor, System::Uitypes::TColor ABackgroundColor);
extern DELPHI_PACKAGE TcxCustomEditProperties* __fastcall cxGetScaledEditProperties(TcxCustomEditProperties* &AInternalProperties, TcxCustomEditProperties* AProperties, Cxgeometry::TdxScaleFactor* AScaleFactor, System::Classes::TPersistent* AOwner = (System::Classes::TPersistent*)(0x0));
extern DELPHI_PACKAGE bool __fastcall cxEditVarEquals(const System::Variant &V1, const System::Variant &V2);
extern DELPHI_PACKAGE TcxEditStyleController* __fastcall DefaultEditStyleController(void);
extern DELPHI_PACKAGE bool __fastcall EmulateStandardControlDrawing(void);
extern DELPHI_PACKAGE TcxEditRepository* __fastcall GetDefaultEditRepository(void);
extern DELPHI_PACKAGE System::Classes::TComponent* __fastcall GetOwnerComponent(System::Classes::TPersistent* APersistent);
extern DELPHI_PACKAGE Cxclasses::TcxRegisteredClasses* __fastcall GetRegisteredEditProperties(void);
extern DELPHI_PACKAGE System::TObject* __fastcall GetStandaloneEventSender(TcxCustomEdit* AEdit);
extern DELPHI_PACKAGE bool __fastcall InternalVarEqualsExact(const System::Variant &V1, const System::Variant &V2);
extern DELPHI_PACKAGE bool __fastcall IsSpaceChar(char C)/* overload */;
extern DELPHI_PACKAGE bool __fastcall IsSpaceChar(System::WideChar C)/* overload */;
extern DELPHI_PACKAGE bool __fastcall NeedAssignRepositoryItem(TcxCustomEditProperties* AItemProperties, TcxEditRepositoryItem* ARepositoryItem, TcxCustomEditProperties* &AEditingProperties);
extern DELPHI_PACKAGE void __fastcall SendMouseEvent(Vcl::Controls::TWinControl* AReceiver, unsigned AMessage, System::Classes::TShiftState AShift, const System::Types::TPoint &APoint);
extern DELPHI_PACKAGE void __fastcall SendKeyDown(Vcl::Controls::TWinControl* AReceiver, System::Word Key, System::Classes::TShiftState Shift);
extern DELPHI_PACKAGE void __fastcall SendKeyPress(Vcl::Controls::TWinControl* AReceiver, System::WideChar Key);
extern DELPHI_PACKAGE void __fastcall SendKeyUp(Vcl::Controls::TWinControl* AReceiver, System::Word Key, System::Classes::TShiftState Shift);
extern DELPHI_PACKAGE void __fastcall SetStandardControlDrawingEmulationMode(bool AEmulate);
extern DELPHI_PACKAGE void __fastcall UniteRegions(Cxgraphics::TcxRegion* ADestRgn, Cxgraphics::TcxRegion* ASrcRgn);
extern DELPHI_PACKAGE Dxgdiplusclasses::TdxSmartGlyph* __fastcall cxEditErrorIcon(void);
extern DELPHI_PACKAGE Dxgdiplusclasses::TdxSmartGlyph* __fastcall cxEditWarningIcon(void);
extern DELPHI_PACKAGE Dxgdiplusclasses::TdxSmartGlyph* __fastcall cxEditInfoIcon(void);
}	/* namespace Cxedit */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXEDIT)
using namespace Cxedit;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxeditHPP
