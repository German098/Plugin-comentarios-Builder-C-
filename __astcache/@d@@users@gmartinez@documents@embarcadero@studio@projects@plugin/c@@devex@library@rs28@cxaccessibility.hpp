// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxAccessibility.pas' rev: 35.00 (Windows)

#ifndef CxaccessibilityHPP
#define CxaccessibilityHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Types.hpp>
#include <Winapi.Windows.hpp>
#include <Winapi.ActiveX.hpp>
#include <System.Classes.hpp>
#include <Vcl.OleServer.hpp>
#include <Winapi.Messages.hpp>
#include <dxCore.hpp>
#include <dxCoreClasses.hpp>
#include <cxClasses.hpp>

//-- user supplied -----------------------------------------------------------
#include <OleIdl.h>

namespace Cxaccessibility
{
//-- forward type declarations -----------------------------------------------
__interface DELPHIINTERFACE IcxAccessible;
typedef System::DelphiInterface<IcxAccessible> _di_IcxAccessible;
__interface DELPHIINTERFACE IdxRawElementProviderSimple;
typedef System::DelphiInterface<IdxRawElementProviderSimple> _di_IdxRawElementProviderSimple;
__interface DELPHIINTERFACE IdxAccessibleEx;
typedef System::DelphiInterface<IdxAccessibleEx> _di_IdxAccessibleEx;
__interface DELPHIINTERFACE IcxAccessibilityHelper;
typedef System::DelphiInterface<IcxAccessibilityHelper> _di_IcxAccessibilityHelper;
__interface DELPHIINTERFACE IdxRangeValueProvider;
typedef System::DelphiInterface<IdxRangeValueProvider> _di_IdxRangeValueProvider;
__interface DELPHIINTERFACE IdxExpandCollapseProvider;
typedef System::DelphiInterface<IdxExpandCollapseProvider> _di_IdxExpandCollapseProvider;
__interface DELPHIINTERFACE IdxScrollItemProvider;
typedef System::DelphiInterface<IdxScrollItemProvider> _di_IdxScrollItemProvider;
__interface DELPHIINTERFACE IdxTextRangeProvider;
typedef System::DelphiInterface<IdxTextRangeProvider> _di_IdxTextRangeProvider;
struct TdxUiaPoint;
__interface DELPHIINTERFACE IdxTextProvider;
typedef System::DelphiInterface<IdxTextProvider> _di_IdxTextProvider;
__interface DELPHIINTERFACE IdxTextProvider2;
typedef System::DelphiInterface<IdxTextProvider2> _di_IdxTextProvider2;
__interface DELPHIINTERFACE IdxSelectionProvider;
typedef System::DelphiInterface<IdxSelectionProvider> _di_IdxSelectionProvider;
__interface DELPHIINTERFACE IdxSelectionItemProvider;
typedef System::DelphiInterface<IdxSelectionItemProvider> _di_IdxSelectionItemProvider;
__interface DELPHIINTERFACE IdxToggleProvider;
typedef System::DelphiInterface<IdxToggleProvider> _di_IdxToggleProvider;
class DELPHICLASS TdxChildAccessibleExPart;
class DELPHICLASS TcxAccessibilityHelper;
class DELPHICLASS TdxRangeValueProvider;
class DELPHICLASS TdxExpandCollapseProvider;
class DELPHICLASS TdxScrollItemProvider;
class DELPHICLASS TdxSelectionItemProvider;
class DELPHICLASS TdxToggleProvider;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TdxAccessiblePattern : unsigned char { apInvoke, apSelection, apValue, apRangeValue };

typedef System::Set<TdxAccessiblePattern, TdxAccessiblePattern::apInvoke, TdxAccessiblePattern::apRangeValue> TdxAccessiblePatterns;

typedef int TcxAccessibleSimpleChildElementID;

enum DECLSPEC_DENUM TcxAccessibleObjectProperty : unsigned char { aopDefaultAction, aopDescription, aopFocus, aopLocation, aopShortcut, aopValue, aopSelect };

typedef System::Set<TcxAccessibleObjectProperty, TcxAccessibleObjectProperty::aopDefaultAction, TcxAccessibleObjectProperty::aopSelect> TcxAccessibleObjectProperties;

enum DECLSPEC_DENUM TcxAccessibleObjectHitTest : unsigned char { aohtNone, aohtSelf, aohtChild };

enum DECLSPEC_DENUM TcxAccessibilityNavigationDirection : unsigned char { andLeft, andUp, andRight, andDown, andPrev, andNext };

__interface  INTERFACE_UUID("{618736E0-3C3D-11CF-810C-00AA00389B71}") IcxAccessible  : public IDispatch 
{
	virtual HRESULT __stdcall Get_accParent(/* out */ _di_IDispatch &ppdispParent) = 0 ;
	virtual HRESULT __stdcall Get_accChildCount(/* out */ int &pcountChildren) = 0 ;
	virtual HRESULT __stdcall Get_accChild(System::OleVariant varChild, /* out */ _di_IDispatch &ppdispChild) = 0 ;
	virtual HRESULT __stdcall Get_accName(System::OleVariant varChild, /* out */ System::WideString &pszName) = 0 ;
	virtual HRESULT __stdcall Get_accValue(System::OleVariant varChild, /* out */ System::WideString &pszValue) = 0 ;
	virtual HRESULT __stdcall Get_accDescription(System::OleVariant varChild, /* out */ System::WideString &pszDescription) = 0 ;
	virtual HRESULT __stdcall Get_accRole(System::OleVariant varChild, /* out */ System::OleVariant &pvarRole) = 0 ;
	virtual HRESULT __stdcall Get_accState(System::OleVariant varChild, /* out */ System::OleVariant &pvarState) = 0 ;
	virtual HRESULT __stdcall Get_accHelp(System::OleVariant varChild, /* out */ System::WideString &pszHelp) = 0 ;
	virtual HRESULT __stdcall Get_accHelpTopic(/* out */ System::WideString &pszHelpFile, System::OleVariant varChild, /* out */ int &pidTopic) = 0 ;
	virtual HRESULT __stdcall Get_accKeyboardShortcut(System::OleVariant varChild, /* out */ System::WideString &pszKeyboardShortcut) = 0 ;
	virtual HRESULT __stdcall Get_accFocus(/* out */ System::OleVariant &pvarChild) = 0 ;
	virtual HRESULT __stdcall Get_accSelection(/* out */ System::OleVariant &pvarChildren) = 0 ;
	virtual HRESULT __stdcall Get_accDefaultAction(System::OleVariant varChild, /* out */ System::WideString &pszDefaultAction) = 0 ;
	virtual HRESULT __stdcall accSelect(int flagsSelect, System::OleVariant varChild) = 0 ;
	virtual HRESULT __stdcall accLocation(/* out */ int &pxLeft, /* out */ int &pyTop, /* out */ int &pcxWidth, /* out */ int &pcyHeight, System::OleVariant varChild) = 0 ;
	virtual HRESULT __stdcall accNavigate(int navDir, System::OleVariant varStart, /* out */ System::OleVariant &pvarEndUpAt) = 0 ;
	virtual HRESULT __stdcall accHitTest(int xLeft, int yTop, /* out */ System::OleVariant &pvarChild) = 0 ;
	virtual HRESULT __stdcall accDoDefaultAction(System::OleVariant varChild) = 0 ;
	virtual HRESULT __stdcall Set_accName(System::OleVariant varChild, const System::WideString pszName) = 0 ;
	virtual HRESULT __stdcall Set_accValue(System::OleVariant varChild, const System::WideString pszValue) = 0 ;
};

__interface  INTERFACE_UUID("{D6DD68D1-86FD-4332-8666-9ABEDEA2D24C}") IdxRawElementProviderSimple  : public System::IInterface 
{
	virtual HRESULT __stdcall Get_ProviderOptions(/* out */ Winapi::Activex::TOleEnum &pRetVal) = 0 ;
	virtual HRESULT __stdcall GetPatternProvider(int patternId, /* out */ System::_di_IInterface &pRetVal) = 0 ;
	virtual HRESULT __stdcall GetPropertyValue(int propertyId, /* out */ System::OleVariant &pRetVal) = 0 ;
	virtual HRESULT __stdcall Get_HostRawElementProvider(/* out */ _di_IdxRawElementProviderSimple &pRetVal) = 0 ;
};

__interface  INTERFACE_UUID("{F8B80ADA-2C44-48D0-89BE-5FF23C9CD875}") IdxAccessibleEx  : public System::IInterface 
{
	virtual HRESULT __stdcall GetObjectForChild(int idChild, /* out */ _di_IdxAccessibleEx &pRetVal) = 0 ;
	virtual HRESULT __stdcall GetIAccessiblePair(/* out */ _di_IcxAccessible &ppAcc, /* out */ int &pidChild) = 0 ;
	virtual HRESULT __stdcall GetRuntimeId(/* out */ Winapi::Activex::PSafeArray &pRetVal) = 0 ;
	virtual HRESULT __stdcall ConvertReturnedElement(const _di_IdxRawElementProviderSimple pIn, /* out */ _di_IdxAccessibleEx &ppRetValOut) = 0 ;
};

__interface  INTERFACE_UUID("{D4890860-09B2-4648-BD9E-DFFBD140E5F1}") IcxAccessibilityHelper  : public System::IInterface 
{
	virtual TcxAccessibilityHelper* __fastcall GetHelper() = 0 ;
	virtual void __fastcall OwnerObjectDestroyed() = 0 ;
};

__interface  INTERFACE_UUID("{36DC7AEF-33E6-4691-AFE1-2BE7274B3D33}") IdxRangeValueProvider  : public System::IInterface 
{
	virtual HRESULT __stdcall SetValue(double val) = 0 ;
	virtual HRESULT __stdcall Get_Value(/* out */ double &pRetVal) = 0 ;
	virtual HRESULT __stdcall Get_IsReadOnly(/* out */ int &pRetVal) = 0 ;
	virtual HRESULT __stdcall Get_Maximum(/* out */ double &pRetVal) = 0 ;
	virtual HRESULT __stdcall Get_Minimum(/* out */ double &pRetVal) = 0 ;
	virtual HRESULT __stdcall Get_LargeChange(/* out */ double &pRetVal) = 0 ;
	virtual HRESULT __stdcall Get_SmallChange(/* out */ double &pRetVal) = 0 ;
};

__interface  INTERFACE_UUID("{D847D3A5-CAB0-4A98-8C32-ECB45C59AD24}") IdxExpandCollapseProvider  : public System::IInterface 
{
	virtual HRESULT __stdcall Expand() = 0 ;
	virtual HRESULT __stdcall Collapse() = 0 ;
	virtual HRESULT __stdcall Get_ExpandCollapseState(/* out */ Winapi::Activex::TOleEnum &pRetVal) = 0 ;
};

__interface  INTERFACE_UUID("{2360C714-4BF1-4B26-BA65-9B21316127EB}") IdxScrollItemProvider  : public System::IInterface 
{
	virtual HRESULT __stdcall ScrollIntoView() = 0 ;
};

__interface  INTERFACE_UUID("{5347AD7B-C355-46F8-AFF5-909033582F63}") IdxTextRangeProvider  : public System::IInterface 
{
	virtual HRESULT __stdcall Clone(/* out */ _di_IdxTextRangeProvider &pRetVal) = 0 ;
	virtual HRESULT __stdcall Compare(const _di_IdxTextRangeProvider range, /* out */ int &pRetVal) = 0 ;
	virtual HRESULT __stdcall CompareEndpoints(Winapi::Activex::TOleEnum endpoint, const _di_IdxTextRangeProvider targetRange, Winapi::Activex::TOleEnum targetEndpoint, /* out */ int &pRetVal) = 0 ;
	virtual HRESULT __stdcall ExpandToEnclosingUnit(Winapi::Activex::TOleEnum unit_) = 0 ;
	virtual HRESULT __stdcall FindAttribute(int attributeId, System::OleVariant val, int backward, /* out */ _di_IdxTextRangeProvider &pRetVal) = 0 ;
	virtual HRESULT __stdcall FindText(const System::WideString text, int backward, int ignoreCase, /* out */ _di_IdxTextRangeProvider &pRetVal) = 0 ;
	virtual HRESULT __stdcall GetAttributeValue(int attributeId, /* out */ System::OleVariant &pRetVal) = 0 ;
	virtual HRESULT __stdcall GetBoundingRectangles(/* out */ Winapi::Activex::PSafeArray &pRetVal) = 0 ;
	virtual HRESULT __stdcall GetEnclosingElement(/* out */ _di_IdxRawElementProviderSimple &pRetVal) = 0 ;
	virtual HRESULT __stdcall GetText(int maxLength, /* out */ System::WideString &pRetVal) = 0 ;
	virtual HRESULT __stdcall Move(Winapi::Activex::TOleEnum unit_, int count, /* out */ int &pRetVal) = 0 ;
	virtual HRESULT __stdcall MoveEndpointByUnit(Winapi::Activex::TOleEnum endpoint, Winapi::Activex::TOleEnum unit_, int count, /* out */ int &pRetVal) = 0 ;
	virtual HRESULT __stdcall MoveEndpointByRange(Winapi::Activex::TOleEnum endpoint, const _di_IdxTextRangeProvider targetRange, Winapi::Activex::TOleEnum targetEndpoint) = 0 ;
	virtual HRESULT __stdcall Select() = 0 ;
	virtual HRESULT __stdcall AddToSelection() = 0 ;
	virtual HRESULT __stdcall RemoveFromSelection() = 0 ;
	virtual HRESULT __stdcall ScrollIntoView(int alignToTop) = 0 ;
	virtual HRESULT __stdcall GetChildren(/* out */ Winapi::Activex::PSafeArray &pRetVal) = 0 ;
};

struct DECLSPEC_DRECORD TdxUiaPoint
{
public:
	double x;
	double y;
};


__interface  INTERFACE_UUID("{3589C92C-63F3-4367-99BB-ADA653B77CF2}") IdxTextProvider  : public System::IInterface 
{
	virtual HRESULT __stdcall GetSelection(/* out */ Winapi::Activex::PSafeArray &pRetVal) = 0 ;
	virtual HRESULT __stdcall GetVisibleRanges(/* out */ Winapi::Activex::PSafeArray &pRetVal) = 0 ;
	virtual HRESULT __stdcall RangeFromChild(const _di_IdxRawElementProviderSimple childElement, /* out */ _di_IdxTextRangeProvider &pRetVal) = 0 ;
	virtual HRESULT __stdcall RangeFromPoint(TdxUiaPoint point, /* out */ _di_IdxTextRangeProvider &pRetVal) = 0 ;
	virtual HRESULT __stdcall Get_DocumentRange(/* out */ _di_IdxTextRangeProvider &pRetVal) = 0 ;
	virtual HRESULT __stdcall Get_SupportedTextSelection(/* out */ Winapi::Activex::TOleEnum &pRetVal) = 0 ;
};

__interface  INTERFACE_UUID("{0DC5E6ED-3E16-4BF1-8F9A-A979878BC195}") IdxTextProvider2  : public System::IInterface 
{
	virtual HRESULT __stdcall RangeFromAnnotation(const _di_IdxRawElementProviderSimple annotationElement, /* out */ _di_IdxTextRangeProvider &pRetVal) = 0 ;
	virtual HRESULT __stdcall GetCaretRange(/* out */ int &isActive, /* out */ _di_IdxTextRangeProvider &pRetVal) = 0 ;
};

__interface  INTERFACE_UUID("{FB8B03AF-3BDF-48D4-BD36-1A65793BE168}") IdxSelectionProvider  : public System::IInterface 
{
	virtual HRESULT __stdcall GetSelection(/* out */ Winapi::Activex::PSafeArray &pRetVal) = 0 ;
	virtual HRESULT __stdcall Get_CanSelectMultiple(/* out */ int &pRetVal) = 0 ;
	virtual HRESULT __stdcall Get_IsSelectionRequired(/* out */ int &pRetVal) = 0 ;
};

__interface  INTERFACE_UUID("{2ACAD808-B2D4-452D-A407-91FF1AD167B2}") IdxSelectionItemProvider  : public System::IInterface 
{
	virtual HRESULT __stdcall Select() = 0 ;
	virtual HRESULT __stdcall AddToSelection() = 0 ;
	virtual HRESULT __stdcall RemoveFromSelection() = 0 ;
	virtual HRESULT __stdcall Get_IsSelected(/* out */ int &pRetVal) = 0 ;
	virtual HRESULT __stdcall Get_SelectionContainer(/* out */ _di_IdxRawElementProviderSimple &pRetVal) = 0 ;
};

__interface  INTERFACE_UUID("{56D00BD0-C4F4-433C-A836-1A52A57E0892}") IdxToggleProvider  : public System::IInterface 
{
	virtual HRESULT __stdcall Toggle() = 0 ;
	virtual HRESULT __stdcall Get_ToggleState(/* out */ Winapi::Activex::TOleEnum &pRetVal) = 0 ;
};

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxChildAccessibleExPart : public System::TInterfacedObject
{
	typedef System::TInterfacedObject inherited;
	
private:
	_di_IcxAccessibilityHelper FIAccessibilityHelper;
	int FIndex;
	HRESULT __stdcall GetObjectForChild(int idChild, /* out */ _di_IdxAccessibleEx &pRetVal);
	HRESULT __stdcall GetIAccessiblePair(/* out */ _di_IcxAccessible &ppAcc, /* out */ int &pidChild);
	HRESULT __stdcall GetRuntimeId(/* out */ Winapi::Activex::PSafeArray &pRetVal);
	HRESULT __stdcall ConvertReturnedElement(const _di_IdxRawElementProviderSimple pIn, /* out */ _di_IdxAccessibleEx &ppRetValOut);
	HRESULT __stdcall Get_ProviderOptions(/* out */ Winapi::Activex::TOleEnum &pRetVal);
	HRESULT __stdcall GetPatternProvider(int patternId, /* out */ System::_di_IInterface &pRetVal);
	HRESULT __stdcall GetPropertyValue(int propertyId, /* out */ System::OleVariant &pRetVal);
	HRESULT __stdcall Get_HostRawElementProvider(/* out */ _di_IdxRawElementProviderSimple &pRetVal);
	
public:
	__fastcall virtual TdxChildAccessibleExPart(_di_IcxAccessibilityHelper AOwner, int AIndex);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxChildAccessibleExPart() { }
	
private:
	void *__IdxRawElementProviderSimple;	// IdxRawElementProviderSimple 
	void *__IdxAccessibleEx;	// IdxAccessibleEx 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {D6DD68D1-86FD-4332-8666-9ABEDEA2D24C}
	operator _di_IdxRawElementProviderSimple()
	{
		_di_IdxRawElementProviderSimple intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IdxRawElementProviderSimple*(void) { return (IdxRawElementProviderSimple*)&__IdxRawElementProviderSimple; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {F8B80ADA-2C44-48D0-89BE-5FF23C9CD875}
	operator _di_IdxAccessibleEx()
	{
		_di_IdxAccessibleEx intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IdxAccessibleEx*(void) { return (IdxAccessibleEx*)&__IdxAccessibleEx; }
	#endif
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxAccessibilityHelper : public System::TInterfacedObject
{
	typedef System::TInterfacedObject inherited;
	
private:
	bool FIsOwnerObjectLive;
	_di_IcxAccessible FInternalChild;
	bool FLock;
	HRESULT __stdcall GetIDsOfNames(const GUID &IID, void * Names, int NameCount, int LocaleID, void * DispIDs);
	HRESULT __stdcall GetTypeInfo(int Index, int LocaleID, /* out */ void *TypeInfo);
	HRESULT __stdcall GetTypeInfoCount(/* out */ int &Count);
	HRESULT __stdcall Invoke(int DispID, const GUID &IID, int LocaleID, System::Word Flags, void *Params, void * VarResult, void * ExcepInfo, void * ArgErr);
	HRESULT __stdcall ContextSensitiveHelp(System::LongBool fEnterMode);
	HRESULT __stdcall GetWindow(/* out */ HWND &wnd);
	HRESULT __stdcall accDoDefaultAction(System::OleVariant varChild);
	HRESULT __stdcall accHitTest(int xLeft, int yTop, /* out */ System::OleVariant &pvarChild);
	HRESULT __stdcall accLocation(/* out */ int &pxLeft, /* out */ int &pyTop, /* out */ int &pcxWidth, /* out */ int &pcyHeight, System::OleVariant varChild);
	HRESULT __stdcall accNavigate(int navDir, System::OleVariant varStart, /* out */ System::OleVariant &pvarEndUpAt);
	HRESULT __stdcall accSelect(int flagsSelect, System::OleVariant varChild);
	HRESULT __stdcall Get_accChild(System::OleVariant varChild, /* out */ _di_IDispatch &ppdispChild);
	HRESULT __stdcall Get_accChildCount(/* out */ int &pcountChildren);
	HRESULT __stdcall Get_accDefaultAction(System::OleVariant varChild, /* out */ System::WideString &pszDefaultAction);
	HRESULT __stdcall Get_accDescription(System::OleVariant varChild, /* out */ System::WideString &pszDescription);
	HRESULT __stdcall Get_accFocus(/* out */ System::OleVariant &pvarChild);
	HRESULT __stdcall Get_accHelp(System::OleVariant varChild, /* out */ System::WideString &pszHelp);
	HRESULT __stdcall Get_accHelpTopic(/* out */ System::WideString &pszHelpFile, System::OleVariant varChild, /* out */ int &pidTopic);
	HRESULT __stdcall Get_accKeyboardShortcut(System::OleVariant varChild, /* out */ System::WideString &pszKeyboardShortcut);
	HRESULT __stdcall Get_accName(System::OleVariant varChild, /* out */ System::WideString &pszName);
	HRESULT __stdcall Get_accParent(/* out */ _di_IDispatch &ppdispParent);
	HRESULT __stdcall Get_accRole(System::OleVariant varChild, /* out */ System::OleVariant &pvarRole);
	HRESULT __stdcall Get_accSelection(/* out */ System::OleVariant &pvarChildren);
	HRESULT __stdcall Get_accState(System::OleVariant varChild, /* out */ System::OleVariant &pvarState);
	HRESULT __stdcall Get_accValue(System::OleVariant varChild, /* out */ System::WideString &pszValue);
	HRESULT __stdcall Set_accName(System::OleVariant varChild, const System::WideString pszName);
	HRESULT __stdcall Set_accValue(System::OleVariant varChild, const System::WideString pszValue);
	HRESULT __stdcall QueryService(const GUID &rsid, const GUID &iid, /* out */ void *Obj);
	HRESULT __stdcall GetObjectForChild(int idChild, /* out */ _di_IdxAccessibleEx &pRetVal);
	HRESULT __stdcall GetIAccessiblePair(/* out */ _di_IcxAccessible &ppAcc, /* out */ int &pidChild);
	HRESULT __stdcall GetRuntimeId(/* out */ Winapi::Activex::PSafeArray &pRetVal);
	HRESULT __stdcall ConvertReturnedElement(const _di_IdxRawElementProviderSimple pIn, /* out */ _di_IdxAccessibleEx &ppRetValOut);
	HRESULT __stdcall Get_ProviderOptions(/* out */ Winapi::Activex::TOleEnum &pRetVal);
	HRESULT __stdcall GetPatternProvider(int patternId, /* out */ System::_di_IInterface &pRetVal);
	HRESULT __stdcall GetPropertyValue(int propertyId, /* out */ System::OleVariant &pRetVal);
	HRESULT __stdcall Get_HostRawElementProvider(/* out */ _di_IdxRawElementProviderSimple &pRetVal);
	bool __fastcall CheckIsOwnerObjectLive(/* out */ HRESULT &AErrorCode);
	void __fastcall CheckSimpleChildElementToBeReturned(System::OleVariant &AVarChild);
	void __fastcall CheckStringToBeReturned(const System::WideString AStr, /* out */ HRESULT &AResult);
	bool __fastcall GetSimpleChildElementID(const System::OleVariant &AChildID, /* out */ TcxAccessibleSimpleChildElementID &ASimpleChildElementID, /* out */ HRESULT &AErrorCode);
	bool __fastcall GetVisible();
	
protected:
	System::TObject* FOwnerObject;
	void __fastcall SetInternalChild(HWND AHandle);
	TcxAccessibilityHelper* __fastcall GetHelper();
	virtual void __fastcall OwnerObjectDestroyed();
	virtual bool __fastcall ChildIsSimpleElement(int AIndex);
	virtual void __fastcall DoDefaultAction(TcxAccessibleSimpleChildElementID AChildID);
	virtual void __fastcall DoSelect(int AFlags, TcxAccessibleSimpleChildElementID AChildID);
	virtual bool __fastcall Focused(/* out */ bool &AIsChildFocused, /* out */ int &AFocusedChildIndex);
	virtual TcxAccessibilityHelper* __fastcall GetChild(int AIndex);
	virtual int __fastcall GetChildCount();
	virtual int __fastcall GetChildIndex(TcxAccessibilityHelper* AChild);
	virtual System::UnicodeString __fastcall GetDefaultActionDescription(TcxAccessibleSimpleChildElementID AChildID);
	virtual System::UnicodeString __fastcall GetDescription(TcxAccessibleSimpleChildElementID AChildID);
	virtual TcxAccessibleObjectHitTest __fastcall GetHitTest(int AScreenX, int AScreenY, /* out */ int &AChildIndex)/* overload */;
	virtual bool __fastcall GetHitTest(int AScreenX, int AScreenY, /* out */ _di_IcxAccessibilityHelper &AIAccessibilityHelper)/* overload */;
	virtual void __fastcall GetKeyboardAccessParameters(TcxAccessibleSimpleChildElementID AChildID, /* out */ System::Classes::TShortCut &AShortCut, /* out */ System::UnicodeString &ACaptionWithAccelChars);
	virtual System::UnicodeString __fastcall GetName(TcxAccessibleSimpleChildElementID AChildID);
	virtual HWND __fastcall GetOwnerObjectWindow();
	virtual TcxAccessibilityHelper* __fastcall GetParent();
	virtual int __fastcall GetRole(TcxAccessibleSimpleChildElementID AChildID);
	virtual bool __fastcall GetSelectable();
	virtual int __fastcall GetState(TcxAccessibleSimpleChildElementID AChildID);
	virtual TcxAccessibleObjectProperties __fastcall GetSupportedProperties(TcxAccessibleSimpleChildElementID AChildID);
	virtual System::UnicodeString __fastcall GetValue(TcxAccessibleSimpleChildElementID AChildID);
	virtual int __fastcall NavigateToChild(int ACurrentChildIndex, TcxAccessibilityNavigationDirection ADirection);
	virtual void __fastcall SetValue(TcxAccessibleSimpleChildElementID AChildID, const System::UnicodeString Value);
	virtual bool __fastcall IsExtended();
	virtual bool __fastcall IsSupportedPattern(int APatternID, /* out */ System::_di_IInterface &AProvider, TcxAccessibleSimpleChildElementID AChildID = (TcxAccessibleSimpleChildElementID)(0x0));
	virtual int __fastcall GetLocalId(TcxAccessibleSimpleChildElementID AChildID = (TcxAccessibleSimpleChildElementID)(0x0));
	virtual System::OleVariant __fastcall GetRawElementPropertyValue(int propertyId, TcxAccessibleSimpleChildElementID AChildID = (TcxAccessibleSimpleChildElementID)(0x0));
	TcxAccessibilityHelper* __fastcall GetRootHelper();
	__property bool Lock = {read=FLock, nodefault};
	
public:
	int __fastcall GetNextSelectableChildIndex(int AStartIndex, bool AGoForward);
	virtual System::Types::TRect __fastcall GetScreenBounds(TcxAccessibleSimpleChildElementID AChildID);
	__fastcall virtual TcxAccessibilityHelper(System::TObject* AOwnerObject);
	__fastcall virtual ~TcxAccessibilityHelper();
	__property TcxAccessibilityHelper* Childs[int AIndex] = {read=GetChild};
	__property int ChildCount = {read=GetChildCount, nodefault};
	__property bool IsOwnerObjectLive = {read=FIsOwnerObjectLive, nodefault};
	__property System::TObject* OwnerObject = {read=FOwnerObject};
	__property HWND OwnerObjectWindow = {read=GetOwnerObjectWindow, nodefault};
	__property TcxAccessibilityHelper* Parent = {read=GetParent};
	__property bool Selectable = {read=GetSelectable, nodefault};
	__property int States[TcxAccessibleSimpleChildElementID AChildID] = {read=GetState};
	__property int Role[TcxAccessibleSimpleChildElementID AChildID] = {read=GetRole};
	__property bool Visible = {read=GetVisible, nodefault};
private:
	void *__IdxRawElementProviderSimple;	// IdxRawElementProviderSimple 
	void *__IdxAccessibleEx;	// IdxAccessibleEx 
	void *__IServiceProvider;	// IServiceProvider 
	void *__IcxAccessibilityHelper;	// IcxAccessibilityHelper 
	void *__IcxAccessible;	// IcxAccessible 
	void *__IOleWindow;	// IOleWindow 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {D6DD68D1-86FD-4332-8666-9ABEDEA2D24C}
	operator _di_IdxRawElementProviderSimple()
	{
		_di_IdxRawElementProviderSimple intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IdxRawElementProviderSimple*(void) { return (IdxRawElementProviderSimple*)&__IdxRawElementProviderSimple; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {F8B80ADA-2C44-48D0-89BE-5FF23C9CD875}
	operator _di_IdxAccessibleEx()
	{
		_di_IdxAccessibleEx intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IdxAccessibleEx*(void) { return (IdxAccessibleEx*)&__IdxAccessibleEx; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {6D5140C1-7436-11CE-8034-00AA006009FA}
	operator _di_IServiceProvider()
	{
		_di_IServiceProvider intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IServiceProvider*(void) { return (IServiceProvider*)&__IServiceProvider; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {D4890860-09B2-4648-BD9E-DFFBD140E5F1}
	operator _di_IcxAccessibilityHelper()
	{
		_di_IcxAccessibilityHelper intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IcxAccessibilityHelper*(void) { return (IcxAccessibilityHelper*)&__IcxAccessibilityHelper; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {618736E0-3C3D-11CF-810C-00AA00389B71}
	operator _di_IcxAccessible()
	{
		_di_IcxAccessible intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IcxAccessible*(void) { return (IcxAccessible*)&__IcxAccessible; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00000114-0000-0000-C000-000000000046}
	operator _di_IOleWindow()
	{
		_di_IOleWindow intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IOleWindow*(void) { return (IOleWindow*)&__IOleWindow; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00020400-0000-0000-C000-000000000046}
	operator _di_IDispatch()
	{
		_di_IDispatch intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IDispatch*(void) { return (IDispatch*)&__IcxAccessible; }
	#endif
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRangeValueProvider : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	HRESULT __stdcall InternalSetValue(double val);
	HRESULT __stdcall Get_IsReadOnly(/* out */ int &pRetVal);
	HRESULT __stdcall Get_LargeChange(/* out */ double &pRetVal);
	HRESULT __stdcall Get_Maximum(/* out */ double &pRetVal);
	HRESULT __stdcall Get_Minimum(/* out */ double &pRetVal);
	HRESULT __stdcall Get_SmallChange(/* out */ double &pRetVal);
	HRESULT __stdcall Get_Value(/* out */ double &pRetVal);
	
protected:
	virtual bool __fastcall GetIsReadOnly();
	virtual double __fastcall GetLargeChange();
	virtual double __fastcall GetMaximum();
	virtual double __fastcall GetMinimum();
	virtual double __fastcall GetSmallChange();
	virtual double __fastcall GetValue();
	virtual void __fastcall SetValue(double AValue);
public:
	/* TObject.Create */ inline __fastcall TdxRangeValueProvider() : Dxcoreclasses::TcxIUnknownObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxRangeValueProvider() { }
	
private:
	void *__IdxRangeValueProvider;	// IdxRangeValueProvider 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {36DC7AEF-33E6-4691-AFE1-2BE7274B3D33}
	operator _di_IdxRangeValueProvider()
	{
		_di_IdxRangeValueProvider intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IdxRangeValueProvider*(void) { return (IdxRangeValueProvider*)&__IdxRangeValueProvider; }
	#endif
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxExpandCollapseProvider : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	HRESULT __stdcall InternalCollapse();
	HRESULT __stdcall InternalExpand();
	HRESULT __stdcall Get_ExpandCollapseState(/* out */ Winapi::Activex::TOleEnum &pRetVal);
	
protected:
	virtual void __fastcall Collapse();
	virtual void __fastcall Expand();
	virtual int __fastcall GetExpandCollapseState();
public:
	/* TObject.Create */ inline __fastcall TdxExpandCollapseProvider() : Dxcoreclasses::TcxIUnknownObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxExpandCollapseProvider() { }
	
private:
	void *__IdxExpandCollapseProvider;	// IdxExpandCollapseProvider 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {D847D3A5-CAB0-4A98-8C32-ECB45C59AD24}
	operator _di_IdxExpandCollapseProvider()
	{
		_di_IdxExpandCollapseProvider intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IdxExpandCollapseProvider*(void) { return (IdxExpandCollapseProvider*)&__IdxExpandCollapseProvider; }
	#endif
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxScrollItemProvider : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	HRESULT __stdcall ScrollIntoView();
	
protected:
	virtual void __fastcall DoScrollIntoView();
public:
	/* TObject.Create */ inline __fastcall TdxScrollItemProvider() : Dxcoreclasses::TcxIUnknownObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxScrollItemProvider() { }
	
private:
	void *__IdxScrollItemProvider;	// IdxScrollItemProvider 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {2360C714-4BF1-4B26-BA65-9B21316127EB}
	operator _di_IdxScrollItemProvider()
	{
		_di_IdxScrollItemProvider intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IdxScrollItemProvider*(void) { return (IdxScrollItemProvider*)&__IdxScrollItemProvider; }
	#endif
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSelectionItemProvider : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	HRESULT __stdcall InternalAddToSelection();
	HRESULT __stdcall InternalRemoveFromSelection();
	HRESULT __stdcall Select();
	HRESULT __stdcall Get_IsSelected(/* out */ int &pRetVal);
	HRESULT __stdcall Get_SelectionContainer(/* out */ _di_IdxRawElementProviderSimple &pRetVal);
	
protected:
	virtual void __fastcall DoSelect();
	virtual void __fastcall AddToSelection();
	virtual _di_IdxRawElementProviderSimple __fastcall GetSelectionContainer();
	virtual bool __fastcall IsSelected();
	virtual void __fastcall RemoveFromSelection();
public:
	/* TObject.Create */ inline __fastcall TdxSelectionItemProvider() : Dxcoreclasses::TcxIUnknownObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSelectionItemProvider() { }
	
private:
	void *__IdxSelectionItemProvider;	// IdxSelectionItemProvider 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {2ACAD808-B2D4-452D-A407-91FF1AD167B2}
	operator _di_IdxSelectionItemProvider()
	{
		_di_IdxSelectionItemProvider intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IdxSelectionItemProvider*(void) { return (IdxSelectionItemProvider*)&__IdxSelectionItemProvider; }
	#endif
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxToggleProvider : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	HRESULT __stdcall Toggle();
	HRESULT __stdcall Get_ToggleState(/* out */ Winapi::Activex::TOleEnum &pRetVal);
	
protected:
	virtual void __fastcall DoToggle();
	virtual int __fastcall GetToggleState();
public:
	/* TObject.Create */ inline __fastcall TdxToggleProvider() : Dxcoreclasses::TcxIUnknownObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxToggleProvider() { }
	
private:
	void *__IdxToggleProvider;	// IdxToggleProvider 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {56D00BD0-C4F4-433C-A836-1A52A57E0892}
	operator _di_IdxToggleProvider()
	{
		_di_IdxToggleProvider intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IdxToggleProvider*(void) { return (IdxToggleProvider*)&__IdxToggleProvider; }
	#endif
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxAccessibilityHelperClass;

//-- var, const, procedure ---------------------------------------------------
static const System::Int8 cxAccessibleObjectSelfID = System::Int8(0x0);
#define SID_IcxAccessible L"{618736E0-3C3D-11CF-810C-00AA00389B71}"
extern DELPHI_PACKAGE GUID IID_IcxAccessible;
#define SID_IdxRawElementProviderSimple L"{D6DD68D1-86FD-4332-8666-9ABEDEA2D24C}"
extern DELPHI_PACKAGE GUID IID_IdxRawElementProviderSimple;
#define SID_IdxAccessibleEx L"{F8B80ADA-2C44-48D0-89BE-5FF23C9CD875}"
extern DELPHI_PACKAGE GUID IID_IdxAccessibleEx;
#define SID_IdxRangeValueProvider L"{36DC7AEF-33E6-4691-AFE1-2BE7274B3D33}"
extern DELPHI_PACKAGE GUID IID_IdxRangeValueProvider;
#define SID_IdxRawElementProviderSimple2 L"{A0A839A9-8DA1-4A82-806A-8E0D44E79F56}"
extern DELPHI_PACKAGE GUID IID_IdxRawElementProviderSimple2;
#define SID_IdxRawElementProviderSimple3 L"{FCF5D820-D7EC-4613-BDF6-42A84CE7DAAF}"
extern DELPHI_PACKAGE GUID IID_IdxRawElementProviderSimple3;
#define SID_IdxRawElementProviderFragmentRoot L"{620CE2A5-AB8F-40A9-86CB-DE3C75599B58}"
extern DELPHI_PACKAGE GUID IID_IdxRawElementProviderFragmentRoot;
#define SID_IdxRawElementProviderFragment L"{F7063DA8-8359-439C-9297-BBC5299A7D87}"
extern DELPHI_PACKAGE GUID IID_IdxRawElementProviderFragment;
#define SID_IdxRawElementProviderAdviseEvents L"{A407B27B-0F6D-4427-9292-473C7BF93258}"
extern DELPHI_PACKAGE GUID IID_IdxRawElementProviderAdviseEvents;
#define SID_IdxRawElementProviderHwndOverride L"{1D5DF27C-8947-4425-B8D9-79787BB460B8}"
extern DELPHI_PACKAGE GUID IID_IdxRawElementProviderHwndOverride;
#define SID_IdxProxyProviderWinEventSink L"{4FD82B78-A43E-46AC-9803-0A6969C7C183}"
extern DELPHI_PACKAGE GUID IID_IdxProxyProviderWinEventSink;
#define SID_IdxProxyProviderWinEventHandler L"{89592AD4-F4E0-43D5-A3B6-BAD7E111B435}"
extern DELPHI_PACKAGE GUID IID_IdxProxyProviderWinEventHandler;
#define SID_IdxRawElementProviderWindowlessSite L"{0A2A93CC-BFAD-42AC-9B2E-0991FB0D3EA0}"
extern DELPHI_PACKAGE GUID IID_IdxRawElementProviderWindowlessSite;
#define SID_IdxAccessibleHostingElementProviders L"{33AC331B-943E-4020-B295-DB37784974A3}"
extern DELPHI_PACKAGE GUID IID_IdxAccessibleHostingElementProviders;
#define SID_IdxDockProvider L"{159BC72C-4AD3-485E-9637-D7052EDF0146}"
extern DELPHI_PACKAGE GUID IID_IdxDockProvider;
#define SID_IdxExpandCollapseProvider L"{D847D3A5-CAB0-4A98-8C32-ECB45C59AD24}"
extern DELPHI_PACKAGE GUID IID_IdxExpandCollapseProvider;
#define SID_IdxGridProvider L"{B17D6187-0907-464B-A168-0EF17A1572B1}"
extern DELPHI_PACKAGE GUID IID_IdxGridProvider;
#define SID_IdxGridItemProvider L"{D02541F1-FB81-4D64-AE32-F520F8A6DBD1}"
extern DELPHI_PACKAGE GUID IID_IdxGridItemProvider;
#define SID_IdxInvokeProvider L"{54FCB24B-E18E-47A2-B4D3-ECCBE77599A2}"
extern DELPHI_PACKAGE GUID IID_IdxInvokeProvider;
#define SID_IdxMultipleViewProvider L"{6278CAB1-B556-4A1A-B4E0-418ACC523201}"
extern DELPHI_PACKAGE GUID IID_IdxMultipleViewProvider;
#define SID_IdxScrollItemProvider L"{2360C714-4BF1-4B26-BA65-9B21316127EB}"
extern DELPHI_PACKAGE GUID IID_IdxScrollItemProvider;
#define SID_IdxSelectionProvider L"{FB8B03AF-3BDF-48D4-BD36-1A65793BE168}"
extern DELPHI_PACKAGE GUID IID_IdxSelectionProvider;
#define SID_IdxScrollProvider L"{B38B8077-1FC3-42A5-8CAE-D40C2215055A}"
extern DELPHI_PACKAGE GUID IID_IdxScrollProvider;
#define SID_IdxSelectionItemProvider L"{2ACAD808-B2D4-452D-A407-91FF1AD167B2}"
extern DELPHI_PACKAGE GUID IID_IdxSelectionItemProvider;
#define SID_IdxSynchronizedInputProvider L"{29DB1A06-02CE-4CF7-9B42-565D4FAB20EE}"
extern DELPHI_PACKAGE GUID IID_IdxSynchronizedInputProvider;
#define SID_IdxTableProvider L"{9C860395-97B3-490A-B52A-858CC22AF166}"
extern DELPHI_PACKAGE GUID IID_IdxTableProvider;
#define SID_IdxTableItemProvider L"{B9734FA6-771F-4D78-9C90-2517999349CD}"
extern DELPHI_PACKAGE GUID IID_IdxTableItemProvider;
#define SID_IdxToggleProvider L"{56D00BD0-C4F4-433C-A836-1A52A57E0892}"
extern DELPHI_PACKAGE GUID IID_IdxToggleProvider;
#define SID_IdxTransformProvider L"{6829DDC4-4F91-4FFA-B86F-BD3E2987CB4C}"
extern DELPHI_PACKAGE GUID IID_IdxTransformProvider;
#define SID_IdxValueProvider L"{C7935180-6FB3-4201-B174-7DF73ADBF64A}"
extern DELPHI_PACKAGE GUID IID_IdxValueProvider;
#define SID_IdxWindowProvider L"{987DF77B-DB06-4D77-8F8A-86A9C3BB90B9}"
extern DELPHI_PACKAGE GUID IID_IdxWindowProvider;
#define SID_IdxLegacyIAccessibleProvider L"{E44C3566-915D-4070-99C6-047BFF5A08F5}"
extern DELPHI_PACKAGE GUID IID_IdxLegacyIAccessibleProvider;
#define SID_IdxItemContainerProvider L"{E747770B-39CE-4382-AB30-D8FB3F336F24}"
extern DELPHI_PACKAGE GUID IID_IdxItemContainerProvider;
#define SID_IdxVirtualizedItemProvider L"{CB98B665-2D35-4FAC-AD35-F3C60D0C0B8B}"
extern DELPHI_PACKAGE GUID IID_IdxVirtualizedItemProvider;
#define SID_IdxObjectModelProvider L"{3AD86EBD-F5EF-483D-BB18-B1042A475D64}"
extern DELPHI_PACKAGE GUID IID_IdxObjectModelProvider;
#define SID_IdxAnnotationProvider L"{F95C7E80-BD63-4601-9782-445EBFF011FC}"
extern DELPHI_PACKAGE GUID IID_IdxAnnotationProvider;
#define SID_IdxStylesProvider L"{19B6B649-F5D7-4A6D-BDCB-129252BE588A}"
extern DELPHI_PACKAGE GUID IID_IdxStylesProvider;
#define SID_IdxSpreadsheetProvider L"{6F6B5D35-5525-4F80-B758-85473832FFC7}"
extern DELPHI_PACKAGE GUID IID_IdxSpreadsheetProvider;
#define SID_IdxSpreadsheetItemProvider L"{EAED4660-7B3D-4879-A2E6-365CE603F3D0}"
extern DELPHI_PACKAGE GUID IID_IdxSpreadsheetItemProvider;
#define SID_IdxTransformProvider2 L"{4758742F-7AC2-460C-BC48-09FC09308A93}"
extern DELPHI_PACKAGE GUID IID_IdxTransformProvider2;
#define SID_IdxDragProvider L"{6AA7BBBB-7FF9-497D-904F-D20B897929D8}"
extern DELPHI_PACKAGE GUID IID_IdxDragProvider;
#define SID_IdxDropTargetProvider L"{BAE82BFD-358A-481C-85A0-D8B4D90A5D61}"
extern DELPHI_PACKAGE GUID IID_IdxDropTargetProvider;
#define SID_IdxTextRangeProvider L"{5347AD7B-C355-46F8-AFF5-909033582F63}"
extern DELPHI_PACKAGE GUID IID_IdxTextRangeProvider;
#define SID_IdxTextProvider L"{3589C92C-63F3-4367-99BB-ADA653B77CF2}"
extern DELPHI_PACKAGE GUID IID_IdxTextProvider;
#define SID_IdxTextProvider2 L"{0DC5E6ED-3E16-4BF1-8F9A-A979878BC195}"
extern DELPHI_PACKAGE GUID IID_IdxTextProvider2;
#define SID_IdxTextEditProvider L"{EA3605B4-3A05-400E-B5F9-4E91B40F6176}"
extern DELPHI_PACKAGE GUID IID_IdxTextEditProvider;
#define SID_IdxTextRangeProvider2 L"{9BBCE42C-1921-4F18-89CA-DBA1910A0386}"
extern DELPHI_PACKAGE GUID IID_IdxTextRangeProvider2;
#define SID_IdxTextChildProvider L"{4C2DE2B9-C88F-4F88-A111-F1D336B7D1A9}"
extern DELPHI_PACKAGE GUID IID_IdxTextChildProvider;
#define SID_IdxCustomNavigationProvider L"{2062A28A-8C07-4B94-8E12-7037C622AEB8}"
extern DELPHI_PACKAGE GUID IID_IdxCustomNavigationProvider;
#define SID_IdxUIAutomationPatternInstance L"{C03A7FE4-9431-409F-BED8-AE7C2299BC8D}"
extern DELPHI_PACKAGE GUID IID_IdxUIAutomationPatternInstance;
#define SID_IdxUIAutomationPatternHandler L"{D97022F3-A947-465E-8B2A-AC4315FA54E8}"
extern DELPHI_PACKAGE GUID IID_IdxUIAutomationPatternHandler;
#define SID_IdxUIAutomationRegistrar L"{8609C4EC-4A1A-4D88-A357-5A66E060E1CF}"
extern DELPHI_PACKAGE GUID IID_IdxUIAutomationRegistrar;
static const System::Int8 dxProviderOptions_ClientSideProvider = System::Int8(0x1);
static const System::Int8 dxProviderOptions_ServerSideProvider = System::Int8(0x2);
static const System::Int8 dxProviderOptions_NonClientAreaProvider = System::Int8(0x4);
static const System::Int8 dxProviderOptions_OverrideProvider = System::Int8(0x8);
static const System::Int8 dxProviderOptions_ProviderOwnsSetFocus = System::Int8(0x10);
static const System::Int8 dxProviderOptions_UseComThreading = System::Int8(0x20);
static const System::Int8 dxProviderOptions_RefuseNonClientSupport = System::Int8(0x40);
static const System::Byte dxProviderOptions_HasNativeIAccessible = System::Byte(0x80);
static const System::Word dxProviderOptions_UseClientCoordinates = System::Word(0x100);
static const System::Int8 dxExpandCollapseState_Collapsed = System::Int8(0x0);
static const System::Int8 dxExpandCollapseState_Expanded = System::Int8(0x1);
static const System::Int8 dxExpandCollapseState_PartiallyExpanded = System::Int8(0x2);
static const System::Int8 dxExpandCollapseState_LeafNode = System::Int8(0x3);
static const System::Int8 cxROLE_SYSTEM_TITLEBAR = System::Int8(0x1);
static const System::Int8 cxROLE_SYSTEM_MENUBAR = System::Int8(0x2);
static const System::Int8 cxROLE_SYSTEM_SCROLLBAR = System::Int8(0x3);
static const System::Int8 cxROLE_SYSTEM_GRIP = System::Int8(0x4);
static const System::Int8 cxROLE_SYSTEM_SOUND = System::Int8(0x5);
static const System::Int8 cxROLE_SYSTEM_CURSOR = System::Int8(0x6);
static const System::Int8 cxROLE_SYSTEM_CARET = System::Int8(0x7);
static const System::Int8 cxROLE_SYSTEM_ALERT = System::Int8(0x8);
static const System::Int8 cxROLE_SYSTEM_WINDOW = System::Int8(0x9);
static const System::Int8 cxROLE_SYSTEM_CLIENT = System::Int8(0xa);
static const System::Int8 cxROLE_SYSTEM_MENUPOPUP = System::Int8(0xb);
static const System::Int8 cxROLE_SYSTEM_MENUITEM = System::Int8(0xc);
static const System::Int8 cxROLE_SYSTEM_TOOLTIP = System::Int8(0xd);
static const System::Int8 cxROLE_SYSTEM_APPLICATION = System::Int8(0xe);
static const System::Int8 cxROLE_SYSTEM_DOCUMENT = System::Int8(0xf);
static const System::Int8 cxROLE_SYSTEM_PANE = System::Int8(0x10);
static const System::Int8 cxROLE_SYSTEM_CHART = System::Int8(0x11);
static const System::Int8 cxROLE_SYSTEM_DIALOG = System::Int8(0x12);
static const System::Int8 cxROLE_SYSTEM_BORDER = System::Int8(0x13);
static const System::Int8 cxROLE_SYSTEM_GROUPING = System::Int8(0x14);
static const System::Int8 cxROLE_SYSTEM_SEPARATOR = System::Int8(0x15);
static const System::Int8 cxROLE_SYSTEM_TOOLBAR = System::Int8(0x16);
static const System::Int8 cxROLE_SYSTEM_STATUSBAR = System::Int8(0x17);
static const System::Int8 cxROLE_SYSTEM_TABLE = System::Int8(0x18);
static const System::Int8 cxROLE_SYSTEM_COLUMNHEADER = System::Int8(0x19);
static const System::Int8 cxROLE_SYSTEM_ROWHEADER = System::Int8(0x1a);
static const System::Int8 cxROLE_SYSTEM_COLUMN = System::Int8(0x1b);
static const System::Int8 cxROLE_SYSTEM_ROW = System::Int8(0x1c);
static const System::Int8 cxROLE_SYSTEM_CELL = System::Int8(0x1d);
static const System::Int8 cxROLE_SYSTEM_LINK = System::Int8(0x1e);
static const System::Int8 cxROLE_SYSTEM_HELPBALLOON = System::Int8(0x1f);
static const System::Int8 cxROLE_SYSTEM_CHARACTER = System::Int8(0x20);
static const System::Int8 cxROLE_SYSTEM_LIST = System::Int8(0x21);
static const System::Int8 cxROLE_SYSTEM_LISTITEM = System::Int8(0x22);
static const System::Int8 cxROLE_SYSTEM_OUTLINE = System::Int8(0x23);
static const System::Int8 cxROLE_SYSTEM_OUTLINEITEM = System::Int8(0x24);
static const System::Int8 cxROLE_SYSTEM_PAGETAB = System::Int8(0x25);
static const System::Int8 cxROLE_SYSTEM_PROPERTYPAGE = System::Int8(0x26);
static const System::Int8 cxROLE_SYSTEM_INDICATOR = System::Int8(0x27);
static const System::Int8 cxROLE_SYSTEM_GRAPHIC = System::Int8(0x28);
static const System::Int8 cxROLE_SYSTEM_STATICTEXT = System::Int8(0x29);
static const System::Int8 cxROLE_SYSTEM_TEXT = System::Int8(0x2a);
static const System::Int8 cxROLE_SYSTEM_PUSHBUTTON = System::Int8(0x2b);
static const System::Int8 cxROLE_SYSTEM_CHECKBUTTON = System::Int8(0x2c);
static const System::Int8 cxROLE_SYSTEM_RADIOBUTTON = System::Int8(0x2d);
static const System::Int8 cxROLE_SYSTEM_COMBOBOX = System::Int8(0x2e);
static const System::Int8 cxROLE_SYSTEM_DROPLIST = System::Int8(0x2f);
static const System::Int8 cxROLE_SYSTEM_PROGRESSBAR = System::Int8(0x30);
static const System::Int8 cxROLE_SYSTEM_DIAL = System::Int8(0x31);
static const System::Int8 cxROLE_SYSTEM_HOTKEYFIELD = System::Int8(0x32);
static const System::Int8 cxROLE_SYSTEM_SLIDER = System::Int8(0x33);
static const System::Int8 cxROLE_SYSTEM_SPINBUTTON = System::Int8(0x34);
static const System::Int8 cxROLE_SYSTEM_DIAGRAM = System::Int8(0x35);
static const System::Int8 cxROLE_SYSTEM_ANIMATION = System::Int8(0x36);
static const System::Int8 cxROLE_SYSTEM_EQUATION = System::Int8(0x37);
static const System::Int8 cxROLE_SYSTEM_BUTTONDROPDOWN = System::Int8(0x38);
static const System::Int8 cxROLE_SYSTEM_BUTTONMENU = System::Int8(0x39);
static const System::Int8 cxROLE_SYSTEM_BUTTONDROPDOWNGRID = System::Int8(0x3a);
static const System::Int8 cxROLE_SYSTEM_WHITESPACE = System::Int8(0x3b);
static const System::Int8 cxROLE_SYSTEM_PAGETABLIST = System::Int8(0x3c);
static const System::Int8 cxROLE_SYSTEM_CLOCK = System::Int8(0x3d);
static const System::Int8 cxROLE_SYSTEM_SPLITBUTTON = System::Int8(0x3e);
static const System::Int8 cxROLE_SYSTEM_IPADDRESS = System::Int8(0x3f);
static const System::Int8 cxROLE_SYSTEM_OUTLINEBUTTON = System::Int8(0x40);
static const System::Int8 cxSTATE_SYSTEM_NORMAL = System::Int8(0x0);
static const System::Int8 cxSTATE_SYSTEM_UNAVAILABLE = System::Int8(0x1);
static const System::Int8 cxSTATE_SYSTEM_SELECTED = System::Int8(0x2);
static const System::Int8 cxSTATE_SYSTEM_FOCUSED = System::Int8(0x4);
static const System::Int8 cxSTATE_SYSTEM_PRESSED = System::Int8(0x8);
static const System::Int8 cxSTATE_SYSTEM_CHECKED = System::Int8(0x10);
static const System::Int8 cxSTATE_SYSTEM_MIXED = System::Int8(0x20);
static const System::Int8 cxSTATE_SYSTEM_INDETERMINATE = System::Int8(0x20);
static const System::Int8 cxSTATE_SYSTEM_READONLY = System::Int8(0x40);
static const System::Byte cxSTATE_SYSTEM_HOTTRACKED = System::Byte(0x80);
static const System::Word cxSTATE_SYSTEM_DEFAULT = System::Word(0x100);
static const System::Word cxSTATE_SYSTEM_EXPANDED = System::Word(0x200);
static const System::Word cxSTATE_SYSTEM_COLLAPSED = System::Word(0x400);
static const System::Word cxSTATE_SYSTEM_BUSY = System::Word(0x800);
static const System::Word cxSTATE_SYSTEM_FLOATING = System::Word(0x1000);
static const System::Word cxSTATE_SYSTEM_MARQUEED = System::Word(0x2000);
static const System::Word cxSTATE_SYSTEM_ANIMATED = System::Word(0x4000);
static const System::Word cxSTATE_SYSTEM_INVISIBLE = System::Word(0x8000);
static const int cxSTATE_SYSTEM_OFFSCREEN = int(0x10000);
static const int cxSTATE_SYSTEM_SIZEABLE = int(0x20000);
static const int cxSTATE_SYSTEM_MOVEABLE = int(0x40000);
static const int cxSTATE_SYSTEM_SELFVOICING = int(0x80000);
static const int cxSTATE_SYSTEM_FOCUSABLE = int(0x100000);
static const int cxSTATE_SYSTEM_SELECTABLE = int(0x200000);
static const int cxSTATE_SYSTEM_LINKED = int(0x400000);
static const int cxSTATE_SYSTEM_TRAVERSED = int(0x800000);
static const int cxSTATE_SYSTEM_MULTISELECTABLE = int(0x1000000);
static const int cxSTATE_SYSTEM_EXTSELECTABLE = int(0x2000000);
static const int cxSTATE_SYSTEM_ALERT_LOW = int(0x4000000);
static const int cxSTATE_SYSTEM_ALERT_MEDIUM = int(0x8000000);
static const int cxSTATE_SYSTEM_ALERT_HIGH = int(0x10000000);
static const int cxSTATE_SYSTEM_PROTECTED = int(0x20000000);
static const int cxSTATE_SYSTEM_VALID = int(0x7fffffff);
static const int cxSTATE_SYSTEM_HASPOPUP = int(0x40000000);
static const System::Int8 cxSELFLAG_TAKEFOCUS = System::Int8(0x1);
static const System::Int8 cxSELFLAG_TAKESELECTION = System::Int8(0x2);
static const System::Int8 cxSELFLAG_EXTENDSELECTION = System::Int8(0x4);
static const System::Int8 cxSELFLAG_ADDSELECTION = System::Int8(0x8);
static const System::Int8 cxSELFLAG_REMOVESELECTION = System::Int8(0x10);
static const System::Int8 cxSELFLAG_VALID = System::Int8(0x1f);
static const System::Word dxUIA_InvokePatternId = System::Word(0x2710);
static const System::Word dxUIA_SelectionPatternId = System::Word(0x2711);
static const System::Word dxUIA_ValuePatternId = System::Word(0x2712);
static const System::Word dxUIA_RangeValuePatternId = System::Word(0x2713);
static const System::Word dxUIA_ExpandCollapsePatternId = System::Word(0x2715);
static const System::Word dxUIA_GridPatternId = System::Word(0x2716);
static const System::Word dxUIA_GridItemPatternId = System::Word(0x2717);
static const System::Word dxUIA_SelectionItemPatternId = System::Word(0x271a);
static const System::Word dxUIA_TablePatternId = System::Word(0x271c);
static const System::Word dxUIA_TextPatternID = System::Word(0x271e);
static const System::Word dxUIA_TogglePatternId = System::Word(0x271f);
static const System::Word dxUIA_ScrollItemPatternId = System::Word(0x2721);
static const System::Word dxUIA_TextPattern2Id = System::Word(0x2728);
static const System::Word dxUIA_NamePropertyId = System::Word(0x7535);
static const System::Word dxUIA_AutomationIdPropertyId = System::Word(0x753b);
static const System::Word dxUIA_ClassNamePropertyId = System::Word(0x753c);
static const System::Word dxUIA_ControlTypePropertyId = System::Word(0x7533);
static const System::Word dxUIA_IsTogglePatternAvailablePropertyId = System::Word(0x7559);
static const System::Word dxUIA_ToggleToggleStatePropertyId = System::Word(0x7586);
static const System::Word UIA_ExpandCollapseExpandCollapseStatePropertyId = System::Word(0x7576);
static const System::Word dxUIA_IsControlElementPropertyId = System::Word(0x7540);
static const System::Word dxUIA_IsContentElementPropertyId = System::Word(0x7541);
static const System::Word dxUIA_IsEnabledPropertyId = System::Word(0x753a);
static const System::Word dxUIA_IsRequiredForFormPropertyId = System::Word(0x7549);
extern DELPHI_PACKAGE NativeInt __fastcall WMGetObjectResultFromIAccessibilityHelper(const Winapi::Messages::TMessage &AWMGetObjectMessage, _di_IcxAccessibilityHelper AIHelper);
extern DELPHI_PACKAGE bool __fastcall CanReturnAccessibleObject(const Winapi::Messages::TMessage &AWMGetObjectMessage);
extern DELPHI_PACKAGE bool __fastcall IsAccessibilitySupported(void);
extern DELPHI_PACKAGE void __fastcall cxAccessibilityHelperOwnerObjectDestroyed(void *AIHelper);
}	/* namespace Cxaccessibility */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXACCESSIBILITY)
using namespace Cxaccessibility;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxaccessibilityHPP
