#ifndef T100WINDOWBASE_H
#define T100WINDOWBASE_H

#include "gui/T100Size.h"
#include "gui/T100Point.h"
#include "gui/event/T100EventHandler.h"
#include "gui/window/T100WindowStyle.h"

class T100Layout;
class T100Win32Application;

typedef     LRESULT CALLBACK (*T100WINDOW_PROCEDURE) (HWND, UINT, WPARAM, LPARAM);

class T100WindowBase : public T100EventHandler
{
    public:
        T100WindowBase();
        T100WindowBase(T100WindowBase*);
        virtual ~T100WindowBase();

        HWND                GetHWND();

        T100VOID            SetLabel(T100WSTRING);
        T100WSTRING         GetLabel();

        T100VOID            SetWidth(T100INT);
        T100INT             GetWidth();
        T100VOID            SetHeight(T100INT);
        T100INT             GetHeight();

        T100VOID            SetSize(T100Size);
        T100VOID            SetSize(T100INT, T100INT);
        T100Size            GetSize();

        T100VOID            SetPosition(T100Point);
        T100Point           GetPosition();

        T100VOID            Show();
        T100VOID            Hide();

    protected:
        T100BOOL            RegisterWindowClass(T100WindowStyle*, WNDPROC = DefWindowProc);

    protected:
        HWND                m_hwnd;
        T100WindowStyle     m_style;

        HWND                CreateWindowInstance(HWND, T100WindowStyle*, T100VOID* = T100NULL);

    private:
};

#endif // T100WINDOWBASE_H
