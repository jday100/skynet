#include "T1003DEditorView.h"

#include "T1003DEditorMainPanel.h"
#include "T1003DEditorEntityPanel.h"

T1003DEditorView::T1003DEditorView(T1003DEditorFrame* frame)
    :m_frame(frame)
{
    //ctor
    create();
}

T1003DEditorView::~T1003DEditorView()
{
    //dtor
    destroy();
}

T100VOID T1003DEditorView::create()
{
    m_manager       = T100NEW wxAuiManager((wxWindow*)m_frame);
    m_entity_panel  = T100NEW T1003DEditorEntityPanel((wxWindow*)m_frame);
    m_main          = T100NEW T1003DEditorMainPanel((wxWindow*)m_frame);

    m_manager->AddPane(m_entity_panel, wxAuiPaneInfo().BestSize(300, -1));
    m_manager->AddPane(m_main, wxAuiPaneInfo().CloseButton(T100FALSE).Center());


    m_manager->Update();
}

T100VOID T1003DEditorView::destroy()
{
    T100SAFE_DELETE m_entity_panel;

    m_manager->UnInit();
    T100SAFE_DELETE m_manager;
}

T100VOID T1003DEditorView::setEditor(T1003DEditor* editor)
{
    m_editor    = editor;

    m_main->setEditor(editor);
}

wxPanel* T1003DEditorView::getPanel()
{
    return m_main;
}
