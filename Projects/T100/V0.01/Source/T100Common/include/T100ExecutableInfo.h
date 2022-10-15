#ifndef T100EXECUTABLEINFO_H
#define T100EXECUTABLEINFO_H

#include "T100String.h"
#include "T100ExecutableCommon.h"
#include <vector>
class T100SegmentCode;
class T100SegmentData;
#define     T100SEGMENT_CODE_VECTOR     std::vector<T100SegmentCode*>
#define     T100SEGMENT_DATA_VECTOR     std::vector<T100SegmentData*>

class T100ExecutableInfo
{
    public:
        T100ExecutableInfo();
        virtual ~T100ExecutableInfo();

        T100SEGMENT_CODE_VECTOR         m_codes;

        T100SEGMENT_DATA_VECTOR         m_datas;

        T100SEGMENT_CODE_VECTOR         m_share_codes;

        T100SEGMENT_DATA_VECTOR         m_share_datas;

    protected:

    private:
};

#endif // T100EXECUTABLEINFO_H
