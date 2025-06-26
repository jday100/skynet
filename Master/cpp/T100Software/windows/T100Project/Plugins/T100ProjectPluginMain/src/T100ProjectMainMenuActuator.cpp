#include "T100ProjectMainMenuActuator.h"

#include "skeletal/T100ProjectInvoking.h"

T100ProjectMainMenuActuator::T100ProjectMainMenuActuator(T100EventHandler* handler) :
    T100EventHandler(handler)
{
    //ctor
}

T100ProjectMainMenuActuator::~T100ProjectMainMenuActuator()
{
    //dtor
}

T100VOID T100ProjectMainMenuActuator::OnQuit(T100WindowEvent& event)
{
    T100ProjectInvoking::Quit();
}
