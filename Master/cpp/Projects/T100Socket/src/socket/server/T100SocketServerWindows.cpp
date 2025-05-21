#include "T100SocketServerWindows.h"

#include <windows.h>
#include <ioapiset.h>

T100SocketServerWindows::T100SocketServerWindows() :
    T100SocketServerBase()
{
    //ctor
}

T100SocketServerWindows::~T100SocketServerWindows()
{
    //dtor
}

T100VOID T100SocketServerWindows::Start()
{
    HANDLE      a;
    HANDLE      b;
    ULONG_PTR   c;
    DWORD       d;

    CreateIoCompletionPort(a, b, c, d);
}

T100VOID T100SocketServerWindows::Stop()
{
    //WSAStartup();
}
