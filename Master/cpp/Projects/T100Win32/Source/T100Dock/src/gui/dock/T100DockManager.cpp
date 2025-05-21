#include "T100DockManager.h"

T100DockManager::T100DockManager() :
    T100DockManagerBase()
{
    //ctor
}

T100DockManager::T100DockManager(T100Frame* frame) :
    T100DockManagerBase(frame)
{
    //ctor
}

T100DockManager::~T100DockManager()
{
    //dtor
}

T100VOID T100DockManager::AddPane(T100WSTRING name, T100Window* pane, T100DockInfo& info)
{
    T100DOCK_DATA*      data    = T100NEW T100DOCK_DATA();

    *data   = {name, pane, info};

    m_children.push_back(data);
    m_names[name]       = data;
    m_windows[pane]     = data;

    Classify(data);
}

T100VOID T100DockManager::Update()
{
    if(!m_framePtr){
        return;
    }

    UpdateLeft();
    UpdateCenter();
}
