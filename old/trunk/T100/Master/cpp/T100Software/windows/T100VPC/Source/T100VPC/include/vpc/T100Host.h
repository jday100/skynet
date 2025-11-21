#ifndef T100HOST_H
#define T100HOST_H

#include "T100Port.h"
#include "T100Memory.h"
#include "T100Processor.h"

#include "T100VPCFrame.h"

class T100Host
{
    public:
        T100Host();
        virtual ~T100Host();

        T100VOID                    SetFrame(T100VPCFrame*);

        virtual T100VOID            Start();
        virtual T100VOID            Stop();

    protected:
        T100Port                    m_port;
        T100Memory                  m_memory;
        T100Processor               m_processor;

        T100VPCFrame*               m_frame     = T100NULL;

        BOOL                        m_hypervisorPresent     = FALSE;
        WHV_PARTITION_HANDLE        m_partition             = T100NULL;

        virtual T100VOID            Run();

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100HOST_H
