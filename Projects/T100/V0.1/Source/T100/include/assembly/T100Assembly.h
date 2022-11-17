#ifndef T100ASSEMBLY_H
#define T100ASSEMBLY_H

#include "T100Produce.h"

namespace T100Assembly{

class T100Assembly
{
    public:
        T100Assembly();
        virtual ~T100Assembly();

        T100BOOL            run(T100STRING, T100STRING);

        T100Produce&        getProduce();

    protected:

    private:
        T100Produce         m_produce;

};

}

#endif // T100ASSEMBLY_H
