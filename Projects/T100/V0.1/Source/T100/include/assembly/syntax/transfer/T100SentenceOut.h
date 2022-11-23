#ifndef T100SENTENCEOUT_H
#define T100SENTENCEOUT_H

#include "T100Sentence.h"

namespace T100Assembly{

class T100SentenceOut : public T100Sentence
{
    public:
        T100SentenceOut(T100SentenceScanner*);
        virtual ~T100SentenceOut();

        static T100VOID                 init();

        T100Component::T100OPERATOR                    target;
        T100Component::T100OPERATOR_COMPLEXUS          source;

        T100BOOL                        parse();

        T100BOOL                        build(T100BuildInfo*);

    protected:

    private:
};

}

#endif // T100SENTENCEOUT_H
