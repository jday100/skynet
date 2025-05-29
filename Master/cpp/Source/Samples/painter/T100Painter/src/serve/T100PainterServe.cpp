#include "T100PainterServe.h"

T100PainterServe::T100PainterServe()
{
    //ctor
}

T100PainterServe::~T100PainterServe()
{
    //dtor
}

T100VOID T100PainterServe::Select(T100WORD index)
{
    m_current   = index;
}

T100WORD& T100PainterServe::GetCurrent()
{
    return m_current;
}
