#ifndef T100VPCAPP_H
#define T100VPCAPP_H

#include "T100Common.h"
#include "T100AppBase.h"
#include "T100ThisAppManager.h"


namespace T100VPC{
class T100VPCServe;
class T100VPCView;


class T100VPCApp : public T100Library::T100AppBase
{
    public:
        T100VPCApp(T100ThisAppManager*);
        virtual ~T100VPCApp();

        T100VOID            setServe(T100VPCServe*);
        T100VPCServe*       getServe();

        T100VOID            setView(T100VPCView*);
        T100VPCView*        getView();

        T100BOOL            show();

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
        T100VPCServe*       m_serve         = T100NULL;
        T100VPCView*        m_view          = T100NULL;

};

}

#endif // T100VPCAPP_H
