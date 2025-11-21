#include "serve/T1003DEditorServe.h"

#include "skeletal/T1003DEditorCallback.h"

T1003DEditorServe::T1003DEditorServe() :
    m_entityManager()
{
    //ctor
}

T1003DEditorServe::~T1003DEditorServe()
{
    //dtor
}

T100BOOL T1003DEditorServe::Open(T1003DEditorDocument* document)
{
    m_document  = document;

    /*
    for(T100Entity* entity : document->GetEntities()){
        T1003DEditorCallback::Append(entity);
    }

    for(T100Camera* camera : document->GetCameras()){
        T1003DEditorCallback::Append(camera);
    }
    */

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

T100BOOL T1003DEditorServe::Append(T100Entity* entity)
{
    m_document->Append(entity);
    return T100TRUE;
}

T100BOOL T1003DEditorServe::Remove(T100Entity* entity)
{
    m_entityManager.Clear();
}

T100BOOL T1003DEditorServe::Append(T1003DCamera* camera)
{
    m_document->Append(camera);
    return T100TRUE;
}

T100BOOL T1003DEditorServe::Remove(T1003DCamera* camera)
{
    m_document->Remove(camera);
    return T100TRUE;
}

T100BOOL T1003DEditorServe::Append(T1003DLight* light)
{
    m_document->Append(light);
    return T100TRUE;
}

T100BOOL T1003DEditorServe::Remove(T1003DLight* light)
{
    m_document->Remove(light);
    return T100TRUE;
}
