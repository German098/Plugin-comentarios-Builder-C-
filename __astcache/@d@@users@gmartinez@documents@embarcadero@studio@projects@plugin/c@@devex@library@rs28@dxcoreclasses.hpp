// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxCoreClasses.pas' rev: 35.00 (Windows)

#ifndef DxcoreclassesHPP
#define DxcoreclassesHPP

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
#include <System.Generics.Defaults.hpp>
#include <System.Generics.Collections.hpp>
#include <System.ObjAuto.hpp>
#include <System.TypInfo.hpp>
#include <dxCore.hpp>
#include <System.SyncObjs.hpp>

//-- user supplied -----------------------------------------------------------

namespace Dxcoreclasses
{
//-- forward type declarations -----------------------------------------------
__interface DELPHIINTERFACE IcxMouseTrackingCaller;
typedef System::DelphiInterface<IcxMouseTrackingCaller> _di_IcxMouseTrackingCaller;
__interface DELPHIINTERFACE IcxMouseTrackingCaller2;
typedef System::DelphiInterface<IcxMouseTrackingCaller2> _di_IcxMouseTrackingCaller2;
__interface DELPHIINTERFACE IcxMouseTrackingCaller3;
typedef System::DelphiInterface<IcxMouseTrackingCaller3> _di_IcxMouseTrackingCaller3;
class DELPHICLASS TcxIUnknownObject;
class DELPHICLASS TcxInterfacedPersistent;
class DELPHICLASS TcxOwnedPersistent;
class DELPHICLASS TcxOwnedInterfacedPersistent;
class DELPHICLASS TcxLockablePersistent;
class DELPHICLASS TcxLockableComponent;
__interface DELPHIINTERFACE IdxFreeNotify;
typedef System::DelphiInterface<IdxFreeNotify> _di_IdxFreeNotify;
class DELPHICLASS TcxFreeNotificator;
class DELPHICLASS TcxCollection;
class DELPHICLASS TcxDoublyLinkedObject;
class DELPHICLASS TcxDoublyLinkedObjectList;
class DELPHICLASS TcxDoublyLinkedData;
class DELPHICLASS TcxDoublyLinkedDataList;
class DELPHICLASS TcxDoublyLinkedIndexedData;
class DELPHICLASS TcxDoublyLinkedDataIndexedList;
__interface DELPHIINTERFACE TdxListSortCompareDelegate;
typedef System::DelphiInterface<TdxListSortCompareDelegate> _di_TdxListSortCompareDelegate;
class DELPHICLASS TdxFastList;
class DELPHICLASS TdxFastObjectList;
class DELPHICLASS TdxFastThreadList;
template<typename T> __interface DELPHIINTERFACE IdxMulticastMethod__1;
#ifdef __clang__
template<typename T> using _di_IdxMulticastMethod__1 = System::DelphiInterface<IdxMulticastMethod__1<T>>;
#endif
class DELPHICLASS TdxEventHandlerInstance;
class DELPHICLASS TdxMulticastImplementator;
template<typename T> class DELPHICLASS TdxMulticastImplementator__1;
template<typename T> struct TdxMulticastMethod__1;
template<typename T> struct TdxNullableValue__1;
template<typename T> class DELPHICLASS TdxCustomComparer__1;
class DELPHICLASS TdxStringComparer;
class DELPHICLASS TdxIStringComparer;
class DELPHICLASS TdxOrdinalStringComparer;
class DELPHICLASS TdxOrdinalIStringComparer;
class DELPHICLASS TdxMemoryStream;
class DELPHICLASS TdxReadOnlySubStream;
class DELPHICLASS TdxHGlobalReadOnlyStream;
class DELPHICLASS TdxBufferedStream;
class DELPHICLASS TdxRectList;
class DELPHICLASS TdxEventArgs;
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TdxComponentNotificationProc)(System::Classes::TComponent* AComponent, System::Classes::TOperation AOperation);

__interface  INTERFACE_UUID("{84A4BCBE-E001-4D60-B7A6-75E2B0DCD3E9}") IcxMouseTrackingCaller  : public System::IInterface 
{
	virtual void __fastcall MouseLeave() = 0 ;
};

__interface  INTERFACE_UUID("{3A5D973B-F016-4F22-80B6-1D35668D7743}") IcxMouseTrackingCaller2  : public IcxMouseTrackingCaller 
{
	virtual bool __fastcall PtInCaller(const System::Types::TPoint &P) = 0 ;
};

__interface  INTERFACE_UUID("{94877AC7-D2D8-4F2B-8396-DF3CB45E01DF}") IcxMouseTrackingCaller3  : public IcxMouseTrackingCaller2 
{
	virtual bool __fastcall IsCaptureMouse() = 0 ;
};

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxIUnknownObject : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef();
	int __stdcall _Release();
public:
	/* TObject.Create */ inline __fastcall TcxIUnknownObject() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxIUnknownObject() { }
	
private:
	void *__IInterface;	// System::IInterface 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00000000-0000-0000-C000-000000000046}
	operator System::_di_IInterface()
	{
		System::_di_IInterface intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator System::IInterface*(void) { return (System::IInterface*)&__IInterface; }
	#endif
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxInterfacedPersistentClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxInterfacedPersistent : public System::Classes::TInterfacedPersistent
{
	typedef System::Classes::TInterfacedPersistent inherited;
	
private:
	System::Classes::TPersistent* FOwner;
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner();
	
public:
	__fastcall virtual TcxInterfacedPersistent(System::Classes::TPersistent* AOwner);
	__property System::Classes::TPersistent* Owner = {read=FOwner};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxInterfacedPersistent() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxOwnedPersistent : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::Classes::TPersistent* FOwner;
	
protected:
	virtual void __fastcall DoAssign(System::Classes::TPersistent* Source);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner();
	__property System::Classes::TPersistent* Owner = {read=FOwner, write=FOwner};
	
public:
	__fastcall virtual TcxOwnedPersistent(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxOwnedPersistent() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxOwnedInterfacedPersistent : public TcxOwnedPersistent
{
	typedef TcxOwnedPersistent inherited;
	
protected:
	int __stdcall _AddRef();
	int __stdcall _Release();
	virtual HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
public:
	/* TcxOwnedPersistent.Create */ inline __fastcall virtual TcxOwnedInterfacedPersistent(System::Classes::TPersistent* AOwner) : TcxOwnedPersistent(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxOwnedInterfacedPersistent() { }
	
private:
	void *__IInterface;	// System::IInterface 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00000000-0000-0000-C000-000000000046}
	operator System::_di_IInterface()
	{
		System::_di_IInterface intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator System::IInterface*(void) { return (System::IInterface*)&__IInterface; }
	#endif
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxLockablePersistent : public TcxOwnedInterfacedPersistent
{
	typedef TcxOwnedInterfacedPersistent inherited;
	
private:
	bool FHasChanges;
	int FLockCount;
	
protected:
	bool __fastcall IsLocked();
	void __fastcall Changed();
	virtual void __fastcall DoChanged() = 0 ;
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall BeginUpdate();
	void __fastcall CancelUpdate();
	virtual void __fastcall EndUpdate();
public:
	/* TcxOwnedPersistent.Create */ inline __fastcall virtual TcxLockablePersistent(System::Classes::TPersistent* AOwner) : TcxOwnedInterfacedPersistent(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxLockablePersistent() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxLockableComponent : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	bool FHasChanges;
	int FLockCount;
	
protected:
	void __fastcall Changed();
	virtual void __fastcall DoChanged() = 0 ;
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall BeginUpdate();
	void __fastcall CancelUpdate();
	void __fastcall EndUpdate();
public:
	/* TComponent.Create */ inline __fastcall virtual TcxLockableComponent(System::Classes::TComponent* AOwner) : System::Classes::TComponent(AOwner) { }
	/* TComponent.Destroy */ inline __fastcall virtual ~TcxLockableComponent() { }
	
};


__interface  INTERFACE_UUID("{31F91C69-F04C-451D-9091-32FF27BBF3A8}") IdxFreeNotify  : public System::IInterface 
{
	virtual void __fastcall DestroyFreeNotificator() = 0 ;
};

typedef void __fastcall (__closure *TcxFreeNotificationEvent)(System::Classes::TComponent* Sender);

class PASCALIMPLEMENTATION TcxFreeNotificator : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	System::TObject* FMaster;
	TcxFreeNotificationEvent FOnFreeNotification;
	bool __fastcall IsFreeNotifiesExists();
	
protected:
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	void __fastcall Check()/* overload */;
	
public:
	__fastcall TcxFreeNotificator(System::TObject* AMaster);
	void __fastcall AddSender(System::Classes::TComponent* ASender);
	void __fastcall RemoveSender(System::Classes::TComponent* ASender);
	__classmethod void __fastcall Check(TcxFreeNotificator* &AFreeNotificator)/* overload */;
	__property TcxFreeNotificationEvent OnFreeNotification = {read=FOnFreeNotification, write=FOnFreeNotification};
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~TcxFreeNotificator() { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCollection : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
public:
	/* TCollection.Create */ inline __fastcall TcxCollection(System::Classes::TCollectionItemClass ItemClass) : System::Classes::TCollection(ItemClass) { }
	/* TCollection.Destroy */ inline __fastcall virtual ~TcxCollection() { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxDoublyLinkedObjectClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDoublyLinkedObject : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxDoublyLinkedObject* FPrev;
	TcxDoublyLinkedObject* FNext;
	
public:
	__property TcxDoublyLinkedObject* Prev = {read=FPrev, write=FPrev};
	__property TcxDoublyLinkedObject* Next = {read=FNext, write=FNext};
public:
	/* TObject.Create */ inline __fastcall TcxDoublyLinkedObject() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDoublyLinkedObject() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDoublyLinkedObjectList : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int __fastcall GetCount();
	
protected:
	TcxDoublyLinkedObject* FFirst;
	TcxDoublyLinkedObject* FLast;
	virtual TcxDoublyLinkedObject* __fastcall CreateLinkedObject();
	virtual void __fastcall DoAdd(TcxDoublyLinkedObject* ASource);
	virtual TcxDoublyLinkedObjectClass __fastcall GetLinkedObjectClass();
	
public:
	__fastcall virtual ~TcxDoublyLinkedObjectList();
	virtual TcxDoublyLinkedObject* __fastcall Add();
	virtual void __fastcall Clear();
	void __fastcall InsertBefore(TcxDoublyLinkedObject* ADestination, TcxDoublyLinkedObject* ASource);
	void __fastcall InsertAfter(TcxDoublyLinkedObject* ADestination, TcxDoublyLinkedObject* ASource);
	virtual void __fastcall Delete(TcxDoublyLinkedObject* ALinkedObject);
	virtual void __fastcall Extract(TcxDoublyLinkedObject* ALinkedObject);
	virtual void __fastcall Remove(TcxDoublyLinkedObject* ALinkedObject);
	__property TcxDoublyLinkedObject* First = {read=FFirst};
	__property TcxDoublyLinkedObject* Last = {read=FLast};
	__property int Count = {read=GetCount, nodefault};
public:
	/* TObject.Create */ inline __fastcall TcxDoublyLinkedObjectList() : System::TObject() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDoublyLinkedData : public TcxDoublyLinkedObject
{
	typedef TcxDoublyLinkedObject inherited;
	
private:
	void *FData;
	TcxDoublyLinkedData* FNextSorted;
	TcxDoublyLinkedData* FPrevSorted;
	
public:
	__property void * Data = {read=FData, write=FData};
public:
	/* TObject.Create */ inline __fastcall TcxDoublyLinkedData() : TcxDoublyLinkedObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDoublyLinkedData() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDoublyLinkedDataList : public TcxDoublyLinkedObjectList
{
	typedef TcxDoublyLinkedObjectList inherited;
	
public:
	HIDESBASE TcxDoublyLinkedData* __fastcall Add(void * AData);
	virtual TcxDoublyLinkedObjectClass __fastcall GetLinkedObjectClass();
	virtual void __fastcall PopulateFromList(System::Classes::TList* AList);
	virtual void __fastcall PopulateToList(System::Classes::TList* AList);
	void __fastcall Sort(System::Classes::TListSortCompare ACompareProc);
public:
	/* TcxDoublyLinkedObjectList.Destroy */ inline __fastcall virtual ~TcxDoublyLinkedDataList() { }
	
public:
	/* TObject.Create */ inline __fastcall TcxDoublyLinkedDataList() : TcxDoublyLinkedObjectList() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDoublyLinkedIndexedData : public TcxDoublyLinkedData
{
	typedef TcxDoublyLinkedData inherited;
	
private:
	int FIndex;
	
public:
	__property int Index = {read=FIndex, write=FIndex, nodefault};
public:
	/* TObject.Create */ inline __fastcall TcxDoublyLinkedIndexedData() : TcxDoublyLinkedData() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDoublyLinkedIndexedData() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDoublyLinkedDataIndexedList : public TcxDoublyLinkedDataList
{
	typedef TcxDoublyLinkedDataList inherited;
	
public:
	HIDESBASE TcxDoublyLinkedIndexedData* __fastcall Add(void * AData, int AIndex);
	virtual TcxDoublyLinkedObjectClass __fastcall GetLinkedObjectClass();
	virtual void __fastcall PopulateFromList(System::Classes::TList* AList);
public:
	/* TcxDoublyLinkedObjectList.Destroy */ inline __fastcall virtual ~TcxDoublyLinkedDataIndexedList() { }
	
public:
	/* TObject.Create */ inline __fastcall TcxDoublyLinkedDataIndexedList() : TcxDoublyLinkedDataList() { }
	
};

#pragma pack(pop)

typedef System::StaticArray<void *, 1> TdxPointerList;

typedef TdxPointerList *PdxPointerList;

typedef int __fastcall (__closure *TCompareItems)(void * AItem1, void * AItem2);

__interface TdxListSortCompareDelegate  : public System::IInterface 
{
	virtual int __fastcall Invoke(void * Item1, void * Item2) = 0 ;
};

enum DECLSPEC_DENUM TdxListDirection : unsigned char { ldFromBeginning, ldFromEnd };

typedef int __fastcall (*TdxStringCompareProc)(const System::UnicodeString AValue1, const System::UnicodeString AValue2);

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFastList : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	void * operator[](int Index) { return this->Items[Index]; }
	
private:
	int FCapacity;
	int FCount;
	TdxPointerList *FList;
	void __fastcall DoDelete(int AIndex);
	
protected:
	void __fastcall CheckDeleteRange(int AIndex, int ACount);
	void __fastcall DoDeleteRange(int AIndex, int ACount);
	void * __fastcall GetItem(int AIndex);
	void __fastcall Grow();
	void __fastcall SetCapacity(int AValue);
	virtual void __fastcall SetCount(int AValue);
	void __fastcall SetItem(int AIndex, void * AItem);
	
public:
	__fastcall TdxFastList(int ACapacity);
	__fastcall virtual ~TdxFastList();
	int __fastcall Add(void * AItem);
	void __fastcall AddRange(TdxFastList* AList);
	void __fastcall Assign(TdxFastList* ASource)/* overload */;
	void __fastcall Assign(System::Classes::TList* ASource)/* overload */;
	void __fastcall Assign(TdxFastList* ASource, System::Classes::TListAssignOp AOperator)/* overload */;
	virtual void __fastcall Clear();
	void __fastcall Delete(int AIndex);
	void __fastcall DeleteRange(int AIndex, int ACount);
	bool __fastcall Empty();
	void __fastcall Exchange(int AIndex1, int AIndex2);
	TdxFastList* __fastcall Expand();
	void * __fastcall Extract(void * AItem, TdxListDirection ADirection = (TdxListDirection)(0x0));
	void * __fastcall ExtractByIndex(int AIndex);
	void * __fastcall First();
	System::Classes::TList* __fastcall GetTList();
	int __fastcall IndexOf(void * AItem, TdxListDirection ADirection = (TdxListDirection)(0x0));
	void __fastcall Insert(int AIndex, void * AItem)/* overload */;
	void __fastcall Insert _DEPRECATED_ATTRIBUTE0 (int AIndex, TdxFastList* AList)/* overload */;
	void __fastcall InsertRange(int AIndex, TdxFastList* AList);
	void * __fastcall Last();
	void __fastcall Move(int ACurrentIndex, int ANewIndex);
	void __fastcall Pack(void * APattern = (void *)(0x0));
	int __fastcall Remove(void * AItem);
	void __fastcall Reverse();
	void __fastcall Sort(TCompareItems ACompare, bool AMultiThreaded = false)/* overload */;
	void __fastcall Sort(System::Classes::TListSortCompare ACompare, bool AMultiThreaded = false)/* overload */;
	void __fastcall SortList(const _di_TdxListSortCompareDelegate ACompare, bool AMultiThreaded = false);
	__property int Capacity = {read=FCapacity, write=SetCapacity, nodefault};
	__property int Count = {read=FCount, write=SetCount, nodefault};
	__property void * Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
	__property PdxPointerList List = {read=FList};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFastObjectList : public TdxFastList
{
	typedef TdxFastList inherited;
	
public:
	System::TObject* operator[](int Index) { return this->Items[Index]; }
	
private:
	bool FOwnsObjects;
	
protected:
	HIDESBASE System::TObject* __fastcall GetItem(int AIndex);
	HIDESBASE void __fastcall SetItem(int AIndex, System::TObject* AObject);
	virtual void __fastcall SetCount(int AValue);
	
public:
	__fastcall TdxFastObjectList(bool AOwnsObjects, int ACapacity);
	HIDESBASE int __fastcall Add(System::TObject* AObject);
	virtual void __fastcall Clear();
	HIDESBASE void __fastcall Delete(int AIndex);
	HIDESBASE void __fastcall DeleteRange(int AIndex, int ACount);
	HIDESBASE System::TObject* __fastcall Extract(System::TObject* AItem);
	void __fastcall ExtractRange(int AIndex, int ACount);
	HIDESBASE int __fastcall Remove(System::TObject* AObject);
	HIDESBASE int __fastcall IndexOf(System::TObject* AObject, TdxListDirection ADirection = (TdxListDirection)(0x0));
	HIDESBASE void __fastcall Insert(int AIndex, System::TObject* AObject);
	HIDESBASE System::TObject* __fastcall First();
	HIDESBASE System::TObject* __fastcall Last();
	__property bool OwnsObjects = {read=FOwnsObjects, write=FOwnsObjects, nodefault};
	__property System::TObject* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TdxFastList.Destroy */ inline __fastcall virtual ~TdxFastObjectList() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFastThreadList : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxFastList* FList;
	System::TObject* FLock;
	int __fastcall GetCount();
	
public:
	__fastcall TdxFastThreadList();
	__fastcall virtual ~TdxFastThreadList();
	void __fastcall Add(void * Item);
	void __fastcall Clear();
	TdxFastList* __fastcall LockList();
	void __fastcall Remove(void * Item);
	void __fastcall UnlockList();
	__property int Count = {read=GetCount, nodefault};
};

#pragma pack(pop)

// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename T> __interface  INTERFACE_UUID("{BCD2B104-F540-4470-B0E9-5A15EAF6FE71}") IdxMulticastMethod__1  : public System::IInterface 
{
	virtual T __fastcall GetInvoke() = 0 ;
	virtual void __fastcall Add(const T AMethod) = 0 /* overload */;
	virtual void __fastcall Clear() = 0 ;
	virtual int __fastcall GetCount() = 0 ;
	virtual void __fastcall Remove(const T AMethod) = 0 /* overload */;
	__property int Count = {read=GetCount};
	__property T Invoke = {read=GetInvoke};
};

class PASCALIMPLEMENTATION TdxEventHandlerInstance : public System::TObject
{
	typedef System::TObject inherited;
	
	
private:
	typedef System::StaticArray<System::Typinfo::PTypeInfo*, 256> TParameterInfos;
	
	typedef TParameterInfos *PParameterInfos;
	
	
private:
	int __fastcall GetTypeSize(System::Typinfo::PTypeInfo ATypeInfo);
	static void * __fastcall GetMethodAdditionalInfo(System::Typinfo::PTypeData ATypeData);
	static void __fastcall NextParameter(System::PByte &P);
	
protected:
	TParameterInfos *FParamInfos;
	int FStackSize;
	System::Objauto::TDynamicInvokeEvent FDynamicInvokeEvent;
	void __fastcall InternalHandler(void * AParams);
	virtual void __fastcall Handler(void * AParams);
	void __fastcall RegisterStub();
	
public:
	__fastcall TdxEventHandlerInstance(const System::Objauto::TDynamicInvokeEvent ADynamicInvokeEvent, System::Typinfo::PTypeData ATypeData);
	static System::TMethod __fastcall CreateMethodPointer(const System::Objauto::TDynamicInvokeEvent ADynamicInvokeEvent, System::Typinfo::PTypeData ATypeData);
	static System::Typinfo::TCallConv __fastcall GetMethodCallingConvention(System::Typinfo::PTypeData ATypeData);
	static void * __fastcall GetMethodParametersTypeInfo(System::Typinfo::PTypeData ATypeData);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxEventHandlerInstance() { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxMulticastImplementator : public System::TInterfacedObject
{
	typedef System::TInterfacedObject inherited;
	
	
private:
	typedef System::DynamicArray<System::TMethod> _TdxMulticastImplementator__1;
	
	
private:
	System::Syncobjs::TCriticalSection* FLock;
	_TdxMulticastImplementator__1 FHandlers;
	System::TMethod FInternalDispatcher;
	static void __fastcall InvokeMethod(const System::TMethod &AMethod, void * AParams, int AStackSize);
	void __fastcall InternalInvoke(System::Objauto::PParameters AParams, int AStackSize);
	
protected:
	int __fastcall GetCount();
	void __fastcall InternalClear();
	void __fastcall InternalAdd(const void *AValue);
	void __fastcall InternalRemove(const void *AValue);
	void __fastcall InternalSetDispatcher(void *ADispatcher, System::Typinfo::PTypeData ATypeData);
	
public:
	__fastcall TdxMulticastImplementator();
	__fastcall virtual ~TdxMulticastImplementator();
};

#pragma pack(pop)

#pragma pack(push,4)
// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename T> class PASCALIMPLEMENTATION TdxMulticastImplementator__1 : public TdxMulticastImplementator
{
	typedef TdxMulticastImplementator inherited;
	
private:
	T FInvoke;
	T __fastcall GetInvoke();
	void __fastcall SetEventDispatcher(T &ADispatcher, System::Typinfo::PTypeData ATypeData);
	
public:
	__fastcall TdxMulticastImplementator__1();
	void __fastcall Add(const T AMethod);
	void __fastcall Remove(const T AMethod);
	void __fastcall Clear();
	__property T Invoke = {read=FInvoke};
public:
	/* TdxMulticastImplementator.Destroy */ inline __fastcall virtual ~TdxMulticastImplementator__1() { }
	
private:
	void *__IdxMulticastMethod__1;	// IdxMulticastMethod__1<T> 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {BCD2B104-F540-4470-B0E9-5A15EAF6FE71}
	operator System::DelphiInterface<IdxMulticastMethod__1<T> >()
	{
		System::DelphiInterface<IdxMulticastMethod__1<T> > intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IdxMulticastMethod__1<T>*(void) { return (IdxMulticastMethod__1<T>*)&__IdxMulticastMethod__1; }
	#endif
	
};

#pragma pack(pop)

// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename T> struct DECLSPEC_DRECORD TdxMulticastMethod__1
{
private:
	System::DelphiInterface<IdxMulticastMethod__1<T> > FImplementator;
	int __fastcall GetCount();
	bool __fastcall GetEmpty();
	T __fastcall GetInvoke();
	void __fastcall Validate();
	
public:
	void __fastcall Add(const T AMethod);
	void __fastcall Remove(const T AMethod);
	void __fastcall Clear();
	TdxMulticastMethod__1<T> __fastcall Clone();
	__property int Count = {read=GetCount};
	__property bool Empty = {read=GetEmpty};
	__property T Invoke = {read=GetInvoke};
};


typedef TdxMulticastMethod__1<System::Classes::TNotifyEvent> TdxNotifyEventHandler;

#pragma pack(push,1)
// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename T> struct DECLSPEC_DRECORD TdxNullableValue__1
{
private:
	System::LongBool FHasValue;
	T FValue;
	bool __fastcall GetHasValue();
	bool __fastcall GetIsNull();
	T __fastcall GetValue();
	void __fastcall SetValue(const T Value);
	static TdxNullableValue__1<T> __fastcall GetNull();
	
public:
	__fastcall TdxNullableValue__1(bool AUse, const T AValue)/* overload */;
	void __fastcall Reset();
	__fastcall operator TdxNullableValue__1<T>();
	__fastcall operator T();
	// explicit __fastcall operator T();
	static bool __fastcall _op_Equality(const TdxNullableValue__1<T> &A, const TdxNullableValue__1<T> &B);
	static bool __fastcall _op_Equality(const TdxNullableValue__1<T> &A, const T B);
	static bool __fastcall _op_GreaterThan(const TdxNullableValue__1<T> &A, const T B);
	static bool __fastcall _op_LessThan(const TdxNullableValue__1<T> &A, const T B);
	static TdxNullableValue__1<T> __fastcall _op_LogicalAnd(const TdxNullableValue__1<T> &A, const TdxNullableValue__1<T> &B);
	static TdxNullableValue__1<T> __fastcall _op_LogicalNot(const TdxNullableValue__1<T> &A);
	static TdxNullableValue__1<T> __fastcall _op_LogicalOr(const TdxNullableValue__1<T> &A, const TdxNullableValue__1<T> &B);
	static bool __fastcall _op_Inequality(const TdxNullableValue__1<T> &A, const TdxNullableValue__1<T> &B);
	static bool __fastcall _op_Inequality(const TdxNullableValue__1<T> &A, const T B);
	static TdxNullableValue__1<T> __fastcall IfThen(bool AValue, const TdxNullableValue__1<T> &ATrue, const TdxNullableValue__1<T> &AFalse)/* overload */;
	static TdxNullableValue__1<T> __fastcall IfThen(bool AValue, const TdxNullableValue__1<T> &ATrue)/* overload */;
	static TdxNullableValue__1<T> __fastcall IfThen(bool AValue, const T ATrue, const T AFalse)/* overload */;
	static TdxNullableValue__1<T> __fastcall IfThen(bool AValue, const T ATrue)/* overload */;
	bool __fastcall IsNullOrEmpty();
	__property bool HasValue = {read=GetHasValue};
	__property bool IsNull = {read=GetIsNull};
	__property T Value = {read=GetValue, write=SetValue};
	/* static */ __property TdxNullableValue__1<T> Null = {read=GetNull};
	TdxNullableValue__1() {}
	
	friend bool operator ==(const TdxNullableValue__1<T> &A, const TdxNullableValue__1<T> &B) { return TdxNullableValue__1::_op_Equality(A, B); }
	friend bool operator ==(const TdxNullableValue__1<T> &A, const T B) { return TdxNullableValue__1::_op_Equality(A, B); }
	friend bool operator >(const TdxNullableValue__1<T> &A, const T B) { return TdxNullableValue__1::_op_GreaterThan(A, B); }
	friend bool operator <(const TdxNullableValue__1<T> &A, const T B) { return TdxNullableValue__1::_op_LessThan(A, B); }
	friend TdxNullableValue__1<T> operator &&(const TdxNullableValue__1<T> &A, const TdxNullableValue__1<T> &B) { return TdxNullableValue__1::_op_LogicalAnd(A, B); }
	friend TdxNullableValue__1<T> operator ||(const TdxNullableValue__1<T> &A, const TdxNullableValue__1<T> &B) { return TdxNullableValue__1::_op_LogicalOr(A, B); }
	friend bool operator !=(const TdxNullableValue__1<T> &A, const TdxNullableValue__1<T> &B) { return TdxNullableValue__1::_op_Inequality(A, B); }
	friend bool operator !=(const TdxNullableValue__1<T> &A, const T B) { return TdxNullableValue__1::_op_Inequality(A, B); }
};
#pragma pack(pop)


typedef TdxNullableValue__1<bool> TdxNullableBoolean;

typedef TdxNullableValue__1<System::UnicodeString> TdxNullableString;

typedef TdxNullableValue__1<System::Byte> TdxNullableByte;

typedef TdxNullableValue__1<System::Int8> TdxNullableShortInt;

typedef TdxNullableValue__1<short> TdxNullableSmallInt;

typedef TdxNullableValue__1<System::Word> TdxNullableWord;

typedef TdxNullableValue__1<int> TdxNullableInteger;

typedef TdxNullableValue__1<__int64> TdxNullableInt64;

typedef TdxNullableValue__1<float> TdxNullableSingle;

typedef TdxNullableValue__1<double> TdxNullableDouble;

typedef TdxNullableValue__1<System::Currency> TdxNullableCurrency;

typedef TdxNullableValue__1<System::TDateTime> TdxNullableDateTime;

typedef TdxNullableValue__1<System::TDate> TdxNullableDate;

typedef TdxNullableValue__1<System::TTime> TdxNullableTime;

typedef TdxNullableValue__1<GUID> TdxNullableGUID;

typedef TdxNullableValue__1<System::Types::TRect> TdxNullableRect;

#pragma pack(push,4)
// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename T> class PASCALIMPLEMENTATION TdxCustomComparer__1 : public System::TInterfacedObject
{
	typedef System::TInterfacedObject inherited;
	
public:
	virtual int __fastcall Compare(const T Left, const T Right) = 0 ;
	HIDESBASE virtual bool __fastcall Equals(const T ALeft, const T ARight) = 0 ;
	HIDESBASE virtual int __fastcall GetHashCode(const T AValue) = 0 ;
public:
	/* TObject.Create */ inline __fastcall TdxCustomComparer__1() : System::TInterfacedObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxCustomComparer__1() { }
	
private:
	void *__IComparer__1;	// System::Generics::Defaults::IComparer__1<T> 
	void *__IEqualityComparer__1;	// System::Generics::Defaults::IEqualityComparer__1<T> 
	
public:
	operator System::Generics::Defaults::IComparer__1<T>*(void) { return (System::Generics::Defaults::IComparer__1<T>*)&__IComparer__1; }
	operator System::Generics::Defaults::IEqualityComparer__1<T>*(void) { return (System::Generics::Defaults::IEqualityComparer__1<T>*)&__IEqualityComparer__1; }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxStringComparer : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	static TdxCustomComparer__1<System::UnicodeString>* FOrdinal;
	
protected:
	__classmethod void __fastcall Finalize();
	
public:
	__classmethod TdxCustomComparer__1<System::UnicodeString>* __fastcall Ordinal();
public:
	/* TObject.Create */ inline __fastcall TdxStringComparer() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxStringComparer() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxIStringComparer : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	static TdxCustomComparer__1<System::UnicodeString>* FOrdinal;
	
protected:
	__classmethod void __fastcall Finalize();
	
public:
	__classmethod TdxCustomComparer__1<System::UnicodeString>* __fastcall Ordinal();
public:
	/* TObject.Create */ inline __fastcall TdxIStringComparer() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxIStringComparer() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxOrdinalStringComparer : public TdxCustomComparer__1<System::UnicodeString>
{
	typedef TdxCustomComparer__1<System::UnicodeString> inherited;
	
public:
	virtual int __fastcall Compare(const System::UnicodeString ALeft, const System::UnicodeString ARight);
	virtual bool __fastcall Equals(const System::UnicodeString ALeft, const System::UnicodeString ARight);
	virtual int __fastcall GetHashCode(const System::UnicodeString AValue);
public:
	/* TObject.Create */ inline __fastcall TdxOrdinalStringComparer() : TdxCustomComparer__1<System::UnicodeString>() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxOrdinalStringComparer() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxOrdinalIStringComparer : public TdxOrdinalStringComparer
{
	typedef TdxOrdinalStringComparer inherited;
	
public:
	virtual int __fastcall Compare(const System::UnicodeString Left, const System::UnicodeString Right);
	virtual bool __fastcall Equals(const System::UnicodeString ALeft, const System::UnicodeString ARight);
	virtual int __fastcall GetHashCode(const System::UnicodeString AValue);
public:
	/* TObject.Create */ inline __fastcall TdxOrdinalIStringComparer() : TdxOrdinalStringComparer() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxOrdinalIStringComparer() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxMemoryStream : public System::Classes::TMemoryStream
{
	typedef System::Classes::TMemoryStream inherited;
	
protected:
	virtual void * __fastcall Realloc(NativeInt &NewCapacity);
	
public:
	__fastcall TdxMemoryStream(const System::UnicodeString AFileName, System::Word AMode)/* overload */;
	__fastcall TdxMemoryStream(const System::DynamicArray<System::Byte> AContent)/* overload */;
	__fastcall TdxMemoryStream(const System::DynamicArray<System::Byte> AContent, int ACount)/* overload */;
	__fastcall TdxMemoryStream(const System::DynamicArray<System::Byte> AContent, int AOffset, int ACount)/* overload */;
	HIDESBASE void __fastcall LoadFromFile(const System::UnicodeString AFileName)/* overload */;
	HIDESBASE void __fastcall LoadFromFile(const System::UnicodeString AFileName, System::Word AMode)/* overload */;
	System::Byte __fastcall ReadByte();
	int __fastcall ReadInteger();
	void __fastcall WriteByte(const System::Byte Value);
	void __fastcall WriteByteArray(const System::DynamicArray<System::Byte> Value);
	void __fastcall WriteInteger(const int Value);
	System::DynamicArray<System::Byte> __fastcall ToArray();
public:
	/* TMemoryStream.Destroy */ inline __fastcall virtual ~TdxMemoryStream() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TdxReadOnlySubStream : public System::Classes::TStream
{
	typedef System::Classes::TStream inherited;
	
private:
	__int64 FOffset;
	__int64 FPosition;
	__int64 FSize;
	System::Classes::TStream* FSource;
	System::Classes::TStreamOwnership FSourceOwnership;
	
protected:
	virtual __int64 __fastcall GetSize();
	virtual void __fastcall SetSize(const __int64 NewSize)/* overload */;
	
public:
	__fastcall TdxReadOnlySubStream(System::Classes::TStream* ASource, const __int64 AOffset, const __int64 ASize, System::Classes::TStreamOwnership ASourceOwnership);
	__fastcall virtual ~TdxReadOnlySubStream();
	virtual int __fastcall Read(void *Buffer, int Count)/* overload */;
	virtual __int64 __fastcall Seek(const __int64 Offset, System::Classes::TSeekOrigin Origin)/* overload */;
	virtual int __fastcall Write(const void *Buffer, int Count)/* overload */;
	__property __int64 Offset = {read=FOffset};
	__property __int64 Size = {read=FSize};
	/* Hoisted overloads: */
	
protected:
	inline void __fastcall  SetSize _DEPRECATED_ATTRIBUTE0 (int NewSize){ System::Classes::TStream::SetSize(NewSize); }
	
public:
	inline int __fastcall  Read(System::DynamicArray<System::Byte> Buffer, int Offset, int Count){ return System::Classes::TStream::Read(Buffer, Offset, Count); }
	inline int __fastcall  Read(System::DynamicArray<System::Byte> &Buffer, int Count){ return System::Classes::TStream::Read(Buffer, Count); }
	inline int __fastcall  Seek(int Offset, System::Word Origin){ return System::Classes::TStream::Seek(Offset, Origin); }
	inline __int64 __fastcall  Seek(const __int64 Offset, System::Word Origin){ return System::Classes::TStream::Seek(Offset, Origin); }
	inline int __fastcall  Write(const System::DynamicArray<System::Byte> Buffer, int Offset, int Count){ return System::Classes::TStream::Write(Buffer, Offset, Count); }
	inline int __fastcall  Write(const System::DynamicArray<System::Byte> Buffer, int Count){ return System::Classes::TStream::Write(Buffer, Count); }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxHGlobalReadOnlyStream : public System::Classes::TCustomMemoryStream
{
	typedef System::Classes::TCustomMemoryStream inherited;
	
private:
	NativeUInt FData;
	System::Classes::TStreamOwnership FDataOwnership;
	
protected:
	virtual void __fastcall SetSize(const __int64 NewSize)/* overload */;
	
public:
	__fastcall TdxHGlobalReadOnlyStream(NativeUInt AData, System::Classes::TStreamOwnership ADataOwnership);
	__fastcall virtual ~TdxHGlobalReadOnlyStream();
	virtual int __fastcall Write(const void *Buffer, int Count)/* overload */;
	/* Hoisted overloads: */
	
protected:
	inline void __fastcall  SetSize _DEPRECATED_ATTRIBUTE0 (int NewSize){ System::Classes::TStream::SetSize(NewSize); }
	
public:
	inline int __fastcall  Write(const System::DynamicArray<System::Byte> Buffer, int Offset, int Count){ return System::Classes::TStream::Write(Buffer, Offset, Count); }
	inline int __fastcall  Write(const System::DynamicArray<System::Byte> Buffer, int Count){ return System::Classes::TStream::Write(Buffer, Count); }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TdxBufferedStream : public System::Classes::TStream
{
	typedef System::Classes::TStream inherited;
	
private:
	System::Byte *FBuffer;
	__int64 FBufferAllocationBase;
	bool FBufferModified;
	__int64 FBufferPosition;
	int FBufferSize;
	int FBufferUsed;
	System::Classes::TStream* FSource;
	System::Classes::TStreamOwnership FSourceOwnership;
	void __fastcall BufferCheckSaveChanges();
	void __fastcall BufferFinalize();
	void __fastcall BufferInitialize(int ABufferSize);
	void __fastcall BufferNextBlock();
	
protected:
	virtual __int64 __fastcall GetSize();
	virtual void __fastcall SetSize(const __int64 NewSize)/* overload */;
	__property System::Classes::TStream* SourceStream = {read=FSource};
	
public:
	__fastcall TdxBufferedStream(System::Classes::TStream* const ASource, System::Classes::TStreamOwnership AOwnership, int ABufferSize)/* overload */;
	__fastcall TdxBufferedStream(const System::UnicodeString AFileName, System::Word AAccessMode, int ABufferSize)/* overload */;
	__fastcall virtual ~TdxBufferedStream();
	virtual int __fastcall Read(void *Buffer, int Count)/* overload */;
	virtual __int64 __fastcall Seek(const __int64 Offset, System::Classes::TSeekOrigin Origin)/* overload */;
	virtual int __fastcall Write(const void *Buffer, int Count)/* overload */;
	virtual int __fastcall Read(System::DynamicArray<System::Byte> Buffer, int Offset, int Count)/* overload */ _FINAL_ATTRIBUTE;
	virtual int __fastcall Write(const System::DynamicArray<System::Byte> Buffer, int Offset, int Count)/* overload */ _FINAL_ATTRIBUTE;
	__property int BufferSize = {read=FBufferSize, nodefault};
	/* Hoisted overloads: */
	
protected:
	inline void __fastcall  SetSize _DEPRECATED_ATTRIBUTE0 (int NewSize){ System::Classes::TStream::SetSize(NewSize); }
	
public:
	inline int __fastcall  Read(System::DynamicArray<System::Byte> &Buffer, int Count){ return System::Classes::TStream::Read(Buffer, Count); }
	inline int __fastcall  Seek(int Offset, System::Word Origin){ return System::Classes::TStream::Seek(Offset, Origin); }
	inline __int64 __fastcall  Seek(const __int64 Offset, System::Word Origin){ return System::Classes::TStream::Seek(Offset, Origin); }
	inline int __fastcall  Write(const System::DynamicArray<System::Byte> Buffer, int Count){ return System::Classes::TStream::Write(Buffer, Count); }
	
};


class PASCALIMPLEMENTATION TdxRectList : public System::Generics::Collections::TList__1<System::Types::TRect>
{
	typedef System::Generics::Collections::TList__1<System::Types::TRect> inherited;
	
public:
	void __fastcall Offset(int X, int Y);
	System::Types::TRect __fastcall Union();
public:
	/* {System_Generics_Collections}TList<System_Types_TRect>.Create */ inline __fastcall TdxRectList()/* overload */ : System::Generics::Collections::TList__1<System::Types::TRect>() { }
	/* {System_Generics_Collections}TList<System_Types_TRect>.Create */ inline __fastcall TdxRectList(const System::DelphiInterface<System::Generics::Defaults::IComparer__1<System::Types::TRect> > AComparer)/* overload */ : System::Generics::Collections::TList__1<System::Types::TRect>(AComparer) { }
	/* {System_Generics_Collections}TList<System_Types_TRect>.Create */ inline __fastcall TdxRectList(System::Generics::Collections::TEnumerable__1<System::Types::TRect>* const Collection)/* overload */ : System::Generics::Collections::TList__1<System::Types::TRect>(Collection) { }
	/* {System_Generics_Collections}TList<System_Types_TRect>.Create */ inline __fastcall TdxRectList(const System::Types::TRect *Values, const int Values_High)/* overload */ : System::Generics::Collections::TList__1<System::Types::TRect>(Values, Values_High) { }
	/* {System_Generics_Collections}TList<System_Types_TRect>.Destroy */ inline __fastcall virtual ~TdxRectList() { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxEventArgs : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod TdxEventArgs* __fastcall Empty();
public:
	/* TObject.Create */ inline __fastcall TdxEventArgs() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxEventArgs() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static const HRESULT cxE_NOINTERFACE = HRESULT(-2147467262);
extern DELPHI_PACKAGE void __fastcall dxQuickSortList(System::Classes::TList* AList, TCompareItems ACompareFunc, bool AMultiThreaded = false)/* overload */;
extern DELPHI_PACKAGE void __fastcall dxQuickSortList(PdxPointerList ASortList, int ACount, TCompareItems ACompareFunc, bool AMultiThreaded = false)/* overload */;
extern DELPHI_PACKAGE void __fastcall dxInternalQuickSortList(PdxPointerList ASortList, int ACount, TCompareItems ACompareFunc)/* overload */;
extern DELPHI_PACKAGE void __fastcall dxQuickSortList(System::Classes::TList* AList, System::Classes::TListSortCompare ACompareFunc, bool AMultiThreaded = false)/* overload */;
extern DELPHI_PACKAGE void __fastcall dxQuickSortList(PdxPointerList ASortList, int ACount, System::Classes::TListSortCompare ACompareFunc, bool AMultiThreaded = false)/* overload */;
extern DELPHI_PACKAGE void __fastcall dxInternalQuickSortList(PdxPointerList ASortList, int ACount, System::Classes::TListSortCompare ACompareFunc)/* overload */;
extern DELPHI_PACKAGE void __fastcall dxInternalQuickSortList2(PdxPointerList ASortList, int ACount, const _di_TdxListSortCompareDelegate ACompareDelegate);
extern DELPHI_PACKAGE void __fastcall dxLiaisonSort(System::Classes::TList* AList, System::Classes::TListSortCompare ACompareProc = 0x0);
}	/* namespace Dxcoreclasses */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXCORECLASSES)
using namespace Dxcoreclasses;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxcoreclassesHPP
