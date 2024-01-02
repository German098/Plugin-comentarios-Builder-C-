//---------------------------------------------------------------------------

#ifndef FileH
#define FileH
//---------------------------------------------------------------------------

#include <toolsAPI.hpp>

class File : public IOTAFile {
	private:
		long ref_count;
		System::UnicodeString source;
	protected:
        // IInterface
        virtual HRESULT __stdcall QueryInterface(const GUID& iid, void** obj);
		virtual ULONG __stdcall AddRef();
		virtual ULONG __stdcall Release();

        virtual System::UnicodeString __fastcall GetSource();
		virtual System::TDateTime __fastcall GetAge();
	public:
		__fastcall File(const System::UnicodeString source);
		virtual __fastcall ~File();
};

#endif
