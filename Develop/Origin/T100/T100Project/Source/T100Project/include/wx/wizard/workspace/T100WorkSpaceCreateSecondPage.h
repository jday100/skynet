#ifndef T100WORKSPACECREATESECONDPAGE_H
#define T100WORKSPACECREATESECONDPAGE_H

#include <wx/wizard.h>
#include "T100CompilerPanel.h"

class T100WorkSpaceCreateSecondPage : public wxWizardPageSimple
{
    public:
        T100WorkSpaceCreateSecondPage(wxWizard *parent,
                       wxWizardPage *prev = NULL,
                       wxWizardPage *next = NULL,
                       const wxBitmap& bitmap = wxNullBitmap);
        virtual ~T100WorkSpaceCreateSecondPage();

        const T100WSTRING           GetPath();

        T100BOOL                    TransferDataToWindow();
        T100BOOL                    TransferDataFromWindow();

    protected:
        T100CompilerPanel*          m_compilerPanel     = T100NULL;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100WORKSPACECREATESECONDPAGE_H
