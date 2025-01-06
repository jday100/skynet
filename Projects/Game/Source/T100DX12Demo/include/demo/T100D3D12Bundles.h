#ifndef T100D3D12BUNDLES_H
#define T100D3D12BUNDLES_H

#include "T100DXSample.h"
#include "T100StepTimer.h"
#include "T100FrameResource.h"
#include "T100SimpleCamera.h"

using namespace DirectX;
using Microsoft::WRL::ComPtr;

class T100D3D12Bundles : public T100DXSample
{
    public:
        T100D3D12Bundles(UINT width, UINT height, std::wstirng name);
        virtual ~T100D3D12Bundles();

        virtual void            OnInit();
        virtual void            OnUpdate();
        virtual void            OnRender();
        virtual void            OnDestroy();

        virtual void            OnKeyDown(UINT8 key);
        virtual void            OnKeyUp(UINT8 key);

    protected:

    private:
        static const UINT       FrameCount              = 3;
        static const UINT       CityRowCount            = 10;
        static const UINT       CityColumnCount         = 3;
        static const bool       UseBundles              = true;

        CD3DX12_VIEWPORT                    m_viewport;
        CD3DX12_RECT                        m_scissorRect;
        ComPtr<IDXGISwapChain3>             m_swapChain;
        ComPtr<ID3D12Device>                m_device;
        ComPtr<ID3D12Resource>              m_renderTargets[FrameCount];
        ComPtr<ID3D12Resource>              m_depthStencil;
        ComPtr<ID3D12CommandAllocator>      m_commandAllocator;
        ComPtr<ID3D12CommandQueue>          m_commandQueue;
        ComPtr<ID3D12RootSignature>         m_rootSignature;
        ComPtr<ID3D12DescriptorHeap>        m_rtvHeap;
        ComPtr<ID3D12DescriptorHeap>        m_cbvSrvHeap;
        ComPtr<ID3D12DescriptorHeap>        m_dsvHeap;
        ComPtr<ID3D12DescriptorHeap>        m_samplerHeap;
        ComPtr<ID3D12PipelineState>         m_pipelineState1;
        ComPtr<ID3D12PipelineState>         m_pipelineState2;
        ComPtr<ID3D12GraphicsCommandList>   m_commandList;

        UINT                                m_numIndices;
        ComPtr<ID3D12Resource>              m_vertexBuffer;
        ComPtr<ID3D12Resource>              m_indexBuffer;
        ComPtr<ID3D12Resource>              m_texture;
        D3D12_VERTEX_BUFFER_VIEW            m_vertexBufferView;
        D3D12_INDEX_BUFFER_VIEW             m_indexBufferView;
        StepTimer                           m_timer;
        UINT                                m_cbvSrvDescriptorSize;
        UINT                                m_rtvDescriptorSize;
        SimpleCamera                        m_camera;

        std::vector<FrameResource*>         m_frameResources;
        FrameResource*                      m_pCurrentFrameResource;
        UINT                                m_currentFrameResourceIndex;

        UINT                                m_frameIndex;
        UINT                                m_frameCounter;
        HANDLE                              m_fenceEvent;
        ComPtr<ID3D12Fence>                 m_fence;
        UINT64                              m_fenceValue;

        void                                LoadPipeline();
        void                                LoadAssets();
        void                                CreateFrameResources();
        void                                PopulateCommandList(FrameResource* pFrameResource);
};

#endif // T100D3D12BUNDLES_H
