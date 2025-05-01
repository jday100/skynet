#ifndef T100FRAMEBASE_H
#define T100FRAMEBASE_H

#include "gui/T100OwnedWindow.h"

class T100FrameBase : public T100OwnedWindow
{
    public:
        T100FrameBase();
        virtual ~T100FrameBase();

        T100VOID            Maximize();
        T100VOID            Minimize();
        T100VOID            RestoreSize();

    protected:

    private:
};

#endif // T100FRAMEBASE_H
