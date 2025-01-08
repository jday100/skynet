#ifndef T100DX12RENDERER_H
#define T100DX12RENDERER_H

#include "windows/dx12/T100DX12.h"
#include "graph/render/T100Renderer.h"

class T100DX12Renderer : public T100Renderer
{
    public:
        T100DX12Renderer();
        virtual ~T100DX12Renderer();

        T100BOOL            create(HWND);
        T100BOOL            destroy();

        T100BOOL            render();

    protected:
        T100DX12*           m_dx12          = T100NULL;

    private:
        T100VOID            init();
        T100VOID            uninit();

};

#endif // T100DX12RENDERER_H
