#ifndef T1003DEDITORCAMERAMANAGER_H
#define T1003DEDITORCAMERAMANAGER_H

#include <atomic>
#include "T100Common.h"
#include "data/T100Camera.h"

class T1003DEditorCameraManager
{
    public:
        T1003DEditorCameraManager();
        virtual ~T1003DEditorCameraManager();

        T100Camera*             GetCamera();

    protected:
        std::atomic_int         m_cameraCount;

    private:
        T100VOID                init();
        T100VOID                uninit();
};

#endif // T1003DEDITORCAMERAMANAGER_H
