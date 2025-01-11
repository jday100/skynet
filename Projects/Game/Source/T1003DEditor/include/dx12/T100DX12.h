#ifndef T100DX12_H
#define T100DX12_H

#include <windows.h>

#include <d3d12.h>
#include <dxgi1_6.h>
#include <wrl.h>
#include "d3d12/d3dx12.h"

#include "T100Common.h"
#include "T100Entity.h"

using Microsoft::WRL::ComPtr;

#define     T100DX12_COMMANDLIST_VECTOR         std::vector<ID3D12GraphicsCommandList*>

class T100DX12
{
    public:
        T100DX12();
        virtual ~T100DX12();

        virtual T100VOID                        Create(HWND, UINT, UINT);
        virtual T100VOID                        Destroy();

        virtual T100VOID                        Start();
        virtual T100VOID                        Stop();

        virtual T100VOID                        Update();
        virtual T100VOID                        Render();

        virtual T100VOID                        Append(T100Entity*);
        virtual T100VOID                        Remove(T100Entity*);

        virtual T100VOID                        SetSize(UINT, UINT);

    protected:
        HWND                                    m_hwnd;
        UINT                                    m_width;
        UINT                                    m_height;

        T100DX12_ENTITY_VECTOR                  m_entities;

        static const UINT                       m_frameCount            = 3;

        ComPtr<ID3D12Device>                    m_device;
        ComPtr<IDXGISwapChain3>                 m_swapChain;
        ComPtr<ID3D12CommandQueue>              m_commandQueue;
        ComPtr<ID3D12CommandAllocator>          m_commandAllocator;

        UINT                                    m_rtvDescriptorSize;
        ComPtr<ID3D12DescriptorHeap>            m_rtvHeap;
        ComPtr<ID3D12PipelineState>             m_pipelineState;

        T100DX12_COMMANDLIST_VECTOR             m_commandLists;
        ComPtr<ID3D12GraphicsCommandList>       m_commandList;

        ComPtr<ID3D12Resource>                  m_renderTargets[m_frameCount];
        UINT                                    m_frameIndex;
        HANDLE                                  m_fenceEvent;
        ComPtr<ID3D12Fence>                     m_fence;
        UINT64                                  m_fenceValue;

        ComPtr<ID3D12RootSignature>             m_rootSignature;
        CD3DX12_VIEWPORT                        m_viewport;
        CD3DX12_RECT                            m_scissorRect;

        ComPtr<ID3D12Resource>                  m_vertexBuffer;
        D3D12_VERTEX_BUFFER_VIEW                m_vertexBufferView;

        float                                   m_aspectRatio;
        std::wstring                            m_assetsPath;
        std::wstring                            GetAssetFullPath(LPCWSTR assetName);
        T100VOID                                WaitForPreviousFrame();

    private:
        T100BOOL                                m_useWarpDevice;

        T100VOID                                LoadPipeline();
        virtual T100VOID                        LoadAssets();
        virtual T100VOID                        LoadEntities();
        virtual T100VOID                        LoadEntity(T100Entity*);

        virtual T100VOID                        PopulateCommandList();


        T100VOID        GetHardwareAdapter(
                                           _In_ IDXGIFactory1* pFactory,
                                           _Outptr_result_maybenull_ IDXGIAdapter1** ppAdapter,
                                           T100BOOL requestHighPerformanceAdapter = T100FALSE
                                           );


};

#endif // T100DX12_H
