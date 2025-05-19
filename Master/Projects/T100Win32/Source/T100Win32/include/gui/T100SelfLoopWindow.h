#ifndef T100SELFLOOPWINDOW_H
#define T100SELFLOOPWINDOW_H

#include "T100Window.h"

LRESULT CALLBACK DefaultSelfLoopWindowProcedure (HWND, UINT, WPARAM, LPARAM);

class T100SelfLoopWindow : public T100Window
{
    public:
        T100SelfLoopWindow();
        T100SelfLoopWindow(T100Win32Application*, T100Window*);
        virtual ~T100SelfLoopWindow();

        T100VOID            Create();
        T100VOID            Create(T100Win32Application*, T100SelfLoopWindow*);

    protected:
        T100BOOL            RegisterSelfLoopWindowClass(T100Win32Application*, T100WSTRING);

    private:
};

#endif // T100SELFLOOPWINDOW_H
