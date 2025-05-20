#include "T100IDManager.h"

T100IDManager::T100IDManager()
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
    m_count = 0;
}

T100VOID T100IDManager::uninit()
{

}

T100INT T100IDManager::Next()
{
    return m_count++;
}

T100VOID T100IDManager::Get(T100WORD length, T100INT& start, T100INT& end)
{
    start   = m_count;
    m_count += length;
    end     = m_count;
}
