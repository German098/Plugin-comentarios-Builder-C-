// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxCrypto.pas' rev: 35.00 (Windows)

#ifndef DxcryptoHPP
#define DxcryptoHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.Windows.hpp>
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <System.Generics.Defaults.hpp>
#include <System.Generics.Collections.hpp>
#include <dxCryptoAPI.hpp>

//-- user supplied -----------------------------------------------------------

namespace Dxcrypto
{
//-- forward type declarations -----------------------------------------------
struct TdxRC4Key;
__interface DELPHIINTERFACE IdxCryptoProvider;
typedef System::DelphiInterface<IdxCryptoProvider> _di_IdxCryptoProvider;
__interface DELPHIINTERFACE IdxCryptoKey;
typedef System::DelphiInterface<IdxCryptoKey> _di_IdxCryptoKey;
class DELPHICLASS TdxCryptoProvider;
class DELPHICLASS TdxCryptoKey;
class DELPHICLASS TdxCipher;
class DELPHICLASS TdxCryptoAlgorithms;
class DELPHICLASS TdxPBKDF2;
//-- type declarations -------------------------------------------------------
struct DECLSPEC_DRECORD TdxRC4Key
{
public:
	System::StaticArray<System::Byte, 256> State;
	int X;
	int Y;
};


__interface  INTERFACE_UUID("{BC0E1F98-91B7-4A1B-8941-3B8828153CFA}") IdxCryptoProvider  : public System::IInterface 
{
	virtual NativeUInt __fastcall GetHandle() = 0 ;
	__property NativeUInt Handle = {read=GetHandle};
};

__interface  INTERFACE_UUID("{0A731ECE-8CA2-429B-92AF-E61D49CB8AFA}") IdxCryptoKey  : public System::IInterface 
{
	virtual int __fastcall GetBlockSize() = 0 ;
	virtual int __fastcall GetChainingMode() = 0 ;
	virtual NativeUInt __fastcall GetHandle() = 0 ;
	virtual void __fastcall SetChainingMode(int AValue) = 0 ;
	virtual System::DynamicArray<System::Byte> __fastcall GetIV() = 0 ;
	virtual _di_IdxCryptoProvider __fastcall GetProvider() = 0 ;
	virtual void __fastcall SetIV(System::DynamicArray<System::Byte> AValue) = 0 ;
	__property int BlockSize = {read=GetBlockSize};
	__property int ChainingMode = {read=GetChainingMode, write=SetChainingMode};
	__property NativeUInt Handle = {read=GetHandle};
};

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCryptoProvider : public System::TInterfacedObject
{
	typedef System::TInterfacedObject inherited;
	
private:
	NativeUInt FHandle;
	
public:
	__fastcall TdxCryptoProvider(const System::WideChar * ACSPName, int AProviderType);
	__fastcall virtual ~TdxCryptoProvider();
	NativeUInt __fastcall GetHandle();
private:
	void *__IdxCryptoProvider;	// IdxCryptoProvider 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {BC0E1F98-91B7-4A1B-8941-3B8828153CFA}
	operator _di_IdxCryptoProvider()
	{
		_di_IdxCryptoProvider intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IdxCryptoProvider*(void) { return (IdxCryptoProvider*)&__IdxCryptoProvider; }
	#endif
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCryptoKey : public System::TInterfacedObject
{
	typedef System::TInterfacedObject inherited;
	
private:
	NativeUInt FHandle;
	_di_IdxCryptoProvider FProvider;
	
public:
	__fastcall TdxCryptoKey(_di_IdxCryptoProvider AProvider, int AAlgorithm, const System::DynamicArray<System::Byte> AKey)/* overload */;
	__fastcall TdxCryptoKey(_di_IdxCryptoProvider AProvider, int AAlgorithm, const NativeUInt APasswordHash)/* overload */;
	__fastcall virtual ~TdxCryptoKey();
	int __fastcall GetBlockSize();
	int __fastcall GetChainingMode();
	NativeUInt __fastcall GetHandle();
	System::DynamicArray<System::Byte> __fastcall GetIV();
	_di_IdxCryptoProvider __fastcall GetProvider();
	void __fastcall SetChainingMode(int AValue);
	void __fastcall SetIV(System::DynamicArray<System::Byte> AValue);
private:
	void *__IdxCryptoKey;	// IdxCryptoKey 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {0A731ECE-8CA2-429B-92AF-E61D49CB8AFA}
	operator _di_IdxCryptoKey()
	{
		_di_IdxCryptoKey intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IdxCryptoKey*(void) { return (IdxCryptoKey*)&__IdxCryptoKey; }
	#endif
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCipher : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	__classmethod void __fastcall Transform(_di_IdxCryptoKey AKey, bool ACrypt, const System::DynamicArray<System::Byte> ASource, /* out */ System::DynamicArray<System::Byte> &ATarget, bool AIsFinalBlock)/* overload */;
	__classmethod void __fastcall Transform(_di_IdxCryptoKey AKey, bool ACrypt, System::Classes::TStream* const ASourceStream, System::Classes::TStream* const ATargetStream, bool AIsFinalBlock)/* overload */;
	
public:
	__classmethod System::DynamicArray<System::Byte> __fastcall Decrypt(_di_IdxCryptoKey AKey, const System::DynamicArray<System::Byte> ASource, bool AIsFinalBlock = true)/* overload */;
	__classmethod void __fastcall Decrypt(_di_IdxCryptoKey AKey, System::Classes::TStream* const ASourceStream, System::Classes::TStream* const ATargetStream, bool AIsFinalBlock = true)/* overload */;
	__classmethod System::DynamicArray<System::Byte> __fastcall Encrypt(_di_IdxCryptoKey AKey, const System::DynamicArray<System::Byte> ASource, bool AIsFinalBlock = true)/* overload */;
	__classmethod void __fastcall Encrypt(_di_IdxCryptoKey AKey, System::Classes::TStream* const ASourceStream, System::Classes::TStream* const ATargetStream, bool AIsFinalBlock = true)/* overload */;
public:
	/* TObject.Create */ inline __fastcall TdxCipher() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxCipher() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCryptoAlgorithms : public System::TObject
{
	typedef System::TObject inherited;
	
	
private:
	#pragma pack(push,8)
	struct DECLSPEC_DRECORD TMapItem
	{
	public:
		System::UnicodeString Name;
		int Provider;
		int Algorithm;
		int KeySize;
	};
	#pragma pack(pop)
	
	
	
private:
	typedef System::StaticArray<TMapItem, 8> _TdxCryptoAlgorithms__1;
	
	
private:
	static _TdxCryptoAlgorithms__1 FMap;
	
public:
	__classmethod bool __fastcall GetInfo(const System::UnicodeString AName, int AKeySize, /* out */ int &AAlgorithmID, /* out */ int &AProviderID);
	
private:
	// __classmethod void __fastcall Create@();
	// __classmethod void __fastcall Destroy@();
public:
	/* TObject.Create */ inline __fastcall TdxCryptoAlgorithms() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxCryptoAlgorithms() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPBKDF2 : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod System::DynamicArray<System::Byte> __fastcall DeriveKey(const System::DynamicArray<System::Byte> APassword, const System::DynamicArray<System::Byte> ASalt, int AIterationCount, int AKeyLength);
public:
	/* TObject.Create */ inline __fastcall TdxPBKDF2() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPBKDF2() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE System::DynamicArray<System::Byte> __fastcall dxGenerateSalt(int ASize);
extern DELPHI_PACKAGE void __fastcall dxRC4Initialize(/* out */ TdxRC4Key &AKey, System::DynamicArray<System::Byte> APassword)/* overload */;
extern DELPHI_PACKAGE void __fastcall dxRC4Initialize(/* out */ TdxRC4Key &AKey, System::Sysutils::PByteArray APassword, int APasswordLength)/* overload */;
extern DELPHI_PACKAGE void __fastcall dxRC4Crypt(TdxRC4Key &AKey, System::Sysutils::PByteArray AInData, System::Sysutils::PByteArray AOutData, int ADataSize);
}	/* namespace Dxcrypto */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXCRYPTO)
using namespace Dxcrypto;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxcryptoHPP
