#ifndef T100CREATEWIZARDFIRSTPAGE_H
#define T100CREATEWIZARDFIRSTPAGE_H

#include <wx/wizard.h>
#include "T100Common.h"

class T100CreateWizardFirstPage : public wxWizardPageSimple
{
    public:
        T100CreateWizardFirstPage(wxWizard *parent,
                       wxWizardPage *prev = NULL,
                       wxWizardPage *next = NULL,
                       const wxBitmap& bitmap = wxNullBitmap);
        virtual ~T100CreateWizardFirstPage();

    protected:

    private:
        T100VOID            init();
        T100VOID            uninit();
};

#endif // T100CREATEWIZARDFIRSTPAGE_H
