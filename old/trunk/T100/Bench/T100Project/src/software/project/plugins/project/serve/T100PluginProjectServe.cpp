#include "T100PluginProjectServe.h"

T100PluginProjectServe::T100PluginProjectServe()
{
    //ctor
    init();
}

T100PluginProjectServe::~T100PluginProjectServe()
{
    //dtor
    uninit();
}

T100VOID T100PluginProjectServe::init()
{
    m_manager   = T100NEW T100ProjectManager();
}

T100VOID T100PluginProjectServe::uninit()
{
    T100SAFE_DELETE(m_manager);
}

T100ProjectManager* T100PluginProjectServe::GetManager()
{
    return m_manager;
}
