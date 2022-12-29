#include "T100PainterServe.h"

#include "T100ElementCircle.h"

namespace T100Painter{

T100PainterServe::T100PainterServe()
    :m_elements()
{
    //ctor
    create();
}

T100PainterServe::~T100PainterServe()
{
    //dtor
    destroy();
}

T100VOID T100PainterServe::create()
{

}

T100VOID T100PainterServe::destroy()
{

}

T100BOOL T100PainterServe::NewFile(T100STRING& file, T100PAINTER_ELEMENT_VECTOR*& elements)
{
    m_elements.clear();
    elements = &m_elements;

    //test
    T100ElementCircle*  circle;

    circle = T100NEW T100ElementCircle();

    m_elements.append(circle);

    return T100TRUE;
}

T100BOOL T100PainterServe::OpenFile(T100STRING file, T100PAINTER_ELEMENT_VECTOR*& elements)
{
    elements = &m_elements;

    return T100TRUE;
}

T100BOOL T100PainterServe::SaveFile(T100STRING filename)
{

}

T100BOOL T100PainterServe::LoadFile(T100STRING filename)
{

}

T100BOOL T100PainterServe::IsModified()
{

}

T100VOID T100PainterServe::DiscardEdits()
{

}

}
