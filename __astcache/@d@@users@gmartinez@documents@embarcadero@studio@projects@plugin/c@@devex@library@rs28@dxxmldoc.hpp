// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxXMLDoc.pas' rev: 35.00 (Windows)

#ifndef DxxmldocHPP
#define DxxmldocHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Hash.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <Winapi.Windows.hpp>
#include <System.StrUtils.hpp>
#include <System.AnsiStrings.hpp>
#include <dxCore.hpp>
#include <dxCoreClasses.hpp>
#include <dxCustomTree.hpp>
#include <System.Generics.Defaults.hpp>
#include <System.Generics.Collections.hpp>
#include <dxHash.hpp>
#include <dxHashUtils.hpp>

//-- user supplied -----------------------------------------------------------

namespace Dxxmldoc
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS EdxXMLUnexpectedToken;
struct TdxXMLToken;
struct TdxXMLDateTime;
class DELPHICLASS TdxXMLSharedStrings;
class DELPHICLASS TdxXMLParser;
class DELPHICLASS TdxXMLHelper;
class DELPHICLASS TdxXMLNodeAttribute;
class DELPHICLASS TdxXMLNodeAttributes;
class DELPHICLASS TdxXMLNodes;
__interface DELPHIINTERFACE TdxXMLNodeForEachProc;
typedef System::DelphiInterface<TdxXMLNodeForEachProc> _di_TdxXMLNodeForEachProc;
class DELPHICLASS TdxXMLNode;
class DELPHICLASS TdxXMLDocument;
class DELPHICLASS TdxXMLPackableNode;
class DELPHICLASS TdxXMLPackableNodeAttributes;
class DELPHICLASS TdxXMLPackableDocument;
//-- type declarations -------------------------------------------------------
typedef System::AnsiString TdxXMLString;

#pragma pack(push,4)
class PASCALIMPLEMENTATION EdxXMLUnexpectedToken : public Dxcore::EdxException
{
	typedef Dxcore::EdxException inherited;
	
public:
	__fastcall EdxXMLUnexpectedToken(const System::UnicodeString AToken, const System::UnicodeString AStringForParsing);
public:
	/* Exception.CreateFmt */ inline __fastcall EdxXMLUnexpectedToken(const System::UnicodeString Msg, const System::TVarRec *Args, const int Args_High) : Dxcore::EdxException(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EdxXMLUnexpectedToken(NativeUInt Ident)/* overload */ : Dxcore::EdxException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EdxXMLUnexpectedToken(System::PResStringRec ResStringRec)/* overload */ : Dxcore::EdxException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxXMLUnexpectedToken(NativeUInt Ident, const System::TVarRec *Args, const int Args_High)/* overload */ : Dxcore::EdxException(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxXMLUnexpectedToken(System::PResStringRec ResStringRec, const System::TVarRec *Args, const int Args_High)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EdxXMLUnexpectedToken(const System::UnicodeString Msg, int AHelpContext) : Dxcore::EdxException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EdxXMLUnexpectedToken(const System::UnicodeString Msg, const System::TVarRec *Args, const int Args_High, int AHelpContext) : Dxcore::EdxException(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxXMLUnexpectedToken(NativeUInt Ident, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxXMLUnexpectedToken(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxXMLUnexpectedToken(System::PResStringRec ResStringRec, const System::TVarRec *Args, const int Args_High, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxXMLUnexpectedToken(NativeUInt Ident, const System::TVarRec *Args, const int Args_High, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EdxXMLUnexpectedToken() { }
	
};

#pragma pack(pop)

enum DECLSPEC_DENUM TdxXMLEncoding : unsigned char { dxxeNone, dxxeUTF8, dxxeWindows };

enum DECLSPEC_DENUM TdxXMLTokenID : unsigned char { ttUnknown, ttEqual, ttTagHeaderBegin, ttTagHeaderEnd, ttTagEnd, ttTagFooter, ttComment, ttCDATA };

#pragma pack(push,1)
struct DECLSPEC_DRECORD TdxXMLToken
{
public:
	char *Buffer;
	int BufferLengthInChars;
	TdxXMLTokenID TokenType;
};
#pragma pack(pop)


struct DECLSPEC_DRECORD TdxXMLDateTime
{
public:
	System::Word Year;
	System::Word Month;
	System::Word Day;
	System::Word Hour;
	System::Word Minute;
	System::Word Second;
	System::Word Millisecond;
	bool IsUTC;
	static TdxXMLDateTime __fastcall Create(const System::UnicodeString ASource)/* overload */;
	static TdxXMLDateTime __fastcall Create(const System::TDateTime ASource, bool AIsUTC = false)/* overload */;
	void __fastcall Assign(const System::TDateTime ASource, bool AIsUTC = false);
	void __fastcall Clear();
	void __fastcall Parse(const System::UnicodeString S);
	System::TDateTime __fastcall ToDateTime();
	System::UnicodeString __fastcall ToString();
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxXMLSharedStrings : public System::TObject
{
	typedef System::TObject inherited;
	
	
private:
	class DELPHICLASS TAnsiStringValue;
	class PASCALIMPLEMENTATION TAnsiStringValue : public System::TObject
	{
		typedef System::TObject inherited;
		
	public:
		unsigned Hash;
		TdxXMLSharedStrings::TAnsiStringValue* Next;
		System::AnsiString Value;
		__fastcall TAnsiStringValue(char * P, int L, unsigned AHash, System::PAnsiString AValue);
	public:
		/* TObject.Destroy */ inline __fastcall virtual ~TAnsiStringValue() { }
		
	};
	
	
	class DELPHICLASS TStringValue;
	class PASCALIMPLEMENTATION TStringValue : public System::TObject
	{
		typedef System::TObject inherited;
		
	public:
		unsigned Hash;
		TdxXMLSharedStrings::TStringValue* Next;
		System::UnicodeString Value;
		__fastcall TStringValue(System::WideChar * P, int L, unsigned AHash, System::PUnicodeString AValue);
	public:
		/* TObject.Destroy */ inline __fastcall virtual ~TStringValue() { }
		
	};
	
	
	typedef System::DynamicArray<TAnsiStringValue*> TAnsiStringValueArray;
	
	typedef System::DynamicArray<TStringValue*> TStringValueArray;
	
	
private:
	TAnsiStringValueArray FTableA;
	TStringValueArray FTableS;
	unsigned FTableSize;
	System::AnsiString __fastcall DoAdd(char * P, int L, System::PAnsiString AValue = (System::PAnsiString)(0x0))/* overload */;
	System::UnicodeString __fastcall DoAdd(System::WideChar * P, int L, System::PUnicodeString AValue = (System::PUnicodeString)(0x0))/* overload */;
	
public:
	__fastcall TdxXMLSharedStrings();
	__fastcall virtual ~TdxXMLSharedStrings();
	System::AnsiString __fastcall Add(const System::AnsiString AValue)/* overload */;
	System::UnicodeString __fastcall Add(const System::UnicodeString AValue)/* overload */;
	System::AnsiString __fastcall Add(const TdxXMLToken &AValue)/* overload */;
	void __fastcall Clear();
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxXMLParser : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	#define TdxXMLParser_CDataBegin "<![CDATA["
	
	#define TdxXMLParser_CDataEnd "]]>"
	
	#define TdxXMLParser_CommentBegin "<!--"
	
	#define TdxXMLParser_CommentEnd "-->"
	
	
public:
	#define TdxXMLParser_NameScopeDelimiter ":"
	
	
protected:
	TdxXMLDocument* FDocument;
	char *FData;
	int FDataLength;
	TdxXMLEncoding FEncoding;
	int FEncodingCodePage;
	TdxXMLSharedStrings* FSharedStrings;
	virtual System::UnicodeString __fastcall DecodeValue(const System::AnsiString S)/* overload */;
	System::UnicodeString __fastcall DecodeValue(const char * P, int ALength)/* overload */;
	bool __fastcall NextToken(/* out */ TdxXMLToken &AToken)/* overload */;
	bool __fastcall NextToken(char * &P, int &C, /* out */ TdxXMLToken &AToken)/* overload */;
	virtual void __fastcall ParseDocumentHeader();
	virtual void __fastcall ParseEncoding();
	virtual TdxXMLNode* __fastcall ParseNodeHeader(TdxXMLNode* ANode);
	virtual void __fastcall ParseNodeValue(TdxXMLNode* ANode, char * ATagHeaderEndCursor, char * ACursor);
	System::AnsiString __fastcall Share(const TdxXMLToken &AToken)/* overload */;
	System::UnicodeString __fastcall Share(const System::UnicodeString AValue)/* overload */;
	void __fastcall SkipTag();
	System::AnsiString __fastcall TokenToString(const TdxXMLToken &AToken);
	
public:
	__fastcall TdxXMLParser(TdxXMLDocument* ADocument, bool AShareStrings);
	__fastcall virtual ~TdxXMLParser();
	void __fastcall Parse(char * AScan, int ACount);
	__property TdxXMLDocument* Document = {read=FDocument};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxXMLHelper : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	__classmethod bool __fastcall GetServiceCharacter(int ACharCount, PWORD P, /* out */ int &L, /* out */ System::WideChar &C);
	__classmethod bool __fastcall IsBoolean(const System::UnicodeString S);
	__classmethod bool __fastcall IsEncodedCharacter(const System::UnicodeString S, int APosition, int ALength, /* out */ int &ACode);
	__classmethod bool __fastcall IsInvalidXmlChar(const System::Word C);
	
public:
	__classmethod TdxXMLString __fastcall ExtractNameScope(const TdxXMLString S);
	__classmethod TdxXMLString __fastcall ExtractNameWithoutNameScope(const TdxXMLString S);
	__classmethod bool __fastcall IsPreserveSpacesNeeded(const System::UnicodeString S);
	__classmethod bool __fastcall DecodeBoolean(const System::UnicodeString S);
	__classmethod System::UnicodeString __fastcall DecodeString(const System::UnicodeString S);
	__classmethod System::UnicodeString __fastcall EncodeBoolean(const bool Value);
	__classmethod System::UnicodeString __fastcall EncodeString(const System::UnicodeString S, bool ARemoveBreakLines, bool ASkipServiceCharacters = false, bool APreserveBreakLines = false);
public:
	/* TObject.Create */ inline __fastcall TdxXMLHelper() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxXMLHelper() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxXMLNodeAttribute : public Dxcoreclasses::TcxDoublyLinkedObject
{
	typedef Dxcoreclasses::TcxDoublyLinkedObject inherited;
	
private:
	TdxXMLString FName;
	System::UnicodeString FValue;
	TdxXMLString __fastcall GetValue();
	bool __fastcall GetValueAsBoolean();
	System::TDateTime __fastcall GetValueAsDateTime();
	double __fastcall GetValueAsFloat();
	__int64 __fastcall GetValueAsInt64();
	int __fastcall GetValueAsInteger();
	void __fastcall SetValue(const TdxXMLString AValue);
	void __fastcall SetValueAsBoolean(bool AValue);
	void __fastcall SetValueAsDateTime(const System::TDateTime Value);
	void __fastcall SetValueAsFloat(const double AValue);
	void __fastcall SetValueAsInt64(const __int64 Value);
	void __fastcall SetValueAsInteger(int AValue);
	
protected:
	void __fastcall Assign(TdxXMLNodeAttribute* ASource);
	void __fastcall WriteData(System::Classes::TStream* AStream);
	
public:
	__property TdxXMLString Name = {read=FName, write=FName};
	__property TdxXMLString Value = {read=GetValue, write=SetValue};
	__property bool ValueAsBoolean = {read=GetValueAsBoolean, write=SetValueAsBoolean, nodefault};
	__property System::TDateTime ValueAsDateTime = {read=GetValueAsDateTime, write=SetValueAsDateTime};
	__property double ValueAsFloat = {read=GetValueAsFloat, write=SetValueAsFloat};
	__property __int64 ValueAsInt64 = {read=GetValueAsInt64, write=SetValueAsInt64};
	__property int ValueAsInteger = {read=GetValueAsInteger, write=SetValueAsInteger, nodefault};
	__property System::UnicodeString ValueAsString = {read=FValue, write=FValue};
public:
	/* TObject.Create */ inline __fastcall TdxXMLNodeAttribute() : Dxcoreclasses::TcxDoublyLinkedObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxXMLNodeAttribute() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxXMLNodeAttributes : public Dxcoreclasses::TcxDoublyLinkedObjectList
{
	typedef Dxcoreclasses::TcxDoublyLinkedObjectList inherited;
	
private:
	TdxXMLNode* FNode;
	TdxXMLNodeAttribute* __fastcall GetFirst();
	TdxXMLNodeAttribute* __fastcall GetLast();
	
protected:
	virtual Dxcoreclasses::TcxDoublyLinkedObject* __fastcall CreateLinkedObject();
	TdxXMLNodeAttribute* __fastcall GetAttr(const TdxXMLString AAttrName);
	void __fastcall WriteData(System::Classes::TStream* AStream);
	
public:
	__fastcall TdxXMLNodeAttributes(TdxXMLNode* ANode);
	HIDESBASE TdxXMLNodeAttribute* __fastcall Add(const TdxXMLString AttrName)/* overload */;
	HIDESBASE TdxXMLNodeAttribute* __fastcall Add(const TdxXMLString AttrName, bool AValue)/* overload */;
	HIDESBASE TdxXMLNodeAttribute* __fastcall Add(const TdxXMLString AttrName, int AValue)/* overload */;
	HIDESBASE TdxXMLNodeAttribute* __fastcall Add(const TdxXMLString AttrName, const double AValue)/* overload */;
	HIDESBASE TdxXMLNodeAttribute* __fastcall Add(const TdxXMLString AttrName, const __int64 AValue)/* overload */;
	HIDESBASE TdxXMLNodeAttribute* __fastcall Add(const TdxXMLString AttrName, const System::UnicodeString AValue)/* overload */;
	HIDESBASE TdxXMLNodeAttribute* __fastcall Add(const TdxXMLString AttrName, const TdxXMLString AValue)/* overload */;
	void __fastcall Assign(TdxXMLNodeAttributes* const ASource);
	HIDESBASE void __fastcall Delete(const TdxXMLString AAttrName);
	bool __fastcall Exists(const TdxXMLString AAttrName);
	bool __fastcall Find(const TdxXMLString AAttrName, /* out */ TdxXMLNodeAttribute* &AAttr);
	TdxXMLString __fastcall GetValue(const TdxXMLString AAttrName, const TdxXMLString ADefaultValue = TdxXMLString());
	bool __fastcall GetValueAsBoolean(const TdxXMLString AAttrName, bool ADefaultValue = false);
	System::TDateTime __fastcall GetValueAsDateTime(const TdxXMLString AAttrName, const System::TDateTime ADefaultValue = 0.000000E+00)/* overload */;
	bool __fastcall GetValueAsDateTime(const TdxXMLString AAttrName, /* out */ TdxXMLDateTime &ADateTime)/* overload */;
	Dxcore::TdxDefaultBoolean __fastcall GetValueAsDefaultBoolean(const TdxXMLString AAttrName);
	double __fastcall GetValueAsFloat(const TdxXMLString AAttrName, const double ADefaultValue = 0.000000E+00);
	__int64 __fastcall GetValueAsInt64(const TdxXMLString AAttrName, const __int64 ADefaultValue = 0LL);
	int __fastcall GetValueAsInteger(const TdxXMLString AAttrName, int ADefaultValue = 0x0);
	System::UnicodeString __fastcall GetValueAsString(const TdxXMLString AAttrName, const System::UnicodeString ADefaultValue = System::UnicodeString());
	void __fastcall SetValue(const TdxXMLString AAttrName, const TdxXMLString AValue);
	void __fastcall SetValueAsBoolean(const TdxXMLString AAttrName, bool AValue);
	void __fastcall SetValueAsDefaultBoolean(const TdxXMLString AAttrName, Dxcore::TdxDefaultBoolean AValue);
	void __fastcall SetValueAsFloat(const TdxXMLString AAttrName, const double AValue);
	void __fastcall SetValueAsInt64(const TdxXMLString AAttrName, const __int64 AValue);
	void __fastcall SetValueAsInteger(const TdxXMLString AAttrName, int AValue);
	void __fastcall SetValueAsString(const TdxXMLString AAttrName, const System::UnicodeString AValue);
	void __fastcall SetValueAsDateTime(const TdxXMLString AAttrName, const System::TDateTime AValue)/* overload */;
	void __fastcall SetValueAsDateTime(const TdxXMLString AAttrName, const TdxXMLDateTime &AValue)/* overload */;
	__property TdxXMLNodeAttribute* First = {read=GetFirst};
	__property TdxXMLNodeAttribute* Last = {read=GetLast};
	__property TdxXMLNode* Node = {read=FNode};
public:
	/* TcxDoublyLinkedObjectList.Destroy */ inline __fastcall virtual ~TdxXMLNodeAttributes() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxXMLNodes : public Dxcoreclasses::TcxDoublyLinkedObjectList
{
	typedef Dxcoreclasses::TcxDoublyLinkedObjectList inherited;
	
public:
	/* TcxDoublyLinkedObjectList.Destroy */ inline __fastcall virtual ~TdxXMLNodes() { }
	
public:
	/* TObject.Create */ inline __fastcall TdxXMLNodes() : Dxcoreclasses::TcxDoublyLinkedObjectList() { }
	
};

#pragma pack(pop)

__interface TdxXMLNodeForEachProc  : public System::IInterface 
{
	virtual void __fastcall Invoke(TdxXMLNode* ANode, void * AUserData) = 0 ;
};

typedef System::TMetaClass* TdxXMLNodeClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxXMLNode : public Dxcoreclasses::TcxDoublyLinkedObject
{
	typedef Dxcoreclasses::TcxDoublyLinkedObject inherited;
	
public:
	TdxXMLNode* operator[](int Index) { return this->Items[Index]; }
	
private:
	TdxXMLNodeAttributes* FAttributes;
	TdxXMLNode* FParent;
	System::UnicodeString FText;
	System::UnicodeString __fastcall GetChildValue(const TdxXMLString AName);
	int __fastcall GetCount();
	TdxXMLNode* __fastcall GetFirst();
	bool __fastcall GetHasChildren();
	int __fastcall GetIndex();
	TdxXMLNode* __fastcall GetItem(int Index);
	int __fastcall GetLevel();
	System::UnicodeString __fastcall GetNameAsString();
	TdxXMLString __fastcall GetNameScope();
	TdxXMLString __fastcall GetNameWithoutNameScope();
	TdxXMLNode* __fastcall GetNext();
	TdxXMLString __fastcall GetText();
	bool __fastcall GetTextAsBoolean();
	System::TDateTime __fastcall GetTextAsDateTime();
	double __fastcall GetTextAsFloat();
	int __fastcall GetTextAsInteger();
	void __fastcall SetText(const TdxXMLString Value);
	void __fastcall SetTextAsBoolean(const bool Value);
	void __fastcall SetTextAsDateTime(const System::TDateTime Value);
	void __fastcall SetTextAsFloat(const double Value);
	void __fastcall SetTextAsInteger(const int Value);
	
protected:
	TdxXMLNodes* FChildren;
	TdxXMLString FName;
	virtual void __fastcall CheckTextEncoding();
	void __fastcall ChildrenNeeded();
	virtual TdxXMLNodeAttributes* __fastcall CreateAttributes();
	virtual bool __fastcall GetIsEmpty();
	virtual TdxXMLNodeClass __fastcall GetNodeClass();
	bool __fastcall HasData();
	bool __fastcall TextIsPreserveSpaceMode();
	virtual void __fastcall ReadData(System::Classes::TStream* AStream, const unsigned AVersion = (unsigned)(0x0));
	virtual void __fastcall WriteAttributes(System::Classes::TStream* AStream);
	virtual void __fastcall WriteChildren(System::Classes::TStream* AStream, bool AAutoIndent);
	virtual void __fastcall WriteContent(System::Classes::TStream* AStream, bool AAutoIndent);
	virtual void __fastcall WriteData(System::Classes::TStream* AStream, bool AAutoIndent);
	
public:
	__fastcall virtual TdxXMLNode();
	__fastcall virtual ~TdxXMLNode();
	TdxXMLNode* __fastcall AddChild(const TdxXMLString ATagName);
	void __fastcall Assign(TdxXMLNode* ASource);
	virtual void __fastcall Clear();
	bool __fastcall HasAttribute(const TdxXMLString AAttrName);
	void __fastcall SetAttribute(const TdxXMLString AttrName, const System::Variant &AValue);
	TdxXMLNode* __fastcall FindChild(const TdxXMLString AName)/* overload */;
	virtual bool __fastcall FindChild(const TdxXMLString AName, /* out */ TdxXMLNode* &ANode)/* overload */;
	bool __fastcall FindChild(const TdxXMLString *ANames, const int ANames_High, /* out */ TdxXMLNode* &ANode, bool ACanCreate = false)/* overload */;
	void __fastcall ForEach(_di_TdxXMLNodeForEachProc AProc, void * AUserData = (void *)(0x0));
	void __fastcall SortChildren(const TdxXMLString *AWithAttributes, const int AWithAttributes_High, const bool AWithSubChildren = true);
	__property TdxXMLNodeAttributes* Attributes = {read=FAttributes};
	__property TdxXMLString Name = {read=FName};
	__property System::UnicodeString NameAsString = {read=GetNameAsString};
	__property TdxXMLString NameScope = {read=GetNameScope};
	__property TdxXMLString NameWithoutNameScope = {read=GetNameWithoutNameScope};
	__property TdxXMLString Text = {read=GetText, write=SetText};
	__property bool TextAsBoolean = {read=GetTextAsBoolean, write=SetTextAsBoolean, nodefault};
	__property System::TDateTime TextAsDateTime = {read=GetTextAsDateTime, write=SetTextAsDateTime};
	__property double TextAsFloat = {read=GetTextAsFloat, write=SetTextAsFloat};
	__property int TextAsInteger = {read=GetTextAsInteger, write=SetTextAsInteger, nodefault};
	__property System::UnicodeString TextAsString = {read=FText, write=FText};
	__property System::UnicodeString ChildValues[const TdxXMLString AName] = {read=GetChildValue};
	__property int Count = {read=GetCount, nodefault};
	__property TdxXMLNode* First = {read=GetFirst};
	__property bool HasChildren = {read=GetHasChildren, nodefault};
	__property int Index = {read=GetIndex, nodefault};
	__property bool IsEmpty = {read=GetIsEmpty, nodefault};
	__property TdxXMLNode* Items[int Index] = {read=GetItem/*, default*/};
	__property int Level = {read=GetLevel, nodefault};
	__property TdxXMLNode* Next = {read=GetNext};
	__property TdxXMLNode* Parent = {read=FParent};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxXMLDocument : public Dxcoreclasses::TcxInterfacedPersistent
{
	typedef Dxcoreclasses::TcxInterfacedPersistent inherited;
	
private:
	bool FAutoIndent;
	TdxXMLString FEncoding;
	TdxXMLNode* FRoot;
	TdxXMLString FStandalone;
	TdxXMLString FVersion;
	
protected:
	virtual TdxXMLParser* __fastcall CreateParser();
	virtual TdxXMLNode* __fastcall CreateRootNode();
	virtual TdxXMLString __fastcall GetFooterText();
	virtual TdxXMLString __fastcall GetHeaderText();
	virtual void __fastcall Parse(const char * P, int ACount);
	
public:
	__fastcall virtual TdxXMLDocument(System::Classes::TPersistent* AOwner);
	__fastcall TdxXMLDocument(const System::Sysutils::TFileName AFileName);
	__fastcall virtual ~TdxXMLDocument();
	virtual void __fastcall BeginUpdate();
	virtual void __fastcall EndUpdate();
	TdxXMLNode* __fastcall AddChild(const TdxXMLString ATagName);
	bool __fastcall FindChild(const TdxXMLString AName, /* out */ TdxXMLNode* &ANode)/* overload */;
	TdxXMLNode* __fastcall FindChild(const TdxXMLString *ANames, const int ANames_High)/* overload */;
	bool __fastcall FindChild(const TdxXMLString *ANames, const int ANames_High, /* out */ TdxXMLNode* &ANode)/* overload */;
	void __fastcall ForEach(const TdxXMLString *ANames, const int ANames_High, _di_TdxXMLNodeForEachProc AProc, void * AUserData = (void *)(0x0));
	void __fastcall LoadFromFile(const System::Sysutils::TFileName AFileName);
	void __fastcall LoadFromResource(NativeUInt AInstance, const System::UnicodeString AResName, System::WideChar * AResType);
	void __fastcall LoadFromStream(System::Classes::TStream* AStream);
	void __fastcall LoadFromString(const System::AnsiString AString);
	void __fastcall SaveToFile(const System::Sysutils::TFileName AFileName);
	void __fastcall SaveToStream(System::Classes::TStream* AStream);
	void __fastcall SortChildren(const TdxXMLString *AWithAttributes, const int AWithAttributes_High, const bool AWithSubChildren = true);
	__property bool AutoIndent = {read=FAutoIndent, write=FAutoIndent, nodefault};
	__property TdxXMLString Encoding = {read=FEncoding, write=FEncoding};
	__property TdxXMLNode* Root = {read=FRoot};
	__property TdxXMLString Standalone = {read=FStandalone, write=FStandalone};
	__property TdxXMLString Version = {read=FVersion, write=FVersion};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxXMLPackableNode : public TdxXMLNode
{
	typedef TdxXMLNode inherited;
	
private:
	System::Classes::TMemoryStream* FPackedData;
	
protected:
	void __fastcall CheckPacked();
	virtual TdxXMLNodeAttributes* __fastcall CreateAttributes();
	virtual bool __fastcall GetIsEmpty();
	virtual TdxXMLNodeClass __fastcall GetNodeClass();
	virtual void __fastcall WriteData(System::Classes::TStream* AStream, bool AAutoIndent);
	
public:
	__fastcall virtual ~TdxXMLPackableNode();
	HIDESBASE TdxXMLPackableNode* __fastcall AddChild(const TdxXMLString ATagName);
	HIDESBASE bool __fastcall FindChild(const TdxXMLString AName, /* out */ TdxXMLPackableNode* &ANode)/* overload */;
	HIDESBASE TdxXMLPackableNode* __fastcall FindChild(const TdxXMLString *ANames, const int ANames_High)/* overload */;
	HIDESBASE bool __fastcall FindChild(const TdxXMLString *ANames, const int ANames_High, /* out */ TdxXMLPackableNode* &ANode)/* overload */;
	void __fastcall Pack();
public:
	/* TdxXMLNode.Create */ inline __fastcall virtual TdxXMLPackableNode() : TdxXMLNode() { }
	
	/* Hoisted overloads: */
	
public:
	inline TdxXMLNode* __fastcall  FindChild(const TdxXMLString AName){ return TdxXMLNode::FindChild(AName); }
	inline bool __fastcall  FindChild(const TdxXMLString AName, /* out */ TdxXMLNode* &ANode){ return TdxXMLNode::FindChild(AName, ANode); }
	inline bool __fastcall  FindChild(const TdxXMLString *ANames, const int ANames_High, /* out */ TdxXMLNode* &ANode, bool ACanCreate = false){ return TdxXMLNode::FindChild(ANames, ANames_High, ANode, ACanCreate); }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxXMLPackableNodeAttributes : public TdxXMLNodeAttributes
{
	typedef TdxXMLNodeAttributes inherited;
	
public:
	virtual Dxcoreclasses::TcxDoublyLinkedObject* __fastcall Add();
public:
	/* TdxXMLNodeAttributes.Create */ inline __fastcall TdxXMLPackableNodeAttributes(TdxXMLNode* ANode) : TdxXMLNodeAttributes(ANode) { }
	
public:
	/* TcxDoublyLinkedObjectList.Destroy */ inline __fastcall virtual ~TdxXMLPackableNodeAttributes() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxXMLPackableDocument : public TdxXMLDocument
{
	typedef TdxXMLDocument inherited;
	
private:
	TdxXMLPackableNode* __fastcall GetRoot();
	
protected:
	virtual TdxXMLNode* __fastcall CreateRootNode();
	
public:
	__property TdxXMLPackableNode* Root = {read=GetRoot};
public:
	/* TdxXMLDocument.Create */ inline __fastcall virtual TdxXMLPackableDocument(System::Classes::TPersistent* AOwner) : TdxXMLDocument(AOwner) { }
	/* TdxXMLDocument.CreateEx */ inline __fastcall TdxXMLPackableDocument(const System::Sysutils::TFileName AFileName) : TdxXMLDocument(AFileName) { }
	/* TdxXMLDocument.Destroy */ inline __fastcall virtual ~TdxXMLPackableDocument() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE TdxXMLString __fastcall dxStringToXMLString(const System::UnicodeString AValue);
extern DELPHI_PACKAGE System::UnicodeString __fastcall dxXMLStringToString(const TdxXMLString AValue);
}	/* namespace Dxxmldoc */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXXMLDOC)
using namespace Dxxmldoc;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxxmldocHPP
