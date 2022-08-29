#include "T100IDEView.h"

#include "T100IDEFrameNew.h"


T100IDEView::T100IDEView()
{
    //ctor
}

T100IDEView::~T100IDEView()
{
    //dtor
    destroy();
}

T100VOID T100IDEView::create()
{
    m_manager       = T100NEW T100IDEViewManager(this);

    //m_frame         = T100NEW T100IDEFrameNew(m_manager->getDocManager(), T100NULL);

    m_menu          = T100NEW T100IDEMenu(m_frame);

    m_status_bar    = T100NEW T100IDEStatusBar(m_frame);

    m_file          = T100NEW T100IDEViewFile(this);
    m_edit          = T100NEW T100IDEViewEdit(this);
    m_view          = T100NEW T100IDEViewView(this);
    m_search        = T100NEW T100IDEViewSearch(this);
    m_project       = T100NEW T100IDEViewProject(this);
    m_build         = T100NEW T100IDEViewBuild(this);
    m_debug         = T100NEW T100IDEViewDebug(this);
    m_setup         = T100NEW T100IDEViewSetup(this);
    m_help          = T100NEW T100IDEViewHelp(this);



    //test
    start();
}

T100VOID T100IDEView::destroy()
{
    if(m_status_bar){
        T100DELETE(m_status_bar);
    }

    if(m_menu){
        T100DELETE(m_menu);
    }

    if(m_frame){
        T100DELETE(m_manager);
        T100DELETE(m_frame);
    }
}

T100IDEViewManager* T100IDEView::getManager()
{
    return m_manager;
}

T100VOID T100IDEView::setFrame(T100IDEFrameNew* frame)
{
    m_frame = frame;
}

T100IDEFrameNew* T100IDEView::getFrame()
{
    return m_frame;
}

T100IDEViewFile* T100IDEView::getFile()
{
    return m_file;
}

T100IDEViewEdit* T100IDEView::getEdit()
{
    return m_edit;
}

T100IDEViewView* T100IDEView::getView()
{
    return m_view;
}

T100IDEViewSearch* T100IDEView::getSearch()
{
    return m_search;
}

T100IDEViewProject* T100IDEView::getProject()
{
    return m_project;
}

T100IDEViewBuild* T100IDEView::getBuild()
{
    return m_build;
}

T100IDEViewDebug* T100IDEView::getDebug()
{
    return m_debug;
}

T100IDEViewSetup* T100IDEView::getSetup()
{
    return m_setup;
}

T100IDEViewHelp* T100IDEView::getHelp()
{
    return m_help;
}

T100BOOL T100IDEView::show()
{
    if(m_frame){
        return m_frame->Show();
    }
    return T100FALSE;
}

T100BOOL T100IDEView::start()
{
    if(m_frame){
        m_frame->setView(this);

        m_frame->SetSize(800, 600);
    }else{
        return T100FALSE;
    }

    if(m_menu){
        m_menu->create();
    }

    if(m_status_bar){
        m_status_bar->create();
    }

    return T100FALSE;
}

T100BOOL T100IDEView::quit()
{
    if(m_frame){
        return m_frame->Close();
    }

    return T100FALSE;
}
