#ifndef T100EXECUTOR32_H
#define T100EXECUTOR32_H

#include "T100Common.h"
#include "T100Thread.h"
class T100QU32;


class T100Executor32 : public T100Thread
{
    public:
        T100Executor32(T100QU32*);
        virtual ~T100Executor32();

        T100BOOL            start();
        T100BOOL            stop();

        T100VOID            debug();

    protected:
        T100VOID            run();

        T100VOID            execute();

    private:
        T100QU32*           m_host          = T100NULL;

};

#endif // T100EXECUTOR32_H
