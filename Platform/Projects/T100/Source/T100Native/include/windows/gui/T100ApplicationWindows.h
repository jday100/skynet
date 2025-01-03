#ifndef T100APPLICATIONWINDOWS_H
#define T100APPLICATIONWINDOWS_H

#include <tchar.h>
#include <windows.h>
#include "T100Common.h"

class T100ApplicationWindows
{
    public:
        T100ApplicationWindows(HINSTANCE, HINSTANCE, LPSTR, int);
        virtual ~T100ApplicationWindows();

        T100VOID            Create();

        T100VOID            Show();

        int                 run();

        HWND                getHWND();

    protected:
        //TCHAR               m_name[]    = _T("CodeBlocksWindowsApp");
        HINSTANCE           m_hthis_instance;
        HINSTANCE           m_hprev_instance;
        LPSTR               m_lpsz_argument;
        int                 m_ncmd_show;

        HWND                m_hwnd;

        static LRESULT CALLBACK    WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

    private:
        T100VOID            init();
        T100VOID            uninit();

};

#endif // T100APPLICATIONWINDOWS_H
