// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxOffice11.pas' rev: 35.00 (Windows)

#ifndef Dxoffice11HPP
#define Dxoffice11HPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Types.hpp>
#include <System.SysUtils.hpp>
#include <System.TypInfo.hpp>
#include <Winapi.Windows.hpp>
#include <Winapi.Messages.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <System.Classes.hpp>
#include <cxGraphics.hpp>
#include <cxGeometry.hpp>

//-- user supplied -----------------------------------------------------------

namespace Dxoffice11
{
//-- forward type declarations -----------------------------------------------
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TOffice11Scheme : unsigned char { schUnknown, schNormalColor, schHomestead, schMetallic };

typedef TOffice11Scheme TOffice11SchemeColor;

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11DockColor1;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11DockColor2;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11ToolbarsColor1;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11ToolbarsColor2;
extern DELPHI_PACKAGE System::StaticArray<System::Uitypes::TColor, 3> dxOffice11BarMarkColors1;
extern DELPHI_PACKAGE System::StaticArray<System::Uitypes::TColor, 3> dxOffice11BarMarkColors2;
extern DELPHI_PACKAGE System::StaticArray<System::Uitypes::TColor, 2> dxOffice11BarBorderColors;
extern DELPHI_PACKAGE System::StaticArray<System::StaticArray<System::Uitypes::TColor, 3>, 2> dxOffice11BarBorderMarkColors;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11BarFingerColor1;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11BarFingerColor2;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11BarSeparatorColor1;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11BarSeparatorColor2;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11BarMarkArrowColor1;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11BarMarkArrowColor2;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11BarFloatingBorderColor1;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11BarFloatingBorderColor2;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11BarFloatingBorderColor3;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11BarFloatingCaptionColor;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11BarFloatingCaptionTextColor1;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11BarFloatingCaptionTextColor2;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11BarFloatingCaptionTextColor3;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11MenuColor;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11MenuDownedColor1;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11MenuDownedColor2;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11MenuIndentColor1;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11MenuIndentColor2;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11MenuNonRecentIndentColor1;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11MenuNonRecentIndentColor2;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11DropDownBorderColor1;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11DropDownBorderColor2;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11ToolbarSelectedColor;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11SelectedBorderColor;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11SelectedColor1;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11SelectedColor2;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11SelectedDownColor1;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11SelectedDownColor2;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11OwnerControlDownedColor;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11DownedColor;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11DownedSelectedColor;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11DetachableColor;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11DetachableSelectedColor;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11TextEnabledColor;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11TextDisabledColor;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11StaticBorderColor;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11DateHeaderColor;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11InPlaceSubItemColor;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11InPlaceSubItemTextColor;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11ControlBorderColor;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11GroupColor;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11DayNavigatorSelectedColor;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11OutlookBorderColor;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11OutlookControlColor;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11GroupIndentColor;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11GroupRowTextColor;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11GroupRowSeparatorColor;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11NavPaneBorder;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11NavPaneGroupCaptionColor1;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11NavPaneGroupCaptionColor2;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11NavPaneGroupCaptionHotColor1;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11NavPaneGroupCaptionHotColor2;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11NavPaneGroupCaptionPressedColor1;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11NavPaneGroupCaptionPressedColor2;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11NavPaneGroupCaptionPressedHotColor1;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11NavPaneGroupCaptionPressedHotColor2;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11NavPaneHeaderColor1;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11NavPaneHeaderColor2;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11NavPaneHeaderFontColor;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11NavPaneSplitterColor1;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11NavPaneSplitterColor2;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11ExpandButtonColor1;
extern DELPHI_PACKAGE System::Uitypes::TColor dxOffice11ExpandButtonColor2;
extern DELPHI_PACKAGE HBRUSH dxOffice11BarFingerBrush1;
extern DELPHI_PACKAGE HBRUSH dxOffice11BarFingerBrush2;
extern DELPHI_PACKAGE HBRUSH dxOffice11BarSeparatorBrush1;
extern DELPHI_PACKAGE HBRUSH dxOffice11BarSeparatorBrush2;
extern DELPHI_PACKAGE HBRUSH dxOffice11MenuBrush;
extern DELPHI_PACKAGE HBRUSH dxOffice11SelectedBorderBrush;
extern DELPHI_PACKAGE HBRUSH dxOffice11ToolbarSelectedBrush;
extern DELPHI_PACKAGE HBRUSH dxOffice11OwnerControlDownedBrush;
extern DELPHI_PACKAGE HBRUSH dxOffice11DownedBrush;
extern DELPHI_PACKAGE HBRUSH dxOffice11DownedSelectedBrush;
extern DELPHI_PACKAGE HBRUSH dxOffice11DropDownBorderBrush1;
extern DELPHI_PACKAGE HBRUSH dxOffice11DropDownBorderBrush2;
extern DELPHI_PACKAGE HBRUSH dxOffice11DetachableBrush;
extern DELPHI_PACKAGE HBRUSH dxOffice11DetachableSelectedBrush;
extern DELPHI_PACKAGE HBRUSH dxOffice11StaticBorderBrush;
extern DELPHI_PACKAGE HBRUSH dxOffice11InPlaceSubItemBrush;
extern DELPHI_PACKAGE Vcl::Graphics::TBitmap* dxOffice11SubMenuExpandBitmap;
extern DELPHI_PACKAGE Vcl::Graphics::TBitmap* dxOffice11ExpandButtonBitmap1;
extern DELPHI_PACKAGE Vcl::Graphics::TBitmap* dxOffice11ExpandButtonBitmap2;
extern DELPHI_PACKAGE TOffice11Scheme __fastcall GetOffice11Scheme(void);
extern DELPHI_PACKAGE void __fastcall Office11DrawItemArrow(HDC DC, const System::Types::TRect &R, bool ADownArrow, bool Enabled, bool Selected, bool Flat);
extern DELPHI_PACKAGE bool __fastcall IsXPStandardScheme(void);
extern DELPHI_PACKAGE void __fastcall ReleaseOffice11Colors(void);
extern DELPHI_PACKAGE void __fastcall CreateOffice11Colors(void);
extern DELPHI_PACKAGE void __fastcall Office11DrawLargeItemArrow(HDC ADC, const System::Types::TRect &R, Cxgraphics::TcxArrowDirection AArrowType, int ASize, bool ASelected, bool AEnabled, bool AFlat);
extern DELPHI_PACKAGE void __fastcall Office11FrameSelectedRect(HDC DC, const System::Types::TRect &R);
extern DELPHI_PACKAGE void __fastcall Office11DrawFingerElements(HDC DC, const System::Types::TRect &ARect, bool AHorizontal, HBRUSH ABrush1 = (HBRUSH)(0x0), HBRUSH ABrush2 = (HBRUSH)(0x0), Cxgeometry::TdxScaleFactor* AScaleFactor = (Cxgeometry::TdxScaleFactor*)(0x0));
extern DELPHI_PACKAGE void __fastcall RefreshOffice11Colors(void);
extern DELPHI_PACKAGE void __fastcall Office11FillTubeGradientRect(HDC DC, const System::Types::TRect &ARect, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, bool AHorizontal);
extern DELPHI_PACKAGE void __fastcall Office11DrawSizeGrip(HDC DC, const System::Types::TRect &ARect, System::Uitypes::TColor AColor1 = (System::Uitypes::TColor)(0x20000000), System::Uitypes::TColor AColor2 = (System::Uitypes::TColor)(0x20000000), Cxgeometry::TdxScaleFactor* AScaleFactor = (Cxgeometry::TdxScaleFactor*)(0x0));
extern DELPHI_PACKAGE int __fastcall GetOffice11FingerElementSize(Cxgeometry::TdxScaleFactor* AScaleFactor = (Cxgeometry::TdxScaleFactor*)(0x0));
}	/* namespace Dxoffice11 */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXOFFICE11)
using namespace Dxoffice11;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Dxoffice11HPP
