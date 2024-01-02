//---------------------------------------------------------------------------

#pragma hdrstop

#include "File.h"
#include "CPPOTATemplateMacros.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

__fastcall File::File(const System::UnicodeString source) : ref_count(0), source(source) {

}

__fastcall File::~File() {

}

// IOTAFile
System::UnicodeString __fastcall File::GetSource() {
	return source;
}

System::TDateTime __fastcall File::GetAge() {
	return -1;
}

// IInterface
HRESULT __stdcall File::QueryInterface(const GUID& iid, void** obj) {
	if (iid == __uuidof(IOTAFile)) {
		*obj = static_cast<IOTAFile*>(this);
		static_cast<IOTAFile*>(*obj)->AddRef();
		return S_OK;
	}

	return QueryInterface(iid, obj);
}

ULONG __stdcall File::AddRef() {
	return InterlockedIncrement(&ref_count);
}

ULONG __stdcall File::Release() {
	ULONG result = InterlockedDecrement(&ref_count);
	if (ref_count == 0)
		delete this;
	return result;
}
