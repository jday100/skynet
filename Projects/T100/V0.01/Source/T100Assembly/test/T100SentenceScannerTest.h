#ifndef T100SENTENCESCANNERTEST_H
#define T100SENTENCESCANNERTEST_H

#include "T100Test.h"


class T100SentenceScannerTest : public T100Test
{
    public:
        T100SentenceScannerTest(T100Test*);
        virtual ~T100SentenceScannerTest();

    protected:
        T100BOOL                    do_test();

        T100BOOL                    test_sentence();

    private:
        static T100WSTRING          m_name;

};

#endif // T100SENTENCESCANNERTEST_H
