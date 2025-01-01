#include "T100ProjectPlatenManager.h"

T100ProjectPlatenManager::T100ProjectPlatenManager(T100ProjectView* view)
    :m_view(view)
{
    //ctor
    create();
}

T100ProjectPlatenManager::~T100ProjectPlatenManager()
{
    //dtor
    destroy();
}

T100VOID T100ProjectPlatenManager::create()
{
    m_default   = T100NEW T100ProjectDefaultPlaten();
}

T100VOID T100ProjectPlatenManager::destroy()
{
    T100SAFE_DELETE m_default;
}

T100ProjectDefaultPlaten* T100ProjectPlatenManager::getDefault()
{
    return m_default;
}

T100ProjectPlatenBase* T100ProjectPlatenManager::getCurrent()
{
    return m_current;
}
