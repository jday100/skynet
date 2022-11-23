#ifndef T100SENTENCEAND_H
#define T100SENTENCEAND_H

#include "T100Sentence.h"

namespace T100Assembly{

class T100SentenceAnd : public T100Sentence
{
    public:
        T100SentenceAnd(T100SentenceScanner*);
        virtual ~T100SentenceAnd();

        static T100VOID     init();

        T100BOOL            parse();

        T100BOOL            build(T100BuildInfo*);

    protected:

    private:
};

}

#endif // T100SENTENCEAND_H
