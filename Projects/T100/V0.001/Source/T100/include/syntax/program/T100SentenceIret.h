#ifndef T100SENTENCEIRET_H
#define T100SENTENCEIRET_H

#include "T100Sentence.h"


class T100SentenceIret : public T100Sentence
{
    public:
        T100SentenceIret(T100SentenceScan*);
        virtual ~T100SentenceIret();

        T100BOOL            parse();
        T100BOOL            build(T100FileData*);

    protected:

    private:
};

#endif // T100SENTENCEIRET_H
