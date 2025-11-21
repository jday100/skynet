#ifndef T100STRINGCLASSIFIER_H
#define T100STRINGCLASSIFIER_H

#include "compiler/base/T100Classifier.h"
#include "compiler/base/T100OperatorTable.h"

namespace T100LIBRARY{

class T100StringScanner;

class T100StringClassifier : public T100Classifier
{
    public:
        T100StringClassifier();
        virtual ~T100StringClassifier();

        virtual T100VOID                SetScanner(T100StringScanner*);
        virtual T100StringScanner*      GetScanner();

        virtual T100VOID                SetOperatorTable(T100OperatorTable*);
        virtual T100OperatorTable*      GetOperatorTable();

        virtual T100BOOL                Classify();

    protected:
        T100OperatorTable*              m_operatorTable     = T100NULL;

    private:
        T100StringScanner*              m_scanner           = T100NULL;
};

}

#endif // T100STRINGCLASSIFIER_H
