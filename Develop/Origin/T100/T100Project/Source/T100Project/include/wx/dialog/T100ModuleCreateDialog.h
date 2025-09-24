#ifndef T100MODULECREATEDIALOG_H
#define T100MODULECREATEDIALOG_H

#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/dialog.h>
#include "T100Common.h"
#include "T100ModuleInfo.h"

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

        T100ModuleInfo*             GetModuleInfo();

    protected:
        static const long ID_MODULE_NAME_TITLE;
        static const long ID_MODULE_NAME_VALUE;

        wxStaticText*               m_nameTitle;
        wxTextCtrl*                 m_nameValue;

        T100VOID                    OnApply(wxCommandEvent&);

    private:
        T100ModuleInfo              m_info;

        T100VOID                    init();
        T100VOID                    uninit();

        DECLARE_EVENT_TABLE()
};

#endif // T100MODULECREATEDIALOG_H
