#include "T1003DEditorThread.h"

T1003DEditorThread::T1003DEditorThread()
{
    //ctor
    init();
}

T1003DEditorThread::~T1003DEditorThread()
{
    //dtor
    uninit();
}

T100VOID T1003DEditorThread::init()
{
    m_running   = T100FALSE;
}

T100VOID T1003DEditorThread::uninit()
{

}

T1003DEditor* T1003DEditorThread::GetEditor()
{
    return m_editor;
}

T100VOID T1003DEditorThread::Create(HWND hwnd, T100UINT width, T100UINT height)
{
    m_editor    = T100NEW T1003DEditor();
    m_editor->Create(hwnd, width, height);
}

T100VOID T1003DEditorThread::Destroy()
{
    T100SAFE_DELETE m_editor;
}

T100VOID T1003DEditorThread::Start()
{
    m_editor->Start();
    m_running   = T100TRUE;
    m_thread    = T100NEW std::thread(&T1003DEditorThread::run, this);
}

T100VOID T1003DEditorThread::Stop()
{
    m_editor->Stop();
}

T100VOID T1003DEditorThread::run()
{
    while(m_running){
        m_editor->Render();
    }
}
