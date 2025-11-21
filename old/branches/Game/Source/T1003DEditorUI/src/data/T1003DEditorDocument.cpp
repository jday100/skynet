#include "T1003DEditorDocument.h"

#include <sstream>
#include "entity/T100AllEntities.h"

T1003DEditorDocument::T1003DEditorDocument() :
    m_scene()
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

T100VOID T1003DEditorDocument::Append(T100Camera* camera)
{
    m_cameras.push_back(camera);
}

T100VOID T1003DEditorDocument::Remove(T100Camera* camera)
{

}

T100VOID T1003DEditorDocument::AppendLight(T100Light* light)
{
    m_lights.push_back(light);
}

T100VOID T1003DEditorDocument::RemoveLight(T100Light* light)
{

}

T100VOID T1003DEditorDocument::Append(T100Texture* texture)
{
    m_textures.push_back(texture);
}

T100VOID T1003DEditorDocument::Remove(T100Texture* texture)
{

}

T100VOID T1003DEditorDocument::Append(T100Material* material)
{
    m_materials.push_back(material);
}

T100VOID T1003DEditorDocument::Remove(T100Material* material)
{

}

T100Scene& T1003DEditorDocument::GetScene()
{
    return m_scene;
}

T100ENTITY_VECTOR& T1003DEditorDocument::GetMeshes()
{
    return m_meshes;
}

T100ENTITY_VECTOR& T1003DEditorDocument::GetEntities()
{
    return m_entities;
}

T100CAMERA_VECTOR& T1003DEditorDocument::GetCameras()
{
    return m_cameras;
}

T100LIGHT_VECTOR& T1003DEditorDocument::GetLights()
{
    return m_lights;
}

T100MATERIAL_VECTOR& T1003DEditorDocument::GetMaterials()
{
    return m_materials;
}

T100VOID T1003DEditorDocument::Decode(T100File3DF& file)
{
    JSON&       json    = file.GetJSON().GetJSON();

    JSON&       entities    = json["entities"];

    for(JSON::iterator it = entities.begin(); it != entities.end(); ++it)
    {
        JSON&   thisEntity  = it.value();

        DecodeEntity(thisEntity);
    }


    JSON&       lights    = json["lights"];

    for(JSON::iterator it = lights.begin(); it != lights.end(); ++it)
    {
        JSON&   thisEntity  = it.value();

        DecodeLight(thisEntity);
    }

    JSON&       materials    = json["materials"];

    for(JSON::iterator it = materials.begin(); it != materials.end(); ++it)
    {
        JSON&   thisEntity  = it.value();

        DecodeMaterial(thisEntity);
    }
}

T100VOID T1003DEditorDocument::Encode(T100File3DF& file)
{
    JSON&       json    = file.GetJSON().GetJSON();

    JSON        scene;

    m_scene.ToJSON(scene);

    json["scene"]   = scene;

    JSON        entities;

    for(T100Entity* entity : m_entities)
    {
        JSON    thisEntity;

        entity->ToJSON(thisEntity);

        entities.push_back(thisEntity);
    }

    json["entities"]    = entities;

    JSON        lights;

    for(T100Entity* light : m_lights)
    {
        JSON    thisEntity;

        light->ToJSON(thisEntity);

        lights.push_back(thisEntity);
    }

    json["lights"]    = lights;

    JSON        materials;

    for(T100Material* material : m_materials)
    {
        JSON    thisEntity;

        material->ToJSON(thisEntity);

        materials.push_back(thisEntity);
    }

    json["materials"]    = materials;
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

T100VOID T1003DEditorDocument::DecodeLight(JSON& json)
{
    T100Light*   light    = T100NEW T100Light();

    light->FromJSON(json);

    m_lights.push_back(light);
}

T100VOID T1003DEditorDocument::DecodeMaterial(JSON& json)
{
    T100Material*   material    = T100NEW T100Material();

    material->FromJSON(json);

    m_materials.push_back(material);
}

T100VOID T1003DEditorDocument::Decode(T100FileGLTF& gltf)
{
    for(auto& camera : gltf.m_cameras){
        T100Camera*     item    = T100NEW T100Camera();

        m_cameras.push_back(item);
    }

    for(GLTF::GLTFMesh& mesh : gltf.m_meshes){
        T100Mesh*       item   = T100NEW T100Mesh();

        m_entities.push_back(item);
    }
}

T100VOID T1003DEditorDocument::Encode(T100FileGLTF& gltf)
{

}

T100VOID T1003DEditorDocument::Decode(T100FileH3D& h3d)
{
    T100UINT    index   = 0;
    T100BYTE*   vertexPtr   = T100NULL;
    T100BYTE*   indexPtr    = T100NULL;

    vertexPtr   = h3d.m_vertexDataPtr;
    indexPtr    = h3d.m_indexDataPtr;

    for(T100H3D::T100H3D_MESH& mesh : h3d.m_meshes){
        T100Mesh*       item    = T100NEW T100Mesh();
        T100Entity*     entity;

        std::wstringstream      wss;

        wss << T100Mesh::Name;
        wss << index++;

        entity  = item;
        entity->Name    = wss.str();

        item->VertexDataPtr     = vertexPtr + mesh.VertexDataByteOffset;
        item->IndexDataPtr      = indexPtr + mesh.IndexDataByteOffset;

        item->VertexDataLength  = mesh.VertexCount;
        item->IndexDataLength   = mesh.IndexCount;

        m_meshes.push_back(item);
    }
}

T100VOID T1003DEditorDocument::Encode(T100FileH3D& h3d)
{

}
