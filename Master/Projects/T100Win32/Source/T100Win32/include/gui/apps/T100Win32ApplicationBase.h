#ifndef T100WIN32APPLICATIONBASE_H
#define T100WIN32APPLICATIONBASE_H

#include "gui/event/T100EventHandler.h"
#include "gui/event/T100WindowMessageDispatcher.h"

class T100Frame;

#define     T100WINDOW_CLASS_HASH                   std::unordered_map<T100WSTRING, T100BOOL>

class T100Win32ApplicationBase : public T100EventHandler
{
    public:
        T100Win32ApplicationBase();
        virtual ~T100Win32ApplicationBase();

        T100VOID                                SetThisInstance(HINSTANCE);
        HINSTANCE                               GetThisInstance();

        T100VOID                                SetFrame(T100Frame*);
        T100Frame*                              GetFramePtr();

        T100WindowMessageDispatcher&            GetWindowMessageDispatcher();

        T100BOOL                                RegisterWindowClass(T100WSTRING);

        virtual T100VOID                        Create() = 0;
        virtual T100VOID                        Destroy() = 0;

    protected:
        HINSTANCE                               m_thisInstance;
        T100Frame*                              m_framePtr          = T100NULL;

        T100WindowMessageDispatcher             m_windowMessageDispatcher;

    private:
        T100WINDOW_CLASS_HASH                   m_windowClass;
};

#endif // T100WIN32APPLICATIONBASE_H
