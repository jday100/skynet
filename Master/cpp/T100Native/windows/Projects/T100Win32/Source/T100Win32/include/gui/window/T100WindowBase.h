#ifndef T100WINDOWBASE_H
#define T100WINDOWBASE_H

#include "handler/T100EventHandler.h"
#include "gui/window/T100WindowModule.h"

namespace T100WINDOWS{

class T100WindowBase : public T100EventHandler
{
    public:
        T100WindowBase();
        virtual ~T100WindowBase();

        HWND                        GetHWND();

        T100VOID                    Show();
        T100VOID                    Hide();

    protected:
        HWND                        m_hwnd;
        T100WindowStyle             m_style;

    private:
};

}

#endif // T100WINDOWBASE_H
