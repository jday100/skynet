#include "T100WPainterMenuOpenThreadTask.h"

#include "T100WxEventData.h"
#include "T100DiagramInfo.h"
#include "T100WPainterCallback.h"
#include "T100WPainterStore.h"
#include "T100WPainterServe.h"
#include "T100WPainterView.h"

T100WPainterMenuOpenThreadTask::T100WPainterMenuOpenThreadTask()
    :T100WxThreadTask()
{
    //ctor
}

T100WPainterMenuOpenThreadTask::~T100WPainterMenuOpenThreadTask()
{
    //dtor
}

T100VOID T100WPainterMenuOpenThreadTask::setFileName(T100STRING filename)
{
    m_filename  = filename;
}

T100STRING T100WPainterMenuOpenThreadTask::getFileName()
{
    return m_filename;
}

T100VOID T100WPainterMenuOpenThreadTask::run()
{
    T100BOOL                result;
    T100DiagramInfo*        diagram         = T100NULL;

    diagram = T100WPainterCallback::getServe()->getDiagramInfo();

    if(diagram){
        result  = T100WPainterCallback::getStore()->Load(m_filename, *diagram);
        if(result){
            T100WxEventData*        data;
            wxThreadEvent           event(wxEVT_THREAD, T100WPainterCallback::getView()->getCanvas()->ID_THREAD_LOAD);

            data    = T100NEW T100WxEventData();
            data->setData(diagram);
            event.SetEventObject(data);

            send(event);
        }
    }

}
