#include "T100DX12Space.h"

#include "T100DX12Tools.h"

T100DX12Space::T100DX12Space() :
    T100DX12Card(),
    m_heap_manager(this)
{
    //ctor
    init();
}

T100DX12Space::~T100DX12Space()
{
    //dtor
    uninit();
}

T100VOID T100DX12Space::init()
{
    if(!m_config){
        m_config    = T100NEW T100DX12Config();
    }
}

T100VOID T100DX12Space::uninit()
{

}

T100VOID T100DX12Space::SetConfig(T100DX12Config* config)
{
    m_config    = config;
}

T100DX12Config* T100DX12Space::GetConfig()
{
    return m_config;
}

T100VOID T100DX12Space::Start()
{
    T100DX12Card::Start();
    m_heap_manager.Start(m_config);
}

T100VOID T100DX12Space::Stop()
{
    T100DX12Card::Stop();
}
