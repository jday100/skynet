#ifndef T100DX12STUDIO_H
#define T100DX12STUDIO_H

#include "core/T100DX12Area.h"
#include "data/T100DX12Timer.h"
#include "mesh/T100DX12MeshManager.h"
#include "light/T100DX12LightManager.h"
#include "frame/T100DX12FrameManager.h"
#include "camera/T100DX12CameraManager.h"
#include "context/T100DX12ContextManager.h"

#include "test/T100DX12BundleTest.h"

class T100DX12Studio : public T100DX12Area
{
    friend class T100DX12FrameManager;
    public:
        T100DX12Studio();
        virtual ~T100DX12Studio();

        T100DX12MeshManager&                    GetMeshManager();
        T100DX12LightManager&                   GetLightManager();
        T100DX12FrameManager&                   GetFrameManager();
        T100DX12CameraManager&                  GetCameraManager();
        T100DX12ContextManager&                 GetContextManager();

        virtual T100VOID                        Create(HWND, T100UINT, T100UINT);
        virtual T100VOID                        Destroy();

        virtual T100VOID                        Start();
        virtual T100VOID                        Stop();

        virtual T100VOID                        Update();
        virtual T100VOID                        Render();

        virtual T100VOID                        Append(T1003DMesh*);
        virtual T100VOID                        Remove(T1003DMesh*);

        virtual T100VOID                        SetBundle(T1003DMesh*);

        T100VOID                                Waiting();

        virtual T100VOID                        SetCameraPtr(T1003DCamera*);
        virtual T1003DCamera*                   GetCameraPtr();

        virtual T1003DTimer&                    GetTimer();

        virtual T100DX12Camera*                 GetCameraInstancePtr();

        virtual T100UINT                        GetWidth();
        virtual T100UINT                        GetHeight();

    protected:
        T100UINT64                              m_fenceValue;
        HANDLE                                  m_fenceEvent;
        ComPtr<ID3D12Fence>                     m_fence;

        T100DX12MeshManager                     m_meshManager;
        T100DX12LightManager                    m_lightManager;
        T100DX12FrameManager                    m_frameManager;
        T100DX12CameraManager                   m_cameraManager;
        T100DX12ContextManager                  m_contextManager;

        T100DX12Timer                           m_timer;

        T100DX12BundleTest                      m_bundleTest;

    protected:
        T100VOID                                CreateFence();

    private:

        ComPtr<ID3D12GraphicsCommandList>       m_commandList;
        ComPtr<ID3D12PipelineState>             m_pipelineState;

        ComPtr<ID3D12RootSignature>             m_rootSignature;
};

#endif // T100DX12STUDIO_H
