#ifndef T100BYTESCANNER_H
#define T100BYTESCANNER_H

#include "T100Scanner.h"

namespace T100Assembly{

class T100ByteScanner : public T100Component::T100Scanner
{
    public:
        T100ByteScanner();
        virtual ~T100ByteScanner();

    protected:

    private:
};

}

#endif // T100BYTESCANNER_H
