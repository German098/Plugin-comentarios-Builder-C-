/*******************************************************************************
*                    Delphi Diesel Systems
*
*                    This document is the property of
*                    Delphi Diesel Systems
*                    It must not be copied (in whole or in part)
*                    or disclosed without prior written consent
*                    of the company. Any copies by any method
*                    must also include a copy of this legend.
********************************************************************************
* Task File History: This comment block is automatically
*                    updated by the configuration management tool
*                    DO NOT Update manually
*                    
*                    written by: Sudeep Gangadharan (DDS, 2006)
*------------------------------------------------------------------------------*
*/

////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// Interface for the CBrowseDlg class /////////////////////////////////////////

class CBrowseDlg
{
public:
	CBrowseDlg();
	~CBrowseDlg();

	CString DisplayBrowseFileDialog(BOOL bOpenFile = TRUE,CString strFileName = _T("")); 
	CString DisplayBrowseFolderDialog(CWnd *pWnd, CString strMessage); 
};
