#include "T100Execute.h"

#include <wx/utils.h>

T100Execute::T100Execute(const T100WSTRING& command, T100Output& output)
{
    //ctor
    wxArrayString       message;
    wxArrayString       error;

    wxExecute(command, message, error);

    for(wxString item : message){
        output.Print(item.ToStdWstring());
    }
    for(wxString item : error)
    {
        output.Print(item.ToStdWstring());
    }
}

T100Execute::~T100Execute()
{
    //dtor
}
