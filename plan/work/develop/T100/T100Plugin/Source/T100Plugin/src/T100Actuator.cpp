#include "T100Actuator.h"

T100Actuator::T100Actuator()
{
    //ctor

    m_editor.Create();
}

T100Actuator::~T100Actuator()
{
    //dtor
}

void T100Actuator::Message()
{
    m_editor.Message();
}
