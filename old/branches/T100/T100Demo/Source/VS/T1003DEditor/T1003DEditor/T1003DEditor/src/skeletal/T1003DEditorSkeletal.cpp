#include "skeletal/T1003DEditorSkeletal.h"

#include "view/T1003DEditorView.h"
#include "serve/T1003DEditorServe.h"
#include "store/T1003DEditorStore.h"
#include "data/T1003DEditorDocument.h"
#include "view/panels/T1003DEditorScenePanel.h"
#include "view/T1003DEditorMainMenu.h"

T1003DEditorSkeletal::T1003DEditorSkeletal()
{
    //ctor
}

T1003DEditorSkeletal::~T1003DEditorSkeletal()
{
    //dtor
}

T100VOID T1003DEditorSkeletal::SetView(T1003DEditorView* view)
{
    m_view  = view;
}

T1003DEditorView* T1003DEditorSkeletal::GetView()
{
    return m_view;
}

T100VOID T1003DEditorSkeletal::SetServe(T1003DEditorServe* serve)
{
    m_serve = serve;
}

T1003DEditorServe* T1003DEditorSkeletal::GetServe()
{
    return m_serve;
}

T100VOID T1003DEditorSkeletal::SetStore(T1003DEditorStore* store)
{
    m_store = store;
}

T1003DEditorStore* T1003DEditorSkeletal::GetStore()
{
    return m_store;
}

T100VOID T1003DEditorSkeletal::Create(T1003DEditorFrame* frame)
{
    m_view  = T100NEW T1003DEditorView();
    m_serve = T100NEW T1003DEditorServe();
    m_store = T100NEW T1003DEditorStore();

    m_view->SetSkeletal(this);
    m_view->Create(frame);

    New();
}

T100VOID T1003DEditorSkeletal::Destroy()
{
    T100SAFE_DELETE m_view;
    T100SAFE_DELETE m_serve;
    T100SAFE_DELETE m_store;
}

T100VOID T1003DEditorSkeletal::New()
{
    if(m_view->IsDirty()){
        Save();
    }

    m_view->Clear();

    T1003DEditorDocument*   document    = T100NEW T1003DEditorDocument();

    m_serve->Open(document);

    m_view->GetMainMenu()->New();
}

T100VOID T1003DEditorSkeletal::Open()
{
    T100WSTRING                 filename;
    T1003DEditorDocument*       document        = T100NULL;

    if(m_view->Open(filename)){
        document    = T100NEW T1003DEditorDocument();
        if(m_store->Open(filename, document)){
            if(m_serve->Open(document)){
                m_view->SetTitle(filename);
                m_view->GetScenePanel()->Open(document);
            }else{
                T100SAFE_DELETE document;
            }
        }else{
            T100SAFE_DELETE document;
        }
    }
}

T100VOID T1003DEditorSkeletal::Close()
{
    if(m_view->IsDirty()){
        Save();
    }
    m_view->Clear();
}

T100VOID T1003DEditorSkeletal::Save()
{
    T100WSTRING                 filename;
    T1003DEditorDocument*       document        = T100NULL;

    if(m_view->IsDirty()){
        document    = m_serve->GetDocument();
        filename    = document->m_filename;

        if(filename.empty()){
            if(m_view->Save(filename)){
                document->m_filename    = filename;
            }else{
                return;
            }
        }

        if(m_store->Save(document)){
            m_view->SetDirty(T100FALSE);
            m_view->SetTitle(filename);
        }
    }
}

T100VOID T1003DEditorSkeletal::SaveAs()
{
    T100WSTRING                 filename;
    T1003DEditorDocument*       document        = T100NULL;

    if(m_view->IsDirty()){
        Save();
    }

    if(m_view->Save(filename)){
        document    = m_serve->GetDocument();
        if(m_store->SaveAs(filename, document)){
            m_view->SetDirty(T100FALSE);
        }
    }
}

T100VOID T1003DEditorSkeletal::Import()
{
    T100WSTRING                 filename;
    T1003DEditorDocument*       document        = T100NULL;

    if(m_view->Import(filename)){
        document    = T100NEW T1003DEditorDocument();
        if(m_store->Import(filename, document)){
            if(m_serve->Open(document)){
                m_view->SetTitle(filename);
                m_view->GetScenePanel()->Open(document);
            }else{
                T100SAFE_DELETE document;
            }
        }else{
            T100SAFE_DELETE document;
        }
    }
}

T100VOID T1003DEditorSkeletal::Export()
{

}

T100VOID T1003DEditorSkeletal::Quit()
{
    Close();
    m_view->Quit();
    exit(0);
}

T100VOID T1003DEditorSkeletal::Undo()
{

}

T100VOID T1003DEditorSkeletal::Redo()
{

}

T100VOID T1003DEditorSkeletal::Cut()
{

}

T100VOID T1003DEditorSkeletal::Copy()
{

}

T100VOID T1003DEditorSkeletal::Paste()
{

}

T100VOID T1003DEditorSkeletal::ShowManager(T100BOOL flag)
{
    m_view->ShowManager(flag);
}

T100VOID T1003DEditorSkeletal::SetManager(T100BOOL flag)
{
    m_view->GetMainMenu()->SetManager(flag);
}

T100VOID T1003DEditorSkeletal::ShowProperties(T100BOOL flag)
{
    m_view->ShowProperties(flag);
}

T100VOID T1003DEditorSkeletal::SetProperties(T100BOOL flag)
{
    m_view->GetMainMenu()->SetProperties(flag);
}

T100VOID T1003DEditorSkeletal::ShowConfig()
{
    m_view->ShowConfig();
}

T100VOID T1003DEditorSkeletal::ShowAbout()
{

}
