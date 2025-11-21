#ifndef T100PLUGINMANAGER_H
#define T100PLUGINMANAGER_H

#include "T100Library.h"
#include "T100Plugin.h"

class T100PluginManager
{
    public:
        T100PluginManager();
        virtual ~T100PluginManager();

        T100VOID                    Start(T100VOID*);
        T100VOID                    Stop();

    protected:
        T100VOID*                   m_handler;
        T100LIBRARY_HASH            m_libraries;

    private:
        T100BOOL                    Load();
        T100BOOL                    Launch(T100Library*);
        T100BOOL                    SignIn(T100Library*);
        T100BOOL                    SignOut(T100Library*);
};

#endif // T100PLUGINMANAGER_H
