#ifndef T100DEMO_H
#define T100DEMO_H

#include "T100DX12.h"

class T100Demo : public T100DX12
{
    public:
        T100Demo(UINT, UINT, std::wstring);
        virtual ~T100Demo();

        virtual void                    OnInit();
        virtual void                    OnUpdate();
        virtual void                    OnRender();
        virtual void                    OnDestroy();

        virtual void                    OnKeyDown(UINT8 key);
        virtual void                    OnKeyUp(UINT8 key);

    protected:

    private:
        static const UINT               FrameCount          = 3;
        static const UINT               CityRowCount        = 10;
        static const UINT               CityColumnCount     = 3;
        static const bool               UseBundles          = true;

        CD3DX12_VIEWPORT                        m_viewport;
        CD3DX12_RECT                            m_scissorRect;
        ComPtr<IDXGISwapChain3>                 m_swapChain;
        ComPtr<ID3D12Device>                    m_device;
        ComPtr<ID3D12Resource>                  m_renderTargets[FrameCount];
        ComPtr<ID3D12Resource>                  m_depthStencil;
        ComPtr<ID3D12CommandAllocator>          m_commandAllocator;
        ComPtr<ID3D12CommandQueue>              m_commandQueue;
        ComPtr<ID3D12RootSignature>             m_rootSignature;
        ComPtr<ID3D12DescriptorHeap>            m_rtvHeap;
        ComPtr<ID3D12DescriptorHeap>            m_cbvSrvHeap;
        ComPtr<ID3D12DescriptorHeap>            m_dsvHeap;
        ComPtr<ID3D12DescriptorHeap>            m_sampleHeap;
        ComPtr<ID3D12PipelineState>             m_pipelineState1;
        ComPtr<ID3D12PipelineState>             m_pipelineState2;
        ComPtr<ID3d12GraphicsCommandList>       m_commandList;

        UINT                                    m_numIndices;
        ComPtr<ID3D12Resource>                  m_vertexBuffer;
        ComPtr<ID3D12Resource>                  m_indexBuffer;
        ComPtr<ID3D12Resource>                  m_texture;
        D3D12_VERTEX_BUFFER_VIEW                m_vertexBufferView;
        D3D12_INDEX_BUFFER_VIEW                 m_indexBufferView;

        T100Timer                               m_timer;

        UINT                                    m_cbvSrvDescriptorSize;
        UINT                                    m_rtvDescriptorSize;

        T100Camera                              m_camera;

        std::vector<T100FrameResource*>         m_frameResources;
        T100FrameResource*                      m_pCurrentFrameResource;
        UINT                                    m_currentFrameResourceIndex;

        UINT                                    m_frameIndex;
        UINT                                    m_frameCounter;
        HANDLE                                  m_fenceEvent;
        ComPtr<ID3D12Fence>                     m_fence;
        UINT64                                  m_fenceValue;

        void                    LoadPipeline();
        void                    LoadAssets();
        void                    CreateFrameResources();
        void                    PopulateCommandList(T100FrameResource* pFrameResource);

};


#endif // T100DEMO_H
