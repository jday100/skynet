#ifndef T100APPLICATIONEVENTHANDLER_H
#define T100APPLICATIONEVENTHANDLER_H

#include "gui/event/T100EventHandler.h"
#include "gui/event/T100IDManager.h"
#include "gui/event/T100WindowMessageDispatcher.h"

class T100Frame;

#define     T100WINDOW_CLASS_HASH                   std::unordered_map<T100WSTRING, T100BOOL>

class T100ApplicationEventHandler : public T100EventHandler
{
    public:
        T100ApplicationEventHandler();
        virtual ~T100ApplicationEventHandler();

        T100VOID                                SetThisInstance(HINSTANCE);
        HINSTANCE                               GetThisInstance();

        T100VOID                                SetFrame(T100Frame*);
        T100Frame*                              GetFramePtr();

        T100IDManager&                          GetIDManager();
        T100WindowMessageDispatcher&            GetWindowMessageDispatcher();
        T100BOOL                                IsRegistered(T100WSTRING);
        T100BOOL                                RegisterWindowClass(T100WSTRING);

        virtual T100VOID                        Create() = 0;
        virtual T100VOID                        Destroy() = 0;

    protected:
        HINSTANCE                               m_thisInstance;
        T100Frame*                              m_framePtr          = T100NULL;

        T100IDManager                           m_idManager;
        T100WindowMessageDispatcher             m_messageDispatcher;

    private:
        T100WINDOW_CLASS_HASH                   m_windowClass;
        T100WINDOW_CLASS_HASH                   m_systemClass;

        T100VOID                                init();
        T100VOID                                uninit();
};

#endif // T100APPLICATIONEVENTHANDLER_H
