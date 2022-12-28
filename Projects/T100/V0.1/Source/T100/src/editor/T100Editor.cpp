#include "T100Editor.h"

#include "T100EditorServe.h"
#include "T100EditorView.h"


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
}

T100VOID T100Editor::destroy()
{
    T100SAFE_DELETE(m_view);
    T100SAFE_DELETE(m_serve);
}

T100VOID T100Editor::setServe(T100EditorServe* serve)
{

}

T100EditorServe* T100Editor::getServe()
{

}

T100VOID T100Editor::setView(T100EditorView* view)
{

}

T100EditorView* T100Editor::getView()
{

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
