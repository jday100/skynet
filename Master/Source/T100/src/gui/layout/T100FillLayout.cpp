#include "gui/layout/T100FillLayout.h"

T100FillLayout::T100FillLayout(T100ORIENTATION_TYPE type) :
    T100Layout(),
    m_type(type)
{
    //ctor
}

T100FillLayout::~T100FillLayout()
{
    //dtor
}

T100VOID T100FillLayout::SetOrientationType(T100ORIENTATION_TYPE type)
{
    m_type  = type;
}

T100ORIENTATION_TYPE T100FillLayout::GetOrientationType()
{
    return m_type;
}

T100VOID T100FillLayout::Update()
{
    if(m_parentPtr && m_childrenPtr){
        switch(m_type){
        case T100HORIZONTAL:
            {
                UpdateHorizontal();
            }
            break;
        case T100VERTICAL:
            {
                UpdateVertical();
            }
            break;
        }
    }
}

T100VOID T100FillLayout::UpdateHorizontal()
{
    T100Size        size    = m_parentPtr->GetClientSize();
    T100UINT        length  = m_childrenPtr->size();
    T100UINT        value   = size.m_x / length;

    size.m_x        = value;
    T100Point       point;

    for(T100Window* item : *m_childrenPtr){
        item->SetSize(size);
        item->SetPosition(point);
        point.m_x += value;
    }
}

T100VOID T100FillLayout::UpdateVertical()
{
    T100Size        size    = m_parentPtr->GetClientSize();
    T100UINT        length  = m_childrenPtr->size();
    T100UINT        value   = size.m_y / length;

    size.m_y        = value;
    T100Point       point;

    for(T100Window* item : *m_childrenPtr){
        item->SetSize(size);
        item->SetPosition(point);
        point.m_y += value;
    }
}
