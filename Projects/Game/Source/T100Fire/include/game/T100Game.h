#ifndef T100GAME_H
#define T100GAME_H

#include <windows.h>
#include "T100Common.h"

class T100Game
{
    public:
        T100Game();
        virtual ~T100Game();

        virtual T100VOID            Create(HWND, UINT, UINT);
        virtual T100VOID            Destroy();

        virtual T100VOID            Init();
        virtual T100VOID            Update();
        virtual T100VOID            Render();

        virtual T100VOID            SetSize(UINT, UINT);

        virtual T100VOID            OnKeyDown(UINT8);
        virtual T100VOID            OnKeyUp(UINT8);



    protected:

    private:
};

#endif // T100GAME_H
