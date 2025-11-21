#ifndef T100DX12TRIANGLE_H
#define T100DX12TRIANGLE_H

#include "dx12/T100DX12Header.h"

class T100DX12Studio;

class T100DX12Triangle
{
    public:
        T100DX12Triangle(T100DX12Studio*);
        virtual ~T100DX12Triangle();

        virtual T100VOID        Start();
        virtual T100VOID        Stop();

        virtual T100VOID        Update();
        virtual T100VOID        Render();

    protected:
        T100DX12Studio*         m_studio            = T100NULL;

        ComPtr<ID3D12CommandAllocator>          m_commandAllocator;
        ComPtr<ID3D12GraphicsCommandList>       m_commandList;
        ComPtr<ID3D12PipelineState>             m_pipelineState;

        ComPtr<ID3D12RootSignature>             m_rootSignature;

        ComPtr<ID3D12Resource>                  m_vertexBuffer;
        D3D12_VERTEX_BUFFER_VIEW                m_vertexBufferView;

    protected:
        T100VOID                LoadAssets();
        T100VOID                PopulateCommandList();

    private:
};

#endif // T100DX12TRIANGLE_H
