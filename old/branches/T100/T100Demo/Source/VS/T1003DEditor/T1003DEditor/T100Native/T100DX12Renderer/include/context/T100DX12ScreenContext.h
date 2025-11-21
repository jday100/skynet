#ifndef T100DX12SCREENCONTEXT_H
#define T100DX12SCREENCONTEXT_H

#include "data/T100DX12Context.h"

class T100DX12ScreenContext : public T100DX12Context
{
    public:
        T100DX12ScreenContext();
        virtual ~T100DX12ScreenContext();

        virtual T100VOID            Update();
        virtual T100VOID            Render();

    protected:
        T100VOID                    DoUpdate();
        T100VOID                    UpdateScreen();

        T100VOID                    DoRender();
        T100VOID                    RenderDot();
        T100VOID                    RenderLine();
        T100VOID                    RenderTriangle();
        T100VOID                    RenderPlane();

        T100VOID                    UpdateConstantBuffer();
        T100VOID                    UpdateConstantBuffers();

        T100VOID                    UpdateScreenConstantBuffer();

    private:
};

#endif // T100DX12SCREENCONTEXT_H
