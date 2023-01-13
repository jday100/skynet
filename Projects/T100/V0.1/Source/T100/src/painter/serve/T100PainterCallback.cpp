#include "T100PainterCallback.h"

#include "T100PainterStore.h"
#include "T100PainterServe.h"
#include "T100PainterView.h"

#include "T100ElementBase.h"

#include "T100DiagramV1.h"
#include "T100DiagramInfo.h"

#include "T100TestTools.h"


namespace T100Painter{

T100PainterStore*       T100PainterCallback::m_store            = T100NULL;
T100PainterServe*       T100PainterCallback::m_serve            = T100NULL;
T100PainterView*        T100PainterCallback::m_view             = T100NULL;

T100Component::T100PainterTransverter        T100PainterCallback::m_manager;


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

T100PainterStore* T100PainterCallback::getStore()
{
    return m_store;
}

T100PainterServe* T100PainterCallback::getServe()
{
    return m_serve;
}

T100PainterView* T100PainterCallback::getView()
{
    return m_view;
}

T100BOOL T100PainterCallback::frame_menu_new(void* d)
{
    T100BOOL                result;
    T100STRING              file;
    T100DiagramInfo*        diagram         = T100NULL;

    result = m_serve->opened();
    if(result){
        if(result){
            result = m_store->close();
        }

        if(result){
            result = m_serve->close();
        }

        if(result){
            result = m_view->close();
        }
    }else{
        result = T100TRUE;
    }

    if(result){
        result = m_serve->NewFile(file, diagram);
    }

    if(result){
        result = m_view->LoadFile(diagram);
    }

    if(result){
        result = m_view->UpdateMenu();
    }

    return result;
}

T100BOOL T100PainterCallback::frame_menu_open(void* d)
{
    T100BOOL                result;
    T100STRING              file;
    T100DiagramInfo*        diagram         = T100NULL;

    result = m_serve->opened();
    if(result){
        if(result){
            result = m_store->close();
        }

        if(result){
            result = m_serve->close();
        }

        if(result){
            result = m_view->close();
        }
    }else{
        result = T100TRUE;
    }

    if(result){
        result = m_view->OpenFile(file);
    }

    if(result){
        result = m_store->OpenFile(file, diagram);
    }

    if(result){
        result = m_serve->OpenFile(diagram);
    }

    if(result){
        result = m_view->LoadFile(diagram);
    }

    return result;
}

T100BOOL T100PainterCallback::frame_menu_close(void* d)
{
    T100BOOL                result;

    result = m_serve->opened();
    if(result){
        if(result){
            result = m_store->close();
        }

        if(result){
            result = m_serve->close();
        }

        if(result){
            result = m_view->close();
        }
    }else{
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100PainterCallback::frame_menu_save(void* d)
{
    T100BOOL        result;
    T100STRING      file;
    T100PAINTER_ELEMENT_VECTOR*     elements            = T100NULL;


}

T100BOOL T100PainterCallback::frame_menu_save_as(void* d)
{
    T100BOOL                result;
    T100STRING              file;
    T100DiagramInfo*        diagram             = T100NULL;

    result = m_view->SaveAsFile(file);
    if(result){
        diagram = m_serve->getCurrent();
        if(!diagram){
            result = T100FALSE;
        }
    }

    if(result){
        result = m_store->SaveAsFile(file, diagram);
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

T100BOOL T100PainterCallback::frame_menu_properties(void* d)
{
    m_view->ShowProperties();
}

T100BOOL T100PainterCallback::frame_menu_about(void* d)
{

}

T100BOOL T100PainterCallback::serve_file_load(void* d)
{
    T100BOOL                result;
    T100STRING*             file            = T100NULL;
    T100DiagramInfo*        diagram         = T100NULL;

    file    = static_cast<T100STRING*>(d);
    if(file){
        result = T100TRUE;
    }else{
        result = T100FALSE;
    }

    if(result){
        result = m_store->OpenFile(*file, diagram);
    }

    if(result){
        result = m_serve->OpenFile(diagram);
    }

    if(result){
        result = m_view->LoadFile(diagram);
    }

    return result;
}

T100BOOL T100PainterCallback::serve_file_save(void* d)
{
    T100BOOL                result;
    T100STRING*             file            = T100NULL;
    T100DiagramInfo*        diagram         = T100NULL;

    file    = static_cast<T100STRING*>(d);
    if(file){
        result = T100TRUE;
    }else{
        result = T100FALSE;
    }

    diagram = m_serve->getCurrent();
    if(!diagram){
        result = T100FALSE;
    }

    if(result){
        result = m_store->SaveAsFile(*file, diagram);
    }

    return result;
}

T100BOOL T100PainterCallback::view_element_init(void* d)
{
    T100BOOL                result;
    T100ElementBase*        element         = T100NULL;

    element = static_cast<T100ElementBase*>(d);
    if(element){
        result = m_view->Append(element->getPanel().to_wstring(), element);
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
        if(result){
            m_view->getPaintCtrl()->Change(T100CANVAS_STATE_PAINT);
        }
    }
}

T100BOOL T100PainterCallback::canvas_mouse_left_down(void* d)
{
    wxMouseEvent*       event           = T100NULL;
    T100ElementBase*    current         = T100NULL;

    event   = static_cast<wxMouseEvent*>(d);
    if(!event)return T100FALSE;


    return T100TRUE;
}

T100BOOL T100PainterCallback::canvas_mouse_left_up(void* d)
{
    T100BOOL            result;
    wxMouseEvent*       event           = T100NULL;
    T100ElementBase*    current         = T100NULL;

    event   = static_cast<wxMouseEvent*>(d);
    if(!event)return T100FALSE;

    return T100TRUE;
}

T100BOOL T100PainterCallback::canvas_mouse_move(void* d)
{
    T100BOOL                result          = T100FALSE;
    wxMouseEvent*           event           = T100NULL;
    T100ElementManager*     manager         = T100NULL;
    T100ElementBase*        current         = T100NULL;

    event   = static_cast<wxMouseEvent*>(d);
    if(!event)return T100FALSE;

    manager = m_view->getElementManager();
    if(!manager)return T100FALSE;

    return result;
}

//////

T100BOOL T100PainterCallback::canvas_state_paint_paint(void* d)
{

}

T100BOOL T100PainterCallback::canvas_state_paint_mouse_left_down(void* d)
{
    wxMouseEvent*       event           = T100NULL;
    T100ElementBase*    current         = T100NULL;

    event   = static_cast<wxMouseEvent*>(d);
    if(!event)return T100FALSE;

    return T100TRUE;
}

T100BOOL T100PainterCallback::canvas_state_paint_mouse_left_up(void* d)
{
    T100BOOL            result;
    wxMouseEvent*       event           = T100NULL;
    T100ElementBase*    current         = T100NULL;

    event   = static_cast<wxMouseEvent*>(d);
    if(!event)return T100FALSE;

    return T100TRUE;
}

T100BOOL T100PainterCallback::canvas_state_paint_mouse_move(void* d)
{

}

T100BOOL T100PainterCallback::canvas_state_paint_mouse_left_dclick(void* d)
{

}

T100BOOL T100PainterCallback::canvas_state_selected_paint(void* d)
{

}

T100BOOL T100PainterCallback::canvas_state_selected_mouse_left_down(void* d)
{

}

T100BOOL T100PainterCallback::canvas_state_selected_mouse_left_up(void* d)
{

}

T100BOOL T100PainterCallback::canvas_state_selected_mouse_move(void* d)
{

}

T100BOOL T100PainterCallback::canvas_state_selected_mouse_left_dclick(void* d)
{

}

}
