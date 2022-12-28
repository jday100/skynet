#ifndef T100MDIPAINTVIEW_H
#define T100MDIPAINTVIEW_H

#include "T100MDIViewBase.h"
#include "T100MDIPaintFrame.h"
#include "T100Painter.h"

namespace T100IDE{

class T100MDIPaintView : public T100MDIViewBase
{
    public:
        T100MDIPaintView();
        virtual ~T100MDIPaintView();

        T100Painter::T100Painter*       GetPainter() const;

        T100BOOL                        OnCreate(wxDocument* doc, long flags);
        T100VOID                        OnDraw(wxDC* dc);
        T100BOOL                        OnClose(T100BOOL deleteWindow = T100TRUE);

    protected:
        T100VOID                        create();
        T100VOID                        destroy();

        T100MDIPaintFrame*              m_frame             = T100NULL;
        T100Painter::T100Painter*       m_painter           = T100NULL;

    private:
        DECLARE_EVENT_TABLE()
        DECLARE_DYNAMIC_CLASS(T100MDIPaintView)
};

}

#endif // T100MDIPAINTVIEW_H
