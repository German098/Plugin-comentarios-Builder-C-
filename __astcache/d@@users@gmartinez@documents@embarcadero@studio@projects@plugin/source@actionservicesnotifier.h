﻿//---------------------------------------------------------------------------

#ifndef ActionServicesNotifierH
#define ActionServicesNotifierH

#include "CPPOTATemplateNotifierObject.h"

class ActionServicesNotifier : public TDGHNotifierObject, public IOTAActionServices {
	typedef TDGHNotifierObject inherited;

	private:
		System::UnicodeString strObjectName;
		//int index;

	protected:
		// IOTANotifier
		void __fastcall AfterSave();
		void __fastcall BeforeSave();
		void __fastcall Destroyed();
		void __fastcall Modified();

        // IOTAActionServices
		virtual bool __fastcall CloseFile(const System::UnicodeString FileName);
		virtual bool __fastcall OpenFile(const System::UnicodeString FileName);
		virtual bool __fastcall OpenProject(const System::UnicodeString ProjName, bool NewProjGroup);
		virtual bool __fastcall ReloadFile(const System::UnicodeString FileName);
		virtual bool __fastcall SaveFile(const System::UnicodeString FileName);

        // IInterface
		virtual HRESULT __stdcall QueryInterface(const GUID&, void**);
		virtual ULONG __stdcall AddRef();
		virtual ULONG __stdcall Release();

	public:
		__fastcall ActionServicesNotifier(System::UnicodeString strObjectName);
		virtual __fastcall ~ActionServicesNotifier();
};

int __fastcall AddActionServicesNotifier();
void __fastcall RemoveActionServicesNotifier(int iIDENotifierIndex);

#endif

