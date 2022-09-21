#ifndef T100EXECUTOR32_H
#define T100EXECUTOR32_H

#include <mutex>
#include <condition_variable>
#include "T100VPCCommon.h"
#include "T100Thread.h"
class T100QU32;


class T100Executor32 : public T100Thread
{
    friend class T100OrderCmt;
    friend class T100OrderCall;
    friend class T100OrderRet;
    friend class T100OrderDebug;
    friend class T100QU32;
    public:
        T100Executor32(T100QU32*);
        virtual ~T100Executor32();

        T100BOOL                        start();
        T100BOOL                        stop();

    protected:
        T100VOID                        debug();

        T100BOOL                        step();
        T100BOOL                        next();

        T100BOOL                        resume();
        T100BOOL                        pause();

        T100BOOL                        nextComment();
        T100BOOL                        nextCall();
        T100BOOL                        nextReturn();

        T100BOOL                        pauseComment();
        T100BOOL                        pauseCall();
        T100BOOL                        pauseReturn();

    protected:
        T100VOID                        run();

        T100VOID                        execute();

    private:
        T100QU32*                       m_host          = T100NULL;

        std::mutex                      m_mutex;
        std::condition_variable         m_condition;

        //volatile T100EXECUTOR_STATE     m_state;
        //volatile T100EXECUTOR_MODE      m_mode;
};

#endif // T100EXECUTOR32_H
