#ifndef T100SEGMENTDATA_H
#define T100SEGMENTDATA_H

#include "T100Segment.h"


class T100SegmentData : public T100Segment
{
    public:
        T100SegmentData();
        virtual ~T100SegmentData();

        T100BOOL                    setValue(T100WORD);
        T100VOID                    next();

        T100BOOL                    setVariable(T100String, T100WORD);
        T100BOOL                    getVariable(T100String, T100WORD&);

    protected:
        T100VARIABLEOFFSET_HASH     m_variable_hash;

    private:
};

#endif // T100SEGMENTDATA_H
