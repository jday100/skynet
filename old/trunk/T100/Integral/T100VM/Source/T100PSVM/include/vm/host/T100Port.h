#ifndef T100PORT_H
#define T100PORT_H

#include "T100Common.h"

class T100Host;

class T100Port
{
    public:
        T100Port(T100Host*);
        virtual ~T100Port();

    protected:

    private:
};

#endif // T100PORT_H
