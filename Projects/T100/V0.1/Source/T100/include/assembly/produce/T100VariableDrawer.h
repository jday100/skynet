#ifndef T100VARIABLEDRAWER_H
#define T100VARIABLEDRAWER_H

#include "T100AssemblyCommon.h"
#include "T100String.h"
#include "T100StringHash.h"
#include "T100StringEqual.h"
#include "T100ProduceInfo.h"


namespace T100Assembly{

class T100VariableDrawer
{
    public:
        T100VariableDrawer();
        virtual ~T100VariableDrawer();

        static T100BOOL                     setVariableDefine(T100STRING, T100VARIABLE_DEFINE*);
        static T100VARIABLE_DEFINE*         getVariableDefine(T100STRING);

        static T100BOOL                     clear();

    protected:
        static T100VARIABLE_HASH            m_variable_hash;

    private:
};

}

#endif // T100VARIABLEDRAWER_H
