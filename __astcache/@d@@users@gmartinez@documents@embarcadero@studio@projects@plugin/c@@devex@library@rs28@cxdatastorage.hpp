// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxDataStorage.pas' rev: 35.00 (Windows)

#ifndef CxdatastorageHPP
#define CxdatastorageHPP

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
#include <cxVariants.hpp>
#include <dxCore.hpp>
#include <System.Variants.hpp>
#include <Data.FmtBcd.hpp>
#include <Data.SqlTimSt.hpp>
#include <System.AnsiStrings.hpp>
#include <dxCoreClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Cxdatastorage
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TcxValueType;
class DELPHICLASS TcxStringValueType;
class DELPHICLASS TcxWideStringValueType;
class DELPHICLASS TcxSmallintValueType;
class DELPHICLASS TcxIntegerValueType;
class DELPHICLASS TcxWordValueType;
class DELPHICLASS TcxBooleanValueType;
class DELPHICLASS TcxSingleValueType;
class DELPHICLASS TcxFloatValueType;
class DELPHICLASS TcxCurrencyValueType;
class DELPHICLASS TcxDateTimeValueType;
class DELPHICLASS TcxLargeIntValueType;
class DELPHICLASS TcxFMTBcdValueType;
class DELPHICLASS TcxSQLTimeStampValueType;
class DELPHICLASS TcxVariantValueType;
class DELPHICLASS TcxBLOBValueType;
class DELPHICLASS TcxObjectValueType;
class DELPHICLASS TcxValueDef;
class DELPHICLASS TcxValueDefs;
class DELPHICLASS TcxInternalValueDef;
class DELPHICLASS TcxInternalValueDefs;
class DELPHICLASS TcxValueDefReader;
class DELPHICLASS TcxDataStorage;
class DELPHICLASS TcxValueTypeHelper;
class DELPHICLASS TcxDataStorageHelper;
struct TcxLookupListItem;
class DELPHICLASS TcxLookupList;
class DELPHICLASS TcxValueTypeClassList;
//-- type declarations -------------------------------------------------------
typedef __int64 LargeInt;

typedef __int64 *PLargeInt;

enum DECLSPEC_DENUM TcxValueDefDataType : unsigned char { dtEmpty, dtNull, dtValue, dtError };

typedef System::PUnicodeString PStringValue;

typedef System::PWideString PWideStringValue;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxValueType : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	__classmethod virtual int __fastcall Compare(void * P1, void * P2);
	__classmethod virtual void __fastcall FreeBuffer(char * ABuffer);
	__classmethod virtual void __fastcall FreeTextBuffer(char * ABuffer);
	__classmethod virtual int __fastcall GetDataSize();
	__classmethod virtual System::Variant __fastcall GetDataValue(char * ABuffer);
	__classmethod virtual System::UnicodeString __fastcall GetDefaultDisplayText(char * ABuffer);
	__classmethod virtual System::UnicodeString __fastcall GetDisplayText(char * ABuffer);
	__classmethod virtual void __fastcall ReadDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	__classmethod virtual void __fastcall ReadDisplayText(char * ABuffer, Dxcore::TdxStream* AStream);
	__classmethod virtual void __fastcall SetDataValue(char * ABuffer, const System::Variant &Value);
	__classmethod virtual void __fastcall SetDisplayText(char * ABuffer, const System::UnicodeString DisplayText);
	__classmethod virtual void __fastcall WriteDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	__classmethod virtual void __fastcall WriteDisplayText(char * ABuffer, Dxcore::TdxStream* AStream);
	
public:
	__classmethod virtual System::UnicodeString __fastcall Caption();
	__classmethod virtual int __fastcall CompareValues(void * P1, void * P2);
	__classmethod virtual System::Variant __fastcall GetValue(char * ABuffer);
	__classmethod virtual int __fastcall GetVarType();
	__classmethod virtual bool __fastcall IsManaged();
	__classmethod virtual bool __fastcall IsNumeric();
	__classmethod virtual bool __fastcall IsString();
	__classmethod virtual bool __fastcall IsValueValid(System::Variant &Value);
	__classmethod virtual void __fastcall PrepareValueBuffer(char * &ABuffer);
public:
	/* TObject.Create */ inline __fastcall TcxValueType() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxValueType() { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxValueTypeClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxStringValueType : public TcxValueType
{
	typedef TcxValueType inherited;
	
protected:
	__classmethod virtual int __fastcall Compare(void * P1, void * P2);
	__classmethod virtual void __fastcall FreeBuffer(char * ABuffer);
	__classmethod virtual int __fastcall GetDataSize();
	__classmethod virtual System::Variant __fastcall GetDataValue(char * ABuffer);
	__classmethod virtual void __fastcall ReadDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	__classmethod virtual void __fastcall SetDataValue(char * ABuffer, const System::Variant &Value);
	__classmethod virtual void __fastcall WriteDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	
public:
	__classmethod virtual int __fastcall CompareValues(void * P1, void * P2);
	__classmethod virtual System::Variant __fastcall GetValue(char * ABuffer);
	__classmethod virtual int __fastcall GetVarType();
	__classmethod virtual bool __fastcall IsManaged();
	__classmethod virtual bool __fastcall IsString();
	__classmethod virtual void __fastcall PrepareValueBuffer(char * &ABuffer);
public:
	/* TObject.Create */ inline __fastcall TcxStringValueType() : TcxValueType() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxStringValueType() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxWideStringValueType : public TcxStringValueType
{
	typedef TcxStringValueType inherited;
	
protected:
	__classmethod virtual int __fastcall Compare(void * P1, void * P2);
	__classmethod virtual void __fastcall FreeBuffer(char * ABuffer);
	__classmethod virtual int __fastcall GetDataSize();
	__classmethod virtual System::Variant __fastcall GetDataValue(char * ABuffer);
	__classmethod virtual void __fastcall ReadDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	__classmethod virtual void __fastcall SetDataValue(char * ABuffer, const System::Variant &Value);
	__classmethod virtual void __fastcall WriteDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	
public:
	__classmethod virtual int __fastcall CompareValues(void * P1, void * P2);
	__classmethod virtual System::Variant __fastcall GetValue(char * ABuffer);
	__classmethod virtual int __fastcall GetVarType();
	__classmethod virtual bool __fastcall IsString();
	__classmethod virtual void __fastcall PrepareValueBuffer(char * &ABuffer);
public:
	/* TObject.Create */ inline __fastcall TcxWideStringValueType() : TcxStringValueType() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxWideStringValueType() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSmallintValueType : public TcxValueType
{
	typedef TcxValueType inherited;
	
protected:
	__classmethod virtual int __fastcall GetDataSize();
	__classmethod virtual System::Variant __fastcall GetDataValue(char * ABuffer);
	__classmethod virtual void __fastcall ReadDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	__classmethod virtual void __fastcall SetDataValue(char * ABuffer, const System::Variant &Value);
	__classmethod virtual void __fastcall WriteDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	
public:
	__classmethod virtual int __fastcall CompareValues(void * P1, void * P2);
	__classmethod virtual int __fastcall GetVarType();
	__classmethod virtual bool __fastcall IsNumeric();
public:
	/* TObject.Create */ inline __fastcall TcxSmallintValueType() : TcxValueType() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSmallintValueType() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxIntegerValueType : public TcxValueType
{
	typedef TcxValueType inherited;
	
protected:
	__classmethod virtual int __fastcall GetDataSize();
	__classmethod virtual System::Variant __fastcall GetDataValue(char * ABuffer);
	__classmethod virtual void __fastcall ReadDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	__classmethod virtual void __fastcall SetDataValue(char * ABuffer, const System::Variant &Value);
	__classmethod virtual void __fastcall WriteDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	
public:
	__classmethod virtual int __fastcall CompareValues(void * P1, void * P2);
	__classmethod virtual int __fastcall GetVarType();
	__classmethod virtual bool __fastcall IsNumeric();
public:
	/* TObject.Create */ inline __fastcall TcxIntegerValueType() : TcxValueType() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxIntegerValueType() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxWordValueType : public TcxValueType
{
	typedef TcxValueType inherited;
	
protected:
	__classmethod virtual int __fastcall GetDataSize();
	__classmethod virtual System::Variant __fastcall GetDataValue(char * ABuffer);
	__classmethod virtual void __fastcall ReadDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	__classmethod virtual void __fastcall SetDataValue(char * ABuffer, const System::Variant &Value);
	__classmethod virtual void __fastcall WriteDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	
public:
	__classmethod virtual int __fastcall CompareValues(void * P1, void * P2);
	__classmethod virtual int __fastcall GetVarType();
	__classmethod virtual bool __fastcall IsNumeric();
public:
	/* TObject.Create */ inline __fastcall TcxWordValueType() : TcxValueType() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxWordValueType() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxBooleanValueType : public TcxValueType
{
	typedef TcxValueType inherited;
	
protected:
	__classmethod virtual int __fastcall GetDataSize();
	__classmethod virtual System::Variant __fastcall GetDataValue(char * ABuffer);
	__classmethod virtual System::UnicodeString __fastcall GetDefaultDisplayText(char * ABuffer);
	__classmethod virtual void __fastcall ReadDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	__classmethod virtual void __fastcall SetDataValue(char * ABuffer, const System::Variant &Value);
	__classmethod virtual void __fastcall WriteDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	
public:
	__classmethod virtual int __fastcall CompareValues(void * P1, void * P2);
	__classmethod virtual int __fastcall GetVarType();
public:
	/* TObject.Create */ inline __fastcall TcxBooleanValueType() : TcxValueType() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxBooleanValueType() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSingleValueType : public TcxValueType
{
	typedef TcxValueType inherited;
	
protected:
	__classmethod virtual int __fastcall GetDataSize();
	__classmethod virtual System::Variant __fastcall GetDataValue(char * ABuffer);
	__classmethod virtual void __fastcall ReadDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	__classmethod virtual void __fastcall SetDataValue(char * ABuffer, const System::Variant &Value);
	__classmethod virtual void __fastcall WriteDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	
public:
	__classmethod virtual int __fastcall CompareValues(void * P1, void * P2);
	__classmethod virtual int __fastcall GetVarType();
	__classmethod virtual bool __fastcall IsNumeric();
public:
	/* TObject.Create */ inline __fastcall TcxSingleValueType() : TcxValueType() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSingleValueType() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFloatValueType : public TcxValueType
{
	typedef TcxValueType inherited;
	
protected:
	__classmethod virtual int __fastcall GetDataSize();
	__classmethod virtual System::Variant __fastcall GetDataValue(char * ABuffer);
	__classmethod virtual void __fastcall ReadDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	__classmethod virtual void __fastcall SetDataValue(char * ABuffer, const System::Variant &Value);
	__classmethod virtual void __fastcall WriteDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	
public:
	__classmethod virtual int __fastcall CompareValues(void * P1, void * P2);
	__classmethod virtual int __fastcall GetVarType();
	__classmethod virtual bool __fastcall IsNumeric();
public:
	/* TObject.Create */ inline __fastcall TcxFloatValueType() : TcxValueType() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxFloatValueType() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCurrencyValueType : public TcxValueType
{
	typedef TcxValueType inherited;
	
protected:
	__classmethod virtual int __fastcall GetDataSize();
	__classmethod virtual System::Variant __fastcall GetDataValue(char * ABuffer);
	__classmethod virtual void __fastcall ReadDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	__classmethod virtual void __fastcall SetDataValue(char * ABuffer, const System::Variant &Value);
	__classmethod virtual void __fastcall WriteDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	
public:
	__classmethod virtual int __fastcall CompareValues(void * P1, void * P2);
	__classmethod virtual int __fastcall GetVarType();
	__classmethod virtual bool __fastcall IsNumeric();
public:
	/* TObject.Create */ inline __fastcall TcxCurrencyValueType() : TcxValueType() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCurrencyValueType() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDateTimeValueType : public TcxValueType
{
	typedef TcxValueType inherited;
	
private:
	__classmethod System::TDateTime __fastcall GetDateTime(char * ABuffer);
	
protected:
	__classmethod virtual int __fastcall GetDataSize();
	__classmethod virtual System::Variant __fastcall GetDataValue(char * ABuffer);
	__classmethod virtual System::UnicodeString __fastcall GetDefaultDisplayText(char * ABuffer);
	__classmethod virtual void __fastcall ReadDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	__classmethod virtual void __fastcall SetDataValue(char * ABuffer, const System::Variant &Value);
	__classmethod virtual void __fastcall WriteDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	
public:
	__classmethod virtual int __fastcall CompareValues(void * P1, void * P2);
	__classmethod virtual int __fastcall GetVarType();
	__classmethod virtual bool __fastcall IsNumeric();
public:
	/* TObject.Create */ inline __fastcall TcxDateTimeValueType() : TcxValueType() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDateTimeValueType() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxLargeIntValueType : public TcxValueType
{
	typedef TcxValueType inherited;
	
protected:
	__classmethod virtual int __fastcall GetDataSize();
	__classmethod virtual System::Variant __fastcall GetDataValue(char * ABuffer);
	__classmethod virtual void __fastcall ReadDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	__classmethod virtual void __fastcall SetDataValue(char * ABuffer, const System::Variant &Value);
	__classmethod virtual void __fastcall WriteDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	
public:
	__classmethod virtual int __fastcall CompareValues(void * P1, void * P2);
	__classmethod virtual int __fastcall GetVarType();
	__classmethod virtual bool __fastcall IsNumeric();
public:
	/* TObject.Create */ inline __fastcall TcxLargeIntValueType() : TcxValueType() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxLargeIntValueType() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFMTBcdValueType : public TcxValueType
{
	typedef TcxValueType inherited;
	
protected:
	__classmethod virtual int __fastcall GetDataSize();
	__classmethod virtual System::Variant __fastcall GetDataValue(char * ABuffer);
	__classmethod virtual System::UnicodeString __fastcall GetDefaultDisplayText(char * ABuffer);
	__classmethod virtual void __fastcall SetDataValue(char * ABuffer, const System::Variant &Value);
	
public:
	__classmethod virtual int __fastcall CompareValues(void * P1, void * P2);
	__classmethod virtual int __fastcall GetVarType();
	__classmethod virtual bool __fastcall IsNumeric();
public:
	/* TObject.Create */ inline __fastcall TcxFMTBcdValueType() : TcxValueType() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxFMTBcdValueType() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSQLTimeStampValueType : public TcxValueType
{
	typedef TcxValueType inherited;
	
protected:
	__classmethod virtual int __fastcall GetDataSize();
	__classmethod virtual System::Variant __fastcall GetDataValue(char * ABuffer);
	__classmethod virtual void __fastcall SetDataValue(char * ABuffer, const System::Variant &Value);
	
public:
	__classmethod virtual int __fastcall CompareValues(void * P1, void * P2);
	__classmethod virtual int __fastcall GetVarType();
	__classmethod virtual bool __fastcall IsNumeric();
public:
	/* TObject.Create */ inline __fastcall TcxSQLTimeStampValueType() : TcxValueType() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSQLTimeStampValueType() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxVariantValueType : public TcxValueType
{
	typedef TcxValueType inherited;
	
protected:
	__classmethod virtual int __fastcall Compare(void * P1, void * P2);
	__classmethod virtual void __fastcall FreeBuffer(char * ABuffer);
	__classmethod virtual int __fastcall GetDataSize();
	__classmethod virtual System::Variant __fastcall GetDataValue(char * ABuffer);
	__classmethod virtual void __fastcall SetDataValue(char * ABuffer, const System::Variant &Value);
	
public:
	__classmethod virtual int __fastcall CompareValues(void * P1, void * P2);
	__classmethod virtual System::Variant __fastcall GetValue(char * ABuffer);
	__classmethod virtual void __fastcall PrepareValueBuffer(char * &ABuffer);
	__classmethod virtual bool __fastcall IsManaged();
public:
	/* TObject.Create */ inline __fastcall TcxVariantValueType() : TcxValueType() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxVariantValueType() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxBLOBValueType : public TcxValueType
{
	typedef TcxValueType inherited;
	
protected:
	__classmethod virtual int __fastcall Compare(void * P1, void * P2);
	__classmethod virtual void __fastcall FreeBuffer(char * ABuffer);
	__classmethod System::AnsiString __fastcall GetAnsiString(char * ABuffer);
	__classmethod virtual int __fastcall GetDataSize();
	__classmethod virtual System::Variant __fastcall GetDataValue(char * ABuffer);
	__classmethod virtual void __fastcall ReadDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	__classmethod virtual void __fastcall SetDataValue(char * ABuffer, const System::Variant &Value);
	__classmethod virtual void __fastcall WriteDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	
public:
	__classmethod virtual int __fastcall CompareValues(void * P1, void * P2);
	__classmethod virtual System::Variant __fastcall GetValue(char * ABuffer);
	__classmethod virtual int __fastcall GetVarType();
	__classmethod virtual bool __fastcall IsManaged();
	__classmethod virtual bool __fastcall IsString();
	__classmethod virtual void __fastcall PrepareValueBuffer(char * &ABuffer);
public:
	/* TObject.Create */ inline __fastcall TcxBLOBValueType() : TcxValueType() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxBLOBValueType() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxObjectValueType : public TcxIntegerValueType
{
	typedef TcxIntegerValueType inherited;
	
protected:
	__classmethod virtual void __fastcall FreeBuffer(char * ABuffer);
	__classmethod virtual void __fastcall ReadDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	__classmethod virtual void __fastcall SetDataValue(char * ABuffer, const System::Variant &Value);
	__classmethod virtual void __fastcall WriteDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	
public:
	__classmethod virtual bool __fastcall IsManaged();
public:
	/* TObject.Create */ inline __fastcall TcxObjectValueType() : TcxIntegerValueType() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxObjectValueType() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxValueDef : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FBufferSize;
	int FDataOffset;
	int FDataSize;
	int FDisplayTextOffset;
	bool FIsNeedConversion;
	int FOffset;
	bool FStored;
	bool FStreamStored;
	TcxValueDefs* FValueDefs;
	TcxValueTypeClass FValueTypeClass;
	bool __fastcall GetTextStored();
	void __fastcall SetStored(bool Value);
	void __fastcall SetTextStored(bool Value);
	void __fastcall SetValueTypeClass(TcxValueTypeClass Value);
	
protected:
	System::TObject* FLinkObject;
	bool FTextStored;
	void __fastcall Changed(bool AResyncNeeded);
	void __fastcall ClearValue(char * ABuffer);
	int __fastcall Compare(char * P1, char * P2);
	void __fastcall FreeBuffer(char * ABuffer);
	void __fastcall FreeTextBuffer(char * ABuffer);
	char * __fastcall GetDataFromBuffer(char * ABuffer);
	TcxValueDefDataType __fastcall GetDataType(char * ABuffer);
	System::Variant __fastcall GetDataValue(char * ABuffer);
	System::UnicodeString __fastcall GetDisplayText(char * ABuffer);
	char * __fastcall GetDisplayTextFromBuffer(char * ABuffer);
	int __fastcall GetErrorCode(char * ABuffer);
	virtual System::TObject* __fastcall GetLinkObject();
	virtual bool __fastcall GetStored();
	void __fastcall Init(int &AOffset);
	bool __fastcall IsNullValueEx(char * ABuffer);
	void __fastcall ReadDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	void __fastcall ReadDisplayText(char * ABuffer, Dxcore::TdxStream* AStream);
	void __fastcall SetDataValue(char * ABuffer, const System::Variant &Value);
	void __fastcall SetDisplayText(char * ABuffer, const System::UnicodeString DisplayText);
	void __fastcall SetErrorCode(char * ABuffer, int ACode);
	virtual void __fastcall SetLinkObject(System::TObject* Value);
	void __fastcall SetNullValue(char * ABuffer);
	void __fastcall SetValueFlag(char * ABuffer, char AValue);
	bool __fastcall UseDataBuffer(char * ABuffer);
	void __fastcall WriteDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	void __fastcall WriteDisplayText(char * ABuffer, Dxcore::TdxStream* AStream);
	
public:
	__fastcall virtual TcxValueDef(TcxValueDefs* AValueDefs, TcxValueTypeClass AValueTypeClass);
	__fastcall virtual ~TcxValueDef();
	virtual void __fastcall Assign(TcxValueDef* ASource);
	int __fastcall CompareValues(bool AIsNull1, bool AIsNull2, char * P1, char * P2);
	__property int BufferSize = {read=FBufferSize, nodefault};
	__property int DataSize = {read=FDataSize, nodefault};
	__property bool IsNeedConversion = {read=FIsNeedConversion, nodefault};
	__property System::TObject* LinkObject = {read=GetLinkObject, write=SetLinkObject};
	__property int Offset = {read=FOffset, nodefault};
	__property bool Stored = {read=GetStored, write=SetStored, default=1};
	__property bool StreamStored = {read=FStreamStored, write=FStreamStored, default=1};
	__property bool TextStored = {read=GetTextStored, write=SetTextStored, default=0};
	__property TcxValueDefs* ValueDefs = {read=FValueDefs};
	__property TcxValueTypeClass ValueTypeClass = {read=FValueTypeClass, write=SetValueTypeClass};
};

#pragma pack(pop)

typedef System::TMetaClass* TcxValueDefClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxValueDefs : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxValueDef* operator[](int Index) { return this->Items[Index]; }
	
private:
	TcxDataStorage* FDataStorage;
	System::Classes::TList* FItems;
	int FRecordOffset;
	int FRecordSize;
	int __fastcall GetStoredCount();
	int __fastcall GetCount();
	TcxValueDef* __fastcall GetItem(int Index);
	
protected:
	virtual void __fastcall Changed(TcxValueDef* AValueDef, bool AResyncNeeded);
	virtual TcxValueDefClass __fastcall GetValueDefClass();
	virtual void __fastcall Prepare(int AStartOffset);
	void __fastcall Remove(TcxValueDef* AItem);
	__property TcxDataStorage* DataStorage = {read=FDataStorage};
	
public:
	__fastcall virtual TcxValueDefs(TcxDataStorage* ADataStorage);
	__fastcall virtual ~TcxValueDefs();
	TcxValueDef* __fastcall Add(TcxValueTypeClass AValueTypeClass, bool AStored, bool ATextStored, System::TObject* ALinkObject);
	void __fastcall Clear();
	__property int StoredCount = {read=GetStoredCount, nodefault};
	__property int Count = {read=GetCount, nodefault};
	__property TcxValueDef* Items[int Index] = {read=GetItem/*, default*/};
	__property int RecordSize = {read=FRecordSize, nodefault};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxInternalValueDef : public TcxValueDef
{
	typedef TcxValueDef inherited;
	
protected:
	virtual System::TObject* __fastcall GetLinkObject();
	virtual bool __fastcall GetStored();
	
public:
	TcxValueDef* __fastcall GetValueDef();
public:
	/* TcxValueDef.Create */ inline __fastcall virtual TcxInternalValueDef(TcxValueDefs* AValueDefs, TcxValueTypeClass AValueTypeClass) : TcxValueDef(AValueDefs, AValueTypeClass) { }
	/* TcxValueDef.Destroy */ inline __fastcall virtual ~TcxInternalValueDef() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxInternalValueDefs : public TcxValueDefs
{
	typedef TcxValueDefs inherited;
	
protected:
	virtual TcxValueDefClass __fastcall GetValueDefClass();
	
public:
	TcxValueDef* __fastcall FindByLinkObject(System::TObject* ALinkObject);
	void __fastcall RemoveByLinkObject(System::TObject* ALinkObject);
public:
	/* TcxValueDefs.Create */ inline __fastcall virtual TcxInternalValueDefs(TcxDataStorage* ADataStorage) : TcxValueDefs(ADataStorage) { }
	/* TcxValueDefs.Destroy */ inline __fastcall virtual ~TcxInternalValueDefs() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxValueDefReader : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__fastcall virtual TcxValueDefReader();
	void __fastcall ClearValue(char * ABuffer, TcxValueDef* AValueDef);
	virtual System::UnicodeString __fastcall GetDisplayText(TcxValueDef* AValueDef);
	virtual System::Variant __fastcall GetValue(TcxValueDef* AValueDef);
	virtual bool __fastcall IsInternal(TcxValueDef* AValueDef);
	virtual void __fastcall Read(char * ABuffer, TcxValueDef* AValueDef);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxValueDefReader() { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxValueDefReaderClass;

typedef void __fastcall (__closure *TcxValueDefSetProc)(TcxValueDef* AValueDef, int AFromRecordIndex, int AToRecordIndex, TcxValueDefReader* AValueDefReader);

typedef void __fastcall (__closure *TcxOnClearRecord)(System::TObject* Sender, int ARecordIndex);

class PASCALIMPLEMENTATION TcxDataStorage : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FDestroying;
	System::Classes::TList* FInternalRecordBuffers;
	TcxInternalValueDefs* FInternalValueDefs;
	bool FStoredValuesOnly;
	System::Classes::TList* FRecordBuffers;
	int FRecordIDCounter;
	bool FUseRecordID;
	TcxValueDefs* FValueDefs;
	System::Classes::TList* FValueDefsList;
	System::Classes::TNotifyEvent FOnClearInternalRecords;
	TcxOnClearRecord FOnClearRecord;
	char * __fastcall GetRecordBuffer(int Index);
	int __fastcall GetRecordCount();
	void __fastcall SetStoredValuesOnly(bool Value);
	void __fastcall SetRecordBuffer(int Index, char * Value);
	void __fastcall SetRecordCount(int Value);
	void __fastcall SetUseRecordID(bool Value);
	
protected:
	char * __fastcall AllocRecordBuffer(int Index);
	int __fastcall CalcRecordOffset();
	void __fastcall ChangeRecordFlag(char * ABuffer, System::Byte AFlag, bool ATurnOn);
	void __fastcall CheckRecordID(int ARecordIndex);
	void __fastcall CheckRecordIDCounter();
	void __fastcall CheckRecordIDCounterAfterLoad(int ALoadedID);
	bool __fastcall CheckValueDef(int ARecordIndex, TcxValueDef* &AValueDef);
	void __fastcall DeleteInternalRecord(int ARecordIndex);
	void __fastcall FreeAndNilRecordBuffer(int AIndex);
	virtual void __fastcall InitStructure(TcxValueDefs* AValueDefs);
	void __fastcall InsertValueDef(int AIndex, TcxValueDef* AValueDef);
	bool __fastcall IsRecordFlag(char * ABuffer, System::Byte AFlag);
	void __fastcall RemoveValueDef(TcxValueDef* AValueDef);
	virtual void __fastcall ValueDefsChanged(TcxValueDef* AValueDef, bool AResyncNeeded);
	virtual TcxValueDefs* __fastcall ValueDefsByRecordIndex(int Index);
	__property TcxInternalValueDefs* InternalValueDefs = {read=FInternalValueDefs};
	
public:
	__fastcall virtual TcxDataStorage();
	__fastcall virtual ~TcxDataStorage();
	int __fastcall AddInternalRecord();
	int __fastcall AppendRecord();
	virtual void __fastcall BeforeDestruction();
	void __fastcall BeginLoad();
	void __fastcall CheckStructure();
	void __fastcall Clear(bool AWithoutInternal);
	void __fastcall ClearInternalRecords();
	void __fastcall ClearRecords(bool AClearList);
	void __fastcall ClearValue(int ARecordIndex, TcxValueDef* AValueDef);
	int __fastcall CompareRecords(int ARecordIndex1, int ARecordIndex2, TcxValueDef* AValueDef);
	void __fastcall DeleteRecord(int ARecordIndex);
	void __fastcall EndLoad();
	System::UnicodeString __fastcall GetDisplayText(int ARecordIndex, TcxValueDef* AValueDef);
	bool __fastcall GetCompareInfo(int ARecordIndex, TcxValueDef* AValueDef, char * &P);
	int __fastcall GetErrorCode(int ARecordIndex, TcxValueDef* AValueDef);
	int __fastcall GetRecordID(int ARecordIndex);
	System::Variant __fastcall GetValue(int ARecordIndex, TcxValueDef* AValueDef);
	void __fastcall InsertRecord(int ARecordIndex);
	bool __fastcall IsValueEmpty(int ARecordIndex, TcxValueDef* AValueDef);
	void __fastcall ReadData(int ARecordIndex, System::Classes::TStream* AStream);
	void __fastcall ReadDataByFields(int ARecordIndex, TcxValueDefReader* AValueDefReader, System::Classes::TList* AFields);
	void __fastcall ReadRecord(int ARecordIndex, TcxValueDefReader* AValueDefReader);
	void __fastcall ReadRecordFrom(int AFromRecordIndex, int AToRecordIndex, TcxValueDefReader* AValueDefReader, TcxValueDefSetProc ASetProc);
	void __fastcall SetDisplayText(int ARecordIndex, TcxValueDef* AValueDef, const System::UnicodeString Value);
	void __fastcall SetErrorCode(int ARecordIndex, TcxValueDef* AValueDef, int ACode);
	void __fastcall SetRecordID(int ARecordIndex, int AID);
	void __fastcall SetValue(int ARecordIndex, TcxValueDef* AValueDef, const System::Variant &Value);
	void __fastcall WriteData(int ARecordIndex, System::Classes::TStream* AStream);
	void __fastcall BeginStreaming(System::Classes::TListSortCompare ACompare);
	void __fastcall EndStreaming();
	__property bool StoredValuesOnly = {read=FStoredValuesOnly, write=SetStoredValuesOnly, nodefault};
	__property bool UseRecordID = {read=FUseRecordID, write=SetUseRecordID, nodefault};
	__property char * RecordBuffers[int Index] = {read=GetRecordBuffer, write=SetRecordBuffer};
	__property int RecordCount = {read=GetRecordCount, write=SetRecordCount, nodefault};
	__property TcxValueDefs* ValueDefs = {read=FValueDefs};
	__property System::Classes::TNotifyEvent OnClearInternalRecords = {read=FOnClearInternalRecords, write=FOnClearInternalRecords};
	__property TcxOnClearRecord OnClearRecord = {read=FOnClearRecord, write=FOnClearRecord};
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxValueTypeHelper : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	static int __fastcall Compare(TcxValueTypeClass AValueTypeClass, void * P1, void * P2);
	static void __fastcall FreeBuffer(TcxValueTypeClass AValueTypeClass, char * ABuffer);
	static void __fastcall FreeTextBuffer(TcxValueTypeClass AValueTypeClass, char * ABuffer);
	static int __fastcall GetDataSize(TcxValueTypeClass AValueTypeClass);
	static System::Variant __fastcall GetDataValue(TcxValueTypeClass AValueTypeClass, char * ABuffer);
	static System::UnicodeString __fastcall GetDefaultDisplayText(TcxValueTypeClass AValueTypeClass, char * ABuffer);
	static System::UnicodeString __fastcall GetDisplayText(TcxValueTypeClass AValueTypeClass, char * ABuffer);
	static void __fastcall ReadDataValue(TcxValueTypeClass AValueTypeClass, char * ABuffer, Dxcore::TdxStream* AStream);
	static void __fastcall ReadDisplayText(TcxValueTypeClass AValueTypeClass, char * ABuffer, Dxcore::TdxStream* AStream);
	static void __fastcall SetDataValue(TcxValueTypeClass AValueTypeClass, char * ABuffer, const System::Variant &AValue);
	static void __fastcall SetDisplayText(TcxValueTypeClass AValueTypeClass, char * ABuffer, const System::UnicodeString ADisplayText);
	static void __fastcall WriteDataValue(TcxValueTypeClass AValueTypeClass, char * ABuffer, Dxcore::TdxStream* AStream);
	static void __fastcall WriteDisplayText(TcxValueTypeClass AValueTypeClass, char * ABuffer, Dxcore::TdxStream* AStream);
public:
	/* TObject.Create */ inline __fastcall TcxValueTypeHelper() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxValueTypeHelper() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataStorageHelper : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod void * __fastcall AllocateRecord(TcxDataStorage* ADataStorage);
	__classmethod int __fastcall AppendRecord(TcxDataStorage* ADataStorage, void * ARecord);
	__classmethod void __fastcall ClearValue(void * ARecord, TcxValueDef* AValueDef);
	__classmethod int __fastcall Compare(TcxValueDef* AValueDef, void * ARecord1, void * ARecord2);
	__classmethod void __fastcall FreeBuffer(TcxValueDef* AValueDef, void * ARecord);
	__classmethod System::UnicodeString __fastcall GetDisplayText(TcxValueDef* AValueDef, void * ARecord);
	__classmethod System::Variant __fastcall GetErrorCode(TcxValueDef* AValueDef, void * ARecord);
	__classmethod int __fastcall GetRecordSize(TcxDataStorage* ADataStorage);
	__classmethod int __fastcall GetStoredCount(TcxDataStorage* ADataStorage);
	__classmethod System::Variant __fastcall GetValue(TcxValueDef* AValueDef, void * ARecord);
	__classmethod bool __fastcall IsValueEmpty(TcxValueDef* AValueDef, void * ARecord);
	__classmethod void * __fastcall RemoveRecord(TcxDataStorage* ADataStorage, int ARecordIndex);
	__classmethod void __fastcall SetDisplayText(void * ARecord, TcxValueDef* AValueDef, const System::UnicodeString AValue);
	__classmethod void __fastcall SetErrorCode(void * ARecord, TcxValueDef* AValueDef, const System::Variant &ACode);
	__classmethod void __fastcall SetRecordsCapacity(TcxDataStorage* ADataStorage, int ACapacity);
	__classmethod void __fastcall SetTextStored(TcxValueDef* AValueDef, bool ATextStored);
	__classmethod void __fastcall SetValue(void * ARecord, TcxValueDef* AValueDef, const System::Variant &AValue);
	__classmethod void __fastcall FreeRecord(TcxDataStorage* ADataStorage, void * &ARecord);
public:
	/* TObject.Create */ inline __fastcall TcxDataStorageHelper() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDataStorageHelper() { }
	
};

#pragma pack(pop)

struct DECLSPEC_DRECORD TcxLookupListItem
{
public:
	System::Variant KeyValue;
	System::UnicodeString DisplayText;
};


typedef TcxLookupListItem *PcxLookupListItem;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxLookupList : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	PcxLookupListItem operator[](int Index) { return this->Items[Index]; }
	
private:
	System::Classes::TList* FItems;
	int __fastcall GetCount();
	PcxLookupListItem __fastcall GetItem(int Index);
	
public:
	__fastcall TcxLookupList();
	__fastcall virtual ~TcxLookupList();
	void __fastcall Clear();
	bool __fastcall Find(const System::Variant &AKeyValue, int &AIndex);
	void __fastcall Insert(int AIndex, const System::Variant &AKeyValue, const System::UnicodeString ADisplayText);
	__property int Count = {read=GetCount, nodefault};
	__property PcxLookupListItem Items[int Index] = {read=GetItem/*, default*/};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxValueTypeClassList : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxValueTypeClass operator[](int Index) { return this->Items[Index]; }
	
private:
	System::Classes::TList* FItems;
	int __fastcall GetCount();
	TcxValueTypeClass __fastcall GetItem(int Index);
	
public:
	__fastcall TcxValueTypeClassList();
	__fastcall virtual ~TcxValueTypeClassList();
	TcxValueTypeClass __fastcall ItemByCaption(const System::UnicodeString ACaption);
	void __fastcall RegisterItem(TcxValueTypeClass AValueTypeClass);
	void __fastcall UnregisterItem(TcxValueTypeClass AValueTypeClass);
	__property int Count = {read=GetCount, nodefault};
	__property TcxValueTypeClass Items[int Index] = {read=GetItem/*, default*/};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE TcxValueTypeClassList* __fastcall cxValueTypeClassList(void);
extern DELPHI_PACKAGE bool __fastcall IsDateTimeValueTypeClass(TcxValueTypeClass AValueTypeClass);
}	/* namespace Cxdatastorage */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXDATASTORAGE)
using namespace Cxdatastorage;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxdatastorageHPP
