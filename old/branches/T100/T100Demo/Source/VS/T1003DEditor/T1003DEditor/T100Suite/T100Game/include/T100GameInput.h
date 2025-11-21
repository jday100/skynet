#ifndef T100GAMEINPUT_H
#define T100GAMEINPUT_H

#include "link/T1003DInput.h"
#include "link/T1003DCamera.h"
#include "T100GameMotion.h"

class T100GameInput : public T1003DInput
{
    public:
        T100GameInput();
        virtual ~T100GameInput();

        virtual T100VOID            OnKeyDown(T100INT);
        virtual T100VOID            OnKeyUp(T100INT);



        T100VOID                    SetMotionPtr(T100GameMotion*);
        T100GameMotion*             GetMotionPtr();

    protected:

        T100GameMotion*             m_motionPtr         = T100NULL;

    private:
};

#endif // T100GAMEINPUT_H
