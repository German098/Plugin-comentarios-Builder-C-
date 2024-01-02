// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxLookAndFeels.pas' rev: 35.00 (Windows)

#ifndef CxlookandfeelsHPP
#define CxlookandfeelsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Types.hpp>
#include <Winapi.Messages.hpp>
#include <System.SysUtils.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <System.Classes.hpp>
#include <Vcl.Graphics.hpp>
#include <dxCore.hpp>
#include <dxCoreClasses.hpp>
#include <dxThemeManager.hpp>
#include <cxClasses.hpp>
#include <dxOffice11.hpp>
#include <cxGeometry.hpp>
#include <cxLookAndFeelPainters.hpp>

//-- user supplied -----------------------------------------------------------

namespace Cxlookandfeels
{
//-- forward type declarations -----------------------------------------------
__interface DELPHIINTERFACE IcxLookAndFeelNotificationListener;
typedef System::DelphiInterface<IcxLookAndFeelNotificationListener> _di_IcxLookAndFeelNotificationListener;
__interface DELPHIINTERFACE IcxLookAndFeelNotificationListener2;
typedef System::DelphiInterface<IcxLookAndFeelNotificationListener2> _di_IcxLookAndFeelNotificationListener2;
__interface DELPHIINTERFACE IdxCustomSkinnedContainer;
typedef System::DelphiInterface<IdxCustomSkinnedContainer> _di_IdxCustomSkinnedContainer;
__interface DELPHIINTERFACE IdxSkinSupport;
typedef System::DelphiInterface<IdxSkinSupport> _di_IdxSkinSupport;
__interface DELPHIINTERFACE IdxSkinSupport2;
typedef System::DelphiInterface<IdxSkinSupport2> _di_IdxSkinSupport2;
__interface DELPHIINTERFACE IdxTouchModeSupport;
typedef System::DelphiInterface<IdxTouchModeSupport> _di_IdxTouchModeSupport;
__interface DELPHIINTERFACE IdxVisualRefinementsListener;
typedef System::DelphiInterface<IdxVisualRefinementsListener> _di_IdxVisualRefinementsListener;
__interface DELPHIINTERFACE IcxLookAndFeelContainer;
typedef System::DelphiInterface<IcxLookAndFeelContainer> _di_IcxLookAndFeelContainer;
struct TcxLookAndFeelData;
class DELPHICLASS TcxLookAndFeel;
class DELPHICLASS TcxRootLookAndFeel;
class DELPHICLASS TcxLookAndFeelController;
class DELPHICLASS TcxSystemPaletteChangedNotifier;
struct TdxPadding;
__interface DELPHIINTERFACE IdxVisualRefinementsTuner;
typedef System::DelphiInterface<IdxVisualRefinementsTuner> _di_IdxVisualRefinementsTuner;
class DELPHICLASS TdxVisualRefinements;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TcxLookAndFeelKind : unsigned char { lfFlat, lfStandard, lfUltraFlat, lfOffice11 };

enum DECLSPEC_DENUM TcxLookAndFeelValue : unsigned char { lfvKind, lfvNativeStyle, lfvSkinName, lfvScrollbarMode, lfvRenderMode, lfvScrollMode };

typedef System::Set<TcxLookAndFeelValue, TcxLookAndFeelValue::lfvKind, TcxLookAndFeelValue::lfvScrollMode> TcxLookAndFeelValues;

enum DECLSPEC_DENUM TdxScrollbarMode : unsigned char { sbmDefault, sbmTouch, sbmClassic, sbmHybrid };

enum DECLSPEC_DENUM TdxScrollMode : unsigned char { scmDefault, scmClassic, scmSmooth };

enum DECLSPEC_DENUM TdxRenderMode : unsigned char { rmDefault, rmGDI, rmDirectX, rmGDIPlus };

__interface  INTERFACE_UUID("{205538BF-F19E-4285-B11F-B182D9635881}") IcxLookAndFeelNotificationListener  : public System::IInterface 
{
	virtual System::TObject* __fastcall GetObject() = 0 ;
	virtual void __fastcall MasterLookAndFeelChanged(TcxLookAndFeel* Sender, TcxLookAndFeelValues AChangedValues) = 0 ;
	virtual void __fastcall MasterLookAndFeelDestroying(TcxLookAndFeel* Sender) = 0 ;
};

__interface  INTERFACE_UUID("{392FC2E2-3F2A-4885-B9E6-43982962F475}") IcxLookAndFeelNotificationListener2  : public System::IInterface 
{
	virtual void __fastcall MasterLookAndFeelBeginChange() = 0 ;
	virtual void __fastcall MasterLookAndFeelEndChange() = 0 ;
};

__interface  INTERFACE_UUID("{8A0FF5C0-C25A-4191-AE0F-B231D2651F2F}") IdxCustomSkinnedContainer  : public System::IInterface 
{
	virtual System::Uitypes::TColor __fastcall GetDefaultTextColor(bool AEnabled) = 0 ;
};

__interface  INTERFACE_UUID("{EF3FF483-9B69-46DF-95A4-D3A3810F63A5}") IdxSkinSupport  : public System::IInterface 
{
	
};

__interface  INTERFACE_UUID("{01C435BA-7DA1-44A4-BE8B-BCE9CE0562AB}") IdxSkinSupport2  : public IdxSkinSupport 
{
	virtual bool __fastcall IsSkinnable() = 0 ;
};

__interface  INTERFACE_UUID("{9107444B-867E-44C5-BF9A-DAB4EE879827}") IdxTouchModeSupport  : public System::IInterface 
{
	virtual void __fastcall Disable() = 0 ;
	virtual void __fastcall Enable() = 0 ;
};

__interface  INTERFACE_UUID("{287BA6FB-1282-4933-AFDB-45DC4D2E3F65}") IdxVisualRefinementsListener  : public System::IInterface 
{
	virtual void __fastcall Changed() = 0 ;
};

__interface  INTERFACE_UUID("{6065B58B-C557-4464-A67D-64183FD13F25}") IcxLookAndFeelContainer  : public System::IInterface 
{
	virtual TcxLookAndFeel* __fastcall GetLookAndFeel() = 0 ;
};

typedef void __fastcall (__closure *TcxLookAndFeelChangedEvent)(TcxLookAndFeel* Sender, TcxLookAndFeelValues AChangedValues);

enum DECLSPEC_DENUM TdxTouchScrollUIMode : unsigned char { tsmDefault, tsmEnabled, tsmDisabled };

struct DECLSPEC_DRECORD TcxLookAndFeelData
{
public:
	TcxLookAndFeelKind Kind;
	bool NativeStyle;
	System::UnicodeString SkinName;
	TdxScrollbarMode ScrollbarMode;
	TdxScrollMode ScrollMode;
	TdxRenderMode RenderMode;
	bool UseSkins;
};


class PASCALIMPLEMENTATION TcxLookAndFeel : public Dxcoreclasses::TcxInterfacedPersistent
{
	typedef Dxcoreclasses::TcxInterfacedPersistent inherited;
	
private:
	TcxLookAndFeelValues FAssignedValues;
	TcxLookAndFeelValues FChangedValues;
	Cxclasses::TcxObjectList* FChangeListenerList;
	TcxLookAndFeelData FCurrentState;
	TcxLookAndFeelData FData;
	bool FIsDestruction;
	bool FIsRootLookAndFeel;
	TcxLookAndFeel* FMasterLookAndFeel;
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* FPainter;
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* FSkinPainter;
	TcxLookAndFeelData FPrevState;
	TcxSystemPaletteChangedNotifier* FSystemPaletteChangedNotifier;
	int FUpdateLockCount;
	TcxLookAndFeelChangedEvent FOnChanged;
	System::Classes::TNotifyEvent FOnMasterBeginChange;
	System::Classes::TNotifyEvent FOnMasterEndChange;
	Cxlookandfeelpainters::TcxLookAndFeelStyle __fastcall GetActiveStyle();
	TcxLookAndFeelKind __fastcall GetKind();
	TcxLookAndFeel* __fastcall GetMasterLookAndFeel();
	bool __fastcall GetNativeStyle();
	TdxRenderMode __fastcall GetRenderMode();
	TdxScrollbarMode __fastcall GetScrollbarMode();
	TdxScrollMode __fastcall GetScrollMode();
	Cxclasses::TdxSkinName __fastcall GetSkinName();
	TdxTouchScrollUIMode __fastcall GetTouchScrollUIMode();
	void __fastcall SetAssignedValues(TcxLookAndFeelValues Value);
	void __fastcall SetKind(TcxLookAndFeelKind Value);
	void __fastcall SetMasterLookAndFeel(TcxLookAndFeel* Value);
	void __fastcall SetNativeStyle(bool Value);
	void __fastcall SetRenderMode(const TdxRenderMode Value);
	void __fastcall SetScrollbarMode(const TdxScrollbarMode Value);
	void __fastcall SetScrollMode(const TdxScrollMode Value);
	void __fastcall SetSkinName(const Cxclasses::TdxSkinName Value);
	void __fastcall SetTouchScrollUIMode(const TdxTouchScrollUIMode Value);
	TcxLookAndFeelKind __fastcall GetDefaultKind();
	bool __fastcall GetDefaultNativeStyle();
	TdxRenderMode __fastcall GetDefaultRenderMode();
	TdxScrollbarMode __fastcall GetDefaultScrollbarMode();
	TdxScrollMode __fastcall GetDefaultScrollMode();
	System::UnicodeString __fastcall GetDefaultSkinName();
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetDefaultSkinPainter();
	bool __fastcall IsKindStored();
	bool __fastcall IsNativeStyleStored();
	bool __fastcall IsRenderModeStored();
	bool __fastcall IsScrollbarModeStored();
	bool __fastcall IsScrollModeStored();
	bool __fastcall IsSkinNameStored();
	void __fastcall CheckStateChanges();
	void __fastcall ReadSkinName(System::Classes::TReader* Reader);
	void __fastcall ReadTouchScrollUIMode(System::Classes::TReader* Reader);
	void __fastcall SaveState();
	void __fastcall WriteSkinName(System::Classes::TWriter* Writer);
	
protected:
	void __fastcall Changed(TcxLookAndFeelValues AChangedValues);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	void __fastcall DoMasterLookAndFeelChanged(TcxLookAndFeelValues AChangedValues);
	void __fastcall DoMasterLookAndFeelDestroying();
	virtual Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetSkinPainter(const System::UnicodeString ASkinName);
	virtual void __fastcall InitializeCurrentState();
	virtual void __fastcall InitializePainter();
	virtual TcxLookAndFeelKind __fastcall InternalGetKind();
	virtual bool __fastcall InternalGetNativeStyle();
	virtual TdxRenderMode __fastcall InternalGetRenderMode();
	virtual TdxScrollbarMode __fastcall InternalGetScrollbarMode();
	virtual TdxScrollMode __fastcall InternalGetScrollMode();
	virtual System::UnicodeString __fastcall InternalGetSkinName();
	virtual Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall InternalGetSkinPainter();
	void __fastcall NotifyChanged();
	virtual void __fastcall SystemPaletteChanged();
	System::TObject* __fastcall GetObject();
	void __fastcall MasterLookAndFeelBeginChange();
	void __fastcall MasterLookAndFeelChanged(TcxLookAndFeel* Sender, TcxLookAndFeelValues AChangedValues);
	void __fastcall MasterLookAndFeelEndChange();
	void __fastcall MasterLookAndFeelDestroying(TcxLookAndFeel* Sender);
	__property Cxclasses::TcxObjectList* ChangeListenerList = {read=FChangeListenerList};
	
public:
	__fastcall virtual TcxLookAndFeel(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TcxLookAndFeel();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall BeginUpdate();
	void __fastcall EndUpdate();
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetAvailablePainter(Dxthememanager::TdxThemedObjectType ANeededThemedObjectType)/* overload */;
	virtual Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetAvailablePainter(Dxthememanager::TdxThemedObjectTypes ANeededThemedObjectTypes = Dxthememanager::TdxThemedObjectTypes() )/* overload */;
	void __fastcall Refresh();
	void __fastcall Reset();
	void __fastcall SetStyle(Cxlookandfeelpainters::TcxLookAndFeelStyle Value);
	void __fastcall AddChangeListener(System::TObject* AListener);
	void __fastcall RemoveChangeListener(System::TObject* AListener);
	__property Cxlookandfeelpainters::TcxLookAndFeelStyle ActiveStyle = {read=GetActiveStyle, nodefault};
	__property TcxLookAndFeel* MasterLookAndFeel = {read=GetMasterLookAndFeel, write=SetMasterLookAndFeel};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* Painter = {read=FPainter};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* SkinPainter = {read=FSkinPainter, write=FSkinPainter};
	__property TdxTouchScrollUIMode TouchScrollUIMode = {read=GetTouchScrollUIMode, write=SetTouchScrollUIMode, nodefault};
	__property TcxLookAndFeelChangedEvent OnChanged = {read=FOnChanged, write=FOnChanged};
	__property System::Classes::TNotifyEvent OnMasterBeginChange = {read=FOnMasterBeginChange, write=FOnMasterBeginChange};
	__property System::Classes::TNotifyEvent OnMasterEndChange = {read=FOnMasterEndChange, write=FOnMasterEndChange};
	
__published:
	__property TcxLookAndFeelValues AssignedValues = {read=FAssignedValues, write=SetAssignedValues, stored=false, nodefault};
	__property TcxLookAndFeelKind Kind = {read=GetKind, write=SetKind, stored=IsKindStored, nodefault};
	__property bool NativeStyle = {read=GetNativeStyle, write=SetNativeStyle, stored=IsNativeStyleStored, nodefault};
	__property TdxRenderMode RenderMode = {read=GetRenderMode, write=SetRenderMode, stored=IsRenderModeStored, nodefault};
	__property TdxScrollbarMode ScrollbarMode = {read=GetScrollbarMode, write=SetScrollbarMode, stored=IsScrollbarModeStored, nodefault};
	__property TdxScrollMode ScrollMode = {read=GetScrollMode, write=SetScrollMode, stored=IsScrollModeStored, nodefault};
	__property Cxclasses::TdxSkinName SkinName = {read=GetSkinName, write=SetSkinName, stored=IsSkinNameStored};
private:
	void *__IcxLookAndFeelNotificationListener2;	// IcxLookAndFeelNotificationListener2 
	void *__IcxLookAndFeelNotificationListener;	// IcxLookAndFeelNotificationListener 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {392FC2E2-3F2A-4885-B9E6-43982962F475}
	operator _di_IcxLookAndFeelNotificationListener2()
	{
		_di_IcxLookAndFeelNotificationListener2 intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IcxLookAndFeelNotificationListener2*(void) { return (IcxLookAndFeelNotificationListener2*)&__IcxLookAndFeelNotificationListener2; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {205538BF-F19E-4285-B11F-B182D9635881}
	operator _di_IcxLookAndFeelNotificationListener()
	{
		_di_IcxLookAndFeelNotificationListener intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IcxLookAndFeelNotificationListener*(void) { return (IcxLookAndFeelNotificationListener*)&__IcxLookAndFeelNotificationListener; }
	#endif
	
};


class PASCALIMPLEMENTATION TcxRootLookAndFeel : public TcxLookAndFeel
{
	typedef TcxLookAndFeel inherited;
	
public:
	__fastcall TcxRootLookAndFeel();
public:
	/* TcxLookAndFeel.Destroy */ inline __fastcall virtual ~TcxRootLookAndFeel() { }
	
};


class PASCALIMPLEMENTATION TcxLookAndFeelController : public Cxclasses::TcxCustomComponent
{
	typedef Cxclasses::TcxCustomComponent inherited;
	
private:
	TcxLookAndFeelKind __fastcall GetKind();
	bool __fastcall GetNativeStyle();
	TdxRenderMode __fastcall GetRenderMode();
	TdxScrollbarMode __fastcall GetScrollbarMode();
	TdxScrollMode __fastcall GetScrollMode();
	Cxclasses::TdxSkinName __fastcall GetSkinName();
	bool __fastcall GetTouchMode();
	bool __fastcall GetTouchScrollUIMode();
	bool __fastcall IsSkinNameStored();
	void __fastcall SetKind(TcxLookAndFeelKind AValue);
	void __fastcall SetNativeStyle(bool AValue);
	void __fastcall SetRenderMode(TdxRenderMode AValue);
	void __fastcall SetScrollbarMode(const TdxScrollbarMode AValue);
	void __fastcall SetScrollMode(const TdxScrollMode AValue);
	void __fastcall SetSkinName(const Cxclasses::TdxSkinName AValue);
	void __fastcall SetTouchMode(bool AValue);
	void __fastcall SetTouchScrollUIMode(const bool AValue);
	void __fastcall ReadTouchScrollUIMode(System::Classes::TReader* AReader);
	void __fastcall Modified();
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	System::TObject* __fastcall GetObject();
	virtual void __fastcall MasterLookAndFeelChanged(TcxLookAndFeel* Sender, TcxLookAndFeelValues AChangedValues);
	virtual void __fastcall MasterLookAndFeelDestroying(TcxLookAndFeel* Sender);
	
public:
	__fastcall virtual TcxLookAndFeelController(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxLookAndFeelController();
	void __fastcall BeginUpdate();
	void __fastcall EndUpdate();
	virtual void __fastcall Reset();
	__property bool TouchScrollUIMode = {read=GetTouchScrollUIMode, write=SetTouchScrollUIMode, nodefault};
	
__published:
	__property TcxLookAndFeelKind Kind = {read=GetKind, write=SetKind, default=2};
	__property bool NativeStyle = {read=GetNativeStyle, write=SetNativeStyle, default=1};
	__property TdxScrollbarMode ScrollbarMode = {read=GetScrollbarMode, write=SetScrollbarMode, default=0};
	__property TdxScrollMode ScrollMode = {read=GetScrollMode, write=SetScrollMode, default=0};
	__property Cxclasses::TdxSkinName SkinName = {read=GetSkinName, write=SetSkinName, stored=IsSkinNameStored};
	__property TdxRenderMode RenderMode = {read=GetRenderMode, write=SetRenderMode, default=0};
	__property bool TouchMode = {read=GetTouchMode, write=SetTouchMode, default=0};
private:
	void *__IcxLookAndFeelNotificationListener;	// IcxLookAndFeelNotificationListener 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {205538BF-F19E-4285-B11F-B182D9635881}
	operator _di_IcxLookAndFeelNotificationListener()
	{
		_di_IcxLookAndFeelNotificationListener intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IcxLookAndFeelNotificationListener*(void) { return (IcxLookAndFeelNotificationListener*)&__IcxLookAndFeelNotificationListener; }
	#endif
	
};


typedef void __fastcall (__closure *TcxSystemPaletteChangedEvent)(void);

class PASCALIMPLEMENTATION TcxSystemPaletteChangedNotifier : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FIsPrimary;
	TcxSystemPaletteChangedEvent FOnSystemPaletteChanged;
	
protected:
	virtual void __fastcall DoChanged();
	
public:
	__fastcall virtual TcxSystemPaletteChangedNotifier(bool AIsPrimary);
	__fastcall virtual ~TcxSystemPaletteChangedNotifier();
	__property TcxSystemPaletteChangedEvent OnSystemPaletteChanged = {read=FOnSystemPaletteChanged, write=FOnSystemPaletteChanged};
};


struct DECLSPEC_DRECORD TdxPadding
{
public:
	int Left;
	int Top;
	int Right;
	int Bottom;
	
private:
	static TdxPadding FNull;
	int __fastcall GetWidth();
	int __fastcall GetHeight();
	
public:
	static void __fastcall Initialize();
	static bool __fastcall _op_Equality(const TdxPadding &L, const TdxPadding &R);
	static bool __fastcall _op_Inequality(const TdxPadding &L, const TdxPadding &R);
	static TdxPadding __fastcall _op_Implicit(const System::Types::TRect &AValue);
	__fastcall operator System::Types::TRect();
	void __fastcall Deflate(System::Types::TRect &R, Cxgeometry::TdxScaleFactor* AScaleFactor, bool ARightToLeft = false)/* overload */;
	void __fastcall Deflate(System::Types::TRect &R, bool ARightToLeft = false)/* overload */;
	TdxPadding __fastcall GetScaled(Cxgeometry::TdxScaleFactor* AScaleFactor);
	void __fastcall Inflate(System::Types::TRect &R, Cxgeometry::TdxScaleFactor* AScaleFactor, bool ARightToLeft = false)/* overload */;
	void __fastcall Inflate(System::Types::TRect &R, bool ARightToLeft = false)/* overload */;
	void __fastcall Inflate(System::Types::TSize &S, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	void __fastcall Inflate(System::Types::TSize &S)/* overload */;
	void __fastcall InflatePadding(System::Types::TRect &APadding, Cxgeometry::TdxScaleFactor* AScaleFactor, bool ARightToLeft = false)/* overload */;
	void __fastcall InflatePadding(System::Types::TRect &APadding, bool ARightToLeft = false)/* overload */;
	bool __fastcall IsZero();
	int __fastcall ScaledWidth(Cxgeometry::TdxScaleFactor* AScaleFactor);
	int __fastcall ScaledHeight(Cxgeometry::TdxScaleFactor* AScaleFactor);
	/* static */ __property TdxPadding Null = {read=FNull};
	__property int Height = {read=GetHeight};
	__property int Width = {read=GetWidth};
	
	friend bool operator ==(const TdxPadding &L, const TdxPadding &R) { return TdxPadding::_op_Equality(L, R); }
	friend bool operator !=(const TdxPadding &L, const TdxPadding &R) { return TdxPadding::_op_Inequality(L, R); }
	TdxPadding& operator =(const System::Types::TRect &AValue) { *this = TdxPadding::_op_Implicit(AValue); return *this; }
};


__interface  INTERFACE_UUID("{DE887152-048A-4051-9A61-0884AB7626E3}") IdxVisualRefinementsTuner  : public System::IInterface 
{
	virtual void __fastcall AdjustPadding(TdxPadding &APadding) = 0 ;
};

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxVisualRefinements : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	static int FLockCount;
	static TdxPadding FPadding;
	static TdxPadding FHeaderPadding;
	static Dxcoreclasses::TdxFastObjectList* FListeners;
	static bool FUsePaddingForStandaloneEditors;
	static bool FLightBorders;
	static void __fastcall Changed();
	static void __fastcall SetPadding(const TdxPadding &AValue);
	static void __fastcall SetHeaderPadding(const TdxPadding &AValue);
	static void __fastcall SetUsePaddingForStandaloneEditors(bool AValue);
	static void __fastcall SetLightBorders(const bool AValue);
	
protected:
	static void __fastcall Initialize();
	static void __fastcall Finalize();
	
public:
	static void __fastcall AddListener(System::TObject* AListener);
	static void __fastcall RemoveListener(System::TObject* AListener);
	static void __fastcall ApplyLightStyle(bool AUsePaddingForStandaloneEditors = false);
	static void __fastcall Reset();
	static void __fastcall BeginUpdate();
	static void __fastcall EndUpdate();
	/* static */ __property TdxPadding Padding = {read=FPadding, write=SetPadding};
	/* static */ __property TdxPadding HeaderPadding = {read=FHeaderPadding, write=SetHeaderPadding};
	/* static */ __property bool UsePaddingForStandaloneEditors = {read=FUsePaddingForStandaloneEditors, write=SetUsePaddingForStandaloneEditors, nodefault};
	/* static */ __property bool LightBorders = {read=FLightBorders, write=SetLightBorders, nodefault};
public:
	/* TObject.Create */ inline __fastcall TdxVisualRefinements() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxVisualRefinements() { }
	
};

#pragma pack(pop)

typedef bool __fastcall (*TdxClassSupportsSkinProc)(System::Classes::TPersistent* AClass);

typedef void __fastcall (*TdxGetSkinNamesProc)(System::Classes::TStrings* AList);

typedef Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall (*TdxGetSkinPainterProc)(const System::UnicodeString ASkinName);

enum DECLSPEC_DENUM TdxFormCorners : unsigned char { fcDefault, fcRectangular, fcRounded, fcSmallRounded };

enum DECLSPEC_DENUM TdxQATPosition : unsigned char { qatpInCaption, qatpAbove, qatpBelow };

//-- var, const, procedure ---------------------------------------------------
static const bool cxDefaultIsTouchModeEnabled = false;
static const bool cxDefaultIsTouchScrollUIModeEnabled = false;
static const TcxLookAndFeelKind cxDefaultLookAndFeelKind = (TcxLookAndFeelKind)(2);
static const bool cxDefaultLookAndFeelNativeStyle = true;
static const TdxRenderMode cxDefaultLookAndFeelRenderMode = (TdxRenderMode)(1);
static const TdxScrollMode cxDefaultLookAndFeelScrollMode = (TdxScrollMode)(1);
#define cxDefaultLookAndFeelSkinName L""
static const bool cxDefaultUseSkins = true;
static const bool cxDefaultUseSkinsInPopupMenus = true;
extern DELPHI_PACKAGE bool cxIsTouchModeEnabled;
extern DELPHI_PACKAGE bool cxUseSkins;
extern DELPHI_PACKAGE bool cxUseSkinsInPopupMenus;
extern DELPHI_PACKAGE bool dxUseVectorIcons;
extern DELPHI_PACKAGE System::StaticArray<TcxLookAndFeelKind, 6> cxLookAndFeelKindMap;
extern DELPHI_PACKAGE System::StaticArray<Cxlookandfeelpainters::TcxLookAndFeelStyle, 4> cxLookAndFeelStyleMap;
extern DELPHI_PACKAGE System::StaticArray<int, 4> dxStandardFormCornerRadius;
extern DELPHI_PACKAGE TdxClassSupportsSkinProc ClassSupportsSkinProc;
extern DELPHI_PACKAGE TdxGetSkinNamesProc GetSkinNamesProc;
extern DELPHI_PACKAGE TdxGetSkinPainterProc GetSkinPainterProc;
extern DELPHI_PACKAGE TdxFormCorners dxSkinFormCorners;
extern DELPHI_PACKAGE Dxcore::TdxDefaultBoolean dxSkinShowFormShadow;
extern DELPHI_PACKAGE void __fastcall SetControlLookAndFeel(Vcl::Controls::TControl* AControl, TcxLookAndFeel* AMasterLookAndFeel)/* overload */;
extern DELPHI_PACKAGE void __fastcall SetControlLookAndFeel(Vcl::Controls::TControl* AControl, TcxLookAndFeelKind AKind, bool ANativeStyle)/* overload */;
extern DELPHI_PACKAGE bool __fastcall cxIsTouchScrollUIModeEnabled(void);
extern DELPHI_PACKAGE bool __fastcall IsRootLookAndFeelAssigned(void);
extern DELPHI_PACKAGE TcxLookAndFeel* __fastcall RootLookAndFeel(void);
}	/* namespace Cxlookandfeels */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXLOOKANDFEELS)
using namespace Cxlookandfeels;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxlookandfeelsHPP
