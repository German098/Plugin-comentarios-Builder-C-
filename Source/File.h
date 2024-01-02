//---------------------------------------------------------------------------

#ifndef FileH
#define FileH

#include <ToolsAPI.hpp>

class File : public IOTAFile {
	typedef IOTAFile inherited;
	private:
		long ref_count;
		System::UnicodeString source;

	protected:
		// IOTAFile
		virtual System::UnicodeString __fastcall GetSource();
		virtual System::TDateTime __fastcall GetAge();
		// IInterface
		virtual HRESULT __stdcall QueryInterface(const GUID&, void**);
		virtual ULONG __stdcall AddRef();
		virtual ULONG __stdcall Release();

	public:
		__fastcall File(const System::UnicodeString source);
		virtual __fastcall ~File();
};

#endif
