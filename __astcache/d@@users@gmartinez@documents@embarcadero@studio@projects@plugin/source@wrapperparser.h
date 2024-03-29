﻿//---------------------------------------------------------------------------

#ifndef WrapperParserH
#define WrapperParserH

#include "WrapperParserDebug.h"
//---------------------------------------------------------------------------
#endif

extern "C" {

#if COMPILING_DLL
#define INESCOPIMPORT extern "C" __declspec( dllexport )
#else
#define INESCOPIMPORT extern "C" __declspec( dllimport )
#endif

	INESCOPIMPORT int __stdcall parseString( char *str, unsigned int str_size, char *&rstr, unsigned int &rsre_size, bool &codeInComment /*std::string str, std::string& rstr*/ );
}

