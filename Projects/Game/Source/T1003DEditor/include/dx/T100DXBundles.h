#ifndef T100DXBUNDLES_H
#define T100DXBUNDLES_H

#include "T100DXBase.h"
#include "T100DXResource.h"

class T100DXBundles : public T100DXBase
{
    public:
        T100DXBundles();
        virtual ~T100DXBundles();

        virtual T100VOID                        Update();
        virtual T100VOID                        Render();

        UINT                                    m_cityRowCount          = 10;
        UINT                                    m_cityColumnCount       = 3;

    protected:
        std::vector<T100DXResource*>            m_frameResources;
        T100DXResource*                         m_pCurrentFrameResource;
        UINT                                    m_currentFrameResourceIndex;

        ComPtr<ID3D12RootSignature>             m_rootSignature;

    private:
        T100VOID                                LoadPipeline();

        T100VOID                                GetHardwareAdapter(
                                                                   _In_ IDXGIFactory1* pFactory,
                                                                   _Outptr_result_maybenull_ IDXGIAdapter1** ppAdapter,
                                                                   T100BOOL requestHighPerformanceAdapter = T100FALSE
                                                                   );
        T100VOID                                CreateFactory();
        T100VOID                                CreateDevice();
        T100VOID                                CreateCommandQueue();
        T100VOID                                CreateSwapChain();
        T100VOID                                CreateRtvHeap();
        T100VOID                                CreateDsvHeap();
        T100VOID                                CreateCbvHeap();
        T100VOID                                CreateSamplerHeap();
        T100VOID                                CreateCommandAllocator();

        T100VOID                                LoadAssets();

        T100VOID                                CreateRootSignature();
        T100VOID                                LoadShader();
        T100VOID                                CreatePipelineState(UINT8*);
        T100VOID                                CreateCommandList();
        T100VOID                                CreateRenderTargetView();
        T100VOID                                LoadMeshData();
        T100VOID                                CreateVertexBuffer();
        T100VOID                                CreateIndexBuffer();
        T100VOID                                CreateTexture();
        T100VOID                                CreateSampler();
        T100VOID                                CreateDepthStencilView();
        T100VOID                                ExecuteCommandList();
        T100VOID                                CreateFence();
        T100VOID                                CreateFrameResources();

        T100VOID                                UpdateFrameTimer();
        T100VOID                                UpdateFence();
        T100VOID                                UpdateCamera();
        T100VOID                                UpdateFrameResource();

        T100VOID                                PopulateCommandList(T100DXResource*);
        T100VOID                                ExecuteCommandListRender();
        T100VOID                                SwapChainPresent();
        T100VOID                                FenceSignal();
        T100VOID                                WaitForPreviousFrame();

        std::wstring                            m_assetsPath;
        std::wstring                            m_title;

        std::wstring                            GetAssetFullPath(LPCWSTR assetName);


};

#endif // T100DXBUNDLES_H
