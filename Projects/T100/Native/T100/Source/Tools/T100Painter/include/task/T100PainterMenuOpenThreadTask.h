#ifndef T100PAINTERMENUOPENTHREADTASK_H
#define T100PAINTERMENUOPENTHREADTASK_H

#include "T100WxThreadTask.h"

class T100PainterMenuOpenThreadTask : public T100WxThreadTask
{
    public:
        T100PainterMenuOpenThreadTask();
        virtual ~T100PainterMenuOpenThreadTask();

        T100VOID                        setFileName(T100STRING);
        T100STRING                      getFileName();

    protected:
        T100VOID                        run();

    private:
        T100STRING                      m_filename;
};

#endif // T100PAINTERMENUOPENTHREADTASK_H
