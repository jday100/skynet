#include "data/T1003DEditorDocument.h"

#include "entity/T100AllEntities.h"

T1003DEditorDocument::T1003DEditorDocument()
{
    //ctor
}

T1003DEditorDocument::~T1003DEditorDocument()
{
    //dtor
}

T100VOID T1003DEditorDocument::Append(T100Entity* entity)
{
    m_entities.push_back(entity);
}

T100VOID T1003DEditorDocument::Remove(T100Entity* entity)
{

}

T100VOID T1003DEditorDocument::Append(T1003DCamera* camera)
{
    m_cameras.push_back(camera);
}

T100VOID T1003DEditorDocument::Remove(T1003DCamera* camera)
{

}

T100VOID T1003DEditorDocument::Append(T1003DLight* light)
{
    m_lights.push_back(light);
}

T100VOID T1003DEditorDocument::Remove(T1003DLight* light)
{

}

T100ENTITY_VECTOR& T1003DEditorDocument::GetEntities()
{
    return m_entities;
}

T1003DCAMERA_VECTOR& T1003DEditorDocument::GetCameras()
{
    return m_cameras;
}

T1003DLIGHT_VECTOR& T1003DEditorDocument::GetLights()
{
    return m_lights;
}

T100VOID T1003DEditorDocument::Decode(T1003DFile3DF& file)
{
    JSON&       json    = file.GetJSON();

    JSON&       entities    = json["entities"];

    for(JSON::iterator it = entities.begin(); it != entities.end(); ++it)
    {
        JSON&   thisEntity  = it.value();

        DecodeEntity(thisEntity);
    }

}

T100VOID T1003DEditorDocument::Encode(T1003DFile3DF& file)
{
    JSON&       json    = file.GetJSON();

    JSON        entities;

    for(T100Entity* entity : m_entities)
    {
        JSON    thisEntity;

        entity->ToJSON(thisEntity);

        entities.push_back(thisEntity);
    }

    json["entities"]    = entities;
}

T100VOID T1003DEditorDocument::DecodeEntity(JSON& json)
{
    T100UINT    type    = json["type"];

    switch(type){
    case 1:
        {
            DecodeDot(json);
        }
        break;
    case 2:
        {
            DecodeLine(json);
        }
        break;
    case 3:
        {
            DecodeTriangle(json);
        }
        break;
    case 4:
        {
            DecodeCity(json);
        }
        break;
    }
}

T100VOID T1003DEditorDocument::DecodeDot(JSON& json)
{
    T100Dot*    dot     = T100NEW T100Dot();

    dot->FromJSON(json);

    m_entities.push_back(dot);
}

T100VOID T1003DEditorDocument::DecodeLine(JSON& json)
{
    T100Line*   line    = T100NEW T100Line();

    line->FromJSON(json);

    m_entities.push_back(line);
}

T100VOID T1003DEditorDocument::DecodeCity(JSON& json)
{
    T100City*   city    = T100NEW T100City();

    city->FromJSON(json);

    m_entities.push_back(city);
}

T100VOID T1003DEditorDocument::DecodeTriangle(JSON& json)
{
    T100Triangle*   triangle    = T100NEW T100Triangle();

    triangle->FromJSON(json);

    m_entities.push_back(triangle);
}

T100VOID T1003DEditorDocument::Decode(T1003DFileGLTF& gltf)
{
    /*
    for(auto& camera : gltf.m_cameras){
        T1003DCamera*   item    = T100NEW T1003DCamera();

        m_cameras.push_back(item);
    }

    for(GLTF::GLTFMesh& mesh : gltf.m_meshes){
        T100Mesh*       item   = T100NEW T100Mesh();

        m_entities.push_back(item);
    }
    */
}

T100VOID T1003DEditorDocument::Encode(T1003DFileGLTF& gltf)
{

}
