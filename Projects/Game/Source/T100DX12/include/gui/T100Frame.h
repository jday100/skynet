#ifndef T100FRAME_H
#define T100FRAME_H

#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <windows.h>
#include "T100Common.h"
class T100Game;

class T100Frame
{
    public:
        T100Frame();
        virtual ~T100Frame();

        static int                  Run(T100Game* game, HINSTANCE hInstance, int nCmdShow);
        static HWND                 GetHwnd();

    protected:
        static LRESULT CALLBACK     WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

    private:
        static HWND                 m_hwnd;
};

#endif // T100FRAME_H
