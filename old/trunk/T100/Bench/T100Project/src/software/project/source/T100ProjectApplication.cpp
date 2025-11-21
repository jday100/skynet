#include "T100ProjectApplication.h"

#include "T100ExtensionCommon.h"
#include "T100ExtensionMenu.h"
#include "T100ExtensionFrame.h"
#include "T100ExtensionDialog.h"

#include "T100ProjectMain.h"

#include "T100PluginDock.h"
#include "T100PluginMainMenu.h"
#include "T100PluginEditor.h"
#include "T100PluginProject.h"

T100ProjectApplication::T100ProjectApplication() :
    T100Class(),
    m_view(),
    m_serve(),
    m_store(),
    m_pluginManager(),
    m_extensionManager()
{
    //ctor
}

T100ProjectApplication::~T100ProjectApplication()
{
    //dtor
}

T100VOID T100ProjectApplication::Create(T100ProjectFrame* frame)
{
    init(frame);
    m_view.Create(frame);

    Load();
}

T100VOID T100ProjectApplication::Destroy()
{
    m_view.Destroy();
}

T100VOID T100ProjectApplication::init(T100ProjectFrame* frame)
{
    m_pluginManager.SetExtensionManager(&m_extensionManager);

    T100ExtensionFrame*         frameExtension      = T100NEW T100ExtensionFrame();

    frameExtension->SetFrame(frame);

    m_extensionManager.Create(T100PROJECT_VIEW_MAIN_FRAME, frameExtension);

    T100ExtensionMenu*          menuExtension       = T100NEW T100ExtensionMenu();

    menuExtension->SetHandler(frame, (wxObjectEventFunction)&frame->OnMenu);

    m_extensionManager.Create(T100PROJECT_VIEW_MAIN_FRAME_MENU, menuExtension);

    T100ExtensionDialog*        dialogExtension     = T100NEW T100ExtensionDialog();

    dialogExtension->SetHandler(this, (T100CLASS_METHOD)&CreateCreateDialog);

    m_extensionManager.Create(T100PROJECT_VIEW_PROJECT_DIALOG_CREATE, dialogExtension);
}

T100VOID T100ProjectApplication::uninit()
{

}

T100VOID T100ProjectApplication::Load()
{
    T100PluginMainMenu*     menu        = T100NEW T100PluginMainMenu();

    m_pluginManager.Load(menu);

    T100PluginDock*         dock        = T100NEW T100PluginDock();

    m_pluginManager.Load(dock);

    T100PluginProject*      project     = T100NEW T100PluginProject();

    m_pluginManager.Load(project);

    T100PluginEditor*       editor      = T100NEW T100PluginEditor();

    m_pluginManager.Load(editor);
}

T100VOID T100ProjectApplication::SendEvent(wxCommandEvent& event)
{
    T100ExtensionMenu*      menuExtension   = dynamic_cast<T100ExtensionMenu*>(m_extensionManager.Find(T100PROJECT_VIEW_MAIN_FRAME_MENU));

    if(!menuExtension){
        return;
    }

    menuExtension->SendEvent(event);
}

T100VOID T100ProjectApplication::Quit()
{
    m_view.Destroy();
}

T100VOID* T100ProjectApplication::CreateCreateDialog(T100VOID*)
{
    T100ExtensionFrame*     frameExtension  = dynamic_cast<T100ExtensionFrame*>(m_extensionManager.Find(T100PROJECT_VIEW_MAIN_FRAME));

    if(!frameExtension){
        return T100NULL;
    }

    T100ProjectCreateDialog*        dialog      = T100NEW T100ProjectCreateDialog(frameExtension->GetFrame(), wxID_ANY, L"Project");

    return dialog;
}
