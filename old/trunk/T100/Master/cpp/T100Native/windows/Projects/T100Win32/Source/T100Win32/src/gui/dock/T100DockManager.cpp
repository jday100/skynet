#include "gui/T100DockManager.h"

namespace T100WINDOWS{

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

T100VOID T100DockManager::Update()
{
    if(!m_frame){
        return;
    }

    if(m_leftWindows.size() != 0)
    UpdateLeft();
    if(m_rightWindows.size() != 0)
    UpdateRight();
    if(m_topWindows.size() != 0)
    UpdateTop();
    if(m_bottomWindows.size() != 0)
    UpdateBottom();
    UpdateCenter();
}

T100VOID T100DockManager::AddPane(const T100WSTRING& label, T100Window* pane, T100DockInfo& info)
{
    T100DOCK_DATA*      data        = T100NEW T100DOCK_DATA();

    *data   = {label, pane, info};

    m_children.push_back(data);
    m_labels[label]     = data;
    m_windows[pane]     = data;

    Classify(data);
}

}
