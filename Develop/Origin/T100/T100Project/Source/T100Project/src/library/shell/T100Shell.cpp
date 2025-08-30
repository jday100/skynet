#include "T100Shell.h"

#include <iostream>
#include "T100ExecuteProcess.h"
#include "T100ProjectInvoking.h"

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

    T100ExecuteProcess*     process     = T100NEW T100ExecuteProcess(&output, &error);

    if(wxExecute(value, wxEXEC_ASYNC | wxEXEC_SHOW_CONSOLE , process) == 0){
        return;
    }

    while(process->IsRunning()){
        process->FlushPipe();

        for(wxString item : output){
            std::cout << item;
            T100ProjectInvoking::OnBuildMessage(item.ToStdWstring());
        }
        for(wxString item : error){
            std::cout << item;
        }
        break;
    }

    process->ExitCode();
}
