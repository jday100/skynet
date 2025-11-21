#include "link/T1003DConfig.h"

T1003DConfig::T1003DConfig(T1003D_HEAP_SIZE size)
{
    //ctor
    CbvSrvHeapSize  = Parse(size);
}

T1003DConfig::~T1003DConfig()
{
    //dtor
}

T100UINT T1003DConfig::Parse(T1003D_HEAP_SIZE size)
{
    T100UINT        result;

    switch(size)
    {
    case T1003D_HEAP_SMALL:
        {
            result  = 256;
        }
        break;
    case T1003D_HEAP_MEDIUM:
        {
            result  = 256 * 256;
        }
        break;
    case T1003D_HEAP_BIG:
        {
            result  = 256 * 256 * 256;
        }
        break;
    case T1003D_HEAP_LARGE:
        {
            result  = 256 * 256 * 256 * 256 - 1;
        }
        break;
    default:
        result  = 256;
    }
    return result;
}
