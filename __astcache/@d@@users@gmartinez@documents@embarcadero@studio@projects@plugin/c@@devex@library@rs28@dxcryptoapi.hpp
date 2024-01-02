// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxCryptoAPI.pas' rev: 35.00 (Windows)

#ifndef DxcryptoapiHPP
#define DxcryptoapiHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.Windows.hpp>

//-- user supplied -----------------------------------------------------------
#pragma link "crypt32.lib"
#pragma link "cryptui.lib"

namespace Dxcryptoapi
{
//-- forward type declarations -----------------------------------------------
struct TdxPublicKeyStructure;
struct TdxHMACInfo;
struct CRYPTOAPI_BLOB;
struct CRYPT_ALGORITHM_IDENTIFIER;
struct CRYPT_BIT_BLOB;
struct CERT_PUBLIC_KEY_INFO;
struct CERT_EXTENSION;
struct CERT_INFO;
struct CERT_CONTEXT;
struct CRYPTUI_VIEWCERTIFICATE_STRUCT;
struct CRYPTUI_SELECTCERTIFICATE_STRUCT;
struct CERT_ALT_NAME_ENTRY;
struct CERT_ALT_NAME_INFO;
struct CERT_RDN_ATTR;
struct CERT_RDN;
struct CERT_NAME_INFO;
struct CTL_USAGE;
struct CRYPT_OID_INFO;
struct CRYPT_KEY_PROV_PARAM;
struct CRYPT_KEY_PROV_INFO;
struct CRYPT_ATTRIBUTE;
struct CRYPT_SIGN_MESSAGE_PARA;
//-- type declarations -------------------------------------------------------
typedef TdxPublicKeyStructure *PdxPublicKeyStructure;

struct DECLSPEC_DRECORD TdxPublicKeyStructure
{
public:
	System::Byte bType;
	System::Byte bVersion;
	System::Word reserved;
	unsigned aiKeyAlg;
};


typedef TdxHMACInfo *PdxHMACInfo;

struct DECLSPEC_DRECORD TdxHMACInfo
{
public:
	unsigned HashAlgid;
	System::Byte *pbInnerString;
	unsigned cbInnerString;
	System::Byte *pbOuterString;
	unsigned cbOuterString;
};


typedef void * PPCCERT_CONTEXT;

typedef void * PPCCRL_CONTEXT;

typedef CRYPTOAPI_BLOB *PCRYPTOAPI_BLOB;

struct DECLSPEC_DRECORD CRYPTOAPI_BLOB
{
public:
	unsigned cbData;
	System::Byte *pbData;
};


typedef CRYPTOAPI_BLOB CRYPT_DATA_BLOB;

typedef CRYPTOAPI_BLOB *PCRYPT_DATA_BLOB;

typedef CRYPTOAPI_BLOB CRYPT_INTEGER_BLOB;

typedef CRYPTOAPI_BLOB *PCRYPT_INTEGER_BLOB;

typedef CRYPTOAPI_BLOB CERT_NAME_BLOB;

typedef CRYPTOAPI_BLOB *PCERT_NAME_BLOB;

typedef CRYPTOAPI_BLOB CRYPT_OBJID_BLOB;

typedef CRYPTOAPI_BLOB *PCRYPT_OBJID_BLOB;

typedef CRYPTOAPI_BLOB CERT_RDN_VALUE_BLOB;

typedef CRYPTOAPI_BLOB *PCERT_RDN_VALUE_BLOB;

typedef CRYPTOAPI_BLOB CRYPT_ATTR_BLOB;

typedef CRYPTOAPI_BLOB *PCRYPT_ATTR_BLOB;

typedef CRYPT_ALGORITHM_IDENTIFIER *PCRYPT_ALGORITHM_IDENTIFIER;

struct DECLSPEC_DRECORD CRYPT_ALGORITHM_IDENTIFIER
{
public:
	char *pszObjId;
	CRYPTOAPI_BLOB Parameters;
};


typedef CRYPT_BIT_BLOB *PCRYPT_BIT_BLOB;

struct DECLSPEC_DRECORD CRYPT_BIT_BLOB
{
public:
	unsigned cbData;
	System::Byte *pbData;
	unsigned cUnusedBits;
};


typedef CERT_PUBLIC_KEY_INFO *PCERT_PUBLIC_KEY_INFO;

struct DECLSPEC_DRECORD CERT_PUBLIC_KEY_INFO
{
public:
	CRYPT_ALGORITHM_IDENTIFIER Algorithm;
	CRYPT_BIT_BLOB PublicKey;
};


typedef CERT_EXTENSION *PCERT_EXTENSION;

struct DECLSPEC_DRECORD CERT_EXTENSION
{
public:
	char *pszObjId;
	System::LongBool fCritical;
	CRYPTOAPI_BLOB Value;
};


typedef CERT_INFO *PCERT_INFO;

struct DECLSPEC_DRECORD CERT_INFO
{
public:
	unsigned dwVersion;
	CRYPTOAPI_BLOB SerialNumber;
	CRYPT_ALGORITHM_IDENTIFIER SignatureAlgorithm;
	CRYPTOAPI_BLOB Issuer;
	_FILETIME NotBefore;
	_FILETIME NotAfter;
	CRYPTOAPI_BLOB Subject;
	CERT_PUBLIC_KEY_INFO SubjectPublicKeyInfo;
	CRYPT_BIT_BLOB IssuerUniqueId;
	CRYPT_BIT_BLOB SubjectUniqueId;
	unsigned cExtension;
	CERT_EXTENSION *rgExtension;
};


typedef CERT_CONTEXT *PCERT_CONTEXT;

struct DECLSPEC_DRECORD CERT_CONTEXT
{
public:
	unsigned dwCertEncodingType;
	System::Byte *pbCertEncoded;
	unsigned cbCertEncoded;
	CERT_INFO *pCertInfo;
	void *hCertStore;
};


typedef CRYPTUI_VIEWCERTIFICATE_STRUCT *PCCRYPTUI_VIEWCERTIFICATE_STRUCT;

struct DECLSPEC_DRECORD CRYPTUI_VIEWCERTIFICATE_STRUCT
{
public:
	unsigned dwSize;
	HWND hwndParent;
	unsigned dwFlags;
	System::WideChar *szTitle;
	CERT_CONTEXT *pCertContext;
	void *rgszPurposes;
	unsigned cPurposes;
	void *hWVTStateData;
	System::LongBool fpCryptProviderDataTrustedUsage;
	unsigned idxSigner;
	unsigned idxCert;
	System::LongBool fCounterSigner;
	unsigned idxCounterSigner;
	unsigned cStores;
	CERT_CONTEXT *rghStores;
	unsigned cPropSheetPages;
	void *rgPropSheetPages;
	unsigned nStartPage;
};


typedef CRYPTUI_SELECTCERTIFICATE_STRUCT *PCCRYPTUI_SELECTCERTIFICATE_STRUCT;

struct DECLSPEC_DRECORD CRYPTUI_SELECTCERTIFICATE_STRUCT
{
public:
	unsigned dwSize;
	unsigned hwndParent;
	unsigned dwFlags;
	void *szTitle;
	unsigned dwDontUseColumn;
	void *szDisplayString;
	unsigned pFilterCallback;
	unsigned pDisplayCallback;
	unsigned pvCallbackData;
	unsigned cDisplayStores;
	void * *rghDisplayStores;
	unsigned cStores;
	unsigned rghStores;
	unsigned cPropSheetPages;
	unsigned rgPropSheetPages;
	void * *hSelectedCertStore;
};


typedef CERT_ALT_NAME_ENTRY *PCERT_ALT_NAME_ENTRY;

struct DECLSPEC_DRECORD CERT_ALT_NAME_ENTRY
{
public:
	unsigned dwAltNameChoice;
	
public:
	union
	{
		struct 
		{
			char *pszRegisteredID;
		};
		struct 
		{
			CRYPTOAPI_BLOB IPAddress;
		};
		struct 
		{
			System::WideChar *pwszURL;
		};
		struct 
		{
			CRYPTOAPI_BLOB DirectoryName;
		};
		struct 
		{
			System::WideChar *pwszDNSName;
		};
		struct 
		{
			System::WideChar *pwszRfc822Name;
		};
		
	};
};


typedef CERT_ALT_NAME_INFO *PCERT_ALT_NAME_INFO;

struct DECLSPEC_DRECORD CERT_ALT_NAME_INFO
{
public:
	unsigned cAltEntry;
	CERT_ALT_NAME_ENTRY *rgAltEntry;
};


typedef CERT_RDN_ATTR *PCERT_RDN_ATTR;

struct DECLSPEC_DRECORD CERT_RDN_ATTR
{
public:
	char *pszObjId;
	unsigned dwValueType;
	CRYPTOAPI_BLOB Value;
};


typedef CERT_RDN *PCERT_RDN;

struct DECLSPEC_DRECORD CERT_RDN
{
public:
	unsigned cRDNAttr;
	CERT_RDN_ATTR *rgRDNAttr;
};


typedef CERT_NAME_INFO *PCERT_NAME_INFO;

struct DECLSPEC_DRECORD CERT_NAME_INFO
{
public:
	unsigned cRDN;
	CERT_RDN *rgRDN;
};


typedef CTL_USAGE *PCTL_USAGE;

struct DECLSPEC_DRECORD CTL_USAGE
{
public:
	unsigned cUsageIdentifier;
	char * *rgpszUsageIdentifier;
};


typedef CTL_USAGE CERT_ENHKEY_USAGE;

typedef CTL_USAGE *PCERT_ENHKEY_USAGE;

typedef CRYPT_OID_INFO *PCRYPT_OID_INFO;

struct DECLSPEC_DRECORD CRYPT_OID_INFO
{
	
private:
	struct DECLSPEC_DRECORD _CRYPT_OID_INFO__1
	{
		
	public:
		union
		{
			struct 
			{
				unsigned dwLength;
			};
			struct 
			{
				unsigned Algid;
			};
			struct 
			{
				unsigned dwValue;
			};
			
		};
	};
	
	
	
public:
	unsigned cbSize;
	char *pszOID;
	System::WideChar *pwszName;
	unsigned dwGroupId;
	_CRYPT_OID_INFO__1 EnumValue;
	CRYPTOAPI_BLOB ExtraInfo;
};


typedef CRYPT_KEY_PROV_PARAM *PCRYPT_KEY_PROV_PARAM;

struct DECLSPEC_DRECORD CRYPT_KEY_PROV_PARAM
{
public:
	unsigned dwParam;
	System::Byte *pbData;
	unsigned cbData;
	unsigned dwFlags;
};


typedef CRYPT_KEY_PROV_INFO *PCRYPT_KEY_PROV_INFO;

struct DECLSPEC_DRECORD CRYPT_KEY_PROV_INFO
{
public:
	System::WideChar *pwszContainerName;
	System::WideChar *pwszProvName;
	unsigned dwProvType;
	unsigned dwFlags;
	unsigned cProvParam;
	CRYPT_KEY_PROV_PARAM *rgProvParam;
	unsigned dwKeySpec;
};


typedef CRYPT_ATTRIBUTE *PCRYPT_ATTRIBUTE;

struct DECLSPEC_DRECORD CRYPT_ATTRIBUTE
{
public:
	char *pszObjId;
	unsigned cValue;
	CRYPTOAPI_BLOB *rgValue;
};


typedef CRYPT_SIGN_MESSAGE_PARA *PCRYPT_SIGN_MESSAGE_PARA;

struct DECLSPEC_DRECORD CRYPT_SIGN_MESSAGE_PARA
{
public:
	unsigned cbSize;
	unsigned dwMsgEncodingType;
	CERT_CONTEXT *pSigningCert;
	CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
	void *pvHashAuxInfo;
	unsigned cMsgCert;
	void *rgpMsgCert;
	unsigned cMsgCrl;
	void *rgpMsgCrl;
	unsigned cAuthAttr;
	CRYPT_ATTRIBUTE *rgAuthAttr;
	unsigned cUnauthAttr;
	CRYPT_ATTRIBUTE *rgUnauthAttr;
	unsigned dwFlags;
	unsigned dwInnerContentType;
};


//-- var, const, procedure ---------------------------------------------------
#define CryptoProviderEnhancedRSA_AES L"Microsoft Enhanced RSA and AES Cryptographic Provider"
#define CryptoProviderEnhancedRSA_AES_XP L"Microsoft Enhanced RSA and AES Cryptographic Provider (Pro"\
	L"totype)"
extern DELPHI_PACKAGE void __fastcall CryptCheck(System::LongBool AResult);
}	/* namespace Dxcryptoapi */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXCRYPTOAPI)
using namespace Dxcryptoapi;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxcryptoapiHPP
