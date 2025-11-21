#include "T100WxPluginActuator.h"

BEGIN_EVENT_TABLE(T100WxPluginActuator, wxEvtHandler)

END_EVENT_TABLE()

T100WxPluginActuator::T100WxPluginActuator(const wxEvtHandler& handler) :
    wxEvtHandler(),
    T100PluginActuator()
{
    //ctor
}

T100WxPluginActuator::~T100WxPluginActuator()
{
    //dtor
}
