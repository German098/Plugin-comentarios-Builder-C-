// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxCustomData.pas' rev: 35.00 (Windows)

#ifndef CxcustomdataHPP
#define CxcustomdataHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Data.FmtBcd.hpp>
#include <System.Types.hpp>
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <System.Variants.hpp>
#include <cxVariants.hpp>
#include <cxDataUtils.hpp>
#include <cxDataStorage.hpp>
#include <cxFilter.hpp>
#include <dxCore.hpp>
#include <dxCoreClasses.hpp>
#include <dxGenerics.hpp>

//-- user supplied -----------------------------------------------------------

namespace Cxcustomdata
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS EcxInvalidDataControllerOperation;
class DELPHICLASS TcxCustomExpressionProvider;
class DELPHICLASS TcxDataCustomExpressionParser;
class DELPHICLASS TcxDataCustomExpressionCalculator;
class DELPHICLASS TcxDataCustomExpressionProvider;
class DELPHICLASS TcxCustomDataSource;
struct TcxDataChangeInfo;
class DELPHICLASS TcxCustomDataProvider;
class DELPHICLASS TcxCustomDataField;
class DELPHICLASS TcxCustomDataFieldList;
class DELPHICLASS TcxDetailInfoObject;
class DELPHICLASS TcxDetailObject;
class DELPHICLASS TcxCustomDataRelation;
class DELPHICLASS TcxCustomDetailObjects;
class DELPHICLASS TcxDetailObjects;
class DELPHICLASS TcxCustomDataRelationList;
class DELPHICLASS TcxDataSortFieldInfo;
class DELPHICLASS TcxSortingFieldList;
class DELPHICLASS TcxDataGroupFieldInfo;
class DELPHICLASS TcxGroupingFieldList;
class DELPHICLASS TcxDataControllerInfoHelper;
class DELPHICLASS TcxDataGroupInfoSummaryInfo;
class DELPHICLASS TcxDataGroupInfo;
struct TcxGroupsRowInfo;
struct TcxDataGroupCompareInfo;
class DELPHICLASS TcxGroupFieldInfo;
class DELPHICLASS TcxDataGroups;
struct TcxRowInfo;
class DELPHICLASS TcxDataFocusingInfo;
class DELPHICLASS TcxDataExpandingInfo;
class DELPHICLASS TcxDataExpandingInfos;
class DELPHICLASS TcxDataFixingInfo;
struct TcxDataSelectionInfo;
class DELPHICLASS TcxDataSelection;
class DELPHICLASS TcxCustomDataControllerInfo;
class DELPHICLASS TcxDataFilterCriteriaItem;
class DELPHICLASS TcxDataFilterValueList;
class DELPHICLASS TcxDataFilterCriteria;
class DELPHICLASS TcxDataFilterList;
class DELPHICLASS TcxCustomDataFindCriteria;
class DELPHICLASS TcxDataFindCriteriaCondition;
class DELPHICLASS TcxDataFindCriteriaConditions;
class DELPHICLASS TcxDataFindCriteriaMatches;
class DELPHICLASS TcxDataFindCriteria;
struct TcxFilteringInfo;
class DELPHICLASS TcxDataControllerGroups;
class DELPHICLASS TcxCustomDataSummaryItem;
class DELPHICLASS TcxDataSummaryItem;
struct TcxSummaryEventArguments;
struct TcxSummaryEventOutArguments;
class DELPHICLASS TcxDataSummaryItems;
class DELPHICLASS TcxDataFooterSummaryItems;
class DELPHICLASS TcxDataGroupSummaryItems;
class DELPHICLASS TcxDataSummaryGroupItemLink;
class DELPHICLASS TcxDataSummaryGroupItemLinks;
class DELPHICLASS TcxDataSummaryGroup;
class DELPHICLASS TcxDataSummaryGroups;
class DELPHICLASS TcxDataControllerObject;
class DELPHICLASS TcxDataControllerPersistent;
class DELPHICLASS TcxDataSummary;
class DELPHICLASS TcxDataControllerMultiThreadedOptions;
class DELPHICLASS TcxDataControllerSearch;
class DELPHICLASS TcxUpdateControlInfo;
class DELPHICLASS TcxFindCriteriaChangedInfo;
class DELPHICLASS TcxFocusedRecordChangedInfo;
class DELPHICLASS TcxFocusedRowChangedInfo;
class DELPHICLASS TcxGroupingChangingInfo;
class DELPHICLASS TcxLayoutChangedInfo;
class DELPHICLASS TcxUpdateRecordInfo;
class DELPHICLASS TcxDataChangedInfo;
class DELPHICLASS TcxBookmarkChangedInfo;
class DELPHICLASS TcxSelectionChangedInfo;
class DELPHICLASS TcxSearchChangedInfo;
struct TcxDataSelectionChangedInfo;
class DELPHICLASS TcxDataControllerLocateObject;
class DELPHICLASS TcxDataControllerKeyLocateObject;
class DELPHICLASS TcxDataControllerGroupLocateObject;
class DELPHICLASS TcxValueDefUnboundReader;
class DELPHICLASS TcxValueDefRecordReader;
class DELPHICLASS TcxDataControllerNotifier;
class DELPHICLASS TcxSortingBySummaryEngine;
class DELPHICLASS TcxDataListenerLink;
class DELPHICLASS TcxCustomDataController;
class DELPHICLASS TcxCustomDataHelper;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION EcxInvalidDataControllerOperation : public Dxcore::EdxException
{
	typedef Dxcore::EdxException inherited;
	
public:
	/* Exception.Create */ inline __fastcall EcxInvalidDataControllerOperation(const System::UnicodeString Msg) : Dxcore::EdxException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EcxInvalidDataControllerOperation(const System::UnicodeString Msg, const System::TVarRec *Args, const int Args_High) : Dxcore::EdxException(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EcxInvalidDataControllerOperation(NativeUInt Ident)/* overload */ : Dxcore::EdxException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EcxInvalidDataControllerOperation(System::PResStringRec ResStringRec)/* overload */ : Dxcore::EdxException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxInvalidDataControllerOperation(NativeUInt Ident, const System::TVarRec *Args, const int Args_High)/* overload */ : Dxcore::EdxException(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxInvalidDataControllerOperation(System::PResStringRec ResStringRec, const System::TVarRec *Args, const int Args_High)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EcxInvalidDataControllerOperation(const System::UnicodeString Msg, int AHelpContext) : Dxcore::EdxException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EcxInvalidDataControllerOperation(const System::UnicodeString Msg, const System::TVarRec *Args, const int Args_High, int AHelpContext) : Dxcore::EdxException(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxInvalidDataControllerOperation(NativeUInt Ident, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxInvalidDataControllerOperation(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxInvalidDataControllerOperation(System::PResStringRec ResStringRec, const System::TVarRec *Args, const int Args_High, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxInvalidDataControllerOperation(NativeUInt Ident, const System::TVarRec *Args, const int Args_High, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EcxInvalidDataControllerOperation() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomExpressionProvider : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	virtual void __fastcall EditExpression(System::UnicodeString &AExpression) = 0 /* overload */;
	virtual System::UnicodeString __fastcall ExpressionToInvariantExpression(const System::UnicodeString AExpression) = 0 ;
	virtual System::UnicodeString __fastcall InvariantExpressionToExpression(const System::UnicodeString AExpression) = 0 ;
public:
	/* TObject.Create */ inline __fastcall TcxCustomExpressionProvider() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomExpressionProvider() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataCustomExpressionParser : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	virtual void __fastcall Parse(const System::UnicodeString AExpression, System::TObject* AFormula) = 0 ;
public:
	/* TObject.Create */ inline __fastcall TcxDataCustomExpressionParser() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDataCustomExpressionParser() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataCustomExpressionCalculator : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	virtual System::Variant __fastcall Calculate(System::TObject* AFormula, int ARecordIndex, /* out */ int &AErrorCode) = 0 ;
public:
	/* TObject.Create */ inline __fastcall TcxDataCustomExpressionCalculator() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDataCustomExpressionCalculator() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataCustomExpressionProvider : public TcxCustomExpressionProvider
{
	typedef TcxCustomExpressionProvider inherited;
	
private:
	TcxDataCustomExpressionCalculator* FCalculator;
	TcxCustomDataController* FDataController;
	TcxDataCustomExpressionParser* FParser;
	TcxDataCustomExpressionCalculator* __fastcall GetCalculator();
	TcxDataCustomExpressionParser* __fastcall GetParser();
	
protected:
	virtual TcxDataCustomExpressionCalculator* __fastcall CreateCalculator() = 0 ;
	virtual System::TObject* __fastcall CreateFormula() = 0 ;
	virtual TcxDataCustomExpressionParser* __fastcall CreateParser() = 0 ;
	virtual System::UnicodeString __fastcall ErrorCodeToString(int ACode) = 0 ;
	virtual int __fastcall GetVarCastErrorCode() = 0 ;
	__property TcxDataCustomExpressionCalculator* Calculator = {read=GetCalculator};
	__property TcxCustomDataController* DataController = {read=FDataController};
	__property TcxDataCustomExpressionParser* Parser = {read=GetParser};
	
public:
	__fastcall virtual TcxDataCustomExpressionProvider(TcxCustomDataController* ADataController);
	__fastcall virtual ~TcxDataCustomExpressionProvider();
	virtual bool __fastcall CanUseItemInExpression(int AItemIndex) = 0 ;
	HIDESBASE virtual void __fastcall EditExpression(int AItemIndex) = 0 /* overload */;
	virtual System::UnicodeString __fastcall GetItemReferenceName(int AItemIndex) = 0 ;
	/* Hoisted overloads: */
	
public:
	inline void __fastcall  EditExpression(System::UnicodeString &AExpression){ TcxCustomExpressionProvider::EditExpression(AExpression); }
	
};

#pragma pack(pop)

typedef void * TcxDataRecordHandle;

typedef void * TcxDataItemHandle;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomDataSource : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxCustomDataProvider* FCurrentProvider;
	TcxCustomDataProvider* FProvider;
	Dxcoreclasses::TdxFastList* FProviders;
	TcxCustomDataController* __fastcall GetDataController();
	TcxCustomDataProvider* __fastcall GetProvider();
	void __fastcall AddProvider(TcxCustomDataProvider* AProvider);
	void __fastcall RemoveProvider(TcxCustomDataProvider* AProvider);
	void __fastcall RemoveFromProviders();
	
protected:
	virtual void * __fastcall AppendRecord();
	virtual void __fastcall CustomSort();
	virtual void __fastcall DeleteRecord(void * ARecordHandle);
	virtual int __fastcall GetDefaultItemID(int AItemIndex);
	virtual bool __fastcall GetDetailHasChildren(int ARecordIndex, int ARelationIndex);
	virtual System::UnicodeString __fastcall GetDisplayText(void * ARecordHandle, void * AItemHandle);
	virtual bool __fastcall GetInfoForCompare(void * ARecordHandle, void * AItemHandle, char * &PValueBuffer);
	virtual void * __fastcall GetItemHandle(int AItemIndex);
	virtual int __fastcall GetRecordCount();
	virtual System::Variant __fastcall GetRecordId(void * ARecordHandle);
	virtual void * __fastcall GetRecordHandle(int ARecordIndex);
	virtual System::Variant __fastcall GetValue(void * ARecordHandle, void * AItemHandle);
	virtual void * __fastcall InsertRecord(void * ARecordHandle);
	virtual bool __fastcall IsCustomSorting();
	virtual bool __fastcall IsMultiThreadingSupported();
	virtual bool __fastcall IsNativeCompare();
	virtual bool __fastcall IsNativeCompareFunc();
	virtual bool __fastcall IsRecordIdSupported();
	virtual void __fastcall LoadRecordHandles();
	virtual int __fastcall NativeCompareFunc(void * ARecordHandle1, void * ARecordHandle2, void * AItemHandle);
	virtual void __fastcall SetRecordCount(int ARecordCount);
	virtual void __fastcall SetValue(void * ARecordHandle, void * AItemHandle, const System::Variant &AValue);
	int __fastcall AddRecordHandle(void * ARecordHandle);
	__property TcxCustomDataProvider* CurrentProvider = {read=FCurrentProvider, write=FCurrentProvider};
	
public:
	__fastcall virtual ~TcxCustomDataSource();
	virtual void __fastcall DataChanged();
	virtual void * __fastcall GetRecordHandleByIndex(int ARecordIndex);
	int __fastcall GetRecordIndexByHandle(void * ARecordHandle);
	__property TcxCustomDataController* DataController = {read=GetDataController};
	__property TcxCustomDataProvider* Provider = {read=GetProvider};
public:
	/* TObject.Create */ inline __fastcall TcxCustomDataSource() : System::TObject() { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCustomDataSourceClass;

enum DECLSPEC_DENUM TcxDataChange : unsigned char { dcField, dcRecord, dcNew, dcDeleted, dcTotal };

struct DECLSPEC_DRECORD TcxDataChangeInfo
{
public:
	TcxDataChange Kind;
	int ItemIndex;
	int RecordIndex;
};


enum DECLSPEC_DENUM TcxDataLayoutChange : unsigned char { lcStructure, lcData };

typedef System::Set<TcxDataLayoutChange, TcxDataLayoutChange::lcStructure, TcxDataLayoutChange::lcData> TcxDataLayoutChanges;

typedef System::DynamicArray<int> TcxDataSummaryCountValues;

typedef System::DynamicArray<System::Variant> TcxDataSummaryValues;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomDataProvider : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FActiveChanging;
	bool FChanging;
	TcxCustomDataSource* FCustomDataSource;
	bool FDataChangedLocked;
	TcxCustomDataController* FDataController;
	int FEditingRecordIndex;
	int FEditingRecordIndex1;
	int FEditingRecordIndex2;
	int FInsertedRecordIndex;
	bool FInUpdateData;
	int FLocateCount;
	int FLockCount;
	bool FModified;
	bool FRecreatedFieldsAfterFirst;
	int FSavedRecordIndex;
	void __fastcall SetCustomDataSource(TcxCustomDataSource* Value);
	
protected:
	bool FInInserting;
	bool FInserting;
	bool FLoadAllNeeded;
	virtual void __fastcall CustomSort();
	virtual bool __fastcall IsCustomDataSourceSupported();
	virtual bool __fastcall IsCustomSorting();
	virtual bool __fastcall IsGridMode();
	virtual bool __fastcall IsDataSource();
	virtual bool __fastcall IsOtherInsert();
	virtual bool __fastcall IsRecordIdSupported();
	virtual bool __fastcall IsSyncMode();
	virtual bool __fastcall IsActive();
	virtual bool __fastcall IsActiveDataSet();
	virtual bool __fastcall IsBOF();
	virtual bool __fastcall IsChanging();
	virtual bool __fastcall IsEditing();
	virtual bool __fastcall IsEOF();
	virtual bool __fastcall IsGridModeUpdating();
	virtual bool __fastcall IsInserting();
	virtual bool __fastcall IsModified();
	virtual bool __fastcall IsUnboundColumnMode();
	virtual void __fastcall CorrectRecordIndex(int ARecordIndex);
	virtual void __fastcall First();
	virtual void __fastcall Prev();
	virtual void __fastcall Next();
	virtual void __fastcall Last();
	virtual void __fastcall MoveBy(int ADistance);
	virtual void __fastcall Scroll(int ADistance);
	virtual void __fastcall SavePos();
	virtual void __fastcall RestorePos();
	virtual bool __fastcall CanAppend();
	virtual bool __fastcall CanDelete();
	virtual bool __fastcall CanInitEditing(int ARecordIndex);
	virtual bool __fastcall CanInsert();
	virtual bool __fastcall CanModify();
	virtual void __fastcall Append();
	virtual void __fastcall Cancel();
	virtual void __fastcall DoUpdateData();
	virtual void __fastcall Delete();
	virtual void __fastcall DoDeleteRecords(System::Classes::TList* AList);
	virtual void __fastcall DeleteRecords(System::Classes::TList* AList);
	virtual void __fastcall DeleteSelection();
	virtual void __fastcall Edit();
	virtual System::Variant __fastcall GetEditValue(int ARecordIndex, TcxCustomDataField* AField, Cxdatautils::TcxDataEditValueSource AEditValueSource);
	virtual void __fastcall Insert();
	virtual void __fastcall Post(bool AForcePost = false);
	virtual void __fastcall PostEditingData();
	virtual bool __fastcall SetEditValue(int ARecordIndex, TcxCustomDataField* AField, const System::Variant &AValue, Cxdatautils::TcxDataEditValueSource AEditValueSource);
	virtual void __fastcall BeginDeleting();
	virtual void __fastcall EndDeleting();
	virtual void __fastcall AssignItemValue(int ARecordIndex, TcxCustomDataField* AField, const System::Variant &AValue);
	void __fastcall ClearSavedRecord();
	void __fastcall CreateSavedRecord(int ARecordIndex);
	virtual void __fastcall DoInitInsertingRecord(int AInsertingRecordIndex, const TcxDataSummaryValues AGroupValues);
	virtual void __fastcall EditingRecord();
	virtual void __fastcall DoInsertingRecord(bool AIsAppending);
	void __fastcall InsertingRecord(bool AIsAppending);
	virtual void __fastcall ResetChanging();
	virtual void __fastcall ResetEditing();
	virtual void __fastcall ResetModified();
	virtual void __fastcall SetChanging();
	virtual void __fastcall SetEditing();
	virtual void __fastcall SetModified();
	virtual void __fastcall BeginLocate();
	virtual void __fastcall EndLocate();
	virtual void __fastcall Freeze();
	virtual void __fastcall Unfreeze();
	int __fastcall AddRecordHandle(void * AData);
	virtual int __fastcall AppendRecord();
	virtual void __fastcall DeleteRecord(int ARecordIndex);
	virtual bool __fastcall GetDetailHasChildren(int ARecordIndex, int ARelationIndex);
	virtual System::UnicodeString __fastcall GetDisplayText(int ARecordIndex, TcxCustomDataField* AField);
	virtual System::UnicodeString __fastcall GetExternalDataDisplayText(int ARecordIndex, TcxCustomDataField* AField);
	virtual System::Variant __fastcall GetExternalDataValue(int ARecordIndex, TcxCustomDataField* AField);
	virtual System::Variant __fastcall GetRecordId(int ARecordIndex);
	virtual int __fastcall GetRecordIndex();
	virtual System::Variant __fastcall GetValue(int ARecordIndex, TcxCustomDataField* AField);
	virtual Cxdatastorage::TcxValueDefReaderClass __fastcall GetValueDefReaderClass();
	virtual int __fastcall InsertRecord(int ARecordIndex);
	virtual void __fastcall LoadDataBuffer();
	void __fastcall LoadRecordHandles();
	virtual int __fastcall NativeCompare(int ARecordIndex1, int ARecordIndex2, TcxCustomDataField* AField);
	virtual int __fastcall NativeCompareFunc(int ARecordIndex1, int ARecordIndex2, TcxCustomDataField* AField);
	virtual void __fastcall SetDisplayText(int ARecordIndex, TcxCustomDataField* AField, const System::UnicodeString Value);
	virtual void __fastcall SetRecordCount(int ARecordCount);
	virtual void __fastcall SetValue(int ARecordIndex, TcxCustomDataField* AField, const System::Variant &Value);
	virtual void __fastcall ActiveChanged(bool AActive);
	virtual void __fastcall DataChanged(TcxDataChange ADataChange, int AItemIndex, int ARecordIndex);
	virtual void __fastcall DataScrolled(int ADistance);
	virtual void __fastcall LayoutChanged(TcxDataLayoutChanges ADataLayoutChanges);
	__property bool ActiveChanging = {read=FActiveChanging, write=FActiveChanging, nodefault};
	__property TcxCustomDataSource* CustomDataSource = {read=FCustomDataSource, write=SetCustomDataSource};
	__property TcxCustomDataController* DataController = {read=FDataController};
	__property int EditingRecordIndex = {read=FEditingRecordIndex, nodefault};
	__property int EditingRecordIndex1 = {read=FEditingRecordIndex1, nodefault};
	__property int EditingRecordIndex2 = {read=FEditingRecordIndex2, nodefault};
	__property int InsertedRecordIndex = {read=FInsertedRecordIndex, write=FInsertedRecordIndex, nodefault};
	__property int LocateCount = {read=FLocateCount, nodefault};
	__property int LockCount = {read=FLockCount, nodefault};
	__property bool RecreatedFieldsAfterFirst = {read=FRecreatedFieldsAfterFirst, write=FRecreatedFieldsAfterFirst, nodefault};
	__property int SavedRecordIndex = {read=FSavedRecordIndex, write=FSavedRecordIndex, nodefault};
	
public:
	__fastcall virtual TcxCustomDataProvider(TcxCustomDataController* ADataController);
	__fastcall virtual ~TcxCustomDataProvider();
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCustomDataProviderClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomDataField : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FCachedIndex;
	System::UnicodeString FExpression;
	System::TObject* FExpressionFormula;
	TcxCustomDataFieldList* FFieldList;
	int FFlags;
	bool FIsExpression;
	bool FIsInternal;
	System::TObject* FItem;
	int FLockRecreateData;
	bool FNeedConversion;
	int FNeedConversionFlag;
	bool FPrepared;
	TcxCustomDataField* FReferenceField;
	bool FTextStored;
	Cxdatastorage::TcxValueDef* FValueDef;
	Cxdatastorage::TcxValueTypeClass FValueTypeClass;
	TcxCustomDataController* __fastcall GetDataController();
	int __fastcall GetIndex();
	System::Classes::TComponent* __fastcall GetNotifier();
	bool __fastcall GetTextStored();
	Cxdatastorage::TcxValueDef* __fastcall GetValueDef();
	Cxdatastorage::TcxValueTypeClass __fastcall GetValueTypeClass();
	void __fastcall SetExpression(const System::UnicodeString AValue);
	void __fastcall SetIndex(int Value);
	void __fastcall SetIsInternal(bool Value);
	void __fastcall SetReferenceField(TcxCustomDataField* Value);
	void __fastcall SetTextStored(bool Value);
	void __fastcall SetValueTypeClass(Cxdatastorage::TcxValueTypeClass Value);
	
protected:
	void __fastcall BeginRecreateData();
	void __fastcall Changed();
	void __fastcall ClearData();
	void __fastcall CreateData();
	void __fastcall DoPropertiesChanged();
	void __fastcall EndRecreateData();
	bool __fastcall IsLoading();
	void __fastcall PrepareComparison(int AConversionFlag);
	virtual void __fastcall Reassign(TcxCustomDataField* ASource);
	void __fastcall RecreateData();
	virtual void __fastcall RemoveNotification(System::Classes::TComponent* AComponent);
	void __fastcall ResetComparison();
	virtual bool __fastcall SupportsMultiThreading();
	virtual void __fastcall UpdateExpressionFormula();
	void __fastcall UpdateExpressionState(bool AExpressionChanged = false);
	__property System::TObject* ExpressionFormula = {read=FExpressionFormula};
	__property TcxCustomDataFieldList* FieldList = {read=FFieldList};
	__property bool IsExpression = {read=FIsExpression, nodefault};
	__property bool NeedConversion = {read=FNeedConversion, write=FNeedConversion, nodefault};
	__property int NeedConversionFlag = {read=FNeedConversionFlag, write=FNeedConversionFlag, nodefault};
	__property System::Classes::TComponent* Notifier = {read=GetNotifier};
	__property bool TextStored = {read=GetTextStored, write=SetTextStored, nodefault};
	__property Cxdatastorage::TcxValueDef* ValueDef = {read=GetValueDef};
	
public:
	__fastcall virtual TcxCustomDataField(TcxCustomDataFieldList* AFieldList);
	__fastcall virtual ~TcxCustomDataField();
	virtual bool __fastcall CanModify(Cxdatautils::TcxDataEditValueSource AEditValueSource);
	virtual bool __fastcall IsUnbound();
	virtual bool __fastcall IsValueDefInternal();
	__property TcxCustomDataController* DataController = {read=GetDataController};
	__property System::UnicodeString Expression = {read=FExpression, write=SetExpression};
	__property int Flags = {read=FFlags, write=FFlags, nodefault};
	__property int Index = {read=GetIndex, write=SetIndex, nodefault};
	__property bool IsInternal = {read=FIsInternal, write=SetIsInternal, nodefault};
	__property System::TObject* Item = {read=FItem, write=FItem};
	__property TcxCustomDataField* ReferenceField = {read=FReferenceField, write=SetReferenceField};
	__property Cxdatastorage::TcxValueTypeClass ValueTypeClass = {read=GetValueTypeClass, write=SetValueTypeClass};
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCustomDataFieldClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomDataFieldList : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxCustomDataField* operator[](int Index) { return this->Items[Index]; }
	
private:
	TcxCustomDataController* FDataController;
	bool FFieldDestroyed;
	bool FHasExpressionFields;
	int FInternalCount;
	int __fastcall GetCount();
	TcxCustomDataField* __fastcall GetItem(int Index);
	int __fastcall GetItemCount();
	
protected:
	Dxcoreclasses::TdxFastList* FItems;
	void __fastcall Add(TcxCustomDataField* AField);
	void __fastcall CheckHasExpressionFields();
	void __fastcall Clear();
	void __fastcall RemoveField(TcxCustomDataField* AField);
	virtual void __fastcall RemoveNotification(System::Classes::TComponent* AComponent);
	void __fastcall Update();
	__property bool HasExpressionFields = {read=FHasExpressionFields, nodefault};
	
public:
	__fastcall virtual TcxCustomDataFieldList(TcxCustomDataController* ADataController);
	__fastcall virtual ~TcxCustomDataFieldList();
	TcxCustomDataField* __fastcall FieldByItem(System::TObject* AItem);
	void __fastcall ReassignFields(TcxCustomDataField* ADestroyedField);
	__property int Count = {read=GetCount, nodefault};
	__property TcxCustomDataController* DataController = {read=FDataController};
	__property int ItemCount = {read=GetItemCount, nodefault};
	__property TcxCustomDataField* Items[int Index] = {read=GetItem/*, default*/};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDetailInfoObject : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	System::TObject* LinkObject;
	bool HasChildren;
	bool HasChildrenAssigned;
	__fastcall virtual ~TcxDetailInfoObject();
public:
	/* TObject.Create */ inline __fastcall TcxDetailInfoObject() : System::TObject() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDetailObject : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FActiveRelationIndex;
	System::DynamicArray<TcxDetailInfoObject*> FInfoObjects;
	bool FExpanded;
	bool FIsClearing;
	TcxDetailInfoObject* __fastcall GetInfoObject(int Index);
	int __fastcall GetInfoObjectCount();
	bool __fastcall GetIsEmpty();
	System::TObject* __fastcall GetLinkObject(int Index);
	int __fastcall GetLinkObjectCount();
	void __fastcall SetInfoObject(int Index, TcxDetailInfoObject* Value);
	void __fastcall SetLinkObject(int Index, System::TObject* Value);
	
protected:
	void __fastcall CorrectCount(TcxCustomDataRelationList* ARelations);
	__property bool IsClearing = {read=FIsClearing, nodefault};
	
public:
	__fastcall TcxDetailObject();
	__fastcall virtual ~TcxDetailObject();
	void __fastcall Clear();
	bool __fastcall ClearHasChildrenFlag();
	void __fastcall ClearInfoObject(int AIndex);
	__property int ActiveRelationIndex = {read=FActiveRelationIndex, write=FActiveRelationIndex, nodefault};
	__property bool Expanded = {read=FExpanded, write=FExpanded, nodefault};
	__property int InfoObjectCount = {read=GetInfoObjectCount, nodefault};
	__property TcxDetailInfoObject* InfoObjects[int Index] = {read=GetInfoObject, write=SetInfoObject};
	__property bool IsEmpty = {read=GetIsEmpty, nodefault};
	__property int LinkObjectCount = {read=GetLinkObjectCount, nodefault};
	__property System::TObject* LinkObjects[int Index] = {read=GetLinkObject, write=SetLinkObject};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomDataRelation : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxCustomDataController* FDetailDataController;
	System::TObject* FItem;
	TcxCustomDataRelationList* FRelationList;
	TcxCustomDataController* __fastcall GetDataController();
	int __fastcall GetIndex();
	
protected:
	void __fastcall Changed();
	virtual void __fastcall RemoveDataField(TcxCustomDataField* ADataField);
	
public:
	__fastcall virtual TcxCustomDataRelation(TcxCustomDataRelationList* ARelationList, System::TObject* AItem);
	__fastcall virtual ~TcxCustomDataRelation();
	virtual void __fastcall Assign(TcxCustomDataRelation* ASource);
	__property TcxCustomDataController* DataController = {read=GetDataController};
	__property TcxCustomDataController* DetailDataController = {read=FDetailDataController};
	__property int Index = {read=GetIndex, nodefault};
	__property System::TObject* Item = {read=FItem};
	__property TcxCustomDataRelationList* RelationList = {read=FRelationList};
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCustomDataRelationClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomDetailObjects : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxDetailObject* operator[](int AIndex) { return this->Items[AIndex]; }
	
protected:
	virtual int __fastcall GetCount() = 0 ;
	virtual TcxDetailObject* __fastcall GetItem(int AIndex) = 0 ;
	virtual void __fastcall SetCount(const int Value) = 0 ;
	virtual void __fastcall SetItem(int AIndex, TcxDetailObject* const Value) = 0 ;
	
public:
	__fastcall virtual TcxCustomDetailObjects();
	virtual void __fastcall Clear() = 0 ;
	virtual void __fastcall Add(TcxDetailObject* AObject) = 0 ;
	virtual void __fastcall Delete(int AIndex) = 0 ;
	virtual void __fastcall Insert(int AIndex, TcxDetailObject* AObject) = 0 ;
	__property int Count = {read=GetCount, write=SetCount, nodefault};
	__property TcxDetailObject* Items[int AIndex] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomDetailObjects() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDetailObjects : public TcxCustomDetailObjects
{
	typedef TcxCustomDetailObjects inherited;
	
private:
	Dxcoreclasses::TdxFastObjectList* FList;
	
protected:
	virtual int __fastcall GetCount();
	virtual TcxDetailObject* __fastcall GetItem(int AIndex);
	virtual void __fastcall SetCount(const int Value);
	virtual void __fastcall SetItem(int AIndex, TcxDetailObject* const Value);
	
public:
	__fastcall virtual TcxDetailObjects();
	__fastcall virtual ~TcxDetailObjects();
	virtual void __fastcall Clear();
	virtual void __fastcall Add(TcxDetailObject* AObject);
	virtual void __fastcall Delete(int AIndex);
	virtual void __fastcall Insert(int AIndex, TcxDetailObject* AObject);
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomDataRelationList : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxCustomDataRelation* operator[](int Index) { return this->Items[Index]; }
	
private:
	TcxCustomDataController* FDataController;
	bool FHasDetails;
	TcxCustomDetailObjects* FDetailObjects;
	Dxcoreclasses::TdxFastList* FItems;
	Dxcore::TdxDefaultBoolean FIsEmpty;
	int FLockCount;
	void __fastcall AddItem(TcxCustomDataRelation* AItem);
	int __fastcall GetCount();
	TcxCustomDataRelation* __fastcall GetItem(int Index);
	void __fastcall RemoveItem(TcxCustomDataRelation* AItem);
	void __fastcall SetHasDetails(bool AHasDetails);
	bool __fastcall GetHasDetails();
	
protected:
	virtual TcxCustomDetailObjects* __fastcall CreateDetailObjects();
	void __fastcall ClearDetailObjects();
	void __fastcall Changed(TcxCustomDataRelation* ARelation);
	virtual TcxDetailObject* __fastcall GetValueAsDetailObject(int ARecordIndex);
	void __fastcall RemoveDataField(TcxCustomDataField* ADataField);
	void __fastcall Update(TcxCustomDataRelation* ARelation);
	__property TcxCustomDataController* DataController = {read=FDataController};
	__property TcxCustomDetailObjects* DetailObjects = {read=FDetailObjects};
	__property bool HasDetails = {read=GetHasDetails, nodefault};
	__property int LockCount = {read=FLockCount, nodefault};
	
public:
	__fastcall TcxCustomDataRelationList(TcxCustomDataController* ADataController);
	__fastcall virtual ~TcxCustomDataRelationList();
	TcxCustomDataRelation* __fastcall Add(System::TObject* AItem);
	void __fastcall Assign(TcxCustomDataRelationList* ASource);
	void __fastcall BeginUpdate();
	void __fastcall Clear();
	virtual bool __fastcall ClearDetailObject(int ARecordIndex, int ARelationIndex);
	void __fastcall EndUpdate();
	TcxCustomDataRelation* __fastcall FindByItem(System::TObject* AItem);
	virtual TcxDetailObject* __fastcall GetDetailObject(int ARecordIndex);
	bool __fastcall IsDetailObjectExist(int ARecordIndex, int ARelationIndex);
	bool __fastcall IsEmpty();
	void __fastcall Move(int ACurIndex, int ANewIndex);
	void __fastcall RemoveByItem(System::TObject* AItem);
	__property int Count = {read=GetCount, nodefault};
	__property TcxCustomDataRelation* Items[int Index] = {read=GetItem/*, default*/};
};

#pragma pack(pop)

typedef Dxcore::TdxSortOrder TcxDataSortOrder;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataSortFieldInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxCustomDataField* FField;
	Dxcore::TdxSortOrder FSortOrder;
	
public:
	__property TcxCustomDataField* Field = {read=FField, write=FField};
	__property Dxcore::TdxSortOrder SortOrder = {read=FSortOrder, write=FSortOrder, nodefault};
public:
	/* TObject.Create */ inline __fastcall TcxDataSortFieldInfo() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDataSortFieldInfo() { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxDataSortFieldInfoClass;

typedef void __fastcall (__closure *TcxNoParamsEvent)(void);

class PASCALIMPLEMENTATION TcxSortingFieldList : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxDataSortFieldInfo* operator[](int Index) { return this->Items[Index]; }
	
private:
	Dxcoreclasses::TdxFastList* FItems;
	TcxNoParamsEvent FOnChanged;
	int __fastcall GetCount();
	TcxDataSortFieldInfo* __fastcall GetItem(int Index);
	
protected:
	void __fastcall Add(TcxCustomDataField* AField, Dxcore::TdxSortOrder ASortOrder);
	void __fastcall Changed();
	void __fastcall Delete(int Index);
	int __fastcall Find(TcxCustomDataField* AField);
	virtual TcxDataSortFieldInfoClass __fastcall GetItemClass();
	void __fastcall Insert(int Index, TcxCustomDataField* AField, Dxcore::TdxSortOrder ASortOrder);
	virtual bool __fastcall IsIndexValid(int AIndex);
	void __fastcall Move(int ACurIndex, int ANewIndex);
	void __fastcall Remove(int AIndex);
	void __fastcall SetSortOrder(int Index, Dxcore::TdxSortOrder ASortOrder);
	
public:
	__fastcall TcxSortingFieldList();
	__fastcall virtual ~TcxSortingFieldList();
	void __fastcall AppendFrom(TcxSortingFieldList* AList);
	virtual void __fastcall ChangeSorting(TcxCustomDataField* AField, Dxcore::TdxSortOrder ASortOrder);
	void __fastcall CheckField(TcxCustomDataField* AField);
	void __fastcall Clear();
	int __fastcall SortIndexByField(TcxCustomDataField* AField);
	Dxcore::TdxSortOrder __fastcall SortOrderByField(TcxCustomDataField* AField);
	bool __fastcall SupportsMultiThreading();
	__property int Count = {read=GetCount, nodefault};
	__property TcxDataSortFieldInfo* Items[int Index] = {read=GetItem/*, default*/};
	__property TcxNoParamsEvent OnChanged = {read=FOnChanged, write=FOnChanged};
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataGroupFieldInfo : public TcxDataSortFieldInfo
{
	typedef TcxDataSortFieldInfo inherited;
	
private:
	bool FIsChildInMergedGroup;
	
public:
	__property bool IsChildInMergedGroup = {read=FIsChildInMergedGroup, write=FIsChildInMergedGroup, nodefault};
public:
	/* TObject.Create */ inline __fastcall TcxDataGroupFieldInfo() : TcxDataSortFieldInfo() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDataGroupFieldInfo() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxGroupingFieldList : public TcxSortingFieldList
{
	typedef TcxSortingFieldList inherited;
	
public:
	TcxDataGroupFieldInfo* operator[](int Index) { return this->Items[Index]; }
	
private:
	bool __fastcall GetIsChildInMergedGroupByIndex(int AIndex);
	bool __fastcall GetIsChildInMergedGroup(TcxCustomDataField* AField);
	HIDESBASE TcxDataGroupFieldInfo* __fastcall GetItem(int Index);
	void __fastcall SetIsChildInMergedGroupByIndex(int AIndex, bool AValue);
	void __fastcall SetIsChildInMergedGroup(TcxCustomDataField* AField, bool AValue);
	
protected:
	virtual void __fastcall ChangeMerge(int AIndex, bool AMergeWithLeftField = false, bool AMergeWithRightField = false);
	virtual TcxDataSortFieldInfoClass __fastcall GetItemClass();
	virtual void __fastcall InsertGroup(TcxCustomDataField* AField, int AGroupIndex, bool AMergeWithLeftField = false, bool AMergeWithRightField = false);
	virtual bool __fastcall IsMergeConsistent(int AGroupIndex, bool AMergeWithLeftField, bool AMergeWithRightField);
	virtual void __fastcall MoveGroup(int ANewGroupIndex, int AOldGroupIndex, bool AMergeWithLeftField = false, bool AMergeWithRightField = false);
	virtual void __fastcall RemoveGroup(int AIndex);
	__property bool IsChildInMergedGroupByIndex[int AGroupIndex] = {read=GetIsChildInMergedGroupByIndex, write=SetIsChildInMergedGroupByIndex};
	
public:
	void __fastcall ChangeGrouping(TcxCustomDataField* AField, int AGroupIndex, bool AMergeWithLeftField = false, bool AMergeWithRightField = false);
	virtual void __fastcall ChangeSorting(TcxCustomDataField* AField, Dxcore::TdxSortOrder ASortOrder);
	int __fastcall GroupIndexByField(TcxCustomDataField* AField);
	void __fastcall UpdateSorting(TcxSortingFieldList* ASortingFieldList);
	__property bool IsChildInMergedGroup[TcxCustomDataField* AField] = {read=GetIsChildInMergedGroup, write=SetIsChildInMergedGroup};
	__property TcxDataGroupFieldInfo* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TcxSortingFieldList.Create */ inline __fastcall TcxGroupingFieldList() : TcxSortingFieldList() { }
	/* TcxSortingFieldList.Destroy */ inline __fastcall virtual ~TcxGroupingFieldList() { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataControllerInfoHelper : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxCustomDataControllerInfo* FDataControllerInfo;
	
protected:
	__property TcxCustomDataControllerInfo* DataControllerInfo = {read=FDataControllerInfo};
	
public:
	__fastcall virtual TcxDataControllerInfoHelper(TcxCustomDataControllerInfo* ADataControllerInfo);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDataControllerInfoHelper() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxDataGroupInfoSummaryInfo : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	System::Variant Values;
public:
	/* TObject.Create */ inline __fastcall TcxDataGroupInfoSummaryInfo() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDataGroupInfoSummaryInfo() { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataGroupInfo : public System::TObject
{
	typedef System::TObject inherited;
	
	
private:
	typedef System::DynamicArray<TcxDataGroupInfoSummaryInfo*> _TcxDataGroupInfo__1;
	
	
private:
	int FGroupedItemCount;
	int FLevel;
	TcxDataGroups* FOwner;
	_TcxDataGroupInfo__1 FSummaryInfos;
	void __fastcall ClearSummaryInfos();
	int __fastcall GetRecordCount();
	TcxDataGroupInfoSummaryInfo* __fastcall GetSummaryInfos(int ALevelGroupedItemIndex);
	System::Variant __fastcall GetSummaryValues();
	void __fastcall SetLevel(int AValue);
	
protected:
	void __fastcall UpdateSummaryInfos();
	__property TcxDataGroups* Owner = {read=FOwner};
	
public:
	bool Expanded;
	int FirstRecordListIndex;
	int LastRecordListIndex;
	int RowIndex;
	__fastcall TcxDataGroupInfo(TcxDataGroups* AOwner);
	__fastcall virtual ~TcxDataGroupInfo();
	void __fastcall AssignTo(TcxDataGroupInfo* ADataGroupInfo);
	bool __fastcall Contains(int ARecordListIndex);
	__property int GroupedItemCount = {read=FGroupedItemCount, nodefault};
	__property int Level = {read=FLevel, write=SetLevel, nodefault};
	__property int RecordCount = {read=GetRecordCount, nodefault};
	__property TcxDataGroupInfoSummaryInfo* SummaryInfos[int AGroupedItemIndex] = {read=GetSummaryInfos};
	__property System::Variant SummaryValues = {read=GetSummaryValues};
};

#pragma pack(pop)

struct DECLSPEC_DRECORD TcxGroupsRowInfo
{
public:
	bool Expanded;
	int Level;
	int Index;
	int RecordListIndex;
};


struct DECLSPEC_DRECORD TcxDataGroupCompareInfo
{
public:
	TcxDataGroupInfo* Info;
	int RecordIndex;
};


typedef TcxDataGroupCompareInfo *PcxDataGroupCompareInfo;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGroupFieldInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxCustomDataField* FField;
	int FLevel;
	
public:
	__fastcall TcxGroupFieldInfo(TcxCustomDataField* AField, int ALevel);
	__property TcxCustomDataField* Field = {read=FField};
	__property int Level = {read=FLevel, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGroupFieldInfo() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataGroups : public TcxDataControllerInfoHelper
{
	typedef TcxDataControllerInfoHelper inherited;
	
public:
	TcxDataGroupInfo* operator[](int Index) { return this->Items[Index]; }
	
private:
	Dxcoreclasses::TdxFastObjectList* FGroupFieldInfos;
	TcxGroupFieldInfo* __fastcall GetGroupFieldInfo(int Index);
	int __fastcall GetGroupFieldInfoCount();
	TcxDataGroupInfo* __fastcall GetItem(int Index);
	int __fastcall GetItemCount();
	int __fastcall GetLevelCount();
	int __fastcall GetRowCount();
	
protected:
	Dxcoreclasses::TdxFastList* FItems;
	void __fastcall Add(TcxDataGroupInfo* const ADataGroupInfo);
	void __fastcall AddGroupFieldInfo(TcxCustomDataField* AField, int ALevel);
	TcxDataGroupInfo* __fastcall AddEmpty();
	void __fastcall AddToList(TcxDataGroupInfo* const ADataGroupInfo);
	virtual void __fastcall Clear();
	bool __fastcall IsLevelContainingField(int ALevel, int AFieldIndex);
	virtual bool __fastcall IsRowIndexValid(int ARowIndex);
	int __fastcall Find(int ARowIndex, TcxDataGroupInfo* &AItem);
	int __fastcall FindByIndex(int ARecordListIndex, int ALevel);
	virtual int __fastcall GetFirstDataRecordListIndex(TcxDataGroupInfo* AInfo);
	virtual int __fastcall GetLastDataRecordListIndex(TcxDataGroupInfo* AInfo);
	TcxCustomDataField* __fastcall GetFieldByLevelGroupedFieldIndex(int ALevel, int ALevelGroupedFieldIndex);
	int __fastcall GetFieldIndexByLevelGroupedFieldIndex(int ALevel, int ALevelGroupedFieldIndex);
	int __fastcall GetLevelGroupedFieldCount(int ALevel);
	int __fastcall GetLevelByFieldGroupIndex(int AIndex);
	virtual TcxGroupsRowInfo __fastcall GetRowInfo(int ARowIndex);
	TcxDataGroupInfo* __fastcall GetTopVisibleItem(int ARowIndex, int &ACurIndex);
	int __fastcall IndexOf(TcxDataGroupInfo* AItem);
	bool __fastcall IsVisible(int AIndex);
	virtual bool __fastcall MakeVisible(int AIndex, bool AExpand);
	__property int GroupFieldInfoCount = {read=GetGroupFieldInfoCount, nodefault};
	__property TcxGroupFieldInfo* GroupFieldInfos[int Index] = {read=GetGroupFieldInfo};
	
public:
	__fastcall virtual TcxDataGroups(TcxCustomDataControllerInfo* ADataControllerInfo);
	__fastcall virtual ~TcxDataGroups();
	virtual void __fastcall ChangeExpanding(int ARowIndex, bool AExpanded, bool ARecursive);
	virtual void __fastcall FullExpanding(bool AExpanded);
	virtual int __fastcall GetChildCount(int AIndex);
	virtual int __fastcall GetChildIndex(int AParentIndex, int AIndex);
	int __fastcall GetChildRecordListIndex(int AParentIndex, int AIndex);
	virtual int __fastcall GetDataRecordListIndex(TcxDataGroupInfo* AInfo);
	int __fastcall GetFirstLevelCount();
	int __fastcall GetFirstLevelIndex(int AIndex);
	int __fastcall GetIndexByRowIndex(int ARowIndex);
	int __fastcall GetIndexByRowIndexLevel(int ARowIndex, int ALevel);
	int __fastcall GetLevel(int AIndex);
	int __fastcall GetParentIndex(int AChildIndex);
	virtual void __fastcall Rebuild();
	void __fastcall SetItem(int AIndex, TcxDataGroupInfo* AItem);
	__property int Count = {read=GetItemCount, nodefault};
	__property TcxDataGroupInfo* Items[int Index] = {read=GetItem/*, default*/};
	__property int LevelCount = {read=GetLevelCount, nodefault};
	__property TcxGroupsRowInfo RowInfo[int RowIndex] = {read=GetRowInfo};
	__property int RowCount = {read=GetRowCount, nodefault};
};

#pragma pack(pop)

typedef System::TMetaClass* TcxDataGroupsClass;

enum DECLSPEC_DENUM TcxDataControllerInfoChange : unsigned char { dcicLoad, dcicGrouping, dcicSorting, dcicFocusedRow, dcicView, dcicExpanding, dcicResetFocusedRow, dcicSelection, dcicSummary, dcicFocusedRecord, dcicFindCriteria, dcicRowFixing, dcicBookmark };

typedef System::Set<TcxDataControllerInfoChange, TcxDataControllerInfoChange::dcicLoad, TcxDataControllerInfoChange::dcicBookmark> TcxDataControllerInfoChanges;

struct DECLSPEC_DRECORD TcxRowInfo
{
public:
	bool Expanded;
	int Level;
	int RecordIndex;
	int DataRowIndex;
	int RowIndex;
	int GroupIndex;
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataFocusingInfo : public TcxDataControllerInfoHelper
{
	typedef TcxDataControllerInfoHelper inherited;
	
private:
	bool FChangedFlag;
	int FLevel;
	bool FPrevNewItemRowFocused;
	int FPrevRecordIndex;
	int FRecordIndex;
	int FRowIndex;
	
protected:
	virtual void __fastcall Assign(TcxDataFocusingInfo* AFocusingInfo);
	virtual void __fastcall Clear();
	virtual bool __fastcall IsEqual(TcxDataFocusingInfo* AFocusingInfo);
	virtual bool __fastcall IsNeedUpdate();
	virtual void __fastcall ResetPos();
	virtual void __fastcall SavePos();
	void __fastcall UpdatePos(/* out */ bool &AChanged);
	void __fastcall ValidateLevel();
	void __fastcall ValidateRowIndex(int AMaxIndex);
	
public:
	__fastcall virtual TcxDataFocusingInfo(TcxCustomDataControllerInfo* ADataControllerInfo);
	__property int Level = {read=FLevel, write=FLevel, nodefault};
	__property int RecordIndex = {read=FRecordIndex, write=FRecordIndex, nodefault};
	__property int RowIndex = {read=FRowIndex, write=FRowIndex, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDataFocusingInfo() { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxDataFocusingInfoClass;

enum DECLSPEC_DENUM TcxDataExpandingInfoState : unsigned char { eisExpanded, eisSelected };

typedef System::Set<TcxDataExpandingInfoState, TcxDataExpandingInfoState::eisExpanded, TcxDataExpandingInfoState::eisSelected> TcxDataExpandingInfoStateSet;

class PASCALIMPLEMENTATION TcxDataExpandingInfo : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	int GroupIndex;
	System::Variant Value;
	TcxDataExpandingInfoStateSet State;
public:
	/* TObject.Create */ inline __fastcall TcxDataExpandingInfo() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDataExpandingInfo() { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataExpandingInfos : public TcxDataControllerInfoHelper
{
	typedef TcxDataControllerInfoHelper inherited;
	
public:
	TcxDataExpandingInfo* operator[](int Index) { return this->Items[Index]; }
	
private:
	Dxcoreclasses::TdxFastList* FFields;
	Dxcoreclasses::TdxFastObjectList* FItems;
	TcxDataExpandingInfoStateSet FSaveStates;
	int __fastcall Find(TcxCustomDataField* AField);
	int __fastcall GetCount();
	bool __fastcall GetEmpty();
	TcxCustomDataField* __fastcall GetField(int Index);
	int __fastcall GetFieldCount();
	TcxDataExpandingInfo* __fastcall GetItem(int Index);
	
public:
	void __fastcall AddField(TcxCustomDataField* AField);
	void __fastcall AddItem(int AGroupIndex, const System::Variant &AValue, TcxDataExpandingInfoStateSet AState);
	void __fastcall CheckField(TcxCustomDataField* AField);
	void __fastcall Clear();
	void __fastcall ClearFields();
	void __fastcall ClearValues();
	__fastcall virtual TcxDataExpandingInfos(TcxCustomDataControllerInfo* ADataControllerInfo);
	__fastcall virtual ~TcxDataExpandingInfos();
	__property int Count = {read=GetCount, nodefault};
	__property bool Empty = {read=GetEmpty, nodefault};
	__property int FieldCount = {read=GetFieldCount, nodefault};
	__property TcxCustomDataField* Fields[int Index] = {read=GetField};
	__property TcxDataExpandingInfo* Items[int Index] = {read=GetItem/*, default*/};
	__property TcxDataExpandingInfoStateSet SaveStates = {read=FSaveStates, write=FSaveStates, nodefault};
};

#pragma pack(pop)

typedef System::TMetaClass* TcxDataExpandingInfosClass;

enum DECLSPEC_DENUM TcxDataControllerRowFixedState : unsigned char { rfsNotFixed, rfsFixedToTop, rfsFixedToBottom };

class PASCALIMPLEMENTATION TcxDataFixingInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Dxcoreclasses::TdxFastList* FBottom;
	bool FEmpty;
	Dxcoreclasses::TdxFastList* FTop;
	TcxNoParamsEvent FOnChanged;
	Dxcoreclasses::TdxFastList* __fastcall GetFixedRecordIndexes(bool ATop);
	TcxDataControllerRowFixedState __fastcall GetFixedState(int ARecordIndex);
	void __fastcall SetFixedState(int ARecordIndex, TcxDataControllerRowFixedState AValue);
	
protected:
	void __fastcall Changed();
	void __fastcall Delete(int ARecordIndex);
	bool __fastcall DeleteCore(int ARecordIndex);
	__property bool Empty = {read=FEmpty, nodefault};
	__property Dxcoreclasses::TdxFastList* FixedRecordIndexes[bool ATop] = {read=GetFixedRecordIndexes};
	__property TcxDataControllerRowFixedState FixedState[int ARecordIndex] = {read=GetFixedState, write=SetFixedState};
	__property TcxNoParamsEvent OnChanged = {read=FOnChanged, write=FOnChanged};
	
public:
	__fastcall virtual TcxDataFixingInfo();
	__fastcall virtual ~TcxDataFixingInfo();
};


struct DECLSPEC_DRECORD TcxDataSelectionInfo
{
public:
	int Level;
	int RecordIndex;
	int RowIndex;
};


typedef TcxDataSelectionInfo *PcxDataSelectionInfo;

class PASCALIMPLEMENTATION TcxDataSelection : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	PcxDataSelectionInfo operator[](int Index) { return this->Items[Index]; }
	
private:
	int FAnchorRowIndex;
	TcxCustomDataController* FDataController;
	Dxcoreclasses::TdxFastList* FItems;
	Dxcoreclasses::TdxFastList* FFields;
	TcxNoParamsEvent FOnChanged;
	int __fastcall GetCount();
	TcxCustomDataField* __fastcall GetField(int Index);
	int __fastcall GetFieldCount();
	PcxDataSelectionInfo __fastcall GetItem(int Index);
	
protected:
	void __fastcall Changed();
	void __fastcall CheckAfterFiltering();
	virtual void __fastcall ClearAnchor();
	int __fastcall CompareSelections(void * AItem1, void * AItem2);
	virtual void __fastcall InternalAdd(int AIndex, int ARowIndex, int ARecordIndex, int ALevel);
	virtual void __fastcall InternalClear();
	virtual void __fastcall InternalDelete(int AIndex);
	virtual void __fastcall SetInternalCount(int ACount);
	
public:
	__fastcall virtual TcxDataSelection(TcxCustomDataController* ADataController);
	__fastcall virtual ~TcxDataSelection();
	virtual void __fastcall Add(int AIndex, int ARowIndex, int ARecordIndex, int ALevel);
	void __fastcall AddField(TcxCustomDataField* AField);
	void __fastcall Clear();
	void __fastcall ClearAll();
	void __fastcall ClearFields();
	void __fastcall Delete(int AIndex);
	int __fastcall FindByGroupIndex(int AGroupIndex);
	int __fastcall FindByRecordIndex(int ARecordIndex);
	virtual bool __fastcall FindByRowIndex(int ARowIndex, int &AIndex);
	bool __fastcall IsRecordSelected(int ARecordIndex);
	bool __fastcall IsRowSelected(int ARowIndex);
	void __fastcall Sort();
	__property int Count = {read=GetCount, nodefault};
	__property TcxCustomDataController* DataController = {read=FDataController};
	__property int FieldCount = {read=GetFieldCount, nodefault};
	__property TcxCustomDataField* Fields[int Index] = {read=GetField};
	__property PcxDataSelectionInfo Items[int Index] = {read=GetItem/*, default*/};
	__property int AnchorRowIndex = {read=FAnchorRowIndex, nodefault};
	__property TcxNoParamsEvent OnChanged = {read=FOnChanged, write=FOnChanged};
};


typedef System::TMetaClass* TcxDataSelectionClass;

enum DECLSPEC_DENUM TcxDataControllerComparisonMode : unsigned char { dccmSorting, dccmGrouping, dccmOther };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomDataControllerInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxDataControllerComparisonMode FComparisonMode;
	TcxCustomDataController* FDataController;
	TcxDataGroups* FDataGroups;
	TcxDataExpandingInfos* FExpandingInfo;
	bool FExpandingFlag;
	TcxDataFixingInfo* FFixingInfo;
	bool FFocusingFlag;
	TcxDataFocusingInfo* FFocusingInfo;
	TcxGroupingFieldList* FGroupingFieldList;
	bool FInCanFocusedRowChanging;
	bool FInfoCalculation;
	int FLockCount;
	TcxDataFocusingInfo* FPrevFocusingInfo;
	Dxcoreclasses::TdxFastList* FRecordList;
	bool FRefreshNeeded;
	TcxDataSelection* FSelection;
	TcxSortingFieldList* FSortingFieldList;
	TcxSortingFieldList* FTotalSortingFieldList;
	bool FHasLockedInfoState;
	int FStateInfoCount;
	bool FSaveInfoSkipFlag;
	int __fastcall CompareRecords(void * ARecord1, void * ARecord2);
	int __fastcall GetDataRowCount();
	int __fastcall GetFocusedDataRowIndex();
	int __fastcall GetFocusedRecordIndex();
	int __fastcall GetFocusedRowIndex();
	int __fastcall GetGroupLevelCount();
	bool __fastcall GetNewItemRowFocusingChanged();
	int __fastcall GetPrevFocusedRecordIndex();
	int __fastcall GetPrevFocusedRowIndex();
	TcxDataControllerRowFixedState __fastcall GetRowFixedState(int ARowIndex);
	void __fastcall SetFocusedRowIndex(int Value);
	void __fastcall SetRowFixedState(int ARowIndex, TcxDataControllerRowFixedState AValue);
	
protected:
	TcxDataControllerInfoChanges FChanges;
	void __fastcall CheckAfterCollapsing();
	void __fastcall CheckFocusingAfterFilter();
	void __fastcall CheckInfo();
	void __fastcall ClearInfo();
	void __fastcall SaveInfo();
	void __fastcall LockStateInfo(bool AUseLockedUpdate = true);
	void __fastcall UnlockStateInfo(bool AUseLockedUpdate = true);
	TcxDataExpandingInfoStateSet __fastcall GetStateInfoSet(bool ACheckChanges);
	bool __fastcall CanFocusedRowChanging(int ARowIndex);
	virtual void __fastcall CheckExpanding();
	virtual void __fastcall PrepareSelectionBeforeExpandGroups();
	virtual void __fastcall RebuildSelectionAfterExpandGroups();
	virtual bool __fastcall CanCreateGroups();
	bool __fastcall CanFixRows();
	virtual void __fastcall CheckFocusing();
	virtual void __fastcall CheckSelectionAnchor();
	virtual void __fastcall ClearGroups();
	void __fastcall CorrectFocusedRow(int ARowIndex);
	virtual void __fastcall CreateGroups();
	void __fastcall DoChangeFocusedRow(int AValue, bool AIsInternal);
	virtual void __fastcall DoFilter();
	virtual void __fastcall DoFindCriteriaUpdate(bool ADataChanged, bool AFocusChanged);
	virtual void __fastcall DoFixRows();
	virtual void __fastcall DoGrouping();
	virtual void __fastcall DoLoad();
	virtual void __fastcall DoSort();
	void __fastcall DoBeginSummary();
	void __fastcall DoEndSummary();
	virtual void __fastcall DoUpdate(bool ASummaryChanged);
	virtual int __fastcall FindDataGroup(int ARecordListIndex);
	virtual int __fastcall FindFocusedRow(bool ANearest);
	int __fastcall FirstNonFixedRecordListIndex();
	virtual void __fastcall FixRows(bool ATop);
	void __fastcall ForwardChanges();
	virtual TcxDataExpandingInfosClass __fastcall GetDataExpandingInfosClass();
	virtual TcxDataFocusingInfoClass __fastcall GetDataFocusingInfoClass();
	virtual TcxDataGroupsClass __fastcall GetDataGroupsClass();
	virtual int __fastcall GetFixedBottomRowCount();
	virtual TcxDataControllerRowFixedState __fastcall GetFixedStateByFocusingInfo();
	virtual int __fastcall GetFixedTopRowCount();
	virtual int __fastcall GetInternalRecordCount();
	virtual int __fastcall GetInternalRecordListIndex(int ARecordIndex);
	virtual int __fastcall GetRecordListIndexByFocusingInfo();
	virtual int __fastcall GetSelectionMaxRecordCount();
	void __fastcall GetTotalSortingFields();
	bool __fastcall IsAlwaysExpanded();
	bool __fastcall IsGrouped();
	virtual bool __fastcall IsResetFocusingNeeded();
	bool __fastcall IsSummaryForSelectedRecords();
	bool __fastcall IsValidDataGroupInfo();
	int __fastcall LastNonFixedRecordListIndex();
	virtual int __fastcall LocateGroupByLevel(int AGroupIndex, int ALevel);
	virtual int __fastcall LocateDetail(int AGroupIndex, int ARecordListIndex, bool AMakeVisible);
	void __fastcall PrepareSorting(TcxDataControllerComparisonMode AMode);
	void __fastcall RecalcSelection();
	void __fastcall RefreshBookmark();
	void __fastcall RefreshGroups();
	virtual void __fastcall ResetFocusing();
	virtual void __fastcall SaveExpanding(TcxDataExpandingInfoStateSet ASaveStates);
	virtual void __fastcall TruncateSelection();
	void __fastcall UnprepareSorting();
	virtual void __fastcall Update();
	virtual void __fastcall UpdateGroupInfo();
	void __fastcall UpdatePrevFocusedInfo();
	virtual bool __fastcall ChangeChildrenSelection(int AGroupIndex, bool ASelection, bool ANeedCheckParent = true);
	virtual bool __fastcall ChangeGroupSelection(int AGroupIndex, bool ASelection);
	bool __fastcall ChangeRecordSelection(int ARecordIndex, bool ASelection);
	virtual bool __fastcall CheckParentSelection(int AChildRecordIndex, int AParentLevel);
	virtual void __fastcall CheckParentsSelection(int AChildRecordIndex);
	virtual void __fastcall SelectRow(int ARowIndex);
	virtual void __fastcall UnselectRow(int ARowIndex);
	void __fastcall DoSortBySummary();
	bool __fastcall IsSortingBySummary(int ALevel)/* overload */;
	bool __fastcall IsSortingBySummary()/* overload */;
	__property TcxDataControllerInfoChanges Changes = {read=FChanges, nodefault};
	__property TcxDataExpandingInfos* ExpandingInfo = {read=FExpandingInfo};
	__property TcxDataFixingInfo* FixingInfo = {read=FFixingInfo};
	__property int FixedBottomRowCount = {read=GetFixedBottomRowCount, nodefault};
	__property int FixedTopRowCount = {read=GetFixedTopRowCount, nodefault};
	__property TcxDataFocusingInfo* FocusingInfo = {read=FFocusingInfo};
	__property int GroupLevelCount = {read=GetGroupLevelCount, nodefault};
	__property bool HasLockedInfoState = {read=FHasLockedInfoState, nodefault};
	__property TcxDataFocusingInfo* PrevFocusingInfo = {read=FPrevFocusingInfo};
	__property Dxcoreclasses::TdxFastList* RecordList = {read=FRecordList};
	__property bool RefreshNeeded = {read=FRefreshNeeded, write=FRefreshNeeded, nodefault};
	__property TcxDataControllerRowFixedState RowFixedState[int ARowIndex] = {read=GetRowFixedState, write=SetRowFixedState};
	__property TcxSortingFieldList* SortingFieldList = {read=FSortingFieldList};
	__property TcxSortingFieldList* TotalSortingFieldList = {read=FTotalSortingFieldList};
	
public:
	__fastcall virtual TcxCustomDataControllerInfo(TcxCustomDataController* ADataController);
	__fastcall virtual ~TcxCustomDataControllerInfo();
	void __fastcall BeginUpdate();
	void __fastcall EndUpdate();
	void __fastcall CheckChanges();
	void __fastcall CheckRowIndex(int ARowIndex);
	virtual int __fastcall GetInternalRecordIndex(int ARecordListIndex);
	void __fastcall Refresh();
	void __fastcall RefreshFocused();
	void __fastcall RefreshSummary(bool ARedrawOnly);
	void __fastcall RefreshView();
	void __fastcall ExpandingChanged();
	void __fastcall FindCriteriaChanged();
	void __fastcall FixingChanged();
	void __fastcall FocusedRecordChanged(bool AChangedFlag);
	void __fastcall GroupingChanged();
	virtual void __fastcall SelectionChanged();
	void __fastcall SortingChanged();
	virtual void __fastcall RemoveField(TcxCustomDataField* AField);
	void __fastcall UpdateField(TcxCustomDataField* AField);
	void __fastcall ChangeSortIndex(TcxCustomDataField* AField, int ASortIndex);
	void __fastcall ChangeSorting(TcxCustomDataField* AField, Dxcore::TdxSortOrder ASortOrder);
	void __fastcall ClearSorting(bool AKeepGroupedItems);
	void __fastcall ChangeExpanding(int ARowIndex, bool AExpanded, bool ARecursive);
	void __fastcall ChangeGrouping(TcxCustomDataField* AField, int AGroupIndex, bool AMergeWithLeftItem = false, bool AMergeWithRightItem = false);
	void __fastcall ChangeGroupMerging(TcxCustomDataField* AField, bool AValue);
	void __fastcall ClearGrouping();
	int __fastcall CompareGroupRecords(int ARecordIndex1, int ARecordIndex2, int AIndex);
	void __fastcall FullCollapse();
	void __fastcall FullExpand();
	int __fastcall GetNearestRowIndex(int ARowIndex);
	int __fastcall GetRowCount();
	int __fastcall GetRowIndexByRecordIndex(int ARecordIndex, bool AMakeVisible);
	virtual TcxRowInfo __fastcall GetRowInfo(int ARowIndex);
	void __fastcall ChangeRowSelection(int ARowIndex, bool ASelection);
	void __fastcall ClearSelection();
	void __fastcall ClearSelectionAnchor();
	int __fastcall GetSelectedCount();
	int __fastcall GetSelectedRowIndex(int Index);
	bool __fastcall GroupContainsSelectedRows(int ARowIndex);
	bool __fastcall IsRowSelected(int ARowIndex);
	__property TcxDataSelection* Selection = {read=FSelection};
	__property int DataRowCount = {read=GetDataRowCount, nodefault};
	__property int FocusedDataRowIndex = {read=GetFocusedDataRowIndex, nodefault};
	__property int FocusedRecordIndex = {read=GetFocusedRecordIndex, nodefault};
	__property int FocusedRowIndex = {read=GetFocusedRowIndex, write=SetFocusedRowIndex, nodefault};
	__property bool NewItemRowFocusingChanged = {read=GetNewItemRowFocusingChanged, nodefault};
	__property int PrevFocusedRecordIndex = {read=GetPrevFocusedRecordIndex, nodefault};
	__property int PrevFocusedRowIndex = {read=GetPrevFocusedRowIndex, nodefault};
	__property TcxDataControllerComparisonMode ComparisonMode = {read=FComparisonMode, nodefault};
	__property TcxCustomDataController* DataController = {read=FDataController};
	__property TcxDataGroups* DataGroups = {read=FDataGroups};
	__property TcxGroupingFieldList* GroupingFieldList = {read=FGroupingFieldList};
	__property int LockCount = {read=FLockCount, nodefault};
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxDataFilterCriteriaItem : public Cxfilter::TcxFilterCriteriaItem
{
	typedef Cxfilter::TcxFilterCriteriaItem inherited;
	
private:
	static const System::WideChar InvariantExpressionFlag = (System::WideChar)(0x1);
	
	
private:
	TcxCustomDataField* FExpressionField;
	TcxCustomDataController* __fastcall GetDataController();
	TcxCustomDataField* __fastcall GetExpressionField();
	TcxCustomDataField* __fastcall GetField();
	
protected:
	virtual TcxCustomDataField* __fastcall CreateExpressionField();
	virtual void __fastcall ExpressionChanged();
	virtual System::Variant __fastcall GetDataValue(System::TObject* AData);
	virtual System::Variant __fastcall GetExpressionValue(System::TObject* AData, /* out */ bool &AHasError);
	virtual System::UnicodeString __fastcall GetFieldCaption();
	virtual System::UnicodeString __fastcall GetFieldName();
	virtual System::TObject* __fastcall GetItemLink();
	virtual bool __fastcall IsItemLinkSupportsMultiThreading();
	virtual System::UnicodeString __fastcall ReadExpression(System::Classes::TStream* AStream, bool AIsUnicode);
	virtual void __fastcall SetItemLink(System::TObject* Value);
	virtual bool __fastcall SupportsMultiThreading();
	virtual void __fastcall UpdateExpressionField();
	virtual void __fastcall WriteExpression(System::Classes::TStream* AStream, const System::UnicodeString AExpression);
	__property TcxCustomDataField* ExpressionField = {read=GetExpressionField};
	
public:
	__fastcall virtual ~TcxDataFilterCriteriaItem();
	__property TcxCustomDataController* DataController = {read=GetDataController};
	__property TcxCustomDataField* Field = {read=GetField};
public:
	/* TcxFilterCriteriaItem.Create */ inline __fastcall virtual TcxDataFilterCriteriaItem(Cxfilter::TcxFilterCriteriaItemList* AOwner, System::TObject* AItemLink, Cxfilter::TcxFilterOperatorKind AOperatorKind, const System::Variant &AValue, const System::UnicodeString ADisplayValue) : Cxfilter::TcxFilterCriteriaItem(AOwner, AItemLink, AOperatorKind, AValue, ADisplayValue) { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataFilterValueList : public Cxfilter::TcxFilterValueList
{
	typedef Cxfilter::TcxFilterValueList inherited;
	
private:
	TcxCustomDataController* __fastcall GetDataController();
	
protected:
	void __fastcall Load(int AItemIndex, bool AInitSortByDisplayText, bool AUseFilteredValues, bool AAddValueItems, bool AUniqueOnly, bool AFilteredValuesShowFilteredItemsOnly)/* overload */;
	
public:
	virtual void __fastcall Load(int AItemIndex, bool AInitSortByDisplayText = true, bool AUseFilteredValues = false, bool AAddValueItems = true)/* overload */;
	__property TcxCustomDataController* DataController = {read=GetDataController};
public:
	/* TcxFilterValueList.Create */ inline __fastcall virtual TcxDataFilterValueList(Cxfilter::TcxFilterCriteria* ACriteria) : Cxfilter::TcxFilterValueList(ACriteria) { }
	/* TcxFilterValueList.Destroy */ inline __fastcall virtual ~TcxDataFilterValueList() { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TcxDataFilterGetValueListEvent)(Cxfilter::TcxFilterCriteria* Sender, int AItemIndex, TcxDataFilterValueList* AValueList);

class PASCALIMPLEMENTATION TcxDataFilterCriteria : public Cxfilter::TcxFilterCriteria
{
	typedef Cxfilter::TcxFilterCriteria inherited;
	
private:
	bool FActive;
	TcxCustomDataController* FDataController;
	bool FDestroying;
	TcxDataFilterGetValueListEvent FOnGetValueList;
	void __fastcall SetActive(bool Value);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	bool __fastcall DoFilterRecord(int ARecordIndex);
	virtual int __fastcall GetIDByItemLink(System::TObject* AItemLink);
	virtual System::UnicodeString __fastcall GetNameByItemLink(System::TObject* AItemLink);
	virtual Cxfilter::TcxFilterCriteriaItemClass __fastcall GetItemClass();
	virtual System::TObject* __fastcall GetItemLinkByID(int AID);
	virtual System::TObject* __fastcall GetItemLinkByName(const System::UnicodeString AName);
	virtual Cxfilter::TcxFilterValueListClass __fastcall GetValueListClass();
	bool __fastcall IsDestroying();
	virtual bool __fastcall IsExpressionsSupported();
	virtual bool __fastcall IsInternal();
	bool __fastcall IsLoading();
	virtual void __fastcall Update();
	__property bool Destroying = {read=FDestroying, nodefault};
	
public:
	__fastcall virtual TcxDataFilterCriteria(TcxCustomDataController* ADataController);
	__fastcall virtual ~TcxDataFilterCriteria();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source, bool AIgnoreItemNames = false);
	virtual void __fastcall AssignEvents(System::Classes::TPersistent* Source);
	virtual TcxDataFilterValueList* __fastcall CreateValueList();
	virtual Cxfilter::TcxFilterCriteriaItem* __fastcall FindItemByItemLink(System::TObject* AItemLink);
	virtual bool __fastcall IsFiltering();
	void __fastcall RemoveItemByField(TcxCustomDataField* AField);
	__property TcxCustomDataController* DataController = {read=FDataController};
	
__published:
	__property bool Active = {read=FActive, write=SetActive, default=0};
	__property TcxDataFilterGetValueListEvent OnGetValueList = {read=FOnGetValueList, write=FOnGetValueList};
};


typedef System::TMetaClass* TcxDataFilterCriteriaClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataFilterList : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	TcxDataFilterCriteria* operator[](int Index) { return this->Items[Index]; }
	
private:
	TcxDataFilterCriteria* __fastcall GetItem(int Index);
	
protected:
	void __fastcall RemoveItemByField(TcxCustomDataField* AField);
	
public:
	virtual void __fastcall Clear();
	__property TcxDataFilterCriteria* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TcxDataFilterList() { }
	
public:
	/* TObject.Create */ inline __fastcall TcxDataFilterList() : System::Classes::TList() { }
	
};

#pragma pack(pop)

enum DECLSPEC_DENUM TcxDataFindCriteriaBehavior : unsigned char { fcbDefault, fcbFilter, fcbSearch };

enum DECLSPEC_DENUM TcxDataFindCriteriaChange : unsigned char { fccText, fccBehavior, fccItems, fccUseExtendedSyntax };

typedef System::Set<TcxDataFindCriteriaChange, TcxDataFindCriteriaChange::fccText, TcxDataFindCriteriaChange::fccUseExtendedSyntax> TcxDataFindCriteriaChanges;

typedef void __fastcall (__closure *TcxDataFindCriteriaBeforeChangeEvent)(TcxDataFindCriteria* Sender, const TcxDataFindCriteriaChange AChange);

typedef void __fastcall (__closure *TcxDataFindCriteriaChangedEvent)(TcxDataFindCriteria* Sender, const TcxDataFindCriteriaChanges AChanges);

enum DECLSPEC_DENUM TcxDataFindCriteriaConditionOperation : unsigned char { fccoOr, fccoAnd, fccoNot };

typedef System::StaticArray<int, 3> TcxDataFindCriteriaConditionOperations;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomDataFindCriteria : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	Cxfilter::TcxFilterCriteria* FFilter;
	System::TObject* FOwner;
	
protected:
	virtual Cxfilter::TcxFilterCriteria* __fastcall CreateFilter() = 0 ;
	virtual void __fastcall InitFilter();
	__property Cxfilter::TcxFilterCriteria* Filter = {read=FFilter};
	__property System::TObject* Owner = {read=FOwner};
	
public:
	__fastcall virtual TcxCustomDataFindCriteria(System::TObject* AOwner);
	__fastcall virtual ~TcxCustomDataFindCriteria();
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataFindCriteriaCondition : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxDataFindCriteriaConditionOperation FOperation;
	System::UnicodeString FText;
	
public:
	__fastcall virtual TcxDataFindCriteriaCondition(System::UnicodeString AText, TcxDataFindCriteriaConditionOperation AOperation);
	__property TcxDataFindCriteriaConditionOperation Operation = {read=FOperation, nodefault};
	__property System::UnicodeString Text = {read=FText};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDataFindCriteriaCondition() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataFindCriteriaConditions : public Dxcoreclasses::TdxFastObjectList
{
	typedef Dxcoreclasses::TdxFastObjectList inherited;
	
public:
	TcxDataFindCriteriaCondition* operator[](int Index) { return this->Items[Index]; }
	
private:
	void __fastcall CheckMissedCondition(System::UnicodeString AText, System::UnicodeString ALeadingQuotes, bool AIsQuoted, TcxDataFindCriteriaConditionOperation AOperation);
	TcxDataFindCriteriaCondition* __fastcall CreateCondition(const System::UnicodeString AText, TcxDataFindCriteriaConditionOperation AOperation = (TcxDataFindCriteriaConditionOperation)(0x0));
	HIDESBASE TcxDataFindCriteriaCondition* __fastcall GetItem(int Index);
	void __fastcall IncrementOperationCount(TcxDataFindCriteriaConditionOperation AOperation);
	bool __fastcall PopulatePlus(const System::UnicodeString AText, bool AIsQuoted, TcxDataFindCriteriaConditionOperation &AOperation);
	bool __fastcall PopulateMinus(const System::UnicodeString AText, bool AIsQuoted, TcxDataFindCriteriaConditionOperation &AOperation);
	bool __fastcall PopulateSpace(System::UnicodeString &AText, System::UnicodeString &ALeadingQuotes, bool &AIsQuoted, TcxDataFindCriteriaConditionOperation &AOperation);
	bool __fastcall PopulateQuote(System::UnicodeString &AText, System::UnicodeString &ALeadingQuotes, bool &AIsQuoted, TcxDataFindCriteriaConditionOperation &AOperation);
	
protected:
	TcxDataFindCriteriaConditionOperations Operations;
	
public:
	virtual void __fastcall Clear();
	virtual void __fastcall Populate(const System::UnicodeString AText, bool AAdjustConditionWithMissedQuote = false);
	virtual void __fastcall Refresh(const System::UnicodeString AText, bool AUseExtendedSyntax);
	__property TcxDataFindCriteriaCondition* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TdxFastObjectList.Create */ inline __fastcall TcxDataFindCriteriaConditions(bool AOwnsObjects, int ACapacity) : Dxcoreclasses::TdxFastObjectList(AOwnsObjects, ACapacity) { }
	
public:
	/* TdxFastList.Destroy */ inline __fastcall virtual ~TcxDataFindCriteriaConditions() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataFindCriteriaMatches : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	int operator[](int Index) { return this->Items[Index]; }
	
private:
	int FCurrentIndex;
	int FNextIndex;
	int FPreviousIndex;
	int __fastcall GetMatch(int AIndex);
	
protected:
	virtual void __fastcall ResetIndexes();
	__property int CurrentIndex = {read=FCurrentIndex, nodefault};
	__property int NextIndex = {read=FNextIndex, nodefault};
	__property int PreviousIndex = {read=FPreviousIndex, nodefault};
	
public:
	__fastcall virtual TcxDataFindCriteriaMatches();
	HIDESBASE virtual void __fastcall Add(int AMatch);
	virtual void __fastcall Clear();
	bool __fastcall Contains(int AMatch);
	void __fastcall UpdateIndexes(int ACurrentMatch);
	__property int Items[int Index] = {read=GetMatch/*, default*/};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TcxDataFindCriteriaMatches() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxDataFindCriteria : public TcxCustomDataFindCriteria
{
	typedef TcxCustomDataFindCriteria inherited;
	
private:
	int FAuxiliaryRecordIndex;
	TcxDataFindCriteriaBehavior FBehavior;
	TcxDataFindCriteriaChanges FChanges;
	TcxDataFindCriteriaConditions* FConditions;
	Cxfilter::TcxFilterCriteria* FDataFilter;
	Cxfilter::TcxFilterCriteria* FGroupFilter;
	System::Classes::TList* FGroupItems;
	bool FHasAuxiliaryRecord;
	System::Classes::TList* FItems;
	System::UnicodeString FLowerText;
	TcxDataFindCriteriaMatches* FMatches;
	System::UnicodeString FText;
	bool FUseExtendedSyntax;
	TcxDataFindCriteriaBeforeChangeEvent FOnBeforeChange;
	TcxDataFindCriteriaChangedEvent FOnChanged;
	void __fastcall AddConditionInFilter(Cxfilter::TcxFilterCriteriaItemList* AFilterGroup, const System::UnicodeString AText);
	TcxCustomDataController* __fastcall GetDataController();
	TcxDataFilterCriteria* __fastcall GetDataFilter();
	TcxDataFilterCriteria* __fastcall GetFilter();
	int __fastcall GetFirstMatchIndex();
	TcxDataFilterCriteria* __fastcall GetGroupFilter();
	int __fastcall GetLastMatchIndex();
	int __fastcall GetMatchRowIndex(int AMatchIndex);
	void __fastcall SetBehavior(const TcxDataFindCriteriaBehavior AValue);
	void __fastcall SetText(System::UnicodeString AValue);
	void __fastcall SetUseExtendedSyntax(bool AValue);
	
protected:
	virtual void __fastcall AssignAuxiliaryRecordFromGroupRow(const TcxRowInfo &AGroupRowInfo);
	virtual void __fastcall CreateAuxiliaryRecord();
	virtual TcxDataFindCriteriaConditions* __fastcall CreateConditions();
	virtual Cxfilter::TcxFilterCriteria* __fastcall CreateFilter();
	virtual void __fastcall Changed(TcxDataFindCriteriaChange AChange);
	virtual bool __fastcall ChangesData();
	virtual void __fastcall DestroyAuxiliaryRecord();
	virtual void __fastcall DoBeforeChange(const TcxDataFindCriteriaChange AChange);
	virtual void __fastcall DoChanged(const TcxDataFindCriteriaChanges AChanges);
	virtual bool __fastcall DoFilterRecord(int ARecordIndex)/* overload */;
	virtual bool __fastcall DoFilterRecord(TcxDataFilterCriteria* AFilter, int ARecordIndex)/* overload */;
	virtual System::UnicodeString __fastcall GetEscapedCondition(const System::UnicodeString AText);
	virtual System::WideChar __fastcall GetEscapeWildcard();
	virtual int __fastcall GetFocusedIndex();
	virtual int __fastcall GetMatchCount();
	virtual int __fastcall GetTextStartPosition(const System::UnicodeString AText, /* out */ System::UnicodeString &AHighlightedText);
	virtual bool __fastcall GoToMatch(int AMatchIndex);
	virtual void __fastcall InitFilter();
	virtual bool __fastcall IsBehaviorSupported(const TcxDataFindCriteriaBehavior AValue);
	virtual bool __fastcall IsConditionsLowerCase();
	virtual bool __fastcall IsFilterActive(TcxDataFilterCriteria* AFilter);
	virtual bool __fastcall IsMatchIndexValid(int AIndex);
	virtual void __fastcall ItemsChanged();
	virtual void __fastcall PopulateMatches();
	virtual System::UnicodeString __fastcall PrepareCondition(const System::UnicodeString AText);
	virtual void __fastcall RebuildDataFilter();
	virtual void __fastcall RebuildFilter();
	virtual void __fastcall RebuildGroupFilter();
	virtual void __fastcall RefreshConditions();
	virtual void __fastcall ResetChanges();
	virtual bool __fastcall SupportsMultiThreading();
	virtual void __fastcall Update(bool ADataChanged, bool AFocusChanged);
	virtual bool __fastcall UseMatches();
	void __fastcall AddField(TcxCustomDataField* AField);
	void __fastcall RemoveField(TcxCustomDataField* AField);
	void __fastcall AddGroupField(TcxCustomDataField* AField);
	void __fastcall RemoveGroupField(TcxCustomDataField* AField);
	__property int AuxiliaryRecordIndex = {read=FAuxiliaryRecordIndex, nodefault};
	__property TcxDataFindCriteriaChanges Changes = {read=FChanges, nodefault};
	__property TcxDataFindCriteriaConditions* Conditions = {read=FConditions};
	__property TcxDataFilterCriteria* DataFilter = {read=GetDataFilter};
	__property TcxDataFilterCriteria* Filter = {read=GetFilter};
	__property TcxDataFilterCriteria* GroupFilter = {read=GetGroupFilter};
	__property System::Classes::TList* GroupItems = {read=FGroupItems};
	__property bool HasAuxiliaryRecord = {read=FHasAuxiliaryRecord, nodefault};
	__property System::Classes::TList* Items = {read=FItems};
	__property TcxDataFindCriteriaMatches* Matches = {read=FMatches};
	__property TcxDataFindCriteriaBeforeChangeEvent OnBeforeChange = {read=FOnBeforeChange, write=FOnBeforeChange};
	__property TcxDataFindCriteriaChangedEvent OnChanged = {read=FOnChanged, write=FOnChanged};
	
public:
	__fastcall virtual TcxDataFindCriteria(TcxCustomDataController* ADataController);
	__fastcall virtual ~TcxDataFindCriteria();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	bool __fastcall IsActive();
	int __fastcall GetCurrentMatchIndex();
	int __fastcall GetNextMatchIndex();
	int __fastcall GetPreviousMatchIndex();
	bool __fastcall GoToFirstMatch();
	bool __fastcall GoToLastMatch();
	bool __fastcall GoToNextMatch();
	bool __fastcall GoToPreviousMatch();
	int __fastcall GetTextStartPositionByRecordIndex(int ARecordIndex, int AItemIndex, /* out */ System::UnicodeString &AHighlightedText);
	int __fastcall GetTextStartPositionByRowIndex(int ARowIndex, int AItemIndex, /* out */ System::UnicodeString &AHighlightedText);
	void __fastcall AddItem(int AItemIndex);
	void __fastcall ClearItems();
	void __fastcall RemoveItem(int AItemIndex);
	void __fastcall AddGroupItem(int AItemIndex);
	void __fastcall ClearGroupItems();
	void __fastcall RemoveGroupItem(int AItemIndex);
	__property TcxDataFindCriteriaBehavior Behavior = {read=FBehavior, write=SetBehavior, nodefault};
	__property TcxCustomDataController* DataController = {read=GetDataController};
	__property int MatchCount = {read=GetMatchCount, nodefault};
	__property int MatchRowIndexes[int AMatchIndex] = {read=GetMatchRowIndex};
	__property System::UnicodeString Text = {read=FText, write=SetText};
	__property bool UseExtendedSyntax = {read=FUseExtendedSyntax, write=SetUseExtendedSyntax, nodefault};
};


struct DECLSPEC_DRECORD TcxFilteringInfo
{
public:
	bool HasFilterEvent;
	bool HasIncrementalFilter;
	bool IsFiltering;
	bool IsFilteringByFindCriteria;
};


typedef int TcxDataGroupIndex;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataControllerGroups : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxCustomDataController* FDataController;
	int __fastcall GetChildCount(int DataGroupIndex);
	int __fastcall GetChildDataGroupIndex(int ParentDataGroupIndex, int ChildIndex);
	int __fastcall GetChildRecordIndex(int ParentDataGroupIndex, int ChildIndex);
	TcxCustomDataControllerInfo* __fastcall GetDataControllerInfo();
	int __fastcall GetDataGroupIndexByRowIndex(int RowIndex);
	TcxDataGroups* __fastcall GetDataGroups();
	int __fastcall GetFieldGroupIndex(TcxCustomDataField* AField);
	int __fastcall GetGroupingItemCount();
	int __fastcall GetGroupingItemIndex(int Index);
	int __fastcall GetItemGroupIndex(int AItemIndex);
	bool __fastcall GetIsChildInMergedGroup(int AItemIndex);
	int __fastcall GetLevel(int ADataGroupIndex);
	int __fastcall GetLevelCount();
	int __fastcall GetParentDataGroupIndex(int ChildDataGroupIndex);
	void __fastcall SetIsChildInMergedGroup(int AItemIndex, bool AValue);
	
protected:
	virtual System::UnicodeString __fastcall GetGroupDisplayText(int ADataGroupIndex);
	virtual System::Variant __fastcall GetGroupValue(int ADataGroupIndex);
	bool __fastcall IsLevelContainingGroupingItem(int ALevel, int AGroupItemIndex);
	int __fastcall GetGroupRecordIndex(int ADataGroupIndex);
	__property TcxCustomDataControllerInfo* DataControllerInfo = {read=GetDataControllerInfo};
	__property TcxDataGroups* DataGroups = {read=GetDataGroups};
	
public:
	__fastcall TcxDataControllerGroups(TcxCustomDataController* ADataController);
	void __fastcall ChangeExpanding(int ARowIndex, bool AExpanded, bool ARecursive);
	void __fastcall ChangeGrouping(int AItemIndex, int AGroupIndex, bool AMergeWithLeftItem = false, bool AMergeWithRightItem = false);
	virtual void __fastcall ClearGrouping();
	virtual void __fastcall FullCollapse();
	virtual void __fastcall FullExpand();
	int __fastcall GetDataGroupIndexByGroupValue(int AParentDataGroupIndex, const System::Variant &AGroupValue);
	int __fastcall GetGroupingItemIndexByLevelGroupedItemIndex(int ALevel, int ALevelGroupedItemIndex);
	int __fastcall GetItemGroupIndexByLevelGroupedItemIndex(int ALevel, int ALevelGroupedItemIndex);
	int __fastcall GetLevelGroupedItemCount(int ALevel);
	int __fastcall GetLevelByItemGroupIndex(int AIndex);
	int __fastcall GetParentGroupingItemIndex(int ALevel);
	bool __fastcall HasAsParent(int ARowIndex, int AParentRowIndex);
	void __fastcall LoadRecordIndexes(System::Classes::TList* AList, int ADataGroupIndex);
	void __fastcall LoadRecordIndexesByRowIndex(System::Classes::TList* AList, int ARowIndex);
	__property TcxCustomDataController* DataController = {read=FDataController};
	__property int FieldGroupIndex[TcxCustomDataField* AField] = {read=GetFieldGroupIndex};
	__property int GroupingItemCount = {read=GetGroupingItemCount, nodefault};
	__property int GroupingItemIndex[int Index] = {read=GetGroupingItemIndex};
	__property int ItemGroupIndex[int ItemIndex] = {read=GetItemGroupIndex};
	__property bool IsChildInMergedGroup[int ItemIndex] = {read=GetIsChildInMergedGroup, write=SetIsChildInMergedGroup};
	__property int DataGroupIndexByRowIndex[int RowIndex] = {read=GetDataGroupIndexByRowIndex};
	__property int Level[int ADataGroupIndex] = {read=GetLevel};
	__property int LevelCount = {read=GetLevelCount, nodefault};
	__property int ChildCount[int DataGroupIndex] = {read=GetChildCount};
	__property int ChildDataGroupIndex[int ParentDataGroupIndex][int ChildIndex] = {read=GetChildDataGroupIndex};
	__property int ChildRecordIndex[int ParentDataGroupIndex][int ChildIndex] = {read=GetChildRecordIndex};
	__property int ParentDataGroupIndex[int ChildDataGroupIndex] = {read=GetParentDataGroupIndex};
	__property System::UnicodeString GroupDisplayTexts[int ADataGroupIndex] = {read=GetGroupDisplayText};
	__property System::Variant GroupValues[int ADataGroupIndex] = {read=GetGroupValue};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDataControllerGroups() { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxDataControllerGroupsClass;

enum DECLSPEC_DENUM TcxSummaryKind : unsigned char { skNone, skSum, skMin, skMax, skCount, skAverage };

typedef System::Set<TcxSummaryKind, TcxSummaryKind::skNone, TcxSummaryKind::skAverage> TcxSummaryKinds;

enum DECLSPEC_DENUM TcxSummaryValueType : unsigned char { svtFloat, svtCurrency, svtDate };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomDataSummaryItem : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	TcxCustomDataField* FField;
	System::UnicodeString FFormat;
	TcxSummaryKind FKind;
	System::TObject* __fastcall GetItemLink();
	void __fastcall SetFormat(const System::UnicodeString Value);
	void __fastcall SetItemLink(System::TObject* Value);
	void __fastcall SetKind(TcxSummaryKind Value);
	
protected:
	virtual void __fastcall AssignValues(TcxCustomDataSummaryItem* ASource);
	virtual bool __fastcall CanSetKind(TcxSummaryKind Value);
	virtual TcxCustomDataController* __fastcall GetDataController() = 0 ;
	virtual System::UnicodeString __fastcall GetValueFormat(TcxSummaryValueType AValueType, const System::Variant &AValue, bool AIsFooter);
	TcxSummaryValueType __fastcall GetValueType(System::Word AVarType);
	virtual bool __fastcall IsCurrency(System::Word AVarType);
	virtual void __fastcall ItemLinkChanging(TcxCustomDataField* AField);
	__property System::UnicodeString Format = {read=FFormat, write=SetFormat};
	__property TcxSummaryKind Kind = {read=FKind, write=SetKind, default=0};
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall BeginUpdate();
	void __fastcall EndUpdate();
	virtual System::UnicodeString __fastcall FormatValue(const System::Variant &AValue, bool AIsFooter);
	__property TcxCustomDataController* DataController = {read=GetDataController};
	__property System::TObject* ItemLink = {read=GetItemLink, write=SetItemLink};
	__property TcxCustomDataField* Field = {read=FField};
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TcxCustomDataSummaryItem(System::Classes::TCollection* Collection) : System::Classes::TCollectionItem(Collection) { }
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TcxCustomDataSummaryItem() { }
	
};

#pragma pack(pop)

enum DECLSPEC_DENUM TcxSummaryOption : unsigned char { soNullIgnore, soSelectedRecords, soMultipleSelectedRecords };

typedef System::Set<TcxSummaryOption, TcxSummaryOption::soNullIgnore, TcxSummaryOption::soMultipleSelectedRecords> TcxSummaryOptions;

enum DECLSPEC_DENUM TcxSummaryPosition : unsigned char { spGroup, spFooter };

enum DECLSPEC_DENUM TcxSummaryProperty : unsigned char { spFormat, spKind, spSorted };

typedef System::Set<TcxSummaryProperty, TcxSummaryProperty::spFormat, TcxSummaryProperty::spSorted> TcxSummaryProperties;

typedef void __fastcall (__closure *TcxDataSummaryItemGetTextEvent)(TcxDataSummaryItem* Sender, const System::Variant &AValue, bool AIsFooter, System::UnicodeString &AText);

class PASCALIMPLEMENTATION TcxDataSummaryItem : public TcxCustomDataSummaryItem
{
	typedef TcxCustomDataSummaryItem inherited;
	
private:
	bool FSorted;
	int FTag;
	TcxDataSummaryItemGetTextEvent FOnGetText;
	TcxSummaryPosition __fastcall GetPosition();
	TcxDataSummaryItems* __fastcall GetSummaryItems();
	void __fastcall SetPosition(TcxSummaryPosition Value);
	void __fastcall SetSorted(bool Value);
	
protected:
	TcxSummaryPosition FPosition;
	virtual void __fastcall AssignValues(TcxCustomDataSummaryItem* Source);
	virtual TcxCustomDataController* __fastcall GetDataController();
	virtual System::UnicodeString __fastcall GetValueFormat(TcxSummaryValueType AValueType, const System::Variant &AValue, bool AIsFooter);
	virtual bool __fastcall IsDataBinded();
	virtual bool __fastcall IsPositionStored();
	
public:
	__fastcall virtual ~TcxDataSummaryItem();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual TcxCustomDataField* __fastcall DataField();
	virtual System::UnicodeString __fastcall FormatValue(const System::Variant &AValue, bool AIsFooter);
	__property TcxCustomDataController* DataController = {read=GetDataController};
	__property TcxDataSummaryItems* SummaryItems = {read=GetSummaryItems};
	__property bool Sorted = {read=FSorted, write=SetSorted, default=0};
	
__published:
	__property Format = {default=0};
	__property Kind = {default=0};
	__property TcxSummaryPosition Position = {read=GetPosition, write=SetPosition, stored=IsPositionStored, nodefault};
	__property int Tag = {read=FTag, write=FTag, default=0};
	__property TcxDataSummaryItemGetTextEvent OnGetText = {read=FOnGetText, write=FOnGetText};
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TcxDataSummaryItem(System::Classes::TCollection* Collection) : TcxCustomDataSummaryItem(Collection) { }
	
};


typedef System::TMetaClass* TcxDataSummaryItemClass;

struct DECLSPEC_DRECORD TcxSummaryEventArguments
{
public:
	int RecordIndex;
	TcxDataSummaryItem* SummaryItem;
};


struct DECLSPEC_DRECORD TcxSummaryEventOutArguments
{
public:
	System::Variant Value;
	System::Variant SummaryValue;
	int CountValue;
	bool Done;
};


typedef void __fastcall (__closure *TcxSummaryEvent)(TcxDataSummaryItems* ASender, const TcxSummaryEventArguments &Arguments, TcxSummaryEventOutArguments &OutArguments);

class PASCALIMPLEMENTATION TcxDataSummaryItems : public Dxcoreclasses::TcxCollection
{
	typedef Dxcoreclasses::TcxCollection inherited;
	
public:
	TcxDataSummaryItem* operator[](int Index) { return this->Items[Index]; }
	
private:
	TcxDataSummary* FSummary;
	TcxSummaryEvent FOnSummary;
	TcxCustomDataController* __fastcall GetDataController();
	HIDESBASE TcxDataSummaryItem* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TcxDataSummaryItem* Value);
	
protected:
	virtual void __fastcall BeforeSortingChange(TcxDataSummaryItem* AItem, bool AValue);
	void __fastcall ChangedView();
	virtual TcxSummaryPosition __fastcall GetItemPosition(TcxDataSummaryItem* AItem);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner();
	int __fastcall IndexOfField(TcxCustomDataField* AField);
	virtual bool __fastcall IsPositionStored(TcxDataSummaryItem* AItem);
	TcxDataSummaryItem* __fastcall ItemOfField(TcxCustomDataField* AField);
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	TcxDataSummaryItem* __fastcall AddDataItem(int AItemIndex, TcxSummaryPosition APosition);
	void __fastcall CheckItemEmpty(TcxDataSummaryItem* AItem);
	void __fastcall GetDataItemProperties(int AItemIndex, TcxSummaryPosition APosition, TcxSummaryProperties AProperties, System::UnicodeString &AFormat, TcxSummaryKind &AKind, bool &ASorted);
	virtual bool __fastcall IsPropertiesEmpty(TcxSummaryProperties AProperties, const System::UnicodeString AFormat, TcxSummaryKind AKind, bool ASorted);
	void __fastcall SetDataItemProperties(int AItemIndex, TcxSummaryPosition APosition, TcxSummaryProperties AProperties, const System::UnicodeString AFormat, TcxSummaryKind AKind, bool ASorted);
	void __fastcall SetItemProperties(TcxDataSummaryItem* AItem, TcxSummaryPosition APosition, TcxSummaryProperties AProperties, const System::UnicodeString AFormat, TcxSummaryKind AKind, bool ASorted);
	
public:
	__fastcall virtual TcxDataSummaryItems(TcxDataSummary* ASummary, TcxDataSummaryItemClass AItemClass);
	HIDESBASE TcxDataSummaryItem* __fastcall Add()/* overload */;
	HIDESBASE TcxDataSummaryItem* __fastcall Add(System::TObject* AItemLink, TcxSummaryPosition APosition, TcxSummaryKind AKind, const System::UnicodeString AFormat = System::UnicodeString())/* overload */;
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall AssignEvents(System::Classes::TPersistent* Source);
	virtual System::UnicodeString __fastcall DefaultFormat(TcxSummaryValueType AValueType, TcxSummaryKind ASummaryKind, bool AIsFooter);
	void __fastcall DeleteItems(System::TObject* AItemLink, TcxSummaryPosition APosition);
	TcxDataSummaryItem* __fastcall FindByTag(int ATag);
	virtual System::UnicodeString __fastcall GetGroupText(const System::Variant &ASummaryValues);
	int __fastcall IndexOf(TcxDataSummaryItem* AItem);
	int __fastcall IndexOfItemLink(System::TObject* AItemLink);
	TcxDataSummaryItem* __fastcall ItemOfItemLink(System::TObject* AItemLink);
	virtual TcxDataSummaryItem* __fastcall GetDataItem(int AItemIndex, TcxSummaryPosition APosition, bool ACheckKind = false, TcxSummaryKind AKind = (TcxSummaryKind)(0x0));
	System::UnicodeString __fastcall GetDataItemFormat(int AItemIndex, TcxSummaryPosition APosition);
	TcxSummaryKind __fastcall GetDataItemKind(int AItemIndex, TcxSummaryPosition APosition);
	bool __fastcall GetDataItemSorted(int AItemIndex, TcxSummaryPosition APosition);
	void __fastcall SetDataItemFormat(int AItemIndex, TcxSummaryPosition APosition, const System::UnicodeString Value);
	void __fastcall SetDataItemKind(int AItemIndex, TcxSummaryPosition APosition, TcxSummaryKind Value);
	void __fastcall SetDataItemSorted(int AItemIndex, TcxSummaryPosition APosition, bool Value);
	__property TcxCustomDataController* DataController = {read=GetDataController};
	__property TcxDataSummaryItem* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
	__property TcxDataSummary* Summary = {read=FSummary};
	
__published:
	__property TcxSummaryEvent OnSummary = {read=FOnSummary, write=FOnSummary};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TcxDataSummaryItems() { }
	
};


class PASCALIMPLEMENTATION TcxDataFooterSummaryItems : public TcxDataSummaryItems
{
	typedef TcxDataSummaryItems inherited;
	
protected:
	virtual TcxSummaryPosition __fastcall GetItemPosition(TcxDataSummaryItem* AItem);
	virtual bool __fastcall IsPositionStored(TcxDataSummaryItem* AItem);
public:
	/* TcxDataSummaryItems.Create */ inline __fastcall virtual TcxDataFooterSummaryItems(TcxDataSummary* ASummary, TcxDataSummaryItemClass AItemClass) : TcxDataSummaryItems(ASummary, AItemClass) { }
	
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TcxDataFooterSummaryItems() { }
	
};


class PASCALIMPLEMENTATION TcxDataGroupSummaryItems : public TcxDataSummaryItems
{
	typedef TcxDataSummaryItems inherited;
	
private:
	System::UnicodeString FBeginText;
	System::UnicodeString FEndText;
	System::UnicodeString FSeparator;
	System::Classes::TPersistent* FOwner;
	bool __fastcall IsBeginTextStored();
	bool __fastcall IsEndTextStored();
	bool __fastcall IsSeparatorStored();
	void __fastcall SetBeginText(const System::UnicodeString Value);
	void __fastcall SetEndText(const System::UnicodeString Value);
	void __fastcall SetSeparator(const System::UnicodeString Value);
	
protected:
	virtual void __fastcall BeforeSortingChange(TcxDataSummaryItem* AItem, bool AValue);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner();
	
public:
	__fastcall virtual TcxDataGroupSummaryItems(TcxDataSummary* ASummary, TcxDataSummaryItemClass AItemClass);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual System::UnicodeString __fastcall GetGroupText(const System::Variant &ASummaryValues);
	TcxDataSummaryItem* __fastcall SortedSummaryItem();
	
__published:
	__property System::UnicodeString BeginText = {read=FBeginText, write=SetBeginText, stored=IsBeginTextStored};
	__property System::UnicodeString EndText = {read=FEndText, write=SetEndText, stored=IsEndTextStored};
	__property System::UnicodeString Separator = {read=FSeparator, write=SetSeparator, stored=IsSeparatorStored};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TcxDataGroupSummaryItems() { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataSummaryGroupItemLink : public TcxCustomDataSummaryItem
{
	typedef TcxCustomDataSummaryItem inherited;
	
private:
	TcxDataSummaryGroupItemLinks* __fastcall GetSummaryGroupItemLinks();
	
protected:
	virtual TcxCustomDataController* __fastcall GetDataController();
	virtual void __fastcall ItemLinkChanging(TcxCustomDataField* AField);
	
public:
	__property TcxDataSummaryGroupItemLinks* SummaryGroupItemLinks = {read=GetSummaryGroupItemLinks};
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TcxDataSummaryGroupItemLink(System::Classes::TCollection* Collection) : TcxCustomDataSummaryItem(Collection) { }
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TcxDataSummaryGroupItemLink() { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxDataSummaryGroupItemLinkClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataSummaryGroupItemLinks : public Dxcoreclasses::TcxCollection
{
	typedef Dxcoreclasses::TcxCollection inherited;
	
public:
	TcxDataSummaryGroupItemLink* operator[](int Index) { return this->Items[Index]; }
	
private:
	TcxDataSummaryGroup* FSummaryGroup;
	HIDESBASE TcxDataSummaryGroupItemLink* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TcxDataSummaryGroupItemLink* Value);
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner();
	int __fastcall IndexOfField(TcxCustomDataField* AField);
	TcxDataSummaryGroupItemLink* __fastcall ItemOfField(TcxCustomDataField* AField);
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	
public:
	__fastcall virtual TcxDataSummaryGroupItemLinks(TcxDataSummaryGroup* ASummaryGroup, TcxDataSummaryGroupItemLinkClass AItemClass);
	HIDESBASE TcxDataSummaryGroupItemLink* __fastcall Add();
	int __fastcall IndexOfItemLink(System::TObject* AItemLink);
	TcxDataSummaryGroupItemLink* __fastcall ItemOfItemLink(System::TObject* AItemLink);
	__property TcxDataSummaryGroupItemLink* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
	__property TcxDataSummaryGroup* SummaryGroup = {read=FSummaryGroup};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TcxDataSummaryGroupItemLinks() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataSummaryGroup : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	TcxDataSummaryGroupItemLinks* FItemLinks;
	TcxDataGroupSummaryItems* FSummaryItems;
	TcxDataSummaryGroupItemLinks* __fastcall GetItemLinks();
	TcxDataSummaryGroups* __fastcall GetSummaryGroups();
	void __fastcall SetItemLinks(TcxDataSummaryGroupItemLinks* Value);
	void __fastcall SetSummaryItems(TcxDataGroupSummaryItems* Value);
	
public:
	__fastcall virtual TcxDataSummaryGroup(System::Classes::TCollection* Collection);
	__fastcall virtual ~TcxDataSummaryGroup();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxDataSummaryGroups* SummaryGroups = {read=GetSummaryGroups};
	
__published:
	__property TcxDataSummaryGroupItemLinks* Links = {read=GetItemLinks, write=SetItemLinks};
	__property TcxDataGroupSummaryItems* SummaryItems = {read=FSummaryItems, write=SetSummaryItems};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataSummaryGroups : public Dxcoreclasses::TcxCollection
{
	typedef Dxcoreclasses::TcxCollection inherited;
	
public:
	TcxDataSummaryGroup* operator[](int Index) { return this->Items[Index]; }
	
private:
	TcxDataSummary* FSummary;
	HIDESBASE TcxDataSummaryGroup* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TcxDataSummaryGroup* Value);
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner();
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	
public:
	__fastcall TcxDataSummaryGroups(TcxDataSummary* ASummary);
	HIDESBASE TcxDataSummaryGroup* __fastcall Add();
	TcxDataSummaryGroup* __fastcall FindByItemLink(System::TObject* AItemLink);
	__property TcxDataSummary* Summary = {read=FSummary};
	__property TcxDataSummaryGroup* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TcxDataSummaryGroups() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataControllerObject : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxCustomDataController* FDataController;
	
public:
	__fastcall virtual TcxDataControllerObject(TcxCustomDataController* ADataController);
	__property TcxCustomDataController* DataController = {read=FDataController};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDataControllerObject() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataControllerPersistent : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TcxCustomDataController* FDataController;
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner();
	
public:
	__fastcall virtual TcxDataControllerPersistent(TcxCustomDataController* ADataController);
	__property TcxCustomDataController* DataController = {read=FDataController};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxDataControllerPersistent() { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TcxAfterSummaryEvent)(TcxDataSummary* ASender);

class PASCALIMPLEMENTATION TcxDataSummary : public TcxDataControllerPersistent
{
	typedef TcxDataControllerPersistent inherited;
	
private:
	TcxDataGroupSummaryItems* FDefaultGroupSummaryItems;
	bool FDestroying;
	TcxDataFooterSummaryItems* FFooterSummaryItems;
	System::Variant FFooterSummaryValues;
	bool FInAfterSummary;
	int FLockCount;
	TcxSummaryOptions FOptions;
	bool FSetCustomSummary;
	TcxDataSummaryGroups* FSummaryGroups;
	TcxAfterSummaryEvent FOnAfterSummary;
	System::Variant __fastcall GetFooterSummaryValue(int Index);
	System::UnicodeString __fastcall GetFooterSummaryText(int Index);
	TcxDataGroupSummaryItems* __fastcall GetGroupMainSummaryItems(int Level);
	System::UnicodeString __fastcall GetGroupMainSummaryText(int RowIndex);
	System::Variant __fastcall GetGroupSummaryDisplayValue(int RowIndex, int Level, int Index);
	System::Variant __fastcall GetGroupSummaryValue(int DataGroupIndex, int Index);
	int __fastcall GetGroupFooterIndexOfItemLink(int Level, System::TObject* ItemLink);
	System::UnicodeString __fastcall GetGroupMainFooterSummaryText(int RowIndex, int Level, int Index);
	TcxSummaryOptions __fastcall GetOptions();
	void __fastcall SetDefaultGroupSummaryItems(TcxDataGroupSummaryItems* Value);
	void __fastcall SetFooterSummaryItems(TcxDataFooterSummaryItems* Value);
	void __fastcall SetFooterSummaryValue(int Index, const System::Variant &Value);
	void __fastcall SetGroupSummaryDisplayValue(int RowIndex, int Level, int Index, const System::Variant &Value);
	void __fastcall SetGroupSummaryValue(int DataGroupIndex, int Index, const System::Variant &Value);
	void __fastcall SetOptions(TcxSummaryOptions Value);
	void __fastcall SetSummaryGroups(TcxDataSummaryGroups* Value);
	
protected:
	virtual void __fastcall BeginCalculateSummary(TcxDataSummaryItems* ASummaryItems, TcxDataSummaryCountValues &ACountValues, TcxDataSummaryValues &ASummaryValues);
	virtual void __fastcall CalculateSummary(TcxDataSummaryItems* ASummaryItems, int ABeginIndex, int AEndIndex, TcxDataSummaryCountValues &ACountValues, TcxDataSummaryValues &ASummaryValues);
	virtual void __fastcall Changed(bool ARedrawOnly);
	virtual void __fastcall DoAfterSummary();
	virtual void __fastcall DoFinishSummaryValue(TcxDataSummaryItem* ASummaryItem, System::Variant &SummaryValue, int &CountValue);
	virtual void __fastcall DoSummaryValue(TcxDataSummaryItem* ASummaryItem, int ARecordIndex, System::Variant &SummaryValue, int &CountValue);
	virtual void __fastcall EndCalculateSummary(TcxDataSummaryItems* ASummaryItems, TcxDataSummaryCountValues &ACountValues, TcxDataSummaryValues &ASummaryValues, System::Variant &SummaryValues);
	System::PVariant __fastcall GetGroupSummaryValues(int ADataGroupIndex, int ALevelGroupedItemIndex = 0x0);
	virtual int __fastcall GetRecordIndex(int ARecordListIndex);
	virtual TcxDataSummaryGroupItemLinkClass __fastcall GetSummaryGroupItemLinkClass();
	virtual TcxDataSummaryItemClass __fastcall GetSummaryItemClass();
	virtual bool __fastcall IsValidSummaryValuesIndex(const System::Variant &ASummaryValues, int AIndex);
	virtual void __fastcall Update(bool ARedrawOnly);
	__property bool Destroying = {read=FDestroying, nodefault};
	__property int LockCount = {read=FLockCount, nodefault};
	
public:
	__fastcall virtual TcxDataSummary(TcxCustomDataController* ADataController);
	__fastcall virtual ~TcxDataSummary();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall AssignEvents(System::Classes::TPersistent* Source);
	void __fastcall BeginUpdate();
	virtual void __fastcall BeginCalculate();
	virtual void __fastcall EndCalculate();
	virtual void __fastcall Calculate();
	virtual void __fastcall CalculateFooterSummary();
	virtual void __fastcall CalculateGroupSummary();
	void __fastcall CancelUpdate();
	void __fastcall EndUpdate();
	System::UnicodeString __fastcall GetGroupFooterSummaryText(int RowIndex, int Level, int Index, int ALevelGroupedItemIndex = 0x0);
	bool __fastcall GetGroupSummaryInfo(int ARowIndex, TcxDataSummaryItems* &ASummaryItems, System::PVariant &ASummaryValues, int ALevelGroupedItemIndex = 0x0);
	TcxDataGroupSummaryItems* __fastcall GetGroupSummaryItems(int Level, int ALevelGroupedItemIndex = 0x0);
	System::UnicodeString __fastcall GetGroupSummaryText(int RowIndex, int ALevelGroupedItemIndex = 0x0);
	TcxDataSummaryItems* __fastcall GetPatternSummaryItems(TcxDataSummary* APatternSummary, TcxDataSummaryItems* ASummaryItems);
	void __fastcall Recalculate();
	void __fastcall RemoveItemByField(TcxCustomDataField* AField);
	__property System::Variant FooterSummaryValues[int Index] = {read=GetFooterSummaryValue, write=SetFooterSummaryValue};
	__property System::UnicodeString FooterSummaryTexts[int Index] = {read=GetFooterSummaryText};
	__property int GroupFooterIndexOfItemLink[int Level][System::TObject* ItemLink] = {read=GetGroupFooterIndexOfItemLink};
	__property TcxDataGroupSummaryItems* GroupSummaryItems[int Level] = {read=GetGroupMainSummaryItems};
	__property System::UnicodeString GroupFooterSummaryTexts[int RowIndex][int Level][int Index] = {read=GetGroupMainFooterSummaryText};
	__property System::UnicodeString GroupSummaryText[int RowIndex] = {read=GetGroupMainSummaryText};
	__property System::Variant GroupSummaryDisplayValues[int RowIndex][int Level][int Index] = {read=GetGroupSummaryDisplayValue, write=SetGroupSummaryDisplayValue};
	__property System::Variant GroupSummaryValues[int DataGroupIndex][int Index] = {read=GetGroupSummaryValue, write=SetGroupSummaryValue};
	
__published:
	__property TcxDataGroupSummaryItems* DefaultGroupSummaryItems = {read=FDefaultGroupSummaryItems, write=SetDefaultGroupSummaryItems};
	__property TcxDataFooterSummaryItems* FooterSummaryItems = {read=FFooterSummaryItems, write=SetFooterSummaryItems};
	__property TcxDataSummaryGroups* SummaryGroups = {read=FSummaryGroups, write=SetSummaryGroups};
	__property TcxSummaryOptions Options = {read=GetOptions, write=SetOptions, default=0};
	__property TcxAfterSummaryEvent OnAfterSummary = {read=FOnAfterSummary, write=FOnAfterSummary};
};


typedef System::TMetaClass* TcxDataSummaryClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataControllerMultiThreadedOptions : public TcxDataControllerPersistent
{
	typedef TcxDataControllerPersistent inherited;
	
private:
	Dxcore::TdxDefaultBoolean FFiltering;
	Dxcore::TdxDefaultBoolean FSorting;
	Dxcore::TdxDefaultBoolean FSummary;
	
protected:
	bool __fastcall IsMultiThreadedFiltering();
	bool __fastcall IsMultiThreadedSorting();
	bool __fastcall IsMultiThreadedSummary();
	__property Dxcore::TdxDefaultBoolean Summary = {read=FSummary, write=FSummary, default=2};
	
public:
	__fastcall virtual TcxDataControllerMultiThreadedOptions(TcxCustomDataController* ADataController);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property Dxcore::TdxDefaultBoolean Filtering = {read=FFiltering, write=FFiltering, default=2};
	__property Dxcore::TdxDefaultBoolean Sorting = {read=FSorting, write=FSorting, default=2};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxDataControllerMultiThreadedOptions() { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxDataControllerMultiThreadedOptionsClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataControllerSearch : public TcxDataControllerObject
{
	typedef TcxDataControllerObject inherited;
	
private:
	bool FLocked;
	int __fastcall GetItemIndex();
	bool __fastcall GetSearching();
	System::UnicodeString __fastcall GetSearchText();
	void __fastcall SetItemIndex(const int Value);
	
protected:
	virtual void __fastcall DoFocusedRecord(int AFilteredRecordIndex, bool ASyncSelection);
	virtual int __fastcall DoSearch(int AStartFilteredRecordIndex, int AEndFilteredRecordIndex, const System::UnicodeString ASubText, bool AForward, bool AIsAnywhere);
	
public:
	void __fastcall Cancel();
	virtual bool __fastcall Locate(int AItemIndex, const System::UnicodeString ASubText, bool AIsAnywhere = false, bool ASyncSelection = true);
	virtual bool __fastcall LocateNext(bool AForward, bool AIsAnywhere = false, bool ASyncSelection = true);
	virtual void __fastcall Lock();
	virtual void __fastcall Unlock();
	__property int ItemIndex = {read=GetItemIndex, write=SetItemIndex, nodefault};
	__property bool Locked = {read=FLocked, nodefault};
	__property bool Searching = {read=GetSearching, nodefault};
	__property System::UnicodeString SearchText = {read=GetSearchText};
public:
	/* TcxDataControllerObject.Create */ inline __fastcall virtual TcxDataControllerSearch(TcxCustomDataController* ADataController) : TcxDataControllerObject(ADataController) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDataControllerSearch() { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxDataControllerSearchClass;

enum DECLSPEC_DENUM TcxDataControllerChange : unsigned char { dccLayout, dccData, dccFocus, dccSelection, dccDetail, dccSummary, dccSearch, dccSorting, dccGrouping, dccSyncMasterPos, dccBookmark, dccUpdateRecord, dccGridMode, dccFindCriteria };

typedef System::Set<TcxDataControllerChange, TcxDataControllerChange::dccLayout, TcxDataControllerChange::dccFindCriteria> TcxDataControllerChanges;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxUpdateControlInfo : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	virtual void __fastcall AssignTo(TcxUpdateControlInfo* AInfo);
	
public:
	TcxUpdateControlInfo* __fastcall Clone();
	virtual bool __fastcall CanNavigatorUpdate();
public:
	/* TObject.Create */ inline __fastcall TcxUpdateControlInfo() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxUpdateControlInfo() { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxUpdateControlInfoClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFindCriteriaChangedInfo : public TcxUpdateControlInfo
{
	typedef TcxUpdateControlInfo inherited;
	
private:
	TcxDataFindCriteriaChanges FChanges;
	
public:
	__fastcall virtual TcxFindCriteriaChangedInfo(TcxDataFindCriteriaChanges AChanges);
	__property TcxDataFindCriteriaChanges Changes = {read=FChanges, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxFindCriteriaChangedInfo() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFocusedRecordChangedInfo : public TcxUpdateControlInfo
{
	typedef TcxUpdateControlInfo inherited;
	
private:
	int FFocusedRecordIndex;
	int FPrevFocusedRecordIndex;
	int FFocusedRowIndex;
	int FPrevFocusedRowIndex;
	bool FNewItemRowFocusingChanged;
	
protected:
	virtual void __fastcall AssignTo(TcxUpdateControlInfo* AInfo);
	
public:
	__fastcall TcxFocusedRecordChangedInfo(int APrevFocusedRecordIndex, int AFocusedRecordIndex, int APrevFocusedRowIndex, int AFocusedRowIndex, bool ANewItemRowFocusingChanged);
	__property int FocusedRecordIndex = {read=FFocusedRecordIndex, nodefault};
	__property int PrevFocusedRecordIndex = {read=FPrevFocusedRecordIndex, nodefault};
	__property int FocusedRowIndex = {read=FFocusedRowIndex, nodefault};
	__property int PrevFocusedRowIndex = {read=FPrevFocusedRowIndex, nodefault};
	__property bool NewItemRowFocusingChanged = {read=FNewItemRowFocusingChanged, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxFocusedRecordChangedInfo() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFocusedRowChangedInfo : public TcxUpdateControlInfo
{
	typedef TcxUpdateControlInfo inherited;
	
private:
	int FFocusedRowIndex;
	int FPrevFocusedRowIndex;
	
protected:
	virtual void __fastcall AssignTo(TcxUpdateControlInfo* AInfo);
	
public:
	__fastcall TcxFocusedRowChangedInfo(int APrevFocusedRowIndex, int AFocusedRowIndex);
	__property int FocusedRowIndex = {read=FFocusedRowIndex, nodefault};
	__property int PrevFocusedRowIndex = {read=FPrevFocusedRowIndex, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxFocusedRowChangedInfo() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGroupingChangingInfo : public TcxUpdateControlInfo
{
	typedef TcxUpdateControlInfo inherited;
	
public:
	virtual bool __fastcall CanNavigatorUpdate();
public:
	/* TObject.Create */ inline __fastcall TcxGroupingChangingInfo() : TcxUpdateControlInfo() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGroupingChangingInfo() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxLayoutChangedInfo : public TcxUpdateControlInfo
{
	typedef TcxUpdateControlInfo inherited;
	
public:
	/* TObject.Create */ inline __fastcall TcxLayoutChangedInfo() : TcxUpdateControlInfo() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxLayoutChangedInfo() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxUpdateRecordInfo : public TcxUpdateControlInfo
{
	typedef TcxUpdateControlInfo inherited;
	
private:
	int FRecordIndex;
	
protected:
	virtual void __fastcall AssignTo(TcxUpdateControlInfo* AInfo);
	
public:
	__fastcall TcxUpdateRecordInfo(int ARecordIndex);
	__property int RecordIndex = {read=FRecordIndex, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxUpdateRecordInfo() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataChangedInfo : public TcxUpdateControlInfo
{
	typedef TcxUpdateControlInfo inherited;
	
protected:
	virtual void __fastcall AssignTo(TcxUpdateControlInfo* AInfo);
	
public:
	TcxDataChange Kind;
	int ItemIndex;
	int RecordIndex;
public:
	/* TObject.Create */ inline __fastcall TcxDataChangedInfo() : TcxUpdateControlInfo() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDataChangedInfo() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxBookmarkChangedInfo : public TcxUpdateControlInfo
{
	typedef TcxUpdateControlInfo inherited;
	
public:
	/* TObject.Create */ inline __fastcall TcxBookmarkChangedInfo() : TcxUpdateControlInfo() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxBookmarkChangedInfo() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSelectionChangedInfo : public TcxUpdateControlInfo
{
	typedef TcxUpdateControlInfo inherited;
	
private:
	System::Classes::TList* FRowIndexes;
	int __fastcall GetCount();
	int __fastcall GetRowIndex(int Index);
	
protected:
	virtual void __fastcall AssignTo(TcxUpdateControlInfo* AInfo);
	System::Classes::TList* __fastcall CreateRowIndexes();
	
public:
	__fastcall TcxSelectionChangedInfo();
	__fastcall TcxSelectionChangedInfo(int ARowIndex1, int ARowIndex2);
	__fastcall virtual ~TcxSelectionChangedInfo();
	virtual bool __fastcall CanNavigatorUpdate();
	__property int Count = {read=GetCount, nodefault};
	__property int RowIndexes[int Index] = {read=GetRowIndex};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSearchChangedInfo : public TcxUpdateControlInfo
{
	typedef TcxUpdateControlInfo inherited;
	
public:
	/* TObject.Create */ inline __fastcall TcxSearchChangedInfo() : TcxUpdateControlInfo() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSearchChangedInfo() { }
	
};

#pragma pack(pop)

struct DECLSPEC_DRECORD TcxDataSelectionChangedInfo
{
public:
	int SelectedCount;
	int RowIndex;
};


typedef void __fastcall (__closure *TcxUpdateControlEvent)(TcxUpdateControlInfo* AInfo);

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataControllerLocateObject : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxCustomDataController* FDataController;
	int FInternalRecordIndex;
	
protected:
	__property TcxCustomDataController* DataController = {read=FDataController};
	__property int InternalRecordIndex = {read=FInternalRecordIndex, nodefault};
	
public:
	__fastcall virtual TcxDataControllerLocateObject(TcxCustomDataController* ADataController);
	__fastcall virtual ~TcxDataControllerLocateObject();
	virtual void __fastcall Clear();
	virtual int __fastcall FindRecordIndex() = 0 ;
	virtual void __fastcall ReadData(Cxdatastorage::TcxValueDefReader* AValueDefReader);
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataControllerKeyLocateObject : public TcxDataControllerLocateObject
{
	typedef TcxDataControllerLocateObject inherited;
	
private:
	System::Classes::TList* FFields;
	
public:
	__fastcall virtual TcxDataControllerKeyLocateObject(TcxCustomDataController* ADataController);
	__fastcall virtual ~TcxDataControllerKeyLocateObject();
	void __fastcall AddField(TcxCustomDataField* AField);
	void __fastcall ClearFields();
	virtual int __fastcall FindRecordIndex();
	virtual void __fastcall ReadData(Cxdatastorage::TcxValueDefReader* AValueDefReader);
	__property System::Classes::TList* FieldList = {read=FFields};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataControllerGroupLocateObject : public TcxDataControllerLocateObject
{
	typedef TcxDataControllerLocateObject inherited;
	
private:
	int FGroupIndex;
	bool FIsGroupDataSorted;
	
public:
	__fastcall virtual TcxDataControllerGroupLocateObject(TcxCustomDataController* ADataController);
	virtual int __fastcall FindRecordIndex();
	__property int GroupIndex = {read=FGroupIndex, write=FGroupIndex, nodefault};
public:
	/* TcxDataControllerLocateObject.Destroy */ inline __fastcall virtual ~TcxDataControllerGroupLocateObject() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxValueDefUnboundReader : public Cxdatastorage::TcxValueDefReader
{
	typedef Cxdatastorage::TcxValueDefReader inherited;
	
private:
	System::Classes::TList* FItems;
	System::Classes::TList* FValues;
	
public:
	__fastcall virtual TcxValueDefUnboundReader();
	__fastcall virtual ~TcxValueDefUnboundReader();
	void __fastcall Clear();
	virtual System::Variant __fastcall GetValue(Cxdatastorage::TcxValueDef* AValueDef);
	virtual bool __fastcall IsInternal(Cxdatastorage::TcxValueDef* AValueDef);
	void __fastcall SetValue(Cxdatastorage::TcxValueDef* AValueDef, const System::Variant &AValue);
	void __fastcall Truncate(int AItemCount);
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxValueDefRecordReader : public Cxdatastorage::TcxValueDefReader
{
	typedef Cxdatastorage::TcxValueDefReader inherited;
	
private:
	TcxCustomDataController* FDataController;
	int FRecordIndex;
	
public:
	__fastcall TcxValueDefRecordReader(TcxCustomDataController* ADataController, int ARecordIndex);
	virtual System::UnicodeString __fastcall GetDisplayText(Cxdatastorage::TcxValueDef* AValueDef);
	virtual System::Variant __fastcall GetValue(Cxdatastorage::TcxValueDef* AValueDef);
	virtual bool __fastcall IsInternal(Cxdatastorage::TcxValueDef* AValueDef);
	virtual void __fastcall Read(char * ABuffer, Cxdatastorage::TcxValueDef* AValueDef);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxValueDefRecordReader() { }
	
};

#pragma pack(pop)

enum DECLSPEC_DENUM TcxDataControllerDetailMode : unsigned char { dcdmNone, dcdmPattern, dcdmClone };

typedef void __fastcall (__closure *TcxDataControllerEachDetailProc)(TcxCustomDataController* ADataController);

typedef void __fastcall (__closure *TcxDataControllerEachRowProc)(int ARowIndex, const TcxRowInfo &ARowInfo);

class PASCALIMPLEMENTATION TcxDataControllerNotifier : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	TcxCustomDataController* FDataController;
	
protected:
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall TcxDataControllerNotifier(System::Classes::TComponent* AOwner, TcxCustomDataController* ADataController);
	__property TcxCustomDataController* DataController = {read=FDataController};
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~TcxDataControllerNotifier() { }
	
};


typedef System::TMetaClass* TcxSortingBySummaryEngineClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSortingBySummaryEngine : public TcxDataControllerInfoHelper
{
	typedef TcxDataControllerInfoHelper inherited;
	
private:
	TcxCustomDataController* __fastcall GetDataController();
	
protected:
	__property TcxCustomDataController* DataController = {read=GetDataController};
	
public:
	virtual void __fastcall Sort() = 0 ;
public:
	/* TcxDataControllerInfoHelper.Create */ inline __fastcall virtual TcxSortingBySummaryEngine(TcxCustomDataControllerInfo* ADataControllerInfo) : TcxDataControllerInfoHelper(ADataControllerInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSortingBySummaryEngine() { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TcxDataControllerCompareEvent)(TcxCustomDataController* ADataController, int ARecordIndex1, int ARecordIndex2, int AItemIndex, const System::Variant &V1, const System::Variant &V2, int &Compare);

typedef void __fastcall (__closure *TcxDataRecordChangedEvent)(TcxCustomDataController* ADataController, int ARecordIndex, int AItemIndex);

typedef void __fastcall (__closure *TcxDataControllerNotifyEvent)(TcxCustomDataController* ADataController);

typedef void __fastcall (__closure *TcxDataRecordNotifyEvent)(TcxCustomDataController* ADataController, int ARecordIndex);

typedef void __fastcall (__closure *TcxDataRecordAllowOperationEvent)(TcxCustomDataController* ADataController, int ARecordIndex, bool &AAllow);

typedef TcxDataRecordAllowOperationEvent TcxDataDetailExpandingEvent;

typedef TcxDataRecordNotifyEvent TcxDataDetailExpandedEvent;

enum DECLSPEC_DENUM TcxDataControllerOption : unsigned char { dcoAnsiSort, dcoCaseInsensitive, dcoAssignGroupingValues, dcoAssignMasterDetailKeys, dcoSaveExpanding, dcoSortByDisplayText, dcoFocusTopRowAfterSorting, dcoGroupsAlwaysExpanded, dcoImmediatePost, dcoInsertOnNewItemRowFocusing, dcoMultiSelectionSyncGroupWithChildren };

typedef System::Set<TcxDataControllerOption, TcxDataControllerOption::dcoAnsiSort, TcxDataControllerOption::dcoMultiSelectionSyncGroupWithChildren> TcxDataControllerOptions;

enum DECLSPEC_DENUM TcxDataControllerEditKind : unsigned char { dceInsert, dceEdit, dceChanging, dceModified };

typedef System::Set<TcxDataControllerEditKind, TcxDataControllerEditKind::dceInsert, TcxDataControllerEditKind::dceModified> TcxDataControllerEditState;

enum DECLSPEC_DENUM TcxDataControllerEditOperation : unsigned char { dceoAppend, dceoDelete, dceoEdit, dceoInsert, dceoShowEdit };

typedef System::Set<TcxDataControllerEditOperation, TcxDataControllerEditOperation::dceoAppend, TcxDataControllerEditOperation::dceoShowEdit> TcxDataControllerEditOperations;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataListenerLink : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxCustomDataController* Ref;
public:
	/* TObject.Create */ inline __fastcall TcxDataListenerLink() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDataListenerLink() { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TcxDataFilterRecordEvent)(TcxCustomDataController* ADataController, int ARecordIndex, bool &Accept);

class PASCALIMPLEMENTATION TcxCustomDataController : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
	
private:
	typedef void __fastcall (__closure *TFieldIndexChangedEvent)(System::TObject* Sender, int AOldIndex, int ANewIndex);
	
	typedef Dxcoreclasses::TdxMulticastMethod__1<TFieldIndexChangedEvent> TFieldIndexChangedEventHandler;
	
	typedef void __fastcall (__closure *TFieldRemovedEvent)(System::TObject* Sender, int AFieldIndex);
	
	typedef Dxcoreclasses::TdxMulticastMethod__1<TFieldRemovedEvent> TFieldRemovedEventHandler;
	
	typedef int __fastcall (__closure *TRecordCompareFunc)(int ARecordIndex1, int ARecordIndex2, TcxCustomDataField* AField);
	
	typedef int __fastcall (*TStringCompareFunc)(const System::UnicodeString S1, const System::UnicodeString S2);
	
	
private:
	TcxCustomDataRelation* FMasterRelation;
	
private:
	bool FActive;
	bool FAfterSummaryFlag;
	int FBookmarkRecordIndex;
	int FBrowsingCount;
	bool FDataChangedFlag;
	int FDataChangedLockCount;
	TcxDataControllerChanges FChanges;
	bool FCheckFocusingAfterFilterNeeded;
	TcxCustomDataController* FCreatingDataController;
	bool FCreatingLinkObject;
	System::Classes::TList* FDataChangedListeners;
	int FDataChangeRefCount;
	TcxCustomDataControllerInfo* FDataControllerInfo;
	Cxdatastorage::TcxDataStorage* FDataStorage;
	bool FDestroying;
	TcxDataCustomExpressionProvider* FExpressionProvider;
	bool FGroupingChangedFlag;
	TcxDataControllerGroups* FGroups;
	TcxCustomDataFieldList* FFields;
	TcxDataFilterCriteria* FFilter;
	TcxFilteringInfo FFilteringInfo;
	TcxDataFindCriteria* FFindCriteria;
	bool FFilterChangedFlag;
	bool FFilteredRecordCountChanged;
	TcxDataFilterList* FFilters;
	bool FFocusedSelected;
	TcxCustomDataField* FIncrementalFilterField;
	System::UnicodeString FIncrementalFilterText;
	bool FIncrementalFilteringFromAnyPos;
	TcxCustomDataField* FIncrementalSearchField;
	bool FIncrementalSearching;
	System::UnicodeString FIncrementalSearchText;
	bool FInCancel;
	bool FInLoadStorage;
	bool FInNotifyControl;
	bool FInOnSortingChanged;
	bool FInternalFindRecord;
	bool FIsDetailExpanding;
	bool FIsPattern;
	bool FIsPatternSave;
	bool FInSetCustomDataSource;
	bool FInSmartLoad;
	System::Classes::TList* FListenerLinks;
	bool FLoadedStorage;
	int FLockGridModeNotifyCount;
	int FLockUpdateFieldsCount;
	bool FUpdateFieldsFlag;
	int FNewItemRecordIndex;
	bool FNewItemRowFocused;
	int FMasterRecordIndex;
	bool FMultiSelect;
	TcxDataControllerMultiThreadedOptions* FMultiThreadedOptions;
	TcxDataControllerNotifier* FNotifier;
	TcxDataControllerOptions FOptions;
	System::Classes::TComponent* FOwner;
	TcxCustomDataController* FPatternDataController;
	TcxCustomDataController* FPostSyncMasterPosDataController;
	TcxDataSelectionChangedInfo FPrevSelectionChangedInfo;
	TcxCustomDataProvider* FProvider;
	TcxCustomDataField* FRecordHandlesField;
	bool FRecreatingLinkObject;
	TcxCustomDataRelationList* FRelations;
	int FSavedInternalRecordIndex;
	System::TObject* FSaveObject;
	int FSaveObjectLockCount;
	TcxDataControllerSearch* FSearch;
	TcxDataSelectionChangedInfo FSelectionChangedInfo;
	bool FSortingBySummaryChangedFlag;
	TcxCustomDataField* FSortingBySummaryDataItemField;
	bool FSortingChangedFlag;
	bool FStructureChanged;
	bool FStructureRecreated;
	TcxDataSummary* FSummary;
	bool FUpdateItems;
	bool FUseNewItemRowForEditing;
	bool FIsAnsiSort;
	bool FIsProviderMode;
	bool FIsStringConversionNeeded;
	TRecordCompareFunc FNativeCompareFunc;
	TStringCompareFunc FStringCompareFunc;
	TcxDataControllerNotifyEvent FOnAfterCancel;
	TcxDataControllerNotifyEvent FOnAfterDelete;
	TcxDataControllerNotifyEvent FOnAfterInsert;
	TcxDataControllerNotifyEvent FOnAfterPost;
	TcxDataControllerNotifyEvent FOnBeforeCancel;
	TcxDataRecordNotifyEvent FOnBeforeDelete;
	TcxDataControllerNotifyEvent FOnBeforeImmediatePost;
	TcxDataControllerNotifyEvent FOnBeforeInsert;
	TcxDataControllerNotifyEvent FOnBeforePost;
	TcxDataRecordAllowOperationEvent FOnCanSelectRecord;
	TcxDataFilterRecordEvent FOnFilterRecord;
	TcxDataRecordNotifyEvent FOnNewRecord;
	TcxDataControllerCompareEvent FOnCompare;
	System::Classes::TNotifyEvent FOnDataChanged;
	TcxDataRecordAllowOperationEvent FOnDetailCollapsing;
	TcxDataRecordNotifyEvent FOnDetailCollapsed;
	TcxDataRecordAllowOperationEvent FOnDetailExpanding;
	TcxDataRecordNotifyEvent FOnDetailExpanded;
	Dxcoreclasses::TdxMulticastMethod__1<TFieldIndexChangedEvent> FOnFieldIndexChanged;
	Dxcoreclasses::TdxMulticastMethod__1<TFieldRemovedEvent> FOnFieldRemoved;
	System::Classes::TNotifyEvent FOnGroupingChanged;
	TcxDataRecordChangedEvent FOnRecordChanged;
	System::Classes::TNotifyEvent FOnSortingChanged;
	TcxUpdateControlEvent FOnUpdateControl;
	bool __fastcall FilterIterationStep(void * AContext, int ARecordIndex);
	TcxCustomDataSource* __fastcall GetCustomDataSource();
	TcxDataControllerDetailMode __fastcall GetDetailMode();
	TcxDataCustomExpressionProvider* __fastcall GetExpressionProvider();
	int __fastcall GetFixedBottomRowCount();
	int __fastcall GetFixedTopRowCount();
	bool __fastcall GetHasRelations();
	bool __fastcall GetIsBrowsing();
	bool __fastcall GetIsEditing();
	bool __fastcall GetIsPattern();
	System::UnicodeString __fastcall GetItemExpression(int AItemIndex);
	int __fastcall GetLockCount();
	bool __fastcall GetNewItemRowFocused();
	TcxDataFindCriteriaBeforeChangeEvent __fastcall GetOnFindCriteriaBeforeChange();
	TcxDataFindCriteriaChangedEvent __fastcall GetOnFindCriteriaChanged();
	TcxCustomDataRelationList* __fastcall GetRelations();
	TcxDataControllerRowFixedState __fastcall GetRowFixedState(int ARowIndex);
	int __fastcall GetSortingBySummaryDataItemIndex();
	void __fastcall SetCustomDataSource(TcxCustomDataSource* Value);
	void __fastcall SetIsBrowsing(bool Value);
	void __fastcall SetIsPattern(bool Value);
	void __fastcall SetItemExpression(int AItemIndex, const System::UnicodeString AValue);
	void __fastcall SetFilter(TcxDataFilterCriteria* Value);
	void __fastcall SetFocusedRowIndex(int Value);
	void __fastcall SetMasterRelationValue(TcxCustomDataRelation* AValue);
	void __fastcall SetMultiSelect(bool Value);
	void __fastcall SetMultiThreadedOptions(TcxDataControllerMultiThreadedOptions* Value);
	void __fastcall SetNewItemRowFocused(bool Value);
	void __fastcall SetOnFilterRecord(TcxDataFilterRecordEvent Value);
	void __fastcall SetOnFindCriteriaBeforeChange(TcxDataFindCriteriaBeforeChangeEvent Value);
	void __fastcall SetOnFindCriteriaChanged(TcxDataFindCriteriaChangedEvent Value);
	void __fastcall SetOptions(TcxDataControllerOptions Value);
	void __fastcall SetRowFixedState(int ARowIndex, TcxDataControllerRowFixedState AValue);
	void __fastcall SetSummary(TcxDataSummary* Value);
	void __fastcall SetUseNewItemRowForEditing(bool Value);
	void __fastcall SetSortingBySummaryDataItemIndex(int Value);
	void __fastcall Update();
	void __fastcall BeforeGroupingNotification();
	void __fastcall BookmarkNotification();
	void __fastcall DataNotification();
	void __fastcall GridModeChanged();
	void __fastcall GroupingChanged();
	void __fastcall FieldIndexChanged(int AOldIndex, int ANewIndex);
	void __fastcall FindCriteriaNotification();
	void __fastcall FocusedNotification();
	void __fastcall LayoutNotification();
	void __fastcall SearchNotification();
	void __fastcall SelectionNotification();
	void __fastcall SortingBySummaryChanged();
	void __fastcall SortingChanged();
	void __fastcall NotifyListenerLinks();
	void __fastcall PrecalculateOptions();
	void __fastcall ResetDataChangeInfo();
	void __fastcall UpdateProviderMode();
	void __fastcall UpdateRecordNotification();
	int __fastcall GetStorageRecordCount();
	void __fastcall SetStorageRecordCount(const int Value);
	
protected:
	TcxDataChangeInfo FDataChangeInfo;
	bool FInDeleteSelection;
	bool FInFocusDetails;
	int FNearestRecordIndex;
	HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef();
	int __stdcall _Release();
	virtual TcxCustomDataField* __fastcall AddInternalField();
	virtual TcxCustomDataField* __fastcall AddField();
	virtual int __fastcall AppendInSmartLoad();
	bool __fastcall AreFieldValuesEqual(int ARecordIndex1, int ARecordIndex2, System::Classes::TList* AFields);
	virtual void __fastcall BeforeSorting();
	virtual int __fastcall CalcEditingRecordIndex();
	virtual bool __fastcall CanChangeDetailExpanding(int ARecordIndex, bool AExpanded);
	virtual bool __fastcall CanFixRows();
	virtual bool __fastcall CanFocusRecord(int ARecordIndex);
	virtual bool __fastcall CanLoadData();
	virtual bool __fastcall CanSelectRecord(int ARecordIndex);
	virtual bool __fastcall CanSelectRow(int ARowIndex);
	void __fastcall CheckChanges();
	void __fastcall Change(TcxDataControllerChanges AChanges);
	virtual void __fastcall CheckBookmarkValid(int ADeletedRecordIndex);
	virtual void __fastcall CheckDataSetCurrent();
	virtual void __fastcall CheckEditingOnFindCriteriaChanged();
	virtual void __fastcall CheckEditingRecordIndex(int ARecordIndex);
	void __fastcall CheckInternalRecordRange(int ARecordIndex);
	void __fastcall CheckItemRange(int AItemIndex);
	virtual bool __fastcall CheckDetailsBrowseMode();
	virtual bool __fastcall CheckMasterBrowseMode();
	void __fastcall CheckMode();
	void __fastcall CheckNearestFocusRow();
	void __fastcall CheckRange(int ARecordIndex, int AItemIndex);
	void __fastcall CheckRecordRange(int ARecordIndex);
	void __fastcall CheckSelectedCount(int ADeletedRecordIndex);
	void __fastcall ClearDataChangedListeners();
	virtual void __fastcall ClearDetailsMasterRelation(TcxCustomDataRelation* ARelation);
	int __fastcall CompareIntegers(void * AItem1, void * AItem2);
	virtual void __fastcall CopyRecord(int AFromRecordIndex, int AToRecordIndex);
	virtual void __fastcall CorrectAfterInsert(int ARecordIndex);
	virtual void __fastcall CorrectAfterDelete(int ARecordIndex);
	void __fastcall CorrectPrevSelectionChangedInfo();
	virtual TcxCustomDataControllerInfo* __fastcall CreateDataControllerInfo();
	virtual TcxDataCustomExpressionProvider* __fastcall CreateExpressionProvider();
	virtual TcxDataFindCriteria* __fastcall CreateFindCriteria();
	void __fastcall CustomDataSourceChanged();
	virtual void __fastcall DeleteInSmartLoad(int ARecordIndex);
	void __fastcall NotifyControl(TcxUpdateControlInfo* AUpdateControlInfo);
	virtual void __fastcall Unlocked();
	void __fastcall CancelIncrementalSearch();
	virtual void __fastcall DoAfterCancel();
	virtual void __fastcall DoAfterDelete();
	virtual void __fastcall DoAfterInsert();
	virtual void __fastcall DoAfterPost();
	virtual void __fastcall DoBeforeCancel();
	virtual void __fastcall DoBeforeDelete(int ARecordIndex);
	virtual void __fastcall DoBeforeImmediatePost();
	virtual void __fastcall DoBeforeInsert();
	virtual void __fastcall DoBeforePost();
	virtual void __fastcall DoGridModeChanged();
	virtual void __fastcall DoGroupingChanged();
	virtual bool __fastcall DoFilterRecordEvent(int ARecordIndex);
	void __fastcall DoFilterRecordList(Dxcoreclasses::TdxFastList* ARecordList);
	virtual bool __fastcall DoGlobalFilterRecord(int ARecordIndex);
	virtual void __fastcall DoNewRecord(int ARecordIndex);
	bool __fastcall DoChangeDetailExpanding(TcxDetailObject* ADetailObject, int ARecordIndex, bool AExpanded);
	virtual void __fastcall DoDataChanged();
	virtual void __fastcall DoDetailExpanding(int ARecordIndex, bool &AAllow);
	virtual void __fastcall DoDetailExpanded(int ARecordIndex);
	virtual void __fastcall DoDetailCollapsing(int ARecordIndex, bool &AAllow);
	virtual void __fastcall DoDetailCollapsed(int ARecordIndex);
	virtual bool __fastcall DoIncrementalFilterRecord(int ARecordIndex);
	virtual void __fastcall DoReadRecord(int ARecordIndex);
	virtual bool __fastcall DoSearchInGridMode(const System::UnicodeString ASubText, bool AForward, bool ANext);
	virtual void __fastcall DoSortingChanged();
	virtual bool __fastcall HasFiltering();
	virtual void __fastcall UpdateFilteringInfo();
	virtual void __fastcall CalculateExpressionFieldValue(int ARecordIndex, TcxCustomDataField* AField);
	virtual void __fastcall ClearExpressionFieldValues()/* overload */;
	virtual void __fastcall ClearExpressionFieldValues(int ARecordIndex)/* overload */;
	virtual void __fastcall ClearFieldValueDef(TcxCustomDataField* AField);
	virtual void __fastcall ClearFieldValues(TcxCustomDataField* AField);
	virtual void __fastcall ClearValue(int ARecordIndex, TcxCustomDataField* AField);
	virtual TcxCustomDataRelationList* __fastcall CreateDataRelationList();
	virtual void __fastcall FieldExpressionChanged();
	virtual bool __fastcall FindCriteriaChangesData();
	virtual System::TObject* __fastcall FindItemByInternalID(int AID);
	virtual System::TObject* __fastcall FindItemByName(const System::UnicodeString AName);
	virtual System::TObject* __fastcall FindProperItemLink(System::TObject* AItemLink);
	virtual int __fastcall GetActiveRecordIndex();
	virtual bool __fastcall GetClearDetailsOnCollapse();
	virtual TcxCustomDataProviderClass __fastcall GetDataProviderClass();
	virtual int __fastcall GetDataRowCount();
	virtual TcxDataSelectionClass __fastcall GetDataSelectionClass();
	virtual TcxDataControllerEditOperations __fastcall GetEditOperations();
	virtual TcxDataControllerEditState __fastcall GetEditState();
	virtual int __fastcall GetErrorCode(int ARecordIndex, int AItemIndex);
	virtual System::UnicodeString __fastcall GetExpressionFieldDisplayText(int ARecordIndex, TcxCustomDataField* AField);
	virtual System::Variant __fastcall GetExpressionFieldValue(int ARecordIndex, TcxCustomDataField* AField);
	virtual int __fastcall GetDefaultActiveRelationIndex();
	virtual TcxCustomDataFieldClass __fastcall GetFieldClass();
	virtual TcxDataFilterCriteriaClass __fastcall GetFilterCriteriaClass();
	virtual int __fastcall GetFilteredIndexByRecordIndex(int Index);
	virtual int __fastcall GetFilteredRecordCount();
	virtual int __fastcall GetFilteredRecordIndex(int Index);
	virtual int __fastcall GetFilteringRecordCount(bool AUseFiltered);
	virtual int __fastcall GetFocusedDataRowIndex();
	virtual TcxDataControllerGroupsClass __fastcall GetGroupsClass();
	virtual System::UnicodeString __fastcall GetInternalDisplayText(int ARecordIndex, TcxCustomDataField* AField)/* overload */;
	System::UnicodeString __fastcall GetInternalDisplayText(int ARecordIndex, int AItemIndex)/* overload */;
	virtual int __fastcall GetInternalErrorCode(int ARecordIndex, int AItemIndex);
	virtual int __fastcall GetItemID(System::TObject* AItem);
	virtual System::UnicodeString __fastcall GetItemName(System::TObject* AItem);
	virtual System::Variant __fastcall GetInternalRecordId(int ARecordIndex, System::Classes::TList* AFieldList);
	virtual System::Variant __fastcall GetInternalValue(int ARecordIndex, TcxCustomDataField* AField);
	virtual void __fastcall GetKeyFields(System::Classes::TList* AList);
	int __fastcall GetLastRecordIndex();
	virtual TcxDataControllerMultiThreadedOptionsClass __fastcall GetMultiThreadedOptionsClass();
	virtual int __fastcall GetRecordIndex();
	virtual int __fastcall GetFilterRecordIndexByFilteringRecordIndex(bool AUseFiltered, int AIndex);
	virtual TcxCustomDataRelationClass __fastcall GetRelationClass();
	virtual TcxDataControllerSearchClass __fastcall GetSearchClass();
	virtual System::UnicodeString __fastcall GetStoredDisplayText(int ARecordIndex, TcxCustomDataField* AField);
	virtual int __fastcall GetStoredErrorCode(int ARecordIndex, TcxCustomDataField* AField);
	virtual System::Variant __fastcall GetStoredValue(int ARecordIndex, TcxCustomDataField* AField);
	virtual TcxDataSummaryClass __fastcall GetSummaryClass();
	virtual TcxDataSummaryItemClass __fastcall GetSummaryItemClass();
	virtual TcxDataSummaryGroupItemLinkClass __fastcall GetSummaryGroupItemLinkClass();
	virtual bool __fastcall HasExpressionFields();
	virtual bool __fastcall HasFilterEvent();
	virtual void __fastcall InitFieldValueDef(TcxCustomDataField* AField);
	virtual bool __fastcall InternalCheckBookmark(int ADeletedRecordIndex);
	virtual void __fastcall InternalClearBookmark();
	virtual void __fastcall InternalGotoBookmark();
	virtual bool __fastcall InternalSaveBookmark();
	bool __fastcall IsDataBound();
	bool __fastcall IsDataChangedListenersExist();
	virtual bool __fastcall IsDataField(TcxCustomDataField* AField);
	virtual bool __fastcall IsDestroying();
	bool __fastcall IsExpression(int AItemIndex);
	virtual bool __fastcall IsExpressionsSupported();
	virtual bool __fastcall IsFieldSupportsExpression(TcxCustomDataField* AField);
	virtual bool __fastcall IsFiltering();
	virtual bool __fastcall IsFilteringByFindCriteria();
	virtual bool __fastcall IsFocusedSelectedMode();
	virtual bool __fastcall IsItemSupportMultiThreading(int AItemIndex);
	bool __fastcall IsItemSupportsExpression(int AItemIndex);
	virtual bool __fastcall IsKeyNavigation();
	virtual bool __fastcall IsLoading();
	virtual bool __fastcall IsMergedGroupsSupported();
	virtual bool __fastcall IsProviderDataSource();
	bool __fastcall IsRecordID();
	virtual bool __fastcall IsSmartLoad();
	virtual bool __fastcall IsSmartRefresh();
	virtual bool __fastcall IsStoredValueEmpty(int ARecordIndex, TcxCustomDataField* AField);
	virtual bool __fastcall IsUnboundMode();
	virtual void __fastcall LoadStorage();
	bool __fastcall IsNewItemRecordIndex(int ARecordIndex);
	virtual bool __fastcall LockOnAfterSummary();
	void __fastcall NotifyDataChangedListeners();
	virtual void __fastcall NotifyDataControllers();
	void __fastcall PostValidateRelations();
	virtual void __fastcall PrepareField(TcxCustomDataField* AField);
	virtual void __fastcall PrepareFieldForSorting(TcxCustomDataField* AField, TcxDataControllerComparisonMode AMode);
	virtual void __fastcall ProviderValueDefSetProc(Cxdatastorage::TcxValueDef* AValueDef, int AFromRecordIndex, int AToRecordIndex, Cxdatastorage::TcxValueDefReader* AValueDefReader);
	virtual void __fastcall RemoveNotification(System::Classes::TComponent* AComponent);
	virtual void __fastcall ResetFieldAfterSorting(TcxCustomDataField* AField);
	void __fastcall ResetMasterHasChildrenFlag();
	void __fastcall ResetNewItemRowFocused();
	virtual void __fastcall RestructData();
	virtual void __fastcall SetStoredErrorCode(int ARecordIndex, TcxCustomDataField* AField, int ACode);
	virtual void __fastcall SetStoredValue(int ARecordIndex, TcxCustomDataField* AField, const System::Variant &Value);
	int __fastcall AppendStorageRecord();
	void __fastcall DeleteStorageRecord(int ARecordIndex);
	void __fastcall SetMasterRecordIndex(int ARecordIndex);
	void __fastcall SetNullValues(TcxCustomDataField* AField);
	void __fastcall SetPatternDataController(TcxCustomDataController* AValue);
	virtual bool __fastcall SyncDetailsFocusWithMaster();
	virtual void __fastcall SyncMasterPos();
	virtual void __fastcall UpdateExpressionFieldFormulas();
	virtual void __fastcall UpdateExpressionFields();
	virtual void __fastcall UpdateFields();
	virtual void __fastcall UpdateFocused();
	virtual void __fastcall UpdateRelations(TcxCustomDataRelation* ARelation);
	void __fastcall UpdateUseRecordIDState();
	void __fastcall UpdateStorage(bool AUpdateFields);
	virtual bool __fastcall UseRecordID();
	__classmethod TcxDataListenerLink* __fastcall AddListenerLink(TcxCustomDataController* ADataController);
	__classmethod void __fastcall RemoveListenerLink(TcxDataListenerLink* ALink);
	void __fastcall ClearStorageInternalRecords(System::TObject* Sender);
	void __fastcall ClearStorageRecord(System::TObject* Sender, int ARecordIndex);
	virtual void __fastcall DoFieldRemoved(int AFieldIndex);
	virtual void __fastcall RemoveField(TcxCustomDataField* ADataField);
	virtual void __fastcall FilterChanged();
	virtual void __fastcall SummaryChanged(bool ARedrawOnly);
	virtual void __fastcall FindCriteriaChanged();
	virtual void __fastcall ActiveChanged(bool AActive);
	virtual void __fastcall DataChanged(TcxDataChange ADataChange, int AItemIndex, int ARecordIndex);
	virtual void __fastcall DataScrolled(int ADistance);
	virtual void __fastcall LayoutChanged(TcxDataLayoutChanges ADataLayoutChanges);
	virtual void __fastcall DoBeforeFocusedRowChange(int ARowIndex);
	virtual void __fastcall DoValueTypeClassChanged(int AItemIndex);
	virtual void __fastcall UpdateControl(TcxUpdateControlInfo* AInfo);
	virtual System::UnicodeString __fastcall GetFilterDisplayText(int ARecordIndex, int AItemIndex);
	virtual System::UnicodeString __fastcall GetIncrementalSearchText(int ARecordIndex, int AItemIndex);
	virtual bool __fastcall GetIsRowInfoValid();
	virtual int __fastcall CompareByField(int ARecordIndex1, int ARecordIndex2, TcxCustomDataField* AField, TcxDataControllerComparisonMode AMode);
	virtual int __fastcall CompareEqualRecords(int ARecordIndex1, int ARecordIndex2);
	virtual int __fastcall CompareRecords(int ARecordIndex1, int ARecordIndex2, TcxDataSortFieldInfo* ASortInfo, TcxDataControllerComparisonMode AMode = (TcxDataControllerComparisonMode)(0x2));
	int __fastcall CompareRecordsValues(int ARecordIndex1, int ARecordIndex2, TcxCustomDataField* AField);
	virtual System::UnicodeString __fastcall DoGetGroupRowDisplayText(const TcxRowInfo &ARowInfo, int &AItemIndex);
	int __fastcall FindGroupRecord(int ABufferRecordIndex, int AGroupItemCount, bool AIsGroupDataSorted);
	virtual int __fastcall FindRecordByFields(int ABufferRecordIndex, System::Classes::TList* AFields);
	virtual System::Variant __fastcall GetComparedValue(int ARecordIndex, TcxCustomDataField* AField);
	virtual System::Variant __fastcall GetGroupRowValueByItemIndex(const TcxRowInfo &ARowInfo, int AItemIndex);
	virtual bool __fastcall IsConversionNeededForCompare(TcxCustomDataField* AField);
	virtual bool __fastcall IsFilterItemSortByDisplayText(int AItemIndex);
	virtual bool __fastcall IsSortByDisplayTextNeeded(TcxCustomDataField* AField);
	virtual bool __fastcall IsStringConversionNeeded(TcxCustomDataField* AField);
	int __fastcall NativeCompareRecords(int ARecordIndex1, int ARecordIndex2, TcxCustomDataField* AField);
	void __fastcall DeleteFocusedRecord();
	void __fastcall DeleteRecords(System::Classes::TList* AList);
	virtual void __fastcall BeginSmartLoad();
	virtual void __fastcall EndSmartLoad();
	virtual int __fastcall LoadRecord(void * AData);
	virtual void __fastcall BeginReadRecord();
	virtual void __fastcall EndReadRecord();
	virtual TcxSortingBySummaryEngineClass __fastcall GetSortingBySummaryEngineClass();
	void __fastcall LockStateInfo(bool AUseLockedUpdate = true);
	void __fastcall UnlockStateInfo(bool AUseLockedUpdate = true);
	virtual bool __fastcall GetAnsiSortSetting();
	virtual bool __fastcall GetAssignGroupingValuesSetting();
	virtual bool __fastcall GetAssignMasterDetailKeysSetting();
	virtual bool __fastcall GetCaseInsensitiveSetting();
	virtual bool __fastcall GetFocusTopRowAfterSortingSetting();
	virtual bool __fastcall GetGroupsAlwaysExpandedSetting();
	virtual bool __fastcall GetImmediatePostSetting();
	virtual bool __fastcall GetInsertOnNewItemRowFocusingSetting();
	virtual bool __fastcall GetIsProviderMode();
	virtual bool __fastcall GetSaveExpandingSetting();
	virtual bool __fastcall GetSortByDisplayTextSetting();
	virtual bool __fastcall IsMultiThreadedFiltering();
	virtual bool __fastcall IsMultiThreadedSorting();
	virtual bool __fastcall IsMultiThreadedSummary();
	virtual void __fastcall PopulateFilterValues(TcxDataFilterValueList* AList, int AItemIndex, Cxfilter::TcxFilterCriteria* ACriteria, bool &AUseFilteredRecords, /* out */ bool &ANullExists, bool AUniqueOnly, bool AFilteredRecordsShowFilteredItemsOnly);
	__property bool FilteredRecordCountChanged = {read=FFilteredRecordCountChanged, write=FFilteredRecordCountChanged, nodefault};
	__property bool FilterChangedFlag = {read=FFilterChangedFlag, write=FFilterChangedFlag, nodefault};
	__property bool GroupingChangedFlag = {read=FGroupingChangedFlag, write=FGroupingChangedFlag, nodefault};
	__property bool InNotifyControl = {read=FInNotifyControl, nodefault};
	__property bool LoadedStorage = {read=FLoadedStorage, write=FLoadedStorage, nodefault};
	__property TcxCustomDataRelation* MasterRelation = {read=FMasterRelation, write=SetMasterRelationValue};
	__property bool SortingBySummaryChangedFlag = {read=FSortingBySummaryChangedFlag, write=FSortingBySummaryChangedFlag, nodefault};
	__property bool SortingChangedFlag = {read=FSortingChangedFlag, write=FSortingChangedFlag, nodefault};
	__property bool StructureChanged = {read=FStructureChanged, write=FStructureChanged, nodefault};
	__property Cxdatastorage::TcxDataStorage* DataStorage = {read=FDataStorage};
	__property TcxCustomDataFieldList* Fields = {read=FFields};
	__property TcxDataControllerNotifier* Notifier = {read=FNotifier};
	__property System::Classes::TComponent* Owner = {read=FOwner};
	__property TcxCustomDataProvider* Provider = {read=FProvider};
	__property int LockUpdateFieldsCount = {read=FLockUpdateFieldsCount, nodefault};
	__property Dxcoreclasses::TdxMulticastMethod__1<TFieldIndexChangedEvent> OnFieldIndexChanged = {read=FOnFieldIndexChanged};
	__property Dxcoreclasses::TdxMulticastMethod__1<TFieldRemovedEvent> OnFieldRemoved = {read=FOnFieldRemoved};
	__property int StorageRecordCount = {read=GetStorageRecordCount, write=SetStorageRecordCount, nodefault};
	__property TcxDataRecordAllowOperationEvent OnCanSelectRecord = {read=FOnCanSelectRecord, write=FOnCanSelectRecord};
	
public:
	__fastcall virtual TcxCustomDataController(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomDataController();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall BeforeDestruction();
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner() _FINAL_ATTRIBUTE;
	void __fastcall BeginUpdate();
	void __fastcall EndUpdate();
	virtual void __fastcall BeginFullUpdate();
	virtual void __fastcall EndFullUpdate();
	void __fastcall BeginUpdateFields();
	void __fastcall EndUpdateFields();
	void __fastcall SaveKeys();
	void __fastcall RestoreKeys();
	virtual TcxDataFilterCriteria* __fastcall CreateFilter();
	virtual TcxSummaryKinds __fastcall GetAllowedSummaryKinds(Cxdatastorage::TcxValueTypeClass ATypeClass)/* overload */;
	virtual TcxSummaryKinds __fastcall GetAllowedSummaryKinds(int AItemIndex)/* overload */;
	virtual TcxSummaryKinds __fastcall GetAllowedSummaryKinds(TcxCustomDataField* AField)/* overload */;
	virtual bool __fastcall IsImmediatePost();
	virtual TcxCustomDataField* __fastcall AddItem(System::TObject* AItem);
	virtual bool __fastcall ItemPropertiesChanged(int AItemIndex);
	virtual void __fastcall Loaded();
	virtual void __fastcall RemoveItem(System::TObject* AItem);
	virtual void __fastcall UpdateItemIndexes();
	virtual void __fastcall UpdateItems(bool AUpdateFields);
	virtual bool __fastcall ExecuteAction(System::Classes::TBasicAction* Action);
	virtual bool __fastcall UpdateAction(System::Classes::TBasicAction* Action);
	virtual void __fastcall UpdateExpressionItems();
	void __fastcall AddDataChangedListener(System::TObject* AInstance, System::Classes::TNotifyEvent ADataChangedEvent);
	void __fastcall RemoveDataChangedListener(System::TObject* AInstance, System::Classes::TNotifyEvent ADataChangedEvent);
	void __fastcall AddDataChangeRefCount();
	void __fastcall RemoveDataChangeRefCount();
	virtual bool __fastcall DataChangedNotifyLocked();
	bool __fastcall IsDataLoading();
	void __fastcall LockDataChangedNotify();
	void __fastcall UnlockDataChangedNotify();
	void __fastcall LockGridModeNotify();
	void __fastcall UnlockGridModeNotify();
	virtual void __fastcall ChangeNeedConversion(int AItemIndex, bool ANeedConversion);
	virtual void __fastcall ChangeTextStored(int AItemIndex, bool ATextStored);
	virtual void __fastcall ChangeValueTypeClass(int AItemIndex, Cxdatastorage::TcxValueTypeClass AValueTypeClass);
	virtual System::TObject* __fastcall GetItem(int Index) = 0 ;
	virtual int __fastcall GetItemCount();
	virtual bool __fastcall GetItemNeedConversion(int AItemIndex);
	virtual bool __fastcall GetItemTextStored(int AItemIndex);
	Cxdatastorage::TcxValueTypeClass __fastcall GetItemValueTypeClass(int AItemIndex);
	virtual bool __fastcall IsDisplayFormatDefined(int AItemIndex, bool AIgnoreSimpleCurrency);
	virtual int __fastcall AppendRecord();
	void __fastcall DeleteRecord(int ARecordIndex);
	virtual System::Variant __fastcall GetGroupValue(int ARecordIndex, TcxCustomDataField* AField);
	virtual void __fastcall GetGroupValues(int ARecordIndex, TcxDataSummaryValues &AValues);
	virtual System::UnicodeString __fastcall GetDisplayText(int ARecordIndex, int AItemIndex);
	virtual int __fastcall GetRecordCount();
	virtual System::Variant __fastcall GetRecordId(int ARecordIndex);
	virtual System::Variant __fastcall GetValue(int ARecordIndex, int AItemIndex);
	virtual int __fastcall InsertRecord(int ARecordIndex);
	bool __fastcall IsItemExpression(int AItemIndex);
	virtual void __fastcall Refresh();
	virtual void __fastcall SetDisplayText(int ARecordIndex, int AItemIndex, const System::UnicodeString Value);
	virtual void __fastcall SetRecordCount(int Value);
	virtual void __fastcall SetValue(int ARecordIndex, int AItemIndex, const System::Variant &Value);
	void __fastcall SortByDisplayTextChanged();
	virtual void __fastcall Append();
	virtual void __fastcall Cancel();
	virtual bool __fastcall CanInitEditing(int AItemIndex);
	virtual void __fastcall CheckBrowseMode();
	virtual void __fastcall DeleteFocused();
	virtual void __fastcall DeleteSelection();
	virtual void __fastcall Edit();
	virtual void __fastcall FocusControl(int AItemIndex, bool &Done);
	virtual System::Variant __fastcall GetEditValue(int AItemIndex, Cxdatautils::TcxDataEditValueSource AEditValueSource);
	virtual Cxdatautils::TcxDataEditValueSource __fastcall GetItemValueSource(int AItemIndex);
	virtual void __fastcall Insert();
	virtual void __fastcall Post(bool AForcePost = false);
	virtual void __fastcall PostEditingData();
	virtual void __fastcall RefreshExternalData();
	virtual bool __fastcall SetEditValue(int AItemIndex, const System::Variant &AValue, Cxdatautils::TcxDataEditValueSource AEditValueSource);
	virtual void __fastcall UpdateData();
	virtual int __fastcall GetEditingRecordIndex();
	virtual int __fastcall GetNewItemRecordIndex();
	void __fastcall LoadFromStream(System::Classes::TStream* AStream);
	void __fastcall SaveToStream(System::Classes::TStream* AStream);
	virtual TcxCustomDataController* __fastcall GetMasterDataController();
	virtual int __fastcall GetMasterRecordIndex();
	virtual TcxCustomDataRelation* __fastcall GetMasterRelation();
	TcxCustomDataController* __fastcall GetPatternDataController();
	TcxCustomDataController* __fastcall GetRootDataController();
	virtual bool __fastcall IsDetailMode();
	virtual System::TObject* __fastcall CreateDetailLinkObject(TcxCustomDataRelation* ARelation, int ARecordIndex);
	void __fastcall FocusDetails(int ARecordIndex);
	virtual TcxCustomDataController* __fastcall GetDetailDataControllerByLinkObject(System::TObject* ALinkObject);
	virtual void __fastcall ResetRelationByItem(System::TObject* AItem);
	void __fastcall SetMasterMode(TcxCustomDataRelation* AMasterRelation, bool AIsPattern);
	virtual void __fastcall SetMasterRelation(TcxCustomDataRelation* AMasterRelation, int AMasterRecordIndex);
	void __fastcall ChangeDetailActiveRelationIndex(int ARecordIndex, int ARelationIndex);
	bool __fastcall ChangeDetailExpanding(int ARecordIndex, bool AExpanded);
	void __fastcall ClearDetailLinkObject(int ARecordIndex, int ARelationIndex);
	virtual void __fastcall ClearDetails();
	void __fastcall CollapseDetails();
	void __fastcall ForEachDetail(TcxCustomDataRelation* AMasterRelation, TcxDataControllerEachDetailProc AProc);
	int __fastcall GetDetailActiveRelationIndex(int ARecordIndex);
	TcxCustomDataController* __fastcall GetDetailDataController(int ARecordIndex, int ARelationIndex);
	bool __fastcall GetDetailExpanding(int ARecordIndex);
	bool __fastcall GetDetailHasChildren(int ARecordIndex, int ARelationIndex);
	System::TObject* __fastcall GetDetailLinkObject(int ARecordIndex, int ARelationIndex);
	bool __fastcall IsDetailDataControllerExist(int ARecordIndex, int ARelationIndex);
	virtual void __fastcall ResetHasChildrenFlag();
	virtual void __fastcall ForEachRow(bool ASelectedRows, TcxDataControllerEachRowProc AProc);
	virtual System::UnicodeString __fastcall GetGroupRowDisplayText(const TcxRowInfo &ARowInfo, int &AItemIndex);
	System::Variant __fastcall GetGroupRowValue(const TcxRowInfo &ARowInfo, int ALevelGroupedItemIndex = 0x0);
	int __fastcall GetNearestRowIndex(int ARowIndex);
	int __fastcall GetRowCount();
	int __fastcall GetRowIndexByRecordIndex(int ARecordIndex, bool AMakeVisible);
	TcxRowInfo __fastcall GetRowInfo(int ARowIndex);
	System::UnicodeString __fastcall GetRowDisplayText(const TcxRowInfo &ARowInfo, int &AItemIndex);
	System::Variant __fastcall GetRowValue(const TcxRowInfo &ARowInfo, int AItemIndex);
	void __fastcall MakeRecordVisible(int ARecordIndex);
	virtual bool __fastcall FocusSelectedRow(int ASelectedIndex);
	virtual void __fastcall RestoreDataSetPos();
	virtual void __fastcall SaveDataSetPos();
	virtual bool __fastcall CanFocusedRecordIndexChangePostData();
	void __fastcall ChangeFocusedRecordIndex(int ARecordIndex);
	virtual bool __fastcall ChangeFocusedRowIndex(int ARowIndex);
	void __fastcall CheckFocusedRow();
	int __fastcall GetFocusedRecordIndex();
	int __fastcall GetFocusedRowIndex();
	void __fastcall GotoFirst();
	void __fastcall GotoLast();
	void __fastcall GotoNext();
	void __fastcall GotoPrev();
	bool __fastcall IsBOF();
	bool __fastcall IsEOF();
	bool __fastcall IsGridMode();
	void __fastcall MoveBy(int ADistance);
	void __fastcall Scroll(int ADistance);
	virtual void __fastcall SetFocus();
	void __fastcall ClearBookmark();
	void __fastcall GotoBookmark();
	virtual bool __fastcall IsBookmarkAvailable();
	virtual bool __fastcall IsBookmarkRow(int ARowIndex);
	void __fastcall SaveBookmark();
	virtual System::Variant __fastcall GetFilterDataValue(int ARecordIndex, TcxCustomDataField* AField);
	virtual System::UnicodeString __fastcall GetFilterItemFieldCaption(System::TObject* AItem);
	virtual System::UnicodeString __fastcall GetFilterItemFieldName(System::TObject* AItem);
	bool __fastcall ChangeIncrementalFilterText(const System::UnicodeString AText);
	virtual int __fastcall FindRecordIndexByText(int AStartRecordIndex, int AItemIndex, const System::UnicodeString AText, bool APartialCompare, bool ACircular, bool AForward)/* overload */;
	virtual int __fastcall FindRecordIndexByText(int AStartRecordIndex, int AItemIndex, const System::UnicodeString AText, bool APartialCompare, bool ACircular, bool AForward, bool ACaseSensitive)/* overload */;
	virtual System::UnicodeString __fastcall GetIncrementalFilterText();
	TcxCustomDataField* __fastcall GetIncrementalFilterField();
	virtual bool __fastcall HasIncrementalFilter();
	virtual void __fastcall ResetIncrementalFilter();
	virtual int __fastcall SetIncrementalFilter(int AItemIndex, const System::UnicodeString AText)/* overload */;
	virtual int __fastcall SetIncrementalFilter(int AItemIndex, const System::UnicodeString AText, bool AUseContainsOperator)/* overload */;
	void __fastcall ChangeItemSortingIndex(int AItemIndex, int ASortingIndex);
	void __fastcall ChangeSorting(int AItemIndex, Dxcore::TdxSortOrder ASortOrder);
	void __fastcall ClearSorting(bool AKeepGroupedItems);
	virtual bool __fastcall GetItemSortByDisplayText(int AItemIndex, bool ASortByDisplayText);
	Dxcore::TdxSortOrder __fastcall GetItemSortOrder(int AItemIndex);
	int __fastcall GetItemSortingIndex(int AItemIndex);
	int __fastcall GetSortingItemCount();
	int __fastcall GetSortingItemIndex(int Index);
	virtual bool __fastcall AreAllRowsSelected();
	virtual void __fastcall ChangeRowSelection(int ARowIndex, bool ASelection);
	void __fastcall CheckFocusedSelected();
	void __fastcall ClearSelection();
	virtual void __fastcall ClearSelectionAnchor();
	virtual System::Variant __fastcall GetRowId(int ARowIndex);
	int __fastcall GetSelectedCount();
	virtual int __fastcall GetSelectedRowIndex(int Index);
	virtual int __fastcall GetSelectionAnchorRowIndex();
	bool __fastcall GroupContainsSelectedRows(int ARowIndex);
	bool __fastcall IsRowSelected(int ARowIndex);
	virtual bool __fastcall IsSelectionAnchorExist();
	virtual bool __fastcall MultiSelectionSyncGroupWithChildren();
	virtual void __fastcall SelectAll();
	virtual void __fastcall SelectFromAnchor(int ARowIndex, bool AKeepSelection);
	void __fastcall SelectRows(int AStartRowIndex, int AEndRowIndex);
	virtual void __fastcall SetSelectionAnchor(int ARowIndex);
	void __fastcall SyncSelected(bool ASelected);
	virtual void __fastcall SyncSelectionFocusedRecord();
	__property bool Active = {read=FActive, nodefault};
	__property TcxCustomDataSource* CustomDataSource = {read=GetCustomDataSource, write=SetCustomDataSource};
	__property TcxCustomDataControllerInfo* DataControllerInfo = {read=FDataControllerInfo};
	__property int DataRowCount = {read=GetDataRowCount, nodefault};
	__property TcxDataControllerDetailMode DetailMode = {read=GetDetailMode, nodefault};
	__property System::UnicodeString DisplayTexts[int RecordIndex][int ItemIndex] = {read=GetDisplayText, write=SetDisplayText};
	__property TcxDataCustomExpressionProvider* ExpressionProvider = {read=GetExpressionProvider};
	__property TcxDataControllerGroups* Groups = {read=FGroups};
	__property int EditingRecordIndex = {read=GetEditingRecordIndex, nodefault};
	__property TcxDataControllerEditOperations EditOperations = {read=GetEditOperations, nodefault};
	__property TcxDataControllerEditState EditState = {read=GetEditState, nodefault};
	__property int ErrorCodes[int ARecordIndex][int AItemIndex] = {read=GetErrorCode};
	__property TcxDataFilterCriteria* Filter = {read=FFilter, write=SetFilter};
	__property int FilteredIndexByRecordIndex[int Index] = {read=GetFilteredIndexByRecordIndex};
	__property int FilteredRecordCount = {read=GetFilteredRecordCount, nodefault};
	__property int FilteredRecordIndex[int Index] = {read=GetFilteredRecordIndex};
	__property TcxDataFindCriteria* FindCriteria = {read=FFindCriteria};
	__property int FixedBottomRowCount = {read=GetFixedBottomRowCount, nodefault};
	__property int FixedTopRowCount = {read=GetFixedTopRowCount, nodefault};
	__property int FocusedDataRowIndex = {read=GetFocusedDataRowIndex, nodefault};
	__property int FocusedRecordIndex = {read=GetFocusedRecordIndex, write=ChangeFocusedRecordIndex, nodefault};
	__property int FocusedRowIndex = {read=GetFocusedRowIndex, write=SetFocusedRowIndex, nodefault};
	__property bool HasRelations = {read=GetHasRelations, nodefault};
	__property bool IsBrowsing = {read=GetIsBrowsing, write=SetIsBrowsing, nodefault};
	__property bool IsCancelling = {read=FInCancel, nodefault};
	__property bool IsCreatingLinkObject = {read=FCreatingLinkObject, nodefault};
	__property bool IsDetailExpanding = {read=FIsDetailExpanding, nodefault};
	__property bool IsEditing = {read=GetIsEditing, nodefault};
	__property bool IsPattern = {read=GetIsPattern, write=SetIsPattern, nodefault};
	__property bool IsProviderMode = {read=FIsProviderMode, nodefault};
	__property bool IsRowInfoValid = {read=GetIsRowInfoValid, nodefault};
	__property bool IsUpdatingItems = {read=FUpdateItems, nodefault};
	__property int ItemCount = {read=GetItemCount, nodefault};
	__property System::UnicodeString ItemExpressions[int AItemIndex] = {read=GetItemExpression, write=SetItemExpression};
	__property int LockCount = {read=GetLockCount, nodefault};
	__property int LockGridModeNotifyCount = {read=FLockGridModeNotifyCount, nodefault};
	__property bool MultiSelect = {read=FMultiSelect, write=SetMultiSelect, nodefault};
	__property TcxDataControllerMultiThreadedOptions* MultiThreadedOptions = {read=FMultiThreadedOptions, write=SetMultiThreadedOptions};
	__property int NewItemRecordIndex = {read=GetNewItemRecordIndex, nodefault};
	__property bool NewItemRowFocused = {read=GetNewItemRowFocused, write=SetNewItemRowFocused, nodefault};
	__property TcxDataControllerOptions Options = {read=FOptions, write=SetOptions, default=28};
	__property int RecordCount = {read=GetRecordCount, write=SetRecordCount, nodefault};
	__property TcxCustomDataRelationList* Relations = {read=GetRelations};
	__property int RowCount = {read=GetRowCount, nodefault};
	__property TcxDataControllerRowFixedState RowFixedState[int ARowIndex] = {read=GetRowFixedState, write=SetRowFixedState};
	__property TcxDataControllerSearch* Search = {read=FSearch};
	__property TcxDataSummary* Summary = {read=FSummary, write=SetSummary};
	__property bool UseNewItemRowForEditing = {read=FUseNewItemRowForEditing, write=SetUseNewItemRowForEditing, nodefault};
	__property System::Variant Values[int RecordIndex][int ItemIndex] = {read=GetValue, write=SetValue};
	__property int SortingBySummaryDataItemIndex = {read=GetSortingBySummaryDataItemIndex, write=SetSortingBySummaryDataItemIndex, nodefault};
	__property TcxDataControllerNotifyEvent OnAfterCancel = {read=FOnAfterCancel, write=FOnAfterCancel};
	__property TcxDataControllerNotifyEvent OnAfterDelete = {read=FOnAfterDelete, write=FOnAfterDelete};
	__property TcxDataControllerNotifyEvent OnAfterInsert = {read=FOnAfterInsert, write=FOnAfterInsert};
	__property TcxDataControllerNotifyEvent OnAfterPost = {read=FOnAfterPost, write=FOnAfterPost};
	__property TcxDataControllerNotifyEvent OnBeforeCancel = {read=FOnBeforeCancel, write=FOnBeforeCancel};
	__property TcxDataRecordNotifyEvent OnBeforeDelete = {read=FOnBeforeDelete, write=FOnBeforeDelete};
	__property TcxDataControllerNotifyEvent OnBeforeImmediatePost = {read=FOnBeforeImmediatePost, write=FOnBeforeImmediatePost};
	__property TcxDataControllerNotifyEvent OnBeforeInsert = {read=FOnBeforeInsert, write=FOnBeforeInsert};
	__property TcxDataControllerNotifyEvent OnBeforePost = {read=FOnBeforePost, write=FOnBeforePost};
	__property TcxDataFilterRecordEvent OnFilterRecord = {read=FOnFilterRecord, write=SetOnFilterRecord};
	__property TcxDataRecordNotifyEvent OnNewRecord = {read=FOnNewRecord, write=FOnNewRecord};
	__property TcxDataControllerCompareEvent OnCompare = {read=FOnCompare, write=FOnCompare};
	__property System::Classes::TNotifyEvent OnDataChanged = {read=FOnDataChanged, write=FOnDataChanged};
	__property TcxDataRecordAllowOperationEvent OnDetailCollapsing = {read=FOnDetailCollapsing, write=FOnDetailCollapsing};
	__property TcxDataRecordNotifyEvent OnDetailCollapsed = {read=FOnDetailCollapsed, write=FOnDetailCollapsed};
	__property TcxDataRecordAllowOperationEvent OnDetailExpanding = {read=FOnDetailExpanding, write=FOnDetailExpanding};
	__property TcxDataRecordNotifyEvent OnDetailExpanded = {read=FOnDetailExpanded, write=FOnDetailExpanded};
	__property TcxDataFindCriteriaBeforeChangeEvent OnFindCriteriaBeforeChange = {read=GetOnFindCriteriaBeforeChange, write=SetOnFindCriteriaBeforeChange};
	__property TcxDataFindCriteriaChangedEvent OnFindCriteriaChanged = {read=GetOnFindCriteriaChanged, write=SetOnFindCriteriaChanged};
	__property System::Classes::TNotifyEvent OnGroupingChanged = {read=FOnGroupingChanged, write=FOnGroupingChanged};
	__property TcxDataRecordChangedEvent OnRecordChanged = {read=FOnRecordChanged, write=FOnRecordChanged};
	__property System::Classes::TNotifyEvent OnSortingChanged = {read=FOnSortingChanged, write=FOnSortingChanged};
	__property TcxUpdateControlEvent OnUpdateControl = {read=FOnUpdateControl, write=FOnUpdateControl};
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


typedef System::TMetaClass* TcxCustomDataControllerClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomDataHelper : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod Cxdatastorage::TcxValueDef* __fastcall GetValueDef(TcxCustomDataField* AField)/* overload */;
	__classmethod Cxdatastorage::TcxValueDef* __fastcall GetValueDef(TcxCustomDataController* ADataController, int AIndex)/* overload */;
	__classmethod void __fastcall SetTextStored(TcxCustomDataField* AField, bool ATextStored);
public:
	/* TObject.Create */ inline __fastcall TcxCustomDataHelper() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomDataHelper() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE bool dxDefaultMultiThreadedFiltering;
extern DELPHI_PACKAGE bool dxDefaultMultiThreadedSorting;
static const int cxNullEditingRecordIndex = int(-2147483647);
extern DELPHI_PACKAGE System::Byte cxDataFilterVersion;
extern DELPHI_PACKAGE void __fastcall InvalidOperation(const System::UnicodeString S);
extern DELPHI_PACKAGE System::UnicodeString __fastcall cxDataGetDataSummaryValueDefaultFormat(TcxSummaryValueType AValueType, TcxSummaryKind ASummaryKind, bool AIsFooter);
}	/* namespace Cxcustomdata */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXCUSTOMDATA)
using namespace Cxcustomdata;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxcustomdataHPP
