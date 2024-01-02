//---------------------------------------------------------------------------

#ifndef CPPOTANotifierH
#define CPPOTANotifierH
//---------------------------------------------------------------------------
#include <ToolsAPI.hpp>

class PACKAGE CPPOTANotifier : public IOTANotifier {
	private:
        long ref_count;
	public:
		__fastcall  CPPOTANotifier() : ref_count(0) { }
		virtual __fastcall ~CPPOTANotifier();
		// IOTANotifier
		void __fastcall AfterSave();
		void __fastcall BeforeSave();
		void __fastcall Destroyed();
		void __fastcall Modified();
	protected:
        // IInterface
		virtual HRESULT __stdcall QueryInterface(const GUID&, void**);
		virtual ULONG __stdcall AddRef();
		virtual ULONG __stdcall Release();

};

#endif
