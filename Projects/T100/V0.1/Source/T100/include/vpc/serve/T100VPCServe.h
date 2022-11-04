#ifndef T100VPCSERVE_H
#define T100VPCSERVE_H

#include "T100Common.h"
#include "T100QU32.h"


namespace T100VPC{

class T100VPCServe
{
    public:
        T100VPCServe();
        virtual ~T100VPCServe();

        T100BOOL            start();
        T100BOOL            stop();

        T100BOOL            running();

    protected:

    private:
        T100QU32::T100QU32*           m_host          = T100NULL;

};

}

#endif // T100VPCSERVE_H
