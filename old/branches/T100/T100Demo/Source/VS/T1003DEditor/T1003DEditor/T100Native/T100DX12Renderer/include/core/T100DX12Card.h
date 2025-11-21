#ifndef T100DX12CARD_H
#define T100DX12CARD_H

#include "dx12/T100DX12Header.h"

class T100DX12Card
{
    friend class T100DX12MeshManagerBase;
    public:
        T100DX12Card();
        virtual ~T100DX12Card();

        virtual T100VOID                    Start();
        virtual T100VOID                    Stop();

        ID3D12Device*                       GetDevicePtr();
        T100UINT                            GetFrameCount();

    protected:
        static const T100UINT               m_frameCount        = 3;
        T100BOOL                            m_useWarpDevice;

        ComPtr<IDXGIFactory4>               m_factory;
        ComPtr<ID3D12Device>                m_device;
        ComPtr<ID3D12CommandQueue>          m_commandQueue;
        ComPtr<ID3D12CommandAllocator>      m_commandAllocator;

    protected:
        T100VOID                            CreateFactory();
        T100VOID                            CreateDevice();
        T100VOID                            CreateCommandQueue();
        T100VOID                            CreateCommandAllocator();

    private:
        T100VOID                            GetHardwareAdapter(
            _In_ IDXGIFactory1* pFactory,
            _Outptr_result_maybenull_ IDXGIAdapter1** ppAdapter,
            T100BOOL requestHighPerformanceAdapter = T100FALSE);
};

#endif // T100DX12CARD_H
