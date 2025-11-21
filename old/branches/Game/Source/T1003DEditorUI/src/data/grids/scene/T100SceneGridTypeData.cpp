#include "T100SceneGridTypeData.h"

#include "data/T100Scene.h"
#include "T100SceneGridSphereRadiusData.h"
#include "T100SceneGridRectangleXData.h"
#include "T100SceneGridRectangleYData.h"
#include "T100SceneGridRectangleZData.h"

T100SceneGridTypeData::T100SceneGridTypeData(wxPropertyGrid* grid, T100Scene* scene, T1003DEditorSceneGridData& data) :
    T100GridClientData(grid),
    m_scenePtr(scene),
    m_sceneData(data)
{
    //ctor
}

T100SceneGridTypeData::~T100SceneGridTypeData()
{
    //dtor
}

T100VOID T100SceneGridTypeData::Update(wxPGProperty* property)
{
    T100UINT    value       = property->GetValue().GetInteger();

    m_scenePtr->Type        = ConvertType(value);

    RemoveItems();
    CreateItems();
}

T100VOID T100SceneGridTypeData::RemoveItems()
{
    for(wxPGProperty* item : m_sceneData.m_typeProperties){
        m_gridPtr->DeleteProperty(item);
    }
    m_sceneData.m_typeProperties.clear();
}

T100VOID T100SceneGridTypeData::CreateItems()
{
    switch(m_scenePtr->Type){
    case T100DX12_SCENE_RECTANGLE:
        {
            m_sceneData.m_typeCategory->SetLabel(wxT("Rectangle"));

            wxFloatProperty*        rectangleX  = T100NEW wxFloatProperty(wxT("X"), wxT("rectanglex"), m_scenePtr->Width);
            wxFloatProperty*        rectangleY  = T100NEW wxFloatProperty(wxT("Y"), wxT("rectangley"), m_scenePtr->Height);
            wxFloatProperty*        rectangleZ  = T100NEW wxFloatProperty(wxT("Z"), wxT("rectanglez"), m_scenePtr->Length);

            m_sceneData.m_typeCategory->AppendChild(rectangleX);
            m_sceneData.m_typeCategory->AppendChild(rectangleY);
            m_sceneData.m_typeCategory->AppendChild(rectangleZ);

            T100SceneGridRectangleXData*        dataX       = T100NEW T100SceneGridRectangleXData(m_gridPtr, m_scenePtr, m_sceneData);
            rectangleX->SetClientObject(dataX);
            T100SceneGridRectangleYData*        dataY       = T100NEW T100SceneGridRectangleYData(m_gridPtr, m_scenePtr, m_sceneData);
            rectangleY->SetClientObject(dataY);
            T100SceneGridRectangleZData*        dataZ       = T100NEW T100SceneGridRectangleZData(m_gridPtr, m_scenePtr, m_sceneData);
            rectangleZ->SetClientObject(dataZ);

            m_sceneData.m_typeProperties.push_back(rectangleX);
            m_sceneData.m_typeProperties.push_back(rectangleY);
            m_sceneData.m_typeProperties.push_back(rectangleZ);

        }
        break;
    case T100DX12_SCENE_SPHERE:
        {
            m_sceneData.m_typeCategory->SetLabel(wxT("Sphere"));

            wxFloatProperty*        sphereRadius    = T100NEW wxFloatProperty(wxT("Radius"), wxT("radius"), m_scenePtr->Radius);
            T100SceneGridSphereRadiusData*      data    = T100NEW T100SceneGridSphereRadiusData(m_gridPtr, m_scenePtr, m_sceneData);
            sphereRadius->SetClientObject(data);
            m_sceneData.m_typeCategory->AppendChild(sphereRadius);

            m_sceneData.m_typeProperties.push_back(sphereRadius);

        }
        break;
    }
}

T100DX12_SCENE_SPATIAL_TYPE T100SceneGridTypeData::ConvertType(T100UINT value)
{
    switch(value){
    case 0:
        {
            return T100DX12_SCENE_RECTANGLE;
        }
        break;
    case 1:
        {
            return T100DX12_SCENE_SPHERE;
        }
        break;
    }
    return T100DX12_SCENE_RECTANGLE;
}
