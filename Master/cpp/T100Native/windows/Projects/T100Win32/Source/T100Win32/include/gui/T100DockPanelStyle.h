#ifndef T100DOCKPANELSTYLE_H
#define T100DOCKPANELSTYLE_H

#include "gui/T100AllStyles.h"

namespace T100WINDOWS{

class T100DockPanelStyle : public T100WindowStyle
{
    public:
        T100DockPanelStyle();
        virtual ~T100DockPanelStyle();

        T100PanelStyle          ToPanelStyle();
        T100CanvasStyle         ToCanvasStyle();

    protected:

    private:
};

}

#endif // T100DOCKPANELSTYLE_H
