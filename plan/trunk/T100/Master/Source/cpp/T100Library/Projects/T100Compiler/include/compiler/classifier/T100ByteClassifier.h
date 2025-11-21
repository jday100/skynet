#ifndef T100BYTECLASSIFIER_H
#define T100BYTECLASSIFIER_H

#include "compiler/base/T100Classifier.h"

namespace T100LIBRARY{

class T100ByteScanner;

class T100ByteClassifier : public T100Classifier
{
    public:
        T100ByteClassifier();
        virtual ~T100ByteClassifier();

        virtual T100VOID                SetScanner(T100ByteScanner*);
        virtual T100ByteScanner*        GetScanner();

        virtual T100BOOL                Classify();

    protected:

    private:
        T100ByteScanner*                m_scanner       = T100NULL;
};

}

#endif // T100BYTECLASSIFIER_H
