#include "T100PainterServe.h"

#include "T100DiagramInfo.h"

T100PainterServe::T100PainterServe()
{
    //ctor
}

T100PainterServe::~T100PainterServe()
{
    //dtor
}

T100BOOL T100PainterServe::opened()
{
    return m_opened;
}

T100BOOL T100PainterServe::modified()
{
    return m_element_drawer.Modified();
}

T100STRING T100PainterServe::getFileName()
{
    return m_filename;
}

T100DiagramInfo* T100PainterServe::getDiagramInfo()
{
    return m_diagram;
}

T100VOID T100PainterServe::create()
{
    m_opened    = T100TRUE;
    m_diagram   = T100NEW T100DiagramInfo();
    m_element_drawer.SetDiagramInfo(m_diagram);
}

T100VOID T100PainterServe::destroy()
{
    T100DELETE  m_diagram;
    m_diagram   = T100NULL;
    m_opened    = T100FALSE;
}

T100PainterElementDrawer* T100PainterServe::getElementDrawer()
{
    return &m_element_drawer;
}
