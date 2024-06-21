#include "T100EditorView.h"

T100EditorView::T100EditorView()
{
    //ctor
    TurnOn();
}

T100EditorView::~T100EditorView()
{
    //dtor
    TurnOff();
}

T100VOID T100EditorView::TurnOn()
{
    m_frame     = T100NEW T100SceneEditorFrame(0);
    m_render    = T100NEW T100EditorRender(m_frame, wxID_ANY);

    m_frame->SetRender(m_render);
    m_frame->SetClientSize(800, 600);

}

T100VOID T100EditorView::TurnOff()
{
    T100SAFE_DELETE(m_frame)
}

T100VOID T100EditorView::Show()
{
    if(m_frame){
        m_frame->Show();
    }
}

T100SceneEditorFrame* T100EditorView::GetFrame()
{
    if(m_frame){
        return m_frame;
    }
    return T100NULL;
}

T100EditorRender* T100EditorView::GetRender()
{
    if(m_render){
        return m_render;
    }
    return T100NULL;
}
