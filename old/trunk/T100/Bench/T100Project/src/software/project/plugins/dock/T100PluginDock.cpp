#include "T100PluginDock.h"

#include <wx/aui/aui.h>
#include "T100ExtensionCommon.h"
#include "T100ExtensionFrame.h"
#include "T100ExtensionManager.h"
#include "T100ProjectMain.h"
#include "T100ExtensionDock.h"

T100PluginDock::T100PluginDock() :
    T100Plugin()
{
    //ctor
}

T100PluginDock::~T100PluginDock()
{
    //dtor
}

T100VOID T100PluginDock::Init(T100ExtensionManager* manager)
{
    T100Plugin::Init(manager);

    Load();
}

T100VOID T100PluginDock::Load()
{
    T100ExtensionFrame*     frameExtension  = dynamic_cast<T100ExtensionFrame*>(m_extensionManager->Find(T100PROJECT_VIEW_MAIN_FRAME));

    if(!frameExtension){
        return;
    }

    T100ProjectFrame*       frame       = dynamic_cast<T100ProjectFrame*>(frameExtension->GetFrame());

    if(!frame){
        return;
    }

    T100ExtensionDock*      dock        = T100NEW T100ExtensionDock();

    wxAuiManager*           manager     = T100NEW wxAuiManager(frame);

    dock->SetDockManager(manager);

    m_extensionManager->Create(T100PROJECT_VIEW_MAIN_DOCK_MANAGER, dock);

    manager->Update();

}
