#ifndef T100CHARCLASSIFIER_H
#define T100CHARCLASSIFIER_H

#include "compiler/base/T100Classifier.h"

namespace T100LIBRARY{

class T100CharScanner;

class T100CharClassifier : public T100Classifier
{
    public:
        T100CharClassifier();
        virtual ~T100CharClassifier();

        virtual T100VOID                SetScanner(T100CharScanner*);
        virtual T100CharScanner*        GetScanner();

        virtual T100BOOL                Classify();

    protected:

    private:
        T100CharScanner*                m_scanner       = T100NULL;
};

}

#endif // T100CHARCLASSIFIER_H
