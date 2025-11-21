#include "core/T100DX12Space.h"

T100DX12Space::T100DX12Space() :
    T100DX12Card(),
    m_heapManager(this)
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
    m_config    = T100NEW T1003DConfig();

    m_config->RtvHeapSize       = 3;
    m_config->DsvHeapSize       = 1;
    m_config->SamplerHeapSize   = 1;
}

T100VOID T100DX12Space::uninit()
{
    T100SAFE_DELETE m_config;
}

T100DX12HeapManager& T100DX12Space::GetHeapManager()
{
    return m_heapManager;
}

T100VOID T100DX12Space::Start()
{
    T100DX12Card::Start();
    m_heapManager.Start(m_config);
}

T100VOID T100DX12Space::Stop()
{
    m_heapManager.Stop();
    T100DX12Card::Stop();
}

T100VOID T100DX12Space::SetConfigPtr(T1003DConfig* config)
{
    m_config    = config;
}

T1003DConfig* T100DX12Space::GetConfigPtr()
{
    return m_config;
}


