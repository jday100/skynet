#ifndef T100WPAINTERVIEW_H
#define T100WPAINTERVIEW_H

#include "T100Common.h"
#include "T100WPainterMain.h"
#include "T100WPainterCanvas.h"
#include "T100WPainterElementsPanel.h"

class T100WPainterView
{
    public:
        T100WPainterView();
        virtual ~T100WPainterView();

        T100BOOL                            Open();
        T100BOOL                            SaveAs(T100STRING&);

        T100BOOL                            show();

        T100WPainterFrame*                  getFrame();
        T100WPainterCanvas*                 getCanvas();

    protected:
        T100VOID                            create();
        T100VOID                            destroy();

    private:
        T100WPainterFrame*                  m_frame                     = T100NULL;
        T100WPainterElementsPanel*          m_elements_panel            = T100NULL;
};

#endif // T100WPAINTERVIEW_H
