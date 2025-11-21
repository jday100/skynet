#ifndef T100PLUGINPROJECTVIEW_H
#define T100PLUGINPROJECTVIEW_H

#include "T100Common.h"
#include "T100ProjectInfo.h"
#include "T100PluginProjectProjectPanel.h"

class T100ProjectFrame;

class T100PluginProjectView
{
    public:
        T100PluginProjectView();
        virtual ~T100PluginProjectView();

        virtual T100VOID            Create(T100ProjectFrame*);
        virtual T100VOID            Destroy();

        T100VOID                    Append(T100ProjectInfo&);

        T100VOID                    Update(T100PROJECT_VESSEL&);

    protected:
        T100ProjectFrame*           m_frame     = T100NULL;

        T100PluginProjectProjectPanel*          m_panel     = T100NULL;


    private:
};

#endif // T100PLUGINPROJECTVIEW_H
