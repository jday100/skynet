#ifndef T100GAME_H
#define T100GAME_H

#include "T100DX12.h"

class T100Game
{
    public:
        T100Game();
        virtual ~T100Game();

        virtual T100BOOL            Create(HWND, UINT, UINT);
        virtual T100BOOL            Start();
        virtual T100BOOL            Render();

        virtual T100VOID            OnKeyDown(UINT8 key);
        virtual T100VOID            OnKeyUp(UINT8 key);

    protected:
        T100DX12*                   m_dx12          = T100NULL;


    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100GAME_H
