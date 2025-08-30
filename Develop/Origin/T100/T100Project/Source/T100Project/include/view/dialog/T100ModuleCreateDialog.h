#ifndef T100MODULECREATEDIALOG_H
#define T100MODULECREATEDIALOG_H

#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/dialog.h>
#include "T100Common.h"

class T100ModuleCreateDialog : public wxDialog
{
    public:
        T100ModuleCreateDialog(wxWindow *parent, wxWindowID id,
             const wxString& title,
             const wxPoint& pos = wxDefaultPosition,
             const wxSize& size = wxDefaultSize,
             long style = wxDEFAULT_DIALOG_STYLE,
             const wxString& name = wxDialogNameStr);
        virtual ~T100ModuleCreateDialog();

    protected:
        static const long ID_;

        wxStaticText*           m_;

        T100VOID                OnApply(wxCommandEvent&);

    private:
        T100VOID                init();
        T100VOID                uninit();

        DECLARE_EVENT_TABLE()
};

#endif // T100MODULECREATEDIALOG_H
