#ifndef T100VPCLINK_H
#define T100VPCLINK_H

#include "T100QU32Interface.h"

namespace T100VPC{

class T100VPCLink : public T100QU32::T100QU32Interface
{
    public:
        T100VPCLink();
        virtual ~T100VPCLink();

    protected:

    private:
};

}

#endif // T100VPCLINK_H
