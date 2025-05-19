#ifndef T100CANVAS_H
#define T100CANVAS_H

#include "gui/T100Panel.h"

class T100Win32Application;

class T100Canvas : public T100Panel
{
    public:
        T100Canvas();
        T100Canvas(T100Win32Application*, T100Window*);
        virtual ~T100Canvas();

    protected:

    private:
};

#endif // T100CANVAS_H
