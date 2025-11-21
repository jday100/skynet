#ifndef T1003DEDITORCALLBACK_H
#define T1003DEDITORCALLBACK_H

#include <atomic>
#include <windows.h>
#include "T100Common.h"
#include "T100Vector2u.h"

class T100Entity;
class T1003DEditorThread;

class T1003DEditorCallback
{
    public:
        T1003DEditorCallback();
        virtual ~T1003DEditorCallback();

        static T100VOID                 Init();
        static T100VOID                 Uninit();

        static T100VOID                 Create(HWND, T100UINT, T100UINT);
        static T100VOID                 Destroy();

        static T100VOID                 Resize(T100UINT, T100UINT);
        static T100VOID                 Render();
        static T100VOID                 KeyDown(T100UINT);
        static T100VOID                 KeyUp(T100UINT);
        static T100VOID                 MouseMove(T100Vector2u);

        static T100VOID                 Append(T100Entity*);

        static T100VOID                 Clear();

    protected:
        static std::atomic_bool         m_created;
        static T1003DEditorThread*      m_thread;

    private:
};

#endif // T1003DEDITORCALLBACK_H
