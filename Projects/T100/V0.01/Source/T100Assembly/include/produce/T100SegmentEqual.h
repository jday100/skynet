#ifndef T100SEGMENTEQUAL_H
#define T100SEGMENTEQUAL_H

#include "T100Segment.h"


class T100SegmentEqual
{
    public:
        T100SegmentEqual();
        virtual ~T100SegmentEqual();

        bool operator()(const T100SEGMENT_KEY& key1, const T100SEGMENT_KEY& key2) const {
            return key1.name == key2.name && key1.location == key2.location;
        }

    protected:

    private:
};

#endif // T100SEGMENTEQUAL_H
