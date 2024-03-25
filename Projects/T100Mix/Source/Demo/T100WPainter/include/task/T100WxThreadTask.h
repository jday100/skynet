#ifndef T100WXTHREADTASK_H
#define T100WXTHREADTASK_H

#include <wx/event.h>
#include "T100ThreadTask.h"


class T100WxThreadTask : public T100ThreadTask
{
    public:
        T100WxThreadTask();
        virtual ~T100WxThreadTask();

        T100VOID                setEvtHandler(wxEvtHandler*);

    protected:
        T100VOID                send(wxThreadEvent&);

    private:
        wxEvtHandler*           m_handler           = T100NULL;
};

#endif // T100WXTHREADTASK_H
