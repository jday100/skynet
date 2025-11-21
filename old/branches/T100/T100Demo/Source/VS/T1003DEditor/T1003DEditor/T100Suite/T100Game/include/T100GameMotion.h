#ifndef T100GAMEMOTION_H
#define T100GAMEMOTION_H

#include "T100Common.h"
#include "link/T1003DCamera.h"

class T100GameMotion
{
    public:
        T100GameMotion();
        virtual ~T100GameMotion();

        T100VOID                    SetCameraPtr(T1003DCamera*);
        T1003DCamera*               GetCameraPtr();

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
        T1003DCamera*               m_cameraPtr         = T100NULL;
        T100UINT                    m_step              = 1;
        T100UINT                    m_turn              = 5;

    private:
};

#endif // T100GAMEMOTION_H
