#ifndef T100VMSERVE_H
#define T100VMSERVE_H

#include "T100VM.h"

class T100PSVMServe;

class T100VMServe
{
    public:
        T100VMServe(T100PSVMServe&);
        virtual ~T100VMServe();

        T100VM*                 GetVM();

        T100BOOL                Start();
        T100BOOL                Stop();

        T100BOOL                DebugStart();
        T100BOOL                DebugStop();

    protected:
        T100PSVMServe&          m_psvm;
        T100VM*                 m_vm        = T100NULL;

    private:
};

#endif // T100VMSERVE_H
