#ifndef T100PROJECTTEXTVIEW_H
#define T100PROJECTTEXTVIEW_H

#include "T100ProjectMDIView.h"

class T100ProjectTextView : public T100ProjectMDIView
{
    public:
        T100ProjectTextView();
        virtual ~T100ProjectTextView();

        T100BOOL                    OnCreate(wxDocument* doc, long flags);
        T100VOID                    OnDraw(wxDC* dc);
        T100BOOL                    OnClose(T100BOOL deleteWindow = T100TRUE);

    protected:
        T100VOID                    create();
        T100VOID                    destroy();

    private:
        DECLARE_EVENT_TABLE()
        DECLARE_DYNAMIC_CLASS(T100ProjectMDIView)
};

#endif // T100PROJECTTEXTVIEW_H
