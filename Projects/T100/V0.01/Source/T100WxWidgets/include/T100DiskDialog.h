#ifndef T100DISKDIALOG_H
#define T100DISKDIALOG_H

#include <wx/dialog.h>
#include "T100Common.h"


class T100DiskDialog : public wxDialog
{
    public:
        T100DiskDialog(wxWindow *parent, wxWindowID id,
             const wxString& title,
             const wxPoint& pos = wxDefaultPosition,
             const wxSize& size = wxDefaultSize,
             long style = wxDEFAULT_DIALOG_STYLE,
             const wxString& name = wxDialogNameStr);
        virtual ~T100DiskDialog();

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
};

#endif // T100DISKDIALOG_H
