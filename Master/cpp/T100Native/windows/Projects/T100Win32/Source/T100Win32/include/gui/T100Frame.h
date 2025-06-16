#ifndef T100FRAME_H
#define T100FRAME_H

#include "gui/T100FrameStyle.h"
#include "gui/window/T100SelfLoopWindow.h"

namespace T100WINDOWS{

class T100Win32Application;

class T100Frame : public T100SelfLoopWindow
{
    public:
        T100Frame();
        T100Frame(T100Win32Application*);
        virtual ~T100Frame();

        virtual T100VOID        Create(T100Win32Application*, T100FrameStyle* = T100NULL);
        virtual T100VOID        Destroy();

    protected:

    private:
        T100VOID                init(T100Win32Application*);
        T100VOID                uninit();
};

}

#endif // T100FRAME_H
