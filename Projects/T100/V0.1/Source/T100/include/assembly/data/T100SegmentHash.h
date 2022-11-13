#ifndef T100SEGMENTHASH_H
#define T100SEGMENTHASH_H

#include "T100AssemblyCommon.h"

namespace T100Assembly{

class T100SegmentHash
{
    public:
        T100SegmentHash();
        virtual ~T100SegmentHash();

        std::size_t operator()(const T100SEGMENT_KEY& key) const {
            return std::hash<std::u32string>()(key.NAME.m_string32.m_string32) ^ std::hash<T100WORD>()(key.LOCATION);
        }

    protected:

    private:
};

}

#endif // T100SEGMENTHASH_H
