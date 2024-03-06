#include "T100ProjectStateEmbed.h"

#include "T100ProjectCallback.h"
#include "T100ProjectView.h"


namespace T100PROJECT{

T100ProjectStateEmbed::T100ProjectStateEmbed()
    :T100ProjectState()
{
    //ctor
}

T100ProjectStateEmbed::~T100ProjectStateEmbed()
{
    //dtor
}

T100BOOL T100ProjectStateEmbed::Create()
{
    return T100ProjectCallback::getView()->create_embed();
}

T100VOID T100ProjectStateEmbed::SetMenu()
{

}

T100VOID T100ProjectStateEmbed::ResetMenu()
{

}

T100ProjectProjectsPanel* T100ProjectStateEmbed::GetProjectsPanel()
{

}

}
