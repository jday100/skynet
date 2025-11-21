#include "T100CXOperatorTable.h"

T100COMPILER_OPERATOR_HASH          T100CXOperatorTable::m_cxOperators      = {
    {
        L"+",           L"+"
    }
};

T100CXOperatorTable::T100CXOperatorTable() :
    T100OperatorTable()
{
    //ctor
    init();
}

T100CXOperatorTable::~T100CXOperatorTable()
{
    //dtor
    uninit();
}

T100VOID T100CXOperatorTable::init()
{
    m_operators         = m_cxOperators;
}

T100VOID T100CXOperatorTable::uninit()
{

}
