#ifndef T100TIME_H
#define T100TIME_H

#include "base/T100Class.h"

class T100Time : public T100Class
{
    public:
        T100Time();
        virtual ~T100Time();

        T100WORD            Now();

        T100WORD            GetMilliseconds();

        T100WORD            GetNanoSeconds();

    protected:

    private:
};

#endif // T100TIME_H
