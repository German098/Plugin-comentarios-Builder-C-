// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxForms.pas' rev: 35.00 (Windows)

#ifndef DxformsHPP
#define DxformsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Messaging.hpp>
#include <System.Types.hpp>
#include <Winapi.Windows.hpp>
#include <Winapi.Messages.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Forms.hpp>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <System.SysUtils.hpp>
#include <Winapi.MultiMon.hpp>
#include <System.Contnrs.hpp>
#include <Vcl.ImgList.hpp>
#include <System.Math.hpp>
#include <System.Generics.Collections.hpp>
#include <System.Generics.Defaults.hpp>
#include <dxGenerics.hpp>
#include <dxMessages.hpp>
#include <cxGeometry.hpp>
#include <dxCoreGraphics.hpp>
#include <cxClasses.hpp>
#include <dxCore.hpp>
#include <cxGraphics.hpp>
#include <cxLookAndFeels.hpp>

//-- user supplied -----------------------------------------------------------

namespace Dxforms
{
//-- forward type declarations -----------------------------------------------
__interface DELPHIINTERFACE IdxFloatForm;
typedef System::DelphiInterface<IdxFloatForm> _di_IdxFloatForm;
class DELPHICLASS TdxCustomForm;
class DELPHICLASS TdxCustomFloatForm;
class DELPHICLASS TdxForm;
class DELPHICLASS TdxFormCornersPainter;
class DELPHICLASS TdxFormHelper;
//-- type declarations -------------------------------------------------------
__interface  INTERFACE_UUID("{BAED1CE9-B7D7-468D-907B-79883637054D}") IdxFloatForm  : public System::IInterface 
{
	virtual Vcl::Forms::TCustomForm* __fastcall GetParentForm() = 0 ;
};

class PASCALIMPLEMENTATION TdxCustomForm : public Vcl::Forms::TCustomForm
{
	typedef Vcl::Forms::TCustomForm inherited;
	
private:
	bool FRightToLeftApplied;
	Dxcore::TdxDefaultBoolean FRightToLeftLayout;
	Cxgeometry::TdxScaleFactor* FScaleFactor;
	bool __fastcall IsRightToLeftLayout();
	void __fastcall RightToLeftLayoutChanged();
	void __fastcall SetRightToLeftLayout(const Dxcore::TdxDefaultBoolean AValue);
	HIDESBASE MESSAGE void __fastcall CMBiDiModeChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMDPIChanged(Winapi::Messages::TMessage &Message);
	Cxgeometry::TdxScaleFactor* __fastcall GetScaleFactor();
	
protected:
	DYNAMIC void __fastcall ChangeScale(int M, int D)/* overload */ _FINAL_ATTRIBUTE;
	DYNAMIC void __fastcall ChangeScale(int M, int D, bool IsDpiChange)/* overload */;
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd();
	DYNAMIC void __fastcall DoShow();
	virtual System::Types::TPoint __fastcall GetClientOrigin();
	DYNAMIC void __fastcall InitializeNewForm();
	virtual void __fastcall ScaleControlsForDpi(int NewPPI);
	virtual void __fastcall ScaleFactorChanged(int M, int D);
	virtual void __fastcall SetParent(Vcl::Controls::TWinControl* AParent);
	virtual void __fastcall UpdateImageLists();
	__property Dxcore::TdxDefaultBoolean RightToLeftLayout = {read=FRightToLeftLayout, write=SetRightToLeftLayout, nodefault};
	__property Cxgeometry::TdxScaleFactor* ScaleFactor = {read=GetScaleFactor};
	
public:
	__fastcall virtual ~TdxCustomForm();
	virtual void __fastcall BeforeDestruction();
	void __fastcall ForceScaleForPPI(int PPI, System::Types::PRect AWindowRect = (System::Types::PRect)(0x0));
	HIDESBASE void __fastcall ScaleBy(int M, int D);
	virtual void __fastcall ScaleForCurrentDPI();
	HIDESBASE virtual void __fastcall ScaleForPPI(int ATargetDPI, System::Types::PRect AWindowRect)/* overload */;
	virtual void __fastcall ScaleForPPI(int ATargetDPI)/* overload */ _FINAL_ATTRIBUTE;
public:
	/* TCustomForm.Create */ inline __fastcall virtual TdxCustomForm(System::Classes::TComponent* AOwner) : Vcl::Forms::TCustomForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxCustomForm(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TCustomForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxCustomForm(HWND ParentWindow) : Vcl::Forms::TCustomForm(ParentWindow) { }
	
private:
	void *__IdxScaleFactor;	// Cxgeometry::IdxScaleFactor 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {367A805A-A84B-441A-83A3-6A7E489D3B6C}
	operator Cxgeometry::_di_IdxScaleFactor()
	{
		Cxgeometry::_di_IdxScaleFactor intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Cxgeometry::IdxScaleFactor*(void) { return (Cxgeometry::IdxScaleFactor*)&__IdxScaleFactor; }
	#endif
	
};


class PASCALIMPLEMENTATION TdxCustomFloatForm : public TdxCustomForm
{
	typedef TdxCustomForm inherited;
	
protected:
	virtual Vcl::Forms::TCustomForm* __fastcall GetParentForm() = 0 ;
	
public:
	__fastcall virtual TdxCustomFloatForm(System::Classes::TComponent* AOwner, int Dummy);
public:
	/* TdxCustomForm.Destroy */ inline __fastcall virtual ~TdxCustomFloatForm() { }
	
public:
	/* TCustomForm.Create */ inline __fastcall virtual TdxCustomFloatForm(System::Classes::TComponent* AOwner) : TdxCustomForm(AOwner) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxCustomFloatForm(HWND ParentWindow) : TdxCustomForm(ParentWindow) { }
	
private:
	void *__IdxFloatForm;	// IdxFloatForm 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {BAED1CE9-B7D7-468D-907B-79883637054D}
	operator _di_IdxFloatForm()
	{
		_di_IdxFloatForm intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IdxFloatForm*(void) { return (IdxFloatForm*)&__IdxFloatForm; }
	#endif
	
};


typedef System::TMetaClass* TdxFormClass;

class PASCALIMPLEMENTATION TdxForm : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
private:
	bool FDynamicCreatedForm;
	bool FBufferedShowing;
	int FLoadedClientHeight;
	int FLoadedClientWidth;
	bool FRightToLeftApplied;
	Dxcore::TdxDefaultBoolean FRightToLeftLayout;
	System::Types::TRect FSaveBoundsRect;
	Cxgeometry::TdxScaleFactor* FScaleFactor;
	Cxgeometry::TdxScaleFactor* __fastcall GetScaleFactor();
	bool __fastcall IsRightToLeftLayout();
	void __fastcall RightToLeftLayoutChanged();
	HIDESBASE void __fastcall SetClientHeight(int Value);
	HIDESBASE void __fastcall SetClientWidth(int Value);
	void __fastcall SetRightToLeftLayout(const Dxcore::TdxDefaultBoolean AValue);
	HIDESBASE MESSAGE void __fastcall CMBiDiModeChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMShowingChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMDPIChanged(Winapi::Messages::TMessage &Message);
	
protected:
	DYNAMIC void __fastcall ChangeScale(int M, int D)/* overload */ _FINAL_ATTRIBUTE;
	DYNAMIC void __fastcall ChangeScale(int M, int D, bool IsDpiChange)/* overload */;
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd();
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	DYNAMIC void __fastcall DoShow();
	virtual System::Types::TPoint __fastcall GetClientOrigin();
	DYNAMIC void __fastcall InitializeNewForm();
	DYNAMIC void __fastcall Resize();
	virtual void __fastcall ScaleFactorChanged(int M, int D);
	virtual void __fastcall UpdateImageLists();
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	virtual void __fastcall ScaleControlsForDpi(int NewPPI);
	virtual void __fastcall BeginBufferedShowing();
	virtual void __fastcall EndBufferedShowing();
	virtual bool __fastcall IsBufferedShowing();
	virtual void __fastcall Loaded();
	virtual void __fastcall ReadState(System::Classes::TReader* Reader);
	virtual void __fastcall SetParent(Vcl::Controls::TWinControl* AParent);
	virtual void __fastcall SetPixelsPerInch(int Value);
	__property bool BufferedShowing = {read=FBufferedShowing, nodefault};
	__property Dxcore::TdxDefaultBoolean RightToLeftLayout = {read=FRightToLeftLayout, write=SetRightToLeftLayout, default=2};
	__property Cxgeometry::TdxScaleFactor* ScaleFactor = {read=GetScaleFactor};
	
public:
	__fastcall virtual TdxForm(System::Classes::TComponent* AOwner, int Dummy);
	__fastcall virtual ~TdxForm();
	virtual void __fastcall BeforeDestruction();
	HIDESBASE void __fastcall ScaleBy(int M, int D);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	virtual void __fastcall ScaleForCurrentDPI();
	HIDESBASE virtual void __fastcall ScaleForPPI(int ATargetDPI, System::Types::PRect AWindowRect)/* overload */;
	virtual void __fastcall ScaleForPPI(int ATargetDPI)/* overload */ _FINAL_ATTRIBUTE;
	
__published:
	__property ClientHeight = {write=SetClientHeight};
	__property ClientWidth = {write=SetClientWidth};
	__property PixelsPerInch = {write=SetPixelsPerInch};
public:
	/* TCustomForm.Create */ inline __fastcall virtual TdxForm(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxForm(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
private:
	void *__IdxScaleFactor;	// Cxgeometry::IdxScaleFactor 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {367A805A-A84B-441A-83A3-6A7E489D3B6C}
	operator Cxgeometry::_di_IdxScaleFactor()
	{
		Cxgeometry::_di_IdxScaleFactor intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Cxgeometry::IdxScaleFactor*(void) { return (Cxgeometry::IdxScaleFactor*)&__IdxScaleFactor; }
	#endif
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFormCornersPainter : public System::TObject
{
	typedef System::TObject inherited;
	
	
public:
	__interface DELPHIINTERFACE TGetColorFunc;
	typedef System::DelphiInterface<TGetColorFunc> _di_TGetColorFunc;
	__interface TGetColorFunc  : public System::IInterface 
	{
		virtual Dxcoregraphics::TdxAlphaColor __fastcall Invoke(bool Active, Dxcore::TdxCorner Corner) = 0 ;
	};
	
	
private:
	System::StaticArray<System::StaticArray<Dxcoregraphics::TdxAlphaColor, 4>, 2> FColors;
	_di_TGetColorFunc FOnGetColor;
	Dxcoregraphics::TdxAlphaColor __fastcall GetColor(bool AActive, Dxcore::TdxCorner ACorner);
	
public:
	__fastcall TdxFormCornersPainter(_di_TGetColorFunc AGetColorFunc);
	void __fastcall Draw(HDC DC, const System::Types::TRect &R, Dxcore::TdxCorners ACorners, bool AActive, int ARadius);
	void __fastcall FlushCache();
	__property Dxcoregraphics::TdxAlphaColor Colors[bool AActive][Dxcore::TdxCorner ACorner] = {read=GetColor};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxFormCornersPainter() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFormHelper : public System::TObject
{
	typedef System::TObject inherited;
	
	
protected:
	class DELPHICLASS TState;
	class PASCALIMPLEMENTATION TState : public System::TObject
	{
		typedef System::TObject inherited;
		
	protected:
		System::Contnrs::TComponentList* LockedControls;
		bool RedrawLocked;
	public:
		/* TObject.Create */ inline __fastcall TState() : System::TObject() { }
		/* TObject.Destroy */ inline __fastcall virtual ~TState() { }
		
	};
	
	
	
private:
	static System::Classes::TList* FLockedForms;
	static System::Classes::TList* FScalingContainers;
	static int FMessageSubscriberId;
	__classmethod bool __fastcall HasMaximizedEmbeddedForms(System::Contnrs::TComponentList* AList);
	__classmethod void __fastcall PopulateControls(Vcl::Controls::TControl* AControl, System::Contnrs::TComponentList* ATargetList);
	
protected:
	__classmethod void __fastcall Finalize();
	__classmethod void __fastcall Initialize();
	__classmethod void __fastcall ScalingBegin(Vcl::Controls::TWinControl* AContainer, /* out */ TState* &AState);
	__classmethod void __fastcall ScalingEnd(Vcl::Controls::TWinControl* AContainer, TState* AState);
	__classmethod void __fastcall UpdateScaleFactorOnParentChange(Vcl::Forms::TCustomForm* AForm);
	
public:
	__classmethod bool __fastcall GetAnimation();
	__classmethod Cxgraphics::TcxRegion* __fastcall GetRegion(Vcl::Controls::TWinControl* AForm);
	__classmethod bool __fastcall SetAnimation(bool AValue);
	__classmethod void __fastcall SetWindowTextWithoutRedrawing(NativeUInt AWndHandle, const System::UnicodeString AText);
	__classmethod HRGN __fastcall CreateRoundedRegion(const System::Types::TRect &ABounds, int ACornerRadius);
	__classmethod int __fastcall GetMinBorderWidth(int ACornerRadius);
	__classmethod unsigned __fastcall LockWindowRedrawing(NativeUInt AWndHandle);
	__classmethod void __fastcall UnlockWindowRedrawing(NativeUInt AWndHandle, unsigned APrevStyle);
	__classmethod bool __fastcall CanResetScalingFlags(System::Classes::TComponent* AComponent, int M, int D);
	__classmethod bool __fastcall IsScaleChanging(Vcl::Controls::TWinControl* AContainer);
	__classmethod void __fastcall RepaintVisibleWindowArea(NativeUInt AHandle, HRGN &APrevVisibleRegion);
	__classmethod void __fastcall ResetScalingFlags(Vcl::Controls::TControl* AControl);
	__classmethod void __fastcall ScaleComponentsForDpi(System::Classes::TComponent* AOwner, int NewPPI);
	__classmethod void __fastcall ScaleForPPI(Vcl::Forms::TCustomForm* Form, int TargetDPI, System::Types::PRect WindowRect, bool FromMessageHandler);
	__classmethod bool __fastcall ShouldPassDpiChangeMessage(Vcl::Forms::TCustomForm* AForm);
	__classmethod void __fastcall ProcessDpiChangeMessageBegin(Vcl::Forms::TCustomForm* AForm);
	__classmethod void __fastcall ProcessDpiChangeMessageEnd(Vcl::Forms::TCustomForm* AForm);
public:
	/* TObject.Create */ inline __fastcall TdxFormHelper() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxFormHelper() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE bool dxAutoReplaceImageListReferencesOnDPIChanges;
extern DELPHI_PACKAGE HICON __fastcall dxGetFormIcon(NativeUInt AHandle, int ASizeX, int ASizeY);
extern DELPHI_PACKAGE Cxlookandfeels::TdxFormCorners __fastcall dxGetFormCorners(NativeUInt AHandle);
extern DELPHI_PACKAGE bool __fastcall dxSetFormCorners(NativeUInt AHandle, Cxlookandfeels::TdxFormCorners ACorners);
}	/* namespace Dxforms */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXFORMS)
using namespace Dxforms;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxformsHPP
