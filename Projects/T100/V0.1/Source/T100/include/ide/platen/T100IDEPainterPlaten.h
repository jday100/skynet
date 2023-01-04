#ifndef T100IDEPAINTERPLATEN_H
#define T100IDEPAINTERPLATEN_H

#include <wx/menu.h>
#include "T100IDEPlatenBase.h"
#include "T100Painter.h"
#include "T100PainterElementsPanel.h"

namespace T100IDE{

class T100IDEPainterPlaten : public T100IDEPlatenBase
{
    public:
        T100IDEPainterPlaten(T100IDEView*, void*);
        virtual ~T100IDEPainterPlaten();

        T100BOOL            create();

        T100BOOL            show();

        T100Painter::T100PainterElementsPanel*      getElementsPanel();

    protected:
        T100VOID            destroy();

    private:
        void*               m_data          = T100NULL;

        T100Painter::T100Painter*           m_painter           = T100NULL;
        T100Painter::T100PainterElementsPanel*          m_panel             = T100NULL;
};

}

#endif // T100IDEPAINTERPLATEN_H
