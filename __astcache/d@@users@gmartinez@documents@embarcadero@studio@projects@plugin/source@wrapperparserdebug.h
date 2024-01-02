#pragma once


#ifndef WrapperParserH

#define NOMINMAX
#include <windows.h>
#include <string>

#if COMPILING_DLL
	#define INESCOPEXPORT extern "C" __declspec(dllexport)
#else
	#define INESCOPEXPORT extern "C" __declspec(dllimport)
#endif

#define DEVCODE_LEN 39

unsigned char devCode[DEVCODE_LEN] = {0x01, 0x01, 0x01, 0x02, 0x04, 0x17, 0x70, 0x00, 0x00, 0x03, 0x10, 0xCB, 0xE6,
                                      0x45, 0x4D, 0xDC, 0x52, 0xF9, 0xD0, 0xAA, 0x85, 0x3D, 0xF9, 0xA6, 0xC5, 0x47,
                                      0x0E, 0x05, 0x04, 0xD2, 0x71, 0x95, 0x01, 0x06, 0x04, 0xAA, 0x12, 0x24, 0x5D};

namespace WrapperParser 
{
INESCOPEXPORT int __stdcall parseString(char*         str,
                                       unsigned int  str_size,
                                       char*&        rstr,
                                       unsigned int& rsre_size,
                                       bool& codeInComment /*std::string str, std::string& rstr*/);
}

#endif