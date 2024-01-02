// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxTextViewInfoCache.pas' rev: 35.00 (Windows)

#ifndef DxtextviewinfocacheHPP
#define DxtextviewinfocacheHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Types.hpp>
#include <Winapi.Windows.hpp>
#include <dxCore.hpp>
#include <dxCoreClasses.hpp>
#include <dxFontHelpers.hpp>

//-- user supplied -----------------------------------------------------------

namespace Dxtextviewinfocache
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TdxTextViewInfo;
class DELPHICLASS TdxTextViewInfoCache;
class DELPHICLASS TdxCustomBoxMeasurer;
//-- type declarations -------------------------------------------------------
typedef System::StaticArray<int, 1> TdxIntegerArray;

typedef TdxIntegerArray *PdxIntegerArray;

typedef System::StaticArray<System::Word, 1> TdxWordArray;

typedef TdxWordArray *PdxWordArray;

typedef PINT IntPtr;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTextViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxIntegerArray *FCharacterWidths;
	int FGlyphCount;
	TdxWordArray *FGlyphs;
	System::Types::TSize FSize;
	
public:
	__fastcall virtual ~TdxTextViewInfo();
	__property PdxIntegerArray CharacterWidths = {read=FCharacterWidths, write=FCharacterWidths};
	__property PdxWordArray Glyphs = {read=FGlyphs, write=FGlyphs};
	__property int GlyphCount = {read=FGlyphCount, write=FGlyphCount, nodefault};
	__property System::Types::TSize Size = {read=FSize, write=FSize};
public:
	/* TObject.Create */ inline __fastcall TdxTextViewInfo() : System::TObject() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTextViewInfoCache : public System::TObject
{
	typedef System::TObject inherited;
	
	
protected:
	class DELPHICLASS TItem;
	class PASCALIMPLEMENTATION TItem : public System::TObject
	{
		typedef System::TObject inherited;
		
	private:
		unsigned FHash;
		System::UnicodeString FText;
		Dxfonthelpers::TdxFontInfo* FFontInfo;
		TdxTextViewInfo* FTextViewInfo;
		TdxTextViewInfoCache::TItem* FNext;
		
	public:
		__fastcall TItem(const System::UnicodeString AText, Dxfonthelpers::TdxFontInfo* AFontInfo, TdxTextViewInfo* ATextInfo);
		__fastcall virtual ~TItem();
		HIDESBASE bool __fastcall Equals(TdxTextViewInfoCache::TItem* AEntry)/* overload */;
		HIDESBASE bool __fastcall Equals(unsigned AHash, const System::UnicodeString AText, Dxfonthelpers::TdxFontInfo* AFontInfo)/* overload */;
		static unsigned __fastcall CalcHash(const System::UnicodeString AText, Dxfonthelpers::TdxFontInfo* AFontInfo);
		__property unsigned Hash = {read=FHash, nodefault};
		__property System::UnicodeString Text = {read=FText};
		__property Dxfonthelpers::TdxFontInfo* FontInfo = {read=FFontInfo};
		__property TdxTextViewInfo* TextViewInfo = {read=FTextViewInfo};
		__property TdxTextViewInfoCache::TItem* Next = {read=FNext, write=FNext};
	};
	
	
	typedef System::DynamicArray<TItem*> TItemArray;
	
	
private:
	int FCount;
	TItemArray FTable;
	unsigned FTableSize;
	
public:
	__fastcall TdxTextViewInfoCache();
	__fastcall virtual ~TdxTextViewInfoCache();
	void __fastcall Clear();
	void __fastcall AddTextViewInfo(const System::UnicodeString AText, Dxfonthelpers::TdxFontInfo* AFontInfo, TdxTextViewInfo* ATextInfo);
	TdxTextViewInfo* __fastcall TryGetTextViewInfo(const System::UnicodeString AText, Dxfonthelpers::TdxFontInfo* AFontInfo);
	__property int Count = {read=FCount, nodefault};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomBoxMeasurer : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	int FCaretPosBufferSize;
	void *FCaretPosBuffer;
	TdxTextViewInfoCache* FTextViewInfoCache;
	
protected:
	void __fastcall AdjustCharacterBoundsForLigature(const System::DynamicArray<System::Types::TRect> ACharacterBounds, int AFrom, int ATo);
	void __fastcall EstimateCaretPositionsForLigatures(const System::DynamicArray<System::Types::TRect> ACharacterBounds);
	System::DynamicArray<System::Types::TRect> __fastcall CalculateCharactersBounds(PINT ACaret, int ALength, const System::Types::TRect &ABounds);
	virtual TdxTextViewInfo* __fastcall CreateTextViewInfoCore(HDC ADC, const System::UnicodeString AText, Dxfonthelpers::TdxFontInfo* AFontInfo);
	int __fastcall MeasureCharactersBoundsSlow(HDC ADC, const System::UnicodeString AText, tagGCP_RESULTSW &AGcpResults);
	int __fastcall MeasureWithGetCharacterPlacementSlow(HDC ADC, const System::UnicodeString AText, tagGCP_RESULTSW &AGcpResults);
	
public:
	__fastcall TdxCustomBoxMeasurer();
	__fastcall virtual ~TdxCustomBoxMeasurer();
	int __fastcall FindLengthToFit(HDC ADC, const System::UnicodeString AText, Dxfonthelpers::TdxFontInfo* AFontInfo, int AMaxWidth, bool ARestoreFont = false);
	virtual TdxTextViewInfo* __fastcall CreateTextViewInfo(HDC ADC, const System::UnicodeString AText, Dxfonthelpers::TdxFontInfo* AFontInfo) = 0 /* overload */;
	virtual TdxTextViewInfo* __fastcall CreateTextViewInfo(const System::UnicodeString AText, Dxfonthelpers::TdxFontInfo* AFontInfo) = 0 /* overload */;
	void * __fastcall GetCaretPosBuffer(int AItemsCount);
	virtual System::Types::TSize __fastcall MeasureText(const System::UnicodeString AText, Dxfonthelpers::TdxFontInfo* AFontInfo)/* overload */;
	virtual System::Types::TSize __fastcall MeasureText(HDC ADC, const System::UnicodeString AText, Dxfonthelpers::TdxFontInfo* AFontInfo)/* overload */;
	virtual System::DynamicArray<System::Types::TRect> __fastcall MeasureCharactersBounds(HDC ADC, const System::UnicodeString AText, Dxfonthelpers::TdxFontInfo* AFontInfo, const System::Types::TRect &ABounds)/* overload */;
	__property TdxTextViewInfoCache* TextViewInfoCache = {read=FTextViewInfoCache};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxtextviewinfocache */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXTEXTVIEWINFOCACHE)
using namespace Dxtextviewinfocache;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxtextviewinfocacheHPP
