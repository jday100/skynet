#ifndef T100WXTHREADTASK_H
#define T100WXTHREADTASK_H

#include <thread>
#include <functional>
#include <wx/window.h>
#include "T100WxEventData.h"

class T100WxThreadTask
{
    public:
        T100WxThreadTask();
        virtual ~T100WxThreadTask();

        T100VOID                        start();
        T100VOID                        stop();

        T100VOID                        setWindow(wxWindow*);
        wxWindow*                       getWindow();

    protected:
        virtual T100VOID                run() = 0;

        T100VOID                        sendEvent(wxThreadEvent&, T100WxEventData* = T100NULL);

    private:
        wxWindow*                       m_parent            = T100NULL;

        std::function<void()>           m_method;
        std::thread*                    m_thread            = T100NULL;
};

#endif // T100WXTHREADTASK_H
