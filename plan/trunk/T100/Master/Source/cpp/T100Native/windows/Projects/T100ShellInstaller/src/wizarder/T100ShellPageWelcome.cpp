#include "T100ShellPageWelcome.h"

T100ShellPageWelcome::T100ShellPageWelcome(wxWizard *parent) :
    wxWizardPage(parent)
{
    //ctor
}

T100ShellPageWelcome::~T100ShellPageWelcome()
{
    //dtor
}

wxWizardPage* T100ShellPageWelcome::GetPrev() const
{
    return this;
}

wxWizardPage* T100ShellPageWelcome::GetNext() const
{
    //return const_cast<const T100ShellPageWelcome*>(this);
    return this;
}
