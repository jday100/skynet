#ifndef T100SOCKETSERVERWINDOWS_H
#define T100SOCKETSERVERWINDOWS_H

#include "socket/server/T100SocketServerBase.h"

class T100SocketServerWindows : public T100SocketServerBase
{
    public:
        T100SocketServerWindows();
        virtual ~T100SocketServerWindows();

        virtual T100VOID            Start();
        virtual T100VOID            Stop();

    protected:

    private:
};

#endif // T100SOCKETSERVERWINDOWS_H
