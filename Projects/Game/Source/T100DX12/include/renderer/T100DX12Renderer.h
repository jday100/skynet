#ifndef T100DX12RENDERER_H
#define T100DX12RENDERER_H

#include <windows.h>

#include <d3d12.h>

#include "T100Common.h"

class T100DX12Renderer
{
    public:
        T100DX12Renderer(HWND hwnd);
        virtual ~T100DX12Renderer();

        virtual T100BOOL            create();
        virtual T100BOOL            destroy();

        virtual T100BOOL            load();
        virtual T100BOOL            release();

        virtual T100BOOL            render();

    protected:
        HWND                        m_hwnd;

    private:
        virtual T100VOID            init();
        virtual T100VOID            uninit();
};

#endif // T100DX12RENDERER_H
