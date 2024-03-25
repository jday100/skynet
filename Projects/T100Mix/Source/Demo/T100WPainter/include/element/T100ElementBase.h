#ifndef T100ELEMENTBASE_H
#define T100ELEMENTBASE_H

#include <vector>
#include "T100Common.h"

#define     T100WPAINTER_ELEMENT_VECTOR                 std::vector<T100ElementBase*>

class T100ElementBase
{
    public:
        T100ElementBase();
        virtual ~T100ElementBase();

    protected:

    private:
};

#endif // T100ELEMENTBASE_H
