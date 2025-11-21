#ifndef T100PLUGIN_H
#define T100PLUGIN_H

#include "T100Common.h"

class T100ExtensionManager;

class T100Plugin
{
    public:
        T100Plugin();
        virtual ~T100Plugin();

        T100ExtensionManager*           GetExtensionManager();

        virtual T100VOID                Init(T100ExtensionManager*);

    protected:
        T100ExtensionManager*           m_extensionManager      = T100NULL;

    private:
};

#endif // T100PLUGIN_H
