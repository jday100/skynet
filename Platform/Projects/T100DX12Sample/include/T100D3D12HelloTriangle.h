#ifndef T100D3D12HELLOTRIANGLE_H
#define T100D3D12HELLOTRIANGLE_H

#include "T100DXSample.h"

using namespace DirectX;
using Microsoft::WRL::ComPtr;

class T100D3D12HelloTriangle : public T100DXSample
{
    public:
        T100D3D12HelloTriangle(UINT width, UINT height, std::wstring name);
        virtual ~T100D3D12HelloTriangle();

        virtual void            OnInit();
        virtual void            OnUpdate();
        virtual void            OnRender();
        virtual void            OnDestroy();

    protected:

    private:
        static const UINT FrameCount = 2;

        struct Vertex
        {
            XMFLOAT3 position;
            XMFLOAT4 color;
        };

        CD3DX12_VIEWPORT                    m_viewport;
        CD3DX12_RECT                        m_scissorRect;
        ComPtr<IDXGISwapChain3>             m_swapChain;
        ComPtr<ID3D12Device>                m_device;
        ComPtr<ID3D12Resource>              m_renderTargets[FrameCount];
        ComPtr<ID3D12CommandAllocator>      m_commandAllocator;
        ComPtr<ID3D12CommandQueue>          m_commandQueue;
        ComPtr<ID3D12RootSignature>         m_rootSignature;
        ComPtr<ID3D12DescriptorHeap>        m_rtvHeap;
        ComPtr<ID3D12PipelineState>         m_pipelineState;
        ComPtr<ID3D12GraphicsCommandList>   m_commandList;
        UINT                                m_rtvDescriptorSize;

        ComPtr<ID3D12Resource>              m_vertexBuffer;
        D3D12_VERTEX_BUFFER_VIEW            m_vertexBufferView;

        UINT                                m_frameIndex;
        HANDLE                              m_fenceEvent;
        ComPtr<ID3D12Fence>                 m_fence;
        UINT64                              m_fenceValue;

        void LoadPipeline();
        void LoadAssets();
        void PopulateCommandList();
        void WaitForPreviousFrame();
};

#endif // T100D3D12HELLOTRIANGLE_H
