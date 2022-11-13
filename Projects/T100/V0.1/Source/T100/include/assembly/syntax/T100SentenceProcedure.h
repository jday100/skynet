#ifndef T100SENTENCEPROCEDURE_H
#define T100SENTENCEPROCEDURE_H

#include "T100Sentence.h"

namespace T100Assembly{

class T100SentenceProcedure : public T100Sentence
{
    public:
        T100SentenceProcedure(T100SentenceScanner*);
        virtual ~T100SentenceProcedure();

        T100STRING          name;

        T100BOOL            parse();

        T100BOOL            build(T100BuildInfo*);

    protected:
        T100BOOL            parseConfig();

        T100BOOL            setDefine(T100STRING&);

    private:
};

}

#endif // T100SENTENCEPROCEDURE_H
