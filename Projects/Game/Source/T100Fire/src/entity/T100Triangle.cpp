#include "T100Triangle.h"

T100Triangle::T100Triangle()
    :T100Entity()
{
    //ctor
    create();
}

T100Triangle::~T100Triangle()
{
    //dtor
    destroy();
}

T100VOID T100Triangle::create()
{
    vertexSize  = 12;
    vertex      = T100NEW T100FLOAT[vertexSize];

    vertex[0]   = 1;
    vertex[1]   = 1;
    vertex[2]   = 1;
    vertex[3]   = 1;

    vertex[4]   = 1;
    vertex[5]   = 1;
    vertex[6]   = 1;
    vertex[7]   = 1;

    vertex[8]   = 1;
    vertex[9]   = 1;
    vertex[10]  = 1;
    vertex[11]  = 1;
}

T100VOID T100Triangle::destroy()
{
    delete[] vertex;
}
