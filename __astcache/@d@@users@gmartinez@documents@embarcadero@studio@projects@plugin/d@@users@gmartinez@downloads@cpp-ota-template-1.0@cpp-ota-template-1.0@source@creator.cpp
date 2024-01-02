//---------------------------------------------------------------------------

#pragma hdrstop

#include "Creator.h"
#include "File.h"
#include "CPPOTAMacroUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

__fastcall Creator::~Creator() {

}

// IOTAModuleCreator
System::UnicodeString __fastcall Creator::GetAncestorName() {

}

System::UnicodeString __fastcall Creator::GetImplFileName() {
    return L"";
}

System::UnicodeString __fastcall Creator::GetIntfFileName() {
    return L"";
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

_di_IOTAFile __fastcall Creator::NewImplSource(const System::UnicodeString ModuleIdent, const System::UnicodeString FormIdent,
	const System::UnicodeString AncestorIdent) {
	System::UnicodeString n = ModuleIdent + " | " + FormIdent + " | " + AncestorIdent;
	//const System::UnicodeString source =
	//    "/*-----------------------------------------------------------------\n"
	//	" %m - description\n"
	//	" Copyright © %y Your company, inc.\n"
	//	" Created on %d\n"
	//	" By %u\n"
	//	" ---------------------------------------------------------------*/\n"
	//	"\n"
	//	"#include <vcl.h>\n"
	//	"#pragma hdrstop\n"
	//	"\n"
	//	"#include \"%m.h\"\n"
	//	"//-----------------------------------------------------------------\n"
	//	"#pragma package(smart_init)\n"
	//	"#pragma resource \"*.dfm\"\n"
	//	"T%f *%f;\n"
	//	"//-----------------------------------------------------------------\n"
	//	"__fastcall T%m::T%m(TComponent* Owner)\n"
	//	" : T%a(Owner)\n"
	//	"{\n"
	//	"}\n"
	//	"//----------------------------------------------------------------\n";

	// Qué es expand?
	//return new File(expand(source, ModuleIdent, FormIdent, AncestorIdent));

	const System::UnicodeString source = creator_type + "\n" + ModuleIdent + FormIdent + AncestorIdent;

    return new File(source);
}

_di_IOTAFile __fastcall Creator::NewIntfSource(const System::UnicodeString ModuleIdent, const System::UnicodeString FormIdent,
	const System::UnicodeString AncestorIdent) {
	_di_IOTAFile file;

	return file;
}

void __fastcall Creator::FormCreated(const _di_IOTAFormEditor FormEditor) {

}

// IOTACreator
System::UnicodeString __fastcall Creator::GetCreatorType() {
	return creator_type;
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

	for(int i = 0; i < svc->ModuleCount; i++){
		_di_IOTAModule module = svc->Modules[i];
		_di_IOTAProject project;
		_di_IOTAProjectGroup group;

		if(module->Supports(project)) {
			if(result == 0)
				result = project;
		}
		else if(module->Supports(group)){
			result = group->ActiveProject;

            break;
		}
	}

    return result;
}

bool __fastcall Creator::GetUnnamed() {
	return true;
}

// IInterface
HRESULT __stdcall Creator::QueryInterface(const GUID& iid, void** obj) {
  QUERY_INTERFACE(IOTAModuleCreator, iid, obj);
  QUERY_INTERFACE(IOTACreator, iid, obj);

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

