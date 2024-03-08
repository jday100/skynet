#ifndef T100WXPROJECTCREATETASK_H
#define T100WXPROJECTCREATETASK_H

#include "T100WxThreadTask.h"
#include "T100ProjectInfo.h"

namespace T100PROJECT{

class T100WxProjectCreateTask : public T100WxWidgets::T100WxThreadTask
{
    public:
        T100WxProjectCreateTask();
        virtual ~T100WxProjectCreateTask();

        T100VOID                run();

        T100VOID                setProjectInfo(T100ProjectInfo*);
        T100ProjectInfo*        getProjectInfo();

    protected:

    private:
        T100ProjectInfo*        m_info          = T100NULL;
};

}

#endif // T100WXPROJECTCREATETASK_H
