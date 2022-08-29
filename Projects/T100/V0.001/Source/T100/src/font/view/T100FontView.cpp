#include "T100FontView.h"

T100FontView::T100FontView()
{
    //ctor
}

T100FontView::~T100FontView()
{
    //dtor
    destroy();
}

T100VOID T100FontView::create()
{
    m_frame = T100NEW T100FontFrame(T100NULL);
}

T100VOID T100FontView::destroy()
{
    if(m_frame){
        T100DELETE(m_frame);
    }
}

T100VOID T100FontView::setFrame(T100FontFrame* frame)
{
    m_frame = frame;
}

T100FontFrame* T100FontView::getFrame()
{
    return m_frame;
}

T100BOOL T100FontView::show()
{
    if(m_frame){
        return m_frame->Show();
    }
    return T100FALSE;
}

T100BOOL T100FontView::start()
{
    return T100FALSE;
}
