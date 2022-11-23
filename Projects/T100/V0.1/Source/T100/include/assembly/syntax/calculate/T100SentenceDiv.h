#ifndef T100SENTENCEDIV_H
#define T100SENTENCEDIV_H

#include "T100Sentence.h"

namespace T100Assembly{

class T100SentenceDiv : public T100Sentence
{
    public:
        T100SentenceDiv(T100SentenceScanner*);
        virtual ~T100SentenceDiv();

        static T100VOID     init();

        T100BOOL            parse();

        T100BOOL            build(T100BuildInfo*);

    protected:

    private:
};

}

#endif // T100SENTENCEDIV_H
