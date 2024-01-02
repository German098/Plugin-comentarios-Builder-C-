//---------------------------------------------------------------------------

#pragma hdrstop

#include "ModuleNotifier.h"
//---------------------------------------------------------------------------
#pragma package( smart_init )

__fastcall ModuleNotifier::ModuleNotifier( _di_IOTAModule module ): index( -1 ), module( module )
{
	index = module->AddNotifier( this );
	name = ChangeFileExt( ExtractFileName( module->FileName ), "" );
}

__fastcall ModuleNotifier::~ModuleNotifier( )
{
	if ( index >= 0 ) module->RemoveNotifier( index );
}

void __fastcall ModuleNotifier::AfterSave( )
{
}

void __fastcall ModuleNotifier::BeforeSave( )
{
}

void __fastcall ModuleNotifier::Destroyed( )
{
	if ( index >= 0 ) {
		module->RemoveNotifier( index );
		index = -1;
	}

	module = 0;
}

void __fastcall ModuleNotifier::Modified( )
{
}

HRESULT __stdcall ModuleNotifier::QueryInterface( const GUID &iid, void **obj )
{
	// QUERY_INTERFACE(IOTAModuleNotifier, iid, obj);
	if ( ( iid ) == __uuidof( IOTAModuleNotifier ) ) {
		*( obj ) = static_cast<IOTAModuleNotifier *>( this );
		static_cast<IOTAModuleNotifier *>( *( obj ) )->AddRef( );
		return S_OK;
	}

	return inherited::QueryInterface( iid, obj );
}

ULONG __stdcall ModuleNotifier::AddRef( )
{
	return inherited::AddRef( );
}

ULONG __stdcall ModuleNotifier::Release( )
{
	return inherited::Release( );
}

// IOTAModuleNotifier
bool __fastcall ModuleNotifier::CheckOverwrite( )
{
	int tyy = 0;
	return true;
}

void __fastcall ModuleNotifier::ModuleRenamed( const System::UnicodeString NewName )
{
	System::UnicodeString module_name = ChangeFileExt( ExtractFileName( module->FileName ), "" );

	for ( int i = 0; i < module->GetModuleFileCount( ); i++ ) {
		_di_IOTAEditor editor = module->GetModuleFileEditor( i );
		_di_IOTAEditBuffer buffer;

		if ( editor->Supports( buffer ) ) {
			_di_IOTAEditPosition pos = buffer->GetEditPosition( );
			pos->Move( 1, 1 );
			pos->Delete( 4 );
			pos->InsertText( module_name );
			name = module_name;
		}
	}
}

