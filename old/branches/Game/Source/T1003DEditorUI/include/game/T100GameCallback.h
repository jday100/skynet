#ifndef T100GAMECALLBACK_H
#define T100GAMECALLBACK_H

#include <atomic>
#include <windows.h>
#include "T100Common.h"

class T100Scene;
class T100Light;
class T100Entity;
class T100GameScene;
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

        static T100VOID                 SetBundle(T100Entity*);

        static T100VOID                 Append(T100Entity*);
        static T100VOID                 Remove(T100Entity*);
        static T100VOID                 Position(T100UINT, T100UINT, T100FLOAT);
        static T100VOID                 Rotation(T100INT, T100INT);

        static T100VOID                 AppendLight(T100Light*);
        static T100VOID                 RemoveLight(T100Light*);

        static T100VOID                 OnKeyDown(T100INT);
        static T100VOID                 OnKeyUp(T100INT);

        static T100VOID                 Clear();
        static T100VOID                 Visible();
        static T100VOID                 UpdateInfo(T100WSTRING&);
        static T100VOID                 Update(T100WSTRING&);
        static T100VOID                 UpdateScene(T100Scene*);

    protected:

    private:
        static std::atomic_bool         m_created;
        static T100GameThread*          m_thread;
        static T100GameScene*           m_scene;
};

#endif // T100GAMECALLBACK_H
