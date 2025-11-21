#include "T100DX12Scene.h"

#include <d3dcompiler.h>
#include "T100Unicode.h"
#include "T100DX12Tools.h"
#include "T100DX12Renderer.h"

T100DX12Scene::T100DX12Scene(T100DX12Renderer* renderer) :
    m_dx12(renderer)
{
    //ctor
    init();
}

T100DX12Scene::~T100DX12Scene()
{
    //dtor
    uninit();
}

T100VOID T100DX12Scene::init()
{
    InitAssetsPath();
}

T100VOID T100DX12Scene::uninit()
{

}

T100DX12Renderer* T100DX12Scene::GetRenderer()
{
    return m_dx12;
}

T100DX12SceneManager* T100DX12Scene::GetSceneManager()
{
    return &m_dx12->m_dx12.m_scene_manager;
}

T100VOID T100DX12Scene::LoadStaticEntities()
{
    for(T100Entity* entity : m_static_entities)
    {
        entity->Load(this);
    }
}

T100VOID T100DX12Scene::LoadDynamicsEntities()
{
    for(T100Entity* entity : m_dynamics_entities)
    {
        entity->Load(this);
    }
}

T100VOID T100DX12Scene::Append(T100Entity* entity)
{
    AppendDynamicsEntity(entity);
}

T100VOID T100DX12Scene::Remove(T100Entity* entity)
{
    RemoveDynamicsEntity(entity);
}

T100VOID T100DX12Scene::AppendLight(T100Light* light)
{
    light->Load(this);
    m_dx12->m_dx12.GetLightManager().Append(light);
}

T100VOID T100DX12Scene::RemoveLight(T100Light* light)
{
    m_dx12->m_dx12.GetLightManager().Remove(light);
}

T100VOID T100DX12Scene::AppendStaticEntity(T100Entity* entity)
{
    std::lock_guard<std::mutex>     lock(m_mutex);
    m_static_entities.push_back(entity);
}

T100VOID T100DX12Scene::ClearStaticEntities()
{
    m_static_entities.clear();
}

T100VOID T100DX12Scene::AppendDynamicsEntity(T100Entity* entity)
{
    std::lock_guard<std::mutex>     lock(m_mutex);
    entity->Load(this);
    m_pending_entities.push_back(entity);
}

T100VOID T100DX12Scene::RemoveDynamicsEntity(T100Entity* entity)
{
    std::lock_guard<std::mutex>     lock(m_mutex);

    T100ENTITY_VECTOR::iterator     it;

    for(it = m_dynamics_entities.begin(); it != m_dynamics_entities.end(); ++it){
        if(entity == *it){
            entity->Clear();
            m_dynamics_entities.erase(it);
            return;
        }
    }
}

T100VOID T100DX12Scene::RemoveDynamicsEntityUnlock(T100Entity* entity)
{
    T100ENTITY_VECTOR::iterator     it;

    for(it = m_dynamics_entities.begin(); it != m_dynamics_entities.end(); ++it){
        if(entity == *it){
            entity->Clear();
            m_dynamics_entities.erase(it);
            return;
        }
    }
}

T100VOID T100DX12Scene::LoadShaderFile(T100WSTRING file, UINT8** data, UINT* length)
{
    ThrowIfFailed(ReadDataFromFile(GetAssetFullPath(file).c_str(), data, length));
}

T100VOID T100DX12Scene::LoadMeshFile(T100WSTRING file, UINT8** data, UINT* length)
{
    ThrowIfFailed(ReadDataFromFile(GetAssetFullPath(file).c_str(), data, length));
}

T100VOID T100DX12Scene::CompileShaderFile(T100WSTRING file, T100STRING entrypoint, T100STRING target, ComPtr<ID3DBlob>& shader)
{
    T100UINT        compileFlags        = 0;

    ComPtr<ID3DBlob>        error;

    ThrowIfFailed(D3DCompileFromFile(GetAssetFullPath(file).c_str(), nullptr, nullptr, entrypoint.c_str(), target.c_str(), compileFlags, 0, &shader, nullptr));
}

T100VOID T100DX12Scene::CompileShaderFile(T100WSTRING file, T100WSTRING entrypoint, T100WSTRING target, ComPtr<ID3DBlob>& shader)
{
    T100UINT        compileFlags        = 0;
    T100STRING      entry;
    T100STRING      value;

    entry   = T100Unicode::to_string8(entrypoint);
    value   = T100Unicode::to_string8(target);

    ComPtr<ID3DBlob>        error;

    ThrowIfFailed(D3DCompileFromFile(GetAssetFullPath(file).c_str(), nullptr, nullptr, entry.c_str(), value.c_str(), compileFlags, 0, &shader, nullptr));
}

T100VOID T100DX12Scene::CompileShaderFile1(T100WSTRING file, T100WSTRING entrypoint, T100WSTRING target, ComPtr<ID3DBlob>& shader)
{
    T100UINT        compileFlags        = D3DCOMPILE_ENABLE_UNBOUNDED_DESCRIPTOR_TABLES;
    T100STRING      entry;
    T100STRING      value;

    entry   = T100Unicode::to_string8(entrypoint);
    value   = T100Unicode::to_string8(target);

    ComPtr<ID3DBlob>        error;

    ThrowIfFailed(D3DCompileFromFile(GetAssetFullPath(file).c_str(), nullptr, nullptr, entry.c_str(), value.c_str(), compileFlags, 0, &shader, nullptr));
}

T100VOID T100DX12Scene::InitAssetsPath()
{
    WCHAR   assetsPath[512];
    GetAssetsPath(assetsPath, _countof(assetsPath));
    m_assetsPath = assetsPath;
}

T100WSTRING T100DX12Scene::GetAssetFullPath(T100WSTRING assetName)
{
    return m_assetsPath + L"..\\..\\resources\\" + assetName;
}

T100VOID T100DX12Scene::CountStaticHeapSize()
{
    T100UINT        result      = 0;
    T100UINT        i           = 0;
    for(T100Entity* entity : m_static_entities)
    {
        if(entity->m_bundle.USED){
            result  += entity->m_bundle.AMOUNT.X * entity->m_bundle.AMOUNT.Y * entity->m_bundle.AMOUNT.Z;
            result++;
        }else{
            result++;
        }
        i++;
    }
    m_cbvSrvHeapLength  = result;
    m_dsvHeapLength     = i;
    m_samplerHeapLength = i;
}

T100VOID T100DX12Scene::SetOrigin(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_origin    = {x, y, z};
}

T100VOID T100DX12Scene::SetOrigin(T100Vector3 origin)
{
    m_origin    = origin;
}

T100Vector3 T100DX12Scene::GetOrigin()
{
    return m_origin;
}

T100VOID T100DX12Scene::SetTerminus(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_terminus  = {x, y, z};
}

T100VOID T100DX12Scene::SetTerminus(T100Vector3 terminus)
{
    m_terminus  = terminus;
}

T100Vector3 T100DX12Scene::GetTerminus()
{
    return m_terminus;
}

T100VOID T100DX12Scene::SetRadius(T100FLOAT radius)
{
    m_radius    = radius;
}

T100FLOAT T100DX12Scene::GetRadius()
{
    return m_radius;
}

T100VOID T100DX12Scene::SetSpatialType(T100DX12_SCENE_SPATIAL_TYPE type)
{
    m_spatialType   = type;
}

T100DX12_SCENE_SPATIAL_TYPE T100DX12Scene::GetSpatialType()
{
    return m_spatialType;
}

T100VOID T100DX12Scene::Clear()
{
    std::lock_guard<std::mutex>     lock(m_mutex);
    for(T100Entity* entity : m_dynamics_entities)
    {
        RemoveDynamicsEntityUnlock(entity);
    }

    m_dynamics_entities.clear();
}

T100DX12Camera* T100DX12Scene::GetCamera()
{
    return &m_dx12->GetCamera();
}

T100VOID T100DX12Scene::Unproject(T100Vector3 source, T100Vector3& target)
{
    XMVECTOR    value;
    XMVECTOR    result;

    T100FLOAT   x   = 0;
    T100FLOAT   y   = 0;
    T100FLOAT   width;
    T100FLOAT   height;
    T100FLOAT   minz    = 0.0f;
    T100FLOAT   maxz    = 1.0f;
    XMMATRIX    project;
    XMMATRIX    view;
    XMMATRIX    world;

    value   = XMLoadFloat3((XMFLOAT3*)&source.FLOAT3);
    width   = m_dx12->m_dx12.m_width;
    height  = m_dx12->m_dx12.m_height;

    minz    = 1.0f;
    maxz    = 1000.0f;

    project = m_dx12->GetCamera().GetProjectionMatrix();
    view    = m_dx12->GetCamera().GetViewMatrix();
    world   = XMMatrixTranslation(0, 0, 0);

    result = XMVector3Unproject(value, x, y, width, height, minz, maxz, project, view, world);

    XMStoreFloat3((XMFLOAT3*)&target.FLOAT3, result);
}

T100VOID T100DX12Scene::PlaneIntersectLine(T100Vector3 plane, T100Vector3 origin, T100Vector3 terminus, T100Vector3 point)
{
    XMVECTOR    vec1;
    XMVECTOR    vec2;
    XMVECTOR    vec3;
    XMVECTOR    result;

    vec1    = XMLoadFloat3((XMFLOAT3*)&plane.FLOAT3);
    vec2    = XMLoadFloat3(&m_dx12->GetCamera().m_position);
    vec3    = XMLoadFloat3((XMFLOAT3*)&terminus.FLOAT3);

    result  = XMPlaneIntersectLine(vec1, vec2, vec3);

    XMStoreFloat3((XMFLOAT3*)&point.FLOAT3, result);
}

T100VOID T100DX12Scene::Convert(T100UINT source, T100FLOAT& target)
{
    target = source * 2.0f / m_dx12->m_dx12.m_width;
}

T100UINT T100DX12Scene::GetWidth()
{
    return m_dx12->m_dx12.m_width;
}

T100UINT T100DX12Scene::GetHeight()
{
    return m_dx12->m_dx12.m_height;
}

T100VOID T100DX12Scene::Test(T100Vector3 source, T100Vector3 point1, T100Vector3 point2, T100Vector3 point3, T100Vector3& target)
{
    XMVECTOR    value;
    XMVECTOR    point;

    T100FLOAT   x   = 0;
    T100FLOAT   y   = 0;
    T100FLOAT   width;
    T100FLOAT   height;
    T100FLOAT   minz;
    T100FLOAT   maxz;

    XMMATRIX    project;
    XMMATRIX    view;
    XMMATRIX    world;

    value   = XMLoadFloat3((XMFLOAT3*)&source.FLOAT3);

    width   = GetWidth();
    height  = GetHeight();
    minz    = 1.0f;
    maxz    = 1000.0f;

    project = m_dx12->GetCamera().GetProjectionMatrix();
    view    = m_dx12->GetCamera().GetViewMatrix();
    world   = XMMatrixTranslation(0, 0, 0);

    point   = XMVector3Unproject(value, x, y, width, height, minz, maxz, project, view, world);

    XMStoreFloat3((XMFLOAT3*)&target.FLOAT3, point);
}

T100VOID T100DX12Scene::ScreenToVector(T100UINT screenX, T100UINT screenY, T100FLOAT radius, T100Vector3& result)
{
    T100FLOAT   m_fRadius   = radius;
    T100FLOAT   m_OffsetX   = 0;
    T100FLOAT   m_OffsetY   = 0;

    T100FLOAT x = -( screenX - m_OffsetX - GetWidth() / 2 ) / ( m_fRadius * GetWidth() / 2 );
    T100FLOAT y = ( screenY - m_OffsetY - GetHeight() / 2 ) / ( m_fRadius * GetHeight() / 2 );

    T100FLOAT z = 0.0f;
    T100FLOAT mag = x * x + y * y;

    if( mag > 1.0f )
    {
        T100FLOAT scale = 1.0f / sqrtf( mag );
        x *= scale;
        y *= scale;
    }
    else
        z = sqrtf( 1.0f - mag );

    result = {x, y, z};
}

/*
    // Scale to screen
    FLOAT x = -( fScreenPtX - m_Offset.x - m_nWidth / 2 ) / ( m_fRadius * m_nWidth / 2 );
    FLOAT y = ( fScreenPtY - m_Offset.y - m_nHeight / 2 ) / ( m_fRadius * m_nHeight / 2 );

    FLOAT z = 0.0f;
    FLOAT mag = x * x + y * y;

    if( mag > 1.0f )
    {
        FLOAT scale = 1.0f / sqrtf( mag );
        x *= scale;
        y *= scale;
    }
    else
        z = sqrtf( 1.0f - mag );

    // Return vector
    return D3DXVECTOR3( x, y, z );
*/

T100VOID T100DX12Scene::ScreenToWorld(T100UINT x, T100UINT y, T100FLOAT z, T100Vector3& result)
{
    T100Vector3     source;
    T100Vector3     value;

    T100FLOAT   w   = (x - GetWidth() / 2.0f) / (GetWidth() / 2.0f);
    T100FLOAT   h   = (GetHeight() / 2.0f - y) / (GetHeight() / 2.0f);

    source  = {x, y, 0};

    Unproject(source, value);

    /*
    T100FLOAT       n;

    n   = z - value.Z;

    result.X    = value.X * n;
    result.Y    = value.Y * n;
    result.Z    = z;
    */

    result.X    = value.X;
    result.Y    = value.Y;
    result.Z    = value.Z;
}

T100VOID T100DX12Scene::ConvertToWorld(T100UINT x, T100UINT y, T100FLOAT z, T100Vector3& result)
{
    T100Vector3     source;
    T100Vector3     value;

    ScreenToWorld(x, y, z, source);

    GetWorld(source, z, value);

    result.X    = value.X;
    result.Y    = value.Y;
    result.Z    = value.Z;
}

T100VOID T100DX12Scene::GetWorld(T100Vector3 source, T100FLOAT z, T100Vector3& result)
{
    T100Vector3     target;

    target      = GetCamera()->GetPosition();

    result.X    = (target.X - source.X) * (z - source.Z) / (target.Z - source.Z) + source.X;
    result.Y    = (target.Y - source.Y) * (z - source.Z) / (target.Z - source.Z) + source.Y;
    result.Z    = z;
}

T100VOID T100DX12Scene::Reset()
{
    //m_dx12->GetCamera().Reset();
    Clear();
}

T100VOID T100DX12Scene::SetBundle(T100Entity* entity)
{
    Remove(entity);
    Append(entity);
}
