#ifndef T100PRODUCEINFO_H
#define T100PRODUCEINFO_H

#include "T100AssemblyCommon.h"

#define         T100TOKEN_NAME_HASH                 std::unordered_map<T100WORD, T100STRING>


namespace T100Assembly{
class T100PartDrawer;

class T100VariableDrawer;
class T100LabelDrawer;
class T100ProcedureDrawer;

class T100SegmentCode;
class T100SegmentData;


class T100ProduceInfo
{
    friend class T100BuildInfo;
    friend class T100RealMerger;
    friend class T100VirtualMerger;
    public:
        T100ProduceInfo();
        virtual ~T100ProduceInfo();

        static T100BOOL                     clear();

        static T100VOID                     setName(T100STRING&);
        static T100STRING&                  getName();

        static T100BOOL                     setDefaultCode(T100SegmentCode*);
        static T100BOOL                     setDefaultData(T100SegmentData*);

        static T100BOOL                     m_code_default;
        static T100BOOL                     m_data_default;

        static T100PartDrawer&              getPartDrawer();

        static T100BOOL                     setMode(T100MODE);
        static T100MODE                     getMode();

        static T100VariableDrawer&          getVariableDrawer();
        static T100LabelDrawer&             getLabelDrawer();
        static T100ProcedureDrawer&         getProcedureDrawer();

        static T100TOKEN_NAME_HASH          m_token_names;

    protected:
        static T100SegmentCode*             m_code;
        static T100SegmentData*             m_data;

    private:
        static T100STRING                   m_name;
        static T100MODE                     m_mode;

        static T100PartDrawer               m_part_drawer;

        static T100VariableDrawer           m_variable_drawer;
        static T100LabelDrawer              m_label_drawer;
        static T100ProcedureDrawer          m_procedure_drawer;

};

}



#define         T100SEGMENT_CODE_VECTOR                 std::vector<T100Assembly::T100SegmentCode*>
#define         T100SEGMENT_DATA_VECTOR                 std::vector<T100Assembly::T100SegmentData*>

#define         T100PART_INFO_VECTOR                    std::vector<T100PartInfo*>
#define         T100PART_INFO_HASH                      std::unordered_map<T100STRING, T100PartInfo*, T100Library::T100StringHash, T100Library::T100StringEqual>

#define         T100VARIABLE_CALL                       T100ITEM
#define         T100LABEL_CALL                          T100ITEM
#define         T100PROCEDURE_CALL                      T100ITEM

#define         T100VARIABLE_HASH                       std::unordered_map<T100STRING, T100VARIABLE_DEFINE*, T100Library::T100StringHash, T100Library::T100StringEqual>
#define         T100VARIABLEOFFSET_HASH                 std::unordered_map<T100STRING, T100WORD, T100Library::T100StringHash, T100Library::T100StringEqual>
#define         T100VARIABLECALL_VECTOR                 std::vector<T100LABEL_CALL*>

#define         T100LABEL_HASH                          std::unordered_map<T100STRING, T100LABEL_DEFINE*, T100Library::T100StringHash, T100Library::T100StringEqual>
#define         T100LABELOFFSET_HASH                    std::unordered_map<T100STRING, T100WORD, T100Library::T100StringHash, T100Library::T100StringEqual>
#define         T100LABELCALL_VECTOR                    std::vector<T100LABEL_CALL*>

#define         T100PROCEDURE_DEFINE                    T100ITEM
#define         T100PROCEDURE_HASH                      std::unordered_map<T100STRING, T100PROCEDURE_DEFINE*, T100Library::T100StringHash, T100Library::T100StringEqual>
#define         T100PROCEDUREOFFSET_HASH                std::unordered_map<T100STRING, T100WORD, T100Library::T100StringHash, T100Library::T100StringEqual>
#define         T100PROCEDURECALL_VECTOR                std::vector<T100PROCEDURE_CALL*>


#endif // T100PRODUCEINFO_H
