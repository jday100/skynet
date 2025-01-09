#ifndef T100SQUARE_H
#define T100SQUARE_H

#include "T100Entity.h"

class T100Square : public T100Entity
{
    public:
        T100Square();
        virtual ~T100Square();

        T100FLOAT           vertex;
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

#endif // T100SQUARE_H
