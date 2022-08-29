#ifndef T100IDETEXTVIEW_H
#define T100IDETEXTVIEW_H

#include <wx/docmdi.h>
#include "T100Common.h"
#include "T100EditCtrl.h"


class T100IDETextView : public wxView
{
    public:
        T100IDETextView();
        virtual ~T100IDETextView();

        T100EditCtrl*           GetEdit() const;

        T100BOOL                OnCreate(wxDocument* doc, long flags);
        T100VOID                OnDraw(wxDC* dc);
        T100BOOL                OnClose(T100BOOL deleteWindow = T100TRUE);

    protected:
        T100EditCtrl*           m_editor        = T100NULL;

        T100VOID                CreateMenu(wxFrame*);

    private:
        wxDECLARE_EVENT_TABLE();
        wxDECLARE_DYNAMIC_CLASS(T103TextView);
};

#endif // T100IDETEXTVIEW_H
