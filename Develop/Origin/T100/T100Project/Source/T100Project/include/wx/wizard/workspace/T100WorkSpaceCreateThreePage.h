#ifndef T100WORKSPACECREATETHREEPAGE_H
#define T100WORKSPACECREATETHREEPAGE_H

#include <wx/wizard.h>
#include "T100PythonPanel.h"

class T100WorkSpaceCreateThreePage : public wxWizardPageSimple
{
    public:
        T100WorkSpaceCreateThreePage(wxWizard *parent,
                       wxWizardPage *prev = NULL,
                       wxWizardPage *next = NULL,
                       const wxBitmap& bitmap = wxNullBitmap);
        virtual ~T100WorkSpaceCreateThreePage();

        const T100WSTRING           GetPath();

        T100BOOL                    TransferDataToWindow();
        T100BOOL                    TransferDataFromWindow();

    protected:
        T100PythonPanel*            m_pythonPanel       = T100NULL;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100WORKSPACECREATETHREEPAGE_H
