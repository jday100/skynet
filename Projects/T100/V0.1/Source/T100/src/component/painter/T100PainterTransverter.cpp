#include "T100PainterTransverter.h"

namespace T100Component{

T100PainterTransverter::T100PainterTransverter()
    :T100StateTransverter()
{
    //ctor
}

T100PainterTransverter::~T100PainterTransverter()
{
    //dtor
}

T100BOOL T100PainterTransverter::Change(T100State* state)
{

}

T100BOOL T100PainterTransverter::Change(T100WORD state)
{

}

T100Painter::T100PainterState* T100PainterTransverter::GetCurrent()
{
    T100Painter::T100PainterState*          current         = T100NULL;


    return current;
}

}
