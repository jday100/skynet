#ifndef T100SEGMENTCODE_H
#define T100SEGMENTCODE_H

#include "T100Segment.h"

namespace T100Assembly{

class T100SegmentCode : public T100Segment
{
    friend class T100RealMerger;
    friend class T100VirtualMerger;
    public:
        T100SegmentCode();
        virtual ~T100SegmentCode();

        T100BOOL                    setValue(T100WORD);
        T100VOID                    next();

        T100BOOL                    addVariableCall(T100VARIABLE_CALL*);

        T100BOOL                    setLabel(T100STRING, T100WORD);
        T100BOOL                    getLabel(T100STRING, T100WORD&);
        T100BOOL                    addLabelCall(T100LABEL_CALL*);

        T100BOOL                    setProcedure(T100STRING, T100WORD);
        T100BOOL                    getProcedure(T100STRING, T100WORD&);
        T100BOOL                    addProcedureCall(T100PROCEDURE_CALL*);

    protected:
        T100VOID                    create();
        T100VOID                    destroy();

    private:
        T100LABELOFFSET_HASH        m_label_hash;
        T100LABELCALL_VECTOR        m_label_call;

        T100VARIABLECALL_VECTOR     m_variable_call;

        T100PROCEDUREOFFSET_HASH    m_procedure_hash;
        T100PROCEDURECALL_VECTOR    m_procedure_call;

};

}

#endif // T100SEGMENTCODE_H
