// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxSpellCheckerCore.pas' rev: 35.00 (Windows)

#ifndef DxspellcheckercoreHPP
#define DxspellcheckercoreHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Types.hpp>
#include <Winapi.Windows.hpp>
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Graphics.hpp>
#include <System.Generics.Defaults.hpp>
#include <System.Generics.Collections.hpp>
#include <System.SyncObjs.hpp>
#include <dxCore.hpp>
#include <dxCoreClasses.hpp>
#include <cxClasses.hpp>
#include <dxCultureInfo.hpp>
#include <dxXMLDoc.hpp>
#include <dxGenerics.hpp>
#include <System.UITypes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Dxspellcheckercore
{
//-- forward type declarations -----------------------------------------------
__interface DELPHIINTERFACE IdxSpellCheckerPosition;
typedef System::DelphiInterface<IdxSpellCheckerPosition> _di_IdxSpellCheckerPosition;
__interface DELPHIINTERFACE IdxSpellCheckerIgnoreList;
typedef System::DelphiInterface<IdxSpellCheckerIgnoreList> _di_IdxSpellCheckerIgnoreList;
__interface DELPHIINTERFACE IdxSpellChecker;
typedef System::DelphiInterface<IdxSpellChecker> _di_IdxSpellChecker;
__interface DELPHIINTERFACE IdxSpellChecker2;
typedef System::DelphiInterface<IdxSpellChecker2> _di_IdxSpellChecker2;
__interface DELPHIINTERFACE IdxSpellCheckTextController;
typedef System::DelphiInterface<IdxSpellCheckTextController> _di_IdxSpellCheckTextController;
__interface DELPHIINTERFACE IdxDisabledSpellChecking;
typedef System::DelphiInterface<IdxDisabledSpellChecking> _di_IdxDisabledSpellChecking;
__interface DELPHIINTERFACE IdxSpellCheckerAdapter;
typedef System::DelphiInterface<IdxSpellCheckerAdapter> _di_IdxSpellCheckerAdapter;
__interface DELPHIINTERFACE IdxSpellCheckerAutoCorrectCustomRule;
typedef System::DelphiInterface<IdxSpellCheckerAutoCorrectCustomRule> _di_IdxSpellCheckerAutoCorrectCustomRule;
struct TdxSpellCheckerAutoCorrectWordRange;
struct TdxSpellCheckerAutoCorrectWordInfo;
template<typename T> class DELPHICLASS TdxSpellCheckerPosition__1;
class DELPHICLASS TdxSpellCheckerIntegerPosition;
class DELPHICLASS TdxSpellCheckCustomSimpleTextController;
class DELPHICLASS TdxSpellCheckerReplacement;
class DELPHICLASS TdxSpellCheckerReplacementList;
class DELPHICLASS TdxSpellCheckerCustomOptions;
class DELPHICLASS TdxSpellCheckerCustomCheckAsYouTypeOptions;
class DELPHICLASS TdxSpellCheckerAutoCorrectExceptions;
class DELPHICLASS TdxSpellCheckerAutoCorrectReplacementList;
class DELPHICLASS TdxSpellCheckerCustomAutoCorrectOptions;
__interface DELPHIINTERFACE IdxSpellingErrorInfo;
typedef System::DelphiInterface<IdxSpellingErrorInfo> _di_IdxSpellingErrorInfo;
__interface DELPHIINTERFACE IdxSpellChecker3CheckCallbackProc;
typedef System::DelphiInterface<IdxSpellChecker3CheckCallbackProc> _di_IdxSpellChecker3CheckCallbackProc;
__interface DELPHIINTERFACE IdxSpellChecker3;
typedef System::DelphiInterface<IdxSpellChecker3> _di_IdxSpellChecker3;
__interface DELPHIINTERFACE IdxSpellCheckerControl;
typedef System::DelphiInterface<IdxSpellCheckerControl> _di_IdxSpellCheckerControl;
class DELPHICLASS TdxSpellingErrorInfo;
class DELPHICLASS TdxSpellCheckerInstance;
class DELPHICLASS TdxSpellCheckerAdapters;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TdxSpellingError : unsigned char { seUnknown, seMisspelling, seRepeating, seSyntax };

__interface  INTERFACE_UUID("{BB627A9B-8F90-4725-BA2B-070D426638E5}") IdxSpellCheckerPosition  : public System::IInterface 
{
	virtual _di_IdxSpellCheckerPosition __fastcall Add(_di_IdxSpellCheckerPosition APosition) = 0 ;
	virtual int __fastcall Compare(_di_IdxSpellCheckerPosition APosition) = 0 ;
	virtual bool __fastcall Equals(System::TObject* AObj) = 0 ;
	virtual _di_IdxSpellCheckerPosition __fastcall MoveBackward() = 0 ;
	virtual _di_IdxSpellCheckerPosition __fastcall MoveForward() = 0 ;
	virtual _di_IdxSpellCheckerPosition __fastcall Subtract(_di_IdxSpellCheckerPosition APosition) = 0 ;
	virtual int __fastcall ToInteger() = 0 ;
};

__interface  INTERFACE_UUID("{2A154D04-E45A-4604-88FB-4251FF09AA1A}") IdxSpellCheckerIgnoreList  : public System::IInterface 
{
	virtual void __fastcall Add(const System::UnicodeString AWord) = 0 /* overload */;
	virtual void __fastcall Add(const _di_IdxSpellCheckerPosition AStart, const _di_IdxSpellCheckerPosition AEnd, const System::UnicodeString AWord) = 0 /* overload */;
	virtual void __fastcall Clear() = 0 ;
	virtual bool __fastcall Contains(const System::UnicodeString AWord) = 0 /* overload */;
	virtual bool __fastcall Contains(const _di_IdxSpellCheckerPosition AStart, const _di_IdxSpellCheckerPosition AEnd, const System::UnicodeString AWord) = 0 /* overload */;
	virtual void __fastcall Remove(const System::UnicodeString AWord) = 0 /* overload */;
	virtual void __fastcall Remove(const _di_IdxSpellCheckerPosition AStart, const _di_IdxSpellCheckerPosition AEnd, const System::UnicodeString AWord) = 0 /* overload */;
};

__interface  INTERFACE_UUID("{4515FCEE-2D09-4709-A170-E29C556355BF}") IdxSpellChecker  : public System::IInterface 
{
	virtual void __fastcall CheckFinish() = 0 ;
	virtual void __fastcall CheckStart(Vcl::Controls::TWinControl* AControl) = 0 ;
	virtual void __fastcall DrawMisspellings(Vcl::Controls::TWinControl* AControl, HDC DC = (HDC)(0x0)) = 0 ;
	virtual bool __fastcall IsSpellCheckerDialogControl(NativeUInt AWnd) = 0 ;
	virtual void __fastcall KeyPress(System::WideChar AKey) = 0 ;
	virtual void __fastcall LayoutChanged(Vcl::Controls::TWinControl* AControl) = 0 ;
	virtual bool __fastcall QueryPopup(System::Classes::TComponent* APopup, const System::Types::TPoint &P) = 0 ;
	virtual void __fastcall SelectionChanged(Vcl::Controls::TWinControl* AControl) = 0 ;
	virtual void __fastcall TextChanged(Vcl::Controls::TWinControl* AControl) = 0 ;
	virtual void __fastcall Undo() = 0 ;
};

__interface  INTERFACE_UUID("{0480D25C-94DA-449D-BBE6-B771C76D0BB1}") IdxSpellChecker2  : public System::IInterface 
{
	virtual void __fastcall KeyDown(System::Word AKey, System::Classes::TShiftState Shift) = 0 ;
	virtual void __fastcall KeyUp(System::Word AKey, System::Classes::TShiftState Shift) = 0 ;
};

__interface  INTERFACE_UUID("{3FD54262-F944-467D-8067-FC644916AF3F}") IdxSpellCheckTextController  : public System::IInterface 
{
	virtual _di_IdxSpellCheckerPosition __fastcall CreatePosition(int ALogPosition) = 0 ;
	virtual bool __fastcall GetNextWord(_di_IdxSpellCheckerPosition &AStart, _di_IdxSpellCheckerPosition &AFinish) = 0 ;
	virtual _di_IdxSpellCheckerPosition __fastcall GetSentenceFinishPosition(const _di_IdxSpellCheckerPosition APos) = 0 ;
	virtual _di_IdxSpellCheckerPosition __fastcall GetSentenceStartPosition(const _di_IdxSpellCheckerPosition APos) = 0 ;
	virtual _di_IdxSpellCheckerPosition __fastcall GetWordFinishPosition(const _di_IdxSpellCheckerPosition APos) = 0 ;
	virtual _di_IdxSpellCheckerPosition __fastcall GetWordStartPosition(const _di_IdxSpellCheckerPosition APos) = 0 ;
	virtual System::UnicodeString __fastcall GetWord(const _di_IdxSpellCheckerPosition AStart, const _di_IdxSpellCheckerPosition AFinish) = 0 ;
	virtual bool __fastcall IsRangeEditable(const _di_IdxSpellCheckerPosition AStart, const _di_IdxSpellCheckerPosition AFinish) = 0 ;
	virtual void __fastcall SetSpellingArea(const _di_IdxSpellCheckerPosition AStart, const _di_IdxSpellCheckerPosition AFinish) = 0 ;
};

__interface  INTERFACE_UUID("{5578E450-1237-41F5-8085-1372A492F13B}") IdxDisabledSpellChecking  : public System::IInterface 
{
	
};

__interface  INTERFACE_UUID("{77231A5B-7883-4119-B6E1-D8A9884036AB}") IdxSpellCheckerAdapter  : public System::IInterface 
{
	virtual _di_IdxSpellCheckTextController __fastcall CreateController() = 0 ;
	virtual Vcl::Controls::TWinControl* __fastcall GetEdit() = 0 ;
	virtual NativeUInt __fastcall GetEditorHandle() = 0 ;
	virtual bool __fastcall GetHideSelection() = 0 ;
	virtual bool __fastcall GetReadOnly() = 0 ;
	virtual void __fastcall GetSelection(/* out */ _di_IdxSpellCheckerPosition &AStart, /* out */ _di_IdxSpellCheckerPosition &AFinish) = 0 ;
	virtual void __fastcall GetSpellingBounds(/* out */ _di_IdxSpellCheckerPosition &AStart, /* out */ _di_IdxSpellCheckerPosition &AFinish) = 0 ;
	virtual void __fastcall Post(bool AUpdateValue = true) = 0 ;
	virtual void __fastcall Replace(_di_IdxSpellCheckerPosition &AStart, _di_IdxSpellCheckerPosition &AFinish, const System::UnicodeString AWord, _di_IdxSpellCheckerPosition &ASpellingStart, _di_IdxSpellCheckerPosition &ASpellingFinish) = 0 ;
	virtual void __fastcall SetHideSelection(bool AValue) = 0 ;
	virtual void __fastcall SetSelection(const _di_IdxSpellCheckerPosition AStart, const _di_IdxSpellCheckerPosition AFinish) = 0 ;
	virtual void __fastcall UpdateController(_di_IdxSpellCheckTextController AController) = 0 ;
	__property Vcl::Controls::TWinControl* Edit = {read=GetEdit};
	__property NativeUInt EditorHandle = {read=GetEditorHandle};
	__property bool HideSelection = {read=GetHideSelection, write=SetHideSelection};
	__property bool ReadOnly = {read=GetReadOnly};
};

__interface  INTERFACE_UUID("{6B517ADE-8B34-4FBF-91B6-BD14146A995F}") IdxSpellCheckerAutoCorrectCustomRule  : public System::IInterface 
{
	virtual void __fastcall AfterCorrect() = 0 ;
	virtual void __fastcall Undo() = 0 ;
};

typedef TdxSpellCheckerAutoCorrectWordRange *PdxSpellCheckerAutoCorrectWordRange;

struct DECLSPEC_DRECORD TdxSpellCheckerAutoCorrectWordRange
{
public:
	System::UnicodeString Replacement;
	int SelStart;
	int SelLength;
	int NewSelStart;
	static bool __fastcall _op_Equality(const TdxSpellCheckerAutoCorrectWordRange &R1, const TdxSpellCheckerAutoCorrectWordRange &R2);
	static bool __fastcall _op_Inequality(const TdxSpellCheckerAutoCorrectWordRange &R1, const TdxSpellCheckerAutoCorrectWordRange &R2);
	
	friend bool operator ==(const TdxSpellCheckerAutoCorrectWordRange &R1, const TdxSpellCheckerAutoCorrectWordRange &R2) { return TdxSpellCheckerAutoCorrectWordRange::_op_Equality(R1, R2); }
	friend bool operator !=(const TdxSpellCheckerAutoCorrectWordRange &R1, const TdxSpellCheckerAutoCorrectWordRange &R2) { return TdxSpellCheckerAutoCorrectWordRange::_op_Inequality(R1, R2); }
};


struct DECLSPEC_DRECORD TdxSpellCheckerAutoCorrectWordInfo
{
public:
	System::WideChar LastKey;
	int CursorLogPosition;
	_di_IdxSpellCheckerPosition SpellingAreaFinish;
	_di_IdxSpellCheckerPosition SpellingAreaStart;
	System::UnicodeString Word;
	_di_IdxSpellCheckerPosition WordPositionFinish;
	_di_IdxSpellCheckerPosition WordPositionStart;
	_di_IdxSpellCheckerAutoCorrectCustomRule Rule;
	static TdxSpellCheckerAutoCorrectWordInfo __fastcall Create()/* overload */;
	static TdxSpellCheckerAutoCorrectWordInfo __fastcall Create(const TdxSpellCheckerAutoCorrectWordRange &AWordRange, const _di_IdxSpellCheckTextController ATextController)/* overload */;
	void __fastcall Reset();
	TdxSpellCheckerAutoCorrectWordRange __fastcall ToWordRange();
};


#pragma pack(push,4)
// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename T> class PASCALIMPLEMENTATION TdxSpellCheckerPosition__1 : public System::TInterfacedObject
{
	typedef System::TInterfacedObject inherited;
	
private:
	static _di_IdxSpellCheckerPosition __fastcall GetNull();
	static _di_IdxSpellCheckerPosition __fastcall GetUndefined();
	bool __fastcall GetIsZero();
	bool __fastcall GetIsNegative();
	bool __fastcall GetIsPositive();
	
protected:
	virtual T __fastcall GetActualPosition() = 0 ;
	virtual int __fastcall GetActualPositionHashCode() = 0 ;
	virtual void __fastcall SetActualPosition(const T Value) = 0 ;
	virtual _di_IdxSpellCheckerPosition __fastcall GetZero();
	virtual int __fastcall Compare(_di_IdxSpellCheckerPosition APosition) = 0 /* overload */;
	virtual _di_IdxSpellCheckerPosition __fastcall MoveBackward() = 0 ;
	virtual _di_IdxSpellCheckerPosition __fastcall MoveForward() = 0 ;
	__property T ActualPosition = {read=GetActualPosition, write=SetActualPosition};
	__property _di_IdxSpellCheckerPosition Zero = {read=GetZero};
	
public:
	__fastcall virtual TdxSpellCheckerPosition__1(const T AActualPosition)/* overload */;
	virtual _di_IdxSpellCheckerPosition __fastcall Add(_di_IdxSpellCheckerPosition APosition) = 0 ;
	virtual _di_IdxSpellCheckerPosition __fastcall Clone() = 0 ;
	virtual _di_IdxSpellCheckerPosition __fastcall Subtract(_di_IdxSpellCheckerPosition APosition) = 0 ;
	virtual int __fastcall ToInteger() = 0 ;
	virtual bool __fastcall Equals(System::TObject* AObj)/* overload */;
	virtual int __fastcall GetHashCode();
	static int __fastcall Compare(const _di_IdxSpellCheckerPosition APosition1, const _di_IdxSpellCheckerPosition APosition2)/* overload */;
	static bool __fastcall IsGreater(const _di_IdxSpellCheckerPosition APosition1, const _di_IdxSpellCheckerPosition APosition2);
	static bool __fastcall IsGreaterOrEqual(const _di_IdxSpellCheckerPosition APosition1, const _di_IdxSpellCheckerPosition APosition2);
	static bool __fastcall IsLess(const _di_IdxSpellCheckerPosition APosition1, const _di_IdxSpellCheckerPosition APosition2);
	static bool __fastcall IsLessOrEqual(const _di_IdxSpellCheckerPosition APosition1, const _di_IdxSpellCheckerPosition APosition2);
	__property bool IsZero = {read=GetIsZero, nodefault};
	__property bool IsNegative = {read=GetIsNegative, nodefault};
	__property bool IsPositive = {read=GetIsPositive, nodefault};
	/* static */ __property _di_IdxSpellCheckerPosition Null = {read=GetNull};
	/* static */ __property _di_IdxSpellCheckerPosition Undefined = {read=GetUndefined};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSpellCheckerPosition__1() { }
	
private:
	void *__IdxSpellCheckerPosition;	// IdxSpellCheckerPosition 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {BB627A9B-8F90-4725-BA2B-070D426638E5}
	operator _di_IdxSpellCheckerPosition()
	{
		_di_IdxSpellCheckerPosition intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IdxSpellCheckerPosition*(void) { return (IdxSpellCheckerPosition*)&__IdxSpellCheckerPosition; }
	#endif
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSpellCheckerIntegerPosition : public TdxSpellCheckerPosition__1<int>
{
	typedef TdxSpellCheckerPosition__1<int> inherited;
	
protected:
	int FValue;
	virtual int __fastcall GetActualPosition();
	virtual int __fastcall GetActualPositionHashCode();
	virtual void __fastcall SetActualPosition(const int Value);
	virtual int __fastcall Compare(_di_IdxSpellCheckerPosition APosition)/* overload */;
	virtual _di_IdxSpellCheckerPosition __fastcall MoveBackward();
	virtual _di_IdxSpellCheckerPosition __fastcall MoveForward();
	
public:
	virtual _di_IdxSpellCheckerPosition __fastcall Add(_di_IdxSpellCheckerPosition APosition);
	virtual _di_IdxSpellCheckerPosition __fastcall Clone();
	virtual _di_IdxSpellCheckerPosition __fastcall Subtract(_di_IdxSpellCheckerPosition APosition);
	virtual int __fastcall ToInteger();
public:
	/* {dxSpellCheckerCore}TdxSpellCheckerPosition<System_Integer>.Create */ inline __fastcall virtual TdxSpellCheckerIntegerPosition(const int AActualPosition)/* overload */ : TdxSpellCheckerPosition__1<int>(AActualPosition) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSpellCheckerIntegerPosition() { }
	
	/* Hoisted overloads: */
	
public:
	inline int __fastcall  Compare(const _di_IdxSpellCheckerPosition APosition1, const _di_IdxSpellCheckerPosition APosition2){ return TdxSpellCheckerPosition__1<int>::Compare(APosition1, APosition2); }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSpellCheckCustomSimpleTextController : public System::TInterfacedObject
{
	typedef System::TInterfacedObject inherited;
	
protected:
	int FSpellingAreaFinish;
	int FSpellingAreaStart;
	System::UnicodeString FText;
	_di_IdxSpellCheckerPosition __fastcall CreatePosition(int AValue);
	int __fastcall DecodePosition(const _di_IdxSpellCheckerPosition AValue);
	bool __fastcall DecodePositions(const _di_IdxSpellCheckerPosition AStart, const _di_IdxSpellCheckerPosition AFinish, int &AIndex, int &ACount);
	_di_IdxSpellCheckerPosition __fastcall EncodePosition(const int AValue);
	
public:
	__fastcall TdxSpellCheckCustomSimpleTextController(const System::UnicodeString AText);
	virtual bool __fastcall GetNextWord(_di_IdxSpellCheckerPosition &AStart, _di_IdxSpellCheckerPosition &AFinish) = 0 ;
	virtual _di_IdxSpellCheckerPosition __fastcall GetSentenceFinishPosition(const _di_IdxSpellCheckerPosition APos) = 0 ;
	virtual _di_IdxSpellCheckerPosition __fastcall GetSentenceStartPosition(const _di_IdxSpellCheckerPosition APos) = 0 ;
	virtual _di_IdxSpellCheckerPosition __fastcall GetWordFinishPosition(const _di_IdxSpellCheckerPosition APos) = 0 ;
	virtual _di_IdxSpellCheckerPosition __fastcall GetWordStartPosition(const _di_IdxSpellCheckerPosition APos) = 0 ;
	virtual System::UnicodeString __fastcall GetWord(const _di_IdxSpellCheckerPosition AStart, const _di_IdxSpellCheckerPosition AFinish);
	virtual bool __fastcall IsRangeEditable(const _di_IdxSpellCheckerPosition AStart, const _di_IdxSpellCheckerPosition AFinish);
	virtual void __fastcall SetSpellingArea(const _di_IdxSpellCheckerPosition AStart, const _di_IdxSpellCheckerPosition AFinish);
	__property System::UnicodeString Text = {read=FText, write=FText};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSpellCheckCustomSimpleTextController() { }
	
private:
	void *__IdxSpellCheckTextController;	// IdxSpellCheckTextController 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {3FD54262-F944-467D-8067-FC644916AF3F}
	operator _di_IdxSpellCheckTextController()
	{
		_di_IdxSpellCheckTextController intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IdxSpellCheckTextController*(void) { return (IdxSpellCheckTextController*)&__IdxSpellCheckTextController; }
	#endif
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSpellCheckerReplacement : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::UnicodeString FReplacement;
	System::UnicodeString FText;
	
public:
	__fastcall TdxSpellCheckerReplacement(const System::UnicodeString AText, const System::UnicodeString AReplacement);
	void __fastcall ChangeReplacement(const System::UnicodeString S);
	__property System::UnicodeString Replacement = {read=FReplacement};
	__property System::UnicodeString Text = {read=FText};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSpellCheckerReplacement() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSpellCheckerReplacementList : public Cxclasses::TcxObjectList
{
	typedef Cxclasses::TcxObjectList inherited;
	
public:
	TdxSpellCheckerReplacement* operator[](int Index) { return this->Items[Index]; }
	
private:
	bool FAllowDuplicates;
	HIDESBASE TdxSpellCheckerReplacement* __fastcall GetItem(int Index);
	
public:
	__fastcall TdxSpellCheckerReplacementList(bool AllowDuplicates);
	HIDESBASE void __fastcall Add(const System::UnicodeString AText, const System::UnicodeString AReplacement);
	TdxSpellCheckerReplacement* __fastcall FindReplacement(const System::UnicodeString AText);
	void __fastcall SortByText();
	__property TdxSpellCheckerReplacement* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxSpellCheckerReplacementList() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSpellCheckerCustomOptions : public Dxcoreclasses::TcxOwnedPersistent
{
	typedef Dxcoreclasses::TcxOwnedPersistent inherited;
	
private:
	Dxcoreclasses::TdxMulticastMethod__1<System::Classes::TNotifyEvent> FOnChanged;
	
protected:
	virtual void __fastcall InitializeOptions();
	void __fastcall Changed();
	virtual void __fastcall DoChanged();
	
public:
	__fastcall virtual TdxSpellCheckerCustomOptions(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TdxSpellCheckerCustomOptions();
	void __fastcall AddChangedHandler(System::Classes::TNotifyEvent AHandler);
	void __fastcall RemoveChangedHandler(System::Classes::TNotifyEvent AHandler);
};

#pragma pack(pop)

enum DECLSPEC_DENUM TdxSpellCheckerUnderlineStyle : unsigned char { usAuto, usWavyLine, usLine };

enum DECLSPEC_DENUM TdxSpellCheckerPopupMenuItem : unsigned char { scmiAddToDictionary, scmiAutoCorrect, scmiDelete, scmiIgnoreAll, scmiSpelling, scmiSuggestions, scmiIgnore };

typedef System::Set<TdxSpellCheckerPopupMenuItem, TdxSpellCheckerPopupMenuItem::scmiAddToDictionary, TdxSpellCheckerPopupMenuItem::scmiIgnore> TdxSpellCheckerPopupMenuItems;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSpellCheckerCustomCheckAsYouTypeOptions : public TdxSpellCheckerCustomOptions
{
	typedef TdxSpellCheckerCustomOptions inherited;
	
private:
	#define TdxSpellCheckerCustomCheckAsYouTypeOptions_DefaultPopupMenuItems (System::Set<TdxSpellCheckerPopupMenuItem, TdxSpellCheckerPopupMenuItem::scmiAddToDictionary, TdxSpellCheckerPopupMenuItem::scmiIgnore>() << TdxSpellCheckerPopupMenuItem::scmiAddToDictionary << TdxSpellCheckerPopupMenuItem::scmiAutoCorrect << TdxSpellCheckerPopupMenuItem::scmiDelete << TdxSpellCheckerPopupMenuItem::scmiIgnoreAll << TdxSpellCheckerPopupMenuItem::scmiSpelling << TdxSpellCheckerPopupMenuItem::scmiSuggestions << TdxSpellCheckerPopupMenuItem::scmiIgnore )
	
	bool FActive;
	TdxSpellCheckerPopupMenuItems FPopupMenuItems;
	int FSuggestionCount;
	System::Uitypes::TColor FUnderlineColor;
	TdxSpellCheckerUnderlineStyle FUnderlineStyle;
	void __fastcall SetActive(bool AValue);
	void __fastcall SetPopupMenuItems(TdxSpellCheckerPopupMenuItems AValue);
	void __fastcall SetSuggestionCount(int AValue);
	void __fastcall SetUnderlineColor(System::Uitypes::TColor AValue);
	void __fastcall SetUnderlineStyle(TdxSpellCheckerUnderlineStyle AValue);
	
protected:
	virtual void __fastcall DoActiveChanged() = 0 ;
	virtual void __fastcall DoAssign(System::Classes::TPersistent* Source);
	virtual void __fastcall InitializeOptions();
	
__published:
	__property bool Active = {read=FActive, write=SetActive, default=0};
	__property TdxSpellCheckerPopupMenuItems PopupMenuItems = {read=FPopupMenuItems, write=SetPopupMenuItems, default=127};
	__property int SuggestionCount = {read=FSuggestionCount, write=SetSuggestionCount, default=5};
	__property System::Uitypes::TColor UnderlineColor = {read=FUnderlineColor, write=SetUnderlineColor, default=255};
	__property TdxSpellCheckerUnderlineStyle UnderlineStyle = {read=FUnderlineStyle, write=SetUnderlineStyle, default=0};
public:
	/* TdxSpellCheckerCustomOptions.Create */ inline __fastcall virtual TdxSpellCheckerCustomCheckAsYouTypeOptions(System::Classes::TPersistent* AOwner) : TdxSpellCheckerCustomOptions(AOwner) { }
	/* TdxSpellCheckerCustomOptions.Destroy */ inline __fastcall virtual ~TdxSpellCheckerCustomCheckAsYouTypeOptions() { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TdxSpellCheckerAutoCorrectExceptionAddEvent)(TdxSpellCheckerAutoCorrectExceptions* Sender, System::WideString &AException, bool &AAllow);

typedef void __fastcall (__closure *TdxSpellCheckerAutoCorrectExceptionDeleteEvent)(TdxSpellCheckerAutoCorrectExceptions* Sender, const System::WideString AException, bool &AAllow);

class PASCALIMPLEMENTATION TdxSpellCheckerAutoCorrectExceptions : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	System::UnicodeString operator[](int Index) { return this->Exceptions[Index]; }
	
private:
	bool FAutoInclude;
	int FCount;
	Dxcore::TdxPWideCharArray *FList;
	_RTL_CRITICAL_SECTION FLock;
	TdxSpellCheckerCustomAutoCorrectOptions* FOptions;
	TdxSpellCheckerAutoCorrectExceptionAddEvent FOnAdd;
	TdxSpellCheckerAutoCorrectExceptionDeleteEvent FOnDelete;
	System::UnicodeString __fastcall GetException(int Index);
	
protected:
	void __fastcall DisposeException(System::WideChar * AException);
	bool __fastcall DoAdd(System::UnicodeString &AException);
	bool __fastcall DoDelete(const System::UnicodeString AException);
	virtual void __fastcall SetCount(int AValue);
	__property TdxSpellCheckerAutoCorrectExceptionAddEvent OnAdd = {read=FOnAdd, write=FOnAdd};
	__property TdxSpellCheckerAutoCorrectExceptionDeleteEvent OnDelete = {read=FOnDelete, write=FOnDelete};
	
public:
	__fastcall virtual TdxSpellCheckerAutoCorrectExceptions(TdxSpellCheckerCustomAutoCorrectOptions* AOptions);
	__fastcall virtual ~TdxSpellCheckerAutoCorrectExceptions();
	int __fastcall Add(const System::UnicodeString AException);
	void __fastcall Clear();
	void __fastcall Delete(int AIndex)/* overload */;
	void __fastcall Delete(const System::UnicodeString AException)/* overload */;
	int __fastcall Find(const System::UnicodeString AException);
	void __fastcall LoadFromFile(const System::UnicodeString AFileName);
	void __fastcall LoadFromStream(System::Classes::TStream* AStream);
	void __fastcall PopulateExceptions(System::Classes::TStrings* AList);
	void __fastcall SaveToFile(const System::UnicodeString AFileName);
	void __fastcall SaveToStream(System::Classes::TStream* AStream);
	__property bool AutoInclude = {read=FAutoInclude, write=FAutoInclude, nodefault};
	__property int Count = {read=FCount, nodefault};
	__property System::UnicodeString Exceptions[int Index] = {read=GetException/*, default*/};
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSpellCheckerAutoCorrectReplacementList : public TdxSpellCheckerReplacementList
{
	typedef TdxSpellCheckerReplacementList inherited;
	
public:
	void __fastcall LoadFromFile(const System::UnicodeString AFileName);
	void __fastcall LoadFromStream(System::Classes::TStream* AStream);
	void __fastcall SaveToFile(const System::UnicodeString AFileName);
	void __fastcall SaveToStream(System::Classes::TStream* AStream);
public:
	/* TdxSpellCheckerReplacementList.Create */ inline __fastcall TdxSpellCheckerAutoCorrectReplacementList(bool AllowDuplicates) : TdxSpellCheckerReplacementList(AllowDuplicates) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxSpellCheckerAutoCorrectReplacementList() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSpellCheckerCustomAutoCorrectOptions : public TdxSpellCheckerCustomOptions
{
	typedef TdxSpellCheckerCustomOptions inherited;
	
private:
	bool FActive;
	bool FAutomaticallyUseSuggestions;
	bool FCorrectCapsLock;
	bool FCorrectInitialCaps;
	bool FCorrectSentenceCaps;
	bool FDisableCapsLock;
	TdxSpellCheckerAutoCorrectExceptions* FFirstLetterExceptions;
	TdxSpellCheckerAutoCorrectExceptions* FInitialCapsExceptions;
	TdxSpellCheckerAutoCorrectReplacementList* FReplacements;
	bool FReplaceTextAsYouType;
	void __fastcall FirstLetterExceptionAddHandler(TdxSpellCheckerAutoCorrectExceptions* Sender, System::WideString &AException, bool &AAllow);
	void __fastcall InitialCapsExceptionAddHandler(TdxSpellCheckerAutoCorrectExceptions* Sender, System::WideString &AException, bool &AAllow);
	void __fastcall SetActive(const bool AValue);
	void __fastcall SetAutomaticallyUseSuggestions(const bool AValue);
	void __fastcall SetCorrectCapsLock(const bool AValue);
	void __fastcall SetCorrectInitialCaps(const bool AValue);
	void __fastcall SetCorrectSentenceCaps(const bool AValue);
	void __fastcall SetDisableCapsLock(const bool AValue);
	void __fastcall SetReplaceTextAsYouType(const bool AValue);
	
protected:
	virtual void __fastcall DoActiveChanged() = 0 ;
	virtual void __fastcall DoAssign(System::Classes::TPersistent* Source);
	virtual void __fastcall InitializeOptions();
	
public:
	__fastcall virtual ~TdxSpellCheckerCustomAutoCorrectOptions();
	__property TdxSpellCheckerAutoCorrectExceptions* FirstLetterExceptions = {read=FFirstLetterExceptions};
	__property TdxSpellCheckerAutoCorrectExceptions* InitialCapsExceptions = {read=FInitialCapsExceptions};
	__property TdxSpellCheckerAutoCorrectReplacementList* Replacements = {read=FReplacements};
	
__published:
	__property bool Active = {read=FActive, write=SetActive, default=0};
	__property bool AutomaticallyUseSuggestions = {read=FAutomaticallyUseSuggestions, write=SetAutomaticallyUseSuggestions, default=1};
	__property bool CorrectCapsLock = {read=FCorrectCapsLock, write=SetCorrectCapsLock, default=1};
	__property bool CorrectInitialCaps = {read=FCorrectInitialCaps, write=SetCorrectInitialCaps, default=1};
	__property bool CorrectSentenceCaps = {read=FCorrectSentenceCaps, write=SetCorrectSentenceCaps, default=1};
	__property bool DisableCapsLock = {read=FDisableCapsLock, write=SetDisableCapsLock, default=0};
	__property bool ReplaceTextAsYouType = {read=FReplaceTextAsYouType, write=SetReplaceTextAsYouType, default=1};
public:
	/* TdxSpellCheckerCustomOptions.Create */ inline __fastcall virtual TdxSpellCheckerCustomAutoCorrectOptions(System::Classes::TPersistent* AOwner) : TdxSpellCheckerCustomOptions(AOwner) { }
	
};

#pragma pack(pop)

__interface  INTERFACE_UUID("{7AE6DEBF-8CE4-4AFA-BEC5-DBC52AB69015}") IdxSpellingErrorInfo  : public System::IInterface 
{
	virtual TdxSpellingError __fastcall GetError() = 0 ;
	virtual System::UnicodeString __fastcall GetWord() = 0 ;
	virtual _di_IdxSpellCheckerPosition __fastcall GetWordEndPosition() = 0 ;
	virtual _di_IdxSpellCheckerPosition __fastcall GetWordStartPosition() = 0 ;
	__property TdxSpellingError Error = {read=GetError};
	__property System::UnicodeString Word = {read=GetWord};
	__property _di_IdxSpellCheckerPosition WordEndPosition = {read=GetWordEndPosition};
	__property _di_IdxSpellCheckerPosition WordStartPosition = {read=GetWordStartPosition};
};

__interface IdxSpellChecker3CheckCallbackProc  : public System::IInterface 
{
	virtual bool __fastcall Invoke(_di_IdxSpellingErrorInfo AErrorInfo) = 0 ;
};

__interface  INTERFACE_UUID("{45807494-4396-401D-ADE2-6FC4312700D6}") IdxSpellChecker3  : public System::IInterface 
{
	virtual TdxSpellCheckerCustomAutoCorrectOptions* __fastcall GetAutoCorrectOptions() = 0 ;
	virtual TdxSpellCheckerCustomCheckAsYouTypeOptions* __fastcall GetCheckAsYouTypeOptions() = 0 ;
	virtual bool __fastcall AutoCorrect(Vcl::Controls::TWinControl* AControl, const _di_IdxSpellCheckTextController AController, TdxSpellCheckerAutoCorrectWordInfo &AInfo) = 0 ;
	virtual bool __fastcall CheckAsync(Vcl::Controls::TWinControl* AControl, const _di_IdxSpellCheckTextController AController, const _di_IdxSpellCheckerPosition AFrom, const _di_IdxSpellCheckerPosition ATo, _di_IdxSpellChecker3CheckCallbackProc AProc, const System::UnicodeString APrevWord = System::UnicodeString()) = 0 ;
	virtual void __fastcall CheckControl(Vcl::Controls::TWinControl* AControl) = 0 ;
	virtual System::DynamicArray<System::UnicodeString> __fastcall GetSuggestions(const System::UnicodeString AWord) = 0 ;
	virtual bool __fastcall IsDialogCheckMode() = 0 ;
	virtual void __fastcall AddToDictionary(const System::UnicodeString AWord) = 0 ;
	virtual bool __fastcall CanAddToDictionary() = 0 ;
	virtual void __fastcall Ignore(Vcl::Controls::TControl* AControl, const System::UnicodeString AWord, const _di_IdxSpellCheckerPosition AStart, const _di_IdxSpellCheckerPosition AEnd) = 0 ;
	virtual void __fastcall IgnoreAll(Vcl::Controls::TControl* AControl, const System::UnicodeString AWord) = 0 ;
	virtual void __fastcall AddDialogCheckModeChangeHandler(System::Classes::TNotifyEvent AEvent) = 0 ;
	virtual void __fastcall RemoveDialogCheckModeChangeHandler(System::Classes::TNotifyEvent AEvent) = 0 ;
	virtual void __fastcall AddSpellingOptionsChangedHandler(System::Classes::TNotifyEvent AEvent) = 0 ;
	virtual void __fastcall RemoveSpellingOptionsChangedHandler(System::Classes::TNotifyEvent AEvent) = 0 ;
	virtual void __fastcall RegisterIgnoreList(Vcl::Controls::TControl* AControl, const _di_IdxSpellCheckerIgnoreList AIgnoreList) = 0 ;
	virtual void __fastcall UnregisterIgnoreList(Vcl::Controls::TControl* AControl) = 0 ;
	__property TdxSpellCheckerCustomAutoCorrectOptions* AutoCorrectOptions = {read=GetAutoCorrectOptions};
	__property TdxSpellCheckerCustomCheckAsYouTypeOptions* CheckAsYouTypeOptions = {read=GetCheckAsYouTypeOptions};
};

__interface  INTERFACE_UUID("{2DEA4CCA-3C6D-4283-9441-AABBD61F74F3}") IdxSpellCheckerControl  : public System::IInterface 
{
	virtual bool __fastcall SupportsSpelling() = 0 ;
	virtual void __fastcall SetSelText(const System::UnicodeString AText, bool APost = false) = 0 ;
	virtual void __fastcall SetIsBarControl(bool AValue) = 0 ;
	virtual void __fastcall SetValue(const System::Variant &AValue) = 0 ;
};

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSpellingErrorInfo : public System::TInterfacedObject
{
	typedef System::TInterfacedObject inherited;
	
private:
	TdxSpellingError FError;
	System::UnicodeString FWord;
	_di_IdxSpellCheckerPosition FWordEndPosition;
	_di_IdxSpellCheckerPosition FWordStartPosition;
	
protected:
	TdxSpellingError __fastcall GetError();
	System::UnicodeString __fastcall GetWord();
	_di_IdxSpellCheckerPosition __fastcall GetWordEndPosition();
	_di_IdxSpellCheckerPosition __fastcall GetWordStartPosition();
	
public:
	__fastcall TdxSpellingErrorInfo(const System::UnicodeString AWord, const _di_IdxSpellCheckerPosition AStart, const _di_IdxSpellCheckerPosition AEnd, TdxSpellingError AError);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSpellingErrorInfo() { }
	
private:
	void *__IdxSpellingErrorInfo;	// IdxSpellingErrorInfo 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {7AE6DEBF-8CE4-4AFA-BEC5-DBC52AB69015}
	operator _di_IdxSpellingErrorInfo()
	{
		_di_IdxSpellingErrorInfo intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IdxSpellingErrorInfo*(void) { return (IdxSpellingErrorInfo*)&__IdxSpellingErrorInfo; }
	#endif
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSpellCheckerInstance : /*[[sealed]]*/ public System::TObject
{
	typedef System::TObject inherited;
	
private:
	static _di_IdxSpellChecker FISpellChecker;
	static _di_IdxSpellChecker2 FISpellChecker2;
	static _di_IdxSpellChecker3 FISpellChecker3;
	static System::Generics::Collections::TList__1<System::Classes::TNotifyEvent>* FListeners;
	
public:
	__classmethod void __fastcall CheckFinish();
	__classmethod void __fastcall CheckStart(Vcl::Controls::TWinControl* AControl);
	__classmethod void __fastcall DrawMisspellings(Vcl::Controls::TWinControl* AControl, HDC DC = (HDC)(0x0));
	__classmethod void __fastcall LayoutChanged(Vcl::Controls::TWinControl* AControl);
	__classmethod void __fastcall SelectionChanged(Vcl::Controls::TWinControl* AControl);
	__classmethod void __fastcall TextChanged(Vcl::Controls::TWinControl* AControl);
	__classmethod void __fastcall Undo();
	__classmethod void __fastcall SetInstance(System::TObject* const AInstance);
	__classmethod void __fastcall RegisterListener(System::Classes::TNotifyEvent AListener);
	__classmethod void __fastcall UnregisterListener(System::Classes::TNotifyEvent AListener);
	/* static */ __property _di_IdxSpellChecker ISpellChecker = {read=FISpellChecker};
	/* static */ __property _di_IdxSpellChecker2 ISpellChecker2 = {read=FISpellChecker2};
	/* static */ __property _di_IdxSpellChecker3 ISpellChecker3 = {read=FISpellChecker3};
	
private:
	// __classmethod void __fastcall Create@();
	// __classmethod void __fastcall Destroy@();
public:
	/* TObject.Create */ inline __fastcall TdxSpellCheckerInstance() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSpellCheckerInstance() { }
	
};

#pragma pack(pop)

typedef _di_IdxSpellCheckerAdapter __fastcall (__closure *TdxSpellCheckerCreateAdapterProc)(System::TObject* AObject);

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSpellCheckerAdapters : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	static Dxgenerics::TdxClassDictionary__1<TdxSpellCheckerCreateAdapterProc>* FAdapters;
	__classmethod bool __fastcall FindAdapter(System::TObject* AObject, /* out */ TdxSpellCheckerCreateAdapterProc &AProc);
	
public:
	__classmethod bool __fastcall CreateAdapter(System::TObject* AObject, /* out */ _di_IdxSpellCheckerAdapter &AAdapter);
	__classmethod bool __fastcall IsSupported(Vcl::Controls::TWinControl* AControl);
	__classmethod void __fastcall Register(System::TClass AClass, TdxSpellCheckerCreateAdapterProc AProc);
	__classmethod void __fastcall Unregister(System::TClass AClass);
public:
	/* TObject.Create */ inline __fastcall TdxSpellCheckerAdapters() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSpellCheckerAdapters() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxspellcheckercore */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSPELLCHECKERCORE)
using namespace Dxspellcheckercore;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxspellcheckercoreHPP
