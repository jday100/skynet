#ifndef T100SELFLOOPWINDOW_H
#define T100SELFLOOPWINDOW_H

#include "gui/window/T100Window.h"

LRESULT CALLBACK DefaultSelfLoopWindowProcedure (HWND, UINT, WPARAM, LPARAM);

class T100SelfLoopWindow : public T100Window
{
    public:
        T100SelfLoopWindow();
        T100SelfLoopWindow(T100ApplicationEventHandler*, T100Window*);
        virtual ~T100SelfLoopWindow();

        T100VOID                    Create(T100ApplicationEventHandler*, T100Window*);

    protected:

    private:
};

#endif // T100SELFLOOPWINDOW_H
