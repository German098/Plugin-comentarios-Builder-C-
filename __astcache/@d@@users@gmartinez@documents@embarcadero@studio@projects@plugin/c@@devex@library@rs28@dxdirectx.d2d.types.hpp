// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxDirectX.D2D.Types.pas' rev: 35.00 (Windows)

#ifndef Dxdirectx_D2d_TypesHPP
#define Dxdirectx_D2d_TypesHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.ActiveX.hpp>
#include <Winapi.Windows.hpp>
#include <System.SysUtils.hpp>
#include <Winapi.Wincodec.hpp>
#include <Winapi.DxgiFormat.hpp>
#include <Winapi.D2D1.hpp>
#include <dxCore.hpp>
#include <System.Types.hpp>

//-- user supplied -----------------------------------------------------------

namespace Dxdirectx
{
namespace D2d
{
namespace Types
{
//-- forward type declarations -----------------------------------------------
struct TDXGIOutputDesc;
struct TDXGIRational;
struct TDXGIModeDesc;
struct TDXGIGammaControlCapabilities;
struct TDXGIRGB;
struct TDXGIGammaControl;
struct TDXGISampleDesc;
struct TDXGISurfaceDesc;
struct TDXGIMappedRect;
struct TDXGIFrameStatistics;
struct TDXGIAdapterDesc;
struct TDXGISharedResource;
struct TDXGIModeDesc1;
struct TDXGISwapChainDesc1;
struct TDXGISwapChainFullScreenDesc;
struct TDXGIPresentParameters;
struct TDXGISwapChainDesc;
struct TDXGIAdapterDesc1;
__interface DELPHIINTERFACE IDXGIObject;
typedef System::DelphiInterface<IDXGIObject> _di_IDXGIObject;
__interface DELPHIINTERFACE IDXGIDeviceSubObject;
typedef System::DelphiInterface<IDXGIDeviceSubObject> _di_IDXGIDeviceSubObject;
__interface DELPHIINTERFACE IDXGISurface;
typedef System::DelphiInterface<IDXGISurface> _di_IDXGISurface;
__interface DELPHIINTERFACE IDXGISurface1;
typedef System::DelphiInterface<IDXGISurface1> _di_IDXGISurface1;
__interface DELPHIINTERFACE IDXGIOutput;
typedef System::DelphiInterface<IDXGIOutput> _di_IDXGIOutput;
__interface DELPHIINTERFACE IDXGIAdapter;
typedef System::DelphiInterface<IDXGIAdapter> _di_IDXGIAdapter;
__interface DELPHIINTERFACE IDXGIDevice;
typedef System::DelphiInterface<IDXGIDevice> _di_IDXGIDevice;
__interface DELPHIINTERFACE IDXGIDevice1;
typedef System::DelphiInterface<IDXGIDevice1> _di_IDXGIDevice1;
__interface DELPHIINTERFACE IDXGISwapChain;
typedef System::DelphiInterface<IDXGISwapChain> _di_IDXGISwapChain;
__interface DELPHIINTERFACE IDXGISwapChain1;
typedef System::DelphiInterface<IDXGISwapChain1> _di_IDXGISwapChain1;
__interface DELPHIINTERFACE IDXGIFactory;
typedef System::DelphiInterface<IDXGIFactory> _di_IDXGIFactory;
__interface DELPHIINTERFACE IDXGIAdapter1;
typedef System::DelphiInterface<IDXGIAdapter1> _di_IDXGIAdapter1;
__interface DELPHIINTERFACE IDXGIFactory1;
typedef System::DelphiInterface<IDXGIFactory1> _di_IDXGIFactory1;
__interface DELPHIINTERFACE IDXGIFactory2;
typedef System::DelphiInterface<IDXGIFactory2> _di_IDXGIFactory2;
struct TD2D1MappedRect;
struct TD2D1ImageBrushProperties;
struct TD2D1BitmapBrushProperties1;
struct TD2D1RenderingControls;
struct TD2D1LayerParameters1;
struct TD2D1StrokeStyleProperties1;
struct TD2D1PointDescription;
struct TD2D1DrawingStateDescription1;
struct TD2D1PropertyBinding;
struct TD2D1BitmapProperties1;
__interface DELPHIINTERFACE ID2D1ColorContext;
typedef System::DelphiInterface<ID2D1ColorContext> _di_ID2D1ColorContext;
__interface DELPHIINTERFACE ID2D1Image;
typedef System::DelphiInterface<ID2D1Image> _di_ID2D1Image;
__interface DELPHIINTERFACE ID2D1Bitmap;
typedef System::DelphiInterface<ID2D1Bitmap> _di_ID2D1Bitmap;
__interface DELPHIINTERFACE ID2D1Bitmap1;
typedef System::DelphiInterface<ID2D1Bitmap1> _di_ID2D1Bitmap1;
__interface DELPHIINTERFACE ID2D1Properties;
typedef System::DelphiInterface<ID2D1Properties> _di_ID2D1Properties;
__interface DELPHIINTERFACE ID2D1Effect;
typedef System::DelphiInterface<ID2D1Effect> _di_ID2D1Effect;
struct TD2D1EffectInputDescription;
__interface DELPHIINTERFACE ID2D1GradientStopCollection1;
typedef System::DelphiInterface<ID2D1GradientStopCollection1> _di_ID2D1GradientStopCollection1;
__interface DELPHIINTERFACE ID2D1ImageBrush;
typedef System::DelphiInterface<ID2D1ImageBrush> _di_ID2D1ImageBrush;
__interface DELPHIINTERFACE ID2D1BitmapBrush1;
typedef System::DelphiInterface<ID2D1BitmapBrush1> _di_ID2D1BitmapBrush1;
__interface DELPHIINTERFACE ID2D1Device;
typedef System::DelphiInterface<ID2D1Device> _di_ID2D1Device;
__interface DELPHIINTERFACE ID2D1DeviceContext;
typedef System::DelphiInterface<ID2D1DeviceContext> _di_ID2D1DeviceContext;
__interface DELPHIINTERFACE ID2D1StrokeStyle1;
typedef System::DelphiInterface<ID2D1StrokeStyle1> _di_ID2D1StrokeStyle1;
__interface DELPHIINTERFACE ID2D1PathGeometry1;
typedef System::DelphiInterface<ID2D1PathGeometry1> _di_ID2D1PathGeometry1;
__interface DELPHIINTERFACE ID2D1DrawingStateBlock1;
typedef System::DelphiInterface<ID2D1DrawingStateBlock1> _di_ID2D1DrawingStateBlock1;
__interface DELPHIINTERFACE ID2D1Factory1;
typedef System::DelphiInterface<ID2D1Factory1> _di_ID2D1Factory1;
struct TD3D11MappedSubResource;
struct TD3D11Box;
__interface DELPHIINTERFACE ID3D11DeviceChild;
typedef System::DelphiInterface<ID3D11DeviceChild> _di_ID3D11DeviceChild;
__interface DELPHIINTERFACE ID3D11PixelShader;
typedef System::DelphiInterface<ID3D11PixelShader> _di_ID3D11PixelShader;
__interface DELPHIINTERFACE ID3D11VertexShader;
typedef System::DelphiInterface<ID3D11VertexShader> _di_ID3D11VertexShader;
__interface DELPHIINTERFACE ID3D11Resource;
typedef System::DelphiInterface<ID3D11Resource> _di_ID3D11Resource;
struct TD3D11BufferDesc;
struct TD3D11Texture2DDesc;
__interface DELPHIINTERFACE ID3D11Buffer;
typedef System::DelphiInterface<ID3D11Buffer> _di_ID3D11Buffer;
__interface DELPHIINTERFACE ID3D11Texture2D;
typedef System::DelphiInterface<ID3D11Texture2D> _di_ID3D11Texture2D;
__interface DELPHIINTERFACE ID3D11InputLayout;
typedef System::DelphiInterface<ID3D11InputLayout> _di_ID3D11InputLayout;
__interface DELPHIINTERFACE ID3D11GeometryShader;
typedef System::DelphiInterface<ID3D11GeometryShader> _di_ID3D11GeometryShader;
__interface DELPHIINTERFACE ID3D11Asynchronous;
typedef System::DelphiInterface<ID3D11Asynchronous> _di_ID3D11Asynchronous;
__interface DELPHIINTERFACE ID3D11BlendState;
typedef System::DelphiInterface<ID3D11BlendState> _di_ID3D11BlendState;
__interface DELPHIINTERFACE ID3D11CommandList;
typedef System::DelphiInterface<ID3D11CommandList> _di_ID3D11CommandList;
__interface DELPHIINTERFACE ID3D11HullShader;
typedef System::DelphiInterface<ID3D11HullShader> _di_ID3D11HullShader;
__interface DELPHIINTERFACE ID3D11DomainShader;
typedef System::DelphiInterface<ID3D11DomainShader> _di_ID3D11DomainShader;
__interface DELPHIINTERFACE ID3D11ComputeShader;
typedef System::DelphiInterface<ID3D11ComputeShader> _di_ID3D11ComputeShader;
__interface DELPHIINTERFACE ID3D11Device;
typedef System::DelphiInterface<ID3D11Device> _di_ID3D11Device;
__interface DELPHIINTERFACE ID3D11DeviceContext;
typedef System::DelphiInterface<ID3D11DeviceContext> _di_ID3D11DeviceContext;
struct TDCompositionFrameStatistics;
__interface DELPHIINTERFACE IDCompositionEffect;
typedef System::DelphiInterface<IDCompositionEffect> _di_IDCompositionEffect;
__interface DELPHIINTERFACE IDCompositionVisual;
typedef System::DelphiInterface<IDCompositionVisual> _di_IDCompositionVisual;
__interface DELPHIINTERFACE IDCompositionTarget;
typedef System::DelphiInterface<IDCompositionTarget> _di_IDCompositionTarget;
__interface DELPHIINTERFACE IDCompositionVisual2;
typedef System::DelphiInterface<IDCompositionVisual2> _di_IDCompositionVisual2;
__interface DELPHIINTERFACE IDCompositionDevice;
typedef System::DelphiInterface<IDCompositionDevice> _di_IDCompositionDevice;
__interface DELPHIINTERFACE IDCompositionDevice2;
typedef System::DelphiInterface<IDCompositionDevice2> _di_IDCompositionDevice2;
__interface DELPHIINTERFACE IDCompositionDesktopDevice;
typedef System::DelphiInterface<IDCompositionDesktopDevice> _di_IDCompositionDesktopDevice;
//-- type declarations -------------------------------------------------------
typedef System::_di_IInterface *PIUnknown;

typedef __int64 TdxLargeInteger;

typedef System::DynamicArray<D2D1_GRADIENT_STOP> TD2D1GradientStops;

typedef DXGI_USAGE TDXGIUsage;

enum DECLSPEC_DENUM TDXGIModeRotation : unsigned int { DXGI_MODE_ROTATION_UNSPECIFIED, DXGI_MODE_ROTATION_IDENTITY, DXGI_MODE_ROTATION_ROTATE90, DXGI_MODE_ROTATION_ROTATE180, DXGI_MODE_ROTATION_ROTATE270 };

typedef TDXGIOutputDesc *PDXGIOutputDesc;

struct DECLSPEC_DRECORD TDXGIOutputDesc
{
public:
	System::StaticArray<System::WideChar, 32> DeviceName;
	System::Types::TRect DesktopCoordinates;
	System::LongBool AttachedToDesktop;
	TDXGIModeRotation Rotation;
	HMONITOR Monitor;
};


typedef TDXGIRational *PDXGIRational;

struct DECLSPEC_DRECORD TDXGIRational
{
public:
	unsigned Numerator;
	unsigned Denominator;
};


enum DECLSPEC_DENUM TDXGIModeScanlineOrder : unsigned int { DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED, DXGI_MODE_SCANLINE_ORDER_PROGRESSIVE, DXGI_MODE_SCANLINE_ORDER_UPPER_FIELD_FIRST, DXGI_MODE_SCANLINE_ORDER_LOWER_FIELD_FIRST };

enum DECLSPEC_DENUM TDXGIModeScaling : unsigned int { DXGI_MODE_SCALING_UNSPECIFIED, DXGI_MODE_SCALING_CENTERED, DXGI_MODE_SCALING_STRETCHED };

typedef TDXGIModeDesc *PDXGIModeDesc;

struct DECLSPEC_DRECORD TDXGIModeDesc
{
public:
	unsigned Width;
	unsigned Height;
	TDXGIRational RefreshRate;
	DXGI_FORMAT Format;
	TDXGIModeScanlineOrder ScanlineOrdering;
	TDXGIModeScaling Scaling;
};


typedef TDXGIGammaControlCapabilities *PDXGIGammaControlCapabilities;

struct DECLSPEC_DRECORD TDXGIGammaControlCapabilities
{
public:
	System::LongBool ScaleAndOffsetSupported;
	float MaxConvertedValue;
	float MinConvertedValue;
	unsigned NumGammaControlPoints;
	System::StaticArray<float, 1025> ControlPointPositions;
};


struct DECLSPEC_DRECORD TDXGIRGB
{
public:
	float Red;
	float Green;
	float Blue;
};


typedef D3DCOLORVALUE TDXGIRGBA;

typedef D3DCOLORVALUE *PDXGIRGBA;

struct DECLSPEC_DRECORD TDXGIGammaControl
{
public:
	TDXGIRGB Scale;
	TDXGIRGB Offset;
	System::StaticArray<TDXGIRGB, 1025> GammaCurve;
};


typedef TDXGISampleDesc *PDXGISampleDesc;

struct DECLSPEC_DRECORD TDXGISampleDesc
{
public:
	unsigned Count;
	unsigned Quality;
};


typedef TDXGISurfaceDesc *PDXGISurfaceDesc;

struct DECLSPEC_DRECORD TDXGISurfaceDesc
{
public:
	unsigned Width;
	unsigned Height;
	DXGI_FORMAT Format;
	TDXGISampleDesc SampleDesc;
};


typedef TDXGIMappedRect *PDXGIMappedRect;

struct DECLSPEC_DRECORD TDXGIMappedRect
{
public:
	int Pitch;
	System::Byte *pBits;
};


typedef TDXGIFrameStatistics *PDXGIFrameStatistics;

struct DECLSPEC_DRECORD TDXGIFrameStatistics
{
public:
	unsigned PresentCount;
	unsigned PresentRefreshCount;
	unsigned SyncRefreshCount;
	__int64 SyncQPCTime;
	__int64 SyncGPUTime;
};


typedef TDXGIAdapterDesc *PDXGIAdapterDesc;

struct DECLSPEC_DRECORD TDXGIAdapterDesc
{
public:
	System::StaticArray<System::WideChar, 128> Description;
	unsigned VendorId;
	unsigned DeviceId;
	unsigned SubSysId;
	unsigned Revision;
	System::Types::TSize DedicatedVideoMemory;
	System::Types::TSize DedicatedSystemMemory;
	System::Types::TSize SharedVideoMemory;
	_LUID AdapterLuid;
};


typedef TDXGISharedResource *PDXGISharedResource;

struct DECLSPEC_DRECORD TDXGISharedResource
{
public:
	NativeUInt Handle;
};


enum DECLSPEC_DENUM TDXGIResidency : unsigned int { DXGI_RESIDENCY_FULLY_RESIDENT = 1, DXGI_RESIDENCY_RESIDENT_IN_SHARED_MEMORY, DXGI_RESIDENCY_EVICTED_TO_DISK };

typedef TDXGIResidency *PDXGIResidency;

enum DECLSPEC_DENUM TDXGISwapEffect : unsigned int { DXGI_SWAP_EFFECT_DISCARD, DXGI_SWAP_EFFECT_SEQUENTIAL, DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL = 3, DXGI_SWAP_EFFECT_FLIP_DISCARD };

typedef TDXGIModeDesc1 *PDXGIModeDesc1;

struct DECLSPEC_DRECORD TDXGIModeDesc1
{
public:
	unsigned Width;
	unsigned Height;
	TDXGIRational RefreshRate;
	DXGI_FORMAT Format;
	TDXGIModeScanlineOrder ScanlineOrdering;
	TDXGIModeScaling Scaling;
	System::LongBool Stereo;
};


enum DECLSPEC_DENUM TDXGIScaling : unsigned int { DXGI_SCALING_STRETCH, DXGI_SCALING_NONE, DXGI_SCALING_ASPECT_RATIO_STRETCH };

enum DECLSPEC_DENUM TDXGIAlphaMode : unsigned int { DXGI_ALPHA_MODE_UNSPECIFIED, DXGI_ALPHA_MODE_PREMULTIPLIED, DXGI_ALPHA_MODE_STRAIGHT, DXGI_ALPHA_MODE_IGNORE };

typedef TDXGISwapChainDesc1 *PDXGISwapChainDesc1;

struct DECLSPEC_DRECORD TDXGISwapChainDesc1
{
public:
	unsigned Width;
	unsigned Height;
	DXGI_FORMAT Format;
	System::LongBool Stereo;
	TDXGISampleDesc SampleDesc;
	DXGI_USAGE BufferUsage;
	unsigned BufferCount;
	TDXGIScaling Scaling;
	TDXGISwapEffect SwapEffect;
	TDXGIAlphaMode AlphaMode;
	unsigned Flags;
};


typedef TDXGISwapChainFullScreenDesc *PDXGISwapChainFullScreenDesc;

struct DECLSPEC_DRECORD TDXGISwapChainFullScreenDesc
{
public:
	TDXGIRational RefreshRate;
	TDXGIModeScanlineOrder ScanlineOrdering;
	TDXGIModeScaling Scaling;
	System::LongBool Windowed;
};


typedef TDXGIPresentParameters *PDXGIPresentParameters;

struct DECLSPEC_DRECORD TDXGIPresentParameters
{
public:
	unsigned DirtyRectsCount;
	System::Types::TRect *pDirtyRects;
	System::Types::TRect *pScrollRect;
	System::Types::TPoint *pScrollOffset;
};


typedef TDXGISwapChainDesc *PDXGISwapChainDesc;

struct DECLSPEC_DRECORD TDXGISwapChainDesc
{
public:
	TDXGIModeDesc BufferDesc;
	TDXGISampleDesc SampleDesc;
	DXGI_USAGE BufferUsage;
	unsigned BufferCount;
	HWND OutputWindow;
	System::LongBool Windowed;
	TDXGISwapEffect SwapEffect;
	unsigned Flags;
};


struct DECLSPEC_DRECORD TDXGIAdapterDesc1
{
public:
	System::StaticArray<System::WideChar, 128> Description;
	unsigned VendorId;
	unsigned DeviceId;
	unsigned SubSysId;
	unsigned Revision;
	System::Types::TSize DedicatedVideoMemory;
	System::Types::TSize DedicatedSystemMemory;
	System::Types::TSize SharedSystemMemory;
	_LUID AdapterLuid;
	unsigned Flags;
};


__interface  INTERFACE_UUID("{AEC22FB8-76F3-4639-9BE0-28EB43A67A2E}") IDXGIObject  : public System::IInterface 
{
	virtual HRESULT __stdcall SetPrivateData(const GUID &Name, unsigned DataSize, void * pData) = 0 ;
	virtual HRESULT __stdcall SetPrivateDataInterface(const GUID &Name, const System::_di_IInterface pUnknown) = 0 ;
	virtual HRESULT __stdcall GetPrivateData(const GUID &Name, unsigned &pDataSize, void * pData) = 0 ;
	virtual HRESULT __stdcall GetParent(const GUID &riid, /* out */ void *ppParent) = 0 ;
};

__interface  INTERFACE_UUID("{3D3E0379-F9DE-4D58-BB6C-18D62992F1A6}") IDXGIDeviceSubObject  : public IDXGIObject 
{
	virtual HRESULT __stdcall GetDevice(const GUID &riid, /* out */ void *ppDevice) = 0 ;
};

__interface  INTERFACE_UUID("{CAFCB56C-6AC3-4889-BF47-9E23BBD260EC}") IDXGISurface  : public IDXGIDeviceSubObject 
{
	virtual HRESULT __stdcall GetDesc(/* out */ TDXGISurfaceDesc &pDesc) = 0 ;
	virtual HRESULT __stdcall Map(/* out */ TDXGIMappedRect &pLockedRect, unsigned MapFlags) = 0 ;
	virtual HRESULT __stdcall Unmap() = 0 ;
};

__interface  INTERFACE_UUID("{4AE63092-6327-4C1B-80AE-BFE12EA32B86}") IDXGISurface1  : public IDXGISurface 
{
	virtual HRESULT __stdcall GetDC(System::LongBool Discard, /* out */ HDC &hdc) = 0 ;
	virtual HRESULT __stdcall ReleaseDC(System::Types::PRect pDirtyRect) = 0 ;
};

__interface  INTERFACE_UUID("{AE02EEDB-C735-4690-8D52-5A8DC20213AA}") IDXGIOutput  : public IDXGIObject 
{
	virtual HRESULT __stdcall GetDesc(/* out */ TDXGIOutputDesc &pDesc) = 0 ;
	virtual HRESULT __stdcall GetDisplayModeList(DXGI_FORMAT EnumFormat, unsigned Flags, unsigned &pNumModes, PDXGIModeDesc pDesc) = 0 ;
	virtual HRESULT __stdcall FindClosestMatchingMode(const TDXGIModeDesc &pModeToMatch, /* out */ TDXGIModeDesc &pClosestMatch, const System::_di_IInterface pConcernedDevice) = 0 ;
	virtual HRESULT __stdcall WaitForVBlank() = 0 ;
	virtual HRESULT __stdcall TakeOwnership(const System::_di_IInterface pDevice, System::LongBool Exclusive) = 0 ;
	virtual HRESULT __stdcall ReleaseOwnership() = 0 ;
	virtual HRESULT __stdcall GetGammaControlCapabilities(/* out */ TDXGIGammaControlCapabilities &pGammaCaps) = 0 ;
	virtual HRESULT __stdcall SetGammaControl(const TDXGIGammaControl &pArray) = 0 ;
	virtual HRESULT __stdcall GetGammaControl(/* out */ TDXGIGammaControl &pArray) = 0 ;
	virtual HRESULT __stdcall SetDisplaySurface(const _di_IDXGISurface pScanOutSurface) = 0 ;
	virtual HRESULT __stdcall GetDisplaySurfaceData(const _di_IDXGISurface pDestination) = 0 ;
	virtual HRESULT __stdcall GetFrameStatistics(/* out */ TDXGIFrameStatistics &pStats) = 0 ;
};

__interface  INTERFACE_UUID("{2411E7E1-12AC-4CCF-BD14-9798E8534DC0}") IDXGIAdapter  : public IDXGIObject 
{
	virtual HRESULT __stdcall EnumOutputs(unsigned Output, /* out */ _di_IDXGIOutput &ppOutput) = 0 ;
	virtual HRESULT __stdcall GetDesc(/* out */ TDXGIAdapterDesc &pDesc) = 0 ;
	virtual HRESULT __stdcall CheckInterfaceSupport(const GUID &InterfaceName, /* out */ __int64 &pUMDVersion) = 0 ;
};

__interface  INTERFACE_UUID("{54EC77FA-1377-44E6-8C32-88FD5F44C84C}") IDXGIDevice  : public IDXGIObject 
{
	virtual HRESULT __stdcall GetAdapter(/* out */ _di_IDXGIAdapter &pAdapter) = 0 ;
	virtual HRESULT __stdcall CreateSurface(const TDXGISurfaceDesc &pDesc, unsigned NumSurfaces, DXGI_USAGE Usage, const TDXGISharedResource pSharedResource, /* out */ _di_IDXGISurface &ppSurface) = 0 ;
	virtual HRESULT __stdcall QueryResourceResidency(const PIUnknown ppResources, /* out */ PDXGIResidency &pResidencyStatus, unsigned NumResources) = 0 ;
	virtual HRESULT __stdcall SetGPUThreadPriority(int Priority) = 0 ;
	virtual HRESULT __stdcall GetGPUThreadPriority(/* out */ int &pPriority) = 0 ;
};

__interface  INTERFACE_UUID("{77DB970F-6276-48BA-BA28-070143B4392C}") IDXGIDevice1  : public IDXGIDevice 
{
	virtual HRESULT __stdcall SetMaximumFrameLatency(unsigned MaxLatency) = 0 ;
	virtual HRESULT __stdcall GetMaximumFrameLatency(/* out */ unsigned &pMaxLatency) = 0 ;
};

__interface  INTERFACE_UUID("{310D36A0-D2E7-4C0A-AA04-6A9D23B8886A}") IDXGISwapChain  : public IDXGIDeviceSubObject 
{
	virtual HRESULT __stdcall Present(unsigned SyncInterval, unsigned Flags) = 0 ;
	virtual HRESULT __stdcall GetBuffer(unsigned Buffer, const GUID &riid, /* out */ void *ppSurface) = 0 ;
	virtual HRESULT __stdcall SetFullScreenState(System::LongBool FullScreen, _di_IDXGIOutput pTarget) = 0 ;
	virtual HRESULT __stdcall GetFullScreenState(/* out */ System::LongBool &pFullScreen, /* out */ _di_IDXGIOutput &ppTarget) = 0 ;
	virtual HRESULT __stdcall GetDesc(/* out */ TDXGISwapChainDesc &pDesc) = 0 ;
	virtual HRESULT __stdcall ResizeBuffers(unsigned BufferCount, unsigned Width, unsigned Height, DXGI_FORMAT NewFormat, unsigned SwapChainFlags) = 0 ;
	virtual HRESULT __stdcall ResizeTarget(const PDXGIModeDesc pNewTargetParameters) = 0 ;
	virtual HRESULT __stdcall GetContainingOutput(/* out */ _di_IDXGIOutput &ppOutput) = 0 ;
	virtual HRESULT __stdcall GetFrameStatistics(/* out */ TDXGIFrameStatistics &pStats) = 0 ;
	virtual HRESULT __stdcall GetLastPresentCount(/* out */ unsigned &pLastPresentCount) = 0 ;
};

__interface  INTERFACE_UUID("{790A45F7-0D42-4876-983A-0A55CFE6F4AA}") IDXGISwapChain1  : public IDXGISwapChain 
{
	virtual HRESULT __stdcall GetDesc1(/* out */ TDXGISwapChainDesc1 &pDesc) = 0 ;
	virtual HRESULT __stdcall GetFullScreenDesc(/* out */ TDXGISwapChainFullScreenDesc &pDesc) = 0 ;
	virtual HRESULT __stdcall GetHwnd(/* out */ HWND &pHwnd) = 0 ;
	virtual HRESULT __stdcall GetCoreWindow(GUID RefIID, /* out */ void * &ppUnk) = 0 ;
	virtual HRESULT __stdcall Present1(unsigned SyncInterval, unsigned PresentFlags, PDXGIPresentParameters pPresentParameters) = 0 ;
	virtual System::LongBool __stdcall IsTemporaryMonoSupported() = 0 ;
	virtual HRESULT __stdcall GetRestrictToOutput(/* out */ _di_IDXGIOutput &ppRestrictToOutput) = 0 ;
	virtual HRESULT __stdcall SetBackgroundColor(PDXGIRGBA pColor) = 0 ;
	virtual HRESULT __stdcall GetBackgroundColor(/* out */ D3DCOLORVALUE &pColor) = 0 ;
	virtual HRESULT __stdcall SetRotation(TDXGIModeRotation Rotation) = 0 ;
	virtual HRESULT __stdcall GetRotation(/* out */ TDXGIModeRotation &pRotation) = 0 ;
};

__interface  INTERFACE_UUID("{7B7166EC-21C7-44AE-B21A-C9AE321AE369}") IDXGIFactory  : public IDXGIObject 
{
	virtual HRESULT __stdcall EnumAdapters(unsigned Adapter, /* out */ _di_IDXGIAdapter &ppAdapter) = 0 ;
	virtual HRESULT __stdcall MakeWindowAssociation(HWND WindowHandle, unsigned Flags) = 0 ;
	virtual HRESULT __stdcall GetWindowAssociation(/* out */ HWND &pWindowHandle) = 0 ;
	virtual HRESULT __stdcall CreateSwapChain(System::_di_IInterface pDevice, PDXGISwapChainDesc pDesc, /* out */ _di_IDXGISwapChain &ppSwapChain) = 0 ;
	virtual HRESULT __stdcall CreateSoftwareAdapter(NativeUInt Module, /* out */ _di_IDXGIAdapter &ppAdapter) = 0 ;
};

__interface  INTERFACE_UUID("{29038F61-3839-4626-91FD-086879011A05}") IDXGIAdapter1  : public IDXGIAdapter 
{
	virtual HRESULT __stdcall GetDesc1(/* out */ TDXGIAdapterDesc1 &pDesc) = 0 ;
};

__interface  INTERFACE_UUID("{770AAE78-F26F-4DBA-A829-253C83D1B387}") IDXGIFactory1  : public IDXGIFactory 
{
	virtual HRESULT __stdcall EnumAdapters1(unsigned Adapter, /* out */ _di_IDXGIAdapter1 &ppAdapter) = 0 ;
	virtual System::LongBool __stdcall IsCurrent() = 0 ;
};

__interface  INTERFACE_UUID("{50C83A1C-E072-4C48-87B0-3630FA36A6D0}") IDXGIFactory2  : public IDXGIFactory1 
{
	virtual System::LongBool __stdcall IsWindowedStereoEnabled() = 0 ;
	virtual HRESULT __stdcall CreateSwapChainForHwnd(System::_di_IInterface pDevice, HWND hWnd, PDXGISwapChainDesc1 pDesc, PDXGISwapChainFullScreenDesc pFullScreenDesc, _di_IDXGIOutput pRestrictToOutput, /* out */ _di_IDXGISwapChain1 &ppSwapChain) = 0 ;
	virtual HRESULT __stdcall CreateSwapChainForCoreWindow(System::_di_IInterface pDevice, System::_di_IInterface pWindow, PDXGISwapChainDesc1 pDesc, _di_IDXGIOutput pRestrictToOutput, /* out */ _di_IDXGISwapChain1 &ppSwapChain) = 0 ;
	virtual HRESULT __stdcall GetSharedResourceAdapterLuid(NativeUInt hResource, /* out */ _LUID &pLuid) = 0 ;
	virtual HRESULT __stdcall RegisterStereoStatusWindow(HWND WindowHandle, unsigned wMsg, /* out */ unsigned &pdwCookie) = 0 ;
	virtual HRESULT __stdcall RegisterStereoStatusEvent(NativeUInt hEvent, /* out */ unsigned &pdwCookie) = 0 ;
	virtual void __stdcall UnregisterStereoStatus(unsigned dwCookie) = 0 ;
	virtual HRESULT __stdcall RegisterOcclusionStatusWindow(HWND WindowHandle, unsigned wMsg, /* out */ unsigned &pdwCookie) = 0 ;
	virtual HRESULT __stdcall RegisterOcclusionStatusEvent(NativeUInt hEvent, /* out */ unsigned &pdwCookie) = 0 ;
	virtual void __stdcall UnregisterOcclusionStatus(unsigned dwCookie) = 0 ;
	virtual HRESULT __stdcall CreateSwapChainForComposition(System::_di_IInterface pDevice, PDXGISwapChainDesc1 pDesc, _di_IDXGIOutput pRestrictToOutput, /* out */ _di_IDXGISwapChain1 &ppSwapChain) = 0 ;
};

typedef int TD2D1BitmapOptions;

enum DECLSPEC_DENUM TD2D1ColorSpace : unsigned int { D2D1_COLOR_SPACE_CUSTOM, D2D1_COLOR_SPACE_SRGB, D2D1_COLOR_SPACE_SCRGB };

typedef TD2D1MappedRect *PD2D1MappedRect;

struct DECLSPEC_DRECORD TD2D1MappedRect
{
public:
	unsigned pitch;
	System::Byte *bits;
};


enum DECLSPEC_DENUM TD2D1PropertyType : unsigned int { D2D1_PROPERTY_TYPE_UNKNOWN, D2D1_PROPERTY_TYPE_STRING, D2D1_PROPERTY_TYPE_BOOL, D2D1_PROPERTY_TYPE_UINT32, D2D1_PROPERTY_TYPE_INT32, D2D1_PROPERTY_TYPE_FLOAT, D2D1_PROPERTY_TYPE_VECTOR2, D2D1_PROPERTY_TYPE_VECTOR3, D2D1_PROPERTY_TYPE_VECTOR4, D2D1_PROPERTY_TYPE_BLOB, D2D1_PROPERTY_TYPE_IUNKNOWN, D2D1_PROPERTY_TYPE_ENUM, D2D1_PROPERTY_TYPE_ARRAY, D2D1_PROPERTY_TYPE_CLSID, D2D1_PROPERTY_TYPE_MATRIX_3X2, D2D1_PROPERTY_TYPE_MATRIX_4X3, D2D1_PROPERTY_TYPE_MATRIX_4X4, D2D1_PROPERTY_TYPE_MATRIX_5X4, D2D1_PROPERTY_TYPE_COLOR_CONTEXT };

typedef int TD2D1Property;

typedef int TD2D1SubProperty;

enum DECLSPEC_DENUM TD2D1BufferPrecision : unsigned int { D2D1_BUFFER_PRECISION_UNKNOWN, D2D1_BUFFER_PRECISION_8BPC_UNORM, D2D1_BUFFER_PRECISION_8BPC_UNORM_SRGB, D2D1_BUFFER_PRECISION_16BPC_UNORM, D2D1_BUFFER_PRECISION_16BPC_FLOAT, D2D1_BUFFER_PRECISION_32BPC_FLOAT };

enum DECLSPEC_DENUM TD2D1ColorInterpolationMode : unsigned int { D2D1_COLOR_INTERPOLATION_MODE_STRAIGHT, D2D1_COLOR_INTERPOLATION_MODE_PREMULTIPLIED };

enum DECLSPEC_DENUM TD2D1MapOptions : unsigned int { D2D1_MAP_OPTIONS_NONE, D2D1_MAP_OPTIONS_READ, D2D1_MAP_OPTIONS_WRITE, D2D1_MAP_OPTIONS_DISCARD = 0x4 };

enum DECLSPEC_DENUM TD2D1InterpolationMode : unsigned int { D2D1_INTERPOLATION_MODE_NEAREST_NEIGHBOR, D2D1_INTERPOLATION_MODE_LINEAR, D2D1_INTERPOLATION_MODE_CUBIC, D2D1_INTERPOLATION_MODE_MULTI_SAMPLE_LINEAR, D2D1_INTERPOLATION_MODE_ANISOTROPIC, D2D1_INTERPOLATION_MODE_HIGH_QUALITY_CUBIC };

typedef TD2D1ImageBrushProperties *PD2D1ImageBrushProperties;

struct DECLSPEC_DRECORD TD2D1ImageBrushProperties
{
public:
	D2D_RECT_F sourceRectangle;
	D2D1_EXTEND_MODE extendModeX;
	D2D1_EXTEND_MODE extendModeY;
	TD2D1InterpolationMode interpolationMode;
};


typedef TD2D1BitmapBrushProperties1 *PD2D1BitmapBrushProperties1;

struct DECLSPEC_DRECORD TD2D1BitmapBrushProperties1
{
public:
	D2D1_EXTEND_MODE extendModeX;
	D2D1_EXTEND_MODE extendModeY;
	TD2D1InterpolationMode interpolationMode;
};


typedef TD2D1RenderingControls *PD2D1RenderingControls;

struct DECLSPEC_DRECORD TD2D1RenderingControls
{
public:
	TD2D1BufferPrecision bufferPrecision;
	D2D_SIZE_U tileSize;
};


enum DECLSPEC_DENUM TD2D1PrimitiveBlend : unsigned int { D2D1_PRIMITIVE_BLEND_SOURCE_OVER, D2D1_PRIMITIVE_BLEND_COPY, D2D1_PRIMITIVE_BLEND_MIN, D2D1_PRIMITIVE_BLEND_ADD, D2D1_PRIMITIVE_BLEND_MAX };

enum DECLSPEC_DENUM TD2D1CompositeMode : unsigned int { D2D1_COMPOSITE_MODE_SOURCE_OVER, D2D1_COMPOSITE_MODE_DESTINATION_OVER, D2D1_COMPOSITE_MODE_SOURCE_IN, D2D1_COMPOSITE_MODE_DESTINATION_IN, D2D1_COMPOSITE_MODE_SOURCE_OUT, D2D1_COMPOSITE_MODE_DESTINATION_OUT, D2D1_COMPOSITE_MODE_SOURCE_ATOP, D2D1_COMPOSITE_MODE_DESTINATION_ATOP, D2D1_COMPOSITE_MODE_XOR, D2D1_COMPOSITE_MODE_PLUS, D2D1_COMPOSITE_MODE_SOURCE_COPY, D2D1_COMPOSITE_MODE_BOUNDED_SOURCE_COPY, D2D1_COMPOSITE_MODE_MASK_INVERT };

enum DECLSPEC_DENUM TD2D1DeviceContextOptions : unsigned int { D2D1_DEVICE_CONTEXT_OPTIONS_NONE, D2D1_DEVICE_CONTEXT_OPTIONS_ENABLE_MULTITHREADED_OPTIMIZATIONS };

enum DECLSPEC_DENUM TD2D1UnitMode : unsigned int { D2D1_UNIT_MODE_DIPS, D2D1_UNIT_MODE_PIXELS };

typedef TD2D1LayerParameters1 *PD2D1LayerParameters1;

struct DECLSPEC_DRECORD TD2D1LayerParameters1
{
public:
	D2D_RECT_F contentBounds;
	Winapi::D2d1::_di_ID2D1Geometry geometricMask;
	D2D1_ANTIALIAS_MODE maskAntiAliasMode;
	D2D_MATRIX_3X2_F maskTransform;
	float opacity;
	Winapi::D2d1::_di_ID2D1Brush opacityBrush;
	D2D1_LAYER_OPTIONS layerOptions;
};


enum DECLSPEC_DENUM TD2D1StrokeTransformType : unsigned int { D2D1_STROKE_TRANSFORM_TYPE_NORMAL, D2D1_STROKE_TRANSFORM_TYPE_FIXED, D2D1_STROKE_TRANSFORM_TYPE_HAIRLINE };

typedef TD2D1StrokeStyleProperties1 *PD2D1StrokeStyleProperties1;

struct DECLSPEC_DRECORD TD2D1StrokeStyleProperties1
{
public:
	D2D1_CAP_STYLE startCap;
	D2D1_CAP_STYLE endCap;
	D2D1_CAP_STYLE dashCap;
	D2D1_LINE_JOIN lineJoin;
	float miterLimit;
	D2D1_DASH_STYLE dashStyle;
	float dashOffset;
	TD2D1StrokeTransformType transformType;
};


typedef TD2D1PointDescription *PD2D1PointDescription;

struct DECLSPEC_DRECORD TD2D1PointDescription
{
public:
	D2D_POINT_2F point;
	D2D_POINT_2F unitTangentVector;
	unsigned endSegment;
	unsigned endFigure;
	float lengthToEndSegment;
};


typedef TD2D1DrawingStateDescription1 *PD2D1DrawingStateDescription1;

struct DECLSPEC_DRECORD TD2D1DrawingStateDescription1
{
public:
	D2D1_ANTIALIAS_MODE antiAliasMode;
	D2D1_TEXT_ANTIALIAS_MODE textAntiAliasMode;
	unsigned __int64 tag1;
	unsigned __int64 tag2;
	D2D_MATRIX_3X2_F transform;
	TD2D1PrimitiveBlend primitiveBlend;
	TD2D1UnitMode unitMode;
};


typedef HRESULT __stdcall (*TD2D1PropertySetFunc)(System::_di_IInterface effect, System::PByte Data, unsigned dataSize);

typedef HRESULT __stdcall (*TD2D1PropertyGetFunc)(System::_di_IInterface effect, /* out */ System::PByte &Data, unsigned dataSize, /* out */ unsigned &actualSize);

typedef TD2D1PropertyBinding *PD2D1PropertyBinding;

struct DECLSPEC_DRECORD TD2D1PropertyBinding
{
public:
	System::WideChar *propertyName;
	TD2D1PropertySetFunc setFunction;
	TD2D1PropertyGetFunc getFunction;
};


typedef TD2D1BitmapProperties1 *PD2D1BitmapProperties1;

struct DECLSPEC_DRECORD TD2D1BitmapProperties1
{
public:
	D2D1_PIXEL_FORMAT pixelFormat;
	float dpiX;
	float dpiY;
	TD2D1BitmapOptions bitmapOptions;
	_di_ID2D1ColorContext colorContext;
};


__interface  INTERFACE_UUID("{1C4820BB-5771-4518-A581-2FE4DD0EC657}") ID2D1ColorContext  : public Winapi::D2d1::ID2D1Resource 
{
	virtual TD2D1ColorSpace __stdcall GetColorSpace() = 0 ;
	virtual unsigned __stdcall GetProfileSize() = 0 ;
	virtual HRESULT __stdcall GetProfile(/* out */ System::PByte &profile, unsigned profileSize) = 0 ;
};

__interface  INTERFACE_UUID("{65019F75-8DA2-497C-B32C-DFA34E48EDE6}") ID2D1Image  : public Winapi::D2d1::ID2D1Resource 
{
	
};

__interface  INTERFACE_UUID("{A2296057-EA42-4099-983B-539FB6505426}") ID2D1Bitmap  : public ID2D1Image 
{
	virtual D2D_SIZE_F __stdcall GetSize() = 0 ;
	virtual D2D_SIZE_U __stdcall GetPixelSize() = 0 ;
	virtual D2D1_PIXEL_FORMAT __stdcall GetPixelFormat() = 0 ;
	virtual void __stdcall GetDpi(/* out */ float &dpiX, /* out */ float &dpiY) = 0 ;
	virtual HRESULT __stdcall CopyFromBitmap(const Winapi::D2d1::PD2D1Point2U destPoint, _di_ID2D1Bitmap bitmap, const Winapi::D2d1::PD2D1RectU srcRect) = 0 ;
	virtual HRESULT __stdcall CopyFromRenderTarget(const Winapi::D2d1::PD2D1Point2U destPoint, Winapi::D2d1::_di_ID2D1RenderTarget renderTarget, const Winapi::D2d1::PD2D1RectU srcRect) = 0 ;
	virtual HRESULT __stdcall CopyFromMemory(const Winapi::D2d1::PD2D1RectU dstRect, void * srcData, unsigned pitch) = 0 ;
};

__interface  INTERFACE_UUID("{A898A84C-3873-4588-B08B-EBBF978DF041}") ID2D1Bitmap1  : public ID2D1Bitmap 
{
	virtual void __stdcall GetColorContext(/* out */ _di_ID2D1ColorContext &colorContext) = 0 ;
	virtual TD2D1BitmapOptions __stdcall GetOptions() = 0 ;
	virtual HRESULT __stdcall GetSurface(/* out */ _di_IDXGISurface &dxgiSurface) = 0 ;
	virtual HRESULT __stdcall Map(TD2D1MapOptions options, /* out */ TD2D1MappedRect &mappedRect) = 0 ;
	virtual HRESULT __stdcall Unmap() = 0 ;
};

__interface  INTERFACE_UUID("{483473D7-CD46-4F9D-9D3A-3112AA80159D}") ID2D1Properties  : public System::IInterface 
{
	virtual unsigned __stdcall GetPropertyCount() = 0 ;
	virtual HRESULT __stdcall GetPropertyName(unsigned index, /* out */ System::WideChar * &Name, unsigned nameCount) = 0 ;
	virtual unsigned __stdcall GetPropertyNameLength(unsigned index) = 0 ;
	virtual TD2D1PropertyType __stdcall GetType(unsigned index) = 0 ;
	virtual unsigned __stdcall GetPropertyIndex(System::WideChar * Name) = 0 ;
	virtual HRESULT __stdcall SetValueByName(System::WideChar * Name, TD2D1PropertyType _type, System::PByte Data, unsigned dataSize) = 0 ;
	virtual HRESULT __stdcall SetValue(unsigned index, TD2D1PropertyType _type, System::PByte Data, unsigned dataSize) = 0 ;
	virtual HRESULT __stdcall GetValueByName(System::WideChar * Name, TD2D1PropertyType _type, /* out */ System::PByte &Data, unsigned dataSize) = 0 ;
	virtual HRESULT __stdcall GetValue(unsigned index, TD2D1PropertyType _type, /* out */ System::PByte &Data, unsigned dataSize) = 0 ;
	virtual unsigned __stdcall GetValueSize(unsigned index) = 0 ;
	virtual HRESULT __stdcall GetSubProperties(unsigned index, /* out */ _di_ID2D1Properties &subProperties) = 0 ;
};

__interface  INTERFACE_UUID("{28211A43-7D89-476F-8181-2D6159B220AD}") ID2D1Effect  : public ID2D1Properties 
{
	virtual void __stdcall SetInput(unsigned index, _di_ID2D1Image input, System::LongBool invalidate = true) = 0 ;
	virtual HRESULT __stdcall SetInputCount(unsigned inputCount) = 0 ;
	virtual void __stdcall GetInput(unsigned index, /* out */ _di_ID2D1Image &input) = 0 ;
	virtual unsigned __stdcall GetInputCount() = 0 ;
	virtual void __stdcall GetOutput(/* out */ _di_ID2D1Image &outputImage) = 0 ;
};

typedef TD2D1EffectInputDescription *PD2D1EffectInputDescription;

struct DECLSPEC_DRECORD TD2D1EffectInputDescription
{
public:
	_di_ID2D1Effect effect;
	unsigned inputIndex;
	D2D_RECT_F inputRectangle;
};


__interface  INTERFACE_UUID("{AE1572F4-5DD0-4777-998B-9279472AE63B}") ID2D1GradientStopCollection1  : public Winapi::D2d1::ID2D1GradientStopCollection 
{
	virtual void __stdcall GetGradientStops1(/* out */ Winapi::D2d1::PD2D1GradientStop &gradientStops, unsigned gradientStopsCount) = 0 ;
	virtual TD2D1ColorSpace __stdcall GetPreInterpolationSpace() = 0 ;
	virtual TD2D1ColorSpace __stdcall GetPostInterpolationSpace() = 0 ;
	virtual TD2D1BufferPrecision __stdcall GetBufferPrecision() = 0 ;
	virtual TD2D1ColorInterpolationMode __stdcall GetColorInterpolationMode() = 0 ;
};

__interface  INTERFACE_UUID("{FE9E984D-3F95-407C-B5DB-CB94D4E8F87C}") ID2D1ImageBrush  : public Winapi::D2d1::ID2D1Brush 
{
	virtual void __stdcall SetImage(_di_ID2D1Image image) = 0 ;
	virtual void __stdcall SetExtendModeX(D2D1_EXTEND_MODE extendModeX) = 0 ;
	virtual void __stdcall SetExtendModeY(D2D1_EXTEND_MODE extendModeY) = 0 ;
	virtual void __stdcall SetInterpolationMode(TD2D1InterpolationMode interpolationMode) = 0 ;
	virtual void __stdcall SetSourceRectangle(D2D_RECT_F sourceRectangle) = 0 ;
	virtual void __stdcall GetImage(/* out */ _di_ID2D1Image &image) = 0 ;
	virtual D2D1_EXTEND_MODE __stdcall GetExtendModeX() = 0 ;
	virtual D2D1_EXTEND_MODE __stdcall GetExtendModeY() = 0 ;
	virtual TD2D1InterpolationMode __stdcall GetInterpolationMode() = 0 ;
	virtual void __stdcall GetSourceRectangle(/* out */ D2D_RECT_F &sourceRectangle) = 0 ;
};

__interface  INTERFACE_UUID("{41343A53-E41A-49A2-91CD-21793BBB62E5}") ID2D1BitmapBrush1  : public Winapi::D2d1::ID2D1BitmapBrush 
{
	virtual void __stdcall SetInterpolationMode1(TD2D1InterpolationMode interpolationMode) = 0 ;
	virtual TD2D1InterpolationMode __stdcall GetInterpolationMode1() = 0 ;
};

__interface  INTERFACE_UUID("{47DD575D-AC05-4CDD-8049-9B02CD16F44C}") ID2D1Device  : public Winapi::D2d1::ID2D1Resource 
{
	virtual HRESULT __stdcall CreateDeviceContext(TD2D1DeviceContextOptions options, /* out */ _di_ID2D1DeviceContext &deviceContext) = 0 ;
	virtual HRESULT __stdcall CreatePrintControl(_di_IWICImagingFactory wicFactory, System::_di_IInterface documentTarget, void * printControlProperties, /* out */ System::_di_IInterface &printControl) = 0 ;
	virtual void __stdcall SetMaximumTextureMemory(unsigned __int64 maximumInBytes) = 0 ;
	virtual unsigned __int64 __stdcall GetMaximumTextureMemory() = 0 ;
	virtual void __stdcall ClearResources(unsigned millisecondsSinceUse = (unsigned)(0x0)) = 0 ;
};

__interface  INTERFACE_UUID("{E8F7FE7A-191C-466D-AD95-975678BDA998}") ID2D1DeviceContext  : public Winapi::D2d1::ID2D1RenderTarget 
{
	HIDESBASE virtual HRESULT __stdcall CreateBitmap(D2D_SIZE_U size, void * sourceData, unsigned pitch, PD2D1BitmapProperties1 bitmapProperties, /* out */ _di_ID2D1Bitmap1 &bitmap) = 0 ;
	HIDESBASE virtual HRESULT __stdcall CreateBitmapFromWicBitmap(_di_IWICBitmapSource wicBitmapSource, PD2D1BitmapProperties1 bitmapProperties, /* out */ _di_ID2D1Bitmap1 &bitmap) = 0 ;
	virtual HRESULT __stdcall CreateColorContext(TD2D1ColorSpace space, System::PByte profile, unsigned profileSize, /* out */ _di_ID2D1ColorContext &colorContext) = 0 ;
	virtual HRESULT __stdcall CreateColorContextFromFilename(System::WideChar * filename, /* out */ _di_ID2D1ColorContext &colorContext) = 0 ;
	virtual HRESULT __stdcall CreateColorContextFromWicColorContext(_di_IWICColorContext wicColorContext, /* out */ _di_ID2D1ColorContext &colorContext) = 0 ;
	virtual HRESULT __stdcall CreateBitmapFromDxgiSurface(_di_IDXGISurface surface, const TD2D1BitmapProperties1 &bitmapProperties, /* out */ _di_ID2D1Bitmap1 &bitmap) = 0 ;
	virtual HRESULT __stdcall CreateEffect(const GUID &effectId, /* out */ _di_ID2D1Effect &effect) = 0 ;
	virtual HRESULT __stdcall CreateGradientStopCollection2(Winapi::D2d1::PD2D1GradientStop straightAlphaGradientStops, unsigned straightAlphaGradientStopsCount, TD2D1ColorSpace preInterpolationSpace, TD2D1ColorSpace postInterpolationSpace, TD2D1BufferPrecision bufferPrecision, D2D1_EXTEND_MODE extendMode, TD2D1ColorInterpolationMode colorInterpolationMode, /* out */ _di_ID2D1GradientStopCollection1 &gradientStopCollection1) = 0 ;
	virtual HRESULT __stdcall CreateImageBrush(_di_ID2D1Image image, PD2D1ImageBrushProperties imageBrushProperties, Winapi::D2d1::PD2D1BrushProperties brushProperties, /* out */ _di_ID2D1ImageBrush &imageBrush) = 0 ;
	HIDESBASE virtual HRESULT __stdcall CreateBitmapBrush(_di_ID2D1Bitmap bitmap, PD2D1BitmapBrushProperties1 bitmapBrushProperties, Winapi::D2d1::PD2D1BrushProperties brushProperties, /* out */ _di_ID2D1BitmapBrush1 &bitmapBrush) = 0 ;
	virtual HRESULT __stdcall CreateCommandList(/* out */ System::_di_IInterface &commandList) = 0 ;
	virtual System::LongBool __stdcall IsDxgiFormatSupported(DXGI_FORMAT format) = 0 ;
	virtual System::LongBool __stdcall IsBufferPrecisionSupported(TD2D1BufferPrecision bufferPrecision) = 0 ;
	virtual HRESULT __stdcall GetImageLocalBounds(_di_ID2D1Image image, /* out */ D2D_RECT_F &localBounds) = 0 ;
	virtual HRESULT __stdcall GetImageWorldBounds(_di_ID2D1Image image, /* out */ D2D_RECT_F &worldBounds) = 0 ;
	virtual HRESULT __stdcall GetGlyphRunWorldBounds(D2D_POINT_2F baselineOrigin, Winapi::D2d1::PDwriteGlyphRun glyphRun, DWRITE_MEASURING_MODE measuringMode, /* out */ D2D_RECT_F &bounds) = 0 ;
	virtual void __stdcall GetDevice(/* out */ _di_ID2D1Device &device) = 0 ;
	virtual void __stdcall SetTarget(_di_ID2D1Image image) = 0 ;
	virtual void __stdcall GetTarget(/* out */ _di_ID2D1Image &image) = 0 ;
	virtual void __stdcall SetRenderingControls(PD2D1RenderingControls renderingControls) = 0 ;
	virtual void __stdcall GetRenderingControls(/* out */ TD2D1RenderingControls &renderingControls) = 0 ;
	virtual void __stdcall SetPrimitiveBlend(TD2D1PrimitiveBlend primitiveBlend) = 0 ;
	virtual TD2D1PrimitiveBlend __stdcall GetPrimitiveBlend() = 0 ;
	virtual void __stdcall SetUnitMode(TD2D1UnitMode unitMode) = 0 ;
	virtual TD2D1UnitMode __stdcall GetUnitMode() = 0 ;
	HIDESBASE virtual void __stdcall DrawGlyphRun(D2D_POINT_2F baselineOrigin, Winapi::D2d1::PDwriteGlyphRun glyphRun, Winapi::D2d1::PDwriteGlyphRunDescription glyphRunDescription, Winapi::D2d1::_di_ID2D1Brush foregroundBrush, DWRITE_MEASURING_MODE measuringMode = (DWRITE_MEASURING_MODE)(0x0)) = 0 ;
	virtual void __stdcall DrawImage(_di_ID2D1Image image, Winapi::D2d1::PD2D1Point2F targetOffset = (Winapi::D2d1::PD2D1Point2F)(0x0), Winapi::D2d1::PD2D1RectF imageRectangle = (Winapi::D2d1::PD2D1RectF)(0x0), TD2D1InterpolationMode interpolationMode = (TD2D1InterpolationMode)(0x1), TD2D1CompositeMode compositeMode = (TD2D1CompositeMode)(0x0)) = 0 ;
	virtual void __stdcall DrawGdiMetafile(System::_di_IInterface gdiMetafile, Winapi::D2d1::PD2D1Point2F targetOffset = (Winapi::D2d1::PD2D1Point2F)(0x0)) = 0 ;
	HIDESBASE virtual void __stdcall DrawBitmap(_di_ID2D1Bitmap bitmap, Winapi::D2d1::PD2D1RectF destinationRectangle, float opacity, TD2D1InterpolationMode interpolationMode, Winapi::D2d1::PD2D1RectF sourceRectangle = (Winapi::D2d1::PD2D1RectF)(0x0), void * perspectiveTransform = (void *)(0x0)) = 0 ;
	HIDESBASE virtual void __stdcall PushLayer(PD2D1LayerParameters1 layerParameters, Winapi::D2d1::_di_ID2D1Layer layer) = 0 ;
	virtual HRESULT __stdcall InvalidateEffectInputRectangle(_di_ID2D1Effect effect, unsigned input, Winapi::D2d1::PD2D1RectF inputRectangle) = 0 ;
	virtual HRESULT __stdcall GetEffectInvalidRectangleCount(_di_ID2D1Effect effect, /* out */ unsigned &rectangleCount) = 0 ;
	virtual HRESULT __stdcall GetEffectInvalidRectangles(_di_ID2D1Effect effect, /* out */ Winapi::D2d1::PD2D1RectF &rectangles, unsigned rectanglesCount) = 0 ;
	virtual HRESULT __stdcall GetEffectRequiredInputRectangles(_di_ID2D1Effect renderEffect, Winapi::D2d1::PD2D1RectF renderImageRectangle, PD2D1EffectInputDescription inputDescriptions, /* out */ Winapi::D2d1::PD2D1RectF &requiredInputRects, unsigned inputCount) = 0 ;
	HIDESBASE virtual void __stdcall FillOpacityMask(_di_ID2D1Bitmap opacityMask, Winapi::D2d1::_di_ID2D1Brush brush, Winapi::D2d1::PD2D1RectF destinationRectangle = (Winapi::D2d1::PD2D1RectF)(0x0), Winapi::D2d1::PD2D1RectF sourceRectangle = (Winapi::D2d1::PD2D1RectF)(0x0)) = 0 ;
};

__interface  INTERFACE_UUID("{10A72A66-E91C-43F4-993F-DDF4B82B0B4A}") ID2D1StrokeStyle1  : public Winapi::D2d1::ID2D1StrokeStyle 
{
	virtual TD2D1StrokeTransformType __stdcall GetStrokeTransformType() = 0 ;
};

__interface  INTERFACE_UUID("{62BAA2D2-AB54-41B7-B872-787E0106A421}") ID2D1PathGeometry1  : public Winapi::D2d1::ID2D1PathGeometry 
{
	virtual HRESULT __stdcall ComputePointAndSegmentAtLength(float length, unsigned startSegment, Winapi::D2d1::PD2D1Matrix3x2F worldTransform, float flatteningTolerance, /* out */ TD2D1PointDescription &pointDescription) = 0 ;
};

__interface  INTERFACE_UUID("{689F1F85-C72E-4E33-8F19-85754EFD5ACE}") ID2D1DrawingStateBlock1  : public Winapi::D2d1::ID2D1DrawingStateBlock 
{
	HIDESBASE virtual void __stdcall GetDescription(/* out */ TD2D1DrawingStateDescription1 &stateDescription) = 0 ;
	HIDESBASE virtual void __stdcall SetDescription(PD2D1DrawingStateDescription1 stateDescription) = 0 ;
};

typedef HRESULT __stdcall (*TD2D1EffectFactoryCallback)(/* out */ System::_di_IInterface &effectImpl);

__interface  INTERFACE_UUID("{BB12D362-DAEE-4B9A-AA1D-14BA401CFA1F}") ID2D1Factory1  : public Winapi::D2d1::ID2D1Factory 
{
	virtual HRESULT __stdcall CreateDevice(_di_IDXGIDevice dxgiDevice, /* out */ _di_ID2D1Device &d2dDevice) = 0 ;
	HIDESBASE virtual HRESULT __stdcall CreateStrokeStyle(PD2D1StrokeStyleProperties1 strokeStyleProperties, Winapi::Windows::PSingle dashes, unsigned dashesCount, /* out */ _di_ID2D1StrokeStyle1 &strokeStyle) = 0 ;
	HIDESBASE virtual HRESULT __stdcall CreatePathGeometry(/* out */ _di_ID2D1PathGeometry1 &pathGeometry) = 0 ;
	HIDESBASE virtual HRESULT __stdcall CreateDrawingStateBlock(PD2D1DrawingStateDescription1 drawingStateDescription, Winapi::D2d1::_di_IDWriteRenderingParams textRenderingParams, /* out */ _di_ID2D1DrawingStateBlock1 &drawingStateBlock) = 0 ;
	virtual HRESULT __stdcall CreateGdiMetafile(_di_IStream metafileStream, /* out */ System::_di_IInterface &metafile) = 0 ;
	virtual HRESULT __stdcall RegisterEffectFromStream(GUID classId, _di_IStream propertyXml, PD2D1PropertyBinding bindings, unsigned bindingsCount, TD2D1EffectFactoryCallback effectFactory) = 0 ;
	virtual HRESULT __stdcall RegisterEffectFromString(GUID classId, System::WideChar * propertyXml, PD2D1PropertyBinding bindings, unsigned bindingsCount, TD2D1EffectFactoryCallback effectFactory) = 0 ;
	virtual HRESULT __stdcall UnregisterEffect(GUID classId) = 0 ;
	virtual HRESULT __stdcall GetRegisteredEffects(/* out */ System::PGUID &effects, unsigned effectsCount, /* out */ unsigned &effectsReturned, /* out */ unsigned &effectsRegistered) = 0 ;
	virtual HRESULT __stdcall GetEffectProperties(GUID effectId, /* out */ _di_ID2D1Properties &properties) = 0 ;
};

enum DECLSPEC_DENUM TD3DDriveType : unsigned int { D3D_DRIVER_TYPE_UNKNOWN, D3D_DRIVER_TYPE_HARDWARE, D3D_DRIVER_TYPE_REFERENCE, D3D_DRIVER_TYPE_NULL, D3D_DRIVER_TYPE_SOFTWARE, D3D_DRIVER_TYPE_WARP };

enum DECLSPEC_DENUM TD3DFeatureLevel : unsigned int { D3D_FEATURE_LEVEL_9_1 = 37120, D3D_FEATURE_LEVEL_9_2 = 37376, D3D_FEATURE_LEVEL_9_3 = 37632, D3D_FEATURE_LEVEL_10_0 = 40960, D3D_FEATURE_LEVEL_10_1 = 41216, D3D_FEATURE_LEVEL_11_0 = 45056, D3D_FEATURE_LEVEL_11_1 = 45312, D3D_FEATURE_LEVEL_12_0 = 49152, D3D_FEATURE_LEVEL_12_1 = 49408 };

typedef TD3DFeatureLevel *PD3DFeatureLevel;

enum DECLSPEC_DENUM TD3D11_RESOURCE_DIMENSION : unsigned int { D3D11_RESOURCE_DIMENSION_UNKNOWN, D3D11_RESOURCE_DIMENSION_BUFFER, D3D11_RESOURCE_DIMENSION_TEXTURE1D, D3D11_RESOURCE_DIMENSION_TEXTURE2D, D3D11_RESOURCE_DIMENSION_TEXTURE3D };

enum DECLSPEC_DENUM TD3D11_MAP : unsigned int { D3D11_MAP_READ = 1, D3D11_MAP_WRITE, D3D11_MAP_READ_WRITE, D3D11_MAP_WRITE_DISCARD, D3D11_MAP_WRITE_NO_OVERWRITE };

enum DECLSPEC_DENUM TD3D11_USAGE : unsigned int { D3D11_USAGE_DEFAULT, D3D11_USAGE_IMMUTABLE, D3D11_USAGE_DYNAMIC, D3D11_USAGE_STAGING };

enum DECLSPEC_DENUM TD3D_PRIMITIVE_TOPOLOGY : unsigned int { D3D_PRIMITIVE_TOPOLOGY_UNDEFINED, D3D_PRIMITIVE_TOPOLOGY_POINTLIST, D3D_PRIMITIVE_TOPOLOGY_LINELIST, D3D_PRIMITIVE_TOPOLOGY_LINESTRIP, D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST, D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP, D3D_PRIMITIVE_TOPOLOGY_LINELIST_ADJ = 10, D3D_PRIMITIVE_TOPOLOGY_LINESTRIP_ADJ, D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST_ADJ, D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP_ADJ, D3D_PRIMITIVE_TOPOLOGY_1_CONTROL_POINT_PATCHLIST = 33, D3D_PRIMITIVE_TOPOLOGY_2_CONTROL_POINT_PATCHLIST, D3D_PRIMITIVE_TOPOLOGY_3_CONTROL_POINT_PATCHLIST, D3D_PRIMITIVE_TOPOLOGY_4_CONTROL_POINT_PATCHLIST, D3D_PRIMITIVE_TOPOLOGY_5_CONTROL_POINT_PATCHLIST, D3D_PRIMITIVE_TOPOLOGY_6_CONTROL_POINT_PATCHLIST, 
	D3D_PRIMITIVE_TOPOLOGY_7_CONTROL_POINT_PATCHLIST, D3D_PRIMITIVE_TOPOLOGY_8_CONTROL_POINT_PATCHLIST, D3D_PRIMITIVE_TOPOLOGY_9_CONTROL_POINT_PATCHLIST, D3D_PRIMITIVE_TOPOLOGY_10_CONTROL_POINT_PATCHLIST, D3D_PRIMITIVE_TOPOLOGY_11_CONTROL_POINT_PATCHLIST, D3D_PRIMITIVE_TOPOLOGY_12_CONTROL_POINT_PATCHLIST, D3D_PRIMITIVE_TOPOLOGY_13_CONTROL_POINT_PATCHLIST, D3D_PRIMITIVE_TOPOLOGY_14_CONTROL_POINT_PATCHLIST, D3D_PRIMITIVE_TOPOLOGY_15_CONTROL_POINT_PATCHLIST, D3D_PRIMITIVE_TOPOLOGY_16_CONTROL_POINT_PATCHLIST, D3D_PRIMITIVE_TOPOLOGY_17_CONTROL_POINT_PATCHLIST, D3D_PRIMITIVE_TOPOLOGY_18_CONTROL_POINT_PATCHLIST, D3D_PRIMITIVE_TOPOLOGY_19_CONTROL_POINT_PATCHLIST, D3D_PRIMITIVE_TOPOLOGY_20_CONTROL_POINT_PATCHLIST, D3D_PRIMITIVE_TOPOLOGY_21_CONTROL_POINT_PATCHLIST, 
	D3D_PRIMITIVE_TOPOLOGY_22_CONTROL_POINT_PATCHLIST, D3D_PRIMITIVE_TOPOLOGY_23_CONTROL_POINT_PATCHLIST, D3D_PRIMITIVE_TOPOLOGY_24_CONTROL_POINT_PATCHLIST, D3D_PRIMITIVE_TOPOLOGY_25_CONTROL_POINT_PATCHLIST, D3D_PRIMITIVE_TOPOLOGY_26_CONTROL_POINT_PATCHLIST, D3D_PRIMITIVE_TOPOLOGY_27_CONTROL_POINT_PATCHLIST, D3D_PRIMITIVE_TOPOLOGY_28_CONTROL_POINT_PATCHLIST, D3D_PRIMITIVE_TOPOLOGY_29_CONTROL_POINT_PATCHLIST, D3D_PRIMITIVE_TOPOLOGY_30_CONTROL_POINT_PATCHLIST, D3D_PRIMITIVE_TOPOLOGY_31_CONTROL_POINT_PATCHLIST, D3D_PRIMITIVE_TOPOLOGY_32_CONTROL_POINT_PATCHLIST, D3D10_PRIMITIVE_TOPOLOGY_UNDEFINED = 0, D3D10_PRIMITIVE_TOPOLOGY_POINTLIST, D3D10_PRIMITIVE_TOPOLOGY_LINELIST, D3D10_PRIMITIVE_TOPOLOGY_LINESTRIP, D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST, 
	D3D10_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP, D3D10_PRIMITIVE_TOPOLOGY_LINELIST_ADJ = 10, D3D10_PRIMITIVE_TOPOLOGY_LINESTRIP_ADJ, D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST_ADJ, D3D10_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP_ADJ, D3D11_PRIMITIVE_TOPOLOGY_UNDEFINED = 0, D3D11_PRIMITIVE_TOPOLOGY_POINTLIST, D3D11_PRIMITIVE_TOPOLOGY_LINELIST, D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP, D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST, D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP, D3D11_PRIMITIVE_TOPOLOGY_LINELIST_ADJ = 10, D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP_ADJ, D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST_ADJ, D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP_ADJ, D3D11_PRIMITIVE_TOPOLOGY_1_CONTROL_POINT_PATCHLIST = 33, D3D11_PRIMITIVE_TOPOLOGY_2_CONTROL_POINT_PATCHLIST, D3D11_PRIMITIVE_TOPOLOGY_3_CONTROL_POINT_PATCHLIST, 
	D3D11_PRIMITIVE_TOPOLOGY_4_CONTROL_POINT_PATCHLIST, D3D11_PRIMITIVE_TOPOLOGY_5_CONTROL_POINT_PATCHLIST, D3D11_PRIMITIVE_TOPOLOGY_6_CONTROL_POINT_PATCHLIST, D3D11_PRIMITIVE_TOPOLOGY_7_CONTROL_POINT_PATCHLIST, D3D11_PRIMITIVE_TOPOLOGY_8_CONTROL_POINT_PATCHLIST, D3D11_PRIMITIVE_TOPOLOGY_9_CONTROL_POINT_PATCHLIST, D3D11_PRIMITIVE_TOPOLOGY_10_CONTROL_POINT_PATCHLIST, D3D11_PRIMITIVE_TOPOLOGY_11_CONTROL_POINT_PATCHLIST, D3D11_PRIMITIVE_TOPOLOGY_12_CONTROL_POINT_PATCHLIST, D3D11_PRIMITIVE_TOPOLOGY_13_CONTROL_POINT_PATCHLIST, D3D11_PRIMITIVE_TOPOLOGY_14_CONTROL_POINT_PATCHLIST, D3D11_PRIMITIVE_TOPOLOGY_15_CONTROL_POINT_PATCHLIST, D3D11_PRIMITIVE_TOPOLOGY_16_CONTROL_POINT_PATCHLIST, D3D11_PRIMITIVE_TOPOLOGY_17_CONTROL_POINT_PATCHLIST, 
	D3D11_PRIMITIVE_TOPOLOGY_18_CONTROL_POINT_PATCHLIST, D3D11_PRIMITIVE_TOPOLOGY_19_CONTROL_POINT_PATCHLIST, D3D11_PRIMITIVE_TOPOLOGY_20_CONTROL_POINT_PATCHLIST, D3D11_PRIMITIVE_TOPOLOGY_21_CONTROL_POINT_PATCHLIST, D3D11_PRIMITIVE_TOPOLOGY_22_CONTROL_POINT_PATCHLIST, D3D11_PRIMITIVE_TOPOLOGY_23_CONTROL_POINT_PATCHLIST, D3D11_PRIMITIVE_TOPOLOGY_24_CONTROL_POINT_PATCHLIST, D3D11_PRIMITIVE_TOPOLOGY_25_CONTROL_POINT_PATCHLIST, D3D11_PRIMITIVE_TOPOLOGY_26_CONTROL_POINT_PATCHLIST, D3D11_PRIMITIVE_TOPOLOGY_27_CONTROL_POINT_PATCHLIST, D3D11_PRIMITIVE_TOPOLOGY_28_CONTROL_POINT_PATCHLIST, D3D11_PRIMITIVE_TOPOLOGY_29_CONTROL_POINT_PATCHLIST, D3D11_PRIMITIVE_TOPOLOGY_30_CONTROL_POINT_PATCHLIST, D3D11_PRIMITIVE_TOPOLOGY_31_CONTROL_POINT_PATCHLIST, 
	D3D11_PRIMITIVE_TOPOLOGY_32_CONTROL_POINT_PATCHLIST };

enum DECLSPEC_DENUM TD3D11_DEVICE_CONTEXT_TYPE : unsigned int { D3D11_DEVICE_CONTEXT_IMMEDIATE, D3D11_DEVICE_CONTEXT_DEFERRED };

typedef void * PD3D11ViewPort;

typedef void * PD3D11Rect;

typedef void * PID3D11ClassInstance;

typedef void * PID3D11RenderTargetView;

typedef void * PID3D11SamplerState;

typedef void * PD3D11SubResourceData;

typedef System::_di_IInterface ID3D11SamplerState;

typedef System::_di_IInterface ID3D11ShaderResourceView;

typedef System::_di_IInterface *PID3D11ShaderResourceView;

typedef System::_di_IInterface ID3D11DepthStencilView;

typedef System::_di_IInterface ID3D11UnorderedAccessView;

typedef System::_di_IInterface *PID3D11UnorderedAccessView;

typedef System::StaticArray<unsigned, 4> TUINTArray4;

typedef System::StaticArray<float, 4> TFloatArray4;

typedef System::StaticArray<float, 3> TFloatArray3;

typedef System::StaticArray<float, 2> TFloatArray2;

typedef TFloatArray4 *PFloatArray4;

typedef TFloatArray3 *PFloatArray3;

typedef TFloatArray2 *PFloatArray2;

typedef TD3D11MappedSubResource *PD3D11MappedSubResource;

struct DECLSPEC_DRECORD TD3D11MappedSubResource
{
public:
	void *pData;
	unsigned RowPitch;
	unsigned DepthPitch;
};


typedef TD3D11Box *PD3D11Box;

struct DECLSPEC_DRECORD TD3D11Box
{
public:
	unsigned left;
	unsigned top;
	unsigned front;
	unsigned right;
	unsigned bottom;
	unsigned back;
	static TD3D11Box __fastcall Create(const int ALeft, const int ATop, const int ARight, const int ABottom, int AFront = 0x0, int ABack = 0x1)/* overload */;
	static TD3D11Box __fastcall Create(const System::Types::TRect &ARect)/* overload */;
	static System::LongBool __fastcall _op_Equality(const TD3D11Box &A, const TD3D11Box &B);
	static System::LongBool __fastcall _op_Inequality(const TD3D11Box &A, const TD3D11Box &B);
	
	friend System::LongBool operator ==(const TD3D11Box &A, const TD3D11Box &B) { return TD3D11Box::_op_Equality(A, B); }
	friend System::LongBool operator !=(const TD3D11Box &A, const TD3D11Box &B) { return TD3D11Box::_op_Inequality(A, B); }
};


__interface  INTERFACE_UUID("{1841E5C8-16B0-489B-BCC8-44CFB0D5DEAE}") ID3D11DeviceChild  : public System::IInterface 
{
	virtual void __stdcall GetDevice(/* out */ _di_ID3D11Device &ppDevice) = 0 ;
	virtual HRESULT __stdcall GetPrivateData(GUID guid, unsigned &pDataSize, /* out */ void * &pData) = 0 ;
	virtual HRESULT __stdcall SetPrivateData(GUID guid, unsigned DataSize, void * pData) = 0 ;
	virtual HRESULT __stdcall SetPrivateDataInterface(GUID guid, System::_di_IInterface pData) = 0 ;
};

__interface  INTERFACE_UUID("{EA82E40D-51DC-4F33-93D4-DB7C9125AE8C}") ID3D11PixelShader  : public ID3D11DeviceChild 
{
	
};

__interface  INTERFACE_UUID("{3B301D64-D678-4289-8897-22F8928B72F3}") ID3D11VertexShader  : public ID3D11DeviceChild 
{
	
};

typedef _di_ID3D11Resource *PID3D11Resource;

__interface  INTERFACE_UUID("{DC8E63F3-D12B-4952-B47B-5E45026A862D}") ID3D11Resource  : public ID3D11DeviceChild 
{
	virtual void __stdcall GetType(/* out */ TD3D11_RESOURCE_DIMENSION &pResourceDimension) = 0 ;
	virtual void __stdcall SetEvictionPriority(unsigned EvictionPriority) = 0 ;
	virtual unsigned __stdcall GetEvictionPriority() = 0 ;
};

typedef TD3D11BufferDesc *PD3D11BufferDesc;

struct DECLSPEC_DRECORD TD3D11BufferDesc
{
public:
	unsigned ByteWidth;
	TD3D11_USAGE Usage;
	unsigned BindFlags;
	unsigned CPUAccessFlags;
	unsigned MiscFlags;
	unsigned StructureByteStride;
	void __fastcall Init(unsigned AByteWidth, unsigned ABindFlags, TD3D11_USAGE AUsage = (TD3D11_USAGE)(0x0), unsigned ACPUAccessFlags = (unsigned)(0x0), unsigned AMiscFlags = (unsigned)(0x0), unsigned AStructureByteStride = (unsigned)(0x0));
};


struct DECLSPEC_DRECORD TD3D11Texture2DDesc
{
public:
	unsigned Width;
	unsigned Height;
	unsigned MipLevels;
	unsigned ArraySize;
	DXGI_FORMAT Format;
	TDXGISampleDesc SampleDesc;
	TD3D11_USAGE Usage;
	unsigned BindFlags;
	unsigned CPUAccessFlags;
	unsigned MiscFlags;
};


typedef _di_ID3D11Buffer *PID3D11Buffer;

__interface  INTERFACE_UUID("{48570B85-D1EE-4FCD-A250-EB350722B037}") ID3D11Buffer  : public ID3D11Resource 
{
	virtual void __stdcall GetDesc(/* out */ TD3D11BufferDesc &pDesc) = 0 ;
};

__interface  INTERFACE_UUID("{6F15AAF2-D208-4E89-9AB4-489535D34F9C}") ID3D11Texture2D  : public ID3D11Resource 
{
	virtual void __stdcall GetDesc(/* out */ TD3D11Texture2DDesc &pDesc) = 0 ;
};

__interface  INTERFACE_UUID("{E4819DDC-4CF0-4025-BD26-5DE82A3E07B7}") ID3D11InputLayout  : public ID3D11DeviceChild 
{
	
};

__interface  INTERFACE_UUID("{38325B96-EFFB-4022-BA02-2E795B70275C}") ID3D11GeometryShader  : public ID3D11DeviceChild 
{
	
};

__interface  INTERFACE_UUID("{4B35D0CD-1E15-4258-9C98-1B1333F6DD3B}") ID3D11Asynchronous  : public ID3D11DeviceChild 
{
	virtual unsigned __stdcall GetDataSize() = 0 ;
};

__interface  INTERFACE_UUID("{75B68FAA-347D-4159-8F45-A0640F01CD9A}") ID3D11BlendState  : public ID3D11DeviceChild 
{
	
};

__interface  INTERFACE_UUID("{A24BC4D1-769E-43F7-8013-98FF566C18E2}") ID3D11CommandList  : public ID3D11DeviceChild 
{
	virtual unsigned __stdcall GetContextFlags() = 0 ;
};

__interface  INTERFACE_UUID("{8E5C6061-628A-4C8E-8264-BBE45CB3D5DD}") ID3D11HullShader  : public ID3D11DeviceChild 
{
	
};

__interface  INTERFACE_UUID("{F582C508-0F36-490C-9977-31EECE268CFA}") ID3D11DomainShader  : public ID3D11DeviceChild 
{
	
};

__interface  INTERFACE_UUID("{4F5B196E-C2BD-495E-BD01-1FDED38E4969}") ID3D11ComputeShader  : public ID3D11DeviceChild 
{
	
};

__interface  INTERFACE_UUID("{DB6F6DDB-AC77-4E88-8253-819DF9BBF140}") ID3D11Device  : public System::IInterface 
{
	virtual HRESULT __stdcall CreateBuffer(const TD3D11BufferDesc &pDesc, void * pInitialData, /* out */ _di_ID3D11Buffer &ppBuffer) = 0 ;
	virtual HRESULT __stdcall CreateTexture1D(void * pDesc, void * pInitialData, /* out */ System::_di_IInterface &ppTexture1D) = 0 ;
	virtual HRESULT __stdcall CreateTexture2D(const TD3D11Texture2DDesc &pDesc, void * pInitialData, /* out */ _di_ID3D11Texture2D &ppTexture2D) = 0 ;
};

__interface  INTERFACE_UUID("{C0BFA96C-E089-44FB-8EAF-26F8796190DA}") ID3D11DeviceContext  : public ID3D11DeviceChild 
{
	virtual void __stdcall VSSetConstantBuffers(unsigned StartSlot, unsigned NumBuffers, PID3D11Buffer ppConstantBuffers) = 0 ;
	virtual void __stdcall PSSetShaderResources(unsigned StartSlot, unsigned NumViews, PID3D11ShaderResourceView ppShaderResourceViews) = 0 ;
	virtual void __stdcall PSSetShader(_di_ID3D11PixelShader pPixelShader, void * ppClassInstances, unsigned NumClassInstances) = 0 ;
	virtual void __stdcall PSSetSamplers(unsigned StartSlot, unsigned NumSamplers, void * ppSamplers) = 0 ;
	virtual void __stdcall VSSetShader(_di_ID3D11VertexShader pVertexShader, void * ppClassInstances, unsigned NumClassInstances) = 0 ;
	virtual void __stdcall DrawIndexed(unsigned IndexCount, unsigned StartIndexLocation, int BaseVertexLocation) = 0 ;
	virtual void __stdcall Draw(unsigned VertexCount, unsigned StartVertexLocation) = 0 ;
	virtual HRESULT __stdcall Map(_di_ID3D11Resource pResource, unsigned Subresource, TD3D11_MAP MapType, unsigned MapFlags, /* out */ TD3D11MappedSubResource &pMappedResource) = 0 ;
	virtual void __stdcall Unmap(_di_ID3D11Resource pResource, unsigned Subresource) = 0 ;
	virtual void __stdcall PSSetConstantBuffers(unsigned StartSlot, unsigned NumBuffers, PID3D11Buffer ppConstantBuffers) = 0 ;
	virtual void __stdcall IASetInputLayout(_di_ID3D11InputLayout pInputLayout) = 0 ;
	virtual void __stdcall IASetVertexBuffers(unsigned StartSlot, unsigned NumBuffers, PID3D11Buffer ppVertexBuffers, PUINT pStrides, PUINT pOffsets) = 0 ;
	virtual void __stdcall IASetIndexBuffer(_di_ID3D11Buffer pIndexBuffer, DXGI_FORMAT Format, unsigned Offset) = 0 ;
	virtual void __stdcall DrawIndexedInstanced(unsigned IndexCountPerInstance, unsigned InstanceCount, unsigned StartIndexLocation, int BaseVertexLocation, unsigned StartInstanceLocation) = 0 ;
	virtual void __stdcall DrawInstanced(unsigned VertexCountPerInstance, unsigned InstanceCount, unsigned StartVertexLocation, unsigned StartInstanceLocation) = 0 ;
	virtual void __stdcall GSSetConstantBuffers(unsigned StartSlot, unsigned NumBuffers, PID3D11Buffer ppConstantBuffers) = 0 ;
	virtual void __stdcall GSSetShader(_di_ID3D11GeometryShader pShader, void * ppClassInstances, unsigned NumClassInstances) = 0 ;
	virtual void __stdcall IASetPrimitiveTopology(TD3D_PRIMITIVE_TOPOLOGY Topology) = 0 ;
	virtual void __stdcall VSSetShaderResources(unsigned StartSlot, unsigned NumViews, PID3D11ShaderResourceView ppShaderResourceViews) = 0 ;
	virtual void __stdcall VSSetSamplers(unsigned StartSlot, unsigned NumSamplers, void * ppSamplers) = 0 ;
	virtual void __stdcall _Begin(_di_ID3D11Asynchronous pAsync) = 0 ;
	virtual void __stdcall _End(_di_ID3D11Asynchronous pAsync) = 0 ;
	virtual HRESULT __stdcall GetData(_di_ID3D11Asynchronous pAsync, /* out */ void * &pData, unsigned DataSize, unsigned GetDataFlags) = 0 ;
	virtual void __stdcall SetPredication(System::_di_IInterface pPredicate, System::LongBool PredicateValue) = 0 ;
	virtual void __stdcall GSSetShaderResources(unsigned StartSlot, unsigned NumViews, PID3D11ShaderResourceView ppShaderResourceViews) = 0 ;
	virtual void __stdcall GSSetSamplers(unsigned StartSlot, unsigned NumSamplers, void * ppSamplers) = 0 ;
	virtual void __stdcall OMSetRenderTargets(unsigned NumViews, void * ppRenderTargetViews, System::_di_IInterface pDepthStencilView) = 0 ;
	virtual void __stdcall OMSetRenderTargetsAndUnorderedAccessViews(unsigned NumRTVs, void * ppRenderTargetViews, System::_di_IInterface pDepthStencilView, unsigned UAVStartSlot, unsigned NumUAVs, PID3D11UnorderedAccessView ppUnorderedAccessViews, PUINT pUAVInitialCounts) = 0 ;
	virtual void __stdcall OMSetBlendState(_di_ID3D11BlendState pBlendState, const TFloatArray4 &BlendFactor, unsigned SampleMask) = 0 ;
	virtual void __stdcall OMSetDepthStencilState(System::_di_IInterface pDepthStencilState, unsigned StencilRef) = 0 ;
	virtual void __stdcall SOSetTargets(unsigned NumBuffers, PID3D11Buffer ppSOTargets, PUINT pOffsets) = 0 ;
	virtual void __stdcall DrawAuto() = 0 ;
	virtual void __stdcall DrawIndexedInstancedIndirect(_di_ID3D11Buffer pBufferForArgs, unsigned AlignedByteOffsetForArgs) = 0 ;
	virtual void __stdcall DrawInstancedIndirect(_di_ID3D11Buffer pBufferForArgs, unsigned AlignedByteOffsetForArgs) = 0 ;
	virtual void __stdcall Dispatch(unsigned ThreadGroupCountX, unsigned ThreadGroupCountY, unsigned ThreadGroupCountZ) = 0 ;
	virtual void __stdcall DispatchIndirect(_di_ID3D11Buffer pBufferForArgs, unsigned AlignedByteOffsetForArgs) = 0 ;
	virtual void __stdcall RSSetState(System::_di_IInterface pRasterizerState) = 0 ;
	virtual void __stdcall RSSetViewports(unsigned NumViewports, void * pViewports) = 0 ;
	virtual void __stdcall RSSetScissorRects(unsigned NumRects, void * pRects) = 0 ;
	virtual void __stdcall CopySubresourceRegion(_di_ID3D11Resource pDstResource, unsigned DstSubresource, unsigned DstX, unsigned DstY, unsigned DstZ, _di_ID3D11Resource pSrcResource, unsigned SrcSubresource, PD3D11Box pSrcBox) = 0 ;
	virtual void __stdcall CopyResource(_di_ID3D11Resource pDstResource, _di_ID3D11Resource pSrcResource) = 0 ;
	virtual void __stdcall UpdateSubresource(_di_ID3D11Resource pDstResource, unsigned DstSubresource, PD3D11Box pDstBox, void * pSrcData, unsigned SrcRowPitch, unsigned SrcDepthPitch) = 0 ;
	virtual void __stdcall CopyStructureCount(_di_ID3D11Buffer pDstBuffer, unsigned DstAlignedByteOffset, System::_di_IInterface pSrcView) = 0 ;
	virtual void __stdcall ClearRenderTargetView(System::_di_IInterface pRenderTargetView, const TFloatArray4 &ColorRGBA) = 0 ;
	virtual void __stdcall ClearUnorderedAccessViewUINT(System::_di_IInterface pUnorderedAccessView, const TUINTArray4 &Values) = 0 ;
	virtual void __stdcall ClearUnorderedAccessViewFloat(System::_di_IInterface pUnorderedAccessView, const TFloatArray4 &Values) = 0 ;
	virtual void __stdcall ClearDepthStencilView(System::_di_IInterface pDepthStencilView, unsigned ClearFlags, float Depth, System::Byte Stencil) = 0 ;
	virtual void __stdcall GenerateMips(System::_di_IInterface pShaderResourceView) = 0 ;
	virtual void __stdcall SetResourceMinLOD(_di_ID3D11Resource pResource, float MinLOD) = 0 ;
	virtual float __stdcall GetResourceMinLOD(_di_ID3D11Resource pResource) = 0 ;
	virtual void __stdcall ResolveSubresource(_di_ID3D11Resource pDstResource, unsigned DstSubresource, _di_ID3D11Resource pSrcResource, unsigned SrcSubresource, DXGI_FORMAT Format) = 0 ;
	virtual void __stdcall ExecuteCommandList(_di_ID3D11CommandList pCommandList, System::LongBool RestoreContextState) = 0 ;
	virtual void __stdcall HSSetShaderResources(unsigned StartSlot, unsigned NumViews, PID3D11ShaderResourceView ppShaderResourceViews) = 0 ;
	virtual void __stdcall HSSetShader(_di_ID3D11HullShader pHullShader, void * ppClassInstances, unsigned NumClassInstances) = 0 ;
	virtual void __stdcall HSSetSamplers(unsigned StartSlot, unsigned NumSamplers, void * ppSamplers) = 0 ;
	virtual void __stdcall HSSetConstantBuffers(unsigned StartSlot, unsigned NumBuffers, PID3D11Buffer ppConstantBuffers) = 0 ;
	virtual void __stdcall DSSetShaderResources(unsigned StartSlot, unsigned NumViews, PID3D11ShaderResourceView ppShaderResourceViews) = 0 ;
	virtual void __stdcall DSSetShader(_di_ID3D11DomainShader pDomainShader, void * ppClassInstances, unsigned NumClassInstances) = 0 ;
	virtual void __stdcall DSSetSamplers(unsigned StartSlot, unsigned NumSamplers, System::_di_IInterface ppSamplers) = 0 ;
	virtual void __stdcall DSSetConstantBuffers(unsigned StartSlot, unsigned NumBuffers, PID3D11Buffer ppConstantBuffers) = 0 ;
	virtual void __stdcall CSSetShaderResources(unsigned StartSlot, unsigned NumViews, System::_di_IInterface ppShaderResourceViews) = 0 ;
	virtual void __stdcall CSSetUnorderedAccessViews(unsigned StartSlot, unsigned NumUAVs, PID3D11UnorderedAccessView ppUnorderedAccessViews, PUINT pUAVInitialCounts) = 0 ;
	virtual void __stdcall CSSetShader(_di_ID3D11ComputeShader pComputeShader, void * ppClassInstances, unsigned NumClassInstances) = 0 ;
	virtual void __stdcall CSSetSamplers(unsigned StartSlot, unsigned NumSamplers, void * ppSamplers) = 0 ;
	virtual void __stdcall CSSetConstantBuffers(unsigned StartSlot, unsigned NumBuffers, PID3D11Buffer ppConstantBuffers) = 0 ;
	virtual void __stdcall VSGetConstantBuffers(unsigned StartSlot, unsigned NumBuffers, /* out */ PID3D11Buffer &ppConstantBuffers) = 0 ;
	virtual void __stdcall PSGetShaderResources(unsigned StartSlot, unsigned NumViews, /* out */ PID3D11ShaderResourceView &ppShaderResourceViews) = 0 ;
	virtual void __stdcall PSGetShader(/* out */ _di_ID3D11PixelShader &ppPixelShader, /* out */ void * &ppClassInstances, unsigned &pNumClassInstances) = 0 ;
	virtual void __stdcall PSGetSamplers(unsigned StartSlot, unsigned NumSamplers, /* out */ void * &ppSamplers) = 0 ;
	virtual void __stdcall VSGetShader(/* out */ _di_ID3D11VertexShader &ppVertexShader, /* out */ void * &ppClassInstances, unsigned &pNumClassInstances) = 0 ;
	virtual void __stdcall PSGetConstantBuffers(unsigned StartSlot, unsigned NumBuffers, /* out */ PID3D11Buffer &ppConstantBuffers) = 0 ;
	virtual void __stdcall IAGetInputLayout(/* out */ _di_ID3D11InputLayout &ppInputLayout) = 0 ;
	virtual void __stdcall IAGetVertexBuffers(unsigned StartSlot, unsigned NumBuffers, /* out */ PID3D11Buffer &ppVertexBuffers, /* out */ PUINT &pStrides, /* out */ PUINT &pOffsets) = 0 ;
	virtual void __stdcall IAGetIndexBuffer(/* out */ _di_ID3D11Buffer &pIndexBuffer, /* out */ DXGI_FORMAT &Format, /* out */ unsigned &Offset) = 0 ;
	virtual void __stdcall GSGetConstantBuffers(unsigned StartSlot, unsigned NumBuffers, /* out */ PID3D11Buffer &ppConstantBuffers) = 0 ;
	virtual void __stdcall GSGetShader(/* out */ _di_ID3D11GeometryShader &ppGeometryShader, /* out */ void * &ppClassInstances, unsigned &pNumClassInstances) = 0 ;
	virtual void __stdcall IAGetPrimitiveTopology(/* out */ TD3D_PRIMITIVE_TOPOLOGY &pTopology) = 0 ;
	virtual void __stdcall VSGetShaderResources(unsigned StartSlot, unsigned NumViews, /* out */ PID3D11ShaderResourceView &ppShaderResourceViews) = 0 ;
	virtual void __stdcall VSGetSamplers(unsigned StartSlot, unsigned NumSamplers, /* out */ void * &ppSamplers) = 0 ;
	virtual void __stdcall GetPredication(/* out */ System::_di_IInterface &ppPredicate, /* out */ System::LongBool &pPredicateValue) = 0 ;
	virtual void __stdcall GSGetShaderResources(unsigned StartSlot, unsigned NumViews, /* out */ PID3D11ShaderResourceView &ppShaderResourceViews) = 0 ;
	virtual void __stdcall GSGetSamplers(unsigned StartSlot, unsigned NumSamplers, /* out */ void * &ppSamplers) = 0 ;
	virtual void __stdcall OMGetRenderTargets(unsigned NumViews, /* out */ void * &ppRenderTargetViews, /* out */ System::_di_IInterface &ppDepthStencilView) = 0 ;
	virtual void __stdcall OMGetRenderTargetsAndUnorderedAccessViews(unsigned NumRTVs, /* out */ void * &ppRenderTargetViews, /* out */ System::_di_IInterface &ppDepthStencilView, unsigned UAVStartSlot, unsigned NumUAVs, /* out */ PID3D11UnorderedAccessView &ppUnorderedAccessViews) = 0 ;
	virtual void __stdcall OMGetBlendState(/* out */ _di_ID3D11BlendState &ppBlendState, /* out */ TFloatArray4 &BlendFactor, /* out */ unsigned &pSampleMask) = 0 ;
	virtual void __stdcall OMGetDepthStencilState(/* out */ System::_di_IInterface &ppDepthStencilState, /* out */ unsigned &pStencilRef) = 0 ;
	virtual void __stdcall SOGetTargets(unsigned NumBuffers, /* out */ PID3D11Buffer &ppSOTargets) = 0 ;
	virtual void __stdcall RSGetState(/* out */ System::_di_IInterface &ppRasterizerState) = 0 ;
	virtual void __stdcall RSGetViewports(unsigned &pNumViewports, /* out */ void * &pViewports) = 0 ;
	virtual void __stdcall RSGetScissorRects(unsigned &pNumRects, /* out */ void * &pRects) = 0 ;
	virtual void __stdcall HSGetShaderResources(unsigned StartSlot, unsigned NumViews, /* out */ PID3D11ShaderResourceView &ppShaderResourceViews) = 0 ;
	virtual void __stdcall HSGetShader(/* out */ _di_ID3D11HullShader &ppHullShader, /* out */ void * &ppClassInstances, unsigned &pNumClassInstances) = 0 ;
	virtual void __stdcall HSGetSamplers(unsigned StartSlot, unsigned NumSamplers, /* out */ void * &ppSamplers) = 0 ;
	virtual void __stdcall HSGetConstantBuffers(unsigned StartSlot, unsigned NumBuffers, /* out */ PID3D11Buffer &ppConstantBuffers) = 0 ;
	virtual void __stdcall DSGetShaderResources(unsigned StartSlot, unsigned NumViews, /* out */ PID3D11ShaderResourceView &ppShaderResourceViews) = 0 ;
	virtual void __stdcall DSGetShader(/* out */ _di_ID3D11DomainShader &ppDomainShader, /* out */ void * &ppClassInstances, unsigned &pNumClassInstances) = 0 ;
	virtual void __stdcall DSGetSamplers(unsigned StartSlot, unsigned NumSamplers, /* out */ void * &ppSamplers) = 0 ;
	virtual void __stdcall DSGetConstantBuffers(unsigned StartSlot, unsigned NumBuffers, /* out */ PID3D11Buffer &ppConstantBuffers) = 0 ;
	virtual void __stdcall CSGetShaderResources(unsigned StartSlot, unsigned NumViews, /* out */ PID3D11ShaderResourceView &ppShaderResourceViews) = 0 ;
	virtual void __stdcall CSGetUnorderedAccessViews(unsigned StartSlot, unsigned NumUAVs, /* out */ PID3D11UnorderedAccessView &ppUnorderedAccessViews) = 0 ;
	virtual void __stdcall CSGetShader(/* out */ _di_ID3D11ComputeShader &ppComputeShader, /* out */ void * &ppClassInstances, unsigned &pNumClassInstances) = 0 ;
	virtual void __stdcall CSGetSamplers(unsigned StartSlot, unsigned NumSamplers, /* out */ void * &ppSamplers) = 0 ;
	virtual void __stdcall CSGetConstantBuffers(unsigned StartSlot, unsigned NumBuffers, /* out */ PID3D11Buffer &ppConstantBuffers) = 0 ;
	virtual void __stdcall ClearState() = 0 ;
	virtual void __stdcall Flush() = 0 ;
	virtual TD3D11_DEVICE_CONTEXT_TYPE __stdcall GetType() = 0 ;
	virtual unsigned __stdcall GetContextFlags() = 0 ;
	virtual HRESULT __stdcall FinishCommandList(System::LongBool RestoreDeferredContextState, /* out */ _di_ID3D11CommandList &ppCommandList) = 0 ;
};

typedef int TDCompositionBackfaceVisibility;

typedef int TDCompositionBitmapInterpolation;

typedef int TDCompositionBorderMode;

typedef int TDCompositionCompositeMode;

typedef int TDCompositionOpacityMode;

typedef TDCompositionFrameStatistics *PDCompositionFrameStatistics;

struct DECLSPEC_DRECORD TDCompositionFrameStatistics
{
public:
	__int64 lastFrameTime;
	TDXGIRational currentCompositionRate;
	__int64 currentTime;
	__int64 timeFrequency;
	__int64 nextEstimatedFrameTime;
};


__interface  INTERFACE_UUID("{EC81B08F-BFCB-4E8D-B193-A915587999E8}") IDCompositionEffect  : public System::IInterface 
{
	
};

__interface  INTERFACE_UUID("{4D93059D-097B-4651-9A60-F0F25116E2F3}") IDCompositionVisual  : public System::IInterface 
{
	virtual HRESULT __stdcall SetOffsetX(System::_di_IInterface animation) = 0 /* overload */;
	virtual HRESULT __stdcall SetOffsetX(float offsetX) = 0 /* overload */;
	virtual HRESULT __stdcall SetOffsetY(System::_di_IInterface animation) = 0 /* overload */;
	virtual HRESULT __stdcall SetOffsetY(float offsetY) = 0 /* overload */;
	virtual HRESULT __stdcall SetTransform(const D2D_MATRIX_3X2_F &matrix) = 0 ;
	virtual HRESULT __stdcall _SetTransform(System::_di_IInterface transform) = 0 ;
	virtual HRESULT __stdcall SetTransformParent(_di_IDCompositionVisual visual) = 0 ;
	virtual HRESULT __stdcall SetEffect(_di_IDCompositionEffect effect) = 0 ;
	virtual HRESULT __stdcall SetBitmapInterpolationMode(TDCompositionBitmapInterpolation interpolationMode) = 0 ;
	virtual HRESULT __stdcall SetBorderMode(TDCompositionBorderMode borderMode) = 0 ;
	virtual HRESULT __stdcall SetClip(const D2D_RECT_F &rect) = 0 ;
	virtual HRESULT __stdcall _SetClip(System::_di_IInterface clip) = 0 ;
	virtual HRESULT __stdcall SetContent(System::_di_IInterface content) = 0 ;
	virtual HRESULT __stdcall AddVisual(_di_IDCompositionVisual visual, bool insertAbove, _di_IDCompositionVisual referenceVisual) = 0 ;
	virtual HRESULT __stdcall RemoveVisual(_di_IDCompositionVisual visual) = 0 ;
	virtual HRESULT __stdcall RemoveAllVisuals() = 0 ;
	virtual HRESULT __stdcall SetCompositeMode(TDCompositionCompositeMode compositeMode) = 0 ;
};

__interface  INTERFACE_UUID("{EACDD04C-117E-4E17-88F4-D1B12B0E3D89}") IDCompositionTarget  : public System::IInterface 
{
	virtual HRESULT __stdcall SetRoot(_di_IDCompositionVisual visual) = 0 ;
};

__interface  INTERFACE_UUID("{E8DE1639-4331-4B26-BC5F-6A321D347A85}") IDCompositionVisual2  : public IDCompositionVisual 
{
	virtual HRESULT __stdcall SetOpacityMode(TDCompositionOpacityMode mode) = 0 ;
	virtual HRESULT __stdcall SetBackFaceVisibility(TDCompositionBackfaceVisibility visibility) = 0 ;
};

__interface  INTERFACE_UUID("{C37EA93A-E7AA-450D-B16F-9746CB0407F3}") IDCompositionDevice  : public System::IInterface 
{
	virtual HRESULT __stdcall Commit() = 0 ;
	virtual HRESULT __stdcall WaitForCommitCompletion() = 0 ;
	virtual HRESULT __stdcall GetFrameStatistics(/* out */ TDCompositionFrameStatistics &statistics) = 0 ;
	virtual HRESULT __stdcall CreateTargetForHwnd(HWND hwnd, bool topmost, /* out */ _di_IDCompositionTarget &target) = 0 ;
	virtual HRESULT __stdcall CreateVisual(/* out */ _di_IDCompositionVisual &visual) = 0 ;
	virtual HRESULT __stdcall CreateSurface(unsigned Width, unsigned Height, DXGI_FORMAT pixelFormat, TDXGIAlphaMode alphaMode, /* out */ System::_di_IInterface &surface) = 0 ;
	virtual HRESULT __stdcall CreateVirtualSurface(unsigned initialWidth, unsigned initialHeight, DXGI_FORMAT pixelFormat, TDXGIAlphaMode alphaMode, /* out */ System::_di_IInterface &virtualSurface) = 0 ;
	virtual HRESULT __stdcall CreateSurfaceFromHandle(NativeUInt handle, /* out */ System::_di_IInterface &surface) = 0 ;
	virtual HRESULT __stdcall CreateSurfaceFromHwnd(HWND hwnd, /* out */ System::_di_IInterface &surface) = 0 ;
	virtual HRESULT __stdcall CreateTranslateTransform(/* out */ System::_di_IInterface &translateTransform) = 0 ;
	virtual HRESULT __stdcall CreateScaleTransform(/* out */ System::_di_IInterface &scaleTransform) = 0 ;
	virtual HRESULT __stdcall CreateRotateTransform(/* out */ System::_di_IInterface &rotateTransform) = 0 ;
	virtual HRESULT __stdcall CreateSkewTransform(/* out */ System::_di_IInterface &skewTransform) = 0 ;
	virtual HRESULT __stdcall CreateMatrixTransform(/* out */ System::_di_IInterface &matrixTransform) = 0 ;
	virtual HRESULT __stdcall CreateTransformGroup(void * transforms, unsigned elements, /* out */ System::_di_IInterface &transformGroup) = 0 ;
	virtual HRESULT __stdcall CreateTranslateTransform3D(/* out */ System::_di_IInterface &translateTransform3D) = 0 ;
	virtual HRESULT __stdcall CreateScaleTransform3D(/* out */ System::_di_IInterface &scaleTransform3D) = 0 ;
	virtual HRESULT __stdcall CreateRotateTransform3D(/* out */ System::_di_IInterface &rotateTransform3D) = 0 ;
	virtual HRESULT __stdcall CreateMatrixTransform3D(/* out */ System::_di_IInterface &matrixTransform3D) = 0 ;
	virtual HRESULT __stdcall CreateTransform3DGroup(void * transforms3D, unsigned elements, /* out */ System::_di_IInterface &transform3DGroup) = 0 ;
	virtual HRESULT __stdcall CreateEffectGroup(/* out */ System::_di_IInterface &effectGroup) = 0 ;
	virtual HRESULT __stdcall CreateRectangleClip(/* out */ System::_di_IInterface &clip) = 0 ;
	virtual HRESULT __stdcall CreateAnimation(/* out */ System::_di_IInterface &animation) = 0 ;
	virtual HRESULT __stdcall CheckDeviceState(/* out */ bool &pfValid) = 0 ;
};

__interface  INTERFACE_UUID("{75F6468D-1B8E-447C-9BC6-75FEA80B5B25}") IDCompositionDevice2  : public System::IInterface 
{
	virtual HRESULT __stdcall Commit() = 0 ;
	virtual HRESULT __stdcall WaitForCommitCompletion() = 0 ;
	virtual HRESULT __stdcall GetFrameStatistics(/* out */ TDCompositionFrameStatistics &statistics) = 0 ;
	virtual HRESULT __stdcall CreateVisual(/* out */ _di_IDCompositionVisual2 &visual) = 0 ;
	virtual HRESULT __stdcall CreateSurfaceFactory(System::_di_IInterface renderingDevice, /* out */ System::_di_IInterface &surfaceFactory) = 0 ;
	virtual HRESULT __stdcall CreateSurface(unsigned Width, unsigned Height, DXGI_FORMAT pixelFormat, TDXGIAlphaMode alphaMode, /* out */ System::_di_IInterface &surface) = 0 ;
	virtual HRESULT __stdcall CreateVirtualSurface(unsigned initialWidth, unsigned initialHeight, DXGI_FORMAT pixelFormat, TDXGIAlphaMode alphaMode, /* out */ System::_di_IInterface &virtualSurface) = 0 ;
	virtual HRESULT __stdcall CreateTranslateTransform(/* out */ System::_di_IInterface &translateTransform) = 0 ;
	virtual HRESULT __stdcall CreateScaleTransform(/* out */ System::_di_IInterface &scaleTransform) = 0 ;
	virtual HRESULT __stdcall CreateRotateTransform(/* out */ System::_di_IInterface &rotateTransform) = 0 ;
	virtual HRESULT __stdcall CreateSkewTransform(/* out */ System::_di_IInterface &skewTransform) = 0 ;
	virtual HRESULT __stdcall CreateMatrixTransform(/* out */ System::_di_IInterface &matrixTransform) = 0 ;
	virtual HRESULT __stdcall CreateTransformGroup(void * transforms, unsigned elements, /* out */ System::_di_IInterface &transformGroup) = 0 ;
	virtual HRESULT __stdcall CreateTranslateTransform3D(/* out */ System::_di_IInterface &translateTransform3D) = 0 ;
	virtual HRESULT __stdcall CreateScaleTransform3D(/* out */ System::_di_IInterface &scaleTransform3D) = 0 ;
	virtual HRESULT __stdcall CreateRotateTransform3D(/* out */ System::_di_IInterface &rotateTransform3D) = 0 ;
	virtual HRESULT __stdcall CreateMatrixTransform3D(/* out */ System::_di_IInterface &matrixTransform3D) = 0 ;
	virtual HRESULT __stdcall CreateTransform3DGroup(void * transforms3D, unsigned elements, /* out */ System::_di_IInterface &transform3DGroup) = 0 ;
	virtual HRESULT __stdcall CreateEffectGroup(/* out */ System::_di_IInterface &effectGroup) = 0 ;
	virtual HRESULT __stdcall CreateRectangleClip(/* out */ System::_di_IInterface &clip) = 0 ;
	virtual HRESULT __stdcall CreateAnimation(/* out */ System::_di_IInterface &animation) = 0 ;
};

__interface  INTERFACE_UUID("{5F4633FE-1E08-4CB8-8C75-CE24333F5602}") IDCompositionDesktopDevice  : public IDCompositionDevice2 
{
	virtual HRESULT __stdcall CreateTargetForHwnd(HWND hwnd, bool topmost, /* out */ _di_IDCompositionTarget &target) = 0 ;
	virtual HRESULT __stdcall CreateSurfaceFromHandle(NativeUInt handle, /* out */ System::_di_IInterface &surface) = 0 ;
	virtual HRESULT __stdcall CreateSurfaceFromHwnd(HWND hwnd, /* out */ System::_di_IInterface &surface) = 0 ;
};

//-- var, const, procedure ---------------------------------------------------
static const System::Int8 DXGI_SWAP_CHAIN_FLAG_NONPREROTATED = System::Int8(0x1);
static const System::Int8 DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH = System::Int8(0x2);
static const System::Int8 DXGI_SWAP_CHAIN_FLAG_GDI_COMPATIBLE = System::Int8(0x4);
static const System::Int8 DXGI_SWAP_CHAIN_FLAG_RESTRICTED_CONTENT = System::Int8(0x8);
static const System::Int8 DXGI_SWAP_CHAIN_FLAG_RESTRICT_SHARED_RESOURCE_DRIVER = System::Int8(0x10);
static const System::Int8 DXGI_SWAP_CHAIN_FLAG_DISPLAY_ONLY = System::Int8(0x20);
static const System::Int8 DXGI_SWAP_CHAIN_FLAG_FRAME_LATENCY_WAITABLE_OBJECT = System::Int8(0x40);
static const System::Byte DXGI_SWAP_CHAIN_FLAG_FOREGROUND_LAYER = System::Byte(0x80);
static const System::Word DXGI_SWAP_CHAIN_FLAG_FULLSCREEN_VIDEO = System::Word(0x100);
static const System::Word DXGI_SWAP_CHAIN_FLAG_YUV_VIDEO = System::Word(0x200);
static const System::Word DXGI_SWAP_CHAIN_FLAG_HW_PROTECTED = System::Word(0x400);
static const System::Word DXGI_SWAP_CHAIN_FLAG_ALLOW_TEARING = System::Word(0x800);
static const System::Word DXGI_SWAP_CHAIN_FLAG_RESTRICTED_TO_ALL_HOLOGRAPHIC_DISPLAYS = System::Word(0x1000);
static const System::Word DXGI_FAC = System::Word(0x87a);
static const int MAKE_DXGI_HRESULT = int(-2005270528);
static const int MAKE_DXGI_STATUS = int(142213120);
#define SID_ID2D1Factory1 L"{bb12d362-daee-4b9a-aa1d-14ba401cfa1f}"
extern DELPHI_PACKAGE GUID IID_ID2D1Factory1;
#define SID_ID2D1DeviceContext L"{e8f7fe7a-191c-466d-ad95-975678bda998}"
extern DELPHI_PACKAGE GUID IID_ID2D1DeviceContext;
#define SID_ID2D1Device L"{47dd575d-ac05-4cdd-8049-9b02cd16f44c}"
extern DELPHI_PACKAGE GUID IID_ID2D1Device;
static const System::Int8 D2D1_INTERPOLATION_MODE_DEFINITION_NEAREST_NEIGHBOR = System::Int8(0x0);
static const System::Int8 D2D1_INTERPOLATION_MODE_DEFINITION_LINEAR = System::Int8(0x1);
static const System::Int8 D2D1_INTERPOLATION_MODE_DEFINITION_CUBIC = System::Int8(0x2);
static const System::Int8 D2D1_INTERPOLATION_MODE_DEFINITION_MULTI_SAMPLE_LINEAR = System::Int8(0x3);
static const System::Int8 D2D1_INTERPOLATION_MODE_DEFINITION_ANISOTROPIC = System::Int8(0x4);
static const System::Int8 D2D1_INTERPOLATION_MODE_DEFINITION_HIGH_QUALITY_CUBIC = System::Int8(0x5);
static const System::Int8 D2D1_INTERPOLATION_MODE_DEFINITION_FANT = System::Int8(0x6);
static const System::Int8 D2D1_INTERPOLATION_MODE_DEFINITION_MIPMAP_LINEAR = System::Int8(0x7);
static const System::Int8 D2D1_BITMAP_OPTIONS_NONE = System::Int8(0x0);
static const System::Int8 D2D1_BITMAP_OPTIONS_TARGET = System::Int8(0x1);
static const System::Int8 D2D1_BITMAP_OPTIONS_CANNOT_DRAW = System::Int8(0x2);
static const System::Int8 D2D1_BITMAP_OPTIONS_CPU_READ = System::Int8(0x4);
static const System::Int8 D2D1_BITMAP_OPTIONS_GDI_COMPATIBLE = System::Int8(0x8);
static const unsigned D2D1_PROPERTY_CLSID = unsigned(0x80000000);
static const unsigned D2D1_PROPERTY_DISPLAYNAME = unsigned(0x80000001);
static const unsigned D2D1_PROPERTY_AUTHOR = unsigned(0x80000002);
static const unsigned D2D1_PROPERTY_CATEGORY = unsigned(0x80000003);
static const unsigned D2D1_PROPERTY_DESCRIPTION = unsigned(0x80000004);
static const unsigned D2D1_PROPERTY_INPUTS = unsigned(0x80000005);
static const unsigned D2D1_PROPERTY_CACHED = unsigned(0x80000006);
static const unsigned D2D1_PROPERTY_PRECISION = unsigned(0x80000007);
static const unsigned D2D1_PROPERTY_MIN_INPUTS = unsigned(0x80000008);
static const unsigned D2D1_PROPERTY_MAX_INPUTS = unsigned(0x80000009);
static const unsigned D2D1_SUBPROPERTY_DISPLAYNAME = unsigned(0x80000000);
static const unsigned D2D1_SUBPROPERTY_ISREADONLY = unsigned(0x80000001);
static const unsigned D2D1_SUBPROPERTY_MIN = unsigned(0x80000002);
static const unsigned D2D1_SUBPROPERTY_MAX = unsigned(0x80000003);
static const unsigned D2D1_SUBPROPERTY_DEFAULT = unsigned(0x80000004);
static const unsigned D2D1_SUBPROPERTY_FIELDS = unsigned(0x80000005);
static const unsigned D2D1_SUBPROPERTY_INDEX = unsigned(0x80000006);
extern DELPHI_PACKAGE GUID CLSID_D2D1ArithmeticComposite;
extern DELPHI_PACKAGE GUID CLSID_D2D1Atlas;
extern DELPHI_PACKAGE GUID CLSID_D2D1BitmapSource;
extern DELPHI_PACKAGE GUID CLSID_D2D1Blend;
extern DELPHI_PACKAGE GUID CLSID_D2D1Border;
extern DELPHI_PACKAGE GUID CLSID_D2D1Brightness;
extern DELPHI_PACKAGE GUID CLSID_D2D1ColorManagement;
extern DELPHI_PACKAGE GUID CLSID_D2D1ColorMatrix;
extern DELPHI_PACKAGE GUID CLSID_D2D1Composite;
extern DELPHI_PACKAGE GUID CLSID_D2D1ConvolveMatrix;
extern DELPHI_PACKAGE GUID CLSID_D2D1Crop;
extern DELPHI_PACKAGE GUID CLSID_D2D1DirectionalBlur;
extern DELPHI_PACKAGE GUID CLSID_D2D1DiscreteTransfer;
extern DELPHI_PACKAGE GUID CLSID_D2D1DisplacementMap;
extern DELPHI_PACKAGE GUID CLSID_D2D1DistantDiffuse;
extern DELPHI_PACKAGE GUID CLSID_D2D1DistantSpecular;
extern DELPHI_PACKAGE GUID CLSID_D2D1DpiCompensation;
extern DELPHI_PACKAGE GUID CLSID_D2D1Flood;
extern DELPHI_PACKAGE GUID CLSID_D2D1GammaTransfer;
extern DELPHI_PACKAGE GUID CLSID_D2D1GaussianBlur;
extern DELPHI_PACKAGE GUID CLSID_D2D1Histogram;
extern DELPHI_PACKAGE GUID CLSID_D2D1HueRotation;
extern DELPHI_PACKAGE GUID CLSID_D2D1LinearTransfer;
extern DELPHI_PACKAGE GUID CLSID_D2D1LuminanceToAlpha;
extern DELPHI_PACKAGE GUID CLSID_D2D1Morphology;
extern DELPHI_PACKAGE GUID CLSID_D2D1OpacityMetadata;
extern DELPHI_PACKAGE GUID CLSID_D2D1PointDiffuse;
extern DELPHI_PACKAGE GUID CLSID_D2D1PointSpecular;
extern DELPHI_PACKAGE GUID CLSID_D2D1Premultiply;
extern DELPHI_PACKAGE GUID CLSID_D2D1Saturation;
extern DELPHI_PACKAGE GUID CLSID_D2D1Scale;
extern DELPHI_PACKAGE GUID CLSID_D2D1Shadow;
extern DELPHI_PACKAGE GUID CLSID_D2D1SpotDiffuse;
extern DELPHI_PACKAGE GUID CLSID_D2D1SpotSpecular;
extern DELPHI_PACKAGE GUID CLSID_D2D1TableTransfer;
extern DELPHI_PACKAGE GUID CLSID_D2D1Tile;
extern DELPHI_PACKAGE GUID CLSID_D2D1Turbulence;
extern DELPHI_PACKAGE GUID CLSID_D2D1UnPremultiply;
extern DELPHI_PACKAGE GUID CLSID_D2D12DAffineTransform;
extern DELPHI_PACKAGE GUID CLSID_D2D13DPerspectiveTransform;
extern DELPHI_PACKAGE GUID CLSID_D2D13DTransform;
static const System::Int8 D2D1_GAUSSIANBLUR_PROP_STANDARD_DEVIATION = System::Int8(0x0);
static const System::Int8 D2D1_GAUSSIANBLUR_PROP_OPTIMIZATION = System::Int8(0x1);
static const System::Int8 D2D1_GAUSSIANBLUR_PROP_BORDER_MODE = System::Int8(0x2);
static const System::Int8 D2D1_GAUSSIANBLUR_OPTIMIZATION_SPEED = System::Int8(0x0);
static const System::Int8 D2D1_GAUSSIANBLUR_OPTIMIZATION_BALANCED = System::Int8(0x1);
static const System::Int8 D2D1_GAUSSIANBLUR_OPTIMIZATION_QUALITY = System::Int8(0x2);
static const System::Int8 D2D1_DIRECTIONALBLUR_PROP_STANDARD_DEVIATION = System::Int8(0x0);
static const System::Int8 D2D1_DIRECTIONALBLUR_PROP_ANGLE = System::Int8(0x1);
static const System::Int8 D2D1_DIRECTIONALBLUR_PROP_OPTIMIZATION = System::Int8(0x2);
static const System::Int8 D2D1_DIRECTIONALBLUR_PROP_BORDER_MODE = System::Int8(0x3);
static const System::Int8 D2D1_DIRECTIONALBLUR_OPTIMIZATION_SPEED = System::Int8(0x0);
static const System::Int8 D2D1_DIRECTIONALBLUR_OPTIMIZATION_BALANCED = System::Int8(0x1);
static const System::Int8 D2D1_DIRECTIONALBLUR_OPTIMIZATION_QUALITY = System::Int8(0x2);
static const System::Int8 D2D1_SHADOW_PROP_BLUR_STANDARD_DEVIATION = System::Int8(0x0);
static const System::Int8 D2D1_SHADOW_PROP_COLOR = System::Int8(0x1);
static const System::Int8 D2D1_SHADOW_PROP_OPTIMIZATION = System::Int8(0x2);
static const System::Int8 D2D1_SHADOW_OPTIMIZATION_SPEED = System::Int8(0x0);
static const System::Int8 D2D1_SHADOW_OPTIMIZATION_BALANCED = System::Int8(0x1);
static const System::Int8 D2D1_SHADOW_OPTIMIZATION_QUALITY = System::Int8(0x2);
static const System::Int8 D2D1_BLEND_MODE_MULTIPLY = System::Int8(0x0);
static const System::Int8 D2D1_BLEND_MODE_SCREEN = System::Int8(0x1);
static const System::Int8 D2D1_BLEND_MODE_DARKEN = System::Int8(0x2);
static const System::Int8 D2D1_BLEND_MODE_LIGHTEN = System::Int8(0x3);
static const System::Int8 D2D1_BLEND_MODE_DISSOLVE = System::Int8(0x4);
static const System::Int8 D2D1_BLEND_MODE_COLOR_BURN = System::Int8(0x5);
static const System::Int8 D2D1_BLEND_MODE_LINEAR_BURN = System::Int8(0x6);
static const System::Int8 D2D1_BLEND_MODE_DARKER_COLOR = System::Int8(0x7);
static const System::Int8 D2D1_BLEND_MODE_LIGHTER_COLOR = System::Int8(0x8);
static const System::Int8 D2D1_BLEND_MODE_COLOR_DODGE = System::Int8(0x9);
static const System::Int8 D2D1_BLEND_MODE_LINEAR_DODGE = System::Int8(0xa);
static const System::Int8 D2D1_BLEND_MODE_OVERLAY = System::Int8(0xb);
static const System::Int8 D2D1_BLEND_MODE_SOFT_LIGHT = System::Int8(0xc);
static const System::Int8 D2D1_BLEND_MODE_HARD_LIGHT = System::Int8(0xd);
static const System::Int8 D2D1_BLEND_MODE_VIVID_LIGHT = System::Int8(0xe);
static const System::Int8 D2D1_BLEND_MODE_LINEAR_LIGHT = System::Int8(0xf);
static const System::Int8 D2D1_BLEND_MODE_PIN_LIGHT = System::Int8(0x10);
static const System::Int8 D2D1_BLEND_MODE_HARD_MIX = System::Int8(0x11);
static const System::Int8 D2D1_BLEND_MODE_DIFFERENCE = System::Int8(0x12);
static const System::Int8 D2D1_BLEND_MODE_EXCLUSION = System::Int8(0x13);
static const System::Int8 D2D1_BLEND_MODE_HUE = System::Int8(0x14);
static const System::Int8 D2D1_BLEND_MODE_SATURATION = System::Int8(0x15);
static const System::Int8 D2D1_BLEND_MODE_COLOR = System::Int8(0x16);
static const System::Int8 D2D1_BLEND_MODE_LUMINOSITY = System::Int8(0x17);
static const System::Int8 D2D1_BLEND_MODE_SUBTRACT = System::Int8(0x18);
static const System::Int8 D2D1_BLEND_MODE_DIVISION = System::Int8(0x19);
static const System::Int8 D2D1_SATURATION_PROP_SATURATION = System::Int8(0x0);
static const System::Int8 D2D1_HUEROTATION_PROP_ANGLE = System::Int8(0x0);
static const System::Int8 D2D1_COLORMATRIX_PROP_COLOR_MATRIX = System::Int8(0x0);
static const System::Int8 D2D1_COLORMATRIX_PROP_ALPHA_MODE = System::Int8(0x1);
static const System::Int8 D2D1_COLORMATRIX_PROP_CLAMP_OUTPUT = System::Int8(0x2);
static const System::Int8 D2D1_COLORMATRIX_ALPHA_MODE_PREMULTIPLIED = System::Int8(0x1);
static const System::Int8 D2D1_COLORMATRIX_ALPHA_MODE_STRAIGHT = System::Int8(0x2);
#define D3D11lib L"d3d11.dll"
static const System::Int8 D3D11_CREATE_DEVICE_SINGLETHREADED = System::Int8(0x1);
static const System::Int8 D3D11_CREATE_DEVICE_DEBUG = System::Int8(0x2);
static const System::Int8 D3D11_CREATE_DEVICE_SWITCH_TO_REF = System::Int8(0x4);
static const System::Int8 D3D11_CREATE_DEVICE_PREVENT_INTERNAL_THREADING_OPTIMIZATIONS = System::Int8(0x8);
static const System::Int8 D3D11_CREATE_DEVICE_BGRA_SUPPORT = System::Int8(0x20);
static const System::Int8 D3D11_CREATE_DEVICE_DEBUGGABLE = System::Int8(0x40);
static const System::Byte D3D11_CREATE_DEVICE_PREVENT_ALTERING_LAYER_SETTINGS_FROM_REGISTRY = System::Byte(0x80);
static const System::Word D3D11_CREATE_DEVICE_DISABLE_GPU_TIMEOUT = System::Word(0x100);
static const System::Word D3D11_CREATE_DEVICE_VIDEO_SUPPORT = System::Word(0x800);
static const System::Int8 D3D11_BIND_VERTEX_BUFFER = System::Int8(0x1);
static const System::Int8 D3D11_BIND_INDEX_BUFFER = System::Int8(0x2);
static const System::Int8 D3D11_BIND_CONSTANT_BUFFER = System::Int8(0x4);
static const System::Int8 D3D11_BIND_SHADER_RESOURCE = System::Int8(0x8);
static const System::Int8 D3D11_BIND_STREAM_OUTPUT = System::Int8(0x10);
static const System::Int8 D3D11_BIND_RENDER_TARGET = System::Int8(0x20);
static const System::Int8 D3D11_BIND_DEPTH_STENCIL = System::Int8(0x40);
static const System::Byte D3D11_BIND_UNORDERED_ACCESS = System::Byte(0x80);
static const System::Word D3D11_BIND_DECODER = System::Word(0x200);
static const System::Word D3D11_BIND_VIDEO_ENCODER = System::Word(0x400);
static const System::Int8 D3D11_RESOURCE_MISC_GENERATE_MIPS = System::Int8(0x1);
static const System::Int8 D3D11_RESOURCE_MISC_SHARED = System::Int8(0x2);
static const System::Int8 D3D11_RESOURCE_MISC_TEXTURECUBE = System::Int8(0x4);
static const System::Int8 D3D11_RESOURCE_MISC_DRAWINDIRECT_ARGS = System::Int8(0x10);
static const System::Int8 D3D11_RESOURCE_MISC_BUFFER_ALLOW_RAW_VIEWS = System::Int8(0x20);
static const System::Int8 D3D11_RESOURCE_MISC_BUFFER_STRUCTURED = System::Int8(0x40);
static const System::Byte D3D11_RESOURCE_MISC_RESOURCE_CLAMP = System::Byte(0x80);
static const System::Word D3D11_RESOURCE_MISC_SHARED_KEYEDMUTEX = System::Word(0x100);
static const System::Word D3D11_RESOURCE_MISC_GDI_COMPATIBLE = System::Word(0x200);
static const System::Word D3D11_RESOURCE_MISC_SHARED_NTHANDLE = System::Word(0x800);
static const System::Word D3D11_RESOURCE_MISC_RESTRICTED_CONTENT = System::Word(0x1000);
static const System::Word D3D11_RESOURCE_MISC_RESTRICT_SHARED_RESOURCE = System::Word(0x2000);
static const System::Word D3D11_RESOURCE_MISC_RESTRICT_SHARED_RESOURCE_DRIVER = System::Word(0x4000);
static const System::Word D3D11_RESOURCE_MISC_GUARDED = System::Word(0x8000);
static const int D3D11_RESOURCE_MISC_TILE_POOL = int(0x20000);
static const int D3D11_RESOURCE_MISC_TILED = int(0x40000);
static const System::Int8 D3D11_SDK_VERSION = System::Int8(0x7);
#define SID_ID3D11DeviceContext L"{c0bfa96c-e089-44fb-8eaf-26f8796190da}"
extern DELPHI_PACKAGE GUID IID_ID3D11DeviceContext;
#define SID_ID3D11DeviceChild L"{1841e5c8-16b0-489b-bcc8-44cfb0d5deae}"
extern DELPHI_PACKAGE GUID IID_ID3D11DeviceChild;
#define SID_ID3D11Device L"{db6f6ddb-ac77-4e88-8253-819df9bbf140}"
extern DELPHI_PACKAGE GUID IID_ID3D11Device;
#define SID_ID3D11PixelShader L"{ea82e40d-51dc-4f33-93d4-db7c9125ae8c}"
extern DELPHI_PACKAGE GUID IID_ID3D11PixelShader;
#define DCompLib L"Dcomp.dll"
static const System::Int8 DCOMPOSITION_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR = System::Int8(0x0);
static const System::Int8 DCOMPOSITION_BITMAP_INTERPOLATION_MODE_LINEAR = System::Int8(0x1);
static const System::Int8 DCOMPOSITION_BORDER_MODE_SOFT = System::Int8(0x0);
static const System::Int8 DCOMPOSITION_BORDER_MODE_HARD = System::Int8(0x1);
static const System::Int8 DCOMPOSITION_COMPOSITE_MODE_SOURCE_OVER = System::Int8(0x0);
static const System::Int8 DCOMPOSITION_COMPOSITE_MODE_DESTINATION_INVERT = System::Int8(0x1);
static const System::Int8 DCOMPOSITION_COMPOSITE_MODE_MIN_BLEND = System::Int8(0x2);
static const System::Int8 DCOMPOSITION_OPACITY_MODE_LAYER = System::Int8(0x0);
static const System::Int8 DCOMPOSITION_OPACITY_MODE_MULTIPLY = System::Int8(0x1);
static const System::Int8 DCOMPOSITION_BACKFACE_VISIBILITY_VISIBLE = System::Int8(0x0);
static const System::Int8 DCOMPOSITION_BACKFACE_VISIBILITY_HIDDEN = System::Int8(0x1);
extern DELPHI_PACKAGE HRESULT __fastcall D2D1CreateFactoryNew(D2D1_FACTORY_TYPE factoryType, const GUID &riid, Winapi::D2d1::PD2D1FactoryOptions pFactoryOptions, /* out */ void *ppIFactory);
extern DELPHI_PACKAGE HRESULT __fastcall D3D11CreateDevice(_di_IDXGIAdapter pAdapter, TD3DDriveType DriverType, NativeUInt Software, unsigned Flags, PD3DFeatureLevel pFeatureLevels, unsigned FeatureLevels, unsigned SDKVersion, /* out */ _di_ID3D11Device &ppDevice, PD3DFeatureLevel pFeatureLevel, /* out */ _di_ID3D11DeviceContext &ppImmediateContext);
extern DELPHI_PACKAGE bool __fastcall CheckNeedRecreateContext(const HRESULT AErrorCode)/* overload */;
extern DELPHI_PACKAGE bool __fastcall CheckNeedSwitchToGdiRenderMode(const HRESULT AErrorCode = (HRESULT)(0x0))/* overload */;
extern DELPHI_PACKAGE bool __fastcall CheckNeedSwitchToGdiRenderMode(System::Sysutils::Exception* const AException)/* overload */;
extern DELPHI_PACKAGE bool __fastcall IsDirectD2Available(void);
extern DELPHI_PACKAGE _di_ID2D1Factory1 __fastcall D2D1Factory1(void);
extern DELPHI_PACKAGE Winapi::D2d1::_di_IDWriteFactory __fastcall DWriteFactory(void);
}	/* namespace Types */
}	/* namespace D2d */
}	/* namespace Dxdirectx */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXDIRECTX_D2D_TYPES)
using namespace Dxdirectx::D2d::Types;
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
#endif	// Dxdirectx_D2d_TypesHPP
