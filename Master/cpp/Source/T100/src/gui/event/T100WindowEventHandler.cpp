#include "gui/event/T100WindowEventHandler.h"

#include "gui/event/T100ApplicationEventHandler.h"

T100WindowEventHandler::T100WindowEventHandler() :
    T100EventHandler()
{
    //ctor
}

T100WindowEventHandler::~T100WindowEventHandler()
{
    //dtor
}

T100ApplicationEventHandler* T100WindowEventHandler::GetApplicationPtr()
{
    //return dynamic_cast<T100ApplicationEventHandler*>(m_rootPtr);

    //return dynamic_cast<T100ApplicationEventHandler*>(ConvertToEventHandler(m_rootPtr));

    T100EventHandler*   handler     = ConvertToEventHandler(m_rootPtr);

    if(handler){
        return dynamic_cast<T100ApplicationEventHandler*>(handler);
    }
    return T100NULL;
}
