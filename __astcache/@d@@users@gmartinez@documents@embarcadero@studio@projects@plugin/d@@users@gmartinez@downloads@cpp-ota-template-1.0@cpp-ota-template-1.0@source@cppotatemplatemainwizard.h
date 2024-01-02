/**
  This module contains a class that implements the IOTAWizard and IOTAMenuWizard interfaces
  to provide a main wizard interfaces for this OTA project which installs and Open Tools
  API wizard / expert / plug-in into the RAD Studio IDE.
  This clas manages ALL objects created and used by this application.
  @Author  David Hoyle
  @Version 1.0
  @date    17 Dec 2016
**/
#ifndef CPPOTATemplateMainWizardH
#define CPPOTATemplateMainWizardH
#include <ToolsAPI.hpp>
#include <CPPOTATemplateNotifierObject.h>
//#include "CPPOTATemplateAppOptions.h"
#include <CPPOTATemplateIDENotifier.h>
//#include "CPPOTATemplateAddinOptions.h"
//#include "CPPOTAKeyBoardBinding.h"
#include <ExtCtrls.hpp>

/*
	{ krUnhandled, krHandled, krNextProc }
	* Establece el parámetro formal BindingResult del método TKeyBindingProc a krHandled si el método ha ejecutado correctamente su comportamiento.
	Establecer BindingResult a krHandled también tiene el efecto de evitar que cualquier otra combinación de teclas procese la tecla, así como
	evitar que los elementos de menú asignados a la combinación de teclas la procesen.

	* Establece BindingResult como krUnhandled si no procesa la pulsación o combinación de teclas. Si establece BindingResult a krUnhandled, el
	editor permitirá que cualquier otra combinación de teclas asignada a la pulsación o combinación de teclas la procese, así como cualquier
	elemento de menú asociado a la combinación de teclas.

	* Establezca BindingResult a krNextProc si ha manipulado la tecla, pero desea permitir que cualquier otra combinación de teclas asociada a la
	pulsación o combinación de teclas también se active. De forma similar a establecer BindingResult a krHandled, establecer BindingResult a
	krNextProc tendrá el efecto de evitar que los atajos de menú reciban la pulsación o combinación de teclas.
*/

class PACKAGE TKeyboardBinding : public TDGHNotifierObject, public IOTAKeyboardBinding  {
	typedef TDGHNotifierObject inherited;
	private:
		TShortCut *keys;
		//static void __fastcall addCommentary( );
        void __fastcall addCommentary( const _di_IOTAKeyContext Context, System::Classes::TShortCut KeyCode, TKeyBindingResult &BindingResult );
	protected:
		// IOTAKeyboardBinding
		virtual TBindingType __fastcall GetBindingType();
		virtual System::UnicodeString __fastcall GetDisplayName();
		virtual System::UnicodeString __fastcall GetName();
		virtual void __fastcall BindKeyboard(const _di_IOTAKeyBindingServices BindingServices);
		// IOTANotifer
		void __fastcall BeforeSave();
		void __fastcall AfterSave();
		void __fastcall Destroyed();
		void __fastcall Modified();
		// IInterface
		virtual HRESULT __stdcall QueryInterface(const GUID& iid, void** obj);
		virtual ULONG __stdcall AddRef();
		virtual ULONG __stdcall Release();
	public:
		__fastcall TKeyboardBinding(TShortCut *keys);
		__fastcall ~TKeyboardBinding();

		//TShortCut* __fastcall setKeys(TShortCut *keys) { this->keys = keys; }
};

TKeyboardBinding* __fastcall AddKeyBoardBindingObject();
//void __fastcall RemoveKeyboardBinding(TCPPOTAKeyBoardBinding *keyBoradBinding);

class PACKAGE TCPPOTATemplateWizard : public TDGHNotifierObject,/* public IOTAMenuWizard*/ public IOTAWizard {
  typedef TDGHNotifierObject inherited;
  private:
	//int FAboutBoxPlugin;
	int FIDENotifier;
	//TCPPOTATemplateOptions* FAppOptions;
	//TTimer* FAutoSaveTimer;
	//int FTimerCounter;
	//TCPPOTATemplateAddInOptions* FIDEOptions;
	TKeyboardBinding *KeyBoradBinding;
	int FPointNotifier;
  protected:
    // IOTAWizard
    virtual UnicodeString __fastcall GetIDString();
    virtual UnicodeString __fastcall GetName();
    virtual TWizardState  __fastcall GetState();
    virtual void __fastcall Execute();
    // IOTAMenuWizard
    //virtual UnicodeString __fastcall GetMenuText();
    // IOTANotifer
    void __fastcall BeforeSave();
    void __fastcall AfterSave();
    void __fastcall Destroyed();
    void __fastcall Modified();
    // IInterface
    virtual HRESULT __stdcall QueryInterface(const GUID& iid, void** obj);
    virtual ULONG __stdcall AddRef();
    virtual ULONG __stdcall Release();
    // Non-interface methods
	//void __fastcall AutoSaveTimerEvent(TObject* Sender);
	//void __fastcall SaveModifiedFiles();
  public:
    __fastcall TCPPOTATemplateWizard(String strObjectName);
    __fastcall ~TCPPOTATemplateWizard();
};

#endif
