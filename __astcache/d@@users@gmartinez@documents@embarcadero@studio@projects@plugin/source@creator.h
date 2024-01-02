//---------------------------------------------------------------------------

#ifndef CreatorH
#define CreatorH

#include <ToolsAPI.hpp>

class PACKAGE Creator : public IOTAModuleCreator {
	private:
		long ref_count;
		const System::UnicodeString creator_type;

	protected:
        // IOTACreator
		virtual System::UnicodeString __fastcall GetCreatorType();
		virtual bool __fastcall GetExisting();
		virtual System::UnicodeString __fastcall GetFileSystem();
		virtual _di_IOTAModule __fastcall GetOwner();
		virtual bool __fastcall GetUnnamed();

		// IOTAModuleCreator
		virtual System::UnicodeString __fastcall GetAncestorName();
		virtual System::UnicodeString __fastcall GetImplFileName();
		virtual System::UnicodeString __fastcall GetIntfFileName();
		virtual System::UnicodeString __fastcall GetFormName();
		virtual bool __fastcall GetMainForm();
		virtual bool __fastcall GetShowForm();
		virtual bool __fastcall GetShowSource();
		virtual _di_IOTAFile __fastcall NewFormFile(const System::UnicodeString FormIdent, const System::UnicodeString AncestorIdent);
		virtual _di_IOTAFile __fastcall NewImplSource(const System::UnicodeString ModuleIdent, const System::UnicodeString FormIdent, const System::UnicodeString AncestorIdent);
		virtual _di_IOTAFile __fastcall NewIntfSource(const System::UnicodeString ModuleIdent, const System::UnicodeString FormIdent, const System::UnicodeString AncestorIdent);
		virtual void __fastcall FormCreated(const _di_IOTAFormEditor FormEditor);

		// IInterface
		virtual HRESULT __stdcall QueryInterface(const GUID& iid, void** obj);
		virtual ULONG __stdcall AddRef();
		virtual ULONG __stdcall Release();

	public:
		__fastcall Creator(const System::UnicodeString creator_type) : ref_count(0), creator_type(creator_type) {}
		virtual __fastcall ~Creator();
};

#endif
