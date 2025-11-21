#include "T100DiagramSkeletal.h"

#include "T100ElementModule.h"
#include "T100SourceImportInfo.h"

T100DiagramSkeletal::T100DiagramSkeletal() :
    T100DiagramSkeletalBase()
{
    //ctor
}

T100DiagramSkeletal::~T100DiagramSkeletal()
{
    //dtor
}

T100VOID T100DiagramSkeletal::Create(T100DiagramFrame* frame)
{
    m_view      = T100NEW T100DiagramView();
    m_serve     = T100NEW T100DiagramServe();
    m_store     = T100NEW T100DiagramStore();

    m_view->Create(frame);

    FileCreate();
}

T100VOID T100DiagramSkeletal::Destroy()
{
    m_view->Destroy();

    T100SAFE_DELETE(m_store);
    T100SAFE_DELETE(m_serve);
    T100SAFE_DELETE(m_view);
}

T100VOID T100DiagramSkeletal::OnFileCreate()
{
    if(m_serve->IsOpened()){
        if(FileClose()){

        }else{
            return;
        }
    }

    FileCreate();
}

T100VOID T100DiagramSkeletal::OnFileOpen()
{
    if(m_serve->IsOpened()){
        if(FileClose()){

        }else{
            return;
        }
    }

    FileOpen();
}

T100VOID T100DiagramSkeletal::OnFileClose()
{
    if(m_serve->IsOpened()){
        if(m_serve->IsModified()){
            if(FileSave()){

            }else{
                return;
            }
        }
    }
    FileClose();
}

T100VOID T100DiagramSkeletal::OnFileSave()
{
    if(m_serve->IsOpened()){

    }else{
        return;
    }

    FileSave();
}

T100VOID T100DiagramSkeletal::OnFileSaveAs()
{
    if(m_serve->IsOpened()){

    }else{
        return;
    }

    FileSaveAs();
}

T100VOID T100DiagramSkeletal::OnFileQuit()
{
    if(m_serve->IsOpened()){
        if(m_serve->IsModified()){
            if(FileSave()){

            }else{
                return;
            }
        }
        if(FileClose()){

        }else{
            return;
        }
    }

    FileQuit();
}

T100VOID T100DiagramSkeletal::OnEditUndo()
{

}

T100VOID T100DiagramSkeletal::OnEditRedo()
{

}

T100VOID T100DiagramSkeletal::OnEditCut()
{
    if(m_serve->IsOpened()){
        if(m_serve->Remove()){
            if(m_view->Remove()){
                OnModified();
                return;
            }
        }
    }
}

T100VOID T100DiagramSkeletal::OnEditCopy()
{

}

T100VOID T100DiagramSkeletal::OnEditPaste()
{

}

T100VOID T100DiagramSkeletal::OnViewManager(T100BOOL flag)
{
    m_view->ShowViewManager(flag);
}

T100VOID T100DiagramSkeletal::OnViewProperty(T100BOOL flag)
{
    m_view->ShowViewProperty(flag);
}

T100VOID T100DiagramSkeletal::OnSearchFind()
{

}

T100VOID T100DiagramSkeletal::OnDevelopImport()
{
    m_view->ShowSourceImportDialog();
}

T100VOID T100DiagramSkeletal::OnSetupConfig()
{

}

T100VOID T100DiagramSkeletal::OnHelpAbout()
{

}

T100VOID T100DiagramSkeletal::OnAuiPaneClose(wxAuiPaneInfo* info)
{
    if(!info){
        return;
    }

    T100WSTRING         name;

    name    = info->name.ToStdWstring();

    if(name == L"Manager"){
        m_view->ShowViewManager(T100FALSE);
    }else if(name == L"Property"){
        m_view->ShowViewProperty(T100FALSE);
    }
}

T100VOID T100DiagramSkeletal::OnItemSelect(T100UINT index)
{
    T100ElementBase*    element     = m_serve->GetElementServe().Create(index);

    if(element){
        m_serve->GetElementServe().SetElement(element);
        m_view->Position(element);
    }
}

T100VOID T100DiagramSkeletal::OnItemAppend()
{
    if(m_serve->Append()){
        if(m_view->Append()){
            OnModified();
            return;
        }
    }
}

T100VOID T100DiagramSkeletal::OnTieSelect(T100UINT index)
{
    T100ElementBase*    element     = m_serve->GetElementServe().Create(index);

    if(element){
        m_serve->GetElementServe().SetElement(element);
        m_view->Tie(element);
    }
}

T100VOID T100DiagramSkeletal::OnTieStart(wxPoint& value)
{
    T100ElementBase*    element         = T100NULL;

    if(m_serve->Hit(value.x, value.y)){
        element = m_serve->GetElementServe().GetElement();

        if(element){
            m_view->TieStart(element);
        }
    }
}

T100VOID T100DiagramSkeletal::OnTieEnd(wxPoint& value)
{
    T100ElementBase*    element         = T100NULL;

    if(m_serve->Hit(value.x, value.y)){
        element = m_serve->GetElementServe().GetElement();

        if(element){
            m_view->TieEnd(element);
        }
    }
}

T100VOID T100DiagramSkeletal::OnSelect(T100INT x, T100INT y)
{
    T100ElementBase*    element         = T100NULL;

    if(m_serve->Hit(x, y)){
        element = m_serve->GetElementServe().GetElement();

        if(element){
            m_view->Select(element);
        }
    }
}

T100VOID T100DiagramSkeletal::OnModified()
{
    if(m_serve->IsOpened()){
        m_serve->SetModified(T100TRUE);
        m_view->Dirty();
    }
}

T100VOID T100DiagramSkeletal::OnMouseDClick(T100INT x, T100INT y)
{
    T100ElementBase*    element         = T100NULL;

    if(m_serve->Hit(x, y)){
        element = m_serve->GetElementServe().GetElement();

        if(element){
            m_view->Edit(element);
        }
    }
}

T100VOID T100DiagramSkeletal::OnCanvasState(T100STRING& value)
{
    m_view->CanvasState(value);
}

T100VOID T100DiagramSkeletal::OnCanvasPosition(T100STRING& value)
{
    m_view->CanvasPosition(value);
}

T100VOID T100DiagramSkeletal::OnSourceImport(T100SourceImportInfo* info)
{
    static T100UINT     x   = 100;
    static T100UINT     y   = 100;

    m_serve->GetSourceImport().Run(info);

    T100SOURCE_IMPORT_FILE_INFO_VECTOR&     files   = m_serve->GetSourceImport().GetFiles();

    for(T100SourceImportFileInfo* file : files){
        T100ElementModule*      module      = T100NEW T100ElementModule();

        module->SetName(file->FileName);
        module->SetOriginX(x);
        module->SetOriginY(y);

        y   = x > 2000 ? y + 100 : y;
        x   = x > 2000 ? 100 : x + 200;


        m_serve->GetDiagramInfo()->GetElements()->push_back(module);
    }

    T100DiagramInfo*    diagram    = m_serve->GetDiagramInfo();

    if(!diagram){
        return;
    }

    diagram->GetCanvas()->WIDTH     = x + 300;
    diagram->GetCanvas()->HEIGHT    = y + 300;

    m_view->Update();
}
