#ifndef T100SENTENCEVARIABLE_H
#define T100SENTENCEVARIABLE_H

#include "T100Sentence.h"


class T100SentenceVariable : public T100Sentence
{
    public:
        T100SentenceVariable(T100SentenceScanner*);
        virtual ~T100SentenceVariable();

        T100String              name;
        T100OPERATOR            target;

        T100BOOL                parse();

        T100BOOL                build(T100BuildInfo*);

    protected:
        T100BOOL                parseType();
        T100BOOL                parseValue();

    private:
};

#endif // T100SENTENCEVARIABLE_H
