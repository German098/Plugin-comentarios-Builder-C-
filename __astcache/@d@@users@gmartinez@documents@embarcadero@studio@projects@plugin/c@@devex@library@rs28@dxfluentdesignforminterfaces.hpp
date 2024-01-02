// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxFluentDesignFormInterfaces.pas' rev: 35.00 (Windows)

#ifndef DxfluentdesignforminterfacesHPP
#define DxfluentdesignforminterfacesHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Winapi.Messages.hpp>
#include <Winapi.Windows.hpp>
#include <dxCore.hpp>
#include <dxCoreGraphics.hpp>

//-- user supplied -----------------------------------------------------------

namespace Dxfluentdesignforminterfaces
{
//-- forward type declarations -----------------------------------------------
__interface DELPHIINTERFACE IdxFluentDesignNavigationControlListener;
typedef System::DelphiInterface<IdxFluentDesignNavigationControlListener> _di_IdxFluentDesignNavigationControlListener;
__interface DELPHIINTERFACE IdxFluentDesignContainerControl;
typedef System::DelphiInterface<IdxFluentDesignContainerControl> _di_IdxFluentDesignContainerControl;
__interface DELPHIINTERFACE IdxFluentDesignNavigationControl;
typedef System::DelphiInterface<IdxFluentDesignNavigationControl> _di_IdxFluentDesignNavigationControl;
__interface DELPHIINTERFACE IdxAcrylicHostControl;
typedef System::DelphiInterface<IdxAcrylicHostControl> _di_IdxAcrylicHostControl;
__interface DELPHIINTERFACE IdxAcrylicHostControl2;
typedef System::DelphiInterface<IdxAcrylicHostControl2> _di_IdxAcrylicHostControl2;
__interface DELPHIINTERFACE IdxAcrylicHostControlListener;
typedef System::DelphiInterface<IdxAcrylicHostControlListener> _di_IdxAcrylicHostControlListener;
__interface DELPHIINTERFACE IdxFluentDesignForm;
typedef System::DelphiInterface<IdxFluentDesignForm> _di_IdxFluentDesignForm;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TdxFluentDesignNavigationControlDisplayMode : unsigned char { ncdmInline, ncdmOverlay, ncdmOverlayMinimal };

enum DECLSPEC_DENUM TdxFluentDesignNavigationControlChangeType : unsigned char { nchtAppearance, nchtBounds, nchtVisibility };

typedef System::Set<TdxFluentDesignNavigationControlChangeType, TdxFluentDesignNavigationControlChangeType::nchtAppearance, TdxFluentDesignNavigationControlChangeType::nchtVisibility> TdxFluentDesignNavigationControlChangeTypes;

enum class DECLSPEC_DENUM TdxFluentDesignBackgroundBlur : unsigned char { None, Standard, Acrylic };

__interface  INTERFACE_UUID("{71365666-FE08-438D-B5C6-46DE2781945A}") IdxFluentDesignNavigationControlListener  : public System::IInterface 
{
	virtual void __fastcall Changed(TdxFluentDesignNavigationControlChangeTypes AChanges) = 0 ;
};

__interface  INTERFACE_UUID("{D0B5352A-B84A-407F-9269-7141054A8AB8}") IdxFluentDesignContainerControl  : public System::IInterface 
{
	virtual bool __fastcall CanBeOpaque() = 0 ;
	virtual void __fastcall NotifyTurnedOpaque() = 0 ;
};

__interface  INTERFACE_UUID("{872FF75F-4368-4F3E-99F9-B277771FFD65}") IdxFluentDesignNavigationControl  : public System::IInterface 
{
	virtual bool __fastcall IsAdaptable() = 0 ;
	virtual bool __fastcall IsCollapsed() = 0 ;
	virtual bool __fastcall GetAcrylicEnabled() = 0 ;
	virtual Dxcoregraphics::TdxAlphaColor __fastcall GetBackgroundColor() = 0 ;
	virtual Dxcoregraphics::TdxAlphaColor __fastcall GetBorderColor() = 0 ;
	virtual TdxFluentDesignNavigationControlDisplayMode __fastcall GetDisplayMode() = 0 ;
	virtual System::Uitypes::TColor __fastcall GetForegroundColor() = 0 ;
	virtual void __fastcall SetDisplayMode(TdxFluentDesignNavigationControlDisplayMode AValue) = 0 ;
	virtual void __fastcall AddListener(_di_IdxFluentDesignNavigationControlListener AListener) = 0 ;
	virtual void __fastcall RemoveListener(_di_IdxFluentDesignNavigationControlListener AListener) = 0 ;
};

__interface  INTERFACE_UUID("{FC0606D4-3A22-4758-8578-D4C570BFE1D9}") IdxAcrylicHostControl  : public System::IInterface 
{
	virtual Dxcoregraphics::TdxAlphaColor __fastcall GetAcrylicColor() = 0 ;
	virtual bool __fastcall IsAcrylic() = 0 ;
};

__interface  INTERFACE_UUID("{817103E0-0DF9-4A53-8572-3091C0FF8B49}") IdxAcrylicHostControl2  : public System::IInterface 
{
	virtual TdxFluentDesignBackgroundBlur __fastcall GetBackgroundBlur() = 0 ;
};

__interface  INTERFACE_UUID("{76D7B1B4-101D-4A67-A93C-6D04868790F4}") IdxAcrylicHostControlListener  : public System::IInterface 
{
	virtual void __fastcall Changed(_di_IdxAcrylicHostControl AValue, bool AHasAcrylicParent) = 0 ;
};

__interface  INTERFACE_UUID("{E5798CE2-65CF-48FD-B23A-B0F4297BF7EA}") IdxFluentDesignForm  : public IdxAcrylicHostControl 
{
	virtual System::Types::TRect __fastcall GetExtendedNavigationControlBounds() = 0 ;
	virtual _di_IdxFluentDesignNavigationControl __fastcall GetNavigationControl() = 0 ;
	virtual Dxcoregraphics::TdxAlphaColor __fastcall GetNavigationControlBackgroundColor() = 0 ;
	virtual System::Uitypes::TColor __fastcall GetNavigationControlForegroundColor() = 0 ;
};

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxfluentdesignforminterfaces */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXFLUENTDESIGNFORMINTERFACES)
using namespace Dxfluentdesignforminterfaces;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxfluentdesignforminterfacesHPP
