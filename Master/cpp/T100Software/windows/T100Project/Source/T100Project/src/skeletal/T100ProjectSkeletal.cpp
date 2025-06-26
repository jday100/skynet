#include "T100ProjectSkeletal.h"

#include "T100ProjectApplication.h"

#include "T100MenuExtension.h"

T100ProjectSkeletal::T100ProjectSkeletal() :
    m_pluginServer(),
    m_extendedManager()
{
    //ctor
    init();
}

T100ProjectSkeletal::~T100ProjectSkeletal()
{
    //dtor
    uninit();
}

T100VOID T100ProjectSkeletal::init()
{
    m_store     = T100NEW T100ProjectStore();
    m_serve     = T100NEW T100ProjectServe();
    m_view      = T100NEW T100ProjectView();
}

T100VOID T100ProjectSkeletal::uninit()
{
    T100SAFE_DELETE(m_view);
    T100SAFE_DELETE(m_serve);
    T100SAFE_DELETE(m_store);
}

T100VOID T100ProjectSkeletal::Launch()
{
    T100ProjectApplication*     app     = dynamic_cast<T100ProjectApplication*>(m_view->GetFrame()->GetApplication());

    T100MenuExtension*  extension   = T100NEW T100MenuExtension();

    m_extendedManager.SignIn(L"T100Project.View.MainMenu.File.Quit", extension);

    m_pluginServer.Start();

    m_pluginServer.Load(L"Main");

    if(!app){
        return;
    }

    void(*PluginInit)(T100ProjectApplication*)  = (void(*)(T100ProjectApplication*))m_pluginServer.GetMethod(L"Main", L"PluginInit");

    if(PluginInit){
        PluginInit(app);
    }

    void(*ViewSignIn)(T100VOID*)    = (void(*)(T100VOID*))m_pluginServer.GetMethod(L"Main", L"ViewSignIn");

    T100MenuBar*        menuBar         = T100NULL;

    T100MenuBar*(*method)() = (T100MenuBar*(*)())m_pluginServer.GetMethod(L"Main", L"Main_GetMainMenuBar");

    if(method){
        menuBar     = method();

        if(menuBar){
            m_view->GetFrame()->SetMenuBar(menuBar);

            if(app){

                ViewSignIn(app);

                m_extendedManager.ConnectMenu(L"T100Project.View.MainMenu.File.Quit", 1000, m_view->GetFrame(), (T100EVENT_FUNCTION)&app->OnMenu, app);

                //m_view->GetFrame()->ConnectMenu(1000, (T100EVENT_FUNCTION)&app->OnMenu, app);
                //m_extendedManager.ConnectMenu(L"T100Project.View.MainMenu.File.Quit", 1000, m_view->GetFrame(), (T100EVENT_FUNCTION)&app->OnMenu, app);
            }
        }
    }

    m_view->Default();
}

T100VOID T100ProjectSkeletal::Quit()
{
    PostQuitMessage(0);
}

T100PluginServer& T100ProjectSkeletal::GetPluginServer()
{
    return m_pluginServer;
}

T100ExtendedManager& T100ProjectSkeletal::GetExtendedManager()
{
    return m_extendedManager;
}

T100VOID T100ProjectSkeletal::SetView(T100ProjectView* view)
{
    m_view      = view;
}

T100ProjectView* T100ProjectSkeletal::GetView()
{
    return m_view;
}

T100VOID T100ProjectSkeletal::SetServe(T100ProjectServe* serve)
{
    m_serve     = serve;
}

T100ProjectServe* T100ProjectSkeletal::GetServe()
{
    return m_serve;
}

T100VOID T100ProjectSkeletal::SetStore(T100ProjectStore* store)
{
    m_store     = store;
}

T100ProjectStore* T100ProjectSkeletal::GetStore()
{
    return m_store;
}
