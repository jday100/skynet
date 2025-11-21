#ifndef T100DX12BOUNDINGBOX_H
#define T100DX12BOUNDINGBOX_H

//#pragma pack(16)

#include "dx12/T100DX12Header.h"

class T100DX12BoundingBox
{
    public:
        T100DX12BoundingBox();
        virtual ~T100DX12BoundingBox();

    protected:

    private:
        XMVECTOR    m_min;
        XMVECTOR    m_max;
};

#endif // T100DX12BOUNDINGBOX_H
