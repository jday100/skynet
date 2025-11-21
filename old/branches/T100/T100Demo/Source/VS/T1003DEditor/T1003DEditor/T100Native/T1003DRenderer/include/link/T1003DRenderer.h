#ifndef T1003DRENDERER_H
#define T1003DRENDERER_H

#include "T1003DCommon.h"
#include "T1003DConfig.h"
#include "T1003DCamera.h"
#include "T1003DMesh.h"
#include "T1003DTimer.h"

class T1003DRenderer
{
    public:
        T1003DRenderer();
        virtual ~T1003DRenderer();

        virtual T100VOID            Create(T1003DWindowHandle, T100UINT, T100UINT) = 0;
        virtual T100VOID            Destroy() = 0;

        virtual T100VOID            SetSize(T100UINT, T100UINT) = 0;

        virtual T100VOID            Start() = 0;
        virtual T100VOID            Stop() = 0;

        virtual T100VOID            Update() = 0;
        virtual T100VOID            Render() = 0;

        virtual T100VOID            SetConfigPtr(T1003DConfig*) = 0;
        virtual T1003DConfig*       GetConfigPtr() = 0;

        virtual T100VOID            SetCameraPtr(T1003DCamera*) = 0;
        virtual T1003DCamera*       GetCameraPtr() = 0;

        virtual T100VOID            Append(T1003DMesh*) = 0;
        virtual T100VOID            Remove(T1003DMesh*) = 0;

        virtual T100UINT            GetWidth() = 0;
        virtual T100UINT            GetHeight() = 0;

        virtual T100FLOAT           GetAspectRatio() = 0;

        virtual T100VOID            SetBundle(T1003DMesh*) = 0;

        virtual T1003DTimer&        GetTimer() = 0;

    protected:

    private:
};

#endif // T1003DRENDERER_H
