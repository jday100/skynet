#include "T1003DEditorCallback.h"

#include "T1003DEditorThread.h"
#include "T1003DEditorScene.h"

std::atomic_bool            T1003DEditorCallback::m_created;
T1003DEditorThread*         T1003DEditorCallback::m_thread          = T100NULL;

T1003DEditorCallback::T1003DEditorCallback()
{
    //ctor
}

T1003DEditorCallback::~T1003DEditorCallback()
{
    //dtor
}

T100VOID T1003DEditorCallback::Init()
{
    m_created   = T100FALSE;
    m_thread    = T100NEW T1003DEditorThread();
}

T100VOID T1003DEditorCallback::Uninit()
{
    T100SAFE_DELETE m_thread;
}

T100VOID T1003DEditorCallback::Create(HWND hwnd, T100UINT width, T100UINT height)
{
    m_thread->Create(hwnd, width, height);
    m_created   = T100TRUE;
    m_thread->Start();
}

T100VOID T1003DEditorCallback::Destroy()
{
    m_thread->Stop();
}

T100VOID T1003DEditorCallback::Resize(T100UINT width, T100UINT height)
{
    if(m_created)
    m_thread->GetEditor()->SetSize(width, height);
}

T100VOID T1003DEditorCallback::Render()
{
    m_thread->GetEditor()->Render();
}

T100VOID T1003DEditorCallback::KeyDown(T100UINT key)
{
    m_thread->GetEditor()->OnKeyDown(key);
}

T100VOID T1003DEditorCallback::KeyUp(T100UINT key)
{
    m_thread->GetEditor()->OnKeyUp(key);
}

T100VOID T1003DEditorCallback::MouseMove(T100Vector2u value)
{
    m_thread->GetEditor()->OnMouseMove(value);
}

T100VOID T1003DEditorCallback::Append(T100Entity* entity)
{
    m_thread->GetEditor()->Append(entity);
}

T100VOID T1003DEditorCallback::Clear()
{
    m_thread->GetEditor()->Clear();
}
