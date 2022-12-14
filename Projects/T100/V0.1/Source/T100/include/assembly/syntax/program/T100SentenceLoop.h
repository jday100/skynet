#ifndef T100SENTENCELOOP_H
#define T100SENTENCELOOP_H

#include "T100Sentence.h"

namespace T100Assembly{

class T100SentenceLoop : public T100Sentence
{
    public:
        T100SentenceLoop(T100SentenceScanner*);
        virtual ~T100SentenceLoop();

        static T100VOID         init();

        T100Component::T100OPERATOR            target;

        T100BOOL                parse();

        T100BOOL                build(T100BuildInfo*);

    protected:

    private:
};

}

#endif // T100SENTENCELOOP_H
