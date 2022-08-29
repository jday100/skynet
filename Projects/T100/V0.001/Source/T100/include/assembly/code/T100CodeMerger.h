#ifndef T100CODEMERGER_H
#define T100CODEMERGER_H

#include "T100SegmentCode.h"
#include "T100SegmentData.h"


class T100CodeMerger
{
    public:
        T100CodeMerger();
        virtual ~T100CodeMerger();

    protected:
        virtual T100BOOL        mergeCode(T100SegmentCode*, T100SegmentCode*);
        virtual T100BOOL        mergeData(T100SegmentData*, T100SegmentData*);

    private:
};

#endif // T100CODEMERGER_H
