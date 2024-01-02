﻿//---------------------------------------------------------------------------

#pragma hdrstop

#include "ActionServicesNotifier.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

int __fastcall AddActionServicesNotifier() {
  _di_IOTAServices IDEServices;
  if (BorlandIDEServices->Supports(IDEServices)) {
	//return IDEServices->AddNotifier(new ActionServicesNotifier("ActionServicesNotifier"));
  }
  return -1;
}

void __fastcall RemoveActionServicesNotifier(int iIDENotifierIndex) {
  _di_IOTAServices IDEServices;
  if (BorlandIDEServices->Supports(IDEServices)) {
	if (iIDENotifierIndex > -1) {
	  IDEServices->RemoveNotifier(iIDENotifierIndex);
	}
  }
}

__fastcall ActionServicesNotifier::ActionServicesNotifier(System::UnicodeString strObjectName) : strObjectName(strObjectName) {
	//index = module->AddNotifier(this);
	//name = ChangeFileExt(ExtractFileName(module->FileName), "");
}

__fastcall ActionServicesNotifier::~ActionServicesNotifier() {
	//if(index >= 0)
    //    module->RemoveNotifier(index);
}

// IOTAActionServices
bool __fastcall ActionServicesNotifier::CloseFile(const System::UnicodeString FileName) {
    return true;
}

bool __fastcall ActionServicesNotifier::OpenFile(const System::UnicodeString FileName) {
	return true;
}

bool __fastcall ActionServicesNotifier::OpenProject(const System::UnicodeString ProjName, bool NewProjGroup) {
	return true;
}

bool __fastcall ActionServicesNotifier::ReloadFile(const System::UnicodeString FileName) {
	return true;
}

bool __fastcall ActionServicesNotifier::SaveFile(const System::UnicodeString FileName) {
DoNotification("Guardar");
  MessageDlg("Hello Dave... How are you...", mtInformation, TMsgDlgButtons() << mbOK, 0);
	return true;
}

// IOTANotifier

void __fastcall ActionServicesNotifier::AfterSave() {

}

void __fastcall ActionServicesNotifier::BeforeSave() {

}

void __fastcall ActionServicesNotifier::Destroyed() {
	/*if(index >= 0) {
		module->RemoveNotifier(index);
		index = -1;
	}

    module = 0;        */
}

void __fastcall ActionServicesNotifier::Modified() {

}

// IInterface

HRESULT __stdcall ActionServicesNotifier::QueryInterface(const GUID& iid, void** obj) {
  //QUERY_INTERFACE(IOTAModuleNotifier, iid, obj);
  if ((iid) == __uuidof(IOTAActionServices)) {
	*(obj) = static_cast<IOTAActionServices*>(this);
	static_cast<IOTAActionServices*>(*(obj))->AddRef();
	return S_OK;
  }

  return inherited::QueryInterface(iid, obj);
}

ULONG __stdcall ActionServicesNotifier::AddRef() {
	return inherited::AddRef();
}

ULONG __stdcall ActionServicesNotifier::Release() {
	return inherited::Release();
}