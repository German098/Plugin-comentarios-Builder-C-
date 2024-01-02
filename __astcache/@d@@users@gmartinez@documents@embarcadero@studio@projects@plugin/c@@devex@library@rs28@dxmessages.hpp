// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxMessages.pas' rev: 35.00 (Windows)

#ifndef DxmessagesHPP
#define DxmessagesHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.Messages.hpp>

//-- user supplied -----------------------------------------------------------

namespace Dxmessages
{
//-- forward type declarations -----------------------------------------------
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
static const System::Word WM_DX = System::Word(0x8064);
static const System::Word DXM_NCSIZECHANGED = System::Word(0x8065);
static const System::Word DXM_SYNCHRONIZETHREADS = System::Word(0x8066);
static const System::Word DXM_CONTAINERSETFOCUS = System::Word(0x8067);
static const System::Word DXM_REFRESHCUSTOMIZATION = System::Word(0x8068);
static const System::Word DXM_UPDATEIMAGES = System::Word(0x8069);
static const System::Word DXM_RECALCULATE = System::Word(0x806a);
static const System::Word DXM_POSTAPPKEYDOWN = System::Word(0x806b);
static const System::Word DXM_SCALECHANGING = System::Word(0x806c);
static const System::Word DXM_SCALECHANGED = System::Word(0x806d);
static const System::Word DXM_UIADORNERMANAGERUPDATE = System::Word(0x806e);
static const System::Word DXM_MOUSEHWHEEL = System::Word(0x806f);
static const System::Word DXM_CLOSEPOPUPWINDOW = System::Word(0x807d);
static const System::Word DXM_SHOWPOPUPWINDOW = System::Word(0x807e);
static const System::Word DXM_SHORTREFRESHCONTAINER = System::Word(0x807f);
static const System::Word DXM_UPDATESCROLLBARS = System::Word(0x8080);
static const System::Word DXM_BUFFEREDPAINTONGLASS = System::Word(0x8081);
static const System::Word DXM_UPDATEEDITVALUE = System::Word(0x8082);
static const System::Word DXM_UPDATEWINDOWREGION = System::Word(0x8083);
static const System::Word DXM_POPUPCONTROLKEY = System::Word(0x8096);
static const System::Word DXM_DROPDOWNBYPASTE = System::Word(0x8097);
static const System::Word DXM_DROPDOWNPOPUPMENU = System::Word(0x8098);
static const System::Word DXM_CLOSEUPPOPUPMENU = System::Word(0x8099);
static const System::Word DXM_UPDATENONCLIENTAREA = System::Word(0x809a);
static const System::Word DXM_GETHEADERITEMINFO = System::Word(0x809b);
static const System::Word DXM_ADJUSTPOSITION = System::Word(0x809c);
static const System::Word DXM_ADJUSTSIZE = System::Word(0x809d);
static const System::Word DXM_VG_PROPERTYCHANGED = System::Word(0x80af);
static const System::Word DXM_BAR_REPAINTBAR = System::Word(0x80c8);
static const System::Word DXM_BAR_LB_SYNCHRONIZE = System::Word(0x80c9);
static const System::Word DXM_BAR_LB_SYNCHRONIZESELECTION = System::Word(0x80ca);
static const System::Word DXM_BAR_LB_UPDATEEVENTS = System::Word(0x80cb);
static const System::Word DXM_BAR_LB_DEFERREDCALLSYNCHRONIZATION = System::Word(0x80cc);
static const System::Word DXM_BAR_SELECTAPPMENUFIRSTITEMCONTROL = System::Word(0x80cd);
static const System::Word DXM_BAR_SHOWKEYTIPS = System::Word(0x80ce);
static const System::Word DXM_BAR_FASTCOMMAND = System::Word(0x80cf);
static const System::Word DXM_BAR_SHOWSYSTEMMENU = System::Word(0x80d0);
static const System::Word DXM_BAR_HIDEALL = System::Word(0x80d2);
static const System::Word DXM_BAR_MERGE = System::Word(0x80d3);
static const System::Word DXM_DOCK_DESTROYCONTROLS = System::Word(0x80e1);
static const System::Word DXM_DOCK_PURGEPARENT = System::Word(0x80e2);
static const System::Word DXM_DOCK_CHECKACTIVEDOCKCONTROL = System::Word(0x80e3);
static const System::Word DXM_LAYOUT_PLACECONTROLS = System::Word(0x80fb);
static const System::Word DXM_LAYOUT_BUILDSELECTIONLAYER = System::Word(0x80fc);
static const System::Word DXM_LAYOUT_INVALIDATESELECTIONLAYER = System::Word(0x80fd);
static const System::Word DXM_LAYOUT_LAYOUTCHANGED = System::Word(0x80fe);
static const System::Word DXM_LAYOUT_UPDATEFLOAT = System::Word(0x80ff);
static const System::Word DXM_LAYOUT_UPDATESCROLLPOS = System::Word(0x8100);
static const System::Word DXM_SKINS_POSTREDRAW = System::Word(0x8113);
static const System::Word DXM_SKINS_CHILDCHANGED = System::Word(0x8114);
static const System::Word DXM_SKINS_POSTCHECKRGN = System::Word(0x8115);
static const System::Word DXM_SKINS_POSTCREATE = System::Word(0x8116);
static const System::Word DXM_SKINS_POSTMSGFORMINIT = System::Word(0x8117);
static const System::Word DXM_SKINS_HASOWNSKINENGINE = System::Word(0x8118);
static const System::Word DXM_SKINS_SUPPRESSMDICHILDBORDERS = System::Word(0x8119);
static const System::Word DXM_SKINS_GETISSKINNED = System::Word(0x811a);
static const System::Word DXM_SKINS_SETISSKINNED = System::Word(0x811b);
static const System::Word DXM_SKINS_POSTSKINCHANGED = System::Word(0x811c);
static const System::Word DXM_SPELL_AUTOCORRECT = System::Word(0x812c);
static const System::Word DXM_SPELL_REDRAWMISSPELLINGS = System::Word(0x812d);
static const System::Word DXM_PS_FREEEXPLORERITEM = System::Word(0x8145);
static const System::Word DXM_PS_UPDATEMARGINS = System::Word(0x8146);
static const System::Word DXM_PS_UPDATESTATUSPROGRESS = System::Word(0x8147);
static const System::Word DXM_PS_PRINTSTYLELISTCHANGED = System::Word(0x8148);
static const System::Word DXM_PS_PRINTERLISTCHANGED = System::Word(0x8149);
static const System::Word DXM_PS_INITIALIZEPRINTER = System::Word(0x814a);
static const System::Word DXM_PS_CREATEFOLDER = System::Word(0x814b);
static const System::Word DXM_BREADCRUMBEDIT_CLOSEPOPUPWINDOW = System::Word(0x815e);
static const System::Word DXM_BREADCRUMBEDIT_HIDESUGGESTIONS = System::Word(0x815f);
static const System::Word DXM_BREADCRUMBEDIT_RELEASEPATHEDITOR = System::Word(0x8160);
static const System::Word DXM_RIBBONFORM_NCCHANGED = System::Word(0x8177);
static const System::Word DXM_RIBBONFORM_SYSCOMMAND = System::Word(0x8178);
static const System::Word DXM_RIBBONFORM_POSTUPDATEREGION = System::Word(0x8179);
static const System::Word DXM_RIBBON_SHOWAPPLICATIONMENU = System::Word(0x817a);
static const System::Word DXM_RIBBON_RECALCULATE = System::Word(0x817b);
static const System::Word DXWM_FILTERCONTROL_DROPDOWNMENUCLOSED = System::Word(0x8190);
static const System::Word DXM_TILECONTROL_HIDEGROUPCAPTIONEDITORS = System::Word(0x81a9);
static const System::Word DXM_UITHREADINVOKE = System::Word(0x81c2);
static const System::Word DXM_RICHEDITCONTROL_UITHREADINVOKE = System::Word(0x81c2);
static const System::Word DXM_CANCELHINT = System::Word(0x81d6);
static const System::Word DXM_POSTHIDEEDIT = System::Word(0x81d7);
}	/* namespace Dxmessages */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXMESSAGES)
using namespace Dxmessages;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxmessagesHPP
