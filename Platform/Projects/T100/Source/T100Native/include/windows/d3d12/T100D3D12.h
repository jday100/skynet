#ifndef T100D3D12_H
#define T100D3D12_H

#include <windows.h>

#include <d3d12.h>
#include <dxgi1_6.h>
#include <d3dcompiler.h>

#include <wrl.h>
#include <shellapi.h>

#include "T100Common.h"
#include "directxmath.h"

using namespace Microsoft::WRL;

class T100D3D12
{
    public:
        T100D3D12(HWND hwnd);
        virtual ~T100D3D12();

        virtual T100BOOL                        load();
        virtual T100BOOL                        release();

        virtual T100BOOL                        render();

    protected:
        HWND                                    m_hwnd;

    private:
        T100VOID                                create();
        T100VOID                                destroy();

        virtual T100BOOL                        init();
        virtual T100BOOL                        uninit();


    private:
        static const UINT                       m_frame_count           = 2;

        ComPtr<ID3D12Fence>                     m_fence;
        ComPtr<IDXGISwapChain3>                 m_swap_chain;
        ComPtr<ID3D12Device>                    m_device;
        ComPtr<ID3D12Resource>                  m_render_targets[m_frame_count];
        ComPtr<ID3D12CommandAllocator>          m_command_allocator;
        ComPtr<ID3D12CommandQueue>              m_command_queue;
        ComPtr<ID3D12PipelineState>             m_pipeline_state;
        ComPtr<ID3D12GraphicsCommandList>       m_command_list;

        ComPtr<ID3D12DescriptorHeap>            m_heap;
};

#endif // T100D3D12_H
