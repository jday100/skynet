#ifndef T100PROJECTVIEWSETUPCOMPILERDIALOG_H
#define T100PROJECTVIEWSETUPCOMPILERDIALOG_H

#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/filepicker.h>
#include <wx/dialog.h>
#include "T100Common.h"

class T100ProjectViewSetupCompilerDialog : public wxDialog
{
    public:
        T100ProjectViewSetupCompilerDialog(wxWindow *parent, wxWindowID id,
             const wxString& title,
             const wxPoint& pos = wxDefaultPosition,
             const wxSize& size = wxDefaultSize,
             long style = wxDEFAULT_DIALOG_STYLE,
             const wxString& name = wxDialogNameStr);
        virtual ~T100ProjectViewSetupCompilerDialog();

    protected:
        static const long ID_COMPILER_PATH_STATIC_TEXT;
        static const long ID_COMPILER_PATH_FOLDER_PICKER;

    protected:
        wxStaticText*           m_compilerPathStaticText;
        wxDirPickerCtrl*        m_compilerPathFolderPicker;

        T100VOID                OnApply(wxCommandEvent&);

    private:
        T100VOID                init();
        T100VOID                uninit();

        DECLARE_EVENT_TABLE()
};

#endif // T100PROJECTVIEWSETUPCOMPILERDIALOG_H
