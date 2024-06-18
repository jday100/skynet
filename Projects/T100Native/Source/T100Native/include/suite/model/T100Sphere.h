#ifndef T100SPHERE_H
#define T100SPHERE_H

#include "T100Entity.h"

class T100Sphere : public T100Entity
{
    public:
        T100Sphere();
        virtual ~T100Sphere();

        T100VOID            Create();
        T100VOID            Destroy();

    protected:

    private:
};

#endif // T100SPHERE_H
