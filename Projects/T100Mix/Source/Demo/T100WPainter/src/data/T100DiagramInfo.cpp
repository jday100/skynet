#include "T100DiagramInfo.h"

T100DiagramInfo::T100DiagramInfo()
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
    m_head.COMMON.SIGN  = T100FILE_DIAGRAM;
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

T100WPAINTER_ELEMENT_VECTOR* T100DiagramInfo::getElements()
{
    return &m_elements;
}
