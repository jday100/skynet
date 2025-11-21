#ifndef T100OPERATORTABLE_H
#define T100OPERATORTABLE_H

#include <unordered_map>
#include "base/T100Class.h"

namespace T100LIBRARY{

#define     T100COMPILER_OPERATOR_HASH          std::unordered_map<T100WSTRING, T100WSTRING>

class T100OperatorTable : public T100Class
{
    public:
        T100OperatorTable();
        virtual ~T100OperatorTable();

    protected:
        T100COMPILER_OPERATOR_HASH          m_operators;

    private:
};

}

#endif // T100OPERATORTABLE_H
