#ifndef T100BUILDINFO_H
#define T100BUILDINFO_H

#include "T100Token.h"
#include "T100AssemblyCommon.h"
#include "T100SegmentCode.h"
#include "T100SegmentData.h"
class T100Sentence;


class T100BuildInfo
{
    public:
        T100BuildInfo();
        virtual ~T100BuildInfo();


        T100BOOL                    setValue(T100WORD);
        T100WORD                    getOffset();
        T100VOID                    next();

        T100BOOL                    openSegment(T100Sentence*);
        T100BOOL                    closeSegment();

        T100BOOL                    setVariable(T100String, T100WORD);
        T100BOOL                    getVariable(T100String, T100WORD&);
        T100BOOL                    addVariableCall(T100VARIABLE_CALL*);

        T100BOOL                    setLabel(T100String, T100WORD);
        T100BOOL                    getLabel(T100String, T100WORD&);
        T100BOOL                    addLabelCall(T100LABEL_CALL*);

        T100BOOL                    setProcedure(T100String, T100WORD);
        T100BOOL                    getProcedure(T100String, T100WORD&);
        T100BOOL                    addProcedureCall(T100PROCEDURE_CALL*);

        T100SEGMENT_CODE_VECTOR&    getCodeSegments();
        T100SEGMENT_DATA_VECTOR&    getDataSegments();


    protected:
        T100TOKEN_TYPE              m_type          = T100TOKEN_NONE;
        T100SegmentCode*            m_code          = T100NULL;
        T100SegmentData*            m_data          = T100NULL;

    private:
        T100SEGMENT_CODE_VECTOR     m_code_segments;
        T100SEGMENT_DATA_VECTOR     m_data_segments;

};

#endif // T100BUILDINFO_H
