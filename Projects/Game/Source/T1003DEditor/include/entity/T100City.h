#ifndef T100CITY_H
#define T100CITY_H

#include "T100Entity.h"

class T100City : public T100Entity
{
    public:
        T100City();
        virtual ~T100City();

    protected:

    private:
        T100VOID                    create();
        T100VOID                    destroy();
};

#endif // T100CITY_H
