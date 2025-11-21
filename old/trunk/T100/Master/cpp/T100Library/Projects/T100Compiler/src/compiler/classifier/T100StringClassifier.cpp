#include "T100StringClassifier.h"

#include "compiler/scanner/T100StringScanner.h"

namespace T100LIBRARY{

T100StringClassifier::T100StringClassifier() :
    T100Classifier()
{
    //ctor
}

T100StringClassifier::~T100StringClassifier()
{
    //dtor
}

T100VOID T100StringClassifier::SetScanner(T100StringScanner* scanner)
{
    m_scanner       = scanner;
}

T100StringScanner* T100StringClassifier::GetScanner()
{
    return m_scanner;
}

T100VOID T100StringClassifier::SetOperatorTable(T100OperatorTable* table)
{
    m_operatorTable     = table;
}

T100OperatorTable* T100StringClassifier::GetOperatorTable()
{
    return m_operatorTable;
}

T100BOOL T100StringClassifier::Classify()
{
    T100BOOL            result;

    result  = m_scanner->Read();
    if(!result){
        return T100FALSE;
    }

    switch(1){
    }

    return result;
}

}
