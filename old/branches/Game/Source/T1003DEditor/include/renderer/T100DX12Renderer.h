#ifndef T100DX12RENDERER_H
#define T100DX12RENDERER_H

#include "renderer/core/T100DX12Core.h"

class T100DX12Renderer
{
    friend class T100DX12Scene;
    public:
        T100DX12Renderer();
        virtual ~T100DX12Renderer();

        T100DX12Camera&             GetCamera();

        virtual T100VOID            Create(HWND, UINT, UINT);
        virtual T100VOID            Destroy();

        virtual T100VOID            SetSize(UINT, UINT);

        virtual T100VOID            Start();
        virtual T100VOID            Stop();

        virtual T100VOID            Update();
        virtual T100VOID            Render();

        virtual T100VOID            SetScene(T100DX12Scene*);
        virtual T100DX12Scene*      GetScene();

        virtual T100VOID            SetConfig(T100DX12Config*);
        virtual T100DX12Config*     GetConfig();

        virtual T100DX12Timer&      GetTimer();

    protected:
        T100DX12Core                m_dx12;

    private:
};

#endif // T100DX12RENDERER_H
