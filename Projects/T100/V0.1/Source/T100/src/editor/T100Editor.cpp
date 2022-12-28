#include "T100Editor.h"

#include "T100EditorServe.h"
#include "T100EditorView.h"
#include "T100EditorCallback.h"


namespace T100Editor{

T100Editor::T100Editor(T100EditorApp* app)
    :m_app(app)
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
    m_serve     = T100NEW T100EditorServe();
    m_view      = T100NEW T100EditorView();

    T100EditorCallback::init(m_serve, m_view);
}

T100VOID T100Editor::destroy()
{
    T100SAFE_DELETE(m_view);
    T100SAFE_DELETE(m_serve);
}

T100VOID T100Editor::setServe(T100EditorServe* serve)
{
    m_serve = serve;
}

T100EditorServe* T100Editor::getServe()
{
    return m_serve;
}

T100VOID T100Editor::setView(T100EditorView* view)
{
    m_view = view;
}

T100EditorView* T100Editor::getView()
{
    return m_view;
}

T100VOID T100Editor::show()
{
    if(m_view){
        m_view->show();
    }
}

T100VOID T100Editor::quit()
{

}

}
