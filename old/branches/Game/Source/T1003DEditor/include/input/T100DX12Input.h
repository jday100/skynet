#ifndef T100DX12INPUT_H
#define T100DX12INPUT_H

//#include <dinput.h>
#include "T100Common.h"
#include "motion/T100DX12Motion.h"

class T100DX12Input
{
    public:
        T100DX12Input();
        virtual ~T100DX12Input();

        T100VOID                    SetMotionPtr(T100DX12Motion*);
        T100DX12Motion*             GetMotionPtr();

        virtual T100VOID            OnKeyDown(T100INT);
        virtual T100VOID            OnKeyUp(T100INT);


        virtual T100VOID            Create();
        virtual T100VOID            Destroy();

        virtual T100VOID            Start();
        virtual T100VOID            Stop();

    protected:
        T100DX12Motion*             m_motionPtr         = T100NULL;

        T100VOID                    InputCreate();

    private:
        //HWND                        m_hwnd;
        //LPDIRECTINPUT8              m_directInput;
        //LPDIRECTINPUTDEVICE8        m_directDevice;
        //DIMOUSESTATE                m_mouseState;
};

#endif // T100DX12INPUT_H
