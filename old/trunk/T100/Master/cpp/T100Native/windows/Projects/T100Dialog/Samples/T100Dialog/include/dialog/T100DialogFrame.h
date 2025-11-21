#ifndef T100DIALOGFRAME_H
#define T100DIALOGFRAME_H

#include "gui/T100Frame.h"

using namespace T100WINDOWS;

class T100DialogFrame : public T100Frame
{
    public:
        T100DialogFrame();
        virtual ~T100DialogFrame();

        virtual T100VOID        Create(T100Win32Application*, T100FrameStyle* = T100NULL);

    protected:
        T100VOID                OnDialog(T100MenuEvent&);

    private:
        T100VOID                init();
        T100VOID                uninit();
};

#endif // T100DIALOGFRAME_H
