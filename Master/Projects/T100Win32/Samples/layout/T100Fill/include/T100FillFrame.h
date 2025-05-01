#ifndef T100FILLFRAME_H
#define T100FILLFRAME_H

#include "gui/T100Frame.h"

class T100FillFrame : public T100Frame
{
    public:
        T100FillFrame();
        virtual ~T100FillFrame();

        T100VOID            Create(T100WSTRING, T100UINT, T100UINT);

    protected:

    private:
        T100VOID            init();
        T100VOID            uninit();
};

#endif // T100FILLFRAME_H
