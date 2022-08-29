#include "T100VPCApp.h"

#include <wx/app.h>
#include "T100App.h"
#include "T100VPCSetup.h"
#include "T100VPCCallbackNew.h"


T100VPCApp::T100VPCApp()
{
    //ctor
    create();
}

T100VPCApp::~T100VPCApp()
{
    //dtor
    destroy();
}

T100VOID T100VPCApp::create()
{
    T100VPCServe*   serve       = T100NULL;
    T100VPCView*    view        = T100NULL;

    serve       = T100NEW T100VPCServe;
    view        = T100NEW T100VPCView;

    if(!serve)return;
    if(!view)return;

    m_serve     = serve;
    m_view      = view;

    T100VPCCallback::init(serve, view);

    if(view){
        view->setApp(this);
    }
    m_view->setServe(m_serve);
    m_view->create();

    view->getFrame()->m_debug = T100TRUE;
}

T100VOID T100VPCApp::destroy()
{
    T100DELETE(m_view);
    T100DELETE(m_serve);
}

T100BOOL T100VPCApp::show()
{
    if(m_view){
        return m_view->show();
    }
    return T100FALSE;
}

wxFrame* T100VPCApp::getFrame()
{
    if(m_view){
        T100VPCView* view   = T100NULL;
        view = dynamic_cast<T100VPCView*>(m_view);
        if(view){
            return view->getFrame();
        }
    }
    return T100NULL;
}

T100VOID T100VPCApp::setServe(IServe* serve)
{
    m_serve = serve;
}

IServe* T100VPCApp::getServe()
{
    return m_serve;
}

T100VOID T100VPCApp::setView(IView* view)
{
    m_view = view;
}

IView* T100VPCApp::getView()
{
    return m_view;
}

T100VOID T100VPCApp::setQuit(T100BOOL quit)
{
    T100VPCSetup::m_quit = quit;
}

T100BOOL T100VPCApp::run(T100App* app, T100STDSTRING file, T100WORD offset)
{
    T100VPCServe*   serve       = T100NULL;
    T100VPCView*    view        = T100NULL;

    view = dynamic_cast<T100VPCView*>(m_view);
    if(!view)return T100FALSE;

    serve = dynamic_cast<T100VPCServe*>(m_serve);
    if(serve){
        if(!serve->create(view, T100NULL)){
            return T100FALSE;
        }
        serve->setFile(file);
        serve->setOffset(offset);
    }

    if(view){
        view->getFrame()->m_debug = T100FALSE;
        view->show();
        if(view->run()){
            //serve->wait();
            app->Run();
            return T100TRUE;
        }
    }

    serve->wait();

    return T100FALSE;
}

T100BOOL T100VPCApp::run(T100WORD_VECTOR& app, T100DWORD offset)
{
    if(!m_serve){
        return T100FALSE;
    }

    T100VPCServe*   serve       = T100NULL;

    serve = dynamic_cast<T100VPCServe*>(m_serve);

    if(!serve){
        return T100FALSE;
    }

    if(!m_view){
        return T100FALSE;
    }

    T100VPCView*    view        = T100NULL;

    view = dynamic_cast<T100VPCView*>(m_view);

    if(!view){
        return T100FALSE;
    }

    if(!serve->create(view, T100NULL)){
        return T100FALSE;
    }

    if(!serve->load(app, offset)){
        return T100FALSE;
    }

    view->getFrame()->m_debug = T100TRUE;

    if(view->run()){
        serve->wait();
        //wxTheApp->OnRun();
        return T100TRUE;
    }

    serve->wait();

    return T100FALSE;
}

T100BOOL T100VPCApp::run(T100App* app)
{
    T100VPCServe*   serve       = T100NULL;
    T100VPCView*    view        = T100NULL;

    view = dynamic_cast<T100VPCView*>(m_view);
    if(!view)return T100FALSE;

    serve = dynamic_cast<T100VPCServe*>(m_serve);
    if(serve){
        if(!serve->create(view, T100NULL)){
            return T100FALSE;
        }
    }

    if(view){
        view->getFrame()->m_debug = T100FALSE;
        view->show();
        if(view->run()){
            //serve->wait();
            app->Run();
            return T100TRUE;
        }
    }

    serve->wait();

    return T100FALSE;
}

T100WORD T100VPCApp::getReturn()
{
    /*
    T100VPCServe* serve     = T100NULL;

    serve = dynamic_cast<T100VPCServe*>(m_serve);

    if(serve){
        return serve->getReturn();
    }

    return m_return;
    */

    return T100VPCSetup::m_return;
}

T100BOOL T100VPCApp::quit()
{
    T100VPCCallback::app_quit();
    return T100FALSE;
}

T100BOOL T100VPCApp::add(T100STDSTRING file, T100WORD offset)
{
    T100FILE_INFO*  info = T100NEW T100FILE_INFO;

    info->FILE      = file;
    info->OFFSET    = offset;

    T100QU32Setup::m_files.push_back(info);

    return T100TRUE;
}
