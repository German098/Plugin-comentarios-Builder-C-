// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxDateUtils.pas' rev: 35.00 (Windows)

#ifndef CxdateutilsHPP
#define CxdateutilsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Variants.hpp>
#include <System.SysUtils.hpp>
#include <Winapi.Windows.hpp>
#include <Vcl.Controls.hpp>
#include <System.Classes.hpp>
#include <Vcl.Graphics.hpp>
#include <System.Win.Registry.hpp>
#include <dxCore.hpp>
#include <dxCoreClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Cxdateutils
{
//-- forward type declarations -----------------------------------------------
struct TcxDateTime;
struct TcxDate;
struct TcxTime;
class DELPHICLASS TcxEra;
class DELPHICLASS TcxEras;
class DELPHICLASS TcxCustomCalendarTable;
struct TcxTZIField;
struct TcxDSTInfo;
struct TcxTimeZoneInformation;
struct TdxTimeZoneHelper;
class DELPHICLASS TdxISO8601Helper;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TcxDateElement : unsigned char { deYear, deMonth, deDay };

enum DECLSPEC_DENUM TcxFirstWeekOfYear : unsigned char { fwySystem, fwyJan1, fwyFirstFullWeek, fwyFirstFourDays };

enum DECLSPEC_DENUM TDay : unsigned char { dSunday, dMonday, dTuesday, dWednesday, dThursday, dFriday, dSaturday };

typedef System::Set<TDay, TDay::dSunday, TDay::dSaturday> TDays;

typedef System::Int8 TdxDayOfWeek;

typedef System::Int8 TdxDayOfWeekSystem;

typedef System::Int8 TdxDayOfWeekVCL;

enum DECLSPEC_DENUM TcxDateOrder : unsigned char { doMDY, doDMY, doYMD };

enum DECLSPEC_DENUM TcxCalendarAlgorithmType : unsigned char { catUnknown, catSolarCalendar, catLunarCalendar, catLunarSolarCalendar };

enum DECLSPEC_DENUM TcxDateEditSmartInput : unsigned char { deiToday, deiYesterday, deiTomorrow, deiSunday, deiMonday, deiTuesday, deiWednesday, deiThursday, deiFriday, deiSaturday, deiFirst, deiSecond, deiThird, deiFourth, deiFifth, deiSixth, deiSeventh, deiBOM, deiEOM, deiNow };

struct DECLSPEC_DRECORD TcxDateTime
{
public:
	int Era;
	unsigned Year;
	unsigned Month;
	unsigned Day;
	System::Byte Hours;
	System::Byte Minutes;
	System::Byte Seconds;
	System::Word Milliseconds;
};


struct DECLSPEC_DRECORD TcxDate
{
public:
	int Era;
	unsigned Year;
	unsigned Month;
	unsigned Day;
};


struct DECLSPEC_DRECORD TcxTime
{
public:
	unsigned Hours;
	unsigned Minutes;
	unsigned Seconds;
	unsigned Miliseconds;
};


class PASCALIMPLEMENTATION TcxEra : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	int FEra;
	int FMaxEraYear;
	int FMinEraYear;
	System::TDateTime FStartDate;
	int FYearOffset;
	
public:
	__fastcall TcxEra(int AEra, System::TDateTime AStartDate, int AYearOffset, int AMinEraYear, int AMaxEraYear);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property int Era = {read=FEra, write=FEra, nodefault};
	__property int MaxEraYear = {read=FMaxEraYear, write=FMaxEraYear, nodefault};
	__property int MinEraYear = {read=FMinEraYear, write=FMinEraYear, nodefault};
	__property System::TDateTime StartDate = {read=FStartDate, write=FStartDate};
	__property int YearOffset = {read=FYearOffset, write=FYearOffset, nodefault};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxEra() { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxEras : public Dxcoreclasses::TdxFastObjectList
{
	typedef Dxcoreclasses::TdxFastObjectList inherited;
	
public:
	TcxEra* operator[](int Index) { return this->Items[Index]; }
	
private:
	HIDESBASE TcxEra* __fastcall GetItem(int AIndex);
	HIDESBASE void __fastcall SetItem(int AIndex, TcxEra* AValue);
	
public:
	__property TcxEra* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TdxFastObjectList.Create */ inline __fastcall TcxEras(bool AOwnsObjects, int ACapacity) : Dxcoreclasses::TdxFastObjectList(AOwnsObjects, ACapacity) { }
	
public:
	/* TdxFastList.Destroy */ inline __fastcall virtual ~TcxEras() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomCalendarTable : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	static const System::Int8 MaxDayNumber = System::Int8(0x1f);
	
	int FTwoDigitYearMax;
	
protected:
	TcxEras* FEras;
	virtual void __fastcall AdjustYear(int &AYear, int &AEra)/* overload */;
	virtual void __fastcall AdjustYear(int &AYear, int &AEra, int AMonth, int ADay)/* overload */;
	virtual TcxCalendarAlgorithmType __fastcall GetCalendarAlgorithmType() = 0 ;
	virtual unsigned __fastcall GetCalendarID() = 0 ;
	virtual TcxEra* __fastcall GetDefaultEra() = 0 ;
	virtual System::TDateTime __fastcall GetMaxSupportedDate() = 0 ;
	virtual System::TDateTime __fastcall GetMinSupportedDate() = 0 ;
	virtual void __fastcall CheckDateTime(System::TDateTime &ADateTime);
	virtual int __fastcall GetMaxSupportedYear() = 0 ;
	virtual int __fastcall GetMinSupportedYear() = 0 ;
	bool __fastcall IsNotValid(const TcxDateTime &ADate, /* out */ System::TDateTime &AResult);
	void __fastcall YearToGregorianYear(unsigned &AYear, int AEra);
	
public:
	__fastcall virtual TcxCustomCalendarTable();
	__fastcall virtual ~TcxCustomCalendarTable();
	virtual System::TDateTime __fastcall AddDays(const TcxDateTime &ADate, int ACountDays)/* overload */;
	virtual System::TDateTime __fastcall AddMonths(System::TDateTime ADate, int ACountMonths)/* overload */;
	virtual System::TDateTime __fastcall AddMonths(const TcxDateTime &ADate, int ACountMonths)/* overload */;
	virtual System::TDateTime __fastcall AddYears(System::TDateTime ADate, int ACountYears)/* overload */;
	virtual System::TDateTime __fastcall AddYears(const TcxDateTime &ADate, int ACountYears)/* overload */;
	virtual System::TDateTime __fastcall AddWeeks(System::TDateTime ADate, int ACountWeeks)/* overload */;
	virtual System::TDateTime __fastcall AddWeeks(const TcxDateTime &ADate, int ACountWeeks)/* overload */;
	virtual TcxDateTime __fastcall FromDateTime(System::TDateTime ADate) = 0 /* overload */;
	virtual TcxDateTime __fastcall FromDateTime(unsigned AYear, unsigned AMonth, unsigned ADay)/* overload */;
	virtual TcxDateTime __fastcall FromDateTime(unsigned AYear, unsigned AMonth, unsigned ADay, System::Byte AHours, System::Byte AMinutes, System::Byte ASeconds, System::Word AMilliseconds)/* overload */;
	virtual unsigned __fastcall GetDayOfYear(System::TDateTime ADate)/* overload */;
	virtual unsigned __fastcall GetDayOfYear(const TcxDateTime &ADate)/* overload */;
	virtual unsigned __fastcall GetDaysInMonth(unsigned AYear, unsigned AMonth)/* overload */;
	virtual unsigned __fastcall GetDaysInMonth(int AEra, unsigned AYear, unsigned AMonth) = 0 /* overload */;
	virtual unsigned __fastcall GetDaysInYear(unsigned AYear)/* overload */;
	virtual unsigned __fastcall GetDaysInYear(int AEra, unsigned AYear) = 0 /* overload */;
	virtual int __fastcall GetEra(int AYear)/* overload */;
	virtual int __fastcall GetEra(int AYear, int AMonth, int ADay)/* overload */;
	virtual System::TDateTime __fastcall GetFirstDayOfWeek(System::TDateTime ADate)/* overload */;
	virtual System::TDateTime __fastcall GetFirstDayOfWeek(System::TDateTime ADate, TDay AStartDayOfWeek)/* overload */;
	virtual TcxDateTime __fastcall GetFirstDayOfWeek(const TcxDateTime &ADate)/* overload */;
	virtual TcxDateTime __fastcall GetFirstDayOfWeek(const TcxDateTime &ADate, TDay AStartDayOfWeek)/* overload */;
	virtual System::TDateTime __fastcall GetFirstDayOfMonth(const System::TDateTime ADate)/* overload */;
	virtual TcxDateTime __fastcall GetFirstDayOfMonth(const TcxDateTime &ADate)/* overload */;
	virtual System::TDateTime __fastcall GetFirstDayOfYear(const System::TDateTime ADate)/* overload */;
	virtual TcxDateTime __fastcall GetFirstDayOfYear(const TcxDateTime &ADate)/* overload */;
	virtual System::Byte __fastcall GetFirstWeekDay() = 0 ;
	virtual unsigned __fastcall GetFullWeeksInYear(unsigned AYear) = 0 ;
	virtual System::TDateTime __fastcall GetLastDayOfMonth(const System::TDateTime ADate)/* overload */;
	virtual TcxDateTime __fastcall GetLastDayOfMonth(const TcxDateTime &ADate)/* overload */;
	virtual System::TDateTime __fastcall GetLastDayOfYear(const System::TDateTime ADate)/* overload */;
	virtual TcxDateTime __fastcall GetLastDayOfYear(const TcxDateTime &ADate)/* overload */;
	virtual unsigned __fastcall GetMonthsInYear(unsigned AYear)/* overload */;
	virtual unsigned __fastcall GetMonthsInYear(int AEra, unsigned AYear) = 0 /* overload */;
	virtual unsigned __fastcall GetYear(System::TDateTime ADate)/* overload */;
	virtual unsigned __fastcall GetYear(const TcxDate &ADate)/* overload */;
	virtual unsigned __fastcall GetYear(const TcxDateTime &ADate)/* overload */;
	virtual System::Byte __fastcall GetWeekDay(System::TDateTime ADate)/* overload */;
	virtual System::Byte __fastcall GetWeekDay(const TcxDateTime &ADate)/* overload */;
	virtual unsigned __fastcall GetWeekNumber(System::TDateTime ADate, TDay AStartOfWeek, TcxFirstWeekOfYear AFirstWeekOfYear)/* overload */;
	virtual unsigned __fastcall GetWeekNumber(const TcxDateTime &ADate, TDay AStartOfWeek, TcxFirstWeekOfYear AFirstWeekOfYear) = 0 /* overload */;
	virtual bool __fastcall IsLeapDay(unsigned AYear, unsigned AMonth, unsigned ADay)/* overload */;
	virtual bool __fastcall IsLeapDay(int AEra, unsigned AYear, unsigned AMonth, unsigned ADay) = 0 /* overload */;
	virtual bool __fastcall IsLeapMonth(unsigned AYear, unsigned AMonth)/* overload */;
	virtual bool __fastcall IsLeapMonth(int AEra, unsigned AYear, unsigned AMonth) = 0 /* overload */;
	virtual bool __fastcall IsLeapYear(unsigned AYear)/* overload */;
	virtual bool __fastcall IsLeapYear(int AEra, unsigned Year) = 0 /* overload */;
	virtual bool __fastcall IsValidYear(unsigned AYear)/* overload */;
	virtual bool __fastcall IsValidYear(int AEra, unsigned AYear)/* overload */;
	virtual bool __fastcall IsValidMonth(unsigned AYear, unsigned AMonth)/* overload */;
	virtual bool __fastcall IsValidMonth(int AEra, unsigned AYear, unsigned AMonth)/* overload */;
	virtual bool __fastcall IsValidDay(unsigned AYear, unsigned AMonth, unsigned ADay)/* overload */;
	virtual bool __fastcall IsValidDay(int AEra, unsigned AYear, unsigned AMonth, unsigned ADay)/* overload */;
	virtual bool __fastcall IsValidDate(System::TDateTime ADate);
	virtual System::TDateTime __fastcall ToDateTime(unsigned AYear, unsigned AMonth, unsigned ADay)/* overload */;
	virtual System::TDateTime __fastcall ToDateTime(unsigned AYear, unsigned AMonth, unsigned ADay, System::Byte AHours, System::Byte AMinutes, System::Byte ASeconds, System::Word AMilliseconds)/* overload */;
	virtual System::TDateTime __fastcall ToDateTime(const TcxDate &ADate)/* overload */;
	virtual System::TDateTime __fastcall ToDateTime(const TcxDateTime &ADateTime) = 0 /* overload */;
	unsigned __fastcall GetDayNumber(const System::UnicodeString S);
	unsigned __fastcall GetMonthNumber(int AYear, const System::UnicodeString S)/* overload */;
	unsigned __fastcall GetMonthNumber(int AYear, const System::UnicodeString S, const System::Sysutils::TFormatSettings &AFormat)/* overload */;
	unsigned __fastcall GetYearNumber(const System::UnicodeString S);
	virtual bool __fastcall TryGetDayNumber(const System::UnicodeString S, /* out */ unsigned &AValue);
	virtual bool __fastcall TryGetMonthNumber(int AYear, const System::UnicodeString S, const System::Sysutils::TFormatSettings &AFormat, /* out */ unsigned &AValue);
	virtual bool __fastcall TryGetYearNumber(const System::UnicodeString S, /* out */ unsigned &AValue);
	__property TcxCalendarAlgorithmType AlgorithmType = {read=GetCalendarAlgorithmType, nodefault};
	__property unsigned CalendarID = {read=GetCalendarID, nodefault};
	__property TcxEra* DefaultEra = {read=GetDefaultEra};
	__property TcxEras* Eras = {read=FEras};
	__property System::TDateTime MaxSupportedDate = {read=GetMaxSupportedDate};
	__property System::TDateTime MinSupportedDate = {read=GetMinSupportedDate};
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCustomCalendarTableClass;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TcxTZIField
{
public:
	int Bias;
	int StandardBias;
	int DaylightBias;
	_SYSTEMTIME StandardDate;
	_SYSTEMTIME DaylightDate;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TcxDSTInfo
{
public:
	System::Word Year;
	System::TDateTime DaylightDate;
	System::TDateTime StandardDate;
};
#pragma pack(pop)


struct DECLSPEC_DRECORD TcxTimeZoneInformation
{
	
private:
	typedef System::DynamicArray<TcxDSTInfo> _TcxTimeZoneInformation__1;
	
	
public:
	System::WideString Display;
	System::WideString StandardName;
	System::WideString DaylightName;
	int Index;
	System::UnicodeString MapId;
	TcxTZIField TZI;
	_TcxTimeZoneInformation__1 DynamicDST;
};


struct DECLSPEC_DRECORD TdxTimeZoneHelper
{
	
private:
	typedef System::DynamicArray<TcxTimeZoneInformation> _TdxTimeZoneHelper__1;
	
	
private:
	static int FCurrentTimeZone;
	static _TdxTimeZoneHelper__1 FTimeZoneInformations;
	static int __fastcall CheckTimeIndex(const int AIndex);
	static _TIME_ZONE_INFORMATION __fastcall cxTZInfoToTZInfo(const TcxTimeZoneInformation &AInfo);
	static TcxTimeZoneInformation __fastcall TZInfoTocxTZInfo(const _TIME_ZONE_INFORMATION &AInfo);
	static void __fastcall ReadTimeZoneInfoFromRegistry(System::Win::Registry::TRegistry* ARegistry, /* out */ TcxTimeZoneInformation &AInfo);
	
private:
	static void __fastcall InitTimeZoneInformation();
	static void __fastcall DoneTimeZoneInformation();
	
public:
	static int __fastcall AddInternalTimeZone(const TcxTimeZoneInformation &ATimeZone);
	static int __fastcall AddDSTInfo(TcxTimeZoneInformation &ATimeZoneInfo, const int AYear, const _SYSTEMTIME &AStandardDate, const _SYSTEMTIME &ADaylightDate)/* overload */;
	static int __fastcall AddDSTInfo(TcxTimeZoneInformation &ATimeZoneInfo, const int AYear, const System::TDateTime AStandardDate, const System::TDateTime ADaylightDate)/* overload */;
	static int __fastcall AddDSTInfo(const int ATimeZone, const int AYear, const System::TDateTime AStandardDate, const System::TDateTime ADaylightDate)/* overload */;
	static System::TDateTime __fastcall CalculateTransitionDate(const System::Word AYear, const _SYSTEMTIME &ADSTDateTime);
	static System::TDateTime __fastcall ConvertToGlobalTime(const System::TDateTime ADateTime, int ATimeZone = 0xffffffff);
	static System::TDateTime __fastcall ConvertToLocalTime(const System::TDateTime ADateTime, int ATimeZone = 0xffffffff);
	static int __fastcall CurrentTimeZone();
	static double __fastcall CurrentTimeZoneBias();
	static bool __fastcall IsDaylightDateTime(int ATimeZone, System::TDateTime ADateTime);
	static System::TDateTime __fastcall TimeZoneBias(int AIndex);
	static System::TDateTime __fastcall TimeZoneBiasDelta(int AIndex);
	static int __fastcall TimeZoneCount();
	static int __fastcall TimeZoneDaylightBias(System::TDateTime ADateTime, int ATimeZone);
	static TcxTimeZoneInformation __fastcall TimeZoneInfo(int AIndex);
	
private:
	// __classmethod void __fastcall Create@();
	// __classmethod void __fastcall Destroy@();
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxISO8601Helper : /*[[sealed]]*/ public System::TObject
{
	typedef System::TObject inherited;
	
public:
	#define TdxISO8601Helper_UTCTimeZoneName L"UTC"
	
	static System::UnicodeString __fastcall DateTimeToString(System::TDateTime AValue);
	static System::TDateTime __fastcall StringToDateTime(const System::UnicodeString AValue, /* out */ bool &AIsUtcTimeZone)/* overload */;
	static System::TDateTime __fastcall StringToDateTime(const System::UnicodeString AValue)/* overload */;
public:
	/* TObject.Create */ inline __fastcall TdxISO8601Helper() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxISO8601Helper() { }
	
};

#pragma pack(pop)

typedef System::StaticArray<System::UnicodeString, 20> Cxdateutils__5;

//-- var, const, procedure ---------------------------------------------------
static const int NullDate = int(-700000);
static const int InvalidDate = int(-699999);
extern DELPHI_PACKAGE bool __fastcall (*SmartTextToDateFunc)(const System::UnicodeString AText, System::TDateTime &ADate);
extern DELPHI_PACKAGE int dxMinYear;
extern DELPHI_PACKAGE int dxMaxYear;
extern DELPHI_PACKAGE bool cxUseSingleCharWeekNames;
extern DELPHI_PACKAGE Cxdateutils__5 scxDateEditSmartInput;
extern DELPHI_PACKAGE TcxTimeZoneInformation DefaultTimeZoneInfo;
extern DELPHI_PACKAGE System::UnicodeString __fastcall cxDateToLocalFormatStr(System::TDateTime ADate);
extern DELPHI_PACKAGE System::UnicodeString __fastcall cxDateToStr(System::TDateTime ADate)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall cxDateToStr(System::TDateTime ADate, const System::Sysutils::TFormatSettings &AFormat)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall cxDayNumberToLocalFormatStr(System::TDateTime ADate)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall cxDayNumberToLocalFormatStr(int ADay, TcxCustomCalendarTable* ACalendar = (TcxCustomCalendarTable*)(0x0))/* overload */;
extern DELPHI_PACKAGE System::WideChar __fastcall cxGetLocalDateSeparator(void);
extern DELPHI_PACKAGE System::Sysutils::TFormatSettings __fastcall cxGetLocalFormatSettings(void);
extern DELPHI_PACKAGE System::UnicodeString __fastcall cxGetLocalLongDateFormat(void);
extern DELPHI_PACKAGE System::UnicodeString __fastcall cxGetLocalLongTimeFormat(void);
extern DELPHI_PACKAGE System::UnicodeString __fastcall cxGetLocalMonthName(System::TDateTime ADate, TcxCustomCalendarTable* ACalendar)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall cxGetLocalMonthName(int AYear, int AMonth, TcxCustomCalendarTable* ACalendar)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall cxGetLocalMonthYear(System::TDateTime ADate, TcxCustomCalendarTable* ACalendar = (TcxCustomCalendarTable*)(0x0));
extern DELPHI_PACKAGE System::UnicodeString __fastcall cxGetLocalShortDateFormat(void);
extern DELPHI_PACKAGE System::UnicodeString __fastcall cxGetLocalTimeAMString(void);
extern DELPHI_PACKAGE System::UnicodeString __fastcall cxGetLocalTimePMString(void);
extern DELPHI_PACKAGE System::WideChar __fastcall cxGetLocalTimeSeparator(void);
extern DELPHI_PACKAGE System::UnicodeString __fastcall cxGetLocalYear(System::TDateTime ADate, TcxCustomCalendarTable* ACalendar = (TcxCustomCalendarTable*)(0x0));
extern DELPHI_PACKAGE System::UnicodeString __fastcall cxGetDayOfWeekName(TDay ADay, System::Uitypes::TFontCharset AFontCharset);
extern DELPHI_PACKAGE System::TDateTime __fastcall cxFloatToDateTime(const double AValue);
extern DELPHI_PACKAGE System::TDateTime __fastcall cxLocalFormatStrToDate(const System::UnicodeString ADateStr);
extern DELPHI_PACKAGE TcxDateTime __fastcall cxStrToDate(const System::UnicodeString ADateStr, TcxCustomCalendarTable* ACalendar = (TcxCustomCalendarTable*)(0x0))/* overload */;
extern DELPHI_PACKAGE TcxDateTime __fastcall cxStrToDate(const System::UnicodeString ADateStr, const System::Sysutils::TFormatSettings &AFormat, TcxCustomCalendarTable* ACalendar = (TcxCustomCalendarTable*)(0x0))/* overload */;
extern DELPHI_PACKAGE bool __fastcall cxTryStrToDate(const System::UnicodeString ADateStr, const System::Sysutils::TFormatSettings &AFormat, /* out */ TcxDateTime &ADateTime, TcxCustomCalendarTable* ACalendar = (TcxCustomCalendarTable*)(0x0))/* overload */;
extern DELPHI_PACKAGE bool __fastcall cxTryStrToDate(const System::UnicodeString ADateStr, const System::Sysutils::TFormatSettings &AFormat, const System::WideChar ADateSeparator, /* out */ TcxDateTime &ADateTime, TcxCustomCalendarTable* ACalendar = (TcxCustomCalendarTable*)(0x0))/* overload */;
extern DELPHI_PACKAGE System::TDate __fastcall cxStrToDate(const System::UnicodeString ADateString, const System::Sysutils::TFormatSettings &AFormat, unsigned ACALTYPE)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall cxTimeToStr(System::TDateTime ATime)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall cxTimeToStr(System::TDateTime ATime, const System::UnicodeString ATimeFormat)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall cxTimeToStr(System::TDateTime ATime, const System::Sysutils::TFormatSettings &AFormatSettings)/* overload */;
extern DELPHI_PACKAGE int __fastcall cxGetCalendarInfo(unsigned Locale, unsigned Calendar, unsigned CalendType, System::WideChar * lpCalData, int cchData, unsigned* lpValue);
extern DELPHI_PACKAGE TcxCustomCalendarTable* __fastcall cxGetCalendar(unsigned ACalendType);
extern DELPHI_PACKAGE unsigned __fastcall cxGetCalendarID(unsigned Locale);
extern DELPHI_PACKAGE TcxCustomCalendarTable* __fastcall cxGetDefaultCalendar(unsigned Locale);
extern DELPHI_PACKAGE unsigned __fastcall cxGetLocalCalendarID(void);
extern DELPHI_PACKAGE TcxCustomCalendarTable* __fastcall cxGetLocalCalendar(void);
extern DELPHI_PACKAGE TcxDateOrder __fastcall cxGetDateOrder(const System::UnicodeString ADateFormat);
extern DELPHI_PACKAGE void __fastcall AddDateRegExprMaskSmartInput(System::UnicodeString &AMask, bool ACanEnterTime);
extern DELPHI_PACKAGE int __fastcall dxGetCalendarDateElement(System::TDateTime ADate, TcxDateElement AElement, TcxCustomCalendarTable* ACalendar);
extern DELPHI_PACKAGE bool __fastcall cxGetDateFormat(System::TDateTime ADate, /* out */ System::UnicodeString &AFormatDate, int AFlags, const System::UnicodeString AFormat = System::UnicodeString());
extern DELPHI_PACKAGE System::UnicodeString __fastcall DateToLongDateStr(System::TDateTime ADate);
extern DELPHI_PACKAGE bool __fastcall SmartTextToDate(const System::UnicodeString AText, System::TDateTime &ADate);
extern DELPHI_PACKAGE bool __fastcall TextToDateEx(System::UnicodeString AText, System::TDateTime &ADate, const System::UnicodeString AFormatString = System::UnicodeString());
extern DELPHI_PACKAGE System::UnicodeString __fastcall cxDateTimeToText(System::TDateTime ADate, bool AFourDigitYearNeeded = false, bool AUseDelphiDateTimeFormats = false);
extern DELPHI_PACKAGE System::TDateTime __fastcall cxTextToDateTime(const System::UnicodeString AText, bool AUseDelphiDateTimeFormats = false);
extern DELPHI_PACKAGE System::UnicodeString __fastcall DateTimeToText(System::TDateTime ADate, bool AFourDigitYearNeeded = false);
extern DELPHI_PACKAGE System::UnicodeString __fastcall DateTimeToTextEx(const System::TDateTime ADate, bool AIsMasked, bool AIsDateTimeEdit = false, bool AFourDigitYearNeeded = false);
extern DELPHI_PACKAGE bool __fastcall cxStrToDateTime(System::UnicodeString S, bool AUseOleDateFormat, /* out */ System::TDateTime &ADate);
extern DELPHI_PACKAGE bool __fastcall cxIsWeekendDay(const System::TDateTime ADate);
extern DELPHI_PACKAGE void __fastcall dxDecMonth(System::Word &AYear, System::Word &AMonth);
extern DELPHI_PACKAGE void __fastcall dxIncMonth(System::Word &AYear, System::Word &AMonth)/* overload */;
extern DELPHI_PACKAGE void __fastcall dxChangeMonth(System::Word &AYear, System::Word &AMonth, int Delta);
extern DELPHI_PACKAGE bool __fastcall IsLeapYear(int AYear);
extern DELPHI_PACKAGE int __fastcall DaysPerMonth(int AYear, int AMonth);
extern DELPHI_PACKAGE int __fastcall CheckDay(int AYear, int AMonth, int ADay);
extern DELPHI_PACKAGE System::TDateTime __fastcall dxTimeOf(const System::TDateTime AValue);
extern DELPHI_PACKAGE System::TDateTime __fastcall dxDateOf(const System::TDateTime AValue);
extern DELPHI_PACKAGE bool __fastcall cxIsDateValid(double ADate);
extern DELPHI_PACKAGE int __fastcall dxGetDateElement(System::TDateTime ADate, TcxDateElement AElement);
extern DELPHI_PACKAGE System::TDateTime __fastcall dxGetStartDateOfMonth(const System::TDateTime ADate);
extern DELPHI_PACKAGE System::TDateTime __fastcall dxGetEndDateOfMonth(const System::TDateTime ADate, bool AIgnoreTime);
extern DELPHI_PACKAGE System::TDateTime __fastcall dxGetStartDateOfYear(const System::TDateTime ADate);
extern DELPHI_PACKAGE System::TDateTime __fastcall dxGetEndDateOfYear(const System::TDateTime ADate, bool AIgnoreTime);
extern DELPHI_PACKAGE TDay __fastcall dxGetStartOfWeek(void);
extern DELPHI_PACKAGE bool __fastcall dxGetAssignedStartOfWeek(void);
extern DELPHI_PACKAGE void __fastcall dxResetAssignedStartOfWeek(void);
extern DELPHI_PACKAGE void __fastcall dxSetStartOfWeek(TDay AValue);
extern DELPHI_PACKAGE System::TDateTime __fastcall dxGetNowInUTC(void);
extern DELPHI_PACKAGE TcxFirstWeekOfYear __fastcall dxGetLocalFirstWeekOfYear(void);
extern DELPHI_PACKAGE TDay __fastcall dxGetLocalStartOfWeek(void);
extern DELPHI_PACKAGE int __fastcall dxGetWeekNumber(System::TDateTime ADate, TDay AStartOfWeek, TcxFirstWeekOfYear AFirstWeekOfYear);
extern DELPHI_PACKAGE int __fastcall dxGetMonthNumber(const System::TDateTime ADate);
extern DELPHI_PACKAGE TDay __fastcall dxDayOfWeek(const System::TDateTime AValue);
extern DELPHI_PACKAGE TdxDayOfWeek __fastcall dxDayOfWeekOffset(const System::TDateTime AValue)/* overload */;
extern DELPHI_PACKAGE TdxDayOfWeek __fastcall dxDayOfWeekOffset(const System::TDateTime AValue, TDay AStartOfWeek)/* overload */;
extern DELPHI_PACKAGE TDay __fastcall dxDayOfWeekFromVCL(const TdxDayOfWeekVCL AValue);
extern DELPHI_PACKAGE TDay __fastcall dxDayOfWeekFromSystem(const TdxDayOfWeekSystem AValue);
extern DELPHI_PACKAGE TdxDayOfWeekVCL __fastcall dxDayOfWeekToVCL(TDay AValue);
extern DELPHI_PACKAGE TdxDayOfWeekSystem __fastcall dxDayOfWeekToSystem(TDay AValue);
extern DELPHI_PACKAGE TDay __fastcall dxGetDayOfWeek(TDay ADayFrom, int ADaysCount);
extern DELPHI_PACKAGE System::TDateTime __fastcall dxGetStartDateOfWeek(const System::TDateTime AValue)/* overload */;
extern DELPHI_PACKAGE System::TDateTime __fastcall dxGetStartDateOfWeek(const System::TDateTime AValue, TDay AStartOfWeek)/* overload */;
}	/* namespace Cxdateutils */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXDATEUTILS)
using namespace Cxdateutils;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxdateutilsHPP
