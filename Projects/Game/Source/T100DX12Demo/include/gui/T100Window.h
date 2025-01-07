#ifndef T100WINDOW_H
#define T100WINDOW_H

#include <tchar.h>
#include <windows.h>
#include "T100Common.h"

class T100Window
{
    public:
        T100Window(HINSTANCE, LPSTR, int, WNDPROC winproc = T100Window::DefaultWindowProcedure);
        virtual ~T100Window();

        T100VOID            Create(LPSTR);
        T100VOID            Destroy();

        T100BOOL            Show();

        T100INT             Run();

        HWND                GetHWND();

    protected:
        HINSTANCE           m_this_instance;
        LPSTR               m_name;
        LPSTR               m_title;
        int                 m_cmd_show;

        HWND                m_hwnd;
        WNDCLASSEX          m_wincl;
        WNDPROC             m_winproc;
        MSG                 m_message;

        static LRESULT CALLBACK     DefaultWindowProcedure(HWND, UINT, WPARAM, LPARAM);

    private:
        T100VOID            init();
        T100VOID            uninit();

};

#endif // T100WINDOW_H
