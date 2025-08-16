#include "T100Shell.h"

#include <windows.h>

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
    STARTUPINFOW            start;
    PROCESS_INFORMATION     process;

    ZeroMemory(&start, sizeof(start));
    start.cb    = sizeof(start);
    ZeroMemory(&process, sizeof(process));

    if(!CreateProcessW(NULL,
                      value.c_str(),
                      NULL,
                      NULL,
                      FALSE,
                      CREATE_NO_WINDOW,         //CREATE_NEW_CONSOLE,
                      NULL,
                      NULL,
                      &start,
                      &process)){
        return;
    }

    WaitForSingleObject(process.hProcess, INFINITE);

    CloseHandle(process.hProcess);
    CloseHandle(process.hThread);
}
