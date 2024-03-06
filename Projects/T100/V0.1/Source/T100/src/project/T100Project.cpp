#include "T100Project.h"

#include "T100ProjectStore.h"
#include "T100ProjectServe.h"
#include "T100ProjectView.h"
#include "T100ProjectCallback.h"
#include "T100ProjectApp.h"


namespace T100PROJECT{

T100Project::T100Project(T100ProjectApp* app)
    :m_app(app)
{
    //ctor
}

T100Project::~T100Project()
{
    //dtor
    destroy();
}


T100BOOL T100Project::create()
{
    m_store     = T100NEW T100ProjectStore();
    m_serve     = T100NEW T100ProjectServe();
    m_view      = T100NEW T100ProjectView();

    m_view->setParent(m_parent);
    m_view->setRootFrame(m_root);

    T100ProjectCallback::init(m_store, m_serve, m_view);

    if(m_parent){
        m_transverter.Change(T100PROJECT_STATE_EMBED);
    }else{
        m_transverter.Change(T100PROJECT_STATE_ALONE);
    }

    return m_transverter.GetCurrent()->Create();
}

T100VOID T100Project::destroy()
{
    T100SAFE_DELETE(m_view);
    T100SAFE_DELETE(m_serve);
    T100SAFE_DELETE(m_store);
}

T100VOID T100Project::reset()
{
    T100ProjectCallback::init(m_store, m_serve, m_view);
}

T100VOID T100Project::setStore(T100ProjectStore* store)
{
    m_store     = store;
}

T100ProjectStore* T100Project::getStore()
{
    return m_store;
}

T100VOID T100Project::setServe(T100ProjectServe* serve)
{
    m_serve     = serve;
}

T100ProjectServe* T100Project::getServe()
{
    return m_serve;
}

T100VOID T100Project::setView(T100ProjectView* view)
{
    m_view      = view;
}

T100ProjectView* T100Project::getView()
{
    return m_view;
}

T100VOID T100Project::show()
{
    if(m_view){
        m_view->show();
    }
}

T100VOID T100Project::quit()
{

}

T100VOID T100Project::NewFile()
{
    //T100ProjectCallback::frame_menu_new();
}

T100VOID T100Project::setParent(wxFrame* parent)
{
    m_parent = parent;
}

T100VOID T100Project::setRootFrame(wxMDIParentFrame* root)
{
    m_root = root;
}

}
