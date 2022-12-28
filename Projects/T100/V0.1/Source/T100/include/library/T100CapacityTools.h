#ifndef T100CAPACITYTOOLS_H
#define T100CAPACITYTOOLS_H

#include "T100Class.h"

namespace T100Library{

class T100CapacityTools
{
    public:
        T100CapacityTools();
        virtual ~T100CapacityTools();

        static T100BOOL         to_word(T100WSTRING, T100WORD&);
        static T100BOOL         to_dword(T100WSTRING, T100DWORD&);

        static T100WSTRING      to_wstring(T100WORD);
        static T100WSTRING      to_wstring(T100DWORD);

    protected:

    private:
};

}

#endif // T100CAPACITYTOOLS_H
