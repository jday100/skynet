#ifndef T100VMHYPERV_H
#define T100VMHYPERV_H

#include "core/T100VMBase.h"

class T100VMHyperV : public T100VMBase
{
    public:
        T100VMHyperV();
        virtual ~T100VMHyperV();

        virtual T100VOID            Start();
        virtual T100VOID            Stop();

    protected:

    private:
};

#endif // T100VMHYPERV_H
