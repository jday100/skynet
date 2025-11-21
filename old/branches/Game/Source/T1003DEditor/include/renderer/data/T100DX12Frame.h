#ifndef T100DX12FRAME_H
#define T100DX12FRAME_H

#include <mutex>
#include <atomic>
#include <vector>
#include <condition_variable>
#include "dx12/T100DX12Header.h"
#include "renderer/data/T100DX12Context.h"

#include <vector>

#define     T100DX12_FRAME_VECTOR               std::vector<T100DX12Frame*>
#define     T100DX12_COMMAND_LIST_VECTOR        std::vector<ID3D12CommandList*>

class T100DX12Frame
{
    friend class T100DX12Model;
    friend class T100DX12Context;
    friend class T100DX12Studio;
    friend class T100DX12FrameManager;
    friend class T100DX12ContextManager;
    public:
        T100DX12Frame();
        virtual ~T100DX12Frame();

        virtual T100VOID                        Append(T100DX12Context*);
        virtual T100VOID                        Remove(T100DX12Context*);

        virtual T100VOID                        Update(T100DX12Studio*);
        virtual T100VOID                        Render(T100DX12Studio*);

        T100VOID                                CreateCommandAllocator(T100DX12Studio*);

        T100UINT                                m_index;

        UINT64                                  m_fenceValue;

    protected:
        T100DX12_CONTEXT_VECTOR                 m_contexts;
        T100DX12_CONTEXT_VECTOR                 m_pendingAppend;
        T100DX12_CONTEXT_VECTOR                 m_pendingRemove;

        T100DX12_COMMAND_LIST_VECTOR            m_commands;
        ComPtr<ID3D12RootSignature>             m_rootSignature;
        ComPtr<ID3D12GraphicsCommandList>       m_commandList;
        ComPtr<ID3D12PipelineState>             m_pipelineState;


    protected:
        T100VOID                                FrameAppend(T100DX12Context*);
        T100VOID                                FrameRemove(T100DX12Context*);
        T100VOID                                FrameUpdate(T100DX12Studio*);
        T100VOID                                FrameRender(T100DX12Studio*);

        T100VOID                                AppendContexts(T100DX12Studio*);
        T100VOID                                RemoveContexts(T100DX12Studio*);
        T100VOID                                RemoveContext(T100DX12Context*);
        T100VOID                                RenderCommands(T100DX12Studio*);

    private:
        std::atomic_bool                        m_append;
        std::atomic_bool                        m_remove;

        std::mutex                              m_mutex;
        std::condition_variable                 m_condition;

        T100VOID                                init();
        T100VOID                                uninit();

    public:
        UINT                                    m_currentFrameResourceIndex;
        ComPtr<ID3D12CommandAllocator>          m_commandAllocator;
};

#endif // T100DX12FRAME_H
