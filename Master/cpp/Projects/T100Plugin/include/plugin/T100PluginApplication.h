#ifndef T100PLUGINAPPLICATION_H
#define T100PLUGINAPPLICATION_H

#include "plugin/T100PluginServer.h"
#include "gui/T100Win32Application.h"

class T100PluginApplication : public T100Win32Application
{
    public:
        T100PluginApplication();
        virtual ~T100PluginApplication();

        virtual T100VOID            Create();
        virtual T100VOID            Destroy();

    protected:
        T100PluginServer            m_server;

    private:
};

#endif // T100PLUGINAPPLICATION_H
