#include "T100EditorCallback.h"

namespace T100Editor{

T100EditorServe*        T100EditorCallback::m_serve             = T100NULL;
T100EditorView*         T100EditorCallback::m_view              = T100NULL;


T100EditorCallback::T100EditorCallback()
{
    //ctor
}

T100EditorCallback::~T100EditorCallback()
{
    //dtor
}

T100VOID T100EditorCallback::init(T100EditorServe* serve, T100EditorView* view)
{
    m_serve     = serve;
    m_view      = view;
}

T100BOOL T100EditorCallback::frame_menu_new(void* d)
{

}

T100BOOL T100EditorCallback::frame_menu_open(void* d)
{

}

T100BOOL T100EditorCallback::frame_menu_close(void* d)
{

}

T100BOOL T100EditorCallback::frame_menu_save(void* d)
{

}

T100BOOL T100EditorCallback::frame_menu_save_as(void* d)
{

}

T100BOOL T100EditorCallback::frame_menu_quit(void* d)
{

}

T100BOOL T100EditorCallback::frame_menu_undo(void* d)
{

}

T100BOOL T100EditorCallback::frame_menu_redo(void* d)
{

}

T100BOOL T100EditorCallback::frame_menu_cut(void* d)
{

}

T100BOOL T100EditorCallback::frame_menu_copy(void* d)
{

}

T100BOOL T100EditorCallback::frame_menu_paste(void* d)
{

}

T100BOOL T100EditorCallback::frame_menu_search(void* d)
{

}

T100BOOL T100EditorCallback::frame_menu_replace(void* d)
{

}

T100BOOL T100EditorCallback::frame_menu_about(void* d)
{

}

}
