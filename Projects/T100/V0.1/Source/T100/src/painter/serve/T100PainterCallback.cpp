#include "T100PainterCallback.h"

#include "T100PainterStore.h"
#include "T100PainterServe.h"
#include "T100PainterView.h"

#include "T100ElementBase.h"

#include "T100DiagramV1.h"


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
    T100BOOL        result;
    T100STRING      file;
    T100PAINTER_ELEMENT_VECTOR*     elements            = T100NULL;


}

T100BOOL T100PainterCallback::frame_menu_save_as(void* d)
{
    T100BOOL        result;
    T100STRING      file;
    T100DiagramV1*                  diagram             = T100NULL;
    T100PAINTER_ELEMENT_VECTOR*     elements            = T100NULL;

    result = m_view->SaveAsFile(file);
    if(result){
        elements = m_serve->GetElements();
        if(!elements){
            result = T100FALSE;
        }
    }

    if(result){
        diagram     = T100NEW T100DiagramV1();
        result      = m_store->SaveAsFile(file, elements, diagram);
        T100SAFE_DELETE(diagram);
    }

    return result;
}

T100BOOL T100PainterCallback::frame_menu_quit(void* d)
{
    m_view->Quit();
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

T100BOOL T100PainterCallback::frame_menu_elements(void* d)
{
    m_view->ShowElements();
}

T100BOOL T100PainterCallback::frame_menu_about(void* d)
{

}

T100BOOL T100PainterCallback::view_element_init(void* d)
{
    T100BOOL                result;
    T100ElementBase*        element         = T100NULL;

    element = static_cast<T100ElementBase*>(d);
    if(element){
        result = m_view->Append(wxT("Elements"), element);
    }
    return result;
}

T100BOOL T100PainterCallback::view_element_select(void* d)
{
    T100BOOL        result;
    T100STRING*     key             = T100NULL;

    key = static_cast<T100STRING*>(d);

    if(key){
        result = m_view->getElementManager()->Select(*key);
    }
}

T100BOOL T100PainterCallback::canvas_mouse_left_down(void* d)
{
    wxMouseEvent*       event           = T100NULL;
    T100ElementBase*    current         = T100NULL;

    event   = static_cast<wxMouseEvent*>(d);
    if(!event)return T100FALSE;

    current = m_view->getElementManager()->GetCurrent();

    if(current){
        current->MouseLeftDown(event->GetPosition().x, event->GetPosition().y);
    }

    return T100TRUE;
}

T100BOOL T100PainterCallback::canvas_mouse_left_up(void* d)
{
    T100BOOL            result;
    wxMouseEvent*       event           = T100NULL;
    T100ElementBase*    current         = T100NULL;

    event   = static_cast<wxMouseEvent*>(d);
    if(!event)return T100FALSE;

    current = m_view->getElementManager()->GetCurrent();

    if(current){
        result = current->MouseLeftUp(event->GetPosition().x, event->GetPosition().y);
        if(result){
            m_serve->GetElements()->append(current->Clone());
            m_view->getPaintCtrl()->Refresh();
        }
    }

    return T100TRUE;
}

T100BOOL T100PainterCallback::canvas_mouse_moving(void* d)
{
    T100ElementBase*    current         = T100NULL;

    current = m_view->getElementManager()->GetCurrent();

    if(current){
        current->MouseMoving();
    }

    return T100TRUE;
}

}
