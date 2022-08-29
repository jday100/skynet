#ifndef T100SENTENCEINT_H
#define T100SENTENCEINT_H

#include "T100Sentence.h"


class T100SentenceInt : public T100Sentence
{
    public:
        T100SentenceInt(T100SentenceScan*);
        virtual ~T100SentenceInt();

        T100BYTE            id;

        T100BOOL            parse();
        T100BOOL            build(T100FileData*);

    protected:
        T100BOOL            parseValue();

    private:
};

#endif // T100SENTENCEINT_H
