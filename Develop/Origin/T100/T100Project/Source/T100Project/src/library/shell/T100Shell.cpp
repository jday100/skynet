#include "T100Shell.h"

#include "T100ExecuteProcess.h"

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
    Execute(value);
}

T100VOID T100Shell::Execute(const T100WSTRING& value)
{
    wxArrayString   output;
    wxArrayString   error;

    T100ExecuteProcess      process(&output, &error);

    if(wxExecute(value, wxEXEC_ASYNC, &process) == 0){
        return;
    }

    while(process.IsRunning()){

    }

    process.ExitCode();
}
