// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxFilterControlUtils.pas' rev: 35.00 (Windows)

#ifndef CxfiltercontrolutilsHPP
#define CxfiltercontrolutilsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Variants.hpp>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <System.SysUtils.hpp>
#include <dxCore.hpp>
#include <cxClasses.hpp>
#include <cxDataStorage.hpp>
#include <cxEdit.hpp>
#include <cxFilter.hpp>
#include <cxLookAndFeels.hpp>

//-- user supplied -----------------------------------------------------------

namespace Cxfiltercontrolutils
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS EcxFilterControlError;
class DELPHICLASS TcxCustomFilterEditHelper;
class DELPHICLASS TcxFilterEditsController;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TcxFilterControlOperator : unsigned char { fcoNone, fcoEqual, fcoNotEqual, fcoLess, fcoLessEqual, fcoGreater, fcoGreaterEqual, fcoLike, fcoNotLike, fcoContains, fcoNotContains, fcoBeginsWith, fcoEndsWith, fcoBlanks, fcoNonBlanks, fcoBetween, fcoNotBetween, fcoInList, fcoNotInList, fcoYesterday, fcoToday, fcoTomorrow, fcoLast7Days, fcoLastWeek, fcoLast14Days, fcoLastTwoWeeks, fcoLast30Days, fcoLastMonth, fcoLastYear, fcoInPast, fcoThisWeek, fcoThisMonth, fcoThisYear, fcoNext7Days, fcoNextWeek, fcoNext14Days, fcoNextTwoWeeks, fcoNext30Days, fcoNextMonth, fcoNextYear, fcoInFuture };

typedef System::Set<TcxFilterControlOperator, TcxFilterControlOperator::fcoNone, TcxFilterControlOperator::fcoInFuture> TcxFilterControlOperators;

#pragma pack(push,4)
class PASCALIMPLEMENTATION EcxFilterControlError : public Dxcore::EdxException
{
	typedef Dxcore::EdxException inherited;
	
public:
	/* Exception.Create */ inline __fastcall EcxFilterControlError(const System::UnicodeString Msg) : Dxcore::EdxException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EcxFilterControlError(const System::UnicodeString Msg, const System::TVarRec *Args, const int Args_High) : Dxcore::EdxException(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EcxFilterControlError(NativeUInt Ident)/* overload */ : Dxcore::EdxException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EcxFilterControlError(System::PResStringRec ResStringRec)/* overload */ : Dxcore::EdxException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxFilterControlError(NativeUInt Ident, const System::TVarRec *Args, const int Args_High)/* overload */ : Dxcore::EdxException(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxFilterControlError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const int Args_High)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EcxFilterControlError(const System::UnicodeString Msg, int AHelpContext) : Dxcore::EdxException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EcxFilterControlError(const System::UnicodeString Msg, const System::TVarRec *Args, const int Args_High, int AHelpContext) : Dxcore::EdxException(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxFilterControlError(NativeUInt Ident, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxFilterControlError(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxFilterControlError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const int Args_High, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxFilterControlError(NativeUInt Ident, const System::TVarRec *Args, const int Args_High, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EcxFilterControlError() { }
	
};

#pragma pack(pop)

enum DECLSPEC_DENUM TcxFilterDataType : unsigned char { fdtText, fdtNumeric, fdtDate, fdtTime, fdtLookup, fdtCheck };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomFilterEditHelper : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	__classmethod virtual void __fastcall ClearPropertiesEvents(Cxedit::TcxCustomEditProperties* AProperties);
	__classmethod virtual void __fastcall InitializeEdit(Cxedit::TcxCustomEdit* AEdit, Cxedit::TcxCustomEditProperties* AEditProperties);
	__classmethod virtual bool __fastcall IsIDefaultValuesProviderNeeded(Cxedit::TcxCustomEditProperties* AEditProperties);
	
public:
	__classmethod virtual bool __fastcall EditPropertiesHasButtons();
	__classmethod virtual TcxFilterDataType __fastcall GetFilterDataType(Cxdatastorage::TcxValueTypeClass AValueTypeClass);
	__classmethod Cxedit::TcxCustomEdit* __fastcall GetFilterEdit(Cxedit::TcxCustomEditProperties* AEditProperties, Cxedit::TcxInplaceEditList* AInplaceEditList = (Cxedit::TcxInplaceEditList*)(0x0));
	__classmethod virtual Cxedit::TcxCustomEditClass __fastcall GetFilterEditClass();
	__classmethod virtual void __fastcall GetFilterValue(Cxedit::TcxCustomEdit* AEdit, Cxedit::TcxCustomEditProperties* AEditProperties, System::Variant &V, Vcl::Controls::TCaption &S);
	__classmethod virtual TcxFilterControlOperators __fastcall GetSupportedFilterOperators(Cxedit::TcxCustomEditProperties* AProperties, Cxdatastorage::TcxValueTypeClass AValueTypeClass, bool AExtendedSet = false);
	__classmethod virtual void __fastcall InitializeProperties(Cxedit::TcxCustomEditProperties* AProperties, Cxedit::TcxCustomEditProperties* AEditProperties, bool AHasButtons);
	__classmethod virtual bool __fastcall IsValueValid(Cxdatastorage::TcxValueTypeClass AValueTypeClass, System::Variant &AValue);
	__classmethod virtual void __fastcall SetFilterValue(Cxedit::TcxCustomEdit* AEdit, Cxedit::TcxCustomEditProperties* AEditProperties, const System::Variant &AValue);
	__classmethod virtual bool __fastcall UseDisplayValue();
public:
	/* TObject.Create */ inline __fastcall TcxCustomFilterEditHelper() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomFilterEditHelper() { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCustomFilterEditHelperClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFilterEditsController : public Cxclasses::TcxRegisteredClassList
{
	typedef Cxclasses::TcxRegisteredClassList inherited;
	
public:
	TcxCustomFilterEditHelperClass __fastcall FindHelper(System::TClass APropertiesClass);
	virtual void __fastcall Unregister(System::TClass AItemClass, System::TClass ARegisteredClass);
public:
	/* TcxRegisteredClassList.Create */ inline __fastcall TcxFilterEditsController() : Cxclasses::TcxRegisteredClassList() { }
	/* TcxRegisteredClassList.Destroy */ inline __fastcall virtual ~TcxFilterEditsController() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE Cxfilter::TcxFilterOperatorKind __fastcall GetFilterOperatorKind(TcxFilterControlOperator AOperator);
extern DELPHI_PACKAGE TcxFilterControlOperator __fastcall GetFilterControlOperator(Cxfilter::TcxFilterOperatorKind AOperatorKind, bool AIsNull);
extern DELPHI_PACKAGE void __fastcall CorrectDlgParams(Vcl::Controls::TCreateParams &Params);
extern DELPHI_PACKAGE void __fastcall FilterControlError(const System::UnicodeString Msg);
extern DELPHI_PACKAGE void __fastcall FilterControlValidateValue(Cxedit::TcxCustomEdit* AEdit, System::Variant &AValue, TcxFilterControlOperator AOperator, Cxdatastorage::TcxValueTypeClass AValueTypeClass, TcxCustomFilterEditHelperClass AFilterEditHelper);
extern DELPHI_PACKAGE TcxFilterEditsController* __fastcall FilterEditsController(void);
extern DELPHI_PACKAGE System::UnicodeString __fastcall GetFilterControlOperatorText(TcxFilterControlOperator AOperator);
}	/* namespace Cxfiltercontrolutils */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXFILTERCONTROLUTILS)
using namespace Cxfiltercontrolutils;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxfiltercontrolutilsHPP
