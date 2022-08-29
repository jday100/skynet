#include "T100IDECallbackView.h"

#include "T100IDEStore.h"
#include "T100IDEServe.h"
#include "T100IDEView.h"


T100IDECallbackView::T100IDECallbackView()
{
    //ctor
}

T100IDECallbackView::~T100IDECallbackView()
{
    //dtor
}

T100BOOL T100IDECallbackView::frame_menu_project(void* d)
{
    T100IDE_PROJECT_VECTOR* projects = T100NEW T100IDE_PROJECT_VECTOR();

    m_serve->getView()->project(*projects);
    m_view->getProject()->show(*projects);

    return T100FALSE;
}
