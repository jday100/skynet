#ifndef T100FRAME_H
#define T100FRAME_H

#include "gui/T100AllEvents.h"
#include "gui/frame/T100FrameBase.h"
#include "gui/T100FrameStyle.h"

class T100Frame : public T100FrameBase
{
    public:
        T100Frame();
        T100Frame(T100Win32Application*, T100Window* = T100NULL);
        virtual ~T100Frame();

        T100VOID            Create(T100WSTRING, T100FrameStyle* = T100NULL);
        T100VOID            Create(T100Win32Application*, T100WSTRING, T100FrameStyle* = T100NULL);

    protected:
        T100VOID            OnFrameResize(T100WindowEvent&);

    private:

};

#endif // T100FRAME_H
