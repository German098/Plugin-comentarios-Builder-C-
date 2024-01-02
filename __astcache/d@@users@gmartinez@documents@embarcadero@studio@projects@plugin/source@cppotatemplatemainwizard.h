//---------------------------------------------------------------------------

#ifndef CPPOTATemplateMainWizardH
#define CPPOTATemplateMainWizardH

#include <design/ToolsAPI.hpp>
#include <ExtCtrls.hpp>
#include <stack>
#include <vector>
#include "CPPOTATemplateIDENotifier.h"
#include "LineNotifier.h"
//#include "Common.h"
#include "KeyboardBinding.h"

/*
	{ krUnhandled, krHandled, krNextProc }
	* Establece el parámetro formal BindingResultç del método TKeyBindingProc a krHandled si el método ha ejecutado correctamente su comportamiento.
	Establecer BindingResult a krHandled también tiene el efecto de evitar que cualquier otra combinación de teclas procese la tecla, así como
	evitar que los elementos de menú asignados a la combinación de teclas la procesen.

	* Establece BindingResult como krUnhandled si no procesa la pulsación o combinación de teclas. Si establece BindingResult a krUnhandled, el
	editor permitirá que cualquier otra combinación de teclas asignada a la pulsación o combinación de teclas la procese, así como cualquier
	elemento de menú asociado a la combinación de teclas.

	* Establezca BindingResult a krNextProc si ha manipulado la tecla, pero desea permitir que cualquier otra combinación de teclas asociada a la
	pulsación o combinación de teclas también se active. De forma similar a establecer BindingResult a krHandled, establecer BindingResult a
	krNextProc tendrá el efecto de evitar que los atajos de menú reciban la pulsación o combinación de teclas.
*/

// std::stack<CommentBlock> rangeComment;
// CommentBlock rangeComment;

System::UnicodeString __fastcall header_comment( System::UnicodeString file, System::UnicodeString author, System::UnicodeString date );

class PACKAGE TCPPOTATemplateWizard : public TDGHNotifierObject, public IOTAMenuWizard // IOTAWizard
{
	typedef TDGHNotifierObject inherited;

  private:
	int FAboutBoxPlugin;
	int FIDENotifier;
	// int IDEKeyBoardBinding;
	TAction *action_doxygen;
	TAction *action_commentary;
	int imageIndex;
	// TCPPOTATemplateOptions* FAppOptions;
	TTimer *FAutoSaveTimer;
	int FTimerCounter;
	// TCPPOTATemplateAddInOptions* FIDEOptions;
	TKeyboardBinding *KeyBoradBinding;
	int FPointNotifier;

  protected:
	// IOTAWizard
	virtual UnicodeString __fastcall GetIDString( );
	virtual UnicodeString __fastcall GetName( );
	virtual TWizardState __fastcall GetState( );
	virtual void __fastcall Execute( );
	// IOTAMenuWizard
	virtual System::UnicodeString __fastcall GetMenuText( );
	// IOTAActionServices
	virtual bool __fastcall CloseFile( const System::UnicodeString FileName );
	virtual bool __fastcall OpenFile( const System::UnicodeString FileName );
	virtual bool __fastcall OpenProject( const System::UnicodeString ProjName, bool NewProjGroup );
	virtual bool __fastcall ReloadFile( const System::UnicodeString FileName );
	virtual bool __fastcall SaveFile( const System::UnicodeString FileName );
	// IOTANotifer
	void __fastcall BeforeSave( );
	void __fastcall AfterSave( );
	void __fastcall Destroyed( );
	void __fastcall Modified( );
	// IInterface
	virtual HRESULT __stdcall QueryInterface( const GUID &iid, void **obj );
	virtual ULONG __stdcall AddRef( );
	virtual ULONG __stdcall Release( );
	// Non-interface methods
	void __fastcall AutoSaveTimerEvent( TObject *Sender );
	// void __fastcall SaveModifiedFiles();
	void __fastcall ExtendToolsMenu( void *wizard, System::UnicodeString menu_name );
	void __fastcall ExtendToolsBar( void *wizard, System::UnicodeString name );

  public:
	__fastcall TCPPOTATemplateWizard( String strObjectName );
	__fastcall ~TCPPOTATemplateWizard( );
	TAction *GetActionDoxygen( )
	{
		return action_doxygen;
	}
	TAction *GetActionCommentary( )
	{
		return action_commentary;
	}
	void __fastcall OnExecuteActionDoxygen( System::TObject *Sender );
	void __fastcall OnExecuteActionCommentary( System::TObject *Sender );
	void remove_action_doxygen( TAction *action, TToolBar *toolbar );
	int GetImageIndex( ) const
	{
		return imageIndex;
	}
	// System::UnicodeString __fastcall GetDesigner( );

	void __fastcall testClick( TObject * );
};

int __fastcall addImageToList( );

#endif

