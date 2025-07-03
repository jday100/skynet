#ifndef T100CXOPERATORTABLE_H
#define T100CXOPERATORTABLE_H

#include "compiler/base/T100OperatorTable.h"

using namespace T100LIBRARY;

class T100CXOperatorTable : public T100OperatorTable
{
    public:
        T100CXOperatorTable();
        virtual ~T100CXOperatorTable();

    protected:
        static T100COMPILER_OPERATOR_HASH           m_cxOperators;

    private:
        T100VOID            init();
        T100VOID            uninit();
};

#endif // T100CXOPERATORTABLE_H
