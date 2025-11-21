#include "T100GameCallback.h"

#include <sstream>
#include "T100Debug.h"
#include "T1003DEditorConfig.h"
#include "T100GameScene.h"
#include "T100GameThread.h"

#include "data/T100Scene.h"
#include "entity/T100Editable.h"

std::atomic_bool        T100GameCallback::m_created;
T100GameThread*         T100GameCallback::m_thread          = T100NULL;
T100GameScene*          T100GameCallback::m_scene           = T100NULL;

T100GameCallback::T100GameCallback()
{
    //ctor
}

T100GameCallback::~T100GameCallback()
{
    //dtor
}

T100VOID T100GameCallback::Init()
{
    m_created   = T100FALSE;
    m_thread    = T100NEW T100GameThread();
}

T100VOID T100GameCallback::Uninit()
{
    T100SAFE_DELETE m_thread;
}

T100VOID T100GameCallback::Create(HWND hwnd, T100UINT width, T100UINT height)
{
    //1591, 904
    width   = width + 21;
    height  = height + 21;
    m_thread->Create(hwnd, width, height);
    m_created   = T100TRUE;

    m_scene     = T100NEW T100GameScene(m_thread->GetGame()->GetRenderer());
    m_thread->GetGame()->SetScene(m_scene);

    m_scene->Width  = T1003DEditorConfig::Width;
    m_scene->Height = T1003DEditorConfig::Height;

    m_thread->Start();
}

T100VOID T100GameCallback::Destroy()
{
    m_thread->Stop();
}

T100VOID T100GameCallback::Append(T100Entity* entity)
{
    m_scene->Append(entity);

    //T100Editable*   editable    = dynamic_cast<T100Editable*>(entity);

    //if(editable && editable->m_editable){
    //    m_scene->Append(editable->m_selection);
    //}
}

T100VOID T100GameCallback::Remove(T100Entity* entity)
{
    m_scene->Remove(entity);
}

T100VOID T100GameCallback::Position(T100UINT x, T100UINT y, T100FLOAT z)
{
    T100Vector3     result;

    m_scene->ConvertToWorld(x, y, z, result);

    //m_scene->m_current->SetPosition(result.X, result.Y, result.Z);

    T100Entity& entity  = *m_scene->m_current;
    if(m_scene->m_editable){
        m_scene->m_editable->SetPosition(result.X, result.Y, result.Z);
    }else{
        //m_scene->m_current->SetPosition(result.X, result.Y, result.Z);
    }

    m_scene->m_horizontal.SetPosition(0, y, 0);
    m_scene->m_vertical.SetPosition(x, 0, 0);

    m_scene->m_horizontal.SetVisible(T100TRUE);
    m_scene->m_vertical.SetVisible(T100TRUE);
}

T100VOID T100GameCallback::Rotation(T100INT x, T100INT y)
{
    /*
    if(x > 0){
        m_scene->TurnRight();
    }else if(x < 0){
        m_scene->TurnLeft();
    }

    if(y > 0){
        m_scene->TurnUp();
    }else if(y < 0){
        m_scene->TurnDown();
    }
    */
}

T100VOID T100GameCallback::AppendLight(T100Light* light)
{
    m_scene->AppendLight(light);
}

T100VOID T100GameCallback::RemoveLight(T100Light* light)
{
    m_scene->RemoveLight(light);
}

T100VOID T100GameCallback::OnKeyDown(T100INT value)
{
    m_thread->GetGame()->GetInputPtr()->OnKeyDown(value);
}

T100VOID T100GameCallback::OnKeyUp(T100INT value)
{
    m_thread->GetGame()->GetInputPtr()->OnKeyUp(value);
}


T100VOID T100GameCallback::Clear()
{
    m_scene->Reset();
}

T100VOID T100GameCallback::Visible()
{
    m_scene->m_horizontal.SetVisible(T100FALSE);
    m_scene->m_vertical.SetVisible(T100FALSE);
}

T100VOID T100GameCallback::UpdateInfo(T100WSTRING& result)
{
    T100Vector3     position    = m_scene->GetCamera()->GetPosition();
    T100Vector3     lookat      = m_scene->GetCamera()->GetLookAt();
    T100Vector3     up          = m_scene->GetCamera()->GetUp();

    std::wstringstream      wss;

    wss << "Camera : <" << position.X << " : ";
    wss << position.Y << " : ";
    wss << position.Z << "> ";
    wss << "LookAt : <" << lookat.X << " : ";
    wss << lookat.Y << " : ";
    wss << lookat.Z << "> ";
    wss << "Up : <" << up.X << " : ";
    wss << up.Y << " : ";
    wss << up.Z << "> ";

    result = wss.str();
}

T100VOID T100GameCallback::Update(T100WSTRING& result)
{
    T100UINT    fps     = m_thread->GetGame()->GetRenderer()->GetTimer().GetFramesPerSecond();

    std::wstringstream  wss;

    wss << fps << L"fps";

    result = wss.str();
}

T100VOID T100GameCallback::SetBundle(T100Entity* entity)
{
    m_scene->SetBundle(entity);
}

T100VOID T100GameCallback::UpdateScene(T100Scene* scene)
{
    m_scene->VertexDescriptions     = scene->VertexDescriptions;
    m_scene->ShaderParameters       = scene->ShaderParameters;

    m_scene->VertexShaderFile       = scene->VertexShaderFile;
    m_scene->PixelShaderFile        = scene->PixelShaderFile;
}
