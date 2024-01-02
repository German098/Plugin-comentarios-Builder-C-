// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxControls.pas' rev: 35.00 (Windows)

#ifndef CxcontrolsHPP
#define CxcontrolsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.UITypes.hpp>
#include <System.Contnrs.hpp>
#include <Winapi.Windows.hpp>
#include <Winapi.Messages.hpp>
#include <Winapi.MultiMon.hpp>
#include <System.SysUtils.hpp>
#include <System.Types.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Dialogs.hpp>
#include <System.Classes.hpp>
#include <Vcl.Themes.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <System.Generics.Defaults.hpp>
#include <System.Generics.Collections.hpp>
#include <dxCore.hpp>
#include <dxCoreClasses.hpp>
#include <dxMessages.hpp>
#include <cxGraphics.hpp>
#include <cxScrollBar.hpp>
#include <cxGeometry.hpp>
#include <cxDrawTextUtils.hpp>
#include <dxTouch.hpp>
#include <cxLookAndFeels.hpp>
#include <cxLookAndFeelPainters.hpp>
#include <dxForms.hpp>
#include <dxCoreGraphics.hpp>
#include <dxGDIPlusClasses.hpp>
#include <dxAnimation.hpp>
#include <cxClasses.hpp>
#include <dxScrollbarAnnotations.hpp>
#include <dxCustomHint.hpp>
#include <cxCustomCanvas.hpp>
#include <dxFluentDesignFormInterfaces.hpp>
#include <dxScrollAnimation.hpp>
#include <dxDirectX.D2D.Canvas.hpp>
#include <Vcl.ImgList.hpp>
#include <System.ImageList.hpp>

//-- user supplied -----------------------------------------------------------

namespace Cxcontrols
{
//-- forward type declarations -----------------------------------------------
struct TLBGetItemRect;
__interface DELPHIINTERFACE IdxScrollParentWindowNotify;
typedef System::DelphiInterface<IdxScrollParentWindowNotify> _di_IdxScrollParentWindowNotify;
__interface DELPHIINTERFACE IdxPopupControl;
typedef System::DelphiInterface<IdxPopupControl> _di_IdxPopupControl;
__interface DELPHIINTERFACE IdxSystemInfoListener;
typedef System::DelphiInterface<IdxSystemInfoListener> _di_IdxSystemInfoListener;
__interface DELPHIINTERFACE IcxMouseCaptureObject;
typedef System::DelphiInterface<IcxMouseCaptureObject> _di_IcxMouseCaptureObject;
__interface DELPHIINTERFACE IcxCompoundControl;
typedef System::DelphiInterface<IcxCompoundControl> _di_IcxCompoundControl;
__interface DELPHIINTERFACE IcxControlComponentState;
typedef System::DelphiInterface<IcxControlComponentState> _di_IcxControlComponentState;
__interface DELPHIINTERFACE IcxPopupMenu;
typedef System::DelphiInterface<IcxPopupMenu> _di_IcxPopupMenu;
__interface DELPHIINTERFACE IcxPopupMenu2;
typedef System::DelphiInterface<IcxPopupMenu2> _di_IcxPopupMenu2;
__interface DELPHIINTERFACE IcxTransparentControl;
typedef System::DelphiInterface<IcxTransparentControl> _di_IcxTransparentControl;
__interface DELPHIINTERFACE IdxPlaceForm;
typedef System::DelphiInterface<IdxPlaceForm> _di_IdxPlaceForm;
__interface DELPHIINTERFACE IdxDialogOwner;
typedef System::DelphiInterface<IdxDialogOwner> _di_IdxDialogOwner;
__interface DELPHIINTERFACE IdxNavigationItem;
typedef System::DelphiInterface<IdxNavigationItem> _di_IdxNavigationItem;
__interface DELPHIINTERFACE IdxNavigationClientListener;
typedef System::DelphiInterface<IdxNavigationClientListener> _di_IdxNavigationClientListener;
__interface DELPHIINTERFACE IdxNavigationClient;
typedef System::DelphiInterface<IdxNavigationClient> _di_IdxNavigationClient;
__interface DELPHIINTERFACE IdxTouchScrollUIOwner;
typedef System::DelphiInterface<IdxTouchScrollUIOwner> _di_IdxTouchScrollUIOwner;
__interface DELPHIINTERFACE IdxHybridScrollbarOwner;
typedef System::DelphiInterface<IdxHybridScrollbarOwner> _di_IdxHybridScrollbarOwner;
class DELPHICLASS TdxApplicationActivateWindowHelper;
class DELPHICLASS TcxControlChildComponent;
class DELPHICLASS TcxScrollBarData;
__interface DELPHIINTERFACE IcxControlScrollBar;
typedef System::DelphiInterface<IcxControlScrollBar> _di_IcxControlScrollBar;
class DELPHICLASS TcxControlScrollBar;
class DELPHICLASS TcxPopupScrollBarViewInfo;
class DELPHICLASS TcxPopupScrollBarPainter;
class DELPHICLASS TdxHybridScrollBarPainter;
class DELPHICLASS TcxCustomPopupScrollBarHelper;
class DELPHICLASS TcxPopupScrollBarHelper;
class DELPHICLASS TdxHybridScrollBarHelper;
class DELPHICLASS TdxTouchScrollUIActivityHelper;
class DELPHICLASS TdxTouchScrollUIModeManager;
class DELPHICLASS TdxHybridScrollbarsManager;
class DELPHICLASS TdxHybridScrollbarManagers;
class DELPHICLASS TcxControlPopupScrollBar;
class DELPHICLASS TcxControlScrollBarHelper;
class DELPHICLASS TcxSizeGrip;
class DELPHICLASS TcxPopupSizeGrip;
class DELPHICLASS TcxSizeGripHelper;
class DELPHICLASS TcxControlScrollBarsManager;
class DELPHICLASS TdxScrollBarWrapper;
class DELPHICLASS TcxControlCustomScrollBars;
class DELPHICLASS TcxControlScrollBars;
class DELPHICLASS TcxControlWindowedScrollBars;
class DELPHICLASS TcxDragAndDropObject;
class DELPHICLASS TcxDragControlObject;
class DELPHICLASS TcxDragImageList;
class DELPHICLASS TcxCustomControl;
class DELPHICLASS TdxMainScrollbarsOwnerHelper;
class DELPHICLASS TcxControlMainScrollbarsHelper;
class DELPHICLASS TcxControl;
class DELPHICLASS TcxControlCanvas;
class DELPHICLASS TcxControlHelper;
class DELPHICLASS TcxControlDefaultHandlerHelper;
class DELPHICLASS TcxControlHintHelper;
__interface DELPHIINTERFACE IdxScrollingControl;
typedef System::DelphiInterface<IdxScrollingControl> _di_IdxScrollingControl;
class DELPHICLASS TcxScrollingControlCustomScrollAnimationHelper;
class DELPHICLASS TcxScrollingControlVertScrollAnimationHelper;
class DELPHICLASS TcxScrollingControlHorzScrollAnimationHelper;
class DELPHICLASS TcxScrollingControl;
class DELPHICLASS TdxScrollHelper;
class DELPHICLASS TcxCustomizeListBox;
class DELPHICLASS TcxMessageWindow;
class DELPHICLASS TcxSystemController;
class DELPHICLASS TdxSystemInfo;
class DELPHICLASS TdxMessagesController;
class DELPHICLASS TcxPopupWindow;
class DELPHICLASS TcxCustomDragImage;
class DELPHICLASS TcxDragImage;
class DELPHICLASS TcxLayeredDragImage;
class DELPHICLASS TcxSizeFrame;
class DELPHICLASS TcxDragAndDropArrow;
class DELPHICLASS TcxDesignController;
class DELPHICLASS TcxWindowProcLinkedObject;
class DELPHICLASS TcxSubclassingHelper;
class DELPHICLASS TcxVCLSubclassingHelper;
class DELPHICLASS TcxWin32SubclassingHelper;
class DELPHICLASS TcxWindowProcLinkedObjectList;
class DELPHICLASS TcxWindowProcController;
__interface DELPHIINTERFACE IcxLockedStatePaint;
typedef System::DelphiInterface<IcxLockedStatePaint> _di_IcxLockedStatePaint;
__interface DELPHIINTERFACE IcxLockedStateFontChanged;
typedef System::DelphiInterface<IcxLockedStateFontChanged> _di_IcxLockedStateFontChanged;
class DELPHICLASS TcxLockedStateImageOptions;
class DELPHICLASS TcxLockedStatePaintHelper;
__interface DELPHIINTERFACE IdxCustomizeControlsHelper;
typedef System::DelphiInterface<IdxCustomizeControlsHelper> _di_IdxCustomizeControlsHelper;
class DELPHICLASS TdxControlsDesignSelectorHelper;
class DELPHICLASS TdxRightToLeftLayoutConverter;
class DELPHICLASS TdxSemiTransparentDragHelper;
class DELPHICLASS TdxAutoScrollHelper;
struct TdxKeyPressWatcher;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TcxSystemMenuType : unsigned char { smSystem, smChild, smDialog };

typedef HWND TcxHandle;

enum DECLSPEC_DENUM TcxDragDetect : unsigned char { ddNone, ddDrag, ddCancel };

enum DECLSPEC_DENUM TcxNumberType : unsigned char { ntInteger, ntFloat, ntExponent };

typedef System::Uitypes::TScrollStyle TcxScrollStyle;

typedef System::Set<Vcl::Forms::TScrollBarKind, Vcl::Forms::TScrollBarKind::sbHorizontal, Vcl::Forms::TScrollBarKind::sbVertical> TScrollBarKinds;

typedef void __fastcall (__closure *TcxScrollControlContent)(Cxclasses::TcxDirection ADirection);

enum DECLSPEC_DENUM TcxRecordScrollMode : unsigned char { rsmDefault, rsmByRecord, rsmByPixel };

#pragma pack(push,1)
struct DECLSPEC_DRECORD TLBGetItemRect
{
public:
	unsigned Msg;
	int ItemIndex;
	System::Types::TRect *Rect;
	int Result;
};
#pragma pack(pop)


typedef System::TMetaClass* TDragControlObjectClass;

__interface  INTERFACE_UUID("{E6A72D05-8320-4E80-8BBC-281889B15476}") IdxScrollParentWindowNotify  : public System::IInterface 
{
	virtual void __fastcall Notify() = 0 ;
};

__interface  INTERFACE_UUID("{631D4C30-8543-4A08-A50E-9ABA2FA7EF33}") IdxPopupControl  : public System::IInterface 
{
	virtual Vcl::Controls::TWinControl* __fastcall GetOwnerControl() = 0 ;
};

__interface  INTERFACE_UUID("{F137963E-6165-47F9-A4C7-96BB4EB91AE0}") IdxSystemInfoListener  : public System::IInterface 
{
	virtual void __fastcall Changed(unsigned AParameter) = 0 ;
};

__interface  INTERFACE_UUID("{ACB73657-6066-4564-9A3D-D4D0273AA82F}") IcxMouseCaptureObject  : public System::IInterface 
{
	virtual void __fastcall DoCancelMode() = 0 ;
};

__interface  INTERFACE_UUID("{A4A77F28-1D03-425B-9A83-0B853B5D8DEF}") IcxCompoundControl  : public System::IInterface 
{
	virtual Vcl::Controls::TWinControl* __fastcall GetActiveControl() = 0 ;
	__property Vcl::Controls::TWinControl* ActiveControl = {read=GetActiveControl};
};

__interface  INTERFACE_UUID("{E29BF582-E8C0-4868-A799-DB4C41AC3BC8}") IcxControlComponentState  : public System::IInterface 
{
	virtual bool __fastcall IsDesigning() = 0 ;
	virtual bool __fastcall IsDestroying() = 0 ;
	virtual bool __fastcall IsLoading() = 0 ;
};

__interface  INTERFACE_UUID("{61EEDA7D-88CC-45BF-8A00-5C25174D6501}") IcxPopupMenu  : public System::IInterface 
{
	virtual bool __fastcall IsShortCutKey(Winapi::Messages::TWMKey &Message) = 0 ;
	virtual void __fastcall Popup(int X, int Y) = 0 ;
};

__interface  INTERFACE_UUID("{E6DC09CE-3252-457B-B6D2-09D8335C2DED}") IcxPopupMenu2  : public IcxPopupMenu 
{
	HIDESBASE virtual void __fastcall Popup(int X, int Y, const System::Types::TRect &AOwnerBounds, Vcl::Menus::TPopupAlignment APopupAlignment) = 0 ;
};

__interface  INTERFACE_UUID("{F4980C69-029E-4B14-B3AD-953DA5C18BE7}") IcxTransparentControl  : public System::IInterface 
{
	virtual bool __fastcall IsTransparentRegionsPresent() = 0 ;
};

__interface  INTERFACE_UUID("{DEA877D7-1646-477A-A722-818DFE41EE47}") IdxPlaceForm  : public System::IInterface 
{
	
};

__interface  INTERFACE_UUID("{09028781-0230-48C9-A8D3-02FD987F872B}") IdxDialogOwner  : public System::IInterface 
{
	virtual Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeel() = 0 ;
	virtual System::Classes::TComponent* __fastcall GetOwner() = 0 ;
	virtual Vcl::Forms::TCustomForm* __fastcall GetParentForm() = 0 ;
};

__interface  INTERFACE_UUID("{9B9F932E-4E46-4BBB-B532-503F739A4559}") IdxNavigationItem  : public System::IInterface 
{
	virtual int __fastcall GetID() = 0 ;
	virtual System::UnicodeString __fastcall GetText() = 0 ;
	virtual System::Uitypes::TImageIndex __fastcall GetImageIndex() = 0 ;
	__property int ID = {read=GetID};
	__property System::UnicodeString Text = {read=GetText};
	__property System::Uitypes::TImageIndex ImageIndex = {read=GetImageIndex};
};

__interface  INTERFACE_UUID("{54AC756F-768D-46CD-84BF-8E6C49D2ABAF}") IdxNavigationClientListener  : public System::IInterface 
{
	virtual void __fastcall ItemsChanged() = 0 ;
	virtual void __fastcall SelectionChanged() = 0 ;
};

__interface  INTERFACE_UUID("{2DB4C89E-A411-4D9E-904D-87898439B315}") IdxNavigationClient  : public System::IInterface 
{
	virtual System::DelphiInterface<System::IEnumerable__1<_di_IdxNavigationItem> > __fastcall GetItems() = 0 ;
	virtual void __fastcall SetSelectedItem(_di_IdxNavigationItem AItem) = 0 ;
	virtual _di_IdxNavigationItem __fastcall GetSelectedItem() = 0 ;
	virtual void __fastcall AddListener(_di_IdxNavigationClientListener AListener) = 0 ;
	virtual void __fastcall RemoveListener(_di_IdxNavigationClientListener AListener) = 0 ;
	__property _di_IdxNavigationItem SelectedItem = {read=GetSelectedItem, write=SetSelectedItem};
};

__interface  INTERFACE_UUID("{CA4C2043-1558-4D5D-8DEB-DAD8652AFFB9}") IdxTouchScrollUIOwner  : public System::IInterface 
{
	virtual void __fastcall CheckUIPosition() = 0 ;
	virtual TcxControl* __fastcall GetOwnerControl() = 0 ;
	virtual bool __fastcall HasVisibleUI() = 0 ;
	virtual void __fastcall HideUI() = 0 ;
};

__interface  INTERFACE_UUID("{2DFA6D14-84FD-42EE-AF0C-CB418ABCA905}") IdxHybridScrollbarOwner  : public IdxTouchScrollUIOwner 
{
	virtual System::Uitypes::TColor __fastcall GetBaseColor() = 0 ;
	virtual TdxHybridScrollbarsManager* __fastcall GetManager() = 0 ;
	virtual void __fastcall Invalidate() = 0 ;
};

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxApplicationActivateWindowHelper : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Dxcoreclasses::TcxFreeNotificator* FFreeNotificator;
	System::Classes::TList* FWindowsList;
	Dxcoreclasses::TcxFreeNotificator* __fastcall GetFreeNotificator();
	void __fastcall FreeNotificationHandler(System::Classes::TComponent* Sender);
	bool __fastcall IsFormShowedBeforeLastModalWindow(Vcl::Forms::TCustomForm* AForm);
	bool __fastcall NeedNormalize(Vcl::Forms::TCustomForm* AForm);
	void __fastcall NormalizeFocusedWindow();
	void __fastcall NormalizeRegisteredWindows();
	__property Dxcoreclasses::TcxFreeNotificator* FreeNotificator = {read=GetFreeNotificator};
	
protected:
	__property System::Classes::TList* WindowsList = {read=FWindowsList};
	
public:
	__fastcall TdxApplicationActivateWindowHelper();
	__fastcall virtual ~TdxApplicationActivateWindowHelper();
	void __fastcall AddWindow(Vcl::Forms::TCustomForm* AForm);
	void __fastcall NormalizeTopMostWindows(Vcl::Forms::TCustomForm* AForm);
	void __fastcall RemoveWindow(Vcl::Forms::TCustomForm* AForm);
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxControlChildComponent : public Cxclasses::TcxComponent
{
	typedef Cxclasses::TcxComponent inherited;
	
private:
	TcxControl* FControl;
	Cxgeometry::TdxOwnedScaleFactor* FScaleFactor;
	HIDESBASE bool __fastcall GetIsLoading();
	void __fastcall ScaleFactorChangeHandler(System::TObject* Sender, int M, int D, bool IsLoading);
	Cxgeometry::TdxScaleFactor* __fastcall GetScaleFactor();
	
protected:
	HIDESBASE virtual bool __fastcall GetIsDestroying();
	virtual void __fastcall Initialize();
	virtual void __fastcall ScaleFactorChanged(int M, int D);
	virtual void __fastcall SetControl(TcxControl* Value);
	__property Cxgeometry::TdxOwnedScaleFactor* ScaleFactor = {read=FScaleFactor};
	
public:
	__fastcall virtual TcxControlChildComponent(System::Classes::TComponent* AOwner);
	__fastcall virtual TcxControlChildComponent(TcxControl* AControl, bool AAssignOwner);
	__fastcall virtual ~TcxControlChildComponent();
	DYNAMIC System::Classes::TComponent* __fastcall GetParentComponent();
	DYNAMIC bool __fastcall HasParent();
	DYNAMIC void __fastcall SetParentComponent(System::Classes::TComponent* Value);
	__property TcxControl* Control = {read=FControl, write=SetControl};
	__property bool IsDestroying = {read=GetIsDestroying, nodefault};
	__property bool IsLoading = {read=GetIsLoading, nodefault};
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
class PASCALIMPLEMENTATION TcxScrollBarData : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FAllowHide;
	bool FAllowShow;
	bool FEnabled;
	bool FIsValid;
	Vcl::Forms::TScrollBarInc FLargeChange;
	int FMin;
	int FMax;
	int FPosition;
	int FPageSize;
	Vcl::Forms::TScrollBarInc FSmallChange;
	bool FVisible;
	
protected:
	void __fastcall Validate();
	
public:
	__property bool AllowHide = {read=FAllowHide, write=FAllowHide, nodefault};
	__property bool AllowShow = {read=FAllowShow, write=FAllowShow, nodefault};
	__property bool Enabled = {read=FEnabled, write=FEnabled, nodefault};
	__property bool IsValid = {read=FIsValid, nodefault};
	__property Vcl::Forms::TScrollBarInc LargeChange = {read=FLargeChange, write=FLargeChange, nodefault};
	__property int Min = {read=FMin, write=FMin, nodefault};
	__property int Max = {read=FMax, write=FMax, nodefault};
	__property int Position = {read=FPosition, write=FPosition, nodefault};
	__property int PageSize = {read=FPageSize, write=FPageSize, nodefault};
	__property Vcl::Forms::TScrollBarInc SmallChange = {read=FSmallChange, write=FSmallChange, nodefault};
	__property bool Visible = {read=FVisible, write=FVisible, nodefault};
public:
	/* TObject.Create */ inline __fastcall TcxScrollBarData() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxScrollBarData() { }
	
};

#pragma pack(pop)

__interface  INTERFACE_UUID("{D70735C6-82E8-4D17-AE14-9317D2A11D0C}") IcxControlScrollBar  : public System::IInterface 
{
	virtual void __fastcall ApplyData() = 0 ;
	virtual TcxControlScrollBar* __fastcall GetControl() = 0 ;
	virtual System::Types::TRect __fastcall GetBoundsRect() = 0 ;
	virtual TcxScrollBarData* __fastcall GetData() = 0 ;
	virtual bool __fastcall GetEnabled() = 0 ;
	virtual int __fastcall GetHeight() = 0 ;
	virtual Vcl::Forms::TScrollBarKind __fastcall GetKind() = 0 ;
	virtual Vcl::Forms::TScrollBarInc __fastcall GetLargeChange() = 0 ;
	virtual int __fastcall GetLeft() = 0 ;
	virtual int __fastcall GetMax() = 0 ;
	virtual int __fastcall GetMin() = 0 ;
	virtual int __fastcall GetPageSize() = 0 ;
	virtual int __fastcall GetPosition() = 0 ;
	virtual Vcl::Forms::TScrollBarInc __fastcall GetSmallChange() = 0 ;
	virtual int __fastcall GetTop() = 0 ;
	virtual bool __fastcall GetUnlimitedTracking() = 0 ;
	virtual bool __fastcall GetVisible() = 0 ;
	virtual int __fastcall GetWidth() = 0 ;
	virtual void __fastcall SetBoundsRect(const System::Types::TRect &AValue) = 0 ;
	virtual void __fastcall SetEnabled(bool AValue) = 0 ;
	virtual void __fastcall SetHeight(int AValue) = 0 ;
	virtual void __fastcall SetKind(Vcl::Forms::TScrollBarKind AValue) = 0 ;
	virtual void __fastcall SetLargeChange(Vcl::Forms::TScrollBarInc AValue) = 0 ;
	virtual void __fastcall SetLeft(int AValue) = 0 ;
	virtual void __fastcall SetMax(int AValue) = 0 ;
	virtual void __fastcall SetMin(int AValue) = 0 ;
	virtual void __fastcall SetPageSize(int AValue) = 0 ;
	virtual void __fastcall SetPosition(int AValue) = 0 ;
	virtual void __fastcall SetScrollParams(int AMin, int AMax, int APosition, int APageSize, bool ARedraw = true) = 0 ;
	virtual void __fastcall SetSmallChange(Vcl::Forms::TScrollBarInc AValue) = 0 ;
	virtual void __fastcall SetTop(int AValue) = 0 ;
	virtual void __fastcall SetUnlimitedTracking(bool AValue) = 0 ;
	virtual void __fastcall SetVisible(bool AValue) = 0 ;
	virtual void __fastcall SetWidth(int AValue) = 0 ;
	__property System::Types::TRect BoundsRect = {read=GetBoundsRect, write=SetBoundsRect};
	__property TcxControlScrollBar* Control = {read=GetControl};
	__property TcxScrollBarData* Data = {read=GetData};
	__property bool Enabled = {read=GetEnabled, write=SetEnabled};
	__property int Height = {read=GetHeight, write=SetHeight};
	__property Vcl::Forms::TScrollBarKind Kind = {read=GetKind, write=SetKind};
	__property Vcl::Forms::TScrollBarInc LargeChange = {read=GetLargeChange, write=SetLargeChange};
	__property int Left = {read=GetLeft, write=SetLeft};
	__property int Max = {read=GetMax, write=SetMax};
	__property int Min = {read=GetMin, write=SetMin};
	__property int PageSize = {read=GetPageSize, write=SetPageSize};
	__property int Position = {read=GetPosition, write=SetPosition};
	__property Vcl::Forms::TScrollBarInc SmallChange = {read=GetSmallChange, write=SetSmallChange};
	__property int Top = {read=GetTop, write=SetTop};
	__property bool UnlimitedTracking = {read=GetUnlimitedTracking, write=SetUnlimitedTracking};
	__property bool Visible = {read=GetVisible, write=SetVisible};
	__property int Width = {read=GetWidth, write=SetWidth};
};

class PASCALIMPLEMENTATION TcxControlScrollBar : public Cxscrollbar::TcxScrollBar
{
	typedef Cxscrollbar::TcxScrollBar inherited;
	
private:
	TcxScrollBarData* FData;
	HIDESBASE MESSAGE void __fastcall CMDesignHitTest(Winapi::Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall CMHintShow(Vcl::Controls::TCMHintShow &Message);
	
protected:
	TcxControl* OwnerControl;
	virtual void __fastcall CreateHandle();
	virtual void __fastcall DoPaint(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DoWndProc(Winapi::Messages::TMessage &Message);
	virtual void __fastcall FocusParent();
	virtual void __fastcall InitControl();
	virtual void __fastcall InternalSetOwnerControlRelativeBounds(const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleBounds);
	virtual bool __fastcall IsActuallyVisible();
	DYNAMIC void __fastcall SetZOrder(bool TopMost);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	
public:
	__fastcall virtual TcxControlScrollBar(System::Classes::TComponent* AOwner);
	__fastcall virtual TcxControlScrollBar(System::TObject* AOwner);
	__fastcall virtual ~TcxControlScrollBar();
	virtual void __fastcall ApplyData();
	HIDESBASE System::Types::TRect __fastcall GetBoundsRect();
	HIDESBASE TcxControlScrollBar* __fastcall GetControl();
	TcxScrollBarData* __fastcall GetData();
	int __fastcall GetHeight();
	int __fastcall GetLeft();
	int __fastcall GetTop();
	bool __fastcall GetVisible();
	int __fastcall GetWidth();
	HIDESBASE void __fastcall SetBoundsRect(const System::Types::TRect &AValue);
	HIDESBASE void __fastcall SetHeight(int AValue);
	HIDESBASE void __fastcall SetLeft(int AValue);
	virtual void __fastcall SetOwnerControlRelativeBounds(const System::Types::TRect &ABounds);
	HIDESBASE void __fastcall SetTop(int AValue);
	HIDESBASE virtual void __fastcall SetVisible(bool AValue);
	HIDESBASE void __fastcall SetWidth(int AValue);
	__property TcxControlScrollBar* Control = {read=GetControl};
	__property bool Visible = {read=GetVisible, write=SetVisible, nodefault};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxControlScrollBar(HWND ParentWindow) : Cxscrollbar::TcxScrollBar(ParentWindow) { }
	
private:
	void *__IcxControlScrollBar;	// IcxControlScrollBar 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {D70735C6-82E8-4D17-AE14-9317D2A11D0C}
	operator _di_IcxControlScrollBar()
	{
		_di_IcxControlScrollBar intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IcxControlScrollBar*(void) { return (IcxControlScrollBar*)&__IcxControlScrollBar; }
	#endif
	
};


typedef System::TMetaClass* TcxControlScrollBarClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPopupScrollBarViewInfo : public Cxscrollbar::TcxScrollBarViewInfo
{
	typedef Cxscrollbar::TcxScrollBarViewInfo inherited;
	
protected:
	virtual int __fastcall GetArrowButtonLength();
public:
	/* TcxScrollBarViewInfo.Create */ inline __fastcall virtual TcxPopupScrollBarViewInfo(Cxscrollbar::TcxScrollBarHelper* AScrollBar) : Cxscrollbar::TcxScrollBarViewInfo(AScrollBar) { }
	/* TcxScrollBarViewInfo.Destroy */ inline __fastcall virtual ~TcxPopupScrollBarViewInfo() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPopupScrollBarPainter : public Cxscrollbar::TcxScrollBarPainter
{
	typedef Cxscrollbar::TcxScrollBarPainter inherited;
	
protected:
	virtual void __fastcall DoDrawScrollBarPart(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxScrollBarPart APart, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawScrollBarBackground(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R);
	virtual bool __fastcall FadingAvailable();
	
public:
	virtual bool __fastcall IsButtonHotTrack();
public:
	/* TcxScrollBarPainter.Create */ inline __fastcall virtual TcxPopupScrollBarPainter(Cxscrollbar::TcxScrollBarHelper* AScrollBar) : Cxscrollbar::TcxScrollBarPainter(AScrollBar) { }
	/* TcxScrollBarPainter.Destroy */ inline __fastcall virtual ~TcxPopupScrollBarPainter() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxHybridScrollBarPainter : public Cxscrollbar::TcxScrollBarPainter
{
	typedef Cxscrollbar::TcxScrollBarPainter inherited;
	
private:
	void __fastcall DrawArrowButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxScrollBarPart APart, Cxlookandfeelpainters::TcxButtonState AState);
	void __fastcall DrawThumb(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxScrollBarPart APart, Cxlookandfeelpainters::TcxButtonState AState);
	System::Uitypes::TColor __fastcall GetBaseColor();
	_di_IdxHybridScrollbarOwner __fastcall GetHybridScrollbarOwner();
	int __fastcall GetVisibleSize();
	bool __fastcall IsActive();
	bool __fastcall IsRightToLeft();
	
protected:
	virtual void __fastcall DoDrawScrollbarAnnotations(Cxcustomcanvas::TcxCustomCanvas* ACanvas);
	virtual void __fastcall DoDrawScrollBarPart(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxScrollBarPart APart, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawScrollBarBackground(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R);
	virtual bool __fastcall FadingAvailable();
	
public:
	virtual bool __fastcall IsButtonHotTrack();
public:
	/* TcxScrollBarPainter.Create */ inline __fastcall virtual TdxHybridScrollBarPainter(Cxscrollbar::TcxScrollBarHelper* AScrollBar) : Cxscrollbar::TcxScrollBarPainter(AScrollBar) { }
	/* TcxScrollBarPainter.Destroy */ inline __fastcall virtual ~TdxHybridScrollBarPainter() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxCustomPopupScrollBarHelper : public Cxscrollbar::TcxScrollBarHelper
{
	typedef Cxscrollbar::TcxScrollBarHelper inherited;
	
protected:
	virtual void __fastcall InvalidateRect(const System::Types::TRect &ARect, bool AEraseBackground = false);
	virtual bool __fastcall NeedBuffering();
public:
	/* TcxScrollBarHelper.Create */ inline __fastcall virtual TcxCustomPopupScrollBarHelper(Cxscrollbar::_di_IcxScrollBarOwner AOwner) : Cxscrollbar::TcxScrollBarHelper(AOwner) { }
	/* TcxScrollBarHelper.Destroy */ inline __fastcall virtual ~TcxCustomPopupScrollBarHelper() { }
	
};


class PASCALIMPLEMENTATION TcxPopupScrollBarHelper : public TcxCustomPopupScrollBarHelper
{
	typedef TcxCustomPopupScrollBarHelper inherited;
	
protected:
	virtual Cxscrollbar::TcxScrollBarPainterClass __fastcall GetPainterClass();
	virtual System::Types::TSize __fastcall GetScrollBarSize();
	virtual Cxscrollbar::TcxScrollBarViewInfoClass __fastcall GetViewInfoClass();
public:
	/* TcxScrollBarHelper.Create */ inline __fastcall virtual TcxPopupScrollBarHelper(Cxscrollbar::_di_IcxScrollBarOwner AOwner) : TcxCustomPopupScrollBarHelper(AOwner) { }
	/* TcxScrollBarHelper.Destroy */ inline __fastcall virtual ~TcxPopupScrollBarHelper() { }
	
};


class PASCALIMPLEMENTATION TdxHybridScrollBarHelper : public TcxCustomPopupScrollBarHelper
{
	typedef TcxCustomPopupScrollBarHelper inherited;
	
protected:
	virtual Cxscrollbar::TcxScrollBarPainterClass __fastcall GetPainterClass();
	virtual System::Types::TSize __fastcall GetScrollBarSize();
public:
	/* TcxScrollBarHelper.Create */ inline __fastcall virtual TdxHybridScrollBarHelper(Cxscrollbar::_di_IcxScrollBarOwner AOwner) : TcxCustomPopupScrollBarHelper(AOwner) { }
	/* TcxScrollBarHelper.Destroy */ inline __fastcall virtual ~TdxHybridScrollBarHelper() { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTouchScrollUIActivityHelper : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Types::TPoint FLastMousePos;
	bool FMouseEnter;
	
public:
	bool __fastcall CheckScrollActivity(Vcl::Controls::TWinControl* AControl, Winapi::Messages::TMessage &Message);
public:
	/* TObject.Create */ inline __fastcall TdxTouchScrollUIActivityHelper() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxTouchScrollUIActivityHelper() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTouchScrollUIModeManager : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	static System::TObject* FActiveScrollUIOwner;
	static int FHidingLockCount;
	static Cxclasses::TcxTimer* FHidingTimer;
	static bool FLockOwner;
	static bool FScrollInfoAllowVisible;
	// __classmethod void __fastcall Finalize@();
	__classmethod void __fastcall Activate(_di_IdxTouchScrollUIOwner AValue);
	__classmethod _di_IdxTouchScrollUIOwner __fastcall ActiveScrollUIOwner();
	__classmethod void __fastcall DoHideTouchScrollUI(bool AImmediately);
	__classmethod void __fastcall HidingTimerHandler(System::TObject* ASender);
	__classmethod void __fastcall LockHiding();
	__classmethod void __fastcall StartHidingTimer();
	__classmethod void __fastcall StopHidingTimer();
	__classmethod void __fastcall UnlockHiding();
	
protected:
	__classmethod void __fastcall CheckUIPosition(HWND AChangedWnd, bool ACheckChangedWnd = false, bool ACheckChilds = true);
	__classmethod void __fastcall CheckUIVisibility(HWND AChangedWnd);
	__classmethod bool __fastcall IsActive(_di_IdxTouchScrollUIOwner AUIOwner);
	__classmethod void __fastcall LockOwner();
	__classmethod void __fastcall UnlockOwner();
	
public:
	__classmethod void __fastcall Deactivate(_di_IdxTouchScrollUIOwner AUIOwner);
	__classmethod void __fastcall HideActive();
	__classmethod void __fastcall HideScrollUI(_di_IdxTouchScrollUIOwner AUIOwner, bool AImmediately);
	__classmethod bool __fastcall IsScrollUIHidden(_di_IdxTouchScrollUIOwner AUIOwner);
	__classmethod void __fastcall ShowScrollUI(_di_IdxTouchScrollUIOwner AUIOwner, bool AControlledByTimer);
	
private:
	// __classmethod void __fastcall Create@();
public:
	/* TObject.Create */ inline __fastcall TdxTouchScrollUIModeManager() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxTouchScrollUIModeManager() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxHybridScrollbarsManager : public System::TObject
{
	typedef System::TObject inherited;
	
	
private:
	enum DECLSPEC_DENUM TExpandState : unsigned char { estNone, estExpanding, estCollapsing };
	
	enum DECLSPEC_DENUM TFadingState : unsigned char { fstNone, fstShowing, fstHiding };
	
	
private:
	static const System::Byte MaxFadingValue = System::Byte(0xff);
	
	static const System::Int8 MaxVisibleSize = System::Int8(0x64);
	
	TFadingState FFadingState;
	Dxanimation::TdxAnimationTransition* FFadingAnimation;
	System::Byte FFadingValue;
	System::Byte FStartFadingValue;
	TExpandState FExpandState;
	Dxanimation::TdxAnimationTransition* FSizeAnimation;
	Cxclasses::TcxTimer* FCollapsingTimer;
	int FExpandLockCount;
	int FStartSize;
	int FVisibleSize;
	bool FAllowVisible;
	System::TObject* FAnimateObject;
	int FHidingLockCount;
	Cxclasses::TcxTimer* FHidingTimer;
	bool FIsDeactivating;
	System::TObject* FOwner;
	void __fastcall CheckStartHidingTimer();
	void __fastcall DoHide(bool AAnimated);
	_di_IdxHybridScrollbarOwner __fastcall GetScrollbarsOwner();
	void __fastcall Invalidate();
	void __fastcall HidingTimerHandler(System::TObject* ASender);
	void __fastcall StartHidingTimer();
	void __fastcall StopHidingTimer();
	bool __fastcall UseAnimation();
	void __fastcall FadeOut();
	void __fastcall FadeIn();
	void __fastcall DoFadingAnimate(Dxanimation::TdxAnimationTransition* Sender, int &APosition, bool &AFinished);
	void __fastcall DoFadingAnimationTerminate(System::TObject* Sender);
	void __fastcall StartFadingAnimation(TFadingState AState);
	void __fastcall StopFadingAnimation();
	void __fastcall DoAfterCollapse();
	void __fastcall DoAfterExpand();
	void __fastcall DoExpand();
	void __fastcall DoCollapse();
	void __fastcall DoSizeAnimate(Dxanimation::TdxAnimationTransition* Sender, int &APosition, bool &AFinished);
	void __fastcall DoSizeAnimationTerminate(System::TObject* Sender);
	void __fastcall SizeChangingTimerHandler(System::TObject* ASender);
	void __fastcall StartSizeAnimation(TExpandState AState);
	void __fastcall StartSizeChangingTimer();
	void __fastcall StopSizeAnimation();
	void __fastcall StopSizeChangingTimer();
	bool __fastcall IsWaitingForCollapse();
	bool __fastcall IsWaitingForHide();
	
protected:
	void __fastcall Collapse();
	void __fastcall Deactivate();
	void __fastcall Expand(System::TObject* AAnimateObject);
	System::Byte __fastcall GetFadingValue();
	int __fastcall GetVisibleSize();
	bool __fastcall IsActive(System::TObject* AScrollbar);
	void __fastcall ScrollbarHiding(System::TObject* AScrollbar);
	void __fastcall ResetSize();
	void __fastcall CheckScrollbarsPosition(HWND AChangedWnd, bool ACheckChangedWnd = false, bool ACheckChilds = true);
	void __fastcall CheckScrollbarsVisibility(HWND AChangedWnd);
	
public:
	__fastcall TdxHybridScrollbarsManager(System::TObject* AOwner);
	__fastcall virtual ~TdxHybridScrollbarsManager();
	void __fastcall Hide(bool AImmediately, bool AAnimated);
	void __fastcall Show(bool AHideByTimer);
	__property bool AllowVisible = {read=FAllowVisible, nodefault};
	__property _di_IdxHybridScrollbarOwner ScrollbarsOwner = {read=GetScrollbarsOwner};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxHybridScrollbarManagers : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	static System::Generics::Collections::TList__1<TdxHybridScrollbarsManager*>* FItems;
	// __classmethod void __fastcall Initialize@();
	// __classmethod void __fastcall Finalize@();
	
protected:
	__classmethod void __fastcall CheckScrollbarsPosition(HWND AChangedWnd, bool ACheckChangedWnd = false, bool ACheckChilds = true);
	__classmethod void __fastcall CheckScrollbarsVisibility(HWND AChangedWnd);
	
public:
	__classmethod void __fastcall Activate(TdxHybridScrollbarsManager* AManager);
	__classmethod void __fastcall Deactivate(TdxHybridScrollbarsManager* AManager);
	__classmethod void __fastcall HideAll();
	__classmethod bool __fastcall IsActive(TdxHybridScrollbarsManager* AManager);
public:
	/* TObject.Create */ inline __fastcall TdxHybridScrollbarManagers() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxHybridScrollbarManagers() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxControlPopupScrollBar : public TcxControlScrollBar
{
	typedef TcxControlScrollBar inherited;
	
private:
	TdxTouchScrollUIActivityHelper* FActivityHelper;
	System::Byte FAlpha;
	bool FAllowVisible;
	bool FMouseEnter;
	System::TObject* FScrollbarOwner;
	Cxscrollbar::_di_IcxScrollBarOwner2 FScrollbarOwner2;
	int FVisibleSize;
	int __fastcall GetMaxVisibleSize();
	int __fastcall GetMinVisibleSize();
	HIDESBASE MESSAGE void __fastcall WMMouseActivate(Winapi::Messages::TWMMouseActivate &Message);
	
private:
	void __fastcall UpdateLayer();
	
protected:
	Vcl::Controls::TWinControl* __fastcall GetOwnerControl();
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall DestroyWnd();
	DYNAMIC bool __fastcall DoMouseWheel(System::Classes::TShiftState Shift, int WheelDelta, const System::Types::TPoint &MousePos);
	virtual void __fastcall DoPaint(Cxgraphics::TcxCanvas* ACanvas);
	virtual System::Types::TSize __fastcall GetInitialSize();
	virtual Cxscrollbar::TcxScrollBarHelperClass __fastcall GetHelperClass();
	_di_IdxTouchScrollUIOwner __fastcall GetScrollbarOwner();
	_di_IdxHybridScrollbarOwner __fastcall GetHybridScrollbarOwner();
	virtual void __fastcall InitControl();
	virtual void __fastcall InternalSetOwnerControlRelativeBounds(const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleBounds);
	virtual bool __fastcall IsActuallyVisible();
	DYNAMIC void __fastcall Resize();
	virtual void __fastcall DoWndProc(Winapi::Messages::TMessage &Message);
	__property bool AllowVisible = {read=FAllowVisible, nodefault};
	__property int VisibleSize = {read=FVisibleSize, nodefault};
	
public:
	__fastcall virtual TcxControlPopupScrollBar(System::TObject* AOwner);
	__fastcall virtual ~TcxControlPopupScrollBar();
	virtual void __fastcall ApplyData();
	virtual void __fastcall SetVisible(bool AValue);
	virtual void __fastcall Invalidate();
	virtual void __fastcall SetOwnerControlRelativeBounds(const System::Types::TRect &ABounds);
public:
	/* TcxControlScrollBar.Create */ inline __fastcall virtual TcxControlPopupScrollBar(System::Classes::TComponent* AOwner) : TcxControlScrollBar(AOwner) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxControlPopupScrollBar(HWND ParentWindow) : TcxControlScrollBar(ParentWindow) { }
	
private:
	void *__IdxPopupControl;	// IdxPopupControl 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {631D4C30-8543-4A08-A50E-9ABA2FA7EF33}
	operator _di_IdxPopupControl()
	{
		_di_IdxPopupControl intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IdxPopupControl*(void) { return (IdxPopupControl*)&__IdxPopupControl; }
	#endif
	
};


typedef System::TMetaClass* TcxControlPopupScrollBarClass;

class PASCALIMPLEMENTATION TcxControlScrollBarHelper : public Cxscrollbar::TcxScrollBarHelper
{
	typedef Cxscrollbar::TcxScrollBarHelper inherited;
	
private:
	TcxScrollBarData* FData;
	
protected:
	void __fastcall InternalSetOwnerControlRelativeBounds(const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleBounds);
	void __fastcall SetOwnerFocusByMouse();
	
public:
	__fastcall virtual TcxControlScrollBarHelper(Cxscrollbar::_di_IcxScrollBarOwner AOwner);
	__fastcall virtual ~TcxControlScrollBarHelper();
	virtual void __fastcall Repaint();
	void __fastcall SetOwnerControlRelativeBounds(const System::Types::TRect &ABounds);
	void __fastcall ApplyData();
	TcxControlScrollBar* __fastcall GetControl();
	TcxScrollBarData* __fastcall GetData();
	int __fastcall GetHeight();
	int __fastcall GetLeft();
	int __fastcall GetTop();
	int __fastcall GetWidth();
	void __fastcall SetHeight(int Value);
	void __fastcall SetLeft(int Value);
	void __fastcall SetTop(int Value);
	void __fastcall SetWidth(int Value);
	__property TcxControlScrollBar* Control = {read=GetControl};
	__property int Left = {read=GetLeft, write=SetLeft, nodefault};
	__property int Top = {read=GetTop, write=SetTop, nodefault};
	__property int Height = {read=GetHeight, write=SetHeight, nodefault};
	__property int Width = {read=GetWidth, write=SetWidth, nodefault};
private:
	void *__IcxControlScrollBar;	// IcxControlScrollBar 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {D70735C6-82E8-4D17-AE14-9317D2A11D0C}
	operator _di_IcxControlScrollBar()
	{
		_di_IcxControlScrollBar intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IcxControlScrollBar*(void) { return (IcxControlScrollBar*)&__IcxControlScrollBar; }
	#endif
	
};


typedef System::TMetaClass* TcxControlScrollBarHelperClass;

typedef System::TMetaClass* TcxSizeGripClass;

class PASCALIMPLEMENTATION TcxSizeGrip : public Vcl::Controls::TCustomControl
{
	typedef Vcl::Controls::TCustomControl inherited;
	
private:
	TcxControl* FOwnerControl;
	Cxlookandfeels::TcxLookAndFeel* FLookAndFeel;
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Winapi::Messages::TWMEraseBkgnd &AMessage);
	
protected:
	virtual void __fastcall CreateHandle();
	virtual void __fastcall Draw(Vcl::Graphics::TCanvas* ACanvas);
	virtual void __fastcall InitControl();
	void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	virtual void __fastcall Paint();
	DYNAMIC void __fastcall SetZOrder(bool TopMost);
	__property TcxControl* OwnerControl = {read=FOwnerControl};
	
public:
	__fastcall virtual TcxSizeGrip(System::Classes::TComponent* AOwner);
	__fastcall virtual TcxSizeGrip(System::TObject* AOwner);
	__fastcall virtual ~TcxSizeGrip();
	__classmethod bool __fastcall IsAvailable(Vcl::Controls::TWinControl* AStatusBar);
	virtual void __fastcall SetOwnerControlRelativeBounds(const System::Types::TRect &ABounds);
	__property Cxlookandfeels::TcxLookAndFeel* LookAndFeel = {read=FLookAndFeel};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxSizeGrip(HWND ParentWindow) : Vcl::Controls::TCustomControl(ParentWindow) { }
	
};


class PASCALIMPLEMENTATION TcxPopupSizeGrip : public TcxSizeGrip
{
	typedef TcxSizeGrip inherited;
	
private:
	System::TObject* FScrollbarOwner;
	Cxscrollbar::_di_IcxScrollBarOwner2 FScrollbarOwner2;
	HIDESBASE MESSAGE void __fastcall WMMouseActivate(Winapi::Messages::TWMMouseActivate &Message);
	
protected:
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall CreateWindowHandle(const Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall Draw(Vcl::Graphics::TCanvas* ACanvas);
	_di_IdxHybridScrollbarOwner __fastcall GetHybridScrollbarOwner();
	_di_IdxTouchScrollUIOwner __fastcall GetScrollbarOwner();
	virtual void __fastcall InitControl();
	
public:
	__fastcall virtual TcxPopupSizeGrip(System::TObject* AOwner);
	virtual void __fastcall SetOwnerControlRelativeBounds(const System::Types::TRect &ABounds);
public:
	/* TcxSizeGrip.Create */ inline __fastcall virtual TcxPopupSizeGrip(System::Classes::TComponent* AOwner) : TcxSizeGrip(AOwner) { }
	/* TcxSizeGrip.Destroy */ inline __fastcall virtual ~TcxPopupSizeGrip() { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxPopupSizeGrip(HWND ParentWindow) : TcxSizeGrip(ParentWindow) { }
	
};


typedef System::TMetaClass* TcxSizeGripHelperClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSizeGripHelper : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Types::TRect FBoundsRect;
	bool FIsNonClient;
	Cxscrollbar::_di_IcxScrollBarOwner FOwner;
	bool FVisible;
	void __fastcall RefreshNCPart(const System::Types::TRect &ARect);
	
protected:
	__property Cxscrollbar::_di_IcxScrollBarOwner Owner = {read=FOwner};
	
public:
	__fastcall virtual TcxSizeGripHelper(Cxscrollbar::_di_IcxScrollBarOwner AOwner);
	virtual void __fastcall Paint(Cxcustomcanvas::TcxCustomCanvas* ACanvas);
	virtual void __fastcall Repaint();
	__property System::Types::TRect BoundsRect = {read=FBoundsRect, write=FBoundsRect};
	__property bool IsNonClient = {read=FIsNonClient, write=FIsNonClient, nodefault};
	__property bool Visible = {read=FVisible, write=FVisible, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSizeGripHelper() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxControlScrollBarsManager : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	Cxclasses::TcxTimer* FCheckCaptureTimer;
	bool FIsCapture;
	TcxControlScrollBarHelper* FHotScrollBar;
	TcxControl* FOwner;
	System::Classes::TList* FScrollBars;
	void __fastcall CheckCaptureTimerHandler(System::TObject* ASender);
	TcxControlScrollBarHelper* __fastcall GetScrollBarAtPos(const System::Types::TPoint &APoint);
	TcxControlScrollBarHelper* __fastcall GetScrollBars(int AIndex);
	bool __fastcall IsMouseButtonDown();
	bool __fastcall IsScrollBarVisible(TcxControlScrollBarHelper* AScrollBar);
	void __fastcall SetHotScrollBar(TcxControlScrollBarHelper* AValue);
	void __fastcall SetIsCapture(bool AValue);
	
protected:
	virtual bool __fastcall ProcessMouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual bool __fastcall ProcessMouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual bool __fastcall ProcessMouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall MouseLeave();
	bool __fastcall PtInCaller(const System::Types::TPoint &P);
	bool __fastcall IsCaptureMouse();
	__property TcxControlScrollBarHelper* HotScrollBar = {read=FHotScrollBar, write=SetHotScrollBar};
	__property TcxControlScrollBarHelper* ScrollBars[int Index] = {read=GetScrollBars};
	
public:
	__fastcall virtual TcxControlScrollBarsManager(TcxControl* AOwner);
	__fastcall virtual ~TcxControlScrollBarsManager();
	virtual bool __fastcall HandleMessage(Winapi::Messages::TMessage &Message);
	virtual bool __fastcall IsScrollBarsArea(const System::Types::TPoint &APoint);
	virtual void __fastcall Paint(Cxcustomcanvas::TcxCustomCanvas* ACanvas);
	void __fastcall RegisterScrollBar(TcxControlScrollBarHelper* AScrollBar);
	void __fastcall UnRegisterScrollBar(TcxControlScrollBarHelper* AScrollBar);
	__property bool IsCapture = {read=FIsCapture, write=SetIsCapture, nodefault};
private:
	void *__IcxMouseTrackingCaller3;	// Dxcoreclasses::IcxMouseTrackingCaller3 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {94877AC7-D2D8-4F2B-8396-DF3CB45E01DF}
	operator Dxcoreclasses::_di_IcxMouseTrackingCaller3()
	{
		Dxcoreclasses::_di_IcxMouseTrackingCaller3 intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Dxcoreclasses::IcxMouseTrackingCaller3*(void) { return (Dxcoreclasses::IcxMouseTrackingCaller3*)&__IcxMouseTrackingCaller3; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {3A5D973B-F016-4F22-80B6-1D35668D7743}
	operator Dxcoreclasses::_di_IcxMouseTrackingCaller2()
	{
		Dxcoreclasses::_di_IcxMouseTrackingCaller2 intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Dxcoreclasses::IcxMouseTrackingCaller2*(void) { return (Dxcoreclasses::IcxMouseTrackingCaller2*)&__IcxMouseTrackingCaller3; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {84A4BCBE-E001-4D60-B7A6-75E2B0DCD3E9}
	operator Dxcoreclasses::_di_IcxMouseTrackingCaller()
	{
		Dxcoreclasses::_di_IcxMouseTrackingCaller intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Dxcoreclasses::IcxMouseTrackingCaller*(void) { return (Dxcoreclasses::IcxMouseTrackingCaller*)&__IcxMouseTrackingCaller3; }
	#endif
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TdxScrollBarWrapper : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	System::TObject* FInnerScrollBar;
	bool FIsControlScrollBar;
	bool FIsTouchScrollUIMode;
	TcxControl* FOwnerControl;
	Cxscrollbar::_di_IcxScrollBarOwner FScrollBarOwner;
	Cxscrollbar::_di_IcxScrollBarOwner2 FScrollBarOwner2;
	System::TObject* FTouchScrollUIOwner;
	Vcl::Stdctrls::TScrollEvent FOnScroll;
	_di_IcxControlScrollBar __fastcall GetInnerScrollBar();
	TcxControlScrollBar* __fastcall GetInnerScrollBarControl();
	TcxControlScrollBarHelper* __fastcall GetInnerScrollBarHelper();
	Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeel();
	Dxscrollbarannotations::_di_IdxScrollbarAnnotationRenderer __fastcall GetScrollbarAnnotationRenderer();
	_di_IdxTouchScrollUIOwner __fastcall GetTouchScrollUIOwner();
	void __fastcall SetOwnerControlRelativeBounds(const System::Types::TRect &ABounds);
	
protected:
	void __fastcall DoScroll(System::TObject* Sender, System::Uitypes::TScrollCode ScrollCode, int &ScrollPos);
	void __fastcall UpdateBounds(const System::Types::TRect &ABoundsRect, const System::Types::TRect &AVisibleBoundsRect);
	__property _di_IcxControlScrollBar InnerScrollBar = {read=GetInnerScrollBar};
	__property TcxControlScrollBar* InnerScrollBarControl = {read=GetInnerScrollBarControl};
	__property TcxControlScrollBarHelper* InnerScrollBarHelper = {read=GetInnerScrollBarHelper};
	__property Dxscrollbarannotations::_di_IdxScrollbarAnnotationRenderer ScrollbarAnnotationRenderer = {read=GetScrollbarAnnotationRenderer};
	__property _di_IdxTouchScrollUIOwner TouchScrollUIOwner = {read=GetTouchScrollUIOwner};
	
public:
	__fastcall TdxScrollBarWrapper(_di_IdxTouchScrollUIOwner AOwner);
	__fastcall virtual ~TdxScrollBarWrapper();
	void __fastcall ApplyData();
	TcxControlScrollBar* __fastcall GetControl();
	System::Types::TRect __fastcall GetBoundsRect();
	TcxScrollBarData* __fastcall GetData();
	bool __fastcall GetEnabled();
	int __fastcall GetHeight();
	Vcl::Forms::TScrollBarKind __fastcall GetKind();
	Vcl::Forms::TScrollBarInc __fastcall GetLargeChange();
	int __fastcall GetLeft();
	int __fastcall GetMax();
	int __fastcall GetMin();
	int __fastcall GetPageSize();
	int __fastcall GetPosition();
	Vcl::Forms::TScrollBarInc __fastcall GetSmallChange();
	int __fastcall GetTop();
	bool __fastcall GetUnlimitedTracking();
	bool __fastcall GetVisible();
	int __fastcall GetWidth();
	void __fastcall SetBoundsRect(const System::Types::TRect &AValue);
	void __fastcall SetEnabled(bool AValue);
	void __fastcall SetHeight(int AValue);
	void __fastcall SetKind(Vcl::Forms::TScrollBarKind AValue);
	void __fastcall SetLargeChange(Vcl::Forms::TScrollBarInc AValue);
	void __fastcall SetLeft(int AValue);
	void __fastcall SetMax(int AValue);
	void __fastcall SetMin(int AValue);
	void __fastcall SetPageSize(int AValue);
	void __fastcall SetPosition(int AValue);
	void __fastcall SetScrollParams(int AMin, int AMax, int APosition, int APageSize, bool ARedraw = true);
	void __fastcall SetSmallChange(Vcl::Forms::TScrollBarInc AValue);
	void __fastcall SetTop(int AValue);
	void __fastcall SetUnlimitedTracking(bool AValue);
	void __fastcall SetVisible(bool AValue);
	void __fastcall SetWidth(int AValue);
	void __fastcall Calculate();
	void __fastcall CreateInnerScrollBar();
	void __fastcall DestroyInnerScrollBar();
	System::Types::TSize __fastcall GetDefaultSize();
	void __fastcall InitControl();
	void __fastcall Invalidate();
	void __fastcall UnInitControl();
	__property System::Types::TRect BoundsRect = {read=GetBoundsRect, write=SetBoundsRect};
	__property TcxControlScrollBar* Control = {read=GetControl};
	__property TcxScrollBarData* Data = {read=GetData};
	__property bool Enabled = {read=GetEnabled, write=SetEnabled, nodefault};
	__property int Height = {read=GetHeight, write=SetHeight, nodefault};
	__property Vcl::Forms::TScrollBarKind Kind = {read=GetKind, write=SetKind, nodefault};
	__property Vcl::Forms::TScrollBarInc LargeChange = {read=GetLargeChange, write=SetLargeChange, nodefault};
	__property int Left = {read=GetLeft, write=SetLeft, nodefault};
	__property Cxlookandfeels::TcxLookAndFeel* LookAndFeel = {read=GetLookAndFeel};
	__property int Max = {read=GetMax, write=SetMax, nodefault};
	__property int Min = {read=GetMin, write=SetMin, nodefault};
	__property int PageSize = {read=GetPageSize, write=SetPageSize, nodefault};
	__property int Position = {read=GetPosition, write=SetPosition, nodefault};
	__property Vcl::Forms::TScrollBarInc SmallChange = {read=GetSmallChange, write=SetSmallChange, nodefault};
	__property int Top = {read=GetTop, write=SetTop, nodefault};
	__property bool UnlimitedTracking = {read=GetUnlimitedTracking, write=SetUnlimitedTracking, nodefault};
	__property bool Visible = {read=GetVisible, write=SetVisible, nodefault};
	__property int Width = {read=GetWidth, write=SetWidth, nodefault};
	__property Vcl::Stdctrls::TScrollEvent OnScroll = {read=FOnScroll, write=FOnScroll};
private:
	void *__IcxControlScrollBar;	// IcxControlScrollBar 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {0C20A750-FAFE-4A96-A0FB-DE73BCF98CF9}
	operator Dxscrollbarannotations::_di_IdxScrollbarAnnotationRenderer() { return ScrollbarAnnotationRenderer; }
	#else
	operator Dxscrollbarannotations::IdxScrollbarAnnotationRenderer*(void) { return (Dxscrollbarannotations::IdxScrollbarAnnotationRenderer*)ScrollbarAnnotationRenderer; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {D70735C6-82E8-4D17-AE14-9317D2A11D0C}
	operator _di_IcxControlScrollBar()
	{
		_di_IcxControlScrollBar intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IcxControlScrollBar*(void) { return (IcxControlScrollBar*)&__IcxControlScrollBar; }
	#endif
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxControlCustomScrollBars : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	bool FCalculating;
	TdxMainScrollbarsOwnerHelper* FMainScrollbarsOwner;
	TcxControl* FOwner;
	System::TObject* FHScrollBar;
	System::TObject* FSizeGrip;
	System::TObject* FVScrollBar;
	
protected:
	void __fastcall ApplyData();
	virtual void __fastcall BringInternalControlsToFront();
	virtual bool __fastcall CheckSize(Vcl::Forms::TScrollBarKind AKind);
	virtual void __fastcall CheckSizeGripVisible(bool AValue) = 0 ;
	virtual System::TObject* __fastcall CreateScrollBar(Vcl::Forms::TScrollBarKind AKind) = 0 ;
	virtual void __fastcall CreateScrollBars();
	virtual System::TObject* __fastcall CreateSizeGrip() = 0 ;
	virtual void __fastcall DestroyHScrollBar();
	virtual void __fastcall DestroyScrollBars();
	virtual void __fastcall DestroySizeGrip();
	virtual void __fastcall DestroyVScrollBar();
	virtual void __fastcall DoScroll(System::TObject* Sender, System::Uitypes::TScrollCode ScrollCode, int &ScrollPos);
	virtual _di_IcxControlScrollBar __fastcall GetScrollBar(Vcl::Forms::TScrollBarKind AKind);
	virtual void __fastcall Hide();
	virtual void __fastcall InitScrollBars();
	virtual void __fastcall UnInitScrollBars();
	virtual bool __fastcall IsInternalControl(Vcl::Controls::TControl* AControl);
	virtual bool __fastcall IsScrollBarActive(Vcl::Forms::TScrollBarKind AKind);
	virtual bool __fastcall IsScrollBarVisible(Vcl::Forms::TScrollBarKind AKind);
	virtual bool __fastcall IsSizeGripArea(const System::Types::TPoint &APoint);
	virtual void __fastcall SetInternalControlsBounds();
	virtual void __fastcall UpdateInternalControlsState();
	__property bool Calculating = {read=FCalculating, write=FCalculating, nodefault};
	__property TcxControl* Owner = {read=FOwner};
	
public:
	__fastcall virtual TcxControlCustomScrollBars(TcxControl* AOwner);
	__fastcall virtual TcxControlCustomScrollBars(TdxMainScrollbarsOwnerHelper* AOwner);
	__fastcall virtual ~TcxControlCustomScrollBars();
	virtual void __fastcall Invalidate();
	virtual void __fastcall DrawSizeGrip(Cxcustomcanvas::TcxCustomCanvas* ACanvas);
};

#pragma pack(pop)

typedef System::TMetaClass* TcxControlCustomScrollBarsClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxControlScrollBars : public TcxControlCustomScrollBars
{
	typedef TcxControlCustomScrollBars inherited;
	
private:
	Cxscrollbar::_di_IcxScrollBarOwner2 FScrollbarOwner2;
	TcxControlScrollBarHelper* __fastcall GetHScrollBar();
	TcxSizeGripHelper* __fastcall GetSizeGrip();
	TcxControlScrollBarHelper* __fastcall GetVScrollBar();
	
protected:
	virtual Vcl::Controls::TWinControl* __fastcall GetControl();
	virtual Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeel();
	Cxgeometry::TdxScaleFactor* __fastcall GetScaleFactor();
	Cxscrollbar::_di_IcxScrollBarOwner2 __fastcall GetOwner2();
	virtual bool __fastcall CheckSize(Vcl::Forms::TScrollBarKind AKind);
	virtual void __fastcall CheckSizeGripVisible(bool AValue);
	virtual System::TObject* __fastcall CreateScrollBar(Vcl::Forms::TScrollBarKind AKind);
	virtual System::TObject* __fastcall CreateSizeGrip();
	virtual void __fastcall DestroyHScrollBar();
	virtual void __fastcall DestroyVScrollBar();
	virtual TcxControlScrollBarHelperClass __fastcall GetScrollBarClass(Vcl::Forms::TScrollBarKind AKind);
	virtual TcxSizeGripHelperClass __fastcall GetSizeGripClass();
	virtual bool __fastcall IsSizeGripArea(const System::Types::TPoint &APoint);
	virtual void __fastcall SetInternalControlsBounds();
	__property TcxControlScrollBarHelper* HScrollBar = {read=GetHScrollBar};
	__property TcxControlScrollBarHelper* VScrollBar = {read=GetVScrollBar};
	__property Cxgeometry::TdxScaleFactor* ScaleFactor = {read=GetScaleFactor};
	__property TcxSizeGripHelper* SizeGrip = {read=GetSizeGrip};
	
public:
	__fastcall virtual TcxControlScrollBars(TdxMainScrollbarsOwnerHelper* AOwner);
	virtual void __fastcall Invalidate();
	virtual void __fastcall DrawSizeGrip(Cxcustomcanvas::TcxCustomCanvas* ACanvas);
public:
	/* TcxControlCustomScrollBars.Create */ inline __fastcall virtual TcxControlScrollBars(TcxControl* AOwner) : TcxControlCustomScrollBars(AOwner) { }
	/* TcxControlCustomScrollBars.Destroy */ inline __fastcall virtual ~TcxControlScrollBars() { }
	
private:
	void *__IcxScrollBarOwner2Provider;	// Cxscrollbar::IcxScrollBarOwner2Provider 
	void *__IcxScrollBarOwner;	// Cxscrollbar::IcxScrollBarOwner 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {5CAEC427-0B33-41D2-8839-5BE9E0920BD4}
	operator Cxscrollbar::_di_IcxScrollBarOwner2Provider()
	{
		Cxscrollbar::_di_IcxScrollBarOwner2Provider intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Cxscrollbar::IcxScrollBarOwner2Provider*(void) { return (Cxscrollbar::IcxScrollBarOwner2Provider*)&__IcxScrollBarOwner2Provider; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {56771164-C253-40FF-B6D4-2A29D0C90236}
	operator Cxscrollbar::_di_IcxScrollBarOwner()
	{
		Cxscrollbar::_di_IcxScrollBarOwner intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Cxscrollbar::IcxScrollBarOwner*(void) { return (Cxscrollbar::IcxScrollBarOwner*)&__IcxScrollBarOwner; }
	#endif
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxControlWindowedScrollBars : public TcxControlCustomScrollBars
{
	typedef TcxControlCustomScrollBars inherited;
	
private:
	TcxControlScrollBar* __fastcall GetHScrollBar();
	TcxSizeGrip* __fastcall GetSizeGrip();
	TcxControlScrollBar* __fastcall GetVScrollBar();
	void __fastcall ScrollBarMouseEnter(System::TObject* Sender);
	void __fastcall ScrollBarMouseLeave(System::TObject* Sender);
	
protected:
	virtual void __fastcall BringInternalControlsToFront();
	virtual bool __fastcall CheckSize(Vcl::Forms::TScrollBarKind AKind);
	virtual void __fastcall CheckSizeGripVisible(bool AValue);
	virtual System::TObject* __fastcall CreateScrollBar(Vcl::Forms::TScrollBarKind AKind);
	virtual System::TObject* __fastcall CreateSizeGrip();
	virtual void __fastcall DestroyScrollBars();
	virtual void __fastcall Hide();
	virtual void __fastcall InitScrollBars();
	virtual void __fastcall UnInitScrollBars();
	virtual bool __fastcall IsInternalControl(Vcl::Controls::TControl* AControl);
	virtual bool __fastcall IsScrollBarActive(Vcl::Forms::TScrollBarKind AKind);
	virtual void __fastcall SetInternalControlsBounds();
	virtual void __fastcall UpdateInternalControlsState();
	__property TcxControlScrollBar* HScrollBar = {read=GetHScrollBar};
	__property TcxControlScrollBar* VScrollBar = {read=GetVScrollBar};
	__property TcxSizeGrip* SizeGrip = {read=GetSizeGrip};
	
public:
	virtual void __fastcall Invalidate();
public:
	/* TcxControlCustomScrollBars.Create */ inline __fastcall virtual TcxControlWindowedScrollBars(TcxControl* AOwner) : TcxControlCustomScrollBars(AOwner) { }
	/* TcxControlCustomScrollBars.CreateEx */ inline __fastcall virtual TcxControlWindowedScrollBars(TdxMainScrollbarsOwnerHelper* AOwner) : TcxControlCustomScrollBars(AOwner) { }
	/* TcxControlCustomScrollBars.Destroy */ inline __fastcall virtual ~TcxControlWindowedScrollBars() { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxDragAndDropObjectClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDragAndDropObject : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Cxgraphics::TcxCanvas* FCanvas;
	TcxControl* FControl;
	bool FDirty;
	void __fastcall SetDirty(bool Value);
	
protected:
	void __fastcall ChangeMousePos(const System::Types::TPoint &P);
	virtual void __fastcall DirtyChanged();
	virtual System::Types::TPoint __fastcall GetClientCursorPos();
	virtual System::Uitypes::TCursor __fastcall GetDragAndDropCursor(bool Accepted);
	virtual bool __fastcall GetImmediateStart();
	virtual int __fastcall GetZoomFactor();
	virtual void __fastcall AfterDragAndDrop(bool Accepted);
	virtual void __fastcall BeforeBeginDragAndDrop();
	virtual void __fastcall BeginDragAndDrop();
	virtual void __fastcall DragAndDrop(const System::Types::TPoint &P, bool &Accepted);
	virtual void __fastcall EndDragAndDrop(bool Accepted);
	virtual bool __fastcall ProcessKeyDown(System::Word AKey, System::Classes::TShiftState AShiftState);
	virtual bool __fastcall ProcessKeyUp(System::Word AKey, System::Classes::TShiftState AShiftState);
	virtual System::Types::TPoint __fastcall TranslateCoords(const System::Types::TPoint &P);
	__property Cxgraphics::TcxCanvas* Canvas = {read=FCanvas, write=FCanvas};
	__property TcxControl* Control = {read=FControl};
	__property bool Dirty = {read=FDirty, write=SetDirty, nodefault};
	
public:
	System::Types::TPoint CurMousePos;
	System::Types::TPoint PrevMousePos;
	__fastcall virtual TcxDragAndDropObject(TcxControl* AControl);
	void __fastcall DoBeginDragAndDrop();
	void __fastcall DoDragAndDrop(const System::Types::TPoint &P, bool &Accepted);
	void __fastcall DoEndDragAndDrop(bool Accepted);
	virtual bool __fastcall DoProcessKeyDown(Winapi::Messages::TWMKey &Message);
	virtual bool __fastcall DoProcessKeyUp(Winapi::Messages::TWMKey &Message);
	__property bool ImmediateStart = {read=GetImmediateStart, nodefault};
	__property int ZoomFactor = {read=GetZoomFactor, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDragAndDropObject() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxDragControlObject : public Vcl::Controls::TDragControlObject
{
	typedef Vcl::Controls::TDragControlObject inherited;
	
protected:
	virtual void __fastcall Finished(System::TObject* Target, int X, int Y, bool Accepted);
	virtual System::Uitypes::TCursor __fastcall GetDragCursor(bool Accepted, int X, int Y);
public:
	/* TBaseDragControlObject.Create */ inline __fastcall virtual TcxDragControlObject(Vcl::Controls::TControl* AControl) : Vcl::Controls::TDragControlObject(AControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDragControlObject() { }
	
};


typedef System::TMetaClass* TcxDragImageListClass;

class PASCALIMPLEMENTATION TcxDragImageList : public Vcl::Controls::TDragImageList
{
	typedef Vcl::Controls::TDragImageList inherited;
	
public:
	/* TCustomImageList.Create */ inline __fastcall virtual TcxDragImageList(System::Classes::TComponent* AOwner) : Vcl::Controls::TDragImageList(AOwner) { }
	/* TCustomImageList.CreateSize */ inline __fastcall TcxDragImageList(int AWidth, int AHeight) : Vcl::Controls::TDragImageList(AWidth, AHeight) { }
	/* TCustomImageList.Destroy */ inline __fastcall virtual ~TcxDragImageList() { }
	
};


enum DECLSPEC_DENUM TcxControlBorderStyle : unsigned char { cxcbsNone, cxcbsDefault };

enum DECLSPEC_DENUM TcxDragAndDropState : unsigned char { ddsNone, ddsStarting, ddsInProcess };

typedef System::Set<TcxDragAndDropState, TcxDragAndDropState::ddsNone, TcxDragAndDropState::ddsInProcess> TcxDragAndDropStates;

enum DECLSPEC_DENUM TcxKey : unsigned char { kAll, kArrows, kChars, kTab };

typedef System::Set<TcxKey, TcxKey::kAll, TcxKey::kTab> TcxKeys;

enum DECLSPEC_DENUM TcxMouseWheelScrollingKind : unsigned char { mwskNone, mwskHorizontal, mwskVertical };

enum DECLSPEC_DENUM TcxControlActivateType : unsigned char { atOther, atByMouse, atByMouseNonClientArea };

class PASCALIMPLEMENTATION TcxCustomControl : public Vcl::Controls::TCustomControl
{
	typedef Vcl::Controls::TCustomControl inherited;
	
private:
	System::Word FScaleChangeCounter;
	Cxgeometry::TdxScaleFactor* FScaleFactor;
	void __fastcall BeginScaleChange();
	void __fastcall EndScaleChange();
	bool __fastcall GetIsScaleChanging();
	MESSAGE void __fastcall DXMScaleChanged(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall DXMScaleChanging(Winapi::Messages::TMessage &Message);
	
protected:
	virtual bool __fastcall IsDoubleBufferedNeeded();
	virtual Vcl::Controls::TWinControl* __fastcall GetAdornerTargetElementControl();
	virtual System::Types::TRect __fastcall GetAdornerTargetElementBounds();
	virtual bool __fastcall GetAdornerTargetElementVisible();
	virtual void __fastcall GetAdornerTargetElements(System::Classes::TStrings* AList);
	virtual Cxgeometry::TdxScaleFactor* __fastcall GetScaleFactor();
	DYNAMIC void __fastcall ChangeScale(int M, int D, bool isDpiChange)/* overload */ _FINAL_ATTRIBUTE;
	virtual void __fastcall ChangeScaleEx(int M, int D, bool isDpiChange);
	virtual void __fastcall ScaleControlsForDpi(int NewPPI);
	virtual void __fastcall ScaleFactorChanging();
	virtual void __fastcall ScaleFactorChanged();
	virtual void __fastcall SetParent(Vcl::Controls::TWinControl* AValue);
	virtual void __fastcall ScrollParentWindowNotify();
	__property bool IsScaleChanging = {read=GetIsScaleChanging, nodefault};
	__property Cxgeometry::TdxScaleFactor* ScaleFactor = {read=GetScaleFactor};
	
public:
	__fastcall virtual TcxCustomControl(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomControl();
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomControl(HWND ParentWindow) : Vcl::Controls::TCustomControl(ParentWindow) { }
	
	/* Hoisted overloads: */
	
protected:
	DYNAMIC inline void __fastcall  ChangeScale(int M, int D){ Vcl::Controls::TControl::ChangeScale(M, D); }
	
private:
	void *__IdxScrollParentWindowNotify;	// IdxScrollParentWindowNotify 
	void *__IdxAdornerTargetElementCollection;	// Cxclasses::IdxAdornerTargetElementCollection 
	void *__IdxAdornerRootTargetElement;	// Cxclasses::IdxAdornerRootTargetElement 
	void *__IdxAdornerTargetElement;	// Cxclasses::IdxAdornerTargetElement 
	void *__IdxScaleFactor;	// Cxgeometry::IdxScaleFactor 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {E6A72D05-8320-4E80-8BBC-281889B15476}
	operator _di_IdxScrollParentWindowNotify()
	{
		_di_IdxScrollParentWindowNotify intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IdxScrollParentWindowNotify*(void) { return (IdxScrollParentWindowNotify*)&__IdxScrollParentWindowNotify; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {315F65EF-DC25-417E-8A4F-26060549DCC7}
	operator Cxclasses::_di_IdxAdornerTargetElementCollection()
	{
		Cxclasses::_di_IdxAdornerTargetElementCollection intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Cxclasses::IdxAdornerTargetElementCollection*(void) { return (Cxclasses::IdxAdornerTargetElementCollection*)&__IdxAdornerTargetElementCollection; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {23C48E23-DCDF-43C2-B855-351ED49B1227}
	operator Cxclasses::_di_IdxAdornerRootTargetElement()
	{
		Cxclasses::_di_IdxAdornerRootTargetElement intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Cxclasses::IdxAdornerRootTargetElement*(void) { return (Cxclasses::IdxAdornerRootTargetElement*)&__IdxAdornerRootTargetElement; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {FF5950DC-2CE8-4206-BB6A-13635D78F551}
	operator Cxclasses::_di_IdxAdornerTargetElement()
	{
		Cxclasses::_di_IdxAdornerTargetElement intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Cxclasses::IdxAdornerTargetElement*(void) { return (Cxclasses::IdxAdornerTargetElement*)&__IdxAdornerTargetElement; }
	#endif
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
class PASCALIMPLEMENTATION TdxMainScrollbarsOwnerHelper : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	System::StaticArray<int, 2> FGestureAccumulatedDelta;
	System::Uitypes::TColor FHybridScrollbarBaseColor;
	TdxHybridScrollbarsManager* FHybridScrollbarsManager;
	bool FInitialHScrollBarActive;
	bool FInitialVScrollBarActive;
	TcxControlCustomScrollBars* FMainScrollBars;
	System::TObject* FOwner;
	System::Uitypes::TScrollStyle FScrollBars;
	int FScrollBarsLockCount;
	bool FScrollBarsUpdateNeeded;
	int FUpdateScrollBarsCount;
	void __fastcall DoScrollBarBasedGestureScroll(Vcl::Forms::TScrollBarKind AKind, int &AAccumulatedDelta, int ADeltaX, int ADeltaY);
	void __fastcall SetScrollbars(const System::Uitypes::TScrollStyle Value);
	
protected:
	void __fastcall CreateScrollBars();
	void __fastcall DestroyScrollBars();
	virtual void __fastcall SystemInfoChanged(unsigned AParameter);
	virtual void __fastcall AddMainScrollBarsAsAnnotationRenderers();
	virtual void __fastcall BeginGestureScroll(const System::Types::TPoint &APos);
	virtual void __fastcall BringInternalControlsToFront();
	virtual bool __fastcall CanScrollContentByGestureWithoutScrollBars();
	virtual bool __fastcall CanUpdateScrollBars();
	void __fastcall CheckNeedsScrollBars();
	virtual TcxControlScrollBar* __fastcall CreateScrollbarControl(Vcl::Forms::TScrollBarKind AKind);
	virtual TcxSizeGrip* __fastcall CreateSizeGripControl();
	virtual void __fastcall DoUpdateScrollBars();
	virtual void __fastcall EndGestureScroll();
	virtual TcxControl* __fastcall GetControl();
	virtual System::Uitypes::TScrollStyle __fastcall GetDefaultScrollbarsValue();
	virtual int __fastcall GetHScrollBarAreaHeight();
	virtual System::Types::TRect __fastcall GetHScrollBarBounds();
	virtual int __fastcall GetHScrollBarDefaultAreaHeight();
	virtual System::Uitypes::TColor __fastcall GetHybridScrollbarBaseColor();
	TdxHybridScrollbarsManager* __fastcall GetHybridScrollbarsManager();
	virtual bool __fastcall GetIsDesigning();
	virtual bool __fastcall GetIsDestroying();
	virtual bool __fastcall GetIsLoading();
	virtual _di_IdxTouchScrollUIOwner __fastcall GetMainTouchScrollUIOwner();
	virtual Cxgeometry::TdxScaleFactor* __fastcall GetScaleFactor();
	virtual Dxscrollbarannotations::TdxScrollbarAnnotations* __fastcall GetScrollbarAnnotationHelper();
	_di_IcxControlScrollBar __fastcall GetScrollBar(Vcl::Forms::TScrollBarKind AKind);
	virtual System::Types::TSize __fastcall GetScrollbarBasedGestureClientSize();
	virtual Cxlookandfeels::TcxLookAndFeel* __fastcall GetScrollBarLookAndFeel();
	Cxlookandfeels::TdxScrollbarMode __fastcall GetScrollbarMode();
	System::Types::TSize __fastcall GetScrollBarSize();
	virtual System::Uitypes::TColor __fastcall GetScrollContentForegroundColor();
	TcxSizeGrip* __fastcall GetSizeGrip();
	virtual System::Types::TRect __fastcall GetSizeGripBounds();
	bool __fastcall GetUpdatingScrollBars();
	virtual int __fastcall GetVScrollBarAreaWidth();
	virtual System::Types::TRect __fastcall GetVScrollBarBounds();
	virtual int __fastcall GetVScrollBarDefaultAreaWidth();
	virtual bool __fastcall HasOwnScrollBars();
	virtual bool __fastcall HasScrollBarArea();
	virtual bool __fastcall HasScrollBars();
	virtual void __fastcall HideScrollBars();
	void __fastcall HideTouchScrollUI(_di_IdxTouchScrollUIOwner AValue, bool AImmediately = false);
	void __fastcall HideTouchScrollUIDirectly();
	void __fastcall InitScrollBars();
	virtual void __fastcall InitScrollBarsParameters();
	virtual void __fastcall InitScrollBarsParametersCache();
	virtual bool __fastcall IsDataScrollbar(Vcl::Forms::TScrollBarKind AKind);
	virtual bool __fastcall IsPixelScrollBar(Vcl::Forms::TScrollBarKind AKind);
	bool __fastcall IsScrollBarActive(Vcl::Forms::TScrollBarKind AKind);
	virtual bool __fastcall IsHybridScrollbarsArea(const System::Types::TPoint &APoint);
	bool __fastcall IsScrollBarVisible(Vcl::Forms::TScrollBarKind AKind);
	virtual bool __fastcall IsSizeGripArea(const System::Types::TPoint &APoint);
	virtual bool __fastcall IsSizeGripVisible();
	virtual bool __fastcall NeedsScrollBars();
	virtual bool __fastcall NeedsToBringInternalControlsToFront();
	virtual void __fastcall OwnerBoundsChanged();
	virtual bool __fastcall OwnerCanScrollLineWithoutScrollBars(Cxclasses::TcxDirection ADirection);
	virtual void __fastcall OwnerCheckOverpan(Vcl::Forms::TScrollBarKind AScrollKind, int ANewDataPos, int AMinDataPos, int AMaxDataPos, int ADeltaX, int ADeltaY);
	virtual void __fastcall OwnerDoUpdateScrollBars();
	virtual void __fastcall OwnerGestureScroll(Vcl::Forms::TScrollBarKind AScrollKind, int ANewScrollPos);
	virtual int __fastcall OwnerGetHScrollBarDefaultAreaHeight();
	virtual int __fastcall OwnerGetVScrollBarDefaultAreaWidth();
	virtual System::Types::TRect __fastcall OwnerGetSizeGripBounds();
	virtual bool __fastcall OwnerHasScrollBarArea();
	virtual void __fastcall OwnerInitScrollBars();
	virtual bool __fastcall OwnerIsSizeGripVisible();
	virtual void __fastcall OwnerSetInternalControlsBounds();
	virtual void __fastcall OwnerUpdate();
	virtual void __fastcall Scroll(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	void __fastcall ScrollBarBasedGestureScroll(Vcl::Forms::TScrollBarKind AScrollBarKind, int ADeltaX, int ADeltaY);
	virtual void __fastcall ScrollBarVisibilityChanged(TScrollBarKinds AScrollBars);
	virtual void __fastcall ScrollContent(Cxclasses::TcxDirection ADirection);
	virtual void __fastcall SetInternalControlsBounds();
	void __fastcall ShowTouchScrollUI(_di_IdxTouchScrollUIOwner AValue, bool AControlledByTimer = false);
	void __fastcall UnInitScrollbars();
	void __fastcall UpdateScrollBarBounds();
	__property System::Uitypes::TColor HybridScrollbarBaseColor = {read=GetHybridScrollbarBaseColor, write=FHybridScrollbarBaseColor, nodefault};
	__property bool IsDesigning = {read=GetIsDesigning, nodefault};
	__property bool IsDestroying = {read=GetIsDestroying, nodefault};
	__property bool IsLoading = {read=GetIsLoading, nodefault};
	__property TcxControlCustomScrollBars* MainScrollBars = {read=FMainScrollBars};
	__property System::TObject* Owner = {read=FOwner};
	__property Cxgeometry::TdxScaleFactor* ScaleFactor = {read=GetScaleFactor};
	__property System::Uitypes::TScrollStyle Scrollbars = {read=FScrollBars, write=SetScrollbars, nodefault};
	
public:
	__fastcall virtual TdxMainScrollbarsOwnerHelper(System::TObject* AOwner);
	__fastcall virtual ~TdxMainScrollbarsOwnerHelper();
	virtual void __fastcall DrawSizeGrip(Cxcustomcanvas::TcxCustomCanvas* ACanvas);
	void __fastcall LockScrollBars();
	void __fastcall SetScrollBarInfo(Vcl::Forms::TScrollBarKind AScrollBarKind, int AMin, int AMax, int AStep, int APage, int APos, bool AAllowShow, bool AAllowHide);
	void __fastcall UnlockScrollBars();
	void __fastcall UpdateScrollBars();
private:
	void *__IdxSystemInfoListener;	// IdxSystemInfoListener 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {F137963E-6165-47F9-A4C7-96BB4EB91AE0}
	operator _di_IdxSystemInfoListener()
	{
		_di_IdxSystemInfoListener intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IdxSystemInfoListener*(void) { return (IdxSystemInfoListener*)&__IdxSystemInfoListener; }
	#endif
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxControlMainScrollbarsHelper : public TdxMainScrollbarsOwnerHelper
{
	typedef TdxMainScrollbarsOwnerHelper inherited;
	
private:
	TcxControl* __fastcall GetOwner();
	
protected:
	virtual bool __fastcall CanScrollContentByGestureWithoutScrollBars();
	virtual TcxControlScrollBar* __fastcall CreateScrollbarControl(Vcl::Forms::TScrollBarKind AKind);
	virtual TcxSizeGrip* __fastcall CreateSizeGripControl();
	virtual TcxControl* __fastcall GetControl();
	virtual System::Uitypes::TScrollStyle __fastcall GetDefaultScrollbarsValue();
	virtual System::Types::TRect __fastcall GetHScrollBarBounds();
	virtual Dxscrollbarannotations::TdxScrollbarAnnotations* __fastcall GetScrollbarAnnotationHelper();
	virtual System::Types::TSize __fastcall GetScrollbarBasedGestureClientSize();
	virtual Cxlookandfeels::TcxLookAndFeel* __fastcall GetScrollBarLookAndFeel();
	virtual System::Uitypes::TColor __fastcall GetScrollContentForegroundColor();
	virtual System::Types::TRect __fastcall GetVScrollBarBounds();
	virtual bool __fastcall HasOwnScrollBars();
	virtual bool __fastcall HasScrollBars();
	virtual void __fastcall InitScrollBarsParameters();
	virtual void __fastcall InitScrollBarsParametersCache();
	virtual bool __fastcall IsDataScrollbar(Vcl::Forms::TScrollBarKind AKind);
	virtual bool __fastcall IsPixelScrollBar(Vcl::Forms::TScrollBarKind AKind);
	virtual bool __fastcall NeedsScrollBars();
	virtual bool __fastcall NeedsToBringInternalControlsToFront();
	virtual void __fastcall OwnerBoundsChanged();
	virtual bool __fastcall OwnerCanScrollLineWithoutScrollBars(Cxclasses::TcxDirection ADirection);
	virtual void __fastcall OwnerCheckOverpan(Vcl::Forms::TScrollBarKind AScrollKind, int ANewDataPos, int AMinDataPos, int AMaxDataPos, int ADeltaX, int ADeltaY);
	virtual void __fastcall OwnerDoUpdateScrollBars();
	virtual void __fastcall OwnerGestureScroll(Vcl::Forms::TScrollBarKind AScrollKind, int ANewScrollPos);
	virtual int __fastcall OwnerGetHScrollBarDefaultAreaHeight();
	virtual System::Types::TRect __fastcall OwnerGetSizeGripBounds();
	virtual int __fastcall OwnerGetVScrollBarDefaultAreaWidth();
	virtual bool __fastcall OwnerHasScrollBarArea();
	virtual void __fastcall OwnerInitScrollBars();
	virtual bool __fastcall OwnerIsSizeGripVisible();
	virtual void __fastcall OwnerSetInternalControlsBounds();
	virtual void __fastcall Scroll(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	virtual void __fastcall OwnerUpdate();
	virtual void __fastcall ScrollBarVisibilityChanged(TScrollBarKinds AScrollBars);
	virtual void __fastcall SystemInfoChanged(unsigned AParameter);
	__property TcxControl* Owner = {read=GetOwner};
public:
	/* TdxMainScrollbarsOwnerHelper.Create */ inline __fastcall virtual TcxControlMainScrollbarsHelper(System::TObject* AOwner) : TdxMainScrollbarsOwnerHelper(AOwner) { }
	/* TdxMainScrollbarsOwnerHelper.Destroy */ inline __fastcall virtual ~TcxControlMainScrollbarsHelper() { }
	
};

#pragma pack(pop)

enum DECLSPEC_DENUM TcxControlBackgroundStyle : unsigned char { bgNone, bgOpaque, bgTransparent };

typedef System::TMetaClass* TcxControlClass;

class PASCALIMPLEMENTATION TcxControl : public TcxCustomControl
{
	typedef TcxCustomControl inherited;
	
private:
	bool FIsScrollUIModeChanging;
	TcxControlMainScrollbarsHelper* FScrollbarsHelper;
	TdxTouchScrollUIActivityHelper* FScrollUIActivityHelper;
	TcxControlActivateType FActivateType;
	Cxcustomcanvas::TcxCustomCanvas* FActualCanvas;
	Cxlookandfeels::TdxRenderMode FActualRenderMode;
	TcxControlBorderStyle FBorderStyle;
	Cxgraphics::TcxCanvas* FCanvas;
	bool FCreatingWindow;
	bool FFinishingDragAndDrop;
	bool FFocusOnClick;
	System::Classes::_di_IInterfaceList FFontListenerList;
	Cxlookandfeels::TcxLookAndFeel* FLookAndFeel;
	System::UnicodeString FOriginalHint;
	System::Classes::TComponent* FPopupMenu;
	bool FJustTurnedOpaque;
	bool FTransparent;
	TcxDragAndDropObject* FDragAndDropObject;
	TcxDragAndDropObjectClass FDragAndDropObjectClass;
	System::Uitypes::TCursor FDragAndDropPrevCursor;
	TcxDragAndDropState FDragAndDropState;
	TcxDragImageList* FDragImages;
	Dxtouch::TdxGestureHelper* FGestureHelper;
	bool FAllowScrollContentOnDrag;
	bool FIsScrollingContent;
	TcxControlScrollBarsManager* FScrollBarsManager;
	Cxlookandfeels::TdxScrollbarMode FScrollbarMode;
	TcxKeys FKeys;
	bool FMouseDoubleClick;
	bool FMouseButtonPressed;
	System::TObject* FMouseCaptureObject;
	System::Types::TPoint FMouseDownPos;
	int FMouseEnterCounter;
	bool FMouseRightButtonReleased;
	int FMouseWheelAccumulator;
	System::Classes::TNotifyEvent FOnFocusChanged;
	System::Classes::TNotifyEvent FOnMouseEnter;
	System::Classes::TNotifyEvent FOnMouseLeave;
	void __fastcall CreateActualCanvas();
	void __fastcall FreeActualCanvas();
	void __fastcall RecreateActualCanvas();
	void __fastcall RecreateActualCanvasNeeded();
	Cxgraphics::TcxCanvas* __fastcall GetActiveCanvas();
	TcxDragAndDropObject* __fastcall GetDragAndDropObject();
	System::UnicodeString __fastcall GetHint();
	_di_IcxControlScrollBar __fastcall GetHScrollBar();
	bool __fastcall GetHScrollBarVisible();
	bool __fastcall GetIsDestroying();
	bool __fastcall GetIsLoading();
	Cxlookandfeels::TdxScrollbarMode __fastcall GetLookAndFeelScrollbarMode();
	TcxControlCustomScrollBars* __fastcall GetMainScrollBars();
	System::Uitypes::TScrollStyle __fastcall GetScrollBars();
	TcxSizeGrip* __fastcall GetSizeGrip();
	bool __fastcall GetUpdatingScrollBars();
	_di_IcxControlScrollBar __fastcall GetVScrollBar();
	bool __fastcall GetVScrollBarVisible();
	HIDESBASE bool __fastcall IsHintStored();
	bool __fastcall IsScrollBarModeChanged();
	void __fastcall SetBorderStyle(TcxControlBorderStyle Value);
	void __fastcall SetDragAndDropState(TcxDragAndDropState Value);
	void __fastcall SetHint(const System::UnicodeString Value);
	void __fastcall SetHybridScrollbarBaseColor(const System::Uitypes::TColor Value);
	void __fastcall SetLookAndFeel(Cxlookandfeels::TcxLookAndFeel* Value);
	void __fastcall SetKeys(TcxKeys Value);
	void __fastcall SetMouseCaptureObject(System::TObject* Value);
	HIDESBASE void __fastcall SetPopupMenu(System::Classes::TComponent* Value);
	void __fastcall SetScrollBars(System::Uitypes::TScrollStyle Value);
	void __fastcall SetTransparent(bool Value);
	MESSAGE void __fastcall DXMMouseHWheel(Vcl::Controls::TCMMouseWheel &Message);
	HIDESBASE MESSAGE void __fastcall WMCancelMode(Winapi::Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall WMContextMenu(Winapi::Messages::TWMContextMenu &Message);
	HIDESBASE MESSAGE void __fastcall WMDestroy(Winapi::Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Winapi::Messages::TWMEraseBkgnd &Message);
	MESSAGE void __fastcall WMGetDlgCode(Winapi::Messages::TWMNoParams &Message);
	MESSAGE void __fastcall WMMouseHWheel(Winapi::Messages::TWMMouseWheel &Message);
	HIDESBASE MESSAGE void __fastcall WMNCCalcSize(Winapi::Messages::TWMNCCalcSize &Message);
	HIDESBASE MESSAGE void __fastcall WMNCPaint(Winapi::Messages::TWMNCPaint &Message);
	HIDESBASE MESSAGE void __fastcall WMPaint(Winapi::Messages::TWMPaint &Message);
	MESSAGE void __fastcall WMPrint(Winapi::Messages::TWMPrint &Message);
	HIDESBASE MESSAGE void __fastcall WMPrintClient(Winapi::Messages::TWMPrint &Message);
	HIDESBASE MESSAGE void __fastcall WMSetCursor(Winapi::Messages::TWMSetCursor &Message);
	HIDESBASE MESSAGE void __fastcall WMWindowPosChanged(Winapi::Messages::TWMWindowPosMsg &Message);
	HIDESBASE MESSAGE void __fastcall CMBiDiModeChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMColorChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMCursorChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMDesignHitTest(Winapi::Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall CMEnabledChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMInvalidate(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseEnter(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseLeave(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall CMNCSizeChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMTextChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMVisibleChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CNKeyDown(Winapi::Messages::TWMKey &Message);
	HIDESBASE MESSAGE void __fastcall CNKeyUp(Winapi::Messages::TWMKey &Message);
	HIDESBASE MESSAGE void __fastcall CNSysKeyDown(Winapi::Messages::TWMKey &Message);
	
protected:
	System::Types::TRect FBounds;
	DYNAMIC void __fastcall ActionChange(System::TObject* Sender, bool CheckDefaults);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd();
	DYNAMIC void __fastcall Resize();
	virtual void __fastcall ScaleFactorChanged();
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	virtual void __fastcall DestroyWindowHandle();
	DYNAMIC void __fastcall DoContextPopup(const System::Types::TPoint &MousePos, bool &Handled);
	void __fastcall CheckFluentDesignContainerBackground();
	virtual void __fastcall BeginGestureScroll(const System::Types::TPoint &APos);
	virtual bool __fastcall CanScrollContentByGestureWithoutScrollBars();
	virtual void __fastcall CheckOverpan(Vcl::Forms::TScrollBarKind AScrollKind, int ANewDataPos, int AMinDataPos, int AMaxDataPos, int ADeltaX, int ADeltaY);
	virtual void __fastcall DoGestureScroll(Vcl::Forms::TScrollBarKind AScrollKind, int ANewScrollPos);
	virtual void __fastcall EndGestureScroll();
	virtual void __fastcall DoGesture(const Vcl::Controls::TGestureEventInfo &EventInfo, bool &Handled);
	virtual void __fastcall DoGetGestureOptions(Vcl::Controls::TInteractiveGestures &Gestures, Vcl::Controls::TInteractiveGestureOptions &Options);
	virtual Vcl::Controls::TInteractiveGestures __fastcall GetDefaultInteractiveGestures();
	virtual Vcl::Controls::TInteractiveGestureOptions __fastcall GetDefaultInteractiveGestureOptions();
	virtual _di_IdxTouchScrollUIOwner __fastcall GetTouchScrollUIOwner(const System::Types::TPoint &APoint);
	DYNAMIC bool __fastcall IsTouchPropertyStored(Vcl::Controls::TTouchProperty AProperty);
	virtual void __fastcall GestureScroll(int ADeltaX, int ADeltaY);
	virtual bool __fastcall CanProcessScrollEvents(Winapi::Messages::TMessage &Message);
	virtual bool __fastcall IsDefaultGesture(int AGestureID);
	virtual bool __fastcall IsGestureHelperMessage(Winapi::Messages::TMessage &Message);
	virtual bool __fastcall IsGestureScrolling();
	virtual bool __fastcall IsScrollBarBasedGestureScroll(Vcl::Forms::TScrollBarKind AScrollKind);
	virtual int __fastcall GetDefaultPanOptions();
	virtual void __fastcall ScrollContentByGesture(Vcl::Forms::TScrollBarKind AScrollKind, int ADelta);
	void __fastcall DoMouseEnter(Vcl::Controls::TControl* AControl);
	void __fastcall DoMouseLeave(Vcl::Controls::TControl* AControl);
	virtual bool __fastcall DoMouseHWheel(System::Classes::TShiftState Shift, int WheelDelta, const System::Types::TPoint &MousePos);
	DYNAMIC bool __fastcall DoMouseWheel(System::Classes::TShiftState Shift, int WheelDelta, const System::Types::TPoint &MousePos);
	virtual bool __fastcall DoShowPopupMenu(System::Classes::TComponent* AMenu, int X, int Y);
	DYNAMIC Vcl::Menus::TPopupMenu* __fastcall GetPopupMenu();
	virtual bool __fastcall InternalMouseHWheel(System::Classes::TShiftState Shift, int WheelDelta, const System::Types::TPoint &MousePos);
	virtual bool __fastcall InternalMouseWheel(System::Classes::TShiftState Shift, int WheelDelta, const System::Types::TPoint &MousePos);
	virtual bool __fastcall IsDoubleBufferedNeeded();
	HIDESBASE bool __fastcall IsMenuKey(Winapi::Messages::TWMKey &Message);
	virtual void __fastcall Modified();
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual bool __fastcall ProcesMouseWheel(System::Classes::TShiftState AShift, int AWheelDelta, const System::Types::TPoint &AMousePos, bool AHorizontalScroll);
	virtual void __fastcall SetParentBackground(bool Value);
	virtual Cxcustomcanvas::TcxCustomCanvas* __fastcall CreateActualCanvasCore(Cxlookandfeels::TdxRenderMode &ARenderMode);
	virtual void __fastcall CreateCanvasBasedResources();
	virtual void __fastcall FreeCanvasBasedResources();
	void __fastcall InvalidateCanvasBuffer();
	virtual void __fastcall DoPaint();
	virtual void __fastcall DoNonClientPaint(HDC AWindowDC);
	virtual void __fastcall DrawBorder(Cxcustomcanvas::TcxCustomCanvas* ACanvas);
	virtual void __fastcall DrawScrollBars(Cxcustomcanvas::TcxCustomCanvas* ACanvas);
	virtual void __fastcall DrawOpaqueBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall EraseBackground(HDC DC)/* overload */;
	virtual void __fastcall EraseBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect)/* overload */;
	virtual TcxControlBackgroundStyle __fastcall GetBackgroundStyle();
	virtual void __fastcall Paint();
	void __fastcall DirectPaintHandler(const Cxcustomcanvas::_di_IcxControlDirectCanvas ADirectCanvas, const Winapi::Messages::TWMPaint &Message);
	void __fastcall StandardPaintHandler(Winapi::Messages::TWMPaint &Message);
	virtual void __fastcall PaintNonClientArea(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall PaintWindow(HDC DC);
	DYNAMIC void __fastcall AddChildComponent(TcxControlChildComponent* AComponent);
	DYNAMIC void __fastcall RemoveChildComponent(TcxControlChildComponent* AComponent);
	virtual void __fastcall AfterMouseDown(System::Uitypes::TMouseButton AButton, int X, int Y);
	virtual void __fastcall BeforeMouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall BringInternalControlsToFront();
	virtual void __fastcall CancelMouseOperations();
	void __fastcall CancelMousePressed();
	DYNAMIC void __fastcall DoCancelMode();
	virtual int __fastcall GetBorderSize();
	virtual System::Types::TRect __fastcall GetBounds();
	virtual System::Types::TRect __fastcall GetClientBounds();
	virtual System::Types::TRect __fastcall GetClientOffsets();
	virtual System::Uitypes::TCursor __fastcall GetCurrentCursor(int X, int Y);
	DYNAMIC bool __fastcall GetDesignHitTest(int X, int Y, System::Classes::TShiftState Shift);
	DYNAMIC TDragControlObjectClass __fastcall GetDragObjectClass();
	virtual bool __fastcall GetIsDesigning();
	virtual bool __fastcall GetIsFocused();
	virtual TcxControlCustomScrollBarsClass __fastcall GetMainScrollBarsClass();
	System::Types::TPoint __fastcall GetMouseCursorClientPos();
	virtual TcxMouseWheelScrollingKind __fastcall GetMouseWheelScrollingKind();
	virtual bool __fastcall GetPaintBlackOpaqueOnGlass();
	virtual TcxControlScrollBarClass __fastcall GetScrollBarClass(Vcl::Forms::TScrollBarKind AKind);
	virtual TcxSizeGripClass __fastcall GetSizeGripClass();
	virtual void __fastcall InitControl();
	__classmethod void __fastcall InvalidateControl(Vcl::Controls::TWinControl* AControl, bool ANeedInvalidateSelf, bool ANeedInvalidateChildren);
	DYNAMIC void __fastcall MouseEnter(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall FocusEnter();
	DYNAMIC void __fastcall FocusLeave();
	virtual void __fastcall SetFocusOnMouseClick(System::Uitypes::TMouseButton AButton, int X, int Y);
	virtual void __fastcall SetPaintRegion();
	void __fastcall UpdateStatusHint(const System::Types::TPoint &APoint);
	virtual System::UnicodeString __fastcall GetStatusHint(const System::Types::TPoint &APoint);
	virtual bool __fastcall AllowCompositionPainting();
	virtual bool __fastcall CanFocusOnClick()/* overload */;
	virtual bool __fastcall CanFocusOnClick(int X, int Y)/* overload */;
	virtual bool __fastcall FocusWhenChildIsClicked(Vcl::Controls::TControl* AChild);
	virtual bool __fastcall HasBackground();
	virtual bool __fastcall HasNonClientArea();
	virtual bool __fastcall IsMouseHWheelHandleNeeded(System::Classes::TShiftState Shift, int WheelDelta, const System::Types::TPoint &MousePos);
	virtual bool __fastcall IsMouseWheelHandleNeeded(System::Classes::TShiftState Shift, int WheelDelta, const System::Types::TPoint &MousePos);
	bool __fastcall IsScrollAnimationEnabled();
	virtual bool __fastcall IsTransparentBackground();
	virtual bool __fastcall IsInternalControl(Vcl::Controls::TControl* AControl);
	DYNAMIC bool __fastcall MayFocus();
	virtual bool __fastcall NeedRedrawOnResize();
	virtual bool __fastcall RecreateWndOnBiDiModeChanged();
	virtual bool __fastcall UpdateMousePositionIfControlMoved();
	virtual void __fastcall BiDiModeChanged();
	DYNAMIC void __fastcall BorderStyleChanged();
	DYNAMIC void __fastcall BoundsChanged();
	DYNAMIC void __fastcall ColorChanged();
	DYNAMIC void __fastcall CursorChanged();
	virtual void __fastcall EnabledChanged();
	DYNAMIC void __fastcall FocusChanged();
	HIDESBASEDYNAMIC void __fastcall FontChanged();
	virtual void __fastcall ParentBackgroundChanged();
	DYNAMIC void __fastcall TextChanged();
	DYNAMIC void __fastcall TransparentChanged();
	DYNAMIC void __fastcall VisibleChanged();
	virtual bool __fastcall AllowGesture(int AGestureId);
	virtual bool __fastcall AllowPan(Vcl::Forms::TScrollBarKind AScrollKind);
	virtual int __fastcall GetPanOptions();
	virtual bool __fastcall IsPanArea(const System::Types::TPoint &APoint);
	virtual bool __fastcall NeedPanningFeedback(Vcl::Forms::TScrollBarKind AScrollKind);
	virtual Dxtouch::_di_IdxGestureClient __fastcall GetGestureClient(const System::Types::TPoint &APoint);
	virtual NativeUInt __fastcall GetGestureClientHandle();
	virtual bool __fastcall IsGestureTarget(NativeUInt AWnd);
	virtual Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeelValue();
	HIDESBASE Vcl::Controls::TWinControl* __fastcall GetControl();
	virtual Cxlookandfeels::TcxLookAndFeel* __fastcall GetScrollBarLookAndFeel();
	virtual void __fastcall CheckTouchScrollUIPosition();
	virtual TcxControl* __fastcall GetTouchScrollUIOwnerControl();
	virtual bool __fastcall HasVisibleTouchScrollUI();
	virtual void __fastcall HideTouchScrollUIDirectly();
	Cxlookandfeels::TdxRenderMode __fastcall GetActualRenderMode(Cxlookandfeels::TdxRenderMode ASuggestedRenderMode);
	virtual Cxlookandfeels::TdxRenderMode __fastcall GetDefaultRenderMode();
	virtual bool __fastcall IsRenderModeSupported(Cxlookandfeels::TdxRenderMode ARenderMode);
	virtual System::Uitypes::TColor __fastcall GetHybridScrollbarBaseColor();
	TdxHybridScrollbarsManager* __fastcall GetManager();
	virtual void __fastcall InvalidateScrollbars();
	void __fastcall NotifyTurnedOpaque();
	virtual bool __fastcall FluentDesignContainerControlCanBeOpaque();
	virtual void __fastcall VisualRefinementsListenerChanged();
	virtual Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter();
	void __fastcall LookAndFeelChangeHandler(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	virtual void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	__property Cxlookandfeels::TcxLookAndFeel* LookAndFeel = {read=FLookAndFeel, write=SetLookAndFeel};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* LookAndFeelPainter = {read=GetLookAndFeelPainter};
	virtual bool __fastcall AllowHybridScrollbarMode();
	virtual bool __fastcall AllowTouchScrollUIMode();
	virtual bool __fastcall CanScrollLineWithoutScrollBars(Cxclasses::TcxDirection ADirection);
	virtual bool __fastcall CanUpdateScrollBars();
	virtual void __fastcall CheckTouchScrollUIMode();
	void __fastcall Deactivate(_di_IdxTouchScrollUIOwner AValue = _di_IdxTouchScrollUIOwner());
	virtual void __fastcall DeactivateAllTouchScrollbars();
	virtual void __fastcall DoCreateScrollBars();
	virtual void __fastcall DoDestroyScrollBars();
	void __fastcall DoScrolling();
	virtual void __fastcall DoUpdateScrollBars();
	virtual System::Uitypes::TScrollStyle __fastcall GetDefaultScrollbarsValue();
	virtual int __fastcall GetHScrollBarAreaHeight();
	virtual System::Types::TRect __fastcall GetHScrollBarBounds();
	virtual int __fastcall GetHScrollBarDefaultAreaHeight();
	virtual System::Types::TRect __fastcall GetSizeGripBounds();
	_di_IcxControlScrollBar __fastcall GetScrollBar(Vcl::Forms::TScrollBarKind AKind);
	System::Types::TSize __fastcall GetScrollBarSize();
	virtual Cxlookandfeels::TdxScrollbarMode __fastcall GetScrollbarMode();
	virtual System::Uitypes::TColor __fastcall GetScrollContentForegroundColor();
	virtual System::Uitypes::TScrollStyle __fastcall GetSystemSizeScrollBars();
	virtual int __fastcall GetVScrollBarAreaWidth();
	virtual System::Types::TRect __fastcall GetVScrollBarBounds();
	virtual int __fastcall GetVScrollBarDefaultAreaWidth();
	virtual bool __fastcall HasOwnScrollbars();
	virtual bool __fastcall HasScrollBarArea();
	virtual bool __fastcall HasScrollBars();
	virtual void __fastcall HideScrollBars();
	void __fastcall HideTouchScrollUI(_di_IdxTouchScrollUIOwner AValue, bool AImmediately = false);
	virtual void __fastcall InitScrollBars();
	virtual void __fastcall InitScrollBarsParameters();
	virtual void __fastcall InitScrollBarsParametersCache();
	virtual bool __fastcall IsPixelScrollBar(Vcl::Forms::TScrollBarKind AKind);
	virtual bool __fastcall IsPopupScrollBars();
	bool __fastcall IsScrollBarActive(Vcl::Forms::TScrollBarKind AKind);
	virtual bool __fastcall IsScrollBarsArea(const System::Types::TPoint &APoint);
	bool __fastcall IsScrollBarsCapture();
	bool __fastcall IsTouchScrollUIHidden(_di_IdxTouchScrollUIOwner ATouchScrollBarOwner = _di_IdxTouchScrollUIOwner());
	virtual bool __fastcall IsTouchScrollUIMode();
	virtual bool __fastcall IsSizeGripArea(const System::Types::TPoint &APoint);
	virtual bool __fastcall IsSizeGripVisible();
	virtual bool __fastcall NeedsScrollBars();
	virtual bool __fastcall NeedsToBringInternalControlsToFront();
	virtual void __fastcall Scroll(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	virtual void __fastcall ScrollBarVisibilityChanged(TScrollBarKinds AScrollBars);
	virtual void __fastcall SetInternalControlsBounds();
	virtual void __fastcall ShowTouchScrollUI(_di_IdxTouchScrollUIOwner AValue, bool AControlledByTimer = false);
	virtual void __fastcall UnInitScrollbars();
	virtual void __fastcall UpdateInternalControlsState();
	void __fastcall UpdateScrollBarBounds();
	virtual void __fastcall UpdateScrollBars();
	virtual void __fastcall AfterScrollUIModeChanged();
	virtual void __fastcall BeforeScrollUIModeChanged();
	virtual void __fastcall DoScrollUIModeChanged();
	virtual void __fastcall ScrollUIModeChanged();
	virtual void __fastcall AddMainScrollBarsAsAnnotationRenderers();
	virtual Dxscrollbarannotations::TdxScrollbarAnnotations* __fastcall GetScrollbarAnnotationHelper();
	virtual bool __fastcall IsDataScrollbar(Vcl::Forms::TScrollBarKind AKind);
	__property bool AllowScrollContentOnDrag = {read=FAllowScrollContentOnDrag, write=FAllowScrollContentOnDrag, nodefault};
	__property _di_IcxControlScrollBar HScrollBar = {read=GetHScrollBar};
	__property bool HScrollBarVisible = {read=GetHScrollBarVisible, nodefault};
	__property TcxControlCustomScrollBars* MainScrollBars = {read=GetMainScrollBars};
	__property TcxControlScrollBarsManager* ScrollBarsManager = {read=FScrollBarsManager};
	__property System::Uitypes::TScrollStyle ScrollBars = {read=GetScrollBars, write=SetScrollBars, default=3};
	__property TcxControlMainScrollbarsHelper* ScrollbarsHelper = {read=FScrollbarsHelper};
	__property TcxSizeGrip* SizeGrip = {read=GetSizeGrip};
	__property bool UpdatingScrollBars = {read=GetUpdatingScrollBars, nodefault};
	__property _di_IcxControlScrollBar VScrollBar = {read=GetVScrollBar};
	__property bool VScrollBarVisible = {read=GetVScrollBarVisible, nodefault};
	virtual bool __fastcall AllowAutoDragAndDropAtDesignTime(int X, int Y, System::Classes::TShiftState Shift);
	DYNAMIC bool __fastcall AllowDragAndDropWithoutFocus();
	virtual bool __fastcall CanCancelDragStartOnCaptureObjectClear();
	virtual bool __fastcall CanStartDragAndDrop(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual TcxDragAndDropObject* __fastcall CreateDragAndDropObject();
	virtual void __fastcall DoFinishDragAndDrop(bool Accepted);
	DYNAMIC void __fastcall DragAndDrop(const System::Types::TPoint &P, bool &Accepted);
	DYNAMIC void __fastcall EndDragAndDrop(bool Accepted);
	virtual TcxDragAndDropObjectClass __fastcall GetDragAndDropObjectClass();
	virtual void __fastcall ProcessDragAndDropOnMouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall ProcessDragAndDropOnMouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC bool __fastcall StartDragAndDrop(const System::Types::TPoint &P);
	__property bool FinishingDragAndDrop = {read=FFinishingDragAndDrop, nodefault};
	DYNAMIC bool __fastcall CanDrag(int X, int Y);
	DYNAMIC void __fastcall DoStartDrag(Vcl::Controls::TDragObject* &DragObject);
	DYNAMIC void __fastcall DoEndDrag(System::TObject* Target, int X, int Y);
	DYNAMIC void __fastcall DragOver(System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	virtual void __fastcall DrawDragImage(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual TcxDragImageListClass __fastcall GetDragImagesClass();
	virtual System::Types::TPoint __fastcall GetDragImagesSize();
	virtual bool __fastcall GetIsCopyDragDrop();
	virtual bool __fastcall HasDragImages();
	void __fastcall HideDragImage();
	virtual void __fastcall InitDragImages(TcxDragImageList* ADragImages);
	void __fastcall ShowDragImage();
	__property TcxControlActivateType ActivateType = {read=FActivateType, write=FActivateType, nodefault};
	__property Cxcustomcanvas::TcxCustomCanvas* ActualCanvas = {read=FActualCanvas};
	__property Cxlookandfeels::TdxRenderMode ActualRenderMode = {read=FActualRenderMode, nodefault};
	__property int BorderSize = {read=GetBorderSize, nodefault};
	__property TcxControlBorderStyle BorderStyle = {read=FBorderStyle, write=SetBorderStyle, nodefault};
	__property bool CreatingWindow = {read=FCreatingWindow, nodefault};
	__property TcxDragImageList* DragImages = {read=FDragImages};
	__property bool FocusOnClick = {read=FFocusOnClick, write=FFocusOnClick, default=1};
	__property System::Classes::_di_IInterfaceList FontListenerList = {read=FFontListenerList};
	__property Dxtouch::TdxGestureHelper* GestureHelper = {read=FGestureHelper};
	__property System::Uitypes::TColor HybridScrollbarBaseColor = {read=GetHybridScrollbarBaseColor, write=SetHybridScrollbarBaseColor, nodefault};
	__property bool IsCopyDragDrop = {read=GetIsCopyDragDrop, nodefault};
	__property bool IsScrollingContent = {read=FIsScrollingContent, nodefault};
	__property bool IsScrollUIModeChanging = {read=FIsScrollUIModeChanging, nodefault};
	__property TcxKeys Keys = {read=FKeys, write=SetKeys, nodefault};
	__property bool MouseRightButtonReleased = {read=FMouseRightButtonReleased, write=FMouseRightButtonReleased, nodefault};
	__property TcxMouseWheelScrollingKind MouseWheelScrollingKind = {read=GetMouseWheelScrollingKind, nodefault};
	__property ParentBackground = {default=1};
	__property System::Classes::TComponent* PopupMenu = {read=FPopupMenu, write=SetPopupMenu};
	__property TdxTouchScrollUIActivityHelper* ScrollUIActivityHelper = {read=FScrollUIActivityHelper};
	__property bool Transparent = {read=FTransparent, write=SetTransparent, default=0};
	__property System::Classes::TNotifyEvent OnFocusChanged = {read=FOnFocusChanged, write=FOnFocusChanged};
	__property System::Classes::TNotifyEvent OnMouseEnter = {read=FOnMouseEnter, write=FOnMouseEnter};
	__property System::Classes::TNotifyEvent OnMouseLeave = {read=FOnMouseLeave, write=FOnMouseLeave};
	
public:
	__fastcall virtual TcxControl(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxControl();
	virtual void __fastcall AfterConstruction();
	virtual void __fastcall BeforeDestruction();
	virtual Vcl::Controls::TDragImageList* __fastcall GetDragImages();
	virtual bool __fastcall CanFocusEx();
	virtual bool __fastcall AcceptMousePosForClick(int X, int Y);
	virtual void __fastcall DefaultHandler(void *Message);
	virtual bool __fastcall IsMouseInPressedArea(int X, int Y);
	void __fastcall PostMouseMove(const System::Types::TPoint &AMousePos)/* overload */;
	void __fastcall PostMouseMove()/* overload */;
	virtual void __fastcall ScrollContent(Cxclasses::TcxDirection ADirection);
	void __fastcall ScrollWindow(int DX, int DY, const System::Types::TRect &AScrollRect);
	virtual void __fastcall SetFocus();
	void __fastcall SetScrollBarInfo(Vcl::Forms::TScrollBarKind AScrollBarKind, int AMin, int AMax, int AStep, int APage, int APos, bool AAllowShow, bool AAllowHide);
	DYNAMIC bool __fastcall StartDrag(Vcl::Controls::TDragObject* DragObject);
	virtual void __fastcall Invalidate();
	void __fastcall InvalidateRect(const System::Types::TRect &R, bool EraseBackground);
	void __fastcall InvalidateRgn(Cxgraphics::TcxRegion* ARegion, bool EraseBackground);
	void __fastcall InvalidateWithChildren();
	void __fastcall UpdateWithChildren();
	DYNAMIC void __fastcall BeginDragAndDrop();
	void __fastcall FinishDragAndDrop(bool Accepted);
	__property TcxDragAndDropObject* DragAndDropObject = {read=GetDragAndDropObject};
	__property TcxDragAndDropObjectClass DragAndDropObjectClass = {read=GetDragAndDropObjectClass, write=FDragAndDropObjectClass};
	__property TcxDragAndDropState DragAndDropState = {read=FDragAndDropState, write=SetDragAndDropState, nodefault};
	void __fastcall AddFontListener(Cxgraphics::_di_IcxFontListener AListener);
	void __fastcall RemoveFontListener(Cxgraphics::_di_IcxFontListener AListener);
	void __fastcall LockScrollBars();
	void __fastcall UnlockScrollBars();
	virtual void __fastcall TranslationChanged();
	virtual void __fastcall SystemInfoChanged(unsigned AParameter);
	__property System::Types::TRect Bounds = {read=GetBounds};
	__property Cxgraphics::TcxCanvas* Canvas = {read=FCanvas};
	__property Cxgraphics::TcxCanvas* ActiveCanvas = {read=GetActiveCanvas};
	__property System::Types::TRect ClientBounds = {read=GetClientBounds};
	__property bool IsDesigning = {read=GetIsDesigning, nodefault};
	__property bool IsDestroying = {read=GetIsDestroying, nodefault};
	__property bool IsLoading = {read=GetIsLoading, nodefault};
	__property bool IsFocused = {read=GetIsFocused, nodefault};
	__property System::TObject* MouseCaptureObject = {read=FMouseCaptureObject, write=SetMouseCaptureObject};
	__property System::Types::TPoint MouseDownPos = {read=FMouseDownPos, write=FMouseDownPos};
	__property TabStop = {default=1};
	
__published:
	__property Touch;
	__property OnGesture;
	__property System::UnicodeString Hint = {read=GetHint, write=SetHint, stored=IsHintStored};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxControl(HWND ParentWindow) : TcxCustomControl(ParentWindow) { }
	
private:
	void *__IdxVisualRefinementsListener;	// Cxlookandfeels::IdxVisualRefinementsListener 
	void *__IdxFluentDesignContainerControl;	// Dxfluentdesignforminterfaces::IdxFluentDesignContainerControl 
	void *__IdxHybridScrollbarOwner;	// IdxHybridScrollbarOwner 
	void *__IdxDirect2DCanvasOwner;	// Dxdirectx::D2d::Canvas::IdxDirect2DCanvasOwner 
	void *__IdxTouchScrollUIOwner;	// IdxTouchScrollUIOwner 
	void *__IdxSystemInfoListener;	// IdxSystemInfoListener 
	void *__IdxLocalizerListener;	// Dxcore::IdxLocalizerListener 
	void *__IdxGestureOwner;	// Dxtouch::IdxGestureOwner 
	void *__IdxGestureClient2;	// Dxtouch::IdxGestureClient2 
	void *__IdxGestureClient;	// Dxtouch::IdxGestureClient 
	void *__IcxScrollBarOwner;	// Cxscrollbar::IcxScrollBarOwner 
	void *__IcxLookAndFeelContainer;	// Cxlookandfeels::IcxLookAndFeelContainer 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {287BA6FB-1282-4933-AFDB-45DC4D2E3F65}
	operator Cxlookandfeels::_di_IdxVisualRefinementsListener()
	{
		Cxlookandfeels::_di_IdxVisualRefinementsListener intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Cxlookandfeels::IdxVisualRefinementsListener*(void) { return (Cxlookandfeels::IdxVisualRefinementsListener*)&__IdxVisualRefinementsListener; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {D0B5352A-B84A-407F-9269-7141054A8AB8}
	operator Dxfluentdesignforminterfaces::_di_IdxFluentDesignContainerControl()
	{
		Dxfluentdesignforminterfaces::_di_IdxFluentDesignContainerControl intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Dxfluentdesignforminterfaces::IdxFluentDesignContainerControl*(void) { return (Dxfluentdesignforminterfaces::IdxFluentDesignContainerControl*)&__IdxFluentDesignContainerControl; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {2DFA6D14-84FD-42EE-AF0C-CB418ABCA905}
	operator _di_IdxHybridScrollbarOwner()
	{
		_di_IdxHybridScrollbarOwner intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IdxHybridScrollbarOwner*(void) { return (IdxHybridScrollbarOwner*)&__IdxHybridScrollbarOwner; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {08D21768-F2CA-4F1B-99D6-AE30A59216CB}
	operator Dxdirectx::D2d::Canvas::_di_IdxDirect2DCanvasOwner()
	{
		Dxdirectx::D2d::Canvas::_di_IdxDirect2DCanvasOwner intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Dxdirectx::D2d::Canvas::IdxDirect2DCanvasOwner*(void) { return (Dxdirectx::D2d::Canvas::IdxDirect2DCanvasOwner*)&__IdxDirect2DCanvasOwner; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {CA4C2043-1558-4D5D-8DEB-DAD8652AFFB9}
	operator _di_IdxTouchScrollUIOwner()
	{
		_di_IdxTouchScrollUIOwner intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IdxTouchScrollUIOwner*(void) { return (IdxTouchScrollUIOwner*)&__IdxTouchScrollUIOwner; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {F137963E-6165-47F9-A4C7-96BB4EB91AE0}
	operator _di_IdxSystemInfoListener()
	{
		_di_IdxSystemInfoListener intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IdxSystemInfoListener*(void) { return (IdxSystemInfoListener*)&__IdxSystemInfoListener; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {8410B6D7-1A56-4599-4FE3-AE8C0E182032}
	operator Dxcore::_di_IdxLocalizerListener()
	{
		Dxcore::_di_IdxLocalizerListener intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Dxcore::IdxLocalizerListener*(void) { return (Dxcore::IdxLocalizerListener*)&__IdxLocalizerListener; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {4DF001DA-BE2C-4817-B75C-55171270D158}
	operator Dxtouch::_di_IdxGestureOwner()
	{
		Dxtouch::_di_IdxGestureOwner intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Dxtouch::IdxGestureOwner*(void) { return (Dxtouch::IdxGestureOwner*)&__IdxGestureOwner; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {834D1E09-D446-4E7E-9DE3-AE158BAA9B73}
	operator Dxtouch::_di_IdxGestureClient2()
	{
		Dxtouch::_di_IdxGestureClient2 intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Dxtouch::IdxGestureClient2*(void) { return (Dxtouch::IdxGestureClient2*)&__IdxGestureClient2; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {652B8A09-DAC8-4332-9206-C8905AEE7791}
	operator Dxtouch::_di_IdxGestureClient()
	{
		Dxtouch::_di_IdxGestureClient intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Dxtouch::IdxGestureClient*(void) { return (Dxtouch::IdxGestureClient*)&__IdxGestureClient; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {56771164-C253-40FF-B6D4-2A29D0C90236}
	operator Cxscrollbar::_di_IcxScrollBarOwner()
	{
		Cxscrollbar::_di_IcxScrollBarOwner intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Cxscrollbar::IcxScrollBarOwner*(void) { return (Cxscrollbar::IcxScrollBarOwner*)&__IcxScrollBarOwner; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {6065B58B-C557-4464-A67D-64183FD13F25}
	operator Cxlookandfeels::_di_IcxLookAndFeelContainer()
	{
		Cxlookandfeels::_di_IcxLookAndFeelContainer intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Cxlookandfeels::IcxLookAndFeelContainer*(void) { return (Cxlookandfeels::IcxLookAndFeelContainer*)&__IcxLookAndFeelContainer; }
	#endif
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxControlCanvas : public Cxgraphics::TcxCanvas
{
	typedef Cxgraphics::TcxCanvas inherited;
	
public:
	/* TcxCanvas.Create */ inline __fastcall virtual TcxControlCanvas(Vcl::Graphics::TCanvas* ACanvas) : Cxgraphics::TcxCanvas(ACanvas) { }
	/* TcxCanvas.Destroy */ inline __fastcall virtual ~TcxControlCanvas() { }
	
private:
	void *__IcxControlCanvas;	// Cxcustomcanvas::IcxControlCanvas 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {E40B5E3C-CD3C-4D2C-81DA-2A41800CA183}
	operator Cxcustomcanvas::_di_IcxControlCanvas()
	{
		Cxcustomcanvas::_di_IcxControlCanvas intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcustomcanvas::IcxControlCanvas*(void) { return (Cxcustomcanvas::IcxControlCanvas*)&__IcxControlCanvas; }
	#endif
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxControlHelper : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	__classmethod Vcl::Controls::TControl* __fastcall GetControlByObject(System::TObject* AObject);
	
public:
	__classmethod bool __fastcall CanSetParent(Vcl::Controls::TControl* AControl, Vcl::Controls::TControl* ANewParent);
	__classmethod void __fastcall ChangeScaleFactor(Vcl::Controls::TControl* AControl, Cxgeometry::TdxScaleFactor* ATargetScaleFactor)/* overload */;
	__classmethod void __fastcall ChangeScaleFactor(Vcl::Controls::TControl* AControl, int ATargetNumerator, int ATargetDenominator)/* overload */;
	__classmethod bool __fastcall DrawLockedState(Vcl::Graphics::TCanvas* ACanvas, Vcl::Controls::TWinControl* AOwnerControl, Vcl::Controls::TControl* AChildControl);
	__classmethod int __fastcall GetCurrentDPIFromControl(System::TObject* AObject);
	__classmethod System::Types::TPoint __fastcall GetOriginalParentSize(System::TObject* AObject);
	__classmethod void __fastcall ScaleForPPI(System::TObject* AObject, int ATargetPPI);
	__classmethod void __fastcall SetOriginalParentSize(System::TObject* AObject, const System::Types::TPoint &APoint);
	__classmethod void __fastcall UpdateScaleFactorOnParentChange(Vcl::Controls::TControl* AControl);
public:
	/* TObject.Create */ inline __fastcall TcxControlHelper() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxControlHelper() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxControlDefaultHandlerHelper : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod bool __fastcall Process(void *Message);
public:
	/* TObject.Create */ inline __fastcall TcxControlDefaultHandlerHelper() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxControlDefaultHandlerHelper() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxControlHintHelper : public Dxcustomhint::TcxCustomHintHelper
{
	typedef Dxcustomhint::TcxCustomHintHelper inherited;
	
protected:
	virtual TcxControl* __fastcall GetHintControl();
	virtual System::Types::TRect __fastcall GetHintControlBounds();
	virtual Vcl::Controls::TWinControl* __fastcall GetHintWinControl();
	virtual TcxControl* __fastcall GetOwnerControl() = 0 ;
	virtual Vcl::Controls::TWinControl* __fastcall GetOwnerWinControl();
public:
	/* TcxCustomHintHelper.Create */ inline __fastcall TcxControlHintHelper() : Dxcustomhint::TcxCustomHintHelper() { }
	/* TcxCustomHintHelper.Destroy */ inline __fastcall virtual ~TcxControlHintHelper() { }
	
};

#pragma pack(pop)

enum DECLSPEC_DENUM TdxAutoSizeMode : unsigned char { asNone, asAutoWidth, asAutoHeight, asAutoSize };

enum DECLSPEC_DENUM TdxChangeType : unsigned char { ctLight, ctMedium, ctHard };

enum DECLSPEC_DENUM TdxVisibilityType : unsigned char { vtPartially, vtFully, vtCentered };

__interface  INTERFACE_UUID("{7F141990-5975-4E6B-BFAF-03D378860F20}") IdxScrollingControl  : public System::IInterface 
{
	virtual int __fastcall GetLeftPos() = 0 ;
	virtual void __fastcall SetLeftPos(int Value) = 0 ;
	virtual int __fastcall GetTopPos() = 0 ;
	virtual void __fastcall SetTopPos(int Value) = 0 ;
	virtual System::Types::TSize __fastcall GetContentSize() = 0 ;
	virtual TcxControl* __fastcall GetInstance() = 0 ;
};

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxScrollingControlCustomScrollAnimationHelper : public Dxscrollanimation::TdxScrollAnimationHelper
{
	typedef Dxscrollanimation::TdxScrollAnimationHelper inherited;
	
private:
	TcxScrollingControl* FOwner;
	
protected:
	virtual bool __fastcall IsAnimationStartNeeded();
	__property TcxScrollingControl* Owner = {read=FOwner};
	
public:
	__fastcall virtual TcxScrollingControlCustomScrollAnimationHelper(TcxScrollingControl* AOwner);
public:
	/* {dxScrollAnimation}TdxCustomScrollAnimationHelper<System_Integer>.Destroy */ inline __fastcall virtual ~TcxScrollingControlCustomScrollAnimationHelper() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxScrollingControlVertScrollAnimationHelper : public TcxScrollingControlCustomScrollAnimationHelper
{
	typedef TcxScrollingControlCustomScrollAnimationHelper inherited;
	
protected:
	virtual void __fastcall AfterAnimationEnded(bool AIsRaiseEvent);
	virtual void __fastcall BeforeAnimationStarted();
	virtual void __fastcall CheckPosition(int &AValue);
	virtual int __fastcall GetOwnerPosition();
	virtual void __fastcall UpdateOwnerPosition(int AValue);
public:
	/* TcxScrollingControlCustomScrollAnimationHelper.Create */ inline __fastcall virtual TcxScrollingControlVertScrollAnimationHelper(TcxScrollingControl* AOwner) : TcxScrollingControlCustomScrollAnimationHelper(AOwner) { }
	
public:
	/* {dxScrollAnimation}TdxCustomScrollAnimationHelper<System_Integer>.Destroy */ inline __fastcall virtual ~TcxScrollingControlVertScrollAnimationHelper() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxScrollingControlHorzScrollAnimationHelper : public TcxScrollingControlCustomScrollAnimationHelper
{
	typedef TcxScrollingControlCustomScrollAnimationHelper inherited;
	
protected:
	virtual void __fastcall AfterAnimationEnded(bool AIsRaiseEvent);
	virtual void __fastcall CheckPosition(int &AValue);
	virtual int __fastcall GetOwnerPosition();
	virtual void __fastcall UpdateOwnerPosition(int AValue);
public:
	/* TcxScrollingControlCustomScrollAnimationHelper.Create */ inline __fastcall virtual TcxScrollingControlHorzScrollAnimationHelper(TcxScrollingControl* AOwner) : TcxScrollingControlCustomScrollAnimationHelper(AOwner) { }
	
public:
	/* {dxScrollAnimation}TdxCustomScrollAnimationHelper<System_Integer>.Destroy */ inline __fastcall virtual ~TcxScrollingControlHorzScrollAnimationHelper() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxScrollingControl : public TcxControl
{
	typedef TcxControl inherited;
	
private:
	TcxScrollingControlHorzScrollAnimationHelper* FHorzScrollAnimationHelper;
	TcxScrollingControlVertScrollAnimationHelper* FVertScrollAnimationHelper;
	int __fastcall GetTopPos();
	int __fastcall GetLeftPos();
	TcxControl* __fastcall GetInstance();
	
protected:
	TdxAutoSizeMode FAutoSizeMode;
	bool FAutoSizeModeSetting;
	int FLeftPos;
	int FTopPos;
	virtual void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	DYNAMIC void __fastcall BoundsChanged();
	virtual bool __fastcall CanCalculate();
	virtual void __fastcall Calculate(TdxChangeType AType);
	virtual bool __fastcall CanMakeVisibleAnimate();
	virtual void __fastcall CreateHandle();
	virtual void __fastcall LayoutChanged(TdxChangeType AType = (TdxChangeType)(0x2));
	virtual void __fastcall Loaded();
	virtual void __fastcall ScrollPosChanged(const System::Types::TPoint &AOffset);
	virtual bool __fastcall IsScrollDataValid();
	virtual int __fastcall GetScrollStep();
	virtual void __fastcall AfterHorzScrollAnimationEnded();
	virtual void __fastcall AfterVertScrollAnimationEnded();
	virtual void __fastcall BeforeVertScrollAnimationStarted();
	virtual void __fastcall DoMakeVisible(const System::Types::TPoint &P, bool AAnimated = false);
	bool __fastcall IsHorzScrollAnimationActive();
	bool __fastcall IsScrollAnimationActive();
	bool __fastcall IsVertScrollAnimationActive();
	bool __fastcall IsVertScrollAnimationProcessing();
	void __fastcall SetLeftPosAnimated(int AValue);
	void __fastcall SetTopPosAnimated(int AValue);
	void __fastcall StopScrollAnimation();
	virtual void __fastcall StopVertScrollAnimation();
	void __fastcall CheckPositions();
	void __fastcall CheckLeftTopPos(System::Types::TPoint &P);
	void __fastcall CheckLeftPos(int &AValue);
	void __fastcall CheckTopPos(int &AValue);
	virtual TcxScrollingControlCustomScrollAnimationHelper* __fastcall CreateScrollAnimationHelper(Vcl::Forms::TScrollBarKind AScrollKind);
	virtual System::Types::TSize __fastcall GetContentSize();
	virtual System::Types::TSize __fastcall GetClientSize();
	virtual void __fastcall InitScrollBarsParameters();
	void __fastcall MakeVisible(const System::Types::TRect &ARect, TdxVisibilityType AType)/* overload */;
	void __fastcall MakeVisible(const System::Types::TRect &ARect, const System::Types::TRect &AClientRect, TdxVisibilityType AType, bool ACheckHorizontalPosition, bool ACheckVerticalPosition)/* overload */;
	virtual void __fastcall SetAutoSize(bool Value);
	virtual void __fastcall SetAutoSizeMode(TdxAutoSizeMode AValue);
	void __fastcall SetLeftTop(const System::Types::TPoint &P, bool AAnimated = false);
	virtual void __fastcall SetLeftPos(int AValue);
	virtual void __fastcall SetTopPos(int AValue);
	virtual void __fastcall Scroll(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	__property TdxAutoSizeMode AutoSizeMode = {read=FAutoSizeMode, write=SetAutoSizeMode, nodefault};
	__property TcxScrollingControlHorzScrollAnimationHelper* HorzScrollAnimationHelper = {read=FHorzScrollAnimationHelper};
	__property int LeftPos = {read=GetLeftPos, write=SetLeftPos, nodefault};
	__property int TopPos = {read=GetTopPos, write=SetTopPos, nodefault};
	__property int ScrollStep = {read=GetScrollStep, nodefault};
	__property TcxScrollingControlVertScrollAnimationHelper* VertScrollAnimationHelper = {read=FVertScrollAnimationHelper};
	
public:
	__fastcall virtual TcxScrollingControl(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxScrollingControl();
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxScrollingControl(HWND ParentWindow) : TcxControl(ParentWindow) { }
	
private:
	void *__IdxScrollingControl;	// IdxScrollingControl 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {7F141990-5975-4E6B-BFAF-03D378860F20}
	operator _di_IdxScrollingControl()
	{
		_di_IdxScrollingControl intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IdxScrollingControl*(void) { return (IdxScrollingControl*)&__IdxScrollingControl; }
	#endif
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxScrollHelper : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	static const System::Int8 ScrollStep = System::Int8(0xa);
	
	
private:
	__classmethod void __fastcall CheckLeftPos(_di_IdxScrollingControl AControl, int &AValue);
	__classmethod void __fastcall CheckTopPos(_di_IdxScrollingControl AControl, int &AValue);
	__classmethod void __fastcall ScrollContent(_di_IdxScrollingControl AControl);
	
public:
	__classmethod void __fastcall CheckPositions(_di_IdxScrollingControl AControl);
	__classmethod void __fastcall SetPos(_di_IdxScrollingControl AControl, int X, int Y);
	__classmethod void __fastcall SetLeftPos(_di_IdxScrollingControl AControl, int AValue);
	__classmethod void __fastcall SetTopPos(_di_IdxScrollingControl AControl, int AValue);
	__classmethod bool __fastcall IsScrollDataValid(_di_IdxScrollingControl AControl);
	__classmethod void __fastcall GestureScroll(_di_IdxScrollingControl AControl, int ADeltaX, int ADeltaY);
	__classmethod System::Types::TSize __fastcall GetClientSize(_di_IdxScrollingControl AControl);
	__classmethod void __fastcall InitScrollBarsParameters(_di_IdxScrollingControl AControl);
	__classmethod void __fastcall Scroll(_di_IdxScrollingControl AControl, Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
public:
	/* TObject.Create */ inline __fastcall TdxScrollHelper() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxScrollHelper() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxCustomizeListBox : public Vcl::Stdctrls::TListBox
{
	typedef Vcl::Stdctrls::TListBox inherited;
	
private:
	int FDragAndDropItemIndex;
	System::Types::TPoint FMouseDownPos;
	System::TObject* __fastcall GetDragAndDropItemObject();
	System::TObject* __fastcall GetItemObject();
	void __fastcall SetItemObject(System::TObject* Value);
	HIDESBASE MESSAGE void __fastcall WMCancelMode(Winapi::Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall WMMouseMove(Winapi::Messages::TWMMouse &Message);
	
protected:
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall BeginDragAndDrop();
	__property int DragAndDropItemIndex = {read=FDragAndDropItemIndex, nodefault};
	__property System::TObject* DragAndDropItemObject = {read=GetDragAndDropItemObject};
	
public:
	__fastcall virtual TcxCustomizeListBox(System::Classes::TComponent* AOwner);
	__property System::TObject* ItemObject = {read=GetItemObject, write=SetItemObject};
public:
	/* TCustomListBox.Destroy */ inline __fastcall virtual ~TcxCustomizeListBox() { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomizeListBox(HWND ParentWindow) : Vcl::Stdctrls::TListBox(ParentWindow) { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxMessageWindow : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	HWND FHandle;
	void __fastcall MainWndProc(Winapi::Messages::TMessage &Message);
	
protected:
	virtual bool __fastcall IsMessageOnlyWindow();
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	
public:
	__fastcall virtual TcxMessageWindow();
	__fastcall virtual ~TcxMessageWindow();
	__property HWND Handle = {read=FHandle, nodefault};
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxSystemController : public TcxMessageWindow
{
	typedef TcxMessageWindow inherited;
	
private:
	System::Classes::TNotifyEvent FPrevWakeMainThread;
	void __fastcall WakeMainThread(System::TObject* Sender);
	void __fastcall HookSynchronizeWakeup();
	void __fastcall UnhookSynchronizeWakeup();
	
protected:
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	
public:
	__fastcall virtual TcxSystemController();
	__fastcall virtual ~TcxSystemController();
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSystemInfo : public TcxMessageWindow
{
	typedef TcxMessageWindow inherited;
	
private:
	bool FIsDropShadow;
	System::Classes::TInterfaceList* FListeners;
	tagNONCLIENTMETRICSW FNonClientMetrics;
	bool FUseMouseWheelRouting;
	bool __fastcall GetIsRemoteSession();
	bool __fastcall GetUseMouseWheelRouting();
	void __fastcall UpdateCache(unsigned AParameter);
	
protected:
	virtual bool __fastcall IsMessageOnlyWindow();
	void __fastcall NotifyListeners(unsigned AParameter);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	
public:
	__fastcall virtual TdxSystemInfo();
	__fastcall virtual ~TdxSystemInfo();
	void __fastcall AddListener(_di_IdxSystemInfoListener AListener);
	bool __fastcall GetParameter(unsigned AParameter, void *AValue);
	void __fastcall RemoveListener(_di_IdxSystemInfoListener AListener);
	__property bool IsDropShadow = {read=FIsDropShadow, nodefault};
	__property bool IsRemoteSession = {read=GetIsRemoteSession, nodefault};
	__property tagNONCLIENTMETRICSW NonClientMetrics = {read=FNonClientMetrics};
	__property bool UseMouseWheelRouting = {read=FUseMouseWheelRouting, nodefault};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxMessagesController : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Classes::TList* FLockedMessages;
	
protected:
	void *FOldWndProc;
	
public:
	__fastcall TdxMessagesController();
	__fastcall virtual ~TdxMessagesController();
	bool __fastcall IsMessageInQueue(NativeUInt AWnd, unsigned AMessage);
	bool __fastcall KillMessages(NativeUInt AWnd, unsigned AMsgFilterMin, unsigned AMsgFilterMax = (unsigned)(0x0), bool AKillAllMessages = true);
	bool __fastcall IsMessageLocked(unsigned AMessage);
	void __fastcall LockMessages(unsigned *AMessages, const int AMessages_High);
	void __fastcall UnlockMessages(unsigned *AMessages, const int AMessages_High);
	void __fastcall BlockMessage(NativeUInt AHandle);
	void __fastcall BlockLockedMessage(NativeUInt AHandle, unsigned &AMessage);
};

#pragma pack(pop)

enum DECLSPEC_DENUM TcxPopupAlignHorz : unsigned char { pahLeft, pahCenter, pahRight };

enum DECLSPEC_DENUM TcxPopupAlignVert : unsigned char { pavTop, pavCenter, pavBottom };

enum DECLSPEC_DENUM TcxPopupDirection : unsigned char { pdHorizontal, pdVertical };

class PASCALIMPLEMENTATION TcxPopupWindow : public Dxforms::TdxCustomForm
{
	typedef Dxforms::TdxCustomForm inherited;
	
private:
	bool FAcceptAnyPosition;
	bool FAdjustable;
	TcxPopupAlignHorz FAlignHorz;
	TcxPopupAlignVert FAlignVert;
	int FBorderSpace;
	Cxlookandfeelpainters::TcxPopupBorderStyle FBorderStyle;
	Cxgraphics::TcxCanvas* FCanvas;
	TcxPopupDirection FDirection;
	System::Uitypes::TColor FFrameColor;
	bool FIsOwnerBoundsRTLDependent;
	System::Types::TRect FOwnerBounds;
	Vcl::Controls::TControl* FOwnerParent;
	HWND FPrevActiveWindow;
	int __fastcall GetNCHeight();
	int __fastcall GetNCWidth();
	void __fastcall SetAdjustable(bool AValue);
	void __fastcall SetBorderSpace(int Value);
	HIDESBASE void __fastcall SetBorderStyle(Cxlookandfeelpainters::TcxPopupBorderStyle Value);
	HIDESBASE MESSAGE void __fastcall WMActivate(Winapi::Messages::TWMActivate &Message);
	MESSAGE void __fastcall WMActivateApp(Winapi::Messages::TWMActivateApp &Message);
	HIDESBASE MESSAGE void __fastcall CMVisibleChanged(Winapi::Messages::TMessage &Message);
	
protected:
	DYNAMIC void __fastcall Deactivate();
	DYNAMIC void __fastcall Paint();
	DYNAMIC void __fastcall VisibleChanged();
	virtual void __fastcall InternalCalculateHorizontalDirectionPosition(System::Types::TPoint &APosition, System::Types::TPoint &AOrigin, const System::Types::TSize &ASize);
	virtual void __fastcall InternalCalculateVerticalDirectionPosition(System::Types::TPoint &APosition, System::Types::TPoint &AOrigin, const System::Types::TSize &ASize);
	virtual void __fastcall InternalCalculateTargetPosition(System::Types::TPoint &APosition, System::Types::TPoint &AOrigin, const System::Types::TSize &ASize);
	virtual void __fastcall AdjustableChanged();
	virtual void __fastcall BordersChanged();
	virtual void __fastcall CalculateCommonPosition(System::Types::TPoint &APosition, System::Types::TPoint &AOrigin, const System::Types::TSize &ASize);
	virtual System::Types::TPoint __fastcall CalculatePosition(const System::Types::TSize &ASize);
	virtual System::Types::TSize __fastcall CalculateSize();
	virtual void __fastcall CheckPosition(System::Types::TPoint &APosition, System::Types::TPoint &AOrigin, const System::Types::TSize &ASize);
	virtual void __fastcall CorrectPositionWithDesktopWorkArea(System::Types::TPoint &APosition, System::Types::TPoint &AOrigin, const System::Types::TSize &ASize);
	virtual int __fastcall GetBorderWidth(Cxgeometry::TcxBorder ABorder);
	virtual System::Types::TRect __fastcall GetClientBounds();
	TcxPopupAlignHorz __fastcall GetDefaultAlignHorz();
	virtual int __fastcall GetFrameWidth(Cxgeometry::TcxBorder ABorder);
	virtual System::Types::TRect __fastcall GetOwnerScreenBounds();
	virtual void __fastcall InitPopup();
	void __fastcall RestoreControlsBounds();
	virtual bool __fastcall UseOwnerParentToGetScreenBounds();
	virtual void __fastcall DrawFrame();
	bool __fastcall IsSkinnable();
	__property bool AcceptAnyPosition = {read=FAcceptAnyPosition, write=FAcceptAnyPosition, nodefault};
	__property int BorderWidths[Cxgeometry::TcxBorder ABorder] = {read=GetBorderWidth};
	__property Cxgraphics::TcxCanvas* Canvas = {read=FCanvas};
	__property int FrameWidths[Cxgeometry::TcxBorder ABorder] = {read=GetFrameWidth};
	__property int NCHeight = {read=GetNCHeight, nodefault};
	__property int NCWidth = {read=GetNCWidth, nodefault};
	__property bool IsOwnerBoundsRTLDependent = {read=FIsOwnerBoundsRTLDependent, write=FIsOwnerBoundsRTLDependent, nodefault};
	
public:
	__fastcall virtual TcxPopupWindow();
	__fastcall virtual ~TcxPopupWindow();
	virtual void __fastcall CloseUp();
	virtual void __fastcall Popup();
	__property bool Adjustable = {read=FAdjustable, write=SetAdjustable, nodefault};
	__property TcxPopupAlignHorz AlignHorz = {read=FAlignHorz, write=FAlignHorz, nodefault};
	__property TcxPopupAlignVert AlignVert = {read=FAlignVert, write=FAlignVert, nodefault};
	__property int BorderSpace = {read=FBorderSpace, write=SetBorderSpace, nodefault};
	__property Cxlookandfeelpainters::TcxPopupBorderStyle BorderStyle = {read=FBorderStyle, write=SetBorderStyle, nodefault};
	__property System::Types::TRect ClientBounds = {read=GetClientBounds};
	__property TcxPopupDirection Direction = {read=FDirection, write=FDirection, nodefault};
	__property System::Uitypes::TColor FrameColor = {read=FFrameColor, write=FFrameColor, nodefault};
	__property System::Types::TRect OwnerBounds = {read=FOwnerBounds, write=FOwnerBounds};
	__property Vcl::Controls::TControl* OwnerParent = {read=FOwnerParent, write=FOwnerParent};
	__property System::Types::TRect OwnerScreenBounds = {read=GetOwnerScreenBounds};
	__property AlphaBlend;
	__property AlphaBlendValue;
	__property AutoScroll = {default=0};
	__property AutoSize = {default=0};
	__property BorderIcons = {default=7};
	__property BorderWidth = {default=0};
	__property TransparentColor;
	__property TransparentColorValue;
	__property Ctl3D = {default=1};
	__property DefaultMonitor = {default=3};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property ParentFont = {default=0};
	__property FormStyle = {default=0};
	__property Icon;
	__property ObjectMenuItem;
	__property ParentBiDiMode = {default=1};
	__property PixelsPerInch;
	__property PopupMenu;
	__property Position = {default=2};
	__property PrintScale = {default=1};
	__property TipMode = {default=2};
	__property WindowMenu;
	__property OnActivate;
	__property OnCanResize;
	__property OnClick;
	__property OnClose;
	__property OnCloseQuery;
	__property OnConstrainedResize;
	__property OnContextPopup;
	__property OnCreate;
	__property OnDblClick;
	__property OnDestroy;
	__property OnDeactivate;
	__property OnDockDrop;
	__property OnDockOver;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEndDock;
	__property OnGetSiteInfo;
	__property OnHide;
	__property OnHelp;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseActivate;
	__property OnMouseDown;
	__property OnMouseEnter;
	__property OnMouseLeave;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnMouseWheel;
	__property OnMouseWheelDown;
	__property OnMouseWheelUp;
	__property OnPaint;
	__property OnResize;
	__property OnShortCut;
	__property OnShow;
	__property OnStartDock;
	__property OnUnDock;
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxPopupWindow(System::Classes::TComponent* AOwner, int Dummy) : Dxforms::TdxCustomForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxPopupWindow(HWND ParentWindow) : Dxforms::TdxCustomForm(ParentWindow) { }
	
private:
	void *__IdxSkinSupport2;	// Cxlookandfeels::IdxSkinSupport2 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {01C435BA-7DA1-44A4-BE8B-BCE9CE0562AB}
	operator Cxlookandfeels::_di_IdxSkinSupport2()
	{
		Cxlookandfeels::_di_IdxSkinSupport2 intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Cxlookandfeels::IdxSkinSupport2*(void) { return (Cxlookandfeels::IdxSkinSupport2*)&__IdxSkinSupport2; }
	#endif
	
};


class PASCALIMPLEMENTATION TcxCustomDragImage : public Vcl::Controls::TCustomControl
{
	typedef Vcl::Controls::TCustomControl inherited;
	
private:
	bool FAlphaBlend;
	System::Byte FAlphaBlendValue;
	Cxgraphics::TcxCanvas* FCanvas;
	Vcl::Controls::TWinControl* FPopupParent;
	System::Types::TPoint FPositionOffset;
	bool FTransparentColor;
	System::Uitypes::TColor FTransparentColorValue;
	bool __fastcall GetAlphaBlended();
	bool __fastcall GetVisible();
	void __fastcall SetAlphaBlend(bool Value);
	void __fastcall SetAlphaBlendValue(System::Byte Value);
	void __fastcall SetPopupParent(Vcl::Controls::TWinControl* const Value);
	HIDESBASE void __fastcall SetVisible(bool Value);
	void __fastcall SetTransparentColor(bool Value);
	void __fastcall SetTransparentColorValue(System::Uitypes::TColor Value);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Winapi::Messages::TWMEraseBkgnd &Message);
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Winapi::Messages::TWMNCHitTest &Message);
	
protected:
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall UpdateLayeredAttributes();
	virtual bool __fastcall IsSkinnable();
	__property bool AlphaBlend = {read=FAlphaBlend, write=SetAlphaBlend, nodefault};
	__property System::Byte AlphaBlendValue = {read=FAlphaBlendValue, write=SetAlphaBlendValue, nodefault};
	__property Cxgraphics::TcxCanvas* Canvas = {read=FCanvas};
	__property bool TransparentColor = {read=FTransparentColor, write=SetTransparentColor, nodefault};
	__property System::Uitypes::TColor TransparentColorValue = {read=FTransparentColorValue, write=SetTransparentColorValue, nodefault};
	
public:
	__fastcall virtual TcxCustomDragImage();
	__fastcall virtual ~TcxCustomDragImage();
	void __fastcall Init(const System::Types::TRect &ASourceBounds, const System::Types::TPoint &ASourcePoint);
	void __fastcall MoveTo(const System::Types::TPoint &APosition);
	void __fastcall Offset(int X, int Y);
	HIDESBASE void __fastcall Show(int ACmdShow = 0x8);
	HIDESBASE void __fastcall Hide();
	__property bool AlphaBlended = {read=GetAlphaBlended, nodefault};
	__property Vcl::Controls::TWinControl* PopupParent = {read=FPopupParent, write=SetPopupParent};
	__property System::Types::TPoint PositionOffset = {read=FPositionOffset, write=FPositionOffset};
	__property bool Visible = {read=GetVisible, write=SetVisible, nodefault};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomDragImage(HWND ParentWindow) : Vcl::Controls::TCustomControl(ParentWindow) { }
	
private:
	void *__IdxSkinSupport2;	// Cxlookandfeels::IdxSkinSupport2 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {01C435BA-7DA1-44A4-BE8B-BCE9CE0562AB}
	operator Cxlookandfeels::_di_IdxSkinSupport2()
	{
		Cxlookandfeels::_di_IdxSkinSupport2 intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Cxlookandfeels::IdxSkinSupport2*(void) { return (Cxlookandfeels::IdxSkinSupport2*)&__IdxSkinSupport2; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {EF3FF483-9B69-46DF-95A4-D3A3810F63A5}
	operator Cxlookandfeels::_di_IdxSkinSupport()
	{
		Cxlookandfeels::_di_IdxSkinSupport intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Cxlookandfeels::IdxSkinSupport*(void) { return (Cxlookandfeels::IdxSkinSupport*)&__IdxSkinSupport2; }
	#endif
	
};


typedef System::TMetaClass* TcxDragImageClass;

class PASCALIMPLEMENTATION TcxDragImage : public TcxCustomDragImage
{
	typedef TcxCustomDragImage inherited;
	
private:
	Cxgraphics::TcxAlphaBitmap* FImage;
	Cxgraphics::TcxCanvas* __fastcall GetImageCanvas();
	Cxgraphics::TcxCanvas* __fastcall GetWindowCanvas();
	
protected:
	virtual void __fastcall Paint();
	__property Cxgraphics::TcxAlphaBitmap* Image = {read=FImage};
	__property Cxgraphics::TcxCanvas* WindowCanvas = {read=GetWindowCanvas};
	
public:
	__fastcall virtual TcxDragImage();
	__fastcall virtual ~TcxDragImage();
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	__property Cxgraphics::TcxCanvas* Canvas = {read=GetImageCanvas};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxDragImage(HWND ParentWindow) : TcxCustomDragImage(ParentWindow) { }
	
};


class PASCALIMPLEMENTATION TcxLayeredDragImage : public TcxDragImage
{
	typedef TcxDragImage inherited;
	
protected:
	virtual void __fastcall Paint();
	virtual void __fastcall UpdateLayeredAttributes();
	
public:
	virtual void __fastcall Invalidate();
	virtual void __fastcall Update();
public:
	/* TcxDragImage.Create */ inline __fastcall virtual TcxLayeredDragImage() : TcxDragImage() { }
	/* TcxDragImage.Destroy */ inline __fastcall virtual ~TcxLayeredDragImage() { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxLayeredDragImage(HWND ParentWindow) : TcxDragImage(ParentWindow) { }
	
};


class PASCALIMPLEMENTATION TcxSizeFrame : public TcxCustomDragImage
{
	typedef TcxCustomDragImage inherited;
	
private:
	bool FFillSelection;
	int FFrameWidth;
	Cxgraphics::TcxRegion* FRegion;
	void __fastcall InitializeFrameRegion();
	void __fastcall SetWindowRegion();
	
protected:
	virtual void __fastcall Paint();
	__property int FrameWidth = {read=FFrameWidth, nodefault};
	
public:
	__fastcall virtual TcxSizeFrame(int AFrameWidth);
	__fastcall virtual ~TcxSizeFrame();
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	void __fastcall DrawSizeFrame(const System::Types::TRect &ARect)/* overload */;
	void __fastcall DrawSizeFrame(const System::Types::TRect &ARect, Cxgraphics::TcxRegion* const ARegion)/* overload */;
	__property bool FillSelection = {read=FFillSelection, write=FFillSelection, nodefault};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxSizeFrame(HWND ParentWindow) : TcxCustomDragImage(ParentWindow) { }
	
};


enum DECLSPEC_DENUM TcxArrowPlace : unsigned char { apLeft, apTop, apRight, apBottom };

typedef System::TMetaClass* TcxDragAndDropArrowClass;

class PASCALIMPLEMENTATION TcxDragAndDropArrow : public TcxDragImage
{
	typedef TcxDragImage inherited;
	
private:
	static const int DragAndDropArrowBorderColor = int(0);
	
	static const int DragAndDropArrowColor = int(65280);
	
	System::Uitypes::TColor FBorderColor;
	System::Uitypes::TColor FColor;
	bool FTransparent;
	__classmethod void __fastcall ApplyColors(Vcl::Graphics::TBitmap* ABitmap, System::Uitypes::TColor AArrowBorderColor, System::Uitypes::TColor AArrowColor);
	bool __fastcall GetTransparent();
	
protected:
	virtual System::Uitypes::TColor __fastcall GetImageBackColor();
	
public:
	__fastcall virtual TcxDragAndDropArrow(bool ATransparent);
	HIDESBASE void __fastcall Init(Vcl::Controls::TControl* AOwner, const System::Types::TRect &AAreaBounds, const System::Types::TRect &AClientRect, TcxArrowPlace APlace)/* overload */;
	HIDESBASE void __fastcall Init(const System::Types::TPoint &AOwnerOrigin, const System::Types::TRect &AAreaBounds, const System::Types::TRect &AClientRect, TcxArrowPlace APlace)/* overload */;
	__classmethod System::Types::TRect __fastcall CalculateBounds(const System::Types::TRect &AAreaBounds, const System::Types::TRect &AClientRect, TcxArrowPlace APlace, Cxgeometry::TdxScaleFactor* AScaleFactor, bool AUseRightToLeftAlignment)/* overload */;
	__classmethod System::Types::TRect __fastcall CalculateBounds(const System::Types::TRect &AAreaBounds, const System::Types::TRect &AClientRect, TcxArrowPlace APlace, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	__classmethod Vcl::Graphics::TBitmap* __fastcall GetGlyph(TcxArrowPlace APlace, Cxgeometry::TdxScaleFactor* AScaleFactor);
	__classmethod void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, TcxArrowPlace APlace, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	__classmethod void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, TcxArrowPlace APlace, System::Uitypes::TColor AArrowBorderColor, System::Uitypes::TColor AArrowColor, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	__property System::Uitypes::TColor BorderColor = {read=FBorderColor, write=FBorderColor, nodefault};
	__property System::Uitypes::TColor Color = {read=FColor, write=FColor, nodefault};
	__property System::Uitypes::TColor ImageBackColor = {read=GetImageBackColor, nodefault};
	__property bool Transparent = {read=GetTransparent, nodefault};
public:
	/* TcxDragImage.Destroy */ inline __fastcall virtual ~TcxDragAndDropArrow() { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxDragAndDropArrow(HWND ParentWindow) : TcxDragImage(ParentWindow) { }
	
};


enum DECLSPEC_DENUM TcxDesignState : unsigned char { dsDesignerModifying };

typedef System::Set<TcxDesignState, TcxDesignState::dsDesignerModifying, TcxDesignState::dsDesignerModifying> TcxDesignStates;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDesignController : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FLockDesignerModifiedCount;
	
protected:
	TcxDesignStates FState;
	
public:
	void __fastcall DesignerModified(Vcl::Forms::TCustomForm* AForm)/* overload */;
	bool __fastcall IsDesignerModifiedLocked();
	void __fastcall LockDesignerModified();
	void __fastcall UnLockDesignerModified();
public:
	/* TObject.Create */ inline __fastcall TcxDesignController() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDesignController() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxWindowProcLinkedObject : public Dxcoreclasses::TcxDoublyLinkedObject
{
	typedef Dxcoreclasses::TcxDoublyLinkedObject inherited;
	
private:
	Vcl::Controls::TControl* FControl;
	NativeUInt FHandle;
	System::Classes::TWndMethod FWindowProc;
	
protected:
	__property System::Classes::TWndMethod WindowProc = {read=FWindowProc, write=FWindowProc};
	
public:
	__fastcall TcxWindowProcLinkedObject(Vcl::Controls::TControl* AControl)/* overload */;
	__fastcall TcxWindowProcLinkedObject(NativeUInt AHandle)/* overload */;
	void __fastcall DefaultProc(Winapi::Messages::TMessage &Message);
	__property Vcl::Controls::TControl* Control = {read=FControl};
	__property NativeUInt Handle = {read=FHandle, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxWindowProcLinkedObject() { }
	
};


class PASCALIMPLEMENTATION TcxSubclassingHelper : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	System::Classes::TWndMethod FDefaultWindowProc;
	virtual Dxcoreclasses::TcxDoublyLinkedObject* __fastcall CreateLinkedObject() = 0 ;
	virtual void __fastcall RestoreDefaultProc() = 0 ;
	virtual void __fastcall StoreAndReplaceDefaultProc(System::Classes::TWndMethod AWndProc) = 0 ;
	__property System::Classes::TWndMethod DefaultWindowProc = {read=FDefaultWindowProc};
public:
	/* TObject.Create */ inline __fastcall TcxSubclassingHelper() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSubclassingHelper() { }
	
};


class PASCALIMPLEMENTATION TcxVCLSubclassingHelper : public TcxSubclassingHelper
{
	typedef TcxSubclassingHelper inherited;
	
private:
	Vcl::Controls::TControl* FControl;
	
protected:
	virtual Dxcoreclasses::TcxDoublyLinkedObject* __fastcall CreateLinkedObject();
	virtual void __fastcall RestoreDefaultProc();
	virtual void __fastcall StoreAndReplaceDefaultProc(System::Classes::TWndMethod AWndProc);
	
public:
	__fastcall TcxVCLSubclassingHelper(Vcl::Controls::TControl* AControl);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxVCLSubclassingHelper() { }
	
};


class PASCALIMPLEMENTATION TcxWin32SubclassingHelper : public TcxSubclassingHelper
{
	typedef TcxSubclassingHelper inherited;
	
private:
	void *FAPIDefaultWndProc;
	void *FAPIWndProc;
	NativeUInt FHandle;
	
protected:
	virtual Dxcoreclasses::TcxDoublyLinkedObject* __fastcall CreateLinkedObject();
	void __fastcall DefaultWndProc(Winapi::Messages::TMessage &Message);
	virtual void __fastcall RestoreDefaultProc();
	virtual void __fastcall StoreAndReplaceDefaultProc(System::Classes::TWndMethod AWndProc);
	
public:
	__fastcall TcxWin32SubclassingHelper(NativeUInt AHandle);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxWin32SubclassingHelper() { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxWindowProcLinkedObjectList : public Dxcoreclasses::TcxDoublyLinkedObjectList
{
	typedef Dxcoreclasses::TcxDoublyLinkedObjectList inherited;
	
private:
	Vcl::Controls::TControl* FControl;
	NativeUInt FHandle;
	TcxSubclassingHelper* FHelper;
	
protected:
	TcxWindowProcLinkedObject* __fastcall AddProc(System::Classes::TWndMethod AWndProc);
	virtual Dxcoreclasses::TcxDoublyLinkedObject* __fastcall CreateLinkedObject();
	virtual void __fastcall Initialize();
	bool __fastcall IsEmpty();
	void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	__property Vcl::Controls::TControl* Control = {read=FControl};
	__property NativeUInt Handle = {read=FHandle, nodefault};
	
public:
	__fastcall TcxWindowProcLinkedObjectList(Vcl::Controls::TControl* AControl)/* overload */;
	__fastcall TcxWindowProcLinkedObjectList(NativeUInt AHandle)/* overload */;
	__fastcall virtual ~TcxWindowProcLinkedObjectList();
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxWindowProcController : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Cxclasses::TcxObjectList* FWindowProcObjects;
	TcxWindowProcLinkedObjectList* __fastcall GetControlWindowProcObjects(Vcl::Controls::TControl* AControl)/* overload */;
	TcxWindowProcLinkedObjectList* __fastcall GetControlWindowProcObjects(NativeUInt AHandle)/* overload */;
	
public:
	__fastcall TcxWindowProcController();
	__fastcall virtual ~TcxWindowProcController();
	TcxWindowProcLinkedObject* __fastcall Add(Vcl::Controls::TControl* AControl, System::Classes::TWndMethod AWndProc)/* overload */;
	TcxWindowProcLinkedObject* __fastcall Add(NativeUInt AHandle, System::Classes::TWndMethod AWndProc)/* overload */;
	void __fastcall Remove(TcxWindowProcLinkedObject* &AWndProcObject);
};

#pragma pack(pop)

__interface  INTERFACE_UUID("{EB45AB76-3681-4838-BDA8-7D0081B4C184}") IcxLockedStatePaint  : public System::IInterface 
{
	virtual Cxgraphics::TcxBitmap32* __fastcall GetImage() = 0 ;
	virtual TcxControl* __fastcall GetTopmostControl() = 0 ;
};

__interface  INTERFACE_UUID("{825BFA90-77C6-4725-BE95-B0A1EA8F934D}") IcxLockedStateFontChanged  : public System::IInterface 
{
	virtual void __fastcall FontChanged(Vcl::Graphics::TFont* AFont) = 0 ;
};

enum DECLSPEC_DENUM TcxLockedStateImageShowingMode : unsigned char { lsimNever, lsimPending, lsimImmediate };

enum DECLSPEC_DENUM TcxLockedStateImageEffect : unsigned char { lsieNone, lsieLight, lsieDark };

enum DECLSPEC_DENUM TcxLockedStateImageAssignedValue : unsigned char { lsiavFont, lsiavColor };

typedef System::Set<TcxLockedStateImageAssignedValue, TcxLockedStateImageAssignedValue::lsiavFont, TcxLockedStateImageAssignedValue::lsiavColor> TcxLockedStateImageAssignedValues;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxLockedStateImageOptions : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TcxLockedStateImageAssignedValues FAssignedValues;
	System::Uitypes::TColor FColor;
	TcxLockedStateImageEffect FEffect;
	bool FEnabled;
	Vcl::Graphics::TFont* FFont;
	System::Classes::TComponent* FOwner;
	bool FShowText;
	System::UnicodeString FText;
	void __fastcall FontChanged(System::TObject* Sender);
	bool __fastcall IsFontStored();
	void __fastcall SetColor(const System::Uitypes::TColor Value);
	void __fastcall SetFont(Vcl::Graphics::TFont* const Value);
	void __fastcall SetAssignedValues(const TcxLockedStateImageAssignedValues Value);
	
protected:
	virtual void __fastcall ChangeScale(int M, int D);
	virtual Vcl::Graphics::TFont* __fastcall GetFont() = 0 ;
	virtual bool __fastcall IsTextStored();
	__property System::Classes::TComponent* Owner = {read=FOwner};
	
public:
	__fastcall virtual TcxLockedStateImageOptions(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxLockedStateImageOptions();
	virtual void __fastcall AfterConstruction();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall UpdateFont(Vcl::Graphics::TFont* AFont);
	__property bool Enabled = {read=FEnabled, write=FEnabled, default=1};
	
__published:
	__property TcxLockedStateImageAssignedValues AssignedValues = {read=FAssignedValues, write=SetAssignedValues, default=0};
	__property System::Uitypes::TColor Color = {read=FColor, write=SetColor, default=536870911};
	__property TcxLockedStateImageEffect Effect = {read=FEffect, write=FEffect, default=0};
	__property Vcl::Graphics::TFont* Font = {read=FFont, write=SetFont, stored=IsFontStored};
	__property bool ShowText = {read=FShowText, write=FShowText, default=0};
	__property System::UnicodeString Text = {read=FText, write=FText, stored=IsTextStored};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxLockedStatePaintHelper : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Cxgraphics::TcxBitmap32* FBitmap;
	int FCount;
	bool FCreatingImage;
	bool FIsImageReady;
	System::Classes::TComponent* FOwner;
	System::Uitypes::TColor __fastcall GetColor();
	TcxLockedStateImageEffect __fastcall GetEffect();
	Vcl::Graphics::TFont* __fastcall GetFont();
	System::UnicodeString __fastcall GetText();
	
protected:
	void __fastcall CreateImage();
	void __fastcall DrawText();
	virtual void __fastcall PrepareImage();
	void __fastcall ValidateImage();
	virtual void __fastcall AfterDestroyingImage();
	virtual void __fastcall BeforeCreatingImage();
	virtual bool __fastcall CanCreateLockedImage();
	virtual bool __fastcall CanControlPaint();
	virtual bool __fastcall DoPrepareImage();
	virtual TcxLockedStateImageOptions* __fastcall GetOptions() = 0 ;
	virtual TcxControl* __fastcall GetControl() = 0 ;
	virtual Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetPainter();
	__property Cxgraphics::TcxBitmap32* Bitmap = {read=FBitmap};
	__property System::Uitypes::TColor Color = {read=GetColor, nodefault};
	__property TcxControl* Control = {read=GetControl};
	__property bool CreatingImage = {read=FCreatingImage, nodefault};
	__property TcxLockedStateImageEffect Effect = {read=GetEffect, nodefault};
	__property Vcl::Graphics::TFont* Font = {read=GetFont};
	__property bool IsImageReady = {read=FIsImageReady, nodefault};
	__property TcxLockedStateImageOptions* Options = {read=GetOptions};
	__property System::Classes::TComponent* Owner = {read=FOwner};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* Painter = {read=GetPainter};
	__property System::UnicodeString Text = {read=GetText};
	
public:
	__fastcall virtual TcxLockedStatePaintHelper(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxLockedStatePaintHelper();
	void __fastcall BeginLockedPaint(TcxLockedStateImageShowingMode AMode);
	void __fastcall EndLockedPaint();
	virtual Cxgraphics::TcxCanvas* __fastcall GetActiveCanvas();
	Cxgraphics::TcxBitmap32* __fastcall GetImage();
	bool __fastcall IsActive();
};

#pragma pack(pop)

__interface  INTERFACE_UUID("{AD2130FB-EDA5-4034-A551-9C26A8DAAE41}") IdxCustomizeControlsHelper  : public System::IInterface 
{
	virtual bool __fastcall CanProcessChildren() = 0 ;
};

typedef System::TMetaClass* TdxControlsDesignSelectorHelperClass;

class PASCALIMPLEMENTATION TdxControlsDesignSelectorHelper : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	static System::Generics::Collections::TObjectDictionary__2<int,Cxgraphics::TcxBitmap*>* FSelectorCache;
	
private:
	Vcl::Controls::TControl* FControl;
	bool FChecked;
	Cxclasses::TcxComponentList* FChildren;
	TdxControlsDesignSelectorHelper* FParent;
	System::Types::TRect FSelectorBounds;
	TcxWindowProcLinkedObject* FWindowProcObject;
	NativeUInt __fastcall GetControlWnd();
	Vcl::Controls::TWinControl* __fastcall GetParentControl();
	bool __fastcall PointInSelectorBounds(const System::Types::TPoint &P);
	void __fastcall SetSelectorBounds(const System::Types::TRect &AValue);
	__classmethod void __fastcall Initialize();
	__classmethod void __fastcall Finalize();
	
protected:
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	void __fastcall CallDefaultWndProc(Winapi::Messages::TMessage &Message);
	void __fastcall ControlWndProc(Winapi::Messages::TMessage &Message);
	virtual bool __fastcall DoControlWndProc(Winapi::Messages::TMessage &Message);
	virtual bool __fastcall IsHitTestTransparent(const System::Types::TPoint &P);
	virtual void __fastcall CheckChildren();
	virtual void __fastcall DestroyChild(TdxControlsDesignSelectorHelper* AChild);
	virtual TdxControlsDesignSelectorHelperClass __fastcall GetChildClass();
	virtual void __fastcall PrepareChild(TdxControlsDesignSelectorHelper* AItem);
	System::Types::TRect __fastcall GetSelectorBoundsForChild(TdxControlsDesignSelectorHelper* AChild);
	System::Types::TPoint __fastcall ClientToScreen(const System::Types::TPoint &P);
	System::Types::TPoint __fastcall ScreenToClient(const System::Types::TPoint &P);
	virtual bool __fastcall IsActiveDesignSelector();
	virtual bool __fastcall IsSelected();
	virtual bool __fastcall IsValid();
	bool __fastcall IsWinControl();
	Vcl::Controls::TWinControl* __fastcall ControlAsWinControl();
	virtual bool __fastcall CanDrawDesignSelector();
	virtual void __fastcall DoDrawDesignSelector(HDC DC);
	void __fastcall DrawDesignSelector(HDC DC);
	__classmethod void __fastcall DrawDesignSelectorRect(HDC DC, const System::Types::TRect &ARect, bool ASelected);
	void __fastcall StoreWndProc();
	void __fastcall RestoreWndProc();
	__property Cxclasses::TcxComponentList* Children = {read=FChildren};
	__property NativeUInt ControlWnd = {read=GetControlWnd, nodefault};
	__property TdxControlsDesignSelectorHelper* Parent = {read=FParent, write=FParent};
	__property Vcl::Controls::TWinControl* ParentControl = {read=GetParentControl};
	
public:
	__fastcall virtual TdxControlsDesignSelectorHelper(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxControlsDesignSelectorHelper();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__classmethod System::Types::TRect __fastcall CalculateBounds(const System::Types::TRect &R, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	__classmethod System::Types::TRect __fastcall CalculateBounds(const System::Types::TRect &R, int AOffset, int ASize, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	__property Vcl::Controls::TControl* Control = {read=FControl};
	__property System::Types::TRect SelectorBounds = {read=FSelectorBounds, write=SetSelectorBounds};
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRightToLeftLayoutConverter : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	static System::StaticArray<Cxgraphics::TcxArrowDirection, 4> ArrowDirectionMap;
	static System::StaticArray<Cxgeometry::TcxBorder, 4> BorderMap;
	static System::StaticArray<Dxcore::TdxCorner, 4> CornersMap;
	static System::StaticArray<Cxclasses::TcxDirection, 5> DirectionMap;
	static System::StaticArray<System::Classes::TLeftRight, 2> LeftRightMap;
	static System::StaticArray<TcxPopupAlignHorz, 3> PopupAlignHorzMap;
	static System::StaticArray<Vcl::Menus::TPopupAlignment, 3> PopupAlignmentMap;
	static System::StaticArray<Cxdrawtextutils::TcxTextAlignX, 5> TextAlignXMap;
	
public:
	__classmethod System::Classes::TLeftRight __fastcall ConvertAlignment(System::Classes::TLeftRight AAlignment);
	__classmethod System::Uitypes::TAnchors __fastcall ConvertAnchors(const System::Uitypes::TAnchors AAnchors);
	__classmethod Cxgraphics::TcxArrowDirection __fastcall ConvertArrowDirection(Cxgraphics::TcxArrowDirection ADirection);
	__classmethod Cxgeometry::TcxBorder __fastcall ConvertBorder(const Cxgeometry::TcxBorder ABorder);
	__classmethod Cxgeometry::TcxBorders __fastcall ConvertBorders(const Cxgeometry::TcxBorders ABorders);
	__classmethod Dxcore::TdxCorner __fastcall ConvertCorner(const Dxcore::TdxCorner ACorner);
	__classmethod int __fastcall ConvertcxDrawTextAlignment(int AAlignment);
	__classmethod Cxdrawtextutils::TcxTextAlignX __fastcall ConvertcxTextAlignX(Cxdrawtextutils::TcxTextAlignX AAlign);
	__classmethod Cxclasses::TcxDirection __fastcall ConvertDirection(Cxclasses::TcxDirection ADirection);
	__classmethod Cxlookandfeelpainters::TcxNeighbors __fastcall ConvertNeighbors(const Cxlookandfeelpainters::TcxNeighbors ANeighbors);
	__classmethod System::Types::TRect __fastcall ConvertOffsets(const System::Types::TRect &AOffsets);
	__classmethod Cxgeometry::TdxPointF __fastcall ConvertPoint(const Cxgeometry::TdxPointF &APoint, const System::Types::TRect &AParentRect)/* overload */;
	__classmethod System::Types::TPoint __fastcall ConvertPoint(const System::Types::TPoint &APoint, const System::Types::TRect &AParentRect)/* overload */;
	__classmethod TcxPopupAlignHorz __fastcall ConvertPopupAlignHorz(TcxPopupAlignHorz APopupAlignHorz);
	__classmethod Vcl::Menus::TPopupAlignment __fastcall ConvertPopupAlignment(Vcl::Menus::TPopupAlignment AAlignment);
	__classmethod System::Types::TRect __fastcall ConvertRect(const System::Types::TRect &ARect, const System::Types::TRect &AParentRect)/* overload */;
	__classmethod Cxgeometry::TdxRectF __fastcall ConvertRect(const Cxgeometry::TdxRectF &ARect, const Cxgeometry::TdxRectF &AParentRect)/* overload */;
	__classmethod System::Word __fastcall ConvertVirtualKeyCode(System::Word AKey);
	__classmethod int __fastcall ConvertXCoordinate(const int X, const System::Types::TRect &AParentRect)/* overload */;
	__classmethod float __fastcall ConvertXCoordinate(const float X, const System::Types::TRect &AParentRect)/* overload */;
public:
	/* TObject.Create */ inline __fastcall TdxRightToLeftLayoutConverter() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxRightToLeftLayoutConverter() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSemiTransparentDragHelper : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Byte FAlpha;
	Cxgraphics::TcxBitmap32* FBackgroundBitmap;
	TcxControl* FControl;
	System::Types::TPoint FPaintOffset;
	Cxgraphics::TcxBitmap32* FSelectionBitmap;
	System::Types::TRect FSelectionsBounds;
	bool FSpecialControlPainting;
	void __fastcall CreateBackgroundBitmap();
	void __fastcall CreateSelectionBitmap();
	void __fastcall SetSelectionsBounds(const System::Types::TRect &Value);
	
protected:
	virtual void __fastcall AfterSelectionPaint(Cxgraphics::TcxCanvas* ACanvas)/* overload */;
	virtual void __fastcall AfterSelectionPaint(Dxgdiplusclasses::TdxGPGraphics* AGraphics)/* overload */;
	Dxcoregraphics::TRGBColors __fastcall GetOpaqueBits(Cxgraphics::TcxBitmap32* ABitmap);
	Dxgdiplusclasses::TdxGPImage* __fastcall GetSelectionImage();
	virtual void __fastcall PaintSelection(Cxgraphics::TcxCanvas* ACanvas);
	virtual System::Types::TRect __fastcall GetSelectionBounds() = 0 ;
	virtual void __fastcall PaintControlSelection(Cxgraphics::TcxCanvas* ACanvas) = 0 ;
	__property System::Byte Alpha = {read=FAlpha, nodefault};
	__property TcxControl* Control = {read=FControl};
	__property System::Types::TRect SelectionsBounds = {read=FSelectionsBounds, write=SetSelectionsBounds};
	
public:
	__fastcall virtual TdxSemiTransparentDragHelper(TcxControl* AControl, System::Byte AAlpha);
	__fastcall virtual ~TdxSemiTransparentDragHelper();
	virtual void __fastcall BeginSpecialPaint();
	virtual void __fastcall EndSpecialPaint();
	void __fastcall Offset(int X, int Y);
	virtual void __fastcall PaintControl(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall Resize(const System::Types::TRect &ANewSelectionBounds)/* overload */;
	void __fastcall Resize()/* overload */;
	void __fastcall UpdateBackground();
	__property bool SpecialControlPainting = {read=FSpecialControlPainting, nodefault};
};

#pragma pack(pop)

enum class DECLSPEC_DENUM TdxScrollDirection : unsigned char { Left, Right, Up, Down };

typedef System::Set<TdxScrollDirection, _DELPHI_SET_ENUMERATOR(TdxScrollDirection::Left), _DELPHI_SET_ENUMERATOR(TdxScrollDirection::Down)> TdxScrollDirections;

enum class DECLSPEC_DENUM TdxScrollAxis : unsigned char { Horizontal, Vertical };

typedef System::Set<TdxScrollAxis, _DELPHI_SET_ENUMERATOR(TdxScrollAxis::Horizontal), _DELPHI_SET_ENUMERATOR(TdxScrollAxis::Vertical)> TdxScrollAxes;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAutoScrollHelper : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	#define TdxAutoScrollHelper_DefaultScrollAxes (System::Set<TdxScrollAxis, _DELPHI_SET_ENUMERATOR(TdxScrollAxis::Horizontal), _DELPHI_SET_ENUMERATOR(TdxScrollAxis::Vertical)>() << TdxScrollAxis::Horizontal << TdxScrollAxis::Vertical )
	
	
private:
	System::Types::TRect FBounds;
	TcxControl* FControl;
	TdxScrollDirections FCurrentDirections;
	int FInterval;
	bool FSingleDirection;
	Cxclasses::TcxTimer* FTimer;
	TdxScrollAxes FValidDirections;
	
protected:
	__fastcall TdxAutoScrollHelper(TcxControl* AControl, const System::Types::TRect &ABounds, TdxScrollAxes ADirections, int AInterval, bool ASingleDirection);
	virtual bool __fastcall CanProcess();
	virtual _di_IcxControlScrollBar __fastcall GetScrollBar(Vcl::Forms::TScrollBarKind AKind);
	virtual void __fastcall GetScrollBarParams(Vcl::Forms::TScrollBarKind AKind, int &AMin, int &AMax, int &APos);
	virtual void __fastcall GetScrollInfo(const System::Types::TPoint &APosition, /* out */ TdxScrollDirections &ADirections, /* out */ System::Types::TSize &ADeltas) = 0 ;
	virtual int __fastcall GetScrollStep(Vcl::Forms::TScrollBarKind AKind, int ADelta) = 0 ;
	void __fastcall Scroll(Vcl::Forms::TScrollBarKind AKind, int AStep);
	void __fastcall OnTimer(System::TObject* Sender);
	void __fastcall StartTimer(TdxScrollDirections ADirections);
	void __fastcall StopTimer();
	void __fastcall ValidateScrollDirections(TdxScrollDirections &ADirections);
	__property System::Types::TRect Bounds = {read=FBounds};
	__property TcxControl* Control = {read=FControl};
	__property TdxScrollDirections CurrentDirections = {read=FCurrentDirections, nodefault};
	__property bool SingleDirection = {read=FSingleDirection, nodefault};
	__property TdxScrollAxes ValidDirections = {read=FValidDirections, nodefault};
	
public:
	__classmethod TdxAutoScrollHelper* __fastcall CreateScroller(TcxControl* AControl, const System::Types::TRect &ABounds, int AScrollAreaSize, int AInterval, const System::Types::TSize &AStep, TdxScrollAxes ADirections = (TdxScrollAxes() << TdxScrollAxis::Horizontal << TdxScrollAxis::Vertical ), bool ASingleDirection = true)/* overload */;
	__classmethod TdxAutoScrollHelper* __fastcall CreateScroller(TcxControl* AControl, const System::Types::TRect &ABounds, int AInterval, System::DelphiInterface<System::Sysutils::TFunc__2<int,int> > AGetHScrollStep, System::DelphiInterface<System::Sysutils::TFunc__2<int,int> > AGetVScrollStep, TdxScrollAxes ADirections = (TdxScrollAxes() << TdxScrollAxis::Horizontal << TdxScrollAxis::Vertical ), bool ASingleDirection = true)/* overload */;
	__fastcall virtual ~TdxAutoScrollHelper();
	void __fastcall CheckMousePosition(const System::Types::TPoint &APosition);
};

#pragma pack(pop)

struct DECLSPEC_DRECORD TdxKeyPressWatcher
{
private:
	int FKeyCode;
	int FCount;
	
public:
	__fastcall TdxKeyPressWatcher(int AKeyCode);
	void __fastcall Start();
	void __fastcall Finish();
	bool __fastcall WasPressed();
	TdxKeyPressWatcher() {}
};


enum DECLSPEC_DENUM TdxSetOperation : unsigned char { soSet, soAdd, soSubtract };

enum DECLSPEC_DENUM TdxWindowStyleIndex : unsigned char { wsiStyle, wsiExStyle };

typedef Vcl::Forms::TCustomForm* __fastcall (*TcxGetParentFormForDockingFunc)(Vcl::Controls::TControl* AControl);

typedef HWND __fastcall (*TcxGetParentWndForDockingFunc)(HWND AWnd);

typedef bool __fastcall (*TcxContextPopupHookFunc)(System::TObject* ASender, System::Classes::TComponent* APopup, const System::Types::TPoint &P);

enum class DECLSPEC_DENUM TdxModifierKey : unsigned char { Shift, Alt, Ctrl };

typedef System::Set<TdxModifierKey, _DELPHI_SET_ENUMERATOR(TdxModifierKey::Shift), _DELPHI_SET_ENUMERATOR(TdxModifierKey::Ctrl)> TdxModifierKeys;

//-- var, const, procedure ---------------------------------------------------
static const System::Int8 cxDesignSelectorIndentFromBorder = System::Int8(0x8);
static const System::Int8 cxDesignSelectorSize = System::Int8(0xf);
static const System::Word cxInvisibleCoordinate = System::Word(0x7530);
extern DELPHI_PACKAGE TcxContextPopupHookFunc cxContextPopupHookFunc;
extern DELPHI_PACKAGE System::Byte cxDragAndDropWindowTransparency;
extern DELPHI_PACKAGE TcxGetParentWndForDockingFunc cxGetParentWndForDocking;
extern DELPHI_PACKAGE TdxApplicationActivateWindowHelper* dxApplicationActivateWindowHelper;
extern DELPHI_PACKAGE TcxControlPopupScrollBarClass dxTouchScrollBarClass;
extern DELPHI_PACKAGE bool __fastcall dxGetUpdateRgn(Vcl::Controls::TWinControl* AControl, HRGN ARegion);
extern DELPHI_PACKAGE bool __fastcall cxIsUpdateLayeredWindowAvailable(void);
extern DELPHI_PACKAGE void __fastcall cxSetLayeredWindowAttributes(HWND AHandle, int AAlphaBlendValue)/* overload */;
extern DELPHI_PACKAGE void __fastcall cxSetLayeredWindowAttributes(HWND AHandle, int AAlphaBlendValue, System::Uitypes::TColor ATransparentColorValue, unsigned AFlags)/* overload */;
extern DELPHI_PACKAGE void __fastcall cxUpdateLayeredWindow(HWND AHandle, Vcl::Graphics::TBitmap* ABitmap, int AAlpha = 0xff)/* overload */;
extern DELPHI_PACKAGE void __fastcall cxUpdateLayeredWindow(HWND AHandle, Vcl::Graphics::TBitmap* ABitmap, const System::Types::TSize &ASize, int AAlpha = 0xff)/* overload */;
extern DELPHI_PACKAGE TcxWindowProcController* __fastcall cxWindowProcController(void);
extern DELPHI_PACKAGE bool __fastcall dxIsCurrentProcessWindow(HWND AWnd);
extern DELPHI_PACKAGE bool __fastcall dxIsWindowStyleSet(NativeUInt AHandle, unsigned AStyle);
extern DELPHI_PACKAGE HWND __fastcall dxGetActualParentWindowForModalDialog(void);
extern DELPHI_PACKAGE void __fastcall dxRecalculateNonClientPart(NativeUInt AHandle, bool AUpdate = false);
extern DELPHI_PACKAGE void * __fastcall dxSetWindowProc(NativeUInt AHandle, void * ANewWindowProc);
extern DELPHI_PACKAGE NativeInt __fastcall dxSetWindowStyle(NativeUInt AHandle, NativeInt ANewStyle, TdxSetOperation AOperation = (TdxSetOperation)(0x0), TdxWindowStyleIndex AStyleIndex = (TdxWindowStyleIndex)(0x0));
extern DELPHI_PACKAGE TdxSystemInfo* __fastcall dxSystemInfo(void);
extern DELPHI_PACKAGE bool __fastcall dxWindowHasRightToLeftLayout(NativeUInt AHandle);
extern DELPHI_PACKAGE void __fastcall dxDrawTextOnGlass(Cxgraphics::TcxCanvas* ACanvas, const System::UnicodeString AText, const System::Types::TRect &ABounds, unsigned AFlags, bool ATransparent, Cxcustomcanvas::TcxRotationAngle AAngle = (Cxcustomcanvas::TcxRotationAngle)(0x0))/* overload */;
extern DELPHI_PACKAGE void __fastcall dxDrawTextOnGlass(HDC DC, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, const System::Types::TRect &ABounds, System::Uitypes::TColor AColor, unsigned AFlags, int AGlowingSize, bool ATransparent, Cxcustomcanvas::TcxRotationAngle AAngle = (Cxcustomcanvas::TcxRotationAngle)(0x0))/* overload */;
extern DELPHI_PACKAGE void __fastcall dxDrawWindowOnGlass(NativeUInt AWnd, NativeUInt ADC, const System::Types::TRect &ABounds, bool APaintBlackOpaque = false)/* overload */;
extern DELPHI_PACKAGE void __fastcall dxDrawWindowOnGlass(NativeUInt AWnd, bool APaintBlackOpaque = false)/* overload */;
extern DELPHI_PACKAGE void __fastcall dxPaintControlOnGlass(Vcl::Controls::TWinControl* AControl, bool APaintBlackOpaque = false);
extern DELPHI_PACKAGE void __fastcall dxPaintWindowOnGlass(NativeUInt AWnd, bool APaintBlackOpaque = false);
extern DELPHI_PACKAGE void __fastcall dxBufferedPaintControl(Vcl::Controls::TWinControl* AControl, bool AIgnorePaintRect = false);
extern DELPHI_PACKAGE bool __fastcall dxIsPaintOnGlass(Vcl::Controls::TWinControl* AControl);
extern DELPHI_PACKAGE bool __fastcall CanAllocateHandle(Vcl::Controls::TWinControl* AControl);
extern DELPHI_PACKAGE bool __fastcall cxIsDrawToMemory(const Winapi::Messages::TWMEraseBkgnd &AMessage);
extern DELPHI_PACKAGE void __fastcall dxRegisterCursor(int ACursorIndex, NativeUInt AResInstance, const System::WideChar * AResName);
extern DELPHI_PACKAGE void __fastcall dxUnregisterCursor(int ACursorIndex);
extern DELPHI_PACKAGE void __fastcall dxUnregisterCursors(int *ACursors, const int ACursors_High);
extern DELPHI_PACKAGE TcxMessageWindow* __fastcall cxMessageWindow(void);
extern DELPHI_PACKAGE TdxMessagesController* __fastcall dxMessagesController(void);
extern DELPHI_PACKAGE bool __fastcall cxIsVCLThemesAvailable(void);
extern DELPHI_PACKAGE bool __fastcall cxIsVCLThemesEnabled(void);
extern DELPHI_PACKAGE Vcl::Themes::TCustomStyleServices* __fastcall cxStyleServices(void);
extern DELPHI_PACKAGE void __fastcall dxDrawThemeEdge(HDC ADC, const Vcl::Themes::TThemedElementDetails &ADetails, const System::Types::TRect &R, unsigned AEdge, unsigned AFlags, System::Types::PRect AContentRect = (System::Types::PRect)(0x0));
extern DELPHI_PACKAGE TcxDragDetect __fastcall cxDragDetect(HWND Wnd, const System::Types::TPoint &AStartPoint);
extern DELPHI_PACKAGE System::WideChar __fastcall GetCharFromKeyCode(System::Word ACode);
extern DELPHI_PACKAGE NativeUInt __fastcall GetMouseKeys(void);
extern DELPHI_PACKAGE int __fastcall GetDblClickInterval(void);
extern DELPHI_PACKAGE System::Types::TRect __fastcall GetDesktopWorkArea(const System::Types::TPoint &P)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall GetDesktopWorkArea(const System::Types::TRect &R)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall GetMonitorWorkArea(const HMONITOR AMonitor);
extern DELPHI_PACKAGE System::Types::TPoint __fastcall GetMouseCursorPos(void);
extern DELPHI_PACKAGE Cxclasses::TcxPosition __fastcall GetPointPosition(const System::Types::TRect &ARect, const System::Types::TPoint &P, bool AHorzSeparation, bool AVertSeparation);
extern DELPHI_PACKAGE void __fastcall cxSetCapture(NativeUInt AHandle);
extern DELPHI_PACKAGE bool __fastcall cxShiftStateMoveOnly(const System::Classes::TShiftState AShift);
extern DELPHI_PACKAGE bool __fastcall cxShiftStateLeftOnly(System::Classes::TShiftState AShift, bool ACanIncludeDoubleClick = false);
extern DELPHI_PACKAGE bool __fastcall IsMouseDownMessage(unsigned AMsg);
extern DELPHI_PACKAGE bool __fastcall IsChildControl(Vcl::Controls::TWinControl* AParentControl, Vcl::Controls::TWinControl* AChildControl);
extern DELPHI_PACKAGE bool __fastcall IsChildClassWindow(HWND AWnd);
extern DELPHI_PACKAGE bool __fastcall IsChildEx(HWND AParentWnd, HWND AWnd);
extern DELPHI_PACKAGE bool __fastcall IsMDIChild(Vcl::Forms::TCustomForm* AForm);
extern DELPHI_PACKAGE bool __fastcall dxIsMDIChildWindow(HWND AWnd);
extern DELPHI_PACKAGE bool __fastcall IsMDIForm(Vcl::Forms::TCustomForm* AForm);
extern DELPHI_PACKAGE bool __fastcall IsCtrlPressed(void);
extern DELPHI_PACKAGE bool __fastcall IsControlChar(System::WideChar C);
extern DELPHI_PACKAGE bool __fastcall IsEditStartChar(System::WideChar C);
extern DELPHI_PACKAGE bool __fastcall IsIncSearchStartChar(System::WideChar C);
extern DELPHI_PACKAGE bool __fastcall IsOwner(HWND AOwnerWnd, HWND AWnd);
extern DELPHI_PACKAGE bool __fastcall IsOwnerEx(HWND AOwnerWnd, HWND AWnd);
extern DELPHI_PACKAGE bool __fastcall IsWindowEnabledEx(HWND AWindowHandle);
extern DELPHI_PACKAGE bool __fastcall IsControlVisible(Vcl::Controls::TWinControl* AControl);
extern DELPHI_PACKAGE bool __fastcall IsParent(Vcl::Controls::TControl* AParent, Vcl::Controls::TControl* AChild);
extern DELPHI_PACKAGE Vcl::Controls::TWinControl* __fastcall cxFindVCLControl(HWND AWnd);
extern DELPHI_PACKAGE System::Classes::TComponent* __fastcall cxFindComponent(System::Classes::TComponent* AParentComponent, System::TClass AClass);
extern DELPHI_PACKAGE System::Types::TPoint __fastcall cxClientToParent(Vcl::Controls::TControl* AControl, const System::Types::TPoint &P, Vcl::Controls::TWinControl* AParent);
extern DELPHI_PACKAGE System::Types::TPoint __fastcall cxParentToClient(Vcl::Controls::TControl* AControl, const System::Types::TPoint &P, Vcl::Controls::TWinControl* AParent);
extern DELPHI_PACKAGE bool __fastcall cxIsParentFocused(NativeUInt AParent);
extern DELPHI_PACKAGE Vcl::Controls::TWinControl* __fastcall dxFindParentControl(NativeUInt AHandle);
extern DELPHI_PACKAGE System::Classes::TComponentState __fastcall dxGetGlobalComponentState(System::Classes::TComponent* AComponent);
extern DELPHI_PACKAGE Vcl::Forms::TCustomForm* __fastcall dxGetParentForm(NativeUInt AHandle);
extern DELPHI_PACKAGE Vcl::Forms::TCustomForm* __fastcall dxGetParentFormForDocking(Vcl::Controls::TControl* AControl);
extern DELPHI_PACKAGE Vcl::Forms::TCustomForm* __fastcall dxGetScreenActiveForm(void);
extern DELPHI_PACKAGE void __fastcall dxPerformMessageByQueue(Vcl::Controls::TControl* AControl, unsigned AMessage);
extern DELPHI_PACKAGE bool __fastcall IsPointInDragDetectArea(const System::Types::TPoint &AMouseDownPos, int X, int Y);
extern DELPHI_PACKAGE bool __fastcall IsNumericChar(System::WideChar C, TcxNumberType AType);
extern DELPHI_PACKAGE bool __fastcall IsSysKey(System::Word AKey);
extern DELPHI_PACKAGE bool __fastcall IsTextChar(System::WideChar C);
extern DELPHI_PACKAGE void __fastcall MakeVisibleOnDesktop(System::Types::TRect &ABounds, const System::Types::TPoint &ADesktopPoint)/* overload */;
extern DELPHI_PACKAGE void __fastcall MakeVisibleOnDesktop(Vcl::Controls::TControl* AControl)/* overload */;
extern DELPHI_PACKAGE System::Types::TPoint __fastcall dxMapWindowPoint(HWND AHandleFrom, HWND AHandleTo, const System::Types::TPoint &P, bool AClient = true);
extern DELPHI_PACKAGE System::Types::TRect __fastcall dxMapWindowRect(HWND AHandleFrom, HWND AHandleTo, const System::Types::TRect &R, bool AClient = true);
extern DELPHI_PACKAGE void __fastcall cxRecreateControlWnd(Vcl::Controls::TWinControl* AControl, bool APostponed = false);
extern DELPHI_PACKAGE System::Types::TPoint __fastcall cxClientToScreen(NativeUInt AHandle, const System::Types::TPoint &APoint);
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxGetClientRect(NativeUInt AHandle)/* overload */;
extern DELPHI_PACKAGE System::Types::TPoint __fastcall cxGetClientOffset(NativeUInt AHandle);
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxGetClientRect(Vcl::Controls::TWinControl* AControl)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxGetWindowRect(NativeUInt AHandle)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall cxGetWindowText(NativeUInt AHandle);
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxGetWindowRect(Vcl::Controls::TWinControl* AControl)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxGetWindowBounds(Vcl::Controls::TWinControl* AControl)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxGetWindowBounds(NativeUInt AHandle)/* overload */;
extern DELPHI_PACKAGE HWND __fastcall cxWindowFromPoint(const System::Types::TPoint &P);
extern DELPHI_PACKAGE void __fastcall dxSetZOrder(NativeUInt AHandle, NativeUInt AWndAfter = (NativeUInt)(0xffffffff), bool AActivate = false, unsigned AFlags = (unsigned)(0x0));
extern DELPHI_PACKAGE void __fastcall cxInvalidateRect(NativeUInt AHandle, const System::Types::TRect &ARect, bool AEraseBackground = true)/* overload */;
extern DELPHI_PACKAGE void __fastcall cxInvalidateRect(NativeUInt AHandle, bool AEraseBackground = true)/* overload */;
extern DELPHI_PACKAGE void __fastcall cxInvalidateRect(Vcl::Controls::TWinControl* AControl, const System::Types::TRect &R, bool AEraseBackground = true)/* overload */;
extern DELPHI_PACKAGE void __fastcall cxInvalidateRect(Vcl::Controls::TWinControl* AControl, bool AEraseBackground = true)/* overload */;
extern DELPHI_PACKAGE void __fastcall cxRedrawWindow(NativeUInt AHandle, unsigned AFlags)/* overload */;
extern DELPHI_PACKAGE void __fastcall cxRedrawWindow(NativeUInt AHandle, const System::Types::TRect &ARect, unsigned AFlags)/* overload */;
extern DELPHI_PACKAGE void __fastcall cxRedrawWindow(NativeUInt AHandle, const System::Types::TRect &ARect, bool AEraseBackground = true, bool ARedrawNC = false)/* overload */;
extern DELPHI_PACKAGE void __fastcall cxRedrawNCRect(NativeUInt AHandle, const System::Types::TRect &ARect);
extern DELPHI_PACKAGE NativeUInt __fastcall cxLoadSysMenu(TcxSystemMenuType AMenuType);
extern DELPHI_PACKAGE void __fastcall cxModifySystemMenu(NativeUInt ASysMenu, NativeUInt AWindowHandle, bool AIsDialog, System::Uitypes::TBorderIcons ABorderIcons, System::Uitypes::TWindowState AWindowState, bool ALockRepaint = true);
extern DELPHI_PACKAGE void __fastcall cxMoveMenuItems(NativeUInt ASource, NativeUInt ADest);
extern DELPHI_PACKAGE void __fastcall SetDesignerModified(System::Classes::TComponent* AComponent);
extern DELPHI_PACKAGE System::UnicodeString __fastcall cxGetFullComponentName(System::Classes::TComponent* AComponent);
extern DELPHI_PACKAGE void __fastcall cxReleaseForm(void *AForm);
extern DELPHI_PACKAGE System::Word __fastcall ShiftStateToKeys(System::Classes::TShiftState AShift);
extern DELPHI_PACKAGE System::Word __fastcall TranslateKey(System::Word Key);
extern DELPHI_PACKAGE void __fastcall cxRecalculateAutoSize(Vcl::Controls::TControl* AControl);
extern DELPHI_PACKAGE void __fastcall cxProcessControlScrollingOnMiddleButton(Vcl::Controls::TWinControl* AControl, bool AllowHorScrolling, bool AllowVerScrolling, TcxScrollControlContent AScrollContentProc, bool &AScrollContentFlag);
extern DELPHI_PACKAGE void __fastcall BeginMouseTracking(Vcl::Controls::TWinControl* AControl, const System::Types::TRect &ABounds, Dxcoreclasses::_di_IcxMouseTrackingCaller ACaller);
extern DELPHI_PACKAGE void __fastcall EndMouseTracking(Dxcoreclasses::_di_IcxMouseTrackingCaller ACaller);
extern DELPHI_PACKAGE bool __fastcall IsMouseTracking(Dxcoreclasses::_di_IcxMouseTrackingCaller ACaller);
extern DELPHI_PACKAGE void __fastcall dxHideCursor(System::Uitypes::TCursor ACursor);
extern DELPHI_PACKAGE void __fastcall dxShowCursor(System::Uitypes::TCursor ACursor);
extern DELPHI_PACKAGE void __fastcall HideHourglassCursor(void);
extern DELPHI_PACKAGE void __fastcall ShowHourglassCursor(void);
extern DELPHI_PACKAGE int __fastcall GetPopupMenuHeight(Vcl::Menus::TPopupMenu* APopupMenu, Cxgeometry::TdxScaleFactor* AScaleFactor = (Cxgeometry::TdxScaleFactor*)(0x0));
extern DELPHI_PACKAGE bool __fastcall IsPopupMenu(System::Classes::TComponent* APopupMenu);
extern DELPHI_PACKAGE bool __fastcall IsPopupMenuShortCut(System::Classes::TComponent* APopupMenu, Winapi::Messages::TWMKey &Message);
extern DELPHI_PACKAGE bool __fastcall ShowPopupMenu(System::Classes::TComponent* ACaller, System::Classes::TComponent* APopupMenu, const System::Types::TPoint &P)/* overload */;
extern DELPHI_PACKAGE bool __fastcall ShowPopupMenu(System::Classes::TComponent* ACaller, System::Classes::TComponent* APopupMenu, int X, int Y)/* overload */;
extern DELPHI_PACKAGE bool __fastcall ShowPopupMenu(System::Classes::TComponent* ACaller, System::Classes::TComponent* APopupMenu, const System::Types::TRect &AOwnerBounds, Vcl::Menus::TPopupAlignment APopupAlignment)/* overload */;
extern DELPHI_PACKAGE bool __fastcall ShowPopupMenuFromCursorPos(System::Classes::TComponent* ACaller, System::Classes::TComponent* AComponent);
extern DELPHI_PACKAGE System::TObject* __fastcall cxExtractDragObjectSource(System::TObject* ADragObject);
extern DELPHI_PACKAGE Vcl::Controls::TDragObject* __fastcall GetDragObject(void);
extern DELPHI_PACKAGE void __fastcall DialogApplyFont(Vcl::Forms::TCustomForm* ADialog, Vcl::Graphics::TFont* AFont, System::TObject* AFontOwner);
extern DELPHI_PACKAGE TcxDesignController* __fastcall DesignController(void);
}	/* namespace Cxcontrols */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXCONTROLS)
using namespace Cxcontrols;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxcontrolsHPP
