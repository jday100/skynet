#include "gui/control/T100Control.h"

#include "gui/event/T100ApplicationEventHandler.h"

T100Control::T100Control() :
    T100Window()
{
    //ctor
}

T100Control::T100Control(T100Window* parent, T100WindowStyle* style) :
    T100Window(T100NULL, parent, style)
{
    //ctor
}

T100Control::~T100Control()
{
    //dtor
}

T100VOID T100Control::Create(T100Window* parent, T100WindowStyle* style)
{
    T100WORD    id  = parent->GetApplicationPtr()->GetIDManager().Next();
    style->Menu     = (HMENU)id;
    T100Window::Create(T100NULL, parent, style);

    GetApplicationPtr()->GetWindowMessageDispatcher().RegisterControlHandler(id, this);
}
