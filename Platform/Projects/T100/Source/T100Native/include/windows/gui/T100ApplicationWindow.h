#ifndef T100APPLICATIONWINDOW_H
#define T100APPLICATIONWINDOW_H

#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif


#include <tchar.h>
#include <windows.h>
#include "T100Common.h"

LRESULT CALLBACK            DefaultWindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

class T100ApplicationWindow
{
    public:
        T100ApplicationWindow(HINSTANCE, HINSTANCE, LPSTR, int);
        virtual ~T100ApplicationWindow();

        T100VOID            Create(LPCWSTR name, LPCWSTR title, WNDPROC wndproc = DefaultWindowProcedure, LPVOID lpParam = NULL);
        T100VOID            Destroy();

        int                 Run();

        WINBOOL             Show();
        HWND                GetHWND();

    protected:
        HINSTANCE           m_hthis_instance;
        HINSTANCE           m_hprev_instance;
        LPSTR               m_lpsz_argument;
        int                 m_ncmd_show;

        HWND                m_hwnd;

    private:

};

#endif // T100APPLICATIONWINDOW_H
