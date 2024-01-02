// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxDrawTextUtils.pas' rev: 35.00 (Windows)

#ifndef CxdrawtextutilsHPP
#define CxdrawtextutilsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.UITypes.hpp>
#include <Winapi.Windows.hpp>
#include <Vcl.Controls.hpp>
#include <System.Types.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <Vcl.Graphics.hpp>
#include <dxCoreGraphics.hpp>

//-- user supplied -----------------------------------------------------------

namespace Cxdrawtextutils
{
//-- forward type declarations -----------------------------------------------
struct TcxTextParams;
struct TcxTextRow;
struct TcxTextRows;
struct TdxTextMeasurerHelper /* Helper for class 'Dxcoregraphics::TdxTextMeasurer*' */;
//-- type declarations -------------------------------------------------------
typedef System::WideChar TCaptionChar;

typedef System::WideChar TcxCaptionChar;

typedef System::WideChar * PcxCaptionChar;

typedef unsigned TcxTextOutFormat;

enum DECLSPEC_DENUM TcxTextAlignX : unsigned char { taLeft, taCenterX, taRight, taJustifyX, taDistributeX };

enum DECLSPEC_DENUM TcxTextAlignY : unsigned char { taTop, taCenterY, taBottom, taDistributeY };

enum DECLSPEC_DENUM TcxVerticalTextOutDirection : unsigned char { vtdTopToBottom, vtdBottomToTop };

typedef TcxTextParams *PcxTextParams;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TcxTextParams
{
public:
	int RowHeight;
	int tmExternalLeading;
	int FullRowHeight;
	int EndEllipsisWidth;
	bool Bold;
	System::WideChar BreakChar;
	TcxTextAlignX TextAlignX;
	TcxTextAlignY TextAlignY;
	bool WordBreak;
	bool SingleLine;
	bool ExpandTabs;
	bool EndEllipsis;
	bool ExternalLeading;
	bool EditControl;
	bool ExcelStyle;
	bool NoClip;
	bool AutoIndents;
	bool PatternedText;
	bool PreventLeftExceed;
	bool PreventTopExceed;
	bool CharBreak;
	bool CalcRowCount;
	bool CalcRect;
	int MaxCharWidth;
	System::Byte CharSet;
	int OnePixel;
	bool HidePrefix;
	bool RTLReading;
};
#pragma pack(pop)


typedef TcxTextRow *PcxTextRow;

struct DECLSPEC_DRECORD TcxTextRow
{
public:
	System::WideChar *Text;
	int TextLength;
	System::Types::TSize TextExtents;
	int BreakCount;
	int TextOriginX;
	int TextOriginY;
	int StartOffset;
	System::UnicodeString __fastcall ToString();
};


typedef HDC TCanvasHandle;

typedef System::DynamicArray<TcxTextRow> TcxDynamicTextRows;

typedef System::Types::TSize __fastcall (*TcxCalcTextExtentsProc)(HDC AHandle, System::WideChar * AText, int ATextLength, bool AExpandTabs, void * AData);

struct DECLSPEC_DRECORD TcxTextRows
{
public:
	int Count;
	System::UnicodeString Text;
	System::StaticArray<TcxTextRow, 32> StaticRows;
	TcxDynamicTextRows DynamicRows;
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 CXTO_LEFT = System::Int8(0x0);
static const System::Int8 CXTO_CENTER_HORIZONTALLY = System::Int8(0x1);
static const System::Int8 CXTO_RIGHT = System::Int8(0x2);
static const System::Int8 CXTO_JUSTIFY_HORIZONTALLY = System::Int8(0x3);
static const System::Int8 CXTO_DISTRIBUTE_HORIZONTALLY = System::Int8(0x4);
static const System::Int8 CXTO_TOP = System::Int8(0x0);
static const System::Int8 CXTO_CENTER_VERTICALLY = System::Int8(0x10);
static const System::Int8 CXTO_BOTTOM = System::Int8(0x20);
static const System::Int8 CXTO_DISTRIBUTE_VERTICALLY = System::Int8(0x30);
static const System::Word CXTO_WORDBREAK = System::Word(0x100);
static const System::Word CXTO_SINGLELINE = System::Word(0x200);
static const System::Word CXTO_EXPANDTABS = System::Word(0x400);
static const System::Word CXTO_END_ELLIPSIS = System::Word(0x800);
static const System::Word CXTO_PATTERNEDTEXT = System::Word(0x1000);
static const System::Word CXTO_EXTERNALLEADING = System::Word(0x2000);
static const System::Word CXTO_EDITCONTROL = System::Word(0x4000);
static const System::Word CXTO_NOCLIP = System::Word(0x8000);
static const int CXTO_AUTOINDENTS = int(0x10000);
static const int CXTO_CHARBREAK = int(0x20000);
static const int CXTO_PREVENT_LEFT_EXCEED = int(0x40000);
static const int CXTO_PREVENT_TOP_EXCEED = int(0x80000);
static const int CXTO_CALCRECT = int(0x100000);
static const int CXTO_CALCROWCOUNT = int(0x200000);
static const System::Int8 CXTO_NOPREFIX = System::Int8(0x0);
static const int CXTO_HIDEPREFIX = int(0x1000000);
static const int CXTO_EXCELSTYLE = int(0x2000000);
static const int CXTO_RTLREADING = int(0x4000000);
static const System::Word CXTO_DEFAULT_FORMAT = System::Word(0x200);
static const System::Int8 cxTextSpace = System::Int8(0x2);
static const System::Int8 TcxCacheStaticRowsCount = System::Int8(0x20);
static const System::Int8 cxMinVisuallyVisibleTextHeight = System::Int8(0x6);
#define cxEndEllipsis L"..."
extern DELPHI_PACKAGE System::WideChar *cxEndEllipsisChars;
static const int cxEndEllipsisCharsLength = int(3);
extern DELPHI_PACKAGE void __fastcall cxResetTextRows(TcxTextRows &ATextRows);
extern DELPHI_PACKAGE PcxTextRow __fastcall cxGetTextRow(const TcxTextRows &ATextRows, int AIndex);
extern DELPHI_PACKAGE int __fastcall cxGetTextRowCount(const TcxTextRows &ATextRows);
extern DELPHI_PACKAGE unsigned __fastcall cxMakeFormat(TcxTextAlignX ATextAlignX, TcxTextAlignY ATextAlignY);
extern DELPHI_PACKAGE System::Types::TSize __fastcall cxCalcTextExtents(HDC AHandle, System::WideChar * AText, int ATextLength, bool AExpandTabs)/* overload */;
extern DELPHI_PACKAGE System::Types::TSize __fastcall cxCalcTextExtentsEx(HDC AHandle, System::WideChar * AText, int ATextLength, bool AExpandTabs, void * AData)/* overload */;
extern DELPHI_PACKAGE void __fastcall cxCalcTextRowExtents(HDC AHandle, PcxTextRow ATextRow, const TcxTextParams &ATextParams)/* overload */;
extern DELPHI_PACKAGE void __fastcall cxCalcTextRowExtents(HDC AHandle, PcxTextRow ATextRow, const TcxTextParams &ATextParams, void * AUserData, TcxCalcTextExtentsProc ACalcTextExtentsProc)/* overload */;
extern DELPHI_PACKAGE TcxTextParams __fastcall cxCalcTextParams(HDC AHandle, unsigned AFormat, const double ALineSpacingFactor = 1.000000E+00)/* overload */;
extern DELPHI_PACKAGE TcxTextParams __fastcall cxCalcTextParams(Vcl::Graphics::TCanvas* ACanvas, unsigned AFormat, const double ALineSpacingFactor = 1.000000E+00)/* overload */;
extern DELPHI_PACKAGE bool __fastcall cxGetIsWordDelimeter(unsigned ACodePage, System::WideChar AChar);
extern DELPHI_PACKAGE System::WideChar * __fastcall cxGetNextWordBreak(unsigned ACodePage, System::WideChar * AStart, System::WideChar * AEnd);
extern DELPHI_PACKAGE bool __fastcall cxMakeTextRows(HDC AHandle, System::WideChar * AText, int ATextLength, const System::Types::TRect &R, const TcxTextParams &ATextParams, TcxTextRows &ATextRows, /* out */ int &ACount, int AMaxLineCount = 0x0)/* overload */;
extern DELPHI_PACKAGE bool __fastcall cxMakeTextRows(HDC AHandle, System::WideChar * AText, int ATextLength, const System::Types::TRect &R, const TcxTextParams &ATextParams, TcxTextRows &ATextRows, /* out */ int &ACount, int AMaxLineCount, void * AUserData, TcxCalcTextExtentsProc ACalcTextExtentsProc)/* overload */;
extern DELPHI_PACKAGE bool __fastcall cxMakeTextRows(Vcl::Graphics::TCanvas* ACanvas, System::WideChar * AText, int ATextLength, const System::Types::TRect &R, const TcxTextParams &ATextParams, TcxTextRows &ATextRows, /* out */ int &ACount, int AMaxLineCount = 0x0)/* overload */;
extern DELPHI_PACKAGE void __fastcall cxPlaceTextRows(HDC AHandle, const System::Types::TRect &R, TcxTextParams &ATextParams, const TcxTextRows &ATextRows, int ARowCount);
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxPrepareRect(const System::Types::TRect &R, const TcxTextParams &ATextParams, int ALeftIndent, int ARightIndent);
extern DELPHI_PACKAGE void __fastcall cxPrepareEndEllipsis(HDC AHandle, PcxTextRow ATextRow, const TcxTextParams &ATextParams, TcxCalcTextExtentsProc ACalcTextExtentsProc, int &AWidth, void * AUserData = (void *)(0x0))/* overload */;
extern DELPHI_PACKAGE void __fastcall cxPrepareEndEllipsis(HDC AHandle, PcxTextRow ATextRow, const TcxTextParams &ATextParams, TcxCalcTextExtentsProc ACalcTextExtentsProc, const System::Types::TRect &ABounds, int &AWidth, void * AUserData = (void *)(0x0))/* overload */;
extern DELPHI_PACKAGE void __fastcall cxTextRowsOutAlphaBlend(HDC AHandle, const System::Types::TRect &ABounds, const TcxTextParams &ATextParams, const TcxTextRows &ATextRows, int ARowCount, bool AForceEndEllipsis, const tagRGBQUAD ATextColor);
extern DELPHI_PACKAGE void __fastcall cxTextRowsOutHighlight(HDC AHandle, const System::Types::TRect &ABounds, const TcxTextParams &ATextParams, const TcxTextRows &ATextRows, int ARowCount, int ASelStart, int ASelLength, System::Uitypes::TColor ASelBkgColor, System::Uitypes::TColor ASelTextColor, bool AForceEndEllipsis);
extern DELPHI_PACKAGE int __fastcall cxGetLongestTextRowWidth(const TcxTextRows &ATextRows, int ARowCount);
extern DELPHI_PACKAGE int __fastcall cxTextOut(HDC AHandle, const System::UnicodeString AText, System::Types::TRect &R, unsigned AFormat, int ASelStart, int ASelLength, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ASelBkgColor, System::Uitypes::TColor ASelTextColor, int AMaxLineCount = 0x0, int ALeftIndent = 0x0, int ARightIndent = 0x0, System::Uitypes::TColor ATextColor = (System::Uitypes::TColor)(0x20000000), const double ALineSpacingFactor = 1.000000E+00)/* overload */;
extern DELPHI_PACKAGE int __fastcall cxTextOut(HDC AHandle, const System::UnicodeString AText, System::Types::TRect &R, unsigned AFormat = (unsigned)(0x200), Vcl::Graphics::TFont* AFont = (Vcl::Graphics::TFont*)(0x0), int AMaxLineCount = 0x0, int ALeftIndent = 0x0, int ARightIndent = 0x0, System::Uitypes::TColor ATextColor = (System::Uitypes::TColor)(0x20000000), const double ALineSpacingFactor = 1.000000E+00)/* overload */;
extern DELPHI_PACKAGE int __fastcall cxTextOut(Vcl::Graphics::TCanvas* ACanvas, const System::UnicodeString AText, System::Types::TRect &R, unsigned AFormat, int ASelStart, int ASelLength, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ASelBkgColor, System::Uitypes::TColor ASelTextColor, int AMaxLineCount = 0x0, int ALeftIndent = 0x0, int ARightIndent = 0x0, System::Uitypes::TColor ATextColor = (System::Uitypes::TColor)(0x20000000), const double ALineSpacingFactor = 1.000000E+00)/* overload */;
extern DELPHI_PACKAGE int __fastcall cxTextOut(Vcl::Graphics::TCanvas* ACanvas, const System::UnicodeString AText, System::Types::TRect &R, unsigned AFormat = (unsigned)(0x200), Vcl::Graphics::TFont* AFont = (Vcl::Graphics::TFont*)(0x0), int AMaxLineCount = 0x0, int ALeftIndent = 0x0, int ARightIndent = 0x0, System::Uitypes::TColor ATextColor = (System::Uitypes::TColor)(0x20000000), const double ALineSpacingFactor = 1.000000E+00)/* overload */;
extern DELPHI_PACKAGE void __fastcall cxRotatedTextOut(HDC AHandle, const System::Types::TRect &ABounds, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, TcxTextAlignX AAlignHorz = (TcxTextAlignX)(0x1), TcxTextAlignY AAlignVert = (TcxTextAlignY)(0x1), bool AWordBreak = true, bool ALeftExceed = true, bool ARightExceed = true, TcxVerticalTextOutDirection ADirection = (TcxVerticalTextOutDirection)(0x1), int AFontSize = 0x0)/* overload */;
}	/* namespace Cxdrawtextutils */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXDRAWTEXTUTILS)
using namespace Cxdrawtextutils;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxdrawtextutilsHPP
