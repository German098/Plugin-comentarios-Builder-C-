// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxLike.pas' rev: 35.00 (Windows)

#ifndef CxlikeHPP
#define CxlikeHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.SysUtils.hpp>

//-- user supplied -----------------------------------------------------------

namespace Cxlike
{
//-- forward type declarations -----------------------------------------------
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TcxFilterLikeOperator : unsigned char { floLike, floBeginsWith, floEndsWith, floContains };

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE TcxFilterLikeOperator __fastcall LikeOperatorByPattern(System::UnicodeString &APatternStr, System::WideChar APercent);
extern DELPHI_PACKAGE bool __fastcall LikeStr(const System::UnicodeString AStr, const System::UnicodeString APatternStr, System::WideChar APercent, System::WideChar AUnderline, System::WideChar AEscape = (System::WideChar)(0x0));
}	/* namespace Cxlike */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXLIKE)
using namespace Cxlike;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxlikeHPP
