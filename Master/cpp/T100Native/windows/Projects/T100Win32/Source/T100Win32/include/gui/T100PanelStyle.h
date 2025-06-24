#ifndef T100PANELSTYLE_H
#define T100PANELSTYLE_H

#include "gui/style/T100WindowStyle.h"

namespace T100WINDOWS{

class T100DockPanelStyle;

class T100PanelStyle : public T100WindowStyle
{
    public:
        T100PanelStyle();
        T100PanelStyle(const T100DockPanelStyle&);
        virtual ~T100PanelStyle();

    protected:

    private:
};

}

#endif // T100PANELSTYLE_H
