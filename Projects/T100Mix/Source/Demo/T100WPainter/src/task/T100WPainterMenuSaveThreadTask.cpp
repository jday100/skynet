#include "T100WPainterMenuSaveThreadTask.h"

#include "T100DiagramInfo.h"
#include "T100WPainterCallback.h"
#include "T100WPainterStore.h"
#include "T100WPainterServe.h"

T100WPainterMenuSaveThreadTask::T100WPainterMenuSaveThreadTask()
    :T100WxThreadTask()
{
    //ctor
}

T100WPainterMenuSaveThreadTask::~T100WPainterMenuSaveThreadTask()
{
    //dtor
}

T100VOID T100WPainterMenuSaveThreadTask::run()
{
    T100STRING              file;
    T100DiagramInfo*        diagram         = T100NULL;

    file    = T100WPainterCallback::getServe()->getFileName();
    diagram = T100WPainterCallback::getServe()->getDiagramInfo();

    T100WPainterCallback::getStore()->Save(file, *diagram);
}
