#ifndef T100DX12CONTEXT_H
#define T100DX12CONTEXT_H

#include <vector>
#include "dx12/T100DX12Header.h"
#include "common/T100DX12Common.h"
#include "renderer/event/T100DX12Event.h"

class T100DX12Studio;
class T100DX12Frame;
class T100DX12Model;

#define     T100DX12_CONTEXT_VECTOR         std::vector<T100DX12Context*>

struct SceneConstantBuffer
{
    XMFLOAT4X4 mvp;
    FLOAT padding[48];
};

struct LightConstantBuffer
{
    float               length;
    T100GPU_LIGHT*      lights;
    FLOAT               paddingp[1];
};

class T100DX12Context
{
    friend class T100DX12Discrete;
    friend class T100DX12FrameResource;

    friend class T100DX12Frame;
    friend class T100DX12FrameManager;
    friend class T100DX12ModelManager;
    friend class T100DX12ContextManager;
    friend class T100DX12ContextManagerBase;
    public:
        T100DX12Context();
        virtual ~T100DX12Context();

        T100VOID                                SetStudioPtr(T100DX12Studio*);
        T100DX12Studio*                         GetStudioPtr();

        T100VOID                                SetFramePtr(T100DX12Frame*);
        T100DX12Frame*                          GetFramePtr();

        T100DX12_BUNDLE                         Bundle;
        T100DX12_MODEL_TYPE                     Type;

        T100VOID                                Append(T100UINT, XMFLOAT3);
        T100VOID                                Append(T100UINT, T100BOOL);
        T100VOID                                Clear();

    public:
        T100DX12_RENDER_TYPE                    RenderType;
        T100DX12_MOTION_TYPE                    MotionType;

        UINT                                    m_numIndices;

    protected:
        ComPtr<ID3D12RootSignature>             m_rootSignature;
        ComPtr<ID3D12CommandAllocator>          m_bundleAllocator;
        ComPtr<ID3D12GraphicsCommandList>       m_bundleCommandList;
        ComPtr<ID3D12GraphicsCommandList>       m_commandList;
        ComPtr<ID3D12PipelineState>             m_pipelineState;

        ComPtr<ID3D12PipelineState>             m_pipelineState1;
        ComPtr<ID3D12PipelineState>             m_pipelineState2;

        ComPtr<ID3D12Resource>                  m_cbvUploadHeap;
        SceneConstantBuffer*                    m_constantBuffersPtr;
        UINT64                                  m_fenceValue;
        std::vector<XMFLOAT4X4>                 m_modelMatrices;

        D3D12_VERTEX_BUFFER_VIEW*               m_vertexBufferViewPtr;
        D3D12_INDEX_BUFFER_VIEW*                m_indexBufferViewPtr;

        ///
        CD3DX12_CPU_DESCRIPTOR_HANDLE           m_rtv;
        CD3DX12_CPU_DESCRIPTOR_HANDLE           m_cbvSrv;
        UINT                                    m_cbvSrvHeapIndex;
        CD3DX12_CPU_DESCRIPTOR_HANDLE           m_dsv;
        CD3DX12_CPU_DESCRIPTOR_HANDLE           m_sampler;
        UINT                                    m_samplerHeapIndex;
        UINT                                    m_textureHeapIndex;

    protected:
        T100VOID                                SetBundlePositions();
        XMMATRIX                                BuildWorld();


    protected:
        T100DX12Studio*                         m_studioPtr             = T100NULL;
        T100DX12Frame*                          m_framePtr              = T100NULL;

        T100UINT                                m_frameIndex;
        XMFLOAT3                                m_position;
        XMFLOAT3                                m_rotation;
        XMFLOAT3                                m_scaling;
        T100BOOL                                m_visible;

    private:
        T100VOID                                SetPosition(XMFLOAT3);
        T100VOID                                SetRotation(XMFLOAT3);
        T100VOID                                SetScaling(XMFLOAT3);


        T100VOID                                DrawBundle();
        T100VOID                                UpdateBundle(XMMATRIX& projection, XMMATRIX& view);


    private:
        ComPtr<ID3D12Resource>                  m_vertexBuffer;
        T100DX12_EVENT_QUEUE                    m_events;
};

#endif // T100DX12CONTEXT_H
