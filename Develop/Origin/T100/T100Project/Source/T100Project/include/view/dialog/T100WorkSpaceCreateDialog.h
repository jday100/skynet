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

        T100VOID                    SetWorkSpacePath(const T100WSTRING&);
        const T100WSTRING&          GetWorkSpacePath();

        T100VOID                    SetPythonFile(const T100WSTRING&);
        const T100WSTRING&          GetPythonFile();

    protected:
        static const long ID_WORKSPACE_STATIC_TEXT;
        static const long ID_WORKSPACE_PATH;
        static const long ID_PYTHON_STATIC_TEXT;
        static const long ID_PYTHON_FILE;

    protected:
        T100WSTRING                 m_workspacePath;
        T100WSTRING                 m_pythonFile;

        wxStaticText*               m_workspaceTitle;
        wxDirPickerCtrl*            m_workspacePathPicker;

        wxStaticText*               m_pythonTitle;
        wxFilePickerCtrl*           m_pythonFilePicker;

    private:
        T100VOID                    init();
        T100VOID                    uninit();

        DECLARE_EVENT_TABLE()
};

#endif // T100WORKSPACECREATEDIALOG_H
