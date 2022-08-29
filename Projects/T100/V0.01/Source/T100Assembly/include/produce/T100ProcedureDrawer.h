#ifndef T100PROCEDUREDRAWER_H
#define T100PROCEDUREDRAWER_H

#include "T100AssemblyCommon.h"
#include "T100String.h"
#include "T100StringHash.h"
#include "T100StringEqual.h"


class T100ProcedureDrawer
{
    public:
        T100ProcedureDrawer();
        virtual ~T100ProcedureDrawer();

        static T100BOOL                     setProcedureDefine(T100String, T100PROCEDURE_DEFINE*);
        static T100PROCEDURE_DEFINE*        getProcedureDefine(T100String);

    protected:
        static T100PROCEDURE_HASH           m_procedure_hash;

    private:
};

#endif // T100PROCEDUREDRAWER_H
