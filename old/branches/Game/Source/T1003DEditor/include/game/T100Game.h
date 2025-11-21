#ifndef T100GAME_H
#define T100GAME_H

#include "input/T100DX12Input.h"
#include "motion/T100DX12Motion.h"
#include "renderer/T100DX12Renderer.h"

class T100Game
{
    public:
        T100Game();
        virtual ~T100Game();

        virtual T100VOID                    Create(HWND, UINT, UINT);
        virtual T100VOID                    Destroy();

        virtual T100VOID                    SetSize(UINT, UINT);

        virtual T100VOID                    Start();
        virtual T100VOID                    Stop();

        virtual T100VOID                    Update();
        virtual T100VOID                    Render();

        virtual T100VOID                    SetScene(T100DX12Scene*);
        virtual T100DX12Scene*              GetScene();

        virtual T100VOID                    SetInputPtr(T100DX12Input*);
        virtual T100DX12Input*              GetInputPtr();

        virtual T100DX12Renderer*           GetRenderer();

        virtual T100VOID                    Move();

    protected:
        T100DX12Renderer                    m_renderer;
        T100DX12Input*                      m_inputPtr          = T100NULL;
        T100DX12Motion*                     m_motionPtr         = T100NULL;

    private:
};

#endif // T100GAME_H
