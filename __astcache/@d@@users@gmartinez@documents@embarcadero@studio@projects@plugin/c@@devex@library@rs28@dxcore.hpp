// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxCore.pas' rev: 35.00 (Windows)

#ifndef DxcoreHPP
#define DxcoreHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.Windows.hpp>
#include <Vcl.Graphics.hpp>
#include <System.UITypes.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <System.Variants.hpp>
#include <System.Character.hpp>
#include <System.Contnrs.hpp>
#include <System.AnsiStrings.hpp>
#include <System.Generics.Defaults.hpp>
#include <System.Generics.Collections.hpp>
#include <System.Types.hpp>

//-- user supplied -----------------------------------------------------------

namespace Dxcore
{
//-- forward type declarations -----------------------------------------------
__interface DELPHIINTERFACE IdxLocalizerListener;
typedef System::DelphiInterface<IdxLocalizerListener> _di_IdxLocalizerListener;
__interface DELPHIINTERFACE IdxDebugVisualizer;
typedef System::DelphiInterface<IdxDebugVisualizer> _di_IdxDebugVisualizer;
class DELPHICLASS TdxByteArray;
class DELPHICLASS TdxStream;
class DELPHICLASS TdxProductResourceStrings;
class DELPHICLASS TdxResourceStringsRepository;
class DELPHICLASS Safe;
template<typename T> class DELPHICLASS Safe__1;
struct TdxProcRec;
class DELPHICLASS TdxProcList;
class DELPHICLASS TdxUnitsLoader;
class DELPHICLASS EdxException;
class DELPHICLASS EdxTestException;
//-- type declarations -------------------------------------------------------
typedef System::DynamicArray<System::Uitypes::TColor> TColors;

typedef System::DynamicArray<System::Types::TPoint> TPoints;

typedef System::DynamicArray<System::Types::TRect> TRects;

typedef NativeInt *PdxNativeInt;

typedef NativeInt TdxNativeInt;

typedef NativeUInt *PdxNativeUInt;

typedef NativeUInt TdxNativeUInt;

typedef void * TcxResourceStringID;

typedef System::StaticArray<System::Types::TRect, 1> TRectArray;

typedef TRectArray *PRectArray;

enum DECLSPEC_DENUM TdxDefaultBoolean : unsigned char { bFalse, bTrue, bDefault };

enum DECLSPEC_DENUM TdxObjectOwnership : unsigned char { ooOwned, ooReferenced, ooCloned };

enum DECLSPEC_DENUM TdxCorner : unsigned char { coTopLeft, coTopRight, coBottomLeft, coBottomRight };

typedef System::Set<TdxCorner, TdxCorner::coTopLeft, TdxCorner::coBottomRight> TdxCorners;

enum DECLSPEC_DENUM TdxSortOrder : unsigned char { soNone, soAscending, soDescending };

enum DECLSPEC_DENUM TdxOrientation : unsigned char { orHorizontal, orVertical };

enum DECLSPEC_DENUM TdxDirectedOrientation : unsigned char { doLeftToRight, doTopToBottom, doBottomToTop, doRightToLeft };

enum DECLSPEC_DENUM TdxTextOrientation : unsigned char { toLeftToRight, toTopToBottom, toBottomToTop };

typedef System::StaticArray<System::WideChar *, 1> TdxPWideCharArray;

typedef TdxPWideCharArray *PdxPWideCharArray;

__interface  INTERFACE_UUID("{8410B6D7-1A56-4599-4FE3-AE8C0E182032}") IdxLocalizerListener  : public System::IInterface 
{
	virtual void __fastcall TranslationChanged() = 0 ;
};

__interface  INTERFACE_UUID("{159F61D6-24F4-47B6-A635-9AD95A904780}") IdxDebugVisualizer  : public System::IInterface 
{
	virtual System::UnicodeString __fastcall GetDebugVisualizerData() = 0 ;
};

typedef System::Set<char, _DELPHI_SET_CHAR(0), _DELPHI_SET_CHAR(255)> TdxAnsiCharSet;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxByteArray : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod System::DynamicArray<System::Byte> __fastcall Clone(const System::DynamicArray<System::Byte> ABytes)/* overload */;
	__classmethod System::DynamicArray<System::Byte> __fastcall Clone(const System::DynamicArray<System::Byte> ABytes, int AMaxLength)/* overload */;
	__classmethod bool __fastcall Compare(const System::DynamicArray<System::Byte> AB1, const System::DynamicArray<System::Byte> AB2);
	__classmethod System::DynamicArray<System::Byte> __fastcall Concatenate(int ANum, const System::DynamicArray<System::Byte> ABytes)/* overload */;
	__classmethod System::DynamicArray<System::Byte> __fastcall Concatenate(const System::DynamicArray<System::Byte> AB1, const System::DynamicArray<System::Byte> AB2)/* overload */;
	__classmethod System::DynamicArray<System::Byte> __fastcall Concatenate(const System::DynamicArray<System::Byte> ABytes, int ANum)/* overload */;
	__classmethod System::DynamicArray<System::Byte> __fastcall Resize(const System::DynamicArray<System::Byte> ABytes, int ATargetSize, System::Byte AFillBy = (System::Byte)(0x0));
public:
	/* TObject.Create */ inline __fastcall TdxByteArray() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxByteArray() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxStream : public System::Classes::TStream
{
	typedef System::Classes::TStream inherited;
	
private:
	bool FIsUnicode;
	System::Classes::TStream* FStream;
	
protected:
	virtual __int64 __fastcall GetSize();
	
public:
	__fastcall virtual TdxStream(System::Classes::TStream* AStream);
	virtual int __fastcall Read(void *Buffer, int Count)/* overload */;
	virtual int __fastcall Seek(int Offset, System::Word Origin)/* overload */;
	virtual int __fastcall Write(const void *Buffer, int Count)/* overload */;
	__property bool IsUnicode = {read=FIsUnicode, nodefault};
	__property System::Classes::TStream* Stream = {read=FStream};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxStream() { }
	
	/* Hoisted overloads: */
	
public:
	inline int __fastcall  Read(System::DynamicArray<System::Byte> Buffer, int Offset, int Count){ return System::Classes::TStream::Read(Buffer, Offset, Count); }
	inline int __fastcall  Read(System::DynamicArray<System::Byte> &Buffer, int Count){ return System::Classes::TStream::Read(Buffer, Count); }
	inline __int64 __fastcall  Seek(const __int64 Offset, System::Classes::TSeekOrigin Origin){ return System::Classes::TStream::Seek(Offset, Origin); }
	inline __int64 __fastcall  Seek(const __int64 Offset, System::Word Origin){ return System::Classes::TStream::Seek(Offset, Origin); }
	inline int __fastcall  Write(const System::DynamicArray<System::Byte> Buffer, int Offset, int Count){ return System::Classes::TStream::Write(Buffer, Offset, Count); }
	inline int __fastcall  Write(const System::DynamicArray<System::Byte> Buffer, int Count){ return System::Classes::TStream::Write(Buffer, Count); }
	
};

#pragma pack(pop)

typedef void __fastcall (*TdxAddResourceStringsProcedure)(TdxProductResourceStrings* AProduct);

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxProductResourceStrings : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::UnicodeString FName;
	System::Classes::TList* FInitializeProcedures;
	System::Classes::TStrings* FResStringNames;
	System::UnicodeString __fastcall GetNames(int AIndex);
	int __fastcall GetResStringsCount();
	void __fastcall SetTranslation(int AIndex);
	System::UnicodeString __fastcall GetValues(int AIndex);
	
protected:
	void __fastcall AddProcedure(TdxAddResourceStringsProcedure AProc);
	void __fastcall RemoveProcedure(TdxAddResourceStringsProcedure AProc);
	void __fastcall Translate();
	__property System::Classes::TList* InitializeProcedures = {read=FInitializeProcedures};
	
public:
	__fastcall virtual TdxProductResourceStrings(const System::UnicodeString AName, TdxAddResourceStringsProcedure AInitializeProc);
	__fastcall virtual ~TdxProductResourceStrings();
	void __fastcall Add(const System::UnicodeString AResStringName, void * AResStringAddr);
	void __fastcall Clear();
	int __fastcall GetIndexByName(const System::UnicodeString AName);
	__property System::UnicodeString Name = {read=FName};
	__property System::UnicodeString Names[int AIndex] = {read=GetNames};
	__property int ResStringsCount = {read=GetResStringsCount, nodefault};
	__property System::UnicodeString Values[int AIndex] = {read=GetValues};
};

#pragma pack(pop)

typedef void __fastcall (__closure *TdxLocalizationTranslateResStringEvent)(const System::UnicodeString AResStringName, void * AResString);

class PASCALIMPLEMENTATION TdxResourceStringsRepository : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Classes::TList* FListeners;
	System::Contnrs::TObjectList* FProducts;
	TdxLocalizationTranslateResStringEvent FOnTranslateResString;
	TdxProductResourceStrings* __fastcall GetProducts(int AIndex);
	int __fastcall GetProductsCount();
	
public:
	__fastcall virtual TdxResourceStringsRepository();
	__fastcall virtual ~TdxResourceStringsRepository();
	void __fastcall AddListener(_di_IdxLocalizerListener AListener);
	void __fastcall RemoveListener(_di_IdxLocalizerListener AListener);
	void __fastcall NotifyListeners();
	void __fastcall RegisterProduct(const System::UnicodeString AProductName, TdxAddResourceStringsProcedure AAddStringsProc);
	int __fastcall GetProductIndexByName(const System::UnicodeString AName);
	System::UnicodeString __fastcall GetOriginalValue(const System::UnicodeString AName);
	void __fastcall Translate();
	void __fastcall UnRegisterProduct(const System::UnicodeString AProductName, TdxAddResourceStringsProcedure AAddStringsProc = 0x0);
	__property TdxProductResourceStrings* Products[int Index] = {read=GetProducts};
	__property int ProductsCount = {read=GetProductsCount, nodefault};
	__property TdxLocalizationTranslateResStringEvent OnTranslateResString = {read=FOnTranslateResString, write=FOnTranslateResString};
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION Safe : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod bool __fastcall Cast(System::TObject* const AObject, const System::TClass AClass, /* out */ void *AValue);
public:
	/* TObject.Create */ inline __fastcall Safe() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~Safe() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename T> class PASCALIMPLEMENTATION Safe__1 : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod T __fastcall Cast(System::TObject* AObject);
public:
	/* TObject.Create */ inline __fastcall Safe__1() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~Safe__1() { }
	
};

#pragma pack(pop)

typedef void __fastcall (*TdxProc)(void);

struct DECLSPEC_DRECORD TdxProcRec
{
public:
	System::UnicodeString UnitName;
	TdxProc Proc;
	NativeUInt hInstance;
};


class PASCALIMPLEMENTATION TdxProcList : public System::Generics::Collections::TList__1<TdxProcRec>
{
	typedef System::Generics::Collections::TList__1<TdxProcRec> inherited;
	
private:
	int __fastcall RemoveProc(TdxProc AProc);
public:
	/* {System_Generics_Collections}TList<dxCore_TdxProcRec>.Create */ inline __fastcall TdxProcList()/* overload */ : System::Generics::Collections::TList__1<TdxProcRec>() { }
	/* {System_Generics_Collections}TList<dxCore_TdxProcRec>.Create */ inline __fastcall TdxProcList(const System::DelphiInterface<System::Generics::Defaults::IComparer__1<TdxProcRec> > AComparer)/* overload */ : System::Generics::Collections::TList__1<TdxProcRec>(AComparer) { }
	/* {System_Generics_Collections}TList<dxCore_TdxProcRec>.Create */ inline __fastcall TdxProcList(System::Generics::Collections::TEnumerable__1<TdxProcRec>* const Collection)/* overload */ : System::Generics::Collections::TList__1<TdxProcRec>(Collection) { }
	/* {System_Generics_Collections}TList<dxCore_TdxProcRec>.Create */ inline __fastcall TdxProcList(const TdxProcRec *Values, const int Values_High)/* overload */ : System::Generics::Collections::TList__1<TdxProcRec>(Values, Values_High) { }
	/* {System_Generics_Collections}TList<dxCore_TdxProcRec>.Destroy */ inline __fastcall virtual ~TdxProcList() { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxUnitsLoader : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	TdxProcList* FinalizeList;
	TdxProcList* InitializeList;
	void __fastcall CallProc(TdxProc AProc);
	
public:
	__fastcall TdxUnitsLoader();
	__fastcall virtual ~TdxUnitsLoader();
	void __fastcall AddUnit(NativeUInt AhInstance, const System::UnicodeString AUnitName, const TdxProc AInitializeProc, const TdxProc AFinalizeProc);
	void __fastcall RemoveUnit(NativeUInt AhInstance, const System::UnicodeString AUnitName, const TdxProc AFinalizeProc);
	void __fastcall Finalize();
	void __fastcall Initialize();
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION EdxException : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EdxException(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EdxException(const System::UnicodeString Msg, const System::TVarRec *Args, const int Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EdxException(NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EdxException(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxException(NativeUInt Ident, const System::TVarRec *Args, const int Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const int Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EdxException(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EdxException(const System::UnicodeString Msg, const System::TVarRec *Args, const int Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxException(NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxException(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const int Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxException(NativeUInt Ident, const System::TVarRec *Args, const int Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EdxException() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION EdxTestException : public EdxException
{
	typedef EdxException inherited;
	
public:
	/* Exception.Create */ inline __fastcall EdxTestException(const System::UnicodeString Msg) : EdxException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EdxTestException(const System::UnicodeString Msg, const System::TVarRec *Args, const int Args_High) : EdxException(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EdxTestException(NativeUInt Ident)/* overload */ : EdxException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EdxTestException(System::PResStringRec ResStringRec)/* overload */ : EdxException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxTestException(NativeUInt Ident, const System::TVarRec *Args, const int Args_High)/* overload */ : EdxException(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxTestException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const int Args_High)/* overload */ : EdxException(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EdxTestException(const System::UnicodeString Msg, int AHelpContext) : EdxException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EdxTestException(const System::UnicodeString Msg, const System::TVarRec *Args, const int Args_High, int AHelpContext) : EdxException(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxTestException(NativeUInt Ident, int AHelpContext)/* overload */ : EdxException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxTestException(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : EdxException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxTestException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const int Args_High, int AHelpContext)/* overload */ : EdxException(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxTestException(NativeUInt Ident, const System::TVarRec *Args, const int Args_High, int AHelpContext)/* overload */ : EdxException(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EdxTestException() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static const int dxVersion = int(0x134afd7);
extern DELPHI_PACKAGE unsigned dxBuildNumber;
extern DELPHI_PACKAGE System::Word dxUnicodePrefix;
static const System::WideChar dxTab = (System::WideChar)(0x9);
static const System::WideChar dxLF = (System::WideChar)(0xa);
static const System::WideChar dxCR = (System::WideChar)(0xd);
static const System::WideChar dxSpace = (System::WideChar)(0x20);
#define dxCRLF L"\r\n"
static const System::WideChar dxVKSelectAll = (System::WideChar)(0x1);
static const System::WideChar dxVKCopy = (System::WideChar)(0x3);
static const System::WideChar dxVKPaste = (System::WideChar)(0x16);
static const System::WideChar dxVKCut = (System::WideChar)(0x18);
static const System::WideChar dxVKBack = (System::WideChar)(0x8);
static const System::WideChar dxVKTab = (System::WideChar)(0x9);
static const System::WideChar dxVKReturn = (System::WideChar)(0xd);
static const System::WideChar dxVKEscape = (System::WideChar)(0x1b);
static const System::WideChar dxVKSpace = (System::WideChar)(0x20);
static const System::WideChar dxVKDelete = (System::WideChar)(0x2e);
#define dxBreakLineCharacters (System::Set<char, _DELPHI_SET_CHAR(0), _DELPHI_SET_CHAR(255)>() << '\xa' << '\xd' )
#define dxSpaceCharacters (System::Set<char, _DELPHI_SET_CHAR(0), _DELPHI_SET_CHAR(255)>() << '\x9' << '\xa' << '\xd' << '\x20' )
static const int MinInt = int(-2147483648);
static const __int64 MinInt64 = (-0x7fffffffffffffffLL-1);
static const __int64 MaxInt64 = 0x7fffffffffffffffLL;
static const System::Int8 dxUserNameUnknown = System::Int8(0x0);
static const System::Int8 dxUserNameFullyQualifiedDN = System::Int8(0x1);
static const System::Int8 dxUserNameSamCompatible = System::Int8(0x2);
static const System::Int8 dxUserNameDisplay = System::Int8(0x3);
static const System::Int8 dxUserNameUniqueId = System::Int8(0x6);
static const System::Int8 dxUserNameCanonical = System::Int8(0x7);
static const System::Int8 dxUserNameUserPrincipal = System::Int8(0x8);
static const System::Int8 dxUserNameCanonicalEx = System::Int8(0x9);
static const System::Int8 dxUserNameServicePrincipal = System::Int8(0xa);
static const System::Int8 dxUserNameDnsDomain = System::Int8(0xc);
#define dxAllCorners (System::Set<TdxCorner, TdxCorner::coTopLeft, TdxCorner::coBottomRight>() << TdxCorner::coTopLeft << TdxCorner::coTopRight << TdxCorner::coBottomLeft << TdxCorner::coBottomRight )
extern DELPHI_PACKAGE bool IsWin9X;
extern DELPHI_PACKAGE bool IsWin95;
extern DELPHI_PACKAGE bool IsWin98;
extern DELPHI_PACKAGE bool IsWinMe;
extern DELPHI_PACKAGE bool IsWinNT;
extern DELPHI_PACKAGE bool IsWin2K;
extern DELPHI_PACKAGE bool IsWin2KOrLater;
extern DELPHI_PACKAGE bool IsWinXP;
extern DELPHI_PACKAGE bool IsWinXPOrLater;
extern DELPHI_PACKAGE bool IsWin2KOrXP;
extern DELPHI_PACKAGE bool IsWinVista;
extern DELPHI_PACKAGE bool IsWinVistaOrLater;
extern DELPHI_PACKAGE bool IsWinSeven;
extern DELPHI_PACKAGE bool IsWinSevenOrLater;
extern DELPHI_PACKAGE bool IsWin8;
extern DELPHI_PACKAGE bool IsWin8OrLater;
extern DELPHI_PACKAGE bool IsWin10OrLater;
extern DELPHI_PACKAGE bool IsWin10v1809OrLater;
extern DELPHI_PACKAGE bool IsWin10v2004OrLater;
extern DELPHI_PACKAGE bool IsWin10FallCreatorsUpdate;
extern DELPHI_PACKAGE bool IsWin11OrLater;
extern DELPHI_PACKAGE bool IsWinSupportsAcrylicEffect;
extern DELPHI_PACKAGE bool IsWin64Bit;
extern DELPHI_PACKAGE bool IsWinServer;
extern DELPHI_PACKAGE System::Sysutils::TFormatSettings dxInvariantFormatSettings;
extern DELPHI_PACKAGE bool dxIsDesignTime;
extern DELPHI_PACKAGE System::TDateTime __fastcall cxFileTimeToDateTime(const _FILETIME &fTime);
extern DELPHI_PACKAGE bool __fastcall dxIsDLL(void);
extern DELPHI_PACKAGE System::LongBool __fastcall dxIsIntResource(System::WideChar * AType);
extern DELPHI_PACKAGE void __fastcall cxCopyData(void * ASource, void * ADestination, int ACount)/* overload */;
extern DELPHI_PACKAGE void __fastcall cxCopyData(void * ASource, void * ADestination, int ASourceOffSet, int ADestinationOffSet, int ACount)/* overload */;
extern DELPHI_PACKAGE System::Word __fastcall dxSwap16(const System::Word AValue);
extern DELPHI_PACKAGE unsigned __fastcall dxSwap32(const unsigned AValue);
extern DELPHI_PACKAGE void __fastcall ExchangeBooleans(bool &AValue1, bool &AValue2);
extern DELPHI_PACKAGE void __fastcall ExchangeIntegers(int &AValue1, int &AValue2);
extern DELPHI_PACKAGE void __fastcall ExchangeLongWords(void *AValue1, void *AValue2);
extern DELPHI_PACKAGE void __fastcall ExchangePointers(void *AValue1, void *AValue2);
extern DELPHI_PACKAGE void __fastcall ExchangeSingle(float &AValue1, float &AValue2);
extern DELPHI_PACKAGE void __fastcall ExchangeStrings(System::UnicodeString &AValue1, System::UnicodeString &AValue2);
extern DELPHI_PACKAGE bool __fastcall ReadBufferFromStream(System::Classes::TStream* AStream, void * ABuffer, int Count);
extern DELPHI_PACKAGE int __fastcall ReadStringFromStream(System::Classes::TStream* AStream, /* out */ System::AnsiString &AValue);
extern DELPHI_PACKAGE int __fastcall dxCompareValues(int A, int B)/* overload */;
extern DELPHI_PACKAGE int __fastcall dxCompareValues(void * A, void * B)/* overload */;
extern DELPHI_PACKAGE bool __fastcall dxSameText(const System::UnicodeString A, const System::UnicodeString B);
extern DELPHI_PACKAGE System::UnicodeString __fastcall dxGetBuildNumberAsString(unsigned ABuildNumber = (unsigned)(0x0));
extern DELPHI_PACKAGE System::UnicodeString __fastcall dxGetShortBuildNumberAsString(unsigned ABuildNumber = (unsigned)(0x0));
extern DELPHI_PACKAGE void __fastcall dxFactorizeBuildNumber(unsigned ABuildNumber, /* out */ int &AMajor, /* out */ int &AMinor, /* out */ int &ABuild);
extern DELPHI_PACKAGE System::UnicodeString __fastcall dxGenerateGUID(void);
extern DELPHI_PACKAGE System::UnicodeString __fastcall dxGenerateID(void);
extern DELPHI_PACKAGE void * __fastcall ShiftPointer(void * P, int AOffset);
extern DELPHI_PACKAGE NativeInt __fastcall dxPointToLParam(const System::Types::TPoint &P);
extern DELPHI_PACKAGE System::Types::TPoint __fastcall dxLParamToPoint(NativeInt AParam);
extern DELPHI_PACKAGE void __fastcall dxCompressStream(System::Classes::TStream* ASourceStream, System::Classes::TStream* ADestStream, System::Byte ACompressMethod, int ASize = 0x0);
extern DELPHI_PACKAGE void __fastcall dxDecompressStream(System::Classes::TStream* ASourceStream, System::Classes::TStream* ADestStream);
extern DELPHI_PACKAGE TdxResourceStringsRepository* __fastcall dxResourceStringsRepository(void);
extern DELPHI_PACKAGE System::UnicodeString __fastcall cxGetResourceString(void * AResString)/* overload */;
extern DELPHI_PACKAGE void __fastcall cxSetResourceString(void * AResString, const System::UnicodeString Value);
extern DELPHI_PACKAGE System::UnicodeString __fastcall cxGetResourceString _DEPRECATED_ATTRIBUTE0 (const System::UnicodeString AResString)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall cxGetResourceStringNet _DEPRECATED_ATTRIBUTE0 (const System::UnicodeString AResString);
extern DELPHI_PACKAGE void __fastcall cxSetResourceStringNet _DEPRECATED_ATTRIBUTE0 (const System::UnicodeString AResString, const System::UnicodeString Value);
extern DELPHI_PACKAGE void __fastcall cxClearResourceStrings(void);
extern DELPHI_PACKAGE bool __fastcall dxFindLocalizedResourceString(const System::UnicodeString AdxResourceString, /* out */ System::UnicodeString &ALocalizedString);
extern DELPHI_PACKAGE System::UnicodeString __fastcall dxGetSystemResourceString(NativeUInt ALibraryHandle, const int AStringID, const System::UnicodeString ADefaultValue = System::UnicodeString());
extern DELPHI_PACKAGE System::UnicodeString __fastcall dxGetLocalizedSystemResourceString(const System::UnicodeString AdxResourceString, NativeUInt ALibraryHandle, const int AStringID)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall dxGetLocalizedSystemResourceString(const System::UnicodeString AdxResourceString, const System::UnicodeString ALibraryName, const int AStringID)/* overload */;
extern DELPHI_PACKAGE void __fastcall WriteBoolean(void * ADestination, System::WordBool AValue, int AOffset = 0x0);
extern DELPHI_PACKAGE void __fastcall WriteByte(void * ADestination, System::Byte AValue, int AOffset = 0x0);
extern DELPHI_PACKAGE void __fastcall WriteInteger(void * ADestination, int AValue, int AOffset = 0x0);
extern DELPHI_PACKAGE void __fastcall WritePointer(void * ADestination, void * AValue);
extern DELPHI_PACKAGE void __fastcall WriteWord(void * ADestination, System::Word AValue, int AOffset = 0x0);
extern DELPHI_PACKAGE void __fastcall dxWriteStr(System::Classes::TStream* Stream, const System::UnicodeString S);
extern DELPHI_PACKAGE NativeUInt __fastcall dxStreamToHGlobal(System::Classes::TMemoryStream* AStream);
extern DELPHI_PACKAGE System::Variant __fastcall dxStreamToVariant(System::Classes::TStream* AStream)/* overload */;
extern DELPHI_PACKAGE System::Variant __fastcall dxStreamToVariant(System::Classes::TStream* AStream, int ASize)/* overload */;
extern DELPHI_PACKAGE bool __fastcall dxCanReadMemory(void * P, unsigned ASize);
extern DELPHI_PACKAGE System::Word __fastcall dxGetAnsiCharCType1(char Ch);
extern DELPHI_PACKAGE System::Word __fastcall dxGetWideCharCType1(System::WideChar Ch);
extern DELPHI_PACKAGE void __fastcall cxZeroMemory(void * ADestination, int ACount);
extern DELPHI_PACKAGE void * __fastcall cxAllocMem(unsigned Size);
extern DELPHI_PACKAGE void __fastcall cxFreeMem(void * P);
extern DELPHI_PACKAGE bool __fastcall dxAnsiIsAlpha(char Ch);
extern DELPHI_PACKAGE bool __fastcall dxCharIsAlpha(System::WideChar Ch);
extern DELPHI_PACKAGE bool __fastcall dxWideIsAlpha(System::WideChar Ch);
extern DELPHI_PACKAGE bool __fastcall dxAnsiIsNumeric(char Ch);
extern DELPHI_PACKAGE bool __fastcall dxCharIsNumeric(System::WideChar Ch);
extern DELPHI_PACKAGE bool __fastcall dxWideIsNumeric(System::WideChar Ch);
extern DELPHI_PACKAGE bool __fastcall dxWideIsSpace(System::WideChar Ch);
extern DELPHI_PACKAGE bool __fastcall dxIsWhiteSpace(System::WideChar AChar);
extern DELPHI_PACKAGE bool __fastcall dxIsLowerCase(System::WideChar AChar);
extern DELPHI_PACKAGE System::WideChar __fastcall dxLowerCase(System::WideChar AChar);
extern DELPHI_PACKAGE System::WideChar __fastcall dxUpperCase(System::WideChar AChar);
extern DELPHI_PACKAGE int __fastcall dxStrComp(const char * Str1, const char * Str2);
extern DELPHI_PACKAGE char * __fastcall dxStrCopy(char * ADest, const char * ASource);
extern DELPHI_PACKAGE char * __fastcall dxStrLCopy(char * ADest, const char * ASource, unsigned AMaxLen);
extern DELPHI_PACKAGE unsigned __fastcall dxStrLen(const char * AStr);
extern DELPHI_PACKAGE int __fastcall dxGetCodePageFromCharset(int ACharset);
extern DELPHI_PACKAGE System::WideString __fastcall dxAnsiStringToWideString(const System::AnsiString ASource, unsigned ACodePage = (unsigned)(0x0));
extern DELPHI_PACKAGE System::AnsiString __fastcall dxWideStringToAnsiString(const System::WideString ASource, unsigned ACodePage = (unsigned)(0x0));
extern DELPHI_PACKAGE int __fastcall dxAnsiStrToInt(const System::AnsiString S);
extern DELPHI_PACKAGE System::UnicodeString __fastcall dxConcatenateStrings(System::WideChar * const *AStrings, const int AStrings_High);
extern DELPHI_PACKAGE void __fastcall dxStringToBytes(const System::UnicodeString S, void *Buf);
extern DELPHI_PACKAGE System::Extended __fastcall dxStrToFloat(const System::UnicodeString S, const System::WideChar ADecimalSeparator = (System::WideChar)(0x2e));
extern DELPHI_PACKAGE System::Extended __fastcall dxStrToFloatDef(const System::UnicodeString S, const System::WideChar ADecimalSeparator = (System::WideChar)(0x2e), System::Extended ADefaultValue = 0.000000E+00);
extern DELPHI_PACKAGE System::UnicodeString __fastcall dxFloatToStr(System::Extended AValue, System::WideChar ADecimalSeparator = (System::WideChar)(0x2e));
extern DELPHI_PACKAGE System::UnicodeString __fastcall RemoveAccelChars(const System::UnicodeString S, bool AAppendTerminatingUnderscore = true);
extern DELPHI_PACKAGE System::AnsiString __fastcall dxUTF8StringToAnsiString(const System::UTF8String S);
extern DELPHI_PACKAGE System::UTF8String __fastcall dxAnsiStringToUTF8String(const System::AnsiString S);
extern DELPHI_PACKAGE System::UnicodeString __fastcall dxUTF8StringToString(const System::UTF8String S);
extern DELPHI_PACKAGE System::WideString __fastcall dxUTF8StringToWideString(const System::UTF8String S);
extern DELPHI_PACKAGE System::UTF8String __fastcall dxStringToUTF8String(const System::UnicodeString S);
extern DELPHI_PACKAGE System::UTF8String __fastcall dxWideStringToUTF8String(const System::WideString S);
extern DELPHI_PACKAGE System::AnsiString __fastcall dxAnsiStringReplace(const System::AnsiString AString, const System::AnsiString AOldPattern, const System::AnsiString ANewPattern, System::Sysutils::TReplaceFlags AFlags);
extern DELPHI_PACKAGE System::UnicodeString __fastcall dxAnsiStringToString(const System::AnsiString S, int ACodePage = 0x0);
extern DELPHI_PACKAGE System::AnsiString __fastcall dxStringToAnsiString(const System::UnicodeString S, int ACodePage = 0x0);
extern DELPHI_PACKAGE System::UnicodeString __fastcall dxVariantToString(const System::Variant &V);
extern DELPHI_PACKAGE System::AnsiString __fastcall dxVariantToAnsiString(const System::Variant &V);
extern DELPHI_PACKAGE System::WordBool __fastcall ReadBoolean(void * ASource, int AOffset = 0x0);
extern DELPHI_PACKAGE System::Byte __fastcall ReadByte(void * ASource, int AOffset = 0x0);
extern DELPHI_PACKAGE int __fastcall ReadInteger(void * ASource, int AOffset = 0x0);
extern DELPHI_PACKAGE void * __fastcall ReadPointer(void * ASource);
extern DELPHI_PACKAGE System::Word __fastcall ReadWord(void * ASource, int AOffset = 0x0);
extern DELPHI_PACKAGE void __fastcall dxFillChar(void *ADest, int Count, const System::WideChar APattern);
extern DELPHI_PACKAGE void __fastcall dxFreeAndNil(void *AObject);
extern DELPHI_PACKAGE void __fastcall dxAppendList(System::Classes::TList* ASource, System::Classes::TList* ADestination);
extern DELPHI_PACKAGE void __fastcall dxCopyList(System::Classes::TList* ASource, System::Classes::TList* ADestination);
extern DELPHI_PACKAGE void __fastcall dxWriteStandardEncodingSignature(System::Classes::TStream* AStream);
extern DELPHI_PACKAGE int __fastcall WriteBufferToStream(System::Classes::TStream* AStream, void * ABuffer, int ACount);
extern DELPHI_PACKAGE int __fastcall WriteCharToStream(System::Classes::TStream* AStream, char AValue);
extern DELPHI_PACKAGE int __fastcall WriteDoubleToStream(System::Classes::TStream* AStream, double AValue);
extern DELPHI_PACKAGE int __fastcall WriteIntegerToStream(System::Classes::TStream* AStream, int AValue);
extern DELPHI_PACKAGE int __fastcall WriteSmallIntToStream(System::Classes::TStream* AStream, short AValue);
extern DELPHI_PACKAGE int __fastcall WriteStringToStream(System::Classes::TStream* AStream, const System::AnsiString AValue);
extern DELPHI_PACKAGE System::UnicodeString __fastcall dxReadStr(System::Classes::TStream* Stream, bool AIsUnicode);
extern DELPHI_PACKAGE void __fastcall dxWriteStreamType(System::Classes::TStream* AStream);
extern DELPHI_PACKAGE System::UnicodeString __fastcall dxCreateTempFile(const System::UnicodeString AExtension = System::UnicodeString());
extern DELPHI_PACKAGE bool __fastcall dxIsPathDelimiter(const System::UnicodeString S, int Index, const System::WideChar APathDelimiter = (System::WideChar)(0x5c));
extern DELPHI_PACKAGE System::UnicodeString __fastcall dxExcludeTrailingPathDelimiter(const System::UnicodeString APath, const System::WideChar APathDelimiter = (System::WideChar)(0x5c));
extern DELPHI_PACKAGE System::UnicodeString __fastcall dxExtractFileName(const System::UnicodeString APath, const System::WideChar APathDelimiter = (System::WideChar)(0x5c));
extern DELPHI_PACKAGE System::UnicodeString __fastcall dxIncludeTrailingPathDelimiter(const System::UnicodeString APath, const System::WideChar APathDelimiter = (System::WideChar)(0x5c));
extern DELPHI_PACKAGE System::AnsiString __fastcall dxReplacePathDelimiter(const System::AnsiString APath, const char AOldDelimiter, const char ANewDelimiter)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall dxReplacePathDelimiter(const System::UnicodeString APath, const System::WideChar AOldDelimiter, const System::WideChar ANewDelimiter)/* overload */;
extern DELPHI_PACKAGE System::LongBool __fastcall dxGetStringTypeA(unsigned Locale, unsigned dwInfoType, const char * lpSrcStr, int cchSrc, void *lpCharType);
extern DELPHI_PACKAGE System::LongBool __fastcall dxGetStringTypeW(unsigned dwInfoType, const System::WideChar * lpSrcStr, int cchSrc, void *lpCharType);
extern DELPHI_PACKAGE bool __fastcall dxVarIsBlob(const System::Variant &V);
extern DELPHI_PACKAGE System::UnicodeString __fastcall dxShortStringToString(const System::ShortString &S);
extern DELPHI_PACKAGE System::ShortString __fastcall dxStringToShortString(const System::UnicodeString S);
extern DELPHI_PACKAGE bool __fastcall dxIsUnicodeStream(System::Classes::TStream* AStream);
extern DELPHI_PACKAGE void __fastcall dxAbstractError(void);
extern DELPHI_PACKAGE void __fastcall dxTestCheck(System::WordBool AValue, const System::UnicodeString AMessage);
extern DELPHI_PACKAGE void __fastcall dxCheckOrientation(TdxOrientation &AValue, TdxOrientation ADefaultOrientation);
extern DELPHI_PACKAGE void __fastcall dxShowException(System::TObject* AException);
extern DELPHI_PACKAGE int __fastcall dxGetInvariantLocaleID(void);
extern DELPHI_PACKAGE void __fastcall dxGetLocaleFormatSettings(int ALocale, System::Sysutils::TFormatSettings &AFormatSettings);
extern DELPHI_PACKAGE System::UnicodeString __fastcall dxGetLocaleInfo(int ALocale, int ALocaleType, const System::UnicodeString ADefaultValue = System::UnicodeString());
extern DELPHI_PACKAGE System::Word __fastcall dxMakeLangID(System::Word APrimaryLang, System::Word ASubLang);
extern DELPHI_PACKAGE unsigned __fastcall dxMakeLCID(System::Word ALangId, System::Word ASortId);
extern DELPHI_PACKAGE System::Word __fastcall dxGetSubLangID(System::Word ALangId);
extern DELPHI_PACKAGE System::UnicodeString __fastcall dxGetUserName(void);
extern DELPHI_PACKAGE System::UnicodeString __fastcall dxGetUserNameEx(unsigned AFormat);
extern DELPHI_PACKAGE bool __fastcall dxShellExecute(HWND AHandle, const System::UnicodeString AFileName, int AShowCmd = 0x1)/* overload */;
extern DELPHI_PACKAGE bool __fastcall dxShellExecute(const System::UnicodeString AFileName, int AShowCmd = 0x1)/* overload */;
extern DELPHI_PACKAGE void __fastcall dxCallNotify(System::Classes::TNotifyEvent ANotifyEvent, System::TObject* ASender);
extern DELPHI_PACKAGE __int64 __fastcall dxGetTickCount(void);
extern DELPHI_PACKAGE bool __fastcall dxSameMethods(const void *Method1, const void *Method2);
extern DELPHI_PACKAGE TdxDefaultBoolean __fastcall dxBooleanToDefaultBoolean(bool AValue);
extern DELPHI_PACKAGE bool __fastcall dxDefaultBooleanToBoolean(TdxDefaultBoolean AValue, bool ADefault);
extern DELPHI_PACKAGE __int64 __fastcall dxMakeInt64(const int A, const int B);
extern DELPHI_PACKAGE float __fastcall dxFMod(const float ANumerator, const float ADenominator)/* overload */;
extern DELPHI_PACKAGE double __fastcall dxFMod(const double ANumerator, const double ADenominator)/* overload */;
extern DELPHI_PACKAGE System::Extended __fastcall dxFMod(const System::Extended ANumerator, const System::Extended ADenominator)/* overload */;
extern DELPHI_PACKAGE System::AnsiString __fastcall dxBinToHex(const System::AnsiString ABuffer)/* overload */;
extern DELPHI_PACKAGE System::AnsiString __fastcall dxBinToHex(const char * ABuffer, int ABufSize)/* overload */;
extern DELPHI_PACKAGE System::AnsiString __fastcall dxHexToBin(const System::AnsiString AText)/* overload */;
extern DELPHI_PACKAGE System::AnsiString __fastcall dxHexToBin(const char * AText)/* overload */;
extern DELPHI_PACKAGE System::Byte __fastcall dxHexToByte(const System::UnicodeString AHex);
extern DELPHI_PACKAGE int __fastcall dxCharCount(const System::UnicodeString S);
extern DELPHI_PACKAGE bool __fastcall dxCharInSet(System::WideChar C, const TdxAnsiCharSet &ACharSet);
extern DELPHI_PACKAGE int __fastcall dxStringSize(const System::UnicodeString S);
extern DELPHI_PACKAGE void __fastcall dxFreeGlobalObject(void *AObject);
extern DELPHI_PACKAGE TdxUnitsLoader* __fastcall dxUnitsLoader(void);
extern DELPHI_PACKAGE void __stdcall dxInitialize(void);
extern DELPHI_PACKAGE void __stdcall dxFinalize(void);
}	/* namespace Dxcore */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXCORE)
using namespace Dxcore;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxcoreHPP
