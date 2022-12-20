#ifndef T100VPCSERVE_H
#define T100VPCSERVE_H

#include "T100Common.h"
#include "T100DeviceInfo.h"
#include "T100QU32.h"


namespace T100VPC{

class T100VPCServe
{
    friend class T100VPCCallback;
    public:
        T100VPCServe();
        virtual ~T100VPCServe();

        T100BOOL                start();
        T100BOOL                stop();

        T100BOOL                running();

        T100BOOL                createCallback();

        T100WORD                getReturn();

    protected:
        T100WORD                m_return;

        T100BOOL                load();

        T100BOOL                init();

        T100BOOL                createDevice(T100QU32::T100QU32*, T100DeviceInfo*);


    private:
        T100QU32::T100QU32*                 m_host          = T100NULL;
        T100QU32::T100QU32Interface*        m_callback          = T100NULL;

};

}

#endif // T100VPCSERVE_H
