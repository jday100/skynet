#ifndef T100PANEL_H
#define T100PANEL_H

#include "gui/window/T100Window.h"
#include "gui/T100PanelStyle.h"

class T100Win32Application;

class T100Panel : public T100Window
{
    public:
        T100Panel();
        T100Panel(T100Win32Application*, T100Window*);
        virtual ~T100Panel();

    protected:

    private:
};

#endif // T100PANEL_H
