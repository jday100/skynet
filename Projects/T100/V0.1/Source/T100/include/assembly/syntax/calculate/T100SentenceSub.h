#ifndef T100SENTENCESUB_H
#define T100SENTENCESUB_H

#include "T100Sentence.h"

namespace T100Assembly{

class T100SentenceSub : public T100Sentence
{
    public:
        T100SentenceSub(T100SentenceScanner*);
        virtual ~T100SentenceSub();

        static T100VOID     init();

        T100BOOL            parse();

        T100BOOL            build(T100BuildInfo*);

    protected:

    private:
};

}

#endif // T100SENTENCESUB_H
