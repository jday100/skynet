#ifndef T100PROJECTCREATEWIZARD_H
#define T100PROJECTCREATEWIZARD_H

#include <wx/wizard.h>
#include "T100CreateWizardFirstPage.h"
#include "T100CreateWizardSecondPage.h"

class T100ProjectCreateWizard : public wxWizard
{
    public:
        T100ProjectCreateWizard(wxWindow *parent,
             int id = wxID_ANY,
             const wxString& title = wxEmptyString,
             const wxBitmap& bitmap = wxNullBitmap,
             const wxPoint& pos = wxDefaultPosition,
             long style = wxDEFAULT_DIALOG_STYLE);
        virtual ~T100ProjectCreateWizard();

        wxWizardPage*               GetFirstPage();

    protected:
        T100VOID                    OnWizardCancel(wxWizardEvent&);
        T100VOID                    OnWizardFinished(wxWizardEvent&);

    protected:
        T100CreateWizardFirstPage*          m_first     = T100NULL;
        T100CreateWizardSecondPage*         m_second    = T100NULL;

    private:
        T100VOID                    init();
        T100VOID                    uninit();

        DECLARE_EVENT_TABLE()
};

#endif // T100PROJECTCREATEWIZARD_H
