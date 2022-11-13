#ifndef T100PROCEDUREDRAWER_H
#define T100PROCEDUREDRAWER_H

#include "T100AssemblyCommon.h"
#include "T100String.h"
#include "T100StringHash.h"
#include "T100StringEqual.h"
#include "T100ProduceInfo.h"

namespace T100Assembly{

class T100ProcedureDrawer
{
    public:
        T100ProcedureDrawer();
        virtual ~T100ProcedureDrawer();

        static T100BOOL                     setProcedureDefine(T100STRING, T100PROCEDURE_DEFINE*);
        static T100PROCEDURE_DEFINE*        getProcedureDefine(T100STRING);

        static T100BOOL                     clear();

    protected:
        static T100PROCEDURE_HASH           m_procedure_hash;

    private:
};

}

#endif // T100PROCEDUREDRAWER_H
