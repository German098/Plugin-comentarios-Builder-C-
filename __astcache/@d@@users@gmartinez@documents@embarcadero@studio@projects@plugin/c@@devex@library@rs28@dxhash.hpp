// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxHash.pas' rev: 35.00 (Windows)

#ifndef DxhashHPP
#define DxhashHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Hash.hpp>
#include <Winapi.Windows.hpp>
#include <dxCrypto.hpp>
#include <dxCryptoAPI.hpp>
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <System.Generics.Defaults.hpp>
#include <System.Generics.Collections.hpp>

//-- user supplied -----------------------------------------------------------

namespace Dxhash
{
//-- forward type declarations -----------------------------------------------
struct TdxMD5Context;
class DELPHICLASS TdxHashAlgorithm;
class DELPHICLASS TdxCustomCryptoHashAlgorithm;
class DELPHICLASS TdxCryptoHashAlgorithm;
class DELPHICLASS TdxHMACHashAlgorithm;
class DELPHICLASS TdxMD2HashAlgorithm;
class DELPHICLASS TdxMD4HashAlgorithm;
class DELPHICLASS TdxMD5HashAlgorithm;
class DELPHICLASS TdxSHA1HashAlgorithm;
class DELPHICLASS TdxSHA2HashAlgorithm;
class DELPHICLASS TdxSHA2HashAlgorithm32Bit;
class DELPHICLASS TdxSHA256HashAlgorithm;
class DELPHICLASS TdxSHA2HashAlgorithm64Bit;
class DELPHICLASS TdxSHA384HashAlgorithm;
class DELPHICLASS TdxSHA512HashAlgorithm;
class DELPHICLASS TdxStringHash;
//-- type declarations -------------------------------------------------------
typedef System::StaticArray<System::Byte, 16> TdxMD4Byte16;

typedef TdxMD4Byte16 TdxMD5Byte16;

typedef System::StaticArray<System::Byte, 64> TdxMD5Byte64;

typedef TdxMD5Byte64 *PdxMD5Byte64;

typedef System::StaticArray<unsigned, 2> TdxMD5Int2;

typedef System::StaticArray<unsigned, 4> TdxMD5Int4;

typedef System::StaticArray<unsigned, 16> TdxMD5Int16;

typedef TdxMD5Int16 *PdxMD5Int16;

struct DECLSPEC_DRECORD TdxMD5Context
{
public:
	TdxMD5Int4 State;
	TdxMD5Int2 Count;
	TdxMD5Byte64 Buffer;
	unsigned BufferLen;
};


typedef System::TMetaClass* TdxHashAlgorithmClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxHashAlgorithm : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	virtual int __fastcall GetHashSize() = 0 ;
	
public:
	__fastcall virtual TdxHashAlgorithm();
	void __fastcall Add(const System::DynamicArray<System::Byte> A)/* overload */;
	void __fastcall Add(const System::DynamicArray<System::Byte> A, int AIndex, int ALength)/* overload */;
	virtual void __fastcall Add(const void * P, int ASize) = 0 /* overload */;
	void __fastcall Add(const System::UnicodeString S, System::Sysutils::TEncoding* AEncoding = (System::Sysutils::TEncoding*)(0x0))/* overload */;
	virtual System::DynamicArray<System::Byte> __fastcall GetHash() = 0 ;
	virtual void __fastcall Reset() = 0 ;
	__classmethod System::DynamicArray<System::Byte> __fastcall Calculate(const System::DynamicArray<System::Byte> A)/* overload */;
	__classmethod System::DynamicArray<System::Byte> __fastcall Calculate(const System::DynamicArray<System::Byte> A, int AIndex, int ALength)/* overload */;
	__classmethod System::DynamicArray<System::Byte> __fastcall Calculate(const void * P, int ASize)/* overload */;
	__classmethod System::DynamicArray<System::Byte> __fastcall Calculate(System::Classes::TStream* const S)/* overload */;
	__classmethod System::DynamicArray<System::Byte> __fastcall Calculate(const System::UnicodeString S)/* overload */;
	static unsigned __fastcall ToBigEndian(unsigned AValue)/* overload */;
	static unsigned __int64 __fastcall ToBigEndian(unsigned __int64 AValue)/* overload */;
	static System::UnicodeString __fastcall ToString(const System::DynamicArray<System::Byte> AHash);
	__property int HashSize = {read=GetHashSize, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxHashAlgorithm() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomCryptoHashAlgorithm : public TdxHashAlgorithm
{
	typedef TdxHashAlgorithm inherited;
	
protected:
	NativeUInt FHandle;
	Dxcrypto::_di_IdxCryptoProvider FProvider;
	virtual void __fastcall Initialize(int AHashAlgorithm, Dxcrypto::_di_IdxCryptoProvider AProvider = Dxcrypto::_di_IdxCryptoProvider());
	virtual int __fastcall GetHashSize();
	
public:
	__fastcall virtual TdxCustomCryptoHashAlgorithm();
	__fastcall virtual ~TdxCustomCryptoHashAlgorithm();
	virtual void __fastcall Add(const void * P, int ASize)/* overload */;
	virtual System::DynamicArray<System::Byte> __fastcall GetHash();
	virtual void __fastcall Reset();
	__property NativeUInt Handle = {read=FHandle, nodefault};
	__property Dxcrypto::_di_IdxCryptoProvider Provider = {read=FProvider};
	/* Hoisted overloads: */
	
public:
	inline void __fastcall  Add(const System::DynamicArray<System::Byte> A){ TdxHashAlgorithm::Add(A); }
	inline void __fastcall  Add(const System::DynamicArray<System::Byte> A, int AIndex, int ALength){ TdxHashAlgorithm::Add(A, AIndex, ALength); }
	inline void __fastcall  Add(const System::UnicodeString S, System::Sysutils::TEncoding* AEncoding = (System::Sysutils::TEncoding*)(0x0)){ TdxHashAlgorithm::Add(S, AEncoding); }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCryptoHashAlgorithm : public TdxCustomCryptoHashAlgorithm
{
	typedef TdxCustomCryptoHashAlgorithm inherited;
	
public:
	__fastcall TdxCryptoHashAlgorithm(int AHashAlgorithm, Dxcrypto::_di_IdxCryptoProvider AProvider);
public:
	/* TdxCustomCryptoHashAlgorithm.Destroy */ inline __fastcall virtual ~TdxCryptoHashAlgorithm() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxHMACHashAlgorithm : public TdxCustomCryptoHashAlgorithm
{
	typedef TdxCustomCryptoHashAlgorithm inherited;
	
private:
	int FHashAlgorithm;
	NativeUInt FKeyHandle;
	void __fastcall CreateHashHandle();
	
public:
	__fastcall TdxHMACHashAlgorithm(System::DynamicArray<System::Byte> AKey, int AHashAlgorithm, Dxcrypto::_di_IdxCryptoProvider AProvider);
	__fastcall virtual ~TdxHMACHashAlgorithm();
	virtual void __fastcall Reset();
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxMD2HashAlgorithm : public TdxCustomCryptoHashAlgorithm
{
	typedef TdxCustomCryptoHashAlgorithm inherited;
	
public:
	__fastcall virtual TdxMD2HashAlgorithm();
public:
	/* TdxCustomCryptoHashAlgorithm.Destroy */ inline __fastcall virtual ~TdxMD2HashAlgorithm() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxMD4HashAlgorithm : public TdxCustomCryptoHashAlgorithm
{
	typedef TdxCustomCryptoHashAlgorithm inherited;
	
public:
	__fastcall virtual TdxMD4HashAlgorithm();
public:
	/* TdxCustomCryptoHashAlgorithm.Destroy */ inline __fastcall virtual ~TdxMD4HashAlgorithm() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxMD5HashAlgorithm : public TdxCustomCryptoHashAlgorithm
{
	typedef TdxCustomCryptoHashAlgorithm inherited;
	
public:
	__fastcall virtual TdxMD5HashAlgorithm();
public:
	/* TdxCustomCryptoHashAlgorithm.Destroy */ inline __fastcall virtual ~TdxMD5HashAlgorithm() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSHA1HashAlgorithm : public TdxCustomCryptoHashAlgorithm
{
	typedef TdxCustomCryptoHashAlgorithm inherited;
	
public:
	__fastcall virtual TdxSHA1HashAlgorithm();
public:
	/* TdxCustomCryptoHashAlgorithm.Destroy */ inline __fastcall virtual ~TdxSHA1HashAlgorithm() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TdxSHA2HashAlgorithm : public TdxHashAlgorithm
{
	typedef TdxHashAlgorithm inherited;
	
protected:
	System::StaticArray<System::Byte, 128> FBuffer;
	int FBufferIndex;
	unsigned __int64 FBitLength;
	bool FFinalized;
	void __fastcall ClearVariables();
	virtual int __fastcall GetBlockSize() = 0 ;
	virtual System::DynamicArray<System::Byte> __fastcall GetHashBytes() = 0 ;
	virtual void __fastcall Initialize() = 0 ;
	virtual void __fastcall Finalize() = 0 ;
	virtual void __fastcall ProcessBlock() = 0 ;
	
public:
	__fastcall virtual TdxSHA2HashAlgorithm();
	virtual void __fastcall Add(const void * AData, int ASize)/* overload */;
	virtual System::DynamicArray<System::Byte> __fastcall GetHash();
	virtual void __fastcall Reset();
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSHA2HashAlgorithm() { }
	
	/* Hoisted overloads: */
	
public:
	inline void __fastcall  Add(const System::DynamicArray<System::Byte> A){ TdxHashAlgorithm::Add(A); }
	inline void __fastcall  Add(const System::DynamicArray<System::Byte> A, int AIndex, int ALength){ TdxHashAlgorithm::Add(A, AIndex, ALength); }
	inline void __fastcall  Add(const System::UnicodeString S, System::Sysutils::TEncoding* AEncoding = (System::Sysutils::TEncoding*)(0x0)){ TdxHashAlgorithm::Add(S, AEncoding); }
	
};


class PASCALIMPLEMENTATION TdxSHA2HashAlgorithm32Bit : public TdxSHA2HashAlgorithm
{
	typedef TdxSHA2HashAlgorithm inherited;
	
protected:
	static const System::Int8 BlockSize = System::Int8(0x40);
	
	System::StaticArray<unsigned, 8> FHash;
	virtual int __fastcall GetBlockSize();
	virtual System::DynamicArray<System::Byte> __fastcall GetHashBytes();
	virtual void __fastcall Finalize();
	virtual void __fastcall ProcessBlock();
public:
	/* TdxSHA2HashAlgorithm.Create */ inline __fastcall virtual TdxSHA2HashAlgorithm32Bit() : TdxSHA2HashAlgorithm() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSHA2HashAlgorithm32Bit() { }
	
};


class PASCALIMPLEMENTATION TdxSHA256HashAlgorithm : public TdxSHA2HashAlgorithm32Bit
{
	typedef TdxSHA2HashAlgorithm32Bit inherited;
	
protected:
	virtual int __fastcall GetHashSize();
	virtual void __fastcall Initialize();
public:
	/* TdxSHA2HashAlgorithm.Create */ inline __fastcall virtual TdxSHA256HashAlgorithm() : TdxSHA2HashAlgorithm32Bit() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSHA256HashAlgorithm() { }
	
};


class PASCALIMPLEMENTATION TdxSHA2HashAlgorithm64Bit : public TdxSHA2HashAlgorithm
{
	typedef TdxSHA2HashAlgorithm inherited;
	
protected:
	static const System::Byte BlockSize = System::Byte(0x80);
	
	System::StaticArray<unsigned __int64, 8> FHash;
	virtual int __fastcall GetBlockSize();
	virtual System::DynamicArray<System::Byte> __fastcall GetHashBytes();
	virtual void __fastcall Finalize();
	virtual void __fastcall ProcessBlock();
public:
	/* TdxSHA2HashAlgorithm.Create */ inline __fastcall virtual TdxSHA2HashAlgorithm64Bit() : TdxSHA2HashAlgorithm() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSHA2HashAlgorithm64Bit() { }
	
};


class PASCALIMPLEMENTATION TdxSHA384HashAlgorithm : public TdxSHA2HashAlgorithm64Bit
{
	typedef TdxSHA2HashAlgorithm64Bit inherited;
	
protected:
	virtual int __fastcall GetHashSize();
	virtual void __fastcall Initialize();
public:
	/* TdxSHA2HashAlgorithm.Create */ inline __fastcall virtual TdxSHA384HashAlgorithm() : TdxSHA2HashAlgorithm64Bit() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSHA384HashAlgorithm() { }
	
};


class PASCALIMPLEMENTATION TdxSHA512HashAlgorithm : public TdxSHA2HashAlgorithm64Bit
{
	typedef TdxSHA2HashAlgorithm64Bit inherited;
	
protected:
	virtual int __fastcall GetHashSize();
	virtual void __fastcall Initialize();
public:
	/* TdxSHA2HashAlgorithm.Create */ inline __fastcall virtual TdxSHA512HashAlgorithm() : TdxSHA2HashAlgorithm64Bit() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSHA512HashAlgorithm() { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxStringHash : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	static unsigned __fastcall BobJenkins(const System::UnicodeString S);
	static unsigned __fastcall DotNet(const System::UnicodeString S);
	static unsigned __fastcall Elf(const System::UnicodeString S);
	static unsigned __fastcall Murmur2(const System::UnicodeString S);
	static unsigned __fastcall Murmur2A(const System::UnicodeString S);
public:
	/* TObject.Create */ inline __fastcall TdxStringHash() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxStringHash() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE void __fastcall dxMD5Init(TdxMD5Context &AContext);
extern DELPHI_PACKAGE void __fastcall dxMD5Update(TdxMD5Context &AContext, const System::AnsiString S)/* overload */;
extern DELPHI_PACKAGE void __fastcall dxMD5Update(TdxMD5Context &AContext, System::Sysutils::PByteArray AInput, int AInputLength)/* overload */;
extern DELPHI_PACKAGE void __fastcall dxMD5Final(TdxMD5Context &AContext, TdxMD4Byte16 &ADigits);
extern DELPHI_PACKAGE void __fastcall dxMD5Calc(System::Sysutils::PByteArray AInput, int AInputLength, TdxMD4Byte16 &ADigits);
extern DELPHI_PACKAGE System::UnicodeString __fastcall dxMD5CalcStr(const System::UnicodeString S);
extern DELPHI_PACKAGE bool __fastcall dxMD5Compare(const TdxMD4Byte16 &ADigits1, const TdxMD4Byte16 &ADigits2);
extern DELPHI_PACKAGE System::UnicodeString __fastcall dxMD5DigestToString(const TdxMD4Byte16 &ADigits);
extern DELPHI_PACKAGE void __fastcall dxMD4Calc(System::Sysutils::PByteArray AInput, int AInputLength, TdxMD4Byte16 &ADigits);
extern DELPHI_PACKAGE unsigned __fastcall dxCRC32(System::PByte AData, int ACount)/* overload */;
extern DELPHI_PACKAGE unsigned __fastcall dxCRC32(System::PByte AData, int ACount, unsigned ACurrentCRC32)/* overload */;
extern DELPHI_PACKAGE unsigned __fastcall dxCRC32(System::Classes::TStream* AStream, const __int64 APosition, __int64 ACount)/* overload */;
extern DELPHI_PACKAGE int __fastcall dxBobJenkinsHash(const void *Data, int Len, int InitData);
extern DELPHI_PACKAGE int __fastcall dxDotNetHash(System::PByte Data, unsigned Len);
extern DELPHI_PACKAGE int __fastcall dxElfHash(const System::AnsiString S, unsigned ALangID = (unsigned)(0x0))/* overload */;
extern DELPHI_PACKAGE int __fastcall dxElfHash(const System::UnicodeString S, unsigned ALangID = (unsigned)(0x0))/* overload */;
extern DELPHI_PACKAGE int __fastcall dxElfHash(System::WideChar * P, int ALength, unsigned ALangID = (unsigned)(0x0))/* overload */;
extern DELPHI_PACKAGE int __fastcall dxElfHash(System::WideChar * P, int ALength, System::WideChar * AUpperCaseBuffer, int AUpperCaseBufferLength, unsigned ALangID = (unsigned)(0x0))/* overload */;
extern DELPHI_PACKAGE unsigned __fastcall dxMurmur2(const System::UnicodeString S, const unsigned ASeed = (unsigned)(0x0));
extern DELPHI_PACKAGE unsigned __fastcall dxMurmur2A(const System::UnicodeString S, const unsigned ASeed = (unsigned)(0x0));
extern DELPHI_PACKAGE unsigned __fastcall dxAdler32(unsigned AInitialValue, void * ABuffer, int ASize);
}	/* namespace Dxhash */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXHASH)
using namespace Dxhash;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxhashHPP
