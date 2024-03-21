#include "T100OpenThreadTask.h"

#include "T100ThreadMain.h"

T100OpenThreadTask::T100OpenThreadTask(wxFrame* frame)
    :T100ThreadTask()
{
    //ctor
    m_frame     = dynamic_cast<T100ThreadFrame*>(frame);
    m_method    = std::bind(&T100OpenThreadTask::run, this);
}

T100OpenThreadTask::~T100OpenThreadTask()
{
    //dtor
}

void T100OpenThreadTask::run()
{
    for(int i=0;i<=100;i++){
        sleep(1000);
        send(i);
    }

}

void T100OpenThreadTask::send(int value)
{
    wxThreadEvent       event(wxEVT_THREAD, m_frame->ID_THREAD_OPEN);

    event.SetInt(value);

    wxQueueEvent(m_frame, event.Clone());
}
