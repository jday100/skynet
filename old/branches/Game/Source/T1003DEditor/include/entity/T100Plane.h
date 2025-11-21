#ifndef T100PLANE_H
#define T100PLANE_H

#include "T100Editable.h"

class T100Plane : public T100Editable
{
    public:
        T100Plane();
        virtual ~T100Plane();

        static T100ENTITY_TYPE      Type;
        static T100WSTRING          Name;

        virtual T100VOID            Load(T100DX12Scene*);
        virtual T100DX12Model*      Convert(T100DX12Studio*);

        virtual T100VOID            ToJSON(JSON&);
        virtual T100VOID            FromJSON(JSON&);

        Vertex*                     vertex;
        T100UINT                    Length;

        T100WSTRING                 file            = L"line.hlsl";
        std::string                 vertexName      = "VSMain";
        std::string                 vertexID        = "vs_5_0";
        std::string                 pixelName       = "PSMain";
        std::string                 pixelID         = "ps_5_0";
        const T100D3D12_INPUT_ELEMENT_DESC      StandardVertexDescription[2] =
        {
            { L"POSITION", 0, T100DXGI_FORMAT_R32G32B32_FLOAT, 0, 0,  T100D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
            { L"COLOR",   0, T100DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, T100D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 }
        };
        T100UINT StandardVertexDescriptionNumElements = _countof(StandardVertexDescription);

    protected:

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100PLANE_H
