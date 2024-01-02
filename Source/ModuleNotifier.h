//---------------------------------------------------------------------------

#ifndef ModuleNotifierH
#define ModuleNotifierH

#include "CPPOTATemplateNotifierObject.h"

class ModuleNotifier : public TDGHNotifierObject, public IOTAModuleNotifier
{
	typedef TDGHNotifierObject inherited;

  private:
	_di_IOTAModule module;
	System::UnicodeString name;
	int index;

  protected:
	// IOTANotifier
	void __fastcall AfterSave( );
	void __fastcall BeforeSave( );
	void __fastcall Destroyed( );
	void __fastcall Modified( );

	// IOTAModuleNotifier
	virtual bool __fastcall CheckOverwrite( );
	virtual void __fastcall ModuleRenamed( const System::UnicodeString NewName );

	// IInterface
	virtual HRESULT __stdcall QueryInterface( const GUID &, void ** );
	virtual ULONG __stdcall AddRef( );
	virtual ULONG __stdcall Release( );

  public:
	__fastcall ModuleNotifier( _di_IOTAModule module );
	virtual __fastcall ~ModuleNotifier( );
};

#endif

