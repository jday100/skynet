#ifndef T100DX12RENDERER_H
#define T100DX12RENDERER_H

#include "d3d12/DirectXMath.h"
#include "T100DX12Base.h"
#include "T100Entity.h"

using namespace DirectX;

class T100DX12Renderer : public T100DX12Base
{
    public:
        T100DX12Renderer();
        virtual ~T100DX12Renderer();

        T100VOID                            Append(T100Entity*);

    protected:
        ComPtr<ID3D12RootSignature>         m_rootSignature;
        CD3DX12_VIEWPORT                    m_viewport;
        CD3DX12_RECT                        m_scissorRect;

        ComPtr<ID3D12Resource>              m_vertexBuffer;
        D3D12_VERTEX_BUFFER_VIEW            m_vertexBufferView;

        T100DX12_ENTITY_VECTOR              m_entities;

    private:
        virtual T100VOID                    LoadAssets();
        virtual T100VOID                    PopulateCommandList();

        float                               m_aspectRatio;
        std::wstring                        m_assetsPath;
        std::wstring                        GetAssetFullPath(LPCWSTR assetName);
};

#endif // T100DX12RENDERER_H
