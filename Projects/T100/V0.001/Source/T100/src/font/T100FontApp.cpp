#include "T100FontApp.h"

T100FontApp::T100FontApp()
{
    //ctor
    create();
}

T100FontApp::~T100FontApp()
{
    //dtor
    destroy();
}

T100VOID T100FontApp::create()
{
    m_serve     = T100NEW T100FontServe;
    m_view      = T100NEW T100FontView;

    m_view->setServe(m_serve);
    m_view->create();
}

T100VOID T100FontApp::destroy()
{
    T100DELETE(m_view);
    T100DELETE(m_serve);
}

T100BOOL T100FontApp::show()
{
    if(m_view){
        return m_view->show();
    }
    return T100FALSE;
}

wxFrame* T100FontApp::getFrame()
{
    if(m_view){
        T100FontView* view   = T100NULL;
        view = dynamic_cast<T100FontView*>(m_view);
        if(view){
            return view->getFrame();
        }
    }
    return T100NULL;
}

T100VOID T100FontApp::setServe(IServe* serve)
{
    m_serve = serve;
}

IServe* T100FontApp::getServe()
{
    return m_serve;
}

T100VOID T100FontApp::setView(IView* view)
{
    m_view = view;
}

IView* T100FontApp::getView()
{
    return m_view;
}

T100BOOL T100FontApp::run(T100STDSTRING file)
{
    T100FontView* view       = T100NULL;

    view = dynamic_cast<T100FontView*>(m_view);
    if(view){
        view->start();
    }

    return T100FALSE;
}

