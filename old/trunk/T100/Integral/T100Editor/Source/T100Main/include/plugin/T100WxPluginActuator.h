#ifndef T100WXPLUGINACTUATOR_H
#define T100WXPLUGINACTUATOR_H

#include <wx/event.h>
#include "T100PluginActuator.h"

class T100WxPluginActuator : public wxEvtHandler, public T100PluginActuator
{
    public:
        T100WxPluginActuator(const wxEvtHandler&);
        virtual ~T100WxPluginActuator();

    protected:

    private:

        DECLARE_EVENT_TABLE()
};

#endif // T100WXPLUGINACTUATOR_H
