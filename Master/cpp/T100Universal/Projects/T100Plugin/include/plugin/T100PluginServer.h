#ifndef T100PLUGINSERVER_H
#define T100PLUGINSERVER_H

#include <unordered_map>
#include "T100Plugin.h"

using namespace T100LIBRARY;

namespace T100UNIVERSAL{

#define     T100PLUGIN_HASH                 std::unordered_map<T100WSTRING, T100Plugin*>

class T100PluginServer : public T100Class
{
    public:
        T100PluginServer();
        virtual ~T100PluginServer();

        virtual T100VOID            Start();
        virtual T100VOID            Stop();

        virtual T100VOID            Load(const T100WSTRING&);

        T100VOID*                   GetMethod(const T100WSTRING&, const T100WSTRING&);

    protected:
        T100PLUGIN_HASH             m_plugins;

    private:
        T100WSTRING                 GetFileName(const T100WSTRING&);
};

}

#endif // T100PLUGINSERVER_H
