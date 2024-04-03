#ifndef T100WPAINTERMENUOPENTHREADTASK_H
#define T100WPAINTERMENUOPENTHREADTASK_H

#include "T100WxThreadTask.h"


class T100WPainterMenuOpenThreadTask : public T100WxThreadTask
{
    public:
        T100WPainterMenuOpenThreadTask();
        virtual ~T100WPainterMenuOpenThreadTask();

        T100VOID                        setFileName(T100STRING);
        T100STRING                      getFileName();

    protected:
        T100VOID                        run();

    private:
        T100STRING                      m_filename;
};

#endif // T100WPAINTERMENUOPENTHREADTASK_H
