#ifndef T100SENTENCEPROCEDURE_H
#define T100SENTENCEPROCEDURE_H

#include "T100Sentence.h"


class T100SentenceProcedure : public T100Sentence
{
    public:
        T100SentenceProcedure(T100SentenceScan*);
        virtual ~T100SentenceProcedure();

        T100String          name;

        T100BOOL            parse();
        T100BOOL            build(T100FileData*);

        T100STDSTRING       tostring();

    protected:
        T100BOOL            parseSetup();

    private:
};

#endif // T100SENTENCEPROCEDURE_H
