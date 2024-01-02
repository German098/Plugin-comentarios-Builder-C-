// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxAnimation.pas' rev: 35.00 (Windows)

#ifndef DxanimationHPP
#define DxanimationHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.Windows.hpp>
#include <System.Types.hpp>
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <Vcl.Graphics.hpp>
#include <System.Math.hpp>
#include <dxCore.hpp>
#include <dxCoreGraphics.hpp>
#include <cxClasses.hpp>
#include <dxGDIPlusAPI.hpp>
#include <dxGDIPlusClasses.hpp>
#include <cxGeometry.hpp>
#include <cxGraphics.hpp>
#include <Vcl.Forms.hpp>
#include <dxSmartImage.hpp>
#include <cxCustomCanvas.hpp>

//-- user supplied -----------------------------------------------------------

namespace Dxanimation
{
//-- forward type declarations -----------------------------------------------
__interface DELPHIINTERFACE IdxAnimationListener;
typedef System::DelphiInterface<IdxAnimationListener> _di_IdxAnimationListener;
class DELPHICLASS TdxAnimationController;
class DELPHICLASS TdxAnimationTransition;
class DELPHICLASS TdxImageAnimationTransition;
class DELPHICLASS TdxRectAnimationTransition;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TdxDrawAnimationMode : unsigned char { amScrollLeft, amScrollUp, amScrollRight, amScrollDown, amFade, amSegmentedFade, amRandomSegmentedFade, amScrollLeftFade, amScrollUpFade, amScrollRightFade, amScrollDownFade };

enum DECLSPEC_DENUM TdxAnimationTransitionEffect : unsigned char { ateLinear, ateAccelerateDecelerate, ateCubic, ateTanh, ateBack, ateBounce, ateCircle, ateElastic, ateExponential, ateSine, ateQuadratic, ateQuartic, ateCustom };

enum DECLSPEC_DENUM TdxAnimationTransitionEffectMode : unsigned char { atmIn, atmOut, atmInOut };

typedef void __fastcall (__closure *TdxAnimationEvent)(TdxAnimationTransition* Sender, int &APosition, bool &AFinished);

typedef int __fastcall (*TdxAnimationTransitionEffectProc)(TdxAnimationTransition* Sender, const __int64 AValue, const __int64 AMaxValue, const int ALength);

__interface  INTERFACE_UUID("{0CAAD87B-8A4B-464B-A738-1340BD80C3D8}") IdxAnimationListener  : public System::IInterface 
{
	virtual void __fastcall AfterAnimation(TdxAnimationController* Sender) = 0 ;
	virtual void __fastcall BeforeAnimation(TdxAnimationController* Sender) = 0 ;
	virtual void __fastcall DestroyAnimation(TdxAnimationTransition* Animation) = 0 ;
};

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAnimationController : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Cxclasses::TcxObjectList* FAnimations;
	int FActiveAnimations;
	bool FDebugMode;
	System::Classes::_di_IInterfaceList FListenerList;
	Cxclasses::TcxTimer* FTimer;
	bool FTimerHandling;
	TdxAnimationTransition* __fastcall GetAnimation(int AIndex);
	int __fastcall GetCount();
	void __fastcall SetDebugMode(bool AValue);
	
protected:
	void __fastcall CheckTimer();
	void __fastcall Resume(TdxAnimationTransition* Animation);
	void __fastcall Suspend(TdxAnimationTransition* Animation);
	virtual void __fastcall TimerHandler(System::TObject* Sender);
	void __fastcall Terminate(TdxAnimationTransition* Animation);
	__property TdxAnimationTransition* Animations[int Index] = {read=GetAnimation};
	__property int ActiveAnimations = {read=FActiveAnimations, write=FActiveAnimations, nodefault};
	__property int Count = {read=GetCount, nodefault};
	__property System::Classes::_di_IInterfaceList ListenerList = {read=FListenerList};
	__property Cxclasses::TcxTimer* Timer = {read=FTimer, write=FTimer};
	__property bool DebugMode = {read=FDebugMode, write=SetDebugMode, nodefault};
	
public:
	__fastcall virtual TdxAnimationController();
	__fastcall virtual ~TdxAnimationController();
	void __fastcall Add(TdxAnimationTransition* Animation);
	void __fastcall AddListener(_di_IdxAnimationListener AListener);
	void __fastcall Remove(TdxAnimationTransition* Animation);
	void __fastcall RemoveListener(_di_IdxAnimationListener AListener);
	void __fastcall Update();
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TdxAnimationTransition : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FIsAnimate;
	__int64 FCurrent;
	__int64 FFinish;
	bool FFinished;
	bool FFreeOnTerminate;
	int FLength;
	int FLockCount;
	int FPosition;
	bool FPositionChanged;
	__int64 FStart;
	unsigned FTime;
	unsigned FTimerInterval;
	TdxAnimationTransitionEffect FTransitionEffect;
	TdxAnimationTransitionEffectProc FTransitionEffectProc;
	TdxAnimationTransitionEffectMode FTransitionEffectMode;
	TdxAnimationEvent FOnAfterAnimate;
	TdxAnimationEvent FOnAnimate;
	TdxAnimationEvent FOnBeforeAnimate;
	System::Classes::TNotifyEvent FOnTerminate;
	bool __fastcall GetFinished();
	bool __fastcall GetSuspended();
	void __fastcall SetFinished(bool AValue);
	
protected:
	System::TObject* FInfo;
	void __fastcall Animate();
	void __fastcall InitializeTime();
	virtual void __fastcall InitializeTransitionEffectProc();
	virtual bool __fastcall IsCompatible(TdxAnimationTransition* Animation);
	virtual void __fastcall DoAfterAnimate();
	virtual void __fastcall DoAnimate();
	virtual void __fastcall DoBeforeAnimate();
	void __fastcall TryAnimate();
	__property __int64 Current = {read=FCurrent, write=FCurrent};
	__property __int64 Finish = {read=FFinish, write=FFinish};
	__property int Length = {read=FLength, nodefault};
	__property __int64 Start = {read=FStart, write=FStart};
	__property unsigned TimerInterval = {read=FTimerInterval, write=FTimerInterval, nodefault};
	__property TdxAnimationTransitionEffectMode TransitionEffectMode = {read=FTransitionEffectMode, nodefault};
	
public:
	__fastcall virtual TdxAnimationTransition(unsigned ATime, TdxAnimationTransitionEffect ATransitionEffect, int ALength, TdxAnimationTransitionEffectMode ATransitionEffectMode);
	__fastcall virtual ~TdxAnimationTransition();
	void __fastcall ImmediateAnimation();
	virtual void __fastcall RefreshAnimatedObject();
	void __fastcall Resume();
	void __fastcall Suspend(bool AFinished = false);
	void __fastcall Terminate();
	__property TdxAnimationTransitionEffect TransitionEffect = {read=FTransitionEffect, nodefault};
	__property TdxAnimationTransitionEffectProc TransitionEffectProc = {read=FTransitionEffectProc};
	__property bool Finished = {read=GetFinished, write=SetFinished, nodefault};
	__property bool FreeOnTerminate = {read=FFreeOnTerminate, write=FFreeOnTerminate, nodefault};
	__property System::TObject* Info = {read=FInfo, write=FInfo};
	__property int Position = {read=FPosition, nodefault};
	__property bool PositionChanged = {read=FPositionChanged, write=FPositionChanged, nodefault};
	__property bool Suspended = {read=GetSuspended, nodefault};
	__property unsigned Time = {read=FTime, nodefault};
	__property TdxAnimationEvent OnAfterAnimate = {read=FOnAfterAnimate, write=FOnAfterAnimate};
	__property TdxAnimationEvent OnAnimate = {read=FOnAnimate, write=FOnAnimate};
	__property TdxAnimationEvent OnBeforeAnimate = {read=FOnBeforeAnimate, write=FOnBeforeAnimate};
	__property System::Classes::TNotifyEvent OnTerminate = {read=FOnTerminate, write=FOnTerminate};
};


typedef void __fastcall (__closure *TdxImageAnimationTransitionDrawProc)(Cxcustomcanvas::TcxCustomCanvas* ACanvas, int ALeft, int ATop, int AWidth, int AHeight, int APosition);

class PASCALIMPLEMENTATION TdxImageAnimationTransition : public TdxAnimationTransition
{
	typedef TdxAnimationTransition inherited;
	
private:
	Cxgraphics::TcxBitmap32* FBuffer;
	TdxImageAnimationTransitionDrawProc FDrawProc;
	TdxDrawAnimationMode FMode;
	int __fastcall CalculateLength(int ALength, int AWidth, int AHeight);
	void __fastcall InitializeDrawProc();
	
public:
	__fastcall virtual TdxImageAnimationTransition(Vcl::Graphics::TGraphic* AStartImage, Vcl::Graphics::TGraphic* AFinishImage, unsigned ATime, TdxDrawAnimationMode AMode, TdxAnimationTransitionEffect ATransition, int ALength, bool AFreeImagesOnTerminate, bool ADoubleBuffered)/* overload */;
	__fastcall virtual TdxImageAnimationTransition(Dxcoregraphics::TdxCustomFastDIB* AStartImage, Dxcoregraphics::TdxCustomFastDIB* AFinishImage, unsigned ATime, TdxDrawAnimationMode AMode, TdxAnimationTransitionEffect ATransition, int ALength, bool AFreeImagesOnTerminate, bool ADoubleBuffered)/* overload */;
	__fastcall virtual ~TdxImageAnimationTransition();
	void __fastcall Draw(Cxcustomcanvas::TcxCustomCanvas* ACanvas, const System::Types::TRect &ADestRect);
	void __fastcall DrawTransparent(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ADestRect);
	__property TdxDrawAnimationMode Mode = {read=FMode, nodefault};
};


class PASCALIMPLEMENTATION TdxRectAnimationTransition : public TdxAnimationTransition
{
	typedef TdxAnimationTransition inherited;
	
private:
	System::Types::TRect FSourceRect;
	System::Types::TRect FTargetRect;
	System::Types::TRect __fastcall GetCurrentRect();
	
public:
	__fastcall TdxRectAnimationTransition(const System::Types::TRect &ASourceRect, const System::Types::TRect &ATargetRect, unsigned ATime, TdxAnimationTransitionEffect ATransitionEffect, TdxAnimationTransitionEffectMode ATransitionEffectMode);
	__property System::Types::TRect CurrentRect = {read=GetCurrentRect};
	__property System::Types::TRect SourceRect = {read=FSourceRect, write=FSourceRect};
	__property System::Types::TRect TargetRect = {read=FTargetRect, write=FTargetRect};
public:
	/* TdxAnimationTransition.Destroy */ inline __fastcall virtual ~TdxRectAnimationTransition() { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE TdxAnimationController* __fastcall dxAnimationController(void);
extern DELPHI_PACKAGE __int64 __fastcall dxMulDiv64(const __int64 nNumber, const __int64 nNumerator, const __int64 nDenominator);
extern DELPHI_PACKAGE __int64 __fastcall dxGetExactTickCount(void);
extern DELPHI_PACKAGE unsigned __fastcall dxGetExactTime(const __int64 AExactTickCount);
extern DELPHI_PACKAGE __int64 __fastcall dxTimeToTickCount(const unsigned ATime);
}	/* namespace Dxanimation */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXANIMATION)
using namespace Dxanimation;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxanimationHPP
