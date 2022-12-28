#include "T100IDEPlatenManager.h"

#include "T100IDEDefaultPlaten.h"

namespace T100IDE{

T100IDEPlatenManager::T100IDEPlatenManager(T100IDEView* view)
    :m_view(view)
{
    //ctor
    create();
}

T100IDEPlatenManager::~T100IDEPlatenManager()
{
    //dtor
    destroy();
}

T100VOID T100IDEPlatenManager::create()
{
    m_current = T100NEW T100IDEDefaultPlaten(m_view);
}

T100VOID T100IDEPlatenManager::destroy()
{
    T100SAFE_DELETE(m_current);
}

T100IDEPlatenBase* T100IDEPlatenManager::getDefault()
{
    return m_current;
}

}
