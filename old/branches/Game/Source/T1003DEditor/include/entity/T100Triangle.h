#ifndef T100TRIANGLE_H
#define T100TRIANGLE_H

#include "T100Editable.h"

class T100DX12Scene;

class T100Triangle : public T100Editable
{
    public:
        T100Triangle();
        virtual ~T100Triangle();

        static T100WSTRING          Name;
        static T100ENTITY_TYPE      Type;

        T100VOID                    Load(T100DX12Scene*);
        T100DX12Model*              Convert(T100DX12Studio*);

        virtual T100VOID            ToJSON(JSON&);
        virtual T100VOID            FromJSON(JSON&);

        Vertex*                     vertex;
        T100UINT                    Length;

        T100WSTRING                 file            = L"line.hlsl";
        std::string                 vertexName      = "VSMain";
        std::string                 vertexID        = "vs_5_0";
        std::string                 pixelName       = "PSMain";
        std::string                 pixelID         = "ps_5_0";


        Vertex                      triangleVertices[3] =
            {
                { { 0.0f, 0.25f, 0.0f }, { 1.0f, 0.0f, 0.0f, 1.0f } },
                { { 0.25f, -0.25f, 0.0f }, { 0.0f, 1.0f, 0.0f, 1.0f } },
                { { -0.25f, -0.25f, 0.0f }, { 0.0f, 0.0f, 1.0f, 1.0f } }
            };
        T100UINT                    Size(){
                                        return sizeof(triangleVertices);
                                    }

        const T100D3D12_INPUT_ELEMENT_DESC      StandardVertexDescription[2] =
        {
            { L"POSITION", 0, T100DXGI_FORMAT_R32G32B32_FLOAT, 0, 0,  T100D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
            { L"COLOR",   0, T100DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, T100D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 }
        };
        T100UINT StandardVertexDescriptionNumElements = _countof(StandardVertexDescription);

    protected:

    private:
        T100VOID            init();
        T100VOID            uninit();
};

#endif // T100TRIANGLE_H
