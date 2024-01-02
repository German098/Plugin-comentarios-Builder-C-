// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxCultureInfo.pas' rev: 35.00 (Windows)

#ifndef DxcultureinfoHPP
#define DxcultureinfoHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.SysUtils.hpp>
#include <Winapi.Windows.hpp>
#include <System.Generics.Defaults.hpp>
#include <System.Generics.Collections.hpp>
#include <cxDateUtils.hpp>

//-- user supplied -----------------------------------------------------------

namespace Dxcultureinfo
{
//-- forward type declarations -----------------------------------------------
struct TdxNumberFormatInfo;
struct TdxCultureInfo;
struct TdxLangInfo;
class DELPHICLASS TdxCultureInfoHelper;
//-- type declarations -------------------------------------------------------
typedef TdxCultureInfo *PdxCultureInfo;

typedef System::Sysutils::TFormatSettings *PdxFormatSettings;

struct DECLSPEC_DRECORD TdxNumberFormatInfo
{
private:
	System::Sysutils::TFormatSettings FFormatSettings;
	System::DynamicArray<int> FNumberGroupSizes;
	System::WideChar __fastcall GetNumberDecimalSeparator();
	System::WideChar __fastcall GetNumberGroupSeparator();
	void __fastcall Initialize();
	void __fastcall SetNumberDecimalSeparator(const System::WideChar Value);
	void __fastcall SetNumberGroupSeparator(const System::WideChar Value);
	
public:
	__fastcall TdxNumberFormatInfo(const System::Sysutils::TFormatSettings &AFormatSettings)/* overload */;
	__property System::Sysutils::TFormatSettings FormatSettings = {read=FFormatSettings};
	__property System::WideChar NumberDecimalSeparator = {read=GetNumberDecimalSeparator, write=SetNumberDecimalSeparator};
	__property System::WideChar NumberGroupSeparator = {read=GetNumberGroupSeparator, write=SetNumberGroupSeparator};
	__property System::DynamicArray<int> NumberGroupSizes = {read=FNumberGroupSizes, write=FNumberGroupSizes};
	TdxNumberFormatInfo() {}
};


typedef TdxNumberFormatInfo *PdxNumberFormatInfo;

struct DECLSPEC_DRECORD TdxCultureInfo
{
private:
	int FLCID;
	TdxNumberFormatInfo FNumberFormatInfo;
	TdxCultureInfo __fastcall GetParent();
	
private:
	Cxdateutils::TcxCustomCalendarTable* __fastcall GetCalendar();
	System::UnicodeString __fastcall GetEnglishName();
	System::Sysutils::TFormatSettings __fastcall GetFormatSettings();
	static TdxCultureInfo __fastcall GetInvariantCulture();
	
public:
	__fastcall TdxCultureInfo(const int LCID, bool AUseUserOverride)/* overload */;
	__fastcall TdxCultureInfo(const System::UnicodeString AName, bool AUseUserOverride)/* overload */;
	static bool __fastcall _op_Equality(const TdxCultureInfo &A, const TdxCultureInfo &B);
	TdxCultureInfo __fastcall Clone();
	static TdxCultureInfo __fastcall CurrentCulture();
	static TdxCultureInfo __fastcall InvalidCulture();
	bool __fastcall IsValid();
	__property Cxdateutils::TcxCustomCalendarTable* Calendar = {read=GetCalendar};
	__property System::UnicodeString EnglishName = {read=GetEnglishName};
	__property System::Sysutils::TFormatSettings FormatSettings = {read=GetFormatSettings};
	/* static */ __property TdxCultureInfo InvariantCulture = {read=GetInvariantCulture};
	__property int LCID = {read=FLCID};
	__property TdxNumberFormatInfo NumberFormat = {read=FNumberFormatInfo};
	__property TdxCultureInfo Parent = {read=GetParent};
	TdxCultureInfo() {}
	
	friend bool operator ==(const TdxCultureInfo &A, const TdxCultureInfo &B) { return TdxCultureInfo::_op_Equality(A, B); }
};


struct DECLSPEC_DRECORD TdxLangInfo
{
private:
	TdxCultureInfo FLatin;
	TdxCultureInfo FBidi;
	TdxCultureInfo FEastAsia;
	
public:
	__fastcall TdxLangInfo(const TdxCultureInfo &ALatin, const TdxCultureInfo &ABidi, const TdxCultureInfo &AEastAsia);
	static bool __fastcall _op_Equality(const TdxLangInfo &A, const TdxLangInfo &B);
	bool __fastcall Equals(const TdxLangInfo &Value);
	bool __fastcall IsValid();
	static TdxLangInfo __fastcall InvalidLangInfo();
	__property TdxCultureInfo Latin = {read=FLatin};
	__property TdxCultureInfo Bidi = {read=FBidi};
	__property TdxCultureInfo EastAsia = {read=FEastAsia};
	TdxLangInfo() {}
	
	friend bool operator ==(const TdxLangInfo &A, const TdxLangInfo &B) { return TdxLangInfo::_op_Equality(A, B); }
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCultureInfoHelper : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	static System::Generics::Collections::TDictionary__2<int,System::UnicodeString>* FDictionary;
	
private:
	static void __fastcall Initialize();
	static void __fastcall Finalize();
	
public:
	static TdxCultureInfo __fastcall CreateCultureInfo(int AKey);
public:
	/* TObject.Create */ inline __fastcall TdxCultureInfoHelper() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxCultureInfoHelper() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxcultureinfo */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXCULTUREINFO)
using namespace Dxcultureinfo;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxcultureinfoHPP
