#ifndef T100RENDERER_H
#define T100RENDERER_H

#include "T100Common.h"
#include "windows/dx12/T100DX12.h"

class T100Renderer
{
    public:
        T100Renderer();
        virtual ~T100Renderer();

        T100BOOL            run();

    protected:
        //T100DX12            m_dx12;

    private:
};

#endif // T100RENDERER_H
