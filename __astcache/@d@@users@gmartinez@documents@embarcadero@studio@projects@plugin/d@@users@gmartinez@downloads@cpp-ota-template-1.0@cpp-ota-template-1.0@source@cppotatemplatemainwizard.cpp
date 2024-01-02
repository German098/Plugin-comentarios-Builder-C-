#pragma hdrstop
#include <CPPOTATemplateMainWizard.h>
#include <Dialogs.hpp>
#include <CPPOTATemplatePkgDLLInit.h>
//#include <CPPOTATemplateSplashScreen.h>
//#include <CPPOTATemplateAboutBoxPlugin.h>
//#include <TCPPOTATemplatePaintNotifier.h>
#include "CPPOTATemplateMacros.h"
//#include "CPPOTAKeyBoardBinding.h"
#include <Lmcons.h>
#include "Header.h"
//#include "WrapperParser.h"

#pragma package(smart_init)
/* TCPPOTATemplateWizard Implementation */
__fastcall TCPPOTATemplateWizard::TCPPOTATemplateWizard(String strObjectName) :
  TDGHNotifierObject(strObjectName) {
  //: @note Not required now
  //: #ifndef DLL
  //AddSplashScreen();
  //: #endif
  //FAboutBoxPlugin = AddAboutBoxPlugin();
  FIDENotifier = AddIDENotifier();
  KeyBoradBinding = AddKeyBoardBindingObject();
  /*FAppOptions = new TCPPOTATemplateOptions();
  FIDEOptions = AddOptionsFrameToIDE(FAppOptions);
  FTimerCounter = 0;
  FAutoSaveTimer = new TTimer(NULL);
  FAutoSaveTimer->Interval = 20;
  FAutoSaveTimer->OnTimer = AutoSaveTimerEvent;
  FAutoSaveTimer->Enabled = true;*/
  //FPointNotifier = AddPaintNotifier();
  //KeyBoradBinding = AddKeyBoardBinding();
}

__fastcall TCPPOTATemplateWizard::~TCPPOTATemplateWizard() {
  //RemoveOptionsFrameFromIDE(FIDEOptions);
  //delete FAppOptions;
  //delete FAutoSaveTimer;
  //RemoveAboutBoxPlugin(FAboutBoxPlugin);
  RemoveIDENotifier(FIDENotifier);
  //RemovePaintNotifier(FPointNotifier);
}
ULONG __stdcall TCPPOTATemplateWizard::AddRef() {
  return inherited::AddRef();
}
ULONG __stdcall TCPPOTATemplateWizard::Release() {
  return inherited::Release();
}
HRESULT __stdcall TCPPOTATemplateWizard::QueryInterface(const GUID& iid, void** obj) {
  //QUERY_INTERFACE(IOTAMenuWizard, iid, obj);
  QUERY_INTERFACE(IOTAWizard, iid, obj);
  return inherited::QueryInterface(iid, obj);
}
UnicodeString __fastcall TCPPOTATemplateWizard::GetIDString() {
  return "CPP.OTA.Template.Wizard";
}
UnicodeString __fastcall TCPPOTATemplateWizard::GetName() {
  return "CPP OTA Temaple";
}
TWizardState  __fastcall TCPPOTATemplateWizard::GetState() {
  TWizardState result;
  result << wsEnabled;
  return result;
}
bool isHeadInserted( const _di_IOTAEditView &editView ) {
	System::UnicodeString headSlice = L"/\**\r\n * @file";
	System::UnicodeString line;
    int i = 1;
	do{
		editView->Buffer->EditPosition->Move(i++, 1);
		line = editView->Buffer->EditPosition->Read(headSlice.Length());
	} while(line == "" && i < editView->Buffer->EditPosition->GetLastRow());
	return (headSlice == line);
}
void __fastcall TCPPOTATemplateWizard::Execute() {
  DoNotification("... Hello Dave!");
  MessageDlg("Hello Dave... How are you...", mtInformation, TMsgDlgButtons() << mbOK, 0);
  _di_IOTAEditorServices editorServices;
  _di_IOTAEditView editView;
  _di_IOTAEditBufferIterator Iterator;
  _di_IOTAActionServices services;
  TOTAEditPos initCursorPos;
  int lineLength;
  System::UnicodeString line;
  System::UnicodeString module_name;
  System::UnicodeString header;
  System::UnicodeString author;
  System::UnicodeString actual_time;
  if(BorlandIDEServices->Supports(editorServices)){
		editView = editorServices->TopView;
		if(!editView) return;
		// Posición cursor
		initCursorPos = editView->GetCursorPos();

        editView->Buffer->Undo();

		if(!isHeadInserted(editView)){
			// Cabecera
			editView->Buffer->EditPosition->MoveEOL();
			lineLength = editView->GetCursorPos().Col;
			editView->Buffer->EditPosition->Move(1, 1);
			//editView->Buffer->EditPosition->Move(initCursorPos.Line, 1);
			line = editView->Buffer->EditPosition->Read(lineLength);
			module_name = ChangeFileExt(ExtractFileName(editView->Buffer->GetFileName()), "");
			lengthFile = module_name.Length();
			DWORD username_len = UNLEN + 1;
			char username[UNLEN + 1];
			GetUserNameA(username, &username_len);
			author = username;
			lengthAuthor = author.Length();
			std::time_t time = std::time(0);
			actual_time = std::ctime(&time);
			lengthDate = actual_time.Length();
			header = header_comment(module_name, author, actual_time);
			editView->Buffer->EditPosition->InsertText(header);

			if(line != "\r" && line != ""){
				editView->Buffer->EditPosition->InsertCharacter('\n');
			}
		}
		else {
			MessageDlg("Ya existe cabecera", mtInformation, TMsgDlgButtons() << mbOK, 0);
		}
		if( editView->Buffer->IsModified ) {
			if( editView->GetBuffer( )->GetModule( )->Save(false, true) ) {
				DoNotification("... Auto Saved:");
				module_name = ChangeFileExt(ExtractFileName(editView->Buffer->GetFileName()), "");
				DWORD username_len = UNLEN + 1;
				char username[UNLEN + 1];
				GetUserNameA(username, &username_len);
				author = username;
				std::time_t time = std::time(0);
				actual_time = std::ctime(&time);
				editView->Buffer->EditPosition->Move(2, 1);
				editView->Buffer->EditPosition->MoveEOL();
				editView->Buffer->EditPosition->BackspaceDelete(lengthFile);
				editView->Buffer->EditPosition->InsertText(module_name);
				editView->Buffer->EditPosition->Move(5, 1);
				editView->Buffer->EditPosition->MoveEOL();
				editView->Buffer->EditPosition->BackspaceDelete(lengthAuthor);
				editView->Buffer->EditPosition->InsertText(author);
				editView->Buffer->EditPosition->Move(6, 1);
				editView->Buffer->EditPosition->MoveEOL();
				editView->Buffer->EditPosition->BackspaceDelete(lengthDate);
				editView->Buffer->EditPosition->InsertText(actual_time);
			}

			//System::UnicodeString author, System::UnicodeString date
		}
  }
}

//UnicodeString __fastcall TCPPOTATemplateWizard::GetMenuText() {
//  return "My CPP OTA Template Menu";
//}

void __fastcall TCPPOTATemplateWizard::BeforeSave() {
  inherited::BeforeSave();
}
void __fastcall TCPPOTATemplateWizard::AfterSave() {
  inherited::AfterSave();
}
void __fastcall TCPPOTATemplateWizard::Destroyed() {
  inherited::Destroyed();
}
void __fastcall TCPPOTATemplateWizard::Modified() {
  inherited::Modified();
}

/*void __fastcall TCPPOTATemplateWizard::AutoSaveTimerEvent(TObject* Sender) {
  FTimerCounter++;
  if (FTimerCounter >= FAppOptions->AutoSaveInterval) {
    FAutoSaveTimer->Enabled = false;
    try {
      FTimerCounter = 0;
      if (FAppOptions->EnableAutoSave) {
		SaveModifiedFiles();
      }
    } __finally {
      FAutoSaveTimer->Enabled = true;
    }
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
}        */

// class TKeyboardBinding

__fastcall TKeyboardBinding::TKeyboardBinding(TShortCut *keys) : TDGHNotifierObject("") {
	this->keys = keys;
}

__fastcall TKeyboardBinding::~TKeyboardBinding() {

}

TBindingType __fastcall TKeyboardBinding::GetBindingType() {
    return TBindingType::btPartial;
}

System::UnicodeString __fastcall TKeyboardBinding::GetDisplayName() {
    return L"Debugging Tools Bindings";
}

System::UnicodeString __fastcall TKeyboardBinding::GetName() {
    return L"DebuggingToolsBindings";
}

void __fastcall TKeyboardBinding::BindKeyboard(const _di_IOTAKeyBindingServices BindingServices) {
	//if(BorlandIDEServices->Supports(BindingServices)){
		BindingServices->AddKeyBinding( keys, 0, addCommentary, 0 );
			//MessageDlg("OKKK", mtInformation, TMsgDlgButtons() << mbOK, 0);
	//}
}

void __fastcall TKeyboardBinding::addCommentary( const _di_IOTAKeyContext Context, System::Classes::TShortCut KeyCode, TKeyBindingResult &BindingResult ) {
	_di_IOTAEditPosition EditPosition;
	_di_IOTAEditBlock EditBlock;
	int currentRow = 0;
	int currentRowEnd = 0;
	int blockSize = 0;
    bool isAutoIndent = false;
	System::UnicodeString text;

	EditPosition = Context->GetEditBuffer()->GetEditPosition();
	EditBlock = Context->GetEditBuffer()->GetEditBlock();
	EditPosition->Save();
	EditBlock->Save();

	currentRow = EditPosition->GetRow();
	blockSize = EditBlock->Size;
	isAutoIndent = Context->GetEditBuffer()->GetBufferOptions()->GetAutoIndent();

	if(isAutoIndent)
		Context->GetEditBuffer()->GetBufferOptions()->AutoIndent = false;

	if(blockSize != 0){
		if((EditBlock->GetEndingRow() == currentRow)) {
			// Una línea
			EditPosition->MoveEOL();
			currentRowEnd = EditPosition->GetColumn();
			EditPosition->MoveBOL();
			text = EditPosition->Read(currentRowEnd - 1);
			//
			EditPosition->Move(currentRow - 1, 1);
			EditPosition->MoveEOL();
			EditPosition->InsertCharacter('\n');

			EditPosition->InsertText(text + L" nuevo");
		}
		else {
			text = EditBlock->GetText();
			EditPosition->Move(EditBlock->GetStartingRow() - 1, 1);
			EditPosition->MoveEOL();
			EditPosition->InsertCharacter('\n');
			EditPosition->InsertText(text + L" nuevo bloque");
		}
	}

	if(isAutoIndent) {
		EditPosition->Restore();
		EditBlock->Restore();
	}

	std::wstring wsin(text.c_str());
	std::string in(wsin.begin(), wsin.end());
	std::string res;
	//WrapperParser::parseString(in, res);
}

// IOTANotifer
void __fastcall TKeyboardBinding::BeforeSave() {
  inherited::BeforeSave();
}

void __fastcall TKeyboardBinding::AfterSave() {
  inherited::AfterSave();
}

void __fastcall TKeyboardBinding::Destroyed() {
  inherited::Destroyed();
}

void __fastcall TKeyboardBinding::Modified() {
  inherited::Modified();
}

ULONG __stdcall TKeyboardBinding::AddRef() {
  return inherited::AddRef();
}
ULONG __stdcall TKeyboardBinding::Release() {
  return inherited::Release();
}

HRESULT __stdcall TKeyboardBinding::QueryInterface(const GUID& iid, void** obj) {
  QUERY_INTERFACE(IOTAKeyboardBinding, iid, obj);
  //QUERY_INTERFACE(IOTAWizard, iid, obj);
  return inherited::QueryInterface(iid, obj);
}

TKeyboardBinding* __fastcall AddKeyBoardBindingObject() {
	_di_IOTAKeyboardServices IOTAKeyboardBinding;

	if (BorlandIDEServices->Supports(IOTAKeyboardBinding)) {
		TShortCut *keys = new TShortCut(TextToShortCut(L"Ctrl+Shift+D"));
		TKeyboardBinding *KeyBoardBinding = new TKeyboardBinding(keys);

		IOTAKeyboardBinding->AddKeyboardBinding( KeyBoardBinding );


		return KeyBoardBinding;
	}

	return 0;
}
