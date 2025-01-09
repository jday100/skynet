#ifndef T100GAME_H
#define T100GAME_H

#include "T100Common.h"
#include "T100DX12.h"
#include "T100Scene.h"

class T100Game
{
    public:
        T100Game();
        virtual ~T100Game();

        virtual T100VOID            Create(HWND, UINT, UINT);
        virtual T100VOID            Destroy();

        virtual T100VOID            Load();
        virtual T100VOID            Release();

        virtual T100VOID            Render();

        virtual T100VOID            SetSize(UINT, UINT);

        virtual T100VOID            OnKeyDown(UINT8);
        virtual T100VOID            OnKeyUp(UINT8);

        T100VOID                    SetScene(T100Scene*);
        T100Scene*                  GetScene();

    protected:
        T100DX12*                   m_dx12          = T100NULL;

    private:
        T100Scene*                  m_scene         = T100NULL;
};

#endif // T100GAME_H
