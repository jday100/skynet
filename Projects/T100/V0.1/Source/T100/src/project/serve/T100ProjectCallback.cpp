#include "T100ProjectCallback.h"

#include <wx/log.h>

#include "T100ProjectStore.h"
#include "T100ProjectServe.h"
#include "T100ProjectView.h"

namespace T100PROJECT{

T100ProjectStore*       T100ProjectCallback::m_store            = T100NULL;
T100ProjectServe*       T100ProjectCallback::m_serve            = T100NULL;
T100ProjectView*        T100ProjectCallback::m_view             = T100NULL;

T100Component::T100ProjectTransverter           T100ProjectCallback::m_manager;

T100ProjectCallback::T100ProjectCallback()
{
    //ctor
}

T100ProjectCallback::~T100ProjectCallback()
{
    //dtor
}


T100VOID T100ProjectCallback::init(T100ProjectStore* store, T100ProjectServe* serve, T100ProjectView* view)
{
    m_store     = store;
    m_serve     = serve;
    m_view      = view;
}

T100ProjectStore* T100ProjectCallback::getStore()
{
    return m_store;
}

T100ProjectServe* T100ProjectCallback::getServe()
{
    return m_serve;
}

T100ProjectView* T100ProjectCallback::getView()
{
    return m_view;
}


T100BOOL T100ProjectCallback::frame_menu_new(void* d)
{
    /*
    T100BOOL                result;
    T100STRING              file;
    T100DiagramInfo*        diagram         = T100NULL;

    result = m_serve->opened();
    if(result){
        if(result){
            result = m_serve->CloseFile();
        }

        if(result){
            result = m_view->CloseFile();
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
    */
}

T100BOOL T100ProjectCallback::frame_menu_open(void* d)
{
    /*
    T100BOOL                result;
    T100STRING              file;
    T100DiagramInfo*        diagram         = T100NULL;

    result = m_serve->opened();
    if(result){
        if(result){
            result = m_serve->CloseFile();
        }

        if(result){
            result = m_view->CloseFile();
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
        result = m_serve->OpenFile(file, diagram);
    }

    if(result){
        result = m_view->LoadFile(diagram);
    }

    if(result){
        result = m_view->UpdateMenu();
    }

    return result;
    */
}

T100BOOL T100ProjectCallback::frame_menu_close(void* d)
{
    T100BOOL                result;
    /*
    result = m_serve->opened();
    if(result){
        if(result){
            result = m_view->CloseFile();
        }

        if(result){
            result = m_serve->CloseFile();
        }
    }else{
        result = T100FALSE;
    }

    if(result){
        m_view->getPaintCtrl()->Refresh();
    }
    */
    return result;
}

T100BOOL T100ProjectCallback::frame_menu_save(void* d)
{
    /*
    T100BOOL                result;
    T100STRING              file;
    T100DiagramInfo*        diagram             = T100NULL;

    result = m_serve->opened();
    if(!result)return T100FALSE;

    diagram = m_serve->getCurrent();
    if(!diagram)return T100FALSE;

    file    = diagram->getFile();

    if(result){
        result = m_store->SaveAsFile(file, diagram);
    }

    return result;
    */
}

T100BOOL T100ProjectCallback::frame_menu_save_as(void* d)
{
    /*
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
    */
}

T100BOOL T100ProjectCallback::frame_menu_quit(void* d)
{
    m_view->Quit();
    return T100FALSE;
}

T100BOOL T100ProjectCallback::frame_menu_undo(void* d)
{
    return T100FALSE;
}

T100BOOL T100ProjectCallback::frame_menu_redo(void* d)
{
    return T100FALSE;
}

T100BOOL T100ProjectCallback::frame_menu_cut(void* d)
{
    return T100FALSE;
}

T100BOOL T100ProjectCallback::frame_menu_copy(void* d)
{
    return T100FALSE;
}

T100BOOL T100ProjectCallback::frame_menu_paste(void* d)
{
    return T100FALSE;
}

T100BOOL T100ProjectCallback::frame_menu_projects(void* d)
{
    m_view->ShowProjects();
    return T100TRUE;
}

T100BOOL T100ProjectCallback::frame_menu_about(void* d)
{
    return T100TRUE;
}

}
