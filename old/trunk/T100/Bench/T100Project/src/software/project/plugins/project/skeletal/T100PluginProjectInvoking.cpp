#include "T100PluginProjectInvoking.h"

#include "T100ProjectLogic.h"

T100PluginProject*          T100PluginProjectInvoking::m_plugin             = T100NULL;

T100PluginProjectInvoking::T100PluginProjectInvoking()
{
    //ctor
}

T100PluginProjectInvoking::~T100PluginProjectInvoking()
{
    //dtor
}

T100VOID T100PluginProjectInvoking::Init(T100PluginProject* plugin)
{
    m_plugin        = plugin;
}

T100VOID T100PluginProjectInvoking::OnCreate(wxCommandEvent& event)
{
    T100ProjectLogic*       logic       = T100NEW T100ProjectLogic(m_plugin);

    logic->Create();
}
