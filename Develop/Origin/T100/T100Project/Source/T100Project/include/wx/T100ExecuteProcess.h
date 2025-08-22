#ifndef T100EXECUTEPROCESS_H
#define T100EXECUTEPROCESS_H

#include <atomic>
#include <wx/process.h>
#include "T100Common.h"

class T100ExecuteProcess : public wxProcess
{
    public:
        T100ExecuteProcess(wxArrayString*, wxArrayString*);
        virtual ~T100ExecuteProcess();

        T100VOID            FlushPipe();

        T100VOID            OnTerminate(T100INT, T100INT);

        T100BOOL            IsRunning();

        T100BOOL            ExitCode();

    protected:

    private:
        wxInputStream*      m_streamStdOut;
        wxInputStream*      m_streamStdErr;

        wxArrayString*      m_stdOut;
        wxArrayString*      m_stdErr;

        std::atomic_bool    m_running;
        T100INT             m_exitCode;

};

#endif // T100EXECUTEPROCESS_H
