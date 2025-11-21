#include "T100PluginMainMenu.h"

#include <wx/menu.h>
#include "T100ExtensionCommon.h"
#include "T100ExtensionMenu.h"
#include "T100ExtensionFrame.h"
#include "T100ExtensionManager.h"

#include "T100ProjectInvoking.h"

T100PluginMainMenu::T100PluginMainMenu() :
    T100Plugin()
{
    //ctor
}

T100PluginMainMenu::~T100PluginMainMenu()
{
    //dtor
}

T100VOID T100PluginMainMenu::Init(T100ExtensionManager* manager)
{
    T100Plugin::Init(manager);

    Load();
}

T100VOID T100PluginMainMenu::Load()
{
    T100ExtensionFrame*     frameExtension  = dynamic_cast<T100ExtensionFrame*>(m_extensionManager->Find(T100PROJECT_VIEW_MAIN_FRAME));

    if(!frameExtension){
        return;
    }

    T100ExtensionMenu*      menuExtension   = dynamic_cast<T100ExtensionMenu*>(m_extensionManager->Find(T100PROJECT_VIEW_MAIN_FRAME_MENU));

    if(!menuExtension){
        return;
    }

    CreateMenu(frameExtension, menuExtension);
}

T100VOID T100PluginMainMenu::CreateMenu(T100ExtensionFrame* frameExtension, T100ExtensionMenu* menuExtension)
{
    wxMenuBar*      menuBar     = T100NEW wxMenuBar();

    wxMenu*         fileMenu    = T100NEW wxMenu();
    wxMenu*         editMenu    = T100NEW wxMenu();
    wxMenu*         viewMenu    = T100NEW wxMenu();
    wxMenu*         searchMenu  = T100NEW wxMenu();
    wxMenu*         helpMenu    = T100NEW wxMenu();

    wxMenuItem*     quitItem    = T100NEW wxMenuItem(fileMenu, 1, L"Quit");

    wxMenuItem*     aboutItem   = T100NEW wxMenuItem(helpMenu, 1, L"About");

    fileMenu->Append(quitItem);

    helpMenu->Append(aboutItem);

    menuBar->Append(fileMenu, L"File");
    menuBar->Append(editMenu, L"Edit");
    menuBar->Append(viewMenu, L"View");
    menuBar->Append(searchMenu, L"Search");
    menuBar->Append(helpMenu, L"Help");

    //frameExtension->GetFrame()->Connect(1,1, (wxObjectEventFunction)&OnQuit, this);
    //Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100ProjectFrame::OnQuit);

    //frameExtension->GetFrame()->Connect(1, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100PluginMainMenu::OnQuit, this);

    menuExtension->GetHandler().Handler->Connect(1, wxEVT_COMMAND_MENU_SELECTED, menuExtension->GetHandler().Function);
    menuExtension->SignIn(1, this, (T100EXTENSION_EVENT_FUNCTION)&OnQuit);

    menuExtension->SetMenuBar(frameExtension->GetFrame(), menuBar);
    menuExtension->Update();
}

T100VOID T100PluginMainMenu::OnQuit(wxCommandEvent& event)
{
    T100ProjectInvoking::OnQuit();

    T100ExtensionMenu*      menuExtension   = dynamic_cast<T100ExtensionMenu*>(m_extensionManager->Find(T100PROJECT_VIEW_MAIN_FRAME_MENU));

    if(!menuExtension){
        return;
    }

    menuExtension->GetHandler().Handler->Disconnect(1);
}

