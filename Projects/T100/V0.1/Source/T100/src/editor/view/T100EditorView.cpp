#include "T100EditorView.h"

#include "T100EditorFrame.h"

namespace T100Editor{

T100EditorView::T100EditorView()
{
    //ctor
    create();
}

T100EditorView::~T100EditorView()
{
    //dtor
    destroy();
}

T100VOID T100EditorView::create()
{
    m_frame     = T100NEW T100EditorFrame(T100NULL);

}

T100VOID T100EditorView::destroy()
{

}

T100VOID T100EditorView::show()
{
    if(m_frame){
        m_frame->Show();
    }
}

}
