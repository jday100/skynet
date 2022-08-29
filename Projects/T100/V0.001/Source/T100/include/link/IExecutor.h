#ifndef IEXECUTOR_H
#define IEXECUTOR_H

#include "T100Common.h"
class IComputer;
class T100QU32;

typedef enum{
    EXECUTOR_STATE_NONE         = 1,
    EXECUTOR_STATE_STOP,
    EXECUTOR_STATE_RUN,
    EXECUTOR_STATE_PAUSE,
    EXECUTOR_STATE_MAX
}EXECUTOR_STATE;

typedef enum{
    EXECUTOR_MODE_NONE          = 1,
    EXECUTOR_MODE_STEP,
    EXECUTOR_MODE_NEXT,
    EXECUTOR_MODE_RUN,
    EXECUTOR_MODE_MAX
}EXECUTOR_MODE;


class IExecutor
{
    public:
        IExecutor(IComputer*);
        virtual ~IExecutor();

        virtual T100VOID            start()=0;
        virtual T100VOID            stop()=0;

        virtual T100VOID            pause()=0;
        virtual T100VOID            resume()=0;

    protected:
        IComputer*                  m_host          = T100NULL;

    private:
};

#endif // IEXECUTOR_H
