﻿//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DoxygenForm.h"
#include <sys/stat.h>
//---------------------------------------------------------------------------
#pragma package( smart_init )
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxTextEdit"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1( TComponent *Owner ): TForm( Owner )
{
	configPath = L"";
	filesPath = L"";
	UMLDiagrams = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonOKClick( TObject *Sender )
{
	std::wstring ws;
	std::string ssConfig, ssFiles;
	int res;
	System::UnicodeString mssError;
	const wchar_t *widecstr;
	std::string cmd1, cmd2, cmd3, cmd4, cmd5, cmd6, cmd7, cmd8, cmd9, cmd10, cmd11, cmd12, cmd13, cmd14, cmd15, cmd16, cmd17, cmd18, cmd19, cmd20, cmd21, cmd22;
	// TCHAR buffer[ MAX_PATH ] = { 0 };

	configPath = cxTextEditPathConfig->Text;
	ws = configPath.c_str( );
	ssConfig.resize( ws.length( ) );
	wcstombs( &ssConfig[ 0 ], ws.c_str( ), ws.size( ) );

	// std::string str( buffer );
	// std::string::size_type pos = str.find_last_of( "\\/" );
	filesPath = cxTextEditPathFiles->Text; // str.substr( 0, pos );
	ws = filesPath.c_str( );
	ssFiles.resize( ws.length( ) );
	wcstombs( &ssFiles[ 0 ], ws.c_str( ), ws.size( ) );

	if ( ssConfig.back( ) == '\\' ) {
		ssConfig.pop_back( );
	}
	if ( ssFiles.back( ) == '\\' ) {
		ssFiles.pop_back( );
	}

	// std::string path = ssExe; // str.substr( 0, pos );
	cmd1 = "cd " + ssConfig;
	cmd2 = "doxygen.exe -g Doxyfile";
	cmd3 = "echo INPUT=" + ssFiles + " >> Doxyfile";
	cmd4 = "echo OUTPUT_DIRECTORY=" + ssConfig + "\\docs >> Doxyfile";
	cmd5 = "echo GENERATE_HTML=YES >> Doxyfile";
	cmd6 = "echo GENERATE_LATEX=NO >> Doxyfile";
	cmd7 = "echo RECURSIVE=YES >> Doxyfile";
	cmd8 = "echo FILE_PATTERNS= *.c \ *.cpp \ *.h >> Doxyfile";
	cmd9 = "echo EXTRACT_ALL=YES >> Doxyfile";

	cmd10 = "echo HAVE_DOT=YES >> Doxyfile";
	cmd11 = "echo HIDE_UNDOC_RELATIONS=NO >> Doxyfile";
	cmd12 = "echo CLASS_GRAPH=YES >> Doxyfile";
	cmd13 = "echo COLLABORATION_GRAPH=YES >> Doxyfile";
	cmd14 = "echo UML_LOOK=YES >> Doxyfile";
	cmd15 = "echo UML_LIMIT_NUM_FIELDS=50 >> Doxyfile";
	cmd16 = "echo TEMPLATE_RELATIONS=YES >> Doxyfile";
	cmd17 = "echo DOT_IMAGE_FORMAT=svg >> Doxyfile";
	cmd18 = "echo INTERACTIVE_SVG=YES >> Doxyfile";
	cmd19 = "echo DOT_GRAPH_MAX_NODES=100 >> Doxyfile";
	cmd20 = "echo MAX_DOT_GRAPH_DEPTH=2 >> Doxyfile";

	cmd21 = "doxygen.exe Doxyfile";
	cmd22 = ssConfig + "\\docs\\html\\index.html";

	system( ( cmd1 + " & " + cmd2 ).c_str( ) );

	struct stat buff;
	if ( stat( ( ssConfig + "\\Doxyfile" ).c_str( ), &buff ) == 0 ) {
		if ( UMLDiagrams ) {
			if ( res = ( system( ( cmd1 + " & " + cmd3 + " & " + cmd4 + " & " + cmd5 + " & " + cmd6 + " & " + cmd7 + " & " + cmd8 + " & " + cmd9 + " & " + cmd10 + " & " + cmd11 + " & " + cmd12 + " & " + cmd13 + " & " + cmd14 + " & " + cmd15 + " & " + cmd16 + " & " + cmd17 + " & " + cmd18 + " & " + cmd19 + " & " + cmd20 + " & " + cmd21 ).c_str( ) ) == 0 ) ) {
				system( ( cmd1 + " & " + cmd22 ).c_str( ) );
			}
		} else {
			if ( res = ( system( ( cmd1 + " & " + cmd3 + " & " + cmd4 + " & " + cmd5 + " & " + cmd6 + " & " + cmd7 + " & " + cmd8 + " & " + cmd9 + " & " + cmd21 ).c_str( ) ) == 0 ) ) {
				system( ( cmd1 + " & " + cmd22 ).c_str( ) );
			}
		}

		if ( res != 1 ) {
			mssError = L"No se ha podido crear la documentación.";
			widecstr = std::wstring( mssError.begin( ), mssError.end( ) ).c_str( );
			Application->MessageBox( widecstr, 0, MB_OK | MB_ICONERROR );
		}

		//	res = system( ( cmd1 + " & " + cmd2 + " & " + cmd3 + " & " + cmd4 + " & " + cmd5 + " & " + cmd6 + " & " + cmd7 + " & " + cmd8 + " & " + cmd9 ).c_str( ) );

		this->Close( );
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonSearchFolderConfig( TObject *Sender )
{
	BROWSEINFO bi;
	std::wstring ws;
	std::string ss;
	char lpBuffer[ MAX_PATH ];

	memset( &bi, 0, sizeof( BROWSEINFO ) );
	bi.hwndOwner = this->Handle;
	bi.pidlRoot = NULL;
	bi.pszDisplayName = lpBuffer;
	bi.lpszTitle = "Choose a folder contains files to comment.";
	bi.lpfn = NULL;
	bi.lParam = 0;
	bi.ulFlags = BIF_RETURNONLYFSDIRS | BIF_NEWDIALOGSTYLE | BIF_EDITBOX;

	ws = cxTextEditPathConfig->Text.c_str( );
	ss.resize( ws.length( ) );
	wcstombs( &ss[ 0 ], ws.c_str( ), ws.size( ) );

	// Browse for a folder and return its PIDL.
	LPITEMIDLIST pidlBrowse = SHBrowseForFolder( &bi );
	if ( pidlBrowse != NULL ) {
		char dirPath[ MAX_PATH ] = "";
		SHGetPathFromIDList( pidlBrowse, dirPath );
		// ShowMessage( dirPath );
		cxTextEditPathConfig->Text = dirPath;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonSearchFolderFiles( TObject *Sender )
{
	BROWSEINFO bi;
	std::wstring ws;
	std::string ss;
	char lpBuffer[ MAX_PATH ];

	memset( &bi, 0, sizeof( BROWSEINFO ) );
	bi.hwndOwner = this->Handle;
	bi.pidlRoot = NULL;
	bi.pszDisplayName = lpBuffer;
	bi.lpszTitle = "Choose a folder contains files to comment.";
	bi.lpfn = NULL;
	bi.lParam = 0;
	bi.ulFlags = BIF_RETURNONLYFSDIRS | BIF_NEWDIALOGSTYLE | BIF_EDITBOX;

	ws = cxTextEditPathFiles->Text.c_str( );
	ss.resize( ws.length( ) );
	wcstombs( &ss[ 0 ], ws.c_str( ), ws.size( ) );

	// Browse for a folder and return its PIDL.
	LPITEMIDLIST pidlBrowse = SHBrowseForFolder( &bi );
	if ( pidlBrowse != NULL ) {
		char dirPath[ MAX_PATH ] = "";
		SHGetPathFromIDList( pidlBrowse, dirPath );
		// ShowMessage( dirPath );
		cxTextEditPathFiles->Text = dirPath;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBoxUMLClick( TObject *Sender )
{
	UMLDiagrams = CheckBoxUML->Checked;
}
//---------------------------------------------------------------------------

