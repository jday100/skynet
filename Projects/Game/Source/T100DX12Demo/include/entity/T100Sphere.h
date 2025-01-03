#ifndef T100SPHERE_H
#define T100SPHERE_H

#include <d3d12.h>
#include "T100EntityBase.h"


class T100Sphere : public T100EntityBase
{
    public:
        T100Sphere();
        virtual ~T100Sphere();

    protected:
        void            create();
        void            destroy();

    private:

};

#endif // T100SPHERE_H
