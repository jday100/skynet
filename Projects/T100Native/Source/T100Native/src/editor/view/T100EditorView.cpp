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
    m_frame = T100NEW T100SceneEditorFrame(0);
}

T100VOID T100EditorView::TurnOff()
{

}

T100VOID T100EditorView::Show()
{
    if(m_frame){
        m_frame->Show();
    }
}
