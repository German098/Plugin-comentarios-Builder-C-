// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxFormattedText.pas' rev: 35.00 (Windows)

#ifndef DxformattedtextHPP
#define DxformattedtextHPP

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
#include <Vcl.Graphics.hpp>
#include <System.Classes.hpp>
#include <System.Generics.Collections.hpp>
#include <System.SysUtils.hpp>
#include <cxGraphics.hpp>
#include <cxDrawTextUtils.hpp>
#include <dxTextViewInfoCache.hpp>
#include <dxFontHelpers.hpp>
#include <cxGeometry.hpp>
#include <dxDPIAwareUtils.hpp>
#include <System.Generics.Defaults.hpp>

//-- user supplied -----------------------------------------------------------

namespace Dxformattedtext
{
//-- forward type declarations -----------------------------------------------
__interface DELPHIINTERFACE IdxFormattedTextOwner;
typedef System::DelphiInterface<IdxFormattedTextOwner> _di_IdxFormattedTextOwner;
struct TdxFormattedTextCharacterProperties;
struct TdxFormattedTextHyperlinkData;
class DELPHICLASS TdxFormattedTextCustomPainter;
class DELPHICLASS TdxFormattedTextPainter;
struct TdxFormattedTextLayoutBuilderInitialData;
class DELPHICLASS TdxFormattedText;
class DELPHICLASS TdxFormattedTextRun;
class DELPHICLASS TdxFormattedTextNoCodeRun;
class DELPHICLASS TdxFormattedTextNoParseRun;
class DELPHICLASS TdxFormattedTextBoldRun;
class DELPHICLASS TdxFormattedTextItalicRun;
class DELPHICLASS TdxFormattedTextUnderlineRun;
class DELPHICLASS TdxFormattedTextStrikeoutRun;
class DELPHICLASS TdxFormattedTextColorRun;
class DELPHICLASS TdxFormattedTextURLRun;
class DELPHICLASS TdxFormattedTextBackgroundColorRun;
class DELPHICLASS TdxFormattedTextSizeRun;
class DELPHICLASS TdxFormattedTextSupRun;
class DELPHICLASS TdxFormattedTextSubRun;
class DELPHICLASS TdxFormattedTextFontRun;
class DELPHICLASS TdxFormattedTextImgRun;
class DELPHICLASS TdxFormattedTextRuns;
class DELPHICLASS TdxFormattedTextRunStack;
class DELPHICLASS TdxFormattedTextLayoutBuilder;
class DELPHICLASS TdxFormattedTextLayout;
class DELPHICLASS TdxFormattedTextLayoutRow;
class DELPHICLASS TdxFormattedTextLayoutBox;
class DELPHICLASS TdxFormattedEmptyLayoutBox;
class DELPHICLASS TdxFormattedCRLayoutBox;
class DELPHICLASS TdxFormattedTextSpaceLayoutBox;
class DELPHICLASS TdxFormattedTextTabLayoutBox;
class DELPHICLASS TdxFormattedTextTextLayoutBox;
class DELPHICLASS TdxFormattedTextConverter;
class DELPHICLASS TdxFormattedTextConverters;
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TdxFormattedTextConverterClass;

__interface  INTERFACE_UUID("{C33BD809-0400-46A8-9029-E9C72579FFA1}") IdxFormattedTextOwner  : public System::IInterface 
{
	virtual Vcl::Graphics::TFont* __fastcall GetFormattedTextFont() = 0 ;
	virtual System::UnicodeString __fastcall GetFormattedText() = 0 ;
	virtual bool __fastcall GetUseFormattedText() = 0 ;
	virtual void __fastcall SetFormattedText(const System::UnicodeString AValue) = 0 ;
};

struct DECLSPEC_DRECORD TdxFormattedTextCharacterProperties
{
private:
	System::Uitypes::TColor __fastcall GetDefaultBackgroundColor();
	bool __fastcall GetBold();
	int __fastcall GetFontSize();
	bool __fastcall GetItalic();
	bool __fastcall GetUnderline();
	bool __fastcall GetStrikeout();
	void __fastcall SetBold(bool AValue);
	void __fastcall SetFontSize(int AValue);
	void __fastcall SetItalic(bool AValue);
	void __fastcall SetUnderline(bool AValue);
	void __fastcall SetStrikeout(bool AValue);
	
public:
	System::Uitypes::TColor BackgroundColor;
	Dxfonthelpers::TdxCharacterFormattingScript CharacterFormattingScript;
	System::Uitypes::TColor FontColor;
	System::UnicodeString FontName;
	int FontDoubleSize;
	System::Uitypes::TFontStyles FontStyle;
	bool __fastcall Compare(const TdxFormattedTextCharacterProperties &ACharacterProperties);
	void __fastcall Initialize(Vcl::Graphics::TFont* AFont)/* overload */;
	void __fastcall Initialize(Vcl::Graphics::TFont* AFont, int AFontDoubleSize)/* overload */;
	__property bool Bold = {read=GetBold, write=SetBold};
	__property int FontSize = {read=GetFontSize, write=SetFontSize};
	__property bool Italic = {read=GetItalic, write=SetItalic};
	__property bool Underline = {read=GetUnderline, write=SetUnderline};
	__property bool Strikeout = {read=GetStrikeout, write=SetStrikeout};
};


struct DECLSPEC_DRECORD TdxFormattedTextHyperlinkData
{
public:
	System::UnicodeString Hyperlink;
	int BeginBoxIndex;
	int BeginRowIndex;
	int BoxCount;
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFormattedTextCustomPainter : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	virtual void __fastcall ExtTextOut(const System::Types::TRect &ABounds, NativeUInt AFontHandle, System::Uitypes::TColor AFontColor, const System::UnicodeString AText, Dxtextviewinfocache::PdxWordArray AGlyphs, int AGlyphCount, Dxtextviewinfocache::PdxIntegerArray AGlyphWidths) = 0 ;
	virtual void __fastcall FillRect(const System::Types::TRect &ARect, System::Uitypes::TColor AColor) = 0 ;
	virtual void __fastcall IntersectClipRect(const System::Types::TRect &ARect) = 0 ;
	virtual void __fastcall Restore() = 0 ;
	virtual void __fastcall Store() = 0 ;
public:
	/* TObject.Create */ inline __fastcall TdxFormattedTextCustomPainter() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxFormattedTextCustomPainter() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFormattedTextPainter : public TdxFormattedTextCustomPainter
{
	typedef TdxFormattedTextCustomPainter inherited;
	
private:
	HDC FDCHandle;
	HDC FSaveDC;
	
public:
	__fastcall virtual TdxFormattedTextPainter(HDC ADCHandle);
	virtual void __fastcall ExtTextOut(const System::Types::TRect &ABounds, NativeUInt AFontHandle, System::Uitypes::TColor AFontColor, const System::UnicodeString AText, Dxtextviewinfocache::PdxWordArray AGlyphs, int AGlyphCount, Dxtextviewinfocache::PdxIntegerArray AGlyphWidths);
	virtual void __fastcall FillRect(const System::Types::TRect &ARect, System::Uitypes::TColor AColor);
	virtual void __fastcall IntersectClipRect(const System::Types::TRect &ARect);
	virtual void __fastcall Restore();
	virtual void __fastcall Store();
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxFormattedTextPainter() { }
	
};

#pragma pack(pop)

struct DECLSPEC_DRECORD TdxFormattedTextLayoutBuilderInitialData
{
public:
	System::Types::TRect Bounds;
	TdxFormattedTextCharacterProperties CharacterProperties;
	unsigned TextOutFormat;
	Cxgeometry::TdxScaleFactor* ScaleFactor;
	float ZoomFactor;
	System::Uitypes::TColor HyperlinkColor;
	bool __fastcall Compare(const TdxFormattedTextLayoutBuilderInitialData &AInitialData);
	void __fastcall Initialize(Vcl::Graphics::TFont* AFont, const System::Types::TRect &ABounds, unsigned ATextOutFormat, Cxgeometry::TdxScaleFactor* AScaleFactor, float AZoomFactor, const System::Uitypes::TColor AHyperlinkColor);
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFormattedText : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Uitypes::TColor FHyperlinkColor;
	TdxFormattedTextRuns* FInternalRuns;
	TdxFormattedTextLayout* FLayout;
	bool FMeasureTrailingSpaces;
	bool FIsTextChanged;
	TdxFormattedTextRuns* FRuns;
	bool FShowAccelChar;
	System::UnicodeString FText;
	bool FUseOfficeFonts;
	bool __fastcall GetHasFormatting();
	System::Types::TSize __fastcall GetTextSize();
	void __fastcall InternalDraw(TdxFormattedTextCustomPainter* APainter, const System::Types::TPoint &APosition, bool AClip);
	void __fastcall SetText(const System::UnicodeString AValue);
	
protected:
	bool FHasAccelCharRun;
	void __fastcall Changed();
	void __fastcall CreateInternalRuns(Vcl::Graphics::TFont* ADefaultFont);
	Dxfonthelpers::TdxFontCache* __fastcall GetActualFontCache(const float ADpi);
	__property System::Uitypes::TColor HyperlinkColor = {read=FHyperlinkColor, write=FHyperlinkColor, nodefault};
	__property TdxFormattedTextRuns* InternalRuns = {read=FInternalRuns};
	__property TdxFormattedTextLayout* Layout = {read=FLayout};
	
public:
	__fastcall virtual TdxFormattedText();
	__fastcall virtual ~TdxFormattedText();
	void __fastcall Import(const System::UnicodeString ASource, Vcl::Graphics::TFont* ADefaultFont = (Vcl::Graphics::TFont*)(0x0))/* overload */;
	void __fastcall Import(const System::Variant &ASource, Vcl::Graphics::TFont* ADefaultFont = (Vcl::Graphics::TFont*)(0x0))/* overload */;
	System::UnicodeString __fastcall Export(TdxFormattedTextConverterClass AConverterClass, Vcl::Graphics::TFont* ADefaultFont = (Vcl::Graphics::TFont*)(0x0));
	void __fastcall CalculateLayout(Vcl::Graphics::TCanvas* ACanvas, Vcl::Graphics::TFont* AFont, const System::Types::TRect &ABounds, unsigned AFormat, Cxgeometry::TdxScaleFactor* AScaleFactor = (Cxgeometry::TdxScaleFactor*)(0x0), float AZoomFactor = 1.000000E+00f, const System::Uitypes::TColor AHyperlinkColor = (System::Uitypes::TColor)(0x20000000));
	void __fastcall Draw(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TPoint &APosition, bool AClip = true)/* overload */;
	void __fastcall Draw(TdxFormattedTextCustomPainter* APainter, const System::Types::TPoint &APosition, bool AClip = true)/* overload */;
	int __fastcall GetBaseLine(int ARowIndex);
	System::UnicodeString __fastcall GetDisplayText();
	System::UnicodeString __fastcall GetUrl(int AIndex);
	TdxFormattedTextLayoutBox* __fastcall HitTest(const System::Types::TPoint &APoint);
	__property bool HasFormatting = {read=GetHasFormatting, nodefault};
	__property bool MeasureTrailingSpaces = {read=FMeasureTrailingSpaces, write=FMeasureTrailingSpaces, nodefault};
	__property TdxFormattedTextRuns* Runs = {read=FRuns};
	__property bool ShowAccelChar = {read=FShowAccelChar, write=FShowAccelChar, nodefault};
	__property System::UnicodeString Text = {read=FText, write=SetText};
	__property System::Types::TSize TextSize = {read=GetTextSize};
	__property bool UseOfficeFonts = {read=FUseOfficeFonts, write=FUseOfficeFonts, nodefault};
};

#pragma pack(pop)

enum DECLSPEC_DENUM TdxFormattedTextRunAction : unsigned char { traOpen, traClose };

typedef System::TMetaClass* TdxFormattedTextRunClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFormattedTextRun : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxFormattedTextRunAction FAction;
	System::WideChar * __fastcall GetTextFinish();
	
protected:
	int FTextLength;
	System::WideChar *FTextStart;
	virtual TdxFormattedTextRun* __fastcall Clone();
	System::UnicodeString __fastcall GetText();
	
public:
	__fastcall TdxFormattedTextRun(TdxFormattedTextRunAction AAction);
	virtual void __fastcall ApplyStyle(TdxFormattedTextCharacterProperties &AStyle);
	__property TdxFormattedTextRunAction Action = {read=FAction, nodefault};
	__property System::UnicodeString Text = {read=GetText};
	__property System::WideChar * TextFinish = {read=GetTextFinish};
	__property int TextLength = {read=FTextLength, nodefault};
	__property System::WideChar * TextStart = {read=FTextStart};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxFormattedTextRun() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFormattedTextNoCodeRun : public TdxFormattedTextRun
{
	typedef TdxFormattedTextRun inherited;
	
public:
	/* TdxFormattedTextRun.Create */ inline __fastcall TdxFormattedTextNoCodeRun(TdxFormattedTextRunAction AAction) : TdxFormattedTextRun(AAction) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxFormattedTextNoCodeRun() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFormattedTextNoParseRun : public TdxFormattedTextRun
{
	typedef TdxFormattedTextRun inherited;
	
public:
	/* TdxFormattedTextRun.Create */ inline __fastcall TdxFormattedTextNoParseRun(TdxFormattedTextRunAction AAction) : TdxFormattedTextRun(AAction) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxFormattedTextNoParseRun() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFormattedTextBoldRun : public TdxFormattedTextRun
{
	typedef TdxFormattedTextRun inherited;
	
public:
	virtual void __fastcall ApplyStyle(TdxFormattedTextCharacterProperties &AStyle);
public:
	/* TdxFormattedTextRun.Create */ inline __fastcall TdxFormattedTextBoldRun(TdxFormattedTextRunAction AAction) : TdxFormattedTextRun(AAction) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxFormattedTextBoldRun() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFormattedTextItalicRun : public TdxFormattedTextRun
{
	typedef TdxFormattedTextRun inherited;
	
public:
	virtual void __fastcall ApplyStyle(TdxFormattedTextCharacterProperties &AStyle);
public:
	/* TdxFormattedTextRun.Create */ inline __fastcall TdxFormattedTextItalicRun(TdxFormattedTextRunAction AAction) : TdxFormattedTextRun(AAction) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxFormattedTextItalicRun() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFormattedTextUnderlineRun : public TdxFormattedTextRun
{
	typedef TdxFormattedTextRun inherited;
	
public:
	virtual void __fastcall ApplyStyle(TdxFormattedTextCharacterProperties &AStyle);
public:
	/* TdxFormattedTextRun.Create */ inline __fastcall TdxFormattedTextUnderlineRun(TdxFormattedTextRunAction AAction) : TdxFormattedTextRun(AAction) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxFormattedTextUnderlineRun() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFormattedTextStrikeoutRun : public TdxFormattedTextRun
{
	typedef TdxFormattedTextRun inherited;
	
public:
	virtual void __fastcall ApplyStyle(TdxFormattedTextCharacterProperties &AStyle);
public:
	/* TdxFormattedTextRun.Create */ inline __fastcall TdxFormattedTextStrikeoutRun(TdxFormattedTextRunAction AAction) : TdxFormattedTextRun(AAction) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxFormattedTextStrikeoutRun() { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TdxFormattedTextColorRunClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFormattedTextColorRun : public TdxFormattedTextRun
{
	typedef TdxFormattedTextRun inherited;
	
protected:
	System::Uitypes::TColor FColor;
	virtual TdxFormattedTextRun* __fastcall Clone();
	
public:
	__fastcall virtual TdxFormattedTextColorRun(TdxFormattedTextRunAction AAction, const System::Uitypes::TColor AColor);
	virtual void __fastcall ApplyStyle(TdxFormattedTextCharacterProperties &AStyle);
	__property System::Uitypes::TColor Color = {read=FColor, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxFormattedTextColorRun() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFormattedTextURLRun : public TdxFormattedTextRun
{
	typedef TdxFormattedTextRun inherited;
	
protected:
	System::UnicodeString FHyperlink;
	System::Uitypes::TColor FColor;
	virtual TdxFormattedTextRun* __fastcall Clone();
	
public:
	__fastcall virtual TdxFormattedTextURLRun(TdxFormattedTextRunAction AAction, const System::UnicodeString AHyperlink);
	virtual void __fastcall ApplyStyle(TdxFormattedTextCharacterProperties &AStyle);
	__property System::UnicodeString Hyperlink = {read=FHyperlink};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxFormattedTextURLRun() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFormattedTextBackgroundColorRun : public TdxFormattedTextColorRun
{
	typedef TdxFormattedTextColorRun inherited;
	
public:
	virtual void __fastcall ApplyStyle(TdxFormattedTextCharacterProperties &AStyle);
public:
	/* TdxFormattedTextColorRun.Create */ inline __fastcall virtual TdxFormattedTextBackgroundColorRun(TdxFormattedTextRunAction AAction, const System::Uitypes::TColor AColor) : TdxFormattedTextColorRun(AAction, AColor) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxFormattedTextBackgroundColorRun() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFormattedTextSizeRun : public TdxFormattedTextRun
{
	typedef TdxFormattedTextRun inherited;
	
protected:
	int FSize;
	virtual TdxFormattedTextRun* __fastcall Clone();
	
public:
	__fastcall virtual TdxFormattedTextSizeRun(TdxFormattedTextRunAction AAction, int ASize);
	virtual void __fastcall ApplyStyle(TdxFormattedTextCharacterProperties &AStyle);
	__property int Size = {read=FSize, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxFormattedTextSizeRun() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFormattedTextSupRun : public TdxFormattedTextRun
{
	typedef TdxFormattedTextRun inherited;
	
public:
	virtual void __fastcall ApplyStyle(TdxFormattedTextCharacterProperties &AStyle);
public:
	/* TdxFormattedTextRun.Create */ inline __fastcall TdxFormattedTextSupRun(TdxFormattedTextRunAction AAction) : TdxFormattedTextRun(AAction) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxFormattedTextSupRun() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFormattedTextSubRun : public TdxFormattedTextRun
{
	typedef TdxFormattedTextRun inherited;
	
public:
	virtual void __fastcall ApplyStyle(TdxFormattedTextCharacterProperties &AStyle);
public:
	/* TdxFormattedTextRun.Create */ inline __fastcall TdxFormattedTextSubRun(TdxFormattedTextRunAction AAction) : TdxFormattedTextRun(AAction) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxFormattedTextSubRun() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFormattedTextFontRun : public TdxFormattedTextRun
{
	typedef TdxFormattedTextRun inherited;
	
protected:
	System::UnicodeString FFontName;
	virtual TdxFormattedTextRun* __fastcall Clone();
	
public:
	__fastcall virtual TdxFormattedTextFontRun(TdxFormattedTextRunAction AAction, const System::UnicodeString AFontName);
	virtual void __fastcall ApplyStyle(TdxFormattedTextCharacterProperties &AStyle);
	__property System::UnicodeString FontName = {read=FFontName};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxFormattedTextFontRun() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFormattedTextImgRun : public TdxFormattedTextRun
{
	typedef TdxFormattedTextRun inherited;
	
public:
	/* TdxFormattedTextRun.Create */ inline __fastcall TdxFormattedTextImgRun(TdxFormattedTextRunAction AAction) : TdxFormattedTextRun(AAction) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxFormattedTextImgRun() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TdxFormattedTextRuns : public System::Generics::Collections::TObjectList__1<TdxFormattedTextRun*>
{
	typedef System::Generics::Collections::TObjectList__1<TdxFormattedTextRun*> inherited;
	
public:
	System::UnicodeString __fastcall ExtractURLText(TdxFormattedTextURLRun* const ARun);
public:
	/* {System_Generics_Collections}TObjectList<dxFormattedText_TdxFormattedTextRun>.Create */ inline __fastcall TdxFormattedTextRuns()/* overload */ : System::Generics::Collections::TObjectList__1<TdxFormattedTextRun*>() { }
	/* {System_Generics_Collections}TObjectList<dxFormattedText_TdxFormattedTextRun>.Create */ inline __fastcall TdxFormattedTextRuns(bool AOwnsObjects)/* overload */ : System::Generics::Collections::TObjectList__1<TdxFormattedTextRun*>(AOwnsObjects) { }
	/* {System_Generics_Collections}TObjectList<dxFormattedText_TdxFormattedTextRun>.Create */ inline __fastcall TdxFormattedTextRuns(const System::DelphiInterface<System::Generics::Defaults::IComparer__1<TdxFormattedTextRun*> > AComparer, bool AOwnsObjects)/* overload */ : System::Generics::Collections::TObjectList__1<TdxFormattedTextRun*>(AComparer, AOwnsObjects) { }
	/* {System_Generics_Collections}TObjectList<dxFormattedText_TdxFormattedTextRun>.Create */ inline __fastcall TdxFormattedTextRuns(System::Generics::Collections::TEnumerable__1<TdxFormattedTextRun*>* const Collection, bool AOwnsObjects)/* overload */ : System::Generics::Collections::TObjectList__1<TdxFormattedTextRun*>(Collection, AOwnsObjects) { }
	/* {System_Generics_Collections}TObjectList<dxFormattedText_TdxFormattedTextRun>.Destroy */ inline __fastcall virtual ~TdxFormattedTextRuns() { }
	
public:
	/* {System_Generics_Collections}TList<dxFormattedText_TdxFormattedTextRun>.Create */ inline __fastcall TdxFormattedTextRuns(const System::DelphiInterface<System::Generics::Defaults::IComparer__1<TdxFormattedTextRun*> > AComparer)/* overload */ : System::Generics::Collections::TObjectList__1<TdxFormattedTextRun*>(AComparer) { }
	/* {System_Generics_Collections}TList<dxFormattedText_TdxFormattedTextRun>.Create */ inline __fastcall TdxFormattedTextRuns(System::Generics::Collections::TEnumerable__1<TdxFormattedTextRun*>* const Collection)/* overload */ : System::Generics::Collections::TObjectList__1<TdxFormattedTextRun*>(Collection) { }
	/* {System_Generics_Collections}TList<dxFormattedText_TdxFormattedTextRun>.Create */ inline __fastcall TdxFormattedTextRuns(TdxFormattedTextRun* const *Values, const int Values_High)/* overload */ : System::Generics::Collections::TObjectList__1<TdxFormattedTextRun*>(Values, Values_High) { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFormattedTextRunStack : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Generics::Collections::TList__1<TdxFormattedTextRun*>* FStack;
	
public:
	__fastcall virtual TdxFormattedTextRunStack();
	__fastcall virtual ~TdxFormattedTextRunStack();
	void __fastcall CalculateStyle(TdxFormattedTextCharacterProperties &AStyle);
	void __fastcall Clear();
	void __fastcall ProcessRun(TdxFormattedTextRun* ARun);
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFormattedTextLayoutBuilder : public System::TObject
{
	typedef System::TObject inherited;
	
	
public:
	#pragma pack(push,8)
	struct DECLSPEC_DRECORD TdxRollbackInfo
	{
	public:
		System::WideChar *TextPosition;
		int RunIndex;
	};
	#pragma pack(pop)
	
	
	
private:
	static int dxTabWidth;
	Dxfonthelpers::TdxFontCache* FFontCache;
	TdxFormattedTextRunStack* FRunStack;
	TdxRollbackInfo FAbilityBreakLineBoxRollbackInfo;
	TdxRollbackInfo FPreviousRollbackInfo;
	TdxRollbackInfo FLastRowRollbackInfo;
	int FHyperlinkIndex;
	TdxFormattedTextLayout* FLayout;
	Dxtextviewinfocache::TdxCustomBoxMeasurer* FMeasurer;
	HDC FDCHandle;
	int FAbilityBreakLineBoxIndex;
	TdxFormattedTextCharacterProperties FCurrentCharacterProperties;
	bool FMeasureTrailingSpaces;
	bool FIsClippedText;
	bool FIsEndEllipsisRow;
	TdxFormattedTextLayoutRow* FRow;
	int FRowTextWidth;
	int FRunIndex;
	TdxFormattedTextRuns* FRuns;
	TdxFormattedTextRun* FRun;
	System::WideChar *FTextStart;
	System::WideChar *FTextFinish;
	Cxdrawtextutils::TcxTextParams FTextParams;
	void __fastcall Align();
	TdxFormattedCRLayoutBox* __fastcall CreateCRLayoutBox();
	TdxFormattedTextSpaceLayoutBox* __fastcall CreateSpaceLayoutBox();
	TdxFormattedTextTabLayoutBox* __fastcall CreateTabLayoutBox();
	TdxFormattedTextTextLayoutBox* __fastcall CreateTextLayoutBox(const System::UnicodeString AText, Dxfonthelpers::TdxFontInfo* AFontInfo);
	TdxFormattedEmptyLayoutBox* __fastcall CreateEmptyLayoutBox();
	Dxtextviewinfocache::TdxTextViewInfo* __fastcall GetTextFromCache(const System::UnicodeString AText, Dxfonthelpers::TdxFontInfo* AFontInfo);
	TdxFormattedTextCharacterProperties __fastcall GetDefaultCharacterProperties();
	System::Uitypes::TColor __fastcall GetHyperlinkColor();
	Cxgeometry::TdxScaleFactor* __fastcall GetScaleFactor();
	unsigned __fastcall GetTextOutFormat();
	float __fastcall GetZoomFactor();
	void __fastcall AddNewRow();
	void __fastcall DeleteLastRow();
	int __fastcall GetAdjustedWidth(int AWidth, int ATabWidth);
	int __fastcall GetAvailableRowWidth();
	System::Types::TRect __fastcall GetBounds();
	Dxfonthelpers::TdxFontInfo* __fastcall GetFontInfo();
	TdxFormattedTextLayoutBuilderInitialData __fastcall GetInitialData();
	System::Types::TSize __fastcall GetTextSize();
	void __fastcall GoToNextRow();
	void __fastcall GoToNextRun();
	void __fastcall InitializeDefaultParameters();
	void __fastcall InitializeLayoutBox(TdxFormattedTextLayoutBox* ABox);
	void __fastcall InitializePossibleBreakLineInfo();
	void __fastcall InitializeRollbackInfo(System::WideChar * ATextPosition, int ARunIndex);
	bool __fastcall IsExcessRow();
	void __fastcall PopulateRunStack(int ARunIndex);
	void __fastcall ProcessSpecialCharacters();
	void __fastcall ProcessText();
	void __fastcall ReturnToRowBeginning();
	void __fastcall SetRunIndex(int AValue);
	
protected:
	__property TdxFormattedTextLayoutBuilderInitialData InitialData = {read=GetInitialData};
	__property System::Types::TRect Bounds = {read=GetBounds};
	__property TdxFormattedTextCharacterProperties DefaultCharacterProperties = {read=GetDefaultCharacterProperties};
	__property unsigned TextOutFormat = {read=GetTextOutFormat, nodefault};
	__property Cxgeometry::TdxScaleFactor* ScaleFactor = {read=GetScaleFactor};
	__property float ZoomFactor = {read=GetZoomFactor};
	__property System::Uitypes::TColor HyperlinkColor = {read=GetHyperlinkColor, nodefault};
	__property int AvailableRowWidth = {read=GetAvailableRowWidth, nodefault};
	__property Dxtextviewinfocache::TdxCustomBoxMeasurer* Measurer = {read=FMeasurer};
	__property int RunIndex = {read=FRunIndex, write=SetRunIndex, nodefault};
	__property System::Types::TSize TextSize = {read=GetTextSize};
	
public:
	__fastcall TdxFormattedTextLayoutBuilder();
	__fastcall virtual ~TdxFormattedTextLayoutBuilder();
	void __fastcall Calculate(Vcl::Graphics::TCanvas* ACanvas, TdxFormattedTextLayout* ALayout, TdxFormattedText* AFormattedText, const TdxFormattedTextLayoutBuilderInitialData &AInitialData);
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TdxFormattedTextLayout : public System::Generics::Collections::TObjectList__1<TdxFormattedTextLayoutRow*>
{
	typedef System::Generics::Collections::TObjectList__1<TdxFormattedTextLayoutRow*> inherited;
	
private:
	System::Types::TRect FBounds;
	System::Generics::Collections::TList__1<TdxFormattedTextHyperlinkData>* FHyperlinks;
	TdxFormattedTextLayoutBuilderInitialData FInitialData;
	bool FMeasureTrailingSpaces;
	System::Types::TSize __fastcall GetTextSize();
	void __fastcall SetInitialData(const TdxFormattedTextLayoutBuilderInitialData &AValue);
	
protected:
	TdxFormattedTextLayoutBox* __fastcall HitTest(const System::Types::TPoint &APoint);
	__property System::Types::TRect Bounds = {read=FBounds, write=FBounds};
	__property System::Generics::Collections::TList__1<TdxFormattedTextHyperlinkData>* Hyperlinks = {read=FHyperlinks};
	__property TdxFormattedTextLayoutBuilderInitialData InitialData = {read=FInitialData, write=SetInitialData};
	__property System::Types::TSize TextSize = {read=GetTextSize};
	
public:
	__fastcall virtual TdxFormattedTextLayout(bool AMeasureTrailingSpaces);
	__fastcall virtual ~TdxFormattedTextLayout();
	void __fastcall Draw(TdxFormattedTextCustomPainter* APainter, const System::Types::TPoint &AOffset, bool AClip);
};


class PASCALIMPLEMENTATION TdxFormattedTextLayoutRow : public System::Generics::Collections::TObjectList__1<TdxFormattedTextLayoutBox*>
{
	typedef System::Generics::Collections::TObjectList__1<TdxFormattedTextLayoutBox*> inherited;
	
private:
	int FAscentAndFree;
	System::Types::TRect FBounds;
	void __fastcall AlignBox(int AIndex, float ASpaceFactor, float &ASpaceResidue, System::Types::TRect &ABoxBounds);
	int __fastcall GetAscentAndFree();
	int __fastcall GetFirstBoxHorizontalPosition();
	float __fastcall GetSpaceFactor();
	int __fastcall GetSpacesWidth(int AStartIndex, int AFinishIndex);
	void __fastcall CalculateUnderline(int AIndex, int &AUnderlineBoxIndex, int &AUnderlineAverageThickness, int &AUnderlineAveragePosition, int &AUnderlineWidth);
	int __fastcall SkipLeftSpaceBlocks();
	int __fastcall SkipRightSpaceBlocks();
	
private:
	bool FExpandTabs;
	bool FMeasureTrailingSpaces;
	Cxdrawtextutils::TcxTextAlignX FTextAlignX;
	Cxdrawtextutils::TcxTextAlignY FTextAlignY;
	
protected:
	System::Types::TSize __fastcall GetTextSize(int ABoxCount, bool AIsLast);
	TdxFormattedTextLayoutBox* __fastcall HitTest(const System::Types::TPoint &APoint);
	__property int AscentAndFree = {read=FAscentAndFree, nodefault};
	__property System::Types::TRect Bounds = {read=FBounds};
	
public:
	__fastcall TdxFormattedTextLayoutRow(const Cxdrawtextutils::TcxTextParams &ATextParams);
	void __fastcall Calculate(const System::Types::TRect &ABounds);
	void __fastcall Draw(TdxFormattedTextCustomPainter* APainter, const System::Types::TPoint &AOffset);
public:
	/* {System_Generics_Collections}TObjectList<dxFormattedText_TdxFormattedTextLayoutBox>.Destroy */ inline __fastcall virtual ~TdxFormattedTextLayoutRow() { }
	
};


enum DECLSPEC_DENUM TdxLayoutBoxType : unsigned char { lbtText, lbtSpace, lbtTab, lbtCR, lbtEmpty };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFormattedTextLayoutBox : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Uitypes::TColor FBackgroundColor;
	System::Types::TRect FBounds;
	Dxfonthelpers::TdxCharacterFormattingScript FCharacterFormattingScript;
	System::Uitypes::TColor FFontColor;
	Dxfonthelpers::TdxFontInfo* FFontInfo;
	int FHyperlinkIndex;
	bool FStrikeout;
	bool FUnderline;
	int FUnderlinePosition;
	int FUnderlineThickness;
	
protected:
	virtual TdxLayoutBoxType __fastcall GetBoxType();
	virtual System::Types::TSize __fastcall GetSize();
	__property System::Types::TRect Bounds = {read=FBounds};
	__property TdxLayoutBoxType BoxType = {read=GetBoxType, nodefault};
	__property System::Uitypes::TColor BackgroundColor = {read=FBackgroundColor, write=FBackgroundColor, nodefault};
	__property Dxfonthelpers::TdxCharacterFormattingScript CharacterFormattingScript = {read=FCharacterFormattingScript, write=FCharacterFormattingScript, nodefault};
	__property System::Uitypes::TColor FontColor = {read=FFontColor, write=FFontColor, nodefault};
	__property Dxfonthelpers::TdxFontInfo* FontInfo = {read=FFontInfo, write=FFontInfo};
	__property System::Types::TSize Size = {read=GetSize};
	__property bool Strikeout = {read=FStrikeout, write=FStrikeout, nodefault};
	__property bool Underline = {read=FUnderline, write=FUnderline, nodefault};
	__property int UnderlinePosition = {read=FUnderlinePosition, write=FUnderlinePosition, nodefault};
	__property int UnderlineThickness = {read=FUnderlineThickness, write=FUnderlineThickness, nodefault};
	
public:
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds);
	virtual void __fastcall Draw(TdxFormattedTextCustomPainter* APainter, const System::Types::TPoint &AOffset);
	bool __fastcall IsHyperlink();
	__property int HyperlinkIndex = {read=FHyperlinkIndex, write=FHyperlinkIndex, nodefault};
public:
	/* TObject.Create */ inline __fastcall TdxFormattedTextLayoutBox() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxFormattedTextLayoutBox() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFormattedEmptyLayoutBox : public TdxFormattedTextLayoutBox
{
	typedef TdxFormattedTextLayoutBox inherited;
	
protected:
	virtual TdxLayoutBoxType __fastcall GetBoxType();
public:
	/* TObject.Create */ inline __fastcall TdxFormattedEmptyLayoutBox() : TdxFormattedTextLayoutBox() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxFormattedEmptyLayoutBox() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFormattedCRLayoutBox : public TdxFormattedTextLayoutBox
{
	typedef TdxFormattedTextLayoutBox inherited;
	
protected:
	virtual TdxLayoutBoxType __fastcall GetBoxType();
public:
	/* TObject.Create */ inline __fastcall TdxFormattedCRLayoutBox() : TdxFormattedTextLayoutBox() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxFormattedCRLayoutBox() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFormattedTextSpaceLayoutBox : public TdxFormattedTextLayoutBox
{
	typedef TdxFormattedTextLayoutBox inherited;
	
private:
	int FCount;
	
protected:
	virtual System::Types::TSize __fastcall GetSize();
	virtual TdxLayoutBoxType __fastcall GetBoxType();
	__property int Count = {read=FCount, write=FCount, nodefault};
public:
	/* TObject.Create */ inline __fastcall TdxFormattedTextSpaceLayoutBox() : TdxFormattedTextLayoutBox() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxFormattedTextSpaceLayoutBox() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFormattedTextTabLayoutBox : public TdxFormattedTextSpaceLayoutBox
{
	typedef TdxFormattedTextSpaceLayoutBox inherited;
	
protected:
	int FTabWidth;
	virtual System::Types::TSize __fastcall GetSize();
	virtual TdxLayoutBoxType __fastcall GetBoxType();
public:
	/* TObject.Create */ inline __fastcall TdxFormattedTextTabLayoutBox() : TdxFormattedTextSpaceLayoutBox() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxFormattedTextTabLayoutBox() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFormattedTextTextLayoutBox : public TdxFormattedTextLayoutBox
{
	typedef TdxFormattedTextLayoutBox inherited;
	
private:
	System::UnicodeString FText;
	Dxtextviewinfocache::TdxTextViewInfo* FTextViewInfo;
	
protected:
	virtual System::Types::TSize __fastcall GetSize();
	__property System::UnicodeString Text = {read=FText};
	__property Dxtextviewinfocache::TdxTextViewInfo* TextViewInfo = {read=FTextViewInfo};
	
public:
	__fastcall TdxFormattedTextTextLayoutBox(const System::UnicodeString AText, Dxtextviewinfocache::TdxTextViewInfo* ATextViewInfo);
	virtual void __fastcall Draw(TdxFormattedTextCustomPainter* APainter, const System::Types::TPoint &AOffset);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxFormattedTextTextLayoutBox() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFormattedTextConverter : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	__classmethod void __fastcall AdjustInternalRuns(TdxFormattedText* ASource, Vcl::Graphics::TFont* ADefaultFont);
	
public:
	__classmethod virtual bool __fastcall CanImport(const System::UnicodeString ASource);
	__classmethod virtual void __fastcall Import(TdxFormattedText* ATarget, const System::UnicodeString ASource, Vcl::Graphics::TFont* ADefaultFont = (Vcl::Graphics::TFont*)(0x0));
	__classmethod virtual System::UnicodeString __fastcall Export(TdxFormattedText* ASource, Vcl::Graphics::TFont* ADefaultFont = (Vcl::Graphics::TFont*)(0x0));
public:
	/* TObject.Create */ inline __fastcall TdxFormattedTextConverter() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxFormattedTextConverter() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFormattedTextConverters : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	static System::Classes::TList* FList;
	
public:
	__classmethod TdxFormattedTextConverterClass __fastcall GetConverterClass(const System::UnicodeString ASource);
	__classmethod void __fastcall Import(TdxFormattedText* ATarget, const System::UnicodeString ASource, Vcl::Graphics::TFont* ADefaultFont = (Vcl::Graphics::TFont*)(0x0))/* overload */;
	__classmethod void __fastcall Import(TdxFormattedText* ATarget, const System::Variant &ASource, Vcl::Graphics::TFont* ADefaultFont = (Vcl::Graphics::TFont*)(0x0))/* overload */;
	__classmethod System::UnicodeString __fastcall Export(TdxFormattedText* ASource, TdxFormattedTextConverterClass AConverterClass, Vcl::Graphics::TFont* ADefaultFont = (Vcl::Graphics::TFont*)(0x0));
	__classmethod void __fastcall Register(TdxFormattedTextConverterClass AConverterClass);
	__classmethod void __fastcall Unregister(TdxFormattedTextConverterClass AConverterClass);
public:
	/* TObject.Create */ inline __fastcall TdxFormattedTextConverters() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxFormattedTextConverters() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE int __fastcall dxGetStringLength(System::WideChar * AFirstChar, System::WideChar * ALastChar);
extern DELPHI_PACKAGE System::UnicodeString __fastcall dxGetString(System::WideChar * AFirstChar, int ALength)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall dxGetString(System::WideChar * AFirstChar, System::WideChar * ALastChar)/* overload */;
}	/* namespace Dxformattedtext */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXFORMATTEDTEXT)
using namespace Dxformattedtext;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxformattedtextHPP
