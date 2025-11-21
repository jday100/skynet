#ifndef T100DX12AREA_H
#define T100DX12AREA_H

#include "T100DX12Stance.h"

//screen size  31cm X 17.5cm
//1920 x 1080 zoom 150%

class T100DX12Area : public T100DX12Stance
{
    friend class T100Line;
    friend class T100DX12Dynamic2;
    friend class T100DX12Model;
    friend class T100DX12Context;
    friend class T100DX12FrameManager;
    friend class T100DX12ContextManager;
    public:
        T100DX12Area();
        virtual ~T100DX12Area();

        virtual T100VOID                    Create(HWND, UINT, UINT);
        virtual T100VOID                    Destroy();

        virtual T100VOID                    SetSize(UINT, UINT);

        virtual T100VOID                    Start();
        virtual T100VOID                    Stop();

        CD3DX12_VIEWPORT*                   GetViewport();
        CD3DX12_RECT*                       GetScissorRect();

        float                               m_aspectRatio;
        UINT                                m_frameIndex;
        ComPtr<ID3D12Resource>              m_renderTargets[m_frameCount];


    protected:
        HWND                                m_hwnd;
        UINT                                m_width;
        UINT                                m_height;

        ComPtr<IDXGISwapChain3>             m_swapChain;

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
