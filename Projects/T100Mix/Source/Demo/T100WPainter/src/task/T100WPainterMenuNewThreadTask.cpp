#include "T100WPainterMenuNewThreadTask.h"

#include "T100WxEventData.h"
#include "T100WPainterCallback.h"
#include "T100WPainterServe.h"
#include "T100WPainterView.h"

T100WPainterMenuNewThreadTask::T100WPainterMenuNewThreadTask()
    :T100WxThreadTask()
{
    //ctor
}

T100WPainterMenuNewThreadTask::~T100WPainterMenuNewThreadTask()
{
    //dtor
}

T100VOID T100WPainterMenuNewThreadTask::run()
{
    T100WPainterCallback::getServe()->create();

    T100DiagramInfo*        diagram         = T100WPainterCallback::getServe()->getDiagramInfo();

    if(diagram){
        T100WxEventData*        data;
        wxThreadEvent           event(wxEVT_THREAD, T100WPainterCallback::getView()->getCanvas()->ID_THREAD_LOAD);

        data    = T100NEW T100WxEventData();
        data->setData(diagram);
        event.SetEventObject(data);

        send(event);
    }
}
