//---------------------------------------------------------------------------

#pragma hdrstop

#include "Header.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

System::UnicodeString __fastcall header_comment(System::UnicodeString file, System::UnicodeString author, System::UnicodeString date) {
	System::UnicodeString c = UnicodeString(h1.c_str() + file + h2.c_str() + author + h3.c_str() + date + h4.c_str());

    return c;
}
