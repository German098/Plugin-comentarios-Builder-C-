//---------------------------------------------------------------------------

#ifndef HeaderWizardH
#define HeaderWizardH
//---------------------------------------------------------------------------

#include "CPPOTANotifier.h"

class PACKAGE HeaderWizard : public CPPOTANotifier, public IOTAWizard/*IOTAMenuWizard*/ {
	typedef CPPOTANotifier inherited;
	private:
		_di_IOTAModule module;
		TInterfaceList *list;

	protected:
		// IOTAWizard
		virtual System::UnicodeString __fastcall GetIDString();
		virtual System::UnicodeString __fastcall GetName();
		virtual TWizardState __fastcall GetState();
		virtual void __fastcall Execute();
		// IOTAMenuWizard
		//virtual System::UnicodeString __fastcall GetMenuText();
		// IOTANotifier
		virtual void __fastcall AfterSave();
		virtual void __fastcall BeforeSave();
		virtual void __fastcall Destroyed();
		virtual void __fastcall Modified();
		// IInterface
        virtual HRESULT __stdcall QueryInterface(const GUID& iid, void** obj);
		virtual ULONG __stdcall AddRef();
		virtual ULONG __stdcall Release();
	public:
		__fastcall HeaderWizard(_di_IOTAModule module);
		__fastcall ~HeaderWizard();
};

#endif
