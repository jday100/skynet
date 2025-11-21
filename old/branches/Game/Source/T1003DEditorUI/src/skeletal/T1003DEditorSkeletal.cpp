#include "T1003DEditorSkeletal.h"

#include <io.h>
#include <fstream>
#include "library/T100Unicode.h"
#include "T1003DEditorConfig.h"
#include "T1003DEditorView.h"
#include "T1003DEditorServe.h"
#include "T1003DEditorStore.h"
#include "T1003DEditorDocument.h"
#include "T1003DEditorScenePanel.h"
#include "T1003DEditorMainMenu.h"

#include "T1003DEditorShaderFile.h"

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

T100VOID T1003DEditorSkeletal::Create(T1003DEditorUIFrame* frame)
{
    m_view  = T100NEW T1003DEditorView();
    m_serve = T100NEW T1003DEditorServe();
    m_store = T100NEW T1003DEditorStore();

    m_view->SetSkeletal(this);
    m_view->Create(frame);

    Load();
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

    m_view->GetScenePanel()->Open(document);
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
    m_view->GetMainMenu()->Close();
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
            m_view->GetMainMenu()->Save();
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

T100VOID T1003DEditorSkeletal::ShowSettings()
{
    m_view->ShowSettings();
}

T100VOID T1003DEditorSkeletal::ShowAbout()
{

}

T100VOID T1003DEditorSkeletal::Load()
{
    if(access(T1003DEditorConfig::ConfigFile.c_str(), 0) != -1){
        m_store->GetSettingsStore().LoadConfigFile();
    }

    if(access(T1003DEditorConfig::SettingsDescriptionFile.c_str(), 0) != -1){
        T1003DEDITOR_VERTEX_DESCRIPTION_VECTOR&         vertexDescriptions      = m_serve->GetSettingsServe().GetVertexDescriptions();
        m_store->GetSettingsStore().LoadDescriptions(vertexDescriptions);
    }

    if(access(T1003DEditorConfig::SettingsParameterFile.c_str(), 0) != -1){
        T1003DEDITOR_SHADER_PARAMETER_VECTOR&           shaderParameters        = m_serve->GetSettingsServe().GetShaderParameters();
        m_store->GetSettingsStore().LoadParameters(shaderParameters);
    }

    if(access(T1003DEditorConfig::SettingsVertexShaderFile.c_str(), 0) != -1){
        T1003DEDITOR_SHADER_FILE_VECTOR&                vertexShaders           = m_serve->GetSettingsServe().GetVertexShaders();
        m_store->GetSettingsStore().LoadVertexShaders(vertexShaders);
    }

    if(access(T1003DEditorConfig::SettingsPixelShaderFile.c_str(), 0) != -1){
        T1003DEDITOR_SHADER_FILE_VECTOR&                pixelShaders            = m_serve->GetSettingsServe().GetPixelShaders();
        m_store->GetSettingsStore().LoadPixelShaders(pixelShaders);
    }

}
