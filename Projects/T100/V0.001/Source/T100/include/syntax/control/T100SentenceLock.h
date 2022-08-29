#ifndef T100SENTENCELOCK_H
#define T100SENTENCELOCK_H

#include "T100Sentence.h"


class T100SentenceLock : public T100Sentence
{
    public:
        T100SentenceLock(T100SentenceScan*);
        virtual ~T100SentenceLock();

        T100BOOL            parse();
        T100BOOL            build(T100FileData*);

    protected:

    private:
};

#endif // T100SENTENCELOCK_H
