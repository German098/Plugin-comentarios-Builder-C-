//---------------------------------------------------------------------------

#pragma hdrstop

#include "CPPOTARegisterDLL.h"
#include "MyWizard.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

/*#ifdef DLL
#define BorlandIDEServices LocalIDEServices
extern _di_IBorlandIDEServices LocalIDEServices;
#endif*/

extern "C" bool __stdcall __declspec(dllexport) INITWIZARD0001(
  const _di_IBorlandIDEServices Service,
  TWizardRegisterProc RegisterWizard,
  TWizardTerminateProc&)
{
  //RegisterComponent
  //: @note Not Required
  //LocalIDEServices = Service; // get reference to the BorlandIDEServices
  RegisterWizard(new MyWizard());
  return true;
}
