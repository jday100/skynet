#ifndef T100ORDERQUIT_H
#define T100ORDERQUIT_H

#include "T100OrderBase.h"

namespace T100QU32{

class T100OrderQuit : public T100OrderBase
{
    public:
        T100OrderQuit(T100QU32*, T100Executor32*);
        virtual ~T100OrderQuit();

    protected:
        T100BOOL            run();
        T100VOID            log();

    private:
};

}

#endif // T100ORDERQUIT_H
