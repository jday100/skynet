#ifndef T100VMWIN_H
#define T100VMWIN_H

#include "core/T100VMBase.h"

class T100VMWin : public T100VMBase
{
    public:
        T100VMWin();
        virtual ~T100VMWin();

        virtual T100VOID            Start();
        virtual T100VOID            Stop();

    protected:

    private:
};

#endif // T100VMWIN_H
