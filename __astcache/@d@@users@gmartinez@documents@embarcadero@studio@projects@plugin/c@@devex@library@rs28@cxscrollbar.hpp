// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxScrollBar.pas' rev: 35.00 (Windows)

#ifndef CxscrollbarHPP
#define CxscrollbarHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.UITypes.hpp>
#include <Winapi.Windows.hpp>
#include <Vcl.Forms.hpp>
#include <Winapi.Messages.hpp>
#include <System.Types.hpp>
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Graphics.hpp>
#include <dxTouch.hpp>
#include <dxThemeManager.hpp>
#include <cxGraphics.hpp>
#include <cxClasses.hpp>
#include <cxLookAndFeels.hpp>
#include <cxLookAndFeelPainters.hpp>
#include <dxFading.hpp>
#include <dxCoreClasses.hpp>
#include <cxGeometry.hpp>
#include <dxCoreGraphics.hpp>
#include <dxScrollbarAnnotations.hpp>
#include <System.Generics.Defaults.hpp>
#include <System.Generics.Collections.hpp>
#include <dxTypeHelpers.hpp>
#include <dxGDIPlusClasses.hpp>
#include <dxCustomHint.hpp>
#include <cxCustomCanvas.hpp>
#include <Vcl.Menus.hpp>

//-- user supplied -----------------------------------------------------------

namespace Cxscrollbar
{
//-- forward type declarations -----------------------------------------------
__interface DELPHIINTERFACE IcxScrollBarOwner;
typedef System::DelphiInterface<IcxScrollBarOwner> _di_IcxScrollBarOwner;
__interface DELPHIINTERFACE IcxScrollBarOwner2;
typedef System::DelphiInterface<IcxScrollBarOwner2> _di_IcxScrollBarOwner2;
__interface DELPHIINTERFACE IcxScrollBarOwner2Provider;
typedef System::DelphiInterface<IcxScrollBarOwner2Provider> _di_IcxScrollBarOwner2Provider;
class DELPHICLASS TcxScrollBarPartFadingHelper;
class DELPHICLASS TcxScrollBarPartViewInfo;
class DELPHICLASS TcxScrollbarAnnotationInfo;
class DELPHICLASS TcxScrollBarAnnotationHintableObject;
class DELPHICLASS TcxScrollbarAnnotationInfos;
class DELPHICLASS TcxScrollBarViewInfo;
class DELPHICLASS TcxScrollBarHintHelper;
class DELPHICLASS TcxScrollBarController;
class DELPHICLASS TcxScrollBarPainter;
class DELPHICLASS TcxScrollBarHelper;
class DELPHICLASS TcxScrollBar;
//-- type declarations -------------------------------------------------------
__interface  INTERFACE_UUID("{56771164-C253-40FF-B6D4-2A29D0C90236}") IcxScrollBarOwner  : public System::IInterface 
{
	virtual Vcl::Controls::TWinControl* __fastcall GetControl() = 0 ;
	virtual Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeel() = 0 ;
	virtual Cxgeometry::TdxScaleFactor* __fastcall GetScaleFactor() = 0 ;
};

__interface  INTERFACE_UUID("{39D5E864-7166-4168-A6C8-AC85303CF088}") IcxScrollBarOwner2  : public System::IInterface 
{
	virtual System::Types::TPoint __fastcall GetOrigin() = 0 ;
	virtual bool __fastcall GetVisible() = 0 ;
	virtual System::Types::TRect __fastcall GetVisibleRect() = 0 ;
	virtual void __fastcall SetFocusByMouse() = 0 ;
};

__interface  INTERFACE_UUID("{5CAEC427-0B33-41D2-8839-5BE9E0920BD4}") IcxScrollBarOwner2Provider  : public System::IInterface 
{
	virtual _di_IcxScrollBarOwner2 __fastcall GetOwner2() = 0 ;
};

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxScrollBarPartFadingHelper : public Dxfading::TdxFadingObjectHelper
{
	typedef Dxfading::TdxFadingObjectHelper inherited;
	
private:
	TcxScrollBarPartViewInfo* FOwner;
	Cxlookandfeelpainters::TcxButtonState FState;
	
protected:
	virtual bool __fastcall CanFade();
	virtual void __fastcall DrawFadeImage();
	virtual void __fastcall GetFadingImages(/* out */ Cxgraphics::TcxBitmap* &AFadeOutImage, /* out */ Cxgraphics::TcxBitmap* &AFadeInImage);
	
public:
	__fastcall TcxScrollBarPartFadingHelper(TcxScrollBarPartViewInfo* AOwner);
	void __fastcall UpdateState();
	__property TcxScrollBarPartViewInfo* Owner = {read=FOwner};
public:
	/* TdxFadingObjectHelper.Destroy */ inline __fastcall virtual ~TcxScrollBarPartFadingHelper() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxScrollBarPartViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxScrollBarViewInfo* FOwner;
	System::Types::TRect FBounds;
	TcxScrollBarPartFadingHelper* FFadingHelper;
	Cxlookandfeelpainters::TcxScrollBarPart FPart;
	Cxlookandfeelpainters::TcxButtonState FState;
	TcxScrollBarPainter* __fastcall GetPainter();
	Cxlookandfeelpainters::TcxButtonState __fastcall GetState();
	void __fastcall SetState(Cxlookandfeelpainters::TcxButtonState AValue);
	
protected:
	bool __fastcall CanFade();
	void __fastcall Invalidate();
	void __fastcall UpdateFadingHelperState();
	__property TcxScrollBarPartFadingHelper* FadingHelper = {read=FFadingHelper};
	__property TcxScrollBarViewInfo* Owner = {read=FOwner};
	__property TcxScrollBarPainter* Painter = {read=GetPainter};
	
public:
	__fastcall TcxScrollBarPartViewInfo(TcxScrollBarViewInfo* AOwner, Cxlookandfeelpainters::TcxScrollBarPart APart);
	__fastcall virtual ~TcxScrollBarPartViewInfo();
	__property System::Types::TRect Bounds = {read=FBounds, write=FBounds};
	__property Cxlookandfeelpainters::TcxScrollBarPart Part = {read=FPart, nodefault};
	__property Cxlookandfeelpainters::TcxButtonState State = {read=GetState, write=SetState, nodefault};
};

#pragma pack(pop)

enum DECLSPEC_DENUM TcxHorizontalScrollBarPart : unsigned char { spbmLineLeft, spbmLineRight, spbmPageLeft, spbmPageRight };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxScrollbarAnnotationInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Types::TRect FBounds;
	Dxcoregraphics::TdxAlphaColor FColor;
	Dxscrollbarannotations::TdxScrollbarAnnotationRowIndexList* FRecordIndexes;
	
public:
	__fastcall virtual TcxScrollbarAnnotationInfo();
	__fastcall virtual ~TcxScrollbarAnnotationInfo();
	__property System::Types::TRect Bounds = {read=FBounds, write=FBounds};
	__property Dxcoregraphics::TdxAlphaColor Color = {read=FColor, write=FColor, nodefault};
	__property Dxscrollbarannotations::TdxScrollbarAnnotationRowIndexList* RecordIndexes = {read=FRecordIndexes};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxScrollBarAnnotationHintableObject : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	System::Types::TRect FBounds;
	
public:
	bool __fastcall HasHintPoint(const System::Types::TPoint &P);
	bool __fastcall IsHintAtMousePos();
	bool __fastcall UseHintHidePause();
	__property System::Types::TRect Bounds = {read=FBounds, write=FBounds};
public:
	/* TObject.Create */ inline __fastcall TcxScrollBarAnnotationHintableObject() : Dxcoreclasses::TcxIUnknownObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxScrollBarAnnotationHintableObject() { }
	
private:
	void *__IcxHintableObject;	// Dxcustomhint::IcxHintableObject 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {228FF1F5-6D0C-40F0-9F7B-8C71CE12CEC8}
	operator Dxcustomhint::_di_IcxHintableObject()
	{
		Dxcustomhint::_di_IcxHintableObject intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Dxcustomhint::IcxHintableObject*(void) { return (Dxcustomhint::IcxHintableObject*)&__IcxHintableObject; }
	#endif
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxScrollbarAnnotationInfos : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Types::TRect FBounds;
	Dxscrollbarannotations::TdxScrollbarAnnotationKinds FChangedAnnotationKinds;
	System::Generics::Collections::TObjectDictionary__2<Dxscrollbarannotations::TdxScrollbarAnnotationKind,System::Generics::Collections::TObjectList__1<TcxScrollbarAnnotationInfo*>*>* FInfos;
	TcxScrollBarHelper* FScrollbar;
	System::Generics::Collections::TObjectList__1<TcxScrollbarAnnotationInfo*>* __fastcall GetAnnotationList(Dxscrollbarannotations::TdxScrollbarAnnotationKind AKind);
	
protected:
	void __fastcall CreateItems(Dxscrollbarannotations::TdxScrollbarAnnotationKind AKind);
	__property Dxscrollbarannotations::TdxScrollbarAnnotationKinds ChangedAnnotationKinds = {read=FChangedAnnotationKinds, write=FChangedAnnotationKinds};
	
public:
	__fastcall TcxScrollbarAnnotationInfos(TcxScrollBarHelper* AOwner);
	__fastcall virtual ~TcxScrollbarAnnotationInfos();
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds);
	void __fastcall Invalidate();
	__property System::Generics::Collections::TObjectDictionary__2<Dxscrollbarannotations::TdxScrollbarAnnotationKind,System::Generics::Collections::TObjectList__1<TcxScrollbarAnnotationInfo*>*>* Infos = {read=FInfos};
	__property System::Types::TRect Bounds = {read=FBounds};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxScrollBarViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxScrollbarAnnotationInfos* FAnnotationInfos;
	System::Types::TRect FAnnotationInfosBounds;
	int FArrowButtonLength;
	int FDragThumbnailPosX;
	int FDragThumbnailPosY;
	Vcl::Forms::TScrollBarKind FKind;
	int FLength;
	Cxlookandfeelpainters::TcxScrollBarPart FHotPart;
	int FMinThumbnailSize;
	System::StaticArray<TcxScrollBarPartViewInfo*, 5> FPartInfos;
	Cxlookandfeelpainters::TcxScrollBarPart FPressedPart;
	TcxScrollBarHelper* FScrollBar;
	void __fastcall CheckKind();
	int __fastcall GetLength();
	int __fastcall GetHeight();
	TcxScrollBarPartViewInfo* __fastcall GetPartInfo(Cxlookandfeelpainters::TcxScrollBarPart APartType);
	void __fastcall SetHotPart(Cxlookandfeelpainters::TcxScrollBarPart AValue);
	void __fastcall SetPressedPart(Cxlookandfeelpainters::TcxScrollBarPart AValue);
	Vcl::Forms::TScrollBarKind __fastcall GetKind();
	int __fastcall GetMax();
	int __fastcall GetMin();
	int __fastcall GetMinThumbnailSize();
	int __fastcall GetPageSize();
	int __fastcall GetPosition();
	Cxgeometry::TdxScaleFactor* __fastcall GetScaleFactor();
	bool __fastcall IsEnabled();
	
protected:
	void __fastcall CalculateAnnotationInfos();
	virtual TcxScrollbarAnnotationInfos* __fastcall CreateAnnotationInfos();
	void __fastcall CreatePartInfos();
	void __fastcall DestroyPartInfos();
	virtual int __fastcall GetArrowButtonLength();
	virtual System::Types::TRect __fastcall GetBounds();
	TcxScrollBarPartViewInfo* __fastcall GetHorizontalScrollbarPart(TcxHorizontalScrollBarPart APartType);
	Cxlookandfeelpainters::TcxScrollBarPart __fastcall GetPart(const System::Types::TPoint &P);
	void __fastcall UpdateAnnotationInfos();
	void __fastcall UpdateFadingHelperStates();
	__property TcxScrollBarHelper* ScrollBar = {read=FScrollBar};
	__property Cxgeometry::TdxScaleFactor* ScaleFactor = {read=GetScaleFactor};
	
public:
	__fastcall virtual TcxScrollBarViewInfo(TcxScrollBarHelper* AScrollBar);
	__fastcall virtual ~TcxScrollBarViewInfo();
	void __fastcall AdjustPageRects();
	virtual void __fastcall Calculate();
	void __fastcall CalculateThumbnailRect();
	void __fastcall SetThumbnailPos(int APos);
	__property TcxScrollbarAnnotationInfos* AnnotationsInfo = {read=FAnnotationInfos};
	__property System::Types::TRect Bounds = {read=GetBounds};
	__property Cxlookandfeelpainters::TcxScrollBarPart HotPart = {read=FHotPart, write=SetHotPart, nodefault};
	__property TcxScrollBarPartViewInfo* PartInfo[Cxlookandfeelpainters::TcxScrollBarPart APartType] = {read=GetPartInfo};
	__property Cxlookandfeelpainters::TcxScrollBarPart PressedPart = {read=FPressedPart, write=SetPressedPart, nodefault};
};

#pragma pack(pop)

typedef System::TMetaClass* TcxScrollBarViewInfoClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxScrollBarHintHelper : public Dxcustomhint::TcxCustomHintHelper
{
	typedef Dxcustomhint::TcxCustomHintHelper inherited;
	
private:
	TcxScrollBarController* FController;
	
protected:
	virtual void __fastcall CorrectHintWindowRect(System::Types::TRect &ARect);
	virtual Vcl::Controls::TWinControl* __fastcall GetOwnerWinControl();
	__property TcxScrollBarController* Controller = {read=FController};
	
public:
	__fastcall TcxScrollBarHintHelper(TcxScrollBarController* AController);
public:
	/* TcxCustomHintHelper.Destroy */ inline __fastcall virtual ~TcxScrollBarHintHelper() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxScrollBarController : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxScrollBarAnnotationHintableObject* FAnnotationsHintableObject;
	System::Types::TPoint FDownMousePos;
	TcxScrollBarHintHelper* FHintHelper;
	int FHotAnnotationRowIndex;
	Dxscrollbarannotations::TdxScrollbarAnnotationRowIndexLists* FHotAnnotationRowIndexLists;
	System::Types::TPoint FLastMousePos;
	int FSavePosition;
	System::Types::TPoint FSaveThumbnailPos;
	TcxScrollBarHelper* FScrollBar;
	Cxclasses::TcxTimer* FTimer;
	void __fastcall CheckHint();
	void __fastcall CheckHotAnnotations(const System::Types::TPoint &APos);
	void __fastcall FinishScrolling(Cxlookandfeelpainters::TcxScrollBarPart AHotPart = (Cxlookandfeelpainters::TcxScrollBarPart)(0x0));
	int __fastcall GetPositionFromThumbnail();
	TcxScrollBarViewInfo* __fastcall GetViewInfo();
	void __fastcall InternalScroll(System::Uitypes::TScrollCode AScrollCode);
	bool __fastcall IsButtonHotTrack();
	void __fastcall OnTimer(System::TObject* Sender);
	
protected:
	virtual TcxScrollBarHintHelper* __fastcall CreateHintHelper();
	virtual void __fastcall DoMouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall DoMouseEnter(Vcl::Controls::TControl* AControl);
	virtual void __fastcall DoMouseLeave(Vcl::Controls::TControl* AControl);
	virtual void __fastcall DoMouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall DoMouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall DoScroll(Cxlookandfeelpainters::TcxScrollBarPart APart);
	void __fastcall SetPositionValue(System::Uitypes::TScrollCode AScrollCode, int AValue);
	virtual void __fastcall SetThumbnailValue(int AValue, bool AUseSetter);
	__property int HotAnnotationRowIndex = {read=FHotAnnotationRowIndex, nodefault};
	__property TcxScrollBarHelper* ScrollBar = {read=FScrollBar};
	__property TcxScrollBarViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual TcxScrollBarController(TcxScrollBarHelper* AScrollBar);
	__fastcall virtual ~TcxScrollBarController();
	void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall MouseEnter(Vcl::Controls::TControl* AControl);
	void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
};

#pragma pack(pop)

typedef System::TMetaClass* TcxScrollBarControllerClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxScrollBarPainter : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxScrollBarHelper* FScrollBar;
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter();
	Cxgeometry::TdxScaleFactor* __fastcall GetScaleFactor();
	TcxScrollBarViewInfo* __fastcall GetViewInfo();
	
protected:
	virtual void __fastcall DoDrawScrollBarPart(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxScrollBarPart APart, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawScrollbarAnnotation(Cxcustomcanvas::TcxCustomCanvas* ACanvas, TcxScrollbarAnnotationInfo* AInfo);
	virtual void __fastcall DoDrawScrollbarAnnotations(Cxcustomcanvas::TcxCustomCanvas* ACanvas);
	virtual void __fastcall DrawScrollbarAnnotations(Cxcustomcanvas::TcxCustomCanvas* ACanvas);
	virtual void __fastcall DrawScrollBarBackground(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DrawScrollBarPart(Cxcustomcanvas::TcxCustomCanvas* ACanvas, Cxlookandfeelpainters::TcxScrollBarPart APart);
	virtual bool __fastcall FadingAvailable();
	virtual int __fastcall GetMinThumbnailSize();
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* LookAndFeelPainter = {read=GetLookAndFeelPainter};
	__property TcxScrollBarHelper* ScrollBar = {read=FScrollBar};
	__property Cxgeometry::TdxScaleFactor* ScaleFactor = {read=GetScaleFactor};
	__property TcxScrollBarViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual TcxScrollBarPainter(TcxScrollBarHelper* AScrollBar);
	__fastcall virtual ~TcxScrollBarPainter();
	virtual bool __fastcall IsButtonHotTrack();
	virtual void __fastcall Paint(Cxcustomcanvas::TcxCustomCanvas* ACanvas);
};

#pragma pack(pop)

typedef System::TMetaClass* TcxScrollBarPainterClass;

class PASCALIMPLEMENTATION TcxScrollBarHelper : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	Dxscrollbarannotations::TdxScrollbarAnnotations* FAnnotations;
	System::Types::TRect FBoundsRect;
	TcxScrollBarController* FController;
	bool FEnabled;
	bool FIsNonClient;
	Vcl::Forms::TScrollBarKind FKind;
	Vcl::Forms::TScrollBarInc FLargeChange;
	int FMax;
	int FMin;
	_di_IcxScrollBarOwner FOwner;
	_di_IcxScrollBarOwner2 FOwner2;
	int FPageSize;
	TcxScrollBarPainter* FPainter;
	int FPosition;
	bool FReverseDirection;
	Vcl::Forms::TScrollBarInc FSmallChange;
	bool FUnlimitedTracking;
	TcxScrollBarViewInfo* FViewInfo;
	bool FVisible;
	HRGN FVisibleRgn;
	System::Classes::TNotifyEvent FOnChange;
	Vcl::Stdctrls::TScrollEvent FOnScroll;
	void __fastcall ClearRegion();
	void __fastcall InvalidateOwnerControlCanvasBuffer();
	bool __fastcall GetAllowOwnerScrollOnDrag();
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter();
	Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeel();
	Cxgraphics::TcxRegion* __fastcall GetTempVisibleRegion();
	void __fastcall RefreshNCPart(const System::Types::TRect &ARect);
	void __fastcall SetVisibleRgn(const HRGN Value);
	
protected:
	System::Types::TRect __fastcall GetBoundsRect();
	bool __fastcall GetEnabled();
	Vcl::Forms::TScrollBarKind __fastcall GetKind();
	Vcl::Forms::TScrollBarInc __fastcall GetLargeChange();
	int __fastcall GetMax();
	int __fastcall GetMin();
	int __fastcall GetPageSize();
	int __fastcall GetPosition();
	Vcl::Forms::TScrollBarInc __fastcall GetSmallChange();
	bool __fastcall GetUnlimitedTracking();
	bool __fastcall GetVisible();
	void __fastcall SetBoundsRect(const System::Types::TRect &AValue);
	void __fastcall SetEnabled(bool AValue);
	void __fastcall SetKind(Vcl::Forms::TScrollBarKind Value);
	void __fastcall SetLargeChange(Vcl::Forms::TScrollBarInc Value);
	void __fastcall SetMax(int Value);
	void __fastcall SetMin(int Value);
	void __fastcall SetPageSize(int Value);
	void __fastcall SetPosition(int Value);
	void __fastcall SetVisible(bool AValue);
	void __fastcall SetSmallChange(Vcl::Forms::TScrollBarInc Value);
	void __fastcall SetUnlimitedTracking(bool Value);
	virtual void __fastcall Change();
	void __fastcall DoBufferedPaint(HDC ADC);
	virtual void __fastcall DoPaint(Cxgraphics::TcxCanvas* ACanvas);
	virtual TcxScrollBarControllerClass __fastcall GetControllerClass();
	virtual Dxcoregraphics::TdxAlphaColor __fastcall GetDefaultScrollbarAnnotationColor(Dxscrollbarannotations::TdxScrollbarAnnotationKind AAnnotationKind);
	virtual TcxScrollBarPainterClass __fastcall GetPainterClass();
	Cxgeometry::TdxScaleFactor* __fastcall GetScaleFactor();
	virtual System::Types::TSize __fastcall GetScrollBarSize();
	virtual TcxScrollBarViewInfoClass __fastcall GetViewInfoClass();
	NativeUInt __fastcall Handle();
	bool __fastcall HandleAllocated();
	virtual void __fastcall Invalidate();
	virtual void __fastcall InvalidateRect(const System::Types::TRect &ARect, bool AEraseBackground = false);
	virtual bool __fastcall IsOwnerControlCapture();
	virtual bool __fastcall IsRightToLeft();
	void __fastcall MoveToCurrentAnnotation();
	virtual bool __fastcall NeedBuffering();
	bool __fastcall PtInVisibleRgn(const System::Types::TPoint &APoint);
	virtual System::Types::TPoint __fastcall ScreenToClient(const System::Types::TPoint &APoint);
	virtual void __fastcall Scroll(System::Uitypes::TScrollCode ScrollCode, int &ScrollPos);
	void __fastcall TranslateCoords(int &X, int &Y);
	__property bool AllowOwnerScrollOnDrag = {read=GetAllowOwnerScrollOnDrag, nodefault};
	__property Dxscrollbarannotations::TdxScrollbarAnnotations* Annotations = {read=FAnnotations};
	__property TcxScrollBarController* Controller = {read=FController};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* LookAndFeelPainter = {read=GetLookAndFeelPainter};
	__property _di_IcxScrollBarOwner Owner = {read=FOwner};
	__property _di_IcxScrollBarOwner2 Owner2 = {read=FOwner2};
	__property TcxScrollBarPainter* Painter = {read=FPainter};
	__property Cxgeometry::TdxScaleFactor* ScaleFactor = {read=GetScaleFactor};
	__property TcxScrollBarViewInfo* ViewInfo = {read=FViewInfo};
	__property HRGN VisibleRgn = {read=FVisibleRgn, write=SetVisibleRgn, nodefault};
	
public:
	__fastcall virtual TcxScrollBarHelper(_di_IcxScrollBarOwner AOwner);
	__fastcall virtual ~TcxScrollBarHelper();
	virtual void __fastcall Calculate();
	virtual void __fastcall CancelMode();
	virtual System::Types::TPoint __fastcall GetOwnerOrigin();
	virtual bool __fastcall GetOwnerVisible();
	virtual void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseEnter(Vcl::Controls::TControl* AControl);
	virtual void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	virtual void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall Paint(Cxcustomcanvas::TcxCustomCanvas* ACanvas)/* overload */;
	virtual void __fastcall Paint(HDC ADC)/* overload */;
	virtual void __fastcall Repaint();
	void __fastcall SetScrollParams(int AMin, int AMax, int APosition, int APageSize, bool ARedraw = true);
	void __fastcall ScrollbarAnnotationsInvalidate(const Dxscrollbarannotations::TdxScrollbarAnnotationKinds &AAnnotationKinds = (Dxscrollbarannotations::TdxScrollbarAnnotationKinds() << 0x0 << 0x1 << 0x2 << 0x3 << 0x4 << 0x5 << 0x6 << 0x7 << 0x8 << 0x9 << 0xa << 0xb << 0xc << 0xd << 0xe << 0xf << 0x10 << 0x11 << 0x12 << 0x13 << 0x14 << 0x15 << 0x16 << 0x17 << 0x18 << 0x19 << 0x1a << 0x1b << 0x1c << 0x1d << 0x1e << 0x1f << 0x20 << 0x21 << 0x22 << 0x23 << 0x24 << 0x25 << 0x26 << 0x27 << 0x28 << 0x29 << 0x2a << 0x2b << 0x2c << 0x2d << 0x2e << 0x2f << 0x30 << 0x31 << 0x32 << 0x33 << 0x34 << 0x35 << 0x36 << 0x37 << 0x38 << 0x39 << 0x3a << 0x3b << 0x3c << 0x3d << 0x3e << 0x3f << 0x40 << 0x41 << 0x42 << 0x43 << 0x44 << 0x45 << 0x46 << 0x47 << 0x48 << 0x49 << 0x4a << 0x4b << 0x4c << 0x4d << 0x4e << 0x4f << 0x50 << 0x51 << 0x52 << 0x53 << 0x54 << 0x55 << 0x56 << 0x57 << 0x58 << 0x59 << 0x5a << 0x5b << 0x5c << 0x5d << 0x5e << 0x5f << 0x60 << 0x61 << 0x62 << 0x63 << 0x64 << 0x65 << 0x66 << 0x67 << 0x68 << 0x69 << 0x6a << 0x6b << 0x6c << 0x6d << 0x6e << 0x6f << 0x70 << 0x71 << 0x72 << 0x73 << 0x74 << 0x75 << 0x76 << 0x77 << 0x78 << 0x79 << 0x7a << 0x7b << 0x7c << 0x7d << 0x7e << 0x7f << 0x80 << 0x81 << 0x82 << 0x83 << 0x84 << 0x85 << 0x86 << 0x87 << 0x88 << 0x89 << 0x8a << 0x8b << 0x8c << 0x8d << 0x8e << 0x8f << 0x90 << 0x91 << 0x92 << 0x93 << 0x94 << 0x95 << 0x96 << 0x97 << 0x98 << 0x99 << 0x9a << 0x9b << 0x9c << 0x9d << 0x9e << 0x9f << 0xa0 << 0xa1 << 0xa2 << 0xa3 << 0xa4 << 0xa5 << 0xa6 << 0xa7 << 0xa8 << 0xa9 << 0xaa << 0xab << 0xac << 0xad << 0xae << 0xaf << 0xb0 << 0xb1 << 0xb2 << 0xb3 << 0xb4 << 0xb5 << 0xb6 << 0xb7 << 0xb8 << 0xb9 << 0xba << 0xbb << 0xbc << 0xbd << 0xbe << 0xbf << 0xc0 << 0xc1 << 0xc2 << 0xc3 << 0xc4 << 0xc5 << 0xc6 << 0xc7 << 0xc8 << 0xc9 << 0xca << 0xcb << 0xcc << 0xcd << 0xce << 0xcf << 0xd0 << 0xd1 << 0xd2 << 0xd3 << 0xd4 << 0xd5 << 0xd6 << 0xd7 << 0xd8 << 0xd9 << 0xda << 0xdb << 0xdc << 0xdd << 0xde << 0xdf << 0xe0 << 0xe1 << 0xe2 << 0xe3 << 0xe4 << 0xe5 << 0xe6 << 0xe7 << 0xe8 << 0xe9 << 0xea << 0xeb << 0xec << 0xed << 0xee << 0xef << 0xf0 << 0xf1 << 0xf2 << 0xf3 << 0xf4 << 0xf5 << 0xf6 << 0xf7 << 0xf8 << 0xf9 << 0xfa << 0xfb << 0xfc << 0xfd << 0xfe << 0xff ));
	void __fastcall ScrollbarAnnotationsUpdate();
	void __fastcall SetAnnotations(Dxscrollbarannotations::TdxScrollbarAnnotations* AAnnotations);
	__property System::Types::TRect BoundsRect = {read=GetBoundsRect, write=SetBoundsRect};
	__property bool Enabled = {read=GetEnabled, write=SetEnabled, nodefault};
	__property bool IsNonClient = {read=FIsNonClient, write=FIsNonClient, nodefault};
	__property Vcl::Forms::TScrollBarKind Kind = {read=GetKind, write=SetKind, nodefault};
	__property Vcl::Forms::TScrollBarInc LargeChange = {read=GetLargeChange, write=SetLargeChange, nodefault};
	__property Cxlookandfeels::TcxLookAndFeel* LookAndFeel = {read=GetLookAndFeel};
	__property int Max = {read=GetMax, write=SetMax, nodefault};
	__property int Min = {read=GetMin, write=SetMin, nodefault};
	__property int PageSize = {read=GetPageSize, write=SetPageSize, nodefault};
	__property int Position = {read=GetPosition, write=SetPosition, nodefault};
	__property bool ReverseDirection = {read=FReverseDirection, write=FReverseDirection, nodefault};
	__property Vcl::Forms::TScrollBarInc SmallChange = {read=GetSmallChange, write=SetSmallChange, nodefault};
	__property bool UnlimitedTracking = {read=GetUnlimitedTracking, write=SetUnlimitedTracking, nodefault};
	__property bool Visible = {read=GetVisible, write=SetVisible, nodefault};
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property Vcl::Stdctrls::TScrollEvent OnScroll = {read=FOnScroll, write=FOnScroll};
private:
	void *__IdxScrollbarAnnotationRenderer;	// Dxscrollbarannotations::IdxScrollbarAnnotationRenderer 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {0C20A750-FAFE-4A96-A0FB-DE73BCF98CF9}
	operator Dxscrollbarannotations::_di_IdxScrollbarAnnotationRenderer()
	{
		Dxscrollbarannotations::_di_IdxScrollbarAnnotationRenderer intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Dxscrollbarannotations::IdxScrollbarAnnotationRenderer*(void) { return (Dxscrollbarannotations::IdxScrollbarAnnotationRenderer*)&__IdxScrollbarAnnotationRenderer; }
	#endif
	
};


typedef System::TMetaClass* TcxScrollBarHelperClass;

class PASCALIMPLEMENTATION TcxScrollBar : public Vcl::Controls::TCustomControl
{
	typedef Vcl::Controls::TCustomControl inherited;
	
private:
	TcxScrollBarHelper* FHelper;
	Cxlookandfeels::TcxLookAndFeel* FLookAndFeel;
	bool FRealCtl3D;
	Cxgeometry::TdxOwnedScaleFactor* FScaleFactor;
	Dxthememanager::TdxThemeChangedNotificator* FThemeChangedNotificator;
	System::Classes::TNotifyEvent FOnChange;
	System::Classes::TNotifyEvent FOnMouseEnter;
	System::Classes::TNotifyEvent FOnMouseLeave;
	Vcl::Stdctrls::TScrollEvent FOnScroll;
	bool __fastcall GetCtl3D();
	bool __fastcall GetInternalCtl3D();
	bool __fastcall GetReverseDirection();
	HIDESBASE bool __fastcall IsCtl3DStored();
	HIDESBASE void __fastcall SetCtl3D(bool Value);
	void __fastcall SetInternalCtl3D(bool Value);
	void __fastcall SetReverseDirection(bool AValue);
	void __fastcall ThemeChanged();
	HIDESBASE MESSAGE void __fastcall CMCtl3DChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMEnabledChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseEnter(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseLeave(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMSysColorChange(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMVisibleChanged(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall CNHScroll(Winapi::Messages::TWMScroll &Message);
	MESSAGE void __fastcall CNVScroll(Winapi::Messages::TWMScroll &Message);
	MESSAGE void __fastcall CNCtlColorScrollBar(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMCancelMode(Winapi::Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Winapi::Messages::TWMEraseBkgnd &Message);
	HIDESBASE MESSAGE void __fastcall WMGestureNotify(Dxtouch::TWMGestureNotify &Message);
	
protected:
	DYNAMIC void __fastcall ChangeScale(int M, int D, bool isDpiChange)/* overload */;
	void __fastcall DoChange(System::TObject* Sender);
	void __fastcall DoScrollEvent(System::TObject* Sender, System::Uitypes::TScrollCode ScrollCode, int &ScrollPos);
	virtual void __fastcall Change();
	virtual System::Types::TSize __fastcall GetInitialSize();
	virtual TcxScrollBarHelperClass __fastcall GetHelperClass();
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetPainter();
	virtual void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseEnter(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	HIDESBASE Vcl::Controls::TWinControl* __fastcall GetControl();
	Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeel();
	Cxgeometry::TdxScaleFactor* __fastcall GetScaleFactor();
	Vcl::Forms::TScrollBarKind __fastcall GetKind();
	Vcl::Forms::TScrollBarInc __fastcall GetLargeChange();
	int __fastcall GetMax();
	int __fastcall GetMin();
	int __fastcall GetPageSize();
	int __fastcall GetPosition();
	Vcl::Forms::TScrollBarInc __fastcall GetSmallChange();
	bool __fastcall GetUnlimitedTracking();
	void __fastcall SetKind(Vcl::Forms::TScrollBarKind Value);
	void __fastcall SetLargeChange(Vcl::Forms::TScrollBarInc AValue);
	void __fastcall SetLookAndFeel(Cxlookandfeels::TcxLookAndFeel* Value);
	void __fastcall SetMax(int Value);
	void __fastcall SetMin(int Value);
	virtual void __fastcall SetParent(Vcl::Controls::TWinControl* AValue);
	void __fastcall SetPageSize(int Value);
	void __fastcall SetPosition(int Value);
	void __fastcall SetSmallChange(Vcl::Forms::TScrollBarInc AValue);
	void __fastcall SetUnlimitedTracking(bool AValue);
	void __fastcall ScrollbarAnnotationsInvalidate(const Dxscrollbarannotations::TdxScrollbarAnnotationKinds &AAnnotationKinds = (Dxscrollbarannotations::TdxScrollbarAnnotationKinds() << 0x0 << 0x1 << 0x2 << 0x3 << 0x4 << 0x5 << 0x6 << 0x7 << 0x8 << 0x9 << 0xa << 0xb << 0xc << 0xd << 0xe << 0xf << 0x10 << 0x11 << 0x12 << 0x13 << 0x14 << 0x15 << 0x16 << 0x17 << 0x18 << 0x19 << 0x1a << 0x1b << 0x1c << 0x1d << 0x1e << 0x1f << 0x20 << 0x21 << 0x22 << 0x23 << 0x24 << 0x25 << 0x26 << 0x27 << 0x28 << 0x29 << 0x2a << 0x2b << 0x2c << 0x2d << 0x2e << 0x2f << 0x30 << 0x31 << 0x32 << 0x33 << 0x34 << 0x35 << 0x36 << 0x37 << 0x38 << 0x39 << 0x3a << 0x3b << 0x3c << 0x3d << 0x3e << 0x3f << 0x40 << 0x41 << 0x42 << 0x43 << 0x44 << 0x45 << 0x46 << 0x47 << 0x48 << 0x49 << 0x4a << 0x4b << 0x4c << 0x4d << 0x4e << 0x4f << 0x50 << 0x51 << 0x52 << 0x53 << 0x54 << 0x55 << 0x56 << 0x57 << 0x58 << 0x59 << 0x5a << 0x5b << 0x5c << 0x5d << 0x5e << 0x5f << 0x60 << 0x61 << 0x62 << 0x63 << 0x64 << 0x65 << 0x66 << 0x67 << 0x68 << 0x69 << 0x6a << 0x6b << 0x6c << 0x6d << 0x6e << 0x6f << 0x70 << 0x71 << 0x72 << 0x73 << 0x74 << 0x75 << 0x76 << 0x77 << 0x78 << 0x79 << 0x7a << 0x7b << 0x7c << 0x7d << 0x7e << 0x7f << 0x80 << 0x81 << 0x82 << 0x83 << 0x84 << 0x85 << 0x86 << 0x87 << 0x88 << 0x89 << 0x8a << 0x8b << 0x8c << 0x8d << 0x8e << 0x8f << 0x90 << 0x91 << 0x92 << 0x93 << 0x94 << 0x95 << 0x96 << 0x97 << 0x98 << 0x99 << 0x9a << 0x9b << 0x9c << 0x9d << 0x9e << 0x9f << 0xa0 << 0xa1 << 0xa2 << 0xa3 << 0xa4 << 0xa5 << 0xa6 << 0xa7 << 0xa8 << 0xa9 << 0xaa << 0xab << 0xac << 0xad << 0xae << 0xaf << 0xb0 << 0xb1 << 0xb2 << 0xb3 << 0xb4 << 0xb5 << 0xb6 << 0xb7 << 0xb8 << 0xb9 << 0xba << 0xbb << 0xbc << 0xbd << 0xbe << 0xbf << 0xc0 << 0xc1 << 0xc2 << 0xc3 << 0xc4 << 0xc5 << 0xc6 << 0xc7 << 0xc8 << 0xc9 << 0xca << 0xcb << 0xcc << 0xcd << 0xce << 0xcf << 0xd0 << 0xd1 << 0xd2 << 0xd3 << 0xd4 << 0xd5 << 0xd6 << 0xd7 << 0xd8 << 0xd9 << 0xda << 0xdb << 0xdc << 0xdd << 0xde << 0xdf << 0xe0 << 0xe1 << 0xe2 << 0xe3 << 0xe4 << 0xe5 << 0xe6 << 0xe7 << 0xe8 << 0xe9 << 0xea << 0xeb << 0xec << 0xed << 0xee << 0xef << 0xf0 << 0xf1 << 0xf2 << 0xf3 << 0xf4 << 0xf5 << 0xf6 << 0xf7 << 0xf8 << 0xf9 << 0xfa << 0xfb << 0xfc << 0xfd << 0xfe << 0xff ));
	void __fastcall SetAnnotations(Dxscrollbarannotations::TdxScrollbarAnnotations* AAnnotations);
	void __fastcall ScrollbarAnnotationsUpdate();
	virtual void __fastcall DoPaint(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall Paint();
	DYNAMIC void __fastcall Resize();
	virtual void __fastcall Scroll(System::Uitypes::TScrollCode ScrollCode, int &ScrollPos);
	__property TcxScrollBarHelper* Helper = {read=FHelper};
	__property bool InternalCtl3D = {read=GetInternalCtl3D, write=SetInternalCtl3D, nodefault};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* Painter = {read=GetPainter};
	__property Cxgeometry::TdxOwnedScaleFactor* ScaleFactor = {read=FScaleFactor};
	
public:
	__fastcall virtual TcxScrollBar(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxScrollBar();
	void __fastcall SetScrollParams(int AMin, int AMax, int APosition, int APageSize, bool ARedraw = true);
	void __fastcall SetParams(int APosition, int AMin, int AMax);
	
__published:
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property BiDiMode;
	__property Constraints;
	__property Ctl3D = {read=GetCtl3D, write=SetCtl3D, stored=IsCtl3DStored};
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property Vcl::Forms::TScrollBarKind Kind = {read=GetKind, write=SetKind, default=0};
	__property Vcl::Forms::TScrollBarInc LargeChange = {read=GetLargeChange, write=SetLargeChange, default=1};
	__property Cxlookandfeels::TcxLookAndFeel* LookAndFeel = {read=FLookAndFeel, write=SetLookAndFeel};
	__property int Max = {read=GetMax, write=SetMax, default=100};
	__property int Min = {read=GetMin, write=SetMin, default=0};
	__property int PageSize = {read=GetPageSize, write=SetPageSize, nodefault};
	__property ParentBiDiMode = {default=1};
	__property ParentCtl3D = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property int Position = {read=GetPosition, write=SetPosition, default=0};
	__property bool ReverseDirection = {read=GetReverseDirection, write=SetReverseDirection, default=0};
	__property ShowHint;
	__property Vcl::Forms::TScrollBarInc SmallChange = {read=GetSmallChange, write=SetSmallChange, default=1};
	__property bool UnlimitedTracking = {read=GetUnlimitedTracking, write=SetUnlimitedTracking, default=0};
	__property Visible = {default=1};
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property OnContextPopup;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property System::Classes::TNotifyEvent OnMouseEnter = {read=FOnMouseEnter, write=FOnMouseEnter};
	__property System::Classes::TNotifyEvent OnMouseLeave = {read=FOnMouseLeave, write=FOnMouseLeave};
	__property OnMouseWheel;
	__property OnMouseWheelDown;
	__property OnMouseWheelUp;
	__property Vcl::Stdctrls::TScrollEvent OnScroll = {read=FOnScroll, write=FOnScroll};
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxScrollBar(HWND ParentWindow) : Vcl::Controls::TCustomControl(ParentWindow) { }
	
	/* Hoisted overloads: */
	
protected:
	DYNAMIC inline void __fastcall  ChangeScale(int M, int D){ Vcl::Controls::TControl::ChangeScale(M, D); }
	
private:
	void *__IdxScrollbarAnnotationRenderer;	// Dxscrollbarannotations::IdxScrollbarAnnotationRenderer 
	void *__IdxSkinSupport;	// Cxlookandfeels::IdxSkinSupport 
	void *__IcxScrollBarOwner;	// IcxScrollBarOwner 
	void *__IdxScaleFactor;	// Cxgeometry::IdxScaleFactor 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {0C20A750-FAFE-4A96-A0FB-DE73BCF98CF9}
	operator Dxscrollbarannotations::_di_IdxScrollbarAnnotationRenderer()
	{
		Dxscrollbarannotations::_di_IdxScrollbarAnnotationRenderer intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Dxscrollbarannotations::IdxScrollbarAnnotationRenderer*(void) { return (Dxscrollbarannotations::IdxScrollbarAnnotationRenderer*)&__IdxScrollbarAnnotationRenderer; }
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
	operator Cxlookandfeels::IdxSkinSupport*(void) { return (Cxlookandfeels::IdxSkinSupport*)&__IdxSkinSupport; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {56771164-C253-40FF-B6D4-2A29D0C90236}
	operator _di_IcxScrollBarOwner()
	{
		_di_IcxScrollBarOwner intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IcxScrollBarOwner*(void) { return (IcxScrollBarOwner*)&__IcxScrollBarOwner; }
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


typedef System::TMetaClass* TcxScrollBarClass;

//-- var, const, procedure ---------------------------------------------------
static const System::Word cxScrollInitialInterval = System::Word(0x190);
static const System::Int8 cxScrollInterval = System::Int8(0x3c);
extern DELPHI_PACKAGE int cxScrollMinDistance;
extern DELPHI_PACKAGE int cxScrollMaxDistance;
extern DELPHI_PACKAGE System::Types::TSize cxTouchScrollbarSize;
extern DELPHI_PACKAGE System::Types::TSize cxHybridScrollbarMaxSize;
extern DELPHI_PACKAGE System::Types::TSize cxHybridScrollbarMinSize;
extern DELPHI_PACKAGE System::Types::TSize __fastcall GetScaledScrollBarSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
extern DELPHI_PACKAGE System::Types::TSize __fastcall GetTouchScrollBarSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
extern DELPHI_PACKAGE System::Types::TSize __fastcall GetHybridScrollBarSize(Cxgeometry::TdxScaleFactor* AScaleFactor, bool AExpanded);
extern DELPHI_PACKAGE System::Types::TSize __fastcall GetScrollBarSize(void);
}	/* namespace Cxscrollbar */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSCROLLBAR)
using namespace Cxscrollbar;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxscrollbarHPP
