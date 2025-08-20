#ifndef T100CREATEWIZARDSECONDPAGE_H
#define T100CREATEWIZARDSECONDPAGE_H

#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/wizard.h>
#include "T100Common.h"

class T100CreateWizardSecondPage : public wxWizardPageSimple
{
    public:
        T100CreateWizardSecondPage(wxWizard *parent,
                       wxWizardPage *prev = NULL,
                       wxWizardPage *next = NULL,
                       const wxBitmap& bitmap = wxNullBitmap);
        virtual ~T100CreateWizardSecondPage();

        const T100WSTRING           GetProjectName();

    protected:
        static const long ID_STATICBOX;
        static const long ID_STATIC_TEXT;
        static const long ID_TEXT_CTRL;

    protected:
        wxStaticText*       m_title;
        wxTextCtrl*         m_label;

    private:
        T100VOID            init();
        T100VOID            uninit();
};

#endif // T100CREATEWIZARDSECONDPAGE_H
