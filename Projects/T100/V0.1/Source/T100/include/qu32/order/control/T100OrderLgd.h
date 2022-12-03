#ifndef T100ORDERLGD_H
#define T100ORDERLGD_H

#include "T100OrderBase.h"

namespace T100QU32{

class T100OrderLgd : public T100OrderBase
{
    public:
        T100OrderLgd(T100QU32*, T100Executor32*);
        virtual ~T100OrderLgd();

        T100SentenceBase::T100OPERATOR_COMPLEXUS_BUILD      target;

    protected:
        T100BOOL            run();
        T100VOID            log();

    private:
};

}

#endif // T100ORDERLGD_H
