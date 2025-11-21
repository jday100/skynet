#ifndef T100DX12CONTEXT_H
#define T100DX12CONTEXT_H

#include <vector>
#include "dx12/T100DX12Header.h"
#include "T100Common.h"
#include "T1003DCommon.h"
#include "vector/T100Vector3f.h"
#include "event/T100DX12Event.h"

class T100DX12Studio;
class T100DX12Frame;

struct SceneConstantBuffer
{
    XMFLOAT4X4 mvp;
    FLOAT padding[48];
};

#define     T100DX12_CONTEXT_VECTOR         std::vector<T100DX12Context*>

class T100DX12Context
{
    friend class T100DX12ContextManager;
    friend class T100DX12ContextManagerBase;
    public:
        T100DX12Context();
        virtual ~T100DX12Context();

        T100UINT                                Type        = 0;

        virtual T100VOID                        Update() = 0;
        virtual T100VOID                        Render() = 0;

        T100VOID                                Clear();

        T100VOID                                SetStudioPtr(T100DX12Studio*);
        T100DX12Studio*                         GetStudioPtr();

        T100VOID                                SetFramePtr(T100DX12Frame*);
        T100DX12Frame*                          GetFramePtr();

        T100BUNDLE                              Bundle;

        T100VOID                                CreateBundle();
        T100VOID                                CreateCityBundle();

        T1003D_RENDER_TYPE                      RenderType;
        T1003D_MOTION_TYPE                      MotionType;

        T100VOID                                AppendEvent(T100UINT, T100Vector3f&);
        T100VOID                                AppendEvent(T100UINT, T100BOOL);

        T100VOID                                SetPosition(XMFLOAT3&);
        T100VOID                                SetPosition(T100Vector3f&);

    protected:
        T100DX12Studio*                         m_studioPtr             = T100NULL;
        T100DX12Frame*                          m_framePtr              = T100NULL;

        ComPtr<ID3D12RootSignature>             m_rootSignature;
        ComPtr<ID3D12GraphicsCommandList>       m_commandList;
        ComPtr<ID3D12PipelineState>             m_pipelineState;

        ComPtr<ID3D12PipelineState>             m_pipelineState1;
        ComPtr<ID3D12PipelineState>             m_pipelineState2;

        ComPtr<ID3D12CommandAllocator>          m_bundleAllocator;
        ComPtr<ID3D12GraphicsCommandList>       m_bundleCommandList;

        D3D12_VERTEX_BUFFER_VIEW*               m_vertexBufferViewPtr   = T100NULL;
        D3D12_INDEX_BUFFER_VIEW*                m_indexBufferViewPtr    = T100NULL;

        T100UINT                                m_frameIndex            = 0;

        T100UINT                                m_cbvSrvHeapIndex       = 0;
        T100UINT                                m_textureHeapIndex      = 0;

        T100UINT                                m_amount                = 0;

        ComPtr<ID3D12Resource>                  m_cbvUploadHeap;
        SceneConstantBuffer*                    m_constantBuffersPtr    = T100NULL;
        UINT64                                  m_fenceValue;
        std::vector<XMFLOAT4X4>                 m_modelMatrices;

        XMFLOAT3                                m_position;
        XMFLOAT3                                m_rotation;
        XMFLOAT3                                m_scaling;
        T100BOOL                                m_visible           = T100TRUE;

        XMMATRIX                                BuildWorld();
        T100VOID                                UpdateBundle();
        T100VOID                                UpdateBundle(XMMATRIX&, XMMATRIX&);

        T100VOID                                DrawBundle();

        T100VOID                                Events();
        T100VOID                                RunEvent(T100DX12Event&);

        T100VOID                                SetBundlePositions();

    private:
        T100DX12_EVENT_QUEUE                    m_events;

        T100VOID                                init();
        T100VOID                                uninit();
};

#endif // T100DX12CONTEXT_H
