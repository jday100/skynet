#ifndef T100WINDOWBASE_H
#define T100WINDOWBASE_H

#include "gui/event/T100EventHandler.h"

class T100WindowBase : public T100EventHandler
{
    public:
        T100WindowBase();
        virtual ~T100WindowBase();

        T100VOID                SetLabel(T100WSTRING);
        T100WSTRING             GetLabel();

        HWND                    GetHWND();

        T100UINT                GetWidth();
        T100UINT                GetHeight();

    protected:
        T100WSTRING             m_label;
        HWND                    m_hwnd;
        T100UINT                m_width         = 0;
        T100UINT                m_height        = 0;

        HWND                    Create(HWND, T100WSTRING, T100LONG, T100LONG);

    private:
};

#endif // T100WINDOWBASE_H
