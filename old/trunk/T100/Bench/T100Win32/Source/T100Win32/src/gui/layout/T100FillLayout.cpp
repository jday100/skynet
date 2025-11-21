#include "gui/T100FillLayout.h"

#include "gui/T100Window.h"

namespace T100WINDOWS{

T100FillLayout::T100FillLayout(T100ORIENTATION_TYPE type) :
    T100Layout(),
    m_orientationType(type)
{
    //ctor
}

T100FillLayout::~T100FillLayout()
{
    //dtor
}

T100VOID T100FillLayout::SetOrientationType(T100ORIENTATION_TYPE type)
{
    m_orientationType   = type;
}

T100ORIENTATION_TYPE T100FillLayout::GetOrientationType()
{
    return m_orientationType;
}

T100VOID T100FillLayout::Update()
{
    if(m_parent && m_children){
        if(m_children->size() > 0){

        }else{
            return;
        }
    }else{
        return;
    }

    switch(m_orientationType){
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
    T100Size        size    = m_parent->GetClientSize();
    T100UINT        length  = m_children->size();
    T100UINT        value   = size.Width / length;

    size.Width      = value;
    T100Point       point;

    for(T100Tree* item : *m_children){
        T100Window* win     = T100Window::ConvertToWindow(item);
        if(win){
            win->SetSize(size);
            win->SetPosition(point);
            point.X += value;
        }
    }
}

T100VOID T100FillLayout::UpdateVertical()
{
    T100Size        size    = m_parent->GetClientSize();
    T100UINT        length  = m_children->size();
    T100UINT        value   = size.Height / length;

    size.Height     = value;
    T100Point       point;

    for(T100Tree* item : *m_children){
        T100Window* win     = T100Window::ConvertToWindow(item);
        if(win){
            win->SetSize(size);
            win->SetPosition(point);
            point.Y += value;
        }
    }
}

}
