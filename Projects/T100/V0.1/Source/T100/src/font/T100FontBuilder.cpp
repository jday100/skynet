#include "T100FontBuilder.h"

#include "T100FontServe.h"
#include "T100FontView.h"
#include "T100FontCallback.h"


namespace T100FontBuilder{

T100FontBuilder::T100FontBuilder()
{
    //ctor
    create();
}

T100FontBuilder::~T100FontBuilder()
{
    //dtor
    destroy();
}

T100VOID T100FontBuilder::create()
{
    m_serve     = T100NEW T100FontServe();
    m_view      = T100NEW T100FontView();

    T100FontCallback::init(m_serve, m_view);

    m_view->init();
}

T100VOID T100FontBuilder::destroy()
{
    T100SAFE_DELETE(m_view);
    T100SAFE_DELETE(m_serve);
}

T100VOID T100FontBuilder::setServe(T100FontServe* serve)
{
    m_serve = serve;
}

T100FontServe* T100FontBuilder::getServe()
{
    return m_serve;
}

T100VOID T100FontBuilder::setView(T100FontView* view)
{
    m_view = view;
}

T100FontView* T100FontBuilder::getView()
{
    return m_view;
}

T100VOID T100FontBuilder::show()
{
    if(m_view){
        m_view->show();
    }
}

T100VOID T100FontBuilder::quit()
{
    std::unique_lock<std::mutex>    locker(m_mutex);
    m_condition.wait(locker);
    locker.unlock();
}

}
