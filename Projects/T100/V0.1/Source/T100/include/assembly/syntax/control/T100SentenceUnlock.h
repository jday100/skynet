#ifndef T100SENTENCEUNLOCK_H
#define T100SENTENCEUNLOCK_H

#include "T100Sentence.h"

namespace T100Assembly{

class T100SentenceUnlock : public T100Sentence
{
    public:
        T100SentenceUnlock(T100SentenceScanner*);
        virtual ~T100SentenceUnlock();

        static T100VOID     init();

        T100BOOL            parse();

        T100BOOL            build(T100BuildInfo*);

    protected:

    private:
};

}

#endif // T100SENTENCEUNLOCK_H
