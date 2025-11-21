#include "T100VM.h"

T100VM::T100VM()
{
    //ctor
    m_running       = T100FALSE;
}

T100VM::~T100VM()
{
    //dtor
}

T100BOOL T100VM::IsRunning()
{
    return m_running;
}
