#include "game/T100GameCallback.h"

#include <sstream>
#include "game/T100GameThread.h"
#include "skeletal/T1003DEditorScene.h"

std::atomic_bool        T100GameCallback::m_created;
T100GameThread*         T100GameCallback::m_threadPtr       = T100NULL;

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
    m_created       = T100FALSE;
    m_threadPtr     = T100NEW T100GameThread();
}

T100VOID T100GameCallback::Uninit()
{
    T100SAFE_DELETE m_threadPtr;
}

T100VOID T100GameCallback::Create(HWND hwnd, T100UINT width, T100UINT height)
{
    //1591, 904
    width   = width + 21;
    height  = height + 21;
    m_threadPtr->Create(hwnd, width, height);
    m_created   = T100TRUE;

    m_threadPtr->Start();
}

T100VOID T100GameCallback::Destroy()
{
    m_threadPtr->Stop();
}

T100VOID T100GameCallback::Append(T100Entity* entity)
{
    T1003DEditorScene*      scenePtr        = T100NULL;

    scenePtr    = m_threadPtr->GetScenePtr();

    scenePtr->Append((T1003DMesh*)entity);

    if(entity->IsEditable()){
        T1003DMesh* selection   = ((T1003DMesh*)entity)->GetSelectionPtr();
        scenePtr->Append(selection);
    }

    scenePtr->m_selection   = entity;
}

T100VOID T100GameCallback::Remove(T100Entity* entity)
{
    T1003DEditorScene*      scenePtr        = T100NULL;

    scenePtr    = m_threadPtr->GetScenePtr();

    scenePtr->Remove(entity);

    if(entity->IsEditable()){
        T1003DMesh* selection   = ((T1003DMesh*)entity)->GetSelectionPtr();
        scenePtr->Remove(selection);
    }

    scenePtr->m_selection   = T100NULL;
}

T100VOID T100GameCallback::Clear()
{

}

T100VOID T100GameCallback::Visible()
{
    m_threadPtr->GetScenePtr()->m_horizontal.SetVisible(T100FALSE);
    m_threadPtr->GetScenePtr()->m_vertical.SetVisible(T100FALSE);
}

T100VOID T100GameCallback::Update()
{

}

T100VOID T100GameCallback::OnKeyDown(T100INT key)
{
    T1003DInput&    input   = m_threadPtr->GetGamePtr()->GetInput();

    input.OnKeyDown(key);

    if(key == 67){
        m_threadPtr->GetScenePtr()->Reset();
    }
}

T100VOID T100GameCallback::OnKeyUp(T100INT key)
{
    T1003DInput&    input   = m_threadPtr->GetGamePtr()->GetInput();

    input.OnKeyUp(key);
}

T100VOID T100GameCallback::Position(T100FLOAT x, T100FLOAT y, T100FLOAT z, T100WSTRING& msg)
{
    T1003DEditorScene*      scene           = T100NULL;
    T100Vector3f    result;

    scene   = m_threadPtr->GetScenePtr();

    scene->ConvertToWorld(x, y, z, result);
    scene->m_selection->SetPosition(result);

    scene->m_horizontal.SetPosition(0, y, 0);
    scene->m_vertical.SetPosition(x, 0, 0);

    scene->m_horizontal.SetVisible(T100TRUE);
    scene->m_vertical.SetVisible(T100TRUE);

    std::wstringstream   wss;

    wss << "X : " << result.X << " ";
    wss << "Y : " << result.Y << " ";
    wss << "Z : " << result.Z << " ";

    msg = wss.str();
}

T100VOID T100GameCallback::Rotation(T100FLOAT, T100FLOAT)
{

}

T100VOID T100GameCallback::UpdateInfo(T100UINT& value)
{
    value = m_threadPtr->GetGamePtr()->GetTimer().GetFramesPerSecond();
}

T100VOID T100GameCallback::UpdateInfo(T100WSTRING& value)
{
    T1003DCamera*   cameraPtr   = m_threadPtr->GetGamePtr()->GetCameraPtr();

    if(cameraPtr){
        T100Vector3f&   position    = cameraPtr->GetPosition();
        T100Vector3f&   lookat      = cameraPtr->GetLookAt();
        T100Vector3f&   up          = cameraPtr->GetUp();

        std::wstringstream   wss;

        wss << "X : " << position.X << " ";
        wss << "Y : " << position.Y << " ";
        wss << "Z : " << position.Z << " ";
        wss << "X : " << lookat.X << " ";
        wss << "Y : " << lookat.Y << " ";
        wss << "Z : " << lookat.Z << " ";
        wss << "X : " << up.X << " ";
        wss << "Y : " << up.Y << " ";
        wss << "Z : " << up.Z << " ";

        value = wss.str();
    }
}

T100VOID T100GameCallback::SetBundle(T100Entity* entity)
{
    T1003DEditorScene*      scenePtr        = T100NULL;

    scenePtr    = m_threadPtr->GetScenePtr();

    scenePtr->Remove(entity);
    scenePtr->Append(entity);
}
