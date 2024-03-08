#include "T100WxProjectCreateTask.h"

#include "T100ProjectCallback.h"
#include "T100ProjectServe.h"

namespace T100PROJECT{

T100WxProjectCreateTask::T100WxProjectCreateTask()
    :T100WxWidgets::T100WxThreadTask()
{
    //ctor
}

T100WxProjectCreateTask::~T100WxProjectCreateTask()
{
    //dtor
}

T100VOID T100WxProjectCreateTask::setProjectInfo(T100ProjectInfo* info)
{
    m_info  = info;
}

T100ProjectInfo* T100WxProjectCreateTask::getProjectInfo()
{
    return m_info;
}

T100VOID T100WxProjectCreateTask::run()
{
    T100BOOL                result;
    T100ProjectServe*       serve           = T100NULL;

    serve   = T100ProjectCallback::getServe();

    if(serve){
        result  = serve->getProjectDrawer()->Create(m_info);
    }
}

}
