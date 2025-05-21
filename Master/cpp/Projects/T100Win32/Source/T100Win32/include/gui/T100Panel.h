#ifndef T100PANEL_H
#define T100PANEL_H

#include "T100Window.h"
#include "gui/T100AllStyles.h"

class T100Panel : public T100Window
{
    public:
        T100Panel();
        T100Panel(T100Win32Application*, T100Window*);
        virtual ~T100Panel();

        T100VOID            Create(T100WSTRING = L"", T100PanelStyle* = T100NULL);
        T100VOID            Create(T100Win32Application*, T100Window*, T100WSTRING = L"", T100PanelStyle* = T100NULL);

    protected:
        T100VOID            OnPanelResize(T100WindowEvent&);

    private:
};

#endif // T100PANEL_H
