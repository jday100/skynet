#ifndef T1003DEDITORCONFIGDIALOG_H
#define T1003DEDITORCONFIGDIALOG_H

#include <wx/dialog.h>
#include "T100Common.h"

class T1003DEditorConfigDialog : public wxDialog
{
    public:
        T1003DEditorConfigDialog(wxWindow *parent,
             wxWindowID id,
             const wxString& title,
             const wxPoint& pos = wxDefaultPosition,
             const wxSize& size = wxDefaultSize,
             long style = wxDEFAULT_DIALOG_STYLE,
             const wxString& name = wxDialogNameStr);
        virtual ~T1003DEditorConfigDialog();

    protected:

    private:
        T100VOID            init();
        T100VOID            uninit();

        DECLARE_EVENT_TABLE()
};

#endif // T1003DEDITORCONFIGDIALOG_H
