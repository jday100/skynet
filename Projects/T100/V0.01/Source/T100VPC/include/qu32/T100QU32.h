#ifndef T100QU32_H
#define T100QU32_H

#include "T100QU32Setup.h"
#include "T100CU32.h"
#include "T100AU32.h"
#include "T100Memory32.h"
#include "T100Port32.h"
#include "T100Interrupt32.h"
#include "T100Executor32.h"


class T100QU32
{
    public:
        T100QU32();
        virtual ~T100QU32();

        T100CU32*               getCU32();
        T100AU32*               getAU32();
        T100Memory32*           getMemory32();
        T100Port32*             getPort32();
        T100Interrupt32*        getInterrupt32();
        T100Executor32*         getExecutor32();


        T100BOOL                start();
        T100BOOL                stop();

        T100BOOL                done();

        T100BOOL                load(T100STRING, T100WORD, T100WORD);


    protected:
        T100VOID                create();
        T100VOID                destroy();

        T100BOOL                load();

    private:

        T100CU32*               m_cu            = T100NULL;
        T100AU32*               m_au            = T100NULL;
        T100Memory32*           m_memory        = T100NULL;
        T100Port32*             m_port          = T100NULL;
        T100Interrupt32*        m_interrupt     = T100NULL;
        T100Executor32*         m_executor      = T100NULL;


};

#endif // T100QU32_H
