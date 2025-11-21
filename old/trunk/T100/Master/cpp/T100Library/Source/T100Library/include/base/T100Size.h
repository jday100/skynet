#ifndef T100SIZE_H
#define T100SIZE_H

#include "base/T100Class.h"

namespace T100LIBRARY{

class T100Size : public T100Class
{
    public:
        T100Size();
        T100Size(T100INT, T100INT);
        virtual ~T100Size();

        T100INT             Width       = 0;
        T100INT             Height      = 0;

    protected:

    private:
};

}

#endif // T100SIZE_H
