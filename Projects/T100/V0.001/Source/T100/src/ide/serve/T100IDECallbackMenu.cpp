#include "T100IDECallbackMenu.h"

#include "T100IDEStore.h"
#include "T100IDEServe.h"
#include "T100IDEView.h"

#include "T100EditorMenuNew.h"


T100IDECallbackMenu::T100IDECallbackMenu()
{
    //ctor
}

T100IDECallbackMenu::~T100IDECallbackMenu()
{
    //dtor
}

T100BOOL T100IDECallbackMenu::frame_menu_new(void* d)
{
    T100EditorMenuNew::run(m_serve, m_view);
    return T100FALSE;
}

T100BOOL T100IDECallbackMenu::frame_menu_open(void* d)
{
    return T100FALSE;
}

T100BOOL T100IDECallbackMenu::frame_menu_close(void* d)
{
    return T100FALSE;
}

T100BOOL T100IDECallbackMenu::frame_menu_quit(void* d)
{
    return T100FALSE;
}
