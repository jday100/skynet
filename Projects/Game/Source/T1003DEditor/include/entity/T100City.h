#ifndef T100CITY_H
#define T100CITY_H

#include <windows.h>
#include <d3d12.h>
#include "T100Entity.h"

class T100City : public T100Entity
{
    public:
        T100City();
        virtual ~T100City();

        T100WSTRING                 VertexShaderFile;
        T100WSTRING                 PixelShaderFile1;
        T100WSTRING                 PixelShaderFile2;
        T100WSTRING                 DataFileName        = L"occcity.bin";

        T100BOOL                    UseBundles          = T100TRUE;
        UINT                        CityRowCount        = 10;
        UINT                        CityColumnCount     = 3;

        const D3D12_INPUT_ELEMENT_DESC StandardVertexDescription[4] =
        {
            { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0,  D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
            { "NORMAL",   0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 12, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
            { "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT,    0, 24, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
            { "TANGENT",  0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 32, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
        };
        UINT StandardVertexDescriptionNumElements = _countof(StandardVertexDescription);

        const UINT StandardVertexStride = 44;

        const DXGI_FORMAT StandardIndexFormat = DXGI_FORMAT_R32_UINT;

        struct TextureResource
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

        struct DrawParameters
        {
            INT DiffuseTextureIndex;
            INT NormalTextureIndex;
            INT SpecularTextureIndex;
            UINT IndexStart;
            UINT IndexCount;
            UINT VertexBase;
        };

        const UINT VertexDataOffset = 524288;
        const UINT VertexDataSize = 820248;
        const UINT IndexDataOffset = 1344536;
        const UINT IndexDataSize = 74568;

        TextureResource Textures[1] =
        {
            { 1024, 1024, 1, DXGI_FORMAT_BC1_UNORM, { { 0, 524288, 2048 }, } }, // city.dds
        };

        DrawParameters Draws[1] =
        {
            { 0, -1, -1, 0, 18642, 0 },
        };

    protected:

    private:
        T100VOID                    create();
        T100VOID                    destroy();
};

#endif // T100CITY_H
