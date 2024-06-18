#ifndef T100CUBOID_H
#define T100CUBOID_H

#include "T100Entity.h"

class T100Cuboid : public T100Entity
{
    public:
        T100Cuboid();
        virtual ~T100Cuboid();

        T100VOID            Create(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID            Destroy();

    protected:

    private:
};

#endif // T100CUBOID_H
