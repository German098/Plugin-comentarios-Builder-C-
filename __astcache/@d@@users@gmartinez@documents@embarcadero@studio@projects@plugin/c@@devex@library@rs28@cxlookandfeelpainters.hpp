// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxLookAndFeelPainters.pas' rev: 35.00 (Windows)

#ifndef CxlookandfeelpaintersHPP
#define CxlookandfeelpaintersHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.UITypes.hpp>
#include <System.Types.hpp>
#include <Winapi.Windows.hpp>
#include <dxCore.hpp>
#include <dxUxTheme.hpp>
#include <dxThemeManager.hpp>
#include <System.Classes.hpp>
#include <Vcl.Graphics.hpp>
#include <System.Generics.Collections.hpp>
#include <System.Generics.Defaults.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.ImgList.hpp>
#include <dxCoreGraphics.hpp>
#include <dxOffice11.hpp>
#include <cxClasses.hpp>
#include <cxGraphics.hpp>
#include <cxGeometry.hpp>
#include <dxGDIPlusClasses.hpp>
#include <cxCustomCanvas.hpp>
#include <dxThemeConsts.hpp>
#include <dxGenerics.hpp>
#include <Vcl.Forms.hpp>
#include <System.Contnrs.hpp>

//-- user supplied -----------------------------------------------------------

namespace Cxlookandfeelpainters
{
//-- forward type declarations -----------------------------------------------
struct TdxGalleryItemViewState;
struct TdxFilterTokenParams;
__interface DELPHIINTERFACE IcxLookAndFeelPainterListener;
typedef System::DelphiInterface<IcxLookAndFeelPainterListener> _di_IcxLookAndFeelPainterListener;
class DELPHICLASS TcxCustomLookAndFeelPainter;
class DELPHICLASS TcxStandardLookAndFeelPainter;
class DELPHICLASS TcxFlatLookAndFeelPainter;
class DELPHICLASS TcxUltraFlatLookAndFeelPainter;
class DELPHICLASS TcxOffice11LookAndFeelPainter;
class DELPHICLASS TcxWinXPLookAndFeelPainter;
class DELPHICLASS TcxLookAndFeelPaintersManager;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TcxLookAndFeelStyle : unsigned char { lfsFlat, lfsStandard, lfsUltraFlat, lfsNative, lfsOffice11, lfsSkin };

typedef System::Set<TcxLookAndFeelStyle, TcxLookAndFeelStyle::lfsFlat, TcxLookAndFeelStyle::lfsSkin> TcxLookAndFeelStyles;

enum DECLSPEC_DENUM TcxEditBtnPosition : unsigned char { cxbpLeft, cxbpRight };

enum DECLSPEC_DENUM TcxGroupBoxCaptionPosition : unsigned char { cxgpTop, cxgpBottom, cxgpLeft, cxgpRight, cxgpCenter };

enum DECLSPEC_DENUM TcxNeighbor : unsigned char { nLeft, nTop, nRight, nBottom };

typedef System::Set<TcxNeighbor, TcxNeighbor::nLeft, TcxNeighbor::nBottom> TcxNeighbors;

enum DECLSPEC_DENUM TcxScrollBarPart : unsigned char { sbpNone, sbpLineUp, sbpLineDown, sbpThumbnail, sbpPageUp, sbpPageDown };

enum DECLSPEC_DENUM TcxTrackBarTicksAlign : unsigned char { tbtaUp, tbtaDown, tbtaBoth };

enum DECLSPEC_DENUM TcxLayoutElement : unsigned char { leGroup, leGroupWithoutBorders, leTabbedGroup, leRootGroup, leRootGroupWithoutBorders, leItem };

enum DECLSPEC_DENUM TdxBevelShape : unsigned char { dxbsNone, dxbsBox, dxbsFrame, dxbsLineTop, dxbsLineBottom, dxbsLineLeft, dxbsLineRight, dxbsLineCenteredHorz, dxbsLineCenteredVert };

enum DECLSPEC_DENUM TdxBevelStyle : unsigned char { dxbsLowered, dxbsRaised };

enum DECLSPEC_DENUM TdxBreadcrumbEditButtonState : unsigned char { dxbcbsNormal, dxbcbsFocused, dxbcbsHot, dxbcbsPressed, dxbcbsDisabled };

enum DECLSPEC_DENUM TdxBreadcrumbEditState : unsigned char { dxbcsNormal, dxbcsFocused, dxbcsHot, dxbcsDisabled };

enum DECLSPEC_DENUM TcxEditCheckState : unsigned char { ecsNormal, ecsHot, ecsPressed, ecsDisabled };

enum DECLSPEC_DENUM TcxButtonPart : unsigned char { cxbpButton, cxbpDropDownLeftPart, cxbpDropDownRightPart };

enum DECLSPEC_DENUM TcxButtonState : unsigned char { cxbsDefault, cxbsNormal, cxbsHot, cxbsPressed, cxbsDisabled };

enum DECLSPEC_DENUM TcxCheckBoxState : unsigned char { cbsUnchecked, cbsChecked, cbsGrayed };

enum DECLSPEC_DENUM TcxProgressBarPart : unsigned char { pbpBackground, pbpProgressChunk, pbpOverloadBar, pbpPeakBar };

enum DECLSPEC_DENUM TdxRatingControlIndicatorState : unsigned char { rcisUnchecked, rcisChecked, rcisHover };

struct DECLSPEC_DRECORD TdxGalleryItemViewState
{
public:
	bool Enabled;
	bool Checked;
	bool Hover;
	bool Pressed;
	bool Focused;
};


struct DECLSPEC_DRECORD TdxFilterTokenParams
{
public:
	System::Uitypes::TColor BoolOperatorTextColor;
	System::Types::TRect BoolOperatorTextMargins;
	int ElementsIndent;
	System::Uitypes::TColor FilterControlBackgroundColor;
	System::Types::TRect FilterPanelItemMargins;
	System::Uitypes::TColor ItemCaptionTextColor;
	System::Types::TRect ItemCaptionTextMargins;
	System::Uitypes::TColor OperatorTextColor;
	System::Types::TRect OperatorTextMargins;
	System::Uitypes::TColor ValueTextColor;
	System::Types::TRect ValueTextMargins;
};


enum DECLSPEC_DENUM TdxListViewItemState : unsigned char { dxlisFocused, dxlisHot, dxlisSelected, dxlisDisabled, dxlisInactive };

typedef System::Set<TdxListViewItemState, TdxListViewItemState::dxlisFocused, TdxListViewItemState::dxlisInactive> TdxListViewItemStates;

enum DECLSPEC_DENUM TdxListViewGroupHeaderState : unsigned char { dxlgsFocused, dxlgsHot, dxlgsCollapsed, dxlgsInactive };

typedef System::Set<TdxListViewGroupHeaderState, TdxListViewGroupHeaderState::dxlgsFocused, TdxListViewGroupHeaderState::dxlgsInactive> TdxListViewGroupHeaderStates;

enum DECLSPEC_DENUM TdxListViewGroupTextKind : unsigned char { dxlgtHeader, dxlgtSubtitle, dxlgtFooter };

enum DECLSPEC_DENUM TcxEditBtnKind : unsigned char { cxbkCloseBtn, cxbkComboBtn, cxbkEditorBtn, cxbkEllipsisBtn, cxbkSpinUpBtn, cxbkSpinDownBtn, cxbkSpinLeftBtn, cxbkSpinRightBtn };

enum DECLSPEC_DENUM TcxEditStateColorKind : unsigned char { esckNormal, esckDisabled, esckInactive, esckReadOnly };

enum DECLSPEC_DENUM TcxCalcButtonKind : unsigned char { cbBack, cbCancel, cbClear, cbMC, cbMR, cbMS, cbMP, cbNum0, cbNum1, cbNum2, cbNum3, cbNum4, cbNum5, cbNum6, cbNum7, cbNum8, cbNum9, cbSign, cbDecimal, cbDiv, cbMul, cbSub, cbAdd, cbSqrt, cbPercent, cbRev, cbEqual, cbNone };

enum DECLSPEC_DENUM TcxIndicatorKind : unsigned char { ikNone, ikArrow, ikEdit, ikInsert, ikMultiDot, ikMultiArrow, ikFilter, ikInplaceEdit };

enum DECLSPEC_DENUM TdxAlertWindowButtonKind : unsigned char { awbkClose, awbkPin, awbkDropdown, awbkPrevious, awbkNext, awbkCustom };

enum DECLSPEC_DENUM TcxFilterSmartTagState : unsigned char { fstsNormal, fstsHot, fstsPressed, fstsParentHot };

enum DECLSPEC_DENUM TdxMapControlElementState : unsigned char { mcesNormal, mcesHot, mcesPressed, mcesSelected, mcesDisabled };

typedef System::Set<TdxMapControlElementState, TdxMapControlElementState::mcesNormal, TdxMapControlElementState::mcesDisabled> TdxMapControlElementStates;

enum DECLSPEC_DENUM TcxCalendarElementState : unsigned char { cesNormal, cesHot, cesPressed, cesSelected, cesFocused, cesMarked, cesDisabled, cesHighlighted };

typedef System::Set<TcxCalendarElementState, TcxCalendarElementState::cesNormal, TcxCalendarElementState::cesHighlighted> TcxCalendarElementStates;

enum DECLSPEC_DENUM TcxExpandButtonState : unsigned char { cebsNormal, cebsSelected, cebsInactive };

enum DECLSPEC_DENUM TcxFilterButtonShowMode : unsigned char { fbmButton, fbmSmartTag, fbmDefault };

enum DECLSPEC_DENUM TcxShowFilterButtons : unsigned char { sfbAlways, sfbWhenSelected, sfbDefault };

enum DECLSPEC_DENUM TdxTreeViewNodeState : unsigned char { dxtnsFocused, dxtnsHot, dxtnsSelected, dxtnsDisabled, dxtnsInactive };

typedef System::Set<TdxTreeViewNodeState, TdxTreeViewNodeState::dxtnsFocused, TdxTreeViewNodeState::dxtnsInactive> TdxTreeViewNodeStates;

enum DECLSPEC_DENUM TcxContainerBorderStyle : unsigned char { cbsNone, cbsSingle, cbsThick, cbsFlat, cbs3D, cbsUltraFlat, cbsOffice11 };

enum DECLSPEC_DENUM TcxContainerBorderState : unsigned char { cbsNormal, cbsFocused, cbsHovered, cbsFocusedAndHovered, cbsDisabled };

enum DECLSPEC_DENUM TcxEditPopupBorderStyle : unsigned char { epbsDefault, epbsSingle, epbsFrame3D, epbsFlat };

enum DECLSPEC_DENUM TcxPopupBorderStyle : unsigned char { pbsNone, pbsUltraFlat, pbsFlat, pbs3D };

typedef bool __fastcall (__closure *TcxDrawBackgroundEvent)(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);

typedef void __fastcall (__closure *TdxDrawEvent)(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);

typedef void __fastcall (__closure *TdxDrawScaledRectEvent)(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxgeometry::TdxScaleFactor* AScaleFactor);

__interface  INTERFACE_UUID("{DCED3226-2C4B-48B9-6EC4-968B0E7EA468}") IcxLookAndFeelPainterListener  : public System::IInterface 
{
	virtual void __fastcall PainterAdded(TcxCustomLookAndFeelPainter* APainter) = 0 ;
	virtual void __fastcall PainterRemoved(TcxCustomLookAndFeelPainter* APainter) = 0 ;
};

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomLookAndFeelPainter : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	Dxgdiplusclasses::TdxSmartImage* FBackButton;
	Dxgdiplusclasses::TdxSmartImage* FCalendarButtonGlyph;
	Dxgdiplusclasses::TdxSmartImage* FClearButtonGlyph;
	Dxgdiplusclasses::TdxSmartImage* FClockFace;
	Dxgdiplusclasses::TdxSmartImage* FClockGlass;
	Dxgdiplusclasses::TdxSmartImage* FClockFace150;
	Dxgdiplusclasses::TdxSmartImage* FClockGlass150;
	Dxgdiplusclasses::TdxSmartImage* FFilterControlAddButtonGlyph;
	Dxgdiplusclasses::TdxSmartImage* FFilterControlRemoveButtonGlyph;
	Dxgdiplusclasses::TdxSmartImage* FFilterPanelRemoveButtonGlyph;
	Dxgdiplusclasses::TdxSmartImage* FFindPanelNextButtonGlyph;
	Dxgdiplusclasses::TdxSmartImage* FFindPanelPreviousButtonGlyph;
	Dxgdiplusclasses::TdxSmartImage* FFixedGroupIndicator;
	Dxgdiplusclasses::TdxSmartImage* FGroupByBoxSearchButtonGlyph;
	Dxgdiplusclasses::TdxSmartImage* FMapPushpin;
	Dxgdiplusclasses::TdxSmartImage* FNavigationBarCustomizationButton;
	System::StaticArray<Dxgdiplusclasses::TdxSmartImage*, 2> FPasswordRevealButtonGlyphs;
	Dxgdiplusclasses::TdxSmartImage* FPinGlyph;
	Dxgdiplusclasses::TdxSmartImage* FRatingControlIndicator;
	Dxgdiplusclasses::TdxSmartImage* FSearchButtonGlyph;
	Dxgdiplusclasses::TdxSmartImage* FSmartTagGlyph;
	Dxgdiplusclasses::TdxSmartImage* __fastcall GetBackButton();
	Dxgdiplusclasses::TdxSmartImage* __fastcall GetCalendarButtonGlyph();
	Dxgdiplusclasses::TdxSmartImage* __fastcall GetClearButtonGlyph();
	Dxgdiplusclasses::TdxSmartImage* __fastcall GetClockFace();
	Dxgdiplusclasses::TdxSmartImage* __fastcall GetClockGlass();
	Dxgdiplusclasses::TdxSmartImage* __fastcall GetFilterControlAddButtonGlyph();
	Dxgdiplusclasses::TdxSmartImage* __fastcall GetFilterControlRemoveButtonGlyph();
	Dxgdiplusclasses::TdxSmartImage* __fastcall GetFilterPanelRemoveButtonGlyph();
	Dxgdiplusclasses::TdxSmartImage* __fastcall GetFindPanelNextButtonGlyph();
	Dxgdiplusclasses::TdxSmartImage* __fastcall GetFindPanelPreviousButtonGlyph();
	Dxgdiplusclasses::TdxSmartImage* __fastcall GetFixedGroupIndicator();
	Dxgdiplusclasses::TdxSmartImage* __fastcall GetGroupByBoxSearchButtonGlyph();
	Dxgdiplusclasses::TdxSmartImage* __fastcall GetMapPushpin();
	Dxgdiplusclasses::TdxSmartImage* __fastcall GetNavigationBarCustomizationButton();
	Dxgdiplusclasses::TdxSmartImage* __fastcall GetPasswordRevealButtonGlyphs(bool Index);
	Dxgdiplusclasses::TdxSmartImage* __fastcall GetPinGlyph();
	System::Types::TRect __fastcall GetRangeTrackBarThumbDrawRect(const System::Types::TRect &R, TcxTrackBarTicksAlign ATicks, bool AHorizontal);
	Dxgdiplusclasses::TdxSmartImage* __fastcall GetRatingControlIndicator();
	Dxgdiplusclasses::TdxSmartImage* __fastcall GetSearchButtonGlyph();
	Dxgdiplusclasses::TdxSmartImage* __fastcall GetSmartTagGlyph();
	
private:
	Dxgdiplusclasses::TdxSmartImage* __fastcall GetClockFace150();
	Dxgdiplusclasses::TdxSmartImage* __fastcall GetClockGlass150();
	
protected:
	System::TObject* FLookAndFeelPainterDetailsCache;
	virtual System::TObject* __fastcall CreateLookAndFeelPainterDetails();
	virtual System::TObject* __fastcall GetLookAndFeelPainterDetails();
	virtual System::Uitypes::TColor __fastcall DefaultDateNavigatorHeaderHighlightTextColor();
	virtual void __fastcall DoDrawDataRowLayoutContent(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual void __fastcall DoDrawScaledButtonCaption(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, const System::UnicodeString ACaption, TcxButtonState AState, System::Uitypes::TColor ATextColor, bool ADrawBorder, bool AIsToolButton, bool AWordWrap, Cxgeometry::TdxScaleFactor* AScaleFactor, TcxButtonPart APart);
	virtual void __fastcall DoDrawScaledScrollBarPart(Cxcustomcanvas::TcxCustomCanvas* ACanvas, bool AHorizontal, const System::Types::TRect &R, TcxScrollBarPart APart, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool ATransparent, System::Uitypes::TColor ABackgroundColor, Vcl::Graphics::TBitmap* const ABackgroundBitmap);
	virtual void __fastcall DrawButtonArrow(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor AColor);
	virtual void __fastcall DrawContent(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &ATextAreaBounds, TcxButtonState AState, System::Classes::TAlignment AAlignmentHorz, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AMultiLine, bool AShowEndEllipsis, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor, TcxDrawBackgroundEvent AOnDrawBackground = 0x0, bool AIsFooter = false);
	virtual void __fastcall DrawContentBackground(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, System::Uitypes::TColor ABackgroundColor, bool AIsFooter);
	void __fastcall DrawExpandButtonCross(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, bool AExpanded, System::Uitypes::TColor AColor, Cxgeometry::TdxScaleFactor* AScaleFactor);
	void __fastcall DrawListViewColumnHeaderSortingArrow(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, bool AAscendingSorting, Cxgeometry::TdxScaleFactor* AScaleFactor);
	void __fastcall DrawMonthHeaderArrows(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, Cxgraphics::TcxArrowDirections AArrows, int ASideWidth, System::Uitypes::TColor AColor);
	void __fastcall DrawMonthHeaderLeftArrow(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, System::Uitypes::TColor AColor);
	void __fastcall DrawMonthHeaderRightArrow(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, System::Uitypes::TColor AColor);
	void __fastcall DrawRangeControlThumb(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, System::Uitypes::TColor AColor, Dxcoregraphics::TdxAlphaColor ABorderColor, Cxgeometry::TdxScaleFactor* AScaleFactor);
	void __fastcall DrawSortingArrow(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, bool AAscendingSorting, Cxgeometry::TdxScaleFactor* AScaleFactor);
	void __fastcall DrawSummarySortingArrow(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, bool AAscendingSorting, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawSchedulerNavigationButtonContent(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const System::Types::TRect &AArrowRect, bool AIsNextButton, TcxButtonState AState, const bool AIsVertical = true);
	virtual int __fastcall FooterCellOffset();
	virtual int __fastcall FooterCellContentOffset();
	virtual int __fastcall FooterContentOffset();
	Cxgraphics::TcxArrowDirection __fastcall GetArrowDirection(bool AHorizontal, TcxScrollBarPart APart);
	virtual System::Uitypes::TColor __fastcall GetDataRowLayoutContentColor();
	virtual System::Types::TRect __fastcall GetDataRowLayoutContentMargins();
	virtual System::Types::TRect __fastcall GetDataRowLayoutItemMargins(TcxButtonState AState);
	virtual System::Byte __fastcall GetDefaultFixedColumnHighlightAAlpha();
	virtual Dxcoregraphics::TdxAlphaColor __fastcall GetFilterAddButtonColor(TcxButtonState AState);
	virtual Dxcoregraphics::TdxAlphaColor __fastcall GetFilterRemoveButtonColor(TcxButtonState AState);
	virtual System::Uitypes::TColor __fastcall GetFilterSmartTagColor(TcxFilterSmartTagState AState, bool AIsFilterActive);
	virtual System::Types::TRect __fastcall GetSeparatorBounds(const System::Types::TRect &R, int AWidth, bool AIsVertical);
	virtual void __fastcall ReleaseImageResources();
	__property Dxgdiplusclasses::TdxSmartImage* BackButton = {read=GetBackButton};
	__property Dxgdiplusclasses::TdxSmartImage* CalendarButtonGlyph = {read=GetCalendarButtonGlyph};
	__property Dxgdiplusclasses::TdxSmartImage* ClearButtonGlyph = {read=GetClearButtonGlyph};
	__property Dxgdiplusclasses::TdxSmartImage* ClockFace = {read=GetClockFace};
	__property Dxgdiplusclasses::TdxSmartImage* ClockGlass = {read=GetClockGlass};
	__property Dxgdiplusclasses::TdxSmartImage* ClockFace150 = {read=GetClockFace150};
	__property Dxgdiplusclasses::TdxSmartImage* ClockGlass150 = {read=GetClockGlass150};
	__property Dxgdiplusclasses::TdxSmartImage* FilterControlAddButtonGlyph = {read=GetFilterControlAddButtonGlyph};
	__property Dxgdiplusclasses::TdxSmartImage* FilterControlRemoveButtonGlyph = {read=GetFilterControlRemoveButtonGlyph};
	__property Dxgdiplusclasses::TdxSmartImage* FilterPanelRemoveButtonGlyph = {read=GetFilterPanelRemoveButtonGlyph};
	__property Dxgdiplusclasses::TdxSmartImage* FindPanelNextButtonGlyph = {read=GetFindPanelNextButtonGlyph};
	__property Dxgdiplusclasses::TdxSmartImage* FindPanelPreviousButtonGlyph = {read=GetFindPanelPreviousButtonGlyph};
	__property Dxgdiplusclasses::TdxSmartImage* FixedGroupIndicator = {read=GetFixedGroupIndicator};
	__property Dxgdiplusclasses::TdxSmartImage* GroupByBoxSearchButtonGlyph = {read=GetGroupByBoxSearchButtonGlyph};
	__property Dxgdiplusclasses::TdxSmartImage* MapPushpin = {read=GetMapPushpin};
	__property Dxgdiplusclasses::TdxSmartImage* NavigationBarCustomizationButton = {read=GetNavigationBarCustomizationButton};
	__property Dxgdiplusclasses::TdxSmartImage* PasswordRevealButtonGlyphs[bool Index] = {read=GetPasswordRevealButtonGlyphs};
	__property Dxgdiplusclasses::TdxSmartImage* PinGlyph = {read=GetPinGlyph};
	__property Dxgdiplusclasses::TdxSmartImage* RatingControlIndicator = {read=GetRatingControlIndicator};
	__property Dxgdiplusclasses::TdxSmartImage* SearchButtonGlyph = {read=GetSearchButtonGlyph};
	__property Dxgdiplusclasses::TdxSmartImage* SmartTagGlyph = {read=GetSmartTagGlyph};
	
public:
	__fastcall virtual ~TcxCustomLookAndFeelPainter();
	virtual bool __fastcall GetPainterData(void *AData);
	virtual bool __fastcall GetPainterDetails(void *ADetails);
	virtual bool __fastcall IsInternalPainter();
	virtual System::UnicodeString __fastcall LookAndFeelName();
	virtual TcxLookAndFeelStyle __fastcall LookAndFeelStyle();
	virtual bool __fastcall NeedRedrawOnResize();
	virtual void __fastcall ResetLookAndFeelSettings();
	virtual void __fastcall DrawScaledEditorBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AIsInplace, bool AReadOnly, System::Uitypes::TColor AColor, TcxContainerBorderState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledImageEditorBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AIsInplace, bool AReadOnly, System::Uitypes::TColor AColor, TcxContainerBorderState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledListBoxBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AIsInplace, System::Uitypes::TColor AColor, TcxContainerBorderState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledListBoxItemBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Winapi::Windows::TOwnerDrawState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual int __fastcall GetEditorGlyphIndent(bool ALeftMost, bool AIsInplace, Cxgeometry::TdxScaleFactor* AScaleFactor, int AControlID = 0x0);
	virtual System::Types::TRect __fastcall GetEditorPadding(bool AIsInplace, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TRect __fastcall GetEditorButtonPadding(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TRect __fastcall GetEditorButtonsPadding(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TRect __fastcall GetImageEditorPadding(bool AIsInplace, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TRect __fastcall GetListBoxBackgroundPadding(bool AIsInplace, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TRect __fastcall GetListBoxItemPadding(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TRect __fastcall GetListBoxScrollBarPadding(bool AIsInplace, Vcl::Forms::TScrollBarKind AKind, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual bool __fastcall SupportsEditorBorders();
	virtual bool __fastcall SupportsEditorPadding(const bool AIsInplace);
	virtual bool __fastcall SupportsImageEditorPadding();
	virtual bool __fastcall SupportsListBoxPadding();
	virtual bool __fastcall SupportsEditorShadow();
	virtual bool __fastcall SupportsTransparentBorder();
	virtual System::Uitypes::TColor __fastcall DefaultContentColor();
	virtual System::Uitypes::TColor __fastcall DefaultContentEvenColor();
	virtual Dxcoregraphics::_di_IdxColorPalette __fastcall DefaultContentGlyphColorPalette(TcxButtonState AState);
	virtual System::Uitypes::TColor __fastcall DefaultContentOddColor();
	virtual System::Uitypes::TColor __fastcall DefaultContentTextColor();
	virtual System::Uitypes::TColor __fastcall DefaultControlColor();
	virtual System::Uitypes::TColor __fastcall DefaultControlTextColor();
	virtual Dxcoregraphics::TdxAlphaColor __fastcall DefaultCustomScrollbarAnnotationColor();
	virtual System::Uitypes::TColor __fastcall DefaultEditorBackgroundColor(bool AIsDisabled);
	virtual System::Uitypes::TColor __fastcall DefaultEditorBackgroundColorEx(TcxEditStateColorKind AKind);
	virtual System::Uitypes::TColor __fastcall DefaultEditorTextColor(bool AIsDisabled);
	virtual System::Uitypes::TColor __fastcall DefaultEditorTextColorEx(TcxEditStateColorKind AKind);
	virtual Dxcoregraphics::TdxAlphaColor __fastcall DefaultErrorScrollbarAnnotationColor();
	virtual System::Uitypes::TColor __fastcall DefaultFilterBoxColor();
	virtual System::Uitypes::TColor __fastcall DefaultFilterBoxTextColor();
	virtual Dxcoregraphics::TdxAlphaColor __fastcall DefaultFixedColumnHighlightColor();
	virtual System::Uitypes::TColor __fastcall DefaultFixedSeparatorColor();
	virtual Dxcoregraphics::TdxAlphaColor __fastcall DefaultFocusedScrollbarAnnotationColor();
	virtual System::Uitypes::TColor __fastcall DefaultFooterColor();
	virtual System::Uitypes::TColor __fastcall DefaultFooterTextColor();
	virtual int __fastcall DefaultGridExpandButtonIndent();
	virtual System::Uitypes::TColor __fastcall DefaultGridDetailsSiteColor();
	virtual System::Uitypes::TColor __fastcall DefaultGridLineColor();
	virtual System::Uitypes::TColor __fastcall DefaultGroupByBoxColor();
	virtual System::Uitypes::TColor __fastcall DefaultGroupByBoxLineColor();
	virtual System::Uitypes::TColor __fastcall DefaultGroupByBoxTextColor();
	virtual System::Uitypes::TColor __fastcall DefaultGroupColor();
	virtual System::Types::TRect __fastcall DefaultGroupContentOffsets(Cxgeometry::TdxScaleFactor* AScaleFactor = (Cxgeometry::TdxScaleFactor*)(0x0));
	virtual System::Uitypes::TColor __fastcall DefaultGroupTextColor();
	virtual System::Uitypes::TColor __fastcall DefaultHeaderBackgroundColor();
	virtual System::Uitypes::TColor __fastcall DefaultHeaderBackgroundTextColor();
	virtual System::Uitypes::TColor __fastcall DefaultHeaderColor();
	virtual System::Uitypes::TColor __fastcall DefaultHeaderTextColor();
	virtual System::Uitypes::TColor __fastcall DefaultHyperlinkTextColor();
	virtual System::Uitypes::TColor __fastcall DefaultInactiveColor();
	virtual System::Uitypes::TColor __fastcall DefaultInactiveTextColor();
	virtual System::Uitypes::TColor __fastcall DefaultLabelTextColorEx(TcxEditStateColorKind AKind);
	virtual System::Uitypes::TColor __fastcall DefaultPreviewTextColor();
	virtual System::Uitypes::TColor __fastcall DefaultRecordSeparatorColor();
	virtual Dxcoregraphics::TdxAlphaColor __fastcall DefaultSearchResultAnnotationColor();
	virtual System::Uitypes::TColor __fastcall DefaultSearchResultHighlightColor();
	virtual System::Uitypes::TColor __fastcall DefaultSearchResultHighlightTextColor();
	virtual Dxcoregraphics::TdxAlphaColor __fastcall DefaultSelectedScrollbarAnnotationColor();
	virtual System::Uitypes::TColor __fastcall DefaultSizeGripAreaColor();
	virtual System::Uitypes::TColor __fastcall DefaultTreeListGridLineColor();
	virtual System::Uitypes::TColor __fastcall DefaultTreeListTreeLineColor();
	virtual System::Uitypes::TColor __fastcall DefaultVGridBandLineColor();
	virtual System::Uitypes::TColor __fastcall DefaultVGridCategoryColor();
	virtual System::Uitypes::TColor __fastcall DefaultVGridCategoryTextColor();
	virtual System::Uitypes::TColor __fastcall DefaultVGridContentColor();
	virtual System::Uitypes::TColor __fastcall DefaultVGridContentEvenColor();
	virtual System::Uitypes::TColor __fastcall DefaultVGridContentOddColor();
	virtual System::Uitypes::TColor __fastcall DefaultVGridContentTextColor();
	virtual System::Uitypes::TColor __fastcall DefaultVGridHeaderColor();
	virtual System::Uitypes::TColor __fastcall DefaultVGridHeaderTextColor();
	virtual System::Uitypes::TColor __fastcall DefaultVGridLineColor();
	virtual System::Uitypes::TColor __fastcall DefaultDateNavigatorContentColor();
	virtual System::Uitypes::TColor __fastcall DefaultDateNavigatorHeaderColor();
	virtual System::Uitypes::TColor __fastcall DefaultDateNavigatorHeaderTextColor(bool AIsHighlight);
	virtual System::Uitypes::TColor __fastcall DefaultDateNavigatorHolydayTextColor();
	virtual System::Uitypes::TColor __fastcall DefaultDateNavigatorInactiveTextColor();
	virtual System::Uitypes::TColor __fastcall DefaultDateNavigatorSelectionColor();
	virtual System::Uitypes::TColor __fastcall DefaultDateNavigatorSelectionTextColor();
	virtual System::Uitypes::TColor __fastcall DefaultDateNavigatorSeparator1Color();
	virtual System::Uitypes::TColor __fastcall DefaultDateNavigatorSeparator2Color();
	virtual System::Uitypes::TColor __fastcall DefaultDateNavigatorTextColor();
	virtual System::Uitypes::TColor __fastcall DefaultDateNavigatorTodayFrameColor();
	virtual System::Uitypes::TColor __fastcall DefaultDateNavigatorTodayTextColor(bool ASelected = false);
	virtual System::Uitypes::TColor __fastcall DefaultDateNavigatorWeekendTextColor();
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerBackgroundColor();
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerBorderColor();
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerContentColor(int AResourceIndex);
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerControlColor();
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerDayHeaderColor();
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerDayHeaderBorderColor();
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerDayHeaderTextColor();
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerDateNavigatorArrowColor(bool AIsHighlight);
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerHeaderContainerAlternateBackgroundColor();
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerHeaderContainerBackgroundColor(bool ASelected);
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerHeaderContainerTextColor(bool ASelected);
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerHeaderContainerBorderColor();
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerEventColor(bool AIsAllDayEvent);
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerEventColorClassic(bool AIsAllDayEvent);
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerNavigatorColor();
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerSelectedEventBorderColor();
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerTextColor();
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerTimeRulerBorderColor();
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerTimeRulerBorderColorClassic();
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerTimeRulerColor();
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerTimeRulerColorClassic();
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerTimeRulerTextColor();
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerTimeRulerTextColorClassic();
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerViewContentColor();
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerViewContentColorClassic();
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerViewSelectedTextColor();
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerViewTextColor();
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerYearViewUnusedContentColor(bool AIsWorkTime);
	virtual System::Uitypes::TColor __fastcall DefaultHotTrackColor();
	virtual System::Uitypes::TColor __fastcall DefaultHotTrackTextColor();
	virtual System::Uitypes::TColor __fastcall DefaultSelectionColor();
	virtual System::Uitypes::TColor __fastcall DefaultSelectionTextColor();
	virtual System::Uitypes::TColor __fastcall DefaultSeparatorColor();
	virtual System::Uitypes::TColor __fastcall DefaultTabColor();
	virtual System::Uitypes::TColor __fastcall DefaultTabTextColor();
	virtual System::Uitypes::TColor __fastcall DefaultTabsBackgroundColor();
	virtual System::Uitypes::TColor __fastcall DefaultRootTabsBackgroundColor();
	virtual System::Uitypes::TColor __fastcall DefaultTimeGridMajorScaleColor();
	virtual System::Uitypes::TColor __fastcall DefaultTimeGridMajorScaleTextColor();
	virtual System::Uitypes::TColor __fastcall DefaultTimeGridMinorScaleColor();
	virtual System::Uitypes::TColor __fastcall DefaultTimeGridMinorScaleTextColor();
	virtual System::Uitypes::TColor __fastcall DefaultTimeGridSelectionBarColor();
	virtual System::Uitypes::TColor __fastcall DefaultChartDiagramValueBorderColor();
	virtual System::Uitypes::TColor __fastcall DefaultChartDiagramValueCaptionTextColor();
	virtual System::Uitypes::TColor __fastcall DefaultChartHistogramAxisColor();
	virtual System::Uitypes::TColor __fastcall DefaultChartHistogramGridLineColor();
	virtual System::Uitypes::TColor __fastcall DefaultChartHistogramPlotColor();
	virtual System::Uitypes::TColor __fastcall DefaultChartPieDiagramSeriesSiteBorderColor();
	virtual System::Uitypes::TColor __fastcall DefaultChartPieDiagramSeriesSiteCaptionColor();
	virtual System::Uitypes::TColor __fastcall DefaultChartPieDiagramSeriesSiteCaptionTextColor();
	virtual System::Uitypes::TColor __fastcall DefaultChartToolBoxDataLevelInfoBorderColor();
	virtual System::Uitypes::TColor __fastcall DefaultChartToolBoxItemSeparatorColor();
	virtual System::Uitypes::TColor __fastcall DefaultLayoutViewCaptionColor(TcxButtonState AState);
	virtual System::Uitypes::TColor __fastcall DefaultLayoutViewCaptionTextColor(TcxGroupBoxCaptionPosition ACaptionPosition, TcxButtonState AState);
	virtual System::Uitypes::TColor __fastcall DefaultLayoutViewContentColor();
	virtual System::Uitypes::TColor __fastcall DefaultLayoutViewContentTextColor(TcxButtonState AState);
	virtual System::Uitypes::TColor __fastcall DefaultGridOptionsTreeViewCategoryColor(bool ASelected);
	virtual System::Uitypes::TColor __fastcall DefaultGridOptionsTreeViewCategoryTextColor(bool ASelected);
	void __fastcall CalculateArrowPoints(const System::Types::TRect &R, Cxgraphics::TcxArrowPoints &P, Cxgraphics::TcxArrowDirection AArrowDirection, bool AProportional, int AArrowSize = 0x0);
	virtual void __fastcall DrawArrow(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, Cxgraphics::TcxArrowDirection AArrowDirection, System::Uitypes::TColor AColor)/* overload */;
	void __fastcall DrawArrow(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgraphics::TcxArrowDirection AArrowDirection, bool ADrawBorder = true)/* overload */;
	void __fastcall DrawArrowBorder(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState);
	virtual void __fastcall DrawCollapseArrow(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor AColor, int ALineWidth = 0x1);
	virtual void __fastcall DrawScaledArrow(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgraphics::TcxArrowDirection AArrowDirection, Cxgeometry::TdxScaleFactor* AScaleFactor, bool ADrawBorder = true)/* overload */;
	virtual void __fastcall DrawScaledArrowBorder(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledScrollBarArrow(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgraphics::TcxArrowDirection AArrowDirection, Cxgeometry::TdxScaleFactor* AScaleFactor);
	void __fastcall DrawScrollBarArrow(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgraphics::TcxArrowDirection AArrowDirection);
	virtual int __fastcall BorderSize();
	virtual int __fastcall SeparatorSize();
	virtual void __fastcall DrawBorder(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, int AWidth = 0x1);
	virtual void __fastcall DrawContainerBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxContainerBorderStyle AStyle, int AWidth, System::Uitypes::TColor AColor, Cxgeometry::TcxBorders ABorders);
	virtual void __fastcall DrawContainerBorderedBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxContainerBorderStyle AStyle, int AWidth, System::Uitypes::TColor AColor, Cxgeometry::TcxBorders ABorders, TcxContainerBorderState AState);
	virtual void __fastcall DoDrawSeparator(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, bool AIsVertical);
	void __fastcall DrawSeparator(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, bool AIsVertical);
	virtual bool __fastcall SupportsRoundedContainerBorders(int AControlID, bool AIsInplace);
	void __fastcall DrawPin(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, System::Uitypes::TColor AColor, bool APinned);
	void __fastcall DrawShellQuickAccessPin(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgraphics::TcxImageFitMode AImageFitMode, Dxcoregraphics::_di_IdxColorPalette APalette);
	virtual int __fastcall ButtonBorderSize(TcxButtonState AState = (TcxButtonState)(0x1));
	virtual System::Uitypes::TColor __fastcall ButtonColor(TcxButtonState AState);
	virtual Dxcoregraphics::_di_IdxColorPalette __fastcall ButtonColorPalette(TcxButtonState AState, TcxButtonPart APart = (TcxButtonPart)(0x0));
	virtual System::Uitypes::TColor __fastcall ButtonDescriptionTextColor(TcxButtonState AState, System::Uitypes::TColor ADefaultColor = (System::Uitypes::TColor)(0x20000000), TcxButtonPart APart = (TcxButtonPart)(0x0));
	System::Types::TRect __fastcall ButtonFocusRect(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual System::Uitypes::TColor __fastcall ButtonSymbolColor(TcxButtonState AState, System::Uitypes::TColor ADefaultColor = (System::Uitypes::TColor)(0x20000000), TcxButtonPart APart = (TcxButtonPart)(0x0));
	virtual TcxButtonState __fastcall ButtonSymbolState(TcxButtonState AState);
	int __fastcall ButtonTextOffset();
	int __fastcall ButtonTextShift();
	virtual System::Types::TRect __fastcall ScaledButtonFocusRect(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual int __fastcall ScaledButtonTextOffset(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual int __fastcall ScaledButtonTextShift(Cxgeometry::TdxScaleFactor* AScaleFactor);
	void __fastcall DrawButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, const System::UnicodeString ACaption, TcxButtonState AState, bool ADrawBorder = true, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000), System::Uitypes::TColor ATextColor = (System::Uitypes::TColor)(0x20000000), bool AWordWrap = false, bool AIsToolButton = false, TcxButtonPart APart = (TcxButtonPart)(0x0));
	virtual void __fastcall DrawButtonBorder(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState);
	void __fastcall DrawButtonCross(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor AColor, TcxButtonState AState)/* overload */;
	void __fastcall DrawButtonCross(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor AColor, TcxButtonState AState, int ASize)/* overload */;
	void __fastcall DrawScaledButton(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor, TcxButtonPart APart, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000))/* overload */;
	virtual void __fastcall DrawScaledButton(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor, bool ADrawBorder = true, bool AIsToolButton = false, TcxButtonPart APart = (TcxButtonPart)(0x0), System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000))/* overload */;
	virtual void __fastcall DrawScaledButton(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, bool AFocused, Cxgeometry::TdxScaleFactor* AScaleFactor, bool ADrawBorder = true, bool AIsToolButton = false, TcxButtonPart APart = (TcxButtonPart)(0x0), System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000))/* overload */;
	void __fastcall DrawScaledButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, const System::UnicodeString ACaption, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor, bool ADrawBorder = true, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000), System::Uitypes::TColor ATextColor = (System::Uitypes::TColor)(0x20000000), bool AWordWrap = false, bool AIsToolButton = false, TcxButtonPart APart = (TcxButtonPart)(0x0))/* overload */;
	void __fastcall DrawScaledButtonCross(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor AColor, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	void __fastcall DrawScaledButtonCrossEx(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor AColor, TcxButtonState AState, int ASize, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledClearButtonGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledDropDownButtonArrow(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	virtual void __fastcall DrawScaledSearchEditButtonGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	void __fastcall DrawScaledPasswordRevealButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TcxButtonState AButtonState, System::Uitypes::TColor AColor, Cxgeometry::TdxScaleFactor* AScaleFactor);
	void __fastcall DrawSearchEditButtonGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState);
	int __fastcall GetDropDownButtonRightPartSize();
	virtual System::Types::TSize __fastcall GetScaledClearButtonGlyphSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual int __fastcall GetScaledDropDownButtonRightPartSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual bool __fastcall IsButtonHotTrack();
	virtual bool __fastcall IsPointOverGroupExpandButton(const System::Types::TRect &R, const System::Types::TPoint &P);
	virtual System::Types::TSize __fastcall ScaledSearchButtonGlyphSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	void __fastcall DrawExpandButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AExpanded, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	void __fastcall DrawExpandButtonEx(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, bool AExpanded, Cxcustomcanvas::TcxRotationAngle ARotationAngle = (Cxcustomcanvas::TcxRotationAngle)(0x0));
	virtual bool __fastcall DrawExpandButtonFirst();
	void __fastcall DrawExpandMark(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor AColor, bool AExpanded);
	void __fastcall DrawGroupExpandButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AExpanded, TcxButtonState AState);
	virtual void __fastcall DrawScaledExpandButton(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, bool AExpanded, Cxgeometry::TdxScaleFactor* AScaleFactor, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000), TcxExpandButtonState AState = (TcxExpandButtonState)(0x0)) = 0 /* overload */;
	void __fastcall DrawScaledExpandButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AExpanded, Cxgeometry::TdxScaleFactor* AScaleFactor, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000), TcxExpandButtonState AState = (TcxExpandButtonState)(0x0))/* overload */;
	virtual void __fastcall DrawScaledExpandButtonEx(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, bool AExpanded, Cxgeometry::TdxScaleFactor* AScaleFactor, Cxcustomcanvas::TcxRotationAngle ARotationAngle = (Cxcustomcanvas::TcxRotationAngle)(0x0))/* overload */;
	virtual void __fastcall DrawScaledExpandMark(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor AColor, bool AExpanded, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledGroupExpandButton(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, bool AExpanded, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledSmallExpandButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AExpanded, System::Uitypes::TColor ABorderColor, Cxgeometry::TdxScaleFactor* AScaleFactor, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	void __fastcall DrawSmallExpandButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AExpanded, System::Uitypes::TColor ABorderColor, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	virtual void __fastcall DrawTreeViewExpandButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AExpanded, bool AExplorerStyle, Cxgeometry::TdxScaleFactor* AScaleFactor, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000), TcxExpandButtonState AState = (TcxExpandButtonState)(0x0))/* overload */;
	int __fastcall ExpandButtonAreaSize();
	int __fastcall ExpandButtonSize();
	int __fastcall GroupExpandButtonSize();
	int __fastcall SmallExpandButtonSize();
	virtual int __fastcall ScaledExpandButtonAreaSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual int __fastcall ScaledExpandButtonSize(Cxgeometry::TdxScaleFactor* AScaleFactor) = 0 ;
	virtual int __fastcall ScaledGroupExpandButtonSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual int __fastcall ScaledSmallExpandButtonSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TSize __fastcall TreeViewExpandButtonSize(bool AExplorerStyle, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Uitypes::TColor __fastcall DefaultCommandLinkTextColor(TcxButtonState AState, System::Uitypes::TColor ADefaultColor = (System::Uitypes::TColor)(0x20000000));
	void __fastcall DrawCommandLinkBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	void __fastcall DrawCommandLinkGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TPoint &AGlyphPos, TcxButtonState AState);
	virtual void __fastcall DrawScaledCommandLinkBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	virtual void __fastcall DrawScaledCommandLinkGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TPoint &AGlyphPos, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	System::Types::TSize __fastcall GetCommandLinkGlyphSize();
	System::Types::TRect __fastcall GetCommandLinkMargins();
	virtual System::Types::TSize __fastcall GetScaledCommandLinkGlyphSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TRect __fastcall GetScaledCommandLinkMargins(Cxgeometry::TdxScaleFactor* AScaleFactor);
	void __fastcall DrawHeader(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &ATextAreaBounds, TcxNeighbors ANeighbors, Cxgeometry::TcxBorders ABorders, TcxButtonState AState, System::Classes::TAlignment AAlignmentHorz, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AMultiLine, bool AShowEndEllipsis, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor, TcxDrawBackgroundEvent AOnDrawBackground = 0x0, bool AIsLast = false, bool AIsGroup = false);
	void __fastcall DrawHeaderEx(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &ATextAreaBounds, TcxNeighbors ANeighbors, Cxgeometry::TcxBorders ABorders, TcxButtonState AState, System::Classes::TAlignment AAlignmentHorz, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AMultiLine, bool AShowEndEllipsis, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor, TcxDrawBackgroundEvent AOnDrawBackground = 0x0);
	virtual void __fastcall DrawHeaderBorder(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, TcxNeighbors ANeighbors, Cxgeometry::TcxBorders ABorders);
	virtual void __fastcall DrawHeaderPressed(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	void __fastcall DrawHeaderControlSection(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &ATextAreaBounds, TcxNeighbors ANeighbors, Cxgeometry::TcxBorders ABorders, TcxButtonState AState, System::Classes::TAlignment AAlignmentHorz, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AMultiLine, bool AShowEndEllipsis, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor);
	virtual void __fastcall DrawHeaderControlSectionBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgeometry::TcxBorders ABorders, TcxButtonState AState);
	virtual void __fastcall DrawHeaderControlSectionContent(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &ATextAreaBounds, TcxButtonState AState, System::Classes::TAlignment AAlignmentHorz, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AMultiLine, bool AShowEndEllipsis, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor);
	virtual void __fastcall DrawHeaderControlSectionText(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ATextAreaBounds, TcxButtonState AState, System::Classes::TAlignment AAlignmentHorz, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AMultiLine, bool AShowEndEllipsis, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor);
	virtual void __fastcall DrawHeaderSeparator(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, int AIndentSize, System::Uitypes::TColor AColor, const Cxgraphics::TcxViewParams &AViewParams);
	virtual void __fastcall DrawScaledHeader(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &ABounds, TcxButtonState AState, TcxNeighbors ANeighbors, Cxgeometry::TcxBorders ABorders, Cxgeometry::TdxScaleFactor* AScaleFactor, bool AIsLast = false, bool AIsGroup = false)/* overload */;
	virtual void __fastcall DrawScaledHeader(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &ATextAreaBounds, TcxNeighbors ANeighbors, Cxgeometry::TcxBorders ABorders, TcxButtonState AState, System::Classes::TAlignment AAlignmentHorz, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AMultiLine, bool AShowEndEllipsis, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor, Cxgeometry::TdxScaleFactor* AScaleFactor, TcxDrawBackgroundEvent AOnDrawBackground = 0x0, bool AIsLast = false, bool AIsGroup = false, int ABorderWidth = 0x1)/* overload */;
	virtual void __fastcall DrawScaledHeaderEx(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &ATextAreaBounds, TcxNeighbors ANeighbors, Cxgeometry::TcxBorders ABorders, TcxButtonState AState, System::Classes::TAlignment AAlignmentHorz, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AMultiLine, bool AShowEndEllipsis, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor, Cxgeometry::TdxScaleFactor* AScaleFactor, TcxDrawBackgroundEvent AOnDrawBackground = 0x0)/* overload */;
	virtual void __fastcall DrawScaledHeaderControlSection(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &ATextAreaBounds, TcxNeighbors ANeighbors, Cxgeometry::TcxBorders ABorders, TcxButtonState AState, System::Classes::TAlignment AAlignmentHorz, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AMultiLine, bool AShowEndEllipsis, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual Cxgeometry::TcxBorders __fastcall HeaderBorders(TcxNeighbors ANeighbors);
	virtual int __fastcall HeaderBorderSize();
	virtual System::Types::TRect __fastcall HeaderBounds(const System::Types::TRect &ABounds, TcxNeighbors ANeighbors, Cxgeometry::TcxBorders ABorders = (Cxgeometry::TcxBorders() << Cxgeometry::TcxBorder::bLeft << Cxgeometry::TcxBorder::bTop << Cxgeometry::TcxBorder::bRight << Cxgeometry::TcxBorder::bBottom ));
	System::Types::TRect __fastcall HeaderContentBounds(const System::Types::TRect &ABounds, Cxgeometry::TcxBorders ABorders);
	virtual System::Types::TRect __fastcall HeaderContentOffsets(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual int __fastcall HeaderControlSectionBorderSize(TcxButtonState AState = (TcxButtonState)(0x1));
	virtual System::Types::TRect __fastcall HeaderControlSectionContentBounds(const System::Types::TRect &ABounds, TcxButtonState AState);
	virtual System::Types::TRect __fastcall HeaderControlSectionTextAreaBounds(const System::Types::TRect &ABounds, TcxButtonState AState);
	virtual bool __fastcall HeaderDrawCellsFirst();
	virtual Dxcoregraphics::_di_IdxColorPalette __fastcall HeaderGlyphColorPalette(TcxButtonState AState);
	int __fastcall HeaderHeight(int AFontHeight);
	int __fastcall HeaderWidth(Cxgraphics::TcxCanvas* ACanvas, Cxgeometry::TcxBorders ABorders, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont);
	virtual bool __fastcall IsHeaderHotTrack();
	virtual System::Types::TRect __fastcall ScaledHeaderContentBounds(const System::Types::TRect &ABounds, Cxgeometry::TcxBorders ABorders, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual int __fastcall ScaledHeaderHeight(int AFontHeight, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual int __fastcall ScaledHeaderWidth(Cxgraphics::TcxCanvas* ACanvas, Cxgeometry::TcxBorders ABorders, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledSortingMark(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AAscendingSorting, Cxgeometry::TdxScaleFactor* AScaleFactor) = 0 ;
	virtual void __fastcall DrawScaledSummarySortingMark(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AAscendingSorting, Cxgeometry::TdxScaleFactor* AScaleFactor) = 0 ;
	virtual void __fastcall DrawScaledSummaryValueSortingMark(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AAscendingSorting, Cxgeometry::TdxScaleFactor* AScaleFactor);
	void __fastcall DrawSortingMark(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AAscendingSorting);
	void __fastcall DrawSummarySortingMark(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AAscendingSorting);
	void __fastcall DrawSummaryValueSortingMark(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AAscendingSorting);
	System::Types::TPoint __fastcall SortingMarkAreaSize();
	System::Types::TPoint __fastcall SortingMarkSize();
	System::Types::TPoint __fastcall SummarySortingMarkSize();
	System::Types::TPoint __fastcall SummaryValueSortingMarkSize();
	virtual System::Types::TPoint __fastcall ScaledSortingMarkAreaSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TPoint __fastcall ScaledSortingMarkSize(Cxgeometry::TdxScaleFactor* AScaleFactor) = 0 ;
	virtual System::Types::TPoint __fastcall ScaledSummarySortingMarkSize(Cxgeometry::TdxScaleFactor* AScaleFactor) = 0 ;
	virtual System::Types::TPoint __fastcall ScaledSummaryValueSortingMarkSize(Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual void __fastcall DrawFilterRowSeparator(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, System::Uitypes::TColor ABackgroundColor);
	virtual void __fastcall DrawGroupByBox(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool ATransparent, System::Uitypes::TColor ABackgroundColor, Vcl::Graphics::TBitmap* const ABackgroundBitmap);
	virtual void __fastcall DrawScaledFindPanelNextButtonGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledFindPanelPreviousButtonGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledGroupByBoxSearchButtonGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	virtual int __fastcall GridBordersOverlapSize();
	virtual int __fastcall GridDefaultIndicatorWidth();
	virtual System::Uitypes::TColor __fastcall GridGroupRowStyleOffice11ContentColor(bool AHasData);
	virtual System::Uitypes::TColor __fastcall GridGroupRowStyleOffice11SeparatorColor();
	virtual System::Uitypes::TColor __fastcall GridGroupRowStyleOffice11TextColor();
	virtual bool __fastcall GridDrawHeaderCellsFirst();
	virtual bool __fastcall GridScaleGridLines();
	virtual bool __fastcall GridUseDiscreteScalingForGridLines();
	virtual System::Uitypes::TColor __fastcall PivotGridHeadersAreaColor();
	virtual System::Uitypes::TColor __fastcall PivotGridHeadersAreaTextColor();
	virtual System::Uitypes::TColor __fastcall GridLikeControlBackgroundColor();
	virtual System::Uitypes::TColor __fastcall GridLikeControlContentColor();
	virtual System::Uitypes::TColor __fastcall GridLikeControlContentEvenColor();
	virtual System::Uitypes::TColor __fastcall GridLikeControlContentOddColor();
	virtual System::Uitypes::TColor __fastcall GridLikeControlContentTextColor();
	virtual bool __fastcall GridLikeControlDefaultUseOddEvenStyle();
	virtual void __fastcall LayoutViewDrawItem(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, TcxButtonState AState, Cxgeometry::TcxBorders ABorders = Cxgeometry::TcxBorders() );
	virtual void __fastcall LayoutViewDrawRecordCaption(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &ATextRect, TcxGroupBoxCaptionPosition APosition, TcxButtonState AState, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000), Vcl::Graphics::TBitmap* const ABitmap = (Vcl::Graphics::TBitmap*)(0x0));
	virtual void __fastcall LayoutViewDrawRecordBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, TcxButtonState AState, Cxgeometry::TcxBorders ABorders = Cxgeometry::TcxBorders() );
	virtual void __fastcall LayoutViewDrawRecordContent(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, TcxGroupBoxCaptionPosition ACaptionPosition, TcxButtonState AState, Cxgeometry::TcxBorders ABorders = (Cxgeometry::TcxBorders() << Cxgeometry::TcxBorder::bLeft << Cxgeometry::TcxBorder::bTop << Cxgeometry::TcxBorder::bRight << Cxgeometry::TcxBorder::bBottom ));
	virtual void __fastcall LayoutViewDrawScaledRecordExpandButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, TcxButtonState AState, bool AExpanded, Cxgeometry::TdxScaleFactor* AScaleFactor);
	void __fastcall LayoutViewDrawRecordExpandButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, TcxButtonState AState, bool AExpanded);
	virtual System::Types::TRect __fastcall LayoutViewGetPadding(TcxLayoutElement AElement);
	virtual System::Types::TRect __fastcall LayoutViewGetSpacing(TcxLayoutElement AElement);
	virtual int __fastcall LayoutViewRecordCaptionTailSize(TcxGroupBoxCaptionPosition ACaptionPosition);
	virtual bool __fastcall LayoutViewRecordCaptionTextBold();
	virtual System::Uitypes::TColor __fastcall WinExplorerViewDefaultRecordColor(TcxButtonState AState);
	virtual void __fastcall WinExplorerViewDrawGroup(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, TcxButtonState AState, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000), Vcl::Graphics::TBitmap* const ABitmap = (Vcl::Graphics::TBitmap*)(0x0));
	virtual void __fastcall WinExplorerViewDrawGroupCaptionLine(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual void __fastcall WinExplorerViewDrawRecord(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, TcxButtonState AState, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000), Vcl::Graphics::TBitmap* const ABitmap = (Vcl::Graphics::TBitmap*)(0x0));
	void __fastcall WinExplorerViewDrawRecordExpandButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, TcxButtonState AState, bool AExpanded);
	virtual void __fastcall WinExplorerViewDrawScaledRecordExpandButton(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &ABounds, TcxButtonState AState, bool AExpanded, Cxgeometry::TdxScaleFactor* AScaleFactor);
	int __fastcall WinExplorerViewExpandButtonSize();
	virtual int __fastcall WinExplorerViewGroupCaptionLineHeight();
	virtual bool __fastcall WinExplorerViewGroupTextBold();
	virtual System::Uitypes::TColor __fastcall WinExplorerViewGroupTextColor(TcxButtonState AState);
	virtual System::Uitypes::TColor __fastcall WinExplorerViewRecordTextColor(TcxButtonState AState);
	virtual int __fastcall WinExplorerViewScaledExpandButtonSize(Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual int __fastcall ChartToolBoxDataLevelInfoBorderSize();
	virtual System::Uitypes::TColor __fastcall DefaultDataRowLayoutContentTextColor(TcxButtonState AState);
	void __fastcall DrawDataRowLayoutContent(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual void __fastcall DrawDataRowLayoutItem(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, TcxButtonState AState);
	void __fastcall DrawDataRowLayoutSelection(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, TcxButtonState AState);
	virtual Cxgeometry::TcxBorders __fastcall FooterBorders();
	virtual int __fastcall FooterBorderSize();
	virtual int __fastcall FooterCellBorderSize();
	virtual System::Types::TRect __fastcall FooterCellBordersSizeRect(const Cxgeometry::TcxBorders ABorders, Cxgeometry::TdxScaleFactor* AScaleFactor, Cxgeometry::TdxScaleFactor* ABordersScaleFactor);
	virtual System::Types::TRect __fastcall FooterCellContentBounds(const System::Types::TRect &ABounds)/* overload */;
	virtual System::Types::TRect __fastcall FooterCellContentBounds(const System::Types::TRect &ABounds, const Cxgeometry::TcxBorders ABorders, Cxgeometry::TdxScaleFactor* AScaleFactor, Cxgeometry::TdxScaleFactor* ABordersScaleFactor)/* overload */;
	virtual System::Types::TRect __fastcall FooterCellContentOffsets(const Cxgeometry::TcxBorders ABorders, bool AIncludeBorders, Cxgeometry::TdxScaleFactor* AScaleFactor, Cxgeometry::TdxScaleFactor* ABordersScaleFactor);
	virtual System::Types::TRect __fastcall FooterCellTextAreaBounds(const System::Types::TRect &ABounds)/* overload */;
	virtual System::Types::TRect __fastcall FooterCellTextAreaBounds(const System::Types::TRect &ABounds, const Cxgeometry::TcxBorders ABorders, Cxgeometry::TdxScaleFactor* APaddingsScaleFactor, Cxgeometry::TdxScaleFactor* ABordersScaleFactor)/* overload */;
	virtual System::Types::TRect __fastcall FooterCellTextOffsets(Cxgeometry::TcxBorders ACellBorders, Cxgeometry::TdxScaleFactor* APaddingsScaleFactor, Cxgeometry::TdxScaleFactor* ABordersScaleFactor);
	virtual bool __fastcall FooterDrawCellsFirst();
	virtual System::Types::TRect __fastcall FooterPanelBordersSizeRect(const Cxgeometry::TcxBorders ABorders, Cxgeometry::TdxScaleFactor* AScaleFactor, Cxgeometry::TdxScaleFactor* ABordersScaleFactor);
	virtual System::Types::TRect __fastcall FooterPanelContentOffsets(const Cxgeometry::TcxBorders ABorders, bool AIncludeBorders, Cxgeometry::TdxScaleFactor* AScaleFactor, Cxgeometry::TdxScaleFactor* ABordersScaleFactor);
	virtual System::Uitypes::TColor __fastcall FooterSeparatorColor();
	virtual int __fastcall FooterSeparatorSize();
	void __fastcall DrawFooterPanel(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const Cxgraphics::TcxViewParams &AViewParams, Cxgeometry::TcxBorders ABorders)/* overload */;
	void __fastcall DrawFooterPanel(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const Cxgraphics::TcxViewParams &AViewParams, const Cxgeometry::TcxBorders ABorders, Cxgeometry::TdxScaleFactor* AScaleFactor, Cxgeometry::TdxScaleFactor* ABordersScaleFactor)/* overload */;
	virtual void __fastcall DrawFooterCell(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, System::Classes::TAlignment AAlignmentHorz, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AMultiLine, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor, TcxDrawBackgroundEvent AOnDrawBackground = 0x0)/* overload */;
	virtual void __fastcall DrawFooterCell(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, System::Classes::TAlignment AAlignmentHorz, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AMultiLine, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor, TcxDrawBackgroundEvent AOnDrawBackground, const Cxgeometry::TcxBorders ABorders, Cxgeometry::TdxScaleFactor* APaddingsScaleFactor, Cxgeometry::TdxScaleFactor* ABordersScaleFactor)/* overload */;
	virtual void __fastcall DrawFooterCellContent(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, System::Classes::TAlignment AAlignmentHorz, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AMultiLine, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor, TcxDrawBackgroundEvent AOnDrawBackground = 0x0)/* overload */;
	virtual void __fastcall DrawFooterCellContent(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, System::Classes::TAlignment AAlignmentHorz, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AMultiLine, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor, TcxDrawBackgroundEvent AOnDrawBackground, const Cxgeometry::TcxBorders ABorders, Cxgeometry::TdxScaleFactor* APaddingsScaleFactor, Cxgeometry::TdxScaleFactor* ABordersScaleFactor)/* overload */;
	virtual void __fastcall DrawFooterBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R)/* overload */;
	virtual void __fastcall DrawFooterBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, const Cxgeometry::TcxBorders ABorders, Cxgeometry::TdxScaleFactor* AScaleFactor, Cxgeometry::TdxScaleFactor* ABordersScaleFactor)/* overload */;
	virtual void __fastcall DrawFooterBorderEx(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgeometry::TcxBorders ABorders, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawFooterCellBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R)/* overload */;
	virtual void __fastcall DrawFooterCellBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, const Cxgeometry::TcxBorders ABorders, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual void __fastcall DrawFooterContent(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const Cxgraphics::TcxViewParams &AViewParams)/* overload */;
	virtual void __fastcall DrawFooterContent(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const Cxgraphics::TcxViewParams &AViewParams, const Cxgeometry::TcxBorders ABorders, Cxgeometry::TdxScaleFactor* AScaleFactor, Cxgeometry::TdxScaleFactor* ABordersScaleFactor)/* overload */;
	virtual void __fastcall DrawFooterSeparator(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	void __fastcall DrawFilterActivateButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, bool AChecked);
	void __fastcall DrawFilterCloseButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState);
	void __fastcall DrawFilterDropDownButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, bool AIsFilterActive);
	virtual void __fastcall DrawFilterPanel(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool ATransparent, System::Uitypes::TColor ABackgroundColor, Vcl::Graphics::TGraphic* const ABackgroundBitmap)/* overload */;
	virtual void __fastcall DrawFilterPanel(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool ATransparent, System::Uitypes::TColor ABackgroundColor, Vcl::Graphics::TGraphic* const ABackgroundBitmap, const Cxgeometry::TcxBorders ABorders, Cxgeometry::TdxScaleFactor* AScaleFactor, Cxgeometry::TdxScaleFactor* ABordersScaleFactor)/* overload */;
	void __fastcall DrawFilterSmartTag(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxFilterSmartTagState AState, bool AIsFilterActive);
	virtual void __fastcall DrawScaledFilterActivateButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, bool AChecked, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual void __fastcall DrawScaledFilterCloseButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledFilterDropDownButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, bool AIsFilterActive, Cxgeometry::TdxScaleFactor* AScaleFactor) = 0 ;
	virtual void __fastcall DrawScaledFilterSmartTag(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxFilterSmartTagState AState, bool AIsFilterActive, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	System::Types::TPoint __fastcall FilterActivateButtonSize();
	System::Types::TPoint __fastcall FilterCloseButtonSize();
	virtual Dxcoregraphics::_di_IdxColorPalette __fastcall FilterControlMenuGetColorPalette();
	System::Types::TPoint __fastcall FilterDropDownButtonSize();
	System::Types::TSize __fastcall FilterSmartTagSize();
	virtual System::Types::TPoint __fastcall ScaledFilterActivateButtonSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TPoint __fastcall ScaledFilterCloseButtonSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TPoint __fastcall ScaledFilterDropDownButtonSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TSize __fastcall ScaledFilterSmartTagSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledFilterBoolOperatorBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledFilterControlAddButtonGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledFilterControlRemoveButtonGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledFilterItemCaptionBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledFilterOperatorBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledFilterPanelBrackets(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledFilterPanelRemoveButtonGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledFilterPanelRemovingArea(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledFilterValueBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall GetScaledFilterTokenParams(/* out */ TdxFilterTokenParams &AParams, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawFindPanel(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool ATransparent, System::Uitypes::TColor ABackgroundColor, Vcl::Graphics::TGraphic* const ABackgroundBitmap)/* overload */;
	virtual void __fastcall DrawFindPanel(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool ATransparent, System::Uitypes::TColor ABackgroundColor, Vcl::Graphics::TGraphic* const ABackgroundBitmap, const Cxgeometry::TcxBorders ABorders, Cxgeometry::TdxScaleFactor* AScaleFactor, Cxgeometry::TdxScaleFactor* ABordersScaleFactor)/* overload */;
	virtual void __fastcall DrawFindPanelBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgeometry::TcxBorders ABorders, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual void __fastcall DrawFindPanelBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, const Cxgeometry::TcxBorders ABorders, Cxgeometry::TdxScaleFactor* AScaleFactor, Cxgeometry::TdxScaleFactor* ABordersScaleFactor)/* overload */;
	virtual System::Uitypes::TColor __fastcall GetWindowContentTextColor();
	virtual void __fastcall DrawWindowContent(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall DrawEditPopupWindowBorder(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, TcxEditPopupBorderStyle ABorderStyle, bool AClientEdge);
	virtual int __fastcall GetEditPopupWindowBorderWidth(TcxEditPopupBorderStyle AStyle);
	virtual int __fastcall GetEditPopupWindowClientEdgeWidth(TcxEditPopupBorderStyle AStyle);
	virtual TcxPopupBorderStyle __fastcall PopupBorderStyle();
	virtual System::Uitypes::TColor __fastcall GetHintBorderColor();
	virtual void __fastcall DrawHintBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	virtual Dxcoregraphics::_di_IdxColorPalette __fastcall ScreenTipGetColorPalette();
	virtual System::Uitypes::TColor __fastcall ScreenTipGetDescriptionTextColor();
	virtual int __fastcall ScreenTipGetFooterLineSize();
	virtual System::Uitypes::TColor __fastcall ScreenTipGetTitleTextColor();
	virtual System::Types::TRect __fastcall ScreenTipGetWindowPadding();
	virtual System::Types::TRect __fastcall ScreenTipGetHeaderPadding();
	virtual System::Types::TRect __fastcall ScreenTipGetDescriptionPadding();
	virtual System::Types::TRect __fastcall ScreenTipGetSeparatorPadding();
	virtual System::Types::TRect __fastcall ScreenTipGetFooterPadding();
	virtual void __fastcall ScreenTipDrawBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall ScreenTipDrawFooterLine(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall DrawTab(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgeometry::TcxBorders ABorders, const System::UnicodeString AText, TcxButtonState AState, bool AVertical, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor, bool AShowPrefix = false);
	virtual void __fastcall DrawTabBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgeometry::TcxBorder ABorder, Cxgeometry::TcxBorders ABorders, bool AVertical);
	virtual void __fastcall DrawTabsRoot(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgeometry::TcxBorders ABorders, bool AVertical);
	virtual bool __fastcall IsDrawTabImplemented(bool AVertical);
	virtual bool __fastcall IsTabHotTrack(bool AVertical);
	virtual int __fastcall TabBorderSize(bool AVertical);
	void __fastcall DrawIndicatorCustomizationMark(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor AColor);
	void __fastcall DrawIndicatorImage(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxIndicatorKind AKind);
	void __fastcall DrawIndicatorItem(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, const System::Types::TRect &AImageAreaBounds, TcxIndicatorKind AKind, System::Uitypes::TColor AColor, TcxDrawBackgroundEvent AOnDrawBackground = 0x0)/* overload */;
	void __fastcall DrawIndicatorItem(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxIndicatorKind AKind, System::Uitypes::TColor AColor, TcxDrawBackgroundEvent AOnDrawBackground = 0x0)/* overload */;
	void __fastcall DrawIndicatorItemEx(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxIndicatorKind AKind, System::Uitypes::TColor AColor, TcxDrawBackgroundEvent AOnDrawBackground = 0x0);
	virtual void __fastcall DrawScaledIndicatorImage(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxIndicatorKind AKind, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledIndicatorItem(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, const System::Types::TRect &AImageAreaBounds, TcxIndicatorKind AKind, System::Uitypes::TColor AColor, Cxgeometry::TdxScaleFactor* AScaleFactor, TcxDrawBackgroundEvent AOnDrawBackground, TcxNeighbors ANeighbors, bool APaintLeftSide, int ABorderWidth = 0x1)/* overload */;
	virtual void __fastcall DrawScaledIndicatorItem(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, const System::Types::TRect &AImageAreaBounds, TcxIndicatorKind AKind, System::Uitypes::TColor AColor, Cxgeometry::TdxScaleFactor* AScaleFactor, TcxDrawBackgroundEvent AOnDrawBackground = 0x0, TcxNeighbors ANeighbors = (TcxNeighbors() << TcxNeighbor::nTop << TcxNeighbor::nBottom ), int ABorderWidth = 0x1)/* overload */;
	virtual void __fastcall DrawScaledIndicatorItem(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxIndicatorKind AKind, System::Uitypes::TColor AColor, Cxgeometry::TdxScaleFactor* AScaleFactor, TcxDrawBackgroundEvent AOnDrawBackground = 0x0, int ABorderWidth = 0x1)/* overload */;
	virtual void __fastcall DrawScaledIndicatorItemEx(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxIndicatorKind AKind, System::Uitypes::TColor AColor, Cxgeometry::TdxScaleFactor* AScaleFactor, TcxDrawBackgroundEvent AOnDrawBackground = 0x0);
	virtual void __fastcall DrawScaledIndicatorCustomizationMark(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor AColor, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual bool __fastcall IndicatorDrawItemsFirst();
	void __fastcall DrawScrollBarBackground(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, bool AHorizontal);
	void __fastcall DrawScrollBarPart(Cxcustomcanvas::TcxCustomCanvas* ACanvas, bool AHorizontal, const System::Types::TRect &R, TcxScrollBarPart APart, TcxButtonState AState);
	void __fastcall DrawScrollBarSplitter(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState);
	virtual void __fastcall DrawScaledScrollBarBackground(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, bool AHorizontal, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledScrollBarPart(Cxcustomcanvas::TcxCustomCanvas* ACanvas, bool AHorizontal, const System::Types::TRect &R, TcxScrollBarPart APart, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledScrollBarSplitter(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual int __fastcall ScaledScrollBarMinimalThumbSize(bool AVertical, Cxgeometry::TdxScaleFactor* AScaleFactor);
	int __fastcall ScrollBarMinimalThumbSize(bool AVertical);
	int __fastcall PopupPanelSize();
	int __fastcall ScaledPopupPanelSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	void __fastcall CalculatePopupPanelClientRect(System::Types::TRect &AClientRect, System::Types::TRect &APanelRect, System::Types::TRect &AGripRect, System::Types::TRect &ACloseButtonRect, Dxcore::TdxCorner ACorner, const System::Types::TRect &ABorders, const System::Types::TRect &APanelBorders, int APanelHeight = 0x0, bool AShowCloseButton = true, bool AShowGripSize = true);
	virtual void __fastcall CalculateScaledPopupPanelClientRect(System::Types::TRect &AClientRect, System::Types::TRect &APanelRect, System::Types::TRect &AGripRect, System::Types::TRect &ACloseButtonRect, Dxcore::TdxCorner ACorner, const System::Types::TRect &ABorders, const System::Types::TRect &APanelBorders, Cxgeometry::TdxScaleFactor* AScaleFactor, int APanelHeight = 0x0, bool AShowCloseButton = true, bool AShowGripSize = true);
	void __fastcall DrawPopupNCPanel(HWND AHandle, bool AMouseAboveCloseButton, bool ACloseButtonIsTracking, Dxcore::TdxCorner ACorner, const System::Types::TRect &ACloseButtonRect, const System::Types::TRect &AGripRect, System::Uitypes::TColor ABorderColor);
	void __fastcall DrawPopupPanelBand(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &AGripRect, const System::Types::TRect &ACloseButtonRect, Dxcore::TdxCorner AGripCorner, TcxButtonState ACloseButtonState, const System::Types::TRect &ABorders, System::Uitypes::TColor ABorderColor, bool AShowGripSize = true, bool AShowCloseButton = true);
	void __fastcall DrawScaledPopupPanelBand(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &AGripRect, const System::Types::TRect &ACloseButtonRect, Dxcore::TdxCorner AGripCorner, TcxButtonState ACloseButtonState, const System::Types::TRect &ABorders, System::Uitypes::TColor ABorderColor, Cxgeometry::TdxScaleFactor* AScaleFactor, bool AShowGripSize = true, bool AShowCloseButton = true);
	virtual void __fastcall DrawScaledPopupNCPanel(HWND AHandle, bool AMouseAboveCloseButton, bool ACloseButtonIsTracking, Dxcore::TdxCorner ACorner, const System::Types::TRect &ACloseButtonRect, const System::Types::TRect &AGripRect, System::Uitypes::TColor ABorderColor, Cxgeometry::TdxScaleFactor* AScaleFactor);
	void __fastcall DoDrawSizeGrip(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect)/* overload */;
	virtual void __fastcall DoDrawSizeGrip(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual void __fastcall DrawSizeGrip(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, System::Uitypes::TColor ABackgroundColor = (System::Uitypes::TColor)(0x20000000), Dxcore::TdxCorner ACorner = (Dxcore::TdxCorner)(0x3));
	virtual void __fastcall DrawScaledSizeGrip(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxgeometry::TdxScaleFactor* AScaleFactor, System::Uitypes::TColor ABackgroundColor = (System::Uitypes::TColor)(0x20000000), Dxcore::TdxCorner ACorner = (Dxcore::TdxCorner)(0x3));
	virtual System::Types::TSize __fastcall ScaledSizeGripSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	System::Types::TSize __fastcall SizeGripSize();
	virtual System::Types::TSize __fastcall ScaledSliderButtonSize(Cxgraphics::TcxArrowDirection ADirection, Cxgeometry::TdxScaleFactor* AScaleFactor);
	System::Types::TSize __fastcall SliderButtonSize(Cxgraphics::TcxArrowDirection ADirection);
	void __fastcall DrawSliderButton(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &ARect, Cxgraphics::TcxArrowDirection ADirection, TcxButtonState AState);
	virtual void __fastcall DrawScaledSliderButton(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &ARect, Cxgraphics::TcxArrowDirection ADirection, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TSize __fastcall DoGetSmallCloseButtonSize();
	void __fastcall DrawSmallButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState);
	void __fastcall DrawSmallCloseButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState);
	virtual void __fastcall DrawScaledSmallButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledSmallCloseButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual Dxcoregraphics::_di_IdxColorPalette __fastcall GetSmallButtonColorPalette(TcxButtonState AState);
	System::Types::TSize __fastcall SmallCloseButtonSize();
	virtual System::Types::TSize __fastcall ScaledSmallCloseButtonSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall CalculateSchedulerNavigationButtonRects(bool AIsNextButton, bool ACollapsed, const System::Types::TSize &APrevButtonTextSize, const System::Types::TSize &ANextButtonTextSize, System::Types::TRect &ABounds, /* out */ System::Types::TRect &ATextRect, /* out */ System::Types::TRect &AArrowRect, Cxgeometry::TdxScaleFactor* AScaleFactor, const bool AIsVertical = true)/* overload */;
	virtual void __fastcall CalculateSchedulerNavigationButtonRects(bool AIsNextButton, bool ACollapsed, const System::Types::TSize &APrevButtonTextSize, const System::Types::TSize &ANextButtonTextSize, System::Types::TRect &ABounds, /* out */ System::Types::TRect &ATextRect, /* out */ System::Types::TRect &AArrowRect, const bool AIsVertical = true)/* overload */;
	virtual void __fastcall DrawScaledMonthHeader(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::UnicodeString AText, TcxNeighbors ANeighbors, const Cxgraphics::TcxViewParams &AViewParams, Cxgraphics::TcxArrowDirections AArrows, int ASideWidth, Cxgeometry::TdxScaleFactor* AScaleFactor, TcxDrawBackgroundEvent AOnDrawBackground = 0x0);
	void __fastcall DrawMonthHeader(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::UnicodeString AText, TcxNeighbors ANeighbors, const Cxgraphics::TcxViewParams &AViewParams, Cxgraphics::TcxArrowDirections AArrows, int ASideWidth, TcxDrawBackgroundEvent AOnDrawBackground = 0x0);
	virtual void __fastcall DrawSchedulerBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DrawSchedulerDayHeader(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &ATextAreaBounds, TcxNeighbors ANeighbors, Cxgeometry::TcxBorders ABorders, TcxButtonState AState, System::Classes::TAlignment AAlignmentHorz, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AMultiLine, bool AShowEndEllipsis, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor, Cxgeometry::TdxScaleFactor* AScaleFactor, TcxDrawBackgroundEvent AOnDrawBackground = 0x0, bool AIsLast = false, bool AIsGroup = false);
	void __fastcall DrawSchedulerEventProgress(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &AProgress, const Cxgraphics::TcxViewParams &AViewParams, bool ATransparent);
	virtual void __fastcall DrawSchedulerScaledEventProgress(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &AProgress, const Cxgraphics::TcxViewParams &AViewParams, bool ATransparent, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawSchedulerGroup(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	virtual void __fastcall DrawSchedulerScaledGroupSeparator(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, System::Uitypes::TColor ABackgroundColor, Cxgeometry::TdxScaleFactor* AScaleFactor, TcxDrawBackgroundEvent AOnDrawBackground = 0x0);
	void __fastcall DrawSchedulerGroupSeparator(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, System::Uitypes::TColor ABackgroundColor, TcxDrawBackgroundEvent AOnDrawBackground = 0x0);
	virtual void __fastcall DrawSchedulerMilestone(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DrawSchedulerNavigationButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool AIsNextButton, TcxButtonState AState, const System::UnicodeString AText, const System::Types::TRect &ATextRect, const System::Types::TRect &AArrowRect, const bool AIsVertical = true);
	virtual void __fastcall DrawSchedulerNavigationButtonArrow(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool AIsNextButton, System::Uitypes::TColor AColor, const bool AForVertical);
	virtual void __fastcall DrawSchedulerScaledNavigatorButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	void __fastcall DrawSchedulerNavigatorButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState);
	virtual void __fastcall DrawSchedulerSplitterBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, const Cxgraphics::TcxViewParams &AViewParams, bool AIsHorizontal);
	virtual void __fastcall DrawSchedulerTaskExpandButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AExpanded, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TRect __fastcall SchedulerEventProgressOffsets();
	Cxgeometry::TcxBorders __fastcall SchedulerHeaderBorders(TcxNeighbors ANeighbors);
	virtual System::Uitypes::TColor __fastcall SchedulerNavigationButtonTextColor(bool AIsNextButton, TcxButtonState AState, System::Uitypes::TColor ADefaultColor = (System::Uitypes::TColor)(0x20000000));
	virtual void __fastcall SchedulerNavigationButtonSizes(bool AIsNextButton, System::Types::TRect &ABorders, System::Types::TSize &AArrowSize, bool &AHasTextArea, Cxgeometry::TdxScaleFactor* AScaleFactor, const bool AIsVertical = true)/* overload */;
	virtual void __fastcall SchedulerNavigationButtonSizes(bool AIsNextButton, System::Types::TRect &ABorders, System::Types::TSize &AArrowSize, bool &AHasTextArea, const bool AIsVertical = true)/* overload */;
	virtual System::Types::TSize __fastcall SchedulerTaskExpandButtonSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	void __fastcall DrawEditorButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TcxEditBtnKind AButtonKind, TcxButtonState AState, TcxEditBtnPosition APosition = (TcxEditBtnPosition)(0x1));
	void __fastcall DrawEditorButtonGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TcxEditBtnKind AButtonKind, TcxButtonState AState, TcxEditBtnPosition APosition = (TcxEditBtnPosition)(0x1));
	virtual void __fastcall DrawScaledEditorButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TcxEditBtnKind AButtonKind, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor, TcxEditBtnPosition APosition = (TcxEditBtnPosition)(0x1));
	virtual void __fastcall DrawScaledEditorButtonGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TcxEditBtnKind AButtonKind, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor, TcxEditBtnPosition APosition = (TcxEditBtnPosition)(0x1));
	virtual Dxcoregraphics::_di_IdxColorPalette __fastcall EditButtonColorPalette(TcxButtonState AState);
	virtual System::Types::TSize __fastcall EditButtonSize();
	virtual System::Uitypes::TColor __fastcall EditButtonTextColor(TcxButtonState AState = (TcxButtonState)(0x1));
	virtual int __fastcall EditButtonTextOffset();
	virtual System::Uitypes::TColor __fastcall GetContainerBorderColor(bool AIsHighlightBorder);
	virtual int __fastcall GetContainerBorderWidth(TcxContainerBorderStyle ABorderStyle);
	System::Types::TSize __fastcall ClockSize();
	void __fastcall DrawClock(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, System::TDateTime ADateTime, System::Uitypes::TColor ABackgroundColor);
	virtual void __fastcall DrawScaledClock(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, System::TDateTime ADateTime, System::Uitypes::TColor ABackgroundColor, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual System::Types::TSize __fastcall ScaledClockSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledZoomInButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledZoomOutButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	void __fastcall DrawZoomInButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState);
	void __fastcall DrawZoomOutButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState);
	virtual System::Types::TSize __fastcall GetScaledZoomInButtonSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TSize __fastcall GetScaledZoomOutButtonSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	System::Types::TSize __fastcall GetZoomInButtonSize();
	System::Types::TSize __fastcall GetZoomOutButtonSize();
	System::Types::TSize __fastcall GetBackButtonSize();
	virtual System::Types::TSize __fastcall GetScaledBackButtonSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	void __fastcall DrawBackButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState);
	virtual void __fastcall DrawScaledBackButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawDateNavigatorCellSelection(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor AColor);
	virtual void __fastcall DrawDateNavigatorDateHeader(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R);
	virtual void __fastcall DrawDateNavigatorTodayCellSelection(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DrawNavigatorBorder(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, bool ASelected);
	virtual void __fastcall DrawNavigatorScaledButton(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, System::Uitypes::TColor ABackgroundColor, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	void __fastcall DrawNavigatorButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, System::Uitypes::TColor ABackgroundColor);
	void __fastcall DrawNavigatorButtonGlyph(Cxgraphics::TcxCanvas* ACanvas, Vcl::Imglist::TCustomImageList* AImageList, System::Uitypes::TImageIndex AImageIndex, const System::Types::TRect &AGlyphRect, bool AEnabled, bool AUserGlyphs);
	virtual void __fastcall DrawNavigatorScaledButtonGlyph(Cxgraphics::TcxCanvas* ACanvas, Vcl::Imglist::TCustomImageList* AImageList, System::Uitypes::TImageIndex AImageIndex, const System::Types::TRect &AGlyphRect, bool AEnabled, bool AUserGlyphs, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual void __fastcall DrawNavigatorInfoPanel(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, const Cxgraphics::TcxViewParams &AViewParams);
	virtual bool __fastcall NavigatorBorderOverlap();
	virtual int __fastcall NavigatorBorderSize();
	virtual Dxcoregraphics::_di_IdxColorPalette __fastcall NavigatorButtonColorPalette(bool AEnabled);
	System::Types::TRect __fastcall NavigatorButtonGlyphPadding();
	System::Types::TSize __fastcall NavigatorButtonGlyphSize();
	System::Types::TSize __fastcall NavigatorButtonMinSize();
	virtual System::Types::TPoint __fastcall NavigatorButtonPressedGlyphOffset();
	virtual System::Uitypes::TColor __fastcall NavigatorButtonTextColor(TcxButtonState AState);
	virtual System::Types::TRect __fastcall NavigatorScaledButtonGlyphPadding(Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual System::Types::TSize __fastcall NavigatorScaledButtonGlyphSize(Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual System::Types::TSize __fastcall NavigatorScaledButtonMinSize(Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual System::Types::TRect __fastcall NavigatorInfoPanelContentOffsets(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Uitypes::TColor __fastcall NavigatorInfoPanelTextColor();
	virtual void __fastcall DrawProgressBarPart(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &ABarBounds, bool AVertical, Cxgeometry::TdxScaleFactor* AScaleFactor, TcxProgressBarPart APart);
	void __fastcall DrawProgressBarText(Cxgraphics::TcxCanvas* ACanvas, const System::UnicodeString AText, const System::Types::TRect &ABounds, const System::Types::TRect &AProgressRect, const System::Types::TRect &AOverloadBarRect, const System::Types::TRect &APeakBarRect, const System::Uitypes::TColor ATextColor = (System::Uitypes::TColor)(0x20000000), bool AVertical = false);
	virtual System::Types::TRect __fastcall ProgressBarBorderSize(bool AVertical);
	virtual System::Uitypes::TColor __fastcall ProgressBarTextColor(TcxProgressBarPart APart = (TcxProgressBarPart)(0x0));
	virtual void __fastcall DrawGroupBoxBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &ARect);
	virtual void __fastcall DrawGroupBoxCaption(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ACaptionRect, const System::Types::TRect &ATextRect, TcxGroupBoxCaptionPosition ACaptionPosition);
	virtual void __fastcall DrawGroupBoxScaledCaption(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ACaptionRect, const System::Types::TRect &ATextRect, TcxGroupBoxCaptionPosition ACaptionPosition, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawGroupBoxContent(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABorderRect, TcxGroupBoxCaptionPosition ACaptionPosition, Cxgeometry::TcxBorders ABorders = (Cxgeometry::TcxBorders() << Cxgeometry::TcxBorder::bLeft << Cxgeometry::TcxBorder::bTop << Cxgeometry::TcxBorder::bRight << Cxgeometry::TcxBorder::bBottom ));
	virtual void __fastcall DrawGroupBoxScaledContent(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABorderRect, TcxGroupBoxCaptionPosition ACaptionPosition, Cxgeometry::TdxScaleFactor* AScaleFactor, Cxgeometry::TcxBorders ABorders = (Cxgeometry::TcxBorders() << Cxgeometry::TcxBorder::bLeft << Cxgeometry::TcxBorder::bTop << Cxgeometry::TcxBorder::bRight << Cxgeometry::TcxBorder::bBottom ));
	virtual void __fastcall DrawGroupBoxScaledExpandButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, bool AExpanded, Cxgeometry::TdxScaleFactor* AScaleFactor, Cxcustomcanvas::TcxRotationAngle ARotationAngle = (Cxcustomcanvas::TcxRotationAngle)(0x0))/* overload */;
	void __fastcall DrawGroupBoxExpandButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, bool AExpanded, Cxcustomcanvas::TcxRotationAngle ARotationAngle = (Cxcustomcanvas::TcxRotationAngle)(0x0));
	virtual void __fastcall DrawGroupBoxScaledButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	void __fastcall DrawGroupBoxButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState);
	virtual void __fastcall DrawGroupBoxScaledExpandGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, bool AExpanded, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	void __fastcall DrawGroupBoxExpandGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, bool AExpanded);
	virtual void __fastcall DrawGroupBoxScaledFrame(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AEnabled, TcxGroupBoxCaptionPosition ACaptionPosition, Cxgeometry::TdxScaleFactor* AScaleFactor, Cxgeometry::TcxBorders ABorders = (Cxgeometry::TcxBorders() << Cxgeometry::TcxBorder::bLeft << Cxgeometry::TcxBorder::bTop << Cxgeometry::TcxBorder::bRight << Cxgeometry::TcxBorder::bBottom ))/* overload */;
	virtual void __fastcall DrawGroupBoxFrame(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AEnabled, TcxGroupBoxCaptionPosition ACaptionPosition, Cxgeometry::TcxBorders ABorders = (Cxgeometry::TcxBorders() << Cxgeometry::TcxBorder::bLeft << Cxgeometry::TcxBorder::bTop << Cxgeometry::TcxBorder::bRight << Cxgeometry::TcxBorder::bBottom ))/* overload */;
	virtual void __fastcall GroupBoxAdjustCaptionFont(Vcl::Graphics::TFont* ACaptionFont, TcxGroupBoxCaptionPosition ACaptionPosition);
	virtual System::Types::TRect __fastcall GroupBoxBorderSize(bool ACaption, TcxGroupBoxCaptionPosition ACaptionPosition);
	virtual int __fastcall GroupBoxCaptionTailSize(TcxGroupBoxCaptionPosition ACaptionPosition);
	virtual System::Uitypes::TColor __fastcall GroupBoxTextColor(bool AEnabled, TcxGroupBoxCaptionPosition ACaptionPosition);
	virtual bool __fastcall IsGroupBoxCaptionTextDrawnOverBorder(TcxGroupBoxCaptionPosition ACaptionPosition);
	virtual bool __fastcall IsGroupBoxTransparent(TcxGroupBoxCaptionPosition ACaptionPosition);
	virtual int __fastcall CheckBorderSize();
	System::Types::TSize __fastcall CheckButtonAreaSize();
	virtual System::Uitypes::TColor __fastcall CheckButtonColor(TcxButtonState AState, TcxCheckBoxState ACheckState);
	System::Types::TSize __fastcall CheckButtonSize();
	virtual System::Types::TSize __fastcall ScaledCheckButtonAreaSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TSize __fastcall ScaledCheckButtonSize(Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	void __fastcall DrawCheck(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, bool AChecked, System::Uitypes::TColor AColor)/* overload */;
	void __fastcall DrawCheck(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, TcxCheckBoxState ACheckState, System::Uitypes::TColor AColor)/* overload */;
	virtual void __fastcall DrawCheckBorder(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState);
	void __fastcall DrawCheckButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, bool AChecked)/* overload */;
	void __fastcall DrawCheckButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, TcxCheckBoxState ACheckState)/* overload */;
	virtual void __fastcall DrawScaledCheck(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, bool AChecked, System::Uitypes::TColor AColor, Cxgeometry::TdxScaleFactor* AScaleFactor, bool ADrawBackground)/* overload */;
	virtual void __fastcall DrawScaledCheck(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, TcxCheckBoxState ACheckState, System::Uitypes::TColor AColor, Cxgeometry::TdxScaleFactor* AScaleFactor, bool ADrawBackground)/* overload */;
	void __fastcall DrawScaledCheck(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, TcxCheckBoxState ACheckState, System::Uitypes::TColor AColor, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	void __fastcall DrawScaledCheck(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, bool AChecked, System::Uitypes::TColor AColor, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual void __fastcall DrawScaledCheckButton(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, bool AChecked, Cxgeometry::TdxScaleFactor* AScaleFactor, bool ADrawBackground)/* overload */;
	virtual void __fastcall DrawScaledCheckButton(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, TcxCheckBoxState ACheckState, Cxgeometry::TdxScaleFactor* AScaleFactor, bool ADrawBackground)/* overload */;
	void __fastcall DrawScaledCheckButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, bool AChecked, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	void __fastcall DrawScaledCheckButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, TcxCheckBoxState ACheckState, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual void __fastcall DrawScaledToggleSwitch(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, TcxButtonState AState, const System::Types::TRect &AThumbBounds, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual void __fastcall DrawScaledToggleSwitch(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, TcxButtonState AState, bool AFocused, const System::Types::TRect &AThumbBounds, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual void __fastcall DrawScaledToggleSwitchState(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, TcxButtonState AState, bool AChecked, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual void __fastcall DrawScaledToggleSwitchState(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, TcxButtonState AState, bool AChecked, bool AFocused, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual void __fastcall DrawScaledToggleSwitchThumb(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual void __fastcall DrawScaledToggleSwitchThumb(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, TcxButtonState AState, bool AChecked, bool AFocused, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	void __fastcall DrawToggleSwitch(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, TcxButtonState AState, const System::Types::TRect &AThumbBounds);
	void __fastcall DrawToggleSwitchState(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, TcxButtonState AState, bool AChecked);
	virtual void __fastcall DrawToggleSwitchStateIndicator(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, System::UnicodeString AText, Vcl::Graphics::TFont* AFont);
	void __fastcall DrawToggleSwitchThumb(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, TcxButtonState AState);
	virtual Dxcoregraphics::_di_IdxColorPalette __fastcall GetToggleSwitchColorPalette();
	virtual System::Uitypes::TColor __fastcall GetToggleSwitchTextColor();
	virtual int __fastcall GetToggleSwitchThumbPercentsWidth();
	virtual System::Uitypes::TColor __fastcall ToggleSwitchToggleColor(bool AChecked);
	void __fastcall DrawRadioButton(Cxgraphics::TcxCanvas* ACanvas, int X, int Y, TcxButtonState AButtonState, bool AChecked, bool AFocused, System::Uitypes::TColor ABrushColor, bool AIsDesigning = false);
	virtual void __fastcall DrawScaledRadioButton(Cxgraphics::TcxCanvas* ACanvas, int X, int Y, TcxButtonState AButtonState, bool AChecked, bool AFocused, System::Uitypes::TColor ABrushColor, Cxgeometry::TdxScaleFactor* AScaleFactor, bool AIsDesigning = false)/* overload */;
	virtual System::Uitypes::TColor __fastcall RadioButtonBodyColor(TcxButtonState AState);
	System::Types::TSize __fastcall RadioButtonSize();
	virtual System::Types::TSize __fastcall ScaledRadioButtonSize(Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual void __fastcall DrawLabelLine(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor AOuterColor, System::Uitypes::TColor AInnerColor, bool AIsVertical);
	virtual int __fastcall LabelLineHeight();
	virtual System::Uitypes::TColor __fastcall GaugeControlBackgroundColor();
	virtual void __fastcall DrawGaugeControlBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool ATransparent, System::Uitypes::TColor ABackgroundColor);
	virtual System::Uitypes::TColor __fastcall MapControlBackgroundColor();
	virtual Dxcoregraphics::TdxAlphaColor __fastcall MapControlPanelBackColor();
	virtual Dxcoregraphics::TdxAlphaColor __fastcall MapControlPanelHotTrackedTextColor();
	virtual Dxcoregraphics::TdxAlphaColor __fastcall MapControlPanelPressedTextColor();
	virtual Dxcoregraphics::TdxAlphaColor __fastcall MapControlPanelTextColor();
	virtual System::Types::TSize __fastcall MapControlGetMapPushpinSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TPoint __fastcall MapControlGetMapPushpinTextOrigin(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TRect __fastcall MapControlMapCustomElementSelectionOffset(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual Dxcoregraphics::TdxAlphaColor __fastcall MapControlMapCustomElementTextColor();
	virtual Dxcoregraphics::TdxAlphaColor __fastcall MapControlMapCustomElementTextGlowColor();
	virtual Dxcoregraphics::TdxAlphaColor __fastcall MapControlMapPushpinTextColor();
	virtual Dxcoregraphics::TdxAlphaColor __fastcall MapControlMapPushpinTextGlowColor();
	virtual Dxcoregraphics::TdxAlphaColor __fastcall MapControlSelectedRegionBackgroundColor();
	virtual Dxcoregraphics::TdxAlphaColor __fastcall MapControlSelectedRegionBorderColor();
	virtual Dxcoregraphics::TdxAlphaColor __fastcall MapControlShapeColor();
	virtual Dxcoregraphics::TdxAlphaColor __fastcall MapControlShapeBorderColor();
	virtual int __fastcall MapControlShapeBorderWidth(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual Dxcoregraphics::TdxAlphaColor __fastcall MapControlShapeHighlightedColor();
	virtual Dxcoregraphics::TdxAlphaColor __fastcall MapControlShapeBorderHighlightedColor();
	virtual int __fastcall MapControlShapeBorderHighlightedWidth(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual Dxcoregraphics::TdxAlphaColor __fastcall MapControlShapeSelectedColor();
	virtual Dxcoregraphics::TdxAlphaColor __fastcall MapControlShapeBorderSelectedColor();
	virtual int __fastcall MapControlShapeBorderSelectedWidth(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawMapCustomElementBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TdxMapControlElementState AState);
	virtual void __fastcall DrawMapPushpin(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TdxMapControlElementState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	void __fastcall OfficeNavigationBarDrawCustomizationButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TcxCalendarElementState AState, Dxcoregraphics::TdxAlphaColor AColor = (Dxcoregraphics::TdxAlphaColor)(0x10203));
	virtual void __fastcall OfficeNavigationBarDrawBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	void __fastcall OfficeNavigationBarDrawImageSelection(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TcxCalendarElementState AState);
	void __fastcall OfficeNavigationBarButtonItemDrawBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TcxCalendarElementState AState);
	void __fastcall OfficeNavigationBarItemDrawBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TcxCalendarElementState AState);
	virtual void __fastcall OfficeNavigationBarDrawScaledButtonItemBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TcxCalendarElementState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall OfficeNavigationBarDrawScaledCustomizationButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TcxCalendarElementState AState, Cxgeometry::TdxScaleFactor* AScaleFactor, Dxcoregraphics::TdxAlphaColor AColor = (Dxcoregraphics::TdxAlphaColor)(0x10203));
	virtual void __fastcall OfficeNavigationBarDrawScaledItemBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TcxCalendarElementState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall OfficeNavigationBarDrawScaledImageSelection(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TcxCalendarElementState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	System::Types::TRect __fastcall OfficeNavigationBarButtonItemContentOffsets();
	int __fastcall OfficeNavigationBarButtonItemFontSize();
	virtual System::Uitypes::TColor __fastcall OfficeNavigationBarButtonItemTextColor(TcxCalendarElementState AState);
	System::Types::TRect __fastcall OfficeNavigationBarContentOffsets();
	System::Types::TSize __fastcall OfficeNavigationBarCustomizationButtonSize();
	System::Types::TRect __fastcall OfficeNavigationBarItemContentOffsets();
	int __fastcall OfficeNavigationBarItemFontSize();
	virtual System::Uitypes::TColor __fastcall OfficeNavigationBarItemTextColor(TcxCalendarElementState AState);
	virtual System::Types::TRect __fastcall OfficeNavigationBarScaledButtonItemContentOffsets(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual int __fastcall OfficeNavigationBarScaledButtonItemFontSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TRect __fastcall OfficeNavigationBarScaledContentOffsets(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TSize __fastcall OfficeNavigationBarScaledCustomizationButtonSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TRect __fastcall OfficeNavigationBarScaledItemContentOffsets(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual int __fastcall OfficeNavigationBarScaledItemFontSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual Dxcoregraphics::_di_IdxColorPalette __fastcall PDFViewerNavigationPaneButtonColorPalette(TcxButtonState AState);
	virtual System::Types::TRect __fastcall PDFViewerNavigationPaneButtonContentOffsets(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TPoint __fastcall PDFViewerNavigationPaneButtonOverlay(Cxgeometry::TdxScaleFactor* AScaleFactor);
	System::Types::TRect __fastcall PDFViewerNavigationPaneButtonRect(const System::Types::TRect &ARect, TcxButtonState AState, bool ASelected, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TSize __fastcall PDFViewerNavigationPaneButtonSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TRect __fastcall PDFViewerNavigationPaneContentOffsets(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TRect __fastcall PDFViewerNavigationPanePageCaptionContentOffsets(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Uitypes::TColor __fastcall PDFViewerNavigationPanePageCaptionTextColor();
	virtual System::Types::TRect __fastcall PDFViewerNavigationPanePageContentOffsets(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TRect __fastcall PDFViewerNavigationPanePageToolbarContentOffsets(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Uitypes::TColor __fastcall PDFViewerSelectionColor();
	virtual void __fastcall PDFViewerDrawNavigationPaneBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall PDFViewerDrawNavigationPaneButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor, bool AMinimized, bool ASelected, bool AIsFirst);
	virtual void __fastcall PDFViewerDrawNavigationPanePageBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall PDFViewerDrawNavigationPanePageButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall PDFViewerDrawNavigationPanePageCaptionBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall PDFViewerDrawNavigationPanePageToolbarBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall PDFViewerDrawFindPanelBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgeometry::TcxBorders ABorders);
	virtual void __fastcall PDFViewerDrawPageThumbnailPreviewBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	void __fastcall DrawSpreadSheetGroupExpandButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState);
	void __fastcall DrawSpreadSheetGroupExpandButtonGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, bool AExpanded, Vcl::Imglist::TCustomImageList* ADefaultGlyphs = (Vcl::Imglist::TCustomImageList*)(0x0));
	virtual void __fastcall DrawSpreadSheetScaledHeader(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, TcxNeighbors ANeighbors, Cxgeometry::TcxBorders ABorders, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawSpreadSheetScaledGroupExpandButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual void __fastcall DrawSpreadSheetScaledGroupExpandButtonGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, bool AExpanded, Cxgeometry::TdxScaleFactor* AScaleFactor, Vcl::Imglist::TCustomImageList* ADefaultGlyphs = (Vcl::Imglist::TCustomImageList*)(0x0))/* overload */;
	virtual System::Uitypes::TColor __fastcall SpreadSheetContentColor();
	virtual System::Uitypes::TColor __fastcall SpreadSheetContentTextColor();
	virtual System::Uitypes::TColor __fastcall SpreadSheetFrozenPaneSeparatorColor();
	System::Types::TRect __fastcall SpreadSheetGroupExpandButtonContentOffsets();
	System::Types::TSize __fastcall SpreadSheetGroupExpandButtonGlyphSize();
	virtual System::Uitypes::TColor __fastcall SpreadSheetGroupExpandButtonTextColor(TcxButtonState AState);
	System::Types::TSize __fastcall SpreadSheetGroupLevelMarkSize();
	virtual System::Uitypes::TColor __fastcall SpreadSheetGroupLineColor();
	virtual System::Types::TRect __fastcall SpreadSheetScaledGroupExpandButtonContentOffsets(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TSize __fastcall SpreadSheetScaledGroupExpandButtonGlyphSize(Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual System::Types::TSize __fastcall SpreadSheetScaledGroupLevelMarkSize(Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual System::Uitypes::TColor __fastcall SpreadSheetSelectionColor();
	virtual void __fastcall DrawSpreadSheetFormulaBarScaledExpandButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, bool AExpanded, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawSpreadSheetFormulaBarScaledSeparator(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual int __fastcall SpreadSheetFormulaBarGetScaledSeparatorSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawPanelBackground(Cxgraphics::TcxCanvas* ACanvas, Vcl::Controls::TWinControl* AControl, const System::Types::TRect &ABounds, System::Uitypes::TColor AColorFrom = (System::Uitypes::TColor)(0x20000000), System::Uitypes::TColor AColorTo = (System::Uitypes::TColor)(0x20000000));
	virtual void __fastcall DrawPanelBorders(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABorderRect);
	virtual void __fastcall DrawPanelScaledBorders(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABorderRect, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawPanelCaption(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ACaptionRect, TcxGroupBoxCaptionPosition ACaptionPosition);
	virtual void __fastcall DrawPanelContent(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &ARect, bool AIsRightToLeft = false);
	virtual System::Types::TRect __fastcall PanelBorderSize();
	virtual System::Uitypes::TColor __fastcall PanelTextColor();
	virtual void __fastcall CorrectThumbRect(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &ARect, bool AHorizontal, TcxTrackBarTicksAlign ATicks, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawTrackBarScaledTrack(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const System::Types::TRect &ASelection, bool AShowSelection, bool AEnabled, bool AHorizontal, System::Uitypes::TColor ATrackColor, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	void __fastcall DrawTrackBarTrack(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const System::Types::TRect &ASelection, bool AShowSelection, bool AEnabled, bool AHorizontal, System::Uitypes::TColor ATrackColor);
	virtual void __fastcall DrawTrackBarTrackBounds(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall DrawTrackBarScaledThumb(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TcxButtonState AState, bool AHorizontal, TcxTrackBarTicksAlign ATicks, System::Uitypes::TColor AThumbColor, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	void __fastcall DrawTrackBarThumb(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TcxButtonState AState, bool AHorizontal, TcxTrackBarTicksAlign ATicks, System::Uitypes::TColor AThumbColor);
	virtual void __fastcall DrawTrackBarThumbBorderUpDown(Cxgraphics::TcxCanvas* ACanvas, const Dxcore::TPoints ALightPolyLine, const Dxcore::TPoints AShadowPolyLine, const Dxcore::TPoints ADarkPolyLine);
	virtual void __fastcall DrawTrackBarThumbBorderBoth(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual System::Types::TSize __fastcall TrackBarScaledThumbSize(bool AHorizontal, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual int __fastcall TrackBarScaledTrackSize(Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	System::Types::TSize __fastcall TrackBarThumbSize(bool AHorizontal);
	virtual System::Uitypes::TColor __fastcall TrackBarTicksColor(bool AText);
	int __fastcall TrackBarTrackSize();
	virtual void __fastcall DrawRangeControlScaledLeftThumb(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, System::Uitypes::TColor AColor, Dxcoregraphics::TdxAlphaColor ABorderColor, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	void __fastcall DrawRangeControlLeftThumb(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, System::Uitypes::TColor AColor, Dxcoregraphics::TdxAlphaColor ABorderColor);
	virtual void __fastcall DrawRangeControlScaledRightThumb(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, System::Uitypes::TColor AColor, Dxcoregraphics::TdxAlphaColor ABorderColor, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	void __fastcall DrawRangeControlRightThumb(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, System::Uitypes::TColor AColor, Dxcoregraphics::TdxAlphaColor ABorderColor);
	virtual void __fastcall DrawRangeControlScaledRulerHeader(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool AIsHot, Dxcoregraphics::TdxAlphaColor AColor, Dxcoregraphics::TdxAlphaColor ABorderColor, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	void __fastcall DrawRangeControlRulerHeader(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool AIsHot, Dxcoregraphics::TdxAlphaColor AColor, Dxcoregraphics::TdxAlphaColor ABorderColor);
	virtual void __fastcall DrawRangeControlScaledSizingGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Dxcoregraphics::TdxAlphaColor ABorderColor, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	void __fastcall DrawRangeControlSizingGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Dxcoregraphics::TdxAlphaColor ABorderColor);
	virtual System::Uitypes::TColor __fastcall GetRangeControlBackColor();
	virtual System::Uitypes::TColor __fastcall GetRangeControlBorderColor();
	virtual System::Uitypes::TColor __fastcall GetRangeControlDefaultElementColor();
	virtual System::Uitypes::TColor __fastcall GetRangeControlElementForeColor();
	virtual Dxcoregraphics::TdxAlphaColor __fastcall GetRangeControlElementsBorderColor();
	virtual System::Uitypes::TColor __fastcall GetRangeControlLabelColor();
	virtual Dxcoregraphics::TdxAlphaColor __fastcall GetRangeControlOutOfRangeColor();
	virtual System::Uitypes::TColor __fastcall GetRangeControlRangePreviewColor();
	virtual Dxcoregraphics::TdxAlphaColor __fastcall GetRangeControlRulerColor();
	virtual int __fastcall GetRangeControlScaledScrollAreaHeight(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TSize __fastcall GetRangeControlScaledSizingGlyphSize(Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual System::Types::TSize __fastcall GetRangeControlScaledThumbSize(Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual System::Uitypes::TColor __fastcall GetRangeControlScrollAreaColor();
	int __fastcall GetRangeControlScrollAreaHeight();
	virtual Dxcoregraphics::TdxAlphaColor __fastcall GetRangeControlSelectedRegionBackgroundColor();
	virtual Dxcoregraphics::TdxAlphaColor __fastcall GetRangeControlSelectedRegionBorderColor();
	System::Types::TSize __fastcall GetRangeControlSizingGlyphSize();
	System::Types::TSize __fastcall GetRangeControlThumbSize();
	virtual System::Uitypes::TColor __fastcall GetRangeControlViewPortPreviewColor();
	System::Types::TSize __fastcall RangeTrackBarLeftThumbSize(bool AHorizontal, TcxTrackBarTicksAlign ATicks);
	System::Types::TSize __fastcall RangeTrackBarRightThumbSize(bool AHorizontal, TcxTrackBarTicksAlign ATicks);
	virtual System::Types::TSize __fastcall RangeTrackBarScaledLeftThumbSize(bool AHorizontal, TcxTrackBarTicksAlign ATicks, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TSize __fastcall RangeTrackBarScaledRightThumbSize(bool AHorizontal, TcxTrackBarTicksAlign ATicks, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawRangeTrackBarScaledLeftThumb(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TcxButtonState AState, bool AHorizontal, TcxTrackBarTicksAlign ATicks, System::Uitypes::TColor AThumbColor, Cxgeometry::TdxScaleFactor* AScaleFactor);
	void __fastcall DrawRangeTrackBarLeftThumb(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TcxButtonState AState, bool AHorizontal, TcxTrackBarTicksAlign ATicks, System::Uitypes::TColor AThumbColor);
	virtual void __fastcall DrawRangeTrackBarScaledRightThumb(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TcxButtonState AState, bool AHorizontal, TcxTrackBarTicksAlign ATicks, System::Uitypes::TColor AThumbColor, Cxgeometry::TdxScaleFactor* AScaleFactor);
	void __fastcall DrawRangeTrackBarRightThumb(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TcxButtonState AState, bool AHorizontal, TcxTrackBarTicksAlign ATicks, System::Uitypes::TColor AThumbColor);
	virtual System::Uitypes::TColor __fastcall GetSplitterInnerColor(bool AHighlighted);
	virtual System::Uitypes::TColor __fastcall GetSplitterOuterColor(bool AHighlighted);
	virtual void __fastcall DrawScaledSplitter(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &ARect, bool AHighlighted, bool AClicked, bool AHorizontal, Cxgeometry::TdxScaleFactor* AScaleFactor, bool AHasCloseMark = false, Cxgraphics::TcxArrowDirection AArrowDirection = (Cxgraphics::TcxArrowDirection)(0x2));
	void __fastcall DrawSplitter(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &ARect, bool AHighlighted, bool AClicked, bool AHorizontal);
	void __fastcall DrawSplitterCloseMark(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &ARect, bool AHighlighted, bool AClicked, bool AHorizontal, Cxgeometry::TdxScaleFactor* AScaleFactor, Cxgraphics::TcxArrowDirection AArrowDirection);
	virtual System::Types::TSize __fastcall GetScaledSplitterSize(bool AHorizontal, Cxgeometry::TdxScaleFactor* AScaleFactor);
	System::Types::TSize __fastcall GetSplitterSize(bool AHorizontal);
	bool __fastcall HasSplitterInnerLine(bool AHorizontal, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Uitypes::TColor __fastcall LayoutControlEmptyAreaColor();
	virtual Dxcoregraphics::_di_IdxColorPalette __fastcall LayoutControlGetColorPaletteForGroupButton(TcxButtonState AState);
	virtual Dxcoregraphics::_di_IdxColorPalette __fastcall LayoutControlGetColorPaletteForItemCaption();
	virtual Dxcoregraphics::_di_IdxColorPalette __fastcall LayoutControlGetColorPaletteForTabbedGroupCaption(bool AIsActive);
	virtual void __fastcall DrawLayoutControlBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DrawScrollBoxBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor AColor);
	virtual System::Uitypes::TColor __fastcall PrintPreviewBackgroundTextColor();
	System::Types::TRect __fastcall PrintPreviewPageBordersWidth();
	virtual System::Types::TRect __fastcall PrintPreviewPageBordersScaledWidth(Cxgeometry::TdxScaleFactor* AScaleFactor);
	void __fastcall DrawPrintPreviewBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DrawPrintPreviewScaledBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgeometry::TdxScaleFactor* AScaleFactor);
	void __fastcall DrawPrintPreviewPageBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABorderRect, const System::Types::TRect &AContentRect, bool ASelected, bool ADrawContent);
	virtual void __fastcall DrawPrintPreviewPageScaledBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABorderRect, const System::Types::TRect &AContentRect, bool ASelected, bool ADrawContent, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Uitypes::TColor __fastcall CalcEditButtonTextColor(TcxCalcButtonKind AButtonKind);
	virtual System::Uitypes::TColor __fastcall GetCustomizationFormListBackgroundColor();
	virtual void __fastcall DrawMessageBox(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::UnicodeString AMessage, Vcl::Graphics::TFont* AFont = (Vcl::Graphics::TFont*)(0x0), System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x1fffffff));
	virtual System::Uitypes::TColor __fastcall BreadcrumbEditBackgroundColor(TdxBreadcrumbEditState AState);
	virtual System::Types::TRect __fastcall BreadcrumbEditBordersSize();
	int __fastcall BreadcrumbEditButtonAreaSeparatorSize();
	virtual Dxcoregraphics::_di_IdxColorPalette __fastcall BreadcrumbEditButtonColorPalette(TdxBreadcrumbEditButtonState AState);
	System::Types::TRect __fastcall BreadcrumbEditButtonContentOffsets(bool AIsFirst, bool AIsLast);
	int __fastcall BreadcrumbEditDropDownButtonWidth();
	virtual bool __fastcall BreadcrumbEditIsFadingSupports();
	int __fastcall BreadcrumbEditNodeDelimiterSize();
	virtual System::Uitypes::TColor __fastcall BreadcrumbEditNodeTextColor(TdxBreadcrumbEditButtonState AState);
	System::Types::TRect __fastcall BreadcrumbEditNodeTextOffsets();
	System::Types::TSize __fastcall BreadcrumbEditProgressChunkOverlaySize();
	System::Types::TRect __fastcall BreadcrumbEditProgressChunkPadding();
	virtual System::Uitypes::TColor __fastcall BreadcrumbEditProgressChunkTextColor();
	virtual int __fastcall BreadcrumbEditScaledButtonAreaSeparatorSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TRect __fastcall BreadcrumbEditScaledButtonContentOffsets(bool AIsFirst, bool AIsLast, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual int __fastcall BreadcrumbEditScaledDropDownButtonWidth(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual int __fastcall BreadcrumbEditScaledNodeDelimiterSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TRect __fastcall BreadcrumbEditScaledNodeTextOffsets(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TSize __fastcall BreadcrumbEditScaledProgressChunkOverlaySize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TRect __fastcall BreadcrumbEditScaledProgressChunkPadding(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawBreadcrumbEditBorders(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxgeometry::TcxBorders ABorders, TdxBreadcrumbEditState AState);
	void __fastcall DrawBreadcrumbEditButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TdxBreadcrumbEditButtonState AState, bool AIsFirst, bool AIsLast);
	void __fastcall DrawBreadcrumbEditButtonAreaSeparator(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TdxBreadcrumbEditState AState);
	void __fastcall DrawBreadcrumbEditDropDownButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TdxBreadcrumbEditButtonState AState, bool AIsInEditor);
	void __fastcall DrawBreadcrumbEditDropDownButtonGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TdxBreadcrumbEditButtonState AState, bool AIsInEditor);
	void __fastcall DrawBreadcrumbEditNode(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TdxBreadcrumbEditButtonState AState, bool AHasDelimiter);
	void __fastcall DrawBreadcrumbEditNodeDelimiter(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TdxBreadcrumbEditButtonState AState);
	void __fastcall DrawBreadcrumbEditNodeDelimiterGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TdxBreadcrumbEditButtonState AState);
	void __fastcall DrawBreadcrumbEditNodeMoreButtonGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TdxBreadcrumbEditButtonState AState);
	void __fastcall DrawBreadcrumbEditProgressChunk(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	void __fastcall DrawBreadcrumbEditProgressChunkOverlay(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DrawBreadcrumbEditScaledButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TdxBreadcrumbEditButtonState AState, bool AIsFirst, bool AIsLast, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawBreadcrumbEditScaledButtonAreaSeparator(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TdxBreadcrumbEditState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawBreadcrumbEditScaledDropDownButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TdxBreadcrumbEditButtonState AState, bool AIsInEditor, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawBreadcrumbEditScaledDropDownButtonGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TdxBreadcrumbEditButtonState AState, bool AIsInEditor, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawBreadcrumbEditScaledNode(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TdxBreadcrumbEditButtonState AState, bool AHasDelimiter, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawBreadcrumbEditScaledNodeDelimiter(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TdxBreadcrumbEditButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawBreadcrumbEditScaledNodeDelimiterGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TdxBreadcrumbEditButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	virtual void __fastcall DrawBreadcrumbEditScaledNodeMoreButtonGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TdxBreadcrumbEditButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	virtual void __fastcall DrawBreadcrumbEditScaledProgressChunk(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawBreadcrumbEditScaledProgressChunkOverlay(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawDropDownListBoxBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool AHasBorders);
	void __fastcall DrawDropDownListBoxGutterBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall DrawDropDownListBoxScaledGutterBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawDropDownListBoxScaledSelection(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const System::Types::TRect &AGutterRect, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawDropDownListBoxScaledSeparator(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const System::Types::TRect &AGutterRect, Cxgeometry::TdxScaleFactor* AScaleFactor);
	void __fastcall DrawDropDownListBoxSelection(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const System::Types::TRect &AGutterRect);
	void __fastcall DrawDropDownListBoxSeparator(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const System::Types::TRect &AGutterRect);
	virtual int __fastcall DropDownListBoxBordersSize();
	System::Types::TRect __fastcall DropDownListBoxItemImageOffsets();
	virtual System::Uitypes::TColor __fastcall DropDownListBoxItemTextColor(bool ASelected);
	System::Types::TRect __fastcall DropDownListBoxItemTextOffsets();
	virtual System::Types::TRect __fastcall DropDownListBoxScaledItemImageOffsets(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TRect __fastcall DropDownListBoxScaledItemTextOffsets(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual int __fastcall DropDownListBoxScaledSeparatorSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	int __fastcall DropDownListBoxSeparatorSize();
	System::Types::TRect __fastcall AlertWindowButtonContentOffsets(TdxAlertWindowButtonKind AKind);
	virtual Dxcoregraphics::_di_IdxColorPalette __fastcall AlertWindowButtonGetColorPalette(TcxButtonState AState);
	System::Types::TSize __fastcall AlertWindowButtonGlyphSize(TdxAlertWindowButtonKind AKind);
	System::Types::TRect __fastcall AlertWindowContentOffsets();
	virtual int __fastcall AlertWindowCornerRadius();
	virtual System::Uitypes::TColor __fastcall AlertWindowNavigationPanelTextColor();
	virtual System::Types::TRect __fastcall AlertWindowScaledButtonContentOffsets(TdxAlertWindowButtonKind AKind, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TSize __fastcall AlertWindowScaledButtonGlyphSize(TdxAlertWindowButtonKind AKind, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TRect __fastcall AlertWindowScaledContentOffsets(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Uitypes::TColor __fastcall AlertWindowTextColor();
	virtual void __fastcall DrawAlertWindowBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, Cxgeometry::TdxScaleFactor* AScaleFactor = (Cxgeometry::TdxScaleFactor*)(0x0));
	virtual void __fastcall DrawAlertWindowScaledButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, TcxButtonState AState, TdxAlertWindowButtonKind AKind, Cxgeometry::TdxScaleFactor* AScaleFactor, bool ADown = false);
	void __fastcall DrawAlertWindowButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, TcxButtonState AState, TdxAlertWindowButtonKind AKind, bool ADown = false);
	virtual void __fastcall DrawAlertWindowNavigationPanel(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	System::Types::TRect __fastcall GetGalleryGroupHeaderContentOffsets();
	virtual System::Uitypes::TColor __fastcall GetGalleryGroupTextColor();
	virtual System::Uitypes::TColor __fastcall GetGalleryDropTargetSelectionColor();
	virtual System::Uitypes::TColor __fastcall GetGalleryItemCaptionTextColor(const TdxGalleryItemViewState &AState);
	virtual Dxcoregraphics::_di_IdxColorPalette __fastcall GetGalleryItemColorPalette(const TdxGalleryItemViewState &AState);
	virtual System::Uitypes::TColor __fastcall GetGalleryItemDescriptionTextColor(const TdxGalleryItemViewState &AState);
	virtual System::Uitypes::TColor __fastcall GetGalleryItemImageFrameColor();
	virtual System::Types::TRect __fastcall GetGalleryScaledGroupHeaderContentOffsets(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawGalleryBackground(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual void __fastcall DrawGalleryGroupHeader(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual bool __fastcall DrawGalleryItemSelectionFirst();
	virtual void __fastcall DrawGalleryItemSelection(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, const TdxGalleryItemViewState &AViewState);
	virtual void __fastcall DrawGalleryItemImageFrame(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R);
	virtual System::Uitypes::TColor __fastcall GetColorGalleryGlyphFrameColor();
	virtual void __fastcall DrawColorGalleryItemSelection(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, const TdxGalleryItemViewState &AViewState);
	virtual void __fastcall DrawBevelFrame(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, bool ABoxStyle);
	virtual void __fastcall DrawBevelLine(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, bool AIsVertical);
	virtual void __fastcall DrawBevelShape(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TdxBevelShape AShape, TdxBevelStyle AStyle);
	virtual System::Types::TSize __fastcall GetBevelMinimalShapeSize(TdxBevelShape AShape);
	virtual void __fastcall GetBevelShapeColors(/* out */ System::Uitypes::TColor &AColor1, /* out */ System::Uitypes::TColor &AColor2);
	virtual void __fastcall DrawCalendarDateCellSelection(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TcxCalendarElementStates AStates);
	virtual void __fastcall DrawModernCalendarArrow(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxgraphics::TcxArrowDirection ADirection, TcxCalendarElementState AState);
	virtual void __fastcall DrawModernCalendarClock(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, System::TDateTime ADateTime, System::Uitypes::TColor ABackgroundColor, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawModernCalendarDateCellSelection(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TcxCalendarElementStates AStates);
	virtual void __fastcall DrawModernCalendarDateHeaderSelection(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TcxCalendarElementStates AStates);
	virtual void __fastcall DrawModernCalendarHeaderSelection(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TcxCalendarElementStates AStates);
	virtual System::Uitypes::TColor __fastcall GetModernCalendarCellTextColor(TcxCalendarElementStates AStates);
	virtual System::Uitypes::TColor __fastcall GetModernCalendarDateHeaderTextColor(TcxCalendarElementStates AStates);
	virtual System::Uitypes::TColor __fastcall GetModernCalendarHeaderTextColor(TcxCalendarElementStates AStates);
	virtual System::Types::TRect __fastcall GetModernCalendarHeaderTextOffsets();
	virtual System::Uitypes::TColor __fastcall GetModernCalendarMarkedCellBorderColor();
	virtual System::Uitypes::TColor __fastcall GetModernCalendarSelectedTextColor();
	void __fastcall DrawModernClockHands(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, System::TDateTime ADateTime, System::Uitypes::TColor AColor);
	virtual void __fastcall DrawScaledModernCalendarArrow(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxgraphics::TcxArrowDirection ADirection, TcxCalendarElementState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledModernClockHands(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, System::TDateTime ADateTime, System::Uitypes::TColor AColor, Cxgeometry::TdxScaleFactor* AScaleFactor);
	void __fastcall DrawRatingControlIndicator(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, TdxRatingControlIndicatorState AState);
	virtual void __fastcall DrawRatingControlScaledIndicator(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, TdxRatingControlIndicatorState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual Dxcoregraphics::_di_IdxColorPalette __fastcall GetRatingControlIndicatorColorPalette(TdxRatingControlIndicatorState AState);
	System::Types::TSize __fastcall GetRatingControlIndicatorSize();
	virtual System::Types::TSize __fastcall GetRatingControlScaledIndicatorSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	void __fastcall DrawFixedGroupIndicator(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual void __fastcall DrawScaledFixedGroupIndicator(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, Cxgeometry::TdxScaleFactor* AScaleFactor);
	System::Types::TSize __fastcall GetFixedGroupIndicatorSize();
	virtual System::Types::TSize __fastcall GetScaledFixedGroupIndicatorSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Uitypes::TColor __fastcall GetWheelPickerBorderItemColor(TcxButtonState AState);
	virtual Dxcoregraphics::_di_IdxColorPalette __fastcall GetWheelPickerColorPalette(TcxButtonState AState);
	virtual System::Uitypes::TColor __fastcall GetWheelPickerFillItemColor(TcxButtonState AState);
	virtual void __fastcall DrawWheelPickerItem(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TcxButtonState AState);
	virtual void __fastcall DrawWheelPickerItemBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TcxButtonState AState);
	virtual void __fastcall DrawWheelPickerItemBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TcxButtonState AState);
	virtual System::Uitypes::TColor __fastcall RichEditControlHeaderFooterLineColor();
	virtual System::Uitypes::TColor __fastcall RichEditControlHeaderFooterMarkBackColor();
	virtual System::Uitypes::TColor __fastcall RichEditControlHeaderFooterMarkTextColor();
	virtual System::Uitypes::TColor __fastcall RichEditRulerControlColor();
	virtual System::Uitypes::TColor __fastcall RichEditRulerActiveAreaColor();
	virtual System::Uitypes::TColor __fastcall RichEditRulerDefaultTabColor();
	virtual System::Uitypes::TColor __fastcall RichEditRulerInactiveAreaColor();
	virtual System::Uitypes::TColor __fastcall RichEditRulerTabTypeToggleBorderColor();
	virtual System::Uitypes::TColor __fastcall RichEditRulerTextColor();
	virtual void __fastcall DrawScaledTokenBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledTokenCloseGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	void __fastcall DrawTokenBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState);
	void __fastcall DrawTokenCloseGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState);
	virtual System::Types::TSize __fastcall GetScaledTokenCloseGlyphSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TRect __fastcall GetScaledTokenContentOffsets(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TSize __fastcall GetScaledTokenDefaultGlyphSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	System::Types::TSize __fastcall GetTokenCloseGlyphSize();
	virtual Dxcoregraphics::_di_IdxColorPalette __fastcall GetTokenColorPalette(TcxButtonState AState);
	System::Types::TRect __fastcall GetTokenContentOffsets();
	System::Types::TSize __fastcall GetTokenDefaultGlyphSize();
	virtual System::Uitypes::TColor __fastcall GetTokenTextColor(TcxButtonState AState);
	virtual System::Uitypes::TColor __fastcall DefaultGanttCurrentDateGridLineColor();
	virtual System::Uitypes::TColor __fastcall DefaultGanttProjectStartGridLineColor();
	virtual System::Uitypes::TColor __fastcall DefaultGanttProjectFinishGridLineColor();
	virtual void __fastcall DoDrawGanttSummaryTaskProgress(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, Cxgeometry::TdxScaleFactor* AScaleFactor, const System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	virtual void __fastcall DoDrawGanttTaskProgress(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, const System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	virtual void __fastcall DrawGanttBaselineMilestone(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, Cxgeometry::TdxScaleFactor* AScaleFactor, const System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	virtual void __fastcall DrawGanttBaselineSummaryTask(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, Cxgeometry::TdxScaleFactor* AScaleFactor, const System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	virtual void __fastcall DrawGanttBaselineTask(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, const System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	virtual void __fastcall DrawGanttDependencyEditPoint(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, const TcxButtonState AState, const bool AIsLeft);
	virtual void __fastcall DrawGanttFocusedRow(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, const bool AIsActive = true);
	virtual void __fastcall DrawGanttSheetHeader(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &ABounds, TcxButtonState AState, TcxNeighbors ANeighbors, Cxgeometry::TcxBorders ABorders, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawGanttMilestone(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, Cxgeometry::TdxScaleFactor* AScaleFactor, const System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	virtual void __fastcall DrawGanttSummaryTask(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, Cxgeometry::TdxScaleFactor* AScaleFactor, const System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	void __fastcall DrawGanttSummaryTaskProgress(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &ATaskRect, const System::Types::TRect &AProgressRect, Cxgeometry::TdxScaleFactor* AScaleFactor, const System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	virtual void __fastcall DrawGanttTask(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, const System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	void __fastcall DrawGanttTaskProgress(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &ATaskRect, const System::Types::TRect &AProgressRect, const System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	virtual void __fastcall DrawGanttTaskTextLabel(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R);
	virtual System::Types::TSize __fastcall GetGanttDependencyEditPointSize(const bool AIsLeft);
	virtual System::Types::TSize __fastcall GetGanttBaselineMilestoneSize();
	virtual int __fastcall GetGanttBaselineSummaryTaskHeight();
	virtual int __fastcall GetGanttBaselineTaskHeight();
	virtual System::Uitypes::TColor __fastcall GetGanttMilestoneColor();
	virtual System::Types::TSize __fastcall GetGanttMilestoneSize();
	virtual int __fastcall GetGanttSummaryTaskHeight();
	virtual System::Uitypes::TColor __fastcall GetGanttSummaryTaskColor();
	virtual System::Uitypes::TColor __fastcall GetGanttTaskColor(bool AManualSchedule);
	virtual int __fastcall GetGanttTaskHeight();
	virtual int __fastcall GetGanttTaskTextLabelHeight();
	virtual int __fastcall GetGanttTaskTextLabelOffset();
	virtual bool __fastcall GetGanttTaskTextLabelTextBold();
	virtual System::Uitypes::TColor __fastcall GetGanttTaskTextLabelTextColor();
	virtual void __fastcall DrawListViewBackground(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &ABounds, bool AExplorerStyle, bool AEnabled);
	virtual void __fastcall DrawListViewCheckButton(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &ABounds, TcxButtonState AState, bool AChecked, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawListViewSortingMark(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, bool AAscendingSorting, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawListViewGroupExpandButton(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &ABounds, TcxButtonState AState, bool AExpanded, bool AExplorerStyle, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawListViewGroupHeaderBackground(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &ABounds, TdxListViewGroupHeaderStates AState, bool AExplorerStyle, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawListViewGroupHeaderLine(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual void __fastcall DrawListViewItemBackground(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &ABounds, TdxListViewItemStates AState, bool AExplorerStyle);
	virtual Dxcoregraphics::_di_IdxColorPalette __fastcall GetListViewColumnHeaderColorPalette(TcxButtonState AState);
	virtual System::Types::TPoint __fastcall GetListViewColumnHeaderSortingMarkSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TRect __fastcall GetListViewColumnHeaderContentOffsets(bool AExplorerStyle, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Uitypes::TColor __fastcall GetListViewColumnHeaderTextColor(TcxButtonState AState, bool AExplorerStyle);
	virtual int __fastcall GetListViewExpandButtonSize(Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual Dxcoregraphics::_di_IdxColorPalette __fastcall GetListViewGroupHeaderColorPalette(TdxListViewGroupHeaderStates AState);
	virtual System::Uitypes::TColor __fastcall GetListViewGroupTextColor(TdxListViewGroupTextKind AKind, TdxListViewGroupHeaderStates AState, bool AExplorerStyle);
	virtual Dxcoregraphics::_di_IdxColorPalette __fastcall GetListViewItemColorPalette(TdxListViewItemStates AState);
	virtual System::Types::TRect __fastcall GetListViewItemContentPadding();
	virtual System::Uitypes::TColor __fastcall GetListViewItemTextColor(TdxListViewItemStates AState, bool AExplorerStyle);
	virtual void __fastcall DrawTreeViewNodeBackground(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &ABounds, TdxTreeViewNodeStates AState);
	virtual System::Uitypes::TColor __fastcall GetTreeViewBackgroundColor(bool AEnabled);
	virtual Dxcoregraphics::_di_IdxColorPalette __fastcall GetTreeViewNodeColorPalette(TdxTreeViewNodeStates AState);
	virtual System::Uitypes::TColor __fastcall GetTreeViewNodeTextColor(TdxTreeViewNodeStates AState);
	virtual bool __fastcall TreeListScaleGridLines();
	virtual bool __fastcall TreeListUseDiscreteScalingForGridLines();
	virtual bool __fastcall ApplyEditorAdvancedMode();
	virtual bool __fastcall SupportsNativeFocusRect(Cxclasses::TdxClassesID AClassID = (Cxclasses::TdxClassesID)(0x0));
public:
	/* TObject.Create */ inline __fastcall TcxCustomLookAndFeelPainter() : System::Classes::TPersistent() { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCustomLookAndFeelPainterClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxStandardLookAndFeelPainter : public TcxCustomLookAndFeelPainter
{
	typedef TcxCustomLookAndFeelPainter inherited;
	
protected:
	virtual void __fastcall DoDrawScaledScrollBarPart(Cxcustomcanvas::TcxCustomCanvas* ACanvas, bool AHorizontal, const System::Types::TRect &R, TcxScrollBarPart APart, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual int __fastcall FooterContentOffset();
	
public:
	virtual System::UnicodeString __fastcall LookAndFeelName();
	virtual TcxLookAndFeelStyle __fastcall LookAndFeelStyle();
	virtual int __fastcall BorderSize();
	virtual void __fastcall DrawBorder(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, int AWidth = 0x1);
	virtual int __fastcall ButtonBorderSize(TcxButtonState AState = (TcxButtonState)(0x1));
	virtual int __fastcall ScaledButtonTextOffset(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual int __fastcall ScaledButtonTextShift(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawButtonBorder(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState);
	virtual void __fastcall DrawScaledGroupExpandButton(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, bool AExpanded, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual int __fastcall ScaledExpandButtonSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledExpandButton(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, bool AExpanded, Cxgeometry::TdxScaleFactor* AScaleFactor, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000), TcxExpandButtonState AState = (TcxExpandButtonState)(0x0))/* overload */;
	virtual bool __fastcall IsButtonHotTrack();
	virtual void __fastcall DrawCheckBorder(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState);
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerTimeRulerBorderColor();
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerTimeRulerTextColor();
	virtual void __fastcall DrawHeaderControlSectionBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgeometry::TcxBorders ABorders, TcxButtonState AState);
	virtual void __fastcall DrawScaledSortingMark(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AAscendingSorting, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledSummarySortingMark(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AAscendingSorting, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual int __fastcall HeaderBorderSize();
	virtual int __fastcall HeaderControlSectionBorderSize(TcxButtonState AState = (TcxButtonState)(0x1));
	virtual System::Types::TPoint __fastcall ScaledSortingMarkSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TPoint __fastcall ScaledSummarySortingMarkSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual int __fastcall FooterBorderSize();
	virtual int __fastcall FooterCellBorderSize();
	virtual int __fastcall FooterCellOffset();
	virtual void __fastcall DrawFooterBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, const Cxgeometry::TcxBorders ABorders, Cxgeometry::TdxScaleFactor* AScaleFactor, Cxgeometry::TdxScaleFactor* ABordersScaleFactor)/* overload */;
	virtual void __fastcall DrawFooterCellBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, const Cxgeometry::TcxBorders ABorders, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual void __fastcall DrawScaledFilterDropDownButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, bool AIsFilterActive, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawTabBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgeometry::TcxBorder ABorder, Cxgeometry::TcxBorders ABorders, bool AVertical);
	virtual void __fastcall DrawTabsRoot(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgeometry::TcxBorders ABorders, bool AVertical);
	virtual int __fastcall TabBorderSize(bool AVertical);
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerViewContentColor();
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerViewContentColorClassic();
	virtual void __fastcall DrawScaledMonthHeader(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::UnicodeString AText, TcxNeighbors ANeighbors, const Cxgraphics::TcxViewParams &AViewParams, Cxgraphics::TcxArrowDirections AArrows, int ASideWidth, Cxgeometry::TdxScaleFactor* AScaleFactor, TcxDrawBackgroundEvent AOnDrawBackground = 0x0);
	virtual void __fastcall DrawSchedulerSplitterBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, const Cxgraphics::TcxViewParams &AViewParams, bool AIsHorizontal);
	virtual void __fastcall DrawGroupBoxScaledFrame(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AEnabled, TcxGroupBoxCaptionPosition ACaptionPosition, Cxgeometry::TdxScaleFactor* AScaleFactor, Cxgeometry::TcxBorders ABorders = (Cxgeometry::TcxBorders() << Cxgeometry::TcxBorder::bLeft << Cxgeometry::TcxBorder::bTop << Cxgeometry::TcxBorder::bRight << Cxgeometry::TcxBorder::bBottom ))/* overload */;
	virtual void __fastcall DrawTrackBarTrackBounds(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall DrawTrackBarThumbBorderUpDown(Cxgraphics::TcxCanvas* ACanvas, const Dxcore::TPoints ALightPolyLine, const Dxcore::TPoints AShadowPolyLine, const Dxcore::TPoints ADarkPolyLine);
	virtual void __fastcall DrawTrackBarThumbBorderBoth(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall DrawBreadcrumbEditScaledButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TdxBreadcrumbEditButtonState AState, bool AIsFirst, bool AIsLast, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledToggleSwitchState(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, TcxButtonState AState, bool AChecked, bool AFocused, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual System::Uitypes::TColor __fastcall ToggleSwitchToggleColor(bool AChecked);
	virtual void __fastcall DrawFindPanelBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, const Cxgeometry::TcxBorders ABorders, Cxgeometry::TdxScaleFactor* AScaleFactor, Cxgeometry::TdxScaleFactor* ABordersScaleFactor)/* overload */;
	virtual void __fastcall DrawScaledTokenBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
public:
	/* TcxCustomLookAndFeelPainter.Destroy */ inline __fastcall virtual ~TcxStandardLookAndFeelPainter() { }
	
public:
	/* TObject.Create */ inline __fastcall TcxStandardLookAndFeelPainter() : TcxCustomLookAndFeelPainter() { }
	
	/* Hoisted overloads: */
	
public:
	inline void __fastcall  DrawScaledExpandButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AExpanded, Cxgeometry::TdxScaleFactor* AScaleFactor, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000), TcxExpandButtonState AState = (TcxExpandButtonState)(0x0)){ TcxCustomLookAndFeelPainter::DrawScaledExpandButton(ACanvas, R, AExpanded, AScaleFactor, AColor, AState); }
	inline void __fastcall  DrawFooterBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R){ TcxCustomLookAndFeelPainter::DrawFooterBorder(ACanvas, R); }
	inline void __fastcall  DrawFooterCellBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R){ TcxCustomLookAndFeelPainter::DrawFooterCellBorder(ACanvas, R); }
	inline void __fastcall  DrawScaledToggleSwitchState(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, TcxButtonState AState, bool AChecked, Cxgeometry::TdxScaleFactor* AScaleFactor){ TcxCustomLookAndFeelPainter::DrawScaledToggleSwitchState(ACanvas, ABounds, AState, AChecked, AScaleFactor); }
	inline void __fastcall  DrawFindPanelBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgeometry::TcxBorders ABorders, Cxgeometry::TdxScaleFactor* AScaleFactor){ TcxCustomLookAndFeelPainter::DrawFindPanelBorder(ACanvas, R, ABorders, AScaleFactor); }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFlatLookAndFeelPainter : public TcxCustomLookAndFeelPainter
{
	typedef TcxCustomLookAndFeelPainter inherited;
	
protected:
	virtual void __fastcall DoDrawScaledScrollBarPart(Cxcustomcanvas::TcxCustomCanvas* ACanvas, bool AHorizontal, const System::Types::TRect &R, TcxScrollBarPart APart, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual int __fastcall FooterContentOffset();
	
public:
	virtual System::UnicodeString __fastcall LookAndFeelName();
	virtual TcxLookAndFeelStyle __fastcall LookAndFeelStyle();
	virtual int __fastcall BorderSize();
	virtual int __fastcall SeparatorSize();
	virtual void __fastcall DrawBorder(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, int AWidth = 0x1);
	virtual int __fastcall ButtonBorderSize(TcxButtonState AState = (TcxButtonState)(0x1));
	virtual int __fastcall ScaledButtonTextOffset(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual int __fastcall ScaledButtonTextShift(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawButtonBorder(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState);
	virtual void __fastcall DrawScaledExpandButton(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, bool AExpanded, Cxgeometry::TdxScaleFactor* AScaleFactor, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000), TcxExpandButtonState AState = (TcxExpandButtonState)(0x0))/* overload */;
	virtual int __fastcall ScaledExpandButtonSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual bool __fastcall IsButtonHotTrack();
	virtual void __fastcall DrawCheckBorder(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState);
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerTimeRulerBorderColor();
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerTimeRulerTextColor();
	virtual void __fastcall DrawHeaderControlSectionBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgeometry::TcxBorders ABorders, TcxButtonState AState);
	virtual void __fastcall DrawScaledSortingMark(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AAscendingSorting, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledSummarySortingMark(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AAscendingSorting, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual int __fastcall HeaderBorderSize();
	virtual System::Types::TPoint __fastcall ScaledSortingMarkSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TPoint __fastcall ScaledSummarySortingMarkSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual int __fastcall FooterBorderSize();
	virtual int __fastcall FooterCellBorderSize();
	virtual int __fastcall FooterCellOffset();
	virtual void __fastcall DrawFooterBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, const Cxgeometry::TcxBorders ABorders, Cxgeometry::TdxScaleFactor* AScaleFactor, Cxgeometry::TdxScaleFactor* ABordersScaleFactor)/* overload */;
	virtual void __fastcall DrawFooterCellBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, const Cxgeometry::TcxBorders ABorders, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual void __fastcall DrawScaledFilterDropDownButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, bool AIsFilterActive, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawTabBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgeometry::TcxBorder ABorder, Cxgeometry::TcxBorders ABorders, bool AVertical);
	virtual void __fastcall DrawTabsRoot(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgeometry::TcxBorders ABorders, bool AVertical);
	virtual int __fastcall TabBorderSize(bool AVertical);
	virtual void __fastcall DrawSchedulerSplitterBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, const Cxgraphics::TcxViewParams &AViewParams, bool AIsHorizontal);
	virtual void __fastcall DrawGroupBoxScaledFrame(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AEnabled, TcxGroupBoxCaptionPosition ACaptionPosition, Cxgeometry::TdxScaleFactor* AScaleFactor, Cxgeometry::TcxBorders ABorders = (Cxgeometry::TcxBorders() << Cxgeometry::TcxBorder::bLeft << Cxgeometry::TcxBorder::bTop << Cxgeometry::TcxBorder::bRight << Cxgeometry::TcxBorder::bBottom ))/* overload */;
	virtual void __fastcall DrawTrackBarTrackBounds(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall DrawTrackBarThumbBorderUpDown(Cxgraphics::TcxCanvas* ACanvas, const Dxcore::TPoints ALightPolyLine, const Dxcore::TPoints AShadowPolyLine, const Dxcore::TPoints ADarkPolyLine);
	virtual void __fastcall DrawTrackBarThumbBorderBoth(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall DrawDateNavigatorDateHeader(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R);
	virtual System::Uitypes::TColor __fastcall GetSplitterOuterColor(bool AHighlighted);
	virtual void __fastcall DrawScaledToggleSwitchState(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, TcxButtonState AState, bool AChecked, bool AFocused, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual System::Uitypes::TColor __fastcall ToggleSwitchToggleColor(bool AChecked);
	virtual void __fastcall DrawFindPanelBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, const Cxgeometry::TcxBorders ABorders, Cxgeometry::TdxScaleFactor* AScaleFactor, Cxgeometry::TdxScaleFactor* ABordersScaleFactor)/* overload */;
public:
	/* TcxCustomLookAndFeelPainter.Destroy */ inline __fastcall virtual ~TcxFlatLookAndFeelPainter() { }
	
public:
	/* TObject.Create */ inline __fastcall TcxFlatLookAndFeelPainter() : TcxCustomLookAndFeelPainter() { }
	
	/* Hoisted overloads: */
	
public:
	inline void __fastcall  DrawScaledExpandButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AExpanded, Cxgeometry::TdxScaleFactor* AScaleFactor, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000), TcxExpandButtonState AState = (TcxExpandButtonState)(0x0)){ TcxCustomLookAndFeelPainter::DrawScaledExpandButton(ACanvas, R, AExpanded, AScaleFactor, AColor, AState); }
	inline void __fastcall  DrawFooterBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R){ TcxCustomLookAndFeelPainter::DrawFooterBorder(ACanvas, R); }
	inline void __fastcall  DrawFooterCellBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R){ TcxCustomLookAndFeelPainter::DrawFooterCellBorder(ACanvas, R); }
	inline void __fastcall  DrawScaledToggleSwitchState(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, TcxButtonState AState, bool AChecked, Cxgeometry::TdxScaleFactor* AScaleFactor){ TcxCustomLookAndFeelPainter::DrawScaledToggleSwitchState(ACanvas, ABounds, AState, AChecked, AScaleFactor); }
	inline void __fastcall  DrawFindPanelBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgeometry::TcxBorders ABorders, Cxgeometry::TdxScaleFactor* AScaleFactor){ TcxCustomLookAndFeelPainter::DrawFindPanelBorder(ACanvas, R, ABorders, AScaleFactor); }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxUltraFlatLookAndFeelPainter : public TcxCustomLookAndFeelPainter
{
	typedef TcxCustomLookAndFeelPainter inherited;
	
protected:
	virtual int __fastcall FooterContentOffset();
	virtual void __fastcall DoDrawScaledScrollBarPart(Cxcustomcanvas::TcxCustomCanvas* ACanvas, bool AHorizontal, const System::Types::TRect &R, TcxScrollBarPart APart, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Uitypes::TColor __fastcall FilterDropDownButtonBorderColor(TcxButtonState AState);
	virtual void __fastcall DrawSchedulerNavigationButtonContent(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const System::Types::TRect &AArrowRect, bool AIsNextButton, TcxButtonState AState, const bool AIsVertical = true);
	virtual void __fastcall DrawBreadcrumbEditCustomButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TdxBreadcrumbEditButtonState AState, Cxgeometry::TcxBorders ABorders);
	virtual System::Uitypes::TColor __fastcall TabBorderHighlightColor();
	virtual System::Uitypes::TColor __fastcall TabBorderDarkColor();
	
public:
	virtual System::UnicodeString __fastcall LookAndFeelName();
	virtual TcxLookAndFeelStyle __fastcall LookAndFeelStyle();
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerBorderColor();
	virtual System::Uitypes::TColor __fastcall BorderHighlightColor();
	virtual int __fastcall BorderSize();
	virtual void __fastcall DrawBorder(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, int AWidth = 0x1);
	virtual void __fastcall DoDrawSeparator(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, bool AIsVertical);
	virtual int __fastcall ButtonBorderSize(TcxButtonState AState = (TcxButtonState)(0x1));
	virtual System::Uitypes::TColor __fastcall ButtonColor(TcxButtonState AState);
	virtual System::Types::TRect __fastcall ScaledButtonFocusRect(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Uitypes::TColor __fastcall ButtonSymbolColor(TcxButtonState AState, System::Uitypes::TColor ADefaultColor = (System::Uitypes::TColor)(0x20000000), TcxButtonPart APart = (TcxButtonPart)(0x0));
	virtual TcxButtonState __fastcall ButtonSymbolState(TcxButtonState AState);
	virtual int __fastcall ScaledButtonTextOffset(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual int __fastcall ScaledButtonTextShift(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawButtonBorder(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState);
	virtual void __fastcall DrawScaledExpandButton(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, bool AExpanded, Cxgeometry::TdxScaleFactor* AScaleFactor, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000), TcxExpandButtonState AState = (TcxExpandButtonState)(0x0))/* overload */;
	virtual void __fastcall DrawHeaderControlSectionBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgeometry::TcxBorders ABorders, TcxButtonState AState);
	virtual void __fastcall DrawHeaderControlSectionContent(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &ATextAreaBounds, TcxButtonState AState, System::Classes::TAlignment AAlignmentHorz, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AMultiLine, bool AShowEndEllipsis, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor);
	virtual int __fastcall ScaledExpandButtonSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual bool __fastcall IsButtonHotTrack();
	virtual void __fastcall DrawCheckBorder(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState);
	virtual System::Uitypes::TColor __fastcall DefaultFixedSeparatorColor();
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerTimeRulerBorderColor();
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerTimeRulerTextColor();
	virtual System::Uitypes::TColor __fastcall RadioButtonBodyColor(TcxButtonState AState);
	virtual void __fastcall DrawHeaderBorder(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, TcxNeighbors ANeighbors, Cxgeometry::TcxBorders ABorders);
	virtual void __fastcall DrawScaledHeaderEx(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &ATextAreaBounds, TcxNeighbors ANeighbors, Cxgeometry::TcxBorders ABorders, TcxButtonState AState, System::Classes::TAlignment AAlignmentHorz, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AMultiLine, bool AShowEndEllipsis, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor, Cxgeometry::TdxScaleFactor* AScaleFactor, TcxDrawBackgroundEvent AOnDrawBackground = 0x0)/* overload */;
	virtual void __fastcall DrawScaledSortingMark(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AAscendingSorting, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledSummarySortingMark(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AAscendingSorting, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual Cxgeometry::TcxBorders __fastcall HeaderBorders(TcxNeighbors ANeighbors);
	virtual int __fastcall HeaderBorderSize();
	virtual System::Types::TPoint __fastcall ScaledSortingMarkSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TPoint __fastcall ScaledSummarySortingMarkSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledIndicatorItem(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, const System::Types::TRect &AImageAreaBounds, TcxIndicatorKind AKind, System::Uitypes::TColor AColor, Cxgeometry::TdxScaleFactor* AScaleFactor, TcxDrawBackgroundEvent AOnDrawBackground, TcxNeighbors ANeighbors, bool APaintLeftSide, int ABorderWidth = 0x1)/* overload */;
	virtual void __fastcall DrawFooterBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, const Cxgeometry::TcxBorders ABorders, Cxgeometry::TdxScaleFactor* AScaleFactor, Cxgeometry::TdxScaleFactor* ABordersScaleFactor)/* overload */;
	virtual void __fastcall DrawFooterBorderEx(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgeometry::TcxBorders ABorders, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawFooterCellBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, const Cxgeometry::TcxBorders ABorders, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual int __fastcall FooterBorderSize();
	virtual int __fastcall FooterCellBorderSize();
	virtual int __fastcall FooterCellOffset();
	virtual void __fastcall DrawScaledFilterDropDownButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, bool AIsFilterActive, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TPoint __fastcall ScaledFilterCloseButtonSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawTabBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgeometry::TcxBorder ABorder, Cxgeometry::TcxBorders ABorders, bool AVertical);
	virtual void __fastcall DrawTabsRoot(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgeometry::TcxBorders ABorders, bool AVertical);
	virtual int __fastcall TabBorderSize(bool AVertical);
	virtual void __fastcall DrawSchedulerScaledNavigatorButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawSchedulerSplitterBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, const Cxgraphics::TcxViewParams &AViewParams, bool AIsHorizontal);
	virtual void __fastcall DrawGroupBoxScaledFrame(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AEnabled, TcxGroupBoxCaptionPosition ACaptionPosition, Cxgeometry::TdxScaleFactor* AScaleFactor, Cxgeometry::TcxBorders ABorders = (Cxgeometry::TcxBorders() << Cxgeometry::TcxBorder::bLeft << Cxgeometry::TcxBorder::bTop << Cxgeometry::TcxBorder::bRight << Cxgeometry::TcxBorder::bBottom ))/* overload */;
	virtual void __fastcall DrawTrackBarTrackBounds(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall DrawTrackBarThumbBorderUpDown(Cxgraphics::TcxCanvas* ACanvas, const Dxcore::TPoints ALightPolyLine, const Dxcore::TPoints AShadowPolyLine, const Dxcore::TPoints ADarkPolyLine);
	virtual void __fastcall DrawTrackBarThumbBorderBoth(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall DrawPrintPreviewScaledBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Uitypes::TColor __fastcall GetSplitterOuterColor(bool AHighlighted);
	virtual System::Types::TSize __fastcall GetScaledSplitterSize(bool AHorizontal, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawNavigatorScaledButton(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, System::Uitypes::TColor ABackgroundColor, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual void __fastcall DrawNavigatorBorder(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, bool ASelected);
	virtual bool __fastcall NavigatorBorderOverlap();
	virtual int __fastcall NavigatorBorderSize();
	virtual void __fastcall DrawDropDownListBoxBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool AHasBorders);
	virtual void __fastcall DrawDropDownListBoxScaledGutterBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawDropDownListBoxScaledSelection(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const System::Types::TRect &AGutterRect, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawDropDownListBoxScaledSeparator(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const System::Types::TRect &AGutterRect, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Uitypes::TColor __fastcall DropDownListBoxItemTextColor(bool ASelected);
	virtual int __fastcall BreadcrumbEditScaledButtonAreaSeparatorSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TRect __fastcall BreadcrumbEditScaledButtonContentOffsets(bool AIsFirst, bool AIsLast, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawBreadcrumbEditBorders(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxgeometry::TcxBorders ABorders, TdxBreadcrumbEditState AState);
	virtual void __fastcall DrawBreadcrumbEditScaledButtonAreaSeparator(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TdxBreadcrumbEditState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawBreadcrumbEditScaledButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TdxBreadcrumbEditButtonState AState, bool AIsFirst, bool AIsLast, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawBreadcrumbEditScaledDropDownButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TdxBreadcrumbEditButtonState AState, bool AIsInEditor, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TSize __fastcall GetBevelMinimalShapeSize(TdxBevelShape AShape);
	virtual void __fastcall GetBevelShapeColors(/* out */ System::Uitypes::TColor &AColor1, /* out */ System::Uitypes::TColor &AColor2);
	virtual int __fastcall GridBordersOverlapSize();
	virtual void __fastcall DrawScaledToggleSwitchState(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, TcxButtonState AState, bool AChecked, bool AFocused, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual System::Uitypes::TColor __fastcall ToggleSwitchToggleColor(bool AChecked);
	virtual void __fastcall DrawScaledToggleSwitchThumb(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, TcxButtonState AState, bool AChecked, bool AFocused, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual void __fastcall DrawScaledTokenBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
public:
	/* TcxCustomLookAndFeelPainter.Destroy */ inline __fastcall virtual ~TcxUltraFlatLookAndFeelPainter() { }
	
public:
	/* TObject.Create */ inline __fastcall TcxUltraFlatLookAndFeelPainter() : TcxCustomLookAndFeelPainter() { }
	
	/* Hoisted overloads: */
	
public:
	inline void __fastcall  DrawScaledExpandButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AExpanded, Cxgeometry::TdxScaleFactor* AScaleFactor, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000), TcxExpandButtonState AState = (TcxExpandButtonState)(0x0)){ TcxCustomLookAndFeelPainter::DrawScaledExpandButton(ACanvas, R, AExpanded, AScaleFactor, AColor, AState); }
	inline void __fastcall  DrawScaledIndicatorItem(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, const System::Types::TRect &AImageAreaBounds, TcxIndicatorKind AKind, System::Uitypes::TColor AColor, Cxgeometry::TdxScaleFactor* AScaleFactor, TcxDrawBackgroundEvent AOnDrawBackground = 0x0, TcxNeighbors ANeighbors = (TcxNeighbors() << TcxNeighbor::nTop << TcxNeighbor::nBottom ), int ABorderWidth = 0x1){ TcxCustomLookAndFeelPainter::DrawScaledIndicatorItem(ACanvas, R, AImageAreaBounds, AKind, AColor, AScaleFactor, AOnDrawBackground, ANeighbors, ABorderWidth); }
	inline void __fastcall  DrawScaledIndicatorItem(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxIndicatorKind AKind, System::Uitypes::TColor AColor, Cxgeometry::TdxScaleFactor* AScaleFactor, TcxDrawBackgroundEvent AOnDrawBackground = 0x0, int ABorderWidth = 0x1){ TcxCustomLookAndFeelPainter::DrawScaledIndicatorItem(ACanvas, R, AKind, AColor, AScaleFactor, AOnDrawBackground, ABorderWidth); }
	inline void __fastcall  DrawFooterBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R){ TcxCustomLookAndFeelPainter::DrawFooterBorder(ACanvas, R); }
	inline void __fastcall  DrawFooterCellBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R){ TcxCustomLookAndFeelPainter::DrawFooterCellBorder(ACanvas, R); }
	inline void __fastcall  DrawScaledToggleSwitchState(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, TcxButtonState AState, bool AChecked, Cxgeometry::TdxScaleFactor* AScaleFactor){ TcxCustomLookAndFeelPainter::DrawScaledToggleSwitchState(ACanvas, ABounds, AState, AChecked, AScaleFactor); }
	inline void __fastcall  DrawScaledToggleSwitchThumb(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor){ TcxCustomLookAndFeelPainter::DrawScaledToggleSwitchThumb(ACanvas, ABounds, AState, AScaleFactor); }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxOffice11LookAndFeelPainter : public TcxUltraFlatLookAndFeelPainter
{
	typedef TcxUltraFlatLookAndFeelPainter inherited;
	
protected:
	virtual System::Uitypes::TColor __fastcall DefaultDateNavigatorHeaderHighlightTextColor();
	virtual System::Byte __fastcall GetDefaultFixedColumnHighlightAAlpha();
	virtual System::Uitypes::TColor __fastcall HeaderBottomColor();
	virtual System::Uitypes::TColor __fastcall HeaderDarkEdgeColor();
	virtual System::Uitypes::TColor __fastcall HeaderHighlightEdgeColor();
	virtual System::Uitypes::TColor __fastcall HeaderTopColor();
	virtual void __fastcall DrawContentBackground(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, System::Uitypes::TColor ABackgroundColor, bool AIsFooter);
	virtual void __fastcall DoDrawScaledScrollBarPart(Cxcustomcanvas::TcxCustomCanvas* ACanvas, bool AHorizontal, const System::Types::TRect &R, TcxScrollBarPart APart, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Uitypes::TColor __fastcall FilterDropDownButtonBorderColor(TcxButtonState AState);
	virtual System::Uitypes::TColor __fastcall TabBorderHighlightColor();
	virtual System::Uitypes::TColor __fastcall TabBorderDarkColor();
	virtual void __fastcall DrawSchedulerNavigationButtonContent(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const System::Types::TRect &AArrowRect, bool AIsNextButton, TcxButtonState AState, const bool AIsVertical = true);
	virtual void __fastcall DrawBreadcrumbEditCustomButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TdxBreadcrumbEditButtonState AState, Cxgeometry::TcxBorders ABorders);
	virtual System::Uitypes::TColor __fastcall GetDataRowLayoutContentColor();
	
public:
	virtual System::UnicodeString __fastcall LookAndFeelName();
	virtual TcxLookAndFeelStyle __fastcall LookAndFeelStyle();
	virtual bool __fastcall NeedRedrawOnResize();
	virtual System::Uitypes::TColor __fastcall DefaultControlColor();
	virtual System::Uitypes::TColor __fastcall DefaultControlTextColor();
	virtual System::Uitypes::TColor __fastcall DefaultDateNavigatorHeaderColor();
	virtual System::Uitypes::TColor __fastcall DefaultDateNavigatorSelectionColor();
	virtual System::Uitypes::TColor __fastcall DefaultDateNavigatorSelectionTextColor();
	virtual System::Uitypes::TColor __fastcall DefaultFilterBoxColor();
	virtual System::Uitypes::TColor __fastcall DefaultFilterBoxTextColor();
	virtual System::Uitypes::TColor __fastcall DefaultFooterColor();
	virtual System::Uitypes::TColor __fastcall DefaultFooterTextColor();
	virtual System::Uitypes::TColor __fastcall DefaultGroupColor();
	virtual System::Uitypes::TColor __fastcall DefaultGroupByBoxColor();
	virtual System::Uitypes::TColor __fastcall DefaultGroupByBoxTextColor();
	virtual System::Uitypes::TColor __fastcall DefaultHeaderColor();
	virtual System::Uitypes::TColor __fastcall DefaultHeaderBackgroundColor();
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerBorderColor();
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerControlColor();
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerDayHeaderColor();
	virtual System::Uitypes::TColor __fastcall DefaultTabColor();
	virtual System::Uitypes::TColor __fastcall DefaultTabsBackgroundColor();
	virtual System::Uitypes::TColor __fastcall DefaultTimeGridMinorScaleColor();
	virtual System::Uitypes::TColor __fastcall DefaultTimeGridSelectionBarColor();
	virtual int __fastcall SeparatorSize();
	virtual System::Uitypes::TColor __fastcall BorderHighlightColor();
	virtual void __fastcall DrawBorder(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, int AWidth = 0x1);
	virtual void __fastcall DoDrawSeparator(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, bool AIsVertical);
	virtual System::Uitypes::TColor __fastcall ButtonColor(TcxButtonState AState);
	virtual System::Uitypes::TColor __fastcall ButtonSymbolColor(TcxButtonState AState, System::Uitypes::TColor ADefaultColor = (System::Uitypes::TColor)(0x20000000), TcxButtonPart APart = (TcxButtonPart)(0x0));
	virtual void __fastcall DrawButtonBorder(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState);
	virtual void __fastcall DrawScaledExpandButton(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, bool AExpanded, Cxgeometry::TdxScaleFactor* AScaleFactor, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000), TcxExpandButtonState AState = (TcxExpandButtonState)(0x0))/* overload */;
	virtual bool __fastcall DrawExpandButtonFirst();
	virtual void __fastcall DrawScaledSmallExpandButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AExpanded, System::Uitypes::TColor ABorderColor, Cxgeometry::TdxScaleFactor* AScaleFactor, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	virtual int __fastcall ScaledExpandButtonSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual int __fastcall ScaledSmallExpandButtonSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Uitypes::TColor __fastcall CheckButtonColor(TcxButtonState AState, TcxCheckBoxState ACheckState);
	virtual System::Uitypes::TColor __fastcall RadioButtonBodyColor(TcxButtonState AState);
	virtual void __fastcall DrawScaledFilterDropDownButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, bool AIsFilterActive, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledHeader(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &ATextAreaBounds, TcxNeighbors ANeighbors, Cxgeometry::TcxBorders ABorders, TcxButtonState AState, System::Classes::TAlignment AAlignmentHorz, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AMultiLine, bool AShowEndEllipsis, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor, Cxgeometry::TdxScaleFactor* AScaleFactor, TcxDrawBackgroundEvent AOnDrawBackground = 0x0, bool AIsLast = false, bool AInGroupByBox = false, int ABorderWidth = 0x1)/* overload */;
	virtual void __fastcall DrawHeaderBorder(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, TcxNeighbors ANeighbors, Cxgeometry::TcxBorders ABorders);
	virtual void __fastcall DrawScaledHeaderControlSection(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &ATextAreaBounds, TcxNeighbors ANeighbors, Cxgeometry::TcxBorders ABorders, TcxButtonState AState, System::Classes::TAlignment AAlignmentHorz, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AMultiLine, bool AShowEndEllipsis, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual void __fastcall DrawScaledSortingMark(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AAscendingSorting, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledSummarySortingMark(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AAscendingSorting, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual Cxgeometry::TcxBorders __fastcall HeaderBorders(TcxNeighbors ANeighbors);
	virtual int __fastcall HeaderBorderSize();
	virtual bool __fastcall IsHeaderHotTrack();
	virtual System::Uitypes::TColor __fastcall FooterSeparatorColor();
	virtual Cxgeometry::TcxBorders __fastcall FooterBorders();
	virtual int __fastcall GridBordersOverlapSize();
	virtual void __fastcall LayoutViewDrawRecordCaption(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &ATextRect, TcxGroupBoxCaptionPosition APosition, TcxButtonState AState, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000), Vcl::Graphics::TBitmap* const ABitmap = (Vcl::Graphics::TBitmap*)(0x0));
	virtual int __fastcall ScaledScrollBarMinimalThumbSize(bool AVertical, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledMonthHeader(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::UnicodeString AText, TcxNeighbors ANeighbors, const Cxgraphics::TcxViewParams &AViewParams, Cxgraphics::TcxArrowDirections AArrows, int ASideWidth, Cxgeometry::TdxScaleFactor* AScaleFactor, TcxDrawBackgroundEvent AOnDrawBackground = 0x0);
	virtual void __fastcall DrawSchedulerScaledNavigatorButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawSchedulerBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DoDrawSizeGrip(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual void __fastcall DrawGroupBoxScaledFrame(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AEnabled, TcxGroupBoxCaptionPosition ACaptionPosition, Cxgeometry::TdxScaleFactor* AScaleFactor, Cxgeometry::TcxBorders ABorders = (Cxgeometry::TcxBorders() << Cxgeometry::TcxBorder::bLeft << Cxgeometry::TcxBorder::bTop << Cxgeometry::TcxBorder::bRight << Cxgeometry::TcxBorder::bBottom ))/* overload */;
	virtual System::Uitypes::TColor __fastcall GroupBoxTextColor(bool AEnabled, TcxGroupBoxCaptionPosition ACaptionPosition);
	virtual void __fastcall DrawTrackBarTrackBounds(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall DrawTrackBarThumbBorderUpDown(Cxgraphics::TcxCanvas* ACanvas, const Dxcore::TPoints ALightPolyLine, const Dxcore::TPoints AShadowPolyLine, const Dxcore::TPoints ADarkPolyLine);
	virtual void __fastcall DrawTrackBarThumbBorderBoth(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall DrawPanelBackground(Cxgraphics::TcxCanvas* ACanvas, Vcl::Controls::TWinControl* AControl, const System::Types::TRect &ABounds, System::Uitypes::TColor AColorFrom = (System::Uitypes::TColor)(0x20000000), System::Uitypes::TColor AColorTo = (System::Uitypes::TColor)(0x20000000));
	virtual void __fastcall DrawLayoutControlBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DrawDateNavigatorDateHeader(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R);
	virtual System::Uitypes::TColor __fastcall GetSplitterInnerColor(bool AHighlighted);
	virtual System::Uitypes::TColor __fastcall GetSplitterOuterColor(bool AHighlighted);
	virtual int __fastcall NavigatorBorderSize();
	virtual System::Uitypes::TColor __fastcall BreadcrumbEditBackgroundColor(TdxBreadcrumbEditState AState);
	virtual void __fastcall DrawBreadcrumbEditBorders(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxgeometry::TcxBorders ABorders, TdxBreadcrumbEditState AState);
	virtual void __fastcall DrawDropDownListBoxBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool AHasBorders);
	virtual void __fastcall DrawDropDownListBoxScaledGutterBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawDropDownListBoxScaledSelection(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const System::Types::TRect &AGutterRect, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawDropDownListBoxScaledSeparator(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const System::Types::TRect &AGutterRect, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawAlertWindowBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, Cxgeometry::TdxScaleFactor* AScaleFactor = (Cxgeometry::TdxScaleFactor*)(0x0));
	virtual System::Types::TSize __fastcall GetBevelMinimalShapeSize(TdxBevelShape AShape);
	virtual void __fastcall GetBevelShapeColors(/* out */ System::Uitypes::TColor &AColor1, /* out */ System::Uitypes::TColor &AColor2);
	virtual System::Types::TSize __fastcall ScaledClockSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledClock(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, System::TDateTime ADateTime, System::Uitypes::TColor ABackgroundColor, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual System::Uitypes::TColor __fastcall RichEditControlHeaderFooterLineColor();
	virtual System::Uitypes::TColor __fastcall RichEditControlHeaderFooterMarkBackColor();
	virtual System::Uitypes::TColor __fastcall RichEditRulerInactiveAreaColor();
	virtual System::Uitypes::TColor __fastcall RichEditRulerTabTypeToggleBorderColor();
	virtual void __fastcall DrawScaledTokenBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawSpreadSheetScaledHeader(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, TcxNeighbors ANeighbors, Cxgeometry::TcxBorders ABorders, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
public:
	/* TcxCustomLookAndFeelPainter.Destroy */ inline __fastcall virtual ~TcxOffice11LookAndFeelPainter() { }
	
public:
	/* TObject.Create */ inline __fastcall TcxOffice11LookAndFeelPainter() : TcxUltraFlatLookAndFeelPainter() { }
	
	/* Hoisted overloads: */
	
public:
	inline void __fastcall  DrawScaledExpandButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AExpanded, Cxgeometry::TdxScaleFactor* AScaleFactor, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000), TcxExpandButtonState AState = (TcxExpandButtonState)(0x0)){ TcxCustomLookAndFeelPainter::DrawScaledExpandButton(ACanvas, R, AExpanded, AScaleFactor, AColor, AState); }
	inline void __fastcall  DrawScaledHeader(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &ABounds, TcxButtonState AState, TcxNeighbors ANeighbors, Cxgeometry::TcxBorders ABorders, Cxgeometry::TdxScaleFactor* AScaleFactor, bool AIsLast = false, bool AIsGroup = false){ TcxCustomLookAndFeelPainter::DrawScaledHeader(ACanvas, ABounds, AState, ANeighbors, ABorders, AScaleFactor, AIsLast, AIsGroup); }
	inline void __fastcall  DoDrawSizeGrip(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect){ TcxCustomLookAndFeelPainter::DoDrawSizeGrip(ACanvas, ARect); }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxWinXPLookAndFeelPainter : public TcxStandardLookAndFeelPainter
{
	typedef TcxStandardLookAndFeelPainter inherited;
	
private:
	static System::StaticArray<int, 5> ButtonStateToHeaderState;
	Cxgraphics::TcxBitmap32* FZoomInButtonGlyph;
	Cxgraphics::TcxBitmap32* FZoomOutButtonGlyph;
	void __fastcall DrawNativeRangeTrackBarThumb(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TcxButtonState AState, bool AHorizontal, TcxTrackBarTicksAlign ATicks, System::Uitypes::TColor AThumbColor, Cxgeometry::TdxScaleFactor* AScaleFactor);
	bool __fastcall DoDrawThemeBackground(Cxcustomcanvas::TcxCustomCanvas* ACanvas, Dxthememanager::TdxThemedObjectType AThemedObjectType, Cxgeometry::TdxScaleFactor* AScaleFactor, const System::Types::TRect &R, int APartId, int AStateId);
	bool __fastcall DoDrawScaledThemeBackground(Cxcustomcanvas::TcxCustomCanvas* ACanvas, Dxthememanager::TdxThemedObjectType AThemedObjectType, Cxgeometry::TdxScaleFactor* AScaleFactor, const System::Types::TRect &R, int APartId, int AStateId);
	
protected:
	virtual void __fastcall DoDrawScaledButtonCaption(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, const System::UnicodeString ACaption, TcxButtonState AState, System::Uitypes::TColor ATextColor, bool ADrawBorder, bool AIsToolButton, bool AWordWrap, Cxgeometry::TdxScaleFactor* AScaleFactor, TcxButtonPart APart);
	virtual void __fastcall DoDrawScaledScrollBarPart(Cxcustomcanvas::TcxCustomCanvas* ACanvas, bool AHorizontal, const System::Types::TRect &R, TcxScrollBarPart APart, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	void __fastcall DrawBreadcrumbEditNodePart(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TdxBreadcrumbEditButtonState AState, Cxgeometry::TcxBorders ABorders, Cxgeometry::TdxScaleFactor* AScaleFactor);
	HIDESBASE virtual void __fastcall DrawContent(Cxgraphics::TcxCanvas* ACanvas, NativeUInt ATheme, int APartId, int AStateId, const System::Types::TRect &ABounds, const System::Types::TRect &ATextAreaBounds, System::Classes::TAlignment AAlignmentHorz, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AMultiLine, bool AShowEndEllipsis, bool AShowPrefix, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor);
	virtual void __fastcall DrawSchedulerNavigationButtonContent(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const System::Types::TRect &AArrowRect, bool AIsNextButton, TcxButtonState AState, const bool AIsVertical = true);
	void __fastcall DrawThemedTab(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgeometry::TcxBorders ABorders, const System::UnicodeString AText, NativeUInt ATheme, int AState, bool AVertical, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor, bool AShowPrefix = false);
	bool __fastcall NativeZoomButtonDraw(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor, Vcl::Graphics::TBitmap* AGlyph);
	bool __fastcall NativeZoomButtonGetMinSize(Vcl::Graphics::TBitmap* AGlyph, Cxgeometry::TdxScaleFactor* AScaleFactor, /* out */ System::Types::TSize &ASize);
	__property Cxgraphics::TcxBitmap32* ZoomInButtonGlyph = {read=FZoomInButtonGlyph};
	__property Cxgraphics::TcxBitmap32* ZoomOutButtonGlyph = {read=FZoomOutButtonGlyph};
	virtual int __fastcall FooterContentOffset();
	
public:
	__fastcall virtual ~TcxWinXPLookAndFeelPainter();
	virtual void __fastcall AfterConstruction();
	virtual System::UnicodeString __fastcall LookAndFeelName();
	virtual TcxLookAndFeelStyle __fastcall LookAndFeelStyle();
	virtual bool __fastcall NeedRedrawOnResize();
	__classmethod void __fastcall DrawScaledThemeBackground(NativeUInt ATheme, HDC DC, int APartId, int AStateId, const System::Types::TRect &R, Cxgeometry::TdxScaleFactor* AScaleFactor, bool AForceScale = false, bool AUseThemePartSize = true);
	virtual System::Uitypes::TColor __fastcall DefaultFilterBoxColor();
	virtual System::Uitypes::TColor __fastcall DefaultFilterBoxTextColor();
	virtual System::Uitypes::TColor __fastcall DefaultFooterColor();
	virtual System::Uitypes::TColor __fastcall DefaultFooterTextColor();
	virtual System::Uitypes::TColor __fastcall DefaultGridLineColor();
	virtual System::Uitypes::TColor __fastcall DefaultGroupByBoxColor();
	virtual System::Uitypes::TColor __fastcall DefaultGroupByBoxTextColor();
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerBorderColor();
	virtual void __fastcall DrawScaledArrow(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgraphics::TcxArrowDirection AArrowDirection, Cxgeometry::TdxScaleFactor* AScaleFactor, bool ADrawBorder = true)/* overload */;
	virtual void __fastcall DrawScaledArrowBorder(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual int __fastcall BorderSize();
	virtual int __fastcall SeparatorSize();
	virtual void __fastcall DrawBorder(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, int AWidth = 0x1);
	virtual void __fastcall DoDrawSeparator(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, bool AIsVertical);
	virtual int __fastcall ButtonBorderSize(TcxButtonState AState = (TcxButtonState)(0x1));
	virtual System::Uitypes::TColor __fastcall ButtonColor(TcxButtonState AState);
	virtual System::Uitypes::TColor __fastcall ButtonSymbolColor(TcxButtonState AState, System::Uitypes::TColor ADefaultColor = (System::Uitypes::TColor)(0x20000000), TcxButtonPart APart = (TcxButtonPart)(0x0));
	virtual void __fastcall DrawScaledButton(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, bool AFocused, Cxgeometry::TdxScaleFactor* AScaleFactor, bool ADrawBorder = true, bool AIsToolButton = false, TcxButtonPart APart = (TcxButtonPart)(0x0), System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000))/* overload */;
	virtual int __fastcall ScaledButtonTextOffset(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual int __fastcall ScaledButtonTextShift(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TRect __fastcall ScaledButtonFocusRect(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Uitypes::TColor __fastcall DefaultCommandLinkTextColor(TcxButtonState AState, System::Uitypes::TColor ADefaultColor = (System::Uitypes::TColor)(0x20000000));
	virtual void __fastcall DrawScaledCommandLinkBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	virtual void __fastcall DrawScaledCommandLinkGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TPoint &AGlyphPos, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TSize __fastcall GetScaledCommandLinkGlyphSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TRect __fastcall GetScaledCommandLinkMargins(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledExpandButton(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, bool AExpanded, Cxgeometry::TdxScaleFactor* AScaleFactor, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000), TcxExpandButtonState AState = (TcxExpandButtonState)(0x0))/* overload */;
	virtual void __fastcall DrawTreeViewExpandButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AExpanded, bool AExplorerStyle, Cxgeometry::TdxScaleFactor* AScaleFactor, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000), TcxExpandButtonState AState = (TcxExpandButtonState)(0x0))/* overload */;
	virtual bool __fastcall DrawExpandButtonFirst();
	virtual void __fastcall DrawScaledGroupExpandButton(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, bool AExpanded, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledSmallButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledSmallExpandButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AExpanded, System::Uitypes::TColor ABorderColor, Cxgeometry::TdxScaleFactor* AScaleFactor, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	virtual int __fastcall ScaledExpandButtonSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual int __fastcall ScaledGroupExpandButtonSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual int __fastcall ScaledSmallExpandButtonSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual bool __fastcall IsButtonHotTrack();
	virtual bool __fastcall IsPointOverGroupExpandButton(const System::Types::TRect &R, const System::Types::TPoint &P);
	virtual System::Types::TSize __fastcall TreeViewExpandButtonSize(bool AExplorerStyle, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual int __fastcall CheckBorderSize();
	virtual System::Types::TSize __fastcall ScaledCheckButtonSize(Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual void __fastcall DrawScaledCheck(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, TcxCheckBoxState ACheckState, System::Uitypes::TColor AColor, Cxgeometry::TdxScaleFactor* AScaleFactor, bool ADrawBackground)/* overload */;
	virtual void __fastcall DrawCheckBorder(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState);
	virtual void __fastcall DrawScaledRadioButton(Cxgraphics::TcxCanvas* ACanvas, int X, int Y, TcxButtonState AButtonState, bool AChecked, bool AFocused, System::Uitypes::TColor ABrushColor, Cxgeometry::TdxScaleFactor* AScaleFactor, bool AIsDesigning = false)/* overload */;
	virtual System::Types::TSize __fastcall ScaledRadioButtonSize(Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual System::Types::TSize __fastcall GetScaledBackButtonSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledBackButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TSize __fastcall GetScaledZoomInButtonSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TSize __fastcall GetScaledZoomOutButtonSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledZoomInButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledZoomOutButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledHeader(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &ABounds, TcxButtonState AState, TcxNeighbors ANeighbors, Cxgeometry::TcxBorders ABorders, Cxgeometry::TdxScaleFactor* AScaleFactor, bool AIsLast = false, bool AIsGroup = false)/* overload */;
	virtual void __fastcall DrawScaledHeader(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &ATextAreaBounds, TcxNeighbors ANeighbors, Cxgeometry::TcxBorders ABorders, TcxButtonState AState, System::Classes::TAlignment AAlignmentHorz, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AMultiLine, bool AShowEndEllipsis, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor, Cxgeometry::TdxScaleFactor* AScaleFactor, TcxDrawBackgroundEvent AOnDrawBackground = 0x0, bool AIsLast = false, bool AInGroupByBox = false, int ABorderWidth = 0x1)/* overload */;
	virtual void __fastcall DrawHeaderPressed(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual void __fastcall DrawScaledHeaderControlSection(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &ATextAreaBounds, TcxNeighbors ANeighbors, Cxgeometry::TcxBorders ABorders, TcxButtonState AState, System::Classes::TAlignment AAlignmentHorz, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AMultiLine, bool AShowEndEllipsis, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual void __fastcall DrawScaledSortingMark(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AAscendingSorting, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledSummarySortingMark(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AAscendingSorting, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual int __fastcall HeaderBorderSize();
	virtual int __fastcall HeaderControlSectionBorderSize(TcxButtonState AState = (TcxButtonState)(0x1));
	virtual System::Types::TRect __fastcall HeaderControlSectionContentBounds(const System::Types::TRect &ABounds, TcxButtonState AState);
	virtual bool __fastcall IsHeaderHotTrack();
	virtual System::Types::TPoint __fastcall ScaledSortingMarkSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawFilterRowSeparator(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, System::Uitypes::TColor ABackgroundColor);
	virtual void __fastcall DrawFooterBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, const Cxgeometry::TcxBorders ABorders, Cxgeometry::TdxScaleFactor* AScaleFactor, Cxgeometry::TdxScaleFactor* ABordersScaleFactor)/* overload */;
	virtual void __fastcall DrawFooterCell(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, System::Classes::TAlignment AAlignmentHorz, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AMultiLine, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor, TcxDrawBackgroundEvent AOnDrawBackground, const Cxgeometry::TcxBorders ABorders, Cxgeometry::TdxScaleFactor* APaddingsScaleFactor, Cxgeometry::TdxScaleFactor* ABordersScaleFactor)/* overload */;
	virtual int __fastcall FooterBorderSize();
	virtual int __fastcall FooterCellBorderSize();
	virtual System::Types::TRect __fastcall FooterCellBordersSizeRect(const Cxgeometry::TcxBorders ABorders, Cxgeometry::TdxScaleFactor* AScaleFactor, Cxgeometry::TdxScaleFactor* ABordersScaleFactor);
	virtual bool __fastcall FooterDrawCellsFirst();
	virtual System::Uitypes::TColor __fastcall FooterSeparatorColor();
	virtual void __fastcall DrawScaledFilterCloseButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledFilterDropDownButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, bool AIsFilterActive, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TPoint __fastcall ScaledFilterActivateButtonSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TPoint __fastcall ScaledFilterCloseButtonSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Uitypes::TColor __fastcall DefaultLayoutViewCaptionTextColor(TcxGroupBoxCaptionPosition ACaptionPosition, TcxButtonState AState);
	virtual System::Uitypes::TColor __fastcall DefaultLayoutViewContentTextColor(TcxButtonState AState);
	virtual void __fastcall LayoutViewDrawRecordCaption(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &ATextRect, TcxGroupBoxCaptionPosition APosition, TcxButtonState AState, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000), Vcl::Graphics::TBitmap* const ABitmap = (Vcl::Graphics::TBitmap*)(0x0));
	virtual void __fastcall LayoutViewDrawItem(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, TcxButtonState AState, Cxgeometry::TcxBorders ABorders = Cxgeometry::TcxBorders() );
	virtual void __fastcall WinExplorerViewDrawRecord(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, TcxButtonState AState, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000), Vcl::Graphics::TBitmap* const ABitmap = (Vcl::Graphics::TBitmap*)(0x0));
	virtual System::Uitypes::TColor __fastcall WinExplorerViewRecordTextColor(TcxButtonState AState);
	virtual void __fastcall DrawTab(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgeometry::TcxBorders ABorders, const System::UnicodeString AText, TcxButtonState AState, bool AVertical, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor, bool AShowPrefix = false);
	virtual void __fastcall DrawTabBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgeometry::TcxBorder ABorder, Cxgeometry::TcxBorders ABorders, bool AVertical);
	virtual void __fastcall DrawTabsRoot(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgeometry::TcxBorders ABorders, bool AVertical);
	virtual bool __fastcall IsDrawTabImplemented(bool AVertical);
	virtual bool __fastcall IsTabHotTrack(bool AVertical);
	virtual int __fastcall TabBorderSize(bool AVertical);
	virtual void __fastcall DrawScaledSplitter(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &ARect, bool AHighlighted, bool AClicked, bool AHorizontal, Cxgeometry::TdxScaleFactor* AScaleFactor, bool AHasCloseMark = false, Cxgraphics::TcxArrowDirection AArrowDirection = (Cxgraphics::TcxArrowDirection)(0x2));
	virtual void __fastcall DrawScaledIndicatorItem(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, const System::Types::TRect &AImageAreaBounds, TcxIndicatorKind AKind, System::Uitypes::TColor AColor, Cxgeometry::TdxScaleFactor* AScaleFactor, TcxDrawBackgroundEvent AOnDrawBackground, TcxNeighbors ANeighbors, bool APaintLeftSide, int ABorderWidth = 0x1)/* overload */;
	virtual int __fastcall ScaledScrollBarMinimalThumbSize(bool AVertical, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledScrollBarSplitter(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerViewContentColor();
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerViewContentColorClassic();
	virtual void __fastcall DrawScaledMonthHeader(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::UnicodeString AText, TcxNeighbors ANeighbors, const Cxgraphics::TcxViewParams &AViewParams, Cxgraphics::TcxArrowDirections AArrows, int ASideWidth, Cxgeometry::TdxScaleFactor* AScaleFactor, TcxDrawBackgroundEvent AOnDrawBackground = 0x0);
	virtual void __fastcall DrawSchedulerScaledEventProgress(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &AProgress, const Cxgraphics::TcxViewParams &AViewParams, bool ATransparent, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawSchedulerScaledNavigatorButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawSchedulerSplitterBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, const Cxgraphics::TcxViewParams &AViewParams, bool AIsHorizontal);
	virtual System::Types::TRect __fastcall SchedulerEventProgressOffsets();
	virtual System::Types::TSize __fastcall ScaledSizeGripSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DoDrawSizeGrip(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual System::Types::TSize __fastcall DoGetSmallCloseButtonSize();
	virtual void __fastcall DrawGroupBoxScaledFrame(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AEnabled, TcxGroupBoxCaptionPosition ACaptionPosition, Cxgeometry::TdxScaleFactor* AScaleFactor, Cxgeometry::TcxBorders ABorders = (Cxgeometry::TcxBorders() << Cxgeometry::TcxBorder::bLeft << Cxgeometry::TcxBorder::bTop << Cxgeometry::TcxBorder::bRight << Cxgeometry::TcxBorder::bBottom ))/* overload */;
	virtual System::Uitypes::TColor __fastcall GroupBoxTextColor(bool AEnabled, TcxGroupBoxCaptionPosition ACaptionPosition);
	virtual void __fastcall DrawPanelBackground(Cxgraphics::TcxCanvas* ACanvas, Vcl::Controls::TWinControl* AControl, const System::Types::TRect &ABounds, System::Uitypes::TColor AColorFrom = (System::Uitypes::TColor)(0x20000000), System::Uitypes::TColor AColorTo = (System::Uitypes::TColor)(0x20000000));
	virtual void __fastcall DrawEditPopupWindowBorder(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, TcxEditPopupBorderStyle ABorderStyle, bool AClientEdge);
	virtual int __fastcall GetEditPopupWindowBorderWidth(TcxEditPopupBorderStyle AStyle);
	virtual int __fastcall GetEditPopupWindowClientEdgeWidth(TcxEditPopupBorderStyle AStyle);
	virtual System::Uitypes::TColor __fastcall GetHintBorderColor();
	virtual void __fastcall DrawHintBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	virtual System::Uitypes::TColor __fastcall ScreenTipGetDescriptionTextColor();
	virtual System::Uitypes::TColor __fastcall ScreenTipGetTitleTextColor();
	virtual void __fastcall CorrectThumbRect(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &ARect, bool AHorizontal, TcxTrackBarTicksAlign ATicks, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawTrackBarScaledTrack(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const System::Types::TRect &ASelection, bool AShowSelection, bool AEnabled, bool AHorizontal, System::Uitypes::TColor ATrackColor, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual void __fastcall DrawTrackBarScaledThumb(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TcxButtonState AState, bool AHorizontal, TcxTrackBarTicksAlign ATicks, System::Uitypes::TColor AThumbColor, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual void __fastcall DrawRangeTrackBarScaledLeftThumb(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TcxButtonState AState, bool AHorizontal, TcxTrackBarTicksAlign ATicks, System::Uitypes::TColor AThumbColor, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawRangeTrackBarScaledRightThumb(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TcxButtonState AState, bool AHorizontal, TcxTrackBarTicksAlign ATicks, System::Uitypes::TColor AThumbColor, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawDateNavigatorDateHeader(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R);
	virtual System::Types::TPoint __fastcall NavigatorButtonPressedGlyphOffset();
	virtual System::Types::TSize __fastcall NavigatorScaledButtonMinSize(Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual System::Uitypes::TColor __fastcall DropDownListBoxItemTextColor(bool ASelected);
	virtual int __fastcall DropDownListBoxScaledSeparatorSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawDropDownListBoxBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool AHasBorders);
	virtual void __fastcall DrawDropDownListBoxScaledGutterBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawDropDownListBoxScaledSelection(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const System::Types::TRect &AGutterRect, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawDropDownListBoxScaledSeparator(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const System::Types::TRect &AGutterRect, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Uitypes::TColor __fastcall ProgressBarTextColor(TcxProgressBarPart APart = (TcxProgressBarPart)(0x0));
	virtual System::Uitypes::TColor __fastcall BreadcrumbEditBackgroundColor(TdxBreadcrumbEditState AState);
	virtual System::Types::TRect __fastcall BreadcrumbEditBordersSize();
	virtual bool __fastcall BreadcrumbEditIsFadingSupports();
	virtual System::Uitypes::TColor __fastcall BreadcrumbEditProgressChunkTextColor();
	virtual System::Types::TRect __fastcall BreadcrumbEditScaledButtonContentOffsets(bool AIsFirst, bool AIsLast, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TSize __fastcall BreadcrumbEditScaledProgressChunkOverlaySize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TRect __fastcall BreadcrumbEditScaledProgressChunkPadding(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawBreadcrumbEditBorders(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxgeometry::TcxBorders ABorders, TdxBreadcrumbEditState AState);
	virtual void __fastcall DrawBreadcrumbEditScaledButtonAreaSeparator(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TdxBreadcrumbEditState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawBreadcrumbEditScaledButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TdxBreadcrumbEditButtonState AState, bool AIsFirst, bool AIsLast, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawBreadcrumbEditScaledDropDownButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TdxBreadcrumbEditButtonState AState, bool AIsInEditor, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawBreadcrumbEditScaledNode(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TdxBreadcrumbEditButtonState AState, bool AHasDelimiter, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawBreadcrumbEditScaledNodeDelimiter(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TdxBreadcrumbEditButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawBreadcrumbEditScaledNodeDelimiterGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TdxBreadcrumbEditButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	virtual void __fastcall DrawBreadcrumbEditScaledNodeMoreButtonGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TdxBreadcrumbEditButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	virtual void __fastcall DrawBreadcrumbEditScaledProgressChunk(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawBreadcrumbEditScaledProgressChunkOverlay(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual int __fastcall AlertWindowCornerRadius();
	virtual void __fastcall DrawBevelFrame(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, bool ABoxStyle);
	virtual void __fastcall DrawBevelLine(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, bool AIsVertical);
	virtual System::Types::TSize __fastcall GetBevelMinimalShapeSize(TdxBevelShape AShape);
	virtual void __fastcall DrawGalleryGroupHeader(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual bool __fastcall DrawGalleryItemSelectionFirst();
	virtual void __fastcall DrawGalleryItemSelection(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, const TdxGalleryItemViewState &AViewState);
	virtual void __fastcall DrawScaledToggleSwitchState(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, TcxButtonState AState, bool AChecked, bool AFocused, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual void __fastcall DrawScaledToggleSwitchThumb(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, TcxButtonState AState, bool AChecked, bool AFocused, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual System::Uitypes::TColor __fastcall ToggleSwitchToggleColor(bool AChecked);
	virtual System::Types::TSize __fastcall ScaledClockSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawScaledClock(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, System::TDateTime ADateTime, System::Uitypes::TColor ABackgroundColor, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
	virtual void __fastcall DrawModernCalendarDateCellSelection(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TcxCalendarElementStates AStates);
	virtual System::Uitypes::TColor __fastcall GetModernCalendarHeaderTextColor(TcxCalendarElementStates AStates);
	virtual void __fastcall DrawFindPanelBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, const Cxgeometry::TcxBorders ABorders, Cxgeometry::TdxScaleFactor* AScaleFactor, Cxgeometry::TdxScaleFactor* ABordersScaleFactor)/* overload */;
	virtual void __fastcall DrawWheelPickerItemBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TcxButtonState AState);
	virtual void __fastcall DrawWheelPickerItemBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TcxButtonState AState);
	virtual void __fastcall DrawScaledTokenBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawListViewBackground(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &ABounds, bool AExplorerStyle, bool AEnabled);
	void __fastcall DrawListViewFocusRect(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &ABounds, bool AExplorerStyle, bool AHot, bool AInactive);
	virtual void __fastcall DrawListViewGroupExpandButton(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &ABounds, TcxButtonState AState, bool AExpanded, bool AExplorerStyle, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawListViewGroupHeaderBackground(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &ABounds, TdxListViewGroupHeaderStates AState, bool AExplorerStyle, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual void __fastcall DrawListViewGroupHeaderLine(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual void __fastcall DrawListViewItemBackground(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &ABounds, TdxListViewItemStates AState, bool AExplorerStyle);
	virtual void __fastcall DrawListViewSortingMark(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, bool AAscendingSorting, Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Types::TPoint __fastcall GetListViewColumnHeaderSortingMarkSize(Cxgeometry::TdxScaleFactor* AScaleFactor);
	virtual System::Uitypes::TColor __fastcall GetListViewColumnHeaderTextColor(TcxButtonState AState, bool AExplorerStyle);
	virtual System::Uitypes::TColor __fastcall GetListViewItemTextColor(TdxListViewItemStates AState, bool AExplorerStyle);
	virtual System::Uitypes::TColor __fastcall GetListViewGroupTextColor(TdxListViewGroupTextKind AKind, TdxListViewGroupHeaderStates AState, bool AExplorerStyle);
	virtual void __fastcall DrawSpreadSheetScaledHeader(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, TcxNeighbors ANeighbors, Cxgeometry::TcxBorders ABorders, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor);
public:
	/* TObject.Create */ inline __fastcall TcxWinXPLookAndFeelPainter() : TcxStandardLookAndFeelPainter() { }
	
	/* Hoisted overloads: */
	
public:
	inline void __fastcall  DrawScaledButton(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor, TcxButtonPart APart, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000)){ TcxCustomLookAndFeelPainter::DrawScaledButton(ACanvas, R, AState, AScaleFactor, APart, AColor); }
	inline void __fastcall  DrawScaledButton(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor, bool ADrawBorder = true, bool AIsToolButton = false, TcxButtonPart APart = (TcxButtonPart)(0x0), System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000)){ TcxCustomLookAndFeelPainter::DrawScaledButton(ACanvas, R, AState, AScaleFactor, ADrawBorder, AIsToolButton, APart, AColor); }
	inline void __fastcall  DrawScaledButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, const System::UnicodeString ACaption, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor, bool ADrawBorder = true, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000), System::Uitypes::TColor ATextColor = (System::Uitypes::TColor)(0x20000000), bool AWordWrap = false, bool AIsToolButton = false, TcxButtonPart APart = (TcxButtonPart)(0x0)){ TcxCustomLookAndFeelPainter::DrawScaledButton(ACanvas, R, ACaption, AState, AScaleFactor, ADrawBorder, AColor, ATextColor, AWordWrap, AIsToolButton, APart); }
	inline void __fastcall  DrawScaledExpandButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AExpanded, Cxgeometry::TdxScaleFactor* AScaleFactor, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000), TcxExpandButtonState AState = (TcxExpandButtonState)(0x0)){ TcxCustomLookAndFeelPainter::DrawScaledExpandButton(ACanvas, R, AExpanded, AScaleFactor, AColor, AState); }
	inline void __fastcall  DrawScaledCheck(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, bool AChecked, System::Uitypes::TColor AColor, Cxgeometry::TdxScaleFactor* AScaleFactor, bool ADrawBackground){ TcxCustomLookAndFeelPainter::DrawScaledCheck(ACanvas, R, AState, AChecked, AColor, AScaleFactor, ADrawBackground); }
	inline void __fastcall  DrawScaledCheck(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, TcxCheckBoxState ACheckState, System::Uitypes::TColor AColor, Cxgeometry::TdxScaleFactor* AScaleFactor){ TcxCustomLookAndFeelPainter::DrawScaledCheck(ACanvas, R, AState, ACheckState, AColor, AScaleFactor); }
	inline void __fastcall  DrawScaledCheck(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, bool AChecked, System::Uitypes::TColor AColor, Cxgeometry::TdxScaleFactor* AScaleFactor){ TcxCustomLookAndFeelPainter::DrawScaledCheck(ACanvas, R, AState, AChecked, AColor, AScaleFactor); }
	inline void __fastcall  DrawFooterBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R){ TcxCustomLookAndFeelPainter::DrawFooterBorder(ACanvas, R); }
	inline void __fastcall  DrawFooterCell(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, System::Classes::TAlignment AAlignmentHorz, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AMultiLine, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor, TcxDrawBackgroundEvent AOnDrawBackground = 0x0){ TcxCustomLookAndFeelPainter::DrawFooterCell(ACanvas, ABounds, AAlignmentHorz, AAlignmentVert, AMultiLine, AText, AFont, ATextColor, ABkColor, AOnDrawBackground); }
	inline void __fastcall  DrawScaledIndicatorItem(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, const System::Types::TRect &AImageAreaBounds, TcxIndicatorKind AKind, System::Uitypes::TColor AColor, Cxgeometry::TdxScaleFactor* AScaleFactor, TcxDrawBackgroundEvent AOnDrawBackground = 0x0, TcxNeighbors ANeighbors = (TcxNeighbors() << TcxNeighbor::nTop << TcxNeighbor::nBottom ), int ABorderWidth = 0x1){ TcxCustomLookAndFeelPainter::DrawScaledIndicatorItem(ACanvas, R, AImageAreaBounds, AKind, AColor, AScaleFactor, AOnDrawBackground, ANeighbors, ABorderWidth); }
	inline void __fastcall  DrawScaledIndicatorItem(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxIndicatorKind AKind, System::Uitypes::TColor AColor, Cxgeometry::TdxScaleFactor* AScaleFactor, TcxDrawBackgroundEvent AOnDrawBackground = 0x0, int ABorderWidth = 0x1){ TcxCustomLookAndFeelPainter::DrawScaledIndicatorItem(ACanvas, R, AKind, AColor, AScaleFactor, AOnDrawBackground, ABorderWidth); }
	inline void __fastcall  DoDrawSizeGrip(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect){ TcxCustomLookAndFeelPainter::DoDrawSizeGrip(ACanvas, ARect); }
	inline void __fastcall  DrawScaledToggleSwitchState(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, TcxButtonState AState, bool AChecked, Cxgeometry::TdxScaleFactor* AScaleFactor){ TcxCustomLookAndFeelPainter::DrawScaledToggleSwitchState(ACanvas, ABounds, AState, AChecked, AScaleFactor); }
	inline void __fastcall  DrawScaledToggleSwitchThumb(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, TcxButtonState AState, Cxgeometry::TdxScaleFactor* AScaleFactor){ TcxCustomLookAndFeelPainter::DrawScaledToggleSwitchThumb(ACanvas, ABounds, AState, AScaleFactor); }
	inline void __fastcall  DrawFindPanelBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgeometry::TcxBorders ABorders, Cxgeometry::TdxScaleFactor* AScaleFactor){ TcxCustomLookAndFeelPainter::DrawFindPanelBorder(ACanvas, R, ABorders, AScaleFactor); }
	
};

#pragma pack(pop)

typedef Dxgenerics::TdxObjectList__1<TcxCustomLookAndFeelPainter*>* TcxCustomLookAndFeelPainterList;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxLookAndFeelPaintersManager : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxCustomLookAndFeelPainter* operator[](int Index) { return this->Items[Index]; }
	
private:
	System::Classes::TInterfaceList* FListeners;
	int FLockCount;
	Cxclasses::TcxObjectList* FPainters;
	System::StaticArray<TcxCustomLookAndFeelPainter*, 6> FStandardPainters;
	int __fastcall GetCount();
	TcxCustomLookAndFeelPainter* __fastcall GetItem(int AIndex);
	static int __fastcall CompareProc(TcxCustomLookAndFeelPainter* AItem1, TcxCustomLookAndFeelPainter* AItem2);
	
protected:
	void __fastcall DoPainterAdded(TcxCustomLookAndFeelPainter* APainter);
	void __fastcall DoPainterRemoved(TcxCustomLookAndFeelPainter* APainter);
	void __fastcall DoRootLookAndFeelChanged();
	void __fastcall ReleaseImageResources();
	void __fastcall SortPainters();
	__property System::Classes::TInterfaceList* Listeners = {read=FListeners};
	__property Cxclasses::TcxObjectList* Painters = {read=FPainters};
	
public:
	__fastcall virtual TcxLookAndFeelPaintersManager();
	__fastcall virtual ~TcxLookAndFeelPaintersManager();
	void __fastcall AddListener(const _di_IcxLookAndFeelPainterListener AListener);
	void __fastcall RemoveListener(const _di_IcxLookAndFeelPainterListener AListener);
	void __fastcall BeginUpdate();
	void __fastcall CancelUpdate();
	void __fastcall EndUpdate();
	TcxCustomLookAndFeelPainter* __fastcall GetPainter(TcxLookAndFeelStyle AStyle)/* overload */;
	bool __fastcall GetPainter(TcxLookAndFeelStyle AStyle, /* out */ TcxCustomLookAndFeelPainter* &APainter)/* overload */;
	TcxCustomLookAndFeelPainter* __fastcall GetPainter(const System::UnicodeString AName)/* overload */;
	bool __fastcall GetPainter(const System::UnicodeString AName, /* out */ TcxCustomLookAndFeelPainter* &APainter)/* overload */;
	void __fastcall PopulateSkinNames(System::Classes::TStrings* AList);
	bool __fastcall Register(TcxCustomLookAndFeelPainter* APainter);
	bool __fastcall Unregister(const System::UnicodeString AName);
	__property int Count = {read=GetCount, nodefault};
	__property TcxCustomLookAndFeelPainter* Items[int Index] = {read=GetItem/*, default*/};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static const System::Int8 cxContainerMaxBorderWidth = System::Int8(0x2);
static const System::Int8 cxTextOffset = System::Int8(0x2);
static const System::Int8 cxTextOffsetHalf = System::Int8(0x1);
static const System::Int8 cxHeaderTextOffset = System::Int8(0x2);
static const System::Int8 cxArrowLeftBasePointIndex = System::Int8(0x0);
static const System::Int8 cxArrowTopPointIndex = System::Int8(0x1);
static const System::Int8 cxArrowRightBasePointIndex = System::Int8(0x2);
static const System::Int8 cxStdThumbnailMinimalSize = System::Int8(0x8);
static const System::Int8 cxInplaceNavigatorDefaultOffset = System::Int8(0x32);
static const System::Int8 cxTouchElementMinSize = System::Int8(0x1b);
static const System::Int8 cxGridDefaultIndicatorWidth = System::Int8(0xc);
static const System::Int8 dxcidCustomControl = System::Int8(0x0);
static const System::Int8 dxcidTextEdit = System::Int8(0x1);
static const System::Int8 dxcidComboBox = System::Int8(0x2);
static const System::Int8 dxcidImageComboBox = System::Int8(0x3);
static const System::Int8 dxcidCheckComboBox = System::Int8(0x4);
static const System::Int8 dxcidListBox = System::Int8(0x5);
static const System::Int8 dxcidCheckListBox = System::Int8(0x6);
extern DELPHI_PACKAGE System::StaticArray<int, 7> cxContainerBorderWidths;
extern DELPHI_PACKAGE System::StaticArray<TcxEditStateColorKind, 2> cxEditStateColorKindMap;
extern DELPHI_PACKAGE void __fastcall dxAdjustToTouchableSize(int &AElementSizeDimension, Cxgeometry::TdxScaleFactor* AScaleFactor = (Cxgeometry::TdxScaleFactor*)(0x0))/* overload */;
extern DELPHI_PACKAGE void __fastcall dxAdjustToTouchableSize(System::Types::TSize &AElementSize, Cxgeometry::TdxScaleFactor* AScaleFactor = (Cxgeometry::TdxScaleFactor*)(0x0))/* overload */;
extern DELPHI_PACKAGE int __fastcall dxGetTouchableSize(int AElementSizeDimension, Cxgeometry::TdxScaleFactor* AScaleFactor = (Cxgeometry::TdxScaleFactor*)(0x0))/* overload */;
extern DELPHI_PACKAGE System::Types::TSize __fastcall dxGetTouchableSize(const System::Types::TSize &AElementSize, Cxgeometry::TdxScaleFactor* AScaleFactor = (Cxgeometry::TdxScaleFactor*)(0x0))/* overload */;
extern DELPHI_PACKAGE bool __fastcall dxElementSizeFitsForTouch(int AElementSizeDimension)/* overload */;
extern DELPHI_PACKAGE bool __fastcall dxElementSizeFitsForTouch(int AElementSizeDimension, Cxgeometry::TdxScaleFactor* AScaleFactor)/* overload */;
extern DELPHI_PACKAGE System::Types::TRect __fastcall cxTextRect(const System::Types::TRect &R);
extern DELPHI_PACKAGE Dxcore::TPoints __fastcall cxGetSchedulerGroupPolygon(const System::Types::TRect &R);
extern DELPHI_PACKAGE Dxcore::TPoints __fastcall cxGetSchedulerMilestonePolygon(const System::Types::TRect &R);
extern DELPHI_PACKAGE void __fastcall PrepareRadioButtonImageList(Cxgeometry::TdxScaleFactor* AScaleFactor);
extern DELPHI_PACKAGE void __fastcall dxRotateSizeGrip(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, System::Uitypes::TColor ABackgroundColor, Dxcore::TdxCorner ACorner, TdxDrawEvent AOnDrawSizeGrip)/* overload */;
extern DELPHI_PACKAGE void __fastcall dxRotateSizeGrip(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxgeometry::TdxScaleFactor* AScaleFactor, System::Uitypes::TColor ABackgroundColor, Dxcore::TdxCorner ACorner, TdxDrawScaledRectEvent AOnDrawSizeGrip)/* overload */;
extern DELPHI_PACKAGE void __fastcall UpdateScrollBarBitmaps(void);
extern DELPHI_PACKAGE void __fastcall dxInitBordersScaleFactor(Cxgeometry::TdxScaleFactor* AScaleFactor, Cxgeometry::TdxScaleFactor* &ABordersScaleFactor);
extern DELPHI_PACKAGE Cxgraphics::TcxImageList* __fastcall cxDataRowFixingImages(void);
extern DELPHI_PACKAGE Vcl::Imglist::TCustomImageList* __fastcall cxIndicatorImages(void);
extern DELPHI_PACKAGE TcxLookAndFeelPaintersManager* __fastcall cxLookAndFeelPaintersManager(void);
extern DELPHI_PACKAGE int __fastcall BtnStateToXPBtnState(TcxButtonState AState);
}	/* namespace Cxlookandfeelpainters */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXLOOKANDFEELPAINTERS)
using namespace Cxlookandfeelpainters;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxlookandfeelpaintersHPP
