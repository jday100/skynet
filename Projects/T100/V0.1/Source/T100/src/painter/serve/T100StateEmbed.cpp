#include "T100StateEmbed.h"

#include "T100PainterCallback.h"
#include "T100PainterView.h"

namespace T100Painter{

T100StateEmbed::T100StateEmbed()
    :T100PainterState()
{
    //ctor
}

T100StateEmbed::~T100StateEmbed()
{
    //dtor
}

T100BOOL T100StateEmbed::Create()
{
    return T100PainterCallback::getView()->create_embed();
}

T100VOID T100StateEmbed::SetMenu()
{

}

T100VOID T100StateEmbed::ResetMenu()
{

}

T100PainterElementsPanel* T100StateEmbed::GetElementsPanel()
{

}

T100PainterPropertiesPanel* T100StateEmbed::GetPropertiesPanel()
{

}

}
