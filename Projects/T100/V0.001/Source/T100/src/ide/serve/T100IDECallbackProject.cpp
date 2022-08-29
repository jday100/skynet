#include "T100IDECallbackProject.h"

#include "T100IDEStore.h"
#include "T100IDEServe.h"
#include "T100IDEView.h"


T100IDECallbackProject::T100IDECallbackProject()
{
    //ctor
}

T100IDECallbackProject::~T100IDECallbackProject()
{
    //dtor
}

T100BOOL T100IDECallbackProject::frame_menu_new(void* d)
{
    m_serve->getProject()->create();

    m_view->getManager()->create_child(T100NULL);

    return T100FALSE;
}

T100BOOL T100IDECallbackProject::frame_menu_open(void* d)
{
    return T100FALSE;
}

T100BOOL T100IDECallbackProject::frame_menu_close(void* d)
{
    return T100FALSE;
}

T100BOOL T100IDECallbackProject::frame_menu_quit(void* d)
{
    return m_view->quit();
}
