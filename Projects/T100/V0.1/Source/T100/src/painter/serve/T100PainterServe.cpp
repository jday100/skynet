#include "T100PainterServe.h"

#include "T100ElementCircle.h"
#include "T100DiagramInfoV1.h"

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
    m_opened    = T100FALSE;
}

T100VOID T100PainterServe::destroy()
{

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

//////
T100BOOL T100PainterServe::opened()
{
    return m_opened;
}

T100BOOL T100PainterServe::close()
{
    return T100TRUE;
}

T100BOOL T100PainterServe::NewFile(T100STRING& file, T100DiagramInfo*& diagram)
{
    file        = L"unnamed.dgm";
    diagram     = T100NEW T100DiagramInfoV1();
    m_current   = diagram;
    m_opened    = T100TRUE;

    return T100TRUE;
}

T100BOOL T100PainterServe::OpenFile(T100DiagramInfo* diagram)
{
    m_current   = diagram;
    m_opened    = T100TRUE;

    return T100TRUE;
}

T100DiagramInfo* T100PainterServe::getCurrent()
{
    return m_current;
}

}
