#ifndef T100WORKSPACECREATEWIZARD_H
#define T100WORKSPACECREATEWIZARD_H

#include <wx/wizard.h>
#include "T100WorkSpaceInfo.h"
#include "T100WorkSpaceCreateFirstPage.h"
#include "T100WorkSpaceCreateSecondPage.h"
#include "T100WorkSpaceCreateThreePage.h"

class T100WorkSpaceCreateWizard : public wxWizard
{
    public:
        T100WorkSpaceCreateWizard(wxWindow *parent,
             int id = wxID_ANY,
             const wxString& title = L"Create WorkSpace...",
             const wxBitmap& bitmap = wxNullBitmap,
             const wxPoint& pos = wxDefaultPosition,
             long style = wxDEFAULT_DIALOG_STYLE);
        virtual ~T100WorkSpaceCreateWizard();

        wxWizardPage*       GetFirstPage();

    protected:
        T100VOID            OnWizardCancel(wxWizardEvent&);
        T100VOID            OnWizardFinished(wxWizardEvent&);

    private:
        T100WorkSpaceInfo   m_info;

        T100WorkSpaceCreateFirstPage*           m_first         = T100NULL;
        T100WorkSpaceCreateSecondPage*          m_second        = T100NULL;
        T100WorkSpaceCreateThreePage*           m_three         = T100NULL;

        T100VOID            init();
        T100VOID            uninit();

        DECLARE_EVENT_TABLE()
};

#endif // T100WORKSPACECREATEWIZARD_H
