// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxDataUtils.pas' rev: 35.00 (Windows)

#ifndef CxdatautilsHPP
#define CxdatautilsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.Windows.hpp>
#include <System.Variants.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>

//-- user supplied -----------------------------------------------------------

namespace Cxdatautils
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TcxCustomDataBinding;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TcxDataEditValueSource : unsigned char { evsValue, evsText, evsKey };

typedef void __fastcall (__closure *TcxDataBindingNotifyEvent)(void);

class PASCALIMPLEMENTATION TcxCustomDataBinding : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::Classes::TComponent* FDataComponent;
	System::Classes::TComponent* FOwner;
	bool FReadOnly;
	System::Classes::TComponent* FVisualControl;
	TcxDataBindingNotifyEvent FOnDataChange;
	TcxDataBindingNotifyEvent FOnDataSetChange;
	TcxDataBindingNotifyEvent FOnUpdateData;
	void __fastcall SetVisualControl(System::Classes::TComponent* Value);
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner();
	virtual void __fastcall DataChange();
	virtual void __fastcall DataSetChange();
	virtual bool __fastcall GetModified();
	virtual bool __fastcall GetReadOnly();
	virtual void __fastcall SetReadOnly(bool Value);
	virtual void __fastcall UpdateData();
	virtual void __fastcall VisualControlChanged();
	__property System::Classes::TComponent* DataComponent = {read=FDataComponent};
	
public:
	__fastcall virtual TcxCustomDataBinding(System::Classes::TComponent* AOwner, System::Classes::TComponent* ADataComponent);
	virtual bool __fastcall CanModify();
	virtual bool __fastcall ExecuteAction(System::Classes::TBasicAction* Action);
	virtual System::Variant __fastcall GetStoredValue(TcxDataEditValueSource AValueSource, bool AFocused);
	virtual bool __fastcall IsControlReadOnly();
	virtual bool __fastcall IsDataSourceLive();
	virtual bool __fastcall IsDataStorage();
	virtual void __fastcall Reset();
	virtual bool __fastcall SetEditMode();
	virtual void __fastcall SetStoredValue(TcxDataEditValueSource AValueSource, const System::Variant &Value);
	virtual bool __fastcall UpdateAction(System::Classes::TBasicAction* Action);
	virtual void __fastcall UpdateDataSource();
	__property bool Modified = {read=GetModified, nodefault};
	__property bool ReadOnly = {read=GetReadOnly, write=SetReadOnly, default=0};
	__property System::Classes::TComponent* VisualControl = {read=FVisualControl, write=SetVisualControl};
	__property TcxDataBindingNotifyEvent OnDataChange = {read=FOnDataChange, write=FOnDataChange};
	__property TcxDataBindingNotifyEvent OnDataSetChange = {read=FOnDataSetChange, write=FOnDataSetChange};
	__property TcxDataBindingNotifyEvent OnUpdateData = {read=FOnUpdateData, write=FOnUpdateData};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxCustomDataBinding() { }
	
};


typedef System::TMetaClass* TcxCustomDataBindingClass;

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE bool __fastcall DataCompareText(const System::UnicodeString S1, const System::UnicodeString S2, bool APartialCompare, bool AIsAnywhere = false, bool ACaseSensitive = false);
}	/* namespace Cxdatautils */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXDATAUTILS)
using namespace Cxdatautils;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxdatautilsHPP
