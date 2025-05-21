#ifndef T100PLUGINSERVER_H
#define T100PLUGINSERVER_H

#include <unordered_map>
#include "base/T100Class.h"

class T100Plugin;

#define     T100PLUGIN_HASH                 std::unordered_map<T100WSTRING, T100Plugin*>

class T100PluginServer : public T100Class
{
    public:
        T100PluginServer();
        virtual ~T100PluginServer();

        virtual T100VOID            Start();
        virtual T100VOID            Stop();

        virtual T100VOID            Execute(T100WSTRING);

    protected:
        T100PLUGIN_HASH             m_plugins;

    private:
        T100WSTRING                 GetFileName(T100WSTRING);
};

#endif // T100PLUGINSERVER_H
