#include "T100EditorCallback.h"

T100EditorView*         T100EditorCallback::m_view          = T100NULL;
T100EditorServe*        T100EditorCallback::m_serve         = T100NULL;
T100EditorStore*        T100EditorCallback::m_store         = T100NULL;

T100EditorCallback::T100EditorCallback()
{
    //ctor
}

T100EditorCallback::~T100EditorCallback()
{
    //dtor
}

T100VOID T100EditorCallback::OnMenuNewSelected()
{

}

T100VOID T100EditorCallback::OnMenuOpenSelected()
{
    m_view->open();
}

T100VOID T100EditorCallback::OnMenuCloseSelected()
{

}

T100VOID T100EditorCallback::OnMenuSaveSelected()
{

}

T100VOID T100EditorCallback::OnMenuSaveAsSelected()
{

}
