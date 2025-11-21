#ifndef T100DX12FRAMEMANAGER_H
#define T100DX12FRAMEMANAGER_H

#include "data/T100DX12Frame.h"
#include "data/T100DX12Mesh.h"

class T100DX12Studio;

class T100DX12FrameManager
{
    public:
        T100DX12FrameManager(T100DX12Studio*);
        virtual ~T100DX12FrameManager();

        virtual T100VOID            Create();
        virtual T100VOID            Destroy();

        virtual T100VOID            Start();
        virtual T100VOID            Stop();

        virtual T100VOID            Update();
        virtual T100VOID            Render();

        virtual T100VOID            Append(T100DX12Mesh*);
        virtual T100VOID            Remove(T100DX12Mesh*);

    protected:
        T100DX12Studio*             m_studioPtr         = T100NULL;
        T100DX12_FRAME_VECTOR       m_frames;
        T100DX12Frame*              m_currentPtr        = T100NULL;
        T100UINT                    m_frameIndex        = 0;

        T100VOID                    CreateCommandAllocator(T100DX12Frame*);
        T100VOID                    CreateAndCloseCommandList(T100DX12Frame*);


    private:
};

#endif // T100DX12FRAMEMANAGER_H
