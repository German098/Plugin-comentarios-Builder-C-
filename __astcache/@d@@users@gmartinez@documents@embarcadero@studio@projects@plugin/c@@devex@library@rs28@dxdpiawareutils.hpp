// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxDPIAwareUtils.pas' rev: 35.00 (Windows)

#ifndef DxdpiawareutilsHPP
#define DxdpiawareutilsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Types.hpp>
#include <Winapi.Windows.hpp>
#include <Vcl.Forms.hpp>
#include <Winapi.MultiMon.hpp>
#include <System.Classes.hpp>
#include <System.Contnrs.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Graphics.hpp>
#include <System.Generics.Defaults.hpp>
#include <System.Generics.Collections.hpp>
#include <cxGeometry.hpp>
#include <dxCore.hpp>

//-- user supplied -----------------------------------------------------------

namespace Dxdpiawareutils
{
//-- forward type declarations -----------------------------------------------
__interface DELPHIINTERFACE IdxSourceSize;
typedef System::DelphiInterface<IdxSourceSize> _di_IdxSourceSize;
__interface DELPHIINTERFACE IdxSourceDPI;
typedef System::DelphiInterface<IdxSourceDPI> _di_IdxSourceDPI;
class DELPHICLASS TdxCursorManager;
struct TdxScaleFactorHelper /* Helper for class 'Cxgeometry::TdxScaleFactor*' */;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TdxProcessDpiAwareness : unsigned int { pdaUnaware, pdaSystemDpiAware, pdaPerMonitorDpiAware, pdaPerMonitorDpiAwareV2, pdaUnawareGdiScaled };

typedef void __fastcall (__closure *TdxSystemDPINotifyEvent)(System::TObject* Sender, int AOldDPI, int ANewDPI);

__interface  INTERFACE_UUID("{F8A5DDDA-FE77-45F1-8A75-203767ED5982}") IdxSourceSize  : public System::IInterface 
{
	virtual System::Types::TSize __fastcall GetSourceSize() = 0 ;
};

__interface  INTERFACE_UUID("{F722512C-50D3-4266-AA1C-399C3301BB6A}") IdxSourceDPI  : public System::IInterface 
{
	virtual int __fastcall GetSourceDPI() = 0 ;
};

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCursorManager : public System::TObject
{
	typedef System::TObject inherited;
	
	
private:
	class DELPHICLASS TCursorInfo;
	class PASCALIMPLEMENTATION TCursorInfo : public System::TObject
	{
		typedef System::TObject inherited;
		
	protected:
		int Index;
		NativeUInt ResInstance;
		int ResInt;
		System::WideChar *ResName;
	public:
		/* TObject.Create */ inline __fastcall TCursorInfo() : System::TObject() { }
		/* TObject.Destroy */ inline __fastcall virtual ~TCursorInfo() { }
		
	};
	
	
	
private:
	static System::Classes::TList* FList;
	
protected:
	__classmethod void __fastcall Finalize();
	__classmethod void __fastcall DoRegister(TCursorInfo* const AInfo);
	
public:
	__classmethod void __fastcall Refresh();
	__classmethod void __fastcall Register(int ACursorIndex, NativeUInt AResInstance, const System::WideChar * AResName);
	__classmethod void __fastcall Unregister(int ACursorIndex);
public:
	/* TObject.Create */ inline __fastcall TdxCursorManager() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxCursorManager() { }
	
};

#pragma pack(pop)

typedef bool __fastcall (*TdxGetSourceDPIFunc)(System::TObject* AObject, /* out */ int &DPI);

//-- var, const, procedure ---------------------------------------------------
static const System::Int8 dxDefaultDPI = System::Int8(0x60);
static const System::Word dxMaxDPI = System::Word(0x1e0);
static const System::Int8 dxMinDPI = System::Int8(0x1e);
extern DELPHI_PACKAGE System::StaticArray<int, 8> dxDefaultDPIValues;
extern DELPHI_PACKAGE TdxGetSourceDPIFunc FGetSourceDPIFunc;
extern DELPHI_PACKAGE int __fastcall dxCheckDPIValue(int AValue);
extern DELPHI_PACKAGE void __fastcall dxAssignFont(Vcl::Graphics::TFont* ATargetFont, Vcl::Graphics::TFont* ASourceFont, Cxgeometry::TdxScaleFactor* ATargetScaleFactor, Cxgeometry::TdxScaleFactor* ASourceScaleFactor)/* overload */;
extern DELPHI_PACKAGE void __fastcall dxAssignFont(Vcl::Graphics::TFont* ATargetFont, Vcl::Graphics::TFont* ASourceFont, int ATargetDPI, int ASourceDPI)/* overload */;
extern DELPHI_PACKAGE Vcl::Graphics::TFont* __fastcall dxCreateFontForDefaultDPI(void)/* overload */;
extern DELPHI_PACKAGE Vcl::Graphics::TFont* __fastcall dxCreateFontForDefaultDPI(int ASize)/* overload */;
extern DELPHI_PACKAGE int __fastcall dxGetFontHeight(int AFontSize, Cxgeometry::TdxScaleFactor* AScaleFactor);
extern DELPHI_PACKAGE int __fastcall dxGetFontHeightForDefaultDPI(int AFontSize, int ADesignDPI = 0x60);
extern DELPHI_PACKAGE void __fastcall dxScaleFont(Vcl::Graphics::TFont* AFont, int M, int D);
extern DELPHI_PACKAGE bool __fastcall dxAdjustWindowRectEx(System::Types::TRect &R, unsigned Style, unsigned ExStyle, bool Menu, Cxgeometry::TdxScaleFactor* AScaleFactor);
extern DELPHI_PACKAGE int __fastcall dxGetCurrentDPI(System::Classes::TComponent* AComponent);
extern DELPHI_PACKAGE int __fastcall dxGetFormDPI(Vcl::Forms::TCustomForm* AForm);
extern DELPHI_PACKAGE bool __fastcall dxGetCurrentScaleFactor(System::Classes::TComponent* AComponent, /* out */ int &M, /* out */ int &D);
extern DELPHI_PACKAGE int __fastcall dxGetDesktopDPI(void);
extern DELPHI_PACKAGE int __fastcall dxGetSystemDPI(void);
extern DELPHI_PACKAGE int __fastcall dxGetMonitorDPI(Vcl::Forms::TMonitor* const AMonitor)/* overload */;
extern DELPHI_PACKAGE int __fastcall dxGetMonitorDPI(const System::Types::TPoint &AScreenPoint)/* overload */;
extern DELPHI_PACKAGE int __fastcall dxGetMonitorDPI(const NativeUInt AWndHandle)/* overload */;
extern DELPHI_PACKAGE int __fastcall dxGetTargetDPI(System::Classes::TComponent* AComponent);
extern DELPHI_PACKAGE Cxgeometry::TdxScaleFactor* __fastcall dxGetScaleFactor(System::TObject* AOwner);
extern DELPHI_PACKAGE Cxgeometry::TdxScaleFactor* __fastcall dxGetScaleFactorForCanvas(Vcl::Graphics::TCanvas* const ACanvas);
extern DELPHI_PACKAGE Cxgeometry::TdxScaleFactor* __fastcall dxGetScaleFactorForInterface(const System::_di_IInterface AOwner);
extern DELPHI_PACKAGE int __fastcall dxGetSystemMetrics(int AIndex, Cxgeometry::TdxScaleFactor* AScaleFactor = (Cxgeometry::TdxScaleFactor*)(0x0));
extern DELPHI_PACKAGE bool __fastcall dxTryGetScaleFactorForControl(Vcl::Controls::TControl* AControl, /* out */ Cxgeometry::TdxScaleFactor* &AScaleFactor);
extern DELPHI_PACKAGE bool __fastcall dxForceUpdateControlDPI(Vcl::Controls::TWinControl* AControl);
extern DELPHI_PACKAGE void __fastcall dxAddSystemDPIListener(TdxSystemDPINotifyEvent AProcedure);
extern DELPHI_PACKAGE Cxgeometry::TdxScaleFactor* __fastcall dxDefaultScaleFactor(void);
extern DELPHI_PACKAGE Cxgeometry::TdxScaleFactor* __fastcall dxDesktopScaleFactor(void);
extern DELPHI_PACKAGE Cxgeometry::TdxScaleFactor* __fastcall dxSystemScaleFactor(void);
extern DELPHI_PACKAGE TdxProcessDpiAwareness __fastcall dxGetProcessDpiAwareness(void)/* overload */;
extern DELPHI_PACKAGE TdxProcessDpiAwareness __fastcall dxGetProcessDpiAwareness _DEPRECATED_ATTRIBUTE0 (NativeUInt AProcess)/* overload */;
extern DELPHI_PACKAGE bool __fastcall dxGetProcessDpiAwareness(NativeUInt AProcess, /* out */ TdxProcessDpiAwareness &AValue)/* overload */;
extern DELPHI_PACKAGE bool __fastcall dxIsGdiScaledMode(void);
extern DELPHI_PACKAGE bool __fastcall dxIsProcessDPIAware(void);
extern DELPHI_PACKAGE bool __fastcall dxIsProcessDPIPerMonitorV2Aware(void);
extern DELPHI_PACKAGE bool __fastcall dxIsWindowsVistaCompatibilityMode(void);
extern DELPHI_PACKAGE bool __fastcall dxSetProcessDpiAwareness(TdxProcessDpiAwareness AValue);
}	/* namespace Dxdpiawareutils */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXDPIAWAREUTILS)
using namespace Dxdpiawareutils;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxdpiawareutilsHPP
