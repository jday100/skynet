#include "T100EditorView.h"

T100EditorView::T100EditorView()
{
    //ctor
}

T100EditorView::~T100EditorView()
{
    //dtor
}

T100VOID T100EditorView::create()
{
    m_main_menu = T100NEW T100EditorMainMenu();
}

T100VOID T100EditorView::destroy()
{
    T100SAFE_DELETE m_main_menu;
}

T100BOOL T100EditorView::show()
{

}

T100BOOL T100EditorView::hide()
{

}

T100BOOL T100EditorView::open()
{

}
