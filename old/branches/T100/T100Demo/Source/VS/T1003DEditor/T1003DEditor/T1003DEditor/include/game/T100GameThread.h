#ifndef T100GAMETHREAD_H
#define T100GAMETHREAD_H

#include <atomic>
#include <thread>
#include <condition_variable>
#include "T100Common.h"
#include "T100Game.h"

class T1003DEditorScene;

class T100GameThread
{
    public:
        T100GameThread();
        virtual ~T100GameThread();

        T100Game*                   GetGamePtr();
        T1003DEditorScene*          GetScenePtr();

        T100VOID                    Create(HWND, T100UINT, T100UINT);
        T100VOID                    Destroy();

        T100VOID                    Start();
        T100VOID                    Stop();
        T100VOID                    Waiting();

    protected:
        T100Game*                   m_gamePtr       = T100NULL;

    private:
        std::atomic_bool            m_running;
        std::mutex                  m_mutex;
        std::condition_variable     m_condition;
        std::thread*                m_threadPtr     = T100NULL;
        T1003DEditorScene*          m_scenePtr      = T100NULL;

        T100VOID                    init();
        T100VOID                    uninit();
        T100VOID                    run();
};

#endif // T100GAMETHREAD_H
