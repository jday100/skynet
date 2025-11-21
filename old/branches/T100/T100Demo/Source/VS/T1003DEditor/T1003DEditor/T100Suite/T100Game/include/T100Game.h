#ifndef T100GAME_H
#define T100GAME_H

#include "T100DX12Renderer.h"
#include "data/T100GameScene.h"
#include "T100GameInput.h"
#include "T100GameMotion.h"

class T100Game
{
    public:
        T100Game();
        virtual ~T100Game();

        T1003DRenderer*             GetRenderer();

        T100VOID                    SetScenePtr(T100GameScene*);
        T100GameScene*              GetScenePtr();

        virtual T100VOID            Create(T1003DWindowHandle, T100UINT, T100UINT);
        virtual T100VOID            Destroy();

        virtual T100VOID            SetSize(T100UINT, T100UINT);

        virtual T100VOID            Start();
        virtual T100VOID            Stop();

        virtual T100VOID            Update();
        virtual T100VOID            Render();

        virtual T100VOID            SetConfigPtr(T1003DConfig*);
        virtual T1003DConfig*       GetConfigPtr();

        virtual T100VOID            Append(T1003DMesh*);
        virtual T100VOID            Remove(T1003DMesh*);

        virtual T1003DTimer&        GetTimer();
        virtual T100GameInput&      GetInput();

        virtual T100VOID            SetCameraPtr(T1003DCamera*);
        virtual T1003DCamera*       GetCameraPtr();

    protected:
        T100DX12Renderer*           m_dx12Ptr           = T100NULL;
        T100GameScene*              m_scenePtr          = T100NULL;
        T100GameInput               m_input;
        T100GameMotion              m_motion;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100GAME_H
