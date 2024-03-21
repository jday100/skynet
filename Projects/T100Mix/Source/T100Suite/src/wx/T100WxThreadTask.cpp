#include "T100WxThreadTask.h"

T100WxThreadTask::T100WxThreadTask()
    :T100ThreadTask()
{
    //ctor
}

T100WxThreadTask::~T100WxThreadTask()
{
    //dtor
}

T100VOID T100WxThreadTask::setWindow(wxWindow* win)
{
    m_parent    = win;
}

wxWindow* T100WxThreadTask::getWindow()
{
    return m_parent;
}

T100VOID T100WxThreadTask::sendEvent(wxThreadEvent& event, T100WxEventData* data)
{

}
