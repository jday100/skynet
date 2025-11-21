#include <libloaderapi.h>

typedef     int(*FUNC)(void);

int main()
{
    HMODULE     module      = LoadLibrary("libT100Plugin.dll");

    if(!module){
        return -1;
    }

    FARPROC     proc        = GetProcAddress(module, "Init");

    if(!proc){
        return -1;
    }
    FUNC    func    = (FUNC)proc;

    int result  = func();

    proc        = GetProcAddress(module, "Message");

    if(!proc){
        return -1;
    }

    FUNC    msg     = (FUNC)proc;

    result  = msg();

    return result;
}
