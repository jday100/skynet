#ifndef T100HELLOFRAME_H
#define T100HELLOFRAME_H

#include "gui/T100Frame.h"

class T100HelloFrame : public T100Frame
{
    public:
        T100HelloFrame();
        virtual ~T100HelloFrame();

        T100VOID            Create(T100Win32Application*);

    protected:

    private:
};

#endif // T100HELLOFRAME_H
