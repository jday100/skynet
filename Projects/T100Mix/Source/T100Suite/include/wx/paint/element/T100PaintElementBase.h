#ifndef T100PAINTELEMENTBASE_H
#define T100PAINTELEMENTBASE_H

#include "T100Common.h"
#include "safe\T100SafeVector.h"

#define     T100PAINTER_ELEMENT_VECTOR          T100SafeVector<T100PaintElementBase*>


class T100PaintElementBase
{
    public:
        T100PaintElementBase();
        virtual ~T100PaintElementBase();

    protected:

    private:
};

#endif // T100PAINTELEMENTBASE_H
