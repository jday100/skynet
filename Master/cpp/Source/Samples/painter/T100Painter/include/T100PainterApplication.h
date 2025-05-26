#ifndef T100PAINTERAPPLICATION_H
#define T100PAINTERAPPLICATION_H

#include "gui/T100Win32Application.h"
#include "T100Painter.h"

class T100PainterApplication : public T100Win32Application
{
    public:
        T100PainterApplication();
        virtual ~T100PainterApplication();

        T100VOID                Create();

    protected:
        T100Painter             m_painter;

    private:
};

#endif // T100PAINTERAPPLICATION_H
