#ifndef T1003DEDITORTHREAD_H
#define T1003DEDITORTHREAD_H

#include <atomic>
#include <thread>
#include "T100Common.h"
#include "T1003DEditor.h"

class T1003DEditorThread
{
    public:
        T1003DEditorThread();
        virtual ~T1003DEditorThread();

        T1003DEditor*           GetEditor();

        T100VOID                Create(HWND, T100UINT, T100UINT);
        T100VOID                Destroy();

        T100VOID                Start();
        T100VOID                Stop();

    protected:
        T1003DEditor*           m_editor        = T100NULL;

    private:
        std::atomic_bool        m_running;
        std::thread*            m_thread        = T100NULL;

        T100VOID                init();
        T100VOID                uninit();
        T100VOID                run();
};

#endif // T1003DEDITORTHREAD_H
