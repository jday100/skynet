#ifndef T100DX12RENDERER_H
#define T100DX12RENDERER_H

#include "T100Renderer.h"

class T100DX12Renderer : public T100Renderer
{
    public:
        T100DX12Renderer();
        virtual ~T100DX12Renderer();

        T100VOID    Start();
        T100VOID    Stop();

    protected:

    private:
};

#endif // T100DX12RENDERER_H
