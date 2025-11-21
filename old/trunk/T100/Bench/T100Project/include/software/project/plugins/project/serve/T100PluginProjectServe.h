#ifndef T100PLUGINPROJECTSERVE_H
#define T100PLUGINPROJECTSERVE_H

#include "T100ProjectManager.h"

class T100PluginProjectServe
{
    public:
        T100PluginProjectServe();
        virtual ~T100PluginProjectServe();

        T100ProjectManager*         GetManager();

    protected:
        T100ProjectManager*         m_manager       = T100NULL;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100PLUGINPROJECTSERVE_H
