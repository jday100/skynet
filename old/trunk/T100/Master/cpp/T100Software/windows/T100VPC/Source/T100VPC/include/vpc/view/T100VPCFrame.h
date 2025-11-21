#ifndef T100VPCFRAME_H
#define T100VPCFRAME_H

#include "gui/T100Frame.h"

using namespace T100WINDOWS;

class T100VPCFrame : public T100Frame
{
    public:
        T100VPCFrame();
        virtual ~T100VPCFrame();

        T100WSTRING         Value;

        T100VOID            Create(T100Win32Application*);
        T100VOID            Destroy();

    protected:
        T100VOID            OnPaint(T100PaintEvent&);

    private:
        T100VOID            init();
        T100VOID            uninit();
};

#endif // T100VPCFRAME_H
