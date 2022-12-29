#include "T100PainterCallback.h"

#include "T100PainterStore.h"
#include "T100PainterServe.h"
#include "T100PainterView.h"


namespace T100Painter{

T100PainterStore*       T100PainterCallback::m_store            = T100NULL;
T100PainterServe*       T100PainterCallback::m_serve            = T100NULL;
T100PainterView*        T100PainterCallback::m_view             = T100NULL;


T100PainterCallback::T100PainterCallback()
{
    //ctor
}

T100PainterCallback::~T100PainterCallback()
{
    //dtor
}

T100VOID T100PainterCallback::init(T100PainterStore* store, T100PainterServe* serve, T100PainterView* view)
{
    m_store     = store;
    m_serve     = serve;
    m_view      = view;
}

T100BOOL T100PainterCallback::frame_menu_new(void* d)
{
    T100BOOL        result;
    T100STRING      file;
    T100PAINTER_ELEMENT_VECTOR*     elements            = T100NULL;

    result = m_serve->NewFile(file, elements);
    if(result){
        result = m_view->LoadFile(elements);
    }

    return result;
}

T100BOOL T100PainterCallback::frame_menu_open(void* d)
{
    T100BOOL        result;
    T100STRING      file;
    T100PAINTER_ELEMENT_VECTOR*     elements            = T100NULL;

    result = m_view->OpenFile(file);
    if(result){
        result = m_serve->OpenFile(file, elements);
    }

    if(result){
        result = m_store->OpenFile(file, elements);
    }

    if(result){
        result = m_view->LoadFile(elements);
    }

    return result;
}

T100BOOL T100PainterCallback::frame_menu_close(void* d)
{

}

T100BOOL T100PainterCallback::frame_menu_save(void* d)
{

}

T100BOOL T100PainterCallback::frame_menu_save_as(void* d)
{

}

T100BOOL T100PainterCallback::frame_menu_quit(void* d)
{

}

T100BOOL T100PainterCallback::frame_menu_undo(void* d)
{

}

T100BOOL T100PainterCallback::frame_menu_redo(void* d)
{

}

T100BOOL T100PainterCallback::frame_menu_cut(void* d)
{

}

T100BOOL T100PainterCallback::frame_menu_copy(void* d)
{

}

T100BOOL T100PainterCallback::frame_menu_paste(void* d)
{

}

T100BOOL T100PainterCallback::frame_menu_about(void* d)
{

}

}
