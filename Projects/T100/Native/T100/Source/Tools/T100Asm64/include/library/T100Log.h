#ifndef T100LOG_H
#define T100LOG_H

#include "T100Common.h"


class T100Log
{
    public:
        T100Log();
        virtual ~T100Log();

        static T100VOID             log(T100STRING);

    protected:

    private:
};

#endif // T100LOG_H
