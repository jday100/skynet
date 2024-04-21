#include "T100PainterElementDrawer.h"

#include "T100ElementCircle.h"

T100PainterElementDrawer::T100PainterElementDrawer()
{
    //ctor
    create();
}

T100PainterElementDrawer::~T100PainterElementDrawer()
{
    //dtor
    destroy();
}

T100VOID T100PainterElementDrawer::create()
{
    m_modified  = T100FALSE;
}

T100VOID T100PainterElementDrawer::destroy()
{

}

T100BOOL T100PainterElementDrawer::Modified()
{
    return m_modified;
}

T100VOID T100PainterElementDrawer::SetDiagramInfo(T100DiagramInfo* diagram)
{
    m_diagram   = diagram;
    m_elements  = diagram->getElements();
}

T100ElementBase* T100PainterElementDrawer::Create()
{
    T100ElementBase*        result          = T100NULL;

    if(!m_current)return T100NULL;

    switch(m_current->Type){
    case 1:
        {
            result  = T100NEW T100ElementCircle();
        }
        break;
    }

    return result;
}

T100BOOL T100PainterElementDrawer::Select(T100ElementInfo* element)
{
    m_current   = element;
    return T100TRUE;
}

T100BOOL T100PainterElementDrawer::Append(T100ElementBase* element)
{
    if(m_elements && element){
        m_elements->push_back(element);
    }
}
