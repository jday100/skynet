#ifndef T100DX12MOTION_H
#define T100DX12MOTION_H

#include "T100Common.h"
#include "renderer/data/T100DX12Camera.h"

class T100DX12Motion
{
    public:
        T100DX12Motion();
        virtual ~T100DX12Motion();

        T100VOID                    SetCameraPtr(T100DX12Camera*);
        T100DX12Camera*             GetCameraPtr();

        T100VOID                    Forward();
        T100VOID                    Backward();
        T100VOID                    MoveLeft();
        T100VOID                    MoveRight();
        T100VOID                    MoveUp();
        T100VOID                    MoveDown();

        T100VOID                    LookUp();
        T100VOID                    LookDown();
        T100VOID                    TurnLeft();
        T100VOID                    TurnRight();
        T100VOID                    LeftHead();
        T100VOID                    RightHead();

        T100VOID                    Reset();

    protected:
        T100DX12Camera*             m_cameraPtr         = T100NULL;
        T100UINT                    m_step              = 1;
        T100UINT                    m_turn              = 5;

    private:
};

#endif // T100DX12MOTION_H
