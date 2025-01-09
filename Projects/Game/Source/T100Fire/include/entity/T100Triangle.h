#ifndef T100TRIANGLE_H
#define T100TRIANGLE_H

#include "T100Entity.h"

class T100Triangle : public T100Entity
{
    public:
        T100Triangle();
        virtual ~T100Triangle();

        T100FLOAT*          vertex;
        T100UINT            vertexSize;

        T100FLOAT           index;
        T100UINT            indexSize;

        T100FLOAT           texture;
        T100UINT            textureSize;

    protected:

    private:
        T100VOID            create();
        T100VOID            destroy();
};

#endif // T100TRIANGLE_H
