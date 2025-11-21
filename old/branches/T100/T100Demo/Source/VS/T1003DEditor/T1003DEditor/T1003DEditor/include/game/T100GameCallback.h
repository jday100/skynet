#ifndef T100GAMECALLBACK_H
#define T100GAMECALLBACK_H

#include <atomic>
#include <windows.h>
#include "T100Common.h"

class T100Entity;
class T100GameThread;

class T100GameCallback
{
    public:
        T100GameCallback();
        virtual ~T100GameCallback();

        static T100VOID                 Init();
        static T100VOID                 Uninit();

        static T100VOID                 Create(HWND, T100UINT, T100UINT);
        static T100VOID                 Destroy();

        static T100VOID                 Append(T100Entity*);
        static T100VOID                 Remove(T100Entity*);
        static T100VOID                 Clear();

        static T100VOID                 Visible();

        static T100VOID                 Update();

        static T100VOID                 OnKeyDown(T100INT);
        static T100VOID                 OnKeyUp(T100INT);

        static T100VOID                 Position(T100FLOAT, T100FLOAT, T100FLOAT, T100WSTRING&);
        static T100VOID                 Rotation(T100FLOAT, T100FLOAT);

        static T100VOID                 UpdateInfo(T100UINT&);
        static T100VOID                 UpdateInfo(T100WSTRING&);

        static T100VOID                 SetBundle(T100Entity*);

    protected:

    private:
        static std::atomic_bool         m_created;
        static T100GameThread*          m_threadPtr;
};

#endif // T100GAMECALLBACK_H
