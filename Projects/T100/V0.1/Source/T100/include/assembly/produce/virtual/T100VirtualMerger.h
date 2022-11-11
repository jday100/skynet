#ifndef T100VIRTUALMERGER_H
#define T100VIRTUALMERGER_H

#include "T100ProduceMerger.h"
#include "T100VirtualInfo.h"

namespace T100Assembly{

class T100VirtualMerger : public T100ProduceMerger
{
    public:
        T100VirtualMerger();
        virtual ~T100VirtualMerger();

        T100BOOL                run(T100ProduceInfo&, T100VirtualInfo&);

    protected:
        T100BOOL                merge(T100PartInfo*);
        T100BOOL                merge(T100SEGMENT_CODE_VECTOR&);
        T100BOOL                merge(T100SEGMENT_DATA_VECTOR&);
        T100BOOL                decide(T100SegmentCode*, T100SegmentCode*);
        T100BOOL                decide(T100SegmentData*, T100SegmentData*);
        T100BOOL                mergeCode(T100SegmentCode*, T100SegmentCode*);
        T100BOOL                mergeData(T100SegmentData*, T100SegmentData*);

        T100Segment*            findCode(T100SEGMENT_KEY*);
        T100Segment*            findData(T100SEGMENT_KEY*);
        T100Segment*            findShareCode(T100SEGMENT_KEY*);
        T100Segment*            findShareData(T100SEGMENT_KEY*);

        T100Segment*            find(T100SEGMENT_KEY*, T100SEGMENT_HASH&);
        T100BOOL                mergeCode(T100SegmentCode*, T100SegmentCode*&, T100SEGMENT_CODE_VECTOR&, T100SEGMENT_HASH&);
        T100BOOL                mergeData(T100SegmentData*, T100SegmentData*&, T100SEGMENT_DATA_VECTOR&, T100SEGMENT_HASH&);

    private:
        T100VirtualInfo*        m_info          = T100NULL;
        T100SEGMENT_HASH        m_codes;
        T100SEGMENT_HASH        m_datas;
        T100SEGMENT_HASH        m_share_codes;
        T100SEGMENT_HASH        m_share_datas;

};

}

#endif // T100VIRTUALMERGER_H
