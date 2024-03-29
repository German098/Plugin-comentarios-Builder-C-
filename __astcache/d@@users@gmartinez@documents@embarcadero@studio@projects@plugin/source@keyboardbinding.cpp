﻿//---------------------------------------------------------------------------

#pragma hdrstop

#include "KeyboardBinding.h"
//#include "WrapperParserDebug.h"
#include "LineNotifier.h"
#include "CPPOTATemplateMacros.h"
#include "WrapperParser.h"
#include "CPPOTATemplateConstants.h"

#include <sstream>
//---------------------------------------------------------------------------
#pragma package( smart_init )

// class TKeyboardBinding

__fastcall TKeyboardBinding::TKeyboardBinding( TShortCut *keys, int nSK ) /*: TDGHNotifierObject( "TKeyboardBinding" )*/
{
	this->keys = keys;
	// this->lastShortKey = TypeCommentBlock::None;
	this->numShortKeys = nSK;
	// list = new TInterfaceList( );
}

__fastcall TKeyboardBinding::TKeyboardBinding( ) /*: TDGHNotifierObject( "TKeyboardBinding" ) */
{
	this->keys = 0;
	this->numShortKeys = 0;
}

__fastcall TKeyboardBinding::~TKeyboardBinding( )
{
}

TBindingType __fastcall TKeyboardBinding::GetBindingType( )
{
	return TBindingType::btPartial;
}

System::UnicodeString __fastcall TKeyboardBinding::GetDisplayName( )
{
	return L"Debugging Tools Bindings";
}

System::UnicodeString __fastcall TKeyboardBinding::GetName( )
{
	return L"DebuggingToolsBindings";
}

void __fastcall TKeyboardBinding::BindKeyboard( const _di_IOTAKeyBindingServices BindingServices )
{
	BindingServices->AddKeyBinding( &keys[ 0 ], 0, addCommentarySelectedText, 0 );
}

System::UnicodeString __fastcall readEOF( _di_IOTAEditPosition EditPosition )
{
	int currnetRow = EditPosition->GetRow( );
	int nCharacters = 0;
	System::UnicodeString text, row;

	while ( currnetRow++ != EditPosition->GetLastRow( ) ) {
		EditPosition->GotoLine( currnetRow );
		EditPosition->MoveEOL( );
		nCharacters = EditPosition->GetColumn( );
		EditPosition->MoveBOL( );
		row = EditPosition->Read( nCharacters );
		text += row;
	}

	return text;
}

bool readUpToDelimiter2( _di_IOTAEditPosition EditPosition, _di_IOTAEditBlock IOTAEditBlock )
{
	System::UnicodeString del1 = "// ---";
	System::UnicodeString del2 = "//---";
	int del_length1 = del1.Length( );
	int del_length2 = del2.Length( );
	System::UnicodeString text;
	int posLastChar;

	// EditPosition->Save( );
	int lastRow = EditPosition->GetLastRow( );
	int currentRow = EditPosition->GetRow( );
	EditPosition->MoveBOL( );
	IOTAEditBlock->BeginBlock( );
	while ( currentRow <= EditPosition->GetLastRow( ) ) {
		int xxx = EditPosition->GetRow( );
		EditPosition->MoveEOL( );
		int xx = EditPosition->GetRow( );
		while ( EditPosition->GetRow( ) > currentRow ) {
			EditPosition->MoveBOL( );
			System::WideChar chr = EditPosition->GetCharacter( );
			EditPosition->MoveEOL( );
			currentRow++;
		}
		/*if ( EditPosition->GetRow( ) > currentRow ) {
			EditPosition->MoveBOL( );
			System::WideChar chr = EditPosition->GetCharacter( );
			EditPosition->MoveEOL( );
			currentRow++;
		}*/
		posLastChar = EditPosition->GetColumn( );
		EditPosition->MoveBOL( );
		int xx2 = EditPosition->GetRow( );
		text = EditPosition->Read( posLastChar );

		System::UnicodeString S1 = text.SubString( 0, del_length1 - 1 );
		System::UnicodeString S2 = text.SubString( 0, del_length2 - 1 );
		if ( text.SubString( 0, del_length1 ) == del1 || text.SubString( 0, del_length2 ) == del2 ) {
			// EditPosition->Restore( );
			// EditPosition->MoveReal( EditPosition->GetRow( ) - 1, 1 );
			int actualRow = EditPosition->GetRow( );
			int actualCol = EditPosition->GetColumn( );
			IOTAEditBlock->EndBlock( );
			int blockLine1 = IOTAEditBlock->GetStartingRow( );
			int blockLine2 = IOTAEditBlock->GetEndingRow( );

			break;
		}

		if ( ++currentRow <= EditPosition->GetLastRow( ) ) {
			EditPosition->Move( currentRow, 1 );
		}
	}

	IOTAEditBlock->EndBlock( );

	return true;
}

bool readUpToDelimiter( _di_IOTAEditPosition EditPosition, System::UnicodeString &currentText, int &currentRow, int lastRow )
{
	System::UnicodeString del1 = "// ---";
	System::UnicodeString del2 = "//---";
	int del_length1 = del1.Length( );
	int del_length2 = del2.Length( );
	System::UnicodeString text = "", aux;
	unsigned int tab_magnitude = 4;
	int i = 0;
	int characteres = 0;

	currentText = "";
	EditPosition->GotoLine( currentRow );
	System::WideChar prev_ch = ' ';
	int contTabs = 0;
	while ( currentRow <= lastRow /*EditPosition->GetLastRow( )*/ ) {
		// EditPosition->MoveEOL( );
		// int characteres = EditPosition->GetColumn( );
		EditPosition->MoveBOL( );
		characteres = 0;
		int col = 1;
		prev_ch = ' ';
		contTabs = 0;
		while ( EditPosition->GetCharacter( ) != '\r' ) {
			System::WideChar ch = EditPosition->GetCharacter( );
			if ( prev_ch == '\t' && ch == '\t' ) {
				contTabs++;
			}

			int r = EditPosition->GetRow( );
			int c = col;
			EditPosition->Move( EditPosition->GetRow( ), ++col );
			if ( ch != '\t' || /*( ch == '\t' && prev_ch != '\t' )*/ ( contTabs % 4 ) == 0 ) {
				characteres++;
			}
			prev_ch = ch;
		}
		characteres++;
		EditPosition->MoveBOL( );
		text = EditPosition->Read( characteres + 1 );
		if ( ( aux = text.SubString( 0, del_length1 ) ) == del1 || ( aux = text.SubString( 0, del_length2 ) ) == del2 ) {
			return true; // false;
		}
		currentText += text;
		i += text.Length( );
		currentRow++;
		EditPosition->GotoLine( currentRow );
	}

	return false;
}

bool processCommentary2( _di_IOTAEditPosition EditPosition, _di_IOTAEditBlock IOTAEditBlock )
{
	System::UnicodeString mssError, currentText;
	std::wstring wsin;
	std::string in;
	char *out, *str;
	unsigned int out_size;
	bool EOBlock = true;
	typedef int( __stdcall * func )( char *, unsigned int, char *&, unsigned int &, bool & );
	HMODULE hMod;
	func pFunc;
	const wchar_t *widecstr;
	int initRow, endRow;
	bool codeInComment;

	initRow = IOTAEditBlock->GetStartingRow( );
	endRow = IOTAEditBlock->GetEndingRow( );

	ShowMessage( "Cargar DLL" );

	hMod = LoadLibrary( dllWrapper );
	pFunc = (func) GetProcAddress( hMod, "parseString" );

	std::stringstream ss;
	ss << pFunc;
	std::string sss = "Dirección función de la DLL " + ss.str( );
	ShowMessage( sss.c_str( ) );

	if ( !pFunc ) {
		mssError = L"No se ha podido acceder a la función de WrapperParserDebug.";
		widecstr = std::wstring( mssError.begin( ), mssError.end( ) ).c_str( );
		Application->MessageBox( widecstr, 0, MB_OK | MB_ICONERROR );
	}

	currentText = IOTAEditBlock->GetText( );
	wsin = currentText.c_str( );
	in.resize( wsin.length( ) );
	wcstombs( &in[ 0 ], wsin.c_str( ), wsin.size( ) );
	str = new char[ in.length( ) + 1 ];
	strcpy_s( str, in.size( ) + 1, in.c_str( ) );
	out = 0;
	out_size = 0;

	if ( currentText != L"" ) {
		( pFunc )( str, (unsigned int) in.length( ), out, out_size, codeInComment );
		// parseString( str, (unsigned int) in.length( ), out, out_size, codeInComment );
	}

	if ( currentText != L"" && !out ) {
		EOBlock = readUpToDelimiter2( EditPosition, IOTAEditBlock );

		int eb1 = IOTAEditBlock->GetStartingRow( );
		int eb2 = IOTAEditBlock->GetEndingRow( );
		currentText = IOTAEditBlock->GetText( );
		wsin = currentText.c_str( );
		in.resize( wsin.length( ) );
		wcstombs( &in[ 0 ], wsin.c_str( ), wsin.size( ) );
		str = new char[ in.length( ) + 1 ];
		strcpy_s( str, in.size( ) + 1, in.c_str( ) );
		out = 0;
		out_size = 0;

		( pFunc )( str, (unsigned int) in.length( ), out, out_size, codeInComment );
		// parseString( str, (unsigned int) in.length( ), out, out_size, codeInComment );

		/*EditPosition->Save( );
		for ( int i = 0; i < out_size; i++ ) {
			System::WideChar ch = out[ i ];
			if ( ch == '\r' ) {
				EditPosition->InsertCharacter( ch );
				EditPosition->MoveBOL( );
			} else if ( ch != '\n' ) {
				EditPosition->InsertCharacter( ch );
			}
		}

		int vv = 0;*/
	}

	if ( out ) {
		int tabs = 0;
		while ( str[ tabs ] == '\t' ) {
			tabs++;
		}

		if ( tabs > 0 ) {
			int i = 0;
			in = "";
			in += '\t';
			while ( out[ i ] != '\t' ) {
				in += out[ i ];

				if ( out[ i ] == '\n' && i + 1 < out_size && out[ i + 1 ] != '\t' ) {
					in += '\t';
				}

				i++;
			}

			char *r = new char[ in.length( ) + 1 ];
			strcpy_s( r, in.size( ) + 1, in.c_str( ) );
			if ( !codeInComment ) {
				char *totalRes = new char[ strlen( r ) + strlen( str ) + 1 ];
				memcpy( totalRes, r, strlen( r ) );
				memcpy( totalRes + strlen( r ), str, strlen( str ) );
				totalRes[ strlen( r ) + strlen( str ) ] = '\0';

				EditPosition->InsertText( totalRes );

				delete totalRes;
			} else {
				EditPosition->InsertText( r );
			}

			delete r;
		} else {
			EditPosition->InsertText( out );
		}
	}

	EditPosition->GotoLine( initRow );

	FreeLibrary( hMod );

	delete str;

	return EOBlock;
}

/*bool processCommentary( _di_IOTAEditPosition &EditPosition, int nCharactersCurrnetLine, int &currentRow, int lastRow, TOTACharPos BlockStart, TOTACharPos BlockAfter, _di_IOTAEditBlock IOTAEditBlock )
{
	System::UnicodeString text, res, currentText, mssError;
	std::wstring wsin;
	std::string in;
	char *out, *str;
	unsigned int out_size;
	int initRow;
	bool EOBlock = true;
	typedef int( __stdcall * func )( char *, unsigned int, char *&, unsigned int & );
	HMODULE hMod;
	// func pFunc;
	int limit = 0;
	const wchar_t *widecstr;

	// ShowMessage( "1" );
	hMod = LoadLibrary( dllWrapper );
	// const func pFunc = reinterpret_cast<func>( GetProcAddress( hMod, "parseString" ) );
	func pFunc = (func) GetProcAddress( hMod, "parseString" );

	if ( !pFunc ) {
		mssError = L"No se ha podido acceder a la función de WrapperParserDebug.";
		widecstr = std::wstring( mssError.begin( ), mssError.end( ) ).c_str( );
		Application->MessageBox( widecstr, 0, MB_OK | MB_ICONERROR );
	}

	// ShowMessage( "INICIO" );

	initRow = currentRow++;
	EditPosition->MoveBOL( );
	currentText = EditPosition->Read( nCharactersCurrnetLine );
	wsin = currentText.c_str( );
	in.resize( wsin.length( ) );
	wcstombs( &in[ 0 ], wsin.c_str( ), wsin.size( ) );
	// Tema tabulaciones (Si existen tabulaciones en la línea a leer, coger carácteres de la siguiente también)
	// std::string::iterator it = in.end( ) - 1;
	// while ( in.length( ) > 1 && *it != '\r' && *it != '\n' ) {
	//	it--;
	//}
	// in.erase( it + 1, in.end( ) );
	if ( in.front( ) == '\t' ) {
		std::string::iterator it = in.begin( );
		while ( it != in.end( ) && *it == '\t' ) {
			std::string::iterator ite = in.end( ) - 1;
			for ( int i = 0; i < 3; i++ ) {
				ite--;
			}
			in.erase( ite + 1, in.end( ) );

			it++;
		}
	}

	// ShowMessage( "INICIO 1" );

	str = new char[ in.length( ) + 1 ];
	strcpy_s( str, in.size( ) + 1, in.c_str( ) );
	// char CR[] = { '\r', '\0' };
	char **CR = new char *[ 2 ];
	CR[ 0 ] = new char[ 2 ];
	CR[ 1 ] = new char[ 2 ];
	CR[ 0 ][ 0 ] = '\r';
	CR[ 0 ][ 1 ] = '\0';
	CR[ 1 ][ 0 ] = ' ';
	CR[ 1 ][ 1 ] = '\0';
	if ( strcmp( str, CR[ 0 ] ) == 0 || strcmp( str, CR[ 1 ] ) == 0 ) {
		out_size = 0;
		out = 0;
	} else {
		// WrapperParser::parseString( str, (unsigned int) in.length( ), out, out_size );

		// https://www.codeproject.com/Articles/6351/Regular-DLL-Tutor-For-Beginners
		( pFunc )( str, (unsigned int) in.length( ), out, out_size );
		// parseString( str, (unsigned int) in.length( ), out, out_size );
		limit = BlockAfter.Line;
	}

	// ShowMessage( "Bien" );

	for ( int i = 0; i < 2; i++ )
		delete[] CR[ 0 ];
	delete CR;
	delete str;

	if ( out_size == in.length( ) + 2 ) {
		if ( initRow == lastRow ) {
			EOBlock = readUpToDelimiter( EditPosition, currentText, --currentRow, EditPosition->GetLastRow( ) );
		} else {
			EOBlock = readUpToDelimiter( EditPosition, currentText, --currentRow, lastRow );
		}

		wsin = currentText.c_str( );
		in.resize( wsin.length( ) );
		wcstombs( &in[ 0 ], wsin.c_str( ), wsin.size( ) );
		str = new char[ in.length( ) + 1 ];
		strcpy_s( str, in.size( ) + 1, in.c_str( ) );
		( pFunc )( str, (unsigned int) in.length( ), out, out_size );
		// parseString( str, (unsigned int) in.length( ), out, out_size );
		limit = currentRow - 1;
		// WrapperParser::parseString( str, (unsigned int) in.length( ), out, out_size );
		delete str;
	}

	if ( out && out_size != in.length( ) + 2 ) {
		System::UnicodeString out_aux = out;

		// while ( ( out_aux.Length( ) > 1 && ( out_aux[ out_aux.Length( ) ] == '\n' && out_aux[ out_aux.Length( ) - 1 ] == '\n' ) || ( out_aux[ out_aux.Length( ) ] == '\r' && out_aux[ out_aux.Length( ) - 1 ] == '\n' ) ) || ( out_aux.Length( ) > 2 && out_aux[ out_aux.Length( ) ] == '\n' && out_aux[ out_aux.Length( ) - 1 ] == '\r' && out_aux[ out_aux.Length( ) - 2 ] == '\n' ) ) {
		//	out_aux.Delete( out_aux.Length( ), out_aux.Length( ) );
		//}

		std::string jumps = "";
		if ( in.size( ) >= 2 ) {
			int i = in.size( ) - 1;
			while ( i >= 0 && ( in[ i ] == '\n' && in[ i - 1 ] == '\r' ) ) {
				jumps += in[ i - 1 ];
				jumps += in[ i ];
				i -= 2;
			}
		}

		while ( out_aux.Length( ) > 1 && ( out_aux[ out_aux.Length( ) ] == '\n' || out_aux[ out_aux.Length( ) ] == '\r' ) ) {
			out_aux.Delete( out_aux.Length( ), out_aux.Length( ) );
		}

		out_aux += jumps.c_str( );

		int i = 0;
		EditPosition->GotoLine( initRow );
		EditPosition->Save( );
		int ll1 = EditPosition->DistanceToTab( sdForward );
		int ll2 = EditPosition->DistanceToTab( sdBackward );
		wsin = currentText.c_str( );
		int nc = 0;
		int space = 0;
		bool notSpace = false;
		int numCharacters = 0;
		System::WideChar prev_ch = ' ';
		int contTabsIni = 0, contTabs = 0;
	}

	// TKeyboardBinding *t = 0;
	// t->setKeys( 0 );

	EditPosition->GotoLine( initRow );

	FreeLibrary( hMod );

	return true;
}*/

void __fastcall TKeyboardBinding::Test( )
{
	ShowMessage( "Hola..." );
}

void __fastcall TKeyboardBinding::addCommentarySelectedText( const _di_IOTAKeyContext Context, System::Classes::TShortCut KeyCode, TKeyBindingResult &BindingResult )
{
	_di_IOTAModuleServices ModuleServices;
	_di_IOTAModule Module;
	_di_IOTAEditor Intf;
	_di_IOTASourceEditor Editor;
	_di_IOTAEditView View;
	_di_IOTAEditPosition EditPosition;
	_di_IOTAEditLineTracker EditLineTracker;
	_di_IOTAProcessModule processModule;
	_di_IOTAEditorServices IOTAEditorServices;
	TOTACharPos BlockStart, BlockAfter;
	int l, line, currentRow, lastRow, numCharacters, id, blockSize;
	System::UnicodeString currentText;
	bool stop;

	// ShowMessage( "Comentar" );
	if ( BorlandIDEServices->Supports( ModuleServices ) ) {
		Module = ModuleServices->CurrentModule( );

		if ( !Module ) {
			BindingResult = krUnhandled;
			return;
		}

		_di_IOTAEditBuffer IOTAEditBuffer;
		if ( BorlandIDEServices->Supports( IOTAEditorServices ) ) {
			Editor = IOTAEditorServices->TopBuffer;
		}

		if ( !Editor ) {
			BindingResult = krUnhandled;
			return;
		}

		//---
		_di_IOTAEditBlock IOTAEditBlock;
		int startCol, endCol, startRow, endRow, currentRow, currentCol;
		if ( Context ) {
			IOTAEditBlock = Context->GetEditBuffer( )->GetEditBlock( );
			EditPosition = Context->GetEditBuffer( )->GetEditPosition( );
		} else {
			IOTAEditBlock = IOTAEditorServices->TopBuffer->GetEditBlock( );
			EditPosition = IOTAEditorServices->TopBuffer->GetEditPosition( );
		}
		System::UnicodeString texto;
		if ( IOTAEditBlock->IsValid ) {
			startCol = IOTAEditBlock->StartingColumn;
			endCol = IOTAEditBlock->EndingColumn;
			startRow = IOTAEditBlock->StartingRow;
			endRow = IOTAEditBlock->EndingRow;
			texto = IOTAEditBlock->GetText( );
		} else {
			// IOTAEditBlock->Style = btLine;
			currentRow = EditPosition->GetRow( );
			// EditPosition->Save( );
			EditPosition->MoveEOL( );
			currentCol = EditPosition->GetColumn( );
			EditPosition->MoveBOL( );
			IOTAEditBlock->BeginBlock( );
			int l1 = IOTAEditBlock->GetStartingRow( );
			int l2 = IOTAEditBlock->GetEndingRow( );
			EditPosition->MoveEOL( );
			IOTAEditBlock->EndBlock( );
			// IOTAEditBlock->EndBlock( );
			// IOTAEditBlock->ExtendReal( currentRow, currentCol );
			texto = IOTAEditBlock->GetText( );
		}

		/*EditPosition->Move( startRow, startCol );
		IOTAEditBlock->BeginBlock( );
		EditPosition->Move( endRow, endCol );
		IOTAEditBlock->EndBlock( );
		System::UnicodeString text = IOTAEditBlock->GetText( );*/

		View = IOTAEditorServices->TopView;

		if ( !View ) {
			BindingResult = krUnhandled;
			return;
		}

		EditLineTracker = View->GetBuffer( )->GetEditLineTracker( );
		LineNotifier *lineNotifier = new LineNotifier( EditLineTracker );

		_di_IOTABufferOptions IOTABufferOptions = View->GetBuffer( )->GetBufferOptions( );

		// IOTABufferOptions->SetPreserveLineEnds( false );
		// IOTABufferOptions->SetSmartTab( true );
		// IOTABufferOptions->SetUndoAfterSave( false );
		// IOTABufferOptions->SetUseTabCharacter( false );
		IOTABufferOptions->SetAutoIndent( false );
		// IOTABufferOptions->SetInsertMode( false );
		// IOTABufferOptions->SetCursorThroughTabs( false );

		bool res = processCommentary2( EditPosition, IOTAEditBlock );

		delete lineNotifier;
	}

	// ShowMessage( "FIN" );

	BindingResult = krHandled;
}

/*void __fastcall TKeyboardBinding::addCommentarySelectedText( const _di_IOTAKeyContext Context, System::Classes::TShortCut KeyCode, TKeyBindingResult &BindingResult )
{
	_di_IOTAModuleServices ModuleServices;
	_di_IOTAModule Module;
	_di_IOTAEditor Intf;
	_di_IOTASourceEditor Editor;
	_di_IOTAEditView View;
	_di_IOTAEditPosition EditPosition;
	_di_IOTAEditLineTracker EditLineTracker;
	TOTACharPos BlockStart, BlockAfter;
	int l, line, currentRow, lastRow, numCharacters, id, blockSize;
	System::UnicodeString currentText;
	bool stop;

	EditPosition = Context->GetEditBuffer( )->GetEditPosition( );
	if ( BorlandIDEServices->Supports( ModuleServices ) ) {
		Module = ModuleServices->CurrentModule( );

		if ( !Module ) {
			BindingResult = krUnhandled;
			return;
		}

		for ( int i = 0; i < Module->GetModuleFileCount( ); i++ ) {
			Intf = Module->GetModuleFileEditor( i );
			if ( Intf->QueryInterface( __uuidof( IOTASourceEditor ), (void **) ( &Editor ) ) == S_OK ) {
				break;
			}
		}

		if ( !Editor ) {
			BindingResult = krUnhandled;
			return;
		}

		View = Editor->EditViews[ 0 ];
		BlockStart = Editor->GetBlockStart( );
		BlockAfter = Editor->GetBlockAfter( );
		EditLineTracker = View->GetBuffer( )->GetEditLineTracker( );
		// View->GetBuffer( )->GetBufferOptions( )->SetUndoLimit( 800 );
		// id = EditLineTracker->AddNotifier( new LineNotifier( EditLineTracker ) );
		LineNotifier *lineNotifier = new LineNotifier( EditLineTracker );

		int linesB = Editor->GetLinesInBuffer( );
		TOTABlockType bType = Editor->GetBlockType( );
		currentRow = EditPosition->GetRow( );

		if ( BlockStart.Line > currentRow ) {
			line = lastRow = currentRow;
			blockSize = 1;
		} else {
			line = BlockStart.Line;
			lastRow = BlockAfter.Line;
			blockSize = lastRow - line + 1;
		}

		for ( int i = line; i <= lastRow; i++ ) {
			EditLineTracker->AddLine( i, 0 );
		}

		stop = false;
		l = 0;
		// EditPosition->Tab( 4 );
		while ( !stop && l < blockSize ) {
			EditPosition->GotoLine( line );
			EditPosition->MoveBOL( );
			// int pos1 = EditPosition->DistanceToTab( sdForward );
			// int pos = EditPosition->DistanceToTab( sdBackward );
			// numCharacters = EditPosition->GetColumn( );
			numCharacters = 0;
			int col = 1;
			while ( EditPosition->GetCharacter( ) != '\r' ) {
				numCharacters++;
				System::WideChar ch = EditPosition->GetCharacter( );
				int r = EditPosition->GetRow( );
				int c = col;
				EditPosition->Move( EditPosition->GetRow( ), col++ );
			}
			numCharacters++;
			stop = processCommentary( EditPosition, numCharacters, line, lastRow, BlockStart, BlockAfter );
			TOTACharPos aa = Editor->GetBlockStart( );
			int nose = EditLineTracker->GetCount( );
			for ( int i = 0; i < EditLineTracker->GetCount( ); i++ ) {
				nose = EditLineTracker->GetLineNum( i );
			}

			if ( ++l < EditLineTracker->GetCount( ) ) {
				line = EditLineTracker->GetLineNum( l );
				lastRow = EditLineTracker->GetLineNum( EditLineTracker->GetCount( ) - 1 );
			}
		}

		delete lineNotifier;
		int pp = EditLineTracker->GetCount( );

		// EditLineTracker->RemoveNotifier( id );
		Editor->Show( );
	}

	BindingResult = krHandled;
}  */

void replaceTabs( _di_IOTAEditPosition EditPosition, int currentRow )
{
	int i = 1;

	EditPosition->GotoLine( currentRow );
	EditPosition->MoveBOL( );

	System::WideChar ch = EditPosition->GetCharacter( );
	while ( ch != '\r' ) {
		if ( ch == '\t' ) {
			EditPosition->Delete( 1 );
			System::WideChar ccc = EditPosition->GetCharacter( );
			// EditPosition->Tab( 4 );
			for ( int i = 0; i < 4; i++ )
				EditPosition->InsertCharacter( ' ' );
		}

		EditPosition->Move( currentRow, ++i );
		ch = EditPosition->GetCharacter( );
	}
}

System::UnicodeString __fastcall readNLines( _di_IOTAEditPosition EditPosition, int currentRow, int lastRow )
{
	int nCharacters = 0;
	System::UnicodeString text, row;

	text = "";
	while ( currentRow != lastRow + 1 ) {
		EditPosition->GotoLine( currentRow );
		EditPosition->MoveEOL( );
		replaceTabs( EditPosition, currentRow );
		// EditPosition->GotoLine( currentRow );
		int r = EditPosition->GetRow( );
		nCharacters = EditPosition->GetColumn( ) + 1;
		EditPosition->MoveBOL( );
		row = EditPosition->Read( nCharacters );
		System::UnicodeString row2 = row;
		auto ch = *row.LastChar( );
		if ( *row.LastChar( ) == '\r' ) {
			row.Insert( '\n', row.Length( ) + 1 );
			EditPosition->MoveEOL( );
			EditPosition->InsertCharacter( '\n' );
		}
		System::UnicodeString row3 = row;
		text += row;
		currentRow++;
	}

	return text;
}

// IOTANotifer
void __fastcall TKeyboardBinding::BeforeSave( )
{
	// inherited::BeforeSave( );
}

void __fastcall TKeyboardBinding::AfterSave( )
{
	// inherited::AfterSave( );
}

void __fastcall TKeyboardBinding::Destroyed( )
{
	// inherited::Destroyed( );
}

void __fastcall TKeyboardBinding::Modified( )
{
	// inherited::Modified( );
}

ULONG __stdcall TKeyboardBinding::AddRef( )
{
	// return inherited::AddRef( );
}
ULONG __stdcall TKeyboardBinding::Release( )
{
	// return inherited::Release( );
}

HRESULT __stdcall TKeyboardBinding::QueryInterface( const GUID &iid, void **obj )
{
	QUERY_INTERFACE( IOTAKeyboardBinding, iid, obj );
	// QUERY_INTERFACE(IOTAWizard, iid, obj);
	// return inherited::QueryInterface( iid, obj );
	return E_NOINTERFACE;
}

int __fastcall AddKeyBoardBindingObject( TKeyboardBinding *KeyBoardBinding )
{
	// ShowMessage( "1" );
	_di_IOTAKeyboardServices IOTAKeyboardBinding;
	_di_IOTAKeyboardBinding KeyBinding;
	_di_IOTAKeyBindingServices BindingServices;

	if ( BorlandIDEServices->Supports( IOTAKeyboardBinding ) ) {
		// ShowMessage( "2" );
		// TShortCut *keys = new TShortCut[ numShortKeys ];
		// keys[ 0 ] = TextToShortCut( "Ctrl+Shift+H" );
		// Seguir por aquí (probar a partir de aquí dónde falla)
		// KeyBoardBinding = new TKeyboardBinding( keys, numShortKeys );
		return IOTAKeyboardBinding->AddKeyboardBinding( KeyBoardBinding );
	}

	// ShowMessage( "3" );

	return -1;
}

void __fastcall RemoveKeyboardBinding( int IDEKeyBoardBinding )
{
	_di_IOTAKeyboardServices IOTAKeyboardServices;

	if ( BorlandIDEServices->Supports( IOTAKeyboardServices ) ) {
		if ( IDEKeyBoardBinding > -1 ) {
			IOTAKeyboardServices->RemoveKeyboardBinding( IDEKeyBoardBinding );
		}
	}
}

