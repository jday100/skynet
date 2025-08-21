#include "T100Shell.h"

#include <windows.h>

static HANDLE   g_stdOutRead                = T100NULL;
static HANDLE   g_stdOutWrite               = T100NULL;

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
    //Execute(value);
    Test(value);
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

T100VOID T100Shell::Test(const T100WSTRING& value)
{
    SECURITY_ATTRIBUTES     securityAttributes;

    securityAttributes.nLength                  = sizeof(SECURITY_ATTRIBUTES);
    securityAttributes.bInheritHandle           = TRUE;
    securityAttributes.lpSecurityDescriptor     = NULL;

    if(!CreatePipe(&g_stdOutRead, &g_stdOutWrite, &securityAttributes, 0)){
        return;
    }

    if(!SetHandleInformation(g_stdOutRead, HANDLE_FLAG_INHERIT, 0)){
        return;
    }

    STARTUPINFOW            start;
    PROCESS_INFORMATION     process;

    ZeroMemory(&start, sizeof(start));

    start.cb            = sizeof(start);
    start.hStdOutput    = g_stdOutWrite;
    start.dwFlags       |= STARTF_USESTDHANDLES;

    ZeroMemory(&process, sizeof(process));

    if(!CreateProcessW(NULL,
                       value.c_str(),
                       NULL,
                       NULL,
                       FALSE,
                       CREATE_NO_WINDOW,
                       NULL,
                       NULL,
                       &start,
                       &process)){
        return;
    }

    DWORD           read, write;
    T100WCHAR       buffer[4096];

    read    = 4096;

    ReadFile(g_stdOutWrite, buffer, read, &write, NULL);

    WaitForSingleObject(process.hProcess, INFINITE);

    CloseHandle(process.hProcess);
    CloseHandle(process.hThread);

    CloseHandle(g_stdOutRead);
    CloseHandle(g_stdOutWrite);
}
