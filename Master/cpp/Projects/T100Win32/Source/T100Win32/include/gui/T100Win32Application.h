#ifndef T100WIN32APPLICATION_H
#define T100WIN32APPLICATION_H

#include <windows.h>
#include "gui/event/T100IDManager.h"
#include "gui/apps/T100Win32ApplicationBase.h"

class T100Win32Application;

T100INT T100Win32ApplicationMessageLoop();
T100INT T100Runner(T100Win32Application&, HINSTANCE, HINSTANCE, LPSTR, T100INT);

class T100Win32Application : public T100Win32ApplicationBase
{
    public:
        T100Win32Application();
        virtual ~T100Win32Application();

        virtual T100VOID            Create();
        virtual T100VOID            Destroy();

        T100IDManager&              GetIDManager();

    protected:

    private:
        T100IDManager               m_idManager;
};

#endif // T100WIN32APPLICATION_H
