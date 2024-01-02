//---------------------------------------------------------------------------

#ifndef ModuleNotifierH
#define ModuleNotifierH
//---------------------------------------------------------------------------

#include <toolsAPI.hpp>
#include "CPPOTANotifier.h"

class ModuleNotifier : public CPPOTANotifier, public IOTAModuleNotifier {
	typedef CPPOTANotifier inherited;
    private:
		_di_IOTAModule module;
		System::UnicodeString name;
        System::TDateTime date_time;
		int index;
	protected:
        // IInterface
		virtual HRESULT __stdcall QueryInterface(const GUID&, void**);
		virtual ULONG __stdcall AddRef();
		virtual ULONG __stdcall Release();
	public:
		__fastcall ModuleNotifier(const _di_IOTAModule module);
		__fastcall ~ModuleNotifier();

		// IOTAModuleNotifier
		virtual bool __fastcall CheckOverwrite();
		virtual void __fastcall ModuleRenamed(const System::UnicodeString NewName);

		// IOTANotifier
		virtual void __fastcall AfterSave();
		virtual void __fastcall BeforeSave();
		virtual void __fastcall Destroyed();
		virtual void __fastcall Modified();
};

#endif
