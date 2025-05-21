#ifndef T100WINDOWFRAME_H
#define T100WINDOWFRAME_H

#include "gui/T100Frame.h"

class T100WindowFrame : public T100Frame
{
    public:
        T100WindowFrame(T100Win32Application*);
        virtual ~T100WindowFrame();

        T100VOID            Create(T100WSTRING);

    protected:

    private:
};

#endif // T100WINDOWFRAME_H
