#ifndef T100SENTENCEIRET_H
#define T100SENTENCEIRET_H

#include "T100Sentence.h"

namespace T100Assembly{

class T100SentenceIret : public T100Sentence
{
    public:
        T100SentenceIret(T100SentenceScanner*);
        virtual ~T100SentenceIret();

        static T100VOID     init();

        T100BOOL            parse();

        T100BOOL            build(T100BuildInfo*);

    protected:

    private:
};

}

#endif // T100SENTENCEIRET_H
