#ifndef T100SQLITE3_H
#define T100SQLITE3_H

#include "sqlite3.h"
#include "T100DatabaseBase.h"

namespace T100Library{

class T100SQLite3 : public T100DatabaseBase
{
    public:
        T100SQLite3();
        virtual ~T100SQLite3();

    protected:

    private:
};

}

#endif // T100SQLITE3_H
