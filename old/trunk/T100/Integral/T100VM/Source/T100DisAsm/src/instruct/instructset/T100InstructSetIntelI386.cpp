#include "T100InstructSetIntelI386.h"

#include "T100AllInstructsI386.h"
#include "T100InstructActuator.h"

T100InstructSetIntelI386::T100InstructSetIntelI386(T100InstructActuator& actuator) :
    T100InstructSet(),
    m_actuator(actuator)
{
    //ctor
}

T100InstructSetIntelI386::~T100InstructSetIntelI386()
{
    //dtor
}

T100BOOL T100InstructSetIntelI386::Load()
{
    T100InstructNop*        nop     = T100NEW T100InstructNop();

    m_actuator.m_instructs[nop->m_byte]         = nop;

    T100InstructHlt*        hlt     = T100NEW T100InstructHlt();

    m_actuator.m_instructs[hlt->m_byte]         = hlt;

    return T100FALSE;
}
