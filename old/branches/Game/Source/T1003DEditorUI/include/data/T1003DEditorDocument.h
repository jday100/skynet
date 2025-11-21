#ifndef T1003DEDITORDOCUMENT_H
#define T1003DEDITORDOCUMENT_H

#include "T100Common.h"
#include "data/T100Scene.h"
#include "game/file/T100File3DF.h"
#include "game/file/T100FileGLTF.h"
#include "game/file/T100FileH3D.h"

class T1003DEditorDocument
{
    friend class T1003DEditorStore;
    friend class T1003DEditorSkeletal;
    public:
        T1003DEditorDocument();
        virtual ~T1003DEditorDocument();

        T100VOID                    Append(T100Entity*);
        T100VOID                    Remove(T100Entity*);

        T100VOID                    Append(T100Camera*);
        T100VOID                    Remove(T100Camera*);

        T100VOID                    AppendLight(T100Light*);
        T100VOID                    RemoveLight(T100Light*);

        T100VOID                    Append(T100Texture*);
        T100VOID                    Remove(T100Texture*);

        T100VOID                    Append(T100Material*);
        T100VOID                    Remove(T100Material*);

        T100Scene&                  GetScene();

        T100ENTITY_VECTOR&          GetEntities();
        T100ENTITY_VECTOR&          GetMeshes();
        T100CAMERA_VECTOR&          GetCameras();
        T100LIGHT_VECTOR&           GetLights();
        T100TEXTURE_VECTOR&         GetTextures();
        T100MATERIAL_VECTOR&        GetMaterials();


        T100VOID                    Decode(T100File3DF&);
        T100VOID                    Encode(T100File3DF&);

        T100VOID                    Decode(T100FileGLTF&);
        T100VOID                    Encode(T100FileGLTF&);

        T100VOID                    Decode(T100FileH3D&);
        T100VOID                    Encode(T100FileH3D&);

    protected:
        T100WSTRING                 m_filename;

        T100Scene                   m_scene;

        T100ENTITY_VECTOR           m_entities;
        T100ENTITY_VECTOR           m_meshes;
        T100CAMERA_VECTOR           m_cameras;
        T100LIGHT_VECTOR            m_lights;
        T100TEXTURE_VECTOR          m_textures;
        T100MATERIAL_VECTOR         m_materials;

    private:
        T100VOID                    DecodeEntity(JSON&);

        T100VOID                    DecodeDot(JSON&);
        T100VOID                    DecodeLine(JSON&);
        T100VOID                    DecodeCity(JSON&);
        T100VOID                    DecodeTriangle(JSON&);

        T100VOID                    DecodeLight(JSON&);
        T100VOID                    DecodeMaterial(JSON&);
};

#endif // T1003DEDITORDOCUMENT_H
