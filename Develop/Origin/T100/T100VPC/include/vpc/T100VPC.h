#ifndef T100VPC_H
#define T100VPC_H

#include "T100Common.h"

using namespace T100LIBRARY;

class T100VPC
{
    public:
        T100VPC();
        virtual ~T100VPC();

        T100VOID            Start();
        T100VOID            Stop();

    protected:

    private:
};

#endif // T100VPC_H
