#include "T100WPainterServe.h"

#include "T100DiagramInfo.h"

T100WPainterServe::T100WPainterServe()
{
    //ctor
}

T100WPainterServe::~T100WPainterServe()
{
    //dtor
}

T100BOOL T100WPainterServe::opened()
{
    return m_opened;
}

T100STRING T100WPainterServe::getFileName()
{
    return m_filename;
}

T100DiagramInfo* T100WPainterServe::getDiagramInfo()
{
    return m_diagram;
}

T100BOOL T100WPainterServe::create()
{
    if(m_diagram){
        return T100FALSE;
    }

    m_opened    = T100TRUE;
    m_diagram   = T100NEW T100DiagramInfo();
    return T100TRUE;
}

T100BOOL T100WPainterServe::destroy()
{
    if(m_diagram){
        T100DELETE m_diagram;
        m_diagram   = T100NULL;
        m_opened    = T100FALSE;
        return T100TRUE;
    }
    return T100FALSE;
}
