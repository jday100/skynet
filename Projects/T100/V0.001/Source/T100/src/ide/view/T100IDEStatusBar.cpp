#include "T100IDEStatusBar.h"

T100IDEStatusBar::T100IDEStatusBar(wxFrame* frame)
    :m_frame(frame)
{
    //ctor
}

T100IDEStatusBar::~T100IDEStatusBar()
{
    //dtor
    destroy();
}

T100BOOL T100IDEStatusBar::create()
{
    return T100FALSE;
}

T100VOID T100IDEStatusBar::destroy()
{

}
