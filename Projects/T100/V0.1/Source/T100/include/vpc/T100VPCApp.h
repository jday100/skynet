#ifndef T100VPCAPP_H
#define T100VPCAPP_H

#include "T100Common.h"
#include "T100AppBase.h"
#include "T100ThisAppManager.h"


namespace T100VPC{
class T100VPC;

class T100VPCApp : public T100Library::T100AppBase
{
    public:
        T100VPCApp(T100ThisAppManager*);
        virtual ~T100VPCApp();

        T100BOOL            show();

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
        T100VPC*            m_vpc           = T100NULL;

};

}

#endif // T100VPCAPP_H
