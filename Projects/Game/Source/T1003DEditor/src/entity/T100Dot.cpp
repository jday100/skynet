#include "T100Dot.h"

T100Dot::T100Dot()
    :T100Entity()
{
    //ctor
}

T100Dot::~T100Dot()
{
    //dtor
}

T100VOID T100Dot::load()
{
    vertex  = T100NEW Vertex[1];
    size    = 1;

    vertex[0]   = {{1.0f, 1.0f, 1.0f},{1.0f, 1.0f, 1.0f, 1.0f}};
}
