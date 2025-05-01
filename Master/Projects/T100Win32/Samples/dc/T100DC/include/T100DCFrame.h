#ifndef T100DCFRAME_H
#define T100DCFRAME_H

#include "gui/T100Frame.h"

class T100DCFrame : public T100Frame
{
    public:
        T100DCFrame();
        virtual ~T100DCFrame();

        T100VOID            Create(T100WSTRING, T100UINT, T100UINT);

    protected:
        T100VOID            OnFramePaint(T100WindowEvent& event);

    private:
        T100VOID            init();
        T100VOID            uninit();
};

#endif // T100DCFRAME_H
