#include "T100ThreadTask.h"

T100ThreadTask::T100ThreadTask()
{
    //ctor
}

T100ThreadTask::~T100ThreadTask()
{
    //dtor
}

T100VOID T100ThreadTask::start()
{
    m_method    = std::bind(&T100ThreadTask::run, this);
    m_thread    = T100NEW std::thread(m_method);
}

T100VOID T100ThreadTask::stop()
{

}
