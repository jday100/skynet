#include "T100DiagramInfo.h"

namespace T100Painter{

T100DiagramInfo::T100DiagramInfo()
    :m_elements()
{
    //ctor
    create();
}

T100DiagramInfo::~T100DiagramInfo()
{
    //dtor
    destroy();
}

T100VOID T100DiagramInfo::create()
{
    m_head.COMMON.SIGN  = T100Library::T100FILE_DIAGRAM;
    m_head.TYPE         = T100DIAGRAM_COMMON;
    m_head.VERSION      = 1;
}

T100VOID T100DiagramInfo::destroy()
{

}

T100DIAGRAM_HEAD* T100DiagramInfo::getHead()
{
    return &m_head;
}

T100PAINTER_ELEMENT_VECTOR* T100DiagramInfo::getElements()
{
    return &m_elements;
}

}
