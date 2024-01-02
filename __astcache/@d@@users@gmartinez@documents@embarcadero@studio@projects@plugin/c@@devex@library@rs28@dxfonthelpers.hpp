// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxFontHelpers.pas' rev: 35.00 (Windows)

#ifndef DxfonthelpersHPP
#define DxfonthelpersHPP

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
#include <System.Win.ComObj.hpp>
#include <Winapi.ActiveX.hpp>
#include <Vcl.Graphics.hpp>
#include <System.Classes.hpp>
#include <System.Generics.Defaults.hpp>
#include <System.Generics.Collections.hpp>
#include <cxClasses.hpp>
#include <dxCoreClasses.hpp>
#include <dxCoreGraphics.hpp>
#include <dxDocumentLayoutUnitConverter.hpp>
#include <cxGraphics.hpp>
#include <dxGenerics.hpp>
#include <System.UITypes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Dxfonthelpers
{
//-- forward type declarations -----------------------------------------------
__interface DELPHIINTERFACE IdxMLangCodePages;
typedef System::DelphiInterface<IdxMLangCodePages> _di_IdxMLangCodePages;
__interface DELPHIINTERFACE IdxMLangFontLink;
typedef System::DelphiInterface<IdxMLangFontLink> _di_IdxMLangFontLink;
struct TdxUnicodeSubrange;
class DELPHICLASS TdxUnicodeRangeInfo;
struct TdxFontCharacterRange;
class DELPHICLASS TdxFontCharacterSet;
struct TdxSupportedFontStylesInfo;
__interface DELPHIINTERFACE IdxFontsContainer;
typedef System::DelphiInterface<IdxFontsContainer> _di_IdxFontsContainer;
class DELPHICLASS TdxFontInfo;
class DELPHICLASS TdxFontInfoMeasurer;
class DELPHICLASS TdxTrueTypeFontInfo;
class DELPHICLASS TdxFontCache;
class DELPHICLASS TdxFontCacheManager;
class DELPHICLASS TdxFontLink;
//-- type declarations -------------------------------------------------------
__interface  INTERFACE_UUID("{359F3443-BD4A-11D0-B188-00AA0038C969}") IdxMLangCodePages  : public System::IInterface 
{
	virtual HRESULT __stdcall GetCharCodePages(const System::WideChar chSrc, /* out */ unsigned &pdwCodePages) = 0 ;
	virtual HRESULT __stdcall GetStrCodePages(const System::WideChar * pszSrc, const unsigned cchSrc, unsigned dwPriorityCodePages, /* out */ unsigned &pdwCodePages, /* out */ unsigned &pcchCodePages) = 0 ;
	virtual HRESULT __stdcall CodePageToCodePages(const unsigned uCodePage, /* out */ unsigned &pdwCodePages) = 0 ;
	virtual HRESULT __stdcall CodePagesToCodePage(const unsigned dwCodePages, const unsigned uDefaultCodePage, /* out */ unsigned &puCodePage) = 0 ;
};

__interface  INTERFACE_UUID("{359F3441-BD4A-11D0-B188-00AA0038C969}") IdxMLangFontLink  : public IdxMLangCodePages 
{
	virtual HRESULT __stdcall GetFontCodePages(const NativeUInt hDC, const NativeUInt hFont, /* out */ unsigned &pdwCodePages) = 0 ;
	virtual HRESULT __stdcall MapFont(const NativeUInt hDC, const unsigned dwCodePages, NativeUInt hSrcFont, /* out */ NativeUInt &phDestFont) = 0 ;
	virtual HRESULT __stdcall ReleaseFont(const NativeUInt hFont) = 0 ;
	virtual HRESULT __stdcall ResetFontMapping() = 0 ;
};

enum DECLSPEC_DENUM TdxTextDirection : unsigned char { LeftToRightTopToBottom, TopToBottomRightToLeft, TopToBottomLeftToRightRotated, BottomToTopLeftToRight, LeftToRightTopToBottomRotated, TopToBottomRightToLeftRotated };

enum DECLSPEC_DENUM TdxVerticalAlignment : unsigned char { Top, Both, Center, Bottom };

struct DECLSPEC_DRECORD TdxUnicodeSubrange
{
public:
	System::WideChar LowValue;
	System::WideChar HiValue;
	int Bit;
	bool __fastcall ContainsChar(System::WideChar ACharacter);
};


typedef TdxUnicodeSubrange *PdxUnicodeSubrange;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxUnicodeRangeInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FCapacity;
	int FCount;
	System::DynamicArray<TdxUnicodeSubrange> FRanges;
	void __fastcall SetCapacity(int AValue);
	
protected:
	void __fastcall AddSubrange(System::WideChar AStartCharacter, System::WideChar AEndCharacter, int ABit);
	void __fastcall Grow();
	void __fastcall PopulateSubranges();
	
public:
	__fastcall TdxUnicodeRangeInfo();
	__fastcall virtual ~TdxUnicodeRangeInfo();
	PdxUnicodeSubrange __fastcall LookupSubrange(System::WideChar ACharacter);
	__property int Capacity = {read=FCapacity, write=SetCapacity, nodefault};
	__property int Count = {read=FCount, nodefault};
};

#pragma pack(pop)

struct DECLSPEC_DRECORD TdxFontCharacterRange
{
public:
	int Low;
	int Hi;
	void __fastcall CopyFrom(int ALow, int AHi)/* overload */;
	void __fastcall CopyFrom(const tagWCRANGE ARange)/* overload */;
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFontCharacterSet : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Classes::TBits* FBits;
	void __fastcall AddRange(const TdxFontCharacterRange &AFontCharacterRange);
	
protected:
	tagPANOSE FPanose;
	__property System::Classes::TBits* Bits = {read=FBits};
	
public:
	__fastcall TdxFontCharacterSet(const System::DynamicArray<TdxFontCharacterRange> ARanges, const tagPANOSE &APanose);
	__fastcall virtual ~TdxFontCharacterSet();
	__classmethod int __fastcall CalculatePanoseDistance(TdxFontCharacterSet* const AFontCharacterSet1, TdxFontCharacterSet* const AFontCharacterSet2);
	bool __fastcall ContainsChar(System::WideChar C);
};

#pragma pack(pop)

enum DECLSPEC_DENUM TdxSupportedFontStyle : unsigned char { Regular, Bold, Italic, Underline, Strikeout, BoldItalic };

typedef System::Set<TdxSupportedFontStyle, TdxSupportedFontStyle::Regular, TdxSupportedFontStyle::BoldItalic> TdxSupportedFontStyles;

struct DECLSPEC_DRECORD TdxSupportedFontStylesInfo
{
public:
	TdxSupportedFontStyles SupportedStyles;
	System::StaticArray<bool, 6> NativeStyles;
};


__interface IdxFontsContainer  : public System::IInterface 
{
	virtual TdxFontCache* __fastcall GetFontCache() = 0 ;
	__property TdxFontCache* FontCache = {read=GetFontCache};
};

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFontInfo : public System::TObject
{
	typedef System::TObject inherited;
	
	
protected:
	class DELPHICLASS TCharacterDrawingAbilityTable;
	class PASCALIMPLEMENTATION TCharacterDrawingAbilityTable : public System::TObject
	{
		typedef System::TObject inherited;
		
	private:
		System::Classes::TBits* FDrawingAbility;
		System::Classes::TBits* FCalculated;
		
	public:
		__fastcall TCharacterDrawingAbilityTable();
		__fastcall virtual ~TCharacterDrawingAbilityTable();
		void __fastcall SetDrawingAbility(System::WideChar ACharacter, bool AValue);
		bool __fastcall GetDrawingAbility(System::WideChar ACharacter, /* out */ bool &AAbility);
	};
	
	
	typedef System::StaticArray<unsigned, 4> TGdiSubrangeBits;
	
	#pragma pack(push,8)
	struct DECLSPEC_DRECORD TUnicodeSubrangeBits
	{
	private:
		static const System::Int8 BitPerDWORD = System::Int8(0x20);
		
		
	public:
		TdxFontInfo::TGdiSubrangeBits Data;
		bool __fastcall GetBit(int AIndex);
		void __fastcall SetBit(int AIndex, const bool Value);
		void __fastcall Clear();
		__property bool Bits[int Index] = {read=GetBit, write=SetBit};
	};
	#pragma pack(pop)
	
	
	
private:
	bool FApplyCjkUnderline;
	int FAscent;
	int FBaseFontIndex;
	TCharacterDrawingAbilityTable* FCharacterDrawingAbilityTable;
	int FCharset;
	int FCjkUnderlinePosition;
	int FCjkUnderlineSize;
	int FDashWidth;
	int FDescent;
	int FDotWidth;
	int FDrawingOffset;
	int FEqualSignWidth;
	System::UnicodeString FFamilyName;
	int FFree;
	NativeUInt FGdiFontHandle;
	int FGdiOffset;
	bool FIsCJKFont;
	int FLineSpacing;
	float FMaxDigitWidth;
	int FMiddleDotWidth;
	System::UnicodeString FName;
	int FNonBreakingSpaceWidth;
	tagPANOSE FPanose;
	int FPilcrowSignWidth;
	float FSizeInPoints;
	int FSpaceWidth;
	int FStrikeoutPosition;
	int FStrikeoutThickness;
	System::Uitypes::TFontStyles FStyle;
	System::Types::TPoint FSubscriptOffset;
	System::Types::TSize FSubscriptSize;
	System::Types::TPoint FSuperscriptOffset;
	System::Types::TSize FSuperscriptSize;
	TdxSupportedFontStyles FSupportedStyles;
	bool FTrueType;
	int FUnderlinePosition;
	int FUnderlineThickness;
	int FUnderscoreWidth;
	TGdiSubrangeBits FUnicodeSubrangeBits;
	bool FUnicodeSubrangeBitsCalculated;
	bool FUseGetGlyphIndices;
	int __fastcall GetAscentAndFree();
	bool __fastcall GetBold();
	bool __fastcall GetItalic();
	bool __fastcall GetUnderline();
	
protected:
	virtual void __fastcall AdjustFontParameters();
	virtual bool __fastcall CalculateCanDrawCharacter(TdxUnicodeRangeInfo* AUnicodeRangeInfo, Vcl::Graphics::TCanvas* ACanvas, System::WideChar ACharacter);
	void __fastcall CalculateCJKFontParameters(Winapi::Windows::POutlineTextmetricW AOutlineTextMetric);
	int __fastcall CalculateFontCharset(TdxFontInfoMeasurer* AMeasurer);
	virtual void __fastcall CalculateFontParameters(TdxFontInfoMeasurer* AMeasurer, bool AAllowCjkCorrection, bool AIsOfficeFont);
	float __fastcall CalculateFontSizeInLayoutUnits(Dxcoregraphics::TdxGraphicUnit AFontUnit, Dxdocumentlayoutunitconverter::TdxDocumentLayoutUnitConverter* AUnitConverter);
	void __fastcall CalculateFontVerticalParameters(TdxFontInfoMeasurer* AMeasurer, bool AAllowCjkCorrection, bool AIsOfficeFont);
	float __fastcall CalculateMaxDigitWidth(TdxFontInfoMeasurer* AMeasurer);
	virtual TUnicodeSubrangeBits __fastcall CalculateSupportedUnicodeSubrangeBits(TdxUnicodeRangeInfo* AUnicodeRangeInfo, Vcl::Graphics::TCanvas* ACanvas);
	void __fastcall CalculateUnderlineAndStrikeoutParameters(const _OUTLINETEXTMETRICW &AOutlineTextmetric);
	virtual void __fastcall CreateFont(TdxFontInfoMeasurer* AMeasurer, const System::UnicodeString AName, int ASize, const System::Uitypes::TFontStyles AFontStyle, bool AIsOfficeFont);
	virtual TdxFontInfo* __fastcall GetBaseFontInfo(const _di_IdxFontsContainer AContainer);
	
public:
	__fastcall TdxFontInfo(TdxFontInfoMeasurer* AMeasurer, const System::UnicodeString AName, int ADoubleSize, const System::Uitypes::TFontStyles AFontStyle, bool AAllowCjkCorrection, bool AIsOfficeFont);
	__fastcall virtual ~TdxFontInfo();
	void __fastcall CalculateSubscriptOffset(TdxFontInfo* ABaseFontInfo);
	void __fastcall CalculateSuperscriptOffset(TdxFontInfo* ABaseFontInfo);
	virtual bool __fastcall CanDrawCharacter(TdxUnicodeRangeInfo* AUnicodeRangeInfo, Vcl::Graphics::TCanvas* ACanvas, System::WideChar ACharacter);
	int __fastcall GetBaseAscentAndFree(const _di_IdxFontsContainer AContainer);
	int __fastcall GetBaseDescent(const _di_IdxFontsContainer AContainer);
	static System::DynamicArray<TdxFontCharacterRange> __fastcall GetFontUnicodeRanges(HDC ADC, HFONT AFont);
	__property NativeUInt GdiFontHandle = {read=FGdiFontHandle, nodefault};
	__property tagPANOSE Panose = {read=FPanose};
	__property bool UseGetGlyphIndices = {read=FUseGetGlyphIndices, nodefault};
	__property int Ascent = {read=FAscent, nodefault};
	__property int AscentAndFree = {read=GetAscentAndFree, nodefault};
	__property int BaseFontIndex = {read=FBaseFontIndex, write=FBaseFontIndex, nodefault};
	__property bool Bold = {read=GetBold, nodefault};
	__property int Charset = {read=FCharset, nodefault};
	__property int DashWidth = {read=FDashWidth, nodefault};
	__property int Descent = {read=FDescent, nodefault};
	__property int DotWidth = {read=FDotWidth, nodefault};
	__property int DrawingOffset = {read=FDrawingOffset, write=FDrawingOffset, nodefault};
	__property int EqualSignWidth = {read=FEqualSignWidth, nodefault};
	__property System::UnicodeString FamilyName = {read=FFamilyName};
	__property int _Free = {read=FFree, nodefault};
	__property int GdiOffset = {read=FGdiOffset, write=FGdiOffset, nodefault};
	__property bool IsCJKFont = {read=FIsCJKFont, nodefault};
	__property bool Italic = {read=GetItalic, nodefault};
	__property int LineSpacing = {read=FLineSpacing, nodefault};
	__property float MaxDigitWidth = {read=FMaxDigitWidth};
	__property int MiddleDotWidth = {read=FMiddleDotWidth, nodefault};
	__property System::UnicodeString Name = {read=FName};
	__property int NonBreakingSpaceWidth = {read=FNonBreakingSpaceWidth, nodefault};
	__property int PilcrowSignWidth = {read=FPilcrowSignWidth, nodefault};
	__property float SizeInPoints = {read=FSizeInPoints};
	__property int SpaceWidth = {read=FSpaceWidth, nodefault};
	__property int StrikeoutPosition = {read=FStrikeoutPosition, nodefault};
	__property int StrikeoutThickness = {read=FStrikeoutThickness, nodefault};
	__property System::Uitypes::TFontStyles Style = {read=FStyle, nodefault};
	__property System::Types::TPoint SubscriptOffset = {read=FSubscriptOffset};
	__property System::Types::TSize SubscriptSize = {read=FSubscriptSize};
	__property System::Types::TPoint SuperscriptOffset = {read=FSuperscriptOffset};
	__property System::Types::TSize SuperscriptSize = {read=FSuperscriptSize};
	__property TdxSupportedFontStyles SupportedStyles = {read=FSupportedStyles, nodefault};
	__property bool Underline = {read=GetUnderline, nodefault};
	__property int UnderlinePosition = {read=FUnderlinePosition, nodefault};
	__property int UnderlineThickness = {read=FUnderlineThickness, nodefault};
	__property int UnderscoreWidth = {read=FUnderscoreWidth, nodefault};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFontInfoMeasurer : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	float FDpi;
	Vcl::Graphics::TCanvas* FCanvas;
	Dxdocumentlayoutunitconverter::TdxDocumentLayoutUnitConverter* FUnitConverter;
	
private:
	Vcl::Graphics::TCanvas* __fastcall CreateMeasureGraphics();
	
public:
	__fastcall virtual TdxFontInfoMeasurer(Dxdocumentlayoutunitconverter::TdxDocumentLayoutUnitConverter* AUnitConverter);
	__fastcall virtual ~TdxFontInfoMeasurer();
	int __fastcall MeasureCharacterWidth(System::WideChar ACharacter, TdxFontInfo* AFontInfo);
	float __fastcall MeasureCharacterWidthF(System::WideChar ACharacter, TdxFontInfo* AFontInfo);
	System::Types::TSize __fastcall MeasureString(const System::UnicodeString AText, TdxFontInfo* AFontInfo);
	float __fastcall MeasureMaxDigitWidthF(TdxFontInfo* AFontInfo);
	__property Vcl::Graphics::TCanvas* Canvas = {read=FCanvas};
	__property Dxdocumentlayoutunitconverter::TdxDocumentLayoutUnitConverter* UnitConverter = {read=FUnitConverter};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTrueTypeFontInfo : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	static const System::Word SymbolFontType = System::Word(0x100);
	
	static const System::Word FixedPitchFontType = System::Word(0x200);
	
	
private:
	System::UnicodeString FFontName;
	int FFontType;
	bool FSupportedStylesCalculated;
	TdxSupportedFontStylesInfo FSupportedStyles;
	TdxSupportedFontStylesInfo __fastcall GetSupportedFontStyles();
	TdxSupportedFontStylesInfo __fastcall GetStylesInfo();
	
public:
	__fastcall TdxTrueTypeFontInfo(const System::UnicodeString AFontName, const int AFontType);
	__property System::UnicodeString FontName = {read=FFontName};
	__property int FontType = {read=FFontType, nodefault};
	__property TdxSupportedFontStylesInfo StylesInfo = {read=GetStylesInfo};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxTrueTypeFontInfo() { }
	
};

#pragma pack(pop)

typedef System::Generics::Collections::TObjectDictionary__2<System::UnicodeString,TdxTrueTypeFontInfo*>* TdxSystemTrueTypeFontDictionary;

enum DECLSPEC_DENUM TdxCharacterFormattingScript : unsigned char { Normal, Subscript, Superscript };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFontCache : public System::TObject
{
	typedef System::TObject inherited;
	
	
private:
	class DELPHICLASS TTrueTypeFontLoader;
	#pragma pack(push,8)
	class PASCALIMPLEMENTATION TTrueTypeFontLoader : public Cxclasses::TcxThread
	{
		typedef Cxclasses::TcxThread inherited;
		
	private:
		static int __stdcall EnumFontInfoProc(tagLOGFONTW &ALogFont, Winapi::Windows::PTextMetricW ATextMetric, int AFontType, TdxFontCache::TTrueTypeFontLoader* ACallingThread);
		TdxFontCharacterSet* __fastcall CreateFontCharacterSet(HDC ADC, const System::UnicodeString AFontName);
		bool __fastcall CanContinue();
		
	protected:
		virtual void __fastcall Execute();
	public:
		/* TcxThread.Create */ inline __fastcall TTrueTypeFontLoader(bool ACreateSuspended, bool ACreatePaused) : Cxclasses::TcxThread(ACreateSuspended, ACreatePaused) { }
		/* TcxThread.Destroy */ inline __fastcall virtual ~TTrueTypeFontLoader() { }
		
	};
	
	#pragma pack(pop)
	
	
public:
	TdxFontInfo* operator[](int Index) { return this->Items[Index]; }
	
public:
	static const System::Word SymbolFontType = System::Word(0x100);
	
	static const System::Word FixedPitchFontType = System::Word(0x200);
	
	
private:
	static TTrueTypeFontLoader* FLoader;
	static System::Generics::Collections::TObjectDictionary__2<System::UnicodeString,TdxFontCharacterSet*>* FNameToCharacterSetMap;
	static System::Generics::Collections::TObjectDictionary__2<System::UnicodeString,TdxTrueTypeFontInfo*>* FSystemTrueTypeFonts;
	static TdxUnicodeRangeInfo* FUnicodeRangeInfo;
	Dxgenerics::TdxStringIntegerDictionary* FCharsets;
	System::Generics::Collections::TDictionary__2<__int64,int>* FIndexHash;
	Dxcoreclasses::TdxFastObjectList* FItems;
	TdxFontInfoMeasurer* FMeasurer;
	Dxdocumentlayoutunitconverter::TdxDocumentLayoutUnitConverter* FUnitConverter;
	bool FUseOfficeFonts;
	int __fastcall GetCount();
	TdxFontInfo* __fastcall GetItem(int AIndex);
	
protected:
	__classmethod void __fastcall Initialize();
	__classmethod void __fastcall Finalize();
	virtual System::Generics::Collections::TObjectDictionary__2<System::UnicodeString,TdxTrueTypeFontInfo*>* __fastcall CreateOverrideFontSubstitutes();
	virtual TdxFontInfoMeasurer* __fastcall CreateFontInfoMeasurer(Dxdocumentlayoutunitconverter::TdxDocumentLayoutUnitConverter* AUnitConverter);
	TdxFontInfo* __fastcall CreateFontInfoCore(const System::UnicodeString AFontName, int ADoubleFontSize, const System::Uitypes::TFontStyles AFontStyle);
	int __fastcall CalcSubscriptFontSize(int ABaseFontIndex);
	int __fastcall CalcSuperscriptFontSize(int ABaseFontIndex);
	int __fastcall CalcSuperscriptFontIndex(const System::UnicodeString AFontName, int ADoubleFontSize, const System::Uitypes::TFontStyles AFontStyle);
	int __fastcall CalcSubscriptFontIndex(const System::UnicodeString AFontName, int ADoubleFontSize, const System::Uitypes::TFontStyles AFontStyle);
	int __fastcall CalcFontIndexCore(const System::UnicodeString AFontName, int ADoubleFontSize, const System::Uitypes::TFontStyles AFontStyle, TdxCharacterFormattingScript AScript);
	__int64 __fastcall CalcHash(const System::UnicodeString AFontName, int ADoubleFontSize, const System::Uitypes::TFontStyles AFontStyle, TdxCharacterFormattingScript AScript);
	int __fastcall CreateFontInfo(const __int64 AHash, const System::UnicodeString AFontName, int ADoubleFontSize, const System::Uitypes::TFontStyles AFontStyle);
	TdxFontCharacterSet* __fastcall CreateFontCharacterSet(const System::UnicodeString AFontName);
	System::DynamicArray<TdxFontCharacterRange> __fastcall GetFontCharacterRanges(TdxFontInfo* AFontInfo);
	__property System::Generics::Collections::TDictionary__2<__int64,int>* IndexHash = {read=FIndexHash};
	/* static */ __property System::Generics::Collections::TObjectDictionary__2<System::UnicodeString,TdxFontCharacterSet*>* NameToCharacterSetMap = {read=FNameToCharacterSetMap};
	/* static */ __property TdxUnicodeRangeInfo* UnicodeRangeInfo = {read=FUnicodeRangeInfo};
	
public:
	__fastcall virtual TdxFontCache(const Dxdocumentlayoutunitconverter::TdxDocumentLayoutUnit AUnit, const float ADpi, bool AUseOfficeFonts);
	__fastcall virtual ~TdxFontCache();
	virtual int __fastcall CalcFontIndex(const System::UnicodeString AFontName, int ADoubleFontSize, const System::Uitypes::TFontStyles AFontStyle, TdxCharacterFormattingScript AScript);
	virtual int __fastcall CalcNormalFontIndex(const System::UnicodeString AFontName, int ADoubleFontSize, const System::Uitypes::TFontStyles AFontStyle);
	__classmethod void __fastcall CheckInitialize();
	__classmethod System::Classes::TStrings* __fastcall CreateSystemTrueTypeFonts();
	System::UnicodeString __fastcall FindSubstituteFont(const System::UnicodeString ASourceFontName, System::WideChar ACharacter, TdxFontCharacterSet* &AFontCharacterSet);
	int __fastcall GetCharsetByFontName(const System::UnicodeString AFontName);
	TdxFontCharacterSet* __fastcall GetFontCharacterSet(const System::UnicodeString AFontName);
	virtual bool __fastcall ShouldUseDefaultFontToDrawInvisibleCharacter(TdxFontInfo* AFontInfo, System::WideChar ACharacter);
	__property int Count = {read=GetCount, nodefault};
	__property TdxFontInfo* Items[int Index] = {read=GetItem/*, default*/};
	__property TdxFontInfoMeasurer* Measurer = {read=FMeasurer};
	/* static */ __property System::Generics::Collections::TObjectDictionary__2<System::UnicodeString,TdxTrueTypeFontInfo*>* SystemTrueTypeFonts = {read=FSystemTrueTypeFonts};
	__property Dxdocumentlayoutunitconverter::TdxDocumentLayoutUnitConverter* UnitConverter = {read=FUnitConverter};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFontCacheManager : /*[[sealed]]*/ public System::TObject
{
	typedef System::TObject inherited;
	
private:
	static System::Generics::Collections::TObjectList__1<TdxFontCache*>* FOfficeItems;
	static System::Generics::Collections::TObjectList__1<TdxFontCache*>* FVCLItems;
	
protected:
	__classmethod void __fastcall Finalize();
	__classmethod void __fastcall Initialize();
	
public:
	static TdxFontCache* __fastcall GetFontCache(const Dxdocumentlayoutunitconverter::TdxDocumentLayoutUnit AUnit, const float ADpi);
	static TdxFontCache* __fastcall GetOfficeFontCache(const Dxdocumentlayoutunitconverter::TdxDocumentLayoutUnit AUnit, const float ADpi);
	static TdxFontCache* __fastcall GetVCLFontCache(const Dxdocumentlayoutunitconverter::TdxDocumentLayoutUnit AUnit, const float ADpi);
public:
	/* TObject.Create */ inline __fastcall TdxFontCacheManager() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxFontCacheManager() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFontLink : /*[[sealed]]*/ public System::TObject
{
	typedef System::TObject inherited;
	
private:
	static bool FInitialized;
	static _di_IdxMLangFontLink FInstance;
	
protected:
	__classmethod void __fastcall CheckInitialized();
	
public:
	__classmethod unsigned __fastcall GetCharCodePage(const System::WideChar ACharacter);
	__classmethod void __fastcall Release();
	
private:
	// __classmethod void __fastcall Create@();
	// __classmethod void __fastcall Destroy@();
public:
	/* TObject.Create */ inline __fastcall TdxFontLink() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxFontLink() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE GUID dxClassCMultiLanguage;
extern DELPHI_PACKAGE System::LongBool __fastcall dxEnumFontFamilies(HDC DC, tagLOGFONTW &p2, void * p3, NativeInt p4, unsigned p5)/* overload */;
extern DELPHI_PACKAGE System::LongBool __fastcall dxEnumFontFamilies(HDC DC, System::WideChar * p2, void * p3, NativeInt p4)/* overload */;
}	/* namespace Dxfonthelpers */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXFONTHELPERS)
using namespace Dxfonthelpers;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxfonthelpersHPP
