#ifndef T100PROJECTVIEWABOUTDIALOG_H
#define T100PROJECTVIEWABOUTDIALOG_H

#include <wx/dialog.h>

class T100ProjectViewAboutDialog : public wxDialog
{
    public:
        T100ProjectViewAboutDialog(wxWindow *parent, wxWindowID id,
             const wxString& title,
             const wxPoint& pos = wxDefaultPosition,
             const wxSize& size = wxDefaultSize,
             long style = wxDEFAULT_DIALOG_STYLE,
             const wxString& name = wxDialogNameStr);
        virtual ~T100ProjectViewAboutDialog();

    protected:

    private:
};

#endif // T100PROJECTVIEWABOUTDIALOG_H
