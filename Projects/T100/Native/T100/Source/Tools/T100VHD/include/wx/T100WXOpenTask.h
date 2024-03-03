#ifndef T100WXOPENTASK_H
#define T100WXOPENTASK_H

#include <wx/wx.h>
#include "T100WXTask.h"
#include "T100WXOpenThread.h"


class T100WXOpenTask : public T100WXTask
{
    public:
        T100WXOpenTask();
        virtual ~T100WXOpenTask();

        virtual T100BOOL            run();

        T100VOID                    setFileName(T100STRING);
        T100VOID                    setFrame(wxFrame*);

    protected:

    private:
        T100STRING                  m_filename;
        wxFrame*                    m_frame         = T100NULL;
        T100WXOpenThread*           m_thread        = T100NULL;
};

#endif // T100WXOPENTASK_H
