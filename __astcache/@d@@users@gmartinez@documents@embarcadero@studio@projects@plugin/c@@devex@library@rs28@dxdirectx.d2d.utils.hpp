// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxDirectX.D2D.Utils.pas' rev: 35.00 (Windows)

#ifndef Dxdirectx_D2d_UtilsHPP
#define Dxdirectx_D2d_UtilsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.UITypes.hpp>
#include <Winapi.Windows.hpp>
#include <Winapi.ActiveX.hpp>
#include <System.Types.hpp>
#include <Winapi.D2D1.hpp>
#include <Winapi.DxgiFormat.hpp>
#include <Vcl.Graphics.hpp>
#include <dxCore.hpp>
#include <dxCoreGraphics.hpp>
#include <dxDirectX.D2D.Types.hpp>
#include <cxGeometry.hpp>
#include <dxGDIPlusClasses.hpp>
#include <System.SysUtils.hpp>

//-- user supplied -----------------------------------------------------------

namespace Dxdirectx
{
namespace D2d
{
namespace Utils
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS EdxDirectCustomException;
class DELPHICLASS EdxDirectXInvalidStateException;
class DELPHICLASS EdxDirectXError;
struct TdxD2DRectFHelper /* Helper for record 'D2D_RECT_F' */;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION EdxDirectCustomException : public Dxcore::EdxException
{
	typedef Dxcore::EdxException inherited;
	
public:
	/* Exception.Create */ inline __fastcall EdxDirectCustomException(const System::UnicodeString Msg) : Dxcore::EdxException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EdxDirectCustomException(const System::UnicodeString Msg, const System::TVarRec *Args, const int Args_High) : Dxcore::EdxException(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EdxDirectCustomException(NativeUInt Ident)/* overload */ : Dxcore::EdxException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EdxDirectCustomException(System::PResStringRec ResStringRec)/* overload */ : Dxcore::EdxException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxDirectCustomException(NativeUInt Ident, const System::TVarRec *Args, const int Args_High)/* overload */ : Dxcore::EdxException(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxDirectCustomException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const int Args_High)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EdxDirectCustomException(const System::UnicodeString Msg, int AHelpContext) : Dxcore::EdxException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EdxDirectCustomException(const System::UnicodeString Msg, const System::TVarRec *Args, const int Args_High, int AHelpContext) : Dxcore::EdxException(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxDirectCustomException(NativeUInt Ident, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxDirectCustomException(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxDirectCustomException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const int Args_High, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxDirectCustomException(NativeUInt Ident, const System::TVarRec *Args, const int Args_High, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EdxDirectCustomException() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION EdxDirectXInvalidStateException : public EdxDirectCustomException
{
	typedef EdxDirectCustomException inherited;
	
public:
	/* Exception.Create */ inline __fastcall EdxDirectXInvalidStateException(const System::UnicodeString Msg) : EdxDirectCustomException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EdxDirectXInvalidStateException(const System::UnicodeString Msg, const System::TVarRec *Args, const int Args_High) : EdxDirectCustomException(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EdxDirectXInvalidStateException(NativeUInt Ident)/* overload */ : EdxDirectCustomException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EdxDirectXInvalidStateException(System::PResStringRec ResStringRec)/* overload */ : EdxDirectCustomException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxDirectXInvalidStateException(NativeUInt Ident, const System::TVarRec *Args, const int Args_High)/* overload */ : EdxDirectCustomException(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxDirectXInvalidStateException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const int Args_High)/* overload */ : EdxDirectCustomException(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EdxDirectXInvalidStateException(const System::UnicodeString Msg, int AHelpContext) : EdxDirectCustomException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EdxDirectXInvalidStateException(const System::UnicodeString Msg, const System::TVarRec *Args, const int Args_High, int AHelpContext) : EdxDirectCustomException(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxDirectXInvalidStateException(NativeUInt Ident, int AHelpContext)/* overload */ : EdxDirectCustomException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxDirectXInvalidStateException(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : EdxDirectCustomException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxDirectXInvalidStateException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const int Args_High, int AHelpContext)/* overload */ : EdxDirectCustomException(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxDirectXInvalidStateException(NativeUInt Ident, const System::TVarRec *Args, const int Args_High, int AHelpContext)/* overload */ : EdxDirectCustomException(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EdxDirectXInvalidStateException() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION EdxDirectXError : public EdxDirectCustomException
{
	typedef EdxDirectCustomException inherited;
	
private:
	HRESULT FErrorCode;
	
public:
	__fastcall EdxDirectXError(HRESULT AErrorCode);
	__property HRESULT ErrorCode = {read=FErrorCode, nodefault};
public:
	/* Exception.CreateFmt */ inline __fastcall EdxDirectXError(const System::UnicodeString Msg, const System::TVarRec *Args, const int Args_High) : EdxDirectCustomException(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EdxDirectXError(NativeUInt Ident)/* overload */ : EdxDirectCustomException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EdxDirectXError(System::PResStringRec ResStringRec)/* overload */ : EdxDirectCustomException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxDirectXError(NativeUInt Ident, const System::TVarRec *Args, const int Args_High)/* overload */ : EdxDirectCustomException(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxDirectXError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const int Args_High)/* overload */ : EdxDirectCustomException(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EdxDirectXError(const System::UnicodeString Msg, int AHelpContext) : EdxDirectCustomException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EdxDirectXError(const System::UnicodeString Msg, const System::TVarRec *Args, const int Args_High, int AHelpContext) : EdxDirectCustomException(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxDirectXError(NativeUInt Ident, int AHelpContext)/* overload */ : EdxDirectCustomException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxDirectXError(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : EdxDirectCustomException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxDirectXError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const int Args_High, int AHelpContext)/* overload */ : EdxDirectCustomException(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxDirectXError(NativeUInt Ident, const System::TVarRec *Args, const int Args_High, int AHelpContext)/* overload */ : EdxDirectCustomException(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EdxDirectXError() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE D3DCOLORVALUE dxNullD2DColor;
extern DELPHI_PACKAGE void __fastcall CheckD2D1Result(HRESULT AValue);
extern DELPHI_PACKAGE Dxdirectx::D2d::Types::_di_ID2D1Bitmap1 __fastcall D2D1Bitmap(const Dxdirectx::D2d::Types::_di_ID2D1DeviceContext AContext, Dxcoregraphics::TdxCustomFastDIB* ABitmap, Vcl::Graphics::TAlphaFormat AAlphaFormat)/* overload */;
extern DELPHI_PACKAGE Dxdirectx::D2d::Types::_di_ID2D1Bitmap1 __fastcall D2D1Bitmap(const Dxdirectx::D2d::Types::_di_ID2D1DeviceContext AContext, System::PByte ABits, int AWidth, int AHeight, int AStride, Vcl::Graphics::TAlphaFormat AAlphaFormat)/* overload */;
extern DELPHI_PACKAGE Dxdirectx::D2d::Types::_di_ID2D1Bitmap1 __fastcall D2D1Bitmap(const Dxdirectx::D2d::Types::_di_ID2D1DeviceContext AContext, Vcl::Graphics::TBitmap* ABitmap, Vcl::Graphics::TAlphaFormat AAlphaFormat)/* overload */;
extern DELPHI_PACKAGE D2D1_ARC_SEGMENT __fastcall D2D1CalculateArcSegment(const D2D_RECT_F &R, const float AStartAngle, const float ASweepAngle, /* out */ D2D_POINT_2F &ACenter, /* out */ D2D_POINT_2F &AStartPoint)/* overload */;
extern DELPHI_PACKAGE D2D1_ARC_SEGMENT __fastcall D2D1CalculateArcSegment(const D2D_RECT_F &R, const D2D_POINT_2F &AArcStart, const D2D_POINT_2F &AArcEnd, /* out */ D2D_POINT_2F &ACenter, /* out */ D2D_POINT_2F &AStartPoint)/* overload */;
extern DELPHI_PACKAGE D3DCOLORVALUE __fastcall D2D1ColorF(const Dxcoregraphics::TdxAlphaColor AColor)/* overload */;
extern DELPHI_PACKAGE D2D_RECT_F __fastcall D2D1Rect(const Cxgeometry::TdxRectF &R)/* overload */;
extern DELPHI_PACKAGE D2D_RECT_F __fastcall D2D1Rect(const System::Types::TRect &R)/* overload */;
extern DELPHI_PACKAGE bool __fastcall D2D1RectIsEqual(const D2D_RECT_F &R1, const D2D_RECT_F &R2);
extern DELPHI_PACKAGE D2D_RECT_F __fastcall D2D1Rect(const float L, const float T, const float R, const float B)/* overload */;
extern DELPHI_PACKAGE D2D1_ELLIPSE __fastcall D2D1Ellipse(const D2D_RECT_F &R)/* overload */;
extern DELPHI_PACKAGE Dxdirectx::D2d::Types::TD2D1GradientStops __fastcall D2D1GradientStops(Dxgdiplusclasses::TdxGPBrushGradientPoints* const AStops, bool AExtendNearestColorsToEdges = false);
extern DELPHI_PACKAGE D2D_POINT_2F __fastcall D2D1Point(const Cxgeometry::TdxPointF &P)/* overload */;
extern DELPHI_PACKAGE D2D_POINT_2F __fastcall D2D1Point(const System::Types::TPoint &P)/* overload */;
extern DELPHI_PACKAGE D2D_POINT_2F __fastcall D2D1Point(const float X, const float Y)/* overload */;
extern DELPHI_PACKAGE D2D_SIZE_U __fastcall D2D1SizeU(const int W, const int H)/* overload */;
extern DELPHI_PACKAGE bool __fastcall D2D1SizeIsEqual(const D2D_RECT_F &R, const D2D_SIZE_F &S)/* overload */;
extern DELPHI_PACKAGE bool __fastcall D2D1SizeIsEqual(const D2D_RECT_F &R1, const D2D_RECT_F &R2)/* overload */;
extern DELPHI_PACKAGE bool __fastcall D2D1SizeIsEqual(const D2D_SIZE_F &S1, const D2D_SIZE_F &S2)/* overload */;
extern DELPHI_PACKAGE D2D_MATRIX_3X2_F __fastcall D2D1Matrix3x2(const tagXFORM &XForm)/* overload */;
extern DELPHI_PACKAGE D2D_MATRIX_3X2_F __fastcall D2D1Matrix3x2(const float M11, const float M12, const float M21, const float M22, const float DX, const float DY)/* overload */;
}	/* namespace Utils */
}	/* namespace D2d */
}	/* namespace Dxdirectx */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXDIRECTX_D2D_UTILS)
using namespace Dxdirectx::D2d::Utils;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXDIRECTX_D2D)
using namespace Dxdirectx::D2d;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXDIRECTX)
using namespace Dxdirectx;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Dxdirectx_D2d_UtilsHPP
