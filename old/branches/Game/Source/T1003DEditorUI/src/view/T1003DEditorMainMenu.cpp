#include "T1003DEditorMainMenu.h"

#include <wx/frame.h>

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
    m_frame     = frame;
    m_menuBar   = m_frame->GetMenuBar();

    m_menuFile      = m_menuBar->GetMenu(m_menuBar->FindMenu(wxT("File")));
    m_menuEdit      = m_menuBar->GetMenu(m_menuBar->FindMenu(wxT("Edit")));
    m_menuView      = m_menuBar->GetMenu(m_menuBar->FindMenu(wxT("View")));
    m_menuSettings  = m_menuBar->GetMenu(m_menuBar->FindMenu(wxT("Settings")));
    m_menuHelp      = m_menuBar->GetMenu(m_menuBar->FindMenu(wxT("Help")));

    m_itemNew           = m_menuFile->FindItem(m_menuFile->FindItem(wxT("New")));
    m_itemOpen          = m_menuFile->FindItem(m_menuFile->FindItem(wxT("Open")));
    m_itemClose         = m_menuFile->FindItem(m_menuFile->FindItem(wxT("Close")));
    m_itemSave          = m_menuFile->FindItem(m_menuFile->FindItem(wxT("Save")));
    m_itemSaveAs        = m_menuFile->FindItem(m_menuFile->FindItem(wxT("Save as")));
    m_itemImport        = m_menuFile->FindItem(m_menuFile->FindItem(wxT("Import")));
    m_itemExport        = m_menuFile->FindItem(m_menuFile->FindItem(wxT("Export")));
    m_itemQuit          = m_menuFile->FindItem(m_menuFile->FindItem(wxT("Quit")));

    m_itemUndo          = m_menuEdit->FindItem(m_menuEdit->FindItem(wxT("Redo")));
    m_itemRedo          = m_menuEdit->FindItem(m_menuEdit->FindItem(wxT("Undo")));
    m_itemCut           = m_menuEdit->FindItem(m_menuEdit->FindItem(wxT("Cut")));
    m_itemCopy          = m_menuEdit->FindItem(m_menuEdit->FindItem(wxT("Copy")));
    m_itemPaste         = m_menuEdit->FindItem(m_menuEdit->FindItem(wxT("Paste")));

    m_itemManager       = m_menuView->FindItem(m_menuView->FindItem(wxT("Manager")));
    m_itemProperties    = m_menuView->FindItem(m_menuView->FindItem(wxT("Properties")));

    m_itemConfig        = m_menuSettings->FindItem(m_menuSettings->FindItem(wxT("Config")));

    m_itemAbout         = m_menuHelp->FindItem(m_menuHelp->FindItem(wxT("About")));

}

T100VOID T1003DEditorMainMenu::Destroy()
{

}

T100VOID T1003DEditorMainMenu::Init()
{
    m_itemNew->Enable(T100TRUE);
    m_itemOpen->Enable(T100TRUE);
    m_itemClose->Enable(T100FALSE);
    m_itemSave->Enable(T100FALSE);
    m_itemSaveAs->Enable(T100FALSE);
    m_itemImport->Enable(T100TRUE);
    m_itemExport->Enable(T100FALSE);
    m_itemQuit->Enable(T100TRUE);

    m_itemUndo->Enable(T100FALSE);
    m_itemRedo->Enable(T100FALSE);
    m_itemCut->Enable(T100FALSE);
    m_itemCopy->Enable(T100FALSE);
    m_itemPaste->Enable(T100FALSE);

    m_itemConfig->Enable(T100TRUE);
    m_itemAbout->Enable(T100TRUE);
}

T100VOID T1003DEditorMainMenu::New()
{
    m_itemNew->Enable(T100TRUE);
    m_itemOpen->Enable(T100TRUE);
    m_itemClose->Enable(T100TRUE);
    m_itemSave->Enable(T100TRUE);
    m_itemSaveAs->Enable(T100TRUE);
    m_itemImport->Enable(T100TRUE);
    m_itemExport->Enable(T100TRUE);
    m_itemQuit->Enable(T100TRUE);

    m_itemUndo->Enable(T100FALSE);
    m_itemRedo->Enable(T100FALSE);
    m_itemCut->Enable(T100FALSE);
    m_itemCopy->Enable(T100FALSE);
    m_itemPaste->Enable(T100FALSE);

    m_itemConfig->Enable(T100TRUE);
    m_itemAbout->Enable(T100TRUE);
}

T100VOID T1003DEditorMainMenu::Open()
{

}

T100VOID T1003DEditorMainMenu::Close()
{
    m_itemNew->Enable(T100TRUE);
    m_itemOpen->Enable(T100TRUE);
    m_itemClose->Enable(T100FALSE);
    m_itemSave->Enable(T100FALSE);
    m_itemSaveAs->Enable(T100FALSE);
    m_itemImport->Enable(T100TRUE);
    m_itemExport->Enable(T100FALSE);
    m_itemQuit->Enable(T100TRUE);

    m_itemUndo->Enable(T100FALSE);
    m_itemRedo->Enable(T100FALSE);
    m_itemCut->Enable(T100FALSE);
    m_itemCopy->Enable(T100FALSE);
    m_itemPaste->Enable(T100FALSE);

    m_itemConfig->Enable(T100TRUE);
    m_itemAbout->Enable(T100TRUE);
}

T100VOID T1003DEditorMainMenu::Save()
{
    m_itemNew->Enable(T100TRUE);
    m_itemOpen->Enable(T100TRUE);
    m_itemClose->Enable(T100TRUE);
    m_itemSave->Enable(T100FALSE);
    m_itemSaveAs->Enable(T100TRUE);
    m_itemImport->Enable(T100TRUE);
    m_itemExport->Enable(T100TRUE);
    m_itemQuit->Enable(T100TRUE);

    m_itemUndo->Enable(T100FALSE);
    m_itemRedo->Enable(T100FALSE);
    m_itemCut->Enable(T100FALSE);
    m_itemCopy->Enable(T100FALSE);
    m_itemPaste->Enable(T100FALSE);

    m_itemConfig->Enable(T100TRUE);
    m_itemAbout->Enable(T100TRUE);
}

T100VOID T1003DEditorMainMenu::SetManager(T100BOOL flag)
{
    if(flag){
        m_itemManager->Check(T100TRUE);
    }else{
        m_itemManager->Check(T100FALSE);
    }
}

T100VOID T1003DEditorMainMenu::UpdateManager()
{
    T100BOOL    flag    = m_itemManager->IsChecked();

    m_itemManager->Check(!flag);
}

T100VOID T1003DEditorMainMenu::SetProperties(T100BOOL flag)
{
    if(flag){
        m_itemProperties->Check(T100TRUE);
    }else{
        m_itemProperties->Check(T100FALSE);
    }
}

T100VOID T1003DEditorMainMenu::SetSave(T100BOOL flag)
{
    m_itemSave->Enable(flag);
    m_itemSaveAs->Enable(flag);
}
