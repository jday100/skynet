#ifndef T100VPC_H
#define T100VPC_H

#include "T100Host.h"
#include "T100VPCFrame.h"

using namespace T100LIBRARY;

class T100VPC
{
    public:
        T100VPC();
        virtual ~T100VPC();

        T100VOID            Create(T100Win32Application*);
        T100VOID            Destroy();

        T100VOID            Start();
        T100VOID            Stop();

    protected:
        T100Host            m_host;
        T100VPCFrame*       m_frame     = T100NULL;

    private:
};

#endif // T100VPC_H
