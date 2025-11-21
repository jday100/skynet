#include "T100ExtensionDock.h"

T100ExtensionDock::T100ExtensionDock()
{
    //ctor
}

T100ExtensionDock::~T100ExtensionDock()
{
    //dtor
}

T100VOID T100ExtensionDock::SetDockManager(wxAuiManager* manager)
{
    m_dockManager       = manager;
}

wxAuiManager* T100ExtensionDock::GetDockManager()
{
    return m_dockManager;
}
