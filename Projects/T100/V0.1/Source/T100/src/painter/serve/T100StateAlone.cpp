#include "T100StateAlone.h"

#include "T100PainterCallback.h"
#include "T100PainterView.h"

namespace T100Painter{

T100StateAlone::T100StateAlone()
    :T100PainterState()
{
    //ctor
}

T100StateAlone::~T100StateAlone()
{
    //dtor
}

T100BOOL T100StateAlone::Create()
{
    return T100PainterCallback::getView()->create_alone();
}

T100VOID T100StateAlone::SetMenu()
{

}

T100VOID T100StateAlone::ResetMenu()
{

}

T100PainterElementsPanel* T100StateAlone::GetElementsPanel()
{

}

T100PainterPropertiesPanel* T100StateAlone::GetPropertiesPanel()
{

}

}
