#ifndef T100SELFLOOPWINDOW_H
#define T100SELFLOOPWINDOW_H

#include "gui/T100Window.h"

namespace T100WINDOWS{

LRESULT CALLBACK DefaultSelfLoopWindowProcedure (HWND, UINT, WPARAM, LPARAM);

class T100SelfLoopWindow : public T100Window
{
    public:
        T100SelfLoopWindow();
        T100SelfLoopWindow(T100Win32Application*);
        virtual ~T100SelfLoopWindow();

        virtual T100VOID            Create(T100Win32Application*, T100WindowStyle* = T100NULL);
        virtual T100VOID            Destroy();

        T100VOID                    Maximize();
        T100VOID                    Minimize();

    protected:

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

}

#endif // T100SELFLOOPWINDOW_H
