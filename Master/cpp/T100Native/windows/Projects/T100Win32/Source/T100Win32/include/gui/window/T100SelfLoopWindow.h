#ifndef T100SELFLOOPWINDOW_H
#define T100SELFLOOPWINDOW_H

#include "gui/T100Window.h"

namespace T100WINDOWS{

LRESULT CALLBACK DefaultSelfLoopWindowProcedure (HWND, UINT, WPARAM, LPARAM);

class T100SelfLoopWindow : public T100Window
{
    public:
        T100SelfLoopWindow();
        virtual ~T100SelfLoopWindow();

        virtual T100VOID            Create(T100Win32Application*, T100WindowStyle* = T100NULL);
        virtual T100VOID            Destroy();

    protected:

    private:
};

}

#endif // T100SELFLOOPWINDOW_H
