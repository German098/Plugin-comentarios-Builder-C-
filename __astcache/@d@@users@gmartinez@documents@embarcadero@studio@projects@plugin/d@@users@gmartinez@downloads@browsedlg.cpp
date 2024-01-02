////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////// Class implementing the Browse functionality //////////////////////////////////////

#include "stdafx.h"
#include "BrowseDlg.h"

CBrowseDlg::CBrowseDlg()
{
}

CBrowseDlg::~CBrowseDlg()
{
}


CString CBrowseDlg::DisplayBrowseFileDialog(BOOL bOpenFile,CString strFileName) 
{
	CString strFilePath = _T("");

	if(bOpenFile)
	{
		CFileDialog dlg(bOpenFile, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_FILEMUSTEXIST, "A2L Files (*.a2l)|*.*a2l||");
		if(dlg.DoModal() == IDOK)
		{
			strFilePath = dlg.GetPathName();
		}

	}
	else
	{
		CFileDialog dlg(bOpenFile,"h",strFileName,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT ,"Header file (*.h)|*.*h||");
		if(dlg.DoModal() == IDOK)
		{
			strFilePath = dlg.GetPathName();	
		}
	}
	
	return strFilePath;
}

int CALLBACK BrowseCallbackProc(HWND hwnd,UINT uMsg,LPARAM lp, LPARAM pData) 
{
         TCHAR szDir[MAX_PATH];

         switch(uMsg) 
		 {
            case BFFM_INITIALIZED: 
			{
               if (GetCurrentDirectory(sizeof(szDir)/sizeof(TCHAR),szDir)) 
			   {
                  // WParam is TRUE since you are passing a path.
                  // It would be FALSE if you were passing a pidl.
                  SendMessage(hwnd,BFFM_SETSELECTION,TRUE,(LPARAM)szDir);
               }
               break;
            }
            case BFFM_SELCHANGED: 
				{
				   // Set the status window to the currently selected path.
				   if (SHGetPathFromIDList((LPITEMIDLIST) lp ,szDir)) 
				   {
					  SendMessage(hwnd,BFFM_SETSTATUSTEXT,0,(LPARAM)szDir);
				   }
				   break;
				}
            default:
               break;
         }
         return 0;
}


CString CBrowseDlg::DisplayBrowseFolderDialog(CWnd *pWnd, CString strMessage) 
{
	if(strMessage.IsEmpty())
		strMessage = _T("Select a Directory");
	CString strDirectory = _T("");

	LPMALLOC pMalloc;

	/* Gets the Shell's default allocator */
	if(::SHGetMalloc(&pMalloc) == NOERROR)
	{
		BROWSEINFO bi;
		char pszBuffer[299];
		LPITEMIDLIST pidl;
		
		// Get help on BROWSEINFO struct - it's got all the bit settings.
		bi.hwndOwner = pWnd->GetSafeHwnd();
		bi.pidlRoot = NULL;
		bi.pszDisplayName = pszBuffer;
		bi.lpszTitle = strMessage;
		bi.ulFlags = BIF_RETURNFSANCESTORS | BIF_RETURNONLYFSDIRS;
		bi.lpfn = BrowseCallbackProc;
		bi.lParam = 0;
		// This next call issues the dialog box.
		if((pidl = ::SHBrowseForFolder(&bi)) != NULL)
		{
			if (::SHGetPathFromIDList(pidl, pszBuffer))
			{ 
				// At this point pszBuffer contains the selected path */.
				strDirectory = pszBuffer;
			}
			// Free the PIDL allocated by SHBrowseForFolder.
			pMalloc->Free(pidl);
		}
		// Release the shell's allocator.
		pMalloc->Release();
	} 

	return strDirectory;
}