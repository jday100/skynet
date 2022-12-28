#ifndef T100ELEMENTBASE_H
#define T100ELEMENTBASE_H

#include "T100Common.h"

namespace T100Painter{

class T100ElementBase
{
    public:
        T100ElementBase();
        virtual ~T100ElementBase();

        virtual T100BOOL            draw() = 0;

    protected:

    private:
};

}

#endif // T100ELEMENTBASE_H
