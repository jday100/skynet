#ifndef T100DX12MESHMANAGER_H
#define T100DX12MESHMANAGER_H

#include <mutex>
#include <condition_variable>
#include "data/T100DX12Mesh.h"
#include "mesh/T100DX12MeshManagerBase.h"

class T100DX12Studio;

class T100DX12MeshManager : public T100DX12MeshManagerBase
{
    public:
        T100DX12MeshManager(T100DX12Studio*);
        virtual ~T100DX12MeshManager();

        virtual T100VOID            Start();
        virtual T100VOID            Stop();

        virtual T100VOID            Update();

        virtual T100VOID            Append(T1003DMesh*);
        virtual T100VOID            Remove(T1003DMesh*);

        virtual T100VOID            SetBundle(T1003DMesh*);

    protected:
        T100DX12Studio*             m_studioPtr         = T100NULL;
        T100DX12_MESH_VECTOR        m_meshes;

        T100DX12_MESH_VECTOR        m_appendMeshes;
        T100DX12_MESH_VECTOR        m_removeMeshes;

        T100VOID                    LoadMesh(T100DX12Mesh*);
        T100VOID                    UploadMeshes();

        T100DX12Mesh*               ConvertCity(T1003DMesh*);

        T100VOID                    UploadMesh(T100DX12Studio*, T100DX12Mesh*);
        T100VOID                    UploadCity(T100DX12Studio*, T100DX12Mesh*);

    private:
        std::mutex                          m_mutex;
        std::condition_variable             m_condition;
};

#endif // T100DX12MESHMANAGER_H
