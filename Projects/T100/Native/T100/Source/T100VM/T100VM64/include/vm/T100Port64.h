#ifndef T100PORT64_H
#define T100PORT64_H

#include "T100Bus64.h"


class T100Port64
{
    public:
        T100Port64(T100Bus64*);
        virtual ~T100Port64();

    protected:

    private:
        T100Bus64*          m_bus           = T100NULL;
};

#endif // T100PORT64_H
