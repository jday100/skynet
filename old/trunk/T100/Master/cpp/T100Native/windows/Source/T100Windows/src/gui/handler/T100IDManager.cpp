#include "gui/handler/T100IDManager.h"

namespace T100WINDOWS{

T100IDManager::T100IDManager() :
    T100Class()
{
    //ctor
    init();
}

T100IDManager::~T100IDManager()
{
    //dtor
    uninit();
}

T100VOID T100IDManager::init()
{
    m_count     = 0;
}

T100VOID T100IDManager::uninit()
{

}

T100INT T100IDManager::Next()
{
    return ++m_count;
}

T100VOID T100IDManager::Get(T100UINT length, T100INT& head, T100INT& stop)
{
    head    = m_count;
    m_count += length;
    stop    = m_count;
}

}
