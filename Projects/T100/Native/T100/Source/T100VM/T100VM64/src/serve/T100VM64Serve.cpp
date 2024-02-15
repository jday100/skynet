#include "T100VM64Serve.h"

T100VM64Serve::T100VM64Serve()
{
    //ctor
    create();
}

T100VM64Serve::~T100VM64Serve()
{
    //dtor
    destroy();
}

T100VOID T100VM64Serve::create()
{
    m_qu64 = T100NEW T100QU64();
}

T100VOID T100VM64Serve::destroy()
{
    T100DELETE m_qu64;
}

T100BOOL T100VM64Serve::start()
{
    INT64       length      = 1024 * 1024 * 1024;

    m_qu64->start(length);
}

T100BOOL T100VM64Serve::stop()
{
    m_qu64->stop();
}
