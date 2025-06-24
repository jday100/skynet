#ifndef T100CANVASSTYLE_H
#define T100CANVASSTYLE_H

#include "gui/T100PanelStyle.h"

namespace T100WINDOWS{

class T100DockPanelStyle;

class T100CanvasStyle : public T100PanelStyle
{
    public:
        T100CanvasStyle();
        T100CanvasStyle(const T100DockPanelStyle&);
        virtual ~T100CanvasStyle();

    protected:

    private:
};

}

#endif // T100CANVASSTYLE_H
