#ifndef T100HYPERV_H
#define T100HYPERV_H

#include "host/T100HostBase.h"
#include "T100HyperVCommon.h"
#include "T100Port.h"
#include "T100Memory.h"
#include "base/T100Device.h"
#include "T100Processor.h"

#include <winhvemulation.h>

class T100HyperV : public T100HostBase
{
    public:
        T100HyperV();
        virtual ~T100HyperV();

        virtual T100VOID            Start();
        virtual T100VOID            Stop();

    protected:
        T100Port                    m_port;
        T100Memory                  m_memory;
        T100Device                  m_device;
        T100Processor               m_processor;

        BOOL                        m_hypervisorPresent         = FALSE;
        WHV_PARTITION_HANDLE        m_partition                 = NULL;

        virtual T100VOID            Run();

        T100VOID                    Install();

        WHV_EMULATOR_HANDLE         m_emulator;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100HYPERV_H
