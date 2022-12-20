#ifndef T100VPC_H
#define T100VPC_H

#include "T100Common.h"
#include "T100VPCLog.h"


namespace T100VPC{
class T100VPCApp;
class T100VPCServe;
class T100VPCView;


class T100VPC
{
    public:
        T100VPC(T100VPCApp* = T100NULL);
        virtual ~T100VPC();

        T100VOID                    setServe(T100VPCServe*);
        T100VPCServe*               getServe();

        T100VOID                    setView(T100VPCView*);
        T100VPCView*                getView();

        T100BOOL                    show();
        T100BOOL                    run();
        T100VOID                    quit();

        T100WORD                    getReturn();

    protected:
        T100VOID                    create();
        T100VOID                    destroy();

        T100VOID                    init();

    private:
        T100VPCApp*                 m_app           = T100NULL;
        T100VPCServe*               m_serve         = T100NULL;
        T100VPCView*                m_view          = T100NULL;

};

}

#endif // T100VPC_H
