#include "T100PluginProject.h"

#include "T100PluginProjectInvoking.h"
#include "T100ExtensionCommon.h"
#include "T100ExtensionFrame.h"
#include "T100ExtensionManager.h"
#include "T100ProjectMain.h"

#include "T100Project.h"

T100PluginProject::T100PluginProject() :
    T100Plugin()
{
    //ctor
}

T100PluginProject::~T100PluginProject()
{
    //dtor
}

T100PluginProjectView* T100PluginProject::GetView()
{
    return m_view;
}

T100PluginProjectServe* T100PluginProject::GetServe()
{
    return m_serve;
}

T100PluginProjectStore* T100PluginProject::GetStore()
{
    return m_store;
}

T100VOID T100PluginProject::Init(T100ExtensionManager* manager)
{
    T100Plugin::Init(manager);
    T100PluginProjectInvoking::Init(this);

    Load();
}

T100VOID T100PluginProject::Load()
{
    T100ExtensionFrame*     frameExtension  = dynamic_cast<T100ExtensionFrame*>(m_extensionManager->Find(T100PROJECT_VIEW_MAIN_FRAME));

    if(!frameExtension){
        return;
    }

    T100ProjectFrame*       frame       = dynamic_cast<T100ProjectFrame*>(frameExtension->GetFrame());

    if(!frame){
        return;
    }

    m_view  = T100NEW T100PluginProjectView();
    m_serve = T100NEW T100PluginProjectServe();
    m_store = T100NEW T100PluginProjectStore();

    m_view->Create(frame);
    m_store->SetPath(L"../../workspace/*.*");


    LoadWorkSpace();
}

T100VOID T100PluginProject::LoadWorkSpace()
{
    T100PROJECT_VESSEL&     projects    = m_serve->GetManager()->GetProjects();

    m_store->Load(projects);

    m_view->Update(projects);
}
