#ifndef T100GAME_H
#define T100GAME_H

#include "T100Frame.h"

class T100Game : public T100Frame
{
    public:
        T100Game(HINSTANCE, HINSTANCE, LPSTR, int);
        virtual ~T100Game();

        virtual T100VOID            Create(LPSTR, LPSTR);

    protected:
        static LRESULT CALLBACK     GameWindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

    private:
};

#endif // T100GAME_H
