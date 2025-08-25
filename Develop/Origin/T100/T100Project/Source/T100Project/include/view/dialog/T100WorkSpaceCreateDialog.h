#ifndef T100WORKSPACECREATEDIALOG_H
#define T100WORKSPACECREATEDIALOG_H

#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/filepicker.h>
#include <wx/dialog.h>
#include "T100Common.h"

class T100WorkSpaceCreateDialog : public wxDialog
{
    public:
        T100WorkSpaceCreateDialog(wxWindow *parent, wxWindowID id,
             const wxString& title,
             const wxPoint& pos = wxDefaultPosition,
             const wxSize& size = wxDefaultSize,
             long style = wxDEFAULT_DIALOG_STYLE,
             const wxString& name = wxDialogNameStr);
        virtual ~T100WorkSpaceCreateDialog();

    protected:
        static const long ID_STATIC_TEXT;
        static const long ID_WORKSPACE_DIR;

    protected:
        wxStaticText*       m_title;
        wxDirPickerCtrl*    m_dir;

    private:
        T100VOID            init();
        T100VOID            uninit();
};

#endif // T100WORKSPACECREATEDIALOG_H
