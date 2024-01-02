﻿#pragma hdrstop
#include "CPPOTATemplateSplashScreen.h"
#include "windows.h"
#include "CPPOTATemplateConstants.h"

#include "SysInit.hpp"
#include <design/ToolsAPI.hpp>
#include "Forms.hpp"
#include "SysUtils.hpp"
#include "Vcl.Graphics.hpp"
#include "CPPOTATemplateFunctions.h"
#include "winuser.h"

#pragma package( smart_init )

//: @note IFNDEF not required anymore
//: #ifndef DLL
void __fastcall AddSplashScreen( )
{
	int iMajor;
	int iMinor;
	int iBugFix;
	int iBuild;
	HBITMAP bmSplashScreen;
	_di_IOTASplashScreenServices SSServices;
	BuildNumber( iMajor, iMinor, iBugFix, iBuild );
	std::string rc = "CPPOTATemplateSplashScreenBitMap24x24";
	bmSplashScreen = LoadBitmap( HInstance, rc.c_str( ) );
	TBitmap *m = new TBitmap( );
	m->Handle = bmSplashScreen;
	TGraphic *g = m;
	TGraphicArray array;
	array.set_length( 1 );
	array[ 0 ] = g;
	if ( SplashScreenServices->Supports( SSServices ) ) {
		String strRev = strRevision[ iBugFix ];
		SSServices->AddPluginBitmap(
			//
			Format( strSplashScreenName, ARRAYOFCONST( ( iMajor, iMinor, strRev, Application->Title ) ) ),
			//
			array,
			//
			False,
			//
			Format( strSplashScreenBuild, ARRAYOFCONST( ( iMajor, iMinor, iBugFix, iBuild ) ) )
			//
		);
		Sleep( 2000 ); //: @debug Here to pause splash screen to check icon
	}
}
//: #endif

