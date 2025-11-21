#ifndef T100PLUGINPROJECTINVOKING_H
#define T100PLUGINPROJECTINVOKING_H

#include <wx/event.h>
#include "T100Common.h"

class T100PluginProject;

class T100PluginProjectInvoking
{
    public:
        T100PluginProjectInvoking();
        virtual ~T100PluginProjectInvoking();

        static T100VOID                     Init(T100PluginProject*);

        static T100VOID                     OnCreate(wxCommandEvent& event);

    protected:

    private:
        static T100PluginProject*           m_plugin;
};

#endif // T100PLUGINPROJECTINVOKING_H
