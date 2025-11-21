#include "game/T100GameThread.h"

#include "skeletal/T1003DEditorScene.h"

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

T100Game* T100GameThread::GetGamePtr()
{
    return m_gamePtr;
}

T1003DEditorScene* T100GameThread::GetScenePtr()
{
    return m_scenePtr;
}

T100VOID T100GameThread::Create(HWND hwnd, T100UINT width, T100UINT height)
{
    T1003DConfig*   configPtr   = T100NEW T1003DConfig(T1003D_HEAP_BIG);

    configPtr->DsvHeapSize      = 256;
    configPtr->RtvHeapSize      = 3;
    configPtr->SamplerHeapSize  = 256;

    m_gamePtr   = T100NEW T100Game();
    m_gamePtr->SetConfigPtr(configPtr);

    m_scenePtr  = T100NEW T1003DEditorScene(m_gamePtr);

    m_scenePtr->SetSpace(1000, 1000, 1000);
    m_gamePtr->SetScenePtr(m_scenePtr);

    T1003DWindowHandle  handle;
    handle.HWND = hwnd;
    m_gamePtr->Create(handle, width, height);
}

T100VOID T100GameThread::Destroy()
{
    T100SAFE_DELETE m_gamePtr;
}

T100VOID T100GameThread::Start()
{
    m_gamePtr->Start();
    m_running       = T100TRUE;
    m_threadPtr     = T100NEW std::thread(&T100GameThread::run, this);
}

T100VOID T100GameThread::Stop()
{
    m_running   = T100FALSE;
    Waiting();
    m_gamePtr->Stop();
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
        m_gamePtr->Update();
        m_gamePtr->Render();
    }
    m_condition.notify_all();
}
