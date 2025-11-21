#ifndef T100PLUGINEDITORACTUATOR_H
#define T100PLUGINEDITORACTUATOR_H

#include <wx/event.h>
#include "T100Editor.h"

class T100PluginEditorActuator : public wxEvtHandler
{
    public:
        T100PluginEditorActuator();
        virtual ~T100PluginEditorActuator();

        T100VOID            OnFileNew(wxCommandEvent&);
        T100VOID            OnFileQuit(wxCommandEvent&);

        T100Editor          m_editor;

    protected:

    private:
};

#endif // T100PLUGINEDITORACTUATOR_H
