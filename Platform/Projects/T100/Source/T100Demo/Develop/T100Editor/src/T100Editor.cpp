#include "T100Editor.h"

T100Editor::T100Editor()
{
    //ctor
    create();
}

T100Editor::~T100Editor()
{
    //dtor
    destroy();
}

T100VOID T100Editor::create()
{
    m_store     = T100NEW T100EditorStore();
    m_serve     = T100NEW T100EditorServe();
    m_view      = T100NEW T100EditorView();
}

T100VOID T100Editor::destroy()
{
    T100SAFE_DELETE m_view;
    T100SAFE_DELETE m_serve;
    T100SAFE_DELETE m_store;
}

T100VOID T100Editor::run()
{
    renew();
    m_view->show();
}

T100VOID* T100Editor::getFrame()
{
    if(m_view){
        return m_view->getFrame();
    }

    return T100NULL;
}

T100BOOL T100Editor::renew()
{
    m_serve->renew();
    m_view->renew();
}
