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

T100BOOL T100StateTransverter::Change(T100State* state)
{
    return T100TRUE;
}

}
