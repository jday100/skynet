#ifndef T100GAMESCENE_H
#define T100GAMESCENE_H

#include <mutex>
#include <condition_variable>
#include "link/T1003DRenderer.h"

class T100Game;

class T100GameScene
{
    friend class T100Game;
    public:
        T100GameScene(T100Game*, T1003D_SCENE_SPATIAL_TYPE = T1003D_SCENE_RECTANGLE);
        virtual ~T100GameScene();

        virtual T100VOID                    Create() = 0;
        virtual T100VOID                    Destroy() = 0;

        virtual T100VOID                    Append(T1003DMesh*);
        virtual T100VOID                    Remove(T1003DMesh*);

        virtual T100VOID                    AppendStaticMesh(T1003DMesh*);
        virtual T100VOID                    ClearStaticMeshes();

        virtual T100VOID                    SetBundle(T1003DMesh*);

        T100VOID                            SetSpace(T100FLOAT, T100FLOAT, T100FLOAT);

    protected:
        virtual T100VOID                    AppendStaticMeshes()        = 0;
        virtual T100VOID                    AppendDynamicsMeshes()      = 0;

        virtual T100VOID                    PreloadDynamicsMesh(T1003DMesh*);
        virtual T100VOID                    AppendDynamicsMesh(T1003DMesh*);
        virtual T100VOID                    RemoveDynamicsMesh(T1003DMesh*);

        virtual T100VOID                    LoadStaticMeshes(T1003DRenderer*);
        virtual T100VOID                    LoadDynamicsMeshes(T1003DRenderer*);

        T100WSTRING                         GetAssetFullPath(T100WSTRING);

        T100VOID                            Unproject(T100Vector3f, T100Vector3f&);
        T100VOID                            ScreenToWorld(T100UINT, T100UINT, T100FLOAT, T100Vector3f&);
        T100VOID                            ConvertToWorld(T100UINT, T100UINT, T100FLOAT, T100Vector3f&);
        T100VOID                            GetWorld(T100Vector3f, T100FLOAT, T100Vector3f&);

        T100VOID                            UnprojectCommon(T100Vector3f, T100Vector3f&);

        T100VOID                            SetLineLength(T1003DMesh*);
        T100FLOAT                           GetSceneLength();



        /*
        virtual T100VOID                    CountStaticHeapSize();

    private:
        virtual T100VOID                    RemoveDynamicsMeshUnlock(T1003DMesh*);
        */

    protected:
        T1003D_SCENE_SPATIAL_TYPE           m_type;
        T100Game*                           m_gamePtr               = T100NULL;
        T1003DRenderer*                     m_rendererPtr           = T100NULL;
        T1003DMESH_VECTOR                   m_staticMeshes;
        T1003DMESH_VECTOR                   m_dynamicsMeshes;

        T100FLOAT                           m_width                 = 0;
        T100FLOAT                           m_height                = 0;
        T100FLOAT                           m_length                = 0;

    private:
        std::mutex                          m_mutex;
        std::condition_variable             m_condition;

        T100WSTRING                         m_assetsPath;

        T100VOID                            InitAssetsPath();

        T100VOID                            ConvertPath(T1003DMesh*);

        T100VOID                            init();
        T100VOID                            uninit();
};

#endif // T100GAMESCENE_H
