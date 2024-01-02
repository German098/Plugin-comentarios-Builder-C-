//---------------------------------------------------------------------------

#pragma hdrstop

#include "CPPNTAActionList.h"
#include <ToolsAPI.hpp>
#include "MyWizard.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void __fastcall addActionToList(void *wizard) {
    MyWizard *w = static_cast<MyWizard*>(wizard);
	_di_INTAServices services;

	if(BorlandIDEServices->Supports(services)){
		TAction *action = w->GetAction();

		action = new TAction(0);
		action->ActionList = services->ActionList;
		action->Caption = w->GetCaption();
		action->Hint = "Display a silly dialog box";
		action->ImageIndex = w->GetImageIndex();
		System::Classes::TNotifyEvent actionOnExecute = &(w->OnExecuteAction);
		action->OnExecute = actionOnExecute;

        TMenuItem *menu_item = w->GetMenuItem();
		for(int i = 0; i < services->GetMainMenu()->Items->Count; i++){
			TMenuItem *item = services->GetMainMenu()->Items->Items[i];

			if(item->Name == "ViewsMenu"){
				menu_item = new TMenuItem(0);
				menu_item->Action = action;
                item->Insert(0, menu_item);
			}
		}
	}
}
