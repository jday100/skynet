#ifndef T100PLUGINMANAGER_H
#define T100PLUGINMANAGER_H

#include "T100Common.h"

class T100MainFrame;

class T100PluginManager
{
    public:
        T100PluginManager();
        virtual ~T100PluginManager();

        T100VOID            Start(T100MainFrame*);
        T100VOID            Stop();

    protected:
        T100MainFrame*      m_frame         = T100NULL;

        T100BOOL            Load(T100WSTRING&);

    private:
};

#endif // T100PLUGINMANAGER_H
