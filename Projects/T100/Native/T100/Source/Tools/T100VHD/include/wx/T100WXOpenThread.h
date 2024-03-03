#ifndef T100WXOPENTHREAD_H
#define T100WXOPENTHREAD_H

#include <wx/wx.h>
#include "T100WXRunThread.h"


class T100WXOpenThread : public T100WXRunThread
{
    public:
        T100WXOpenThread();
        virtual ~T100WXOpenThread();

        T100VOID                    setFileName(T100STRING);
        T100VOID                    setFrame(wxFrame*);

    protected:
        virtual T100VOID            run();

        T100BOOL                    load();

    private:
        T100STRING                  m_filename;
        wxFrame*                    m_frame         = T100NULL;
};

#endif // T100WXOPENTHREAD_H
