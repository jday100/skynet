#ifndef T100DX12BUNDLES_H
#define T100DX12BUNDLES_H

#include "T100DX12Base.h"

class T100DX12Bundles : public T100DX12Base
{
    public:
        T100DX12Bundles();
        virtual ~T100DX12Bundles();

        virtual T100VOID                    Append(T100Entity*);

    protected:
        ComPtr<ID3D12RootSignature>         m_rootSignature;
        ComPtr<ID3D12PipelineState>         m_pipelineState1;
        ComPtr<ID3D12PipelineState>         m_pipelineState2;

    protected:
        virtual T100VOID                    LoadEntity(T100Entity*);

        virtual T100VOID                    LoadVertexBuffer(T100Entity*);
        virtual T100VOID                    LoadPixelBuffer(T100Entity*);
        virtual T100VOID                    LoadTexture(T100Entity*);

    protected:
        T100VOID                            CreateRootSignature();
        //T100VOID                            LoadShader(UINT8**, UINT&, UINT8**, UINT&, UINT8**, UINT&);
        T100VOID                            CreatePipelineState(UINT8*, UINT, UINT8*, UINT, UINT8*, UINT);
        T100VOID                            CreateCommandList();
        T100VOID                            CreateRenderTargetView();
        T100VOID                            LoadMeshData(UINT8**, UINT&);
        T100VOID                            CreateVertexBuffer(ComPtr<ID3D12Resource>&, UINT8*, UINT);
        T100VOID                            CreateIndexBuffer(ComPtr<ID3D12Resource>&, UINT8*, UINT);
        T100VOID                            CreateTexture(UINT&, UINT64&);
        T100VOID                            CreateSampler(ComPtr<ID3D12Resource>&, UINT8*, UINT, UINT, UINT64);
        T100VOID                            CreateTextureSRV();
        T100VOID                            CreateDepthStencilView();
        T100VOID                            ExecuteCommandList();
        T100VOID                            CreateFence();
        T100VOID                            CreateFrameResources();

        T100VOID                            UpdateFrameTimer();
        T100VOID                            UpdateFence();
        T100VOID                            UpdateCamera();
        T100VOID                            UpdateFrameResource();

        T100VOID                            PopulateCommandList(T100DX12FrameResource*);
        T100VOID                            ExecuteCommandListRender();
        T100VOID                            SwapChainPresent();
        T100VOID                            FenceSignal();
        T100VOID                            WaitForPreviousFrame();

        std::wstring                        m_assetsPath;
        std::wstring                        m_title;

        std::wstring                        GetAssetFullPath(LPCWSTR assetName);
        void                                SetCustomWindowText(LPCWSTR text);


    private:
        T100VOID                            LoadShader(T100WSTRING, UINT8**, UINT&);
        T100VOID                            CreatePipelineState();
        T100VOID                            LoadMesh();
        T100VOID                            CreateBuffer();
        T100VOID                            CreateTexture();
        T100VOID                            CreateSampler();
};

#endif // T100DX12BUNDLES_H
