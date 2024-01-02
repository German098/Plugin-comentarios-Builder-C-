/**
  This module contains a class that implements the IOTAWizard and IOTAMenuWizard interfaces
  to provide a main wizard interfaces for this OTA project which installs and Open Tools
  API wizard / expert / plug-in into the RAD Studio IDE.
  This clas manages ALL objects created and used by this application.
  @Author  David Hoyle
  @Version 1.0
  @date    17 Dec 2016
**/
#ifndef CPPOTAKeyBoardBindingH
#define CPPOTAKeyBoardBindingH

#include <CPPOTATemplateNotifierObject.h>

class PACKAGE TCPPOTAKeyBoardBinding : public TDGHNotifierObject, public IOTAKeyboardBinding {
	typedef TDGHNotifierObject inherited;
	//typedef void (__closure *ptr)();
	private:
		static void __fastcall executeWizard();
	protected:
		// IOTAKeyboardBinding
		virtual TBindingType __fastcall GetBindingType();
		virtual UnicodeString __fastcall GetDisplayName();
		virtual UnicodeString __fastcall GetName();
		virtual void __fastcall BindKeyboard(const _di_IOTAKeyboardServices BindingServices);
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
		__fastcall TCPPOTAKeyBoardBinding();
		__fastcall TCPPOTAKeyBoardBinding(String strObjectName);
		__fastcall ~TCPPOTAKeyBoardBinding();
};

TCPPOTAKeyBoardBinding* __fastcall AddKeyBoardBinding();
void __fastcall RemoveKeyboardBinding(TCPPOTAKeyBoardBinding *keyBoradBinding);

#endif
