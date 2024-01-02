// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxDocumentLayoutUnitConverter.pas' rev: 35.00 (Windows)

#ifndef DxdocumentlayoutunitconverterHPP
#define DxdocumentlayoutunitconverterHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Types.hpp>
#include <dxCoreClasses.hpp>
#include <cxGeometry.hpp>
#include <dxCoreGraphics.hpp>
#include <dxGDIPlusClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Dxdocumentlayoutunitconverter
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TdxDocumentModelDpi;
class DELPHICLASS TdxDpiSupport;
class DELPHICLASS TdxGraphicsDpi;
class DELPHICLASS TdxDocumentLayoutUnitConverter;
class DELPHICLASS TdxDocumentLayoutUnitPixelsConverter;
class DELPHICLASS TdxDocumentLayoutUnitTwipsConverter;
class DELPHICLASS TdxDocumentLayoutUnitDocumentConverter;
//-- type declarations -------------------------------------------------------
enum class DECLSPEC_DENUM TdxDocumentLayoutUnit : unsigned char { Document, Twip, Pixel };

enum class DECLSPEC_DENUM TdxLayoutGraphicsUnit : unsigned char { Pixel = 2, Point, Document = 5 };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxDocumentModelDpi : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	static float __fastcall DpiX();
	static float __fastcall DpiY();
	static float __fastcall Dpi();
public:
	/* TObject.Create */ inline __fastcall TdxDocumentModelDpi() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxDocumentModelDpi() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxDpiSupport : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	float FScreenDpiX;
	float FScreenDpiY;
	float FScreenDpi;
	
public:
	__fastcall TdxDpiSupport(float AScreenDpiX, float AScreenDpiY, float AScreenDpi)/* overload */;
	__fastcall TdxDpiSupport(float AScreenDpiX, float AScreenDpiY)/* overload */;
	__fastcall TdxDpiSupport()/* overload */;
	__property float ScreenDpiX = {read=FScreenDpiX};
	__property float ScreenDpiY = {read=FScreenDpiY};
	__property float ScreenDpi = {read=FScreenDpi};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxDpiSupport() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGraphicsDpi : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	#define TdxGraphicsDpi_Display  (7.500000E+01)
	
	#define TdxGraphicsDpi_Inch  (1.000000E+00)
	
	#define TdxGraphicsDpi_Document  (3.000000E+02)
	
	#define TdxGraphicsDpi_Millimeter  (2.540000E+01)
	
	#define TdxGraphicsDpi_Point  (7.200000E+01)
	
	#define TdxGraphicsDpi_HundredthsOfAnInch  (1.000000E+02)
	
	#define TdxGraphicsDpi_TenthsOfAMillimeter  (2.540000E+02)
	
	#define TdxGraphicsDpi_Twips  (1.440000E+03)
	
	#define TdxGraphicsDpi_EMU  (9.144000E+05)
	
	#define TdxGraphicsDpi_DeviceIndependentPixel  (9.600000E+01)
	
	
private:
	static float FPixel;
	// __classmethod void __fastcall Initialize@();
	
public:
	static float __fastcall GetGraphicsDpi(Dxgdiplusclasses::TdxGPCanvas* AGraphics);
	static float __fastcall UnitToDpi(Dxcoregraphics::TdxGraphicUnit AUnit);
	static Dxcoregraphics::TdxGraphicUnit __fastcall DpiToUnit(float ADpi);
	/* static */ __property float Pixel = {read=FPixel};
	
private:
	// __classmethod void __fastcall Destroy@();
public:
	/* TObject.Create */ inline __fastcall TdxGraphicsDpi() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxGraphicsDpi() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxDocumentLayoutUnitConverter : public TdxDpiSupport
{
	typedef TdxDpiSupport inherited;
	
protected:
	virtual float __fastcall GetDpi() = 0 ;
	virtual float __fastcall GetFontSizeScale() = 0 ;
	virtual float __fastcall GetFontSizeScaleForPrinting();
	virtual TdxLayoutGraphicsUnit __fastcall GetFontUnit() = 0 ;
	virtual float __fastcall GetGraphicsPageScale() = 0 ;
	virtual TdxLayoutGraphicsUnit __fastcall GetGraphicsPageUnit() = 0 ;
	
public:
	virtual bool __fastcall Equals(System::TObject* Obj);
	__classmethod TdxDocumentLayoutUnitConverter* __fastcall CreateConverter(const TdxDocumentLayoutUnit AUnit, const float ADpi);
	virtual float __fastcall DocumentsToFontUnitsF(const float AValue) = 0 ;
	virtual int __fastcall DocumentsToLayoutUnits(const int AValue) = 0 /* overload */;
	virtual Cxgeometry::TdxRectF __fastcall DocumentsToLayoutUnits(const Cxgeometry::TdxRectF &AValue) = 0 /* overload */;
	virtual System::Types::TRect __fastcall DocumentsToLayoutUnits(const System::Types::TRect &AValue) = 0 /* overload */;
	virtual float __fastcall InchesToFontUnitsF(const float AValue) = 0 ;
	virtual Cxgeometry::TdxRectF __fastcall LayoutUnitsToDocuments(const Cxgeometry::TdxRectF &AValue) = 0 /* overload */;
	virtual System::Types::TRect __fastcall LayoutUnitsToDocuments(const System::Types::TRect &AValue) = 0 /* overload */;
	virtual int __fastcall LayoutUnitsToHundredthsOfInch(const int AValue) = 0 /* overload */;
	virtual System::Types::TSize __fastcall LayoutUnitsToHundredthsOfInch(const System::Types::TSize &AValue) = 0 /* overload */;
	virtual int __fastcall LayoutUnitsToPixels(const int AValue, const float ADpi) = 0 /* overload */;
	int __fastcall LayoutUnitsToPixels(const int AValue)/* overload */;
	System::Types::TSize __fastcall LayoutUnitsToPixels(const System::Types::TSize &AValue)/* overload */;
	virtual System::Types::TSize __fastcall LayoutUnitsToPixels(const System::Types::TSize &AValue, const float ADpiX, const float ADpiY) = 0 /* overload */;
	virtual System::Types::TPoint __fastcall LayoutUnitsToPixels(const System::Types::TPoint &AValue, const float ADpiX, const float ADpiY) = 0 /* overload */;
	virtual System::Types::TRect __fastcall LayoutUnitsToPixels(const System::Types::TRect &AValue, const float ADpiX, const float ADpiY) = 0 /* overload */;
	virtual float __fastcall LayoutUnitsToPixelsF(const float AValue, const float ADpi) = 0 ;
	virtual float __fastcall LayoutUnitsToPointsF(const float AValue) = 0 ;
	virtual __int64 __fastcall LayoutUnitsToTwips(const __int64 AValue) = 0 /* overload */;
	virtual int __fastcall LayoutUnitsToTwips(const int AValue) = 0 /* overload */;
	virtual float __fastcall MillimetersToFontUnitsF(const float AValue) = 0 ;
	int __fastcall PixelsToLayoutUnits(const int AValue)/* overload */;
	virtual int __fastcall PixelsToLayoutUnits(const int AValue, const float ADpi) = 0 /* overload */;
	virtual System::Types::TPoint __fastcall PixelsToLayoutUnits(const System::Types::TPoint &AValue, const float ADpiX, const float ADpiY)/* overload */;
	virtual System::Types::TSize __fastcall PixelsToLayoutUnits(const System::Types::TSize &AValue, const float ADpiX, const float ADpiY) = 0 /* overload */;
	System::Types::TRect __fastcall PixelsToLayoutUnits(const System::Types::TRect &AValue)/* overload */;
	virtual System::Types::TRect __fastcall PixelsToLayoutUnits(const System::Types::TRect &AValue, const float ADpiX, const float ADpiY) = 0 /* overload */;
	virtual float __fastcall PixelsToLayoutUnitsF(const float AValue, const float ADpi) = 0 ;
	virtual int __fastcall PointsToFontUnits(const int AValue) = 0 ;
	virtual float __fastcall PointsToFontUnitsF(const float AValue) = 0 ;
	virtual int __fastcall PointsToLayoutUnits(const int AValue) = 0 ;
	virtual float __fastcall PointsToLayoutUnitsF(const float AValue) = 0 ;
	virtual int __fastcall SnapToPixels(const int AValue, const float ADpi) = 0 ;
	virtual __int64 __fastcall TwipsToLayoutUnits(const __int64 AValue) = 0 /* overload */;
	virtual int __fastcall TwipsToLayoutUnits(const int AValue) = 0 /* overload */;
	__property float Dpi = {read=GetDpi};
	__property float FontSizeScale = {read=GetFontSizeScale};
	__property float FontSizeScaleForPrinting = {read=GetFontSizeScaleForPrinting};
	__property TdxLayoutGraphicsUnit FontUnit = {read=GetFontUnit, nodefault};
	__property float GraphicsPageScale = {read=GetGraphicsPageScale};
	__property TdxLayoutGraphicsUnit GraphicsPageUnit = {read=GetGraphicsPageUnit, nodefault};
public:
	/* TdxDpiSupport.Create */ inline __fastcall TdxDocumentLayoutUnitConverter(float AScreenDpiX, float AScreenDpiY, float AScreenDpi)/* overload */ : TdxDpiSupport(AScreenDpiX, AScreenDpiY, AScreenDpi) { }
	/* TdxDpiSupport.Create */ inline __fastcall TdxDocumentLayoutUnitConverter(float AScreenDpiX, float AScreenDpiY)/* overload */ : TdxDpiSupport(AScreenDpiX, AScreenDpiY) { }
	/* TdxDpiSupport.Create */ inline __fastcall TdxDocumentLayoutUnitConverter()/* overload */ : TdxDpiSupport() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxDocumentLayoutUnitConverter() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxDocumentLayoutUnitPixelsConverter : /*[[sealed]]*/ public TdxDocumentLayoutUnitConverter
{
	typedef TdxDocumentLayoutUnitConverter inherited;
	
private:
	float FDpi;
	
protected:
	virtual float __fastcall GetDpi();
	virtual float __fastcall GetFontSizeScale();
	virtual TdxLayoutGraphicsUnit __fastcall GetFontUnit();
	virtual float __fastcall GetGraphicsPageScale();
	virtual TdxLayoutGraphicsUnit __fastcall GetGraphicsPageUnit();
	
public:
	__fastcall TdxDocumentLayoutUnitPixelsConverter(float ADpi);
	virtual float __fastcall DocumentsToFontUnitsF(const float AValue);
	virtual int __fastcall DocumentsToLayoutUnits(const int AValue)/* overload */;
	virtual Cxgeometry::TdxRectF __fastcall DocumentsToLayoutUnits(const Cxgeometry::TdxRectF &AValue)/* overload */;
	virtual System::Types::TRect __fastcall DocumentsToLayoutUnits(const System::Types::TRect &AValue)/* overload */;
	virtual float __fastcall InchesToFontUnitsF(const float AValue);
	virtual Cxgeometry::TdxRectF __fastcall LayoutUnitsToDocuments(const Cxgeometry::TdxRectF &AValue)/* overload */;
	virtual System::Types::TRect __fastcall LayoutUnitsToDocuments(const System::Types::TRect &AValue)/* overload */;
	virtual int __fastcall LayoutUnitsToHundredthsOfInch(const int AValue)/* overload */;
	virtual System::Types::TSize __fastcall LayoutUnitsToHundredthsOfInch(const System::Types::TSize &AValue)/* overload */;
	virtual int __fastcall LayoutUnitsToPixels(const int AValue, const float ADpi)/* overload */;
	virtual System::Types::TSize __fastcall LayoutUnitsToPixels(const System::Types::TSize &AValue, const float ADpiX, const float ADpiY)/* overload */;
	virtual System::Types::TPoint __fastcall LayoutUnitsToPixels(const System::Types::TPoint &AValue, const float ADpiX, const float ADpiY)/* overload */;
	virtual System::Types::TRect __fastcall LayoutUnitsToPixels(const System::Types::TRect &AValue, const float ADpiX, const float ADpiY)/* overload */;
	virtual float __fastcall LayoutUnitsToPixelsF(const float AValue, const float ADpi);
	virtual float __fastcall LayoutUnitsToPointsF(const float AValue);
	virtual __int64 __fastcall LayoutUnitsToTwips(const __int64 AValue)/* overload */;
	virtual int __fastcall LayoutUnitsToTwips(const int AValue)/* overload */;
	virtual float __fastcall MillimetersToFontUnitsF(const float AValue);
	virtual int __fastcall PixelsToLayoutUnits(const int AValue, const float ADpi)/* overload */;
	virtual System::Types::TSize __fastcall PixelsToLayoutUnits(const System::Types::TSize &AValue, const float ADpiX, const float ADpiY)/* overload */;
	virtual System::Types::TRect __fastcall PixelsToLayoutUnits(const System::Types::TRect &AValue, const float ADpiX, const float ADpiY)/* overload */;
	virtual float __fastcall PixelsToLayoutUnitsF(const float AValue, const float ADpi);
	virtual int __fastcall PointsToFontUnits(const int AValue);
	virtual float __fastcall PointsToFontUnitsF(const float AValue);
	virtual int __fastcall PointsToLayoutUnits(const int AValue);
	virtual float __fastcall PointsToLayoutUnitsF(const float AValue);
	virtual int __fastcall SnapToPixels(const int AValue, const float ADpi);
	virtual __int64 __fastcall TwipsToLayoutUnits(const __int64 AValue)/* overload */;
	virtual int __fastcall TwipsToLayoutUnits(const int AValue)/* overload */;
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxDocumentLayoutUnitPixelsConverter() { }
	
	/* Hoisted overloads: */
	
public:
	inline int __fastcall  LayoutUnitsToPixels(const int AValue){ return TdxDocumentLayoutUnitConverter::LayoutUnitsToPixels(AValue); }
	inline System::Types::TSize __fastcall  LayoutUnitsToPixels(const System::Types::TSize &AValue){ return TdxDocumentLayoutUnitConverter::LayoutUnitsToPixels(AValue); }
	inline int __fastcall  PixelsToLayoutUnits(const int AValue){ return TdxDocumentLayoutUnitConverter::PixelsToLayoutUnits(AValue); }
	inline System::Types::TPoint __fastcall  PixelsToLayoutUnits(const System::Types::TPoint &AValue, const float ADpiX, const float ADpiY){ return TdxDocumentLayoutUnitConverter::PixelsToLayoutUnits(AValue, ADpiX, ADpiY); }
	inline System::Types::TRect __fastcall  PixelsToLayoutUnits(const System::Types::TRect &AValue){ return TdxDocumentLayoutUnitConverter::PixelsToLayoutUnits(AValue); }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxDocumentLayoutUnitTwipsConverter : /*[[sealed]]*/ public TdxDocumentLayoutUnitConverter
{
	typedef TdxDocumentLayoutUnitConverter inherited;
	
protected:
	virtual float __fastcall GetDpi();
	virtual float __fastcall GetFontSizeScale();
	virtual float __fastcall GetFontSizeScaleForPrinting();
	virtual TdxLayoutGraphicsUnit __fastcall GetFontUnit();
	virtual float __fastcall GetGraphicsPageScale();
	virtual TdxLayoutGraphicsUnit __fastcall GetGraphicsPageUnit();
	
public:
	virtual float __fastcall DocumentsToFontUnitsF(const float AValue);
	virtual int __fastcall DocumentsToLayoutUnits(const int AValue)/* overload */;
	virtual Cxgeometry::TdxRectF __fastcall DocumentsToLayoutUnits(const Cxgeometry::TdxRectF &AValue)/* overload */;
	virtual System::Types::TRect __fastcall DocumentsToLayoutUnits(const System::Types::TRect &AValue)/* overload */;
	virtual float __fastcall InchesToFontUnitsF(const float AValue);
	virtual Cxgeometry::TdxRectF __fastcall LayoutUnitsToDocuments(const Cxgeometry::TdxRectF &AValue)/* overload */;
	virtual System::Types::TRect __fastcall LayoutUnitsToDocuments(const System::Types::TRect &AValue)/* overload */;
	virtual int __fastcall LayoutUnitsToHundredthsOfInch(const int AValue)/* overload */;
	virtual System::Types::TSize __fastcall LayoutUnitsToHundredthsOfInch(const System::Types::TSize &AValue)/* overload */;
	virtual int __fastcall LayoutUnitsToPixels(const int AValue, const float ADpi)/* overload */;
	virtual System::Types::TSize __fastcall LayoutUnitsToPixels(const System::Types::TSize &AValue, const float ADpiX, const float ADpiY)/* overload */;
	virtual System::Types::TPoint __fastcall LayoutUnitsToPixels(const System::Types::TPoint &AValue, const float ADpiX, const float ADpiY)/* overload */;
	virtual System::Types::TRect __fastcall LayoutUnitsToPixels(const System::Types::TRect &AValue, const float ADpiX, const float ADpiY)/* overload */;
	virtual float __fastcall LayoutUnitsToPixelsF(const float AValue, const float ADpi);
	virtual float __fastcall LayoutUnitsToPointsF(const float AValue);
	virtual __int64 __fastcall LayoutUnitsToTwips(const __int64 AValue)/* overload */;
	virtual int __fastcall LayoutUnitsToTwips(const int AValue)/* overload */;
	virtual float __fastcall MillimetersToFontUnitsF(const float AValue);
	virtual int __fastcall PixelsToLayoutUnits(const int AValue, const float ADpi)/* overload */;
	virtual System::Types::TSize __fastcall PixelsToLayoutUnits(const System::Types::TSize &AValue, const float ADpiX, const float ADpiY)/* overload */;
	virtual System::Types::TRect __fastcall PixelsToLayoutUnits(const System::Types::TRect &AValue, const float ADpiX, const float ADpiY)/* overload */;
	virtual float __fastcall PixelsToLayoutUnitsF(const float AValue, const float ADpi);
	virtual int __fastcall PointsToFontUnits(const int AValue);
	virtual float __fastcall PointsToFontUnitsF(const float AValue);
	virtual int __fastcall PointsToLayoutUnits(const int AValue);
	virtual float __fastcall PointsToLayoutUnitsF(const float AValue);
	virtual int __fastcall SnapToPixels(const int AValue, const float ADpi);
	virtual __int64 __fastcall TwipsToLayoutUnits(const __int64 AValue)/* overload */;
	virtual int __fastcall TwipsToLayoutUnits(const int AValue)/* overload */;
public:
	/* TdxDpiSupport.Create */ inline __fastcall TdxDocumentLayoutUnitTwipsConverter(float AScreenDpiX, float AScreenDpiY, float AScreenDpi)/* overload */ : TdxDocumentLayoutUnitConverter(AScreenDpiX, AScreenDpiY, AScreenDpi) { }
	/* TdxDpiSupport.Create */ inline __fastcall TdxDocumentLayoutUnitTwipsConverter(float AScreenDpiX, float AScreenDpiY)/* overload */ : TdxDocumentLayoutUnitConverter(AScreenDpiX, AScreenDpiY) { }
	/* TdxDpiSupport.Create */ inline __fastcall TdxDocumentLayoutUnitTwipsConverter()/* overload */ : TdxDocumentLayoutUnitConverter() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxDocumentLayoutUnitTwipsConverter() { }
	
	/* Hoisted overloads: */
	
public:
	inline int __fastcall  LayoutUnitsToPixels(const int AValue){ return TdxDocumentLayoutUnitConverter::LayoutUnitsToPixels(AValue); }
	inline System::Types::TSize __fastcall  LayoutUnitsToPixels(const System::Types::TSize &AValue){ return TdxDocumentLayoutUnitConverter::LayoutUnitsToPixels(AValue); }
	inline int __fastcall  PixelsToLayoutUnits(const int AValue){ return TdxDocumentLayoutUnitConverter::PixelsToLayoutUnits(AValue); }
	inline System::Types::TPoint __fastcall  PixelsToLayoutUnits(const System::Types::TPoint &AValue, const float ADpiX, const float ADpiY){ return TdxDocumentLayoutUnitConverter::PixelsToLayoutUnits(AValue, ADpiX, ADpiY); }
	inline System::Types::TRect __fastcall  PixelsToLayoutUnits(const System::Types::TRect &AValue){ return TdxDocumentLayoutUnitConverter::PixelsToLayoutUnits(AValue); }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxDocumentLayoutUnitDocumentConverter : /*[[sealed]]*/ public TdxDocumentLayoutUnitConverter
{
	typedef TdxDocumentLayoutUnitConverter inherited;
	
public:
	static const System::Word DefaultDpi = System::Word(0x12c);
	
	
protected:
	virtual float __fastcall GetDpi();
	virtual float __fastcall GetFontSizeScale();
	virtual TdxLayoutGraphicsUnit __fastcall GetFontUnit();
	virtual float __fastcall GetGraphicsPageScale();
	virtual TdxLayoutGraphicsUnit __fastcall GetGraphicsPageUnit();
	
public:
	virtual float __fastcall DocumentsToFontUnitsF(const float AValue);
	virtual int __fastcall DocumentsToLayoutUnits(const int AValue)/* overload */;
	virtual Cxgeometry::TdxRectF __fastcall DocumentsToLayoutUnits(const Cxgeometry::TdxRectF &AValue)/* overload */;
	virtual System::Types::TRect __fastcall DocumentsToLayoutUnits(const System::Types::TRect &AValue)/* overload */;
	virtual float __fastcall InchesToFontUnitsF(const float AValue);
	virtual Cxgeometry::TdxRectF __fastcall LayoutUnitsToDocuments(const Cxgeometry::TdxRectF &AValue)/* overload */;
	virtual System::Types::TRect __fastcall LayoutUnitsToDocuments(const System::Types::TRect &AValue)/* overload */;
	virtual int __fastcall LayoutUnitsToHundredthsOfInch(const int AValue)/* overload */;
	virtual System::Types::TSize __fastcall LayoutUnitsToHundredthsOfInch(const System::Types::TSize &AValue)/* overload */;
	virtual int __fastcall LayoutUnitsToPixels(const int AValue, const float ADpi)/* overload */;
	virtual System::Types::TSize __fastcall LayoutUnitsToPixels(const System::Types::TSize &AValue, const float ADpiX, const float ADpiY)/* overload */;
	virtual System::Types::TPoint __fastcall LayoutUnitsToPixels(const System::Types::TPoint &AValue, const float ADpiX, const float ADpiY)/* overload */;
	virtual System::Types::TRect __fastcall LayoutUnitsToPixels(const System::Types::TRect &AValue, const float ADpiX, const float ADpiY)/* overload */;
	virtual float __fastcall LayoutUnitsToPixelsF(const float AValue, const float ADpi);
	virtual float __fastcall LayoutUnitsToPointsF(const float AValue);
	virtual __int64 __fastcall LayoutUnitsToTwips(const __int64 AValue)/* overload */;
	virtual int __fastcall LayoutUnitsToTwips(const int AValue)/* overload */;
	virtual float __fastcall MillimetersToFontUnitsF(const float AValue);
	virtual int __fastcall PixelsToLayoutUnits(const int AValue, const float ADpi)/* overload */;
	virtual System::Types::TSize __fastcall PixelsToLayoutUnits(const System::Types::TSize &AValue, const float ADpiX, const float ADpiY)/* overload */;
	virtual System::Types::TRect __fastcall PixelsToLayoutUnits(const System::Types::TRect &AValue, const float ADpiX, const float ADpiY)/* overload */;
	virtual float __fastcall PixelsToLayoutUnitsF(const float AValue, const float ADpi);
	virtual int __fastcall PointsToFontUnits(const int AValue);
	virtual float __fastcall PointsToFontUnitsF(const float AValue);
	virtual int __fastcall PointsToLayoutUnits(const int AValue);
	virtual float __fastcall PointsToLayoutUnitsF(const float AValue);
	virtual int __fastcall SnapToPixels(const int AValue, const float ADpi);
	virtual __int64 __fastcall TwipsToLayoutUnits(const __int64 AValue)/* overload */;
	virtual int __fastcall TwipsToLayoutUnits(const int AValue)/* overload */;
public:
	/* TdxDpiSupport.Create */ inline __fastcall TdxDocumentLayoutUnitDocumentConverter(float AScreenDpiX, float AScreenDpiY, float AScreenDpi)/* overload */ : TdxDocumentLayoutUnitConverter(AScreenDpiX, AScreenDpiY, AScreenDpi) { }
	/* TdxDpiSupport.Create */ inline __fastcall TdxDocumentLayoutUnitDocumentConverter(float AScreenDpiX, float AScreenDpiY)/* overload */ : TdxDocumentLayoutUnitConverter(AScreenDpiX, AScreenDpiY) { }
	/* TdxDpiSupport.Create */ inline __fastcall TdxDocumentLayoutUnitDocumentConverter()/* overload */ : TdxDocumentLayoutUnitConverter() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxDocumentLayoutUnitDocumentConverter() { }
	
	/* Hoisted overloads: */
	
public:
	inline int __fastcall  LayoutUnitsToPixels(const int AValue){ return TdxDocumentLayoutUnitConverter::LayoutUnitsToPixels(AValue); }
	inline System::Types::TSize __fastcall  LayoutUnitsToPixels(const System::Types::TSize &AValue){ return TdxDocumentLayoutUnitConverter::LayoutUnitsToPixels(AValue); }
	inline int __fastcall  PixelsToLayoutUnits(const int AValue){ return TdxDocumentLayoutUnitConverter::PixelsToLayoutUnits(AValue); }
	inline System::Types::TPoint __fastcall  PixelsToLayoutUnits(const System::Types::TPoint &AValue, const float ADpiX, const float ADpiY){ return TdxDocumentLayoutUnitConverter::PixelsToLayoutUnits(AValue, ADpiX, ADpiY); }
	inline System::Types::TRect __fastcall  PixelsToLayoutUnits(const System::Types::TRect &AValue){ return TdxDocumentLayoutUnitConverter::PixelsToLayoutUnits(AValue); }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxdocumentlayoutunitconverter */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXDOCUMENTLAYOUTUNITCONVERTER)
using namespace Dxdocumentlayoutunitconverter;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxdocumentlayoutunitconverterHPP
