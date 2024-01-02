// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxCoreGraphics.pas' rev: 35.00 (Windows)

#ifndef DxcoregraphicsHPP
#define DxcoregraphicsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.UITypes.hpp>
#include <Winapi.Windows.hpp>
#include <Winapi.Messages.hpp>
#include <System.Types.hpp>
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <Vcl.Graphics.hpp>
#include <System.Generics.Defaults.hpp>
#include <System.Generics.Collections.hpp>
#include <dxCore.hpp>
#include <dxCoreClasses.hpp>
#include <dxHashUtils.hpp>

//-- user supplied -----------------------------------------------------------

namespace Dxcoregraphics
{
//-- forward type declarations -----------------------------------------------
__interface DELPHIINTERFACE TdxAlphaColorFunc;
typedef System::DelphiInterface<TdxAlphaColorFunc> _di_TdxAlphaColorFunc;
struct TdxAlphaColors;
__interface DELPHIINTERFACE IdxColorPalette;
typedef System::DelphiInterface<IdxColorPalette> _di_IdxColorPalette;
class DELPHICLASS TdxCustomColorPalette;
class DELPHICLASS TdxSimpleColorPalette;
class DELPHICLASS TdxAdvancedColorPalette;
template<typename TKey, typename TValue> class DELPHICLASS TdxValueCacheManager__2;
struct TdxGdiClippingHelper;
struct TdxRTLReadingCharacterPlacementHelper;
class DELPHICLASS TdxTextMeasurer;
class DELPHICLASS TdxColors;
class DELPHICLASS TdxCustomFastDIB;
class DELPHICLASS TdxFastDIB;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TdxAlphaState : unsigned int { asNoAlpha, asSemitransparent, asOpaque };

typedef unsigned TdxAlphaColor;

typedef TdxAlphaColor *PdxAlphaColor;

typedef System::DynamicArray<TdxAlphaColor> TdxAlphaColorDynArray;

__interface TdxAlphaColorFunc  : public System::IInterface 
{
	virtual TdxAlphaColor __fastcall Invoke() = 0 ;
};

struct DECLSPEC_DRECORD TdxAlphaColors
{
	
private:
	enum DECLSPEC_DENUM TSystemColor : unsigned int { cActiveBorder, cActiveCaption, cActiveCaptionText, cAppWorkspace, cButtonFace, cButtonHighlight, cButtonShadow, cControl, cControlDark, cControlDarkDark, cControlLight, cControlLightLight, cControlText, cDesktop, cGradientActiveCaption, cGradientInactiveCaption, cGrayText, cHighlight, cHighlightText, cHotTrack, cInactiveBorder, cInactiveCaption, cInactiveCaptionText, cInfo, cInfoText, cMenu, cMenuBar, cMenuHighlight, cMenuText, cScrollBar, cWindow, cWindowFrame, cWindowText };
	
	struct DECLSPEC_DRECORD TSystemColorData
	{
	public:
		System::UnicodeString Name;
		int Index;
	};
	
	
	struct DECLSPEC_DRECORD TColorInfo
	{
	public:
		TdxAlphaColor Color;
		System::UnicodeString Name;
	};
	
	
	class DELPHICLASS TUpdateSystemColorsListener;
	#pragma pack(push,4)
	class PASCALIMPLEMENTATION TUpdateSystemColorsListener : public System::TObject
	{
		typedef System::TObject inherited;
		
	private:
		HWND FHandle;
		
	public:
		__fastcall TUpdateSystemColorsListener();
		__fastcall virtual ~TUpdateSystemColorsListener();
		void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	};
	
	#pragma pack(pop)
	
	
private:
	typedef System::StaticArray<TSystemColorData, 33> _TdxAlphaColors__1;
	
	
private:
	static _TdxAlphaColors__1 SystemColorsData;
	static System::Generics::Collections::TDictionary__2<System::UnicodeString,TdxAlphaColor>* FNameToColorMap;
	static System::Generics::Collections::TDictionary__2<System::UnicodeString,TdxAlphaColor>* FHtmlNameToColorMap;
	static System::Generics::Collections::TList__1<TColorInfo>* FColorToNameMap;
	static System::StaticArray<TdxAlphaColor, 33> FSystemColors;
	static TUpdateSystemColorsListener* FSystemColorsListener;
	// __classmethod void __fastcall Initialize@();
	// __classmethod void __fastcall Finalize@();
	static void __fastcall CreateColors();
	static void __fastcall CreateHtmlColors();
	static void __fastcall AddNamedColor(const System::UnicodeString AName, TdxAlphaColor AColor);
	static TdxAlphaColor __fastcall GetSystemAlphaColor(TSystemColor AColor);
	
public:
	static void __fastcall UpdateSystemColors();
	static void __fastcall UpdateHtmlSystemColors();
	static const System::Int8 Empty = System::Int8(0x0);
	
	static const int Transparent = int(0xffffff);
	
	static const int Default = int(0x10203);
	
	static const unsigned AliceBlue = unsigned(0xfff0f8ff);
	
	static const unsigned AntiqueWhite = unsigned(0xfffaebd7);
	
	static const unsigned Aqua = unsigned(0xff00ffff);
	
	static const unsigned Aquamarine = unsigned(0xff7fffd4);
	
	static const unsigned Azure = unsigned(0xfff0ffff);
	
	static const unsigned Beige = unsigned(0xfff5f5dc);
	
	static const unsigned Bisque = unsigned(0xffffe4c4);
	
	static const unsigned Black = unsigned(0xff000000);
	
	static const unsigned BlanchedAlmond = unsigned(0xffffebcd);
	
	static const unsigned Blue = unsigned(0xff0000ff);
	
	static const unsigned BlueViolet = unsigned(0xff8a2be2);
	
	static const unsigned Brown = unsigned(0xffa52a2a);
	
	static const unsigned BurlyWood = unsigned(0xffdeb887);
	
	static const unsigned CadetBlue = unsigned(0xff5f9ea0);
	
	static const unsigned Chartreuse = unsigned(0xff7fff00);
	
	static const unsigned Chocolate = unsigned(0xffd2691e);
	
	static const unsigned Coral = unsigned(0xffff7f50);
	
	static const unsigned CornflowerBlue = unsigned(0xff6495ed);
	
	static const unsigned Cornsilk = unsigned(0xfffff8dc);
	
	static const unsigned Crimson = unsigned(0xffdc143c);
	
	static const unsigned Cyan = unsigned(0xff00ffff);
	
	static const unsigned DarkBlue = unsigned(0xff00008b);
	
	static const unsigned DarkCyan = unsigned(0xff008b8b);
	
	static const unsigned DarkGoldenrod = unsigned(0xffb8860b);
	
	static const unsigned DarkGray = unsigned(0xffa9a9a9);
	
	static const unsigned DarkGreen = unsigned(0xff006400);
	
	static const unsigned DarkKhaki = unsigned(0xffbdb76b);
	
	static const unsigned DarkMagenta = unsigned(0xff8b008b);
	
	static const unsigned DarkOliveGreen = unsigned(0xff556b2f);
	
	static const unsigned DarkOrange = unsigned(0xffff8c00);
	
	static const unsigned DarkOrchid = unsigned(0xff9932cc);
	
	static const unsigned DarkRed = unsigned(0xff8b0000);
	
	static const unsigned DarkSalmon = unsigned(0xffe9967a);
	
	static const unsigned DarkSeaGreen = unsigned(0xff8fbc8b);
	
	static const unsigned DarkSlateBlue = unsigned(0xff483d8b);
	
	static const unsigned DarkSlateGray = unsigned(0xff2f4f4f);
	
	static const unsigned DarkTurquoise = unsigned(0xff00ced1);
	
	static const unsigned DarkViolet = unsigned(0xff9400d3);
	
	static const unsigned DeepPink = unsigned(0xffff1493);
	
	static const unsigned DeepSkyBlue = unsigned(0xff00bfff);
	
	static const unsigned DimGray = unsigned(0xff696969);
	
	static const unsigned DodgerBlue = unsigned(0xff1e90ff);
	
	static const unsigned Firebrick = unsigned(0xffb22222);
	
	static const unsigned FloralWhite = unsigned(0xfffffaf0);
	
	static const unsigned ForestGreen = unsigned(0xff228b22);
	
	static const unsigned Fuchsia = unsigned(0xffff00ff);
	
	static const unsigned Gainsboro = unsigned(0xffdcdcdc);
	
	static const unsigned GhostWhite = unsigned(0xfff8f8ff);
	
	static const unsigned Gold = unsigned(0xffffd700);
	
	static const unsigned Goldenrod = unsigned(0xffdaa520);
	
	static const unsigned Gray = unsigned(0xff808080);
	
	static const unsigned Green = unsigned(0xff008000);
	
	static const unsigned GreenYellow = unsigned(0xffadff2f);
	
	static const unsigned Honeydew = unsigned(0xfff0fff0);
	
	static const unsigned HotPink = unsigned(0xffff69b4);
	
	static const unsigned IndianRed = unsigned(0xffcd5c5c);
	
	static const unsigned Indigo = unsigned(0xff4b0082);
	
	static const unsigned Ivory = unsigned(0xfffffff0);
	
	static const unsigned Khaki = unsigned(0xfff0e68c);
	
	static const unsigned Lavender = unsigned(0xffe6e6fa);
	
	static const unsigned LavenderBlush = unsigned(0xfffff0f5);
	
	static const unsigned LawnGreen = unsigned(0xff7cfc00);
	
	static const unsigned LemonChiffon = unsigned(0xfffffacd);
	
	static const unsigned LightBlue = unsigned(0xffadd8e6);
	
	static const unsigned LightCoral = unsigned(0xfff08080);
	
	static const unsigned LightCyan = unsigned(0xffe0ffff);
	
	static const unsigned LightGoldenrodYellow = unsigned(0xfffafad2);
	
	static const unsigned LightGray = unsigned(0xffd3d3d3);
	
	static const unsigned LightGreen = unsigned(0xff90ee90);
	
	static const unsigned LightPink = unsigned(0xffffb6c1);
	
	static const unsigned LightSalmon = unsigned(0xffffa07a);
	
	static const unsigned LightSeaGreen = unsigned(0xff20b2aa);
	
	static const unsigned LightSkyBlue = unsigned(0xff87cefa);
	
	static const unsigned LightSlateGray = unsigned(0xff778899);
	
	static const unsigned LightSteelBlue = unsigned(0xffb0c4de);
	
	static const unsigned LightYellow = unsigned(0xffffffe0);
	
	static const unsigned Lime = unsigned(0xff00ff00);
	
	static const unsigned LimeGreen = unsigned(0xff32cd32);
	
	static const unsigned Linen = unsigned(0xfffaf0e6);
	
	static const unsigned Magenta = unsigned(0xffff00ff);
	
	static const unsigned Maroon = unsigned(0xff800000);
	
	static const unsigned MediumAquamarine = unsigned(0xff66cdaa);
	
	static const unsigned MediumBlue = unsigned(0xff0000cd);
	
	static const unsigned MediumOrchid = unsigned(0xffba55d3);
	
	static const unsigned MediumPurple = unsigned(0xff9370db);
	
	static const unsigned MediumSeaGreen = unsigned(0xff3cb371);
	
	static const unsigned MediumSlateBlue = unsigned(0xff7b68ee);
	
	static const unsigned MediumSpringGreen = unsigned(0xff00fa9a);
	
	static const unsigned MediumTurquoise = unsigned(0xff48d1cc);
	
	static const unsigned MediumVioletRed = unsigned(0xffc71585);
	
	static const unsigned MidnightBlue = unsigned(0xff191970);
	
	static const unsigned MintCream = unsigned(0xfff5fffa);
	
	static const unsigned MistyRose = unsigned(0xffffe4e1);
	
	static const unsigned Moccasin = unsigned(0xffffe4b5);
	
	static const unsigned NavajoWhite = unsigned(0xffffdead);
	
	static const unsigned Navy = unsigned(0xff000080);
	
	static const unsigned OldLace = unsigned(0xfffdf5e6);
	
	static const unsigned Olive = unsigned(0xff808000);
	
	static const unsigned OliveDrab = unsigned(0xff6b8e23);
	
	static const unsigned Orange = unsigned(0xffffa500);
	
	static const unsigned OrangeRed = unsigned(0xffff4500);
	
	static const unsigned Orchid = unsigned(0xffda70d6);
	
	static const unsigned PaleGoldenrod = unsigned(0xffeee8aa);
	
	static const unsigned PaleGreen = unsigned(0xff98fb98);
	
	static const unsigned PaleTurquoise = unsigned(0xffafeeee);
	
	static const unsigned PaleVioletRed = unsigned(0xffdb7093);
	
	static const unsigned PapayaWhip = unsigned(0xffffefd5);
	
	static const unsigned PeachPuff = unsigned(0xffffdab9);
	
	static const unsigned Peru = unsigned(0xffcd853f);
	
	static const unsigned Pink = unsigned(0xffffc0cb);
	
	static const unsigned Plum = unsigned(0xffdda0dd);
	
	static const unsigned PowderBlue = unsigned(0xffb0e0e6);
	
	static const unsigned Purple = unsigned(0xff800080);
	
	static const unsigned Red = unsigned(0xffff0000);
	
	static const unsigned RosyBrown = unsigned(0xffbc8f8f);
	
	static const unsigned RoyalBlue = unsigned(0xff4169e1);
	
	static const unsigned SaddleBrown = unsigned(0xff8b4513);
	
	static const unsigned Salmon = unsigned(0xfffa8072);
	
	static const unsigned SandyBrown = unsigned(0xfff4a460);
	
	static const unsigned SeaGreen = unsigned(0xff2e8b57);
	
	static const unsigned SeaShell = unsigned(0xfffff5ee);
	
	static const unsigned Sienna = unsigned(0xffa0522d);
	
	static const unsigned Silver = unsigned(0xffc0c0c0);
	
	static const unsigned SkyBlue = unsigned(0xff87ceeb);
	
	static const unsigned SlateBlue = unsigned(0xff6a5acd);
	
	static const unsigned SlateGray = unsigned(0xff708090);
	
	static const unsigned Snow = unsigned(0xfffffafa);
	
	static const unsigned SpringGreen = unsigned(0xff00ff7f);
	
	static const unsigned SteelBlue = unsigned(0xff4682b4);
	
	static const unsigned Tan = unsigned(0xffd2b48c);
	
	static const unsigned Teal = unsigned(0xff008080);
	
	static const unsigned Thistle = unsigned(0xffd8bfd8);
	
	static const unsigned Tomato = unsigned(0xffff6347);
	
	static const unsigned Turquoise = unsigned(0xff40e0d0);
	
	static const unsigned Violet = unsigned(0xffee82ee);
	
	static const unsigned Wheat = unsigned(0xfff5deb3);
	
	static const unsigned White = unsigned(0xffffffff);
	
	static const unsigned WhiteSmoke = unsigned(0xfff5f5f5);
	
	static const unsigned Yellow = unsigned(0xffffff00);
	
	static const unsigned YellowGreen = unsigned(0xff9acd32);
	
	static TdxAlphaColor __fastcall _3DDkShadow();
	static TdxAlphaColor __fastcall _3DLight();
	static TdxAlphaColor __fastcall ActiveBorder();
	static TdxAlphaColor __fastcall ActiveCaption();
	static TdxAlphaColor __fastcall ActiveCaptionText();
	static TdxAlphaColor __fastcall AppWorkSpace();
	static TdxAlphaColor __fastcall Background();
	static TdxAlphaColor __fastcall BtnFace();
	static TdxAlphaColor __fastcall BtnHighlight();
	static TdxAlphaColor __fastcall BtnShadow();
	static TdxAlphaColor __fastcall BtnText();
	static TdxAlphaColor __fastcall ButtonFace();
	static TdxAlphaColor __fastcall ButtonHighlight();
	static TdxAlphaColor __fastcall ButtonShadow();
	static TdxAlphaColor __fastcall CaptionText();
	static TdxAlphaColor __fastcall Control();
	static TdxAlphaColor __fastcall ControlDark();
	static TdxAlphaColor __fastcall ControlDarkDark();
	static TdxAlphaColor __fastcall ControlLight();
	static TdxAlphaColor __fastcall ControlLightLight();
	static TdxAlphaColor __fastcall ControlText();
	static TdxAlphaColor __fastcall Desktop();
	static TdxAlphaColor __fastcall GradientActiveCaption();
	static TdxAlphaColor __fastcall GradientInactiveCaption();
	static TdxAlphaColor __fastcall GrayText();
	static TdxAlphaColor __fastcall Highlight();
	static TdxAlphaColor __fastcall HighlightText();
	static TdxAlphaColor __fastcall HotLight();
	static TdxAlphaColor __fastcall HotTrack();
	static TdxAlphaColor __fastcall InactiveBorder();
	static TdxAlphaColor __fastcall InactiveCaption();
	static TdxAlphaColor __fastcall InactiveCaptionText();
	static TdxAlphaColor __fastcall Info();
	static TdxAlphaColor __fastcall InfoBk();
	static TdxAlphaColor __fastcall InfoText();
	static TdxAlphaColor __fastcall Menu();
	static TdxAlphaColor __fastcall MenuBar();
	static TdxAlphaColor __fastcall MenuHighlight();
	static TdxAlphaColor __fastcall MenuText();
	static TdxAlphaColor __fastcall ScrollBar();
	static TdxAlphaColor __fastcall Window();
	static TdxAlphaColor __fastcall WindowFrame();
	static TdxAlphaColor __fastcall WindowText();
	static TdxAlphaColor __fastcall Blend(TdxAlphaColor AColor, TdxAlphaColor ABackgroundColor)/* overload */;
	static TdxAlphaColor __fastcall CalculateNearestColor(const TdxAlphaColor *AColorsToChooseFrom, const int AColorsToChooseFrom_High, TdxAlphaColor AValue);
	static TdxAlphaColor __fastcall ChangeBrightness(TdxAlphaColor AColor, float ABrightness);
	static TdxAlphaColor __fastcall ConvertNotation(TdxAlphaColor AColor);
	static TdxAlphaColor __fastcall GetActualValue(TdxAlphaColor AColor, TdxAlphaColor ADefaultColor);
	static float __fastcall GetBrightness(TdxAlphaColor AColor);
	static float __fastcall GetHue(TdxAlphaColor AColor);
	static float __fastcall GetSaturation(TdxAlphaColor AColor);
	static bool __fastcall IsEmpty(TdxAlphaColor AColor)/* overload */;
	static bool __fastcall IsTransparentOrEmpty(const TdxAlphaColor AColor)/* overload */;
	static System::Byte __fastcall Alpha(TdxAlphaColor AColor);
	static System::Byte __fastcall R(TdxAlphaColor AColor);
	static System::Byte __fastcall G(TdxAlphaColor AColor);
	static System::Byte __fastcall B(TdxAlphaColor AColor);
	static System::UnicodeString __fastcall GetColorName(TdxAlphaColor AColor);
	static bool __fastcall IsKnownColor(TdxAlphaColor AColor);
	static TdxAlphaColor __fastcall FromArgb(System::Byte ARed, System::Byte AGreen, System::Byte ABlue)/* overload */;
	static TdxAlphaColor __fastcall FromArgb(System::Byte AAlpha, System::Byte ARed, System::Byte AGreen, System::Byte ABlue)/* overload */;
	static TdxAlphaColor __fastcall FromArgb(System::Byte AAlpha, TdxAlphaColor ABaseColor)/* overload */;
	static TdxAlphaColor __fastcall FromColor(const System::Uitypes::TColor AColor)/* overload */;
	static TdxAlphaColor __fastcall FromHSL(float H, float S, float L)/* overload */;
	static TdxAlphaColor __fastcall FromHexCode(const System::UnicodeString AHexCode, bool AIsDelphiNotation = false);
	static TdxAlphaColor __fastcall FromHtml(const System::UnicodeString AHtmlColor);
	static TdxAlphaColor __fastcall FromName(const System::UnicodeString AName);
	static TdxAlphaColor __fastcall FromString(const System::UnicodeString S);
	static unsigned __fastcall ToArgb(const TdxAlphaColor AColor);
	static System::Uitypes::TColor __fastcall ToColor(const TdxAlphaColor AColor)/* overload */;
	static System::UnicodeString __fastcall ToHexCode(TdxAlphaColor AColor, bool AUseAlpha = false, bool AUseDelphiNotation = false)/* overload */;
	static System::UnicodeString __fastcall ToHexCode(TdxAlphaColor AColor, bool AUseAlpha, System::WideChar APrefix)/* overload */;
	static System::UnicodeString __fastcall ToHtml(TdxAlphaColor AColor, bool AUseNamedColors = true);
	static void __fastcall ToHSL(TdxAlphaColor AColor, /* out */ float &H, /* out */ float &S, /* out */ float &L);
	static System::UnicodeString __fastcall ToString(TdxAlphaColor AColor, bool AUseDelphiNotation = false);
	static void __fastcall GetPropertyValues(const System::Classes::TGetStrProc AProc);
	static System::UnicodeString __fastcall GetPropertyValue(int AValue);
	static int __fastcall SetPropertyValue(const System::UnicodeString AValue);
};


typedef System::DynamicArray<tagRGBQUAD> TRGBColors;

typedef System::StaticArray<tagRGBQUAD, 1> TdxRGBQuadArray;

typedef TdxRGBQuadArray *PdxRGBQuadArray;

enum DECLSPEC_DENUM TdxGraphicUnit : unsigned int { guWorld, guDisplay, guPixel, guPoint, guInch, guDocument, guMillimeter };

__interface  INTERFACE_UUID("{D0CB7E80-BE5A-4532-972C-5046B346FDA5}") IdxColorPalette  : public System::IInterface 
{
	virtual GUID __fastcall GetID() = 0 ;
	virtual TdxAlphaColor __fastcall GetFillColor(const System::UnicodeString ID) = 0 ;
	virtual TdxAlphaColor __fastcall GetStrokeColor(const System::UnicodeString ID) = 0 ;
};

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomColorPalette : public System::TInterfacedObject
{
	typedef System::TInterfacedObject inherited;
	
protected:
	GUID FID;
	virtual void __fastcall Changed();
	virtual void __fastcall GenerateID();
	
public:
	virtual void __fastcall AfterConstruction();
	GUID __fastcall GetID();
	virtual TdxAlphaColor __fastcall GetFillColor(const System::UnicodeString ID) = 0 ;
	virtual TdxAlphaColor __fastcall GetStrokeColor(const System::UnicodeString ID) = 0 ;
public:
	/* TObject.Create */ inline __fastcall TdxCustomColorPalette() : System::TInterfacedObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxCustomColorPalette() { }
	
private:
	void *__IdxColorPalette;	// IdxColorPalette 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {D0CB7E80-BE5A-4532-972C-5046B346FDA5}
	operator _di_IdxColorPalette()
	{
		_di_IdxColorPalette intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IdxColorPalette*(void) { return (IdxColorPalette*)&__IdxColorPalette; }
	#endif
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSimpleColorPalette : public TdxCustomColorPalette
{
	typedef TdxCustomColorPalette inherited;
	
private:
	TdxAlphaColor FFillColor;
	TdxAlphaColor FStrokeColor;
	void __fastcall SetFillColor(const TdxAlphaColor Value);
	void __fastcall SetStrokeColor(const TdxAlphaColor Value);
	
protected:
	virtual void __fastcall GenerateID();
	
public:
	__fastcall TdxSimpleColorPalette(TdxAlphaColor AFillColor, TdxAlphaColor AStrokeColor);
	virtual TdxAlphaColor __fastcall GetFillColor(const System::UnicodeString ID);
	virtual TdxAlphaColor __fastcall GetStrokeColor(const System::UnicodeString ID);
	__property TdxAlphaColor FillColor = {read=FFillColor, write=SetFillColor, nodefault};
	__property TdxAlphaColor StrokeColor = {read=FStrokeColor, write=SetStrokeColor, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSimpleColorPalette() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAdvancedColorPalette : public TdxCustomColorPalette
{
	typedef TdxCustomColorPalette inherited;
	
private:
	System::Generics::Collections::TDictionary__2<System::UnicodeString,TdxAlphaColor>* FFillColors;
	System::Generics::Collections::TDictionary__2<System::UnicodeString,TdxAlphaColor>* FStrokeColors;
	void __fastcall HandlerKeyChanged(System::TObject* Sender, const System::UnicodeString Item, System::Generics::Collections::TCollectionNotification Action);
	void __fastcall HandlerValueChanged(System::TObject* Sender, const TdxAlphaColor Item, System::Generics::Collections::TCollectionNotification Action);
	void __fastcall SetFillColor(const System::UnicodeString ID, const TdxAlphaColor Value);
	void __fastcall SetStrokeColor(const System::UnicodeString ID, const TdxAlphaColor Value);
	
public:
	__fastcall TdxAdvancedColorPalette();
	__fastcall virtual ~TdxAdvancedColorPalette();
	virtual TdxAlphaColor __fastcall GetFillColor(const System::UnicodeString ID);
	virtual TdxAlphaColor __fastcall GetStrokeColor(const System::UnicodeString ID);
	__property TdxAlphaColor FillColors[const System::UnicodeString ID] = {read=GetFillColor, write=SetFillColor};
	__property TdxAlphaColor StrokeColors[const System::UnicodeString ID] = {read=GetStrokeColor, write=SetStrokeColor};
};

#pragma pack(pop)

#pragma pack(push,4)
// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename TKey, typename TValue> class PASCALIMPLEMENTATION TdxValueCacheManager__2 : public System::TObject
{
	typedef System::TObject inherited;
	
	
private:
	typedef System::Generics::Collections::TPair__2<TKey,bool> *PQueueItem;
	
	
public:
	typedef System::DynamicArray<System::Generics::Collections::TPair__2<TKey,bool> > _1;
	
	
private:
	int FCapacity;
	System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<TKey> > FComparer;
	System::Generics::Collections::TDictionary__2<TKey,TValue>* FData;
	System::DynamicArray<System::Generics::Collections::TPair__2<TKey,bool> > FQueue;
	int FQueueCursor;
	void __fastcall CreateDataDictionary();
	void __fastcall ValueHandler(System::TObject* Sender, const TValue Item, System::Generics::Collections::TCollectionNotification Action);
	
protected:
	virtual void __fastcall DoRemove(const TValue Value);
	
public:
	__fastcall TdxValueCacheManager__2(int ACapacity)/* overload */;
	__fastcall TdxValueCacheManager__2(int ACapacity, System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<TKey> > AEqualityComparer)/* overload */;
	__fastcall virtual ~TdxValueCacheManager__2();
	void __fastcall Add(const TKey Key, const TValue Value);
	void __fastcall Clear();
	bool __fastcall Get(const TKey Key, /* out */ TValue &Value);
	void __fastcall Remove(const TKey Key);
};

#pragma pack(pop)

struct DECLSPEC_DRECORD TdxGdiClippingHelper
{
public:
	static void __fastcall AddClippingRectangle(HDC DC, const System::Types::TRect &R);
	static void __fastcall AddRectangleToRegion(HRGN &ARegion, const System::Types::TRect &R);
	static void __fastcall ExcludeRectangleFromRegion(HRGN &ARegion, const System::Types::TRect &R);
	static void __fastcall RestoreClipping(HDC DC, HRGN ARegion);
	static void __fastcall SaveClipping(HDC DC, /* out */ HRGN &ARegion);
};


struct DECLSPEC_DRECORD TdxRTLReadingCharacterPlacementHelper
{
private:
	static System::StaticArray<int, 2> GCPFlags;
	static System::DynamicArray<System::Types::TRect> __fastcall CalculateCharactersBounds(const tagGCP_RESULTSW &AGcpResults, int ALength, const System::Types::TRect &ABounds);
	static int __fastcall TryMeasureCharactersSlow(NativeUInt ADC, const System::WideChar * AText, int ALength, tagGCP_RESULTSW &AGcpResults, int AFlags);
	
public:
	static HRGN __fastcall GetSelectionRangeRegion(HDC ADC, const System::WideChar * AText, int ALength, const System::Types::TRect &ABounds, int ASelStart, int ASelLength, HFONT AFont = (HFONT)(0x0), bool AIsRTLReading = false);
	static System::DynamicArray<System::Types::TRect> __fastcall MeasureCharactersBounds(HDC ADC, const System::WideChar * AText, int ALength, const System::Types::TRect &ABounds, HFONT AFont = (HFONT)(0x0), bool AIsRTLReading = false);
};


enum DECLSPEC_DENUM TcxModifyStringType : unsigned int { mstEndEllipsis, mstPathEllipsis };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTextMeasurer : public System::TObject
{
	typedef System::TObject inherited;
	
	
protected:
	typedef void __fastcall (*TCalcRectProc)(HDC ADC, const System::UnicodeString AText, System::Types::TRect &R, unsigned AFlags);
	
	class DELPHICLASS TMeasureCanvas;
	#pragma pack(push,8)
	class PASCALIMPLEMENTATION TMeasureCanvas : public Vcl::Graphics::TCanvas
	{
		typedef Vcl::Graphics::TCanvas inherited;
		
	private:
		HDC FDeviceContext;
		
	protected:
		virtual void __fastcall CreateHandle();
		void __fastcall FreeHandle();
		
	public:
		HIDESBASE void __fastcall SetFont(Vcl::Graphics::TFont* AFont);
		__fastcall virtual ~TMeasureCanvas();
	public:
		/* TCanvas.Create */ inline __fastcall TMeasureCanvas() : Vcl::Graphics::TCanvas() { }
		
	};
	
	#pragma pack(pop)
	
	
private:
	static TMeasureCanvas* FMeasureCanvas;
	static Vcl::Graphics::TFont* FBufferFont;
	static void __fastcall CalcTextRectDT(HDC ADC, const System::UnicodeString AText, System::Types::TRect &R, unsigned AFlags);
	static Vcl::Graphics::TCanvas* __fastcall GetMeasureCanvas();
	
protected:
	static System::Types::TRect __fastcall TextRectCore(NativeUInt ADC, const System::UnicodeString AText, int ARowCount, TCalcRectProc ACalcRectFunc, int ASingleLineFlags, int AMultilineFlags, bool AReturnMaxRectHeight)/* overload */;
	
private:
	// __classmethod void __fastcall Initialize@();
	// __classmethod void __fastcall Finalize@();
	
public:
	static int __fastcall TextIndent(Vcl::Graphics::TFont* AFont);
	static int __fastcall TextLineHeight(NativeUInt ADC)/* overload */;
	static int __fastcall TextLineHeight(Vcl::Graphics::TFont* AFont)/* overload */;
	static int __fastcall TextLineHeight(Vcl::Graphics::TFont* AFont, System::Uitypes::TFontStyles AFontStyle)/* overload */;
	static bool __fastcall TextMetrics(Vcl::Graphics::TFont* AFont, /* out */ tagTEXTMETRICW &ATextMetric);
	static System::Types::TSize __fastcall TextSizeTO(Vcl::Graphics::TFont* AFont, const System::UnicodeString AText, int AFontSize = 0x0)/* overload */;
	static System::Types::TSize __fastcall TextSizeTO(NativeUInt AFontHandle, const System::UnicodeString AText)/* overload */;
	static int __fastcall TextHeightTO(Vcl::Graphics::TFont* AFont, const System::UnicodeString AText, int AFontSize = 0x0)/* overload */;
	static int __fastcall TextWidthTO(Vcl::Graphics::TFont* AFont, const System::UnicodeString AText, int AFontSize = 0x0)/* overload */;
	static int __fastcall TextWidthTO(Vcl::Graphics::TFont* AFont, const System::UnicodeString AText, System::Uitypes::TFontStyles AFontStyle)/* overload */;
	static System::UnicodeString __fastcall GetStringAdjustedToWidthDT(Vcl::Graphics::TFont* AFont, const System::UnicodeString S, int AWidth, TcxModifyStringType AModifyStringType)/* overload */;
	static System::UnicodeString __fastcall GetStringAdjustedToWidthDT(HDC ADC, HFONT AFontHandle, const System::UnicodeString S, int AWidth, TcxModifyStringType AModifyStringType)/* overload */;
	static void __fastcall TextRectDT(System::Types::TRect &ARect, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, int ADTFlags = 0x0)/* overload */;
	static System::Types::TRect __fastcall TextRectDT(Vcl::Graphics::TFont* AFont, const System::UnicodeString AText, int ARowCount, bool AConsiderLineBreaks = false)/* overload */;
	static System::Types::TRect __fastcall TextRectDT(NativeUInt ADC, const System::UnicodeString AText, int ARowCount, bool AReturnMaxRectHeight = false, int ADTFlags = 0x0)/* overload */;
	static System::Types::TSize __fastcall TextSizeDT(Vcl::Graphics::TFont* AFont, const System::UnicodeString AText, int AFlags = 0x0)/* overload */;
	static System::Types::TSize __fastcall TextSizeDT(NativeUInt ADC, const System::UnicodeString AText)/* overload */;
	static int __fastcall TextHeightDT(Vcl::Graphics::TFont* AFont, const System::UnicodeString AText, const System::Types::TRect &R, int AFlags)/* overload */;
	static int __fastcall GetEndEllipsisTextHeightDT(Vcl::Graphics::TFont* AFont, const System::UnicodeString AText, int AWidth, int AMaxHeight, int AFlags);
	/* static */ __property Vcl::Graphics::TCanvas* MeasureCanvas = {read=GetMeasureCanvas};
public:
	/* TObject.Create */ inline __fastcall TdxTextMeasurer() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxTextMeasurer() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxColors : public System::TObject
{
	typedef System::TObject inherited;
	
	
public:
	typedef float __fastcall (*TFilterFunc)(float AValue);
	
	
public:
	static System::StaticArray<System::StaticArray<System::Byte, 256>, 256> PremultiplyTable;
	static System::StaticArray<System::StaticArray<System::Byte, 256>, 256> UnPremultiplyTable;
	__classmethod void __fastcall Initialize();
	__classmethod bool __fastcall ArePremultiplied(Winapi::Windows::PRGBQuad AColors, int ACount)/* overload */;
	__classmethod bool __fastcall ArePremultiplied(const TRGBColors AColors)/* overload */;
	__classmethod void __fastcall Premultiply(Winapi::Windows::PRGBQuad AColors, int ACount);
	__classmethod void __fastcall UnPremultiply(Winapi::Windows::PRGBQuad AColors, int ACount);
	__classmethod void __fastcall GrayScale(Winapi::Windows::PRGBQuad AColors, int ACount);
	static float __fastcall FilterBell(float AValue);
	static float __fastcall FilterHermite(float AValue);
	static float __fastcall FilterLanczos2(float AValue);
	static float __fastcall FilterLanczos3(float AValue);
	static float __fastcall FilterLanczosN(float AValue, float N);
	static float __fastcall FilterLinear(float AValue);
	static float __fastcall FilterNearestNeighbour(float AValue);
	static float __fastcall FilterSpline(float AValue);
	static void __fastcall SmoothResize(Vcl::Graphics::TBitmap* ASource, Vcl::Graphics::TBitmap* ATarget, TFilterFunc AFilterFunc)/* overload */;
	static void __fastcall SmoothResize(PdxRGBQuadArray ASourceColors, int ASourceWidth, int ASourceHeight, PdxRGBQuadArray ATargetColors, int ATargetWidth, int ATargetHeight, TFilterFunc AFilterFunc)/* overload */;
public:
	/* TObject.Create */ inline __fastcall TdxColors() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxColors() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomFastDIB : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Types::TRect __fastcall GetClientRect();
	Winapi::Windows::PRGBQuad __fastcall GetPixel(int X, int Y);
	bool __fastcall InRange(int X, int Y);
	
protected:
	tagRGBQUAD *FBits;
	int FHeight;
	int FWidth;
	virtual void __fastcall Allocate() = 0 ;
	virtual void __fastcall Release() = 0 ;
	
public:
	__fastcall TdxCustomFastDIB(int AWidth, int AHeight, bool AClear)/* overload */;
	__fastcall TdxCustomFastDIB(const System::Types::TRect &R, bool AClear)/* overload */;
	__fastcall TdxCustomFastDIB(const System::Types::TSize &S, bool AClear)/* overload */;
	__fastcall virtual ~TdxCustomFastDIB();
	virtual void __fastcall Clear() = 0 ;
	void __fastcall ChangeColor(System::Uitypes::TColor AColor);
	bool __fastcall Empty();
	HIDESBASE bool __fastcall Equals(TdxCustomFastDIB* ASource, int ACompareTolerance);
	void __fastcall Fill(const int X, const int Y, const tagRGBQUAD AColor, int ACompareTolerance = 0x0);
	void __fastcall GrayScale();
	void __fastcall MakeOpaque();
	void __fastcall MakeTransparent(const tagRGBQUAD ATransparentColor)/* overload */;
	void __fastcall MakeTransparent(const tagRGBQUAD ATransparentColor, int ACompareTolerance)/* overload */;
	void __fastcall Premultiply();
	void __fastcall Resize(int AWidth, int AHeight)/* overload */;
	void __fastcall Resize(const System::Types::TRect &R)/* overload */;
	void __fastcall UnPremultiply();
	__property Winapi::Windows::PRGBQuad Bits = {read=FBits};
	__property System::Types::TRect ClientRect = {read=GetClientRect};
	__property int Height = {read=FHeight, nodefault};
	__property Winapi::Windows::PRGBQuad Pixels[int X][int Y] = {read=GetPixel};
	__property int Width = {read=FWidth, nodefault};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFastDIB : public TdxCustomFastDIB
{
	typedef TdxCustomFastDIB inherited;
	
private:
	HBITMAP FBitmap;
	HDC FDC;
	
protected:
	virtual void __fastcall Allocate();
	virtual void __fastcall Release();
	
public:
	virtual void __fastcall Clear();
	__property HDC DC = {read=FDC, nodefault};
public:
	/* TdxCustomFastDIB.Create */ inline __fastcall TdxFastDIB(int AWidth, int AHeight, bool AClear)/* overload */ : TdxCustomFastDIB(AWidth, AHeight, AClear) { }
	/* TdxCustomFastDIB.Create */ inline __fastcall TdxFastDIB(const System::Types::TRect &R, bool AClear)/* overload */ : TdxCustomFastDIB(R, AClear) { }
	/* TdxCustomFastDIB.Create */ inline __fastcall TdxFastDIB(const System::Types::TSize &S, bool AClear)/* overload */ : TdxCustomFastDIB(S, AClear) { }
	/* TdxCustomFastDIB.Destroy */ inline __fastcall virtual ~TdxFastDIB() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
#define dxMeasurePattern L"Zq"
static const int dxacDefault = int(0x10203);
static const System::Int8 dxacNone = System::Int8(0x0);
extern DELPHI_PACKAGE bool __fastcall dxAlphaColorIsValid(TdxAlphaColor AColor);
extern DELPHI_PACKAGE System::Uitypes::TColor __fastcall dxAlphaColorToColor(TdxAlphaColor AColor)/* overload */;
extern DELPHI_PACKAGE System::Uitypes::TColor __fastcall dxAlphaColorToColor(TdxAlphaColor AColor, /* out */ System::Byte &AAlpha)/* overload */;
extern DELPHI_PACKAGE tagRGBQUAD __fastcall dxAlphaColorToRGBQuad(TdxAlphaColor AColor);
extern DELPHI_PACKAGE TdxAlphaColor __fastcall dxColorToAlphaColor(System::Uitypes::TColor AColor, System::Byte AAlpha = (System::Byte)(0xff));
extern DELPHI_PACKAGE System::Byte __fastcall dxGetAlpha(TdxAlphaColor AColor);
extern DELPHI_PACKAGE System::Byte __fastcall dxGetRed(TdxAlphaColor AColor);
extern DELPHI_PACKAGE System::Byte __fastcall dxGetGreen(TdxAlphaColor AColor);
extern DELPHI_PACKAGE System::Byte __fastcall dxGetBlue(TdxAlphaColor AColor);
extern DELPHI_PACKAGE TdxAlphaColor __fastcall dxMakeAlphaColor(System::Byte R, System::Byte G, System::Byte B)/* overload */;
extern DELPHI_PACKAGE TdxAlphaColor __fastcall dxMakeAlphaColor(System::Byte A, System::Byte R, System::Byte G, System::Byte B)/* overload */;
extern DELPHI_PACKAGE TdxAlphaColor __fastcall dxMakeAlphaColor(System::Uitypes::TColor AColor, System::Byte AAlpha = (System::Byte)(0xff))/* overload */;
extern DELPHI_PACKAGE tagRGBQUAD __fastcall dxColorToRGBQuad(System::Uitypes::TColor AColor, System::Byte AReserved = (System::Byte)(0x0));
extern DELPHI_PACKAGE TdxAlphaColor __fastcall dxRGBQuadToAlphaColor(const tagRGBQUAD ARGB);
extern DELPHI_PACKAGE System::Uitypes::TColor __fastcall dxRGBQuadToColor(const tagRGBQUAD ARGB);
extern DELPHI_PACKAGE int __fastcall cxGetBitmapPixelFormat(Vcl::Graphics::TBitmap* ABitmap);
extern DELPHI_PACKAGE void __fastcall dxFillBitmapInfoHeader(/* out */ tagBITMAPINFOHEADER &AHeader, int AWidth, int AHeight, System::WordBool ATopDownDIB)/* overload */;
extern DELPHI_PACKAGE void __fastcall dxFillBitmapInfoHeader(/* out */ tagBITMAPINFOHEADER &AHeader, Vcl::Graphics::TBitmap* ABitmap, System::WordBool ATopDownDIB)/* overload */;
extern DELPHI_PACKAGE bool __fastcall GetBitmapBits(Vcl::Graphics::TBitmap* ABitmap, TRGBColors &AColors, bool ATopDownDIB);
extern DELPHI_PACKAGE void __fastcall GetBitmapBitsByScanLine(Vcl::Graphics::TBitmap* ABitmap, TRGBColors &AColors);
extern DELPHI_PACKAGE void __fastcall SetBitmapBits(Vcl::Graphics::TBitmap* ABitmap, const TRGBColors AColors, bool ATopDownDIB);
extern DELPHI_PACKAGE TdxAlphaState __fastcall dxGetAlphaState(const TRGBColors AColors)/* overload */;
extern DELPHI_PACKAGE TdxAlphaState __fastcall dxGetAlphaState(Vcl::Graphics::TBitmap* const ABitmap)/* overload */;
extern DELPHI_PACKAGE void __fastcall dxChangeColor(Winapi::Windows::PRGBQuad AColors, int ACount, System::Uitypes::TColor AColor);
extern DELPHI_PACKAGE bool __fastcall dxIsAlphaUsed(Vcl::Graphics::TBitmap* ABitmap);
extern DELPHI_PACKAGE bool __fastcall dxAreColorsEqual(const tagRGBQUAD AColor1, const tagRGBQUAD AColor2, int ATolerance = 0x0);
extern DELPHI_PACKAGE GUID __fastcall dxGetColorPaletteID(const _di_IdxColorPalette AIntf);
extern DELPHI_PACKAGE HICON __fastcall dxLoadCursor(NativeUInt AInstance, const System::WideChar * ACursorName);
extern DELPHI_PACKAGE bool __fastcall dxGetBitmapData(HBITMAP ABitmapHandle, /* out */ tagBITMAP &ABitmapData);
extern DELPHI_PACKAGE bool __fastcall dxGetBrushData(HBRUSH ABrushHandle, /* out */ tagLOGBRUSH &ALogBrush)/* overload */;
extern DELPHI_PACKAGE tagLOGBRUSH __fastcall dxGetBrushData(HBRUSH ABrushHandle)/* overload */;
extern DELPHI_PACKAGE bool __fastcall dxGetFontData(HFONT AFontHandle, /* out */ tagLOGFONTW &ALogFont)/* overload */;
extern DELPHI_PACKAGE tagLOGFONTW __fastcall dxGetFontData(HFONT AFontHandle)/* overload */;
extern DELPHI_PACKAGE bool __fastcall dxGetPenData(HPEN APenHandle, /* out */ tagLOGPEN &ALogPen);
extern DELPHI_PACKAGE bool __fastcall cxGetRegionData(HRGN ARegionHandle, /* out */ Winapi::Windows::PRgnData &AData);
extern DELPHI_PACKAGE bool __fastcall dxGraphicIsEquals(Vcl::Graphics::TGraphic* AGraphic1, Vcl::Graphics::TGraphic* AGraphic2);
extern DELPHI_PACKAGE bool __fastcall dxAreFontsEqual(Vcl::Graphics::TFont* AFont1, Vcl::Graphics::TFont* AFont2);
}	/* namespace Dxcoregraphics */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXCOREGRAPHICS)
using namespace Dxcoregraphics;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxcoregraphicsHPP
