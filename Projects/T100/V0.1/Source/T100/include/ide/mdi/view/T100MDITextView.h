#ifndef T100MDITEXTVIEW_H
#define T100MDITEXTVIEW_H

#include "T100MDIViewBase.h"
#include "T100MDITextFrame.h"
#include "T100Editor.h"


namespace T100IDE{

class T100MDITextView : public T100MDIViewBase
{
    public:
        T100MDITextView();
        virtual ~T100MDITextView();

        T100Editor::T100Editor*     GetEditor() const;

        T100BOOL                    OnCreate(wxDocument* doc, long flags);
        T100VOID                    OnDraw(wxDC* dc);
        T100BOOL                    OnClose(T100BOOL deleteWindow = T100TRUE);

    protected:
        T100VOID                    create();
        T100VOID                    destroy();

        T100MDITextFrame*           m_frame         = T100NULL;
        T100Editor::T100Editor*     m_editor        = T100NULL;

    private:
        DECLARE_EVENT_TABLE()
        DECLARE_DYNAMIC_CLASS(T100MDITextView)
};

}

#endif // T100MDITEXTVIEW_H
