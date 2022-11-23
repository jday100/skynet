#ifndef T100SENTENCEDEBUG_H
#define T100SENTENCEDEBUG_H

#include "T100Sentence.h"

namespace T100Assembly{

class T100SentenceDebug : public T100Sentence
{
    public:
        T100SentenceDebug(T100SentenceScanner*);
        virtual ~T100SentenceDebug();

        static T100VOID     init();

        T100BOOL            parse();

        T100BOOL            build(T100BuildInfo*);

    protected:

    private:
};

}

#endif // T100SENTENCEDEBUG_H
