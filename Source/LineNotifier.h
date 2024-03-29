//---------------------------------------------------------------------------

#ifndef LineNotifierH
#define LineNotifierH
//---------------------------------------------------------------------------

#include "CPPOTATemplateNotifierObject.h"

class LineNotifier : public TDGHNotifierObject, public IOTAEditLineNotifier
{
	typedef TDGHNotifierObject inherited;

  private:
	_di_IOTAEditLineTracker line;
	int id;

  protected:
	// IOTANotifier
	void __fastcall AfterSave( );
	void __fastcall BeforeSave( );
	void __fastcall Destroyed( );
	void __fastcall Modified( );

	// IOTAEditLineNotifier
	virtual void __fastcall LineChanged( int OldLine, int NewLine, int Data );

	// IInterface
	virtual HRESULT __stdcall QueryInterface( const GUID &, void ** );
	virtual ULONG __stdcall AddRef( );
	virtual ULONG __stdcall Release( );

  public:
	__fastcall LineNotifier( _di_IOTAEditLineTracker line );
	virtual __fastcall ~LineNotifier( );

	int GetID( ) const
	{
		return id;
	}

	_di_IOTAEditLineTracker GetLine( )
	{
		return line;
	}
};

int __fastcall AddLineNotifier( );
void __fastcall RemoveLineNotifier( int iIDENotifierIndex );

#endif

