// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxHashUtils.pas' rev: 35.00 (Windows)

#ifndef DxhashutilsHPP
#define DxhashutilsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Hash.hpp>
#include <Winapi.Windows.hpp>
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <System.Math.hpp>
#include <System.Generics.Defaults.hpp>
#include <System.Generics.Collections.hpp>
#include <dxCore.hpp>
#include <dxCoreClasses.hpp>
#include <dxHash.hpp>

//-- user supplied -----------------------------------------------------------

namespace Dxhashutils
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TdxDynamicListItem;
__interface DELPHIINTERFACE TdxDynamicItemListForEachProcRef;
typedef System::DelphiInterface<TdxDynamicItemListForEachProcRef> _di_TdxDynamicItemListForEachProcRef;
class DELPHICLASS TdxDynamicItemList;
class DELPHICLASS TdxHashTableRow;
class DELPHICLASS TdxHashTable;
class DELPHICLASS TdxHashTableItem;
class DELPHICLASS TdxHashTableItemList;
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TdxDynamicListItemClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxDynamicListItem : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
protected:
	int FIndex;
	TdxDynamicListItem* FNext;
	TdxDynamicItemList* FOwner;
	TdxDynamicListItem* FPrev;
	virtual void __fastcall ShiftIndex(int ADelta);
	
public:
	__fastcall virtual TdxDynamicListItem(TdxDynamicItemList* AOwner, int AIndex);
	__fastcall virtual ~TdxDynamicListItem();
	virtual void __fastcall Assign(TdxDynamicListItem* ASource);
	__property int Index = {read=FIndex, nodefault};
};

#pragma pack(pop)

__interface TdxDynamicItemListForEachProcRef  : public System::IInterface 
{
	virtual void __fastcall Invoke(TdxDynamicListItem* AItem) = 0 ;
};

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxDynamicItemList : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TdxDynamicListItem* operator[](int Index) { return this->Items[Index]; }
	
private:
	int __fastcall GetCount();
	int __fastcall GetFirstIndex();
	TdxDynamicListItem* __fastcall GetItem(int AIndex);
	int __fastcall GetLastIndex();
	void __fastcall SetItem(int AIndex, TdxDynamicListItem* const AValue);
	
protected:
	TdxDynamicListItem* FCurrentItem;
	TdxDynamicListItem* FFirst;
	bool FIsDeletion;
	TdxDynamicListItem* FLast;
	TdxDynamicListItem* __fastcall CreateItem(const int AIndex);
	void __fastcall DeleteItem(TdxDynamicListItem* const AItem);
	virtual void __fastcall DoItemCreated(TdxDynamicListItem* AItem);
	TdxDynamicListItem* __fastcall FindItem(const int AIndex);
	void __fastcall ForEach(_di_TdxDynamicItemListForEachProcRef AProc, bool AGoForward = true)/* overload */;
	void __fastcall ForEach(_di_TdxDynamicItemListForEachProcRef AProc, int AStartIndex, int AFinishIndex, bool AGoForward = true)/* overload */;
	virtual TdxDynamicListItemClass __fastcall GetItemClass();
	void __fastcall InsertItem(TdxDynamicListItem* const ANewItem, TdxDynamicListItem* const ANeighborItem);
	TdxDynamicListItem* __fastcall ItemNeeded(const int AIndex);
	virtual void __fastcall ReleaseItem(TdxDynamicListItem* AItem);
	void __fastcall ShiftIndexes(int AStartFromIndex, int ADelta);
	
public:
	__fastcall virtual ~TdxDynamicItemList();
	void __fastcall Clear();
	__property int Count = {read=GetCount, nodefault};
	__property int FirstIndex = {read=GetFirstIndex, nodefault};
	__property TdxDynamicListItem* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
	__property int LastIndex = {read=GetLastIndex, nodefault};
public:
	/* TObject.Create */ inline __fastcall TdxDynamicItemList() : System::TObject() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxHashTableRow : public TdxDynamicItemList
{
	typedef TdxDynamicItemList inherited;
	
protected:
	virtual void __fastcall ReleaseItem(TdxDynamicListItem* Item);
public:
	/* TdxDynamicItemList.Destroy */ inline __fastcall virtual ~TdxHashTableRow() { }
	
public:
	/* TObject.Create */ inline __fastcall TdxHashTableRow() : TdxDynamicItemList() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxHashTable : public System::TObject
{
	typedef System::TObject inherited;
	
	
private:
	typedef System::DynamicArray<TdxHashTableRow*> _TdxHashTable__1;
	
	
protected:
	int FCount;
	_TdxHashTable__1 FTable;
	void __fastcall CheckAndAddItem(void *AItem);
	virtual void __fastcall DeleteItem(TdxHashTableItem* AItem);
	void __fastcall ForEach(_di_TdxDynamicItemListForEachProcRef AProc);
	
public:
	__fastcall virtual TdxHashTable();
	__fastcall virtual ~TdxHashTable();
	virtual void __fastcall Clear();
	__property int Count = {read=FCount, nodefault};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxHashTableItem : public TdxDynamicListItem
{
	typedef TdxDynamicListItem inherited;
	
private:
	TdxHashTable* FHashTable;
	int FRefCount;
	unsigned __fastcall GetKey();
	void __fastcall SetHashTable(TdxHashTable* AValue);
	
protected:
	void __fastcall AddToHash(int &AHash, const System::AnsiString AData)/* overload */;
	void __fastcall AddToHash(int &AHash, const System::UnicodeString AData)/* overload */;
	void __fastcall AddToHash(int &AHash, const void *AData, int ADataSize)/* overload */;
	void __fastcall CalculateHash()/* overload */;
	virtual void __fastcall CalculateHash(int &AHash) = 0 /* overload */;
	virtual bool __fastcall DoIsEqual(TdxHashTableItem* const AItem) = 0 ;
	__property TdxHashTable* HashTable = {read=FHashTable, write=SetHashTable};
	
public:
	__fastcall virtual ~TdxHashTableItem();
	void __fastcall AddRef();
	bool __fastcall IsEqual(TdxHashTableItem* const AItem);
	void __fastcall Release();
	__property unsigned Key = {read=GetKey, nodefault};
	__property int RefCount = {read=FRefCount, nodefault};
public:
	/* TdxDynamicListItem.Create */ inline __fastcall virtual TdxHashTableItem(TdxDynamicItemList* AOwner, int AIndex) : TdxDynamicListItem(AOwner, AIndex) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxHashTableItemList : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
protected:
	virtual void __fastcall Notify(void * Ptr, System::Classes::TListNotification Action);
	
public:
	void * __fastcall FirstOrNil();
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxHashTableItemList() { }
	
public:
	/* TObject.Create */ inline __fastcall TdxHashTableItemList() : System::Classes::TList() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static const System::Word dxHashTableSize = System::Word(0xffff);
extern DELPHI_PACKAGE bool __fastcall dxChangeHandle(void *ACurrentValue, TdxHashTableItem* ANewValue);
}	/* namespace Dxhashutils */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXHASHUTILS)
using namespace Dxhashutils;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxhashutilsHPP
