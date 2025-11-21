#ifndef T100PLUGINDOCK_H
#define T100PLUGINDOCK_H

#include "T100Plugin.h"

class T100PluginDock : public T100Plugin
{
    public:
        T100PluginDock();
        virtual ~T100PluginDock();

        virtual T100VOID            Init(T100ExtensionManager*);

    protected:
        T100VOID                    Load();

    private:
};

#endif // T100PLUGINDOCK_H
