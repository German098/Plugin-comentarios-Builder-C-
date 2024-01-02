//---------------------------------------------------------------------------

#ifndef CPPOTAMacroUnitH
#define CPPOTAMacroUnitH
//---------------------------------------------------------------------------
#include <ToolsAPI.hpp>

#define QUERY_INTERFACE(T, iid, obj)   \
  if ((iid) == __uuidof(T)) {          \
    *(obj) = static_cast<T*>(this);    \
    static_cast<T*>(*(obj))->AddRef(); \
    return S_OK;                       \
  }

#endif
