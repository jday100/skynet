#ifndef T100SENTENCEADD_H
#define T100SENTENCEADD_H

#include "T100Sentence.h"

/*
ADD
ADD     WORD
ADD     DWORD
*/

namespace T100Assembly{

class T100SentenceAdd : public T100Sentence
{
    public:
        T100SentenceAdd(T100SentenceScanner*);
        virtual ~T100SentenceAdd();

        static T100VOID         init();

        T100Component::T100OPERATOR            target;
        T100Component::T100OPERATOR            source;

        T100BOOL                parse();
        T100BOOL                build(T100BuildInfo*);

    protected:

    private:
};

}

#endif // T100SENTENCEADD_H
