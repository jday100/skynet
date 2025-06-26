#ifndef T100PROJECTSKELETAL_H
#define T100PROJECTSKELETAL_H

#include "view/T100ProjectView.h"
#include "serve/T100ProjectServe.h"
#include "store/T100ProjectStore.h"

#include "plugin/T100PluginServer.h"
#include "extension/T100ExtendedManager.h"

using namespace T100UNIVERSAL;

class T100ProjectSkeletal
{
    public:
        T100ProjectSkeletal();
        virtual ~T100ProjectSkeletal();

        T100VOID                    Launch();

        T100VOID                    Quit();

        T100VOID                    SetView(T100ProjectView*);
        T100ProjectView*            GetView();

        T100VOID                    SetServe(T100ProjectServe*);
        T100ProjectServe*           GetServe();

        T100VOID                    SetStore(T100ProjectStore*);
        T100ProjectStore*           GetStore();

        T100PluginServer&           GetPluginServer();
        T100ExtendedManager&        GetExtendedManager();

    protected:
        T100ProjectView*            m_view          = T100NULL;
        T100ProjectServe*           m_serve         = T100NULL;
        T100ProjectStore*           m_store         = T100NULL;

        T100PluginServer            m_pluginServer;
        T100ExtendedManager         m_extendedManager;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100PROJECTSKELETAL_H
