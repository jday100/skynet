#ifndef T100PROJECTCREATEFIRSTPAGE_H
#define T100PROJECTCREATEFIRSTPAGE_H

#include <wx/sizer.h>
#include <wx/wizard.h>
#include "T100Common.h"

class T100ProjectCreateFirstPage : public wxWizardPageSimple
{
    public:
        T100ProjectCreateFirstPage(wxWizard *parent,
                       wxWizardPage *prev = NULL,
                       wxWizardPage *next = NULL,
                       const wxBitmap& bitmap = wxNullBitmap);
        virtual ~T100ProjectCreateFirstPage();

        T100BOOL            TransferDataToWindow();
        T100BOOL            TransferDataFromWindow();

    protected:

    private:
        T100VOID            init();
        T100VOID            uninit();
};

#endif // T100PROJECTCREATEFIRSTPAGE_H
