#ifndef T100SHELLWIZARDER_H
#define T100SHELLWIZARDER_H

#include <wx/frame.h>
#include <wx/wizard.h>
#include "T100Common.h"

using namespace T100LIBRARY;

class T100ShellWizarder : public wxWizard
{
    public:
        T100ShellWizarder(wxWindow*);
        virtual ~T100ShellWizarder();

        T100INT             ShowModal();

    protected:

    private:
};

#endif // T100SHELLWIZARDER_H
