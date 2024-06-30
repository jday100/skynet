#ifndef T100LIGHT_H
#define T100LIGHT_H

#include <vector>
#include "T100Common.h"

#define     T100LIGHT_VECTOR            std::vector<T100Light*>

class T100Light
{
    public:
        T100Light();
        virtual ~T100Light();

        T100VOID            Location(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID            Direction(T100FLOAT, T100FLOAT, T100FLOAT);

    protected:

    private:
};

#endif // T100LIGHT_H
