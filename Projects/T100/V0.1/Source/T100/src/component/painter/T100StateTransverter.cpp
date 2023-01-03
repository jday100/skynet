#include "T100StateTransverter.h"

namespace T100Component{

T100StateTransverter::T100StateTransverter()
{
    //ctor
}

T100StateTransverter::~T100StateTransverter()
{
    //dtor
}

T100State* T100StateTransverter::GetCurrent()
{
    return m_current;
}

T100BOOL T100StateTransverter::Change(T100State* state)
{
    m_current = state;
    return T100TRUE;
}

}
