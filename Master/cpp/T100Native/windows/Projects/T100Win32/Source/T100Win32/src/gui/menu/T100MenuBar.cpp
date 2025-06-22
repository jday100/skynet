#include "T100MenuBar.h"

namespace T100WINDOWS{

T100MenuBar::T100MenuBar() :
    T100MenuBase()
{
    //ctor
    m_hmenu = CreateMenu();
}

T100MenuBar::~T100MenuBar()
{
    //dtor
    DestroyMenu(m_hmenu);
}

}
