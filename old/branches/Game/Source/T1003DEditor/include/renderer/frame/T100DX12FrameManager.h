#ifndef T100DX12FRAMEMANAGER_H
#define T100DX12FRAMEMANAGER_H

#include "renderer/data/T100DX12Frame.h"
#include "entity/T100City.h"
#include "renderer/data/T100DX12Model.h"

class T100DX12Studio;

class T100DX12FrameManager
{
    friend class T100DX12Line;
    friend class T100DX12Triangle;

    friend class T100DX12Studio;
    friend class T100DX12ContextManager;
    public:
        T100DX12FrameManager(T100DX12Studio*);
        virtual ~T100DX12FrameManager();

        T100DX12Frame*                          GetCurrentFrame();

        virtual T100VOID                        Start();
        virtual T100VOID                        Stop();

        virtual T100VOID                        Update();
        virtual T100VOID                        Render();

        virtual T100VOID                        Append(T100DX12Model*);
        virtual T100VOID                        Remove(T100DX12Model*);

        virtual T100VOID                        Remove(T100DX12Context*);

    protected:
        T100DX12Studio*                         m_studio            = T100NULL;
        T100DX12_FRAME_VECTOR                   m_frames;
        T100DX12Frame*                          m_current           = T100NULL;
        T100DX12Frame*                          m_back              = T100NULL;

    protected:
        T100VOID                                ContextAppend(T100DX12Model*);

    protected:
        T100VOID                                FrameManagerStart();
        T100VOID                                FrameManagerStop();
        T100VOID                                FrameManagerUpdate();
        T100VOID                                FrameManagerRender();

        T100VOID                                FrameManagerAppend(T100DX12Model*);
        T100VOID                                FrameManagerRemove(T100DX12Model*);

        T100VOID                                CreateFrames();
        T100VOID                                CreateCommandAllocators();
        T100VOID                                CreateAndCloseCommandList(T100DX12Frame*);

        T100VOID                                PopulateCommandList(T100DX12Frame*);

    protected:
        UINT                                    m_frameCounter;
        UINT                                    m_currentFrameResourceIndex;

    protected:

    private:
        std::wstring                            m_title;

        void    SetCustomWindowText(LPCWSTR text);
};

#endif // T100DX12FRAMEMANAGER_H
