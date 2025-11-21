#ifndef T100DX12SCENEMANAGER_H
#define T100DX12SCENEMANAGER_H

#include "renderer/data/T100DX12Scene.h"

class T100DX12Studio;

class T100DX12SceneManager
{
    friend class T100Line;
    public:
        T100DX12SceneManager(T100DX12Studio*);
        virtual ~T100DX12SceneManager();

        virtual T100VOID            SetScene(T100DX12Scene*);
        virtual T100DX12Scene*      GetScene();

        virtual T100VOID            Start();
        virtual T100VOID            Stop();

        virtual T100VOID            Load();
        virtual T100VOID            Update();

    protected:
        T100DX12Studio*             m_studio            = T100NULL;
        T100DX12Scene*              m_scene             = T100NULL;

    protected:
        T100VOID                    SceneManagerStart();
        T100VOID                    SceneManagerStop();
        T100VOID                    SceneManagerLoad();
        T100VOID                    SceneManagerUpdate();

        T100VOID                    AppendStaticEntities(T100ENTITY_VECTOR&);
        T100VOID                    AppendDynamicsEntities(T100ENTITY_VECTOR&);

    private:
};

#endif // T100DX12SCENEMANAGER_H
