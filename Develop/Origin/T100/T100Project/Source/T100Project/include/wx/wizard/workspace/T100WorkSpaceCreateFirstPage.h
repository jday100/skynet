#ifndef T100WORKSPACECREATEFIRSTPAGE_H
#define T100WORKSPACECREATEFIRSTPAGE_H

#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/filepicker.h>
#include <wx/wizard.h>
#include "T100Common.h"

class T100WorkSpaceCreateFirstPage : public wxWizardPageSimple
{
    public:
        T100WorkSpaceCreateFirstPage(wxWizard *parent,
                       wxWizardPage *prev = NULL,
                       wxWizardPage *next = NULL,
                       const wxBitmap& bitmap = wxNullBitmap);
        virtual ~T100WorkSpaceCreateFirstPage();

        const T100WSTRING       GetPath();

        T100BOOL                TransferDataToWindow();
        T100BOOL                TransferDataFromWindow();

    protected:
        static const long ID_WORKSPACE_PATH_TITLE;
        static const long ID_WORKSPACE_PATH_PICKER;

    protected:
        wxStaticText*           m_workspaceTitle        = T100NULL;
        wxDirPickerCtrl*        m_workspacePath         = T100NULL;

    private:
        T100VOID                init();
        T100VOID                uninit();
};

#endif // T100WORKSPACECREATEFIRSTPAGE_H
