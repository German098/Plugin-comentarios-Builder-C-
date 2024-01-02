// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxFormats.pas' rev: 35.00 (Windows)

#ifndef CxformatsHPP
#define CxformatsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Types.hpp>
#include <Winapi.Windows.hpp>
#include <Winapi.Messages.hpp>
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <dxCore.hpp>
#include <cxDateUtils.hpp>
#include <cxClasses.hpp>
#include <cxControls.hpp>
#include <dxCoreClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Cxformats
{
//-- forward type declarations -----------------------------------------------
__interface DELPHIINTERFACE IcxFormatControllerListener;
typedef System::DelphiInterface<IcxFormatControllerListener> _di_IcxFormatControllerListener;
__interface DELPHIINTERFACE IcxFormatControllerListener2;
typedef System::DelphiInterface<IcxFormatControllerListener2> _di_IcxFormatControllerListener2;
class DELPHICLASS TcxDateTimeFormatItem;
class DELPHICLASS TcxDateTimeFormatInfo;
struct TcxDateTimeFormatItemInfo;
class DELPHICLASS TcxFormatController;
class DELPHICLASS TdxFormatSettings;
//-- type declarations -------------------------------------------------------
__interface  INTERFACE_UUID("{A7F2F6D3-1A7D-4295-A6E6-9297BD83D0DE}") IcxFormatControllerListener  : public System::IInterface 
{
	virtual void __fastcall FormatChanged() = 0 ;
};

__interface  INTERFACE_UUID("{5E33A2A7-0C77-415F-A359-112103E54937}") IcxFormatControllerListener2  : public System::IInterface 
{
	virtual void __fastcall TimeChanged() = 0 ;
};

enum DECLSPEC_DENUM TcxDateTimeEditMaskKind : unsigned char { dtmkDate, dtmkTime, dtmkDateTime };

enum DECLSPEC_DENUM TcxDateTimeFormatItemKind : unsigned char { dtikString, dtikYear, dtikMonth, dtikDay, dtikHour, dtikMin, dtikSec, dtikMSec, dtikTimeSuffix, dtikDateSeparator, dtikTimeSeparator };

enum DECLSPEC_DENUM TcxTimeSuffixKind : unsigned char { tskAP, tskAMPM, tskAMPMString };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDateTimeFormatItem : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	System::UnicodeString Data;
	TcxDateTimeFormatItemKind Kind;
public:
	/* TObject.Create */ inline __fastcall TcxDateTimeFormatItem() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDateTimeFormatItem() { }
	
};

#pragma pack(pop)

typedef System::StaticArray<bool, 11> TcxDateTimeFormatItemKindArray;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDateTimeFormatInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxDateTimeFormatItemKindArray FDefinedItems;
	Cxclasses::TcxObjectList* FItems;
	int __fastcall GetItemCount();
	bool __fastcall GetDefinedItems(TcxDateTimeFormatItemKind AKind);
	TcxDateTimeFormatItem* __fastcall GetItems(int AIndex);
	void __fastcall SetDefinedItems(TcxDateTimeFormatItemKind AKind, bool AValue);
	void __fastcall ClearItems();
	
public:
	__fastcall TcxDateTimeFormatInfo();
	__fastcall virtual ~TcxDateTimeFormatInfo();
	void __fastcall AddItem(TcxDateTimeFormatItemKind AKind, System::UnicodeString AData);
	void __fastcall RemoveItem(int AIndex);
	void __fastcall ClearFormatInfo();
	__property bool DefinedItems[TcxDateTimeFormatItemKind AKind] = {read=GetDefinedItems, write=SetDefinedItems};
	__property TcxDateTimeFormatItem* Items[int AIndex] = {read=GetItems};
	__property int ItemCount = {read=GetItemCount, nodefault};
};

#pragma pack(pop)

struct DECLSPEC_DRECORD TcxDateTimeFormatItemInfo
{
public:
	TcxDateTimeFormatItemKind Kind;
	int ItemZoneStart;
	int ItemZoneLength;
	TcxTimeSuffixKind TimeSuffixKind;
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFormatController : public Cxcontrols::TcxMessageWindow
{
	typedef Cxcontrols::TcxMessageWindow inherited;
	
private:
	bool FAssignedCurrencyFormat;
	bool FAssignedRegExprDateEditMask;
	bool FAssignedRegExprDateTimeEditMask;
	bool FAssignedStandardDateEditMask;
	bool FAssignedStandardDateTimeEditMask;
	System::UnicodeString FCurrencyFormat;
	System::UnicodeString FDateEditFormat;
	System::UnicodeString FDateEditMask;
	bool FDateEditShowZeroTime;
	Cxdateutils::TcxFirstWeekOfYear FFirstWeekOfYear;
	bool FIsStandardMaskValid;
	System::Classes::TList* FList;
	System::Sysutils::TFormatSettings FLocalFormatSettings;
	bool FLocalIsGregorianCalendar;
	int FLockCount;
	System::UnicodeString FMaskedDateEditFormat;
	System::UnicodeString FMaskedDateTimeEditFormat;
	System::UnicodeString FRegExprDateEditMask;
	System::UnicodeString FRegExprDateTimeEditMask;
	System::UnicodeString FStandardDateEditMask;
	System::UnicodeString FStandardDateTimeEditMask;
	bool FUseDelphiDateTimeFormats;
	TcxDateTimeFormatInfo* FDateFormatInfo;
	TcxDateTimeFormatInfo* FDateTimeFormatInfo;
	TcxDateTimeFormatInfo* FTimeFormatInfo;
	void __fastcall CalculateDateEditMasks(bool AUseSmartInputWhenRegExpr);
	bool __fastcall GetAssignedStartOfWeek();
	System::UnicodeString __fastcall GetCurrencyFormat()/* overload */;
	System::UnicodeString __fastcall GetDateEditFormat(bool AIsMasked);
	System::UnicodeString __fastcall GetDateTimeDisplayFormat(TcxDateTimeEditMaskKind AMaskKind);
	__classmethod int __fastcall GetDateTimeFormatItemStandardMaskZoneLength(TcxDateTimeFormatItem* const AItem);
	Cxdateutils::TDay __fastcall GetStartOfWeek();
	System::UnicodeString __fastcall InternalGetDateTimeEditRegExprMask(TcxDateTimeFormatInfo* AFormatInfo, TcxDateTimeEditMaskKind AMaskKind);
	System::UnicodeString __fastcall InternalGetDateTimeEditStandardMask(TcxDateTimeFormatInfo* AFormatInfo, TcxDateTimeEditMaskKind AMaskKind);
	System::UnicodeString __fastcall InternalGetMaskedDateEditFormat(TcxDateTimeFormatInfo* AFormatInfo);
	void __fastcall SetAssignedCurrencyFormat(bool Value);
	void __fastcall SetAssignedRegExprDateEditMask(bool Value);
	void __fastcall SetAssignedRegExprDateTimeEditMask(bool Value);
	void __fastcall SetAssignedStandardDateEditMask(bool Value);
	void __fastcall SetAssignedStandardDateTimeEditMask(bool Value);
	void __fastcall SetAssignedStartOfWeek(bool Value);
	void __fastcall SetCurrencyFormat(const System::UnicodeString Value);
	void __fastcall SetDateEditShowZeroTime(bool Value);
	void __fastcall SetFirstWeekOfYear(Cxdateutils::TcxFirstWeekOfYear Value);
	void __fastcall SetRegExprDateEditMask(const System::UnicodeString Value);
	void __fastcall SetRegExprDateTimeEditMask(const System::UnicodeString Value);
	void __fastcall SetStandardDateEditMask(const System::UnicodeString Value);
	void __fastcall SetStandardDateTimeEditMask(const System::UnicodeString Value);
	void __fastcall SetStartOfWeek(Cxdateutils::TDay Value);
	void __fastcall SetUseDelphiDateTimeFormats(bool Value);
	
protected:
	virtual bool __fastcall IsMessageOnlyWindow();
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	void __fastcall FormatChanged();
	void __fastcall TimeChanged();
	void __fastcall UpdateLocalSettings();
	
public:
	__fastcall virtual TcxFormatController();
	__fastcall virtual ~TcxFormatController();
	virtual void __fastcall AddListener(_di_IcxFormatControllerListener AListener);
	void __fastcall BeginUpdate();
	void __fastcall EndUpdate();
	void __fastcall GetFormats();
	__classmethod bool __fastcall GetDateTimeFormatItemStandardMaskInfo(TcxDateTimeFormatInfo* const AFormatInfo, int APos, /* out */ TcxDateTimeFormatItemInfo &AItemInfo);
	int __fastcall GetDateTimeStandardMaskStringLength(TcxDateTimeFormatInfo* const AFormatInfo);
	void __fastcall NotifyListeners();
	virtual void __fastcall RemoveListener(_di_IcxFormatControllerListener AListener);
	System::UnicodeString __fastcall RegExprCustomDateEditMask(const System::UnicodeString AFormatString);
	static System::UnicodeString __fastcall GetCurrencyFormat(const System::Sysutils::TFormatSettings &AFormatSettings)/* overload */;
	void __fastcall TranslationChanged();
	__property bool AssignedCurrencyFormat = {read=FAssignedCurrencyFormat, write=SetAssignedCurrencyFormat, nodefault};
	__property bool AssignedRegExprDateEditMask = {read=FAssignedRegExprDateEditMask, write=SetAssignedRegExprDateEditMask, nodefault};
	__property bool AssignedRegExprDateTimeEditMask = {read=FAssignedRegExprDateTimeEditMask, write=SetAssignedRegExprDateTimeEditMask, nodefault};
	__property bool AssignedStandardDateEditMask = {read=FAssignedStandardDateEditMask, write=SetAssignedStandardDateEditMask, nodefault};
	__property bool AssignedStandardDateTimeEditMask = {read=FAssignedStandardDateTimeEditMask, write=SetAssignedStandardDateTimeEditMask, nodefault};
	__property bool AssignedStartOfWeek = {read=GetAssignedStartOfWeek, write=SetAssignedStartOfWeek, nodefault};
	__property System::UnicodeString CurrencyFormat = {read=FCurrencyFormat, write=SetCurrencyFormat};
	__property System::UnicodeString DateEditFormat = {read=FDateEditFormat};
	__property System::UnicodeString DateEditMask = {read=FDateEditMask};
	__property bool DateEditShowZeroTime = {read=FDateEditShowZeroTime, write=SetDateEditShowZeroTime, nodefault};
	__property TcxDateTimeFormatInfo* DateFormatInfo = {read=FDateFormatInfo};
	__property TcxDateTimeFormatInfo* DateTimeFormatInfo = {read=FDateTimeFormatInfo};
	__property Cxdateutils::TcxFirstWeekOfYear FirstWeekOfYear = {read=FFirstWeekOfYear, write=SetFirstWeekOfYear, nodefault};
	__property bool IsStandardMaskValid = {read=FIsStandardMaskValid, nodefault};
	__property System::UnicodeString MaskedDateEditFormat = {read=FMaskedDateEditFormat};
	__property System::UnicodeString MaskedDateTimeEditFormat = {read=FMaskedDateTimeEditFormat};
	__property System::UnicodeString RegExprDateEditMask = {read=FRegExprDateEditMask, write=SetRegExprDateEditMask};
	__property System::UnicodeString RegExprDateTimeEditMask = {read=FRegExprDateTimeEditMask, write=SetRegExprDateTimeEditMask};
	__property System::UnicodeString StandardDateEditMask = {read=FStandardDateEditMask, write=SetStandardDateEditMask};
	__property System::UnicodeString StandardDateTimeEditMask = {read=FStandardDateTimeEditMask, write=SetStandardDateTimeEditMask};
	__property Cxdateutils::TDay StartOfWeek = {read=GetStartOfWeek, write=SetStartOfWeek, nodefault};
	__property TcxDateTimeFormatInfo* TimeFormatInfo = {read=FTimeFormatInfo};
	__property bool UseDelphiDateTimeFormats = {read=FUseDelphiDateTimeFormats, write=SetUseDelphiDateTimeFormats, nodefault};
	__property System::Sysutils::TFormatSettings LocalFormatSettings = {read=FLocalFormatSettings};
	__property bool LocalIsGregorianCalendar = {read=FLocalIsGregorianCalendar, nodefault};
private:
	void *__IdxLocalizerListener;	// Dxcore::IdxLocalizerListener 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {8410B6D7-1A56-4599-4FE3-AE8C0E182032}
	operator Dxcore::_di_IdxLocalizerListener()
	{
		Dxcore::_di_IdxLocalizerListener intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Dxcore::IdxLocalizerListener*(void) { return (Dxcore::IdxLocalizerListener*)&__IdxLocalizerListener; }
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
	operator System::IInterface*(void) { return (System::IInterface*)&__IdxLocalizerListener; }
	#endif
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFormatSettings : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Byte __fastcall GetCurrencyDecimals();
	System::Byte __fastcall GetCurrencyFormat();
	System::UnicodeString __fastcall GetCurrencyString();
	System::WideChar __fastcall GetDateSeparator();
	System::WideChar __fastcall GetDecimalSeparator();
	System::WideChar __fastcall GetListSeparator();
	System::UnicodeString __fastcall GetLongDateFormat();
	System::UnicodeString __fastcall GetLongDayNames(int AIndex);
	System::UnicodeString __fastcall GetLongMonthNames(int AIndex);
	System::UnicodeString __fastcall GetLongTimeFormat();
	System::Byte __fastcall GetNegCurrFormat();
	System::UnicodeString __fastcall GetShortDateFormat();
	System::UnicodeString __fastcall GetShortDayNames(int AIndex);
	System::UnicodeString __fastcall GetShortMonthNames(int AIndex);
	System::UnicodeString __fastcall GetShortTimeFormat();
	System::WideChar __fastcall GetThousandSeparator();
	System::UnicodeString __fastcall GetTimeAMString();
	System::UnicodeString __fastcall GetTimePMString();
	System::WideChar __fastcall GetTimeSeparator();
	void __fastcall SetCurrencyDecimals(System::Byte AValue);
	void __fastcall SetCurrencyString(const System::UnicodeString AValue);
	void __fastcall SetDateSeparator(System::WideChar AValue);
	void __fastcall SetDecimalSeparator(System::WideChar AValue);
	void __fastcall SetLongDayNames(int AIndex, const System::UnicodeString Value);
	void __fastcall SetLongMonthNames(int AIndex, const System::UnicodeString Value);
	void __fastcall SetShortDateFormat(const System::UnicodeString AValue);
	void __fastcall SetShortDayNames(int AIndex, const System::UnicodeString AValue);
	void __fastcall SetShortMonthNames(int AIndex, const System::UnicodeString AValue);
	void __fastcall SetThousandSeparator(System::WideChar AValue);
	
protected:
	System::Sysutils::TFormatSettings __fastcall ToFormatSettings();
	
public:
	__property System::Byte CurrencyDecimals = {read=GetCurrencyDecimals, write=SetCurrencyDecimals, nodefault};
	__property System::Byte CurrencyFormat = {read=GetCurrencyFormat, nodefault};
	__property System::UnicodeString CurrencyString = {read=GetCurrencyString, write=SetCurrencyString};
	__property System::WideChar DateSeparator = {read=GetDateSeparator, write=SetDateSeparator, nodefault};
	__property System::WideChar DecimalSeparator = {read=GetDecimalSeparator, write=SetDecimalSeparator, nodefault};
	__property System::WideChar ListSeparator = {read=GetListSeparator, nodefault};
	__property System::UnicodeString LongDateFormat = {read=GetLongDateFormat};
	__property System::UnicodeString LongDayNames[int AIndex] = {read=GetLongDayNames, write=SetLongDayNames};
	__property System::UnicodeString LongMonthNames[int AIndex] = {read=GetLongMonthNames, write=SetLongMonthNames};
	__property System::UnicodeString LongTimeFormat = {read=GetLongTimeFormat};
	__property System::Byte NegCurrFormat = {read=GetNegCurrFormat, nodefault};
	__property System::UnicodeString ShortDateFormat = {read=GetShortDateFormat, write=SetShortDateFormat};
	__property System::UnicodeString ShortDayNames[int AIndex] = {read=GetShortDayNames, write=SetShortDayNames};
	__property System::UnicodeString ShortMonthNames[int AIndex] = {read=GetShortMonthNames, write=SetShortMonthNames};
	__property System::UnicodeString ShortTimeFormat = {read=GetShortTimeFormat};
	__property System::WideChar ThousandSeparator = {read=GetThousandSeparator, write=SetThousandSeparator, nodefault};
	__property System::UnicodeString TimeAMString = {read=GetTimeAMString};
	__property System::UnicodeString TimePMString = {read=GetTimePMString};
	__property System::WideChar TimeSeparator = {read=GetTimeSeparator, nodefault};
public:
	/* TObject.Create */ inline __fastcall TdxFormatSettings() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxFormatSettings() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE TdxFormatSettings* dxFormatSettings;
extern DELPHI_PACKAGE System::UnicodeString __fastcall GetCharString(System::WideChar C, int ACount);
extern DELPHI_PACKAGE void __fastcall GetDateTimeFormatInfo(const System::UnicodeString AFormat, TcxDateTimeFormatInfo* &AFormatInfo);
extern DELPHI_PACKAGE System::UnicodeString __fastcall DefaultCurrencyDisplayFormat(void);
extern DELPHI_PACKAGE TcxFormatController* __fastcall cxFormatController(void);
}	/* namespace Cxformats */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXFORMATS)
using namespace Cxformats;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxformatsHPP
