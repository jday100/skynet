#ifndef T100WIN32APPLICATION_H
#define T100WIN32APPLICATION_H

#include "gui/T100Frame.h"
#include "gui/handler/T100IDManager.h"
#include "gui/handler/T100WindowMessageDispatcher.h"

using namespace T100LIBRARY;

namespace T100WINDOWS{

#define     T100WINDOW_CLASS_HASH                   std::unordered_map<T100WSTRING, T100BOOL>

T100INT     T100Win32MessageLoop();
T100INT     T100Runner(T100Win32Application&, HINSTANCE, HINSTANCE, LPSTR, T100INT);

class T100Win32Application : public T100EventHandler
{
    public:
        T100Win32Application();
        virtual ~T100Win32Application();

        virtual T100VOID                    Create();
        virtual T100VOID                    Destroy();

        T100VOID                            SetInstance(HINSTANCE);
        HINSTANCE                           GetInstance();

        T100VOID                            SetFrame(T100Frame*);
        T100Frame*                          GetFrame();

        T100IDManager&                      GetIDManager();
        T100WindowMessageDispatcher&        GetWindowMessageDispatcher();
        T100BOOL                            IsRegistered(const T100WSTRING&);
        T100BOOL                            RegisterWindowClass(const T100WSTRING&);

    protected:
        HINSTANCE                           m_instance;
        T100Frame*                          m_frame         = T100NULL;
        T100IDManager                       m_idManager;
        T100WindowMessageDispatcher         m_dispatcher;

    private:
        T100WINDOW_CLASS_HASH               m_windowClass;
        T100WINDOW_CLASS_HASH               m_systemClass;

        T100VOID                            init();
        T100VOID                            uninit();
};

}

#endif // T100WIN32APPLICATION_H
