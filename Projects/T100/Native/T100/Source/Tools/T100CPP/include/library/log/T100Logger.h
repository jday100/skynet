#ifndef T100LOGGER_H
#define T100LOGGER_H

#include "T100Common.h"
#include "T100WString.h"

class T100Logger
{
    public:
        T100Logger();
        virtual ~T100Logger();

        virtual T100BOOL            log(T100WString);

    protected:

    private:
};

#endif // T100LOGGER_H
