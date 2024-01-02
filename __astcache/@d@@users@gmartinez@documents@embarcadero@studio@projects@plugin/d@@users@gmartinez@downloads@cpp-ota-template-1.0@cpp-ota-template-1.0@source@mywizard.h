//---------------------------------------------------------------------------

#ifndef MyWizardH
#define MyWizardH
//---------------------------------------------------------------------------
#include "CPPOTANotifier.h"

class PACKAGE MyWizard : public CPPOTANotifier, public IOTAMenuWizard {
	typedef CPPOTANotifier inherited;
	private:
		int imageIndex;
		TAction *action;
		TMenuItem *menu_item;
	protected:
		// IOTAWizard
		virtual System::UnicodeString __fastcall GetIDString();
		virtual System::UnicodeString __fastcall GetName();
		virtual TWizardState __fastcall GetState();
		virtual void __fastcall Execute();
		// IOTAMenuWizard
		virtual System::UnicodeString __fastcall GetMenuText();
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
		__fastcall MyWizard();
		__fastcall ~MyWizard();

		int GetImageIndex() const { return imageIndex; }
		TAction* GetAction() { return action; }
		TMenuItem* GetMenuItem() { return menu_item; }
		System::UnicodeString GetCaption() { return GetMenuText(); }
        void __fastcall OnExecuteAction(System::TObject *Sender);
		void action_execute();
		//void action_update();
        void remove_action(TAction *action, TToolBar* toolbar);
};

#endif
