#include "T100VDiskApp.h"

T100VDiskApp::T100VDiskApp()
{
    //ctor
    create();
}

T100VDiskApp::~T100VDiskApp()
{
    //dtor
    destroy();
}

T100VOID T100VDiskApp::create()
{
    m_serve     = T100NEW T100VDiskServe;
    m_view      = T100NEW T100VDiskView;

    m_view->setServe(m_serve);
    m_view->create();
}

T100VOID T100VDiskApp::destroy()
{
    T100DELETE(m_view);
    T100DELETE(m_serve);
}

T100BOOL T100VDiskApp::show()
{
    if(m_view){
        return m_view->show();
    }
    return T100FALSE;
}

wxFrame* T100VDiskApp::getFrame()
{
    if(m_view){
        T100VDiskView* view   = T100NULL;
        view = dynamic_cast<T100VDiskView*>(m_view);
        if(view){
            return view->getFrame();
        }
    }
    return T100NULL;
}

T100VOID T100VDiskApp::setServe(IServe* serve)
{
    m_serve = serve;
}

IServe* T100VDiskApp::getServe()
{
    return m_serve;
}

T100VOID T100VDiskApp::setView(IView* view)
{
    m_view = view;
}

IView* T100VDiskApp::getView()
{
    return m_view;
}

T100BOOL T100VDiskApp::run(T100STDSTRING file)
{
    T100VDiskView* view       = T100NULL;

    view = dynamic_cast<T100VDiskView*>(m_view);
    if(view){
        view->start();
    }

    return T100FALSE;
}
