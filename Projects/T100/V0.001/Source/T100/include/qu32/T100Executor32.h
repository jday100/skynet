#ifndef T100EXECUTOR32_H
#define T100EXECUTOR32_H

#include <atomic>
#include <mutex>
#include <condition_variable>
#include <thread>
#include "IExecutor.h"
class T100QU32;


class T100Executor32 : public IExecutor
{
    friend class T100QU32;
    friend class T100Memory32;
    friend class T100Manager32;
    friend class T100VPCServe;
    friend class T100VPCDebugFrame;
    friend class T100OrderDebug;
    public:
        T100Executor32(T100QU32*);
        virtual ~T100Executor32();

        virtual T100VOID            start();
        virtual T100VOID            stop();

        virtual T100VOID            pause();
        virtual T100VOID            resume();
        virtual T100VOID            step();
        virtual T100VOID            next();

        virtual T100VOID            wait();

    protected:
        T100VOID                    run();
        T100VOID                    execute();
        T100VOID                    execute_none();

        T100VOID                    done();
        T100VOID                    debug();

        //
        T100VOID                    run_step();
        T100VOID                    run_next();
        T100VOID                    run_run();

    private:
        T100QU32*                   m_host          = T100NULL;

        std::thread*                m_thread        = T100NULL;
        volatile std::atomic_bool   m_running;

        std::mutex                  m_mutex;
        std::condition_variable     m_condition;

        volatile EXECUTOR_STATE     m_state         = EXECUTOR_STATE_STOP;
        volatile EXECUTOR_MODE      m_mode          = EXECUTOR_MODE_RUN;

};

#endif // T100EXECUTOR32_H
