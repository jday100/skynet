#include "view/T1003DEditorMainMenu.h"

#include <wx/frame.h>
#include "skeletal/T1003DEditorCallback.h"

const long T1003DEditorMainMenu::ID_MENU_NEW = wxNewId();
const long T1003DEditorMainMenu::ID_MENU_OPEN = wxNewId();
const long T1003DEditorMainMenu::ID_MENU_CLOSE = wxNewId();
const long T1003DEditorMainMenu::ID_MENU_SAVE = wxNewId();
const long T1003DEditorMainMenu::ID_MENU_SAVE_AS = wxNewId();
const long T1003DEditorMainMenu::ID_MENU_IMPORT = wxNewId();
const long T1003DEditorMainMenu::ID_MENU_EXPORT = wxNewId();
const long T1003DEditorMainMenu::ID_MENU_QUIT = wxNewId();
const long T1003DEditorMainMenu::ID_MENU_UNDO = wxNewId();
const long T1003DEditorMainMenu::ID_MENU_REDO = wxNewId();
const long T1003DEditorMainMenu::ID_MENU_CUT = wxNewId();
const long T1003DEditorMainMenu::ID_MENU_COPY = wxNewId();
const long T1003DEditorMainMenu::ID_MENU_PASTE = wxNewId();
const long T1003DEditorMainMenu::ID_MENU_MANAGER = wxNewId();
const long T1003DEditorMainMenu::ID_MENU_PROPERTIES = wxNewId();
const long T1003DEditorMainMenu::ID_MENU_CONFIG = wxNewId();

T1003DEditorMainMenu::T1003DEditorMainMenu()
{
    //ctor
    init();
}

T1003DEditorMainMenu::~T1003DEditorMainMenu()
{
    //dtor
    uninit();
}

T100VOID T1003DEditorMainMenu::init()
{

}

T100VOID T1003DEditorMainMenu::uninit()
{
    Destroy();
}

T100VOID T1003DEditorMainMenu::Create(wxFrame* frame)
{
    m_framePtr      = frame;

    m_menuBarPtr    = T100NEW wxMenuBar();

    createFileMenu();
    createEditMenu();
    createViewMenu();
    createSettingsMenu();
    createHelpMenu();

    m_framePtr->SetMenuBar(m_menuBarPtr);
}

T100VOID T1003DEditorMainMenu::Destroy()
{

}

T100VOID T1003DEditorMainMenu::createFileMenu()
{
    m_menuFilePtr       = T100NEW wxMenu();

    m_itemNewPtr        = m_menuFilePtr->Append(ID_MENU_NEW, wxT("New"));
    m_itemOpenPtr       = m_menuFilePtr->Append(ID_MENU_OPEN, wxT("Open"));
    m_itemClosePtr      = m_menuFilePtr->Append(ID_MENU_CLOSE, wxT("Close"));
    m_menuFilePtr->AppendSeparator();
    m_itemSavePtr       = m_menuFilePtr->Append(ID_MENU_SAVE, wxT("Save"));
    m_itemSaveAsPtr     = m_menuFilePtr->Append(ID_MENU_SAVE_AS, wxT("Save as"));
    m_menuFilePtr->AppendSeparator();
    m_itemImportPtr     = m_menuFilePtr->Append(ID_MENU_IMPORT, wxT("Import"));
    m_itemExportPtr     = m_menuFilePtr->Append(ID_MENU_EXPORT, wxT("Export"));
    m_menuFilePtr->AppendSeparator();
    m_itemQuitPtr       = m_menuFilePtr->Append(ID_MENU_QUIT, wxT("Quit"));

    m_menuBarPtr->Append(m_menuFilePtr, wxT("File"));
}

T100VOID T1003DEditorMainMenu::createEditMenu()
{
    m_menuEditPtr       = T100NEW wxMenu();

    m_itemUndoPtr       = m_menuEditPtr->Append(ID_MENU_UNDO, wxT("Undo"));
    m_itemRedoPtr       = m_menuEditPtr->Append(ID_MENU_REDO, wxT("Redo"));
    m_menuEditPtr->AppendSeparator();
    m_itemCutPtr        = m_menuEditPtr->Append(ID_MENU_CUT, wxT("Cut"));
    m_itemCopyPtr       = m_menuEditPtr->Append(ID_MENU_COPY, wxT("Copy"));
    m_itemPastePtr      = m_menuEditPtr->Append(ID_MENU_PASTE, wxT("Paste"));

    m_menuBarPtr->Append(m_menuEditPtr, wxT("Edit"));
}

T100VOID T1003DEditorMainMenu::createViewMenu()
{
    m_menuViewPtr       = T100NEW wxMenu();

    m_itemManagerPtr    = m_menuViewPtr->Append(ID_MENU_MANAGER, wxT("Manager"));
    m_itemPropertiesPtr = m_menuViewPtr->Append(ID_MENU_PROPERTIES, wxT("Properties"));

    m_itemManagerPtr->SetCheckable(T100TRUE);
    m_itemPropertiesPtr->SetCheckable(T100TRUE);

    m_menuBarPtr->Append(m_menuViewPtr, wxT("View"));

    m_framePtr->Connect(ID_MENU_MANAGER,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T1003DEditorMainMenu::OnMenuItemManagerSelected);
    m_framePtr->Connect(ID_MENU_PROPERTIES,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T1003DEditorMainMenu::OnMenuItemPropertiesSelected);

}

T100VOID T1003DEditorMainMenu::createSettingsMenu()
{
    m_menuSettingsPtr   = T100NEW wxMenu();

    m_itemConfigPtr     = m_menuSettingsPtr->Append(ID_MENU_CONFIG, wxT("Config"));

    m_menuBarPtr->Append(m_menuSettingsPtr, wxT("Settings"));
}

T100VOID T1003DEditorMainMenu::createHelpMenu()
{
    m_menuHelpPtr       = T100NEW wxMenu();

    //m_itemAboutPtr      = m_menuHelpPtr->Append(ID_MENU_ABOUT, wxT("About"));

    m_menuBarPtr->Append(m_menuHelpPtr, wxT("Help"));
}

T100VOID T1003DEditorMainMenu::New()
{
    m_itemNewPtr->Enable(T100TRUE);
    m_itemOpenPtr->Enable(T100TRUE);
    m_itemClosePtr->Enable(T100TRUE);
    m_itemSavePtr->Enable(T100FALSE);
    m_itemSaveAsPtr->Enable(T100FALSE);
    m_itemQuitPtr->Enable(T100TRUE);

    m_itemUndoPtr->Enable(T100FALSE);
    m_itemRedoPtr->Enable(T100FALSE);
    m_itemCutPtr->Enable(T100FALSE);
    m_itemCopyPtr->Enable(T100FALSE);
    m_itemPastePtr->Enable(T100FALSE);

    m_itemConfigPtr->Enable(T100TRUE);
    //m_itemAboutPtr->Enable(T100TRUE);
}

T100VOID T1003DEditorMainMenu::Open()
{

}

T100VOID T1003DEditorMainMenu::Save()
{

}

T100VOID T1003DEditorMainMenu::SetManager(T100BOOL flag)
{
    if(flag){
        m_itemManagerPtr->Check(T100TRUE);
    }else{
        m_itemManagerPtr->Check(T100FALSE);
    }
}

T100VOID T1003DEditorMainMenu::UpdateManager()
{
    T100BOOL    flag    = m_itemManagerPtr->IsChecked();

    m_itemManagerPtr->Check(!flag);
}

T100VOID T1003DEditorMainMenu::SetProperties(T100BOOL flag)
{
    if(flag){
        m_itemPropertiesPtr->Check(T100TRUE);
    }else{
        m_itemPropertiesPtr->Check(T100FALSE);
    }
}

T100VOID T1003DEditorMainMenu::SetSave(T100BOOL flag)
{
    m_itemSavePtr->Enable(flag);
    m_itemSaveAsPtr->Enable(flag);
}

void T1003DEditorMainMenu::OnMenuItemManagerSelected(wxCommandEvent& event)
{
    T1003DEditorCallback::MenuManager(event.IsChecked());
}

void T1003DEditorMainMenu::OnMenuItemPropertiesSelected(wxCommandEvent& event)
{
    T1003DEditorCallback::MenuProperties(event.IsChecked());
}
