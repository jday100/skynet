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
    vertex  = triangleVertices;
}

T100VOID T100Triangle::destroy()
{

}
