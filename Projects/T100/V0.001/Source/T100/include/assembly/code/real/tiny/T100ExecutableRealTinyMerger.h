#ifndef T100EXECUTABLEREALTINYMERGER_H
#define T100EXECUTABLEREALTINYMERGER_H

#include "T100CodeMerger.h"
#include "T100AsmCommon.h"
#include "T100CodeNew.h"


class T100ExecutableRealTinyMerger : public T100CodeMerger
{
    public:
        T100ExecutableRealTinyMerger(T100Code*);
        virtual ~T100ExecutableRealTinyMerger();

        T100FileData*           run(T100CODEDATA_VECTOR&);

    protected:
        T100BOOL                merge(T100FileData*, T100FileData*);
        T100BOOL                decide(T100SegmentCode*, T100SegmentCode*);
        T100BOOL                decide(T100SegmentData*, T100SegmentData*);
        T100BOOL                mergeCode(T100SegmentCode*, T100SegmentCode*);
        T100BOOL                mergeData(T100SegmentData*, T100SegmentData*);

    private:
        T100Code*               m_code          = T100NULL;

};

#endif // T100EXECUTABLEREALTINYMERGER_H
