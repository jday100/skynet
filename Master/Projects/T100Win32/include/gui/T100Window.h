#ifndef T100WINDOW_H
#define T100WINDOW_H

#include <windows.h>
#include "T100EventHandler.h"

LRESULT CALLBACK T100DefaultWindowProcedure (HWND, UINT, WPARAM, LPARAM);

class T100Window : public T100EventHandler
{
    public:
        T100Window();
        virtual ~T100Window();

        T100VOID            Create(T100Window*, T100WSTRING, T100UINT, T100UINT);
        T100VOID            Destroy();

        HWND                GetHWND();

        T100VOID            Show();
        T100VOID            Hide();

        T100INT             Run();

    protected:
        HWND                m_hwnd;
        T100UINT            m_width;
        T100UINT            m_height;

    private:
};

#endif // T100WINDOW_H
