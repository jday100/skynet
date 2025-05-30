#ifndef T100WINDOWBASE_H
#define T100WINDOWBASE_H

#include "gui/base/T100Size.h"
#include "gui/base/T100Point.h"
#include "gui/font/T100Font.h"
#include "gui/window/T100WindowStyle.h"
#include "gui/event/T100WindowEventHandler.h"

class T100WindowBase : public T100WindowEventHandler
{
    public:
        T100WindowBase();
        virtual ~T100WindowBase();

        HWND                        GetHWND();

        T100VOID                    SetLabel(T100WSTRING);
        T100WSTRING                 GetLabel();

        T100VOID                    SetFont(T100Font&);
        T100Font&                   GetFont();

        T100VOID                    SetWidth(T100INT);
        T100INT                     GetWidth();
        T100VOID                    SetHeight(T100INT);
        T100INT                     GetHeight();

        T100VOID                    SetSize(T100Size);
        T100VOID                    SetSize(T100INT, T100INT);
        T100Size                    GetSize();

        T100VOID                    SetClientSize(T100Size);
        T100VOID                    SetClientSize(T100INT, T100INT);
        T100Size                    GetClientSize();

        T100VOID                    SetPosition(T100Point);
        T100Point                   GetPosition();

        T100VOID                    Enable();
        T100VOID                    Disable();
        T100BOOL                    IsEnabled();

        T100VOID                    Show();
        T100VOID                    Hide();
        T100BOOL                    IsShown();

    protected:
        HWND                        m_hwnd;
        T100Font                    m_font;
        T100WindowStyle             m_style;

    private:
};

#endif // T100WINDOWBASE_H
