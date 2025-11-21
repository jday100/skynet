#include "T100GameThread.h"

#include "T1003DEditorConfig.h"

T100GameThread::T100GameThread()
{
    //ctor
    init();
}

T100GameThread::~T100GameThread()
{
    //dtor
    uninit();
}

T100VOID T100GameThread::init()
{
    m_running   = T100FALSE;
}

T100VOID T100GameThread::uninit()
{

}

T100Game* T100GameThread::GetGame()
{
    return m_game;
}

T100VOID T100GameThread::Create(HWND hwnd, T100UINT width, T100UINT height)
{
    m_game  = T100NEW T100Game();
    T100DX12Config*     config      = T100NEW T100DX12Config(T100DX12_HEAP_MEDIUM);

    config->DefaultCoordinateSystemType     = T1003DEditorConfig::DefaultCoordinateSystemType;
    config->DefaultProjectionType           = T1003DEditorConfig::DefaultProjectiveType;

    config->DsvHeapSize             = 256;
    config->SamplerHeapSize         = 256;
    m_game->GetRenderer()->SetConfig(config);
    m_game->Create(hwnd, width, height);
}

T100VOID T100GameThread::Destroy()
{
    T100SAFE_DELETE m_game;
}

T100VOID T100GameThread::Start()
{
    m_game->Start();
    m_running   = T100TRUE;
    m_thread    = T100NEW std::thread(&T100GameThread::run, this);
}

T100VOID T100GameThread::Stop()
{
    m_running   = T100FALSE;
    Waiting();
    m_game->Stop();
}

T100VOID T100GameThread::Waiting()
{
    std::unique_lock<std::mutex>        locker(m_mutex);
    m_condition.wait(locker);
    locker.unlock();
}

T100VOID T100GameThread::run()
{
    while(m_running){
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
        m_game->Update();
        m_game->Render();
    }
    m_condition.notify_all();
}
