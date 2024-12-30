#include "T100EditorWindowsManager.h"

T100EditorWindowsManager::T100EditorWindowsManager(T100MainPanel* parent)
    :m_parent(parent)
{
    //ctor
}

T100EditorWindowsManager::~T100EditorWindowsManager()
{
    //dtor
}

T100BOOL T100EditorWindowsManager::renew()
{
    T100EditorCtrl*         editor          = T100NULL;

    editor  = T100NEW T100EditorCtrl(m_parent->Notebook);
    if(editor){
        m_windows.push_back(editor);
        m_parent->Notebook->AddPage(editor, wxT("unnamed"));
        return T100TRUE;
    }

    return T100FALSE;
}

T100EditorCtrl* T100EditorWindowsManager::getCurrent()
{
    return m_windows[0];
}

T100BOOL T100EditorWindowsManager::quit()
{

}
