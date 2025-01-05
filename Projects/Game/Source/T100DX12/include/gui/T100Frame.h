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

LRESULT CALLBACK            DefaultWindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

class T100Frame
{
    public:
        T100Frame(HINSTANCE, HINSTANCE, LPSTR, int);
        virtual ~T100Frame();

        T100VOID            Create(LPSTR name, LPSTR title, WNDPROC wndproc = DefaultWindowProcedure);
        T100VOID            Destroy();

        int                 Run();

        T100BOOL            Show();
        HWND                GetHWND();

    protected:
        HINSTANCE           m_hthis_instance;
        HINSTANCE           m_hprev_instance;
        LPSTR               m_lpsz_argument;
        int                 m_ncmd_show;

        LPSTR               m_name;
        HWND                m_hwnd;
        WNDCLASSEX          m_wincl;

    private:
};

#endif // T100FRAME_H
