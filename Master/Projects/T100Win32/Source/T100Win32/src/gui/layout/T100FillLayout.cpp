#include "T100FillLayout.h"

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
        if(m_childrenPtr->size() > 0){

        }else{
            return;
        }
    }else{
        return;
    }

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

T100VOID T100FillLayout::UpdateHorizontal()
{
    T100Size        size    = m_parentPtr->GetSize();
    T100UINT        length  = m_childrenPtr->size();
    T100UINT        value   = size.width / length;

    size.width      = value;
    T100Point       point;

    for(T100ObjectTree* item : *m_childrenPtr){
        T100Window* win     = T100Window::ConvertToWindow(item);
        if(win){
            win->SetSize(size);
            win->SetPosition(point);
            point.x += value;
        }
    }
}

T100VOID T100FillLayout::UpdateVertical()
{
    T100Size        size    = m_parentPtr->GetSize();
    T100UINT        length  = m_childrenPtr->size();
    T100UINT        value   = size.height / length;

    size.height     = value;
    T100Point       point;

    for(T100ObjectTree* item : *m_childrenPtr){
        T100Window* win     = T100Window::ConvertToWindow(item);
        if(win){
            win->SetSize(size);
            win->SetPosition(point);
            point.y += value;
        }
    }
}
