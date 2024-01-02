//---------------------------------------------------------------------------

#pragma hdrstop

#include "DocWizard.h"
#include "ModuleNotifier.h"
#include "Creator.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


__fastcall DocWizard::DocWizard(_di_IOTAModule module, System::UnicodeString creator_type) : module(module), creator_type(creator_type) {
	list = new TInterfaceList();
}

__fastcall DocWizard::~DocWizard() {
	for(int i = list->Count - 1; i >= 0; i--) {
		_di_IOTANotifier notifier;

		_di_IInterface x = list->Last();
		if(list->Last()->Supports(notifier)){
			notifier->Destroyed();
			list->Delete(i);
		}

	}

    delete list;
}

// IOTAWizard
System::UnicodeString __fastcall DocWizard::GetIDString() {
	return "ID DocWizard";
}

System::UnicodeString __fastcall DocWizard::GetName() {
    return "DocWizard Name";
}

TWizardState __fastcall DocWizard::GetState() {
    TWizardState result;
	result << wsEnabled;
    return result;
}

void __fastcall DocWizard::Execute() {
	_di_IOTAModuleServices svc;

	if(BorlandIDEServices->Supports(svc)) {
		_di_IOTAModule module = svc->CreateModule(new Creator(creator_type));
		_di_IOTAModuleNotifier notifier = new ModuleNotifier(module);
		if(!notifier){
            int aaa = 0;
		}
        list->Add(notifier);
	}
}

// IOTAMenuWizard
System::UnicodeString __fastcall DocWizard::GetMenuText() {
    return "DocWizard Menu";
}

// IInterface
ULONG __stdcall DocWizard::AddRef() {
  return inherited::AddRef();
}
ULONG __stdcall DocWizard::Release() {
  return inherited::Release();
}
HRESULT __stdcall DocWizard::QueryInterface(const GUID& iid, void** obj) {
  //QUERY_INTERFACE(IOTAMenuWizard, iid, obj);
  //QUERY_INTERFACE(IOTAWizard, iid, obj);
  if (iid == __uuidof(IOTAMenuWizard)) {
*obj = static_cast<IOTAMenuWizard*>(this);
static_cast<IOTAMenuWizard*>(*obj)->AddRef();
return S_OK;
}
if (iid == __uuidof(IOTAWizard)) {
*obj = static_cast<IOTAWizard*>(this);
static_cast<IOTAWizard*>(*obj)->AddRef();
return S_OK;
}
  return inherited::QueryInterface(iid, obj);
}

// IOTANotifier
void __fastcall DocWizard::AfterSave() {}

void __fastcall DocWizard::BeforeSave() {}

void __fastcall DocWizard::Destroyed() {}

void __fastcall DocWizard::Modified() {}

