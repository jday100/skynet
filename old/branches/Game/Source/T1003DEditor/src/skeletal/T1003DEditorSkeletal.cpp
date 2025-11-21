#include "T1003DEditorSkeletal.h"

#include "T1003DEditorStore.h"
#include "T1003DEditorServe.h"
#include "T1003DEditorView.h"
#include "T1003DEditorCallback.h"

#include "T100Entity.h"
#include "T1003DEditorDocument.h"
#include "T1003DEditorTaskReadFile.h"

T1003DEditorSkeletal::T1003DEditorSkeletal()
{
    //ctor
    init();
}

T1003DEditorSkeletal::~T1003DEditorSkeletal()
{
    //dtor
    uninit();
}

T100VOID T1003DEditorSkeletal::init()
{
    T1003DEditorCallback::Init();

    m_store = T100NEW T1003DEditorStore();
    m_serve = T100NEW T1003DEditorServe();
    m_view  = T100NEW T1003DEditorView();

    m_view->SetSkeletal(this);
}

T100VOID T1003DEditorSkeletal::uninit()
{
    T100SAFE_DELETE m_store;
    T100SAFE_DELETE m_serve;
    T100SAFE_DELETE m_view;

    T1003DEditorCallback::Uninit();
}

T100VOID T1003DEditorSkeletal::SetStore(T1003DEditorStore* store)
{
    m_store     = store;
}

T1003DEditorStore* T1003DEditorSkeletal::GetStore()
{
    return m_store;
}

T100VOID T1003DEditorSkeletal::SetServe(T1003DEditorServe* serve)
{
    m_serve     = serve;
}

T1003DEditorServe* T1003DEditorSkeletal::GetServe()
{
    return m_serve;
}

T100VOID T1003DEditorSkeletal::SetView(T1003DEditorView* view)
{
    m_view      = view;
}

T1003DEditorView* T1003DEditorSkeletal::GetView()
{
    return m_view;
}

T100VOID T1003DEditorSkeletal::New()
{

}

T100VOID T1003DEditorSkeletal::Open()
{
    T100WSTRING             filename;
    T1003DEditorDocument    document;

    m_view->SetCursor();

    if(m_view->Open(filename)){
        m_view->SetCursor();
        if(m_store->Open(filename, document)){
            if(m_serve->Open(document)){

            }
        }
    }
}

T100VOID T1003DEditorSkeletal::Close()
{

}

T100VOID T1003DEditorSkeletal::Save()
{
    T100WSTRING             filename;
    T1003DEditorDocument&   document = m_serve->GetDocument();

    m_view->SetCursor();

    if(document.m_filename.empty()){
        if(m_view->Save(filename)){
            if(m_store->Save(filename, document)){

            }
        }
    }else{
        if(m_store->Save(filename, document)){

        }
    }
}
