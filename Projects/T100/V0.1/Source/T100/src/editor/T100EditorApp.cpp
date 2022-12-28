#include "T100EditorApp.h"

#include "T100Editor.h"

namespace T100Editor{

T100EditorApp::T100EditorApp(T100ThisAppManager* obj, T100BOOL quit)
    :T100WxWidgets::T100WxApp((T100WxWidgets::T100WxAppManager*)obj, quit)
{
    //ctor
    create();
}

T100EditorApp::~T100EditorApp()
{
    //dtor
    destroy();
}

T100VOID T100EditorApp::create()
{
    m_editor    = T100NEW T100Editor(this);
}

T100VOID T100EditorApp::destroy()
{
    T100SAFE_DELETE(m_editor);
}

T100VOID T100EditorApp::show()
{
    if(m_editor){
        m_editor->show();
    }
}

}
