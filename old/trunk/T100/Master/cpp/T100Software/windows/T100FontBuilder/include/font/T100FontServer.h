#ifndef T100FONTSERVER_H
#define T100FONTSERVER_H

#include "plugin/T100ExtensionServer.h"

using namespace T100UNIVERSAL;

class T100FontServer : public T100ExtensionServer
{
    public:
        T100FontServer();
        virtual ~T100FontServer();

        virtual T100VOID            Start();
        virtual T100VOID            Stop();

        virtual T100VOID            Load();

    protected:

    private:
};

#endif // T100FONTSERVER_H
