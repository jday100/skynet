#ifndef T100CANVAS_H
#define T100CANVAS_H

#include "T100Window.h"

class T100Canvas : public T100Window
{
    public:
        T100Canvas();
        T100Canvas(T100Win32Application*, T100Window*);
        virtual ~T100Canvas();

        T100VOID            Create(T100Win32Application*, T100Window*, T100WSTRING, T100WindowStyle*);

    protected:

    private:
};

#endif // T100CANVAS_H
