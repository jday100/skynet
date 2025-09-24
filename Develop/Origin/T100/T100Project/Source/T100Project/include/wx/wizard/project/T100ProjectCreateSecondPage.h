#ifndef T100PROJECTCREATESECONDPAGE_H
#define T100PROJECTCREATESECONDPAGE_H

#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/wizard.h>
#include "T100Common.h"

class T100ProjectCreateSecondPage : public wxWizardPageSimple
{
    public:
        T100ProjectCreateSecondPage(wxWizard *parent,
                       wxWizardPage *prev = NULL,
                       wxWizardPage *next = NULL,
                       const wxBitmap& bitmap = wxNullBitmap);
        virtual ~T100ProjectCreateSecondPage();

        const T100WSTRING       GetLabel();

        T100BOOL                TransferDataToWindow();
        T100BOOL                TransferDataFromWindow();

    protected:
        static const long ID_PROJECT_NAME_TITLE;
        static const long ID_PROJECT_NAME_LABEL;

    protected:
        wxStaticText*           m_title;
        wxTextCtrl*             m_label;

    private:
        T100VOID                init();
        T100VOID                uninit();
};

#endif // T100PROJECTCREATESECONDPAGE_H
