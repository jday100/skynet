#include "IView.h"

IView::IView()
{
    //ctor
}

IView::~IView()
{
    //dtor
}

T100VOID IView::setServe(IServe* serve)
{
    m_serve = serve;
}

IServe* IView::getServe()
{
    return m_serve;
}
