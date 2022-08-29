#ifndef T100REALMERGER_H
#define T100REALMERGER_H

#include "T100ProduceMerger.h"
#include "T100RealInfo.h"


class T100RealMerger : public T100ProduceMerger
{
    public:
        T100RealMerger();
        virtual ~T100RealMerger();

        T100BOOL            run(T100ProduceInfo&, T100RealInfo&);

    protected:
        T100BOOL            merge(T100RealInfo&, T100PartInfo*);

        T100BOOL            decide_code(T100SegmentCode*, T100SegmentCode*);
        T100BOOL            decide_data(T100SegmentData*, T100SegmentData*);

        T100BOOL            merge_code(T100SegmentCode*, T100SegmentCode*);
        T100BOOL            merge_data(T100SegmentData*, T100SegmentData*);

    private:
};

#endif // T100REALMERGER_H
