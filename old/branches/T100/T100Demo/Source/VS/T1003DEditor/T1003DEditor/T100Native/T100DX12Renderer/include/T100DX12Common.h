#ifndef T100DX12COMMON_H
#define T100DX12COMMON_H

#include "dx12/T100DX12Header.h"

typedef enum{
    T100DX12_CONTEXT_EVENT_REMOVE,
    T100DX12_CONTEXT_EVENT_POSITION,
    T100DX12_CONTEXT_EVENT_ROTATION,
    T100DX12_CONTEXT_EVENT_SCALING,
    T100DX12_CONTEXT_EVENT_VISIBLE
}T100DX12_CONTEXT_EVENT_TYPE;


struct DX12TextureResource
{
    UINT Width;
    UINT Height;
    UINT16 MipLevels;
    DXGI_FORMAT Format;
    struct DataProperties
    {
        UINT Offset;
        UINT Size;
        UINT Pitch;
    } Data[D3D12_REQ_MIP_LEVELS];
};

struct DX12DrawParameters
{
    INT DiffuseTextureIndex;
    INT NormalTextureIndex;
    INT SpecularTextureIndex;
    UINT IndexStart;
    UINT IndexCount;
    UINT VertexBase;
};


#endif // T100DX12COMMON_H
