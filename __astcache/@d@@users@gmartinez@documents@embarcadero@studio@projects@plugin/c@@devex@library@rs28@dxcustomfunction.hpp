// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxCustomFunction.pas' rev: 35.00 (Windows)

#ifndef DxcustomfunctionHPP
#define DxcustomfunctionHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Classes.hpp>
#include <System.Types.hpp>
#include <System.TypInfo.hpp>

//-- user supplied -----------------------------------------------------------

namespace Dxcustomfunction
{
//-- forward type declarations -----------------------------------------------
__interface DELPHIINTERFACE IdxCustomFunctionContainer;
typedef System::DelphiInterface<IdxCustomFunctionContainer> _di_IdxCustomFunctionContainer;
class DELPHICLASS TdxCustomFunctionOperator;
class DELPHICLASS TdxCustomFunctionOperatorBrowsable;
class DELPHICLASS TdxCustomFunctionDisplayAttributes;
class DELPHICLASS TdxCustomFunctionOperatorFactory;
//-- type declarations -------------------------------------------------------
__interface  INTERFACE_UUID("{96B14169-B9A6-465F-B10F-89288993F8FB}") IdxCustomFunctionContainer  : public System::IInterface 
{
	virtual System::UnicodeString __fastcall GetCustomFunctions(System::Classes::TStrings* ACustomFunctions) = 0 ;
};

enum DECLSPEC_DENUM TdxFunctionCategory : unsigned char { DateTime, Logical, Math, Text };

typedef System::TMetaClass* TdxCustomFunctionOperatorClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomFunctionOperator : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetName();
	virtual System::Typinfo::PTypeInfo __fastcall ResultType() = 0 ;
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetFunctionName();
	virtual System::Variant __fastcall Evaluate(const System::Variant *AOperands, const int AOperands_High) = 0 ;
	__property System::UnicodeString Name = {read=GetName};
public:
	/* TObject.Create */ inline __fastcall TdxCustomFunctionOperator() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxCustomFunctionOperator() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomFunctionOperatorBrowsable : public TdxCustomFunctionOperator
{
	typedef TdxCustomFunctionOperator inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetDescription() = 0 ;
	virtual TdxFunctionCategory __fastcall GetFunctionCategory() = 0 ;
	virtual bool __fastcall IsValidOperandCount(int ACount);
	virtual bool __fastcall IsValidOperandType(int AOperandIndex, int AOperandCount, System::Typinfo::PTypeInfo AType);
	
public:
	virtual int __fastcall MinOperandCount() = 0 ;
	virtual int __fastcall MaxOperandCount() = 0 ;
	__property System::UnicodeString Description = {read=GetDescription};
	__property TdxFunctionCategory FunctionCategory = {read=GetFunctionCategory, nodefault};
public:
	/* TObject.Create */ inline __fastcall TdxCustomFunctionOperatorBrowsable() : TdxCustomFunctionOperator() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxCustomFunctionOperatorBrowsable() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomFunctionDisplayAttributes : public TdxCustomFunctionOperatorBrowsable
{
	typedef TdxCustomFunctionOperatorBrowsable inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetDisplayName() = 0 ;
	
public:
	__property System::UnicodeString DisplayName = {read=GetDisplayName};
public:
	/* TObject.Create */ inline __fastcall TdxCustomFunctionDisplayAttributes() : TdxCustomFunctionOperatorBrowsable() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxCustomFunctionDisplayAttributes() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomFunctionOperatorFactory : /*[[sealed]]*/ public System::TObject
{
	typedef System::TObject inherited;
	
public:
	static System::UnicodeString __fastcall GetCustomFunctionOperatorName(TdxCustomFunctionOperator* ACustomFunctionOperator);
	__classmethod TdxCustomFunctionOperator* __fastcall GetCustomFunctionOperator(const System::UnicodeString ACustomFunctionName);
	__classmethod void __fastcall Register(TdxCustomFunctionOperatorClass ACustomFunctionOperatorClass)/* overload */;
	__classmethod void __fastcall Register(TdxCustomFunctionOperatorClass const *ACustomFunctionOperatorClasses, const int ACustomFunctionOperatorClasses_High)/* overload */;
	__classmethod void __fastcall UnRegister(TdxCustomFunctionOperatorClass ACustomFunctionOperatorClass);
public:
	/* TObject.Create */ inline __fastcall TdxCustomFunctionOperatorFactory() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxCustomFunctionOperatorFactory() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxcustomfunction */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXCUSTOMFUNCTION)
using namespace Dxcustomfunction;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxcustomfunctionHPP
