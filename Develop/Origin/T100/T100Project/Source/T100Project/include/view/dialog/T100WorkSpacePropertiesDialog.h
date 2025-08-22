#ifndef T100WORKSPACEPROPERTIESDIALOG_H
#define T100WORKSPACEPROPERTIESDIALOG_H

#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/filepicker.h>
#include <wx/dialog.h>
#include "T100Common.h"

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
        static const long ID_STATIC_TEXT;
        static const long ID_PYTHON_DIR;

    protected:
        wxStaticText*       m_title;
        wxDirPickerCtrl*    m_dir;

    private:
        T100VOID            init();
        T100VOID            uninit();
};

#endif // T100WORKSPACEPROPERTIESDIALOG_H
