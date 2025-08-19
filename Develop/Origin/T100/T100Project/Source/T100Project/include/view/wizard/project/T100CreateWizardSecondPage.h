#ifndef T100CREATEWIZARDSECONDPAGE_H
#define T100CREATEWIZARDSECONDPAGE_H

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

    protected:

    private:
        T100VOID            init();
        T100VOID            uninit();
};

#endif // T100CREATEWIZARDSECONDPAGE_H
