#ifndef T100SENTENCENOP_H
#define T100SENTENCENOP_H

#include "T100Sentence.h"

namespace T100Assembly{

class T100SentenceNop : public T100Sentence
{
    public:
        T100SentenceNop(T100SentenceScanner*);
        virtual ~T100SentenceNop();

        static T100VOID     init();

        T100BOOL            parse();

        T100BOOL            build(T100BuildInfo*);

    protected:

    private:
};

}

#endif // T100SENTENCENOP_H
