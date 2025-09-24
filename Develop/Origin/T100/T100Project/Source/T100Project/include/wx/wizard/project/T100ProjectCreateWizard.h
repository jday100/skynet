#ifndef T100PROJECTCREATEWIZARD_H
#define T100PROJECTCREATEWIZARD_H

#include "T100ProjectInfo.h"
#include "T100ProjectCreateFirstPage.h"
#include "T100ProjectCreateSecondPage.h"

class T100ProjectCreateWizard : public wxWizard
{
    public:
        T100ProjectCreateWizard(wxWindow *parent,
             int id = wxID_ANY,
             const wxString& title = L"Create Project...",
             const wxBitmap& bitmap = wxNullBitmap,
             const wxPoint& pos = wxDefaultPosition,
             long style = wxDEFAULT_DIALOG_STYLE);
        virtual ~T100ProjectCreateWizard();

        wxWizardPage*       GetFirstPage();

    protected:
        T100VOID            OnWizardCancel(wxWizardEvent&);
        T100VOID            OnWizardFinished(wxWizardEvent&);

    private:
        T100ProjectInfo     m_info;

        T100ProjectCreateFirstPage*         m_first         = T100NULL;
        T100ProjectCreateSecondPage*        m_second        = T100NULL;

        T100VOID            init();
        T100VOID            uninit();

        DECLARE_EVENT_TABLE()
};

#endif // T100PROJECTCREATEWIZARD_H
