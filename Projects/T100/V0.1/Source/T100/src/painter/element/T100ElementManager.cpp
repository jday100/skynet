#include "T100ElementManager.h"

#include "T100AllElements.h"
#include "T100PainterCallback.h"

namespace T100Painter{

T100ElementManager::T100ElementManager()
    :m_elements()
{
    //ctor
}

T100ElementManager::~T100ElementManager()
{
    //dtor
}

T100VOID T100ElementManager::init()
{
    T100PainterCallback::serve_element_init(T100NEW T100ElementCircle());
}

T100BOOL T100ElementManager::Append(T100ElementBase* element)
{
    if(element){
        m_elements[element->getKey()] = element;
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100ElementManager::Select(T100STRING key)
{
    m_current = m_elements[key];

    return T100TRUE;
}

T100ElementBase* T100ElementManager::GetCurrent()
{
    return m_current;
}

}
