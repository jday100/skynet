#ifndef T100PANELFRAME_H
#define T100PANELFRAME_H

#include "gui/T100Frame.h"

class T100PanelFrame : public T100Frame
{
    public:
        T100PanelFrame();
        virtual ~T100PanelFrame();

        T100VOID            Create(T100Win32Application*);

    protected:

    private:
        T100VOID            init();
        T100VOID            uninit();
};

#endif // T100PANELFRAME_H
