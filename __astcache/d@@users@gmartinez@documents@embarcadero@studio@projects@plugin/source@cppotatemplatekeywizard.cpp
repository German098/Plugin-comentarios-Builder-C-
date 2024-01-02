//---------------------------------------------------------------------------

#pragma hdrstop

#include "CPPOTATemplateKeyWizard.h"
#include "CPPOTATemplateMacros.h"
#include "CPPOTATemplateSplashScreen.h"
#include "CPPOTATemplateAboutBoxPlugin.h"
//---------------------------------------------------------------------------
#pragma package( smart_init )

class TKeyboardBinding;

__fastcall TCPPOTATemplateKeyWizard::TCPPOTATemplateKeyWizard( String strObjectName ): TDGHNotifierObject( strObjectName )
{
	// ShowMessage( "AQUI" );
	AddSplashScreen( );
	FAboutBoxPlugin = AddAboutBoxPlugin( );
	imageIndex = addImageToList( );
	FIDENotifier = AddIDENotifier( "TCPPOTATemplateIDENotifierKey" );
	int numShortKeys = 1;
	TShortCut *keys = new TShortCut[ numShortKeys ];
	keys[ 0 ] = TextToShortCut( "Ctrl+Shift+H" );
	KeyBoradBinding = new TKeyboardBinding( keys, numShortKeys );
	action_doxygen = 0;
	action_commentary = 0;
	ExtendToolsMenu( this, "ToolsMenu" );
	// ExtendToolsBar( this, "Commentary" );
	IDEKeyBoardBinding = AddKeyBoardBindingObject( KeyBoradBinding );
	doxyForm = new TForm1( 0 );
}

__fastcall TCPPOTATemplateKeyWizard::~TCPPOTATemplateKeyWizard( )
{
	RemoveIDENotifier( FIDENotifier );
	RemoveKeyboardBinding( IDEKeyBoardBinding );
	RemoveAboutBoxPlugin( FAboutBoxPlugin );
	if ( KeyBoradBinding ) delete KeyBoradBinding;
	if ( doxyForm ) delete doxyForm;
	if ( action_doxygen ) delete action_doxygen;
	if ( action_commentary ) delete action_commentary;
}

UnicodeString __fastcall TCPPOTATemplateKeyWizard::GetIDString( )
{
	return "CPP.OTA.Template.Wizard.Key";
}
UnicodeString __fastcall TCPPOTATemplateKeyWizard::GetName( )
{
	return "CPP OTA Temaple Key";
}
TWizardState __fastcall TCPPOTATemplateKeyWizard::GetState( )
{
	TWizardState result;
	result << wsEnabled;
	return result;
}

// IOTAMenuWizard
System::UnicodeString __fastcall TCPPOTATemplateKeyWizard::GetMenuText( )
{
	return "Prueba Menu";
}

void __fastcall TCPPOTATemplateKeyWizard::Execute( )
{
	// DoNotification( "... Hello Dave!" );
	MessageDlg( "Hello Dave... How are you...", mtInformation, TMsgDlgButtons( ) << mbOK, 0 );
}

void __fastcall TCPPOTATemplateKeyWizard::BeforeSave( )
{
	inherited::BeforeSave( );
}
void __fastcall TCPPOTATemplateKeyWizard::AfterSave( )
{
	inherited::AfterSave( );
}
void __fastcall TCPPOTATemplateKeyWizard::Destroyed( )
{
	inherited::Destroyed( );
}
void __fastcall TCPPOTATemplateKeyWizard::Modified( )
{
	inherited::Modified( );
}

ULONG __stdcall TCPPOTATemplateKeyWizard::AddRef( )
{
	return inherited::AddRef( );
}
ULONG __stdcall TCPPOTATemplateKeyWizard::Release( )
{
	return inherited::Release( );
}
HRESULT __stdcall TCPPOTATemplateKeyWizard::QueryInterface( const GUID &iid, void **obj )
{
	QUERY_INTERFACE( IOTAMenuWizard, iid, obj );
	QUERY_INTERFACE( IOTAWizard, iid, obj );
	return inherited::QueryInterface( iid, obj );
}

void __fastcall TCPPOTATemplateKeyWizard::OnExecuteActionDoxygen( System::TObject *Sender )
{
	/*TCHAR buffer[ MAX_PATH ] = { 0 };
	GetModuleFileName( NULL, buffer, MAX_PATH );
	std::string str( buffer );
	std::string::size_type pos = str.find_last_of( "\\/" );*/
	// std::wstring::size_type pos = std::wstring( buffer ).find_last_of( L"\\/" );

	doxyForm->Show( );
}

void __fastcall TCPPOTATemplateKeyWizard::OnExecuteActionCommentary( System::TObject *Sender )
{
	// ShowMessage( "Evento" );
	if ( KeyBoradBinding ) {
		_di_IOTAKeyContext Context;
		System::Classes::TShortCut KeyCode;
		TKeyBindingResult BindingResult;
		KeyBoradBinding->addCommentarySelectedText( Context, KeyCode, BindingResult );
	}
}

void __fastcall TCPPOTATemplateKeyWizard::ExtendToolsMenu( void *wizard, System::UnicodeString menu_name )
{
	_di_INTAServices services;
	TMenuItem *new_menu_item1, *new_menu_item2;
	TCPPOTATemplateKeyWizard *w = static_cast<TCPPOTATemplateKeyWizard *>( wizard );

	if ( BorlandIDEServices->Supports( services ) ) {
		if ( services->GetMainMenu( )->Items->Count > 0 ) {
			action_doxygen = w->GetActionDoxygen( );

			action_doxygen = new TAction( 0 );
			action_doxygen->ActionList = services->ActionList;
			action_doxygen->Caption = "Generate Documentation";
			action_doxygen->Hint = "Generate Documentation";
			action_doxygen->ImageIndex = w->GetImageIndex( );
			System::Classes::TNotifyEvent actionOnExecute1 = &( w->OnExecuteActionDoxygen );
			action_doxygen->OnExecute = actionOnExecute1;

			action_commentary = w->GetActionCommentary( );

			action_commentary = new TAction( 0 );
			action_commentary->ActionList = services->ActionList;
			action_commentary->Caption = "Comment Code";
			action_commentary->Hint = "Comment Code";
			action_commentary->ImageIndex = w->GetImageIndex( );
			System::Classes::TNotifyEvent actionOnExecute2 = &( w->OnExecuteActionCommentary );
			action_commentary->OnExecute = actionOnExecute2;

			// services->AddActionMenu( "Doxygen", 0, services->GetMainMenu( ) );
			TMenuItem *new_menu = new TMenuItem( 0 );
			new_menu->Name = "DoxygenMenu";
			new_menu->Caption = "Doxygen";

			new_menu_item1 = new TMenuItem( 0 );
			new_menu_item2 = new TMenuItem( 0 );
			new_menu_item1->Action = action_doxygen;
			new_menu->Insert( 0, new_menu_item1 );
			new_menu_item2->Action = action_commentary;
			new_menu->Insert( 1, new_menu_item2 );

			services->GetMainMenu( )->Items->Insert( services->GetMainMenu( )->Items->Count - 1, new_menu );
		}

		/*action_doxygen = w->GetActionDoxygen( );

		action_doxygen = new TAction( 0 );
		action_doxygen->ActionList = services->ActionList;
		action_doxygen->Caption = "Generate Documentation";
		action_doxygen->Hint = "Generate Documentation";
		action_doxygen->ImageIndex = w->GetImageIndex( );
		System::Classes::TNotifyEvent actionOnExecute1 = &( w->OnExecuteActionDoxygen );
		action_doxygen->OnExecute = actionOnExecute1;

		action_commentary = w->GetActionCommentary( );

		action_commentary = new TAction( 0 );
		action_commentary->ActionList = services->ActionList;
		action_commentary->Caption = "Comment Code";
		action_commentary->Hint = "Comment Code";
		action_commentary->ImageIndex = w->GetImageIndex( );
		System::Classes::TNotifyEvent actionOnExecute2 = &( w->OnExecuteActionCommentary );
		action_commentary->OnExecute = actionOnExecute2;

		for ( int i = 0; i < services->GetMainMenu( )->Items->Count; i++ ) {
			TMenuItem *item = services->GetMainMenu( )->Items->Items[ i ];
			if ( CompareText( item->Name, menu_name ) == 0 ) {
				new_menu_item1 = new TMenuItem( 0 );
				new_menu_item2 = new TMenuItem( 0 );
				new_menu_item1->Action = action_doxygen;
				item->Insert( item->Count - 1, new_menu_item1 );
				new_menu_item2->Action = action_commentary;
				item->Insert( item->Count - 1, new_menu_item2 );
				break;
			}
		}*/
	}
}

void __fastcall TCPPOTATemplateKeyWizard::ExtendToolsBar( void *wizard, System::UnicodeString name )
{
	_di_INTAServices services;
	_di_INTAIDEInsightService INTAIDEInsightService;
	_di_INTAComponent INTAComponent;
	TCPPOTATemplateKeyWizard *w = static_cast<TCPPOTATemplateKeyWizard *>( wizard );

	if ( BorlandIDEServices->Supports( services ) ) {
		// https://www.functionx.com/cppbuilder/controls/toolbar.htm
		/*Vcl::Comctrls::TToolBar *newToolBar = services->NewToolbar( name, "Comment code" );
		TToolButton *btnToolBar = new TToolButton( newToolBar );
		btnToolBar->Parent = newToolBar;
		btnToolBar->Caption = "Comment";
		btnToolBar->Style = tbsTextButton;
		Vcl::Controls::TControl *newControl = services->AddToolButton( name, "Button", action ); */

		/*	TContainedAction *taction = 0;

		 if ( BorlandIDEServices->Supports( INTAIDEInsightService ) ) {
			 Vcl::Actnlist::TCustomActionList *actionList = services->GetActionList( );
			 taction = new TContainedAction( 0 );
			 taction->ActionList = services->ActionList;
			 taction->Caption = name;
			 taction->Hint = "Comment code snippet";
			 taction->ImageIndex = w->GetImageIndex( );
			 taction->OnExecute = actionOnExecute;

			 actionList->Images = lstImages;
			 actionList->Actions[ 1 ] = taction;

			 INTAIDEInsightService->AddActionList( actionList, "Documentar código" );
		 }  */

		Vcl::Menus::TMainMenu *menu = services->GetMainMenu( );
		int num = services->GetMainMenu( )->Items->Count;
		// Vcl::Menus::TMainMenu *item = 0;
		System::UnicodeString nname;
		for ( int i = 0; i < services->GetMainMenu( )->Items->Count; i++ ) {
			TMenuItem *item = services->GetMainMenu( )->Items->Items[ i ];
			// item = services->GetMainMenu( );
			nname = item->Name;
		}

		/*Vcl::Actnlist::TCustomActionList *actionList = services->GetActionList( );
		Graphics::TBitmap *bmpImage = new Graphics::TBitmap;
		TImageList *lstImages = new TImageList( 0 );
		bmpImage->LoadFromResourceName( reinterpret_cast<unsigned>( HInstance ), L"CPPOTATemplateSplashScreenBitMap16x16" );
		lstImages->Add( bmpImage, 0 );
		TCustomAction *caction = new TCustomAction( 0 );
		caction->ActionList = services->ActionList;
		caction->Caption = name;
		caction->Hint = "Comment code snippet";
		// actionList->Images = lstImages;
		caction->ImageIndex = 0;
		caction->OnExecute = actionOnExecute; */

		/*int count = actionList->ActionCount;
		actionList->Actions[ 0 ] = caction;

		if ( BorlandIDEServices->Supports( INTAIDEInsightService ) ) {
			INTAIDEInsightService->AddActionList( actionList, "Documentar código" );
		}*/

		// services->AddActionMenu( "MainMenu1", caction, &services->GetMainMenu( )->Items[ 0 ], false );
		Vcl::Comctrls::TToolBar *newToolBar = services->NewToolbar( "NewCustomToolBar", "Barra prueba" );
		newToolBar->ShowCaptions = true;
		newToolBar->List = true;

		TAction *action = w->GetActionCommentary( );

		action = new TAction( 0 );
		// action->ActionList = services->ActionList;
		action->Caption = "Comment Code";
		action->Hint = "Comment Code";
		action->ImageIndex = w->GetImageIndex( );
		System::Classes::TNotifyEvent actionOnExecute = &w->OnExecuteActionCommentary;
		action->OnExecute = actionOnExecute;

		Vcl::Controls::TControl *control1 = services->AddToolButton( "NewCustomToolBar", "CommentButton", action );
		// TToolButton *button = new TToolButton( control1 );
		// button->Parent = newToolBar;
		int a = newToolBar->ButtonCount;
		// newToolBar->Buttons[ 0 ]->Hint = "Comment Code";
		// newToolBar->Buttons[ 0 ]->OnClick = actionOnExecute;
		// newToolBar->Buttons[ 0 ]->Action = action;
		// newToolBar->Buttons[ 0 ]->ImageIndex = w->GetImageIndex( );
		// newToolBar->Buttons[ 0 ]->MenuItem->Action = action;

		// TToolButton *btnToolbar = new TToolButton( 0 );
		/*TAction *action = w->GetActionCommentary( );

		action = new TAction( 0 );
		// action->ActionList = services->ActionList;
		action->Caption = "Comment Code";
		action->Hint = "Comment Code";
		action->ImageIndex = w->GetImageIndex( );
		System::Classes::TNotifyEvent actionOnExecute = &w->OnExecuteActionCommentary;
		action->OnExecute = actionOnExecute; */

		// newToolBar->Action = action;
		/*btnToolbar->Enabled = true;
		newToolBar->ShowCaptions = true;
		btnToolbar->Caption = "";
		int lastbtnindex = newToolBar->ButtonCount - 1;
		if ( lastbtnindex > -1 ) {
			btnToolbar->Left = newToolBar->Buttons[ lastbtnindex ]->Left + newToolBar->Buttons[ lastbtnindex ]->Width;
		} else {
			btnToolbar->Left = 0;
		}

		System::Classes::TNotifyEvent test = &( w->testClick );
		btnToolbar->OnClick = test;
		btnToolbar->Parent = newToolBar; */

		/*Vcl::Controls::TControl *control1 = services->AddToolButton( "NewCustomToolBar", "CommentButton", action );
		// newToolBar->InsertButton( control1 );
		TToolButton *buttonComment = static_cast<TToolButton *>( control1 );
		buttonComment->Style = tbsButton;
		buttonComment->Caption = "";
		buttonComment->Hint = "Comment code";
		buttonComment->OnClick = actionOnExecute;
		newToolBar->OnClick = actionOnExecute; */

		/*action = w->GetActionDoxygen( );

		action = new TAction( 0 );
		// action->ActionList = services->ActionList;
		action->Caption = "Doxygen";
		action->Hint = "Doxygen";
		action->ImageIndex = w->GetImageIndex( );
		actionOnExecute = &w->OnExecuteActionDoxygen;
		action->OnExecute = actionOnExecute;

		Vcl::Controls::TControl *control2 = services->AddToolButton( "NewCustomToolBar", "GenerateDocumentationButton", action );
		TToolButton *buttonGenerateDocumentation = static_cast<TToolButton *>( control2 );
		buttonGenerateDocumentation->Style = tbsButton;
		buttonGenerateDocumentation->Caption = "";
		buttonGenerateDocumentation->Hint = "Doxygen";
		buttonGenerateDocumentation->OnClick = actionOnExecute;*/
	}
}

int __fastcall addImageToList( )
{
	_di_INTAServices services;
	int image = -1;

	if ( BorlandIDEServices->Supports( services ) ) {
		Vcl::Graphics::TBitmap *bitmap( new Graphics::TBitmap( ) );
		bitmap->LoadFromResourceName( reinterpret_cast<unsigned>( HInstance ), L"CPPOTATemplateSplashScreenBitMap16x16" );
		image = services->AddMasked( bitmap, bitmap->TransparentColor, "Bitmap1" );

		delete bitmap;
	}

	return image;
}

