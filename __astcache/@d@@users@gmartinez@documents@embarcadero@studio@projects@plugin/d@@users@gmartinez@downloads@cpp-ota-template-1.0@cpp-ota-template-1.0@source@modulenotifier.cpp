//---------------------------------------------------------------------------

#pragma hdrstop

#include "ModuleNotifier.h"
#include "CPPOTAMacroUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

__fastcall ModuleNotifier::ModuleNotifier(const _di_IOTAModule module) : index(-1), module(module) {
	index = module->AddNotifier(this);
	name = ChangeFileExt(ExtractFileName(module->FileName), "");
}

__fastcall ModuleNotifier::~ModuleNotifier() {
	if(index >= 0)
        module->RemoveNotifier(index);
}

// IOTAModuleNotifier
bool __fastcall ModuleNotifier::CheckOverwrite() {
    return true;
}

void __fastcall ModuleNotifier::ModuleRenamed(const System::UnicodeString NewName) {
	System::UnicodeString module_name = ChangeFileExt(ExtractFileName(NewName), "");

	for(int i = 0; i < module->GetModuleFileCount(); i++){
		_di_IOTAEditor editor = module->GetModuleFileEditor(i);
		_di_IOTAEditBuffer buffer;

		if(editor->Supports(buffer)){
			_di_IOTAEditPosition pos = buffer->GetEditPosition();
			//pos->Move(2, 1);
			//pos->MoveCursor(mmSkipWhite | mmSkipRight);
			//System::UnicodeString check = pos->RipText("", rfIncludeNumericChars | rfIncludeAlphaChars);
			pos->Move(1, 1);
			pos->MoveCursor(mmSkipWord);
			System::UnicodeString check = pos->RipText("", rfIncludeAlphaChars);

			if(check == name){
				pos->Delete(check.Length());
				pos->InsertText(module_name);
                name = module_name;
			}
		}
	}
}

// IOTANotifier
void __fastcall ModuleNotifier::AfterSave() {
    int cc = 0;
}

void __fastcall ModuleNotifier::BeforeSave() {
    int a = 11;
}

void __fastcall ModuleNotifier::Destroyed() {
    if(index >= 0){
		module->RemoveNotifier(index);
        index = -1;
	}

    module = 0;
}

void __fastcall ModuleNotifier::Modified() {}

// IInterface
HRESULT __stdcall ModuleNotifier::QueryInterface(const GUID& iid, void** obj) {
	//QUERY_INTERFACE(IInterface, iid, obj);
	//QUERY_INTERFACE(IOTANotifier, iid, obj);
	QUERY_INTERFACE(IOTAModuleNotifier, iid, obj);


  	return inherited::QueryInterface(iid, obj);	 //E_NOINTERFACE;
}

ULONG __stdcall ModuleNotifier::AddRef() {
	//return InterlockedIncrement(&ref_count);
    return inherited::AddRef();
}

ULONG __stdcall ModuleNotifier::Release() {
	/*ULONG result = InterlockedDecrement(&ref_count);
	if (ref_count == 0)
		delete this;
	return result;*/
    return inherited::Release();
}
