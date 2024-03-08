#ifndef T100DATABASEBASE_H
#define T100DATABASEBASE_H

#include "T100Common.h"
#include "T100String.h"

namespace T100Library{

class T100DatabaseBase
{
    public:
        T100DatabaseBase();
        virtual ~T100DatabaseBase();

        virtual T100BOOL            connect() = 0;
        virtual T100BOOL            disconnect() = 0;

        virtual T100BOOL            query(T100STRING) = 0;
        virtual T100BOOL            execute(T100STRING) = 0;

    protected:

    private:
};

}

#endif // T100DATABASEBASE_H
