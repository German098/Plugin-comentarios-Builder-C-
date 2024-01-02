﻿// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxScrollbarAnnotations.pas' rev: 35.00 (Windows)

#ifndef DxscrollbarannotationsHPP
#define DxscrollbarannotationsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.Windows.hpp>
#include <Vcl.Forms.hpp>
#include <Winapi.Messages.hpp>
#include <System.Types.hpp>
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <Vcl.Graphics.hpp>
#include <System.Generics.Defaults.hpp>
#include <System.Generics.Collections.hpp>
#include <dxCoreGraphics.hpp>

//-- user supplied -----------------------------------------------------------

namespace Dxscrollbarannotations
{
//-- forward type declarations -----------------------------------------------
__interface DELPHIINTERFACE IdxScrollbarAnnotationRenderer;
typedef System::DelphiInterface<IdxScrollbarAnnotationRenderer> _di_IdxScrollbarAnnotationRenderer;
class DELPHICLASS TdxScrollbarAnnotationRowIndexList;
class DELPHICLASS TdxScrollbarAnnotationRowIndexLists;
struct TdxScrollbarAnnotationStyle;
class DELPHICLASS TdxScrollbarAnnotations;
class DELPHICLASS TdxCustomScrollbarAnnotation;
class DELPHICLASS TdxCustomScrollbarAnnotations;
class DELPHICLASS TdxScrollbarAnnotationOptions;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TdxScrollbarAnnotationAlignment : unsigned char { saaNear, saaCenter, saaFar, saaClient };

typedef System::Byte TdxScrollbarAnnotationKind;

typedef System::Set<TdxScrollbarAnnotationKind, 0, 255> TdxScrollbarAnnotationKinds;

__interface  INTERFACE_UUID("{0C20A750-FAFE-4A96-A0FB-DE73BCF98CF9}") IdxScrollbarAnnotationRenderer  : public System::IInterface 
{
	virtual void __fastcall SetAnnotations(TdxScrollbarAnnotations* AAnnotations) = 0 ;
	virtual void __fastcall Invalidate(const TdxScrollbarAnnotationKinds &AAnnotationKinds = (TdxScrollbarAnnotationKinds() << 0x0 << 0x1 << 0x2 << 0x3 << 0x4 << 0x5 << 0x6 << 0x7 << 0x8 << 0x9 << 0xa << 0xb << 0xc << 0xd << 0xe << 0xf << 0x10 << 0x11 << 0x12 << 0x13 << 0x14 << 0x15 << 0x16 << 0x17 << 0x18 << 0x19 << 0x1a << 0x1b << 0x1c << 0x1d << 0x1e << 0x1f << 0x20 << 0x21 << 0x22 << 0x23 << 0x24 << 0x25 << 0x26 << 0x27 << 0x28 << 0x29 << 0x2a << 0x2b << 0x2c << 0x2d << 0x2e << 0x2f << 0x30 << 0x31 << 0x32 << 0x33 << 0x34 << 0x35 << 0x36 << 0x37 << 0x38 << 0x39 << 0x3a << 0x3b << 0x3c << 0x3d << 0x3e << 0x3f << 0x40 << 0x41 << 0x42 << 0x43 << 0x44 << 0x45 << 0x46 << 0x47 << 0x48 << 0x49 << 0x4a << 0x4b << 0x4c << 0x4d << 0x4e << 0x4f << 0x50 << 0x51 << 0x52 << 0x53 << 0x54 << 0x55 << 0x56 << 0x57 << 0x58 << 0x59 << 0x5a << 0x5b << 0x5c << 0x5d << 0x5e << 0x5f << 0x60 << 0x61 << 0x62 << 0x63 << 0x64 << 0x65 << 0x66 << 0x67 << 0x68 << 0x69 << 0x6a << 0x6b << 0x6c << 0x6d << 0x6e << 0x6f << 0x70 << 0x71 << 0x72 << 0x73 << 0x74 << 0x75 << 0x76 << 0x77 << 0x78 << 0x79 << 0x7a << 0x7b << 0x7c << 0x7d << 0x7e << 0x7f << 0x80 << 0x81 << 0x82 << 0x83 << 0x84 << 0x85 << 0x86 << 0x87 << 0x88 << 0x89 << 0x8a << 0x8b << 0x8c << 0x8d << 0x8e << 0x8f << 0x90 << 0x91 << 0x92 << 0x93 << 0x94 << 0x95 << 0x96 << 0x97 << 0x98 << 0x99 << 0x9a << 0x9b << 0x9c << 0x9d << 0x9e << 0x9f << 0xa0 << 0xa1 << 0xa2 << 0xa3 << 0xa4 << 0xa5 << 0xa6 << 0xa7 << 0xa8 << 0xa9 << 0xaa << 0xab << 0xac << 0xad << 0xae << 0xaf << 0xb0 << 0xb1 << 0xb2 << 0xb3 << 0xb4 << 0xb5 << 0xb6 << 0xb7 << 0xb8 << 0xb9 << 0xba << 0xbb << 0xbc << 0xbd << 0xbe << 0xbf << 0xc0 << 0xc1 << 0xc2 << 0xc3 << 0xc4 << 0xc5 << 0xc6 << 0xc7 << 0xc8 << 0xc9 << 0xca << 0xcb << 0xcc << 0xcd << 0xce << 0xcf << 0xd0 << 0xd1 << 0xd2 << 0xd3 << 0xd4 << 0xd5 << 0xd6 << 0xd7 << 0xd8 << 0xd9 << 0xda << 0xdb << 0xdc << 0xdd << 0xde << 0xdf << 0xe0 << 0xe1 << 0xe2 << 0xe3 << 0xe4 << 0xe5 << 0xe6 << 0xe7 << 0xe8 << 0xe9 << 0xea << 0xeb << 0xec << 0xed << 0xee << 0xef << 0xf0 << 0xf1 << 0xf2 << 0xf3 << 0xf4 << 0xf5 << 0xf6 << 0xf7 << 0xf8 << 0xf9 << 0xfa << 0xfb << 0xfc << 0xfd << 0xfe << 0xff )) = 0 ;
	virtual void __fastcall Update() = 0 ;
};

class PASCALIMPLEMENTATION TdxScrollbarAnnotationRowIndexList : public System::Generics::Collections::TList__1<int>
{
	typedef System::Generics::Collections::TList__1<int> inherited;
	
public:
	/* {System_Generics_Collections}TList<System_Integer>.Create */ inline __fastcall TdxScrollbarAnnotationRowIndexList()/* overload */ : System::Generics::Collections::TList__1<int>() { }
	/* {System_Generics_Collections}TList<System_Integer>.Create */ inline __fastcall TdxScrollbarAnnotationRowIndexList(const System::DelphiInterface<System::Generics::Defaults::IComparer__1<int> > AComparer)/* overload */ : System::Generics::Collections::TList__1<int>(AComparer) { }
	/* {System_Generics_Collections}TList<System_Integer>.Create */ inline __fastcall TdxScrollbarAnnotationRowIndexList(System::Generics::Collections::TEnumerable__1<int>* const Collection)/* overload */ : System::Generics::Collections::TList__1<int>(Collection) { }
	/* {System_Generics_Collections}TList<System_Integer>.Create */ inline __fastcall TdxScrollbarAnnotationRowIndexList(const int *Values, const int Values_High)/* overload */ : System::Generics::Collections::TList__1<int>(Values, Values_High) { }
	/* {System_Generics_Collections}TList<System_Integer>.Destroy */ inline __fastcall virtual ~TdxScrollbarAnnotationRowIndexList() { }
	
};


class PASCALIMPLEMENTATION TdxScrollbarAnnotationRowIndexLists : public System::Generics::Collections::TObjectDictionary__2<TdxScrollbarAnnotationKind,TdxScrollbarAnnotationRowIndexList*>
{
	typedef System::Generics::Collections::TObjectDictionary__2<TdxScrollbarAnnotationKind,TdxScrollbarAnnotationRowIndexList*> inherited;
	
public:
	/* {System_Generics_Collections}TObjectDictionary<dxScrollbarAnnotations_TdxScrollbarAnnotationKind,dxScrollbarAnnotations_TdxScrollbarAnnotationRowIndexList>.Create */ inline __fastcall TdxScrollbarAnnotationRowIndexLists(System::Generics::Collections::TDictionaryOwnerships Ownerships, int ACapacity)/* overload */ : System::Generics::Collections::TObjectDictionary__2<TdxScrollbarAnnotationKind,TdxScrollbarAnnotationRowIndexList*>(Ownerships, ACapacity) { }
	/* {System_Generics_Collections}TObjectDictionary<dxScrollbarAnnotations_TdxScrollbarAnnotationKind,dxScrollbarAnnotations_TdxScrollbarAnnotationRowIndexList>.Create */ inline __fastcall TdxScrollbarAnnotationRowIndexLists(System::Generics::Collections::TDictionaryOwnerships Ownerships, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<TdxScrollbarAnnotationKind> > AComparer)/* overload */ : System::Generics::Collections::TObjectDictionary__2<TdxScrollbarAnnotationKind,TdxScrollbarAnnotationRowIndexList*>(Ownerships, AComparer) { }
	/* {System_Generics_Collections}TObjectDictionary<dxScrollbarAnnotations_TdxScrollbarAnnotationKind,dxScrollbarAnnotations_TdxScrollbarAnnotationRowIndexList>.Create */ inline __fastcall TdxScrollbarAnnotationRowIndexLists(System::Generics::Collections::TDictionaryOwnerships Ownerships, int ACapacity, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<TdxScrollbarAnnotationKind> > AComparer)/* overload */ : System::Generics::Collections::TObjectDictionary__2<TdxScrollbarAnnotationKind,TdxScrollbarAnnotationRowIndexList*>(Ownerships, ACapacity, AComparer) { }
	
public:
	/* {System_Generics_Collections}TDictionary<dxScrollbarAnnotations_TdxScrollbarAnnotationKind,dxScrollbarAnnotations_TdxScrollbarAnnotationRowIndexList>.Create */ inline __fastcall TdxScrollbarAnnotationRowIndexLists()/* overload */ : System::Generics::Collections::TObjectDictionary__2<TdxScrollbarAnnotationKind,TdxScrollbarAnnotationRowIndexList*>() { }
	/* {System_Generics_Collections}TDictionary<dxScrollbarAnnotations_TdxScrollbarAnnotationKind,dxScrollbarAnnotations_TdxScrollbarAnnotationRowIndexList>.Create */ inline __fastcall TdxScrollbarAnnotationRowIndexLists(int ACapacity)/* overload */ : System::Generics::Collections::TObjectDictionary__2<TdxScrollbarAnnotationKind,TdxScrollbarAnnotationRowIndexList*>(ACapacity) { }
	/* {System_Generics_Collections}TDictionary<dxScrollbarAnnotations_TdxScrollbarAnnotationKind,dxScrollbarAnnotations_TdxScrollbarAnnotationRowIndexList>.Create */ inline __fastcall TdxScrollbarAnnotationRowIndexLists(const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<TdxScrollbarAnnotationKind> > AComparer)/* overload */ : System::Generics::Collections::TObjectDictionary__2<TdxScrollbarAnnotationKind,TdxScrollbarAnnotationRowIndexList*>(AComparer) { }
	/* {System_Generics_Collections}TDictionary<dxScrollbarAnnotations_TdxScrollbarAnnotationKind,dxScrollbarAnnotations_TdxScrollbarAnnotationRowIndexList>.Create */ inline __fastcall TdxScrollbarAnnotationRowIndexLists(int ACapacity, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<TdxScrollbarAnnotationKind> > AComparer)/* overload */ : System::Generics::Collections::TObjectDictionary__2<TdxScrollbarAnnotationKind,TdxScrollbarAnnotationRowIndexList*>(ACapacity, AComparer) { }
	/* {System_Generics_Collections}TDictionary<dxScrollbarAnnotations_TdxScrollbarAnnotationKind,dxScrollbarAnnotations_TdxScrollbarAnnotationRowIndexList>.Create */ inline __fastcall TdxScrollbarAnnotationRowIndexLists(System::Generics::Collections::TEnumerable__1<System::Generics::Collections::TPair__2<TdxScrollbarAnnotationKind,TdxScrollbarAnnotationRowIndexList*> >* const Collection)/* overload */ : System::Generics::Collections::TObjectDictionary__2<TdxScrollbarAnnotationKind,TdxScrollbarAnnotationRowIndexList*>(Collection) { }
	/* {System_Generics_Collections}TDictionary<dxScrollbarAnnotations_TdxScrollbarAnnotationKind,dxScrollbarAnnotations_TdxScrollbarAnnotationRowIndexList>.Create */ inline __fastcall TdxScrollbarAnnotationRowIndexLists(System::Generics::Collections::TEnumerable__1<System::Generics::Collections::TPair__2<TdxScrollbarAnnotationKind,TdxScrollbarAnnotationRowIndexList*> >* const Collection, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<TdxScrollbarAnnotationKind> > AComparer)/* overload */ : System::Generics::Collections::TObjectDictionary__2<TdxScrollbarAnnotationKind,TdxScrollbarAnnotationRowIndexList*>(Collection, AComparer) { }
	/* {System_Generics_Collections}TDictionary<dxScrollbarAnnotations_TdxScrollbarAnnotationKind,dxScrollbarAnnotations_TdxScrollbarAnnotationRowIndexList>.Create */ inline __fastcall TdxScrollbarAnnotationRowIndexLists(const System::Generics::Collections::TPair__2<TdxScrollbarAnnotationKind,TdxScrollbarAnnotationRowIndexList*> *AItems, const int AItems_High)/* overload */ : System::Generics::Collections::TObjectDictionary__2<TdxScrollbarAnnotationKind,TdxScrollbarAnnotationRowIndexList*>(AItems, AItems_High) { }
	/* {System_Generics_Collections}TDictionary<dxScrollbarAnnotations_TdxScrollbarAnnotationKind,dxScrollbarAnnotations_TdxScrollbarAnnotationRowIndexList>.Create */ inline __fastcall TdxScrollbarAnnotationRowIndexLists(const System::Generics::Collections::TPair__2<TdxScrollbarAnnotationKind,TdxScrollbarAnnotationRowIndexList*> *AItems, const int AItems_High, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<TdxScrollbarAnnotationKind> > AComparer)/* overload */ : System::Generics::Collections::TObjectDictionary__2<TdxScrollbarAnnotationKind,TdxScrollbarAnnotationRowIndexList*>(AItems, AItems_High, AComparer) { }
	/* {System_Generics_Collections}TDictionary<dxScrollbarAnnotations_TdxScrollbarAnnotationKind,dxScrollbarAnnotations_TdxScrollbarAnnotationRowIndexList>.Destroy */ inline __fastcall virtual ~TdxScrollbarAnnotationRowIndexLists() { }
	
};


typedef void __fastcall (__closure *TdxPopulateCustomScrollbarAnnotationRowIndexList)(System::TObject* Sender, int AAnnotationIndex, TdxScrollbarAnnotationRowIndexList* ARowIndexList);

typedef void __fastcall (__closure *TdxGetScrollbarAnnotationHint)(System::TObject* Sender, TdxScrollbarAnnotationRowIndexLists* AAnnotationRowIndexLists, System::UnicodeString &AHint);

struct DECLSPEC_DRECORD TdxScrollbarAnnotationStyle
{
public:
	TdxScrollbarAnnotationAlignment Alignment;
	Dxcoregraphics::TdxAlphaColor Color;
	int MaxHeight;
	int MinHeight;
	int Offset;
	int Width;
	bool __fastcall IsEqual(const TdxScrollbarAnnotationStyle &AStyle);
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxScrollbarAnnotations : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxScrollbarAnnotationKinds FChangedKinds;
	TdxScrollbarAnnotationRowIndexLists* FItemLists;
	int FLockCount;
	System::Generics::Collections::TList__1<_di_IdxScrollbarAnnotationRenderer>* FRenderers;
	void __fastcall Changed(const TdxScrollbarAnnotationKinds &AKinds = (TdxScrollbarAnnotationKinds() << 0x0 << 0x1 << 0x2 << 0x3 << 0x4 << 0x5 << 0x6 << 0x7 << 0x8 << 0x9 << 0xa << 0xb << 0xc << 0xd << 0xe << 0xf << 0x10 << 0x11 << 0x12 << 0x13 << 0x14 << 0x15 << 0x16 << 0x17 << 0x18 << 0x19 << 0x1a << 0x1b << 0x1c << 0x1d << 0x1e << 0x1f << 0x20 << 0x21 << 0x22 << 0x23 << 0x24 << 0x25 << 0x26 << 0x27 << 0x28 << 0x29 << 0x2a << 0x2b << 0x2c << 0x2d << 0x2e << 0x2f << 0x30 << 0x31 << 0x32 << 0x33 << 0x34 << 0x35 << 0x36 << 0x37 << 0x38 << 0x39 << 0x3a << 0x3b << 0x3c << 0x3d << 0x3e << 0x3f << 0x40 << 0x41 << 0x42 << 0x43 << 0x44 << 0x45 << 0x46 << 0x47 << 0x48 << 0x49 << 0x4a << 0x4b << 0x4c << 0x4d << 0x4e << 0x4f << 0x50 << 0x51 << 0x52 << 0x53 << 0x54 << 0x55 << 0x56 << 0x57 << 0x58 << 0x59 << 0x5a << 0x5b << 0x5c << 0x5d << 0x5e << 0x5f << 0x60 << 0x61 << 0x62 << 0x63 << 0x64 << 0x65 << 0x66 << 0x67 << 0x68 << 0x69 << 0x6a << 0x6b << 0x6c << 0x6d << 0x6e << 0x6f << 0x70 << 0x71 << 0x72 << 0x73 << 0x74 << 0x75 << 0x76 << 0x77 << 0x78 << 0x79 << 0x7a << 0x7b << 0x7c << 0x7d << 0x7e << 0x7f << 0x80 << 0x81 << 0x82 << 0x83 << 0x84 << 0x85 << 0x86 << 0x87 << 0x88 << 0x89 << 0x8a << 0x8b << 0x8c << 0x8d << 0x8e << 0x8f << 0x90 << 0x91 << 0x92 << 0x93 << 0x94 << 0x95 << 0x96 << 0x97 << 0x98 << 0x99 << 0x9a << 0x9b << 0x9c << 0x9d << 0x9e << 0x9f << 0xa0 << 0xa1 << 0xa2 << 0xa3 << 0xa4 << 0xa5 << 0xa6 << 0xa7 << 0xa8 << 0xa9 << 0xaa << 0xab << 0xac << 0xad << 0xae << 0xaf << 0xb0 << 0xb1 << 0xb2 << 0xb3 << 0xb4 << 0xb5 << 0xb6 << 0xb7 << 0xb8 << 0xb9 << 0xba << 0xbb << 0xbc << 0xbd << 0xbe << 0xbf << 0xc0 << 0xc1 << 0xc2 << 0xc3 << 0xc4 << 0xc5 << 0xc6 << 0xc7 << 0xc8 << 0xc9 << 0xca << 0xcb << 0xcc << 0xcd << 0xce << 0xcf << 0xd0 << 0xd1 << 0xd2 << 0xd3 << 0xd4 << 0xd5 << 0xd6 << 0xd7 << 0xd8 << 0xd9 << 0xda << 0xdb << 0xdc << 0xdd << 0xde << 0xdf << 0xe0 << 0xe1 << 0xe2 << 0xe3 << 0xe4 << 0xe5 << 0xe6 << 0xe7 << 0xe8 << 0xe9 << 0xea << 0xeb << 0xec << 0xed << 0xee << 0xef << 0xf0 << 0xf1 << 0xf2 << 0xf3 << 0xf4 << 0xf5 << 0xf6 << 0xf7 << 0xf8 << 0xf9 << 0xfa << 0xfb << 0xfc << 0xfd << 0xfe << 0xff ));
	bool __fastcall FindNearestRecordIndex(const TdxScrollbarAnnotationKinds &AKinds, bool ACircular, bool AGoForward, /* out */ int &AIndex);
	void __fastcall SortChangedLists();
	void __fastcall UpdateRenderers();
	
protected:
	void __fastcall Add(TdxScrollbarAnnotationKind AKind, int ARecordIndex);
	void __fastcall AddRange(TdxScrollbarAnnotationKind AKind, TdxScrollbarAnnotationRowIndexList* ARecordIndices);
	void __fastcall BeginUpdate();
	void __fastcall Clear(TdxScrollbarAnnotationKind AKind);
	void __fastcall EndUpdate();
	virtual int __fastcall GetCurrentRecordIndex();
	int __fastcall GetFirstRecordIndex();
	int __fastcall GetLastRecordIndex();
	virtual TdxScrollbarAnnotationOptions* __fastcall GetOptions();
	virtual int __fastcall GetDataPixelScrollSize();
	virtual int __fastcall GetRecordIndexByScrollableRecordIndex(int AIndex);
	virtual bool __fastcall IsVisible(TdxScrollbarAnnotationKind AKind);
	virtual void __fastcall Populate(TdxScrollbarAnnotationKind AKind, TdxScrollbarAnnotationRowIndexList* AList);
	virtual void __fastcall Refresh(const TdxScrollbarAnnotationKinds &AChangedAnnotationKinds = (TdxScrollbarAnnotationKinds() << 0x0 << 0x1 << 0x2 << 0x3 << 0x4 << 0x5 << 0x6 << 0x7 << 0x8 << 0x9 << 0xa << 0xb << 0xc << 0xd << 0xe << 0xf << 0x10 << 0x11 << 0x12 << 0x13 << 0x14 << 0x15 << 0x16 << 0x17 << 0x18 << 0x19 << 0x1a << 0x1b << 0x1c << 0x1d << 0x1e << 0x1f << 0x20 << 0x21 << 0x22 << 0x23 << 0x24 << 0x25 << 0x26 << 0x27 << 0x28 << 0x29 << 0x2a << 0x2b << 0x2c << 0x2d << 0x2e << 0x2f << 0x30 << 0x31 << 0x32 << 0x33 << 0x34 << 0x35 << 0x36 << 0x37 << 0x38 << 0x39 << 0x3a << 0x3b << 0x3c << 0x3d << 0x3e << 0x3f << 0x40 << 0x41 << 0x42 << 0x43 << 0x44 << 0x45 << 0x46 << 0x47 << 0x48 << 0x49 << 0x4a << 0x4b << 0x4c << 0x4d << 0x4e << 0x4f << 0x50 << 0x51 << 0x52 << 0x53 << 0x54 << 0x55 << 0x56 << 0x57 << 0x58 << 0x59 << 0x5a << 0x5b << 0x5c << 0x5d << 0x5e << 0x5f << 0x60 << 0x61 << 0x62 << 0x63 << 0x64 << 0x65 << 0x66 << 0x67 << 0x68 << 0x69 << 0x6a << 0x6b << 0x6c << 0x6d << 0x6e << 0x6f << 0x70 << 0x71 << 0x72 << 0x73 << 0x74 << 0x75 << 0x76 << 0x77 << 0x78 << 0x79 << 0x7a << 0x7b << 0x7c << 0x7d << 0x7e << 0x7f << 0x80 << 0x81 << 0x82 << 0x83 << 0x84 << 0x85 << 0x86 << 0x87 << 0x88 << 0x89 << 0x8a << 0x8b << 0x8c << 0x8d << 0x8e << 0x8f << 0x90 << 0x91 << 0x92 << 0x93 << 0x94 << 0x95 << 0x96 << 0x97 << 0x98 << 0x99 << 0x9a << 0x9b << 0x9c << 0x9d << 0x9e << 0x9f << 0xa0 << 0xa1 << 0xa2 << 0xa3 << 0xa4 << 0xa5 << 0xa6 << 0xa7 << 0xa8 << 0xa9 << 0xaa << 0xab << 0xac << 0xad << 0xae << 0xaf << 0xb0 << 0xb1 << 0xb2 << 0xb3 << 0xb4 << 0xb5 << 0xb6 << 0xb7 << 0xb8 << 0xb9 << 0xba << 0xbb << 0xbc << 0xbd << 0xbe << 0xbf << 0xc0 << 0xc1 << 0xc2 << 0xc3 << 0xc4 << 0xc5 << 0xc6 << 0xc7 << 0xc8 << 0xc9 << 0xca << 0xcb << 0xcc << 0xcd << 0xce << 0xcf << 0xd0 << 0xd1 << 0xd2 << 0xd3 << 0xd4 << 0xd5 << 0xd6 << 0xd7 << 0xd8 << 0xd9 << 0xda << 0xdb << 0xdc << 0xdd << 0xde << 0xdf << 0xe0 << 0xe1 << 0xe2 << 0xe3 << 0xe4 << 0xe5 << 0xe6 << 0xe7 << 0xe8 << 0xe9 << 0xea << 0xeb << 0xec << 0xed << 0xee << 0xef << 0xf0 << 0xf1 << 0xf2 << 0xf3 << 0xf4 << 0xf5 << 0xf6 << 0xf7 << 0xf8 << 0xf9 << 0xfa << 0xfb << 0xfc << 0xfd << 0xfe << 0xff ));
	virtual void __fastcall SetCurrentRecordIndex(int AIndex);
	
public:
	__fastcall TdxScrollbarAnnotations();
	__fastcall virtual ~TdxScrollbarAnnotations();
	void __fastcall AddRenderer(_di_IdxScrollbarAnnotationRenderer ARenderer);
	virtual void __fastcall Click(TdxScrollbarAnnotationRowIndexLists* AAnnotationRowIndexLists, bool &AHandled);
	int __fastcall GetDataScrollSize();
	virtual void __fastcall GetHint(TdxScrollbarAnnotationRowIndexLists* AAnnotationRowIndexLists, System::UnicodeString &AHint);
	virtual int __fastcall GetLastIndexInScrollBand(int ARecordIndex);
	virtual int __fastcall GetRecordPixelScrollPosition(int ARecordIndex);
	virtual int __fastcall GetScrollableRecordCount();
	virtual int __fastcall GetScrollableRecordIndexByRecordIndex(int AIndex);
	virtual TdxScrollbarAnnotationStyle __fastcall GetStyle(TdxScrollbarAnnotationKind AKind);
	void __fastcall InvalidateRenderers(const TdxScrollbarAnnotationKinds &AAnnotationKinds = (TdxScrollbarAnnotationKinds() << 0x0 << 0x1 << 0x2 << 0x3 << 0x4 << 0x5 << 0x6 << 0x7 << 0x8 << 0x9 << 0xa << 0xb << 0xc << 0xd << 0xe << 0xf << 0x10 << 0x11 << 0x12 << 0x13 << 0x14 << 0x15 << 0x16 << 0x17 << 0x18 << 0x19 << 0x1a << 0x1b << 0x1c << 0x1d << 0x1e << 0x1f << 0x20 << 0x21 << 0x22 << 0x23 << 0x24 << 0x25 << 0x26 << 0x27 << 0x28 << 0x29 << 0x2a << 0x2b << 0x2c << 0x2d << 0x2e << 0x2f << 0x30 << 0x31 << 0x32 << 0x33 << 0x34 << 0x35 << 0x36 << 0x37 << 0x38 << 0x39 << 0x3a << 0x3b << 0x3c << 0x3d << 0x3e << 0x3f << 0x40 << 0x41 << 0x42 << 0x43 << 0x44 << 0x45 << 0x46 << 0x47 << 0x48 << 0x49 << 0x4a << 0x4b << 0x4c << 0x4d << 0x4e << 0x4f << 0x50 << 0x51 << 0x52 << 0x53 << 0x54 << 0x55 << 0x56 << 0x57 << 0x58 << 0x59 << 0x5a << 0x5b << 0x5c << 0x5d << 0x5e << 0x5f << 0x60 << 0x61 << 0x62 << 0x63 << 0x64 << 0x65 << 0x66 << 0x67 << 0x68 << 0x69 << 0x6a << 0x6b << 0x6c << 0x6d << 0x6e << 0x6f << 0x70 << 0x71 << 0x72 << 0x73 << 0x74 << 0x75 << 0x76 << 0x77 << 0x78 << 0x79 << 0x7a << 0x7b << 0x7c << 0x7d << 0x7e << 0x7f << 0x80 << 0x81 << 0x82 << 0x83 << 0x84 << 0x85 << 0x86 << 0x87 << 0x88 << 0x89 << 0x8a << 0x8b << 0x8c << 0x8d << 0x8e << 0x8f << 0x90 << 0x91 << 0x92 << 0x93 << 0x94 << 0x95 << 0x96 << 0x97 << 0x98 << 0x99 << 0x9a << 0x9b << 0x9c << 0x9d << 0x9e << 0x9f << 0xa0 << 0xa1 << 0xa2 << 0xa3 << 0xa4 << 0xa5 << 0xa6 << 0xa7 << 0xa8 << 0xa9 << 0xaa << 0xab << 0xac << 0xad << 0xae << 0xaf << 0xb0 << 0xb1 << 0xb2 << 0xb3 << 0xb4 << 0xb5 << 0xb6 << 0xb7 << 0xb8 << 0xb9 << 0xba << 0xbb << 0xbc << 0xbd << 0xbe << 0xbf << 0xc0 << 0xc1 << 0xc2 << 0xc3 << 0xc4 << 0xc5 << 0xc6 << 0xc7 << 0xc8 << 0xc9 << 0xca << 0xcb << 0xcc << 0xcd << 0xce << 0xcf << 0xd0 << 0xd1 << 0xd2 << 0xd3 << 0xd4 << 0xd5 << 0xd6 << 0xd7 << 0xd8 << 0xd9 << 0xda << 0xdb << 0xdc << 0xdd << 0xde << 0xdf << 0xe0 << 0xe1 << 0xe2 << 0xe3 << 0xe4 << 0xe5 << 0xe6 << 0xe7 << 0xe8 << 0xe9 << 0xea << 0xeb << 0xec << 0xed << 0xee << 0xef << 0xf0 << 0xf1 << 0xf2 << 0xf3 << 0xf4 << 0xf5 << 0xf6 << 0xf7 << 0xf8 << 0xf9 << 0xfa << 0xfb << 0xfc << 0xfd << 0xfe << 0xff ));
	virtual bool __fastcall IsRecordIndexBasedRendering();
	bool __fastcall GoToNext(const TdxScrollbarAnnotationKinds &AKinds = (TdxScrollbarAnnotationKinds() << 0x0 << 0x1 << 0x2 << 0x3 << 0x4 << 0x5 << 0x6 << 0x7 << 0x8 << 0x9 << 0xa << 0xb << 0xc << 0xd << 0xe << 0xf << 0x10 << 0x11 << 0x12 << 0x13 << 0x14 << 0x15 << 0x16 << 0x17 << 0x18 << 0x19 << 0x1a << 0x1b << 0x1c << 0x1d << 0x1e << 0x1f << 0x20 << 0x21 << 0x22 << 0x23 << 0x24 << 0x25 << 0x26 << 0x27 << 0x28 << 0x29 << 0x2a << 0x2b << 0x2c << 0x2d << 0x2e << 0x2f << 0x30 << 0x31 << 0x32 << 0x33 << 0x34 << 0x35 << 0x36 << 0x37 << 0x38 << 0x39 << 0x3a << 0x3b << 0x3c << 0x3d << 0x3e << 0x3f << 0x40 << 0x41 << 0x42 << 0x43 << 0x44 << 0x45 << 0x46 << 0x47 << 0x48 << 0x49 << 0x4a << 0x4b << 0x4c << 0x4d << 0x4e << 0x4f << 0x50 << 0x51 << 0x52 << 0x53 << 0x54 << 0x55 << 0x56 << 0x57 << 0x58 << 0x59 << 0x5a << 0x5b << 0x5c << 0x5d << 0x5e << 0x5f << 0x60 << 0x61 << 0x62 << 0x63 << 0x64 << 0x65 << 0x66 << 0x67 << 0x68 << 0x69 << 0x6a << 0x6b << 0x6c << 0x6d << 0x6e << 0x6f << 0x70 << 0x71 << 0x72 << 0x73 << 0x74 << 0x75 << 0x76 << 0x77 << 0x78 << 0x79 << 0x7a << 0x7b << 0x7c << 0x7d << 0x7e << 0x7f << 0x80 << 0x81 << 0x82 << 0x83 << 0x84 << 0x85 << 0x86 << 0x87 << 0x88 << 0x89 << 0x8a << 0x8b << 0x8c << 0x8d << 0x8e << 0x8f << 0x90 << 0x91 << 0x92 << 0x93 << 0x94 << 0x95 << 0x96 << 0x97 << 0x98 << 0x99 << 0x9a << 0x9b << 0x9c << 0x9d << 0x9e << 0x9f << 0xa0 << 0xa1 << 0xa2 << 0xa3 << 0xa4 << 0xa5 << 0xa6 << 0xa7 << 0xa8 << 0xa9 << 0xaa << 0xab << 0xac << 0xad << 0xae << 0xaf << 0xb0 << 0xb1 << 0xb2 << 0xb3 << 0xb4 << 0xb5 << 0xb6 << 0xb7 << 0xb8 << 0xb9 << 0xba << 0xbb << 0xbc << 0xbd << 0xbe << 0xbf << 0xc0 << 0xc1 << 0xc2 << 0xc3 << 0xc4 << 0xc5 << 0xc6 << 0xc7 << 0xc8 << 0xc9 << 0xca << 0xcb << 0xcc << 0xcd << 0xce << 0xcf << 0xd0 << 0xd1 << 0xd2 << 0xd3 << 0xd4 << 0xd5 << 0xd6 << 0xd7 << 0xd8 << 0xd9 << 0xda << 0xdb << 0xdc << 0xdd << 0xde << 0xdf << 0xe0 << 0xe1 << 0xe2 << 0xe3 << 0xe4 << 0xe5 << 0xe6 << 0xe7 << 0xe8 << 0xe9 << 0xea << 0xeb << 0xec << 0xed << 0xee << 0xef << 0xf0 << 0xf1 << 0xf2 << 0xf3 << 0xf4 << 0xf5 << 0xf6 << 0xf7 << 0xf8 << 0xf9 << 0xfa << 0xfb << 0xfc << 0xfd << 0xfe << 0xff ),
		bool AGoForward = true, bool AGoOnCycle = false);
	void __fastcall RemoveRenderer(_di_IdxScrollbarAnnotationRenderer ARenderer);
	__property TdxScrollbarAnnotationKinds ChangedKinds = {read=FChangedKinds};
	__property int CurrentRecordIndex = {read=GetCurrentRecordIndex, write=SetCurrentRecordIndex, nodefault};
	__property TdxScrollbarAnnotationRowIndexLists* ItemLists = {read=FItemLists};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomScrollbarAnnotation : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	TdxScrollbarAnnotationStyle FStyle;
	bool FVisible;
	TdxScrollbarAnnotationAlignment __fastcall GetAlignment();
	Dxcoregraphics::TdxAlphaColor __fastcall GetColor();
	int __fastcall GetMaxHeight();
	int __fastcall GetMinHeight();
	int __fastcall GetOffset();
	int __fastcall GetWidth();
	bool __fastcall IsAlignmentStored();
	bool __fastcall IsMaxHeightStored();
	bool __fastcall IsMinHeightStored();
	bool __fastcall IsOffsetStored();
	bool __fastcall IsWidthStored();
	void __fastcall SetAlignment(const TdxScrollbarAnnotationAlignment Value);
	void __fastcall SetColor(const Dxcoregraphics::TdxAlphaColor Value);
	void __fastcall SetMaxHeight(int Value);
	void __fastcall SetMinHeight(int Value);
	void __fastcall SetOffset(int Value);
	void __fastcall SetStyle(const TdxScrollbarAnnotationStyle &Value);
	void __fastcall SetVisible(bool Value);
	void __fastcall SetWidth(int Value);
	
public:
	__fastcall virtual TdxCustomScrollbarAnnotation(System::Classes::TCollection* Collection);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TdxScrollbarAnnotationStyle Style = {read=FStyle, write=SetStyle};
	
__published:
	__property TdxScrollbarAnnotationAlignment Alignment = {read=GetAlignment, write=SetAlignment, stored=IsAlignmentStored, nodefault};
	__property Dxcoregraphics::TdxAlphaColor Color = {read=GetColor, write=SetColor, default=66051};
	__property int MaxHeight = {read=GetMaxHeight, write=SetMaxHeight, stored=IsMaxHeightStored, nodefault};
	__property int MinHeight = {read=GetMinHeight, write=SetMinHeight, stored=IsMinHeightStored, nodefault};
	__property int Offset = {read=GetOffset, write=SetOffset, stored=IsOffsetStored, nodefault};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
	__property int Width = {read=GetWidth, write=SetWidth, stored=IsWidthStored, nodefault};
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TdxCustomScrollbarAnnotation() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomScrollbarAnnotations : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	TdxCustomScrollbarAnnotation* operator[](int Index) { return this->Items[Index]; }
	
private:
	TdxScrollbarAnnotationOptions* FOwner;
	
private:
	HIDESBASE TdxCustomScrollbarAnnotation* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TdxCustomScrollbarAnnotation* const Value);
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner();
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	
public:
	__fastcall virtual TdxCustomScrollbarAnnotations(TdxScrollbarAnnotationOptions* AOwner);
	HIDESBASE TdxCustomScrollbarAnnotation* __fastcall Add();
	__property TdxCustomScrollbarAnnotation* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TdxCustomScrollbarAnnotations() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxScrollbarAnnotationOptions : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::StaticArray<bool, 5> FStates;
	TdxCustomScrollbarAnnotations* FCustomScrollbarAnnotations;
	void __fastcall SetCustomScrollbarAnnotations(TdxCustomScrollbarAnnotations* const Value);
	TdxCustomScrollbarAnnotations* __fastcall GetCustomScrollbarAnnotations();
	
protected:
	virtual void __fastcall Changed();
	virtual void __fastcall CheckScrollbarAnnotations();
	virtual bool __fastcall GetDefaultValue(int Index);
	bool __fastcall GetValue(int Index);
	virtual TdxScrollbarAnnotationStyle __fastcall GetStyle(TdxScrollbarAnnotationKind AKind);
	virtual bool __fastcall IsVisible(int AKind);
	virtual void __fastcall RefreshScrollbarAnnotations(const TdxScrollbarAnnotationKinds &AChangedAnnotationKinds = (TdxScrollbarAnnotationKinds() << 0x0 << 0x1 << 0x2 << 0x3 << 0x4 << 0x5 << 0x6 << 0x7 << 0x8 << 0x9 << 0xa << 0xb << 0xc << 0xd << 0xe << 0xf << 0x10 << 0x11 << 0x12 << 0x13 << 0x14 << 0x15 << 0x16 << 0x17 << 0x18 << 0x19 << 0x1a << 0x1b << 0x1c << 0x1d << 0x1e << 0x1f << 0x20 << 0x21 << 0x22 << 0x23 << 0x24 << 0x25 << 0x26 << 0x27 << 0x28 << 0x29 << 0x2a << 0x2b << 0x2c << 0x2d << 0x2e << 0x2f << 0x30 << 0x31 << 0x32 << 0x33 << 0x34 << 0x35 << 0x36 << 0x37 << 0x38 << 0x39 << 0x3a << 0x3b << 0x3c << 0x3d << 0x3e << 0x3f << 0x40 << 0x41 << 0x42 << 0x43 << 0x44 << 0x45 << 0x46 << 0x47 << 0x48 << 0x49 << 0x4a << 0x4b << 0x4c << 0x4d << 0x4e << 0x4f << 0x50 << 0x51 << 0x52 << 0x53 << 0x54 << 0x55 << 0x56 << 0x57 << 0x58 << 0x59 << 0x5a << 0x5b << 0x5c << 0x5d << 0x5e << 0x5f << 0x60 << 0x61 << 0x62 << 0x63 << 0x64 << 0x65 << 0x66 << 0x67 << 0x68 << 0x69 << 0x6a << 0x6b << 0x6c << 0x6d << 0x6e << 0x6f << 0x70 << 0x71 << 0x72 << 0x73 << 0x74 << 0x75 << 0x76 << 0x77 << 0x78 << 0x79 << 0x7a << 0x7b << 0x7c << 0x7d << 0x7e << 0x7f << 0x80 << 0x81 << 0x82 << 0x83 << 0x84 << 0x85 << 0x86 << 0x87 << 0x88 << 0x89 << 0x8a << 0x8b << 0x8c << 0x8d << 0x8e << 0x8f << 0x90 << 0x91 << 0x92 << 0x93 << 0x94 << 0x95 << 0x96 << 0x97 << 0x98 << 0x99 << 0x9a << 0x9b << 0x9c << 0x9d << 0x9e << 0x9f << 0xa0 << 0xa1 << 0xa2 << 0xa3 << 0xa4 << 0xa5 << 0xa6 << 0xa7 << 0xa8 << 0xa9 << 0xaa << 0xab << 0xac << 0xad << 0xae << 0xaf << 0xb0 << 0xb1 << 0xb2 << 0xb3 << 0xb4 << 0xb5 << 0xb6 << 0xb7 << 0xb8 << 0xb9 << 0xba << 0xbb << 0xbc << 0xbd << 0xbe << 0xbf << 0xc0 << 0xc1 << 0xc2 << 0xc3 << 0xc4 << 0xc5 << 0xc6 << 0xc7 << 0xc8 << 0xc9 << 0xca << 0xcb << 0xcc << 0xcd << 0xce << 0xcf << 0xd0 << 0xd1 << 0xd2 << 0xd3 << 0xd4 << 0xd5 << 0xd6 << 0xd7 << 0xd8 << 0xd9 << 0xda << 0xdb << 0xdc << 0xdd << 0xde << 0xdf << 0xe0 << 0xe1 << 0xe2 << 0xe3 << 0xe4 << 0xe5 << 0xe6 << 0xe7 << 0xe8 << 0xe9 << 0xea << 0xeb << 0xec << 0xed << 0xee << 0xef << 0xf0 << 0xf1 << 0xf2 << 0xf3 << 0xf4 << 0xf5 << 0xf6 << 0xf7 << 0xf8 << 0xf9 << 0xfa << 0xfb << 0xfc << 0xfd << 0xfe << 0xff ));
	virtual void __fastcall SetValue(int Index, bool Value);
	__property bool Active = {read=GetValue, write=SetValue, index=0, nodefault};
	__property TdxCustomScrollbarAnnotations* CustomAnnotations = {read=GetCustomScrollbarAnnotations, write=SetCustomScrollbarAnnotations};
	__property bool ShowErrors = {read=GetValue, write=SetValue, index=4, nodefault};
	__property bool ShowSearchResults = {read=GetValue, write=SetValue, index=3, nodefault};
	__property bool ShowFocusedRow = {read=GetValue, write=SetValue, index=2, nodefault};
	__property bool ShowSelectedRows = {read=GetValue, write=SetValue, index=1, nodefault};
	
public:
	__fastcall TdxScrollbarAnnotationOptions();
	__fastcall virtual ~TdxScrollbarAnnotationOptions();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static const System::Int8 dxFirstScrollbarAnnotationID = System::Int8(0x0);
static const System::Byte dxFirstPredefinedScrollbarAnnotationID = System::Byte(0xf0);
static const System::Byte dxSelectedRowScrollbarAnnotationID = System::Byte(0xf0);
static const System::Byte dxFocusedRowScrollbarAnnotationID = System::Byte(0xf1);
static const System::Byte dxSearchResultScrollbarAnnotationID = System::Byte(0xf2);
static const System::Byte dxErrorScrollbarAnnotationID = System::Byte(0xf3);
static const System::Byte dxLastScrollbarAnnotationID = System::Byte(0xff);
#define dxAllScrollbarAnnotationKinds (System::Set<System::Byte, 0, 255>() << 0x0 << 0x1 << 0x2 << 0x3 << 0x4 << 0x5 << 0x6 << 0x7 << 0x8 << 0x9 << 0xa << 0xb << 0xc << 0xd << 0xe << 0xf << 0x10 << 0x11 << 0x12 << 0x13 << 0x14 << 0x15 << 0x16 << 0x17 << 0x18 << 0x19 << 0x1a << 0x1b << 0x1c << 0x1d << 0x1e << 0x1f << 0x20 << 0x21 << 0x22 << 0x23 << 0x24 << 0x25 << 0x26 << 0x27 << 0x28 << 0x29 << 0x2a << 0x2b << 0x2c << 0x2d << 0x2e << 0x2f << 0x30 << 0x31 << 0x32 << 0x33 << 0x34 << 0x35 << 0x36 << 0x37 << 0x38 << 0x39 << 0x3a << 0x3b << 0x3c << 0x3d << 0x3e << 0x3f << 0x40 << 0x41 << 0x42 << 0x43 << 0x44 << 0x45 << 0x46 << 0x47 << 0x48 << 0x49 << 0x4a << 0x4b << 0x4c << 0x4d << 0x4e << 0x4f << 0x50 << 0x51 << 0x52 << 0x53 << 0x54 << 0x55 << 0x56 \
	<< 0x57 << 0x58 << 0x59 << 0x5a << 0x5b << 0x5c << 0x5d << 0x5e << 0x5f << 0x60 << 0x61 << 0x62 << 0x63 << 0x64 << 0x65 << 0x66 << 0x67 << 0x68 << 0x69 << 0x6a << 0x6b << 0x6c << 0x6d << 0x6e << 0x6f << 0x70 << 0x71 << 0x72 << 0x73 << 0x74 << 0x75 << 0x76 << 0x77 << 0x78 << 0x79 << 0x7a << 0x7b << 0x7c << 0x7d << 0x7e << 0x7f << 0x80 << 0x81 << 0x82 << 0x83 << 0x84 << 0x85 << 0x86 << 0x87 << 0x88 << 0x89 << 0x8a << 0x8b << 0x8c << 0x8d << 0x8e << 0x8f << 0x90 << 0x91 << 0x92 << 0x93 << 0x94 << 0x95 << 0x96 << 0x97 << 0x98 << 0x99 << 0x9a << 0x9b << 0x9c << 0x9d << 0x9e << 0x9f << 0xa0 << 0xa1 << 0xa2 << 0xa3 << 0xa4 << 0xa5 << 0xa6 << 0xa7 << 0xa8 << 0xa9 << 0xaa << 0xab << 0xac << 0xad << 0xae << 0xaf << 0xb0 << 0xb1 << 0xb2 << 0xb3 << 0xb4 \
	<< 0xb5 << 0xb6 << 0xb7 << 0xb8 << 0xb9 << 0xba << 0xbb << 0xbc << 0xbd << 0xbe << 0xbf << 0xc0 << 0xc1 << 0xc2 << 0xc3 << 0xc4 << 0xc5 << 0xc6 << 0xc7 << 0xc8 << 0xc9 << 0xca << 0xcb << 0xcc << 0xcd << 0xce << 0xcf << 0xd0 << 0xd1 << 0xd2 << 0xd3 << 0xd4 << 0xd5 << 0xd6 << 0xd7 << 0xd8 << 0xd9 << 0xda << 0xdb << 0xdc << 0xdd << 0xde << 0xdf << 0xe0 << 0xe1 << 0xe2 << 0xe3 << 0xe4 << 0xe5 << 0xe6 << 0xe7 << 0xe8 << 0xe9 << 0xea << 0xeb << 0xec << 0xed << 0xee << 0xef << 0xf0 << 0xf1 << 0xf2 << 0xf3 << 0xf4 << 0xf5 << 0xf6 << 0xf7 << 0xf8 << 0xf9 << 0xfa << 0xfb << 0xfc << 0xfd << 0xfe << 0xff )
#define dxAllCustomScrollbarAnnotationKinds (System::Set<System::Byte, 0, 255>() << 0x0 << 0x1 << 0x2 << 0x3 << 0x4 << 0x5 << 0x6 << 0x7 << 0x8 << 0x9 << 0xa << 0xb << 0xc << 0xd << 0xe << 0xf << 0x10 << 0x11 << 0x12 << 0x13 << 0x14 << 0x15 << 0x16 << 0x17 << 0x18 << 0x19 << 0x1a << 0x1b << 0x1c << 0x1d << 0x1e << 0x1f << 0x20 << 0x21 << 0x22 << 0x23 << 0x24 << 0x25 << 0x26 << 0x27 << 0x28 << 0x29 << 0x2a << 0x2b << 0x2c << 0x2d << 0x2e << 0x2f << 0x30 << 0x31 << 0x32 << 0x33 << 0x34 << 0x35 << 0x36 << 0x37 << 0x38 << 0x39 << 0x3a << 0x3b << 0x3c << 0x3d << 0x3e << 0x3f << 0x40 << 0x41 << 0x42 << 0x43 << 0x44 << 0x45 << 0x46 << 0x47 << 0x48 << 0x49 << 0x4a << 0x4b << 0x4c << 0x4d << 0x4e << 0x4f << 0x50 << 0x51 << 0x52 << 0x53 << 0x54 << 0x55 \
	<< 0x56 << 0x57 << 0x58 << 0x59 << 0x5a << 0x5b << 0x5c << 0x5d << 0x5e << 0x5f << 0x60 << 0x61 << 0x62 << 0x63 << 0x64 << 0x65 << 0x66 << 0x67 << 0x68 << 0x69 << 0x6a << 0x6b << 0x6c << 0x6d << 0x6e << 0x6f << 0x70 << 0x71 << 0x72 << 0x73 << 0x74 << 0x75 << 0x76 << 0x77 << 0x78 << 0x79 << 0x7a << 0x7b << 0x7c << 0x7d << 0x7e << 0x7f << 0x80 << 0x81 << 0x82 << 0x83 << 0x84 << 0x85 << 0x86 << 0x87 << 0x88 << 0x89 << 0x8a << 0x8b << 0x8c << 0x8d << 0x8e << 0x8f << 0x90 << 0x91 << 0x92 << 0x93 << 0x94 << 0x95 << 0x96 << 0x97 << 0x98 << 0x99 << 0x9a << 0x9b << 0x9c << 0x9d << 0x9e << 0x9f << 0xa0 << 0xa1 << 0xa2 << 0xa3 << 0xa4 << 0xa5 << 0xa6 << 0xa7 << 0xa8 << 0xa9 << 0xaa << 0xab << 0xac << 0xad << 0xae << 0xaf << 0xb0 << 0xb1 << 0xb2 << 0xb3 \
	<< 0xb4 << 0xb5 << 0xb6 << 0xb7 << 0xb8 << 0xb9 << 0xba << 0xbb << 0xbc << 0xbd << 0xbe << 0xbf << 0xc0 << 0xc1 << 0xc2 << 0xc3 << 0xc4 << 0xc5 << 0xc6 << 0xc7 << 0xc8 << 0xc9 << 0xca << 0xcb << 0xcc << 0xcd << 0xce << 0xcf << 0xd0 << 0xd1 << 0xd2 << 0xd3 << 0xd4 << 0xd5 << 0xd6 << 0xd7 << 0xd8 << 0xd9 << 0xda << 0xdb << 0xdc << 0xdd << 0xde << 0xdf << 0xe0 << 0xe1 << 0xe2 << 0xe3 << 0xe4 << 0xe5 << 0xe6 << 0xe7 << 0xe8 << 0xe9 << 0xea << 0xeb << 0xec << 0xed << 0xee << 0xef )
extern DELPHI_PACKAGE TdxScrollbarAnnotationStyle dxSelectedRowScrollbarAnnotationStyle;
extern DELPHI_PACKAGE TdxScrollbarAnnotationStyle dxFocusedRowScrollbarAnnotationStyle;
extern DELPHI_PACKAGE TdxScrollbarAnnotationStyle dxSearchResultScrollbarAnnotationStyle;
extern DELPHI_PACKAGE TdxScrollbarAnnotationStyle dxErrorScrollbarAnnotationStyle;
extern DELPHI_PACKAGE TdxScrollbarAnnotationStyle dxCustomScrollbarAnnotationStyle;
}	/* namespace Dxscrollbarannotations */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSCROLLBARANNOTATIONS)
using namespace Dxscrollbarannotations;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxscrollbarannotationsHPP
