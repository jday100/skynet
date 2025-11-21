#ifndef T100DX12CONFIG_H
#define T100DX12CONFIG_H

#include "T100Common.h"
#include "common/T100DX12Common.h"

typedef enum{
    T100DX12_HEAP_SMALL,
    T100DX12_HEAP_MEDIUM,
    T100DX12_HEAP_BIG,
    T100DX12_HEAP_LARGE
}T100DX12_CBV_SRV_HEAP_SIZE;

class T100DX12Config
{
    public:
        T100DX12Config(T100DX12_CBV_SRV_HEAP_SIZE  = T100DX12_HEAP_SMALL);
        virtual ~T100DX12Config();

        T100DX12_COORDINATE_SYSTEM_TYPE         DefaultCoordinateSystemType         = T100DX12_COORDINATE_SYSTEM_LEFT_HAND;
        T100DX12_PROJECTION_TYPE                DefaultProjectionType               = T100DX12_PERSPECTIVE_PROJECTION;

        T100UINT                                CbvSrvHeapSize          = 0;
        T100UINT                                DsvHeapSize             = 0;
        T100UINT                                SamplerHeapSize         = 0;

    protected:
        T100UINT                                Parse(T100DX12_CBV_SRV_HEAP_SIZE);

    private:
};

#endif // T100DX12CONFIG_H
