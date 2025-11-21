#ifndef T100DX12SCENE_H
#define T100DX12SCENE_H

#include <mutex>
#include <condition_variable>
#include "dx12/T100DX12Header.h"
#include "common/T100DX12Common.h"
#include "entity/T100Entity.h"
#include "data/T100Light.h"

class T100DX12Camera;
class T100DX12Renderer;
class T100DX12SceneManager;

class T100DX12Scene
{
    friend class T100DX12Line;
    friend class T100DX12Discrete;
    friend class T1003DEditor;
    friend class T100DX12Triangle;
    friend class T100Triangle;
    friend class T100DX12Context;
    friend class T100DX12Dynamic2;

    friend class T100DX12Studio;
    friend class T100DX12Bundle;
    friend class T100DX12SceneManager;
    friend class T100DX12ModelManager;
    friend class T100DX12FrameManager;
    public:
        T100DX12Scene(T100DX12Renderer*);
        virtual ~T100DX12Scene();

        T100VertexDescriptions              VertexDescriptions;
        T100ShaderParameters                ShaderParameters;

        T100SHADER_FILE                     VertexShaderFile;
        T100SHADER_FILE                     PixelShaderFile;


        T100DX12Renderer*                   GetRenderer();
        T100DX12SceneManager*               GetSceneManager();

        virtual T100VOID                    Append(T100Entity*);
        virtual T100VOID                    Remove(T100Entity*);

        virtual T100VOID                    AppendLight(T100Light*);
        virtual T100VOID                    RemoveLight(T100Light*);

        T100VOID                            SetBundle(T100Entity*);

        T100UINT                            GetWidth();
        T100UINT                            GetHeight();

        T100VOID                            Convert(T100UINT, T100FLOAT&);
        T100VOID                            Unproject(T100Vector3, T100Vector3&);
        T100VOID                            PlaneIntersectLine(T100Vector3, T100Vector3, T100Vector3, T100Vector3);

        T100VOID                            Test(T100Vector3, T100Vector3, T100Vector3, T100Vector3, T100Vector3&);
        T100VOID                            ScreenToVector(T100UINT, T100UINT, T100FLOAT, T100Vector3&);
        T100VOID                            ScreenToWorld(T100UINT, T100UINT, T100FLOAT, T100Vector3&);
        T100VOID                            ConvertToWorld(T100UINT, T100UINT, T100FLOAT, T100Vector3&);
        T100VOID                            GetWorld(T100Vector3, T100FLOAT, T100Vector3&);

        T100VOID                            Clear();

        T100DX12Camera*                     GetCamera();
        T100VOID                            Reset();

    public:
        T100VOID                            SetOrigin(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                            SetOrigin(T100Vector3);
        T100Vector3                         GetOrigin();

        T100VOID                            SetTerminus(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                            SetTerminus(T100Vector3);
        T100Vector3                         GetTerminus();

        T100VOID                            SetRadius(T100FLOAT);
        T100FLOAT                           GetRadius();

        T100VOID                            SetSpatialType(T100DX12_SCENE_SPATIAL_TYPE);
        T100DX12_SCENE_SPATIAL_TYPE         GetSpatialType();

        T100VOID                            LoadShaderFile(T100WSTRING, UINT8**, UINT*);
        T100VOID                            LoadMeshFile(T100WSTRING, UINT8**, UINT*);

        T100VOID                            CompileShaderFile(T100WSTRING, T100STRING, T100STRING, ComPtr<ID3DBlob>&);
        T100VOID                            CompileShaderFile(T100WSTRING, T100WSTRING, T100WSTRING, ComPtr<ID3DBlob>&);
        T100VOID                            CompileShaderFile1(T100WSTRING, T100WSTRING, T100WSTRING, ComPtr<ID3DBlob>&);

    protected:
        T100DX12Renderer*                   m_dx12          = T100NULL;
        T100ENTITY_VECTOR                   m_static_entities;
        T100ENTITY_VECTOR                   m_dynamics_entities;
        T100ENTITY_VECTOR                   m_pending_entities;

    protected:
        virtual T100VOID                    AppendStaticEntities()        = 0;
        virtual T100VOID                    AppendDynamicsEntities()      = 0;

        virtual T100VOID                    LoadStaticEntities();
        virtual T100VOID                    LoadDynamicsEntities();

        virtual T100VOID                    AppendStaticEntity(T100Entity*);
        virtual T100VOID                    ClearStaticEntities();

        virtual T100VOID                    AppendDynamicsEntity(T100Entity*);
        virtual T100VOID                    RemoveDynamicsEntity(T100Entity*);
        virtual T100VOID                    RemoveDynamicsEntityUnlock(T100Entity*);

        virtual T100VOID                    CountStaticHeapSize();

        T100VOID                            InitAssetsPath();
        T100WSTRING                         GetAssetFullPath(T100WSTRING);

    private:
        T100UINT                            m_cbvSrvHeapLength          = 0;
        T100UINT                            m_dsvHeapLength             = 0;
        T100UINT                            m_samplerHeapLength         = 0;
        T100WSTRING                         m_assetsPath;

        T100Vector3                         m_origin;
        T100Vector3                         m_terminus;
        T100FLOAT                           m_radius;

        T100DX12_SCENE_SPATIAL_TYPE         m_spatialType;

        std::mutex                          m_mutex;
        std::condition_variable             m_condition;

        T100VOID                            init();
        T100VOID                            uninit();
};

#endif // T100DX12SCENE_H
