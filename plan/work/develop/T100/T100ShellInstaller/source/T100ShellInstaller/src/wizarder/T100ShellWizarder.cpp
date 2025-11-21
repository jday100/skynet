#include "T100ShellWizarder.h"

#include "T100ShellPageWelcome.h"

T100ShellWizarder::T100ShellWizarder(wxWindow* parent) :
    wxWizard(parent)
{
    //ctor
}

T100ShellWizarder::~T100ShellWizarder()
{
    //dtor
}

T100INT T100ShellWizarder::ShowModal()
{
    T100ShellPageWelcome*       welcome     = T100NEW T100ShellPageWelcome(this);

    RunWizard(welcome);
}
