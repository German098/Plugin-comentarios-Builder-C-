//---------------------------------------------------------------------------

#pragma hdrstop

#include "CPPOTATemplateMainWizard.h"
#include "CPPOTATemplateMacros.h"
#include "CPPOTATemplateSplashScreen.h"
#include "CPPOTATemplateAboutBoxPlugin.h"
//#include "ModuleNotifier.h"
//#include "Header.h"
#include <Lmcons.h>
#include <Dialogs.hpp>
//#include "WrapperParserDebug.h"
#include "string"
//#include "TApplicationMainMenu.h"

//---------------------------------------------------------------------------
#pragma package( smart_init )

const std::string h1 = "/\**\r\n * @file\t";
const std::string h2 = "\r\n* @brief Descripción fichero.\r\n*\r\n* @author\t";
const std::string h3 = "\r\n* @date\t";
const std::string h4 = "\r\n*/\r\n";
int lengthFile;
int lengthAuthor;
int lengthDate;

/* TCPPOTATemplateWizard Implementation */
__fastcall TCPPOTATemplateWizard::TCPPOTATemplateWizard( String strObjectName ): TDGHNotifierObject( strObjectName )
{
	// GetDesigner( );
	//: @note Not required now
	ShowMessage( "Splash" );
	//: #ifndef DLL
	// AddSplashScreen( );
	//: #endif
	/*FAboutBoxPlugin = AddAboutBoxPlugin( );
	imageIndex = addImageToList( );
	FIDENotifier = AddIDENotifier( "TCPPOTATemplateIDENotifierMain" );
	// ShowMessage( "AQUI" );
	int numShortKeys = 1;
	TShortCut *keys = new TShortCut[ numShortKeys ];
	keys[ 0 ] = TextToShortCut( "Ctrl+Shift+H" );
	KeyBoradBinding = new TKeyboardBinding( keys, numShortKeys );
	action_doxygen = 0;
	ExtendToolsMenu( this, "ToolsMenu" );*/
	// ExtendToolsBar( this, "Commentary" );

	/*FAutoSaveTimer = new TTimer( NULL );
	FAutoSaveTimer->Interval = 10000;
	FAutoSaveTimer->OnTimer = AutoSaveTimerEvent;
	FAutoSaveTimer->Enabled = true;
	FTimerCounter = 0;*/
}

__fastcall TCPPOTATemplateWizard::~TCPPOTATemplateWizard( )
{
	/*RemoveAboutBoxPlugin( FAboutBoxPlugin );

	RemoveIDENotifier( FIDENotifier );
	// RemoveKeyboardBinding( IDEKeyBoardBinding );

	_di_INTAServices services;
	if ( BorlandIDEServices->Supports( services ) ) {
		remove_action_doxygen( action_doxygen, services->ToolBar[ sCustomToolBar ] );
		remove_action_doxygen( action_doxygen, services->ToolBar[ sStandardToolBar ] );
		remove_action_doxygen( action_doxygen, services->ToolBar[ sDebugToolBar ] );
		remove_action_doxygen( action_doxygen, services->ToolBar[ sViewToolBar ] );
		remove_action_doxygen( action_doxygen, services->ToolBar[ sDesktopToolBar ] );
		remove_action_doxygen( action_doxygen, services->ToolBar[ sInternetToolBar ] );
	}
	delete action_doxygen;
	delete action_commentary;*/
}

void TCPPOTATemplateWizard::remove_action_doxygen( TAction *action, TToolBar *toolbar )
{
	if ( !toolbar ) return;

	for ( int i = toolbar->ButtonCount - 1; i >= 0; i-- ) {
		TToolButton *button = toolbar->Buttons[ i ];

		if ( button->Action == action ) {
			System::WideChar *LParam = 0;
			toolbar->Perform( CM_CONTROLCHANGE, WPARAM( button ), LParam );
		}
	}
}

ULONG __stdcall TCPPOTATemplateWizard::AddRef( )
{
	return inherited::AddRef( );
}
ULONG __stdcall TCPPOTATemplateWizard::Release( )
{
	return inherited::Release( );
}
HRESULT __stdcall TCPPOTATemplateWizard::QueryInterface( const GUID &iid, void **obj )
{
	QUERY_INTERFACE( IOTAMenuWizard, iid, obj );
	QUERY_INTERFACE( IOTAWizard, iid, obj );
	return inherited::QueryInterface( iid, obj );
}
UnicodeString __fastcall TCPPOTATemplateWizard::GetIDString( )
{
	return "CPP.OTA.Template.Wizard.Main";
}
UnicodeString __fastcall TCPPOTATemplateWizard::GetName( )
{
	return "CPP OTA Temaple Main";
}
TWizardState __fastcall TCPPOTATemplateWizard::GetState( )
{
	TWizardState result;
	result << wsEnabled;
	return result;
}
bool isHeadInserted( const _di_IOTAEditView &editView )
{
	System::UnicodeString headSlice = L"/\**\r\n * @file";
	System::UnicodeString line;
	int i = 1;
	do {
		editView->Buffer->EditPosition->Move( i++, 1 );
		line = editView->Buffer->EditPosition->Read( headSlice.Length( ) );
	} while ( line == "" && i < editView->Buffer->EditPosition->GetLastRow( ) );
	return ( headSlice == line );
}

// IOTAMenuWizard
System::UnicodeString __fastcall TCPPOTATemplateWizard::GetMenuText( )
{
	return "Prueba Menu";
}

void __fastcall TCPPOTATemplateWizard::Execute( )
{
	// DoNotification( "... Hello Dave!" );
	MessageDlg( "Hello Dave... How are you...", mtInformation, TMsgDlgButtons( ) << mbOK, 0 );
	//	TApplicationMainMenu *mainMenu = new TApplicationMainMenu( );
	OnExecuteActionCommentary( 0 );
}

void __fastcall TCPPOTATemplateWizard::BeforeSave( )
{
	inherited::BeforeSave( );
}
void __fastcall TCPPOTATemplateWizard::AfterSave( )
{
	inherited::AfterSave( );
}
void __fastcall TCPPOTATemplateWizard::Destroyed( )
{
	inherited::Destroyed( );
}
void __fastcall TCPPOTATemplateWizard::Modified( )
{
	inherited::Modified( );
}

/*void __fastcall TCPPOTATemplateWizard::AutoSaveTimerEvent( TObject *Sender )
{
	FTimerCounter++;
	ShowMessage( "Contador" );
	if ( FAutoSaveTimer->Enabled ) {
		FAutoSaveTimer->Enabled = false;
		IDEKeyBoardBinding = AddKeyBoardBindingObject( );
}
}


	void __fastcall TCPPOTATemplateWizard::SaveModifiedFiles() {
	 _di_IOTAEditBufferIterator Iterator;
	 _di_IOTAEditorServices EditorServices;
	 if (BorlandIDEServices->Supports(EditorServices)) {
	   if (EditorServices->GetEditBufferIterator(Iterator)) {
		 for (int i = 0; i < Iterator->Count; i++) {
		   if (Iterator->EditBuffers[i]->IsModified) {
			 if (Iterator->EditBuffers[i]->Module->Save(false, !FAppOptions->PromptOnAutoSave)) {
			   DoNotification(
				 Format("... Auto Saved: %s",
				   ARRAYOFCONST((ExtractFileName(Iterator->EditBuffers[i]->FileName)))
				 )
			   );
			 }
		   }
		 }
	   }
	 }
	}       */

// IOTAActionServices
bool __fastcall TCPPOTATemplateWizard::CloseFile( const System::UnicodeString FileName )
{
	return true;
}

bool __fastcall TCPPOTATemplateWizard::OpenFile( const System::UnicodeString FileName )
{
	return true;
}

bool __fastcall TCPPOTATemplateWizard::OpenProject( const System::UnicodeString ProjName, bool NewProjGroup )
{
	return true;
}

bool __fastcall TCPPOTATemplateWizard::ReloadFile( const System::UnicodeString FileName )
{
	return true;
}

bool __fastcall TCPPOTATemplateWizard::SaveFile( const System::UnicodeString FileName )
{
	DoNotification( "Guardar" );
	MessageDlg( "Hello Dave... How are you...", mtInformation, TMsgDlgButtons( ) << mbOK, 0 );
	return true;
}

void __fastcall TCPPOTATemplateWizard::OnExecuteActionDoxygen( System::TObject *Sender )
{
	TCHAR buffer[ MAX_PATH ] = { 0 };
	GetModuleFileName( NULL, buffer, MAX_PATH );
	std::string str( buffer );
	std::string::size_type pos = str.find_last_of( "\\/" );
	// std::wstring::size_type pos = std::wstring( buffer ).find_last_of( L"\\/" );

	std::string path = str.substr( 0, pos );
	std::string cmd1 = "cd " + path;
	std::string cmd2 = "doxygen.exe -g Doxyfile";
	std::string cmd3 = "echo INPUT=\"" + path + "\\Source\" >> Doxyfile";
	std::string cmd4 = "echo OUTPUT_DIRECTORY=\"" + path + "\\docs\" >> Doxyfile";
	std::string cmd5 = "echo GENERATE_HTML=YES >> Doxyfile";
	std::string cmd6 = "echo GENERATE_LATEX=NO >> Doxyfile";
	std::string cmd7 = "doxygen.exe Doxyfile";
	std::string cmd8 = path + "\\docs\\html\\index.html";

	system( ( cmd1 + " & " + cmd2 + " & " + cmd3 + " & " + cmd4 + " & " + cmd5 + " & " + cmd6 + " & " + cmd7 + " & " + cmd8 ).c_str( ) );
}

void __fastcall TCPPOTATemplateWizard::OnExecuteActionCommentary( System::TObject *Sender )
{
	if ( KeyBoradBinding ) {
		// KeyBoradBinding->addCommentarySelectedText( );
	}
}

void __fastcall TCPPOTATemplateWizard::ExtendToolsMenu( void *wizard, System::UnicodeString menu_name )
{
	_di_INTAServices services;
	TMenuItem *new_menu_item;
	TCPPOTATemplateWizard *w = static_cast<TCPPOTATemplateWizard *>( wizard );

	if ( BorlandIDEServices->Supports( services ) ) {
		TAction *action = w->GetActionDoxygen( );

		action = new TAction( 0 );
		action->ActionList = services->ActionList;
		action->Caption = "Doxygen";
		action->Hint = "Display a silly dialog box";
		action->ImageIndex = w->GetImageIndex( );
		System::Classes::TNotifyEvent actionOnExecute = &( w->OnExecuteActionDoxygen );
		action->OnExecute = actionOnExecute;

		for ( int i = 0; i < services->GetMainMenu( )->Items->Count; i++ ) {
			TMenuItem *item = services->GetMainMenu( )->Items->Items[ i ];
			if ( CompareText( item->Name, menu_name ) == 0 ) {
				new_menu_item = new TMenuItem( 0 );
				new_menu_item->Action = action;
				item->Insert( item->Count - 1, new_menu_item );
				break;
			}
		}
	}
}

void __fastcall TCPPOTATemplateWizard::testClick( System::TObject *Sender )
{
	TToolButton *button;
	System::UnicodeString tag = "";

	button = dynamic_cast<TToolButton *>( Sender );

	if ( button ) {
		tag = button->Tag;
	}
	ShowMessage( tag );
}

void __fastcall TCPPOTATemplateWizard::ExtendToolsBar( void *wizard, System::UnicodeString name )
{
	_di_INTAServices services;
	_di_INTAIDEInsightService INTAIDEInsightService;
	_di_INTAComponent INTAComponent;
	TCPPOTATemplateWizard *w = static_cast<TCPPOTATemplateWizard *>( wizard );

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
		// TToolButton *btnToolbar = new TToolButton( 0 );
		TAction *action = w->GetActionCommentary( );

		action = new TAction( 0 );
		// action->ActionList = services->ActionList;
		action->Caption = "Comment Code";
		action->Hint = "Comment Code";
		action->ImageIndex = w->GetImageIndex( );
		System::Classes::TNotifyEvent actionOnExecute = &w->OnExecuteActionCommentary;
		action->OnExecute = actionOnExecute;

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

		Vcl::Controls::TControl *control1 = services->AddToolButton( "NewCustomToolBar", "CommentButton", action );
		TToolButton *buttonComment = static_cast<TToolButton *>( control1 );
		buttonComment->Style = tbsButton;
		buttonComment->Caption = "";
		buttonComment->Hint = "Comment code";
		buttonComment->OnClick = actionOnExecute;

		action = w->GetActionDoxygen( );

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
		buttonGenerateDocumentation->OnClick = actionOnExecute;

		/*System::UnicodeString name = button->Name;
		button->Caption = "";
		button->Hint = "Comment code";
		button->Enabled = true;
		button->EnableDropdown = true;
		button->OnClick = w->testClick;
		System::Classes::TNotifyEvent actionOnExecute = button->OnClick;
		button->OnClick = actionOnExecute; */

		// if ( BorlandIDEServices->Supports( INTAIDEInsightService ) ) {
		/*Vcl::Comctrls::TToolBar *currToolBar = services->GetToolBar( "NewCustomToolBar" );

		for ( int i = 0; i < currToolBar->ButtonCount; i++ ) {
			name = currToolBar->Buttons[ i ]->Name;
			if ( CompareText( currToolBar->Buttons[ i ]->Name, "BotonPrueba" ) == 0 ) {
				System::UnicodeString nameParent = currToolBar->Buttons[ i ]->Parent->Name;
				currToolBar->Buttons[ i ]->Caption = "";
				currToolBar->Buttons[ i ]->Hint = "Comment code";
				break;
			}
		}  */
		//}
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

