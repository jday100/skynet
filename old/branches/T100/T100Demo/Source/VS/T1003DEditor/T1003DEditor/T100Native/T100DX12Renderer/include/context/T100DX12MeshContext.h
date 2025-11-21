#ifndef T100DX12MESHCONTEXT_H
#define T100DX12MESHCONTEXT_H

#include "data/T100DX12Context.h"

class T100DX12MeshContext : public T100DX12Context
{
    public:
        T100DX12MeshContext();
        virtual ~T100DX12MeshContext();

        virtual T100VOID            Update();
        virtual T100VOID            Render();

    protected:
        T100VOID                    DoUpdate();

        T100VOID                    RenderBundle();
        T100VOID                    RenderSingle();
        T100VOID                    RenderCity();

        T100VOID                    DoRender();
        T100VOID                    RenderDot();
        T100VOID                    RenderLine();
        T100VOID                    RenderTriangle();
        T100VOID                    RenderPlane();

        T100VOID                    UpdateConstantBuffer();
        T100VOID                    UpdateConstantBuffers();

    private:
};

#endif // T100DX12MESHCONTEXT_H
