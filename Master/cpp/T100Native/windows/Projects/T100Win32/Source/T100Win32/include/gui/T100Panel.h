#ifndef T100PANEL_H
#define T100PANEL_H

#include "gui/T100Window.h"
#include "gui/T100PanelStyle.h"

namespace T100WINDOWS{

class T100Panel : public T100Window
{
    public:
        T100Panel();
        T100Panel(T100Window*);
        virtual ~T100Panel();

        virtual T100VOID            Create(T100Window*, T100PanelStyle* = T100NULL);
        virtual T100VOID            Destroy();

    protected:

    private:
        T100VOID                    init(T100Window*);
        T100VOID                    uninit();
};

}

#endif // T100PANEL_H
