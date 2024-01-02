// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxVariants.pas' rev: 35.00 (Windows)

#ifndef CxvariantsHPP
#define CxvariantsHPP

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
#include <dxCore.hpp>
#include <dxGenerics.hpp>
#include <System.Variants.hpp>
#include <System.Generics.Defaults.hpp>
#include <System.Generics.Collections.hpp>

//-- user supplied -----------------------------------------------------------

namespace Cxvariants
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TcxFiler;
class DELPHICLASS TcxReader;
class DELPHICLASS TcxWriter;
class DELPHICLASS TdxVariantList;
class DELPHICLASS TdxVariantSet;
class DELPHICLASS TdxVariantListComparer;
class DELPHICLASS TdxVariantComparer;
template<typename T> class DELPHICLASS TdxVariantDictionary__1;
template<typename TValue> class DELPHICLASS TdxVariantToObjectDictionary__1;
//-- type declarations -------------------------------------------------------
typedef __int64 LargeInt;

typedef System::DynamicArray<System::Variant> TVariantArray;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFiler : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FIsUnicode;
	System::Classes::TStream* FStream;
	unsigned FVersion;
	
public:
	__fastcall TcxFiler(System::Classes::TStream* AStream)/* overload */;
	__fastcall TcxFiler(System::Classes::TStream* AStream, unsigned AVersion)/* overload */;
	__property bool IsUnicode = {read=FIsUnicode, nodefault};
	__property System::Classes::TStream* Stream = {read=FStream};
	__property unsigned Version = {read=FVersion, write=FVersion, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxFiler() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxReader : public TcxFiler
{
	typedef TcxFiler inherited;
	
public:
	void __fastcall BeginChunk(/* out */ __int64 &APosition);
	void __fastcall EndChunk(const __int64 APosition);
	System::AnsiString __fastcall ReadAnsiString();
	bool __fastcall ReadBoolean();
	System::Byte __fastcall ReadByte();
	unsigned __fastcall ReadCardinal();
	System::WideChar __fastcall ReadChar();
	System::Currency __fastcall ReadCurrency();
	System::TDateTime __fastcall ReadDateTime();
	System::Extended __fastcall ReadFloat();
	__int64 __fastcall ReadInt64();
	int __fastcall ReadInteger();
	__int64 __fastcall ReadLargeInt();
	void __fastcall ReadMemoryStream(System::Classes::TMemoryStream* AStream);
	System::Types::TPoint __fastcall ReadPoint();
	System::Types::TRect __fastcall ReadRect();
	System::Int8 __fastcall ReadShortInt();
	float __fastcall ReadSingle();
	short __fastcall ReadSmallInt();
	System::UnicodeString __fastcall ReadString();
	System::UnicodeString __fastcall ReadString_();
	System::Variant __fastcall ReadVariant();
	System::WideString __fastcall ReadWideString();
	System::Word __fastcall ReadWord();
	void __fastcall Skip(unsigned ACount);
public:
	/* TcxFiler.Create */ inline __fastcall TcxReader(System::Classes::TStream* AStream)/* overload */ : TcxFiler(AStream) { }
	/* TcxFiler.Create */ inline __fastcall TcxReader(System::Classes::TStream* AStream, unsigned AVersion)/* overload */ : TcxFiler(AStream, AVersion) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxReader() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxWriter : public TcxFiler
{
	typedef TcxFiler inherited;
	
public:
	void __fastcall BeginChunk(/* out */ __int64 &APosition);
	void __fastcall EndChunk(const __int64 APosition);
	void __fastcall WriteAnsiString(const System::AnsiString S);
	void __fastcall WriteBoolean(bool AValue);
	void __fastcall WriteByte(System::Byte AValue);
	void __fastcall WriteCardinal(unsigned AValue);
	void __fastcall WriteChar(System::WideChar AValue);
	void __fastcall WriteCurrency(System::Currency AValue);
	void __fastcall WriteDateTime(System::TDateTime AValue);
	void __fastcall WriteFloat(System::Extended AValue);
	void __fastcall WriteInt64(__int64 AValue);
	void __fastcall WriteInteger(int AValue);
	void __fastcall WriteLargeInt(__int64 AValue);
	void __fastcall WriteMemoryStream(System::Classes::TMemoryStream* AStream);
	void __fastcall WritePoint(const System::Types::TPoint &AValue);
	void __fastcall WriteRaw(System::Classes::TMemoryStream* AStream)/* overload */;
	void __fastcall WriteRaw(const void *AData, NativeInt ASize)/* overload */;
	void __fastcall WriteRect(const System::Types::TRect &AValue);
	void __fastcall WriteShortInt(System::Int8 AValue);
	void __fastcall WriteSingle(float AValue);
	void __fastcall WriteString(const System::UnicodeString AValue);
	void __fastcall WriteSmallInt(short AValue);
	void __fastcall WriteVariant(const System::Variant &AValue);
	void __fastcall WriteWideString(const System::WideString S);
	void __fastcall WriteWord(System::Word AValue);
public:
	/* TcxFiler.Create */ inline __fastcall TcxWriter(System::Classes::TStream* AStream)/* overload */ : TcxFiler(AStream) { }
	/* TcxFiler.Create */ inline __fastcall TcxWriter(System::Classes::TStream* AStream, unsigned AVersion)/* overload */ : TcxFiler(AStream, AVersion) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxWriter() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TdxVariantList : public System::Generics::Collections::TList__1<System::Variant>
{
	typedef System::Generics::Collections::TList__1<System::Variant> inherited;
	
public:
	__fastcall TdxVariantList();
public:
	/* {System_Generics_Collections}TList<System_Variant>.Destroy */ inline __fastcall virtual ~TdxVariantList() { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxVariantSet : public Dxgenerics::TdxHashSet__1<System::Variant>
{
	typedef Dxgenerics::TdxHashSet__1<System::Variant> inherited;
	
public:
	__fastcall TdxVariantSet(int ACapacity);
public:
	/* {dxGenerics}TdxHashSet<System_Variant>.Destroy */ inline __fastcall virtual ~TdxVariantSet() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxVariantListComparer : public System::TInterfacedObject
{
	typedef System::TInterfacedObject inherited;
	
public:
	int __fastcall Compare(const System::Variant &Left, const System::Variant &Right);
public:
	/* TObject.Create */ inline __fastcall TdxVariantListComparer() : System::TInterfacedObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxVariantListComparer() { }
	
private:
	void *__IComparer__1;	// System::Generics::Defaults::IComparer__1<System::Variant> 
	
public:
	operator System::Generics::Defaults::IComparer__1<System::Variant>*(void) { return (System::Generics::Defaults::IComparer__1<System::Variant>*)&__IComparer__1; }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxVariantComparer : public System::Generics::Defaults::TEqualityComparer__1<System::Variant>
{
	typedef System::Generics::Defaults::TEqualityComparer__1<System::Variant> inherited;
	
public:
	virtual bool __fastcall Equals(const System::Variant &Left, const System::Variant &Right)/* overload */;
	virtual int __fastcall GetHashCode(const System::Variant &Value)/* overload */;
public:
	/* TObject.Create */ inline __fastcall TdxVariantComparer() : System::Generics::Defaults::TEqualityComparer__1<System::Variant>() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxVariantComparer() { }
	
};

#pragma pack(pop)

// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename T> class PASCALIMPLEMENTATION TdxVariantDictionary__1 : public System::Generics::Collections::TDictionary__2<System::Variant,T>
{
	typedef System::Generics::Collections::TDictionary__2<System::Variant,T> inherited;
	
public:
	__fastcall TdxVariantDictionary__1(int ACapacity);
public:
	/* {System_Generics_Collections}TDictionary<System_Variant,cxVariants_TdxVariantDictionary<T>_T>.Destroy */ inline __fastcall virtual ~TdxVariantDictionary__1() { }
	
};


// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename TValue> class PASCALIMPLEMENTATION TdxVariantToObjectDictionary__1 : public System::Generics::Collections::TObjectDictionary__2<System::Variant,TValue>
{
	typedef System::Generics::Collections::TObjectDictionary__2<System::Variant,TValue> inherited;
	
public:
	__fastcall TdxVariantToObjectDictionary__1(bool AOwnsValues, int ACapacity);
public:
	/* {System_Generics_Collections}TDictionary<System_Variant,cxVariants_TdxVariantToObjectDictionary<TValue>_TValue>.Destroy */ inline __fastcall virtual ~TdxVariantToObjectDictionary__1() { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE int __fastcall VarCompare(const System::Variant &V1, const System::Variant &V2);
extern DELPHI_PACKAGE bool __fastcall VarEquals(const System::Variant &V1, const System::Variant &V2);
extern DELPHI_PACKAGE bool __fastcall VarEqualsExact(const System::Variant &V1, const System::Variant &V2);
extern DELPHI_PACKAGE bool __fastcall VarEqualsSoft(const System::Variant &V1, const System::Variant &V2);
extern DELPHI_PACKAGE int __fastcall VarIndex(const TVariantArray AList, const System::Variant &AValue);
extern DELPHI_PACKAGE bool __fastcall VarIsDate(const System::Variant &AValue);
extern DELPHI_PACKAGE bool __fastcall VarIsNumericEx(const System::Variant &AValue);
extern DELPHI_PACKAGE bool __fastcall VarIsSoftNull(const System::Variant &AValue);
extern DELPHI_PACKAGE bool __fastcall VarIsSoftEmpty(const System::Variant &AValue);
extern DELPHI_PACKAGE System::UnicodeString __fastcall VarToStrEx(const System::Variant &V);
extern DELPHI_PACKAGE bool __fastcall VarTypeIsCurrency(System::Word AVarType);
extern DELPHI_PACKAGE System::Variant __fastcall VarBetweenArrayCreate(const System::Variant &AValue1, const System::Variant &AValue2);
extern DELPHI_PACKAGE System::Variant __fastcall VarListArrayCreate(const System::Variant &AValue);
extern DELPHI_PACKAGE void __fastcall VarListArrayAddValue(System::Variant &Value, const System::Variant &AValue);
extern DELPHI_PACKAGE System::AnsiString __fastcall ReadAnsiStringFunc(System::Classes::TStream* AStream);
extern DELPHI_PACKAGE void __fastcall ReadAnsiStringProc(System::Classes::TStream* AStream, System::AnsiString &S);
extern DELPHI_PACKAGE void __fastcall WriteAnsiStringProc(System::Classes::TStream* AStream, const System::AnsiString S);
extern DELPHI_PACKAGE System::WideString __fastcall ReadWideStringFunc(System::Classes::TStream* AStream);
extern DELPHI_PACKAGE void __fastcall ReadWideStringProc(System::Classes::TStream* AStream, System::WideString &S);
extern DELPHI_PACKAGE void __fastcall WriteWideStringProc(System::Classes::TStream* AStream, const System::WideString S);
extern DELPHI_PACKAGE System::Variant __fastcall ReadVariantFunc(System::Classes::TStream* AStream);
extern DELPHI_PACKAGE void __fastcall ReadVariantProc(System::Classes::TStream* AStream, System::Variant &Value);
extern DELPHI_PACKAGE void __fastcall WriteVariantProc(System::Classes::TStream* AStream, const System::Variant &AValue);
extern DELPHI_PACKAGE bool __fastcall ReadBooleanFunc(System::Classes::TStream* AStream);
extern DELPHI_PACKAGE void __fastcall ReadBooleanProc(System::Classes::TStream* AStream, bool &Value);
extern DELPHI_PACKAGE void __fastcall WriteBooleanProc(System::Classes::TStream* AStream, bool AValue);
extern DELPHI_PACKAGE System::WideChar __fastcall ReadCharFunc(System::Classes::TStream* AStream);
extern DELPHI_PACKAGE void __fastcall ReadCharProc(System::Classes::TStream* AStream, System::WideChar &Value);
extern DELPHI_PACKAGE void __fastcall WriteCharProc(System::Classes::TStream* AStream, System::WideChar AValue);
extern DELPHI_PACKAGE System::Extended __fastcall ReadFloatFunc(System::Classes::TStream* AStream);
extern DELPHI_PACKAGE void __fastcall ReadFloatProc(System::Classes::TStream* AStream, System::Extended &Value);
extern DELPHI_PACKAGE void __fastcall WriteFloatProc(System::Classes::TStream* AStream, System::Extended AValue);
extern DELPHI_PACKAGE float __fastcall ReadSingleFunc(System::Classes::TStream* AStream);
extern DELPHI_PACKAGE void __fastcall ReadSingleProc(System::Classes::TStream* AStream, float &Value);
extern DELPHI_PACKAGE void __fastcall WriteSingleProc(System::Classes::TStream* AStream, float AValue);
extern DELPHI_PACKAGE double __fastcall ReadDoubleFunc(System::Classes::TStream* AStream);
extern DELPHI_PACKAGE void __fastcall ReadDoubleProc(System::Classes::TStream* AStream, double &Value);
extern DELPHI_PACKAGE void __fastcall WriteDoubleProc(System::Classes::TStream* AStream, const double AValue);
extern DELPHI_PACKAGE System::Currency __fastcall ReadCurrencyFunc(System::Classes::TStream* AStream);
extern DELPHI_PACKAGE void __fastcall ReadCurrencyProc(System::Classes::TStream* AStream, System::Currency &Value);
extern DELPHI_PACKAGE void __fastcall WriteCurrencyProc(System::Classes::TStream* AStream, System::Currency AValue);
extern DELPHI_PACKAGE System::TDateTime __fastcall ReadDateTimeFunc(System::Classes::TStream* AStream);
extern DELPHI_PACKAGE void __fastcall ReadDateTimeProc(System::Classes::TStream* AStream, System::TDateTime &Value);
extern DELPHI_PACKAGE void __fastcall WriteDateTimeProc(System::Classes::TStream* AStream, System::TDateTime AValue);
extern DELPHI_PACKAGE int __fastcall ReadIntegerFunc(System::Classes::TStream* AStream);
extern DELPHI_PACKAGE void __fastcall ReadInt64Proc(System::Classes::TStream* AStream, __int64 &Value);
extern DELPHI_PACKAGE void __fastcall ReadIntegerProc(System::Classes::TStream* AStream, int &Value);
extern DELPHI_PACKAGE void __fastcall WriteInt64Proc(System::Classes::TStream* AStream, __int64 AValue);
extern DELPHI_PACKAGE void __fastcall WriteIntegerProc(System::Classes::TStream* AStream, int AValue);
extern DELPHI_PACKAGE __int64 __fastcall ReadLargeIntFunc(System::Classes::TStream* AStream);
extern DELPHI_PACKAGE void __fastcall ReadLargeIntProc(System::Classes::TStream* AStream, __int64 &Value);
extern DELPHI_PACKAGE void __fastcall WriteLargeIntProc(System::Classes::TStream* AStream, __int64 AValue);
extern DELPHI_PACKAGE System::Byte __fastcall ReadByteFunc(System::Classes::TStream* AStream);
extern DELPHI_PACKAGE void __fastcall ReadByteProc(System::Classes::TStream* AStream, System::Byte &Value);
extern DELPHI_PACKAGE void __fastcall WriteByteProc(System::Classes::TStream* AStream, System::Byte AValue);
extern DELPHI_PACKAGE short __fastcall ReadSmallIntFunc(System::Classes::TStream* AStream);
extern DELPHI_PACKAGE void __fastcall ReadSmallIntProc(System::Classes::TStream* AStream, short &Value);
extern DELPHI_PACKAGE void __fastcall WriteSmallIntProc(System::Classes::TStream* AStream, short AValue);
extern DELPHI_PACKAGE unsigned __fastcall ReadCardinalFunc(System::Classes::TStream* AStream);
extern DELPHI_PACKAGE void __fastcall ReadCardinalProc(System::Classes::TStream* AStream, unsigned &Value);
extern DELPHI_PACKAGE void __fastcall WriteCardinalProc(System::Classes::TStream* AStream, unsigned AValue);
extern DELPHI_PACKAGE System::Int8 __fastcall ReadShortIntFunc(System::Classes::TStream* AStream);
extern DELPHI_PACKAGE void __fastcall ReadShortIntProc(System::Classes::TStream* AStream, System::Int8 &Value);
extern DELPHI_PACKAGE void __fastcall WriteShortIntProc(System::Classes::TStream* AStream, System::Int8 AValue);
extern DELPHI_PACKAGE System::Word __fastcall ReadWordFunc(System::Classes::TStream* AStream);
extern DELPHI_PACKAGE void __fastcall ReadWordProc(System::Classes::TStream* AStream, System::Word &Value);
extern DELPHI_PACKAGE void __fastcall WriteWordProc(System::Classes::TStream* AStream, System::Word AValue);
extern DELPHI_PACKAGE System::DynamicArray<System::Byte> __fastcall ReadBytesFunc(System::Classes::TStream* AStream, int ACount);
extern DELPHI_PACKAGE void __fastcall WriteBytesProc(System::Classes::TStream* AStream, System::DynamicArray<System::Byte> ABytes);
extern DELPHI_PACKAGE unsigned __fastcall GetVariantHash(const System::Variant &V);
}	/* namespace Cxvariants */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXVARIANTS)
using namespace Cxvariants;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxvariantsHPP
