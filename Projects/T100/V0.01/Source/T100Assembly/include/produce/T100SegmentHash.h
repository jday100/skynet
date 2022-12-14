#ifndef T100SEGMENTHASH_H
#define T100SEGMENTHASH_H

#include "T100AssemblyCommon.h"


class T100SegmentHash
{
    public:
        T100SegmentHash();
        virtual ~T100SegmentHash();

        std::size_t operator()(const T100SEGMENT_KEY& key) const {
            return std::hash<std::u32string>()(key.name.m_string32.m_string32) ^ std::hash<T100WORD>()(key.location);
        }

    protected:

    private:
};

#endif // T100SEGMENTHASH_H
