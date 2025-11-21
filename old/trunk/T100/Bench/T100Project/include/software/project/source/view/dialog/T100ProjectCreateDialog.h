#ifndef T100PROJECTCREATEDIALOG_H
#define T100PROJECTCREATEDIALOG_H

#include <wx/dialog.h>
#include <wx/treebook.h>
#include "T100Common.h"

class T100ProjectCreateDialog : public wxDialog
{
    public:
        T100ProjectCreateDialog(wxWindow *parent, wxWindowID id,
             const wxString& title,
             const wxPoint& pos = wxDefaultPosition,
             const wxSize& size = wxDefaultSize,
             long style = wxDEFAULT_DIALOG_STYLE,
             const wxString& name = wxDialogNameStr);
        virtual ~T100ProjectCreateDialog();

    protected:
        T100VOID            On(wxCommandEvent&);
        T100VOID            OnSelected(wxTreebookEvent&);

    private:
        T100VOID            init();
        T100VOID            uninit();
};

#endif // T100PROJECTCREATEDIALOG_H
