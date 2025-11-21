#include "T100DX12Config.h"

T100DX12Config::T100DX12Config(T100DX12_CBV_SRV_HEAP_SIZE size)
{
    //ctor
    CbvSrvHeapSize  = Parse(size);
}

T100DX12Config::~T100DX12Config()
{
    //dtor
}

T100UINT T100DX12Config::Parse(T100DX12_CBV_SRV_HEAP_SIZE size)
{
    T100UINT        result;

    switch(size)
    {
    case T100DX12_HEAP_SMALL:
        {
            result  = 256;
        }
        break;
    case T100DX12_HEAP_MEDIUM:
        {
            result  = 256 * 256;
        }
        break;
    case T100DX12_HEAP_BIG:
        {
            result  = 256 * 256 * 256;
        }
        break;
    case T100DX12_HEAP_LARGE:
        {
            result  = 256 * 256 * 256 * 256 - 1;
        }
        break;
    default:
        result  = 256;
    }
    return result;
}
