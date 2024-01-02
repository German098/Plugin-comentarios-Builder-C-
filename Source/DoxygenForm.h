//---------------------------------------------------------------------------

#ifndef DoxygenFormH
#define DoxygenFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxTextEdit.hpp"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
  __published: // IDE-managed Components
	TButton *ButtonOK;
	TcxTextEdit *cxTextEditPathConfig;
	TButton *ButtonSearchFolder;
	TStaticText *StaticTextConfigFile;
	TStaticText *StaticText1;
	TcxTextEdit *cxTextEditPathFiles;
	TButton *ButtonSearchFiles;
	TCheckBox *CheckBoxUML;
	void __fastcall ButtonOKClick( TObject *Sender );
	void __fastcall ButtonSearchFolderConfig( TObject *Sender );
	void __fastcall ButtonSearchFolderFiles( TObject *Sender );
	void __fastcall CheckBoxUMLClick( TObject *Sender );

  private: // User declarations
	System::UnicodeString configPath;
	System::UnicodeString filesPath;
	bool UMLDiagrams;

  public: // User declarations
	__fastcall TForm1( TComponent *Owner );
	System::UnicodeString __fastcall getConfigPath( )
	{
		return configPath;
	}
	System::UnicodeString __fastcall getFilesPath( )
	{
		return filesPath;
	}
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

