#include "T1003DEditorCallback.h"

#include "T100Debug.h"
#include "T1003DEditorStore.h"
#include "T1003DEditorServe.h"
#include "T1003DEditorView.h"
#include "T1003DEditorSkeletal.h"

#include "T100GameCallback.h"
#include "T1003DEditorUIMain.h"
#include "T1003DEditorMainPanel.h"
#include "T1003DEditorScenePanel.h"
#include "T1003DEditorEntityPanel.h"
#include "T1003DEditorPropertiesPanel.h"

#include "entity/T100Entity.h"
#include "entity/T100Mesh.h"

T1003DEditorSkeletal*       T1003DEditorCallback::m_skeletal            = T100NULL;

T1003DEditorCallback::T1003DEditorCallback()
{
    //ctor
}

T1003DEditorCallback::~T1003DEditorCallback()
{
    //dtor
}

T100VOID T1003DEditorCallback::Create(T1003DEditorUIFrame* frame)
{
    T100GameCallback::Init();
    m_skeletal  = T100NEW T1003DEditorSkeletal();

    m_skeletal->Create(frame);

    T100GameCallback::Create(
        m_skeletal->GetView()->GetMainPanel()->GetHWND(),
        m_skeletal->GetView()->GetMainPanel()->GetWidth(),
        m_skeletal->GetView()->GetMainPanel()->GetHeight());

    m_skeletal->New();
}

T100VOID T1003DEditorCallback::Destroy()
{
    T100SAFE_DELETE m_skeletal;
    T100GameCallback::Destroy();
    T100GameCallback::Uninit();
}

T100VOID T1003DEditorCallback::MenuNew()
{
    m_skeletal->New();
    T100GameCallback::Clear();
}

T100VOID T1003DEditorCallback::MenuOpen()
{
    m_skeletal->Open();
}

T100VOID T1003DEditorCallback::MenuClose()
{
    m_skeletal->Close();
}

T100VOID T1003DEditorCallback::MenuSave()
{
    m_skeletal->Save();
}

T100VOID T1003DEditorCallback::MenuSaveAs()
{
    m_skeletal->SaveAs();
}

T100VOID T1003DEditorCallback::MenuImport()
{
    m_skeletal->Import();
}

T100VOID T1003DEditorCallback::MenuExport()
{
    m_skeletal->Export();
}

T100VOID T1003DEditorCallback::MenuUndo()
{
    m_skeletal->Undo();
}

T100VOID T1003DEditorCallback::MenuRedo()
{
    m_skeletal->Redo();
}

T100VOID T1003DEditorCallback::MenuCut()
{
    m_skeletal->Cut();
}

T100VOID T1003DEditorCallback::MenuCopy()
{
    m_skeletal->Copy();
}

T100VOID T1003DEditorCallback::MenuPaste()
{
    m_skeletal->Paste();
}

T100VOID T1003DEditorCallback::SetMenu(T100WSTRING name, T100BOOL flag)
{
    if(name == L"manager"){
        m_skeletal->SetManager(flag);
    }else if(name == L"properties"){
        m_skeletal->SetProperties(flag);
    }
}

T100VOID T1003DEditorCallback::MenuManager(T100BOOL flag)
{
    m_skeletal->ShowManager(flag);
}

T100VOID T1003DEditorCallback::MenuProperties(T100BOOL flag)
{
    m_skeletal->ShowProperties(flag);
}

T100VOID T1003DEditorCallback::MenuConfig()
{
    m_skeletal->ShowConfig();
}

T100VOID T1003DEditorCallback::MenuSettings()
{
    m_skeletal->ShowSettings();
}

T100VOID T1003DEditorCallback::MenuAbout()
{
    m_skeletal->ShowAbout();
}

T100VOID T1003DEditorCallback::OnKeyDown(T100INT value)
{
    T100WSTRING     result;

    m_skeletal->GetView()->SetDirty();

    T100GameCallback::OnKeyDown(value);

    T100GameCallback::UpdateInfo(result);

    m_skeletal->GetView()->SetStatus(3, result);
}

T100VOID T1003DEditorCallback::OnKeyUp(T100INT value)
{
    T100GameCallback::OnKeyUp(value);
}

T100VOID T1003DEditorCallback::Update(T100INT value)
{
    m_skeletal->GetServe()->GetEntityManager()->Update(value);
    T100Entity* entity  = m_skeletal->GetServe()->GetEntityManager()->GetCurrent();

    m_skeletal->GetView()->GetPropertiesPanel()->Update(value, entity);

    //T100GameCallback::Append(entity);

    m_skeletal->GetView()->GetMainPanel()->SetAppendState();

    m_skeletal->GetView()->Update();
}

T100VOID T1003DEditorCallback::Update(T100Scene* scene)
{
    m_skeletal->GetView()->GetPropertiesPanel()->Update(scene);
}

T100VOID T1003DEditorCallback::UpdateScene(T100Scene* scene)
{
    T100GameCallback::UpdateScene(scene);
}

T100VOID T1003DEditorCallback::Update(T100Entity* entity)
{
    m_skeletal->GetView()->GetPropertiesPanel()->Update(entity->Type, entity);
}

T100VOID T1003DEditorCallback::UpdateMesh(T100Mesh* mesh)
{
    m_skeletal->GetView()->GetPropertiesPanel()->UpdateMesh(mesh);
}

T100VOID T1003DEditorCallback::Update(T100Camera* camera)
{
    m_skeletal->GetView()->GetPropertiesPanel()->Update(camera);
}

T100VOID T1003DEditorCallback::Update(T100Light* light)
{
    m_skeletal->GetView()->GetPropertiesPanel()->Update(light);
}

T100VOID T1003DEditorCallback::Update(T100Material* material)
{
    m_skeletal->GetView()->GetPropertiesPanel()->Update(material);
}

T100VOID T1003DEditorCallback::UpdateInfo()
{
    T100WSTRING         msg;

    T100GameCallback::Update(msg);
    m_skeletal->GetView()->SetStatus(4, msg);
}

T100VOID T1003DEditorCallback::Clear()
{
    m_skeletal->GetView()->GetPropertiesPanel()->Clear();
}

T100VOID T1003DEditorCallback::Append()
{
    T100Entity*     entity          = T100NULL;

    entity  = m_skeletal->GetServe()->GetEntityManager()->GetCurrent();

    m_skeletal->GetServe()->Update(entity);

    T100GameCallback::Append(entity);

    m_skeletal->GetServe()->Append(entity);

    m_skeletal->GetView()->GetScenePanel()->Append(entity);

    m_skeletal->GetView()->GetEntityPanel()->Clear();

    m_skeletal->GetView()->SetDirty();

    T100GameCallback::Visible();
}

T100VOID T1003DEditorCallback::Remove()
{
    T100Entity*     entity          = T100NULL;

    entity  = m_skeletal->GetServe()->GetEntityManager()->GetCurrent();

    T100GameCallback::Remove(entity);

    m_skeletal->GetServe()->Remove(entity);

    m_skeletal->GetView()->GetEntityPanel()->Clear();

    T100GameCallback::Visible();
}

T100VOID T1003DEditorCallback::Append(T100Entity* entity)
{
    T100GameCallback::Append(entity);
}

T100VOID T1003DEditorCallback::Remove(T100Entity* entity)
{
    T100GameCallback::Remove(entity);
    m_skeletal->GetServe()->Remove(entity);
}

T100VOID T1003DEditorCallback::AppendMesh()
{
    m_skeletal->GetServe()->GetEntityManager()->Update(T100ENTITY_MESH);

    T100Entity*     entity          = T100NULL;

    entity  = m_skeletal->GetServe()->GetEntityManager()->GetCurrent();

    m_skeletal->GetServe()->Append(entity);

    m_skeletal->GetView()->GetScenePanel()->AppendMesh(dynamic_cast<T100Mesh*>(entity));

    m_skeletal->GetView()->SetDirty();
}

T100VOID T1003DEditorCallback::AppendCamera()
{
    T100Camera*     camera      = T100NULL;

    camera  = m_skeletal->GetServe()->GetCameraManager()->GetCamera();

    m_skeletal->GetServe()->Append(camera);

    m_skeletal->GetView()->GetScenePanel()->Append(camera);

    m_skeletal->GetView()->SetDirty();
}

T100VOID T1003DEditorCallback::AppendLight()
{
    T100Light*      light       = T100NULL;

    light   = m_skeletal->GetServe()->GetLightManager()->GetLight();

    T100GameCallback::AppendLight(light);

    m_skeletal->GetServe()->AppendLight(light);

    m_skeletal->GetView()->GetScenePanel()->AppendLight(light);

    m_skeletal->GetView()->SetDirty();
}

T100VOID T1003DEditorCallback::AppendMaterial()
{
    T100Material*      material       = T100NULL;

    material   = m_skeletal->GetServe()->GetMaterialManager()->GetMaterial();

    m_skeletal->GetServe()->Append(material);

    m_skeletal->GetView()->GetScenePanel()->AppendMaterial(material);

    m_skeletal->GetView()->SetDirty();
}

T100VOID T1003DEditorCallback::Position(T100UINT x, T100UINT y)
{
    T100Entity* entity      = m_skeletal->GetServe()->GetEntityManager()->GetCurrent();

    T100Editable*   editable    = dynamic_cast<T100Editable*>(entity);

    if(editable){
        T100GameCallback::Position(x, y, entity->GetPosition().Z);
    }else if(entity){
        T100GameCallback::Position(x, y, entity->GetPosition().Z);
    }
}

T100VOID T1003DEditorCallback::Rotation(T100INT x, T100INT y)
{
    T100GameCallback::Rotation(x, y);
}

T100VOID T1003DEditorCallback::Move(T100UINT x, T100UINT y)
{
    wxString            msg;
    wxString            value;

    msg     = wxString::Format("X : %04u Y : %04u ", x, y);

    m_skeletal->GetView()->SetStatus(2, msg);
}

T100VOID T1003DEditorCallback::SetDirty()
{
    m_skeletal->GetView()->SetDirty();
}

T100VOID T1003DEditorCallback::Cancel()
{
    if(m_skeletal->GetView()->GetMainPanel()->m_appendState){
        T1003DEditorCallback::Remove();
        m_skeletal->GetView()->GetMainPanel()->SetCursor(wxNullCursor);
        m_skeletal->GetView()->GetEntityPanel()->SetCursor(wxNullCursor);
        m_skeletal->GetView()->GetMainPanel()->m_appendState    = T100FALSE;
    }
}

T100VOID T1003DEditorCallback::SetBundle(T100BOOL flag, T100Entity* entity)
{
    entity->SetBundle(flag);
    T100GameCallback::SetBundle(entity);
}

T100VOID T1003DEditorCallback::Append(T100Camera* camera)
{
    m_skeletal->GetView()->GetScenePanel()->Append(camera);
}

T100VOID T1003DEditorCallback::SaveConfig()
{
    m_skeletal->GetStore()->GetSettingsStore().SaveConfigFile();
}

T100VOID T1003DEditorCallback::GetMaterialList(wxArrayString& names, wxArrayInt& values, T100WSTRING& name, T100UINT& value)
{
    m_skeletal->GetServe()->GetMaterialManager()->GetMaterialList(names, values, name, value);
}

T100VOID T1003DEditorCallback::GetMaterialNames(wxArrayString& names)
{
    m_skeletal->GetServe()->GetMaterialManager()->GetMaterialNames(names);
}

T100VOID T1003DEditorCallback::GetDescriptions(wxArrayString& labels, wxArrayInt& values)
{
    m_skeletal->GetServe()->GetSettingsServe().GetDescriptions(labels, values);
}

T100VOID T1003DEditorCallback::GetDescriptionReferences(wxArrayString& labels, wxArrayInt& values)
{
    m_skeletal->GetServe()->GetSettingsServe().GetDescriptionReferences(labels, values);
}

T100VOID T1003DEditorCallback::GetParameters(wxArrayString& labels, wxArrayInt& values)
{
    m_skeletal->GetServe()->GetSettingsServe().GetParameters(labels, values);
}

T100VOID T1003DEditorCallback::GetParameterReferences(wxArrayString& labels, wxArrayInt& values)
{
    m_skeletal->GetServe()->GetSettingsServe().GetParameterReferences(labels, values);
}

T100VOID T1003DEditorCallback::GetVertexShaders(wxArrayString& labels, wxArrayInt& values)
{
    m_skeletal->GetServe()->GetSettingsServe().GetVertexShaders(labels, values);
}

T100VOID T1003DEditorCallback::GetPixelShaders(wxArrayString& labels, wxArrayInt& values)
{
    m_skeletal->GetServe()->GetSettingsServe().GetPixelShaders(labels, values);
}

T100VOID T1003DEditorCallback::GetShaders(wxArrayString& labels, wxArrayInt& values)
{
    m_skeletal->GetServe()->GetSettingsServe().GetShaders(labels, values);
}

T1003DEDITOR_VERTEX_DESCRIPTION_VECTOR& T1003DEditorCallback::GetDescriptions()
{
    return m_skeletal->GetServe()->GetSettingsServe().GetVertexDescriptions();
}

T100VOID T1003DEditorCallback::SaveDescriptions(T1003DEDITOR_VERTEX_DESCRIPTION_VECTOR& descs)
{
    m_skeletal->GetStore()->GetSettingsStore().SaveDescriptions(descs);
}

T1003DEDITOR_DESCRIPTION_REFERENCE_DATA_VECTOR& T1003DEditorCallback::GetDescriptionReferences()
{
    return m_skeletal->GetServe()->GetSettingsServe().GetDescriptionReferences();
}

T100VOID T1003DEditorCallback::SaveDescriptionReferences(T1003DEDITOR_DESCRIPTION_REFERENCE_DATA_VECTOR& value)
{
    m_skeletal->GetStore()->GetSettingsStore().SaveDescriptionReferences(value);
}

T1003DEDITOR_SHADER_PARAMETER_VECTOR& T1003DEditorCallback::GetParameters()
{
    return m_skeletal->GetServe()->GetSettingsServe().GetShaderParameters();
}

T100VOID T1003DEditorCallback::SaveParameters(T1003DEDITOR_SHADER_PARAMETER_VECTOR& value)
{
    m_skeletal->GetStore()->GetSettingsStore().SaveParameters(value);
}

T1003DEDITOR_PARAMETER_REFERENCE_DATA_VECTOR& T1003DEditorCallback::GetParameterReferences()
{
    return m_skeletal->GetServe()->GetSettingsServe().GetParameterReferences();
}

T100VOID T1003DEditorCallback::SaveParameterReferences(T1003DEDITOR_PARAMETER_REFERENCE_DATA_VECTOR& value)
{
    m_skeletal->GetStore()->GetSettingsStore().SaveParameterReferences(value);
}

T1003DEDITOR_SHADER_FILE_VECTOR& T1003DEditorCallback::GetVertexShaders()
{
    return m_skeletal->GetServe()->GetSettingsServe().GetVertexShaders();
}

T100VOID T1003DEditorCallback::SaveVertexShaders(T1003DEDITOR_SHADER_FILE_VECTOR& value)
{
    m_skeletal->GetStore()->GetSettingsStore().SaveVertexShaders(value);
}

T1003DEDITOR_SHADER_FILE_VECTOR& T1003DEditorCallback::GetPixelShaders()
{
    return m_skeletal->GetServe()->GetSettingsServe().GetPixelShaders();
}

T100VOID T1003DEditorCallback::SavePixelShaders(T1003DEDITOR_SHADER_FILE_VECTOR& value)
{
    m_skeletal->GetStore()->GetSettingsStore().SavePixelShaders(value);
}

T1003DEDITOR_SHADER_VECTOR& T1003DEditorCallback::GetShaders()
{
    return m_skeletal->GetServe()->GetSettingsServe().GetShaders();
}

T100VOID T1003DEditorCallback::SaveShaders(T1003DEDITOR_SHADER_VECTOR& value)
{
    m_skeletal->GetStore()->GetSettingsStore().SaveShaders(value);
}
