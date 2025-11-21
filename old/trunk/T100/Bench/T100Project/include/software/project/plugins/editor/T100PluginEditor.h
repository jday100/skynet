#ifndef T100PLUGINEDITOR_H
#define T100PLUGINEDITOR_H

#include "T100Plugin.h"

class T100PluginEditor : public T100Plugin
{
    public:
        T100PluginEditor();
        virtual ~T100PluginEditor();

        virtual T100VOID            Init(T100ExtensionManager*);

    protected:
        T100VOID                    Load();

    private:
};

#endif // T100PLUGINEDITOR_H
