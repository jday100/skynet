#include "T100WPainterElementDrawer.h"

#include "T100ElementCircle.h"

T100WPainterElementDrawer::T100WPainterElementDrawer()
{
    //ctor
}

T100WPainterElementDrawer::~T100WPainterElementDrawer()
{
    //dtor
}

T100ElementBase* T100WPainterElementDrawer::Create()
{
    T100ElementBase*        result          = T100NULL;

    if(!m_current)return T100NULL;

    switch(m_current->type){
    case 1:
        {
            result  = T100NEW T100ElementCircle();
        }
        break;
    }

    return result;
}

T100BOOL T100WPainterElementDrawer::Select(T100ElementInfo* element)
{
    m_current   = element;
    return T100TRUE;
}
