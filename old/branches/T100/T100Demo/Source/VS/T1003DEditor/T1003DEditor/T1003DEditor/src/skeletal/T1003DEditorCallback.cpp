#include "skeletal/T1003DEditorCallback.h"

//#include "T100Debug.h"
#include "serve/T1003DEditorServe.h"
#include "view/T1003DEditorView.h"
#include "skeletal/T1003DEditorSkeletal.h"

#include "game/T100GameCallback.h"
#include "T1003DEditorMain.h"
#include "view/panels/T1003DEditorMainPanel.h"
#include "view/panels/T1003DEditorScenePanel.h"
#include "view/panels/T1003DEditorEntityPanel.h"
#include "view/panels/T1003DEditorPropertiesPanel.h"

#include "link/T100Entity.h"

T1003DEditorSkeletal*       T1003DEditorCallback::m_skeletal            = T100NULL;

T1003DEditorCallback::T1003DEditorCallback()
{
    //ctor
}

T1003DEditorCallback::~T1003DEditorCallback()
{
    //dtor
}

T100VOID T1003DEditorCallback::Create(T1003DEditorFrame* frame)
{
    T100GameCallback::Init();
    m_skeletal  = T100NEW T1003DEditorSkeletal();

    m_skeletal->Create(frame);

    T100GameCallback::Create(
        m_skeletal->GetView()->GetMainPanel()->GetHWND(),
        m_skeletal->GetView()->GetMainPanel()->GetWidth(),
        m_skeletal->GetView()->GetMainPanel()->GetHeight());
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

T100VOID T1003DEditorCallback::MenuQuit()
{
    m_skeletal->Quit();
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

T100VOID T1003DEditorCallback::MenuAbout()
{
    m_skeletal->ShowAbout();
}

T100VOID T1003DEditorCallback::OnKeyDown(T100INT value)
{
    m_skeletal->GetView()->SetDirty();

    T100GameCallback::OnKeyDown(value);

    T100WSTRING     msg;

    T100GameCallback::UpdateInfo(msg);

    m_skeletal->GetView()->SetStatus(4, msg);
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

    T100GameCallback::Append(entity);

    m_skeletal->GetView()->GetMainPanel()->SetAppendState();

    m_skeletal->GetView()->Update();
}

T100VOID T1003DEditorCallback::Update(T100Entity* entity)
{
    m_skeletal->GetView()->GetPropertiesPanel()->Update(entity->Type, entity);
}

T100VOID T1003DEditorCallback::Update(T1003DCamera* camera)
{
    m_skeletal->GetView()->GetPropertiesPanel()->Update(camera);
}

T100VOID T1003DEditorCallback::Update(T1003DLight* light)
{
    m_skeletal->GetView()->GetPropertiesPanel()->Update(light);
}

T100VOID T1003DEditorCallback::UpdateInfo()
{
    T100WSTRING     msg;
    T100UINT        value;

    T100GameCallback::UpdateInfo(value);

    msg     = wxString::Format("%u fps", value);

    m_skeletal->GetView()->SetStatus(5, msg);
}

T100VOID T1003DEditorCallback::Append()
{
    T100Entity*     entity          = T100NULL;

    entity  = m_skeletal->GetServe()->GetEntityManager()->GetCurrent();

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

    m_skeletal->GetView()->GetPropertiesPanel()->Clear();

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
    //T100Camera*     camera      = T100NULL;

    //camera  = m_skeletal->GetServe()->GetCameraManager()->GetCamera();

    //m_skeletal->GetServe()->Append(camera);

    //m_skeletal->GetView()->GetScenePanel()->Append(camera);

    m_skeletal->GetView()->SetDirty();
}

T100VOID T1003DEditorCallback::AppendCamera()
{
    T1003DCamera*   camera      = T100NULL;

    camera  = m_skeletal->GetServe()->GetCameraManager()->GetCamera();

    m_skeletal->GetServe()->Append(camera);

    m_skeletal->GetView()->GetScenePanel()->Append(camera);

    m_skeletal->GetView()->SetDirty();
}

T100VOID T1003DEditorCallback::AppendLight()
{
    T1003DLight*    light       = T100NULL;

    light   = m_skeletal->GetServe()->GetLightManager()->GetLight();

    m_skeletal->GetServe()->Append(light);

    m_skeletal->GetView()->GetScenePanel()->Append(light);

    m_skeletal->GetView()->SetDirty();
}

T100VOID T1003DEditorCallback::Position(T100UINT x, T100UINT y)
{
    T100Entity* entity      = m_skeletal->GetServe()->GetEntityManager()->GetCurrent();

    T100Editable*   editable    = dynamic_cast<T100Editable*>(entity);

    T100WSTRING     msg;

    if(editable){
        T100GameCallback::Position(x, y, entity->GetPosition().Z, msg);
    }else if(entity){
        T100GameCallback::Position(x, y, entity->GetPosition().Z, msg);
    }

    m_skeletal->GetView()->SetStatus(3, msg);
}

T100VOID T1003DEditorCallback::Rotation(T100INT x, T100INT y)
{
    T100GameCallback::Rotation(x, y);
}

T100VOID T1003DEditorCallback::Move(T100UINT x, T100UINT y)
{
    T100WSTRING         result;
    wxString            msg;
    wxString            value;

    msg     = wxString::Format("X : %04u Y : %04u ", x, y);

    value   = msg + result;

    m_skeletal->GetView()->SetStatus(2, value);
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

T100VOID T1003DEditorCallback::Append(T1003DCamera* camera)
{
    m_skeletal->GetView()->GetScenePanel()->Append(camera);
}
