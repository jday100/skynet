#ifndef T100DXBUNDLES_H
#define T100DXBUNDLES_H

#include "T100DXBase.h"

class T100DXBundles : public T100DXBase
{
    public:
        T100DXBundles();
        virtual ~T100DXBundles();

        UINT                                    m_cityRowCount          = 10;
        UINT                                    m_cityColumnCount       = 3;

    protected:
        T100VOID                                CreateRtvHeap();
        T100VOID                                CreateDsvHeap();
        T100VOID                                CreateCbvHeap();
        T100VOID                                CreateSamplerHeap();


    private:
};

#endif // T100DXBUNDLES_H
