#ifndef T100CAPACITYPARSER_H
#define T100CAPACITYPARSER_H

#include "T100String.h"

namespace T100Library{

class T100CapacityParser
{
    public:
        T100CapacityParser();
        virtual ~T100CapacityParser();

        virtual T100BOOL            parse(T100WSTRING, T100DWORD&);

    protected:

    private:
};

}

#endif // T100CAPACITYPARSER_H
