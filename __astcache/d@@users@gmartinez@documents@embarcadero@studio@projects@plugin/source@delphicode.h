﻿//---------------------------------------------------------------------------

#ifndef DelphiCodeH
#define DelphiCodeH

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx // Zero-length empty class member
#pragma pack( push, 8 )
#include <System.hpp>
#include <SysInit.hpp>
#include <Vcl.Forms.hpp>
#include <libloaderapi.h>
//---------------------------------------------------------------------------

namespace DelphiCode
{
	__interface TExpertManagerExpert;
	typedef System::DelphiInterface<TExpertManagerExpert> _di_TExpertManagerExpert;
	__interface TAddExpertToRegistryResult;
	typedef System::DelphiInterface<TAddExpertToRegistryResult> _di_TAddExpertToRegistryResult;
	class DELPHICLASS TMyDelphiClass;

	__interface TAddExpertToRegistryResult :
		public System::IInterface {

		};

	__interface TExpertManagerExpert : public System::IInterface
	{
		virtual _di_TAddExpertToRegistryResult __fastcall AddExpertToRegistry( const std::string ExpertName, std::string FileName ) = 0;
	};

		/*typedef void( __stdcall *InstallGExpertsPtr )( HWND, HINST, char *, Integer );
		HMODULE hModule = NULL;
		GetModuleHandleEx(																		   //
			GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, //
			(LPCTSTR) GetCurrentModule, &hModule );
		InstallGExpertsPtr InstallGExperts = (InstallGExpertsPtr) GetProcAddress( hModule, "InstallGExperts" );     */

		// static void __fastcall InstallGExperts( HWND Handle, HINST InstHandle, PAnsiChar CmdLine, Integer CmdShow );

#pragma pack( push, 4 )
#pragma pack( pop )

	extern DELPHI_PACKAGE void __fastcall Create( void );
}; // namespace DelphiCode

#if !defined( DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE ) && !defined( NO_USING_NAMESPACE_DELPHICODE )
using namespace DelphiCode;
#endif
#pragma pack( pop )
#pragma option pop

#pragma delphiheader end.

#endif
