#include "T100Editor.h"

T100Editor::T100Editor()
{
    //ctor
    TurnOn();
}

T100Editor::~T100Editor()
{
    //dtor
    TurnOff();
}

T100VOID T100Editor::TurnOn()
{
    m_store     = T100NEW T100EditorStore();
    m_serve     = T100NEW T100EditorServe();
    m_view      = T100NEW T100EditorView();
}

T100VOID T100Editor::TurnOff()
{
    T100SAFE_DELETE(m_view)
    T100SAFE_DELETE(m_serve)
    T100SAFE_DELETE(m_store)
}

T100VOID T100Editor::SetStore(T100EditorStore* store)
{
    m_store     = store;
}

T100EditorStore* T100Editor::GetStore()
{
    return m_store;
}

T100VOID T100Editor::SetServe(T100EditorServe* serve)
{
    m_serve     = serve;
}

T100EditorServe* T100Editor::GetServe()
{
    return m_serve;
}

T100VOID T100Editor::SetView(T100EditorView* view)
{
    m_view      = view;
}

T100EditorView* T100Editor::GetView()
{
    return m_view;
}
