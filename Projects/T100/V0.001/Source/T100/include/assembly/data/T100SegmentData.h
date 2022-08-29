#ifndef T100SEGMENTDATA_H
#define T100SEGMENTDATA_H

#include "T100Segment.h"


class T100SegmentData : public T100Segment
{
    friend class T100CodeMerger;
    friend class T100ExecutableRealTinyFile;
    friend class T100ExecutableRealTinyMerger;
    friend class T100ExecutableNormalSmallMerger;
    friend class T100ExecutableNormalBigMerger;
    public:
        T100SegmentData();
        virtual ~T100SegmentData();

        T100BOOL                        addLabelCall(T100LABEL_CALL*);

    protected:
        T100LABElCALL_VECTOR            m_label_call;

    private:
};

#endif // T100SEGMENTDATA_H
