#ifndef T100TIME_H
#define T100TIME_H

#include "base/T100Class.h"

using namespace T100LIBRARY;

namespace T100WINDOWS{

class T100Time : public T100Class
{
    public:
        T100Time();
        virtual ~T100Time();

        static T100UINT             Now();

        static T100UINT             GetMilliSeconds();

        static T100UINT             GetNanoSeconds();

    protected:

    private:
};

}

#endif // T100TIME_H
