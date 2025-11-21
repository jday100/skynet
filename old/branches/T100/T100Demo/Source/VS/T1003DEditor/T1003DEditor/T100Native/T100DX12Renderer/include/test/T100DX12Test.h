#ifndef T100DX12TEST_H
#define T100DX12TEST_H

#include "T100Common.h"
#include "T100DX12Renderer.h"

class T100DX12Test
{
    public:
        T100DX12Test();
        virtual ~T100DX12Test();

        T100VOID                Create(T1003DWindowHandle, T100UINT, T100UINT);
        T100VOID                Start();
        T100VOID                Stop();

        T100VOID                Update();
        T100VOID                Render();

    protected:
        T100DX12Renderer        m_renderer;

        T100VOID                init();

        T100VOID                City();

    private:
};

#endif // T100DX12TEST_H
