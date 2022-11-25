#include "T100FontView.h"

#include "T100FontFrame.h"


namespace T100FontBuilder{

T100FontView::T100FontView()
{
    //ctor
    create();
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
    T100SAFE_DELETE(m_frame);
}

T100FontFrame* T100FontView::getFrame()
{
    return m_frame;
}

T100BOOL T100FontView::init()
{

}

T100BOOL T100FontView::show()
{
    if(m_frame){
        return m_frame->Show();
    }
    return T100FALSE;
}

T100BOOL T100FontView::quit()
{
    if(m_frame){
        return m_frame->Close();
    }
    return T100FALSE;
}

}
