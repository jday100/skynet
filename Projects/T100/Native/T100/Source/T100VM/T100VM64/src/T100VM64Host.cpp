#include "T100VM64Host.h"

T100VM64Host::T100VM64Host()
{
    //ctor
    create();
}

T100VM64Host::~T100VM64Host()
{
    //dtor
    destroy();
}

T100VOID T100VM64Host::create()
{
    m_serve     = T100NEW T100VM64Serve();
    m_view      = T100NEW T100VM64View();
}

T100VOID T100VM64Host::destroy()
{
    T100DELETE m_view;
    T100DELETE m_serve;
}

T100BOOL T100VM64Host::start()
{
    m_serve->start();
}

T100BOOL T100VM64Host::stop()
{
    m_serve->stop();
}
