#ifndef T1003DCONFIG_H
#define T1003DCONFIG_H

#include "T1003DRendererCommon.h"

class T1003DConfig
{
    public:
        T1003DConfig(T1003D_HEAP_SIZE = T1003D_HEAP_MEDIUM);
        virtual ~T1003DConfig();

        T100UINT            RtvHeapSize             = 0;
        T100UINT            CbvSrvHeapSize          = 0;
        T100UINT            DsvHeapSize             = 0;
        T100UINT            SamplerHeapSize         = 0;

    protected:
        T100UINT            Parse(T1003D_HEAP_SIZE);

    private:
};

#endif // T1003DCONFIG_H
