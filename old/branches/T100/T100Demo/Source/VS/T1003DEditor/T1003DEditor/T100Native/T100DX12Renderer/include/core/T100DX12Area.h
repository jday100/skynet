#ifndef T100DX12AREA_H
#define T100DX12AREA_H

#include "T100DX12Stance.h"

class T100DX12Area : public T100DX12Stance
{
    friend class T100DX12Frame;
    friend class T100DX12MeshContext;
    friend class T100DX12ScreenContext;
    public:
        T100DX12Area();
        virtual ~T100DX12Area();

        CD3DX12_VIEWPORT&                   GetViewport();
        CD3DX12_RECT&                       GetScissorRect();

        T100FLOAT                           GetAspectRatio();

        virtual T100VOID                    Create(HWND, T100UINT, T100UINT);
        virtual T100VOID                    Destroy();

        virtual T100VOID                    SetSize(T100UINT, T100UINT);

        virtual T100VOID                    Start();
        virtual T100VOID                    Stop();

    protected:
        HWND                                m_hwnd;
        T100UINT                            m_width;
        T100UINT                            m_height;

        T100UINT                            m_frameIndex;

        T100FLOAT                           m_aspectRatio;

        ComPtr<IDXGISwapChain3>             m_swapChain;
        ComPtr<ID3D12Resource>              m_renderTargets[m_frameCount];
        ComPtr<ID3D12Resource>              m_depthStencil;

        CD3DX12_VIEWPORT                    m_viewport;
        CD3DX12_RECT                        m_scissorRect;

    protected:
        T100VOID                            CreateSwapChain();
        T100VOID                            CreateRenderTargetView();
        T100VOID                            CreateDepthStencilView();

        T100VOID                            Present();
        T100VOID                            UpdateFrameIndex();

    private:
};

#endif // T100DX12AREA_H
