#ifndef T100EXECUTABLENORMALSMALLMERGER_H
#define T100EXECUTABLENORMALSMALLMERGER_H

#include "T100CodeMerger.h"
#include "T100AsmCommon.h"
#include "T100CodeNew.h"
#include "T100FileData.h"


class T100ExecutableNormalSmallMerger : public T100CodeMerger
{
    public:
        T100ExecutableNormalSmallMerger(T100Code*);
        virtual ~T100ExecutableNormalSmallMerger();

        T100FileData*           run(T100CODEDATA_VECTOR&);

    protected:
        T100BOOL                merge(T100FileData*, T100FileData*);
        T100BOOL                decideCode(T100SegmentCode*, T100SegmentCode*);
        T100BOOL                decideData(T100SegmentData*, T100SegmentData*);

    private:
        T100Code*               m_code          = T100NULL;
};

#endif // T100EXECUTABLENORMALSMALLMERGER_H
