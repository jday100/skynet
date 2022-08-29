#ifndef T100QU32_H
#define T100QU32_H

#include "T100QU32Setup.h"
#include "IComputer.h"
#include "T100CU32.h"
#include "T100AU32.h"
#include "T100Memory32.h"
#include "T100Manager32.h"
#include "T100Interrupt32.h"
#include "T100Executor32.h"
#include "T100QU32Callback.h"


class T100QU32 : public IComputer
{
    friend class T100Memory32;
    friend class T100Executor32;
    friend class T100OrderHalt;
    friend class T100OrderIn;
    friend class T100OrderOut;
    friend class T100OrderCall;
    friend class T100OrderRet;
    public:
        T100QU32();
        virtual ~T100QU32();

        T100CU32*                   getCU32();
        T100AU32*                   getAU32();
        T100Memory32*               getMemory32();
        T100Manager32*              getManager32();
        T100Interrupt32*            getInterrupt32();
        T100Executor32*             getExecutor32();
        //
        T100QU32Callback*           getCallback();
        //
        T100BOOL                    start();
        T100BOOL                    stop();
        T100BOOL                    wait();
        //
        T100BOOL                    pause();
        T100BOOL                    resume();
        //
        T100BOOL                    step();
        T100BOOL                    next();
        //
        T100BOOL                    isRunning();

    protected:
        T100VOID                    create();
        T100VOID                    destroy();

        T100BOOL                    load(T100String, T100WORD);
        T100BOOL                    done();
        T100BOOL                    debug();

        T100BOOL                    load();

        //
        ICU*                        getCU();
        IAU*                        getAU();
        IMemory*                    getMemory();
        IManager*                   getManager();
        IInterrupt*                 getInterrupt();
        IExecutor*                  getExecutor();

    private:
        volatile std::atomic_bool   m_running;
        T100BOOL                    m_created       = T100FALSE;
        //
        T100CU32*                   m_cu            = T100NULL;
        T100AU32*                   m_au            = T100NULL;
        T100Memory32*               m_memory        = T100NULL;
        T100Manager32*              m_manager       = T100NULL;
        T100Interrupt32*            m_interrupt     = T100NULL;
        T100Executor32*             m_executor      = T100NULL;
};

#endif // T100QU32_H
