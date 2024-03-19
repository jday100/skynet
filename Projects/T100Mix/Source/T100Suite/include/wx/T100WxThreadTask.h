#ifndef T100WXTHREADTASK_H
#define T100WXTHREADTASK_H

#include <wx/window.h>
#include "task\T100ThreadTask.h"

class T100WxThreadTask : public T100ThreadTask
{
    public:
        T100WxThreadTask();
        virtual ~T100WxThreadTask();

        T100VOID            setWindow(wxWindow*);
        wxWindow*           getWindow();

    protected:

    private:
        wxWindow*           m_parent            = T100NULL;
};

#endif // T100WXTHREADTASK_H
