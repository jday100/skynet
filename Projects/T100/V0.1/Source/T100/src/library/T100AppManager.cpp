#include "T100AppManager.h"

namespace T100Library{

T100AppManager::T100AppManager()
{
    //ctor
    create();
}

T100AppManager::~T100AppManager()
{
    //dtor
    destroy();
}

T100VOID T100AppManager::create()
{
    m_count     = 0;
    m_running   = T100FALSE;
}

T100VOID T100AppManager::destroy()
{
    m_apps.clear();
}

T100BOOL T100AppManager::start()
{
    std::lock_guard<std::mutex>     lock(m_mutex);

    if(m_running){
        return T100FALSE;
    }

    m_running   = T100TRUE;
    return T100TRUE;
}

T100BOOL T100AppManager::stop()
{
    std::lock_guard<std::mutex>     lock(m_mutex);

    if(!m_running){
        return T100FALSE;
    }

    m_running   = T100FALSE;
    return T100TRUE;
}

T100BOOL T100AppManager::quit(T100WORD value)
{
    if(m_running){
        if(!stop()){
            return T100FALSE;
        }
    }

    std::lock_guard<std::mutex>     lock(m_mutex);

    if(0 <= m_count){
        exit(value);
    }
    return T100FALSE;
}

T100VOID T100AppManager::open()
{
    std::lock_guard<std::mutex>     lock(m_mutex);
    m_count++;
}

T100VOID T100AppManager::close()
{
    std::lock_guard<std::mutex>     lock(m_mutex);
    m_count--;
}

}
