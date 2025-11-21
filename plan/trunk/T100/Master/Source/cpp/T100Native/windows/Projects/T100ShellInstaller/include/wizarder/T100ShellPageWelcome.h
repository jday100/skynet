#ifndef T100SHELLPAGEWELCOME_H
#define T100SHELLPAGEWELCOME_H

#include <wx/wizard.h>
#include "T100Common.h"

using namespace T100LIBRARY;

class T100ShellPageWelcome : public wxWizardPage
{
    public:
        T100ShellPageWelcome(wxWizard *parent);
        virtual ~T100ShellPageWelcome();

        wxWizardPage*           GetPrev() const;
        wxWizardPage*           GetNext() const;

    protected:

    private:
};

#endif // T100SHELLPAGEWELCOME_H
