#ifndef T100DX12FRAME_H
#define T100DX12FRAME_H

#include <mutex>
#include <atomic>
#include <vector>
#include <condition_variable>
#include "T100Common.h"
#include "dx12/T100DX12Header.h"
#include "T100DX12Context.h"

class T100DX12Studio;

#define     T100DX12_FRAME_VECTOR           std::vector<T100DX12Frame*>

class T100DX12Frame
{
    friend class T100DX12MeshContext;
    friend class T100DX12ScreenContext;
    friend class T100DX12FrameManager;
    friend class T100DX12ContextManagerBase;
    public:
        T100DX12Frame(T100DX12Studio*);
        virtual ~T100DX12Frame();

        virtual T100VOID                        Update();
        virtual T100VOID                        Render();

        virtual T100VOID                        Append(T100DX12Context*);
        virtual T100VOID                        Remove(T100DX12Context*);

        T100VOID                                SetIndex(T100UINT);
        T100UINT                                GetIndex();

    protected:
        T100DX12Studio*                         m_studioPtr     = T100NULL;
        T100UINT                                m_index         = 0;
        T100UINT64                              m_fenceValue    = 0;

        ComPtr<ID3D12CommandAllocator>          m_commandAllocator;
        ComPtr<ID3D12GraphicsCommandList>       m_commandList;
        ComPtr<ID3D12PipelineState>             m_pipelineState;

        T100DX12_CONTEXT_VECTOR                 m_contexts;
        T100DX12_CONTEXT_VECTOR                 m_pendingAppends;
        T100DX12_CONTEXT_VECTOR                 m_pendingRemoves;

        T100VOID                                AppendContexts();
        T100VOID                                RemoveContexts();

        T100VOID                                RemoveContext(T100DX12Context*);

        T100VOID                                FrameRender();

    private:
        std::atomic_bool                        m_append;
        std::atomic_bool                        m_remove;

        std::mutex                              m_mutex;
        std::condition_variable                 m_condition;

        T100VOID                                init();
        T100VOID                                uninit();
};

#endif // T100DX12FRAME_H
