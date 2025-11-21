#ifndef T100WXPLUGINACTUATOR_H
#define T100WXPLUGINACTUATOR_H

#include <wx/event.h>
#include "T100PluginActuator.h"

class T100WxPluginActuator : public T100PluginActuator, public wxEvtHandler
{
    public:
        T100WxPluginActuator();
        virtual ~T100WxPluginActuator();

        T100VOID            OnFileOpen(wxCommandEvent&);
        T100VOID            OnFileQuit(wxCommandEvent&);

    protected:

    private:
};

#endif // T100WXPLUGINACTUATOR_H
