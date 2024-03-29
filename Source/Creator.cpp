//---------------------------------------------------------------------------

#pragma hdrstop

#include "Creator.h"
#include "Header.h"
#include "File.h"
#include <Lmcons.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)

__fastcall Creator::~Creator() {

}

 // IOTACreator
 System::UnicodeString __fastcall Creator::GetCreatorType() {
    return sUnit;
 }

 bool __fastcall Creator::GetExisting() {
    return false;
 }

 System::UnicodeString __fastcall Creator::GetFileSystem() {
    return "";
 }

 _di_IOTAModule __fastcall Creator::GetOwner() {
	_di_IOTAProject result = 0;
	_di_IOTAModuleServices svc = interface_cast<IOTAModuleServices>(BorlandIDEServices);

	for(int i = 0; i < svc->GetModuleCount(); i++) {
		_di_IOTAModule module = svc->Modules[i];
		_di_IOTAProject project;
		_di_IOTAProjectGroup group;

		if(module->Supports(project)) {
			if(!result)
				result = project;
		}
		else if(module->Supports(group)) {
			result = group->ActiveProject;
            break;
		}
	}

    return result;
 }

 bool __fastcall Creator::GetUnnamed() {
	return true;
 }

 // IOTAModuleCreator
 System::UnicodeString __fastcall Creator::GetAncestorName() {
    return "";
 }

 System::UnicodeString __fastcall Creator::GetImplFileName() {
	return "";
 }

 System::UnicodeString __fastcall Creator::GetIntfFileName() {
	return "";
 }

 System::UnicodeString __fastcall Creator::GetFormName() {
    return "";
 }

 bool __fastcall Creator::GetMainForm() {
	return true;
 }

 bool __fastcall Creator::GetShowForm() {
    return true;
 }

 bool __fastcall Creator::GetShowSource() {
    return true;
 }

 _di_IOTAFile __fastcall Creator::NewFormFile(const System::UnicodeString FormIdent, const System::UnicodeString AncestorIdent) {
    return 0;
 }

 _di_IOTAFile __fastcall Creator::NewImplSource(const System::UnicodeString ModuleIdent, const System::UnicodeString FormIdent, const System::UnicodeString AncestorIdent) {
	System::UnicodeString file, author, date;

    file = "Nombre_fichero";

    DWORD username_len = UNLEN + 1;
	char username[UNLEN + 1];
	GetUserNameA(username, &username_len);
	author = username;

    std::time_t time = std::time(0);
	date = std::ctime(&time);

	return new File(header_comment(file, author, date));
 }

 _di_IOTAFile __fastcall Creator::NewIntfSource(const System::UnicodeString ModuleIdent, const System::UnicodeString FormIdent, const System::UnicodeString AncestorIdent) {
    return 0;
 }

 void __fastcall Creator::FormCreated(const _di_IOTAFormEditor FormEditor) {

 }

 // IInterface
HRESULT __stdcall Creator::QueryInterface(const GUID& iid, void** obj) {
  //QUERY_INTERFACE(IOTAModuleCreator, iid, obj);
  //QUERY_INTERFACE(IOTACreator, iid, obj);

	if (iid == __uuidof(IOTAActionServices)) {
		*obj = static_cast<IOTAModuleCreator*>(this);
		static_cast<IOTAActionServices*>(*obj)->AddRef();
		return S_OK;
	}

	if (iid == __uuidof(IOTACreator)) {
		*obj = static_cast<IOTACreator*>(this);
		static_cast<IOTACreator*>(*obj)->AddRef();
		return S_OK;
	}

  return E_NOINTERFACE;
}

ULONG __stdcall Creator::AddRef() {
	return InterlockedIncrement(&ref_count);
}

ULONG __stdcall Creator::Release() {
    ULONG result = InterlockedDecrement(&ref_count);
	if (ref_count == 0)
		delete this;
	return result;
}
