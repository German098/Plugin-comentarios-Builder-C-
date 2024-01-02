// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxThemeManager.pas' rev: 35.00 (Windows)

#ifndef DxthememanagerHPP
#define DxthememanagerHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Types.hpp>
#include <Winapi.Windows.hpp>
#include <Winapi.Messages.hpp>
#include <System.SysUtils.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Forms.hpp>
#include <System.Generics.Collections.hpp>
#include <System.Generics.Defaults.hpp>
#include <dxUxTheme.hpp>
#include <cxGeometry.hpp>

//-- user supplied -----------------------------------------------------------

namespace Dxthememanager
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TdxThemeChangedNotificator;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TdxThemedObjectType : unsigned char { totButton, totClock, totComboBox, totEdit, totExplorerBar, totHeader, totListBox, totListView, totMenu, totPage, totProgress, totRebar, totScrollBar, totSpin, totStartPanel, totStatus, totTab, totTaskBand, totTaskBar, totToolBar, totToolTip, totTrackBar, totTrayNotify, totTreeView, totWindow, totNavigation, totExplorerListView, totTextStyle, totItemsViewListView, totItemsViewHeader, totExplorerTreeView };

enum DECLSPEC_DENUM TdxThemeSizeScaleSource : unsigned char { tssNoScaling, tssSystemDpi, tssThemeDpi };

typedef System::Set<TdxThemedObjectType, TdxThemedObjectType::totButton, TdxThemedObjectType::totExplorerTreeView> TdxThemedObjectTypes;

typedef void __fastcall (__closure *TdxThemeChangedEvent)(void);

class PASCALIMPLEMENTATION TdxThemeChangedNotificator : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxThemeChangedEvent FOnThemeChanged;
	
protected:
	virtual void __fastcall DoThemeChanged();
	
public:
	__fastcall TdxThemeChangedNotificator();
	__fastcall virtual ~TdxThemeChangedNotificator();
	__property TdxThemeChangedEvent OnThemeChanged = {read=FOnThemeChanged, write=FOnThemeChanged};
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE bool __fastcall AreVisualStylesAvailable(TdxThemedObjectType ANeededThemedObjectType)/* overload */;
extern DELPHI_PACKAGE bool __fastcall AreVisualStylesAvailable(TdxThemedObjectTypes ANeededThemedObjectTypes = TdxThemedObjectTypes() )/* overload */;
extern DELPHI_PACKAGE HRESULT __fastcall CloseTheme(TdxThemedObjectType AThemedObjectType);
extern DELPHI_PACKAGE void __fastcall CloseAllThemes(void);
extern DELPHI_PACKAGE NativeUInt __fastcall OpenTheme(TdxThemedObjectType AThemedObjectType, System::WideChar * AClassNameList = (System::WideChar *)(0x0))/* overload */;
extern DELPHI_PACKAGE NativeUInt __fastcall OpenTheme(TdxThemedObjectType AThemedObjectType, int ADpi, System::WideChar * AClassNameList = (System::WideChar *)(0x0))/* overload */;
extern DELPHI_PACKAGE NativeUInt __fastcall OpenTheme(TdxThemedObjectType AThemedObjectType, Cxgeometry::TdxScaleFactor* AScaleFactor, System::WideChar * AClassNameList = (System::WideChar *)(0x0))/* overload */;
extern DELPHI_PACKAGE System::Types::TSize __fastcall GetThemeScaledPartSize(TdxThemedObjectType AThemedObjectType, Cxgeometry::TdxScaleFactor* AScaleFactor, int APartId, int AStateId, TdxThemeSizeScaleSource AScaleSource = (TdxThemeSizeScaleSource)(0x2))/* overload */;
extern DELPHI_PACKAGE bool __fastcall GetThemeScaledPartSize(TdxThemedObjectType AThemedObjectType, Cxgeometry::TdxScaleFactor* AScaleFactor, int APartId, /* out */ System::Types::TSize &ASize, int AStateId = 0x0, TdxThemeSizeScaleSource AScaleSource = (TdxThemeSizeScaleSource)(0x2))/* overload */;
extern DELPHI_PACKAGE Cxgeometry::TdxScaleFactor* __fastcall GetThemeScaleFactor(NativeUInt ATheme);
extern DELPHI_PACKAGE System::Uitypes::TColor __fastcall cxGetThemeColor(TdxThemedObjectType AObjectType, int APartId, int AStateId, int APropId)/* overload */;
extern DELPHI_PACKAGE bool __fastcall cxGetThemeColor(TdxThemedObjectType AObjectType, int APartId, int AStateId, int APropId, /* out */ System::Uitypes::TColor &AColor)/* overload */;
extern DELPHI_PACKAGE bool __fastcall dxDrawThemeBackground(HDC DC, TdxThemedObjectType AThemedObjectType, const System::Types::TRect &R, int APartId, int AStateId)/* overload */;
extern DELPHI_PACKAGE bool __fastcall dxDrawThemeBackground(HDC DC, TdxThemedObjectType AThemedObjectType, Cxgeometry::TdxScaleFactor* AScaleFactor, const System::Types::TRect &R, int APartId, int AStateId)/* overload */;
extern DELPHI_PACKAGE bool __fastcall IsStandardTheme(void);
extern DELPHI_PACKAGE bool __fastcall IsThemeScaled(NativeUInt ATheme);
}	/* namespace Dxthememanager */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXTHEMEMANAGER)
using namespace Dxthememanager;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxthememanagerHPP
