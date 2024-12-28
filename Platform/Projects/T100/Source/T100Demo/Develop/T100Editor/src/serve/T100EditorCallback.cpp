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
    T100BOOL            result          = T100FALSE;
    T100WString         filename;

    result  = m_view->open(filename);
    if(result){
        result  = m_serve->open(filename);
    }

    if(result){
        result  = m_view->renew();
    }

    if(result){
        result  = m_view->load(filename);
    }
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
