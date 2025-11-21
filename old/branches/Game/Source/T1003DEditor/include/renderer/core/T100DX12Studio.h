#ifndef T100DX12STUDIO_H
#define T100DX12STUDIO_H

#include "renderer/core/T100DX12Area.h"
#include "renderer/frame/T100DX12FrameManager.h"
#include "renderer/model/T100DX12ModelManager.h"
#include "renderer/scene/T100DX12SceneManager.h"
#include "renderer/light/T100DX12LightManager.h"
#include "renderer/context/T100DX12ContextManager.h"
#include "renderer/data/T100DX12Camera.h"
#include "renderer/utils/T100DX12Timer.h"

#include "renderer/core/T100DX12Line.h"
#include "renderer/core/T100DX12Bundle.h"
#include "renderer/core/T100DX12Discrete.h"
#include "renderer/core/T100DX12Triangle.h"
#include "renderer/core/T100DX12Dynamic2.h"

#include "renderer/T100DX12FrameResource.h"

class T100DX12Studio : public T100DX12Area
{
    friend class T100DX12Dynamic2;
    friend class T100DX12Discrete;
    friend class T100DX12Bundle;
    friend class T100Dot;
    friend class T100Plane;
    friend class T100Triangle;
    friend class T100DX12Line;
    friend class T100DX12Triangle;
    friend class T100Sphere;
    friend class T100Rectangle;

    friend class T100DX12Scene;
    friend class T100DX12Model;
    friend class T100DX12Frame;
    friend class T100DX12Context;
    friend class T100DX12Renderer;
    friend class T100DX12SceneManager;
    friend class T100DX12ModelManager;
    friend class T100DX12FrameManager;
    friend class T100DX12ContextManager;
    friend class T100DX12ModelManagerBase;
    public:
        T100DX12Studio();
        virtual ~T100DX12Studio();

        virtual T100DX12HeapManager&            GetHeapManager();
        virtual T100DX12ModelManager&           GetModelManager();
        virtual T100DX12LightManager&           GetLightManager();

        virtual T100DX12Camera&                 GetCamera();

        virtual T100VOID                        SetScene(T100DX12Scene*);
        virtual T100DX12Scene*                  GetScene();

        virtual T100VOID                        Create(HWND, T100UINT, T100UINT);

        virtual T100VOID                        Start();
        virtual T100VOID                        Stop();

        virtual T100VOID                        Update();
        virtual T100VOID                        Render();

        T100VOID                                Waiting();

    protected:
        UINT64                                  m_fenceValue;
        HANDLE                                  m_fenceEvent;
        ComPtr<ID3D12Fence>                     m_fence;

        T100DX12FrameManager                    m_frame_manager;
        T100DX12ModelManager                    m_model_manager;
        T100DX12SceneManager                    m_scene_manager;
        T100DX12LightManager                    m_light_manager;
        T100DX12ContextManager                  m_context_manager;

        T100DX12Camera                          m_camera;
        T100DX12Timer                           m_timer;

        T100DX12Dynamic2                        m_dynamic;

        UINT                                    m_frameCounter;

    protected:
        T100VOID                                CreateFence();

        T100VOID                                InitCbvSrvHeapSize();

    private:
        T100VOID                                StudioStart();
        T100VOID                                StudioStop();
        T100VOID                                StudioUpdate();
        T100VOID                                StudioRender();
};

#endif // T100DX12STUDIO_H
