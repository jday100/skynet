#ifndef T100PLUGINMANAGER_H
#define T100PLUGINMANAGER_H

#include "T100Plugin.h"

class T100ExtensionManager;

class T100PluginManager
{
    public:
        T100PluginManager();
        virtual ~T100PluginManager();

        T100VOID                    SetExtensionManager(T100ExtensionManager*);
        T100ExtensionManager*       GetExtensionManager();

        virtual T100VOID            Load(T100Plugin*);

    protected:
        T100ExtensionManager*       m_extensionManager      = T100NULL;

    private:
};

#endif // T100PLUGINMANAGER_H
