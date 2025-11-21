#ifndef T100HOST_H
#define T100HOST_H

#include "T100Port.h"
#include "T100Memory.h"
#include "T100Device.h"
#include "T100Processor.h"

#include <winhvemulation.h>

class T100Host
{
    public:
        T100Host();
        virtual ~T100Host();

        virtual T100VOID            Start();
        virtual T100VOID            Stop();

    protected:
        T100Port                    m_port;
        T100Memory                  m_memory;
        T100Device                  m_device;
        T100Processor               m_processor;

        BOOL                        m_hypervisorPresent     = FALSE;
        WHV_PARTITION_HANDLE        m_partition             = T100NULL;

        virtual T100VOID            Run();

        T100VOID                    Install();

        WHV_EMULATOR_HANDLE         m_emulator;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100HOST_H
