#ifndef T100SEGMENTEQUAL_H
#define T100SEGMENTEQUAL_H

#include "T100AssemblyCommon.h"

namespace T100Assembly{

class T100SegmentEqual
{
    public:
        T100SegmentEqual();
        virtual ~T100SegmentEqual();

        bool operator()(const T100SEGMENT_KEY& key1, const T100SEGMENT_KEY& key2) const {
            return const_cast<T100STRING&>(key1.NAME) == const_cast<T100STRING&>(key2.NAME) && key1.LOCATION == key2.LOCATION;
        }

    protected:

    private:
};

}

#endif // T100SEGMENTEQUAL_H
