#include "T100EditorView.h"

#include "T100Editor.h"

T100EditorView::T100EditorView(T100Editor* editor)
    :m_editor(editor)
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
    m_frame             = T100NEW T100SceneEditorFrame(0);
    m_render            = T100NEW T100EditorRender(m_frame, wxID_ANY);
    m_entity_panel      = T100NEW T100SceneEditorEntityPanel(m_frame);

    m_render->SetEditor(m_editor);
    m_entity_panel->SetEditor(m_editor);

    //m_render->GetRender()->SetOrigin(100, 100, 100);
    m_frame->SetRender(m_render);
    m_frame->SetClientSize(800, 600);

    m_frame->AuiManager1->AddPane(m_entity_panel, wxAuiPaneInfo().Left());
    m_frame->AuiManager1->AddPane(m_render, wxAuiPaneInfo().CenterPane());
    m_frame->AuiManager1->Update();

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

T100Editor* T100EditorView::GetEditor()
{
    return m_editor;
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
