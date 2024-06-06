#ifndef T100DX12RENDERER_H
#define T100DX12RENDERER_H

#include "T100Renderer.h"

class T100DX12Renderer : public T100Renderer
{
    public:
        T100DX12Renderer();
        virtual ~T100DX12Renderer();

        T100VOID            Start();
        T100VOID            Stop();

    protected:
        T100BOOL            m_useWarpDevice;

        T100VOID            LoadPipeline();
        T100VOID            LoadAssets();

    private:
        static const UINT   FrameCount  = 2;

        Microsoft::WRL::ComPtr<IDXGISwapChain3>                 m_swapChain;
        Microsoft::WRL::ComPtr<ID3D12Device>                    m_device;
        Microsoft::WRL::ComPtr<ID3D12Resource>                  m_renderTargets[FrameCount];
        Microsoft::WRL::ComPtr<ID3D12CommandAllocator>          m_commandAllocator;
        Microsoft::WRL::ComPtr<ID3D12CommandQueue>              m_commandQueue;
        Microsoft::WRL::ComPtr<ID3D12DescriptorHeap>            m_rtvHeap;
        Microsoft::WRL::ComPtr<ID3D12PipelineState>             m_pipelineState;
        Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList>       m_commandList;

};

#endif // T100DX12RENDERER_H
