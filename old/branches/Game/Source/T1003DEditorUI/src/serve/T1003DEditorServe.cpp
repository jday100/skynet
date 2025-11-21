#include "T1003DEditorServe.h"

#include "T1003DEditorCallback.h"

T1003DEditorServe::T1003DEditorServe() :
    m_entityManager(),
    m_lightManager(this),
    m_settingsServe()
{
    //ctor
}

T1003DEditorServe::~T1003DEditorServe()
{
    //dtor
}

T100VOID T1003DEditorServe::Update(T100Entity* entity)
{
    if(entity->Shader.INHERIT){
        UpdateEntity(m_document->GetScene(), entity);
    }
}

T100BOOL T1003DEditorServe::Open(T1003DEditorDocument* document)
{
    m_document  = document;

    for(T100Entity* entity : document->GetEntities()){
        T1003DEditorCallback::Append(entity);
    }

    for(T100Entity* entity : document->GetMeshes()){
        T1003DEditorCallback::Append(entity);
    }

    for(T100Camera* camera : document->GetCameras()){
        T1003DEditorCallback::Append(camera);
    }

    return T100TRUE;
}

T1003DEditorDocument* T1003DEditorServe::GetDocument()
{
    return m_document;
}

T1003DEditorEntityManager* T1003DEditorServe::GetEntityManager()
{
    return &m_entityManager;
}

T1003DEditorCameraManager* T1003DEditorServe::GetCameraManager()
{
    return &m_cameraManager;
}

T1003DEditorLightManager* T1003DEditorServe::GetLightManager()
{
    return &m_lightManager;
}

T1003DEditorMaterialManager* T1003DEditorServe::GetMaterialManager()
{
    return &m_materialManager;
}

T1003DEditorSettingsServe& T1003DEditorServe::GetSettingsServe()
{
    return m_settingsServe;
}

T100BOOL T1003DEditorServe::Append(T100Entity* entity)
{
    m_document->Append(entity);
    return T100TRUE;
}

T100BOOL T1003DEditorServe::Remove(T100Entity* entity)
{
    //m_entityManager.Clear();
}

T100BOOL T1003DEditorServe::Append(T100Camera* camera)
{
    m_document->Append(camera);
    return T100TRUE;
}

T100BOOL T1003DEditorServe::Remove(T100Camera* camera)
{
    m_document->Remove(camera);
    return T100TRUE;
}

T100BOOL T1003DEditorServe::AppendLight(T100Light* light)
{
    m_document->AppendLight(light);
    return T100TRUE;
}

T100BOOL T1003DEditorServe::RemoveLight(T100Light* light)
{
    m_document->RemoveLight(light);
    return T100TRUE;
}

T100BOOL T1003DEditorServe::Append(T100Material* material)
{
    m_document->Append(material);
    return T100TRUE;
}

T100BOOL T1003DEditorServe::Remove(T100Material* material)
{
    m_document->Remove(material);
    return T100TRUE;
}

T100VOID T1003DEditorServe::UpdateEntity(T100Scene& scene, T100Entity* entityPtr)
{
    entityPtr->VertexShaderFile.TYPE    = scene.VertexShaderFile.TYPE;
    entityPtr->VertexShaderFile.FILE    = scene.VertexShaderFile.FILE;
    entityPtr->VertexShaderFile.ENTRY   = scene.VertexShaderFile.ENTRY;
    entityPtr->VertexShaderFile.TARGET  = scene.VertexShaderFile.TARGET;

    entityPtr->PixelShaderFile.TYPE     = scene.PixelShaderFile.TYPE;
    entityPtr->PixelShaderFile.FILE     = scene.PixelShaderFile.FILE;
    entityPtr->PixelShaderFile.ENTRY    = scene.PixelShaderFile.ENTRY;
    entityPtr->PixelShaderFile.TARGET   = scene.PixelShaderFile.TARGET;

    entityPtr->VertexDescriptions       = scene.VertexDescriptions;
    entityPtr->ShaderParameters         = scene.ShaderParameters;
}
