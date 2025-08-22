#include "T100ExecuteProcess.h"

#include <wx/txtstrm.h>

T100ExecuteProcess::T100ExecuteProcess(wxArrayString* out, wxArrayString* err) :
    wxProcess(),
    m_stdOut(out),
    m_stdErr(err)
{
    //ctor
    m_running   = T100FALSE;

    Redirect();
}

T100ExecuteProcess::~T100ExecuteProcess()
{
    //dtor
}

T100VOID T100ExecuteProcess::FlushPipe()
{
    wxString        line;
    m_streamStdOut  = GetInputStream();
    m_streamStdErr  = GetErrorStream();

    if(m_streamStdOut && m_streamStdErr){
        wxTextInputStream   thisStreamStdOut(*m_streamStdOut);
        wxTextInputStream   thisStreamStdErr(*m_streamStdErr);

        while(!m_streamStdOut->Eof()){
            line    = thisStreamStdOut.ReadLine();
            m_stdOut->Add(line);
        }

        if(m_stdErr){
            while(!m_streamStdErr->Eof()){
                line    = thisStreamStdErr.ReadLine();
                m_stdErr->Add(line);
            }
        }
    }
}

T100VOID T100ExecuteProcess::OnTerminate(T100INT pid, T100INT status)
{
    FlushPipe();
    m_exitCode  = status;
    m_running   = T100FALSE;
}

T100BOOL T100ExecuteProcess::IsRunning()
{
    return m_running;
}

T100BOOL T100ExecuteProcess::ExitCode()
{
    return m_exitCode;
}
