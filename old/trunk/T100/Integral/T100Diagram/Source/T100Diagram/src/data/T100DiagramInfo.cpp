#include "T100DiagramInfo.h"

T100DiagramInfo::T100DiagramInfo() :
    m_elements()
{
    //ctor
    init();
}

T100DiagramInfo::~T100DiagramInfo()
{
    //dtor
    uninit();
}

T100VOID T100DiagramInfo::init()
{
    m_head.COMMON.SIGN      = T100FILE_DIAGRAM;
    m_head.TYPE             = T100DIAGRAM_COMMON;
    m_head.VERSION          = 1;
}

T100VOID T100DiagramInfo::uninit()
{
    m_elements.clear();
}

T100VOID T100DiagramInfo::SetPath(T100WSTRING& path)
{
    m_path      = path;
}

T100WSTRING& T100DiagramInfo::GetPath()
{
    return m_path;
}

T100DIAGRAM_HEAD* T100DiagramInfo::GetHead()
{
    return &m_head;
}

T100DIAGRAM_CANVAS* T100DiagramInfo::GetCanvas()
{
    return &m_canvas;
}

T100DIAGRAM_ELEMENT_VECTOR* T100DiagramInfo::GetElements()
{
    return &m_elements;
}

T100BOOL T100DiagramInfo::Remove(T100ElementBase* element)
{
    T100DIAGRAM_ELEMENT_VECTOR::iterator    it;

    for(it = m_elements.begin(); it != m_elements.end();++it){
        if(*it == element){
            m_elements.erase(it);
            return T100TRUE;
        }
    }
    return T100FALSE;
}
