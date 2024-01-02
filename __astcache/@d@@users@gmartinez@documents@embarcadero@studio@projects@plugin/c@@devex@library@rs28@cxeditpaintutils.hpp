// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxEditPaintUtils.pas' rev: 35.00 (Windows)

#ifndef CxeditpaintutilsHPP
#define CxeditpaintutilsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.Windows.hpp>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Graphics.hpp>
#include <System.SysUtils.hpp>
#include <dxCore.hpp>
#include <cxClasses.hpp>
#include <cxControls.hpp>
#include <cxGraphics.hpp>
#include <cxLookAndFeels.hpp>

//-- user supplied -----------------------------------------------------------

namespace Cxeditpaintutils
{
//-- forward type declarations -----------------------------------------------
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE HBRUSH __fastcall GetSolidBrush(System::Uitypes::TColor ABrushColor)/* overload */;
extern DELPHI_PACKAGE HBRUSH __fastcall GetSolidBrush(Vcl::Graphics::TCanvas* ACanvas, System::Uitypes::TColor ABrushColor)/* overload */;
extern DELPHI_PACKAGE HBRUSH __fastcall GetSolidBrush(Cxgraphics::TcxCanvas* ACanvas, System::Uitypes::TColor ABrushColor)/* overload */;
extern DELPHI_PACKAGE void __fastcall ResetSolidBrushCache(void);
}	/* namespace Cxeditpaintutils */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXEDITPAINTUTILS)
using namespace Cxeditpaintutils;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxeditpaintutilsHPP
