#include "T100ProjectStateAlone.h"

#include "T100ProjectCallback.h"
#include "T100ProjectView.h"

namespace T100PROJECT{

T100ProjectStateAlone::T100ProjectStateAlone()
    :T100ProjectState()
{
    //ctor
}

T100ProjectStateAlone::~T100ProjectStateAlone()
{
    //dtor
}

T100BOOL T100ProjectStateAlone::Create()
{
    return T100ProjectCallback::getView()->create_alone();
}

T100VOID T100ProjectStateAlone::SetMenu()
{

}

T100VOID T100ProjectStateAlone::ResetMenu()
{

}

T100ProjectProjectsPanel* T100ProjectStateAlone::GetProjectsPanel()
{

}

}
