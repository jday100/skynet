#ifndef T100PLUGINPROJECT_H
#define T100PLUGINPROJECT_H

#include "T100Plugin.h"
#include "T100PluginProjectView.h"
#include "T100PluginProjectServe.h"
#include "T100PluginProjectStore.h"

class T100PluginProject : public T100Plugin
{
    public:
        T100PluginProject();
        virtual ~T100PluginProject();

        virtual T100VOID            Init(T100ExtensionManager*);

        T100PluginProjectView*      GetView();
        T100PluginProjectServe*     GetServe();
        T100PluginProjectStore*     GetStore();

    protected:
        T100PluginProjectView*      m_view      = T100NULL;
        T100PluginProjectServe*     m_serve     = T100NULL;
        T100PluginProjectStore*     m_store     = T100NULL;

    private:
        T100VOID                    Load();

        T100VOID                    LoadWorkSpace();
};

#endif // T100PLUGINPROJECT_H
