//---------------------------------------------------------------------------

#ifndef DocWizardH
#define DocWizardH

#include <ToolsAPI.hpp>
#include "CPPOTATemplateNotifierObject.h"

class PACKAGE DocWizard : public TDGHNotifierObject, public IOTAMenuWizard
{
	typedef TDGHNotifierObject inherited;

  private:
	//_di_IOTAModule module;
	System::UnicodeString creator_type;
	TInterfaceList *list;

  protected:
	// IOTAWizard
	virtual System::UnicodeString __fastcall GetIDString( );
	virtual System::UnicodeString __fastcall GetName( );
	virtual TWizardState __fastcall GetState( );
	virtual void __fastcall Execute( );
	// IOTAMenuWizard
	virtual System::UnicodeString __fastcall GetMenuText( );
	// IOTANotifier
	virtual void __fastcall AfterSave( );
	virtual void __fastcall BeforeSave( );
	virtual void __fastcall Destroyed( );
	virtual void __fastcall Modified( );
	// IInterface
	virtual HRESULT __stdcall QueryInterface( const GUID &iid, void **obj );
	virtual ULONG __stdcall AddRef( );
	virtual ULONG __stdcall Release( );

  public:
	__fastcall DocWizard( System::UnicodeString strObjectName, System::UnicodeString creator_type );
	__fastcall ~DocWizard( );
};

#endif

