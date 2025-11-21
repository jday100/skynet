#ifndef T100POINT_H
#define T100POINT_H

#include "base/T100Class.h"

namespace T100LIBRARY{

class T100Point : public T100Class
{
    public:
        T100Point();
        T100Point(T100INT, T100INT);
        virtual ~T100Point();

        T100INT             X       = 0;
        T100INT             Y       = 0;

    protected:

    private:
};

}

#endif // T100POINT_H
