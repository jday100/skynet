#include "T100WPainterMenuSaveAsThreadTask.h"

#include "T100DiagramInfo.h"
#include "T100WPainterCallback.h"
#include "T100WPainterStore.h"
#include "T100WPainterServe.h"

T100WPainterMenuSaveAsThreadTask::T100WPainterMenuSaveAsThreadTask()
    :T100WxThreadTask()
{
    //ctor
}

T100WPainterMenuSaveAsThreadTask::~T100WPainterMenuSaveAsThreadTask()
{
    //dtor
}

T100VOID T100WPainterMenuSaveAsThreadTask::setFileName(T100STRING filename)
{
    m_filename  = filename;
}

T100VOID T100WPainterMenuSaveAsThreadTask::run()
{
    T100STRING              file;
    T100DiagramInfo*        diagram         = T100NULL;

    file    = T100WPainterCallback::getServe()->getFileName();
    diagram = T100WPainterCallback::getServe()->getDiagramInfo();

    T100WPainterCallback::getStore()->Save(m_filename, *diagram);
}
