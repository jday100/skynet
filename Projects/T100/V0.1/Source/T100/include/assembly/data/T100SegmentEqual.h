#ifndef T100SEGMENTEQUAL_H
#define T100SEGMENTEQUAL_H

#include "T100AssemblyCommon.h"

namespace T100Assembly{

class T100SegmentEqual
{
    public:
        T100SegmentEqual();
        virtual ~T100SegmentEqual();

        boot operator()(const T100SEGMENT_KEY& key1, const T100SEGMENT_KEY& key2) const {
            return key1.name == key2.name && key1.LOCATION == key2.LOCATION;
        }

    protected:

    private:
};

}

#endif // T100SEGMENTEQUAL_H
