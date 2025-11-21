#ifndef T100VPCAPPLICATION_H
#define T100VPCAPPLICATION_H

#include "gui/T100Win32Application.h"
#include "T100VPC.h"

using namespace T100WINDOWS;

class T100VPCApplication : public T100Win32Application
{
    public:
        T100VPCApplication();
        virtual ~T100VPCApplication();

        virtual T100VOID            Create();
        virtual T100VOID            Destroy();

    protected:
        T100VPC*                    m_vpc       = T100NULL;

        T100VOID                    CreateMenu(T100Frame*);

    private:
        T100VOID                    OnStart(T100MenuEvent&);
        T100VOID                    OnStop(T100MenuEvent&);
        T100VOID                    OnQuit(T100MenuEvent&);
};

#endif // T100VPCAPPLICATION_H
