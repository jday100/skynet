#include "T100Shell.h"

#include <wx/utils.h>

T100Shell::T100Shell()
{
    //ctor
}

T100Shell::~T100Shell()
{
    //dtor
}

T100VOID T100Shell::Run(const T100WSTRING& value)
{
    wxArrayString   output;

    wxShell(value);
}
