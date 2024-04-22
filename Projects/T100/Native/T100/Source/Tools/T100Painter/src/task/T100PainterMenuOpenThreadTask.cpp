#include "T100PainterMenuOpenThreadTask.h"

#include "T100WxEventData.h"
#include "T100PainterStore.h"
#include "T100PainterServe.h"
#include "T100PainterView.h"
#include "T100PainterCallback.h"

T100PainterMenuOpenThreadTask::T100PainterMenuOpenThreadTask()
    :T100WxThreadTask()
{
    //ctor
}

T100PainterMenuOpenThreadTask::~T100PainterMenuOpenThreadTask()
{
    //dtor
}

T100VOID T100PainterMenuOpenThreadTask::setFileName(T100STRING filename)
{
    m_filename  = filename;
}

T100STRING T100PainterMenuOpenThreadTask::getFileName()
{
    return m_filename;
}

T100VOID T100PainterMenuOpenThreadTask::run()
{
    T100BOOL                result;
    T100DiagramInfo*        diagram         = T100NULL;

    diagram = T100PainterCallback::getServe()->getDiagramInfo();

    if(diagram){
        result  = T100PainterCallback::getStore()->Load(m_filename, *diagram);
        if(result){
            T100WxEventData*        data;
            wxThreadEvent           event(wxEVT_THREAD, T100PainterCallback::getView()->getCanvas()->ID_THREAD_LOAD);

            data    = T100NEW T100WxEventData();
            data->setData(diagram);
            event.SetEventObject(data);

            send(event);
        }
    }
}
