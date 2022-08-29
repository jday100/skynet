#include "T100IDEServeView.h"

#include "T100IDEStore.h"
#include "T100IDEServe.h"


T100IDEServeView::T100IDEServeView(T100IDEServe* serve)
    :T100IDEServeBase(serve)
{
    //ctor
}

T100IDEServeView::~T100IDEServeView()
{
    //dtor
}

T100BOOL T100IDEServeView::project(T100IDE_PROJECT_VECTOR& projects)
{
    T100BOOL        result      = T100FALSE;
    T100IDEStore*   store;

    store = dynamic_cast<T100IDEStore*>(m_serve->getStore());

    if(!store){
        return T100FALSE;
    }

    result = store->getProject()->list(projects);

    if(result){
        return T100TRUE;
    }

    return T100FALSE;
}
