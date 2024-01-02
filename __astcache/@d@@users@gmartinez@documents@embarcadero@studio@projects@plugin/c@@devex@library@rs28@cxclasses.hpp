// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxClasses.pas' rev: 35.00 (Windows)

#ifndef CxclassesHPP
#define CxclassesHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Types.hpp>
#include <Winapi.Windows.hpp>
#include <Winapi.Messages.hpp>
#include <Winapi.ShellAPI.hpp>
#include <System.TypInfo.hpp>
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Controls.hpp>
#include <System.IniFiles.hpp>
#include <System.Contnrs.hpp>
#include <System.SyncObjs.hpp>
#include <dxCore.hpp>
#include <dxCoreClasses.hpp>
#include <dxMessages.hpp>
#include <cxGeometry.hpp>
#include <dxGenerics.hpp>
#include <System.Generics.Collections.hpp>
#include <System.Generics.Defaults.hpp>

//-- user supplied -----------------------------------------------------------

namespace Cxclasses
{
//-- forward type declarations -----------------------------------------------
__interface DELPHIINTERFACE IcxDesignSelectionChanged;
typedef System::DelphiInterface<IcxDesignSelectionChanged> _di_IcxDesignSelectionChanged;
__interface DELPHIINTERFACE IcxDesignHelper;
typedef System::DelphiInterface<IcxDesignHelper> _di_IcxDesignHelper;
__interface DELPHIINTERFACE IcxDesignHelper2;
typedef System::DelphiInterface<IcxDesignHelper2> _di_IcxDesignHelper2;
__interface DELPHIINTERFACE IdxManager;
typedef System::DelphiInterface<IdxManager> _di_IdxManager;
__interface DELPHIINTERFACE IdxManagedObject;
typedef System::DelphiInterface<IdxManagedObject> _di_IdxManagedObject;
__interface DELPHIINTERFACE IdxAdornerRootTargetElement;
typedef System::DelphiInterface<IdxAdornerRootTargetElement> _di_IdxAdornerRootTargetElement;
__interface DELPHIINTERFACE IdxAdornerTargetElement;
typedef System::DelphiInterface<IdxAdornerTargetElement> _di_IdxAdornerTargetElement;
__interface DELPHIINTERFACE IdxAdornerTargetElementCollection;
typedef System::DelphiInterface<IdxAdornerTargetElementCollection> _di_IdxAdornerTargetElementCollection;
class DELPHICLASS TcxCustomComponent;
class DELPHICLASS TcxComponent;
class DELPHICLASS TcxComponentHolder;
class DELPHICLASS TcxTimer;
__interface DELPHIINTERFACE IcxScalableComponent;
typedef System::DelphiInterface<IcxScalableComponent> _di_IcxScalableComponent;
class DELPHICLASS TcxScalableComponent;
class DELPHICLASS TcxInterfacedCollectionItem;
class DELPHICLASS TcxHashedStringList;
class DELPHICLASS TcxOwnedInterfacedCollection;
class DELPHICLASS TcxObjectList;
class DELPHICLASS TcxEventHandlerCollection;
class DELPHICLASS TcxRegisteredClassListItemData;
class DELPHICLASS TcxRegisteredClassList;
class DELPHICLASS TcxRegisteredClasses;
class DELPHICLASS TcxAutoWidthItem;
class DELPHICLASS TcxAutoWidthObject;
class DELPHICLASS TcxAlignment;
class DELPHICLASS TcxObjectLink;
class DELPHICLASS TcxObjectLinkController;
class DELPHICLASS TcxMRUItem;
class DELPHICLASS TcxMRUItems;
class DELPHICLASS TcxOpenList;
class DELPHICLASS TcxComponentCollectionItem;
class DELPHICLASS TcxComponentCollection;
class DELPHICLASS TcxInterfacedComponentCollection;
__interface DELPHIINTERFACE IcxDialogMetricsInfoData;
typedef System::DelphiInterface<IcxDialogMetricsInfoData> _di_IcxDialogMetricsInfoData;
__interface DELPHIINTERFACE IcxDialogMetricsClientSize;
typedef System::DelphiInterface<IcxDialogMetricsClientSize> _di_IcxDialogMetricsClientSize;
class DELPHICLASS TcxDialogMetricsInfo;
class DELPHICLASS TcxDialogsMetricsStore;
class DELPHICLASS TcxEvent;
class DELPHICLASS TcxCustomThread;
class DELPHICLASS TcxThread;
class DELPHICLASS TcxComponentList;
class DELPHICLASS TcxCustomProgressCalculationHelper;
class DELPHICLASS TdxMemIniFile;
__interface DELPHIINTERFACE IcxProgress;
typedef System::DelphiInterface<IcxProgress> _di_IcxProgress;
class DELPHICLASS TcxProgressCalculationHelper;
struct TcxLangRec;
class DELPHICLASS TdxLanguages;
class DELPHICLASS TdxLanguageID;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TcxAlignmentVert : unsigned char { vaTop, vaBottom, vaCenter };

typedef TcxAlignmentVert TcxTopBottom;

enum DECLSPEC_DENUM TcxCollectionOperation : unsigned char { copAdd, copDelete, copChanged };

enum DECLSPEC_DENUM TcxDirection : unsigned char { dirNone, dirLeft, dirRight, dirUp, dirDown };

typedef System::Classes::TComponent* __fastcall (*TcxGetComponent)(System::Classes::TComponent* ACaller, int Index);

typedef System::UnicodeString __fastcall (*TcxGetCaptionForIntegerItemFunc)(int AItem);

enum DECLSPEC_DENUM TcxPosition : unsigned char { posNone, posLeft, posRight, posTop, posBottom };

typedef System::UnicodeString TdxSkinName;

typedef System::DynamicArray<int> TdxIntegerIndexes;

typedef NativeInt TcxTag;

__interface  INTERFACE_UUID("{66B3AA59-1EBD-4135-AB18-E980F9C970F3}") IcxDesignSelectionChanged  : public System::IInterface 
{
	virtual void __fastcall DesignSelectionChanged(System::Classes::TList* ASelection) = 0 ;
};

__interface  INTERFACE_UUID("{4C78CC4F-699B-43BD-94AC-E3BD2233F7A1}") IcxDesignHelper  : public System::IInterface 
{
	virtual void __fastcall AddSelectionChangedListener(System::Classes::TPersistent* AObject) = 0 ;
	virtual bool __fastcall CanAddComponent(System::Classes::TComponent* AOwner) = 0 ;
	virtual bool __fastcall CanDeleteComponent(System::Classes::TComponent* AOwner, System::Classes::TComponent* AComponent) = 0 ;
	virtual void __fastcall ChangeSelection(System::Classes::TComponent* AOwner, System::Classes::TPersistent* AObject) = 0 ;
	virtual bool __fastcall IsObjectSelected(System::Classes::TComponent* AOwner, System::Classes::TPersistent* AObject) = 0 ;
	virtual void __fastcall Modified() = 0 ;
	virtual void __fastcall RemoveSelectionChangedListener(System::Classes::TPersistent* AObject) = 0 ;
	virtual void __fastcall SelectObject(System::Classes::TComponent* AOwner, System::Classes::TPersistent* AObject, bool AClearSelection = true, bool AActivateOwner = true) = 0 ;
	virtual void __fastcall ShowComponentDefaultEventHandler(System::Classes::TComponent* AComponent) = 0 ;
	virtual System::UnicodeString __fastcall UniqueName(System::Classes::TComponent* AOwner, const System::UnicodeString ABaseName) = 0 ;
	virtual void __fastcall UnselectObject(System::Classes::TComponent* AOwner, System::Classes::TPersistent* AObject) = 0 ;
};

__interface  INTERFACE_UUID("{B5E39C64-543A-4AED-B81D-DA59317FB6E9}") IcxDesignHelper2  : public System::IInterface 
{
	virtual void __fastcall ClearSelection(System::Classes::TComponent* AOwner) = 0 ;
	virtual void __fastcall GetSelection(System::Classes::TComponent* AOwner, System::Classes::TList* AList) = 0 ;
	virtual void __fastcall SetSelection(System::Classes::TComponent* AOwner, System::Classes::TList* AList) = 0 ;
};

__interface  INTERFACE_UUID("{E82263AF-4C67-44BE-AD3E-3F8CEF246A3B}") IdxManager  : public System::IInterface 
{
	virtual Vcl::Forms::TCustomForm* __fastcall GetParentForm() = 0 ;
};

__interface  INTERFACE_UUID("{AB78C3D2-400B-407F-A988-C015DDCEFED3}") IdxManagedObject  : public System::IInterface 
{
	virtual _di_IdxManager __fastcall GetManager() = 0 ;
};

__interface  INTERFACE_UUID("{23C48E23-DCDF-43C2-B855-351ED49B1227}") IdxAdornerRootTargetElement  : public System::IInterface 
{
	
};

__interface  INTERFACE_UUID("{FF5950DC-2CE8-4206-BB6A-13635D78F551}") IdxAdornerTargetElement  : public System::IInterface 
{
	virtual Vcl::Controls::TWinControl* __fastcall GetControl() = 0 ;
	virtual System::Types::TRect __fastcall GetBounds() = 0 ;
	virtual bool __fastcall GetVisible() = 0 ;
};

__interface  INTERFACE_UUID("{315F65EF-DC25-417E-8A4F-26060549DCC7}") IdxAdornerTargetElementCollection  : public System::IInterface 
{
	virtual void __fastcall GetElements(System::Classes::TStrings* AList) = 0 ;
};

class PASCALIMPLEMENTATION TcxCustomComponent : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
protected:
	virtual void __fastcall GetAdornerTargetElements(System::Classes::TStrings* AList);
	
public:
	__fastcall virtual ~TcxCustomComponent();
	virtual void __fastcall AfterConstruction();
	virtual void __fastcall BeforeDestruction();
public:
	/* TComponent.Create */ inline __fastcall virtual TcxCustomComponent(System::Classes::TComponent* AOwner) : System::Classes::TComponent(AOwner) { }
	
private:
	void *__IdxAdornerTargetElementCollection;	// IdxAdornerTargetElementCollection 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {315F65EF-DC25-417E-8A4F-26060549DCC7}
	operator _di_IdxAdornerTargetElementCollection()
	{
		_di_IdxAdornerTargetElementCollection intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IdxAdornerTargetElementCollection*(void) { return (IdxAdornerTargetElementCollection*)&__IdxAdornerTargetElementCollection; }
	#endif
	
};


class PASCALIMPLEMENTATION TcxComponent : public TcxCustomComponent
{
	typedef TcxCustomComponent inherited;
	
private:
	System::Classes::TComponent* FFakeComponentLink1;
	System::Classes::TComponent* FFakeComponentLink2;
	System::Classes::TComponent* FFakeComponentLink3;
	int __fastcall GetFakeComponentLinkCount();
	bool __fastcall GetIsDesigning();
	bool __fastcall GetIsDestroying();
	bool __fastcall GetIsLoading();
	void __fastcall SetFakeComponentLink(int Index, System::Classes::TComponent* Value);
	
protected:
	virtual void __fastcall GetFakeComponentLinks(System::Classes::TList* AList);
	virtual void __fastcall Loaded();
	void __fastcall UpdateFakeLinks();
	
public:
	__property bool IsDesigning = {read=GetIsDesigning, nodefault};
	__property bool IsDestroying = {read=GetIsDestroying, nodefault};
	__property bool IsLoading = {read=GetIsLoading, nodefault};
	
__published:
	__property System::Classes::TComponent* FakeComponentLink1 = {read=FFakeComponentLink1, write=FFakeComponentLink1, stored=false};
	__property System::Classes::TComponent* FakeComponentLink2 = {read=FFakeComponentLink2, write=FFakeComponentLink2, stored=false};
	__property System::Classes::TComponent* FakeComponentLink3 = {read=FFakeComponentLink3, write=FFakeComponentLink3, stored=false};
public:
	/* TcxCustomComponent.Destroy */ inline __fastcall virtual ~TcxComponent() { }
	
public:
	/* TComponent.Create */ inline __fastcall virtual TcxComponent(System::Classes::TComponent* AOwner) : TcxCustomComponent(AOwner) { }
	
};


class PASCALIMPLEMENTATION TcxComponentHolder : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	System::Classes::TComponent* FComponent;
	System::Classes::TNotifyEvent FOnAfterComponentChange;
	System::Classes::TNotifyEvent FOnBeforeComponentChange;
	void __fastcall SetComponent(System::Classes::TComponent* AValue);
	
protected:
	void __fastcall DoAfterComponentChange();
	void __fastcall DoBeforeComponentChange();
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall TcxComponentHolder();
	__property System::Classes::TComponent* Component = {read=FComponent, write=SetComponent};
	__property System::Classes::TNotifyEvent OnAfterComponentChange = {read=FOnAfterComponentChange, write=FOnAfterComponentChange};
	__property System::Classes::TNotifyEvent OnBeforeComponentChange = {read=FOnBeforeComponentChange, write=FOnBeforeComponentChange};
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~TcxComponentHolder() { }
	
};


typedef void __stdcall (*TdxTimerProc)(HWND AWnd, unsigned AMsg, NativeUInt ATimerID, unsigned ASysTime);

class PASCALIMPLEMENTATION TcxTimer : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	bool FEnabled;
	NativeUInt FEventID;
	unsigned FInterval;
	bool FTimerOn;
	System::Classes::TNotifyEvent FOnTimer;
	bool __fastcall CanSetTimer();
	void __fastcall KillTimer();
	void __fastcall SetEnabled(bool Value);
	void __fastcall SetInterval(unsigned Value);
	void __fastcall SetOnTimer(System::Classes::TNotifyEvent Value);
	void __fastcall SetTimer();
	void __fastcall SetTimerOn(bool Value);
	void __fastcall UpdateTimer();
	__property bool TimerOn = {read=FTimerOn, write=SetTimerOn, nodefault};
	
protected:
	DYNAMIC void __fastcall TimeOut();
	
public:
	__fastcall virtual TcxTimer(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxTimer();
	void __fastcall Reset();
	
__published:
	__property bool Enabled = {read=FEnabled, write=SetEnabled, default=1};
	__property unsigned Interval = {read=FInterval, write=SetInterval, default=1000};
	__property System::Classes::TNotifyEvent OnTimer = {read=FOnTimer, write=SetOnTimer};
};


__interface  INTERFACE_UUID("{70931963-6520-4B20-A9FD-06EE20C9EEF1}") IcxScalableComponent  : public System::IInterface 
{
	virtual void __fastcall ChangeScale(int M, int D) = 0 ;
	virtual void __fastcall ScaleForPPI(int TargetPPI) = 0 ;
};

class PASCALIMPLEMENTATION TcxScalableComponent : public TcxComponent
{
	typedef TcxComponent inherited;
	
private:
	bool FScalable;
	Cxgeometry::TdxScaleFactor* FScaleFactor;
	void __fastcall ReadPixelsPerInch(System::Classes::TReader* Reader);
	void __fastcall WritePixelsPerInch(System::Classes::TWriter* Writer);
	int __fastcall GetPixelsPerInch();
	Cxgeometry::TdxScaleFactor* __fastcall GetScaleFactor();
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual void __fastcall Loaded();
	virtual void __fastcall ChangeScale(int M, int D);
	__property int PixelsPerInch = {read=GetPixelsPerInch, nodefault};
	__property bool Scalable = {read=FScalable, write=FScalable, default=1};
	__property Cxgeometry::TdxScaleFactor* ScaleFactor = {read=FScaleFactor};
	
public:
	__fastcall virtual TcxScalableComponent(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxScalableComponent();
	void __fastcall ScaleForPPI(int TargetPPI);
private:
	void *__IcxScalableComponent;	// IcxScalableComponent 
	void *__IdxScaleFactor;	// Cxgeometry::IdxScaleFactor 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {70931963-6520-4B20-A9FD-06EE20C9EEF1}
	operator _di_IcxScalableComponent()
	{
		_di_IcxScalableComponent intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IcxScalableComponent*(void) { return (IcxScalableComponent*)&__IcxScalableComponent; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {367A805A-A84B-441A-83A3-6A7E489D3B6C}
	operator Cxgeometry::_di_IdxScaleFactor()
	{
		Cxgeometry::_di_IdxScaleFactor intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Cxgeometry::IdxScaleFactor*(void) { return (Cxgeometry::IdxScaleFactor*)&__IdxScaleFactor; }
	#endif
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxInterfacedCollectionItem : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	System::_di_IInterface FOwnerInterface;
	
protected:
	int __stdcall _AddRef();
	int __stdcall _Release();
	virtual HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	
public:
	virtual void __fastcall AfterConstruction();
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TcxInterfacedCollectionItem(System::Classes::TCollection* Collection) : System::Classes::TCollectionItem(Collection) { }
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TcxInterfacedCollectionItem() { }
	
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
class PASCALIMPLEMENTATION TcxHashedStringList : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Classes::TStringList* FList;
	int __fastcall GetCount();
	int __fastcall GetHash(int Index);
	System::UnicodeString __fastcall GetString(int Index);
	void __fastcall SetString(int Index, const System::UnicodeString AValue);
	
public:
	__fastcall virtual TcxHashedStringList();
	__fastcall virtual ~TcxHashedStringList();
	virtual int __fastcall Add(const System::UnicodeString S);
	virtual int __fastcall IndexOf(const System::UnicodeString S);
	virtual void __fastcall Clear();
	__property int Count = {read=GetCount, nodefault};
	__property int Hash[int Index] = {read=GetHash};
	__property System::UnicodeString Strings[int Index] = {read=GetString, write=SetString};
};

#pragma pack(pop)

typedef void __fastcall (__closure *TcxCollectionNotifyEvent)(System::TObject* Sender, System::Classes::TCollectionItem* AItem);

typedef int __fastcall (__closure *TcxCollectionCompareEvent)(System::TObject* ASender, System::Classes::TCollectionItem* AItem1, System::Classes::TCollectionItem* AItem2);

enum DECLSPEC_DENUM TcxCollectionInternalState : unsigned char { cisDestroying, cisUpdating, cisSorting };

typedef System::Set<TcxCollectionInternalState, TcxCollectionInternalState::cisDestroying, TcxCollectionInternalState::cisSorting> TcxCollectionInternalStates;

class PASCALIMPLEMENTATION TcxOwnedInterfacedCollection : public System::Classes::TOwnedCollection
{
	typedef System::Classes::TOwnedCollection inherited;
	
private:
	TcxCollectionInternalStates FInternalState;
	bool FSorted;
	TcxCollectionNotifyEvent FOnChange;
	TcxCollectionCompareEvent FOnCompare;
	int __fastcall CompareItems(System::Classes::TStringList* AList, int AIndex1, int AIndex2);
	bool __fastcall GetIsDestroying();
	void __fastcall SetSorted(bool AValue);
	
protected:
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	virtual int __fastcall DoCompareItems(TcxInterfacedCollectionItem* AItem1, TcxInterfacedCollectionItem* AItem2);
	HIDESBASE void __fastcall Sort();
	__property bool Sorted = {read=FSorted, write=SetSorted, nodefault};
	virtual HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef();
	int __stdcall _Release();
	__property bool IsDestroying = {read=GetIsDestroying, nodefault};
	__property TcxCollectionCompareEvent OnCompare = {read=FOnCompare, write=FOnCompare};
	
public:
	__fastcall virtual ~TcxOwnedInterfacedCollection();
	__property TcxCollectionNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
public:
	/* TOwnedCollection.Create */ inline __fastcall TcxOwnedInterfacedCollection(System::Classes::TPersistent* AOwner, System::Classes::TCollectionItemClass ItemClass) : System::Classes::TOwnedCollection(AOwner, ItemClass) { }
	
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


#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxObjectList : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	System::TObject* operator[](int Index) { return this->Items[Index]; }
	
private:
	bool FOwnObjects;
	System::TObject* __fastcall GetItem(int Index);
	
protected:
	virtual void __fastcall FreeItem(int AIndex);
	
public:
	__fastcall TcxObjectList(bool AOwnObjects);
	virtual void __fastcall Clear();
	void __fastcall FreeAndDelete(int Index);
	int __fastcall FreeAndRemove(System::TObject* AObject);
	__property System::TObject* Items[int Index] = {read=GetItem/*, default*/};
	__property bool OwnObjects = {read=FOwnObjects, nodefault};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TcxObjectList() { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TcxEventHandler)(System::TObject* Sender, const void *AEventArgs);

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxEventHandlerCollection : public System::TObject
{
	typedef System::TObject inherited;
	
	
private:
	typedef System::DynamicArray<TcxEventHandler> _TcxEventHandlerCollection__1;
	
	
private:
	_TcxEventHandlerCollection__1 FEvents;
	void __fastcall Delete(int AIndex);
	int __fastcall IndexOf(TcxEventHandler AEvent);
	
public:
	void __fastcall Add(TcxEventHandler AEvent);
	void __fastcall CallEvents(System::TObject* Sender, const void *AEventArgs)/* overload */;
	void __fastcall CallEvents(System::TObject* Sender)/* overload */;
	void __fastcall Remove(TcxEventHandler AEvent);
public:
	/* TObject.Create */ inline __fastcall TcxEventHandlerCollection() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxEventHandlerCollection() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxRegisteredClassListItemData : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	System::TClass ItemClass;
	System::TClass RegisteredClass;
public:
	/* TObject.Create */ inline __fastcall TcxRegisteredClassListItemData() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxRegisteredClassListItemData() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxRegisteredClassList : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxRegisteredClassListItemData* operator[](int Index) { return this->Items[Index]; }
	
private:
	Dxcoreclasses::TdxFastList* FItems;
	int __fastcall GetCount();
	TcxRegisteredClassListItemData* __fastcall GetItem(int Index);
	
protected:
	virtual bool __fastcall Find(System::TClass AItemClass, int &AIndex);
	
public:
	__fastcall TcxRegisteredClassList();
	__fastcall virtual ~TcxRegisteredClassList();
	void __fastcall Clear();
	System::TClass __fastcall FindClass(System::TClass AItemClass);
	virtual void __fastcall Register(System::TClass AItemClass, System::TClass ARegisteredClass);
	virtual void __fastcall Unregister(System::TClass AItemClass, System::TClass ARegisteredClass);
	__property int Count = {read=GetCount, nodefault};
	__property TcxRegisteredClassListItemData* Items[int Index] = {read=GetItem/*, default*/};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxRegisteredClasses : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	System::TClass operator[](int Index) { return this->Items[Index]; }
	
private:
	System::Classes::TStringList* FItems;
	bool FRegisterClasses;
	bool FSorted;
	int __fastcall GetCount();
	System::UnicodeString __fastcall GetDescription(int Index);
	System::UnicodeString __fastcall GetHint(int Index);
	System::TClass __fastcall GetItem(int Index);
	void __fastcall SetSorted(bool Value);
	
protected:
	virtual int __fastcall CompareItems(int AIndex1, int AIndex2);
	virtual void __fastcall Sort();
	
public:
	__fastcall TcxRegisteredClasses(bool ARegisterClasses);
	__fastcall virtual ~TcxRegisteredClasses();
	void __fastcall Clear();
	System::TClass __fastcall FindByClassName(const System::UnicodeString AClassName);
	System::TClass __fastcall FindByDescription(const System::UnicodeString ADescription);
	System::UnicodeString __fastcall GetDescriptionByClass(System::TClass AClass);
	System::UnicodeString __fastcall GetHintByClass(System::TClass AClass);
	int __fastcall GetIndexByClass(System::TClass AClass);
	void __fastcall Register(System::TClass AClass, const System::UnicodeString ADescription);
	void __fastcall Unregister(System::TClass AClass);
	__property int Count = {read=GetCount, nodefault};
	__property System::UnicodeString Descriptions[int Index] = {read=GetDescription};
	__property System::UnicodeString Hints[int Index] = {read=GetHint};
	__property System::TClass Items[int Index] = {read=GetItem/*, default*/};
	__property bool RegisterClasses = {read=FRegisterClasses, write=FRegisterClasses, nodefault};
	__property bool Sorted = {read=FSorted, write=SetSorted, nodefault};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxAutoWidthItem : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	int MinWidth;
	int Width;
	bool Fixed;
	int AutoWidth;
	__fastcall TcxAutoWidthItem();
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxAutoWidthItem() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxAutoWidthObject : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxAutoWidthItem* operator[](int Index) { return this->Items[Index]; }
	
private:
	int FAvailableWidth;
	System::Classes::TList* FItems;
	int __fastcall GetCount();
	TcxAutoWidthItem* __fastcall GetItem(int Index);
	int __fastcall GetWidth();
	
protected:
	void __fastcall Clear();
	
public:
	__fastcall TcxAutoWidthObject(int ACount);
	__fastcall virtual ~TcxAutoWidthObject();
	TcxAutoWidthItem* __fastcall AddItem();
	void __fastcall Calculate();
	__property int AvailableWidth = {read=FAvailableWidth, write=FAvailableWidth, nodefault};
	__property int Count = {read=GetCount, nodefault};
	__property TcxAutoWidthItem* Items[int Index] = {read=GetItem/*, default*/};
	__property int Width = {read=GetWidth, nodefault};
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxAlignment : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::Classes::TAlignment FDefaultHorz;
	TcxAlignmentVert FDefaultVert;
	System::Classes::TAlignment FHorz;
	bool FIsHorzAssigned;
	bool FIsVertAssigned;
	System::Classes::TPersistent* FOwner;
	bool FUseAssignedValues;
	TcxAlignmentVert FVert;
	System::Classes::TNotifyEvent FOnChanged;
	bool __fastcall IsHorzStored();
	bool __fastcall IsVertStored();
	void __fastcall SetHorz(const System::Classes::TAlignment Value);
	void __fastcall SetVert(const TcxAlignmentVert Value);
	
protected:
	void __fastcall DoChanged();
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner();
	
public:
	__fastcall virtual TcxAlignment(System::Classes::TPersistent* AOwner, bool AUseAssignedValues, System::Classes::TAlignment ADefaultHorz, TcxAlignmentVert ADefaultVert);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall Reset();
	__property System::Classes::TNotifyEvent OnChanged = {read=FOnChanged, write=FOnChanged};
	
__published:
	__property System::Classes::TAlignment Horz = {read=FHorz, write=SetHorz, stored=IsHorzStored, nodefault};
	__property TcxAlignmentVert Vert = {read=FVert, write=SetVert, stored=IsVertStored, nodefault};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxAlignment() { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxObjectLink : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	System::TObject* Ref;
public:
	/* TObject.Create */ inline __fastcall TcxObjectLink() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxObjectLink() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxObjectLinkController : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Dxgenerics::TdxHashSet__1<TcxObjectLink*>* FLinks;
	
public:
	__fastcall TcxObjectLinkController();
	__fastcall virtual ~TcxObjectLinkController();
	TcxObjectLink* __fastcall AddLink(System::TObject* AObject);
	void __fastcall RemoveLink(TcxObjectLink* ALink);
	void __fastcall ClearLinks(System::TObject* AObject);
};

#pragma pack(pop)

typedef System::TMetaClass* TcxMRUItemClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxMRUItem : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	HIDESBASE virtual bool __fastcall Equals(TcxMRUItem* AItem) = 0 ;
public:
	/* TObject.Create */ inline __fastcall TcxMRUItem() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxMRUItem() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxMRUItems : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxMRUItem* operator[](int Index) { return this->Items[Index]; }
	
private:
	bool FAllowDuplicates;
	System::Classes::TList* FItems;
	int FMaxCount;
	int __fastcall GetCount();
	TcxMRUItem* __fastcall GetItem(int Index);
	void __fastcall SetCount(int Value);
	void __fastcall SetMaxCount(int Value);
	
protected:
	void __fastcall Delete(int AIndex);
	void __fastcall UpdateCount();
	__property bool AllowDuplicates = {read=FAllowDuplicates, write=FAllowDuplicates, nodefault};
	
public:
	__fastcall virtual TcxMRUItems();
	__fastcall virtual ~TcxMRUItems();
	void __fastcall Add(TcxMRUItem* AItem);
	void __fastcall ClearItems();
	int __fastcall IndexOf(TcxMRUItem* AItem);
	__property int Count = {read=GetCount, write=SetCount, nodefault};
	__property TcxMRUItem* Items[int Index] = {read=GetItem/*, default*/};
	__property int MaxCount = {read=FMaxCount, write=SetMaxCount, nodefault};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxOpenList : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	System::TObject* operator[](int Index) { return this->Items[Index]; }
	
private:
	System::TObject* __fastcall GetItem(int Index);
	void __fastcall SetItem(int Index, System::TObject* Value);
	
public:
	__property System::TObject* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TcxOpenList() { }
	
public:
	/* TObject.Create */ inline __fastcall TcxOpenList() : System::Classes::TList() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxComponentCollectionItem : public TcxCustomComponent
{
	typedef TcxCustomComponent inherited;
	
private:
	TcxComponentCollection* FCollection;
	int FID;
	
protected:
	void __fastcall AddToCollection(TcxComponentCollection* ACollection);
	void __fastcall Changed(bool AAllItems);
	virtual TcxComponentCollection* __fastcall GetCollectionFromParent(System::Classes::TComponent* AParent) = 0 ;
	virtual System::UnicodeString __fastcall GetDisplayName();
	int __fastcall GetIndex();
	void __fastcall RemoveFromCollection(TcxComponentCollection* ACollection);
	virtual void __fastcall SetCollection(TcxComponentCollection* AValue);
	virtual void __fastcall SetIndex(int AValue);
	
public:
	__fastcall virtual ~TcxComponentCollectionItem();
	DYNAMIC System::Classes::TComponent* __fastcall GetParentComponent();
	DYNAMIC bool __fastcall HasParent();
	DYNAMIC void __fastcall SetParentComponent(System::Classes::TComponent* Value);
	__property TcxComponentCollection* Collection = {read=FCollection, write=SetCollection};
	__property System::UnicodeString DisplayName = {read=GetDisplayName};
	__property int ID = {read=FID, nodefault};
	__property int Index = {read=GetIndex, write=SetIndex, nodefault};
public:
	/* TComponent.Create */ inline __fastcall virtual TcxComponentCollectionItem(System::Classes::TComponent* AOwner) : TcxCustomComponent(AOwner) { }
	
};


typedef System::TMetaClass* TcxComponentCollectionItemClass;

enum DECLSPEC_DENUM TcxComponentCollectionNotification : unsigned char { ccnAdded, ccnChanged, ccnExtracting, ccnExtracted, ccnDeleting };

typedef void __fastcall (__closure *TcxComponentCollectionChangeEvent)(System::TObject* Sender, TcxComponentCollectionItem* AItem, TcxComponentCollectionNotification AAction);

class PASCALIMPLEMENTATION TcxComponentCollection : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
public:
	TcxComponentCollectionItem* operator[](int AIndex) { return this->Items[AIndex]; }
	
private:
	TcxComponentCollectionItemClass FItemClass;
	System::Classes::TList* FItems;
	int FNextID;
	System::Classes::TComponent* FParentComponent;
	int FUpdateCount;
	TcxComponentCollectionChangeEvent FOnChange;
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner();
	TcxComponentCollectionItem* __fastcall AddItem(TcxComponentCollectionItemClass AItemClass, System::Classes::TComponent* AParentComponent, System::Classes::TComponent* AOwner)/* overload */;
	TcxComponentCollectionItem* __fastcall AddInternalItem();
	int __fastcall GetCount();
	void __fastcall InsertItem(TcxComponentCollectionItem* AItem);
	void __fastcall RemoveItem(TcxComponentCollectionItem* AItem);
	void __fastcall Changed(TcxComponentCollectionItem* AItem = (TcxComponentCollectionItem*)(0x0), TcxComponentCollectionNotification AAction = (TcxComponentCollectionNotification)(0x1));
	TcxComponentCollectionItem* __fastcall GetItem(int AIndex);
	virtual Vcl::Controls::TControl* __fastcall GetParentControl();
	virtual System::UnicodeString __fastcall GetItemPrefixName();
	virtual System::UnicodeString __fastcall GetItemSuffixName();
	virtual void __fastcall Notify(TcxComponentCollectionItem* AItem, TcxComponentCollectionNotification AAction);
	void __fastcall ReadOldCollection(System::Classes::TReader* AReader);
	void __fastcall SetItem(int AIndex, TcxComponentCollectionItem* Value);
	virtual void __fastcall SetItemName(TcxComponentCollectionItem* AItem, int ABaseIndex = 0xffffffff);
	virtual void __fastcall Update(TcxComponentCollectionItem* AItem, TcxComponentCollectionNotification AAction);
	__property int NextID = {read=FNextID, nodefault};
	__property int UpdateCount = {read=FUpdateCount, nodefault};
	__property TcxComponentCollectionItemClass ItemClass = {read=FItemClass};
	
public:
	__fastcall virtual TcxComponentCollection(System::Classes::TComponent* AParentComponent, TcxComponentCollectionItemClass AItemClass);
	__fastcall virtual ~TcxComponentCollection();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	TcxComponentCollectionItem* __fastcall Add()/* overload */;
	TcxComponentCollectionItem* __fastcall Add(TcxComponentCollectionItemClass AItemClass)/* overload */;
	virtual void __fastcall BeginUpdate();
	void __fastcall Clear();
	void __fastcall Delete(int AIndex);
	virtual void __fastcall EndUpdate(bool AForceUpdate = true);
	TcxComponentCollectionItem* __fastcall FindItemByID(int ID);
	int __fastcall IndexOf(TcxComponentCollectionItem* AItem);
	TcxComponentCollectionItem* __fastcall Insert(int AIndex);
	void __fastcall Remove(TcxComponentCollectionItem* AItem);
	__property int Count = {read=GetCount, nodefault};
	__property System::Classes::TComponent* ParentComponent = {read=FParentComponent};
	__property TcxComponentCollectionItem* Items[int AIndex] = {read=GetItem, write=SetItem/*, default*/};
	__property TcxComponentCollectionChangeEvent OnChange = {read=FOnChange, write=FOnChange};
};


class PASCALIMPLEMENTATION TcxInterfacedComponentCollection : public TcxComponentCollection
{
	typedef TcxComponentCollection inherited;
	
protected:
	HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef();
	int __stdcall _Release();
public:
	/* TcxComponentCollection.Create */ inline __fastcall virtual TcxInterfacedComponentCollection(System::Classes::TComponent* AParentComponent, TcxComponentCollectionItemClass AItemClass) : TcxComponentCollection(AParentComponent, AItemClass) { }
	/* TcxComponentCollection.Destroy */ inline __fastcall virtual ~TcxInterfacedComponentCollection() { }
	
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


__interface  INTERFACE_UUID("{DBFB3040-4677-4C9D-913C-45A1EE41E35A}") IcxDialogMetricsInfoData  : public System::IInterface 
{
	virtual void * __fastcall GetInfoData() = 0 ;
	virtual int __fastcall GetInfoDataSize() = 0 ;
	virtual void __fastcall SetInfoData(void * AData) = 0 ;
};

__interface  INTERFACE_UUID("{A68C1688-1F54-4E26-8716-A95AB50A7711}") IcxDialogMetricsClientSize  : public System::IInterface 
{
	virtual System::Types::TSize __fastcall GetClientSize() = 0 ;
	virtual void __fastcall SetClientSize(const System::Types::TSize &Value) = 0 ;
};

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDialogMetricsInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Types::TSize FClientSize;
	void *FData;
	System::TClass FDialogClass;
	int FLeft;
	bool FMaximized;
	int FTop;
	void __fastcall FreeCustomData();
	
protected:
	void __fastcall Restore(Vcl::Forms::TForm* AForm);
	void __fastcall Store(Vcl::Forms::TForm* AForm);
	void __fastcall UpdateFormPosition(Vcl::Forms::TForm* AForm);
	void __fastcall UpdateFormSize(Vcl::Forms::TForm* AForm);
	
public:
	__fastcall TcxDialogMetricsInfo(Vcl::Forms::TForm* AForm);
	__fastcall virtual ~TcxDialogMetricsInfo();
	__property System::Types::TSize ClientSize = {read=FClientSize};
	__property void * Data = {read=FData};
	__property System::TClass DialogClass = {read=FDialogClass};
	__property int Left = {read=FLeft, nodefault};
	__property bool Maximized = {read=FMaximized, nodefault};
	__property int Top = {read=FTop, nodefault};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDialogsMetricsStore : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Vcl::Forms::TPosition FDefaultPosition;
	TcxObjectList* FMetrics;
	
protected:
	TcxDialogMetricsInfo* __fastcall CreateMetrics(Vcl::Forms::TForm* AForm);
	int __fastcall FindMetrics(Vcl::Forms::TForm* AForm);
	__property TcxObjectList* Metrics = {read=FMetrics};
	
public:
	__fastcall virtual TcxDialogsMetricsStore();
	__fastcall virtual ~TcxDialogsMetricsStore();
	void __fastcall InitDialog(Vcl::Forms::TForm* AForm);
	void __fastcall StoreMetrics(Vcl::Forms::TForm* AForm);
	__property Vcl::Forms::TPosition DefaultPosition = {read=FDefaultPosition, write=FDefaultPosition, default=6};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxEvent : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	NativeUInt FHandle;
	
public:
	__fastcall TcxEvent(bool AManualReset, bool AInitialState);
	__fastcall virtual ~TcxEvent();
	System::Types::TWaitResult __fastcall WaitFor(unsigned TimeOut);
	void __fastcall ResetEvent();
	void __fastcall SetEvent();
	__property NativeUInt Handle = {read=FHandle, nodefault};
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxCustomThread : public System::Classes::TThread
{
	typedef System::Classes::TThread inherited;
	
private:
	System::Sysutils::Exception* FException;
	void __fastcall DoHandleException();
	
protected:
	virtual void __fastcall HandleException();
	void __fastcall ResetException();
public:
	/* TThread.Create */ inline __fastcall TcxCustomThread()/* overload */ : System::Classes::TThread() { }
	/* TThread.Create */ inline __fastcall TcxCustomThread(bool CreateSuspended)/* overload */ : System::Classes::TThread(CreateSuspended) { }
	/* TThread.Create */ inline __fastcall TcxCustomThread(bool CreateSuspended, NativeUInt ReservedStackSize)/* overload */ : System::Classes::TThread(CreateSuspended, ReservedStackSize) { }
	/* TThread.Destroy */ inline __fastcall virtual ~TcxCustomThread() { }
	
};


class PASCALIMPLEMENTATION TcxThread : public TcxCustomThread
{
	typedef TcxCustomThread inherited;
	
private:
	bool FCheckingForPause;
	bool FDestroying;
	bool FPaused;
	TcxEvent* FPauseEvent;
	_RTL_CRITICAL_SECTION FRTLCriticalSection;
	TcxEvent* FWaitForPauseEvent;
	bool __fastcall GetRunning();
	
protected:
	void __fastcall CheckForPause();
	__property bool Destroying = {read=FDestroying, nodefault};
	__property bool Paused = {read=FPaused, nodefault};
	__property bool Running = {read=GetRunning, nodefault};
	
public:
	__fastcall TcxThread(bool ACreateSuspended, bool ACreatePaused);
	__fastcall virtual ~TcxThread();
	virtual void __fastcall Pause(bool AWaitForPause = false);
	virtual void __fastcall Unpause();
};


typedef void __fastcall (__closure *TcxComponentListNotifyEvent)(System::TObject* Sender, System::Classes::TComponent* AComponent, System::Classes::TListNotification AAction);

typedef void __fastcall (__closure *TcxComponentListChangeEvent)(System::TObject* Sender, System::Classes::TComponent* AComponent, TcxComponentCollectionNotification AAction);

class PASCALIMPLEMENTATION TcxComponentList : public System::Contnrs::TComponentList
{
	typedef System::Contnrs::TComponentList inherited;
	
private:
	int FUpdateCount;
	TcxComponentListChangeEvent FOnComponentListChanged;
	TcxComponentListNotifyEvent FOnNotify;
	
protected:
	virtual void __fastcall DoNotify(System::Classes::TComponent* AItem, System::Classes::TListNotification AAction);
	virtual System::TClass __fastcall GetItemClass();
	virtual void __fastcall Notify(void * Ptr, System::Classes::TListNotification Action);
	void __fastcall Update(System::Classes::TComponent* AItem = (System::Classes::TComponent*)(0x0), TcxComponentCollectionNotification AAction = (TcxComponentCollectionNotification)(0x1));
	
public:
	__fastcall TcxComponentList()/* overload */;
	__fastcall virtual ~TcxComponentList();
	virtual void __fastcall Clear();
	void __fastcall BeginUpdate();
	void __fastcall CancelUpdate();
	void __fastcall EndUpdate();
	__property TcxComponentListChangeEvent OnComponentListChanged = {read=FOnComponentListChanged, write=FOnComponentListChanged};
	__property TcxComponentListNotifyEvent OnNotify = {read=FOnNotify, write=FOnNotify};
public:
	/* TComponentList.Create */ inline __fastcall TcxComponentList(bool AOwnsObjects)/* overload */ : System::Contnrs::TComponentList(AOwnsObjects) { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomProgressCalculationHelper : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FIsAborting;
	int FProgress;
	int FStage;
	int FStageCount;
	int FStageTaskCount;
	int FStageTaskNumber;
	void __fastcall CalculateProgress();
	void __fastcall SetProgress(int AValue);
	
protected:
	virtual void __fastcall ProgressChanged() = 0 ;
	
public:
	__fastcall TcxCustomProgressCalculationHelper(int AStageCount);
	virtual void __fastcall BeforeDestruction();
	void __fastcall BeginStage(int ATaskCount);
	void __fastcall EndStage();
	void __fastcall NextTask(int ASkipCount = 0x1);
	void __fastcall SetTaskNumber(int AValue);
	void __fastcall SkipStage();
	__property int Progress = {read=FProgress, nodefault};
	__property int Stage = {read=FStage, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomProgressCalculationHelper() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxMemIniFile : public System::Inifiles::TMemIniFile
{
	typedef System::Inifiles::TMemIniFile inherited;
	
public:
	__fastcall TdxMemIniFile()/* overload */;
	__fastcall TdxMemIniFile(System::Classes::TStream* AStream)/* overload */;
	void __fastcall LoadFromStream(System::Classes::TStream* AStream);
	void __fastcall SaveToStream(System::Classes::TStream* AStream)/* overload */;
	void __fastcall SaveToStream(System::Classes::TStream* AStream, System::Sysutils::TEncoding* AEncoding)/* overload */;
public:
	/* TMemIniFile.Create */ inline __fastcall TdxMemIniFile(const System::UnicodeString FileName)/* overload */ : System::Inifiles::TMemIniFile(FileName) { }
	/* TMemIniFile.Create */ inline __fastcall TdxMemIniFile(const System::UnicodeString FileName, System::Sysutils::TEncoding* const Encoding)/* overload */ : System::Inifiles::TMemIniFile(FileName, Encoding) { }
	/* TMemIniFile.Create */ inline __fastcall TdxMemIniFile(const System::UnicodeString FileName, System::Sysutils::TEncoding* const Encoding, bool CaseSensitive)/* overload */ : System::Inifiles::TMemIniFile(FileName, Encoding, CaseSensitive) { }
	/* TMemIniFile.Create */ inline __fastcall virtual TdxMemIniFile(const System::UnicodeString FileName, System::Sysutils::TEncoding* const Encoding, bool CaseSensitive, bool UseLocale)/* overload */ : System::Inifiles::TMemIniFile(FileName, Encoding, CaseSensitive, UseLocale) { }
	/* TMemIniFile.Create */ inline __fastcall virtual TdxMemIniFile(System::Classes::TStream* Stream, System::Sysutils::TEncoding* const Encoding, bool CaseSensitive, bool UseLocale)/* overload */ : System::Inifiles::TMemIniFile(Stream, Encoding, CaseSensitive, UseLocale) { }
	/* TMemIniFile.Destroy */ inline __fastcall virtual ~TdxMemIniFile() { }
	
};

#pragma pack(pop)

__interface  INTERFACE_UUID("{B54F46D5-7BF5-4B5F-9868-4A042E0E975A}") IcxProgress  : public System::IInterface 
{
	virtual void __fastcall OnProgress(System::TObject* Sender, int Percent) = 0 ;
};

typedef void __fastcall (__closure *TcxProgressEvent)(System::TObject* Sender, int Percent);

class PASCALIMPLEMENTATION TcxProgressCalculationHelper : public TcxCustomProgressCalculationHelper
{
	typedef TcxCustomProgressCalculationHelper inherited;
	
private:
	System::TObject* FEventSender;
	TcxProgressEvent FOnProgress;
	
protected:
	virtual void __fastcall ProgressChanged();
	
public:
	__fastcall TcxProgressCalculationHelper(int AStageCount, System::TObject* AEventSender, TcxProgressEvent AProgressEvent);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxProgressCalculationHelper() { }
	
};


typedef void __fastcall (*TcxNotifyProcedure)(System::TObject* Sender);

typedef void __fastcall (__closure *TcxNotifyEvent)(System::TObject* Sender, System::UnicodeString ANotificationText);

#pragma pack(push,1)
struct DECLSPEC_DRECORD TcxLangRec
{
public:
	System::UnicodeString FName;
	unsigned FLCID;
	System::UnicodeString FExt;
	System::UnicodeString FLocaleName;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLanguages : public System::TObject
{
	typedef System::TObject inherited;
	
	
private:
	typedef System::DynamicArray<TcxLangRec> _TdxLanguages__1;
	
	
private:
	_TdxLanguages__1 FSysLangs;
	int __stdcall LocalesCallback(System::WideChar * LocaleID);
	int __fastcall GetCount();
	System::UnicodeString __fastcall GetExt(int Index);
	System::UnicodeString __fastcall GetID(int Index);
	unsigned __fastcall GetLocaleID(int Index);
	System::UnicodeString __fastcall GetLocaleName(int Index);
	System::UnicodeString __fastcall GetName(int Index);
	System::UnicodeString __fastcall GetNameFromLocaleID(unsigned ID);
	System::UnicodeString __fastcall GetNameFromLCID(const System::UnicodeString ID);
	
public:
	__fastcall TdxLanguages();
	unsigned __fastcall GetDefaultLanguageLCID();
	unsigned __fastcall GetLCID(const System::UnicodeString AName);
	int __fastcall IndexOf(unsigned ID)/* overload */;
	int __fastcall IndexOf(const System::UnicodeString ALocaleName)/* overload */;
	__property int Count = {read=GetCount, nodefault};
	__property System::UnicodeString Name[int Index] = {read=GetName};
	__property System::UnicodeString NameFromLCID[const System::UnicodeString ID] = {read=GetNameFromLCID};
	__property System::UnicodeString NameFromLocaleID[unsigned ID] = {read=GetNameFromLocaleID};
	__property System::UnicodeString ID[int Index] = {read=GetID};
	__property unsigned LocaleID[int Index] = {read=GetLocaleID};
	__property System::UnicodeString LocaleName[int Index] = {read=GetLocaleName};
	__property System::UnicodeString Ext[int Index] = {read=GetExt};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLanguages() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLanguageID : /*[[sealed]]*/ public System::TObject
{
	typedef System::TObject inherited;
	
	
private:
	#pragma pack(push,8)
	struct DECLSPEC_DRECORD TLangRec
	{
	public:
		System::WideChar *ShortName;
		int LanguageID;
	};
	#pragma pack(pop)
	
	
	
public:
	static const System::Int8 None = System::Int8(0x0);
	
	static const System::Word Arabic = System::Word(0x401);
	
	static const System::Word Azerbaijani = System::Word(0x42c);
	
	static const System::Word Bulgarian = System::Word(0x402);
	
	static const System::Word Catalan = System::Word(0x403);
	
	static const System::Word Czech = System::Word(0x405);
	
	static const System::Word Danish = System::Word(0x406);
	
	static const System::Word German = System::Word(0x407);
	
	static const System::Word Greek = System::Word(0x408);
	
	static const System::Word English = System::Word(0x409);
	
	static const System::Word Spanish = System::Word(0x40a);
	
	static const System::Word Basque = System::Word(0x42d);
	
	static const System::Word Galician = System::Word(0x456);
	
	static const System::Word French = System::Word(0x40c);
	
	static const System::Word Croatian = System::Word(0x41a);
	
	static const System::Word Hungarian = System::Word(0x40e);
	
	static const System::Word Italian = System::Word(0x410);
	
	static const System::Word Latvian = System::Word(0x426);
	
	static const System::Word Dutch = System::Word(0x413);
	
	static const System::Word Polish = System::Word(0x415);
	
	static const System::Word Portuguese = System::Word(0x816);
	
	static const System::Word Russian = System::Word(0x419);
	
	static const System::Word Swedish = System::Word(0x41d);
	
	static const System::Word Turkish = System::Word(0x41f);
	
	static const System::Word Ukrainian = System::Word(0x422);
	
	
private:
	static System::StaticArray<TLangRec, 24> LangMap;
	
public:
	static int __fastcall GetLanguageID(const System::WideChar * ALanguage);
public:
	/* TObject.Create */ inline __fastcall TdxLanguageID() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLanguageID() { }
	
};

#pragma pack(pop)

enum DECLSPEC_DENUM TdxClassesID : unsigned char { dxIdUnknown, dxIdTextEdit, dxIdButton, dxIdRadioButton, dxIdRadioGroup, dxIdCheckBox, dxIdComboBox, dxIdMemo, dxIdRichEdit, dxIdImage, dxIdGroupBox, dxIdGrid, dxIdListBox, dxIdVerticalGrid, dxIdColorComboBox, dxIdRatingControl, dxIdToggleSwitch, dxIdNavigator, dxIdCalc, dxIdColorEdit, dxIdTreeList, dxIdRibbon, dxIdSpreedSheet, dxIdChart };

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE TcxAlignmentVert cxDefaultAlignmentVert;
extern DELPHI_PACKAGE _di_IcxDesignHelper cxDesignHelper;
extern DELPHI_PACKAGE TcxDialogsMetricsStore* __fastcall cxDialogsMetricsStore(void);
extern DELPHI_PACKAGE TcxObjectLink* __fastcall cxAddObjectLink(System::TObject* AObject);
extern DELPHI_PACKAGE void __fastcall cxRemoveObjectLink(TcxObjectLink* ALink);
extern DELPHI_PACKAGE void __fastcall cxClearObjectLinks(System::TObject* AObject);
extern DELPHI_PACKAGE void __fastcall cxAddFreeNotification(System::Classes::TComponent* ARecipient, System::Classes::TComponent* ASender);
extern DELPHI_PACKAGE void __fastcall cxRemoveFreeNotification(System::Classes::TComponent* ARecipient, System::Classes::TComponent* ASender);
extern DELPHI_PACKAGE bool __fastcall cxIsDestroying(System::Classes::TComponent* AComponent, bool ARecursive = false);
extern DELPHI_PACKAGE void __fastcall cxBroadcastRemoveNotifications(System::Classes::TComponent* AComponent);
extern DELPHI_PACKAGE System::UnicodeString __fastcall cxGetClassName(NativeUInt AWnd);
extern DELPHI_PACKAGE int __fastcall cxStrCharLength(const System::UnicodeString AStr, int AIndex = 0x1);
extern DELPHI_PACKAGE int __fastcall cxNextCharPos(const System::UnicodeString AStr, int AIndex);
extern DELPHI_PACKAGE int __fastcall cxPrevCharPos(const System::UnicodeString AStr, int AIndex);
extern DELPHI_PACKAGE void __fastcall dxStreamInsertData(System::Classes::TStream* AStream, System::Classes::TMemoryStream* AData, const __int64 AInsertPosition, TcxCustomProgressCalculationHelper* AProgressHelper = (TcxCustomProgressCalculationHelper*)(0x0));
extern DELPHI_PACKAGE void __fastcall CallNotify(System::Classes::TNotifyEvent ANotifyEvent, System::TObject* ASender);
extern DELPHI_PACKAGE bool __fastcall ClassInheritsFrom(System::TClass AClass, const System::UnicodeString AParentClassName);
extern DELPHI_PACKAGE void __fastcall FillStringsWithEnumTypeValues(System::Classes::TStrings* AStrings, System::Typinfo::PTypeInfo ATypeInfo, TcxGetCaptionForIntegerItemFunc AGetTypeItemCaption);
extern DELPHI_PACKAGE System::Classes::TPersistent* __fastcall GetPersistentOwner(System::Classes::TPersistent* APersistent);
extern DELPHI_PACKAGE System::UnicodeString __fastcall GetSubobjectName(System::Classes::TPersistent* AObject, System::Classes::TPersistent* ASubobject);
extern DELPHI_PACKAGE System::UnicodeString __fastcall GetValidName(System::Classes::TComponent* AComponent, const System::UnicodeString AName, bool AIsBaseName = false);
extern DELPHI_PACKAGE void __fastcall RenameComponents(System::Classes::TComponent* ACaller, System::Classes::TComponent* AOwner, System::Classes::TComponentName ANewName, const System::Classes::TComponentName AOldName, int AComponentCount, TcxGetComponent AGetComponent);
extern DELPHI_PACKAGE int __fastcall RoundDiv(int I1, int I2);
extern DELPHI_PACKAGE System::Types::TSize __fastcall Size(int cx, int cy);
extern DELPHI_PACKAGE void __fastcall SwapIntegers(int &I1, int &I2);
extern DELPHI_PACKAGE int __fastcall GetRangeCenter(int ABound1, int ABound2);
extern DELPHI_PACKAGE bool __fastcall StreamsEqual(System::Classes::TMemoryStream* AStream1, System::Classes::TMemoryStream* AStream2);
extern DELPHI_PACKAGE System::UnicodeString __fastcall GetCorrectPath(const System::UnicodeString S);
extern DELPHI_PACKAGE TdxLanguages* __fastcall dxLanguages(void);
extern DELPHI_PACKAGE System::UnicodeString __fastcall cxGetUnitName(System::TClass AClass);
extern DELPHI_PACKAGE System::UnicodeString __fastcall CreateUniqueName(System::Classes::TComponent* AOwnerForm, System::Classes::TComponent* AOwnerComponent, System::Classes::TComponent* AComponent, const System::UnicodeString APrefixName, const System::UnicodeString ASuffixName, int ABaseIndex = 0xffffffff);
extern DELPHI_PACKAGE System::UnicodeString __fastcall cxGenerateComponentName(System::Classes::TComponent* AOwnerComponent, const System::UnicodeString AClassName, const System::UnicodeString APrefixName, const System::UnicodeString ASuffixName, int ANumber);
extern DELPHI_PACKAGE void __fastcall cxRegisterVclClasses(System::Classes::TPersistentClass *AClasses, const int AClasses_High);
extern DELPHI_PACKAGE int __fastcall cxSign(const double AValue);
extern DELPHI_PACKAGE NativeInt __fastcall cxSendStructMessage(NativeUInt AHandle, unsigned AMsg, NativeUInt WParam, const void *LParam)/* overload */;
extern DELPHI_PACKAGE NativeInt __fastcall cxSendStructMessage(NativeUInt AHandle, unsigned AMsg, const void *WParam, NativeInt LParam)/* overload */;
extern DELPHI_PACKAGE TcxTimer* __fastcall cxCreateTimer(System::Classes::TNotifyEvent AOnTimer, int AInterval = 0x3e8, bool AEnabled = true);
extern DELPHI_PACKAGE bool __fastcall dxSetTimer(NativeUInt AWindowHandle, NativeUInt ATimerID, unsigned AInterval)/* overload */;
extern DELPHI_PACKAGE NativeUInt __fastcall dxSetTimer(unsigned AInterval, TdxTimerProc ATimerProcedure)/* overload */;
extern DELPHI_PACKAGE NativeUInt __fastcall dxSetTimer(NativeUInt AWindowHandle, NativeUInt ATimerID, unsigned AInterval, TdxTimerProc ATimerProcedure)/* overload */;
extern DELPHI_PACKAGE bool __fastcall dxKillTimer(HWND AWindowHandle, NativeUInt &ATimerID);
}	/* namespace Cxclasses */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXCLASSES)
using namespace Cxclasses;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxclassesHPP
