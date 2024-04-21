#include "T100PainterMenuNewThreadTask.h"

#include "T100WxEventData.h"
#include "T100PainterServe.h"
#include "T100PainterView.h"
#include "T100PainterCallback.h"

T100PainterMenuNewThreadTask::T100PainterMenuNewThreadTask()
    :T100WxThreadTask()
{
    //ctor
}

T100PainterMenuNewThreadTask::~T100PainterMenuNewThreadTask()
{
    //dtor
}

T100VOID T100PainterMenuNewThreadTask::run()
{
    T100PainterCallback::task_new();
}
