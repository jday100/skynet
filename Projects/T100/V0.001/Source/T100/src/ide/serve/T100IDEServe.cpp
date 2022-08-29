#include "T100IDEServe.h"

T100IDEServe::T100IDEServe()
{
    //ctor
    create();
}

T100IDEServe::~T100IDEServe()
{
    //dtor
    destroy();
}

T100VOID T100IDEServe::create()
{
    m_file      = T100NEW T100IDEServeFile(this);
    m_edit      = T100NEW T100IDEServeEdit(this);
    m_view      = T100NEW T100IDEServeView(this);
    m_search    = T100NEW T100IDEServeSearch(this);
    m_project   = T100NEW T100IDEServeProject(this);
    m_build     = T100NEW T100IDEServeBuild(this);
    m_debug     = T100NEW T100IDEServeDebug(this);
    m_setup     = T100NEW T100IDEServeSetup(this);
    m_help      = T100NEW T100IDEServeHelp(this);
}

T100VOID T100IDEServe::destroy()
{

}

T100VOID T100IDEServe::setStore(T100IDEStore* store)
{
    m_store = store;
}

T100IDEStore* T100IDEServe::getStore()
{
    return m_store;
}

T100IDEServeFile* T100IDEServe::getFile()
{
    return m_file;
}

T100IDEServeEdit* T100IDEServe::getEdit()
{
    return m_edit;
}

T100IDEServeView* T100IDEServe::getView()
{
    return m_view;
}

T100IDEServeSearch* T100IDEServe::getSearch()
{
    return m_search;
}

T100IDEServeProject* T100IDEServe::getProject()
{
    return m_project;
}

T100IDEServeBuild* T100IDEServe::getBuild()
{
    return m_build;
}

T100IDEServeDebug* T100IDEServe::getDebug()
{
    return m_debug;
}

T100IDEServeSetup* T100IDEServe::getSetup()
{
    return m_setup;
}

T100IDEServeHelp* T100IDEServe::getHelp()
{
    return m_help;
}
