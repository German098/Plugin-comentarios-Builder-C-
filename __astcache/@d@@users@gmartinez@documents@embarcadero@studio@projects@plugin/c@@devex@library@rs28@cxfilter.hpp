// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxFilter.pas' rev: 35.00 (Windows)

#ifndef CxfilterHPP
#define CxfilterHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Types.hpp>
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <System.Variants.hpp>
#include <Winapi.Windows.hpp>
#include <cxClasses.hpp>
#include <Vcl.ImgList.hpp>
#include <dxCore.hpp>
#include <dxCoreClasses.hpp>
#include <cxLike.hpp>
#include <dxCustomFunction.hpp>

//-- user supplied -----------------------------------------------------------

namespace Cxfilter
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TcxFilterOperator;
class DELPHICLASS TcxFilterEqualOperator;
class DELPHICLASS TcxFilterNotEqualOperator;
class DELPHICLASS TcxFilterLessOperator;
class DELPHICLASS TcxFilterLessEqualOperator;
class DELPHICLASS TcxFilterGreaterOperator;
class DELPHICLASS TcxFilterGreaterEqualOperator;
class DELPHICLASS TcxFilterCustomLikeOperator;
class DELPHICLASS TcxFilterLikeOperator;
class DELPHICLASS TcxFilterNotLikeOperator;
class DELPHICLASS TcxFilterContainsOperator;
class DELPHICLASS TcxFilterNotContainsOperator;
class DELPHICLASS TcxFilterBeginsWithOperator;
class DELPHICLASS TcxFilterEndsWithOperator;
class DELPHICLASS TcxFilterCustomFunctionOperator;
class DELPHICLASS TcxFilterBetweenOperator;
class DELPHICLASS TcxFilterNotBetweenOperator;
class DELPHICLASS TcxFilterInListOperator;
class DELPHICLASS TcxFilterNotInListOperator;
class DELPHICLASS TcxFilterNullOperator;
class DELPHICLASS TcxFilterNotNullOperator;
class DELPHICLASS TcxFilterDateOperator;
class DELPHICLASS TcxFilterYesterdayOperator;
class DELPHICLASS TcxFilterTodayOperator;
class DELPHICLASS TcxFilterTomorrowOperator;
class DELPHICLASS TcxFilterLastNDaysOperator;
class DELPHICLASS TcxFilterLast7DaysOperator;
class DELPHICLASS TcxFilterLastWeekOperator;
class DELPHICLASS TcxFilterLast14DaysOperator;
class DELPHICLASS TcxFilterLastTwoWeeksOperator;
class DELPHICLASS TcxFilterLast30DaysOperator;
class DELPHICLASS TcxFilterLastMonthOperator;
class DELPHICLASS TcxFilterLastYearOperator;
class DELPHICLASS TcxFilterInPastOperator;
class DELPHICLASS TcxFilterThisWeekOperator;
class DELPHICLASS TcxFilterThisMonthOperator;
class DELPHICLASS TcxFilterThisYearOperator;
class DELPHICLASS TcxFilterNextNDaysOperator;
class DELPHICLASS TcxFilterNext7DaysOperator;
class DELPHICLASS TcxFilterNextWeekOperator;
class DELPHICLASS TcxFilterNext14DaysOperator;
class DELPHICLASS TcxFilterNextTwoWeeksOperator;
class DELPHICLASS TcxFilterNext30DaysOperator;
class DELPHICLASS TcxFilterNextMonthOperator;
class DELPHICLASS TcxFilterNextYearOperator;
class DELPHICLASS TcxFilterInFutureOperator;
class DELPHICLASS TcxCustomFilterCriteriaItem;
class DELPHICLASS TcxFilterCriteriaItemList;
class DELPHICLASS TcxFilterCriteriaItem;
class DELPHICLASS TcxFilterValueItem;
class DELPHICLASS TcxFilterMRUValueItem;
class DELPHICLASS TcxFilterMRUValueItems;
class DELPHICLASS TcxFilterValueList;
class DELPHICLASS TcxFilterCriteria;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TcxFilterCriteriaDisplayStyle : unsigned char { fcdsDefault, fcdsText, fcdsTokens };

enum DECLSPEC_DENUM TcxFilterOperatorKind : unsigned char { foEqual, foNotEqual, foLess, foLessEqual, foGreater, foGreaterEqual, foLike, foNotLike, foBetween, foNotBetween, foInList, foNotInList, foYesterday, foToday, foTomorrow, foLast7Days, foLastWeek, foLast14Days, foLastTwoWeeks, foLast30Days, foLastMonth, foLastYear, foInPast, foThisWeek, foThisMonth, foThisYear, foNext7Days, foNextWeek, foNext14Days, foNextTwoWeeks, foNext30Days, foNextMonth, foNextYear, foInFuture, foContains, foNotContains, foBeginsWith, foEndsWith };

typedef System::Set<TcxFilterOperatorKind, TcxFilterOperatorKind::foEqual, TcxFilterOperatorKind::foEndsWith> TcxFilterOperatorKinds;

enum DECLSPEC_DENUM TcxFilterBoolOperatorKind : unsigned char { fboAnd, fboOr, fboNotAnd, fboNotOr };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFilterOperator : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxFilterCriteriaItem* FCriteriaItem;
	_RTL_CRITICAL_SECTION FCriticalSection;
	
protected:
	virtual System::UnicodeString __fastcall GetFilterExpressionText(const System::Variant &AValue);
	virtual System::UnicodeString __fastcall GetFilterExpressionValue(const System::Variant &AValue);
	void __fastcall Lock();
	virtual void __fastcall PrepareDisplayValue(System::UnicodeString &DisplayValue);
	virtual void __fastcall Prepare();
	virtual bool __fastcall PrepareExpressionValue(const System::Variant &AValue, System::UnicodeString &DisplayValue);
	void __fastcall Unlock();
	
public:
	__fastcall virtual TcxFilterOperator(TcxFilterCriteriaItem* ACriteriaItem);
	__fastcall virtual ~TcxFilterOperator();
	virtual bool __fastcall CompareValues(const System::Variant &AValue1, const System::Variant &AValue2) = 0 ;
	virtual System::UnicodeString __fastcall DisplayText();
	virtual System::UnicodeString __fastcall FilterText() = 0 ;
	virtual bool __fastcall IsDescription();
	virtual bool __fastcall IsExpression();
	virtual bool __fastcall IsUnary();
	__property TcxFilterCriteriaItem* CriteriaItem = {read=FCriteriaItem};
};

#pragma pack(pop)

typedef System::TMetaClass* TcxFilterOperatorClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFilterEqualOperator : public TcxFilterOperator
{
	typedef TcxFilterOperator inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetFilterExpressionText(const System::Variant &AValue);
	
public:
	virtual bool __fastcall CompareValues(const System::Variant &AValue1, const System::Variant &AValue2);
	virtual System::UnicodeString __fastcall DisplayText();
	virtual System::UnicodeString __fastcall FilterText();
	virtual bool __fastcall IsExpression();
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterEqualOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterEqualOperator() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFilterNotEqualOperator : public TcxFilterEqualOperator
{
	typedef TcxFilterEqualOperator inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetFilterExpressionText(const System::Variant &AValue);
	
public:
	virtual bool __fastcall CompareValues(const System::Variant &AValue1, const System::Variant &AValue2);
	virtual System::UnicodeString __fastcall DisplayText();
	virtual System::UnicodeString __fastcall FilterText();
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterNotEqualOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterEqualOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterNotEqualOperator() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFilterLessOperator : public TcxFilterOperator
{
	typedef TcxFilterOperator inherited;
	
public:
	virtual bool __fastcall CompareValues(const System::Variant &AValue1, const System::Variant &AValue2);
	virtual System::UnicodeString __fastcall DisplayText();
	virtual System::UnicodeString __fastcall FilterText();
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterLessOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterLessOperator() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFilterLessEqualOperator : public TcxFilterOperator
{
	typedef TcxFilterOperator inherited;
	
public:
	virtual bool __fastcall CompareValues(const System::Variant &AValue1, const System::Variant &AValue2);
	virtual System::UnicodeString __fastcall DisplayText();
	virtual System::UnicodeString __fastcall FilterText();
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterLessEqualOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterLessEqualOperator() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFilterGreaterOperator : public TcxFilterOperator
{
	typedef TcxFilterOperator inherited;
	
public:
	virtual bool __fastcall CompareValues(const System::Variant &AValue1, const System::Variant &AValue2);
	virtual System::UnicodeString __fastcall DisplayText();
	virtual System::UnicodeString __fastcall FilterText();
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterGreaterOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterGreaterOperator() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFilterGreaterEqualOperator : public TcxFilterOperator
{
	typedef TcxFilterOperator inherited;
	
public:
	virtual bool __fastcall CompareValues(const System::Variant &AValue1, const System::Variant &AValue2);
	virtual System::UnicodeString __fastcall DisplayText();
	virtual System::UnicodeString __fastcall FilterText();
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterGreaterEqualOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterGreaterEqualOperator() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFilterCustomLikeOperator : public TcxFilterOperator
{
	typedef TcxFilterOperator inherited;
	
protected:
	virtual bool __fastcall AllowUserMasks();
	virtual System::WideChar __fastcall GetEscapeWildard _DEPRECATED_ATTRIBUTE1("use GetEscapeWildcard instead") ();
	virtual System::WideChar __fastcall GetEscapeWildcard();
	virtual System::WideChar __fastcall GetPercentWildcard();
	virtual System::WideChar __fastcall GetUnderscoreWildcard();
	virtual System::UnicodeString __fastcall GetFilterExpressionText(const System::Variant &AValue);
	virtual System::UnicodeString __fastcall GetExpressionOperatorText();
	virtual System::UnicodeString __fastcall PrepareEscapedString(const System::UnicodeString AString);
	virtual System::UnicodeString __fastcall PrepareFilterString(const System::Variant &AValue);
	virtual System::UnicodeString __fastcall PreparePatternString(const System::Variant &AValue);
	virtual System::UnicodeString __fastcall PrepareString(const System::Variant &AValue);
	
public:
	virtual bool __fastcall CompareValues(const System::Variant &AValue1, const System::Variant &AValue2);
	virtual System::UnicodeString __fastcall FilterText();
	virtual bool __fastcall IsDescription();
	virtual bool __fastcall IsExpression();
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterCustomLikeOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterCustomLikeOperator() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFilterLikeOperator : public TcxFilterCustomLikeOperator
{
	typedef TcxFilterCustomLikeOperator inherited;
	
protected:
	virtual bool __fastcall AllowUserMasks();
	Cxlike::TcxFilterLikeOperator __fastcall GetLikeOperator();
	virtual void __fastcall PrepareDisplayValue(System::UnicodeString &DisplayValue);
	
public:
	virtual System::UnicodeString __fastcall DisplayText();
	virtual System::UnicodeString __fastcall FilterText();
	virtual bool __fastcall IsExpression();
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterLikeOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterCustomLikeOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterLikeOperator() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFilterNotLikeOperator : public TcxFilterLikeOperator
{
	typedef TcxFilterLikeOperator inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetFilterExpressionText(const System::Variant &AValue);
	
public:
	virtual bool __fastcall CompareValues(const System::Variant &AValue1, const System::Variant &AValue2);
	virtual System::UnicodeString __fastcall DisplayText();
	virtual System::UnicodeString __fastcall FilterText();
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterNotLikeOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterLikeOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterNotLikeOperator() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFilterContainsOperator : public TcxFilterCustomLikeOperator
{
	typedef TcxFilterCustomLikeOperator inherited;
	
protected:
	virtual System::WideChar __fastcall GetEscapeWildcard();
	virtual System::UnicodeString __fastcall PrepareFilterString(const System::Variant &AValue);
	virtual System::UnicodeString __fastcall PreparePatternString(const System::Variant &AValue);
	
public:
	virtual System::UnicodeString __fastcall DisplayText();
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterContainsOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterCustomLikeOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterContainsOperator() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFilterNotContainsOperator : public TcxFilterContainsOperator
{
	typedef TcxFilterContainsOperator inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetFilterExpressionText(const System::Variant &AValue);
	virtual System::UnicodeString __fastcall GetExpressionOperatorText();
	
public:
	virtual bool __fastcall CompareValues(const System::Variant &AValue1, const System::Variant &AValue2);
	virtual System::UnicodeString __fastcall DisplayText();
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterNotContainsOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterContainsOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterNotContainsOperator() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFilterBeginsWithOperator : public TcxFilterCustomLikeOperator
{
	typedef TcxFilterCustomLikeOperator inherited;
	
protected:
	virtual System::WideChar __fastcall GetEscapeWildcard();
	virtual System::UnicodeString __fastcall PrepareFilterString(const System::Variant &AValue);
	virtual System::UnicodeString __fastcall PreparePatternString(const System::Variant &AValue);
	
public:
	virtual System::UnicodeString __fastcall DisplayText();
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterBeginsWithOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterCustomLikeOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterBeginsWithOperator() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFilterEndsWithOperator : public TcxFilterCustomLikeOperator
{
	typedef TcxFilterCustomLikeOperator inherited;
	
protected:
	virtual System::WideChar __fastcall GetEscapeWildcard();
	virtual System::UnicodeString __fastcall PrepareFilterString(const System::Variant &AValue);
	virtual System::UnicodeString __fastcall PreparePatternString(const System::Variant &AValue);
	
public:
	virtual System::UnicodeString __fastcall DisplayText();
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterEndsWithOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterCustomLikeOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterEndsWithOperator() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFilterCustomFunctionOperator : public TcxFilterOperator
{
	typedef TcxFilterOperator inherited;
	
private:
	Dxcustomfunction::TdxCustomFunctionOperator* FCustomFunctionOperator;
	System::UnicodeString FFunctionName;
	int FMaxOperandCount;
	void __fastcall SetFunctionName(const System::UnicodeString Value);
	
protected:
	virtual void __fastcall PrepareDisplayValue(System::UnicodeString &DisplayValue);
	
public:
	virtual bool __fastcall CompareValues(const System::Variant &AValue1, const System::Variant &AValue2);
	virtual System::UnicodeString __fastcall DisplayText();
	virtual System::UnicodeString __fastcall FilterText();
	virtual bool __fastcall IsUnary();
	__property System::UnicodeString FunctionName = {read=FFunctionName, write=SetFunctionName};
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterCustomFunctionOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterCustomFunctionOperator() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFilterBetweenOperator : public TcxFilterOperator
{
	typedef TcxFilterOperator inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetFilterExpressionText(const System::Variant &AValue);
	virtual void __fastcall PrepareDisplayValue(System::UnicodeString &DisplayValue);
	virtual bool __fastcall PrepareExpressionValue(const System::Variant &AValue, System::UnicodeString &DisplayValue);
	
public:
	virtual bool __fastcall CompareValues(const System::Variant &AValue1, const System::Variant &AValue2);
	virtual System::UnicodeString __fastcall DisplayText();
	virtual System::UnicodeString __fastcall FilterText();
	virtual bool __fastcall IsDescription();
	virtual bool __fastcall IsExpression();
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterBetweenOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterBetweenOperator() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFilterNotBetweenOperator : public TcxFilterBetweenOperator
{
	typedef TcxFilterBetweenOperator inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetFilterExpressionText(const System::Variant &AValue);
	
public:
	virtual bool __fastcall CompareValues(const System::Variant &AValue1, const System::Variant &AValue2);
	virtual System::UnicodeString __fastcall DisplayText();
	virtual System::UnicodeString __fastcall FilterText();
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterNotBetweenOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterBetweenOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterNotBetweenOperator() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFilterInListOperator : public TcxFilterOperator
{
	typedef TcxFilterOperator inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetFilterExpressionText(const System::Variant &AValue);
	virtual void __fastcall PrepareDisplayValue(System::UnicodeString &DisplayValue);
	virtual bool __fastcall PrepareExpressionValue(const System::Variant &AValue, System::UnicodeString &DisplayValue);
	
public:
	virtual bool __fastcall CompareValues(const System::Variant &AValue1, const System::Variant &AValue2);
	virtual System::UnicodeString __fastcall DisplayText();
	virtual System::UnicodeString __fastcall FilterText();
	virtual bool __fastcall IsDescription();
	virtual bool __fastcall IsExpression();
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterInListOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterInListOperator() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFilterNotInListOperator : public TcxFilterInListOperator
{
	typedef TcxFilterInListOperator inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetFilterExpressionText(const System::Variant &AValue);
	
public:
	virtual bool __fastcall CompareValues(const System::Variant &AValue1, const System::Variant &AValue2);
	virtual System::UnicodeString __fastcall DisplayText();
	virtual System::UnicodeString __fastcall FilterText();
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterNotInListOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterInListOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterNotInListOperator() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFilterNullOperator : public TcxFilterEqualOperator
{
	typedef TcxFilterEqualOperator inherited;
	
protected:
	virtual void __fastcall PrepareDisplayValue(System::UnicodeString &DisplayValue);
	
public:
	virtual bool __fastcall CompareValues(const System::Variant &AValue1, const System::Variant &AValue2);
	virtual System::UnicodeString __fastcall DisplayText();
	virtual bool __fastcall IsUnary();
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterNullOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterEqualOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterNullOperator() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFilterNotNullOperator : public TcxFilterNullOperator
{
	typedef TcxFilterNullOperator inherited;
	
public:
	virtual bool __fastcall CompareValues(const System::Variant &AValue1, const System::Variant &AValue2);
	virtual System::UnicodeString __fastcall DisplayText();
	virtual System::UnicodeString __fastcall FilterText();
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterNotNullOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterNullOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterNotNullOperator() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxFilterDateOperator : public TcxFilterOperator
{
	typedef TcxFilterOperator inherited;
	
private:
	System::TDateTime FDate1;
	System::TDateTime FDate2;
	
protected:
	virtual void __fastcall PrepareDisplayValue(System::UnicodeString &DisplayValue);
	virtual System::UnicodeString __fastcall GetFilterExpressionText(const System::Variant &AValue);
	
public:
	virtual bool __fastcall CompareValues(const System::Variant &AValue1, const System::Variant &AValue2);
	virtual System::UnicodeString __fastcall FilterText();
	virtual bool __fastcall IsExpression();
	virtual bool __fastcall IsUnary();
	__property System::TDateTime Date1 = {read=FDate1, write=FDate1};
	__property System::TDateTime Date2 = {read=FDate2, write=FDate2};
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterDateOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterDateOperator() { }
	
};


class PASCALIMPLEMENTATION TcxFilterYesterdayOperator : public TcxFilterDateOperator
{
	typedef TcxFilterDateOperator inherited;
	
protected:
	virtual void __fastcall Prepare();
	
public:
	virtual System::UnicodeString __fastcall DisplayText();
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterYesterdayOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterDateOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterYesterdayOperator() { }
	
};


class PASCALIMPLEMENTATION TcxFilterTodayOperator : public TcxFilterDateOperator
{
	typedef TcxFilterDateOperator inherited;
	
protected:
	virtual void __fastcall Prepare();
	
public:
	virtual System::UnicodeString __fastcall DisplayText();
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterTodayOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterDateOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterTodayOperator() { }
	
};


class PASCALIMPLEMENTATION TcxFilterTomorrowOperator : public TcxFilterDateOperator
{
	typedef TcxFilterDateOperator inherited;
	
protected:
	virtual void __fastcall Prepare();
	
public:
	virtual System::UnicodeString __fastcall DisplayText();
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterTomorrowOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterDateOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterTomorrowOperator() { }
	
};


class PASCALIMPLEMENTATION TcxFilterLastNDaysOperator : public TcxFilterDateOperator
{
	typedef TcxFilterDateOperator inherited;
	
protected:
	virtual int __fastcall DayCount() = 0 ;
	virtual void __fastcall Prepare();
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterLastNDaysOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterDateOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterLastNDaysOperator() { }
	
};


class PASCALIMPLEMENTATION TcxFilterLast7DaysOperator : public TcxFilterLastNDaysOperator
{
	typedef TcxFilterLastNDaysOperator inherited;
	
protected:
	virtual int __fastcall DayCount();
	
public:
	virtual System::UnicodeString __fastcall DisplayText();
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterLast7DaysOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterLastNDaysOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterLast7DaysOperator() { }
	
};


class PASCALIMPLEMENTATION TcxFilterLastWeekOperator : public TcxFilterDateOperator
{
	typedef TcxFilterDateOperator inherited;
	
protected:
	virtual void __fastcall Prepare();
	
public:
	virtual System::UnicodeString __fastcall DisplayText();
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterLastWeekOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterDateOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterLastWeekOperator() { }
	
};


class PASCALIMPLEMENTATION TcxFilterLast14DaysOperator : public TcxFilterLastNDaysOperator
{
	typedef TcxFilterLastNDaysOperator inherited;
	
protected:
	virtual int __fastcall DayCount();
	
public:
	virtual System::UnicodeString __fastcall DisplayText();
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterLast14DaysOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterLastNDaysOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterLast14DaysOperator() { }
	
};


class PASCALIMPLEMENTATION TcxFilterLastTwoWeeksOperator : public TcxFilterDateOperator
{
	typedef TcxFilterDateOperator inherited;
	
protected:
	virtual void __fastcall Prepare();
	
public:
	virtual System::UnicodeString __fastcall DisplayText();
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterLastTwoWeeksOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterDateOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterLastTwoWeeksOperator() { }
	
};


class PASCALIMPLEMENTATION TcxFilterLast30DaysOperator : public TcxFilterLastNDaysOperator
{
	typedef TcxFilterLastNDaysOperator inherited;
	
protected:
	virtual int __fastcall DayCount();
	
public:
	virtual System::UnicodeString __fastcall DisplayText();
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterLast30DaysOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterLastNDaysOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterLast30DaysOperator() { }
	
};


class PASCALIMPLEMENTATION TcxFilterLastMonthOperator : public TcxFilterDateOperator
{
	typedef TcxFilterDateOperator inherited;
	
protected:
	virtual void __fastcall Prepare();
	
public:
	virtual System::UnicodeString __fastcall DisplayText();
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterLastMonthOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterDateOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterLastMonthOperator() { }
	
};


class PASCALIMPLEMENTATION TcxFilterLastYearOperator : public TcxFilterDateOperator
{
	typedef TcxFilterDateOperator inherited;
	
protected:
	virtual void __fastcall Prepare();
	
public:
	virtual System::UnicodeString __fastcall DisplayText();
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterLastYearOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterDateOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterLastYearOperator() { }
	
};


class PASCALIMPLEMENTATION TcxFilterInPastOperator : public TcxFilterDateOperator
{
	typedef TcxFilterDateOperator inherited;
	
protected:
	virtual void __fastcall Prepare();
	
public:
	virtual System::UnicodeString __fastcall DisplayText();
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterInPastOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterDateOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterInPastOperator() { }
	
};


class PASCALIMPLEMENTATION TcxFilterThisWeekOperator : public TcxFilterDateOperator
{
	typedef TcxFilterDateOperator inherited;
	
protected:
	virtual void __fastcall Prepare();
	
public:
	virtual System::UnicodeString __fastcall DisplayText();
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterThisWeekOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterDateOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterThisWeekOperator() { }
	
};


class PASCALIMPLEMENTATION TcxFilterThisMonthOperator : public TcxFilterDateOperator
{
	typedef TcxFilterDateOperator inherited;
	
protected:
	virtual void __fastcall Prepare();
	
public:
	virtual System::UnicodeString __fastcall DisplayText();
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterThisMonthOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterDateOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterThisMonthOperator() { }
	
};


class PASCALIMPLEMENTATION TcxFilterThisYearOperator : public TcxFilterDateOperator
{
	typedef TcxFilterDateOperator inherited;
	
protected:
	virtual void __fastcall Prepare();
	
public:
	virtual System::UnicodeString __fastcall DisplayText();
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterThisYearOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterDateOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterThisYearOperator() { }
	
};


class PASCALIMPLEMENTATION TcxFilterNextNDaysOperator : public TcxFilterDateOperator
{
	typedef TcxFilterDateOperator inherited;
	
protected:
	virtual int __fastcall DayCount() = 0 ;
	virtual void __fastcall Prepare();
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterNextNDaysOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterDateOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterNextNDaysOperator() { }
	
};


class PASCALIMPLEMENTATION TcxFilterNext7DaysOperator : public TcxFilterNextNDaysOperator
{
	typedef TcxFilterNextNDaysOperator inherited;
	
protected:
	virtual int __fastcall DayCount();
	
public:
	virtual System::UnicodeString __fastcall DisplayText();
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterNext7DaysOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterNextNDaysOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterNext7DaysOperator() { }
	
};


class PASCALIMPLEMENTATION TcxFilterNextWeekOperator : public TcxFilterDateOperator
{
	typedef TcxFilterDateOperator inherited;
	
protected:
	virtual void __fastcall Prepare();
	
public:
	virtual System::UnicodeString __fastcall DisplayText();
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterNextWeekOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterDateOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterNextWeekOperator() { }
	
};


class PASCALIMPLEMENTATION TcxFilterNext14DaysOperator : public TcxFilterNextNDaysOperator
{
	typedef TcxFilterNextNDaysOperator inherited;
	
protected:
	virtual int __fastcall DayCount();
	
public:
	virtual System::UnicodeString __fastcall DisplayText();
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterNext14DaysOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterNextNDaysOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterNext14DaysOperator() { }
	
};


class PASCALIMPLEMENTATION TcxFilterNextTwoWeeksOperator : public TcxFilterDateOperator
{
	typedef TcxFilterDateOperator inherited;
	
protected:
	virtual void __fastcall Prepare();
	
public:
	virtual System::UnicodeString __fastcall DisplayText();
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterNextTwoWeeksOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterDateOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterNextTwoWeeksOperator() { }
	
};


class PASCALIMPLEMENTATION TcxFilterNext30DaysOperator : public TcxFilterNextNDaysOperator
{
	typedef TcxFilterNextNDaysOperator inherited;
	
protected:
	virtual int __fastcall DayCount();
	
public:
	virtual System::UnicodeString __fastcall DisplayText();
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterNext30DaysOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterNextNDaysOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterNext30DaysOperator() { }
	
};


class PASCALIMPLEMENTATION TcxFilterNextMonthOperator : public TcxFilterDateOperator
{
	typedef TcxFilterDateOperator inherited;
	
protected:
	virtual void __fastcall Prepare();
	
public:
	virtual System::UnicodeString __fastcall DisplayText();
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterNextMonthOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterDateOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterNextMonthOperator() { }
	
};


class PASCALIMPLEMENTATION TcxFilterNextYearOperator : public TcxFilterDateOperator
{
	typedef TcxFilterDateOperator inherited;
	
protected:
	virtual void __fastcall Prepare();
	
public:
	virtual System::UnicodeString __fastcall DisplayText();
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterNextYearOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterDateOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterNextYearOperator() { }
	
};


class PASCALIMPLEMENTATION TcxFilterInFutureOperator : public TcxFilterDateOperator
{
	typedef TcxFilterDateOperator inherited;
	
protected:
	virtual void __fastcall Prepare();
	
public:
	virtual System::UnicodeString __fastcall DisplayText();
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterInFutureOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterDateOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterInFutureOperator() { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomFilterCriteriaItem : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxFilterCriteriaItemList* FParent;
	
protected:
	virtual void __fastcall Changed();
	virtual bool __fastcall DoFilterData(System::TObject* AData) = 0 ;
	virtual TcxFilterCriteria* __fastcall GetCriteria();
	virtual bool __fastcall GetIsItemList() = 0 ;
	virtual void __fastcall ReadData(System::Classes::TStream* AStream);
	virtual void __fastcall WriteData(System::Classes::TStream* AStream);
	
public:
	__fastcall TcxCustomFilterCriteriaItem(TcxFilterCriteriaItemList* AOwner);
	__fastcall virtual ~TcxCustomFilterCriteriaItem();
	virtual bool __fastcall IsEmpty() = 0 ;
	__property bool IsItemList = {read=GetIsItemList, nodefault};
	__property TcxFilterCriteria* Criteria = {read=GetCriteria};
	__property TcxFilterCriteriaItemList* Parent = {read=FParent};
};

#pragma pack(pop)

typedef System::TMetaClass* TcxFilterCriteriaItemListClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFilterCriteriaItemList : public TcxCustomFilterCriteriaItem
{
	typedef TcxCustomFilterCriteriaItem inherited;
	
public:
	TcxCustomFilterCriteriaItem* operator[](int Index) { return this->Items[Index]; }
	
private:
	TcxFilterBoolOperatorKind FBoolOperatorKind;
	TcxFilterCriteria* FCriteria;
	Dxcoreclasses::TdxFastList* FItems;
	void __fastcall CheckFilterResult(bool &AResult, /* out */ bool &ADone);
	int __fastcall GetCount();
	TcxCustomFilterCriteriaItem* __fastcall GetItem(int Index);
	void __fastcall SetBoolOperatorKind(TcxFilterBoolOperatorKind Value);
	
protected:
	TcxFilterCriteriaItem* __fastcall AddExpressionItem(System::TObject* AItemLink, const System::UnicodeString ACustomFunctionName, const System::UnicodeString AExpression, const System::UnicodeString ADisplayValue)/* overload */;
	TcxFilterCriteriaItem* __fastcall AddItem(System::TObject* AItemLink, const System::UnicodeString ACustomFunctionName, const System::Variant &AValue, const System::UnicodeString ADisplayValue)/* overload */;
	virtual bool __fastcall DoFilterData(System::TObject* AData);
	virtual TcxFilterCriteria* __fastcall GetCriteria();
	virtual bool __fastcall GetIsItemList();
	virtual void __fastcall RemoveItem(TcxCustomFilterCriteriaItem* AItem);
	virtual void __fastcall ReadData(System::Classes::TStream* AStream);
	virtual void __fastcall WriteData(System::Classes::TStream* AStream);
	TcxCustomFilterCriteriaItem* __fastcall ReadItem(System::Classes::TStream* AStream);
	void __fastcall WriteItem(System::Classes::TStream* AStream, TcxCustomFilterCriteriaItem* AItem);
	
public:
	__fastcall virtual TcxFilterCriteriaItemList(TcxFilterCriteriaItemList* AOwner, TcxFilterBoolOperatorKind ABoolOperatorKind);
	__fastcall virtual ~TcxFilterCriteriaItemList();
	TcxFilterCriteriaItem* __fastcall AddExpressionItem(System::TObject* AItemLink, TcxFilterOperatorKind AOperatorKind, const System::UnicodeString AExpression, const System::UnicodeString ADisplayValue)/* overload */;
	TcxFilterCriteriaItem* __fastcall AddItem(System::TObject* AItemLink, TcxFilterOperatorKind AOperatorKind, const System::Variant &AValue, const System::UnicodeString ADisplayValue)/* overload */;
	TcxFilterCriteriaItemList* __fastcall AddItemList(TcxFilterBoolOperatorKind ABoolOperatorKind);
	void __fastcall Clear();
	virtual bool __fastcall IsEmpty();
	__property TcxFilterBoolOperatorKind BoolOperatorKind = {read=FBoolOperatorKind, write=SetBoolOperatorKind, default=0};
	__property int Count = {read=GetCount, nodefault};
	__property TcxFilterCriteria* Criteria = {read=GetCriteria};
	__property TcxCustomFilterCriteriaItem* Items[int Index] = {read=GetItem/*, default*/};
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxFilterCriteriaItem : public TcxCustomFilterCriteriaItem
{
	typedef TcxCustomFilterCriteriaItem inherited;
	
private:
	System::UnicodeString FCustomFunctionName;
	System::UnicodeString FDisplayValue;
	System::UnicodeString FExpression;
	System::TObject* FItemLink;
	TcxFilterOperator* FOperator;
	TcxFilterOperatorKind FOperatorKind;
	System::Variant FPreparedValue;
	System::Variant FValue;
	bool __fastcall Compare(System::TObject* AData);
	void __fastcall InternalSetValue(const System::Variant &Value);
	void __fastcall SetDisplayValue(const System::UnicodeString Value);
	void __fastcall SetExpression(const System::UnicodeString AValue);
	void __fastcall SetOperatorKind(TcxFilterOperatorKind Value);
	void __fastcall SetValue(const System::Variant &Value);
	void __fastcall SetCustomFunctionName(const System::UnicodeString Value);
	
protected:
	void __fastcall CheckDisplayValue();
	bool __fastcall CompareByDisplayValue();
	virtual bool __fastcall DoFilterData(System::TObject* AData);
	virtual void __fastcall ExpressionChanged();
	virtual System::Variant __fastcall GetComparedValue(System::TObject* AData, /* out */ bool &AHasError);
	virtual System::Variant __fastcall GetDataValue(System::TObject* AData) = 0 ;
	virtual System::UnicodeString __fastcall GetDisplayValue();
	virtual System::Variant __fastcall GetExpressionValue(System::TObject* AData, /* out */ bool &AHasError) = 0 ;
	virtual System::UnicodeString __fastcall GetFieldCaption();
	virtual System::UnicodeString __fastcall GetFieldName();
	virtual System::UnicodeString __fastcall GetFilterExpressionValue(bool AIsCaption);
	virtual TcxFilterOperatorClass __fastcall GetFilterOperatorClass()/* overload */;
	TcxFilterOperatorClass __fastcall GetFilterOperatorClass(TcxFilterOperatorKind AKind)/* overload */;
	virtual System::TObject* __fastcall GetItemLink();
	virtual void __fastcall SetItemLink(System::TObject* Value);
	virtual bool __fastcall GetIsItemList();
	bool __fastcall IsOperatorNull(TcxFilterOperatorKind AOperatorKind)/* overload */;
	void __fastcall Prepare();
	void __fastcall PrepareValue();
	virtual void __fastcall RecreateOperator();
	virtual void __fastcall ReadData(System::Classes::TStream* AStream);
	virtual System::UnicodeString __fastcall ReadExpression(System::Classes::TStream* AStream, bool AIsUnicode);
	virtual bool __fastcall SupportsMultiThreading();
	virtual void __fastcall WriteData(System::Classes::TStream* AStream);
	virtual void __fastcall WriteExpression(System::Classes::TStream* AStream, const System::UnicodeString AExpression);
	
public:
	__fastcall virtual TcxFilterCriteriaItem(TcxFilterCriteriaItemList* AOwner, System::TObject* AItemLink, TcxFilterOperatorKind AOperatorKind, const System::Variant &AValue, const System::UnicodeString ADisplayValue);
	__fastcall virtual ~TcxFilterCriteriaItem();
	virtual bool __fastcall IsEmpty();
	bool __fastcall IsOperatorNull()/* overload */;
	virtual bool __fastcall ValueIsNull(const System::Variant &AValue);
	__property System::UnicodeString CustomFunctionName = {read=FCustomFunctionName, write=SetCustomFunctionName};
	__property System::UnicodeString DisplayValue = {read=FDisplayValue, write=SetDisplayValue};
	__property System::UnicodeString Expression = {read=FExpression, write=SetExpression};
	__property System::TObject* ItemLink = {read=GetItemLink};
	__property TcxFilterOperator* Operator = {read=FOperator};
	__property TcxFilterOperatorKind OperatorKind = {read=FOperatorKind, write=SetOperatorKind, nodefault};
	__property System::Variant PreparedValue = {read=FPreparedValue};
	__property System::Variant Value = {read=FValue, write=SetValue};
};


typedef System::TMetaClass* TcxFilterCriteriaItemClass;

enum DECLSPEC_DENUM TcxFilterValueItemKind : unsigned char { fviAll, fviCustom, fviBlanks, fviNonBlanks, fviUser, fviValue, fviMRU, fviMRUSeparator, fviSpecial, fviUserEx };

typedef void __fastcall (__closure *TcxUserFilteringEvent)(System::TObject* Sender, const System::Variant &AValue, const System::UnicodeString ADisplayText);

typedef void __fastcall (__closure *TcxUserFilteringExEvent)(System::TObject* Sender, TcxFilterCriteriaItemList* AFilterList, const System::Variant &AValue, const System::UnicodeString ADisplayText);

typedef void __fastcall (__closure *TcxGetFilterDisplayTextEvent)(System::TObject* Sender, const System::Variant &AValue, System::UnicodeString &ADisplayText);

typedef void __fastcall (__closure *TcxGetFilterImagesEvent)(System::TObject* Sender, TcxFilterValueList* AValueList, Vcl::Imglist::TCustomImageList* &AImages);

typedef void __fastcall (__closure *TcxGetFilterValuesEvent)(System::TObject* Sender, TcxFilterValueList* AValueList);

typedef void __fastcall (__closure *TcxQueryCustomFunctions)(System::TObject* Sender, const System::UnicodeString APropertyName, System::Classes::TStrings* AFunctionNames);

class PASCALIMPLEMENTATION TcxFilterValueItem : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::UnicodeString FPreparedDisplayText;
	System::Variant FPreparedValue;
	System::UnicodeString FDisplayText;
	int FImageIndex;
	TcxFilterValueItemKind FKind;
	TcxFilterValueList* FOwner;
	System::Variant FValue;
	TcxFilterCriteria* __fastcall GetCriteria();
	
protected:
	void __fastcall Prepare();
	__property TcxFilterCriteria* Criteria = {read=GetCriteria};
	__property System::UnicodeString PreparedDisplayText = {read=FPreparedDisplayText};
	__property System::Variant PreparedValue = {read=FPreparedValue};
	
public:
	__fastcall TcxFilterValueItem(TcxFilterValueList* AOwner, TcxFilterValueItemKind AKind, const System::Variant &AValue, const System::UnicodeString ADisplayText);
	int __fastcall ComparePreparedValue(const System::Variant &APreparedValue, const System::UnicodeString APreparedDisplayText);
	__property System::UnicodeString DisplayText = {read=FDisplayText};
	__property int ImageIndex = {read=FImageIndex, write=FImageIndex, nodefault};
	__property TcxFilterValueItemKind Kind = {read=FKind, nodefault};
	__property System::Variant Value = {read=FValue};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxFilterValueItem() { }
	
};


class PASCALIMPLEMENTATION TcxFilterMRUValueItem : public Cxclasses::TcxMRUItem
{
	typedef Cxclasses::TcxMRUItem inherited;
	
public:
	System::Variant Value;
	System::UnicodeString DisplayText;
	__fastcall TcxFilterMRUValueItem(const System::Variant &AValue, const System::UnicodeString ADisplayText);
	virtual bool __fastcall Equals(Cxclasses::TcxMRUItem* AItem);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxFilterMRUValueItem() { }
	
};


typedef System::TMetaClass* TcxFilterMRUValueItemsClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFilterMRUValueItems : public Cxclasses::TcxMRUItems
{
	typedef Cxclasses::TcxMRUItems inherited;
	
public:
	TcxFilterMRUValueItem* operator[](int Index) { return this->Items[Index]; }
	
private:
	HIDESBASE TcxFilterMRUValueItem* __fastcall GetItem(int Index);
	
public:
	HIDESBASE void __fastcall Add(const System::Variant &AValue, const System::UnicodeString ADisplayText);
	void __fastcall AddItemsTo(TcxFilterValueList* AValueList);
	__property TcxFilterMRUValueItem* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TcxMRUItems.Create */ inline __fastcall virtual TcxFilterMRUValueItems() : Cxclasses::TcxMRUItems() { }
	/* TcxMRUItems.Destroy */ inline __fastcall virtual ~TcxFilterMRUValueItems() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFilterValueList : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxFilterValueItem* operator[](int Index) { return this->Items[Index]; }
	
private:
	TcxFilterCriteria* FCriteria;
	bool FIsUnsortedValues;
	Dxcoreclasses::TdxFastObjectList* FItems;
	int FMRUSeparatorIndex;
	bool FSortByDisplayText;
	int FStartValueIndex;
	int __fastcall GetCount();
	TcxFilterValueItem* __fastcall GetItem(int Index);
	int __fastcall GetMaxCount();
	
protected:
	void __fastcall Add(TcxFilterValueItemKind AKind, const System::Variant &AValue, const System::UnicodeString ADisplayText, bool ANoSorting, bool AUniqueOnly)/* overload */;
	virtual int __fastcall CompareItem(int AIndex, const System::Variant &APreparedValue, const System::UnicodeString APreparedDisplayText);
	TcxFilterValueItem* __fastcall CreateItem(TcxFilterValueItemKind AKind, const System::Variant &AValue, const System::UnicodeString ADisplayText);
	bool __fastcall FindValueIndex(const System::Variant &APreparedValue, const System::UnicodeString APreparedDisplayText, /* out */ int &AIndex);
	__property Dxcoreclasses::TdxFastObjectList* ItemsList = {read=FItems};
	
public:
	__fastcall virtual TcxFilterValueList(TcxFilterCriteria* ACriteria);
	__fastcall virtual ~TcxFilterValueList();
	virtual void __fastcall Add(TcxFilterValueItemKind AKind, const System::Variant &AValue, const System::UnicodeString ADisplayText, bool ANoSorting)/* overload */;
	virtual void __fastcall Clear();
	void __fastcall Delete(int AIndex);
	virtual bool __fastcall Find(const System::Variant &AValue, const System::UnicodeString ADisplayText, int &AIndex);
	int __fastcall FindItemByKind(TcxFilterValueItemKind AKind)/* overload */;
	int __fastcall FindItemByKind(TcxFilterValueItemKind AKind, const System::Variant &AValue)/* overload */;
	int __fastcall FindItemByValue(const System::Variant &AValue);
	virtual int __fastcall GetIndexByCriteriaItem(TcxFilterCriteriaItem* ACriteriaItem);
	int __fastcall IndexOf(TcxFilterValueItem* AItem);
	__property int Count = {read=GetCount, nodefault};
	__property TcxFilterCriteria* Criteria = {read=FCriteria};
	__property TcxFilterValueItem* Items[int Index] = {read=GetItem/*, default*/};
	__property int MaxCount = {read=GetMaxCount, nodefault};
	__property bool SortByDisplayText = {read=FSortByDisplayText, write=FSortByDisplayText, nodefault};
	__property int StartValueIndex = {read=FStartValueIndex, nodefault};
};

#pragma pack(pop)

typedef System::TMetaClass* TcxFilterValueListClass;

enum DECLSPEC_DENUM TcxFilterCriteriaOption : unsigned char { fcoCaseInsensitive, fcoShowOperatorDescription, fcoSoftNull, fcoSoftCompare, fcoIgnoreNull };

typedef System::Set<TcxFilterCriteriaOption, TcxFilterCriteriaOption::fcoCaseInsensitive, TcxFilterCriteriaOption::fcoIgnoreNull> TcxFilterCriteriaOptions;

class PASCALIMPLEMENTATION TcxFilterCriteria : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	bool FChanged;
	_RTL_CRITICAL_SECTION FCriticalSection;
	System::UnicodeString FDateTimeFormat;
	System::WideChar FEscapeWildcard;
	bool FIsUnicode;
	System::Byte FLoadedVersion;
	int FLockCount;
	int FMaxValueListCount;
	TcxFilterCriteriaOptions FOptions;
	System::WideChar FPercentWildcard;
	bool FCompareByDisplayValues;
	TcxFilterCriteriaItemList* FRoot;
	System::Byte FSavedVersion;
	bool FSavingToStream;
	bool FSupportedLike;
	bool FTranslateBetween;
	bool FTranslateLike;
	bool FTranslateIn;
	System::WideChar FUnderscoreWildcard;
	System::Byte FVersion;
	System::Classes::TNotifyEvent FOnChanged;
	TcxFilterCriteriaOptions __fastcall GetOptions();
	bool __fastcall GetStoreItemLinkNames();
	void __fastcall SetDateTimeFormat(const System::UnicodeString Value);
	void __fastcall SetOptions(TcxFilterCriteriaOptions Value);
	void __fastcall SetPercentWildcard(System::WideChar Value);
	void __fastcall SetStoreItemLinkNames(bool Value);
	void __fastcall SetUnderscoreWildcard(System::WideChar Value);
	
protected:
	virtual void __fastcall CheckChanges();
	virtual System::UnicodeString __fastcall ConvertBoolToStr(const System::Variant &AValue);
	virtual System::UnicodeString __fastcall ConvertDateToStr(const System::Variant &AValue, bool AIsSQLTimeStamp);
	bool __fastcall DoFilterData(System::TObject* AData);
	virtual bool __fastcall FilterTextUsed();
	virtual void __fastcall FormatFilterTextValue(TcxFilterCriteriaItem* AItem, const System::Variant &AValue, System::UnicodeString &ADisplayValue);
	virtual System::UnicodeString __fastcall GetFilterCaption();
	virtual System::UnicodeString __fastcall GetFilterExpression(bool AIsCaption);
	virtual System::UnicodeString __fastcall GetFilterText();
	virtual int __fastcall GetIDByItemLink(System::TObject* AItemLink) = 0 ;
	virtual System::UnicodeString __fastcall GetNameByItemLink(System::TObject* AItemLink) = 0 ;
	virtual TcxFilterCriteriaItemClass __fastcall GetItemClass();
	virtual TcxFilterCriteriaItemListClass __fastcall GetItemListClass();
	virtual System::UnicodeString __fastcall GetItemExpression(TcxFilterCriteriaItem* AItem, bool AIsCaption);
	virtual System::UnicodeString __fastcall GetItemExpressionFieldName(TcxFilterCriteriaItem* AItem, bool AIsCaption);
	virtual System::UnicodeString __fastcall GetItemExpressionOperator(TcxFilterCriteriaItem* AItem, bool AIsCaption);
	virtual System::UnicodeString __fastcall GetItemExpressionValue(TcxFilterCriteriaItem* AItem, bool AIsCaption);
	virtual System::TObject* __fastcall GetItemLinkByID(int AID) = 0 ;
	virtual System::TObject* __fastcall GetItemLinkByName(const System::UnicodeString AName) = 0 ;
	virtual TcxFilterCriteriaItemListClass __fastcall GetRootClass();
	virtual TcxFilterValueListClass __fastcall GetValueListClass();
	virtual bool __fastcall IsExpressionsSupported();
	bool __fastcall IsStore();
	void __fastcall Lock();
	virtual void __fastcall Prepare();
	virtual System::UnicodeString __fastcall PrepareDisplayText(const System::UnicodeString ADisplayText);
	virtual System::Variant __fastcall PrepareValue(const System::Variant &AValue);
	virtual void __fastcall SetFilterText(const System::UnicodeString Value);
	bool __fastcall SupportsMultiThreading();
	void __fastcall Unlock();
	virtual void __fastcall Update();
	__property System::WideChar EscapeWildcard = {read=FEscapeWildcard, write=FEscapeWildcard, nodefault};
	__property bool IsUnicode = {read=FIsUnicode, nodefault};
	__property System::Byte LoadedVersion = {read=FLoadedVersion, nodefault};
	__property int LockCount = {read=FLockCount, nodefault};
	__property System::Byte SavedVersion = {read=FSavedVersion, nodefault};
	__property System::Byte Version = {read=FVersion, write=FVersion, nodefault};
	
public:
	__fastcall TcxFilterCriteria();
	__fastcall virtual ~TcxFilterCriteria();
	HIDESBASE virtual void __fastcall Assign(System::Classes::TPersistent* Source, bool AIgnoreItemNames = false);
	virtual void __fastcall AssignEvents(System::Classes::TPersistent* Source);
	virtual void __fastcall AssignItems(TcxFilterCriteria* ASource, bool AIgnoreItemNames = false);
	virtual TcxFilterCriteriaItem* __fastcall AddExpressionItem(TcxFilterCriteriaItemList* AParent, System::TObject* AItemLink, TcxFilterOperatorKind AOperatorKind, const System::UnicodeString AExpression, const System::UnicodeString ADisplayValue)/* overload */;
	virtual TcxFilterCriteriaItem* __fastcall AddExpressionItem(TcxFilterCriteriaItemList* AParent, System::TObject* AItemLink, const System::UnicodeString ACustomFunctionName, const System::UnicodeString AExpression, const System::UnicodeString ADisplayValue)/* overload */;
	virtual TcxFilterCriteriaItem* __fastcall AddItem(TcxFilterCriteriaItemList* AParent, System::TObject* AItemLink, TcxFilterOperatorKind AOperatorKind, const System::Variant &AValue, const System::UnicodeString ADisplayValue)/* overload */;
	virtual TcxFilterCriteriaItem* __fastcall AddItem(TcxFilterCriteriaItemList* AParent, System::TObject* AItemLink, const System::UnicodeString ACustomFunctionName, const System::Variant &AValue, const System::UnicodeString ADisplayValue)/* overload */;
	void __fastcall BeginUpdate();
	void __fastcall CancelUpdate();
	void __fastcall Clear();
	virtual void __fastcall Changed();
	void __fastcall EndUpdate();
	bool __fastcall EqualItems(TcxFilterCriteria* AFilterCriteria, bool AIgnoreItemNames = false);
	virtual TcxFilterCriteriaItem* __fastcall FindItemByItemLink(System::TObject* AItemLink);
	virtual bool __fastcall IsEmpty();
	virtual void __fastcall LoadFromStream(System::Classes::TStream* AStream);
	void __fastcall Refresh();
	void __fastcall RemoveItemByItemLink(System::TObject* AItemLink);
	virtual void __fastcall RestoreDefaults();
	virtual void __fastcall SaveToStream(System::Classes::TStream* AStream);
	virtual bool __fastcall ValueIsNull(const System::Variant &AValue);
	virtual void __fastcall ReadData(System::Classes::TStream* AStream);
	void __fastcall WriteData(System::Classes::TStream* AStream)/* overload */;
	virtual void __fastcall WriteData(System::Classes::TStream* AStream, System::Byte AVersion)/* overload */;
	__property System::UnicodeString DateTimeFormat = {read=FDateTimeFormat, write=SetDateTimeFormat};
	__property System::UnicodeString FilterCaption = {read=GetFilterCaption};
	__property System::UnicodeString FilterText = {read=GetFilterText, write=SetFilterText};
	__property bool CompareByDisplayValues = {read=FCompareByDisplayValues, write=FCompareByDisplayValues, nodefault};
	__property TcxFilterCriteriaItemList* Root = {read=FRoot};
	__property bool StoreItemLinkNames = {read=GetStoreItemLinkNames, write=SetStoreItemLinkNames, nodefault};
	__property bool SupportedLike = {read=FSupportedLike, write=FSupportedLike, default=1};
	__property bool TranslateBetween = {read=FTranslateBetween, write=FTranslateBetween, default=0};
	__property bool TranslateIn = {read=FTranslateIn, write=FTranslateIn, default=0};
	__property bool TranslateLike = {read=FTranslateLike, write=FTranslateLike, default=0};
	
__published:
	__property int MaxValueListCount = {read=FMaxValueListCount, write=FMaxValueListCount, default=0};
	__property TcxFilterCriteriaOptions Options = {read=GetOptions, write=SetOptions, default=0};
	__property System::WideChar PercentWildcard = {read=FPercentWildcard, write=SetPercentWildcard, default=37};
	__property System::WideChar UnderscoreWildcard = {read=FUnderscoreWildcard, write=SetUnderscoreWildcard, default=95};
	__property System::Classes::TNotifyEvent OnChanged = {read=FOnChanged, write=FOnChanged};
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 cxFilterCriteriaVersion1 = System::Int8(0x1);
static const System::Int8 cxFilterCriteriaVersion2 = System::Int8(0x2);
static const System::Int8 cxFilterCriteriaVersion3 = System::Int8(0x3);
static const System::Int8 cxFilterCriteriaVersion4 = System::Int8(0x4);
static const System::Int8 cxFilterCriteriaVersion5 = System::Int8(0x5);
static const System::Int8 cxFilterCriteriaVersion6 = System::Int8(0x6);
static const System::Int8 cxFilterCriteriaLastVersion = System::Int8(0x6);
extern DELPHI_PACKAGE TcxFilterCriteriaDisplayStyle dxFilterCriteriaDisplayStyle;
extern DELPHI_PACKAGE bool cxFilterIncludeTodayInLastNextDaysList;
extern DELPHI_PACKAGE System::UnicodeString __fastcall ExtractFilterDisplayValue(const System::UnicodeString AValues, int &Pos);
extern DELPHI_PACKAGE System::UnicodeString __fastcall VarBetweenArrayToStr(const System::Variant &AValue);
extern DELPHI_PACKAGE System::UnicodeString __fastcall VarListArrayToStr(const System::Variant &AValue);
extern DELPHI_PACKAGE bool __fastcall IsOperatorSupportedForExpression(TcxFilterOperatorKind AOperator);
}	/* namespace Cxfilter */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXFILTER)
using namespace Cxfilter;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxfilterHPP
