#ifndef T100SETUPCOMPILERDIALOG_H
#define T100SETUPCOMPILERDIALOG_H

#include <wx/dialog.h>
#include "T100Common.h"

class T100SetupCompilerDialog : public wxDialog
{
    public:
        T100SetupCompilerDialog(wxWindow *parent, wxWindowID id,
             const wxString& title,
             const wxPoint& pos = wxDefaultPosition,
             const wxSize& size = wxDefaultSize,
             long style = wxDEFAULT_DIALOG_STYLE,
             const wxString& name = wxDialogNameStr);
        virtual ~T100SetupCompilerDialog();

    protected:

    private:
};

#endif // T100SETUPCOMPILERDIALOG_H
