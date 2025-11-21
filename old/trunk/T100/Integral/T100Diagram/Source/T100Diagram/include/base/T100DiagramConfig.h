#ifndef T100DIAGRAMCONFIG_H
#define T100DIAGRAMCONFIG_H

#include "T100Common.h"

class T100DiagramConfig
{
    public:
        T100DiagramConfig();
        virtual ~T100DiagramConfig();

        static T100UINT             T100DIAGRAM_CANVAS_SCROLL_PIXELS_PER_UNIT_X;
        static T100UINT             T100DIAGRAM_CANVAS_SCROLL_PIXELS_PER_UNIT_Y;

    protected:

    private:
};

#endif // T100DIAGRAMCONFIG_H
