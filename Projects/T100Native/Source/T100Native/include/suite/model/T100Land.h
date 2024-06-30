#ifndef T100LAND_H
#define T100LAND_H

#include "T100Entity.h"

class T100Land : public T100Entity
{
    public:
        T100Land();
        virtual ~T100Land();

        T100VOID            SetTerminus(T100FLOAT, T100FLOAT, T100FLOAT);

    protected:

    private:
};

#endif // T100LAND_H
