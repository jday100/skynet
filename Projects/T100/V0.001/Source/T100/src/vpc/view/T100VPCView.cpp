#include "T100VPCView.h"

T100VPCView::T100VPCView()
{
    //ctor
}

T100VPCView::~T100VPCView()
{
    //dtor
    destroy();
}

T100VOID T100VPCView::create()
{
    T100Log::trace(T100VPC_HINT_VIEW_START);

    m_frame = T100NEW T100VPCFrame(T100NULL);

    if(m_frame){
        m_frame->setView(this);
    }
}

T100VOID T100VPCView::destroy()
{
    if((!m_quit) && m_frame){
        T100DELETE(m_frame);
        m_frame = T100NULL;
    }

    T100Log::trace(T100VPC_HINT_VIEW_STOP);
}

T100VOID T100VPCView::setApp(T100VPCApp* app)
{
    m_app = app;
}

T100VPCApp* T100VPCView::getApp()
{
    return m_app;
}

T100VOID T100VPCView::setFrame(T100VPCFrame* frame)
{
    m_frame = frame;
}

T100VPCFrame* T100VPCView::getFrame()
{
    return m_frame;
}

T100VPCDebugFrame* T100VPCView::getDebugFrame()
{
    if(!m_debug){
        m_debug = T100NEW T100VPCDebugFrame(m_frame);
        if(m_debug){
            m_debug->setView(this);
        }
    }
    return m_debug;
}

T100BOOL T100VPCView::show()
{
    if(m_frame){
        return m_frame->Show();
    }
    return T100FALSE;
}

T100BOOL T100VPCView::run()
{
    if(!m_screen){
        m_screen = T100NEW T100VPCScreen(m_frame, wxID_ANY, wxDefaultPosition, wxSize(SCREEN_WIDTH, SCREEN_HEIGHT));
    }
    if(m_screen){
        if(m_screen->Show()){
            T100VPCHint::m_detail = T100TRUE;
            return m_screen->run();
        }
    }
    return T100FALSE;
}

T100BOOL T100VPCView::start()
{
    if(!m_screen){
        m_screen = T100NEW T100VPCScreen(m_frame, wxID_ANY, wxDefaultPosition, wxSize(SCREEN_WIDTH, SCREEN_HEIGHT));
    }
    if(m_screen){
        if(!m_frame->start()){
            return T100FALSE;
        }
        if(m_screen->Show()){
            T100VPCHint::m_detail = T100TRUE;
            return m_screen->start();
        }
    }
    return T100FALSE;
}

T100BOOL T100VPCView::stop()
{
    if(m_screen){
        if(m_screen->stop()){
            T100DELETE(m_screen);
            m_screen = T100NULL;
        }else{
            return T100FALSE;
        }
    }

    if(m_debug){
        if(m_debug->stop()){
            T100DELETE(m_debug);
            m_debug = T100NULL;
        }else{
            return T100FALSE;
        }
    }

    if(!m_frame->stop()){
        return T100FALSE;
    }

    return T100TRUE;
}

T100BOOL T100VPCView::quit()
{
    if(m_screen){
        m_screen->stop();
        m_screen->Destroy();
    }

    if(m_debug){
        m_debug->Destroy();
    }

    if(m_frame){
        m_frame->Destroy();
    }

    return T100FALSE;
}
