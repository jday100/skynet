#include "T100CVMView.h"

T100CVMView::T100CVMView()
{
    //ctor
}

T100CVMView::~T100CVMView()
{
    //dtor
}

T100VOID T100CVMView::Create(T100Frame* frame)
{
    m_frame     = frame;
    m_mainMenu  = T100NEW T100CVMViewMainMenu(m_frame);

    m_mainMenu->Create();
}

T100VOID T100CVMView::Destroy()
{
    m_mainMenu->Destroy();

    T100SAFE_DELETE(m_mainMenu);
}
