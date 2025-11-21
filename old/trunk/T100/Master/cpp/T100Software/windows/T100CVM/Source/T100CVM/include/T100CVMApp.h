#ifndef T100CVMAPP_H
#define T100CVMAPP_H

#include "gui/T100Win32Application.h"
#include "T100CVMSkeletal.h"
#include "plugin/T100PluginServer.h"

using namespace T100WINDOWS;
using namespace T100UNIVERSAL;

class T100CVMApp : public T100Win32Application
{
    public:
        T100CVMApp();
        virtual ~T100CVMApp();

        virtual T100VOID            Create();
        virtual T100VOID            Destroy();

    protected:
        T100CVMSkeletal             m_skeletal;
        T100PluginServer            m_server;

    private:
        T100VOID            OnStart(T100MenuEvent&);
        T100VOID            OnStop(T100MenuEvent&);
};

#endif // T100CVMAPP_H
