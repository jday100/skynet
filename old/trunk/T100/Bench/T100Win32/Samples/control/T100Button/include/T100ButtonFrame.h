#ifndef T100BUTTONFRAME_H
#define T100BUTTONFRAME_H

#include "gui/T100Frame.h"

using namespace T100WINDOWS;

class T100ButtonFrame : public T100Frame
{
    public:
        T100ButtonFrame();
        virtual ~T100ButtonFrame();

        T100VOID            Create(T100Win32Application*);

    protected:
        T100VOID            OnButtonClick(T100CommandEvent&);

    private:
        T100VOID            init();
        T100VOID            uninit();
};

#endif // T100BUTTONFRAME_H
