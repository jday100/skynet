#include "T100WxThreadTask.h"

T100WxThreadTask::T100WxThreadTask()
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

T100VOID T100WxThreadTask::start()
{
    m_method    = std::bind(&T100WxThreadTask::run, this);
    m_thread    = T100NEW std::thread(m_method);
}

T100VOID T100WxThreadTask::stop()
{

}

T100VOID T100WxThreadTask::sendEvent(wxThreadEvent& event, T100WxEventData* data)
{

}
