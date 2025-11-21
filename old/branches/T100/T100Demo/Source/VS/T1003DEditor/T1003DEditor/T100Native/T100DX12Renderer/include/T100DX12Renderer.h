#ifndef T100DX12RENDERER_H
#define T100DX12RENDERER_H

#include "link/T1003DRenderer.h"
#include "core/T100DX12Studio.h"

class T100DX12Renderer : public T1003DRenderer
{
    public:
        T100DX12Renderer();
        virtual ~T100DX12Renderer();

        virtual T100VOID            Create(T1003DWindowHandle, T100UINT, T100UINT);
        virtual T100VOID            Destroy();

        virtual T100VOID            SetSize(T100UINT, T100UINT);

        virtual T100VOID            Start();
        virtual T100VOID            Stop();

        virtual T100VOID            Update();
        virtual T100VOID            Render();

        virtual T100VOID            SetConfigPtr(T1003DConfig*);
        virtual T1003DConfig*       GetConfigPtr();

        virtual T100VOID            SetCameraPtr(T1003DCamera*);
        virtual T1003DCamera*       GetCameraPtr();

        virtual T100VOID            Append(T1003DMesh*);
        virtual T100VOID            Remove(T1003DMesh*);

        virtual T100UINT            GetWidth();
        virtual T100UINT            GetHeight();

        virtual T100FLOAT           GetAspectRatio();

        virtual T100VOID            SetBundle(T1003DMesh*);

        virtual T1003DTimer&        GetTimer();

    protected:
        T100DX12Studio*             m_studioPtr         = T100NULL;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100DX12RENDERER_H
