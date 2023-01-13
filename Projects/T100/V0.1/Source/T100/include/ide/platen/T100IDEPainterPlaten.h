#ifndef T100IDEPAINTERPLATEN_H
#define T100IDEPAINTERPLATEN_H

#include <wx/menu.h>
#include "T100IDEPlatenBase.h"
#include "T100Painter.h"
#include "T100PainterElementsPanel.h"
#include "T100PainterPropertiesPanel.h"


namespace T100IDE{

class T100IDEPainterPlaten : public T100IDEPlatenBase
{
    public:
        T100IDEPainterPlaten(T100IDEView*);
        virtual ~T100IDEPainterPlaten();

        T100BOOL            create();

        T100BOOL            show();
        T100BOOL            hide();

        T100VOID            setPainter(T100Painter::T100Painter*);

        T100Painter::T100PainterElementsPanel*          getElementsPanel();
        T100Painter::T100PainterPropertiesPanel*        getPropertiesPanel();

    protected:
        T100VOID            destroy();

        T100VOID            set_menu();

    private:
        T100Painter::T100Painter*                       m_painter               = T100NULL;
        T100Painter::T100PainterElementsPanel*          m_elements_panel        = T100NULL;
        T100Painter::T100PainterPropertiesPanel*        m_properties_panel      = T100NULL;

};

}

#endif // T100IDEPAINTERPLATEN_H
