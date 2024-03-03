#include "T100WXOpenTask.h"

T100WXOpenTask::T100WXOpenTask()
    :T100WXTask()
{
    //ctor
}

T100WXOpenTask::~T100WXOpenTask()
{
    //dtor
}

T100VOID T100WXOpenTask::setFileName(T100STRING file)
{
    m_filename  = file;
}

T100VOID T100WXOpenTask::setFrame(wxFrame* frame)
{
    m_frame     = frame;
}

T100BOOL T100WXOpenTask::run()
{
    m_thread    = T100NEW T100WXOpenThread();

    m_thread->start();
}
