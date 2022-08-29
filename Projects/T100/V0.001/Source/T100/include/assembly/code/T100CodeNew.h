#ifndef T100CODENEW_H
#define T100CODENEW_H

#include "T100AsmCommon.h"
#include "T100String.h"
#include "T100StringHash.h"
#include "T100StringEqual.h"

#include "T100OrderTypes.h"
#include "T100FileToken.h"
#include "T100SegmentToken.h"
#include "T100SentenceMode.h"

class T100FileData;
class T100Segment;
class T100SegmentCode;
class T100SegmentData;


typedef struct{
    T100BOOL            isvirtual   = T100FALSE;
    T100BOOL            isshare     = T100FALSE;
    T100String          name;
    T100WORD            value;
    T100WORD            length;
    T100WORD            offset;
    T100DATA_TYPE       type;
    T100BOOL            isarray     = T100FALSE;
}T100VARIABLE_DEFINE;


typedef struct{
    T100BOOL            isvirtual;
    T100BOOL            isshare;
    T100String          name;
    T100WORD            offset;
}T100LABEL_DEFINE;

typedef struct{
    T100String          name;
    T100WORD            offset;
}T100ITEM;



#define     T100SEGMENTDATA_VECTOR      std::vector<T100Segment*>

#define     T100CODEDATA_VECTOR         std::vector<T100FileData*>

#define     T100VARIABLE_CALL           T100ITEM
#define     T100LABEL_CALL              T100ITEM
#define     T100PROCEDURE_CALL          T100ITEM

#define     T100VARIABLE_HASH           std::unordered_map<T100String, T100VARIABLE_DEFINE*, T100StringHash, T100StringEqual>
#define     T100VARIABLEOFFSET_HASH     std::unordered_map<T100String, T100WORD, T100StringHash, T100StringEqual>
#define     T100VARIABLECALL_VECTOR     std::vector<T100VARIABLE_CALL*>

#define     T100LABEL_HASH              std::unordered_map<T100String, T100LABEL_DEFINE*, T100StringHash, T100StringEqual>
#define     T100LABELOFFSET_HASH        std::unordered_map<T100String, T100WORD, T100StringHash, T100StringEqual>
#define     T100LABElCALL_VECTOR        std::vector<T100LABEL_CALL*>


#define     T100PROCEDURE_DEFINE        T100ITEM
#define     T100PROCEDURE_HASH          std::unordered_map<T100String, T100PROCEDURE_DEFINE*, T100StringHash, T100StringEqual>
#define     T100PROCEDUREOFFSET_HASH    std::unordered_map<T100String, T100WORD, T100StringHash, T100StringEqual>
#define     T100PROCEDURECALL_VECTOR    std::vector<T100PROCEDURE_CALL*>



class T100Code
{
    friend class T100Builder;
    friend class T100FileData;
    friend class T100SentenceCode;
    friend class T100ExecutableRealTinyBuilder;
    friend class T100ExecutableNormalSmallBuilder;
    friend class T100ExecutableNormalBigBuilder;
    public:
        T100Code();
        virtual ~T100Code();

        static T100VARIABLE_DEFINE*     getVariableDefine(T100String);
        static T100BOOL                 setVariableDefine(T100String, T100VARIABLE_DEFINE*);

        static T100LABEL_DEFINE*        getLabelDefine(T100String);
        static T100BOOL                 setLabelDefine(T100String, T100LABEL_DEFINE*);

        static T100PROCEDURE_DEFINE*    getProcedureDefine(T100String);
        static T100BOOL                 setProcedureDefine(T100String, T100PROCEDURE_DEFINE*);

        static T100SegmentCode*         m_code;
        static T100SegmentData*         m_data;
        static T100BOOL                 m_code_default;
        static T100BOOL                 m_data_default;
        static T100BOOL                 m_code_default_flag;
        static T100BOOL                 m_data_default_flag;

        T100BOOL                        istiny();

        T100BOOL                        build(T100FileToken*);
        T100BOOL                        build(T100SegmentToken*);
        T100BOOL                        build(T100SentenceToken*);

        T100BOOL                        clear();

    protected:
        static T100VARIABLE_HASH        m_variables;
        static T100LABEL_HASH           m_labels;
        static T100PROCEDURE_HASH       m_procedures;

        T100BOOL                        setDefaultSegment(T100SegmentToken*);

    private:
        T100CODEDATA_VECTOR             m_files;
        T100FileData*                   m_file;

        T100BOOL                        m_istiny                = T100FALSE;
        T100MODE                        m_mode                  = T100MODE_VIRTUAL;
        T100TYPE                        m_type                  = T100TYPE_NONE;
};

#endif // T100CODENEW_H
