#ifndef T100SEGMENTDATA_H
#define T100SEGMENTDATA_H

#include "T100Segment.h"
#include "T100ProduceInfo.h"

namespace T100Assembly{

class T100SegmentData : public T100Segment
{
    friend class T100RealMerger;
    friend class T100VirtualMerger;
    public:
        T100SegmentData();
        virtual ~T100SegmentData();

        T100BOOL                    setValue(T100WORD);
        T100VOID                    next();

        T100BOOL                    setVariable(T100STRING, T100WORD);
        T100BOOL                    getVariable(T100STRING, T100WORD&);

        T100BOOL                    addLabelCall(T100LABEL_CALL*);

    protected:
        T100VARIABLEOFFSET_HASH     m_variable_hash;
        T100LABELCALL_VECTOR        m_label_call;

    private:
};

}

#endif // T100SEGMENTDATA_H
