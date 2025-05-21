#ifndef T100FRAME_H
#define T100FRAME_H

#include "gui/frame/T100FrameBase.h"

class T100Frame : public T100FrameBase
{
    public:
        T100Frame();
        T100Frame(T100Win32Application*, T100WSTRING);
        virtual ~T100Frame();

        virtual T100VOID            Create(T100Win32Application*, T100WSTRING);
        virtual T100VOID            Destroy();

    protected:

    private:
};

#endif // T100FRAME_H
