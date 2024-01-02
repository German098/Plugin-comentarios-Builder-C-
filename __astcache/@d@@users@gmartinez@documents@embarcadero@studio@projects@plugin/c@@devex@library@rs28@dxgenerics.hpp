// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxGenerics.pas' rev: 35.00 (Windows)

#ifndef DxgenericsHPP
#define DxgenericsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.UITypes.hpp>
#include <System.TypInfo.hpp>
#include <System.Types.hpp>
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <Vcl.Graphics.hpp>
#include <System.Generics.Defaults.hpp>
#include <System.Generics.Collections.hpp>
#include <System.Contnrs.hpp>
#include <dxCore.hpp>
#include <dxCoreClasses.hpp>
#include <dxCoreGraphics.hpp>

//-- user supplied -----------------------------------------------------------

namespace Dxgenerics
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TdxCharStringDictionary;
class DELPHICLASS TdxIntegersDictionary;
class DELPHICLASS TdxStringsDictionary;
class DELPHICLASS TdxStringColorDictionary;
class DELPHICLASS TdxStringIntegerDictionary;
class DELPHICLASS TdxCharList;
class DELPHICLASS TdxObjectIntegerDictionary;
class DELPHICLASS TdxObjectDictionary;
template<typename T> __interface DELPHIINTERFACE TdxListMaxIntegerAction__1;
#ifdef __clang__
template<typename T> using _di_TdxListMaxIntegerAction__1 = System::DelphiInterface<TdxListMaxIntegerAction__1<T>>;
#endif
class DELPHICLASS TdxStringList;
template<typename T> class DELPHICLASS TdxList__1;
template<typename T> class DELPHICLASS TdxNotificationCollection__1;
template<typename T> class DELPHICLASS TdxObjectList__1;
template<typename T> class DELPHICLASS TdxNotificationObjectCollection__1;
class DELPHICLASS TdxOrdinalHelper;
class DELPHICLASS TdxStringToOrdinalMap;
class DELPHICLASS TdxNamedOrdinalDictionary;
template<typename T> class DELPHICLASS TdxNamedOrdinalDictionary__1;
class DELPHICLASS TdxStringBooleanDictionary;
template<typename T> class DELPHICLASS TdxNamedObjectDictionary__1;
template<typename TValue> class DELPHICLASS TdxNamedDelegateDictionary__1;
template<typename TValue> class DELPHICLASS TdxEnumeratedMap__1;
template<typename TValue> class DELPHICLASS TdxEnumeratedDictionary__1;
template<typename TEnumeration, typename TValue> class DELPHICLASS TdxEnumeratedDictionary__2;
template<typename TEnumeration, typename TValue> class DELPHICLASS TdxEnumeratedObjectDictionary__2;
class DELPHICLASS TdxOrdinalList;
template<typename T> class DELPHICLASS TdxOrdinalList__1;
class DELPHICLASS TdxAlphaColorList;
class DELPHICLASS TdxColorList;
class DELPHICLASS TdxIntegerList;
template<typename T> class DELPHICLASS TdxObjectStack__1;
class DELPHICLASS TdxIntegerStack;
__interface DELPHIINTERFACE TdxTopologicalSorterIsDependOnDelegate;
typedef System::DelphiInterface<TdxTopologicalSorterIsDependOnDelegate> _di_TdxTopologicalSorterIsDependOnDelegate;
class DELPHICLASS TdxTopologicalSorterNode;
template<typename T> class DELPHICLASS TdxTopologicalSorter__1;
template<typename T> class DELPHICLASS TdxComparer__1;
template<typename T> __interface DELPHIINTERFACE IdxComparable__1;
#ifdef __clang__
template<typename T> using _di_IdxComparable__1 = System::DelphiInterface<IdxComparable__1<T>>;
#endif
template<typename T> class DELPHICLASS TdxDefaultComparable__1;
template<typename T> __interface DELPHIINTERFACE TdxComparableFunc__1;
#ifdef __clang__
template<typename T> using _di_TdxComparableFunc__1 = System::DelphiInterface<TdxComparableFunc__1<T>>;
#endif
template<typename T> class DELPHICLASS TdxAlgorithms__1;
template<typename T> class DELPHICLASS TdxAlgorithms1__1;
template<typename T> class DELPHICLASS TdxSortedList__1;
template<typename T> class DELPHICLASS TdxObjectSortedList__1;
class DELPHICLASS TdxLayoutUnitSortedList;
template<typename T> class DELPHICLASS TdxHashSet__1;
template<typename T> struct TdxSmartPointer__1;
template<typename TKey, typename TValue> class DELPHICLASS TdxMap__2;
template<typename T> class DELPHICLASS TdxClassDictionary__1;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TdxCharStringDictionary : public System::Generics::Collections::TDictionary__2<System::WideChar,System::UnicodeString>
{
	typedef System::Generics::Collections::TDictionary__2<System::WideChar,System::UnicodeString> inherited;
	
public:
	/* {System_Generics_Collections}TDictionary<System_Char,System_string>.Create */ inline __fastcall TdxCharStringDictionary()/* overload */ : System::Generics::Collections::TDictionary__2<System::WideChar,System::UnicodeString>() { }
	/* {System_Generics_Collections}TDictionary<System_Char,System_string>.Create */ inline __fastcall TdxCharStringDictionary(int ACapacity)/* overload */ : System::Generics::Collections::TDictionary__2<System::WideChar,System::UnicodeString>(ACapacity) { }
	/* {System_Generics_Collections}TDictionary<System_Char,System_string>.Create */ inline __fastcall TdxCharStringDictionary(const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<System::WideChar> > AComparer)/* overload */ : System::Generics::Collections::TDictionary__2<System::WideChar,System::UnicodeString>(AComparer) { }
	/* {System_Generics_Collections}TDictionary<System_Char,System_string>.Create */ inline __fastcall TdxCharStringDictionary(int ACapacity, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<System::WideChar> > AComparer)/* overload */ : System::Generics::Collections::TDictionary__2<System::WideChar,System::UnicodeString>(ACapacity, AComparer) { }
	/* {System_Generics_Collections}TDictionary<System_Char,System_string>.Create */ inline __fastcall TdxCharStringDictionary(System::Generics::Collections::TEnumerable__1<System::Generics::Collections::TPair__2<System::WideChar,System::UnicodeString> >* const Collection)/* overload */ : System::Generics::Collections::TDictionary__2<System::WideChar,System::UnicodeString>(Collection) { }
	/* {System_Generics_Collections}TDictionary<System_Char,System_string>.Create */ inline __fastcall TdxCharStringDictionary(System::Generics::Collections::TEnumerable__1<System::Generics::Collections::TPair__2<System::WideChar,System::UnicodeString> >* const Collection, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<System::WideChar> > AComparer)/* overload */ : System::Generics::Collections::TDictionary__2<System::WideChar,System::UnicodeString>(Collection, AComparer) { }
	/* {System_Generics_Collections}TDictionary<System_Char,System_string>.Create */ inline __fastcall TdxCharStringDictionary(const System::Generics::Collections::TPair__2<System::WideChar,System::UnicodeString> *AItems, const int AItems_High)/* overload */ : System::Generics::Collections::TDictionary__2<System::WideChar,System::UnicodeString>(AItems, AItems_High) { }
	/* {System_Generics_Collections}TDictionary<System_Char,System_string>.Create */ inline __fastcall TdxCharStringDictionary(const System::Generics::Collections::TPair__2<System::WideChar,System::UnicodeString> *AItems, const int AItems_High, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<System::WideChar> > AComparer)/* overload */ : System::Generics::Collections::TDictionary__2<System::WideChar,System::UnicodeString>(AItems, AItems_High, AComparer) { }
	/* {System_Generics_Collections}TDictionary<System_Char,System_string>.Destroy */ inline __fastcall virtual ~TdxCharStringDictionary() { }
	
};


class PASCALIMPLEMENTATION TdxIntegersDictionary : public System::Generics::Collections::TDictionary__2<int,int>
{
	typedef System::Generics::Collections::TDictionary__2<int,int> inherited;
	
public:
	/* {System_Generics_Collections}TDictionary<System_Integer,System_Integer>.Create */ inline __fastcall TdxIntegersDictionary()/* overload */ : System::Generics::Collections::TDictionary__2<int,int>() { }
	/* {System_Generics_Collections}TDictionary<System_Integer,System_Integer>.Create */ inline __fastcall TdxIntegersDictionary(int ACapacity)/* overload */ : System::Generics::Collections::TDictionary__2<int,int>(ACapacity) { }
	/* {System_Generics_Collections}TDictionary<System_Integer,System_Integer>.Create */ inline __fastcall TdxIntegersDictionary(const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<int> > AComparer)/* overload */ : System::Generics::Collections::TDictionary__2<int,int>(AComparer) { }
	/* {System_Generics_Collections}TDictionary<System_Integer,System_Integer>.Create */ inline __fastcall TdxIntegersDictionary(int ACapacity, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<int> > AComparer)/* overload */ : System::Generics::Collections::TDictionary__2<int,int>(ACapacity, AComparer) { }
	/* {System_Generics_Collections}TDictionary<System_Integer,System_Integer>.Create */ inline __fastcall TdxIntegersDictionary(System::Generics::Collections::TEnumerable__1<System::Generics::Collections::TPair__2<int,int> >* const Collection)/* overload */ : System::Generics::Collections::TDictionary__2<int,int>(Collection) { }
	/* {System_Generics_Collections}TDictionary<System_Integer,System_Integer>.Create */ inline __fastcall TdxIntegersDictionary(System::Generics::Collections::TEnumerable__1<System::Generics::Collections::TPair__2<int,int> >* const Collection, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<int> > AComparer)/* overload */ : System::Generics::Collections::TDictionary__2<int,int>(Collection, AComparer) { }
	/* {System_Generics_Collections}TDictionary<System_Integer,System_Integer>.Create */ inline __fastcall TdxIntegersDictionary(const System::Generics::Collections::TPair__2<int,int> *AItems, const int AItems_High)/* overload */ : System::Generics::Collections::TDictionary__2<int,int>(AItems, AItems_High) { }
	/* {System_Generics_Collections}TDictionary<System_Integer,System_Integer>.Create */ inline __fastcall TdxIntegersDictionary(const System::Generics::Collections::TPair__2<int,int> *AItems, const int AItems_High, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<int> > AComparer)/* overload */ : System::Generics::Collections::TDictionary__2<int,int>(AItems, AItems_High, AComparer) { }
	/* {System_Generics_Collections}TDictionary<System_Integer,System_Integer>.Destroy */ inline __fastcall virtual ~TdxIntegersDictionary() { }
	
};


typedef System::Generics::Collections::TPair__2<int,int> TdxIntegersPair;

class PASCALIMPLEMENTATION TdxStringsDictionary : public System::Generics::Collections::TDictionary__2<System::UnicodeString,System::UnicodeString>
{
	typedef System::Generics::Collections::TDictionary__2<System::UnicodeString,System::UnicodeString> inherited;
	
public:
	/* {System_Generics_Collections}TDictionary<System_string,System_string>.Create */ inline __fastcall TdxStringsDictionary()/* overload */ : System::Generics::Collections::TDictionary__2<System::UnicodeString,System::UnicodeString>() { }
	/* {System_Generics_Collections}TDictionary<System_string,System_string>.Create */ inline __fastcall TdxStringsDictionary(int ACapacity)/* overload */ : System::Generics::Collections::TDictionary__2<System::UnicodeString,System::UnicodeString>(ACapacity) { }
	/* {System_Generics_Collections}TDictionary<System_string,System_string>.Create */ inline __fastcall TdxStringsDictionary(const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<System::UnicodeString> > AComparer)/* overload */ : System::Generics::Collections::TDictionary__2<System::UnicodeString,System::UnicodeString>(AComparer) { }
	/* {System_Generics_Collections}TDictionary<System_string,System_string>.Create */ inline __fastcall TdxStringsDictionary(int ACapacity, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<System::UnicodeString> > AComparer)/* overload */ : System::Generics::Collections::TDictionary__2<System::UnicodeString,System::UnicodeString>(ACapacity, AComparer) { }
	/* {System_Generics_Collections}TDictionary<System_string,System_string>.Create */ inline __fastcall TdxStringsDictionary(System::Generics::Collections::TEnumerable__1<System::Generics::Collections::TPair__2<System::UnicodeString,System::UnicodeString> >* const Collection)/* overload */ : System::Generics::Collections::TDictionary__2<System::UnicodeString,System::UnicodeString>(Collection) { }
	/* {System_Generics_Collections}TDictionary<System_string,System_string>.Create */ inline __fastcall TdxStringsDictionary(System::Generics::Collections::TEnumerable__1<System::Generics::Collections::TPair__2<System::UnicodeString,System::UnicodeString> >* const Collection, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<System::UnicodeString> > AComparer)/* overload */ : System::Generics::Collections::TDictionary__2<System::UnicodeString,System::UnicodeString>(Collection, AComparer) { }
	/* {System_Generics_Collections}TDictionary<System_string,System_string>.Create */ inline __fastcall TdxStringsDictionary(const System::Generics::Collections::TPair__2<System::UnicodeString,System::UnicodeString> *AItems, const int AItems_High)/* overload */ : System::Generics::Collections::TDictionary__2<System::UnicodeString,System::UnicodeString>(AItems, AItems_High) { }
	/* {System_Generics_Collections}TDictionary<System_string,System_string>.Create */ inline __fastcall TdxStringsDictionary(const System::Generics::Collections::TPair__2<System::UnicodeString,System::UnicodeString> *AItems, const int AItems_High, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<System::UnicodeString> > AComparer)/* overload */ : System::Generics::Collections::TDictionary__2<System::UnicodeString,System::UnicodeString>(AItems, AItems_High, AComparer) { }
	/* {System_Generics_Collections}TDictionary<System_string,System_string>.Destroy */ inline __fastcall virtual ~TdxStringsDictionary() { }
	
};


class PASCALIMPLEMENTATION TdxStringColorDictionary : public System::Generics::Collections::TDictionary__2<System::UnicodeString,Dxcoregraphics::TdxAlphaColor>
{
	typedef System::Generics::Collections::TDictionary__2<System::UnicodeString,Dxcoregraphics::TdxAlphaColor> inherited;
	
public:
	/* {System_Generics_Collections}TDictionary<System_string,dxCoreGraphics_TdxAlphaColor>.Create */ inline __fastcall TdxStringColorDictionary()/* overload */ : System::Generics::Collections::TDictionary__2<System::UnicodeString,Dxcoregraphics::TdxAlphaColor>() { }
	/* {System_Generics_Collections}TDictionary<System_string,dxCoreGraphics_TdxAlphaColor>.Create */ inline __fastcall TdxStringColorDictionary(int ACapacity)/* overload */ : System::Generics::Collections::TDictionary__2<System::UnicodeString,Dxcoregraphics::TdxAlphaColor>(ACapacity) { }
	/* {System_Generics_Collections}TDictionary<System_string,dxCoreGraphics_TdxAlphaColor>.Create */ inline __fastcall TdxStringColorDictionary(const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<System::UnicodeString> > AComparer)/* overload */ : System::Generics::Collections::TDictionary__2<System::UnicodeString,Dxcoregraphics::TdxAlphaColor>(AComparer) { }
	/* {System_Generics_Collections}TDictionary<System_string,dxCoreGraphics_TdxAlphaColor>.Create */ inline __fastcall TdxStringColorDictionary(int ACapacity, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<System::UnicodeString> > AComparer)/* overload */ : System::Generics::Collections::TDictionary__2<System::UnicodeString,Dxcoregraphics::TdxAlphaColor>(ACapacity, AComparer) { }
	/* {System_Generics_Collections}TDictionary<System_string,dxCoreGraphics_TdxAlphaColor>.Create */ inline __fastcall TdxStringColorDictionary(System::Generics::Collections::TEnumerable__1<System::Generics::Collections::TPair__2<System::UnicodeString,Dxcoregraphics::TdxAlphaColor> >* const Collection)/* overload */ : System::Generics::Collections::TDictionary__2<System::UnicodeString,Dxcoregraphics::TdxAlphaColor>(Collection) { }
	/* {System_Generics_Collections}TDictionary<System_string,dxCoreGraphics_TdxAlphaColor>.Create */ inline __fastcall TdxStringColorDictionary(System::Generics::Collections::TEnumerable__1<System::Generics::Collections::TPair__2<System::UnicodeString,Dxcoregraphics::TdxAlphaColor> >* const Collection, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<System::UnicodeString> > AComparer)/* overload */ : System::Generics::Collections::TDictionary__2<System::UnicodeString,Dxcoregraphics::TdxAlphaColor>(Collection, AComparer) { }
	/* {System_Generics_Collections}TDictionary<System_string,dxCoreGraphics_TdxAlphaColor>.Create */ inline __fastcall TdxStringColorDictionary(const System::Generics::Collections::TPair__2<System::UnicodeString,Dxcoregraphics::TdxAlphaColor> *AItems, const int AItems_High)/* overload */ : System::Generics::Collections::TDictionary__2<System::UnicodeString,Dxcoregraphics::TdxAlphaColor>(AItems, AItems_High) { }
	/* {System_Generics_Collections}TDictionary<System_string,dxCoreGraphics_TdxAlphaColor>.Create */ inline __fastcall TdxStringColorDictionary(const System::Generics::Collections::TPair__2<System::UnicodeString,Dxcoregraphics::TdxAlphaColor> *AItems, const int AItems_High, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<System::UnicodeString> > AComparer)/* overload */ : System::Generics::Collections::TDictionary__2<System::UnicodeString,Dxcoregraphics::TdxAlphaColor>(AItems, AItems_High, AComparer) { }
	/* {System_Generics_Collections}TDictionary<System_string,dxCoreGraphics_TdxAlphaColor>.Destroy */ inline __fastcall virtual ~TdxStringColorDictionary() { }
	
};


class PASCALIMPLEMENTATION TdxStringIntegerDictionary : public System::Generics::Collections::TDictionary__2<System::UnicodeString,int>
{
	typedef System::Generics::Collections::TDictionary__2<System::UnicodeString,int> inherited;
	
public:
	/* {System_Generics_Collections}TDictionary<System_string,System_Integer>.Create */ inline __fastcall TdxStringIntegerDictionary()/* overload */ : System::Generics::Collections::TDictionary__2<System::UnicodeString,int>() { }
	/* {System_Generics_Collections}TDictionary<System_string,System_Integer>.Create */ inline __fastcall TdxStringIntegerDictionary(int ACapacity)/* overload */ : System::Generics::Collections::TDictionary__2<System::UnicodeString,int>(ACapacity) { }
	/* {System_Generics_Collections}TDictionary<System_string,System_Integer>.Create */ inline __fastcall TdxStringIntegerDictionary(const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<System::UnicodeString> > AComparer)/* overload */ : System::Generics::Collections::TDictionary__2<System::UnicodeString,int>(AComparer) { }
	/* {System_Generics_Collections}TDictionary<System_string,System_Integer>.Create */ inline __fastcall TdxStringIntegerDictionary(int ACapacity, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<System::UnicodeString> > AComparer)/* overload */ : System::Generics::Collections::TDictionary__2<System::UnicodeString,int>(ACapacity, AComparer) { }
	/* {System_Generics_Collections}TDictionary<System_string,System_Integer>.Create */ inline __fastcall TdxStringIntegerDictionary(System::Generics::Collections::TEnumerable__1<System::Generics::Collections::TPair__2<System::UnicodeString,int> >* const Collection)/* overload */ : System::Generics::Collections::TDictionary__2<System::UnicodeString,int>(Collection) { }
	/* {System_Generics_Collections}TDictionary<System_string,System_Integer>.Create */ inline __fastcall TdxStringIntegerDictionary(System::Generics::Collections::TEnumerable__1<System::Generics::Collections::TPair__2<System::UnicodeString,int> >* const Collection, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<System::UnicodeString> > AComparer)/* overload */ : System::Generics::Collections::TDictionary__2<System::UnicodeString,int>(Collection, AComparer) { }
	/* {System_Generics_Collections}TDictionary<System_string,System_Integer>.Create */ inline __fastcall TdxStringIntegerDictionary(const System::Generics::Collections::TPair__2<System::UnicodeString,int> *AItems, const int AItems_High)/* overload */ : System::Generics::Collections::TDictionary__2<System::UnicodeString,int>(AItems, AItems_High) { }
	/* {System_Generics_Collections}TDictionary<System_string,System_Integer>.Create */ inline __fastcall TdxStringIntegerDictionary(const System::Generics::Collections::TPair__2<System::UnicodeString,int> *AItems, const int AItems_High, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<System::UnicodeString> > AComparer)/* overload */ : System::Generics::Collections::TDictionary__2<System::UnicodeString,int>(AItems, AItems_High, AComparer) { }
	/* {System_Generics_Collections}TDictionary<System_string,System_Integer>.Destroy */ inline __fastcall virtual ~TdxStringIntegerDictionary() { }
	
};


class PASCALIMPLEMENTATION TdxCharList : public System::Generics::Collections::TList__1<System::WideChar>
{
	typedef System::Generics::Collections::TList__1<System::WideChar> inherited;
	
public:
	/* {System_Generics_Collections}TList<System_Char>.Create */ inline __fastcall TdxCharList()/* overload */ : System::Generics::Collections::TList__1<System::WideChar>() { }
	/* {System_Generics_Collections}TList<System_Char>.Create */ inline __fastcall TdxCharList(const System::DelphiInterface<System::Generics::Defaults::IComparer__1<System::WideChar> > AComparer)/* overload */ : System::Generics::Collections::TList__1<System::WideChar>(AComparer) { }
	/* {System_Generics_Collections}TList<System_Char>.Create */ inline __fastcall TdxCharList(System::Generics::Collections::TEnumerable__1<System::WideChar>* const Collection)/* overload */ : System::Generics::Collections::TList__1<System::WideChar>(Collection) { }
	/* {System_Generics_Collections}TList<System_Char>.Create */ inline __fastcall TdxCharList(const System::WideChar *Values, const int Values_High)/* overload */ : System::Generics::Collections::TList__1<System::WideChar>(Values, Values_High) { }
	/* {System_Generics_Collections}TList<System_Char>.Destroy */ inline __fastcall virtual ~TdxCharList() { }
	
};


class PASCALIMPLEMENTATION TdxObjectIntegerDictionary : public System::Generics::Collections::TDictionary__2<System::TObject*,int>
{
	typedef System::Generics::Collections::TDictionary__2<System::TObject*,int> inherited;
	
public:
	/* {System_Generics_Collections}TDictionary<System_TObject,System_Integer>.Create */ inline __fastcall TdxObjectIntegerDictionary()/* overload */ : System::Generics::Collections::TDictionary__2<System::TObject*,int>() { }
	/* {System_Generics_Collections}TDictionary<System_TObject,System_Integer>.Create */ inline __fastcall TdxObjectIntegerDictionary(int ACapacity)/* overload */ : System::Generics::Collections::TDictionary__2<System::TObject*,int>(ACapacity) { }
	/* {System_Generics_Collections}TDictionary<System_TObject,System_Integer>.Create */ inline __fastcall TdxObjectIntegerDictionary(const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<System::TObject*> > AComparer)/* overload */ : System::Generics::Collections::TDictionary__2<System::TObject*,int>(AComparer) { }
	/* {System_Generics_Collections}TDictionary<System_TObject,System_Integer>.Create */ inline __fastcall TdxObjectIntegerDictionary(int ACapacity, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<System::TObject*> > AComparer)/* overload */ : System::Generics::Collections::TDictionary__2<System::TObject*,int>(ACapacity, AComparer) { }
	/* {System_Generics_Collections}TDictionary<System_TObject,System_Integer>.Create */ inline __fastcall TdxObjectIntegerDictionary(System::Generics::Collections::TEnumerable__1<System::Generics::Collections::TPair__2<System::TObject*,int> >* const Collection)/* overload */ : System::Generics::Collections::TDictionary__2<System::TObject*,int>(Collection) { }
	/* {System_Generics_Collections}TDictionary<System_TObject,System_Integer>.Create */ inline __fastcall TdxObjectIntegerDictionary(System::Generics::Collections::TEnumerable__1<System::Generics::Collections::TPair__2<System::TObject*,int> >* const Collection, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<System::TObject*> > AComparer)/* overload */ : System::Generics::Collections::TDictionary__2<System::TObject*,int>(Collection, AComparer) { }
	/* {System_Generics_Collections}TDictionary<System_TObject,System_Integer>.Create */ inline __fastcall TdxObjectIntegerDictionary(const System::Generics::Collections::TPair__2<System::TObject*,int> *AItems, const int AItems_High)/* overload */ : System::Generics::Collections::TDictionary__2<System::TObject*,int>(AItems, AItems_High) { }
	/* {System_Generics_Collections}TDictionary<System_TObject,System_Integer>.Create */ inline __fastcall TdxObjectIntegerDictionary(const System::Generics::Collections::TPair__2<System::TObject*,int> *AItems, const int AItems_High, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<System::TObject*> > AComparer)/* overload */ : System::Generics::Collections::TDictionary__2<System::TObject*,int>(AItems, AItems_High, AComparer) { }
	/* {System_Generics_Collections}TDictionary<System_TObject,System_Integer>.Destroy */ inline __fastcall virtual ~TdxObjectIntegerDictionary() { }
	
};


class PASCALIMPLEMENTATION TdxObjectDictionary : public System::Generics::Collections::TObjectDictionary__2<System::TObject*,System::TObject*>
{
	typedef System::Generics::Collections::TObjectDictionary__2<System::TObject*,System::TObject*> inherited;
	
public:
	/* {System_Generics_Collections}TObjectDictionary<System_TObject,System_TObject>.Create */ inline __fastcall TdxObjectDictionary(System::Generics::Collections::TDictionaryOwnerships Ownerships, int ACapacity)/* overload */ : System::Generics::Collections::TObjectDictionary__2<System::TObject*,System::TObject*>(Ownerships, ACapacity) { }
	/* {System_Generics_Collections}TObjectDictionary<System_TObject,System_TObject>.Create */ inline __fastcall TdxObjectDictionary(System::Generics::Collections::TDictionaryOwnerships Ownerships, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<System::TObject*> > AComparer)/* overload */ : System::Generics::Collections::TObjectDictionary__2<System::TObject*,System::TObject*>(Ownerships, AComparer) { }
	/* {System_Generics_Collections}TObjectDictionary<System_TObject,System_TObject>.Create */ inline __fastcall TdxObjectDictionary(System::Generics::Collections::TDictionaryOwnerships Ownerships, int ACapacity, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<System::TObject*> > AComparer)/* overload */ : System::Generics::Collections::TObjectDictionary__2<System::TObject*,System::TObject*>(Ownerships, ACapacity, AComparer) { }
	
public:
	/* {System_Generics_Collections}TDictionary<System_TObject,System_TObject>.Create */ inline __fastcall TdxObjectDictionary()/* overload */ : System::Generics::Collections::TObjectDictionary__2<System::TObject*,System::TObject*>() { }
	/* {System_Generics_Collections}TDictionary<System_TObject,System_TObject>.Create */ inline __fastcall TdxObjectDictionary(int ACapacity)/* overload */ : System::Generics::Collections::TObjectDictionary__2<System::TObject*,System::TObject*>(ACapacity) { }
	/* {System_Generics_Collections}TDictionary<System_TObject,System_TObject>.Create */ inline __fastcall TdxObjectDictionary(const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<System::TObject*> > AComparer)/* overload */ : System::Generics::Collections::TObjectDictionary__2<System::TObject*,System::TObject*>(AComparer) { }
	/* {System_Generics_Collections}TDictionary<System_TObject,System_TObject>.Create */ inline __fastcall TdxObjectDictionary(int ACapacity, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<System::TObject*> > AComparer)/* overload */ : System::Generics::Collections::TObjectDictionary__2<System::TObject*,System::TObject*>(ACapacity, AComparer) { }
	/* {System_Generics_Collections}TDictionary<System_TObject,System_TObject>.Create */ inline __fastcall TdxObjectDictionary(System::Generics::Collections::TEnumerable__1<System::Generics::Collections::TPair__2<System::TObject*,System::TObject*> >* const Collection)/* overload */ : System::Generics::Collections::TObjectDictionary__2<System::TObject*,System::TObject*>(Collection) { }
	/* {System_Generics_Collections}TDictionary<System_TObject,System_TObject>.Create */ inline __fastcall TdxObjectDictionary(System::Generics::Collections::TEnumerable__1<System::Generics::Collections::TPair__2<System::TObject*,System::TObject*> >* const Collection, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<System::TObject*> > AComparer)/* overload */ : System::Generics::Collections::TObjectDictionary__2<System::TObject*,System::TObject*>(Collection, AComparer) { }
	/* {System_Generics_Collections}TDictionary<System_TObject,System_TObject>.Create */ inline __fastcall TdxObjectDictionary(const System::Generics::Collections::TPair__2<System::TObject*,System::TObject*> *AItems, const int AItems_High)/* overload */ : System::Generics::Collections::TObjectDictionary__2<System::TObject*,System::TObject*>(AItems, AItems_High) { }
	/* {System_Generics_Collections}TDictionary<System_TObject,System_TObject>.Create */ inline __fastcall TdxObjectDictionary(const System::Generics::Collections::TPair__2<System::TObject*,System::TObject*> *AItems, const int AItems_High, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<System::TObject*> > AComparer)/* overload */ : System::Generics::Collections::TObjectDictionary__2<System::TObject*,System::TObject*>(AItems, AItems_High, AComparer) { }
	/* {System_Generics_Collections}TDictionary<System_TObject,System_TObject>.Destroy */ inline __fastcall virtual ~TdxObjectDictionary() { }
	
};


// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename T> __interface TdxListMaxIntegerAction__1  : public System::IInterface 
{
	virtual int __fastcall Invoke(const T AItem) = 0 ;
};

class PASCALIMPLEMENTATION TdxStringList : public System::Classes::TStringList
{
	typedef System::Classes::TStringList inherited;
	
public:
	void __fastcall AddRange(System::Classes::TStrings* const Values)/* overload */;
	void __fastcall AddRange(const System::DynamicArray<System::UnicodeString> Values)/* overload */;
	bool __fastcall Contains(const System::UnicodeString Value);
	void __fastcall DeleteRange(int AIndex, int ACount);
	void __fastcall InsertRange(int Index, System::Classes::TStrings* const Values)/* overload */;
	void __fastcall InsertRange(int Index, const System::DynamicArray<System::UnicodeString> Values)/* overload */;
	int __fastcall Remove(const System::UnicodeString Value);
	System::DynamicArray<System::UnicodeString> __fastcall ToArray();
public:
	/* TStringList.Create */ inline __fastcall TdxStringList()/* overload */ : System::Classes::TStringList() { }
	/* TStringList.Create */ inline __fastcall TdxStringList(bool OwnsObjects)/* overload */ : System::Classes::TStringList(OwnsObjects) { }
	/* TStringList.Create */ inline __fastcall TdxStringList(System::WideChar QuoteChar, System::WideChar Delimiter)/* overload */ : System::Classes::TStringList(QuoteChar, Delimiter) { }
	/* TStringList.Create */ inline __fastcall TdxStringList(System::WideChar QuoteChar, System::WideChar Delimiter, System::Classes::TStringsOptions Options)/* overload */ : System::Classes::TStringList(QuoteChar, Delimiter, Options) { }
	/* TStringList.Create */ inline __fastcall TdxStringList(System::Types::TDuplicates Duplicates, bool Sorted, bool CaseSensitive)/* overload */ : System::Classes::TStringList(Duplicates, Sorted, CaseSensitive) { }
	/* TStringList.Destroy */ inline __fastcall virtual ~TdxStringList() { }
	
};


#pragma pack(push,4)
// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename T> class PASCALIMPLEMENTATION TdxList__1 : public System::Contnrs::TObjectList
{
	typedef System::Contnrs::TObjectList inherited;
	
public:
	T operator[](int Index) { return this->Items[Index]; }
	
private:
	HIDESBASE T __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, const T Value);
	
public:
	__fastcall TdxList__1()/* overload */;
	__fastcall TdxList__1(bool AOwnsObjects)/* overload */;
	void __fastcall AddRange(TdxList__1<T>* const Collection)/* overload */;
	void __fastcall AddRange(const T *Collection, const int Collection_High)/* overload */;
	bool __fastcall BinarySearch(const T Item, /* out */ int &Index, const System::DelphiInterface<System::Generics::Defaults::IComparer__1<T> > AComparer);
	bool __fastcall Contains(const T AItem);
	void __fastcall DeleteRange(int AIndex, int ACount);
	HIDESBASE T __fastcall Extract(const T AItem);
	HIDESBASE T __fastcall First();
	HIDESBASE T __fastcall Last();
	int __fastcall Max(System::DelphiInterface<TdxListMaxIntegerAction__1<T> > AAction);
	HIDESBASE void __fastcall Sort(const System::DelphiInterface<System::Generics::Defaults::IComparer__1<T> > AComparer)/* overload */;
	HIDESBASE void __fastcall Sort()/* overload */;
	System::DynamicArray<T> __fastcall ToArray();
	__property T Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxList__1() { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TdxNotificationCollectionChangedEvent)(System::TObject* const AItem, System::Classes::TListNotification Action);

typedef Dxcoreclasses::TdxMulticastMethod__1<TdxNotificationCollectionChangedEvent> TdxNotificationCollectionChangedEventHandler;

#pragma pack(push,4)
// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename T> class PASCALIMPLEMENTATION TdxNotificationCollection__1 : public TdxList__1<T>
{
	typedef TdxList__1<T> inherited;
	
private:
	Dxcoreclasses::TdxMulticastMethod__1<TdxNotificationCollectionChangedEvent> FOnChanged;
	
protected:
	virtual void __fastcall Notify(void * Ptr, System::Classes::TListNotification Action);
	void __fastcall RaiseChanged(System::TObject* const AItem, System::Classes::TListNotification Action);
	
public:
	void __fastcall AddChangedHandler(TdxNotificationCollectionChangedEvent AHandler);
	void __fastcall RemoveChangedHandler(TdxNotificationCollectionChangedEvent AHandler);
public:
	/* {dxGenerics}TdxList<dxGenerics_TdxNotificationCollection<T>_T>.Create */ inline __fastcall TdxNotificationCollection__1()/* overload */ : TdxList__1<T>() { }
	/* {dxGenerics}TdxList<dxGenerics_TdxNotificationCollection<T>_T>.Create */ inline __fastcall TdxNotificationCollection__1(bool AOwnsObjects)/* overload */ : TdxList__1<T>(AOwnsObjects) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxNotificationCollection__1() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename T> class PASCALIMPLEMENTATION TdxObjectList__1 : public TdxList__1<T>
{
	typedef TdxList__1<T> inherited;
	
public:
	__fastcall TdxObjectList__1()/* overload */;
public:
	/* {dxGenerics}TdxList<dxGenerics_TdxObjectList<T>_T>.Create */ inline __fastcall TdxObjectList__1(bool AOwnsObjects)/* overload */ : TdxList__1<T>(AOwnsObjects) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxObjectList__1() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename T> class PASCALIMPLEMENTATION TdxNotificationObjectCollection__1 : public TdxNotificationCollection__1<T>
{
	typedef TdxNotificationCollection__1<T> inherited;
	
public:
	__fastcall TdxNotificationObjectCollection__1()/* overload */;
public:
	/* {dxGenerics}TdxList<dxGenerics_TdxNotificationObjectCollection<T>_T>.Create */ inline __fastcall TdxNotificationObjectCollection__1(bool AOwnsObjects)/* overload */ : TdxNotificationCollection__1<T>(AOwnsObjects) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxNotificationObjectCollection__1() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxOrdinalHelper : public System::TObject
{
	typedef System::TObject inherited;
	
	
public:
	typedef void __fastcall (*TSetter)(NativeInt AValue, void * ADest);
	
	
public:
	static System::StaticArray<NativeUInt, 4> SizeMask;
	static void __fastcall Set2(NativeInt AValue, void * ADest);
	static void __fastcall Set3(NativeInt AValue, void * ADest);
	
private:
	static System::StaticArray<TSetter, 2> Setters;
	
public:
	static void __fastcall SetValue(int ASize, NativeInt AValue, void * ADest);
public:
	/* TObject.Create */ inline __fastcall TdxOrdinalHelper() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxOrdinalHelper() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxStringToOrdinalMap : public System::TObject
{
	typedef System::TObject inherited;
	
	
public:
	struct TItem;
	typedef TItem *PItem;
	
	#pragma pack(push,8)
	struct DECLSPEC_DRECORD TItem
	{
	public:
		System::UnicodeString Key;
		unsigned Hash;
		NativeInt Value;
		TdxStringToOrdinalMap::TItem *Next;
	};
	#pragma pack(pop)
	
	
	typedef System::DynamicArray<PItem> TTable;
	
	
public:
	static const System::Word DefaultHashTableSize = System::Word(0x2b3);
	
	
private:
	unsigned FCount;
	TTable FTable;
	unsigned FTableSize;
	int FValueSize;
	
protected:
	PItem __fastcall NewItem(const System::UnicodeString AKey, unsigned AHash, const NativeInt AValue);
	void __fastcall InternalAdd(const System::UnicodeString AKey, NativeInt AValue, bool ACheckDuplicates);
	void __fastcall InternalRemove(PItem AItem);
	bool __fastcall InternalTryGetValue(const System::UnicodeString AKey, /* out */ NativeInt &AValue);
	virtual void __fastcall RemoveValue(NativeInt AValue);
	
protected:
	__property TTable Table = {read=FTable};
	
public:
	__fastcall TdxStringToOrdinalMap(int AValueSize, unsigned ATableSize);
	__fastcall virtual ~TdxStringToOrdinalMap();
	void __fastcall Add(const System::UnicodeString AKey, void * AValue);
	void __fastcall AddOrSetValue(const System::UnicodeString AKey, void * AValue);
	void __fastcall Clear();
	bool __fastcall ContainsKey(const System::UnicodeString AKey);
	static unsigned __fastcall Hash(const System::UnicodeString S);
	bool __fastcall Remove(const System::UnicodeString AKey);
	bool __fastcall TryGetValue(const System::UnicodeString AKey, void * AValue);
	System::DynamicArray<System::UnicodeString> __fastcall Keys();
	__property unsigned Count = {read=FCount, nodefault};
	__property unsigned TableSize = {read=FTableSize, nodefault};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNamedOrdinalDictionary : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxStringToOrdinalMap* FMap;
	int __fastcall GetCount();
	
protected:
	virtual TdxStringToOrdinalMap* __fastcall CreateMap() = 0 ;
	
protected:
	__property TdxStringToOrdinalMap* Map = {read=FMap};
	
public:
	__fastcall TdxNamedOrdinalDictionary();
	__fastcall virtual ~TdxNamedOrdinalDictionary();
	void __fastcall Clear();
	bool __fastcall ContainsKey(const System::UnicodeString AKey);
	void __fastcall Remove(const System::UnicodeString AKey);
	System::DynamicArray<System::UnicodeString> __fastcall Keys();
	__property int Count = {read=GetCount, nodefault};
};

#pragma pack(pop)

#pragma pack(push,4)
// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename T> class PASCALIMPLEMENTATION TdxNamedOrdinalDictionary__1 : public TdxNamedOrdinalDictionary
{
	typedef TdxNamedOrdinalDictionary inherited;
	
public:
	T operator[](const System::UnicodeString AKey) { return this->Items[AKey]; }
	
private:
	T __fastcall GetItem(const System::UnicodeString AKey);
	void __fastcall SetItem(const System::UnicodeString AKey, const T Value);
	
protected:
	virtual TdxStringToOrdinalMap* __fastcall CreateMap();
	
public:
	void __fastcall Add(const System::UnicodeString AKey, T AValue);
	void __fastcall AddOrSetValue(const System::UnicodeString AKey, T AValue);
	bool __fastcall ContainsValue(const T Value);
	T __fastcall GetValueDef(const System::UnicodeString AKey, T ADefaultValue);
	bool __fastcall TryGetValue(const System::UnicodeString AKey, /* out */ T &AValue);
	__property T Items[const System::UnicodeString AKey] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TdxNamedOrdinalDictionary.Create */ inline __fastcall TdxNamedOrdinalDictionary__1() : TdxNamedOrdinalDictionary() { }
	/* TdxNamedOrdinalDictionary.Destroy */ inline __fastcall virtual ~TdxNamedOrdinalDictionary__1() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxStringBooleanDictionary : public TdxNamedOrdinalDictionary__1<bool>
{
	typedef TdxNamedOrdinalDictionary__1<bool> inherited;
	
public:
	/* TdxNamedOrdinalDictionary.Create */ inline __fastcall TdxStringBooleanDictionary() : TdxNamedOrdinalDictionary__1<bool>() { }
	/* TdxNamedOrdinalDictionary.Destroy */ inline __fastcall virtual ~TdxStringBooleanDictionary() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename T> class PASCALIMPLEMENTATION TdxNamedObjectDictionary__1 : public TdxNamedOrdinalDictionary
{
	typedef TdxNamedOrdinalDictionary inherited;
	
	
protected:
	class DELPHICLASS TMap;
	// Template declaration generated by Delphi parameterized types is
	// used only for accessing Delphi variables and fields.
	// Don't instantiate with new type parameters in user code.
	class PASCALIMPLEMENTATION TMap : public TdxStringToOrdinalMap
	{
		typedef TdxStringToOrdinalMap inherited;
		
	private:
		bool FOwnsObjects;
		
	protected:
		virtual void __fastcall RemoveValue(NativeInt AValue);
		
	public:
		__property bool OwnsObjects = {read=FOwnsObjects, write=FOwnsObjects, nodefault};
	public:
		/* TdxStringToOrdinalMap.Create */ inline __fastcall TMap(int AValueSize, unsigned ATableSize) : TdxStringToOrdinalMap(AValueSize, ATableSize) { }
		/* TdxStringToOrdinalMap.Destroy */ inline __fastcall virtual ~TMap() { }
		
	};
	
	
	
public:
	T operator[](const System::UnicodeString AKey) { return this->Items[AKey]; }
	
private:
	T __fastcall GetItem(const System::UnicodeString AKey);
	bool __fastcall GetOwnsObjects();
	void __fastcall SetItem(const System::UnicodeString AKey, const T Value);
	void __fastcall SetOwnsObjects(const bool Value);
	
protected:
	virtual TdxStringToOrdinalMap* __fastcall CreateMap();
	
public:
	__fastcall TdxNamedObjectDictionary__1(bool AOwnsObjects);
	void __fastcall Add(const System::UnicodeString AKey, T AValue);
	void __fastcall AddOrSetValue(const System::UnicodeString AKey, T AValue);
	bool __fastcall TryGetValue(const System::UnicodeString AKey, /* out */ T &AValue);
	__property T Items[const System::UnicodeString AKey] = {read=GetItem, write=SetItem/*, default*/};
	__property bool OwnsObjects = {read=GetOwnsObjects, write=SetOwnsObjects, nodefault};
	System::DynamicArray<T> __fastcall Values();
public:
	/* TdxNamedOrdinalDictionary.Destroy */ inline __fastcall virtual ~TdxNamedObjectDictionary__1() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename TValue> class PASCALIMPLEMENTATION TdxNamedDelegateDictionary__1 : public System::TObject
{
	typedef System::TObject inherited;
	
	
protected:
	class DELPHICLASS TItem;
	// Template declaration generated by Delphi parameterized types is
	// used only for accessing Delphi variables and fields.
	// Don't instantiate with new type parameters in user code.
	class PASCALIMPLEMENTATION TItem : public System::TObject
	{
		typedef System::TObject inherited;
		
	private:
		System::UnicodeString FKey;
		unsigned FHash;
		TValue FValue;
		typename TdxNamedDelegateDictionary__1<TValue>::TItem* FNext;
		
	public:
		__fastcall TItem(const System::UnicodeString AKey, unsigned AHash, const TValue AValue);
		bool __fastcall IsEqualTo(typename TdxNamedDelegateDictionary__1<TValue>::TItem* AItem);
		__property System::UnicodeString Key = {read=FKey};
		__property unsigned Hash = {read=FHash, nodefault};
		__property typename TdxNamedDelegateDictionary__1<TValue>::TItem* Next = {read=FNext, write=FNext};
		__property TValue Value = {read=FValue, write=FValue};
	public:
		/* TObject.Destroy */ inline __fastcall virtual ~TItem() { }
		
	};
	
	
	
public:
	static const unsigned DefaultHashTableSize = unsigned(0x1d3);
	
	
private:
	int FCount;
	System::DynamicArray<TItem*> FTable;
	
protected:
	static unsigned __fastcall Hash(const System::UnicodeString AKey);
	void __fastcall InternalAdd(const System::UnicodeString AKey, const TValue AValue, bool ACheckDuplicates);
	__property System::DynamicArray<TItem*> Table = {read=FTable};
	
public:
	__fastcall TdxNamedDelegateDictionary__1();
	__fastcall virtual ~TdxNamedDelegateDictionary__1();
	void __fastcall Add(const System::UnicodeString AKey, TValue AValue);
	void __fastcall AddOrSetValue(const System::UnicodeString AKey, TValue AValue);
	void __fastcall Clear();
	bool __fastcall ContainsKey(const System::UnicodeString AKey);
	System::DynamicArray<System::UnicodeString> __fastcall Keys();
	bool __fastcall TryGetValue(const System::UnicodeString AKey, /* out */ TValue &AValue);
	__property int Count = {read=FCount, nodefault};
};

#pragma pack(pop)

#pragma pack(push,4)
// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename TValue> class PASCALIMPLEMENTATION TdxEnumeratedMap__1 : public System::TObject
{
	typedef System::TObject inherited;
	
	
protected:
	typedef System::DynamicArray<bool> TKeyTable;
	
	typedef System::DynamicArray<TValue> TValueTable;
	
	
private:
	int FCount;
	System::DynamicArray<bool> FKeyTable;
	System::DynamicArray<TValue> FValueTable;
	unsigned FTableSize;
	System::DynamicArray<TValue> __fastcall GetValues();
	
protected:
	void __fastcall Clear();
	void __fastcall InternalAdd(unsigned AKey, const TValue AValue, bool ACheckDuplicates);
	virtual void __fastcall InternalRemove(unsigned AKey);
	
public:
	__fastcall TdxEnumeratedMap__1(unsigned ATableSize);
	__fastcall virtual ~TdxEnumeratedMap__1();
	void __fastcall Add(unsigned AKey, const TValue AValue);
	void __fastcall AddOrSetValue(unsigned AKey, const TValue AValue);
	bool __fastcall ContainsKey(unsigned AKey);
	void __fastcall Remove(unsigned AKey);
	bool __fastcall TryGetValue(unsigned AKey, /* out */ TValue &AValue);
	__property int Count = {read=FCount, nodefault};
	__property unsigned TableSize = {read=FTableSize, nodefault};
	__property TKeyTable KeyTable = {read=FKeyTable};
	__property TValueTable ValueTable = {read=FValueTable};
	__property System::DynamicArray<TValue> Values = {read=GetValues};
};

#pragma pack(pop)

#pragma pack(push,4)
// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename TValue> class PASCALIMPLEMENTATION TdxEnumeratedDictionary__1 : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	unsigned FKeySize;
	TdxEnumeratedMap__1<TValue>* FMap;
	int FMinValue;
	int FMaxValue;
	int __fastcall GetCount();
	System::DynamicArray<TValue> __fastcall GetValues();
	
protected:
	virtual TdxEnumeratedMap__1<TValue>* __fastcall CreateMap(unsigned ATableSize);
	__property unsigned KeySize = {read=FKeySize, nodefault};
	__property int MinValue = {read=FMinValue, nodefault};
	__property TdxEnumeratedMap__1<TValue>* Map = {read=FMap};
	__property int MaxValue = {read=FMaxValue, nodefault};
	
public:
	__fastcall TdxEnumeratedDictionary__1(unsigned AKeySize, System::Typinfo::PTypeInfo ATypeInfo);
	__fastcall virtual ~TdxEnumeratedDictionary__1();
	__property int Count = {read=GetCount, nodefault};
	__property System::DynamicArray<TValue> Values = {read=GetValues};
};

#pragma pack(pop)

#pragma pack(push,4)
// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename TEnumeration, typename TValue> class PASCALIMPLEMENTATION TdxEnumeratedDictionary__2 : public TdxEnumeratedDictionary__1<TValue>
{
	typedef TdxEnumeratedDictionary__1<TValue> inherited;
	
public:
	TValue operator[](TEnumeration AKey) { return this->Items[AKey]; }
	
private:
	TValue __fastcall GetItem(TEnumeration AKey);
	System::DynamicArray<TEnumeration> __fastcall GetKeys();
	void __fastcall SetItem(TEnumeration AKey, const TValue Value);
	
public:
	__fastcall TdxEnumeratedDictionary__2();
	void __fastcall Add(TEnumeration AKey, const TValue AValue);
	void __fastcall AddOrSetValue(TEnumeration AKey, const TValue AValue);
	bool __fastcall TryGetValue(TEnumeration AKey, /* out */ TValue &AValue);
	bool __fastcall ContainsKey(TEnumeration AKey);
	void __fastcall Remove(TEnumeration AKey);
	__property TValue Items[TEnumeration AKey] = {read=GetItem, write=SetItem/*, default*/};
	__property System::DynamicArray<TEnumeration> Keys = {read=GetKeys};
public:
	/* {dxGenerics}TdxEnumeratedDictionary<dxGenerics_TdxEnumeratedDictionary<TEnumeration,TValue>_TValue>.Destroy */ inline __fastcall virtual ~TdxEnumeratedDictionary__2() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename TEnumeration, typename TValue> class PASCALIMPLEMENTATION TdxEnumeratedObjectDictionary__2 : public TdxEnumeratedDictionary__1<TValue>
{
	typedef TdxEnumeratedDictionary__1<TValue> inherited;
	
	
protected:
	class DELPHICLASS TMap;
	// Template declaration generated by Delphi parameterized types is
	// used only for accessing Delphi variables and fields.
	// Don't instantiate with new type parameters in user code.
	class PASCALIMPLEMENTATION TMap : public TdxEnumeratedMap__1<System::TObject*>
	{
		typedef TdxEnumeratedMap__1<System::TObject*> inherited;
		
	private:
		bool FOwnsObjects;
		
	protected:
		virtual void __fastcall InternalRemove(unsigned AKey);
		
	public:
		__property bool OwnsObjects = {read=FOwnsObjects, write=FOwnsObjects, nodefault};
	public:
		/* {dxGenerics}TdxEnumeratedMap<System_TObject>.Create */ inline __fastcall TMap(unsigned ATableSize) : TdxEnumeratedMap__1<System::TObject*>(ATableSize) { }
		/* {dxGenerics}TdxEnumeratedMap<System_TObject>.Destroy */ inline __fastcall virtual ~TMap() { }
		
	};
	
	
	
public:
	TValue operator[](TEnumeration AKey) { return this->Items[AKey]; }
	
private:
	TValue __fastcall GetItem(TEnumeration AKey);
	System::DynamicArray<TEnumeration> __fastcall GetKeys();
	TMap* __fastcall GetMap();
	bool __fastcall GetOwnsObjects();
	void __fastcall SetOwnsObjects(const bool Value);
	void __fastcall SetItem(TEnumeration AKey, const TValue Value);
	
protected:
	virtual TdxEnumeratedMap__1<TValue>* __fastcall CreateMap(unsigned ATableSize);
	__property TMap* Map = {read=GetMap};
	
public:
	__fastcall TdxEnumeratedObjectDictionary__2(bool AOwnsObjects);
	void __fastcall Add(TEnumeration AKey, TValue AValue);
	void __fastcall AddOrSetValue(TEnumeration AKey, TValue AValue);
	bool __fastcall TryGetValue(TEnumeration AKey, /* out */ TValue &AValue);
	bool __fastcall ContainsKey(TEnumeration AKey);
	void __fastcall Remove(TEnumeration AKey);
	__property TValue Items[TEnumeration AKey] = {read=GetItem, write=SetItem/*, default*/};
	__property System::DynamicArray<TEnumeration> Keys = {read=GetKeys};
	__property bool OwnsObjects = {read=GetOwnsObjects, write=SetOwnsObjects, nodefault};
public:
	/* {dxGenerics}TdxEnumeratedDictionary<dxGenerics_TdxEnumeratedObjectDictionary<TEnumeration,TValue>_TValue>.Destroy */ inline __fastcall virtual ~TdxEnumeratedObjectDictionary__2() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TdxOrdinalList : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FCapacity;
	int FCount;
	typedef void __fastcall (__closure *_dt_Dxgenerics_1)(System::TObject* Sender, const NativeUInt Item, System::Generics::Collections::TCollectionNotification Action);
	_dt_Dxgenerics_1 FOnNotify;
	
protected:
	System::DynamicArray<NativeUInt> FList;
	void __fastcall DoDelete(int AIndex);
	void __fastcall CheckDeleteRange(int AIndex, int ACount);
	void __fastcall DoDeleteRange(int AIndex, int ACount);
	NativeUInt __fastcall GetItem(int AIndex);
	void __fastcall Grow();
	virtual void __fastcall Notify(const NativeUInt AItem, System::Generics::Collections::TCollectionNotification AAction);
	void __fastcall SetCapacity(int AValue);
	virtual void __fastcall SetCount(int AValue);
	void __fastcall SetItem(int AIndex, NativeUInt AItem);
	int __fastcall Add(NativeUInt AItem);
	bool __fastcall BinarySearch(NativeUInt AItem, /* out */ int &AIndex, const System::DelphiInterface<System::Generics::Defaults::IComparer__1<NativeUInt> > AComparer);
	bool __fastcall Contains(NativeUInt AItem);
	NativeUInt __fastcall Extract(NativeUInt AItem, System::Types::TDirection ADirection = (System::Types::TDirection)(0x0));
	NativeUInt __fastcall ExtractByIndex(int AIndex);
	NativeUInt __fastcall First();
	int __fastcall IndexOf(NativeUInt AItem);
	int __fastcall LastIndexOf(NativeUInt AItem);
	NativeUInt __fastcall Last();
	int __fastcall Remove(NativeUInt AItem);
	typedef void __fastcall (__closure *_dt_Dxgenerics_2)(System::TObject* Sender, const NativeUInt Item, System::Generics::Collections::TCollectionNotification Action);
	__property _dt_Dxgenerics_2 OnNotify = {read=FOnNotify, write=FOnNotify};
	
public:
	__fastcall TdxOrdinalList(int ACapacity);
	__fastcall virtual ~TdxOrdinalList();
	virtual void __fastcall Clear();
	void __fastcall Delete(int AIndex);
	void __fastcall DeleteRange(int AIndex, int ACount);
	bool __fastcall Empty();
	void __fastcall Exchange(int AIndex1, int AIndex2);
	void __fastcall Insert(int AIndex, NativeUInt AItem);
	void __fastcall Move(int ACurrentIndex, int ANewIndex);
	void __fastcall Reverse();
	void __fastcall Sort()/* overload */;
	void __fastcall Sort(Dxcoreclasses::TCompareItems ACompare, bool AMultiThreaded = false)/* overload */;
	void __fastcall Sort(System::Classes::TListSortCompare ACompare, bool AMultiThreaded = false)/* overload */;
	void __fastcall Sort(Dxcoreclasses::_di_TdxListSortCompareDelegate ACompare)/* overload */;
	__property int Capacity = {read=FCapacity, write=SetCapacity, nodefault};
	__property int Count = {read=FCount, write=SetCount, nodefault};
};


// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename T> class PASCALIMPLEMENTATION TdxOrdinalList__1 : public TdxOrdinalList
{
	typedef TdxOrdinalList inherited;
	
public:
	T operator[](int Index) { return this->Items[Index]; }
	
private:
	int FItemSize;
	NativeUInt FValueMask;
	HIDESBASE T __fastcall GetItem(int AIndex);
	HIDESBASE void __fastcall SetItem(int AIndex, T AValue);
	
protected:
	__property int ItemSize = {read=FItemSize, nodefault};
	__property NativeUInt ValueMask = {read=FValueMask, nodefault};
	
public:
	__fastcall TdxOrdinalList__1(int ACapacity)/* overload */;
	__fastcall TdxOrdinalList__1(TdxOrdinalList__1<T>* ACollection)/* overload */;
	HIDESBASE int __fastcall Add(T AItem);
	void __fastcall AddRange(TdxOrdinalList__1<T>* AList)/* overload */;
	void __fastcall AddRange(const System::DynamicArray<T> AArray)/* overload */;
	void __fastcall AddRange(System::Generics::Collections::TEnumerable__1<T>* const AEnumerable)/* overload */;
	HIDESBASE bool __fastcall BinarySearch(T AItem, /* out */ int &AIndex)/* overload */;
	HIDESBASE bool __fastcall Contains(T AItem);
	HIDESBASE T __fastcall Extract(T AItem, System::Types::TDirection ADirection = (System::Types::TDirection)(0x0));
	HIDESBASE T __fastcall ExtractByIndex(int AIndex);
	HIDESBASE T __fastcall First();
	HIDESBASE void __fastcall Insert(int AIndex, NativeUInt AItem);
	HIDESBASE int __fastcall IndexOf(T AItem);
	HIDESBASE int __fastcall LastIndexOf(T AItem);
	HIDESBASE T __fastcall Last();
	HIDESBASE int __fastcall Remove(T AItem);
	System::DynamicArray<T> __fastcall ToArray();
	__property T Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TdxOrdinalList.Destroy */ inline __fastcall virtual ~TdxOrdinalList__1() { }
	
};


class PASCALIMPLEMENTATION TdxAlphaColorList : public TdxOrdinalList__1<Dxcoregraphics::TdxAlphaColor>
{
	typedef TdxOrdinalList__1<Dxcoregraphics::TdxAlphaColor> inherited;
	
public:
	/* {dxGenerics}TdxOrdinalList<dxCoreGraphics_TdxAlphaColor>.Create */ inline __fastcall TdxAlphaColorList(int ACapacity)/* overload */ : TdxOrdinalList__1<Dxcoregraphics::TdxAlphaColor>(ACapacity) { }
	/* {dxGenerics}TdxOrdinalList<dxCoreGraphics_TdxAlphaColor>.Create */ inline __fastcall TdxAlphaColorList(TdxOrdinalList__1<Dxcoregraphics::TdxAlphaColor>* ACollection)/* overload */ : TdxOrdinalList__1<Dxcoregraphics::TdxAlphaColor>(ACollection) { }
	
public:
	/* TdxOrdinalList.Destroy */ inline __fastcall virtual ~TdxAlphaColorList() { }
	
};


class PASCALIMPLEMENTATION TdxColorList : public TdxOrdinalList__1<System::Uitypes::TColor>
{
	typedef TdxOrdinalList__1<System::Uitypes::TColor> inherited;
	
public:
	/* {dxGenerics}TdxOrdinalList<System_UITypes_TColor>.Create */ inline __fastcall TdxColorList(int ACapacity)/* overload */ : TdxOrdinalList__1<System::Uitypes::TColor>(ACapacity) { }
	/* {dxGenerics}TdxOrdinalList<System_UITypes_TColor>.Create */ inline __fastcall TdxColorList(TdxOrdinalList__1<System::Uitypes::TColor>* ACollection)/* overload */ : TdxOrdinalList__1<System::Uitypes::TColor>(ACollection) { }
	
public:
	/* TdxOrdinalList.Destroy */ inline __fastcall virtual ~TdxColorList() { }
	
};


class PASCALIMPLEMENTATION TdxIntegerList : public TdxOrdinalList__1<int>
{
	typedef TdxOrdinalList__1<int> inherited;
	
public:
	/* {dxGenerics}TdxOrdinalList<System_Integer>.Create */ inline __fastcall TdxIntegerList(int ACapacity)/* overload */ : TdxOrdinalList__1<int>(ACapacity) { }
	/* {dxGenerics}TdxOrdinalList<System_Integer>.Create */ inline __fastcall TdxIntegerList(TdxOrdinalList__1<int>* ACollection)/* overload */ : TdxOrdinalList__1<int>(ACollection) { }
	
public:
	/* TdxOrdinalList.Destroy */ inline __fastcall virtual ~TdxIntegerList() { }
	
};


#pragma pack(push,4)
// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename T> class PASCALIMPLEMENTATION TdxObjectStack__1 : public System::Contnrs::TObjectStack
{
	typedef System::Contnrs::TObjectStack inherited;
	
private:
	bool FOwnsObjects;
	
public:
	__fastcall TdxObjectStack__1(bool AOwnsObjects);
	__fastcall virtual ~TdxObjectStack__1();
	void __fastcall Clear();
	T __fastcall Extract();
	HIDESBASE void __fastcall Pop();
	HIDESBASE T __fastcall Peek();
	System::DynamicArray<T> __fastcall ToArray();
	__property bool OwnsObjects = {read=FOwnsObjects, write=FOwnsObjects, nodefault};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxIntegerStack : public System::Contnrs::TStack
{
	typedef System::Contnrs::TStack inherited;
	
public:
	void __fastcall Clear();
	HIDESBASE void * __fastcall Push(NativeInt AItem);
	HIDESBASE NativeInt __fastcall Pop();
	HIDESBASE NativeInt __fastcall Peek();
public:
	/* TOrderedList.Create */ inline __fastcall TdxIntegerStack() : System::Contnrs::TStack() { }
	/* TOrderedList.Destroy */ inline __fastcall virtual ~TdxIntegerStack() { }
	
};

#pragma pack(pop)

__interface TdxTopologicalSorterIsDependOnDelegate  : public System::IInterface 
{
	virtual bool __fastcall Invoke(int ALeft, int ARight) = 0 ;
};

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTopologicalSorterNode : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FOneBasedSuccessorIndex;
	TdxTopologicalSorterNode* FNext;
	
public:
	__fastcall TdxTopologicalSorterNode(int AOneBasedSuccessorIndex, TdxTopologicalSorterNode* ANext);
	__property int OneBasedSuccessorIndex = {read=FOneBasedSuccessorIndex, nodefault};
	__property TdxTopologicalSorterNode* Next = {read=FNext};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxTopologicalSorterNode() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename T> class PASCALIMPLEMENTATION TdxTopologicalSorter__1 : public System::TObject
{
	typedef System::TObject inherited;
	
	
private:
	#pragma pack(push,8)
	// Template declaration generated by Delphi parameterized types is
	// used only for accessing Delphi variables and fields.
	// Don't instantiate with new type parameters in user code.
	struct DECLSPEC_DRECORD TDefaultDependencyCalculator
	{
	private:
		TdxList__1<T>* FSourceObjects;
		System::DelphiInterface<System::Generics::Defaults::IComparer__1<T> > FComparer;
		
	public:
		__fastcall TDefaultDependencyCalculator(TdxList__1<T>* ASourceObjects, System::DelphiInterface<System::Generics::Defaults::IComparer__1<T> > AComparer);
		bool __fastcall IsDependOn(int Left, int Right);
		TDefaultDependencyCalculator() {}
	};
	#pragma pack(pop)
	
	
	
private:
	System::DynamicArray<int> FQLink;
	TdxObjectList__1<TdxTopologicalSorterNode*>* FNodeList;
	System::DynamicArray<TdxTopologicalSorterNode*> FNodes;
	bool FSuccess;
	
protected:
	void __fastcall AppendRelation(int ASuccessorIndex, int APredecessorIndex);
	void __fastcall Initialize(int N);
	void __fastcall CalculateRelations(TdxList__1<T>* ASourceObjects, const _di_TdxTopologicalSorterIsDependOnDelegate AIsDependOn);
	int __fastcall CreateVirtualNoPredecessorsItemList();
	TdxList__1<T>* __fastcall ProcessNodes(int ALastNoPredecessorItemIndex, TdxList__1<T>* ASourceObjects);
	TdxTopologicalSorterNode* __fastcall RemoveRelation(TdxTopologicalSorterNode* ANode, int &ALastNoPredecessorItemIndex);
	TdxList__1<T>* __fastcall DoSort(TdxList__1<T>* ASourceObjects, System::DelphiInterface<System::Generics::Defaults::IComparer__1<T> > AComparer)/* overload */;
	TdxList__1<T>* __fastcall DoSort(TdxList__1<T>* ASourceObjects, const _di_TdxTopologicalSorterIsDependOnDelegate AIsDependOn)/* overload */;
	__property System::DynamicArray<TdxTopologicalSorterNode*> Nodes = {read=FNodes};
	__property System::DynamicArray<int> QLink = {read=FQLink};
	
public:
	__fastcall TdxTopologicalSorter__1();
	__fastcall virtual ~TdxTopologicalSorter__1();
	__classmethod TdxList__1<T>* __fastcall Sort(TdxList__1<T>* ASourceObjects, System::DelphiInterface<System::Generics::Defaults::IComparer__1<T> > AComparer);
	__property bool Success = {read=FSuccess, nodefault};
};

#pragma pack(pop)

#pragma pack(push,4)
// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename T> class PASCALIMPLEMENTATION TdxComparer__1 : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
public:
	__classmethod System::DelphiInterface<System::Generics::Defaults::IComparer__1<T> > __fastcall Default();
	__classmethod System::DelphiInterface<System::Generics::Defaults::IComparer__1<T> > __fastcall Construct(const System::DelphiInterface<System::Generics::Defaults::TComparison__1<T> > Comparison);
	virtual int __fastcall Compare(const T Left, const T Right) = 0 ;
public:
	/* TObject.Create */ inline __fastcall TdxComparer__1() : Dxcoreclasses::TcxIUnknownObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxComparer__1() { }
	
private:
	void *__IComparer__1;	// System::Generics::Defaults::IComparer__1<T> 
	
public:
	operator System::Generics::Defaults::IComparer__1<T>*(void) { return (System::Generics::Defaults::IComparer__1<T>*)&__IComparer__1; }
	
};

#pragma pack(pop)

// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename T> __interface IdxComparable__1  : public System::IInterface 
{
	virtual int __fastcall CompareTo(const T Value) = 0 ;
};

#pragma pack(push,4)
// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename T> class PASCALIMPLEMENTATION TdxDefaultComparable__1 : public System::TInterfacedObject
{
	typedef System::TInterfacedObject inherited;
	
private:
	T FValue;
	System::DelphiInterface<System::Generics::Defaults::IComparer__1<T> > FComparer;
	
protected:
	int __fastcall CompareTo(const T AValue);
	
public:
	__fastcall TdxDefaultComparable__1(const T AValue);
	__property T Value = {read=FValue};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxDefaultComparable__1() { }
	
private:
	void *__IdxComparable__1;	// IdxComparable__1<T> 
	
public:
	operator IdxComparable__1<T>*(void) { return (IdxComparable__1<T>*)&__IdxComparable__1; }
	
};

#pragma pack(pop)

// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename T> __interface TdxComparableFunc__1  : public System::IInterface 
{
	virtual int __fastcall Invoke(const T Arg1) = 0 ;
};

#pragma pack(push,4)
// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename T> class PASCALIMPLEMENTATION TdxAlgorithms__1 : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod bool __fastcall BinarySearch(System::Generics::Collections::TList__1<T>* AList, const T AValue, /* out */ int &AIndex)/* overload */;
	__classmethod bool __fastcall BinarySearch(System::Generics::Collections::TList__1<T>* AList, const System::DelphiInterface<IdxComparable__1<T> > APredicate, int AStartIndex, int AEndIndex, /* out */ int &AIndex)/* overload */;
	__classmethod bool __fastcall BinarySearch(System::Generics::Collections::TList__1<T>* AList, const System::DelphiInterface<IdxComparable__1<T> > APredicate, /* out */ int &AIndex)/* overload */;
	__classmethod bool __fastcall BinarySearch(System::Generics::Collections::TList__1<T>* AList, const System::DelphiInterface<TdxComparableFunc__1<T> > APredicate, int AStartIndex, int AEndIndex, /* out */ int &AIndex)/* overload */;
	__classmethod bool __fastcall BinarySearch(System::Generics::Collections::TList__1<T>* AList, const System::DelphiInterface<TdxComparableFunc__1<T> > APredicate, /* out */ int &AIndex)/* overload */;
public:
	/* TObject.Create */ inline __fastcall TdxAlgorithms__1() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxAlgorithms__1() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename T> class PASCALIMPLEMENTATION TdxAlgorithms1__1 : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod bool __fastcall BinarySearch(TdxList__1<T>* AList, const System::DelphiInterface<IdxComparable__1<T> > APredicate, int AStartIndex, int AEndIndex, /* out */ int &AIndex)/* overload */;
	__classmethod bool __fastcall BinarySearch(TdxList__1<T>* AList, const System::DelphiInterface<IdxComparable__1<T> > APredicate, /* out */ int &AIndex)/* overload */;
	__classmethod bool __fastcall BinarySearch(TdxList__1<T>* AList, const System::DelphiInterface<TdxComparableFunc__1<T> > APredicate, int AStartIndex, int AEndIndex, /* out */ int &AIndex)/* overload */;
	__classmethod bool __fastcall BinarySearch(TdxList__1<T>* AList, const System::DelphiInterface<TdxComparableFunc__1<T> > APredicate, /* out */ int &AIndex)/* overload */;
	__classmethod bool __fastcall BinarySearchReverseOrder(TdxList__1<T>* AList, const System::DelphiInterface<IdxComparable__1<T> > APredicate, int AStartIndex, int AEndIndex, /* out */ int &AIndex)/* overload */;
	__classmethod bool __fastcall BinarySearchReverseOrder(TdxList__1<T>* AList, const System::DelphiInterface<IdxComparable__1<T> > APredicate, /* out */ int &AIndex)/* overload */;
public:
	/* TObject.Create */ inline __fastcall TdxAlgorithms1__1() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxAlgorithms1__1() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename T> class PASCALIMPLEMENTATION TdxSortedList__1 : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	T operator[](int Index) { return this->Self[Index]; }
	
private:
	System::DelphiInterface<System::Generics::Defaults::IComparer__1<T> > FComparer;
	T __fastcall GetItem(int Index);
	
protected:
	System::Generics::Collections::TList__1<T>* FInnerList;
	virtual System::Generics::Collections::TList__1<T>* __fastcall CreateInnerList();
	
public:
	__fastcall TdxSortedList__1()/* overload */;
	__fastcall TdxSortedList__1(const System::DelphiInterface<System::Generics::Defaults::IComparer__1<T> > AComparer)/* overload */;
	__fastcall virtual ~TdxSortedList__1();
	int __fastcall Count();
	T __fastcall First();
	T __fastcall Last();
	void __fastcall Add(const T AValue);
	void __fastcall Insert(int AIndex, const T AValue);
	virtual bool __fastcall Contains(const T AValue);
	int __fastcall BinarySearch(const T AValue)/* overload */;
	int __fastcall BinarySearch(const System::DelphiInterface<IdxComparable__1<T> > APredicate)/* overload */;
	int __fastcall BinarySearch(const System::DelphiInterface<TdxComparableFunc__1<T> > APredicate)/* overload */;
	void __fastcall Delete(int AIndex);
	T __fastcall Extract(const T Value);
	virtual void __fastcall Remove(const T AValue);
	virtual void __fastcall RemoveFrom(const T AValue);
	virtual void __fastcall Clear();
	virtual void __fastcall CopyCore(TdxSortedList__1<T>* ADestination);
	__property System::DelphiInterface<System::Generics::Defaults::IComparer__1<T> > Comparer = {read=FComparer};
	__property T Self[int Index] = {read=GetItem/*, default*/};
};

#pragma pack(pop)

#pragma pack(push,4)
// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename T> class PASCALIMPLEMENTATION TdxObjectSortedList__1 : public TdxSortedList__1<T>
{
	typedef TdxSortedList__1<T> inherited;
	
protected:
	virtual System::Generics::Collections::TList__1<T>* __fastcall CreateInnerList();
	
public:
	T __fastcall ExtractByIndex(int AIndex);
public:
	/* {dxGenerics}TdxSortedList<dxGenerics_TdxObjectSortedList<T>_T>.Create */ inline __fastcall TdxObjectSortedList__1()/* overload */ : TdxSortedList__1<T>() { }
	/* {dxGenerics}TdxSortedList<dxGenerics_TdxObjectSortedList<T>_T>.Create */ inline __fastcall TdxObjectSortedList__1(const System::DelphiInterface<System::Generics::Defaults::IComparer__1<T> > AComparer)/* overload */ : TdxSortedList__1<T>(AComparer) { }
	/* {dxGenerics}TdxSortedList<dxGenerics_TdxObjectSortedList<T>_T>.Destroy */ inline __fastcall virtual ~TdxObjectSortedList__1() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutUnitSortedList : /*[[sealed]]*/ public TdxSortedList__1<int>
{
	typedef TdxSortedList__1<int> inherited;
	
public:
	TdxLayoutUnitSortedList* __fastcall Clone();
public:
	/* {dxGenerics}TdxSortedList<System_Integer>.Create */ inline __fastcall TdxLayoutUnitSortedList()/* overload */ : TdxSortedList__1<int>() { }
	/* {dxGenerics}TdxSortedList<System_Integer>.Create */ inline __fastcall TdxLayoutUnitSortedList(const System::DelphiInterface<System::Generics::Defaults::IComparer__1<int> > AComparer)/* overload */ : TdxSortedList__1<int>(AComparer) { }
	/* {dxGenerics}TdxSortedList<System_Integer>.Destroy */ inline __fastcall virtual ~TdxLayoutUnitSortedList() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename T> class PASCALIMPLEMENTATION TdxHashSet__1 : public System::Generics::Collections::TEnumerable__1<T>
{
	typedef System::Generics::Collections::TEnumerable__1<T> inherited;
	
private:
	System::Generics::Collections::TDictionary__2<T,int>* FDictionary;
	int __fastcall GetCount();
	
protected:
	virtual System::Generics::Collections::TEnumerator__1<T>* __fastcall DoGetEnumerator();
	
public:
	__fastcall TdxHashSet__1(int ACapacity)/* overload */;
	__fastcall TdxHashSet__1(const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<T> > AComparer)/* overload */;
	__fastcall TdxHashSet__1(int ACapacity, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<T> > AComparer)/* overload */;
	__fastcall virtual ~TdxHashSet__1();
	bool __fastcall Contains(const T AValue);
	void __fastcall Clear();
	void __fastcall Include(const T AValue)/* overload */;
	void __fastcall Include(TdxHashSet__1<T>* const AValue)/* overload */;
	void __fastcall Include(System::Generics::Collections::TList__1<T>* const AValue)/* overload */;
	void __fastcall Include(const System::DynamicArray<T> AValue)/* overload */;
	void __fastcall Exclude(const T AValue)/* overload */;
	void __fastcall Exclude(TdxHashSet__1<T>* const AValue)/* overload */;
	void __fastcall Exclude(System::Generics::Collections::TList__1<T>* const AValue)/* overload */;
	void __fastcall Exclude(const System::DynamicArray<T> AValue)/* overload */;
	virtual System::DynamicArray<T> __fastcall ToArray();
	System::Generics::Collections::TList__1<T>* __fastcall ToList();
	__property int Count = {read=GetCount, nodefault};
};

#pragma pack(pop)

// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename T> struct DECLSPEC_DRECORD TdxSmartPointer__1
{
	
private:
	class DELPHICLASS TLifetimeWatcher;
	#pragma pack(push,4)
	// Template declaration generated by Delphi parameterized types is
	// used only for accessing Delphi variables and fields.
	// Don't instantiate with new type parameters in user code.
	class PASCALIMPLEMENTATION TLifetimeWatcher : public System::TInterfacedObject
	{
		typedef System::TInterfacedObject inherited;
		
	private:
		System::TObject* FObject;
		
	public:
		__fastcall TLifetimeWatcher(System::TObject* AObject);
		__fastcall virtual ~TLifetimeWatcher();
	};
	
	#pragma pack(pop)
	
	
private:
	T FValue;
	System::_di_IInterface FLifetime;
	
public:
	__fastcall TdxSmartPointer__1(const T AValue);
	__fastcall operator TdxSmartPointer__1<T>();
	__fastcall operator T();
	__property T Value = {read=FValue};
	TdxSmartPointer__1() {}
};


#pragma pack(push,4)
// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename TKey, typename TValue> class PASCALIMPLEMENTATION TdxMap__2 : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Generics::Collections::TDictionary__2<TKey,TValue>* FKeyToValue;
	System::Generics::Collections::TDictionary__2<TValue,TKey>* FValueToKey;
	
public:
	__fastcall TdxMap__2()/* overload */;
	__fastcall TdxMap__2(System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<TKey> > AComparerKey, System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<TValue> > AComparerValue, System::Generics::Collections::TDictionaryOwnerships AOwnerships, int ACapacity)/* overload */;
	__fastcall TdxMap__2(int ACapacity, System::Generics::Collections::TDictionaryOwnerships AOwnerships)/* overload */;
	__fastcall TdxMap__2(System::Generics::Collections::TDictionaryOwnerships AOwnerships)/* overload */;
	__fastcall virtual ~TdxMap__2();
	void __fastcall Add(const TKey AKey, const TValue AValue);
	void __fastcall Clear();
	void __fastcall DeleteByKey(const TKey AKey);
	void __fastcall DeleteByValue(const TValue AValue);
	TKey __fastcall GetKey(const TValue AValue);
	TValue __fastcall GetValue(const TKey AKey);
	bool __fastcall TryGetKey(const TValue AValue, /* out */ TKey &AKey);
	bool __fastcall TryGetValue(const TKey AKey, /* out */ TValue &AValue);
};

#pragma pack(pop)

#pragma pack(push,4)
// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename T> class PASCALIMPLEMENTATION TdxClassDictionary__1 : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
public:
	T operator[](System::TClass AClass) { return this->Items[AClass]; }
	
private:
	System::Generics::Collections::TDictionary__2<System::TClass,T>* FData;
	int __fastcall GetCount();
	T __fastcall GetItem(System::TClass AClass);
	
public:
	__fastcall TdxClassDictionary__1();
	__fastcall virtual ~TdxClassDictionary__1();
	void __fastcall Add(const System::TClass AClass, const T AValue);
	void __fastcall AddOrSetValue(const System::TClass AClass, const T AValue);
	void __fastcall Remove(const System::TClass AClass);
	bool __fastcall TryGetValue(System::TClass AClass, /* out */ T &AValue)/* overload */;
	bool __fastcall TryGetValue(System::TObject* AObject, /* out */ T &AValue)/* overload */;
	__property int Count = {read=GetCount, nodefault};
	__property T Items[System::TClass AClass] = {read=GetItem/*, default*/};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxgenerics */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXGENERICS)
using namespace Dxgenerics;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxgenericsHPP
