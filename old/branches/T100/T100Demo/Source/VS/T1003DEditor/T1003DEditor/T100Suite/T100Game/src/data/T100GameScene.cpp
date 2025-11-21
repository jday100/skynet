#include "data/T100GameScene.h"

#include "T100Game.h"
#include "tools/T100GameTools.h"
#include "entity/T100Line.h"

#define     max(a, b)       (a) > (b) ? (a) : (b)

T100GameScene::T100GameScene(T100Game* game, T1003D_SCENE_SPATIAL_TYPE type) :
    m_gamePtr(game),
    m_rendererPtr(T100NULL),
    m_type(type),
    m_staticMeshes(),
    m_dynamicsMeshes()
{
    //ctor
    init();
}

T100GameScene::~T100GameScene()
{
    //dtor
    uninit();
}

T100VOID T100GameScene::init()
{
    m_rendererPtr   = m_gamePtr->GetRenderer();
    InitAssetsPath();
}

T100VOID T100GameScene::uninit()
{

}

T100VOID T100GameScene::InitAssetsPath()
{
    WCHAR   assetsPath[512];
    GetAssetsPath(assetsPath, _countof(assetsPath));
    m_assetsPath = assetsPath;
}

T100WSTRING T100GameScene::GetAssetFullPath(T100WSTRING assetName)
{
    return m_assetsPath + L"..\\..\\resources\\" + assetName;
}

T100VOID T100GameScene::Append(T1003DMesh* meshPtr)
{
    AppendDynamicsMesh(meshPtr);
}

T100VOID T100GameScene::Remove(T1003DMesh* meshPtr)
{
    RemoveDynamicsMesh(meshPtr);
}

T100VOID T100GameScene::AppendStaticMesh(T1003DMesh* meshPtr)
{
    std::lock_guard<std::mutex>     lock(m_mutex);

    ConvertPath(meshPtr);

    if(meshPtr->Type == T100ENTITY_LINE){
        SetLineLength(meshPtr);
    }

    meshPtr->Load();

    m_staticMeshes.push_back(meshPtr);
}

T100VOID T100GameScene::ClearStaticMeshes()
{
    std::lock_guard<std::mutex>     lock(m_mutex);

}

T100VOID T100GameScene::PreloadDynamicsMesh(T1003DMesh* meshPtr)
{
    std::lock_guard<std::mutex>     lock(m_mutex);

    ConvertPath(meshPtr);

    if(meshPtr->Type == T100ENTITY_LINE){
        SetLineLength(meshPtr);
    }

    meshPtr->Load();

    m_dynamicsMeshes.push_back(meshPtr);
}

T100VOID T100GameScene::AppendDynamicsMesh(T1003DMesh* meshPtr)
{
    std::lock_guard<std::mutex>     lock(m_mutex);

    ConvertPath(meshPtr);

    if(meshPtr->Type == T100ENTITY_LINE){
        SetLineLength(meshPtr);
    }

    meshPtr->Load();

    m_dynamicsMeshes.push_back(meshPtr);

    m_rendererPtr->Append(meshPtr);
}

T100VOID T100GameScene::RemoveDynamicsMesh(T1003DMesh* meshPtr)
{
    std::lock_guard<std::mutex>     lock(m_mutex);

    T1003DMESH_VECTOR::iterator     it;

    for(it = m_dynamicsMeshes.begin(); it != m_dynamicsMeshes.end(); ++it){
        if(meshPtr == *it){
            meshPtr->GetInstancePtr()->Clear();
            m_dynamicsMeshes.erase(it);
            return;
        }
    }
}

T100VOID T100GameScene::LoadStaticMeshes(T1003DRenderer* rendererPtr)
{
    std::lock_guard<std::mutex>     lock(m_mutex);

    for(T1003DMesh*     mesh : m_staticMeshes){
        rendererPtr->Append(mesh);
    }
}

T100VOID T100GameScene::LoadDynamicsMeshes(T1003DRenderer* rendererPtr)
{
    std::lock_guard<std::mutex>     lock(m_mutex);

    for(T1003DMesh*     mesh : m_dynamicsMeshes){
        rendererPtr->Append(mesh);
    }
}

T100VOID T100GameScene::SetBundle(T1003DMesh* meshPtr)
{
    m_rendererPtr->SetBundle(meshPtr);
}

T100VOID T100GameScene::ScreenToWorld(T100UINT x, T100UINT y, T100FLOAT z, T100Vector3f& result)
{
    T100Vector3f    source;
    T100Vector3f    value;

    T100FLOAT   w   = (x - m_rendererPtr->GetWidth() / 2.0f) / (m_rendererPtr->GetWidth() / 2.0f);
    T100FLOAT   h   = (m_rendererPtr->GetHeight() / 2.0f - y) / (m_rendererPtr->GetHeight() / 2.0f);

    source  = { static_cast<float>(x), static_cast<float>(y), 0};

    UnprojectCommon(source, value);

    result.X    = value.X;
    result.Y    = value.Y;
    result.Z    = value.Z;
}

T100VOID T100GameScene::Unproject(T100Vector3f source, T100Vector3f& target)
{
    XMVECTOR    value;
    XMVECTOR    result;

    T100FLOAT   x   = 0;
    T100FLOAT   y   = 0;
    T100UINT    width;
    T100UINT    height;
    T100FLOAT   minz    = 0.0f;
    T100FLOAT   maxz    = 1.0f;
    XMMATRIX    project;
    XMMATRIX    view;
    XMMATRIX    world;

    value   = XMLoadFloat3((XMFLOAT3*)&source.FLOAT3);
    width   = m_rendererPtr->GetWidth();
    height  = m_rendererPtr->GetHeight();

    minz    = 1.0f;
    maxz    = 1000.0f;

    //project = m_dx12->GetCamera().GetProjectionMatrix(0.8f, m_dx12->m_dx12.m_aspectRatio);
    //view    = m_dx12->GetCamera().GetViewMatrix();
    world   = XMMatrixTranslation(0, 0, 0);

    result = XMVector3Unproject(value, x, y, static_cast<float>(width), static_cast<float>(height), minz, maxz, project, view, world);

    XMStoreFloat3((XMFLOAT3*)&target.FLOAT3, result);
}

T100VOID T100GameScene::UnprojectCommon(T100Vector3f source, T100Vector3f& target)
{
    T100Vector3f    value;
    T100Vector3f    result;

    T100FLOAT       x   = 0;
    T100FLOAT       y   = 0;
    T100UINT        width;
    T100UINT        height;
    T100FLOAT       minz;
    T100FLOAT       maxz;

    T100Matrix4f    world;
    T100Matrix4f    view;
    T100Matrix4f    project;

    T1003DCamera*     camera          = T100NULL;

    camera  = m_rendererPtr->GetCameraPtr();

    value   = source;
    width   = m_rendererPtr->GetWidth();
    height  = m_rendererPtr->GetHeight();

    if(camera){
        minz    = camera->GetNearPlane();
        maxz    = camera->GetFarPlane();

        camera->GetViewMatrix(view);
        camera->GetProjectionMatrix(project);

        camera->GetTranslation(world);

        camera->Unproject(value, x, y, width, height, minz, maxz, project, view, world, result);

    }else{


        T100FLOAT   w   = (source.X - m_rendererPtr->GetWidth() / 2.0f) / (m_rendererPtr->GetWidth() / 2.0f);
        T100FLOAT   h   = (m_rendererPtr->GetHeight() / 2.0f - source.Y) / (m_rendererPtr->GetHeight() / 2.0f);

        result  = {w, h, source.Z};
    }

    target  = result;
}

T100VOID T100GameScene::ConvertToWorld(T100UINT x, T100UINT y, T100FLOAT z, T100Vector3f& result)
{
    T100Vector3f    source;
    T100Vector3f    value;

    ScreenToWorld(x, y, z, source);

    GetWorld(source, z, value);

    result.X    = value.X;
    result.Y    = value.Y;
    result.Z    = value.Z;
}

T100VOID T100GameScene::GetWorld(T100Vector3f source, T100FLOAT z, T100Vector3f& result)
{
    T100Vector3f    target;

    T1003DCamera*     camera      = T100NULL;

    camera      = m_rendererPtr->GetCameraPtr();

    if(camera){
        target  = camera->GetPosition();

        result.X    = (target.X - source.X) * (z - source.Z) / (target.Z - source.Z) + source.X;
        result.Y    = (target.Y - source.Y) * (z - source.Z) / (target.Z - source.Z) + source.Y;
        result.Z    = z;
    }else{
        result  = std::move(source);
    }
}

T100VOID T100GameScene::SetLineLength(T1003DMesh* meshPtr)
{
    T100Line*       linePtr         = T100NULL;

    linePtr = dynamic_cast<T100Line*>(meshPtr);

    if(linePtr && linePtr->GetLength() ==  -1){
        linePtr->SetLength(GetSceneLength());
    }
}

T100FLOAT T100GameScene::GetSceneLength()
{
    T100FLOAT   result;

    switch(m_type){
    case T1003D_SCENE_RECTANGLE:
        {
            result  = max(m_length, m_width);
            result  = max(result, m_height);
        }
        break;
    case T1003D_SCENE_SPHERE:
        {

        }
        break;
    }

    result *= 3;
    return result;
}

T100VOID T100GameScene::SetSpace(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_length    = x;
    m_width     = y;
    m_height    = z;
}

T100VOID T100GameScene::ConvertPath(T1003DMesh* meshPtr)
{
    if(meshPtr->VertexShaderFile.REALPATH.empty()){
        meshPtr->VertexShaderFile.REALPATH  = GetAssetFullPath(meshPtr->VertexShaderFile.FILE);
    }
    if(meshPtr->PixelShaderFile.REALPATH.empty()){
        meshPtr->PixelShaderFile.REALPATH   = GetAssetFullPath(meshPtr->PixelShaderFile.FILE);
    }

    if(meshPtr->Type == T100ENTITY_CITY){
        if(meshPtr->PixelShaderFile1.REALPATH.empty()){
            meshPtr->PixelShaderFile1.REALPATH  = GetAssetFullPath(meshPtr->PixelShaderFile1.FILE);
        }
        if(meshPtr->PixelShaderFile2.REALPATH.empty()){
            meshPtr->PixelShaderFile2.REALPATH  = GetAssetFullPath(meshPtr->PixelShaderFile2.FILE);
        }
        if(meshPtr->MeshDataFile.REALPATH.empty()){
            meshPtr->MeshDataFile.REALPATH  = GetAssetFullPath(meshPtr->MeshDataFile.FILE);
        }
    }
}
