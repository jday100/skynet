#include "T100IDE.h"

#include "T100IDEServe.h"
#include "T100IDEView.h"


namespace T100IDE{

T100IDE::T100IDE(T100IDEApp* app)
    :m_app(app)
{
    //ctor
    create();
}

T100IDE::~T100IDE()
{
    //dtor
    destroy();
}

T100VOID T100IDE::create()
{
    m_serve     = T100NEW T100IDEServe();
    m_view      = T100NEW T100IDEView();
}

T100VOID T100IDE::destroy()
{
    T100SAFE_DELETE(m_view);
    T100SAFE_DELETE(m_serve);
}

T100VOID T100IDE::setServe(T100IDEServe* serve)
{

}

T100IDEServe* T100IDE::getServe()
{

}

T100VOID T100IDE::setView(T100IDEView* view)
{

}

T100IDEView* T100IDE::getView()
{

}

T100VOID T100IDE::show()
{
    if(m_view){
        m_view->show();
    }
}

T100VOID T100IDE::quit()
{

}

}
