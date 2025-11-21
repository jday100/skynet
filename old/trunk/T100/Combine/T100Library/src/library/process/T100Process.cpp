#include "library\process\T100Process.h"

#include <processthreadsapi.h>

T100Process::T100Process()
{
    //ctor
}

T100Process::~T100Process()
{
    //dtor
}

T100BOOL T100Process::Run(T100STRING cmd)
{
    DWORD           flags           = 0x00000010;
    DWORD           pid             = 0;

    STARTUPINFO             startupinfo     = {0};
    PROCESS_INFORMATION     processinfo     = {0};

    startupinfo.cb      = sizeof(STARTUPINFO);

    T100CHAR*   value   = const_cast<T100CHAR*>(cmd.c_str());

    WINBOOL     result  = CreateProcess(
                                        NULL,
                                        value,
                                        NULL,
                                        NULL,
                                        FALSE,
                                        flags,
                                        NULL,
                                        NULL,
                                        &startupinfo,
                                        &processinfo
                                        );

    if(result){
        pid     = processinfo.dwProcessId;
    }
    return result;
}
