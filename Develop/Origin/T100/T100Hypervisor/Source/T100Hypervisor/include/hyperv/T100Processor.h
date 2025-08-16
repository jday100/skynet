#ifndef T100PROCESSOR_H
#define T100PROCESSOR_H

#include <cstring>
#include <windows.h>
#include <winhvplatform.h>
#include "T100Common.h"

using namespace T100LIBRARY;

class T100Processor
{
    public:
        T100Processor();
        virtual ~T100Processor();

        virtual T100VOID            Create(WHV_PARTITION_HANDLE, T100UINT);

        virtual T100VOID            Start();

        virtual T100VOID            SetRIP(T100UINT64);
        virtual T100UINT64          GetRIP();

        virtual T100VOID            Run(WHV_RUN_VP_EXIT_CONTEXT&);

    protected:
        WHV_PARTITION_HANDLE        m_partition     = T100NULL;

    private:
};

#endif // T100PROCESSOR_H
