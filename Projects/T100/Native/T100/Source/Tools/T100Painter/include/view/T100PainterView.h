#ifndef T100PAINTERVIEW_H
#define T100PAINTERVIEW_H

#include "T100Common.h"
#include "T100Canvas.h"
#include "T100PainterMain.h"
#include "T100PainterElementsPanel.h"
#include "T100PainterPropertiesPanel.h"

class T100PainterView
{
    public:
        T100PainterView();
        virtual ~T100PainterView();

        T100BOOL                        Open(T100STRING&);
        T100BOOL                        SaveAs(T100STRING&);

        T100BOOL                        show();

        T100Canvas*                     getCanvas();
        T100PainterFrame*               getFrame();
        T100PainterElementsPanel*       getElementsPanel();
        T100PainterPropertiesPanel*     getPropertiesPanel();

    protected:
        T100VOID                        create();
        T100VOID                        destroy();

    private:
        T100Canvas*                     m_canvas                = T100NULL;
        T100PainterFrame*               m_frame                 = T100NULL;
        T100PainterElementsPanel*       m_elements_panel        = T100NULL;
        T100PainterPropertiesPanel*     m_properties_panel      = T100NULL;
};

#endif // T100PAINTERVIEW_H
