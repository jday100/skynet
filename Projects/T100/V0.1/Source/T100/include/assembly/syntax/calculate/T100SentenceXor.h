#ifndef T100SENTENCEXOR_H
#define T100SENTENCEXOR_H

#include "T100Sentence.h"

namespace T100Assembly{

class T100SentenceXor : public T100Sentence
{
    public:
        T100SentenceXor(T100SentenceScanner*);
        virtual ~T100SentenceXor();

        static T100VOID     init();

        T100BOOL            parse();

        T100BOOL            build(T100BuildInfo*);

    protected:

    private:
};

}

#endif // T100SENTENCEXOR_H
