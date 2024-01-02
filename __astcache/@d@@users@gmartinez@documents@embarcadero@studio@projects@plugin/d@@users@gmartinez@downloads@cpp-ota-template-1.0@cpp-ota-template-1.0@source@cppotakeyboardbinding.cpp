#pragma hdrstop
#include <CPPOTATemplateMainWizard.h>
#include <Dialogs.hpp>
#include <CPPOTAKeyBoardBinding.h>
#include "CPPOTATemplateMacros.h"
#pragma package(smart_init)

/* TKeyboardBinding implementation */
__fastcall TCPPOTAKeyBoardBinding::TCPPOTAKeyBoardBinding() :
  TDGHNotifierObject("") {
  std::cout<<"HOLA..."<<std::endl;
}

__fastcall TCPPOTAKeyBoardBinding::TCPPOTAKeyBoardBinding(String strObjectName) : TDGHNotifierObject(strObjectName) {
  std::cout<<"HOLA"<<std::endl;
}

__fastcall TCPPOTAKeyBoardBinding::~TCPPOTAKeyBoardBinding() {

}

void __fastcall TCPPOTAKeyBoardBinding::BeforeSave() {
  inherited::BeforeSave();
}

void __fastcall TCPPOTAKeyBoardBinding::AfterSave() {
  inherited::AfterSave();
}

void __fastcall TCPPOTAKeyBoardBinding::Destroyed() {
  inherited::Destroyed();
}

void __fastcall TCPPOTAKeyBoardBinding::Modified() {
  inherited::Modified();
}

TBindingType __fastcall TCPPOTAKeyBoardBinding::GetBindingType() {
    return btPartial;
}

UnicodeString __fastcall TCPPOTAKeyBoardBinding::GetDisplayName(){
	return "Debugging Tools Bindings";
}

UnicodeString __fastcall TCPPOTAKeyBoardBinding::GetName() {
	return "DebuggingToolsBindings";
}

ULONG __stdcall TCPPOTAKeyBoardBinding::AddRef() {
  return inherited::AddRef();
}
ULONG __stdcall TCPPOTAKeyBoardBinding::Release() {
  return inherited::Release();
}

HRESULT __stdcall TCPPOTAKeyBoardBinding::QueryInterface(const GUID& iid, void** obj) {
  QUERY_INTERFACE(IOTAKeyboardBinding, iid, obj);
  //QUERY_INTERFACE(IOTAWizard, iid, obj);
  return inherited::QueryInterface(iid, obj);
}

void __fastcall TCPPOTAKeyBoardBinding::BindKeyboard(const _di_IOTAKeyboardServices BindingServices) {
	TShortCut *keys = new TShortCut(TextToShortCut("Ctrl+Alt+W"));
	//_di_IOTAKeyContext c;
	//TKeyBindingRec BindingRec;
	//c->GetKeyBindingRec(BindingRec);
	_di_IOTAKeyboardBinding KeyBinding;
	// AQUI
	//if(BorlandIDEServices->Supports(BindingServices)){
		//BindingServices->AddKeyBinding(keys, 0, BindingRec.KeyProc, &executeWizard);
		//BindingServices->AddKeyboardBinding();
	//}
}

void __fastcall TCPPOTAKeyBoardBinding::executeWizard() {
	//DoNotification("... Hello Daveeeeee!");
	MessageDlg("Hello Dave... How are you... executeWizard", mtInformation, TMsgDlgButtons() << mbOK, 0);
}

TCPPOTAKeyBoardBinding* __fastcall AddKeyBoardBinding() {
	_di_IOTAKeyboardServices IOTAKeyboardBinding;

	if (BorlandIDEServices->Supports(IOTAKeyboardBinding)) {
		//TCPPOTAKeyBoardBinding *keyboardBinding = new TCPPOTAKeyBoardBinding("TKeyboardBinding");
		//IOTAKeyboardBinding->AddKeyboardBinding(keyboardBinding);

		//return keyboardBinding;
	}

    return NULL;
}

void __fastcall RemoveKeyboardBinding(TCPPOTAKeyBoardBinding *keyBoradBinding) {
	
}
