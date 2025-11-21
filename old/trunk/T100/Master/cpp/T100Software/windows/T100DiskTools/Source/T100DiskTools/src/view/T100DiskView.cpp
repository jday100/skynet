#include "T100DiskView.h"

T100DiskView::T100DiskView()
{
    //ctor
}

T100DiskView::~T100DiskView()
{
    //dtor
}

T100VOID T100DiskView::Create(T100Frame* frame)
{
    m_frame     = frame;

    m_mainMenu  = T100NEW T100DiskViewMainMenu();

    m_mainMenu->Create(m_frame);
}

T100VOID T100DiskView::Destroy()
{
    m_mainMenu->Destroy();
}
