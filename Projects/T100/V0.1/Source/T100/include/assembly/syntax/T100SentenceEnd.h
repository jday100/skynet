#ifndef T100SENTENCEEND_H
#define T100SENTENCEEND_H

#include "T100Sentence.h"

namespace T100Assembly{

class T100SentenceEnd : public T100Sentence
{
    public:
        T100SentenceEnd(T100SentenceScanner*);
        virtual ~T100SentenceEnd();

        static T100VOID     init();

        T100BOOL            parse();

        T100BOOL            build(T100BuildInfo*);

    protected:

    private:
};

}

#endif // T100SENTENCEEND_H
