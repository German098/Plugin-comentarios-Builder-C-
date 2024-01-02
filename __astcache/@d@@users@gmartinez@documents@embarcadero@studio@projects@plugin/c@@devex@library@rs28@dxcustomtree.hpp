// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxCustomTree.pas' rev: 35.00 (Windows)

#ifndef DxcustomtreeHPP
#define DxcustomtreeHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Classes.hpp>
#include <dxCore.hpp>
#include <dxCoreClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Dxcustomtree
{
//-- forward type declarations -----------------------------------------------
__interface DELPHIINTERFACE IdxTreeOwner;
typedef System::DelphiInterface<IdxTreeOwner> _di_IdxTreeOwner;
class DELPHICLASS TdxTreeCustomNode;
__interface DELPHIINTERFACE TdxTreeForEachNodeProc;
typedef System::DelphiInterface<TdxTreeForEachNodeProc> _di_TdxTreeForEachNodeProc;
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TdxTreeCustomNodeClass;

enum DECLSPEC_DENUM TdxTreeNodeNotification : unsigned char { tnStructure, tnData };

typedef System::Set<TdxTreeNodeNotification, TdxTreeNodeNotification::tnStructure, TdxTreeNodeNotification::tnData> TdxTreeNodeNotifications;

__interface  INTERFACE_UUID("{E5BD359F-E1D0-4ABC-9D9D-45A6516F2F8B}") IdxTreeOwner  : public System::IInterface 
{
	virtual bool __fastcall CanCollapse(TdxTreeCustomNode* ASender) = 0 ;
	virtual bool __fastcall CanExpand(TdxTreeCustomNode* ASender) = 0 ;
	virtual void __fastcall Collapsed(TdxTreeCustomNode* ASender) = 0 ;
	virtual void __fastcall Expanded(TdxTreeCustomNode* ASender) = 0 ;
	virtual void __fastcall LoadChildren(TdxTreeCustomNode* ASender) = 0 ;
	virtual void __fastcall BeforeDelete(TdxTreeCustomNode* ASender) = 0 ;
	virtual void __fastcall DeleteNode(TdxTreeCustomNode* ASender) = 0 ;
	virtual System::Classes::TPersistent* __fastcall GetOwner() = 0 ;
	virtual TdxTreeCustomNodeClass __fastcall GetNodeClass(TdxTreeCustomNode* ARelativeNode) = 0 ;
	virtual void __fastcall TreeNotification(TdxTreeCustomNode* ASender, TdxTreeNodeNotifications ANotification) = 0 ;
	virtual void __fastcall BeginUpdate() = 0 ;
	virtual void __fastcall EndUpdate() = 0 ;
};

enum DECLSPEC_DENUM TdxTreeNodeAttachMode : unsigned char { namAdd, namAddFirst, namAddChild, namAddChildFirst, namInsert };

enum DECLSPEC_DENUM TdxTreeNodeAddMode : unsigned char { amAdd, amAddFirst, amInsert };

enum DECLSPEC_DENUM TdxTreeNodeState : unsigned char { nsCollapsed, nsHasChildren, nsValidIndexes, nsDeleting, nsInternalDelete, nsInvisible };

typedef System::Set<TdxTreeNodeState, TdxTreeNodeState::nsCollapsed, TdxTreeNodeState::nsInvisible> TdxTreeNodeStates;

typedef int __fastcall (*TdxCustomTreeNodeCompareProc)(TdxTreeCustomNode* ANode1, TdxTreeCustomNode* ANode2);

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTreeCustomNode : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TdxTreeCustomNode* operator[](int Index) { return this->Items[Index]; }
	
private:
	int FCount;
	void *FData;
	TdxTreeCustomNode* FFirst;
	int FImageIndex;
	int FIndex;
	TdxTreeCustomNode* FLast;
	TdxTreeCustomNode* FNext;
	TdxTreeCustomNode* FParent;
	TdxTreeCustomNode* FPrev;
	TdxTreeNodeStates FState;
	int FStructureID;
	bool __fastcall GetExpanded();
	bool __fastcall GetHasChildren();
	int __fastcall GetIndex();
	TdxTreeCustomNode* __fastcall GetItem(int AIndex);
	int __fastcall GetLevel();
	System::Classes::TPersistent* __fastcall GetOwner();
	TdxTreeCustomNode* __fastcall GetRoot();
	bool __fastcall GetVisible();
	void __fastcall SetData(void * AValue);
	void __fastcall SetExpanded(bool AValue);
	void __fastcall SetHasChildren(bool AValue);
	void __fastcall SetImageIndex(int AValue);
	void __fastcall SetVisible(bool AValue);
	
protected:
	_di_IdxTreeOwner FOwner;
	virtual void __fastcall Added(TdxTreeCustomNode* ANode);
	void __fastcall AdjustIndexes();
	virtual bool __fastcall AreChildrenLoaded();
	virtual void __fastcall DataChanged();
	virtual void __fastcall DoNodeExpandStateChanged();
	void __fastcall ExtractFromParent();
	virtual int __fastcall GetDefaultImageIndexValue();
	virtual TdxTreeNodeStates __fastcall GetDefaultState();
	virtual int __fastcall GetImageIndex();
	void __fastcall InternalInsert(TdxTreeCustomNode* AValue);
	void __fastcall Notify(TdxTreeNodeNotifications ANotification);
	void __fastcall PopulateItems(Dxcoreclasses::TdxFastList* AList);
	void __fastcall SetFirst(TdxTreeCustomNode* AValue);
	void __fastcall SetLast(TdxTreeCustomNode* AValue);
	virtual void __fastcall SetNodeParent(TdxTreeCustomNode* ANewNode, TdxTreeCustomNode* ANewParent, TdxTreeNodeAddMode AMode);
	void __fastcall SetParentFor(TdxTreeCustomNode* AValue, bool AValidateIndexes = true);
	void __fastcall UpdateItems(Dxcoreclasses::TdxFastList* AList);
	virtual void __fastcall ReadData(System::Classes::TStream* AStream, const unsigned AVersion = (unsigned)(0x0));
	virtual void __fastcall WriteData(System::Classes::TStream* AStream);
	__property TdxTreeNodeStates State = {read=FState, write=FState, nodefault};
	__property int StructureID = {read=FStructureID, write=FStructureID, nodefault};
	
public:
	__fastcall virtual TdxTreeCustomNode(_di_IdxTreeOwner AOwner);
	__fastcall virtual ~TdxTreeCustomNode();
	TdxTreeCustomNode* __fastcall AddChild();
	TdxTreeCustomNode* __fastcall AddChildFirst();
	TdxTreeCustomNode* __fastcall AddNode(TdxTreeCustomNode* ANode, TdxTreeCustomNode* ARelative, void * AData, TdxTreeNodeAttachMode AttachMode);
	virtual void __fastcall Assign(TdxTreeCustomNode* ASource);
	void __fastcall CustomSort(TdxCustomTreeNodeCompareProc ACompareProc, bool ARecurse = false);
	void __fastcall BeginUpdate();
	void __fastcall EndUpdate();
	virtual void __fastcall Clear();
	void __fastcall Delete();
	virtual void __fastcall DeleteChildren();
	bool __fastcall HasAsParent(TdxTreeCustomNode* ANode);
	bool __fastcall IsRoot();
	virtual void __fastcall LoadChildren();
	virtual void __fastcall MoveTo(TdxTreeCustomNode* ADestNode, TdxTreeNodeAttachMode AMode);
	__property int Count = {read=FCount, nodefault};
	__property void * Data = {read=FData, write=SetData};
	__property TdxTreeCustomNode* First = {read=FFirst};
	__property bool Expanded = {read=GetExpanded, write=SetExpanded, nodefault};
	__property bool HasChildren = {read=GetHasChildren, write=SetHasChildren, nodefault};
	__property int ImageIndex = {read=GetImageIndex, write=SetImageIndex, nodefault};
	__property int Index = {read=GetIndex, nodefault};
	__property TdxTreeCustomNode* Items[int Index] = {read=GetItem/*, default*/};
	__property TdxTreeCustomNode* Last = {read=FLast};
	__property int Level = {read=GetLevel, nodefault};
	__property TdxTreeCustomNode* Next = {read=FNext};
	__property System::Classes::TPersistent* Owner = {read=GetOwner};
	__property TdxTreeCustomNode* Parent = {read=FParent};
	__property TdxTreeCustomNode* Prev = {read=FPrev};
	__property TdxTreeCustomNode* Root = {read=GetRoot};
	__property bool Visible = {read=GetVisible, write=SetVisible, nodefault};
};

#pragma pack(pop)

__interface TdxTreeForEachNodeProc  : public System::IInterface 
{
	virtual bool __fastcall Invoke(TdxTreeCustomNode* ANode, void * AData) = 0 ;
};

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE int __fastcall dxTreeForEach(TdxTreeCustomNode* ARoot, _di_TdxTreeForEachNodeProc AProc, void * AData);
}	/* namespace Dxcustomtree */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXCUSTOMTREE)
using namespace Dxcustomtree;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxcustomtreeHPP
