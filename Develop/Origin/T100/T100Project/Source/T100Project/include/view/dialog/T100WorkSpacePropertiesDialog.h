#ifndef T100WORKSPACEPROPERTIESDIALOG_H
#define T100WORKSPACEPROPERTIESDIALOG_H

#include <wx/dialog.h>

class T100WorkSpacePropertiesDialog : public wxDialog
{
    public:
        T100WorkSpacePropertiesDialog(wxWindow *parent, wxWindowID id,
             const wxString& title,
             const wxPoint& pos = wxDefaultPosition,
             const wxSize& size = wxDefaultSize,
             long style = wxDEFAULT_DIALOG_STYLE,
             const wxString& name = wxDialogNameStr);
        virtual ~T100WorkSpacePropertiesDialog();

    protected:

    private:
};

#endif // T100WORKSPACEPROPERTIESDIALOG_H
