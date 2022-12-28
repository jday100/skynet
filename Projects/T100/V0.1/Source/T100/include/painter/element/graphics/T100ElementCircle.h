#ifndef T100ELEMENTCIRCLE_H
#define T100ELEMENTCIRCLE_H

#include "T100ElementBase.h"

namespace T100Painter{


class T100ElementCircle : public T100ElementBase
{
    public:
        T100ElementCircle();
        virtual ~T100ElementCircle();

        T100BOOL            draw();

    protected:

    private:
};

}

#endif // T100ELEMENTCIRCLE_H
