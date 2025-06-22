#ifndef T100WINDOWBASE_H
#define T100WINDOWBASE_H

#include "base/T100Size.h"
#include "base/T100Point.h"
#include "gui/handler/T100EventHandler.h"
#include "gui/window/T100WindowModule.h"

namespace T100WINDOWS{

class T100WindowBase : public T100EventHandler
{
    public:
        T100WindowBase();
        virtual ~T100WindowBase();

        HWND                        GetHWND();

        T100VOID                    SetWidth(T100INT);
        T100INT                     GetWidth();
        T100VOID                    SetHeight(T100INT);
        T100INT                     GetHeight();

        T100VOID                    SetSize(const T100Size&);
        T100VOID                    SetSize(T100INT, T100INT);
        const T100Size&             GetSize();

        T100VOID                    SetClientSize(const T100Size&);
        T100VOID                    SetClientSize(T100INT, T100INT);
        const T100Size              GetClientSize();

        T100VOID                    SetPosition(const T100Point&);
        const T100Point&            GetPosition();

        T100VOID                    Enable();
        T100VOID                    Disable();
        T100BOOL                    IsEnabled();

        T100VOID                    Show();
        T100VOID                    Hide();
        T100BOOL                    IsShown();

        T100VOID                    SetStyle(const T100WindowStyle&);
        const T100WindowStyle&      GetStyle();

    protected:
        HWND                        m_hwnd;
        T100WindowStyle             m_style;

    private:
};

}

#endif // T100WINDOWBASE_H
