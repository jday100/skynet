#ifndef T100EXECUTABLENORMALBIGMERGER_H
#define T100EXECUTABLENORMALBIGMERGER_H

#include "T100CodeMerger.h"
#include "T100AsmCommon.h"
#include "T100CodeNew.h"
#include "T100FileData.h"


class T100ExecutableNormalBigMerger : public T100CodeMerger
{
    public:
        T100ExecutableNormalBigMerger(T100Code*);
        virtual ~T100ExecutableNormalBigMerger();

        T100FileData*           run(T100CODEDATA_VECTOR&);

    protected:
        T100BOOL                merge(T100FileData*, T100FileData*);
        T100BOOL                decide(T100SegmentCode*, T100SegmentCode*);
        T100BOOL                decide(T100SegmentData*, T100SegmentData*);
        T100BOOL                mergeCode(T100SegmentCode*, T100SegmentCode*);
        T100BOOL                mergeData(T100SegmentData*, T100SegmentData*);

        T100Segment*            findCode(T100SEGMENT_KEY*);
        T100Segment*            findData(T100SEGMENT_KEY*);
        T100Segment*            findShareCode(T100SEGMENT_KEY*);
        T100Segment*            findShareData(T100SEGMENT_KEY*);

    private:
        T100Code*               m_code          = T100NULL;
        T100SEGMENTDATA_HASH    m_code_segments;
        T100SEGMENTDATA_HASH    m_data_segments;
        T100SEGMENTDATA_HASH    m_share_code_segments;
        T100SEGMENTDATA_HASH    m_share_data_segments;

};

#endif // T100EXECUTABLENORMALBIGMERGER_H
