#ifndef T100PRODUCEINFO_H
#define T100PRODUCEINFO_H

#include "T100AssemblyCommon.h"
#include "T100SentenceMode.h"
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
    public:
        T100ProduceInfo();
        virtual ~T100ProduceInfo();

        static T100BOOL                 clear();

        static T100BOOL                 setDefaultCode(T100SegmentCode*);
        static T100BOOL                 setDefaultData(T100SegmentData*);

        static T100BOOL                 m_code_default;
        static T100BOOL                 m_data_default;

        static T100PartDrawer&          getPartDrawer();

        static T100BOOL                 setMode(T100MODE);
        static T100MODE                 getMode();

        static T100VariableDrawer&      getVariableDrawer();
        static T100LabelDrawer&         getLabelDrawer();
        static T100ProcedureDrawer&     getProcedureDrawer();

    protected:
        static T100SegmentCode*         m_code;
        static T100SegmentData*         m_data;

    private:
        static T100MODE                 m_mode;

        static T100PartDrawer           m_part_drawer;

        static T100VariableDrawer       m_variable_drawer;
        static T100LabelDrawer          m_label_drawer;
        static T100ProcedureDrawer      m_procedure_drawer;

};

#endif // T100PRODUCEINFO_H
