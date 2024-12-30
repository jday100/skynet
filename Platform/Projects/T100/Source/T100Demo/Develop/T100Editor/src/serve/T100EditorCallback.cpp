#include "T100EditorCallback.h"

#include "T100EditorDocument.h"

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

T100VOID T100EditorCallback::init(T100EditorView* view, T100EditorServe* serve, T100EditorStore* store)
{
    m_view  = view;
    m_serve = serve;
    m_store = store;
}

T100VOID T100EditorCallback::OnMenuNewSelected()
{
    T100BOOL            result          = T100FALSE;

    result  = m_view->renew();

}

T100VOID T100EditorCallback::OnMenuOpenSelected()
{
    T100BOOL                result          = T100FALSE;
    T100EditorDocument      document;

    result  = m_view->open(document);
    if(result){
        result  = m_view->renew();
    }

    if(result){
        result  = m_view->load_file(document);
    }

    if(result){

    }else{
        result  = m_view->close();
    }
}

T100VOID T100EditorCallback::OnMenuCloseSelected()
{
    T100BOOL        result          = T100FALSE;

    result  = m_view->close();
}

T100VOID T100EditorCallback::OnMenuSaveSelected()
{
    T100BOOL        result          = T100FALSE;

    result  = m_view->save();
}

T100VOID T100EditorCallback::OnMenuSaveAsSelected()
{
    T100BOOL                result          = T100FALSE;
    T100EditorDocument      document;

    result  = m_view->save_as(document);
    if(result){
        result  = m_view->save_file(document);
    }
}

T100VOID T100EditorCallback::OnMenuUndoSelected()
{
    m_view->undo();
}

T100VOID T100EditorCallback::OnMenuRedoSelected()
{
    m_view->redo();
}

T100VOID T100EditorCallback::OnMenuCutSelected()
{
    m_view->cut();
}

T100VOID T100EditorCallback::OnMenuCopySelected()
{
    m_view->copy();
}

T100VOID T100EditorCallback::OnMenuPasteSelected()
{
    m_view->paste();
}

T100VOID T100EditorCallback::OnMenuFindSelected()
{
    m_view->find();
}

T100VOID T100EditorCallback::OnMenuReplaceSelected()
{
    m_view->replace();
}

T100VOID T100EditorCallback::OnMenuQuitSelected()
{
    m_view->quit();
}
