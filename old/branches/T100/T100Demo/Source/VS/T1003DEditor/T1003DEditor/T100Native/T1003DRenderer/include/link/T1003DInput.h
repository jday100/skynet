#ifndef T1003DINPUT_H
#define T1003DINPUT_H

#include "T100Common.h"

class T1003DInput
{
    public:
        T1003DInput();
        virtual ~T1003DInput();

        virtual T100VOID            OnKeyDown(T100INT) = 0;
        virtual T100VOID            OnKeyUp(T100INT) = 0;

    protected:

    private:
};

#endif // T1003DINPUT_H
