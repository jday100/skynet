#ifndef T100FILEDATA_H
#define T100FILEDATA_H

#include "T100CodeNew.h"
#include "T100SegmentHash.h"
#include "T100SegmentEqual.h"
#include "T100SegmentCode.h"
#include "T100SegmentData.h"
#include "T100SentenceMode.h"


#define     T100CODEDATA_VECTOR     std::vector<T100FileData*>
#define     T100SEGMENTDATA_HASH    std::unordered_map<T100SEGMENT_KEY, T100Segment*, T100SegmentHash, T100SegmentEqual>


class T100FileData
{
    friend class T100Code;
    friend class T100ExecutableRealTinyMerger;
    friend class T100ExecutableNormalSmallMerger;
    friend class T100ExecutableNormalBigMerger;
    friend class T100CodeExecutableFile;
    public:
        T100FileData(T100Code*);
        virtual ~T100FileData();

        T100String                      file;

        T100BOOL                        addSegment();
        T100BOOL                        createSegment(T100Sentence*);

        T100BOOL                        setValue(T100WORD);
        T100WORD                        getOffset();
        T100VOID                        next();

        T100BOOL                        setVariable(T100String, T100WORD);
        T100BOOL                        getVariable(T100String, T100WORD&);
        T100BOOL                        addVariableCall(T100VARIABLE_CALL*);

        T100BOOL                        setLabel(T100String, T100WORD);
        T100BOOL                        getLabel(T100String, T100WORD&);
        T100BOOL                        addLabelCall(T100LABEL_CALL*);

        T100BOOL                        setProcedure(T100String, T100WORD);
        T100BOOL                        getProcedure(T100String, T100WORD&);
        T100BOOL                        addProcedureCall(T100PROCEDURE_CALL*);

        T100SegmentCode*                getCode();
        T100SegmentData*                getData();

        T100BOOL                        setTiny(T100BOOL);
        T100BOOL                        setMode(T100MODE);
        T100BOOL                        setType(T100TYPE);

    protected:

    private:
        T100Code*                       m_parent;

        T100SEGMENTDATA_VECTOR          m_codes;
        T100SEGMENTDATA_VECTOR          m_datas;
        T100SEGMENTDATA_VECTOR          m_share_codes;
        T100SEGMENTDATA_VECTOR          m_share_datas;

        T100SegmentCode*                m_code          = T100NULL;
        T100SegmentData*                m_data          = T100NULL;
        T100SegmentCode*                m_share_code    = T100NULL;
        T100SegmentData*                m_share_data    = T100NULL;

        T100TOKEN_TYPE                  m_type          = T100TOKEN_NONE;

        T100BOOL                        m_master        = T100FALSE;
        T100BOOL                        m_istiny        = T100FALSE;
        T100MODE                        m_mode          = T100MODE_VIRTUAL;
        T100TYPE                        m_segment_type  = T100TYPE_NONE;

        T100BOOL                        m_code_default  = T100FALSE;
        T100BOOL                        m_data_default  = T100FALSE;
        T100BOOL                        m_code_virtual  = T100TRUE;
        T100BOOL                        m_data_virtual  = T100TRUE;

        T100WORD                        m_code_id       = 0;
        T100WORD                        m_data_id       = 0;

};

#endif // T100FILEDATA_H
