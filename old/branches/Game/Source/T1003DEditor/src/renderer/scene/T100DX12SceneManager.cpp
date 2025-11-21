#include "T100DX12SceneManager.h"

#include "T100DX12Studio.h"

T100DX12SceneManager::T100DX12SceneManager(T100DX12Studio* studio) :
    m_studio(studio)
{
    //ctor
}

T100DX12SceneManager::~T100DX12SceneManager()
{
    //dtor
}

T100VOID T100DX12SceneManager::SetScene(T100DX12Scene* scene)
{
    m_scene     = scene;
}

T100DX12Scene* T100DX12SceneManager::GetScene()
{
    return m_scene;
}

T100VOID T100DX12SceneManager::Start()
{
    SceneManagerStart();
}

T100VOID T100DX12SceneManager::Stop()
{
    SceneManagerStop();
}

T100VOID T100DX12SceneManager::Load()
{
    SceneManagerLoad();
}

T100VOID T100DX12SceneManager::Update()
{
    SceneManagerUpdate();
}

T100VOID T100DX12SceneManager::AppendStaticEntities(T100ENTITY_VECTOR& entities)
{
    for(T100Entity* entity : entities)
    {
        T100DX12Model*      model       = entity->Convert(m_studio);

        m_studio->m_model_manager.Append(model);
    }
}

T100VOID T100DX12SceneManager::AppendDynamicsEntities(T100ENTITY_VECTOR& entities)
{
    for(T100Entity* entity : entities)
    {
        T100DX12Model*      model       = entity->Convert(m_studio);

        m_studio->m_model_manager.Append(model);
        m_scene->m_dynamics_entities.push_back(entity);
    }

    entities.clear();
}

T100VOID T100DX12SceneManager::SceneManagerStart()
{
    m_scene->AppendStaticEntities();
    m_scene->AppendDynamicsEntities();
}

T100VOID T100DX12SceneManager::SceneManagerStop()
{

}

T100VOID T100DX12SceneManager::SceneManagerLoad()
{
    m_scene->LoadStaticEntities();
    m_scene->LoadDynamicsEntities();
    std::lock_guard<std::mutex>     lock(m_scene->m_mutex);
    AppendStaticEntities(m_scene->m_static_entities);
}

T100VOID T100DX12SceneManager::SceneManagerUpdate()
{
    std::lock_guard<std::mutex>     lock(m_scene->m_mutex);
    //AppendDynamicsEntities(m_scene->m_dynamics_entities);
    AppendDynamicsEntities(m_scene->m_pending_entities);
}
