#include "T100ExtensionPanel.h"

T100ExtensionPanel::T100ExtensionPanel() :
    T100Extension()
{
    //ctor
}

T100ExtensionPanel::~T100ExtensionPanel()
{
    //dtor
}

T100VOID T100ExtensionPanel::SetPanel(wxPanel* panel)
{
    m_panel         = panel;
}

wxPanel* T100ExtensionPanel::GetPanel()
{
    return m_panel;
}
